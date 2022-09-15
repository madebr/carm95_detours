#ifndef _PEDESTRN_H_
#define _PEDESTRN_H_

#include "br_types.h"
#include "dr_types.h"

extern int * hookvar_gDetect_peds ; // addr: 00511740
extern int * hookvar_gReally_stupid_ped_bug_enable ; // addr: 00511744
extern int * hookvar_gPed_sound_disable ; // addr: 00511748
extern int * hookvar_gVesuvians_last_time ; // addr: 0051174C
extern int * hookvar_gSend_peds ; // addr: 00511750
extern tU32 * hookvar_gLast_ped_message_send ; // addr: 00511754
extern char *(* hookvar_gRate_commands )[3]; // addr: 00511760
extern char *(* hookvar_gCollide_commands )[1]; // addr: 0051176C
extern char *(* hookvar_gInstruc_commands )[10]; // addr: 00511770
extern float(* hookvar_gMin_ped_gib_speeds )[4]; // addr: 00511798
extern float(* hookvar_gPed_gib_distrib )[4]; // addr: 005117A8
extern float(* hookvar_gPed_gib_speeds )[4]; // addr: 005117B8
extern int(* hookvar_gPed_size_counts )[4]; // addr: 005117C8
extern char *(* hookvar_gPed_gib_names )[4][5]; // addr: 005117D8
extern char *(* hookvar_gPed_geb_names )[4][5]; // addr: 00511828
extern int(* hookvar_gPed_gib_maxes )[4][5]; // addr: 00511878
extern br_scalar(* hookvar_gExploding_ped_scale )[3]; // addr: 005118C8
extern br_vector3 * hookvar_gZero_v__pedestrn ; // addr: 005118D8 // suffix added to avoid duplicate symbol
extern int * hookvar_gPed_instruc_count ; // addr: 005118E8
extern int * hookvar_gPed_count ; // addr: 00536B50
extern br_actor ** hookvar_gPath_actor ; // addr: 005118F0
extern br_actor ** hookvar_gCurrent_ped_path_actor ; // addr: 005118F4
extern int * hookvar_gPedestrians_on ; // addr: 005118F8
extern int * hookvar_gVesuvian_corpses ; // addr: 005118FC
extern br_material ** hookvar_gPed_material ; // addr: 005118E4
extern int(* hookvar_gPed_gib_counts )[4][5]; // addr: 005378C8
extern tPed_gib(* hookvar_gPed_gibs )[30]; // addr: 00537418
extern tPed_gib_materials(* hookvar_gPed_gib_materials )[4]; // addr: 00536AB0
extern tProximity_ray(* hookvar_gProximity_rays )[20]; // addr: 00536B58
// extern int * hookvar_gPed_colliding ;
extern float * hookvar_gZombie_factor ; // addr: 00550A90
extern int * hookvar_gRespawn_variance ; // addr: 00550AAC
extern br_scalar * hookvar_gPed_scale_factor ; // addr: 00550A94
extern int * hookvar_gTotal_peds ; // addr: 00550A8C
extern int * hookvar_gPedestrian_harvest ; // addr: 00550AA0
// extern br_vector3 * hookvar_gPed_pos_camera ;
extern int * hookvar_gMin_respawn_time ; // addr: 00550AA4
extern br_material ** hookvar_gPath_mat_calc ; // addr: 00536B38
extern float * hookvar_gPedestrian_speed_factor ; // addr: 00550AA8
extern int * hookvar_gExploding_pedestrians ; // addr: 00550A88
extern int * hookvar_gBlind_pedestrians ; // addr: 00550A84
extern br_material ** hookvar_gPath_mat_normal ; // addr: 00536B18
extern br_material ** hookvar_gInit_pos_mat_calc ; // addr: 00536B1C
// extern int * hookvar_gPed_other ;
extern int * hookvar_gAttracted_pedestrians ; // addr: 00550A98
extern int * hookvar_gPed_ref_num ; // addr: 00536AAC
extern br_scalar * hookvar_gMax_distance_squared ; // addr: 00536B24
extern br_model ** hookvar_gPed_model ; // addr: 00536B28
extern float * hookvar_gDanger_level ; // addr: 00536B20
extern br_vector3 * hookvar_gDanger_direction ; // addr: 00536B40
extern int * hookvar_gInit_ped_instruc ; // addr: 00536B4C
extern int * hookvar_gCurrent_lollipop_index ; // addr: 00536B10
extern int * hookvar_gVesuvians_this_time ; // addr: 00536AA8
// extern int * hookvar_gNumber_of_ped_gibs ;
extern tPedestrian_data ** hookvar_gFlag_waving_bastard ; // addr: 00536B14
extern int * hookvar_gNumber_of_pedestrians ; // addr: 005118EC
extern br_pixelmap ** hookvar_gProx_ray_shade_table ; // addr: 00536B30
extern tPedestrian_data ** hookvar_gPedestrian_array ; // addr: 0053791C
extern tU32 * hookvar_gLast_ped_splat_time ; // addr: 00536B34
extern int * hookvar_gCurrent_ped_multiplier ; // addr: 00537918

