#ifndef _SET_INTERRUPTS_H
#define _SET_INTERRUPTS_H

#include "../include/kapi.h"
#include "../include/stdint.h"

struct IDT_entry
{
	uint16_t offset_lower;
	uint16_t selector;
	uint8_t zero;
	uint8_t type_attr;
	uint16_t offset_high;
};

struct  IDT_entry IDT[256];

/* 
	type 	- handler is interrupt, gate or exception handler 
*/
void init_handler(uint8_t type, uint8_t vector, unsigned long handler_address);

void IDT_init();

#endif