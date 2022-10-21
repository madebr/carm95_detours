#include "trig.h"

#include "harness/trace.h"

#include "carm95_hooks.h"

#include "carm95_webserver.h"

#include <assert.h>
float(* hookvar_gFloat_sine_table )[91] = (void*)0x0051e620;
br_fixed_ls(* hookvar_gFixed_sine_table )[91] = (void*)0x0051e790;
br_matrix23 * hookvar_mat23tmp1  = (void*)0x0053e4b8;
br_matrix23 * hookvar_mat23tmp2  = (void*)0x0053e4d0;
 // Suffix added to avoid duplicate symbol
br_matrix34 * hookvar_mattmp1__trig  = (void*)0x0053e4e8;
 // Suffix added to avoid duplicate symbol
br_matrix34 * hookvar_mattmp2__trig  = (void*)0x0053e518;

function_hook_state_t function_hook_state_FastFloatSin = HOOK_UNAVAILABLE;
static float(__cdecl*original_FastFloatSin)(int) = (float(__cdecl*)(int))0x004aa0d0;
CARM95_HOOK_FUNCTION(original_FastFloatSin, FastFloatSin)
float __cdecl FastFloatSin(int pAngle_in_degrees) {
    LOG_TRACE("(%d)", pAngle_in_degrees);

    (void)pAngle_in_degrees;

    if (function_hook_state_FastFloatSin == HOOK_ENABLED) {
        assert(0 && "FastFloatSin not implemented.");
        abort();
    } else {
        return original_FastFloatSin(pAngle_in_degrees);
    }
}

function_hook_state_t function_hook_state_FastFloatCos = HOOK_UNAVAILABLE;
static float(__cdecl*original_FastFloatCos)(int) = (float(__cdecl*)(int))0x004aa18c;
CARM95_HOOK_FUNCTION(original_FastFloatCos, FastFloatCos)
float __cdecl FastFloatCos(int pAngle_in_degrees) {
    LOG_TRACE("(%d)", pAngle_in_degrees);

    (void)pAngle_in_degrees;

    if (function_hook_state_FastFloatCos == HOOK_ENABLED) {
        assert(0 && "FastFloatCos not implemented.");
        abort();
    } else {
        return original_FastFloatCos(pAngle_in_degrees);
    }
}

function_hook_state_t function_hook_state_FastFloatTan = HOOK_UNAVAILABLE;
static float(__cdecl*original_FastFloatTan)(int) = (float(__cdecl*)(int))0x004aa248;
CARM95_HOOK_FUNCTION(original_FastFloatTan, FastFloatTan)
float __cdecl FastFloatTan(int pAngle_in_degrees) {
    LOG_TRACE("(%d)", pAngle_in_degrees);

    (void)pAngle_in_degrees;

    if (function_hook_state_FastFloatTan == HOOK_ENABLED) {
        assert(0 && "FastFloatTan not implemented.");
        abort();
    } else {
        return original_FastFloatTan(pAngle_in_degrees);
    }
}

function_hook_state_t function_hook_state_FastScalarSin = HOOK_UNAVAILABLE;
static br_scalar(__cdecl*original_FastScalarSin)(int) = (br_scalar(__cdecl*)(int))0x004aa279;
CARM95_HOOK_FUNCTION(original_FastScalarSin, FastScalarSin)
br_scalar __cdecl FastScalarSin(int pAngle_in_degrees) {
    LOG_TRACE("(%d)", pAngle_in_degrees);

    (void)pAngle_in_degrees;

    if (function_hook_state_FastScalarSin == HOOK_ENABLED) {
        assert(0 && "FastScalarSin not implemented.");
        abort();
    } else {
        return original_FastScalarSin(pAngle_in_degrees);
    }
}

