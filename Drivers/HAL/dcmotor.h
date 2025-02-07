/*
 * dcmotor.h
 *
 *  Created on: Oct 4, 2024
 *      Author: Mariam hassan
 */

#ifndef DCMOTOR_H_
#define DCMOTOR_H_
#include "std_types.h"

#define DC_MOTOR_PORT         PORTB_ID
#define DC_MOTOR_PIN_INTPUT1  PIN0_ID
#define DC_MOTOR_PIN_INTPUT2  PIN1_ID
#define DC_MOTOR_PIN_ENABLE   PIN3_ID


typedef enum
{
	STOP,CW,ACW

}DcMotor_State;

void DcMotor_Init(void);
void DcMotor_Rotate(DcMotor_State state, uint8 speed);


#endif /* DCMOTOR_H_ */
