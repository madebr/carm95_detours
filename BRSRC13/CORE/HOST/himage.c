#include "himage.h"

#include "harness/trace.h"

#include "carm95_hooks.h"

#include "carm95_webserver.h"

#include <assert.h>

function_hook_state_t function_hook_state_HostImageLoad = HOOK_UNAVAILABLE;
static void *(__cdecl*original_HostImageLoad)(char *) = (void *(__cdecl*)(char *))0x005012d0;
CARM95_HOOK_FUNCTION(original_HostImageLoad, HostImageLoad)
void* __cdecl HostImageLoad(char *name) {
    LOG_TRACE("(\"%s\")", name);

    (void)name;

    if (function_hook_state_HostImageLoad == HOOK_ENABLED) {
        assert(0 && "HostImageLoad not implemented.");
        abort();
    } else {
        return original_HostImageLoad(name);
    }
}

function_hook_state_t function_hook_state_HostImageUnload = HOOK_UNAVAILABLE;
void(__cdecl*HostImageUnload)(void *) = (void(__cdecl*)(void *))0x005012e0;
void HostImageUnload_do_not_use(void *image) {
    LOG_TRACE("(%p)", image);

    (void)image;

    if (function_hook_state_HostImageUnload == HOOK_ENABLED) {
        assert(0 && "HostImageUnload_do_not_use not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}

function_hook_state_t function_hook_state_HostImageLookupName = HOOK_UNAVAILABLE;
static void *(__cdecl*original_HostImageLookupName)(void *, char *, br_uint_32) = (void *(__cdecl*)(void *, char *, br_uint_32))0x005012f0;
CARM95_HOOK_FUNCTION(original_HostImageLookupName, HostImageLookupName)
void* __cdecl HostImageLookupName(void *img, char *name, br_uint_32 hint) {
    LOG_TRACE("(%p, \"%s\", %u)", img, name, hint);

    (void)img;
    (void)name;
    (void)hint;

    if (function_hook_state_HostImageLookupName == HOOK_ENABLED) {
        assert(0 && "HostImageLookupName not implemented.");
        abort();
    } else {
        return original_HostImageLookupName(img, name, hint);
    }
}

function_hook_state_t function_hook_state_HostImageLookupOrdinal = HOOK_UNAVAILABLE;
void *(__cdecl*HostImageLookupOrdinal)(void *, br_uint_32) = (void *(__cdecl*)(void *, br_uint_32))0x00501310;
void* HostImageLookupOrdinal_do_not_use(void *img, br_uint_32 ordinal) {
    LOG_TRACE("(%p, %u)", img, ordinal);

    (void)img;
    (void)ordinal;

    if (function_hook_state_HostImageLookupOrdinal == HOOK_ENABLED) {
        assert(0 && "HostImageLookupOrdinal_do_not_use not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}

