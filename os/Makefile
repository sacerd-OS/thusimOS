_DEPS = strings.h terminal.h
CC = HOME/opt/cross/bin/i686-elf-gcc
ODIR = obj
SDIR = src
IDIR = include
CFLAGS = -I$(IDIR) -ffreestanding -Wall -Wextra -g -pthread
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

all: $(ODIR)/%.o

$(ODIR)/%.o: $(SDIR)/%.c $(DEPS)
	$(CC) -c $@ -o $< $(CFLAGS)