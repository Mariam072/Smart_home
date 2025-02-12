/*
 * flame.h
 *
 *  Created on: Oct 4, 2024
 *      Author: Mariam hassan
 */

#ifndef FLAME_H_
#define FLAME_H_

#include "std_types.h"

#define FLAME_SENSOR_PORT   PORTD_ID
#define FLAME_SENSOR_PIN    PIN2_ID

void FlameSensor_init(void);
uint8 FlameSensor_getValue(void);

#endif /* FLAME_H_ */
