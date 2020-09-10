#ifndef _STANDART_KEYBOARD_h
#define _STANDART_KEYBOARD_h

char keyboard_buffer[256];
unsigned int keyboard_current;
unsigned char keyboard_ready;

void keyboardHandler();
void keyboard_handler_caller();

#endif