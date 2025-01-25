#include <stdio.h>
#include <stdint.h>

int main(int argc, char* argv[])
{
	uint16_t data = 259;
	
	uint16_t* p = &data;
	
	printf("1st Byte : %d\n", ((uint8_t*)p)[0]); 
	printf("2nd Byte : %d\n", ((uint8_t*)p)[1]);
	printf("3rd Byte (undefined) : %d\n", ((uint8_t*)p)[2]);
	
	// All the expression are evaluted from right to left
	// (uint8_t*)p[0] = dereference first and then cast
	// ((uint8_t*)p)[0] = cast first then dereference
	
	// a[i] = *(a + i)
	
	
	return 0;
}