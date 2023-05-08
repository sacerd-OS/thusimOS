#include "stdio.h"
#include "../etc/terminal.h"
#include "../string/string.h"

// puts adds a newline at the end. otherwise its just for(chars) print(char)
void puts(const char* data) {
    for (size_t i = 0; i < strlen(data); i++)
		  putchar(data[i]);
    putchar('\n');
}