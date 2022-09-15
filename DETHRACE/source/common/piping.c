#include "piping.h"

#include "harness/trace.h"

#include "carm95_hooks.h"

#include <stdio.h>
tU8 ** hookvar_gPipe_buffer_start  = (void*)0x0050ba00;
int * hookvar_gDisable_sound  = (void*)0x0050ba04;
#if 0
int * hookvar_gDisable_advance ;
#endif
#if 0
int * hookvar_gMax_rewind_chunks ;
#endif
float * hookvar_gWall_severity  = (void*)0x0050ba10;
tPipe_reset_proc*(* hookvar_gReset_procs )[32] = (void*)0x0050ba18;
#if 0
tPiped_registration_snapshot(* hookvar_gRegistration_snapshots )[5];
#endif
tPipe_smudge_data ** hookvar_gSmudge_space  = (void*)0x00531ffc;
#if 0
tU32 * hookvar_gOldest_time ;
#endif
#if 0
int * hookvar_gCurrent_snapshot_registration_index ;
#endif
tPipe_chunk ** hookvar_gMr_chunky  = (void*)0x00531fa0;
#if 0
tCar_spec ** hookvar_gCar_ptr ;
#endif
br_vector3 * hookvar_gZero_vector  = (void*)0x00532068;
tPipe_chunk_type(* hookvar_gReentrancy_array )[5] = (void*)0x00532050;
#if 0
tU32 * hookvar_gLast_time ;
#endif
tPipe_model_geometry_data ** hookvar_gModel_geometry_space  = (void*)0x0053204c;
#if 0
tU32 * hookvar_gEnd_time ;
#endif
#if 0
tU32 * hookvar_gTrigger_time ;
#endif
int * hookvar_gReentrancy_count  = (void*)0x00532074;
#if 0
br_vector3 * hookvar_gCar_pos ;
#endif
#if 0
br_vector3 * hookvar_gReference_pos ;
#endif
#if 0
br_scalar * hookvar_gMax_distance ;
#endif
#if 0
tU32 * hookvar_gLoop_abort_time ;
#endif
br_vector3 * hookvar_gWall_impact_point  = (void*)0x00532078;
#if 0
tU8 ** hookvar_gPipe_buffer_working_end ;
#endif
#if 0
tU32 * hookvar_gYoungest_time ;
#endif
tU8 ** hookvar_gPipe_buffer_phys_end  = (void*)0x0053208c;
#if 0
tU8 ** hookvar_gLocal_buffer_record_ptr ;
#endif
tU8 ** hookvar_gPipe_play_ptr  = (void*)0x00532018;
#if 0
tU8 ** hookvar_gEnd_of_session ;
#endif
#if 0
tU8 ** hookvar_gPipe_record_ptr ;
#endif
#if 0
tU8 ** hookvar_gPipe_buffer_oldest ;
#endif
tU32 * hookvar_gPipe_buffer_size  = (void*)0x00532088;
tU8 ** hookvar_gLocal_buffer  = (void*)0x00532014;
tU32 * hookvar_gLocal_buffer_size  = (void*)0x00532090;

static void(*original_GetReducedPos)(br_vector3 *, tReduced_pos *, ...) = (void(*)(br_vector3 *, tReduced_pos *, ...))0x00427ed0;
CARM95_HOOK_FUNCTION(original_GetReducedPos, GetReducedPos)
void GetReducedPos(br_vector3 *v, tReduced_pos *p) {
    LOG_TRACE("(%p, %p)", v, p);

    (void)v;
    (void)p;

    original_GetReducedPos(v, p);
}

static void(*original_SaveReducedPos)(tReduced_pos *, br_vector3 *, ...) = (void(*)(tReduced_pos *, br_vector3 *, ...))0x00427f61;
CARM95_HOOK_FUNCTION(original_SaveReducedPos, SaveReducedPos)
void SaveReducedPos(tReduced_pos *p, br_vector3 *v) {
    br_vector3 tv;
    LOG_TRACE("(%p, %p)", p, v);

    (void)p;
    (void)v;
    (void)tv;

    original_SaveReducedPos(p, v);
}

static int(*original_PipeSearchForwards)() = (int(*)())0x00427fdf;
CARM95_HOOK_FUNCTION(original_PipeSearchForwards, PipeSearchForwards)
int PipeSearchForwards() {
    LOG_TRACE("()");


    return original_PipeSearchForwards();
}

static int(*original_IsActionReplayAvailable)() = (int(*)())0x00428078;
CARM95_HOOK_FUNCTION(original_IsActionReplayAvailable, IsActionReplayAvailable)
int IsActionReplayAvailable() {
    LOG_TRACE("()");


    return original_IsActionReplayAvailable();
}

static int(*original_SomeReplayLeft)() = (int(*)())0x004280a1;
CARM95_HOOK_FUNCTION(original_SomeReplayLeft, SomeReplayLeft)
int SomeReplayLeft() {
    LOG_TRACE("()");


    return original_SomeReplayLeft();
}

static void(*original_DisablePipedSounds)() = (void(*)())0x004280f9;
CARM95_HOOK_FUNCTION(original_DisablePipedSounds, DisablePipedSounds)
void DisablePipedSounds() {
    LOG_TRACE("()");


    original_DisablePipedSounds();
}

static void(*original_EnablePipedSounds)() = (void(*)())0x0042810e;
CARM95_HOOK_FUNCTION(original_EnablePipedSounds, EnablePipedSounds)
void EnablePipedSounds() {
    LOG_TRACE("()");


    original_EnablePipedSounds();
}

static tU32(*original_LengthOfSession)(tPipe_session *, ...) = (tU32(*)(tPipe_session *, ...))0x00428123;
CARM95_HOOK_FUNCTION(original_LengthOfSession, LengthOfSession)
tU32 LengthOfSession(tPipe_session *pSession) {
    int i;
    tU32 running_total;
    tPipe_chunk *the_chunk;
    LOG_TRACE("(%p)", pSession);

    (void)pSession;
    (void)i;
    (void)running_total;
    (void)the_chunk;

    return original_LengthOfSession(pSession);
}

static void(*original_StartPipingSession2)(tPipe_chunk_type, int, ...) = (void(*)(tPipe_chunk_type, int, ...))0x004285e1;
CARM95_HOOK_FUNCTION(original_StartPipingSession2, StartPipingSession2)
void StartPipingSession2(tPipe_chunk_type pThe_type, int pMunge_reentrancy) {
    LOG_TRACE("(%d, %d)", pThe_type, pMunge_reentrancy);

    (void)pThe_type;
    (void)pMunge_reentrancy;

    original_StartPipingSession2(pThe_type, pMunge_reentrancy);
}

static void(*original_StartPipingSession)(tPipe_chunk_type, ...) = (void(*)(tPipe_chunk_type, ...))0x0042868f;
CARM95_HOOK_FUNCTION(original_StartPipingSession, StartPipingSession)
void StartPipingSession(tPipe_chunk_type pThe_type) {
    LOG_TRACE("(%d)", pThe_type);

    (void)pThe_type;

    original_StartPipingSession(pThe_type);
}

static void(*original_EndPipingSession2)(int, ...) = (void(*)(int, ...))0x004286a8;
CARM95_HOOK_FUNCTION(original_EndPipingSession2, EndPipingSession2)
void EndPipingSession2(int pMunge_reentrancy) {
    int a;
    LOG_TRACE("(%d)", pMunge_reentrancy);

    (void)pMunge_reentrancy;
    (void)a;

    original_EndPipingSession2(pMunge_reentrancy);
}

static void(*original_EndPipingSession)() = (void(*)())0x0042884c;
CARM95_HOOK_FUNCTION(original_EndPipingSession, EndPipingSession)
void EndPipingSession() {
    LOG_TRACE("()");


    original_EndPipingSession();
}

static void(*original_AddDataToSession)(int, void *, tU32, ...) = (void(*)(int, void *, tU32, ...))0x00428861;
CARM95_HOOK_FUNCTION(original_AddDataToSession, AddDataToSession)
void AddDataToSession(int pSubject_index, void *pData, tU32 pData_length) {
    tU32 temp_buffer_size;
    int variable_for_breaking_on;
    LOG_TRACE("(%d, %p, %u)", pSubject_index, pData, pData_length);

    (void)pSubject_index;
    (void)pData;
    (void)pData_length;
    (void)temp_buffer_size;
    (void)variable_for_breaking_on;

    original_AddDataToSession(pSubject_index, pData, pData_length);
}

static void(*original_AddModelGeometryToPipingSession)(tU16, int, int, tChanged_vertex *, ...) = (void(*)(tU16, int, int, tChanged_vertex *, ...))0x00428904;
CARM95_HOOK_FUNCTION(original_AddModelGeometryToPipingSession, AddModelGeometryToPipingSession)
void AddModelGeometryToPipingSession(tU16 pCar_ID, int pModel_index, int pVertex_count, tChanged_vertex *pCoordinates) {
    tU32 data_size;
    LOG_TRACE("(%u, %d, %d, %p)", pCar_ID, pModel_index, pVertex_count, pCoordinates);

    (void)pCar_ID;
    (void)pModel_index;
    (void)pVertex_count;
    (void)pCoordinates;
    (void)data_size;

    original_AddModelGeometryToPipingSession(pCar_ID, pModel_index, pVertex_count, pCoordinates);
}

