#include "drfile.h"

#include "harness/trace.h"

#include "carm95_hooks.h"

#include "carm95_webserver.h"

#include <assert.h>
br_filesystem * hookvar_gFilesystem  = (void*)0x0050f020;
br_filesystem ** hookvar_gOld_file_system  = (void*)0x00536298;

function_hook_state_t function_hook_state_DRStdioOpenRead = HOOK_UNAVAILABLE;
static void *(__cdecl*original_DRStdioOpenRead)(char *, br_size_t, br_mode_test_cbfn *, int *) = (void *(__cdecl*)(char *, br_size_t, br_mode_test_cbfn *, int *))0x0044cf30;
CARM95_HOOK_FUNCTION(original_DRStdioOpenRead, DRStdioOpenRead)
void* __cdecl DRStdioOpenRead(char *name, br_size_t n_magics, br_mode_test_cbfn *identify, int *mode_result) {
    LOG_TRACE("(\"%s\", %u, %p, %p)", name, n_magics, identify, mode_result);

    (void)name;
    (void)n_magics;
    (void)identify;
    (void)mode_result;

    if (function_hook_state_DRStdioOpenRead == HOOK_ENABLED) {
        assert(0 && "DRStdioOpenRead not implemented.");
        abort();
    } else {
        return original_DRStdioOpenRead(name, n_magics, identify, mode_result);
    }
}

function_hook_state_t function_hook_state_DRStdioOpenWrite = HOOK_UNAVAILABLE;
static void *(__cdecl*original_DRStdioOpenWrite)(char *, int) = (void *(__cdecl*)(char *, int))0x0044cf64;
CARM95_HOOK_FUNCTION(original_DRStdioOpenWrite, DRStdioOpenWrite)
void* __cdecl DRStdioOpenWrite(char *name, int mode) {
    LOG_TRACE("(\"%s\", %d)", name, mode);

    (void)name;
    (void)mode;

    if (function_hook_state_DRStdioOpenWrite == HOOK_ENABLED) {
        assert(0 && "DRStdioOpenWrite not implemented.");
        abort();
    } else {
        return original_DRStdioOpenWrite(name, mode);
    }
}

function_hook_state_t function_hook_state_DRStdioClose = HOOK_UNAVAILABLE;
static void(__cdecl*original_DRStdioClose)(void *) = (void(__cdecl*)(void *))0x0044cf87;
CARM95_HOOK_FUNCTION(original_DRStdioClose, DRStdioClose)
void __cdecl DRStdioClose(void *f) {
    LOG_TRACE("(%p)", f);

    (void)f;

    if (function_hook_state_DRStdioClose == HOOK_ENABLED) {
        assert(0 && "DRStdioClose not implemented.");
        abort();
    } else {
        original_DRStdioClose(f);
    }
}

function_hook_state_t function_hook_state_DRStdioRead = HOOK_UNAVAILABLE;
static br_size_t(__cdecl*original_DRStdioRead)(void *, br_size_t, unsigned int, void *) = (br_size_t(__cdecl*)(void *, br_size_t, unsigned int, void *))0x0044cfa1;
CARM95_HOOK_FUNCTION(original_DRStdioRead, DRStdioRead)
br_size_t __cdecl DRStdioRead(void *buf, br_size_t size, unsigned int n, void *f) {
    br_size_t result;
    LOG_TRACE("(%p, %u, %u, %p)", buf, size, n, f);

    (void)buf;
    (void)size;
    (void)n;
    (void)f;
    (void)result;

    if (function_hook_state_DRStdioRead == HOOK_ENABLED) {
        assert(0 && "DRStdioRead not implemented.");
        abort();
    } else {
        return original_DRStdioRead(buf, size, n, f);
    }
}

function_hook_state_t function_hook_state_DRStdioWrite = HOOK_UNAVAILABLE;
static br_size_t(__cdecl*original_DRStdioWrite)(void *, br_size_t, unsigned int, void *) = (br_size_t(__cdecl*)(void *, br_size_t, unsigned int, void *))0x0044cfd5;
CARM95_HOOK_FUNCTION(original_DRStdioWrite, DRStdioWrite)
br_size_t __cdecl DRStdioWrite(void *buf, br_size_t size, unsigned int n, void *f) {
    br_size_t result;
    LOG_TRACE("(%p, %u, %u, %p)", buf, size, n, f);

    (void)buf;
    (void)size;
    (void)n;
    (void)f;
    (void)result;

    if (function_hook_state_DRStdioWrite == HOOK_ENABLED) {
        assert(0 && "DRStdioWrite not implemented.");
        abort();
    } else {
        return original_DRStdioWrite(buf, size, n, f);
    }
}

function_hook_state_t function_hook_state_InstallDRFileCalls = HOOK_UNAVAILABLE;
void InstallDRFileCalls() {
    br_filesystem *temp_system;
    LOG_TRACE("()");

    (void)temp_system;

    if (function_hook_state_InstallDRFileCalls == HOOK_ENABLED) {
        assert(0 && "InstallDRFileCalls not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}

