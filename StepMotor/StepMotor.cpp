#include "StepMotor.h"

//Serial pc(USBTX, USBRX);
StepMotor::StepMotor(PinName stepPin, PinName dirPin, PinName endStopLeftPin, PinName endStopRightPin, float stepPeriod) :
                         _step(stepPin), _dir(dirPin), _endStopLeft(endStopLeftPin), _endStopRight(endStopRightPin), _stepPeriod(stepPeriod) {
    _endStopLeft.mode(PullUp);
    _endStopRight.mode(PullUp);
    _step = 0;
}

void StepMotor::setStepGoal(int numStep, int direction) {
    _currentStep = numStep * 2;
    _dir = direction;
    
   // pc.printf("attach()\n");
    t.attach(this, &StepMotor::doStep, _stepPeriod);
}

void StepMotor::doStep() {
    //pc.printf("flip()\n");
    if(_currentStep <= 0 /*|| _endStopLeft || _endStopRight*/) {
        _step = 0;
        _currentStep = 0;
        t.detach();
        return;
    }
    _currentStep--;
    _step = !_step;
}

bool StepMotor::isMoveCompleted() {
    if(_currentStep <= 0) {
        return true;
    }
    return false;
}
