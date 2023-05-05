#include "../../libc/etc/terminal.h"
#include "../../libc/stdio/stdio.h"
#include "kernel.h"

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

void k_main(void){
  t_initialize(VGA_COLOR_LIGHT_MAGENTA, VGA_COLOR_BLACK);
  puts("hello squirrel\nit's squirrel time :3");
  printf("string %s\n", "squirrely");
  printf("char %c\n", 'c');
  printf("int %d\n", 45);
  printf("zero %d\n", 0);
  printf("negative %d\n", -1);
  printf("hex %x", 450);
} 