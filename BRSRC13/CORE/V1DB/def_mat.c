#include "def_mat.h"

#include "harness/trace.h"

#include "carm95_hooks.h"


static br_material *(__cdecl*original_SetupDefaultMaterial)() = (br_material *(__cdecl*)())0x004de450;
CARM95_HOOK_FUNCTION(original_SetupDefaultMaterial, SetupDefaultMaterial)
br_material* __cdecl SetupDefaultMaterial() {
    static br_material *default_mat;
    LOG_TRACE("()");

    (void)default_mat;

    return original_SetupDefaultMaterial();
}
