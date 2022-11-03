#include "matrix23.h"

#include "harness/trace.h"

#include "carm95_hooks.h"

#include "carm95_webserver.h"

#include <assert.h>
 // Suffix added to avoid duplicate symbol
#if 0
br_matrix23 * hookvar_mattmp1__matrix23 ;
#endif
 // Suffix added to avoid duplicate symbol
#if 0
br_matrix23 * hookvar_mattmp2__matrix23 ;
#endif

function_hook_state_t function_hook_state_BrMatrix23Copy = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(BrMatrix23Copy, function_hook_state_BrMatrix23Copy)
static void(__cdecl*original_BrMatrix23Copy)(br_matrix23 *, br_matrix23 *) = (void(__cdecl*)(br_matrix23 *, br_matrix23 *))0x004d3190;
CARM95_HOOK_FUNCTION(original_BrMatrix23Copy, BrMatrix23Copy)
void __cdecl BrMatrix23Copy(br_matrix23 *A, br_matrix23 *B) {
    LOG_TRACE("(%p, %p)", A, B);

    (void)A;
    (void)B;

    if (function_hook_state_BrMatrix23Copy == HOOK_ENABLED) {
        assert(0 && "BrMatrix23Copy not implemented.");
        abort();
    } else {
        original_BrMatrix23Copy(A, B);
    }
}

function_hook_state_t function_hook_state_BrMatrix23Mul = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(BrMatrix23Mul, function_hook_state_BrMatrix23Mul)
static void(__cdecl*original_BrMatrix23Mul)(br_matrix23 *, br_matrix23 *, br_matrix23 *) = (void(__cdecl*)(br_matrix23 *, br_matrix23 *, br_matrix23 *))0x004d31c0;
CARM95_HOOK_FUNCTION(original_BrMatrix23Mul, BrMatrix23Mul)
void __cdecl BrMatrix23Mul(br_matrix23 *A, br_matrix23 *B, br_matrix23 *C) {
    LOG_TRACE("(%p, %p, %p)", A, B, C);

    (void)A;
    (void)B;
    (void)C;

    if (function_hook_state_BrMatrix23Mul == HOOK_ENABLED) {
        assert(0 && "BrMatrix23Mul not implemented.");
        abort();
    } else {
        original_BrMatrix23Mul(A, B, C);
    }
}

function_hook_state_t function_hook_state_BrMatrix23Identity = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(BrMatrix23Identity, function_hook_state_BrMatrix23Identity)
static void(__cdecl*original_BrMatrix23Identity)(br_matrix23 *) = (void(__cdecl*)(br_matrix23 *))0x004d3240;
CARM95_HOOK_FUNCTION(original_BrMatrix23Identity, BrMatrix23Identity)
void __cdecl BrMatrix23Identity(br_matrix23 *mat) {
    LOG_TRACE("(%p)", mat);

    (void)mat;

    if (function_hook_state_BrMatrix23Identity == HOOK_ENABLED) {
        assert(0 && "BrMatrix23Identity not implemented.");
        abort();
    } else {
        original_BrMatrix23Identity(mat);
    }
}

function_hook_state_t function_hook_state_BrMatrix23Rotate = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(BrMatrix23Rotate, function_hook_state_BrMatrix23Rotate)
static void(__cdecl*original_BrMatrix23Rotate)(br_matrix23 *, br_angle) = (void(__cdecl*)(br_matrix23 *, br_angle))0x004d3260;
CARM95_HOOK_FUNCTION(original_BrMatrix23Rotate, BrMatrix23Rotate)
void __cdecl BrMatrix23Rotate(br_matrix23 *mat, br_angle rz) {
    br_scalar s;
    br_scalar c;
    LOG_TRACE("(%p, %u)", mat, rz);

    (void)mat;
    (void)rz;
    (void)s;
    (void)c;

    if (function_hook_state_BrMatrix23Rotate == HOOK_ENABLED) {
        assert(0 && "BrMatrix23Rotate not implemented.");
        abort();
    } else {
        original_BrMatrix23Rotate(mat, rz);
    }
}

