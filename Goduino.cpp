/*
  File: Goduino.cpp - Library for controlling the GOduino III robot controller.
  Created by: Hazim Bitar (techbitar at gmail dot com)
  Date: August 20, 20012.
  Version: 0.1 beta
  License: Released into the public domain.
*/

#include "Arduino.h"
#include "Goduino.h"

// map motor poles to Arduino pins
#define motor1pole1 4  
#define motor1pole2 2
#define motor2pole1 7
#define motor2pole2 8

// map L293d motor enable pins to Arduino pins
#define enablePin1 5
#define enablePin2 6

#define M1_MAX_SPEED 1023
#define M2_MAX_SPEED 1023

#define motordelay 30
#define debugmotorsec 3000

Goduino::Goduino()
{
  // set mapped motor poles (L293D) to Arduino pins 
  pinMode(enablePin1, OUTPUT);
  pinMode(enablePin2, OUTPUT);

  pinMode( motor1pole1 , OUTPUT);
  pinMode( motor1pole2, OUTPUT);
  pinMode( motor2pole1, OUTPUT);
  pinMode( motor2pole2 , OUTPUT);

}

void Goduino::motorstop(uint8_t motornum){
  delay(motordelay);
  if (motornum == 1) {
    digitalWrite(motor1pole1, LOW);
    digitalWrite(motor1pole2, LOW);
  }
  else if (motornum == 2) {

    digitalWrite(motor2pole1, LOW);
    digitalWrite(motor2pole2, LOW);
  }
  delay(motordelay);
}

void Goduino::motorforward(uint8_t motornum){
  if (motornum == 1) {
    digitalWrite(motor1pole1, HIGH);
    digitalWrite(motor1pole2, LOW);
  }
  else if (motornum == 2) {

    digitalWrite(motor2pole1, LOW);
    digitalWrite(motor2pole2, HIGH);
  }
  delay(motordelay);
}

void Goduino::motorback(uint8_t motornum){
  if (motornum == 1) {
    digitalWrite(motor1pole1, LOW);
    digitalWrite(motor1pole2, HIGH);
  }  
  else if (motornum == 2) {
    digitalWrite(motor2pole1, HIGH);
    digitalWrite(motor2pole2, LOW);
  }
  delay(motordelay);
}

void Goduino::motorspeed(uint16_t motor1speed, uint16_t motor2speed) {
  if (motor1speed > M1_MAX_SPEED ) motor1speed = M1_MAX_SPEED; // limit top speed
  if (motor2speed > M2_MAX_SPEED ) motor2speed = M2_MAX_SPEED; // limit top speed
  if (motor1speed < 0) motor1speed = 0; // keep motor above 0
  if (motor2speed < 0) motor2speed = 0; // keep motor speed above 0
  analogWrite(enablePin1, motor1speed);
  analogWrite(enablePin2, motor2speed);
}




