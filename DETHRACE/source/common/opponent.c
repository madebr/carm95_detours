#include "opponent.h"

#include "harness/trace.h"

#include "carm95_hooks.h"

#include <stdio.h>
br_actor ** hookvar_gOppo_path_actor  = (void*)0x005070d0;
br_model ** hookvar_gOppo_path_model  = (void*)0x005070d4;
br_material ** hookvar_gMat_dk_yel  = (void*)0x005070d8;
br_material ** hookvar_gMat_md_yel  = (void*)0x005070dc;
br_material ** hookvar_gMat_lt_yel  = (void*)0x005070e0;
br_material ** hookvar_gMat_dk_red  = (void*)0x005070e4;
br_material ** hookvar_gMat_lt_red  = (void*)0x005070e8;
br_material ** hookvar_gMat_dk_grn  = (void*)0x005070ec;
br_material ** hookvar_gMat_lt_grn  = (void*)0x005070f0;
br_material ** hookvar_gMat_dk_blu  = (void*)0x005070f4;
br_material ** hookvar_gMat_lt_blu  = (void*)0x005070f8;
br_material ** hookvar_gMat_dk_turq  = (void*)0x005070fc;
br_material ** hookvar_gMat_lt_turq  = (void*)0x00507100;
br_material ** hookvar_gMat_dk_gry  = (void*)0x00507104;
br_material ** hookvar_gMat_md_gry  = (void*)0x00507108;
br_material ** hookvar_gMat_lt_gry  = (void*)0x0050710c;
int * hookvar_gMellow_opponents  = (void*)0x00507110;
int * hookvar_gTest_toggle  = (void*)0x00507114;
int * hookvar_gAlready_elasticating  = (void*)0x00507118;
#if 0
int * hookvar_gVertices_used_in_non_edit_paths ;
#endif
#if 0
int * hookvar_gFaces_used_in_non_edit_paths ;
#endif
int * hookvar_gMats_allocated  = (void*)0x00507124;
int * hookvar_gOppo_paths_shown  = (void*)0x00507128;
int * hookvar_gMade_path_filename  = (void*)0x0050712c;
int * hookvar_gBIG_APC_index  = (void*)0x00507130;
char *(* hookvar_gPath_section_type_names )[3] = (void*)0x00507138;
int * hookvar_gMin_bangness  = (void*)0x00507144;
int * hookvar_gMax_bangness  = (void*)0x00507148;
tU32 * hookvar_gNext_elastication  = (void*)0x0050714c;
tU32 * hookvar_gNext_write_during_elastication  = (void*)0x00507150;
char ** hookvar_gCop_name  = (void*)0x00507154;
char ** hookvar_gDrone_name  = (void*)0x00507158;
 // Suffix added to avoid duplicate symbol
int * hookvar_gChallenger_index__opponent  = (void*)0x0050715c;
int * hookvar_gSFS_count  = (void*)0x00507160;
int * hookvar_gSFS_total_cycles  = (void*)0x00507164;
int * hookvar_gSFS_max_cycles  = (void*)0x00507168;
float * hookvar_gOpponent_nastyness_frigger  = (void*)0x0050716c;
char(* hookvar_gOppo_path_filename )[256] = (void*)0x00530ca8;
br_scalar * hookvar_gIn_view_distance  = (void*)0x00530df0;
tU8 ** hookvar_gBit_per_node  = (void*)0x00530de8;
int * hookvar_gGrudge_reduction_per_period  = (void*)0x00530da8;
int * hookvar_gSFS_cycles_this_time  = (void*)0x00530df8;
br_scalar * hookvar_gMinimum_yness_before_knackerisation  = (void*)0x00530dec;
#if 0
int * hookvar_gWanky_arse_tit_fuck ;
#endif
br_scalar * hookvar_gHead_on_cos_value  = (void*)0x00530df4;
tU32 * hookvar_gNext_grudge_reduction  = (void*)0x00530de0;
br_scalar * hookvar_gCop_pursuit_speed_percentage_multiplier  = (void*)0x00530dd0;
br_scalar * hookvar_gDefinite_cop_pursuit_speed  = (void*)0x00530dbc;
int * hookvar_gAcknowledged_start  = (void*)0x00530dd8;
int * hookvar_gStart_jumped  = (void*)0x00530ca0;
int * hookvar_gNum_of_opponents_getting_near  = (void*)0x00530dc8;
#if 0
int * hookvar_gNumber_of_cops_before_faffage ;
#endif
int * hookvar_gFirst_frame  = (void*)0x00530dc0;
tU32 * hookvar_gAcme_frame_count  = (void*)0x00530dac;
br_scalar * hookvar_gDefinite_no_cop_pursuit_speed  = (void*)0x00530db8;
int * hookvar_gNum_of_opponents_completing_race  = (void*)0x00530de4;
int * hookvar_gNum_of_opponents_pursuing  = (void*)0x00530c98;
int * hookvar_gActive_car_list_rebuild_required  = (void*)0x00530dc4;
br_scalar * hookvar_gFrame_period_for_this_munging_in_secs  = (void*)0x00530db4;
int * hookvar_gBig_bang  = (void*)0x00530c94;
#if 0
int * hookvar_gProcessing_opponents ;
#endif
tU32 * hookvar_gFrame_period_for_this_munging  = (void*)0x005520e0;
tU32 * hookvar_gTime_stamp_for_this_munging  = (void*)0x005520e4;
tS16 * hookvar_gMobile_section  = (void*)0x00530c90;

static void(*original_PointActorAlongThisBloodyVector)(br_actor *, br_vector3 *, ...) = (void(*)(br_actor *, br_vector3 *, ...))0x00402390;
CARM95_HOOK_FUNCTION(original_PointActorAlongThisBloodyVector, PointActorAlongThisBloodyVector)
void PointActorAlongThisBloodyVector(br_actor *pThe_actor, br_vector3 *pThe_vector) {
    br_transform trans;
    LOG_TRACE("(%p, %p)", pThe_actor, pThe_vector);

    (void)pThe_actor;
    (void)pThe_vector;
    (void)trans;

    original_PointActorAlongThisBloodyVector(pThe_actor, pThe_vector);
}

static void(*original_ProcessCurrentObjective)(tOpponent_spec *, tProcess_objective_command, ...) = (void(*)(tOpponent_spec *, tProcess_objective_command, ...))0x004065e0;
CARM95_HOOK_FUNCTION(original_ProcessCurrentObjective, ProcessCurrentObjective)
void ProcessCurrentObjective(tOpponent_spec *pOpponent_spec, tProcess_objective_command pCommand) {
    LOG_TRACE("(%p, %d)", pOpponent_spec, pCommand);

    (void)pOpponent_spec;
    (void)pCommand;

    original_ProcessCurrentObjective(pOpponent_spec, pCommand);
}

static tS16(*original_ReallocExtraPathNodes)(int, ...) = (tS16(*)(int, ...))0x004057a1;
CARM95_HOOK_FUNCTION(original_ReallocExtraPathNodes, ReallocExtraPathNodes)
tS16 ReallocExtraPathNodes(int pHow_many_then) {
    tPath_node *new_nodes;
    tS16 first_new_node;
    LOG_TRACE("(%d)", pHow_many_then);

    (void)pHow_many_then;
    (void)new_nodes;
    (void)first_new_node;

    return original_ReallocExtraPathNodes(pHow_many_then);
}

static tS16(*original_ReallocExtraPathSections)(int, ...) = (tS16(*)(int, ...))0x00405855;
CARM95_HOOK_FUNCTION(original_ReallocExtraPathSections, ReallocExtraPathSections)
tS16 ReallocExtraPathSections(int pHow_many_then) {
    tPath_section *new_sections;
    tS16 first_new_section;
    LOG_TRACE("(%d)", pHow_many_then);

    (void)pHow_many_then;
    (void)new_sections;
    (void)first_new_section;

    return original_ReallocExtraPathSections(pHow_many_then);
}

static int(*original_PointVisibleFromHere)(br_vector3 *, br_vector3 *, ...) = (int(*)(br_vector3 *, br_vector3 *, ...))0x004063ac;
CARM95_HOOK_FUNCTION(original_PointVisibleFromHere, PointVisibleFromHere)
int PointVisibleFromHere(br_vector3 *pFrom, br_vector3 *pTo) {
    br_vector3 from;
    br_vector3 dir;
    br_vector3 norm;
    br_scalar t;
    br_material *material;
    LOG_TRACE("(%p, %p)", pFrom, pTo);

    (void)pFrom;
    (void)pTo;
    (void)from;
    (void)dir;
    (void)norm;
    (void)t;
    (void)material;

    return original_PointVisibleFromHere(pFrom, pTo);
}

static tS16(*original_FindNearestPathNode)(br_vector3 *, br_scalar *, ...) = (tS16(*)(br_vector3 *, br_scalar *, ...))0x0040f331;
CARM95_HOOK_FUNCTION(original_FindNearestPathNode, FindNearestPathNode)
tS16 FindNearestPathNode(br_vector3 *pActor_coords, br_scalar *pDistance) {
    int i;
    tS16 nearest_node;
    br_scalar distance;
    br_vector3 actor_to_node;
    LOG_TRACE("(%p, %p)", pActor_coords, pDistance);

    (void)pActor_coords;
    (void)pDistance;
    (void)i;
    (void)nearest_node;
    (void)distance;
    (void)actor_to_node;

    return original_FindNearestPathNode(pActor_coords, pDistance);
}

static tS16(*original_FindNearestPathSection)(br_vector3 *, br_vector3 *, br_vector3 *, br_scalar *, ...) = (tS16(*)(br_vector3 *, br_vector3 *, br_vector3 *, br_scalar *, ...))0x0040294b;
CARM95_HOOK_FUNCTION(original_FindNearestPathSection, FindNearestPathSection)
tS16 FindNearestPathSection(br_vector3 *pActor_coords, br_vector3 *pPath_direction, br_vector3 *pIntersect, br_scalar *pDistance) {
    LOG_TRACE("(%p, %p, %p, %p)", pActor_coords, pPath_direction, pIntersect, pDistance);

    (void)pActor_coords;
    (void)pPath_direction;
    (void)pIntersect;
    (void)pDistance;

    return original_FindNearestPathSection(pActor_coords, pPath_direction, pIntersect, pDistance);
}

static tS16(*original_FindNearestGeneralSection)(tCar_spec *, br_vector3 *, br_vector3 *, br_vector3 *, br_scalar *, ...) = (tS16(*)(tCar_spec *, br_vector3 *, br_vector3 *, br_vector3 *, br_scalar *, ...))0x00402975;
CARM95_HOOK_FUNCTION(original_FindNearestGeneralSection, FindNearestGeneralSection)
tS16 FindNearestGeneralSection(tCar_spec *pPursuee, br_vector3 *pActor_coords, br_vector3 *pPath_direction, br_vector3 *pIntersect, br_scalar *pDistance) {
    int section_no;
    int no_sections;
    tS16 nearest_node_section_no;
    tS16 nearest_section;
    br_scalar nearest_node_distance_squared;
    br_scalar closest_distance_squared;
    br_scalar the_distance_squared;
    br_scalar t;
    br_scalar length_squared_a;
    br_vector3 a;
    br_vector3 p;
    br_vector3 wank;
    br_vector3 intersect;
    br_vector3 *start;
    br_vector3 *finish;
    br_vector3 *nearest_node_v;
    br_scalar __block0___scale;
    br_scalar __block1___scale;
    LOG_TRACE("(%p, %p, %p, %p, %p)", pPursuee, pActor_coords, pPath_direction, pIntersect, pDistance);

    (void)pPursuee;
    (void)pActor_coords;
    (void)pPath_direction;
    (void)pIntersect;
    (void)pDistance;
    (void)section_no;
    (void)no_sections;
    (void)nearest_node_section_no;
    (void)nearest_section;
    (void)nearest_node_distance_squared;
    (void)closest_distance_squared;
    (void)the_distance_squared;
    (void)t;
    (void)length_squared_a;
    (void)a;
    (void)p;
    (void)wank;
    (void)intersect;
    (void)start;
    (void)finish;
    (void)nearest_node_v;

    return original_FindNearestGeneralSection(pPursuee, pActor_coords, pPath_direction, pIntersect, pDistance);
}