static void(*original_AddSmudgeToPipingSession)(tU16, int, int, tSmudged_vertex *, ...) = (void(*)(tU16, int, int, tSmudged_vertex *, ...))0x0042898f;
CARM95_HOOK_FUNCTION(original_AddSmudgeToPipingSession, AddSmudgeToPipingSession)
void AddSmudgeToPipingSession(tU16 pCar_ID, int pModel_index, int pVertex_count, tSmudged_vertex *pCoordinates) {
    tU32 data_size;
    LOG_TRACE("(%u, %d, %d, %p)", pCar_ID, pModel_index, pVertex_count, pCoordinates);

    (void)pCar_ID;
    (void)pModel_index;
    (void)pVertex_count;
    (void)pCoordinates;
    (void)data_size;

    original_AddSmudgeToPipingSession(pCar_ID, pModel_index, pVertex_count, pCoordinates);
}

static void(*original_AddPedestrianToPipingSession)(int, br_matrix34 *, tU8, tU8, tS8, int, tU16, float, br_scalar, br_vector3 *, ...) = (void(*)(int, br_matrix34 *, tU8, tU8, tS8, int, tU16, float, br_scalar, br_vector3 *, ...))0x00428a1a;
CARM95_HOOK_FUNCTION(original_AddPedestrianToPipingSession, AddPedestrianToPipingSession)
void AddPedestrianToPipingSession(int pPedestrian_index, br_matrix34 *pTrans, tU8 pAction_index, tU8 pFrame_index, tS8 pHit_points, int pDone_initial, tU16 pParent_ID, float pSpin_period, br_scalar pJump_magnitude, br_vector3 *pOffset) {
    tPipe_pedestrian_data data;
    tU32 data_size;
    LOG_TRACE("(%d, %p, %u, %u, %d, %d, %u, %f, %f, %p)", pPedestrian_index, pTrans, pAction_index, pFrame_index, pHit_points, pDone_initial, pParent_ID, pSpin_period, pJump_magnitude, pOffset);

    (void)pPedestrian_index;
    (void)pTrans;
    (void)pAction_index;
    (void)pFrame_index;
    (void)pHit_points;
    (void)pDone_initial;
    (void)pParent_ID;
    (void)pSpin_period;
    (void)pJump_magnitude;
    (void)pOffset;
    (void)data;
    (void)data_size;

    original_AddPedestrianToPipingSession(pPedestrian_index, pTrans, pAction_index, pFrame_index, pHit_points, pDone_initial, pParent_ID, pSpin_period, pJump_magnitude, pOffset);
}

static void(*original_AddSparkToPipingSession)(int, br_vector3 *, br_vector3 *, ...) = (void(*)(int, br_vector3 *, br_vector3 *, ...))0x00428af9;
CARM95_HOOK_FUNCTION(original_AddSparkToPipingSession, AddSparkToPipingSession)
void AddSparkToPipingSession(int pSpark_index, br_vector3 *pPos, br_vector3 *pV) {
    tPipe_spark_data data;
    LOG_TRACE("(%d, %p, %p)", pSpark_index, pPos, pV);

    (void)pSpark_index;
    (void)pPos;
    (void)pV;
    (void)data;

    original_AddSparkToPipingSession(pSpark_index, pPos, pV);
}

static void(*original_AddShrapnelToPipingSession)(int, br_vector3 *, tU16, br_material *, ...) = (void(*)(int, br_vector3 *, tU16, br_material *, ...))0x00428b4d;
CARM95_HOOK_FUNCTION(original_AddShrapnelToPipingSession, AddShrapnelToPipingSession)
void AddShrapnelToPipingSession(int pShrapnel_index, br_vector3 *pPos, tU16 pAge, br_material *pMaterial) {
    tPipe_shrapnel_data data;
    tU32 data_size;
    LOG_TRACE("(%d, %p, %u, %p)", pShrapnel_index, pPos, pAge, pMaterial);

    (void)pShrapnel_index;
    (void)pPos;
    (void)pAge;
    (void)pMaterial;
    (void)data;
    (void)data_size;

    original_AddShrapnelToPipingSession(pShrapnel_index, pPos, pAge, pMaterial);
}

static void(*original_AddScreenWobbleToPipingSession)(int, int, ...) = (void(*)(int, int, ...))0x00428bb4;
CARM95_HOOK_FUNCTION(original_AddScreenWobbleToPipingSession, AddScreenWobbleToPipingSession)
void AddScreenWobbleToPipingSession(int pWobble_x, int pWobble_y) {
    tPipe_screen_shake_data data;
    LOG_TRACE("(%d, %d)", pWobble_x, pWobble_y);

    (void)pWobble_x;
    (void)pWobble_y;
    (void)data;

    original_AddScreenWobbleToPipingSession(pWobble_x, pWobble_y);
}

static void(*original_AddGrooveStopToPipingSession)(int, br_matrix34 *, int, int, float, float, ...) = (void(*)(int, br_matrix34 *, int, int, float, float, ...))0x00428bde;
CARM95_HOOK_FUNCTION(original_AddGrooveStopToPipingSession, AddGrooveStopToPipingSession)
void AddGrooveStopToPipingSession(int pGroove_index, br_matrix34 *pMatrix, int pPath_interrupt, int pObject_interrupt, float pPath_resumption, float pObject_resumption) {
    tPipe_groove_stop_data data;
    LOG_TRACE("(%d, %p, %d, %d, %f, %f)", pGroove_index, pMatrix, pPath_interrupt, pObject_interrupt, pPath_resumption, pObject_resumption);

    (void)pGroove_index;
    (void)pMatrix;
    (void)pPath_interrupt;
    (void)pObject_interrupt;
    (void)pPath_resumption;
    (void)pObject_resumption;
    (void)data;

    original_AddGrooveStopToPipingSession(pGroove_index, pMatrix, pPath_interrupt, pObject_interrupt, pPath_resumption, pObject_resumption);
}

static void(*original_AddNonCarToPipingSession)(int, br_actor *, ...) = (void(*)(int, br_actor *, ...))0x00428c26;
CARM95_HOOK_FUNCTION(original_AddNonCarToPipingSession, AddNonCarToPipingSession)
void AddNonCarToPipingSession(int pIndex, br_actor *pActor) {
    tPipe_non_car_data data;
    LOG_TRACE("(%d, %p)", pIndex, pActor);

    (void)pIndex;
    (void)pActor;
    (void)data;

    original_AddNonCarToPipingSession(pIndex, pActor);
}

static void(*original_AddSmokeToPipingSession)(int, tU8, br_vector3 *, br_scalar, br_scalar, ...) = (void(*)(int, tU8, br_vector3 *, br_scalar, br_scalar, ...))0x00428c5f;
CARM95_HOOK_FUNCTION(original_AddSmokeToPipingSession, AddSmokeToPipingSession)
void AddSmokeToPipingSession(int pIndex, tU8 pType, br_vector3 *pPos, br_scalar pRadius, br_scalar pStrength) {
    tPipe_smoke_data data;
    LOG_TRACE("(%d, %u, %p, %f, %f)", pIndex, pType, pPos, pRadius, pStrength);

    (void)pIndex;
    (void)pType;
    (void)pPos;
    (void)pRadius;
    (void)pStrength;
    (void)data;

    original_AddSmokeToPipingSession(pIndex, pType, pPos, pRadius, pStrength);
}

static void(*original_AddSmokeColumnToPipingSession)(int, tCar_spec *, int, int, ...) = (void(*)(int, tCar_spec *, int, int, ...))0x00428cb8;
CARM95_HOOK_FUNCTION(original_AddSmokeColumnToPipingSession, AddSmokeColumnToPipingSession)
void AddSmokeColumnToPipingSession(int pIndex, tCar_spec *pCar, int pVertex, int pColour) {
    tPipe_smoke_column_data data;
    LOG_TRACE("(%d, %p, %d, %d)", pIndex, pCar, pVertex, pColour);

    (void)pIndex;
    (void)pCar;
    (void)pVertex;
    (void)pColour;
    (void)data;

    original_AddSmokeColumnToPipingSession(pIndex, pCar, pVertex, pColour);
}

static void(*original_AddFlameToPipingSession)(int, int, br_scalar, br_scalar, br_scalar, br_scalar, ...) = (void(*)(int, int, br_scalar, br_scalar, br_scalar, br_scalar, ...))0x00428cf7;
CARM95_HOOK_FUNCTION(original_AddFlameToPipingSession, AddFlameToPipingSession)
void AddFlameToPipingSession(int pIndex, int pFrame_count, br_scalar pScale_x, br_scalar pScale_y, br_scalar pOffset_x, br_scalar pOffset_z) {
    tPipe_flame_data data;
    LOG_TRACE("(%d, %d, %f, %f, %f, %f)", pIndex, pFrame_count, pScale_x, pScale_y, pOffset_x, pOffset_z);

    (void)pIndex;
    (void)pFrame_count;
    (void)pScale_x;
    (void)pScale_y;
    (void)pOffset_x;
    (void)pOffset_z;
    (void)data;

    original_AddFlameToPipingSession(pIndex, pFrame_count, pScale_x, pScale_y, pOffset_x, pOffset_z);
}

static void(*original_AddSplashToPipingSession)(tCollision_info *, ...) = (void(*)(tCollision_info *, ...))0x00428d36;
CARM95_HOOK_FUNCTION(original_AddSplashToPipingSession, AddSplashToPipingSession)
void AddSplashToPipingSession(tCollision_info *pCar) {
    tPipe_splash_data data;
    LOG_TRACE("(%p)", pCar);

    (void)pCar;
    (void)data;

    original_AddSplashToPipingSession(pCar);
}

