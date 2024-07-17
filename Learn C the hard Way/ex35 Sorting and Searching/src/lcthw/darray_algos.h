#ifndef darray_algos_h
#define darray_algos_h

#include <lcthw/darray.h>
#include <lcthw/list.h>
#include <lcthw/PQueue.h>

typedef int (*DArray_compare) (const void* a, const void* b);

static inline void DArray_swap(DArray* array, unsigned int i, unsigned int j)
{
	void* temp = DArray_get(array, i);
	DArray_set(array, i, DArray_get(array, j));
	DArray_set(array, j, temp);
}

int DArray_quicksort(DArray* array, DArray_compare cmp);

int DArray_heapsort(DArray* array, DArray_compare cmp);

int DArray_mergesort(DArray* array, DArray_compare cmp);

#endif