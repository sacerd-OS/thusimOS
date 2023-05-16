#include "stdio.h"
#include "../stdlib/stdlib.h"
#include "../string/string.h"

#include <stdarg.h>
#include <stdbool.h>

static int print(const char* data) {
    for (size_t i = 0; i < strlen(data); i++)
		putchar(data[i]);
}
 
// REFERSE AND INT2ASCII ARE NOT MINE I TOOK THEM
// FROM STACK OVERFLOW, AS ALL GOOD SWES DO
// THIS IS BECAUSE WRITING AN ITOA() FUNCTION IS HARD
// AND IT'S NOT APART OF THE C STDLIB BECAUSE THEY
// HATE ME IN PARTICULAR
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
 
    // Handle 0 explicitly
    if (num == 0) {
        str[i++] = '0';
        str[i] = '\0';
        return str;
    }
 
    // negative
    if (num < 0 && base == 10)
        num = -num;

    // Process individual digits
    while (num != 0) {
        int rem = num % base;
        str[i++] = (rem > 9) ? (rem - 10) + 'a' : rem + '0';
        num = num / base;
    }

    // negative part 2
    if (num < 0 && base == 10)
        str[i++] = '-';
 
    str[i] = '\0';
    reverse(str, i);
    return str;
}

size_t printf(const char* restrict format, ...){
    // we need to return the no. bytes written
    size_t written = 0;
    // va_list is an obscureish c feature
    // which basically allows u to proces an infinite
    // list of arguments using va_arg() to getNExt
    va_list ag;
    va_start(ag, format);

    // try changing this to || for insane effects
    while(*format != EOF && *format != 0){
        if(*(format) == '%'){
            switch(*(format+1)){
                // if %%
                case '%':
                putchar('%');
                written++; format++;
                break;

                // if %d
                // hardest case b/c you need to transform
                // int to str
                case 'd': ; // the ; is to prevent a compiler error relating to the declaration of strr
                char strr[256];
                int integer = va_arg(ag, int);
                print(int2ascii(integer,strr, 10));
                written+=strlen(strr); // per printf spec
                break;

                case 'x': ; 
                char strrr[256];
                int hex = va_arg(ag, int);
                print(int2ascii(hex,strrr, 16));
                written+=strlen(strr);// per printf spec
                break;
                
                case 'c': ;
                char c = (char)va_arg(ag, int); // ill have 2 give myself a promotion...2day!
                putchar(c);
                written++;
                break;
                
                case 's': ;
                const char* str = va_arg(ag, const char*); // prevents a compiler warning
                print(str);
                written+= strlen(str);
                break;

                case -1: ;
                return written;

                default:
                continue;
            }
            format+=2; // dealing with the % stuff is 2 chars
            // so format is increased twice
        }
        else{
            putchar(*format);
            format++; // read next char
            written++;
        }
        // if *format == %
        // if *format + 1 == d: print int
        // if *format + 1 == c: print c
        // if *format + 1 == s: print s. for s you want to written + len 
        // if *format + 1 == EOF/\0: return written

        // else print char and go onto the next format char
        // written++, format++
    }

    va_end(ag);

    return written;   
}