static void(*original_DeadStopCar)(tCar_spec *, ...) = (void(*)(tCar_spec *, ...))0x00402481;
CARM95_HOOK_FUNCTION(original_DeadStopCar, DeadStopCar)
void DeadStopCar(tCar_spec *pCar_spec) {
    LOG_TRACE("(%p)", pCar_spec);

    (void)pCar_spec;

    original_DeadStopCar(pCar_spec);
}

static void(*original_TurnOpponentPhysicsOn)(tOpponent_spec *, ...) = (void(*)(tOpponent_spec *, ...))0x00402401;
CARM95_HOOK_FUNCTION(original_TurnOpponentPhysicsOn, TurnOpponentPhysicsOn)
void TurnOpponentPhysicsOn(tOpponent_spec *pOpponent_spec) {
    LOG_TRACE("(%p)", pOpponent_spec);

    (void)pOpponent_spec;

    original_TurnOpponentPhysicsOn(pOpponent_spec);
}

static void(*original_TurnOpponentPhysicsOff)(tOpponent_spec *, ...) = (void(*)(tOpponent_spec *, ...))0x0040243f;
CARM95_HOOK_FUNCTION(original_TurnOpponentPhysicsOff, TurnOpponentPhysicsOff)
void TurnOpponentPhysicsOff(tOpponent_spec *pOpponent_spec) {
    LOG_TRACE("(%p)", pOpponent_spec);

    (void)pOpponent_spec;

    original_TurnOpponentPhysicsOff(pOpponent_spec);
}

void NewObjective_do_not_use(tOpponent_spec *pOpponent_spec, tOpponent_objective_type pObjective_type) {
    va_list marker;
    LOG_TRACE("(%p, %d)", pOpponent_spec, pObjective_type);

    (void)pOpponent_spec;
    (void)pObjective_type;
    (void)marker;

    NOT_IMPLEMENTED();
}

static void(*original_CalcRaceRoute)(tOpponent_spec *, ...) = (void(*)(tOpponent_spec *, ...))0x00402512;
CARM95_HOOK_FUNCTION(original_CalcRaceRoute, CalcRaceRoute)
void CalcRaceRoute(tOpponent_spec *pOpponent_spec) {
    tS16 section_no;
    tS16 section_no_index;
    tS16 node_no;
    tS16 race_section_count;
    tS16 normal_section_ok_direction_count;
    tS16 normal_section_wrong_direction_count;
    tS16 temp_section_array[8];
    br_scalar distance;
    br_vector3 direction_v;
    br_vector3 intersect;
    char str[256];
    char work_str[32];
    int i;
    LOG_TRACE("(%p)", pOpponent_spec);

    (void)pOpponent_spec;
    (void)section_no;
    (void)section_no_index;
    (void)node_no;
    (void)race_section_count;
    (void)normal_section_ok_direction_count;
    (void)normal_section_wrong_direction_count;
    (void)temp_section_array;
    (void)distance;
    (void)direction_v;
    (void)intersect;
    (void)str;
    (void)work_str;
    (void)i;

    original_CalcRaceRoute(pOpponent_spec);
}

static void(*original_TopUpRandomRoute)(tOpponent_spec *, int, ...) = (void(*)(tOpponent_spec *, int, ...))0x00402e11;
CARM95_HOOK_FUNCTION(original_TopUpRandomRoute, TopUpRandomRoute)
void TopUpRandomRoute(tOpponent_spec *pOpponent_spec, int pSections_to_add) {
    tS16 section_no;
    tS16 node_no;
    tS16 temp_section_array[8];
    int i;
    int target;
    int num_of_temp_sections;
    int direction;
    LOG_TRACE("(%p, %d)", pOpponent_spec, pSections_to_add);

    (void)pOpponent_spec;
    (void)pSections_to_add;
    (void)section_no;
    (void)node_no;
    (void)temp_section_array;
    (void)i;
    (void)target;
    (void)num_of_temp_sections;
    (void)direction;

    original_TopUpRandomRoute(pOpponent_spec, pSections_to_add);
}

static int(*original_SearchForSection)(tRoute_section *, tRoute_section *, int *, tS16, int, br_scalar, tOpponent_spec *, ...) = (int(*)(tRoute_section *, tRoute_section *, int *, tS16, int, br_scalar, tOpponent_spec *, ...))0x00407f5d;
CARM95_HOOK_FUNCTION(original_SearchForSection, SearchForSection)
int SearchForSection(tRoute_section *pTemp_store, tRoute_section *pPerm_store, int *pNum_of_perm_store_sections, tS16 pTarget_section, int pDepth, br_scalar pDistance_so_far, tOpponent_spec *pOpponent_spec) {
    static br_scalar shortest_dist;
    static int routes_found;
    char depth_indent[32];
    int direction;
    tPath_node *node_ptr;
    tS16 node_no;
    tS16 section_no;
    tS16 section_no_index;
    br_scalar distance_so_far;
    LOG_TRACE("(%p, %p, %p, %d, %d, %f, %p)", pTemp_store, pPerm_store, pNum_of_perm_store_sections, pTarget_section, pDepth, pDistance_so_far, pOpponent_spec);

    (void)pTemp_store;
    (void)pPerm_store;
    (void)pNum_of_perm_store_sections;
    (void)pTarget_section;
    (void)pDepth;
    (void)pDistance_so_far;
    (void)pOpponent_spec;
    (void)shortest_dist;
    (void)routes_found;
    (void)depth_indent;
    (void)direction;
    (void)node_ptr;
    (void)node_no;
    (void)section_no;
    (void)section_no_index;
    (void)distance_so_far;

    return original_SearchForSection(pTemp_store, pPerm_store, pNum_of_perm_store_sections, pTarget_section, pDepth, pDistance_so_far, pOpponent_spec);
}

static void(*original_CalcGetNearPlayerRoute)(tOpponent_spec *, tCar_spec *, ...) = (void(*)(tOpponent_spec *, tCar_spec *, ...))0x004089bf;
CARM95_HOOK_FUNCTION(original_CalcGetNearPlayerRoute, CalcGetNearPlayerRoute)
void CalcGetNearPlayerRoute(tOpponent_spec *pOpponent_spec, tCar_spec *pPlayer) {
    int i;
    int pass_2_depth;
    int sections_away;
    int num_of_perm_store_sections;
    int sections_to_copy;
    int fuck_it;
    tS16 section_no;
    tS16 players_section;
    br_vector3 section_v;
    br_vector3 intersect;
    br_scalar distance;
    tRoute_section temp_store[10];
    tRoute_section perm_store[10];
    char work_str[32];
    char str[256];
    LOG_TRACE("(%p, %p)", pOpponent_spec, pPlayer);

    (void)pOpponent_spec;
    (void)pPlayer;
    (void)i;
    (void)pass_2_depth;
    (void)sections_away;
    (void)num_of_perm_store_sections;
    (void)sections_to_copy;
    (void)fuck_it;
    (void)section_no;
    (void)players_section;
    (void)section_v;
    (void)intersect;
    (void)distance;
    (void)temp_store;
    (void)perm_store;
    (void)work_str;
    (void)str;

    original_CalcGetNearPlayerRoute(pOpponent_spec, pPlayer);
}

static void(*original_CalcReturnToStartPointRoute)(tOpponent_spec *, ...) = (void(*)(tOpponent_spec *, ...))0x00407d1e;
CARM95_HOOK_FUNCTION(original_CalcReturnToStartPointRoute, CalcReturnToStartPointRoute)
void CalcReturnToStartPointRoute(tOpponent_spec *pOpponent_spec) {
    int i;
    int pass_2_depth;
    int sections_away;
    int num_of_perm_store_sections;
    int sections_to_copy;
    tS16 section_no;
    br_vector3 intersect;
    br_vector3 section_v;
    br_scalar distance;
    tRoute_section temp_store[10];
    tRoute_section perm_store[10];
    br_scalar __block0___scale;
    LOG_TRACE("(%p)", pOpponent_spec);

    (void)pOpponent_spec;
    (void)i;
    (void)pass_2_depth;
    (void)sections_away;
    (void)num_of_perm_store_sections;
    (void)sections_to_copy;
    (void)section_no;
    (void)intersect;
    (void)section_v;
    (void)distance;
    (void)temp_store;
    (void)perm_store;

    original_CalcReturnToStartPointRoute(pOpponent_spec);
}

static void(*original_ClearOpponentsProjectedRoute)(tOpponent_spec *, ...) = (void(*)(tOpponent_spec *, ...))0x00404684;
CARM95_HOOK_FUNCTION(original_ClearOpponentsProjectedRoute, ClearOpponentsProjectedRoute)
void ClearOpponentsProjectedRoute(tOpponent_spec *pOpponent_spec) {
    LOG_TRACE("(%p)", pOpponent_spec);

    (void)pOpponent_spec;

    original_ClearOpponentsProjectedRoute(pOpponent_spec);
}

static int(*original_AddToOpponentsProjectedRoute)(tOpponent_spec *, tS16, int, ...) = (int(*)(tOpponent_spec *, tS16, int, ...))0x004030ef;
CARM95_HOOK_FUNCTION(original_AddToOpponentsProjectedRoute, AddToOpponentsProjectedRoute)
int AddToOpponentsProjectedRoute(tOpponent_spec *pOpponent_spec, tS16 pSection_no, int pDirection) {
    LOG_TRACE("(%p, %d, %d)", pOpponent_spec, pSection_no, pDirection);

    (void)pOpponent_spec;
    (void)pSection_no;
    (void)pDirection;

    return original_AddToOpponentsProjectedRoute(pOpponent_spec, pSection_no, pDirection);
}

static int(*original_ShiftOpponentsProjectedRoute)(tOpponent_spec *, int, ...) = (int(*)(tOpponent_spec *, int, ...))0x00404699;
CARM95_HOOK_FUNCTION(original_ShiftOpponentsProjectedRoute, ShiftOpponentsProjectedRoute)
int ShiftOpponentsProjectedRoute(tOpponent_spec *pOpponent_spec, int pPlaces) {
    int i;
    LOG_TRACE("(%p, %d)", pOpponent_spec, pPlaces);

    (void)pOpponent_spec;
    (void)pPlaces;
    (void)i;

    return original_ShiftOpponentsProjectedRoute(pOpponent_spec, pPlaces);
}

static void(*original_StunTheBugger)(tOpponent_spec *, int, ...) = (void(*)(tOpponent_spec *, int, ...))0x0040b12d;
CARM95_HOOK_FUNCTION(original_StunTheBugger, StunTheBugger)
void StunTheBugger(tOpponent_spec *pOpponent_spec, int pMilliseconds) {
    LOG_TRACE("(%p, %d)", pOpponent_spec, pMilliseconds);

    (void)pOpponent_spec;
    (void)pMilliseconds;

    original_StunTheBugger(pOpponent_spec, pMilliseconds);
}

static void(*original_UnStunTheBugger)(tOpponent_spec *, ...) = (void(*)(tOpponent_spec *, ...))0x00405e44;
CARM95_HOOK_FUNCTION(original_UnStunTheBugger, UnStunTheBugger)
void UnStunTheBugger(tOpponent_spec *pOpponent_spec) {
    LOG_TRACE("(%p)", pOpponent_spec);

    (void)pOpponent_spec;

    original_UnStunTheBugger(pOpponent_spec);
}

static void(*original_ProcessCompleteRace)(tOpponent_spec *, tProcess_objective_command, ...) = (void(*)(tOpponent_spec *, tProcess_objective_command, ...))0x00406732;
CARM95_HOOK_FUNCTION(original_ProcessCompleteRace, ProcessCompleteRace)
void ProcessCompleteRace(tOpponent_spec *pOpponent_spec, tProcess_objective_command pCommand) {
    br_vector3 *initial_pos;
    br_actor *car_actor;
    tComplete_race_data *data;
    int res;
    char str[256];
    LOG_TRACE("(%p, %d)", pOpponent_spec, pCommand);

    (void)pOpponent_spec;
    (void)pCommand;
    (void)initial_pos;
    (void)car_actor;
    (void)data;
    (void)res;
    (void)str;

    original_ProcessCompleteRace(pOpponent_spec, pCommand);
}

