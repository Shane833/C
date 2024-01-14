#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

void read_things(const char *format,...)
{
	va_list argp;
	va_start(argp,format);
	
	char c = va_arg(argp,char);
	int number = va_arg(argp,int);
	printf("%d %c \n",number,c);
}

int main(int argc,char *argv[])
{
	int num = 3;
	char ch = 'a';
	read_things("245",num,ch);
	
}