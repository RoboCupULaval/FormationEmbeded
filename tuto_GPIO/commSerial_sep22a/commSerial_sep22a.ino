/*Bienvenue dans l'IDE d'arduino
  Nous allons apprendre comment utiliser la communication serial
  avec l'Arduino. Parce que la communication serial,
  c'est de la magie! **~\('-')/~**
  
  Ne laissez pas le langage C vous faire peur.
  C'est du python, mais avec plus de parenthseses :)
*/

int g_Time = 0;

void setup() // C'est ici que l'on initialise l'arduino
{
  Serial.begin(9600); // Permet 
  
  for (int j = 5; j < 0; --j)
 {
   Serial.println(j);
   delay(500);
 } 
 Serial.println("Partez!");
 
}

void loop() //Ceci est une boucle infinie que l'arduino va appeler apres le setup
{
  if (Serial.available() > 0)
   {
     char inChar = (char)Serial.read(); //l'arduino lis le message envoyé, soit quelle touche a été cliquée
     
     if (inChar == 'a') // appuyer sur une touche sur votre clavier
     {
       Serial.println("MAGIE! **~\('-')/~**"); //cliquer sur l'icone en haut a droite
     }
   }
   Serial.print(g_Time);
   Serial.println(" Seconde est passée!");
   g_Time++;
   delay(1000); // attend 1000ms (1 seconde)
}