static void(*original_AddOilSpillToPipingSession)(int, br_matrix34 *, br_scalar, br_scalar, tU32, tU32, tCar_spec *, br_vector3 *, br_pixelmap *, ...) = (void(*)(int, br_matrix34 *, br_scalar, br_scalar, tU32, tU32, tCar_spec *, br_vector3 *, br_pixelmap *, ...))0x00428da1;
CARM95_HOOK_FUNCTION(original_AddOilSpillToPipingSession, AddOilSpillToPipingSession)
void AddOilSpillToPipingSession(int pIndex, br_matrix34 *pMat, br_scalar pFull_size, br_scalar pGrow_rate, tU32 pSpill_time, tU32 pStop_time, tCar_spec *pCar, br_vector3 *pOriginal_pos, br_pixelmap *pPixelmap) {
    tPipe_oil_spill_data data;
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
    (void)data;

    original_AddOilSpillToPipingSession(pIndex, pMat, pFull_size, pGrow_rate, pSpill_time, pStop_time, pCar, pOriginal_pos, pPixelmap);
}

static void(*original_AddFrameFinishToPipingSession)(tU32, ...) = (void(*)(tU32, ...))0x00428e0f;
CARM95_HOOK_FUNCTION(original_AddFrameFinishToPipingSession, AddFrameFinishToPipingSession)
void AddFrameFinishToPipingSession(tU32 pThe_time) {
    tPipe_frame_boundary_data data;
    LOG_TRACE("(%u)", pThe_time);

    (void)pThe_time;
    (void)data;

    original_AddFrameFinishToPipingSession(pThe_time);
}

static void(*original_AddCarToPipingSession)(int, br_matrix34 *, br_vector3 *, float, float, float, float, float, float, br_scalar, int, int, ...) = (void(*)(int, br_matrix34 *, br_vector3 *, float, float, float, float, float, float, br_scalar, int, int, ...))0x00428e33;
CARM95_HOOK_FUNCTION(original_AddCarToPipingSession, AddCarToPipingSession)
void AddCarToPipingSession(int pCar_ID, br_matrix34 *pCar_mat, br_vector3 *pCar_velocity, float pSpeedo_speed, float pLf_sus_position, float pRf_sus_position, float pLr_sus_position, float pRr_sus_position, float pSteering_angle, br_scalar pRevs, int pGear, int pFrame_coll_flag) {
    tPipe_car_data data;
    LOG_TRACE("(%d, %p, %p, %f, %f, %f, %f, %f, %f, %f, %d, %d)", pCar_ID, pCar_mat, pCar_velocity, pSpeedo_speed, pLf_sus_position, pRf_sus_position, pLr_sus_position, pRr_sus_position, pSteering_angle, pRevs, pGear, pFrame_coll_flag);

    (void)pCar_ID;
    (void)pCar_mat;
    (void)pCar_velocity;
    (void)pSpeedo_speed;
    (void)pLf_sus_position;
    (void)pRf_sus_position;
    (void)pLr_sus_position;
    (void)pRr_sus_position;
    (void)pSteering_angle;
    (void)pRevs;
    (void)pGear;
    (void)pFrame_coll_flag;
    (void)data;

    original_AddCarToPipingSession(pCar_ID, pCar_mat, pCar_velocity, pSpeedo_speed, pLf_sus_position, pRf_sus_position, pLr_sus_position, pRr_sus_position, pSteering_angle, pRevs, pGear, pFrame_coll_flag);
}

static void(*original_AddSoundToPipingSession)(tS3_outlet_ptr, int, tS3_volume, tS3_volume, tS3_pitch, br_vector3 *, ...) = (void(*)(tS3_outlet_ptr, int, tS3_volume, tS3_volume, tS3_pitch, br_vector3 *, ...))0x00428f38;
CARM95_HOOK_FUNCTION(original_AddSoundToPipingSession, AddSoundToPipingSession)
void AddSoundToPipingSession(tS3_outlet_ptr pOutlet, int pSound_index, tS3_volume pL_volume, tS3_volume pR_volume, tS3_pitch pPitch, br_vector3 *pPos) {
    tPipe_sound_data data;
    LOG_TRACE("(\"%s\", %d, %d, %d, %d, %p)", pOutlet, pSound_index, pL_volume, pR_volume, pPitch, pPos);

    (void)pOutlet;
    (void)pSound_index;
    (void)pL_volume;
    (void)pR_volume;
    (void)pPitch;
    (void)pPos;
    (void)data;

    original_AddSoundToPipingSession(pOutlet, pSound_index, pL_volume, pR_volume, pPitch, pPos);
}

static void(*original_AddDamageToPipingSession)(int, tS8 *, ...) = (void(*)(int, tS8 *, ...))0x00428fb5;
CARM95_HOOK_FUNCTION(original_AddDamageToPipingSession, AddDamageToPipingSession)
void AddDamageToPipingSession(int pCar_ID, tS8 *pDifferences) {
    tPipe_damage_data data;
    int i;
    LOG_TRACE("(%d, %p)", pCar_ID, pDifferences);

    (void)pCar_ID;
    (void)pDifferences;
    (void)data;
    (void)i;

    original_AddDamageToPipingSession(pCar_ID, pDifferences);
}

static void(*original_AddSpecialToPipingSession)(tSpecial_type, ...) = (void(*)(tSpecial_type, ...))0x00429003;
CARM95_HOOK_FUNCTION(original_AddSpecialToPipingSession, AddSpecialToPipingSession)
void AddSpecialToPipingSession(tSpecial_type pType) {
    tPipe_special_data data;
    LOG_TRACE("(%d)", pType);

    (void)pType;
    (void)data;

    original_AddSpecialToPipingSession(pType);
}

static void(*original_AddPedGibToPipingSession)(int, br_matrix34 *, int, int, int, ...) = (void(*)(int, br_matrix34 *, int, int, int, ...))0x00429023;
CARM95_HOOK_FUNCTION(original_AddPedGibToPipingSession, AddPedGibToPipingSession)
void AddPedGibToPipingSession(int pIndex, br_matrix34 *pTrans, int pSize, int pGib_index, int pPed_index) {
    tPipe_ped_gib_data data;
    LOG_TRACE("(%d, %p, %d, %d, %d)", pIndex, pTrans, pSize, pGib_index, pPed_index);

    (void)pIndex;
    (void)pTrans;
    (void)pSize;
    (void)pGib_index;
    (void)pPed_index;
    (void)data;

    original_AddPedGibToPipingSession(pIndex, pTrans, pSize, pGib_index, pPed_index);
}

static void(*original_AddCarIncidentToPipingSession)(float, tCar_spec *, br_vector3 *, ...) = (void(*)(float, tCar_spec *, br_vector3 *, ...))0x00429063;
CARM95_HOOK_FUNCTION(original_AddCarIncidentToPipingSession, AddCarIncidentToPipingSession)
void AddCarIncidentToPipingSession(float pSeverity, tCar_spec *pCar, br_vector3 *pImpact_point) {
    tPipe_incident_data data;
    LOG_TRACE("(%f, %p, %p)", pSeverity, pCar, pImpact_point);

    (void)pSeverity;
    (void)pCar;
    (void)pImpact_point;
    (void)data;

    original_AddCarIncidentToPipingSession(pSeverity, pCar, pImpact_point);
}

static void(*original_AddPedIncidentToPipingSession)(int, br_actor *, ...) = (void(*)(int, br_actor *, ...))0x004290ab;
CARM95_HOOK_FUNCTION(original_AddPedIncidentToPipingSession, AddPedIncidentToPipingSession)
void AddPedIncidentToPipingSession(int pPed_index, br_actor *pActor) {
    tPipe_incident_data data;
    LOG_TRACE("(%d, %p)", pPed_index, pActor);

    (void)pPed_index;
    (void)pActor;
    (void)data;

    original_AddPedIncidentToPipingSession(pPed_index, pActor);
}

static void(*original_AddWallIncidentToPipingSession)(float, br_vector3 *, ...) = (void(*)(float, br_vector3 *, ...))0x004290dd;
CARM95_HOOK_FUNCTION(original_AddWallIncidentToPipingSession, AddWallIncidentToPipingSession)
void AddWallIncidentToPipingSession(float pSeverity, br_vector3 *pImpact_point) {
    tPipe_incident_data data;
    LOG_TRACE("(%f, %p)", pSeverity, pImpact_point);

    (void)pSeverity;
    (void)pImpact_point;
    (void)data;

    original_AddWallIncidentToPipingSession(pSeverity, pImpact_point);
}

static void(*original_AddProxRayToPipingSession)(int, tCar_spec *, tU16, tU32, ...) = (void(*)(int, tCar_spec *, tU16, tU32, ...))0x00429117;
CARM95_HOOK_FUNCTION(original_AddProxRayToPipingSession, AddProxRayToPipingSession)
void AddProxRayToPipingSession(int pRay_index, tCar_spec *pCar, tU16 pPed_index, tU32 pTime) {
    tPipe_prox_ray_data data;
    LOG_TRACE("(%d, %p, %u, %u)", pRay_index, pCar, pPed_index, pTime);

    (void)pRay_index;
    (void)pCar;
    (void)pPed_index;
    (void)pTime;
    (void)data;

    original_AddProxRayToPipingSession(pRay_index, pCar, pPed_index, pTime);
}

