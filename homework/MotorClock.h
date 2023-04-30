#ifndef MotorClock_h
#define MotorClock_h

#include <Arduino.h>
#include <Servo.h>
#include <Stepper.h>

class MotorClock {
  public:
    MotorClock(int hour, int minutes, uint8_t servoP, uint8_t stepperN1P, uint8_t
stepperN2P, uint8_t stepperN3P, uint8_t stepperN4P, uint8_t buzzerP, uint8_t
button1P, uint8_t button2P,uint8_t rgbRP, uint8_t rgbGP, uint8_t rgbBP);
    String showTime();
    void setTimer(double minutes);
    void setTimerByHand();
    void setAlarmByHand();
    void setAlarm(int hour,int minutes);
    int setTimeOnAlarm();
    void checkAlarm();
    void setCurrentTime();
    double setStopwatch();
    double setStopwatchByHand();
    void setColor(int redValue, int greenValue, int blueValue);
  
  private:
   int hours;
   int minute;
   int buzzer;
   int buttonI;
   int buttonII;
   int count;
   int stepper1;
   int stepper2;
   int stepper3;
   int stepper4;
   int currentHour;
   int currentMinute;
   int alarmHour;
   int alarmMinutes;
    int redPin;
    int bluePin;
    int greenPin;
   Servo servo;
   
};

#endif
