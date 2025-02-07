/*
 * pwm.h
 *
 *  Created on: Oct 4, 2024
 *      Author: Mariam hassan
 */

#ifndef PWM_H_
#define PWM_H_
#include "std_types.h"

#define PWM_TIMER0_PORT   PORTB_ID
#define PWM_OC0_PIN       PIN3_ID
void PWM_Timer0_Start(uint8 duty_cycle);

#endif /* PWM_H_ */
