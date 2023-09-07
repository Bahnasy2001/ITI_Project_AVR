/*
 * LCD.h
 *
 * Created: 8/25/2023 11:01:44 AM
 *  Author: Hassan Bahnasy
 */ 

#include <avr/io.h>
#include <util/delay.h>
#include "../../MCAL/DIO/DIO.h"
#ifndef LCD_H_
#define LCD_H_

#define LCD_DATA_PORT PORT_D
#define LCD_CTRL_PORT PORT_C
#define LCD_CTRL_RS   pin5
#define LCD_CTRL_RW   pin6
#define LCD_CTRL_EN   pin7
/************************************************************************/
/* Commands                                                              */
/************************************************************************/
#define FUNC_SET            0x38 //8-bit 2-lines operation mode
#define CLR_DIS             0x01
#define ENTRY_MODE          0x06
#define DIS_OFF_CURS_OFF    0x08
#define DIS_ON_CURS_OFF     0x0C
#define DIS_ON_CURS_ON      0x0E
#define DIS_ON_CURS_BLINK   0x0F

#define ROW_1               0x80        //Address of the first row
#define ROW_2               0xC0        //Address of the Second row

void LCD_init(void);//initiation of ports direction and initiation of LCD
void LCD_SendCmd(u8 command);//sends a command to the LCD
void LCD_SendData(u8 data);//sends a data (char) to the LCD to be displayed
void LCD_setCursor(u8 row,u8 col);//moves cursor to any position 
void LCD_clr(void);
void LCD_writeStr(u8 *str);//displays entire string on the LCD
void LCD_clrScnd(void);//clears the second line of the LCD only and set cursor to the beginning of the second line
void LCD_DisplayInt(u32 number);

#endif /* LCD_H_ */