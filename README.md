## General Information

The Purpose of a code is to implement clock with servo motor and stepper motor and give it various features using
various components

## Program Information

#### Program includes the following Commands:

- String showTime();
- void setTimer(double minutes);
- void setTimerByHand();
- void setAlarmByHand();
- void setAlarm(int hour,int minutes);
- int setTimeOnAlarm();
- void checkAlarm();
- double setStopwatch();
- double setStopwatchByHand();

#### Program uses the following components:

- Arduino Uno
- Breadboard
- Servo motor
- Stepper motor (including driver bridge)
- Buzzer
- RGB led
- Resistors
- Female-male and male-male cables

## Commands

`Motorclock(int hour, int minutes, uint8_t servoP, uint8_t stepperN1P, uint8_t
stepperN2P, uint8_t stepperN3P, uint8_t stepperN4P, uint8_t buzzerP, uint8_t
button1P, uint8_t button2P, uint8_t rgbRP, uint8_t rgbGP, uint8_t rgbBP)`

It initializes the clock according to the given hour and minute. Note that the clock does not tick continuously, only
when requested by the user.

`String showTime()`
The function should rotate clock hands and set them based on hour and minute values. It should also return the
value in a string format of "hour:minutes".


