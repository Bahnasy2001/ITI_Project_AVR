/*
 * ADC.c
 *
 * Created: 9/4/2023 7:08:17 PM
 *  Author: Hassan Bahnasy
 */ 
#include "ADC.h"
void ADC_init()
{
	/************************************************************************/
	/* steps
	1- set prescaler  
	2- choose vref
	3- choose of auto triggered or not
	4- if auto triggered choose one of the triggering options
	5- set right or left adjust
	6- enable adc
	                                                                   */
	/************************************************************************/
	/************************************************************************/
	/* SET PRESCALAR                                                   */
	/************************************************************************/
	#if ADC_PRESCALER == ADC_PRESCALER_DIV2
	SET_BIT(ADCSRA,0);
	CLR_BIT(ADCSRA,1);
	CLR_BIT(ADCSRA,2);
	
	#elif ADC_PRESCALER == ADC_PRESCALER_DIV4
	CLR_BIT(ADCSRA,0);
	SET_BIT(ADCSRA,1);
	CLR_BIT(ADCSRA,2);
	
	#elif ADC_PRESCALER == ADC_PRESCALER_DIV8
	SET_BIT(ADCSRA,ADPS0);
	SET_BIT(ADCSRA,ADPS1);
	CLR_BIT(ADCSRA,ADPS2);

	#elif ADC_PRESCALER == ADC_PRESCALER_DIV16
	CLR_BIT(ADCSRA,ADPS0);
	CLR_BIT(ADCSRA,ADPS1);
	SET_BIT(ADCSRA,ADPS2);

	#elif ADC_PRESCALER == ADC_PRESCALER_DIV32
	SET_BIT(ADCSRA,ADPS0);
	CLR_BIT(ADCSRA,ADPS1);
	SET_BIT(ADCSRA,ADPS2);

	#elif ADC_PRESCALER == ADC_PRESCALER_DIV64
	CLR_BIT(ADCSRA,ADPS0);
	SET_BIT(ADCSRA,ADPS1);
	SET_BIT(ADCSRA,ADPS2);

	#elif ADC_PRESCALER == ADC_PRESCALER_DIV128
	SET_BIT(ADCSRA,ADPS0);
	SET_BIT(ADCSRA,ADPS1);
	SET_BIT(ADCSRA,ADPS2);
	#endif
	/************************************************************************/
	/* CHOOSE VREF                                                          */
	/************************************************************************/
	    // Set ADC reference voltage
	#if ADC_REFERENCE == ADC_REF_AREF
	CLR_BIT(ADMUX,REFS0);
	CLR_BIT(ADMUX,REFS1);
	#elif ADC_REFERENCE == ADC_REF_AVCC
	SET_BIT(ADMUX,0);
	CLR_BIT(ADMUX,1);
	#elif ADC_REFERENCE == ADC_REF_INTERNAL
	SET_BIT(ADMUX,REFS0);
	SET_BIT(ADMUX,REFS1);
	#endif
	//Choose Manual trigger
	CLR_BIT(ADCSRA,ADATE);
	//Set right Adjust
	CLR_BIT(ADMUX,ADLAR);
	// Enable ADC
	SET_BIT(ADCSRA,ADEN);
}

u16 ADC_Read(u8 channel)
{
	/**
	 * choose channel
	 * start conversion
	 * busy wait until flag is down
	 * return the value of analog signal
	 */
	
	/* Configure the channel */
	ADMUX = (ADMUX & 0xF8) | (channel & 0x07);
	
	/* Start Conversion */
	SET_BIT(ADCSRA,6);
	
	// Wait for conversion to complete
	while (READ_BIT(ADCSRA,6));
	
	return ADC;
}