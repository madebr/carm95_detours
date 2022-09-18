#include "drmem.h"

#include "harness/trace.h"

#include "carm95_hooks.h"

br_allocator * hookvar_gAllocator  = (void*)0x00513600;
int * hookvar_gNon_fatal_allocation_errors  = (void*)0x00513614;
char *(* hookvar_gMem_names )[247] = (void*)0x00513618;
br_resource_class(* hookvar_gStainless_classes )[118] = (void*)0x00537960;

static void(__cdecl*original_SetNonFatalAllocationErrors)() = (void(__cdecl*)())0x00463d80;
CARM95_HOOK_FUNCTION(original_SetNonFatalAllocationErrors, SetNonFatalAllocationErrors)
void __cdecl SetNonFatalAllocationErrors() {
    LOG_TRACE("()");


    original_SetNonFatalAllocationErrors();
}

static void(__cdecl*original_ResetNonFatalAllocationErrors)() = (void(__cdecl*)())0x00463d95;
CARM95_HOOK_FUNCTION(original_ResetNonFatalAllocationErrors, ResetNonFatalAllocationErrors)
void __cdecl ResetNonFatalAllocationErrors() {
    LOG_TRACE("()");


    original_ResetNonFatalAllocationErrors();
}

static int(__cdecl*original_AllocationErrorsAreFatal)() = (int(__cdecl*)())0x00463daa;
CARM95_HOOK_FUNCTION(original_AllocationErrorsAreFatal, AllocationErrorsAreFatal)
int __cdecl AllocationErrorsAreFatal() {
    LOG_TRACE("()");


    return original_AllocationErrorsAreFatal();
}

static void(__cdecl*original_MAMSInitMem)() = (void(__cdecl*)())0x00463dd3;
CARM95_HOOK_FUNCTION(original_MAMSInitMem, MAMSInitMem)
void __cdecl MAMSInitMem() {
    int i;
    FILE *f;
    tPath_name the_path;
    LOG_TRACE("()");

    (void)i;
    (void)f;
    (void)the_path;

    original_MAMSInitMem();
}

static void(__cdecl*original_PrintMemoryDump)(int, char *) = (void(__cdecl*)(int, char *))0x00463de4;
CARM95_HOOK_FUNCTION(original_PrintMemoryDump, PrintMemoryDump)
void __cdecl PrintMemoryDump(int pFlags, char *pTitle) {
    LOG_TRACE("(%d, \"%s\")", pFlags, pTitle);

    (void)pFlags;
    (void)pTitle;

    original_PrintMemoryDump(pFlags, pTitle);
}

static void *(__cdecl*original_DRStdlibAllocate)(br_size_t, br_uint_8) = (void *(__cdecl*)(br_size_t, br_uint_8))0x00463def;
CARM95_HOOK_FUNCTION(original_DRStdlibAllocate, DRStdlibAllocate)
void* __cdecl DRStdlibAllocate(br_size_t size, br_uint_8 type) {
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

static void(__cdecl*original_DRStdlibFree)(void *) = (void(__cdecl*)(void *))0x00463ea1;
CARM95_HOOK_FUNCTION(original_DRStdlibFree, DRStdlibFree)
void __cdecl DRStdlibFree(void *mem) {
    int i;
    LOG_TRACE("(%p)", mem);

    (void)mem;
    (void)i;

    original_DRStdlibFree(mem);
}

static br_size_t(__cdecl*original_DRStdlibInquire)(br_uint_8) = (br_size_t(__cdecl*)(br_uint_8))0x00463ebb;
CARM95_HOOK_FUNCTION(original_DRStdlibInquire, DRStdlibInquire)
br_size_t __cdecl DRStdlibInquire(br_uint_8 type) {
    LOG_TRACE("(%u)", type);

    (void)type;

    return original_DRStdlibInquire(type);
}

static br_uint_32(__cdecl*original_Claim4ByteAlignment)(br_uint_8) = (br_uint_32(__cdecl*)(br_uint_8))0x00463ecd;
CARM95_HOOK_FUNCTION(original_Claim4ByteAlignment, Claim4ByteAlignment)
br_uint_32 __cdecl Claim4ByteAlignment(br_uint_8 type) {
    LOG_TRACE("(%u)", type);

    (void)type;

    return original_Claim4ByteAlignment(type);
}

static void(__cdecl*original_InstallDRMemCalls)() = (void(__cdecl*)())0x00463ee2;
CARM95_HOOK_FUNCTION(original_InstallDRMemCalls, InstallDRMemCalls)
void __cdecl InstallDRMemCalls() {
    LOG_TRACE("()");


    original_InstallDRMemCalls();
}

static void(__cdecl*original_MAMSUnlock)(void **) = (void(__cdecl*)(void **))0x00463efa;
CARM95_HOOK_FUNCTION(original_MAMSUnlock, MAMSUnlock)
void __cdecl MAMSUnlock(void **pPtr) {
    LOG_TRACE("(%p)", pPtr);

    (void)pPtr;

    original_MAMSUnlock(pPtr);
}

static void(__cdecl*original_MAMSLock)(void **) = (void(__cdecl*)(void **))0x00463f1c;
CARM95_HOOK_FUNCTION(original_MAMSLock, MAMSLock)
void __cdecl MAMSLock(void **pPtr) {
    LOG_TRACE("(%p)", pPtr);

    (void)pPtr;

    original_MAMSLock(pPtr);
}

static void(__cdecl*original_CreateStainlessClasses)() = (void(__cdecl*)())0x00463f27;
CARM95_HOOK_FUNCTION(original_CreateStainlessClasses, CreateStainlessClasses)
void __cdecl CreateStainlessClasses() {
    int i;
    LOG_TRACE("()");

    (void)i;

    original_CreateStainlessClasses();
}

static void(__cdecl*original_CheckMemory)() = (void(__cdecl*)())0x00463f97;
CARM95_HOOK_FUNCTION(original_CheckMemory, CheckMemory)
void __cdecl CheckMemory() {
    LOG_TRACE("()");


    original_CheckMemory();
}

