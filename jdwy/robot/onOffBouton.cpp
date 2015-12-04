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
    Serial.println("button pushed");
    bouton.isOn = !bouton.isOn;
    if(bouton.isOn) {
      Serial.println("is on");
      (*bouton.callBackOn)();
    }
    else {
      Serial.println("is on");
      (*bouton.callBackOff)();
    }
  }
  else
  {
    Serial.println("button up");
  }
}

