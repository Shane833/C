#include <stdio.h>

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

void countingSort(int* arr, int* output, size_t n)
{
	// 1. Find the max element
	const int k = findMax(arr,n);
	
	// 2. Create two array count and output of size k+1
	int count[k+1];
	// 2.1 for the count array Set all the digits to 0
	for(int i = 0;i < k+1;i++){
		count[i] = 0;
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
}

int main(int argc, char* argv[])
{
	int arr[5] = {3,4,1,6,2};
	int output[5] = { 0 };
	
	countingSort(arr, output, 5);
	
	for(int i = 0;i < 5;i++){
		printf("%d ", output[i]);
	}
	
	return 0;
}