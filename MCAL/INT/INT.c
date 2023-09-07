/*
 * INT.c
 *
 * Created: 8/28/2023 5:11:01 PM
 *  Author: Hassan Bahnasy
 */ 
#include "INT.h"

static volatile void (*ptrToINT[3])(void)={NULL,NULL,NULL};

void INT_ENGlobINT()
{
	SET_BIT(SREG,pin7);
}
void INT_DisGlobINT()
{
	CLR_BIT(SREG,pin7);
}
void INT_Init(u8 INT,u8 source)
{
	INT_ENGlobINT();
	switch(INT)
	{
		case INT_0:
			//Enable INT0 in GICR
			SET_BIT(GICR,pin6);
			// SET INT0 PIN TO INPUT
			DIO_setDirPin(PORT_D,pin2,INPUT);
			//Activate PULL UP
			DIO_writePin(PORT_D,pin2,HIGH);
			//Select Clock source
		switch(source)
		{
			case LOW_LEVEL:
				CLR_BIT(MCUCR,pin0);
				CLR_BIT(MCUCR,pin1);
				break;
			case IOC:
				SET_BIT(MCUCR,pin0);
				CLR_BIT(MCUCR,pin1);
				break;
			case FALL_EDGE:
				CLR_BIT(MCUCR,pin0);
				SET_BIT(MCUCR,pin1);
				break;
			case RISE_EDGE:
				SET_BIT(MCUCR,pin0);
				SET_BIT(MCUCR,pin1);
				break;
			default:break; //Error Handling
		}
		break;
		case INT_1:
			//Enable INT1 in GICR
			SET_BIT(GICR,pin7);
			// SET INT1 PIN TO INPUT
			DIO_setDirPin(PORT_D,pin3,INPUT);
			//Activate PULL UP
			DIO_writePin(PORT_D,pin3,HIGH);
			//Select Clock source
			switch(source)
			{
				case LOW_LEVEL:
					CLR_BIT(MCUCR,pin2);
					CLR_BIT(MCUCR,pin3);
					break;
				case IOC:
					SET_BIT(MCUCR,pin2);
					CLR_BIT(MCUCR,pin3);
					break;
				case FALL_EDGE:
					CLR_BIT(MCUCR,pin2);
					SET_BIT(MCUCR,pin3);
					break;
				case RISE_EDGE:
					SET_BIT(MCUCR,pin2);
					SET_BIT(MCUCR,pin3);
					break;
				default:break; //Error Handling
			}
			break;
			case INT_2:
				//Enable INT2 in GICR
				SET_BIT(GICR,pin5);
				// SET INT2 PIN TO INPUT
				DIO_setDirPin(PORT_B,pin2,INPUT);
				//Activate PULL UP
				DIO_writePin(PORT_B,pin2,HIGH);
				//Select Clock source
				switch(source)
				{
					case FALL_EDGE:
						CLR_BIT(MCUCSR,pin6);
						break;
					case RISE_EDGE:
						SET_BIT(MCUCSR,pin6);
						break;
					default:break; //Error Handling
				}
				break;
				default:break;//Error Handling
	}
}

void INT_Disable(u8 INT)
{
	switch(INT)
	{
		case INT_0: CLR_BIT(GICR,pin6);break;
		case INT_1: CLR_BIT(GICR,pin7);break;
		case INT_2: CLR_BIT(GICR,pin5);break;
	}
}

void INT_SetCallBack(u8 INT,void (*ptrToFunc)(void))
{
	if(INT <= INT_2  && ptrToFunc != ((void*)0))
	{
		ptrToINT[INT] = ptrToFunc;
	}
	else
	{
		//Error Handling
	}
}

void __vector_1(void)    __attribute__((signal));
void __vector_1(void)
{
	if(ptrToINT[INT_0]!= NULL)
	{
		ptrToINT[INT_0]();
	}
}
void __vector_2(void)    __attribute__((signal));
void __vector_2(void)
{
	if(ptrToINT[INT_1]!= NULL)
	{
		ptrToINT[INT_1]();
	}
		
	
}
void __vector_3(void)    __attribute__((signal));
void __vector_3(void)
{
	if(ptrToINT[INT_2]!= NULL)
	{
		ptrToINT[INT_2]();
	}
}