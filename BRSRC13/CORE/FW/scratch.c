#include "scratch.h"

#include "harness/trace.h"

#include "carm95_hooks.h"

#include <stdio.h>
#if 0
char(* hookvar_scratchString )[512];
#endif

static void *(*original_BrScratchAllocate)(br_size_t, ...) = (void *(*)(br_size_t, ...))0x004e0930;
CARM95_HOOK_FUNCTION(original_BrScratchAllocate, BrScratchAllocate)
void* BrScratchAllocate(br_size_t size) {
    LOG_TRACE("(%u)", size);

    (void)size;

    return original_BrScratchAllocate(size);
}

static void(*original_BrScratchFree)(void *, ...) = (void(*)(void *, ...))0x004e09a0;
CARM95_HOOK_FUNCTION(original_BrScratchFree, BrScratchFree)
void BrScratchFree(void *scratch) {
    LOG_TRACE("(%p)", scratch);

    (void)scratch;

    original_BrScratchFree(scratch);
}

static void(*original_BrScratchFlush)() = (void(*)())0x004e09b0;
CARM95_HOOK_FUNCTION(original_BrScratchFlush, BrScratchFlush)
void BrScratchFlush() {
    LOG_TRACE("()");


    original_BrScratchFlush();
}

static br_size_t(*original_BrScratchInquire)() = (br_size_t(*)())0x004e09f0;
CARM95_HOOK_FUNCTION(original_BrScratchInquire, BrScratchInquire)
br_size_t BrScratchInquire() {
    LOG_TRACE("()");


    return original_BrScratchInquire();
}

static char *(*original_BrScratchString)() = (char *(*)())0x004e0a00;
CARM95_HOOK_FUNCTION(original_BrScratchString, BrScratchString)
char* BrScratchString() {
    LOG_TRACE("()");


    return original_BrScratchString();
}

static br_size_t(*original_BrScratchStringSize)() = (br_size_t(*)())0x004e0a10;
CARM95_HOOK_FUNCTION(original_BrScratchStringSize, BrScratchStringSize)
br_size_t BrScratchStringSize() {
    LOG_TRACE("()");


    return original_BrScratchStringSize();
}

