/*
* SmartHomeShehab_S.c
*
* Created: 13-Dec-20 2:54:37 PM
* Author : Jean
*/

#include "DIO.h"
#include "LCD.h"
#include "SPI.h"
#include "ADC.h"
#include <stdlib.h>
#define F_CPU 16000000UL
#include <util/delay.h>
#include <avr/io.h>

void Temp_Read();

int main(void)
{
	unsigned char Command;
	DIO_Init();
	LCD_Init();
	SPI_Init(Slave);
	ADC_Init();
	OCR1A = 200;
	TCCR1A = (1<<WGM10)|(1<<COM1A1);
	TCCR1B = (1<<WGM12)|(1<<CS01);
	while (1)
	{
		Command = SPITxRx(11);
		switch(Command){
			case 1:
			LCD_String("Lights 1");
			LCD_StringPos("ON",2,0);
			DIO_Write(DIO_ChannelC0,STD_High);
			_delay_ms(1000);
			LCD_Cmd(0x01);
			break;
			case 2:
			LCD_String("Lights 1");
			LCD_StringPos("OFF",2,4);
			DIO_Write(DIO_ChannelC0,STD_Low);
			_delay_ms(1000);
			LCD_Cmd(0x01);
			break;
			case 3:
			LCD_String("Lights 2");
			LCD_StringPos("ON",2,7);
			DIO_Write(DIO_ChannelC1,STD_High);
			_delay_ms(1000);
			LCD_Cmd(0x01);
			break;
			case 4:
			LCD_String("Lights 2");
			LCD_StringPos("OFF",2,7);
			DIO_Write(DIO_ChannelC1,STD_Low);
			_delay_ms(1000);
			LCD_Cmd(0x01);
			break;
			case 5:
			LCD_String("Motor ON");
			LCD_StringPos("Forward",2,0);
			DIO_Write(DIO_ChannelC5,STD_High);
			DIO_Write(DIO_ChannelC6,STD_Low);
			_delay_ms(1000);
			LCD_Cmd(0x01);
			break;
			case 6:
			LCD_String("Motor ON");
			LCD_StringPos("Backward",2,0);
			DIO_Write(DIO_ChannelC5,STD_Low);
			DIO_Write(DIO_ChannelC6,STD_High);
			_delay_ms(1000);
			LCD_Cmd(0x01);
			break;
			case 7:
			LCD_String("Motor OFF");
			DIO_Write(DIO_ChannelC5,STD_Low);
			DIO_Write(DIO_ChannelC6,STD_Low);
			_delay_ms(1000);
			LCD_Cmd(0x01);
			break;
		}
		Temp_Read();
	}
}

void Temp_Read(){
	unsigned short temp = ADC_Read(1);
	temp /= 4;
	SPITxRx(temp) == 20;
}