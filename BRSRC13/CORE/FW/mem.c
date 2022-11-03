#include "mem.h"

#include "harness/trace.h"

#include "carm95_hooks.h"

#include "carm95_webserver.h"

#include <assert.h>

function_hook_state_t function_hook_state_BrMemAllocate = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(BrMemAllocate, function_hook_state_BrMemAllocate)
static void *(__cdecl*original_BrMemAllocate)(br_size_t, br_uint_8) = (void *(__cdecl*)(br_size_t, br_uint_8))0x004df250;
CARM95_HOOK_FUNCTION(original_BrMemAllocate, BrMemAllocate)
void* __cdecl BrMemAllocate(br_size_t size, br_uint_8 type) {
    void *b;
    LOG_TRACE("(%u, %u)", size, type);

    (void)size;
    (void)type;
    (void)b;

    if (function_hook_state_BrMemAllocate == HOOK_ENABLED) {
        assert(0 && "BrMemAllocate not implemented.");
        abort();
    } else {
        return original_BrMemAllocate(size, type);
    }
}

function_hook_state_t function_hook_state_BrMemFree = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(BrMemFree, function_hook_state_BrMemFree)
static void(__cdecl*original_BrMemFree)(void *) = (void(__cdecl*)(void *))0x004df280;
CARM95_HOOK_FUNCTION(original_BrMemFree, BrMemFree)
void __cdecl BrMemFree(void *block) {
    LOG_TRACE("(%p)", block);

    (void)block;

    if (function_hook_state_BrMemFree == HOOK_ENABLED) {
        assert(0 && "BrMemFree not implemented.");
        abort();
    } else {
        original_BrMemFree(block);
    }
}

function_hook_state_t function_hook_state_BrMemInquire = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(BrMemInquire, function_hook_state_BrMemInquire)
static br_size_t(__cdecl*original_BrMemInquire)(br_uint_8) = (br_size_t(__cdecl*)(br_uint_8))0x004df2a0;
CARM95_HOOK_FUNCTION(original_BrMemInquire, BrMemInquire)
br_size_t __cdecl BrMemInquire(br_uint_8 type) {
    br_size_t i;
    LOG_TRACE("(%u)", type);

    (void)type;
    (void)i;

    if (function_hook_state_BrMemInquire == HOOK_ENABLED) {
        assert(0 && "BrMemInquire not implemented.");
        abort();
    } else {
        return original_BrMemInquire(type);
    }
}

function_hook_state_t function_hook_state_BrMemAlign = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(BrMemAlign, function_hook_state_BrMemAlign)
br_int_32 BrMemAlign(br_uint_8 type) {
    br_int_32 i;
    LOG_TRACE("(%u)", type);

    (void)type;
    (void)i;

    if (function_hook_state_BrMemAlign == HOOK_ENABLED) {
        assert(0 && "BrMemAlign not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}

function_hook_state_t function_hook_state_BrMemCalloc = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(BrMemCalloc, function_hook_state_BrMemCalloc)
static void *(__cdecl*original_BrMemCalloc)(int, br_size_t, br_uint_8) = (void *(__cdecl*)(int, br_size_t, br_uint_8))0x004df2e0;
CARM95_HOOK_FUNCTION(original_BrMemCalloc, BrMemCalloc)
void* __cdecl BrMemCalloc(int nelems, br_size_t size, br_uint_8 type) {
    void *b;
    LOG_TRACE("(%d, %u, %u)", nelems, size, type);

    (void)nelems;
    (void)size;
    (void)type;
    (void)b;

    if (function_hook_state_BrMemCalloc == HOOK_ENABLED) {
        assert(0 && "BrMemCalloc not implemented.");
        abort();
    } else {
        return original_BrMemCalloc(nelems, size, type);
    }
}

function_hook_state_t function_hook_state_BrMemStrDup = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(BrMemStrDup, function_hook_state_BrMemStrDup)
static char *(__cdecl*original_BrMemStrDup)(char *) = (char *(__cdecl*)(char *))0x004df320;
CARM95_HOOK_FUNCTION(original_BrMemStrDup, BrMemStrDup)
char* __cdecl BrMemStrDup(char *str) {
    int l;
    char *nstr;
    LOG_TRACE("(\"%s\")", str);

    (void)str;
    (void)l;
    (void)nstr;

    if (function_hook_state_BrMemStrDup == HOOK_ENABLED) {
        assert(0 && "BrMemStrDup not implemented.");
        abort();
    } else {
        return original_BrMemStrDup(str);
    }
}

