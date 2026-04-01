#if defined (_WIN32)
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

void* my_work(void * any_data)
{
	printf("Say hello to my little thread!\n");
}

int main()
{
	// Declare a thread variable 
	pthread_t thread;

	// Start the thread
	int result = pthread_create(&thread, NULL, my_work, NULL);

	// On successful creation, this function will return 0, if not some error value
	if(result){ // if it returns 0, this if block won't run
		fprintf(stdout, "ERROR : Failed to create thread");
		exit(1);
	}

	// waits for the thread to finish
	pthread_join(thread, NULL);

	return 0;
}

#elif defined (__linux__)
#include <threads.h>
#include <stdio.h>

typedef int (*thrd_start_t)(void*);


int main(){
   
    return 0;
}
#endif
