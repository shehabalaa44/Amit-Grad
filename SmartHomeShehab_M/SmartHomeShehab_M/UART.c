/*
 * UART.c
 *
 * Created: 20-Oct-20 8:26:53 PM
 *  Author: Jean
 */ 

#include "UART.h"

void Uart_Init(){
	UCSRB = (1<<TXEN)|(1<<RXEN);
	UCSRC = (1<<URSEL)|(1<<UCSZ0)|(1<<UCSZ1);
	UBRRL = MyUBRR;
	UBRRH = (MyUBRR>>8);
}

void UartSend(char data){
	while(!(UCSRA & (1<<UDRE)));
	UDR = data;                                
}

unsigned char UartReceive(){
	while(!(UCSRA & (1<<RXC)));
	return UDR;
}

void UartSendString(char * string){
	unsigned char i = 0;
	while(string[i] != '\0'){
		UartSend(string[i]);
		i++;
	}
}