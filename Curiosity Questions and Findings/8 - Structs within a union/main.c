#include <stdio.h>
#include <stdint.h>

typedef union Test{
	int16_t raw;
	struct{
		int8_t key;
		int8_t value;
	}data;
}Test;

int main(int argc, char* argv[])
{
	Test t = {.raw = 129};
	
	// 8 bits = 0 - 255 (256 values)
	// printf("%d\n", 300 % 256);
	
	
	printf("Raw Value : %d\n", t.raw);
	printf("Key : %d\n", t.data.key);
	printf("Value : %d\n", t.data.value);
	return 0;
}