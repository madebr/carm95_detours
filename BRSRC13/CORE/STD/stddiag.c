#include "stddiag.h"

#include "harness/trace.h"

#include "carm95_hooks.h"

br_diaghandler * hookvar_BrStdioDiagHandler  = (void*)0x00530168;
br_diaghandler ** hookvar__BrDefaultDiagHandler  = (void*)0x00530174;

static void(__cdecl*original_BrStdioWarning)(char *) = (void(__cdecl*)(char *))0x00503090;
CARM95_HOOK_FUNCTION(original_BrStdioWarning, BrStdioWarning)
void __cdecl BrStdioWarning(char *message) {
    LOG_TRACE("(\"%s\")", message);

    (void)message;

    original_BrStdioWarning(message);
}

static void(__cdecl*original_BrStdioFailure)(char *) = (void(__cdecl*)(char *))0x005030d0;
CARM95_HOOK_FUNCTION(original_BrStdioFailure, BrStdioFailure)
void __cdecl BrStdioFailure(char *message) {
    LOG_TRACE("(\"%s\")", message);

    (void)message;

    original_BrStdioFailure(message);
}

