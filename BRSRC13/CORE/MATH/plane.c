#include "plane.h"

#include "harness/trace.h"

#include "carm95_hooks.h"


static br_int_32(__cdecl*original_BrPlaneEquation)(br_vector4 *, br_vector3 *, br_vector3 *, br_vector3 *) = (br_int_32(__cdecl*)(br_vector4 *, br_vector3 *, br_vector3 *, br_vector3 *))0x00501d90;
CARM95_HOOK_FUNCTION(original_BrPlaneEquation, BrPlaneEquation)
br_int_32 __cdecl BrPlaneEquation(br_vector4 *eqn, br_vector3 *v0, br_vector3 *v1, br_vector3 *v2) {
    br_vector3 a;
    br_vector3 b;
    float ax;
    float ay;
    float az;
    float bx;
    float by;
    float bz;
    float nx;
    float ny;
    float nz;
    float d;
    float l;
    LOG_TRACE("(%p, %p, %p, %p)", eqn, v0, v1, v2);

    (void)eqn;
    (void)v0;
    (void)v1;
    (void)v2;
    (void)a;
    (void)b;
    (void)ax;
    (void)ay;
    (void)az;
    (void)bx;
    (void)by;
    (void)bz;
    (void)nx;
    (void)ny;
    (void)nz;
    (void)d;
    (void)l;

    return original_BrPlaneEquation(eqn, v0, v1, v2);
}

