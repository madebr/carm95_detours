#include "finteray.h"

#include "harness/trace.h"

#include "carm95_hooks.h"

int * hookvar_gPling_materials  = (void*)0x0051e8fc;
#if 0
br_material ** hookvar_gSub_material ;
#endif
#if 0
br_material ** hookvar_gReal_material ;
#endif
int * hookvar_gNfaces  = (void*)0x0051e908;
 // Suffix added to avoid duplicate symbol
br_matrix34 * hookvar_gPick_model_to_view__finteray  = (void*)0x0053e558;
int * hookvar_gTemp_group  = (void*)0x0053e588;
br_model ** hookvar_gNearest_model  = (void*)0x0053e54c;
br_model ** hookvar_gSelected_model  = (void*)0x0053e58c;
int * hookvar_gNearest_face_group  = (void*)0x0053e554;
int * hookvar_gNearest_face  = (void*)0x0053e548;
br_scalar * hookvar_gNearest_T  = (void*)0x0053e550;
tFace_ref ** hookvar_gPling_face  = (void*)0x00550240;

static int(__cdecl*original_BadDiv__finteray)(br_scalar, br_scalar) = (int(__cdecl*)(br_scalar, br_scalar))0x004952ca;
CARM95_HOOK_FUNCTION(original_BadDiv__finteray, BadDiv__finteray)
int __cdecl BadDiv__finteray(br_scalar a, br_scalar b) {
    LOG_TRACE("(%f, %f)", a, b);

    (void)a;
    (void)b;

    return original_BadDiv__finteray(a, b);
}

static void(__cdecl*original_DRVector2AccumulateScale__finteray)(br_vector2 *, br_vector2 *, br_scalar) = (void(__cdecl*)(br_vector2 *, br_vector2 *, br_scalar))0x00495319;
CARM95_HOOK_FUNCTION(original_DRVector2AccumulateScale__finteray, DRVector2AccumulateScale__finteray)
void __cdecl DRVector2AccumulateScale__finteray(br_vector2 *a, br_vector2 *b, br_scalar s) {
    LOG_TRACE("(%p, %p, %f)", a, b, s);

    (void)a;
    (void)b;
    (void)s;

    original_DRVector2AccumulateScale__finteray(a, b, s);
}

static int(__cdecl*original_PickBoundsTestRay__finteray)(br_bounds *, br_vector3 *, br_vector3 *, br_scalar, br_scalar, br_scalar *, br_scalar *) = (int(__cdecl*)(br_bounds *, br_vector3 *, br_vector3 *, br_scalar, br_scalar, br_scalar *, br_scalar *))0x004ab244;
CARM95_HOOK_FUNCTION(original_PickBoundsTestRay__finteray, PickBoundsTestRay__finteray)
int __cdecl PickBoundsTestRay__finteray(br_bounds *b, br_vector3 *rp, br_vector3 *rd, br_scalar t_near, br_scalar t_far, br_scalar *new_t_near, br_scalar *new_t_far) {
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

    return original_PickBoundsTestRay__finteray(b, rp, rd, t_near, t_far, new_t_near, new_t_far);
}

static int(__cdecl*original_ActorRayPick2D)(br_actor *, br_vector3 *, br_vector3 *, br_model *, br_material *, dr_pick2d_cbfn *) = (int(__cdecl*)(br_actor *, br_vector3 *, br_vector3 *, br_model *, br_material *, dr_pick2d_cbfn *))0x004aaf5a;
CARM95_HOOK_FUNCTION(original_ActorRayPick2D, ActorRayPick2D)
int __cdecl ActorRayPick2D(br_actor *ap, br_vector3 *pPosition, br_vector3 *pDir, br_model *model, br_material *material, dr_pick2d_cbfn *callback) {
    br_actor *a;
    br_model *this_model;
    br_material *this_material;
    br_scalar t_near;
    br_scalar t_far;
    int r;
    br_matrix34 mat;
    br_matrix34 invmat;
    br_vector3 pos;
    br_vector3 dir;
    void *arg;
    LOG_TRACE("(%p, %p, %p, %p, %p, %p)", ap, pPosition, pDir, model, material, callback);

    (void)ap;
    (void)pPosition;
    (void)pDir;
    (void)model;
    (void)material;
    (void)callback;
    (void)a;
    (void)this_model;
    (void)this_material;
    (void)t_near;
    (void)t_far;
    (void)r;
    (void)mat;
    (void)invmat;
    (void)pos;
    (void)dir;
    (void)arg;

    return original_ActorRayPick2D(ap, pPosition, pDir, model, material, callback);
}