function_hook_state_t function_hook_state_FastScalarCos = HOOK_UNAVAILABLE;
static br_scalar(__cdecl*original_FastScalarCos)(int) = (br_scalar(__cdecl*)(int))0x004aa295;
CARM95_HOOK_FUNCTION(original_FastScalarCos, FastScalarCos)
br_scalar __cdecl FastScalarCos(int pAngle_in_degrees) {
    LOG_TRACE("(%d)", pAngle_in_degrees);

    (void)pAngle_in_degrees;

    if (function_hook_state_FastScalarCos == HOOK_ENABLED) {
        assert(0 && "FastScalarCos not implemented.");
        abort();
    } else {
        return original_FastScalarCos(pAngle_in_degrees);
    }
}

function_hook_state_t function_hook_state_FastScalarTan = HOOK_UNAVAILABLE;
static br_scalar(__cdecl*original_FastScalarTan)(int) = (br_scalar(__cdecl*)(int))0x004aa2b1;
CARM95_HOOK_FUNCTION(original_FastScalarTan, FastScalarTan)
br_scalar __cdecl FastScalarTan(int pAngle_in_degrees) {
    LOG_TRACE("(%d)", pAngle_in_degrees);

    (void)pAngle_in_degrees;

    if (function_hook_state_FastScalarTan == HOOK_ENABLED) {
        assert(0 && "FastScalarTan not implemented.");
        abort();
    } else {
        return original_FastScalarTan(pAngle_in_degrees);
    }
}

function_hook_state_t function_hook_state_FastScalarSinAngle = HOOK_UNAVAILABLE;
static br_scalar(__cdecl*original_FastScalarSinAngle)(br_angle) = (br_scalar(__cdecl*)(br_angle))0x004aa2e2;
CARM95_HOOK_FUNCTION(original_FastScalarSinAngle, FastScalarSinAngle)
br_scalar __cdecl FastScalarSinAngle(br_angle pBR_angle) {
    LOG_TRACE("(%u)", pBR_angle);

    (void)pBR_angle;

    if (function_hook_state_FastScalarSinAngle == HOOK_ENABLED) {
        assert(0 && "FastScalarSinAngle not implemented.");
        abort();
    } else {
        return original_FastScalarSinAngle(pBR_angle);
    }
}

function_hook_state_t function_hook_state_FastScalarCosAngle = HOOK_UNAVAILABLE;
static br_scalar(__cdecl*original_FastScalarCosAngle)(br_angle) = (br_scalar(__cdecl*)(br_angle))0x004aa317;
CARM95_HOOK_FUNCTION(original_FastScalarCosAngle, FastScalarCosAngle)
br_scalar __cdecl FastScalarCosAngle(br_angle pBR_angle) {
    LOG_TRACE("(%u)", pBR_angle);

    (void)pBR_angle;

    if (function_hook_state_FastScalarCosAngle == HOOK_ENABLED) {
        assert(0 && "FastScalarCosAngle not implemented.");
        abort();
    } else {
        return original_FastScalarCosAngle(pBR_angle);
    }
}

function_hook_state_t function_hook_state_FastScalarTanAngle = HOOK_UNAVAILABLE;
static br_scalar(__cdecl*original_FastScalarTanAngle)(br_angle) = (br_scalar(__cdecl*)(br_angle))0x004aa34c;
CARM95_HOOK_FUNCTION(original_FastScalarTanAngle, FastScalarTanAngle)
br_scalar __cdecl FastScalarTanAngle(br_angle pBR_angle) {
    int angle_in_degrees;
    LOG_TRACE("(%u)", pBR_angle);

    (void)pBR_angle;
    (void)angle_in_degrees;

    if (function_hook_state_FastScalarTanAngle == HOOK_ENABLED) {
        assert(0 && "FastScalarTanAngle not implemented.");
        abort();
    } else {
        return original_FastScalarTanAngle(pBR_angle);
    }
}

