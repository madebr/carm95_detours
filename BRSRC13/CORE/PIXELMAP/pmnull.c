#include "pmnull.h"

#include "harness/trace.h"

#include "carm95_hooks.h"


br_error(__stdcall*_M_br_device_pixelmap_null_resize)(br_device_pixelmap *, br_int_32, br_int_32) = (br_error(__stdcall*)(br_device_pixelmap *, br_int_32, br_int_32))0x004d0a80;
br_error _M_br_device_pixelmap_null_resize_do_not_use(br_device_pixelmap *self, br_int_32 width, br_int_32 height) {
    LOG_TRACE("(%p, %d, %d)", self, width, height);

    (void)self;
    (void)width;
    (void)height;

    NOT_IMPLEMENTED();
}

br_error(__stdcall*_M_br_device_pixelmap_null_copyTo)(br_device_pixelmap *, br_device_pixelmap *) = (br_error(__stdcall*)(br_device_pixelmap *, br_device_pixelmap *))0x004d0a90;
br_error _M_br_device_pixelmap_null_copyTo_do_not_use(br_device_pixelmap *self, br_device_pixelmap *src) {
    LOG_TRACE("(%p, %p)", self, src);

    (void)self;
    (void)src;

    NOT_IMPLEMENTED();
}

br_error(__stdcall*_M_br_device_pixelmap_null_copyFrom)(br_device_pixelmap *, br_device_pixelmap *) = (br_error(__stdcall*)(br_device_pixelmap *, br_device_pixelmap *))0x004d0aa0;
br_error _M_br_device_pixelmap_null_copyFrom_do_not_use(br_device_pixelmap *self, br_device_pixelmap *src) {
    LOG_TRACE("(%p, %p)", self, src);

    (void)self;
    (void)src;

    NOT_IMPLEMENTED();
}

br_error(__stdcall*_M_br_device_pixelmap_null_fill)(br_device_pixelmap *, br_uint_32) = (br_error(__stdcall*)(br_device_pixelmap *, br_uint_32))0x004d0ab0;
br_error _M_br_device_pixelmap_null_fill_do_not_use(br_device_pixelmap *self, br_uint_32 colour) {
    LOG_TRACE("(%p, %u)", self, colour);

    (void)self;
    (void)colour;

    NOT_IMPLEMENTED();
}

br_error(__stdcall*_M_br_device_pixelmap_null_doubleBuffer)(br_device_pixelmap *, br_device_pixelmap *) = (br_error(__stdcall*)(br_device_pixelmap *, br_device_pixelmap *))0x004d0ac0;
br_error _M_br_device_pixelmap_null_doubleBuffer_do_not_use(br_device_pixelmap *self, br_device_pixelmap *src) {
    LOG_TRACE("(%p, %p)", self, src);

    (void)self;
    (void)src;

    NOT_IMPLEMENTED();
}

br_error(__stdcall*_M_br_device_pixelmap_null_copyDirty)(br_device_pixelmap *, br_device_pixelmap *, br_rectangle *, br_int_32) = (br_error(__stdcall*)(br_device_pixelmap *, br_device_pixelmap *, br_rectangle *, br_int_32))0x004d0ad0;
br_error _M_br_device_pixelmap_null_copyDirty_do_not_use(br_device_pixelmap *self, br_device_pixelmap *src, br_rectangle *dirty, br_int_32 num_rects) {
    LOG_TRACE("(%p, %p, %p, %d)", self, src, dirty, num_rects);

    (void)self;
    (void)src;
    (void)dirty;
    (void)num_rects;

    NOT_IMPLEMENTED();
}

br_error(__stdcall*_M_br_device_pixelmap_null_copyToDirty)(br_device_pixelmap *, br_device_pixelmap *, br_rectangle *, br_int_32) = (br_error(__stdcall*)(br_device_pixelmap *, br_device_pixelmap *, br_rectangle *, br_int_32))0x004d0ae0;
br_error _M_br_device_pixelmap_null_copyToDirty_do_not_use(br_device_pixelmap *self, br_device_pixelmap *src, br_rectangle *dirty, br_int_32 num_rects) {
    LOG_TRACE("(%p, %p, %p, %d)", self, src, dirty, num_rects);

    (void)self;
    (void)src;
    (void)dirty;
    (void)num_rects;

    NOT_IMPLEMENTED();
}

