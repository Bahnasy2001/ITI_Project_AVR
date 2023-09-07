/*
 * TIMER.h
 *
 * Created: 9/5/2023 8:44:12 AM
 *  Author: Hassan Bahnasy
 */ 


#ifndef TIMER_H_
#define TIMER_H_

#include <avr/interrupt.h>
//#include <avr/io.h>
#include "../../utils/STD_TYPES.h"
#include "../../utils/BIT_MATH.h"

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

/************** TIMER0 MODES **************/
#define TIMER_OVF_MODE			0
#define TIMER_PHASE_PWM_MODE    1
#define TIMER_CTC_MODE 			2
#define TIMER_FAST_PWM_MODE     3

/************* TIMER OCx MODES**********/
#define TIMER_OCx_DIS   0x00
#define TIMER_OCx_TOG   0x10
#define TIMER_OCx_CLR   0x20
#define TIMER_OCx_SET   0x30

/************** TIMER PRESCALER **************/
#define TIMER_STOP_TIMER           0
#define TIMER_PRESCALER_1          1
#define TIMER_PRESCALER_8          2
#define TIMER_PRESCALER_64         3
#define TIMER_PRESCALER_256        4
#define TIMER_PRESCALER_1024       5
#define TIMER_PRESCALER_T0         6
#define TIMER_PRESCALER_T1         7

void Timer0_init(u8 PreScaler,u8 MODE,u8 PreLoadVal,u8 OC0_MODE,u8 CMP_MatchVal);

void setTCNT0(u8 preload_value);

void clearTCNT0(void);

void setOCR0(u8 value);

void Timer0_OpenPIE(u8 MODE);

void Timer0_ClosePIE(u8 MODE);

void Timer0_DisT0();

void Timer0_OVF_setCallBack(void(*ptrToFunc)(void));

void Timer0_CTC_setCallBack(void(*ptrToFunc)(void));

#endif /* TIMER_H_ */