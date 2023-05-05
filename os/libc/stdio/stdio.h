#ifndef __STDIO 
#define __STDIO
#include <stddef.h>
#define EOF -1

void puts(const char* data);
int putchar(const char c);
size_t printf(const char* __restrict, ...);

#endif