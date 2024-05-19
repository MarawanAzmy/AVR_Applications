/*
 * LCD.c
 *
 *  Created on: 2 May 2024
 *      Author: marmar
 */
#include "LCD.h"
#include <util/delay.h>
void LCD_Init(){
	LCD_RS_DDR	|= (1<<LCD_RS_PIN_Num);
	LCD_E_DDR	|= (1<<LCD_E_PIN_Num);

	LCD_DATA_DDR = 0xff;

	LCD_Send_Command(Return_Home);
	LCD_Send_Command(_8bit_2line);//momkn t2ollo 4 bit hna

	LCD_Send_Command(Clear_Display);
	LCD_Send_Command(Display_ON_Curser_ON);
}

void LCD_Send_Command(unsigned char Command){//sequence in datasheet
	//R/W kda kda gnded

	LCD_RS_PORT &= ~(1<<LCD_RS_PIN_Num);	//RS low 3shan command mode

	_delay_ms(1);
	LCD_E_PORT 	|= (1<<LCD_E_PIN_Num); 		//	Enable pin high
	_delay_ms(1);							// kolo bl nano sec, 1ms is good
	LCD_DATA_PORT =Command 	;				// ekteb 3l data
			_delay_ms(1);							//momkn tshel da
	LCD_E_PORT 	&= ~(1<<LCD_E_PIN_Num);//Enable low
	_delay_ms(1);
}

void LCD_Send_Character(char character){//sequence in datasheet
	//R/W kda kda gnded

	LCD_RS_PORT |= (1<<LCD_RS_PIN_Num);	//RS high 3shan data mode

	_delay_ms(1);
	LCD_E_PORT 	|= (1<<LCD_E_PIN_Num); 		//	Enable pin high
	_delay_ms(1);							// kolo bl nano sec, 1ms is good
	LCD_DATA_PORT =character ;					// ekteb 3l data
			_delay_ms(1);							//momkn tshel da
	LCD_E_PORT 	&= ~(1<<LCD_E_PIN_Num);//Enable low
	_delay_ms(1);
}

void LCD_Send_String(char*string ){//sequence in datasheet
	short i = 0;

	while (string[i] != '\0'){
		LCD_Send_Character(string[i]);
		i++;
	}


}

void LCD_Clear_Display(){
	LCD_Send_Command(Clear_Display);

}



void LCD_Go_To_Row_Column(char row , char column){

	unsigned char address = 0;
	switch(row){
	case 0:address = (column ); break;
	case 1:address = (column +0x40); break;
	}
	LCD_Send_Command(address|(Set_Curser_Location));
	//Set_Curser_Location hya el 1 set fl 8th bit, say3a


}

void LCD_Send_String_Row_Column(char row , char column, char*String){
	LCD_Go_To_Row_Column(row,column);
	LCD_Send_String(String);



}

void LCD_Int_To_String(int integer, char *String){

	itoa(integer,String,10 );

}


void LCD_Set_Custom_Char(unsigned char location, unsigned char* pattern ){
	unsigned char arrayIndex = 0;
		if (location < 8)// 3deet el 8 custom places cells el msmo7alak, kol cell 7rf kaml msh dot a2sod
		{

			LCD_Send_Command(0x40 + (location*8)); // add to 6th bit, t2rebn feh fr2 ben di wli fo2 msh mot2kd
			for (arrayIndex = 0 ; arrayIndex<8 ; arrayIndex++){

				LCD_Send_Character(pattern[arrayIndex]);
			}


		}else{

			//return error todo
		}




}
