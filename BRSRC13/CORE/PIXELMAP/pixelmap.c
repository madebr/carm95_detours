#include "pixelmap.h"

#include "harness/trace.h"

#include "carm95_hooks.h"

#include "carm95_webserver.h"

#include <assert.h>

function_hook_state_t function_hook_state_BrPixelmapAllocate = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(BrPixelmapAllocate, function_hook_state_BrPixelmapAllocate)
static br_pixelmap *(__cdecl*original_BrPixelmapAllocate)(br_uint_8, br_int_32, br_int_32, void *, int) = (br_pixelmap *(__cdecl*)(br_uint_8, br_int_32, br_int_32, void *, int))0x004caef0;
CARM95_HOOK_FUNCTION(original_BrPixelmapAllocate, BrPixelmapAllocate)
br_pixelmap* __cdecl BrPixelmapAllocate(br_uint_8 type, br_int_32 w, br_int_32 h, void *pixels, int flags) {
    LOG_TRACE("(%u, %d, %d, %p, %d)", type, w, h, pixels, flags);

    (void)type;
    (void)w;
    (void)h;
    (void)pixels;
    (void)flags;

    if (function_hook_state_BrPixelmapAllocate == HOOK_ENABLED) {
        assert(0 && "BrPixelmapAllocate not implemented.");
        abort();
    } else {
        return original_BrPixelmapAllocate(type, w, h, pixels, flags);
    }
}

