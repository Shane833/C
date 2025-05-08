#include <stdio.h>
#include <stdint.h>

int radix_sort(int max, uint8_t* src, uint8_t* dest)
{
	// max is basically the size of the src array or the no. of elements within it
	// count array for all possible byte values
	uint8_t count[256] = { 0 };
	
	uint8_t* cp = NULL; // count pointer pointing to the count array
	uint8_t* sp = NULL; // src pointer pointing to the source
	uint8_t* end = NULL; // keeps us in bounds keeping us from accessing foreign memory
	uint8_t s = 0; // for obtaining the cumulative sum
	uint8_t c = 0; // temporary variable used while accumulating the sum
	
	// src is supposedly an array so we will go through it
	// and find which value of byte occurs how many times like a histogram
	for(sp = src, end = src + max; sp < end; sp++){
		count[*sp]++; // obtain the value of the byte and increment its count occurence
	}
	
	// we have to obtain a cumulative sum of the values
	// This piece of code
	// sets count[0] = 0 (which is the default)
	// and count[i+1] = count[i] + count[i - 1]
	for(s = 0, cp = count, end = count + 265; cp < end; cp++){
		c = *cp; 
		*cp = s;
		s += c;
	}
	
	for(int i = 0; i < 256;i++){
		printf("%d : %d\n", i-1, count[i]);
	}
	
	// Map the indices to their respective positions
	for(sp = src, end = src + max; sp < end; sp++){
		cp = count + *sp; // We point to the index in the count array where the index of the *sp is situated
		dest[*cp] = *sp; // and we place the *sp at the index in the destination array
		++(*cp); // then we increment the value so if the there are multiple same values they are situated right next to each other
	}			// Defining the in-order nature of the algorithm
}

int main(int argc, char* argv[])
{
	uint8_t arr[6] = {5,9,7,3,6,2};
	uint8_t dest[6] = { 0 };
	
	radix_sort(6,arr,dest);
	
	for(int i = 0; i < 6;i++){
		printf("%d ", dest[i]);
	}
	
	return 0;
}