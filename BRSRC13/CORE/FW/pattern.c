#include "pattern.h"

#include "harness/trace.h"

#include "carm95_hooks.h"

#include "carm95_webserver.h"

#include <assert.h>

function_hook_state_t function_hook_state_BrNamePatternMatch = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(BrNamePatternMatch, function_hook_state_BrNamePatternMatch)
static br_boolean(__cdecl*original_BrNamePatternMatch)(char *, char *) = (br_boolean(__cdecl*)(char *, char *))0x004e5cf0;
CARM95_HOOK_FUNCTION(original_BrNamePatternMatch, BrNamePatternMatch)
br_boolean __cdecl BrNamePatternMatch(char *p, char *s) {
    char *cp;
    LOG_TRACE("(\"%s\", \"%s\")", p, s);

    (void)p;
    (void)s;
    (void)cp;

    if (function_hook_state_BrNamePatternMatch == HOOK_ENABLED) {
        assert(0 && "BrNamePatternMatch not implemented.");
        abort();
    } else {
        return original_BrNamePatternMatch(p, s);
    }
}

