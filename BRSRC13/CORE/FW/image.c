#include "image.h"

#include "harness/trace.h"

#include "carm95_hooks.h"

#include "carm95_webserver.h"

#include <assert.h>

function_hook_state_t function_hook_state_BrImageAdd = HOOK_UNAVAILABLE;
static br_boolean(__cdecl*original_BrImageAdd)(br_image *) = (br_boolean(__cdecl*)(br_image *))0x004e53b0;
CARM95_HOOK_FUNCTION(original_BrImageAdd, BrImageAdd)
br_boolean __cdecl BrImageAdd(br_image *img) {
    LOG_TRACE("(%p)", img);

    (void)img;

    if (function_hook_state_BrImageAdd == HOOK_ENABLED) {
        assert(0 && "BrImageAdd not implemented.");
        abort();
    } else {
        return original_BrImageAdd(img);
    }
}

function_hook_state_t function_hook_state_BrImageRemove = HOOK_UNAVAILABLE;
static br_boolean(__cdecl*original_BrImageRemove)(br_image *) = (br_boolean(__cdecl*)(br_image *))0x004e53d0;
CARM95_HOOK_FUNCTION(original_BrImageRemove, BrImageRemove)
br_boolean __cdecl BrImageRemove(br_image *img) {
    LOG_TRACE("(%p)", img);

    (void)img;

    if (function_hook_state_BrImageRemove == HOOK_ENABLED) {
        assert(0 && "BrImageRemove not implemented.");
        abort();
    } else {
        return original_BrImageRemove(img);
    }
}

function_hook_state_t function_hook_state_BrImageFind = HOOK_UNAVAILABLE;
static br_image *(__cdecl*original_BrImageFind)(char *) = (br_image *(__cdecl*)(char *))0x004e53f0;
CARM95_HOOK_FUNCTION(original_BrImageFind, BrImageFind)
br_image* __cdecl BrImageFind(char *pattern) {
    char *c;
    br_image *img;
    LOG_TRACE("(\"%s\")", pattern);

    (void)pattern;
    (void)c;
    (void)img;

    if (function_hook_state_BrImageFind == HOOK_ENABLED) {
        assert(0 && "BrImageFind not implemented.");
        abort();
    } else {
        return original_BrImageFind(pattern);
    }
}

