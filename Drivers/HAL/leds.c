/*
 * leds.c
 *
 *  Created on: Oct 4, 2024
 *      Author: Mariam hassan
 */

#include "gpio.h"
#include "leds.h"
#include "common_macros.h"
#include <avr/io.h>
void LEDS_init(void)
{
	/*initialize all leds pin direction*/
	GPIO_setupPinDirection(LEDS_PORT_ID,LED_RED_PIN_ID,PIN_OUTPUT);
	GPIO_setupPinDirection(LEDS_PORT_ID,LED_GREEN_PIN_ID,PIN_OUTPUT);
	GPIO_setupPinDirection(LEDS_PORT_ID,LED_BLUE_PIN_ID,PIN_OUTPUT);
	/*turn off all leds*/
#if (POSTIVE_LOGIC==1 && NEGATIVE_LOGIC==0)
    /*postive turn off by low on its pin*/
	GPIO_writePin(LEDS_PORT_ID,LED_RED_PIN_ID,LOGIC_LOW);
	GPIO_writePin(LEDS_PORT_ID,LED_GREEN_PIN_ID,LOGIC_LOW);
	GPIO_writePin(LEDS_PORT_ID,LED_BLUE_PIN_ID,LOGIC_LOW);

#elif (POSTIVE_LOGIC==0 && NEGATIVE_LOGIC==1)
    /* negative logic turn off by high on pin */
	GPIO_writePin(LEDS_PORT_ID,LED_RED_PIN_ID,LOGIC_HIGH);
    GPIO_writePin(LEDS_PORT_ID,LED_GREEN_PIN_ID,LOGIC_HIGH);
	GPIO_writePin(LEDS_PORT_ID,LED_BLUE_PIN_ID,LOGIC_HIGH);

#endif
}

void LED_on( uint8 LED_ID)
{
	/*TURN ON LED BY WRITE HIGH ON ITS PIN*/

#if (POSTIVE_LOGIC==1 && NEGATIVE_LOGIC==0)
	switch (LED_ID)
	{

	   case LED_BLUE_PIN_ID:
		   GPIO_writePin(LEDS_PORT_ID,LED_BLUE_PIN_ID,LOGIC_HIGH);
		   break;
	   case LED_GREEN_PIN_ID:
		   GPIO_writePin(LEDS_PORT_ID,LED_GREEN_PIN_ID,LOGIC_HIGH);
		   break;
	   case LED_RED_PIN_ID:
	   		GPIO_writePin(LEDS_PORT_ID,LED_RED_PIN_ID,LOGIC_HIGH);
	   		break;
	}
	/*TURN ON LED BY WRITE LOW ON ITS PIN*/
#elif(POSTIVE_LOGIC==0 && NEGATIVE_LOGIC==1)
	switch (LED_ID)
		{

		   case LED_BLUE_PIN_ID:
			   GPIO_writePin(LEDS_PORT_ID,LED_BLUE_PIN_ID,LOGIC_LOW);
			   break;
		   case LED_GREEN_PIN_ID:
			   GPIO_writePin(LEDS_PORT_ID,LED_GREEN_PIN_ID,LOGIC_LOW);
			   break;
		   case LED_RED_PIN_ID:
		   		GPIO_writePin(LEDS_PORT_ID,LED_RED_PIN_ID,LOGIC_LOW);
		   		break;
		}
#endif

}

void LED_off(uint8 LED_ID)
{
	/*TURN OFF LED BY WRITE LOW ON ITS PIN */
#if (POSTIVE_LOGIC==1 && NEGATIVE_LOGIC==0)
	switch (LED_ID)
	{

	   case LED_BLUE_PIN_ID:
		   GPIO_writePin(LEDS_PORT_ID,LED_BLUE_PIN_ID,LOGIC_LOW);
		   break;
	   case LED_GREEN_PIN_ID:
		   GPIO_writePin(LEDS_PORT_ID,LED_GREEN_PIN_ID,LOGIC_LOW);
		   break;
	   case LED_RED_PIN_ID:
	   		GPIO_writePin(LEDS_PORT_ID,LED_RED_PIN_ID,LOGIC_LOW);
	   		break;
	}
	/*TURN OFF LED BY WRITE HIGH ON ITS PIN */
#elif(POSTIVE_LOGIC==0 && NEGATIVE_LOGIC==1)
	switch (LED_ID)
	{

	   case LED_BLUE_PIN_ID:
			   GPIO_writePin(LEDS_PORT_ID,LED_BLUE_PIN_ID,LOGIC_HIGH);
			   break;
	   case LED_GREEN_PIN_ID:
		   GPIO_writePin(LEDS_PORT_ID,LED_GREEN_PIN_ID,LOGIC_HIGH);
		   break;
	   case LED_RED_PIN_ID:
	   		GPIO_writePin(LEDS_PORT_ID,LED_RED_PIN_ID,LOGIC_HIGH);
		   		break;
	}
#endif

}
