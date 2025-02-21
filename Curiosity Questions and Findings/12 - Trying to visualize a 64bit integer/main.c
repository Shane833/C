#include <stdio.h>
#include <stdint.h>

int main()
{
	
	uint64_t b = 456;
	uint32_t* p = &b;
	printf("%u",((uint8_t*)p)[3]);
	return 0;
}