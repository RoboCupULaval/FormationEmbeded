#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>

#include "onOffBouton.h"
#include "dc.h"
#include "i2c.h"
#include "capteur.h"


I2c i2c(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

OnOffBouton monBouton;
MoteurDc moteurDC;
Servo myservo;
Capteur cGauche, cDroit;

void setup() {
  Serial.begin(9600); 
  
  on_off_button_setup(monBouton, 2);
  monBouton.callBackOff = maFonctionOff;
  monBouton.callBackOn = maFonctionOn;

  moteur_dc_setup(moteurDC, 3, 4, false);
  myservo.attach(9);

  capteur_setup(cGauche, A2, 45,0,500);
  capteur_setup(cDroit, A1, 45,90,500);

  i2c.setup();
}

void loop() {
  on_off_button_handleInput(monBouton);
  moteur_dc_loop(moteurDC);
  myservo.write(capteur_get_angle(cGauche) + capteur_get_angle(cDroit));
 Serial.println (analogRead(cGauche.pin));
 Serial.println (analogRead(cDroit.pin));
 Serial.println ("");
  
}


void maFonctionOn(void)
{
  Serial.println("En marche!");
  i2c.ecrireMessage("En marche!");
  moteur_dc_accelerate(moteurDC, 200);
  delay(100);
  moteur_dc_accelerate(moteurDC, 200);
  delay(100);
  moteur_dc_accelerate(moteurDC, 200);
}

void maFonctionOff(void)
{
  Serial.println("Stop!");
  i2c.ecrireMessage("Stop!");
  moteur_dc_decelerate(moteurDC, 200);
  delay(100);
  moteur_dc_decelerate(moteurDC, 200);
  delay(100);
  moteur_dc_decelerate(moteurDC, 200);
}



