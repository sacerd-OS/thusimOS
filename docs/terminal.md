# Terminal Docs
This section describes each function used in terminal.c.

## terminal
These functions are defined in ``terminal.h`` in the directory ``os/libc/etc``.

### uint16_t vga_entry(unsigned char uc, uint8_t color)
Source file: ``terminal.c``

Concatenates a color with a character and returns that value.

### void t_scroll(size_t line)
Source file: ``terminal.c``

Scrolls through the screen by moving each line up one.

### void t_delete_last_line(void) 
Source file: ``terminal.c``

Erases the last line of the screen. Helper function for scrolling.

### void t_initialize(enum vga_color fg, enum vga_color bg)
Source file: ``terminal.c``

Initializes the terminal and the VGA array.

### void t_setcolor(uint8_t color)
Source file: ``terminal.c``

Sets the main color for the terminal.

### void vga_putentryat(char c, uint8_t color, size_t x, size_t y)
Source file: ``terminal.c``

Puts a color ``c`` in a color ``color`` at the coordinates ``x``, ``y``.