#ifndef _TRANSFRM_H_
#define _TRANSFRM_H_

#include "br_types.h"

extern br_uint_8(* hookvar__CombineTransforms )[7][7]; // addr: 00523CA0

void __cdecl BrTransformToMatrix34(br_matrix34 *mat, br_transform *xform);

void __cdecl BrMatrix34PreTransform(br_matrix34 *mat, br_transform *xform);

void __cdecl BrMatrix34PostTransform(br_matrix34 *mat, br_transform *xform);

void __cdecl BrMatrix4PreTransform(br_matrix4 *mat, br_transform *xform);

void __cdecl BrMatrix34ToTransform(br_transform *xform, br_matrix34 *mat);

void __cdecl BrTransformToTransform(br_transform *dest, br_transform *src);

#endif
