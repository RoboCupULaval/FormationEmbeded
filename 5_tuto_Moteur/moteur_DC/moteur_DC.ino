int pwm = 3;
int dir = 6;
int maximum = 900;
int minimum = 300;
bool toggle = OUTPUT;
int currentSpeed = 0;

void setup() {
  pinMode(dir, OUTPUT);
  Serial.begin(9600);
  analogWrite(pwm, currentSpeed); //0 to 1023
  Serial.println("Entering Main Loop");

}

void loop() {
  if (Serial.available() > 0)
   {
     char inChar = (char)Serial.read(); 
     
     if (inChar == '0') // appuyer sur une touche sur votre clavier
     {
       currentSpeed = 0;
     }
     else if(inChar == '1')
     {
      currentSpeed = 200;
     }
     else if(inChar == '2')
     {
      currentSpeed = 900;
     }
   }
  
  //Motor Input
  Serial.println("Toggle direction");
  analogWrite(pwm, currentSpeed); //0 to 1023
  toggle = !toggle;
  digitalWrite(dir, toggle);
  delay(1000);
}
