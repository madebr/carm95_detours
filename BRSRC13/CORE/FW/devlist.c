#include "devlist.h"

#include "harness/trace.h"

#include "carm95_hooks.h"


br_error AddRequestedDrivers() {
    char devstr[256];
    static br_boolean bAlreadyDone;
    LOG_TRACE("()");

    (void)devstr;
    (void)bAlreadyDone;

    NOT_IMPLEMENTED();
}

static br_error(__stdcall*original_devAdd)(br_device **, br_device_begin_fn *, char *, br_image *) = (br_error(__stdcall*)(br_device **, br_device_begin_fn *, char *, br_image *))0x004e78e0;
CARM95_HOOK_FUNCTION(original_devAdd, devAdd)
br_error __stdcall devAdd(br_device **pdev, br_device_begin_fn *dev_begin, char *args, br_image *image) {
    int i;
    br_device *dev;
    struct br_open_device *new_slots;
    LOG_TRACE("(%p, %p, \"%s\", %p)", pdev, dev_begin, args, image);

    (void)pdev;
    (void)dev_begin;
    (void)args;
    (void)image;
    (void)i;
    (void)dev;
    (void)new_slots;

    return original_devAdd(pdev, dev_begin, args, image);
}

static br_error(__cdecl*original_BrDevAdd)(br_device **, char *, char *) = (br_error(__cdecl*)(br_device **, char *, char *))0x004e7880;
CARM95_HOOK_FUNCTION(original_BrDevAdd, BrDevAdd)
br_error __cdecl BrDevAdd(br_device **pdev, char *image, char *args) {
    br_image *dev_image;
    br_device_begin_fn *dev_begin;
    LOG_TRACE("(%p, \"%s\", \"%s\")", pdev, image, args);

    (void)pdev;
    (void)image;
    (void)args;
    (void)dev_image;
    (void)dev_begin;

    return original_BrDevAdd(pdev, image, args);
}

static br_error(__cdecl*original_BrDevAddStatic)(br_device **, br_device_begin_fn *, char *) = (br_error(__cdecl*)(br_device **, br_device_begin_fn *, char *))0x004e7a00;
CARM95_HOOK_FUNCTION(original_BrDevAddStatic, BrDevAddStatic)
br_error __cdecl BrDevAddStatic(br_device **pdev, br_device_begin_fn *dev_begin, char *args) {
    LOG_TRACE("(%p, %p, \"%s\")", pdev, dev_begin, args);

    (void)pdev;
    (void)dev_begin;
    (void)args;

    return original_BrDevAddStatic(pdev, dev_begin, args);
}

static br_error(__cdecl*original_BrDevCheckAdd)(br_device **, char *, char *) = (br_error(__cdecl*)(br_device **, char *, char *))0x004e7a20;
CARM95_HOOK_FUNCTION(original_BrDevCheckAdd, BrDevCheckAdd)
br_error __cdecl BrDevCheckAdd(br_device **pdev, char *name, char *args) {
    LOG_TRACE("(%p, \"%s\", \"%s\")", pdev, name, args);

    (void)pdev;
    (void)name;
    (void)args;

    return original_BrDevCheckAdd(pdev, name, args);
}

br_error BrDevAddConfig(char *config) {
    char *end;
    char *dev;
    char *arg;
    char tmp[512];
    int n;
    LOG_TRACE("(\"%s\")", config);

    (void)config;
    (void)end;
    (void)dev;
    (void)arg;
    (void)tmp;
    (void)n;

    NOT_IMPLEMENTED();
}

static br_error(__cdecl*original_BrDevRemove)(br_device *) = (br_error(__cdecl*)(br_device *))0x004e7c60;
CARM95_HOOK_FUNCTION(original_BrDevRemove, BrDevRemove)
br_error __cdecl BrDevRemove(br_device *dev) {
    int i;
    LOG_TRACE("(%p)", dev);

    (void)dev;
    (void)i;

    return original_BrDevRemove(dev);
}

static br_error(__stdcall*original_BrDevFind)(struct br_device **, char *) = (br_error(__stdcall*)(struct br_device **, char *))0x004e7cd0;
CARM95_HOOK_FUNCTION(original_BrDevFind, BrDevFind)
br_error __stdcall BrDevFind(struct br_device **pdev, char *pattern) {
    int i;
    int c;
    LOG_TRACE("(%p, \"%s\")", pdev, pattern);

    (void)pdev;
    (void)pattern;
    (void)i;
    (void)c;

    return original_BrDevFind(pdev, pattern);
}

