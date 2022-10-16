#include "hstsetup.h"

#include "harness/trace.h"

#include "carm95_hooks.h"

char *(* hookvar_namePointers_BRHOST1 )[50] = (void*)0x0052ee10;
br_uint_16(* hookvar_nameOrdinals_BRHOST1 )[50] = (void*)0x0052eed8;
void *(* hookvar_functionPointers_BRHOST1 )[50] = (void*)0x0052ef40;
br_image * hookvar_Image_BRHOST1  = (void*)0x0052f008;
host_info * hookvar_hostInfo  = (void*)0x0052f048;

static void(__cdecl*original_HostBegin)() = (void(__cdecl*)())0x00501320;
CARM95_HOOK_FUNCTION(original_HostBegin, HostBegin)
void __cdecl HostBegin() {
    LOG_TRACE("()");


    original_HostBegin();
}

static void(__stdcall*original_HostEnd)() = (void(__stdcall*)())0x00501340;
CARM95_HOOK_FUNCTION(original_HostEnd, HostEnd)
void __stdcall HostEnd() {
    LOG_TRACE("()");


    original_HostEnd();
}

static br_error(__cdecl*original_HostInfo)(host_info *, br_size_t) = (br_error(__cdecl*)(host_info *, br_size_t))0x00501360;
CARM95_HOOK_FUNCTION(original_HostInfo, HostInfo)
br_error __cdecl HostInfo(host_info *buffer, br_size_t buffersize) {
    br_int_32 features;
    LOG_TRACE("(%p, %u)", buffer, buffersize);

    (void)buffer;
    (void)buffersize;
    (void)features;

    return original_HostInfo(buffer, buffersize);
}

