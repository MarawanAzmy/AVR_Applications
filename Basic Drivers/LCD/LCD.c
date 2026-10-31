/**
 * @file    LCD.c
 * @brief   HD44780 character LCD driver (8-bit mode).
 * @author  Marawan Azmy
 */

#include "LCD.h"
#include <util/delay.h>

void LCD_Init(){
	LCD_RS_DDR |= (1<<LCD_RS_PIN_Num);
	LCD_E_DDR |= (1<<LCD_E_PIN_Num);
	LCD_DATA_DDR = 0xff;

	LCD_Send_Command(Return_Home);
	LCD_Send_Command(_8bit_2line);
	LCD_Send_Command(Clear_Display);
	LCD_Send_Command(Display_ON_Curser_ON);
}

/* R/W is tied to GND, so the LCD is only written to. */
void LCD_Send_Command(unsigned char Command){
	LCD_RS_PORT &= ~(1<<LCD_RS_PIN_Num);	/* RS low: command register */
	_delay_ms(1);
	LCD_E_PORT |= (1<<LCD_E_PIN_Num);
	_delay_ms(1);
	LCD_DATA_PORT = Command;
	_delay_ms(1);
	LCD_E_PORT &= ~(1<<LCD_E_PIN_Num);
	_delay_ms(1);
}

void LCD_Send_Character(char character){
	LCD_RS_PORT |= (1<<LCD_RS_PIN_Num);	/* RS high: data register */
	_delay_ms(1);
	LCD_E_PORT |= (1<<LCD_E_PIN_Num);
	_delay_ms(1);
	LCD_DATA_PORT = character;
	_delay_ms(1);
	LCD_E_PORT &= ~(1<<LCD_E_PIN_Num);
	_delay_ms(1);
}

void LCD_Send_String(char *string){
	short i = 0;

	while (string[i] != '\0'){
		LCD_Send_Character(string[i]);
		i++;
	}
}

void LCD_Clear_Display(){
	LCD_Send_Command(Clear_Display);
}

void LCD_Go_To_Row_Column(char row, char column){
	unsigned char address = 0;

	switch(row){
	case 0: address = (column); break;
	case 1: address = (column + 0x40); break;
	}
	LCD_Send_Command(address | (Set_Curser_Location));
}

void LCD_Send_String_Row_Column(char row, char column, char *String){
	LCD_Go_To_Row_Column(row, column);
	LCD_Send_String(String);
}

void LCD_Int_To_String(int integer, char *String){
	itoa(integer, String, 10);
}

/* Stores an 8-byte pattern in one of the 8 CGRAM character slots. */
void LCD_Set_Custom_Char(unsigned char location, unsigned char *pattern){
	unsigned char arrayIndex = 0;

	if (location < 8)
	{
		LCD_Send_Command(0x40 + (location*8));	/* Set CGRAM address */
		for (arrayIndex = 0; arrayIndex < 8; arrayIndex++){
			LCD_Send_Character(pattern[arrayIndex]);
		}
	}else{
		/* Invalid slot: ignored */
	}
}