function_hook_state_t function_hook_state_FastFloatArcSin = HOOK_UNAVAILABLE;
static float(__cdecl*original_FastFloatArcSin)(float) = (float(__cdecl*)(float))0x004aa399;
CARM95_HOOK_FUNCTION(original_FastFloatArcSin, FastFloatArcSin)
float __cdecl FastFloatArcSin(float pValue) {
    float low_limit;
    float high_limit;
    float mid_point;
    LOG_TRACE("(%f)", pValue);

    (void)pValue;
    (void)low_limit;
    (void)high_limit;
    (void)mid_point;

    if (function_hook_state_FastFloatArcSin == HOOK_ENABLED) {
        assert(0 && "FastFloatArcSin not implemented.");
        abort();
    } else {
        return original_FastFloatArcSin(pValue);
    }
}

function_hook_state_t function_hook_state_FastFloatArcCos = HOOK_UNAVAILABLE;
static float(__cdecl*original_FastFloatArcCos)(float) = (float(__cdecl*)(float))0x004aa460;
CARM95_HOOK_FUNCTION(original_FastFloatArcCos, FastFloatArcCos)
float __cdecl FastFloatArcCos(float pValue) {
    LOG_TRACE("(%f)", pValue);

    (void)pValue;

    if (function_hook_state_FastFloatArcCos == HOOK_ENABLED) {
        assert(0 && "FastFloatArcCos not implemented.");
        abort();
    } else {
        return original_FastFloatArcCos(pValue);
    }
}

function_hook_state_t function_hook_state_FastScalarArcSin = HOOK_UNAVAILABLE;
static br_scalar(__cdecl*original_FastScalarArcSin)(br_scalar) = (br_scalar(__cdecl*)(br_scalar))0x004aa482;
CARM95_HOOK_FUNCTION(original_FastScalarArcSin, FastScalarArcSin)
br_scalar __cdecl FastScalarArcSin(br_scalar pValue) {
    LOG_TRACE("(%f)", pValue);

    (void)pValue;

    if (function_hook_state_FastScalarArcSin == HOOK_ENABLED) {
        assert(0 && "FastScalarArcSin not implemented.");
        abort();
    } else {
        return original_FastScalarArcSin(pValue);
    }
}

function_hook_state_t function_hook_state_FastScalarArcCos = HOOK_UNAVAILABLE;
static br_scalar(__cdecl*original_FastScalarArcCos)(br_scalar) = (br_scalar(__cdecl*)(br_scalar))0x004aa49e;
CARM95_HOOK_FUNCTION(original_FastScalarArcCos, FastScalarArcCos)
br_scalar __cdecl FastScalarArcCos(br_scalar pValue) {
    LOG_TRACE("(%f)", pValue);

    (void)pValue;

    if (function_hook_state_FastScalarArcCos == HOOK_ENABLED) {
        assert(0 && "FastScalarArcCos not implemented.");
        abort();
    } else {
        return original_FastScalarArcCos(pValue);
    }
}

function_hook_state_t function_hook_state_FastFloatArcTan2 = HOOK_UNAVAILABLE;
static float(__cdecl*original_FastFloatArcTan2)(float, float) = (float(__cdecl*)(float, float))0x004aa4c0;
CARM95_HOOK_FUNCTION(original_FastFloatArcTan2, FastFloatArcTan2)
float __cdecl FastFloatArcTan2(float pY, float pX) {
    float abs_x;
    float abs_y;
    LOG_TRACE("(%f, %f)", pY, pX);

    (void)pY;
    (void)pX;
    (void)abs_x;
    (void)abs_y;

    if (function_hook_state_FastFloatArcTan2 == HOOK_ENABLED) {
        assert(0 && "FastFloatArcTan2 not implemented.");
        abort();
    } else {
        return original_FastFloatArcTan2(pY, pX);
    }
}

function_hook_state_t function_hook_state_FastScalarArcTan2 = HOOK_UNAVAILABLE;
static br_scalar(__cdecl*original_FastScalarArcTan2)(br_scalar, br_scalar) = (br_scalar(__cdecl*)(br_scalar, br_scalar))0x004aa69f;
CARM95_HOOK_FUNCTION(original_FastScalarArcTan2, FastScalarArcTan2)
br_scalar __cdecl FastScalarArcTan2(br_scalar pY, br_scalar pX) {
    br_scalar abs_x;
    br_scalar abs_y;
    LOG_TRACE("(%f, %f)", pY, pX);

    (void)pY;
    (void)pX;
    (void)abs_x;
    (void)abs_y;

    if (function_hook_state_FastScalarArcTan2 == HOOK_ENABLED) {
        assert(0 && "FastScalarArcTan2 not implemented.");
        abort();
    } else {
        return original_FastScalarArcTan2(pY, pX);
    }
}

