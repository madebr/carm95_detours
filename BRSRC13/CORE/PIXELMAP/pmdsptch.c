#include "pmdsptch.h"

#include "harness/trace.h"

#include "carm95_hooks.h"


static br_pixelmap *(__cdecl*original_BrPixelmapAllocateSub)(br_pixelmap *, br_int_32, br_int_32, br_int_32, br_int_32) = (br_pixelmap *(__cdecl*)(br_pixelmap *, br_int_32, br_int_32, br_int_32, br_int_32))0x004c9610;
CARM95_HOOK_FUNCTION(original_BrPixelmapAllocateSub, BrPixelmapAllocateSub)
br_pixelmap* __cdecl BrPixelmapAllocateSub(br_pixelmap *src, br_int_32 x, br_int_32 y, br_int_32 w, br_int_32 h) {
    br_pixelmap *new;
    br_rectangle r;
    LOG_TRACE("(%p, %d, %d, %d, %d)", src, x, y, w, h);

    (void)src;
    (void)x;
    (void)y;
    (void)w;
    (void)h;
    (void)new;
    (void)r;

    return original_BrPixelmapAllocateSub(src, x, y, w, h);
}

static void(__cdecl*original_BrPixelmapFree)(br_pixelmap *) = (void(__cdecl*)(br_pixelmap *))0x004c9670;
CARM95_HOOK_FUNCTION(original_BrPixelmapFree, BrPixelmapFree)
void __cdecl BrPixelmapFree(br_pixelmap *src) {
    LOG_TRACE("(%p)", src);

    (void)src;

    original_BrPixelmapFree(src);
}

static br_pixelmap *(__cdecl*original_BrPixelmapResize)(br_pixelmap *, br_int_32, br_int_32) = (br_pixelmap *(__cdecl*)(br_pixelmap *, br_int_32, br_int_32))0x004c96a0;
CARM95_HOOK_FUNCTION(original_BrPixelmapResize, BrPixelmapResize)
br_pixelmap* __cdecl BrPixelmapResize(br_pixelmap *src, br_int_32 width, br_int_32 height) {
    LOG_TRACE("(%p, %d, %d)", src, width, height);

    (void)src;
    (void)width;
    (void)height;

    return original_BrPixelmapResize(src, width, height);
}

static br_pixelmap *(__cdecl*original_BrPixelmapMatch)(br_pixelmap *, br_uint_8) = (br_pixelmap *(__cdecl*)(br_pixelmap *, br_uint_8))0x004c96d0;
CARM95_HOOK_FUNCTION(original_BrPixelmapMatch, BrPixelmapMatch)
br_pixelmap* __cdecl BrPixelmapMatch(br_pixelmap *src, br_uint_8 match_type) {
    br_pixelmap *new;
    br_token_value tv[3];
    LOG_TRACE("(%p, %u)", src, match_type);

    (void)src;
    (void)match_type;
    (void)new;
    (void)tv;

    return original_BrPixelmapMatch(src, match_type);
}

static br_pixelmap *(__cdecl*original_BrPixelmapMatchSized)(br_pixelmap *, br_uint_8, br_int_32, br_int_32) = (br_pixelmap *(__cdecl*)(br_pixelmap *, br_uint_8, br_int_32, br_int_32))0x004c980c;
CARM95_HOOK_FUNCTION(original_BrPixelmapMatchSized, BrPixelmapMatchSized)
br_pixelmap* __cdecl BrPixelmapMatchSized(br_pixelmap *src, br_uint_8 match_type, br_int_32 width, br_int_32 height) {
    br_pixelmap *new;
    br_token_value tv[5];
    LOG_TRACE("(%p, %u, %d, %d)", src, match_type, width, height);

    (void)src;
    (void)match_type;
    (void)width;
    (void)height;
    (void)new;
    (void)tv;

    return original_BrPixelmapMatchSized(src, match_type, width, height);
}

