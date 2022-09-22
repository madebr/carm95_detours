#include "mem.h"

#include "harness/trace.h"

#include "carm95_hooks.h"


static void *(__cdecl*original_BrMemAllocate)(br_size_t, br_uint_8) = (void *(__cdecl*)(br_size_t, br_uint_8))0x004df250;
CARM95_HOOK_FUNCTION(original_BrMemAllocate, BrMemAllocate)
void* __cdecl BrMemAllocate(br_size_t size, br_uint_8 type) {
    void *b;
    LOG_TRACE("(%u, %u)", size, type);

    (void)size;
    (void)type;
    (void)b;

    return original_BrMemAllocate(size, type);
}

static void(__cdecl*original_BrMemFree)(void *) = (void(__cdecl*)(void *))0x004df280;
CARM95_HOOK_FUNCTION(original_BrMemFree, BrMemFree)
void __cdecl BrMemFree(void *block) {
    LOG_TRACE("(%p)", block);

    (void)block;

    original_BrMemFree(block);
}

static br_size_t(__cdecl*original_BrMemInquire)(br_uint_8) = (br_size_t(__cdecl*)(br_uint_8))0x004df2a0;
CARM95_HOOK_FUNCTION(original_BrMemInquire, BrMemInquire)
br_size_t __cdecl BrMemInquire(br_uint_8 type) {
    br_size_t i;
    LOG_TRACE("(%u)", type);

    (void)type;
    (void)i;

    return original_BrMemInquire(type);
}

br_int_32 BrMemAlign(br_uint_8 type) {
    br_int_32 i;
    LOG_TRACE("(%u)", type);

    (void)type;
    (void)i;

    NOT_IMPLEMENTED();
}

static void *(__cdecl*original_BrMemCalloc)(int, br_size_t, br_uint_8) = (void *(__cdecl*)(int, br_size_t, br_uint_8))0x004df2e0;
CARM95_HOOK_FUNCTION(original_BrMemCalloc, BrMemCalloc)
void* __cdecl BrMemCalloc(int nelems, br_size_t size, br_uint_8 type) {
    void *b;
    LOG_TRACE("(%d, %u, %u)", nelems, size, type);

    (void)nelems;
    (void)size;
    (void)type;
    (void)b;

    return original_BrMemCalloc(nelems, size, type);
}

static char *(__cdecl*original_BrMemStrDup)(char *) = (char *(__cdecl*)(char *))0x004df320;
CARM95_HOOK_FUNCTION(original_BrMemStrDup, BrMemStrDup)
char* __cdecl BrMemStrDup(char *str) {
    int l;
    char *nstr;
    LOG_TRACE("(\"%s\")", str);

    (void)str;
    (void)l;
    (void)nstr;

    return original_BrMemStrDup(str);
}

