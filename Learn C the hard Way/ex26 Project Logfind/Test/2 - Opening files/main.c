#include "dbg.h"
#include <string.h>

int main(int argc,char *argv[])
{
	// Checking for the arguments
	check(argc > 2,"Usage : ./main word word ...");
	
	// Creating and opening a file
	FILE *file = fopen("New.txt","w");
	check_mem(file);
	
	// writing some text 
	fprintf(file,"Test File");
	fclose(file);
	
	// Reading the data from the file
	file = fopen("New.txt","r");
	char buffer[50];
	fgets(buffer,49,file);
	printf("%s\n",buffer);
	fclose(file);
	
	// Testing for string comparisons
	char *sentence = "This is C program for comparing stuff.";
	char *to_be_found = "comparing";
	char *result = NULL;
	// This will return the address where the string is found 
	
	result = strstr(sentence,to_be_found);
	for(int i = 0;i < strlen(to_be_found);i++)
	{
		printf("%c",result[i]);
	}
	printf("\n");
	error:
		if (file) fclose(file);
		return 1;
	
	return 0;
}