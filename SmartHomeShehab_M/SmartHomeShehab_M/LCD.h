/*
 * LCD.h
 *
 * Created: 9/29/2020 7:05:58 PM
 *  Author: Jean
 */ 


#ifndef LCD_H_
#define LCD_H_

#include "DIO.h"
#define  F_CPU 16000000UL
#include <Util/delay.h>

#define RS DIO_ChannelB1
#define RW DIO_ChannelB2
#define E DIO_ChannelB3

#define LCDDataPort PORTA_Reg

void LCD_Init();
void LCD_Cmd(Uint8 cmd);
void LCD_Char(Sint8 data);
void LCD_String(Sint8 * string);
void LCD_StringPos(Sint8 * string,Uint8 line,Uint8 pos);
void LCD_Custom_Char(Uint8 * data,Uint8 loc);

#endif /* LCD_H_ */