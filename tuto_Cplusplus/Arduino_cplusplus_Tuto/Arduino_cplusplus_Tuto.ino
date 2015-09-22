/*
  This tutorial show different C/C++ concepts. It is taken for granted that the reader know the basics of programming.
*/

//######## Types #########
/*
  ref : https://learn.sparkfun.com/tutorials/data-types-in-arduino
  A type is the format of data in memory. It defines a way to manipulate and visualise data that both the programmer and the computer (compilator) can understand.
  In C/C++, the programmer has to define the type of its variables the following ways:
*/

boolean aFlag = true;     //boolean value : true or false : 8 bits
int aInt = -13;           //Integer value : depending on the architecture of your device, generally represent a 16 bits signed integer [-32768, ..., 32767]
unsigned int aUInt = 100; //Unsigned Integer value : 16 bits [0, ..., 65532]
long aLong = 65533;       //Long Integer : 32 bits : [-2,147,483,648, ..., 2,147,483,647]
float aFloat = 0.5;       //Floating point representation :16 bits [-3.4028235E38, ..., 3.4028235E38] :Arduino does not support these in its hardware.. the compiler need to make more code for its manipulation
double aDouble = 0.05;    //Double floating point representation : 32 bits, more accurate : 0.000000000...
char aCharacter = 's';     //signed integer (8 bits) representing an ascii value : [-128, ..., 127]
byte aByte = 255;           //unsigned integer (8bits) [0, ..., 255]

void setup()
{
  int value = 10;
  //############ CONDITIONS STRUCTUR ###################
  if(value == 5)
  {
    // value is 5! 
  }
  else if( value < 5)
  {
    // value is smaller than 5! 
  }
  else
  {
     // value is greater than 5! 
  }
  
  //############ FOR LOOPS ###################
  
  int i = 0;
  for(i = 5; i < 10; ++i)
  {
     //initialise i to 5, loop until i is greater or equal to 10, at each loop, increment i 
  }
  for(i = 0; i < 10; i += 2)
  {
     //initialise i to 0, and this time increment i with 2 at each loops 
  }
  
  //############ WHILE LOOPS ###################
  while(value <= 100)
  {
    value++;
     //will run loop as long as value is smaller or equal to 100; 
  }
  
  // In arduino, the void loop() is in fact a kind of while(true) : infinite loop!
}

void loop()
{
  //Do nothing for ever;
}