static br_error(__stdcall*original_BrDevFindMany)(struct br_device **, br_int_32 *, br_int_32, char *) = (br_error(__stdcall*)(struct br_device **, br_int_32 *, br_int_32, char *))0x004e7d90;
CARM95_HOOK_FUNCTION(original_BrDevFindMany, BrDevFindMany)
br_error __stdcall BrDevFindMany(struct br_device **devices, br_int_32 *ndevices, br_int_32 max_devices, char *pattern) {
    int i;
    int c;
    LOG_TRACE("(%p, %p, %d, \"%s\")", devices, ndevices, max_devices, pattern);

    (void)devices;
    (void)ndevices;
    (void)max_devices;
    (void)pattern;
    (void)i;
    (void)c;

    return original_BrDevFindMany(devices, ndevices, max_devices, pattern);
}

static br_error(__stdcall*original_BrDevCount)(br_int_32 *, char *) = (br_error(__stdcall*)(br_int_32 *, char *))0x004e7e70;
CARM95_HOOK_FUNCTION(original_BrDevCount, BrDevCount)
br_error __stdcall BrDevCount(br_int_32 *ndevices, char *pattern) {
    int i;
    int c;
    LOG_TRACE("(%p, \"%s\")", ndevices, pattern);

    (void)ndevices;
    (void)pattern;
    (void)i;
    (void)c;

    return original_BrDevCount(ndevices, pattern);
}

static br_error(__cdecl*original_BrDevContainedFind)(struct br_object **, br_token, char *, br_token_value *) = (br_error(__cdecl*)(struct br_object **, br_token, char *, br_token_value *))0x004e7f20;
CARM95_HOOK_FUNCTION(original_BrDevContainedFind, BrDevContainedFind)
br_error __cdecl BrDevContainedFind(struct br_object **ph, br_token type, char *pattern, br_token_value *tv) {
    int i;
    LOG_TRACE("(%p, %d, \"%s\", %p)", ph, type, pattern, tv);

    (void)ph;
    (void)type;
    (void)pattern;
    (void)tv;
    (void)i;

    return original_BrDevContainedFind(ph, type, pattern, tv);
}

static br_error(__cdecl*original_BrDevContainedFindMany)(struct br_object **, br_int_32, br_int_32 *, br_token, char *, br_token_value *) = (br_error(__cdecl*)(struct br_object **, br_int_32, br_int_32 *, br_token, char *, br_token_value *))0x004e7fe0;
CARM95_HOOK_FUNCTION(original_BrDevContainedFindMany, BrDevContainedFindMany)
br_error __cdecl BrDevContainedFindMany(struct br_object **objects, br_int_32 max_objects, br_int_32 *pnum_objects, br_token type, char *pattern, br_token_value *tv) {
    int i;
    br_int_32 n;
    br_int_32 total;
    br_error r;
    LOG_TRACE("(%p, %d, %p, %d, \"%s\", %p)", objects, max_objects, pnum_objects, type, pattern, tv);

    (void)objects;
    (void)max_objects;
    (void)pnum_objects;
    (void)type;
    (void)pattern;
    (void)tv;
    (void)i;
    (void)n;
    (void)total;
    (void)r;

    return original_BrDevContainedFindMany(objects, max_objects, pnum_objects, type, pattern, tv);
}

static br_error(__cdecl*original_BrDevContainedCount)(br_int_32 *, br_token, char *, br_token_value *) = (br_error(__cdecl*)(br_int_32 *, br_token, char *, br_token_value *))0x004e80c0;
CARM95_HOOK_FUNCTION(original_BrDevContainedCount, BrDevContainedCount)
br_error __cdecl BrDevContainedCount(br_int_32 *pcount, br_token type, char *pattern, br_token_value *tv) {
    int i;
    br_int_32 n;
    br_int_32 total;
    br_error r;
    LOG_TRACE("(%p, %d, \"%s\", %p)", pcount, type, pattern, tv);

    (void)pcount;
    (void)type;
    (void)pattern;
    (void)tv;
    (void)i;
    (void)n;
    (void)total;
    (void)r;

    return original_BrDevContainedCount(pcount, type, pattern, tv);
}

