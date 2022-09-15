#include "prepmatl.h"

#include "harness/trace.h"

#include "carm95_hooks.h"

#include <stdio.h>

static void(*original_BrMaterialUpdate)(br_material *, br_uint_16, ...) = (void(*)(br_material *, br_uint_16, ...))0x004d9150;
CARM95_HOOK_FUNCTION(original_BrMaterialUpdate, BrMaterialUpdate)
void BrMaterialUpdate(br_material *mat, br_uint_16 flags) {
    br_token_value tva[32];
    br_token_value *tvp;
    br_token t;
    br_int_32 c;
    LOG_TRACE("(%p, %u)", mat, flags);

    (void)mat;
    (void)flags;
    (void)tva;
    (void)tvp;
    (void)t;
    (void)c;

    original_BrMaterialUpdate(mat, flags);
}

static void(*original_BrMaterialClear)(br_material *, ...) = (void(*)(br_material *, ...))0x004d9700;
CARM95_HOOK_FUNCTION(original_BrMaterialClear, BrMaterialClear)
void BrMaterialClear(br_material *mat) {
    LOG_TRACE("(%p)", mat);

    (void)mat;

    original_BrMaterialClear(mat);
}

