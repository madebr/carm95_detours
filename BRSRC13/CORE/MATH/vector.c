#include "vector.h"

#include "harness/trace.h"

#include "carm95_hooks.h"

#include "carm95_webserver.h"

#include <assert.h>

function_hook_state_t function_hook_state_BrVector2Copy = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_BrVector2Copy)
static void(__cdecl*original_BrVector2Copy)(br_vector2 *, br_vector2 *) = (void(__cdecl*)(br_vector2 *, br_vector2 *))0x004d2abd;
CARM95_HOOK_FUNCTION(original_BrVector2Copy, BrVector2Copy)
void __cdecl BrVector2Copy(br_vector2 *v1, br_vector2 *v2) {
    LOG_TRACE("(%p, %p)", v1, v2);

    (void)v1;
    (void)v2;

    if (function_hook_state_BrVector2Copy == HOOK_ENABLED) {
        assert(0 && "BrVector2Copy not implemented.");
        abort();
    } else {
        original_BrVector2Copy(v1, v2);
    }
}

function_hook_state_t function_hook_state_BrVector2Set = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_BrVector2Set)
static void(__cdecl*original_BrVector2Set)(br_vector2 *, br_scalar, br_scalar) = (void(__cdecl*)(br_vector2 *, br_scalar, br_scalar))0x004d2ad3;
CARM95_HOOK_FUNCTION(original_BrVector2Set, BrVector2Set)
void __cdecl BrVector2Set(br_vector2 *v1, br_scalar s1, br_scalar s2) {
    LOG_TRACE("(%p, %f, %f)", v1, s1, s2);

    (void)v1;
    (void)s1;
    (void)s2;

    if (function_hook_state_BrVector2Set == HOOK_ENABLED) {
        assert(0 && "BrVector2Set not implemented.");
        abort();
    } else {
        original_BrVector2Set(v1, s1, s2);
    }
}

function_hook_state_t function_hook_state_BrVector2SetInt = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_BrVector2SetInt)
static void(__cdecl*original_BrVector2SetInt)(br_vector2 *, int, int) = (void(__cdecl*)(br_vector2 *, int, int))0x004d2af2;
CARM95_HOOK_FUNCTION(original_BrVector2SetInt, BrVector2SetInt)
void __cdecl BrVector2SetInt(br_vector2 *v1, int i1, int i2) {
    LOG_TRACE("(%p, %d, %d)", v1, i1, i2);

    (void)v1;
    (void)i1;
    (void)i2;

    if (function_hook_state_BrVector2SetInt == HOOK_ENABLED) {
        assert(0 && "BrVector2SetInt not implemented.");
        abort();
    } else {
        original_BrVector2SetInt(v1, i1, i2);
    }
}

function_hook_state_t function_hook_state_BrVector2SetFloat = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_BrVector2SetFloat)
static void(__cdecl*original_BrVector2SetFloat)(br_vector2 *, float, float) = (void(__cdecl*)(br_vector2 *, float, float))0x004d2b1a;
CARM95_HOOK_FUNCTION(original_BrVector2SetFloat, BrVector2SetFloat)
void __cdecl BrVector2SetFloat(br_vector2 *v1, float f1, float f2) {
    LOG_TRACE("(%p, %f, %f)", v1, f1, f2);

    (void)v1;
    (void)f1;
    (void)f2;

    if (function_hook_state_BrVector2SetFloat == HOOK_ENABLED) {
        assert(0 && "BrVector2SetFloat not implemented.");
        abort();
    } else {
        original_BrVector2SetFloat(v1, f1, f2);
    }
}

function_hook_state_t function_hook_state_BrVector2Negate = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_BrVector2Negate)
static void(__cdecl*original_BrVector2Negate)(br_vector2 *, br_vector2 *) = (void(__cdecl*)(br_vector2 *, br_vector2 *))0x004d2b32;
CARM95_HOOK_FUNCTION(original_BrVector2Negate, BrVector2Negate)
void __cdecl BrVector2Negate(br_vector2 *v1, br_vector2 *v2) {
    LOG_TRACE("(%p, %p)", v1, v2);

    (void)v1;
    (void)v2;

    if (function_hook_state_BrVector2Negate == HOOK_ENABLED) {
        assert(0 && "BrVector2Negate not implemented.");
        abort();
    } else {
        original_BrVector2Negate(v1, v2);
    }
}

