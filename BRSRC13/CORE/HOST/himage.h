#ifndef _HIMAGE_H_
#define _HIMAGE_H_

#include "br_types.h"


void* __cdecl HostImageLoad(char *name);

#if 0
void HostImageUnload_do_not_use(void *image);
#endif

void* __cdecl HostImageLookupName(void *img, char *name, br_uint_32 hint);

#if 0
void* HostImageLookupOrdinal_do_not_use(void *img, br_uint_32 ordinal);
#endif

#endif