function_hook_state_t function_hook_state_FastFloatArcTan2Angle = HOOK_UNAVAILABLE;
static br_angle(__cdecl*original_FastFloatArcTan2Angle)(float, float) = (br_angle(__cdecl*)(float, float))0x004aa6c2;
CARM95_HOOK_FUNCTION(original_FastFloatArcTan2Angle, FastFloatArcTan2Angle)
br_angle __cdecl FastFloatArcTan2Angle(float pY, float pX) {
    float abs_x;
    float abs_y;
    LOG_TRACE("(%f, %f)", pY, pX);

    (void)pY;
    (void)pX;
    (void)abs_x;
    (void)abs_y;

    if (function_hook_state_FastFloatArcTan2Angle == HOOK_ENABLED) {
        assert(0 && "FastFloatArcTan2Angle not implemented.");
        abort();
    } else {
        return original_FastFloatArcTan2Angle(pY, pX);
    }
}

function_hook_state_t function_hook_state_FastScalarArcTan2Angle = HOOK_UNAVAILABLE;
static br_angle(__cdecl*original_FastScalarArcTan2Angle)(br_scalar, br_scalar) = (br_angle(__cdecl*)(br_scalar, br_scalar))0x004aa8c2;
CARM95_HOOK_FUNCTION(original_FastScalarArcTan2Angle, FastScalarArcTan2Angle)
br_angle __cdecl FastScalarArcTan2Angle(br_scalar pY, br_scalar pX) {
    br_scalar abs_x;
    br_scalar abs_y;
    LOG_TRACE("(%f, %f)", pY, pX);

    (void)pY;
    (void)pX;
    (void)abs_x;
    (void)abs_y;

    if (function_hook_state_FastScalarArcTan2Angle == HOOK_ENABLED) {
        assert(0 && "FastScalarArcTan2Angle not implemented.");
        abort();
    } else {
        return original_FastScalarArcTan2Angle(pY, pX);
    }
}

function_hook_state_t function_hook_state_DRMatrix34RotateX = HOOK_UNAVAILABLE;
static void(__cdecl*original_DRMatrix34RotateX)(br_matrix34 *, br_angle) = (void(__cdecl*)(br_matrix34 *, br_angle))0x004aa8e5;
CARM95_HOOK_FUNCTION(original_DRMatrix34RotateX, DRMatrix34RotateX)
void __cdecl DRMatrix34RotateX(br_matrix34 *mat, br_angle rx) {
    br_scalar s;
    br_scalar c;
    LOG_TRACE("(%p, %u)", mat, rx);

    (void)mat;
    (void)rx;
    (void)s;
    (void)c;

    if (function_hook_state_DRMatrix34RotateX == HOOK_ENABLED) {
        assert(0 && "DRMatrix34RotateX not implemented.");
        abort();
    } else {
        original_DRMatrix34RotateX(mat, rx);
    }
}

function_hook_state_t function_hook_state_DRMatrix34RotateY = HOOK_UNAVAILABLE;
static void(__cdecl*original_DRMatrix34RotateY)(br_matrix34 *, br_angle) = (void(__cdecl*)(br_matrix34 *, br_angle))0x004aa986;
CARM95_HOOK_FUNCTION(original_DRMatrix34RotateY, DRMatrix34RotateY)
void __cdecl DRMatrix34RotateY(br_matrix34 *mat, br_angle ry) {
    br_scalar s;
    br_scalar c;
    LOG_TRACE("(%p, %u)", mat, ry);

    (void)mat;
    (void)ry;
    (void)s;
    (void)c;

    if (function_hook_state_DRMatrix34RotateY == HOOK_ENABLED) {
        assert(0 && "DRMatrix34RotateY not implemented.");
        abort();
    } else {
        original_DRMatrix34RotateY(mat, ry);
    }
}

