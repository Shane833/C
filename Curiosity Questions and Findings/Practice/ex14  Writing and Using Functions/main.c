#include <stdio.h>
#include <ctype.h>

// Forward Declarations
void print_letters(char argv[]);
int can_print_it(char c);

void print_arguments(int argc, char* argv[])
{
	for(int i = 1;i < argc;i++){
		print_letters(argv[i]);
	}
}

void print_letters(char argv[])
{
	for(int i = 0;argv[i] != '\0';i++){
		char c = argv[i];
		if(can_print_it(c)){
			printf("%c : %d ", c, c);
		}
	}
}

int can_print_it(char c)
{
	return isalpha(c) || isblank(c);
}

int main(int argc, char* argv[])
{
	print_arguments(argc, argv);
	return 0;
}