#ifndef _lcthw_Hashmap_h
#define _lcthw_Hashmap_h

#include <stdint.h>
#include <lcthw/darray.h>
#include <lcthw/darray_algos.h>

#define DEFAULT_NUMBER_OF_BUCKETS 100 // Macro defining the default size of the Hashmap Keys

typedef int (*Hashmap_compare) (const void* a, const void* b); // Pointer to Function for comparing Keys 
typedef uint32_t (*Hashmap_hash) (void* key); // Pointer to a Function for generating the hash from a key		
											  // Returns an unsigned 32 bit integer hash value

// This is our Hashmap which contains pointer to compare function and pointer to hash generating function
// and a Dynamic Array called bucket for storing the Nodes corresponding to a specific hash
typedef struct Hashmap{
	DArray* buckets; 
	Hashmap_compare compare; // Pointer to a function for comparing keys
	Hashmap_hash hash; // Pointer to a function for generating the hash
}Hashmap;

// This is our single Node which is a pair of keys and values
// and also stores a unique has code within it
typedef struct HashmapNode{
	void* key;
	void* data;
	uint32_t hash;
}HashmapNode;

// This is a function for traversing the Node and displaying all the data associated with it
// This is a user-defined function which tells how to display the data within the node
typedef int (*Hashmap_traverse_cb) (HashmapNode* node);

// Function to create a Hashmap and you have to provide a compare and hash generating function
// for the specific datatype that you wish to use as a key
Hashmap* Hashmap_create(Hashmap_compare, Hashmap_hash);

// Destroys the data in the hashmap
void Hashmap_destroy(Hashmap* map);

// Function to set/add a specific key value pair assuming that the keys are unique
int Hashmap_set(Hashmap* map, void* key, void* data);

// Function to get the value for a corresponding key from the hashmap
void* Hashmap_get(Hashmap* map, void* key);

// Function to traverse the hashmap and you have to provide how each of the node gets traversed
int Hashmap_traverse(Hashmap* map, Hashmap_traverse_cb traverse_cb);

// Function to remove a key value pair from the map
void* Hashmap_delete(Hashmap* map, void* key);

// Improvements
// 1. Sort each of the bucket so that we can use binary search to find the element, this would increase
// insertion time but decreases the searching time since currently it used linear search to find the keys
// include the darray_algos header file and use the required functions
/* Improvement 1 - Done */


#endif