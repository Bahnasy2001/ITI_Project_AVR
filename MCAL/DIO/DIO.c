/*
 * DIO.c
 *
 * Created: 8/25/2023 10:58:30 AM
 *  Author: Hassan Bahnasy
 */ 

#include "DIO.h"

void DIO_setDirPin(u8 portNumber,u8 pinNumber, u8 direction)
{
	switch(portNumber)
	{
		case PORT_A:
			if(direction == INPUT)
			{
				CLR_BIT(DDRA,pinNumber);//INPUT direction
			}
			else if(direction == OUTPUT)
			{
				SET_BIT(DDRA,pinNumber); //OUTPUT direction
			}
			else
			{
				//Error Handling
			}
		break;
		case PORT_B:
			if(direction == INPUT)
			{
				CLR_BIT(DDRB,pinNumber);
			}
			else if(direction == OUTPUT)
			{
				SET_BIT(DDRB,pinNumber);
			}
			else
			{
				//Error Handling
			}
		break;
		case PORT_C:
			if(direction == INPUT)
			{
				CLR_BIT(DDRC,pinNumber);
			}
			else if(direction == OUTPUT)
			{
				SET_BIT(DDRC,pinNumber);
			}
			else
			{
				//Error Handling
			}
		break;
		case PORT_D:
			if(direction == INPUT)
			{
				CLR_BIT(DDRD,pinNumber);
			}
			else if(direction == OUTPUT)
			{
				SET_BIT(DDRD,pinNumber);
			}
			else
			{
				//Error Handling
			}
		break;
	}
}

void DIO_writePin(u8 portNumber,u8 pinNumber, u8 value)
{
	switch(portNumber)
	{
		case PORT_A:
			if(value == LOW) //write 0 if pin is output or disable pull up if pin is input
			{
				CLR_BIT(PORTA,pinNumber);
			}
			else if(value == HIGH) // write 1 if pin is output or enable pull up if pin is input
			{
				SET_BIT(PORTA,pinNumber);
			}
			else
			{
				//Error Handling
			}
		break;
		case PORT_B:
			if(value == LOW) //write 0 if pin is output or disable pull up if pin is input
			{
				CLR_BIT(PORTB,pinNumber);
			}
			else if(value == HIGH) // write 1 if pin is output or enable pull up if pin is input
			{
				SET_BIT(PORTB,pinNumber);
			}
			else
			{
				//Error Handling
			}
		break;
		case PORT_C:
			if(value == LOW) //write 0 if pin is output or disable pull up if pin is input
			{
				CLR_BIT(PORTC,pinNumber);
			}
			else if(value == HIGH) // write 1 if pin is output or enable pull up if pin is input
			{
				SET_BIT(PORTC,pinNumber);
			}
			else
			{
				//Error Handling
			}
		break;
		case PORT_D:
			if(value == LOW) //write 0 if pin is output or disable pull up if pin is input
			{
				CLR_BIT(PORTD,pinNumber);
			}
			else if(value == HIGH) // write 1 if pin is output or enable pull up if pin is input
			{
				SET_BIT(PORTD,pinNumber);
			}
			else
			{
				//Error Handling
			}
		break;
	}
}

void DIO_togglePin(u8 portNumber,u8 pinNumber)
{
	switch(portNumber)
	{
		case PORT_A: TOG_BIT(PORTA,pinNumber);break;
		case PORT_B: TOG_BIT(PORTB,pinNumber);break;
		case PORT_C: TOG_BIT(PORTC,pinNumber);break;
		case PORT_D: TOG_BIT(PORTD,pinNumber);break;
	}
}

u8 DIO_readPin(u8 portNumber,u8 pinNumber)
{
	u8 value;
	switch(portNumber)
	{
		case PORT_A:
		value = READ_BIT(PINA,pinNumber);
		break;
		case PORT_B:
		value = READ_BIT(PINB,pinNumber);
		break;
		case PORT_C:
		value = READ_BIT(PINC,pinNumber);
		break;
		case PORT_D:
		value = READ_BIT(PIND,pinNumber);
		break;
	}
	return value;
}

void DIO_setDirGroup(u8 portNumber, u8 direction)
{
	switch(portNumber)
	{
		case PORT_A:
			if(direction == INPUT)
			{
				REG_CLR(DDRA);
			}
			else if(direction == OUTPUT)
			{
				REG_SET(DDRA);
			}
			else
			{
				//Error Handling
			}
		break;
		case PORT_B:
			if(direction == INPUT)
			{
				REG_CLR(DDRB);
			}
			else if(direction == OUTPUT)
			{
				REG_SET(DDRB);
			}
			else
			{
				//Error Handling
			}
		break;
		case PORT_C:
			if(direction == INPUT)
			{
				REG_CLR(DDRC);
			}
			else if(direction == OUTPUT)
			{
				REG_SET(DDRC);
			}
			else
			{
				//Error Handling
			}
		break;
		case PORT_D:
			if(direction == INPUT)
			{
				REG_CLR(DDRD);
			}
			else if(direction == OUTPUT)
			{
				REG_SET(DDRD);
			}
			else
			{
				//Error Handling
			}
		break;
	}
}

void DIO_writeGroup(u8 portNumber, u8 value)
{
	switch(portNumber)
	{
		case PORT_A:REG_WRT(PORTA,value);break;
		case PORT_B:REG_WRT(PORTB,value);break;
		case PORT_C:REG_WRT(PORTC,value);break;
		case PORT_D:REG_WRT(PORTD,value);break;
	}
}