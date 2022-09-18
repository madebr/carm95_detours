#include "bswap.h"

#include "harness/trace.h"

#include "carm95_hooks.h"


static br_uint_32(__cdecl*original_BrSwap32)(br_uint_32) = (br_uint_32(__cdecl*)(br_uint_32))0x004df980;
CARM95_HOOK_FUNCTION(original_BrSwap32, BrSwap32)
br_uint_32 __cdecl BrSwap32(br_uint_32 l) {
    union {		// size: 0x4
        unsigned char c[4];		// @0x0
        unsigned long l;		// @0x0
    } u;
    LOG_TRACE("(%u)", l);

    (void)l;
    (void)u;

    return original_BrSwap32(l);
}

static br_uint_16(__cdecl*original_BrSwap16)(br_uint_16) = (br_uint_16(__cdecl*)(br_uint_16))0x004df9d0;
CARM95_HOOK_FUNCTION(original_BrSwap16, BrSwap16)
br_uint_16 __cdecl BrSwap16(br_uint_16 s) {
    union {		// size: 0x2
        unsigned char c[2];		// @0x0
        unsigned short s;		// @0x0
    } u;
    LOG_TRACE("(%u)", s);

    (void)s;
    (void)u;

    return original_BrSwap16(s);
}

static br_float(__cdecl*original_BrSwapFloat)(br_float) = (br_float(__cdecl*)(br_float))0x004dfa00;
CARM95_HOOK_FUNCTION(original_BrSwapFloat, BrSwapFloat)
br_float __cdecl BrSwapFloat(br_float f) {
    union {		// size: 0x4
        unsigned char c[4];		// @0x0
        br_float f;		// @0x0
    } u;
    LOG_TRACE("(%f)", f);

    (void)f;
    (void)u;

    return original_BrSwapFloat(f);
}

static void *(__cdecl*original_BrSwapBlock)(void *, int, int) = (void *(__cdecl*)(void *, int, int))0x004dfa50;
CARM95_HOOK_FUNCTION(original_BrSwapBlock, BrSwapBlock)
void* __cdecl BrSwapBlock(void *block, int count, int size) {
    br_uint_8 *cp;
    int i;
    int k;
    LOG_TRACE("(%p, %d, %d)", block, count, size);

    (void)block;
    (void)count;
    (void)size;
    (void)cp;
    (void)i;
    (void)k;

    return original_BrSwapBlock(block, count, size);
}

