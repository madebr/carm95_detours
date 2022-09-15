#include "error.h"

#include "harness/trace.h"

#include "carm95_hooks.h"

#include <stdio.h>

static br_error(*original_BrLastErrorGet)(void **, ...) = (br_error(*)(void **, ...))0x004e7850;
CARM95_HOOK_FUNCTION(original_BrLastErrorGet, BrLastErrorGet)
br_error BrLastErrorGet(void **valuep) {
    LOG_TRACE("(%p)", valuep);

    (void)valuep;

    return original_BrLastErrorGet(valuep);
}

static void(*original_BrLastErrorSet)(br_error, void *, ...) = (void(*)(br_error, void *, ...))0x004e7860;
CARM95_HOOK_FUNCTION(original_BrLastErrorSet, BrLastErrorSet)
void BrLastErrorSet(br_error type, void *value) {
    LOG_TRACE("(%u, %p)", type, value);

    (void)type;
    (void)value;

    original_BrLastErrorSet(type, value);
}

