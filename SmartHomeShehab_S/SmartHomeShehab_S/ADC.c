/*
 * ADC.c
 *
 * Created: 09-Dec-20 10:17:42 PM
 *  Author: Jean
 */ 

#include "ADC.h"

void ADC_Init(){
	ADMUX |= (1<<REFS1)|(1<<REFS0);
	ADCSRA |= (1<<ADEN)|(1<<ADPS0)|(1<<ADPS1)|(1<<ADPS2);
}
unsigned short ADC_Read(unsigned char channel){
	unsigned short data = 0;
	ADMUX = (ADMUX & 0b11100000)|(channel & 0b00011111);
	ADCSRA |= (1<<ADSC);
	while(!(ADCSRA & (1<<ADIF)));
	ADCSRA |= (1<<ADIF);
	data = ADCL;
	data |= (ADCH << 8);
	return data;
}