#include "game.h"

/**
 * constructeur avec stream
 */
game::game(Stream& stream)
  :_stream(stream), _menu(stream)
{
}

/**
 * run the game
 */
void game::run()
{
  _menu.handleMenu();

  displayInstructions();
  
  objet objUser = getUserInput();
  objet objComputer = getComputersChoice();
  
  afficherChoix(objUser, objComputer);
  afficherGagnant(objUser, objComputer);
  
  _menu.reload();
}

/**
 * Affiche les commandes à l'utlisateur
 */
void game::displayInstructions()
{
  _stream.println("entrer r pour roche");
  _stream.println("entrer p pour papier");
  _stream.println("entrer c pour ciseau");
}

/**
 * gère l'entré utlisateur
 */
objet game::getUserInput()
{
    //on attend un petit peut le temps que l'utilisateur entre quelque chose
    while(_stream.available() <= 0)
    {
      delay(500);
    } 
    char inChar = (char)_stream.read(); //l'arduino lis le message envoyé, soit quelle touche a été cliquée

    //on vide le reste de la chaîne
    while(_stream.available() > 0)
    {
      _stream.read();
    }
    objet obj;
    obj.o = {(_objet)inChar};
    return obj;
}

/**
 * génère le choix de l'ordinateur
 */
objet game::getComputersChoice()
{
  long computerChoice = random(1, 100);
  objet obj;
  if(computerChoice < 34)
  {
    obj.o = {roche};
  }
  else if(computerChoice < 67)
  {
    obj.o = {papier};
  }
  else
  {
    obj.o = {ciseau};
  }
  return obj;
}

/**
 * affiche les choix
 */
void game::afficherChoix(objet objUser, objet objComp)
{
  _stream.println("");
  _stream.println("Vous avez choisi:");
  _stream.println(objUser.tostring());

   _stream.println("L'ordinateur a choisi:");
   _stream.println(objComp.tostring());
   _stream.println("");
}

/**
 * affiche le gagnant de la partie
 */
void game::afficherGagnant(objet objUser, objet objComp)
{
  if(objUser.o == objComp.o)
  {
    _stream.println("**partie nulle**");
  }
  else if((objUser.o == roche && objComp.o == ciseau) ||
      (objUser.o == papier && objComp.o == roche) ||
      (objUser.o == ciseau && objComp.o == papier))
  {
    _stream.println("Vous avez gagné! Bravo champion!");
  }
  else
  {
    _stream.println("Vous avez perdu! (fouin fouin fouin)");
  }
}

