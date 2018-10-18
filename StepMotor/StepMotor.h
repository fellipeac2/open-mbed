#ifndef STEP_MOTOR_H
#define STEP_MOTOR_H
#include "mbed.h"
 
// A class for flip()-ing a DigitalOut 
class StepMotor {
public:
    StepMotor(PinName stepPin, PinName dirPin, PinName endStopLeftPin, PinName endStopRightPin, float stepPeriod);
    void setStepGoal(int numStep, int direction);
    void doStep();
    bool isMoveCompleted();
private:
    DigitalOut  _step;
    DigitalOut  _dir;
    DigitalIn   _endStopLeft;
    DigitalIn   _endStopRight;
    Ticker t;
    float       _stepPeriod;
    int         _currentStep;
};

#endif