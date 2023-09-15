#include <stdio.h>
#include <ctype.h> // Defines functions for handling the characters

// FUNCTIONS - They are certain peices of a program that are designed to perform a specific task
// It is better to use functions when you have to perform similar task again and again and for a more cleaner program
// Syntax of a function :
/* 
	return_type name(argument1,argument2){body}
	
	// The return_type of the function tells what kind of data will the function will be returning after it will done with its execution
	// For example if you are making a function to obtain the sum of numbers you might want to make the return type as int as you will be returning integer result
	// However there is also a type called called void which
	// Eg: int sum() or float power() or void print() or could be any other type depending on your work use
	
	// The name of the function should follow the naming convention of the variables
	// name of the function should reflect the kind of work it will perform like you won't name a function multiply if it is perfoming a division
	
	// arguments : These are provided in the brackets after the name of the function, these argument are the things the function is going to need for its execution
	// For example if you're making a function to print something on the screen you would need the argument which will be the message to be printed i.e. void print(message)
        // Or say you're creating a function for adding two numbers then you would provide those two numbers in the arguments i.e. int add(int a, int b)

        // You define the functionality/work of the function in the body of the function and may use the arguments defined in the function declaration 
	// However remember the scope of these arguments and the local variables is only valid for the runtime of the function and after them any reference to them will be invalid
        // For actually reflecting the changes in the arguments (not the local variables within the function) you must use the concept of call by reference 

        // For returning a value after computation or for exiting the function prior to the end you should use the return keyword
	// In case of void return type function using return keywors will let you exit the program at that instance and any code written below that will not be executed 
        // In case of non-void return type functions you must provide additional data when using the return keyword For eg: in case if add(a, b) you should return the sum i.e. return (a+b)
	// Again for other non-void return types you'll return the values accordingly and in case no value is returned by the function it'll automatically return zero equivalent of that return type 
        // Again no code after the return keyword will get executed as it exists the function at that instance 
*/


// This is forward declaractions or function prototyping, where we let the compiler know that we are have declared some functions to be defined later
// This is useful as these functions are now added to the global scope before definitions and they can be called at uneven times before definition
int can_print_it(char ch);
void print_letters(char arg[]);
// However if you try to call a function without forward declaration and before its declaration it will result in an error

/* Case 1:
   func1(){func2()}	
   func2(){something}
  // This would be wrong as we are trying to call func2 before the compiler knows it exists i.e. before its declaration or definition
 
   Case 2:
   func1();
   func2(){func1()}
   func1(){something}
   // Now this scenario is completely perfect as even though we didn't define
*/

//
void print_arguments(int argc,char *argv[])
{
	int i = 0;
	for(i = 0;i < argc;i++)
	{
		print_letters(argv[i]);
	}
}

void print_letters(char arg[])
{
	int i = 0;
	for(i = 0;arg[i] != '\0';i++)
	{
		char ch = arg[i];
		if(can_print_it(ch))
		{
			printf("'%c' == '%d'",ch,ch);
		}
	}
	printf("\n");
}

int can_print_it(char ch)
{
	return isalpha(ch) || isblank(ch);
}

int main(int argc,char *argv[])
{

	print_arguments(argc,argv);

return 0;
}
