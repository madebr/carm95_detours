#ifndef _IMAGE_H_
#define _IMAGE_H_

#include "br_types.h"


br_boolean __cdecl BrImageAdd(br_image *img);

br_boolean __cdecl BrImageRemove(br_image *img);

br_image* __cdecl BrImageFind(char *pattern);

br_image* imageLoadHost(char *name);

br_image* __cdecl BrImageReference(char *name);

void* __stdcall imageLookupName(br_image *img, char *name, br_uint_32 hint);

void* __cdecl BrImageLookupName(br_image *img, char *name, br_uint_32 hint);

void* __cdecl BrImageLookupOrdinal(br_image *img, br_uint_32 ordinal);

void __cdecl BrImageDereference(br_image *image);

void __cdecl BrImageFree(br_image *image);

void __cdecl _BrImageFree(void *res, br_uint_8 res_class, br_size_t size);

#endif
