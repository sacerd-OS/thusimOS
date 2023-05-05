#include "terminal.h"
#include "../string/string.h"
#include <stddef.h>
static const size_t VGA_WIDTH = 80;
static const size_t VGA_HEIGHT = 25;
size_t row;
size_t column;
uint8_t terminal_color;
uint16_t* terminal_buffer;

static inline uint8_t vga_entry_color(enum vga_color fg, enum vga_color bg) {
	return fg | bg << 4;
}
 
static inline uint16_t vga_entry(unsigned char uc, uint8_t color) {
	return (uint16_t) uc | (uint16_t) color << 8;
}

void t_initialize(enum vga_color fg, enum vga_color bg){
	row = 0;
	column = 0;
	terminal_color = vga_entry_color(fg, bg);
	terminal_buffer = (uint16_t*) 0xB8000; // START OF VIDEO MEMORY
	for (size_t y = 0; y < VGA_HEIGHT; y++) {
		for (size_t x = 0; x < VGA_WIDTH; x++) {
			const size_t index = y * VGA_WIDTH + x;
			terminal_buffer[index] = vga_entry(' ', terminal_color);
		}
	}
}
 

void t_setcolor(uint8_t color) {
	terminal_color = color;
}
 
void vga_putentryat(char c, uint8_t color, size_t x, size_t y) {
	const size_t index = y * VGA_WIDTH + x;
	terminal_buffer[index] = vga_entry(c, color);
}