static void(*original_StartRecordingTrail)(tCar_spec *, ...) = (void(*)(tCar_spec *, ...))0x00405e59;
CARM95_HOOK_FUNCTION(original_StartRecordingTrail, StartRecordingTrail)
void StartRecordingTrail(tCar_spec *pPursuee) {
    int i;
    LOG_TRACE("(%p)", pPursuee);

    (void)pPursuee;
    (void)i;

    original_StartRecordingTrail(pPursuee);
}

static void(*original_RecordNextTrailNode)(tCar_spec *, ...) = (void(*)(tCar_spec *, ...))0x00405f97;
CARM95_HOOK_FUNCTION(original_RecordNextTrailNode, RecordNextTrailNode)
void RecordNextTrailNode(tCar_spec *pPursuee) {
    tPursuee_trail *trail;
    br_vector3 start1;
    br_vector3 finish1;
    br_vector3 start2;
    br_vector3 finish2;
    br_vector3 offset_v;
    br_vector3 car_to_last_point_v;
    br_scalar length;
    int visible;
    LOG_TRACE("(%p)", pPursuee);

    (void)pPursuee;
    (void)trail;
    (void)start1;
    (void)finish1;
    (void)start2;
    (void)finish2;
    (void)offset_v;
    (void)car_to_last_point_v;
    (void)length;
    (void)visible;

    original_RecordNextTrailNode(pPursuee);
}

static tS16(*original_FindNearestTrailSection)(tOpponent_spec *, tCar_spec *, br_vector3 *, br_vector3 *, br_scalar *, ...) = (tS16(*)(tOpponent_spec *, tCar_spec *, br_vector3 *, br_vector3 *, br_scalar *, ...))0x0040769d;
CARM95_HOOK_FUNCTION(original_FindNearestTrailSection, FindNearestTrailSection)
tS16 FindNearestTrailSection(tOpponent_spec *pOpponent_spec, tCar_spec *pPursuee, br_vector3 *pSection_v, br_vector3 *pIntersect, br_scalar *pDistance) {
    LOG_TRACE("(%p, %p, %p, %p, %p)", pOpponent_spec, pPursuee, pSection_v, pIntersect, pDistance);

    (void)pOpponent_spec;
    (void)pPursuee;
    (void)pSection_v;
    (void)pIntersect;
    (void)pDistance;

    return original_FindNearestTrailSection(pOpponent_spec, pPursuee, pSection_v, pIntersect, pDistance);
}

static tS16(*original_CalcNextTrailSection)(tOpponent_spec *, int, ...) = (tS16(*)(tOpponent_spec *, int, ...))0x00403145;
CARM95_HOOK_FUNCTION(original_CalcNextTrailSection, CalcNextTrailSection)
tS16 CalcNextTrailSection(tOpponent_spec *pOpponent_spec, int pSection) {
    int section_no;
    tPursuee_trail *trail;
    LOG_TRACE("(%p, %d)", pOpponent_spec, pSection);

    (void)pOpponent_spec;
    (void)pSection;
    (void)section_no;
    (void)trail;

    return original_CalcNextTrailSection(pOpponent_spec, pSection);
}

static void(*original_ProcessPursueAndTwat)(tOpponent_spec *, tProcess_objective_command, ...) = (void(*)(tOpponent_spec *, tProcess_objective_command, ...))0x00406a69;
CARM95_HOOK_FUNCTION(original_ProcessPursueAndTwat, ProcessPursueAndTwat)
void ProcessPursueAndTwat(tOpponent_spec *pOpponent_spec, tProcess_objective_command pCommand) {
    tPursue_car_data *data;
    br_vector3 wank;
    br_vector3 section_v;
    br_vector3 intersect;
    br_scalar d;
    br_scalar s;
    br_scalar t;
    br_scalar distance;
    tFollow_path_result res;
    char str[256];
    tS16 section_no;
    LOG_TRACE("(%p, %d)", pOpponent_spec, pCommand);

    (void)pOpponent_spec;
    (void)pCommand;
    (void)data;
    (void)wank;
    (void)section_v;
    (void)intersect;
    (void)d;
    (void)s;
    (void)t;
    (void)distance;
    (void)res;
    (void)str;
    (void)section_no;

    original_ProcessPursueAndTwat(pOpponent_spec, pCommand);
}

static void(*original_ProcessRunAway)(tOpponent_spec *, tProcess_objective_command, ...) = (void(*)(tOpponent_spec *, tProcess_objective_command, ...))0x004076d2;
CARM95_HOOK_FUNCTION(original_ProcessRunAway, ProcessRunAway)
void ProcessRunAway(tOpponent_spec *pOpponent_spec, tProcess_objective_command pCommand) {
    int res;
    tS16 section_no;
    br_scalar distance;
    br_vector3 intersect;
    br_vector3 direction_v;
    char str[256];
    LOG_TRACE("(%p, %d)", pOpponent_spec, pCommand);

    (void)pOpponent_spec;
    (void)pCommand;
    (void)res;
    (void)section_no;
    (void)distance;
    (void)intersect;
    (void)direction_v;
    (void)str;

    original_ProcessRunAway(pOpponent_spec, pCommand);
}

static void(*original_ProcessWaitForSomeHaplessSod)(tOpponent_spec *, tProcess_objective_command, ...) = (void(*)(tOpponent_spec *, tProcess_objective_command, ...))0x004079da;
CARM95_HOOK_FUNCTION(original_ProcessWaitForSomeHaplessSod, ProcessWaitForSomeHaplessSod)
void ProcessWaitForSomeHaplessSod(tOpponent_spec *pOpponent_spec, tProcess_objective_command pCommand) {
    LOG_TRACE("(%p, %d)", pOpponent_spec, pCommand);

    (void)pOpponent_spec;
    (void)pCommand;

    original_ProcessWaitForSomeHaplessSod(pOpponent_spec, pCommand);
}

static void(*original_ProcessReturnToStart)(tOpponent_spec *, tProcess_objective_command, ...) = (void(*)(tOpponent_spec *, tProcess_objective_command, ...))0x00407a66;
CARM95_HOOK_FUNCTION(original_ProcessReturnToStart, ProcessReturnToStart)
void ProcessReturnToStart(tOpponent_spec *pOpponent_spec, tProcess_objective_command pCommand) {
    br_vector3 section_v;
    br_vector3 our_pos_xz;
    br_vector3 cop_to_start;
    br_scalar distance;
    int res;
    LOG_TRACE("(%p, %d)", pOpponent_spec, pCommand);

    (void)pOpponent_spec;
    (void)pCommand;
    (void)section_v;
    (void)our_pos_xz;
    (void)cop_to_start;
    (void)distance;
    (void)res;

    original_ProcessReturnToStart(pOpponent_spec, pCommand);
}

static void(*original_ProcessLevitate)(tOpponent_spec *, tProcess_objective_command, ...) = (void(*)(tOpponent_spec *, tProcess_objective_command, ...))0x00408349;
CARM95_HOOK_FUNCTION(original_ProcessLevitate, ProcessLevitate)
void ProcessLevitate(tOpponent_spec *pOpponent_spec, tProcess_objective_command pCommand) {
    float t;
    float terminal_time;
    float y;
    LOG_TRACE("(%p, %d)", pOpponent_spec, pCommand);

    (void)pOpponent_spec;
    (void)pCommand;
    (void)t;
    (void)terminal_time;
    (void)y;

    original_ProcessLevitate(pOpponent_spec, pCommand);
}

static void(*original_ProcessGetNearPlayer)(tOpponent_spec *, tProcess_objective_command, ...) = (void(*)(tOpponent_spec *, tProcess_objective_command, ...))0x004086fe;
CARM95_HOOK_FUNCTION(original_ProcessGetNearPlayer, ProcessGetNearPlayer)
void ProcessGetNearPlayer(tOpponent_spec *pOpponent_spec, tProcess_objective_command pCommand) {
    br_vector3 *initial_pos;
    br_actor *car_actor;
    int res;
    char str[256];
    LOG_TRACE("(%p, %d)", pOpponent_spec, pCommand);

    (void)pOpponent_spec;
    (void)pCommand;
    (void)initial_pos;
    (void)car_actor;
    (void)res;
    (void)str;

    original_ProcessGetNearPlayer(pOpponent_spec, pCommand);
}

static void(*original_ProcessFrozen)(tOpponent_spec *, tProcess_objective_command, ...) = (void(*)(tOpponent_spec *, tProcess_objective_command, ...))0x00408d47;
CARM95_HOOK_FUNCTION(original_ProcessFrozen, ProcessFrozen)
void ProcessFrozen(tOpponent_spec *pOpponent_spec, tProcess_objective_command pCommand) {
    LOG_TRACE("(%p, %d)", pOpponent_spec, pCommand);

    (void)pOpponent_spec;
    (void)pCommand;

    original_ProcessFrozen(pOpponent_spec, pCommand);
}

static int(*original_HeadOnWithPlayerPossible)(tOpponent_spec *, ...) = (int(*)(tOpponent_spec *, ...))0x00409cd5;
CARM95_HOOK_FUNCTION(original_HeadOnWithPlayerPossible, HeadOnWithPlayerPossible)
int HeadOnWithPlayerPossible(tOpponent_spec *pOpponent_spec) {
    br_vector3 oppo_to_player_norm;
    br_scalar __block0___scale;
    LOG_TRACE("(%p)", pOpponent_spec);

    (void)pOpponent_spec;
    (void)oppo_to_player_norm;

    return original_HeadOnWithPlayerPossible(pOpponent_spec);
}

static int(*original_AlreadyPursuingCar)(tOpponent_spec *, tCar_spec *, ...) = (int(*)(tOpponent_spec *, tCar_spec *, ...))0x00409e29;
CARM95_HOOK_FUNCTION(original_AlreadyPursuingCar, AlreadyPursuingCar)
int AlreadyPursuingCar(tOpponent_spec *pOpponent_spec, tCar_spec *pPursuee) {
    LOG_TRACE("(%p, %p)", pOpponent_spec, pPursuee);

    (void)pOpponent_spec;
    (void)pPursuee;

    return original_AlreadyPursuingCar(pOpponent_spec, pPursuee);
}

static int(*original_LastTwatteeAPlayer)(tOpponent_spec *, ...) = (int(*)(tOpponent_spec *, ...))0x00409e64;
CARM95_HOOK_FUNCTION(original_LastTwatteeAPlayer, LastTwatteeAPlayer)
int LastTwatteeAPlayer(tOpponent_spec *pOpponent_spec) {
    LOG_TRACE("(%p)", pOpponent_spec);

    (void)pOpponent_spec;

    return original_LastTwatteeAPlayer(pOpponent_spec);
}

static int(*original_LastTwatterAPlayer)(tOpponent_spec *, ...) = (int(*)(tOpponent_spec *, ...))0x00409ea9;
CARM95_HOOK_FUNCTION(original_LastTwatterAPlayer, LastTwatterAPlayer)
int LastTwatterAPlayer(tOpponent_spec *pOpponent_spec) {
    LOG_TRACE("(%p)", pOpponent_spec);

    (void)pOpponent_spec;

    return original_LastTwatterAPlayer(pOpponent_spec);
}

static void(*original_ObjectiveComplete)(tOpponent_spec *, ...) = (void(*)(tOpponent_spec *, ...))0x00408e2d;
CARM95_HOOK_FUNCTION(original_ObjectiveComplete, ObjectiveComplete)
void ObjectiveComplete(tOpponent_spec *pOpponent_spec) {
    LOG_TRACE("(%p)", pOpponent_spec);

    (void)pOpponent_spec;

    original_ObjectiveComplete(pOpponent_spec);
}

