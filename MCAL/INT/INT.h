/*
 * INT.h
 *
 * Created: 8/28/2023 5:11:16 PM
 *  Author: Hassan Bahnasy
 */ 


#ifndef INT_H_
#define INT_H_
#include <avr/interrupt.h>
#include "../DIO/DIO.h"

#define LOW_LEVEL  0
#define IOC        1
#define FALL_EDGE  2
#define RISE_EDGE  3

#define INT_0       0
#define INT_1       1
#define INT_2       2

#define NULL ((void *)0)
//FOR ALL INTs
void INT_ENGlobINT();

void INT_DisGlobINT();

void INT_Init(u8 INT,u8 source);

void INT_Disable(u8 INT);

void INT_SetCallBack(u8 INT,void (*ptrToFunc)(void));
#endif /* INT_H_ */