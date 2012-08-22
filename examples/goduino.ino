/*
 File: goduino.ino - example sketch to test the GOduino III robot controller.
 Created by: Hazim Bitar (techbitar at gmail dot com)
 Date: August 20, 20012.
 Version: 0.1 beta
 License: Released into the public domain.
 */

#include <Goduino.h>

Goduino myrobot;

void setup() {
  Serial.begin(9600);

  Serial.println("Set speed of both motors to 100 (max 1024)");
  myrobot.motorspeed(50,50);

}

void loop() {

  Serial.println("TEST PHASE I - SPIN BOTH MOTORS TOGETHER IN SAME DIRECTION");
  delay(3000);

  Serial.println("Spin both motors in one direction (3 sec)");
  myrobot.motorforward(1);
  myrobot.motorforward(2);
  delay(3000);

  Serial.println("Stop both motors for 1 sec");
  myrobot.motorstop(1);
  myrobot.motorstop(2);
  delay(1000);

  Serial.println("Spin both motors in opposite direction (3 sec)");
  myrobot.motorback(1);	
  myrobot.motorback(2);	
  delay(3000);

  Serial.println("Stop both motors for 1 sec");
  myrobot.motorstop(1);
  myrobot.motorstop(2);
  delay(1000);

  //=================================================================================

  Serial.println("TEST PHASE II - SPIN EACH MOTOR OPPOSTE OF THE OTHER");
  delay(3000);

  Serial.println("Spin  motor 1 in one direction while motor 2 in opposite direction (3 sec)");
  myrobot.motorforward(1);
  myrobot.motorback(2);
  delay(3000);

  Serial.println("Stop both motors for 1 sec");
  myrobot.motorstop(1);
  myrobot.motorstop(2);
  delay(1000);

  Serial.println("Spin  motor 2 in one direction while motor 1 in opposite direction (3 sec)");
  myrobot.motorback(1);	
  myrobot.motorforward(2);	
  delay(3000);

  Serial.println("Stop both motors for 1 sec");
  myrobot.motorstop(1);
  myrobot.motorstop(2);
  delay(1000);

  //=================================================================================

  Serial.println("TEST PHASE III - SPIN EACH WHEELS WHILE THE OTHER IS STOPPED");
  delay(3000);

  Serial.println("Spin motor 1 in one direction while motor 2 is stopped (3 sec)");
  myrobot.motorforward(1);
  myrobot.motorstop(2);
  delay(3000);

  Serial.println("Stop both motors for 1 sec");
  myrobot.motorstop(1);
  myrobot.motorstop(2);
  delay(1000);

  Serial.println("Spin motor 2 in one direction while motor 1 is stopped (3 sec)");
  myrobot.motorforward(2);
  myrobot.motorstop(1);
  delay(3000);
  
  Serial.println("Stop both motors for 1 sec");
  myrobot.motorstop(1);
  myrobot.motorstop(2);
  delay(1000);

  Serial.println("Spin motor 1 in reverse direction while motor 2 is stopped (3 sec)");
  myrobot.motorback(1);
  myrobot.motorstop(2);
  delay(3000);

  Serial.println("Stop both motors for 1 sec");
  myrobot.motorstop(1);
  myrobot.motorstop(2);
  delay(1000);

  Serial.println("Spin motor 2 in reverse direction while motor 1 is stopped (3 sec)");
  myrobot.motorback(2);
  myrobot.motorstop(1);
  delay(3000);

  Serial.println("Stop both motors for 1 sec");
  myrobot.motorstop(1);
  myrobot.motorstop(2);
  delay(1000);

}