static void(*original_AddSkidAdjustmentToPipingSession)(int, br_matrix34 *, int, ...) = (void(*)(int, br_matrix34 *, int, ...))0x00429153;
CARM95_HOOK_FUNCTION(original_AddSkidAdjustmentToPipingSession, AddSkidAdjustmentToPipingSession)
void AddSkidAdjustmentToPipingSession(int pSkid_num, br_matrix34 *pMatrix, int pMaterial_index) {
    tPipe_skid_adjustment adjustment;
    LOG_TRACE("(%d, %p, %d)", pSkid_num, pMatrix, pMaterial_index);

    (void)pSkid_num;
    (void)pMatrix;
    (void)pMaterial_index;
    (void)adjustment;

    original_AddSkidAdjustmentToPipingSession(pSkid_num, pMatrix, pMaterial_index);
}

static void(*original_PipeSingleModelGeometry)(tU16, int, int, tChanged_vertex *, ...) = (void(*)(tU16, int, int, tChanged_vertex *, ...))0x00429186;
CARM95_HOOK_FUNCTION(original_PipeSingleModelGeometry, PipeSingleModelGeometry)
void PipeSingleModelGeometry(tU16 pCar_ID, int pModel_index, int pVertex_count, tChanged_vertex *pCoordinates) {
    LOG_TRACE("(%u, %d, %d, %p)", pCar_ID, pModel_index, pVertex_count, pCoordinates);

    (void)pCar_ID;
    (void)pModel_index;
    (void)pVertex_count;
    (void)pCoordinates;

    original_PipeSingleModelGeometry(pCar_ID, pModel_index, pVertex_count, pCoordinates);
}

static void(*original_PipeSinglePedestrian)(int, br_matrix34 *, tU8, tU8, tS8, int, tU16, float, br_scalar, br_vector3 *, ...) = (void(*)(int, br_matrix34 *, tU8, tU8, tS8, int, tU16, float, br_scalar, br_vector3 *, ...))0x004291b8;
CARM95_HOOK_FUNCTION(original_PipeSinglePedestrian, PipeSinglePedestrian)
void PipeSinglePedestrian(int pPedestrian_index, br_matrix34 *pTrans, tU8 pAction_index, tU8 pFrame_index, tS8 pHit_points, int pDone_initial, tU16 pParent_ID, float pSpin_period, br_scalar pJump_magnitude, br_vector3 *pOffset) {
    LOG_TRACE("(%d, %p, %u, %u, %d, %d, %u, %f, %f, %p)", pPedestrian_index, pTrans, pAction_index, pFrame_index, pHit_points, pDone_initial, pParent_ID, pSpin_period, pJump_magnitude, pOffset);

    (void)pPedestrian_index;
    (void)pTrans;
    (void)pAction_index;
    (void)pFrame_index;
    (void)pHit_points;
    (void)pDone_initial;
    (void)pParent_ID;
    (void)pSpin_period;
    (void)pJump_magnitude;
    (void)pOffset;

    original_PipeSinglePedestrian(pPedestrian_index, pTrans, pAction_index, pFrame_index, pHit_points, pDone_initial, pParent_ID, pSpin_period, pJump_magnitude, pOffset);
}

static void(*original_PipeSingleCar)(int, br_matrix34 *, br_vector3 *, float, float, float, float, float, float, br_scalar, int, int, ...) = (void(*)(int, br_matrix34 *, br_vector3 *, float, float, float, float, float, float, br_scalar, int, int, ...))0x00429202;
CARM95_HOOK_FUNCTION(original_PipeSingleCar, PipeSingleCar)
void PipeSingleCar(int pCar_ID, br_matrix34 *pCar_mat, br_vector3 *pCar_velocity, float pSpeedo_speed, float pLf_sus_position, float pRf_sus_position, float pLr_sus_position, float pRr_sus_position, float pSteering_angle, br_scalar pRevs, int pGear, int pFrame_coll_flag) {
    LOG_TRACE("(%d, %p, %p, %f, %f, %f, %f, %f, %f, %f, %d, %d)", pCar_ID, pCar_mat, pCar_velocity, pSpeedo_speed, pLf_sus_position, pRf_sus_position, pLr_sus_position, pRr_sus_position, pSteering_angle, pRevs, pGear, pFrame_coll_flag);

    (void)pCar_ID;
    (void)pCar_mat;
    (void)pCar_velocity;
    (void)pSpeedo_speed;
    (void)pLf_sus_position;
    (void)pRf_sus_position;
    (void)pLr_sus_position;
    (void)pRr_sus_position;
    (void)pSteering_angle;
    (void)pRevs;
    (void)pGear;
    (void)pFrame_coll_flag;

    original_PipeSingleCar(pCar_ID, pCar_mat, pCar_velocity, pSpeedo_speed, pLf_sus_position, pRf_sus_position, pLr_sus_position, pRr_sus_position, pSteering_angle, pRevs, pGear, pFrame_coll_flag);
}

static void(*original_PipeSingleSound)(tS3_outlet_ptr, int, tS3_volume, tS3_volume, tS3_pitch, br_vector3 *, ...) = (void(*)(tS3_outlet_ptr, int, tS3_volume, tS3_volume, tS3_pitch, br_vector3 *, ...))0x00429254;
CARM95_HOOK_FUNCTION(original_PipeSingleSound, PipeSingleSound)
void PipeSingleSound(tS3_outlet_ptr pOutlet, int pSound_index, tS3_volume pL_volume, tS3_volume pR_volume, tS3_pitch pPitch, br_vector3 *pPos) {
    LOG_TRACE("(\"%s\", %d, %d, %d, %d, %p)", pOutlet, pSound_index, pL_volume, pR_volume, pPitch, pPos);

    (void)pOutlet;
    (void)pSound_index;
    (void)pL_volume;
    (void)pR_volume;
    (void)pPitch;
    (void)pPos;

    original_PipeSingleSound(pOutlet, pSound_index, pL_volume, pR_volume, pPitch, pPos);
}

static void(*original_PipeSingleOilSpill)(int, br_matrix34 *, br_scalar, br_scalar, tU32, tU32, tCar_spec *, br_vector3 *, br_pixelmap *, ...) = (void(*)(int, br_matrix34 *, br_scalar, br_scalar, tU32, tU32, tCar_spec *, br_vector3 *, br_pixelmap *, ...))0x004292a8;
CARM95_HOOK_FUNCTION(original_PipeSingleOilSpill, PipeSingleOilSpill)
void PipeSingleOilSpill(int pIndex, br_matrix34 *pMat, br_scalar pFull_size, br_scalar pGrow_rate, tU32 pSpill_time, tU32 pStop_time, tCar_spec *pCar, br_vector3 *pOriginal_pos, br_pixelmap *pPixelmap) {
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

    original_PipeSingleOilSpill(pIndex, pMat, pFull_size, pGrow_rate, pSpill_time, pStop_time, pCar, pOriginal_pos, pPixelmap);
}

static void(*original_PipeSingleDamage)(int, tS8 *, ...) = (void(*)(int, tS8 *, ...))0x004292ee;
CARM95_HOOK_FUNCTION(original_PipeSingleDamage, PipeSingleDamage)
void PipeSingleDamage(int pCar_ID, tS8 *pDifferences) {
    LOG_TRACE("(%d, %p)", pCar_ID, pDifferences);

    (void)pCar_ID;
    (void)pDifferences;

    original_PipeSingleDamage(pCar_ID, pDifferences);
}

static void(*original_PipeSingleSpecial)(tSpecial_type, ...) = (void(*)(tSpecial_type, ...))0x00429318;
CARM95_HOOK_FUNCTION(original_PipeSingleSpecial, PipeSingleSpecial)
void PipeSingleSpecial(tSpecial_type pType) {
    LOG_TRACE("(%d)", pType);

    (void)pType;

    original_PipeSingleSpecial(pType);
}

static void(*original_PipeSinglePedGib)(int, br_matrix34 *, int, int, int, ...) = (void(*)(int, br_matrix34 *, int, int, int, ...))0x0042933e;
CARM95_HOOK_FUNCTION(original_PipeSinglePedGib, PipeSinglePedGib)
void PipeSinglePedGib(int pIndex, br_matrix34 *pTrans, int pSize, int pGib_index, int pPed_index) {
    LOG_TRACE("(%d, %p, %d, %d, %d)", pIndex, pTrans, pSize, pGib_index, pPed_index);

    (void)pIndex;
    (void)pTrans;
    (void)pSize;
    (void)pGib_index;
    (void)pPed_index;

    original_PipeSinglePedGib(pIndex, pTrans, pSize, pGib_index, pPed_index);
}

static void(*original_PipeSingleCarIncident)(float, tCar_spec *, br_vector3 *, ...) = (void(*)(float, tCar_spec *, br_vector3 *, ...))0x00429374;
CARM95_HOOK_FUNCTION(original_PipeSingleCarIncident, PipeSingleCarIncident)
void PipeSingleCarIncident(float pSeverity, tCar_spec *pCar, br_vector3 *pImpact_point) {
    LOG_TRACE("(%f, %p, %p)", pSeverity, pCar, pImpact_point);

    (void)pSeverity;
    (void)pCar;
    (void)pImpact_point;

    original_PipeSingleCarIncident(pSeverity, pCar, pImpact_point);
}

static void(*original_PipeSinglePedIncident)(int, br_actor *, ...) = (void(*)(int, br_actor *, ...))0x004293a2;
CARM95_HOOK_FUNCTION(original_PipeSinglePedIncident, PipeSinglePedIncident)
void PipeSinglePedIncident(int pPed_index, br_actor *pActor) {
    LOG_TRACE("(%d, %p)", pPed_index, pActor);

    (void)pPed_index;
    (void)pActor;

    original_PipeSinglePedIncident(pPed_index, pActor);
}

