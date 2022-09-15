#include "trig.h"

#include "harness/trace.h"

#include "carm95_hooks.h"

#include <stdio.h>
float(* hookvar_gFloat_sine_table )[91] = (void*)0x0051e620;
br_fixed_ls(* hookvar_gFixed_sine_table )[91] = (void*)0x0051e790;
br_matrix23 * hookvar_mat23tmp1  = (void*)0x0053e4b8;
br_matrix23 * hookvar_mat23tmp2  = (void*)0x0053e4d0;
 // Suffix added to avoid duplicate symbol
br_matrix34 * hookvar_mattmp1__trig  = (void*)0x0053e4e8;
 // Suffix added to avoid duplicate symbol
br_matrix34 * hookvar_mattmp2__trig  = (void*)0x0053e518;

static float(*original_FastFloatSin)(int, ...) = (float(*)(int, ...))0x004aa0d0;
CARM95_HOOK_FUNCTION(original_FastFloatSin, FastFloatSin)
float FastFloatSin(int pAngle_in_degrees) {
    LOG_TRACE("(%d)", pAngle_in_degrees);

    (void)pAngle_in_degrees;

    return original_FastFloatSin(pAngle_in_degrees);
}

static float(*original_FastFloatCos)(int, ...) = (float(*)(int, ...))0x004aa18c;
CARM95_HOOK_FUNCTION(original_FastFloatCos, FastFloatCos)
float FastFloatCos(int pAngle_in_degrees) {
    LOG_TRACE("(%d)", pAngle_in_degrees);

    (void)pAngle_in_degrees;

    return original_FastFloatCos(pAngle_in_degrees);
}

static float(*original_FastFloatTan)(int, ...) = (float(*)(int, ...))0x004aa248;
CARM95_HOOK_FUNCTION(original_FastFloatTan, FastFloatTan)
float FastFloatTan(int pAngle_in_degrees) {
    LOG_TRACE("(%d)", pAngle_in_degrees);

    (void)pAngle_in_degrees;

    return original_FastFloatTan(pAngle_in_degrees);
}

static br_scalar(*original_FastScalarSin)(int, ...) = (br_scalar(*)(int, ...))0x004aa279;
CARM95_HOOK_FUNCTION(original_FastScalarSin, FastScalarSin)
br_scalar FastScalarSin(int pAngle_in_degrees) {
    LOG_TRACE("(%d)", pAngle_in_degrees);

    (void)pAngle_in_degrees;

    return original_FastScalarSin(pAngle_in_degrees);
}

static br_scalar(*original_FastScalarCos)(int, ...) = (br_scalar(*)(int, ...))0x004aa295;
CARM95_HOOK_FUNCTION(original_FastScalarCos, FastScalarCos)
br_scalar FastScalarCos(int pAngle_in_degrees) {
    LOG_TRACE("(%d)", pAngle_in_degrees);

    (void)pAngle_in_degrees;

    return original_FastScalarCos(pAngle_in_degrees);
}

static br_scalar(*original_FastScalarTan)(int, ...) = (br_scalar(*)(int, ...))0x004aa2b1;
CARM95_HOOK_FUNCTION(original_FastScalarTan, FastScalarTan)
br_scalar FastScalarTan(int pAngle_in_degrees) {
    LOG_TRACE("(%d)", pAngle_in_degrees);

    (void)pAngle_in_degrees;

    return original_FastScalarTan(pAngle_in_degrees);
}

static br_scalar(*original_FastScalarSinAngle)(br_angle, ...) = (br_scalar(*)(br_angle, ...))0x004aa2e2;
CARM95_HOOK_FUNCTION(original_FastScalarSinAngle, FastScalarSinAngle)
br_scalar FastScalarSinAngle(br_angle pBR_angle) {
    LOG_TRACE("(%u)", pBR_angle);

    (void)pBR_angle;

    return original_FastScalarSinAngle(pBR_angle);
}

static br_scalar(*original_FastScalarCosAngle)(br_angle, ...) = (br_scalar(*)(br_angle, ...))0x004aa317;
CARM95_HOOK_FUNCTION(original_FastScalarCosAngle, FastScalarCosAngle)
br_scalar FastScalarCosAngle(br_angle pBR_angle) {
    LOG_TRACE("(%u)", pBR_angle);

    (void)pBR_angle;

    return original_FastScalarCosAngle(pBR_angle);
}