function_hook_state_t function_hook_state_BrMatrix23Translate = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(BrMatrix23Translate, function_hook_state_BrMatrix23Translate)
static void(__cdecl*original_BrMatrix23Translate)(br_matrix23 *, br_scalar, br_scalar) = (void(__cdecl*)(br_matrix23 *, br_scalar, br_scalar))0x004d32a5;
CARM95_HOOK_FUNCTION(original_BrMatrix23Translate, BrMatrix23Translate)
void __cdecl BrMatrix23Translate(br_matrix23 *mat, br_scalar dx, br_scalar dy) {
    LOG_TRACE("(%p, %f, %f)", mat, dx, dy);

    (void)mat;
    (void)dx;
    (void)dy;

    if (function_hook_state_BrMatrix23Translate == HOOK_ENABLED) {
        assert(0 && "BrMatrix23Translate not implemented.");
        abort();
    } else {
        original_BrMatrix23Translate(mat, dx, dy);
    }
}

function_hook_state_t function_hook_state_BrMatrix23Scale = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(BrMatrix23Scale, function_hook_state_BrMatrix23Scale)
static void(__cdecl*original_BrMatrix23Scale)(br_matrix23 *, br_scalar, br_scalar) = (void(__cdecl*)(br_matrix23 *, br_scalar, br_scalar))0x004d32da;
CARM95_HOOK_FUNCTION(original_BrMatrix23Scale, BrMatrix23Scale)
void __cdecl BrMatrix23Scale(br_matrix23 *mat, br_scalar sx, br_scalar sy) {
    LOG_TRACE("(%p, %f, %f)", mat, sx, sy);

    (void)mat;
    (void)sx;
    (void)sy;

    if (function_hook_state_BrMatrix23Scale == HOOK_ENABLED) {
        assert(0 && "BrMatrix23Scale not implemented.");
        abort();
    } else {
        original_BrMatrix23Scale(mat, sx, sy);
    }
}

function_hook_state_t function_hook_state_BrMatrix23ShearX = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(BrMatrix23ShearX, function_hook_state_BrMatrix23ShearX)
static void(__cdecl*original_BrMatrix23ShearX)(br_matrix23 *, br_scalar) = (void(__cdecl*)(br_matrix23 *, br_scalar))0x004d3300;
CARM95_HOOK_FUNCTION(original_BrMatrix23ShearX, BrMatrix23ShearX)
void __cdecl BrMatrix23ShearX(br_matrix23 *mat, br_scalar sy) {
    LOG_TRACE("(%p, %f)", mat, sy);

    (void)mat;
    (void)sy;

    if (function_hook_state_BrMatrix23ShearX == HOOK_ENABLED) {
        assert(0 && "BrMatrix23ShearX not implemented.");
        abort();
    } else {
        original_BrMatrix23ShearX(mat, sy);
    }
}

function_hook_state_t function_hook_state_BrMatrix23ShearY = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(BrMatrix23ShearY, function_hook_state_BrMatrix23ShearY)
static void(__cdecl*original_BrMatrix23ShearY)(br_matrix23 *, br_scalar) = (void(__cdecl*)(br_matrix23 *, br_scalar))0x004d3324;
CARM95_HOOK_FUNCTION(original_BrMatrix23ShearY, BrMatrix23ShearY)
void __cdecl BrMatrix23ShearY(br_matrix23 *mat, br_scalar sx) {
    LOG_TRACE("(%p, %f)", mat, sx);

    (void)mat;
    (void)sx;

    if (function_hook_state_BrMatrix23ShearY == HOOK_ENABLED) {
        assert(0 && "BrMatrix23ShearY not implemented.");
        abort();
    } else {
        original_BrMatrix23ShearY(mat, sx);
    }
}

function_hook_state_t function_hook_state_BrMatrix23Inverse = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(BrMatrix23Inverse, function_hook_state_BrMatrix23Inverse)
static br_scalar(__cdecl*original_BrMatrix23Inverse)(br_matrix23 *, br_matrix23 *) = (br_scalar(__cdecl*)(br_matrix23 *, br_matrix23 *))0x004d3355;
CARM95_HOOK_FUNCTION(original_BrMatrix23Inverse, BrMatrix23Inverse)
br_scalar __cdecl BrMatrix23Inverse(br_matrix23 *B, br_matrix23 *A) {
    br_scalar det;
    br_scalar idet;
    br_scalar pos;
    br_scalar neg;
    LOG_TRACE("(%p, %p)", B, A);

    (void)B;
    (void)A;
    (void)det;
    (void)idet;
    (void)pos;
    (void)neg;

    if (function_hook_state_BrMatrix23Inverse == HOOK_ENABLED) {
        assert(0 && "BrMatrix23Inverse not implemented.");
        abort();
    } else {
        return original_BrMatrix23Inverse(B, A);
    }
}

