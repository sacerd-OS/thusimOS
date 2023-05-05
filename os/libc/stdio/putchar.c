#include "stdio.h"
#include "../etc/terminal.h"

int putchar(const char c) {
	size_t line = 0;
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
		{
			for(line = 1; line <= VGA_HEIGHT - 1; line++)
			{
				t_scroll(line);
			}
			t_delete_last_line();
			row = VGA_HEIGHT - 1;
		}
	}
	return 1;
}