#include "pmsetup.h"

#include "harness/trace.h"

#include "carm95_hooks.h"

#include "carm95_webserver.h"

#include <assert.h>
char *(* hookvar_namePointers_BRPMAP1 )[77] = (void*)0x00522d60;
br_uint_16(* hookvar_nameOrdinals_BRPMAP1 )[77] = (void*)0x00522e98;
void *(* hookvar_functionPointers_BRPMAP1 )[77] = (void*)0x00522f38;
br_image * hookvar_Image_BRPMAP1  = (void*)0x00523070;
struct br_pixelmap_state * hookvar__pixelmap  = (void*)0x005520f0;
 // Suffix added to avoid duplicate symbol
#if 0
br_resource_class(* hookvar_resourceClasses__pmsetup )[2];
#endif

function_hook_state_t function_hook_state_BrPixelmapBegin = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(BrPixelmapBegin, function_hook_state_BrPixelmapBegin)
static void(__cdecl*original_BrPixelmapBegin)() = (void(__cdecl*)())0x004d03f0;
CARM95_HOOK_FUNCTION(original_BrPixelmapBegin, BrPixelmapBegin)
void __cdecl BrPixelmapBegin() {
    int i;
    LOG_TRACE("()");

    (void)i;

    if (function_hook_state_BrPixelmapBegin == HOOK_ENABLED) {
        assert(0 && "BrPixelmapBegin not implemented.");
        abort();
    } else {
        original_BrPixelmapBegin();
    }
}

function_hook_state_t function_hook_state_BrPixelmapEnd = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(BrPixelmapEnd, function_hook_state_BrPixelmapEnd)
static void(__cdecl*original_BrPixelmapEnd)() = (void(__cdecl*)())0x004d0440;
CARM95_HOOK_FUNCTION(original_BrPixelmapEnd, BrPixelmapEnd)
void __cdecl BrPixelmapEnd() {
    LOG_TRACE("()");


    if (function_hook_state_BrPixelmapEnd == HOOK_ENABLED) {
        assert(0 && "BrPixelmapEnd not implemented.");
        abort();
    } else {
        original_BrPixelmapEnd();
    }
}

