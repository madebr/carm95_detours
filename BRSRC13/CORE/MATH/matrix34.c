#include "matrix34.h"

#include "harness/trace.h"

#include "carm95_hooks.h"

 // Suffix added to avoid duplicate symbol
#if 0
br_matrix34 * hookvar_mattmp1__matrix34 ;
#endif
 // Suffix added to avoid duplicate symbol
#if 0
br_matrix34 * hookvar_mattmp2__matrix34 ;
#endif

static void(__cdecl*original_BrMatrix34Copy)(br_matrix34 *, br_matrix34 *) = (void(__cdecl*)(br_matrix34 *, br_matrix34 *))0x004d0bd0;
CARM95_HOOK_FUNCTION(original_BrMatrix34Copy, BrMatrix34Copy)
void __cdecl BrMatrix34Copy(br_matrix34 *A, br_matrix34 *B) {
    LOG_TRACE("(%p, %p)", A, B);

    (void)A;
    (void)B;

    original_BrMatrix34Copy(A, B);
}

static void(__cdecl*original_BrMatrix34Mul)(br_matrix34 *, br_matrix34 *, br_matrix34 *) = (void(__cdecl*)(br_matrix34 *, br_matrix34 *, br_matrix34 *))0x004d0c30;
CARM95_HOOK_FUNCTION(original_BrMatrix34Mul, BrMatrix34Mul)
void __cdecl BrMatrix34Mul(br_matrix34 *A, br_matrix34 *B, br_matrix34 *C) {
    LOG_TRACE("(%p, %p, %p)", A, B, C);

    (void)A;
    (void)B;
    (void)C;

    original_BrMatrix34Mul(A, B, C);
}

static void(__cdecl*original_BrMatrix34Identity)(br_matrix34 *) = (void(__cdecl*)(br_matrix34 *))0x004d0d90;
CARM95_HOOK_FUNCTION(original_BrMatrix34Identity, BrMatrix34Identity)
void __cdecl BrMatrix34Identity(br_matrix34 *mat) {
    LOG_TRACE("(%p)", mat);

    (void)mat;

    original_BrMatrix34Identity(mat);
}

static void(__cdecl*original_BrMatrix34RotateX)(br_matrix34 *, br_angle) = (void(__cdecl*)(br_matrix34 *, br_angle))0x004d0dc0;
CARM95_HOOK_FUNCTION(original_BrMatrix34RotateX, BrMatrix34RotateX)
void __cdecl BrMatrix34RotateX(br_matrix34 *mat, br_angle rx) {
    br_scalar s;
    br_scalar c;
    LOG_TRACE("(%p, %u)", mat, rx);

    (void)mat;
    (void)rx;
    (void)s;
    (void)c;

    original_BrMatrix34RotateX(mat, rx);
}

static void(__cdecl*original_BrMatrix34RotateY)(br_matrix34 *, br_angle) = (void(__cdecl*)(br_matrix34 *, br_angle))0x004d0e20;
CARM95_HOOK_FUNCTION(original_BrMatrix34RotateY, BrMatrix34RotateY)
void __cdecl BrMatrix34RotateY(br_matrix34 *mat, br_angle ry) {
    br_scalar s;
    br_scalar c;
    LOG_TRACE("(%p, %u)", mat, ry);

    (void)mat;
    (void)ry;
    (void)s;
    (void)c;

    original_BrMatrix34RotateY(mat, ry);
}

static void(__cdecl*original_BrMatrix34RotateZ)(br_matrix34 *, br_angle) = (void(__cdecl*)(br_matrix34 *, br_angle))0x004d0e80;
CARM95_HOOK_FUNCTION(original_BrMatrix34RotateZ, BrMatrix34RotateZ)
void __cdecl BrMatrix34RotateZ(br_matrix34 *mat, br_angle rz) {
    br_scalar s;
    br_scalar c;
    LOG_TRACE("(%p, %u)", mat, rz);

    (void)mat;
    (void)rz;
    (void)s;
    (void)c;

    original_BrMatrix34RotateZ(mat, rz);
}

