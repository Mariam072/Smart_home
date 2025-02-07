/*
 * dcmotor.c
 *
 *  Created on: Oct 4, 2024
 *      Author: Mariam hassan
 */


#include "gpio.h"
#include "dcmotor.h"
#include "pwm.h"




void DcMotor_Init(void)
{
	/*Initializes the DC motor by setting the direction */
  GPIO_setupPinDirection(DC_MOTOR_PORT,DC_MOTOR_PIN_INTPUT1,PIN_OUTPUT);
  GPIO_setupPinDirection(DC_MOTOR_PORT,DC_MOTOR_PIN_INTPUT2,PIN_OUTPUT);
  GPIO_setupPinDirection(DC_MOTOR_PORT,DC_MOTOR_PIN_ENABLE,PIN_OUTPUT);
         /*STOP MOTOR AT BEGINING*/
  GPIO_writePin(DC_MOTOR_PORT,DC_MOTOR_PIN_INTPUT1,LOGIC_LOW);
  GPIO_writePin(DC_MOTOR_PORT,DC_MOTOR_PIN_INTPUT2,LOGIC_LOW);
  GPIO_writePin(DC_MOTOR_PORT,DC_MOTOR_PIN_ENABLE,LOGIC_HIGH);

}

void DcMotor_Rotate(DcMotor_State state, uint8 speed)
{

	switch (state)
	{
	case CW:
		/* CLOCKWISE INT1=0,INT2=1*/
		GPIO_writePin(DC_MOTOR_PORT,DC_MOTOR_PIN_INTPUT1,LOGIC_LOW);
		GPIO_writePin(DC_MOTOR_PORT,DC_MOTOR_PIN_INTPUT2,LOGIC_HIGH);
		break;
	case ACW:
		/* CLOCKWISE INT1=1,INT2=0*/
		GPIO_writePin(DC_MOTOR_PORT,DC_MOTOR_PIN_INTPUT1,LOGIC_HIGH);
		GPIO_writePin(DC_MOTOR_PORT,DC_MOTOR_PIN_INTPUT2,LOGIC_LOW);
		break;
	case STOP:/* CLOCKWISE INT1=0,INT2=0*/
	default :
		GPIO_writePin(DC_MOTOR_PORT,DC_MOTOR_PIN_INTPUT1,LOGIC_LOW);
	    GPIO_writePin(DC_MOTOR_PORT,DC_MOTOR_PIN_INTPUT2,LOGIC_LOW);
	    PWM_Timer0_Start(0);
	    break;
	}
	PWM_Timer0_Start(speed);
}
