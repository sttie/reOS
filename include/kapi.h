#ifndef KERLIB_H_
#define KERLIB_H_

#include "stdint.h"


void disableCursor();
void enableCursor();

/* 8-bit */
void outb(uint16_t port, uint8_t value);
uint8_t inb(uint16_t port);

/* 16-bit */
void outw(uint16_t port, uint16_t value);
uint16_t inw(uint16_t port);

/* 32-bit */
void outdw(uint16_t port, uint32_t value);
uint32_t indw(uint16_t port);

// ????????????????????
void debugInfo();

#endif