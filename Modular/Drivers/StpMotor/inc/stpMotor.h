#ifndef _STPMOTOR_H_
#define _STPMOTOR_H_

/*==================================================================================================
 * FILE: stpMotor.h
 *==================================================================================================
 * Author:				Felipe J.
 * Date Created			Dec 2023
 *--------------------------------------------------------------------------------------------------
 * DESCRIPTION:
 *
 =================================================================================================*/
/***************************************** Includes ***********************************************/
#include "stpMotor_cfg.h"

/***************************************** Defines ************************************************/
#define Rojo 0
#define Verde 1

/***************************************** Typedef ************************************************/
typedef enum
{
	STOP,
	ACCELERATING,
	MOVING,
	DESACELERATING
}StpMtrState;

typedef enum
{
	STATE_NOTSTARTED,
	STATE_INIT,
	STATE_MAIN
}MainStpMtrStatus;

typedef enum
{
	kDIR_UP,
	kDIR_DOWN
}StpMtrZDir;

typedef enum
{
	kDIR_RIGHT,
	kDIR_LEFT
}StpMtrXDir;

typedef enum
{
	kEOL_None,
	kEOL_Top,
	kEOL_Bottom,
	kEOL_Right,
	kEOL_Left,
	kEOL_Unkown
}StpMtrEOLActive;

typedef enum
{
	E_OK,
	E_NOK
}StpMtrReturnType;

/***************************************** Structures *********************************************/
typedef struct stpMotorDes
{
	AxisGroup axisGroup;
	StpMtrState state;
	StepperMotorCfg *stpMotorCfg;
	uint8_t	crrnt_step;
	StpMtrEOLActive EOLflag;
}AxisStpMtrDescriptor;

typedef struct stpMotorRequest
{
	uint8_t	steps_to_move;
	uint8_t	dir;
}StpMtrRequestType;


/***************************************** Global Variables ***************************************/

/***************************************** Function Prototypes ************************************/

/***************************************** Functions **********************************************/

void smInit(AxisStpMtrDescriptor *StpMotor);


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
void smMotorSteps(uint8_t steps);

#endif /* STP_MOTOR_H */
