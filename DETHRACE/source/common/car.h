#ifndef _CAR_H_
#define _CAR_H_

#include "br_types.h"
#include "dr_types.h"

extern int * hookvar_gDoing_physics ; // addr: 00514CB0
extern br_scalar * hookvar_gDt ; // addr: 00514CB4
extern int * hookvar_gCollision_detection_on__car ; // addr: 00514CB8 // suffix added to avoid duplicate symbol
extern br_vector3 * hookvar_gGround_normal__car ; // addr: 00514CC0 // suffix added to avoid duplicate symbol
// extern void(**(* hookvar_ControlCar__car )[6])(tCar_spec *, br_scalar, ...); // suffix added to avoid duplicate symbol
extern int * hookvar_gControl__car ; // addr: 00514CE8 // suffix added to avoid duplicate symbol
extern int * hookvar_gFace_num__car ; // addr: 00514DF8 // suffix added to avoid duplicate symbol
extern br_angle * hookvar_gOld_yaw__car ; // addr: 00514CF0 // suffix added to avoid duplicate symbol
extern br_angle * hookvar_gOld_zoom ; // addr: 00514CF4
extern br_vector3 * hookvar_gCamera_pos_before_collide ; // addr: 00514CF8
extern int(* hookvar_gMetal_crunch_sound_id__car )[5]; // addr: 00514D08 // suffix added to avoid duplicate symbol
extern int(* hookvar_gMetal_scrape_sound_id__car )[3]; // addr: 00514D20 // suffix added to avoid duplicate symbol
extern int * hookvar_gCar_car_collisions ; // addr: 00514D2C
extern int * hookvar_gFreeze_mechanics ; // addr: 00514D30
extern tU32 * hookvar_gLast_cunning_stunt ; // addr: 00514D34
extern tU32 * hookvar_gWild_start ; // addr: 00514D38
extern tU32 * hookvar_gQuite_wild_start ; // addr: 00514D3C
extern tU32 * hookvar_gQuite_wild_end ; // addr: 00514D40
extern tU32 * hookvar_gOn_me_wheels_start ; // addr: 00514D44
extern int * hookvar_gWoz_upside_down_at_all ; // addr: 00514D48
// extern tS3_sound_tag(* hookvar_gSkid_tag )[2];
// extern tCar_spec *(* hookvar_gLast_car_to_skid )[2];
extern int * hookvar_gEliminate_faces ; // addr: 00514D60
extern br_vector3 * hookvar_gZero_v__car ; // addr: 00514D68 // suffix added to avoid duplicate symbol
// extern tU32 * hookvar_gSwitch_time ;
// extern tSave_camera(* hookvar_gSave_camera )[2];
extern tU32 * hookvar_gLast_mechanics_time ; // addr: 00514D90
extern int * hookvar_gOpponent_viewing_mode ; // addr: 00514D94
extern int * hookvar_gNet_player_to_view_index ; // addr: 00514D98
extern int * hookvar_gDouble_pling_water ; // addr: 00514D9C
extern int * hookvar_gStop_opponents_moving ; // addr: 00514DA0
extern float(* hookvar_gDefensive_powerup_factor )[6]; // addr: 00514DA8
extern float(* hookvar_gOffensive_powerup_factor )[6]; // addr: 00514DC0
extern float(* hookvar_gEngine_powerup_factor )[6]; // addr: 00514DD8
// extern br_angle * hookvar_gPanning_camera_angle ;
// extern br_scalar * hookvar_gPanning_camera_height ;
extern int * hookvar_gFace_count ; // addr: 00514CEC
extern float(* hookvar_gCar_simplification_factor )[2][5]; // addr: 00514E00
extern int * hookvar_gCar_simplification_level ; // addr: 00514E28
extern int * hookvar_gNum_active_non_cars ; // addr: 00514E2C
extern int * hookvar_gCamera_has_collided ; // addr: 00514E30
extern tFace_ref(* hookvar_gFace_list__car )[150]; // addr: 0053A5B8 // suffix added to avoid duplicate symbol
extern tNon_car_spec *(* hookvar_gActive_non_car_list )[50]; // addr: 00550680
extern int * hookvar_gOver_shoot ; // addr: 0053A57C
extern br_scalar * hookvar_gMin_world_y ; // addr: 0053A574
// extern br_scalar * hookvar_gAccel ;
extern br_vector3 * hookvar_gAverage_grid_position ; // addr: 0053A518
extern br_actor ** hookvar_gPed_actor ; // addr: 0053CFE8
// extern int * hookvar_gCollision_count ;
extern int * hookvar_gCamera_frozen ; // addr: 0053D000
extern int * hookvar_gMaterial_index ; // addr: 0053A584
extern int * hookvar_gInTheSea ; // addr: 0053A578
extern int * hookvar_gCamera_mode ; // addr: 0053A524
// extern br_scalar * hookvar_gOur_yaw__car ; // suffix added to avoid duplicate symbol
// extern br_scalar * hookvar_gGravity__car ; // suffix added to avoid duplicate symbol
// extern br_vector3 * hookvar_gNew_ground_normal__car ; // suffix added to avoid duplicate symbol
extern char(* hookvar_gNon_car_spec_list )[100]; // addr: 00550750
extern tU32 * hookvar_gMechanics_time_sync ; // addr: 00550670
extern int * hookvar_gNum_cars_and_non_cars ; // addr: 00550748

