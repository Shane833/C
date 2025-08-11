#include <stdio.h>

int main()
{
	// use format specifier
	// %#b - for binary
	// %#o - for octal
	// %#x - for hex

	printf("%#b %#o %#x\n", 29, 29, 29);

	// Binary is not supported by gcc yet
}