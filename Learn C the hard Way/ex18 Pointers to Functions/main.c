#include <stdio.h> // defines functions for handling standard input output data streams
#include <stdlib.h> // defines functions for dynamic memory allocation
#include <errno.h> // defines a macro for reporting and retrieving error condtions, by providing an integer error no. which gets its value from system calls

// POINTERS TO FUNCTIONS
/**
-> Functions are basically pointers to a specific location in the program where some code exists
-> and since they are pointers they can be pointed to themselves by other pointers, just like we create pointers to struct, strings and arrays
-> The main feature of using pointers to functions is
*/


// Custom function to terminate the program with an error message
void die(const char *message)
{
	if(errno) // First we check the value of the pre defined variable errno, if its value is anything other than 0 (it mostly likely be -1 as defined in the man page) we know an error has occured
	{
		perror(message); // This function prints the value of the string provided in the arguments to the stderr stream desribing the last error occured during the function call
						 // then an error message corresponding to the current value of errno and a new-line.
	}
	else // However if we explicitely want to terminate the program despite of any system error
	{
		fprintf(stderr,"%s\n",message); // Then we can simply print the provided error message to the stderr stream
	}
	exit(1); // In the end we will exit the program with an exit code of 1, signifying failed execution
}

int main(int argc,char *argv[])
{
	
}