static int(__cdecl*original_DRSceneRayPick2D)(br_actor *, br_vector3 *, br_vector3 *, dr_pick2d_cbfn *) = (int(__cdecl*)(br_actor *, br_vector3 *, br_vector3 *, dr_pick2d_cbfn *))0x004aaf10;
CARM95_HOOK_FUNCTION(original_DRSceneRayPick2D, DRSceneRayPick2D)
int __cdecl DRSceneRayPick2D(br_actor *world, br_vector3 *pPosition, br_vector3 *pDir, dr_pick2d_cbfn *callback) {
    LOG_TRACE("(%p, %p, %p, %p)", world, pPosition, pDir, callback);

    (void)world;
    (void)pPosition;
    (void)pDir;
    (void)callback;

    return original_DRSceneRayPick2D(world, pPosition, pDir, callback);
}

static int(__cdecl*original_DRModelPick2D__finteray)(br_model *, br_material *, br_vector3 *, br_vector3 *, br_scalar, br_scalar, dr_modelpick2d_cbfn *, void *) = (int(__cdecl*)(br_model *, br_material *, br_vector3 *, br_vector3 *, br_scalar, br_scalar, dr_modelpick2d_cbfn *, void *))0x004ab5e4;
CARM95_HOOK_FUNCTION(original_DRModelPick2D__finteray, DRModelPick2D__finteray)
int __cdecl DRModelPick2D__finteray(br_model *model, br_material *material, br_vector3 *ray_pos, br_vector3 *ray_dir, br_scalar t_near, br_scalar t_far, dr_modelpick2d_cbfn *callback, void *arg) {
    DR_FACE *fp;
    int f;
    int axis_m;
    int axis_0;
    int axis_1;
    br_scalar t;
    br_scalar n;
    br_scalar d;
    br_vector3 p;
    float u0;
    float u1;
    float u2;
    float v0;
    float v1;
    float v2;
    br_scalar v0i1;
    br_scalar v0i2;
    float alpha;
    float beta;
    float f_d;
    float f_n;
    br_scalar s_alpha;
    br_scalar s_beta;
    br_vector2 map;
    int v;
    int e;
    int r;
    br_material *this_material;
    br_scalar numerator;
    float f_numerator;
    int group;
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
    (void)group;

    return original_DRModelPick2D__finteray(model, material, ray_pos, ray_dir, t_near, t_far, callback, arg);
}

static int(__cdecl*original_FindHighestPolyCallBack__finteray)(br_model *, br_material *, br_vector3 *, br_vector3 *, br_scalar, int, int, int, br_vector3 *, br_vector2 *, void *) = (int(__cdecl*)(br_model *, br_material *, br_vector3 *, br_vector3 *, br_scalar, int, int, int, br_vector3 *, br_vector2 *, void *))0x004abe8d;
CARM95_HOOK_FUNCTION(original_FindHighestPolyCallBack__finteray, FindHighestPolyCallBack__finteray)
int __cdecl FindHighestPolyCallBack__finteray(br_model *pModel, br_material *pMaterial, br_vector3 *pRay_pos, br_vector3 *pRay_dir, br_scalar pT, int pF, int pE, int pV, br_vector3 *pPoint, br_vector2 *pMap, void *pArg) {
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

    return original_FindHighestPolyCallBack__finteray(pModel, pMaterial, pRay_pos, pRay_dir, pT, pF, pE, pV, pPoint, pMap, pArg);
}

static int(__cdecl*original_FindHighestCallBack__finteray)(br_actor *, br_model *, br_material *, br_vector3 *, br_vector3 *, br_scalar, br_scalar, void *) = (int(__cdecl*)(br_actor *, br_model *, br_material *, br_vector3 *, br_vector3 *, br_scalar, br_scalar, void *))0x004ab584;
CARM95_HOOK_FUNCTION(original_FindHighestCallBack__finteray, FindHighestCallBack__finteray)
int __cdecl FindHighestCallBack__finteray(br_actor *pActor, br_model *pModel, br_material *pMaterial, br_vector3 *pRay_pos, br_vector3 *pRay_dir, br_scalar pT_near, br_scalar pT_far, void *pArg) {
    LOG_TRACE("(%p, %p, %p, %p, %p, %f, %f, %p)", pActor, pModel, pMaterial, pRay_pos, pRay_dir, pT_near, pT_far, pArg);

    (void)pActor;
    (void)pModel;
    (void)pMaterial;
    (void)pRay_pos;
    (void)pRay_dir;
    (void)pT_near;
    (void)pT_far;
    (void)pArg;

    return original_FindHighestCallBack__finteray(pActor, pModel, pMaterial, pRay_pos, pRay_dir, pT_near, pT_far, pArg);
}