static void(*original_PipeSingleWallIncident)(float, br_vector3 *, ...) = (void(*)(float, br_vector3 *, ...))0x004293d6;
CARM95_HOOK_FUNCTION(original_PipeSingleWallIncident, PipeSingleWallIncident)
void PipeSingleWallIncident(float pSeverity, br_vector3 *pImpact_point) {
    LOG_TRACE("(%f, %p)", pSeverity, pImpact_point);

    (void)pSeverity;
    (void)pImpact_point;

    original_PipeSingleWallIncident(pSeverity, pImpact_point);
}

static void(*original_PipeSingleScreenShake)(int, int, ...) = (void(*)(int, int, ...))0x00429415;
CARM95_HOOK_FUNCTION(original_PipeSingleScreenShake, PipeSingleScreenShake)
void PipeSingleScreenShake(int pWobble_x, int pWobble_y) {
    LOG_TRACE("(%d, %d)", pWobble_x, pWobble_y);

    (void)pWobble_x;
    (void)pWobble_y;

    original_PipeSingleScreenShake(pWobble_x, pWobble_y);
}

static void(*original_PipeSingleGrooveStop)(int, br_matrix34 *, int, int, float, float, ...) = (void(*)(int, br_matrix34 *, int, int, float, float, ...))0x0042943f;
CARM95_HOOK_FUNCTION(original_PipeSingleGrooveStop, PipeSingleGrooveStop)
void PipeSingleGrooveStop(int pGroove_index, br_matrix34 *pMatrix, int pPath_interrupt, int pObject_interrupt, float pPath_resumption, float pObject_resumption) {
    LOG_TRACE("(%d, %p, %d, %d, %f, %f)", pGroove_index, pMatrix, pPath_interrupt, pObject_interrupt, pPath_resumption, pObject_resumption);

    (void)pGroove_index;
    (void)pMatrix;
    (void)pPath_interrupt;
    (void)pObject_interrupt;
    (void)pPath_resumption;
    (void)pObject_resumption;

    original_PipeSingleGrooveStop(pGroove_index, pMatrix, pPath_interrupt, pObject_interrupt, pPath_resumption, pObject_resumption);
}

static void(*original_PipeFrameFinish)() = (void(*)())0x00429479;
CARM95_HOOK_FUNCTION(original_PipeFrameFinish, PipeFrameFinish)
void PipeFrameFinish() {
    LOG_TRACE("()");


    original_PipeFrameFinish();
}

static void(*original_PipingFrameReset)() = (void(*)())0x004294e4;
CARM95_HOOK_FUNCTION(original_PipingFrameReset, PipingFrameReset)
void PipingFrameReset() {
    int i;
    LOG_TRACE("()");

    (void)i;

    original_PipingFrameReset();
}

static void(*original_PipeSingleSkidAdjustment)(int, br_matrix34 *, int, ...) = (void(*)(int, br_matrix34 *, int, ...))0x0042952b;
CARM95_HOOK_FUNCTION(original_PipeSingleSkidAdjustment, PipeSingleSkidAdjustment)
void PipeSingleSkidAdjustment(int pSkid_num, br_matrix34 *pMatrix, int pMaterial_index) {
    LOG_TRACE("(%d, %p, %d)", pSkid_num, pMatrix, pMaterial_index);

    (void)pSkid_num;
    (void)pMatrix;
    (void)pMaterial_index;

    original_PipeSingleSkidAdjustment(pSkid_num, pMatrix, pMaterial_index);
}

static void(*original_ResetPiping)() = (void(*)())0x00429559;
CARM95_HOOK_FUNCTION(original_ResetPiping, ResetPiping)
void ResetPiping() {
    LOG_TRACE("()");


    original_ResetPiping();
}

static void(*original_InitialisePiping)() = (void(*)())0x00429596;
CARM95_HOOK_FUNCTION(original_InitialisePiping, InitialisePiping)
void InitialisePiping() {
    LOG_TRACE("()");


    original_InitialisePiping();
}

static void(*original_DisposePiping)() = (void(*)())0x0042966f;
CARM95_HOOK_FUNCTION(original_DisposePiping, DisposePiping)
void DisposePiping() {
    LOG_TRACE("()");


    original_DisposePiping();
}

static void(*original_InitLastDamageArrayEtc)() = (void(*)())0x004296e9;
CARM95_HOOK_FUNCTION(original_InitLastDamageArrayEtc, InitLastDamageArrayEtc)
void InitLastDamageArrayEtc() {
    int i;
    int j;
    int cat;
    int car_count;
    tCar_spec *car;
    LOG_TRACE("()");

    (void)i;
    (void)j;
    (void)cat;
    (void)car_count;
    (void)car;

    original_InitLastDamageArrayEtc();
}

static void(*original_ResetCars)() = (void(*)())0x004297d2;
CARM95_HOOK_FUNCTION(original_ResetCars, ResetCars)
void ResetCars() {
    tCar_spec *car;
    int cat;
    int i;
    int car_count;
    LOG_TRACE("()");

    (void)car;
    (void)cat;
    (void)i;
    (void)car_count;

    original_ResetCars();
}

static void(*original_PipeCarPositions)() = (void(*)())0x0042987f;
CARM95_HOOK_FUNCTION(original_PipeCarPositions, PipeCarPositions)
void PipeCarPositions() {
    tCar_spec *car;
    int cat;
    int i;
    int j;
    int car_count;
    int session_started;
    int difference_found;
    tS8 damage_deltas[12];
    LOG_TRACE("()");

    (void)car;
    (void)cat;
    (void)i;
    (void)j;
    (void)car_count;
    (void)session_started;
    (void)difference_found;
    (void)damage_deltas;

    original_PipeCarPositions();
}

static void(*original_ResetPipePlayToEnd)() = (void(*)())0x00429b22;
CARM95_HOOK_FUNCTION(original_ResetPipePlayToEnd, ResetPipePlayToEnd)
void ResetPipePlayToEnd() {
    LOG_TRACE("()");


    original_ResetPipePlayToEnd();
}

static void(*original_ResetPipePlayToStart)() = (void(*)())0x00429b37;
CARM95_HOOK_FUNCTION(original_ResetPipePlayToStart, ResetPipePlayToStart)
void ResetPipePlayToStart() {
    LOG_TRACE("()");


    original_ResetPipePlayToStart();
}

static tU8 *(*original_GetPipePlayPtr)() = (tU8 *(*)())0x00429b4c;
CARM95_HOOK_FUNCTION(original_GetPipePlayPtr, GetPipePlayPtr)
tU8* GetPipePlayPtr() {
    LOG_TRACE("()");


    return original_GetPipePlayPtr();
}

static void(*original_SetPipePlayPtr)(tU8 *, ...) = (void(*)(tU8 *, ...))0x00429b61;
CARM95_HOOK_FUNCTION(original_SetPipePlayPtr, SetPipePlayPtr)
void SetPipePlayPtr(tU8 *pPtr) {
    LOG_TRACE("(%p)", pPtr);

    (void)pPtr;

    original_SetPipePlayPtr(pPtr);
}

static void(*original_AdvanceChunkPtr)(tPipe_chunk **, tChunk_subject_index, ...) = (void(*)(tPipe_chunk **, tChunk_subject_index, ...))0x00429fcd;
CARM95_HOOK_FUNCTION(original_AdvanceChunkPtr, AdvanceChunkPtr)
void AdvanceChunkPtr(tPipe_chunk **pChunk, tChunk_subject_index pType) {
    tPipe_chunk *old_chunk;
    LOG_TRACE("(%p, %u)", pChunk, pType);

    (void)pChunk;
    (void)pType;
    (void)old_chunk;

    original_AdvanceChunkPtr(pChunk, pType);
}

static void(*original_ApplyModelGeometry)(tPipe_chunk **, ...) = (void(*)(tPipe_chunk **, ...))0x0042a1fd;
CARM95_HOOK_FUNCTION(original_ApplyModelGeometry, ApplyModelGeometry)
void ApplyModelGeometry(tPipe_chunk **pChunk) {
    int i;
    br_model *model_ptr;
    tCar_spec *car;
    LOG_TRACE("(%p)", pChunk);

    (void)pChunk;
    (void)i;
    (void)model_ptr;
    (void)car;

    original_ApplyModelGeometry(pChunk);
}

void DoSmudge(tPipe_chunk **pChunk, int pDir) {
    int i;
    int v;
    tU8 inc;
    br_model *model_ptr;
    tCar_spec *car;
    int group;
    LOG_TRACE("(%p, %d)", pChunk, pDir);

    (void)pChunk;
    (void)pDir;
    (void)i;
    (void)v;
    (void)inc;
    (void)model_ptr;
    (void)car;
    (void)group;

    NOT_IMPLEMENTED();
}

static void(*original_ApplySmudge)(tPipe_chunk **, ...) = (void(*)(tPipe_chunk **, ...))0x0042a3b1;
CARM95_HOOK_FUNCTION(original_ApplySmudge, ApplySmudge)
void ApplySmudge(tPipe_chunk **pChunk) {
    LOG_TRACE("(%p)", pChunk);

    (void)pChunk;

    original_ApplySmudge(pChunk);
}

static void(*original_ApplyPedestrian)(tPipe_chunk **, ...) = (void(*)(tPipe_chunk **, ...))0x0042a3d8;
CARM95_HOOK_FUNCTION(original_ApplyPedestrian, ApplyPedestrian)
void ApplyPedestrian(tPipe_chunk **pChunk) {
    LOG_TRACE("(%p)", pChunk);

    (void)pChunk;

    original_ApplyPedestrian(pChunk);
}

