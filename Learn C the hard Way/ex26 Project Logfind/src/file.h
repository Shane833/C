#ifndef FILE_H
#define FILE_H

#include <path.h>

typedef enum {
    READ_ONLY,
    WRITE_ONLY,
    READWRITE_ONLY,
    APPEND_ONLY
}ACCESS_MODE;

// Represents a single line in the file
typedef struct{
    bstring data;
    size_t line_no;
}Line;

typedef struct{
    Path *file; 
    FILE *fileptr;
    Line *current_line;
    DArray *lines;
}File;

File *File_open(const char *filepath, ACCESS_MODE mode);

int File_readlines(File *file);
int File_readline(File *file);
int File_writeline(File *file);
int File_writelines(File *file);
// Searches a words in a file
int File_search(File *file, bstring word, DArray *result);

int File_reset(File *file);
void File_close(File *file);

#endif
