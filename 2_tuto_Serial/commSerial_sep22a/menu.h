#ifndef _MENU
#define _MENU

#include "Arduino.h"

class menu
{
  private:
    Stream& _serial;
    bool _isDisplayed;

    void displayMenu();
    char getUserInput();
    void handleInput(char input);
    void quitterLeJeu();
  
  public:
    menu(Stream& serial);
    void handleMenu(); 
    void reload();
};

#endif

