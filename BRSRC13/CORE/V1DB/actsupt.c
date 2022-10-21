#include "actsupt.h"

#include "harness/trace.h"

#include "carm95_hooks.h"

#include "carm95_webserver.h"

#include <assert.h>

function_hook_state_t function_hook_state_BrActorEnum = HOOK_UNAVAILABLE;
static br_uint_32(__cdecl*original_BrActorEnum)(br_actor *, br_actor_enum_cbfn *, void *) = (br_uint_32(__cdecl*)(br_actor *, br_actor_enum_cbfn *, void *))0x004d6710;
CARM95_HOOK_FUNCTION(original_BrActorEnum, BrActorEnum)
br_uint_32 __cdecl BrActorEnum(br_actor *parent, br_actor_enum_cbfn *callback, void *arg) {
    br_actor *a;
    br_actor *next;
    br_uint_32 r;
    LOG_TRACE("(%p, %p, %p)", parent, callback, arg);

    (void)parent;
    (void)callback;
    (void)arg;
    (void)a;
    (void)next;
    (void)r;

    if (function_hook_state_BrActorEnum == HOOK_ENABLED) {
        assert(0 && "BrActorEnum not implemented.");
        abort();
    } else {
        return original_BrActorEnum(parent, callback, arg);
    }
}

function_hook_state_t function_hook_state_BrActorSearchMany = HOOK_UNAVAILABLE;
static br_uint_32(__cdecl*original_BrActorSearchMany)(br_actor *, char *, br_actor **, int) = (br_uint_32(__cdecl*)(br_actor *, char *, br_actor **, int))0x004d6740;
CARM95_HOOK_FUNCTION(original_BrActorSearchMany, BrActorSearchMany)
br_uint_32 __cdecl BrActorSearchMany(br_actor *root, char *pattern, br_actor **actors, int max) {
    br_actor *a;
    char *sub;
    int n;
    int remaining;
    LOG_TRACE("(%p, \"%s\", %p, %d)", root, pattern, actors, max);

    (void)root;
    (void)pattern;
    (void)actors;
    (void)max;
    (void)a;
    (void)sub;
    (void)n;
    (void)remaining;

    if (function_hook_state_BrActorSearchMany == HOOK_ENABLED) {
        assert(0 && "BrActorSearchMany not implemented.");
        abort();
    } else {
        return original_BrActorSearchMany(root, pattern, actors, max);
    }
}

function_hook_state_t function_hook_state_BrActorSearch = HOOK_UNAVAILABLE;
static br_actor *(__cdecl*original_BrActorSearch)(br_actor *, char *) = (br_actor *(__cdecl*)(br_actor *, char *))0x004d67ef;
CARM95_HOOK_FUNCTION(original_BrActorSearch, BrActorSearch)
br_actor* __cdecl BrActorSearch(br_actor *root, char *pattern) {
    br_actor *a;
    LOG_TRACE("(%p, \"%s\")", root, pattern);

    (void)root;
    (void)pattern;
    (void)a;

    if (function_hook_state_BrActorSearch == HOOK_ENABLED) {
        assert(0 && "BrActorSearch not implemented.");
        abort();
    } else {
        return original_BrActorSearch(root, pattern);
    }
}

function_hook_state_t function_hook_state_RenumberActor = HOOK_UNAVAILABLE;
static void(__stdcall*original_RenumberActor)(br_actor *, int) = (void(__stdcall*)(br_actor *, int))0x004d6880;
CARM95_HOOK_FUNCTION(original_RenumberActor, RenumberActor)
void __stdcall RenumberActor(br_actor *a, int d) {
    br_actor *ac;
    LOG_TRACE("(%p, %d)", a, d);

    (void)a;
    (void)d;
    (void)ac;

    if (function_hook_state_RenumberActor == HOOK_ENABLED) {
        assert(0 && "RenumberActor not implemented.");
        abort();
    } else {
        original_RenumberActor(a, d);
    }
}

function_hook_state_t function_hook_state_BrActorAdd = HOOK_UNAVAILABLE;
static br_actor *(__cdecl*original_BrActorAdd)(br_actor *, br_actor *) = (br_actor *(__cdecl*)(br_actor *, br_actor *))0x004d6820;
CARM95_HOOK_FUNCTION(original_BrActorAdd, BrActorAdd)
br_actor* __cdecl BrActorAdd(br_actor *parent, br_actor *a) {
    br_actor *ac;
    LOG_TRACE("(%p, %p)", parent, a);

    (void)parent;
    (void)a;
    (void)ac;

    if (function_hook_state_BrActorAdd == HOOK_ENABLED) {
        assert(0 && "BrActorAdd not implemented.");
        abort();
    } else {
        return original_BrActorAdd(parent, a);
    }
}

