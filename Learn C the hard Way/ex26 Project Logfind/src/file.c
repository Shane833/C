#include <file.h>
#include <stdio.h>
#include <stdlib.h>

File *File_open(const char *filepath, ACCESS_MODE mode){
    check(filepath != NULL, "Invalid file path!");
    check((Path_exists(filepath) && Path_isFile(filepath)) == true, "Invalid file path!");

    File *temp = malloc(sizeof(File));
    check(temp != NULL, "Failed to create file!");
    
    temp->file = Path_open(filepath);
    check(temp->file != NULL, "Failed to open file!");

    temp->fileptr = fopen(filepath, "r+");
    check(temp->fileptr != NULL, "Failed to open file!");
    
    // Setting all bytes to null characater
    check_debug(memset(temp->current_line.data, '\0', MAXLINELEN) == temp->current_line.data,\
            "Failed to initialize line!");
    temp->current_line.line_no = 0; // Initially set to zero to depict file not read yet
    
    temp->lines = NULL;

    return temp;
error:
    File_close(temp);
    return NULL;
}

char *File_readline(File *file){
    check(file != NULL, "Invalid File Object!");

    char *result = fgets(file->current_line.data, MAXLINELEN + 1, file->fileptr);

    check_debug(result == file->current_line.data && (!feof(file->fileptr)), "Wrong result from fgets!");

    file->current_line.line_no++;
    
    return (char *)1;
error:
    return NULL;
}

void File_readlines(File *file){
    check(file != NULL, "Invalid File Object!");
    // store the current position in the file
    long pos = ftell(file->fileptr);
    check_debug(pos != -1, "Failed to get the file position!");

    // Reset the file position 
    check_debug(fseek(file->fileptr, 0, SEEK_SET) == 0, "Failed to set the file position!");
    
    // Create our DArray of lines
    file->lines = DArray_create(sizeof(Line), 100);
    check(file->lines != NULL, "Failed to read lines!");

    char buffer[MAXLINELEN] = { '\0' };
    size_t line_no = 0;

    while(fgets(buffer, MAXLINELEN + 1, file->fileptr) != NULL){
        Line *line = malloc(sizeof(Line));
        check_debug(line != NULL, "Failed to initialize the line!");  

        check_debug(strncpy(line->data, buffer, MAXLINELEN + 1) == line->data,\
                "Failed to copy lines!");
        line->line_no = ++line_no;
        check_debug(DArray_push(file->lines, line) == 0, "Failed to push line!");
    }
    
    // Go back to the same file position
    check_debug(fseek(file->fileptr, pos, SEEK_SET) == 0, "Failed to set the file position!");
    
    return;
error:
    if(file->lines){ 
        DArray_clear_destroy(file->lines);
    }
    return;
}

int File_reset(File *file){
    check(file != NULL, "Invalid File Object!");
    // Reset file position
    check_debug(fseek(file->fileptr, 0, SEEK_SET) == 0, "Failed to set the file position!");
    // Reset the current line
    check_debug(memset(file->current_line.data, '\0', MAXLINELEN) == file->current_line.data,\
            "Failed to initialize line!");
    file->current_line.line_no = 0; // Initially set to zero to depict file not read yet

    if(file->lines){
        DArray_clear_destroy(file->lines);
        file->lines = NULL;
    }

    return 0;
error:
    return -1;
}

void File_close(File *file){
    if(file){
        if(file->fileptr){
            fclose(file->fileptr);
            file->fileptr = NULL;
        }
        if(file->file){
            Path_destroy(file->file);
            file->file = NULL;
        }
        if(file->lines){
            DArray_clear_destroy(file->lines);
            file->lines = NULL;
        }
        memset(file->current_line.data, '\0', MAXLINELEN);
        file->current_line.line_no = 0;

        free(file);
    }
}