function_hook_state_t function_hook_state_BrMatrix23LPInverse = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(BrMatrix23LPInverse, function_hook_state_BrMatrix23LPInverse)
static void(__cdecl*original_BrMatrix23LPInverse)(br_matrix23 *, br_matrix23 *) = (void(__cdecl*)(br_matrix23 *, br_matrix23 *))0x004d3477;
CARM95_HOOK_FUNCTION(original_BrMatrix23LPInverse, BrMatrix23LPInverse)
void __cdecl BrMatrix23LPInverse(br_matrix23 *B, br_matrix23 *A) {
    LOG_TRACE("(%p, %p)", B, A);

    (void)B;
    (void)A;

    if (function_hook_state_BrMatrix23LPInverse == HOOK_ENABLED) {
        assert(0 && "BrMatrix23LPInverse not implemented.");
        abort();
    } else {
        original_BrMatrix23LPInverse(B, A);
    }
}

function_hook_state_t function_hook_state_BrMatrix23LPNormalise = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(BrMatrix23LPNormalise, function_hook_state_BrMatrix23LPNormalise)
static void(__cdecl*original_BrMatrix23LPNormalise)(br_matrix23 *, br_matrix23 *) = (void(__cdecl*)(br_matrix23 *, br_matrix23 *))0x004d34c6;
CARM95_HOOK_FUNCTION(original_BrMatrix23LPNormalise, BrMatrix23LPNormalise)
void __cdecl BrMatrix23LPNormalise(br_matrix23 *A, br_matrix23 *B) {
    br_scalar __block0___scale;
    LOG_TRACE("(%p, %p)", A, B);

    (void)A;
    (void)B;
    (void)__block0___scale;

    if (function_hook_state_BrMatrix23LPNormalise == HOOK_ENABLED) {
        assert(0 && "BrMatrix23LPNormalise not implemented.");
        abort();
    } else {
        original_BrMatrix23LPNormalise(A, B);
    }
}

function_hook_state_t function_hook_state_BrMatrix23ApplyP = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(BrMatrix23ApplyP, function_hook_state_BrMatrix23ApplyP)
static void(__cdecl*original_BrMatrix23ApplyP)(br_vector2 *, br_vector2 *, br_matrix23 *) = (void(__cdecl*)(br_vector2 *, br_vector2 *, br_matrix23 *))0x004d3543;
CARM95_HOOK_FUNCTION(original_BrMatrix23ApplyP, BrMatrix23ApplyP)
void __cdecl BrMatrix23ApplyP(br_vector2 *A, br_vector2 *B, br_matrix23 *C) {
    LOG_TRACE("(%p, %p, %p)", A, B, C);

    (void)A;
    (void)B;
    (void)C;

    if (function_hook_state_BrMatrix23ApplyP == HOOK_ENABLED) {
        assert(0 && "BrMatrix23ApplyP not implemented.");
        abort();
    } else {
        original_BrMatrix23ApplyP(A, B, C);
    }
}

function_hook_state_t function_hook_state_BrMatrix23ApplyV = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(BrMatrix23ApplyV, function_hook_state_BrMatrix23ApplyV)
static void(__cdecl*original_BrMatrix23ApplyV)(br_vector2 *, br_vector2 *, br_matrix23 *) = (void(__cdecl*)(br_vector2 *, br_vector2 *, br_matrix23 *))0x004d3581;
CARM95_HOOK_FUNCTION(original_BrMatrix23ApplyV, BrMatrix23ApplyV)
void __cdecl BrMatrix23ApplyV(br_vector2 *A, br_vector2 *B, br_matrix23 *C) {
    LOG_TRACE("(%p, %p, %p)", A, B, C);

    (void)A;
    (void)B;
    (void)C;

    if (function_hook_state_BrMatrix23ApplyV == HOOK_ENABLED) {
        assert(0 && "BrMatrix23ApplyV not implemented.");
        abort();
    } else {
        original_BrMatrix23ApplyV(A, B, C);
    }
}

