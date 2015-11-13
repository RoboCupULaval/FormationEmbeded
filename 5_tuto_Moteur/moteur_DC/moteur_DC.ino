int pwm = 3;  //Motor PWM pin
int dir = 6;  //Motor direction pin
bool currentDirection = HIGH;
unsigned int currentSpeed = 0;

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
     
     if (inChar == 'w') // appuyer sur une touche sur votre clavier
     {
       currentSpeed = (currentSpeed + 100) % 1023;
     }
     else if(inChar == 's')
     {
      currentSpeed = (currentSpeed - 100) % 1023;
     }
     else if(inChar == '0')
     {
      currentSpeed = 0;
     }
     else if(inChar == 'a')
     {
      currentDirection = HIGH;
     }
     else if(inChar == 'd')
     {
      currentDirection = LOW;
     }
     Serial.print("Current PWM : ");
     Serial.println(currentSpeed);
     analogWrite(pwm, currentSpeed); //0 to 1023 to set motor's pwm
     digitalWrite(dir, currentDirection);
   }
}
