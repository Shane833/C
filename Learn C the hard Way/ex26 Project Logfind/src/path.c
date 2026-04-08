#include <path.h>
#include <stdlib.h>
#include <string.h>

// Building it for setting up files for now
static inline bstring getParent(const char *path){
    bstring parent = NULL;

   // 1. If its a file
   if(Path_isFile(path)){
        // We can search for the first '\\' character from the last
        // and then move until that pointer, if nothing is found
        // then this suggests that the file belongs to the same 
        // directory as the the binary itself
        // Checking for both type of slashes
       char *char_ptr = strrchr(path, '\\') == NULL ? (strrchr(path, '/') \
               == NULL ? NULL : strrchr(path,'/')) : strrchr(path, '\\');

       if(char_ptr){
          // then we would need to get the path before the file name
          //size_t parent_size = (char_ptr - path) + 1; // +1 to include '\\' character
          size_t parent_size = char_ptr - path;
          
          char *parent_ptr = calloc(1, parent_size + 1); // +1 for the null character
          check(parent_ptr != NULL, "Failed to initialize parent!");
          
          strncpy(parent_ptr, path, parent_size);
          
          parent = bfromcstr(parent_ptr);
          check(parent != NULL, "Failed to initialize parent");
            
          free(parent_ptr);
       }else{
           char *parent_ptr = calloc(1, sizeof(char) + 1);
           check(parent_ptr != NULL, "Failed to initialize parent!");
           
           strcpy(parent_ptr,".");
            
           parent = bfromcstr(parent_ptr);
           check(parent != NULL, "Failed to initialize parent");

           free(parent_ptr);
       } 
   }else if(Path_isDir(path)){
       char *char_ptr = strrchr(path, '\\') == NULL ? (strrchr(path, '/') \
               == NULL ? NULL : strrchr(path,'/')) : strrchr(path, '\\');
        
       if(char_ptr){
           /*
           if(*(char_ptr + 1) == '\0'){ // This means its still the same directory
                                        // But this would still be true for other directories too
               char *parent_ptr = calloc(1, sizeof(char) + 1);
               check(parent_ptr != NULL, "Failed to initialize parent!");
            
               strcpy(parent_ptr,".");
                 
               parent = bfromcstr(parent_ptr);
               check(parent != NULL, "Failed to initialize parent");

               free(parent_ptr);
           */ 
            

      }else{
            char *parent_ptr = calloc(1, sizeof(char) + 1);
            check(parent_ptr != NULL, "Failed to initialize parent!");
            
            strcpy(parent_ptr,".");
             
            parent = bfromcstr(parent_ptr);
            check(parent != NULL, "Failed to initialize parent");

            free(parent_ptr);
      }
   }

   return parent;
error:
   if(parent) bdestroy(parent);
   parent = NULL;
   return NULL;
}

static inline void setupDirectory(Path *temp, const char *path){
    DIR *dir = opendir(path);
    check(dir != NULL, "Failed to open path!");

    temp->_path = bfromcstr(dir->dd_name);
    check(path != NULL, "Failed to create bstring!");
    
    // Cleanup the asterisk - slen is the actual length of the string
    bdelete(temp->_path, temp->_path->slen - 1, 1);
    // Initializing everything else
    temp->is_file = false;
    // Pointing to the actual data
    temp->path = bdata(temp->_path);
    
    getParent(path);
    closedir(dir);

error:
    return;
}

static inline void setupFile(Path *temp, const char *path){
    temp->_parent = getParent(path);
    check(temp->_parent != NULL, "Failed to find parent");
    temp->parent = bdata(temp->_parent);

error:
    return;
}

Path *Path_open(const char *path){
    check(path != NULL, "Invalid Path!");
    check(Path_exists(path) == true, "Something went wrong!");

    Path *temp = calloc(1, sizeof(Path));
    check(temp != NULL, "Failed to create Path object!");
    
    if(Path_isDir(path)){
       temp->is_dir = true;
       temp->is_file = false;
       setupDirectory(temp, path);
    }else if(Path_isFile(path)){
       temp->is_file = true;
       temp->is_dir = false;
       setupFile(temp, path);
    }

    return temp;
error:
    return NULL;
}

inline bool Path_isFile(const char *filepath){
    check(filepath != NULL, "Invalid file path!");
    
    FILE *file = fopen(filepath, "r");
    check_debug(file != NULL, "Unable to open file!");

    fclose(file);
    return true;
error:
    if(file) fclose(file);
    return false;
}

inline bool Path_isDir(const char *dirpath){
    check(dirpath != NULL, "Invalid directory path!");

    DIR *dir = opendir(dirpath);
    check_debug(dir != NULL, "Unable to open directory!");

    closedir(dir);
    return true;
error:
    if(dir) closedir(dir);
    return false;
}

inline bool Path_exists(const char *path){
    check(path != NULL, "Path does not exist!");
    return Path_isDir(path) || Path_isFile(path);
error:
    return false;
}

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

// Handy macro for identifying path type
#define PATHTYPE(path) Path_isDir((path)) ? "Directory" : (Path_isFile((path)) ? "File" : NULL)

inline char *Path_type(const char *path){
    check(path != NULL, "Invalid path!");
    return PATHTYPE(path);

error:
    return NULL;
}

// Destroying path object
void Path_destroy(Path *path){
    if(path){
       if(path->_path) bdestroy(path->_path);
       if(path->_parent) bdestroy(path->_parent);
       if(path->_name) bdestroy(path->_name);
       if(path->_stem) bdestroy(path->_stem);
       if(path->_suffix) bdestroy(path->_suffix);

       free(path); 
    }                                             
}