function_hook_state_t function_hook_state_BrMatrix23TApplyP = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(BrMatrix23TApplyP, function_hook_state_BrMatrix23TApplyP)
static void(__cdecl*original_BrMatrix23TApplyP)(br_vector2 *, br_vector2 *, br_matrix23 *) = (void(__cdecl*)(br_vector2 *, br_vector2 *, br_matrix23 *))0x004d35bb;
CARM95_HOOK_FUNCTION(original_BrMatrix23TApplyP, BrMatrix23TApplyP)
void __cdecl BrMatrix23TApplyP(br_vector2 *A, br_vector2 *B, br_matrix23 *C) {
    LOG_TRACE("(%p, %p, %p)", A, B, C);

    (void)A;
    (void)B;
    (void)C;

    if (function_hook_state_BrMatrix23TApplyP == HOOK_ENABLED) {
        assert(0 && "BrMatrix23TApplyP not implemented.");
        abort();
    } else {
        original_BrMatrix23TApplyP(A, B, C);
    }
}

function_hook_state_t function_hook_state_BrMatrix23TApplyV = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(BrMatrix23TApplyV, function_hook_state_BrMatrix23TApplyV)
static void(__cdecl*original_BrMatrix23TApplyV)(br_vector2 *, br_vector2 *, br_matrix23 *) = (void(__cdecl*)(br_vector2 *, br_vector2 *, br_matrix23 *))0x004d35eb;
CARM95_HOOK_FUNCTION(original_BrMatrix23TApplyV, BrMatrix23TApplyV)
void __cdecl BrMatrix23TApplyV(br_vector2 *A, br_vector2 *B, br_matrix23 *C) {
    LOG_TRACE("(%p, %p, %p)", A, B, C);

    (void)A;
    (void)B;
    (void)C;

    if (function_hook_state_BrMatrix23TApplyV == HOOK_ENABLED) {
        assert(0 && "BrMatrix23TApplyV not implemented.");
        abort();
    } else {
        original_BrMatrix23TApplyV(A, B, C);
    }
}

function_hook_state_t function_hook_state_BrMatrix23Pre = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(BrMatrix23Pre, function_hook_state_BrMatrix23Pre)
static void(__cdecl*original_BrMatrix23Pre)(br_matrix23 *, br_matrix23 *) = (void(__cdecl*)(br_matrix23 *, br_matrix23 *))0x004d361b;
CARM95_HOOK_FUNCTION(original_BrMatrix23Pre, BrMatrix23Pre)
void __cdecl BrMatrix23Pre(br_matrix23 *mat, br_matrix23 *A) {
    LOG_TRACE("(%p, %p)", mat, A);

    (void)mat;
    (void)A;

    if (function_hook_state_BrMatrix23Pre == HOOK_ENABLED) {
        assert(0 && "BrMatrix23Pre not implemented.");
        abort();
    } else {
        original_BrMatrix23Pre(mat, A);
    }
}

function_hook_state_t function_hook_state_BrMatrix23Post = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(BrMatrix23Post, function_hook_state_BrMatrix23Post)
static void(__cdecl*original_BrMatrix23Post)(br_matrix23 *, br_matrix23 *) = (void(__cdecl*)(br_matrix23 *, br_matrix23 *))0x004d366d;
CARM95_HOOK_FUNCTION(original_BrMatrix23Post, BrMatrix23Post)
void __cdecl BrMatrix23Post(br_matrix23 *mat, br_matrix23 *A) {
    LOG_TRACE("(%p, %p)", mat, A);

    (void)mat;
    (void)A;

    if (function_hook_state_BrMatrix23Post == HOOK_ENABLED) {
        assert(0 && "BrMatrix23Post not implemented.");
        abort();
    } else {
        original_BrMatrix23Post(mat, A);
    }
}

function_hook_state_t function_hook_state_BrMatrix23PreRotate = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(BrMatrix23PreRotate, function_hook_state_BrMatrix23PreRotate)
static void(__cdecl*original_BrMatrix23PreRotate)(br_matrix23 *, br_angle) = (void(__cdecl*)(br_matrix23 *, br_angle))0x004d36bd;
CARM95_HOOK_FUNCTION(original_BrMatrix23PreRotate, BrMatrix23PreRotate)
void __cdecl BrMatrix23PreRotate(br_matrix23 *mat, br_angle rz) {
    LOG_TRACE("(%p, %u)", mat, rz);

    (void)mat;
    (void)rz;

    if (function_hook_state_BrMatrix23PreRotate == HOOK_ENABLED) {
        assert(0 && "BrMatrix23PreRotate not implemented.");
        abort();
    } else {
        original_BrMatrix23PreRotate(mat, rz);
    }
}

