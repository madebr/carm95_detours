#include "preptab.h"

#include "harness/trace.h"

#include "carm95_hooks.h"

#include "carm95_webserver.h"

#include <assert.h>

function_hook_state_t function_hook_state_BrTableUpdate = HOOK_UNAVAILABLE;
static void(__cdecl*original_BrTableUpdate)(br_pixelmap *, br_uint_16) = (void(__cdecl*)(br_pixelmap *, br_uint_16))0x004dda70;
CARM95_HOOK_FUNCTION(original_BrTableUpdate, BrTableUpdate)
void __cdecl BrTableUpdate(br_pixelmap *table, br_uint_16 flags) {
    LOG_TRACE("(%p, %u)", table, flags);

    (void)table;
    (void)flags;

    if (function_hook_state_BrTableUpdate == HOOK_ENABLED) {
        assert(0 && "BrTableUpdate not implemented.");
        abort();
    } else {
        original_BrTableUpdate(table, flags);
    }
}

