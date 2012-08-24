/*
  File: Goduino.cpp - Library for controlling the GOduino III robot controller.
  Created by: Hazim Bitar (techbitar at gmail dot com)
  Date: August 23, 20012.
  Version: 0.12 beta
  License: Released into the public domain.
*/

#include "Arduino.h"
#include "Goduino.h"

// map motor poles to Arduino pins
#define MOT1_POL1 4  
#define MOT1_POL2 2
#define MOT2_POL1 7
#define MOT2_POL2 8

// map L293d motor enable pins to Arduino pins
#define MOT1_ENA 5
#define MOT2_ENA 6

#define MOT1_MAX_SPEED 1023
#define MOT2_MAX_SPEED 1023

#define MOT_DELAY 30
#define DBG_MOT_SPEED 3000

Goduino::Goduino()
{
  // set mapped motor poles (L293D) to Arduino pins 
  pinMode(MOT1_ENA, OUTPUT);
  pinMode(MOT2_ENA, OUTPUT);

  pinMode( MOT1_POL1 , OUTPUT);
  pinMode( MOT1_POL2, OUTPUT);
  pinMode( MOT2_POL1, OUTPUT);
  pinMode( MOT2_POL2 , OUTPUT);

}

void Goduino::motorStop(uint8_t motorNum){
  delay(MOT_DELAY);
  if (motorNum == 1) {
    digitalWrite(MOT1_POL1, LOW);
    digitalWrite(MOT1_POL2, LOW);
  }
  else if (motorNum == 2) {

    digitalWrite(MOT2_POL1, LOW);
    digitalWrite(MOT2_POL2, LOW);
  }
  delay(MOT_DELAY);
}

void Goduino::motorForward(uint8_t motorNum){
  if (motorNum == 1) {
    digitalWrite(MOT1_POL1, HIGH);
    digitalWrite(MOT1_POL2, LOW);
  }
  else if (motorNum == 2) {

    digitalWrite(MOT2_POL1, LOW);
    digitalWrite(MOT2_POL2, HIGH);
  }
  delay(MOT_DELAY);
}

void Goduino::motorBack(uint8_t motorNum){
  if (motorNum == 1) {
    digitalWrite(MOT1_POL1, LOW);
    digitalWrite(MOT1_POL2, HIGH);
  }  
  else if (motorNum == 2) {
    digitalWrite(MOT2_POL1, HIGH);
    digitalWrite(MOT2_POL2, LOW);
  }
  delay(MOT_DELAY);
}

void Goduino::motorSpeed(uint16_t mot1speed, uint16_t mot2speed) {
  if (mot1speed > MOT1_MAX_SPEED ) mot1speed = MOT1_MAX_SPEED; // limit top speed
  if (mot2speed > MOT2_MAX_SPEED ) mot2speed = MOT2_MAX_SPEED; // limit top speed
  if (mot1speed < 0) mot1speed = 0; // keep motor above 0
  if (mot2speed < 0) mot2speed = 0; // keep motor speed above 0
  analogWrite(MOT1_ENA, mot1speed);
  analogWrite(MOT2_ENA, mot2speed);
}




