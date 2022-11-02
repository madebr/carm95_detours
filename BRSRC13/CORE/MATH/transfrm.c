#include "transfrm.h"

#include "harness/trace.h"

#include "carm95_hooks.h"

#include "carm95_webserver.h"

#include <assert.h>
br_uint_8(* hookvar__CombineTransforms )[7][7] = (void*)0x00523ca0;

function_hook_state_t function_hook_state_BrTransformToMatrix34 = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_BrTransformToMatrix34)
static void(__cdecl*original_BrTransformToMatrix34)(br_matrix34 *, br_transform *) = (void(__cdecl*)(br_matrix34 *, br_transform *))0x004d25b0;
CARM95_HOOK_FUNCTION(original_BrTransformToMatrix34, BrTransformToMatrix34)
void __cdecl BrTransformToMatrix34(br_matrix34 *mat, br_transform *xform) {
    br_scalar __block0___scale;
    br_scalar __block1___scale;
    br_vector3 __block2__vx;
    br_vector3 __block2__vy;
    br_vector3 __block2__vz;
    LOG_TRACE("(%p, %p)", mat, xform);

    (void)mat;
    (void)xform;
    (void)__block0___scale;
    (void)__block1___scale;
    (void)__block2__vx;
    (void)__block2__vy;
    (void)__block2__vz;

    if (function_hook_state_BrTransformToMatrix34 == HOOK_ENABLED) {
        assert(0 && "BrTransformToMatrix34 not implemented.");
        abort();
    } else {
        original_BrTransformToMatrix34(mat, xform);
    }
}

function_hook_state_t function_hook_state_BrMatrix34PreTransform = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_BrMatrix34PreTransform)
static void(__cdecl*original_BrMatrix34PreTransform)(br_matrix34 *, br_transform *) = (void(__cdecl*)(br_matrix34 *, br_transform *))0x004d2840;
CARM95_HOOK_FUNCTION(original_BrMatrix34PreTransform, BrMatrix34PreTransform)
void __cdecl BrMatrix34PreTransform(br_matrix34 *mat, br_transform *xform) {
    br_matrix34 tmp;
    LOG_TRACE("(%p, %p)", mat, xform);

    (void)mat;
    (void)xform;
    (void)tmp;

    if (function_hook_state_BrMatrix34PreTransform == HOOK_ENABLED) {
        assert(0 && "BrMatrix34PreTransform not implemented.");
        abort();
    } else {
        original_BrMatrix34PreTransform(mat, xform);
    }
}

function_hook_state_t function_hook_state_BrMatrix34PostTransform = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_BrMatrix34PostTransform)
static void(__cdecl*original_BrMatrix34PostTransform)(br_matrix34 *, br_transform *) = (void(__cdecl*)(br_matrix34 *, br_transform *))0x004d2880;
CARM95_HOOK_FUNCTION(original_BrMatrix34PostTransform, BrMatrix34PostTransform)
void __cdecl BrMatrix34PostTransform(br_matrix34 *mat, br_transform *xform) {
    br_matrix34 tmp;
    LOG_TRACE("(%p, %p)", mat, xform);

    (void)mat;
    (void)xform;
    (void)tmp;

    if (function_hook_state_BrMatrix34PostTransform == HOOK_ENABLED) {
        assert(0 && "BrMatrix34PostTransform not implemented.");
        abort();
    } else {
        original_BrMatrix34PostTransform(mat, xform);
    }
}

function_hook_state_t function_hook_state_BrMatrix4PreTransform = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_BrMatrix4PreTransform)
static void(__cdecl*original_BrMatrix4PreTransform)(br_matrix4 *, br_transform *) = (void(__cdecl*)(br_matrix4 *, br_transform *))0x004d28b1;
CARM95_HOOK_FUNCTION(original_BrMatrix4PreTransform, BrMatrix4PreTransform)
void __cdecl BrMatrix4PreTransform(br_matrix4 *mat, br_transform *xform) {
    br_matrix34 tmp;
    LOG_TRACE("(%p, %p)", mat, xform);

    (void)mat;
    (void)xform;
    (void)tmp;

    if (function_hook_state_BrMatrix4PreTransform == HOOK_ENABLED) {
        assert(0 && "BrMatrix4PreTransform not implemented.");
        abort();
    } else {
        original_BrMatrix4PreTransform(mat, xform);
    }
}

function_hook_state_t function_hook_state_BrMatrix34ToTransform = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_BrMatrix34ToTransform)
static void(__cdecl*original_BrMatrix34ToTransform)(br_transform *, br_matrix34 *) = (void(__cdecl*)(br_transform *, br_matrix34 *))0x004d2900;
CARM95_HOOK_FUNCTION(original_BrMatrix34ToTransform, BrMatrix34ToTransform)
void __cdecl BrMatrix34ToTransform(br_transform *xform, br_matrix34 *mat) {
    LOG_TRACE("(%p, %p)", xform, mat);

    (void)xform;
    (void)mat;

    if (function_hook_state_BrMatrix34ToTransform == HOOK_ENABLED) {
        assert(0 && "BrMatrix34ToTransform not implemented.");
        abort();
    } else {
        original_BrMatrix34ToTransform(xform, mat);
    }
}

function_hook_state_t function_hook_state_BrTransformToTransform = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_BrTransformToTransform)
static void(__cdecl*original_BrTransformToTransform)(br_transform *, br_transform *) = (void(__cdecl*)(br_transform *, br_transform *))0x004d2a50;
CARM95_HOOK_FUNCTION(original_BrTransformToTransform, BrTransformToTransform)
void __cdecl BrTransformToTransform(br_transform *dest, br_transform *src) {
    br_matrix34 temp;
    LOG_TRACE("(%p, %p)", dest, src);

    (void)dest;
    (void)src;
    (void)temp;

    if (function_hook_state_BrTransformToTransform == HOOK_ENABLED) {
        assert(0 && "BrTransformToTransform not implemented.");
        abort();
    } else {
        original_BrTransformToTransform(dest, src);
    }
}

