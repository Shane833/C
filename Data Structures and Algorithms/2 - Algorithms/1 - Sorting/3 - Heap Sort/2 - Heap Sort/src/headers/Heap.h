#ifndef __HEAP_H__
#define __HEAP_H__

#define MAX_SIZE 10

#include <stdio.h>

// Heap Data Strucutre - It can be used to represent a binary tree without using pointers
// with the help of an array where the ROOT is stored at the FIRST position and then
// its LEFT and RIGHT childern in the SECOND and THIRD position respectively.

// Say if we have the position of the parent at k
// then its left child will be at 2k + 1 and right child at 2k + 2

// Constructing the heap - Since we must use the space efficiently therefore we prefer to
// always maintain a complete binary tree, where we keep filling the tree from the left most
// side, also in doing we maintain the structure of the tree but the rules of the heap maybe
// violated as the new child might dominate (greater for max heap or smaller in value for min heap than) its parent
// Therefore we must place it at its right place in the heirarchy after inserting the element
// and this will be done using the bubble up function

// Bubble Up function - This function works recursively and puts the newly inserted element in its right position
// in the heap. So we compare the current element with its parent and depending on the comparison we swap the elements
//  and we recurse until either the condition is satisfied or we reach the root. Now swapping takes constant time and 
// the height of the tree is log(n) for n elements, therefore we can create a heap in O(nlog(n)) time

// Using these two functions we can create a heap from any array

// Extracting the minimum or maximum from the heap depending upon the type of heap, since the most dominant elementt is 
// always at the root of the hoop we can simply remove it but then it will leave a hole in the heap which 
// is to filled by the right most element in the heap or the element at the last position of the heap, however
// this would disrupt the dominance and that element would need to be placed at its right position in the heap.
// so we would need to compare the children and obtain the most dominant of those and replace the parent with that
// and keep continuing this process till we can't find any dominant children which means our element is at its right place
// in the heap.

// Heap Sort - This is a mixture of both creating and removing the elements from the heap. We first make the heap by inserting
// the elements and bubblin them up, and keep on removing them from the heap and inserting them in the array

typedef struct Heap{
	int array[MAX_SIZE];
	int end;
}Heap;

#define Heap_Count(A) (A != NULL ? (A)->end + 1 : -1)

// Heap functions
void Heap_Initialize(Heap* heap);

int Heap_Parent(Heap* heap,int child_index);
int Heap_LeftChild(Heap* heap,int parent_index);
int Heap_RightChild(Heap* heap, int parent_index);

void Heap_Insert(Heap* heap, int element);
void Heap_MakeHeap(Heap* heap, int* array, size_t size);
int Heap_Remove(Heap* heap);

void Heap_Sort(int* array, size_t size);


#endif