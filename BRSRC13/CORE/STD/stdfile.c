#include "stdfile.h"

#include "harness/trace.h"

#include "carm95_hooks.h"

#include <stdio.h>
br_filesystem * hookvar_BrStdioFilesystem  = (void*)0x005300e0;
br_filesystem ** hookvar__BrDefaultFilesystem  = (void*)0x00530114;

br_uint_32 BrStdioAttributes() {
    LOG_TRACE("()");


    NOT_IMPLEMENTED();
}

static void *(__cdecl*original_BrStdioOpenRead)(char *, br_size_t, br_mode_test_cbfn *, int *) = (void *(__cdecl*)(char *, br_size_t, br_mode_test_cbfn *, int *))0x00502cf0;
CARM95_HOOK_FUNCTION(original_BrStdioOpenRead, BrStdioOpenRead)
void* __cdecl BrStdioOpenRead(char *name, br_size_t n_magics, br_mode_test_cbfn *identify, int *mode_result) {
    FILE *fh;
    char *br_path;
    char config_path[512];
    char try_name[512];
    char *cp;
    br_uint_8 magics[16];
    int open_mode;
    LOG_TRACE("(\"%s\", %u, %p, %p)", name, n_magics, identify, mode_result);

    (void)name;
    (void)n_magics;
    (void)identify;
    (void)mode_result;
    (void)fh;
    (void)br_path;
    (void)config_path;
    (void)try_name;
    (void)cp;
    (void)magics;
    (void)open_mode;

    return original_BrStdioOpenRead(name, n_magics, identify, mode_result);
}

static void *(__cdecl*original_BrStdioOpenWrite)(char *, int) = (void *(__cdecl*)(char *, int))0x00502f20;
CARM95_HOOK_FUNCTION(original_BrStdioOpenWrite, BrStdioOpenWrite)
void* __cdecl BrStdioOpenWrite(char *name, int mode) {
    FILE *fh;
    LOG_TRACE("(\"%s\", %d)", name, mode);

    (void)name;
    (void)mode;
    (void)fh;

    return original_BrStdioOpenWrite(name, mode);
}

static void(__cdecl*original_BrStdioClose)(void *) = (void(__cdecl*)(void *))0x00502f50;
CARM95_HOOK_FUNCTION(original_BrStdioClose, BrStdioClose)
void __cdecl BrStdioClose(void *f) {
    LOG_TRACE("(%p)", f);

    (void)f;

    original_BrStdioClose(f);
}

static int(__cdecl*original_BrStdioEof)(void *) = (int(__cdecl*)(void *))0x00502f60;
CARM95_HOOK_FUNCTION(original_BrStdioEof, BrStdioEof)
int __cdecl BrStdioEof(void *f) {
    LOG_TRACE("(%p)", f);

    (void)f;

    return original_BrStdioEof(f);
}

static int(__cdecl*original_BrStdioGetChar)(void *) = (int(__cdecl*)(void *))0x00502f70;
CARM95_HOOK_FUNCTION(original_BrStdioGetChar, BrStdioGetChar)
int __cdecl BrStdioGetChar(void *f) {
    LOG_TRACE("(%p)", f);

    (void)f;

    return original_BrStdioGetChar(f);
}

static void(__cdecl*original_BrStdioPutChar)(int, void *) = (void(__cdecl*)(int, void *))0x00502fa0;
CARM95_HOOK_FUNCTION(original_BrStdioPutChar, BrStdioPutChar)
void __cdecl BrStdioPutChar(int c, void *f) {
    LOG_TRACE("(%d, %p)", c, f);

    (void)c;
    (void)f;

    original_BrStdioPutChar(c, f);
}

static br_size_t(__cdecl*original_BrStdioRead)(void *, br_size_t, unsigned int, void *) = (br_size_t(__cdecl*)(void *, br_size_t, unsigned int, void *))0x00502fc0;
CARM95_HOOK_FUNCTION(original_BrStdioRead, BrStdioRead)
br_size_t __cdecl BrStdioRead(void *buf, br_size_t size, unsigned int n, void *f) {
    LOG_TRACE("(%p, %u, %u, %p)", buf, size, n, f);

    (void)buf;
    (void)size;
    (void)n;
    (void)f;

    return original_BrStdioRead(buf, size, n, f);
}

static br_size_t(__cdecl*original_BrStdioWrite)(void *, br_size_t, unsigned int, void *) = (br_size_t(__cdecl*)(void *, br_size_t, unsigned int, void *))0x00502fe0;
CARM95_HOOK_FUNCTION(original_BrStdioWrite, BrStdioWrite)
br_size_t __cdecl BrStdioWrite(void *buf, br_size_t size, unsigned int n, void *f) {
    LOG_TRACE("(%p, %u, %u, %p)", buf, size, n, f);

    (void)buf;
    (void)size;
    (void)n;
    (void)f;

    return original_BrStdioWrite(buf, size, n, f);
}

static br_size_t(__cdecl*original_BrStdioGetLine)(char *, br_size_t, void *) = (br_size_t(__cdecl*)(char *, br_size_t, void *))0x00503000;
CARM95_HOOK_FUNCTION(original_BrStdioGetLine, BrStdioGetLine)
br_size_t __cdecl BrStdioGetLine(char *buf, br_size_t buf_len, void *f) {
    br_size_t l;
    LOG_TRACE("(\"%s\", %u, %p)", buf, buf_len, f);

    (void)buf;
    (void)buf_len;
    (void)f;
    (void)l;

    return original_BrStdioGetLine(buf, buf_len, f);
}

static void(__cdecl*original_BrStdioPutLine)(char *, void *) = (void(__cdecl*)(char *, void *))0x00503050;
CARM95_HOOK_FUNCTION(original_BrStdioPutLine, BrStdioPutLine)
void __cdecl BrStdioPutLine(char *buf, void *f) {
    LOG_TRACE("(\"%s\", %p)", buf, f);

    (void)buf;
    (void)f;

    original_BrStdioPutLine(buf, f);
}

static void(__cdecl*original_BrStdioAdvance)(br_size_t, void *) = (void(__cdecl*)(br_size_t, void *))0x00503070;
CARM95_HOOK_FUNCTION(original_BrStdioAdvance, BrStdioAdvance)
void __cdecl BrStdioAdvance(br_size_t count, void *f) {
    LOG_TRACE("(%u, %p)", count, f);

    (void)count;
    (void)f;

    original_BrStdioAdvance(count, f);
}

