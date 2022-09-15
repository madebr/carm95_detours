#include "pmnull.h"

#include "harness/trace.h"

#include "carm95_hooks.h"

#include <stdio.h>

static br_error(*original__M_br_device_pixelmap_null_resize)(br_device_pixelmap *, br_int_32, br_int_32, ...) = (br_error(*)(br_device_pixelmap *, br_int_32, br_int_32, ...))0x004d0a80;
CARM95_HOOK_FUNCTION(original__M_br_device_pixelmap_null_resize, _M_br_device_pixelmap_null_resize)
br_error _M_br_device_pixelmap_null_resize(br_device_pixelmap *self, br_int_32 width, br_int_32 height) {
    LOG_TRACE("(%p, %d, %d)", self, width, height);

    (void)self;
    (void)width;
    (void)height;

    return original__M_br_device_pixelmap_null_resize(self, width, height);
}

static br_error(*original__M_br_device_pixelmap_null_copyTo)(br_device_pixelmap *, br_device_pixelmap *, ...) = (br_error(*)(br_device_pixelmap *, br_device_pixelmap *, ...))0x004d0a90;
CARM95_HOOK_FUNCTION(original__M_br_device_pixelmap_null_copyTo, _M_br_device_pixelmap_null_copyTo)
br_error _M_br_device_pixelmap_null_copyTo(br_device_pixelmap *self, br_device_pixelmap *src) {
    LOG_TRACE("(%p, %p)", self, src);

    (void)self;
    (void)src;

    return original__M_br_device_pixelmap_null_copyTo(self, src);
}

static br_error(*original__M_br_device_pixelmap_null_copyFrom)(br_device_pixelmap *, br_device_pixelmap *, ...) = (br_error(*)(br_device_pixelmap *, br_device_pixelmap *, ...))0x004d0aa0;
CARM95_HOOK_FUNCTION(original__M_br_device_pixelmap_null_copyFrom, _M_br_device_pixelmap_null_copyFrom)
br_error _M_br_device_pixelmap_null_copyFrom(br_device_pixelmap *self, br_device_pixelmap *src) {
    LOG_TRACE("(%p, %p)", self, src);

    (void)self;
    (void)src;

    return original__M_br_device_pixelmap_null_copyFrom(self, src);
}

static br_error(*original__M_br_device_pixelmap_null_fill)(br_device_pixelmap *, br_uint_32, ...) = (br_error(*)(br_device_pixelmap *, br_uint_32, ...))0x004d0ab0;
CARM95_HOOK_FUNCTION(original__M_br_device_pixelmap_null_fill, _M_br_device_pixelmap_null_fill)
br_error _M_br_device_pixelmap_null_fill(br_device_pixelmap *self, br_uint_32 colour) {
    LOG_TRACE("(%p, %u)", self, colour);

    (void)self;
    (void)colour;

    return original__M_br_device_pixelmap_null_fill(self, colour);
}

static br_error(*original__M_br_device_pixelmap_null_doubleBuffer)(br_device_pixelmap *, br_device_pixelmap *, ...) = (br_error(*)(br_device_pixelmap *, br_device_pixelmap *, ...))0x004d0ac0;
CARM95_HOOK_FUNCTION(original__M_br_device_pixelmap_null_doubleBuffer, _M_br_device_pixelmap_null_doubleBuffer)
br_error _M_br_device_pixelmap_null_doubleBuffer(br_device_pixelmap *self, br_device_pixelmap *src) {
    LOG_TRACE("(%p, %p)", self, src);

    (void)self;
    (void)src;

    return original__M_br_device_pixelmap_null_doubleBuffer(self, src);
}

static br_error(*original__M_br_device_pixelmap_null_copyDirty)(br_device_pixelmap *, br_device_pixelmap *, br_rectangle *, br_int_32, ...) = (br_error(*)(br_device_pixelmap *, br_device_pixelmap *, br_rectangle *, br_int_32, ...))0x004d0ad0;
CARM95_HOOK_FUNCTION(original__M_br_device_pixelmap_null_copyDirty, _M_br_device_pixelmap_null_copyDirty)
br_error _M_br_device_pixelmap_null_copyDirty(br_device_pixelmap *self, br_device_pixelmap *src, br_rectangle *dirty, br_int_32 num_rects) {
    LOG_TRACE("(%p, %p, %p, %d)", self, src, dirty, num_rects);

    (void)self;
    (void)src;
    (void)dirty;
    (void)num_rects;

    return original__M_br_device_pixelmap_null_copyDirty(self, src, dirty, num_rects);
}

