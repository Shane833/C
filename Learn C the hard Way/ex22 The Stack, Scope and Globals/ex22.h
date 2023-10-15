#ifndef EX22_H // Preprocessor guards to let the program include the header file only once
#define EX22_H
// This is a header file (*.h) which are like a pre-defined structure declaring variables, data structures and function
// However this is just like a template and you must define the definitions of the various attributes in another file (*.c)


// This variables is declared extern meaning that it is available to all the other files and can be defined externally
extern int THE_SIZE;

// These functions are declared for handling the internal static variable defined in the ex22.c file
int get_age();
void set_age(int age);

// Used for updating a static variable defining within this function
double update_ratio(double new_ratio);

// Prints the value of the variable THE_SIZE
void print_size();

#endif