static br_scalar(*original_FastScalarTanAngle)(br_angle, ...) = (br_scalar(*)(br_angle, ...))0x004aa34c;
CARM95_HOOK_FUNCTION(original_FastScalarTanAngle, FastScalarTanAngle)
br_scalar FastScalarTanAngle(br_angle pBR_angle) {
    int angle_in_degrees;
    LOG_TRACE("(%u)", pBR_angle);

    (void)pBR_angle;
    (void)angle_in_degrees;

    return original_FastScalarTanAngle(pBR_angle);
}

static float(*original_FastFloatArcSin)(float, ...) = (float(*)(float, ...))0x004aa399;
CARM95_HOOK_FUNCTION(original_FastFloatArcSin, FastFloatArcSin)
float FastFloatArcSin(float pValue) {
    float low_limit;
    float high_limit;
    float mid_point;
    LOG_TRACE("(%f)", pValue);

    (void)pValue;
    (void)low_limit;
    (void)high_limit;
    (void)mid_point;

    return original_FastFloatArcSin(pValue);
}

static float(*original_FastFloatArcCos)(float, ...) = (float(*)(float, ...))0x004aa460;
CARM95_HOOK_FUNCTION(original_FastFloatArcCos, FastFloatArcCos)
float FastFloatArcCos(float pValue) {
    LOG_TRACE("(%f)", pValue);

    (void)pValue;

    return original_FastFloatArcCos(pValue);
}

static br_scalar(*original_FastScalarArcSin)(br_scalar, ...) = (br_scalar(*)(br_scalar, ...))0x004aa482;
CARM95_HOOK_FUNCTION(original_FastScalarArcSin, FastScalarArcSin)
br_scalar FastScalarArcSin(br_scalar pValue) {
    LOG_TRACE("(%f)", pValue);

    (void)pValue;

    return original_FastScalarArcSin(pValue);
}

static br_scalar(*original_FastScalarArcCos)(br_scalar, ...) = (br_scalar(*)(br_scalar, ...))0x004aa49e;
CARM95_HOOK_FUNCTION(original_FastScalarArcCos, FastScalarArcCos)
br_scalar FastScalarArcCos(br_scalar pValue) {
    LOG_TRACE("(%f)", pValue);

    (void)pValue;

    return original_FastScalarArcCos(pValue);
}

static float(*original_FastFloatArcTan2)(float, float, ...) = (float(*)(float, float, ...))0x004aa4c0;
CARM95_HOOK_FUNCTION(original_FastFloatArcTan2, FastFloatArcTan2)
float FastFloatArcTan2(float pY, float pX) {
    float abs_x;
    float abs_y;
    LOG_TRACE("(%f, %f)", pY, pX);

    (void)pY;
    (void)pX;
    (void)abs_x;
    (void)abs_y;

    return original_FastFloatArcTan2(pY, pX);
}

static br_scalar(*original_FastScalarArcTan2)(br_scalar, br_scalar, ...) = (br_scalar(*)(br_scalar, br_scalar, ...))0x004aa69f;
CARM95_HOOK_FUNCTION(original_FastScalarArcTan2, FastScalarArcTan2)
br_scalar FastScalarArcTan2(br_scalar pY, br_scalar pX) {
    br_scalar abs_x;
    br_scalar abs_y;
    LOG_TRACE("(%f, %f)", pY, pX);

    (void)pY;
    (void)pX;
    (void)abs_x;
    (void)abs_y;

    return original_FastScalarArcTan2(pY, pX);
}

static br_angle(*original_FastFloatArcTan2Angle)(float, float, ...) = (br_angle(*)(float, float, ...))0x004aa6c2;
CARM95_HOOK_FUNCTION(original_FastFloatArcTan2Angle, FastFloatArcTan2Angle)
br_angle FastFloatArcTan2Angle(float pY, float pX) {
    float abs_x;
    float abs_y;
    LOG_TRACE("(%f, %f)", pY, pX);

    (void)pY;
    (void)pX;
    (void)abs_x;
    (void)abs_y;

    return original_FastFloatArcTan2Angle(pY, pX);
}

static br_angle(*original_FastScalarArcTan2Angle)(br_scalar, br_scalar, ...) = (br_angle(*)(br_scalar, br_scalar, ...))0x004aa8c2;
CARM95_HOOK_FUNCTION(original_FastScalarArcTan2Angle, FastScalarArcTan2Angle)
br_angle FastScalarArcTan2Angle(br_scalar pY, br_scalar pX) {
    br_scalar abs_x;
    br_scalar abs_y;
    LOG_TRACE("(%f, %f)", pY, pX);

    (void)pY;
    (void)pX;
    (void)abs_x;
    (void)abs_y;

    return original_FastScalarArcTan2Angle(pY, pX);
}

