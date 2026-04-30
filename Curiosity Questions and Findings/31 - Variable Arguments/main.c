#include <stdio.h>
#include <stdarg.h>

#define VAR(...) printf(__VA_ARGS__)

void varList(const char *fmt, ...){
   va_list argp;
   va_start(argp, fmt);

   fprintf(stderr, "The things you wanted to print : ");
   vfprintf(stderr,fmt, argp);
   fprintf(stderr, "\n");

}

int main(){
    int a = 5;
    varList("Hello there!");

    VAR("Hello %d", 2);

    return 0;
}
