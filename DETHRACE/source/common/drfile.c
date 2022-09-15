#include "drfile.h"

#include "harness/trace.h"

#include "carm95_hooks.h"

#include <stdio.h>
br_filesystem * hookvar_gFilesystem  = (void*)0x0050f020;
br_filesystem ** hookvar_gOld_file_system  = (void*)0x00536298;

static void *(*original_DRStdioOpenRead)(char *, br_size_t, br_mode_test_cbfn *, int *, ...) = (void *(*)(char *, br_size_t, br_mode_test_cbfn *, int *, ...))0x0044cf30;
CARM95_HOOK_FUNCTION(original_DRStdioOpenRead, DRStdioOpenRead)
void* DRStdioOpenRead(char *name, br_size_t n_magics, br_mode_test_cbfn *identify, int *mode_result) {
    LOG_TRACE("(\"%s\", %u, %p, %p)", name, n_magics, identify, mode_result);

    (void)name;
    (void)n_magics;
    (void)identify;
    (void)mode_result;

    return original_DRStdioOpenRead(name, n_magics, identify, mode_result);
}

static void *(*original_DRStdioOpenWrite)(char *, int, ...) = (void *(*)(char *, int, ...))0x0044cf64;
CARM95_HOOK_FUNCTION(original_DRStdioOpenWrite, DRStdioOpenWrite)
void* DRStdioOpenWrite(char *name, int mode) {
    LOG_TRACE("(\"%s\", %d)", name, mode);

    (void)name;
    (void)mode;

    return original_DRStdioOpenWrite(name, mode);
}

static void(*original_DRStdioClose)(void *, ...) = (void(*)(void *, ...))0x0044cf87;
CARM95_HOOK_FUNCTION(original_DRStdioClose, DRStdioClose)
void DRStdioClose(void *f) {
    LOG_TRACE("(%p)", f);

    (void)f;

    original_DRStdioClose(f);
}

static br_size_t(*original_DRStdioRead)(void *, br_size_t, unsigned int, void *, ...) = (br_size_t(*)(void *, br_size_t, unsigned int, void *, ...))0x0044cfa1;
CARM95_HOOK_FUNCTION(original_DRStdioRead, DRStdioRead)
br_size_t DRStdioRead(void *buf, br_size_t size, unsigned int n, void *f) {
    br_size_t result;
    LOG_TRACE("(%p, %u, %u, %p)", buf, size, n, f);

    (void)buf;
    (void)size;
    (void)n;
    (void)f;
    (void)result;

    return original_DRStdioRead(buf, size, n, f);
}

static br_size_t(*original_DRStdioWrite)(void *, br_size_t, unsigned int, void *, ...) = (br_size_t(*)(void *, br_size_t, unsigned int, void *, ...))0x0044cfd5;
CARM95_HOOK_FUNCTION(original_DRStdioWrite, DRStdioWrite)
br_size_t DRStdioWrite(void *buf, br_size_t size, unsigned int n, void *f) {
    br_size_t result;
    LOG_TRACE("(%p, %u, %u, %p)", buf, size, n, f);

    (void)buf;
    (void)size;
    (void)n;
    (void)f;
    (void)result;

    return original_DRStdioWrite(buf, size, n, f);
}

void InstallDRFileCalls() {
    br_filesystem *temp_system;
    LOG_TRACE("()");

    (void)temp_system;

    NOT_IMPLEMENTED();
}

