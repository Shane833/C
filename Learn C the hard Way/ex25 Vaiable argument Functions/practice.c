#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

void read_things(const char *format,...)
{
	va_list argp;
	va_start(argp,format);

	int number = va_arg(argp,int);
	char c = va_arg(argp, int);
    char *str = va_arg(argp, char*);
	printf("%d %c %s\n",number,c,str);
}

int main(int argc,char *argv[])
{
	int num = 3;
	char ch = 'a';
	read_things("245",num,ch, "Hello");

    return 0;
}
