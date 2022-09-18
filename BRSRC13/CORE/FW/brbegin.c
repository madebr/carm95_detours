#include "brbegin.h"

#include "harness/trace.h"

#include "carm95_hooks.h"

br_boolean * hookvar_active  = (void*)0x005289b0;

static br_error(__stdcall*original_BrBegin)() = (br_error(__stdcall*)())0x004e6260;
CARM95_HOOK_FUNCTION(original_BrBegin, BrBegin)
br_error __stdcall BrBegin() {
    LOG_TRACE("()");


    return original_BrBegin();
}

static br_error(__cdecl*original_BrEnd)() = (br_error(__cdecl*)())0x004e6290;
CARM95_HOOK_FUNCTION(original_BrEnd, BrEnd)
br_error __cdecl BrEnd() {
    br_device *dev;
    LOG_TRACE("()");

    (void)dev;

    return original_BrEnd();
}