static br_pixelmap *(__cdecl*original_BrPixelmapMatchTyped)(br_pixelmap *, br_uint_8, br_uint_8) = (br_pixelmap *(__cdecl*)(br_pixelmap *, br_uint_8, br_uint_8))0x004c9934;
CARM95_HOOK_FUNCTION(original_BrPixelmapMatchTyped, BrPixelmapMatchTyped)
br_pixelmap* __cdecl BrPixelmapMatchTyped(br_pixelmap *src, br_uint_8 match_type, br_uint_8 pixelmap_type) {
    br_pixelmap *new;
    br_token_value tv[4];
    LOG_TRACE("(%p, %u, %u)", src, match_type, pixelmap_type);

    (void)src;
    (void)match_type;
    (void)pixelmap_type;
    (void)new;
    (void)tv;

    return original_BrPixelmapMatchTyped(src, match_type, pixelmap_type);
}

static br_pixelmap *(__cdecl*original_BrPixelmapMatchTypedSized)(br_pixelmap *, br_uint_8, br_uint_8, br_int_32, br_int_32) = (br_pixelmap *(__cdecl*)(br_pixelmap *, br_uint_8, br_uint_8, br_int_32, br_int_32))0x004c9a4c;
CARM95_HOOK_FUNCTION(original_BrPixelmapMatchTypedSized, BrPixelmapMatchTypedSized)
br_pixelmap* __cdecl BrPixelmapMatchTypedSized(br_pixelmap *src, br_uint_8 match_type, br_uint_8 pixelmap_type, br_int_32 width, br_int_32 height) {
    br_pixelmap *new;
    br_token_value tv[6];
    LOG_TRACE("(%p, %u, %u, %d, %d)", src, match_type, pixelmap_type, width, height);

    (void)src;
    (void)match_type;
    (void)pixelmap_type;
    (void)width;
    (void)height;
    (void)new;
    (void)tv;

    return original_BrPixelmapMatchTypedSized(src, match_type, pixelmap_type, width, height);
}

static br_pixelmap *(__cdecl*original_BrPixelmapClone)(br_pixelmap *) = (br_pixelmap *(__cdecl*)(br_pixelmap *))0x004c9b90;
CARM95_HOOK_FUNCTION(original_BrPixelmapClone, BrPixelmapClone)
br_pixelmap* __cdecl BrPixelmapClone(br_pixelmap *src) {
    br_pixelmap *new;
    br_token_value tv[2];
    LOG_TRACE("(%p)", src);

    (void)src;
    (void)new;
    (void)tv;

    return original_BrPixelmapClone(src);
}

static void(__cdecl*original_BrPixelmapFill)(br_pixelmap *, br_uint_32) = (void(__cdecl*)(br_pixelmap *, br_uint_32))0x004c9bf0;
CARM95_HOOK_FUNCTION(original_BrPixelmapFill, BrPixelmapFill)
void __cdecl BrPixelmapFill(br_pixelmap *dst, br_uint_32 colour) {
    LOG_TRACE("(%p, %u)", dst, colour);

    (void)dst;
    (void)colour;

    original_BrPixelmapFill(dst, colour);
}

static void(__cdecl*original_BrPixelmapRectangle)(br_pixelmap *, br_int_32, br_int_32, br_int_32, br_int_32, br_uint_32) = (void(__cdecl*)(br_pixelmap *, br_int_32, br_int_32, br_int_32, br_int_32, br_uint_32))0x004c9c0d;
CARM95_HOOK_FUNCTION(original_BrPixelmapRectangle, BrPixelmapRectangle)
void __cdecl BrPixelmapRectangle(br_pixelmap *dst, br_int_32 x, br_int_32 y, br_int_32 w, br_int_32 h, br_uint_32 colour) {
    br_rectangle r;
    LOG_TRACE("(%p, %d, %d, %d, %d, %u)", dst, x, y, w, h, colour);

    (void)dst;
    (void)x;
    (void)y;
    (void)w;
    (void)h;
    (void)colour;
    (void)r;

    original_BrPixelmapRectangle(dst, x, y, w, h, colour);
}

