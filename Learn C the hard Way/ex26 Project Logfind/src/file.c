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
    
    temp->current_line = malloc(sizeof(Line));
    check(temp->current_line != NULL, "Failed to initialize line!");

    temp->current_line->data = NULL;
    temp->current_line->line_no = 0; // Initially set to zero to depict file not read yet
    
    temp->lines = NULL;

    return temp;
error:
    File_close(temp);
    return NULL;
}

int File_readline(File *file){
    check(file != NULL, "Invalid File Object!");
    check(file->fileptr != NULL, "No file opened!");

    size_t line_len = 0; 
    unsigned char c = '\0';

    while(!feof(file->fileptr)){

        c = fgetc(file->fileptr);
        line_len++;

        if(c == '\n'){
            check(file->current_line != NULL, "");
            // Deallocate line if it has something
            if(file->current_line->data){
                bdestroy(file->current_line->data);
                file->current_line->data = NULL;
        }
            // Allocate the line
            file->current_line->data = malloc(sizeof(struct tagbstring));
            check_debug(file->current_line->data != NULL, "Failed to initialized line");
            // Currently line_len represents index
            // we convert to actual size by adding one
            // Move back the to the start of the line
            fseek(file->fileptr, -(line_len + 1), SEEK_CUR);
            // get the line
            // Allocate the line data and copy the line
            file->current_line->data->data = calloc(1, line_len + 1);
            check_debug(file->current_line->data->data != NULL, " Failed to initialize line data");
            file->current_line->data->mlen = file->current_line->data->mlen = line_len; 
            // fgets, if successful returns the address of the passed buffer
            check(fgets(file->current_line->data->data, line_len + 1,\
                        file->fileptr) == file->current_line->data->data, "Failed to read the line!");

            break;
        }
    }
    // If we are already at the end of the file don't do anything 
    if(feof(file->fileptr)){
        fprintf(stderr, "[INFO] End of File reached!\n");
        return -1; // but this is not a failed state, its completely fine 
    }else{
        check(file->current_line != NULL, "");
        file->current_line->line_no++;
        return 0;
    }

error:
    // Reset the line
    if(file->current_line->data){
        bdestroy(file->current_line->data);
        file->current_line->data = NULL;
    }
    file->current_line->line_no = 0;
    return -1;
}

int File_readlines(File *file){
    check(file != NULL, "Invalid File Object!");
    // store the current position in the file
    long pos = ftell(file->fileptr);
    check_debug(pos != -1, "Failed to get the file position!");

    // Reset the file position 
    check_debug(fseek(file->fileptr, 0, SEEK_SET) == 0, "Failed to set the file position!");
    
    // Create our DArray of lines
    // Assuming initially the file to have 100 lines
    file->lines = DArray_create(sizeof(Line), 100);
    check(file->lines != NULL, "Failed to read lines!");

    bstring data = NULL;
    unsigned char c = '\0';
    size_t line_no = 0;
    size_t line_len = 0;

    while(!feof(file->fileptr)){
        c = fgetc(file->fileptr);
        line_len++;
        
        if(c == '\n'){
            Line *line = malloc(sizeof(Line));
            check_debug(line != NULL, "Failed to initialize the line!");  
            
            line->data = malloc(sizeof(struct tagbstring));
            check_debug(line->data != NULL, "Failed to initialize bstring!");
            
            line->data->data = calloc(1, line_len + 1);
            check_debug(line->data->data != NULL, "Failed to initialize bstring data!");
            line->data->slen = line->data->mlen = line_len;
            // Moving back the file pointer
            fseek(file->fileptr, -(line_len + 1), SEEK_CUR);
            /// fgets, if successful returns the address of the passed buffer
            check(fgets(line->data->data, line_len + 1, file->fileptr) == line->data->data, "Failed to read the line!");

            line->line_no = ++line_no;
            check_debug(DArray_push(file->lines, line) == 0, "Failed to push line!");
            
            line_len = 0;
        }
    }
    
    // Go back to the same file position
    check_debug(fseek(file->fileptr, pos, SEEK_SET) == 0, "Failed to set the file position!");
    
    return 0;
error:
    if(file->lines){ 

        DArray_destroy(file->lines);
    }
    return -1;
}

// Reads the lines from the file one by one
// Searches for the provided word in those files
// If found adds the line no and the charcter position
// of the word found in the results DArray
// returns 0 on success and -1 if it fails
int File_search(File *file, bstring word, DArray *result){
    check(file != NULL, "Invalid File Object!");
    check(file->fileptr != NULL, "No file opened!");
    check(word != NULL, "Invalid word!")
    check(word->slen >= 0 && word->mlen >= word->slen && word->data != NULL, "Invalid word data!");
    check(result != NULL, "Invalid result DArray!");

    while(!feof(file->fileptr)){
        if(File_readline(file) == 0){
            
        }else{
            break;
        }
    }

    return 0;
error:
    return -1;
}

int File_reset(File *file){
    check(file != NULL, "Invalid File Object!");
    // Reset file position
    check_debug(fseek(file->fileptr, 0, SEEK_SET) == 0, "Failed to set the file position!");
    // Reset the current line
    if(file->current_line->data){
        bdestroy(file->current_line->data);
        file->current_line->data = NULL;
    }
    file->current_line->line_no = 0; // Initially set to zero to depict file not read yet

    if(file->lines){
        for(size_t i = 0;i < DArray_count(file->lines);i++){
            bstring temp = (bstring)DArray_get(file->lines, i);
            if(temp){
                bdestroy(temp);
            }
        }
        DArray_destroy(file->lines);
        file->lines = NULL;
    }

    return 0;
error:
    return -1;
}

int File_writeline(File *file){
    check(file != NULL, "Invalid File Object!");    

    // Check the access mode
    
    // Check if the line have some data



    return 0;
error:
    return -1;
}

int File_writelines(File *file){
    check(file != NULL, "Invalid File Object!"); 

    // Check the access mode
    
    // Check the DArray lines if it contains any data

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
            for(size_t i = 0;i < DArray_count(file->lines);i++){
                bstring temp = (bstring)DArray_get(file->lines, i);
                if(temp){
                    bdestroy(temp);
                }
            }
            DArray_destroy(file->lines);
            file->lines = NULL;
        }
        if(file->current_line){
            if(file->current_line->data){
                bdestroy(file->current_line->data);
                file->current_line->data = NULL;
            }
            file->current_line->line_no = 0;
            free(file->current_line);
        }

        free(file);
    }
}
