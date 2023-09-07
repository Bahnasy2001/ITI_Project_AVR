/*
 * DIO.h
 *
 * Created: 8/25/2023 10:57:37 AM
 *  Author: Hassan Bahnasy
 */ 


#ifndef DIO_H_
#define DIO_H_

#include "avr/io.h"
#include "../../utils/BIT_MATH.h"
#include "../../utils/STD_TYPES.h"
/************************************************************************/
/*                              PORTS                                   */
/************************************************************************/
#define PORT_A 'A'
#define PORT_B 'B'
#define PORT_C 'C'
#define PORT_D 'D'

#define pin0 0
#define pin1 1
#define pin2 2
#define pin3 3
#define pin4 4
#define pin5 5
#define pin6 6
#define pin7 7
/************************************************************************/
/*                    Direction defines                                 */
/************************************************************************/

#define INPUT 0
#define OUTPUT 1

/************************************************************************/
/*                   value defines                                      */
/************************************************************************/

#define LOW 0
#define HIGH 1

/************************************************************************/
/*                   functions prototypes                               */
/************************************************************************/

//SET Direction for pin
void DIO_setDirPin(u8 portNumber,u8 pinNumber, u8 direction); 

//Write High or Low in pin(OUTPUT) or Enable pull up  or Disable(INPUT)
void DIO_writePin(u8 portNumber,u8 pinNumber, u8 value); 

//Toggle value in pin
void DIO_togglePin(u8 portNumber,u8 pinNumber);

//Read value from  input pin
u8 DIO_readPin(u8 portNumber,u8 pinNumber);

//SET GROUP DIRECTION
void DIO_setDirGroup(u8 portNumber, u8 direction);

void DIO_writeGroup(u8 portNumber, u8 value);
#endif /* DIO_H_ */