static void(__cdecl*original_BrPixelmapRectangle2)(br_pixelmap *, br_int_32, br_int_32, br_int_32, br_int_32, br_uint_32, br_uint_32) = (void(__cdecl*)(br_pixelmap *, br_int_32, br_int_32, br_int_32, br_int_32, br_uint_32, br_uint_32))0x004c9c60;
CARM95_HOOK_FUNCTION(original_BrPixelmapRectangle2, BrPixelmapRectangle2)
void __cdecl BrPixelmapRectangle2(br_pixelmap *dst, br_int_32 x, br_int_32 y, br_int_32 w, br_int_32 h, br_uint_32 colour_tl, br_uint_32 colour_br) {
    br_rectangle r;
    LOG_TRACE("(%p, %d, %d, %d, %d, %u, %u)", dst, x, y, w, h, colour_tl, colour_br);

    (void)dst;
    (void)x;
    (void)y;
    (void)w;
    (void)h;
    (void)colour_tl;
    (void)colour_br;
    (void)r;

    original_BrPixelmapRectangle2(dst, x, y, w, h, colour_tl, colour_br);
}

static br_error(__stdcall*original_DispatchCopy)(br_device_pixelmap *, br_device_pixelmap *) = (br_error(__stdcall*)(br_device_pixelmap *, br_device_pixelmap *))0x004c9cb0;
CARM95_HOOK_FUNCTION(original_DispatchCopy, DispatchCopy)
br_error __stdcall DispatchCopy(br_device_pixelmap *self, br_device_pixelmap *src) {
    LOG_TRACE("(%p, %p)", self, src);

    (void)self;
    (void)src;

    return original_DispatchCopy(self, src);
}

static br_error(__stdcall*original_DispatchRectangleCopy)(br_device_pixelmap *, br_point *, br_device_pixelmap *, br_rectangle *) = (br_error(__stdcall*)(br_device_pixelmap *, br_point *, br_device_pixelmap *, br_rectangle *))0x004c9d30;
CARM95_HOOK_FUNCTION(original_DispatchRectangleCopy, DispatchRectangleCopy)
br_error __stdcall DispatchRectangleCopy(br_device_pixelmap *self, br_point *p, br_device_pixelmap *src, br_rectangle *r) {
    LOG_TRACE("(%p, %p, %p, %p)", self, p, src, r);

    (void)self;
    (void)p;
    (void)src;
    (void)r;

    return original_DispatchRectangleCopy(self, p, src, r);
}

static br_error(__cdecl*original_DispatchRectangleStretchCopy)(br_device_pixelmap *, br_rectangle *, br_device_pixelmap *, br_rectangle *) = (br_error(__cdecl*)(br_device_pixelmap *, br_rectangle *, br_device_pixelmap *, br_rectangle *))0x004c9de0;
CARM95_HOOK_FUNCTION(original_DispatchRectangleStretchCopy, DispatchRectangleStretchCopy)
br_error __cdecl DispatchRectangleStretchCopy(br_device_pixelmap *self, br_rectangle *r, br_device_pixelmap *src, br_rectangle *s) {
    LOG_TRACE("(%p, %p, %p, %p)", self, r, src, s);

    (void)self;
    (void)r;
    (void)src;
    (void)s;

    return original_DispatchRectangleStretchCopy(self, r, src, s);
}

