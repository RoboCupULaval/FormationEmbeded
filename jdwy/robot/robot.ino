#include "onOffBouton.h"
#include "dc.h"

OnOffBouton monBouton;
MoteurDc moteurDC;

void setup() {
  Serial.begin(9600); 
  
  on_off_button_setup(monBouton, 2);
  monBouton.callBackOff = maFonctionOff;
  monBouton.callBackOn = maFonctionOn;

  moteur_dc_setup(moteurDC, 5, 3, true);
  
}

void loop() {
  on_off_button_handleInput(monBouton);
  moteur_dc_loop(moteurDC);
}


void maFonctionOn(void)
{
  Serial.println("En marche!");
  moteur_dc_accelerate(moteurDC, 100);
  delay(100);
  moteur_dc_accelerate(moteurDC, 100);
  delay(100);
  moteur_dc_accelerate(moteurDC, 100);
  
}

void maFonctionOff(void)
{
  Serial.println("Stop!");
  moteur_dc_decelerate(moteurDC, 100);
  delay(100);
  moteur_dc_decelerate(moteurDC, 100);
  delay(100);
  moteur_dc_decelerate(moteurDC, 100);
}

