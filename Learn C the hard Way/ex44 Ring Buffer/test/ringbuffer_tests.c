#include <lcthw/ringbuffer.h>
#include "minunit.h"

RingBuffer* buffer = NULL;

char* test_create()
{
	buffer = RingBuffer_create(15);
	mu_assert(buffer != NULL, "Failed to create the RingBuffer");
	
	return NULL;
}

char* test_destroy()
{
	RingBuffer_destroy(buffer);
	
	return NULL;
}

char* all_tests()
{
	mu_suite_start();
	
	mu_run_test(test_create);
	mu_run_test(test_destroy);
	
	return NULL;
}

RUN_TESTS(all_tests);