function_hook_state_t function_hook_state_DRMatrix34RotateZ = HOOK_UNAVAILABLE;
static void(__cdecl*original_DRMatrix34RotateZ)(br_matrix34 *, br_angle) = (void(__cdecl*)(br_matrix34 *, br_angle))0x004aaa27;
CARM95_HOOK_FUNCTION(original_DRMatrix34RotateZ, DRMatrix34RotateZ)
void __cdecl DRMatrix34RotateZ(br_matrix34 *mat, br_angle rz) {
    br_scalar s;
    br_scalar c;
    LOG_TRACE("(%p, %u)", mat, rz);

    (void)mat;
    (void)rz;
    (void)s;
    (void)c;

    if (function_hook_state_DRMatrix34RotateZ == HOOK_ENABLED) {
        assert(0 && "DRMatrix34RotateZ not implemented.");
        abort();
    } else {
        original_DRMatrix34RotateZ(mat, rz);
    }
}

function_hook_state_t function_hook_state_DRMatrix34Rotate = HOOK_UNAVAILABLE;
static void(__cdecl*original_DRMatrix34Rotate)(br_matrix34 *, br_angle, br_vector3 *) = (void(__cdecl*)(br_matrix34 *, br_angle, br_vector3 *))0x004aaac8;
CARM95_HOOK_FUNCTION(original_DRMatrix34Rotate, DRMatrix34Rotate)
void __cdecl DRMatrix34Rotate(br_matrix34 *mat, br_angle r, br_vector3 *a) {
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

    if (function_hook_state_DRMatrix34Rotate == HOOK_ENABLED) {
        assert(0 && "DRMatrix34Rotate not implemented.");
        abort();
    } else {
        original_DRMatrix34Rotate(mat, r, a);
    }
}

function_hook_state_t function_hook_state_DRMatrix34PreRotateX = HOOK_UNAVAILABLE;
static void(__cdecl*original_DRMatrix34PreRotateX)(br_matrix34 *, br_angle) = (void(__cdecl*)(br_matrix34 *, br_angle))0x004aabfe;
CARM95_HOOK_FUNCTION(original_DRMatrix34PreRotateX, DRMatrix34PreRotateX)
void __cdecl DRMatrix34PreRotateX(br_matrix34 *mat, br_angle rx) {
    LOG_TRACE("(%p, %u)", mat, rx);

    (void)mat;
    (void)rx;

    if (function_hook_state_DRMatrix34PreRotateX == HOOK_ENABLED) {
        assert(0 && "DRMatrix34PreRotateX not implemented.");
        abort();
    } else {
        original_DRMatrix34PreRotateX(mat, rx);
    }
}

function_hook_state_t function_hook_state_DRMatrix34PostRotateX = HOOK_UNAVAILABLE;
static void(__cdecl*original_DRMatrix34PostRotateX)(br_matrix34 *, br_angle) = (void(__cdecl*)(br_matrix34 *, br_angle))0x004aac41;
CARM95_HOOK_FUNCTION(original_DRMatrix34PostRotateX, DRMatrix34PostRotateX)
void __cdecl DRMatrix34PostRotateX(br_matrix34 *mat, br_angle rx) {
    LOG_TRACE("(%p, %u)", mat, rx);

    (void)mat;
    (void)rx;

    if (function_hook_state_DRMatrix34PostRotateX == HOOK_ENABLED) {
        assert(0 && "DRMatrix34PostRotateX not implemented.");
        abort();
    } else {
        original_DRMatrix34PostRotateX(mat, rx);
    }
}

