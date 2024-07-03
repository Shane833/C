#include <Heap.h>

// Washed out debug macro from the dbg.h
#define check(A, M, ...) if(!(A)){fprintf(stderr, "[ERROR] %s:%d : " M "\n", __FILE__, __LINE__, ##__VA_ARGS__); goto error;}

// Function declarations
static void Heap_Swap(Heap* heap, int a_index, int b_index);
static void Heap_BubbleUp(Heap* heap, int element_index);
static void Heap_BubbleDown(Heap* heap, int parent_index);


// Function to swap the elements of heap
static void Heap_Swap(Heap* heap, int a_index, int b_index)
{
	int temp = heap->array[a_index];
	heap->array[a_index] = heap->array[b_index];
	heap->array[b_index] = temp;
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
	check(parent_index <= heap->end,"Invalid Parent Index!");
	
	int child_index  = 2 * parent_index + 1;
	if(child_index > heap->end) goto error;

	return child_index;
error:
	return -1;
}

int Heap_RightChild(Heap* heap, int parent_index)
{
	check(heap != NULL, "Invalid Heap!");
	check(parent_index <= heap->end,"Invalid Parent Index!");
	
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

void Heap_MakeHeap(Heap* heap, int* array, size_t size)
{
	check(heap != NULL, "Invalid Heap!");
	
	for(int i = 0;i < size;i++){
		Heap_Insert(heap, array[i]);
	}

error: // fallthrough
	return;
}

int Heap_Remove(Heap* heap)
{
	check(heap != NULL, "Invalid Heap!");
	check(Heap_Count(heap) > 0, "Invalid Operation!");

	int dominant = heap->array[0];
	// replace the element at 0th index with the last one
	// and decrease the size of the heap
	heap->array[0] = heap->array[heap->end--];
	// Now to shift down this element at its right position
	Heap_BubbleDown(heap, 0);
	
	return dominant;
error:
	return -1;
}

static void Heap_BubbleDown(Heap* heap, int parent_index)
{
	if(Heap_Count(heap) == 0) return; // case when only one element remains

	int dominant = parent_index; // dominant element index to swap with, we assume the parent is 
								// at its right place in the heirarchy and then swap it 
	// lets obatin the children of the parent
	// and compare both of the children with the parent for dominance
	if(Heap_LeftChild(heap, parent_index) != -1){
		dominant = heap->array[parent_index] < heap->array[Heap_LeftChild(heap, parent_index)] ? Heap_LeftChild(heap, parent_index) : parent_index;
	}
	if(Heap_RightChild(heap, parent_index) != -1){
		dominant = heap->array[dominant] < heap->array[Heap_RightChild(heap, parent_index)] ? Heap_RightChild(heap, parent_index) : dominant;
	}
	
	if(dominant != parent_index){ // if the parent is still the dominant one
		// now to swap this with the parent
		Heap_Swap(heap, dominant, parent_index);
		// now calling the same function with the new parent index
		Heap_BubbleDown(heap, dominant);
	}

}

void Heap_Sort(int* array, size_t size)
{
	// First create the heap
	Heap heap;
	Heap_Initialize(&heap);
	
	// Lets create the heap from the array
	Heap_MakeHeap(&heap, array, size);
	
	// Now lets repeatedly remove elments into the array
	for(int i = 0;i < size;i++){
		array[i] = Heap_Remove(&heap);
	}
}