static void(__cdecl*original_FindFace)(br_vector3 *, br_vector3 *, br_vector3 *, br_scalar *, br_material **) = (void(__cdecl*)(br_vector3 *, br_vector3 *, br_vector3 *, br_scalar *, br_material **))0x004ab47d;
CARM95_HOOK_FUNCTION(original_FindFace, FindFace)
void __cdecl FindFace(br_vector3 *pPosition, br_vector3 *pDir, br_vector3 *nor, br_scalar *t, br_material **material) {
    int group;
    LOG_TRACE("(%p, %p, %p, %p, %p)", pPosition, pDir, nor, t, material);

    (void)pPosition;
    (void)pDir;
    (void)nor;
    (void)t;
    (void)material;
    (void)group;

    original_FindFace(pPosition, pDir, nor, t, material);
}

static void(__cdecl*original_EnablePlingMaterials)() = (void(__cdecl*)())0x004abed5;
CARM95_HOOK_FUNCTION(original_EnablePlingMaterials, EnablePlingMaterials)
void __cdecl EnablePlingMaterials() {
    LOG_TRACE("()");


    original_EnablePlingMaterials();
}

static void(__cdecl*original_DisablePlingMaterials)() = (void(__cdecl*)())0x004abeea;
CARM95_HOOK_FUNCTION(original_DisablePlingMaterials, DisablePlingMaterials)
void __cdecl DisablePlingMaterials() {
    LOG_TRACE("()");


    original_DisablePlingMaterials();
}

static void(__cdecl*original_CheckSingleFace)(tFace_ref *, br_vector3 *, br_vector3 *, br_vector3 *, br_scalar *) = (void(__cdecl*)(tFace_ref *, br_vector3 *, br_vector3 *, br_vector3 *, br_scalar *))0x004abeff;
CARM95_HOOK_FUNCTION(original_CheckSingleFace, CheckSingleFace)
void __cdecl CheckSingleFace(tFace_ref *pFace, br_vector3 *ray_pos, br_vector3 *ray_dir, br_vector3 *normal, br_scalar *rt) {
    br_scalar t;
    br_scalar numerator;
    br_scalar d;
    br_vector3 p;
    br_vector3 tv;
    int axis_m;
    int axis_0;
    int axis_1;
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
    double f_numerator;
    br_material *this_material;
    LOG_TRACE("(%p, %p, %p, %p, %p)", pFace, ray_pos, ray_dir, normal, rt);

    (void)pFace;
    (void)ray_pos;
    (void)ray_dir;
    (void)normal;
    (void)rt;
    (void)t;
    (void)numerator;
    (void)d;
    (void)p;
    (void)tv;
    (void)axis_m;
    (void)axis_0;
    (void)axis_1;
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
    (void)f_numerator;
    (void)this_material;

    original_CheckSingleFace(pFace, ray_pos, ray_dir, normal, rt);
}

static void(__cdecl*original_MultiRayCheckSingleFace)(int, tFace_ref *, br_vector3 *, br_vector3 *, br_vector3 *, br_scalar *) = (void(__cdecl*)(int, tFace_ref *, br_vector3 *, br_vector3 *, br_vector3 *, br_scalar *))0x004ac3b7;
CARM95_HOOK_FUNCTION(original_MultiRayCheckSingleFace, MultiRayCheckSingleFace)
void __cdecl MultiRayCheckSingleFace(int pNum_rays, tFace_ref *pFace, br_vector3 *ray_pos, br_vector3 *ray_dir, br_vector3 *normal, br_scalar *rt) {
    int i;
    br_scalar t[4];
    br_scalar numerator;
    br_scalar d;
    br_vector3 p[4];
    br_vector3 tv;
    int axis_m;
    int axis_0;
    int axis_1;
    double u0[4];
    double u1;
    double u2;
    double v0[4];
    double v1;
    double v2;
    br_scalar v0i1;
    br_scalar v0i2;
    double alpha;
    double beta;
    double f_d;
    double f_n;
    double f_numerator;
    br_material *this_material;
    LOG_TRACE("(%d, %p, %p, %p, %p, %p)", pNum_rays, pFace, ray_pos, ray_dir, normal, rt);

    (void)pNum_rays;
    (void)pFace;
    (void)ray_pos;
    (void)ray_dir;
    (void)normal;
    (void)rt;
    (void)i;
    (void)t;
    (void)numerator;
    (void)d;
    (void)p;
    (void)tv;
    (void)axis_m;
    (void)axis_0;
    (void)axis_1;
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
    (void)f_numerator;
    (void)this_material;

    original_MultiRayCheckSingleFace(pNum_rays, pFace, ray_pos, ray_dir, normal, rt);
}

