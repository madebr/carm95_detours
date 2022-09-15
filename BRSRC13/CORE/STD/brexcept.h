#ifndef _BREXCEPT_H_
#define _BREXCEPT_H_

#include "br_types.h"

extern br_exception_handler ** hookvar__BrExceptionHandler ; // addr: 0053005C
extern void ** hookvar_exceptionValue ; // addr: 00544D84

br_exception_handler* _BrExceptionBegin();

void _BrExceptionEnd();

void _BrExceptionThrow(br_int_32 type, void *value);

br_exception _BrExceptionValueFetch(br_exception type, void **evp);

void* _BrExceptionResource();

#endif
