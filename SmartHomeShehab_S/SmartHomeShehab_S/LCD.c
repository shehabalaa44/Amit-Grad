/*
* LCD.c
*
* Created: 9/29/2020 7:06:22 PM
*  Author: Jean
*/

#include "LCD.h"

void LCD_Init(){
	DIO_Write(RW,STD_Low);
	_delay_ms(20);
	LCD_Cmd(0x33);
	_delay_us(200);
	LCD_Cmd(0x32);
	LCD_Cmd(0x28);
	LCD_Cmd(0x06);
	LCD_Cmd(0x0C);
	LCD_Cmd(0x01);
	_delay_ms(2);
}

void LCD_Cmd(Uint8 cmd){
	LCDDataPort = (LCDDataPort & 0x0F) | (cmd & 0xF0);
	DIO_Write(RS,STD_Low);
	DIO_Write(E,STD_High);
	_delay_us(100);
	DIO_Write(E,STD_Low);
	
	_delay_ms(5);
	
	LCDDataPort = (LCDDataPort & 0x0F) | (cmd << 4);
	DIO_Write(RS,STD_Low);
	DIO_Write(E,STD_High);
	_delay_us(100);
	DIO_Write(E,STD_Low);
	_delay_ms(2);
}

void LCD_Char(Sint8 data){
	LCDDataPort = (LCDDataPort & 0x0F) | (data & 0xF0);
	DIO_Write(RS,STD_High);
	DIO_Write(E,STD_High);
	_delay_us(100);
	DIO_Write(E,STD_Low);
	
	_delay_ms(5);
	
	LCDDataPort = (LCDDataPort & 0x0F) | (data << 4);
	DIO_Write(RS,STD_High);
	DIO_Write(E,STD_High);
	_delay_us(100);
	DIO_Write(E,STD_Low);
	_delay_ms(2);
}

void LCD_String(Sint8 * string){
	Uint8 count = 0;
	while (string[count] != '\0')
	{
		LCD_Char(string[count]);
		count++;
	}
}

void LCD_StringPos(Sint8 * string,Uint8 line,Uint8 pos){
	switch(line){
		case 1:
		LCD_Cmd(0x80 | (pos & 0x0F));
		LCD_String(string);
		break;
		case 2:
		LCD_Cmd(0xC0 | (pos & 0x0F));
		LCD_String(string);
		break;
	}
}

void LCD_Custom_Char(Uint8 * data,Uint8 loc){
	if(loc < 8){
		Uint8 i = 0;
		LCD_Cmd(0x40 + (loc*8));
		for (i = 0;i < 8;i++)
		{
			LCD_Char(data[i]);
		}
	}
}