static void(__cdecl*original_GetNewBoundingBox)(br_bounds *, br_bounds *, br_matrix34 *) = (void(__cdecl*)(br_bounds *, br_bounds *, br_matrix34 *))0x004acaa2;
CARM95_HOOK_FUNCTION(original_GetNewBoundingBox, GetNewBoundingBox)
void __cdecl GetNewBoundingBox(br_bounds *b2, br_bounds *b1, br_matrix34 *m) {
    br_vector3 a;
    br_vector3 c[3];
    int j;
    LOG_TRACE("(%p, %p, %p)", b2, b1, m);

    (void)b2;
    (void)b1;
    (void)m;
    (void)a;
    (void)c;
    (void)j;

    original_GetNewBoundingBox(b2, b1, m);
}

static int(__cdecl*original_FindFacesInBox)(tBounds *, tFace_ref *, int) = (int(__cdecl*)(tBounds *, tFace_ref *, int))0x004accae;
CARM95_HOOK_FUNCTION(original_FindFacesInBox, FindFacesInBox)
int __cdecl FindFacesInBox(tBounds *bnds, tFace_ref *face_list, int max_face) {
    br_vector3 a;
    br_vector3 b;
    br_vector3 c[3];
    int i;
    int j;
    int x;
    int z;
    tU8 cx_min;
    tU8 cx_max;
    tU8 cz_min;
    tU8 cz_max;
    tTrack_spec *track_spec;
    LOG_TRACE("(%p, %p, %d)", bnds, face_list, max_face);

    (void)bnds;
    (void)face_list;
    (void)max_face;
    (void)a;
    (void)b;
    (void)c;
    (void)i;
    (void)j;
    (void)x;
    (void)z;
    (void)cx_min;
    (void)cx_max;
    (void)cz_min;
    (void)cz_max;
    (void)track_spec;

    return original_FindFacesInBox(bnds, face_list, max_face);
}

static int(__cdecl*original_FindFacesInBox2)(tBounds *, tFace_ref *, int) = (int(__cdecl*)(tBounds *, tFace_ref *, int))0x004ad176;
CARM95_HOOK_FUNCTION(original_FindFacesInBox2, FindFacesInBox2)
int __cdecl FindFacesInBox2(tBounds *bnds, tFace_ref *face_list, int max_face) {
    br_vector3 a;
    br_vector3 b;
    br_vector3 c[3];
    int i;
    int j;
    LOG_TRACE("(%p, %p, %d)", bnds, face_list, max_face);

    (void)bnds;
    (void)face_list;
    (void)max_face;
    (void)a;
    (void)b;
    (void)c;
    (void)i;
    (void)j;

    return original_FindFacesInBox2(bnds, face_list, max_face);
}

