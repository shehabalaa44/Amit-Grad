/*
* UART.h
*
* Created: 20-Oct-20 8:27:10 PM
*  Author: Jean
*/


#ifndef UART_H_
#define UART_H_

#include <avr/io.h>
#define F_CPU 16000000UL

#define BaudRate 9600

#ifndef DoubleSpeed
#define MyUBRR ((F_CPU/(16UL*BaudRate))-1)
#else
#define MyUBRR ((F_CPU/(8UL*BaudRate))-1)
#endif

void Uart_Init();
void UartSend(char data);
void UartSendString(char * string);
unsigned char UartReceive();

#endif /* UART_H_ */