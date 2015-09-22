

int pushSens = 2;// <--toujours mettre un ";" a la fin de la ligne

int ledRouge = 4; // Remarquer que le chiffre est celui de la connection
int ledJaune = 5;
int ledVerte = 6;

volatile int state = HIGH; //#Alexandra: pourquoi Volatile? explique le ici, => les variables volatiles sont une feature du C/C++ un peu difficile à comprendre sur le coup, je t'invite à faire des recherches et bien comprendre leurs engagement :)

void setup()
{
  // Associations des pins ainsi que leur role
  //output
  pinMode(ledRouge, OUTPUT);
  pinMode(ledJaune, OUTPUT);
  pinMode(ledVerte, OUTPUT);

  //Initialise l'interupte de la pin "pushSens". Lorsque l'interupt est lancé, il va executer la fonction changeSens!
  attachInterrupt(pushSens, changeSens, LOW);

  //Commence la communication serial a 9600 bits/sec
  Serial.begin(9600);
}

void loop()
{
  //This is where the magic happens **~\('-')/~**
  // And by magic, I mean SCIENCE!
  // And by SCIENCE!, I mean blinking leds
  
  digitalWrite(ledRouge, state); //normal : HIGH
  digitalWrite(ledJaune, !state); //normal : LOW
  digitalWrite(ledVerte, !state); //normal : LOW
  delay(1000);

  digitalWrite(ledRouge, !state);
  digitalWrite(ledJaune, state);
  digitalWrite(ledVerte, !state);
  delay(1000);

  digitalWrite(ledRouge, !state);
  digitalWrite(ledJaune, !state);
  digitalWrite(ledVerte, state);
  delay(1000);
}

/*
 * Question aile de poulet! : Trouvez moi les dangers d'utilisation d'interupts! (3 ailes par danger) (pas plus de 3 ailes par personnes qui en trouve) (2 réponses acceptés)
 */

void changeSens()
{
  // inverse les états des leds
  //Les fonctions d'un interrupt doivent respecter 2 regles:
  // - Ne recoit rien (aucun argument)
  // - Ne retourne rien (fonction void)
  state = !state;
}

