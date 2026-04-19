#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>

#if defined (__linux__)
#include <unistd.h>
#include <limits.h>
#elif defined (_WIN32)
#include <windows.h>
#endif

int main(){

    // NOTE: Main Problem here
    // In windows, the new line is represented as \r\n i.e. by 2 bytes
    // However in linux, its just \n which is one byte
    // Using fgetc it counts the \r for windows, when we open in text mode
    // hence the actual length becomes line_len + 1 only in windows
    // So, in order for this to be  

    FILE *file = fopen("file2.txt", "rb");
    if(!file){ exit(EXIT_FAILURE); }

    char buffer[512] = { '\0' };
    size_t line_len = 0; 

    unsigned char c = '\0';
    while(!feof(file)){
        c = fgetc(file);
        //printf("%c", c);
        line_len++;

        if(c == '\n'){
            //printf("len:%llu ", line_len);
            // Currently line_len represents index
            // we convert to actual size by adding one
            // Move back the to the start of the line
            fseek(file, -(line_len), SEEK_CUR);
            // get the line
            int pos = ftell(file);
            //printf("File Position : %d\n", pos);
            fgets(buffer, line_len + 1, file);
            //fgets(buffer, 512, file);
            printf("line : %s", buffer);
            // Reset the line length
            line_len = 0;
        }
    } 

    fclose(file);

    DIR *dir = opendir(".");
    if(!dir){ exit(EXIT_FAILURE); }
    
    // Here we can't dereference dir bcz on linux systems
    // DIR is opaque hence its details are not available
    // before it gets linked to glibc
    //printf("Directory name : %s\n", dir->dd_name);
    char abs_path[PATH_MAX] = { '\0' };
    
    #if defined (__linux__)
    if(realpath(".", abs_path) == abs_path){
        printf("Absolute Path : %s\n", abs_path);
    }
    #elif defined (_WIN32)
    if(GetFullPathNameA("socks", PATH_MAX, abs_path, NULL) != 0){
        printf("Absolute Path : %s\n", abs_path);
    }
    #endif    
    closedir(dir);

return 0;
}
