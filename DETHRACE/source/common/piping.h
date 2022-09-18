#ifndef _PIPING_H_
#define _PIPING_H_

#include "br_types.h"
#include "dr_types.h"

extern tU8 ** hookvar_gPipe_buffer_start ; // addr: 0050BA00
extern int * hookvar_gDisable_sound ; // addr: 0050BA04
// extern int * hookvar_gDisable_advance ;
// extern int * hookvar_gMax_rewind_chunks ;
extern float * hookvar_gWall_severity ; // addr: 0050BA10
extern tPipe_reset_proc*(* hookvar_gReset_procs )[32]; // addr: 0050BA18
// extern tPiped_registration_snapshot(* hookvar_gRegistration_snapshots )[5];
extern tPipe_smudge_data ** hookvar_gSmudge_space ; // addr: 00531FFC
// extern tU32 * hookvar_gOldest_time ;
// extern int * hookvar_gCurrent_snapshot_registration_index ;
extern tPipe_chunk ** hookvar_gMr_chunky ; // addr: 00531FA0
// extern tCar_spec ** hookvar_gCar_ptr ;
extern br_vector3 * hookvar_gZero_vector ; // addr: 00532068
extern tPipe_chunk_type(* hookvar_gReentrancy_array )[5]; // addr: 00532050
// extern tU32 * hookvar_gLast_time ;
extern tPipe_model_geometry_data ** hookvar_gModel_geometry_space ; // addr: 0053204C
// extern tU32 * hookvar_gEnd_time ;
// extern tU32 * hookvar_gTrigger_time ;
extern int * hookvar_gReentrancy_count ; // addr: 00532074
// extern br_vector3 * hookvar_gCar_pos ;
// extern br_vector3 * hookvar_gReference_pos ;
// extern br_scalar * hookvar_gMax_distance ;
// extern tU32 * hookvar_gLoop_abort_time ;
extern br_vector3 * hookvar_gWall_impact_point ; // addr: 00532078
// extern tU8 ** hookvar_gPipe_buffer_working_end ;
// extern tU32 * hookvar_gYoungest_time ;
extern tU8 ** hookvar_gPipe_buffer_phys_end ; // addr: 0053208C
// extern tU8 ** hookvar_gLocal_buffer_record_ptr ;
extern tU8 ** hookvar_gPipe_play_ptr ; // addr: 00532018
// extern tU8 ** hookvar_gEnd_of_session ;
// extern tU8 ** hookvar_gPipe_record_ptr ;
// extern tU8 ** hookvar_gPipe_buffer_oldest ;
extern tU32 * hookvar_gPipe_buffer_size ; // addr: 00532088
extern tU8 ** hookvar_gLocal_buffer ; // addr: 00532014
extern tU32 * hookvar_gLocal_buffer_size ; // addr: 00532090

void __cdecl GetReducedPos(br_vector3 *v, tReduced_pos *p);

void __cdecl SaveReducedPos(tReduced_pos *p, br_vector3 *v);

int __cdecl PipeSearchForwards();

int __cdecl IsActionReplayAvailable();

int __cdecl SomeReplayLeft();

void __cdecl DisablePipedSounds();

void __cdecl EnablePipedSounds();

tU32 __cdecl LengthOfSession(tPipe_session *pSession);

void __cdecl StartPipingSession2(tPipe_chunk_type pThe_type, int pMunge_reentrancy);

void __cdecl StartPipingSession(tPipe_chunk_type pThe_type);

void __cdecl EndPipingSession2(int pMunge_reentrancy);

void __cdecl EndPipingSession();

void __cdecl AddDataToSession(int pSubject_index, void *pData, tU32 pData_length);

void __cdecl AddModelGeometryToPipingSession(tU16 pCar_ID, int pModel_index, int pVertex_count, tChanged_vertex *pCoordinates);

void __cdecl AddSmudgeToPipingSession(tU16 pCar_ID, int pModel_index, int pVertex_count, tSmudged_vertex *pCoordinates);

