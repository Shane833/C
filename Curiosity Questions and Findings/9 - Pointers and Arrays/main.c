#include <stdio.h>
#include <stdint.h>

int main(int argc, char* argv[])
{
	uint32_t data = 123456;
	
	uint32_t* p = &data;
	
	printf("%d\n", *(uint8_t*)p[6]);
	
	return 0;
}