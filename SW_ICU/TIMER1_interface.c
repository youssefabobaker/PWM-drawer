/*
 * TIMER1_interface.c
 *
 * Created: 10/2/2023 10:52:02 PM
 *  Author: youssef
 */ 

#include "MATH.h"
#include "STD_TYPE.h"
#include "TIMER1_interface.h"

void TIMER1_Vid_FastPWM(u8 copy_u8_duty){
	
	/* SELECT PRESCALER */
	TCCR1B_REG &= 0b11111000 ;        // BIT MASK FOR TCCR0_REG
	TCCR1B_REG |= TIMER1_PRESCALER ;  // START THE TIMER WITH TIMER1_PRESCALER (_64_PRESCALAR)
	
	/* SELECTING THE MODE OF TIMER --> FAST PWM MODE, 10 BIT */
	SET_BIT(TCCR1A_REG,0);
	SET_BIT(TCCR1A_REG,1);
	SET_BIT(TCCR1B_REG,3);
	CLR_BIT(TCCR1B_REG,4);
	
	/* SELECT NONINVERTING MODE */
	CLR_BIT(TCCR1A_REG,4);
	CLR_BIT(TCCR1A_REG,6);
	SET_BIT(TCCR1A_REG,5);
	SET_BIT(TCCR1A_REG,7);
	
	/* SET OCR ---> DUTY = OCR(count) / 2^RES % , OCR(count) = (DUTY/100) * 2^RES = D/100 *1024 = D*10.24 */
	//OCR1AH_REG = (copy_u8_duty>>8)*10.24;   // SET OCR1AH_REG FIRST THEN OCR1AL_REG THE VALUE BY WHICH THE TIMER WILL MAKE CLR ON COMPARE WHEN IT REACHES THE OCR VALUE
	OCR1A_REG = copy_u8_duty*10.23;        

	//OCR1BH_REG = (copy_u8_duty>>8)*10.24;   // SET OCR1BH_REG FIRST THEN OCR1BL_REG THE VALUE BY WHICH THE TIMER WILL MAKE CLR ON COMPARE WHEN IT REACHES THE OCR VALUE
	OCR1B_REG = copy_u8_duty*10.23;        

	while (GET_BIT(TIFR_REG,4) == 0); // WAIT TILL THE COMPARE PROCESS FINISHED
	while (GET_BIT(TIFR_REG,3) == 0); // WAIT TILL THE COMPARE PROCESS FINISHED
	/* CLEAR CTC FLAG */
	SET_BIT(TIFR_REG,4);
	SET_BIT(TIFR_REG,3);

}

void TIMER1_Vid_FastPWM_ICR1_Init(){
	/* SELECT NONINVERTING MODE ---> OCRA */
	CLR_BIT(TCCR1A_REG,6);
	SET_BIT(TCCR1A_REG,7);
	/* SELECTING THE MODE OF TIMER --> FAST PWM MODE, 16 BIT, ICR1 */
	CLR_BIT(TCCR1A_REG,0);
	SET_BIT(TCCR1A_REG,1);
	SET_BIT(TCCR1B_REG,3);
	SET_BIT(TCCR1B_REG,4);
	/* SET TOP */
	ICR_REG = 40000;
	/* SET OCR */
	//OCR1A_REG = 2000;
	/* SELECT PRESCALER */
	TCCR1B_REG &= 0b11111000 ;   // BIT MASK FOR TCCR0_REG
	TCCR1B_REG |= 2 ;            // START THE TIMER WITH TIMER1_PRESCALER (_64_PRESCALAR)
}

void TIMER1_Vid_SetCompareVal(u32 copy_u32_val){
	OCR1A_REG = copy_u32_val;
}

void TIMER1_Vid_NormalMode_Init(){
	/* SELECT NORMAL MODE */
	CLR_BIT(TCCR1A_REG,0);
	CLR_BIT(TCCR1A_REG,1);
	CLR_BIT(TCCR1B_REG,3);
	CLR_BIT(TCCR1B_REG,4);
	/* SET PRESCALER --> 64 */
	SET_BIT(TCCR1B_REG,0);
	SET_BIT(TCCR1B_REG,1);
	CLR_BIT(TCCR1B_REG,2);
}
void TIMER1_Vid_Reset_Timer(){
	TCNT1_REG = 0x00;
}
u32  TIMER1_u32_ReadVal(){
	return TCNT1_REG;
}