static int(__cdecl*original_ActorBoxPick)(tBounds *, br_actor *, br_model *, br_material *, tFace_ref *, int, br_matrix34 *) = (int(__cdecl*)(tBounds *, br_actor *, br_model *, br_material *, tFace_ref *, int, br_matrix34 *))0x004ad45b;
CARM95_HOOK_FUNCTION(original_ActorBoxPick, ActorBoxPick)
int __cdecl ActorBoxPick(tBounds *bnds, br_actor *ap, br_model *model, br_material *material, tFace_ref *face_list, int max_face, br_matrix34 *pMat) {
    br_model *this_model;
    br_material *this_material;
    int i;
    int n;
    int test_children;
    br_actor *a;
    br_actor *next_a;
    br_matrix34 mat;
    br_matrix34 mat2;
    br_matrix34 invmat;
    br_matrix34 box_to_actor;
    tBounds new_bounds;
    br_bounds br_bnds;
    LOG_TRACE("(%p, %p, %p, %p, %p, %d, %p)", bnds, ap, model, material, face_list, max_face, pMat);

    (void)bnds;
    (void)ap;
    (void)model;
    (void)material;
    (void)face_list;
    (void)max_face;
    (void)pMat;
    (void)this_model;
    (void)this_material;
    (void)i;
    (void)n;
    (void)test_children;
    (void)a;
    (void)next_a;
    (void)mat;
    (void)mat2;
    (void)invmat;
    (void)box_to_actor;
    (void)new_bounds;
    (void)br_bnds;

    return original_ActorBoxPick(bnds, ap, model, material, face_list, max_face, pMat);
}

static int(__cdecl*original_ModelPickBox)(br_actor *, tBounds *, br_model *, br_material *, tFace_ref *, int, br_matrix34 *) = (int(__cdecl*)(br_actor *, tBounds *, br_model *, br_material *, tFace_ref *, int, br_matrix34 *))0x004ad8ce;
CARM95_HOOK_FUNCTION(original_ModelPickBox, ModelPickBox)
int __cdecl ModelPickBox(br_actor *actor, tBounds *bnds, br_model *model, br_material *model_material, tFace_ref *face_list, int max_face, br_matrix34 *pMat) {
    int f;
    int i;
    int n;
    int group;
    DR_FACE *fp;
    int v1;
    int v2;
    int v3;
    br_vector3 polygon[12];
    br_vector3 a;
    br_vector3 tv;
    br_scalar t;
    struct v11model *prepared;
    LOG_TRACE("(%p, %p, %p, %p, %p, %d, %p)", actor, bnds, model, model_material, face_list, max_face, pMat);

    (void)actor;
    (void)bnds;
    (void)model;
    (void)model_material;
    (void)face_list;
    (void)max_face;
    (void)pMat;
    (void)f;
    (void)i;
    (void)n;
    (void)group;
    (void)fp;
    (void)v1;
    (void)v2;
    (void)v3;
    (void)polygon;
    (void)a;
    (void)tv;
    (void)t;
    (void)prepared;

    return original_ModelPickBox(actor, bnds, model, model_material, face_list, max_face, pMat);
}

static void(__cdecl*original_ClipToPlaneGE)(br_vector3 *, int *, int, br_scalar) = (void(__cdecl*)(br_vector3 *, int *, int, br_scalar))0x004ae5b5;
CARM95_HOOK_FUNCTION(original_ClipToPlaneGE, ClipToPlaneGE)
void __cdecl ClipToPlaneGE(br_vector3 *p, int *nv, int i, br_scalar limit) {
    int last_vertex;
    int j;
    int vertex;
    int k;
    br_vector3 p2[12];
    LOG_TRACE("(%p, %p, %d, %f)", p, nv, i, limit);

    (void)p;
    (void)nv;
    (void)i;
    (void)limit;
    (void)last_vertex;
    (void)j;
    (void)vertex;
    (void)k;
    (void)p2;

    original_ClipToPlaneGE(p, nv, i, limit);
}

static void(__cdecl*original_ClipToPlaneLE)(br_vector3 *, int *, int, br_scalar) = (void(__cdecl*)(br_vector3 *, int *, int, br_scalar))0x004ae89f;
CARM95_HOOK_FUNCTION(original_ClipToPlaneLE, ClipToPlaneLE)
void __cdecl ClipToPlaneLE(br_vector3 *p, int *nv, int i, br_scalar limit) {
    int last_vertex;
    int j;
    int vertex;
    int k;
    br_vector3 p2[12];
    LOG_TRACE("(%p, %p, %d, %f)", p, nv, i, limit);

    (void)p;
    (void)nv;
    (void)i;
    (void)limit;
    (void)last_vertex;
    (void)j;
    (void)vertex;
    (void)k;
    (void)p2;

    original_ClipToPlaneLE(p, nv, i, limit);
}

static int(__cdecl*original_BoundsOverlapTest__finteray)(br_bounds *, br_bounds *) = (int(__cdecl*)(br_bounds *, br_bounds *))0x004aeb89;
CARM95_HOOK_FUNCTION(original_BoundsOverlapTest__finteray, BoundsOverlapTest__finteray)
int __cdecl BoundsOverlapTest__finteray(br_bounds *b1, br_bounds *b2) {
    LOG_TRACE("(%p, %p)", b1, b2);

    (void)b1;
    (void)b2;

    return original_BoundsOverlapTest__finteray(b1, b2);
}

