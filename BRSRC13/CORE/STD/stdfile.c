#include "stdfile.h"

#include "harness/trace.h"

#include "carm95_hooks.h"

#include "carm95_webserver.h"

#include <assert.h>
#include <stdio.h>
br_filesystem * hookvar_BrStdioFilesystem  = (void*)0x005300e0;
br_filesystem ** hookvar__BrDefaultFilesystem  = (void*)0x00530114;

function_hook_state_t function_hook_state_BrStdioAttributes = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_BrStdioAttributes)
br_uint_32 BrStdioAttributes() {
    LOG_TRACE("()");


    if (function_hook_state_BrStdioAttributes == HOOK_ENABLED) {
        assert(0 && "BrStdioAttributes not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}

function_hook_state_t function_hook_state_BrStdioOpenRead = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_BrStdioOpenRead)
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

    if (function_hook_state_BrStdioOpenRead == HOOK_ENABLED) {
        assert(0 && "BrStdioOpenRead not implemented.");
        abort();
    } else {
        return original_BrStdioOpenRead(name, n_magics, identify, mode_result);
    }
}

function_hook_state_t function_hook_state_BrStdioOpenWrite = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_BrStdioOpenWrite)
static void *(__cdecl*original_BrStdioOpenWrite)(char *, int) = (void *(__cdecl*)(char *, int))0x00502f20;
CARM95_HOOK_FUNCTION(original_BrStdioOpenWrite, BrStdioOpenWrite)
void* __cdecl BrStdioOpenWrite(char *name, int mode) {
    FILE *fh;
    LOG_TRACE("(\"%s\", %d)", name, mode);

    (void)name;
    (void)mode;
    (void)fh;

    if (function_hook_state_BrStdioOpenWrite == HOOK_ENABLED) {
        assert(0 && "BrStdioOpenWrite not implemented.");
        abort();
    } else {
        return original_BrStdioOpenWrite(name, mode);
    }
}

function_hook_state_t function_hook_state_BrStdioClose = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_BrStdioClose)
static void(__cdecl*original_BrStdioClose)(void *) = (void(__cdecl*)(void *))0x00502f50;
CARM95_HOOK_FUNCTION(original_BrStdioClose, BrStdioClose)
void __cdecl BrStdioClose(void *f) {
    LOG_TRACE("(%p)", f);

    (void)f;

    if (function_hook_state_BrStdioClose == HOOK_ENABLED) {
        assert(0 && "BrStdioClose not implemented.");
        abort();
    } else {
        original_BrStdioClose(f);
    }
}

function_hook_state_t function_hook_state_BrStdioEof = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_BrStdioEof)
static int(__cdecl*original_BrStdioEof)(void *) = (int(__cdecl*)(void *))0x00502f60;
CARM95_HOOK_FUNCTION(original_BrStdioEof, BrStdioEof)
int __cdecl BrStdioEof(void *f) {
    LOG_TRACE("(%p)", f);

    (void)f;

    if (function_hook_state_BrStdioEof == HOOK_ENABLED) {
        assert(0 && "BrStdioEof not implemented.");
        abort();
    } else {
        return original_BrStdioEof(f);
    }
}

function_hook_state_t function_hook_state_BrStdioGetChar = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_BrStdioGetChar)
static int(__cdecl*original_BrStdioGetChar)(void *) = (int(__cdecl*)(void *))0x00502f70;
CARM95_HOOK_FUNCTION(original_BrStdioGetChar, BrStdioGetChar)
int __cdecl BrStdioGetChar(void *f) {
    LOG_TRACE("(%p)", f);

    (void)f;

    if (function_hook_state_BrStdioGetChar == HOOK_ENABLED) {
        assert(0 && "BrStdioGetChar not implemented.");
        abort();
    } else {
        return original_BrStdioGetChar(f);
    }
}

function_hook_state_t function_hook_state_BrStdioPutChar = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_BrStdioPutChar)
static void(__cdecl*original_BrStdioPutChar)(int, void *) = (void(__cdecl*)(int, void *))0x00502fa0;
CARM95_HOOK_FUNCTION(original_BrStdioPutChar, BrStdioPutChar)
void __cdecl BrStdioPutChar(int c, void *f) {
    LOG_TRACE("(%d, %p)", c, f);

    (void)c;
    (void)f;

    if (function_hook_state_BrStdioPutChar == HOOK_ENABLED) {
        assert(0 && "BrStdioPutChar not implemented.");
        abort();
    } else {
        original_BrStdioPutChar(c, f);
    }
}

