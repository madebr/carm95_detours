#ifndef _CAR_H_
#define _CAR_H_

#include "br_types.h"
#include "dr_types.h"

extern int * hookvar_gDoing_physics ; // addr: 00514CB0
extern br_scalar * hookvar_gDt ; // addr: 00514CB4
extern int * hookvar_gCollision_detection_on__car ; // addr: 00514CB8 // suffix added to avoid duplicate symbol
extern br_vector3 * hookvar_gGround_normal__car ; // addr: 00514CC0 // suffix added to avoid duplicate symbol
// extern void(**(* hookvar_ControlCar__car )[6])(tCar_spec *, br_scalar); // suffix added to avoid duplicate symbol
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
extern tS3_sound_tag(* hookvar_gSkid_tag )[2]; // addr: 00514D50
extern tCar_spec *(* hookvar_gLast_car_to_skid )[2]; // addr: 00514D58
extern int * hookvar_gEliminate_faces ; // addr: 00514D60
extern br_vector3 * hookvar_gZero_v__car ; // addr: 00514D68 // suffix added to avoid duplicate symbol
extern tU32 * hookvar_gSwitch_time ; // addr: 00514D74
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

void __cdecl DamageUnit(tCar_spec *pCar, int pUnit_type, int pDamage_amount);

void __cdecl DamageUnitWithSmoke(tCar_spec *pCar, int pUnit_type, int pDamage_amount);

void __cdecl DamageEngine(int pDamage_amount);

void __cdecl DamageTrans(int pDamage_amount);

void __cdecl DamageSteering(int pDamage_amount);

void __cdecl DamageLFWheel(int pDamage_amount);

void __cdecl DamageLFBrake(int pDamage_amount);

void __cdecl DamageLRBrake(int pDamage_amount);

void __cdecl DamageLRWheel(int pDamage_amount);

void __cdecl DamageRFWheel(int pDamage_amount);

void __cdecl DamageRFBrake(int pDamage_amount);

void __cdecl DamageRRBrake(int pDamage_amount);

void __cdecl DamageRRWheel(int pDamage_amount);

void CalculatePlaneNormal(br_vector3 *pP1, br_vector3 *pP2, br_vector3 *pP3, br_vector3 *pNormal);

void CalculateGroundNormal(br_model *pThe_model, int pFace_index);

void ChangeYCoordinate(br_scalar pNew_y, tU32 pTime_taken, br_model *pThe_model, int pFace_index);

void __cdecl SwitchCarActor(tCar_spec *pCar_spec, int pModel_index);

void __cdecl InitialiseCar2(tCar_spec *pCar, int pClear_disabled_flag);

void __cdecl InitialiseCar(tCar_spec *pCar);

void __cdecl InitialiseCarsEtc(tRace_info *pThe_race);

void __cdecl GetAverageGridPosition(tRace_info *pThe_race);

void __cdecl SetInitialPosition(tRace_info *pThe_race, int pCar_index, int pGrid_index);

void __cdecl SetInitialPositions(tRace_info *pThe_race);

void __cdecl InitialiseNonCar(tNon_car_spec *non_car);

void __cdecl GetFacesInBox(tCollision_info *c);

int __cdecl IsCarInTheSea();

void __cdecl RememberSafePosition(tCar_spec *car, tU32 pTime);

void __cdecl ControlOurCar(tU32 pTime_difference);

void __cdecl CalcEngineForce(tCar_spec *c, br_scalar dt);

void __cdecl PrepareCars(tU32 pFrame_start_time);

void __cdecl FinishCars(tU32 pLast_frame_time, tU32 pTime);

void __cdecl InterpolateCars(tU32 pLast_frame_time, tU32 pTime);

void __cdecl ResetOldmat();

void __cdecl GetNonCars();

void __cdecl GetNetPos(tCar_spec *pCar);

void __cdecl ApplyPhysicsToCars(tU32 last_frame_time, tU32 pTime_difference);

void __cdecl MungeSpecialVolume(tCollision_info *pCar);

void __cdecl ResetCarSpecialVolume(tCollision_info *pCar);

void __cdecl TestAutoSpecialVolume(tCollision_info *pCar);

void __cdecl MoveAndCollideCar(tCar_spec *car, br_scalar dt);

