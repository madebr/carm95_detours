#include "quat.h"

#include "harness/trace.h"

#include "carm95_hooks.h"

#include <stdio.h>

static br_quat *(*original_BrQuatMul)(br_quat *, br_quat *, br_quat *, ...) = (br_quat *(*)(br_quat *, br_quat *, br_quat *, ...))0x004d53a0;
CARM95_HOOK_FUNCTION(original_BrQuatMul, BrQuatMul)
br_quat* BrQuatMul(br_quat *q, br_quat *l, br_quat *r) {
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

    return original_BrQuatMul(q, l, r);
}

static br_quat *(*original_BrQuatNormalise)(br_quat *, br_quat *, ...) = (br_quat *(*)(br_quat *, br_quat *, ...))0x004d5490;
CARM95_HOOK_FUNCTION(original_BrQuatNormalise, BrQuatNormalise)
br_quat* BrQuatNormalise(br_quat *q, br_quat *qq) {
    br_scalar s;
    LOG_TRACE("(%p, %p)", q, qq);

    (void)q;
    (void)qq;
    (void)s;

    return original_BrQuatNormalise(q, qq);
}

static br_quat *(*original_BrQuatInvert)(br_quat *, br_quat *, ...) = (br_quat *(*)(br_quat *, br_quat *, ...))0x004d54f0;
CARM95_HOOK_FUNCTION(original_BrQuatInvert, BrQuatInvert)
br_quat* BrQuatInvert(br_quat *q, br_quat *qq) {
    LOG_TRACE("(%p, %p)", q, qq);

    (void)q;
    (void)qq;

    return original_BrQuatInvert(q, qq);
}

static br_quat *(*original_BrQuatSlerp)(br_quat *, br_quat *, br_quat *, br_scalar, br_int_16, ...) = (br_quat *(*)(br_quat *, br_quat *, br_quat *, br_scalar, br_int_16, ...))0x004d5520;
CARM95_HOOK_FUNCTION(original_BrQuatSlerp, BrQuatSlerp)
br_quat* BrQuatSlerp(br_quat *q, br_quat *l, br_quat *r, br_scalar a, br_int_16 spins) {
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

    return original_BrQuatSlerp(q, l, r, a, spins);
}

static br_matrix34 *(*original_BrQuatToMatrix34)(br_matrix34 *, br_quat *, ...) = (br_matrix34 *(*)(br_matrix34 *, br_quat *, ...))0x004d56e0;
CARM95_HOOK_FUNCTION(original_BrQuatToMatrix34, BrQuatToMatrix34)
br_matrix34* BrQuatToMatrix34(br_matrix34 *mat, br_quat *q) {
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

    return original_BrQuatToMatrix34(mat, q);
}

static br_quat *(*original_BrMatrix34ToQuat)(br_quat *, br_matrix34 *, ...) = (br_quat *(*)(br_quat *, br_matrix34 *, ...))0x004d57c0;
CARM95_HOOK_FUNCTION(original_BrMatrix34ToQuat, BrMatrix34ToQuat)
br_quat* BrMatrix34ToQuat(br_quat *q, br_matrix34 *mat) {
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

    return original_BrMatrix34ToQuat(q, mat);
}

static br_matrix4 *(*original_BrQuatToMatrix4)(br_matrix4 *, br_quat *, ...) = (br_matrix4 *(*)(br_matrix4 *, br_quat *, ...))0x004d58fb;
CARM95_HOOK_FUNCTION(original_BrQuatToMatrix4, BrQuatToMatrix4)
br_matrix4* BrQuatToMatrix4(br_matrix4 *mat, br_quat *q) {
    br_matrix34 tmp;
    LOG_TRACE("(%p, %p)", mat, q);

    (void)mat;
    (void)q;
    (void)tmp;

    return original_BrQuatToMatrix4(mat, q);
}

static br_quat *(*original_BrMatrix4ToQuat)(br_quat *, br_matrix4 *, ...) = (br_quat *(*)(br_quat *, br_matrix4 *, ...))0x004d5930;
CARM95_HOOK_FUNCTION(original_BrMatrix4ToQuat, BrMatrix4ToQuat)
br_quat* BrMatrix4ToQuat(br_quat *q, br_matrix4 *mat) {
    br_matrix34 tmp;
    LOG_TRACE("(%p, %p)", q, mat);

    (void)q;
    (void)mat;
    (void)tmp;

    return original_BrMatrix4ToQuat(q, mat);
}

