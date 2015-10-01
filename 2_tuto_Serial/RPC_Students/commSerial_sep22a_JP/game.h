#ifndef _GAME
#define _GAME

#include "Arduino.h"
#include "menu.h"




enum _objet
{
  roche = 'r', papier = 'p', ciseau = 'c'
};

struct objet
{
  enum _objet o;

  char* tostring() 
  {
    if(o == roche)
    {
      return "roche";
    }
    else if (o == papier)
    {
      return "papier";
    }
    else
    {
      return "ciseau";
    }
  };
};


/**
 * classe du jeu roche papier ciseau
 */ 
class game
{
  private:
    Stream& _stream;
    menu _menu;

    void displayInstructions();
    objet getUserInput();
    objet getComputersChoice();
    void afficherChoix(objet objUser, objet objComp);
    void afficherGagnant(objet objUser, objet objComp);

  public:
    game(Stream& stream);
    void run();
};

#endif
