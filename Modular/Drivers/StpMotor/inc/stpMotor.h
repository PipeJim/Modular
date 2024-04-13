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
typedef unsigned char boolean;

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
	kEOL_None,
	kEOL_Top,
	kEOL_Bottom,
	kEOL_Right,
	kEOL_Left,
	kEOL_Unkown
}StpMtrEOLActive;

typedef enum
{
	kReq_Done,
	kReq_standby
}ReqPhaseType;

typedef enum
{
	E_OK,
	E_NOK
}StpMtrReturnType;

/* Step Motor Client callback function type */
typedef void (* StpMotorReqCbk)(AxisGroup motor, uint8_t crrntStp, StpMtrEOLActive eolDetected, StpMtrReturnType PosResult);

/***************************************** Structures *********************************************/
typedef struct stpMotorDes
{
	AxisGroup 			axisGroup;
	StpMtrState 		state;
	StepperMotorCfg 	*stpMotorCfg;
	uint8_t				crrnt_step;
	StpMtrEOLActive 	EOLflag;
}AxisStpMtrDescriptor;

typedef struct stpMotorRequest
{
	AxisGroup axisGroup;
	uint8_t	steps_to_move;
	boolean	dir;
	StpMotorReqCbk ClientCallback;
}StpMtrRequestType;


/***************************************** Global Variables ***************************************/

/***************************************** Function Prototypes ************************************/

/***************************************** Functions **********************************************/

void smInit(void);


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
void smRun(StpMtrRequestType *request);
StpMtrReturnType smSetRequest(StpMtrRequestType *request);

#endif /* STP_MOTOR_H */
