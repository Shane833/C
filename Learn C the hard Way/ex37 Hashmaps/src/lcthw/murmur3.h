#ifndef MURMUR3_H
#define MURMUR3_H

#include <stdint.h>
#include <lcthw/dbg.h>
#include <stdlib.h>
#include <time.h>

// Copy of murmur3_x86_32 function
uint32_t murmur3_32(const void * key, size_t len, uint32_t seed);
 
#endif