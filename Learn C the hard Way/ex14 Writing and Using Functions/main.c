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
// Using this method you can provide a neater look to your program and increase its readability
int can_print_it(char ch);
void print_letters(char arg[]);

// However there is another method of declaring functions called implicit declaration where the working(definition) of the function is provided along with declaration as done with the function below
// Although this method is also very valid however implicit declaration can sometimes make your program look messy so personally I would prefere the prototyping
void print_arguments(int argc,char *argv[])
{
	// Working : This function is designed to print all the command line arguments given to the program at the time of execution
	// When you run the program from the commandline you type ('main.exe' or './main') so when you does so the first argument you have provided is the name of the file
	// then say you run the file as './main Shane 20' now you have total 3 argument that are 'main' 'Shane' and '20', hence the argc = 3 and arg[0] = 'main', arg[1] = 'Shane', arg[2] = '20'
	int i = 0;
	for(i = 0;i < argc;i++) // Now we are going to print all the arguments provided by the user since the no. of argument will be stored in argc we'll loop uptil then
	{
		print_letters(argv[i]);  // Here we are calling another function which takes a char array as its argument and we are providing the commandline argument array with argc as index
	}
}

// Now this part is function definition where after the declaration of the function we can define its working
void print_letters(char arg[])
{
	// Working : This function is designed to print all the characters in a the argument array
	int i = 0;
	for(i = 0;arg[i] != '\0';i++) // We loop through the argument array till we encounter a null character 
	{
		char ch = arg[i]; // Storing individual character in the variable ch
		if(can_print_it(ch)) // Calling another function to check if the given character is a alphabet or a blank space
		{
			printf("'%c' == '%d'",ch,ch); // Printing the character and its integer value 
		}
	}
	printf("\n");
}

// This function will return a 1 or a 0 depending upon if the character is an alphabet or a blank space
int can_print_it(char ch)
{
	return isalpha(ch) || isblank(ch);
}

// The main function is the first function that executed whenever you run the program
int main(int argc,char *argv[])
{
	// Calling a function : This means you are telling the function to start its execution 
	// In order to do so, just write the name of the function with the parenthesis, Eg : print_Hello() or if you have a function that takes argument then provide the parenthesis in the brackets Eg : int c = sum(a,b)
	// Now since sum will return the addition of a and b we will store it in c, as at the end of the execution of the function the whole value of the function will be equal to value returned
	// NOTE : Now always remember that you can only ever call a function within another function, if you try to call a function outside it will be considered as declration instead of a function call and would likely result in an error
	print_arguments(argc,argv); // Here we are calling thr print_arguments function providing the argc and argv in the function argument

return 0;
}
