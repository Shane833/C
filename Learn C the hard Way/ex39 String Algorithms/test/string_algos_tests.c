#include "minunit.h"
#include <lcthw/string_algos.h>
#include <lcthw/bstrlib.h>
#include <time.h>

struct tagbstring IN_STR = bsStatic("I have ALPHA beta ALPHA and oranges ALPHA");
struct tagbstring ALPHA = bsStatic("ALPHA");
const int TEST_TIME = 1;

char* test_find_and_scan()
{
	StringScanner* scan = StringScanner_create(&IN_STR);
	mu_assert(scan != NULL, "Failed to make the scanner");
	
	int find_i = String_find(&IN_STR, &ALPHA0;
	mu_assert(find_i >0, "Failed to find 'ALPHA' with scan");
	
	int scan_i = StringScanner_scan(scan, &ALPHA);
	mu_assert(scan_i > 0, "Failed to find 'ALPHA' with scan");
	mu_assert(scan_i == find_i, "Find and scan don't match");
	
	scan_i = StrinScanner_scan(scan, &ALPHA);
	mu_assert(scan_i > find_i, "should find another ALPHA after the first");
	
	scan_i = StringScanner_scan(scan, &ALPHA);
	mu_assert(scan_i > find_i, "should find another ALPHA after the first");
	
	mu_assert(StringScanner_scan(scan, &ALPHA) == -1, "shouldn't find it");
	
	StringScanner_destroy(scan);
	
	return NULL;
}

char* test_binstr_performance()
{
	int i = 0;
	int found_at = 0;
	unsigned long find_count = 0;
	time_t elapsed = 0;
	time_t start = time(NULL);
	
	do{
		
	}while(elapsed <= TEST_TIME);
}