static void(__cdecl*original_BrMatrix34Rotate)(br_matrix34 *, br_angle, br_vector3 *) = (void(__cdecl*)(br_matrix34 *, br_angle, br_vector3 *))0x004d0ee0;
CARM95_HOOK_FUNCTION(original_BrMatrix34Rotate, BrMatrix34Rotate)
void __cdecl BrMatrix34Rotate(br_matrix34 *mat, br_angle r, br_vector3 *a) {
    br_scalar t;
    br_scalar s;
    br_scalar c;
    br_scalar txy;
    br_scalar txz;
    br_scalar tyz;
    br_scalar sx;
    br_scalar sy;
    br_scalar sz;
    LOG_TRACE("(%p, %u, %p)", mat, r, a);

    (void)mat;
    (void)r;
    (void)a;
    (void)t;
    (void)s;
    (void)c;
    (void)txy;
    (void)txz;
    (void)tyz;
    (void)sx;
    (void)sy;
    (void)sz;

    original_BrMatrix34Rotate(mat, r, a);
}

static void(__cdecl*original_BrMatrix34Translate)(br_matrix34 *, br_scalar, br_scalar, br_scalar) = (void(__cdecl*)(br_matrix34 *, br_scalar, br_scalar, br_scalar))0x004d0fc0;
CARM95_HOOK_FUNCTION(original_BrMatrix34Translate, BrMatrix34Translate)
void __cdecl BrMatrix34Translate(br_matrix34 *mat, br_scalar dx, br_scalar dy, br_scalar dz) {
    LOG_TRACE("(%p, %f, %f, %f)", mat, dx, dy, dz);

    (void)mat;
    (void)dx;
    (void)dy;
    (void)dz;

    original_BrMatrix34Translate(mat, dx, dy, dz);
}

static void(__cdecl*original_BrMatrix34Scale)(br_matrix34 *, br_scalar, br_scalar, br_scalar) = (void(__cdecl*)(br_matrix34 *, br_scalar, br_scalar, br_scalar))0x004d1000;
CARM95_HOOK_FUNCTION(original_BrMatrix34Scale, BrMatrix34Scale)
void __cdecl BrMatrix34Scale(br_matrix34 *mat, br_scalar sx, br_scalar sy, br_scalar sz) {
    LOG_TRACE("(%p, %f, %f, %f)", mat, sx, sy, sz);

    (void)mat;
    (void)sx;
    (void)sy;
    (void)sz;

    original_BrMatrix34Scale(mat, sx, sy, sz);
}

static void(__cdecl*original_BrMatrix34ShearX)(br_matrix34 *, br_scalar, br_scalar) = (void(__cdecl*)(br_matrix34 *, br_scalar, br_scalar))0x004d1040;
CARM95_HOOK_FUNCTION(original_BrMatrix34ShearX, BrMatrix34ShearX)
void __cdecl BrMatrix34ShearX(br_matrix34 *mat, br_scalar sy, br_scalar sz) {
    LOG_TRACE("(%p, %f, %f)", mat, sy, sz);

    (void)mat;
    (void)sy;
    (void)sz;

    original_BrMatrix34ShearX(mat, sy, sz);
}

static void(__cdecl*original_BrMatrix34ShearY)(br_matrix34 *, br_scalar, br_scalar) = (void(__cdecl*)(br_matrix34 *, br_scalar, br_scalar))0x004d1080;
CARM95_HOOK_FUNCTION(original_BrMatrix34ShearY, BrMatrix34ShearY)
void __cdecl BrMatrix34ShearY(br_matrix34 *mat, br_scalar sx, br_scalar sz) {
    LOG_TRACE("(%p, %f, %f)", mat, sx, sz);

    (void)mat;
    (void)sx;
    (void)sz;

    original_BrMatrix34ShearY(mat, sx, sz);
}

static void(__cdecl*original_BrMatrix34ShearZ)(br_matrix34 *, br_scalar, br_scalar) = (void(__cdecl*)(br_matrix34 *, br_scalar, br_scalar))0x004d10c0;
CARM95_HOOK_FUNCTION(original_BrMatrix34ShearZ, BrMatrix34ShearZ)
void __cdecl BrMatrix34ShearZ(br_matrix34 *mat, br_scalar sx, br_scalar sy) {
    LOG_TRACE("(%p, %f, %f)", mat, sx, sy);

    (void)mat;
    (void)sx;
    (void)sy;

    original_BrMatrix34ShearZ(mat, sx, sy);
}

