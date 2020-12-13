/*
 * DIO_CFG.h
 *
 * Created: 08-Dec-20 7:29:39 PM
 *  Author: Jean
 */ 


#ifndef DIO_CFG_H_
#define DIO_CFG_H_

#include "DIO.h"

typedef struct{
	DIO_DirTypes PinDir;
	STD_LevelTypes PINLevel;
	}DIO_PinCFG;
	
#define PINCOUNT 32

void DIO_Init(void);

#endif /* DIO_CFG_H_ */