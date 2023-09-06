#include <stdio.h>

int main(int argc,char *argv[])
{
	int numbers[4] = { 0 }; // modern c automatically initializes the elements of the array after you initialze one of them
	char name[4] = { 'a' };

	printf("numbers: %d %d %d %d\n",numbers[0],numbers[1],numbers[2],numbers[3]);
	printf("name each: %c %c %c %c\n",name[0],name[1],name[2],name[3]);

	printf("name: %s\n",name);

	numbers[0] = 1;	
	numbers[1] = 2;
	numbers[2] = 3;
	numbers[3] = 4;

	name[0] = 'Z';
	name[1] = 'a';
	name[2] = 'c';
	name[3] = 'A'; // now we have to set the null character to let the compiler know that the string ends here
	// you can break this by removing the null character at the end of the string
	printf("numbers; %d %d %d %d\n",numbers[0],numbers[1],numbers[2],numbers[3]);
	printf("name each: %c %c %c %c\n",name[0],name[1],name[2],name[3]);

	printf("name: %s\n",name);

	char *another = "Zac"; // This way it will automatically append a null character at the end of the string and this is still an array of 4 characters, this is a character pointer
	printf("another: %s\n",another);
	printf("another each: %c %c %c %c\n",another[0],another[1],another[2],another[3]);
	
	return 0;
}