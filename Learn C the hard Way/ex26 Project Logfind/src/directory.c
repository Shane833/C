#include <directory.h>
/*
inline void Path_listDirEnt(const char *dirpath){
    if(Path_exists(dirpath) && Path_isDir(dirpath)){
        DIR *dir = opendir(dirpath);
        check(dir != NULL, "Unable to open directory!");

        struct dirent *items = NULL;

        while((items = readdir(dir)) != NULL){
           fprintf(stdout, "%s\n", items->d_name); 
        }

        items = NULL;
        closedir(dir);
    }
    else{
        log_err("Invalid directory!");
    }
error:
    return;
}
*/
