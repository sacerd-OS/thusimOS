#include "../string/string.h"
#include "stdlib.h"

int char2dig(char c){
  if (c >= '0' && c <= '9')
    return c - '0';
  else 
    return -1;
}

int pow10(int pow){
    int ret = 10;
    
    if(pow == 0)
        return 1;

    for(int i = 1; i < pow; i++)
        ret *=10;

    return ret;
}

// bad code
int atoi(const char *nptr){
    int start = 0;
    int number_digits = strlen(nptr);
    int ret = 0;
    
    if(nptr[0] == '-'){
        start++;
        number_digits--;
    }
    
    for(int i = 0; i < number_digits; i++){
       if(char2dig(nptr[start+i]) == -1){
            return 0; // per spec
        }
        else{
            ret += char2dig(nptr[start + i]) * pow10(i);
        }
    }
    if(nptr[0] == '-') ret *= -1;

    return ret;
}