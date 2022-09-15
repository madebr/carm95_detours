#include "himage.h"

#include "harness/trace.h"

#include "carm95_hooks.h"

#include <stdio.h>

static void *(*original_HostImageLoad)(char *, ...) = (void *(*)(char *, ...))0x005012d0;
CARM95_HOOK_FUNCTION(original_HostImageLoad, HostImageLoad)
void* HostImageLoad(char *name) {
    LOG_TRACE("(\"%s\")", name);

    (void)name;

    return original_HostImageLoad(name);
}

static void(*original_HostImageUnload)(void *, ...) = (void(*)(void *, ...))0x005012e0;
CARM95_HOOK_FUNCTION(original_HostImageUnload, HostImageUnload)
void HostImageUnload(void *image) {
    LOG_TRACE("(%p)", image);

    (void)image;

    original_HostImageUnload(image);
}

static void *(*original_HostImageLookupName)(void *, char *, br_uint_32, ...) = (void *(*)(void *, char *, br_uint_32, ...))0x005012f0;
CARM95_HOOK_FUNCTION(original_HostImageLookupName, HostImageLookupName)
void* HostImageLookupName(void *img, char *name, br_uint_32 hint) {
    LOG_TRACE("(%p, \"%s\", %u)", img, name, hint);

    (void)img;
    (void)name;
    (void)hint;

    return original_HostImageLookupName(img, name, hint);
}

static void *(*original_HostImageLookupOrdinal)(void *, br_uint_32, ...) = (void *(*)(void *, br_uint_32, ...))0x00501310;
CARM95_HOOK_FUNCTION(original_HostImageLookupOrdinal, HostImageLookupOrdinal)
void* HostImageLookupOrdinal(void *img, br_uint_32 ordinal) {
    LOG_TRACE("(%p, %u)", img, ordinal);

    (void)img;
    (void)ordinal;

    return original_HostImageLookupOrdinal(img, ordinal);
}