void DamageUnit(tCar_spec *pCar, int pUnit_type, int pDamage_amount);

void DamageUnitWithSmoke(tCar_spec *pCar, int pUnit_type, int pDamage_amount);

void DamageEngine(int pDamage_amount);

void DamageTrans(int pDamage_amount);

void DamageSteering(int pDamage_amount);

void DamageLFWheel(int pDamage_amount);

void DamageLFBrake(int pDamage_amount);

void DamageLRBrake(int pDamage_amount);

void DamageLRWheel(int pDamage_amount);

void DamageRFWheel(int pDamage_amount);

void DamageRFBrake(int pDamage_amount);

void DamageRRBrake(int pDamage_amount);

void DamageRRWheel(int pDamage_amount);

void CalculatePlaneNormal(br_vector3 *pP1, br_vector3 *pP2, br_vector3 *pP3, br_vector3 *pNormal);

void CalculateGroundNormal(br_model *pThe_model, int pFace_index);

void ChangeYCoordinate(br_scalar pNew_y, tU32 pTime_taken, br_model *pThe_model, int pFace_index);

void SwitchCarActor(tCar_spec *pCar_spec, int pModel_index);

void InitialiseCar2(tCar_spec *pCar, int pClear_disabled_flag);

void InitialiseCar(tCar_spec *pCar);

void InitialiseCarsEtc(tRace_info *pThe_race);

void GetAverageGridPosition(tRace_info *pThe_race);

void SetInitialPosition(tRace_info *pThe_race, int pCar_index, int pGrid_index);

void SetInitialPositions(tRace_info *pThe_race);

void InitialiseNonCar(tNon_car_spec *non_car);

void GetFacesInBox(tCollision_info *c);

int IsCarInTheSea();

void RememberSafePosition(tCar_spec *car, tU32 pTime);

void ControlOurCar(tU32 pTime_difference);

void CalcEngineForce(tCar_spec *c, br_scalar dt);

void PrepareCars(tU32 pFrame_start_time);

void FinishCars(tU32 pLast_frame_time, tU32 pTime);

void InterpolateCars(tU32 pLast_frame_time, tU32 pTime);

void ResetOldmat();

void GetNonCars();

void GetNetPos(tCar_spec *pCar);

void ApplyPhysicsToCars(tU32 last_frame_time, tU32 pTime_difference);

void MungeSpecialVolume(tCollision_info *pCar);

void ResetCarSpecialVolume(tCollision_info *pCar);

void TestAutoSpecialVolume(tCollision_info *pCar);

void MoveAndCollideCar(tCar_spec *car, br_scalar dt);

void MoveAndCollideNonCar(tNon_car_spec *non_car, br_scalar dt);

int CollideCarWithWall(tCollision_info *car, br_scalar dt);

void ToggleControls();

void ControlCar2(tCar_spec *c, br_scalar dt);

void ControlCar3(tCar_spec *c, br_scalar dt);

void ControlCar4(tCar_spec *c, br_scalar dt);

void ControlCar5(tCar_spec *c, br_scalar dt);

void ControlCar1(tCar_spec *c, br_scalar dt);

void setrotate(struct br_vector3 *wdt, struct br_matrix34 *m);

void RotateCar2(tCollision_info *c, br_scalar dt);

void RotateCarSecondOrder(tCollision_info *c, br_scalar dt);

void RotateCarFirstOrder(tCollision_info *c, br_scalar dt);

void SimpleRotate(tCollision_info *c, br_scalar dt);

void RotateCar(tCollision_info *c, br_scalar dt);

void SteeringSelfCentre(tCar_spec *c, br_scalar dt, br_vector3 *n);

void NonCarCalcForce(tNon_car_spec *nc, br_scalar dt);

void AddDrag(tCar_spec *c, br_scalar dt);

void DoBumpiness(tCar_spec *c, br_vector3 *wheel_pos, br_vector3 *norm, br_scalar *d, int n);

void CalcForce(tCar_spec *c, br_scalar dt);

void DoRevs(tCar_spec *c, br_scalar dt);

void ApplyTorque(tCar_spec *c, br_vector3 *tdt);

void TranslateCar(tCollision_info *c, br_scalar dt);