static br_scalar(__cdecl*original_BrMatrix34Inverse)(br_matrix34 *, br_matrix34 *) = (br_scalar(__cdecl*)(br_matrix34 *, br_matrix34 *))0x004d1100;
CARM95_HOOK_FUNCTION(original_BrMatrix34Inverse, BrMatrix34Inverse)
br_scalar __cdecl BrMatrix34Inverse(br_matrix34 *B, br_matrix34 *A) {
    float idet;
    float det;
    float pos;
    float neg;
    float temp;
    float AF[4][3];
    float BF[4][3];
    int i;
    LOG_TRACE("(%p, %p)", B, A);

    (void)B;
    (void)A;
    (void)idet;
    (void)det;
    (void)pos;
    (void)neg;
    (void)temp;
    (void)AF;
    (void)BF;
    (void)i;

    return original_BrMatrix34Inverse(B, A);
}

static void(__cdecl*original_BrMatrix34LPInverse)(br_matrix34 *, br_matrix34 *) = (void(__cdecl*)(br_matrix34 *, br_matrix34 *))0x004d1480;
CARM95_HOOK_FUNCTION(original_BrMatrix34LPInverse, BrMatrix34LPInverse)
void __cdecl BrMatrix34LPInverse(br_matrix34 *A, br_matrix34 *B) {
    LOG_TRACE("(%p, %p)", A, B);

    (void)A;
    (void)B;

    original_BrMatrix34LPInverse(A, B);
}

static void(__cdecl*original_BrMatrix34LPNormalise)(br_matrix34 *, br_matrix34 *) = (void(__cdecl*)(br_matrix34 *, br_matrix34 *))0x004d1520;
CARM95_HOOK_FUNCTION(original_BrMatrix34LPNormalise, BrMatrix34LPNormalise)
void __cdecl BrMatrix34LPNormalise(br_matrix34 *A, br_matrix34 *B) {
    br_scalar __block0___scale;
    br_scalar __block1___scale;
    LOG_TRACE("(%p, %p)", A, B);

    (void)A;
    (void)B;
    (void)__block0___scale;
    (void)__block1___scale;

    original_BrMatrix34LPNormalise(A, B);
}

static void(__cdecl*original_BrMatrix34RollingBall)(br_matrix34 *, int, int, int) = (void(__cdecl*)(br_matrix34 *, int, int, int))0x004d1670;
CARM95_HOOK_FUNCTION(original_BrMatrix34RollingBall, BrMatrix34RollingBall)
void __cdecl BrMatrix34RollingBall(br_matrix34 *mat, int dx, int dy, int radius) {
    br_scalar nx;
    br_scalar ny;
    br_scalar ca;
    br_scalar sa;
    br_scalar dr;
    br_scalar h;
    LOG_TRACE("(%p, %d, %d, %d)", mat, dx, dy, radius);

    (void)mat;
    (void)dx;
    (void)dy;
    (void)radius;
    (void)nx;
    (void)ny;
    (void)ca;
    (void)sa;
    (void)dr;
    (void)h;

    original_BrMatrix34RollingBall(mat, dx, dy, radius);
}

br_matrix34* BrBoundsToMatrix34(br_matrix34 *mat, br_bounds *bounds) {
    int i;
    br_vector3 tr;
    br_vector3 sc;
    LOG_TRACE("(%p, %p)", mat, bounds);

    (void)mat;
    (void)bounds;
    (void)i;
    (void)tr;
    (void)sc;

    NOT_IMPLEMENTED();
}

static void(__cdecl*original_BrMatrix34Copy4)(br_matrix34 *, br_matrix4 *) = (void(__cdecl*)(br_matrix34 *, br_matrix4 *))0x004d18c0;
CARM95_HOOK_FUNCTION(original_BrMatrix34Copy4, BrMatrix34Copy4)
void __cdecl BrMatrix34Copy4(br_matrix34 *A, br_matrix4 *B) {
    LOG_TRACE("(%p, %p)", A, B);

    (void)A;
    (void)B;

    original_BrMatrix34Copy4(A, B);
}

