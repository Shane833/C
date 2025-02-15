#include <stdio.h>
#include "bstrlib.h"

int main()
{
	// Understanding bdelete function
	bstring s = bfromcstr("Shivang");
	printf("Data Before: %s\n",bdata(s));
	bdelete(s, 6, 1);
	printf("Data After: %s\n",bdata(s));
	
	return 0;
}