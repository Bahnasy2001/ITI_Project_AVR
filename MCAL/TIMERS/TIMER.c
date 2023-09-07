/*
 * TIMER.c
 *
 * Created: 9/5/2023 8:43:24 AM
 *  Author: Hassan Bahnasy
 */ 
#include "TIMER.h"

static volatile void(*ptrToT0_OVF)(void)=((void*)0);
static volatile void(*ptrToT0_CTC)(void)=((void*)0);

void Timer0_init(u8 PreScaler,u8 MODE,u8 PreLoadVal,u8 OC0_MODE,u8 CMP_MatchVal)
{
	/**
	 * 1st step : configure the mode
	 * 2nd step : configure FOC0
	 * 3rd step : configure OC0 Pin if CTC
	 * 4th step : Set PreLoad Val if needed
	 * 5th step : set OCR value if CTC
	 * 6th step : Enable INT
	 * 7th step : Enable GIE
	 * 8th step : Set prescaler
	 */
	
	switch(MODE)
	{
		case TIMER_OVF_MODE:
		CLR_BIT(TCCR0,WGM00);
		CLR_BIT(TCCR0,WGM01);
		setTCNT0(PreLoadVal);
		break;
		case TIMER_PHASE_PWM_MODE:
		SET_BIT(TCCR0,WGM00);
		CLR_BIT(TCCR0,WGM01);
		break;
		case TIMER_CTC_MODE:
		CLR_BIT(TCCR0,WGM00);
		SET_BIT(TCCR0,WGM01);
		//SET FOC0
		SET_BIT(TCCR0,FOC0);
		
		//SET OC0 MODE
		TCCR0 = (TCCR0 & 0xCF) |(OC0_MODE & 0x30);
		
		//setTCNT0(PreLoadVal);
		
		setOCR0(CMP_MatchVal);
		break;
		case TIMER_FAST_PWM_MODE:
		SET_BIT(TCCR0,WGM00);
		SET_BIT(TCCR0,WGM01);
		break;
	}
	
	SET_BIT(SREG,7);
	Timer0_OpenPIE(MODE);
	
	
	
	//Set prescaler
	TCCR0 = (TCCR0 & 0xF8) |(PreScaler & 7); 
}

void setTCNT0(u8 preload_value)
{
	TCNT0 = preload_value;
}
void clearTCNT0(void)
{
	TCNT0 &= 0x00;
}

void setOCR0(u8 value)
{
	OCR0 = value;
}

void Timer0_OpenPIE(u8 MODE)
{
	switch(MODE)
	{
		case TIMER_OVF_MODE:
		SET_BIT(TIMSK,TOIE0);
		break;
		case TIMER_CTC_MODE:
		SET_BIT(TIMSK,OCIE0);
		break;
	}
}

void Timer0_ClosePIE(u8 MODE)
{
	switch(MODE)
	{
		case TIMER_OVF_MODE:
		CLR_BIT(TIMSK,TOIE0);
		break;
		case TIMER_CTC_MODE:
		CLR_BIT(TIMSK,OCIE0);
		break;
	}
}

void Timer0_DisT0()
{
	TCCR0 = 0;
}
void Timer0_OVF_setCallBack(void(*ptrToFunc)(void))
{
	if(ptrToFunc != ((void*)0))
	{
		ptrToT0_OVF =ptrToFunc;
	}
}

void Timer0_CTC_setCallBack(void(*ptrToFunc)(void))
{
		if(ptrToFunc != ((void*)0))
		{
			ptrToT0_CTC =ptrToFunc;
		}
}

void __vector_11(void)    __attribute__((signal));
void __vector_11(void)
{
	if(ptrToT0_OVF)
	{
		ptrToT0_OVF();
	}
}
void __vector_10(void)    __attribute__((signal));
void __vector_10(void)
{
	if(ptrToT0_CTC)
	{
		ptrToT0_CTC();
	}
}