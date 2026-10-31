/**
 * @file    main.c
 * @brief   LCD demo: prints a string and a running counter.
 * @author  Marawan Azmy
 */

#include "LCD.h"
#include <util/delay.h>

char pattern[8] = {0b0001010, 0x1f, 0x1f, 0x1f, 0x1f, 0x0e, 0x04, 0x00};
char arr[10];

int main(){
	volatile char x = 0;

	LCD_Init();
	LCD_Clear_Display();
	LCD_Send_String_Row_Column(0,0,"OOOSAMAAAA");

	while(1){
		x++;
		LCD_Go_To_Row_Column(1,0);
		LCD_Int_To_String(x,arr);
		LCD_Send_String(arr);
		_delay_ms(1000);
	}
	return 0;
}