void __cdecl MoveAndCollideNonCar(tNon_car_spec *non_car, br_scalar dt);

int __cdecl CollideCarWithWall(tCollision_info *car, br_scalar dt);

void ToggleControls();

void __cdecl ControlCar2(tCar_spec *c, br_scalar dt);

void __cdecl ControlCar3(tCar_spec *c, br_scalar dt);

void __cdecl ControlCar4(tCar_spec *c, br_scalar dt);

void __cdecl ControlCar5(tCar_spec *c, br_scalar dt);

void __cdecl ControlCar1(tCar_spec *c, br_scalar dt);

void setrotate(struct br_vector3 *wdt, struct br_matrix34 *m);

void RotateCar2(tCollision_info *c, br_scalar dt);

void __cdecl RotateCarSecondOrder(tCollision_info *c, br_scalar dt);

void RotateCarFirstOrder(tCollision_info *c, br_scalar dt);

void __cdecl SimpleRotate(tCollision_info *c, br_scalar dt);

void __cdecl RotateCar(tCollision_info *c, br_scalar dt);

void __cdecl SteeringSelfCentre(tCar_spec *c, br_scalar dt, br_vector3 *n);

void __cdecl NonCarCalcForce(tNon_car_spec *nc, br_scalar dt);

void __cdecl AddDrag(tCar_spec *c, br_scalar dt);

void __cdecl DoBumpiness(tCar_spec *c, br_vector3 *wheel_pos, br_vector3 *norm, br_scalar *d, int n);

void __cdecl CalcForce(tCar_spec *c, br_scalar dt);

void __cdecl DoRevs(tCar_spec *c, br_scalar dt);

void __cdecl ApplyTorque(tCar_spec *c, br_vector3 *tdt);

void __cdecl TranslateCar(tCollision_info *c, br_scalar dt);

int __cdecl CollCheck(tCollision_info *c, br_scalar dt);

br_scalar __cdecl AddFriction(tCollision_info *c, br_vector3 *vel, br_vector3 *normal_force, br_vector3 *pos, br_scalar total_force, br_vector3 *max_friction);

void __cdecl AddFrictionCarToCar(tCollision_info *car1, tCollision_info *car2, br_vector3 *vel1, br_vector3 *vel2, br_vector3 *normal_force1, br_vector3 *pos1, br_vector3 *pos2, br_scalar total_force, br_vector3 *max_friction);

void __cdecl ScrapeNoise(br_scalar vel, br_vector3 *position, int material);

void __cdecl SkidNoise(tCar_spec *pC, int pWheel_num, br_scalar pV, int material);

void __cdecl StopSkid(tCar_spec *pC);

void __cdecl CrashNoise(br_vector3 *pForce, br_vector3 *position, int material);

void __cdecl CrushAndDamageCar(tCar_spec *c, br_vector3 *pPosition, br_vector3 *pForce_car_space, tCar_spec *car2);

int __cdecl ExpandBoundingBox(tCar_spec *c);

void __cdecl CrushBoundingBox(tCar_spec *c, int crush_only);

void __cdecl AddCollPoint(br_scalar dist, br_vector3 *p, br_vector3 *norm, br_vector3 *r, br_vector3 *n, br_vector3 *dir, int num, tCollision_info *c);

br_scalar __cdecl SinglePointColl(br_scalar *f, br_matrix4 *m, br_scalar *d);

br_scalar __cdecl TwoPointColl(br_scalar *f, br_matrix4 *m, br_scalar *d, br_vector3 *tau, br_vector3 *n);

br_scalar __cdecl DrMatrix4Inverse(br_matrix4 *mi, br_matrix4 *mc);

br_scalar __cdecl ThreePointColl(br_scalar *f, br_matrix4 *m, br_scalar *d);

br_scalar __cdecl ThreePointCollRec(br_scalar *f, br_matrix4 *m, br_scalar *d, br_vector3 *tau, br_vector3 *n, tCollision_info *c);

br_scalar __cdecl FourPointColl(br_scalar *f, br_matrix4 *m, br_scalar *d, br_vector3 *tau, br_vector3 *n, tCollision_info *c);

