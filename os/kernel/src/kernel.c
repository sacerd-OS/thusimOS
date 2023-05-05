#include "../include/strings.h"
#include "../include/terminal.h"
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
void k_main(){
  t_initialize(VGA_COLOR_LIGHT_MAGENTA, VGA_COLOR_BLACK);
  t_write("hello squirrel\nit's squirrel time");
} 