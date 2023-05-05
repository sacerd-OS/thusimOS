cd ../bin

if grub-file --is-x86-multiboot thusimos.bin; then
  echo verified :3
  cp thusimos.bin ../os/iso/boot/thusimos.bin
  cd ../os
  grub-mkrescue -o ../bin/thusimos.iso iso
  
  qemu-system-i386 -cdrom ../bin/thusimos.iso
else
  echo error: not verified
fi