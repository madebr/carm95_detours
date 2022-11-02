#include "drmem.h"

#include "harness/trace.h"

#include "carm95_hooks.h"

#include "carm95_webserver.h"

#include <assert.h>
br_allocator * hookvar_gAllocator  = (void*)0x00513600;
int * hookvar_gNon_fatal_allocation_errors  = (void*)0x00513614;
char *(* hookvar_gMem_names )[247] = (void*)0x00513618;
br_resource_class(* hookvar_gStainless_classes )[118] = (void*)0x00537960;

function_hook_state_t function_hook_state_SetNonFatalAllocationErrors = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_SetNonFatalAllocationErrors)
static void(__cdecl*original_SetNonFatalAllocationErrors)() = (void(__cdecl*)())0x00463d80;
CARM95_HOOK_FUNCTION(original_SetNonFatalAllocationErrors, SetNonFatalAllocationErrors)
void __cdecl SetNonFatalAllocationErrors() {
    LOG_TRACE("()");


    if (function_hook_state_SetNonFatalAllocationErrors == HOOK_ENABLED) {
        assert(0 && "SetNonFatalAllocationErrors not implemented.");
        abort();
    } else {
        original_SetNonFatalAllocationErrors();
    }
}

function_hook_state_t function_hook_state_ResetNonFatalAllocationErrors = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_ResetNonFatalAllocationErrors)
static void(__cdecl*original_ResetNonFatalAllocationErrors)() = (void(__cdecl*)())0x00463d95;
CARM95_HOOK_FUNCTION(original_ResetNonFatalAllocationErrors, ResetNonFatalAllocationErrors)
void __cdecl ResetNonFatalAllocationErrors() {
    LOG_TRACE("()");


    if (function_hook_state_ResetNonFatalAllocationErrors == HOOK_ENABLED) {
        assert(0 && "ResetNonFatalAllocationErrors not implemented.");
        abort();
    } else {
        original_ResetNonFatalAllocationErrors();
    }
}

function_hook_state_t function_hook_state_AllocationErrorsAreFatal = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_AllocationErrorsAreFatal)
static int(__cdecl*original_AllocationErrorsAreFatal)() = (int(__cdecl*)())0x00463daa;
CARM95_HOOK_FUNCTION(original_AllocationErrorsAreFatal, AllocationErrorsAreFatal)
int __cdecl AllocationErrorsAreFatal() {
    LOG_TRACE("()");


    if (function_hook_state_AllocationErrorsAreFatal == HOOK_ENABLED) {
        assert(0 && "AllocationErrorsAreFatal not implemented.");
        abort();
    } else {
        return original_AllocationErrorsAreFatal();
    }
}

function_hook_state_t function_hook_state_MAMSInitMem = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_MAMSInitMem)
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

    if (function_hook_state_MAMSInitMem == HOOK_ENABLED) {
        assert(0 && "MAMSInitMem not implemented.");
        abort();
    } else {
        original_MAMSInitMem();
    }
}

function_hook_state_t function_hook_state_PrintMemoryDump = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_PrintMemoryDump)
static void(__cdecl*original_PrintMemoryDump)(int, char *) = (void(__cdecl*)(int, char *))0x00463de4;
CARM95_HOOK_FUNCTION(original_PrintMemoryDump, PrintMemoryDump)
void __cdecl PrintMemoryDump(int pFlags, char *pTitle) {
    LOG_TRACE("(%d, \"%s\")", pFlags, pTitle);

    (void)pFlags;
    (void)pTitle;

    if (function_hook_state_PrintMemoryDump == HOOK_ENABLED) {
        assert(0 && "PrintMemoryDump not implemented.");
        abort();
    } else {
        original_PrintMemoryDump(pFlags, pTitle);
    }
}

function_hook_state_t function_hook_state_DRStdlibAllocate = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_DRStdlibAllocate)
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

    if (function_hook_state_DRStdlibAllocate == HOOK_ENABLED) {
        assert(0 && "DRStdlibAllocate not implemented.");
        abort();
    } else {
        return original_DRStdlibAllocate(size, type);
    }
}

function_hook_state_t function_hook_state_DRStdlibFree = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_DRStdlibFree)
static void(__cdecl*original_DRStdlibFree)(void *) = (void(__cdecl*)(void *))0x00463ea1;
CARM95_HOOK_FUNCTION(original_DRStdlibFree, DRStdlibFree)
void __cdecl DRStdlibFree(void *mem) {
    int i;
    LOG_TRACE("(%p)", mem);

    (void)mem;
    (void)i;

    if (function_hook_state_DRStdlibFree == HOOK_ENABLED) {
        assert(0 && "DRStdlibFree not implemented.");
        abort();
    } else {
        original_DRStdlibFree(mem);
    }
}

