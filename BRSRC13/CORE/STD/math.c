#include "math.h"

#include "harness/trace.h"

#include "carm95_hooks.h"

#include "carm95_webserver.h"

#include <assert.h>

function_hook_state_t function_hook_state_BrFloatFloor = HOOK_UNAVAILABLE;
static float(__cdecl*original_BrFloatFloor)(float) = (float(__cdecl*)(float))0x00502b20;
CARM95_HOOK_FUNCTION(original_BrFloatFloor, BrFloatFloor)
float __cdecl BrFloatFloor(float f) {
    LOG_TRACE("(%f)", f);

    (void)f;

    if (function_hook_state_BrFloatFloor == HOOK_ENABLED) {
        assert(0 && "BrFloatFloor not implemented.");
        abort();
    } else {
        return original_BrFloatFloor(f);
    }
}

function_hook_state_t function_hook_state_BrFloatCeil = HOOK_UNAVAILABLE;
static float(__cdecl*original_BrFloatCeil)(float) = (float(__cdecl*)(float))0x00502b40;
CARM95_HOOK_FUNCTION(original_BrFloatCeil, BrFloatCeil)
float __cdecl BrFloatCeil(float f) {
    LOG_TRACE("(%f)", f);

    (void)f;

    if (function_hook_state_BrFloatCeil == HOOK_ENABLED) {
        assert(0 && "BrFloatCeil not implemented.");
        abort();
    } else {
        return original_BrFloatCeil(f);
    }
}

function_hook_state_t function_hook_state_BrFloatSqrt = HOOK_UNAVAILABLE;
static float(__cdecl*original_BrFloatSqrt)(float) = (float(__cdecl*)(float))0x00502b60;
CARM95_HOOK_FUNCTION(original_BrFloatSqrt, BrFloatSqrt)
float __cdecl BrFloatSqrt(float f) {
    LOG_TRACE("(%f)", f);

    (void)f;

    if (function_hook_state_BrFloatSqrt == HOOK_ENABLED) {
        assert(0 && "BrFloatSqrt not implemented.");
        abort();
    } else {
        return original_BrFloatSqrt(f);
    }
}

function_hook_state_t function_hook_state_BrFloatPow = HOOK_UNAVAILABLE;
static float(__stdcall*original_BrFloatPow)(float, float) = (float(__stdcall*)(float, float))0x00502b70;
CARM95_HOOK_FUNCTION(original_BrFloatPow, BrFloatPow)
float __stdcall BrFloatPow(float a, float b) {
    LOG_TRACE("(%f, %f)", a, b);

    (void)a;
    (void)b;

    if (function_hook_state_BrFloatPow == HOOK_ENABLED) {
        assert(0 && "BrFloatPow not implemented.");
        abort();
    } else {
        return original_BrFloatPow(a, b);
    }
}

function_hook_state_t function_hook_state_BrFloatAtan2 = HOOK_UNAVAILABLE;
static float(__cdecl*original_BrFloatAtan2)(float, float) = (float(__cdecl*)(float, float))0x00502b80;
CARM95_HOOK_FUNCTION(original_BrFloatAtan2, BrFloatAtan2)
float __cdecl BrFloatAtan2(float x, float y) {
    LOG_TRACE("(%f, %f)", x, y);

    (void)x;
    (void)y;

    if (function_hook_state_BrFloatAtan2 == HOOK_ENABLED) {
        assert(0 && "BrFloatAtan2 not implemented.");
        abort();
    } else {
        return original_BrFloatAtan2(x, y);
    }
}

