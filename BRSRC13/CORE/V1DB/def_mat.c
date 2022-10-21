#include "def_mat.h"

#include "harness/trace.h"

#include "carm95_hooks.h"

#include "carm95_webserver.h"

#include <assert.h>

function_hook_state_t function_hook_state_SetupDefaultMaterial = HOOK_UNAVAILABLE;
static br_material *(__cdecl*original_SetupDefaultMaterial)() = (br_material *(__cdecl*)())0x004de450;
CARM95_HOOK_FUNCTION(original_SetupDefaultMaterial, SetupDefaultMaterial)
br_material* __cdecl SetupDefaultMaterial() {
    static br_material *default_mat;
    LOG_TRACE("()");

    (void)default_mat;

    if (function_hook_state_SetupDefaultMaterial == HOOK_ENABLED) {
        assert(0 && "SetupDefaultMaterial not implemented.");
        abort();
    } else {
        return original_SetupDefaultMaterial();
    }
}

