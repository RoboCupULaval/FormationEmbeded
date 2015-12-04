#ifndef SCREEN_I2C_JDWY
#define SCREEN_I2C_JDWY

#include <Arduino.h>
#include "Wire.h"
#include <LiquidCrystal_I2C.h>


class I2c : LiquidCrystal_I2C{

  public:
    I2c(int addr, int en, int rw, int rs, int d4, int d5, int d6, int d7, int bl, t_backlighPol blpol);
  
    void setup();

    void ecrireMessage(String message);
  
};

#endif