void PedModelUpdate(br_model *pModel, br_scalar x0, br_scalar y0, br_scalar x1, br_scalar y1, br_scalar x2, br_scalar y2, br_scalar x3, br_scalar y3);

int ActorIsPedestrian(br_actor *pActor);

br_scalar PedHeightFromActor(br_actor *pActor);

int GetPedestrianValue(br_actor *pActor);

int PedestrianActorIsPerson(br_actor *pActor);

br_actor* GetPedestrianActor(int pIndex);

br_pixelmap* GetPedestrianTexture(br_actor *pActor, int *pFlipped);

void TogglePedestrians();

void InitPedGibs();

void SetPedMaterialForRender(br_actor *pActor);

void PedCallBack(br_actor *pActor, struct br_model *pModel, struct br_material *pMaterial, void *pRender_data, br_uint_8 pStyle, int pOn_screen);

void InitPeds();

void MungeModelSize(br_actor *pActor, br_scalar pScaling_factor);

int BurstPedestrian(tPedestrian_data *pPedestrian, float pSplattitudinalitude, int pAllow_explosion);

void ResetAllPedGibs();

void AdjustPedGib(int pIndex, int pSize, int pGib_index, int pPed_index, br_matrix34 *pTrans);

void MungePedGibs(tU32 pFrame_period);

void KillPedestrian(tPedestrian_data *pPedestrian);

void CalcPedWidthNHeight(tPedestrian_data *pPedestrian, br_pixelmap *pPixelmap, br_scalar *pHeight, br_scalar *pWidth);

int PedestrianNextInstruction(tPedestrian_data *pPedestrian, float pDanger_level, int pPosition_explicitly, int pMove_pc);

void MungePedestrianSequence(tPedestrian_data *pPedestrian, int pAction_changed);

void DetachPedFromCar(tPedestrian_data *pPedestrian);

void SetPedPos(tPedestrian_data *pPedestrian);

void DetachPedActorFromCar(br_actor *pActor);

void MungePedestrianFrames(tPedestrian_data *pPedestrian);

void MungePedModel(tPedestrian_data *pPedestrian);

void ChangeActionTo(tPedestrian_data *pPedestrian, int pAction_index, int pRedo_frames_etc);

int MungePedestrianAction(tPedestrian_data *pPedestrian, float pDanger_level);

void MakeFlagWavingBastardWaveHisFlagWhichIsTheProbablyTheLastThingHeWillEverDo();

void MungePedestrianPath(tPedestrian_data *pPedestrian, float pDanger_level, br_vector3 *pDanger_direction);

float CalcPedestrianDangerLevel(tPedestrian_data *pPedestrian, br_vector3 *pDanger_direction);

