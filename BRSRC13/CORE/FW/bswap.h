#ifndef _BSWAP_H_
#define _BSWAP_H_

#include "br_types.h"


br_uint_32 __cdecl BrSwap32(br_uint_32 l);

br_uint_16 __cdecl BrSwap16(br_uint_16 s);

br_float __cdecl BrSwapFloat(br_float f);

void* __cdecl BrSwapBlock(void *block, int count, int size);

#endif