static void(__cdecl*original_BrPixelmapRectangleCopy)(br_pixelmap *, br_int_32, br_int_32, br_pixelmap *, br_int_32, br_int_32, br_int_32, br_int_32) = (void(__cdecl*)(br_pixelmap *, br_int_32, br_int_32, br_pixelmap *, br_int_32, br_int_32, br_int_32, br_int_32))0x004c9e90;
CARM95_HOOK_FUNCTION(original_BrPixelmapRectangleCopy, BrPixelmapRectangleCopy)
void __cdecl BrPixelmapRectangleCopy(br_pixelmap *dst, br_int_32 dx, br_int_32 dy, br_pixelmap *src, br_int_32 sx, br_int_32 sy, br_int_32 w, br_int_32 h) {
    br_rectangle r;
    br_point p;
    LOG_TRACE("(%p, %d, %d, %p, %d, %d, %d, %d)", dst, dx, dy, src, sx, sy, w, h);

    (void)dst;
    (void)dx;
    (void)dy;
    (void)src;
    (void)sx;
    (void)sy;
    (void)w;
    (void)h;
    (void)r;
    (void)p;

    original_BrPixelmapRectangleCopy(dst, dx, dy, src, sx, sy, w, h);
}

static void(__cdecl*original_BrPixelmapRectangleStretchCopy)(br_pixelmap *, br_int_32, br_int_32, br_int_32, br_int_32, br_pixelmap *, br_int_32, br_int_32, br_int_32, br_int_32) = (void(__cdecl*)(br_pixelmap *, br_int_32, br_int_32, br_int_32, br_int_32, br_pixelmap *, br_int_32, br_int_32, br_int_32, br_int_32))0x004c9ee0;
CARM95_HOOK_FUNCTION(original_BrPixelmapRectangleStretchCopy, BrPixelmapRectangleStretchCopy)
void __cdecl BrPixelmapRectangleStretchCopy(br_pixelmap *dst, br_int_32 dx, br_int_32 dy, br_int_32 dw, br_int_32 dh, br_pixelmap *src, br_int_32 sx, br_int_32 sy, br_int_32 sw, br_int_32 sh) {
    br_rectangle s;
    br_rectangle d;
    LOG_TRACE("(%p, %d, %d, %d, %d, %p, %d, %d, %d, %d)", dst, dx, dy, dw, dh, src, sx, sy, sw, sh);

    (void)dst;
    (void)dx;
    (void)dy;
    (void)dw;
    (void)dh;
    (void)src;
    (void)sx;
    (void)sy;
    (void)sw;
    (void)sh;
    (void)s;
    (void)d;

    original_BrPixelmapRectangleStretchCopy(dst, dx, dy, dw, dh, src, sx, sy, sw, sh);
}

static void(__cdecl*original_BrPixelmapRectangleFill)(br_pixelmap *, br_int_32, br_int_32, br_int_32, br_int_32, br_uint_32) = (void(__cdecl*)(br_pixelmap *, br_int_32, br_int_32, br_int_32, br_int_32, br_uint_32))0x004c9f40;
CARM95_HOOK_FUNCTION(original_BrPixelmapRectangleFill, BrPixelmapRectangleFill)
void __cdecl BrPixelmapRectangleFill(br_pixelmap *dst, br_int_32 x, br_int_32 y, br_int_32 w, br_int_32 h, br_uint_32 colour) {
    br_rectangle r;
    LOG_TRACE("(%p, %d, %d, %d, %d, %u)", dst, x, y, w, h, colour);

    (void)dst;
    (void)x;
    (void)y;
    (void)w;
    (void)h;
    (void)colour;
    (void)r;

    original_BrPixelmapRectangleFill(dst, x, y, w, h, colour);
}

static void(__cdecl*original_BrPixelmapDirtyRectangleCopy)(br_pixelmap *, br_pixelmap *, br_int_32, br_int_32, br_int_32, br_int_32) = (void(__cdecl*)(br_pixelmap *, br_pixelmap *, br_int_32, br_int_32, br_int_32, br_int_32))0x004c9f89;
CARM95_HOOK_FUNCTION(original_BrPixelmapDirtyRectangleCopy, BrPixelmapDirtyRectangleCopy)
void __cdecl BrPixelmapDirtyRectangleCopy(br_pixelmap *dst, br_pixelmap *src, br_int_32 x, br_int_32 y, br_int_32 w, br_int_32 h) {
    br_rectangle r;
    br_point p;
    LOG_TRACE("(%p, %p, %d, %d, %d, %d)", dst, src, x, y, w, h);

    (void)dst;
    (void)src;
    (void)x;
    (void)y;
    (void)w;
    (void)h;
    (void)r;
    (void)p;

    original_BrPixelmapDirtyRectangleCopy(dst, src, x, y, w, h);
}

