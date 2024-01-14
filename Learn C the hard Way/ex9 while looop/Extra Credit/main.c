/* The program is to write a program to make the loop count backwards */
/* form 25 down to 0 */

#include <stdio.h>

int main(int argc,char *argv[])
{
	int i = 25;
	
	while(i >= 0)
	{
		printf("i : %d\n",i);
		i--;
	}
}