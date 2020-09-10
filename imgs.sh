#!/bin/bash

# ============================= ASM ===================================
nasm -g -f elf32 -F dwarf -o boot.o asm/first_stage.asm
ld -melf_i386 -Ttext=0x7c00 -nostdlib --nmagic -o boot.elf boot.o
objcopy -O binary boot.elf boot.bin

nasm -g -f elf32 -F dwarf -o interrupts_calls.o asm/interrupts_calls.asm
# =====================================================================

# ============================= C =====================================
gcc -g -m32 -c -ffreestanding kernel/kernel.c
gcc -g -m32 -c -ffreestanding c_src/kapi.c
gcc -g -m32 -c -ffreestanding c_src/string.c
gcc -g -m32 -c -ffreestanding c_src/math.c
gcc -g -m32 -c -ffreestanding interrupts/set_interrupts.c
gcc -g -m32 -c -ffreestanding drivers/standart_keyboard.c
gcc -g -m32 -c -ffreestanding drivers/exception_handlers.c
gcc -g -m32 -c -ffreestanding drivers/vgamode.c
# =====================================================================

# ============================= LINK ==================================
ld -r -m elf_i386 kernel.o kapi.o vgamode.o interrupts_calls.o exception_handlers.o set_interrupts.o string.o math.o standart_keyboard.o -o main.o
ld -melf_i386 -Tlinker.ld -nostdlib --nmagic -o main.elf main.o

objcopy -O binary main.elf main.bin
# =====================================================================

# ============================= DOWNLOAD ==============================
dd if=boot.bin of=boot.img bs=512 conv=notrunc
dd if=main.bin of=boot.img bs=512 seek=1 conv=notrunc
# =====================================================================

size=$(wc -c < "main.bin")
let kbsize=size/1024;
echo "Size of the kernel is $size bytes, $kbsize kilobytes"


rm -rf kernel.o
rm -rf kapi.o
rm -rf string.o
rm -rf math.o
rm -rf standart_keyboard.o
rm -rf interrupts_calls.o
rm -rf exception_handlers.o
rm -rf set_interrupts.o
rm -rf vgamode.o
rm -rf main.o
rm -rf main.bin
rm -rf main.elf
rm -rf boot.bin
rm -rf boot.elf
rm -rf boot.o

qemu-system-x86_64 -fda boot.img -s -monitor stdio

rm -rf boot.img
