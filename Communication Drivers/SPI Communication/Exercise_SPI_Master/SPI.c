/**
 * @file    SPI.c
 * @brief   SPI driver, master mode, polling.
 * @author  Marawan Azmy
 */

#include <AVR/io.h>

/* SPI2X, SPR1 and SPR0 stay 0: SCK = F_CPU / 4 = 2 MHz. */
void SPI_init(void){
	SPCR = (1<<SPE) | (1<<MSTR);
}

/* A transfer starts as soon as SPDR is written. */
void SPI_Send_Byte(unsigned char byte, char slave_pin_no){
	SPDR = byte;
	while (!(SPSR & (1<<SPIF)));
}

unsigned char SPI_Send_Recieve_Byte(unsigned char byte, char slave_pin_no){
	SPDR = byte;
	while (!(SPSR & (1<<SPIF)));
	return SPDR;
}

void SPI_Send_String(char *string_to_send, char slave_pin_no){
	unsigned short i = 0;

	while(string_to_send[i] != '\0'){	/* The terminating '\0' is not sent */
		SPI_Send_Recieve_Byte(string_to_send[i],slave_pin_no);
		i++;
	}
}

unsigned char SPI_Recieve_Byte(void){
	while (!(SPSR & (1<<SPIF)));
	return SPDR;
}

void SPI_Recieve_String(char *string_to_recieve_in){
	unsigned short i = 0;

	do{
		string_to_recieve_in[i] = SPI_Recieve_Byte();
	}while(string_to_recieve_in[i++] != '\0');
}