function_hook_state_t function_hook_state_BrVector2Add = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_BrVector2Add)
static void(__cdecl*original_BrVector2Add)(br_vector2 *, br_vector2 *, br_vector2 *) = (void(__cdecl*)(br_vector2 *, br_vector2 *, br_vector2 *))0x004d2b57;
CARM95_HOOK_FUNCTION(original_BrVector2Add, BrVector2Add)
void __cdecl BrVector2Add(br_vector2 *v1, br_vector2 *v2, br_vector2 *v3) {
    LOG_TRACE("(%p, %p, %p)", v1, v2, v3);

    (void)v1;
    (void)v2;
    (void)v3;

    if (function_hook_state_BrVector2Add == HOOK_ENABLED) {
        assert(0 && "BrVector2Add not implemented.");
        abort();
    } else {
        original_BrVector2Add(v1, v2, v3);
    }
}

function_hook_state_t function_hook_state_BrVector2Accumulate = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_BrVector2Accumulate)
static void(__cdecl*original_BrVector2Accumulate)(br_vector2 *, br_vector2 *) = (void(__cdecl*)(br_vector2 *, br_vector2 *))0x004d2b7c;
CARM95_HOOK_FUNCTION(original_BrVector2Accumulate, BrVector2Accumulate)
void __cdecl BrVector2Accumulate(br_vector2 *v1, br_vector2 *v2) {
    LOG_TRACE("(%p, %p)", v1, v2);

    (void)v1;
    (void)v2;

    if (function_hook_state_BrVector2Accumulate == HOOK_ENABLED) {
        assert(0 && "BrVector2Accumulate not implemented.");
        abort();
    } else {
        original_BrVector2Accumulate(v1, v2);
    }
}

function_hook_state_t function_hook_state_BrVector2Sub = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_BrVector2Sub)
static void(__cdecl*original_BrVector2Sub)(br_vector2 *, br_vector2 *, br_vector2 *) = (void(__cdecl*)(br_vector2 *, br_vector2 *, br_vector2 *))0x004d2b98;
CARM95_HOOK_FUNCTION(original_BrVector2Sub, BrVector2Sub)
void __cdecl BrVector2Sub(br_vector2 *v1, br_vector2 *v2, br_vector2 *v3) {
    LOG_TRACE("(%p, %p, %p)", v1, v2, v3);

    (void)v1;
    (void)v2;
    (void)v3;

    if (function_hook_state_BrVector2Sub == HOOK_ENABLED) {
        assert(0 && "BrVector2Sub not implemented.");
        abort();
    } else {
        original_BrVector2Sub(v1, v2, v3);
    }
}

function_hook_state_t function_hook_state_BrVector2Scale = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_BrVector2Scale)
static void(__cdecl*original_BrVector2Scale)(br_vector2 *, br_vector2 *, br_scalar) = (void(__cdecl*)(br_vector2 *, br_vector2 *, br_scalar))0x004d2bbc;
CARM95_HOOK_FUNCTION(original_BrVector2Scale, BrVector2Scale)
void __cdecl BrVector2Scale(br_vector2 *v1, br_vector2 *v2, br_scalar s) {
    LOG_TRACE("(%p, %p, %f)", v1, v2, s);

    (void)v1;
    (void)v2;
    (void)s;

    if (function_hook_state_BrVector2Scale == HOOK_ENABLED) {
        assert(0 && "BrVector2Scale not implemented.");
        abort();
    } else {
        original_BrVector2Scale(v1, v2, s);
    }
}

