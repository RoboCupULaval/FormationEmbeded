#include "menu.h"


/**
 * constructor with serial
 */
menu::menu(Stream& serial)
:_serial(serial), _isDisplayed(true)
{
}

/**
 * handle le menu du jeu
 */
void menu::handleMenu()
{
    char input = ' ';

    while(_isDisplayed)
    {
      displayMenu();
      input = getUserInput();
      handleInput(input);
    }
}

/**
 * Display le menu
 */
void menu::displayMenu()
{
   _serial.println("");
   _serial.println("**Bienvenue dans le jeu full cool de jp**");
   _serial.println("Appuyer sur 'j' pour jouer");
   _serial.println("Appuyer sur 'q' pour quitter");
   _serial.println("");
}

/**
 * gère les entrées de l'utilisateur
 */
char menu::getUserInput()
{
   //on attend un petit peut le temps que l'utilisateur entre quelque chose
    while(_serial.available() <= 0)
    {
      delay(500);
    } 
    char inChar = (char)_serial.read(); //l'arduino lis le message envoyé, soit quelle touche a été cliquée

    //on vide le reste de la chaîne
    while(_serial.available() > 0)
    {
      _serial.read();
    }
    return inChar;
}

/**
 * gère le caractère entré par le user  
 */
void menu::handleInput(char input)
{
  if (input == 'j') // appuyer sur une touche sur votre clavier
  {
     _isDisplayed = false;
  }
  else if(input == 'q')
  {
    quitterLeJeu();
  }
  else
  {
    _serial.println("charactere non valide");
  } 
}

/**
 * permet de "quitter" le jeu
 */
void menu::quitterLeJeu()
{
   _serial.println("We are sorry to see you go... :(");
   while(1)
   {
    delay(1000);
   } //on ne peut pas stoper le programme dans arduino. alors on lui fait rien faire infiniment
}

/**
 * reload le menu
 */
void menu::reload()
{
  _isDisplayed = true;
}


