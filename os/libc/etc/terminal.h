#ifndef __TERMINAL
#define __TERMINAL
#include <stddef.h>
#include <stdint.h>
static const size_t VGA_WIDTH = 80;
static const size_t VGA_HEIGHT = 25;
size_t row;
size_t column;
uint8_t terminal_color;
uint16_t* terminal_buffer;

enum vga_color {
	VGA_COLOR_BLACK = 0,
	VGA_COLOR_BLUE = 1,
	VGA_COLOR_GREEN = 2,
	VGA_COLOR_CYAN = 3,
	VGA_COLOR_RED = 4,
	VGA_COLOR_MAGENTA = 5,
	VGA_COLOR_BROWN = 6,
	VGA_COLOR_LIGHT_GREY = 7,
	VGA_COLOR_DARK_GREY = 8,
	VGA_COLOR_LIGHT_BLUE = 9,
	VGA_COLOR_LIGHT_GREEN = 10,
	VGA_COLOR_LIGHT_CYAN = 11,
	VGA_COLOR_LIGHT_RED = 12,
	VGA_COLOR_LIGHT_MAGENTA = 13,
	VGA_COLOR_LIGHT_BROWN = 14,
	VGA_COLOR_WHITE = 15,
};
uint8_t vga_entry_color(enum vga_color fg, enum vga_color bg);
uint16_t vga_entry(unsigned char uc, uint8_t color);
void t_initialize(enum vga_color fg, enum vga_color bg);
void vga_putentryat(char c, uint8_t color, size_t x, size_t y);
void t_setcolor(uint8_t color);
void t_scroll(size_t line);
void t_delete_last_line(void);
#endif