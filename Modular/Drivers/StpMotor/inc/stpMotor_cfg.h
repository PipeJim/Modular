#ifndef _STPMOTOR_CFG_H_
#define _STPMOTOR_CFG_H_

/*==================================================================================================
 * FILE: stpMotor_cfg.h
 *==================================================================================================
 * Author:				Felipe J.
 * Date Created			Dec 2023
 *--------------------------------------------------------------------------------------------------
 * DESCRIPTION:
 *
 =================================================================================================*/
/***************************************** Includes ***********************************************/
#include "main.h"

/***************************************** Defines ************************************************/
#define StepsperRev	200

#define Motor_X_Axis \
{\
	{ \
	  SMX_DIR_GPIO_Port,\
	  SMX_DIR_Pin,\
	  SMX_STEP_GPIO_Port,\
	  SMX_STEP_Pin\
	}\
}

#define Motor_Z_Axis \
{ \
	{ /* Right position Motor*/\
	  SMZR_DIR_GPIO_Port,				/**/\
	  SMZR_DIR_Pin,\
	  SMZR_STEP_GPIO_Port,\
	  SMZR_STEP_Pin\
	},\
	{/* Left position Motor*/\
	  SMZL_DIR_GPIO_Port, \
	  SMZL_DIR_Pin,\
	  SMZL_STEP_GPIO_Port,\
	  SMZL_STEP_Pin\
	}\
}

/***************************************** Typedef ************************************************/
typedef struct stpMotorCfg
{
	const unsigned long dirPort;
	const uint16_t dirPin;
	const unsigned long stepPort;
	const uint16_t stepPin;
	const uint8_t stpXRev;
}StepperMotorCfg;

/***************************************** Enumerations *******************************************/
typedef enum
{
	SMDRV_AXIS_X,
	SMDRV_AXIS_Z,
	SMDRV_AXIS_Y
}AxisGroup;

typedef enum
{
	kTurnLeft,
	kTurnRight,
	kTurn_invalid
}Direction;

typedef enum
{
	kZMotor_Right,
	kZMotor_Left,
	kZMotors_nOf
}NoOf_Z_StpMotor;

typedef enum
{
	kXMotor,
	kXMotors_nOf
}NoOf_X_StpMotor;

/***************************************** Structures *********************************************/


/***************************************** Global Variables ***************************************/

/***************************************** Function Prototypes ************************************/

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

#endif /* _STPMOTOR_CFG_H_ */
