#include "brbhook.h"

#include "harness/trace.h"

#include "carm95_hooks.h"

#include "carm95_webserver.h"

#include <assert.h>

function_hook_state_t function_hook_state__BrBeginHook = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state__BrBeginHook)
void _BrBeginHook() {
    LOG_TRACE("()");


    if (function_hook_state__BrBeginHook == HOOK_ENABLED) {
        assert(0 && "_BrBeginHook not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}

function_hook_state_t function_hook_state__BrEndHook = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state__BrEndHook)
void _BrEndHook() {
    LOG_TRACE("()");


    if (function_hook_state__BrEndHook == HOOK_ENABLED) {
        assert(0 && "_BrEndHook not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}

