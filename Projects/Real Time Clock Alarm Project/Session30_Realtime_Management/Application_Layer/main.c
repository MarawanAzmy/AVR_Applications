/**
 * @file    main.c
 * @brief   RTC alarm: shows the DS1307 time on the LCD and turns on PD5 when the minute is between 19 and 24.
 * @author  Marawan Azmy
 *
 * The hour format is selected with hr_12_24 in RTC.h (the Proteus model uses 24-hour).
 * The RTC keeps running on its backup battery, so it only needs to be programmed once.
 */

#include "../HAL/RTC.h"
#include "../HAL/LCD.h"
#include <avr/io.h>

int main(){
	char arr[10];

	DDRD |= (1<<PD5);
	PORTD &= ~(1<<PD5);
	RTC S1;

	S1.sec = 15;
	S1.min = 35;
	S1.hour = 7;
	S1.day = 2;	/* Tuesday */
	S1.date = 24;
	S1.month = 5;
	S1.year = 24;
	S1.control = 0;

	RTC_init();
	/* Uncomment once to program the RTC with the values above, then comment it out again. */
	//RTC_set_parameters(&S1);

	LCD_Init();
	LCD_Clear_Display();
	LCD_Send_String_Row_Column(0,0,"Time: ");

	while(1){
		S1 = RTC_get_parameters();

		LCD_Go_To_Row_Column(1,0);

		LCD_Int_To_String(S1.hour, arr);
		LCD_Send_String(arr);

		LCD_Send_String(" : ");

		LCD_Int_To_String(S1.min, arr);
		LCD_Send_String(arr);

		LCD_Send_String(" : ");

		LCD_Int_To_String(S1.sec, arr);
		LCD_Send_String(arr);

		_delay_ms(50);

		if((S1.min > 18) && (S1.min < 25)){
			PORTD |= (1<<PD5);
		}
	}

	return 0;
}
