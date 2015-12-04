#include "onOffBouton.h"

OnOffBouton monBouton;

void setup() {
  Serial.begin(9600); 
  on_off_button_setup(monBouton, 2);
  monBouton.callBackOff = maFonctionOff;
  monBouton.callBackOn = maFonctionOn;
}

void loop() {
  on_off_button_handleInput(monBouton);
}


void maFonctionOn(void)
{
  Serial.println("des chose on");
  
}

void maFonctionOff(void)
{
  Serial.println("des choses off");
}