static void(__stdcall*original_BrMatrix34TApplyFV)(br_vector3 *, br_fvector3 *, br_matrix34 *) = (void(__stdcall*)(br_vector3 *, br_fvector3 *, br_matrix34 *))0x004d1920;
CARM95_HOOK_FUNCTION(original_BrMatrix34TApplyFV, BrMatrix34TApplyFV)
void __stdcall BrMatrix34TApplyFV(br_vector3 *A, br_fvector3 *B, br_matrix34 *C) {
    LOG_TRACE("(%p, %p, %p)", A, B, C);

    (void)A;
    (void)B;
    (void)C;

    original_BrMatrix34TApplyFV(A, B, C);
}

static void(__cdecl*original_BrMatrix34Apply)(br_vector3 *, br_vector4 *, br_matrix34 *) = (void(__cdecl*)(br_vector3 *, br_vector4 *, br_matrix34 *))0x004d1980;
CARM95_HOOK_FUNCTION(original_BrMatrix34Apply, BrMatrix34Apply)
void __cdecl BrMatrix34Apply(br_vector3 *A, br_vector4 *B, br_matrix34 *C) {
    LOG_TRACE("(%p, %p, %p)", A, B, C);

    (void)A;
    (void)B;
    (void)C;

    original_BrMatrix34Apply(A, B, C);
}

static void(__cdecl*original_BrMatrix34ApplyP)(br_vector3 *, br_vector3 *, br_matrix34 *) = (void(__cdecl*)(br_vector3 *, br_vector3 *, br_matrix34 *))0x004d1a00;
CARM95_HOOK_FUNCTION(original_BrMatrix34ApplyP, BrMatrix34ApplyP)
void __cdecl BrMatrix34ApplyP(br_vector3 *A, br_vector3 *B, br_matrix34 *C) {
    LOG_TRACE("(%p, %p, %p)", A, B, C);

    (void)A;
    (void)B;
    (void)C;

    original_BrMatrix34ApplyP(A, B, C);
}

static void(__cdecl*original_BrMatrix34ApplyV)(br_vector3 *, br_vector3 *, br_matrix34 *) = (void(__cdecl*)(br_vector3 *, br_vector3 *, br_matrix34 *))0x004d1a70;
CARM95_HOOK_FUNCTION(original_BrMatrix34ApplyV, BrMatrix34ApplyV)
void __cdecl BrMatrix34ApplyV(br_vector3 *A, br_vector3 *B, br_matrix34 *C) {
    LOG_TRACE("(%p, %p, %p)", A, B, C);

    (void)A;
    (void)B;
    (void)C;

    original_BrMatrix34ApplyV(A, B, C);
}

static void(__cdecl*original_BrMatrix34TApply)(br_vector4 *, br_vector4 *, br_matrix34 *) = (void(__cdecl*)(br_vector4 *, br_vector4 *, br_matrix34 *))0x004d1ad0;
CARM95_HOOK_FUNCTION(original_BrMatrix34TApply, BrMatrix34TApply)
void __cdecl BrMatrix34TApply(br_vector4 *A, br_vector4 *B, br_matrix34 *C) {
    LOG_TRACE("(%p, %p, %p)", A, B, C);

    (void)A;
    (void)B;
    (void)C;

    original_BrMatrix34TApply(A, B, C);
}

static void(__cdecl*original_BrMatrix34TApplyP)(br_vector3 *, br_vector3 *, br_matrix34 *) = (void(__cdecl*)(br_vector3 *, br_vector3 *, br_matrix34 *))0x004d1b46;
CARM95_HOOK_FUNCTION(original_BrMatrix34TApplyP, BrMatrix34TApplyP)
void __cdecl BrMatrix34TApplyP(br_vector3 *A, br_vector3 *B, br_matrix34 *C) {
    LOG_TRACE("(%p, %p, %p)", A, B, C);

    (void)A;
    (void)B;
    (void)C;

    original_BrMatrix34TApplyP(A, B, C);
}

static void(__cdecl*original_BrMatrix34TApplyV)(br_vector3 *, br_vector3 *, br_matrix34 *) = (void(__cdecl*)(br_vector3 *, br_vector3 *, br_matrix34 *))0x004d1bb0;
CARM95_HOOK_FUNCTION(original_BrMatrix34TApplyV, BrMatrix34TApplyV)
void __cdecl BrMatrix34TApplyV(br_vector3 *A, br_vector3 *B, br_matrix34 *C) {
    LOG_TRACE("(%p, %p, %p)", A, B, C);

    (void)A;
    (void)B;
    (void)C;

    original_BrMatrix34TApplyV(A, B, C);
}

