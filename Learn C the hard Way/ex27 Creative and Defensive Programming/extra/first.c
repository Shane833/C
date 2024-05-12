// This is a code example to validate a statment at line 53 of main.c

#include <stdio.h>

int main(int argc,char* argv[])
{
	// So in the file we wrote an expression (to[i] = from[i]) != '\0'
	// i.e. there's a way to check the value of this expression
	
	// Let's take a simple example
	int a = 10;
	int b = 5;
	
	printf("%d\n",a = b);
	// So it seems like that this returns the value that a has been assigned to
	// by b, so basically whatever value b has will be printed
	
	/* Curiosity Question */
	// When I add more %d as to simulate printing other parts of the expression
	// They all give garbage values and this is considered a single expression
	// and have not separate components
}