static void(*original_ApplySpark)(tPipe_chunk **, ...) = (void(*)(tPipe_chunk **, ...))0x0042a472;
CARM95_HOOK_FUNCTION(original_ApplySpark, ApplySpark)
void ApplySpark(tPipe_chunk **pChunk) {
    LOG_TRACE("(%p)", pChunk);

    (void)pChunk;

    original_ApplySpark(pChunk);
}

static void(*original_ApplyShrapnel)(tPipe_chunk **, ...) = (void(*)(tPipe_chunk **, ...))0x0042a4b0;
CARM95_HOOK_FUNCTION(original_ApplyShrapnel, ApplyShrapnel)
void ApplyShrapnel(tPipe_chunk **pChunk) {
    LOG_TRACE("(%p)", pChunk);

    (void)pChunk;

    original_ApplyShrapnel(pChunk);
}

static void(*original_ApplyScreenWobble)(tPipe_chunk **, ...) = (void(*)(tPipe_chunk **, ...))0x0042a4f8;
CARM95_HOOK_FUNCTION(original_ApplyScreenWobble, ApplyScreenWobble)
void ApplyScreenWobble(tPipe_chunk **pChunk) {
    LOG_TRACE("(%p)", pChunk);

    (void)pChunk;

    original_ApplyScreenWobble(pChunk);
}

static void(*original_ApplyGrooveStop)(tPipe_chunk **, ...) = (void(*)(tPipe_chunk **, ...))0x0042a52d;
CARM95_HOOK_FUNCTION(original_ApplyGrooveStop, ApplyGrooveStop)
void ApplyGrooveStop(tPipe_chunk **pChunk) {
    LOG_TRACE("(%p)", pChunk);

    (void)pChunk;

    original_ApplyGrooveStop(pChunk);
}

static void(*original_ApplyNonCar)(tPipe_chunk **, ...) = (void(*)(tPipe_chunk **, ...))0x0042a586;
CARM95_HOOK_FUNCTION(original_ApplyNonCar, ApplyNonCar)
void ApplyNonCar(tPipe_chunk **pChunk) {
    LOG_TRACE("(%p)", pChunk);

    (void)pChunk;

    original_ApplyNonCar(pChunk);
}

static void(*original_ApplySmoke)(tPipe_chunk **, ...) = (void(*)(tPipe_chunk **, ...))0x0042a5b9;
CARM95_HOOK_FUNCTION(original_ApplySmoke, ApplySmoke)
void ApplySmoke(tPipe_chunk **pChunk) {
    br_vector3 pos;
    LOG_TRACE("(%p)", pChunk);

    (void)pChunk;
    (void)pos;

    original_ApplySmoke(pChunk);
}

static void(*original_ApplySmokeColumn)(tPipe_chunk **, ...) = (void(*)(tPipe_chunk **, ...))0x0042a651;
CARM95_HOOK_FUNCTION(original_ApplySmokeColumn, ApplySmokeColumn)
void ApplySmokeColumn(tPipe_chunk **pChunk) {
    LOG_TRACE("(%p)", pChunk);

    (void)pChunk;

    original_ApplySmokeColumn(pChunk);
}

static void(*original_ApplyFlame)(tPipe_chunk **, ...) = (void(*)(tPipe_chunk **, ...))0x0042a6f8;
CARM95_HOOK_FUNCTION(original_ApplyFlame, ApplyFlame)
void ApplyFlame(tPipe_chunk **pChunk) {
    LOG_TRACE("(%p)", pChunk);

    (void)pChunk;

    original_ApplyFlame(pChunk);
}

static void(*original_ApplySplash)(tPipe_chunk **, ...) = (void(*)(tPipe_chunk **, ...))0x0042a752;
CARM95_HOOK_FUNCTION(original_ApplySplash, ApplySplash)
void ApplySplash(tPipe_chunk **pChunk) {
    tCar_spec *c;
    LOG_TRACE("(%p)", pChunk);

    (void)pChunk;
    (void)c;

    original_ApplySplash(pChunk);
}

static void(*original_ApplyOilSpill)(tPipe_chunk **, tU32, ...) = (void(*)(tPipe_chunk **, tU32, ...))0x0042a80d;
CARM95_HOOK_FUNCTION(original_ApplyOilSpill, ApplyOilSpill)
void ApplyOilSpill(tPipe_chunk **pChunk, tU32 pStop_time) {
    LOG_TRACE("(%p, %u)", pChunk, pStop_time);

    (void)pChunk;
    (void)pStop_time;

    original_ApplyOilSpill(pChunk, pStop_time);
}

static void(*original_ApplyFrameBoundary)(tPipe_chunk **, ...) = (void(*)(tPipe_chunk **, ...))0x0042a87c;
CARM95_HOOK_FUNCTION(original_ApplyFrameBoundary, ApplyFrameBoundary)
void ApplyFrameBoundary(tPipe_chunk **pChunk) {
    tU32 result;
    LOG_TRACE("(%p)", pChunk);

    (void)pChunk;
    (void)result;

    original_ApplyFrameBoundary(pChunk);
}

static void(*original_ApplySound)(tPipe_chunk **, ...) = (void(*)(tPipe_chunk **, ...))0x0042a8b5;
CARM95_HOOK_FUNCTION(original_ApplySound, ApplySound)
void ApplySound(tPipe_chunk **pChunk) {
    LOG_TRACE("(%p)", pChunk);

    (void)pChunk;

    original_ApplySound(pChunk);
}

static void(*original_ApplyCar)(tPipe_chunk **, ...) = (void(*)(tPipe_chunk **, ...))0x0042aa59;
CARM95_HOOK_FUNCTION(original_ApplyCar, ApplyCar)
void ApplyCar(tPipe_chunk **pChunk) {
    tCar_spec *car;
    br_vector3 com_offset_c;
    br_vector3 com_offset_w;
    br_scalar __block0___scale;
    LOG_TRACE("(%p)", pChunk);

    (void)pChunk;
    (void)car;
    (void)com_offset_c;
    (void)com_offset_w;

    original_ApplyCar(pChunk);
}

static void(*original_ApplyDamage)(tPipe_chunk **, ...) = (void(*)(tPipe_chunk **, ...))0x0042ae65;
CARM95_HOOK_FUNCTION(original_ApplyDamage, ApplyDamage)
void ApplyDamage(tPipe_chunk **pChunk) {
    tCar_spec *car;
    int i;
    LOG_TRACE("(%p)", pChunk);

    (void)pChunk;
    (void)car;
    (void)i;

    original_ApplyDamage(pChunk);
}

static void(*original_ApplySpecial)(tPipe_chunk **, ...) = (void(*)(tPipe_chunk **, ...))0x0042af1e;
CARM95_HOOK_FUNCTION(original_ApplySpecial, ApplySpecial)
void ApplySpecial(tPipe_chunk **pChunk) {
    LOG_TRACE("(%p)", pChunk);

    (void)pChunk;

    original_ApplySpecial(pChunk);
}

static void(*original_ApplyPedGib)(tPipe_chunk **, ...) = (void(*)(tPipe_chunk **, ...))0x0042afc8;
CARM95_HOOK_FUNCTION(original_ApplyPedGib, ApplyPedGib)
void ApplyPedGib(tPipe_chunk **pChunk) {
    LOG_TRACE("(%p)", pChunk);

    (void)pChunk;

    original_ApplyPedGib(pChunk);
}

static void(*original_ApplyProxRay)(tPipe_chunk **, ...) = (void(*)(tPipe_chunk **, ...))0x0042b01f;
CARM95_HOOK_FUNCTION(original_ApplyProxRay, ApplyProxRay)
void ApplyProxRay(tPipe_chunk **pChunk) {
    LOG_TRACE("(%p)", pChunk);

    (void)pChunk;

    original_ApplyProxRay(pChunk);
}

static void(*original_ApplySkidAdjustment)(tPipe_chunk **, ...) = (void(*)(tPipe_chunk **, ...))0x0042b068;
CARM95_HOOK_FUNCTION(original_ApplySkidAdjustment, ApplySkidAdjustment)
void ApplySkidAdjustment(tPipe_chunk **pChunk) {
    LOG_TRACE("(%p)", pChunk);

    (void)pChunk;

    original_ApplySkidAdjustment(pChunk);
}

static int(*original_ApplyPipedSession)(tU8 **, ...) = (int(*)(tU8 **, ...))0x0042b0a6;
CARM95_HOOK_FUNCTION(original_ApplyPipedSession, ApplyPipedSession)
int ApplyPipedSession(tU8 **pPtr) {
    int i;
    int return_value;
    tPipe_chunk *chunk_ptr;
    tPipe_chunk_type chunk_type;
    LOG_TRACE("(%p)", pPtr);

    (void)pPtr;
    (void)i;
    (void)return_value;
    (void)chunk_ptr;
    (void)chunk_type;

    return original_ApplyPipedSession(pPtr);
}

static int(*original_MoveSessionPointerBackOne)(tU8 **, ...) = (int(*)(tU8 **, ...))0x0042b419;
CARM95_HOOK_FUNCTION(original_MoveSessionPointerBackOne, MoveSessionPointerBackOne)
int MoveSessionPointerBackOne(tU8 **pPtr) {
    LOG_TRACE("(%p)", pPtr);

    (void)pPtr;

    return original_MoveSessionPointerBackOne(pPtr);
}

int MoveSessionPointerForwardOne(tU8 **pPtr) {
    LOG_TRACE("(%p)", pPtr);

    (void)pPtr;

    NOT_IMPLEMENTED();
}

