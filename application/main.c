/*
 * main.c
 *
 *  Created on: Oct 4, 2024
 *      Author: Mariam hassan
 */

#include "gpio.h"
#include "lcd.h"
#include"dcmotor.h"
#include "ldr.h"
#include "lm35_sensor.h"
#include "pwm.h"
#include "flame.h"
#include "adc.h"
#include "leds.h"
#include"buzzer.h"
#include <avr/io.h>
#include<util/delay.h>

/*function to control ligth*/
void automated_light_control(uint16 intensity)
{
	/*set condition of intensity*/
	if (intensity <= 15)
	{
		LED_on(LED_RED_PIN_ID);
		LED_on(LED_GREEN_PIN_ID);
		LED_on(LED_BLUE_PIN_ID);

	}else if ((intensity >= 16) && (intensity <=50))
	{
		LED_on(LED_RED_PIN_ID);
		LED_on(LED_GREEN_PIN_ID);
		LED_off(LED_BLUE_PIN_ID);

	}else if ((intensity >= 51) && (intensity <70))
	{
		LED_on(LED_RED_PIN_ID);
		LED_off(LED_GREEN_PIN_ID);
		LED_off(LED_BLUE_PIN_ID);
	}else if ((intensity >=70 ))
	{
		LED_off(LED_RED_PIN_ID);
		LED_off(LED_GREEN_PIN_ID);
		LED_off(LED_BLUE_PIN_ID);
	}
/* displaying intensity on lcd*/
	LCD_displayStringRowColumn(1,0,"LDR:");
	LCD_intgerToString(intensity);
	LCD_displayCharacter('%');
}
 /*===================================================================*/
/*function for speed control*/
void Fan_Speed_Control(uint8 temp)
{
	/*set control conditions*/
	if (temp < 25)
		{
			DcMotor_Rotate(STOP,0);

		}else if ((temp >= 25) && (temp <=30))
		{
			DcMotor_Rotate(ACW,64);
		}else if ((temp >= 30) && (temp <35))
		{
			DcMotor_Rotate(ACW,128);
		}else if ((temp >= 35) && (temp <40))
		{
			DcMotor_Rotate(ACW,192);
		}else if ((temp >=40 ))
		{
			DcMotor_Rotate(ACW,255);
		}
	if (temp<25)
	{
		LCD_displayStringRowColumn(0,2,"FAN IS OFF");
	}else
	{
		LCD_displayStringRowColumn(0,2,"FAN IS ON");
		LCD_displayCharacter(' ');
	}
	/* display temperature on lcd*/
	LCD_displayStringRowColumn(1,8,"TEMP:");
	LCD_intgerToString(temp);
	LCD_displayCharacter('%');
}
/*===================================================================*/
/* flame detection function*/
void flame_detection(uint8 detect)
{
    static int flag = 0;  /* flame detection state*/

    // Check if the flame is detected
    while (detect != 0)
    {
        if (flag == 0)
        {
            Buzzer_on();  // Turn on the buzzer
            LCD_clearScreen();  // Clear LCD before showing alert
            LCD_displayString("Critical alert!!!");  // Display alert message
            flag = 1;  // Set flag to indicate flame is detected
        }

        // Break out of the while loop if the flame is no longer detected
       detect = FlameSensor_getValue();  // Update the detection value inside the loop
        if (detect == 0)  // If flame is no longer detected
        {
            Buzzer_off();  // Turn off the buzzer
            LCD_clearScreen();  // Clear LCD before showing normal message
              // Display normal message
            flag = 0;  // Reset the flag
            break;  // Exit the while loop and return to normal operation
        }
    }
}



int main ()
{

	    uint16 ldr_light=0;   /*variable to hold light intensity*/
	    uint8 lm_temp,flame;  /*variables to hold temperature and flame detector*/
	    /* intialization of all modules you will use in application*/
	            ADC_init();
	            LCD_init();
				LEDS_init();
				DcMotor_Init();
			    Buzzer_init();
			    FlameSensor_init();
	while (1)
	{
		/*calling function of speed control passing temp to it*/
		  lm_temp=LM35_getTemperature();
		  Fan_Speed_Control(lm_temp);
	   /*calling function of light control passing intensity to it*/
		  ldr_light=LDR_getLightIntensity();
		  automated_light_control(ldr_light);
	  /*calling function of flame detection passing detect to it*/
          flame=FlameSensor_getValue();
          flame_detection(flame);

	}
}
