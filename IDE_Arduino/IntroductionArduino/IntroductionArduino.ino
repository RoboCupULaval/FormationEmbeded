/*
  Welcome in the Robocup's Embeded Formation, in these tutorials we will always write text in english. You will rarely see comments un other langages and it's
  a good practice to make your comments readable for most users.
  
  This Tutorial is a simple introduction to Arduino's development environnement, and will teach you how to flash simple code into the arduino.
  
  First look up at the small icons in the Arduino's main window (this window!) and hover your mouse on them to get there names:
  Verify : Will compile your C/C++ code with Arduino's compiler, if there is error it will write them in orange in the black window at the bottom.
  Upload : Will compile and flash the arduino ship if comilation pass.
  New, Open, Save : Basic file operations.
  Serial Monitor : A good friend that will show you every data passing in the USB cable and will let you send data in the USB. (Right of the icon bar)
  (To open Serial monitor you must be connected with an arduino, read the following section.)
  
  Now you will plug your first arduino and configure the Ide to recognize it!
  - Plug the arduino in any usb port of your computer.
  - Select Tools/Boards/(Name of your arduino device) : tell the ide which hardware you are using!
  - Select Tools/Serial Port/(Port) : tell the ide which COM port you are using
  - Click on Upload
  - If There is a led blinking fast on the arduino you have done it!!
 */
 
// Pin 13 has an LED connected on most Arduino boards.
// give it a name with a variable, making your code textual is a good practice as "ledPin" make it evident that its refering to a pin connected to a Led :) 
int ledPin = 13;

// the setup routine runs once when you press reset button on the arduino board, it is mainly used to prepare hardware and configure everything buffer the infinite loop.
void setup() {                
  // initialize the digital pin (GPIO) as an output so you can write data to it.
  pinMode(ledPin, OUTPUT);     
}

// the loop routine runs over and over again forever. MCU program don't have OS like general computers and once in there you can go back! It will execute once the setup() as been
// terminated
void loop() {
  digitalWrite(ledPin, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(500);               // wait for 500 ms
  digitalWrite(ledPin, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);
}

// Sorry it is easy, but the purpose is only to make you handle an Arduino for the first time. you now have all the tools to play with arduino and make awesome projects.