static void(__cdecl*original_BrMatrix34Pre)(br_matrix34 *, br_matrix34 *) = (void(__cdecl*)(br_matrix34 *, br_matrix34 *))0x004d1c10;
CARM95_HOOK_FUNCTION(original_BrMatrix34Pre, BrMatrix34Pre)
void __cdecl BrMatrix34Pre(br_matrix34 *mat, br_matrix34 *A) {
    LOG_TRACE("(%p, %p)", mat, A);

    (void)mat;
    (void)A;

    original_BrMatrix34Pre(mat, A);
}

static void(__cdecl*original_BrMatrix34Post)(br_matrix34 *, br_matrix34 *) = (void(__cdecl*)(br_matrix34 *, br_matrix34 *))0x004d1c40;
CARM95_HOOK_FUNCTION(original_BrMatrix34Post, BrMatrix34Post)
void __cdecl BrMatrix34Post(br_matrix34 *mat, br_matrix34 *A) {
    LOG_TRACE("(%p, %p)", mat, A);

    (void)mat;
    (void)A;

    original_BrMatrix34Post(mat, A);
}

static void(__cdecl*original_BrMatrix34PreRotateX)(br_matrix34 *, br_angle) = (void(__cdecl*)(br_matrix34 *, br_angle))0x004d1c70;
CARM95_HOOK_FUNCTION(original_BrMatrix34PreRotateX, BrMatrix34PreRotateX)
void __cdecl BrMatrix34PreRotateX(br_matrix34 *mat, br_angle rx) {
    LOG_TRACE("(%p, %u)", mat, rx);

    (void)mat;
    (void)rx;

    original_BrMatrix34PreRotateX(mat, rx);
}

static void(__cdecl*original_BrMatrix34PostRotateX)(br_matrix34 *, br_angle) = (void(__cdecl*)(br_matrix34 *, br_angle))0x004d1d10;
CARM95_HOOK_FUNCTION(original_BrMatrix34PostRotateX, BrMatrix34PostRotateX)
void __cdecl BrMatrix34PostRotateX(br_matrix34 *mat, br_angle rx) {
    LOG_TRACE("(%p, %u)", mat, rx);

    (void)mat;
    (void)rx;

    original_BrMatrix34PostRotateX(mat, rx);
}

static void(__cdecl*original_BrMatrix34PreRotateY)(br_matrix34 *, br_angle) = (void(__cdecl*)(br_matrix34 *, br_angle))0x004d1db0;
CARM95_HOOK_FUNCTION(original_BrMatrix34PreRotateY, BrMatrix34PreRotateY)
void __cdecl BrMatrix34PreRotateY(br_matrix34 *mat, br_angle ry) {
    LOG_TRACE("(%p, %u)", mat, ry);

    (void)mat;
    (void)ry;

    original_BrMatrix34PreRotateY(mat, ry);
}

static void(__cdecl*original_BrMatrix34PostRotateY)(br_matrix34 *, br_angle) = (void(__cdecl*)(br_matrix34 *, br_angle))0x004d1e50;
CARM95_HOOK_FUNCTION(original_BrMatrix34PostRotateY, BrMatrix34PostRotateY)
void __cdecl BrMatrix34PostRotateY(br_matrix34 *mat, br_angle ry) {
    LOG_TRACE("(%p, %u)", mat, ry);

    (void)mat;
    (void)ry;

    original_BrMatrix34PostRotateY(mat, ry);
}

static void(__cdecl*original_BrMatrix34PreRotateZ)(br_matrix34 *, br_angle) = (void(__cdecl*)(br_matrix34 *, br_angle))0x004d1ef0;
CARM95_HOOK_FUNCTION(original_BrMatrix34PreRotateZ, BrMatrix34PreRotateZ)
void __cdecl BrMatrix34PreRotateZ(br_matrix34 *mat, br_angle rz) {
    LOG_TRACE("(%p, %u)", mat, rz);

    (void)mat;
    (void)rz;

    original_BrMatrix34PreRotateZ(mat, rz);
}

