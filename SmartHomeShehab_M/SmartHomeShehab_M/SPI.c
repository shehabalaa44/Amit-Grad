/*
 * SPI.c
 *
 * Created: 08-Dec-20 8:48:17 PM
 *  Author: Jean
 */ 
#include "SPI.h"
#include <avr/io.h>

void SPI_Init(SPIState state){
	switch(state){
		case Master:
		SPIDDR |= (1<<SS)|(1<<MOSI)|(1<<SCK);
		SPIDDR &=~ (1<<MISO);
		SlaveDIS();
		//SPCR |= (1<<MSTR)|(1<<SPE);
		SPI->MySPCR.S_MSTR = 1;
		SPI->MySPCR.S_SPE = 1;
		break;
		case Slave:
		SPIDDR &=~ ((1<<SS)|(1<<MOSI)|(1<<SCK));
		SPIDDR |= (1<<MISO);
		//SPCR |= (1<<SPE);
		SPI->MySPCR.S_SPE = 1;
		break;
	}
}

unsigned char SPITxRx(unsigned char data){
	SPDR = data;
	while(!(SPSR & (1<<SPIF)));
	return SPDR;
}