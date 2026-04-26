#include "ValuePhysics.h"
#include "iostream"

using namespace std;

ValuePhysics::ValuePhysics(float *valptr, float targetval) {
  this->valuePtr = valptr;
  this->targetValue = targetval;
  this->friction = 0.8f;
  this->startVal = 0;
  this->overshooting = 0;
  this->privateFriction = 0.8f;
  this->speed = 0;
  this->speedCeil = 999999;
  this->speedFloor = -999999;
  this->outElasticRatio = 0;
}

void ValuePhysics::Update(float deltaTime) {
  float valueDelta = targetValue - *valuePtr;
  // if ((speed > 0 && valueDelta > 0) || (speed <= 0 && valueDelta <= 0)) {
  if (outElasticRatio == 0)
    speed += valueDelta * changeSpeedRatio * deltaTime * privateFriction;
  else
    speed = valueDelta / outElasticRatio;
  if (valueDelta < 0.5f) {
    speed = 0;
    *valuePtr = targetValue;
    privateFriction = friction;
  }
  //}

  if (speed > speedCeil) {
    speed = speedCeil;
  }
  if (speed < speedFloor) {
    speed = speedFloor;
  }
  float prevValue = *valuePtr;
  *valuePtr += deltaTime * speed;
  valueDelta = targetValue - *valuePtr;
  if ((*valuePtr > targetValue && prevValue < targetValue) ||
      (*valuePtr < targetValue && prevValue > targetValue)) {
    startVal = *valuePtr;
    if (overshooting != 0)
      privateFriction /= overshooting;
    else
      privateFriction = 1000000;
    float tmp =
        valueDelta * changeSpeedRatio * deltaTime * privateFriction * deltaTime;
    if ((tmp > valueDelta && valueDelta > 0) ||
        (tmp < valueDelta && valueDelta <= 0)) {
      *valuePtr = targetValue;
      speed = 0;
      privateFriction = friction;
    }
  }
}
