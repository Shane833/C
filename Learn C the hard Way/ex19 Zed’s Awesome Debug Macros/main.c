#include <stdio.h>
#include <stdlib.h>
#include "dbg.h"

// This is a macro Sum which returns a value
#define Sum(a,b) ({int c; c = a + b; c;})
// This is a macro Add which performs the addition and updates the value of a (as it directly works on the reference of the value)
#define Add(a,b) (a = a + b)

#define returnAdd(a,b) (a + b) // Simply returns the value in the end

// MACROS :
/**

*/

void test_debug()
{
	// notice you don't need the \n
	debug("I have black hair.");
	
	// Passing in arguments like printf
	debug("I am %d years old.",20);
}

void test_log_err()
{
	log_err("I believe everything is broken.");
	log_err("There is %d problem in %s",0,"space");
}

void test_log_warn()
{
	log_warn("You can safely ignore this.");
	log_warn("Maybe consider taking a look at %s","/etc/passwd");
}

void test_log_info()
{
	log_info("Well I did something mundane today.");
	log_info("It happened %f times this day",1.3f);
}

int test_check(char *filename)
{
	FILE *input = NULL;
	char *block = NULL;

	block = malloc(100);
	check_mem(block);

	input = fopen(filename,"r");
	check(input,"Failed to open %s",filename);

	free(block);
	fclose(input);
	return 0;

	error:
		if(block) free(block);
		if(input) fclose(input);
		return -1;
}

int test_sentinel(int code)
{
	char *temp = malloc(100);
	check_mem(temp);

	switch(code)
	{
		case 1:
			log_info("It worked.");
			break;
		default:
			sentinel("It shouldn't run.");
	}

	free(temp);
	return 0;

	error:
		if(temp) free(temp);
		return -1;
}

int test_check_mem()
{
	char *test = NULL;
	check_mem(test);

	free(test);
	return 1;

	error:
		return -1;
}

int test_check_debug()
{
	int i = 0;
	check_debug(i != 0,"Oops I was 0.");
	return 0;

	error:
		return -1;
}

int main(int argc,char *argv[])
{
	printf("Hello there\n");
	int a = 5;
	int b = 2;
	a = Sum(a,b);
	printf("Sum : %d\n",a);
	int c = returnAdd(a,b);
	printf("Add : %d\n",c);

	test_sentinel(0);
	test_check_debug();
	

}