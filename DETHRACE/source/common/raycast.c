#include "raycast.h"

#include "harness/trace.h"

#include "carm95_hooks.h"

#include "carm95_webserver.h"

#include <assert.h>
 // Suffix added to avoid duplicate symbol
br_matrix34 * hookvar_gPick_model_to_view__raycast  = (void*)0x0053d028;
int * hookvar_gBelow_face_index  = (void*)0x0053d010;
br_scalar * hookvar_gCurrent_y  = (void*)0x0053d018;
int * hookvar_gAbove_face_index  = (void*)0x0053d020;
br_model ** hookvar_gAbove_model  = (void*)0x0053d01c;
br_model ** hookvar_gBelow_model  = (void*)0x0053d00c;
br_scalar * hookvar_gHighest_y_below  = (void*)0x0053d058;
br_actor ** hookvar_gY_picking_camera  = (void*)0x0053d008;
br_scalar * hookvar_gLowest_y_above  = (void*)0x0053d014;

function_hook_state_t function_hook_state_DRActorToRoot = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_DRActorToRoot)
static int(__cdecl*original_DRActorToRoot)(br_actor *, br_actor *, br_matrix34 *) = (int(__cdecl*)(br_actor *, br_actor *, br_matrix34 *))0x00494230;
CARM95_HOOK_FUNCTION(original_DRActorToRoot, DRActorToRoot)
int __cdecl DRActorToRoot(br_actor *a, br_actor *world, br_matrix34 *m) {
    LOG_TRACE("(%p, %p, %p)", a, world, m);

    (void)a;
    (void)world;
    (void)m;

    if (function_hook_state_DRActorToRoot == HOOK_ENABLED) {
        assert(0 && "DRActorToRoot not implemented.");
        abort();
    } else {
        return original_DRActorToRoot(a, world, m);
    }
}

function_hook_state_t function_hook_state_InitRayCasting = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_InitRayCasting)
static void(__cdecl*original_InitRayCasting)() = (void(__cdecl*)())0x004942e4;
CARM95_HOOK_FUNCTION(original_InitRayCasting, InitRayCasting)
void __cdecl InitRayCasting() {
    br_camera *camera_ptr;
    LOG_TRACE("()");

    (void)camera_ptr;

    if (function_hook_state_InitRayCasting == HOOK_ENABLED) {
        assert(0 && "InitRayCasting not implemented.");
        abort();
    } else {
        original_InitRayCasting();
    }
}

