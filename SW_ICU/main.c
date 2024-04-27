/*
 * SW_ICU.c
 *
 * Created: 10/8/2023 4:23:13 PM
 * Author : youssef
 */ 

#include "STD_TYPE.h"
#include "MATH.h"
#include "DIO_interface.h"
#include "TIMER0_interface.h"
#include "TIMER1_interface.h"
#include "GIE_interface.h"
#include "EXT_interface.h"
#include "LCD_config.h"
#include "LCD_interface.h"
#define  F_CPU 16000000UL
#include <util/delay.h>

volatile static u8 ton_val = 0;
volatile static u32 on_tick = 0;
volatile static u32 tov_tick = 0;
u8 char1[] = {0x00,0x00,0x00,0x07,0x04,0x04,0x1C,0x00};
u8 char2[] = {0x00,0x00,0x00,0x1C,0x04,0x04,0x07,0x00};
void lcd_0(){
	LCD_Vid_GotoXY(COL1,ROW1);
	LCD_Vid_Send_String("____________");
}
void lcd_10(){
	LCD_Vid_GotoXY(COL1,ROW1);
	LCD_Vid_Send_String("_________");
	LCD_Vid_Send_Custom_Char(COL10,ROW1,0,char1);
	LCD_Vid_Send_String("-");
	LCD_Vid_Send_Custom_Char(COL12,ROW1,1,char2); 
	//_delay_ms(10);
	LCD_Vid_GotoXY(COL1,ROW1);
	LCD_Vid_Send_String("________");
	LCD_Vid_Send_Custom_Char(COL9,ROW1,0,char1);  
	LCD_Vid_Send_String("-");
	LCD_Vid_Send_Custom_Char(COL11,ROW1,1,char2);
	LCD_Vid_Send_String("_");
	//_delay_ms(10);
	LCD_Vid_GotoXY(COL1,ROW1);
	LCD_Vid_Send_String("_______");
	LCD_Vid_Send_Custom_Char(COL8,ROW1,0,char1);
	LCD_Vid_Send_String("-");
	LCD_Vid_Send_Custom_Char(COL10,ROW1,1,char2);
	LCD_Vid_Send_String("__");
	//_delay_ms(10);
	LCD_Vid_GotoXY(COL1,ROW1);
	LCD_Vid_Send_String("______");
	LCD_Vid_Send_Custom_Char(COL7,ROW1,0,char1);
	LCD_Vid_Send_String("-");
	LCD_Vid_Send_Custom_Char(COL9,ROW1,1,char2);
	LCD_Vid_Send_String("___");
	//_delay_ms(10);
	LCD_Vid_GotoXY(COL1,ROW1);
	LCD_Vid_Send_String("_____");
	LCD_Vid_Send_Custom_Char(COL6,ROW1,0,char1);
	LCD_Vid_Send_String("-");
	LCD_Vid_Send_Custom_Char(COL8,ROW1,1,char2);
	LCD_Vid_Send_String("____");
	//_delay_ms(10);
	LCD_Vid_GotoXY(COL1,ROW1);
	LCD_Vid_Send_String("____");
	LCD_Vid_Send_Custom_Char(COL5,ROW1,0,char1);
	LCD_Vid_Send_String("-");
	LCD_Vid_Send_Custom_Char(COL7,ROW1,1,char2);
	LCD_Vid_Send_String("_____");
	//_delay_ms(10);
	LCD_Vid_GotoXY(COL1,ROW1);
	LCD_Vid_Send_String("___");
	LCD_Vid_Send_Custom_Char(COL4,ROW1,0,char1);
	LCD_Vid_Send_String("-");
	LCD_Vid_Send_Custom_Char(COL6,ROW1,1,char2);
	LCD_Vid_Send_String("______");
	//_delay_ms(10);
	LCD_Vid_GotoXY(COL1,ROW1);
	LCD_Vid_Send_String("__");
	LCD_Vid_Send_Custom_Char(COL3,ROW1,0,char1);
	LCD_Vid_Send_String("-");
	LCD_Vid_Send_Custom_Char(COL5,ROW1,1,char2);
	LCD_Vid_Send_String("_______");
	//_delay_ms(10);
	LCD_Vid_GotoXY(COL1,ROW1);
	LCD_Vid_Send_String("_");
	LCD_Vid_Send_Custom_Char(COL2,ROW1,0,char1);
	LCD_Vid_Send_String("-");
	LCD_Vid_Send_Custom_Char(COL4,ROW1,1,char2);
	LCD_Vid_Send_String("________");
	//_delay_ms(10);
	LCD_Vid_GotoXY(COL1,ROW1);
	LCD_Vid_Send_Custom_Char(COL1,ROW1,0,char1);
	LCD_Vid_Send_String("-");
	LCD_Vid_Send_Custom_Char(COL3,ROW1,1,char2);
	LCD_Vid_Send_String("_________");
	//_delay_ms(10);
}
void lcd_20(){
	LCD_Vid_GotoXY(COL1,ROW1);
	LCD_Vid_Send_String("________");
	LCD_Vid_Send_Custom_Char(COL9,ROW1,0,char1);
	LCD_Vid_Send_String("--");
	LCD_Vid_Send_Custom_Char(COL12,ROW1,1,char2);
	//_delay_ms(10);
	LCD_Vid_GotoXY(COL1,ROW1);
	LCD_Vid_Send_String("_______");
	LCD_Vid_Send_Custom_Char(COL8,ROW1,0,char1);
	LCD_Vid_Send_String("--");
	LCD_Vid_Send_Custom_Char(COL11,ROW1,1,char2);
	LCD_Vid_Send_String("_");
	//_delay_ms(10);
	LCD_Vid_GotoXY(COL1,ROW1);
	LCD_Vid_Send_String("______");
	LCD_Vid_Send_Custom_Char(COL7,ROW1,0,char1);
	LCD_Vid_Send_String("--");
	LCD_Vid_Send_Custom_Char(COL10,ROW1,1,char2);
	LCD_Vid_Send_String("__");
	//_delay_ms(10);
	LCD_Vid_GotoXY(COL1,ROW1);
	LCD_Vid_Send_String("_____");
	LCD_Vid_Send_Custom_Char(COL6,ROW1,0,char1);
	LCD_Vid_Send_String("--");
	LCD_Vid_Send_Custom_Char(COL9,ROW1,1,char2);
	LCD_Vid_Send_String("___");
	//_delay_ms(10);
	LCD_Vid_GotoXY(COL1,ROW1);
	LCD_Vid_Send_String("____");
	LCD_Vid_Send_Custom_Char(COL5,ROW1,0,char1);
	LCD_Vid_Send_String("--");
	LCD_Vid_Send_Custom_Char(COL8,ROW1,1,char2);
	LCD_Vid_Send_String("____");
	//_delay_ms(10);
	LCD_Vid_GotoXY(COL1,ROW1);
	LCD_Vid_Send_String("___");
	LCD_Vid_Send_Custom_Char(COL4,ROW1,0,char1);
	LCD_Vid_Send_String("--");
	LCD_Vid_Send_Custom_Char(COL7,ROW1,1,char2);
	LCD_Vid_Send_String("_____");
	//_delay_ms(10);
	LCD_Vid_GotoXY(COL1,ROW1);
	LCD_Vid_Send_String("__");
	LCD_Vid_Send_Custom_Char(COL3,ROW1,0,char1);
	LCD_Vid_Send_String("--");
	LCD_Vid_Send_Custom_Char(COL6,ROW1,1,char2);
	LCD_Vid_Send_String("______");
	//_delay_ms(10);
	LCD_Vid_GotoXY(COL1,ROW1);
	LCD_Vid_Send_String("_");
	LCD_Vid_Send_Custom_Char(COL2,ROW1,0,char1);
	LCD_Vid_Send_String("--");
	LCD_Vid_Send_Custom_Char(COL5,ROW1,1,char2);
	LCD_Vid_Send_String("_______");
	//_delay_ms(10);
	LCD_Vid_Send_Custom_Char(COL1,ROW1,0,char1);
	LCD_Vid_Send_String("--");
	LCD_Vid_Send_Custom_Char(COL4,ROW1,1,char2);
	LCD_Vid_Send_String("________");
	//_delay_ms(10);
	LCD_Vid_GotoXY(COL1,ROW1);
	LCD_Vid_Send_String("--");
	LCD_Vid_Send_Custom_Char(COL3,ROW1,1,char2);
	LCD_Vid_Send_String("________");
	LCD_Vid_Send_Custom_Char(COL12,ROW1,0,char1);
	//_delay_ms(10);
	LCD_Vid_GotoXY(COL1,ROW1);
	LCD_Vid_Send_String("-");
	LCD_Vid_Send_Custom_Char(COL2,ROW1,1,char2);
	LCD_Vid_Send_String("________");
	LCD_Vid_Send_Custom_Char(COL11,ROW1,0,char1);
	LCD_Vid_Send_String("-");
	//_delay_ms(10);
	LCD_Vid_Send_Custom_Char(COL1,ROW1,1,char2);
	LCD_Vid_Send_String("________");
	LCD_Vid_Send_Custom_Char(COL10,ROW1,0,char1);
	LCD_Vid_Send_String("--");
	//_delay_ms(10);
}
void lcd_30(){
	LCD_Vid_GotoXY(COL1,ROW1);
	LCD_Vid_Send_String("_______");
	LCD_Vid_Send_Custom_Char(COL8,ROW1,0,char1);
	LCD_Vid_Send_String("---");
	LCD_Vid_Send_Custom_Char(COL12,ROW1,1,char2);
	//_delay_ms(10);
	LCD_Vid_GotoXY(COL1,ROW1);
	LCD_Vid_Send_String("______");
	LCD_Vid_Send_Custom_Char(COL7,ROW1,0,char1);
	LCD_Vid_Send_String("---");
	LCD_Vid_Send_Custom_Char(COL11,ROW1,1,char2);
	LCD_Vid_Send_String("_");
	//_delay_ms(10);
	LCD_Vid_GotoXY(COL1,ROW1);
	LCD_Vid_Send_String("_____");
	LCD_Vid_Send_Custom_Char(COL6,ROW1,0,char1);
	LCD_Vid_Send_String("---");
	LCD_Vid_Send_Custom_Char(COL10,ROW1,1,char2);
	LCD_Vid_Send_String("__");
	//_delay_ms(10);
	LCD_Vid_GotoXY(COL1,ROW1);
	LCD_Vid_Send_String("____");
	LCD_Vid_Send_Custom_Char(COL5,ROW1,0,char1);
	LCD_Vid_Send_String("---");
	LCD_Vid_Send_Custom_Char(COL9,ROW1,1,char2);
	LCD_Vid_Send_String("___");
	//_delay_ms(10);
	LCD_Vid_GotoXY(COL1,ROW1);
	LCD_Vid_Send_String("___");
	LCD_Vid_Send_Custom_Char(COL4,ROW1,0,char1);
	LCD_Vid_Send_String("---");
	LCD_Vid_Send_Custom_Char(COL8,ROW1,1,char2);
	LCD_Vid_Send_String("____");
	//_delay_ms(10);
	LCD_Vid_GotoXY(COL1,ROW1);
	LCD_Vid_Send_String("__");
	LCD_Vid_Send_Custom_Char(COL3,ROW1,0,char1);
	LCD_Vid_Send_String("---");
	LCD_Vid_Send_Custom_Char(COL7,ROW1,1,char2);
	LCD_Vid_Send_String("_____");
	//_delay_ms(10);
	LCD_Vid_GotoXY(COL1,ROW1);
	LCD_Vid_Send_String("_");
	LCD_Vid_Send_Custom_Char(COL2,ROW1,0,char1);
	LCD_Vid_Send_String("---");
	LCD_Vid_Send_Custom_Char(COL6,ROW1,1,char2);
	LCD_Vid_Send_String("______");
	//_delay_ms(10);
	LCD_Vid_Send_Custom_Char(COL1,ROW1,0,char1);
	LCD_Vid_Send_String("--");
	LCD_Vid_Send_Custom_Char(COL4,ROW1,1,char2);
	LCD_Vid_Send_String("________");
	//_delay_ms(10);
	LCD_Vid_GotoXY(COL1,ROW1);
	LCD_Vid_Send_String("---");
	LCD_Vid_Send_Custom_Char(COL4,ROW1,1,char2);
	LCD_Vid_Send_String("_______");
	LCD_Vid_Send_Custom_Char(COL12,ROW1,0,char1);
	//_delay_ms(10);
	LCD_Vid_GotoXY(COL1,ROW1);
	LCD_Vid_Send_String("--");
	LCD_Vid_Send_Custom_Char(COL3,ROW1,1,char2);
	LCD_Vid_Send_String("_______");
	LCD_Vid_Send_Custom_Char(COL11,ROW1,0,char1);
	LCD_Vid_Send_String("-");
	//_delay_ms(10);
	LCD_Vid_GotoXY(COL1,ROW1);
	LCD_Vid_Send_String("-");
	LCD_Vid_Send_Custom_Char(COL3,ROW1,1,char2);
	LCD_Vid_Send_String("_______");
	LCD_Vid_Send_Custom_Char(COL10,ROW1,0,char1);
	LCD_Vid_Send_String("--");
	//_delay_ms(10);
	LCD_Vid_Send_Custom_Char(COL1,ROW1,1,char2);
	LCD_Vid_Send_String("_______");
	LCD_Vid_Send_Custom_Char(COL9,ROW1,0,char1);
	LCD_Vid_Send_String("---");
	//_delay_ms(10);
}
void lcd_40(){
	LCD_Vid_GotoXY(COL1,ROW1);
	LCD_Vid_Send_String("______");
	LCD_Vid_Send_Custom_Char(COL7,ROW1,0,char1);
	LCD_Vid_Send_String("----");
	LCD_Vid_Send_Custom_Char(COL12,ROW1,1,char2);
	//_delay_ms(10);
	LCD_Vid_GotoXY(COL1,ROW1);
	LCD_Vid_Send_String("_____");
	LCD_Vid_Send_Custom_Char(COL6,ROW1,0,char1);
	LCD_Vid_Send_String("----");
	LCD_Vid_Send_Custom_Char(COL11,ROW1,1,char2);
	LCD_Vid_Send_String("_");
	//_delay_ms(10);
	LCD_Vid_GotoXY(COL1,ROW1);
	LCD_Vid_Send_String("____");
	LCD_Vid_Send_Custom_Char(COL5,ROW1,0,char1);
	LCD_Vid_Send_String("----");
	LCD_Vid_Send_Custom_Char(COL10,ROW1,1,char2);
	LCD_Vid_Send_String("__");
	//_delay_ms(10);
	LCD_Vid_GotoXY(COL1,ROW1);
	LCD_Vid_Send_String("___");
	LCD_Vid_Send_Custom_Char(COL4,ROW1,0,char1);
	LCD_Vid_Send_String("----");
	LCD_Vid_Send_Custom_Char(COL9,ROW1,1,char2);
	LCD_Vid_Send_String("___");
	//_delay_ms(10);
	LCD_Vid_GotoXY(COL1,ROW1);
	LCD_Vid_Send_String("__");
	LCD_Vid_Send_Custom_Char(COL3,ROW1,0,char1);
	LCD_Vid_Send_String("----");
	LCD_Vid_Send_Custom_Char(COL8,ROW1,1,char2);
	LCD_Vid_Send_String("____");
	//_delay_ms(10);
	LCD_Vid_GotoXY(COL1,ROW1);
	LCD_Vid_Send_String("_");
	LCD_Vid_Send_Custom_Char(COL2,ROW1,0,char1);
	LCD_Vid_Send_String("----");
	LCD_Vid_Send_Custom_Char(COL7,ROW1,1,char2);
	LCD_Vid_Send_String("_____");
	//_delay_ms(10);
	LCD_Vid_Send_Custom_Char(COL1,ROW1,0,char1);
	LCD_Vid_Send_String("----");
	LCD_Vid_Send_Custom_Char(COL6,ROW1,1,char2);
	LCD_Vid_Send_String("______");
	//_delay_ms(10);
	LCD_Vid_GotoXY(COL1,ROW1);
	LCD_Vid_Send_String("----");
	LCD_Vid_Send_Custom_Char(COL5,ROW1,1,char2);
	LCD_Vid_Send_String("______");
	LCD_Vid_Send_Custom_Char(COL12,ROW1,0,char1);
	//_delay_ms(10);
	LCD_Vid_GotoXY(COL1,ROW1);
	LCD_Vid_Send_String("---");
	LCD_Vid_Send_Custom_Char(COL4,ROW1,1,char2);
	LCD_Vid_Send_String("_______");
	LCD_Vid_Send_Custom_Char(COL11,ROW1,0,char1);
	LCD_Vid_Send_String("-");
	//_delay_ms(10);
	LCD_Vid_GotoXY(COL1,ROW1);
	LCD_Vid_Send_String("--");
	LCD_Vid_Send_Custom_Char(COL3,ROW1,1,char2);
	LCD_Vid_Send_String("_______");
	LCD_Vid_Send_Custom_Char(COL10,ROW1,0,char1);
	LCD_Vid_Send_String("--");
	//_delay_ms(10);
	LCD_Vid_GotoXY(COL1,ROW1);
	LCD_Vid_Send_String("-");
	LCD_Vid_Send_Custom_Char(COL2,ROW1,1,char2);
	LCD_Vid_Send_String("_______");
	LCD_Vid_Send_Custom_Char(COL9,ROW1,0,char1);
	LCD_Vid_Send_String("---");
	//_delay_ms(10);
	LCD_Vid_Send_Custom_Char(COL1,ROW1,1,char2);
	LCD_Vid_Send_String("_______");
	LCD_Vid_Send_Custom_Char(COL8,ROW1,0,char1);
	LCD_Vid_Send_String("----");
	//_delay_ms(10);
}
void lcd_50(){
	LCD_Vid_GotoXY(COL1,ROW1);
	LCD_Vid_Send_String("_____");
	LCD_Vid_Send_Custom_Char(COL6,ROW1,0,char1);
	LCD_Vid_Send_String("-----");
	LCD_Vid_Send_Custom_Char(COL12,ROW1,1,char2);
	//_delay_ms(10);
	LCD_Vid_GotoXY(COL1,ROW1);
	LCD_Vid_Send_String("____");
	LCD_Vid_Send_Custom_Char(COL5,ROW1,0,char1);
	LCD_Vid_Send_String("-----");
	LCD_Vid_Send_Custom_Char(COL11,ROW1,1,char2);
	LCD_Vid_Send_String("_");
	//_delay_ms(10);
	LCD_Vid_GotoXY(COL1,ROW1);
	LCD_Vid_Send_String("___");
	LCD_Vid_Send_Custom_Char(COL4,ROW1,0,char1);
	LCD_Vid_Send_String("-----");
	LCD_Vid_Send_Custom_Char(COL10,ROW1,1,char2);
	LCD_Vid_Send_String("__");
	//_delay_ms(10);
	LCD_Vid_GotoXY(COL1,ROW1);
	LCD_Vid_Send_String("__");
	LCD_Vid_Send_Custom_Char(COL3,ROW1,0,char1);
	LCD_Vid_Send_String("-----");
	LCD_Vid_Send_Custom_Char(COL9,ROW1,1,char2);
	LCD_Vid_Send_String("___");
	//_delay_ms(10);
	LCD_Vid_GotoXY(COL1,ROW1);
	LCD_Vid_Send_String("_");
	LCD_Vid_Send_Custom_Char(COL2,ROW1,0,char1);
	LCD_Vid_Send_String("-----");
	LCD_Vid_Send_Custom_Char(COL8,ROW1,1,char2);
	LCD_Vid_Send_String("____");
	//_delay_ms(10);
	LCD_Vid_Send_Custom_Char(COL1,ROW1,0,char1);
	LCD_Vid_Send_String("-----");
	LCD_Vid_Send_Custom_Char(COL7,ROW1,1,char2);
	LCD_Vid_Send_String("_____");
	//_delay_ms(10);
	LCD_Vid_GotoXY(COL1,ROW1);
	LCD_Vid_Send_String("-----");
	LCD_Vid_Send_Custom_Char(COL6,ROW1,1,char2);
	LCD_Vid_Send_String("_____");
	LCD_Vid_Send_Custom_Char(COL12,ROW1,0,char1);
	//_delay_ms(10);
	LCD_Vid_GotoXY(COL1,ROW1);
	LCD_Vid_Send_String("----");
	LCD_Vid_Send_Custom_Char(COL5,ROW1,1,char2);
	LCD_Vid_Send_String("_____");
	LCD_Vid_Send_Custom_Char(COL11,ROW1,0,char1);
	LCD_Vid_Send_String("-");
	//_delay_ms(10);
	LCD_Vid_GotoXY(COL1,ROW1);
	LCD_Vid_Send_String("---");
	LCD_Vid_Send_Custom_Char(COL4,ROW1,1,char2);
	LCD_Vid_Send_String("_____");
	LCD_Vid_Send_Custom_Char(COL10,ROW1,0,char1);
	LCD_Vid_Send_String("--");
	//_delay_ms(10);
	LCD_Vid_GotoXY(COL1,ROW1);
	LCD_Vid_Send_String("--");
	LCD_Vid_Send_Custom_Char(COL3,ROW1,1,char2);
	LCD_Vid_Send_String("_____");
	LCD_Vid_Send_Custom_Char(COL9,ROW1,0,char1);
	LCD_Vid_Send_String("---");
	//_delay_ms(10);
	LCD_Vid_GotoXY(COL1,ROW1);
	LCD_Vid_Send_String("-");
	LCD_Vid_Send_Custom_Char(COL2,ROW1,1,char2);
	LCD_Vid_Send_String("_____");
	LCD_Vid_Send_Custom_Char(COL8,ROW1,0,char1);
	LCD_Vid_Send_String("----");
	//_delay_ms(10);
	LCD_Vid_Send_Custom_Char(COL1,ROW1,1,char2);
	LCD_Vid_Send_String("_____");
	LCD_Vid_Send_Custom_Char(COL7,ROW1,0,char1);
	LCD_Vid_Send_String("-----");
	//_delay_ms(10);
}
void lcd_60(){
	LCD_Vid_GotoXY(COL1,ROW1);
	LCD_Vid_Send_String("____");
	LCD_Vid_Send_Custom_Char(COL5,ROW1,0,char1);
	LCD_Vid_Send_String("------");
	LCD_Vid_Send_Custom_Char(COL12,ROW1,1,char2);
	//_delay_ms(10);
	LCD_Vid_GotoXY(COL1,ROW1);
	LCD_Vid_Send_String("___");
	LCD_Vid_Send_Custom_Char(COL4,ROW1,0,char1);
	LCD_Vid_Send_String("------");
	LCD_Vid_Send_Custom_Char(COL11,ROW1,1,char2);
	LCD_Vid_Send_String("_");
	//_delay_ms(10);
	LCD_Vid_GotoXY(COL1,ROW1);
	LCD_Vid_Send_String("__");
	LCD_Vid_Send_Custom_Char(COL3,ROW1,0,char1);
	LCD_Vid_Send_String("------");
	LCD_Vid_Send_Custom_Char(COL10,ROW1,1,char2);
	LCD_Vid_Send_String("__");
	//_delay_ms(10);
	LCD_Vid_GotoXY(COL1,ROW1);
	LCD_Vid_Send_String("_");
	LCD_Vid_Send_Custom_Char(COL2,ROW1,0,char1);
	LCD_Vid_Send_String("------");
	LCD_Vid_Send_Custom_Char(COL9,ROW1,1,char2);
	LCD_Vid_Send_String("___");
	//_delay_ms(10);
	LCD_Vid_Send_Custom_Char(COL1,ROW1,0,char1);
	LCD_Vid_Send_String("------");
	LCD_Vid_Send_Custom_Char(COL8,ROW1,1,char2);
	LCD_Vid_Send_String("____");
	//_delay_ms(10);
	LCD_Vid_GotoXY(COL1,ROW1);
	LCD_Vid_Send_String("------");
	LCD_Vid_Send_Custom_Char(COL7,ROW1,1,char2);
	LCD_Vid_Send_String("____");
	LCD_Vid_Send_Custom_Char(COL12,ROW1,0,char1);
	//_delay_ms(10);
	LCD_Vid_GotoXY(COL1,ROW1);
	LCD_Vid_Send_String("-----");
	LCD_Vid_Send_Custom_Char(COL6,ROW1,1,char2);
	LCD_Vid_Send_String("____");
	LCD_Vid_Send_Custom_Char(COL11,ROW1,0,char1);
	LCD_Vid_Send_String("-");
	//_delay_ms(10);
	LCD_Vid_GotoXY(COL1,ROW1);
	LCD_Vid_Send_String("----");
	LCD_Vid_Send_Custom_Char(COL5,ROW1,1,char2);
	LCD_Vid_Send_String("____");
	LCD_Vid_Send_Custom_Char(COL10,ROW1,0,char1);
	LCD_Vid_Send_String("--");
	//_delay_ms(10);
	LCD_Vid_GotoXY(COL1,ROW1);
	LCD_Vid_Send_String("---");
	LCD_Vid_Send_Custom_Char(COL4,ROW1,1,char2);
	LCD_Vid_Send_String("____");
	LCD_Vid_Send_Custom_Char(COL9,ROW1,0,char1);
	LCD_Vid_Send_String("---");
	//_delay_ms(10);
	LCD_Vid_GotoXY(COL1,ROW1);
	LCD_Vid_Send_String("--");
	LCD_Vid_Send_Custom_Char(COL3,ROW1,1,char2);
	LCD_Vid_Send_String("____");
	LCD_Vid_Send_Custom_Char(COL8,ROW1,0,char1);
	LCD_Vid_Send_String("----");
	//_delay_ms(10);
	LCD_Vid_GotoXY(COL1,ROW1);
	LCD_Vid_Send_String("-");
	LCD_Vid_Send_Custom_Char(COL2,ROW1,1,char2);
	LCD_Vid_Send_String("____");
	LCD_Vid_Send_Custom_Char(COL7,ROW1,0,char1);
	LCD_Vid_Send_String("-----");
	//_delay_ms(10);
	LCD_Vid_Send_Custom_Char(COL1,ROW1,1,char2);
	LCD_Vid_Send_String("____");
	LCD_Vid_Send_Custom_Char(COL6,ROW1,0,char1);
	LCD_Vid_Send_String("------");
	//_delay_ms(10);
}
void lcd_70(){
	LCD_Vid_GotoXY(COL1,ROW1);
	LCD_Vid_Send_String("___");
	LCD_Vid_Send_Custom_Char(COL4,ROW1,0,char1);
	LCD_Vid_Send_String("-------");
	LCD_Vid_Send_Custom_Char(COL12,ROW1,1,char2);
	//_delay_ms(10);
	LCD_Vid_GotoXY(COL1,ROW1);
	LCD_Vid_Send_String("__");
	LCD_Vid_Send_Custom_Char(COL3,ROW1,0,char1);
	LCD_Vid_Send_String("-------");
	LCD_Vid_Send_Custom_Char(COL11,ROW1,1,char2);
	LCD_Vid_Send_String("_");
	//_delay_ms(10);
	LCD_Vid_GotoXY(COL1,ROW1);
	LCD_Vid_Send_String("_");
	LCD_Vid_Send_Custom_Char(COL2,ROW1,0,char1);
	LCD_Vid_Send_String("-------");
	LCD_Vid_Send_Custom_Char(COL10,ROW1,1,char2);
	LCD_Vid_Send_String("__");
	//_delay_ms(10);
	LCD_Vid_Send_Custom_Char(COL1,ROW1,0,char1);
	LCD_Vid_Send_String("-------");
	LCD_Vid_Send_Custom_Char(COL9,ROW1,1,char2);
	LCD_Vid_Send_String("___");
	//_delay_ms(10);
	LCD_Vid_GotoXY(COL1,ROW1);
	LCD_Vid_Send_String("-------");
	LCD_Vid_Send_Custom_Char(COL8,ROW1,1,char2);
	LCD_Vid_Send_String("___");
	LCD_Vid_Send_Custom_Char(COL12,ROW1,0,char1);
	//_delay_ms(10);
	LCD_Vid_GotoXY(COL1,ROW1);
	LCD_Vid_Send_String("------");
	LCD_Vid_Send_Custom_Char(COL7,ROW1,1,char2);
	LCD_Vid_Send_String("___");
	LCD_Vid_Send_Custom_Char(COL11,ROW1,0,char1);
	LCD_Vid_Send_String("-");
	//_delay_ms(10);
	LCD_Vid_GotoXY(COL1,ROW1);
	LCD_Vid_Send_String("-----");
	LCD_Vid_Send_Custom_Char(COL6,ROW1,1,char2);
	LCD_Vid_Send_String("___");
	LCD_Vid_Send_Custom_Char(COL10,ROW1,0,char1);
	LCD_Vid_Send_String("--");
	//_delay_ms(10);
	LCD_Vid_GotoXY(COL1,ROW1);
	LCD_Vid_Send_String("----");
	LCD_Vid_Send_Custom_Char(COL5,ROW1,1,char2);
	LCD_Vid_Send_String("___");
	LCD_Vid_Send_Custom_Char(COL9,ROW1,0,char1);
	LCD_Vid_Send_String("---");
	//_delay_ms(10);
	LCD_Vid_GotoXY(COL1,ROW1);
	LCD_Vid_Send_String("---");
	LCD_Vid_Send_Custom_Char(COL4,ROW1,1,char2);
	LCD_Vid_Send_String("___");
	LCD_Vid_Send_Custom_Char(COL8,ROW1,0,char1);
	LCD_Vid_Send_String("----");
	//_delay_ms(10);
	LCD_Vid_GotoXY(COL1,ROW1);
	LCD_Vid_Send_String("--");
	LCD_Vid_Send_Custom_Char(COL3,ROW1,1,char2);
	LCD_Vid_Send_String("___");
	LCD_Vid_Send_Custom_Char(COL7,ROW1,0,char1);
	LCD_Vid_Send_String("-----");
	//_delay_ms(10);
	LCD_Vid_GotoXY(COL1,ROW1);
	LCD_Vid_Send_String("-");
	LCD_Vid_Send_Custom_Char(COL2,ROW1,1,char2);
	LCD_Vid_Send_String("___");
	LCD_Vid_Send_Custom_Char(COL6,ROW1,0,char1);
	LCD_Vid_Send_String("------");
	//_delay_ms(10);
	LCD_Vid_Send_Custom_Char(COL1,ROW1,1,char2);
	LCD_Vid_Send_String("___");
	LCD_Vid_Send_Custom_Char(COL5,ROW1,0,char1);
	LCD_Vid_Send_String("-------");
	//_delay_ms(10);
}
void lcd_80(){
	LCD_Vid_GotoXY(COL1,ROW1);
	LCD_Vid_Send_String("__");
	LCD_Vid_Send_Custom_Char(COL3,ROW1,0,char1);
	LCD_Vid_Send_String("--------");
	LCD_Vid_Send_Custom_Char(COL12,ROW1,1,char2);
	//_delay_ms(10);
	LCD_Vid_GotoXY(COL1,ROW1);
	LCD_Vid_Send_String("_");
	LCD_Vid_Send_Custom_Char(COL2,ROW1,0,char1);
	LCD_Vid_Send_String("--------");
	LCD_Vid_Send_Custom_Char(COL11,ROW1,1,char2);
	LCD_Vid_Send_String("_");
	//_delay_ms(10);
	LCD_Vid_Send_Custom_Char(COL1,ROW1,0,char1);
	LCD_Vid_Send_String("--------");
	LCD_Vid_Send_Custom_Char(COL10,ROW1,1,char2);
	LCD_Vid_Send_String("__");
	//_delay_ms(10);
	LCD_Vid_GotoXY(COL1,ROW1);
	LCD_Vid_Send_String("--------");
	LCD_Vid_Send_Custom_Char(COL9,ROW1,1,char2);
	LCD_Vid_Send_String("__");
	LCD_Vid_Send_Custom_Char(COL12,ROW1,0,char1);
	//_delay_ms(10);
	LCD_Vid_GotoXY(COL1,ROW1);
	LCD_Vid_Send_String("-------");
	LCD_Vid_Send_Custom_Char(COL8,ROW1,1,char2);
	LCD_Vid_Send_String("__");
	LCD_Vid_Send_Custom_Char(COL11,ROW1,0,char1);
	LCD_Vid_Send_String("-");
	//_delay_ms(10);
	LCD_Vid_GotoXY(COL1,ROW1);
	LCD_Vid_Send_String("------");
	LCD_Vid_Send_Custom_Char(COL7,ROW1,1,char2);
	LCD_Vid_Send_String("__");
	LCD_Vid_Send_Custom_Char(COL10,ROW1,0,char1);
	LCD_Vid_Send_String("--");
	//_delay_ms(10);
	LCD_Vid_GotoXY(COL1,ROW1);
	LCD_Vid_Send_String("-----");
	LCD_Vid_Send_Custom_Char(COL6,ROW1,1,char2);
	LCD_Vid_Send_String("__");
	LCD_Vid_Send_Custom_Char(COL9,ROW1,0,char1);
	LCD_Vid_Send_String("---");
	//_delay_ms(10);
	LCD_Vid_GotoXY(COL1,ROW1);
	LCD_Vid_Send_String("----");
	LCD_Vid_Send_Custom_Char(COL5,ROW1,1,char2);
	LCD_Vid_Send_String("__");
	LCD_Vid_Send_Custom_Char(COL8,ROW1,0,char1);
	LCD_Vid_Send_String("----");
	//_delay_ms(10);
	LCD_Vid_GotoXY(COL1,ROW1);
	LCD_Vid_Send_String("---");
	LCD_Vid_Send_Custom_Char(COL4,ROW1,1,char2);
	LCD_Vid_Send_String("__");
	LCD_Vid_Send_Custom_Char(COL7,ROW1,0,char1);
	LCD_Vid_Send_String("-----");
	//_delay_ms(10);
	LCD_Vid_GotoXY(COL1,ROW1);
	LCD_Vid_Send_String("--");
	LCD_Vid_Send_Custom_Char(COL3,ROW1,1,char2);
	LCD_Vid_Send_String("__");
	LCD_Vid_Send_Custom_Char(COL6,ROW1,0,char1);
	LCD_Vid_Send_String("------");
	//_delay_ms(10);
	LCD_Vid_GotoXY(COL1,ROW1);
	LCD_Vid_Send_String("-");
	LCD_Vid_Send_Custom_Char(COL2,ROW1,1,char2);
	LCD_Vid_Send_String("__");
	LCD_Vid_Send_Custom_Char(COL5,ROW1,0,char1);
	LCD_Vid_Send_String("-------");
	//_delay_ms(10);
	LCD_Vid_Send_Custom_Char(COL1,ROW1,1,char2);
	LCD_Vid_Send_String("__");
	LCD_Vid_Send_Custom_Char(COL4,ROW1,0,char1);
	LCD_Vid_Send_String("--------");
	//_delay_ms(10);
}
void lcd_90(){
	LCD_Vid_GotoXY(COL1,ROW1);
	LCD_Vid_Send_String("_");
	LCD_Vid_Send_Custom_Char(COL2,ROW1,0,char1);
	LCD_Vid_Send_String("---------");
	LCD_Vid_Send_Custom_Char(COL12,ROW1,1,char2);
	//_delay_ms(10);
	LCD_Vid_Send_Custom_Char(COL1,ROW1,0,char1);
	LCD_Vid_Send_String("---------");
	LCD_Vid_Send_Custom_Char(COL11,ROW1,1,char2);
	LCD_Vid_Send_String("_");
	//_delay_ms(10);
	LCD_Vid_GotoXY(COL1,ROW1);
	LCD_Vid_Send_String("---------");
	LCD_Vid_Send_Custom_Char(COL10,ROW1,1,char2);
	LCD_Vid_Send_String("_");
	LCD_Vid_Send_Custom_Char(COL12,ROW1,0,char1);
	//_delay_ms(10);
	LCD_Vid_GotoXY(COL1,ROW1);
	LCD_Vid_Send_String("--------");
	LCD_Vid_Send_Custom_Char(COL9,ROW1,1,char2);
	LCD_Vid_Send_String("_");
	LCD_Vid_Send_Custom_Char(COL11,ROW1,0,char1);
	LCD_Vid_Send_String("-");
	//_delay_ms(10);
	LCD_Vid_GotoXY(COL1,ROW1);
	LCD_Vid_Send_String("-------");
	LCD_Vid_Send_Custom_Char(COL8,ROW1,1,char2);
	LCD_Vid_Send_String("_");
	LCD_Vid_Send_Custom_Char(COL10,ROW1,0,char1);
	LCD_Vid_Send_String("--");
	//_delay_ms(10);
	LCD_Vid_GotoXY(COL1,ROW1);
	LCD_Vid_Send_String("------");
	LCD_Vid_Send_Custom_Char(COL7,ROW1,1,char2);
	LCD_Vid_Send_String("_");
	LCD_Vid_Send_Custom_Char(COL9,ROW1,0,char1);
	LCD_Vid_Send_String("---");
	//_delay_ms(10);
	LCD_Vid_GotoXY(COL1,ROW1);
	LCD_Vid_Send_String("-----");
	LCD_Vid_Send_Custom_Char(COL6,ROW1,1,char2);
	LCD_Vid_Send_String("_");
	LCD_Vid_Send_Custom_Char(COL8,ROW1,0,char1);
	LCD_Vid_Send_String("----");
	//_delay_ms(10);
	LCD_Vid_GotoXY(COL1,ROW1);
	LCD_Vid_Send_String("----");
	LCD_Vid_Send_Custom_Char(COL5,ROW1,1,char2);
	LCD_Vid_Send_String("_");
	LCD_Vid_Send_Custom_Char(COL7,ROW1,0,char1);
	LCD_Vid_Send_String("-----");
	//_delay_ms(10);
	LCD_Vid_GotoXY(COL1,ROW1);
	LCD_Vid_Send_String("---");
	LCD_Vid_Send_Custom_Char(COL4,ROW1,1,char2);
	LCD_Vid_Send_String("_");
	LCD_Vid_Send_Custom_Char(COL6,ROW1,0,char1);
	LCD_Vid_Send_String("------");
	//_delay_ms(10);
	LCD_Vid_GotoXY(COL1,ROW1);
	LCD_Vid_Send_String("--");
	LCD_Vid_Send_Custom_Char(COL3,ROW1,1,char2);
	LCD_Vid_Send_String("_");
	LCD_Vid_Send_Custom_Char(COL5,ROW1,0,char1);
	LCD_Vid_Send_String("-------");
	//_delay_ms(10);
	LCD_Vid_GotoXY(COL1,ROW1);
	LCD_Vid_Send_String("-");
	LCD_Vid_Send_Custom_Char(COL2,ROW1,1,char2);
	LCD_Vid_Send_String("_");
	LCD_Vid_Send_Custom_Char(COL4,ROW1,0,char1);
	LCD_Vid_Send_String("--------");
	//_delay_ms(10);
	LCD_Vid_Send_Custom_Char(COL1,ROW1,1,char2);
	LCD_Vid_Send_String("_");
	LCD_Vid_Send_Custom_Char(COL3,ROW1,0,char1);
	LCD_Vid_Send_String("---------");
	//_delay_ms(10);
}
void lcd_100(){
	LCD_Vid_GotoXY(COL1,ROW1);
	LCD_Vid_Send_String("------------");
}
void SW_ICU();

