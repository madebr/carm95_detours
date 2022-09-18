#ifndef _DRMEM_H_
#define _DRMEM_H_

#include "br_types.h"
#include "dr_types.h"

extern br_allocator * hookvar_gAllocator ; // addr: 00513600
extern int * hookvar_gNon_fatal_allocation_errors ; // addr: 00513614
extern char *(* hookvar_gMem_names )[247]; // addr: 00513618
extern br_resource_class(* hookvar_gStainless_classes )[118]; // addr: 00537960

void __cdecl SetNonFatalAllocationErrors();

void __cdecl ResetNonFatalAllocationErrors();

int __cdecl AllocationErrorsAreFatal();

void __cdecl MAMSInitMem();

void __cdecl PrintMemoryDump(int pFlags, char *pTitle);

void* __cdecl DRStdlibAllocate(br_size_t size, br_uint_8 type);

void __cdecl DRStdlibFree(void *mem);

br_size_t __cdecl DRStdlibInquire(br_uint_8 type);

br_uint_32 __cdecl Claim4ByteAlignment(br_uint_8 type);

void __cdecl InstallDRMemCalls();

void __cdecl MAMSUnlock(void **pPtr);

void __cdecl MAMSLock(void **pPtr);

void __cdecl CreateStainlessClasses();

void __cdecl CheckMemory();

#endif
