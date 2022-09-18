#ifndef _RESREG_H_
#define _RESREG_H_

#include "br_types.h"


br_resource_class* __cdecl BrResClassAdd(br_resource_class *rclass);

br_resource_class* __cdecl BrResClassRemove(br_resource_class *rclass);

br_resource_class* __cdecl BrResClassFind(char *pattern);

br_resclass_find_cbfn* __cdecl BrResClassFindHook(br_resclass_find_cbfn *hook);

br_uint_32 __cdecl BrResClassAddMany(br_resource_class **items, int n);

br_uint_32 __cdecl BrResClassRemoveMany(br_resource_class **items, int n);

br_uint_32 __cdecl BrResClassFindMany(char *pattern, br_resource_class **items, int max);

br_uint_32 __cdecl BrResClassCount(char *pattern);

br_uint_32 __cdecl BrResClassEnum(char *pattern, br_resclass_enum_cbfn *callback, void *arg);

#endif
