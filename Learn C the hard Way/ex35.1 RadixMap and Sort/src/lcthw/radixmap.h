#ifndef _radixmap_h
#define _radixmap_h

#include <stdint.h> // Since we will using exact size integers across all platforms 

// This represents a single element in the radixmap
// We have a union of 2 things : 1. Raw Data (64 bits) 2. A struct (32 bits key, 32 bits value)
typedef union RMElement{
	uint64_t raw;
	struct{
		uint32_t key;
		uint32_t value;
	}data;
}RMElement;

typedef struct RadixMap{
	size_t max;
	size_t end;
	uint32_t counter;
	RMElement* contents;
	RMElement* temp;
}RadixMap;

RadixMap* RadixMap_create(size_t max);

void RadixMap_destroy(RadixMap* map);

void RadixMap_sort(RadixMap* map);

RMElement* RadixMap_find(RadixMap* map, uint32_t key);

int RadixMap_add(RadixMap* map, uint32_t key, uint32_t value);

int RadixMap_delete(RadixMap* map, RMElement* el);

#endif