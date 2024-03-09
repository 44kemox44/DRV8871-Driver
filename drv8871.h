#ifndef DRV8871_H
#define DRV8871_H

#include <Arduino.h>

class DRV8871 {
  private:
    int motor1In1;
    int motor1In2;
    int motor2In1;
    int motor2In2;
    int motor3In1;
    int motor3In2;
    int motor4In1;
    int motor4In2;

  public:
    DRV8871(int in1, int in2, int in3, int in4, int in5, int in6, int in7, int in8);
    void forwardRampUp();
    void forward(int speed);
    void backward(int speed);
    void forwardRight(int speed);
    void forwardLeft(int speed);
    void backwardRight(int speed);
    void backwardLeft(int speed);
    void stop(bool motor1 = true, bool motor2 = true, bool motor3 = true, bool motor4 = true);
};

#endif
