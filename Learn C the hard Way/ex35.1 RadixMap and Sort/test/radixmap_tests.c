#include "minunit.h"
#include <lcthw/radixmap.h>
#include <time.h>

static int make_random(RadixMap* map)
{
	size_t i = 0;
	for(i = 0; i < map->max - 1; i++){
		uint32_t key = (uint32_t) (rand() | (rand() << 16)); // shifts the bits by 16 digits and OR the result with another rand call 
		check(RadixMap_add(map, key, i) == 0, "Failed to add key %u", key); // Then we add these keys in the map
	}
	
	return i;
error:
	return 0;
}

static int check_order(RadixMap* map)
{
	RMElement d1, d2;
	unsigned int i = 0;
	
	// only signal errors if any (should nto be)
	for(i = 0; map->end > 0 && i < map->end - 1; i++){
		d1 = map->contents[i];
		d2 = map->contents[i + 1];
		
		// Since they are arranged in ascending order the preceding key should
		// always be larger the succeding key
		if(d1.data.key > d2.data.key){
			debug("FAIL: i=%u, key: %u, value: %u, equals max? %d\n", i, d1.data.key, d1.data.value, d2.data.key == UINT32_MAX);
			return 0;
		}
	}
	
	return 1;
}

static int test_search(RadixMap* map)
{
	unsigned i = 0;
	RMElement* d = NULL;
	RMElement* found = NULL;
	
	for(i = map->end /2; i < map->end; i++){ // We start at the middle of the map and move our way to the end
		d = &map->contents[i];
		found = RadixMap_find(map, d->data.key);
		check(found != NULL, "Didn't find %u at %u:", d->data.key, i);
		// We check if the element we have found are the same 
		check(found->data.key == d->data.key, "Got the wrong result: %d:%u looking for %u at %u", found, found->data.key, d->data.key, i);
	}
	
	return 1;
error:
	return 0;
}

/* TEMPORARY COMMENT
//test for big number of elements
static char* test_operations()
{
	size_t N = 100;
	
	// Creates a map of size 100
	RadixMap* map = RadixMap_create(N);
	mu_assert(map != NULL, "Failed to make the map");
	mu_assert(make_random(map), "Didn't make a random fake radix map"); // add elements and sort them automatically
	
	
	// check if the order of the map is maintained
	mu_assert(check_order(map), "Failed to properly sort the RadixMap");
	
	// Test the search and order functionality
	mu_assert(test_search(map), "Failed the search test");
	mu_assert(check_order(map), "RadixMap didn't stay sorted after search");
	
	// In addition we are also checking the delete functionality
	while(map->end > 0){
		RMElement* el = RadixMap_find(map, map->contents[map->end / 2].data.key);
		mu_assert(el != NULL, "Should get a result");
		
		// storing the old size
		size_t old_end = map->end;
		
		mu_assert(RadixMap_delete(map,el) == 0, "Didn't delete it");
		// checking the new size
		mu_assert(old_end - 1 == map->end, "Wrong size after delete");
		
		//test that the end is now the old value, but uint32 max so it trails off
		mu_assert(check_order(map), "RadixMap didn'tt stay sorted after delete");
	}
				
	RadixMap_destroy(map);
	
	return NULL; 
}
*/

// TEMPORARY UTITLITY FUNCTION
void displayMap(RadixMap* map)
{
	for(int i = 0;i < map->end;i++){
		printf("%u ", map->contents[i].data.key);
	}
	
	printf("\n");
}

static char* test_find_min(){
	// Lets create a new map
	RadixMap* map = RadixMap_create(10);
	mu_assert(map != NULL, "ERROR : Failed to create RadixMap!");
	
	// Adding elements to the map
	RadixMap_add(map, 3, 2);
	RadixMap_add(map, 1, 2);
	// displaying the map
	displayMap(map);
	
	// Adding elements to the map
	RadixMap_add(map, 2, 2);
	// displaying the map
	displayMap(map);
	
	// deleting elements
	RMElement* el = RadixMap_find(map, 2);
	mu_assert(el != NULL, "ERROR : Cannot find element!");
	RadixMap_delete(map, el);
	// display the map
	displayMap(map);
	
	/* TEMPORARY COMMENT
	int min_pos = RadixMap_find_min(map, 6);
	mu_assert(min_pos == 2, "ERROR : Wrong position of the min pos");
	*/
	
	RadixMap_destroy(map); // deallocate the map
	
	return NULL; // don't forget this else it will throw random values
}

char* all_tests()
{
	mu_suite_start();
	srand(time(NULL)); // we seed the rand function with the current time
	
	/* TEMPORARY COMMENT
	mu_run_test(test_operations);
	*/
	mu_run_test(test_find_min);
	
	return NULL;
}

RUN_TESTS(all_tests);