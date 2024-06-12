#include <Sorting.h>

bool bubble_sort(void** array, size_t size, Compare cmp)
{
	check(array != NULL, "Can't sort a NULL pointed array!");
		
	bool swapped = true;
	unsigned int pass = 0;
	unsigned int index = 0;
	
	for(pass = 0; pass < size && swapped; pass++){ // n - 1 pass to sort the array
		swapped = false;
		for(index = 0; index < size - pass - 1; index++){ // excluding last element with each pass
			if(cmp(array[index], array[index + 1]) > 0){
				swap(array, index, index + 1);
				swapped = true;
			}
		}
	}
	
	return true;
error:
	return false;
} 

bool selection_sort(void** array, size_t size, Compare cmp) // Declare a minimum at the start of each loop and swap it if it changes
{
	check(array != NULL, "Can't sort a NULL pointed array!");
	
	unsigned int pass = 0;
	unsigned int index = 0;
	unsigned int min = 0;
	
	for(pass = 0; pass < size; pass++){
		min = pass;
		for(index = pass + 1;index < size; index++){ // Here we compare with each value but only swap once 
			if(cmp(array[min], array[index]) > 0){
				min = index;
			}
		}
		if(min == pass) continue; // array has been sorted
		else swap(array, min, pass); // else swap the values
	}

	return true;
error:
	return false;
}

bool insertion_sort(void** array, size_t size, Compare cmp) // Here we keep inserting the elements in a sorted manner
{
	check(array != NULL, "Can't sort a NULL pointer array!");
	
	unsigned int pass = 0;
	unsigned int index = 0;
	
	for(pass = 1; pass < size; pass++){
		for(index = pass; index > 0 && (cmp(array[index - 1],array[index]) > 0); index--){ // Continously move the element until it is in the right position
			swap(array, index, index - 1);
		}
	}
	
	return true;
error:
	return false;
}

static void sort_and_merge(void** array, unsigned int low, unsigned int middle, unsigned int high, Compare cmp)
{
	// Counter / index
	int i = 0; 
	int j = 0;
	
	// Temporary buffers (need to be queues, and thats why I'm halting its production for now)
	void* left[middle - low + 1];
	void* right[high - middle]; // Why is the right size high - middle ?
	
	// Copying data into the buffers
	for(i = low,j = 0;i <= middle;i++,j++){
		left[j] = array[i];
	}
	for(i = middle + 1,j = 0;i <= high;i++,j++){
		right[j] = array[i];
	}
	
	printf("Left Array before : ");
	for(int i = 0;i < middle - low + 1; i++){printf("%d ", left[i]);}
	printf("\n");
	
	printf("Right Array before : ");
	for(int i = 0;i < high - middle; i++){printf("%d ", right[i]);}
	printf("\n");
	
	// Sort and add back into the original array
	for(i = low, j = 0; j < middle - low + 1;j++){
		if(cmp(left[j], right[j]) < 0){
			array[i++] = left[j];
			left[j] = -1;
		}else{
			array[i++] = right[j];
			right[j] = -1;
		}
	} 
	
	printf("Left Array after : ");
	for(int i = 0;i < middle - low + 1; i++){printf("%d ", left[i]);}
	printf("\n");
	
	printf("Right Array after : ");
	for(int i = 0;i < high - middle; i++){printf("%d ", right[i]);}
	printf("\n");
	
	
	// Now copy the additional elements which are left, from both the temporary arrays
	for(int index = 0;index < middle - low + 1; index++){
		if(left[index] != -1){
			array[i++] = left[index];
		}
	}
	for(int index = 0;index < high - middle; index++){
		if(right[index] != -1){
			array[i++] = right[index];
		}
	}
	
	printf("Main Array : ");
	for(int i = low; i <= high;i++){
		printf("%d ", array[i]);
	}
	printf("\n");
	
}

static void divide(void** array, unsigned int low, unsigned int high, Compare cmp)
{
	// 1. Display the array as is
	// 2. calculate the mid point and call the function with that again
	// 3. defined a base case to exit out of the function
	
	if(low >= high) return;
	
	int mid = low + (high - low) / 2; // protects from integer overflow
	
	divide(array, low, mid, cmp);
	divide(array, mid + 1, high, cmp);
	sort_and_merge(array, low, mid, high, cmp);
}

bool merge_sort(void** array, size_t size, Compare cmp)
{
	printf("Original Array : ");
	for(int i = 0;i < size;i++){
		printf("%d ", array[i]);
	}
	printf("\n");
	
	divide(array, 0, size - 1, cmp);
}

