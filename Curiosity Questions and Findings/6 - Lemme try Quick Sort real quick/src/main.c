#include <stdio.h>
#include "QSort.h"

// Testing the algorithm

int i_asc_order(const int a, const int b)
{
	if(a - b > 0) return 1;
	else if(a - b == 0) return 0;
	else return -1;
}

int f_asc_order(const float a, const float b)
{
	if(a - b > 0.0f) return 1;
	else if(a - b == 0.0f) return 0;
	return -1;
}

int d_asc_order(const double *a, const double *b)
{
	printf("%lf - %lf = %lf\n", *a, *b, *a - *b);
	if(*a - *b > 0.0L) return 1;
	else if(a - b == 0.0L) return 0;
	return -1;
}

void display(void** array, size_t size, size_t element_size)
{
	char* arr = (char*)array;
	for(int i = 0;i < size; i++){
		printf("%d " , *(int*)(arr + i * element_size));
	}
	printf("\n");
}

int is_sorted(void** array, size_t size, size_t element_size, Compare cmp)
{
	char* arr = (char*)array;
	
	for(int i = 0;i < size - 1;i++){
		printf("%p ? %p \n", ((arr + (i * element_size))), ((arr + ((i+1) * element_size)))); // since arr is of type char* , deferencing it would give a char i.e. size = 1 byte
		if(cmp((arr + (i * element_size)), (arr + ((i + 1) * element_size))) > 0) return 0; // I must pass the pointer to the location of the elements and the compare functions must dereference the pointer to get the values
		// bcz if you think about it the array is 
	}
	
	return 1;
}



int main(int argc, char* argv[])
{
	// Seem to work here
	// double d_arr[5] = {3.0L, 2.0L, 7.0L, 5.0L, 9.0L};
	int i_arr[6] = {3, 2, 7, 5, 9, 1};
	
	display(i_arr, sizeof(i_arr)/sizeof(i_arr[0]), sizeof(int));
	quicksort(i_arr, 0, (sizeof(i_arr)/sizeof(i_arr[0])) - 1, (Compare)i_asc_order);
	display(i_arr, sizeof(i_arr)/sizeof(i_arr[0]), sizeof(int));
	
	// printf("Is Sorted ? : %d\n", is_sorted(d_arr, sizeof(d_arr)/sizeof(d_arr[0]), sizeof(double), (Compare)d_asc_order));
	
	
	// swap(d_arr, 1, 3, sizeof(double));
	// display(i_arr, sizeof(i_arr)/sizeof(i_arr[0]), sizeof(int));
	
	return 0;
}

