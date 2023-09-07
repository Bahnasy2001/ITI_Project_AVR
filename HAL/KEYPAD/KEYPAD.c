/*
 * KEYPAD.c
 *
 * Created: 8/25/2023 11:02:35 AM
 *  Author: Hassan Bahnasy
 */ 
#include "KEYPAD.h"
u8 KeyMap[4][4]=
{
        {'7','8','9','/'},
        {'4','5','6','*'},
		{'1','2','3','-'},
        {'c','0','=','+'}
};
void KeyPad_Init()
{
	//SET COL to be OUTPUT
	DIO_setDirPin(COL_PORT,COL0,OUTPUT);
	DIO_setDirPin(COL_PORT,COL1,OUTPUT);
	DIO_setDirPin(COL_PORT,COL2,OUTPUT);
	DIO_setDirPin(COL_PORT,COL3,OUTPUT);
	
	//SET ROW to be INPUT
	DIO_setDirPin(ROW_PORT,ROW0,INPUT);
	DIO_setDirPin(ROW_PORT,ROW1,INPUT);
	DIO_setDirPin(ROW_PORT,ROW2,INPUT);
	DIO_setDirPin(ROW_PORT,ROW3,INPUT);
	
	//SET COL to be HIGH
	DIO_writePin(COL_PORT,COL0,HIGH);
	DIO_writePin(COL_PORT,COL1,HIGH);
	DIO_writePin(COL_PORT,COL2,HIGH);
	DIO_writePin(COL_PORT,COL3,HIGH);
	
	//SET ROWS PULL UP
	DIO_writePin(ROW_PORT,ROW0,HIGH);
	DIO_writePin(ROW_PORT,ROW1,HIGH);
	DIO_writePin(ROW_PORT,ROW2,HIGH);
	DIO_writePin(ROW_PORT,ROW3,HIGH);
}
u8 getChar()
{
	for (u8 col = COL0;col<=COL3;col++)
	{
		DIO_writePin(COL_PORT,col,LOW);
		for (u8 row = ROW0;row <=ROW3;row++)
		{
			if(DIO_readPin(ROW_PORT,row) == 0)
			{
				while(DIO_readPin(ROW_PORT,row) == 0);
				_delay_ms(20);
				
				DIO_writePin(COL_PORT,col,HIGH);
				return KeyMap[row-ROW0][col-COL0];
			}
		}
		DIO_writePin(COL_PORT,col,HIGH);
	}
	return -1;
}
