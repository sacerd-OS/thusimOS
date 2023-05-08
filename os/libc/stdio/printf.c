#include "stdio.h"
#include "../stdlib/stdlib.h"
#include "../string/string.h"

#include <stdarg.h>
#include <stdbool.h>

static void print(const char* data) {
    for (size_t i = 0; i < strlen(data); i++)
		putchar(data[i]);
}

void reverse(char str[], int length){
    int start = 0;
    int end = length - 1;
    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        end--;
        start++;
    }
}

char* int2ascii(int num, char* str, int base){
    int i = 0;
    bool isNegative = false;
 
    /* Handle 0 explicitly, otherwise empty string is
     * printed for 0 */
    if (num == 0) {
        str[i++] = '0';
        str[i] = '\0';
        return str;
    }
 
    if (num < 0 && base == 10) {
        isNegative = true;
        num = -num;
    }
    // Process individual digits
    while (num != 0) {
        int rem = num % base;
        str[i++] = (rem > 9) ? (rem - 10) + 'a' : rem + '0';
        num = num / base;
    }

    if (isNegative)
        str[i++] = '-';
 
    str[i] = '\0';
    reverse(str, i);
    return str;
}

size_t printf(const char* restrict format, ...){
    size_t written = 0;
    va_list ag;
    va_start(ag, format);

    while(*format != EOF && *format != 0){
        if(*(format) == '%'){
            switch(*(format+1)){
                case '%':
                putchar('%');
                written++; format++;
                break;

                case 'd': ;
                char strr[256];
                int integer = va_arg(ag, int);
                print(int2ascii(integer,strr, 10));
                written++;
                break;

                case 'x': ; 
                 char strrr[256];
                int hex = va_arg(ag, int);
                print(int2ascii(hex,strrr, 16));
                written++;
                break;
                
                case 'c': ;
                char c = (char)va_arg(ag, int); // ill have 2 give myself a promotion...2day!
                putchar(c);
                written++;
                break;
                
                case 's': ;
                const char* str = va_arg(ag, const char*);
                print(str);
                written+= strlen(str);
                break;

                case -1: ;
                return written;

                default:
                continue;
            }
            format+=2;
        }
        else{
            putchar(*format);
            format++;
            written++;
        }
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