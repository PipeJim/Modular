/*==================================================================================================
 * FILE: stpMotor.c
 *==================================================================================================
 * Author:				Felipe J.
 * Date Created			Dec 2023
 *--------------------------------------------------------------------------------------------------
 * DESCRIPTION:
 *
 =================================================================================================*/
/***************************************** Includes ***********************************************/
#include "stm32f429xx.h"
#include "cmsis_os2.h"
#include "stpMotor.h"
#include "main.h"

/***************************************** Defines ************************************************/

/***************************************** Structures *********************************************/
StepperMotorCfg ZMotors_Cfg[kZMotors_nOf] = Motor_Z_Axis;
StepperMotorCfg XMotors_Cfg[kXMotors_nOf] = Motor_X_Axis;

AxisStpMtrDescriptor ZAxisDes =
{
	.axisGroup = SMDRV_AXIS_Z,
	.stpMotorCfg = ZMotors_Cfg,
	.crrnt_step = 0,
	.EOLflag = kEOL_Unkown,
	.state = STOP
};

AxisStpMtrDescriptor XAxisDes;

/***************************************** Global Variables ***************************************/

/***************************************** Typedef ************************************************/

/***************************************** Function Prototypes ************************************/
StpMtrReturnType smInitAxisandMotors(AxisStpMtrDescriptor * axisDes, AxisGroup group, StepperMotorCfg *motorCfg);

/***************************************** Functions **********************************************/

/***************************************************************************************************
 *
 *	FUNCTION NAME:
 *
 **************************************************************************************************/
/**
 * @brief breve descripcion, no mas de un renglon
 *
 * desglosar el breif
 *
 * @param[in,out] *variable: descripcion del argumento recibido
 *
 * @return
 *
 * @note
 *
 **************************************************************************************************/
void smInit(void)
{
	smInitAxisandMotors(&XAxisDes, SMDRV_AXIS_X, XMotors_Cfg);
	smInitAxisandMotors(&ZAxisDes, SMDRV_AXIS_Z, ZMotors_Cfg);

}


StpMtrReturnType smInitAxisandMotors(AxisStpMtrDescriptor * axisDes, AxisGroup group, StepperMotorCfg *motorCfg)
{
	if(NULL != axisDes)
	{
		axisDes->axisGroup = group;
		axisDes->stpMotorCfg = motorCfg;
		axisDes->crrnt_step = 0;
		axisDes->EOLflag = kEOL_Unkown;
		axisDes->state = STOP;
	}

	return 0;
}

/***************************************************************************************************
 *
 *	FUNCTION NAME:
 *
 **************************************************************************************************/
/**
 * @brief breve descripcion, no mas de un renglon
 *
 * desglosar el breif
 *
 * @param[in,out] *variable: descripcion del argumento recibido
 *
 * @return
 *
 * @note
 *
 **************************************************************************************************/
void smMotorSteps(uint8_t steps)
{
	for (int var = 0; var < 200; ++var)
	{
		HAL_GPIO_WritePin(SMZR_STEP_GPIO_Port, SMZR_STEP_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(SMZL_STEP_GPIO_Port, SMZL_STEP_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(SMX_STEP_GPIO_Port, SMX_STEP_Pin, GPIO_PIN_SET);
		osDelay(1);
		HAL_GPIO_WritePin(SMZR_STEP_GPIO_Port, SMZR_STEP_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SMZL_STEP_GPIO_Port, SMZL_STEP_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SMX_STEP_GPIO_Port, SMX_STEP_Pin, GPIO_PIN_RESET);
		osDelay(1);
	}
}

void smRun(StpMtrRequestType *request)
{
	StpMtrRequestType *req;

	for (uint8_t i = 0; i < 8; i++)
	{
		if (ZAxisDes.EOLflag != kEOL_Top)
		{
			HAL_GPIO_TogglePin(SMZR_STEP_GPIO_Port, SMZR_STEP_Pin);
			osDelay(1);
		}
		else
		{
			
			break;
		}
	}
}

void sm_Task(void)
{

}

/*API*/
StpMtrReturnType smSetRequest(StpMtrRequestType *request)
{
	uint8_t retval = E_NOK;
	
	
	
	return retval;
}

/***********************************************************************************
 * 
 * @brief External Interupt Handler for End of Line switches
 *
 **********************************************************************************/
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	GPIO_TypeDef *port;
	StpMtrEOLActive flag = kEOL_None;

	switch (GPIO_Pin){
		case TOP_ZEL_Pin:
			port = TOP_ZEL_GPIO_Port;
			flag = kEOL_Top;
			break;
		case RGHT_XEL_Pin:
			port = RGHT_XEL_GPIO_Port;
			flag = kEOL_Right;
			break;
		case BOTT_ZEL_Pin:
			port = BOTT_ZEL_GPIO_Port;
			flag = kEOL_Bottom;
			break;
		case LEFT_XEL_Pin:
			port = LEFT_XEL_GPIO_Port;
			flag = kEOL_Left;
			break;	
		default:
			break;
	}

	if (GPIO_PIN_SET == HAL_GPIO_ReadPin(port,GPIO_Pin))
	{
		if (TOP_ZEL_Pin == GPIO_Pin || BOTT_ZEL_Pin== GPIO_Pin)
		{
			ZAxisDes.EOLflag = flag;			
		}
		else if (RGHT_XEL_Pin == GPIO_Pin || LEFT_XEL_Pin== GPIO_Pin)
		{
			XAxisDes.EOLflag = flag;
		}
	}
}
