

#ifndef SPI_H_
#define SPI_H_



extern void SPI_init(void);


extern unsigned char SPI_Send_Recieve_Byte(unsigned char byte, char slave_pin_no);//zyada for simultinuous

extern void SPI_Send_Byte(unsigned char byte, char slave_pin_no);
extern void SPI_Send_String(char * string_to_send, char slave_pin_no);

extern unsigned char SPI_Recieve_Byte(void);
extern void SPI_Recieve_String(char * string_to_recieve_in);//hya hya el send







#endif /* SPI_H_ */
