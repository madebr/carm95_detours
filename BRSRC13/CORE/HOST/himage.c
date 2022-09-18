#include "himage.h"

#include "harness/trace.h"

#include "carm95_hooks.h"


static void *(__cdecl*original_HostImageLoad)(char *) = (void *(__cdecl*)(char *))0x005012d0;
CARM95_HOOK_FUNCTION(original_HostImageLoad, HostImageLoad)
void* __cdecl HostImageLoad(char *name) {
    LOG_TRACE("(\"%s\")", name);

    (void)name;

    return original_HostImageLoad(name);
}

void(__stdcall*HostImageUnload)(void *) = (void(__stdcall*)(void *))0x005012e0;
void HostImageUnload_do_not_use(void *image) {
    LOG_TRACE("(%p)", image);

    (void)image;

    NOT_IMPLEMENTED();
}

static void *(__cdecl*original_HostImageLookupName)(void *, char *, br_uint_32) = (void *(__cdecl*)(void *, char *, br_uint_32))0x005012f0;
CARM95_HOOK_FUNCTION(original_HostImageLookupName, HostImageLookupName)
void* __cdecl HostImageLookupName(void *img, char *name, br_uint_32 hint) {
    LOG_TRACE("(%p, \"%s\", %u)", img, name, hint);

    (void)img;
    (void)name;
    (void)hint;

    return original_HostImageLookupName(img, name, hint);
}

void *(__stdcall*HostImageLookupOrdinal)(void *, br_uint_32) = (void *(__stdcall*)(void *, br_uint_32))0x00501310;
void* HostImageLookupOrdinal_do_not_use(void *img, br_uint_32 ordinal) {
    LOG_TRACE("(%p, %u)", img, ordinal);

    (void)img;
    (void)ordinal;

    NOT_IMPLEMENTED();
}

