#include "stdio.h"
#include "../etc/terminal.h"

int putchar(const char c) {
	if(c == '\0') return -1;
    if(c == '\n'){
	  column = 0;
      if (++row == VGA_HEIGHT){
		row = 0;
	  }
	  return 1;
    }
	vga_putentryat(c, terminal_color, column, row);
	if (++column == VGA_WIDTH) {
		column = 0;
		if (++row == VGA_HEIGHT)
			row = 0;
	}
	return 1;
}