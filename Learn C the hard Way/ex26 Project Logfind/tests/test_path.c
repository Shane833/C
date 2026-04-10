#include <path.h>
#include "minunit.h"
#include <string.h>
#include <dirent.h>

char *test_file()
{
    Path *file = NULL;
    /*
    file = Path_open("Makefile");
    mu_assert(file != NULL, "Failed to create path object");
    mu_assert(strcmp(file->parent, ".") == 0, "Wrong parent!");
    Path_destroy(file);

    file = Path_open("src/path.py");
    mu_assert(file != NULL, "Failed to create path object");
    mu_assert(strcmp(file->parent, "src") == 0, "Wrong parent!");
    Path_destroy(file);
    */

    file = Path_open("src/");
    mu_assert(file != NULL, "Failed to create path object");
    printf("File: %d, Directory: %d\n", file->is_file, file->is_dir);
    //mu_assert(strcmp(file->parent, "src") == 0, "Wrong parent!");
    Path_destroy(file);

    return NULL;
}

char *all_tests(){
    mu_suite_start();
    mu_run_test(test_file);
    return NULL;
}

RUN_TESTS(all_tests)
