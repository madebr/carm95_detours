#include "pmgen.h"

#include "harness/trace.h"

#include "carm95_hooks.h"

#include "carm95_webserver.h"

#include <assert.h>

function_hook_state_t function_hook_state__M_br_device_pixelmap_gen_match = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state__M_br_device_pixelmap_gen_match)
br_error(__cdecl*_M_br_device_pixelmap_gen_match)(br_device_pixelmap *, br_device_pixelmap **, br_token_value *) = (br_error(__cdecl*)(br_device_pixelmap *, br_device_pixelmap **, br_token_value *))0x004cdb20;
br_error _M_br_device_pixelmap_gen_match_do_not_use(br_device_pixelmap *self, br_device_pixelmap **newpm, br_token_value *tv) {
    LOG_TRACE("(%p, %p, %p)", self, newpm, tv);

    (void)self;
    (void)newpm;
    (void)tv;

    if (function_hook_state__M_br_device_pixelmap_gen_match == HOOK_ENABLED) {
        assert(0 && "_M_br_device_pixelmap_gen_match_do_not_use not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}

function_hook_state_t function_hook_state__M_br_device_pixelmap_gen_copy = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state__M_br_device_pixelmap_gen_copy)
static br_error(__cdecl*original__M_br_device_pixelmap_gen_copy)(br_device_pixelmap *, br_device_pixelmap *) = (br_error(__cdecl*)(br_device_pixelmap *, br_device_pixelmap *))0x004cdb30;
CARM95_HOOK_FUNCTION(original__M_br_device_pixelmap_gen_copy, _M_br_device_pixelmap_gen_copy)
br_error __cdecl _M_br_device_pixelmap_gen_copy(br_device_pixelmap *self, br_device_pixelmap *src) {
    br_rectangle r;
    br_point p;
    LOG_TRACE("(%p, %p)", self, src);

    (void)self;
    (void)src;
    (void)r;
    (void)p;

    if (function_hook_state__M_br_device_pixelmap_gen_copy == HOOK_ENABLED) {
        assert(0 && "_M_br_device_pixelmap_gen_copy not implemented.");
        abort();
    } else {
        return original__M_br_device_pixelmap_gen_copy(self, src);
    }
}

function_hook_state_t function_hook_state__M_br_device_pixelmap_gen_copyTo = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state__M_br_device_pixelmap_gen_copyTo)
static br_error(__cdecl*original__M_br_device_pixelmap_gen_copyTo)(br_device_pixelmap *, br_device_pixelmap *) = (br_error(__cdecl*)(br_device_pixelmap *, br_device_pixelmap *))0x004cdba0;
CARM95_HOOK_FUNCTION(original__M_br_device_pixelmap_gen_copyTo, _M_br_device_pixelmap_gen_copyTo)
br_error __cdecl _M_br_device_pixelmap_gen_copyTo(br_device_pixelmap *self, br_device_pixelmap *src) {
    br_rectangle r;
    br_point p;
    LOG_TRACE("(%p, %p)", self, src);

    (void)self;
    (void)src;
    (void)r;
    (void)p;

    if (function_hook_state__M_br_device_pixelmap_gen_copyTo == HOOK_ENABLED) {
        assert(0 && "_M_br_device_pixelmap_gen_copyTo not implemented.");
        abort();
    } else {
        return original__M_br_device_pixelmap_gen_copyTo(self, src);
    }
}

function_hook_state_t function_hook_state__M_br_device_pixelmap_gen_copyFrom = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state__M_br_device_pixelmap_gen_copyFrom)
static br_error(__cdecl*original__M_br_device_pixelmap_gen_copyFrom)(br_device_pixelmap *, br_device_pixelmap *) = (br_error(__cdecl*)(br_device_pixelmap *, br_device_pixelmap *))0x004cdc10;
CARM95_HOOK_FUNCTION(original__M_br_device_pixelmap_gen_copyFrom, _M_br_device_pixelmap_gen_copyFrom)
br_error __cdecl _M_br_device_pixelmap_gen_copyFrom(br_device_pixelmap *self, br_device_pixelmap *src) {
    br_rectangle r;
    br_point p;
    LOG_TRACE("(%p, %p)", self, src);

    (void)self;
    (void)src;
    (void)r;
    (void)p;

    if (function_hook_state__M_br_device_pixelmap_gen_copyFrom == HOOK_ENABLED) {
        assert(0 && "_M_br_device_pixelmap_gen_copyFrom not implemented.");
        abort();
    } else {
        return original__M_br_device_pixelmap_gen_copyFrom(self, src);
    }
}