static br_error(*original__M_br_device_pixelmap_null_copyToDirty)(br_device_pixelmap *, br_device_pixelmap *, br_rectangle *, br_int_32, ...) = (br_error(*)(br_device_pixelmap *, br_device_pixelmap *, br_rectangle *, br_int_32, ...))0x004d0ae0;
CARM95_HOOK_FUNCTION(original__M_br_device_pixelmap_null_copyToDirty, _M_br_device_pixelmap_null_copyToDirty)
br_error _M_br_device_pixelmap_null_copyToDirty(br_device_pixelmap *self, br_device_pixelmap *src, br_rectangle *dirty, br_int_32 num_rects) {
    LOG_TRACE("(%p, %p, %p, %d)", self, src, dirty, num_rects);

    (void)self;
    (void)src;
    (void)dirty;
    (void)num_rects;

    return original__M_br_device_pixelmap_null_copyToDirty(self, src, dirty, num_rects);
}

static br_error(*original__M_br_device_pixelmap_null_copyFromDirty)(br_device_pixelmap *, br_device_pixelmap *, br_rectangle *, br_int_32, ...) = (br_error(*)(br_device_pixelmap *, br_device_pixelmap *, br_rectangle *, br_int_32, ...))0x004d0af0;
CARM95_HOOK_FUNCTION(original__M_br_device_pixelmap_null_copyFromDirty, _M_br_device_pixelmap_null_copyFromDirty)
br_error _M_br_device_pixelmap_null_copyFromDirty(br_device_pixelmap *self, br_device_pixelmap *src, br_rectangle *dirty, br_int_32 num_rects) {
    LOG_TRACE("(%p, %p, %p, %d)", self, src, dirty, num_rects);

    (void)self;
    (void)src;
    (void)dirty;
    (void)num_rects;

    return original__M_br_device_pixelmap_null_copyFromDirty(self, src, dirty, num_rects);
}

static br_error(*original__M_br_device_pixelmap_null_fillDirty)(br_device_pixelmap *, br_uint_32, br_rectangle *, br_int_32, ...) = (br_error(*)(br_device_pixelmap *, br_uint_32, br_rectangle *, br_int_32, ...))0x004d0b00;
CARM95_HOOK_FUNCTION(original__M_br_device_pixelmap_null_fillDirty, _M_br_device_pixelmap_null_fillDirty)
br_error _M_br_device_pixelmap_null_fillDirty(br_device_pixelmap *self, br_uint_32 colour, br_rectangle *dirty, br_int_32 num_rects) {
    LOG_TRACE("(%p, %u, %p, %d)", self, colour, dirty, num_rects);

    (void)self;
    (void)colour;
    (void)dirty;
    (void)num_rects;

    return original__M_br_device_pixelmap_null_fillDirty(self, colour, dirty, num_rects);
}

static br_error(*original__M_br_device_pixelmap_null_doubleBufferDirty)(br_device_pixelmap *, br_device_pixelmap *, br_rectangle *, br_int_32, ...) = (br_error(*)(br_device_pixelmap *, br_device_pixelmap *, br_rectangle *, br_int_32, ...))0x004d0b10;
CARM95_HOOK_FUNCTION(original__M_br_device_pixelmap_null_doubleBufferDirty, _M_br_device_pixelmap_null_doubleBufferDirty)
br_error _M_br_device_pixelmap_null_doubleBufferDirty(br_device_pixelmap *self, br_device_pixelmap *src, br_rectangle *dirty, br_int_32 num_rects) {
    LOG_TRACE("(%p, %p, %p, %d)", self, src, dirty, num_rects);

    (void)self;
    (void)src;
    (void)dirty;
    (void)num_rects;

    return original__M_br_device_pixelmap_null_doubleBufferDirty(self, src, dirty, num_rects);
}

