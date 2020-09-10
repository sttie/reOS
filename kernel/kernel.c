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
