#include "image.h"

#include "harness/trace.h"

#include "carm95_hooks.h"

#include <stdio.h>

static br_boolean(*original_BrImageAdd)(br_image *, ...) = (br_boolean(*)(br_image *, ...))0x004e53b0;
CARM95_HOOK_FUNCTION(original_BrImageAdd, BrImageAdd)
br_boolean BrImageAdd(br_image *img) {
    LOG_TRACE("(%p)", img);

    (void)img;

    return original_BrImageAdd(img);
}

static br_boolean(*original_BrImageRemove)(br_image *, ...) = (br_boolean(*)(br_image *, ...))0x004e53d0;
CARM95_HOOK_FUNCTION(original_BrImageRemove, BrImageRemove)
br_boolean BrImageRemove(br_image *img) {
    LOG_TRACE("(%p)", img);

    (void)img;

    return original_BrImageRemove(img);
}

static br_image *(*original_BrImageFind)(char *, ...) = (br_image *(*)(char *, ...))0x004e53f0;
CARM95_HOOK_FUNCTION(original_BrImageFind, BrImageFind)
br_image* BrImageFind(char *pattern) {
    char *c;
    br_image *img;
    LOG_TRACE("(\"%s\")", pattern);

    (void)pattern;
    (void)c;
    (void)img;

    return original_BrImageFind(pattern);
}

br_image* imageLoadHost(char *name) {
    br_image *img;
    void *host_image;
    LOG_TRACE("(\"%s\")", name);

    (void)name;
    (void)img;
    (void)host_image;

    NOT_IMPLEMENTED();
}

static br_image *(*original_BrImageReference)(char *, ...) = (br_image *(*)(char *, ...))0x004e5470;
CARM95_HOOK_FUNCTION(original_BrImageReference, BrImageReference)
br_image* BrImageReference(char *name) {
    char *suffix;
    char *scratch;
    br_image *img;
    LOG_TRACE("(\"%s\")", name);

    (void)name;
    (void)suffix;
    (void)scratch;
    (void)img;

    return original_BrImageReference(name);
}

static void *(*original_imageLookupName)(br_image *, char *, br_uint_32, ...) = (void *(*)(br_image *, char *, br_uint_32, ...))0x004e5710;
CARM95_HOOK_FUNCTION(original_imageLookupName, imageLookupName)
void* imageLookupName(br_image *img, char *name, br_uint_32 hint) {
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

    return original_imageLookupName(img, name, hint);
}

static void *(*original_BrImageLookupName)(br_image *, char *, br_uint_32, ...) = (void *(*)(br_image *, char *, br_uint_32, ...))0x004e56a0;
CARM95_HOOK_FUNCTION(original_BrImageLookupName, BrImageLookupName)
void* BrImageLookupName(br_image *img, char *name, br_uint_32 hint) {
    char *scratch;
    void *p;
    LOG_TRACE("(%p, \"%s\", %u)", img, name, hint);

    (void)img;
    (void)name;
    (void)hint;
    (void)scratch;
    (void)p;

    return original_BrImageLookupName(img, name, hint);
}

static void *(*original_BrImageLookupOrdinal)(br_image *, br_uint_32, ...) = (void *(*)(br_image *, br_uint_32, ...))0x004e57d0;
CARM95_HOOK_FUNCTION(original_BrImageLookupOrdinal, BrImageLookupOrdinal)
void* BrImageLookupOrdinal(br_image *img, br_uint_32 ordinal) {
    LOG_TRACE("(%p, %u)", img, ordinal);

    (void)img;
    (void)ordinal;

    return original_BrImageLookupOrdinal(img, ordinal);
}

static void(*original_BrImageDereference)(br_image *, ...) = (void(*)(br_image *, ...))0x004e5810;
CARM95_HOOK_FUNCTION(original_BrImageDereference, BrImageDereference)
void BrImageDereference(br_image *image) {
    LOG_TRACE("(%p)", image);

    (void)image;

    original_BrImageDereference(image);
}

static void(*original_BrImageFree)(br_image *, ...) = (void(*)(br_image *, ...))0x004e5850;
CARM95_HOOK_FUNCTION(original_BrImageFree, BrImageFree)
void BrImageFree(br_image *image) {
    int i;
    LOG_TRACE("(%p)", image);

    (void)image;
    (void)i;

    original_BrImageFree(image);
}

static void(*original__BrImageFree)(void *, br_uint_8, br_size_t, ...) = (void(*)(void *, br_uint_8, br_size_t, ...))0x004e58c0;
CARM95_HOOK_FUNCTION(original__BrImageFree, _BrImageFree)
void _BrImageFree(void *res, br_uint_8 res_class, br_size_t size) {
    LOG_TRACE("(%p, %u, %u)", res, res_class, size);

    (void)res;
    (void)res_class;
    (void)size;

    original__BrImageFree(res, res_class, size);
}

