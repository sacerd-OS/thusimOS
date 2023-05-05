#include "stdio.h"
#include <stdarg.h>
#include <stdbool.h>

int printf(const char* restrict format, ...){
    int written = 0;
    va_list ag;
    va_start(ag, format);

    while(*format != EOF){
        // if *format == %
        // if *format + 1 == d: print int
        // if *format + 1 == c: print c
        // if *format + 1 == s: print s. for s you want to written + len 
        // if *format + 1 == EOf: return written

        // else print char and go onto the next format char
        // written++, format++
    }

    va_end(ag);

    return written;   
}