
#include <AVR/io.h>


void SPI_init(void){
	SPCR=(1<<SPE) | (1<<MSTR) ;

//SPI2X SPR1 SPR0 all set to zero, therefore SCK freq is 8Mhz/4
//thats why you sould check initial values for regs
}
void SPI_Send_Byte(unsigned char byte, char slave_pin_no){//data transmission automatic start when SPI DataReg is written, reading 3ady

	SPDR = byte;
	while (!(SPSR & (1<<SPIF)));

}



unsigned char SPI_Send_Recieve_Byte(unsigned char byte, char slave_pin_no){//data transmission automatic start when SPI DataReg is written, reading 3ady

	SPDR = byte;
	while (!(SPSR & (1<<SPIF)));
	//(SPSR & (1<<SPIF)); //read this as mentioned, and then SPDR to clear, no alrady read fo2 a5er cycle
	return SPDR ; //7lwa el raz3a di ?
}



void SPI_Send_String(char * string_to_send, char slave_pin_no){ //zabat 7war el null char da fl a5er
	unsigned short i = 0;

	while(string_to_send[i] != '\0'){ //kda msh hab3t null char
		SPI_Send_Recieve_Byte(string_to_send[i],slave_pin_no);
		i++;
	}

}


unsigned char SPI_Recieve_Byte(void){

	while (!(SPSR & (1<<SPIF)));
		//(SPSR & (1<<SPIF)); //read this as mentioned, and then SPDR to clear, no alrady read fo2 a5er cycle
		return SPDR ; //7lwa el raz3a di ?

}


void SPI_Recieve_String(char * string_to_recieve_in){

	unsigned short i = 0;


	do{
		string_to_recieve_in[i] = SPI_Recieve_Byte();
	}while(string_to_recieve_in[i++] != '\0');


}


