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
void smRun(void);

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
	for (int var = 0; var < 100; ++var)
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

void smRun(void)
{

	for (;;)
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

/*API*/
StpMtrReturnType smMoveAxis2Pos(StpMtrRequestType *request)
{
	//uint8_t status = E_NOK;
	//uint8_t state;
	return 0;
}
