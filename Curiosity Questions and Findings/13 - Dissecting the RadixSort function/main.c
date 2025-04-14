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
	uint8_t c = 0; // temporary variable
	
	// src is supposedly an array so we will go through it
	// and find which value of byte occurs how many times like a histogram
	for(sp = src, end = src + max; sp < end; sp++){
		count[*sp]++; // obtain the value of the byte and increment its count occurence
	}
	
	// we have to obtain a cumulative sum of the values
	// This piece of code
	// sets count[0] = 0
	// and count[i+1] = count[i] + count[i - 1]
	for(s = 0, cp = count, end = count + 265; cp < end; cp++){
		c = *cp; 
		*cp = s;
		s += c;
	}
	
	// Map the indices to their respective positions
	for(sp = src, end = src + max; sp < end; sp++){
		cp = count + *sp;
		dest[*cp] = *sp;
		++(*cp);
	}
}

int main(int argc, char* argv[])
{
	
	
	return 0;
}