#include <SList.h>
#include <SList_Algos.h>
// Testing

int increasing_order(const void* a, const void* b)
{
	return a - b;
}

int main(int arg, char* argv[])
{
	SList* list = SList_create();
	check(list != NULL, "Failed to create list");
	printf("Works\n");

	SList_shift(list, 1);
	SList_shift(list, 2);
	SList_shift(list, 3);
	SList_shift(list, 4);
	
	check(SList_bubble_sort(list, increasing_order) != false, "Bubble sort unsuccessful");
	
	SLIST_FOREACH(list, first, next, cur){
		printf("%d ", cur->value);
	}
	
	
	
	return 0;
error:
	return 1;
}