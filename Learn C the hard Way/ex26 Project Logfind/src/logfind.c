#include <file.h>
#include <directory.h>
#include <string.h>
#include <dbg.h>

int main(int argc, char* argv[]){

    if(argc == 1){ 
         fprintf(stderr, "[ERROR] Wrong Usage! logfind [word(s)]\n");
         exit(EXIT_FAILURE);
    }
    // The location to look for log files will be fixed
    Directory *dir = Directory_open("logs");
    check(dir != NULL, "Failed to create directory!");
 
    bstring word = bfromcstr(argv[1]);
    check(word != NULL, "Failed to create bstring word!");
   
    // Read the entries
    DArray *entries = DArray_create(sizeof(bstring), 20);
    check(entries != NULL, "Failed to create entries DArray!");

    check(Directory_getDirEnt(dir, entries) == 0, "Failed to get directory entries!");
    
    // DArray to read the results
    DArray *result = DArray_create(sizeof(bstring), 50);
    check(result != NULL, "Failed to create result DArray!");

    // check for files with suffix = .log
    bstring suffix = bfromcstr(".log");
    check(suffix != NULL, " Failed to create suffix bstring!");
    
   for(int i = 0;i < DArray_count(entries);i++){
       bstring entry = (bstring)DArray_get(entries, i); 
       if(entry){
           // Generate the new path for file
           bstring entry_path = bformat("%s%s", bdata(dir->dir->path), bdata(entry));
           check(entry_path != NULL, "Failed to create entry path!");

           // Get the suffix from our path
           if( Path_isFile(bdata(entry_path)) ){
               bstring extension = Path_getFileSuffix(bdata(entry_path));
               if(extension){
                    // compare the extensions
                    if(bstrcmp(suffix, extension) == 0){
                        // Open this file and search for the word
                        File *file = File_open(bdata(entry_path), READ_ONLY);
                        check(file != NULL, "Failed to open file!");

                        check(File_search(file, word, result) == 0, "Failed to search file : %s", bdata(entry_path)); 

                        File_close(file);
                    }
                }
               bdestroy(extension);
           }
           bdestroy(entry_path);
       }

       bdestroy(entry);
   }  
    
   // printing the found data
    for(int i = 0;i < DArray_count(result);i++){
        bstring data = (bstring)DArray_get(result, i);
        if(data){
            printf("%s", bdata(data));
        }
    }
    
   // Closing and freeing resources
    bdestroy(word); 

    for(int i = 0;i < DArray_count(entries);i++){
        bstring temp = (bstring)DArray_get(entries, i);
        if(temp){
            bdestroy(temp);
        }
    }
    DArray_destroy(entries);

    for(int i = 0;i < DArray_count(result);i++){
        bstring temp = (bstring)DArray_get(result, i);
        if(temp){
            bdestroy(temp);
        }
    }
    DArray_destroy(result);

    Directory_close(dir);
    
    return 0;
error:
    return -1;
}
