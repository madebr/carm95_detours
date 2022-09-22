#ifndef _MATSUPT_H_
#define _MATSUPT_H_

#include "br_types.h"


br_material* __cdecl BrMaterialAllocate(char *name);

void __cdecl BrMaterialFree(br_material *m);

#endif
