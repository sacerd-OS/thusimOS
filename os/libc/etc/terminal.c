#include "terminal.h"
#include "../string/string.h"
#include <stddef.h>

uint8_t vga_entry_color(enum vga_color fg, enum vga_color bg) {
	return fg | bg << 4;
}
 
// first 8 bits are color, last 8 are char
// then we feed this into an index to show
// a char of a certain color at a certain place
uint16_t vga_entry(unsigned char uc, uint8_t color) {
	return (uint16_t) uc | (uint16_t) color << 8;
}

void t_scroll(size_t line) {
	for(size_t x = 0; x < VGA_WIDTH; x++){ // for all in row
		const size_t initial_index = (line) * VGA_WIDTH + x; // get index of char on line
		char initial_char = (char)(terminal_buffer[initial_index] & 0x00FF); // get actual value
		vga_putentryat(initial_char, terminal_color, x, line - 1); // move char up one line
	}
}
 
void t_delete_last_line(void) {
	const size_t FINAL_ROW = VGA_HEIGHT - 1;
	for (size_t x = 0; x < VGA_WIDTH; x++) {// for all in row
		vga_putentryat(' ', terminal_color, x, FINAL_ROW); // delete
	}
}

void t_initialize(enum vga_color fg, enum vga_color bg){
	row = 0;
	column = 0;
	terminal_color = vga_entry_color(fg, bg); // make every color fg / bg inputs
	terminal_buffer = (uint16_t*) 0xB8000; // START OF VIDEO MEMORY

	// clear entire screen
	for (size_t y = 0; y < VGA_HEIGHT; y++) {
		for (size_t x = 0; x < VGA_WIDTH; x++) {
			const size_t index = y * VGA_WIDTH + x;
			terminal_buffer[index] = vga_entry(' ', terminal_color);
		}
	}
}
 

// in case one might want to change color later
void t_setcolor(uint8_t color) {
	terminal_color = color;
}
 
// helper function for putchar et al
// given a coord in the VGA array, puts char there
// terminal_buffer[] is an array that basically represents
// the screen, where index is a size_t that represents a 
// concatenation  of an x, y coord pair
void vga_putentryat(char c, uint8_t color, size_t x, size_t y) {
	const size_t index = y * VGA_WIDTH + x;
	terminal_buffer[index] = vga_entry(c, color);
}