static void(__cdecl*original_BrMatrix34PostRotateZ)(br_matrix34 *, br_angle) = (void(__cdecl*)(br_matrix34 *, br_angle))0x004d1f90;
CARM95_HOOK_FUNCTION(original_BrMatrix34PostRotateZ, BrMatrix34PostRotateZ)
void __cdecl BrMatrix34PostRotateZ(br_matrix34 *mat, br_angle rz) {
    LOG_TRACE("(%p, %u)", mat, rz);

    (void)mat;
    (void)rz;

    original_BrMatrix34PostRotateZ(mat, rz);
}

static void(__cdecl*original_BrMatrix34PreRotate)(br_matrix34 *, br_angle, br_vector3 *) = (void(__cdecl*)(br_matrix34 *, br_angle, br_vector3 *))0x004d2030;
CARM95_HOOK_FUNCTION(original_BrMatrix34PreRotate, BrMatrix34PreRotate)
void __cdecl BrMatrix34PreRotate(br_matrix34 *mat, br_angle r, br_vector3 *axis) {
    LOG_TRACE("(%p, %u, %p)", mat, r, axis);

    (void)mat;
    (void)r;
    (void)axis;

    original_BrMatrix34PreRotate(mat, r, axis);
}

static void(__cdecl*original_BrMatrix34PostRotate)(br_matrix34 *, br_angle, br_vector3 *) = (void(__cdecl*)(br_matrix34 *, br_angle, br_vector3 *))0x004d2070;
CARM95_HOOK_FUNCTION(original_BrMatrix34PostRotate, BrMatrix34PostRotate)
void __cdecl BrMatrix34PostRotate(br_matrix34 *mat, br_angle r, br_vector3 *axis) {
    LOG_TRACE("(%p, %u, %p)", mat, r, axis);

    (void)mat;
    (void)r;
    (void)axis;

    original_BrMatrix34PostRotate(mat, r, axis);
}

static void(__cdecl*original_BrMatrix34PreTranslate)(br_matrix34 *, br_scalar, br_scalar, br_scalar) = (void(__cdecl*)(br_matrix34 *, br_scalar, br_scalar, br_scalar))0x004d20b0;
CARM95_HOOK_FUNCTION(original_BrMatrix34PreTranslate, BrMatrix34PreTranslate)
void __cdecl BrMatrix34PreTranslate(br_matrix34 *mat, br_scalar x, br_scalar y, br_scalar z) {
    LOG_TRACE("(%p, %f, %f, %f)", mat, x, y, z);

    (void)mat;
    (void)x;
    (void)y;
    (void)z;

    original_BrMatrix34PreTranslate(mat, x, y, z);
}

static void(__cdecl*original_BrMatrix34PostTranslate)(br_matrix34 *, br_scalar, br_scalar, br_scalar) = (void(__cdecl*)(br_matrix34 *, br_scalar, br_scalar, br_scalar))0x004d2130;
CARM95_HOOK_FUNCTION(original_BrMatrix34PostTranslate, BrMatrix34PostTranslate)
void __cdecl BrMatrix34PostTranslate(br_matrix34 *mat, br_scalar x, br_scalar y, br_scalar z) {
    LOG_TRACE("(%p, %f, %f, %f)", mat, x, y, z);

    (void)mat;
    (void)x;
    (void)y;
    (void)z;

    original_BrMatrix34PostTranslate(mat, x, y, z);
}

static void(__cdecl*original_BrMatrix34PreScale)(br_matrix34 *, br_scalar, br_scalar, br_scalar) = (void(__cdecl*)(br_matrix34 *, br_scalar, br_scalar, br_scalar))0x004d21b0;
CARM95_HOOK_FUNCTION(original_BrMatrix34PreScale, BrMatrix34PreScale)
void __cdecl BrMatrix34PreScale(br_matrix34 *mat, br_scalar sx, br_scalar sy, br_scalar sz) {
    LOG_TRACE("(%p, %f, %f, %f)", mat, sx, sy, sz);

    (void)mat;
    (void)sx;
    (void)sy;
    (void)sz;

    original_BrMatrix34PreScale(mat, sx, sy, sz);
}

static void(__cdecl*original_BrMatrix34PostScale)(br_matrix34 *, br_scalar, br_scalar, br_scalar) = (void(__cdecl*)(br_matrix34 *, br_scalar, br_scalar, br_scalar))0x004d2230;
CARM95_HOOK_FUNCTION(original_BrMatrix34PostScale, BrMatrix34PostScale)
void __cdecl BrMatrix34PostScale(br_matrix34 *mat, br_scalar sx, br_scalar sy, br_scalar sz) {
    LOG_TRACE("(%p, %f, %f, %f)", mat, sx, sy, sz);

    (void)mat;
    (void)sx;
    (void)sy;
    (void)sz;

    original_BrMatrix34PostScale(mat, sx, sy, sz);
}