static int(__cdecl*original_BoundsTransformTest)(br_bounds *, br_bounds *, br_matrix34 *) = (int(__cdecl*)(br_bounds *, br_bounds *, br_matrix34 *))0x004aec32;
CARM95_HOOK_FUNCTION(original_BoundsTransformTest, BoundsTransformTest)
int __cdecl BoundsTransformTest(br_bounds *b1, br_bounds *b2, br_matrix34 *M) {
    br_scalar val;
    br_vector3 o;
    LOG_TRACE("(%p, %p, %p)", b1, b2, M);

    (void)b1;
    (void)b2;
    (void)M;
    (void)val;
    (void)o;

    return original_BoundsTransformTest(b1, b2, M);
}

static int(__cdecl*original_LineBoxColl)(br_vector3 *, br_vector3 *, br_bounds *, br_vector3 *) = (int(__cdecl*)(br_vector3 *, br_vector3 *, br_bounds *, br_vector3 *))0x004af126;
CARM95_HOOK_FUNCTION(original_LineBoxColl, LineBoxColl)
int __cdecl LineBoxColl(br_vector3 *o, br_vector3 *p, br_bounds *pB, br_vector3 *pHit_point) {
    br_vector3 dir;
    int inside;
    int quad[3];
    int i;
    int which_plane;
    br_scalar max_t[3];
    br_scalar cp[3];
    LOG_TRACE("(%p, %p, %p, %p)", o, p, pB, pHit_point);

    (void)o;
    (void)p;
    (void)pB;
    (void)pHit_point;
    (void)dir;
    (void)inside;
    (void)quad;
    (void)i;
    (void)which_plane;
    (void)max_t;
    (void)cp;

    return original_LineBoxColl(o, p, pB, pHit_point);
}

static int(__cdecl*original_SphereBoxIntersection)(br_bounds *, br_vector3 *, br_scalar, br_vector3 *) = (int(__cdecl*)(br_bounds *, br_vector3 *, br_scalar, br_vector3 *))0x004af3f0;
CARM95_HOOK_FUNCTION(original_SphereBoxIntersection, SphereBoxIntersection)
int __cdecl SphereBoxIntersection(br_bounds *pB, br_vector3 *pC, br_scalar pR_squared, br_vector3 *pHit_point) {
    int i;
    br_scalar d;
    LOG_TRACE("(%p, %p, %f, %p)", pB, pC, pR_squared, pHit_point);

    (void)pB;
    (void)pC;
    (void)pR_squared;
    (void)pHit_point;
    (void)i;
    (void)d;

    return original_SphereBoxIntersection(pB, pC, pR_squared, pHit_point);
}

static int(__cdecl*original_LineBoxCollWithSphere)(br_vector3 *, br_vector3 *, br_bounds *, br_vector3 *) = (int(__cdecl*)(br_vector3 *, br_vector3 *, br_bounds *, br_vector3 *))0x004af4d2;
CARM95_HOOK_FUNCTION(original_LineBoxCollWithSphere, LineBoxCollWithSphere)
int __cdecl LineBoxCollWithSphere(br_vector3 *o, br_vector3 *p, br_bounds *pB, br_vector3 *pHit_point) {
    int i;
    int plane;
    LOG_TRACE("(%p, %p, %p, %p)", o, p, pB, pHit_point);

    (void)o;
    (void)p;
    (void)pB;
    (void)pHit_point;
    (void)i;
    (void)plane;

    return original_LineBoxCollWithSphere(o, p, pB, pHit_point);
}

static int(__cdecl*original_CompVert)(int, int) = (int(__cdecl*)(int, int))0x004af90e;
CARM95_HOOK_FUNCTION(original_CompVert, CompVert)
int __cdecl CompVert(int v1, int v2) {
    br_vertex *vl;
    br_vector3 tv;
    br_vector2 tv2;
    LOG_TRACE("(%d, %d)", v1, v2);

    (void)v1;
    (void)v2;
    (void)vl;
    (void)tv;
    (void)tv2;

    return original_CompVert(v1, v2);
}

