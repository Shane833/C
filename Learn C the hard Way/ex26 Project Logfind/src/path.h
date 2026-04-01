/* Trying to provide an API similar to pathlib in python */
#ifndef PATH_H
#define PATH_H

#include <stdio.h>
#include <dirent.h>
#include <stdbool.h>
#include <bstrlib.h>
#include <darray.h>
#include <dbg.h>

// Declaring the struct
typedef struct{
    bstring _parent; 
    bstring _name;
    bstring _stem;
    bstring _suffix;
    bstring _path; // original path passed as argument
    
    const char *parent;
    const char *name;
    const char *stem;
    const char *suffix;
    const char *path;

    bool is_file;
    bool is_dir;
}Path;


Path *Path_open(const char *path);

bool Path_exists(const char *path);
void Path_listDirEnt(const char *path);
bool Path_isFile(const char *path);
bool Path_isDir(const char *path);
char *Path_type(const char *path);

void Path_destroy(Path *path);

#endif
