// Creative and Defensive Programming

// The Creative Programmer Mindset:
/*
1. I can't make a mistake
2. It doesn't matter what people think
3. Whatever my brain comes up with is going to be a great idea
*/
// You must adopt this mindset temporarily when you need to come up with creative ideas
// You don't always want to live in fear, you must be willing to take some risks sometimes
// Once you are done with the creative prototype then you must throw away this mind set and 
// focus on creating something serious and get defensive about it

// The Defensive Programmer Mindset:
/*
1. Software has errors
2. You aren't your software, yet you are responsible for the errors
3. You can enver remove the errors, only reduce their probability
*/
// Don't be ruthless and become super strict with it, leave some room for creativity

// The Eight Defensive Programmer Strategies
/*
Once you've adopted this mindset, you can go and rewrite your prototype using the
following strategies to make your code as solid as possible but also constantly
think like someones who is trying to break your software:

1. Never Trust Input: Never trust the data you're given and always validate it
2. Prevent Errors: if and error is possible, no matter how probable, try to prevent it
3. Fail Early and Openly: Fail early, cleanly, and openly, stating what happened, where, and how
   to fix it 
4. Document Assumptions: Clearly state the pre-conditions, post-conditions and invariants
5. Prevention over Documentations: Don't do with documentation that which can be done with code 
   or avoided completely
6. Automate Everything: Automate everything, especially testing
7. Simplify and Clarify: Always simplify the code to the smalleset, cleanest formthat works
   without sacrificing safety.
8. Question Authority: Don't blindly follow or reject rules.   
*/

// APPLYING THE EIGHT STRATEGIES

#undef NDEBUG
#include "dbg.h"
#include <stdio.h>
#include <assert.h>

// Naive copy method that assumes all input are valid
void copy(char to[], char from[])
{
	int i = 0;
	// Here the while loop will not end if from isn't '\0' terminated
	while((to[i] = from[i]) != '\0') // For more findings refer to "extra/first.c"
	{
		++i;
	}
}

// Safer Version that checks for many common errors using the length of each string
// to control the loops and termination.
int safercopy(int from_len, char* from, int to_len, char* to)
{
	assert(from != NULL && to != NULL && "from and to can't be NULL"); 
	// This hack of going '&& "Message"' is great as when the assert
	// will be called by the OS, it will print this message and you
	// will know what exactly is the problem
	// i.e. from and to can't be null, we simply abort the program
	int i = 0;
	int max = from_len > to_len - 1 ? to_len - 1 : from_len;
	// In this statement we are obtaining the max length upto which
	// the copy operation must be done from 'from' to 'to'
	// Now obviously we would need the smaller length and the smaller
	// buffer would not be able to fit all the data of the larger buffer
	
	// to_len must have atleast one byte
	if(from_len < 0 || to_len <= 0)
	{
		return -1;
	}
	
	// Copying the data
	for(i = 0;i < max;i++)
	{
		to[i] = from[i];
	}
	
	// Explicitely null terminating the string
	to[to_len - 1] = '\0';
	
	return i; // Returns the no. of bytes transferred
	
}

int main(int argc,char* argv[])
{
	// careful to understand why we can get these sizes
	char from[] = "0123456789";
	int from_len = sizeof(from);
	
	// notice that its 7chars + \0
	char to[] = "0123456";
	int to_len = sizeof(to);
	
	debug("Copying '%s':%d to '%s':%d", from, from_len, to, to_len);
	
	int rc = safercopy(from_len, from, to_len, to);
	check(rc > 0,"Failed to safercopy."); // Since it will return -1 in case of mishaps
	check(to[to_len - 1] == '\0', "String not terminated.");
	
	debug("Result is: '%s':%d", to, to_len);
	
	// Now try to break it
	rc = safercopy(from_len * -1, from, to_len, to);
	check(rc == -1," safercopy should fail #1");
	check(to[to_len - 1] == '\0', "String not terminated.");
	
	rc = safercopy(from_len, from, 0, to);
	check(rc == -1, "safercopy should fail #2");
	check(to[to_len - 1] == '\0',"String not terminated");
	
	return 0;
	
	error:
		return 1;
}