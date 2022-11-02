#include "quat.h"

#include "harness/trace.h"

#include "carm95_hooks.h"

#include "carm95_webserver.h"

#include <assert.h>

function_hook_state_t function_hook_state_BrQuatMul = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_BrQuatMul)
static br_quat *(__cdecl*original_BrQuatMul)(br_quat *, br_quat *, br_quat *) = (br_quat *(__cdecl*)(br_quat *, br_quat *, br_quat *))0x004d53a0;
CARM95_HOOK_FUNCTION(original_BrQuatMul, BrQuatMul)
br_quat* __cdecl BrQuatMul(br_quat *q, br_quat *l, br_quat *r) {
    br_scalar x1;
    br_scalar x2;
    br_scalar x3;
    br_scalar x4;
    br_scalar x5;
    br_scalar x6;
    br_scalar x7;
    br_scalar x8;
    br_scalar s;
    br_scalar t;
    LOG_TRACE("(%p, %p, %p)", q, l, r);

    (void)q;
    (void)l;
    (void)r;
    (void)x1;
    (void)x2;
    (void)x3;
    (void)x4;
    (void)x5;
    (void)x6;
    (void)x7;
    (void)x8;
    (void)s;
    (void)t;

    if (function_hook_state_BrQuatMul == HOOK_ENABLED) {
        assert(0 && "BrQuatMul not implemented.");
        abort();
    } else {
        return original_BrQuatMul(q, l, r);
    }
}

function_hook_state_t function_hook_state_BrQuatNormalise = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_BrQuatNormalise)
static br_quat *(__cdecl*original_BrQuatNormalise)(br_quat *, br_quat *) = (br_quat *(__cdecl*)(br_quat *, br_quat *))0x004d5490;
CARM95_HOOK_FUNCTION(original_BrQuatNormalise, BrQuatNormalise)
br_quat* __cdecl BrQuatNormalise(br_quat *q, br_quat *qq) {
    br_scalar s;
    LOG_TRACE("(%p, %p)", q, qq);

    (void)q;
    (void)qq;
    (void)s;

    if (function_hook_state_BrQuatNormalise == HOOK_ENABLED) {
        assert(0 && "BrQuatNormalise not implemented.");
        abort();
    } else {
        return original_BrQuatNormalise(q, qq);
    }
}

function_hook_state_t function_hook_state_BrQuatInvert = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_BrQuatInvert)
static br_quat *(__cdecl*original_BrQuatInvert)(br_quat *, br_quat *) = (br_quat *(__cdecl*)(br_quat *, br_quat *))0x004d54f0;
CARM95_HOOK_FUNCTION(original_BrQuatInvert, BrQuatInvert)
br_quat* __cdecl BrQuatInvert(br_quat *q, br_quat *qq) {
    LOG_TRACE("(%p, %p)", q, qq);

    (void)q;
    (void)qq;

    if (function_hook_state_BrQuatInvert == HOOK_ENABLED) {
        assert(0 && "BrQuatInvert not implemented.");
        abort();
    } else {
        return original_BrQuatInvert(q, qq);
    }
}

function_hook_state_t function_hook_state_BrQuatSlerp = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_BrQuatSlerp)
static br_quat *(__cdecl*original_BrQuatSlerp)(br_quat *, br_quat *, br_quat *, br_scalar, br_int_16) = (br_quat *(__cdecl*)(br_quat *, br_quat *, br_quat *, br_scalar, br_int_16))0x004d5520;
CARM95_HOOK_FUNCTION(original_BrQuatSlerp, BrQuatSlerp)
br_quat* __cdecl BrQuatSlerp(br_quat *q, br_quat *l, br_quat *r, br_scalar a, br_int_16 spins) {
    int omega;
    int omega_spin;
    br_scalar s_omega;
    br_scalar c_omega;
    br_scalar scale_l;
    br_scalar scale_r;
    br_quat t;
    LOG_TRACE("(%p, %p, %p, %f, %d)", q, l, r, a, spins);

    (void)q;
    (void)l;
    (void)r;
    (void)a;
    (void)spins;
    (void)omega;
    (void)omega_spin;
    (void)s_omega;
    (void)c_omega;
    (void)scale_l;
    (void)scale_r;
    (void)t;

    if (function_hook_state_BrQuatSlerp == HOOK_ENABLED) {
        assert(0 && "BrQuatSlerp not implemented.");
        abort();
    } else {
        return original_BrQuatSlerp(q, l, r, a, spins);
    }
}