function_hook_state_t function_hook_state_BrStdioRead = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_BrStdioRead)
static br_size_t(__cdecl*original_BrStdioRead)(void *, br_size_t, unsigned int, void *) = (br_size_t(__cdecl*)(void *, br_size_t, unsigned int, void *))0x00502fc0;
CARM95_HOOK_FUNCTION(original_BrStdioRead, BrStdioRead)
br_size_t __cdecl BrStdioRead(void *buf, br_size_t size, unsigned int n, void *f) {
    LOG_TRACE("(%p, %u, %u, %p)", buf, size, n, f);

    (void)buf;
    (void)size;
    (void)n;
    (void)f;

    if (function_hook_state_BrStdioRead == HOOK_ENABLED) {
        assert(0 && "BrStdioRead not implemented.");
        abort();
    } else {
        return original_BrStdioRead(buf, size, n, f);
    }
}

function_hook_state_t function_hook_state_BrStdioWrite = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_BrStdioWrite)
static br_size_t(__cdecl*original_BrStdioWrite)(void *, br_size_t, unsigned int, void *) = (br_size_t(__cdecl*)(void *, br_size_t, unsigned int, void *))0x00502fe0;
CARM95_HOOK_FUNCTION(original_BrStdioWrite, BrStdioWrite)
br_size_t __cdecl BrStdioWrite(void *buf, br_size_t size, unsigned int n, void *f) {
    LOG_TRACE("(%p, %u, %u, %p)", buf, size, n, f);

    (void)buf;
    (void)size;
    (void)n;
    (void)f;

    if (function_hook_state_BrStdioWrite == HOOK_ENABLED) {
        assert(0 && "BrStdioWrite not implemented.");
        abort();
    } else {
        return original_BrStdioWrite(buf, size, n, f);
    }
}

function_hook_state_t function_hook_state_BrStdioGetLine = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_BrStdioGetLine)
static br_size_t(__cdecl*original_BrStdioGetLine)(char *, br_size_t, void *) = (br_size_t(__cdecl*)(char *, br_size_t, void *))0x00503000;
CARM95_HOOK_FUNCTION(original_BrStdioGetLine, BrStdioGetLine)
br_size_t __cdecl BrStdioGetLine(char *buf, br_size_t buf_len, void *f) {
    br_size_t l;
    LOG_TRACE("(\"%s\", %u, %p)", buf, buf_len, f);

    (void)buf;
    (void)buf_len;
    (void)f;
    (void)l;

    if (function_hook_state_BrStdioGetLine == HOOK_ENABLED) {
        assert(0 && "BrStdioGetLine not implemented.");
        abort();
    } else {
        return original_BrStdioGetLine(buf, buf_len, f);
    }
}

function_hook_state_t function_hook_state_BrStdioPutLine = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_BrStdioPutLine)
static void(__cdecl*original_BrStdioPutLine)(char *, void *) = (void(__cdecl*)(char *, void *))0x00503050;
CARM95_HOOK_FUNCTION(original_BrStdioPutLine, BrStdioPutLine)
void __cdecl BrStdioPutLine(char *buf, void *f) {
    LOG_TRACE("(\"%s\", %p)", buf, f);

    (void)buf;
    (void)f;

    if (function_hook_state_BrStdioPutLine == HOOK_ENABLED) {
        assert(0 && "BrStdioPutLine not implemented.");
        abort();
    } else {
        original_BrStdioPutLine(buf, f);
    }
}

function_hook_state_t function_hook_state_BrStdioAdvance = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_BrStdioAdvance)
static void(__cdecl*original_BrStdioAdvance)(br_size_t, void *) = (void(__cdecl*)(br_size_t, void *))0x00503070;
CARM95_HOOK_FUNCTION(original_BrStdioAdvance, BrStdioAdvance)
void __cdecl BrStdioAdvance(br_size_t count, void *f) {
    LOG_TRACE("(%u, %p)", count, f);

    (void)count;
    (void)f;

    if (function_hook_state_BrStdioAdvance == HOOK_ENABLED) {
        assert(0 && "BrStdioAdvance not implemented.");
        abort();
    } else {
        original_BrStdioAdvance(count, f);
    }
}

