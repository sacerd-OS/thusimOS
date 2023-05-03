if grub-file --is-x86-multiboot thusimos.bin; then
  echo verified :3
  cp thusimos.bin iso/boot/thusimos.bin
  grub-mkrescue -o thusomos.iso iso
  
  qemu-system-i386 -cdrom thusimos.iso
else
  echo error: not verified
fi