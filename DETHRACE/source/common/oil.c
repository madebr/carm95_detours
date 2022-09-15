#include "oil.h"

#include "harness/trace.h"

#include "carm95_hooks.h"

#include <stdio.h>
#if 0
char *(* hookvar_gOil_pixie_names )[1];
#endif
#if 0
int * hookvar_gNext_oil_pixie ;
#endif
#if 0
br_scalar * hookvar_gZ_buffer_diff ;
#endif
#if 0
br_scalar * hookvar_gMin_z_diff ;
#endif
#if 0
br_pixelmap *(* hookvar_gOil_pixies )[1];
#endif
tOil_spill_info(* hookvar_gOily_spills )[15] = (void*)0x00551dd0;

void InitOilSpills() {
    int i;
    br_model *the_model;
    br_material *the_material;
    LOG_TRACE("()");

    (void)i;
    (void)the_model;
    (void)the_material;

    NOT_IMPLEMENTED();
}

static void(*original_ResetOilSpills)() = (void(*)())0x00412859;
CARM95_HOOK_FUNCTION(original_ResetOilSpills, ResetOilSpills)
void ResetOilSpills() {
    int i;
    LOG_TRACE("()");

    (void)i;

    original_ResetOilSpills();
}

static void(*original_QueueOilSpill)(tCar_spec *, ...) = (void(*)(tCar_spec *, ...))0x004128c7;
CARM95_HOOK_FUNCTION(original_QueueOilSpill, QueueOilSpill)
void QueueOilSpill(tCar_spec *pCar) {
    int i;
    int oily_index;
    int oldest_one;
    tU32 the_time;
    tU32 oldest_time;
    LOG_TRACE("(%p)", pCar);

    (void)pCar;
    (void)i;
    (void)oily_index;
    (void)oldest_one;
    (void)the_time;
    (void)oldest_time;

    original_QueueOilSpill(pCar);
}

int OKToSpillOil(tOil_spill_info *pOil) {
    br_scalar temp;
    br_scalar size_with_margin;
    br_scalar distance;
    br_scalar mr_dotty;
    br_vector3 v;
    br_vector3 ray_pos;
    br_vector3 ray_dir;
    br_vector3 normal;
    tCar_spec *car;
    int i;
    int face_count;
    int found_one;
    br_angle angle_to_rotate_by;
    tBounds kev_bounds;
    tFace_ref the_list[10];
    tFace_ref *face_ref;
    LOG_TRACE("(%p)", pOil);

    (void)pOil;
    (void)temp;
    (void)size_with_margin;
    (void)distance;
    (void)mr_dotty;
    (void)v;
    (void)ray_pos;
    (void)ray_dir;
    (void)normal;
    (void)car;
    (void)i;
    (void)face_count;
    (void)found_one;
    (void)angle_to_rotate_by;
    (void)kev_bounds;
    (void)the_list;
    (void)face_ref;

    NOT_IMPLEMENTED();
}

static void(*original_Vector3Interpolate)(br_vector3 *, br_vector3 *, br_vector3 *, br_scalar, ...) = (void(*)(br_vector3 *, br_vector3 *, br_vector3 *, br_scalar, ...))0x00412b76;
CARM95_HOOK_FUNCTION(original_Vector3Interpolate, Vector3Interpolate)
void Vector3Interpolate(br_vector3 *pDst, br_vector3 *pFrom, br_vector3 *pTo, br_scalar pP) {
    LOG_TRACE("(%p, %p, %p, %f)", pDst, pFrom, pTo, pP);

    (void)pDst;
    (void)pFrom;
    (void)pTo;
    (void)pP;

    original_Vector3Interpolate(pDst, pFrom, pTo, pP);
}

static void(*original_EnsureGroundDetailVisible)(br_vector3 *, br_vector3 *, br_vector3 *, ...) = (void(*)(br_vector3 *, br_vector3 *, br_vector3 *, ...))0x00412a81;
CARM95_HOOK_FUNCTION(original_EnsureGroundDetailVisible, EnsureGroundDetailVisible)
void EnsureGroundDetailVisible(br_vector3 *pNew_pos, br_vector3 *pGround_normal, br_vector3 *pOld_pos) {
    br_scalar factor;
    br_scalar s;
    br_scalar dist;
    br_vector3 to_camera;
    LOG_TRACE("(%p, %p, %p)", pNew_pos, pGround_normal, pOld_pos);

    (void)pNew_pos;
    (void)pGround_normal;
    (void)pOld_pos;
    (void)factor;
    (void)s;
    (void)dist;
    (void)to_camera;

    original_EnsureGroundDetailVisible(pNew_pos, pGround_normal, pOld_pos);
}

static void(*original_MungeOilsHeightAboveGround)(tOil_spill_info *, ...) = (void(*)(tOil_spill_info *, ...))0x00412bf4;
CARM95_HOOK_FUNCTION(original_MungeOilsHeightAboveGround, MungeOilsHeightAboveGround)
void MungeOilsHeightAboveGround(tOil_spill_info *pOil) {
    LOG_TRACE("(%p)", pOil);

    (void)pOil;

    original_MungeOilsHeightAboveGround(pOil);
}

static void(*original_MungeIndexedOilsHeightAboveGround)(int, ...) = (void(*)(int, ...))0x00412bce;
CARM95_HOOK_FUNCTION(original_MungeIndexedOilsHeightAboveGround, MungeIndexedOilsHeightAboveGround)
void MungeIndexedOilsHeightAboveGround(int pIndex) {
    LOG_TRACE("(%d)", pIndex);

    (void)pIndex;

    original_MungeIndexedOilsHeightAboveGround(pIndex);
}

