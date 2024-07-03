#include <Heap.h>

// Washed out debug macro from the dbg.h
#define check(A, M, ...) if(!(A)){fprintf(stderr, "[ERROR] %s:%d : " M "\n", __FILE__, __LINE__, ##__VA_ARGS__); goto error;}

// Function to swap the elements of heap
static void Heap_Swap(Heap* heap, int a_index, int b_index)
{
	int temp = heap->array[a_index];
	heap->array[a_index] = heap->array[b_index];
	heap->array[b_index] = temp;
}

// Declared static so that can't be used outside of the file
static void Heap_BubbleUp(Heap* heap, int element_index)
{
	if(Heap_Parent(heap, element_index) == -1) return; // as the root would have no parent 
	
	// If it is greater than its parent than we swap them 
	if(heap->array[element_index] > heap->array[Heap_Parent(heap, element_index)])
	{
		Heap_Swap(heap, element_index, Heap_Parent(heap, element_index));
		// call the function again with the parent
		Heap_BubbleUp(heap, Heap_Parent(heap, element_index));
	}
}


// Function Definitions
void Heap_Initialize(Heap* heap)
{
	check(heap != NULL, "Invalid Heap!");
	// set the heap end to be zero
	heap->end = -1;
	
error: // fallthrough
	return;
}

int Heap_Parent(Heap* heap,int child_index)
{
	check(heap != NULL, "Invalid Heap!");
	check(child_index <= heap->end, "Invalid Child Index!");
	if(child_index <= 0) goto error;
		
	return ((int)((child_index - 1) / 2)); // Specifically taking the floor 
error:
	return -1;
}

int Heap_LeftChild(Heap* heap, int parent_index)
{
	check(heap != NULL, "Invalid Heap!");
	check(parent_index <= heap->end,"Invalid Child Index!");
	
	int child_index  = 2 * parent_index + 1;
	if(child_index > heap->end) goto error;

	return child_index;
error:
	return -1;
}

int Heap_RightChild(Heap* heap, int parent_index)
{
	check(heap != NULL, "Invalid Heap!");
	check(parent_index <= heap->end,"Invalid Child Index!");
	
	int child_index  = 2 * parent_index + 2;
	if(child_index > heap->end) goto error;

	return child_index;
error:
	return -1;	
}

void Heap_Insert(Heap* heap, int element)
{
	check(heap != NULL, "Invalid Heap!");
	
	heap->end++;
	heap->array[heap->end] = element;
	Heap_BubbleUp(heap, heap->end);
	
error: // fallthrough
	return;
}

void Heap_MakeHeap(Heap* heap, int* array, size_t size)
{
	check(heap != NULL, "Invalid Heap!");
	
	for(int i = 0;i < size;i++){
		Heap_Insert(heap, array[i]);
	}

error: // fallthrough
	return;
}

