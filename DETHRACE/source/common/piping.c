#include "piping.h"

#include "harness/trace.h"

#include "carm95_hooks.h"

tU8 ** hookvar_gPipe_buffer_start  = (void*)0x0050ba00;
int * hookvar_gDisable_sound  = (void*)0x0050ba04;
int * hookvar_gDisable_advance  = (void*)0x0050ba08;
int * hookvar_gMax_rewind_chunks  = (void*)0x0050ba0c;
float * hookvar_gWall_severity  = (void*)0x0050ba10;
tPipe_reset_proc*(* hookvar_gReset_procs )[32] = (void*)0x0050ba18;
#if 0
tPiped_registration_snapshot(* hookvar_gRegistration_snapshots )[5];
#endif
tPipe_smudge_data ** hookvar_gSmudge_space  = (void*)0x00531ffc;
tU32 * hookvar_gOldest_time  = (void*)0x00531ff8;
#if 0
int * hookvar_gCurrent_snapshot_registration_index ;
#endif
tPipe_chunk ** hookvar_gMr_chunky  = (void*)0x00531fa0;
tCar_spec ** hookvar_gCar_ptr  = (void*)0x00532040;
br_vector3 * hookvar_gZero_vector  = (void*)0x00532068;
tPipe_chunk_type(* hookvar_gReentrancy_array )[5] = (void*)0x00532050;
#if 0
tU32 * hookvar_gLast_time ;
#endif
tPipe_model_geometry_data ** hookvar_gModel_geometry_space  = (void*)0x0053204c;
#if 0
tU32 * hookvar_gEnd_time ;
#endif
tU32 * hookvar_gTrigger_time  = (void*)0x00532094;
int * hookvar_gReentrancy_count  = (void*)0x00532074;
br_vector3 * hookvar_gCar_pos  = (void*)0x00532030;
br_vector3 * hookvar_gReference_pos  = (void*)0x00532020;
br_scalar * hookvar_gMax_distance  = (void*)0x00532004;
#if 0
tU32 * hookvar_gLoop_abort_time ;
#endif
br_vector3 * hookvar_gWall_impact_point  = (void*)0x00532078;
tU8 ** hookvar_gPipe_buffer_working_end  = (void*)0x00532044;
tU32 * hookvar_gYoungest_time  = (void*)0x00532084;
tU8 ** hookvar_gPipe_buffer_phys_end  = (void*)0x0053208c;
#if 0
tU8 ** hookvar_gLocal_buffer_record_ptr ;
#endif
tU8 ** hookvar_gPipe_play_ptr  = (void*)0x00532018;
tU8 ** hookvar_gEnd_of_session  = (void*)0x00532048;
tU8 ** hookvar_gPipe_record_ptr  = (void*)0x0053201c;
tU8 ** hookvar_gPipe_buffer_oldest  = (void*)0x0053200c;
tU32 * hookvar_gPipe_buffer_size  = (void*)0x00532088;
tU8 ** hookvar_gLocal_buffer  = (void*)0x00532014;
tU32 * hookvar_gLocal_buffer_size  = (void*)0x00532090;

static void(__cdecl*original_GetReducedPos)(br_vector3 *, tReduced_pos *) = (void(__cdecl*)(br_vector3 *, tReduced_pos *))0x00427ed0;
CARM95_HOOK_FUNCTION(original_GetReducedPos, GetReducedPos)
void __cdecl GetReducedPos(br_vector3 *v, tReduced_pos *p) {
    LOG_TRACE("(%p, %p)", v, p);

    (void)v;
    (void)p;

    original_GetReducedPos(v, p);
}

static void(__cdecl*original_SaveReducedPos)(tReduced_pos *, br_vector3 *) = (void(__cdecl*)(tReduced_pos *, br_vector3 *))0x00427f61;
CARM95_HOOK_FUNCTION(original_SaveReducedPos, SaveReducedPos)
void __cdecl SaveReducedPos(tReduced_pos *p, br_vector3 *v) {
    br_vector3 tv;
    LOG_TRACE("(%p, %p)", p, v);

    (void)p;
    (void)v;
    (void)tv;

    original_SaveReducedPos(p, v);
}

static int(__cdecl*original_PipeSearchForwards)() = (int(__cdecl*)())0x00427fdf;
CARM95_HOOK_FUNCTION(original_PipeSearchForwards, PipeSearchForwards)
int __cdecl PipeSearchForwards() {
    LOG_TRACE("()");


    return original_PipeSearchForwards();
}

static int(__cdecl*original_IsActionReplayAvailable)() = (int(__cdecl*)())0x00428078;
CARM95_HOOK_FUNCTION(original_IsActionReplayAvailable, IsActionReplayAvailable)
int __cdecl IsActionReplayAvailable() {
    LOG_TRACE("()");


    return original_IsActionReplayAvailable();
}

static int(__cdecl*original_SomeReplayLeft)() = (int(__cdecl*)())0x004280a1;
CARM95_HOOK_FUNCTION(original_SomeReplayLeft, SomeReplayLeft)
int __cdecl SomeReplayLeft() {
    LOG_TRACE("()");


    return original_SomeReplayLeft();
}

static void(__cdecl*original_DisablePipedSounds)() = (void(__cdecl*)())0x004280f9;
CARM95_HOOK_FUNCTION(original_DisablePipedSounds, DisablePipedSounds)
void __cdecl DisablePipedSounds() {
    LOG_TRACE("()");


    original_DisablePipedSounds();
}

static void(__cdecl*original_EnablePipedSounds)() = (void(__cdecl*)())0x0042810e;
CARM95_HOOK_FUNCTION(original_EnablePipedSounds, EnablePipedSounds)
void __cdecl EnablePipedSounds() {
    LOG_TRACE("()");


    original_EnablePipedSounds();
}

