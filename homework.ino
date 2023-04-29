


const int buzzer = 6; //buzzer to arduino pin 9
const int buttonII = 2;
const int buttonI = 4;

#include "MotorClock.h"
int count = 0;
void setup(){
  MotorClock* MC  = new MotorClock(1,2,3,8,9,10,11,6,4,2,12,3,5);
  Serial.begin(9600);
}

void loop(){

}


}