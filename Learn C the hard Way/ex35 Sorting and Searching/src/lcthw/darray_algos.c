#include <lcthw/darray_algos.h>

static void merge(DArray* array, unsigned int low, unsigned int mid, unsigned int high, DArray_compare cmp)
{
	// Index / Counter
	unsigned int i = 0; 
	
	// Buffers for holding the data
	List* left = List_create();
	List* right = List_create();
	
	check_mem(left);
	check_mem(left);
	
	// Copy the data into the buffers
	for(i = low;i <= mid; i++){
		List_push(left, DArray_get(array, i));
	}
	for(i = mid + 1; i <= high; i++){
		List_push(right, DArray_get(array, i));
	}
	
	i = low; // starting at the beginning of the counter
	
	// Now compare and push the data back into the array
	while(List_count(left) > 0 && List_count(right) > 0){ // There was a bug I had to put '&&' instead of '||' bcz then one of the list would become invalid
		if(cmp(List_first(left), List_last(right)) < 0){ // The cmp function must return -ve if a<b, 0 if a==b and +ve if a > b
			DArray_set(array, i++, List_shift(left));
		}
		else{
			DArray_set(array, i++, List_shift(right));
		}
	}
	
	// Now copying the additional data left (if any)
	while(List_count(left) > 0) DArray_set(array, i++, List_shift(left));
	while(List_count(right) > 0) DArray_set(array, i++, List_shift(right));
	
error: // Fallthrough
	if(left) List_destroy(left);
	if(right) List_destroy(right);
	return;
}

static void divide(DArray* array, unsigned int low, unsigned int high, DArray_compare cmp) // helper function
{
	if(low >= high) return; // base case
	
	unsigned int mid = low + (high - low) / 2;
	
	divide(array, low, mid,(DArray_compare) cmp);
	divide(array, mid + 1, high,(DArray_compare) cmp);
	merge(array, low, mid, high,(DArray_compare) cmp); 	
}


int mergesort(DArray* array, size_t size, DArray_compare cmp)
{
	check(array != NULL, "Can't sort a NULL pointed array");
	check(array->contents != NULL, "Can't sort a NULL pointed array");
	
	divide(array, 0, size - 1,(DArray_compare) cmp);
	
	return 0;
error:
	return 1;
}

int DArray_heapsort(DArray* array, DArray_compare cmp)
{
	// return heapsort(array->contents, DArray_count(array), sizeof(void*), cmp);
	return 0;
}

int DArray_mergesort(DArray* array, DArray_compare cmp)
{
	return mergesort(array, DArray_count(array), cmp);
}

int DArray_qsort(DArray* array, DArray_compare cmp)
{
	qsort(array->contents, DArray_count(array), sizeof(void*), cmp);
	return 0;
}