function_hook_state_t function_hook_state_BrMatrix23PostRotate = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(BrMatrix23PostRotate, function_hook_state_BrMatrix23PostRotate)
static void(__cdecl*original_BrMatrix23PostRotate)(br_matrix23 *, br_angle) = (void(__cdecl*)(br_matrix23 *, br_angle))0x004d375e;
CARM95_HOOK_FUNCTION(original_BrMatrix23PostRotate, BrMatrix23PostRotate)
void __cdecl BrMatrix23PostRotate(br_matrix23 *mat, br_angle rz) {
    LOG_TRACE("(%p, %u)", mat, rz);

    (void)mat;
    (void)rz;

    if (function_hook_state_BrMatrix23PostRotate == HOOK_ENABLED) {
        assert(0 && "BrMatrix23PostRotate not implemented.");
        abort();
    } else {
        original_BrMatrix23PostRotate(mat, rz);
    }
}

function_hook_state_t function_hook_state_BrMatrix23PreTranslate = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(BrMatrix23PreTranslate, function_hook_state_BrMatrix23PreTranslate)
static void(__cdecl*original_BrMatrix23PreTranslate)(br_matrix23 *, br_scalar, br_scalar) = (void(__cdecl*)(br_matrix23 *, br_scalar, br_scalar))0x004d37fe;
CARM95_HOOK_FUNCTION(original_BrMatrix23PreTranslate, BrMatrix23PreTranslate)
void __cdecl BrMatrix23PreTranslate(br_matrix23 *mat, br_scalar x, br_scalar y) {
    LOG_TRACE("(%p, %f, %f)", mat, x, y);

    (void)mat;
    (void)x;
    (void)y;

    if (function_hook_state_BrMatrix23PreTranslate == HOOK_ENABLED) {
        assert(0 && "BrMatrix23PreTranslate not implemented.");
        abort();
    } else {
        original_BrMatrix23PreTranslate(mat, x, y);
    }
}

function_hook_state_t function_hook_state_BrMatrix23PostTranslate = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(BrMatrix23PostTranslate, function_hook_state_BrMatrix23PostTranslate)
static void(__cdecl*original_BrMatrix23PostTranslate)(br_matrix23 *, br_scalar, br_scalar) = (void(__cdecl*)(br_matrix23 *, br_scalar, br_scalar))0x004d387d;
CARM95_HOOK_FUNCTION(original_BrMatrix23PostTranslate, BrMatrix23PostTranslate)
void __cdecl BrMatrix23PostTranslate(br_matrix23 *A, br_scalar x, br_scalar y) {
    LOG_TRACE("(%p, %f, %f)", A, x, y);

    (void)A;
    (void)x;
    (void)y;

    if (function_hook_state_BrMatrix23PostTranslate == HOOK_ENABLED) {
        assert(0 && "BrMatrix23PostTranslate not implemented.");
        abort();
    } else {
        original_BrMatrix23PostTranslate(A, x, y);
    }
}

function_hook_state_t function_hook_state_BrMatrix23PreScale = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(BrMatrix23PreScale, function_hook_state_BrMatrix23PreScale)
static void(__cdecl*original_BrMatrix23PreScale)(br_matrix23 *, br_scalar, br_scalar) = (void(__cdecl*)(br_matrix23 *, br_scalar, br_scalar))0x004d389b;
CARM95_HOOK_FUNCTION(original_BrMatrix23PreScale, BrMatrix23PreScale)
void __cdecl BrMatrix23PreScale(br_matrix23 *mat, br_scalar sx, br_scalar sy) {
    LOG_TRACE("(%p, %f, %f)", mat, sx, sy);

    (void)mat;
    (void)sx;
    (void)sy;

    if (function_hook_state_BrMatrix23PreScale == HOOK_ENABLED) {
        assert(0 && "BrMatrix23PreScale not implemented.");
        abort();
    } else {
        original_BrMatrix23PreScale(mat, sx, sy);
    }
}

