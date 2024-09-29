#include "minunit.h"
#include <lcthw/darray.h>

// So the purpose of this test is to see what happens when we cross
// the pre-defined expand rate and how does the contract and pop functions
// behave in doing so

// So first of all lets define the expected behaviour of the program:
// Q) What will happen happen when you push past the initial max?
// -> It will simply allocate more memory, and increment max variable

// Q) What will happen when we pop off an element ?
// -> It will resize the array back to a normal size just enough to fit the elements I suppose
// Lets find out

static DArray* test_array = NULL;

char* all_tests()
{	
	// Simple test to validate expan
	/*
	test_array = DArray_create(0, 5);
	mu_assert(test_array != NULL, "failed to create the DArray");
	

	// First I want to first break the initial max that is set
	for(int i = 0;i < 6; i++){
		DArray_push(test_array, rand());
	}
	
	printf("Array End : %d, Array Max : %d\n", test_array->end, test_array->max);
	
	DArray_pop(test_array);
	
	printf("Array End : %d, Array Max : %d\n", test_array->end, test_array->max);
	*/
	
	// Checking the end point
	test_array = DArray_create(0, 305);
	mu_assert(test_array != NULL, "failed to create the DArray");
	
	DArray_set(test_array, 303, 5);
	void* value = DArray_get(test_array, 303);
	
	printf("Value at 303th index : %d\n", (int)value);
	
	printf("Array End : %d, Array Max : %d\n", test_array->end, test_array->max);
	
	DArray_push(test_array, 10);
	DArray_push(test_array, 15);
	
	printf("Array End : %d, Array Max : %d\n", test_array->end, test_array->max);
	
	DArray_pop(test_array);
	
	printf("Array End : %d, Array Max : %d\n", test_array->end, test_array->max);
	
	printDArraySize();
	
	return NULL;
}

RUN_TESTS(all_tests);