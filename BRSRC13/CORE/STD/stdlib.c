#include "stdlib.h"

#include "harness/trace.h"

#include "carm95_hooks.h"


static int(__cdecl*original_BrMemCmp)(void *, void *, size_t) = (int(__cdecl*)(void *, void *, size_t))0x004d5960;
CARM95_HOOK_FUNCTION(original_BrMemCmp, BrMemCmp)
int __cdecl BrMemCmp(void *s1, void *s2, size_t n) {
    LOG_TRACE("(%p, %p, %u)", s1, s2, n);

    (void)s1;
    (void)s2;
    (void)n;

    return original_BrMemCmp(s1, s2, n);
}

static void *(__cdecl*original_BrMemCpy)(void *, void *, size_t) = (void *(__cdecl*)(void *, void *, size_t))0x004d5980;
CARM95_HOOK_FUNCTION(original_BrMemCpy, BrMemCpy)
void* __cdecl BrMemCpy(void *s1, void *s2, size_t n) {
    LOG_TRACE("(%p, %p, %u)", s1, s2, n);

    (void)s1;
    (void)s2;
    (void)n;

    return original_BrMemCpy(s1, s2, n);
}

static void *(__cdecl*original_BrMemSet)(void *, int, size_t) = (void *(__cdecl*)(void *, int, size_t))0x004d59b0;
CARM95_HOOK_FUNCTION(original_BrMemSet, BrMemSet)
void* __cdecl BrMemSet(void *s, int c, size_t n) {
    LOG_TRACE("(%p, %d, %u)", s, c, n);

    (void)s;
    (void)c;
    (void)n;

    return original_BrMemSet(s, c, n);
}

static char *(__cdecl*original_BrStrCat)(char *, char *) = (char *(__cdecl*)(char *, char *))0x004d59f0;
CARM95_HOOK_FUNCTION(original_BrStrCat, BrStrCat)
char* __cdecl BrStrCat(char *s1, char *s2) {
    LOG_TRACE("(\"%s\", \"%s\")", s1, s2);

    (void)s1;
    (void)s2;

    return original_BrStrCat(s1, s2);
}

static int(__cdecl*original_BrStrCmp)(char *, char *) = (int(__cdecl*)(char *, char *))0x004d5a30;
CARM95_HOOK_FUNCTION(original_BrStrCmp, BrStrCmp)
int __cdecl BrStrCmp(char *s1, char *s2) {
    LOG_TRACE("(\"%s\", \"%s\")", s1, s2);

    (void)s1;
    (void)s2;

    return original_BrStrCmp(s1, s2);
}

int BrStrICmp(char *s1, char *s2) {
    LOG_TRACE("(\"%s\", \"%s\")", s1, s2);

    (void)s1;
    (void)s2;

    NOT_IMPLEMENTED();
}

static char *(__cdecl*original_BrStrCpy)(char *, char *) = (char *(__cdecl*)(char *, char *))0x004d5a80;
CARM95_HOOK_FUNCTION(original_BrStrCpy, BrStrCpy)
char* __cdecl BrStrCpy(char *s1, char *s2) {
    LOG_TRACE("(\"%s\", \"%s\")", s1, s2);

    (void)s1;
    (void)s2;

    return original_BrStrCpy(s1, s2);
}

static br_size_t(__cdecl*original_BrStrLen)(char *) = (br_size_t(__cdecl*)(char *))0x004d5ab0;
CARM95_HOOK_FUNCTION(original_BrStrLen, BrStrLen)
br_size_t __cdecl BrStrLen(char *s) {
    LOG_TRACE("(\"%s\")", s);

    (void)s;

    return original_BrStrLen(s);
}

static int(__cdecl*original_BrStrNCmp)(char *, char *, size_t) = (int(__cdecl*)(char *, char *, size_t))0x004d5ad0;
CARM95_HOOK_FUNCTION(original_BrStrNCmp, BrStrNCmp)
int __cdecl BrStrNCmp(char *s1, char *s2, size_t n) {
    LOG_TRACE("(\"%s\", \"%s\", %u)", s1, s2, n);

    (void)s1;
    (void)s2;
    (void)n;

    return original_BrStrNCmp(s1, s2, n);
}

