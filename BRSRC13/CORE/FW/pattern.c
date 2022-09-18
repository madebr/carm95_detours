#include "pattern.h"

#include "harness/trace.h"

#include "carm95_hooks.h"


static br_boolean(__cdecl*original_BrNamePatternMatch)(char *, char *) = (br_boolean(__cdecl*)(char *, char *))0x004e5cf0;
CARM95_HOOK_FUNCTION(original_BrNamePatternMatch, BrNamePatternMatch)
br_boolean __cdecl BrNamePatternMatch(char *p, char *s) {
    char *cp;
    LOG_TRACE("(\"%s\", \"%s\")", p, s);

    (void)p;
    (void)s;
    (void)cp;

    return original_BrNamePatternMatch(p, s);
}