static void(__cdecl*original_BrPixelmapDirtyRectangleClear)(br_pixelmap *, br_int_32, br_int_32, br_int_32, br_int_32, br_uint_32) = (void(__cdecl*)(br_pixelmap *, br_int_32, br_int_32, br_int_32, br_int_32, br_uint_32))0x004ca05d;
CARM95_HOOK_FUNCTION(original_BrPixelmapDirtyRectangleClear, BrPixelmapDirtyRectangleClear)
void __cdecl BrPixelmapDirtyRectangleClear(br_pixelmap *dst, br_int_32 x, br_int_32 y, br_int_32 w, br_int_32 h, br_uint_32 colour) {
    br_rectangle r;
    LOG_TRACE("(%p, %d, %d, %d, %d, %u)", dst, x, y, w, h, colour);

    (void)dst;
    (void)x;
    (void)y;
    (void)w;
    (void)h;
    (void)colour;
    (void)r;

    original_BrPixelmapDirtyRectangleClear(dst, x, y, w, h, colour);
}

static void(__cdecl*original_BrPixelmapDirtyRectangleDoubleBuffer)(br_pixelmap *, br_pixelmap *, br_int_32, br_int_32, br_int_32, br_int_32) = (void(__cdecl*)(br_pixelmap *, br_pixelmap *, br_int_32, br_int_32, br_int_32, br_int_32))0x004ca0a8;
CARM95_HOOK_FUNCTION(original_BrPixelmapDirtyRectangleDoubleBuffer, BrPixelmapDirtyRectangleDoubleBuffer)
void __cdecl BrPixelmapDirtyRectangleDoubleBuffer(br_pixelmap *dst, br_pixelmap *src, br_int_32 x, br_int_32 y, br_int_32 w, br_int_32 h) {
    br_rectangle r;
    LOG_TRACE("(%p, %p, %d, %d, %d, %d)", dst, src, x, y, w, h);

    (void)dst;
    (void)src;
    (void)x;
    (void)y;
    (void)w;
    (void)h;
    (void)r;

    original_BrPixelmapDirtyRectangleDoubleBuffer(dst, src, x, y, w, h);
}

static void(__cdecl*original_BrPixelmapPixelSet)(br_pixelmap *, br_int_32, br_int_32, br_uint_32) = (void(__cdecl*)(br_pixelmap *, br_int_32, br_int_32, br_uint_32))0x004ca100;
CARM95_HOOK_FUNCTION(original_BrPixelmapPixelSet, BrPixelmapPixelSet)
void __cdecl BrPixelmapPixelSet(br_pixelmap *dst, br_int_32 x, br_int_32 y, br_uint_32 colour) {
    br_point p;
    LOG_TRACE("(%p, %d, %d, %u)", dst, x, y, colour);

    (void)dst;
    (void)x;
    (void)y;
    (void)colour;
    (void)p;

    original_BrPixelmapPixelSet(dst, x, y, colour);
}

static br_uint_32(__cdecl*original_BrPixelmapPixelGet)(br_pixelmap *, br_int_32, br_int_32) = (br_uint_32(__cdecl*)(br_pixelmap *, br_int_32, br_int_32))0x004ca13b;
CARM95_HOOK_FUNCTION(original_BrPixelmapPixelGet, BrPixelmapPixelGet)
br_uint_32 __cdecl BrPixelmapPixelGet(br_pixelmap *dst, br_int_32 x, br_int_32 y) {
    br_point p;
    br_uint_32 colour;
    LOG_TRACE("(%p, %d, %d)", dst, x, y);

    (void)dst;
    (void)x;
    (void)y;
    (void)p;
    (void)colour;

    return original_BrPixelmapPixelGet(dst, x, y);
}

