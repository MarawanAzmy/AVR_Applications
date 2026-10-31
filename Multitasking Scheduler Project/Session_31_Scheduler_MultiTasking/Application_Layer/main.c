/**
 * @file    main.c
 * @brief   Scheduler demo: periodic tasks read the temperature, update the LCD and blink LEDs.
 * @author  Marawan Azmy
 */

#include "../Service_Layer/Scheduler.h"
#include "../HAL/LCD.h"
#include "../MCAL/ADC.h"

volatile float sensor = 0;

void Task_2ms(void)
{
}

void Task_5ms(void)
{
	sensor = ADC_Read(6);
	sensor *= 5;
	sensor /= 1023;	/* Volts */
	sensor *= 100;	/* Degrees C */
}

void Task_10ms(void)
{
	PORTA ^= (1<<PA2);
}

void Task_100ms(void)
{
	PORTA ^= (1<<PA1);
}

void Task_500ms(void)
{
	char arr[10];

	LCD_Send_String_Row_Column(0,0,"Temp is : ");
	LCD_Int_To_String(sensor,arr);
	LCD_Send_String(arr);
	LCD_Send_String(" *C");
}

void Task_1000ms(void)
{
	PORTA ^= (1<<PA0);
}

int main(){
	DDRA |= (1<<PA0)|(1<<PA1)|(1<<PA2);
	ADC_Init();

	LCD_Init();
	LCD_Clear_Display();

	Scheduler_init();

	Scheduler_2ms_Task_Create(Task_2ms);
	Scheduler_5ms_Task_Create(Task_5ms);
	Scheduler_10ms_Task_Create(Task_10ms);
	Scheduler_100ms_Task_Create(Task_100ms);
	Scheduler_500ms_Task_Create(Task_500ms);
	Scheduler_1000ms_Task_Create(Task_1000ms);

	Scheduler_Run();

	while(1){
	}

	return 0;
}
