#include "matrix23.h"

#include "harness/trace.h"

#include "carm95_hooks.h"

 // Suffix added to avoid duplicate symbol
#if 0
br_matrix23 * hookvar_mattmp1__matrix23 ;
#endif
 // Suffix added to avoid duplicate symbol
#if 0
br_matrix23 * hookvar_mattmp2__matrix23 ;
#endif

static void(__cdecl*original_BrMatrix23Copy)(br_matrix23 *, br_matrix23 *) = (void(__cdecl*)(br_matrix23 *, br_matrix23 *))0x004d3190;
CARM95_HOOK_FUNCTION(original_BrMatrix23Copy, BrMatrix23Copy)
void __cdecl BrMatrix23Copy(br_matrix23 *A, br_matrix23 *B) {
    LOG_TRACE("(%p, %p)", A, B);

    (void)A;
    (void)B;

    original_BrMatrix23Copy(A, B);
}

static void(__cdecl*original_BrMatrix23Mul)(br_matrix23 *, br_matrix23 *, br_matrix23 *) = (void(__cdecl*)(br_matrix23 *, br_matrix23 *, br_matrix23 *))0x004d31c0;
CARM95_HOOK_FUNCTION(original_BrMatrix23Mul, BrMatrix23Mul)
void __cdecl BrMatrix23Mul(br_matrix23 *A, br_matrix23 *B, br_matrix23 *C) {
    LOG_TRACE("(%p, %p, %p)", A, B, C);

    (void)A;
    (void)B;
    (void)C;

    original_BrMatrix23Mul(A, B, C);
}

static void(__cdecl*original_BrMatrix23Identity)(br_matrix23 *) = (void(__cdecl*)(br_matrix23 *))0x004d3240;
CARM95_HOOK_FUNCTION(original_BrMatrix23Identity, BrMatrix23Identity)
void __cdecl BrMatrix23Identity(br_matrix23 *mat) {
    LOG_TRACE("(%p)", mat);

    (void)mat;

    original_BrMatrix23Identity(mat);
}

static void(__cdecl*original_BrMatrix23Rotate)(br_matrix23 *, br_angle) = (void(__cdecl*)(br_matrix23 *, br_angle))0x004d3260;
CARM95_HOOK_FUNCTION(original_BrMatrix23Rotate, BrMatrix23Rotate)
void __cdecl BrMatrix23Rotate(br_matrix23 *mat, br_angle rz) {
    br_scalar s;
    br_scalar c;
    LOG_TRACE("(%p, %u)", mat, rz);

    (void)mat;
    (void)rz;
    (void)s;
    (void)c;

    original_BrMatrix23Rotate(mat, rz);
}

static void(__cdecl*original_BrMatrix23Translate)(br_matrix23 *, br_scalar, br_scalar) = (void(__cdecl*)(br_matrix23 *, br_scalar, br_scalar))0x004d32a5;
CARM95_HOOK_FUNCTION(original_BrMatrix23Translate, BrMatrix23Translate)
void __cdecl BrMatrix23Translate(br_matrix23 *mat, br_scalar dx, br_scalar dy) {
    LOG_TRACE("(%p, %f, %f)", mat, dx, dy);

    (void)mat;
    (void)dx;
    (void)dy;

    original_BrMatrix23Translate(mat, dx, dy);
}

static void(__cdecl*original_BrMatrix23Scale)(br_matrix23 *, br_scalar, br_scalar) = (void(__cdecl*)(br_matrix23 *, br_scalar, br_scalar))0x004d32da;
CARM95_HOOK_FUNCTION(original_BrMatrix23Scale, BrMatrix23Scale)
void __cdecl BrMatrix23Scale(br_matrix23 *mat, br_scalar sx, br_scalar sy) {
    LOG_TRACE("(%p, %f, %f)", mat, sx, sy);

    (void)mat;
    (void)sx;
    (void)sy;

    original_BrMatrix23Scale(mat, sx, sy);
}