static void(__cdecl*original_BrPixelmapCopy)(br_pixelmap *, br_pixelmap *) = (void(__cdecl*)(br_pixelmap *, br_pixelmap *))0x004ca180;
CARM95_HOOK_FUNCTION(original_BrPixelmapCopy, BrPixelmapCopy)
void __cdecl BrPixelmapCopy(br_pixelmap *dst, br_pixelmap *src) {
    br_rectangle s;
    br_rectangle d;
    LOG_TRACE("(%p, %p)", dst, src);

    (void)dst;
    (void)src;
    (void)s;
    (void)d;

    original_BrPixelmapCopy(dst, src);
}

static void(__cdecl*original_BrPixelmapLine)(br_pixelmap *, br_int_32, br_int_32, br_int_32, br_int_32, br_uint_32) = (void(__cdecl*)(br_pixelmap *, br_int_32, br_int_32, br_int_32, br_int_32, br_uint_32))0x004ca290;
CARM95_HOOK_FUNCTION(original_BrPixelmapLine, BrPixelmapLine)
void __cdecl BrPixelmapLine(br_pixelmap *dst, br_int_32 x1, br_int_32 y1, br_int_32 x2, br_int_32 y2, br_uint_32 colour) {
    br_point s;
    br_point e;
    LOG_TRACE("(%p, %d, %d, %d, %d, %u)", dst, x1, y1, x2, y2, colour);

    (void)dst;
    (void)x1;
    (void)y1;
    (void)x2;
    (void)y2;
    (void)colour;
    (void)s;
    (void)e;

    original_BrPixelmapLine(dst, x1, y1, x2, y2, colour);
}

static void(__cdecl*original_BrPixelmapDoubleBuffer)(br_pixelmap *, br_pixelmap *) = (void(__cdecl*)(br_pixelmap *, br_pixelmap *))0x004ca2e0;
CARM95_HOOK_FUNCTION(original_BrPixelmapDoubleBuffer, BrPixelmapDoubleBuffer)
void __cdecl BrPixelmapDoubleBuffer(br_pixelmap *dst, br_pixelmap *src) {
    LOG_TRACE("(%p, %p)", dst, src);

    (void)dst;
    (void)src;

    original_BrPixelmapDoubleBuffer(dst, src);
}

static void(__cdecl*original_BrPixelmapText)(br_pixelmap *, br_int_32, br_int_32, br_uint_32, br_font *, char *) = (void(__cdecl*)(br_pixelmap *, br_int_32, br_int_32, br_uint_32, br_font *, char *))0x004ca310;
CARM95_HOOK_FUNCTION(original_BrPixelmapText, BrPixelmapText)
void __cdecl BrPixelmapText(br_pixelmap *dst, br_int_32 x, br_int_32 y, br_uint_32 colour, br_font *font, char *text) {
    br_point p;
    LOG_TRACE("(%p, %d, %d, %u, %p, \"%s\")", dst, x, y, colour, font, text);

    (void)dst;
    (void)x;
    (void)y;
    (void)colour;
    (void)font;
    (void)text;
    (void)p;

    original_BrPixelmapText(dst, x, y, colour, font, text);
}

void(__cdecl*BrPixelmapTextF)(br_pixelmap *, br_int_32, br_int_32, br_uint_32, br_font *, char *) = (void(__cdecl*)(br_pixelmap *, br_int_32, br_int_32, br_uint_32, br_font *, char *))0x004ca360;
void BrPixelmapTextF_do_not_use(br_pixelmap *dst, br_int_32 x, br_int_32 y, br_uint_32 colour, br_font *font, char *fmt) {
    char *ss;
    br_point p;
    va_list args;
    LOG_TRACE("(%p, %d, %d, %u, %p, \"%s\")", dst, x, y, colour, font, fmt);

    (void)dst;
    (void)x;
    (void)y;
    (void)colour;
    (void)font;
    (void)fmt;
    (void)ss;
    (void)p;
    (void)args;

    NOT_IMPLEMENTED();
}

