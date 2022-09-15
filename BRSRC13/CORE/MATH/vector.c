#include "vector.h"

#include "harness/trace.h"

#include "carm95_hooks.h"

#include <stdio.h>

static void(*original_BrVector2Copy)(br_vector2 *, br_vector2 *, ...) = (void(*)(br_vector2 *, br_vector2 *, ...))0x004d2abd;
CARM95_HOOK_FUNCTION(original_BrVector2Copy, BrVector2Copy)
void BrVector2Copy(br_vector2 *v1, br_vector2 *v2) {
    LOG_TRACE("(%p, %p)", v1, v2);

    (void)v1;
    (void)v2;

    original_BrVector2Copy(v1, v2);
}

static void(*original_BrVector2Set)(br_vector2 *, br_scalar, br_scalar, ...) = (void(*)(br_vector2 *, br_scalar, br_scalar, ...))0x004d2ad3;
CARM95_HOOK_FUNCTION(original_BrVector2Set, BrVector2Set)
void BrVector2Set(br_vector2 *v1, br_scalar s1, br_scalar s2) {
    LOG_TRACE("(%p, %f, %f)", v1, s1, s2);

    (void)v1;
    (void)s1;
    (void)s2;

    original_BrVector2Set(v1, s1, s2);
}

static void(*original_BrVector2SetInt)(br_vector2 *, int, int, ...) = (void(*)(br_vector2 *, int, int, ...))0x004d2af2;
CARM95_HOOK_FUNCTION(original_BrVector2SetInt, BrVector2SetInt)
void BrVector2SetInt(br_vector2 *v1, int i1, int i2) {
    LOG_TRACE("(%p, %d, %d)", v1, i1, i2);

    (void)v1;
    (void)i1;
    (void)i2;

    original_BrVector2SetInt(v1, i1, i2);
}

static void(*original_BrVector2SetFloat)(br_vector2 *, float, float, ...) = (void(*)(br_vector2 *, float, float, ...))0x004d2b1a;
CARM95_HOOK_FUNCTION(original_BrVector2SetFloat, BrVector2SetFloat)
void BrVector2SetFloat(br_vector2 *v1, float f1, float f2) {
    LOG_TRACE("(%p, %f, %f)", v1, f1, f2);

    (void)v1;
    (void)f1;
    (void)f2;

    original_BrVector2SetFloat(v1, f1, f2);
}

static void(*original_BrVector2Negate)(br_vector2 *, br_vector2 *, ...) = (void(*)(br_vector2 *, br_vector2 *, ...))0x004d2b32;
CARM95_HOOK_FUNCTION(original_BrVector2Negate, BrVector2Negate)
void BrVector2Negate(br_vector2 *v1, br_vector2 *v2) {
    LOG_TRACE("(%p, %p)", v1, v2);

    (void)v1;
    (void)v2;

    original_BrVector2Negate(v1, v2);
}

static void(*original_BrVector2Add)(br_vector2 *, br_vector2 *, br_vector2 *, ...) = (void(*)(br_vector2 *, br_vector2 *, br_vector2 *, ...))0x004d2b57;
CARM95_HOOK_FUNCTION(original_BrVector2Add, BrVector2Add)
void BrVector2Add(br_vector2 *v1, br_vector2 *v2, br_vector2 *v3) {
    LOG_TRACE("(%p, %p, %p)", v1, v2, v3);

    (void)v1;
    (void)v2;
    (void)v3;

    original_BrVector2Add(v1, v2, v3);
}

static void(*original_BrVector2Accumulate)(br_vector2 *, br_vector2 *, ...) = (void(*)(br_vector2 *, br_vector2 *, ...))0x004d2b7c;
CARM95_HOOK_FUNCTION(original_BrVector2Accumulate, BrVector2Accumulate)
void BrVector2Accumulate(br_vector2 *v1, br_vector2 *v2) {
    LOG_TRACE("(%p, %p)", v1, v2);

    (void)v1;
    (void)v2;

    original_BrVector2Accumulate(v1, v2);
}