function_hook_state_t function_hook_state_BrVector2InvScale = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_BrVector2InvScale)
static void(__cdecl*original_BrVector2InvScale)(br_vector2 *, br_vector2 *, br_scalar) = (void(__cdecl*)(br_vector2 *, br_vector2 *, br_scalar))0x004d2bdb;
CARM95_HOOK_FUNCTION(original_BrVector2InvScale, BrVector2InvScale)
void __cdecl BrVector2InvScale(br_vector2 *v1, br_vector2 *v2, br_scalar s) {
    LOG_TRACE("(%p, %p, %f)", v1, v2, s);

    (void)v1;
    (void)v2;
    (void)s;

    if (function_hook_state_BrVector2InvScale == HOOK_ENABLED) {
        assert(0 && "BrVector2InvScale not implemented.");
        abort();
    } else {
        original_BrVector2InvScale(v1, v2, s);
    }
}

function_hook_state_t function_hook_state_BrVector2Dot = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_BrVector2Dot)
static br_scalar(__cdecl*original_BrVector2Dot)(br_vector2 *, br_vector2 *) = (br_scalar(__cdecl*)(br_vector2 *, br_vector2 *))0x004d2bfb;
CARM95_HOOK_FUNCTION(original_BrVector2Dot, BrVector2Dot)
br_scalar __cdecl BrVector2Dot(br_vector2 *v1, br_vector2 *v2) {
    LOG_TRACE("(%p, %p)", v1, v2);

    (void)v1;
    (void)v2;

    if (function_hook_state_BrVector2Dot == HOOK_ENABLED) {
        assert(0 && "BrVector2Dot not implemented.");
        abort();
    } else {
        return original_BrVector2Dot(v1, v2);
    }
}

function_hook_state_t function_hook_state_BrVector2Length = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_BrVector2Length)
static br_scalar(__cdecl*original_BrVector2Length)(br_vector2 *) = (br_scalar(__cdecl*)(br_vector2 *))0x004d2c15;
CARM95_HOOK_FUNCTION(original_BrVector2Length, BrVector2Length)
br_scalar __cdecl BrVector2Length(br_vector2 *v1) {
    LOG_TRACE("(%p)", v1);

    (void)v1;

    if (function_hook_state_BrVector2Length == HOOK_ENABLED) {
        assert(0 && "BrVector2Length not implemented.");
        abort();
    } else {
        return original_BrVector2Length(v1);
    }
}

function_hook_state_t function_hook_state_BrVector2LengthSquared = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_BrVector2LengthSquared)
static br_scalar(__cdecl*original_BrVector2LengthSquared)(br_vector2 *) = (br_scalar(__cdecl*)(br_vector2 *))0x004d2c33;
CARM95_HOOK_FUNCTION(original_BrVector2LengthSquared, BrVector2LengthSquared)
br_scalar __cdecl BrVector2LengthSquared(br_vector2 *v1) {
    LOG_TRACE("(%p)", v1);

    (void)v1;

    if (function_hook_state_BrVector2LengthSquared == HOOK_ENABLED) {
        assert(0 && "BrVector2LengthSquared not implemented.");
        abort();
    } else {
        return original_BrVector2LengthSquared(v1);
    }
}

function_hook_state_t function_hook_state_BrVector3Copy = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_BrVector3Copy)
static void(__cdecl*original_BrVector3Copy)(br_vector3 *, br_vector3 *) = (void(__cdecl*)(br_vector3 *, br_vector3 *))0x004d2c51;
CARM95_HOOK_FUNCTION(original_BrVector3Copy, BrVector3Copy)
void __cdecl BrVector3Copy(br_vector3 *v1, br_vector3 *v2) {
    LOG_TRACE("(%p, %p)", v1, v2);

    (void)v1;
    (void)v2;

    if (function_hook_state_BrVector3Copy == HOOK_ENABLED) {
        assert(0 && "BrVector3Copy not implemented.");
        abort();
    } else {
        original_BrVector3Copy(v1, v2);
    }
}

