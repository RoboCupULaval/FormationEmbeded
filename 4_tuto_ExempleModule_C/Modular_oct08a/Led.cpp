#include "Led.h"

LedHandler Led_init(int pin)
{
  pinMode(pin, OUTPUT);
  digitalWrite(pin, LOW);
  return LedHandler {.pin=pin, .currentState=LOW};
}
void Led_toggle(LedHandler * led)
{
  led->currentState = !led->currentState;     //at this point, we invert the state of the handler's currentState
  digitalWrite(led->pin, led->currentState);  //simply write de new value
}