static void(*original_BrVector2Sub)(br_vector2 *, br_vector2 *, br_vector2 *, ...) = (void(*)(br_vector2 *, br_vector2 *, br_vector2 *, ...))0x004d2b98;
CARM95_HOOK_FUNCTION(original_BrVector2Sub, BrVector2Sub)
void BrVector2Sub(br_vector2 *v1, br_vector2 *v2, br_vector2 *v3) {
    LOG_TRACE("(%p, %p, %p)", v1, v2, v3);

    (void)v1;
    (void)v2;
    (void)v3;

    original_BrVector2Sub(v1, v2, v3);
}

static void(*original_BrVector2Scale)(br_vector2 *, br_vector2 *, br_scalar, ...) = (void(*)(br_vector2 *, br_vector2 *, br_scalar, ...))0x004d2bbc;
CARM95_HOOK_FUNCTION(original_BrVector2Scale, BrVector2Scale)
void BrVector2Scale(br_vector2 *v1, br_vector2 *v2, br_scalar s) {
    LOG_TRACE("(%p, %p, %f)", v1, v2, s);

    (void)v1;
    (void)v2;
    (void)s;

    original_BrVector2Scale(v1, v2, s);
}

static void(*original_BrVector2InvScale)(br_vector2 *, br_vector2 *, br_scalar, ...) = (void(*)(br_vector2 *, br_vector2 *, br_scalar, ...))0x004d2bdb;
CARM95_HOOK_FUNCTION(original_BrVector2InvScale, BrVector2InvScale)
void BrVector2InvScale(br_vector2 *v1, br_vector2 *v2, br_scalar s) {
    LOG_TRACE("(%p, %p, %f)", v1, v2, s);

    (void)v1;
    (void)v2;
    (void)s;

    original_BrVector2InvScale(v1, v2, s);
}

static br_scalar(*original_BrVector2Dot)(br_vector2 *, br_vector2 *, ...) = (br_scalar(*)(br_vector2 *, br_vector2 *, ...))0x004d2bfb;
CARM95_HOOK_FUNCTION(original_BrVector2Dot, BrVector2Dot)
br_scalar BrVector2Dot(br_vector2 *v1, br_vector2 *v2) {
    LOG_TRACE("(%p, %p)", v1, v2);

    (void)v1;
    (void)v2;

    return original_BrVector2Dot(v1, v2);
}

static br_scalar(*original_BrVector2Length)(br_vector2 *, ...) = (br_scalar(*)(br_vector2 *, ...))0x004d2c15;
CARM95_HOOK_FUNCTION(original_BrVector2Length, BrVector2Length)
br_scalar BrVector2Length(br_vector2 *v1) {
    LOG_TRACE("(%p)", v1);

    (void)v1;

    return original_BrVector2Length(v1);
}

static br_scalar(*original_BrVector2LengthSquared)(br_vector2 *, ...) = (br_scalar(*)(br_vector2 *, ...))0x004d2c33;
CARM95_HOOK_FUNCTION(original_BrVector2LengthSquared, BrVector2LengthSquared)
br_scalar BrVector2LengthSquared(br_vector2 *v1) {
    LOG_TRACE("(%p)", v1);

    (void)v1;

    return original_BrVector2LengthSquared(v1);
}

static void(*original_BrVector3Copy)(br_vector3 *, br_vector3 *, ...) = (void(*)(br_vector3 *, br_vector3 *, ...))0x004d2c51;
CARM95_HOOK_FUNCTION(original_BrVector3Copy, BrVector3Copy)
void BrVector3Copy(br_vector3 *v1, br_vector3 *v2) {
    LOG_TRACE("(%p, %p)", v1, v2);

    (void)v1;
    (void)v2;

    original_BrVector3Copy(v1, v2);
}

static void(*original_BrVector3Set)(br_vector3 *, br_scalar, br_scalar, br_scalar, ...) = (void(*)(br_vector3 *, br_scalar, br_scalar, br_scalar, ...))0x004d2c7b;
CARM95_HOOK_FUNCTION(original_BrVector3Set, BrVector3Set)
void BrVector3Set(br_vector3 *v1, br_scalar s1, br_scalar s2, br_scalar s3) {
    LOG_TRACE("(%p, %f, %f, %f)", v1, s1, s2, s3);

    (void)v1;
    (void)s1;
    (void)s2;
    (void)s3;

    original_BrVector3Set(v1, s1, s2, s3);
}

