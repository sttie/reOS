#include "../include/string.h"
#include "../include/math.h"
#include "../include/vgamode.h"

/* compares two strings, returns 1 if equal */
int strcmp(char* first, char* second)
{
	while (*first && *second && *first == *second) {
        first++;
        second++;
    }

    if ((*first && *second) || (!*first && *second) || (*first && !*second)) {
        return 0;
    }

    return 1;
}

/* returns length of the str */
int strlen(char* str)
{
	int size = 0;

	while (str[size])
		size++;

	return size;
}

/* copy strings */
char* strcpy(char* destptr, char* srcptr)
{
    while (*srcptr) {
        *destptr = *srcptr;
        srcptr++;
    }
    *destptr = *srcptr;

    return destptr;
}

/* concatinating strings */
char* strcat(char* destptr, char* srcptr)
{
	strcpy(destptr + strlen(destptr), srcptr);

    return destptr;
}

/* converts char* to int */
int atoi(char* str)
{
	// 1234
	int res = 0, length = strlen(str) - 1;

	while (length >= 0)
	{
		res += (str[length] - '0') * binpow(10, length);
		length--;
	}

	return res;
}

/* reverses the buffer */
void reverse(char* buffer)
{
    char c;
    
    for (int i = 0, j = strlen(buffer) - 1; i < j; i++, j--) {
        c = buffer[i];
        buffer[i] = buffer[j];
        buffer[j] = c;
    }
}

/* converts int to char* */
void itoa(int num, char* buffer)
{
	int i, sign;

    if ((sign = num) < 0) {
        num = -num;
    }

    i = 0;
    while (num > 0) {
        buffer[i++] = num % 10 + '0';
        num /= 10;
    }

    if (sign < 0) buffer[i++] = '-';
    if (num == 0 && i == 0) buffer[i++] = '0';
    buffer[i] = '\0';
    reverse(buffer);
}


void toHex(int num, char* newhex)
{
    int index = 0;
    char hexses[17] = "0123456789abcdef";
    while (num > 0)
    {
        newhex[index] = hexses[num % 16];
        index++;
        num /= 16;
    }

    newhex[index] = '\0';

    reverse(newhex);
}


/*  */
int checkbit(int c, unsigned char bitn)
{
    return (c >> bitn) & 1;
}
