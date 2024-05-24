/*
 * LCD.h
 *
 *  Created on: 2 May 2024
 *      Author: marmar
 */

#ifndef LCD_H_
#define LCD_H_
#include <avr/io.h>

void LCD_Init(void);//done
void LCD_Clear_Display(void);//done
void LCD_Send_Command(unsigned char Command);//done
void LCD_Send_Character(char character);//done
void LCD_Send_String(char*string );//done
void LCD_Go_To_Row_Column(char row , char column);//done
void LCD_Send_String_Row_Column(char row , char column, char*String);//done
void LCD_Int_To_String(int integer, char *String);//Done
void LCD_Set_Custom_Char(unsigned char location, unsigned char* pattern );//Done

#define LCD_RS_PIN_Num 6
#define LCD_E_PIN_Num 7

#define LCD_RS_DDR DDRC
#define LCD_E_DDR DDRC
#define LCD_DATA_DDR DDRB

#define LCD_RS_PORT PORTC
#define LCD_E_PORT PORTC
#define LCD_DATA_PORT PORTB



#define Clear_Display 0x01
#define Return_Home  0x02
#define Display_ON_Curser_ON 0x0E
#define Display_ON_Curser_OFF 0x0C
#define Set_Curser_Location 0x80 //gabha ezay de mnen????
#define _8bit_2line 0x38
#define _4bit_2line 0x28




#endif /* LCD_H_ */
