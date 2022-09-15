#include "math.h"

#include "harness/trace.h"

#include "carm95_hooks.h"

#include <stdio.h>

static float(*original_BrFloatFloor)(float, ...) = (float(*)(float, ...))0x00502b20;
CARM95_HOOK_FUNCTION(original_BrFloatFloor, BrFloatFloor)
float BrFloatFloor(float f) {
    LOG_TRACE("(%f)", f);

    (void)f;

    return original_BrFloatFloor(f);
}

static float(*original_BrFloatCeil)(float, ...) = (float(*)(float, ...))0x00502b40;
CARM95_HOOK_FUNCTION(original_BrFloatCeil, BrFloatCeil)
float BrFloatCeil(float f) {
    LOG_TRACE("(%f)", f);

    (void)f;

    return original_BrFloatCeil(f);
}

static float(*original_BrFloatSqrt)(float, ...) = (float(*)(float, ...))0x00502b60;
CARM95_HOOK_FUNCTION(original_BrFloatSqrt, BrFloatSqrt)
float BrFloatSqrt(float f) {
    LOG_TRACE("(%f)", f);

    (void)f;

    return original_BrFloatSqrt(f);
}

static float(*original_BrFloatPow)(float, float, ...) = (float(*)(float, float, ...))0x00502b70;
CARM95_HOOK_FUNCTION(original_BrFloatPow, BrFloatPow)
float BrFloatPow(float a, float b) {
    LOG_TRACE("(%f, %f)", a, b);

    (void)a;
    (void)b;

    return original_BrFloatPow(a, b);
}

static float(*original_BrFloatAtan2)(float, float, ...) = (float(*)(float, float, ...))0x00502b80;
CARM95_HOOK_FUNCTION(original_BrFloatAtan2, BrFloatAtan2)
float BrFloatAtan2(float x, float y) {
    LOG_TRACE("(%f, %f)", x, y);

    (void)x;
    (void)y;

    return original_BrFloatAtan2(x, y);
}

