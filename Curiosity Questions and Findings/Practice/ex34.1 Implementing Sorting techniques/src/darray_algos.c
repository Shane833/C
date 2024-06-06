#include <darray_algos.h>

bool DArray_bubble_sort(DArray* array, DArray_compare cmp)
{
	check(array != NULL, "Invalid array");
	check(array->end != 0, "Cannot sort an empty array");
	
	bool swapped = true;
	for(int pass = 0;pass < DArray_count(array) && swapped; pass++){
		swapped = false;
		for(int j = 0;j < DArray_count(array) - pass - 1; j++){
			if(cmp(DArray_get(array, j), DArray_get(array, j+1)) > 0){
				DArray_swap(array, j, j+1);
				swapped = true;
			}
		}
	}
	
	return true;
error:
	return false;
}