#include <stdio.h>

int main(int argc,char *argv[])
{
	// You can break this program by forgetting to initailize the int i which will point to undefined value
	int i; 
	while(i < 25)
	{
		printf("%d\n",i);
		i++; // or forget to increment which will run forever
	}

	return 0;
}