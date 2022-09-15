#include "brucetrk.h"

#include "harness/trace.h"

#include "carm95_hooks.h"

#include <stdio.h>
br_actor ** hookvar_gMr_blendy  = (void*)0x0053e488;
int * hookvar_gDefault_blend_pc  = (void*)0x00550244;

static void(*original_AllocateActorMatrix)(tTrack_spec *, br_actor ****, ...) = (void(*)(tTrack_spec *, br_actor ****, ...))0x004a8a26;
CARM95_HOOK_FUNCTION(original_AllocateActorMatrix, AllocateActorMatrix)
void AllocateActorMatrix(tTrack_spec *pTrack_spec, br_actor ****pDst) {
    tU16 z;
    LOG_TRACE("(%p, %p)", pTrack_spec, pDst);

    (void)pTrack_spec;
    (void)pDst;
    (void)z;

    original_AllocateActorMatrix(pTrack_spec, pDst);
}

static void(*original_DisposeActorMatrix)(tTrack_spec *, br_actor ****, int, ...) = (void(*)(tTrack_spec *, br_actor ****, int, ...))0x004a8610;
CARM95_HOOK_FUNCTION(original_DisposeActorMatrix, DisposeActorMatrix)
void DisposeActorMatrix(tTrack_spec *pTrack_spec, br_actor ****pVictim, int pRemove_act_mod) {
    tU16 z;
    tU16 x;
    LOG_TRACE("(%p, %p, %d)", pTrack_spec, pVictim, pRemove_act_mod);

    (void)pTrack_spec;
    (void)pVictim;
    (void)pRemove_act_mod;
    (void)z;
    (void)x;

    original_DisposeActorMatrix(pTrack_spec, pVictim, pRemove_act_mod);
}

static void(*original_DisposeColumns)(tTrack_spec *, ...) = (void(*)(tTrack_spec *, ...))0x004a8590;
CARM95_HOOK_FUNCTION(original_DisposeColumns, DisposeColumns)
void DisposeColumns(tTrack_spec *pTrack_spec) {
    LOG_TRACE("(%p)", pTrack_spec);

    (void)pTrack_spec;

    original_DisposeColumns(pTrack_spec);
}

static void(*original_XZToColumnXZ)(tU8 *, tU8 *, br_scalar, br_scalar, tTrack_spec *, ...) = (void(*)(tU8 *, tU8 *, br_scalar, br_scalar, tTrack_spec *, ...))0x004a874b;
CARM95_HOOK_FUNCTION(original_XZToColumnXZ, XZToColumnXZ)
void XZToColumnXZ(tU8 *pColumn_x, tU8 *pColumn_z, br_scalar pX, br_scalar pZ, tTrack_spec *pTrack_spec) {
    br_scalar x;
    br_scalar z;
    LOG_TRACE("(%p, %p, %f, %f, %p)", pColumn_x, pColumn_z, pX, pZ, pTrack_spec);

    (void)pColumn_x;
    (void)pColumn_z;
    (void)pX;
    (void)pZ;
    (void)pTrack_spec;
    (void)x;
    (void)z;

    original_XZToColumnXZ(pColumn_x, pColumn_z, pX, pZ, pTrack_spec);
}

static void(*original_StripBlendedFaces)(br_actor *, br_model *, ...) = (void(*)(br_actor *, br_model *, ...))0x004a8d47;
CARM95_HOOK_FUNCTION(original_StripBlendedFaces, StripBlendedFaces)
void StripBlendedFaces(br_actor *pActor, br_model *pModel) {
    int i;
    br_face *face;
    int changed_one;
    char s[256];
    static tU16 nfaces_allocated;
    LOG_TRACE("(%p, %p)", pActor, pModel);

    (void)pActor;
    (void)pModel;
    (void)i;
    (void)face;
    (void)changed_one;
    (void)s;
    (void)nfaces_allocated;

    original_StripBlendedFaces(pActor, pModel);
}

static br_uint_32(*original_FindNonCarsCB)(br_actor *, tTrack_spec *, ...) = (br_uint_32(*)(br_actor *, tTrack_spec *, ...))0x004a90ff;
CARM95_HOOK_FUNCTION(original_FindNonCarsCB, FindNonCarsCB)
br_uint_32 FindNonCarsCB(br_actor *pActor, tTrack_spec *pTrack_spec) {
    int i;
    br_scalar r1;
    br_scalar r2;
    br_scalar r3;
    LOG_TRACE("(%p, %p)", pActor, pTrack_spec);

    (void)pActor;
    (void)pTrack_spec;
    (void)i;
    (void)r1;
    (void)r2;
    (void)r3;

    return original_FindNonCarsCB(pActor, pTrack_spec);
}

static br_uint_32(*original_ProcessModelsCB)(br_actor *, tTrack_spec *, ...) = (br_uint_32(*)(br_actor *, tTrack_spec *, ...))0x004a8afc;
CARM95_HOOK_FUNCTION(original_ProcessModelsCB, ProcessModelsCB)
br_uint_32 ProcessModelsCB(br_actor *pActor, tTrack_spec *pTrack_spec) {
    unsigned int x;
    unsigned int z;
    int group;
    LOG_TRACE("(%p, %p)", pActor, pTrack_spec);

    (void)pActor;
    (void)pTrack_spec;
    (void)x;
    (void)z;
    (void)group;

    return original_ProcessModelsCB(pActor, pTrack_spec);
}

