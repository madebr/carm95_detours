#include "matrix4.h"

#include "harness/trace.h"

#include "carm95_hooks.h"

#include <stdio.h>

static void(*original_BrMatrix4Copy)(br_matrix4 *, br_matrix4 *, ...) = (void(*)(br_matrix4 *, br_matrix4 *, ...))0x004d3ba0;
CARM95_HOOK_FUNCTION(original_BrMatrix4Copy, BrMatrix4Copy)
void BrMatrix4Copy(br_matrix4 *A, br_matrix4 *B) {
    LOG_TRACE("(%p, %p)", A, B);

    (void)A;
    (void)B;

    original_BrMatrix4Copy(A, B);
}

static void(*original_BrMatrix4Mul)(br_matrix4 *, br_matrix4 *, br_matrix4 *, ...) = (void(*)(br_matrix4 *, br_matrix4 *, br_matrix4 *, ...))0x004d3c10;
CARM95_HOOK_FUNCTION(original_BrMatrix4Mul, BrMatrix4Mul)
void BrMatrix4Mul(br_matrix4 *A, br_matrix4 *B, br_matrix4 *C) {
    LOG_TRACE("(%p, %p, %p)", A, B, C);

    (void)A;
    (void)B;
    (void)C;

    original_BrMatrix4Mul(A, B, C);
}

static void(*original_BrMatrix4Identity)(br_matrix4 *, ...) = (void(*)(br_matrix4 *, ...))0x004d3e64;
CARM95_HOOK_FUNCTION(original_BrMatrix4Identity, BrMatrix4Identity)
void BrMatrix4Identity(br_matrix4 *mat) {
    LOG_TRACE("(%p)", mat);

    (void)mat;

    original_BrMatrix4Identity(mat);
}

static void(*original_BrMatrix4Scale)(br_matrix4 *, br_scalar, br_scalar, br_scalar, ...) = (void(*)(br_matrix4 *, br_scalar, br_scalar, br_scalar, ...))0x004d3eb0;
CARM95_HOOK_FUNCTION(original_BrMatrix4Scale, BrMatrix4Scale)
void BrMatrix4Scale(br_matrix4 *mat, br_scalar sx, br_scalar sy, br_scalar sz) {
    LOG_TRACE("(%p, %f, %f, %f)", mat, sx, sy, sz);

    (void)mat;
    (void)sx;
    (void)sy;
    (void)sz;

    original_BrMatrix4Scale(mat, sx, sy, sz);
}

static br_scalar(*original_BrMatrix4Inverse)(br_matrix4 *, br_matrix4 *, ...) = (br_scalar(*)(br_matrix4 *, br_matrix4 *, ...))0x004d3f00;
CARM95_HOOK_FUNCTION(original_BrMatrix4Inverse, BrMatrix4Inverse)
br_scalar BrMatrix4Inverse(br_matrix4 *A, br_matrix4 *B) {
    int i;
    int j;
    br_scalar det;
    br_scalar idet;
    LOG_TRACE("(%p, %p)", A, B);

    (void)A;
    (void)B;
    (void)i;
    (void)j;
    (void)det;
    (void)idet;

    return original_BrMatrix4Inverse(A, B);
}

static br_scalar(*original_Determinant3)(br_scalar, br_scalar, br_scalar, br_scalar, br_scalar, br_scalar, br_scalar, br_scalar, br_scalar, ...) = (br_scalar(*)(br_scalar, br_scalar, br_scalar, br_scalar, br_scalar, br_scalar, br_scalar, br_scalar, br_scalar, ...))0x004d4590;
CARM95_HOOK_FUNCTION(original_Determinant3, Determinant3)
br_scalar Determinant3(br_scalar a1, br_scalar a2, br_scalar a3, br_scalar b1, br_scalar b2, br_scalar b3, br_scalar c1, br_scalar c2, br_scalar c3) {
    LOG_TRACE("(%f, %f, %f, %f, %f, %f, %f, %f, %f)", a1, a2, a3, b1, b2, b3, c1, c2, c3);

    (void)a1;
    (void)a2;
    (void)a3;
    (void)b1;
    (void)b2;
    (void)b3;
    (void)c1;
    (void)c2;
    (void)c3;

    return original_Determinant3(a1, a2, a3, b1, b2, b3, c1, c2, c3);
}

