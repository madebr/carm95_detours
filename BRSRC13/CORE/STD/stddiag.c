#include "stddiag.h"

#include "harness/trace.h"

#include "carm95_hooks.h"

#include "carm95_webserver.h"

#include <assert.h>
br_diaghandler * hookvar_BrStdioDiagHandler  = (void*)0x00530168;
br_diaghandler ** hookvar__BrDefaultDiagHandler  = (void*)0x00530174;

function_hook_state_t function_hook_state_BrStdioWarning = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(BrStdioWarning, function_hook_state_BrStdioWarning)
static void(__cdecl*original_BrStdioWarning)(char *) = (void(__cdecl*)(char *))0x00503090;
CARM95_HOOK_FUNCTION(original_BrStdioWarning, BrStdioWarning)
void __cdecl BrStdioWarning(char *message) {
    LOG_TRACE("(\"%s\")", message);

    (void)message;

    if (function_hook_state_BrStdioWarning == HOOK_ENABLED) {
        assert(0 && "BrStdioWarning not implemented.");
        abort();
    } else {
        original_BrStdioWarning(message);
    }
}

function_hook_state_t function_hook_state_BrStdioFailure = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(BrStdioFailure, function_hook_state_BrStdioFailure)
static void(__cdecl*original_BrStdioFailure)(char *) = (void(__cdecl*)(char *))0x005030d0;
CARM95_HOOK_FUNCTION(original_BrStdioFailure, BrStdioFailure)
void __cdecl BrStdioFailure(char *message) {
    LOG_TRACE("(\"%s\")", message);

    (void)message;

    if (function_hook_state_BrStdioFailure == HOOK_ENABLED) {
        assert(0 && "BrStdioFailure not implemented.");
        abort();
    } else {
        original_BrStdioFailure(message);
    }
}

