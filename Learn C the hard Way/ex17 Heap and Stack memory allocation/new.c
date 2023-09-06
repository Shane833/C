// Heap vs. Stack
// For now consider that whenever you use malloc you are using the heap and anywhere else it would be stack
// Now one of the advantages of using the heap is when you are passing structures in the function calls
// If you are passing the complete member of the structure it can easily take over the function call stack and will
// take more space in memory, and would have to be copied onto the stack. So now we are beginning to come to call by
// value vs. call by reference
// So here we are using the stack to store the actual value and the heap to share around the structures among the functions

// Using the Heap:
// In the function Database_open, we making a structure using malloc which will be from the heap
// Similary in the struct we again have a pointer to the struct database which we are allocating memory using malloc

// Function Stack
// Whenever you create local variables (includes parameterized) in a function they are stored in the function stack for the entirity
// of the execution of that function and automatically that memory gets freed once the execution ends
/** Note : Don't use memcpy() function to copy one struct to another,if they are variables of the same struct just directly assign them to each other using '=' **/

// EXTRA CREDIT PROGRAMS HERE

#include <stdio.h> // 
 