function_hook_state_t function_hook_state_BrVector3Set = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_BrVector3Set)
static void(__cdecl*original_BrVector3Set)(br_vector3 *, br_scalar, br_scalar, br_scalar) = (void(__cdecl*)(br_vector3 *, br_scalar, br_scalar, br_scalar))0x004d2c7b;
CARM95_HOOK_FUNCTION(original_BrVector3Set, BrVector3Set)
void __cdecl BrVector3Set(br_vector3 *v1, br_scalar s1, br_scalar s2, br_scalar s3) {
    LOG_TRACE("(%p, %f, %f, %f)", v1, s1, s2, s3);

    (void)v1;
    (void)s1;
    (void)s2;
    (void)s3;

    if (function_hook_state_BrVector3Set == HOOK_ENABLED) {
        assert(0 && "BrVector3Set not implemented.");
        abort();
    } else {
        original_BrVector3Set(v1, s1, s2, s3);
    }
}

function_hook_state_t function_hook_state_BrVector3SetInt = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_BrVector3SetInt)
static void(__cdecl*original_BrVector3SetInt)(br_vector3 *, int, int, int) = (void(__cdecl*)(br_vector3 *, int, int, int))0x004d2c9b;
CARM95_HOOK_FUNCTION(original_BrVector3SetInt, BrVector3SetInt)
void __cdecl BrVector3SetInt(br_vector3 *v1, int i1, int i2, int i3) {
    LOG_TRACE("(%p, %d, %d, %d)", v1, i1, i2, i3);

    (void)v1;
    (void)i1;
    (void)i2;
    (void)i3;

    if (function_hook_state_BrVector3SetInt == HOOK_ENABLED) {
        assert(0 && "BrVector3SetInt not implemented.");
        abort();
    } else {
        original_BrVector3SetInt(v1, i1, i2, i3);
    }
}

function_hook_state_t function_hook_state_BrVector3SetFloat = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_BrVector3SetFloat)
static void(__cdecl*original_BrVector3SetFloat)(br_vector3 *, float, float, float) = (void(__cdecl*)(br_vector3 *, float, float, float))0x004d2cd0;
CARM95_HOOK_FUNCTION(original_BrVector3SetFloat, BrVector3SetFloat)
void __cdecl BrVector3SetFloat(br_vector3 *v1, float f1, float f2, float f3) {
    LOG_TRACE("(%p, %f, %f, %f)", v1, f1, f2, f3);

    (void)v1;
    (void)f1;
    (void)f2;
    (void)f3;

    if (function_hook_state_BrVector3SetFloat == HOOK_ENABLED) {
        assert(0 && "BrVector3SetFloat not implemented.");
        abort();
    } else {
        original_BrVector3SetFloat(v1, f1, f2, f3);
    }
}

function_hook_state_t function_hook_state_BrVector3Negate = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_BrVector3Negate)
static void(__cdecl*original_BrVector3Negate)(br_vector3 *, br_vector3 *) = (void(__cdecl*)(br_vector3 *, br_vector3 *))0x004d2ceb;
CARM95_HOOK_FUNCTION(original_BrVector3Negate, BrVector3Negate)
void __cdecl BrVector3Negate(br_vector3 *v1, br_vector3 *v2) {
    LOG_TRACE("(%p, %p)", v1, v2);

    (void)v1;
    (void)v2;

    if (function_hook_state_BrVector3Negate == HOOK_ENABLED) {
        assert(0 && "BrVector3Negate not implemented.");
        abort();
    } else {
        original_BrVector3Negate(v1, v2);
    }
}

function_hook_state_t function_hook_state_BrVector3Add = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_BrVector3Add)
static void(__cdecl*original_BrVector3Add)(br_vector3 *, br_vector3 *, br_vector3 *) = (void(__cdecl*)(br_vector3 *, br_vector3 *, br_vector3 *))0x004d2d0f;
CARM95_HOOK_FUNCTION(original_BrVector3Add, BrVector3Add)
void __cdecl BrVector3Add(br_vector3 *v1, br_vector3 *v2, br_vector3 *v3) {
    LOG_TRACE("(%p, %p, %p)", v1, v2, v3);

    (void)v1;
    (void)v2;
    (void)v3;

    if (function_hook_state_BrVector3Add == HOOK_ENABLED) {
        assert(0 && "BrVector3Add not implemented.");
        abort();
    } else {
        original_BrVector3Add(v1, v2, v3);
    }
}

