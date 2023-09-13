#include <stdio.h>
#include <ctype.h>

// FUNCTIONS - They are certain peices of a program that are designed to perform a specific task
// It is better to use functions when you have to perform

// This is forward declaractions or function prototyping, where we let the compiler know that we are have declared some functions to be defined later
// This is useful as these functions are now added to the global scope before definitions and they can be called at uneven
int can_print_it(char ch);
void print_letters(char arg[]);

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