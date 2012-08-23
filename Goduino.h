/*
  File: Goduino.h - Library for controlling the GOduino III robot controller.
  Created by: Hazim Bitar (techbitar at gmail dot com)
  Date: August 23, 20012.
  Version: 0.11 beta
  License: Released into the public domain.
*/
#ifndef Goduino_h
#define Goduino_h

#include "Arduino.h"

class Goduino
{
public:
  Goduino();
  void motorStop(uint8_t motorNum);
  void motorForward(uint8_t motorNum);
  void motorBack(uint8_t motorNum);
  void motorSpeed(uint16_t mot1speed, uint16_t mot2speed);
private:
};

#endif