static br_error(*original__M_br_device_pixelmap_null_rectangleCopyTo)(br_device_pixelmap *, br_point *, br_device_pixelmap *, br_rectangle *, ...) = (br_error(*)(br_device_pixelmap *, br_point *, br_device_pixelmap *, br_rectangle *, ...))0x004d0b20;
CARM95_HOOK_FUNCTION(original__M_br_device_pixelmap_null_rectangleCopyTo, _M_br_device_pixelmap_null_rectangleCopyTo)
br_error _M_br_device_pixelmap_null_rectangleCopyTo(br_device_pixelmap *self, br_point *p, br_device_pixelmap *src, br_rectangle *r) {
    LOG_TRACE("(%p, %p, %p, %p)", self, p, src, r);

    (void)self;
    (void)p;
    (void)src;
    (void)r;

    return original__M_br_device_pixelmap_null_rectangleCopyTo(self, p, src, r);
}

static br_error(*original__M_br_device_pixelmap_null_rectangleCopyFrom)(br_device_pixelmap *, br_point *, br_device_pixelmap *, br_rectangle *, ...) = (br_error(*)(br_device_pixelmap *, br_point *, br_device_pixelmap *, br_rectangle *, ...))0x004d0b30;
CARM95_HOOK_FUNCTION(original__M_br_device_pixelmap_null_rectangleCopyFrom, _M_br_device_pixelmap_null_rectangleCopyFrom)
br_error _M_br_device_pixelmap_null_rectangleCopyFrom(br_device_pixelmap *self, br_point *p, br_device_pixelmap *mem, br_rectangle *r) {
    LOG_TRACE("(%p, %p, %p, %p)", self, p, mem, r);

    (void)self;
    (void)p;
    (void)mem;
    (void)r;

    return original__M_br_device_pixelmap_null_rectangleCopyFrom(self, p, mem, r);
}

static br_error(*original__M_br_device_pixelmap_null_rectangleStretchCopyTo)(br_device_pixelmap *, br_rectangle *, br_device_pixelmap *, br_rectangle *, ...) = (br_error(*)(br_device_pixelmap *, br_rectangle *, br_device_pixelmap *, br_rectangle *, ...))0x004d0b40;
CARM95_HOOK_FUNCTION(original__M_br_device_pixelmap_null_rectangleStretchCopyTo, _M_br_device_pixelmap_null_rectangleStretchCopyTo)
br_error _M_br_device_pixelmap_null_rectangleStretchCopyTo(br_device_pixelmap *self, br_rectangle *d, br_device_pixelmap *src, br_rectangle *s) {
    LOG_TRACE("(%p, %p, %p, %p)", self, d, src, s);

    (void)self;
    (void)d;
    (void)src;
    (void)s;

    return original__M_br_device_pixelmap_null_rectangleStretchCopyTo(self, d, src, s);
}

static br_error(*original__M_br_device_pixelmap_null_rectangleStretchCopyFrom)(br_device_pixelmap *, br_rectangle *, br_device_pixelmap *, br_rectangle *, ...) = (br_error(*)(br_device_pixelmap *, br_rectangle *, br_device_pixelmap *, br_rectangle *, ...))0x004d0b50;
CARM95_HOOK_FUNCTION(original__M_br_device_pixelmap_null_rectangleStretchCopyFrom, _M_br_device_pixelmap_null_rectangleStretchCopyFrom)
br_error _M_br_device_pixelmap_null_rectangleStretchCopyFrom(br_device_pixelmap *self, br_rectangle *d, br_device_pixelmap *src, br_rectangle *s) {
    LOG_TRACE("(%p, %p, %p, %p)", self, d, src, s);

    (void)self;
    (void)d;
    (void)src;
    (void)s;

    return original__M_br_device_pixelmap_null_rectangleStretchCopyFrom(self, d, src, s);
}

static br_error(*original__M_br_device_pixelmap_null_rectangleFill)(br_device_pixelmap *, br_rectangle *, br_uint_32, ...) = (br_error(*)(br_device_pixelmap *, br_rectangle *, br_uint_32, ...))0x004d0b60;
CARM95_HOOK_FUNCTION(original__M_br_device_pixelmap_null_rectangleFill, _M_br_device_pixelmap_null_rectangleFill)
br_error _M_br_device_pixelmap_null_rectangleFill(br_device_pixelmap *self, br_rectangle *rect, br_uint_32 colour) {
    LOG_TRACE("(%p, %p, %u)", self, rect, colour);

    (void)self;
    (void)rect;
    (void)colour;

    return original__M_br_device_pixelmap_null_rectangleFill(self, rect, colour);
}

