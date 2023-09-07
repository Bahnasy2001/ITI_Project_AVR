/*
 * calculator.c
 *
 * Created: 9/6/2023 5:16:00 PM
 *  Author: Hassan Bahnasy
 */ 
#define F_CPU 8000000UL
#include "../MCAL/DIO/DIO.h"
#include "../HAL/LCD/LCD.h"
#include "../HAL/KEYPAD/KEYPAD.h"
#define NULL ((void*)0)
void main()
{
	u8 calc[5] = {0,0,0,0,0};
	u8 op1=0;
	u8 op2=0;
	u8 result = 0;
	u8 operation;
	LCD_init();
	KeyPad_Init();
	u8 i =0;
	while(1)
	{
	
	s8 chr1=getChar();
	switch(chr1){
		case -1:
		break;
		case 'c':
		LCD_SendCmd(CLR_DIS);
		op1=0;
		op2=0;
		result = 0;
		operation = NULL;
		i = 0;
		break;
		default :
		
		calc[i] = chr1;
		LCD_SendData(calc[i]);
		i++;
		op1 = calc[0]-0x30;
		op2 = calc[2]-0x30;
		operation = calc[1];
		if(i>=4)
		{
			calc[4]  = '\0';
			if(calc[3] == '=')
			{
				switch(operation)
				{
					case '+':result = op1 + op2;
							 LCD_DisplayInt(result);
							 break;
					case '-':result = op1 - op2; 
							LCD_DisplayInt(result);
							break;
					case '*':result = op1 * op2;
							LCD_DisplayInt(result);
							break;
					case '/':result = op1 / op2;
						if(op2 == 0)
						{
							LCD_writeStr("Error Math");
							break;
						}
						LCD_DisplayInt(result);
						break;
				}
			}
		}
	}
	}
}