int CollCheck(tCollision_info *c, br_scalar dt);

br_scalar AddFriction(tCollision_info *c, br_vector3 *vel, br_vector3 *normal_force, br_vector3 *pos, br_scalar total_force, br_vector3 *max_friction);

void AddFrictionCarToCar(tCollision_info *car1, tCollision_info *car2, br_vector3 *vel1, br_vector3 *vel2, br_vector3 *normal_force1, br_vector3 *pos1, br_vector3 *pos2, br_scalar total_force, br_vector3 *max_friction);

void ScrapeNoise(br_scalar vel, br_vector3 *position, int material);

void SkidNoise(tCar_spec *pC, int pWheel_num, br_scalar pV, int material);

void StopSkid(tCar_spec *pC);

void CrashNoise(br_vector3 *pForce, br_vector3 *position, int material);

void CrushAndDamageCar(tCar_spec *c, br_vector3 *pPosition, br_vector3 *pForce_car_space, tCar_spec *car2);

int ExpandBoundingBox(tCar_spec *c);

void CrushBoundingBox(tCar_spec *c, int crush_only);

void AddCollPoint(br_scalar dist, br_vector3 *p, br_vector3 *norm, br_vector3 *r, br_vector3 *n, br_vector3 *dir, int num, tCollision_info *c);

br_scalar SinglePointColl(br_scalar *f, br_matrix4 *m, br_scalar *d);

br_scalar TwoPointColl(br_scalar *f, br_matrix4 *m, br_scalar *d, br_vector3 *tau, br_vector3 *n);

br_scalar DrMatrix4Inverse(br_matrix4 *mi, br_matrix4 *mc);

br_scalar ThreePointColl(br_scalar *f, br_matrix4 *m, br_scalar *d);

br_scalar ThreePointCollRec(br_scalar *f, br_matrix4 *m, br_scalar *d, br_vector3 *tau, br_vector3 *n, tCollision_info *c);

br_scalar FourPointColl(br_scalar *f, br_matrix4 *m, br_scalar *d, br_vector3 *tau, br_vector3 *n, tCollision_info *c);

void MultiFindFloorInBoxM(int pNum_rays, br_vector3 *a, br_vector3 *b, br_vector3 *nor, br_scalar *d, tCar_spec *c, int *mat_ref);

void MultiFindFloorInBoxBU(int pNum_rays, br_vector3 *a, br_vector3 *b, br_vector3 *nor, br_scalar *d, tCar_spec *c, int *mat_ref);

void findfloor(br_vector3 *a, br_vector3 *b, br_vector3 *nor, br_scalar *d);

int FindFloorInBoxM(br_vector3 *a, br_vector3 *b, br_vector3 *nor, br_scalar *d, tCollision_info *c);

int FindFloorInBoxBU(br_vector3 *a, br_vector3 *b, br_vector3 *nor, br_scalar *d, tCollision_info *c);

int FindFloorInBoxBU2(br_vector3 *a, br_vector3 *b, br_vector3 *nor, br_scalar *d, tCollision_info *c);

int FindFloorInBoxM2(br_vector3 *a, br_vector3 *b, br_vector3 *nor, br_scalar *d, tCollision_info *c);

int BoxFaceIntersect(br_bounds *pB, br_matrix34 *pM, br_matrix34 *pMold, br_vector3 *pPoint_list, br_vector3 *pNorm_list, br_scalar *pDist_list, int pMax_pnts, tCollision_info *c);

int AddEdgeCollPoints(br_vector3 *p1, br_vector3 *p2, br_bounds *pB, br_matrix34 *pMold, br_vector3 *pPoint_list, br_vector3 *pNorm_list, int n, int pMax_pnts, tCollision_info *c);

void GetPlaneNormal(br_vector3 *n, int p);

int GetBoundsEdge(br_vector3 *pos, br_vector3 *edge, br_bounds *pB, int plane1, int plane2, br_vector3 *a, br_vector3 *b, br_vector3 *c, int flag);

void oldMoveOurCar(tU32 pTime_difference);

void ToggleCollisionDetection();

void CancelPendingCunningStunt();

float frac(float pN);

void SetAmbientPratCam(tCar_spec *pCar);

void MungeCarGraphics(tU32 pFrame_period);

void ResetCarScreens();

tCar_spec* GetRaceLeader();

void AmIGettingBoredWatchingCameraSpin();

void ViewNetPlayer();

void ViewOpponent();

void ToggleCarToCarCollisions();

void SwapCar();

void AdjustDownForce();

void FreezeMechanics();

void PutOpponentsInNeutral();

void SetPanningFieldOfView();

void CheckDisablePlingMaterials(tCar_spec *pCar);

void PositionExternalCamera(tCar_spec *c, tU32 pTime);

void CameraBugFix(tCar_spec *c, tU32 pTime);

