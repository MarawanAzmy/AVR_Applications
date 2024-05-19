#include"ADC.h"


int main(){

	ADC_Init();

	f32 Sensor = 0;
	DDRC |= (1<<PC5);


	while(1){

		Sensor = ADC_Read(6);// read 0-1023
		Sensor *=5;
		Sensor /=1023;// to Volt
		Sensor *=100;// to Temprature C

		if(Sensor > 30){
			PORTC |= (1<<PC5);
		}
		else{
			PORTC &= ~(1<<PC5);
		}


	}

	return 0;
}


