#include <Arduino.h>
#include "L293D.h"


  
L293D::L293D(int enablePin, int firstPin) {
  this->EnablePin = enablePin;
  this->FirstPin = firstPin;
  this->SecondPin = firstPin;

  pinMode(this->EnablePin, OUTPUT);
  pinMode(this->FirstPin, OUTPUT);
}

L293D::L293D(int enablePin, int firstPin, int secondPin) {
  this->EnablePin = enablePin;
  this->FirstPin = firstPin;
  this->SecondPin = secondPin; 

  pinMode(this->EnablePin, OUTPUT);
  pinMode(this->FirstPin, OUTPUT);
  pinMode(this->SecondPin, OUTPUT); 
}

int L293D::GetSpeed() {
  return this->Speed;
}

void L293D::SetSpeed(int Speed) {
  this->Speed = Speed;
}

void L293D::Stop() {
  SetSpeed(0);
  analogWrite(EnablePin, GetSpeed());
}

void L293D::Forward() {
  digitalWrite(FirstPin, HIGH); /* Change direction of the motor */
  if (FirstPin != SecondPin)
    digitalWrite(SecondPin, LOW);
  analogWrite(EnablePin, GetSpeed());     /* Change the speed */
}


void L293D::Reverse() {
  digitalWrite(FirstPin, LOW);  /* Change direction of the motor */
  if (FirstPin != SecondPin)
    digitalWrite(SecondPin, HIGH);
  analogWrite(EnablePin, GetSpeed());     /* Change the speed */
}
