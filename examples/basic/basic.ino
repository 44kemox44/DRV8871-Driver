#include <drv8871.h>

// Define motor pins
#define MOTOR1_IN1 10
#define MOTOR1_IN2 11
#define MOTOR2_IN1 8
#define MOTOR2_IN2 9
#define MOTOR3_IN1 12
#define MOTOR3_IN2 13
#define MOTOR4_IN1 6
#define MOTOR4_IN2 7

// Create an instance of the DRV8871 class
DRV8871 motorController(MOTOR1_IN1, MOTOR1_IN2, MOTOR2_IN1, MOTOR2_IN2, MOTOR3_IN1, MOTOR3_IN2, MOTOR4_IN1, MOTOR4_IN2);

void setup() {
  // Initialize Serial communication
  Serial.begin(9600);
}

void loop() {
  // Move forward at speed 50 for 2 seconds
  motorController.forward(50);
  delay(2000);

  // Stop for 1 second
  motorController.stop();
  delay(1000);

  // Move backward at speed 20 for 2 seconds
  motorController.backward(20);
  delay(2000);

  // Stop for 1 second
  motorController.stop();
  delay(1000);
}
