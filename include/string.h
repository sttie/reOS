#ifndef STRING_H_
#define STRING_H_

void memset(void* buffer, int c, int n);
/* compares two strings, returns 1 if equal */
int strcmp(char* first, char* second);
/* returns length of the str */
int strlen(char* str);
/* copy strcptr to desptr */
char* strcpy(char* destptr, char* srcptr);
/* copy first n symbols of srcptr to destptr */
char* strncpy(char* destptr, char* srcptr, int n);
/* concatinate strings */
char* strcat(char* destptr, char* srcptr);
/*  */
char* strtok(char* str, char delimeter);
/* convert char* to int */
int atoi(char* str);
/* reverse the buffer */
void reverse(char* buffer);
/* converts int to char* */
void itoa(int num, char* buffer);
/* check if the bitn bit in c is 1 */
int checkbit(int c, unsigned char bitn);
/* converts a decimal number to a hex number */
void toHex(int num, char* newhex);

#endif