#include "onOffBouton.h"

void on_off_button_setup(OnOffBouton& bouton, int pin)
{
  bouton.isOn = false;
  bouton.pin = pin;

  pinMode(bouton.pin, INPUT);
}

void on_off_button_handleInput(OnOffBouton& bouton)
{
  if (digitalRead(bouton.pin) == LOW)
  {
    bouton.isOn = !bouton.isOn;
    if(bouton.isOn) {
      (*bouton.callBackOn)();
    }
    else {
      (*bouton.callBackOff)();
    }
  }
}

