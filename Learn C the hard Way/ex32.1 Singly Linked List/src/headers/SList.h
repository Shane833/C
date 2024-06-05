#ifndef __SLIST_H__
#define __SLIST_H__

#include <stdlib.h>
#include <dbg.h>

// The single linked list node
typedef struct SListNode{
	struct SListNode* next;
	void* value;
}SListNode;

// The Singly linked list
typedef struct SList{
	SListNode* first;
	size_t count;
}SList;

SList* SList_create(); // Returns a newly created list
void SList_destroy(SList* list); // Deallocates memory from the list
void SList_clear(SList* list); // clears the values from the list
void SList_clear_destroy(SList* list); // combines both the functions into ones

#define SLIST_COUNT(A) ((A)->count) // returns the no. of nodes in the list
#define SLIST_FIRST(A) ((A)->first != NULL ? (A)->first->value : NULL)

void SList_push(SList* list, void* value); // inserts the nodes in the list
void* SList_pop(SList* list); // removes the last element from the list
void SList_shift(SList* list, void* value); // inserts value in the beginning
void* SList_unshift(SList* list); // removes the node at the beginning

void* SList_remove(SList* list, SListNode* node); // removes any given node

// Handy macro to traverse the list
#define SLIST_FOREACH(L, S, M, V) SListNode* _node = NULL;SListNode* V = NULL;\
for(V = _node = L->S; _node !=  NULL; V = _node = _node->M)
	
#endif