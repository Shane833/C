#include "dbg.h"
#include <stdio.h>
#include <stdlib.h>

// This is a macro Sum which returns a value, i.e. whatever value is in the last section of the definition of the macro get returned 
// or more accurately whatever expression is in the end the value of the macro equates to that
#define Sum(a,b) ({int c; c = a + b; c;})
// This is a macro Add which performs the addition and updates the value of a (as it directly works on the reference of the value)
#define Add(a,b) (a = a + b)

#define returnAdd(a,b) (a + b) // Simply returns the value in the end


void test_debug()
{
	// notice you don't need the \n
	debug("I have black hair.");
	
	// Passing in arguments like printf
	debug("I am %d years old.",20);
	// as the macro takes the argument in the form debug(M,...)
	// M actually stores the strings and then ... takes whatever arguments are to be placed in that string as per their format specifiers
}

void test_log_err()
{
	// Simply passing arguments as a string or with formats
	log_err("I believe everything is broken.");
	log_err("There is %d problem in %s",0,"space");
}

void test_log_warn()
{
	// Simply passing arguments as a string or with formats
	log_warn("You can safely ignore this.");
	log_warn("Maybe consider taking a look at %s","/etc/passwd");
}

void test_log_info()
{
	// Simply passing arguments as a string or with formats
	log_info("Well I did something mundane today.");
	log_info("It happened %f times this day",1.3f);
}

int test_check(char *filename)
{
	// Declaring two null pointers
	FILE *input = NULL;
	char *block = NULL;
	// Dynamically allocating memory
	block = malloc(100); // 100 bytes of memory should be allocated to that pointer
	check_mem(block); // Checking the allocation

	input = fopen(filename,"r"); // Opening the given file
	check(input,"Failed to open %s",filename); // Checking the if the file pointer is valid and throwing an error message just in case

	// If everything goes right
	free(block); // Closing the file pointer
	fclose(input); // Deallocating memory
	return 0;

	// If some error occurs the program will jump to this section of the code
	error:
		if(block) free(block);
		if(input) fclose(input);
		return -1;
}

int test_sentinel(int code)
{
	// Dynamic allocatin and error checking
	char *temp = malloc(100);
	check_mem(temp);

	switch(code)
	{
		case 1:
			log_info("It worked.");
			break;
		default:
			// Checking that this section of the program shouln't run
			sentinel("It shouldn't run.");
	}

	// If everything goes right	
	free(temp);
	return 0;

	// In case some error occurs
	error:
		if(temp) free(temp);
		return -1;
}

int test_check_mem()
{
	char *test = NULL;
	check_mem(test); // This will throw an error message as the pointer is invalid

	free(test);
	return 1;

	error:
		return -1;
}

int test_check_debug()
{
	int i = 0;
	check_debug(i != 0,"Oops I was 0."); // Checks the given statement i.e. we wrote i != 0, so it will exactly check, if i is not 0 then its ok however if it is 0 then its gonna be a problem
	return 0;

	error:
		return -1;
}

int main(int argc,char *argv[])
{
/*
	// My own little experiments
	int a = 5;
	int b = 2;
	a = Sum(a,b);
	printf("Sum : %d\n",a);
	int c = returnAdd(a,b);
	printf("Add : %d\n",c);
	// Test : can we equate a variable to a block 
	
	a = ({int c; c = a + b; c;})
	
	// Unfortunately we cannot this syntax seems to have been reserved for macros only

	// The '==' operator returns a 1 for a true expression and a 0 for a false expresion	
	printf("%d",1==1); // The answer will be 1
	printf("%d",1==2); // The answer will be 0
*/

	// Actual source code from the book
	
	// Using the macros and their designated functions
	check(argc == 2,"Need an argument.");
	
	test_debug();
	test_log_err();
	test_log_warn();
	test_log_info();

	// Using check macro 
	check(test_check("main.c") == 0,"Failed with main.c");
	check(test_check(argv[1]) == -1,"Failed with argv");
	check(test_sentinel(1) == 0,"test_sentinel failed");
	check(test_sentinel(100) == -1,"test_senitnel failed");
	check(test_check_mem() == -1,"test_check_mem failed");
	check(test_check_debug() == -1,"test_check_debug failed");
	
	return 0;

	error:
		return 1;

}