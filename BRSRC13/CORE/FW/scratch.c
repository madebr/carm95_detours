#include "scratch.h"

#include "harness/trace.h"

#include "carm95_hooks.h"

#include "carm95_webserver.h"

#include <assert.h>
#if 0
char(* hookvar_scratchString )[512];
#endif

function_hook_state_t function_hook_state_BrScratchAllocate = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_BrScratchAllocate)
static void *(__cdecl*original_BrScratchAllocate)(br_size_t) = (void *(__cdecl*)(br_size_t))0x004e0930;
CARM95_HOOK_FUNCTION(original_BrScratchAllocate, BrScratchAllocate)
void* __cdecl BrScratchAllocate(br_size_t size) {
    LOG_TRACE("(%u)", size);

    (void)size;

    if (function_hook_state_BrScratchAllocate == HOOK_ENABLED) {
        assert(0 && "BrScratchAllocate not implemented.");
        abort();
    } else {
        return original_BrScratchAllocate(size);
    }
}

function_hook_state_t function_hook_state_BrScratchFree = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_BrScratchFree)
static void(__cdecl*original_BrScratchFree)(void *) = (void(__cdecl*)(void *))0x004e09a0;
CARM95_HOOK_FUNCTION(original_BrScratchFree, BrScratchFree)
void __cdecl BrScratchFree(void *scratch) {
    LOG_TRACE("(%p)", scratch);

    (void)scratch;

    if (function_hook_state_BrScratchFree == HOOK_ENABLED) {
        assert(0 && "BrScratchFree not implemented.");
        abort();
    } else {
        original_BrScratchFree(scratch);
    }
}

function_hook_state_t function_hook_state_BrScratchFlush = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_BrScratchFlush)
static void(__cdecl*original_BrScratchFlush)() = (void(__cdecl*)())0x004e09b0;
CARM95_HOOK_FUNCTION(original_BrScratchFlush, BrScratchFlush)
void __cdecl BrScratchFlush() {
    LOG_TRACE("()");


    if (function_hook_state_BrScratchFlush == HOOK_ENABLED) {
        assert(0 && "BrScratchFlush not implemented.");
        abort();
    } else {
        original_BrScratchFlush();
    }
}

function_hook_state_t function_hook_state_BrScratchInquire = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_BrScratchInquire)
static br_size_t(__cdecl*original_BrScratchInquire)() = (br_size_t(__cdecl*)())0x004e09f0;
CARM95_HOOK_FUNCTION(original_BrScratchInquire, BrScratchInquire)
br_size_t __cdecl BrScratchInquire() {
    LOG_TRACE("()");


    if (function_hook_state_BrScratchInquire == HOOK_ENABLED) {
        assert(0 && "BrScratchInquire not implemented.");
        abort();
    } else {
        return original_BrScratchInquire();
    }
}

function_hook_state_t function_hook_state_BrScratchString = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_BrScratchString)
static char *(__cdecl*original_BrScratchString)() = (char *(__cdecl*)())0x004e0a00;
CARM95_HOOK_FUNCTION(original_BrScratchString, BrScratchString)
char* __cdecl BrScratchString() {
    LOG_TRACE("()");


    if (function_hook_state_BrScratchString == HOOK_ENABLED) {
        assert(0 && "BrScratchString not implemented.");
        abort();
    } else {
        return original_BrScratchString();
    }
}

function_hook_state_t function_hook_state_BrScratchStringSize = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_BrScratchStringSize)
static br_size_t(__cdecl*original_BrScratchStringSize)() = (br_size_t(__cdecl*)())0x004e0a10;
CARM95_HOOK_FUNCTION(original_BrScratchStringSize, BrScratchStringSize)
br_size_t __cdecl BrScratchStringSize() {
    LOG_TRACE("()");


    if (function_hook_state_BrScratchStringSize == HOOK_ENABLED) {
        assert(0 && "BrScratchStringSize not implemented.");
        abort();
    } else {
        return original_BrScratchStringSize();
    }
}

