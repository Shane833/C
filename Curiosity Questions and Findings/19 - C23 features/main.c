#include <stdio.h>
#include <stddef.h>

int main()
{
	int * p = nullptr; // nullptr is now a constant in C23

	int a = 23;

	//nullptr_t pnull;

	// printf("%p",pnull);	

	typeof(p) b = &a; // typeof b is int*



	return 0;
}