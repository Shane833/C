// This is source file which defines variables, functions declared in header file and defines one variables of its own 
#include <stdio.h>
#include "ex22.h"
#include "dbg.h"

// This below is the definition of the extern variable declared in the header file
// So basically how the extern variable works is that you declare the variable in a header file with the extern keyword with its type
// At that stage the compiler knows that the variable exists and is to be declared elsewhere (possibly in the source file) hence no memory is allocated to the variable
// Then in the source file you provide a definition for that variable by simply initializing the variable keeping the syntax same but this time without the extern variable
// For eg: 
// say you declared : extern int age;
// Then you must define the same variable as : int age = 20; 
int THE_SIZE = 1000;

// Static variable are special kinds in the sense that they are initialized once exists for the entirity of the program 
// There are basically two types of static variable definition:
/**
-> 1. Static defined in the file: The static variables if defined globally within a file can only be used in that file only
								  any function can reference them within that file, however any reference outside of that file
								  will resutl in an undefined reference.
-> 2. Static defined within a block or a function : The static variable defined within a block or function will be initialized once and will retain their life
													for the entirity of the program. Unlike local variables they are not defined with each function call but only 
													retain their previous values for the lifetime of the program.

-> Also an important thing to note here is that unlike other variables static variables are not stored on stack or heap, but they
   have a seaparate memory space called a "data segment" or "BSS Segement" and hence can behave different from them
*/
static int THE_AGE = 20; // The scope of this variable only exists within this file

// This function simply returns the value of the defined static variable
int get_age()
{
	return THE_AGE;
}

// This function sets the value of the static variable
void set_age(int age)
{
	// Also since this function is using the variable within this file its a valid operation
	// And then function can be called outside of this file but according to the definition of the function and will still work
	// Since it will look for function defintion within this file where the scope of the static variable is valid
	THE_AGE = age;
}

// This function internally defines a static variable
double update_ratio(double new_ratio)
{
	static double ratio = 1.0;
	double old_ratio = ratio;
	ratio = new_ratio;
	
	return old_ratio;
}

void print_size()
{
	log_info("I think the size is: %d",THE_SIZE);
}