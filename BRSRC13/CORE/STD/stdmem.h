#ifndef _STDMEM_H_
#define _STDMEM_H_

#include "br_types.h"

extern br_allocator * hookvar_BrStdlibAllocator ; // addr: 00530090
// extern br_allocator ** hookvar__BrDefaultAllocator ;

void* BrStdlibAllocate(br_size_t size, br_uint_8 type);

void BrStdlibFree(void *mem);

br_size_t BrStdlibInquire(br_uint_8 type);

br_uint_32 BrStdlibAlign(br_uint_8 type);

#endif
