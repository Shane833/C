#include <stdio.h>

int main(int argc, char *argv[]){
	
	// You can print messages to the console through formatting using printf() function

	int age = 18;
	int height = 175;

	printf("I am %d years old.\n",age); // You will see various symbols like "%d,%f,%s,%c,%p etc" and these are  
										// simply templates/spaces where you can put specific things according to
										// its format (like int,float,string,character,pointer etc)
	printf("I am %d cms tall.\n",height); // Also in C language you have explicitely add new line unlike python 

	return 0;

}