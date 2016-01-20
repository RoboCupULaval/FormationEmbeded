#include "capteur.h"
#include <Arduino.h>

void capteur_setup(Capteur& capteur, short pin, FonctionDeSortie fds)
{
  capteur.pin = pin;
  capteur.fonctiondesortie = fds;
}

float capteur_get_data(Capteur& capteur)
{
  int rawdata = analogRead(capteur.pin);
  return (*capteur.fonctiondesortie)(rawdata);
}
