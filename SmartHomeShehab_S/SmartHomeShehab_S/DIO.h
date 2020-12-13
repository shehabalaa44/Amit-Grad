/*
 * DIO.h
 *
 * Created: 08-Dec-20 7:07:30 PM
 *  Author: Jean
 */ 


#ifndef DIO_H_
#define DIO_H_

#include "BitMath.h"
#include "STD_Types.h"
#include "DIO_HW.h"
#include "DIO_Types.h"
#include "DIO_CFG.h"

void DIO_Write(DIO_ChannelTypes ChannelID,STD_LevelTypes Level);
STD_LevelTypes DIO_Read(DIO_ChannelTypes ChannelId);
void DIO_Toggle(DIO_ChannelTypes ChannelId);

#endif /* DIO_H_ */