function_hook_state_t function_hook_state_BrVector3Accumulate = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_BrVector3Accumulate)
static void(__cdecl*original_BrVector3Accumulate)(br_vector3 *, br_vector3 *) = (void(__cdecl*)(br_vector3 *, br_vector3 *))0x004d2d35;
CARM95_HOOK_FUNCTION(original_BrVector3Accumulate, BrVector3Accumulate)
void __cdecl BrVector3Accumulate(br_vector3 *v1, br_vector3 *v2) {
    LOG_TRACE("(%p, %p)", v1, v2);

    (void)v1;
    (void)v2;

    if (function_hook_state_BrVector3Accumulate == HOOK_ENABLED) {
        assert(0 && "BrVector3Accumulate not implemented.");
        abort();
    } else {
        original_BrVector3Accumulate(v1, v2);
    }
}

function_hook_state_t function_hook_state_BrVector3Sub = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_BrVector3Sub)
static void(__cdecl*original_BrVector3Sub)(br_vector3 *, br_vector3 *, br_vector3 *) = (void(__cdecl*)(br_vector3 *, br_vector3 *, br_vector3 *))0x004d2d61;
CARM95_HOOK_FUNCTION(original_BrVector3Sub, BrVector3Sub)
void __cdecl BrVector3Sub(br_vector3 *v1, br_vector3 *v2, br_vector3 *v3) {
    LOG_TRACE("(%p, %p, %p)", v1, v2, v3);

    (void)v1;
    (void)v2;
    (void)v3;

    if (function_hook_state_BrVector3Sub == HOOK_ENABLED) {
        assert(0 && "BrVector3Sub not implemented.");
        abort();
    } else {
        original_BrVector3Sub(v1, v2, v3);
    }
}

function_hook_state_t function_hook_state_BrVector3Scale = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_BrVector3Scale)
static void(__cdecl*original_BrVector3Scale)(br_vector3 *, br_vector3 *, br_scalar) = (void(__cdecl*)(br_vector3 *, br_vector3 *, br_scalar))0x004d2d95;
CARM95_HOOK_FUNCTION(original_BrVector3Scale, BrVector3Scale)
void __cdecl BrVector3Scale(br_vector3 *v1, br_vector3 *v2, br_scalar s) {
    LOG_TRACE("(%p, %p, %f)", v1, v2, s);

    (void)v1;
    (void)v2;
    (void)s;

    if (function_hook_state_BrVector3Scale == HOOK_ENABLED) {
        assert(0 && "BrVector3Scale not implemented.");
        abort();
    } else {
        original_BrVector3Scale(v1, v2, s);
    }
}

function_hook_state_t function_hook_state_BrVector3InvScale = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_BrVector3InvScale)
static void(__cdecl*original_BrVector3InvScale)(br_vector3 *, br_vector3 *, br_scalar) = (void(__cdecl*)(br_vector3 *, br_vector3 *, br_scalar))0x004d2dc5;
CARM95_HOOK_FUNCTION(original_BrVector3InvScale, BrVector3InvScale)
void __cdecl BrVector3InvScale(br_vector3 *v1, br_vector3 *v2, br_scalar s) {
    LOG_TRACE("(%p, %p, %f)", v1, v2, s);

    (void)v1;
    (void)v2;
    (void)s;

    if (function_hook_state_BrVector3InvScale == HOOK_ENABLED) {
        assert(0 && "BrVector3InvScale not implemented.");
        abort();
    } else {
        original_BrVector3InvScale(v1, v2, s);
    }
}

function_hook_state_t function_hook_state_BrVector3Dot = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_BrVector3Dot)
static br_scalar(__cdecl*original_BrVector3Dot)(br_vector3 *, br_vector3 *) = (br_scalar(__cdecl*)(br_vector3 *, br_vector3 *))0x004d2df5;
CARM95_HOOK_FUNCTION(original_BrVector3Dot, BrVector3Dot)
br_scalar __cdecl BrVector3Dot(br_vector3 *v1, br_vector3 *v2) {
    LOG_TRACE("(%p, %p)", v1, v2);

    (void)v1;
    (void)v2;

    if (function_hook_state_BrVector3Dot == HOOK_ENABLED) {
        assert(0 && "BrVector3Dot not implemented.");
        abort();
    } else {
        return original_BrVector3Dot(v1, v2);
    }
}

