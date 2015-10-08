#ifndef _LED_H
#define _LED_H

/*
 * This is the Led header. It is simple but it shows the idea
 */

#include <Arduino.h>

//Define you datatype which contain all module's intern states
 typedef struct LedHandler{
    int pin;
    bool currentState;
} LedHandler;

LedHandler Led_init(int pin);
void Led_toggle(LedHandler * leds);

#endif

