/*
 * ADC.h
 *
 * Created: 09-Dec-20 10:17:53 PM
 *  Author: Jean
 */ 


#ifndef ADC_H_
#define ADC_H_

#include <avr/io.h>

void ADC_Init();
unsigned short ADC_Read(unsigned char channel);



#endif /* ADC_H_ */