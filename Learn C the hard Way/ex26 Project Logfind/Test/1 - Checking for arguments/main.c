#include "dbg.h"

int main(int argc,char *argv[])
{
	// Checking for the arguments
	check(argc > 2,"Usage : ./main word word ...");
	
	error:
		return 1;
	
	return 0;
}