static void(*original_BrVector3SetInt)(br_vector3 *, int, int, int, ...) = (void(*)(br_vector3 *, int, int, int, ...))0x004d2c9b;
CARM95_HOOK_FUNCTION(original_BrVector3SetInt, BrVector3SetInt)
void BrVector3SetInt(br_vector3 *v1, int i1, int i2, int i3) {
    LOG_TRACE("(%p, %d, %d, %d)", v1, i1, i2, i3);

    (void)v1;
    (void)i1;
    (void)i2;
    (void)i3;

    original_BrVector3SetInt(v1, i1, i2, i3);
}

static void(*original_BrVector3SetFloat)(br_vector3 *, float, float, float, ...) = (void(*)(br_vector3 *, float, float, float, ...))0x004d2cd0;
CARM95_HOOK_FUNCTION(original_BrVector3SetFloat, BrVector3SetFloat)
void BrVector3SetFloat(br_vector3 *v1, float f1, float f2, float f3) {
    LOG_TRACE("(%p, %f, %f, %f)", v1, f1, f2, f3);

    (void)v1;
    (void)f1;
    (void)f2;
    (void)f3;

    original_BrVector3SetFloat(v1, f1, f2, f3);
}

static void(*original_BrVector3Negate)(br_vector3 *, br_vector3 *, ...) = (void(*)(br_vector3 *, br_vector3 *, ...))0x004d2ceb;
CARM95_HOOK_FUNCTION(original_BrVector3Negate, BrVector3Negate)
void BrVector3Negate(br_vector3 *v1, br_vector3 *v2) {
    LOG_TRACE("(%p, %p)", v1, v2);

    (void)v1;
    (void)v2;

    original_BrVector3Negate(v1, v2);
}

static void(*original_BrVector3Add)(br_vector3 *, br_vector3 *, br_vector3 *, ...) = (void(*)(br_vector3 *, br_vector3 *, br_vector3 *, ...))0x004d2d0f;
CARM95_HOOK_FUNCTION(original_BrVector3Add, BrVector3Add)
void BrVector3Add(br_vector3 *v1, br_vector3 *v2, br_vector3 *v3) {
    LOG_TRACE("(%p, %p, %p)", v1, v2, v3);

    (void)v1;
    (void)v2;
    (void)v3;

    original_BrVector3Add(v1, v2, v3);
}

static void(*original_BrVector3Accumulate)(br_vector3 *, br_vector3 *, ...) = (void(*)(br_vector3 *, br_vector3 *, ...))0x004d2d35;
CARM95_HOOK_FUNCTION(original_BrVector3Accumulate, BrVector3Accumulate)
void BrVector3Accumulate(br_vector3 *v1, br_vector3 *v2) {
    LOG_TRACE("(%p, %p)", v1, v2);

    (void)v1;
    (void)v2;

    original_BrVector3Accumulate(v1, v2);
}

static void(*original_BrVector3Sub)(br_vector3 *, br_vector3 *, br_vector3 *, ...) = (void(*)(br_vector3 *, br_vector3 *, br_vector3 *, ...))0x004d2d61;
CARM95_HOOK_FUNCTION(original_BrVector3Sub, BrVector3Sub)
void BrVector3Sub(br_vector3 *v1, br_vector3 *v2, br_vector3 *v3) {
    LOG_TRACE("(%p, %p, %p)", v1, v2, v3);

    (void)v1;
    (void)v2;
    (void)v3;

    original_BrVector3Sub(v1, v2, v3);
}

static void(*original_BrVector3Scale)(br_vector3 *, br_vector3 *, br_scalar, ...) = (void(*)(br_vector3 *, br_vector3 *, br_scalar, ...))0x004d2d95;
CARM95_HOOK_FUNCTION(original_BrVector3Scale, BrVector3Scale)
void BrVector3Scale(br_vector3 *v1, br_vector3 *v2, br_scalar s) {
    LOG_TRACE("(%p, %p, %f)", v1, v2, s);

    (void)v1;
    (void)v2;
    (void)s;

    original_BrVector3Scale(v1, v2, s);
}

static void(*original_BrVector3InvScale)(br_vector3 *, br_vector3 *, br_scalar, ...) = (void(*)(br_vector3 *, br_vector3 *, br_scalar, ...))0x004d2dc5;
CARM95_HOOK_FUNCTION(original_BrVector3InvScale, BrVector3InvScale)
void BrVector3InvScale(br_vector3 *v1, br_vector3 *v2, br_scalar s) {
    LOG_TRACE("(%p, %p, %f)", v1, v2, s);

    (void)v1;
    (void)v2;
    (void)s;

    original_BrVector3InvScale(v1, v2, s);
}

