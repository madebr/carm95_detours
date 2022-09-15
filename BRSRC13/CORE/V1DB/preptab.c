#include "preptab.h"

#include "harness/trace.h"

#include "carm95_hooks.h"

#include <stdio.h>

static void(*original_BrTableUpdate)(br_pixelmap *, br_uint_16, ...) = (void(*)(br_pixelmap *, br_uint_16, ...))0x004dda70;
CARM95_HOOK_FUNCTION(original_BrTableUpdate, BrTableUpdate)
void BrTableUpdate(br_pixelmap *table, br_uint_16 flags) {
    LOG_TRACE("(%p, %u)", table, flags);

    (void)table;
    (void)flags;

    original_BrTableUpdate(table, flags);
}

