#include "MotorClock.h"
#include <Servo.h>
#include <Stepper.h>

MotorClock::MotorClock(int hour, int minutes, uint8_t servoP, uint8_t stepperN1P, uint8_t stepperN2P, uint8_t stepperN3P, uint8_t stepperN4P, uint8_t buzzerP, uint8_t button1P, uint8_t button2P, uint8_t rgbRP, uint8_t rgbGP, uint8_t rgbBP) {
    buzzer = buzzerP;
    buttonI = button1P;
    buttonII = button2P;
    servo.attach(servoP);
    stepper1 = stepperN1P;
    stepper2 = stepperN2P;
    stepper3 = stepperN3P;
    stepper4 = stepperN4P;
    Stepper stepper(2038, stepper1, stepper3, stepper2, stepper4);
    alarmHour = 0;
    alarmMinutes = 0;
    hours = hour;
    minute = minutes;
    currentMinute = minutes;
    currentHour = hour;
    redPin = rgbRP;
    bluePin = rgbBP;
    greenPin = rgbGP;
    pinMode(redPin, OUTPUT);
    pinMode(greenPin, OUTPUT);
    pinMode(bluePin, OUTPUT);
}

void MotorClock::setCurrentTime() {
    int passedMinutes = millis() / 60000;
    currentHour = hours;
    currentMinute = minute;
    int minutesNashti = passedMinutes % 60;
    int minutesGanayofi = passedMinutes / 60;
    currentHour += minutesGanayofi;
    currentMinute += minutesNashti;
    if (currentMinute > 60) {
        currentMinute -= 60;
        currentHour = currentHour % 12;
    }
}

String MotorClock::showTime() {
    Stepper stepper(2038, stepper1, stepper3, stepper2, stepper4);
    MotorClock::setCurrentTime();
    servo.write(map(0, 12, 0, 180, currentHour));
    stepper.setSpeed(10);
    stepper.step(currentMinute / 0.177);
}

void MotorClock::setTimer(double seconds) {
    delay(60000 * seconds);
    tone(buzzer, 1000);
    while (true) {
        int buttonState = digitalRead(buttonII);
        if (buttonState == HIGH) {
            noTone(buzzer);
            break;
        }
    }
}

void MotorClock::setTimerByHand() {
    MotorClock::setColor(255, 0, 0);
    int minutes = setTimeOnAlarm();
    setTimer(minutes);
    MotorClock::setColor(0, 0, 0);
}

void MotorClock::setAlarm(int hour, int minutes) {
    alarmHour = hour % 12;
    alarmMinutes = minutes % 60;
}

void MotorClock::setAlarmByHand() {
    MotorClock::setColor(0, 255, 0);
    int hours = setTimeOnAlarm();
    int minutes = setTimeOnAlarm();
    MotorClock::setAlarm(hours, minutes);
    MotorClock::setColor(0, 0, 0);
}
int MotorClock::setTimeOnAlarm() {
  int hourCount = 0;
    while (true) {
        delay(1000);
        int state = digitalRead(buttonI);
        if (state == HIGH) {
            hourCount++;
        }
        int state2 = digitalRead(buttonII);
        if (state2 == HIGH) {
            return hourCount;
        }
    }
}

void MotorClock::checkAlarm() {
    if (alarmHour == 0 && alarmMinutes == 0) {
        return;
    }
    MotorClock::setCurrentTime();
    if ((currentHour > alarmHour) || (currentHour == alarmHour && currentMinute > alarmMinutes)) {
        tone(buzzer, 1000);
        while (true) {
            int buttonState = digitalRead(buttonII);
            if (buttonState == HIGH) {
                noTone(buzzer);
                alarmMinutes = 0;
                alarmHour = 0;
                break;
            }
        }
    }
}

double MotorClock::setStopwatch() {
    unsigned long int curr = millis();
    while (true) {
        int readState = digitalRead(buttonII);
        if (readState == HIGH) {
            unsigned long int passedTime = millis()-curr;
            int passedTimeInMinutes = passedTime / 60000.0;
            Stepper stepper(2038, stepper1, stepper3, stepper2, stepper4);
            stepper.setSpeed(15);
            stepper.step(passedTimeInMinutes / 0.177);
            delay(1000);
            stepper.step(-passedTimeInMinutes / 0.117);
            return passedTimeInMinutes;
        }
    }
}

double MotorClock::setStopwatchByHand() {
  MotorClock::setColor(0, 0, 255);
    while (true) {
        int state = digitalRead(buttonI);
        if (state == HIGH) {  
            double a = MotorClock::setStopwatch();
            MotorClock::setColor(0, 0,0);
            return a;
        }
    }
}

void MotorClock::setColor(int redValue, int greenValue, int blueValue) {
    analogWrite(redPin, redValue);
    analogWrite(greenPin, greenValue);
    analogWrite(bluePin, blueValue);
}
