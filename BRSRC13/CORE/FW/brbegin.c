#include "brbegin.h"

#include "harness/trace.h"

#include "carm95_hooks.h"

#include "carm95_webserver.h"

#include <assert.h>
br_boolean * hookvar_active  = (void*)0x005289b0;

function_hook_state_t function_hook_state_BrBegin = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_BrBegin)
static br_error(__cdecl*original_BrBegin)() = (br_error(__cdecl*)())0x004e6260;
CARM95_HOOK_FUNCTION(original_BrBegin, BrBegin)
br_error __cdecl BrBegin() {
    LOG_TRACE("()");


    if (function_hook_state_BrBegin == HOOK_ENABLED) {
        assert(0 && "BrBegin not implemented.");
        abort();
    } else {
        return original_BrBegin();
    }
}

function_hook_state_t function_hook_state_BrEnd = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_BrEnd)
static br_error(__cdecl*original_BrEnd)() = (br_error(__cdecl*)())0x004e6290;
CARM95_HOOK_FUNCTION(original_BrEnd, BrEnd)
br_error __cdecl BrEnd() {
    br_device *dev;
    LOG_TRACE("()");

    (void)dev;

    if (function_hook_state_BrEnd == HOOK_ENABLED) {
        assert(0 && "BrEnd not implemented.");
        abort();
    } else {
        return original_BrEnd();
    }
}

