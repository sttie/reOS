#include "../include/standart_keyboard.h"
#include "../include/vgamode.h"
#include "../include/kapi.h"
#include "../include/keymap.h"

void keyboardHandler()
{
	char letter;

	if (!inb(0x64) & 0x1 || (letter = inb(0x60)) <= 0)
		return;

	letter = kmap[letter];

	putc(letter);
}