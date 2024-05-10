#include <stdio.h>

// Lets define a struct
typedef struct Person
{
	int age;
	
}Person;

// Function to return a struct not a pointer to a struct but a whole struct
Person createPerson(int age)
{
	Person me;
	me.age = age;
	return me;
}

int main(int argc,char *argv)
{
	// I always thought that the variable within a function were local to it
	// but still I can return it out of the function
	
	// But then if I come to think about it, this is literally what I have done
	// with simple function that return int, float, char so maybe using the stack
	// instead of the heap only makes a difference in terms of computations
	// and logically both are correct but one is fast then the other bcz we only
	// reference the variables instead of creating them, and it also makes our
	// program fast due to less overhead on the function stack
	
	Person me = createPerson(20);
	printf("%d",me.age);
}