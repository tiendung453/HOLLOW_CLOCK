#include <Arduino.h>
#include <Stepper.h>

const int stepsPerRevolution = 2048;  // Half-step: 2048 bước cho 1 vòng

// Chân kết nối tới driver ULN2003
const int in1 = 8;
const int in2 = 9;
const int in3 = 10;
const int in4 = 11;

// Khởi tạo động cơ bước
Stepper myStepper(stepsPerRevolution, in1, in2, in3, in4);

void setup() {
  myStepper.setSpeed(1);
  myStepper.Update_time(2,0);
}

void loop() 
{
  //myStepper.Update_time(2,0);
}