static tU32(__cdecl*original_LengthOfSession)(tPipe_session *) = (tU32(__cdecl*)(tPipe_session *))0x00428123;
CARM95_HOOK_FUNCTION(original_LengthOfSession, LengthOfSession)
tU32 __cdecl LengthOfSession(tPipe_session *pSession) {
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

static void(__cdecl*original_StartPipingSession2)(tPipe_chunk_type, int) = (void(__cdecl*)(tPipe_chunk_type, int))0x004285e1;
CARM95_HOOK_FUNCTION(original_StartPipingSession2, StartPipingSession2)
void __cdecl StartPipingSession2(tPipe_chunk_type pThe_type, int pMunge_reentrancy) {
    LOG_TRACE("(%d, %d)", pThe_type, pMunge_reentrancy);

    (void)pThe_type;
    (void)pMunge_reentrancy;

    original_StartPipingSession2(pThe_type, pMunge_reentrancy);
}

static void(__cdecl*original_StartPipingSession)(tPipe_chunk_type) = (void(__cdecl*)(tPipe_chunk_type))0x0042868f;
CARM95_HOOK_FUNCTION(original_StartPipingSession, StartPipingSession)
void __cdecl StartPipingSession(tPipe_chunk_type pThe_type) {
    LOG_TRACE("(%d)", pThe_type);

    (void)pThe_type;

    original_StartPipingSession(pThe_type);
}

static void(__cdecl*original_EndPipingSession2)(int) = (void(__cdecl*)(int))0x004286a8;
CARM95_HOOK_FUNCTION(original_EndPipingSession2, EndPipingSession2)
void __cdecl EndPipingSession2(int pMunge_reentrancy) {
    int a;
    LOG_TRACE("(%d)", pMunge_reentrancy);

    (void)pMunge_reentrancy;
    (void)a;

    original_EndPipingSession2(pMunge_reentrancy);
}

static void(__cdecl*original_EndPipingSession)() = (void(__cdecl*)())0x0042884c;
CARM95_HOOK_FUNCTION(original_EndPipingSession, EndPipingSession)
void __cdecl EndPipingSession() {
    LOG_TRACE("()");


    original_EndPipingSession();
}

static void(__cdecl*original_AddDataToSession)(int, void *, tU32) = (void(__cdecl*)(int, void *, tU32))0x00428861;
CARM95_HOOK_FUNCTION(original_AddDataToSession, AddDataToSession)
void __cdecl AddDataToSession(int pSubject_index, void *pData, tU32 pData_length) {
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

static void(__cdecl*original_AddModelGeometryToPipingSession)(tU16, int, int, tChanged_vertex *) = (void(__cdecl*)(tU16, int, int, tChanged_vertex *))0x00428904;
CARM95_HOOK_FUNCTION(original_AddModelGeometryToPipingSession, AddModelGeometryToPipingSession)
void __cdecl AddModelGeometryToPipingSession(tU16 pCar_ID, int pModel_index, int pVertex_count, tChanged_vertex *pCoordinates) {
    tU32 data_size;
    LOG_TRACE("(%u, %d, %d, %p)", pCar_ID, pModel_index, pVertex_count, pCoordinates);

    (void)pCar_ID;
    (void)pModel_index;
    (void)pVertex_count;
    (void)pCoordinates;
    (void)data_size;

    original_AddModelGeometryToPipingSession(pCar_ID, pModel_index, pVertex_count, pCoordinates);
}

static void(__cdecl*original_AddSmudgeToPipingSession)(tU16, int, int, tSmudged_vertex *) = (void(__cdecl*)(tU16, int, int, tSmudged_vertex *))0x0042898f;
CARM95_HOOK_FUNCTION(original_AddSmudgeToPipingSession, AddSmudgeToPipingSession)
void __cdecl AddSmudgeToPipingSession(tU16 pCar_ID, int pModel_index, int pVertex_count, tSmudged_vertex *pCoordinates) {
    tU32 data_size;
    LOG_TRACE("(%u, %d, %d, %p)", pCar_ID, pModel_index, pVertex_count, pCoordinates);

    (void)pCar_ID;
    (void)pModel_index;
    (void)pVertex_count;
    (void)pCoordinates;
    (void)data_size;

    original_AddSmudgeToPipingSession(pCar_ID, pModel_index, pVertex_count, pCoordinates);
}

static void(__cdecl*original_AddPedestrianToPipingSession)(int, br_matrix34 *, tU8, tU8, tS8, int, tU16, float, br_scalar, br_vector3 *) = (void(__cdecl*)(int, br_matrix34 *, tU8, tU8, tS8, int, tU16, float, br_scalar, br_vector3 *))0x00428a1a;
CARM95_HOOK_FUNCTION(original_AddPedestrianToPipingSession, AddPedestrianToPipingSession)
void __cdecl AddPedestrianToPipingSession(int pPedestrian_index, br_matrix34 *pTrans, tU8 pAction_index, tU8 pFrame_index, tS8 pHit_points, int pDone_initial, tU16 pParent_ID, float pSpin_period, br_scalar pJump_magnitude, br_vector3 *pOffset) {
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

static void(__cdecl*original_AddSparkToPipingSession)(int, br_vector3 *, br_vector3 *) = (void(__cdecl*)(int, br_vector3 *, br_vector3 *))0x00428af9;
CARM95_HOOK_FUNCTION(original_AddSparkToPipingSession, AddSparkToPipingSession)
void __cdecl AddSparkToPipingSession(int pSpark_index, br_vector3 *pPos, br_vector3 *pV) {
    tPipe_spark_data data;
    LOG_TRACE("(%d, %p, %p)", pSpark_index, pPos, pV);

    (void)pSpark_index;
    (void)pPos;
    (void)pV;
    (void)data;

    original_AddSparkToPipingSession(pSpark_index, pPos, pV);
}

static void(__cdecl*original_AddShrapnelToPipingSession)(int, br_vector3 *, tU16, br_material *) = (void(__cdecl*)(int, br_vector3 *, tU16, br_material *))0x00428b4d;
CARM95_HOOK_FUNCTION(original_AddShrapnelToPipingSession, AddShrapnelToPipingSession)
void __cdecl AddShrapnelToPipingSession(int pShrapnel_index, br_vector3 *pPos, tU16 pAge, br_material *pMaterial) {
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

static void(__cdecl*original_AddScreenWobbleToPipingSession)(int, int) = (void(__cdecl*)(int, int))0x00428bb4;
CARM95_HOOK_FUNCTION(original_AddScreenWobbleToPipingSession, AddScreenWobbleToPipingSession)
void __cdecl AddScreenWobbleToPipingSession(int pWobble_x, int pWobble_y) {
    tPipe_screen_shake_data data;
    LOG_TRACE("(%d, %d)", pWobble_x, pWobble_y);

    (void)pWobble_x;
    (void)pWobble_y;
    (void)data;

    original_AddScreenWobbleToPipingSession(pWobble_x, pWobble_y);
}

static void(__cdecl*original_AddGrooveStopToPipingSession)(int, br_matrix34 *, int, int, float, float) = (void(__cdecl*)(int, br_matrix34 *, int, int, float, float))0x00428bde;
CARM95_HOOK_FUNCTION(original_AddGrooveStopToPipingSession, AddGrooveStopToPipingSession)
void __cdecl AddGrooveStopToPipingSession(int pGroove_index, br_matrix34 *pMatrix, int pPath_interrupt, int pObject_interrupt, float pPath_resumption, float pObject_resumption) {
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

static void(__cdecl*original_AddNonCarToPipingSession)(int, br_actor *) = (void(__cdecl*)(int, br_actor *))0x00428c26;
CARM95_HOOK_FUNCTION(original_AddNonCarToPipingSession, AddNonCarToPipingSession)
void __cdecl AddNonCarToPipingSession(int pIndex, br_actor *pActor) {
    tPipe_non_car_data data;
    LOG_TRACE("(%d, %p)", pIndex, pActor);

    (void)pIndex;
    (void)pActor;
    (void)data;

    original_AddNonCarToPipingSession(pIndex, pActor);
}

static void(__cdecl*original_AddSmokeToPipingSession)(int, tU8, br_vector3 *, br_scalar, br_scalar) = (void(__cdecl*)(int, tU8, br_vector3 *, br_scalar, br_scalar))0x00428c5f;
CARM95_HOOK_FUNCTION(original_AddSmokeToPipingSession, AddSmokeToPipingSession)
void __cdecl AddSmokeToPipingSession(int pIndex, tU8 pType, br_vector3 *pPos, br_scalar pRadius, br_scalar pStrength) {
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

static void(__cdecl*original_AddSmokeColumnToPipingSession)(int, tCar_spec *, int, int) = (void(__cdecl*)(int, tCar_spec *, int, int))0x00428cb8;
CARM95_HOOK_FUNCTION(original_AddSmokeColumnToPipingSession, AddSmokeColumnToPipingSession)
void __cdecl AddSmokeColumnToPipingSession(int pIndex, tCar_spec *pCar, int pVertex, int pColour) {
    tPipe_smoke_column_data data;
    LOG_TRACE("(%d, %p, %d, %d)", pIndex, pCar, pVertex, pColour);

    (void)pIndex;
    (void)pCar;
    (void)pVertex;
    (void)pColour;
    (void)data;

    original_AddSmokeColumnToPipingSession(pIndex, pCar, pVertex, pColour);
}

static void(__cdecl*original_AddFlameToPipingSession)(int, int, br_scalar, br_scalar, br_scalar, br_scalar) = (void(__cdecl*)(int, int, br_scalar, br_scalar, br_scalar, br_scalar))0x00428cf7;
CARM95_HOOK_FUNCTION(original_AddFlameToPipingSession, AddFlameToPipingSession)
void __cdecl AddFlameToPipingSession(int pIndex, int pFrame_count, br_scalar pScale_x, br_scalar pScale_y, br_scalar pOffset_x, br_scalar pOffset_z) {
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

static void(__cdecl*original_AddSplashToPipingSession)(tCollision_info *) = (void(__cdecl*)(tCollision_info *))0x00428d36;
CARM95_HOOK_FUNCTION(original_AddSplashToPipingSession, AddSplashToPipingSession)
void __cdecl AddSplashToPipingSession(tCollision_info *pCar) {
    tPipe_splash_data data;
    LOG_TRACE("(%p)", pCar);

    (void)pCar;
    (void)data;

    original_AddSplashToPipingSession(pCar);
}

static void(__cdecl*original_AddOilSpillToPipingSession)(int, br_matrix34 *, br_scalar, br_scalar, tU32, tU32, tCar_spec *, br_vector3 *, br_pixelmap *) = (void(__cdecl*)(int, br_matrix34 *, br_scalar, br_scalar, tU32, tU32, tCar_spec *, br_vector3 *, br_pixelmap *))0x00428da1;
CARM95_HOOK_FUNCTION(original_AddOilSpillToPipingSession, AddOilSpillToPipingSession)
void __cdecl AddOilSpillToPipingSession(int pIndex, br_matrix34 *pMat, br_scalar pFull_size, br_scalar pGrow_rate, tU32 pSpill_time, tU32 pStop_time, tCar_spec *pCar, br_vector3 *pOriginal_pos, br_pixelmap *pPixelmap) {
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

static void(__cdecl*original_AddFrameFinishToPipingSession)(tU32) = (void(__cdecl*)(tU32))0x00428e0f;
CARM95_HOOK_FUNCTION(original_AddFrameFinishToPipingSession, AddFrameFinishToPipingSession)
void __cdecl AddFrameFinishToPipingSession(tU32 pThe_time) {
    tPipe_frame_boundary_data data;
    LOG_TRACE("(%u)", pThe_time);

    (void)pThe_time;
    (void)data;

    original_AddFrameFinishToPipingSession(pThe_time);
}

static void(__cdecl*original_AddCarToPipingSession)(int, br_matrix34 *, br_vector3 *, float, float, float, float, float, float, br_scalar, int, int) = (void(__cdecl*)(int, br_matrix34 *, br_vector3 *, float, float, float, float, float, float, br_scalar, int, int))0x00428e33;
CARM95_HOOK_FUNCTION(original_AddCarToPipingSession, AddCarToPipingSession)
void __cdecl AddCarToPipingSession(int pCar_ID, br_matrix34 *pCar_mat, br_vector3 *pCar_velocity, float pSpeedo_speed, float pLf_sus_position, float pRf_sus_position, float pLr_sus_position, float pRr_sus_position, float pSteering_angle, br_scalar pRevs, int pGear, int pFrame_coll_flag) {
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

static void(__cdecl*original_AddSoundToPipingSession)(tS3_outlet_ptr, int, tS3_volume, tS3_volume, tS3_pitch, br_vector3 *) = (void(__cdecl*)(tS3_outlet_ptr, int, tS3_volume, tS3_volume, tS3_pitch, br_vector3 *))0x00428f38;
CARM95_HOOK_FUNCTION(original_AddSoundToPipingSession, AddSoundToPipingSession)
void __cdecl AddSoundToPipingSession(tS3_outlet_ptr pOutlet, int pSound_index, tS3_volume pL_volume, tS3_volume pR_volume, tS3_pitch pPitch, br_vector3 *pPos) {
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

static void(__cdecl*original_AddDamageToPipingSession)(int, tS8 *) = (void(__cdecl*)(int, tS8 *))0x00428fb5;
CARM95_HOOK_FUNCTION(original_AddDamageToPipingSession, AddDamageToPipingSession)
void __cdecl AddDamageToPipingSession(int pCar_ID, tS8 *pDifferences) {
    tPipe_damage_data data;
    int i;
    LOG_TRACE("(%d, %p)", pCar_ID, pDifferences);

    (void)pCar_ID;
    (void)pDifferences;
    (void)data;
    (void)i;

    original_AddDamageToPipingSession(pCar_ID, pDifferences);
}

static void(__cdecl*original_AddSpecialToPipingSession)(tSpecial_type) = (void(__cdecl*)(tSpecial_type))0x00429003;
CARM95_HOOK_FUNCTION(original_AddSpecialToPipingSession, AddSpecialToPipingSession)
void __cdecl AddSpecialToPipingSession(tSpecial_type pType) {
    tPipe_special_data data;
    LOG_TRACE("(%d)", pType);

    (void)pType;
    (void)data;

    original_AddSpecialToPipingSession(pType);
}

static void(__cdecl*original_AddPedGibToPipingSession)(int, br_matrix34 *, int, int, int) = (void(__cdecl*)(int, br_matrix34 *, int, int, int))0x00429023;
CARM95_HOOK_FUNCTION(original_AddPedGibToPipingSession, AddPedGibToPipingSession)
void __cdecl AddPedGibToPipingSession(int pIndex, br_matrix34 *pTrans, int pSize, int pGib_index, int pPed_index) {
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

static void(__cdecl*original_AddCarIncidentToPipingSession)(float, tCar_spec *, br_vector3 *) = (void(__cdecl*)(float, tCar_spec *, br_vector3 *))0x00429063;
CARM95_HOOK_FUNCTION(original_AddCarIncidentToPipingSession, AddCarIncidentToPipingSession)
void __cdecl AddCarIncidentToPipingSession(float pSeverity, tCar_spec *pCar, br_vector3 *pImpact_point) {
    tPipe_incident_data data;
    LOG_TRACE("(%f, %p, %p)", pSeverity, pCar, pImpact_point);

    (void)pSeverity;
    (void)pCar;
    (void)pImpact_point;
    (void)data;

    original_AddCarIncidentToPipingSession(pSeverity, pCar, pImpact_point);
}

static void(__cdecl*original_AddPedIncidentToPipingSession)(int, br_actor *) = (void(__cdecl*)(int, br_actor *))0x004290ab;
CARM95_HOOK_FUNCTION(original_AddPedIncidentToPipingSession, AddPedIncidentToPipingSession)
void __cdecl AddPedIncidentToPipingSession(int pPed_index, br_actor *pActor) {
    tPipe_incident_data data;
    LOG_TRACE("(%d, %p)", pPed_index, pActor);

    (void)pPed_index;
    (void)pActor;
    (void)data;

    original_AddPedIncidentToPipingSession(pPed_index, pActor);
}

static void(__cdecl*original_AddWallIncidentToPipingSession)(float, br_vector3 *) = (void(__cdecl*)(float, br_vector3 *))0x004290dd;
CARM95_HOOK_FUNCTION(original_AddWallIncidentToPipingSession, AddWallIncidentToPipingSession)
void __cdecl AddWallIncidentToPipingSession(float pSeverity, br_vector3 *pImpact_point) {
    tPipe_incident_data data;
    LOG_TRACE("(%f, %p)", pSeverity, pImpact_point);

    (void)pSeverity;
    (void)pImpact_point;
    (void)data;

    original_AddWallIncidentToPipingSession(pSeverity, pImpact_point);
}

static void(__cdecl*original_AddProxRayToPipingSession)(int, tCar_spec *, tU16, tU32) = (void(__cdecl*)(int, tCar_spec *, tU16, tU32))0x00429117;
CARM95_HOOK_FUNCTION(original_AddProxRayToPipingSession, AddProxRayToPipingSession)
void __cdecl AddProxRayToPipingSession(int pRay_index, tCar_spec *pCar, tU16 pPed_index, tU32 pTime) {
    tPipe_prox_ray_data data;
    LOG_TRACE("(%d, %p, %u, %u)", pRay_index, pCar, pPed_index, pTime);

    (void)pRay_index;
    (void)pCar;
    (void)pPed_index;
    (void)pTime;
    (void)data;

    original_AddProxRayToPipingSession(pRay_index, pCar, pPed_index, pTime);
}

static void(__cdecl*original_AddSkidAdjustmentToPipingSession)(int, br_matrix34 *, int) = (void(__cdecl*)(int, br_matrix34 *, int))0x00429153;
CARM95_HOOK_FUNCTION(original_AddSkidAdjustmentToPipingSession, AddSkidAdjustmentToPipingSession)
void __cdecl AddSkidAdjustmentToPipingSession(int pSkid_num, br_matrix34 *pMatrix, int pMaterial_index) {
    tPipe_skid_adjustment adjustment;
    LOG_TRACE("(%d, %p, %d)", pSkid_num, pMatrix, pMaterial_index);

    (void)pSkid_num;
    (void)pMatrix;
    (void)pMaterial_index;
    (void)adjustment;

    original_AddSkidAdjustmentToPipingSession(pSkid_num, pMatrix, pMaterial_index);
}

static void(__cdecl*original_PipeSingleModelGeometry)(tU16, int, int, tChanged_vertex *) = (void(__cdecl*)(tU16, int, int, tChanged_vertex *))0x00429186;
CARM95_HOOK_FUNCTION(original_PipeSingleModelGeometry, PipeSingleModelGeometry)
void __cdecl PipeSingleModelGeometry(tU16 pCar_ID, int pModel_index, int pVertex_count, tChanged_vertex *pCoordinates) {
    LOG_TRACE("(%u, %d, %d, %p)", pCar_ID, pModel_index, pVertex_count, pCoordinates);

    (void)pCar_ID;
    (void)pModel_index;
    (void)pVertex_count;
    (void)pCoordinates;

    original_PipeSingleModelGeometry(pCar_ID, pModel_index, pVertex_count, pCoordinates);
}

static void(__cdecl*original_PipeSinglePedestrian)(int, br_matrix34 *, tU8, tU8, tS8, int, tU16, float, br_scalar, br_vector3 *) = (void(__cdecl*)(int, br_matrix34 *, tU8, tU8, tS8, int, tU16, float, br_scalar, br_vector3 *))0x004291b8;
CARM95_HOOK_FUNCTION(original_PipeSinglePedestrian, PipeSinglePedestrian)
void __cdecl PipeSinglePedestrian(int pPedestrian_index, br_matrix34 *pTrans, tU8 pAction_index, tU8 pFrame_index, tS8 pHit_points, int pDone_initial, tU16 pParent_ID, float pSpin_period, br_scalar pJump_magnitude, br_vector3 *pOffset) {
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

static void(__cdecl*original_PipeSingleCar)(int, br_matrix34 *, br_vector3 *, float, float, float, float, float, float, br_scalar, int, int) = (void(__cdecl*)(int, br_matrix34 *, br_vector3 *, float, float, float, float, float, float, br_scalar, int, int))0x00429202;
CARM95_HOOK_FUNCTION(original_PipeSingleCar, PipeSingleCar)
void __cdecl PipeSingleCar(int pCar_ID, br_matrix34 *pCar_mat, br_vector3 *pCar_velocity, float pSpeedo_speed, float pLf_sus_position, float pRf_sus_position, float pLr_sus_position, float pRr_sus_position, float pSteering_angle, br_scalar pRevs, int pGear, int pFrame_coll_flag) {
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

static void(__cdecl*original_PipeSingleSound)(tS3_outlet_ptr, int, tS3_volume, tS3_volume, tS3_pitch, br_vector3 *) = (void(__cdecl*)(tS3_outlet_ptr, int, tS3_volume, tS3_volume, tS3_pitch, br_vector3 *))0x00429254;
CARM95_HOOK_FUNCTION(original_PipeSingleSound, PipeSingleSound)
void __cdecl PipeSingleSound(tS3_outlet_ptr pOutlet, int pSound_index, tS3_volume pL_volume, tS3_volume pR_volume, tS3_pitch pPitch, br_vector3 *pPos) {
    LOG_TRACE("(\"%s\", %d, %d, %d, %d, %p)", pOutlet, pSound_index, pL_volume, pR_volume, pPitch, pPos);

    (void)pOutlet;
    (void)pSound_index;
    (void)pL_volume;
    (void)pR_volume;
    (void)pPitch;
    (void)pPos;

    original_PipeSingleSound(pOutlet, pSound_index, pL_volume, pR_volume, pPitch, pPos);
}

static void(__cdecl*original_PipeSingleOilSpill)(int, br_matrix34 *, br_scalar, br_scalar, tU32, tU32, tCar_spec *, br_vector3 *, br_pixelmap *) = (void(__cdecl*)(int, br_matrix34 *, br_scalar, br_scalar, tU32, tU32, tCar_spec *, br_vector3 *, br_pixelmap *))0x004292a8;
CARM95_HOOK_FUNCTION(original_PipeSingleOilSpill, PipeSingleOilSpill)
void __cdecl PipeSingleOilSpill(int pIndex, br_matrix34 *pMat, br_scalar pFull_size, br_scalar pGrow_rate, tU32 pSpill_time, tU32 pStop_time, tCar_spec *pCar, br_vector3 *pOriginal_pos, br_pixelmap *pPixelmap) {
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

static void(__cdecl*original_PipeSingleDamage)(int, tS8 *) = (void(__cdecl*)(int, tS8 *))0x004292ee;
CARM95_HOOK_FUNCTION(original_PipeSingleDamage, PipeSingleDamage)
void __cdecl PipeSingleDamage(int pCar_ID, tS8 *pDifferences) {
    LOG_TRACE("(%d, %p)", pCar_ID, pDifferences);

    (void)pCar_ID;
    (void)pDifferences;

    original_PipeSingleDamage(pCar_ID, pDifferences);
}

static void(__cdecl*original_PipeSingleSpecial)(tSpecial_type) = (void(__cdecl*)(tSpecial_type))0x00429318;
CARM95_HOOK_FUNCTION(original_PipeSingleSpecial, PipeSingleSpecial)
void __cdecl PipeSingleSpecial(tSpecial_type pType) {
    LOG_TRACE("(%d)", pType);

    (void)pType;

    original_PipeSingleSpecial(pType);
}

static void(__cdecl*original_PipeSinglePedGib)(int, br_matrix34 *, int, int, int) = (void(__cdecl*)(int, br_matrix34 *, int, int, int))0x0042933e;
CARM95_HOOK_FUNCTION(original_PipeSinglePedGib, PipeSinglePedGib)
void __cdecl PipeSinglePedGib(int pIndex, br_matrix34 *pTrans, int pSize, int pGib_index, int pPed_index) {
    LOG_TRACE("(%d, %p, %d, %d, %d)", pIndex, pTrans, pSize, pGib_index, pPed_index);

    (void)pIndex;
    (void)pTrans;
    (void)pSize;
    (void)pGib_index;
    (void)pPed_index;

    original_PipeSinglePedGib(pIndex, pTrans, pSize, pGib_index, pPed_index);
}

static void(__cdecl*original_PipeSingleCarIncident)(float, tCar_spec *, br_vector3 *) = (void(__cdecl*)(float, tCar_spec *, br_vector3 *))0x00429374;
CARM95_HOOK_FUNCTION(original_PipeSingleCarIncident, PipeSingleCarIncident)
void __cdecl PipeSingleCarIncident(float pSeverity, tCar_spec *pCar, br_vector3 *pImpact_point) {
    LOG_TRACE("(%f, %p, %p)", pSeverity, pCar, pImpact_point);

    (void)pSeverity;
    (void)pCar;
    (void)pImpact_point;

    original_PipeSingleCarIncident(pSeverity, pCar, pImpact_point);
}

static void(__cdecl*original_PipeSinglePedIncident)(int, br_actor *) = (void(__cdecl*)(int, br_actor *))0x004293a2;
CARM95_HOOK_FUNCTION(original_PipeSinglePedIncident, PipeSinglePedIncident)
void __cdecl PipeSinglePedIncident(int pPed_index, br_actor *pActor) {
    LOG_TRACE("(%d, %p)", pPed_index, pActor);

    (void)pPed_index;
    (void)pActor;

    original_PipeSinglePedIncident(pPed_index, pActor);
}

static void(__cdecl*original_PipeSingleWallIncident)(float, br_vector3 *) = (void(__cdecl*)(float, br_vector3 *))0x004293d6;
CARM95_HOOK_FUNCTION(original_PipeSingleWallIncident, PipeSingleWallIncident)
void __cdecl PipeSingleWallIncident(float pSeverity, br_vector3 *pImpact_point) {
    LOG_TRACE("(%f, %p)", pSeverity, pImpact_point);

    (void)pSeverity;
    (void)pImpact_point;

    original_PipeSingleWallIncident(pSeverity, pImpact_point);
}

static void(__cdecl*original_PipeSingleScreenShake)(int, int) = (void(__cdecl*)(int, int))0x00429415;
CARM95_HOOK_FUNCTION(original_PipeSingleScreenShake, PipeSingleScreenShake)
void __cdecl PipeSingleScreenShake(int pWobble_x, int pWobble_y) {
    LOG_TRACE("(%d, %d)", pWobble_x, pWobble_y);

    (void)pWobble_x;
    (void)pWobble_y;

    original_PipeSingleScreenShake(pWobble_x, pWobble_y);
}

static void(__cdecl*original_PipeSingleGrooveStop)(int, br_matrix34 *, int, int, float, float) = (void(__cdecl*)(int, br_matrix34 *, int, int, float, float))0x0042943f;
CARM95_HOOK_FUNCTION(original_PipeSingleGrooveStop, PipeSingleGrooveStop)
void __cdecl PipeSingleGrooveStop(int pGroove_index, br_matrix34 *pMatrix, int pPath_interrupt, int pObject_interrupt, float pPath_resumption, float pObject_resumption) {
    LOG_TRACE("(%d, %p, %d, %d, %f, %f)", pGroove_index, pMatrix, pPath_interrupt, pObject_interrupt, pPath_resumption, pObject_resumption);

    (void)pGroove_index;
    (void)pMatrix;
    (void)pPath_interrupt;
    (void)pObject_interrupt;
    (void)pPath_resumption;
    (void)pObject_resumption;

    original_PipeSingleGrooveStop(pGroove_index, pMatrix, pPath_interrupt, pObject_interrupt, pPath_resumption, pObject_resumption);
}

static void(__cdecl*original_PipeFrameFinish)() = (void(__cdecl*)())0x00429479;
CARM95_HOOK_FUNCTION(original_PipeFrameFinish, PipeFrameFinish)
void __cdecl PipeFrameFinish() {
    LOG_TRACE("()");


    original_PipeFrameFinish();
}

static void(__cdecl*original_PipingFrameReset)() = (void(__cdecl*)())0x004294e4;
CARM95_HOOK_FUNCTION(original_PipingFrameReset, PipingFrameReset)
void __cdecl PipingFrameReset() {
    int i;
    LOG_TRACE("()");

    (void)i;

    original_PipingFrameReset();
}

static void(__cdecl*original_PipeSingleSkidAdjustment)(int, br_matrix34 *, int) = (void(__cdecl*)(int, br_matrix34 *, int))0x0042952b;
CARM95_HOOK_FUNCTION(original_PipeSingleSkidAdjustment, PipeSingleSkidAdjustment)
void __cdecl PipeSingleSkidAdjustment(int pSkid_num, br_matrix34 *pMatrix, int pMaterial_index) {
    LOG_TRACE("(%d, %p, %d)", pSkid_num, pMatrix, pMaterial_index);

    (void)pSkid_num;
    (void)pMatrix;
    (void)pMaterial_index;

    original_PipeSingleSkidAdjustment(pSkid_num, pMatrix, pMaterial_index);
}

static void(__cdecl*original_ResetPiping)() = (void(__cdecl*)())0x00429559;
CARM95_HOOK_FUNCTION(original_ResetPiping, ResetPiping)
void __cdecl ResetPiping() {
    LOG_TRACE("()");


    original_ResetPiping();
}

static void(__cdecl*original_InitialisePiping)() = (void(__cdecl*)())0x00429596;
CARM95_HOOK_FUNCTION(original_InitialisePiping, InitialisePiping)
void __cdecl InitialisePiping() {
    LOG_TRACE("()");


    original_InitialisePiping();
}

static void(__cdecl*original_DisposePiping)() = (void(__cdecl*)())0x0042966f;
CARM95_HOOK_FUNCTION(original_DisposePiping, DisposePiping)
void __cdecl DisposePiping() {
    LOG_TRACE("()");


    original_DisposePiping();
}

static void(__cdecl*original_InitLastDamageArrayEtc)() = (void(__cdecl*)())0x004296e9;
CARM95_HOOK_FUNCTION(original_InitLastDamageArrayEtc, InitLastDamageArrayEtc)
void __cdecl InitLastDamageArrayEtc() {
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

static void(__cdecl*original_ResetCars)() = (void(__cdecl*)())0x004297d2;
CARM95_HOOK_FUNCTION(original_ResetCars, ResetCars)
void __cdecl ResetCars() {
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

static void(__cdecl*original_PipeCarPositions)() = (void(__cdecl*)())0x0042987f;
CARM95_HOOK_FUNCTION(original_PipeCarPositions, PipeCarPositions)
void __cdecl PipeCarPositions() {
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

static void(__cdecl*original_ResetPipePlayToEnd)() = (void(__cdecl*)())0x00429b22;
CARM95_HOOK_FUNCTION(original_ResetPipePlayToEnd, ResetPipePlayToEnd)
void __cdecl ResetPipePlayToEnd() {
    LOG_TRACE("()");


    original_ResetPipePlayToEnd();
}

static void(__cdecl*original_ResetPipePlayToStart)() = (void(__cdecl*)())0x00429b37;
CARM95_HOOK_FUNCTION(original_ResetPipePlayToStart, ResetPipePlayToStart)
void __cdecl ResetPipePlayToStart() {
    LOG_TRACE("()");


    original_ResetPipePlayToStart();
}

static tU8 *(__cdecl*original_GetPipePlayPtr)() = (tU8 *(__cdecl*)())0x00429b4c;
CARM95_HOOK_FUNCTION(original_GetPipePlayPtr, GetPipePlayPtr)
tU8* __cdecl GetPipePlayPtr() {
    LOG_TRACE("()");


    return original_GetPipePlayPtr();
}

static void(__cdecl*original_SetPipePlayPtr)(tU8 *) = (void(__cdecl*)(tU8 *))0x00429b61;
CARM95_HOOK_FUNCTION(original_SetPipePlayPtr, SetPipePlayPtr)
void __cdecl SetPipePlayPtr(tU8 *pPtr) {
    LOG_TRACE("(%p)", pPtr);

    (void)pPtr;

    original_SetPipePlayPtr(pPtr);
}

static void(__cdecl*original_AdvanceChunkPtr)(tPipe_chunk **, tChunk_subject_index) = (void(__cdecl*)(tPipe_chunk **, tChunk_subject_index))0x00429fcd;
CARM95_HOOK_FUNCTION(original_AdvanceChunkPtr, AdvanceChunkPtr)
void __cdecl AdvanceChunkPtr(tPipe_chunk **pChunk, tChunk_subject_index pType) {
    tPipe_chunk *old_chunk;
    LOG_TRACE("(%p, %u)", pChunk, pType);

    (void)pChunk;
    (void)pType;
    (void)old_chunk;

    original_AdvanceChunkPtr(pChunk, pType);
}

static void(__cdecl*original_ApplyModelGeometry)(tPipe_chunk **) = (void(__cdecl*)(tPipe_chunk **))0x0042a1fd;
CARM95_HOOK_FUNCTION(original_ApplyModelGeometry, ApplyModelGeometry)
void __cdecl ApplyModelGeometry(tPipe_chunk **pChunk) {
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

static void(__cdecl*original_DoSmudge)(tPipe_chunk **, int) = (void(__cdecl*)(tPipe_chunk **, int))0x00429b74;
CARM95_HOOK_FUNCTION(original_DoSmudge, DoSmudge)
void __cdecl DoSmudge(tPipe_chunk **pChunk, int pDir) {
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

    original_DoSmudge(pChunk, pDir);
}

static void(__cdecl*original_ApplySmudge)(tPipe_chunk **) = (void(__cdecl*)(tPipe_chunk **))0x0042a3b1;
CARM95_HOOK_FUNCTION(original_ApplySmudge, ApplySmudge)
void __cdecl ApplySmudge(tPipe_chunk **pChunk) {
    LOG_TRACE("(%p)", pChunk);

    (void)pChunk;

    original_ApplySmudge(pChunk);
}

static void(__cdecl*original_ApplyPedestrian)(tPipe_chunk **) = (void(__cdecl*)(tPipe_chunk **))0x0042a3d8;
CARM95_HOOK_FUNCTION(original_ApplyPedestrian, ApplyPedestrian)
void __cdecl ApplyPedestrian(tPipe_chunk **pChunk) {
    LOG_TRACE("(%p)", pChunk);

    (void)pChunk;

    original_ApplyPedestrian(pChunk);
}

static void(__cdecl*original_ApplySpark)(tPipe_chunk **) = (void(__cdecl*)(tPipe_chunk **))0x0042a472;
CARM95_HOOK_FUNCTION(original_ApplySpark, ApplySpark)
void __cdecl ApplySpark(tPipe_chunk **pChunk) {
    LOG_TRACE("(%p)", pChunk);

    (void)pChunk;

    original_ApplySpark(pChunk);
}

static void(__cdecl*original_ApplyShrapnel)(tPipe_chunk **) = (void(__cdecl*)(tPipe_chunk **))0x0042a4b0;
CARM95_HOOK_FUNCTION(original_ApplyShrapnel, ApplyShrapnel)
void __cdecl ApplyShrapnel(tPipe_chunk **pChunk) {
    LOG_TRACE("(%p)", pChunk);

    (void)pChunk;

    original_ApplyShrapnel(pChunk);
}

static void(__cdecl*original_ApplyScreenWobble)(tPipe_chunk **) = (void(__cdecl*)(tPipe_chunk **))0x0042a4f8;
CARM95_HOOK_FUNCTION(original_ApplyScreenWobble, ApplyScreenWobble)
void __cdecl ApplyScreenWobble(tPipe_chunk **pChunk) {
    LOG_TRACE("(%p)", pChunk);

    (void)pChunk;

    original_ApplyScreenWobble(pChunk);
}

static void(__cdecl*original_ApplyGrooveStop)(tPipe_chunk **) = (void(__cdecl*)(tPipe_chunk **))0x0042a52d;
CARM95_HOOK_FUNCTION(original_ApplyGrooveStop, ApplyGrooveStop)
void __cdecl ApplyGrooveStop(tPipe_chunk **pChunk) {
    LOG_TRACE("(%p)", pChunk);

    (void)pChunk;

    original_ApplyGrooveStop(pChunk);
}

static void(__cdecl*original_ApplyNonCar)(tPipe_chunk **) = (void(__cdecl*)(tPipe_chunk **))0x0042a586;
CARM95_HOOK_FUNCTION(original_ApplyNonCar, ApplyNonCar)
void __cdecl ApplyNonCar(tPipe_chunk **pChunk) {
    LOG_TRACE("(%p)", pChunk);

    (void)pChunk;

    original_ApplyNonCar(pChunk);
}

static void(__cdecl*original_ApplySmoke)(tPipe_chunk **) = (void(__cdecl*)(tPipe_chunk **))0x0042a5b9;
CARM95_HOOK_FUNCTION(original_ApplySmoke, ApplySmoke)
void __cdecl ApplySmoke(tPipe_chunk **pChunk) {
    br_vector3 pos;
    LOG_TRACE("(%p)", pChunk);

    (void)pChunk;
    (void)pos;

    original_ApplySmoke(pChunk);
}

static void(__cdecl*original_ApplySmokeColumn)(tPipe_chunk **) = (void(__cdecl*)(tPipe_chunk **))0x0042a651;
CARM95_HOOK_FUNCTION(original_ApplySmokeColumn, ApplySmokeColumn)
void __cdecl ApplySmokeColumn(tPipe_chunk **pChunk) {
    LOG_TRACE("(%p)", pChunk);

    (void)pChunk;

    original_ApplySmokeColumn(pChunk);
}

static void(__cdecl*original_ApplyFlame)(tPipe_chunk **) = (void(__cdecl*)(tPipe_chunk **))0x0042a6f8;
CARM95_HOOK_FUNCTION(original_ApplyFlame, ApplyFlame)
void __cdecl ApplyFlame(tPipe_chunk **pChunk) {
    LOG_TRACE("(%p)", pChunk);

    (void)pChunk;

    original_ApplyFlame(pChunk);
}

static void(__cdecl*original_ApplySplash)(tPipe_chunk **) = (void(__cdecl*)(tPipe_chunk **))0x0042a752;
CARM95_HOOK_FUNCTION(original_ApplySplash, ApplySplash)
void __cdecl ApplySplash(tPipe_chunk **pChunk) {
    tCar_spec *c;
    LOG_TRACE("(%p)", pChunk);

    (void)pChunk;
    (void)c;

    original_ApplySplash(pChunk);
}

static void(__cdecl*original_ApplyOilSpill)(tPipe_chunk **, tU32) = (void(__cdecl*)(tPipe_chunk **, tU32))0x0042a80d;
CARM95_HOOK_FUNCTION(original_ApplyOilSpill, ApplyOilSpill)
void __cdecl ApplyOilSpill(tPipe_chunk **pChunk, tU32 pStop_time) {
    LOG_TRACE("(%p, %u)", pChunk, pStop_time);

    (void)pChunk;
    (void)pStop_time;

    original_ApplyOilSpill(pChunk, pStop_time);
}

static void(__cdecl*original_ApplyFrameBoundary)(tPipe_chunk **) = (void(__cdecl*)(tPipe_chunk **))0x0042a87c;
CARM95_HOOK_FUNCTION(original_ApplyFrameBoundary, ApplyFrameBoundary)
void __cdecl ApplyFrameBoundary(tPipe_chunk **pChunk) {
    tU32 result;
    LOG_TRACE("(%p)", pChunk);

    (void)pChunk;
    (void)result;

    original_ApplyFrameBoundary(pChunk);
}

static void(__cdecl*original_ApplySound)(tPipe_chunk **) = (void(__cdecl*)(tPipe_chunk **))0x0042a8b5;
CARM95_HOOK_FUNCTION(original_ApplySound, ApplySound)
void __cdecl ApplySound(tPipe_chunk **pChunk) {
    LOG_TRACE("(%p)", pChunk);

    (void)pChunk;

    original_ApplySound(pChunk);
}

static void(__cdecl*original_ApplyCar)(tPipe_chunk **) = (void(__cdecl*)(tPipe_chunk **))0x0042aa59;
CARM95_HOOK_FUNCTION(original_ApplyCar, ApplyCar)
void __cdecl ApplyCar(tPipe_chunk **pChunk) {
    tCar_spec *car;
    br_vector3 com_offset_c;
    br_vector3 com_offset_w;
    br_scalar __block0___scale;
    LOG_TRACE("(%p)", pChunk);

    (void)pChunk;
    (void)car;
    (void)com_offset_c;
    (void)com_offset_w;
    (void)__block0___scale;

    original_ApplyCar(pChunk);
}

static void(__cdecl*original_ApplyDamage)(tPipe_chunk **) = (void(__cdecl*)(tPipe_chunk **))0x0042ae65;
CARM95_HOOK_FUNCTION(original_ApplyDamage, ApplyDamage)
void __cdecl ApplyDamage(tPipe_chunk **pChunk) {
    tCar_spec *car;
    int i;
    LOG_TRACE("(%p)", pChunk);

    (void)pChunk;
    (void)car;
    (void)i;

    original_ApplyDamage(pChunk);
}

static void(__cdecl*original_ApplySpecial)(tPipe_chunk **) = (void(__cdecl*)(tPipe_chunk **))0x0042af1e;
CARM95_HOOK_FUNCTION(original_ApplySpecial, ApplySpecial)
void __cdecl ApplySpecial(tPipe_chunk **pChunk) {
    LOG_TRACE("(%p)", pChunk);

    (void)pChunk;

    original_ApplySpecial(pChunk);
}

static void(__cdecl*original_ApplyPedGib)(tPipe_chunk **) = (void(__cdecl*)(tPipe_chunk **))0x0042afc8;
CARM95_HOOK_FUNCTION(original_ApplyPedGib, ApplyPedGib)
void __cdecl ApplyPedGib(tPipe_chunk **pChunk) {
    LOG_TRACE("(%p)", pChunk);

    (void)pChunk;

    original_ApplyPedGib(pChunk);
}

static void(__cdecl*original_ApplyProxRay)(tPipe_chunk **) = (void(__cdecl*)(tPipe_chunk **))0x0042b01f;
CARM95_HOOK_FUNCTION(original_ApplyProxRay, ApplyProxRay)
void __cdecl ApplyProxRay(tPipe_chunk **pChunk) {
    LOG_TRACE("(%p)", pChunk);

    (void)pChunk;

    original_ApplyProxRay(pChunk);
}

static void(__cdecl*original_ApplySkidAdjustment)(tPipe_chunk **) = (void(__cdecl*)(tPipe_chunk **))0x0042b068;
CARM95_HOOK_FUNCTION(original_ApplySkidAdjustment, ApplySkidAdjustment)
void __cdecl ApplySkidAdjustment(tPipe_chunk **pChunk) {
    LOG_TRACE("(%p)", pChunk);

    (void)pChunk;

    original_ApplySkidAdjustment(pChunk);
}

static int(__cdecl*original_ApplyPipedSession)(tU8 **) = (int(__cdecl*)(tU8 **))0x00429cfb;
CARM95_HOOK_FUNCTION(original_ApplyPipedSession, ApplyPipedSession)
int __cdecl ApplyPipedSession(tU8 **pPtr) {
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

static int(__cdecl*original_MoveSessionPointerBackOne)(tU8 **) = (int(__cdecl*)(tU8 **))0x0042b419;
CARM95_HOOK_FUNCTION(original_MoveSessionPointerBackOne, MoveSessionPointerBackOne)
int __cdecl MoveSessionPointerBackOne(tU8 **pPtr) {
    LOG_TRACE("(%p)", pPtr);

    (void)pPtr;

    return original_MoveSessionPointerBackOne(pPtr);
}

static int(__cdecl*original_MoveSessionPointerForwardOne)(tU8 **) = (int(__cdecl*)(tU8 **))0x0042bf9e;
CARM95_HOOK_FUNCTION(original_MoveSessionPointerForwardOne, MoveSessionPointerForwardOne)
int __cdecl MoveSessionPointerForwardOne(tU8 **pPtr) {
    LOG_TRACE("(%p)", pPtr);

    (void)pPtr;

    return original_MoveSessionPointerForwardOne(pPtr);
}

static tPipe_chunk *(__cdecl*original_FindPreviousChunk)(tU8 *, tPipe_chunk_type, tChunk_subject_index) = (tPipe_chunk *(__cdecl*)(tU8 *, tPipe_chunk_type, tChunk_subject_index))0x0042b492;
CARM95_HOOK_FUNCTION(original_FindPreviousChunk, FindPreviousChunk)
tPipe_chunk* __cdecl FindPreviousChunk(tU8 *pPtr, tPipe_chunk_type pType, tChunk_subject_index pIndex) {
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

static void(__cdecl*original_UndoModelGeometry)(tPipe_chunk **) = (void(__cdecl*)(tPipe_chunk **))0x0042b5ae;
CARM95_HOOK_FUNCTION(original_UndoModelGeometry, UndoModelGeometry)
void __cdecl UndoModelGeometry(tPipe_chunk **pChunk) {
    int i;
    br_model *model_ptr;
    tCar_spec *car;
    LOG_TRACE("(%p)", pChunk);

    (void)pChunk;
    (void)i;
    (void)model_ptr;
    (void)car;

    original_UndoModelGeometry(pChunk);
}

static void(__cdecl*original_UndoSmudge)(tPipe_chunk **) = (void(__cdecl*)(tPipe_chunk **))0x0042b762;
CARM95_HOOK_FUNCTION(original_UndoSmudge, UndoSmudge)
void __cdecl UndoSmudge(tPipe_chunk **pChunk) {
    int i;
    br_model *model_ptr;
    tCar_spec *car;
    LOG_TRACE("(%p)", pChunk);

    (void)pChunk;
    (void)i;
    (void)model_ptr;
    (void)car;

    original_UndoSmudge(pChunk);
}

static void(__cdecl*original_UndoPedestrian)(tPipe_chunk **, tPipe_chunk *) = (void(__cdecl*)(tPipe_chunk **, tPipe_chunk *))0x0042b78c;
CARM95_HOOK_FUNCTION(original_UndoPedestrian, UndoPedestrian)
void __cdecl UndoPedestrian(tPipe_chunk **pChunk, tPipe_chunk *pPrev_chunk) {
    tPipe_chunk *temp_prev_chunk;
    LOG_TRACE("(%p, %p)", pChunk, pPrev_chunk);

    (void)pChunk;
    (void)pPrev_chunk;
    (void)temp_prev_chunk;

    original_UndoPedestrian(pChunk, pPrev_chunk);
}

static void(__cdecl*original_UndoFrameBoundary)(tPipe_chunk **, tPipe_chunk *) = (void(__cdecl*)(tPipe_chunk **, tPipe_chunk *))0x0042b7e9;
CARM95_HOOK_FUNCTION(original_UndoFrameBoundary, UndoFrameBoundary)
void __cdecl UndoFrameBoundary(tPipe_chunk **pChunk, tPipe_chunk *pPrev_chunk) {
    tPipe_chunk *temp_prev_chunk;
    LOG_TRACE("(%p, %p)", pChunk, pPrev_chunk);

    (void)pChunk;
    (void)pPrev_chunk;
    (void)temp_prev_chunk;

    original_UndoFrameBoundary(pChunk, pPrev_chunk);
}

static void(__cdecl*original_UndoCar)(tPipe_chunk **, tPipe_chunk *) = (void(__cdecl*)(tPipe_chunk **, tPipe_chunk *))0x0042b817;
CARM95_HOOK_FUNCTION(original_UndoCar, UndoCar)
void __cdecl UndoCar(tPipe_chunk **pChunk, tPipe_chunk *pPrev_chunk) {
    tPipe_chunk *temp_prev_chunk;
    LOG_TRACE("(%p, %p)", pChunk, pPrev_chunk);

    (void)pChunk;
    (void)pPrev_chunk;
    (void)temp_prev_chunk;

    original_UndoCar(pChunk, pPrev_chunk);
}

static void(__cdecl*original_UndoSound)(tPipe_chunk **) = (void(__cdecl*)(tPipe_chunk **))0x0042b874;
CARM95_HOOK_FUNCTION(original_UndoSound, UndoSound)
void __cdecl UndoSound(tPipe_chunk **pChunk) {
    LOG_TRACE("(%p)", pChunk);

    (void)pChunk;

    original_UndoSound(pChunk);
}

static void(__cdecl*original_UndoDamage)(tPipe_chunk **) = (void(__cdecl*)(tPipe_chunk **))0x0042b88d;
CARM95_HOOK_FUNCTION(original_UndoDamage, UndoDamage)
void __cdecl UndoDamage(tPipe_chunk **pChunk) {
    tCar_spec *car;
    int i;
    LOG_TRACE("(%p)", pChunk);

    (void)pChunk;
    (void)car;
    (void)i;

    original_UndoDamage(pChunk);
}

static void(__cdecl*original_UndoSpecial)(tPipe_chunk **) = (void(__cdecl*)(tPipe_chunk **))0x0042b94c;
CARM95_HOOK_FUNCTION(original_UndoSpecial, UndoSpecial)
void __cdecl UndoSpecial(tPipe_chunk **pChunk) {
    LOG_TRACE("(%p)", pChunk);

    (void)pChunk;

    original_UndoSpecial(pChunk);
}

static void(__cdecl*original_UndoPedGib)(tPipe_chunk **, tPipe_chunk *) = (void(__cdecl*)(tPipe_chunk **, tPipe_chunk *))0x0042b9f6;
CARM95_HOOK_FUNCTION(original_UndoPedGib, UndoPedGib)
void __cdecl UndoPedGib(tPipe_chunk **pChunk, tPipe_chunk *pPrev_chunk) {
    tPipe_chunk *temp_prev_chunk;
    LOG_TRACE("(%p, %p)", pChunk, pPrev_chunk);

    (void)pChunk;
    (void)pPrev_chunk;
    (void)temp_prev_chunk;

    original_UndoPedGib(pChunk, pPrev_chunk);
}

static void(__cdecl*original_UndoSpark)(tPipe_chunk **, tPipe_chunk *) = (void(__cdecl*)(tPipe_chunk **, tPipe_chunk *))0x0042ba42;
CARM95_HOOK_FUNCTION(original_UndoSpark, UndoSpark)
void __cdecl UndoSpark(tPipe_chunk **pChunk, tPipe_chunk *pPrev_chunk) {
    tPipe_chunk *temp_prev_chunk;
    LOG_TRACE("(%p, %p)", pChunk, pPrev_chunk);

    (void)pChunk;
    (void)pPrev_chunk;
    (void)temp_prev_chunk;

    original_UndoSpark(pChunk, pPrev_chunk);
}

static void(__cdecl*original_UndoShrapnel)(tPipe_chunk **, tPipe_chunk *) = (void(__cdecl*)(tPipe_chunk **, tPipe_chunk *))0x0042ba8e;
CARM95_HOOK_FUNCTION(original_UndoShrapnel, UndoShrapnel)
void __cdecl UndoShrapnel(tPipe_chunk **pChunk, tPipe_chunk *pPrev_chunk) {
    tPipe_chunk *temp_prev_chunk;
    LOG_TRACE("(%p, %p)", pChunk, pPrev_chunk);

    (void)pChunk;
    (void)pPrev_chunk;
    (void)temp_prev_chunk;

    original_UndoShrapnel(pChunk, pPrev_chunk);
}

static void(__cdecl*original_UndoScreenWobble)(tPipe_chunk **, tPipe_chunk *) = (void(__cdecl*)(tPipe_chunk **, tPipe_chunk *))0x0042bada;
CARM95_HOOK_FUNCTION(original_UndoScreenWobble, UndoScreenWobble)
void __cdecl UndoScreenWobble(tPipe_chunk **pChunk, tPipe_chunk *pPrev_chunk) {
    tPipe_chunk *temp_prev_chunk;
    LOG_TRACE("(%p, %p)", pChunk, pPrev_chunk);

    (void)pChunk;
    (void)pPrev_chunk;
    (void)temp_prev_chunk;

    original_UndoScreenWobble(pChunk, pPrev_chunk);
}

static void(__cdecl*original_UndoGrooveStop)(tPipe_chunk **, tPipe_chunk *) = (void(__cdecl*)(tPipe_chunk **, tPipe_chunk *))0x0042bb37;
CARM95_HOOK_FUNCTION(original_UndoGrooveStop, UndoGrooveStop)
void __cdecl UndoGrooveStop(tPipe_chunk **pChunk, tPipe_chunk *pPrev_chunk) {
    tPipe_chunk *temp_prev_chunk;
    LOG_TRACE("(%p, %p)", pChunk, pPrev_chunk);

    (void)pChunk;
    (void)pPrev_chunk;
    (void)temp_prev_chunk;

    original_UndoGrooveStop(pChunk, pPrev_chunk);
}

static void(__cdecl*original_UndoNonCar)(tPipe_chunk **, tPipe_chunk *) = (void(__cdecl*)(tPipe_chunk **, tPipe_chunk *))0x0042bb83;
CARM95_HOOK_FUNCTION(original_UndoNonCar, UndoNonCar)
void __cdecl UndoNonCar(tPipe_chunk **pChunk, tPipe_chunk *pPrev_chunk) {
    tPipe_chunk *temp_prev_chunk;
    LOG_TRACE("(%p, %p)", pChunk, pPrev_chunk);

    (void)pChunk;
    (void)pPrev_chunk;
    (void)temp_prev_chunk;

    original_UndoNonCar(pChunk, pPrev_chunk);
}

static void(__cdecl*original_UndoSmoke)(tPipe_chunk **, tPipe_chunk *) = (void(__cdecl*)(tPipe_chunk **, tPipe_chunk *))0x0042bbcf;
CARM95_HOOK_FUNCTION(original_UndoSmoke, UndoSmoke)
void __cdecl UndoSmoke(tPipe_chunk **pChunk, tPipe_chunk *pPrev_chunk) {
    tPipe_chunk *temp_prev_chunk;
    LOG_TRACE("(%p, %p)", pChunk, pPrev_chunk);

    (void)pChunk;
    (void)pPrev_chunk;
    (void)temp_prev_chunk;

    original_UndoSmoke(pChunk, pPrev_chunk);
}

static void(__cdecl*original_UndoSmokeColumn)(tPipe_chunk **, tPipe_chunk *) = (void(__cdecl*)(tPipe_chunk **, tPipe_chunk *))0x0042bc1b;
CARM95_HOOK_FUNCTION(original_UndoSmokeColumn, UndoSmokeColumn)
void __cdecl UndoSmokeColumn(tPipe_chunk **pChunk, tPipe_chunk *pPrev_chunk) {
    tPipe_chunk *temp_prev_chunk;
    LOG_TRACE("(%p, %p)", pChunk, pPrev_chunk);

    (void)pChunk;
    (void)pPrev_chunk;
    (void)temp_prev_chunk;

    original_UndoSmokeColumn(pChunk, pPrev_chunk);
}

static void(__cdecl*original_UndoFlame)(tPipe_chunk **, tPipe_chunk *) = (void(__cdecl*)(tPipe_chunk **, tPipe_chunk *))0x0042bc3b;
CARM95_HOOK_FUNCTION(original_UndoFlame, UndoFlame)
void __cdecl UndoFlame(tPipe_chunk **pChunk, tPipe_chunk *pPrev_chunk) {
    LOG_TRACE("(%p, %p)", pChunk, pPrev_chunk);

    (void)pChunk;
    (void)pPrev_chunk;

    original_UndoFlame(pChunk, pPrev_chunk);
}

static void(__cdecl*original_UndoSplash)(tPipe_chunk **, tPipe_chunk *) = (void(__cdecl*)(tPipe_chunk **, tPipe_chunk *))0x0042bc52;
CARM95_HOOK_FUNCTION(original_UndoSplash, UndoSplash)
void __cdecl UndoSplash(tPipe_chunk **pChunk, tPipe_chunk *pPrev_chunk) {
    tPipe_chunk *temp_prev_chunk;
    LOG_TRACE("(%p, %p)", pChunk, pPrev_chunk);

    (void)pChunk;
    (void)pPrev_chunk;
    (void)temp_prev_chunk;

    original_UndoSplash(pChunk, pPrev_chunk);
}

static void(__cdecl*original_UndoOilSpill)(tPipe_chunk **, tPipe_chunk *) = (void(__cdecl*)(tPipe_chunk **, tPipe_chunk *))0x0042bd0b;
CARM95_HOOK_FUNCTION(original_UndoOilSpill, UndoOilSpill)
void __cdecl UndoOilSpill(tPipe_chunk **pChunk, tPipe_chunk *pPrev_chunk) {
    tPipe_chunk *temp_prev_chunk;
    LOG_TRACE("(%p, %p)", pChunk, pPrev_chunk);

    (void)pChunk;
    (void)pPrev_chunk;
    (void)temp_prev_chunk;

    original_UndoOilSpill(pChunk, pPrev_chunk);
}

static void(__cdecl*original_UndoProxRay)(tPipe_chunk **) = (void(__cdecl*)(tPipe_chunk **))0x0042bd60;
CARM95_HOOK_FUNCTION(original_UndoProxRay, UndoProxRay)
void __cdecl UndoProxRay(tPipe_chunk **pChunk) {
    LOG_TRACE("(%p)", pChunk);

    (void)pChunk;

    original_UndoProxRay(pChunk);
}

static void(__cdecl*original_UndoSkidAdjustment)(tPipe_chunk **, tPipe_chunk *) = (void(__cdecl*)(tPipe_chunk **, tPipe_chunk *))0x0042bd77;
CARM95_HOOK_FUNCTION(original_UndoSkidAdjustment, UndoSkidAdjustment)
void __cdecl UndoSkidAdjustment(tPipe_chunk **pChunk, tPipe_chunk *pPrev_chunk) {
    LOG_TRACE("(%p, %p)", pChunk, pPrev_chunk);

    (void)pChunk;
    (void)pPrev_chunk;

    original_UndoSkidAdjustment(pChunk, pPrev_chunk);
}

static int(__cdecl*original_UndoPipedSession)(tU8 **) = (int(__cdecl*)(tU8 **))0x0042b0a6;
CARM95_HOOK_FUNCTION(original_UndoPipedSession, UndoPipedSession)
int __cdecl UndoPipedSession(tU8 **pPtr) {
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

    return original_UndoPipedSession(pPtr);
}

static tU32(__cdecl*original_FindPrevFrameTime)(tU8 *) = (tU32(__cdecl*)(tU8 *))0x0042bdd2;
CARM95_HOOK_FUNCTION(original_FindPrevFrameTime, FindPrevFrameTime)
tU32 __cdecl FindPrevFrameTime(tU8 *pPtr) {
    tU8 *temp_ptr;
    LOG_TRACE("(%p)", pPtr);

    (void)pPtr;
    (void)temp_ptr;

    return original_FindPrevFrameTime(pPtr);
}

static void(__cdecl*original_ScanBuffer)(tU8 **, tPipe_chunk_type, tU32, int(**)(tPipe_chunk *, int, tU32), int(**)(tU32)) = (void(__cdecl*)(tU8 **, tPipe_chunk_type, tU32, int(**)(tPipe_chunk *, int, tU32), int(**)(tU32)))0x0042be18;
CARM95_HOOK_FUNCTION(original_ScanBuffer, ScanBuffer)
void __cdecl ScanBuffer(tU8 **pPtr, tPipe_chunk_type pType, tU32 pDefault_time, int(**pCall_back)(tPipe_chunk *, int, tU32), int(**pTime_check)(tU32)) {
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

static int(__cdecl*original_CheckSound)(tPipe_chunk *, int, tU32) = (int(__cdecl*)(tPipe_chunk *, int, tU32))0x0042c00a;
CARM95_HOOK_FUNCTION(original_CheckSound, CheckSound)
int __cdecl CheckSound(tPipe_chunk *pChunk_ptr, int pChunk_count, tU32 pTime) {
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

static int(__cdecl*original_SoundTimeout)(tU32) = (int(__cdecl*)(tU32))0x0042c132;
CARM95_HOOK_FUNCTION(original_SoundTimeout, SoundTimeout)
int __cdecl SoundTimeout(tU32 pTime) {
    LOG_TRACE("(%u)", pTime);

    (void)pTime;

    return original_SoundTimeout(pTime);
}

static void(__cdecl*original_ScanAndPlaySoundsToBe)(tU8 *, tU32, tU32) = (void(__cdecl*)(tU8 *, tU32, tU32))0x0042c06e;
CARM95_HOOK_FUNCTION(original_ScanAndPlaySoundsToBe, ScanAndPlaySoundsToBe)
void __cdecl ScanAndPlaySoundsToBe(tU8 *pPtr, tU32 pOldest_time, tU32 pYoungest_time) {
    tU8 *temp_ptr;
    LOG_TRACE("(%p, %u, %u)", pPtr, pOldest_time, pYoungest_time);

    (void)pPtr;
    (void)pOldest_time;
    (void)pYoungest_time;
    (void)temp_ptr;

    original_ScanAndPlaySoundsToBe(pPtr, pOldest_time, pYoungest_time);
}

static int(__cdecl*original_CheckCar)(tPipe_chunk *, int, tU32) = (int(__cdecl*)(tPipe_chunk *, int, tU32))0x0042c327;
CARM95_HOOK_FUNCTION(original_CheckCar, CheckCar)
int __cdecl CheckCar(tPipe_chunk *pChunk_ptr, int pChunk_count, tU32 pTime) {
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

    return original_CheckCar(pChunk_ptr, pChunk_count, pTime);
}

static int(__cdecl*original_CarTimeout)(tU32) = (int(__cdecl*)(tU32))0x0042c5b2;
CARM95_HOOK_FUNCTION(original_CarTimeout, CarTimeout)
int __cdecl CarTimeout(tU32 pTime) {
    LOG_TRACE("(%u)", pTime);

    (void)pTime;

    return original_CarTimeout(pTime);
}

static void(__cdecl*original_ScanCarsPositions)(tCar_spec *, br_vector3 *, br_scalar, tU32, tU32, br_vector3 *, tU32 *) = (void(__cdecl*)(tCar_spec *, br_vector3 *, br_scalar, tU32, tU32, br_vector3 *, tU32 *))0x0042c171;
CARM95_HOOK_FUNCTION(original_ScanCarsPositions, ScanCarsPositions)
void __cdecl ScanCarsPositions(tCar_spec *pCar, br_vector3 *pSource_pos, br_scalar pMax_distance_sqr, tU32 pOffset_time, tU32 pTime_period, br_vector3 *pCar_pos, tU32 *pTime_returned) {
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

    original_ScanCarsPositions(pCar, pSource_pos, pMax_distance_sqr, pOffset_time, pTime_period, pCar_pos, pTime_returned);
}

static int(__cdecl*original_CheckIncident)(tPipe_chunk *, int, tU32) = (int(__cdecl*)(tPipe_chunk *, int, tU32))0x0042c90d;
CARM95_HOOK_FUNCTION(original_CheckIncident, CheckIncident)
int __cdecl CheckIncident(tPipe_chunk *pChunk_ptr, int pChunk_count, tU32 pTime) {
    LOG_TRACE("(%p, %d, %u)", pChunk_ptr, pChunk_count, pTime);

    (void)pChunk_ptr;
    (void)pChunk_count;
    (void)pTime;

    return original_CheckIncident(pChunk_ptr, pChunk_count, pTime);
}

static int(__cdecl*original_GetNextIncident)(tU32, tIncident_type *, float *, tIncident_info *, tU32 *) = (int(__cdecl*)(tU32, tIncident_type *, float *, tIncident_info *, tU32 *))0x0042c6a3;
CARM95_HOOK_FUNCTION(original_GetNextIncident, GetNextIncident)
int __cdecl GetNextIncident(tU32 pOffset_time, tIncident_type *pIncident_type, float *pSeverity, tIncident_info *pInfo, tU32 *pTime_away) {
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

static tU32(__cdecl*original_GetARStartTime)() = (tU32(__cdecl*)())0x0042ca0e;
CARM95_HOOK_FUNCTION(original_GetARStartTime, GetARStartTime)
tU32 __cdecl GetARStartTime() {
    tU8 *temp_ptr;
    LOG_TRACE("()");

    (void)temp_ptr;

    return original_GetARStartTime();
}

