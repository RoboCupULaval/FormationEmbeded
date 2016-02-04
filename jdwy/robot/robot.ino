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

unsigned long lastRecordedDetection;

void setup() {
  Serial.begin(9600); 
  
  on_off_button_setup(monBouton, 2);
  monBouton.callBackOff = maFonctionOff;
  monBouton.callBackOn = maFonctionOn;

  moteur_dc_setup(moteurDC, 3, 4, false);
  myservo.attach(9);

  capteur_setup(cGauche, A1, 45,0,500, maFonctionOnDetection);
  capteur_setup(cDroit, A2, 45,90,500, maFonctionOnDetection);

  i2c.setup();

  lastRecordedDetection = 0;
}

void loop() {
  on_off_button_handleInput(monBouton);
  moteur_dc_loop(moteurDC);
  myservo.write(capteur_get_angle(cGauche) + capteur_get_angle(cDroit));
}

void maFonctionOn(void)
{
  Serial.println("En marche!");
  i2c.ecrireMessage("En marche!");
  moteur_dc_accelerate(moteurDC, 100);
}

void maFonctionOff(void)
{
  Serial.println("Stop!");
  i2c.ecrireMessage("Stop!");
  moteur_dc_stop(moteurDC);
}

void maFonctionOnDetection(void)
{
  /*do stuff usefull... debug... idk*/
}