void __cdecl AddPedestrianToPipingSession(int pPedestrian_index, br_matrix34 *pTrans, tU8 pAction_index, tU8 pFrame_index, tS8 pHit_points, int pDone_initial, tU16 pParent_ID, float pSpin_period, br_scalar pJump_magnitude, br_vector3 *pOffset);

void __cdecl AddSparkToPipingSession(int pSpark_index, br_vector3 *pPos, br_vector3 *pV);

void __cdecl AddShrapnelToPipingSession(int pShrapnel_index, br_vector3 *pPos, tU16 pAge, br_material *pMaterial);

void __cdecl AddScreenWobbleToPipingSession(int pWobble_x, int pWobble_y);

void __cdecl AddGrooveStopToPipingSession(int pGroove_index, br_matrix34 *pMatrix, int pPath_interrupt, int pObject_interrupt, float pPath_resumption, float pObject_resumption);

void __cdecl AddNonCarToPipingSession(int pIndex, br_actor *pActor);

void __cdecl AddSmokeToPipingSession(int pIndex, tU8 pType, br_vector3 *pPos, br_scalar pRadius, br_scalar pStrength);

void __cdecl AddSmokeColumnToPipingSession(int pIndex, tCar_spec *pCar, int pVertex, int pColour);

void __cdecl AddFlameToPipingSession(int pIndex, int pFrame_count, br_scalar pScale_x, br_scalar pScale_y, br_scalar pOffset_x, br_scalar pOffset_z);

void __cdecl AddSplashToPipingSession(tCollision_info *pCar);

void __cdecl AddOilSpillToPipingSession(int pIndex, br_matrix34 *pMat, br_scalar pFull_size, br_scalar pGrow_rate, tU32 pSpill_time, tU32 pStop_time, tCar_spec *pCar, br_vector3 *pOriginal_pos, br_pixelmap *pPixelmap);

void __cdecl AddFrameFinishToPipingSession(tU32 pThe_time);

void __cdecl AddCarToPipingSession(int pCar_ID, br_matrix34 *pCar_mat, br_vector3 *pCar_velocity, float pSpeedo_speed, float pLf_sus_position, float pRf_sus_position, float pLr_sus_position, float pRr_sus_position, float pSteering_angle, br_scalar pRevs, int pGear, int pFrame_coll_flag);

void __cdecl AddSoundToPipingSession(tS3_outlet_ptr pOutlet, int pSound_index, tS3_volume pL_volume, tS3_volume pR_volume, tS3_pitch pPitch, br_vector3 *pPos);

void __cdecl AddDamageToPipingSession(int pCar_ID, tS8 *pDifferences);

void __cdecl AddSpecialToPipingSession(tSpecial_type pType);

void __cdecl AddPedGibToPipingSession(int pIndex, br_matrix34 *pTrans, int pSize, int pGib_index, int pPed_index);

void __cdecl AddCarIncidentToPipingSession(float pSeverity, tCar_spec *pCar, br_vector3 *pImpact_point);

void __cdecl AddPedIncidentToPipingSession(int pPed_index, br_actor *pActor);

void __cdecl AddWallIncidentToPipingSession(float pSeverity, br_vector3 *pImpact_point);

void __cdecl AddProxRayToPipingSession(int pRay_index, tCar_spec *pCar, tU16 pPed_index, tU32 pTime);

void __cdecl AddSkidAdjustmentToPipingSession(int pSkid_num, br_matrix34 *pMatrix, int pMaterial_index);

void __cdecl PipeSingleModelGeometry(tU16 pCar_ID, int pModel_index, int pVertex_count, tChanged_vertex *pCoordinates);

void __cdecl PipeSinglePedestrian(int pPedestrian_index, br_matrix34 *pTrans, tU8 pAction_index, tU8 pFrame_index, tS8 pHit_points, int pDone_initial, tU16 pParent_ID, float pSpin_period, br_scalar pJump_magnitude, br_vector3 *pOffset);

