#include "../include/standart_keyboard.h"
#include "../include/vgamode.h"
#include "../include/kapi.h"
#include "../include/keymap.h"


void initKeyboardHandler() {
	keyboard_current = 0;
	keyboard_ready = 0;
	last_input_size = 0;
}

void keyboardHandler()
{
	char letter;

	if (!inb(0x64) & 0x1 || (letter = inb(0x60)) <= 0)
		return;

	letter = kmap[letter];
	if (letter == '\n') {
		keyboard_buffer[keyboard_current] = letter;
		last_input_size = keyboard_current;
		keyboard_ready = 1;
	}
	else if (letter == '\b' && keyboard_current > 0) {
		keyboard_current--;
		keyboard_buffer[keyboard_current] = '\0';
	}
	else if (letter != '\b' && keyboard_current < 256) {
		keyboard_buffer[keyboard_current++] = letter;
	}
	
	putc(letter);
}

void clearKeyboardBuffer() {
	keyboard_current = 0;
	keyboard_ready = 0;
	keyboard_buffer[0] = '\0';
}

// почему-то при вызове этой функции в другом файле она иногда возвращает бред
int isKeyboardReady() {
	return keyboard_ready;
}