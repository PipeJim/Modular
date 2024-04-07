/*
 * uart_wrpr.h
 *
 *  Created on: Mar 30, 2024
 *      Author: Pipe
 */

#ifndef UART_WRPR_INC_UART_WRPR_H_
#define UART_WRPR_INC_UART_WRPR_H_

#define uartdataRxBuffSize 20
#define uartdataMainRxBuffSize 15
#define uartdataTxBuffSize 60

typedef unsigned char CBUFF_UINT8;
typedef unsigned long int CBUFF_UINT32;

typedef enum
{
  CBUFF_SUCCESS,
  CBUFF_PARAM_NOT_PROVIDED_FAILURE,
  CBUFF_FULL,
  CBUFF_NOT_FULL,
  CBUFF_EMPTY,
  CBUFF_NOT_EMPTY,
} CBUFF_RETURN_STATUS;

typedef enum
{
  UARTWRPR_SUCCESS,
  UARTWRPR_NOT_SUCCESS
} UARTWRPR_RETURN_STATUS;

#define DBUG_INFO_MESSAGES \
{ \
  "\nINFO: INSTRUCTION received\n",\
  "\nINFO: INSTRUCTION fail\n",\
}

typedef enum
{
  MSSG_RECEIVED,
  MSSG_NOT_RECEIVED,
  MSSG_LAST
} MESSAGES_INFO;

typedef struct uartCircularBuffer
{
  void *buffer;
  void *buffer_end;
  CBUFF_UINT32 size;
  CBUFF_UINT32 count;
  void *read;
  void *write;
} CIRCULAR_BUFFER;


void uart_Main(void);

void uartInit(void);

#endif /* UART_WRPR_INC_UART_WRPR_H_ */
