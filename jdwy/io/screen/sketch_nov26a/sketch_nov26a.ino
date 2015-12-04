#include "i2c.h"
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

I2c i2c(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

void setup()
{
  Serial.begin(9600);
  i2c.setup();
}

void loop()
{
  i2c.ecrireMessage("lol");

}