static void(__cdecl*original_BrMatrix34PreShearX)(br_matrix34 *, br_scalar, br_scalar) = (void(__cdecl*)(br_matrix34 *, br_scalar, br_scalar))0x004d22b0;
CARM95_HOOK_FUNCTION(original_BrMatrix34PreShearX, BrMatrix34PreShearX)
void __cdecl BrMatrix34PreShearX(br_matrix34 *mat, br_scalar sy, br_scalar sz) {
    LOG_TRACE("(%p, %f, %f)", mat, sy, sz);

    (void)mat;
    (void)sy;
    (void)sz;

    original_BrMatrix34PreShearX(mat, sy, sz);
}

static void(__cdecl*original_BrMatrix34PostShearX)(br_matrix34 *, br_scalar, br_scalar) = (void(__cdecl*)(br_matrix34 *, br_scalar, br_scalar))0x004d2330;
CARM95_HOOK_FUNCTION(original_BrMatrix34PostShearX, BrMatrix34PostShearX)
void __cdecl BrMatrix34PostShearX(br_matrix34 *mat, br_scalar sy, br_scalar sz) {
    LOG_TRACE("(%p, %f, %f)", mat, sy, sz);

    (void)mat;
    (void)sy;
    (void)sz;

    original_BrMatrix34PostShearX(mat, sy, sz);
}

static void(__cdecl*original_BrMatrix34PreShearY)(br_matrix34 *, br_scalar, br_scalar) = (void(__cdecl*)(br_matrix34 *, br_scalar, br_scalar))0x004d23b0;
CARM95_HOOK_FUNCTION(original_BrMatrix34PreShearY, BrMatrix34PreShearY)
void __cdecl BrMatrix34PreShearY(br_matrix34 *mat, br_scalar sx, br_scalar sz) {
    LOG_TRACE("(%p, %f, %f)", mat, sx, sz);

    (void)mat;
    (void)sx;
    (void)sz;

    original_BrMatrix34PreShearY(mat, sx, sz);
}

static void(__cdecl*original_BrMatrix34PostShearY)(br_matrix34 *, br_scalar, br_scalar) = (void(__cdecl*)(br_matrix34 *, br_scalar, br_scalar))0x004d2430;
CARM95_HOOK_FUNCTION(original_BrMatrix34PostShearY, BrMatrix34PostShearY)
void __cdecl BrMatrix34PostShearY(br_matrix34 *mat, br_scalar sx, br_scalar sz) {
    LOG_TRACE("(%p, %f, %f)", mat, sx, sz);

    (void)mat;
    (void)sx;
    (void)sz;

    original_BrMatrix34PostShearY(mat, sx, sz);
}

static void(__cdecl*original_BrMatrix34PreShearZ)(br_matrix34 *, br_scalar, br_scalar) = (void(__cdecl*)(br_matrix34 *, br_scalar, br_scalar))0x004d24b0;
CARM95_HOOK_FUNCTION(original_BrMatrix34PreShearZ, BrMatrix34PreShearZ)
void __cdecl BrMatrix34PreShearZ(br_matrix34 *mat, br_scalar sx, br_scalar sy) {
    LOG_TRACE("(%p, %f, %f)", mat, sx, sy);

    (void)mat;
    (void)sx;
    (void)sy;

    original_BrMatrix34PreShearZ(mat, sx, sy);
}

static void(__cdecl*original_BrMatrix34PostShearZ)(br_matrix34 *, br_scalar, br_scalar) = (void(__cdecl*)(br_matrix34 *, br_scalar, br_scalar))0x004d2530;
CARM95_HOOK_FUNCTION(original_BrMatrix34PostShearZ, BrMatrix34PostShearZ)
void __cdecl BrMatrix34PostShearZ(br_matrix34 *mat, br_scalar sx, br_scalar sy) {
    LOG_TRACE("(%p, %f, %f)", mat, sx, sy);

    (void)mat;
    (void)sx;
    (void)sy;

    original_BrMatrix34PostShearZ(mat, sx, sy);
}
