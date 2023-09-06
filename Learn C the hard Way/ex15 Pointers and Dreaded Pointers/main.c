#include <stdio.h>

int main(int argc,char *argv[])
{
	// create two arrays that we care about
	int ages[] = {23,42,59,81,2};
	char *names[] = {"Frank","Lisa","April","May","Zac"};

	//safely get the size of ages
	int count = sizeof(ages)/sizeof(int);
	int i = 0;

	// printing first way using indexing
	for(i = 0;i < count;i++)
	{
		printf("%s has %d years alive\n",names[i],ages[i]);
	}
	
	printf("---\n");

	// Second way using pointers
	// setup pointers to the start of the array
	int *cur_age = ages;
	char **cur_name = names; 

	for(i = 0;i < count ;i++)
	{
		printf("%d : %p\n%s has %d years alive\n",i, (cur_name + i),*(cur_name + i),*(cur_age + i)); // dereferencing
	}

	printf("---\n");

	// Third way, pointers are just arrays so you can use simple indexing

	for(i = 0;i < count;i++)
	{
		printf("%s has %d years alive\n",cur_name[i],cur_age[i]);
	}
	
	printf("---\n");

	// fourth way, a bit complex

	for(cur_name = names,cur_age = ages;(cur_age - ages) < count;cur_name++,cur_age++) // pointer arithemetic
	{
		printf("%s has %d years alive\n",*cur_name,*cur_age);
	}

	
return 0;
}