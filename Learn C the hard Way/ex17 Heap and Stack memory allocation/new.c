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

// Creating a Database
struct Connection *createDatabase(const char* filename,char mode) // This function will return a pointer to a dynamically allocated and new created variable of struct Database
{
	struct Connection *conn = malloc(sizeof(struct Database)); // Dynamically allocting memory
	if(!conn) // Here we are checking if the memory was correctly allocated or not
	// As if the memory was correctly allocated the conn pointer will be pointing to a memory address, and using '!' on that memory address will give a 0
	// i.e. !(any_correctly_allocated_pointer) = 0, and if its zero the if block will not be executed
	// However if the memory was not allocated the pointer will not be pointing to any memory address  and will have the value NULL(if you print it, it'll either say nil or 0)
	// so now !(NULL or you can say its 0) = 1, so in this case the if block will run
	{
		
		die("Memory Error");
	}
}

// Loading the Database
void loadDatabase(struct Connection *conn)
{
	size_t read_count = fread(conn->db,sizeof(struct Database),1,conn->file);
	// The fread and fwrite functions are used for reading an writing binary data, it could be the whole array or struct
	// while the fprintf and fscanf can be used to read text data
	// Here we are reading a whole instance of the struct Database which will be stored in the file
	// both fread and fwrite returns the no. items read/written when eno of file is reached or an error occrus
	// FUNCTION TEMPLATE (fread) : size_t fread(void *ptr,size_t size,size_t nmemb(no. of instances of ptr to be read),FILE *stream)
	// Now as we provide the pointer of the databasae to the fread function, by call of reference all the data will automatically be stored in it	
	// here as we are only reading 1 instance of the database therefore when function completes it should return 1 (meaning read count must be 1)
	
	if(read_count != 1) // Now if the read count is not 1, means we have not succesfully read the file
	{
		die("Failed to load Database"); // Terminating the program with an error message
	}
}

int main(int argc, char *argv[])
{
	createDatabase("test.db",'c');
}