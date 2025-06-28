#include <stdio.h>
#include <stdlib.h>

int main()
{
	// You can provide a size of 0 to malloc or calloc
	// Then they will return a pointer which can be safely passed
	// to free without causing any issues
	// This can be used to enter elements in a static array

	int array[5] = {1,2,3,4,5};

	int * ptr = malloc(0);
	ptr = &array[4];
	printf("ptr contains: %d\n",*ptr);

	free(ptr); // should not cause any problems

	printf("array[4] : %d\n", array[4]);
}