static void(*original_TeleportOpponentToNearestSafeLocation)(tOpponent_spec *, ...) = (void(*)(tOpponent_spec *, ...))0x00404464;
CARM95_HOOK_FUNCTION(original_TeleportOpponentToNearestSafeLocation, TeleportOpponentToNearestSafeLocation)
void TeleportOpponentToNearestSafeLocation(tOpponent_spec *pOpponent_spec) {
    tS16 section_no;
    tU8 section_direction;
    br_scalar distance;
    br_vector3 direction_v;
    br_vector3 intersect;
    int section_counter;
    int found_safe_place;
    LOG_TRACE("(%p)", pOpponent_spec);

    (void)pOpponent_spec;
    (void)section_no;
    (void)section_direction;
    (void)distance;
    (void)direction_v;
    (void)intersect;
    (void)section_counter;
    (void)found_safe_place;

    original_TeleportOpponentToNearestSafeLocation(pOpponent_spec);
}

static void(*original_ChooseNewObjective)(tOpponent_spec *, int, ...) = (void(*)(tOpponent_spec *, int, ...))0x00408ec5;
CARM95_HOOK_FUNCTION(original_ChooseNewObjective, ChooseNewObjective)
void ChooseNewObjective(tOpponent_spec *pOpponent_spec, int pMust_choose_one) {
    char str[255];
    tS16 players_section;
    br_vector3 wank;
    br_vector3 player_to_oppo_v;
    br_vector3 section_v;
    br_vector3 intersect;
    br_scalar dot;
    br_scalar distance;
    int do_it;
    int i;
    int j;
    int pursuit_percentage;
    int percentage;
    int general_grudge_increase;
    LOG_TRACE("(%p, %d)", pOpponent_spec, pMust_choose_one);

    (void)pOpponent_spec;
    (void)pMust_choose_one;
    (void)str;
    (void)players_section;
    (void)wank;
    (void)player_to_oppo_v;
    (void)section_v;
    (void)intersect;
    (void)dot;
    (void)distance;
    (void)do_it;
    (void)i;
    (void)j;
    (void)pursuit_percentage;
    (void)percentage;
    (void)general_grudge_increase;

    original_ChooseNewObjective(pOpponent_spec, pMust_choose_one);
}

void ProcessThisOpponent(tOpponent_spec *pOpponent_spec) {
    int i;
    LOG_TRACE("(%p)", pOpponent_spec);

    (void)pOpponent_spec;
    (void)i;

    NOT_IMPLEMENTED();
}

static int(*original_IsNetCarActive)(br_vector3 *, ...) = (int(*)(br_vector3 *, ...))0x004034b7;
CARM95_HOOK_FUNCTION(original_IsNetCarActive, IsNetCarActive)
int IsNetCarActive(br_vector3 *pPoint) {
    br_vector3 tv;
    LOG_TRACE("(%p)", pPoint);

    (void)pPoint;
    (void)tv;

    return original_IsNetCarActive(pPoint);
}

static void(*original_RebuildActiveCarList)() = (void(*)())0x004031c3;
CARM95_HOOK_FUNCTION(original_RebuildActiveCarList, RebuildActiveCarList)
void RebuildActiveCarList() {
    int i;
    tCar_spec *car_spec;
    LOG_TRACE("()");

    (void)i;
    (void)car_spec;

    original_RebuildActiveCarList();
}

static void(*original_ForceRebuildActiveCarList)() = (void(*)())0x0040319c;
CARM95_HOOK_FUNCTION(original_ForceRebuildActiveCarList, ForceRebuildActiveCarList)
void ForceRebuildActiveCarList() {
    LOG_TRACE("()");


    original_ForceRebuildActiveCarList();
}

static void(*original_StartToCheat)(tOpponent_spec *, ...) = (void(*)(tOpponent_spec *, ...))0x00409eee;
CARM95_HOOK_FUNCTION(original_StartToCheat, StartToCheat)
void StartToCheat(tOpponent_spec *pOpponent_spec) {
    LOG_TRACE("(%p)", pOpponent_spec);

    (void)pOpponent_spec;

    original_StartToCheat(pOpponent_spec);
}

static void(*original_OiStopCheating)(tOpponent_spec *, ...) = (void(*)(tOpponent_spec *, ...))0x00409f78;
CARM95_HOOK_FUNCTION(original_OiStopCheating, OiStopCheating)
void OiStopCheating(tOpponent_spec *pOpponent_spec) {
    LOG_TRACE("(%p)", pOpponent_spec);

    (void)pOpponent_spec;

    original_OiStopCheating(pOpponent_spec);
}

static int(*original_TeleportCopToStart)(tOpponent_spec *, ...) = (int(*)(tOpponent_spec *, ...))0x00409ff7;
CARM95_HOOK_FUNCTION(original_TeleportCopToStart, TeleportCopToStart)
int TeleportCopToStart(tOpponent_spec *pOpponent_spec) {
    br_vector3 wank;
    LOG_TRACE("(%p)", pOpponent_spec);

    (void)pOpponent_spec;
    (void)wank;

    return original_TeleportCopToStart(pOpponent_spec);
}

static void(*original_CalcDistanceFromHome)(tOpponent_spec *, ...) = (void(*)(tOpponent_spec *, ...))0x0040a13d;
CARM95_HOOK_FUNCTION(original_CalcDistanceFromHome, CalcDistanceFromHome)
void CalcDistanceFromHome(tOpponent_spec *pOpponent_spec) {
    br_vector3 wank;
    LOG_TRACE("(%p)", pOpponent_spec);

    (void)pOpponent_spec;
    (void)wank;

    original_CalcDistanceFromHome(pOpponent_spec);
}

static int(*original_MassageOpponentPosition)(tOpponent_spec *, int, ...) = (int(*)(tOpponent_spec *, int, ...))0x0040472e;
CARM95_HOOK_FUNCTION(original_MassageOpponentPosition, MassageOpponentPosition)
int MassageOpponentPosition(tOpponent_spec *pOpponent_spec, int pMassage_count) {
    br_matrix34 *mat;
    br_vector3 *car_trans;
    br_vector3 displacement;
    br_vector3 positive_y_vector;
    br_vector3 direction_v;
    br_scalar __block0___scale;
    br_scalar __block1___scale;
    LOG_TRACE("(%p, %d)", pOpponent_spec, pMassage_count);

    (void)pOpponent_spec;
    (void)pMassage_count;
    (void)mat;
    (void)car_trans;
    (void)displacement;
    (void)positive_y_vector;
    (void)direction_v;

    return original_MassageOpponentPosition(pOpponent_spec, pMassage_count);
}

static int(*original_RematerialiseOpponentOnThisSection)(tOpponent_spec *, br_scalar, tS16, ...) = (int(*)(tOpponent_spec *, br_scalar, tS16, ...))0x004035b1;
CARM95_HOOK_FUNCTION(original_RematerialiseOpponentOnThisSection, RematerialiseOpponentOnThisSection)
int RematerialiseOpponentOnThisSection(tOpponent_spec *pOpponent_spec, br_scalar pSpeed, tS16 pSection_no) {
    br_vector3 *start;
    br_vector3 *finish;
    br_vector3 a;
    br_vector3 p;
    br_vector3 section_v;
    br_vector3 car_to_end;
    br_vector3 intersect;
    br_scalar t;
    br_scalar distance_to_end;
    br_scalar length;
    LOG_TRACE("(%p, %f, %d)", pOpponent_spec, pSpeed, pSection_no);

    (void)pOpponent_spec;
    (void)pSpeed;
    (void)pSection_no;
    (void)start;
    (void)finish;
    (void)a;
    (void)p;
    (void)section_v;
    (void)car_to_end;
    (void)intersect;
    (void)t;
    (void)distance_to_end;
    (void)length;

    return original_RematerialiseOpponentOnThisSection(pOpponent_spec, pSpeed, pSection_no);
}

static int(*original_RematerialiseOpponentOnNearestSection)(tOpponent_spec *, br_scalar, ...) = (int(*)(tOpponent_spec *, br_scalar, ...))0x004038fe;
CARM95_HOOK_FUNCTION(original_RematerialiseOpponentOnNearestSection, RematerialiseOpponentOnNearestSection)
int RematerialiseOpponentOnNearestSection(tOpponent_spec *pOpponent_spec, br_scalar pSpeed) {
    br_vector3 intersect;
    br_vector3 direction_v;
    br_vector3 car_to_end;
    br_vector3 *start;
    br_vector3 *finish;
    br_scalar distance;
    br_scalar distance_to_end;
    tS16 section_no;
    LOG_TRACE("(%p, %f)", pOpponent_spec, pSpeed);

    (void)pOpponent_spec;
    (void)pSpeed;
    (void)intersect;
    (void)direction_v;
    (void)car_to_end;
    (void)start;
    (void)finish;
    (void)distance;
    (void)distance_to_end;
    (void)section_no;

    return original_RematerialiseOpponentOnNearestSection(pOpponent_spec, pSpeed);
}

static int(*original_RematerialiseOpponent)(tOpponent_spec *, br_scalar, ...) = (int(*)(tOpponent_spec *, br_scalar, ...))0x00403ad9;
CARM95_HOOK_FUNCTION(original_RematerialiseOpponent, RematerialiseOpponent)
int RematerialiseOpponent(tOpponent_spec *pOpponent_spec, br_scalar pSpeed) {
    static int count;
    static int total;
    static int highest;
    int this_total;
    br_matrix34 *mat;
    br_matrix34 original_mat;
    br_vector3 a;
    br_vector3 b;
    br_vector3 norm;
    br_vector3 norm2;
    br_scalar dist;
    br_scalar dist2;
    br_scalar ts;
    br_angle phi;
    int i;
    int j;
    int massage_count;
    br_angle theta;
    int sensible_place;
    br_scalar __block0___scale;
    LOG_TRACE("(%p, %f)", pOpponent_spec, pSpeed);

    (void)pOpponent_spec;
    (void)pSpeed;
    (void)count;
    (void)total;
    (void)highest;
    (void)this_total;
    (void)mat;
    (void)original_mat;
    (void)a;
    (void)b;
    (void)norm;
    (void)norm2;
    (void)dist;
    (void)dist2;
    (void)ts;
    (void)phi;
    (void)i;
    (void)j;
    (void)massage_count;
    (void)theta;
    (void)sensible_place;

    return original_RematerialiseOpponent(pOpponent_spec, pSpeed);
}

static void(*original_CalcPlayerConspicuousness)(tOpponent_spec *, ...) = (void(*)(tOpponent_spec *, ...))0x0040a1ab;
CARM95_HOOK_FUNCTION(original_CalcPlayerConspicuousness, CalcPlayerConspicuousness)
void CalcPlayerConspicuousness(tOpponent_spec *pOpponent_spec) {
    br_vector3 pos_in_cop_space;
    br_matrix34 inverse_transform;
    LOG_TRACE("(%p)", pOpponent_spec);

    (void)pOpponent_spec;
    (void)pos_in_cop_space;
    (void)inverse_transform;

    original_CalcPlayerConspicuousness(pOpponent_spec);
}

static void(*original_CalcOpponentConspicuousnessWithAViewToCheatingLikeFuck)(tOpponent_spec *, ...) = (void(*)(tOpponent_spec *, ...))0x00406458;
CARM95_HOOK_FUNCTION(original_CalcOpponentConspicuousnessWithAViewToCheatingLikeFuck, CalcOpponentConspicuousnessWithAViewToCheatingLikeFuck)
void CalcOpponentConspicuousnessWithAViewToCheatingLikeFuck(tOpponent_spec *pOpponent_spec) {
    LOG_TRACE("(%p)", pOpponent_spec);

    (void)pOpponent_spec;

    original_CalcOpponentConspicuousnessWithAViewToCheatingLikeFuck(pOpponent_spec);
}

static void(*original_ChallengeOccurred)(int, int, ...) = (void(*)(int, int, ...))0x00404abc;
CARM95_HOOK_FUNCTION(original_ChallengeOccurred, ChallengeOccurred)
void ChallengeOccurred(int pChallenger_index, int pAccepted) {
    LOG_TRACE("(%d, %d)", pChallenger_index, pAccepted);

    (void)pChallenger_index;
    (void)pAccepted;

    original_ChallengeOccurred(pChallenger_index, pAccepted);
}

