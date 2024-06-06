#ifndef __DARRAY_ALGOS_H__
#define __DARRAY_ALGOS_H__

#include <darray.h>
#include <stdbool.h>

typedef int (*DArray_compare) (const void* a, const void* b);

bool DArray_bubble_sort(DArray* array, DArray_compare cmp);

static inline void DArray_swap(DArray* array, int i, int j)
{
	check(array != NULL, "Invalid array");
	void* temp = DArray_get(array, i);
	DArray_set(array, i, DArray_get(array, j));
	DArray_set(array, j, temp);

error: // fallthrough
	return;
}

#endif