function_hook_state_t function_hook_state_BrMatrix23PostScale = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(BrMatrix23PostScale, function_hook_state_BrMatrix23PostScale)
static void(__cdecl*original_BrMatrix23PostScale)(br_matrix23 *, br_scalar, br_scalar) = (void(__cdecl*)(br_matrix23 *, br_scalar, br_scalar))0x004d3920;
CARM95_HOOK_FUNCTION(original_BrMatrix23PostScale, BrMatrix23PostScale)
void __cdecl BrMatrix23PostScale(br_matrix23 *mat, br_scalar sx, br_scalar sy) {
    LOG_TRACE("(%p, %f, %f)", mat, sx, sy);

    (void)mat;
    (void)sx;
    (void)sy;

    if (function_hook_state_BrMatrix23PostScale == HOOK_ENABLED) {
        assert(0 && "BrMatrix23PostScale not implemented.");
        abort();
    } else {
        original_BrMatrix23PostScale(mat, sx, sy);
    }
}

function_hook_state_t function_hook_state_BrMatrix23PreShearX = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(BrMatrix23PreShearX, function_hook_state_BrMatrix23PreShearX)
static void(__cdecl*original_BrMatrix23PreShearX)(br_matrix23 *, br_scalar) = (void(__cdecl*)(br_matrix23 *, br_scalar))0x004d3996;
CARM95_HOOK_FUNCTION(original_BrMatrix23PreShearX, BrMatrix23PreShearX)
void __cdecl BrMatrix23PreShearX(br_matrix23 *mat, br_scalar sy) {
    LOG_TRACE("(%p, %f)", mat, sy);

    (void)mat;
    (void)sy;

    if (function_hook_state_BrMatrix23PreShearX == HOOK_ENABLED) {
        assert(0 && "BrMatrix23PreShearX not implemented.");
        abort();
    } else {
        original_BrMatrix23PreShearX(mat, sy);
    }
}

function_hook_state_t function_hook_state_BrMatrix23PostShearX = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(BrMatrix23PostShearX, function_hook_state_BrMatrix23PostShearX)
static void(__cdecl*original_BrMatrix23PostShearX)(br_matrix23 *, br_scalar) = (void(__cdecl*)(br_matrix23 *, br_scalar))0x004d3a18;
CARM95_HOOK_FUNCTION(original_BrMatrix23PostShearX, BrMatrix23PostShearX)
void __cdecl BrMatrix23PostShearX(br_matrix23 *mat, br_scalar sy) {
    LOG_TRACE("(%p, %f)", mat, sy);

    (void)mat;
    (void)sy;

    if (function_hook_state_BrMatrix23PostShearX == HOOK_ENABLED) {
        assert(0 && "BrMatrix23PostShearX not implemented.");
        abort();
    } else {
        original_BrMatrix23PostShearX(mat, sy);
    }
}

function_hook_state_t function_hook_state_BrMatrix23PreShearY = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(BrMatrix23PreShearY, function_hook_state_BrMatrix23PreShearY)
static void(__cdecl*original_BrMatrix23PreShearY)(br_matrix23 *, br_scalar) = (void(__cdecl*)(br_matrix23 *, br_scalar))0x004d3a98;
CARM95_HOOK_FUNCTION(original_BrMatrix23PreShearY, BrMatrix23PreShearY)
void __cdecl BrMatrix23PreShearY(br_matrix23 *mat, br_scalar sx) {
    LOG_TRACE("(%p, %f)", mat, sx);

    (void)mat;
    (void)sx;

    if (function_hook_state_BrMatrix23PreShearY == HOOK_ENABLED) {
        assert(0 && "BrMatrix23PreShearY not implemented.");
        abort();
    } else {
        original_BrMatrix23PreShearY(mat, sx);
    }
}

function_hook_state_t function_hook_state_BrMatrix23PostShearY = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(BrMatrix23PostShearY, function_hook_state_BrMatrix23PostShearY)
static void(__cdecl*original_BrMatrix23PostShearY)(br_matrix23 *, br_scalar) = (void(__cdecl*)(br_matrix23 *, br_scalar))0x004d3b1a;
CARM95_HOOK_FUNCTION(original_BrMatrix23PostShearY, BrMatrix23PostShearY)
void __cdecl BrMatrix23PostShearY(br_matrix23 *mat, br_scalar sx) {
    LOG_TRACE("(%p, %f)", mat, sx);

    (void)mat;
    (void)sx;

    if (function_hook_state_BrMatrix23PostShearY == HOOK_ENABLED) {
        assert(0 && "BrMatrix23PostShearY not implemented.");
        abort();
    } else {
        original_BrMatrix23PostShearY(mat, sx);
    }
}