void __cdecl PipeSingleCar(int pCar_ID, br_matrix34 *pCar_mat, br_vector3 *pCar_velocity, float pSpeedo_speed, float pLf_sus_position, float pRf_sus_position, float pLr_sus_position, float pRr_sus_position, float pSteering_angle, br_scalar pRevs, int pGear, int pFrame_coll_flag);

void __cdecl PipeSingleSound(tS3_outlet_ptr pOutlet, int pSound_index, tS3_volume pL_volume, tS3_volume pR_volume, tS3_pitch pPitch, br_vector3 *pPos);

void __cdecl PipeSingleOilSpill(int pIndex, br_matrix34 *pMat, br_scalar pFull_size, br_scalar pGrow_rate, tU32 pSpill_time, tU32 pStop_time, tCar_spec *pCar, br_vector3 *pOriginal_pos, br_pixelmap *pPixelmap);

void __cdecl PipeSingleDamage(int pCar_ID, tS8 *pDifferences);

void __cdecl PipeSingleSpecial(tSpecial_type pType);

void __cdecl PipeSinglePedGib(int pIndex, br_matrix34 *pTrans, int pSize, int pGib_index, int pPed_index);

void __cdecl PipeSingleCarIncident(float pSeverity, tCar_spec *pCar, br_vector3 *pImpact_point);

void __cdecl PipeSinglePedIncident(int pPed_index, br_actor *pActor);

void __cdecl PipeSingleWallIncident(float pSeverity, br_vector3 *pImpact_point);

void __cdecl PipeSingleScreenShake(int pWobble_x, int pWobble_y);

void __cdecl PipeSingleGrooveStop(int pGroove_index, br_matrix34 *pMatrix, int pPath_interrupt, int pObject_interrupt, float pPath_resumption, float pObject_resumption);

void __cdecl PipeFrameFinish();

void __cdecl PipingFrameReset();

void __cdecl PipeSingleSkidAdjustment(int pSkid_num, br_matrix34 *pMatrix, int pMaterial_index);

void __cdecl ResetPiping();

void __cdecl InitialisePiping();

void __cdecl DisposePiping();

void __cdecl InitLastDamageArrayEtc();

void __cdecl ResetCars();

void __cdecl PipeCarPositions();

void __cdecl ResetPipePlayToEnd();

void __cdecl ResetPipePlayToStart();

tU8* __cdecl GetPipePlayPtr();

void __cdecl SetPipePlayPtr(tU8 *pPtr);

void __cdecl AdvanceChunkPtr(tPipe_chunk **pChunk, tChunk_subject_index pType);

void __cdecl ApplyModelGeometry(tPipe_chunk **pChunk);

void DoSmudge(tPipe_chunk **pChunk, int pDir);

void __cdecl ApplySmudge(tPipe_chunk **pChunk);

void __cdecl ApplyPedestrian(tPipe_chunk **pChunk);

void __cdecl ApplySpark(tPipe_chunk **pChunk);

void __cdecl ApplyShrapnel(tPipe_chunk **pChunk);

void __cdecl ApplyScreenWobble(tPipe_chunk **pChunk);

void __cdecl ApplyGrooveStop(tPipe_chunk **pChunk);

void __cdecl ApplyNonCar(tPipe_chunk **pChunk);

void __cdecl ApplySmoke(tPipe_chunk **pChunk);

void __cdecl ApplySmokeColumn(tPipe_chunk **pChunk);

void __cdecl ApplyFlame(tPipe_chunk **pChunk);

void __cdecl ApplySplash(tPipe_chunk **pChunk);

void __cdecl ApplyOilSpill(tPipe_chunk **pChunk, tU32 pStop_time);

void __cdecl ApplyFrameBoundary(tPipe_chunk **pChunk);

void __cdecl ApplySound(tPipe_chunk **pChunk);

void __cdecl ApplyCar(tPipe_chunk **pChunk);

void __cdecl ApplyDamage(tPipe_chunk **pChunk);

void __cdecl ApplySpecial(tPipe_chunk **pChunk);

void __cdecl ApplyPedGib(tPipe_chunk **pChunk);

