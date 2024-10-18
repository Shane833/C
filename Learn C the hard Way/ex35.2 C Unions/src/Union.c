#include <dbg.h>

// C Unions provide a way to represent the same piece of memory in a number of
// different ways. It's defined like a struct and all the elements in it actually
// share space/memory as the size of the union is equal to the largest element 
// defined in the union itself

// You can think of the union as a picture and the differnt elements in it as 
// different lenses to view the picture.
// There primary use is to either save space or to convert between different formats

// This enumeration will let us define which type of data we will be storing
typedef enum{
	TYPE_INT,
	TYPE_FLOAT,
	TYPE_STRING
}VariantType;

// This is the actual struct which we will be using to store the different datatypes
// We define a type variable to explicitely define the type of data we will be storing
// and then a Union called data which will be storing different types of data as per the
// defined type
typedef struct Variant{
	VariantType type;
	union{
		int as_integer;
		float  as_float;
		char* as_string;
	}data;
}Variant;

// Function to print the struct as per their types
void Variant_print(Variant* var)
{
	switch(var->type){
		case TYPE_INT:
			printf("INT : %d\n", var->data.as_integer);
			break;
		case TYPE_FLOAT:
			printf("FLOAT : %f\n", var->data.as_float);
			break;
		case TYPE_STRING:
			printf("STRING : %s\n", var->data.as_string);
			break;
		default:
			printf("UNKNOWN TYPE : %d\n", var->type);
	}
}


int main(void)
{
	// Variant Variable
	Variant empty;
	
	// Some basic sizes for reference
	printf("Size of INT   		: %d\n", sizeof(int));
	printf("Size of FLOAT 		: %d\n", sizeof(float));
	printf("Size of DOUBLE		: %d\n", sizeof(double));
	printf("Size of CHAR  		: %d\n", sizeof(char)); 
	printf("Size of Any Pointer 	: %d\n", sizeof(void*));
	
	// Lets compute the size of our defined datatypes
	printf("Size of Type		: %d\n", sizeof(VariantType)); 
	// Interesing how the size of the enum is 4 despite the no. of elements
	printf("Size of Struct 		: %d\n", sizeof(empty));
	printf("Size of Union  		: %d\n", sizeof(empty.data));
	
	// Defining different Variants
	Variant a_int = {.type = TYPE_INT, .data.as_integer = 100};
	Variant a_float = {.type = TYPE_FLOAT, .data.as_float = 3.14};
	Variant a_string = {.type = TYPE_STRING, .data.as_string = "YO DUDE!"};
	
	// Lets now print these 
	Variant_print(&a_int);
	Variant_print(&a_float);
	Variant_print(&a_string);
	
	// here's how you cann access them
	a_int.data.as_integer = 200;
	a_float.data.as_float = 6.28;
	a_string.data.as_string = "Hi there";
	// Ok so I had completely forgotten that I can overwirte the pointer like that
	// but then I shouldn't be surprised because we are just assigning a memory address
	
	Variant_print(&a_int);
	Variant_print(&a_float);
	Variant_print(&a_string);
	
	// Also it is interesting that many of the dynamically typed languages use this kind of
	// inference of types where they will define some base type and then as per the data the
	// type can be decided by the user 
	
	return 0;
}