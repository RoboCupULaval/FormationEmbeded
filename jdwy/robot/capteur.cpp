#include "capteur.h"
#include <Arduino.h>

void capteur_setup(Capteur& capteur, short pin, int angleDeSortieSurBlanc, int angleDeSortieSurNoir, int treshold)
{
  capteur.pin = pin;
  capteur.angleDeSortieSurBlanc = angleDeSortieSurBlanc;
  capteur.angleDeSortieSurNoir = angleDeSortieSurNoir;
  capteur.treshold = treshold;
}

int capteur_get_angle(Capteur& capteur)
{
  int rawdata = analogRead(capteur.pin);
  if (rawdata > capteur.treshold)
  {
    return capteur.angleDeSortieSurNoir;
  }
  return capteur.angleDeSortieSurBlanc;
}


