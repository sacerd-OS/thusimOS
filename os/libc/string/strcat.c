#include "string.h"

char * strcat(char *dest, const char *src){
size_t dest_len = strlen(dest);
size_t i = 0;

// null byte is overwritten first
for (i = 0; src[i] != 0; i++)
    dest[dest_len + i] = src[i];

dest[dest_len + i] = 0; // readd nullbyte

return dest;
}
