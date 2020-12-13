/*
* DIO.c
*
* Created: 08-Dec-20 7:07:46 PM
*  Author: Jean
*/
#include "DIO.h"

void DIO_Write(DIO_ChannelTypes ChannelID,STD_LevelTypes Level){
	DIO_PortTypes Portx = ChannelID/8;
	DIO_ChannelTypes ChannelPos = ChannelID%8;
	switch(Portx){
		case DIO_PortA:
		if (Level == STD_High)
		{
			SetBit(PORTA_Reg,ChannelPos);
		}
		else{
			ClearBit(PORTA_Reg,ChannelPos);
		}
		break;
		case DIO_PortB:
		if (Level == STD_High)
		{
			SetBit(PORTB_Reg,ChannelPos);
		}
		else{
			ClearBit(PORTB_Reg,ChannelPos);
		}
		break;
		case DIO_PortC:
		if (Level == STD_High)
		{
			SetBit(PORTC_Reg,ChannelPos);
		}
		else{
			ClearBit(PORTC_Reg,ChannelPos);
		}
		break;
		case DIO_PortD:
		if (Level == STD_High)
		{
			SetBit(PORTD_Reg,ChannelPos);
		}
		else{
			ClearBit(PORTD_Reg,ChannelPos);
		}
		break;
	}
}

STD_LevelTypes DIO_Read(DIO_ChannelTypes ChannelId){
	STD_LevelTypes ChannelBit = STD_Low;
	DIO_PortTypes Portx = ChannelId/8;
	DIO_ChannelTypes ChannelPos = ChannelId%8;
	switch(Portx){
		case DIO_PortA:
		ChannelBit = GetBit(PINA_Reg,ChannelPos);
		break;
		case DIO_PortB:
		ChannelBit = GetBit(PINB_Reg,ChannelPos);
		break;
		case DIO_PortC:
		ChannelBit = GetBit(PINC_Reg,ChannelPos);
		break;
		case DIO_PortD:
		ChannelBit = GetBit(PIND_Reg,ChannelPos);
		break;
	}
	return ChannelBit;
}

void DIO_Toggle(DIO_ChannelTypes ChannelId){
	DIO_PortTypes Portx = ChannelId/8;
	DIO_ChannelTypes ChannelPos = ChannelId%8;
	switch(Portx){
		case DIO_PortA:
		ToggleBit(PINA_Reg,ChannelPos);
		break;
		case DIO_PortB:
		ToggleBit(PINB_Reg,ChannelPos);
		break;
		case DIO_PortC:
		ToggleBit(PINC_Reg,ChannelPos);
		break;
		case DIO_PortD:
		ToggleBit(PIND_Reg,ChannelPos);
		break;
	}
}