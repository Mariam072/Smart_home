/*
 * flame.c
 *
 *  Created on: Oct 4, 2024
 *      Author: Mariam hassan
 */

#include "flame.h"
#include "adc.h"
#include "gpio.h"
#include "common_macros.h"
#include <avr/io.h>

void FlameSensor_init(void)
{
	/*set pin as input*/
	GPIO_setupPinDirection(FLAME_SENSOR_PORT,FLAME_SENSOR_PIN,PIN_INPUT);

}
uint8 FlameSensor_getValue(void)
{
	/*check on pin and return value indecating detection*/
	uint8 value=GPIO_readPin(FLAME_SENSOR_PORT,FLAME_SENSOR_PIN);

	return value ;
}