function_hook_state_t function_hook_state_BrActorRemove = HOOK_UNAVAILABLE;
static br_actor *(__cdecl*original_BrActorRemove)(br_actor *) = (br_actor *(__cdecl*)(br_actor *))0x004d68b0;
CARM95_HOOK_FUNCTION(original_BrActorRemove, BrActorRemove)
br_actor* __cdecl BrActorRemove(br_actor *a) {
    br_actor *ac;
    LOG_TRACE("(%p)", a);

    (void)a;
    (void)ac;

    if (function_hook_state_BrActorRemove == HOOK_ENABLED) {
        assert(0 && "BrActorRemove not implemented.");
        abort();
    } else {
        return original_BrActorRemove(a);
    }
}

function_hook_state_t function_hook_state_BrActorRelink = HOOK_UNAVAILABLE;
static void(__cdecl*original_BrActorRelink)(br_actor *, br_actor *) = (void(__cdecl*)(br_actor *, br_actor *))0x00434aa0;
CARM95_HOOK_FUNCTION(original_BrActorRelink, BrActorRelink)
void __cdecl BrActorRelink(br_actor *parent, br_actor *a) {
    br_matrix34 mat;
    LOG_TRACE("(%p, %p)", parent, a);

    (void)parent;
    (void)a;
    (void)mat;

    if (function_hook_state_BrActorRelink == HOOK_ENABLED) {
        assert(0 && "BrActorRelink not implemented.");
        abort();
    } else {
        original_BrActorRelink(parent, a);
    }
}

function_hook_state_t function_hook_state_BrActorAllocate = HOOK_UNAVAILABLE;
static br_actor *(__cdecl*original_BrActorAllocate)(br_uint_8, void *) = (br_actor *(__cdecl*)(br_uint_8, void *))0x004d69d0;
CARM95_HOOK_FUNCTION(original_BrActorAllocate, BrActorAllocate)
br_actor* __cdecl BrActorAllocate(br_uint_8 type, void *type_data) {
    br_actor *a;
    br_light *light;
    br_camera *camera;
    br_bounds *bounds;
    br_vector4 *clip_plane;
    LOG_TRACE("(%u, %p)", type, type_data);

    (void)type;
    (void)type_data;
    (void)a;
    (void)light;
    (void)camera;
    (void)bounds;
    (void)clip_plane;

    if (function_hook_state_BrActorAllocate == HOOK_ENABLED) {
        assert(0 && "BrActorAllocate not implemented.");
        abort();
    } else {
        return original_BrActorAllocate(type, type_data);
    }
}

function_hook_state_t function_hook_state_InternalActorFree = HOOK_UNAVAILABLE;
static void(__stdcall*original_InternalActorFree)(br_actor *) = (void(__stdcall*)(br_actor *))0x004d6b30;
CARM95_HOOK_FUNCTION(original_InternalActorFree, InternalActorFree)
void __stdcall InternalActorFree(br_actor *a) {
    LOG_TRACE("(%p)", a);

    (void)a;

    if (function_hook_state_InternalActorFree == HOOK_ENABLED) {
        assert(0 && "InternalActorFree not implemented.");
        abort();
    } else {
        original_InternalActorFree(a);
    }
}

function_hook_state_t function_hook_state_BrActorFree = HOOK_UNAVAILABLE;
static void(__cdecl*original_BrActorFree)(br_actor *) = (void(__cdecl*)(br_actor *))0x004d6af0;
CARM95_HOOK_FUNCTION(original_BrActorFree, BrActorFree)
void __cdecl BrActorFree(br_actor *a) {
    LOG_TRACE("(%p)", a);

    (void)a;

    if (function_hook_state_BrActorFree == HOOK_ENABLED) {
        assert(0 && "BrActorFree not implemented.");
        abort();
    } else {
        original_BrActorFree(a);
    }
}

