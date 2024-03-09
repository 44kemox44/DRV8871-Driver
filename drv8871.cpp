#include "DRV8871.h"

DRV8871::DRV8871(int in1, int in2, int in3, int in4, int in5, int in6, int in7, int in8) {
  motor1In1 = in1;
  motor1In2 = in2;
  motor2In1 = in3;
  motor2In2 = in4;
  motor3In1 = in5;
  motor3In2 = in6;
  motor4In1 = in7;
  motor4In2 = in8;

  pinMode(motor1In1, OUTPUT);
  pinMode(motor1In2, OUTPUT);
  pinMode(motor2In1, OUTPUT);
  pinMode(motor2In2, OUTPUT);
  pinMode(motor3In1, OUTPUT);
  pinMode(motor3In2, OUTPUT);
  pinMode(motor4In1, OUTPUT);
  pinMode(motor4In2, OUTPUT);
}

void DRV8871::forwardRampUp() {
  digitalWrite(motor1In1, LOW);
  digitalWrite(motor2In1, LOW);
  digitalWrite(motor3In1, LOW);
  digitalWrite(motor4In1, LOW);

  for (int i = 0; i < 100; i++) {
    analogWrite(motor1In2, i);
    analogWrite(motor2In2, i);
    analogWrite(motor3In2, i);
    analogWrite(motor4In2, i);
    delay(10);
  }
}

void DRV8871::forward(int speed) {
  digitalWrite(motor1In1, LOW);
  digitalWrite(motor2In1, LOW);
  digitalWrite(motor3In1, LOW);
  digitalWrite(motor4In1, LOW);

  analogWrite(motor1In2, speed);
  analogWrite(motor2In2, speed);
  analogWrite(motor3In2, speed);
  analogWrite(motor4In2, speed);
}

void DRV8871::backward(int speed) {
  digitalWrite(motor1In2, LOW);
  digitalWrite(motor2In2, LOW);
  digitalWrite(motor3In2, LOW);
  digitalWrite(motor4In2, LOW);

  analogWrite(motor1In1, 255 - speed);
  analogWrite(motor2In1, 255 - speed);
  analogWrite(motor3In1, 255 - speed);
  analogWrite(motor4In1, 255 - speed);
}

// Implement other methods similarly

void DRV8871::stop(bool motor1, bool motor2, bool motor3, bool motor4) {
  if (motor1) {
    digitalWrite(motor1In1, HIGH);
    analogWrite(motor1In2, 255);
  }

  if (motor2) {
    digitalWrite(motor2In1, HIGH);
    analogWrite(motor2In2, 255);
  }

  if (motor3) {
    digitalWrite(motor3In1, HIGH);
    analogWrite(motor3In2, 255);
  }

  if (motor4) {
    digitalWrite(motor4In1, HIGH);
    analogWrite(motor4In2, 255);
  }
}