static void(__cdecl*original_SetFacesGroup)(int) = (void(__cdecl*)(int))0x004af7d4;
CARM95_HOOK_FUNCTION(original_SetFacesGroup, SetFacesGroup)
void __cdecl SetFacesGroup(int pFace) {
    int f;
    int v;
    int i;
    LOG_TRACE("(%d)", pFace);

    (void)pFace;
    (void)f;
    (void)v;
    (void)i;

    original_SetFacesGroup(pFace);
}

static void(__cdecl*original_SelectFace)(br_vector3 *) = (void(__cdecl*)(br_vector3 *))0x004af5e8;
CARM95_HOOK_FUNCTION(original_SelectFace, SelectFace)
void __cdecl SelectFace(br_vector3 *pDir) {
    tCar_spec *c;
    br_vector3 dir;
    br_vector3 normal;
    br_scalar t;
    br_model *old_model;
    int i;
    LOG_TRACE("(%p)", pDir);

    (void)pDir;
    (void)c;
    (void)dir;
    (void)normal;
    (void)t;
    (void)old_model;
    (void)i;

    original_SelectFace(pDir);
}

static void(__cdecl*original_GetTilingLimits)(br_vector2 *, br_vector2 *) = (void(__cdecl*)(br_vector2 *, br_vector2 *))0x004afa2a;
CARM95_HOOK_FUNCTION(original_GetTilingLimits, GetTilingLimits)
void __cdecl GetTilingLimits(br_vector2 *min, br_vector2 *max) {
    int f;
    int i;
    int j;
    br_vertex *verts;
    br_face *faces;
    LOG_TRACE("(%p, %p)", min, max);

    (void)min;
    (void)max;
    (void)f;
    (void)i;
    (void)j;
    (void)verts;
    (void)faces;

    original_GetTilingLimits(min, max);
}

static void(__cdecl*original_Scale)(int, int) = (void(__cdecl*)(int, int))0x004afbf3;
CARM95_HOOK_FUNCTION(original_Scale, Scale)
void __cdecl Scale(int pD, int factor) {
    br_vector2 min;
    br_vector2 max;
    int f;
    int v;
    br_scalar d;
    br_vertex *verts;
    br_face *faces;
    LOG_TRACE("(%d, %d)", pD, factor);

    (void)pD;
    (void)factor;
    (void)min;
    (void)max;
    (void)f;
    (void)v;
    (void)d;
    (void)verts;
    (void)faces;

    original_Scale(pD, factor);
}

static void(__cdecl*original_ScaleUpX)() = (void(__cdecl*)())0x004afbdc;
CARM95_HOOK_FUNCTION(original_ScaleUpX, ScaleUpX)
void __cdecl ScaleUpX() {
    LOG_TRACE("()");


    original_ScaleUpX();
}

static void(__cdecl*original_ScaleDnX)() = (void(__cdecl*)())0x004afd9a;
CARM95_HOOK_FUNCTION(original_ScaleDnX, ScaleDnX)
void __cdecl ScaleDnX() {
    LOG_TRACE("()");


    original_ScaleDnX();
}

static void(__cdecl*original_ScaleUpY)() = (void(__cdecl*)())0x004afdb1;
CARM95_HOOK_FUNCTION(original_ScaleUpY, ScaleUpY)
void __cdecl ScaleUpY() {
    LOG_TRACE("()");


    original_ScaleUpY();
}

static void(__cdecl*original_ScaleDnY)() = (void(__cdecl*)())0x004afdc8;
CARM95_HOOK_FUNCTION(original_ScaleDnY, ScaleDnY)
void __cdecl ScaleDnY() {
    LOG_TRACE("()");


    original_ScaleDnY();
}

static void(__cdecl*original_SelectFaceForward)() = (void(__cdecl*)())0x004afddf;
CARM95_HOOK_FUNCTION(original_SelectFaceForward, SelectFaceForward)
void __cdecl SelectFaceForward() {
    br_vector3 dir;
    LOG_TRACE("()");

    (void)dir;

    original_SelectFaceForward();
}

static void(__cdecl*original_SelectFaceDown)() = (void(__cdecl*)())0x004afe2c;
CARM95_HOOK_FUNCTION(original_SelectFaceDown, SelectFaceDown)
void __cdecl SelectFaceDown() {
    br_vector3 dir;
    LOG_TRACE("()");

    (void)dir;

    original_SelectFaceDown();
}