static int(__cdecl*original_BrStrNICmp)(char *, char *, size_t) = (int(__cdecl*)(char *, char *, size_t))0x004d5af0;
CARM95_HOOK_FUNCTION(original_BrStrNICmp, BrStrNICmp)
int __cdecl BrStrNICmp(char *s1, char *s2, size_t n) {
    LOG_TRACE("(\"%s\", \"%s\", %u)", s1, s2, n);

    (void)s1;
    (void)s2;
    (void)n;

    return original_BrStrNICmp(s1, s2, n);
}

static char *(__cdecl*original_BrStrNCpy)(char *, char *, size_t) = (char *(__cdecl*)(char *, char *, size_t))0x004d5b10;
CARM95_HOOK_FUNCTION(original_BrStrNCpy, BrStrNCpy)
char* __cdecl BrStrNCpy(char *s1, char *s2, size_t n) {
    LOG_TRACE("(\"%s\", \"%s\", %u)", s1, s2, n);

    (void)s1;
    (void)s2;
    (void)n;

    return original_BrStrNCpy(s1, s2, n);
}

static char *(__cdecl*original_BrStrRChr)(char *, char) = (char *(__cdecl*)(char *, char))0x004d5b30;
CARM95_HOOK_FUNCTION(original_BrStrRChr, BrStrRChr)
char* __cdecl BrStrRChr(char *s1, char c) {
    LOG_TRACE("(\"%s\", '%c')", s1, c);

    (void)s1;
    (void)c;

    return original_BrStrRChr(s1, c);
}

void(__cdecl*BrAbort)() = (void(__cdecl*)())0x004d5b50;
void BrAbort_do_not_use() {
    LOG_TRACE("()");


    NOT_IMPLEMENTED();
}

static char *(__cdecl*original_BrGetEnv)(char *) = (char *(__cdecl*)(char *))0x004d5b60;
CARM95_HOOK_FUNCTION(original_BrGetEnv, BrGetEnv)
char* __cdecl BrGetEnv(char *name) {
    LOG_TRACE("(\"%s\")", name);

    (void)name;

    return original_BrGetEnv(name);
}

static float(__cdecl*original_BrStrToF)(char *, char **) = (float(__cdecl*)(char *, char **))0x004d5b70;
CARM95_HOOK_FUNCTION(original_BrStrToF, BrStrToF)
float __cdecl BrStrToF(char *nptr, char **endptr) {
    LOG_TRACE("(\"%s\", %p)", nptr, endptr);

    (void)nptr;
    (void)endptr;

    return original_BrStrToF(nptr, endptr);
}

static double(__cdecl*original_BrStrToD)(char *, char **) = (double(__cdecl*)(char *, char **))0x004d5b90;
CARM95_HOOK_FUNCTION(original_BrStrToD, BrStrToD)
double __cdecl BrStrToD(char *nptr, char **endptr) {
    LOG_TRACE("(\"%s\", %p)", nptr, endptr);

    (void)nptr;
    (void)endptr;

    return original_BrStrToD(nptr, endptr);
}

static long(__cdecl*original_BrStrToL)(char *, char **, int) = (long(__cdecl*)(char *, char **, int))0x004d5bb0;
CARM95_HOOK_FUNCTION(original_BrStrToL, BrStrToL)
long __cdecl BrStrToL(char *nptr, char **endptr, int base) {
    LOG_TRACE("(\"%s\", %p, %d)", nptr, endptr, base);

    (void)nptr;
    (void)endptr;
    (void)base;

    return original_BrStrToL(nptr, endptr, base);
}

