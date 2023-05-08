#include "../../libc/etc/terminal.h"
#include "../../libc/stdio/stdio.h"
#include "kernel.h"

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

void k_main(void){
  // initialize
  t_initialize(VGA_COLOR_LIGHT_MAGENTA, VGA_COLOR_BLACK);

  // print tests
  puts("hello squirrel\nit's squirrel time :3");
  printf("printf with string: %s\n", "squirrely");
  printf("printf with char: %c\n", 'c');
  printf("printf with int: %d\n", 45);
  printf("printf with int case zero: %d\n", 0);
  printf("printf with int case negative: %d\n", -1);
  printf("printf with hex: %x", 450);
} 