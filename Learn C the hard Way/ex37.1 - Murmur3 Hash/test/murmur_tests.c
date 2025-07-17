#include "minunit.h"
#include <murmur3.h>

char * test_hash()
{
	uint32_t hash = murmur3_32("Hello",5);
	mu_assert(hash == 316307400, "Wrong result for hash!");

	hash = murmur3_32("Hello World!", 12);
	mu_assert(hash == 3691591037, "Wrong result for hash!");

	return NULL;
}

char * all_tests()
{
	mu_suite_start();
	mu_run_test(test_hash);

	return NULL;
}

RUN_TESTS(all_tests)