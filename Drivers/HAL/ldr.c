/*
 * ldr.c
 *
 *  Created on: Oct 4, 2024
 *      Author: Mariam hassan
 */


#include "gpio.h"
#include "adc.h"
#include "ldr.h"

uint16 LDR_getLightIntensity(void)
{
	    uint8 light_value = 0;

		uint16 adc_value = 0;

		/* Read ADC channel where the LDR sensor is connected */
		adc_value = ADC_readChannel(LDR_CHANNEL_ID);

		/* Calculate the LDR from the ADC value*/
		light_value = (uint8)(((uint32)adc_value*LDR_SENSOR_MAX_LIGHT_INTENSITY*ADC_REF_VOLT_VALUE)/(ADC_MAXIMUM_VALUE*LDR_SENSOR_MAX_VOLT_VALUE));

		return light_value;
}
