#include <Stepper.h>

const int stepsPerRevolution = 4096;  // Half-step: 4096 bước cho 1 vòng

// Chân kết nối tới driver ULN2003
const int in1 = 8;
const int in2 = 9;
const int in3 = 10;
const int in4 = 11;

// Khởi tạo động cơ bước
Stepper myStepper(stepsPerRevolution, in1, in3, in2, in4);  // Thứ tự chân đặc biệt quan trọng

void setup() {
  myStepper.setSpeed(5);  // Tốc độ: 10 vòng/phút
}

void loop() {
  myStepper.step(stepsPerRevolution);  // Quay đúng 1 vòng (360°)
  //delay(2000);  // Dừng 2 giây
}
