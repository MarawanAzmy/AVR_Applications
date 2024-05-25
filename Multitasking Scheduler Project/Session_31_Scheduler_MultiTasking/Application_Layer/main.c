
#include "../Service_Layer/Scheduler.h"
#include "../HAL/LCD.h"
#include "../MCAL/ADC.h"

volatile float sensor = 0;

void Task_2ms(void)
{

}

void Task_5ms(void)
{
	sensor = ADC_Read(6);//to be moved to HAL
	sensor *=5;
	sensor /=1023;// to Volt
	sensor *=100;// to Temprature C
}

void Task_10ms(void)
{

	PORTA ^=(1<<PA2);//to be moved to MCAL

}

void Task_100ms(void)
{
	PORTA ^=(1<<PA1);//to be moved to MCAL

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
	PORTA ^=(1<<PA0);

}

int main(){
	DDRA |= (1<<PA0) |(1<<PA1)|(1<<PA2);
	ADC_Init();//to be moved to MCAL

	LCD_Init();
	LCD_Clear_Display();



	Scheduler_init();

	Scheduler_2ms_Task_Create(Task_2ms);//insert fun name without the bracket, ptr to fun
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