static br_scalar(*original_BrVector3Dot)(br_vector3 *, br_vector3 *, ...) = (br_scalar(*)(br_vector3 *, br_vector3 *, ...))0x004d2df5;
CARM95_HOOK_FUNCTION(original_BrVector3Dot, BrVector3Dot)
br_scalar BrVector3Dot(br_vector3 *v1, br_vector3 *v2) {
    LOG_TRACE("(%p, %p)", v1, v2);

    (void)v1;
    (void)v2;

    return original_BrVector3Dot(v1, v2);
}

static void(*original_BrVector3Cross)(br_vector3 *, br_vector3 *, br_vector3 *, ...) = (void(*)(br_vector3 *, br_vector3 *, br_vector3 *, ...))0x004d2e1f;
CARM95_HOOK_FUNCTION(original_BrVector3Cross, BrVector3Cross)
void BrVector3Cross(br_vector3 *v1, br_vector3 *v2, br_vector3 *v3) {
    LOG_TRACE("(%p, %p, %p)", v1, v2, v3);

    (void)v1;
    (void)v2;
    (void)v3;

    original_BrVector3Cross(v1, v2, v3);
}

static br_scalar(*original_BrVector3Length)(br_vector3 *, ...) = (br_scalar(*)(br_vector3 *, ...))0x004d2e5b;
CARM95_HOOK_FUNCTION(original_BrVector3Length, BrVector3Length)
br_scalar BrVector3Length(br_vector3 *v1) {
    LOG_TRACE("(%p)", v1);

    (void)v1;

    return original_BrVector3Length(v1);
}

static br_scalar(*original_BrVector3LengthSquared)(br_vector3 *, ...) = (br_scalar(*)(br_vector3 *, ...))0x004d2e7d;
CARM95_HOOK_FUNCTION(original_BrVector3LengthSquared, BrVector3LengthSquared)
br_scalar BrVector3LengthSquared(br_vector3 *v1) {
    LOG_TRACE("(%p)", v1);

    (void)v1;

    return original_BrVector3LengthSquared(v1);
}

static void(*original_BrVector3Normalise)(br_vector3 *, br_vector3 *, ...) = (void(*)(br_vector3 *, br_vector3 *, ...))0x004d2e9b;
CARM95_HOOK_FUNCTION(original_BrVector3Normalise, BrVector3Normalise)
void BrVector3Normalise(br_vector3 *v1, br_vector3 *v2) {
    br_scalar scale;
    LOG_TRACE("(%p, %p)", v1, v2);

    (void)v1;
    (void)v2;
    (void)scale;

    original_BrVector3Normalise(v1, v2);
}

static void(*original_BrVector3NormaliseLP)(br_vector3 *, br_vector3 *, ...) = (void(*)(br_vector3 *, br_vector3 *, ...))0x004d2f0c;
CARM95_HOOK_FUNCTION(original_BrVector3NormaliseLP, BrVector3NormaliseLP)
void BrVector3NormaliseLP(br_vector3 *v1, br_vector3 *v2) {
    br_scalar scale;
    LOG_TRACE("(%p, %p)", v1, v2);

    (void)v1;
    (void)v2;
    (void)scale;

    original_BrVector3NormaliseLP(v1, v2);
}

static br_scalar(*original_BrVector4Dot)(br_vector4 *, br_vector4 *, ...) = (br_scalar(*)(br_vector4 *, br_vector4 *, ...))0x004d2f6a;
CARM95_HOOK_FUNCTION(original_BrVector4Dot, BrVector4Dot)
br_scalar BrVector4Dot(br_vector4 *v1, br_vector4 *v2) {
    LOG_TRACE("(%p, %p)", v1, v2);

    (void)v1;
    (void)v2;

    return original_BrVector4Dot(v1, v2);
}

static void(*original_BrVector4Copy)(br_vector4 *, br_vector4 *, ...) = (void(*)(br_vector4 *, br_vector4 *, ...))0x004d2f99;
CARM95_HOOK_FUNCTION(original_BrVector4Copy, BrVector4Copy)
void BrVector4Copy(br_vector4 *v1, br_vector4 *v2) {
    LOG_TRACE("(%p, %p)", v1, v2);

    (void)v1;
    (void)v2;

    original_BrVector4Copy(v1, v2);
}

