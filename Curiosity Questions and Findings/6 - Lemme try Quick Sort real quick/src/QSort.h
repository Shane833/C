#ifndef QSORT_H
#define QSORT_H

#include <stdio.h>

typedef int (*Compare) (const void* a, const void* b);

/*
static inline void swap(void** array, int i, int j, size_t element_size) // Yet to be tested!
{
	// Switch the locations of the pointers
	char* arr = (char*)array;
	void* temp_i = (void*)(arr + i * element_size); // Holds the pointer 
	void* temp_j = (void*)arr(j * element_size];
	printf("i : %lf, j : %lf\n",*(double*)temp_i, *(double*)(arr + (j * element_size)));
	
	// arr[i * element_size] = (char*)temp_j;
	// arr[j * element_size] = (char*)temp_i;
}
*/

static inline void swap(void** array, unsigned int i, unsigned int j)
{
	void* temp = array[i];
	array[i] = array[j];
	array[j] = temp;
}

void quicksort(void** array, int low, int high , Compare cmp);



#endif