function_hook_state_t function_hook_state_BrVector3Cross = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_BrVector3Cross)
static void(__cdecl*original_BrVector3Cross)(br_vector3 *, br_vector3 *, br_vector3 *) = (void(__cdecl*)(br_vector3 *, br_vector3 *, br_vector3 *))0x004d2e1f;
CARM95_HOOK_FUNCTION(original_BrVector3Cross, BrVector3Cross)
void __cdecl BrVector3Cross(br_vector3 *v1, br_vector3 *v2, br_vector3 *v3) {
    LOG_TRACE("(%p, %p, %p)", v1, v2, v3);

    (void)v1;
    (void)v2;
    (void)v3;

    if (function_hook_state_BrVector3Cross == HOOK_ENABLED) {
        assert(0 && "BrVector3Cross not implemented.");
        abort();
    } else {
        original_BrVector3Cross(v1, v2, v3);
    }
}

function_hook_state_t function_hook_state_BrVector3Length = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_BrVector3Length)
static br_scalar(__cdecl*original_BrVector3Length)(br_vector3 *) = (br_scalar(__cdecl*)(br_vector3 *))0x004d2e5b;
CARM95_HOOK_FUNCTION(original_BrVector3Length, BrVector3Length)
br_scalar __cdecl BrVector3Length(br_vector3 *v1) {
    LOG_TRACE("(%p)", v1);

    (void)v1;

    if (function_hook_state_BrVector3Length == HOOK_ENABLED) {
        assert(0 && "BrVector3Length not implemented.");
        abort();
    } else {
        return original_BrVector3Length(v1);
    }
}

function_hook_state_t function_hook_state_BrVector3LengthSquared = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_BrVector3LengthSquared)
static br_scalar(__cdecl*original_BrVector3LengthSquared)(br_vector3 *) = (br_scalar(__cdecl*)(br_vector3 *))0x004d2e7d;
CARM95_HOOK_FUNCTION(original_BrVector3LengthSquared, BrVector3LengthSquared)
br_scalar __cdecl BrVector3LengthSquared(br_vector3 *v1) {
    LOG_TRACE("(%p)", v1);

    (void)v1;

    if (function_hook_state_BrVector3LengthSquared == HOOK_ENABLED) {
        assert(0 && "BrVector3LengthSquared not implemented.");
        abort();
    } else {
        return original_BrVector3LengthSquared(v1);
    }
}

function_hook_state_t function_hook_state_BrVector3Normalise = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_BrVector3Normalise)
static void(__cdecl*original_BrVector3Normalise)(br_vector3 *, br_vector3 *) = (void(__cdecl*)(br_vector3 *, br_vector3 *))0x004d2e9b;
CARM95_HOOK_FUNCTION(original_BrVector3Normalise, BrVector3Normalise)
void __cdecl BrVector3Normalise(br_vector3 *v1, br_vector3 *v2) {
    br_scalar scale;
    LOG_TRACE("(%p, %p)", v1, v2);

    (void)v1;
    (void)v2;
    (void)scale;

    if (function_hook_state_BrVector3Normalise == HOOK_ENABLED) {
        assert(0 && "BrVector3Normalise not implemented.");
        abort();
    } else {
        original_BrVector3Normalise(v1, v2);
    }
}

function_hook_state_t function_hook_state_BrVector3NormaliseLP = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_BrVector3NormaliseLP)
static void(__cdecl*original_BrVector3NormaliseLP)(br_vector3 *, br_vector3 *) = (void(__cdecl*)(br_vector3 *, br_vector3 *))0x004d2f0c;
CARM95_HOOK_FUNCTION(original_BrVector3NormaliseLP, BrVector3NormaliseLP)
void __cdecl BrVector3NormaliseLP(br_vector3 *v1, br_vector3 *v2) {
    br_scalar scale;
    LOG_TRACE("(%p, %p)", v1, v2);

    (void)v1;
    (void)v2;
    (void)scale;

    if (function_hook_state_BrVector3NormaliseLP == HOOK_ENABLED) {
        assert(0 && "BrVector3NormaliseLP not implemented.");
        abort();
    } else {
        original_BrVector3NormaliseLP(v1, v2);
    }
}

