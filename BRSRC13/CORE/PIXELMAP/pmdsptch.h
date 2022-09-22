#ifndef _PMDSPTCH_H_
#define _PMDSPTCH_H_

#include "br_types.h"


br_pixelmap* __cdecl BrPixelmapAllocateSub(br_pixelmap *src, br_int_32 x, br_int_32 y, br_int_32 w, br_int_32 h);

void __cdecl BrPixelmapFree(br_pixelmap *src);

br_pixelmap* __cdecl BrPixelmapResize(br_pixelmap *src, br_int_32 width, br_int_32 height);

br_pixelmap* __cdecl BrPixelmapMatch(br_pixelmap *src, br_uint_8 match_type);

br_pixelmap* __cdecl BrPixelmapMatchSized(br_pixelmap *src, br_uint_8 match_type, br_int_32 width, br_int_32 height);

br_pixelmap* __cdecl BrPixelmapMatchTyped(br_pixelmap *src, br_uint_8 match_type, br_uint_8 pixelmap_type);

br_pixelmap* __cdecl BrPixelmapMatchTypedSized(br_pixelmap *src, br_uint_8 match_type, br_uint_8 pixelmap_type, br_int_32 width, br_int_32 height);

br_pixelmap* __cdecl BrPixelmapClone(br_pixelmap *src);

void __cdecl BrPixelmapFill(br_pixelmap *dst, br_uint_32 colour);

void __cdecl BrPixelmapRectangle(br_pixelmap *dst, br_int_32 x, br_int_32 y, br_int_32 w, br_int_32 h, br_uint_32 colour);

void __cdecl BrPixelmapRectangle2(br_pixelmap *dst, br_int_32 x, br_int_32 y, br_int_32 w, br_int_32 h, br_uint_32 colour_tl, br_uint_32 colour_br);

br_error __stdcall DispatchCopy(br_device_pixelmap *self, br_device_pixelmap *src);

br_error __stdcall DispatchRectangleCopy(br_device_pixelmap *self, br_point *p, br_device_pixelmap *src, br_rectangle *r);

br_error __cdecl DispatchRectangleStretchCopy(br_device_pixelmap *self, br_rectangle *r, br_device_pixelmap *src, br_rectangle *s);

void __cdecl BrPixelmapRectangleCopy(br_pixelmap *dst, br_int_32 dx, br_int_32 dy, br_pixelmap *src, br_int_32 sx, br_int_32 sy, br_int_32 w, br_int_32 h);

void __cdecl BrPixelmapRectangleStretchCopy(br_pixelmap *dst, br_int_32 dx, br_int_32 dy, br_int_32 dw, br_int_32 dh, br_pixelmap *src, br_int_32 sx, br_int_32 sy, br_int_32 sw, br_int_32 sh);

void __cdecl BrPixelmapRectangleFill(br_pixelmap *dst, br_int_32 x, br_int_32 y, br_int_32 w, br_int_32 h, br_uint_32 colour);

void __cdecl BrPixelmapDirtyRectangleCopy(br_pixelmap *dst, br_pixelmap *src, br_int_32 x, br_int_32 y, br_int_32 w, br_int_32 h);

void __cdecl BrPixelmapDirtyRectangleClear(br_pixelmap *dst, br_int_32 x, br_int_32 y, br_int_32 w, br_int_32 h, br_uint_32 colour);

void __cdecl BrPixelmapDirtyRectangleDoubleBuffer(br_pixelmap *dst, br_pixelmap *src, br_int_32 x, br_int_32 y, br_int_32 w, br_int_32 h);

void __cdecl BrPixelmapPixelSet(br_pixelmap *dst, br_int_32 x, br_int_32 y, br_uint_32 colour);

br_uint_32 __cdecl BrPixelmapPixelGet(br_pixelmap *dst, br_int_32 x, br_int_32 y);

void __cdecl BrPixelmapCopy(br_pixelmap *dst, br_pixelmap *src);

void __cdecl BrPixelmapLine(br_pixelmap *dst, br_int_32 x1, br_int_32 y1, br_int_32 x2, br_int_32 y2, br_uint_32 colour);

void __cdecl BrPixelmapDoubleBuffer(br_pixelmap *dst, br_pixelmap *src);

void __cdecl BrPixelmapText(br_pixelmap *dst, br_int_32 x, br_int_32 y, br_uint_32 colour, br_font *font, char *text);

extern void(__cdecl*BrPixelmapTextF)(br_pixelmap *, br_int_32, br_int_32, br_uint_32, br_font *, char *);
#if 0
void BrPixelmapTextF_do_not_use(br_pixelmap *dst, br_int_32 x, br_int_32 y, br_uint_32 colour, br_font *font, char *fmt);
#endif

br_uint_16 __cdecl BrPixelmapTextWidth(br_pixelmap *dst, br_font *font, char *text);

br_uint_16 __cdecl BrPixelmapTextHeight(br_pixelmap *dst, br_font *font);

void __cdecl BrPixelmapCopyBits(br_pixelmap *dst, br_int_32 x, br_int_32 y, br_uint_8 *src, br_int_32 s_stride, br_int_32 start_bit, br_int_32 end_bit, br_int_32 nrows, br_uint_32 colour);

br_uint_16 __cdecl BrPixelmapFileSize(br_pixelmap *pm);

br_uint_16 __cdecl BrPixelmapPixelSize(br_pixelmap *pm);

br_uint_16 __cdecl BrPixelmapChannels(br_pixelmap *pm);

void __cdecl BrPixelmapPaletteSet(br_pixelmap *pm, br_pixelmap *pal);

void __cdecl BrPixelmapPaletteEntrySet(br_pixelmap *pm, br_int_32 index, br_colour colour);

void __cdecl BrPixelmapPaletteEntrySetMany(br_pixelmap *pm, br_int_32 index, br_int_32 ncolours, br_colour *colours);

br_pixelmap* __cdecl BrPixelmapDirectLock(br_pixelmap *src, br_boolean block);

br_pixelmap* __cdecl BrPixelmapDirectUnlock(br_pixelmap *src);

#endif
