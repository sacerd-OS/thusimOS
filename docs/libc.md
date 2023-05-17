# libc Docs
This document describes each function of libc I implemented.

## stdio
These functions are defined in ``stdio.h``.
### void reverse(char str[], int length)
Source file: ``printf.c``

Reverses a string ``str[]`` of ``length`` in place.

### char* int2ascii(int num, char* str, int base)
Source file: ``printf.c``

Takes an integer ``num`` with the base ``base`` and converts it to a string, stored in ``str``.

### size_t printf(const char* restrict format, ...)
Source file: ``printf.c``

Takes in a string and a list of arguments and outputs a formatted string to the terminal. 

Currently supports the following formats:
- ``%%``
- ``%d``
- ``%x``
- ``%s``
- ``%c``

### int putchar(const char c)
Source file: ``putchar.c``

Puts a char ``c`` on the next index on the screen. Returns 1 on success.

### void void puts(const char* data)
Source file: ``puts.c``

Puts a string ``data`` onto the screen.

## stdlib
These functions are defined in ``stdlib.h``.

### int char2dig(char c)
Source file: ``atoi.c``

Returns the input character ``c`` as an integer.

### int pow10(int pow)
Source file: ``atoi.c``

Returns 10^``pow``. Simplification of the C stdlib function ``pow()``.

### int atoi(const char *nptr)
Returns the string ``nptr`` as an integer.

## string
These functions are defined in ``string.h``.

### char* strcat(char *dest, const char *src)
Source file: ``strcat.c``

Concats ``src`` to ``dest``.

### size_t strlen(const char* string)
Source file: ``strlen.c``

Returns the number of bytes in ``string`` before a null terminator is reached.