static void(__cdecl*original_BrMatrix23ShearX)(br_matrix23 *, br_scalar) = (void(__cdecl*)(br_matrix23 *, br_scalar))0x004d3300;
CARM95_HOOK_FUNCTION(original_BrMatrix23ShearX, BrMatrix23ShearX)
void __cdecl BrMatrix23ShearX(br_matrix23 *mat, br_scalar sy) {
    LOG_TRACE("(%p, %f)", mat, sy);

    (void)mat;
    (void)sy;

    original_BrMatrix23ShearX(mat, sy);
}

static void(__cdecl*original_BrMatrix23ShearY)(br_matrix23 *, br_scalar) = (void(__cdecl*)(br_matrix23 *, br_scalar))0x004d3324;
CARM95_HOOK_FUNCTION(original_BrMatrix23ShearY, BrMatrix23ShearY)
void __cdecl BrMatrix23ShearY(br_matrix23 *mat, br_scalar sx) {
    LOG_TRACE("(%p, %f)", mat, sx);

    (void)mat;
    (void)sx;

    original_BrMatrix23ShearY(mat, sx);
}

static br_scalar(__cdecl*original_BrMatrix23Inverse)(br_matrix23 *, br_matrix23 *) = (br_scalar(__cdecl*)(br_matrix23 *, br_matrix23 *))0x004d3355;
CARM95_HOOK_FUNCTION(original_BrMatrix23Inverse, BrMatrix23Inverse)
br_scalar __cdecl BrMatrix23Inverse(br_matrix23 *B, br_matrix23 *A) {
    br_scalar det;
    br_scalar idet;
    br_scalar pos;
    br_scalar neg;
    LOG_TRACE("(%p, %p)", B, A);

    (void)B;
    (void)A;
    (void)det;
    (void)idet;
    (void)pos;
    (void)neg;

    return original_BrMatrix23Inverse(B, A);
}

static void(__cdecl*original_BrMatrix23LPInverse)(br_matrix23 *, br_matrix23 *) = (void(__cdecl*)(br_matrix23 *, br_matrix23 *))0x004d3477;
CARM95_HOOK_FUNCTION(original_BrMatrix23LPInverse, BrMatrix23LPInverse)
void __cdecl BrMatrix23LPInverse(br_matrix23 *B, br_matrix23 *A) {
    LOG_TRACE("(%p, %p)", B, A);

    (void)B;
    (void)A;

    original_BrMatrix23LPInverse(B, A);
}

static void(__cdecl*original_BrMatrix23LPNormalise)(br_matrix23 *, br_matrix23 *) = (void(__cdecl*)(br_matrix23 *, br_matrix23 *))0x004d34c6;
CARM95_HOOK_FUNCTION(original_BrMatrix23LPNormalise, BrMatrix23LPNormalise)
void __cdecl BrMatrix23LPNormalise(br_matrix23 *A, br_matrix23 *B) {
    br_scalar __block0___scale;
    LOG_TRACE("(%p, %p)", A, B);

    (void)A;
    (void)B;
    (void)__block0___scale;

    original_BrMatrix23LPNormalise(A, B);
}

static void(__cdecl*original_BrMatrix23ApplyP)(br_vector2 *, br_vector2 *, br_matrix23 *) = (void(__cdecl*)(br_vector2 *, br_vector2 *, br_matrix23 *))0x004d3543;
CARM95_HOOK_FUNCTION(original_BrMatrix23ApplyP, BrMatrix23ApplyP)
void __cdecl BrMatrix23ApplyP(br_vector2 *A, br_vector2 *B, br_matrix23 *C) {
    LOG_TRACE("(%p, %p, %p)", A, B, C);

    (void)A;
    (void)B;
    (void)C;

    original_BrMatrix23ApplyP(A, B, C);
}

static void(__cdecl*original_BrMatrix23ApplyV)(br_vector2 *, br_vector2 *, br_matrix23 *) = (void(__cdecl*)(br_vector2 *, br_vector2 *, br_matrix23 *))0x004d3581;
CARM95_HOOK_FUNCTION(original_BrMatrix23ApplyV, BrMatrix23ApplyV)
void __cdecl BrMatrix23ApplyV(br_vector2 *A, br_vector2 *B, br_matrix23 *C) {
    LOG_TRACE("(%p, %p, %p)", A, B, C);

    (void)A;
    (void)B;
    (void)C;

    original_BrMatrix23ApplyV(A, B, C);
}

