#include "matsupt.h"

#include "harness/trace.h"

#include "carm95_hooks.h"

#include "carm95_webserver.h"

#include <assert.h>

function_hook_state_t function_hook_state_BrMaterialAllocate = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(BrMaterialAllocate, function_hook_state_BrMaterialAllocate)
static br_material *(__cdecl*original_BrMaterialAllocate)(char *) = (br_material *(__cdecl*)(char *))0x004d90e0;
CARM95_HOOK_FUNCTION(original_BrMaterialAllocate, BrMaterialAllocate)
br_material* __cdecl BrMaterialAllocate(char *name) {
    br_material *m;
    LOG_TRACE("(\"%s\")", name);

    (void)name;
    (void)m;

    if (function_hook_state_BrMaterialAllocate == HOOK_ENABLED) {
        assert(0 && "BrMaterialAllocate not implemented.");
        abort();
    } else {
        return original_BrMaterialAllocate(name);
    }
}

function_hook_state_t function_hook_state_BrMaterialFree = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(BrMaterialFree, function_hook_state_BrMaterialFree)
static void(__cdecl*original_BrMaterialFree)(br_material *) = (void(__cdecl*)(br_material *))0x004d9140;
CARM95_HOOK_FUNCTION(original_BrMaterialFree, BrMaterialFree)
void __cdecl BrMaterialFree(br_material *m) {
    LOG_TRACE("(%p)", m);

    (void)m;

    if (function_hook_state_BrMaterialFree == HOOK_ENABLED) {
        assert(0 && "BrMaterialFree not implemented.");
        abort();
    } else {
        original_BrMaterialFree(m);
    }
}

