#ifndef MOTEUR_DC_JDWY
#define MOTEUR_DC_JDWY

typedef struct MoteurDc MoteurDc;
struct MoteurDc {
  short pwm_pin;
  short dir_pin;
  bool currentDirection;
  unsigned int currentSpeed;
};

const int moteur_dc_max_speed = 1000;
const int moteur_dc_min_speed = 0;

void moteur_dc_setup(MoteurDc& moteur, short pwm_pin, short dir_pin, bool dir);

void moteur_dc_accelerate(MoteurDc& moteur, unsigned int factor = 100);

void moteur_dc_decelerate(MoteurDc& moteur, unsigned int factor = 100);

void moteur_dc_stop(MoteurDc& moteur);

void moteur_dc_switch_direction(MoteurDc& moteur);

void moteur_dc_loop(MoteurDc& moteur);


#endif
