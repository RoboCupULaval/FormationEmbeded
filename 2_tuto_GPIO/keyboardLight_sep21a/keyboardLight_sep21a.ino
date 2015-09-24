/*Cet exemple enseigne la communication serial:
   - L'arduino attend un message d'envoie du clavier
   - Si une touche de clavier est clicked, un message en série de bit est envoye a l'arduino
   - l'arduino lit le message
   - Les leds reagissent selon la touche clique  
   Pour cet exemple, la led verte nous est pas nécessaire! on peut donc l'enlever
 */
 
 int ledRouge = 4;
 int ledJaune = 5;
 
 void setup()
 {
   //output
   pinMode(ledRouge, OUTPUT);
   pinMode(ledJaune, OUTPUT);
   
   Serial.begin(9600);
 }
 
 void loop()
 {
   if (Serial.available() > 0)
   {
     char inChar = Serial.read(); //l'arduino lis le message envoyé, soit quelle touche a été cliquée
     
     if (inChar)
     {
       Serial.println("MAGIE! **~\('-')/~**"); //cliquer sur l'icone en haut a droite
       
       
       if (inChar == 'x') //si le message envoyé est la touche x, on allume la led rouge
       {
         digitalWrite(ledRouge, HIGH);
       }
       else 
       {
         digitalWrite(ledJaune, HIGH); // Sinon, la led jaune s'allume
       }
       
       delay(500);
       
       digitalWrite(ledJaune, LOW);
       digitalWrite(ledRouge, LOW); // Pour éteindre les leds
       
     }
   }
 }
 
