// This is a source file which defines variables, functions declared in header file and defines one variables of its own 
#include <stdio.h>
#include "ex22.h" // We include this file to provide a definition to the various variables and functions declared in this header file
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
								  will result in an undefined reference.
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

// This function internally defines a static variable and updates it
double update_ratio(double new_ratio)
{
	// First we declare a static variable and initialize it (If static variables are not initialized their value defaults to 0)
	static double ratio = 1.0;
	// Then we store its value in another variable called old_ratio
	double old_ratio = ratio;
	// Then we finally update its value to the value provided in the function argument
	ratio = new_ratio;
	
	// But here we return the old value of the static variable i.e. before we changed it
	return old_ratio;

	// So how it works is that the first its value is initialized to 1.0, hence, the value of old ratio is also 1.0
	// But then in the subsequent line the value of ratio is updated to say 5.0 but value of old ratio still remains the same hence it return 1.0
	
	// Second time you can simply neglect the first line of initialization as it simply don't affect the status of the program
	// So now the value of old ratio is 5.0 as ratio was updated to 5.0, but then ratio gets updated again say to 10.0 but the value of old ratio is still 5.0 and hence it returns that
}

void print_size()
{
	// This simply prints the current value of the THE_SIZE variable
	log_info("I think the size is: %d",THE_SIZE);
}