function_hook_state_t function_hook_state__M_br_device_pixelmap_gen_fill = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state__M_br_device_pixelmap_gen_fill)
static br_error(__cdecl*original__M_br_device_pixelmap_gen_fill)(br_device_pixelmap *, br_uint_32) = (br_error(__cdecl*)(br_device_pixelmap *, br_uint_32))0x004cdc80;
CARM95_HOOK_FUNCTION(original__M_br_device_pixelmap_gen_fill, _M_br_device_pixelmap_gen_fill)
br_error __cdecl _M_br_device_pixelmap_gen_fill(br_device_pixelmap *self, br_uint_32 colour) {
    br_rectangle r;
    LOG_TRACE("(%p, %u)", self, colour);

    (void)self;
    (void)colour;
    (void)r;

    if (function_hook_state__M_br_device_pixelmap_gen_fill == HOOK_ENABLED) {
        assert(0 && "_M_br_device_pixelmap_gen_fill not implemented.");
        abort();
    } else {
        return original__M_br_device_pixelmap_gen_fill(self, colour);
    }
}

function_hook_state_t function_hook_state__M_br_device_pixelmap_gen_doubleBuffer = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state__M_br_device_pixelmap_gen_doubleBuffer)
static br_error(__cdecl*original__M_br_device_pixelmap_gen_doubleBuffer)(br_device_pixelmap *, br_device_pixelmap *) = (br_error(__cdecl*)(br_device_pixelmap *, br_device_pixelmap *))0x004cdcd0;
CARM95_HOOK_FUNCTION(original__M_br_device_pixelmap_gen_doubleBuffer, _M_br_device_pixelmap_gen_doubleBuffer)
br_error __cdecl _M_br_device_pixelmap_gen_doubleBuffer(br_device_pixelmap *self, br_device_pixelmap *src) {
    br_rectangle s;
    br_rectangle d;
    LOG_TRACE("(%p, %p)", self, src);

    (void)self;
    (void)src;
    (void)s;
    (void)d;

    if (function_hook_state__M_br_device_pixelmap_gen_doubleBuffer == HOOK_ENABLED) {
        assert(0 && "_M_br_device_pixelmap_gen_doubleBuffer not implemented.");
        abort();
    } else {
        return original__M_br_device_pixelmap_gen_doubleBuffer(self, src);
    }
}

function_hook_state_t function_hook_state__M_br_device_pixelmap_gen_copyDirty = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state__M_br_device_pixelmap_gen_copyDirty)
static br_error(__cdecl*original__M_br_device_pixelmap_gen_copyDirty)(br_device_pixelmap *, br_device_pixelmap *, br_rectangle *, br_int_32) = (br_error(__cdecl*)(br_device_pixelmap *, br_device_pixelmap *, br_rectangle *, br_int_32))0x004cdd70;
CARM95_HOOK_FUNCTION(original__M_br_device_pixelmap_gen_copyDirty, _M_br_device_pixelmap_gen_copyDirty)
br_error __cdecl _M_br_device_pixelmap_gen_copyDirty(br_device_pixelmap *self, br_device_pixelmap *src, br_rectangle *dirty, br_int_32 num_rects) {
    int i;
    br_point p;
    br_error e;
    LOG_TRACE("(%p, %p, %p, %d)", self, src, dirty, num_rects);

    (void)self;
    (void)src;
    (void)dirty;
    (void)num_rects;
    (void)i;
    (void)p;
    (void)e;

    if (function_hook_state__M_br_device_pixelmap_gen_copyDirty == HOOK_ENABLED) {
        assert(0 && "_M_br_device_pixelmap_gen_copyDirty not implemented.");
        abort();
    } else {
        return original__M_br_device_pixelmap_gen_copyDirty(self, src, dirty, num_rects);
    }
}