static void(*original_LoadCopCars)() = (void(*)())0x00404ad9;
CARM95_HOOK_FUNCTION(original_LoadCopCars, LoadCopCars)
void LoadCopCars() {
    int i;
    LOG_TRACE("()");

    (void)i;

    original_LoadCopCars();
}

static void(*original_LoadInOppoPaths)(FILE *, ...) = (void(*)(FILE *, ...))0x00404b9b;
CARM95_HOOK_FUNCTION(original_LoadInOppoPaths, LoadInOppoPaths)
void LoadInOppoPaths(FILE *pF) {
    char s[256];
    char *res;
    int data_errors;
    int section_no;
    int node_no;
    int i;
    br_scalar x;
    br_scalar y;
    br_scalar z;
    br_scalar scalars[8];
    br_scalar distance;
    tPath_node *node_ptr;
    br_vector3 section_v;
    br_vector3 positive_y_vector;
    br_vector3 intersect;
    br_vector3 cop_to_section;
    int j;
    int sections_to_delete;
    int delete_these[1024];
    float __block0__x_0;
    float __block0__x_1;
    float __block0__x_2;
    LOG_TRACE("(%p)", pF);

    (void)pF;
    (void)s;
    (void)res;
    (void)data_errors;
    (void)section_no;
    (void)node_no;
    (void)i;
    (void)x;
    (void)y;
    (void)z;
    (void)scalars;
    (void)distance;
    (void)node_ptr;
    (void)section_v;
    (void)positive_y_vector;
    (void)intersect;
    (void)cop_to_section;
    (void)j;
    (void)sections_to_delete;
    (void)delete_these;

    original_LoadInOppoPaths(pF);
}

static void(*original_DisposeOpponentPaths)() = (void(*)())0x00405912;
CARM95_HOOK_FUNCTION(original_DisposeOpponentPaths, DisposeOpponentPaths)
void DisposeOpponentPaths() {
    LOG_TRACE("()");


    original_DisposeOpponentPaths();
}

static void(*original_MungeOpponents)(tU32, ...) = (void(*)(tU32, ...))0x004059a0;
CARM95_HOOK_FUNCTION(original_MungeOpponents, MungeOpponents)
void MungeOpponents(tU32 pFrame_period) {
    int i;
    int un_stun_flag;
    LOG_TRACE("(%u)", pFrame_period);

    (void)pFrame_period;
    (void)i;
    (void)un_stun_flag;

    original_MungeOpponents(pFrame_period);
}

static void(*original_SetInitialCopPositions)() = (void(*)())0x0040a3a5;
CARM95_HOOK_FUNCTION(original_SetInitialCopPositions, SetInitialCopPositions)
void SetInitialCopPositions() {
    int i;
    LOG_TRACE("()");

    (void)i;

    original_SetInitialCopPositions();
}

static void(*original_InitOpponents)(tRace_info *, ...) = (void(*)(tRace_info *, ...))0x0040a4ce;
CARM95_HOOK_FUNCTION(original_InitOpponents, InitOpponents)
void InitOpponents(tRace_info *pRace_info) {
    int i;
    int opponent_number;
    int rank_dependent_difficulty;
    int skill_dependent_difficulty;
    br_bounds bounds;
    tCar_spec *__block0__car_spec;
    tOpponent_spec *__block0__opponent_spec;
    LOG_TRACE("(%p)", pRace_info);

    (void)pRace_info;
    (void)i;
    (void)opponent_number;
    (void)rank_dependent_difficulty;
    (void)skill_dependent_difficulty;
    (void)bounds;

    original_InitOpponents(pRace_info);
}

static void(*original_DisposeOpponents)() = (void(*)())0x0040b186;
CARM95_HOOK_FUNCTION(original_DisposeOpponents, DisposeOpponents)
void DisposeOpponents() {
    int i;
    LOG_TRACE("()");

    (void)i;

    original_DisposeOpponents();
}

static void(*original_WakeUpOpponentsToTheFactThatTheStartHasBeenJumped)(int, ...) = (void(*)(int, ...))0x0040b20f;
CARM95_HOOK_FUNCTION(original_WakeUpOpponentsToTheFactThatTheStartHasBeenJumped, WakeUpOpponentsToTheFactThatTheStartHasBeenJumped)
void WakeUpOpponentsToTheFactThatTheStartHasBeenJumped(int pWhat_the_countdown_was) {
    int i;
    LOG_TRACE("(%d)", pWhat_the_countdown_was);

    (void)pWhat_the_countdown_was;
    (void)i;

    original_WakeUpOpponentsToTheFactThatTheStartHasBeenJumped(pWhat_the_countdown_was);
}

static void(*original_ReportMurderToPoliceDepartment)(tCar_spec *, ...) = (void(*)(tCar_spec *, ...))0x0040b3a5;
CARM95_HOOK_FUNCTION(original_ReportMurderToPoliceDepartment, ReportMurderToPoliceDepartment)
void ReportMurderToPoliceDepartment(tCar_spec *pCar_spec) {
    int i;
    LOG_TRACE("(%p)", pCar_spec);

    (void)pCar_spec;
    (void)i;

    original_ReportMurderToPoliceDepartment(pCar_spec);
}

static int(*original_GetCarCount)(tVehicle_type, ...) = (int(*)(tVehicle_type, ...))0x0040b412;
CARM95_HOOK_FUNCTION(original_GetCarCount, GetCarCount)
int GetCarCount(tVehicle_type pCategory) {
    LOG_TRACE("(%d)", pCategory);

    (void)pCategory;

    return original_GetCarCount(pCategory);
}

static tCar_spec *(*original_GetCarSpec)(tVehicle_type, int, ...) = (tCar_spec *(*)(tVehicle_type, int, ...))0x0040b4b1;
CARM95_HOOK_FUNCTION(original_GetCarSpec, GetCarSpec)
tCar_spec* GetCarSpec(tVehicle_type pCategory, int pIndex) {
    LOG_TRACE("(%d, %d)", pCategory, pIndex);

    (void)pCategory;
    (void)pIndex;

    return original_GetCarSpec(pCategory, pIndex);
}

static char *(*original_GetDriverName)(tVehicle_type, int, ...) = (char *(*)(tVehicle_type, int, ...))0x0040b592;
CARM95_HOOK_FUNCTION(original_GetDriverName, GetDriverName)
char* GetDriverName(tVehicle_type pCategory, int pIndex) {
    LOG_TRACE("(%d, %d)", pCategory, pIndex);

    (void)pCategory;
    (void)pIndex;

    return original_GetDriverName(pCategory, pIndex);
}

static tOpponent_spec *(*original_GetOpponentSpecFromCarSpec)(tCar_spec *, ...) = (tOpponent_spec *(*)(tCar_spec *, ...))0x0040b639;
CARM95_HOOK_FUNCTION(original_GetOpponentSpecFromCarSpec, GetOpponentSpecFromCarSpec)
tOpponent_spec* GetOpponentSpecFromCarSpec(tCar_spec *pCar_spec) {
    int i;
    LOG_TRACE("(%p)", pCar_spec);

    (void)pCar_spec;
    (void)i;

    return original_GetOpponentSpecFromCarSpec(pCar_spec);
}

static tCar_spec *(*original_GetCarSpecFromGlobalOppoIndex)(int, ...) = (tCar_spec *(*)(int, ...))0x0040b74d;
CARM95_HOOK_FUNCTION(original_GetCarSpecFromGlobalOppoIndex, GetCarSpecFromGlobalOppoIndex)
tCar_spec* GetCarSpecFromGlobalOppoIndex(int pIndex) {
    int i;
    LOG_TRACE("(%d)", pIndex);

    (void)pIndex;
    (void)i;

    return original_GetCarSpecFromGlobalOppoIndex(pIndex);
}

static int(*original_GetOpponentsRealSection)(tOpponent_spec *, int, ...) = (int(*)(tOpponent_spec *, int, ...))0x0040b7b7;
CARM95_HOOK_FUNCTION(original_GetOpponentsRealSection, GetOpponentsRealSection)
int GetOpponentsRealSection(tOpponent_spec *pOpponent_spec, int pSection_no) {
    LOG_TRACE("(%p, %d)", pOpponent_spec, pSection_no);

    (void)pOpponent_spec;
    (void)pSection_no;

    return original_GetOpponentsRealSection(pOpponent_spec, pSection_no);
}

static int(*original_GetOpponentsFirstSection)(tOpponent_spec *, ...) = (int(*)(tOpponent_spec *, ...))0x0040b806;
CARM95_HOOK_FUNCTION(original_GetOpponentsFirstSection, GetOpponentsFirstSection)
int GetOpponentsFirstSection(tOpponent_spec *pOpponent_spec) {
    LOG_TRACE("(%p)", pOpponent_spec);

    (void)pOpponent_spec;

    return original_GetOpponentsFirstSection(pOpponent_spec);
}

static int(*original_GetOpponentsNextSection)(tOpponent_spec *, tS16, ...) = (int(*)(tOpponent_spec *, tS16, ...))0x0040b86e;
CARM95_HOOK_FUNCTION(original_GetOpponentsNextSection, GetOpponentsNextSection)
int GetOpponentsNextSection(tOpponent_spec *pOpponent_spec, tS16 pCurrent_section) {
    LOG_TRACE("(%p, %d)", pOpponent_spec, pCurrent_section);

    (void)pOpponent_spec;
    (void)pCurrent_section;

    return original_GetOpponentsNextSection(pOpponent_spec, pCurrent_section);
}

static tS16(*original_GetOpponentsSectionStartNode)(tOpponent_spec *, tS16, ...) = (tS16(*)(tOpponent_spec *, tS16, ...))0x0040b91f;
CARM95_HOOK_FUNCTION(original_GetOpponentsSectionStartNode, GetOpponentsSectionStartNode)
tS16 GetOpponentsSectionStartNode(tOpponent_spec *pOpponent_spec, tS16 pSection) {
    tS16 section_no;
    int node_index_index;
    LOG_TRACE("(%p, %d)", pOpponent_spec, pSection);

    (void)pOpponent_spec;
    (void)pSection;
    (void)section_no;
    (void)node_index_index;

    return original_GetOpponentsSectionStartNode(pOpponent_spec, pSection);
}

static tS16(*original_GetOpponentsSectionFinishNode)(tOpponent_spec *, tS16, ...) = (tS16(*)(tOpponent_spec *, tS16, ...))0x0040b9fb;
CARM95_HOOK_FUNCTION(original_GetOpponentsSectionFinishNode, GetOpponentsSectionFinishNode)
tS16 GetOpponentsSectionFinishNode(tOpponent_spec *pOpponent_spec, tS16 pSection) {
    tS16 section_no;
    int node_index_index;
    LOG_TRACE("(%p, %d)", pOpponent_spec, pSection);

    (void)pOpponent_spec;
    (void)pSection;
    (void)section_no;
    (void)node_index_index;

    return original_GetOpponentsSectionFinishNode(pOpponent_spec, pSection);
}

static br_vector3 *(*original_GetOpponentsSectionStartNodePoint)(tOpponent_spec *, tS16, ...) = (br_vector3 *(*)(tOpponent_spec *, tS16, ...))0x0040baa1;
CARM95_HOOK_FUNCTION(original_GetOpponentsSectionStartNodePoint, GetOpponentsSectionStartNodePoint)
br_vector3* GetOpponentsSectionStartNodePoint(tOpponent_spec *pOpponent_spec, tS16 pSection) {
    tS16 section_no;
    tS16 node_no;
    int node_index_index;
    LOG_TRACE("(%p, %d)", pOpponent_spec, pSection);

    (void)pOpponent_spec;
    (void)pSection;
    (void)section_no;
    (void)node_no;
    (void)node_index_index;

    return original_GetOpponentsSectionStartNodePoint(pOpponent_spec, pSection);
}

