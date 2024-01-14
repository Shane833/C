/* Write program that uses math to convert the letter into lowercase letter */
/* Also remove the extraneous upper case letters from the switch statement */

#include <stdio.h>

int main(int argc,char *argv[])
{
	// Uppercase ASCII value 65 - 91
	// Lowercase ASCII value 97 - 123
	
	// So we can approach the following problem as:
	// -> Check if the input character is uppercase
	// -> lowercase value = val(uppercase) + 32
	
	if(argc != 2)
	{
		printf("You need to provide an argument!!!\n");
		return -1;
	}
	
	int i = 0; // iterator
	char c = '\0';
	for(i = 0;argv[1][i] != '\0';i++)
	{
		// storing the character
		c = argv[1][i];
		
		// Checking for Uppercase
		if(c >= 65 && c < 92)
		{
			printf("A uppercase letter : %c\n",c);
			// Converting to lowercase
			c = c + 32; 
			printf("%c \n",c);
		}
	
		// Switch statement
		switch(c)
		{
			case 'a':
				printf("%d : 'A'\n",i);
				break;
			
			case 'e':
				printf("%d : 'E'\n",i);
				break;
				
			case 'i':
				printf("%d : 'I'\n",i);
				break;
			
			case 'o':
				printf("%d : 'O'\n",i);
				break;
				
			case 'u':
				printf("%d : 'U'\n",i);
				break;
		}
			
	}
	
	return 0;
}