tPed_hit_position MoveToEdgeOfCar(tPedestrian_data *pPedestrian, tCollision_info *pCar, br_actor *pCar_actor, br_scalar pPed_x, br_scalar pPed_z, br_scalar pCar_bounds_min_x, br_scalar pCar_bounds_max_x, br_scalar pCar_bounds_min_z, br_scalar pCar_bounds_max_z, br_vector3 *pMin_ped_bounds_car, br_vector3 *pMax_ped_bounds_car);

void CheckLastPed();

int BloodyWheels(tCar_spec *pCar, br_vector3 *pPed_car, br_scalar pSize, br_vector3 *pPed_glob);

int FancyATossOffMate(tPedestrian_data *pPedestrian, tCollision_info *pCar, float pImpact_speed);

void CheckPedestrianDeathScenario(tPedestrian_data *pPedestrian);

void SendPedestrian(tPedestrian_data *pPedestrian, int pIndex);

void DoPedestrian(tPedestrian_data *pPedestrian, int pIndex);

void AdjustPedestrian(int pIndex, int pAction_index, int pFrame_index, int pHit_points, int pDone_initial, tU16 pParent, br_actor *pParent_actor, float pSpin_period, br_scalar pJump_magnitude, br_vector3 *pOffset, br_vector3 *pTrans);

void SquirtPathVertex(br_vertex *pFirst_vertex, br_vector3 *pPoint);

void ResetAllPedestrians();

void GroundPedestrian(tPedestrian_data *pPedestrian);

void RevivePedestrian(tPedestrian_data *pPedestrian, int pAnimate);

void MungePedestrians(tU32 pFrame_period);

void RespawnPedestrians();

int GetPedCount();

int GetPedPosition(int pIndex, br_vector3 *pPos);

void CreatePedestrian(FILE *pG, tPedestrian_instruction *pInstructions, int pInstruc_count, int pInit_instruc, int pRef_num, int pForce_read);

void ResetProxRay();

void PedMaterialFromHell();

void ResetPedMaterial();

void LoadInPedestrians(FILE *pF, int pSubs_count, tPed_subs *pSubs_array);

br_actor* BuildPedPaths(tPedestrian_instruction *pInstructions, int pInstruc_count, int pInit_instruc);

void WriteOutPeds();

void AddPed();

void NewPed(int pRef_num);

void RemoveCurrentPedPath();

void ScrubPedestrian();

void TogglePedDetect();

void NewPed0();

void NewPed1();

void NewPed2();

void NewPed3();

void NewPed4();

void NewPed5();

void NewPed6();

void NewPed7();

void NewPed8();

void NewPed9();

void NewPed0B();

void NewPed1B();

void NewPed2B();

void NewPed3B();

void NewPed4B();

void NewPed5B();

void NewPed6B();

void NewPed7B();

void NewPed8B();

void NewPed9B();

void MungeShowPedPath();

void DropPedPoint2();

void DropPedPoint();

void DropInitPedPoint();

void DropPedPointAir2();

void DropPedPointAir();

void DropInitPedPointAir();

br_uint_32 KillActorsModel(br_actor *pActor, void *pArg);

void DisposePedPaths();

void GetPedPos(int *pPed_index, int *pPoint_index);

void ShowPedPos();

void ShowPedPaths();

void PullPedPoint();

void PullPedPointAir();

void DeletePedPath();

void DeletePedPoint();

void DisposePedestrians();

void DoPedReport();

void RenderProximityRays(br_pixelmap *pRender_screen, br_pixelmap *pDepth_buffer, br_actor *pCamera, br_matrix34 *pCamera_to_world, tU32 pTime);

void AdjustProxRay(int pRay_index, tU16 pCar_ID, tU16 pPed_index, tU32 pTime);

void ReceivedPedestrian(tNet_contents *pContents, tNet_message *pMessage, tU32 pReceive_time);

void SendAllPedestrianPositions(tPlayer_ID pPlayer);

#endif