static br_uint_16(__cdecl*original_BrPixelmapTextWidth)(br_pixelmap *, br_font *, char *) = (br_uint_16(__cdecl*)(br_pixelmap *, br_font *, char *))0x004ca3d0;
CARM95_HOOK_FUNCTION(original_BrPixelmapTextWidth, BrPixelmapTextWidth)
br_uint_16 __cdecl BrPixelmapTextWidth(br_pixelmap *dst, br_font *font, char *text) {
    int i;
    int j;
    int w;
    LOG_TRACE("(%p, %p, \"%s\")", dst, font, text);

    (void)dst;
    (void)font;
    (void)text;
    (void)i;
    (void)j;
    (void)w;

    return original_BrPixelmapTextWidth(dst, font, text);
}

static br_uint_16(__cdecl*original_BrPixelmapTextHeight)(br_pixelmap *, br_font *) = (br_uint_16(__cdecl*)(br_pixelmap *, br_font *))0x004ca460;
CARM95_HOOK_FUNCTION(original_BrPixelmapTextHeight, BrPixelmapTextHeight)
br_uint_16 __cdecl BrPixelmapTextHeight(br_pixelmap *dst, br_font *font) {
    LOG_TRACE("(%p, %p)", dst, font);

    (void)dst;
    (void)font;

    return original_BrPixelmapTextHeight(dst, font);
}

static void(__cdecl*original_BrPixelmapCopyBits)(br_pixelmap *, br_int_32, br_int_32, br_uint_8 *, br_int_32, br_int_32, br_int_32, br_int_32, br_uint_32) = (void(__cdecl*)(br_pixelmap *, br_int_32, br_int_32, br_uint_8 *, br_int_32, br_int_32, br_int_32, br_int_32, br_uint_32))0x004ca480;
CARM95_HOOK_FUNCTION(original_BrPixelmapCopyBits, BrPixelmapCopyBits)
void __cdecl BrPixelmapCopyBits(br_pixelmap *dst, br_int_32 x, br_int_32 y, br_uint_8 *src, br_int_32 s_stride, br_int_32 start_bit, br_int_32 end_bit, br_int_32 nrows, br_uint_32 colour) {
    br_point p;
    br_rectangle r;
    LOG_TRACE("(%p, %d, %d, %p, %d, %d, %d, %d, %u)", dst, x, y, src, s_stride, start_bit, end_bit, nrows, colour);

    (void)dst;
    (void)x;
    (void)y;
    (void)src;
    (void)s_stride;
    (void)start_bit;
    (void)end_bit;
    (void)nrows;
    (void)colour;
    (void)p;
    (void)r;

    original_BrPixelmapCopyBits(dst, x, y, src, s_stride, start_bit, end_bit, nrows, colour);
}

static br_uint_16(__cdecl*original_BrPixelmapFileSize)(br_pixelmap *) = (br_uint_16(__cdecl*)(br_pixelmap *))0x004ca4f0;
CARM95_HOOK_FUNCTION(original_BrPixelmapFileSize, BrPixelmapFileSize)
br_uint_16 __cdecl BrPixelmapFileSize(br_pixelmap *pm) {
    LOG_TRACE("(%p)", pm);

    (void)pm;

    return original_BrPixelmapFileSize(pm);
}

static br_uint_16(__cdecl*original_BrPixelmapPixelSize)(br_pixelmap *) = (br_uint_16(__cdecl*)(br_pixelmap *))0x004ca510;
CARM95_HOOK_FUNCTION(original_BrPixelmapPixelSize, BrPixelmapPixelSize)
br_uint_16 __cdecl BrPixelmapPixelSize(br_pixelmap *pm) {
    LOG_TRACE("(%p)", pm);

    (void)pm;

    return original_BrPixelmapPixelSize(pm);
}

