#include "file.h"

#include "harness/trace.h"

#include "carm95_hooks.h"

#include "carm95_webserver.h"

#include <assert.h>

function_hook_state_t function_hook_state__BrFileFree = HOOK_UNAVAILABLE;
void _BrFileFree(void *res, br_uint_8 res_class, br_size_t size) {
    br_file *file;
    LOG_TRACE("(%p, %u, %u)", res, res_class, size);

    (void)res;
    (void)res_class;
    (void)size;
    (void)file;

    if (function_hook_state__BrFileFree == HOOK_ENABLED) {
        assert(0 && "_BrFileFree not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}

function_hook_state_t function_hook_state_BrFileAttributes = HOOK_UNAVAILABLE;
static br_uint_32(__stdcall*original_BrFileAttributes)() = (br_uint_32(__stdcall*)())0x004e5fc0;
CARM95_HOOK_FUNCTION(original_BrFileAttributes, BrFileAttributes)
br_uint_32 __stdcall BrFileAttributes() {
    LOG_TRACE("()");


    if (function_hook_state_BrFileAttributes == HOOK_ENABLED) {
        assert(0 && "BrFileAttributes not implemented.");
        abort();
    } else {
        return original_BrFileAttributes();
    }
}

function_hook_state_t function_hook_state_BrFileOpenRead = HOOK_UNAVAILABLE;
static void *(__cdecl*original_BrFileOpenRead)(char *, br_size_t, br_mode_test_cbfn *, int *) = (void *(__cdecl*)(char *, br_size_t, br_mode_test_cbfn *, int *))0x004e5fd0;
CARM95_HOOK_FUNCTION(original_BrFileOpenRead, BrFileOpenRead)
void* __cdecl BrFileOpenRead(char *name, br_size_t n_magics, br_mode_test_cbfn *mode_test, int *mode_result) {
    void *raw_file;
    br_file *file;
    int bin_mode;
    LOG_TRACE("(\"%s\", %u, %p, %p)", name, n_magics, mode_test, mode_result);

    (void)name;
    (void)n_magics;
    (void)mode_test;
    (void)mode_result;
    (void)raw_file;
    (void)file;
    (void)bin_mode;

    if (function_hook_state_BrFileOpenRead == HOOK_ENABLED) {
        assert(0 && "BrFileOpenRead not implemented.");
        abort();
    } else {
        return original_BrFileOpenRead(name, n_magics, mode_test, mode_result);
    }
}

function_hook_state_t function_hook_state_BrFileOpenWrite = HOOK_UNAVAILABLE;
static void *(__cdecl*original_BrFileOpenWrite)(char *, int) = (void *(__cdecl*)(char *, int))0x004e6080;
CARM95_HOOK_FUNCTION(original_BrFileOpenWrite, BrFileOpenWrite)
void* __cdecl BrFileOpenWrite(char *name, int mode) {
    void *raw_file;
    br_file *file;
    LOG_TRACE("(\"%s\", %d)", name, mode);

    (void)name;
    (void)mode;
    (void)raw_file;
    (void)file;

    if (function_hook_state_BrFileOpenWrite == HOOK_ENABLED) {
        assert(0 && "BrFileOpenWrite not implemented.");
        abort();
    } else {
        return original_BrFileOpenWrite(name, mode);
    }
}

function_hook_state_t function_hook_state_BrFileClose = HOOK_UNAVAILABLE;
static void(__cdecl*original_BrFileClose)(void *) = (void(__cdecl*)(void *))0x004e60f0;
CARM95_HOOK_FUNCTION(original_BrFileClose, BrFileClose)
void __cdecl BrFileClose(void *f) {
    LOG_TRACE("(%p)", f);

    (void)f;

    if (function_hook_state_BrFileClose == HOOK_ENABLED) {
        assert(0 && "BrFileClose not implemented.");
        abort();
    } else {
        original_BrFileClose(f);
    }
}

function_hook_state_t function_hook_state_BrFileEof = HOOK_UNAVAILABLE;
static int(__cdecl*original_BrFileEof)(void *) = (int(__cdecl*)(void *))0x004e6100;
CARM95_HOOK_FUNCTION(original_BrFileEof, BrFileEof)
int __cdecl BrFileEof(void *f) {
    LOG_TRACE("(%p)", f);

    (void)f;

    if (function_hook_state_BrFileEof == HOOK_ENABLED) {
        assert(0 && "BrFileEof not implemented.");
        abort();
    } else {
        return original_BrFileEof(f);
    }
}

function_hook_state_t function_hook_state_BrFileGetChar = HOOK_UNAVAILABLE;
static int(__cdecl*original_BrFileGetChar)(void *) = (int(__cdecl*)(void *))0x004e6120;
CARM95_HOOK_FUNCTION(original_BrFileGetChar, BrFileGetChar)
int __cdecl BrFileGetChar(void *f) {
    LOG_TRACE("(%p)", f);

    (void)f;

    if (function_hook_state_BrFileGetChar == HOOK_ENABLED) {
        assert(0 && "BrFileGetChar not implemented.");
        abort();
    } else {
        return original_BrFileGetChar(f);
    }
}

function_hook_state_t function_hook_state_BrFilePutChar = HOOK_UNAVAILABLE;
static void(__cdecl*original_BrFilePutChar)(int, void *) = (void(__cdecl*)(int, void *))0x004e6140;
CARM95_HOOK_FUNCTION(original_BrFilePutChar, BrFilePutChar)
void __cdecl BrFilePutChar(int c, void *f) {
    LOG_TRACE("(%d, %p)", c, f);

    (void)c;
    (void)f;

    if (function_hook_state_BrFilePutChar == HOOK_ENABLED) {
        assert(0 && "BrFilePutChar not implemented.");
        abort();
    } else {
        original_BrFilePutChar(c, f);
    }
}

function_hook_state_t function_hook_state_BrFileRead = HOOK_UNAVAILABLE;
static int(__cdecl*original_BrFileRead)(void *, int, int, void *) = (int(__cdecl*)(void *, int, int, void *))0x004e6160;
CARM95_HOOK_FUNCTION(original_BrFileRead, BrFileRead)
int __cdecl BrFileRead(void *buf, int size, int n, void *f) {
    LOG_TRACE("(%p, %d, %d, %p)", buf, size, n, f);

    (void)buf;
    (void)size;
    (void)n;
    (void)f;

    if (function_hook_state_BrFileRead == HOOK_ENABLED) {
        assert(0 && "BrFileRead not implemented.");
        abort();
    } else {
        return original_BrFileRead(buf, size, n, f);
    }
}

function_hook_state_t function_hook_state_BrFileWrite = HOOK_UNAVAILABLE;
static int(__cdecl*original_BrFileWrite)(void *, int, int, void *) = (int(__cdecl*)(void *, int, int, void *))0x004e6190;
CARM95_HOOK_FUNCTION(original_BrFileWrite, BrFileWrite)
int __cdecl BrFileWrite(void *buf, int size, int n, void *f) {
    LOG_TRACE("(%p, %d, %d, %p)", buf, size, n, f);

    (void)buf;
    (void)size;
    (void)n;
    (void)f;

    if (function_hook_state_BrFileWrite == HOOK_ENABLED) {
        assert(0 && "BrFileWrite not implemented.");
        abort();
    } else {
        return original_BrFileWrite(buf, size, n, f);
    }
}

function_hook_state_t function_hook_state_BrFileGetLine = HOOK_UNAVAILABLE;
static int(__cdecl*original_BrFileGetLine)(char *, br_size_t, void *) = (int(__cdecl*)(char *, br_size_t, void *))0x004e61c0;
CARM95_HOOK_FUNCTION(original_BrFileGetLine, BrFileGetLine)
int __cdecl BrFileGetLine(char *buf, br_size_t buf_len, void *f) {
    LOG_TRACE("(\"%s\", %u, %p)", buf, buf_len, f);

    (void)buf;
    (void)buf_len;
    (void)f;

    if (function_hook_state_BrFileGetLine == HOOK_ENABLED) {
        assert(0 && "BrFileGetLine not implemented.");
        abort();
    } else {
        return original_BrFileGetLine(buf, buf_len, f);
    }
}

function_hook_state_t function_hook_state_BrFilePutLine = HOOK_UNAVAILABLE;
static void(__cdecl*original_BrFilePutLine)(char *, void *) = (void(__cdecl*)(char *, void *))0x004e61e0;
CARM95_HOOK_FUNCTION(original_BrFilePutLine, BrFilePutLine)
void __cdecl BrFilePutLine(char *buf, void *f) {
    LOG_TRACE("(\"%s\", %p)", buf, f);

    (void)buf;
    (void)f;

    if (function_hook_state_BrFilePutLine == HOOK_ENABLED) {
        assert(0 && "BrFilePutLine not implemented.");
        abort();
    } else {
        original_BrFilePutLine(buf, f);
    }
}

function_hook_state_t function_hook_state_BrFileAdvance = HOOK_UNAVAILABLE;
static void(__cdecl*original_BrFileAdvance)(long, void *) = (void(__cdecl*)(long, void *))0x004e6200;
CARM95_HOOK_FUNCTION(original_BrFileAdvance, BrFileAdvance)
void __cdecl BrFileAdvance(long count, void *f) {
    LOG_TRACE("(%d, %p)", count, f);

    (void)count;
    (void)f;

    if (function_hook_state_BrFileAdvance == HOOK_ENABLED) {
        assert(0 && "BrFileAdvance not implemented.");
        abort();
    } else {
        original_BrFileAdvance(count, f);
    }
}

function_hook_state_t function_hook_state_BrFilePrintf = HOOK_UNAVAILABLE;
int(__cdecl*BrFilePrintf)(void *, char *) = (int(__cdecl*)(void *, char *))0x004e6220;
int BrFilePrintf_do_not_use(void *f, char *fmt) {
    int n;
    va_list args;
    LOG_TRACE("(%p, \"%s\")", f, fmt);

    (void)f;
    (void)fmt;
    (void)n;
    (void)args;

    if (function_hook_state_BrFilePrintf == HOOK_ENABLED) {
        assert(0 && "BrFilePrintf_do_not_use not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}