function_hook_state_t function_hook_state_BadDiv__raycast = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_BadDiv__raycast)
int BadDiv__raycast(br_scalar a, br_scalar b) {
    LOG_TRACE("(%f, %f)", a, b);

    (void)a;
    (void)b;

    if (function_hook_state_BadDiv__raycast == HOOK_ENABLED) {
        assert(0 && "BadDiv__raycast not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}

function_hook_state_t function_hook_state_DRVector2AccumulateScale__raycast = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_DRVector2AccumulateScale__raycast)
void DRVector2AccumulateScale__raycast(br_vector2 *a, br_vector2 *b, br_scalar s) {
    LOG_TRACE("(%p, %p, %f)", a, b, s);

    (void)a;
    (void)b;
    (void)s;

    if (function_hook_state_DRVector2AccumulateScale__raycast == HOOK_ENABLED) {
        assert(0 && "DRVector2AccumulateScale__raycast not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}

function_hook_state_t function_hook_state_PickBoundsTestRay__raycast = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_PickBoundsTestRay__raycast)
static int(__cdecl*original_PickBoundsTestRay__raycast)(br_bounds *, br_vector3 *, br_vector3 *, br_scalar, br_scalar, br_scalar *, br_scalar *) = (int(__cdecl*)(br_bounds *, br_vector3 *, br_vector3 *, br_scalar, br_scalar, br_scalar *, br_scalar *))0x00494765;
CARM95_HOOK_FUNCTION(original_PickBoundsTestRay__raycast, PickBoundsTestRay__raycast)
int __cdecl PickBoundsTestRay__raycast(br_bounds *b, br_vector3 *rp, br_vector3 *rd, br_scalar t_near, br_scalar t_far, br_scalar *new_t_near, br_scalar *new_t_far) {
    int i;
    float s;
    float t;
    LOG_TRACE("(%p, %p, %p, %f, %f, %p, %p)", b, rp, rd, t_near, t_far, new_t_near, new_t_far);

    (void)b;
    (void)rp;
    (void)rd;
    (void)t_near;
    (void)t_far;
    (void)new_t_near;
    (void)new_t_far;
    (void)i;
    (void)s;
    (void)t;

    if (function_hook_state_PickBoundsTestRay__raycast == HOOK_ENABLED) {
        assert(0 && "PickBoundsTestRay__raycast not implemented.");
        abort();
    } else {
        return original_PickBoundsTestRay__raycast(b, rp, rd, t_near, t_far, new_t_near, new_t_far);
    }
}

function_hook_state_t function_hook_state_ActorPick2D = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_ActorPick2D)
static int(__cdecl*original_ActorPick2D)(br_actor *, br_model *, br_material *, dr_pick2d_cbfn *, void *) = (int(__cdecl*)(br_actor *, br_model *, br_material *, dr_pick2d_cbfn *, void *))0x004944de;
CARM95_HOOK_FUNCTION(original_ActorPick2D, ActorPick2D)
int __cdecl ActorPick2D(br_actor *ap, br_model *model, br_material *material, dr_pick2d_cbfn *callback, void *arg) {
    br_actor *a;
    br_model *this_model;
    br_material *this_material;
    br_matrix34 m_to_v;
    br_matrix34 v_to_m;
    br_scalar t_near;
    br_scalar t_far;
    int r;
    br_vector3 __block0__dir;
    LOG_TRACE("(%p, %p, %p, %p, %p)", ap, model, material, callback, arg);

    (void)ap;
    (void)model;
    (void)material;
    (void)callback;
    (void)arg;
    (void)a;
    (void)this_model;
    (void)this_material;
    (void)m_to_v;
    (void)v_to_m;
    (void)t_near;
    (void)t_far;
    (void)r;
    (void)__block0__dir;

    if (function_hook_state_ActorPick2D == HOOK_ENABLED) {
        assert(0 && "ActorPick2D not implemented.");
        abort();
    } else {
        return original_ActorPick2D(ap, model, material, callback, arg);
    }
}

function_hook_state_t function_hook_state_DRScenePick2DXY = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_DRScenePick2DXY)
static int(__cdecl*original_DRScenePick2DXY)(br_actor *, br_actor *, br_pixelmap *, int, int, dr_pick2d_cbfn *, void *) = (int(__cdecl*)(br_actor *, br_actor *, br_pixelmap *, int, int, dr_pick2d_cbfn *, void *))0x004943a8;
CARM95_HOOK_FUNCTION(original_DRScenePick2DXY, DRScenePick2DXY)
int __cdecl DRScenePick2DXY(br_actor *world, br_actor *camera, br_pixelmap *viewport, int pick_x, int pick_y, dr_pick2d_cbfn *callback, void *arg) {
    br_matrix34 camera_tfm;
    br_scalar scale;
    br_scalar cos_angle;
    br_scalar sin_angle;
    br_camera *camera_data;
    br_angle view_over_2;
    LOG_TRACE("(%p, %p, %p, %d, %d, %p, %p)", world, camera, viewport, pick_x, pick_y, callback, arg);

    (void)world;
    (void)camera;
    (void)viewport;
    (void)pick_x;
    (void)pick_y;
    (void)callback;
    (void)arg;
    (void)camera_tfm;
    (void)scale;
    (void)cos_angle;
    (void)sin_angle;
    (void)camera_data;
    (void)view_over_2;

    if (function_hook_state_DRScenePick2DXY == HOOK_ENABLED) {
        assert(0 && "DRScenePick2DXY not implemented.");
        abort();
    } else {
        return original_DRScenePick2DXY(world, camera, viewport, pick_x, pick_y, callback, arg);
    }
}

function_hook_state_t function_hook_state_DRScenePick2D = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_DRScenePick2D)
static int(__cdecl*original_DRScenePick2D)(br_actor *, br_actor *, dr_pick2d_cbfn *, void *) = (int(__cdecl*)(br_actor *, br_actor *, dr_pick2d_cbfn *, void *))0x0049499e;
CARM95_HOOK_FUNCTION(original_DRScenePick2D, DRScenePick2D)
int __cdecl DRScenePick2D(br_actor *world, br_actor *camera, dr_pick2d_cbfn *callback, void *arg) {
    br_matrix34 camera_tfm;
    br_scalar scale;
    br_camera *camera_data;
    LOG_TRACE("(%p, %p, %p, %p)", world, camera, callback, arg);

    (void)world;
    (void)camera;
    (void)callback;
    (void)arg;
    (void)camera_tfm;
    (void)scale;
    (void)camera_data;

    if (function_hook_state_DRScenePick2D == HOOK_ENABLED) {
        assert(0 && "DRScenePick2D not implemented.");
        abort();
    } else {
        return original_DRScenePick2D(world, camera, callback, arg);
    }
}

function_hook_state_t function_hook_state_DRModelPick2D__raycast = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_DRModelPick2D__raycast)
static int(__cdecl*original_DRModelPick2D__raycast)(br_model *, br_material *, br_vector3 *, br_vector3 *, br_scalar, br_scalar, dr_modelpick2d_cbfn *, void *) = (int(__cdecl*)(br_model *, br_material *, br_vector3 *, br_vector3 *, br_scalar, br_scalar, dr_modelpick2d_cbfn *, void *))0x00494b88;
CARM95_HOOK_FUNCTION(original_DRModelPick2D__raycast, DRModelPick2D__raycast)
int __cdecl DRModelPick2D__raycast(br_model *model, br_material *material, br_vector3 *ray_pos, br_vector3 *ray_dir, br_scalar t_near, br_scalar t_far, dr_modelpick2d_cbfn *callback, void *arg) {
    DR_FACE *fp;
    int f;
    int axis_m;
    int axis_0;
    int axis_1;
    int group;
    br_scalar t;
    br_scalar n;
    br_scalar d;
    br_vector3 p;
    double u0;
    double u1;
    double u2;
    double v0;
    double v1;
    double v2;
    br_scalar v0i1;
    br_scalar v0i2;
    double alpha;
    double beta;
    double f_d;
    double f_n;
    br_scalar s_alpha;
    br_scalar s_beta;
    br_vector2 map;
    int v;
    int e;
    int r;
    br_material *this_material;
    br_scalar numerator;
    double f_numerator;
    LOG_TRACE("(%p, %p, %p, %p, %f, %f, %p, %p)", model, material, ray_pos, ray_dir, t_near, t_far, callback, arg);

    (void)model;
    (void)material;
    (void)ray_pos;
    (void)ray_dir;
    (void)t_near;
    (void)t_far;
    (void)callback;
    (void)arg;
    (void)fp;
    (void)f;
    (void)axis_m;
    (void)axis_0;
    (void)axis_1;
    (void)group;
    (void)t;
    (void)n;
    (void)d;
    (void)p;
    (void)u0;
    (void)u1;
    (void)u2;
    (void)v0;
    (void)v1;
    (void)v2;
    (void)v0i1;
    (void)v0i2;
    (void)alpha;
    (void)beta;
    (void)f_d;
    (void)f_n;
    (void)s_alpha;
    (void)s_beta;
    (void)map;
    (void)v;
    (void)e;
    (void)r;
    (void)this_material;
    (void)numerator;
    (void)f_numerator;

    if (function_hook_state_DRModelPick2D__raycast == HOOK_ENABLED) {
        assert(0 && "DRModelPick2D__raycast not implemented.");
        abort();
    } else {
        return original_DRModelPick2D__raycast(model, material, ray_pos, ray_dir, t_near, t_far, callback, arg);
    }
}

