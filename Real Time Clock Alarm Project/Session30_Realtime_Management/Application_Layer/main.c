/*
 * main.c
 *
 *  Created on: 24 May 2024
 *      Author: marmar
 */
#include "../HAL/RTC.h"
#include "../HAL/LCD.h"
#include <avr/io.h>
int main(){
char arr[10];


//in the RTC h file, select 24 or 12 in hr_12_24 macro
//note that proteus in 24 h, set hr_12_24  to 24 to read it correctly
	DDRD |=(1<<PD5);
	PORTD&= ~(1<<PD5);
	RTC S1;//fill it, set data, then use it to read data

	S1.sec = 15;
	S1.min = 35;
	S1.hour= 7;
	S1.day = 2;//tuesday
	S1.date = 24;
	S1.month = 5;
	S1.year = 24;
	S1.control = 0;

	RTC_init();//init I2C
	//RTC_set_parameters(&S1);//set once and then comment this line



	LCD_Init();
	LCD_Clear_Display();
	LCD_Send_String_Row_Column(0,0,"Time: ");


//you just set once and then comment set line
//this module automatically increment clock, and never go out of power bec connected to external battery
//just get from module and display in loop


	while(1){


		S1 = RTC_get_parameters();


		LCD_Go_To_Row_Column(1,0);

		LCD_Int_To_String(S1.hour, arr); //convert to chars to write on LCD, takes chars
		LCD_Send_String(arr);


		LCD_Send_String(" : ");

		LCD_Int_To_String(S1.min, arr); //convert to chars to write on LCD, takes chars
		LCD_Send_String(arr);


		LCD_Send_String(" : ");

		LCD_Int_To_String(S1.sec , arr); //convert to chars to write on LCD, takes chars
		LCD_Send_String(arr);

		_delay_ms(50);



	}


	return 0;
}