static br_vector3 *(*original_GetOpponentsSectionFinishNodePoint)(tOpponent_spec *, tS16, ...) = (br_vector3 *(*)(tOpponent_spec *, tS16, ...))0x0040bbc3;
CARM95_HOOK_FUNCTION(original_GetOpponentsSectionFinishNodePoint, GetOpponentsSectionFinishNodePoint)
br_vector3* GetOpponentsSectionFinishNodePoint(tOpponent_spec *pOpponent_spec, tS16 pSection) {
    tS16 section_no;
    tS16 node_no;
    int node_index_index;
    LOG_TRACE("(%p, %d)", pOpponent_spec, pSection);

    (void)pOpponent_spec;
    (void)pSection;
    (void)section_no;
    (void)node_no;
    (void)node_index_index;

    return original_GetOpponentsSectionFinishNodePoint(pOpponent_spec, pSection);
}

static br_scalar(*original_GetOpponentsSectionWidth)(tOpponent_spec *, tS16, ...) = (br_scalar(*)(tOpponent_spec *, tS16, ...))0x0040bccd;
CARM95_HOOK_FUNCTION(original_GetOpponentsSectionWidth, GetOpponentsSectionWidth)
br_scalar GetOpponentsSectionWidth(tOpponent_spec *pOpponent_spec, tS16 pSection) {
    LOG_TRACE("(%p, %d)", pOpponent_spec, pSection);

    (void)pOpponent_spec;
    (void)pSection;

    return original_GetOpponentsSectionWidth(pOpponent_spec, pSection);
}

static int(*original_GetOpponentsSectionMinSpeed)(tOpponent_spec *, tS16, int, ...) = (int(*)(tOpponent_spec *, tS16, int, ...))0x0040bd7a;
CARM95_HOOK_FUNCTION(original_GetOpponentsSectionMinSpeed, GetOpponentsSectionMinSpeed)
int GetOpponentsSectionMinSpeed(tOpponent_spec *pOpponent_spec, tS16 pSection, int pTowards_finish) {
    tS16 section_no;
    int direction;
    LOG_TRACE("(%p, %d, %d)", pOpponent_spec, pSection, pTowards_finish);

    (void)pOpponent_spec;
    (void)pSection;
    (void)pTowards_finish;
    (void)section_no;
    (void)direction;

    return original_GetOpponentsSectionMinSpeed(pOpponent_spec, pSection, pTowards_finish);
}

static int(*original_GetOpponentsSectionMaxSpeed)(tOpponent_spec *, tS16, int, ...) = (int(*)(tOpponent_spec *, tS16, int, ...))0x0040be6e;
CARM95_HOOK_FUNCTION(original_GetOpponentsSectionMaxSpeed, GetOpponentsSectionMaxSpeed)
int GetOpponentsSectionMaxSpeed(tOpponent_spec *pOpponent_spec, tS16 pSection, int pTowards_finish) {
    tS16 section_no;
    int direction;
    LOG_TRACE("(%p, %d, %d)", pOpponent_spec, pSection, pTowards_finish);

    (void)pOpponent_spec;
    (void)pSection;
    (void)pTowards_finish;
    (void)section_no;
    (void)direction;

    return original_GetOpponentsSectionMaxSpeed(pOpponent_spec, pSection, pTowards_finish);
}

static void(*original_InitOpponentPsyche)(int, ...) = (void(*)(int, ...))0x0040bf68;
CARM95_HOOK_FUNCTION(original_InitOpponentPsyche, InitOpponentPsyche)
void InitOpponentPsyche(int pOpponent_index) {
    int i;
    LOG_TRACE("(%d)", pOpponent_index);

    (void)pOpponent_index;
    (void)i;

    original_InitOpponentPsyche(pOpponent_index);
}

static void(*original_ClearTwattageOccurrenceVariables)(tOpponent_spec *, ...) = (void(*)(tOpponent_spec *, ...))0x0040bf8d;
CARM95_HOOK_FUNCTION(original_ClearTwattageOccurrenceVariables, ClearTwattageOccurrenceVariables)
void ClearTwattageOccurrenceVariables(tOpponent_spec *pOpponent_spec) {
    LOG_TRACE("(%p)", pOpponent_spec);

    (void)pOpponent_spec;

    original_ClearTwattageOccurrenceVariables(pOpponent_spec);
}

static void(*original_TwoCarsHitEachOther)(tCar_spec *, tCar_spec *, ...) = (void(*)(tCar_spec *, tCar_spec *, ...))0x0040bfdf;
CARM95_HOOK_FUNCTION(original_TwoCarsHitEachOther, TwoCarsHitEachOther)
void TwoCarsHitEachOther(tCar_spec *pA_car, tCar_spec *pAnother_car) {
    LOG_TRACE("(%p, %p)", pA_car, pAnother_car);

    (void)pA_car;
    (void)pAnother_car;

    original_TwoCarsHitEachOther(pA_car, pAnother_car);
}

static void(*original_RecordOpponentTwattageOccurrence)(tCar_spec *, tCar_spec *, ...) = (void(*)(tCar_spec *, tCar_spec *, ...))0x0040c020;
CARM95_HOOK_FUNCTION(original_RecordOpponentTwattageOccurrence, RecordOpponentTwattageOccurrence)
void RecordOpponentTwattageOccurrence(tCar_spec *pTwatter, tCar_spec *pTwattee) {
    int bangness;
    int twatter_index;
    int twattee_index;
    int grudginess_caused_by_damage;
    int new_grudge_value;
    float damage;
    char str[256];
    tOpponent_spec *twattee_opponent_spec;
    tOpponent_spec *twatter_opponent_spec;
    LOG_TRACE("(%p, %p)", pTwatter, pTwattee);

    (void)pTwatter;
    (void)pTwattee;
    (void)bangness;
    (void)twatter_index;
    (void)twattee_index;
    (void)grudginess_caused_by_damage;
    (void)new_grudge_value;
    (void)damage;
    (void)str;
    (void)twattee_opponent_spec;
    (void)twatter_opponent_spec;

    original_RecordOpponentTwattageOccurrence(pTwatter, pTwattee);
}

static void(*original_ToggleOpponentTest)() = (void(*)())0x0040c537;
CARM95_HOOK_FUNCTION(original_ToggleOpponentTest, ToggleOpponentTest)
void ToggleOpponentTest() {
    LOG_TRACE("()");


    original_ToggleOpponentTest();
}

static void(*original_ToggleOpponentProcessing)() = (void(*)())0x0040c568;
CARM95_HOOK_FUNCTION(original_ToggleOpponentProcessing, ToggleOpponentProcessing)
void ToggleOpponentProcessing() {
    int i;
    LOG_TRACE("()");

    (void)i;

    original_ToggleOpponentProcessing();
}

static void(*original_ToggleMellowOpponents)() = (void(*)())0x0040c6dd;
CARM95_HOOK_FUNCTION(original_ToggleMellowOpponents, ToggleMellowOpponents)
void ToggleMellowOpponents() {
    int i;
    LOG_TRACE("()");

    (void)i;

    original_ToggleMellowOpponents();
}

static void(*original_RepairOpponentsSystems)() = (void(*)())0x0040c795;
CARM95_HOOK_FUNCTION(original_RepairOpponentsSystems, RepairOpponentsSystems)
void RepairOpponentsSystems() {
    int i;
    LOG_TRACE("()");

    (void)i;

    original_RepairOpponentsSystems();
}

static void(*original_CopyVertex__opponent)(br_vertex *, br_vertex *, ...) = (void(*)(br_vertex *, br_vertex *, ...))0x0040e205;
CARM95_HOOK_FUNCTION(original_CopyVertex__opponent, CopyVertex__opponent)
void CopyVertex__opponent(br_vertex *pDest_vertex, br_vertex *pSrc_vertex) {
    LOG_TRACE("(%p, %p)", pDest_vertex, pSrc_vertex);

    (void)pDest_vertex;
    (void)pSrc_vertex;

    original_CopyVertex__opponent(pDest_vertex, pSrc_vertex);
}

static void(*original_CopyFace__opponent)(br_face *, br_face *, ...) = (void(*)(br_face *, br_face *, ...))0x0040e27a;
CARM95_HOOK_FUNCTION(original_CopyFace__opponent, CopyFace__opponent)
void CopyFace__opponent(br_face *pDest_face, br_face *pSrc_face) {
    LOG_TRACE("(%p, %p)", pDest_face, pSrc_face);

    (void)pDest_face;
    (void)pSrc_face;

    original_CopyFace__opponent(pDest_face, pSrc_face);
}

static void(*original_DeleteSection)(tS16, ...) = (void(*)(tS16, ...))0x0040c868;
CARM95_HOOK_FUNCTION(original_DeleteSection, DeleteSection)
void DeleteSection(tS16 pSection_to_delete) {
    tS16 section_no;
    tS16 section_no_index;
    tS16 node_no;
    tS16 node_no_index;
    tS16 found_it;
    LOG_TRACE("(%d)", pSection_to_delete);

    (void)pSection_to_delete;
    (void)section_no;
    (void)section_no_index;
    (void)node_no;
    (void)node_no_index;
    (void)found_it;

    original_DeleteSection(pSection_to_delete);
}

static void(*original_DeleteNode)(tS16, int, ...) = (void(*)(tS16, int, ...))0x0040caf4;
CARM95_HOOK_FUNCTION(original_DeleteNode, DeleteNode)
void DeleteNode(tS16 pNode_to_delete, int pAnd_sections) {
    tS16 node_no;
    tS16 section_no;
    tS16 section1;
    tS16 section2;
    LOG_TRACE("(%d, %d)", pNode_to_delete, pAnd_sections);

    (void)pNode_to_delete;
    (void)pAnd_sections;
    (void)node_no;
    (void)section_no;
    (void)section1;
    (void)section2;

    original_DeleteNode(pNode_to_delete, pAnd_sections);
}

static void(*original_DeleteOrphanNodes)() = (void(*)())0x0040ca84;
CARM95_HOOK_FUNCTION(original_DeleteOrphanNodes, DeleteOrphanNodes)
void DeleteOrphanNodes() {
    tS16 node_no;
    LOG_TRACE("()");

    (void)node_no;

    original_DeleteOrphanNodes();
}

static void(*original_InsertThisNodeInThisSectionHere)(tS16, tS16, br_vector3 *, ...) = (void(*)(tS16, tS16, br_vector3 *, ...))0x0040fb06;
CARM95_HOOK_FUNCTION(original_InsertThisNodeInThisSectionHere, InsertThisNodeInThisSectionHere)
void InsertThisNodeInThisSectionHere(tS16 pInserted_node, tS16 pSection_no, br_vector3 *pWhere) {
    tS16 new_section;
    tS16 section_no_index;
    tS16 node1;
    tS16 node2;
    tS16 node3;
    LOG_TRACE("(%d, %d, %p)", pInserted_node, pSection_no, pWhere);

    (void)pInserted_node;
    (void)pSection_no;
    (void)pWhere;
    (void)new_section;
    (void)section_no_index;
    (void)node1;
    (void)node2;
    (void)node3;

    original_InsertThisNodeInThisSectionHere(pInserted_node, pSection_no, pWhere);
}

static void(*original_TrackElasticateyPath)() = (void(*)())0x0040ce66;
CARM95_HOOK_FUNCTION(original_TrackElasticateyPath, TrackElasticateyPath)
void TrackElasticateyPath() {
    LOG_TRACE("()");


    original_TrackElasticateyPath();
}

static void(*original_RecalcNearestPathSectionSpeed)(int, int, ...) = (void(*)(int, int, ...))0x004105c6;
CARM95_HOOK_FUNCTION(original_RecalcNearestPathSectionSpeed, RecalcNearestPathSectionSpeed)
void RecalcNearestPathSectionSpeed(int pMax_not_min, int pAdjustment) {
    tS16 section_no;
    br_vector3 direction_v;
    br_vector3 intersect;
    br_vector3 wank;
    br_scalar distance;
    br_scalar dist_to_start;
    br_scalar dist_to_finish;
    char str[128];
    int new_speed;
    int nearest_end;
    LOG_TRACE("(%d, %d)", pMax_not_min, pAdjustment);

    (void)pMax_not_min;
    (void)pAdjustment;
    (void)section_no;
    (void)direction_v;
    (void)intersect;
    (void)wank;
    (void)distance;
    (void)dist_to_start;
    (void)dist_to_finish;
    (void)str;
    (void)new_speed;
    (void)nearest_end;

    original_RecalcNearestPathSectionSpeed(pMax_not_min, pAdjustment);
}

