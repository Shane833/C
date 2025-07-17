#ifndef MURMUR3_H
#define MURMUR3_H

#include <stdint.h>
#include <dbg.h>

// Copy of murmur3_x86_32 function
uint32_t murmur3_32(const void * key, size_t len);

#endif