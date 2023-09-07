/*
 * LCD.c
 *
 * Created: 8/25/2023 11:02:00 AM
 *  Author: Hassan Bahnasy
 */ 
#include "LCD.h"
void LCD_init(void)
{
	//Set Data pins direction to be output pins
	DIO_setDirGroup(LCD_DATA_PORT,0xFF);
	//Set CTRL pins direction to be output pins
	DIO_setDirPin(LCD_CTRL_PORT,LCD_CTRL_RS,HIGH);
	DIO_setDirPin(LCD_CTRL_PORT,LCD_CTRL_RW,HIGH);
	DIO_setDirPin(LCD_CTRL_PORT,LCD_CTRL_EN,HIGH);
	
	//wait 30ms 
	_delay_ms(35);
	//Functions Set Command
	LCD_SendCmd(FUNC_SET);
	_delay_ms(2);
	//Display ON/OFF Control Command
	LCD_SendCmd(DIS_ON_CURS_BLINK);
	_delay_ms(2);
	//Display Clear Command
	LCD_SendCmd(CLR_DIS);
	_delay_ms(2);
	LCD_SendCmd(ENTRY_MODE);
	_delay_ms(5);
}
void LCD_SendCmd(u8 command)
{
	//Write command to Data_Port
	DIO_writeGroup(LCD_DATA_PORT,command);
	//SET Command Mode
	DIO_writePin(LCD_CTRL_PORT,LCD_CTRL_RS,LOW); //RS = 0
	//Choose Write Mode
	DIO_writePin(LCD_CTRL_PORT,LCD_CTRL_RW,LOW); // RW = 0
	
	//make falling edge for EN
	DIO_writePin(LCD_CTRL_PORT,LCD_CTRL_EN,HIGH); // EN = High
	_delay_ms(2);
	DIO_writePin(LCD_CTRL_PORT,LCD_CTRL_EN,LOW);
	_delay_ms(2);
}

void LCD_SendData(u8 data)
{
	//Write data to Data_Port
	DIO_writeGroup(LCD_DATA_PORT,data);
	//SET Data Mode
	DIO_writePin(LCD_CTRL_PORT,LCD_CTRL_RS,HIGH); //RS = 1
	//Choose Write Mode
	DIO_writePin(LCD_CTRL_PORT,LCD_CTRL_RW,LOW); // RW = 0
		
	//make falling edge for EN
	DIO_writePin(LCD_CTRL_PORT,LCD_CTRL_EN,HIGH); // EN = High
	_delay_ms(2);
	DIO_writePin(LCD_CTRL_PORT,LCD_CTRL_EN,LOW);
	_delay_ms(2);
}

void LCD_setCursor(u8 row,u8 col)
{
	if(col >=0 && col <=15)
	{
		switch(row)
		{
			case ROW_1:LCD_SendCmd(ROW_1+col);break;
			case ROW_2:LCD_SendCmd(ROW_2+col);break;
			default:break;
		}
	}
}

void LCD_clr(void)
{
	LCD_SendCmd(CLR_DIS);
}
void LCD_writeStr(u8 *str)
{
	while(*str != '\0')
	{
		LCD_SendData(*str);
		str++;
	}
}
void LCD_clrScnd(void)
{
	LCD_setCursor(ROW_2,0);
	LCD_writeStr("               ");
}
void LCD_DisplayInt(u32 number){

	u8 arr_new[11];		//The max value of u32 has ten digits
	u8 arr1[11], i = 0, j;
	if(number == 0)
	{
		LCD_writeStr("0");
		return;
	}

	while(number != 0)
	{
		arr1[i] = (number % 10) + 0x30;
		number /= 10;
		i++;
	}

	i--;
	j = 0;
	while(i < 11) //After it reaches zero
	{
		arr_new[j] = arr1[i];
		j++;
		i--;
	}

	arr_new[j] = '\0';

	LCD_writeStr(arr_new);
	
}