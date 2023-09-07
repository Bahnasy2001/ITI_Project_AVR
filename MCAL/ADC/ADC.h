/*
 * ADC.h
 *
 * Created: 9/4/2023 7:08:04 PM
 *  Author: Hassan Bahnasy
 */ 


#ifndef ADC_H_
#define ADC_H_

#include "../DIO/DIO.h"
#include <avr/io.h>
// ADC prescaler options
#define ADC_PRESCALER_DIV2   0
#define ADC_PRESCALER_DIV4   2
#define ADC_PRESCALER_DIV8   3
#define ADC_PRESCALER_DIV16  4
#define ADC_PRESCALER_DIV32  5
#define ADC_PRESCALER_DIV64  6
//COMMON USE
#define ADC_PRESCALER_DIV128 7

// ADC reference options
#define ADC_REF_AREF         0
//COMMON USE
#define ADC_REF_AVCC         1
#define ADC_REF_INTERNAL     3

// Set your desired configuration options here
#define ADC_PRESCALER        ADC_PRESCALER_DIV128
#define ADC_REFERENCE        ADC_REF_AVCC
void ADC_init();
u16 ADC_Read(u8 channel);


#endif /* ADC_H_ */