static br_scalar(*original_BrMatrix4Determinant)(br_matrix4 *, ...) = (br_scalar(*)(br_matrix4 *, ...))0x004d3f80;
CARM95_HOOK_FUNCTION(original_BrMatrix4Determinant, BrMatrix4Determinant)
br_scalar BrMatrix4Determinant(br_matrix4 *mat) {
    br_scalar a1;
    br_scalar a2;
    br_scalar a3;
    br_scalar a4;
    br_scalar b1;
    br_scalar b2;
    br_scalar b3;
    br_scalar b4;
    br_scalar c1;
    br_scalar c2;
    br_scalar c3;
    br_scalar c4;
    br_scalar d1;
    br_scalar d2;
    br_scalar d3;
    br_scalar d4;
    LOG_TRACE("(%p)", mat);

    (void)mat;
    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)b1;
    (void)b2;
    (void)b3;
    (void)b4;
    (void)c1;
    (void)c2;
    (void)c3;
    (void)c4;
    (void)d1;
    (void)d2;
    (void)d3;
    (void)d4;

    return original_BrMatrix4Determinant(mat);
}

static void(*original_BrMatrix4Adjoint)(br_matrix4 *, br_matrix4 *, ...) = (void(*)(br_matrix4 *, br_matrix4 *, ...))0x004d4120;
CARM95_HOOK_FUNCTION(original_BrMatrix4Adjoint, BrMatrix4Adjoint)
void BrMatrix4Adjoint(br_matrix4 *A, br_matrix4 *B) {
    br_scalar a1;
    br_scalar a2;
    br_scalar a3;
    br_scalar a4;
    br_scalar b1;
    br_scalar b2;
    br_scalar b3;
    br_scalar b4;
    br_scalar c1;
    br_scalar c2;
    br_scalar c3;
    br_scalar c4;
    br_scalar d1;
    br_scalar d2;
    br_scalar d3;
    br_scalar d4;
    LOG_TRACE("(%p, %p)", A, B);

    (void)A;
    (void)B;
    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)b1;
    (void)b2;
    (void)b3;
    (void)b4;
    (void)c1;
    (void)c2;
    (void)c3;
    (void)c4;
    (void)d1;
    (void)d2;
    (void)d3;
    (void)d4;

    original_BrMatrix4Adjoint(A, B);
}

static void(*original_BrMatrix4Perspective)(br_matrix4 *, br_angle, br_scalar, br_scalar, br_scalar, ...) = (void(*)(br_matrix4 *, br_angle, br_scalar, br_scalar, br_scalar, ...))0x004d45f0;
CARM95_HOOK_FUNCTION(original_BrMatrix4Perspective, BrMatrix4Perspective)
void BrMatrix4Perspective(br_matrix4 *mat, br_angle field_of_view, br_scalar aspect, br_scalar hither, br_scalar yon) {
    br_scalar scale;
    LOG_TRACE("(%p, %u, %f, %f, %f)", mat, field_of_view, aspect, hither, yon);

    (void)mat;
    (void)field_of_view;
    (void)aspect;
    (void)hither;
    (void)yon;
    (void)scale;

    original_BrMatrix4Perspective(mat, field_of_view, aspect, hither, yon);
}

static void(*original_BrMatrix4Apply)(br_vector4 *, br_vector4 *, br_matrix4 *, ...) = (void(*)(br_vector4 *, br_vector4 *, br_matrix4 *, ...))0x004d467f;
CARM95_HOOK_FUNCTION(original_BrMatrix4Apply, BrMatrix4Apply)
void BrMatrix4Apply(br_vector4 *A, br_vector4 *B, br_matrix4 *C) {
    LOG_TRACE("(%p, %p, %p)", A, B, C);

    (void)A;
    (void)B;
    (void)C;

    original_BrMatrix4Apply(A, B, C);
}

static void(*original_BrMatrix4ApplyP)(br_vector4 *, br_vector3 *, br_matrix4 *, ...) = (void(*)(br_vector4 *, br_vector3 *, br_matrix4 *, ...))0x004d4720;
CARM95_HOOK_FUNCTION(original_BrMatrix4ApplyP, BrMatrix4ApplyP)
void BrMatrix4ApplyP(br_vector4 *A, br_vector3 *B, br_matrix4 *C) {
    LOG_TRACE("(%p, %p, %p)", A, B, C);

    (void)A;
    (void)B;
    (void)C;

    original_BrMatrix4ApplyP(A, B, C);
}

static void(*original_BrMatrix4ApplyV)(br_vector4 *, br_vector3 *, br_matrix4 *, ...) = (void(*)(br_vector4 *, br_vector3 *, br_matrix4 *, ...))0x004d479f;
CARM95_HOOK_FUNCTION(original_BrMatrix4ApplyV, BrMatrix4ApplyV)
void BrMatrix4ApplyV(br_vector4 *A, br_vector3 *B, br_matrix4 *C) {
    LOG_TRACE("(%p, %p, %p)", A, B, C);

    (void)A;
    (void)B;
    (void)C;

    original_BrMatrix4ApplyV(A, B, C);
}