static tPipe_chunk *(*original_FindPreviousChunk)(tU8 *, tPipe_chunk_type, tChunk_subject_index, ...) = (tPipe_chunk *(*)(tU8 *, tPipe_chunk_type, tChunk_subject_index, ...))0x0042b492;
CARM95_HOOK_FUNCTION(original_FindPreviousChunk, FindPreviousChunk)
tPipe_chunk* FindPreviousChunk(tU8 *pPtr, tPipe_chunk_type pType, tChunk_subject_index pIndex) {
    tU8 *ptr;
    int i;
    int reached_end;
    int chunk_counter;
    tPipe_chunk *mr_chunky;
    tChunk_subject_index masked_index;
    LOG_TRACE("(%p, %d, %u)", pPtr, pType, pIndex);

    (void)pPtr;
    (void)pType;
    (void)pIndex;
    (void)ptr;
    (void)i;
    (void)reached_end;
    (void)chunk_counter;
    (void)mr_chunky;
    (void)masked_index;

    return original_FindPreviousChunk(pPtr, pType, pIndex);
}

void UndoModelGeometry(tPipe_chunk **pChunk) {
    int i;
    br_model *model_ptr;
    tCar_spec *car;
    LOG_TRACE("(%p)", pChunk);

    (void)pChunk;
    (void)i;
    (void)model_ptr;
    (void)car;

    NOT_IMPLEMENTED();
}

void UndoSmudge(tPipe_chunk **pChunk) {
    int i;
    br_model *model_ptr;
    tCar_spec *car;
    LOG_TRACE("(%p)", pChunk);

    (void)pChunk;
    (void)i;
    (void)model_ptr;
    (void)car;

    NOT_IMPLEMENTED();
}

void UndoPedestrian(tPipe_chunk **pChunk, tPipe_chunk *pPrev_chunk) {
    tPipe_chunk *temp_prev_chunk;
    LOG_TRACE("(%p, %p)", pChunk, pPrev_chunk);

    (void)pChunk;
    (void)pPrev_chunk;
    (void)temp_prev_chunk;

    NOT_IMPLEMENTED();
}

void UndoFrameBoundary(tPipe_chunk **pChunk, tPipe_chunk *pPrev_chunk) {
    tPipe_chunk *temp_prev_chunk;
    LOG_TRACE("(%p, %p)", pChunk, pPrev_chunk);

    (void)pChunk;
    (void)pPrev_chunk;
    (void)temp_prev_chunk;

    NOT_IMPLEMENTED();
}

void UndoCar(tPipe_chunk **pChunk, tPipe_chunk *pPrev_chunk) {
    tPipe_chunk *temp_prev_chunk;
    LOG_TRACE("(%p, %p)", pChunk, pPrev_chunk);

    (void)pChunk;
    (void)pPrev_chunk;
    (void)temp_prev_chunk;

    NOT_IMPLEMENTED();
}

void UndoSound(tPipe_chunk **pChunk) {
    LOG_TRACE("(%p)", pChunk);

    (void)pChunk;

    NOT_IMPLEMENTED();
}

void UndoDamage(tPipe_chunk **pChunk) {
    tCar_spec *car;
    int i;
    LOG_TRACE("(%p)", pChunk);

    (void)pChunk;
    (void)car;
    (void)i;

    NOT_IMPLEMENTED();
}

static void(*original_UndoSpecial)(tPipe_chunk **, ...) = (void(*)(tPipe_chunk **, ...))0x0042b94c;
CARM95_HOOK_FUNCTION(original_UndoSpecial, UndoSpecial)
void UndoSpecial(tPipe_chunk **pChunk) {
    LOG_TRACE("(%p)", pChunk);

    (void)pChunk;

    original_UndoSpecial(pChunk);
}

static void(*original_UndoPedGib)(tPipe_chunk **, tPipe_chunk *, ...) = (void(*)(tPipe_chunk **, tPipe_chunk *, ...))0x0042b9f6;
CARM95_HOOK_FUNCTION(original_UndoPedGib, UndoPedGib)
void UndoPedGib(tPipe_chunk **pChunk, tPipe_chunk *pPrev_chunk) {
    tPipe_chunk *temp_prev_chunk;
    LOG_TRACE("(%p, %p)", pChunk, pPrev_chunk);

    (void)pChunk;
    (void)pPrev_chunk;
    (void)temp_prev_chunk;

    original_UndoPedGib(pChunk, pPrev_chunk);
}

static void(*original_UndoSpark)(tPipe_chunk **, tPipe_chunk *, ...) = (void(*)(tPipe_chunk **, tPipe_chunk *, ...))0x0042ba42;
CARM95_HOOK_FUNCTION(original_UndoSpark, UndoSpark)
void UndoSpark(tPipe_chunk **pChunk, tPipe_chunk *pPrev_chunk) {
    tPipe_chunk *temp_prev_chunk;
    LOG_TRACE("(%p, %p)", pChunk, pPrev_chunk);

    (void)pChunk;
    (void)pPrev_chunk;
    (void)temp_prev_chunk;

    original_UndoSpark(pChunk, pPrev_chunk);
}

static void(*original_UndoShrapnel)(tPipe_chunk **, tPipe_chunk *, ...) = (void(*)(tPipe_chunk **, tPipe_chunk *, ...))0x0042ba8e;
CARM95_HOOK_FUNCTION(original_UndoShrapnel, UndoShrapnel)
void UndoShrapnel(tPipe_chunk **pChunk, tPipe_chunk *pPrev_chunk) {
    tPipe_chunk *temp_prev_chunk;
    LOG_TRACE("(%p, %p)", pChunk, pPrev_chunk);

    (void)pChunk;
    (void)pPrev_chunk;
    (void)temp_prev_chunk;

    original_UndoShrapnel(pChunk, pPrev_chunk);
}

static void(*original_UndoScreenWobble)(tPipe_chunk **, tPipe_chunk *, ...) = (void(*)(tPipe_chunk **, tPipe_chunk *, ...))0x0042bada;
CARM95_HOOK_FUNCTION(original_UndoScreenWobble, UndoScreenWobble)
void UndoScreenWobble(tPipe_chunk **pChunk, tPipe_chunk *pPrev_chunk) {
    tPipe_chunk *temp_prev_chunk;
    LOG_TRACE("(%p, %p)", pChunk, pPrev_chunk);

    (void)pChunk;
    (void)pPrev_chunk;
    (void)temp_prev_chunk;

    original_UndoScreenWobble(pChunk, pPrev_chunk);
}

static void(*original_UndoGrooveStop)(tPipe_chunk **, tPipe_chunk *, ...) = (void(*)(tPipe_chunk **, tPipe_chunk *, ...))0x0042bb37;
CARM95_HOOK_FUNCTION(original_UndoGrooveStop, UndoGrooveStop)
void UndoGrooveStop(tPipe_chunk **pChunk, tPipe_chunk *pPrev_chunk) {
    tPipe_chunk *temp_prev_chunk;
    LOG_TRACE("(%p, %p)", pChunk, pPrev_chunk);

    (void)pChunk;
    (void)pPrev_chunk;
    (void)temp_prev_chunk;

    original_UndoGrooveStop(pChunk, pPrev_chunk);
}

static void(*original_UndoNonCar)(tPipe_chunk **, tPipe_chunk *, ...) = (void(*)(tPipe_chunk **, tPipe_chunk *, ...))0x0042bb83;
CARM95_HOOK_FUNCTION(original_UndoNonCar, UndoNonCar)
void UndoNonCar(tPipe_chunk **pChunk, tPipe_chunk *pPrev_chunk) {
    tPipe_chunk *temp_prev_chunk;
    LOG_TRACE("(%p, %p)", pChunk, pPrev_chunk);

    (void)pChunk;
    (void)pPrev_chunk;
    (void)temp_prev_chunk;

    original_UndoNonCar(pChunk, pPrev_chunk);
}

static void(*original_UndoSmoke)(tPipe_chunk **, tPipe_chunk *, ...) = (void(*)(tPipe_chunk **, tPipe_chunk *, ...))0x0042bbcf;
CARM95_HOOK_FUNCTION(original_UndoSmoke, UndoSmoke)
void UndoSmoke(tPipe_chunk **pChunk, tPipe_chunk *pPrev_chunk) {
    tPipe_chunk *temp_prev_chunk;
    LOG_TRACE("(%p, %p)", pChunk, pPrev_chunk);

    (void)pChunk;
    (void)pPrev_chunk;
    (void)temp_prev_chunk;

    original_UndoSmoke(pChunk, pPrev_chunk);
}

static void(*original_UndoSmokeColumn)(tPipe_chunk **, tPipe_chunk *, ...) = (void(*)(tPipe_chunk **, tPipe_chunk *, ...))0x0042bc1b;
CARM95_HOOK_FUNCTION(original_UndoSmokeColumn, UndoSmokeColumn)
void UndoSmokeColumn(tPipe_chunk **pChunk, tPipe_chunk *pPrev_chunk) {
    tPipe_chunk *temp_prev_chunk;
    LOG_TRACE("(%p, %p)", pChunk, pPrev_chunk);

    (void)pChunk;
    (void)pPrev_chunk;
    (void)temp_prev_chunk;

    original_UndoSmokeColumn(pChunk, pPrev_chunk);
}

void UndoFlame(tPipe_chunk **pChunk, tPipe_chunk *pPrev_chunk) {
    LOG_TRACE("(%p, %p)", pChunk, pPrev_chunk);

    (void)pChunk;
    (void)pPrev_chunk;

    NOT_IMPLEMENTED();
}

