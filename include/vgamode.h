#ifndef _VGAMODE_H_
#define _VGAMODE_H_

#define VGABLUECOLOR 0x1
#define VGAGREENCOLOR 0x2
#define VGAREDCOLOR 0x4
#define VGABROWNCOLOR 0x6
#define VGAYELLOWCOLOR 0x14

char* VGA_VIDEOBUFFER;
unsigned int VGALocation;
unsigned char VGAcolor;

void initOutput();
void VGAChangeColor(unsigned char newcolor);
void printf(char* format, ...);
void printint(int num);
void putc(char ch);

#endif