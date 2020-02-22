#ifndef STRING_H_
#define STRING_H_

void memset(void* buffer, int c, int n);
/* compares two strings, returns 1 if equal */
int strcmp(char* first, char* second);
/* returns length of the str */
int strlen(char* str);
/* copy strings */
char* strcpy(char* destptr, char* srcptr);
/* concatinating strings */
char* strcat(char* destptr, char* srcptr);
/* converts char* to int */
int atoi(char* str);
/* reverses the buffer */
void reverse(char* buffer);
/* converts int to char* */
void itoa(int num, char* buffer);
/*  */
int checkbit(int c, unsigned char bitn);
/* converts a decimal number to a hex number */
void toHex(int num, char* newhex);

#endif