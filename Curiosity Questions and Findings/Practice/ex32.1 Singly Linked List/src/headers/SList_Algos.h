#ifndef __SLIST_ALGOS_H__
#define __SLIST_ALGOS_H__

#include <SList.h>
#include <stdbool.h>

typedef int (*SList_compare) (const void* a, const void* b);

bool SList_bubble_sort(SList* list, SList_compare cmp);


#endif