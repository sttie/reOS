#include "../include/vgamode.h"
#include "../include/string.h"

void zeroDivisionHandler()
{
	printf("Got Zero Division Error!\n");
}


void debugHandler()
{
	register int r_eax asm("eax");
	register int r_ebx asm("ebx");
	register int r_ecx asm("ecx");
	register int r_esp asm("esp");

	/* TODO: print stack frame */
	printf("DEBUG INFO:\n"
		   "\tEAX=%x\n"
		   "\tEBX=%x\n"
		   "\tECX=%x\n"
		   "\tESP=%x\n", r_eax, r_ebx, r_ecx, r_esp);
}


void boundRangeExceededException()
{
	printf("boundRangeExceededException");
}

void invalidOpcodeException()
{
	printf("invalidOpcodeException");
}

void deviceNotAvailableException()
{
	printf("deviceNotAvailableException");
}

void invalidTSSException()
{
	printf("invalidTSSException");
}

void segmentNotPresentException()
{
	printf("segmentNotPresentException");
}

void stackSegmentException()
{
	printf("stackSegmentException");
}

void generalProtectionException()
{
	printf("generalProtectionException");
}

void pageFaultException()
{
	printf("pageFaultException");
}

void x87FloatingPointException()
{
	printf("x87FloatingPointException");
}

void alignmentCheckException()
{
	printf("alignmentCheckException");
}

void SIMDFloatingPointException()
{
	printf("SIMDFloatingPointException");
}

void virtualizationException()
{
	printf("virtualizationException");
}