/*Cet exemple enseigne la communication serial:
   - L'arduino attend un message d'envoie du clavier
   - Si une touche de clavier est clicked, un message en série de bit est envoye a l'arduino
   - l'arduino lit le message
   - Les leds reagissent selon la touche clique  
   Pour cet exemple, la led verte nous est pas nécessaire! on peut donc l'enlever
 */
 
 //int ledRouge = 1;
 //int ledJaune = 5;
 int pain;
 int mainAdv;
 String res[] = {"Pierre", "Papier", "Ciseaux"};
 
 void setup()
 {
   
   Serial.begin(9600);
 }

 void loop()
 {
  
   Serial.print("Faite donc une petite partie de Pierre Papier Ciseaux ! \n");
   Serial.print("Taper 1 pour Pierre, 2 pour Papier et 3 pour Ciseaux \n (pour lezard et spock on verra plus tard)\n");
   Serial.print("1...\n");
   delay(1000);
   Serial.print("2...\n");
   pain = random(1, 3);
   delay(1000);
   Serial.print("3...\n");
  
   while(Serial.available() == false){}
   
   if (Serial.available() > 0)
   {
     char mainAdv = Serial.read(); //l'arduino lis le message envoyé, soit quelle touche a été cliquée
     
     if (mainAdv =! 0)
     {
       int i = (mainAdv - 1);
       Serial.println(res[i]); //cliquer sur l'icone en haut a droite
       
       
    
       delay(500);

       
     }
   }
 }
 