static unsigned long(__cdecl*original_BrStrToUL)(char *, char **, int) = (unsigned long(__cdecl*)(char *, char **, int))0x004d5bd0;
CARM95_HOOK_FUNCTION(original_BrStrToUL, BrStrToUL)
unsigned long __cdecl BrStrToUL(char *nptr, char **endptr, int base) {
    LOG_TRACE("(\"%s\", %p, %d)", nptr, endptr, base);

    (void)nptr;
    (void)endptr;
    (void)base;

    return original_BrStrToUL(nptr, endptr, base);
}

static br_boolean(__cdecl*original_BrIsAlpha)(int) = (br_boolean(__cdecl*)(int))0x004d5bf0;
CARM95_HOOK_FUNCTION(original_BrIsAlpha, BrIsAlpha)
br_boolean __cdecl BrIsAlpha(int c) {
    LOG_TRACE("(%d)", c);

    (void)c;

    return original_BrIsAlpha(c);
}

static br_boolean(__cdecl*original_BrIsDigit)(int) = (br_boolean(__cdecl*)(int))0x004d5c30;
CARM95_HOOK_FUNCTION(original_BrIsDigit, BrIsDigit)
br_boolean __cdecl BrIsDigit(int c) {
    LOG_TRACE("(%d)", c);

    (void)c;

    return original_BrIsDigit(c);
}

static br_boolean(__cdecl*original_BrIsSpace)(int) = (br_boolean(__cdecl*)(int))0x004d5c60;
CARM95_HOOK_FUNCTION(original_BrIsSpace, BrIsSpace)
br_boolean __cdecl BrIsSpace(int c) {
    LOG_TRACE("(%d)", c);

    (void)c;

    return original_BrIsSpace(c);
}

static br_boolean(__cdecl*original_BrIsPrint)(int) = (br_boolean(__cdecl*)(int))0x004d5c90;
CARM95_HOOK_FUNCTION(original_BrIsPrint, BrIsPrint)
br_boolean __cdecl BrIsPrint(int c) {
    LOG_TRACE("(%d)", c);

    (void)c;

    return original_BrIsPrint(c);
}

static br_int_32(__cdecl*original_BrVSprintf)(char *, char *, char **) = (br_int_32(__cdecl*)(char *, char *, char **))0x004d5cd0;
CARM95_HOOK_FUNCTION(original_BrVSprintf, BrVSprintf)
br_int_32 __cdecl BrVSprintf(char *buf, char *fmt, char **args) {
    LOG_TRACE("(\"%s\", \"%s\", %p)", buf, fmt, args);

    (void)buf;
    (void)fmt;
    (void)args;

    return original_BrVSprintf(buf, fmt, args);
}

static br_int_32(__cdecl*original_BrVSprintfN)(char *, br_size_t, char *, char **) = (br_int_32(__cdecl*)(char *, br_size_t, char *, char **))0x004d5cf0;
CARM95_HOOK_FUNCTION(original_BrVSprintfN, BrVSprintfN)
br_int_32 __cdecl BrVSprintfN(char *buf, br_size_t buf_size, char *fmt, char **args) {
    unsigned int n;
    char tmp[512];
    LOG_TRACE("(\"%s\", %u, \"%s\", %p)", buf, buf_size, fmt, args);

    (void)buf;
    (void)buf_size;
    (void)fmt;
    (void)args;
    (void)n;
    (void)tmp;

    return original_BrVSprintfN(buf, buf_size, fmt, args);
}

static br_int_32(__cdecl*original_BrVSScanf)(char *, char *, char **) = (br_int_32(__cdecl*)(char *, char *, char **))0x004d5d50;
CARM95_HOOK_FUNCTION(original_BrVSScanf, BrVSScanf)
br_int_32 __cdecl BrVSScanf(char *buf, char *fmt, char **args) {
    LOG_TRACE("(\"%s\", \"%s\", %p)", buf, fmt, args);

    (void)buf;
    (void)fmt;
    (void)args;

    return original_BrVSScanf(buf, fmt, args);
}

