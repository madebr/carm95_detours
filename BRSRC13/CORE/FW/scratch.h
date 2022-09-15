#ifndef _SCRATCH_H_
#define _SCRATCH_H_

#include "br_types.h"

// extern char(* hookvar_scratchString )[512];

void* BrScratchAllocate(br_size_t size);

void BrScratchFree(void *scratch);

void BrScratchFlush();

br_size_t BrScratchInquire();

char* BrScratchString();

br_size_t BrScratchStringSize();

#endif