function_hook_state_t function_hook_state_DRMatrix34PreRotateY = HOOK_UNAVAILABLE;
static void(__cdecl*original_DRMatrix34PreRotateY)(br_matrix34 *, br_angle) = (void(__cdecl*)(br_matrix34 *, br_angle))0x004aac84;
CARM95_HOOK_FUNCTION(original_DRMatrix34PreRotateY, DRMatrix34PreRotateY)
void __cdecl DRMatrix34PreRotateY(br_matrix34 *mat, br_angle ry) {
    LOG_TRACE("(%p, %u)", mat, ry);

    (void)mat;
    (void)ry;

    if (function_hook_state_DRMatrix34PreRotateY == HOOK_ENABLED) {
        assert(0 && "DRMatrix34PreRotateY not implemented.");
        abort();
    } else {
        original_DRMatrix34PreRotateY(mat, ry);
    }
}

function_hook_state_t function_hook_state_DRMatrix34PostRotateY = HOOK_UNAVAILABLE;
static void(__cdecl*original_DRMatrix34PostRotateY)(br_matrix34 *, br_angle) = (void(__cdecl*)(br_matrix34 *, br_angle))0x004aacc7;
CARM95_HOOK_FUNCTION(original_DRMatrix34PostRotateY, DRMatrix34PostRotateY)
void __cdecl DRMatrix34PostRotateY(br_matrix34 *mat, br_angle ry) {
    LOG_TRACE("(%p, %u)", mat, ry);

    (void)mat;
    (void)ry;

    if (function_hook_state_DRMatrix34PostRotateY == HOOK_ENABLED) {
        assert(0 && "DRMatrix34PostRotateY not implemented.");
        abort();
    } else {
        original_DRMatrix34PostRotateY(mat, ry);
    }
}

function_hook_state_t function_hook_state_DRMatrix34PreRotateZ = HOOK_UNAVAILABLE;
static void(__cdecl*original_DRMatrix34PreRotateZ)(br_matrix34 *, br_angle) = (void(__cdecl*)(br_matrix34 *, br_angle))0x004aad0a;
CARM95_HOOK_FUNCTION(original_DRMatrix34PreRotateZ, DRMatrix34PreRotateZ)
void __cdecl DRMatrix34PreRotateZ(br_matrix34 *mat, br_angle rz) {
    LOG_TRACE("(%p, %u)", mat, rz);

    (void)mat;
    (void)rz;

    if (function_hook_state_DRMatrix34PreRotateZ == HOOK_ENABLED) {
        assert(0 && "DRMatrix34PreRotateZ not implemented.");
        abort();
    } else {
        original_DRMatrix34PreRotateZ(mat, rz);
    }
}

function_hook_state_t function_hook_state_DRMatrix34PostRotateZ = HOOK_UNAVAILABLE;
static void(__cdecl*original_DRMatrix34PostRotateZ)(br_matrix34 *, br_angle) = (void(__cdecl*)(br_matrix34 *, br_angle))0x004aad4d;
CARM95_HOOK_FUNCTION(original_DRMatrix34PostRotateZ, DRMatrix34PostRotateZ)
void __cdecl DRMatrix34PostRotateZ(br_matrix34 *mat, br_angle rz) {
    LOG_TRACE("(%p, %u)", mat, rz);

    (void)mat;
    (void)rz;

    if (function_hook_state_DRMatrix34PostRotateZ == HOOK_ENABLED) {
        assert(0 && "DRMatrix34PostRotateZ not implemented.");
        abort();
    } else {
        original_DRMatrix34PostRotateZ(mat, rz);
    }
}

function_hook_state_t function_hook_state_DRMatrix34PreRotate = HOOK_UNAVAILABLE;
static void(__cdecl*original_DRMatrix34PreRotate)(br_matrix34 *, br_angle, br_vector3 *) = (void(__cdecl*)(br_matrix34 *, br_angle, br_vector3 *))0x004aad90;
CARM95_HOOK_FUNCTION(original_DRMatrix34PreRotate, DRMatrix34PreRotate)
void __cdecl DRMatrix34PreRotate(br_matrix34 *mat, br_angle r, br_vector3 *axis) {
    LOG_TRACE("(%p, %u, %p)", mat, r, axis);

    (void)mat;
    (void)r;
    (void)axis;

    if (function_hook_state_DRMatrix34PreRotate == HOOK_ENABLED) {
        assert(0 && "DRMatrix34PreRotate not implemented.");
        abort();
    } else {
        original_DRMatrix34PreRotate(mat, r, axis);
    }
}

