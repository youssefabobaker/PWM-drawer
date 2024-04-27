/*
 * TIMER1_private.h
 *
 * Created: 10/2/2023 10:51:19 PM
 *  Author: youssef
 */ 

#ifndef TIMER1_PRIVATE_H_
#define TIMER1_PRIVATE_H_

#define  TCCR1A_REG   *((volatile u8*)0x4F) 
#define  TCCR1B_REG   *((volatile u8*)0x4E) 

#define  OCR1A_REG   *((volatile u16*)0x4A) //OCR1AL + OCR1AH
#define  OCR1B_REG   *((volatile u16*)0x48) //OCR1BL + OCR1BH

#define  ICR_REG     *((volatile u16*)0x46) // ICRL_REG + ICRH_REG

#define  TIFR_REG    *((volatile u8*)0x58)

#define  TCNT1_REG   *((volatile u16*)0x4C) // TCNT1L + TCNT1H 
#define  TIMSK_REG   *((volatile u8*)0x59) 

#endif /* TIMER1_PRIVATE_H_ */