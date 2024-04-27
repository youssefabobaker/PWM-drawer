/*
 * TIMER1_interface.h
 *
 * Created: 10/2/2023 10:51:37 PM
 *  Author: youssef
 */ 

#include "MATH.h"
#include "STD_TYPE.h"
#include "TIMER1_private.h"

#ifndef TIMER1_INTERFACE_H_
#define TIMER1_INTERFACE_H_

void TIMER1_Vid_FastPWM(u8 copy_u8_duty);

void TIMER1_Vid_FastPWM_ICR1_Init();

void TIMER1_Vid_SetCompareVal(u32 copy_u32_val);

void TIMER1_Vid_NormalMode_Init();
void TIMER1_Vid_Reset_Timer();
u32  TIMER1_u32_ReadVal(); 

/* PRESCALER MACROS */
#define TIMER_STOP        0X00
#define NO_PRESCALAR      0X01
#define _2_PRESCALAR      0X02
#define _64_PRESCALAR     0X03
#define _256_PRESCALAR    0X04
#define _1024_PRESCALAR   0X05

/* SELECT PRESCALER */
#define TIMER1_PRESCALER  _64_PRESCALAR





#endif /* TIMER1_INTERFACE_H_ */