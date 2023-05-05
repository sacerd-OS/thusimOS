#include "stdio.h"
#include "../etc/terminal.h"
#include "../string/string.h"

void puts(const char* data) {
    for (size_t i = 0; i < strlen(data); i++)
		putchar(data[i]);
    putchar('\n');
}