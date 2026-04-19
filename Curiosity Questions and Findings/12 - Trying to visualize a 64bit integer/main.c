#include <stdio.h>
#include <stdint.h>

int main()
{
	
	uint64_t b = 456;
	uint32_t* p = (uint32_t*)&b;
	printf("%b\n",((uint8_t*)p)[0]);
	printf("%b\n",((uint8_t*)p)[1]);
	printf("%b\n",((uint8_t*)p)[2]);
	printf("%b\n",((uint8_t*)p)[3]);
	return 0;
}
