#include <stdlib.h>
#include <stdio.h>

int* addr()
{
	int* p = (int*)malloc(sizeof(int));
	*p = 10;

	return p;
}

int main()
{
	// So when I write a function like int* returnsomething()
	// According to me I'm returning a pointer to an integer
	// so I must be able to treat it like a pointer to an integer I suppose

	printf("%d\n", *(addr())); // yes so I was able to deference it bcz it basically behaves like a pointer to an int
	printf("%p\n", (addr()));
	// printf("%p\n", &(addr())); this throws an error saying lvalue required by & operator
	// and it is valid bcz functions only return things they can't be assigned values so there memory address is 
	// not really required

	// But maybe we can deferene the pointer returned by the function and then try to find its address
	printf("%p\n",&(*(addr()))); // works but here i'm not quering the same pointer by calling the function 3 times 
	// I have created 3 different pointers
	return 0;
}