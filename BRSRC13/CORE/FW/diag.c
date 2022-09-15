#include "diag.h"

#include "harness/trace.h"

#include "carm95_hooks.h"

#include <stdio.h>
#if 0
char(* hookvar__diag_scratch )[128];
#endif

void BrFailure_do_not_use(char *s) {
    va_list args;
    static char failure_header[10];
    LOG_TRACE("(\"%s\")", s);

    (void)s;
    (void)args;
    (void)failure_header;

    NOT_IMPLEMENTED();
}

void BrWarning_do_not_use(char *s) {
    va_list args;
    static char warning_header[10];
    LOG_TRACE("(\"%s\")", s);

    (void)s;
    (void)args;
    (void)warning_header;

    NOT_IMPLEMENTED();
}

void BrFatal_do_not_use(char *name, int line, char *s) {
    va_list args;
    int n;
    LOG_TRACE("(\"%s\", %d, \"%s\")", name, line, s);

    (void)name;
    (void)line;
    (void)s;
    (void)args;
    (void)n;

    NOT_IMPLEMENTED();
}

static void(*original__BrAssert)(char *, char *, unsigned int, ...) = (void(*)(char *, char *, unsigned int, ...))0x004df1b0;
CARM95_HOOK_FUNCTION(original__BrAssert, _BrAssert)
void _BrAssert(char *condition, char *file, unsigned int line) {
    LOG_TRACE("(\"%s\", \"%s\", %u)", condition, file, line);

    (void)condition;
    (void)file;
    (void)line;

    original__BrAssert(condition, file, line);
}

static void(*original__BrUAssert)(char *, char *, unsigned int, ...) = (void(*)(char *, char *, unsigned int, ...))0x004df200;
CARM95_HOOK_FUNCTION(original__BrUAssert, _BrUAssert)
void _BrUAssert(char *condition, char *file, unsigned int line) {
    LOG_TRACE("(\"%s\", \"%s\", %u)", condition, file, line);

    (void)condition;
    (void)file;
    (void)line;

    original__BrUAssert(condition, file, line);
}

