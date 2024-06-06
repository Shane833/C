#include <SList_Algos.h>

inline void SList_swap(SListNode* a, SListNode* b)
{
	void* temp = a->value;
	a->value = b->value;
	b->value = temp;
}

bool SList_bubble_sort(SList* list, SList_compare cmp)
{
	check(list != NULL, "Invalid List");

	if(SLIST_COUNT(list) <= 1){
		return 0; // list already sorted
	}
	else{
		bool sorted = false;
		
		while(true){
			sorted = false;
			SLIST_FOREACH(list, first, next, cur){
				if(cur->next){
					if(cmp(cur->value, cur->next->value) > 0){
						SList_swap(cur, cur->next);
						sorted = true;
					}
				}
			}
			if(sorted == false) break;
		}	
	}

	return true;
error:
	return false;
}