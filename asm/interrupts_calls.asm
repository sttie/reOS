bits 32

; EXCEPTIONS =========================

extern zeroDivisionHandler
global zeroDivisionCaller

extern debugHandler
global debugCaller

extern boundRangeExceededException
global boundRangeExceededCaller

extern invalidOpcodeException
global invalidOpcodeCaller

extern deviceNotAvailableException
global deviceNotAvailableCaller

extern invalidTSSException
global invalidTSSCaller

extern segmentNotPresentException
global segmentNotPresentCaller

extern stackSegmentException
global stackSegmentCaller

extern generalProtectionException
global generalProtectionCaller

extern pageFaultException
global pageFaultCaller

extern x87FloatingPointException
global x87FloatingPointCaller

extern alignmentCheckException
global alignmentCheckCaller

extern SIMDFloatingPointException
global SIMDFloatingPointCaller

extern virtualizationException
global virtualizationCaller


zeroDivisionCaller:
	call zeroDivisionHandler
    iretd

debugCaller:
	call debugHandler
	iretd

boundRangeExceededCaller:
	call boundRangeExceededException
	iretd

invalidOpcodeCaller:
	call invalidOpcodeException
	iretd

deviceNotAvailableCaller:
	call deviceNotAvailableException
	iretd

invalidTSSCaller:
	call invalidTSSException
	iretd

segmentNotPresentCaller:
	call segmentNotPresentException
	iretd

stackSegmentCaller:
	call stackSegmentException
	iretd

generalProtectionCaller:
	call generalProtectionException
	iretd

pageFaultCaller:
	call pageFaultException
	iretd

x87FloatingPointCaller:
	call x87FloatingPointException
	iretd

alignmentCheckCaller:
	call alignmentCheckException
	iretd

SIMDFloatingPointCaller:
	call SIMDFloatingPointException
	iretd

virtualizationCaller:
	call virtualizationException
	iretd

; ====================================

; INTERRUPTS =========================

extern keyboardHandler
global keyboard_handler_caller


keyboard_handler_caller:
	call keyboardHandler
	iretd

; ====================================