function_hook_state_t function_hook_state_imageLoadHost = HOOK_UNAVAILABLE;
br_image* imageLoadHost(char *name) {
    br_image *img;
    void *host_image;
    LOG_TRACE("(\"%s\")", name);

    (void)name;
    (void)img;
    (void)host_image;

    if (function_hook_state_imageLoadHost == HOOK_ENABLED) {
        assert(0 && "imageLoadHost not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}

function_hook_state_t function_hook_state_BrImageReference = HOOK_UNAVAILABLE;
static br_image *(__cdecl*original_BrImageReference)(char *) = (br_image *(__cdecl*)(char *))0x004e5470;
CARM95_HOOK_FUNCTION(original_BrImageReference, BrImageReference)
br_image* __cdecl BrImageReference(char *name) {
    char *suffix;
    char *scratch;
    br_image *img;
    LOG_TRACE("(\"%s\")", name);

    (void)name;
    (void)suffix;
    (void)scratch;
    (void)img;

    if (function_hook_state_BrImageReference == HOOK_ENABLED) {
        assert(0 && "BrImageReference not implemented.");
        abort();
    } else {
        return original_BrImageReference(name);
    }
}

function_hook_state_t function_hook_state_imageLookupName = HOOK_UNAVAILABLE;
static void *(__stdcall*original_imageLookupName)(br_image *, char *, br_uint_32) = (void *(__stdcall*)(br_image *, char *, br_uint_32))0x004e5710;
CARM95_HOOK_FUNCTION(original_imageLookupName, imageLookupName)
void* __stdcall imageLookupName(br_image *img, char *name, br_uint_32 hint) {
    int c;
    int limit;
    int base;
    LOG_TRACE("(%p, \"%s\", %u)", img, name, hint);

    (void)img;
    (void)name;
    (void)hint;
    (void)c;
    (void)limit;
    (void)base;

    if (function_hook_state_imageLookupName == HOOK_ENABLED) {
        assert(0 && "imageLookupName not implemented.");
        abort();
    } else {
        return original_imageLookupName(img, name, hint);
    }
}

function_hook_state_t function_hook_state_BrImageLookupName = HOOK_UNAVAILABLE;
static void *(__cdecl*original_BrImageLookupName)(br_image *, char *, br_uint_32) = (void *(__cdecl*)(br_image *, char *, br_uint_32))0x004e56a0;
CARM95_HOOK_FUNCTION(original_BrImageLookupName, BrImageLookupName)
void* __cdecl BrImageLookupName(br_image *img, char *name, br_uint_32 hint) {
    char *scratch;
    void *p;
    LOG_TRACE("(%p, \"%s\", %u)", img, name, hint);

    (void)img;
    (void)name;
    (void)hint;
    (void)scratch;
    (void)p;

    if (function_hook_state_BrImageLookupName == HOOK_ENABLED) {
        assert(0 && "BrImageLookupName not implemented.");
        abort();
    } else {
        return original_BrImageLookupName(img, name, hint);
    }
}

function_hook_state_t function_hook_state_BrImageLookupOrdinal = HOOK_UNAVAILABLE;
static void *(__cdecl*original_BrImageLookupOrdinal)(br_image *, br_uint_32) = (void *(__cdecl*)(br_image *, br_uint_32))0x004e57d0;
CARM95_HOOK_FUNCTION(original_BrImageLookupOrdinal, BrImageLookupOrdinal)
void* __cdecl BrImageLookupOrdinal(br_image *img, br_uint_32 ordinal) {
    LOG_TRACE("(%p, %u)", img, ordinal);

    (void)img;
    (void)ordinal;

    if (function_hook_state_BrImageLookupOrdinal == HOOK_ENABLED) {
        assert(0 && "BrImageLookupOrdinal not implemented.");
        abort();
    } else {
        return original_BrImageLookupOrdinal(img, ordinal);
    }
}

function_hook_state_t function_hook_state_BrImageDereference = HOOK_UNAVAILABLE;
static void(__cdecl*original_BrImageDereference)(br_image *) = (void(__cdecl*)(br_image *))0x004e5810;
CARM95_HOOK_FUNCTION(original_BrImageDereference, BrImageDereference)
void __cdecl BrImageDereference(br_image *image) {
    LOG_TRACE("(%p)", image);

    (void)image;

    if (function_hook_state_BrImageDereference == HOOK_ENABLED) {
        assert(0 && "BrImageDereference not implemented.");
        abort();
    } else {
        original_BrImageDereference(image);
    }
}

function_hook_state_t function_hook_state_BrImageFree = HOOK_UNAVAILABLE;
static void(__cdecl*original_BrImageFree)(br_image *) = (void(__cdecl*)(br_image *))0x004e5850;
CARM95_HOOK_FUNCTION(original_BrImageFree, BrImageFree)
void __cdecl BrImageFree(br_image *image) {
    int i;
    LOG_TRACE("(%p)", image);

    (void)image;
    (void)i;

    if (function_hook_state_BrImageFree == HOOK_ENABLED) {
        assert(0 && "BrImageFree not implemented.");
        abort();
    } else {
        original_BrImageFree(image);
    }
}

function_hook_state_t function_hook_state__BrImageFree = HOOK_UNAVAILABLE;
static void(__cdecl*original__BrImageFree)(void *, br_uint_8, br_size_t) = (void(__cdecl*)(void *, br_uint_8, br_size_t))0x004e58c0;
CARM95_HOOK_FUNCTION(original__BrImageFree, _BrImageFree)
void __cdecl _BrImageFree(void *res, br_uint_8 res_class, br_size_t size) {
    LOG_TRACE("(%p, %u, %u)", res, res_class, size);

    (void)res;
    (void)res_class;
    (void)size;

    if (function_hook_state__BrImageFree == HOOK_ENABLED) {
        assert(0 && "_BrImageFree not implemented.");
        abort();
    } else {
        original__BrImageFree(res, res_class, size);
    }
}

