/*
 * uart.c
 *
 *  Created on: Mar 30, 2024
 *      Author: Pipe
 */

#include "uart_wrpr.h"
#include "string.h"
#include "stm32f429xx.h"
#include "main.h"


static CIRCULAR_BUFFER uartRXCBuffDescriptor;
static CIRCULAR_BUFFER uartMainRxBuffDescriptor;

CBUFF_UINT8 uartrxDataBuffer[uartdataRxBuffSize] = {0};
CBUFF_UINT8 uarttxDataBuffer[MSSG_LAST][uartdataTxBuffSize] = DBUG_INFO_MESSAGES;
CBUFF_UINT8 uartMainRxBuff[uartdataMainRxBuffSize];

static CBUFF_RETURN_STATUS cbuff_init(CIRCULAR_BUFFER *cb, CBUFF_UINT8 *data, CBUFF_UINT32 size);
static CBUFF_RETURN_STATUS cbuff_discard(CIRCULAR_BUFFER *cb);
static void uartwrpr_rx(CIRCULAR_BUFFER *cb, uint16_t nbytes);

extern UART_HandleTypeDef huart1;


CBUFF_RETURN_STATUS cbuff_init(CIRCULAR_BUFFER *cb, CBUFF_UINT8 *data, CBUFF_UINT32 size)
{
    if((cb == NULL) || (data == NULL))
    {
        return CBUFF_PARAM_NOT_PROVIDED_FAILURE;
    }

    cb->buffer = data;
    cb->size = size;
    cb->buffer_end = (CBUFF_UINT8 *)cb->buffer + size;
    cb->count = 0;
    cb->read = cb->buffer;
    cb->write = cb->buffer;

    cbuff_discard(cb);

    return CBUFF_SUCCESS;
}


static CBUFF_RETURN_STATUS cbuff_discard(CIRCULAR_BUFFER *cb)
{
//     CBUFF_UINT32 index = 0;
    
//     if((cb == NULL) || (data == NULL))
//     {
//         return CBUFF_PARAM_NOT_PROVIDED_FAILURE;
//     }

//     if ((0 == ))
//     {
//         /* code */
//     }    

//     while (index < cb->size)
//     {
//         *(cb + index) = 0;
//         index++;
//     }
    return CBUFF_SUCCESS;
}

static void uartwrpr_rx(CIRCULAR_BUFFER *cb, uint16_t nbytes)
{
	uint8_t data_at_tail = 0;
	uint8_t data_at_front = 0;

	if (cb->count + nbytes <= cb->size)
	{
		if ((uint8_t *)cb->write + nbytes > (uint8_t *)cb->buffer_end)
		{
			data_at_tail = (uint8_t *)cb->buffer_end - (uint8_t *)cb->write;
			data_at_front = nbytes - data_at_tail;
			memcpy (cb->write, uartrxDataBuffer, data_at_tail);  // copy data in that remaining space
			cb->write = cb->buffer;
			memcpy (cb->write, (uint8_t *)uartrxDataBuffer + data_at_tail, (nbytes - data_at_tail));  // copy data in that remaining space
			cb->write = (uint8_t *)cb->write + data_at_front;
		}
		else
		{
			memcpy (cb->write, uartrxDataBuffer, nbytes);  // copy data in that remaining space
			cb->write = (uint8_t *)cb->write + nbytes;
		}
		
		HAL_UART_Transmit(&huart1, uarttxDataBuffer[MSSG_RECEIVED], uartdataTxBuffSize, 10);
		cb->count = cb->count + nbytes;
	}
	else
	{
		HAL_UART_Transmit(&huart1, uarttxDataBuffer[MSSG_NOT_RECEIVED], uartdataTxBuffSize, 10);
	}
	
}

static void uartwrpr_process(void)
{
	
}

void uartInit(void)
{
    HAL_UARTEx_ReceiveToIdle_DMA(&huart1, uartrxDataBuffer, uartdataRxBuffSize);

    cbuff_init(&uartRXCBuffDescriptor, uartrxDataBuffer, uartdataRxBuffSize);
	cbuff_init(&uartMainRxBuffDescriptor, uartMainRxBuff, uartdataMainRxBuffSize);
}


void uart_Main(void)
{
    
    
}


void HAL_UARTEx_RxEventCallback(UART_HandleTypeDef *huart, uint16_t Size)
{
	HAL_GPIO_WritePin(LD4_GPIO_Port, LD4_Pin, GPIO_PIN_RESET);

	if (huart->Instance == USART1)
	{
		uartwrpr_rx(&uartMainRxBuffDescriptor, Size);
	}

	HAL_UARTEx_ReceiveToIdle_DMA(huart, uartrxDataBuffer, uartdataRxBuffSize);

	HAL_GPIO_WritePin(LD4_GPIO_Port, LD4_Pin, GPIO_PIN_SET);
}
