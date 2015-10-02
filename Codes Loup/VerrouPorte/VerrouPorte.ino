const int red = 50;
const int green = 51;
char mdp[4];

void setup(){
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  Serial.begin(9600);
  Serial.print("Merci d'initialiser le verrou en indiquant le code a 4 chiffres désiré a l'aide du clavier \n");
  for (int i =0; i<4; i++){
    while(Serial.available()==false){};
    
    mdp[i] = Serial.read();
    
    
  }
}
