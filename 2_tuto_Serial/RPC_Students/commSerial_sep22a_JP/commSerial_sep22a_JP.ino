/*Bienvenue dans l'IDE d'arduino
  Nous allons apprendre comment utiliser la communication serial
  avec l'Arduino. Parce que la communication serial,
  c'est de la magie! **~\('-')/~**
  
  Ne laissez pas le langage C vous faire peur.
  C'est du python, mais avec plus de parenthseses :)
*/

#include "game.h"

game * myGame;

void setup() // C'est ici que l'on initialise l'arduino
{
  Serial.begin(9600); // Permet 

  myGame = new game(Serial);
}

void loop() //Ceci est une boucle infinie que l'arduino va appeler apres le setup
{
    myGame->run();
}
