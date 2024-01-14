#include <stdio.h> // This library includes the I/O functions                  
#include "dbg.h" // Custom file for debugging
#include <string.h> // library for handling strings

#define MAX_DATA 100 // Constant for defining the max size

// Creating a new type using an enum called EyeColor which holds symbolic 
// representation for numeric values
// So instead of referring to this "enum EyeColor variable" again and again, 
// we can simply use "EyeColor variable"
typedef enum EyeColor{BLUE_EYES,GREEN_EYES,BROWN_EYES,BLACK_EYES,OTHER_EYES} EyeColor;

// Defining a array of strings
// This is basically an array of const char * (i.e, there is only read only right 
// and no one can change the data after declaration)
const char *EYE_COLOR_NAMES[] = {"Blue", "Green", "Brown", "Black", "Other"};
// So we are storing the strings in the same order as defined in the enum to refer 
// to them in the same order

// Here we are again creating a new type using a struct which holds a strucutre of data for a Person
// So instead of using "struct Person variable", you can simply write "Person variable"
typedef struct Person 
{
  // members of the struct
  int age;
  char first_name[MAX_DATA];
  char last_name[MAX_DATA];
  EyeColor eyes;
  float income;
}Person;

// Main Function
int main(int argc, char *argv[])
{

  Person you = {.age = 0}; // only initializing a certain part of the struct
  int i = 0; // variable to be used as an iterator/counter
  char *in = NULL; // variable to be used as a debugging tool
  
  
  // The function used here is 'fgets'
  // Function template : char * fgets(char *s,int size,FILE *stream)
  // This function reads in at most one less than the characters specified by the size and stores them in the buffer
  // pointed to by s, Reading stops after an EOF or a new line, if a new line is read it is stored into the buffer
  // A terminating null byte ('\0') is stored after the last character in the buffer
  // So say you define a size of 100, then it will only read atmost upto 99 characters reserving that single character for the null byte
  // It returns the address to the buffer itself on successful reading, returns NULL in case of unsuccessful and EOF if no characters is read
  printf("What's your first name : ");
  in = fgets(you.first_name,MAX_DATA - 1, stdin);
  check(in != NULL,"Failed to read the first name.");
  
  printf("What's your last name : ");
  in = fgets(you.last_name,MAX_DATA - 1,stdin);
  check(in != NULL,"Failed to read the last name.");
  
  // The function used here is fscanf
  // Function Template : int fscanf(FILE *stream,const char *format,...)
  // This function reads input from the stream pointed to by stream pointer
  // Upon successful reading it returns the no. of input items successfully matched and assigned
  // The value of EOF is returned if the end of input is reached before either the first successful conversion or a matching failure
  // EOF is also returned when a reading error occurs
  printf("How old are? : ");
  int rc = fscanf(stdin," %d",&you.age); // This will return the no. of items read
  check(rc > 0,"You have to enter a number.");

	// Reading the eye colors from the user
  printf("What color are your eyes ? :\n");
  for(i = 0;i <= OTHER_EYES;i++)
  {
		// Displaying the all the possible options
    printf("%d) %s\n",i+1,EYE_COLOR_NAMES[i]);
  }
  printf("> ");

	// Since our indexes
  int eyes = -1; // Better to initialize than have garbage values
  rc = fscanf(stdin," %d",&eyes);
  check(rc > 0,"You have to enter a number");

	// Here eyes stores the value as displayed values not the indexes
  you.eyes = eyes - 1; // Converting that value to indexes
  check(you.eyes <= OTHER_EYES && you.eyes >= 0,"Do it right, that's not an option.");

	// Storing the income 
  printf("How much do you make ? : ");
  rc = fscanf(stdin," %f",&you.income);
  check(rc > 0,"Enter a floating point number.")

  // Displaying the Results
  printf("-----------RESULTS-----------\n");
  printf("First Name: %s",you.first_name); // don't require new line here
  printf("Last Name: %s",you.last_name); // as fscanf stores it in the buffer
  printf("Age: %d\n",you.age);
  printf("Eyes: %s\n",EYE_COLOR_NAMES[you.eyes]);
  printf("Income: %0.2f\n",you.income);
  
  return 0;
  error:
    return -1;
	
}