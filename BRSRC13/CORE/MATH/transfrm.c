#include "transfrm.h"

#include "harness/trace.h"

#include "carm95_hooks.h"

#include <stdio.h>
br_uint_8(* hookvar__CombineTransforms )[7][7] = (void*)0x00523ca0;

static void(*original_BrTransformToMatrix34)(br_matrix34 *, br_transform *, ...) = (void(*)(br_matrix34 *, br_transform *, ...))0x004d25b0;
CARM95_HOOK_FUNCTION(original_BrTransformToMatrix34, BrTransformToMatrix34)
void BrTransformToMatrix34(br_matrix34 *mat, br_transform *xform) {
    br_scalar __block0___scale;
    br_scalar __block1___scale;
    br_vector3 __block2__vx;
    br_vector3 __block2__vy;
    br_vector3 __block2__vz;
    LOG_TRACE("(%p, %p)", mat, xform);

    (void)mat;
    (void)xform;

    original_BrTransformToMatrix34(mat, xform);
}

static void(*original_BrMatrix34PreTransform)(br_matrix34 *, br_transform *, ...) = (void(*)(br_matrix34 *, br_transform *, ...))0x004d2840;
CARM95_HOOK_FUNCTION(original_BrMatrix34PreTransform, BrMatrix34PreTransform)
void BrMatrix34PreTransform(br_matrix34 *mat, br_transform *xform) {
    br_matrix34 tmp;
    LOG_TRACE("(%p, %p)", mat, xform);

    (void)mat;
    (void)xform;
    (void)tmp;

    original_BrMatrix34PreTransform(mat, xform);
}

static void(*original_BrMatrix34PostTransform)(br_matrix34 *, br_transform *, ...) = (void(*)(br_matrix34 *, br_transform *, ...))0x004d2880;
CARM95_HOOK_FUNCTION(original_BrMatrix34PostTransform, BrMatrix34PostTransform)
void BrMatrix34PostTransform(br_matrix34 *mat, br_transform *xform) {
    br_matrix34 tmp;
    LOG_TRACE("(%p, %p)", mat, xform);

    (void)mat;
    (void)xform;
    (void)tmp;

    original_BrMatrix34PostTransform(mat, xform);
}

static void(*original_BrMatrix4PreTransform)(br_matrix4 *, br_transform *, ...) = (void(*)(br_matrix4 *, br_transform *, ...))0x004d28b1;
CARM95_HOOK_FUNCTION(original_BrMatrix4PreTransform, BrMatrix4PreTransform)
void BrMatrix4PreTransform(br_matrix4 *mat, br_transform *xform) {
    br_matrix34 tmp;
    LOG_TRACE("(%p, %p)", mat, xform);

    (void)mat;
    (void)xform;
    (void)tmp;

    original_BrMatrix4PreTransform(mat, xform);
}

static void(*original_BrMatrix34ToTransform)(br_transform *, br_matrix34 *, ...) = (void(*)(br_transform *, br_matrix34 *, ...))0x004d2900;
CARM95_HOOK_FUNCTION(original_BrMatrix34ToTransform, BrMatrix34ToTransform)
void BrMatrix34ToTransform(br_transform *xform, br_matrix34 *mat) {
    LOG_TRACE("(%p, %p)", xform, mat);

    (void)xform;
    (void)mat;

    original_BrMatrix34ToTransform(xform, mat);
}

static void(*original_BrTransformToTransform)(br_transform *, br_transform *, ...) = (void(*)(br_transform *, br_transform *, ...))0x004d2a50;
CARM95_HOOK_FUNCTION(original_BrTransformToTransform, BrTransformToTransform)
void BrTransformToTransform(br_transform *dest, br_transform *src) {
    br_matrix34 temp;
    LOG_TRACE("(%p, %p)", dest, src);

    (void)dest;
    (void)src;
    (void)temp;

    original_BrTransformToTransform(dest, src);
}

