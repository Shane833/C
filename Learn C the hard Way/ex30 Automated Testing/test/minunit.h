#undef NDEBUG // This is a way to undefine previously defined macros and they can no longer be used again defined
#ifndef _minunit_h
#define _minunit_h

#include <stdio.h>
#include "dbg.h"
#include <stdlib.h>

// creates a local variabe message, which is used to hold return message from the functions
#define mu_suite_start() char* message = NULL 

// This is very similary to any assert, here we just check if the given 
// statement is true and if not then we log the error using another macros
// and try the return message line to disrupt the flow of our program
#define mu_assert(test, message) if(!(test)){ log_err(message); return message; }

/*NOTE to MYSELF : Sometimes it takes to understand think, so don't be frustated and irritated if you don't get the things on our first try*/

// This macros just calls the function provided in the arguemnts and increments the no. of tests ran
// It also prints the name of the test function that is being currently run using the debug macro
#define mu_run_test(test) debug("\n-----%s"," " #test); message = test(); tests_run++; if (message) return message;

// So here we are basically defining our main function
 // simply calls the functions provided in the arguments
#define RUN_TESTS(name) int main(int argc, char* argv[]){\
	argc = 1; \
	debug("---- RUNNING: %s", argv[0]);\
	printf("----\nRUNNING: %s\n", argv[0]);\
	char* result = name();\
	if(result != 0){\
		printf("FAILED: %s\n", result);\
	}\
	else{\
		printf("ALL TESTS PASSED\n");\
	}\
	printf("Tests run: %d\n", tests_run);\
	exit(result != 0);\
}

int tests_run;

#endif