#include "gencopy.h"

#include "harness/trace.h"

#include "carm95_hooks.h"


static br_error(__stdcall*original_GeneralRectangleCopy)(br_device_pixelmap *, br_point *, br_device_pixelmap *, br_rectangle *) = (br_error(__stdcall*)(br_device_pixelmap *, br_point *, br_device_pixelmap *, br_rectangle *))0x004cdaf0;
CARM95_HOOK_FUNCTION(original_GeneralRectangleCopy, GeneralRectangleCopy)
br_error __stdcall GeneralRectangleCopy(br_device_pixelmap *dest, br_point *p, br_device_pixelmap *src, br_rectangle *r) {
    LOG_TRACE("(%p, %p, %p, %p)", dest, p, src, r);

    (void)dest;
    (void)p;
    (void)src;
    (void)r;

    return original_GeneralRectangleCopy(dest, p, src, r);
}

static br_error(__stdcall*original_GeneralCopy)(br_device_pixelmap *, br_device_pixelmap *) = (br_error(__stdcall*)(br_device_pixelmap *, br_device_pixelmap *))0x004cdb00;
CARM95_HOOK_FUNCTION(original_GeneralCopy, GeneralCopy)
br_error __stdcall GeneralCopy(br_device_pixelmap *dst, br_device_pixelmap *src) {
    LOG_TRACE("(%p, %p)", dst, src);

    (void)dst;
    (void)src;

    return original_GeneralCopy(dst, src);
}

static br_error(__stdcall*original_GeneralRectangleStretchCopy)(struct br_device_pixelmap *, br_rectangle *, struct br_device_pixelmap *, br_rectangle *) = (br_error(__stdcall*)(struct br_device_pixelmap *, br_rectangle *, struct br_device_pixelmap *, br_rectangle *))0x004cdb10;
CARM95_HOOK_FUNCTION(original_GeneralRectangleStretchCopy, GeneralRectangleStretchCopy)
br_error __stdcall GeneralRectangleStretchCopy(struct br_device_pixelmap *dst, br_rectangle *d, struct br_device_pixelmap *src, br_rectangle *s) {
    LOG_TRACE("(%p, %p, %p, %p)", dst, d, src, s);

    (void)dst;
    (void)d;
    (void)src;
    (void)s;

    return original_GeneralRectangleStretchCopy(dst, d, src, s);
}

