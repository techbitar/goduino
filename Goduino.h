/*
  File: Goduino.h - Library for controlling the GOduino III robot controller.
  Created by: Hazim Bitar (techbitar at gmail dot com)
  Date: August 20, 20012.
  Version: 0.1 beta
  License: Released into the public domain.
*/
#ifndef Goduino_h
#define Goduino_h

#include "Arduino.h"

class Goduino
{
public:
  Goduino();
  void motorstop(uint8_t motornum);
  void motorforward(uint8_t motornum);
  void motorback(uint8_t motornum);
  void motorspeed(uint16_t motor1speed, uint16_t motor2speed);
private:
};

#endif