br_error(__stdcall*_M_br_device_pixelmap_null_copyFromDirty)(br_device_pixelmap *, br_device_pixelmap *, br_rectangle *, br_int_32) = (br_error(__stdcall*)(br_device_pixelmap *, br_device_pixelmap *, br_rectangle *, br_int_32))0x004d0af0;
br_error _M_br_device_pixelmap_null_copyFromDirty_do_not_use(br_device_pixelmap *self, br_device_pixelmap *src, br_rectangle *dirty, br_int_32 num_rects) {
    LOG_TRACE("(%p, %p, %p, %d)", self, src, dirty, num_rects);

    (void)self;
    (void)src;
    (void)dirty;
    (void)num_rects;

    NOT_IMPLEMENTED();
}

br_error(__stdcall*_M_br_device_pixelmap_null_fillDirty)(br_device_pixelmap *, br_uint_32, br_rectangle *, br_int_32) = (br_error(__stdcall*)(br_device_pixelmap *, br_uint_32, br_rectangle *, br_int_32))0x004d0b00;
br_error _M_br_device_pixelmap_null_fillDirty_do_not_use(br_device_pixelmap *self, br_uint_32 colour, br_rectangle *dirty, br_int_32 num_rects) {
    LOG_TRACE("(%p, %u, %p, %d)", self, colour, dirty, num_rects);

    (void)self;
    (void)colour;
    (void)dirty;
    (void)num_rects;

    NOT_IMPLEMENTED();
}

br_error(__stdcall*_M_br_device_pixelmap_null_doubleBufferDirty)(br_device_pixelmap *, br_device_pixelmap *, br_rectangle *, br_int_32) = (br_error(__stdcall*)(br_device_pixelmap *, br_device_pixelmap *, br_rectangle *, br_int_32))0x004d0b10;
br_error _M_br_device_pixelmap_null_doubleBufferDirty_do_not_use(br_device_pixelmap *self, br_device_pixelmap *src, br_rectangle *dirty, br_int_32 num_rects) {
    LOG_TRACE("(%p, %p, %p, %d)", self, src, dirty, num_rects);

    (void)self;
    (void)src;
    (void)dirty;
    (void)num_rects;

    NOT_IMPLEMENTED();
}

br_error(__stdcall*_M_br_device_pixelmap_null_rectangleCopyTo)(br_device_pixelmap *, br_point *, br_device_pixelmap *, br_rectangle *) = (br_error(__stdcall*)(br_device_pixelmap *, br_point *, br_device_pixelmap *, br_rectangle *))0x004d0b20;
br_error _M_br_device_pixelmap_null_rectangleCopyTo_do_not_use(br_device_pixelmap *self, br_point *p, br_device_pixelmap *src, br_rectangle *r) {
    LOG_TRACE("(%p, %p, %p, %p)", self, p, src, r);

    (void)self;
    (void)p;
    (void)src;
    (void)r;

    NOT_IMPLEMENTED();
}

br_error(__stdcall*_M_br_device_pixelmap_null_rectangleCopyFrom)(br_device_pixelmap *, br_point *, br_device_pixelmap *, br_rectangle *) = (br_error(__stdcall*)(br_device_pixelmap *, br_point *, br_device_pixelmap *, br_rectangle *))0x004d0b30;
br_error _M_br_device_pixelmap_null_rectangleCopyFrom_do_not_use(br_device_pixelmap *self, br_point *p, br_device_pixelmap *mem, br_rectangle *r) {
    LOG_TRACE("(%p, %p, %p, %p)", self, p, mem, r);

    (void)self;
    (void)p;
    (void)mem;
    (void)r;

    NOT_IMPLEMENTED();
}

br_error(__stdcall*_M_br_device_pixelmap_null_rectangleStretchCopyTo)(br_device_pixelmap *, br_rectangle *, br_device_pixelmap *, br_rectangle *) = (br_error(__stdcall*)(br_device_pixelmap *, br_rectangle *, br_device_pixelmap *, br_rectangle *))0x004d0b40;
br_error _M_br_device_pixelmap_null_rectangleStretchCopyTo_do_not_use(br_device_pixelmap *self, br_rectangle *d, br_device_pixelmap *src, br_rectangle *s) {
    LOG_TRACE("(%p, %p, %p, %p)", self, d, src, s);

    (void)self;
    (void)d;
    (void)src;
    (void)s;

    NOT_IMPLEMENTED();
}

