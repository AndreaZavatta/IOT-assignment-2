#include <Arduino.h>
#include "Sonar.h"

float Sonar::getDistance()
{
    /* invio impulso */
    digitalWrite(trigPin,LOW);
    delayMicroseconds(3);
    digitalWrite(trigPin,HIGH);
    delayMicroseconds(5);
    digitalWrite(trigPin,LOW);
    
    /* ricevi l’eco */
    long tUS = pulseInLong(echoPin, HIGH);
    //Serial.println(tUS);

    double t = tUS / 1000.0 / 1000.0 / 2;
    double d = t*this->vs;
    return d;
}

Sonar::Sonar(int echoPin, int trigPin)
{
    this->echoPin = echoPin;
    this->trigPin = trigPin;
    pinMode(echoPin, INPUT);
    pinMode(trigPin, OUTPUT);
}