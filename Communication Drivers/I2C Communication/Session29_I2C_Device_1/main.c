#include <AVR/io.h>
#include <util/delay.h>
#include "I2C.h"

#define BIT_RATE 32 //either 100(32 reg val) or 400(2 reg val)


int main(void){
	DDRA = (1<<PA6);

	I2C_init(0x01);


	while(1){
		I2C_Send_Start();
		PORTA |= (1<<PA6);
		I2C_Send_Address_Write(0x02);
		I2C_Send_Data((unsigned char)91);
		I2C_Send_End();
		_delay_ms(1000);
		PORTA &= ~(1<<PA6);

		I2C_Send_Start();
		I2C_Send_Address_Write(0x02);
		I2C_Send_Data((unsigned char)17);
		I2C_Send_End();
		_delay_ms(1000);
	}


	return 0;
}
