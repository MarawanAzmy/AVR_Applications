/**
 * @file    LCD.h
 * @brief   HD44780 character LCD driver: pin mapping, commands and API.
 * @author  Marawan Azmy
 */

#ifndef LCD_H_
#define LCD_H_

#include <avr/io.h>

void LCD_Init(void);
void LCD_Clear_Display(void);
void LCD_Send_Command(unsigned char Command);
void LCD_Send_Character(char character);
void LCD_Send_String(char *string);
void LCD_Go_To_Row_Column(char row, char column);
void LCD_Send_String_Row_Column(char row, char column, char *String);
void LCD_Int_To_String(int integer, char *String);
void LCD_Set_Custom_Char(unsigned char location, unsigned char *pattern);

/* Pin mapping */
#define LCD_RS_PIN_Num 6
#define LCD_E_PIN_Num 7

#define LCD_RS_DDR DDRC
#define LCD_E_DDR DDRC
#define LCD_DATA_DDR DDRB

#define LCD_RS_PORT PORTC
#define LCD_E_PORT PORTC
#define LCD_DATA_PORT PORTB

/* Commands */
#define Clear_Display 0x01
#define Return_Home 0x02
#define Display_ON_Curser_ON 0x0E
#define Display_ON_Curser_OFF 0x0C
#define Set_Curser_Location 0x80	/* Set DDRAM address */
#define _8bit_2line 0x38
#define _4bit_2line 0x28

#endif /* LCD_H_ */
