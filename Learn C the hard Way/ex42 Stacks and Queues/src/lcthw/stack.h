#include <lcthw/dbg.h>
#include <lcthw/list.h>

// THIS IS MY IMPLEMENTATION (NOOB WAY)

// Lets define our Stack
// We will just create a list data structure
// Since it will handle all of the other operation for us
typedef struct Stack{
	List* data;
}Stack;

// Function to create the stack
Stack* Stack_create()
{
	// Allocating the base stack
	Stack* stack = calloc(1, sizeof(Stack));
	check_mem(stack);
	
	// Creating the list within
	stack->data = List_create();
	check_mem(stack->data);
	
	return stack;
error:
	return NULL;
}

// Function to deallocate/destroy stack
void Stack_destroy(Stack* stack)
{
	if(stack){
		List_destroy(stack->data);
		free(stack);
	}
}

#define Stack_count(A) (List_count(A->data))

#define STACK_FOREACH(A, V) ListNode* _node = NULL; ListNode* V = NULL;\
for(_node = V = A->data->first; _node != NULL; V = _node = _node->next)

#define Stack_peek(A) (List_first(A->data))

// Function to push the element
void Stack_push(Stack* stack, void* element)
{
	check(stack != NULL, "Invalid Stack");
	List_unshift(stack->data, element);
	
error: // Fallthrough
	return;
}

// Function to pop the element
void* Stack_pop(Stack* stack)
{
	check(stack != NULL, "Invalid Stack");
	return List_shift(stack->data);
error:
	return NULL; 
}


