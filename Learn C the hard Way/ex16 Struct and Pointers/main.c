#include <stdio.h>
#include <assert.h> // this library provides a macro which can check if some expression is true or false for the lifetime of the program
#include <stdlib.h> // this library mainly deals with memory allocation, process control etc.
#include <string.h>

struct Person // This is a struct a hetrogeneous container of different types
{
	char *name; // These are the members of the struct
	int age;
	int height;
	int weight;
};

struct Person *Person_Create(char *name,int age,int height,int weight)
{
	struct Person *who = malloc(sizeof(struct Person)); // allocates memory to a pointer of struct Person equivalent to the size of the struct itself
	assert(who != NULL); // This basically checks if the value returned by the who should not be equal to NULL, if it is then it will terminate the program there
	
	who->name = strdup(name); // This basically returns a duplicate of the string as a pointer and memory to it is allocated dynamically
	who->age = age;
	who->height = height;
	who->weight = weight;
	
	return who; // We are returning the pointer who itself
}

void Person_destroy(struct Person *who) // This takes a pointer object of struct person
{
	assert(who != NULL); // Again checks if the pointer is a NULL pointer
	
	free(who->name); // Since this was duplicate and was allocated memory by the function this needed to be freed itself
	free(who);
}

void Person_print(struct Person *who) // This functions just takes the pointer object of the struct and just prints out the information of the object
{
	printf("Name : %s\n",who->name);
	printf("Age : %d\n",who->age);
	printf("Height : %d\n",who->height);
	printf("Weight : %d\n",who->weight);
}

int main(int argc,char *argv[])
{
	// Creating two pointer objects of the struct Person and allocating data to them
	struct Person *joe = Person_Create("Joe Alex",32,64,140);
	Person_print(joe);

	struct Person *frank = Person_Create("Frank Blank",20,72,180);
	Person_print(frank);
	
	// You can make change to the current data of the existing person by simply accesing their date from the pointer object
	
	joe->age += 20;
	joe->height -= 2;
	joe->weight += 40;
	Person_print(joe);
	
	frank->age += 20;
	frank->weight += 20;
	Person_print(frank);

	// now we will destroy both of the objects
	Person_destroy(joe);
	Person_destroy(frank);

	return 0;

	
	Person_destroy(joe);

}