function_hook_state_t function_hook_state_FindHighestPolyCallBack__raycast = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_FindHighestPolyCallBack__raycast)
int FindHighestPolyCallBack__raycast(br_model *pModel, br_material *pMaterial, br_vector3 *pRay_pos, br_vector3 *pRay_dir, br_scalar pT, int pF, int pE, int pV, br_vector3 *pPoint, br_vector2 *pMap, void *pArg) {
    br_scalar the_y;
    LOG_TRACE("(%p, %p, %p, %p, %f, %d, %d, %d, %p, %p, %p)", pModel, pMaterial, pRay_pos, pRay_dir, pT, pF, pE, pV, pPoint, pMap, pArg);

    (void)pModel;
    (void)pMaterial;
    (void)pRay_pos;
    (void)pRay_dir;
    (void)pT;
    (void)pF;
    (void)pE;
    (void)pV;
    (void)pPoint;
    (void)pMap;
    (void)pArg;
    (void)the_y;

    if (function_hook_state_FindHighestPolyCallBack__raycast == HOOK_ENABLED) {
        assert(0 && "FindHighestPolyCallBack__raycast not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}

function_hook_state_t function_hook_state_FindHighestCallBack__raycast = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_FindHighestCallBack__raycast)
static int(__cdecl*original_FindHighestCallBack__raycast)(br_actor *, br_model *, br_material *, br_vector3 *, br_vector3 *, br_scalar, br_scalar, void *) = (int(__cdecl*)(br_actor *, br_model *, br_material *, br_vector3 *, br_vector3 *, br_scalar, br_scalar, void *))0x00494b28;
CARM95_HOOK_FUNCTION(original_FindHighestCallBack__raycast, FindHighestCallBack__raycast)
int __cdecl FindHighestCallBack__raycast(br_actor *pActor, br_model *pModel, br_material *pMaterial, br_vector3 *pRay_pos, br_vector3 *pRay_dir, br_scalar pT_near, br_scalar pT_far, void *pArg) {
    LOG_TRACE("(%p, %p, %p, %p, %p, %f, %f, %p)", pActor, pModel, pMaterial, pRay_pos, pRay_dir, pT_near, pT_far, pArg);

    (void)pActor;
    (void)pModel;
    (void)pMaterial;
    (void)pRay_pos;
    (void)pRay_dir;
    (void)pT_near;
    (void)pT_far;
    (void)pArg;

    if (function_hook_state_FindHighestCallBack__raycast == HOOK_ENABLED) {
        assert(0 && "FindHighestCallBack__raycast not implemented.");
        abort();
    } else {
        return original_FindHighestCallBack__raycast(pActor, pModel, pMaterial, pRay_pos, pRay_dir, pT_near, pT_far, pArg);
    }
}

function_hook_state_t function_hook_state_FindBestY = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_FindBestY)
static void(__cdecl*original_FindBestY)(br_vector3 *, br_actor *, br_scalar, br_scalar *, br_scalar *, br_model **, br_model **, int *, int *) = (void(__cdecl*)(br_vector3 *, br_actor *, br_scalar, br_scalar *, br_scalar *, br_model **, br_model **, int *, int *))0x00494a71;
CARM95_HOOK_FUNCTION(original_FindBestY, FindBestY)
void __cdecl FindBestY(br_vector3 *pPosition, br_actor *gWorld, br_scalar pStarting_height, br_scalar *pNearest_y_above, br_scalar *pNearest_y_below, br_model **pNearest_above_model, br_model **pNearest_below_model, int *pNearest_above_face_index, int *pNearest_below_face_index) {
    LOG_TRACE("(%p, %p, %f, %p, %p, %p, %p, %p, %p)", pPosition, gWorld, pStarting_height, pNearest_y_above, pNearest_y_below, pNearest_above_model, pNearest_below_model, pNearest_above_face_index, pNearest_below_face_index);

    (void)pPosition;
    (void)gWorld;
    (void)pStarting_height;
    (void)pNearest_y_above;
    (void)pNearest_y_below;
    (void)pNearest_above_model;
    (void)pNearest_below_model;
    (void)pNearest_above_face_index;
    (void)pNearest_below_face_index;

    if (function_hook_state_FindBestY == HOOK_ENABLED) {
        assert(0 && "FindBestY not implemented.");
        abort();
    } else {
        original_FindBestY(pPosition, gWorld, pStarting_height, pNearest_y_above, pNearest_y_below, pNearest_above_model, pNearest_below_model, pNearest_above_face_index, pNearest_below_face_index);
    }
}

function_hook_state_t function_hook_state_FindYVerticallyBelowPolyCallBack = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_FindYVerticallyBelowPolyCallBack)
static int(__cdecl*original_FindYVerticallyBelowPolyCallBack)(br_model *, br_material *, br_vector3 *, br_vector3 *, br_scalar, int, int, int, br_vector3 *, br_vector2 *, void *) = (int(__cdecl*)(br_model *, br_material *, br_vector3 *, br_vector3 *, br_scalar, int, int, int, br_vector3 *, br_vector2 *, void *))0x004955eb;
CARM95_HOOK_FUNCTION(original_FindYVerticallyBelowPolyCallBack, FindYVerticallyBelowPolyCallBack)
int __cdecl FindYVerticallyBelowPolyCallBack(br_model *pModel, br_material *pMaterial, br_vector3 *pRay_pos, br_vector3 *pRay_dir, br_scalar pT, int pF, int pE, int pV, br_vector3 *pPoint, br_vector2 *pMap, void *pArg) {
    br_scalar the_y;
    LOG_TRACE("(%p, %p, %p, %p, %f, %d, %d, %d, %p, %p, %p)", pModel, pMaterial, pRay_pos, pRay_dir, pT, pF, pE, pV, pPoint, pMap, pArg);

    (void)pModel;
    (void)pMaterial;
    (void)pRay_pos;
    (void)pRay_dir;
    (void)pT;
    (void)pF;
    (void)pE;
    (void)pV;
    (void)pPoint;
    (void)pMap;
    (void)pArg;
    (void)the_y;

    if (function_hook_state_FindYVerticallyBelowPolyCallBack == HOOK_ENABLED) {
        assert(0 && "FindYVerticallyBelowPolyCallBack not implemented.");
        abort();
    } else {
        return original_FindYVerticallyBelowPolyCallBack(pModel, pMaterial, pRay_pos, pRay_dir, pT, pF, pE, pV, pPoint, pMap, pArg);
    }
}

