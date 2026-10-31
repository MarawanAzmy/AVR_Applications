/**
 * @file    I2C.c
 * @brief   I2C (TWI) driver, master and slave, polling.
 * @author  Marawan Azmy
 *
 * TWCR is written with '=' (not '|=') on every operation, so TWINT is cleared
 * and no old START/STOP request stays set. TWEA is kept set so the device
 * acknowledges; it is cleared only when receiving the last byte (No_Ack).
 */

#include <AVR/io.h>

void I2C_init(unsigned char MyAddress){
	TWBR = 32;	/* SCL = 100 kHz at 8 MHz */
	TWCR = (1<<TWEN) | (1<<TWEA);
	TWAR = ((MyAddress<<1)&(0xfe));	/* Own address in bits 7:1, bit 0 = general call enable */
}

void I2C_Send_Start(void){
	TWCR = (1<<TWSTA)|(1<<TWINT)|(1<<TWEN)|(1<<TWEA);

	while(!(TWCR&(1<<TWINT)));
	while (!((TWSR == 0x08)|(TWSR == 0x10)));	/* START / repeated START sent */
}

void I2C_Send_End(void){
	TWCR = (1<<TWSTO)|(1<<TWEN)|(1<<TWINT)|(1<<TWEA);
}

void I2C_Send_Address_Read(unsigned char address){
	TWDR = (address<<1) | 0x01;	/* SLA+R */
	TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWEA);

	while(!(TWCR&(1<<TWINT)));
	while (!((TWSR == 0x40)|(TWSR == 0x48)));	/* SLA+R sent, ACK or NACK received */
}

void I2C_Send_Address_Write(unsigned char address){
	TWDR = (address<<1) & 0xfe;	/* SLA+W */
	TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWEA);

	while(!(TWCR&(1<<TWINT)));
	while (!((TWSR == 0x18)|(TWSR == 0x20)));	/* SLA+W sent, ACK or NACK received */
}

void I2C_Send_Data(unsigned char data){
	TWDR = data;
	TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWEA);

	while(!(TWCR&(1<<TWINT)));
	while (!((TWSR == 0x28)|(TWSR == 0x30)|(TWSR == 0xB8)|(TWSR == 0xC0)));	/* Data sent as master or slave, ACK or NACK received */
}

unsigned char I2C_Recieve_Data_Ack(void){
	while(1){
		while(!((TWCR&(1<<TWINT)))){};

		if ((TWSR == 0x50)||(TWSR == 0x80)){	/* Data received as master or slave, ACK returned */
			TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWEA);
			break;
		}else{
			TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWEA);
		}
	}

	return TWDR;
}

unsigned char I2C_Recieve_Data_No_Ack(void){
	while(1){
		while(!((TWCR&(1<<TWINT)))){};

		if ((TWSR == 0x58)||(TWSR == 0x88)){	/* Data received as master or slave, NACK returned */
			TWCR = (1<<TWINT)|(1<<TWEN);
			break;
		}else{
			TWCR = (1<<TWINT)|(1<<TWEN);
		}
	}

	return TWDR;
}

/* START, SLA+W, one data byte, STOP. */
void I2C_Send_Byte_Generic(unsigned char address, unsigned char data){
	I2C_Send_Start();
	I2C_Send_Address_Write(address);
	I2C_Send_Data(data);
	I2C_Send_End();
}
