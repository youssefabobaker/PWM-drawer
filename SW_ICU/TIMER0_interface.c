/*
 * TIMER0_interface.c
 *
 * Created: 9/26/2023 3:41:38 PM
 *  Author: youssef
 */ 

#include "MATH.h"
#include "STD_TYPE.h"
#include "DIO_interface.h"
#include "TIMER0_private.h"
#include "TIMER0_interface.h"
#include "GIE_interface.h"
#include "Interrupt_Vector.h"

/* TIMER0_Vid_Init ---> USED WITH INTERRUPT */
void TIMER0_Vid_Init(u8 copy_u8_mode){
	// (F(timer) = 0.25 MHz) , (T(ticktime) = 4 Us) , (TIMER OVERFLOW COUNT = 2^8 = 256) , (TIMER OVERFLOW TIME = 256 * 4Us = 1024 Us = 1.024 Ms)
	
	/* BIT (2,1,0) IN TCCR0_REG RESPONSIBLE FOR SELECTING PRESCALER ACCORDING TO THE TABLE  */
	TCCR0_REG&=0b11111000 ;          // BIT MASK FOR TCCR0_REG
	TCCR0_REG |= TIMER0_PRESCALER_Ms ;  // START THE TIMER WITH TIMER0_PRESCALER (_64_PRESCALAR) 
	
	/* ENABLE GLOBAL INTERRUPT  */
	GIE_Vid_Interrupt_Enable() ;
	
	/* OV_MODE --> THE TIMER COUNT FROM (0 --> 2^RES) THEN MAKE OVERFLOW */
	if(copy_u8_mode == OV_MODE){
		/* BIT (0) IN TIMSK_REG RESPONSIBLE FOR ENABLING THE TIMER OVERFLOW INTERRUPT  */
		SET_BIT(TIMSK_REG,0) ;
	}
	/* CTC_MODE --> THE TIMER COUNT FROM (0 --> CTC COUNT(VALUE OF OCR0_REG))AUTOMATICALLY THEN MAKE OVERFLOW */
	else if(copy_u8_mode == CTC_MODE){
		/* SET THE TIMER(0) ON CTC MODE */
		CLR_BIT(TCCR0_REG,6);
		SET_BIT(TCCR0_REG,3);
		/* The Output Compare Register (OCRO_REG) contains an 8-bit value that is continuously compared with the counter value (TCNT0) */
		/* SET VALUE TO OCR0_REG --> ( RESOLUTION = ??) , (F(SYSTEM) = 16 MHz) , (PRESCALER = 64) , (T(TICKTIME) = 4 Us) ,(ASSUME CTC COUNT(OCR0_VAL) = 250) , (CTC OVERFLOW TIME = 250 * 4Us = 1000 Us = 1 Ms) */
		OCR0_REG = OCR0_VAL;
		/* ENABLE CTC INTERRUPT */
		SET_BIT(TIMSK_REG,1);
	}
}

/* TIMER0_Vid_DelayMs , TIMER0_Vid_Delayus ---> USED WITH POLLING */
void TIMER0_Vid_DelayMs(u32 copy_u32_delay){
	u32 count=0 ;
	
	// (F(timer) = 0.25 MHz) , (T(ticktime) = 4 Us) , (TIMER OVERFLOW COUNT = 2^8 = 256) , (TIMER OVERFLOW TIME = 256 * 4Us = 1024 Us = 1.024 Ms)
	/* CALCULATE THE NUMBER OF NUMBER OF COUNT */
	copy_u32_delay=(f32)copy_u32_delay/1.024 ;
	
	while(count<copy_u32_delay){
		/* BIT (2,1,0) IN TCCR0_REG RESPONSIBLE FOR SELECTING PRESCALER ACCORDING TO THE TABLE  */
		TCCR0_REG &= 0b11111000 ;        // BIT MASK FOR TCCR0_REG
		TCCR0_REG |= TIMER0_PRESCALER_Ms ;  // START THE TIMER WITH TIMER0_PRESCALER (_64_PRESCALAR) 
		
		/* BIT (0) IN TIFR_REG IS FLAG --->  is set (1) when an overflow occurs in Timer/Counter0 */
		while(GET_BIT(TIFR_REG,0)==0) ;
		/* SET IT TO (0) TO REPEAT THE OVERFLOW */
		SET_BIT(TIFR_REG,0) ;
		
		count++ ;
	}
	
	/* AT THE END ---> STOP THE TIMER + NO PRESCALER */
	TCCR0_REG = TIMER_STOP ; 
}

