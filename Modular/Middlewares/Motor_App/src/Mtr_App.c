/*
 * Mtr_App.c
 *
 *  Created on: Feb 19, 2024
 *      Author: Pipe
 */
#include "Mtr_App.h"
#include "stm32f4xx_hal.h"
#include "stpMotor.h"
#include "main.h"


extern UART_HandleTypeDef huart1;

void Mian(void)
{
    uint8_t dataRx[10];
    HAL_UART_Receive(&huart1, dataRx, 5, 50);
    HAL_UART_Transmit(&huart1, dataRx, 1, 1);
}
