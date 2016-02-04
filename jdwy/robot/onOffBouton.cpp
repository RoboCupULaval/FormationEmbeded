#include "onOffBouton.h"

void on_off_button_setup(OnOffBouton& bouton, int pin)
{
  bouton.isOn = false;
  bouton.pin = pin;

  pinMode(bouton.pin, INPUT);

  bouton.lastInput = 0;
}

void on_off_button_handleInput(OnOffBouton& bouton)
{
  if (digitalRead(bouton.pin) == LOW)
  {
    unsigned long newEntry = millis();
    
    if(bouton.lastInput + 1000 < newEntry)
    {
      bouton.lastInput = newEntry;
      bouton.isOn = !bouton.isOn;
      if(bouton.isOn) {
        (*bouton.callBackOn)();
      }
      else {
        (*bouton.callBackOff)();
      }
    }
  }
}