void TIMER0_Vid_DelayUs(u32 copy_u32_delay){
	u32 count=0 ;
	
	// (F(timer) = 16 MHz) , (T(ticktime) = 0.0625 Us) , (TIMER OVERFLOW COUNT = 2^8 = 256) , (TIMER OVERFLOW TIME = 256 * 0.0625Us = 16 Us)
	/* CALCULATE THE NUMBER OF NUMBER OF COUNT */
	copy_u32_delay=(f32)copy_u32_delay/16 ;
	
	while(count<copy_u32_delay){
		/* BIT (2,1,0) IN TCCR0_REG RESPONSIBLE FOR SELECTING PRESCALER ACCORDING TO THE TABLE  */
		TCCR0_REG &= 0b11111000 ;        // BIT MASK FOR TCCR0_REG
		TCCR0_REG |= TIMER0_PRESCALER_Us ;  // START THE TIMER WITH TIMER0_PRESCALER (_64_PRESCALAR)
		
		/* BIT (0) IN TIFR_REG IS FLAG --->  is set (1) when an overflow occurs in Timer/Counter0 */
		while(GET_BIT(TIFR_REG,0)==0) ;
		/* SET IT TO (0) TO REPEAT THE OVERFLOW */
		SET_BIT(TIFR_REG,0) ;
		
		count++ ;
	}
	
	/* AT THE END ---> STOP THE TIMER + NO PRESCALER */
	TCCR0_REG = TIMER_STOP ;
}

void (*OV_MODE_ptr)(void) = null;  // POINTER TO OVERFLOW FUNCTION
void (*CTC_MODE_ptr)(void) = null; // POINTER TO CTC FUNCTION

void TIMER0_Vid_SetCallBack(u8 copy_u8_mode , void(*ptr_fun)(void)){
	if(copy_u8_mode == OV_MODE){
		OV_MODE_ptr = ptr_fun;
	}
	else if (copy_u8_mode == CTC_MODE){
		CTC_MODE_ptr = ptr_fun;
	}
}

ISR(TIMER0_OVF){
	OV_MODE_ptr();
}

ISR(TIMER0_COMP){
	CTC_MODE_ptr();
}


/* FAST PWM "PULSE WIDTH MODULATION" ---> CONTROLING THE WIDTH OF THE PULSE(ACTIVE HIGH) */ 
void TIMER0_Vid_FastPWM(u8 copy_u8_duty){
	
	/* SELECT PRESCALER */
	TCCR0_REG &= 0b11111000 ;           // BIT MASK FOR TCCR0_REG
	TCCR0_REG |= TIMER0_PRESCALER_Ms ;  // START THE TIMER WITH TIMER0_PRESCALER (_64_PRESCALAR)
	
	/* BIT(6,3) IN TCCR0_REG RESPONSIBLE FOR ---> SELECTING THE MODE OF TIMER */ 
	SET_BIT(TCCR0_REG,6);  // SELECT FAST PWM MODE 
	SET_BIT(TCCR0_REG,3);
	/* BIT(5,4) IN TCCRO_REG RESPONSIBLE FOR ---> SELECTING COMPARE MATCH OUTPUT MODE OCCORDING TO THE TABLE */
	SET_BIT(TCCR0_REG,5);  // SELECT NONINVERTING MODE --> SET OC0 ON COMPARE MATCH (THE OUTPUT OF PWM IS CONNECTED TO OC0 PIN AUTOMATICALLY) (BELONGS TO TIMER0) (PORTB,PIN3)
	CLR_BIT(TCCR0_REG,4);
	/* SET OCR ---> DUTY = OCR(count) / 2^RES % , OCR(count) = (DUTY/100) * 2^RES = D/100 *256 = D*2.56 */
	OCR0_REG = copy_u8_duty*2.55;   // SET OCR0_REG WITH THE VALUE BY WHICH THE TIMER WILL MAKE CLR ON COMPARE WHEN IT REACHES THE OCR VALUE
	/* WAIT TO CTC HAPPEN */
	while (GET_BIT(TIFR_REG,1) == 0); // WAIT TILL THE COMPARE PROCESS FINISHED
	/* CLEAR CTC FLAG */
	SET_BIT(TIFR_REG,1);
}

