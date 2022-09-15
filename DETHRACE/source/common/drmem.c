#include "drmem.h"

#include "harness/trace.h"

#include "carm95_hooks.h"

#include <stdio.h>
br_allocator * hookvar_gAllocator  = (void*)0x00513600;
int * hookvar_gNon_fatal_allocation_errors  = (void*)0x00513614;
char *(* hookvar_gMem_names )[247] = (void*)0x00513618;
br_resource_class(* hookvar_gStainless_classes )[118] = (void*)0x00537960;

static void(*original_SetNonFatalAllocationErrors)() = (void(*)())0x00463d80;
CARM95_HOOK_FUNCTION(original_SetNonFatalAllocationErrors, SetNonFatalAllocationErrors)
void SetNonFatalAllocationErrors() {
    LOG_TRACE("()");


    original_SetNonFatalAllocationErrors();
}

static void(*original_ResetNonFatalAllocationErrors)() = (void(*)())0x00463d95;
CARM95_HOOK_FUNCTION(original_ResetNonFatalAllocationErrors, ResetNonFatalAllocationErrors)
void ResetNonFatalAllocationErrors() {
    LOG_TRACE("()");


    original_ResetNonFatalAllocationErrors();
}

static int(*original_AllocationErrorsAreFatal)() = (int(*)())0x00463daa;
CARM95_HOOK_FUNCTION(original_AllocationErrorsAreFatal, AllocationErrorsAreFatal)
int AllocationErrorsAreFatal() {
    LOG_TRACE("()");


    return original_AllocationErrorsAreFatal();
}

static void(*original_MAMSInitMem)() = (void(*)())0x00463dd3;
CARM95_HOOK_FUNCTION(original_MAMSInitMem, MAMSInitMem)
void MAMSInitMem() {
    int i;
    FILE *f;
    tPath_name the_path;
    LOG_TRACE("()");

    (void)i;
    (void)f;
    (void)the_path;

    original_MAMSInitMem();
}

static void(*original_PrintMemoryDump)(int, char *, ...) = (void(*)(int, char *, ...))0x00463de4;
CARM95_HOOK_FUNCTION(original_PrintMemoryDump, PrintMemoryDump)
void PrintMemoryDump(int pFlags, char *pTitle) {
    LOG_TRACE("(%d, \"%s\")", pFlags, pTitle);

    (void)pFlags;
    (void)pTitle;

    original_PrintMemoryDump(pFlags, pTitle);
}

static void *(*original_DRStdlibAllocate)(br_size_t, br_uint_8, ...) = (void *(*)(br_size_t, br_uint_8, ...))0x00463def;
CARM95_HOOK_FUNCTION(original_DRStdlibAllocate, DRStdlibAllocate)
void* DRStdlibAllocate(br_size_t size, br_uint_8 type) {
    void *p;
    int i;
    char s[256];
    LOG_TRACE("(%u, %u)", size, type);

    (void)size;
    (void)type;
    (void)p;
    (void)i;
    (void)s;

    return original_DRStdlibAllocate(size, type);
}

static void(*original_DRStdlibFree)(void *, ...) = (void(*)(void *, ...))0x00463ea1;
CARM95_HOOK_FUNCTION(original_DRStdlibFree, DRStdlibFree)
void DRStdlibFree(void *mem) {
    int i;
    LOG_TRACE("(%p)", mem);

    (void)mem;
    (void)i;

    original_DRStdlibFree(mem);
}

static br_size_t(*original_DRStdlibInquire)(br_uint_8, ...) = (br_size_t(*)(br_uint_8, ...))0x00463ebb;
CARM95_HOOK_FUNCTION(original_DRStdlibInquire, DRStdlibInquire)
br_size_t DRStdlibInquire(br_uint_8 type) {
    LOG_TRACE("(%u)", type);

    (void)type;

    return original_DRStdlibInquire(type);
}

static br_uint_32(*original_Claim4ByteAlignment)(br_uint_8, ...) = (br_uint_32(*)(br_uint_8, ...))0x00463ecd;
CARM95_HOOK_FUNCTION(original_Claim4ByteAlignment, Claim4ByteAlignment)
br_uint_32 Claim4ByteAlignment(br_uint_8 type) {
    LOG_TRACE("(%u)", type);

    (void)type;

    return original_Claim4ByteAlignment(type);
}

static void(*original_InstallDRMemCalls)() = (void(*)())0x00463ee2;
CARM95_HOOK_FUNCTION(original_InstallDRMemCalls, InstallDRMemCalls)
void InstallDRMemCalls() {
    LOG_TRACE("()");


    original_InstallDRMemCalls();
}

static void(*original_MAMSUnlock)(void **, ...) = (void(*)(void **, ...))0x00463efa;
CARM95_HOOK_FUNCTION(original_MAMSUnlock, MAMSUnlock)
void MAMSUnlock(void **pPtr) {
    LOG_TRACE("(%p)", pPtr);

    (void)pPtr;

    original_MAMSUnlock(pPtr);
}

static void(*original_MAMSLock)(void **, ...) = (void(*)(void **, ...))0x00463f1c;
CARM95_HOOK_FUNCTION(original_MAMSLock, MAMSLock)
void MAMSLock(void **pPtr) {
    LOG_TRACE("(%p)", pPtr);

    (void)pPtr;

    original_MAMSLock(pPtr);
}

static void(*original_CreateStainlessClasses)() = (void(*)())0x00463f27;
CARM95_HOOK_FUNCTION(original_CreateStainlessClasses, CreateStainlessClasses)
void CreateStainlessClasses() {
    int i;
    LOG_TRACE("()");

    (void)i;

    original_CreateStainlessClasses();
}

static void(*original_CheckMemory)() = (void(*)())0x00463f97;
CARM95_HOOK_FUNCTION(original_CheckMemory, CheckMemory)
void CheckMemory() {
    LOG_TRACE("()");


    original_CheckMemory();
}

