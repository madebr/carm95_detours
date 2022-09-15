#include "brbegin.h"

#include "harness/trace.h"

#include "carm95_hooks.h"

#include <stdio.h>
br_boolean * hookvar_active  = (void*)0x005289b0;

static br_error(*original_BrBegin)() = (br_error(*)())0x004e6260;
CARM95_HOOK_FUNCTION(original_BrBegin, BrBegin)
br_error BrBegin() {
    LOG_TRACE("()");


    return original_BrBegin();
}

static br_error(*original_BrEnd)() = (br_error(*)())0x004e6290;
CARM95_HOOK_FUNCTION(original_BrEnd, BrEnd)
br_error BrEnd() {
    br_device *dev;
    LOG_TRACE("()");

    (void)dev;

    return original_BrEnd();
}

