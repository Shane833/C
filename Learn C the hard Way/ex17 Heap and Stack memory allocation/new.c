// Heap vs. Stack
// For now consider that whenever you use malloc you are using the heap and anywhere else it would be stack
// Now one of the advantages of using the heap is when you are passing structures in the function calls
// If you are passing the complete member of the structure it can easily take over the function call stack and will
// take more space in memory, and would have to be copied onto the stack. So now we are beginning to come to call by
// value vs. call by reference
// So here we are using the stack to store the actual value and the heap to share around the structures among the functions

// Using the Heap:
// In the function Database_open, we making a structure using malloc which will be from the heap
// Similary in the struct we again have a pointer to the struct database which we are allocating memory using malloc

// Function Stack
// Whenever you create local variables (includes parameterized) in a function they are stored in the function stack for the entirity
// of the execution of that function and automatically that memory gets freed once the execution ends
/** Note : Don't use memcpy() function to copy one struct to another,if they are variables of the same struct just directly assign them to each other using '=' **/

// EXTRA CREDIT PROGRAMS HERE

#include <stdio.h> // defines functions for handling standard input output data streams
#include <assert.h> // defines a macro which helps in debugging as it checks for a condition and terminates the program with an error message in case the condition is false
#include <errno.h> // defines a macro for reporting and retrieving error condtions, by providing an integer error no. which gets its value from system calls
#include <stdlib.h> // defines functions for dynamic memory allocation
#include <string.h> // defines functions for handling strings

#define MAX_DATA 512 // A constant defining the maximum amount of data to be stored
#define MAX_ROWS 100 // A constant for defining the maximum number of addresses to be stored

struct Address // This is a struct (a complex data structure) which will hold various values regarding the details of a person
{
	int ID; // This variable helps to provide each person a specific ID
	int set; // This variable helps in identifying whether the values for a given ID are set or not
	char name[MAX_DATA]; // An array called name that can store upto 512 characters
	char email[MAX_DATA];// An array called email that can also store upto 512 characters
	
};

struct Database // This is a struct which will store an array of 100 (MAX_ROWS) struct Address variables
{
	struct Address rows[MAX_ROWS]; 
};

struct Connection // As the name suggests this struct will be useful in making a connection with the locally stored database file and read and write its values
{
	FILE *file; // This is a file pointer which will help us traverse the database file
	struct Database *db; // This is a pointer to the struct Database which will help in writing and loading values from the locally stored database file
};

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

// Printing the values in struct Address
void printAddress(struct Address *addr) // This function will print the data member of the address variable
{
	printf("%d %s %s\n",addr->ID,addr->name,addr->email);
}

int main(int argc, char *argv[])
{
	
}