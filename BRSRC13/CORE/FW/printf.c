#include "printf.h"

#include "harness/trace.h"

#include "carm95_hooks.h"

#include <stdio.h>

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

int BrLogPrintf_do_not_use(char *fmt) {
    int n;
    va_list args;
    LOG_TRACE("(\"%s\")", fmt);

    (void)fmt;
    (void)n;
    (void)args;

    NOT_IMPLEMENTED();
}

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

