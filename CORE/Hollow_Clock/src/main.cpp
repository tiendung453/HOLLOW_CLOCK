#include <Arduino.h>
#include <Stepper.h>

const int stepsPerRevolution = 2048;  // Half-step: 2048 bước cho 1 vòng

// Chân kết nối tới driver ULN2003
const int in1 = 8;
const int in2 = 9;
const int in3 = 10;
const int in4 = 11;
bool stt = false;

// Khởi tạo động cơ bước
Stepper myStepper(stepsPerRevolution, in1, in2, in3, in4);
void check_ble();
void setup() {
  myStepper.setSpeed(5);
  Serial.begin(9600);
  //Serial.println("hi");
  //myStepper.Update_time(1,5);
  //yStepper.step(15360);
}

void loop() 
{
  check_ble();
  if(stt) 
  {
    myStepper.setSpeed(0.125);
    myStepper.step(256);
  }
}

void check_ble()
{
  if (Serial.available()) 
  {
    String timeData = Serial.readStringUntil('\n');
    int hour = timeData.substring(0, timeData.indexOf('/')).toInt();
    int minute = timeData.substring(timeData.indexOf('/') + 1).toInt();
    myStepper.Update_time(hour, minute); 
    stt = true;
  }
}