function_hook_state_t function_hook_state_DRMatrix34PostRotate = HOOK_UNAVAILABLE;
static void(__cdecl*original_DRMatrix34PostRotate)(br_matrix34 *, br_angle, br_vector3 *) = (void(__cdecl*)(br_matrix34 *, br_angle, br_vector3 *))0x004aadd7;
CARM95_HOOK_FUNCTION(original_DRMatrix34PostRotate, DRMatrix34PostRotate)
void __cdecl DRMatrix34PostRotate(br_matrix34 *mat, br_angle r, br_vector3 *axis) {
    LOG_TRACE("(%p, %u, %p)", mat, r, axis);

    (void)mat;
    (void)r;
    (void)axis;

    if (function_hook_state_DRMatrix34PostRotate == HOOK_ENABLED) {
        assert(0 && "DRMatrix34PostRotate not implemented.");
        abort();
    } else {
        original_DRMatrix34PostRotate(mat, r, axis);
    }
}

function_hook_state_t function_hook_state_DRMatrix23Rotate = HOOK_UNAVAILABLE;
static void(__cdecl*original_DRMatrix23Rotate)(br_matrix23 *, br_angle) = (void(__cdecl*)(br_matrix23 *, br_angle))0x004aae1e;
CARM95_HOOK_FUNCTION(original_DRMatrix23Rotate, DRMatrix23Rotate)
void __cdecl DRMatrix23Rotate(br_matrix23 *mat, br_angle rz) {
    br_scalar s;
    br_scalar c;
    LOG_TRACE("(%p, %u)", mat, rz);

    (void)mat;
    (void)rz;
    (void)s;
    (void)c;

    if (function_hook_state_DRMatrix23Rotate == HOOK_ENABLED) {
        assert(0 && "DRMatrix23Rotate not implemented.");
        abort();
    } else {
        original_DRMatrix23Rotate(mat, rz);
    }
}

function_hook_state_t function_hook_state_DRMatrix23PreRotate = HOOK_UNAVAILABLE;
static void(__cdecl*original_DRMatrix23PreRotate)(br_matrix23 *, br_angle) = (void(__cdecl*)(br_matrix23 *, br_angle))0x004aae83;
CARM95_HOOK_FUNCTION(original_DRMatrix23PreRotate, DRMatrix23PreRotate)
void __cdecl DRMatrix23PreRotate(br_matrix23 *mat, br_angle rz) {
    LOG_TRACE("(%p, %u)", mat, rz);

    (void)mat;
    (void)rz;

    if (function_hook_state_DRMatrix23PreRotate == HOOK_ENABLED) {
        assert(0 && "DRMatrix23PreRotate not implemented.");
        abort();
    } else {
        original_DRMatrix23PreRotate(mat, rz);
    }
}

function_hook_state_t function_hook_state_DRMatrix23PostRotate = HOOK_UNAVAILABLE;
static void(__cdecl*original_DRMatrix23PostRotate)(br_matrix23 *, br_angle) = (void(__cdecl*)(br_matrix23 *, br_angle))0x004aaec6;
CARM95_HOOK_FUNCTION(original_DRMatrix23PostRotate, DRMatrix23PostRotate)
void __cdecl DRMatrix23PostRotate(br_matrix23 *mat, br_angle rz) {
    LOG_TRACE("(%p, %u)", mat, rz);

    (void)mat;
    (void)rz;

    if (function_hook_state_DRMatrix23PostRotate == HOOK_ENABLED) {
        assert(0 && "DRMatrix23PostRotate not implemented.");
        abort();
    } else {
        original_DRMatrix23PostRotate(mat, rz);
    }
}

