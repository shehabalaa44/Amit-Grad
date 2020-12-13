/*
 * SPI.h
 *
 * Created: 08-Dec-20 8:48:02 PM
 *  Author: Jean
 */ 


#ifndef SPI_H_
#define SPI_H_

#include "DIO.h"
#define F_CPU 16000000UL
#include <util/delay.h>

#define SS 4
#define MOSI 5
#define MISO 6
#define SCK 7

#define SPIPort PORTB_Reg
#define SPIDDR DDRB_Reg

#define  SlaveEN() (SPIPort &=~ (1<<SS))
#define  SlaveDIS() (SPIPort |= (1<<SS))

typedef enum{
	Master = 0,
	Slave
	}SPIState;

typedef struct{
	unsigned char S_SPR:2;
	unsigned char S_CPHA:1;
	unsigned char S_CPOL:1;
	unsigned char S_MSTR:1;
	unsigned char S_DORD:1;
	unsigned char S_SPE:1;
	unsigned char S_SPIE:1;
	}SPISPCRBitsType;

typedef struct{
	SPISPCRBitsType MySPCR;
	unsigned char MySPSR;
	unsigned char MySPDR; 
	}SPIRegType;
	
#define SPI ((volatile SPIRegType *)0x2D)

void SPI_Init(SPIState state);
unsigned char SPITxRx(unsigned char data);

#endif /* SPI_H_ */