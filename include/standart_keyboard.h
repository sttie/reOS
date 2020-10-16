#ifndef _STANDART_KEYBOARD_h
#define _STANDART_KEYBOARD_h

char keyboard_buffer[256];
int keyboard_current;
int keyboard_ready;
int last_input_size;

void initKeyboardHandler();
void keyboardHandler();
void keyboard_handler_caller();
void clearKeyboardBuffer();
int isKeyboardReady();

#endif