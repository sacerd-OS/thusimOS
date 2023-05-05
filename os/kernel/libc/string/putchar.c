#include "string.h"
#include "../etc/terminal.h"

void putchar(char c) {
    if(c == '\n'){
	  column = 0;
      if (++row == VGA_HEIGHT){
		row = 0;
	  }
	  return;
    }
	t_putentryat(c, terminal_color, column, row);
	if (++column == VGA_WIDTH) {
		column = 0;
		if (++row == VGA_HEIGHT)
			row = 0;
	}
}