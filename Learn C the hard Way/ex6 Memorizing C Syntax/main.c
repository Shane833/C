`// Memorizing the C syntax for various structures

/*
auto - give the local variable a local lifetime
break - exit out of a compound statement
case - branch in a switch statement
char - character data type
const - make a variable unmodifiable
continue - continue to the top of the loop
default - default branch in a switch statement
do - start a do while loop
double - a double floating point data type
else - an else branch of an if statement
enum - define a set of int constants
extern - declare an identifier which is defined externally
float - a floating point data type
for - start a for loop
goto - jump to a label
if - starts an if statement
int - an integer datatype
long - a long integer datatype
register - declare a variable to be stored in a CPU register
return - return from a function
short - a short integer data type
signed - a signed modifier for integer data types
sizeof - determines the size of a data structure
static - preserves variable value after its scope exits
struct - combine variables into a single record
switch - start a switch statement
typedef - create a new type
union - start a union statement
unsigned - an unsigned modifier for integer data types
void - declare a data type empty
volatile - declare a variable that might be modified elsewhere
while - starts a while loop

*/

/*
structures of keywords

if :
	if(TEST){
		CODE;
	}
	else if(TEST){
		CODE;
	}
	else{
		CODE;
	}

switch:
	switch(OPERAND){
		case CONSTANT:
			CODE;
			break;
		default:
			CODE;
	}

while continue and while break loop:
	while(TEST){
		if(OTHER TEST){
			continue;
		}
	}

	while(TEST){
		if(OTHER TEST){
			break;
		}
	}

do-while:
	do{
		CODE;
	}
	while(TEST);
for:
	for(INITIALIZATION;TEST;INCREMENT/DECREMENT){
		CODE;
	}

enum:
	enum {CONST_1,CONST_2,CONST_3} NAME;

goto:
	if(ERROR_TEST){
		goto FAIL;
	}
	FAIL:
		CODE;

functions:
	TYPE NAME (arg1,arg2...){
		CODE;
		return VALUE;
	}

typedef:
	typedef DEFINITION IDENTIFIER;

struct:
	struct NAME{
		ELEMENTS;
	}VARIABLE_NAME;

union:
	union NAME{
		ELEMENTS;
	}VARIABLE_NAME;
*/

#include <stdio.h>

int main(int argc,char *argv[]){

auto a = 5;

}