function_hook_state_t function_hook_state__M_br_device_pixelmap_gen_copyToDirty = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state__M_br_device_pixelmap_gen_copyToDirty)
static br_error(__cdecl*original__M_br_device_pixelmap_gen_copyToDirty)(br_device_pixelmap *, br_device_pixelmap *, br_rectangle *, br_int_32) = (br_error(__cdecl*)(br_device_pixelmap *, br_device_pixelmap *, br_rectangle *, br_int_32))0x004cddf0;
CARM95_HOOK_FUNCTION(original__M_br_device_pixelmap_gen_copyToDirty, _M_br_device_pixelmap_gen_copyToDirty)
br_error __cdecl _M_br_device_pixelmap_gen_copyToDirty(br_device_pixelmap *self, br_device_pixelmap *src, br_rectangle *dirty, br_int_32 num_rects) {
    int i;
    br_point p;
    br_error e;
    LOG_TRACE("(%p, %p, %p, %d)", self, src, dirty, num_rects);

    (void)self;
    (void)src;
    (void)dirty;
    (void)num_rects;
    (void)i;
    (void)p;
    (void)e;

    if (function_hook_state__M_br_device_pixelmap_gen_copyToDirty == HOOK_ENABLED) {
        assert(0 && "_M_br_device_pixelmap_gen_copyToDirty not implemented.");
        abort();
    } else {
        return original__M_br_device_pixelmap_gen_copyToDirty(self, src, dirty, num_rects);
    }
}

function_hook_state_t function_hook_state__M_br_device_pixelmap_gen_copyFromDirty = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state__M_br_device_pixelmap_gen_copyFromDirty)
static br_error(__cdecl*original__M_br_device_pixelmap_gen_copyFromDirty)(br_device_pixelmap *, br_device_pixelmap *, br_rectangle *, br_int_32) = (br_error(__cdecl*)(br_device_pixelmap *, br_device_pixelmap *, br_rectangle *, br_int_32))0x004cde70;
CARM95_HOOK_FUNCTION(original__M_br_device_pixelmap_gen_copyFromDirty, _M_br_device_pixelmap_gen_copyFromDirty)
br_error __cdecl _M_br_device_pixelmap_gen_copyFromDirty(br_device_pixelmap *self, br_device_pixelmap *src, br_rectangle *dirty, br_int_32 num_rects) {
    int i;
    br_point p;
    br_error e;
    LOG_TRACE("(%p, %p, %p, %d)", self, src, dirty, num_rects);

    (void)self;
    (void)src;
    (void)dirty;
    (void)num_rects;
    (void)i;
    (void)p;
    (void)e;

    if (function_hook_state__M_br_device_pixelmap_gen_copyFromDirty == HOOK_ENABLED) {
        assert(0 && "_M_br_device_pixelmap_gen_copyFromDirty not implemented.");
        abort();
    } else {
        return original__M_br_device_pixelmap_gen_copyFromDirty(self, src, dirty, num_rects);
    }
}

function_hook_state_t function_hook_state__M_br_device_pixelmap_gen_fillDirty = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state__M_br_device_pixelmap_gen_fillDirty)
static br_error(__cdecl*original__M_br_device_pixelmap_gen_fillDirty)(br_device_pixelmap *, br_uint_32, br_rectangle *, br_int_32) = (br_error(__cdecl*)(br_device_pixelmap *, br_uint_32, br_rectangle *, br_int_32))0x004cdef0;
CARM95_HOOK_FUNCTION(original__M_br_device_pixelmap_gen_fillDirty, _M_br_device_pixelmap_gen_fillDirty)
br_error __cdecl _M_br_device_pixelmap_gen_fillDirty(br_device_pixelmap *self, br_uint_32 colour, br_rectangle *dirty, br_int_32 num_rects) {
    int i;
    br_error e;
    LOG_TRACE("(%p, %u, %p, %d)", self, colour, dirty, num_rects);

    (void)self;
    (void)colour;
    (void)dirty;
    (void)num_rects;
    (void)i;
    (void)e;

    if (function_hook_state__M_br_device_pixelmap_gen_fillDirty == HOOK_ENABLED) {
        assert(0 && "_M_br_device_pixelmap_gen_fillDirty not implemented.");
        abort();
    } else {
        return original__M_br_device_pixelmap_gen_fillDirty(self, colour, dirty, num_rects);
    }
}