static void(*original_RecalcNearestPathSectionWidth)(br_scalar, ...) = (void(*)(br_scalar, ...))0x004103ef;
CARM95_HOOK_FUNCTION(original_RecalcNearestPathSectionWidth, RecalcNearestPathSectionWidth)
void RecalcNearestPathSectionWidth(br_scalar pAdjustment) {
    tS16 section_no;
    br_vector3 direction_v;
    br_vector3 intersect;
    br_scalar distance;
    char str[128];
    LOG_TRACE("(%f)", pAdjustment);

    (void)pAdjustment;
    (void)section_no;
    (void)direction_v;
    (void)intersect;
    (void)distance;
    (void)str;

    original_RecalcNearestPathSectionWidth(pAdjustment);
}

static void(*original_CalcNegativeXVector)(br_vector3 *, br_vector3 *, br_vector3 *, br_scalar, ...) = (void(*)(br_vector3 *, br_vector3 *, br_vector3 *, br_scalar, ...))0x0040cf4e;
CARM95_HOOK_FUNCTION(original_CalcNegativeXVector, CalcNegativeXVector)
void CalcNegativeXVector(br_vector3 *pNegative_x_vector, br_vector3 *pStart, br_vector3 *pFinish, br_scalar pLength) {
    br_vector3 positive_y_vector;
    br_vector3 path_vector;
    br_scalar __block0___scale;
    LOG_TRACE("(%p, %p, %p, %f)", pNegative_x_vector, pStart, pFinish, pLength);

    (void)pNegative_x_vector;
    (void)pStart;
    (void)pFinish;
    (void)pLength;
    (void)positive_y_vector;
    (void)path_vector;

    original_CalcNegativeXVector(pNegative_x_vector, pStart, pFinish, pLength);
}

static void(*original_MakeVertexAndOffsetIt)(br_model *, int, br_scalar, br_scalar, br_scalar, br_vector3 *, ...) = (void(*)(br_model *, int, br_scalar, br_scalar, br_scalar, br_vector3 *, ...))0x0040d9d3;
CARM95_HOOK_FUNCTION(original_MakeVertexAndOffsetIt, MakeVertexAndOffsetIt)
void MakeVertexAndOffsetIt(br_model *pModel, int pVertex_num, br_scalar pX, br_scalar pY, br_scalar pZ, br_vector3 *pOffset) {
    LOG_TRACE("(%p, %d, %f, %f, %f, %p)", pModel, pVertex_num, pX, pY, pZ, pOffset);

    (void)pModel;
    (void)pVertex_num;
    (void)pX;
    (void)pY;
    (void)pZ;
    (void)pOffset;

    original_MakeVertexAndOffsetIt(pModel, pVertex_num, pX, pY, pZ, pOffset);
}

static void(*original_MakeFaceAndTextureIt)(br_model *, int, int, int, int, br_material *, ...) = (void(*)(br_model *, int, int, int, int, br_material *, ...))0x0040da85;
CARM95_HOOK_FUNCTION(original_MakeFaceAndTextureIt, MakeFaceAndTextureIt)
void MakeFaceAndTextureIt(br_model *pModel, int pFace_num, int pV0, int pV1, int pV2, br_material *pMaterial) {
    LOG_TRACE("(%p, %d, %d, %d, %d, %p)", pModel, pFace_num, pV0, pV1, pV2, pMaterial);

    (void)pModel;
    (void)pFace_num;
    (void)pV0;
    (void)pV1;
    (void)pV2;
    (void)pMaterial;

    original_MakeFaceAndTextureIt(pModel, pFace_num, pV0, pV1, pV2, pMaterial);
}

static void(*original_MakeSection)(br_uint_16, br_uint_16, br_vector3 *, br_vector3 *, br_scalar, br_material *, br_material *, br_material *, br_material *, br_material *, br_material *, ...) = (void(*)(br_uint_16, br_uint_16, br_vector3 *, br_vector3 *, br_scalar, br_material *, br_material *, br_material *, br_material *, br_material *, br_material *, ...))0x0040d59f;
CARM95_HOOK_FUNCTION(original_MakeSection, MakeSection)
void MakeSection(br_uint_16 pFirst_vertex, br_uint_16 pFirst_face, br_vector3 *pStart, br_vector3 *pFinish, br_scalar pWidth, br_material *pMaterial_centre_lt, br_material *pMaterial_centre_dk, br_material *pMaterial_edges_start_lt, br_material *pMaterial_edges_start_dk, br_material *pMaterial_edges_finish_lt, br_material *pMaterial_edges_finish_dk) {
    int i;
    br_vector3 offset_v;
    br_vector3 centre_length_v;
    br_material *the_material_start_lt;
    br_material *the_material_start_dk;
    br_material *the_material_finish_lt;
    br_material *the_material_finish_dk;
    br_scalar height;
    LOG_TRACE("(%u, %u, %p, %p, %f, %p, %p, %p, %p, %p, %p)", pFirst_vertex, pFirst_face, pStart, pFinish, pWidth, pMaterial_centre_lt, pMaterial_centre_dk, pMaterial_edges_start_lt, pMaterial_edges_start_dk, pMaterial_edges_finish_lt, pMaterial_edges_finish_dk);

    (void)pFirst_vertex;
    (void)pFirst_face;
    (void)pStart;
    (void)pFinish;
    (void)pWidth;
    (void)pMaterial_centre_lt;
    (void)pMaterial_centre_dk;
    (void)pMaterial_edges_start_lt;
    (void)pMaterial_edges_start_dk;
    (void)pMaterial_edges_finish_lt;
    (void)pMaterial_edges_finish_dk;
    (void)i;
    (void)offset_v;
    (void)centre_length_v;
    (void)the_material_start_lt;
    (void)the_material_start_dk;
    (void)the_material_finish_lt;
    (void)the_material_finish_dk;
    (void)height;

    original_MakeSection(pFirst_vertex, pFirst_face, pStart, pFinish, pWidth, pMaterial_centre_lt, pMaterial_centre_dk, pMaterial_edges_start_lt, pMaterial_edges_start_dk, pMaterial_edges_finish_lt, pMaterial_edges_finish_dk);
}

static void(*original_MakeCube)(br_uint_16, br_uint_16, br_vector3 *, br_material *, br_material *, br_material *, ...) = (void(*)(br_uint_16, br_uint_16, br_vector3 *, br_material *, br_material *, br_material *, ...))0x0040daf1;
CARM95_HOOK_FUNCTION(original_MakeCube, MakeCube)
void MakeCube(br_uint_16 pFirst_vertex, br_uint_16 pFirst_face, br_vector3 *pPoint, br_material *pMaterial_1, br_material *pMaterial_2, br_material *pMaterial_3) {
    br_vector3 offset_v;
    br_vector3 point;
    LOG_TRACE("(%u, %u, %p, %p, %p, %p)", pFirst_vertex, pFirst_face, pPoint, pMaterial_1, pMaterial_2, pMaterial_3);

    (void)pFirst_vertex;
    (void)pFirst_face;
    (void)pPoint;
    (void)pMaterial_1;
    (void)pMaterial_2;
    (void)pMaterial_3;
    (void)offset_v;
    (void)point;

    original_MakeCube(pFirst_vertex, pFirst_face, pPoint, pMaterial_1, pMaterial_2, pMaterial_3);
}

static void(*original_CalcNumberOfFacesAndVerticesForOppoPathModel)(br_uint_16 *, br_uint_16 *, ...) = (void(*)(br_uint_16 *, br_uint_16 *, ...))0x0040e016;
CARM95_HOOK_FUNCTION(original_CalcNumberOfFacesAndVerticesForOppoPathModel, CalcNumberOfFacesAndVerticesForOppoPathModel)
void CalcNumberOfFacesAndVerticesForOppoPathModel(br_uint_16 *pFace_index_ptr, br_uint_16 *pVertex_index_ptr) {
    LOG_TRACE("(%p, %p)", pFace_index_ptr, pVertex_index_ptr);

    (void)pFace_index_ptr;
    (void)pVertex_index_ptr;

    original_CalcNumberOfFacesAndVerticesForOppoPathModel(pFace_index_ptr, pVertex_index_ptr);
}

static void(*original_ReallocModelFacesAndVertices)(br_model *, int, int, ...) = (void(*)(br_model *, int, int, ...))0x0040e057;
CARM95_HOOK_FUNCTION(original_ReallocModelFacesAndVertices, ReallocModelFacesAndVertices)
void ReallocModelFacesAndVertices(br_model *pModel, int pNum_faces, int pNum_vertices) {
    br_vertex *new_vertices;
    br_face *new_faces;
    int i;
    LOG_TRACE("(%p, %d, %d)", pModel, pNum_faces, pNum_vertices);

    (void)pModel;
    (void)pNum_faces;
    (void)pNum_vertices;
    (void)new_vertices;
    (void)new_faces;
    (void)i;

    original_ReallocModelFacesAndVertices(pModel, pNum_faces, pNum_vertices);
}

static br_material *(*original_CreateSimpleMaterial)(int, ...) = (br_material *(*)(int, ...))0x0040e3cf;
CARM95_HOOK_FUNCTION(original_CreateSimpleMaterial, CreateSimpleMaterial)
br_material* CreateSimpleMaterial(int pColour_index) {
    br_material *return_me;
    LOG_TRACE("(%d)", pColour_index);

    (void)pColour_index;
    (void)return_me;

    return original_CreateSimpleMaterial(pColour_index);
}

static void(*original_AllocateMatsForOppoPathModel)() = (void(*)())0x0040e2d3;
CARM95_HOOK_FUNCTION(original_AllocateMatsForOppoPathModel, AllocateMatsForOppoPathModel)
void AllocateMatsForOppoPathModel() {
    LOG_TRACE("()");


    original_AllocateMatsForOppoPathModel();
}

static void(*original_RebuildOppoPathModel)() = (void(*)())0x0040d097;
CARM95_HOOK_FUNCTION(original_RebuildOppoPathModel, RebuildOppoPathModel)
void RebuildOppoPathModel() {
    static int nvertices_last_time;
    static int nfaces_last_time;
    int i;
    int at_least_one;
    br_uint_16 nfaces;
    br_uint_16 nvertices;
    br_uint_16 first_face;
    br_uint_16 first_vertex;
    br_material *centre_mat_lt;
    br_material *centre_mat_dk;
    br_material *edge_mat_start_lt;
    br_material *edge_mat_start_dk;
    br_material *edge_mat_finish_lt;
    br_material *edge_mat_finish_dk;
    LOG_TRACE("()");

    (void)nvertices_last_time;
    (void)nfaces_last_time;
    (void)i;
    (void)at_least_one;
    (void)nfaces;
    (void)nvertices;
    (void)first_face;
    (void)first_vertex;
    (void)centre_mat_lt;
    (void)centre_mat_dk;
    (void)edge_mat_start_lt;
    (void)edge_mat_start_dk;
    (void)edge_mat_finish_lt;
    (void)edge_mat_finish_dk;

    original_RebuildOppoPathModel();
}

static int(*original_ConsistencyCheck)() = (int(*)())0x0040e436;
CARM95_HOOK_FUNCTION(original_ConsistencyCheck, ConsistencyCheck)
int ConsistencyCheck() {
    tS16 node_no;
    tS16 section_no;
    tS16 start_node;
    tS16 finish_node;
    tS16 section_no_index;
    tS16 section_no_index1;
    int found_how_many;
    int failed;
    tU8 *nodes_referenced_by_sections_array;
    tU8 *sections_referenced_by_nodes_array;
    LOG_TRACE("()");

    (void)node_no;
    (void)section_no;
    (void)start_node;
    (void)finish_node;
    (void)section_no_index;
    (void)section_no_index1;
    (void)found_how_many;
    (void)failed;
    (void)nodes_referenced_by_sections_array;
    (void)sections_referenced_by_nodes_array;

    return original_ConsistencyCheck();
}

