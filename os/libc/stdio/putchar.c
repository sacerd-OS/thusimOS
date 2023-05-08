#include "stdio.h"
#include "../etc/terminal.h"

int putchar(const char c) {
	// for scrolling if necessary
	size_t line = 0;
	
	// we dont want to print \0
	if(c == '\0') return -1;
	
	// \n case:
	// move to next row
	// if next row is off the screen, scroll
	// and delete the last line to make room
    if(c == '\n'){
	  column = 0;
	  row++;
      if (row == VGA_HEIGHT){
		for(line = 1; line < VGA_HEIGHT; line++){
			t_scroll(line);
		}
		t_delete_last_line();
		row = VGA_HEIGHT - 1;
	  }
	  return 1;
    }
	
	// this line is generally the only one that'll run
	// it baically just prints a char(c) in a color (terminal_color)
	// at a coordinate (column, row)
	vga_putentryat(c, terminal_color, column, row);
	
	// case: character hits the end of the screen
	// move to next row
	// if next row is off the screen, scroll
	// and delete the last row to make room
	// note: VERY similar to \n case
	if (++column == VGA_WIDTH) {
		column = 0;
		if (++row == VGA_HEIGHT){
			for(line = 1; line <= VGA_HEIGHT - 1; line++){
				t_scroll(line);
			}
			t_delete_last_line();
			row = VGA_HEIGHT - 1;
		}
	}
	return 1;
}