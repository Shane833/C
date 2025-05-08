#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <lcthw/radixmap.h>
#include <lcthw/dbg.h>

// Function to initialize and create a radixmap
RadixMap* RadixMap_create(size_t max)
{
	// Allocating memory to the whole map
	RadixMap* map = calloc(1, sizeof(RadixMap));
	check_mem(map);
	
	// Allocating memory to our contents union
	map->contents = calloc(max + 1, sizeof(RMElement));
	check_mem(map->contents);
	
	// Allocating memory to our temp union
	map->temp = calloc(max + 1, sizeof(RMElement));
	check_mem(map->temp);
	
	// initiliazing the max as per the user
	map->max = max;
	map->end = 0; // initializing end to 0 well bcz its the index of the first element
	
	return map; // simply return the map
error:
	return NULL;
}

// Function to free the dynamic memory from the map
void RadixMap_destroy(RadixMap* map)
{
	// Simply check if the memory exists
	if(map){
		// and if it does then simply free it
		free(map->contents);
		free(map->temp);
		free(map);
	}
}

// Handy macro for retreiving the values of the bytes
#define ByteOf(x,y) (((uint8_t*)x)[(y)])

static inline void radix_sort(short offset, uint64_t max, uint64_t* source, uint64_t* dest)
{
	// This array will hold the count/occurences of all the values of bytes i.e. from 0-255
	// i.e. we count which bytes contains a specific value from 0-255
	uint64_t count[256] = { 0 };
	
	uint64_t* cp = NULL; // This is the count pointer, pointing to the count array
	uint64_t* sp = NULL; // This is the source pointer, pointing to the source 
	uint64_t* end = NULL; // End pointer to keep us in bounds
	uint64_t s = 0;
	uint64_t c = 0;
	
	// count occurences of every byte value
	for(sp = source, end = source + max; sp < end; sp++){
		count[ByteOf(sp, offset)]++; // frequency of Byte = sp[offset]
		// Equivalent to:
		// uint64_t j = ByteOf(sp, offset); 
		// count[j] = count[j] + 1;
	}
	
	// for debug purposes
	for(int i = 0;i < 256;i++){
		printf("%dth byte : %ld\n", i, count[i]);
	}
	
	// transform count into index by summing
	// elements and storing into same array
	for(s = 0, cp = count, end = count + 256; cp < end; cp++){
		c = *cp;
		*cp = s;
		s += c;
	}
	
	// fill dest with right values in the right place
	// We simply obtain the count of the value at address (base_count + sp(basically our element))
	// Which provides us the index at which the value of sp is to be stored in the destination array
	// Then we increment the value at cp by 1 to handle the case if there are multiple values
	for(sp = source, end = source + max; sp < end; sp++){
		cp = count + ByteOf(sp, offset);
		dest[*cp] = *sp;
		++(*cp);
	}
}

void RadixMap_sort(RadixMap* map)
{
	uint64_t* source = &map->contents[0].raw;
	uint64_t* temp = &map->temp[0].raw;
	
	// Sorting the Keys
	// Since we are sorting one byte at a time and there are 4 bytes (32bits) in total
	// Hence we offset the bytes by 4 indices and sort them individually
	// We go back and forth between changing the src and dest arrays
	radix_sort(0, map->end, source, temp); 
	radix_sort(1, map->end, temp, source);
	radix_sort(2, map->end, source, temp);
	radix_sort(3, map->end, temp, source);
	// and at the end we have sorted all of the keys based on the 4 bytes
}

RMElement* RadixMap_find(RadixMap* map, uint32_t to_find)
{
	// Simple binary search algorithm
	int low = 0;
	int high = map->end - 1;
	RMElement* data = map->contents;
	
	while(low <= high){
		int middle = low + (high - low) / 2;
		uint32_t key = data[middle].data.key;
		
		if(to_find < key){
			high = middle - 1;
		}
		else if(to_find > key){
			low = middle + 1;
		}
		else{
			return &data[middle];
		}	
	}
	
	return NULL;
}

int RadixMap_add(RadixMap* map, uint32_t key, uint32_t value)
{
	// We put a condition that the values in the key must always
	// be less than and not equal to UINT32_MAX and if it ain't
	// then that key is not considered valid
	check(key < UINT32_MAX, "Key can't be equal to UINT32_MAX.");
	
	RMElement element = {.data = {.key = key, .value = value} };
	check(map->end + 1 < map->max, "RadixMap is full");
	
	// we add the element to the end of the map then
	// we increment end and resort the order of the elements
	map->contents[map->end++] = element;
	
	RadixMap_sort(map);
	
	return 0;
error:
	return -1;
}

int RadixMap_delete(RadixMap* map, RMElement* el)
{
	check(map->end > 0, "There is nothing to delete");
	check(el != NULL, "Can't delete a NULL element");
	
	// We set the key of that element to max value of uint32_t 
	// When sorted this will push the element to the end of the map
	// and since we can only add keys less than UINT32_MAX it will
	// act as if it has been deleted
	el->data.key = UINT32_MAX;
	
	if(map->end > 1){
		// don't bother resorting a map of 1 length
		RadixMap_sort(map);
	}
	
	map->end--;
	
	return 0;
error:
	return -1;
}

