#ifndef CAPTEUR_JDWY
#define CAPTEUR_JDWY

typedef void(*OnDetectionCallBack)(void);

typedef struct {
  short pin;
  int treshold; 
  int angleDeSortieSurBlanc;
  int angleDeSortieSurNoir;
  OnDetectionCallBack onDetectionCallBack;
}Capteur;

void capteur_setup(Capteur& capteur, short pin, int angleDeSortieSurBlanc, int angleDeSortieSurNoir, int treshold, OnDetectionCallBack onDetectionCallBack);

int capteur_get_angle(Capteur& capteur);

#endif