function_hook_state_t function_hook_state_ActorToRoot = HOOK_UNAVAILABLE;
static br_boolean(__stdcall*original_ActorToRoot)(br_actor *, br_actor *, br_matrix34 *) = (br_boolean(__stdcall*)(br_actor *, br_actor *, br_matrix34 *))0x004d6b68;
CARM95_HOOK_FUNCTION(original_ActorToRoot, ActorToRoot)
br_boolean __stdcall ActorToRoot(br_actor *a, br_actor *world, br_matrix34 *m) {
    LOG_TRACE("(%p, %p, %p)", a, world, m);

    (void)a;
    (void)world;
    (void)m;

    if (function_hook_state_ActorToRoot == HOOK_ENABLED) {
        assert(0 && "ActorToRoot not implemented.");
        abort();
    } else {
        return original_ActorToRoot(a, world, m);
    }
}

function_hook_state_t function_hook_state_ActorToRootTyped = HOOK_UNAVAILABLE;
static br_boolean(__stdcall*original_ActorToRootTyped)(br_actor *, br_actor *, br_matrix34 *, br_int_32 *) = (br_boolean(__stdcall*)(br_actor *, br_actor *, br_matrix34 *, br_int_32 *))0x004d6be0;
CARM95_HOOK_FUNCTION(original_ActorToRootTyped, ActorToRootTyped)
br_boolean __stdcall ActorToRootTyped(br_actor *a, br_actor *world, br_matrix34 *m, br_int_32 *type) {
    br_int_32 t;
    LOG_TRACE("(%p, %p, %p, %p)", a, world, m, type);

    (void)a;
    (void)world;
    (void)m;
    (void)type;
    (void)t;

    if (function_hook_state_ActorToRootTyped == HOOK_ENABLED) {
        assert(0 && "ActorToRootTyped not implemented.");
        abort();
    } else {
        return original_ActorToRootTyped(a, world, m, type);
    }
}

function_hook_state_t function_hook_state_Matrix4PerspectiveNew = HOOK_UNAVAILABLE;
static void(__stdcall*original_Matrix4PerspectiveNew)(br_matrix4 *, br_angle, br_scalar, br_scalar, br_scalar, br_scalar, br_scalar) = (void(__stdcall*)(br_matrix4 *, br_angle, br_scalar, br_scalar, br_scalar, br_scalar, br_scalar))0x004d6c80;
CARM95_HOOK_FUNCTION(original_Matrix4PerspectiveNew, Matrix4PerspectiveNew)
void __stdcall Matrix4PerspectiveNew(br_matrix4 *mat, br_angle field_of_view, br_scalar aspect, br_scalar hither, br_scalar yon, br_scalar origin_x, br_scalar origin_y) {
    br_scalar scale;
    LOG_TRACE("(%p, %u, %f, %f, %f, %f, %f)", mat, field_of_view, aspect, hither, yon, origin_x, origin_y);

    (void)mat;
    (void)field_of_view;
    (void)aspect;
    (void)hither;
    (void)yon;
    (void)origin_x;
    (void)origin_y;
    (void)scale;

    if (function_hook_state_Matrix4PerspectiveNew == HOOK_ENABLED) {
        assert(0 && "Matrix4PerspectiveNew not implemented.");
        abort();
    } else {
        original_Matrix4PerspectiveNew(mat, field_of_view, aspect, hither, yon, origin_x, origin_y);
    }
}

function_hook_state_t function_hook_state_CameraToScreenMatrix4 = HOOK_UNAVAILABLE;
static br_token(__stdcall*original_CameraToScreenMatrix4)(br_matrix4 *, br_actor *) = (br_token(__stdcall*)(br_matrix4 *, br_actor *))0x004d6d30;
CARM95_HOOK_FUNCTION(original_CameraToScreenMatrix4, CameraToScreenMatrix4)
br_token __stdcall CameraToScreenMatrix4(br_matrix4 *mat, br_actor *camera) {
    br_camera *camera_type;
    br_matrix34 mat34;
    LOG_TRACE("(%p, %p)", mat, camera);

    (void)mat;
    (void)camera;
    (void)camera_type;
    (void)mat34;

    if (function_hook_state_CameraToScreenMatrix4 == HOOK_ENABLED) {
        assert(0 && "CameraToScreenMatrix4 not implemented.");
        abort();
    } else {
        return original_CameraToScreenMatrix4(mat, camera);
    }
}

