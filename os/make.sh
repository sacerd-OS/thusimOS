 #!/bin/bash
 # I couldn't fucking figure out Make. Is that embarassing? Yessssss.
CFLAGS="-g -std=gnu99 -ffreestanding -Wall -Wextra -pedantic -Wshadow -Wpointer-arith -Wcast-align -Wwrite-strings -Wmissing-prototypes -Wmissing-declarations -Wredundant-decls -Wnested-externs -Winline -Wno-long-long -Wconversion -Wstrict-prototypes"
OBJDIR=./obj
STDIO=./libc/stdio
KERNEL=./kernel/src
STRING=./libc/string
ETC=./libc/etc
COMPILER=~/opt/cross/bin/i686-elf-gcc
OFILES="obj/kernel.o obj/puts.o obj/printf.o obj/putchar.o obj/strlen.o obj/terminal.o obj/boot.o"

$COMPILER -c $KERNEL/kernel.c -o obj/kernel.o $CFLAGS

$COMPILER -c $STDIO/puts.c -o obj/puts.o $CFLAGS
$COMPILER -c $STDIO/printf.c -o obj/printf.o $CFLAGS
$COMPILER -c $STDIO/putchar.c -o obj/putchar.o $CFLAGS

$COMPILER -c $STRING/strlen.c -o obj/strlen.o $CFLAGS

$COMPILER -c $ETC/terminal.c -o obj/terminal.o $CFLAGS

$COMPILER -T linker.ld -o ../bin/thusimos.bin -ffreestanding -nostdlib $OFILES -lgcc