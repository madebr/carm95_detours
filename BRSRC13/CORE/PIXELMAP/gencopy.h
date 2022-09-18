#ifndef _GENCOPY_H_
#define _GENCOPY_H_

#include "br_types.h"


br_error __stdcall GeneralRectangleCopy(br_device_pixelmap *dest, br_point *p, br_device_pixelmap *src, br_rectangle *r);

br_error __stdcall GeneralCopy(br_device_pixelmap *dst, br_device_pixelmap *src);

br_error __stdcall GeneralRectangleStretchCopy(struct br_device_pixelmap *dst, br_rectangle *d, struct br_device_pixelmap *src, br_rectangle *s);

#endif
