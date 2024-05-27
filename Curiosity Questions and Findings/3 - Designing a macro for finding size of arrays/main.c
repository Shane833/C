#include <stdio.h>
#include <stdlib.h>

#define GET_ARRAY_SIZE(A) A != NULL ? sizeof(A)/sizeof(A[0]) : -1
// Ok so this only works for local arrays and that too which are statically created

typedef struct Custom{
	int a;
	char b;
	float c;
	double d;
}Custom;

int main(int argc, char* argv[])
{
	int arr[5] = { 0 };
	char* carr = "1234";
	Custom custom[3];
	Custom *new = (Custom*)malloc(3 * sizeof(Custom));
	
	printf("%d\n", GET_ARRAY_SIZE(arr));
	printf("%d\n", GET_ARRAY_SIZE(carr));
	printf("%d\n", GET_ARRAY_SIZE(custom));
	printf("%d\n", GET_ARRAY_SIZE(new)); // Ok so this gives the value of 0
	// The reason it returns a zero is the size of any pointer is 32-bit or 64-bit depending on system
	// Then it doesn't matter if you are refering to a double(8 bytes), custom struct(n bytes) etc.
	// The size of the pointer will only remain of 32 or 64 bits
	
	// Let me see that basically the name of the array is actually a pointer to the first element right ?
	printf("Previous arr: %d\n", arr);
	// Well yes, it is infact a pointer to the first element of the array
	// Ok Let us define another array but this time I will dynamically allocate it using calloc as to emulate an array
	int* darr = (int*)calloc(3, sizeof(int));
	// Now by default the the pointer should be pointing to the first element
	printf("New darr : %d\n", *darr);
	// Now would the size macro work on this
	printf("Size of the darr using macro: %d\n", GET_ARRAY_SIZE(darr));
	// No it don't work in the same manner, I guess it has something to do with
	// how the compiler uses memory allocators and how the memory is maintained on the stack
	
	// So after finding somethings out, the int arr[5], 'arr' is not equivalent to a pointer variable
	// of type int*, however it do points to the first element of the array, but it don't behave like one
	
	// Also, how the sizeof works is completely different for static and dynamic arrays
	// As when you declare an array statically, the compiler knows its size and can return the
	// total memory occupied by the array when using the sizeof
	// However with dynamic arrays the compiler does not know the size of the array ahead of time
	// and hence returns the size occupied by the pointer variable
}