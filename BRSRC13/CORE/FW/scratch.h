#ifndef _SCRATCH_H_
#define _SCRATCH_H_

#include "br_types.h"

// extern char(* hookvar_scratchString )[512];

void* __cdecl BrScratchAllocate(br_size_t size);

void __cdecl BrScratchFree(void *scratch);

void __cdecl BrScratchFlush();

br_size_t __cdecl BrScratchInquire();

char* __cdecl BrScratchString();

br_size_t __cdecl BrScratchStringSize();

#endif
