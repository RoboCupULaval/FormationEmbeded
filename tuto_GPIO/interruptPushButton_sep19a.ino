

int pushSens = 2;// <--toujours mettre un ";" a la fin de la ligne

int ledRouge = 4; // Remarquer que le chiffre est celui de la connection
int ledJaune = 5;
int ledVerte = 6;

volatile int state = HIGH;

void setup()
{
  // Associations des pins ainsi que leur role
  //output
  pinMode(ledRouge, OUTPUT);
  pinMode(ledJaune, OUTPUT);
  pinMode(ledVerte, OUTPUT);

  //pin interrupt
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

void changeSens()
{
  // inverse les états des leds
  //Les fonctions d'un interrupt doivent respecter 2 regles:
  // - Ne recoit rien (aucun argument)
  // - Ne redonne rien (fonction void)
  state = !state;
}