static br_uint_16(__cdecl*original_BrPixelmapChannels)(br_pixelmap *) = (br_uint_16(__cdecl*)(br_pixelmap *))0x004ca530;
CARM95_HOOK_FUNCTION(original_BrPixelmapChannels, BrPixelmapChannels)
br_uint_16 __cdecl BrPixelmapChannels(br_pixelmap *pm) {
    LOG_TRACE("(%p)", pm);

    (void)pm;

    return original_BrPixelmapChannels(pm);
}

static void(__cdecl*original_BrPixelmapPaletteSet)(br_pixelmap *, br_pixelmap *) = (void(__cdecl*)(br_pixelmap *, br_pixelmap *))0x004ca550;
CARM95_HOOK_FUNCTION(original_BrPixelmapPaletteSet, BrPixelmapPaletteSet)
void __cdecl BrPixelmapPaletteSet(br_pixelmap *pm, br_pixelmap *pal) {
    LOG_TRACE("(%p, %p)", pm, pal);

    (void)pm;
    (void)pal;

    original_BrPixelmapPaletteSet(pm, pal);
}

static void(__cdecl*original_BrPixelmapPaletteEntrySet)(br_pixelmap *, br_int_32, br_colour) = (void(__cdecl*)(br_pixelmap *, br_int_32, br_colour))0x004ca5b0;
CARM95_HOOK_FUNCTION(original_BrPixelmapPaletteEntrySet, BrPixelmapPaletteEntrySet)
void __cdecl BrPixelmapPaletteEntrySet(br_pixelmap *pm, br_int_32 index, br_colour colour) {
    br_device_clut *clut;
    LOG_TRACE("(%p, %d, %u)", pm, index, colour);

    (void)pm;
    (void)index;
    (void)colour;
    (void)clut;

    original_BrPixelmapPaletteEntrySet(pm, index, colour);
}

static void(__cdecl*original_BrPixelmapPaletteEntrySetMany)(br_pixelmap *, br_int_32, br_int_32, br_colour *) = (void(__cdecl*)(br_pixelmap *, br_int_32, br_int_32, br_colour *))0x004ca600;
CARM95_HOOK_FUNCTION(original_BrPixelmapPaletteEntrySetMany, BrPixelmapPaletteEntrySetMany)
void __cdecl BrPixelmapPaletteEntrySetMany(br_pixelmap *pm, br_int_32 index, br_int_32 ncolours, br_colour *colours) {
    br_device_clut *clut;
    LOG_TRACE("(%p, %d, %d, %p)", pm, index, ncolours, colours);

    (void)pm;
    (void)index;
    (void)ncolours;
    (void)colours;
    (void)clut;

    original_BrPixelmapPaletteEntrySetMany(pm, index, ncolours, colours);
}

static br_pixelmap *(__cdecl*original_BrPixelmapDirectLock)(br_pixelmap *, br_boolean) = (br_pixelmap *(__cdecl*)(br_pixelmap *, br_boolean))0x004ca650;
CARM95_HOOK_FUNCTION(original_BrPixelmapDirectLock, BrPixelmapDirectLock)
br_pixelmap* __cdecl BrPixelmapDirectLock(br_pixelmap *src, br_boolean block) {
    LOG_TRACE("(%p, %d)", src, block);

    (void)src;
    (void)block;

    return original_BrPixelmapDirectLock(src, block);
}

static br_pixelmap *(__cdecl*original_BrPixelmapDirectUnlock)(br_pixelmap *) = (br_pixelmap *(__cdecl*)(br_pixelmap *))0x004ca680;
CARM95_HOOK_FUNCTION(original_BrPixelmapDirectUnlock, BrPixelmapDirectUnlock)
br_pixelmap* __cdecl BrPixelmapDirectUnlock(br_pixelmap *src) {
    LOG_TRACE("(%p)", src);

    (void)src;

    return original_BrPixelmapDirectUnlock(src);
}

