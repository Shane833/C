#include "QSort.h"

static int partition(void** array, int low, int high, Compare cmp);

void quicksort(void** array, int low, int high, Compare cmp)
{
	if(!(low < high)) return; // If low is not less than high than return
	
	int pivot = partition(array, low, high, cmp);
	quicksort(array, low, pivot - 1, cmp);
	quicksort(array, pivot + 1, high, cmp);
	
}

static int partition(void** array, int low, int high, Compare cmp)
{
	// This approach takes a O(n^2) time
	/*
	int left = low;
	int right = high;
	int pivot_pos = low;
	
	while(left < right){
		while(cmp(array[left], array[pivot_pos]) <=  0) left++;
		while(cmp(array[right], array[pivot_pos]) > 0) right--;
		if(left < right) swap(array, left, right);
	}
	
	swap(array, low, right);
	
	return right;
	*/
	
	// This is a linear approach
	int pivot = high;
	int first_high = low;
	
	// Using this loop we simply shift all the elements greater than pivot to the right and all smaller to the left 
	// as we keep on iterating
	
	for(int i = low; i < high; i++){
		if(cmp(array[i], array[pivot]) <= 0){
			swap(array, i, first_high);
			first_high++;
		}
	}
	swap(array, first_high, pivot);
	return first_high;
}
