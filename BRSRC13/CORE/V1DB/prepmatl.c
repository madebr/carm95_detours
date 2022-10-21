#include "prepmatl.h"

#include "harness/trace.h"

#include "carm95_hooks.h"

#include "carm95_webserver.h"

#include <assert.h>

function_hook_state_t function_hook_state_BrMaterialUpdate = HOOK_UNAVAILABLE;
static void(__cdecl*original_BrMaterialUpdate)(br_material *, br_uint_16) = (void(__cdecl*)(br_material *, br_uint_16))0x004d9150;
CARM95_HOOK_FUNCTION(original_BrMaterialUpdate, BrMaterialUpdate)
void __cdecl BrMaterialUpdate(br_material *mat, br_uint_16 flags) {
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

    if (function_hook_state_BrMaterialUpdate == HOOK_ENABLED) {
        assert(0 && "BrMaterialUpdate not implemented.");
        abort();
    } else {
        original_BrMaterialUpdate(mat, flags);
    }
}

function_hook_state_t function_hook_state_BrMaterialClear = HOOK_UNAVAILABLE;
static void(__stdcall*original_BrMaterialClear)(br_material *) = (void(__stdcall*)(br_material *))0x004d9700;
CARM95_HOOK_FUNCTION(original_BrMaterialClear, BrMaterialClear)
void __stdcall BrMaterialClear(br_material *mat) {
    LOG_TRACE("(%p)", mat);

    (void)mat;

    if (function_hook_state_BrMaterialClear == HOOK_ENABLED) {
        assert(0 && "BrMaterialClear not implemented.");
        abort();
    } else {
        original_BrMaterialClear(mat);
    }
}