void __cdecl ApplyProxRay(tPipe_chunk **pChunk);

void __cdecl ApplySkidAdjustment(tPipe_chunk **pChunk);

int __cdecl ApplyPipedSession(tU8 **pPtr);

int __cdecl MoveSessionPointerBackOne(tU8 **pPtr);

int MoveSessionPointerForwardOne(tU8 **pPtr);

tPipe_chunk* __cdecl FindPreviousChunk(tU8 *pPtr, tPipe_chunk_type pType, tChunk_subject_index pIndex);

void UndoModelGeometry(tPipe_chunk **pChunk);

void UndoSmudge(tPipe_chunk **pChunk);

void UndoPedestrian(tPipe_chunk **pChunk, tPipe_chunk *pPrev_chunk);

void UndoFrameBoundary(tPipe_chunk **pChunk, tPipe_chunk *pPrev_chunk);

void UndoCar(tPipe_chunk **pChunk, tPipe_chunk *pPrev_chunk);

void UndoSound(tPipe_chunk **pChunk);

void UndoDamage(tPipe_chunk **pChunk);

void __cdecl UndoSpecial(tPipe_chunk **pChunk);

void __cdecl UndoPedGib(tPipe_chunk **pChunk, tPipe_chunk *pPrev_chunk);

void __cdecl UndoSpark(tPipe_chunk **pChunk, tPipe_chunk *pPrev_chunk);

void __cdecl UndoShrapnel(tPipe_chunk **pChunk, tPipe_chunk *pPrev_chunk);

void __cdecl UndoScreenWobble(tPipe_chunk **pChunk, tPipe_chunk *pPrev_chunk);

void __cdecl UndoGrooveStop(tPipe_chunk **pChunk, tPipe_chunk *pPrev_chunk);

void __cdecl UndoNonCar(tPipe_chunk **pChunk, tPipe_chunk *pPrev_chunk);

void __cdecl UndoSmoke(tPipe_chunk **pChunk, tPipe_chunk *pPrev_chunk);

void __cdecl UndoSmokeColumn(tPipe_chunk **pChunk, tPipe_chunk *pPrev_chunk);

void UndoFlame(tPipe_chunk **pChunk, tPipe_chunk *pPrev_chunk);

void __cdecl UndoSplash(tPipe_chunk **pChunk, tPipe_chunk *pPrev_chunk);

void __cdecl UndoOilSpill(tPipe_chunk **pChunk, tPipe_chunk *pPrev_chunk);

void __cdecl UndoProxRay(tPipe_chunk **pChunk);

void __cdecl UndoSkidAdjustment(tPipe_chunk **pChunk, tPipe_chunk *pPrev_chunk);

int UndoPipedSession(tU8 **pPtr);

tU32 FindPrevFrameTime(tU8 *pPtr);

void __cdecl ScanBuffer(tU8 **pPtr, tPipe_chunk_type pType, tU32 pDefault_time, int(**pCall_back)(tPipe_chunk *, int, tU32), int(**pTime_check)(tU32));

int __cdecl CheckSound(tPipe_chunk *pChunk_ptr, int pChunk_count, tU32 pTime);

int SoundTimeout(tU32 pTime);

void __cdecl ScanAndPlaySoundsToBe(tU8 *pPtr, tU32 pOldest_time, tU32 pYoungest_time);

int CheckCar(tPipe_chunk *pChunk_ptr, int pChunk_count, tU32 pTime);

int CarTimeout(tU32 pTime);

void ScanCarsPositions(tCar_spec *pCar, br_vector3 *pSource_pos, br_scalar pMax_distance_sqr, tU32 pOffset_time, tU32 pTime_period, br_vector3 *pCar_pos, tU32 *pTime_returned);

int __cdecl CheckIncident(tPipe_chunk *pChunk_ptr, int pChunk_count, tU32 pTime);

int __cdecl GetNextIncident(tU32 pOffset_time, tIncident_type *pIncident_type, float *pSeverity, tIncident_info *pInfo, tU32 *pTime_away);

tU32 GetARStartTime();

#endif
