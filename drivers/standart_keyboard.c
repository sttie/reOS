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
	if (letter == '\n') {
		keyboard_ready = 1;
		putc(letter);
	}
	else if (letter == '\b' && keyboard_current > 0) {
		keyboard_current--;
		keyboard_buffer[keyboard_current] = '\0';
		putc(letter);
	}
	else if (letter != '\b' && keyboard_current < 256) {
		keyboard_buffer[keyboard_current] = letter;
		putc(letter);
		keyboard_current++;
	}
}