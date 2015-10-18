

int potentioPin = A0; // Les entrées analogiques commencent par la lettre 'A'
 // Attention ce n'est pas tout les GPIO qui peuvent servir comme output analogique (PWM)
 // Sur l'Arduino Uno les pins 3, 5, 6, 9, 10, 11, 12 et 13 sont utilisable
int ledPin = 3;     

void setup() {
  // Il faut declarer le PWM en output
  pinMode(ledPin, OUTPUT);
  // Il n'est pas nécessaire de mettre en mode input les entrées analogiques
}

void loop() {
  // Lit la valeur du potentiomètre. Elle sera entre 0 et 1023
  int valeurPot = analogRead(potentioPin);
  // Le PWN varie entre 0 et 255, il faut donc diviser par 4 la valeur
  int valeurSortie = valeurPot /4;

  // Une valeur de 0 renvoie un voltage analogique de 0 et une valeur de 255 renvoie un voltage de 5v
  analogWrite(ledPin, valeurSortie);
}
