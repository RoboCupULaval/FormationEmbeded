#ifndef CAPTEUR_JDWY
#define CAPTEUR_JDWY

typedef struct {
  short pin;
  int treshold; 
  int angleDeSortieSurBlanc;
  int angleDeSortieSurNoir;
}Capteur;

void capteur_setup(Capteur& capteur, short pin, int angleDeSortieSurBlanc, int angleDeSortieSurNoir, int treshold);

int capteur_get_angle(Capteur& capteur);

#endif