function_hook_state_t function_hook_state_BrVector4Dot = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_BrVector4Dot)
static br_scalar(__cdecl*original_BrVector4Dot)(br_vector4 *, br_vector4 *) = (br_scalar(__cdecl*)(br_vector4 *, br_vector4 *))0x004d2f6a;
CARM95_HOOK_FUNCTION(original_BrVector4Dot, BrVector4Dot)
br_scalar __cdecl BrVector4Dot(br_vector4 *v1, br_vector4 *v2) {
    LOG_TRACE("(%p, %p)", v1, v2);

    (void)v1;
    (void)v2;

    if (function_hook_state_BrVector4Dot == HOOK_ENABLED) {
        assert(0 && "BrVector4Dot not implemented.");
        abort();
    } else {
        return original_BrVector4Dot(v1, v2);
    }
}

function_hook_state_t function_hook_state_BrVector4Copy = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_BrVector4Copy)
static void(__cdecl*original_BrVector4Copy)(br_vector4 *, br_vector4 *) = (void(__cdecl*)(br_vector4 *, br_vector4 *))0x004d2f99;
CARM95_HOOK_FUNCTION(original_BrVector4Copy, BrVector4Copy)
void __cdecl BrVector4Copy(br_vector4 *v1, br_vector4 *v2) {
    LOG_TRACE("(%p, %p)", v1, v2);

    (void)v1;
    (void)v2;

    if (function_hook_state_BrVector4Copy == HOOK_ENABLED) {
        assert(0 && "BrVector4Copy not implemented.");
        abort();
    } else {
        original_BrVector4Copy(v1, v2);
    }
}

function_hook_state_t function_hook_state_BrFVector2Dot = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_BrFVector2Dot)
static br_scalar(__stdcall*original_BrFVector2Dot)(br_fvector2 *, br_vector2 *) = (br_scalar(__stdcall*)(br_fvector2 *, br_vector2 *))0x004d2fc3;
CARM95_HOOK_FUNCTION(original_BrFVector2Dot, BrFVector2Dot)
br_scalar __stdcall BrFVector2Dot(br_fvector2 *v1, br_vector2 *v2) {
    LOG_TRACE("(%p, %p)", v1, v2);

    (void)v1;
    (void)v2;

    if (function_hook_state_BrFVector2Dot == HOOK_ENABLED) {
        assert(0 && "BrFVector2Dot not implemented.");
        abort();
    } else {
        return original_BrFVector2Dot(v1, v2);
    }
}

function_hook_state_t function_hook_state_BrFVector3Copy = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_BrFVector3Copy)
static void(__stdcall*original_BrFVector3Copy)(br_fvector3 *, br_vector3 *) = (void(__stdcall*)(br_fvector3 *, br_vector3 *))0x004d2fe7;
CARM95_HOOK_FUNCTION(original_BrFVector3Copy, BrFVector3Copy)
void __stdcall BrFVector3Copy(br_fvector3 *v1, br_vector3 *v2) {
    LOG_TRACE("(%p, %p)", v1, v2);

    (void)v1;
    (void)v2;

    if (function_hook_state_BrFVector3Copy == HOOK_ENABLED) {
        assert(0 && "BrFVector3Copy not implemented.");
        abort();
    } else {
        original_BrFVector3Copy(v1, v2);
    }
}