void __cdecl MultiFindFloorInBoxM(int pNum_rays, br_vector3 *a, br_vector3 *b, br_vector3 *nor, br_scalar *d, tCar_spec *c, int *mat_ref);

void __cdecl MultiFindFloorInBoxBU(int pNum_rays, br_vector3 *a, br_vector3 *b, br_vector3 *nor, br_scalar *d, tCar_spec *c, int *mat_ref);

void __cdecl findfloor(br_vector3 *a, br_vector3 *b, br_vector3 *nor, br_scalar *d);

int __cdecl FindFloorInBoxM(br_vector3 *a, br_vector3 *b, br_vector3 *nor, br_scalar *d, tCollision_info *c);

int __cdecl FindFloorInBoxBU(br_vector3 *a, br_vector3 *b, br_vector3 *nor, br_scalar *d, tCollision_info *c);

int __cdecl FindFloorInBoxBU2(br_vector3 *a, br_vector3 *b, br_vector3 *nor, br_scalar *d, tCollision_info *c);

int __cdecl FindFloorInBoxM2(br_vector3 *a, br_vector3 *b, br_vector3 *nor, br_scalar *d, tCollision_info *c);

int __cdecl BoxFaceIntersect(br_bounds *pB, br_matrix34 *pM, br_matrix34 *pMold, br_vector3 *pPoint_list, br_vector3 *pNorm_list, br_scalar *pDist_list, int pMax_pnts, tCollision_info *c);

int __cdecl AddEdgeCollPoints(br_vector3 *p1, br_vector3 *p2, br_bounds *pB, br_matrix34 *pMold, br_vector3 *pPoint_list, br_vector3 *pNorm_list, int n, int pMax_pnts, tCollision_info *c);

void __cdecl GetPlaneNormal(br_vector3 *n, int p);

int __cdecl GetBoundsEdge(br_vector3 *pos, br_vector3 *edge, br_bounds *pB, int plane1, int plane2, br_vector3 *a, br_vector3 *b, br_vector3 *c, int flag);

void oldMoveOurCar(tU32 pTime_difference);

void ToggleCollisionDetection();

void __cdecl CancelPendingCunningStunt();

float __cdecl frac(float pN);

void __cdecl SetAmbientPratCam(tCar_spec *pCar);

void __cdecl MungeCarGraphics(tU32 pFrame_period);

void __cdecl ResetCarScreens();

tCar_spec* __cdecl GetRaceLeader();

void __cdecl AmIGettingBoredWatchingCameraSpin();

void __cdecl ViewNetPlayer();

void __cdecl ViewOpponent();

void __cdecl ToggleCarToCarCollisions();

void __cdecl SwapCar();

void __cdecl AdjustDownForce();

void __cdecl FreezeMechanics();

void __cdecl PutOpponentsInNeutral();

void __cdecl SetPanningFieldOfView();

void __cdecl CheckDisablePlingMaterials(tCar_spec *pCar);

void __cdecl PositionExternalCamera(tCar_spec *c, tU32 pTime);

void __cdecl CameraBugFix(tCar_spec *c, tU32 pTime);

int __cdecl PossibleRemoveNonCarFromWorld(br_actor *pActor);

void __cdecl PutNonCarBackInWorld(br_actor *pActor);

int __cdecl IncidentCam(tCar_spec *c, tU32 pTime);

int __cdecl MoveCamToIncident(tCar_spec *c, tIncident_type *type, float *severity, tIncident_info *info, tU32 *next_incident_time);

void __cdecl PanningExternalCamera(tCar_spec *c, tU32 pTime);

int __cdecl CheckForWall(br_vector3 *start, br_vector3 *end);

void __cdecl SetUpPanningCamera(tCar_spec *c);

void __cdecl SaveCameraPosition(int i);

void __cdecl RestoreCameraPosition(int i);

void __cdecl NormalPositionExternalCamera(tCar_spec *c, tU32 pTime);

void __cdecl MoveWithWheels(tCar_spec *c, br_vector3 *vn, int manual_swing);

void __cdecl SwingCamera(tCar_spec *c, br_matrix34 *m1, br_matrix34 *m2, br_vector3 *vn, tU32 pTime);

void __cdecl PointCameraAtCar(tCar_spec *c, br_matrix34 *m1, br_matrix34 *m2);

