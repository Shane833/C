#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){

    FILE *file = fopen("file.txt", "r+");
    if(!file){ exit(EXIT_FAILURE); }

    char buffer[512] = { '\0' };
    size_t line_len = 0; 

    unsigned char c = '\0';
    while(!feof(file)){

        c = fgetc(file);
        line_len++;

        if(c == '\n'){
            printf("len:%llu ", line_len);
            // Currently line_len represents index
            // we convert to actual size by adding one
            // Move back the to the start of the line
            fseek(file, -(line_len + 1), SEEK_CUR);
            // get the line
            fgets(buffer, line_len + 1, file);

            printf("line : %s", buffer);

            // Reset the line length
            line_len = 0;
        }
    } 

    fclose(file);

    return 0;
}
