#ifndef CAPTEUR_JDWY
#define CAPTEUR_JDWY

typedef float(*FonctionDeSortie)(int);

typedef struct {
  short pin;
   FonctionDeSortie fonctiondesortie;
}Capteur;

void capteur_setup(Capteur& capteur, short pin, FonctionDeSortie fds);

float capteur_get_data(Capteur& capteur);

#endif

