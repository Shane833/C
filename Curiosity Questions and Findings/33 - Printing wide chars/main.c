#include <wchar.h>
#include <stdio.h>
#include <locale.h> // you need this to specify the encoding for the wide character you're using

int main(){
       
    setlocale(LC_ALL, "");
   
    wchar_t a = 0xC389;

    printf("%lc\n",a);

    return 0;
}
