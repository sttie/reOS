#include "../include/vgamode.h"
#include "../include/string.h"

void initOutput()
{
	VGA_VIDEOBUFFER = (char*) 0xb8000;
	location = 0;
	VGAcolor = 0x7;
}


void changeColor(unsigned char newcolor)
{
	VGAcolor = newcolor;
}


void printf(char* format, ...)
{
    char* current_arg = (char*) &format + sizeof(format);

    while (*format)
    {
        if (*format != '%')
            putc(*format);
        else
        {
            format++;

            if (*format == 'd')
            {
                int int_arg = *((int*) current_arg);
                printint(int_arg);
                current_arg += sizeof(int_arg);
            }
            else if (*format == 's')
            {
                char** str_arg = (char**) current_arg;

                while (**str_arg)
                {
                    putc(**str_arg);
                    (*str_arg)++;
                }

                current_arg += sizeof(char*);
            }

            else if (*format == 'c')
            {
                // TODO
            }

            else if (*format == 'p')
            {
                // TODO
            }
            else if (*format == 'x')
            {
                int int_arg = *((int*) current_arg);
                char newhex[16] = {0};
                toHex(int_arg, newhex);
                printf("0x%s", newhex);
                current_arg += sizeof(int_arg);
            }
            else
            {
                putc('%');
            }
        }

        format++;
    }
}


void printint(int num)
{
    char buf[11] = {0};
    itoa(num, buf);
    printf("%s", buf);
}


void putc(char ch)
{
	if (ch == '\n') {
		location -= location % 160 - 160;
    }

	else if (ch == '\t') {
		location += 8;
    }

	else if (ch == '\r') {
		location = location / 160 + location + 160;
    }

    else if (ch == '\b') {
        location -= 2;
        VGA_VIDEOBUFFER[location] = '\0';
    }

	else
	{
		VGA_VIDEOBUFFER[location] = ch;
		VGA_VIDEOBUFFER[location + 1] = VGAcolor;
		location += 2;
	}
}
