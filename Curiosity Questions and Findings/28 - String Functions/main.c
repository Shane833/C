#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]){
   // Searching and Splitting string functions

   // 1. strstr - finds the occurrence of the needle in the haystack
   // on successful search it returns the address of the first match
   // else it returns NULL
    char *haystack = "I have some words that need to be found that is important that is neccesary";
    char *needle = "is";
    
    char *result = haystack;
    size_t needle_size = 0;

    // We can iteratively search through the haystack
    do{
        result = strstr(result + needle_size, needle); 
        printf("%s\n", result);
        if(result){
            needle_size = strlen(needle);
            result = result + needle_size;
        }else{
            break;
        }
    }while(result != NULL);

    // 2. strtok - breaks down the string into tokens as per the delimiter and appends
    // a null character at the end
    char string[] = "D:\\Shane\\C\\GitHub\\C\\Learn C the hard Way\\ex26 Project Logfind\\";
    // char *string = "This is a string"; This is a string literal which can't be used 
    // as strtok has to modify the string itself, hence it can't work with string literals
    // for tokenizing on the same string each subsequent call must be made by passing NULL
    for(char *ans = strtok(string, "\\"); ans != NULL; ans = strtok(NULL, "\\")){
        printf("Token : %s\n", ans);
    }

    // 3. strsep - This is the replacement for strtok
    // But this is not present on mingw I guess
    /*
    while((ans = strsep(&string, "\\"))){
        printf("Token : %s\n", ans);
    }
    */

    // 3. strchr - Returns the first occurrence of the specified character
    // if not then simply return NULL
    char *str = "C:\\Users\\Makefile";
    result = str;
    size_t char_size = 0;
    
    do{
        result = strchr(result + char_size, '\\');
        printf("%s\n", result);

        if(result){
            char_size = 1;
            result = result + char_size;
        }else{
            break;
        }
    }while(result != NULL);
   
    // 4. strrchr - Returns the first occurence of the specified character
    // but from the last, if not then simply return NULL
    // One example of this is that it can be used to identify
    // retrive the extensions from files
    str = "C:\\Users\\file.txt";
    char *extension = strrchr(str, '.');
    if(extension){
        printf("File Extension : %s\n", extension);
    }else{
        printf("File doesn't have an extension\n");
    }

    return 0;
}