static br_error(*original__M_br_device_pixelmap_null_pixelSet)(br_device_pixelmap *, br_point *, br_uint_32, ...) = (br_error(*)(br_device_pixelmap *, br_point *, br_uint_32, ...))0x004d0b70;
CARM95_HOOK_FUNCTION(original__M_br_device_pixelmap_null_pixelSet, _M_br_device_pixelmap_null_pixelSet)
br_error _M_br_device_pixelmap_null_pixelSet(br_device_pixelmap *self, br_point *p, br_uint_32 colour) {
    LOG_TRACE("(%p, %p, %u)", self, p, colour);

    (void)self;
    (void)p;
    (void)colour;

    return original__M_br_device_pixelmap_null_pixelSet(self, p, colour);
}

static br_error(*original__M_br_device_pixelmap_null_copyBits)(br_device_pixelmap *, br_point *, br_uint_8 *, br_uint_16, br_rectangle *, br_uint_32, ...) = (br_error(*)(br_device_pixelmap *, br_point *, br_uint_8 *, br_uint_16, br_rectangle *, br_uint_32, ...))0x004d0b80;
CARM95_HOOK_FUNCTION(original__M_br_device_pixelmap_null_copyBits, _M_br_device_pixelmap_null_copyBits)
br_error _M_br_device_pixelmap_null_copyBits(br_device_pixelmap *self, br_point *point, br_uint_8 *src, br_uint_16 s_stride, br_rectangle *bit_rect, br_uint_32 colour) {
    LOG_TRACE("(%p, %p, %p, %u, %p, %u)", self, point, src, s_stride, bit_rect, colour);

    (void)self;
    (void)point;
    (void)src;
    (void)s_stride;
    (void)bit_rect;
    (void)colour;

    return original__M_br_device_pixelmap_null_copyBits(self, point, src, s_stride, bit_rect, colour);
}

static br_error(*original__M_br_device_pixelmap_null_pixelQuery)(br_device_pixelmap *, br_uint_32 *, br_point *, ...) = (br_error(*)(br_device_pixelmap *, br_uint_32 *, br_point *, ...))0x004d0b90;
CARM95_HOOK_FUNCTION(original__M_br_device_pixelmap_null_pixelQuery, _M_br_device_pixelmap_null_pixelQuery)
br_error _M_br_device_pixelmap_null_pixelQuery(br_device_pixelmap *self, br_uint_32 *pcolour, br_point *p) {
    LOG_TRACE("(%p, %p, %p)", self, pcolour, p);

    (void)self;
    (void)pcolour;
    (void)p;

    return original__M_br_device_pixelmap_null_pixelQuery(self, pcolour, p);
}

static br_error(*original__M_br_device_pixelmap_null_pixelAddressQuery)(br_device_pixelmap *, void **, br_uint_32 *, br_point *, ...) = (br_error(*)(br_device_pixelmap *, void **, br_uint_32 *, br_point *, ...))0x004d0ba0;
CARM95_HOOK_FUNCTION(original__M_br_device_pixelmap_null_pixelAddressQuery, _M_br_device_pixelmap_null_pixelAddressQuery)
br_error _M_br_device_pixelmap_null_pixelAddressQuery(br_device_pixelmap *self, void **pptr, br_uint_32 *pqual, br_point *p) {
    LOG_TRACE("(%p, %p, %p, %p)", self, pptr, pqual, p);

    (void)self;
    (void)pptr;
    (void)pqual;
    (void)p;

    return original__M_br_device_pixelmap_null_pixelAddressQuery(self, pptr, pqual, p);
}

static br_error(*original__M_br_device_pixelmap_null_pixelAddressSet)(br_device_pixelmap *, void *, br_uint_32 *, ...) = (br_error(*)(br_device_pixelmap *, void *, br_uint_32 *, ...))0x004d0bb0;
CARM95_HOOK_FUNCTION(original__M_br_device_pixelmap_null_pixelAddressSet, _M_br_device_pixelmap_null_pixelAddressSet)
br_error _M_br_device_pixelmap_null_pixelAddressSet(br_device_pixelmap *self, void *ptr, br_uint_32 *qual) {
    LOG_TRACE("(%p, %p, %p)", self, ptr, qual);

    (void)self;
    (void)ptr;
    (void)qual;

    return original__M_br_device_pixelmap_null_pixelAddressSet(self, ptr, qual);
}

