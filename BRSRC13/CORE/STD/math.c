#include "math.h"

#include "harness/trace.h"

#include "carm95_hooks.h"


static float(__cdecl*original_BrFloatFloor)(float) = (float(__cdecl*)(float))0x00502b20;
CARM95_HOOK_FUNCTION(original_BrFloatFloor, BrFloatFloor)
float __cdecl BrFloatFloor(float f) {
    LOG_TRACE("(%f)", f);

    (void)f;

    return original_BrFloatFloor(f);
}

static float(__cdecl*original_BrFloatCeil)(float) = (float(__cdecl*)(float))0x00502b40;
CARM95_HOOK_FUNCTION(original_BrFloatCeil, BrFloatCeil)
float __cdecl BrFloatCeil(float f) {
    LOG_TRACE("(%f)", f);

    (void)f;

    return original_BrFloatCeil(f);
}

static float(__cdecl*original_BrFloatSqrt)(float) = (float(__cdecl*)(float))0x00502b60;
CARM95_HOOK_FUNCTION(original_BrFloatSqrt, BrFloatSqrt)
float __cdecl BrFloatSqrt(float f) {
    LOG_TRACE("(%f)", f);

    (void)f;

    return original_BrFloatSqrt(f);
}

static float(__stdcall*original_BrFloatPow)(float, float) = (float(__stdcall*)(float, float))0x00502b70;
CARM95_HOOK_FUNCTION(original_BrFloatPow, BrFloatPow)
float __stdcall BrFloatPow(float a, float b) {
    LOG_TRACE("(%f, %f)", a, b);

    (void)a;
    (void)b;

    return original_BrFloatPow(a, b);
}

static float(__cdecl*original_BrFloatAtan2)(float, float) = (float(__cdecl*)(float, float))0x00502b80;
CARM95_HOOK_FUNCTION(original_BrFloatAtan2, BrFloatAtan2)
float __cdecl BrFloatAtan2(float x, float y) {
    LOG_TRACE("(%f, %f)", x, y);

    (void)x;
    (void)y;

    return original_BrFloatAtan2(x, y);
}

