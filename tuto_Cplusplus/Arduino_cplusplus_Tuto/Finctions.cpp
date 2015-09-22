/*
 * This file is the .cpp, it define every functions in its associated header file (else the compiler will complain). The cpp file is straigth forward
 */

//You have no choice to include the header, so the compiler know where to find the functions prototypes.
 #include "Functions.h"

 //now you can define every function:

 float afunction(boolean inputBoolean, int inputInteger)
 {
    //this function get as input two parameter, a boolean and a integer
    //this function return a float

    float returnVariable = 0;
    
    if(inputBoolean == true) // Is there a way to make this line shorter?
    {
      for(int i = 0; i < inputInteger; ++i)
      {
        returnVariable += 0.1;
      }
    }

    return returnVariable;
 }

