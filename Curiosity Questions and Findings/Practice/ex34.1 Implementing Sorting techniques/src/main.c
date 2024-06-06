#include <darray.h>
#include <darray_algos.h>
// Testing

int increasing_order(const void* a, const void* b)
{
	return a - b;
}

void display(DArray* array)
{
	for(int i = 0;i < array->end;i++){
		printf("%d ",DArray_get(array, i));
	}
	printf("\n");
}

int main(int arg, char* argv[])
{
	DArray* array = DArray_create(sizeof(int), 10);
	check(array != NULL, "Something went wrong");
	
	DArray_push(array,10);
	DArray_push(array,9);
	DArray_push(array,8);
	DArray_push(array,7);
	DArray_push(array,6);
	DArray_push(array,5);
	DArray_push(array,4);
	DArray_push(array,3);
	DArray_push(array,2);
	
	display(array);
	
	bool r = DArray_bubble_sort(array, increasing_order);
	check(r == true, "Bubble sort failed");
	
	display(array);	
	
	return 0;
error:
	return 1;
}