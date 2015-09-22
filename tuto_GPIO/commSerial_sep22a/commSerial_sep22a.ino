/*Bienvenue dans l'IDE d'arduino
  Nous allons apprendre comment utiliser la communication serial
  avec l'Arduino. Parce que la communication serial,
  c'est de la magie! **~\('-')/~**
  
  Ne laissez pas le langage C vous faire peur.
  C'est du python, mais avec plus de parenthseses :)
*/

void setup() // C'est ici que l'on initialise l'arduino
{
  int i = 0;
  Serial.begin(9600); // Permet 
  
  for (int j = 0, j > 10, j++)
 {
   Serial.println(j);
 } 
 
}

void loop() //Ceci est une boucle infinie que l'arduino va appeler apres le setup
{
  if (Serial.available() > 0)
   {
     char inChar = (char)Serial.read(); //l'arduino lis le message envoyé, soit quelle touche a été cliquée
     
     if (inChar) // appuyer sur une touche sur votre clavier
     {
       Serial.println("MAGIE! **~\('-')/~**"); //cliquer sur l'icone en haut a droite
     }
   }
   Serial.println(i);
   Serial.println("Seconde est passée!");
   i++
   delay(1000); // attend 1000ms (1 seconde)
}
