#include <wchar.h>
#include <stdio.h>

int main(){
    //  You need to put 'L' to make it a wide string
    FILE *file = fopen("file.log", "rb");
    if(!file) { return -1; }

    wchar_t buffer[512] = { '\0' };

    while(!feof(file)){
        fgetws(buffer, 512, file);
        wprintf(L"%ls", buffer);
    }

    fclose(file);

    return 0;
}
