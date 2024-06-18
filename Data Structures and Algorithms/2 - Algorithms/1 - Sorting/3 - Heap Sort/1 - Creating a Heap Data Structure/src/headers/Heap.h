#ifndef __HEAP_H__
#define __HEAP_H__

#define MAX_SIZE 10

typedef struct Heap{
	int array[MAX_SIZE];
	int end;
}Heap;

Heap* Heap_Create();


#endif