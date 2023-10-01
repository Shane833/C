#ifndef __dbg_h__
#define __dbg_h__

#include <stdio.h>
#include <errno.h>
#include <string.h>

#ifdef NDEBUG
#define debug(M, ...)
#else
#define debug(M, ...) fprintf(stderr, "DEBUG %s:%d: " M "\n",__FILE__, __LINE__, ##__VA_ARGS__)
#endif

#define clean_errno() (errno == 0 ? "None" : strerror(errno))

#define log_err(M, ...) fprintf(stderr,"[ERROR] (%s:%d: errno: %s) " M "\n", __FILE__, __LINE__,\
						clean_errno(), ##__VA_ARGS__)

#define log_warn(M, ...) fprintf(stderr,"[WARN] (%s:%d: errno: %s) " M "\n",__FILE__, __LINE__,\
						clean_errno(), ##__VA_ARGS__)

#define log_info(M, ...) fprintf(stderr, "[INFO] (%s:%d) " M "\n",__FILE__, __LINE__, ##__VA_ARGS__)

#define check(A, M, ...) if(!(A)){ log_err(M, ##__VA_ARGS__); errno = 0; goto error; }

#define sentinel(M, ...) {log_err(M, ##__VA_ARGS__);errno = 0; goto error; }

#define check_mem(A) check((A),"Out of memory.")

#define check_debug(A, M, ...) if((!A)) {debug(M, ##__VA_ARGS__);}errno = 0; goto error; }

#endif

// Using the character '\' is optional as it works as an escape character, which lets us jump to the next line
// while still continuing the flow of the program
// Eg : You can define a statement to be printed like this
// 1. printf("Hello there");
// 2. printf("Hello\
			there");
// Both ways are valid 
// Using '\' character we can still continue writing our statement even when its in new line

// __FILE__ : This is pre-defined string which contains the name of the file where it is called
// __LINE__ : This is a pre-defined variable which stores the line number where its called is used
