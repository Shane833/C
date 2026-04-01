#ifndef FILE_H
#define FILE_H

#include <path.h>

#define MAXLINELEN 512

typedef enum {
    READ_ONLY,
    WRITE_ONLY,
    READWRITE_ONLY,
    APPEND_ONLY
}ACCESS_MODE;

// Represents a single line in the file
typedef struct{
    char data[MAXLINELEN];
    size_t line_no;
}Line;

typedef struct{
    Path *file; // 
    FILE *fileptr;
    Line current_line;
    DArray *lines;
}File;

File *File_open(const char *filepath, ACCESS_MODE mode);

void File_readlines(File *file);
char *File_readline(File *file);
size_t File_writelines(File *file, DArray *lines);

int File_reset(File *file);
void File_close(File *file);

#endif
