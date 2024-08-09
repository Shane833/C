#include <stdio.h>

// Lets see how big is a long

int main(int argc, char* argv[])
{
	// for 32 bit systems : 4, 4, 8
	printf("Size of a long: %d\n", sizeof(long));
	printf("Size of a unsigned long: %d\n", sizeof(unsigned long));
	printf("Size of a long long: %d\n", sizeof(long long));
}