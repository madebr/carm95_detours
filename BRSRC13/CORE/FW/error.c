#include "error.h"

#include "harness/trace.h"

#include "carm95_hooks.h"


static br_error(__cdecl*original_BrLastErrorGet)(void **) = (br_error(__cdecl*)(void **))0x004e7850;
CARM95_HOOK_FUNCTION(original_BrLastErrorGet, BrLastErrorGet)
br_error __cdecl BrLastErrorGet(void **valuep) {
    LOG_TRACE("(%p)", valuep);

    (void)valuep;

    return original_BrLastErrorGet(valuep);
}

static void(__cdecl*original_BrLastErrorSet)(br_error, void *) = (void(__cdecl*)(br_error, void *))0x004e7860;
CARM95_HOOK_FUNCTION(original_BrLastErrorSet, BrLastErrorSet)
void __cdecl BrLastErrorSet(br_error type, void *value) {
    LOG_TRACE("(%u, %p)", type, value);

    (void)type;
    (void)value;

    original_BrLastErrorSet(type, value);
}

