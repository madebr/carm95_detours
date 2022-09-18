#ifndef _RESOURCE_H_
#define _RESOURCE_H_

#include "br_types.h"


void* ResToUser(struct resource_header *r);

struct resource_header* UserToRes(void *r);

void* __cdecl BrResAllocate(void *vparent, br_size_t size, br_uint_8 res_class);

void __stdcall BrResInternalFree(struct resource_header *res, br_boolean callback);

void __cdecl BrResFree(void *vres);

void __cdecl BrResFreeNoCallback(void *vres);

void* __cdecl BrResAdd(void *vparent, void *vres);

void* __cdecl BrResRemove(void *vres);

br_uint_8 __cdecl BrResClass(void *vres);

br_boolean __cdecl BrResIsChild(void *vparent, void *vchild);

br_uint_32 __cdecl BrResSize(void *vres);

br_uint_32 __cdecl ResSizeTotal(void *vres, br_uint_32 *ptotal);

br_uint_32 __cdecl BrResSizeTotal(void *vres);

br_uint_32 __cdecl BrResChildEnum(void *vres, br_resenum_cbfn *callback, void *arg);

br_uint_32 __cdecl BrResCheck(void *vres, int no_tag);

char* __cdecl BrResStrDup(void *vparent, char *str);

void InternalResourceDump(struct resource_header *res, br_putline_cbfn *putline, void *arg, int level);

#if 0
void BrResDump_do_not_use(void *vres, br_putline_cbfn *putline, void *arg);
#endif

char* BrResClassIdentifier(br_uint_8 res_class);

#endif
