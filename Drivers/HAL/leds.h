/*
 * leds.h
 *
 *  Created on: Oct 4, 2024
 *      Author: Mariam hassan
 */

#ifndef LEDS_H_
#define LEDS_H_
#include "std_types.h"


#define POSTIVE_LOGIC  1
#define NEGATIVE_LOGIC 0
#define LEDS_PORT_ID      PORTB_ID
#define LED_RED_PIN_ID    PIN5_ID
#define LED_GREEN_PIN_ID  PIN6_ID
#define LED_BLUE_PIN_ID   PIN7_ID

void LEDS_init(void);
void LED_on( uint8 LED_ID);
void LED_off(uint8 LED_ID);


#endif /* LEDS_H_ */
