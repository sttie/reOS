#ifndef _EXCEPTION_HANDLERS_H
#define _EXCEPTION_HANDLERS_H

void zeroDivisionHandler();
void debugHandler();

void zeroDivisionCaller();
void debugCaller();
void boundRangeExceededCaller();
void invalidOpcodeCaller();
void deviceNotAvailableCaller();
void invalidTSSCaller();
void segmentNotPresentCaller();
void stackSegmentCaller();
void generalProtectionCaller();
void pageFaultCaller();
void x87FloatingPointCaller();
void alignmentCheckCaller();
void SIMDFloatingPointCaller();
void virtualizationCaller();

#endif