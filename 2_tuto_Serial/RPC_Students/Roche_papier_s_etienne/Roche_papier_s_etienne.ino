  int counterWin = 0;
  int counterLose = 0;
  int counterDraw = 0; 

  
void setup() {
  Serial.begin(9600);
  Serial.println("Roche/Papier/Ciseaux");
  Serial.println("0 pour roche, 1 pour papier, 2 pour ciseaux et 'r' pour le resultat");

}

void loop() {

  if (Serial.available())
   {
    int inInt = (int)Serial.read();
    int RandInt = random(3);

    if (inInt == 114) // pour afficher les resultats
    {
      Serial.println("------Resultat--------");
      Serial.print(counterWin);
      Serial.println(" gagne");
      Serial.print(counterLose);
      Serial.println(" perdu");
      Serial.print(counterDraw);
      Serial.println(" egalite");
      Serial.println("----------------------");
    }
    
    if (inInt == 48) // 48 pour 0
    {
       if (RandInt == 2)
       {
        Serial.println("Vous avez gagne :)");
        counterWin++;
       }
       else if (RandInt == 1)
       {
        Serial.println("Vous avez perdu :(");
        counterLose++;  
       }
       else if (RandInt == 0)
       {
        Serial.println("egalite");
        counterDraw++;
       }
/*
       switch (RandInt)  // Here you could use a switch case statement ;)
       {
        case 2:
          // statements
          break;
        case 1:
          // statements
          break;
        default:
          // statements
        break;
      }
*/
    }

    if (inInt == 49)
    {
       if (RandInt == 0)
       {
        Serial.println("Vous avez gagne :)");
        counterWin++;
       }
       else if (RandInt == 2)
       {
        Serial.println("Vous avez perdu :(");
        counterLose++; 
       }
       else if (RandInt == 1)
       {
        Serial.println("egalite");
        counterDraw++;
       }
    }
    if (inInt == 50)
    {
       if (RandInt == 1)
       {
        Serial.println("Vous avez gagne :)");
        counterWin++;
       }
       else if (RandInt == 0)
       {
        Serial.println("Vous avez perdu :(");
        counterLose++;  
       }
       else if (RandInt == 2)
       {
        Serial.println("egalite");
        counterDraw++;
       }
    }
   }

}