static br_scalar(*original_BrFVector2Dot)(br_fvector2 *, br_vector2 *, ...) = (br_scalar(*)(br_fvector2 *, br_vector2 *, ...))0x004d2fc3;
CARM95_HOOK_FUNCTION(original_BrFVector2Dot, BrFVector2Dot)
br_scalar BrFVector2Dot(br_fvector2 *v1, br_vector2 *v2) {
    LOG_TRACE("(%p, %p)", v1, v2);

    (void)v1;
    (void)v2;

    return original_BrFVector2Dot(v1, v2);
}

static void(*original_BrFVector3Copy)(br_fvector3 *, br_vector3 *, ...) = (void(*)(br_fvector3 *, br_vector3 *, ...))0x004d2fe7;
CARM95_HOOK_FUNCTION(original_BrFVector3Copy, BrFVector3Copy)
void BrFVector3Copy(br_fvector3 *v1, br_vector3 *v2) {
    LOG_TRACE("(%p, %p)", v1, v2);

    (void)v1;
    (void)v2;

    original_BrFVector3Copy(v1, v2);
}

static void(*original_BrVector3ScaleF)(br_vector3 *, br_fvector3 *, br_scalar, ...) = (void(*)(br_vector3 *, br_fvector3 *, br_scalar, ...))0x004d300d;
CARM95_HOOK_FUNCTION(original_BrVector3ScaleF, BrVector3ScaleF)
void BrVector3ScaleF(br_vector3 *v1, br_fvector3 *v2, br_scalar s) {
    LOG_TRACE("(%p, %p, %f)", v1, v2, s);

    (void)v1;
    (void)v2;
    (void)s;

    original_BrVector3ScaleF(v1, v2, s);
}

static br_scalar(*original_BrFVector3Dot)(br_fvector3 *, br_vector3 *, ...) = (br_scalar(*)(br_fvector3 *, br_vector3 *, ...))0x004d3037;
CARM95_HOOK_FUNCTION(original_BrFVector3Dot, BrFVector3Dot)
br_scalar BrFVector3Dot(br_fvector3 *v1, br_vector3 *v2) {
    LOG_TRACE("(%p, %p)", v1, v2);

    (void)v1;
    (void)v2;

    return original_BrFVector3Dot(v1, v2);
}

static void(*original_BrFVector3Normalise)(br_fvector3 *, br_vector3 *, ...) = (void(*)(br_fvector3 *, br_vector3 *, ...))0x004d3061;
CARM95_HOOK_FUNCTION(original_BrFVector3Normalise, BrFVector3Normalise)
void BrFVector3Normalise(br_fvector3 *v1, br_vector3 *v2) {
    br_scalar scale;
    LOG_TRACE("(%p, %p)", v1, v2);

    (void)v1;
    (void)v2;
    (void)scale;

    original_BrFVector3Normalise(v1, v2);
}

static void(*original_BrFVector3NormaliseLP)(br_fvector3 *, br_vector3 *, ...) = (void(*)(br_fvector3 *, br_vector3 *, ...))0x004d30e0;
CARM95_HOOK_FUNCTION(original_BrFVector3NormaliseLP, BrFVector3NormaliseLP)
void BrFVector3NormaliseLP(br_fvector3 *v1, br_vector3 *v2) {
    br_scalar scale;
    LOG_TRACE("(%p, %p)", v1, v2);

    (void)v1;
    (void)v2;
    (void)scale;

    original_BrFVector3NormaliseLP(v1, v2);
}

static void(*original_BrVector2Normalise)(br_vector2 *, br_vector2 *, ...) = (void(*)(br_vector2 *, br_vector2 *, ...))0x004d3121;
CARM95_HOOK_FUNCTION(original_BrVector2Normalise, BrVector2Normalise)
void BrVector2Normalise(br_vector2 *v1, br_vector2 *v2) {
    br_scalar scale;
    LOG_TRACE("(%p, %p)", v1, v2);

    (void)v1;
    (void)v2;
    (void)scale;

    original_BrVector2Normalise(v1, v2);
}

