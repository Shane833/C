#include <stdio.h> // defines functions for handling standard input output data streams
#include <stdlib.h> // defines functions for dynamic memory allocation
#include <errno.h> // defines a macro for reporting and retrieving error condtions, by providing an integer error no. which gets its value from system calls
#include <string.h> // This library actually contains the memcpy function to be used in the program

// POINTERS TO FUNCTIONS
/**
-> Functions are basically pointers to a specific location in the program where some code exists
-> and since they are pointers they can be pointed to themselves by other pointers, just like we create pointers to struct, strings and arrays
-> The main feature of using pointers to functions is to pass callbacks to other functions or to simulate class object relationship
-> A function callback meaning not invoking a function directly but by using some other to way to call it

-> Syntax for a function pointer : return_type (*pointer_name)(same arguments as the function we want to refer to)
-> Also make sure that the return type also matches
-> Steps involved in creating a function pointer
   -> Say you want to create a function pointer to the function : int sum(int a,int b)
	1. Wrap the name of the function in parenthesis : int (sum)(int a,int b)
	2. Add * before the name of the function : int (*sum)(int a,int b)
	3. Change the name of the pointer now : int (*add)(int a,int b)
   -> and now you have successfully created a pointer to a function whose return type is int and takes two integers in the argument
   -> This also works with function returning a pointer too
      For example : Say we want to create a function pointer to the function : Node *insert(int data)
					Then your function pointer will be like : Node *(*insert_cb)(int data)

-> Assigning the pointer to the function:
   -> There are mainly 2 ways:
	1. At the time of declaration/definition:
		-> Lets say we want to point to our sum function:
           int (*add)(int a,int b) = sum; // You can simply put it equal to the name of the function you are trying to point to at the time of declaration
					OR
		   int (*add)(int a,int b);
		   add = sum; // You can also declare first then use it later by simply equating it to the function name
	2. You can define a complex type using typedef:
		-> Define your function pointer in this way:
		   typedef int (*function_cb)(int a,int b);
		-> Now you have created a complex type whose variables acts as function pointers themselves
		-> So you can do the following:
		   function_cb add = sum;
		-> As the add is of the type int (*ptr_name)(int a,int b), hence it can be used to refer to sum

-> Usage:
	-> These function pointers basically acts as functions themeselves and can be called like functions
	   For example : int (*add)(int a,int b) = sum;
		             add(2,3); // Simply make a function call using the pointer name instead and provide the same arguments
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



// Defining the classic bubble sort function that uses the compare_cb to perform sorting
int *bubble_sort(int *numbers,int count,compare_cb cmp) // This functions takes the pointer to integer( basically an array of integers), its count/size and a variable of the compare_cb which will help us pass different functions to it
{
	int temp = 0; // will be used for swapping elements
	int i = 0; // will be used as an iterator in the loop
	int j = 0; // will be used as an iterator in the loop
	int *target = malloc(count * sizeof(int)); // Used to store the array, since any operation on the array itself will change its original state hence we will save save it this variable

	if(!target) // In case the memory allocation fails
	{
		die("ERROR : Memory Error!!!\n"); // exiting the program with an error message
	}

	memcpy(target,numbers,count * sizeof(int)); // memcpy function (memcpy(void *dest,const void *src,size_t n)) copies 'n' bytes memory from one memory area (source) to another memory area (destination) given they must not overlap
	// After the execution of this function all the data in the numbers will be copied to target

	// Bubble Sort
	for(i = 0;i < count;i++) // Since count denotes the size, the upper index will obviously be less than size
	{
		for(j = 0;j < count - 1;j++) // Since we will be comparing j and j + 1, hence not exceed any out of bound stay one less the size
		{
			if(cmp(target[j],target[j+1]) > 0) // Checking if the function returns a positive value which means to perform the swap 
			{
				// Now depending on the different defintion of the function that will be provided in the argument
				// We will either get the result in ascending, descending or in strange order
				
				// Performing a simple swap
				temp = target[j];
				target[j] = target[j+1];
				target[j+1] = temp;
			}
		}
	}

	return target; // In the end we will return the sorted array
}

// Defining a function that will check our result and if everything will go correclty will display them
void test_sorting(int *numbers,int count,compare_cb cmp)
{
	int i = 0; // will be used as an iterator in the loop	
	int *sorted = bubble_sort(numbers,count,cmp); // Calling bubble sort and retrieving our sorted array
	
	if(!sorted) // Checking the validity of the pointer
	{
		die("ERROR : Failed to sort as requested\n"); // Exiting our program in case of invalid pointer to array
	}

	// Printing our newly sorted array
	printf("Sorted Array : ");
	for(i = 0;i < count;i++)
	{
		printf("%d ",sorted[i]);
	}
	printf("\n");

	free(sorted); // Deallocating memory, since we had gotten a dynamically allocated pointer to array
}


int main(int argc,char *argv[])
{
	if(argc < 2)
	{
		die("Usage : ./main 1 4 2 6 7");
	}
	
	int count = argc - 1; // Since argc tells the number of commandline arguments and './main' is always one among them
						  // Hence if we remove one from the 1 from the argc we would get the amount of numbers provided in the input
	char **inputs = argv + 1; // Since the argv would point to the base (where './main' is stored) we are moving one after that where the actual number input is stored it is also equivalent to argv[1]
	int i = 0; // will be used as an iterator in the loop

	int *numbers = malloc(count * sizeof(int)); // Creating a pointer to integer arrays of the provided size

	// Assigning value from the argument array to the integer array
	for(i = 0;i < count;i++)
	{
		numbers[i] = atoi(inputs[i]); // Converting from char* to int using atoi() and assigning value to the integer array
	}

	test_sorting(numbers,count,sorted_order); // This will sort the array in ascending order
	test_sorting(numbers,count,reverse_order); // This will sort the array in descending order
	test_sorting(numbers,count,random_order); 

	free(numbers); // Deallocating memory

	return 0;
}
