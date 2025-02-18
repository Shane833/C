#include <stdio.h>
#include <math.h>

// So in order to understand radix sort I must understand count sort first

// COUNTING SORT
// 1. Function to compute the max (k)
int findMax(int arr[], size_t n)
{
	int max = arr[0];
	for(int i = 1; i < n;i++){
		if(arr[i] > max)
			max = arr[i];
	}
	
	return max;
}
// 2. Counting Sort function

void countingSort(int* arr, size_t n)
{
	// 1. Find the max element
	const int k = findMax(arr,n);
	
	// 2. Create two array count and output of size k+1
	int count[k+1];
	int output[n];
	// 2.1 for the count array Set all the digits to 0
	for(int i = 0;i < k+1;i++){
		count[i] = 0;
	}
	for(int i = 0;i < n;i++){
		output[i] = 0;
	}
	
	// 3. to obtain the count of each key in the input array
	for(int i = 0,j = 0;i < n;i++){
		j = arr[i];
		count[j] = count[j] + 1;
	}
	
	// 4. Obtain the prefix sum of the occurences of the keys in the count array
	// which obtains the position of the elements in the input array
	for(int i = 1;i < k+1;i++){
		count[i] = count[i] + count[i-1];
	}
	
	// 5. Now we convert the positions to indexes and then simply return the sorted array
	for(int i = n - 1, j = 0; i >= 0;i--){
		j = arr[i];
		count[j] = count[j] - 1; // convert the position to index
		output[count[j]] = arr[i];
	} 
	
	// 6. copy the sorted array from output to arr
	for(int i = 0;i < n;i++){
		arr[i] = output[i];
	}
}

// Special implementation of count sort for being used in radix sort
void countsortRadix(int* arr, size_t n, int digit_place)
{
	// Obtain the max
	int count[10] = { 0 };
	int output[n];
	
	// initialize output to zeroes
	for(int i = 0;i < n;i++){
		output[i] = 0;
	}
	
	// Count the occurences
	for(int i = 0,j = 0;i < n;i++){
		j = (int)(arr[i] / (int)pow(10, digit_place)) % 10; // obtaining the key based on the place of digit
		count[j] = count[j] + 1;
	}
	
	// Obtain the prefix sum
	for(int i = 1;i < 10;i++){
		count[i] = count[i] + count[i-1];
	}
	
	// Map the position into indexes in the output array
	// NOTE : don't forget to start the loop in reverse to make it stable
	for(int i = n - 1,j = 0;i >= 0;i--){
		j = (int)(arr[i] / (int)pow(10, digit_place)) % 10;
		count[j] = count[j] - 1;
		output[count[j]] = arr[i];
	}
	
	// copy the output array into arr
	for(int i = 0;i < n;i++){
		arr[i] = output[i];
	}
	
}

// Radix sort
void radixSort(int* arr, size_t n)
{
	// Find the max element
	int max = findMax(arr, n);
	// Compute the no. of digits
	int no_of_digits = 1;
	while(max / (int)pow(10, no_of_digits) != 0){
		no_of_digits++;
	}
	// Perform count sort on all the places of the digits
	for(int digit_place = 0; digit_place < no_of_digits; digit_place++){
		countsortRadix(arr, n, digit_place);
	}
	
	
}

int main(int argc, char* argv[])
{
	int arr[5] = {32,415,100,6,29};
	
	radixSort(arr, 5);
	
	for(int i = 0;i < 5;i++){
		printf("%d ", arr[i]);
	}
	
	return 0;
}