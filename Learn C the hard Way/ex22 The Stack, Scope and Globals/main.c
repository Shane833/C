#include "dbg.h"
#include "ex22.h" // Since we want to use the features of this file we simply include it 

// This is a pointer to characters defining a name
const char *MY_NAME = "Shane Williams";

// This function demonstrates the concept of scope by having multiple variables having the same name but having different scopes
void scope_demo(int count)
{
	log_info("count is: %d",count);

	if(count > 10)
	{
		int count = 100;
		log_info("count in this scope is: %d",count);
	}
	
	log_info("count at exit is: %d",count);

	count = 3000;
	
	log_info("count after assign: %d",count);
}

int main(int argc,char *argv[])
{
	
	log_info("My name is: %s, age: %d",MY_NAME,get_age());

	set_age(100);

	log_info("My age now is: %d",get_age());

	log_info("The size is: %d",THE_SIZE);
	print_size();

	// Since this variable was declared as extern hence it could be used outside of the file
	THE_SIZE = 9; // and can be referenced and updated accordingly
	// However, if this were to be declared static we won't be able to reference it directly in another files

	log_info("The size now is: %d",THE_SIZE);
	print_size();

	log_info("Ratio at first: %f",update_ratio(2.0));
	log_info("Ratio again: %f",update_ratio(10.0));
	log_info("Ratio once more: %f",update_ratio(300.0));

	int count = 4;
	scope_demo(count);
	scope_demo(count * 20);

	log_info("count after calling scope_demo: %d",count);

	
	return 0;
}