br_error(__stdcall*_M_br_device_pixelmap_null_rectangleStretchCopyFrom)(br_device_pixelmap *, br_rectangle *, br_device_pixelmap *, br_rectangle *) = (br_error(__stdcall*)(br_device_pixelmap *, br_rectangle *, br_device_pixelmap *, br_rectangle *))0x004d0b50;
br_error _M_br_device_pixelmap_null_rectangleStretchCopyFrom_do_not_use(br_device_pixelmap *self, br_rectangle *d, br_device_pixelmap *src, br_rectangle *s) {
    LOG_TRACE("(%p, %p, %p, %p)", self, d, src, s);

    (void)self;
    (void)d;
    (void)src;
    (void)s;

    NOT_IMPLEMENTED();
}

br_error(__stdcall*_M_br_device_pixelmap_null_rectangleFill)(br_device_pixelmap *, br_rectangle *, br_uint_32) = (br_error(__stdcall*)(br_device_pixelmap *, br_rectangle *, br_uint_32))0x004d0b60;
br_error _M_br_device_pixelmap_null_rectangleFill_do_not_use(br_device_pixelmap *self, br_rectangle *rect, br_uint_32 colour) {
    LOG_TRACE("(%p, %p, %u)", self, rect, colour);

    (void)self;
    (void)rect;
    (void)colour;

    NOT_IMPLEMENTED();
}

br_error(__stdcall*_M_br_device_pixelmap_null_pixelSet)(br_device_pixelmap *, br_point *, br_uint_32) = (br_error(__stdcall*)(br_device_pixelmap *, br_point *, br_uint_32))0x004d0b70;
br_error _M_br_device_pixelmap_null_pixelSet_do_not_use(br_device_pixelmap *self, br_point *p, br_uint_32 colour) {
    LOG_TRACE("(%p, %p, %u)", self, p, colour);

    (void)self;
    (void)p;
    (void)colour;

    NOT_IMPLEMENTED();
}

br_error(__stdcall*_M_br_device_pixelmap_null_copyBits)(br_device_pixelmap *, br_point *, br_uint_8 *, br_uint_16, br_rectangle *, br_uint_32) = (br_error(__stdcall*)(br_device_pixelmap *, br_point *, br_uint_8 *, br_uint_16, br_rectangle *, br_uint_32))0x004d0b80;
br_error _M_br_device_pixelmap_null_copyBits_do_not_use(br_device_pixelmap *self, br_point *point, br_uint_8 *src, br_uint_16 s_stride, br_rectangle *bit_rect, br_uint_32 colour) {
    LOG_TRACE("(%p, %p, %p, %u, %p, %u)", self, point, src, s_stride, bit_rect, colour);

    (void)self;
    (void)point;
    (void)src;
    (void)s_stride;
    (void)bit_rect;
    (void)colour;

    NOT_IMPLEMENTED();
}

br_error(__stdcall*_M_br_device_pixelmap_null_pixelQuery)(br_device_pixelmap *, br_uint_32 *, br_point *) = (br_error(__stdcall*)(br_device_pixelmap *, br_uint_32 *, br_point *))0x004d0b90;
br_error _M_br_device_pixelmap_null_pixelQuery_do_not_use(br_device_pixelmap *self, br_uint_32 *pcolour, br_point *p) {
    LOG_TRACE("(%p, %p, %p)", self, pcolour, p);

    (void)self;
    (void)pcolour;
    (void)p;

    NOT_IMPLEMENTED();
}

br_error(__stdcall*_M_br_device_pixelmap_null_pixelAddressQuery)(br_device_pixelmap *, void **, br_uint_32 *, br_point *) = (br_error(__stdcall*)(br_device_pixelmap *, void **, br_uint_32 *, br_point *))0x004d0ba0;
br_error _M_br_device_pixelmap_null_pixelAddressQuery_do_not_use(br_device_pixelmap *self, void **pptr, br_uint_32 *pqual, br_point *p) {
    LOG_TRACE("(%p, %p, %p, %p)", self, pptr, pqual, p);

    (void)self;
    (void)pptr;
    (void)pqual;
    (void)p;

    NOT_IMPLEMENTED();
}

br_error(__stdcall*_M_br_device_pixelmap_null_pixelAddressSet)(br_device_pixelmap *, void *, br_uint_32 *) = (br_error(__stdcall*)(br_device_pixelmap *, void *, br_uint_32 *))0x004d0bb0;
br_error _M_br_device_pixelmap_null_pixelAddressSet_do_not_use(br_device_pixelmap *self, void *ptr, br_uint_32 *qual) {
    LOG_TRACE("(%p, %p, %p)", self, ptr, qual);

    (void)self;
    (void)ptr;
    (void)qual;

    NOT_IMPLEMENTED();
}

