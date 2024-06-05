#include  <SList.h>

// Function definitions
SList* SList_create()
{
	return calloc(1, sizeof(SList));
}

void SList_push(SList* list, void* value)
{
	check(list != NULL, "Invalid List!");
	
	SListNode* node = calloc(1, sizeof(SListNode));
	check(node != NULL, "Failed to create node");
	node->value = value;
	
	if(list->first == NULL){ // if the list is empty then make it the first
		list->first = node;
		list->first->next = NULL;
	}
	else{
		SListNode* last = NULL;
		for(SListNode* V = list->first; V != NULL; V = V->next){
			if(V->next == NULL){
				last = V;
				break;
			}
		}
		last->next = node;
	}
	
	list->count++;
	
error:
	return;
}

void* SList_pop(SList* list)
{
	check(list != NULL, "Invalid list");
	
	void* value = NULL;
	
	if(list->first == NULL){
		return NULL; // empty list
	}
	else if(list->first->next == NULL){ // checking for single element list
		value = list->first->value;
		free(list->first);
		list->first = NULL;
	}
	else{
		SListNode* second_last = NULL;
		SListNode* last = NULL;
		
		SLIST_FOREACH(list, first, next, cur){
			if(cur->next->next == NULL){
				second_last = cur;
				last = cur->next;
				break;
			}
		}
		second_last->next = NULL;
		value = last->value;
		free(last);
		last = NULL;
	}
	
	list->count--;
	return value;
error:
	return NULL;
}

void SList_destroy(SList* list)
{
	check(list != NULL, "Invalid List");
	
	SListNode* prev = list->first;
	
	for(SListNode* cur = list->first->next; cur != NULL; cur = cur->next){
		free(prev);
		prev = cur;
	}

	free(prev);	
	free(list);
error:
	return;
}

void SList_clear(SList* list)
{
	check(list != NULL, "Invalid List");
	
	SLIST_FOREACH(list, first, next, cur){
		free(cur->value);
		cur->value = NULL;
	}

error:
	return;
}

void SList_clear_destroy(SList* list)
{
	check(list != NULL, "Invalid List");
	SList_clear(list);
	SList_destroy(list);
	
error:
	return;
}

void SList_shift(SList* list, void* value)
{
	check(list != NULL, "Invalid List");
	
	SListNode* node = calloc(1, sizeof(SListNode));
	node->value = value;
	
	if(list->first == NULL){
		list->first = node;
	}
	else{
		node->next = list->first;
		list->first = node;
	}
	
	list->count++;
error:
	return;
}

void* SList_unshift(SList* list)
{
	check(list != NULL, "Invalid List");
	void* value = NULL;
	
	if(list->first == NULL){
		
	}
	else{
		SListNode* node = list->first;
		list->first = list->first->next;
		value = node->value;
		node->next = NULL;
		
		free(node);
	}
	
	list->count--;
	return value;
error:
	return NULL;
}