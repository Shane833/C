#include <stdio.h>
#include <stdlib.h>
int main(int argc,char *argv[]){

// You can debug your program using the gdb (GNU Debugger)
// You can find out many problems in your file after compiler
// *Note : You can only use the gdb on a compiled program (*.exe) not on the source file (*.c)

// To use the gdb, in the terminal type gdb file_name
// When you compile the source remember to add the '-g' argument that enables debugging
// There are set of keywords and arguments that you can give to the debugger

// Arguments are given in the form 'gdb --args filename'
// One of the most useful argument is 'gdb --batch --ex r --ex bt --ex q --args ./filename'

// some other useful arguments that you can give are:

/** 
bt : for getting a backtrace to any memory related error in the stack or simply check where the memory is pointing to while you are going through the program line by line in break points
break : this can be used to break our program function wise and then see what going on within that function
		For eg: for breaking to the main function we will give the arguments 'break main' while the debugger is active
step : after you have set the break points then you can go through the source code line by line
next : it is the same as step but it don't execute the program it just goes through it and step over function calls
list : This command will list next 10 lines of the source on the command line, you can also add an argument '-a' to your list command and it will print out the previous 10 lines of the source
cont : This command will run the program till there are any faults its like going through the program and then only stops if any error has occured
quit : This command exits the GDB
cd,pwd,make : They work just like you when you give these commands in any shell
clear : It clears any created breakpoints
info break, info watch : Shows information about break points and watch points
print expr : Print the value of the expression. short hand is 'p'

*/

// Other than gdb there is also a tool called valgrind which can help magnify the cause of the errors
// It basically checks your complete memory and then see where the problem is and at what address
// To use Valgrind, in your terminal simply write this 'valgrind ./compiled_filename'


char *c = (char *)malloc(4 * sizeof(char)); // initializing the pointer with only a size of 4 bytes

for(int i = 0;i < 1000000;i++){
	
	printf("%c",c[i]); // pointing to unitialized and out of index characters
						// results in segmentation fault error
}

return 0;


}