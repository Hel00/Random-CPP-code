nasm -f elf32 start.s -o start.o
z++ main.cpp -o main.o -m32 -Oz -s -c --target=i386-freestanding-none
ld -m elf_i386 -T link.ld  -o boot/kernel.bin start.o main.o
grub-mkrescue -o kernel.iso boot/kernel.bin
