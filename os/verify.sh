#!/bin/sh
cd ../bin

if grub-file --is-x86-multiboot thusimos.bin; then
  echo verified :3
  cp thusimos.bin ../os/iso/boot/thusimos.bin
  cd ../os
  grub-mkrescue -o ../bin/thusimos.iso iso
  cd ../bin
  qemu-system-i386 -cdrom thusimos.iso
else
  echo error: not verified
fi