function_hook_state_t function_hook_state_BrVector3ScaleF = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_BrVector3ScaleF)
static void(__stdcall*original_BrVector3ScaleF)(br_vector3 *, br_fvector3 *, br_scalar) = (void(__stdcall*)(br_vector3 *, br_fvector3 *, br_scalar))0x004d300d;
CARM95_HOOK_FUNCTION(original_BrVector3ScaleF, BrVector3ScaleF)
void __stdcall BrVector3ScaleF(br_vector3 *v1, br_fvector3 *v2, br_scalar s) {
    LOG_TRACE("(%p, %p, %f)", v1, v2, s);

    (void)v1;
    (void)v2;
    (void)s;

    if (function_hook_state_BrVector3ScaleF == HOOK_ENABLED) {
        assert(0 && "BrVector3ScaleF not implemented.");
        abort();
    } else {
        original_BrVector3ScaleF(v1, v2, s);
    }
}

function_hook_state_t function_hook_state_BrFVector3Dot = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_BrFVector3Dot)
static br_scalar(__stdcall*original_BrFVector3Dot)(br_fvector3 *, br_vector3 *) = (br_scalar(__stdcall*)(br_fvector3 *, br_vector3 *))0x004d3037;
CARM95_HOOK_FUNCTION(original_BrFVector3Dot, BrFVector3Dot)
br_scalar __stdcall BrFVector3Dot(br_fvector3 *v1, br_vector3 *v2) {
    LOG_TRACE("(%p, %p)", v1, v2);

    (void)v1;
    (void)v2;

    if (function_hook_state_BrFVector3Dot == HOOK_ENABLED) {
        assert(0 && "BrFVector3Dot not implemented.");
        abort();
    } else {
        return original_BrFVector3Dot(v1, v2);
    }
}

function_hook_state_t function_hook_state_BrFVector3Normalise = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_BrFVector3Normalise)
static void(__stdcall*original_BrFVector3Normalise)(br_fvector3 *, br_vector3 *) = (void(__stdcall*)(br_fvector3 *, br_vector3 *))0x004d3061;
CARM95_HOOK_FUNCTION(original_BrFVector3Normalise, BrFVector3Normalise)
void __stdcall BrFVector3Normalise(br_fvector3 *v1, br_vector3 *v2) {
    br_scalar scale;
    LOG_TRACE("(%p, %p)", v1, v2);

    (void)v1;
    (void)v2;
    (void)scale;

    if (function_hook_state_BrFVector3Normalise == HOOK_ENABLED) {
        assert(0 && "BrFVector3Normalise not implemented.");
        abort();
    } else {
        original_BrFVector3Normalise(v1, v2);
    }
}

function_hook_state_t function_hook_state_BrFVector3NormaliseLP = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_BrFVector3NormaliseLP)
static void(__stdcall*original_BrFVector3NormaliseLP)(br_fvector3 *, br_vector3 *) = (void(__stdcall*)(br_fvector3 *, br_vector3 *))0x004d30e0;
CARM95_HOOK_FUNCTION(original_BrFVector3NormaliseLP, BrFVector3NormaliseLP)
void __stdcall BrFVector3NormaliseLP(br_fvector3 *v1, br_vector3 *v2) {
    br_scalar scale;
    LOG_TRACE("(%p, %p)", v1, v2);

    (void)v1;
    (void)v2;
    (void)scale;

    if (function_hook_state_BrFVector3NormaliseLP == HOOK_ENABLED) {
        assert(0 && "BrFVector3NormaliseLP not implemented.");
        abort();
    } else {
        original_BrFVector3NormaliseLP(v1, v2);
    }
}

function_hook_state_t function_hook_state_BrVector2Normalise = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_BrVector2Normalise)
static void(__cdecl*original_BrVector2Normalise)(br_vector2 *, br_vector2 *) = (void(__cdecl*)(br_vector2 *, br_vector2 *))0x004d3121;
CARM95_HOOK_FUNCTION(original_BrVector2Normalise, BrVector2Normalise)
void __cdecl BrVector2Normalise(br_vector2 *v1, br_vector2 *v2) {
    br_scalar scale;
    LOG_TRACE("(%p, %p)", v1, v2);

    (void)v1;
    (void)v2;
    (void)scale;

    if (function_hook_state_BrVector2Normalise == HOOK_ENABLED) {
        assert(0 && "BrVector2Normalise not implemented.");
        abort();
    } else {
        original_BrVector2Normalise(v1, v2);
    }
}

