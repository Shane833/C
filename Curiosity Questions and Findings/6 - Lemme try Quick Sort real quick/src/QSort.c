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
	// This approach takes a O(n^2) time // Wrong this is still a O(n) solution, don't assume 2 loops means O(n^2)
	// and even better as there are fewer no. of swaps as they are done only when necessary
	int left = low;
	int right = high;
	int pivot_pos = low;
	
	while(left < right){
		while(cmp(array[left], array[pivot_pos]) <=  0) left++; // Finding the element that is greater than pivot but present on its left side - done in O(n) time
		while(cmp(array[right], array[pivot_pos]) > 0) right--; // Finding the element that is smaller than pivot but present on its right side - done in O(n) time
		if(left < right) swap(array, left, right); // If we find such elements we bring the smaller element (j) to the left of pivot and larger element (i) to the right of the pivot
	}

	// So total time complexity = O(n) + O(n) => O(n)
	
	swap(array, low, right); // Placing the pivot at its correct position in the array
							 // At the end all the smaller elements are present on the left of the pivot
							 // and all the larger elements are present to the right of the pivot

	return right;
	
	/*
	// This is a linear approach, This is runs comparitively slower even though being O(n)
	// because swaps are done almost in every iteration and it goes through the entirity of the array
	// while the above solution ends quickly 
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
	*/
}
