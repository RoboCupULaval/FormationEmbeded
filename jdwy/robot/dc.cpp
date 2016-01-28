#include "dc.h"
#include <Arduino.h>

void moteur_dc_setup(MoteurDc& moteur, short pwm_pin, short dir_pin, bool dir)
{
  moteur.pwm_pin = pwm_pin;
  moteur.dir_pin = dir_pin;
  moteur.currentDirection = dir;
  moteur.currentSpeed = 0;

  pinMode(moteur.dir_pin, OUTPUT);
  analogWrite(moteur.pwm_pin, moteur.currentSpeed);
}

void moteur_dc_accelerate(MoteurDc& moteur, unsigned int factor)
{
  if(moteur.currentSpeed + factor >= moteur_dc_max_speed)
  {
    moteur.currentSpeed = moteur_dc_max_speed;
  }
  else
  {
    moteur.currentSpeed += factor; 
  }
}

void moteur_dc_decelerate(MoteurDc& moteur, unsigned int factor)
{
  if(moteur.currentSpeed - factor <= moteur_dc_min_speed)
  {
    moteur.currentSpeed = moteur_dc_min_speed;
  }
  else
  {
    moteur.currentSpeed -= factor;  
  }
}

void moteur_dc_stop(MoteurDc& moteur)
{
  moteur.currentSpeed = 0;
}

void moteur_dc_switch_direction(MoteurDc& moteur)
{
  moteur.currentDirection = !moteur.currentDirection;
}

void moteur_dc_loop(MoteurDc& moteur)
{
  analogWrite(moteur.pwm_pin, moteur.currentSpeed);
  digitalWrite(moteur.dir_pin, moteur.currentDirection);
}