static void(__cdecl*original_BrMatrix23TApplyP)(br_vector2 *, br_vector2 *, br_matrix23 *) = (void(__cdecl*)(br_vector2 *, br_vector2 *, br_matrix23 *))0x004d35bb;
CARM95_HOOK_FUNCTION(original_BrMatrix23TApplyP, BrMatrix23TApplyP)
void __cdecl BrMatrix23TApplyP(br_vector2 *A, br_vector2 *B, br_matrix23 *C) {
    LOG_TRACE("(%p, %p, %p)", A, B, C);

    (void)A;
    (void)B;
    (void)C;

    original_BrMatrix23TApplyP(A, B, C);
}

static void(__cdecl*original_BrMatrix23TApplyV)(br_vector2 *, br_vector2 *, br_matrix23 *) = (void(__cdecl*)(br_vector2 *, br_vector2 *, br_matrix23 *))0x004d35eb;
CARM95_HOOK_FUNCTION(original_BrMatrix23TApplyV, BrMatrix23TApplyV)
void __cdecl BrMatrix23TApplyV(br_vector2 *A, br_vector2 *B, br_matrix23 *C) {
    LOG_TRACE("(%p, %p, %p)", A, B, C);

    (void)A;
    (void)B;
    (void)C;

    original_BrMatrix23TApplyV(A, B, C);
}

static void(__cdecl*original_BrMatrix23Pre)(br_matrix23 *, br_matrix23 *) = (void(__cdecl*)(br_matrix23 *, br_matrix23 *))0x004d361b;
CARM95_HOOK_FUNCTION(original_BrMatrix23Pre, BrMatrix23Pre)
void __cdecl BrMatrix23Pre(br_matrix23 *mat, br_matrix23 *A) {
    LOG_TRACE("(%p, %p)", mat, A);

    (void)mat;
    (void)A;

    original_BrMatrix23Pre(mat, A);
}

static void(__cdecl*original_BrMatrix23Post)(br_matrix23 *, br_matrix23 *) = (void(__cdecl*)(br_matrix23 *, br_matrix23 *))0x004d366d;
CARM95_HOOK_FUNCTION(original_BrMatrix23Post, BrMatrix23Post)
void __cdecl BrMatrix23Post(br_matrix23 *mat, br_matrix23 *A) {
    LOG_TRACE("(%p, %p)", mat, A);

    (void)mat;
    (void)A;

    original_BrMatrix23Post(mat, A);
}

static void(__cdecl*original_BrMatrix23PreRotate)(br_matrix23 *, br_angle) = (void(__cdecl*)(br_matrix23 *, br_angle))0x004d36bd;
CARM95_HOOK_FUNCTION(original_BrMatrix23PreRotate, BrMatrix23PreRotate)
void __cdecl BrMatrix23PreRotate(br_matrix23 *mat, br_angle rz) {
    LOG_TRACE("(%p, %u)", mat, rz);

    (void)mat;
    (void)rz;

    original_BrMatrix23PreRotate(mat, rz);
}

static void(__cdecl*original_BrMatrix23PostRotate)(br_matrix23 *, br_angle) = (void(__cdecl*)(br_matrix23 *, br_angle))0x004d375e;
CARM95_HOOK_FUNCTION(original_BrMatrix23PostRotate, BrMatrix23PostRotate)
void __cdecl BrMatrix23PostRotate(br_matrix23 *mat, br_angle rz) {
    LOG_TRACE("(%p, %u)", mat, rz);

    (void)mat;
    (void)rz;

    original_BrMatrix23PostRotate(mat, rz);
}

static void(__cdecl*original_BrMatrix23PreTranslate)(br_matrix23 *, br_scalar, br_scalar) = (void(__cdecl*)(br_matrix23 *, br_scalar, br_scalar))0x004d37fe;
CARM95_HOOK_FUNCTION(original_BrMatrix23PreTranslate, BrMatrix23PreTranslate)
void __cdecl BrMatrix23PreTranslate(br_matrix23 *mat, br_scalar x, br_scalar y) {
    LOG_TRACE("(%p, %f, %f)", mat, x, y);

    (void)mat;
    (void)x;
    (void)y;

    original_BrMatrix23PreTranslate(mat, x, y);
}

