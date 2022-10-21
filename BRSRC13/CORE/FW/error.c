#include "error.h"

#include "harness/trace.h"

#include "carm95_hooks.h"

#include "carm95_webserver.h"

#include <assert.h>

function_hook_state_t function_hook_state_BrLastErrorGet = HOOK_UNAVAILABLE;
static br_error(__cdecl*original_BrLastErrorGet)(void **) = (br_error(__cdecl*)(void **))0x004e7850;
CARM95_HOOK_FUNCTION(original_BrLastErrorGet, BrLastErrorGet)
br_error __cdecl BrLastErrorGet(void **valuep) {
    LOG_TRACE("(%p)", valuep);

    (void)valuep;

    if (function_hook_state_BrLastErrorGet == HOOK_ENABLED) {
        assert(0 && "BrLastErrorGet not implemented.");
        abort();
    } else {
        return original_BrLastErrorGet(valuep);
    }
}

function_hook_state_t function_hook_state_BrLastErrorSet = HOOK_UNAVAILABLE;
static void(__cdecl*original_BrLastErrorSet)(br_error, void *) = (void(__cdecl*)(br_error, void *))0x004e7860;
CARM95_HOOK_FUNCTION(original_BrLastErrorSet, BrLastErrorSet)
void __cdecl BrLastErrorSet(br_error type, void *value) {
    LOG_TRACE("(%u, %p)", type, value);

    (void)type;
    (void)value;

    if (function_hook_state_BrLastErrorSet == HOOK_ENABLED) {
        assert(0 && "BrLastErrorSet not implemented.");
        abort();
    } else {
        original_BrLastErrorSet(type, value);
    }
}

