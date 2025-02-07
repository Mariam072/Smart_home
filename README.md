# Smart_home
This project involves developing a smart home system that adjusts lighting, fan speed, and safety  alerts based on environmental conditions

# Smart_home
This project involves developing a smart home system that adjusts lighting, fan speed, and safety  alerts based on environmental conditions
Project Overview:
This project involves developing a smart home system that adjusts lighting, fan speed, and safety 
alerts based on environmental conditions:

1. Lighting Control: The LDR detects ambient light intensity and controls three LEDs to 
indicate different levels of light.

2. Fan Speed Control: The LM35 temperature sensor adjusts the fan speed proportionally to 
the room temperature.

3. Fire Detection: A flame sensor detects fire, triggers an alarm, and displays a critical alert 
on the LCD.

4. LCD Display: Shows real-time temperature readings, fan status, light intensity, and alerts.
   
Features:
1• Automatic Lighting Control: Based on the LDR readings, the system controls three LEDs 
according to light intensity thresholds:
o Intensity < 15%: All 3 LEDs (Red, Green, and Blue) turn ON.
o Intensity 16–50%: Red and Green LEDs turn ON.
o Intensity 51–70%: Only the Red LED turns ON.
o Intensity > 70%: All LEDs are turned OFF.

2• Automatic Fan Speed Control: Fan speed is automatically adjusted based on room 
temperature, controlled by a PWM signal. The fan operates at different speeds based on 
temperature ranges:
o Temperature ≥ 40°C: Fan ON at 100% speed.
o Temperature ≥ 35°C and < 40°C: Fan ON at 75% speed.
o Temperature ≥ 30°C and < 35°C: Fan ON at 50% speed.
o Temperature ≥ 25°C and < 30°C: Fan ON at 25% speed.
o Temperature < 25°C: Fan OFF.

3• Fire Detection and Alert: The system raises an alarm and displays "Critical alert!" on the 
LCD if fire is detected. The system remains in alert mode until the flame is no longer 
detected.

4• LCD Display: Real-time feedback on system status:
o First Row: Displays "FAN is ON" or "FAN is OFF" based on the fan's state.
o Second Row: Displays "Temp= xxC LDR= xxx%" showing temperature and light 
intensity.


Hardware Components:
• Microcontroller: ATmega32.
• Light Sensor: LDR (Connected to PA0, ADC Channel 0).
• Temperature Sensor: LM35 (Connected to PA1, ADC Channel 1).
• Display: 16x2 LCD in 8-bit mode.
o RS: PD0.
o Enable: PD1.
o R/W: Ground (always write mode).
o Data Pins: PORTC (8-bit mode).
• Motor Control: H-Bridge connected for motor speed control.
o IN1: PB0.
o IN2: PB1.
o Enable1: PB3/OC0.
• LEDs:
o Red LED: Connected to PB5.
o Green LED: Connected to PB6.
o Blue LED: Connected to PB7.
• Flame Sensor: Connected to PD2 to detect fire.
• Buzzer: Connected to PD3, activated during fire alert.


Operation Description:
• Lighting Control (LDR): The LDR monitors light intensity, and the three LEDs are controlled 
based on the previous mentioned thresholds.

• Temperature Control (LM35): The LM35 sensor measures room temperature. The fan 
speed is controlled using a PWM signal adjusting speed according to temperature ranges 
specified above.

• Fire Detection: The flame sensor triggers an alert when fire is detected:
o Displays "Critical alert!" on the LCD.
o Activates the buzzer.
o The system stays in alert mode until the flame sensor no longer detects fire.

• LCD Display:
o First Row: Indicates the fan status ("FAN is ON" or "FAN is OFF").
o Second Row: Displays temperature ("Temp= xxx") and light intensity ("LDR= xx%").


System Requirements:
1. Microcontroller: ATmega32
2. System Frequency: 16 MHz
3. The Project should be implemented using the below layered model architecture
