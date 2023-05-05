~/opt/cross/bin/i686-elf-gcc -c kernel/src/kernel.c -o kernel/obj/kernel.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra
~/opt/cross/bin/i686-elf-gcc -c kernel/src/strings.c -o kernel/obj/strings.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra
~/opt/cross/bin/i686-elf-gcc -c kernel/src/terminal.c -o kernel/obj/terminal.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra