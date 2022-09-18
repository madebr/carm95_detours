#ifndef _OPPONENT_H_
#define _OPPONENT_H_

#include "br_types.h"
#include "dr_types.h"

extern br_actor ** hookvar_gOppo_path_actor ; // addr: 005070D0
extern br_model ** hookvar_gOppo_path_model ; // addr: 005070D4
extern br_material ** hookvar_gMat_dk_yel ; // addr: 005070D8
extern br_material ** hookvar_gMat_md_yel ; // addr: 005070DC
extern br_material ** hookvar_gMat_lt_yel ; // addr: 005070E0
extern br_material ** hookvar_gMat_dk_red ; // addr: 005070E4
extern br_material ** hookvar_gMat_lt_red ; // addr: 005070E8
extern br_material ** hookvar_gMat_dk_grn ; // addr: 005070EC
extern br_material ** hookvar_gMat_lt_grn ; // addr: 005070F0
extern br_material ** hookvar_gMat_dk_blu ; // addr: 005070F4
extern br_material ** hookvar_gMat_lt_blu ; // addr: 005070F8
extern br_material ** hookvar_gMat_dk_turq ; // addr: 005070FC
extern br_material ** hookvar_gMat_lt_turq ; // addr: 00507100
extern br_material ** hookvar_gMat_dk_gry ; // addr: 00507104
extern br_material ** hookvar_gMat_md_gry ; // addr: 00507108
extern br_material ** hookvar_gMat_lt_gry ; // addr: 0050710C
extern int * hookvar_gMellow_opponents ; // addr: 00507110
extern int * hookvar_gTest_toggle ; // addr: 00507114
extern int * hookvar_gAlready_elasticating ; // addr: 00507118
// extern int * hookvar_gVertices_used_in_non_edit_paths ;
// extern int * hookvar_gFaces_used_in_non_edit_paths ;
extern int * hookvar_gMats_allocated ; // addr: 00507124
extern int * hookvar_gOppo_paths_shown ; // addr: 00507128
extern int * hookvar_gMade_path_filename ; // addr: 0050712C
extern int * hookvar_gBIG_APC_index ; // addr: 00507130
extern char *(* hookvar_gPath_section_type_names )[3]; // addr: 00507138
extern int * hookvar_gMin_bangness ; // addr: 00507144
extern int * hookvar_gMax_bangness ; // addr: 00507148
extern tU32 * hookvar_gNext_elastication ; // addr: 0050714C
extern tU32 * hookvar_gNext_write_during_elastication ; // addr: 00507150
extern char ** hookvar_gCop_name ; // addr: 00507154
extern char ** hookvar_gDrone_name ; // addr: 00507158
extern int * hookvar_gChallenger_index__opponent ; // addr: 0050715C // suffix added to avoid duplicate symbol
extern int * hookvar_gSFS_count ; // addr: 00507160
extern int * hookvar_gSFS_total_cycles ; // addr: 00507164
extern int * hookvar_gSFS_max_cycles ; // addr: 00507168
extern float * hookvar_gOpponent_nastyness_frigger ; // addr: 0050716C
extern char(* hookvar_gOppo_path_filename )[256]; // addr: 00530CA8
extern br_scalar * hookvar_gIn_view_distance ; // addr: 00530DF0
extern tU8 ** hookvar_gBit_per_node ; // addr: 00530DE8
extern int * hookvar_gGrudge_reduction_per_period ; // addr: 00530DA8
extern int * hookvar_gSFS_cycles_this_time ; // addr: 00530DF8
extern br_scalar * hookvar_gMinimum_yness_before_knackerisation ; // addr: 00530DEC
// extern int * hookvar_gWanky_arse_tit_fuck ;
extern br_scalar * hookvar_gHead_on_cos_value ; // addr: 00530DF4
extern tU32 * hookvar_gNext_grudge_reduction ; // addr: 00530DE0
extern br_scalar * hookvar_gCop_pursuit_speed_percentage_multiplier ; // addr: 00530DD0
extern br_scalar * hookvar_gDefinite_cop_pursuit_speed ; // addr: 00530DBC
extern int * hookvar_gAcknowledged_start ; // addr: 00530DD8
extern int * hookvar_gStart_jumped ; // addr: 00530CA0
extern int * hookvar_gNum_of_opponents_getting_near ; // addr: 00530DC8
// extern int * hookvar_gNumber_of_cops_before_faffage ;
extern int * hookvar_gFirst_frame ; // addr: 00530DC0
extern tU32 * hookvar_gAcme_frame_count ; // addr: 00530DAC
extern br_scalar * hookvar_gDefinite_no_cop_pursuit_speed ; // addr: 00530DB8
extern int * hookvar_gNum_of_opponents_completing_race ; // addr: 00530DE4
extern int * hookvar_gNum_of_opponents_pursuing ; // addr: 00530C98
extern int * hookvar_gActive_car_list_rebuild_required ; // addr: 00530DC4
extern br_scalar * hookvar_gFrame_period_for_this_munging_in_secs ; // addr: 00530DB4
extern int * hookvar_gBig_bang ; // addr: 00530C94
// extern int * hookvar_gProcessing_opponents ;
extern tU32 * hookvar_gFrame_period_for_this_munging ; // addr: 005520E0
extern tU32 * hookvar_gTime_stamp_for_this_munging ; // addr: 005520E4
extern tS16 * hookvar_gMobile_section ; // addr: 00530C90

void __cdecl PointActorAlongThisBloodyVector(br_actor *pThe_actor, br_vector3 *pThe_vector);

void __cdecl ProcessCurrentObjective(tOpponent_spec *pOpponent_spec, tProcess_objective_command pCommand);

tS16 __cdecl ReallocExtraPathNodes(int pHow_many_then);

tS16 __cdecl ReallocExtraPathSections(int pHow_many_then);

int __cdecl PointVisibleFromHere(br_vector3 *pFrom, br_vector3 *pTo);

tS16 __cdecl FindNearestPathNode(br_vector3 *pActor_coords, br_scalar *pDistance);

tS16 __cdecl FindNearestPathSection(br_vector3 *pActor_coords, br_vector3 *pPath_direction, br_vector3 *pIntersect, br_scalar *pDistance);

tS16 __cdecl FindNearestGeneralSection(tCar_spec *pPursuee, br_vector3 *pActor_coords, br_vector3 *pPath_direction, br_vector3 *pIntersect, br_scalar *pDistance);

void __cdecl DeadStopCar(tCar_spec *pCar_spec);

void __cdecl TurnOpponentPhysicsOn(tOpponent_spec *pOpponent_spec);

void __cdecl TurnOpponentPhysicsOff(tOpponent_spec *pOpponent_spec);

extern void(__cdecl*NewObjective)(tOpponent_spec *, tOpponent_objective_type);
#if 0
void NewObjective_do_not_use(tOpponent_spec *pOpponent_spec, tOpponent_objective_type pObjective_type);
#endif

void __cdecl CalcRaceRoute(tOpponent_spec *pOpponent_spec);

void __cdecl TopUpRandomRoute(tOpponent_spec *pOpponent_spec, int pSections_to_add);

int __cdecl SearchForSection(tRoute_section *pTemp_store, tRoute_section *pPerm_store, int *pNum_of_perm_store_sections, tS16 pTarget_section, int pDepth, br_scalar pDistance_so_far, tOpponent_spec *pOpponent_spec);

void __cdecl CalcGetNearPlayerRoute(tOpponent_spec *pOpponent_spec, tCar_spec *pPlayer);

void __cdecl CalcReturnToStartPointRoute(tOpponent_spec *pOpponent_spec);

void __cdecl ClearOpponentsProjectedRoute(tOpponent_spec *pOpponent_spec);

int __cdecl AddToOpponentsProjectedRoute(tOpponent_spec *pOpponent_spec, tS16 pSection_no, int pDirection);

int __cdecl ShiftOpponentsProjectedRoute(tOpponent_spec *pOpponent_spec, int pPlaces);

void __cdecl StunTheBugger(tOpponent_spec *pOpponent_spec, int pMilliseconds);

void __cdecl UnStunTheBugger(tOpponent_spec *pOpponent_spec);

void __cdecl ProcessCompleteRace(tOpponent_spec *pOpponent_spec, tProcess_objective_command pCommand);

void __cdecl StartRecordingTrail(tCar_spec *pPursuee);

void __cdecl RecordNextTrailNode(tCar_spec *pPursuee);

tS16 __cdecl FindNearestTrailSection(tOpponent_spec *pOpponent_spec, tCar_spec *pPursuee, br_vector3 *pSection_v, br_vector3 *pIntersect, br_scalar *pDistance);

tS16 __cdecl CalcNextTrailSection(tOpponent_spec *pOpponent_spec, int pSection);

void __cdecl ProcessPursueAndTwat(tOpponent_spec *pOpponent_spec, tProcess_objective_command pCommand);

void __cdecl ProcessRunAway(tOpponent_spec *pOpponent_spec, tProcess_objective_command pCommand);

void __cdecl ProcessWaitForSomeHaplessSod(tOpponent_spec *pOpponent_spec, tProcess_objective_command pCommand);

void __cdecl ProcessReturnToStart(tOpponent_spec *pOpponent_spec, tProcess_objective_command pCommand);

void __cdecl ProcessLevitate(tOpponent_spec *pOpponent_spec, tProcess_objective_command pCommand);

void __cdecl ProcessGetNearPlayer(tOpponent_spec *pOpponent_spec, tProcess_objective_command pCommand);

void __cdecl ProcessFrozen(tOpponent_spec *pOpponent_spec, tProcess_objective_command pCommand);

int __cdecl HeadOnWithPlayerPossible(tOpponent_spec *pOpponent_spec);

int __cdecl AlreadyPursuingCar(tOpponent_spec *pOpponent_spec, tCar_spec *pPursuee);

int __cdecl LastTwatteeAPlayer(tOpponent_spec *pOpponent_spec);

int __cdecl LastTwatterAPlayer(tOpponent_spec *pOpponent_spec);

void __cdecl ObjectiveComplete(tOpponent_spec *pOpponent_spec);

void __cdecl TeleportOpponentToNearestSafeLocation(tOpponent_spec *pOpponent_spec);

void __cdecl ChooseNewObjective(tOpponent_spec *pOpponent_spec, int pMust_choose_one);

void ProcessThisOpponent(tOpponent_spec *pOpponent_spec);

int __cdecl IsNetCarActive(br_vector3 *pPoint);

void __cdecl RebuildActiveCarList();

void __cdecl ForceRebuildActiveCarList();

void __cdecl StartToCheat(tOpponent_spec *pOpponent_spec);

void __cdecl OiStopCheating(tOpponent_spec *pOpponent_spec);

int __cdecl TeleportCopToStart(tOpponent_spec *pOpponent_spec);

void __cdecl CalcDistanceFromHome(tOpponent_spec *pOpponent_spec);

int __cdecl MassageOpponentPosition(tOpponent_spec *pOpponent_spec, int pMassage_count);

int __cdecl RematerialiseOpponentOnThisSection(tOpponent_spec *pOpponent_spec, br_scalar pSpeed, tS16 pSection_no);

int __cdecl RematerialiseOpponentOnNearestSection(tOpponent_spec *pOpponent_spec, br_scalar pSpeed);

int __cdecl RematerialiseOpponent(tOpponent_spec *pOpponent_spec, br_scalar pSpeed);

void __cdecl CalcPlayerConspicuousness(tOpponent_spec *pOpponent_spec);

void __cdecl CalcOpponentConspicuousnessWithAViewToCheatingLikeFuck(tOpponent_spec *pOpponent_spec);

void __cdecl ChallengeOccurred(int pChallenger_index, int pAccepted);

void __cdecl LoadCopCars();

void __cdecl LoadInOppoPaths(FILE *pF);

void __cdecl DisposeOpponentPaths();

void __cdecl MungeOpponents(tU32 pFrame_period);

void __cdecl SetInitialCopPositions();

void __cdecl InitOpponents(tRace_info *pRace_info);

void __cdecl DisposeOpponents();

void __cdecl WakeUpOpponentsToTheFactThatTheStartHasBeenJumped(int pWhat_the_countdown_was);

void __cdecl ReportMurderToPoliceDepartment(tCar_spec *pCar_spec);

int __cdecl GetCarCount(tVehicle_type pCategory);

tCar_spec* __cdecl GetCarSpec(tVehicle_type pCategory, int pIndex);

char* __cdecl GetDriverName(tVehicle_type pCategory, int pIndex);

tOpponent_spec* __cdecl GetOpponentSpecFromCarSpec(tCar_spec *pCar_spec);

tCar_spec* __cdecl GetCarSpecFromGlobalOppoIndex(int pIndex);

int __cdecl GetOpponentsRealSection(tOpponent_spec *pOpponent_spec, int pSection_no);

int __cdecl GetOpponentsFirstSection(tOpponent_spec *pOpponent_spec);

int __cdecl GetOpponentsNextSection(tOpponent_spec *pOpponent_spec, tS16 pCurrent_section);

tS16 __cdecl GetOpponentsSectionStartNode(tOpponent_spec *pOpponent_spec, tS16 pSection);

tS16 __cdecl GetOpponentsSectionFinishNode(tOpponent_spec *pOpponent_spec, tS16 pSection);

br_vector3* __cdecl GetOpponentsSectionStartNodePoint(tOpponent_spec *pOpponent_spec, tS16 pSection);

br_vector3* __cdecl GetOpponentsSectionFinishNodePoint(tOpponent_spec *pOpponent_spec, tS16 pSection);

br_scalar __cdecl GetOpponentsSectionWidth(tOpponent_spec *pOpponent_spec, tS16 pSection);

