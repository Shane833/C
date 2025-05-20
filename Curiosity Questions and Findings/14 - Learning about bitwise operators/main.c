#include <stdio.h>

int main(int argc, char* argv[])
{
	/* BITWISE AND OPERATION */
	// We use this to check if a particular bit is set or not
	int a = 2, b = 4;

	// Binary representation of 2 : 0010
	// Binary representation of 4 : 0100
	// 2 & 4 : 0, as none of the bits were matched

	// Binary representation of 2 : 0010
	// Binary representation of 3 : 0011
	// We can check if the second bit was set or not
	// 2 & 3 : 2, which is a positive no. depicting the second 
	// bit was set and this process is called bit-masking

	printf("%d & %d : %d\n", a, b, a&b);

	/* BITWISE OR OPERATION */
	int c = 5, d = 3;

	// Binary representation of 5 : 0101
	// Binary representation of 3 : 0011
	// 5 | 3 : 7


	printf("%d | %d : %d\n", c, d, c | d);

	/* BITWISE SHIFT OPERATION*/

	// 1. BITWISE LEFT SHIFT
	// This operator shifts the bits in the binary string to the left
	// and the discarded bits are filled with 0s

	int e = 2;
	int shift = 1;

	// Binary representation of 2 : 0010
	// 2 << 1 : 0100

	printf("%d << %d : %d\n", e, shift, e << shift); // shifting the bits by 1 digit

	// You can provide the no. bits to be shifted as the second operand to the << operator

	// 2. BITWISE RIGHT SHIFT
	// This operator shifts the bits in the binary string to the right
	// and the discarded bits are filled with 0s

	return 0;
}