function_hook_state_t function_hook_state__M_br_device_pixelmap_gen_doubleBufferDirty = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state__M_br_device_pixelmap_gen_doubleBufferDirty)
static br_error(__cdecl*original__M_br_device_pixelmap_gen_doubleBufferDirty)(br_device_pixelmap *, br_device_pixelmap *, br_rectangle *, br_int_32) = (br_error(__cdecl*)(br_device_pixelmap *, br_device_pixelmap *, br_rectangle *, br_int_32))0x004cdf30;
CARM95_HOOK_FUNCTION(original__M_br_device_pixelmap_gen_doubleBufferDirty, _M_br_device_pixelmap_gen_doubleBufferDirty)
br_error __cdecl _M_br_device_pixelmap_gen_doubleBufferDirty(br_device_pixelmap *self, br_device_pixelmap *src, br_rectangle *dirty, br_int_32 num_rects) {
    int i;
    br_point p;
    br_error e;
    LOG_TRACE("(%p, %p, %p, %d)", self, src, dirty, num_rects);

    (void)self;
    (void)src;
    (void)dirty;
    (void)num_rects;
    (void)i;
    (void)p;
    (void)e;

    if (function_hook_state__M_br_device_pixelmap_gen_doubleBufferDirty == HOOK_ENABLED) {
        assert(0 && "_M_br_device_pixelmap_gen_doubleBufferDirty not implemented.");
        abort();
    } else {
        return original__M_br_device_pixelmap_gen_doubleBufferDirty(self, src, dirty, num_rects);
    }
}

function_hook_state_t function_hook_state__M_br_device_pixelmap_gen_rectangle = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state__M_br_device_pixelmap_gen_rectangle)
static br_error(__cdecl*original__M_br_device_pixelmap_gen_rectangle)(br_device_pixelmap *, br_rectangle *, br_uint_32) = (br_error(__cdecl*)(br_device_pixelmap *, br_rectangle *, br_uint_32))0x004cdfb0;
CARM95_HOOK_FUNCTION(original__M_br_device_pixelmap_gen_rectangle, _M_br_device_pixelmap_gen_rectangle)
br_error __cdecl _M_br_device_pixelmap_gen_rectangle(br_device_pixelmap *self, br_rectangle *rect, br_uint_32 colour) {
    br_point tl;
    br_point tr;
    br_point bl;
    br_point br;
    br_error e;
    LOG_TRACE("(%p, %p, %u)", self, rect, colour);

    (void)self;
    (void)rect;
    (void)colour;
    (void)tl;
    (void)tr;
    (void)bl;
    (void)br;
    (void)e;

    if (function_hook_state__M_br_device_pixelmap_gen_rectangle == HOOK_ENABLED) {
        assert(0 && "_M_br_device_pixelmap_gen_rectangle not implemented.");
        abort();
    } else {
        return original__M_br_device_pixelmap_gen_rectangle(self, rect, colour);
    }
}

function_hook_state_t function_hook_state__M_br_device_pixelmap_gen_rectangle2 = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state__M_br_device_pixelmap_gen_rectangle2)
static br_error(__cdecl*original__M_br_device_pixelmap_gen_rectangle2)(br_device_pixelmap *, br_rectangle *, br_uint_32, br_uint_32) = (br_error(__cdecl*)(br_device_pixelmap *, br_rectangle *, br_uint_32, br_uint_32))0x004ce080;
CARM95_HOOK_FUNCTION(original__M_br_device_pixelmap_gen_rectangle2, _M_br_device_pixelmap_gen_rectangle2)
br_error __cdecl _M_br_device_pixelmap_gen_rectangle2(br_device_pixelmap *self, br_rectangle *rect, br_uint_32 colour_tl, br_uint_32 colour_br) {
    br_point tl;
    br_point tr;
    br_point bl;
    br_point br;
    br_error e;
    LOG_TRACE("(%p, %p, %u, %u)", self, rect, colour_tl, colour_br);

    (void)self;
    (void)rect;
    (void)colour_tl;
    (void)colour_br;
    (void)tl;
    (void)tr;
    (void)bl;
    (void)br;
    (void)e;

    if (function_hook_state__M_br_device_pixelmap_gen_rectangle2 == HOOK_ENABLED) {
        assert(0 && "_M_br_device_pixelmap_gen_rectangle2 not implemented.");
        abort();
    } else {
        return original__M_br_device_pixelmap_gen_rectangle2(self, rect, colour_tl, colour_br);
    }
}

