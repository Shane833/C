#include <stdio.h>

int main()
{
	int a = 0;
	char c = 'c';
	struct combine{
		int a;
		char c;
		char str[5];
	};

	printf("sizeof a : %d\n",sizeof(a)); // Expected : 4
	printf("sizeof c : %d\n",sizeof(c)); // Expected : 1
	printf("sizeof combine : %d\n",sizeof(struct combine)); // Expected : 10
	// However it won't be 10, since it pads the data accordingly as per the size
	// of a word (which is usually 4bytes) and hence we obtain a size of 12

	return 0;
}