static void(*original_ShowOppoPaths)() = (void(*)())0x0040ed8e;
CARM95_HOOK_FUNCTION(original_ShowOppoPaths, ShowOppoPaths)
void ShowOppoPaths() {
    char str[256];
    LOG_TRACE("()");

    (void)str;

    original_ShowOppoPaths();
}

static void(*original_WriteOutOppoPaths)() = (void(*)())0x0040e9d4;
CARM95_HOOK_FUNCTION(original_WriteOutOppoPaths, WriteOutOppoPaths)
void WriteOutOppoPaths() {
    char the_path[256];
    char str[13];
    FILE *f;
    int i;
    LOG_TRACE("()");

    (void)the_path;
    (void)str;
    (void)f;
    (void)i;

    original_WriteOutOppoPaths();
}

static int(*original_NewNodeOKHere)() = (int(*)())0x0040f42b;
CARM95_HOOK_FUNCTION(original_NewNodeOKHere, NewNodeOKHere)
int NewNodeOKHere() {
    br_vector3 last_node_to_this;
    LOG_TRACE("()");

    (void)last_node_to_this;

    return original_NewNodeOKHere();
}

static void(*original_ShowHideOppoPaths)() = (void(*)())0x0040ed4b;
CARM95_HOOK_FUNCTION(original_ShowHideOppoPaths, ShowHideOppoPaths)
void ShowHideOppoPaths() {
    LOG_TRACE("()");


    original_ShowHideOppoPaths();
}

void DropElasticateyNode() {
    char str[256];
    tS16 old_node;
    tS16 new_node;
    tS16 section_no_index;
    br_scalar distance;
    int all_the_same_type;
    int one_wayness;
    tPath_section_type_enum section_type;
    tPath_section_type_enum original_type;
    LOG_TRACE("()");

    (void)str;
    (void)old_node;
    (void)new_node;
    (void)section_no_index;
    (void)distance;
    (void)all_the_same_type;
    (void)one_wayness;
    (void)section_type;
    (void)original_type;

    NOT_IMPLEMENTED();
}

void InsertAndElasticate() {
    tS16 inserted_node;
    tS16 elasticatey_node;
    tS16 section_no;
    tS16 new_section;
    br_vector3 direction_v;
    br_vector3 intersect;
    br_vector3 wank;
    br_scalar distance;
    int not_perp;
    int one_wayness;
    char str[256];
    tPath_section_type_enum section_type;
    LOG_TRACE("()");

    (void)inserted_node;
    (void)elasticatey_node;
    (void)section_no;
    (void)new_section;
    (void)direction_v;
    (void)intersect;
    (void)wank;
    (void)distance;
    (void)not_perp;
    (void)one_wayness;
    (void)str;
    (void)section_type;

    NOT_IMPLEMENTED();
}

void InsertAndDontElasticate() {
    tS16 inserted_node;
    tS16 section_no;
    br_vector3 direction_v;
    br_vector3 intersect;
    br_vector3 wank;
    br_scalar distance;
    int not_perp;
    char str[256];
    LOG_TRACE("()");

    (void)inserted_node;
    (void)section_no;
    (void)direction_v;
    (void)intersect;
    (void)wank;
    (void)distance;
    (void)not_perp;
    (void)str;

    NOT_IMPLEMENTED();
}

void DropDeadEndNode() {
    char str[256];
    LOG_TRACE("()");

    (void)str;

    NOT_IMPLEMENTED();
}

void DropNodeOnNodeAndStopElasticating() {
    int node_no;
    char str[256];
    br_scalar distance;
    LOG_TRACE("()");

    (void)node_no;
    (void)str;
    (void)distance;

    NOT_IMPLEMENTED();
}

static void(*original_WidenOppoPathSection)() = (void(*)())0x004103c5;
CARM95_HOOK_FUNCTION(original_WidenOppoPathSection, WidenOppoPathSection)
void WidenOppoPathSection() {
    LOG_TRACE("()");


    original_WidenOppoPathSection();
}

static void(*original_NarrowOppoPathSection)() = (void(*)())0x00410573;
CARM95_HOOK_FUNCTION(original_NarrowOppoPathSection, NarrowOppoPathSection)
void NarrowOppoPathSection() {
    LOG_TRACE("()");


    original_NarrowOppoPathSection();
}

static void(*original_IncreaseSectionMinSpeed)() = (void(*)())0x0041059d;
CARM95_HOOK_FUNCTION(original_IncreaseSectionMinSpeed, IncreaseSectionMinSpeed)
void IncreaseSectionMinSpeed() {
    LOG_TRACE("()");


    original_IncreaseSectionMinSpeed();
}

static void(*original_DecreaseSectionMinSpeed)() = (void(*)())0x00410a7f;
CARM95_HOOK_FUNCTION(original_DecreaseSectionMinSpeed, DecreaseSectionMinSpeed)
void DecreaseSectionMinSpeed() {
    LOG_TRACE("()");


    original_DecreaseSectionMinSpeed();
}

static void(*original_IncreaseSectionMaxSpeed)() = (void(*)())0x00410aa8;
CARM95_HOOK_FUNCTION(original_IncreaseSectionMaxSpeed, IncreaseSectionMaxSpeed)
void IncreaseSectionMaxSpeed() {
    LOG_TRACE("()");


    original_IncreaseSectionMaxSpeed();
}

static void(*original_DecreaseSectionMaxSpeed)() = (void(*)())0x00410ad1;
CARM95_HOOK_FUNCTION(original_DecreaseSectionMaxSpeed, DecreaseSectionMaxSpeed)
void DecreaseSectionMaxSpeed() {
    LOG_TRACE("()");


    original_DecreaseSectionMaxSpeed();
}

static void(*original_PullOppoPoint)() = (void(*)())0x00410afa;
CARM95_HOOK_FUNCTION(original_PullOppoPoint, PullOppoPoint)
void PullOppoPoint() {
    tS16 node_no;
    br_scalar distance;
    LOG_TRACE("()");

    (void)node_no;
    (void)distance;

    original_PullOppoPoint();
}

static void(*original_ShowNodeInfo)() = (void(*)())0x00410bfa;
CARM95_HOOK_FUNCTION(original_ShowNodeInfo, ShowNodeInfo)
void ShowNodeInfo() {
    tS16 node_no;
    char str[256];
    br_scalar distance;
    LOG_TRACE("()");

    (void)node_no;
    (void)str;
    (void)distance;

    original_ShowNodeInfo();
}

static void(*original_ShowSectionInfo1)() = (void(*)())0x00410d28;
CARM95_HOOK_FUNCTION(original_ShowSectionInfo1, ShowSectionInfo1)
void ShowSectionInfo1() {
    tS16 section_no;
    char str[256];
    br_scalar distance;
    br_vector3 direction_v;
    br_vector3 intersect;
    LOG_TRACE("()");

    (void)section_no;
    (void)str;
    (void)distance;
    (void)direction_v;
    (void)intersect;

    original_ShowSectionInfo1();
}

static void(*original_ShowSectionInfo2)() = (void(*)())0x00410e9b;
CARM95_HOOK_FUNCTION(original_ShowSectionInfo2, ShowSectionInfo2)
void ShowSectionInfo2() {
    tS16 section_no;
    char str[256];
    br_scalar distance;
    br_vector3 direction_v;
    br_vector3 intersect;
    LOG_TRACE("()");

    (void)section_no;
    (void)str;
    (void)distance;
    (void)direction_v;
    (void)intersect;

    original_ShowSectionInfo2();
}

void DeleteOppoPathSection() {
    br_scalar distance;
    br_vector3 intersect;
    br_vector3 direction_v;
    tS16 section_no;
    LOG_TRACE("()");

    (void)distance;
    (void)intersect;
    (void)direction_v;
    (void)section_no;

    NOT_IMPLEMENTED();
}

static void(*original_DeleteOppoPathNodeAndSections)() = (void(*)())0x00411124;
CARM95_HOOK_FUNCTION(original_DeleteOppoPathNodeAndSections, DeleteOppoPathNodeAndSections)
void DeleteOppoPathNodeAndSections() {
    br_scalar distance;
    tS16 node_no;
    LOG_TRACE("()");

    (void)distance;
    (void)node_no;

    original_DeleteOppoPathNodeAndSections();
}

static void(*original_DeleteOppoPathNodeAndJoin)() = (void(*)())0x004112e2;
CARM95_HOOK_FUNCTION(original_DeleteOppoPathNodeAndJoin, DeleteOppoPathNodeAndJoin)
void DeleteOppoPathNodeAndJoin() {
    br_scalar distance;
    tS16 node_no;
    LOG_TRACE("()");

    (void)distance;
    (void)node_no;

    original_DeleteOppoPathNodeAndJoin();
}

static void(*original_ReverseSectionDirection)() = (void(*)())0x004114dd;
CARM95_HOOK_FUNCTION(original_ReverseSectionDirection, ReverseSectionDirection)
void ReverseSectionDirection() {
    tS16 temp;
    tU8 speed_temp;
    br_scalar distance;
    br_vector3 intersect;
    br_vector3 direction_v;
    tS16 section_no;
    LOG_TRACE("()");

    (void)temp;
    (void)speed_temp;
    (void)distance;
    (void)intersect;
    (void)direction_v;
    (void)section_no;

    original_ReverseSectionDirection();
}

static void(*original_CycleSectionType)() = (void(*)())0x0041169c;
CARM95_HOOK_FUNCTION(original_CycleSectionType, CycleSectionType)
void CycleSectionType() {
    br_scalar distance;
    br_vector3 intersect;
    br_vector3 direction_v;
    tS16 section_no;
    char str[256];
    LOG_TRACE("()");

    (void)distance;
    (void)intersect;
    (void)direction_v;
    (void)section_no;
    (void)str;

    original_CycleSectionType();
}

static void(*original_ToggleOneWayNess)() = (void(*)())0x004117ee;
CARM95_HOOK_FUNCTION(original_ToggleOneWayNess, ToggleOneWayNess)
void ToggleOneWayNess() {
    br_scalar distance;
    br_vector3 intersect;
    br_vector3 direction_v;
    tS16 section_no;
    LOG_TRACE("()");

    (void)distance;
    (void)intersect;
    (void)direction_v;
    (void)section_no;

    original_ToggleOneWayNess();
}

static void(*original_CopStartPointInfo)() = (void(*)())0x00411947;
CARM95_HOOK_FUNCTION(original_CopStartPointInfo, CopStartPointInfo)
void CopStartPointInfo() {
    char str[256];
    int i;
    int closest;
    br_scalar closest_distance;
    br_scalar distance;
    br_vector3 car_to_point;
    LOG_TRACE("()");

    (void)str;
    (void)i;
    (void)closest;
    (void)closest_distance;
    (void)distance;
    (void)car_to_point;

    original_CopStartPointInfo();
}

static void(*original_DropCopStartPoint)() = (void(*)())0x00411ae8;
CARM95_HOOK_FUNCTION(original_DropCopStartPoint, DropCopStartPoint)
void DropCopStartPoint() {
    char str[256];
    LOG_TRACE("()");

    (void)str;

    original_DropCopStartPoint();
}

static void(*original_DeleteCopStartPoint)() = (void(*)())0x00411c18;
CARM95_HOOK_FUNCTION(original_DeleteCopStartPoint, DeleteCopStartPoint)
void DeleteCopStartPoint() {
    char str[256];
    int i;
    int closest;
    br_scalar closest_distance;
    br_scalar distance;
    br_vector3 car_to_point;
    LOG_TRACE("()");

    (void)str;
    (void)i;
    (void)closest;
    (void)closest_distance;
    (void)distance;
    (void)car_to_point;

    original_DeleteCopStartPoint();
}

static void(*original_CycleCopStartPointType)() = (void(*)())0x00411e7f;
CARM95_HOOK_FUNCTION(original_CycleCopStartPointType, CycleCopStartPointType)
void CycleCopStartPointType() {
    LOG_TRACE("()");


    original_CycleCopStartPointType();
}