int PossibleRemoveNonCarFromWorld(br_actor *pActor);

void PutNonCarBackInWorld(br_actor *pActor);

int IncidentCam(tCar_spec *c, tU32 pTime);

int MoveCamToIncident(tCar_spec *c, tIncident_type *type, float *severity, tIncident_info *info, tU32 *next_incident_time);

void PanningExternalCamera(tCar_spec *c, tU32 pTime);

int CheckForWall(br_vector3 *start, br_vector3 *end);

void SetUpPanningCamera(tCar_spec *c);

void SaveCameraPosition(int i);

void RestoreCameraPosition(int i);

void NormalPositionExternalCamera(tCar_spec *c, tU32 pTime);

void MoveWithWheels(tCar_spec *c, br_vector3 *vn, int manual_swing);

void SwingCamera(tCar_spec *c, br_matrix34 *m1, br_matrix34 *m2, br_vector3 *vn, tU32 pTime);

void PointCameraAtCar(tCar_spec *c, br_matrix34 *m1, br_matrix34 *m2);

void PointCamera(br_vector3 *pos, br_matrix34 *m2);

int CollideCamera2(br_vector3 *car_pos, br_vector3 *cam_pos, br_vector3 *old_camera_pos, int manual_move);

int BoundsTest(br_bounds *bnds, br_vector3 *p);

int CollideCameraWithOtherCars(br_vector3 *car_pos, br_vector3 *cam_pos);

void InitialiseExternalCamera();

void FreezeCamera();

void FlyCar(tCar_spec *c, br_scalar dt);

void DrVector3RotateY(br_vector3 *v, br_angle t);

void CrashCarsTogether(br_scalar dt);

int CrashCarsTogetherSinglePass(br_scalar dt, int pPass, tCollison_data *collide_list);

void BringCarToAGrindingHalt(tCollision_info *car);

int BoundsOverlapTest__car(br_bounds *b1, br_bounds *b2);

int SimpleCarCarCollisionTest(tCollision_info *car1, tCollision_info *car2);

int CollideTwoCarsWithWalls(tCollision_info *car1, tCollision_info *car2, br_scalar dt);

int CollideTwoCarsRepeatedly(tCollision_info *car1, tCollision_info *car2, br_scalar dt);

int CollideTwoCars(tCollision_info *car1, tCollision_info *car2, int pPass);

int GetEdgeEdgeCollisions(br_bounds *pB1, br_bounds *pB2, br_matrix34 *pM21, br_matrix34 *pM12, br_matrix34 *pMo21, br_matrix34 *pMo12, br_matrix34 *pM1o1, br_vector3 *pPoint_list, br_vector3 *pNorm_list, int pMax);

int FacePointCarCarCollide(tCollision_info *car1, tCollision_info *car2, br_matrix34 *pMms, br_matrix34 *pMoms, br_matrix34 *pMsos, br_vector3 *pPoint_list, br_vector3 *pNorm_list, int pMax, int order);

void MungeCarsMass(tCollision_info *pCar, br_scalar pFactor);

void ModifyCarsMass(tCollision_info *pCar_1, tCollision_info *pCar_2);

void ResetCarsMass(tCollision_info *pCar_1, tCollision_info *pCar_2);

int DoCollide(tCollision_info *car1, tCollision_info *car2, br_vector3 *r, br_vector3 *n, int k, int pPass, br_matrix34 *mat1_to_mat2);

br_scalar TwoPointCollB(br_scalar *f, br_matrix4 *m, br_scalar *d, br_vector3 *tau, br_vector3 *n);

br_scalar ThreePointCollRecB(br_scalar *f, br_matrix4 *m, br_scalar *d, br_vector3 *tau, br_vector3 *n);

br_scalar FourPointCollB(br_scalar *f, br_matrix4 *m, br_scalar *d, br_vector3 *tau, br_vector3 *n);

int TestForNan(float *f);

void CheckCameraHither();

void SetCarSuspGiveAndHeight(tCar_spec *pCar, br_scalar pFront_give_factor, br_scalar pRear_give_factor, br_scalar pDamping_factor, br_scalar pExtra_front_height, br_scalar pExtra_rear_height);

int TestForCarInSensiblePlace(tCar_spec *car);

int TestOldMats(tCollision_info *c1, tCollision_info *c2, int newmats);

int PullActorFromWorld(br_actor *pActor);

int DoPullActorFromWorld(br_actor *pActor);

void CheckForDeAttachmentOfNonCars(tU32 pTime);

void AdjustNonCar(br_actor *pActor, br_matrix34 *pMat);

void PipeSingleNonCar(tCollision_info *c);

int GetPrecalculatedFacesUnderCar(tCar_spec *pCar, tFace_ref **pFace_refs);

br_material* SomeNearbyMaterial();

#endif