void __cdecl PointCamera(br_vector3 *pos, br_matrix34 *m2);

int __cdecl CollideCamera2(br_vector3 *car_pos, br_vector3 *cam_pos, br_vector3 *old_camera_pos, int manual_move);

int __cdecl BoundsTest(br_bounds *bnds, br_vector3 *p);

int __cdecl CollideCameraWithOtherCars(br_vector3 *car_pos, br_vector3 *cam_pos);

void __cdecl InitialiseExternalCamera();

void __cdecl FreezeCamera();

void __cdecl FlyCar(tCar_spec *c, br_scalar dt);

void __cdecl DrVector3RotateY(br_vector3 *v, br_angle t);

void __cdecl CrashCarsTogether(br_scalar dt);

int __cdecl CrashCarsTogetherSinglePass(br_scalar dt, int pPass, tCollison_data *collide_list);

void __cdecl BringCarToAGrindingHalt(tCollision_info *car);

int BoundsOverlapTest__car(br_bounds *b1, br_bounds *b2);

int __cdecl SimpleCarCarCollisionTest(tCollision_info *car1, tCollision_info *car2);

int __cdecl CollideTwoCarsWithWalls(tCollision_info *car1, tCollision_info *car2, br_scalar dt);

int __cdecl CollideTwoCarsRepeatedly(tCollision_info *car1, tCollision_info *car2, br_scalar dt);

int __cdecl CollideTwoCars(tCollision_info *car1, tCollision_info *car2, int pPass);

int __cdecl GetEdgeEdgeCollisions(br_bounds *pB1, br_bounds *pB2, br_matrix34 *pM21, br_matrix34 *pM12, br_matrix34 *pMo21, br_matrix34 *pMo12, br_matrix34 *pM1o1, br_vector3 *pPoint_list, br_vector3 *pNorm_list, int pMax);

int __cdecl FacePointCarCarCollide(tCollision_info *car1, tCollision_info *car2, br_matrix34 *pMms, br_matrix34 *pMoms, br_matrix34 *pMsos, br_vector3 *pPoint_list, br_vector3 *pNorm_list, int pMax, int order);

void __cdecl MungeCarsMass(tCollision_info *pCar, br_scalar pFactor);

void __cdecl ModifyCarsMass(tCollision_info *pCar_1, tCollision_info *pCar_2);

void __cdecl ResetCarsMass(tCollision_info *pCar_1, tCollision_info *pCar_2);

int __cdecl DoCollide(tCollision_info *car1, tCollision_info *car2, br_vector3 *r, br_vector3 *n, int k, int pPass, br_matrix34 *mat1_to_mat2);

br_scalar __cdecl TwoPointCollB(br_scalar *f, br_matrix4 *m, br_scalar *d, br_vector3 *tau, br_vector3 *n);

br_scalar __cdecl ThreePointCollRecB(br_scalar *f, br_matrix4 *m, br_scalar *d, br_vector3 *tau, br_vector3 *n);

br_scalar __cdecl FourPointCollB(br_scalar *f, br_matrix4 *m, br_scalar *d, br_vector3 *tau, br_vector3 *n);

int __cdecl TestForNan(float *f);

void __cdecl CheckCameraHither();

void __cdecl SetCarSuspGiveAndHeight(tCar_spec *pCar, br_scalar pFront_give_factor, br_scalar pRear_give_factor, br_scalar pDamping_factor, br_scalar pExtra_front_height, br_scalar pExtra_rear_height);

int __cdecl TestForCarInSensiblePlace(tCar_spec *car);

int __cdecl TestOldMats(tCollision_info *c1, tCollision_info *c2, int newmats);

int __cdecl PullActorFromWorld(br_actor *pActor);

int __cdecl DoPullActorFromWorld(br_actor *pActor);

void __cdecl CheckForDeAttachmentOfNonCars(tU32 pTime);

void __cdecl AdjustNonCar(br_actor *pActor, br_matrix34 *pMat);

void __cdecl PipeSingleNonCar(tCollision_info *c);

int __cdecl GetPrecalculatedFacesUnderCar(tCar_spec *pCar, tFace_ref **pFace_refs);

br_material* SomeNearbyMaterial();

#endif
