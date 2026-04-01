#include <file.h>
#include "minunit.h"

File *file = NULL;

char *test_create(){
    file = File_open("src/path.h", READWRITE_ONLY);
    mu_assert(file != NULL, "Failed to open file!");

    return NULL;
}

char *test_readline(){
   
    /*
    while(File_readline(file) != NULL){
        printf("%llu:%s", file->current_line.line_no, file->current_line.data);
    }
    */

    printf("Initially : %s\n", file->current_line.data);
    File_readline(file); 
    printf("Line : %s\n", file->current_line.data);
    return NULL;
}

char *test_reset(){
    File_reset(file);

    mu_assert(ftell(file->fileptr) == 0, "Failed to reset the file position!");
    mu_assert(file->current_line.line_no == 0, "Failed to reset the current line!");

    return NULL;
}

char *test_readlines(){
    File_readlines(file);
    mu_assert(file->lines != NULL, "Failed to read lines!");
    
    for(size_t i = 0;i < DArray_count(file->lines);i++){
        Line *line = (Line *)DArray_get(file->lines, i);
        printf("%llu:%s", line->line_no, line->data);
    }

    return NULL;
}

char *test_close(){
    File_close(file);
}

char *all_tests(){
    mu_suite_start(); 

    mu_run_test(test_create);
    mu_run_test(test_readline);
    //mu_run_test(test_reset);
    mu_run_test(test_readlines);
    mu_run_test(test_readline);
    return NULL;
}

RUN_TESTS(all_tests);
