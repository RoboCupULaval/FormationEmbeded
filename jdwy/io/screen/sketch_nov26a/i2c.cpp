#include "i2c.h"


I2c::I2c(int addr, int en, int rw, int rs, int d4, int d5, int d6, int d7, int bl, t_backlighPol blpol) :
  LiquidCrystal_I2C(addr, en, rw, rs, d4, d5, d6, d7, bl, blpol)
{}

void I2c::setup() {
  begin(16, 2);

   // ------- Quick 3 blinks of backlight  -------------
  for (int i = 0; i < 3; i++)
  {
    backlight();
    delay(250);
    noBacklight();
    delay(250);
  }
  backlight();
}

void I2c::ecrireMessage(String message) {
  clear();
  setCursor(0, 0);
  print(message);
}

