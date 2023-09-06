#include <stdio.h>

int main(int argc,char *argv[]){

int distance = 100;
float power = 2.345f;// using f explicitely declares the number as a floating point memory
double superPower = 56789.4532;
char initials = 'K';
char firstname[] = "Shivang";
char lastname[] = "Singh";

// now we will break this program 
// first we can start by pointing outside of our string
// Like our character string for firstname have 7 chararcters in it and so its index is 0-6
// Therefore by referencing outside of it we can make it do crazy stuff

firstname[7] = 'G';

printf("You are %d miles away.\n",distance);
printf("You have %f levels of power.\n",power);
printf("You have %lf awesome super power.\n",superPower);
printf("My first name :  %s\n",firstname);
printf("My last name :  %s\n",lastname);
printf("My full name : %s %c. %s\n",firstname + 100,initials,lastname); // upon adding 100 to our pointer for firstname we can see that it start pointing outside of the index range and hence we see nothing

int bugs = 100;
double bug_rate = 1.2;
printf("You have %d bugs at %lf imaginary rate.\n",bugs,bug_rate);

long universe_of_defects = 1L * 1024L * 1024L * 1024L; // L stands for long integers
printf("The Entire Universe has %ld bugs.\n",universe_of_defects);// %ld is the format for long integers

double expected_bugs = bugs * bug_rate;
printf("You are expected to have %f bugs.\n",expected_bugs);

double part_of_universe = expected_bugs/universe_of_defects;
printf("This is only a %e portion of the universe.\n",part_of_universe);// %e format is used when the number is very very small in this case 10^-7 also called exponential notation

char nul_byte = '\0'; // Variable of type characters are also numbers and this is equivalent of 0 in integers
int care_percentage = nul_byte * bugs;

printf("Thats why you should care %d%%.\n",care_percentage);// in order to show the '%' sign you would have to use %% format

return 0;

}