function_hook_state_t function_hook_state_FindYVerticallyBelowCallBack = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_FindYVerticallyBelowCallBack)
static int(__cdecl*original_FindYVerticallyBelowCallBack)(br_actor *, br_model *, br_material *, br_vector3 *, br_vector3 *, br_scalar, br_scalar, void *) = (int(__cdecl*)(br_actor *, br_model *, br_material *, br_vector3 *, br_vector3 *, br_scalar, br_scalar, void *))0x0049558b;
CARM95_HOOK_FUNCTION(original_FindYVerticallyBelowCallBack, FindYVerticallyBelowCallBack)
int __cdecl FindYVerticallyBelowCallBack(br_actor *pActor, br_model *pModel, br_material *pMaterial, br_vector3 *pRay_pos, br_vector3 *pRay_dir, br_scalar pT_near, br_scalar pT_far, void *pArg) {
    LOG_TRACE("(%p, %p, %p, %p, %p, %f, %f, %p)", pActor, pModel, pMaterial, pRay_pos, pRay_dir, pT_near, pT_far, pArg);

    (void)pActor;
    (void)pModel;
    (void)pMaterial;
    (void)pRay_pos;
    (void)pRay_dir;
    (void)pT_near;
    (void)pT_far;
    (void)pArg;

    if (function_hook_state_FindYVerticallyBelowCallBack == HOOK_ENABLED) {
        assert(0 && "FindYVerticallyBelowCallBack not implemented.");
        abort();
    } else {
        return original_FindYVerticallyBelowCallBack(pActor, pModel, pMaterial, pRay_pos, pRay_dir, pT_near, pT_far, pArg);
    }
}

