#include <stdio.h>
#include <stddef.h>
// #include <threads.h> optional feature don't think its here anymore
#include <stdlib.h> // NOT HERE YET! defines the new memalignment() function to determine the byte alignment of a pointer 
#include <string.h> // added the new strdup() and strndup() function to the standard
#if __has_include("dbg.h") // checks the availability of the header before trying to include it
	#include "dbg.h"
#endif

typedef struct S S;

struct S{
	int a;
	float b;
};

int add_int(int a, int b){
	return a + b;
}

float add_float(float a, float b){
	return a + b;
}

#define add_num(X, Y) _Generic((X), int : )


int foo(){return 0;}

int main()
{
	int * p = nullptr; // nullptr is now a constant in C23

	int a = 23;

	// void c; can't really declare a void variable

	//nullptr_t pnull;

	// printf("%p",pnull);	

	typeof(p) b = &a; // typeof b is int*

	// You can also use functions to infer types
	typeof(foo()) c = 20;
	printf("%d\n",c);

	int d = 0b1010; // New Binary representation
	// printf("%b\n",5); // binary format specifier supported yet

    auto e = foo(); //  You can also infer the type from functions

    auto f = (S){1, 3.14}; // along with structs and unions too

    // However you cannot declare a function with the auto keyword like C++
    // hence auto add(int x, int y){} is invalid 

    // new constexpr keyword has been added
    // it only works for variables/objects not for functions
    // Here using constexpr we can check if the value being used
    // to define the constexpr is truly constant or not, i.e. it
    // sometimes a const variable may be defined using a non-const value
    constexpr int size = 10;
    int arr[size] = {}; // element of 10 ints with all value 0 now can be done with just {}

    char * str1 = "Hi";
    char * str2 = strdup(str1); // creates a duplicate of str1 and the memory for it allocated wit malloc
    puts(str2);

    free(str2);

    int x = 10'000; //  You can separate digits by the ' character

	return 0;
}