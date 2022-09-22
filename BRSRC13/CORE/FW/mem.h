#ifndef _MEM_H_
#define _MEM_H_

#include "br_types.h"


void* __cdecl BrMemAllocate(br_size_t size, br_uint_8 type);

void __cdecl BrMemFree(void *block);

br_size_t __cdecl BrMemInquire(br_uint_8 type);

br_int_32 BrMemAlign(br_uint_8 type);

void* __cdecl BrMemCalloc(int nelems, br_size_t size, br_uint_8 type);

char* __cdecl BrMemStrDup(char *str);

#endif
