#include "angles.h"

#include "harness/trace.h"

#include "carm95_hooks.h"

#include "carm95_webserver.h"

#include <assert.h>
struct order_info(* hookvar_OrderAxes )[32] = (void*)0x00523cd8;

function_hook_state_t function_hook_state_BrEulerToMatrix34 = HOOK_UNAVAILABLE;
static br_matrix34 *(__cdecl*original_BrEulerToMatrix34)(br_matrix34 *, br_euler *) = (br_matrix34 *(__cdecl*)(br_matrix34 *, br_euler *))0x004d4c70;
CARM95_HOOK_FUNCTION(original_BrEulerToMatrix34, BrEulerToMatrix34)
br_matrix34* __cdecl BrEulerToMatrix34(br_matrix34 *mat, br_euler *euler) {
    br_uint_8 o;
    br_angle ti;
    br_angle tj;
    br_angle th;
    br_scalar ci;
    br_scalar cj;
    br_scalar ch;
    br_scalar si;
    br_scalar sj;
    br_scalar sh;
    br_scalar cc;
    br_scalar cs;
    br_scalar sc;
    br_scalar ss;
    int a0;
    int a1;
    int a2;
    LOG_TRACE("(%p, %p)", mat, euler);

    (void)mat;
    (void)euler;
    (void)o;
    (void)ti;
    (void)tj;
    (void)th;
    (void)ci;
    (void)cj;
    (void)ch;
    (void)si;
    (void)sj;
    (void)sh;
    (void)cc;
    (void)cs;
    (void)sc;
    (void)ss;
    (void)a0;
    (void)a1;
    (void)a2;

    if (function_hook_state_BrEulerToMatrix34 == HOOK_ENABLED) {
        assert(0 && "BrEulerToMatrix34 not implemented.");
        abort();
    } else {
        return original_BrEulerToMatrix34(mat, euler);
    }
}

function_hook_state_t function_hook_state_BrMatrix34ToEuler = HOOK_UNAVAILABLE;
static br_euler *(__cdecl*original_BrMatrix34ToEuler)(br_euler *, br_matrix34 *) = (br_euler *(__cdecl*)(br_euler *, br_matrix34 *))0x004d4ee0;
CARM95_HOOK_FUNCTION(original_BrMatrix34ToEuler, BrMatrix34ToEuler)
br_euler* __cdecl BrMatrix34ToEuler(br_euler *euler, br_matrix34 *mat) {
    br_uint_8 o;
    int a0;
    int a1;
    int a2;
    br_scalar __block0__sy;
    br_scalar __block1__cy;
    br_angle __block2__t;
    LOG_TRACE("(%p, %p)", euler, mat);

    (void)euler;
    (void)mat;
    (void)o;
    (void)a0;
    (void)a1;
    (void)a2;
    (void)__block0__sy;
    (void)__block1__cy;
    (void)__block2__t;

    if (function_hook_state_BrMatrix34ToEuler == HOOK_ENABLED) {
        assert(0 && "BrMatrix34ToEuler not implemented.");
        abort();
    } else {
        return original_BrMatrix34ToEuler(euler, mat);
    }
}

function_hook_state_t function_hook_state_BrEulerToMatrix4 = HOOK_UNAVAILABLE;
static br_matrix4 *(__cdecl*original_BrEulerToMatrix4)(br_matrix4 *, br_euler *) = (br_matrix4 *(__cdecl*)(br_matrix4 *, br_euler *))0x004d5150;
CARM95_HOOK_FUNCTION(original_BrEulerToMatrix4, BrEulerToMatrix4)
br_matrix4* __cdecl BrEulerToMatrix4(br_matrix4 *mat, br_euler *euler) {
    br_matrix34 tmp;
    LOG_TRACE("(%p, %p)", mat, euler);

    (void)mat;
    (void)euler;
    (void)tmp;

    if (function_hook_state_BrEulerToMatrix4 == HOOK_ENABLED) {
        assert(0 && "BrEulerToMatrix4 not implemented.");
        abort();
    } else {
        return original_BrEulerToMatrix4(mat, euler);
    }
}

function_hook_state_t function_hook_state_BrMatrix4ToEuler = HOOK_UNAVAILABLE;
static br_euler *(__cdecl*original_BrMatrix4ToEuler)(br_euler *, br_matrix4 *) = (br_euler *(__cdecl*)(br_euler *, br_matrix4 *))0x004d5180;
CARM95_HOOK_FUNCTION(original_BrMatrix4ToEuler, BrMatrix4ToEuler)
br_euler* __cdecl BrMatrix4ToEuler(br_euler *dest, br_matrix4 *mat) {
    br_matrix34 tmp;
    LOG_TRACE("(%p, %p)", dest, mat);

    (void)dest;
    (void)mat;
    (void)tmp;

    if (function_hook_state_BrMatrix4ToEuler == HOOK_ENABLED) {
        assert(0 && "BrMatrix4ToEuler not implemented.");
        abort();
    } else {
        return original_BrMatrix4ToEuler(dest, mat);
    }
}

function_hook_state_t function_hook_state_BrEulerToQuat = HOOK_UNAVAILABLE;
static br_quat *(__cdecl*original_BrEulerToQuat)(br_quat *, br_euler *) = (br_quat *(__cdecl*)(br_quat *, br_euler *))0x004d51b0;
CARM95_HOOK_FUNCTION(original_BrEulerToQuat, BrEulerToQuat)
br_quat* __cdecl BrEulerToQuat(br_quat *q, br_euler *euler) {
    br_uint_8 o;
    br_angle ti;
    br_angle tj;
    br_angle th;
    br_scalar ci;
    br_scalar cj;
    br_scalar ch;
    br_scalar si;
    br_scalar sj;
    br_scalar sh;
    br_scalar cc;
    br_scalar cs;
    br_scalar sc;
    br_scalar ss;
    int a0;
    int a1;
    int a2;
    LOG_TRACE("(%p, %p)", q, euler);

    (void)q;
    (void)euler;
    (void)o;
    (void)ti;
    (void)tj;
    (void)th;
    (void)ci;
    (void)cj;
    (void)ch;
    (void)si;
    (void)sj;
    (void)sh;
    (void)cc;
    (void)cs;
    (void)sc;
    (void)ss;
    (void)a0;
    (void)a1;
    (void)a2;

    if (function_hook_state_BrEulerToQuat == HOOK_ENABLED) {
        assert(0 && "BrEulerToQuat not implemented.");
        abort();
    } else {
        return original_BrEulerToQuat(q, euler);
    }
}

function_hook_state_t function_hook_state_BrQuatToEuler = HOOK_UNAVAILABLE;
static br_euler *(__cdecl*original_BrQuatToEuler)(br_euler *, br_quat *) = (br_euler *(__cdecl*)(br_euler *, br_quat *))0x004d5370;
CARM95_HOOK_FUNCTION(original_BrQuatToEuler, BrQuatToEuler)
br_euler* __cdecl BrQuatToEuler(br_euler *euler, br_quat *q) {
    br_matrix34 mat;
    LOG_TRACE("(%p, %p)", euler, q);

    (void)euler;
    (void)q;
    (void)mat;

    if (function_hook_state_BrQuatToEuler == HOOK_ENABLED) {
        assert(0 && "BrQuatToEuler not implemented.");
        abort();
    } else {
        return original_BrQuatToEuler(euler, q);
    }
}

