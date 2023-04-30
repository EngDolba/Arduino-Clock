#include "MotorClock.h"
const int hours = 15;
const int minutes = 37;
const int servoP = 3;
const int stepperN1P = 8;
const int stepperN2P = 9;
const int stepperN3P = 10;
const int stepperN4P = 11;
const int buzzer = 6;
const int buttonI = 4;
const int buttonII = 2;
const int rgbRP = 12;
const int rgbGP = 13;
const int rgbBP = 5;

void setup(){
  MotorClock* MC  = new MotorClock(hours,minutes,servoP,stepperN1P,stepperN2P,stepperN3P,stepperN4P,buzzer,buttonI,buttonII,rgbRP,rgbGP,rgbBP);
  Serial.begin(9600);
  
}

void loop() {
 
}