function_hook_state_t function_hook_state__M_br_device_pixelmap_gen_line = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state__M_br_device_pixelmap_gen_line)
static br_error(__cdecl*original__M_br_device_pixelmap_gen_line)(br_device_pixelmap *, br_point *, br_point *, br_uint_32) = (br_error(__cdecl*)(br_device_pixelmap *, br_point *, br_point *, br_uint_32))0x004ce150;
CARM95_HOOK_FUNCTION(original__M_br_device_pixelmap_gen_line, _M_br_device_pixelmap_gen_line)
br_error __cdecl _M_br_device_pixelmap_gen_line(br_device_pixelmap *self, br_point *s, br_point *e, br_uint_32 colour) {
    int dx;
    int dy;
    int incr1;
    int incr2;
    int D;
    int x;
    int y;
    int xend;
    int c;
    int pixels_left;
    int x1;
    int y1;
    int sign_x;
    int sign_y;
    int step;
    int reverse;
    int i;
    br_point as;
    br_point ae;
    br_point p;
    LOG_TRACE("(%p, %p, %p, %u)", self, s, e, colour);

    (void)self;
    (void)s;
    (void)e;
    (void)colour;
    (void)dx;
    (void)dy;
    (void)incr1;
    (void)incr2;
    (void)D;
    (void)x;
    (void)y;
    (void)xend;
    (void)c;
    (void)pixels_left;
    (void)x1;
    (void)y1;
    (void)sign_x;
    (void)sign_y;
    (void)step;
    (void)reverse;
    (void)i;
    (void)as;
    (void)ae;
    (void)p;

    if (function_hook_state__M_br_device_pixelmap_gen_line == HOOK_ENABLED) {
        assert(0 && "_M_br_device_pixelmap_gen_line not implemented.");
        abort();
    } else {
        return original__M_br_device_pixelmap_gen_line(self, s, e, colour);
    }
}

function_hook_state_t function_hook_state__M_br_device_pixelmap_gen_text = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state__M_br_device_pixelmap_gen_text)
static br_error(__cdecl*original__M_br_device_pixelmap_gen_text)(br_device_pixelmap *, br_point *, br_font *, char *, br_uint_32) = (br_error(__cdecl*)(br_device_pixelmap *, br_point *, br_font *, char *, br_uint_32))0x004cef80;
CARM95_HOOK_FUNCTION(original__M_br_device_pixelmap_gen_text, _M_br_device_pixelmap_gen_text)
br_error __cdecl _M_br_device_pixelmap_gen_text(br_device_pixelmap *self, br_point *point, br_font *font, char *text, br_uint_32 colour) {
    br_rectangle r;
    br_point p;
    br_int_32 x;
    br_int_32 y;
    br_int_32 s_stride;
    LOG_TRACE("(%p, %p, %p, \"%s\", %u)", self, point, font, text, colour);

    (void)self;
    (void)point;
    (void)font;
    (void)text;
    (void)colour;
    (void)r;
    (void)p;
    (void)x;
    (void)y;
    (void)s_stride;

    if (function_hook_state__M_br_device_pixelmap_gen_text == HOOK_ENABLED) {
        assert(0 && "_M_br_device_pixelmap_gen_text not implemented.");
        abort();
    } else {
        return original__M_br_device_pixelmap_gen_text(self, point, font, text, colour);
    }
}

function_hook_state_t function_hook_state__M_br_device_pixelmap_gen_textBounds = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state__M_br_device_pixelmap_gen_textBounds)
static br_error(__cdecl*original__M_br_device_pixelmap_gen_textBounds)(br_device_pixelmap *, br_rectangle *, br_font *, char *) = (br_error(__cdecl*)(br_device_pixelmap *, br_rectangle *, br_font *, char *))0x004cf130;
CARM95_HOOK_FUNCTION(original__M_br_device_pixelmap_gen_textBounds, _M_br_device_pixelmap_gen_textBounds)
br_error __cdecl _M_br_device_pixelmap_gen_textBounds(br_device_pixelmap *self, br_rectangle *rect, br_font *font, char *text) {
    int i;
    int j;
    LOG_TRACE("(%p, %p, %p, \"%s\")", self, rect, font, text);

    (void)self;
    (void)rect;
    (void)font;
    (void)text;
    (void)i;
    (void)j;

    if (function_hook_state__M_br_device_pixelmap_gen_textBounds == HOOK_ENABLED) {
        assert(0 && "_M_br_device_pixelmap_gen_textBounds not implemented.");
        abort();
    } else {
        return original__M_br_device_pixelmap_gen_textBounds(self, rect, font, text);
    }
}

