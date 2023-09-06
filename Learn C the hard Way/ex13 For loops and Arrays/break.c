#include <stdio.h>

int main(int argc,char *argv[])
{
	
	int areas[] = {10,12,13,14,20};
	char name[] = "Zac";
	char fullname[] = {'Z','a','c',' ','B','.',' ','L','i','t','t','\0'};

	printf("Size of an int: %ld\n",sizeof(int));
	printf("Size of areas: %ld\n",sizeof(areas));
	printf("The number of ints in areas: %ld\n",sizeof(areas)/sizeof(int));

	printf("The first area is %d and the second is %d\n",areas[0],areas[1]);

	printf("The size of a char: %ld\n",sizeof(char));
	printf("Size of name: %ld\n",sizeof(name));
	printf("The number of characters in name: %ld\n",sizeof(name)/sizeof(char));

	printf("The size of the fullname: %ld\n",sizeof(fullname));
	printf("The number of characters: %ld\n",sizeof(fullname)/sizeof(char));

	printf("name: %s and Fullname: %s\n",name,fullname);
	return 0;
}