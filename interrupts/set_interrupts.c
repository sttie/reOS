#include "../include/set_interrupts.h"

void init_handler(uint8_t type, uint8_t vector, unsigned long handler_address)
{
    IDT[0x20 * type + vector].offset_lower = handler_address & 0xffff;
    IDT[0x20 * type + vector].selector = 0x8;
    IDT[0x20 * type + vector].zero = 0;
    IDT[0x20 * type + vector].type_attr = 0x8e;
    IDT[0x20 * type + vector].offset_high = (handler_address & 0xffff0000) >> 16;
}

void IDT_init()
{
	/*
                PIC1   PIC2
    Commands    0x20   0xA0
    Data        0x21   0xA1

    */

    // ICW1 - init
    outb(0x20, 0b00010001);
    outb(0xA0, 0b00010001);

    // ICW2 - reset offset address if IDT
    // first 32 interrpts are reserved
    outb(0x21, 0x20);
    outb(0xA1, 0x28);

    // ICW3 - setup cascading
    outb(0x21, 0b00000100);
    outb(0xA1, 0b00000100);

    // ICW4 - env info
    outb(0x21, 0b00000011);
    outb(0xA1, 0b00000011);
    // INIT FINISHED!!

    // отключаем все линии IRQ кроме IRQ0 (IRQ1?)!!!
    outb(0x21, 0b11111001);
    outb(0xA1, 0b00000000);

    unsigned long idt_ptr[2];
    unsigned long idt_address = (unsigned long)IDT ;
	idt_ptr[0] = (sizeof (struct IDT_entry) * 256) + ((idt_address & 0xffff) << 16);
	idt_ptr[1] = idt_address >> 16;

    __asm__ __volatile__("lidt %0" :: "m" (*idt_ptr));
    __asm__ __volatile__("sti");
}