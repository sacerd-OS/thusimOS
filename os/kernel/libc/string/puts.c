#include "string.h"
#include "../etc/terminal.h"

void puts(const char* data) {
    for (size_t i = 0; i < strlen(data); i++)
		t_putchar(data[i]);
}