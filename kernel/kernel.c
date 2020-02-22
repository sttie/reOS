/*

1. Структура с данными CPUID                НЕТ
2. malloc()                                 НЕТ
3. Прерывания APIC                          НЕТ
4. Обработчики исключений                   ДА
5. PCI                                      НЕТ
6. Таймер (в APIC есть свой PIT)			НЕТ
7. Дебаг									ДА
8. printf с переменным числом параметров    ДА

*/
// PIT CPUID
/* 
			САМОЕ ВАЖНОЕ! 
	1. Having a working and reliable interrupt/exception handling system that can dump the contents of 
		the registers (and perhaps the address of the fault).
	2. Plan your memory map (virtual, and physical): decide where you want the data to be.
	3. The heap: allocating memory at runtime (malloc and free). 
*/


#include "../include/command_line.h"
#include "../include/kapi.h"
#include "../include/string.h"
#include "../include/vgamode.h"
#include "../include/set_interrupts.h"
#include "../include/standart_keyboard.h"
#include "../include/exception_handlers.h"

#define EXCEPTIONOFFSET 0
#define INTERRUPTOFFSET 1

void initExceptions();
void initInterrupts();

void kmain() {
    /* init output */
    initOutput();
    disableCursor();

    /* init interrupts */
    initInterrupts();
    initExceptions();
    IDT_init();

    debugInfo();

   	for (;;) {}
}


void initInterrupts()
{
    init_handler(INTERRUPTOFFSET, 1, (unsigned long) keyboard_handler_caller);
}


void initExceptions()
{
    init_handler(EXCEPTIONOFFSET,  0, (unsigned long) zeroDivisionCaller);
    init_handler(EXCEPTIONOFFSET,  1, (unsigned long) debugCaller);
    init_handler(EXCEPTIONOFFSET,  5, (unsigned long) boundRangeExceededCaller);
    init_handler(EXCEPTIONOFFSET,  6, (unsigned long) invalidOpcodeCaller);
    init_handler(EXCEPTIONOFFSET,  7, (unsigned long) deviceNotAvailableCaller);
    init_handler(EXCEPTIONOFFSET, 10, (unsigned long) invalidTSSCaller);
    init_handler(EXCEPTIONOFFSET, 11, (unsigned long) segmentNotPresentCaller);
    init_handler(EXCEPTIONOFFSET, 12, (unsigned long) stackSegmentCaller);
    init_handler(EXCEPTIONOFFSET, 13, (unsigned long) generalProtectionCaller);
    init_handler(EXCEPTIONOFFSET, 14, (unsigned long) pageFaultCaller);
    init_handler(EXCEPTIONOFFSET, 16, (unsigned long) x87FloatingPointCaller);
    init_handler(EXCEPTIONOFFSET, 19, (unsigned long) SIMDFloatingPointCaller);
    init_handler(EXCEPTIONOFFSET, 20, (unsigned long) virtualizationCaller);
}