function_hook_state_t function_hook_state__M_br_device_pixelmap_gen_copyBits = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state__M_br_device_pixelmap_gen_copyBits)
static br_error(__cdecl*original__M_br_device_pixelmap_gen_copyBits)(br_device_pixelmap *, br_point *, br_uint_8 *, br_uint_16, br_rectangle *, br_uint_32) = (br_error(__cdecl*)(br_device_pixelmap *, br_point *, br_uint_8 *, br_uint_16, br_rectangle *, br_uint_32))0x004cf1c0;
CARM95_HOOK_FUNCTION(original__M_br_device_pixelmap_gen_copyBits, _M_br_device_pixelmap_gen_copyBits)
br_error __cdecl _M_br_device_pixelmap_gen_copyBits(br_device_pixelmap *self, br_point *point, br_uint_8 *src, br_uint_16 s_stride, br_rectangle *bit_rect, br_uint_32 colour) {
    br_int_32 x;
    br_int_32 y;
    br_point p;
    LOG_TRACE("(%p, %p, %p, %u, %p, %u)", self, point, src, s_stride, bit_rect, colour);

    (void)self;
    (void)point;
    (void)src;
    (void)s_stride;
    (void)bit_rect;
    (void)colour;
    (void)x;
    (void)y;
    (void)p;

    if (function_hook_state__M_br_device_pixelmap_gen_copyBits == HOOK_ENABLED) {
        assert(0 && "_M_br_device_pixelmap_gen_copyBits not implemented.");
        abort();
    } else {
        return original__M_br_device_pixelmap_gen_copyBits(self, point, src, s_stride, bit_rect, colour);
    }
}

function_hook_state_t function_hook_state__M_br_device_pixelmap_gen_flush = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state__M_br_device_pixelmap_gen_flush)
br_error(__cdecl*_M_br_device_pixelmap_gen_flush)(struct br_device_pixelmap *) = (br_error(__cdecl*)(struct br_device_pixelmap *))0x004cf2b0;
br_error _M_br_device_pixelmap_gen_flush_do_not_use(struct br_device_pixelmap *self) {
    LOG_TRACE("(%p)", self);

    (void)self;

    if (function_hook_state__M_br_device_pixelmap_gen_flush == HOOK_ENABLED) {
        assert(0 && "_M_br_device_pixelmap_gen_flush_do_not_use not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}

function_hook_state_t function_hook_state__M_br_device_pixelmap_gen_synchronise = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state__M_br_device_pixelmap_gen_synchronise)
br_error(__cdecl*_M_br_device_pixelmap_gen_synchronise)(struct br_device_pixelmap *, br_token, br_boolean) = (br_error(__cdecl*)(struct br_device_pixelmap *, br_token, br_boolean))0x004cf2c0;
br_error _M_br_device_pixelmap_gen_synchronise_do_not_use(struct br_device_pixelmap *self, br_token sync_type, br_boolean block) {
    LOG_TRACE("(%p, %d, %d)", self, sync_type, block);

    (void)self;
    (void)sync_type;
    (void)block;

    if (function_hook_state__M_br_device_pixelmap_gen_synchronise == HOOK_ENABLED) {
        assert(0 && "_M_br_device_pixelmap_gen_synchronise_do_not_use not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}

function_hook_state_t function_hook_state__M_br_device_pixelmap_gen_directLock = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state__M_br_device_pixelmap_gen_directLock)
br_error(__cdecl*_M_br_device_pixelmap_gen_directLock)(br_device_pixelmap *, br_boolean) = (br_error(__cdecl*)(br_device_pixelmap *, br_boolean))0x004cf2d0;
br_error _M_br_device_pixelmap_gen_directLock_do_not_use(br_device_pixelmap *self, br_boolean block) {
    LOG_TRACE("(%p, %d)", self, block);

    (void)self;
    (void)block;

    if (function_hook_state__M_br_device_pixelmap_gen_directLock == HOOK_ENABLED) {
        assert(0 && "_M_br_device_pixelmap_gen_directLock_do_not_use not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}

function_hook_state_t function_hook_state__M_br_device_pixelmap_gen_directUnlock = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state__M_br_device_pixelmap_gen_directUnlock)
br_error(__cdecl*_M_br_device_pixelmap_gen_directUnlock)(br_device_pixelmap *) = (br_error(__cdecl*)(br_device_pixelmap *))0x004cf2e0;
br_error _M_br_device_pixelmap_gen_directUnlock_do_not_use(br_device_pixelmap *self) {
    LOG_TRACE("(%p)", self);

    (void)self;

    if (function_hook_state__M_br_device_pixelmap_gen_directUnlock == HOOK_ENABLED) {
        assert(0 && "_M_br_device_pixelmap_gen_directUnlock_do_not_use not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}