static void(*original_BrMatrix4TApply)(br_vector4 *, br_vector4 *, br_matrix4 *, ...) = (void(*)(br_vector4 *, br_vector4 *, br_matrix4 *, ...))0x004d4820;
CARM95_HOOK_FUNCTION(original_BrMatrix4TApply, BrMatrix4TApply)
void BrMatrix4TApply(br_vector4 *A, br_vector4 *B, br_matrix4 *C) {
    LOG_TRACE("(%p, %p, %p)", A, B, C);

    (void)A;
    (void)B;
    (void)C;

    original_BrMatrix4TApply(A, B, C);
}

static void(*original_BrMatrix4TApplyP)(br_vector4 *, br_vector3 *, br_matrix4 *, ...) = (void(*)(br_vector4 *, br_vector3 *, br_matrix4 *, ...))0x004d48bb;
CARM95_HOOK_FUNCTION(original_BrMatrix4TApplyP, BrMatrix4TApplyP)
void BrMatrix4TApplyP(br_vector4 *A, br_vector3 *B, br_matrix4 *C) {
    LOG_TRACE("(%p, %p, %p)", A, B, C);

    (void)A;
    (void)B;
    (void)C;

    original_BrMatrix4TApplyP(A, B, C);
}

static void(*original_BrMatrix4TApplyV)(br_vector4 *, br_vector3 *, br_matrix4 *, ...) = (void(*)(br_vector4 *, br_vector3 *, br_matrix4 *, ...))0x004d493f;
CARM95_HOOK_FUNCTION(original_BrMatrix4TApplyV, BrMatrix4TApplyV)
void BrMatrix4TApplyV(br_vector4 *A, br_vector3 *B, br_matrix4 *C) {
    LOG_TRACE("(%p, %p, %p)", A, B, C);

    (void)A;
    (void)B;
    (void)C;

    original_BrMatrix4TApplyV(A, B, C);
}

static void(*original_BrMatrix4Copy34)(br_matrix4 *, br_matrix34 *, ...) = (void(*)(br_matrix4 *, br_matrix34 *, ...))0x004d49c0;
CARM95_HOOK_FUNCTION(original_BrMatrix4Copy34, BrMatrix4Copy34)
void BrMatrix4Copy34(br_matrix4 *A, br_matrix34 *B) {
    LOG_TRACE("(%p, %p)", A, B);

    (void)A;
    (void)B;

    original_BrMatrix4Copy34(A, B);
}

static void(*original_BrMatrix4Mul34)(br_matrix4 *, br_matrix34 *, br_matrix4 *, ...) = (void(*)(br_matrix4 *, br_matrix34 *, br_matrix4 *, ...))0x004d4a30;
CARM95_HOOK_FUNCTION(original_BrMatrix4Mul34, BrMatrix4Mul34)
void BrMatrix4Mul34(br_matrix4 *A, br_matrix34 *B, br_matrix4 *C) {
    LOG_TRACE("(%p, %p, %p)", A, B, C);

    (void)A;
    (void)B;
    (void)C;

    original_BrMatrix4Mul34(A, B, C);
}

static void(*original_BrMatrix4Pre34)(br_matrix4 *, br_matrix34 *, ...) = (void(*)(br_matrix4 *, br_matrix34 *, ...))0x004d4bf0;
CARM95_HOOK_FUNCTION(original_BrMatrix4Pre34, BrMatrix4Pre34)
void BrMatrix4Pre34(br_matrix4 *A, br_matrix34 *B) {
    br_matrix4 C;
    LOG_TRACE("(%p, %p)", A, B);

    (void)A;
    (void)B;
    (void)C;

    original_BrMatrix4Pre34(A, B);
}

static void(*original_BrMatrix4ShearZ)(br_matrix4 *, br_scalar, br_scalar, ...) = (void(*)(br_matrix4 *, br_scalar, br_scalar, ...))0x004d4c20;
CARM95_HOOK_FUNCTION(original_BrMatrix4ShearZ, BrMatrix4ShearZ)
void BrMatrix4ShearZ(br_matrix4 *mat, br_scalar sx, br_scalar sy) {
    LOG_TRACE("(%p, %f, %f)", mat, sx, sy);

    (void)mat;
    (void)sx;
    (void)sy;

    original_BrMatrix4ShearZ(mat, sx, sy);
}

