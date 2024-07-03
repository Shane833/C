#include <stdio.h>
#include <Heap.h>

int main(int argc, char* argv[])
{
	//int array[7] = {7,5,6,1,4,2,3};
	int array[7] = {1,2,3,4,5,6,7};
	Heap heap;
	Heap_Initialize(&heap);
	
	Heap_MakeHeap(&heap, array, 7);
	
	// Test for the new heap functions
	for(int i = 1;i < Heap_Count(&heap);i++)
		printf("Child :%d, Parent %d\n",heap.array[i], heap.array[Heap_Parent(&heap, i)]);
	
	
	
	// OLD TESTS WITH SIMPLE ARRAY AND OLD HEAP FUNCTIONS
	/*
	for(int i = 0;i < 3;i++){ // Since there are 3 levels : 0, 1, 2
		printf("Root : %d, ",array[i]);
		printf("Left Child : %d, ", array[Heap_LeftChild(i)]);
		printf("Right Child : %d\n", array[Heap_RightChild(i)]);
	}
	
	for(int i = 6;i > 0;i--){ // only going till index 1, since at 0 its the root having no parent
		printf("Child : %d, Parent : %d\n",array[i], array[Heap_Parent(i)]);
	}
	*/
	
	
	return 0;
}

