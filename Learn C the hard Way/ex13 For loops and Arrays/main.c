#include <stdio.h>

int main(int argc,char *argv[])
{
	int i = 0;
	
	for(i = 0 ;i < argc;i++)
	{
		printf("arg %d : %s\n",i,argv[i]);
	}

	char *states[] = {"California","Oregon","Texas","Washington"};

	int num_state = 4;

	for(i = 0;i < num_state;i++)
	{
		printf("State %d : %s\n",i,states[i]);
	}


return 0;
}