## General Information

The purpose of a code is to implement clock with servo motor and stepper motor and give it various features using
various components, such as: stopwatch,alarm,timer and so on.

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

`void setTimer(double minutes)`

If given minutes, the program checks the passage of time and notifies the user with the sound of a buzzer upon time expiration. The buzzer sound should be heard continuously until the user presses the "II" button

`void setTimerByHand()`

The user should have the opportunity to set the desired timer manually using two buttons. Button I is used to differentiate the time by pressing it once = 1 minute. Button II fixes the entered time. After the time runs out, in this case, the buzzer will sound until the user presses the II button. For example: if the user wants to set a 7-minute timer, after entering the command, they will press the I button 7 times, then press the II button to fix the minutes. After 7 seconds from the start of the timer, the buzzer will sound from the II button, and the command will be completed if the user does not press the II button again.

`void setAlarm(int hour, int minutes)`

Using this command, the user sets the alarm by specifying the corresponding hour and minute values.

`void setAlarmByHand()`

This command is similar to setTimerByHand();, but in this case it is necessary to fix the hours and minutes. First, the user sets the desired hour by pressing the I button - pressing 1 adds 1 hour (if the user presses the I button more than 12 times, the counting starts from the beginning). Then the user presses the II button to fix the hour. After fixing the hour, the user sets the desired number of minutes by pressing the I button again - pressing 1 adds 10 minutes (if the user presses the I button more than 6 times, the counting starts from the beginning).

`void checkAlarm()`

If the alarm is installed and at the time of checking this command and the current time is greater than the time installed on alarm, the buzzer must be signaled to the user. The sound should be turned off when the user presses the II button. After executing this command, if the user did not reset the alarm, the buzzer should not sound anymore.

`double setStopWatch()`

Sets the timer that counts time while the user does not press the II button. Returns the number of corresponding minutes. Except for this, the timer pointer must be turned counterclockwise by the corresponding value. For example, if the timer was set for 1 hour, a full turn of the pointer should be made after 60 minutes. It should be noted that after the completion of the timer command, the pointer of the minutes must stand still 1 minute, and then it return back pointing where it did until this command.

`double setStopWatchByHand()`
It is similar to the previous command that the program starts counting time when the user clicks on the I button,  and after the user presses the II button, it rotates the minute hand and returns the corresponding value

## Components' Functions
#### Servo motor:

➢ This motor must control the hours hand.

➢ The number of hours is 12.

➢ Servo 0 degrees means 0 hours, 180 degrees means 12 hours.

➢ You can use the servo's pointer for the hours hand.

#### Stepper motor:
➢ This motor must control the minutes hand in a range of 0-60.

➢ When turned on, the stepper motor is at 0 minutes.

➢ You can use it for any minute position.

#### Buzzer:

➢ Used for a metronome, timer, and other functions.

#### Buttons:

➢ The number of buttons is 2.

➢ Button I is used to set the time manually in hand mode.

➢ Button II is used to set the fixed time in hand mode and to activate the buzzer

#### RGB led:

➢ The function of flashing is to be recognized by the user in the commands of type ByHand() related to input.

➢ In the event that the setTimerByHand() command is executed, the color red must be displayed.

➢ In the event that the setAlarmByHand() command is executed, the color green must be displayed.

➢ In the event that the setStopWatchByHand() command is executed, the color blue must be displayed.


