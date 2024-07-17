#include <lcthw/bstrlib.h>
#include "minunit.h"

char* test_create()
{
	// Okay so the thing is that the bstring data type is declared
	// as a pointer so by default any variable of the type bstring 
	// will automatically be a pointer
	
	bstring a = bfromcstr("Shivang"); 
	printf("Length : %d\n", blength(a));
	printf("Data : %s\n", bdata(a));
	
	return NULL;
}

char* all_tests()
{
	mu_suite_start();
	mu_run_test(test_create)
	
	return NULL;
}

RUN_TESTS(all_tests);