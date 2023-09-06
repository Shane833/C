#include <stdio.h>

int main(int argc,char *argv[])
{
	if(argc != 2)
	{
		printf("You need an argument\n");
		return 1; // if one is returned then the program will abort
	}
	
	int i = 0;
	for(i = 0;argv[1][i] != '\0';i++) // the argv is array of strings and each argument is a string and we can obtain the individual character from that string using the subscript operator
	{
		char letter = argv[1][i];
	
		switch(letter)
		{
			case 'a': // this will check for both of the cases either if its a lowercase letter or an uppercase
			case 'A':
				printf("%d 'A'\n",i);
			break;
			
			case 'e':
			case 'E':
				printf("%d 'E'\n",i);
			break;

			case 'i':
			case 'I':
				printf("%d 'I'\n",i);
			
			case 'o':
			case 'O':
				printf("%d 'O'\n",i);
			break;

			case 'u':
			case 'U':
				printf("%d 'U'\n",i);
			break;
	
			default:
				printf("%d: %c is not a vowel\n",i,letter);
		}
	}

	return 0;
}