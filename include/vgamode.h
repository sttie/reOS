#ifndef _VGAMODE_H_
#define _VGAMODE_H_

char* VGA_VIDEOBUFFER;
unsigned int location;
unsigned char VGAcolor;

void initOutput();
void printf(char* format, ...);
void printint(int num);
void putc(char ch);

#endif