int __cdecl GetOpponentsSectionMinSpeed(tOpponent_spec *pOpponent_spec, tS16 pSection, int pTowards_finish);

int __cdecl GetOpponentsSectionMaxSpeed(tOpponent_spec *pOpponent_spec, tS16 pSection, int pTowards_finish);

void __cdecl InitOpponentPsyche(int pOpponent_index);

void __cdecl ClearTwattageOccurrenceVariables(tOpponent_spec *pOpponent_spec);

void __cdecl TwoCarsHitEachOther(tCar_spec *pA_car, tCar_spec *pAnother_car);

void __cdecl RecordOpponentTwattageOccurrence(tCar_spec *pTwatter, tCar_spec *pTwattee);

void __cdecl ToggleOpponentTest();

void __cdecl ToggleOpponentProcessing();

void __cdecl ToggleMellowOpponents();

void __cdecl RepairOpponentsSystems();

void __cdecl CopyVertex__opponent(br_vertex *pDest_vertex, br_vertex *pSrc_vertex);

void __cdecl CopyFace__opponent(br_face *pDest_face, br_face *pSrc_face);

void __cdecl DeleteSection(tS16 pSection_to_delete);

void __cdecl DeleteNode(tS16 pNode_to_delete, int pAnd_sections);

void __cdecl DeleteOrphanNodes();

void __cdecl InsertThisNodeInThisSectionHere(tS16 pInserted_node, tS16 pSection_no, br_vector3 *pWhere);

void __cdecl TrackElasticateyPath();

void __cdecl RecalcNearestPathSectionSpeed(int pMax_not_min, int pAdjustment);

void __cdecl RecalcNearestPathSectionWidth(br_scalar pAdjustment);

void __cdecl CalcNegativeXVector(br_vector3 *pNegative_x_vector, br_vector3 *pStart, br_vector3 *pFinish, br_scalar pLength);

void __cdecl MakeVertexAndOffsetIt(br_model *pModel, int pVertex_num, br_scalar pX, br_scalar pY, br_scalar pZ, br_vector3 *pOffset);

void __cdecl MakeFaceAndTextureIt(br_model *pModel, int pFace_num, int pV0, int pV1, int pV2, br_material *pMaterial);

void __cdecl MakeSection(br_uint_16 pFirst_vertex, br_uint_16 pFirst_face, br_vector3 *pStart, br_vector3 *pFinish, br_scalar pWidth, br_material *pMaterial_centre_lt, br_material *pMaterial_centre_dk, br_material *pMaterial_edges_start_lt, br_material *pMaterial_edges_start_dk, br_material *pMaterial_edges_finish_lt, br_material *pMaterial_edges_finish_dk);

void __cdecl MakeCube(br_uint_16 pFirst_vertex, br_uint_16 pFirst_face, br_vector3 *pPoint, br_material *pMaterial_1, br_material *pMaterial_2, br_material *pMaterial_3);

void __cdecl CalcNumberOfFacesAndVerticesForOppoPathModel(br_uint_16 *pFace_index_ptr, br_uint_16 *pVertex_index_ptr);

void __cdecl ReallocModelFacesAndVertices(br_model *pModel, int pNum_faces, int pNum_vertices);

br_material* __cdecl CreateSimpleMaterial(int pColour_index);

void __cdecl AllocateMatsForOppoPathModel();

void __cdecl RebuildOppoPathModel();

int __cdecl ConsistencyCheck();

void __cdecl ShowOppoPaths();

void __cdecl WriteOutOppoPaths();

int __cdecl NewNodeOKHere();

void __cdecl ShowHideOppoPaths();

void DropElasticateyNode();

void InsertAndElasticate();

void InsertAndDontElasticate();

void DropDeadEndNode();

void DropNodeOnNodeAndStopElasticating();

void __cdecl WidenOppoPathSection();

void __cdecl NarrowOppoPathSection();

void __cdecl IncreaseSectionMinSpeed();

void __cdecl DecreaseSectionMinSpeed();

void __fastcall IncreaseSectionMaxSpeed();

void __fastcall DecreaseSectionMaxSpeed();

void __cdecl PullOppoPoint();

void __cdecl ShowNodeInfo();

void __fastcall ShowSectionInfo1();

void __fastcall ShowSectionInfo2();

void DeleteOppoPathSection();

void __fastcall DeleteOppoPathNodeAndSections();

void __cdecl DeleteOppoPathNodeAndJoin();

void __fastcall ReverseSectionDirection();

void __fastcall CycleSectionType();

void __fastcall ToggleOneWayNess();

void __fastcall CopStartPointInfo();

void __cdecl DropCopStartPoint();

void __fastcall DeleteCopStartPoint();

void __cdecl CycleCopStartPointType();

#endif
