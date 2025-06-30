#include <stdio.h>
#include <stdlib.h>

int main()
{
	// You can provide a size of 0 to malloc or calloc
	// Then they will return a pointer which can be safely passed
	// to free without causing any issues

	// This can be used to enter elements in a static array

	int array[5] = {1,2,3,4,5};
	
	void * ptr = malloc(0); // runtime allocated
	// It's allowed to return NULL, and it's allowed to return a non-NULL pointer you can't dereference. 
	// Both ways are sanctioned by the standard (7.20.3):
	ptr = &array[4];

	int * iptr = &array[4]; // statically-allocated
	
	
	printf("ptr contains: %d\n",*(int*)ptr);
	
	ptr = NULL; // we are not referencing anything safe to free

	free(ptr); // should not cause any problems

	// free(iptr); // This causes error

	printf("array[4] : %d\n", array[4]);
}