static void(*original_UndoSplash)(tPipe_chunk **, tPipe_chunk *, ...) = (void(*)(tPipe_chunk **, tPipe_chunk *, ...))0x0042bc52;
CARM95_HOOK_FUNCTION(original_UndoSplash, UndoSplash)
void UndoSplash(tPipe_chunk **pChunk, tPipe_chunk *pPrev_chunk) {
    tPipe_chunk *temp_prev_chunk;
    LOG_TRACE("(%p, %p)", pChunk, pPrev_chunk);

    (void)pChunk;
    (void)pPrev_chunk;
    (void)temp_prev_chunk;

    original_UndoSplash(pChunk, pPrev_chunk);
}

static void(*original_UndoOilSpill)(tPipe_chunk **, tPipe_chunk *, ...) = (void(*)(tPipe_chunk **, tPipe_chunk *, ...))0x0042bd0b;
CARM95_HOOK_FUNCTION(original_UndoOilSpill, UndoOilSpill)
void UndoOilSpill(tPipe_chunk **pChunk, tPipe_chunk *pPrev_chunk) {
    tPipe_chunk *temp_prev_chunk;
    LOG_TRACE("(%p, %p)", pChunk, pPrev_chunk);

    (void)pChunk;
    (void)pPrev_chunk;
    (void)temp_prev_chunk;

    original_UndoOilSpill(pChunk, pPrev_chunk);
}

static void(*original_UndoProxRay)(tPipe_chunk **, ...) = (void(*)(tPipe_chunk **, ...))0x0042bd60;
CARM95_HOOK_FUNCTION(original_UndoProxRay, UndoProxRay)
void UndoProxRay(tPipe_chunk **pChunk) {
    LOG_TRACE("(%p)", pChunk);

    (void)pChunk;

    original_UndoProxRay(pChunk);
}

static void(*original_UndoSkidAdjustment)(tPipe_chunk **, tPipe_chunk *, ...) = (void(*)(tPipe_chunk **, tPipe_chunk *, ...))0x0042bd77;
CARM95_HOOK_FUNCTION(original_UndoSkidAdjustment, UndoSkidAdjustment)
void UndoSkidAdjustment(tPipe_chunk **pChunk, tPipe_chunk *pPrev_chunk) {
    LOG_TRACE("(%p, %p)", pChunk, pPrev_chunk);

    (void)pChunk;
    (void)pPrev_chunk;

    original_UndoSkidAdjustment(pChunk, pPrev_chunk);
}

int UndoPipedSession(tU8 **pPtr) {
    tPipe_chunk *chunk_ptr;
    tPipe_chunk *prev_chunk;
    tU8 *temp_ptr;
    tU8 *pushed_end_of_session;
    int i;
    tPipe_chunk_type chunk_type;
    LOG_TRACE("(%p)", pPtr);

    (void)pPtr;
    (void)chunk_ptr;
    (void)prev_chunk;
    (void)temp_ptr;
    (void)pushed_end_of_session;
    (void)i;
    (void)chunk_type;

    NOT_IMPLEMENTED();
}

tU32 FindPrevFrameTime(tU8 *pPtr) {
    tU8 *temp_ptr;
    LOG_TRACE("(%p)", pPtr);

    (void)pPtr;
    (void)temp_ptr;

    NOT_IMPLEMENTED();
}

static void(*original_ScanBuffer)(tU8 **, tPipe_chunk_type, tU32, int(**)(tPipe_chunk *, int, tU32, ...), int(**)(tU32, ...), ...) = (void(*)(tU8 **, tPipe_chunk_type, tU32, int(**)(tPipe_chunk *, int, tU32, ...), int(**)(tU32, ...), ...))0x0042be18;
CARM95_HOOK_FUNCTION(original_ScanBuffer, ScanBuffer)
void ScanBuffer(tU8 **pPtr, tPipe_chunk_type pType, tU32 pDefault_time, int(**pCall_back)(tPipe_chunk *, int, tU32, ...), int(**pTime_check)(tU32, ...)) {
    tPipe_chunk *chunk_ptr;
    tU32 the_time;
    LOG_TRACE("(%p, %d, %u, %p, %p)", pPtr, pType, pDefault_time, pCall_back, pTime_check);

    (void)pPtr;
    (void)pType;
    (void)pDefault_time;
    (void)pCall_back;
    (void)pTime_check;
    (void)chunk_ptr;
    (void)the_time;

    original_ScanBuffer(pPtr, pType, pDefault_time, pCall_back, pTime_check);
}

static int(*original_CheckSound)(tPipe_chunk *, int, tU32, ...) = (int(*)(tPipe_chunk *, int, tU32, ...))0x0042c00a;
CARM95_HOOK_FUNCTION(original_CheckSound, CheckSound)
int CheckSound(tPipe_chunk *pChunk_ptr, int pChunk_count, tU32 pTime) {
    int i;
    int sound_length;
    tPipe_chunk *temp_ptr;
    LOG_TRACE("(%p, %d, %u)", pChunk_ptr, pChunk_count, pTime);

    (void)pChunk_ptr;
    (void)pChunk_count;
    (void)pTime;
    (void)i;
    (void)sound_length;
    (void)temp_ptr;

    return original_CheckSound(pChunk_ptr, pChunk_count, pTime);
}

int SoundTimeout(tU32 pTime) {
    LOG_TRACE("(%u)", pTime);

    (void)pTime;

    NOT_IMPLEMENTED();
}

static void(*original_ScanAndPlaySoundsToBe)(tU8 *, tU32, tU32, ...) = (void(*)(tU8 *, tU32, tU32, ...))0x0042c06e;
CARM95_HOOK_FUNCTION(original_ScanAndPlaySoundsToBe, ScanAndPlaySoundsToBe)
void ScanAndPlaySoundsToBe(tU8 *pPtr, tU32 pOldest_time, tU32 pYoungest_time) {
    tU8 *temp_ptr;
    LOG_TRACE("(%p, %u, %u)", pPtr, pOldest_time, pYoungest_time);

    (void)pPtr;
    (void)pOldest_time;
    (void)pYoungest_time;
    (void)temp_ptr;

    original_ScanAndPlaySoundsToBe(pPtr, pOldest_time, pYoungest_time);
}

int CheckCar(tPipe_chunk *pChunk_ptr, int pChunk_count, tU32 pTime) {
    int i;
    tCar_spec *car;
    br_vector3 com_offset_c;
    br_vector3 com_offset_w;
    br_vector3 difference;
    tPipe_chunk *temp_ptr;
    LOG_TRACE("(%p, %d, %u)", pChunk_ptr, pChunk_count, pTime);

    (void)pChunk_ptr;
    (void)pChunk_count;
    (void)pTime;
    (void)i;
    (void)car;
    (void)com_offset_c;
    (void)com_offset_w;
    (void)difference;
    (void)temp_ptr;

    NOT_IMPLEMENTED();
}

int CarTimeout(tU32 pTime) {
    LOG_TRACE("(%u)", pTime);

    (void)pTime;

    NOT_IMPLEMENTED();
}

void ScanCarsPositions(tCar_spec *pCar, br_vector3 *pSource_pos, br_scalar pMax_distance_sqr, tU32 pOffset_time, tU32 pTime_period, br_vector3 *pCar_pos, tU32 *pTime_returned) {
    tU8 *temp_ptr;
    LOG_TRACE("(%p, %p, %f, %u, %u, %p, %p)", pCar, pSource_pos, pMax_distance_sqr, pOffset_time, pTime_period, pCar_pos, pTime_returned);

    (void)pCar;
    (void)pSource_pos;
    (void)pMax_distance_sqr;
    (void)pOffset_time;
    (void)pTime_period;
    (void)pCar_pos;
    (void)pTime_returned;
    (void)temp_ptr;

    NOT_IMPLEMENTED();
}

static int(*original_CheckIncident)(tPipe_chunk *, int, tU32, ...) = (int(*)(tPipe_chunk *, int, tU32, ...))0x0042c90d;
CARM95_HOOK_FUNCTION(original_CheckIncident, CheckIncident)
int CheckIncident(tPipe_chunk *pChunk_ptr, int pChunk_count, tU32 pTime) {
    LOG_TRACE("(%p, %d, %u)", pChunk_ptr, pChunk_count, pTime);

    (void)pChunk_ptr;
    (void)pChunk_count;
    (void)pTime;

    return original_CheckIncident(pChunk_ptr, pChunk_count, pTime);
}

static int(*original_GetNextIncident)(tU32, tIncident_type *, float *, tIncident_info *, tU32 *, ...) = (int(*)(tU32, tIncident_type *, float *, tIncident_info *, tU32 *, ...))0x0042c6a3;
CARM95_HOOK_FUNCTION(original_GetNextIncident, GetNextIncident)
int GetNextIncident(tU32 pOffset_time, tIncident_type *pIncident_type, float *pSeverity, tIncident_info *pInfo, tU32 *pTime_away) {
    tU8 *temp_ptr;
    LOG_TRACE("(%u, %p, %p, %p, %p)", pOffset_time, pIncident_type, pSeverity, pInfo, pTime_away);

    (void)pOffset_time;
    (void)pIncident_type;
    (void)pSeverity;
    (void)pInfo;
    (void)pTime_away;
    (void)temp_ptr;

    return original_GetNextIncident(pOffset_time, pIncident_type, pSeverity, pInfo, pTime_away);
}

tU32 GetARStartTime() {
    tU8 *temp_ptr;
    LOG_TRACE("()");

    (void)temp_ptr;

    NOT_IMPLEMENTED();
}