int main(void)
{
	DIO_Vid_Set_Pin_Dir(PORTB,PIN3,OUTPUT);
	DIO_Vid_Set_Pin_Dir(PORTC,PIN2,OUTPUT);
	
	/* LCD INIT */
    DIO_Vid_Set_Port_Dir(LCD_DPORT, 0XF0);
    DIO_Vid_Set_Pin_Dir(LCD_CPORT, LCD_RS_PIN, OUTPUT);
    DIO_Vid_Set_Pin_Dir(LCD_CPORT, LCD_RW_PIN, OUTPUT);
    DIO_Vid_Set_Pin_Dir(LCD_CPORT, LCD_EN_PIN, OUTPUT);
    LCD_Vid_Init();
	
	/* ENABLE GIE */
	GIE_Vid_Interrupt_Enable();
	
	/* INTERRUPT INIT */
	EXT_Vid_Interrupt_Init0(RISING_EDGE);
	EXT_Vid_Interrupt_Init12();
	EXT_Vid_Enable_Interrupt0();
	EXT_Vid_Enable_Interrupt1();
	EXT_Vid_Enable_Interrupt2();
	
	/* INIT TIMER 1 */
	TIMER1_Vid_NormalMode_Init();
	
	/* CALLBACK FUNCTION */
	SET_CallBack(SW_ICU);
	
    while (1) 
    {
		TIMER0_Vid_FastPWM(ton_val);
		if(ton_val == 0){
			LCD_Vid_GotoXY(COL1,ROW2);
			LCD_Vid_Send_String("ON=");
			LCD_Vid_GotoXY(COL6,ROW2);
			LCD_Vid_Send_Data(' ');
			LCD_Vid_GotoXY(COL5,ROW2);
			LCD_Vid_Send_Data(' ');
			LCD_Vid_GotoXY(COL4,ROW2);
			LCD_Vid_Send_Number(0);
			LCD_Vid_GotoXY(COL10,ROW2);
			LCD_Vid_Send_String("TOV=");
			LCD_Vid_Send_Number(256);
			LCD_Vid_GotoXY(COL15,ROW1);
			LCD_Vid_Send_Data(' ');
			LCD_Vid_GotoXY(COL16,ROW1);
			LCD_Vid_Send_Data(' ');
			LCD_Vid_GotoXY(COL13,ROW1);
			LCD_Vid_Send_Number(ton_val);
			LCD_Vid_Send_Data('%');
			lcd_0();
		}
		else if(ton_val == 100){
			LCD_Vid_GotoXY(COL1,ROW2);
			LCD_Vid_Send_String("ON=");
			LCD_Vid_GotoXY(COL6,ROW2);
			LCD_Vid_Send_Data(' ');
			LCD_Vid_GotoXY(COL5,ROW2);
			LCD_Vid_Send_Data(' ');
			LCD_Vid_GotoXY(COL4,ROW2);
			LCD_Vid_Send_Number(256);
			LCD_Vid_GotoXY(COL10,ROW2);
			LCD_Vid_Send_String("TOV=");
			LCD_Vid_Send_Number(256);
			LCD_Vid_GotoXY(COL13,ROW1);
			LCD_Vid_Send_Number(ton_val);
			LCD_Vid_Send_Data('%');
			lcd_100();
		}
		else{
			LCD_Vid_GotoXY(COL1,ROW2);
			LCD_Vid_Send_String("ON=");
			LCD_Vid_GotoXY(COL6,ROW2);
			LCD_Vid_Send_Data(' ');
			LCD_Vid_GotoXY(COL5,ROW2);
			LCD_Vid_Send_Data(' ');
			LCD_Vid_GotoXY(COL4,ROW2);
			LCD_Vid_Send_Number(on_tick);
			LCD_Vid_GotoXY(COL10,ROW2);
			LCD_Vid_Send_String("TOV=");
			LCD_Vid_Send_Number(tov_tick);
			LCD_Vid_GotoXY(COL16,ROW1);
			LCD_Vid_Send_Data(' ');
			LCD_Vid_GotoXY(COL13,ROW1);
			LCD_Vid_Send_Number(ton_val);
			LCD_Vid_Send_Data('%');
			switch(ton_val){
				case 10 : lcd_10(); break;
				case 20 : lcd_20(); break;
				case 30 : lcd_30(); break;
				case 40 : lcd_40(); break;
				case 50 : lcd_50(); break;
				case 60 : lcd_60(); break;
				case 70 : lcd_70(); break;
				case 80 : lcd_80(); break;
				case 90 : lcd_90(); break;
			}
		}
    }
}

void SW_ICU(){
	static u8 count = 0;
	count++;
	if(count == 1){
		/* RESET TIMER */
		TIMER1_Vid_Reset_Timer();
		EXT_Vid_Interrupt_Init0(FALLING_EDGE); 
	}
	else if(count == 2){
		on_tick = TIMER1_u32_ReadVal();
		EXT_Vid_Interrupt_Init0(RISING_EDGE);	
	}
	else if(count == 3){
		tov_tick = TIMER1_u32_ReadVal();
		count = 0;
		TIMER1_Vid_Reset_Timer();
	}
}

/* THIS IS ISR() FUNCTION IN WHICH WHEN INT1 IS HAPPEN IT AUTOMATICALLY JUMP TO THIS FUNCTION TO DO IT */
void __vector_2(void)__attribute__((signal)) ;
void __vector_2(void){
	
	if(ton_val >0){
		ton_val -= 10;
	}
}


/* THIS IS ISR() FUNCTION IN WHICH WHEN INT2 IS HAPPEN IT AUTOMATICALLY JUMP TO THIS FUNCTION TO DO IT */
void __vector_3(void)__attribute__((signal)) ;
void __vector_3(void){
	if(ton_val <100){
		ton_val += 10;
	}
}