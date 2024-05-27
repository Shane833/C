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
}