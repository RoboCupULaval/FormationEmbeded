#ifndef _DISPLAY_H   //Instruction to compilator : if _DISPLAY_H as been defined, dont compile this code
#define _DISPLAY_H   // Instruction to compilator : define _DISPLAY_H
// The 2 first line make sure that the compilator will never read the same header file more than once

//Here you tell the compiler if you need other module for this code to work with the include compiler instruction.
#include <Arduino.h>


/*
 * Header files are the first files read by the compilator, it contains every definitions (functions, class, defines etc..) that other file will need to compile the code
 */

 //for this tutorial, we will simply show how to define a function prototype :
float afunction(boolean inputBoolean, int inputInteger);

  //Information and definition of this function will be in the .cpp file. Note that this prototype could be defined in the first lines of the implementation code (before main)

/*
 * Header file are usefull to create different module, you really dont want all your code in the same file (think about windows which as thousand of millions of line of code)
 * This file is usefull as documentation, well written modules will have many functhion with expressive names, it is a good place to see all available functions as it is mostly a list of functions with documentation (if you are lucky!)
 */


#endif
