#include "scratch.h"

#include "harness/trace.h"

#include "carm95_hooks.h"

#if 0
char(* hookvar_scratchString )[512];
#endif

static void *(__cdecl*original_BrScratchAllocate)(br_size_t) = (void *(__cdecl*)(br_size_t))0x004e0930;
CARM95_HOOK_FUNCTION(original_BrScratchAllocate, BrScratchAllocate)
void* __cdecl BrScratchAllocate(br_size_t size) {
    LOG_TRACE("(%u)", size);

    (void)size;

    return original_BrScratchAllocate(size);
}

static void(__cdecl*original_BrScratchFree)(void *) = (void(__cdecl*)(void *))0x004e09a0;
CARM95_HOOK_FUNCTION(original_BrScratchFree, BrScratchFree)
void __cdecl BrScratchFree(void *scratch) {
    LOG_TRACE("(%p)", scratch);

    (void)scratch;

    original_BrScratchFree(scratch);
}

static void(__cdecl*original_BrScratchFlush)() = (void(__cdecl*)())0x004e09b0;
CARM95_HOOK_FUNCTION(original_BrScratchFlush, BrScratchFlush)
void __cdecl BrScratchFlush() {
    LOG_TRACE("()");


    original_BrScratchFlush();
}

static br_size_t(__cdecl*original_BrScratchInquire)() = (br_size_t(__cdecl*)())0x004e09f0;
CARM95_HOOK_FUNCTION(original_BrScratchInquire, BrScratchInquire)
br_size_t __cdecl BrScratchInquire() {
    LOG_TRACE("()");


    return original_BrScratchInquire();
}

static char *(__cdecl*original_BrScratchString)() = (char *(__cdecl*)())0x004e0a00;
CARM95_HOOK_FUNCTION(original_BrScratchString, BrScratchString)
char* __cdecl BrScratchString() {
    LOG_TRACE("()");


    return original_BrScratchString();
}

static br_size_t(__cdecl*original_BrScratchStringSize)() = (br_size_t(__cdecl*)())0x004e0a10;
CARM95_HOOK_FUNCTION(original_BrScratchStringSize, BrScratchStringSize)
br_size_t __cdecl BrScratchStringSize() {
    LOG_TRACE("()");


    return original_BrScratchStringSize();
}

