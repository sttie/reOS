#!/bin/bash

# ============================= ASM ===================================
nasm -g -f elf32 -F dwarf -o boot.o asm/first_stage.asm
ld -melf_i386 -Ttext=0x7c00 -nostdlib --nmagic -o boot.elf boot.o
objcopy -O binary boot.elf boot.bin

nasm -g -f elf32 -F dwarf -o interrupts_calls.o asm/interrupts_calls.asm
# =====================================================================

# ============================= C =====================================
gcc -g -m32 -c -ffreestanding kernel/*.c
gcc -g -m32 -c -ffreestanding c_src/*.c
gcc -g -m32 -c -ffreestanding interrupts/*.c
gcc -g -m32 -c -ffreestanding drivers/*.c
# =====================================================================

# ============================= LINK ==================================
ld -r -m elf_i386 kernel.o kapi.o vgamode.o interrupts_calls.o \
                  set_interrupts.o string.o math.o \
                  standart_keyboard.o exception_handlers.o \
                  proccess_input.o \
                  -o main.o

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


rm -rf *.o
rm -rf *.bin
rm -rf *.elf

qemu-system-x86_64 -fda boot.img -s -monitor stdio

rm -rf boot.img
