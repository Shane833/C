#include <stdio.h>
#include <stdbool.h>

// The new C standard defines stdbool.h header file which contains the macros
// true - integer constant 1
// false - integer constant 0

int main(int argc,char *argv[])
{
	printf("%d\n", true);
	printf("%d\n", false);
}