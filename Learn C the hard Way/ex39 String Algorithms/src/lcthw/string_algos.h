#ifndef string_algos_h
#define string_algos_h

#include <lcthw/bstrlib.h>
#include <lcthw/darray.h>

typedef struct StringScanner{
	bstring in;
	const unsgined char* haystack;
	ssize_t hlen;
	const unsigned char* needle;
	ssize_t nlen;
	size_t skip_chars[UCHAR_MAX + 1];
}String Scanner;

int String_find(bstring in, bstring what);

StringScanner* StringScanner_create(bstring in);

int StringScanner_scan(StringScanner* scan, bstring tofind);

void StringScanner_destroy((StringScanner* scan);