function_hook_state_t function_hook_state_FindYVerticallyBelow = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_FindYVerticallyBelow)
static br_scalar(__cdecl*original_FindYVerticallyBelow)(br_vector3 *) = (br_scalar(__cdecl*)(br_vector3 *))0x004953da;
CARM95_HOOK_FUNCTION(original_FindYVerticallyBelow, FindYVerticallyBelow)
br_scalar __cdecl FindYVerticallyBelow(br_vector3 *pPosition) {
    tU8 cx;
    tU8 cz;
    tU8 x;
    tU8 z;
    tTrack_spec *track_spec;
    LOG_TRACE("(%p)", pPosition);

    (void)pPosition;
    (void)cx;
    (void)cz;
    (void)x;
    (void)z;
    (void)track_spec;

    if (function_hook_state_FindYVerticallyBelow == HOOK_ENABLED) {
        assert(0 && "FindYVerticallyBelow not implemented.");
        abort();
    } else {
        return original_FindYVerticallyBelow(pPosition);
    }
}

function_hook_state_t function_hook_state_FindYVerticallyBelow2 = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_FindYVerticallyBelow2)
static br_scalar(__cdecl*original_FindYVerticallyBelow2)(br_vector3 *) = (br_scalar(__cdecl*)(br_vector3 *))0x0049564b;
CARM95_HOOK_FUNCTION(original_FindYVerticallyBelow2, FindYVerticallyBelow2)
br_scalar __cdecl FindYVerticallyBelow2(br_vector3 *pCast_point) {
    br_scalar result;
    int number_of_attempts;
    br_vector3 cast_point;
    LOG_TRACE("(%p)", pCast_point);

    (void)pCast_point;
    (void)result;
    (void)number_of_attempts;
    (void)cast_point;

    if (function_hook_state_FindYVerticallyBelow2 == HOOK_ENABLED) {
        assert(0 && "FindYVerticallyBelow2 not implemented.");
        abort();
    } else {
        return original_FindYVerticallyBelow2(pCast_point);
    }
}