function_hook_state_t function_hook_state_DRStdlibInquire = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_DRStdlibInquire)
static br_size_t(__cdecl*original_DRStdlibInquire)(br_uint_8) = (br_size_t(__cdecl*)(br_uint_8))0x00463ebb;
CARM95_HOOK_FUNCTION(original_DRStdlibInquire, DRStdlibInquire)
br_size_t __cdecl DRStdlibInquire(br_uint_8 type) {
    LOG_TRACE("(%u)", type);

    (void)type;

    if (function_hook_state_DRStdlibInquire == HOOK_ENABLED) {
        assert(0 && "DRStdlibInquire not implemented.");
        abort();
    } else {
        return original_DRStdlibInquire(type);
    }
}

function_hook_state_t function_hook_state_Claim4ByteAlignment = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_Claim4ByteAlignment)
static br_uint_32(__cdecl*original_Claim4ByteAlignment)(br_uint_8) = (br_uint_32(__cdecl*)(br_uint_8))0x00463ecd;
CARM95_HOOK_FUNCTION(original_Claim4ByteAlignment, Claim4ByteAlignment)
br_uint_32 __cdecl Claim4ByteAlignment(br_uint_8 type) {
    LOG_TRACE("(%u)", type);

    (void)type;

    if (function_hook_state_Claim4ByteAlignment == HOOK_ENABLED) {
        assert(0 && "Claim4ByteAlignment not implemented.");
        abort();
    } else {
        return original_Claim4ByteAlignment(type);
    }
}

function_hook_state_t function_hook_state_InstallDRMemCalls = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_InstallDRMemCalls)
static void(__cdecl*original_InstallDRMemCalls)() = (void(__cdecl*)())0x00463ee2;
CARM95_HOOK_FUNCTION(original_InstallDRMemCalls, InstallDRMemCalls)
void __cdecl InstallDRMemCalls() {
    LOG_TRACE("()");


    if (function_hook_state_InstallDRMemCalls == HOOK_ENABLED) {
        assert(0 && "InstallDRMemCalls not implemented.");
        abort();
    } else {
        original_InstallDRMemCalls();
    }
}

function_hook_state_t function_hook_state_MAMSUnlock = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_MAMSUnlock)
static void(__cdecl*original_MAMSUnlock)(void **) = (void(__cdecl*)(void **))0x00463efa;
CARM95_HOOK_FUNCTION(original_MAMSUnlock, MAMSUnlock)
void __cdecl MAMSUnlock(void **pPtr) {
    LOG_TRACE("(%p)", pPtr);

    (void)pPtr;

    if (function_hook_state_MAMSUnlock == HOOK_ENABLED) {
        assert(0 && "MAMSUnlock not implemented.");
        abort();
    } else {
        original_MAMSUnlock(pPtr);
    }
}

function_hook_state_t function_hook_state_MAMSLock = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_MAMSLock)
static void(__cdecl*original_MAMSLock)(void **) = (void(__cdecl*)(void **))0x00463f1c;
CARM95_HOOK_FUNCTION(original_MAMSLock, MAMSLock)
void __cdecl MAMSLock(void **pPtr) {
    LOG_TRACE("(%p)", pPtr);

    (void)pPtr;

    if (function_hook_state_MAMSLock == HOOK_ENABLED) {
        assert(0 && "MAMSLock not implemented.");
        abort();
    } else {
        original_MAMSLock(pPtr);
    }
}

function_hook_state_t function_hook_state_CreateStainlessClasses = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_CreateStainlessClasses)
static void(__cdecl*original_CreateStainlessClasses)() = (void(__cdecl*)())0x00463f27;
CARM95_HOOK_FUNCTION(original_CreateStainlessClasses, CreateStainlessClasses)
void __cdecl CreateStainlessClasses() {
    int i;
    LOG_TRACE("()");

    (void)i;

    if (function_hook_state_CreateStainlessClasses == HOOK_ENABLED) {
        assert(0 && "CreateStainlessClasses not implemented.");
        abort();
    } else {
        original_CreateStainlessClasses();
    }
}

function_hook_state_t function_hook_state_CheckMemory = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_CheckMemory)
static void(__cdecl*original_CheckMemory)() = (void(__cdecl*)())0x00463f97;
CARM95_HOOK_FUNCTION(original_CheckMemory, CheckMemory)
void __cdecl CheckMemory() {
    LOG_TRACE("()");


    if (function_hook_state_CheckMemory == HOOK_ENABLED) {
        assert(0 && "CheckMemory not implemented.");
        abort();
    } else {
        original_CheckMemory();
    }
}

