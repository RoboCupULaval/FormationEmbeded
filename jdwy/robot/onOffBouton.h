#ifndef HARDWARE_BOUNCED_ON_OFF_BOUTON_JDWY
#define HARDWARE_BOUNCED_ON_OFF_BOUTON_JDWY

#include <Arduino.h>

typedef void(*BoutonCallBack)(void);

typedef struct OnOffBouton OnOffBouton;

struct OnOffBouton {
  bool isOn;
  int pin;
  BoutonCallBack callBackOn;
  BoutonCallBack callBackOff;
};


void on_off_button_setup(OnOffBouton& bouton, int pin);

void on_off_button_handleInput(OnOffBouton& bouton);

#endif
