/**
 * @file    UART.h
 * @brief   UART driver API.
 * @author  Marawan Azmy
 */

#ifndef UART_H_
#define UART_H_

volatile void UART_Init(long Baud_rate);

volatile void UART_Send_Byte(char byte_input);
volatile void UART_Send_String(char *string_input);

volatile unsigned char UART_Recieve_Byte(void);
volatile void UART_Recieve_String(char *string_returned);

#endif /* UART_H_ */
