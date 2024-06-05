// In this file I'm going to create a calculator type something that will use function callbacks

#include <stdio.h>
// lets create a macros to check for invalid values
#define check(A, M, ...) if(!(A)){fprintf(stderr,"%s:%d : " M "\n", __FILE__, __LINE__, ##__VA_ARGS__);error = 1;goto error;}
// A global variable to know if an error has occured on not
size_t error = 0;
// Then lets delcare our function pointer
typedef int (*Operation) (int a, int b, int* result);
// So this will take the value of the two operands and after the operation store it in result
// and return 1 or a 0 upon correct execution

// Now we define our operations
int add(int a, int b, int* result)
{
	check(result != NULL, "Invalid value passed for result");
	*result = a + b;
	error = 0;
	return 0;
error:
	return 1;
}

int sub(int a, int b, int* result)
{
	check(result != NULL, "Invalid value passed for result");
	*result = a - b;
	error = 0;
	return 0;
error:
	return 1;
}

int mul(int a, int b, int* result)
{
	check(result != NULL, "Invalid value passed for resutl");
	*result = a * b;
	error = 0;
	return 0;
error:
	return 1;
}

int div(int a, int b, int* result)
{
	check(result != NULL, "Invalid value passed for result");
	check(b != 0, "Cannot divide by 0!");
	*result = a / b;
	error = 0;
	return 0;
error:
	return 1;
}

// Now lets define another function which will use these functions
int operate(int a, int b, Operation opr)
{
	int result = 0;
	check(opr(a, b, &result) == 0, "Failed to execute the operation!");
	return result;
error:
	return -1;
}

int main(int argc, char* argv[])
{
	int a = 10;
	int b = 0;
	int result = 0;
	
	result = operate(a, b, add);
	check((error != 1) || (result != -1), "Something went wrong"); // as the 
	printf("%d\n",result);
	
	result = operate(a, b, sub);
	check((error != 1) || (result != -1), "Something went wrong");
	printf("%d\n",result);
	
	result = operate(a, b, mul);
	check((error != 1) || (result != -1), "Something went wrong");
	printf("%d\n",result);
	
	result = operate(a, b, div);
	check((error != 1) || (result != -1), "Something went wrong");
	printf("%d\n",result);
	
	return 0;
error:
	return 1;
	
}


// NOTE: I was using #__VA_ARGS__ in the macro which converst the variadic args to a string literal instead of
// using the variadic argument as it and that is why it was throwing a waring, what I then changed was
// #__VA_ARGS__ -> ##__VA_ARGS__ and the warning disappeared