#include "diag.h"

#include "harness/trace.h"

#include "carm95_hooks.h"

#include "carm95_webserver.h"

#include <assert.h>
#if 0
char(* hookvar__diag_scratch )[128];
#endif

function_hook_state_t function_hook_state_BrFailure = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_BrFailure)
void(__cdecl*BrFailure)(char *) = (void(__cdecl*)(char *))0x004df0b0;
void BrFailure_do_not_use(char *s) {
    va_list args;
    static char failure_header[10];
    LOG_TRACE("(\"%s\")", s);

    (void)s;
    (void)args;
    (void)failure_header;

    if (function_hook_state_BrFailure == HOOK_ENABLED) {
        assert(0 && "BrFailure_do_not_use not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}

function_hook_state_t function_hook_state_BrWarning = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_BrWarning)
void(__cdecl*BrWarning)(char *) = (void(__cdecl*)(char *))0x004df100;
void BrWarning_do_not_use(char *s) {
    va_list args;
    static char warning_header[10];
    LOG_TRACE("(\"%s\")", s);

    (void)s;
    (void)args;
    (void)warning_header;

    if (function_hook_state_BrWarning == HOOK_ENABLED) {
        assert(0 && "BrWarning_do_not_use not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}

function_hook_state_t function_hook_state_BrFatal = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_BrFatal)
void(__cdecl*BrFatal)(char *, int, char *) = (void(__cdecl*)(char *, int, char *))0x004df150;
void BrFatal_do_not_use(char *name, int line, char *s) {
    va_list args;
    int n;
    LOG_TRACE("(\"%s\", %d, \"%s\")", name, line, s);

    (void)name;
    (void)line;
    (void)s;
    (void)args;
    (void)n;

    if (function_hook_state_BrFatal == HOOK_ENABLED) {
        assert(0 && "BrFatal_do_not_use not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}

function_hook_state_t function_hook_state__BrAssert = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state__BrAssert)
static void(__cdecl*original__BrAssert)(char *, char *, unsigned int) = (void(__cdecl*)(char *, char *, unsigned int))0x004df1b0;
CARM95_HOOK_FUNCTION(original__BrAssert, _BrAssert)
void __cdecl _BrAssert(char *condition, char *file, unsigned int line) {
    LOG_TRACE("(\"%s\", \"%s\", %u)", condition, file, line);

    (void)condition;
    (void)file;
    (void)line;

    if (function_hook_state__BrAssert == HOOK_ENABLED) {
        assert(0 && "_BrAssert not implemented.");
        abort();
    } else {
        original__BrAssert(condition, file, line);
    }
}

function_hook_state_t function_hook_state__BrUAssert = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state__BrUAssert)
static void(__cdecl*original__BrUAssert)(char *, char *, unsigned int) = (void(__cdecl*)(char *, char *, unsigned int))0x004df200;
CARM95_HOOK_FUNCTION(original__BrUAssert, _BrUAssert)
void __cdecl _BrUAssert(char *condition, char *file, unsigned int line) {
    LOG_TRACE("(\"%s\", \"%s\", %u)", condition, file, line);

    (void)condition;
    (void)file;
    (void)line;

    if (function_hook_state__BrUAssert == HOOK_ENABLED) {
        assert(0 && "_BrUAssert not implemented.");
        abort();
    } else {
        original__BrUAssert(condition, file, line);
    }
}

