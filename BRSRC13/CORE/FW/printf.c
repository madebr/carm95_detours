#include "printf.h"

#include "harness/trace.h"

#include "carm95_hooks.h"


br_int_32(__cdecl*BrSprintf)(char *, char *) = (br_int_32(__cdecl*)(char *, char *))0x004e6300;
br_int_32 BrSprintf_do_not_use(char *buf, char *fmt) {
    int n;
    va_list args;
    LOG_TRACE("(\"%s\", \"%s\")", buf, fmt);

    (void)buf;
    (void)fmt;
    (void)n;
    (void)args;

    NOT_IMPLEMENTED();
}

br_int_32(__cdecl*BrSprintfN)(char *, br_size_t, char *) = (br_int_32(__cdecl*)(char *, br_size_t, char *))0x004e6320;
br_int_32 BrSprintfN_do_not_use(char *buf, br_size_t buf_size, char *fmt) {
    int n;
    va_list args;
    LOG_TRACE("(\"%s\", %u, \"%s\")", buf, buf_size, fmt);

    (void)buf;
    (void)buf_size;
    (void)fmt;
    (void)n;
    (void)args;

    NOT_IMPLEMENTED();
}

int(__cdecl*BrLogPrintf)(char *) = (int(__cdecl*)(char *))0x004e6340;
int BrLogPrintf_do_not_use(char *fmt) {
    int n;
    va_list args;
    LOG_TRACE("(\"%s\")", fmt);

    (void)fmt;
    (void)n;
    (void)args;

    NOT_IMPLEMENTED();
}

br_int_32(__cdecl*BrSScanf)(char *, char *) = (br_int_32(__cdecl*)(char *, char *))0x004e6370;
br_int_32 BrSScanf_do_not_use(char *str, char *fmt) {
    int n;
    va_list args;
    LOG_TRACE("(\"%s\", \"%s\")", str, fmt);

    (void)str;
    (void)fmt;
    (void)n;
    (void)args;

    NOT_IMPLEMENTED();
}

