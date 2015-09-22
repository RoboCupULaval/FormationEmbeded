/*Bienvenue dans l'IDE d'arduino
  Les trois prochains tutoriels vont nous permettre 
  de faire de la magie! **~\('-')/~**
  
  Ne laissez pas le langage C vous faire peur.
  C'est du python, mais avec plus de parenthseses :)
*/

int ledRouge = 4; // En C, lorsqu'on crée un objet, il faut définir son type
int ledJaune = 5; // Remarquez que le chiffre est celui de la connection sur le board
int ledVerte = 6; // <--toujours mettre un ";" a la fin de la ligne

int push = 2;

void setup()
{
  // Associations des pins ainsi que leur role
  //input
  pinMode(push, INPUT);
  
  //output
  pinMode(ledRouge, OUTPUT);
  pinMode(ledJaune, OUTPUT);
  pinMode(ledVerte, OUTPUT);
  
  //Commence la communication serial a 9600 bits/sec
  Serial.begin(9600);
}

void loop() // cette fonction se rappelle quand elle a terminé: c'est une boucle
{
  if (digitalRead(push) == HIGH)
  {
    digitalWrite(ledRouge, HIGH); 
    digitalWrite(ledJaune, HIGH); 
    digitalWrite(ledVerte, HIGH);
  }
  else
  {
    digitalWrite(ledRouge, LOW); 
    digitalWrite(ledJaune, LOW); 
    digitalWrite(ledVerte, LOW);
  }
}
