#include <lcthw/list.h>
// Written after learning about the og way

typedef List Queue;

#define Queue_create List_create
#define Queue_destroy List_destroy
#define Queue_send List_push
#define Queue_recv List_shift
#define Queue_peek List_first
#define Queue_count List_count

#define QUEUE_FOREACH(A, V) LIST_FOREACH(A, last, prev, V)	