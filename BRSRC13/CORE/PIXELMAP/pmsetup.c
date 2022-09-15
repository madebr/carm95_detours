#include "pmsetup.h"

#include "harness/trace.h"

#include "carm95_hooks.h"

#include <stdio.h>
char *(* hookvar_namePointers_BRPMAP1 )[77] = (void*)0x00522d60;
br_uint_16(* hookvar_nameOrdinals_BRPMAP1 )[77] = (void*)0x00522e98;
void *(* hookvar_functionPointers_BRPMAP1 )[77] = (void*)0x00522f38;
br_image * hookvar_Image_BRPMAP1  = (void*)0x00523070;
struct br_pixelmap_state * hookvar__pixelmap  = (void*)0x005520f0;
 // Suffix added to avoid duplicate symbol
#if 0
br_resource_class(* hookvar_resourceClasses__pmsetup )[2];
#endif

static void(*original_BrPixelmapBegin)() = (void(*)())0x004d03f0;
CARM95_HOOK_FUNCTION(original_BrPixelmapBegin, BrPixelmapBegin)
void BrPixelmapBegin() {
    int i;
    LOG_TRACE("()");

    (void)i;

    original_BrPixelmapBegin();
}

static void(*original_BrPixelmapEnd)() = (void(*)())0x004d0440;
CARM95_HOOK_FUNCTION(original_BrPixelmapEnd, BrPixelmapEnd)
void BrPixelmapEnd() {
    LOG_TRACE("()");


    original_BrPixelmapEnd();
}

