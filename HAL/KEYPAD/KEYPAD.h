/*
 * KEYPAD.h
 *
 * Created: 8/25/2023 11:02:45 AM
 *  Author: Hassan Bahnasy
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_

#include "../../MCAL/DIO/DIO.h"
#include <util/delay.h>

#define ROW_PORT PORT_A
#define COL_PORT PORT_A

#define ROW0 pin4
#define ROW1 pin5
#define ROW2 pin6
#define ROW3 pin7

#define COL0 pin0
#define COL1 pin1
#define COL2 pin2
#define COL3 pin3

void KeyPad_Init();//initiation of port direction
u8 getChar();//return the character that the user pushed



#endif /* KEYPAD_H_ */