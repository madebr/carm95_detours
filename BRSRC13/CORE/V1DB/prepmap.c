#include "prepmap.h"

#include "harness/trace.h"

#include "carm95_hooks.h"


static void(__cdecl*original_BrMapUpdate)(br_pixelmap *, br_uint_16) = (void(__cdecl*)(br_pixelmap *, br_uint_16))0x004dc8b0;
CARM95_HOOK_FUNCTION(original_BrMapUpdate, BrMapUpdate)
void __cdecl BrMapUpdate(br_pixelmap *map, br_uint_16 flags) {
    LOG_TRACE("(%p, %u)", map, flags);

    (void)map;
    (void)flags;

    original_BrMapUpdate(map, flags);
}

static void(__stdcall*original_BrBufferUpdate)(br_pixelmap *, br_token, br_uint_16) = (void(__stdcall*)(br_pixelmap *, br_token, br_uint_16))0x004dc930;
CARM95_HOOK_FUNCTION(original_BrBufferUpdate, BrBufferUpdate)
void __stdcall BrBufferUpdate(br_pixelmap *pm, br_token use, br_uint_16 flags) {
    br_token_value tv[3];
    LOG_TRACE("(%p, %d, %u)", pm, use, flags);

    (void)pm;
    (void)use;
    (void)flags;
    (void)tv;

    original_BrBufferUpdate(pm, use, flags);
}

static void(__stdcall*original_BrBufferClear)(br_pixelmap *) = (void(__stdcall*)(br_pixelmap *))0x004dc9b0;
CARM95_HOOK_FUNCTION(original_BrBufferClear, BrBufferClear)
void __stdcall BrBufferClear(br_pixelmap *pm) {
    LOG_TRACE("(%p)", pm);

    (void)pm;

    original_BrBufferClear(pm);
}