static void(*original_DRMatrix34RotateX)(br_matrix34 *, br_angle, ...) = (void(*)(br_matrix34 *, br_angle, ...))0x004aa8e5;
CARM95_HOOK_FUNCTION(original_DRMatrix34RotateX, DRMatrix34RotateX)
void DRMatrix34RotateX(br_matrix34 *mat, br_angle rx) {
    br_scalar s;
    br_scalar c;
    LOG_TRACE("(%p, %u)", mat, rx);

    (void)mat;
    (void)rx;
    (void)s;
    (void)c;

    original_DRMatrix34RotateX(mat, rx);
}

static void(*original_DRMatrix34RotateY)(br_matrix34 *, br_angle, ...) = (void(*)(br_matrix34 *, br_angle, ...))0x004aa986;
CARM95_HOOK_FUNCTION(original_DRMatrix34RotateY, DRMatrix34RotateY)
void DRMatrix34RotateY(br_matrix34 *mat, br_angle ry) {
    br_scalar s;
    br_scalar c;
    LOG_TRACE("(%p, %u)", mat, ry);

    (void)mat;
    (void)ry;
    (void)s;
    (void)c;

    original_DRMatrix34RotateY(mat, ry);
}

static void(*original_DRMatrix34RotateZ)(br_matrix34 *, br_angle, ...) = (void(*)(br_matrix34 *, br_angle, ...))0x004aaa27;
CARM95_HOOK_FUNCTION(original_DRMatrix34RotateZ, DRMatrix34RotateZ)
void DRMatrix34RotateZ(br_matrix34 *mat, br_angle rz) {
    br_scalar s;
    br_scalar c;
    LOG_TRACE("(%p, %u)", mat, rz);

    (void)mat;
    (void)rz;
    (void)s;
    (void)c;

    original_DRMatrix34RotateZ(mat, rz);
}

static void(*original_DRMatrix34Rotate)(br_matrix34 *, br_angle, br_vector3 *, ...) = (void(*)(br_matrix34 *, br_angle, br_vector3 *, ...))0x004aaac8;
CARM95_HOOK_FUNCTION(original_DRMatrix34Rotate, DRMatrix34Rotate)
void DRMatrix34Rotate(br_matrix34 *mat, br_angle r, br_vector3 *a) {
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

    original_DRMatrix34Rotate(mat, r, a);
}

static void(*original_DRMatrix34PreRotateX)(br_matrix34 *, br_angle, ...) = (void(*)(br_matrix34 *, br_angle, ...))0x004aabfe;
CARM95_HOOK_FUNCTION(original_DRMatrix34PreRotateX, DRMatrix34PreRotateX)
void DRMatrix34PreRotateX(br_matrix34 *mat, br_angle rx) {
    LOG_TRACE("(%p, %u)", mat, rx);

    (void)mat;
    (void)rx;

    original_DRMatrix34PreRotateX(mat, rx);
}

static void(*original_DRMatrix34PostRotateX)(br_matrix34 *, br_angle, ...) = (void(*)(br_matrix34 *, br_angle, ...))0x004aac41;
CARM95_HOOK_FUNCTION(original_DRMatrix34PostRotateX, DRMatrix34PostRotateX)
void DRMatrix34PostRotateX(br_matrix34 *mat, br_angle rx) {
    LOG_TRACE("(%p, %u)", mat, rx);

    (void)mat;
    (void)rx;

    original_DRMatrix34PostRotateX(mat, rx);
}

static void(*original_DRMatrix34PreRotateY)(br_matrix34 *, br_angle, ...) = (void(*)(br_matrix34 *, br_angle, ...))0x004aac84;
CARM95_HOOK_FUNCTION(original_DRMatrix34PreRotateY, DRMatrix34PreRotateY)
void DRMatrix34PreRotateY(br_matrix34 *mat, br_angle ry) {
    LOG_TRACE("(%p, %u)", mat, ry);

    (void)mat;
    (void)ry;

    original_DRMatrix34PreRotateY(mat, ry);
}