function_hook_state_t function_hook_state_BrActorToActorMatrix34 = HOOK_UNAVAILABLE;
static br_uint_16(__cdecl*original_BrActorToActorMatrix34)(br_matrix34 *, br_actor *, br_actor *) = (br_uint_16(__cdecl*)(br_matrix34 *, br_actor *, br_actor *))0x004345e0;
CARM95_HOOK_FUNCTION(original_BrActorToActorMatrix34, BrActorToActorMatrix34)
br_uint_16 __cdecl BrActorToActorMatrix34(br_matrix34 *m, br_actor *a, br_actor *b) {
    br_matrix34 mata;
    br_matrix34 matb;
    br_matrix34 matc;
    br_uint_8 at;
    br_uint_8 bt;
    LOG_TRACE("(%p, %p, %p)", m, a, b);

    (void)m;
    (void)a;
    (void)b;
    (void)mata;
    (void)matb;
    (void)matc;
    (void)at;
    (void)bt;

    if (function_hook_state_BrActorToActorMatrix34 == HOOK_ENABLED) {
        assert(0 && "BrActorToActorMatrix34 not implemented.");
        abort();
    } else {
        return original_BrActorToActorMatrix34(m, a, b);
    }
}

function_hook_state_t function_hook_state_BrActorToScreenMatrix4 = HOOK_UNAVAILABLE;
static void(__cdecl*original_BrActorToScreenMatrix4)(br_matrix4 *, br_actor *, br_actor *) = (void(__cdecl*)(br_matrix4 *, br_actor *, br_actor *))0x004d7273;
CARM95_HOOK_FUNCTION(original_BrActorToScreenMatrix4, BrActorToScreenMatrix4)
void __cdecl BrActorToScreenMatrix4(br_matrix4 *m, br_actor *a, br_actor *camera) {
    br_matrix34 a2c;
    LOG_TRACE("(%p, %p, %p)", m, a, camera);

    (void)m;
    (void)a;
    (void)camera;
    (void)a2c;

    if (function_hook_state_BrActorToScreenMatrix4 == HOOK_ENABLED) {
        assert(0 && "BrActorToScreenMatrix4 not implemented.");
        abort();
    } else {
        original_BrActorToScreenMatrix4(m, a, camera);
    }
}

function_hook_state_t function_hook_state_BrMatrix34ApplyBounds = HOOK_UNAVAILABLE;
void BrMatrix34ApplyBounds(br_bounds *d, br_bounds *s, br_matrix34 *m) {
    int i;
    int j;
    br_scalar a;
    br_scalar b;
    LOG_TRACE("(%p, %p, %p)", d, s, m);

    (void)d;
    (void)s;
    (void)m;
    (void)i;
    (void)j;
    (void)a;
    (void)b;

    if (function_hook_state_BrMatrix34ApplyBounds == HOOK_ENABLED) {
        assert(0 && "BrMatrix34ApplyBounds not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}

function_hook_state_t function_hook_state_ActorToBounds = HOOK_UNAVAILABLE;
static void(__stdcall*original_ActorToBounds)(br_bounds *, br_actor *, br_model *) = (void(__stdcall*)(br_bounds *, br_actor *, br_model *))0x004d7370;
CARM95_HOOK_FUNCTION(original_ActorToBounds, ActorToBounds)
void __stdcall ActorToBounds(br_bounds *dest, br_actor *ap, br_model *model) {
    br_actor *a;
    br_bounds new;
    br_matrix34 m2v;
    int i;
    LOG_TRACE("(%p, %p, %p)", dest, ap, model);

    (void)dest;
    (void)ap;
    (void)model;
    (void)a;
    (void)new;
    (void)m2v;
    (void)i;

    if (function_hook_state_ActorToBounds == HOOK_ENABLED) {
        assert(0 && "ActorToBounds not implemented.");
        abort();
    } else {
        original_ActorToBounds(dest, ap, model);
    }
}

function_hook_state_t function_hook_state_BrActorToBounds = HOOK_UNAVAILABLE;
static br_bounds *(__cdecl*original_BrActorToBounds)(br_bounds *, br_actor *) = (br_bounds *(__cdecl*)(br_bounds *, br_actor *))0x004d72c0;
CARM95_HOOK_FUNCTION(original_BrActorToBounds, BrActorToBounds)
br_bounds* __cdecl BrActorToBounds(br_bounds *b, br_actor *ap) {
    br_matrix34 m2v;
    br_model *model;
    br_actor *a;
    LOG_TRACE("(%p, %p)", b, ap);

    (void)b;
    (void)ap;
    (void)m2v;
    (void)model;
    (void)a;

    if (function_hook_state_BrActorToBounds == HOOK_ENABLED) {
        assert(0 && "BrActorToBounds not implemented.");
        abort();
    } else {
        return original_BrActorToBounds(b, ap);
    }
}