static void(__cdecl*original_BrMatrix23PostTranslate)(br_matrix23 *, br_scalar, br_scalar) = (void(__cdecl*)(br_matrix23 *, br_scalar, br_scalar))0x004d387d;
CARM95_HOOK_FUNCTION(original_BrMatrix23PostTranslate, BrMatrix23PostTranslate)
void __cdecl BrMatrix23PostTranslate(br_matrix23 *A, br_scalar x, br_scalar y) {
    LOG_TRACE("(%p, %f, %f)", A, x, y);

    (void)A;
    (void)x;
    (void)y;

    original_BrMatrix23PostTranslate(A, x, y);
}

static void(__cdecl*original_BrMatrix23PreScale)(br_matrix23 *, br_scalar, br_scalar) = (void(__cdecl*)(br_matrix23 *, br_scalar, br_scalar))0x004d389b;
CARM95_HOOK_FUNCTION(original_BrMatrix23PreScale, BrMatrix23PreScale)
void __cdecl BrMatrix23PreScale(br_matrix23 *mat, br_scalar sx, br_scalar sy) {
    LOG_TRACE("(%p, %f, %f)", mat, sx, sy);

    (void)mat;
    (void)sx;
    (void)sy;

    original_BrMatrix23PreScale(mat, sx, sy);
}

static void(__cdecl*original_BrMatrix23PostScale)(br_matrix23 *, br_scalar, br_scalar) = (void(__cdecl*)(br_matrix23 *, br_scalar, br_scalar))0x004d3920;
CARM95_HOOK_FUNCTION(original_BrMatrix23PostScale, BrMatrix23PostScale)
void __cdecl BrMatrix23PostScale(br_matrix23 *mat, br_scalar sx, br_scalar sy) {
    LOG_TRACE("(%p, %f, %f)", mat, sx, sy);

    (void)mat;
    (void)sx;
    (void)sy;

    original_BrMatrix23PostScale(mat, sx, sy);
}

static void(__cdecl*original_BrMatrix23PreShearX)(br_matrix23 *, br_scalar) = (void(__cdecl*)(br_matrix23 *, br_scalar))0x004d3996;
CARM95_HOOK_FUNCTION(original_BrMatrix23PreShearX, BrMatrix23PreShearX)
void __cdecl BrMatrix23PreShearX(br_matrix23 *mat, br_scalar sy) {
    LOG_TRACE("(%p, %f)", mat, sy);

    (void)mat;
    (void)sy;

    original_BrMatrix23PreShearX(mat, sy);
}

static void(__cdecl*original_BrMatrix23PostShearX)(br_matrix23 *, br_scalar) = (void(__cdecl*)(br_matrix23 *, br_scalar))0x004d3a18;
CARM95_HOOK_FUNCTION(original_BrMatrix23PostShearX, BrMatrix23PostShearX)
void __cdecl BrMatrix23PostShearX(br_matrix23 *mat, br_scalar sy) {
    LOG_TRACE("(%p, %f)", mat, sy);

    (void)mat;
    (void)sy;

    original_BrMatrix23PostShearX(mat, sy);
}

static void(__cdecl*original_BrMatrix23PreShearY)(br_matrix23 *, br_scalar) = (void(__cdecl*)(br_matrix23 *, br_scalar))0x004d3a98;
CARM95_HOOK_FUNCTION(original_BrMatrix23PreShearY, BrMatrix23PreShearY)
void __cdecl BrMatrix23PreShearY(br_matrix23 *mat, br_scalar sx) {
    LOG_TRACE("(%p, %f)", mat, sx);

    (void)mat;
    (void)sx;

    original_BrMatrix23PreShearY(mat, sx);
}

static void(__cdecl*original_BrMatrix23PostShearY)(br_matrix23 *, br_scalar) = (void(__cdecl*)(br_matrix23 *, br_scalar))0x004d3b1a;
CARM95_HOOK_FUNCTION(original_BrMatrix23PostShearY, BrMatrix23PostShearY)
void __cdecl BrMatrix23PostShearY(br_matrix23 *mat, br_scalar sx) {
    LOG_TRACE("(%p, %f)", mat, sx);

    (void)mat;
    (void)sx;

    original_BrMatrix23PostShearY(mat, sx);
}