static void(*original_DRMatrix34PostRotateY)(br_matrix34 *, br_angle, ...) = (void(*)(br_matrix34 *, br_angle, ...))0x004aacc7;
CARM95_HOOK_FUNCTION(original_DRMatrix34PostRotateY, DRMatrix34PostRotateY)
void DRMatrix34PostRotateY(br_matrix34 *mat, br_angle ry) {
    LOG_TRACE("(%p, %u)", mat, ry);

    (void)mat;
    (void)ry;

    original_DRMatrix34PostRotateY(mat, ry);
}

static void(*original_DRMatrix34PreRotateZ)(br_matrix34 *, br_angle, ...) = (void(*)(br_matrix34 *, br_angle, ...))0x004aad0a;
CARM95_HOOK_FUNCTION(original_DRMatrix34PreRotateZ, DRMatrix34PreRotateZ)
void DRMatrix34PreRotateZ(br_matrix34 *mat, br_angle rz) {
    LOG_TRACE("(%p, %u)", mat, rz);

    (void)mat;
    (void)rz;

    original_DRMatrix34PreRotateZ(mat, rz);
}

static void(*original_DRMatrix34PostRotateZ)(br_matrix34 *, br_angle, ...) = (void(*)(br_matrix34 *, br_angle, ...))0x004aad4d;
CARM95_HOOK_FUNCTION(original_DRMatrix34PostRotateZ, DRMatrix34PostRotateZ)
void DRMatrix34PostRotateZ(br_matrix34 *mat, br_angle rz) {
    LOG_TRACE("(%p, %u)", mat, rz);

    (void)mat;
    (void)rz;

    original_DRMatrix34PostRotateZ(mat, rz);
}

static void(*original_DRMatrix34PreRotate)(br_matrix34 *, br_angle, br_vector3 *, ...) = (void(*)(br_matrix34 *, br_angle, br_vector3 *, ...))0x004aad90;
CARM95_HOOK_FUNCTION(original_DRMatrix34PreRotate, DRMatrix34PreRotate)
void DRMatrix34PreRotate(br_matrix34 *mat, br_angle r, br_vector3 *axis) {
    LOG_TRACE("(%p, %u, %p)", mat, r, axis);

    (void)mat;
    (void)r;
    (void)axis;

    original_DRMatrix34PreRotate(mat, r, axis);
}

static void(*original_DRMatrix34PostRotate)(br_matrix34 *, br_angle, br_vector3 *, ...) = (void(*)(br_matrix34 *, br_angle, br_vector3 *, ...))0x004aadd7;
CARM95_HOOK_FUNCTION(original_DRMatrix34PostRotate, DRMatrix34PostRotate)
void DRMatrix34PostRotate(br_matrix34 *mat, br_angle r, br_vector3 *axis) {
    LOG_TRACE("(%p, %u, %p)", mat, r, axis);

    (void)mat;
    (void)r;
    (void)axis;

    original_DRMatrix34PostRotate(mat, r, axis);
}

static void(*original_DRMatrix23Rotate)(br_matrix23 *, br_angle, ...) = (void(*)(br_matrix23 *, br_angle, ...))0x004aae1e;
CARM95_HOOK_FUNCTION(original_DRMatrix23Rotate, DRMatrix23Rotate)
void DRMatrix23Rotate(br_matrix23 *mat, br_angle rz) {
    br_scalar s;
    br_scalar c;
    LOG_TRACE("(%p, %u)", mat, rz);

    (void)mat;
    (void)rz;
    (void)s;
    (void)c;

    original_DRMatrix23Rotate(mat, rz);
}

static void(*original_DRMatrix23PreRotate)(br_matrix23 *, br_angle, ...) = (void(*)(br_matrix23 *, br_angle, ...))0x004aae83;
CARM95_HOOK_FUNCTION(original_DRMatrix23PreRotate, DRMatrix23PreRotate)
void DRMatrix23PreRotate(br_matrix23 *mat, br_angle rz) {
    LOG_TRACE("(%p, %u)", mat, rz);

    (void)mat;
    (void)rz;

    original_DRMatrix23PreRotate(mat, rz);
}

static void(*original_DRMatrix23PostRotate)(br_matrix23 *, br_angle, ...) = (void(*)(br_matrix23 *, br_angle, ...))0x004aaec6;
CARM95_HOOK_FUNCTION(original_DRMatrix23PostRotate, DRMatrix23PostRotate)
void DRMatrix23PostRotate(br_matrix23 *mat, br_angle rz) {
    LOG_TRACE("(%p, %u)", mat, rz);

    (void)mat;
    (void)rz;

    original_DRMatrix23PostRotate(mat, rz);
}

