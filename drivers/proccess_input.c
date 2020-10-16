#include "../include/vgamode.h"
#include "../include/string.h"
#include "../include/standart_keyboard.h"
#include "../include/kapi.h"


void command_changeColor(int current_token_start);
void command_printHelpInfo();


/* returns start of the current token */
int getNewToken(char* destptr, char* startptr) {
    char* current_token_end = strtok(startptr, ' ');
    int token_length = current_token_end - startptr - 1;
    strncpy(destptr, startptr, token_length);
    destptr[token_length] = '\0';
    return token_length + 1;
}

void proccessInput() {
    char command[256];
    int last_token_end = getNewToken(command, keyboard_buffer);

    if (strcmp(command, "color")) {
        command_changeColor(last_token_end);
    }
    else if (strcmp(command, "help")) {
        command_printHelpInfo();
    }
    else if (strcmp(command, "quit")) {
        shutdownPC();
    }
}

void printInputBuffer() {
    printf("%s", keyboard_buffer);
}


void startCommandLine() {
    while (1) {
        if (keyboard_ready) {
            proccessInput();
            clearKeyboardBuffer();
        }
    }
}


void command_changeColor(int current_token_start) {
    char color_name[256];
    int last_token_end = getNewToken(color_name, keyboard_buffer + current_token_start);

    if (current_token_start + last_token_end < last_input_size) {
        printf("Too much arguments for \"color\" command\n");
    }

    int new_color = VGAcolor;
    if (strcmp(color_name, "red")) {
        new_color = VGAREDCOLOR;
    }
    else if (strcmp(color_name, "green")) {
        new_color = VGAGREENCOLOR;
    }
    else if (strcmp(color_name, "blue")) {
        new_color = VGABLUECOLOR;
    }
    else if (strcmp(color_name, "brown")) {
        new_color = VGABROWNCOLOR;
    }
    else if (strcmp(color_name, "yellow")) {
        new_color = VGAYELLOWCOLOR;
    }

    VGAChangeColor(new_color);
}

void command_printHelpInfo() {
    printf("You are connected to reOS. Available commands:\n"
           "help - print help information\n"
           "color color_name - change the terminal color to color_name (blue, red, green, yellow)\n"
           "quit - shutdown\n");
}