static void(*original_SetInitialOilStuff)(tOil_spill_info *, br_model *, ...) = (void(*)(tOil_spill_info *, br_model *, ...))0x004137ad;
CARM95_HOOK_FUNCTION(original_SetInitialOilStuff, SetInitialOilStuff)
void SetInitialOilStuff(tOil_spill_info *pOil, br_model *pModel) {
    LOG_TRACE("(%p, %p)", pOil, pModel);

    (void)pOil;
    (void)pModel;

    original_SetInitialOilStuff(pOil, pModel);
}

static void(*original_ProcessOilSpills)(tU32, ...) = (void(*)(tU32, ...))0x00412c20;
CARM95_HOOK_FUNCTION(original_ProcessOilSpills, ProcessOilSpills)
void ProcessOilSpills(tU32 pFrame_period) {
    int i;
    tU32 time;
    br_model *the_model;
    br_scalar grow_amount;
    br_scalar initial_size;
    br_scalar this_size;
    br_vector3 v;
    tNet_message *message;
    LOG_TRACE("(%u)", pFrame_period);

    (void)pFrame_period;
    (void)i;
    (void)time;
    (void)the_model;
    (void)grow_amount;
    (void)initial_size;
    (void)this_size;
    (void)v;
    (void)message;

    original_ProcessOilSpills(pFrame_period);
}

static int(*original_GetOilSpillCount)() = (int(*)())0x00413852;
CARM95_HOOK_FUNCTION(original_GetOilSpillCount, GetOilSpillCount)
int GetOilSpillCount() {
    LOG_TRACE("()");


    return original_GetOilSpillCount();
}

static void(*original_GetOilSpillDetails)(int, br_actor **, br_scalar *, ...) = (void(*)(int, br_actor **, br_scalar *, ...))0x00413867;
CARM95_HOOK_FUNCTION(original_GetOilSpillDetails, GetOilSpillDetails)
void GetOilSpillDetails(int pIndex, br_actor **pActor, br_scalar *pSize) {
    LOG_TRACE("(%d, %p, %p)", pIndex, pActor, pSize);

    (void)pIndex;
    (void)pActor;
    (void)pSize;

    original_GetOilSpillDetails(pIndex, pActor, pSize);
}

static int(*original_PointInSpill)(br_vector3 *, int, ...) = (int(*)(br_vector3 *, int, ...))0x00413b72;
CARM95_HOOK_FUNCTION(original_PointInSpill, PointInSpill)
int PointInSpill(br_vector3 *pV, int pSpill) {
    LOG_TRACE("(%p, %d)", pV, pSpill);

    (void)pV;
    (void)pSpill;

    return original_PointInSpill(pV, pSpill);
}

static void(*original_GetOilFrictionFactors)(tCar_spec *, br_scalar *, br_scalar *, br_scalar *, br_scalar *, ...) = (void(*)(tCar_spec *, br_scalar *, br_scalar *, br_scalar *, br_scalar *, ...))0x004138c7;
CARM95_HOOK_FUNCTION(original_GetOilFrictionFactors, GetOilFrictionFactors)
void GetOilFrictionFactors(tCar_spec *pCar, br_scalar *pFl_factor, br_scalar *pFr_factor, br_scalar *pRl_factor, br_scalar *pRr_factor) {
    int i;
    br_vector3 wheel_world;
    LOG_TRACE("(%p, %p, %p, %p, %p)", pCar, pFl_factor, pFr_factor, pRl_factor, pRr_factor);

    (void)pCar;
    (void)pFl_factor;
    (void)pFr_factor;
    (void)pRl_factor;
    (void)pRr_factor;
    (void)i;
    (void)wheel_world;

    original_GetOilFrictionFactors(pCar, pFl_factor, pFr_factor, pRl_factor, pRr_factor);
}

void AdjustOilSpill(int pIndex, br_matrix34 *pMat, br_scalar pFull_size, br_scalar pGrow_rate, tU32 pSpill_time, tU32 pStop_time, tCar_spec *pCar, br_vector3 *pOriginal_pos, br_pixelmap *pPixelmap) {
    LOG_TRACE("(%d, %p, %f, %f, %u, %u, %p, %p, %p)", pIndex, pMat, pFull_size, pGrow_rate, pSpill_time, pStop_time, pCar, pOriginal_pos, pPixelmap);

    (void)pIndex;
    (void)pMat;
    (void)pFull_size;
    (void)pGrow_rate;
    (void)pSpill_time;
    (void)pStop_time;
    (void)pCar;
    (void)pOriginal_pos;
    (void)pPixelmap;

    NOT_IMPLEMENTED();
}

static void(*original_ReceivedOilSpill)(tNet_contents *, ...) = (void(*)(tNet_contents *, ...))0x00413dc4;
CARM95_HOOK_FUNCTION(original_ReceivedOilSpill, ReceivedOilSpill)
void ReceivedOilSpill(tNet_contents *pContents) {
    int i;
    int oily_index;
    int oldest_one;
    tU32 the_time;
    tU32 oldest_time;
    tCar_spec *car;
    LOG_TRACE("(%p)", pContents);

    (void)pContents;
    (void)i;
    (void)oily_index;
    (void)oldest_one;
    (void)the_time;
    (void)oldest_time;
    (void)car;

    original_ReceivedOilSpill(pContents);
}

