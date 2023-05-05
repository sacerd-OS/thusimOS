#include "../../libc/etc/terminal.h"
#include "../../libc/stdio/stdio.h"
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
void k_main(){
  t_initialize(VGA_COLOR_LIGHT_MAGENTA, VGA_COLOR_BLACK);
  puts("hello squirrel\nit's squirrel time :3");
} 