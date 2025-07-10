#include <murmur3.h>


static inline uint32_t murmur32_scramble(uint32_t k)
{
	k *= 0xcc9e2d51;
	k = (k << 15) | (k >> 17);
	k *= 0x1b873593;
	return k;
}

uint32_t murmur3_32(void * key, size_t len)
{
	hash = 0; // Starts with a seed
	uint32_t k = 0;

	
}