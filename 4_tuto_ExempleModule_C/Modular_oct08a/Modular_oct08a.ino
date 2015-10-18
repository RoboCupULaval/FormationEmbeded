/*
 * When you code with non OO langages (Like C which is popular in MCU) you can use the following method to mimic Objects. This exemple is only a simplification of the idea, it can be improved to be suitable
 * for large scale projects.
 */

 #include "Led.h"

 LedHandler g_led1;
 LedHandler g_led2;

void setup() {
  // put your setup code here, to run once:
  g_led1 = Led_init(5); //Initialise handlers : in a more complexe case with an object containing many states and initialisations
  g_led2 = Led_init(4);
}

void loop() {
  // put your main code here, to run repeatedly:
  Led_toggle(&g_led1);
  Led_toggle(&g_led2);
  delay(500);
}
