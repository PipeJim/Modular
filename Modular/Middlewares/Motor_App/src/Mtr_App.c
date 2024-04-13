/*
 * Mtr_App.c
 *
 *  Created on: Feb 19, 2024
 *      Author: Pipe
 */
#include "Mtr_App.h"
#include "stpMotor.h"
#include "uart_wrpr.h"

void mtrApp_ExtractRoutine(void);
void mtrApp_SaveRoutine(void);
void mtrApp_SearchRoutine(void);
void mtrApp_DeliveryRoutine(void);

void mtrAppInit(void)
{



}

void mtrApp_TableProcess(void)
{

}

void mtrApp_StpMtrCalibration(void)
{
    StpMtrRequestType request;
    StpMtrReturnType retXaxis;

    request.axisGroup = SMDRV_AXIS_Z;
    request.dir = AxisDir_Z_DOWN;
    

    smSetRequest(&request);
    
    
}

void mtrApp_Main(void)
{
    

}

void mtrApp_SetPos2Move(void)
{


}

void mtrApp_ExtractRoutine(void)
{

}
void mtrApp_SaveRoutine(void)
{

}
void mtrApp_SearchRoutine(void)
{

}

void mtrApp_DeliveryRoutine(void)
{

}

void mtrApp_Callback(AxisGroup motor, uint8_t crrntStp, StpMtrReturnType PosResult)
{

}