function_hook_state_t function_hook_state_BrQuatToMatrix34 = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_BrQuatToMatrix34)
static br_matrix34 *(__cdecl*original_BrQuatToMatrix34)(br_matrix34 *, br_quat *) = (br_matrix34 *(__cdecl*)(br_matrix34 *, br_quat *))0x004d56e0;
CARM95_HOOK_FUNCTION(original_BrQuatToMatrix34, BrQuatToMatrix34)
br_matrix34* __cdecl BrQuatToMatrix34(br_matrix34 *mat, br_quat *q) {
    br_scalar xs;
    br_scalar ys;
    br_scalar zs;
    br_scalar wx;
    br_scalar wy;
    br_scalar wz;
    br_scalar xx;
    br_scalar xy;
    br_scalar xz;
    br_scalar yy;
    br_scalar yz;
    br_scalar zz;
    LOG_TRACE("(%p, %p)", mat, q);

    (void)mat;
    (void)q;
    (void)xs;
    (void)ys;
    (void)zs;
    (void)wx;
    (void)wy;
    (void)wz;
    (void)xx;
    (void)xy;
    (void)xz;
    (void)yy;
    (void)yz;
    (void)zz;

    if (function_hook_state_BrQuatToMatrix34 == HOOK_ENABLED) {
        assert(0 && "BrQuatToMatrix34 not implemented.");
        abort();
    } else {
        return original_BrQuatToMatrix34(mat, q);
    }
}

function_hook_state_t function_hook_state_BrMatrix34ToQuat = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_BrMatrix34ToQuat)
static br_quat *(__cdecl*original_BrMatrix34ToQuat)(br_quat *, br_matrix34 *) = (br_quat *(__cdecl*)(br_quat *, br_matrix34 *))0x004d57c0;
CARM95_HOOK_FUNCTION(original_BrMatrix34ToQuat, BrMatrix34ToQuat)
br_quat* __cdecl BrMatrix34ToQuat(br_quat *q, br_matrix34 *mat) {
    br_scalar tr;
    br_scalar s;
    int i;
    int j;
    int k;
    static int __block0__n[3];
    LOG_TRACE("(%p, %p)", q, mat);

    (void)q;
    (void)mat;
    (void)tr;
    (void)s;
    (void)i;
    (void)j;
    (void)k;
    (void)__block0__n;

    if (function_hook_state_BrMatrix34ToQuat == HOOK_ENABLED) {
        assert(0 && "BrMatrix34ToQuat not implemented.");
        abort();
    } else {
        return original_BrMatrix34ToQuat(q, mat);
    }
}

function_hook_state_t function_hook_state_BrQuatToMatrix4 = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_BrQuatToMatrix4)
static br_matrix4 *(__cdecl*original_BrQuatToMatrix4)(br_matrix4 *, br_quat *) = (br_matrix4 *(__cdecl*)(br_matrix4 *, br_quat *))0x004d58fb;
CARM95_HOOK_FUNCTION(original_BrQuatToMatrix4, BrQuatToMatrix4)
br_matrix4* __cdecl BrQuatToMatrix4(br_matrix4 *mat, br_quat *q) {
    br_matrix34 tmp;
    LOG_TRACE("(%p, %p)", mat, q);

    (void)mat;
    (void)q;
    (void)tmp;

    if (function_hook_state_BrQuatToMatrix4 == HOOK_ENABLED) {
        assert(0 && "BrQuatToMatrix4 not implemented.");
        abort();
    } else {
        return original_BrQuatToMatrix4(mat, q);
    }
}

function_hook_state_t function_hook_state_BrMatrix4ToQuat = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_BrMatrix4ToQuat)
static br_quat *(__cdecl*original_BrMatrix4ToQuat)(br_quat *, br_matrix4 *) = (br_quat *(__cdecl*)(br_quat *, br_matrix4 *))0x004d5930;
CARM95_HOOK_FUNCTION(original_BrMatrix4ToQuat, BrMatrix4ToQuat)
br_quat* __cdecl BrMatrix4ToQuat(br_quat *q, br_matrix4 *mat) {
    br_matrix34 tmp;
    LOG_TRACE("(%p, %p)", q, mat);

    (void)q;
    (void)mat;
    (void)tmp;

    if (function_hook_state_BrMatrix4ToQuat == HOOK_ENABLED) {
        assert(0 && "BrMatrix4ToQuat not implemented.");
        abort();
    } else {
        return original_BrMatrix4ToQuat(q, mat);
    }
}

