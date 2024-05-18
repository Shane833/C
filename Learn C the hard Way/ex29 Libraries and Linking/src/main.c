#include <stdio.h>
#include "dbg.h"
#include <dlfcn.h>
#include <string.h>

typedef int (*lib_function) (const char* data);

int main(int argc, char* argv[]){
	int rc = 0;
	check(argc == 4, "USAGE: main lib.so function data");
	
	char* lib_file = argv[1];
	char* func_to_run = argv[2];
	char* data = argv[3];
	
	// This function is used to load and return a handle to the shared object/library
	// RTLD_NOW flag resolves all the undefined symbols in the library
	void* lib = dlopen(lib_file, RTLD_NOW);
	check(lib != NULL, "Failed to open the library %s: %s", lib_file,dlerror());
	
	// This function to used to get a pointer to a function by its name from the shared library
	lib_function func = dlsym(lib, func_to_run);
	check(func != NULL, "Did not find %s function int he library %s: %s", func_to_run, lib_file, dlerror());
	
	rc = func(data);
	check(rc == 0, "Function %s return %d for data: %s", func_to_run, rc, data);
	// In the end we close the library just like we close a file
	// However we usually keep it up the whole time the program is running
	rc = dlclose(lib);
	check(rc == 0, "Failed to close %s", lib_file);
	
	return 0;
	
	error:
		return 1;
}