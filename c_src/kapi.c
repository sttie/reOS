#include "../include/kapi.h"

void disableCursor()
{
	outb(0x3d4, 0x0a);
    outb(0x3d5, 0x20);
}

void enableCursor()
{

}


void shutdownPC() {
	outw(0xB004, 0x2000);
}

void rebootPC() {
	
}


/* 8-bit */
void outb(uint16_t port, uint8_t value)
{
	__asm__ __volatile__ ("outb %1, %0" : : "dN" (port), "a" (value));
}

uint8_t inb(uint16_t port)
{
	unsigned char value;
	__asm__ __volatile__ ("inb %1, %0" : "=a"(value) : "Nd"(port));
    
	return value;
}

/* 16-bit */
void outw(uint16_t port, uint16_t value)
{
	__asm__ __volatile__ ("outw %1, %0" : : "dN" (port), "a" (value));
}

uint16_t inw(uint16_t port)
{
	unsigned short value;
	__asm__ __volatile__ ("inw %1, %0" : "=a"(value) : "Nd"(port));
	
	return value;
}

/* 32-bit */
void outdw(uint16_t port, uint32_t value)
{
	__asm__ __volatile__ ("outl %1, %0" : : "dN" (port), "a" (value));
}

uint32_t indw(uint16_t port)
{
	unsigned int value;
	__asm__ __volatile__ ("inl %1, %0" : "=a"(value) : "Nd"(port));
	
	return value;
}


// ????????????????????
void debugInfo()
{
	asm("int $0x1");
}