static void(*original_ProcessModels)(tTrack_spec *, ...) = (void(*)(tTrack_spec *, ...))0x004a8ad9;
CARM95_HOOK_FUNCTION(original_ProcessModels, ProcessModels)
void ProcessModels(tTrack_spec *pTrack_spec) {
    LOG_TRACE("(%p)", pTrack_spec);

    (void)pTrack_spec;

    original_ProcessModels(pTrack_spec);
}

static void(*original_ExtractColumns)(tTrack_spec *, ...) = (void(*)(tTrack_spec *, ...))0x004a884d;
CARM95_HOOK_FUNCTION(original_ExtractColumns, ExtractColumns)
void ExtractColumns(tTrack_spec *pTrack_spec) {
    unsigned int x;
    unsigned int z;
    int ad;
    int unsplit;
    float e;
    br_scalar extra_room;
    br_bounds bounds;
    LOG_TRACE("(%p)", pTrack_spec);

    (void)pTrack_spec;
    (void)x;
    (void)z;
    (void)ad;
    (void)unsplit;
    (void)e;
    (void)extra_room;
    (void)bounds;

    original_ExtractColumns(pTrack_spec);
}

void LollipopizeActor4(br_actor *pActor, br_matrix34 *pRef_to_world, br_actor *pCamera) {
    LOG_TRACE("(%p, %p, %p)", pActor, pRef_to_world, pCamera);

    (void)pActor;
    (void)pRef_to_world;
    (void)pCamera;

    NOT_IMPLEMENTED();
}

br_uint_32 LollipopizeChildren(br_actor *pActor, void *pArg) {
    tMatrix_and_actor *maa;
    LOG_TRACE("(%p, %p)", pActor, pArg);

    (void)pActor;
    (void)pArg;
    (void)maa;

    NOT_IMPLEMENTED();
}

static void(*original_DrawColumns)(int, tTrack_spec *, int, int, int, int, br_matrix34 *, ...) = (void(*)(int, tTrack_spec *, int, int, int, int, br_matrix34 *, ...))0x004a9a01;
CARM95_HOOK_FUNCTION(original_DrawColumns, DrawColumns)
void DrawColumns(int pDraw_blends, tTrack_spec *pTrack_spec, int pMin_x, int pMax_x, int pMin_z, int pMax_z, br_matrix34 *pCamera_to_world) {
    tU8 column_x;
    tU8 column_z;
    tU8 column_x2;
    tU8 column_z2;
    tMatrix_and_actor maa;
    br_actor *blended_polys;
    LOG_TRACE("(%d, %p, %d, %d, %d, %d, %p)", pDraw_blends, pTrack_spec, pMin_x, pMax_x, pMin_z, pMax_z, pCamera_to_world);

    (void)pDraw_blends;
    (void)pTrack_spec;
    (void)pMin_x;
    (void)pMax_x;
    (void)pMin_z;
    (void)pMax_z;
    (void)pCamera_to_world;
    (void)column_x;
    (void)column_z;
    (void)column_x2;
    (void)column_z2;
    (void)maa;
    (void)blended_polys;

    original_DrawColumns(pDraw_blends, pTrack_spec, pMin_x, pMax_x, pMin_z, pMax_z, pCamera_to_world);
}

static void(*original_RenderTrack)(br_actor *, tTrack_spec *, br_actor *, br_matrix34 *, int, ...) = (void(*)(br_actor *, tTrack_spec *, br_actor *, br_matrix34 *, int, ...))0x004a944a;
CARM95_HOOK_FUNCTION(original_RenderTrack, RenderTrack)
void RenderTrack(br_actor *pWorld, tTrack_spec *pTrack_spec, br_actor *pCamera, br_matrix34 *pCamera_to_world, int pRender_blends) {
    static tU8 column_x;
    static tU8 column_z;
    static tU8 min_x;
    static tU8 max_x;
    static tU8 min_z;
    static tU8 max_z;
    static br_vector3 edge_before;
    static br_vector3 edge_after;
    static br_camera *camera;
    static br_scalar tan_fov_ish;
    static br_actor *result;
    LOG_TRACE("(%p, %p, %p, %p, %d)", pWorld, pTrack_spec, pCamera, pCamera_to_world, pRender_blends);

    (void)pWorld;
    (void)pTrack_spec;
    (void)pCamera;
    (void)pCamera_to_world;
    (void)pRender_blends;
    (void)column_x;
    (void)column_z;
    (void)min_x;
    (void)max_x;
    (void)min_z;
    (void)max_z;
    (void)edge_before;
    (void)edge_after;
    (void)camera;
    (void)tan_fov_ish;
    (void)result;

    original_RenderTrack(pWorld, pTrack_spec, pCamera, pCamera_to_world, pRender_blends);
}

static br_scalar(*original_GetYonFactor)() = (br_scalar(*)())0x004a9e6e;
CARM95_HOOK_FUNCTION(original_GetYonFactor, GetYonFactor)
br_scalar GetYonFactor() {
    LOG_TRACE("()");


    return original_GetYonFactor();
}

static void(*original_SetYonFactor)(br_scalar, ...) = (void(*)(br_scalar, ...))0x004a9e84;
CARM95_HOOK_FUNCTION(original_SetYonFactor, SetYonFactor)
void SetYonFactor(br_scalar pNew) {
    LOG_TRACE("(%f)", pNew);

    (void)pNew;

    original_SetYonFactor(pNew);
}

