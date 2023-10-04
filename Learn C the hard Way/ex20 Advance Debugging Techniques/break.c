#include <stdio.h> // defines functions for handling standard input output data streams
#include <stdlib.h> // defines functions for dynamic memory allocation
#include <errno.h> // defines a macro for reporting and retrieving error condtions, by providing an integer error no. which gets its value from system calls
#include <string.h> // This library defines the 

// POINTERS TO FUNCTIONS
/**
 COOL THINGS (proabably dangerous aspec of pointers to functions)
-> Now as these are simple pointers you can use them to point anywhere in the program or possibly outside of the program as well
-> So what a lot of hackers would do is that they would is that they would find a pointer in the program and may use to it point to other functions or other parts of the program
-> Or they may define their own functions and make the program pointers point to them hence running their own code
-> Mostly the easiest pointers are string pointers and they are often targetted for such attacks
*/


// Defining a custom type to create custom function pointer variables
typedef int (*compare_cb)(int a,int b);

// Defining 3 functions to compare the values while implementing the sorting
int sorted_order(int a, int b)
{
	// The way this function works is that it returns the difference between first number and the second number
	// As they will be compared like (a[i] and a[i+1])
	// So if the difference is positive means a is greater than b and hence we can swap them
	// This way the smaller elements will all start going towards the left
	// However if the number are same or the a is less than b, then their difference will be less than equal to 0
	// which suggest than a is already smaller than b, so we won't need to swap them
	return a - b;
}

int reverse_order(int a, int b)
{
	// The way this function works is that it returns the difference between second number and the first number
	// As they will be compared like (a[i] and a[i+1])
	// So if the difference is positive means the b is greater than a and we must swap them
	// This way all the larger elements will start moving towards the left and all the smaller towards the right
	// and this way the array will be sorted in descending order or reversed order

	return b - a;
}

int random_order(int a,int b)
{
	if(a == 0 || b ==  0)
	{
		return 0;
	}
	else
	{
		return a % b;
	}
}

// This function will 
void dump(compare_cb fun)
{
	int i = 0; // Used as an iterator in the loop
	unsigned char *data = (unsigned char *)fun; // Literally reading the data from the function pointer and converting into string format
	for(i = 0;i < 20;i++)
	{
		printf("%x ",data[i]); // Printing the given data into hex digit form
		 data[i] = i; // Overwriting the data itself
	}
	printf("\n");

}

int main(int argc,char *argv[])
{
	// When we call this function it will take the function pointer and start showing all the address in the memory
	// In the function definition of dump() I have commented out one part which overwrites the data itself
	// Now if you will try to run it without the comments it is actually overwriting the executible code itself
	// Now OS like Linux or macOS will not let you do this but it can be done in windows
	dump(sorted_order);
	dump(reverse_order);
	
	dump(NULL);

	// RULES FOR DEBUGGING
	// -> You can't debug code by just looking at it
	// -> Repeat the bug with an automated test
	// -> Run the program under a debugger, valgrint, lint
	// -> Find the backtrace and print out all the variables on the path
	// -> Once you fix it add checking capabilites to prevent it from happening again
	
	return 0;
}
