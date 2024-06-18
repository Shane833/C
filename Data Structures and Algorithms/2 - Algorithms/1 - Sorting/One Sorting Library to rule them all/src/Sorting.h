#ifndef __SORTING_H__
#define __SORTING_H__

#include <dbg.h> // Additional Dependency (must be set as the include in makefile/recipe)
#include <stdbool.h>

typedef int (*Compare) (const void* a, const void* b); // Function pointer to a user-defined compare function

static inline void swap(void** array, const int index_a, const int index_b) // Function to swap two elements in an array 
{
	void* temp = array[index_a];
	array[index_a] = array[index_b];
	array[index_b] = temp;
}

// general sorting algorithm for data types with holding 4 bytes of memory
// This is so bcz I'm using a void* and it sizes up to 4 bytes, hence
// when I actually increament data it is incremented in terms of 4 bytes

bool Sort_bubble(void** array, size_t size, Compare cmp); 

bool Sort_selection(void** array, size_t size, Compare cmp);

bool Sort_insertion(void** array, size_t size, Compare cmp);

bool Sort_merge(void** array, size_t size, Compare cmp);

bool Sort_quick(void** array, size_t size, Compare cmp);




#endif