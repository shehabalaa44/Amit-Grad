/*
* SmartHomeShehab alaa and amr alaa _M.c
*
* Created: 13-Dec-20 2:54:03 PM
* Author : Jean
*/

#include "DIO.h"
#include "LCD.h"
#include "UART.h"
#include "SPI.h"
#define F_CPU 16000000UL
#include <util/delay.h>
#include <stdlib.h>

void Temp_Receive();

int main(void)
{
	DIO_Init();
	LCD_Init();
	Uart_Init();
	SPI_Init(Master);
	SlaveEN();
	unsigned char Order;
	while (1)
	{
		LCD_StringPos("Welcome Shehab and amr",1,0);
		LCD_StringPos("Temperature:",2,0);
		Order = UartReceive();
		if (Order == '1')
		{
			UartSendString("Lights 1 ON");
			SPITxRx(1) == 55;
			_delay_ms(500);
		}
		if (Order == '2')
		{
			UartSendString("Lights 1 OFF");
			SPITxRx(2) == 55;
			_delay_ms(500);
		}
		if (Order == '3')
		{
			UartSendString("Lights 2 ON");
			SPITxRx(3) == 55;
			_delay_ms(500);
		}
		if (Order == '4')
		{
			UartSendString("Lights 2 OFF");
			SPITxRx(4) == 55;
			_delay_ms(500);
		}
		if (Order == '5')
		{
			UartSendString("Motor ON CW");
			SPITxRx(5) == 55;
			_delay_ms(500);
		}
		if (Order == '6')
		{
			UartSendString("Motor ON Anti_CW");
			SPITxRx(6) == 55;
			_delay_ms(500);
		}
		if (Order == '7')
		{
			UartSendString("Motor OFF");
			SPITxRx(7) == 55;
			_delay_ms(500);
		}
		Temp_Receive();
	}
}

void Temp_Receive(){
	unsigned char temp = SPITxRx(20);
	char temperature[5];
	itoa(temp,temperature,10);
	LCD_StringPos(temperature,2,14);
	_delay_ms(500);
}
