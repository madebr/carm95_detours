#include "opponent.h"

#include "harness/trace.h"

#include "carm95_hooks.h"

#include "carm95_webserver.h"

#include <assert.h>
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

function_hook_state_t function_hook_state_PointActorAlongThisBloodyVector = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_PointActorAlongThisBloodyVector)
static void(__cdecl*original_PointActorAlongThisBloodyVector)(br_actor *, br_vector3 *) = (void(__cdecl*)(br_actor *, br_vector3 *))0x00402390;
CARM95_HOOK_FUNCTION(original_PointActorAlongThisBloodyVector, PointActorAlongThisBloodyVector)
void __cdecl PointActorAlongThisBloodyVector(br_actor *pThe_actor, br_vector3 *pThe_vector) {
    br_transform trans;
    LOG_TRACE("(%p, %p)", pThe_actor, pThe_vector);

    (void)pThe_actor;
    (void)pThe_vector;
    (void)trans;

    if (function_hook_state_PointActorAlongThisBloodyVector == HOOK_ENABLED) {
        assert(0 && "PointActorAlongThisBloodyVector not implemented.");
        abort();
    } else {
        original_PointActorAlongThisBloodyVector(pThe_actor, pThe_vector);
    }
}

function_hook_state_t function_hook_state_ProcessCurrentObjective = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_ProcessCurrentObjective)
static void(__cdecl*original_ProcessCurrentObjective)(tOpponent_spec *, tProcess_objective_command) = (void(__cdecl*)(tOpponent_spec *, tProcess_objective_command))0x004065e0;
CARM95_HOOK_FUNCTION(original_ProcessCurrentObjective, ProcessCurrentObjective)
void __cdecl ProcessCurrentObjective(tOpponent_spec *pOpponent_spec, tProcess_objective_command pCommand) {
    LOG_TRACE("(%p, %d)", pOpponent_spec, pCommand);

    (void)pOpponent_spec;
    (void)pCommand;

    if (function_hook_state_ProcessCurrentObjective == HOOK_ENABLED) {
        assert(0 && "ProcessCurrentObjective not implemented.");
        abort();
    } else {
        original_ProcessCurrentObjective(pOpponent_spec, pCommand);
    }
}

function_hook_state_t function_hook_state_ReallocExtraPathNodes = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_ReallocExtraPathNodes)
static tS16(__cdecl*original_ReallocExtraPathNodes)(int) = (tS16(__cdecl*)(int))0x004057a1;
CARM95_HOOK_FUNCTION(original_ReallocExtraPathNodes, ReallocExtraPathNodes)
tS16 __cdecl ReallocExtraPathNodes(int pHow_many_then) {
    tPath_node *new_nodes;
    tS16 first_new_node;
    LOG_TRACE("(%d)", pHow_many_then);

    (void)pHow_many_then;
    (void)new_nodes;
    (void)first_new_node;

    if (function_hook_state_ReallocExtraPathNodes == HOOK_ENABLED) {
        assert(0 && "ReallocExtraPathNodes not implemented.");
        abort();
    } else {
        return original_ReallocExtraPathNodes(pHow_many_then);
    }
}

function_hook_state_t function_hook_state_ReallocExtraPathSections = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_ReallocExtraPathSections)
static tS16(__cdecl*original_ReallocExtraPathSections)(int) = (tS16(__cdecl*)(int))0x00405855;
CARM95_HOOK_FUNCTION(original_ReallocExtraPathSections, ReallocExtraPathSections)
tS16 __cdecl ReallocExtraPathSections(int pHow_many_then) {
    tPath_section *new_sections;
    tS16 first_new_section;
    LOG_TRACE("(%d)", pHow_many_then);

    (void)pHow_many_then;
    (void)new_sections;
    (void)first_new_section;

    if (function_hook_state_ReallocExtraPathSections == HOOK_ENABLED) {
        assert(0 && "ReallocExtraPathSections not implemented.");
        abort();
    } else {
        return original_ReallocExtraPathSections(pHow_many_then);
    }
}

function_hook_state_t function_hook_state_PointVisibleFromHere = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_PointVisibleFromHere)
static int(__cdecl*original_PointVisibleFromHere)(br_vector3 *, br_vector3 *) = (int(__cdecl*)(br_vector3 *, br_vector3 *))0x004063ac;
CARM95_HOOK_FUNCTION(original_PointVisibleFromHere, PointVisibleFromHere)
int __cdecl PointVisibleFromHere(br_vector3 *pFrom, br_vector3 *pTo) {
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

    if (function_hook_state_PointVisibleFromHere == HOOK_ENABLED) {
        assert(0 && "PointVisibleFromHere not implemented.");
        abort();
    } else {
        return original_PointVisibleFromHere(pFrom, pTo);
    }
}

function_hook_state_t function_hook_state_FindNearestPathNode = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_FindNearestPathNode)
static tS16(__cdecl*original_FindNearestPathNode)(br_vector3 *, br_scalar *) = (tS16(__cdecl*)(br_vector3 *, br_scalar *))0x0040f331;
CARM95_HOOK_FUNCTION(original_FindNearestPathNode, FindNearestPathNode)
tS16 __cdecl FindNearestPathNode(br_vector3 *pActor_coords, br_scalar *pDistance) {
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

    if (function_hook_state_FindNearestPathNode == HOOK_ENABLED) {
        assert(0 && "FindNearestPathNode not implemented.");
        abort();
    } else {
        return original_FindNearestPathNode(pActor_coords, pDistance);
    }
}

function_hook_state_t function_hook_state_FindNearestPathSection = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_FindNearestPathSection)
static tS16(__cdecl*original_FindNearestPathSection)(br_vector3 *, br_vector3 *, br_vector3 *, br_scalar *) = (tS16(__cdecl*)(br_vector3 *, br_vector3 *, br_vector3 *, br_scalar *))0x0040294b;
CARM95_HOOK_FUNCTION(original_FindNearestPathSection, FindNearestPathSection)
tS16 __cdecl FindNearestPathSection(br_vector3 *pActor_coords, br_vector3 *pPath_direction, br_vector3 *pIntersect, br_scalar *pDistance) {
    LOG_TRACE("(%p, %p, %p, %p)", pActor_coords, pPath_direction, pIntersect, pDistance);

    (void)pActor_coords;
    (void)pPath_direction;
    (void)pIntersect;
    (void)pDistance;

    if (function_hook_state_FindNearestPathSection == HOOK_ENABLED) {
        assert(0 && "FindNearestPathSection not implemented.");
        abort();
    } else {
        return original_FindNearestPathSection(pActor_coords, pPath_direction, pIntersect, pDistance);
    }
}

function_hook_state_t function_hook_state_FindNearestGeneralSection = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_FindNearestGeneralSection)
static tS16(__cdecl*original_FindNearestGeneralSection)(tCar_spec *, br_vector3 *, br_vector3 *, br_vector3 *, br_scalar *) = (tS16(__cdecl*)(tCar_spec *, br_vector3 *, br_vector3 *, br_vector3 *, br_scalar *))0x00402975;
CARM95_HOOK_FUNCTION(original_FindNearestGeneralSection, FindNearestGeneralSection)
tS16 __cdecl FindNearestGeneralSection(tCar_spec *pPursuee, br_vector3 *pActor_coords, br_vector3 *pPath_direction, br_vector3 *pIntersect, br_scalar *pDistance) {
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
    (void)__block0___scale;
    (void)__block1___scale;

    if (function_hook_state_FindNearestGeneralSection == HOOK_ENABLED) {
        assert(0 && "FindNearestGeneralSection not implemented.");
        abort();
    } else {
        return original_FindNearestGeneralSection(pPursuee, pActor_coords, pPath_direction, pIntersect, pDistance);
    }
}

function_hook_state_t function_hook_state_DeadStopCar = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_DeadStopCar)
static void(__cdecl*original_DeadStopCar)(tCar_spec *) = (void(__cdecl*)(tCar_spec *))0x00402481;
CARM95_HOOK_FUNCTION(original_DeadStopCar, DeadStopCar)
void __cdecl DeadStopCar(tCar_spec *pCar_spec) {
    LOG_TRACE("(%p)", pCar_spec);

    (void)pCar_spec;

    if (function_hook_state_DeadStopCar == HOOK_ENABLED) {
        assert(0 && "DeadStopCar not implemented.");
        abort();
    } else {
        original_DeadStopCar(pCar_spec);
    }
}

function_hook_state_t function_hook_state_TurnOpponentPhysicsOn = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_TurnOpponentPhysicsOn)
static void(__cdecl*original_TurnOpponentPhysicsOn)(tOpponent_spec *) = (void(__cdecl*)(tOpponent_spec *))0x00402401;
CARM95_HOOK_FUNCTION(original_TurnOpponentPhysicsOn, TurnOpponentPhysicsOn)
void __cdecl TurnOpponentPhysicsOn(tOpponent_spec *pOpponent_spec) {
    LOG_TRACE("(%p)", pOpponent_spec);

    (void)pOpponent_spec;

    if (function_hook_state_TurnOpponentPhysicsOn == HOOK_ENABLED) {
        assert(0 && "TurnOpponentPhysicsOn not implemented.");
        abort();
    } else {
        original_TurnOpponentPhysicsOn(pOpponent_spec);
    }
}

function_hook_state_t function_hook_state_TurnOpponentPhysicsOff = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_TurnOpponentPhysicsOff)
static void(__cdecl*original_TurnOpponentPhysicsOff)(tOpponent_spec *) = (void(__cdecl*)(tOpponent_spec *))0x0040243f;
CARM95_HOOK_FUNCTION(original_TurnOpponentPhysicsOff, TurnOpponentPhysicsOff)
void __cdecl TurnOpponentPhysicsOff(tOpponent_spec *pOpponent_spec) {
    LOG_TRACE("(%p)", pOpponent_spec);

    (void)pOpponent_spec;

    if (function_hook_state_TurnOpponentPhysicsOff == HOOK_ENABLED) {
        assert(0 && "TurnOpponentPhysicsOff not implemented.");
        abort();
    } else {
        original_TurnOpponentPhysicsOff(pOpponent_spec);
    }
}

function_hook_state_t function_hook_state_NewObjective = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_NewObjective)
void(__cdecl*NewObjective)(tOpponent_spec *, tOpponent_objective_type) = (void(__cdecl*)(tOpponent_spec *, tOpponent_objective_type))0x0040694d;
void NewObjective_do_not_use(tOpponent_spec *pOpponent_spec, tOpponent_objective_type pObjective_type) {
    va_list marker;
    LOG_TRACE("(%p, %d)", pOpponent_spec, pObjective_type);

    (void)pOpponent_spec;
    (void)pObjective_type;
    (void)marker;

    if (function_hook_state_NewObjective == HOOK_ENABLED) {
        assert(0 && "NewObjective_do_not_use not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}

function_hook_state_t function_hook_state_CalcRaceRoute = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_CalcRaceRoute)
static void(__cdecl*original_CalcRaceRoute)(tOpponent_spec *) = (void(__cdecl*)(tOpponent_spec *))0x00402512;
CARM95_HOOK_FUNCTION(original_CalcRaceRoute, CalcRaceRoute)
void __cdecl CalcRaceRoute(tOpponent_spec *pOpponent_spec) {
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

    if (function_hook_state_CalcRaceRoute == HOOK_ENABLED) {
        assert(0 && "CalcRaceRoute not implemented.");
        abort();
    } else {
        original_CalcRaceRoute(pOpponent_spec);
    }
}

function_hook_state_t function_hook_state_TopUpRandomRoute = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_TopUpRandomRoute)
static void(__cdecl*original_TopUpRandomRoute)(tOpponent_spec *, int) = (void(__cdecl*)(tOpponent_spec *, int))0x00402e11;
CARM95_HOOK_FUNCTION(original_TopUpRandomRoute, TopUpRandomRoute)
void __cdecl TopUpRandomRoute(tOpponent_spec *pOpponent_spec, int pSections_to_add) {
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

    if (function_hook_state_TopUpRandomRoute == HOOK_ENABLED) {
        assert(0 && "TopUpRandomRoute not implemented.");
        abort();
    } else {
        original_TopUpRandomRoute(pOpponent_spec, pSections_to_add);
    }
}

function_hook_state_t function_hook_state_SearchForSection = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_SearchForSection)
static int(__cdecl*original_SearchForSection)(tRoute_section *, tRoute_section *, int *, tS16, int, br_scalar, tOpponent_spec *) = (int(__cdecl*)(tRoute_section *, tRoute_section *, int *, tS16, int, br_scalar, tOpponent_spec *))0x00407f5d;
CARM95_HOOK_FUNCTION(original_SearchForSection, SearchForSection)
int __cdecl SearchForSection(tRoute_section *pTemp_store, tRoute_section *pPerm_store, int *pNum_of_perm_store_sections, tS16 pTarget_section, int pDepth, br_scalar pDistance_so_far, tOpponent_spec *pOpponent_spec) {
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

    if (function_hook_state_SearchForSection == HOOK_ENABLED) {
        assert(0 && "SearchForSection not implemented.");
        abort();
    } else {
        return original_SearchForSection(pTemp_store, pPerm_store, pNum_of_perm_store_sections, pTarget_section, pDepth, pDistance_so_far, pOpponent_spec);
    }
}

function_hook_state_t function_hook_state_CalcGetNearPlayerRoute = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_CalcGetNearPlayerRoute)
static void(__cdecl*original_CalcGetNearPlayerRoute)(tOpponent_spec *, tCar_spec *) = (void(__cdecl*)(tOpponent_spec *, tCar_spec *))0x004089bf;
CARM95_HOOK_FUNCTION(original_CalcGetNearPlayerRoute, CalcGetNearPlayerRoute)
void __cdecl CalcGetNearPlayerRoute(tOpponent_spec *pOpponent_spec, tCar_spec *pPlayer) {
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

    if (function_hook_state_CalcGetNearPlayerRoute == HOOK_ENABLED) {
        assert(0 && "CalcGetNearPlayerRoute not implemented.");
        abort();
    } else {
        original_CalcGetNearPlayerRoute(pOpponent_spec, pPlayer);
    }
}

function_hook_state_t function_hook_state_CalcReturnToStartPointRoute = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_CalcReturnToStartPointRoute)
static void(__cdecl*original_CalcReturnToStartPointRoute)(tOpponent_spec *) = (void(__cdecl*)(tOpponent_spec *))0x00407d1e;
CARM95_HOOK_FUNCTION(original_CalcReturnToStartPointRoute, CalcReturnToStartPointRoute)
void __cdecl CalcReturnToStartPointRoute(tOpponent_spec *pOpponent_spec) {
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
    (void)__block0___scale;

    if (function_hook_state_CalcReturnToStartPointRoute == HOOK_ENABLED) {
        assert(0 && "CalcReturnToStartPointRoute not implemented.");
        abort();
    } else {
        original_CalcReturnToStartPointRoute(pOpponent_spec);
    }
}

function_hook_state_t function_hook_state_ClearOpponentsProjectedRoute = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_ClearOpponentsProjectedRoute)
static void(__cdecl*original_ClearOpponentsProjectedRoute)(tOpponent_spec *) = (void(__cdecl*)(tOpponent_spec *))0x00404684;
CARM95_HOOK_FUNCTION(original_ClearOpponentsProjectedRoute, ClearOpponentsProjectedRoute)
void __cdecl ClearOpponentsProjectedRoute(tOpponent_spec *pOpponent_spec) {
    LOG_TRACE("(%p)", pOpponent_spec);

    (void)pOpponent_spec;

    if (function_hook_state_ClearOpponentsProjectedRoute == HOOK_ENABLED) {
        assert(0 && "ClearOpponentsProjectedRoute not implemented.");
        abort();
    } else {
        original_ClearOpponentsProjectedRoute(pOpponent_spec);
    }
}

function_hook_state_t function_hook_state_AddToOpponentsProjectedRoute = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_AddToOpponentsProjectedRoute)
static int(__cdecl*original_AddToOpponentsProjectedRoute)(tOpponent_spec *, tS16, int) = (int(__cdecl*)(tOpponent_spec *, tS16, int))0x004030ef;
CARM95_HOOK_FUNCTION(original_AddToOpponentsProjectedRoute, AddToOpponentsProjectedRoute)
int __cdecl AddToOpponentsProjectedRoute(tOpponent_spec *pOpponent_spec, tS16 pSection_no, int pDirection) {
    LOG_TRACE("(%p, %d, %d)", pOpponent_spec, pSection_no, pDirection);

    (void)pOpponent_spec;
    (void)pSection_no;
    (void)pDirection;

    if (function_hook_state_AddToOpponentsProjectedRoute == HOOK_ENABLED) {
        assert(0 && "AddToOpponentsProjectedRoute not implemented.");
        abort();
    } else {
        return original_AddToOpponentsProjectedRoute(pOpponent_spec, pSection_no, pDirection);
    }
}

function_hook_state_t function_hook_state_ShiftOpponentsProjectedRoute = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_ShiftOpponentsProjectedRoute)
static int(__cdecl*original_ShiftOpponentsProjectedRoute)(tOpponent_spec *, int) = (int(__cdecl*)(tOpponent_spec *, int))0x00404699;
CARM95_HOOK_FUNCTION(original_ShiftOpponentsProjectedRoute, ShiftOpponentsProjectedRoute)
int __cdecl ShiftOpponentsProjectedRoute(tOpponent_spec *pOpponent_spec, int pPlaces) {
    int i;
    LOG_TRACE("(%p, %d)", pOpponent_spec, pPlaces);

    (void)pOpponent_spec;
    (void)pPlaces;
    (void)i;

    if (function_hook_state_ShiftOpponentsProjectedRoute == HOOK_ENABLED) {
        assert(0 && "ShiftOpponentsProjectedRoute not implemented.");
        abort();
    } else {
        return original_ShiftOpponentsProjectedRoute(pOpponent_spec, pPlaces);
    }
}

function_hook_state_t function_hook_state_StunTheBugger = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_StunTheBugger)
static void(__cdecl*original_StunTheBugger)(tOpponent_spec *, int) = (void(__cdecl*)(tOpponent_spec *, int))0x0040b12d;
CARM95_HOOK_FUNCTION(original_StunTheBugger, StunTheBugger)
void __cdecl StunTheBugger(tOpponent_spec *pOpponent_spec, int pMilliseconds) {
    LOG_TRACE("(%p, %d)", pOpponent_spec, pMilliseconds);

    (void)pOpponent_spec;
    (void)pMilliseconds;

    if (function_hook_state_StunTheBugger == HOOK_ENABLED) {
        assert(0 && "StunTheBugger not implemented.");
        abort();
    } else {
        original_StunTheBugger(pOpponent_spec, pMilliseconds);
    }
}

function_hook_state_t function_hook_state_UnStunTheBugger = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_UnStunTheBugger)
static void(__cdecl*original_UnStunTheBugger)(tOpponent_spec *) = (void(__cdecl*)(tOpponent_spec *))0x00405e44;
CARM95_HOOK_FUNCTION(original_UnStunTheBugger, UnStunTheBugger)
void __cdecl UnStunTheBugger(tOpponent_spec *pOpponent_spec) {
    LOG_TRACE("(%p)", pOpponent_spec);

    (void)pOpponent_spec;

    if (function_hook_state_UnStunTheBugger == HOOK_ENABLED) {
        assert(0 && "UnStunTheBugger not implemented.");
        abort();
    } else {
        original_UnStunTheBugger(pOpponent_spec);
    }
}

function_hook_state_t function_hook_state_ProcessCompleteRace = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_ProcessCompleteRace)
static void(__cdecl*original_ProcessCompleteRace)(tOpponent_spec *, tProcess_objective_command) = (void(__cdecl*)(tOpponent_spec *, tProcess_objective_command))0x00406732;
CARM95_HOOK_FUNCTION(original_ProcessCompleteRace, ProcessCompleteRace)
void __cdecl ProcessCompleteRace(tOpponent_spec *pOpponent_spec, tProcess_objective_command pCommand) {
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

    if (function_hook_state_ProcessCompleteRace == HOOK_ENABLED) {
        assert(0 && "ProcessCompleteRace not implemented.");
        abort();
    } else {
        original_ProcessCompleteRace(pOpponent_spec, pCommand);
    }
}

function_hook_state_t function_hook_state_StartRecordingTrail = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_StartRecordingTrail)
static void(__cdecl*original_StartRecordingTrail)(tCar_spec *) = (void(__cdecl*)(tCar_spec *))0x00405e59;
CARM95_HOOK_FUNCTION(original_StartRecordingTrail, StartRecordingTrail)
void __cdecl StartRecordingTrail(tCar_spec *pPursuee) {
    int i;
    LOG_TRACE("(%p)", pPursuee);

    (void)pPursuee;
    (void)i;

    if (function_hook_state_StartRecordingTrail == HOOK_ENABLED) {
        assert(0 && "StartRecordingTrail not implemented.");
        abort();
    } else {
        original_StartRecordingTrail(pPursuee);
    }
}

function_hook_state_t function_hook_state_RecordNextTrailNode = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_RecordNextTrailNode)
static void(__cdecl*original_RecordNextTrailNode)(tCar_spec *) = (void(__cdecl*)(tCar_spec *))0x00405f97;
CARM95_HOOK_FUNCTION(original_RecordNextTrailNode, RecordNextTrailNode)
void __cdecl RecordNextTrailNode(tCar_spec *pPursuee) {
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

    if (function_hook_state_RecordNextTrailNode == HOOK_ENABLED) {
        assert(0 && "RecordNextTrailNode not implemented.");
        abort();
    } else {
        original_RecordNextTrailNode(pPursuee);
    }
}

function_hook_state_t function_hook_state_FindNearestTrailSection = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_FindNearestTrailSection)
static tS16(__cdecl*original_FindNearestTrailSection)(tOpponent_spec *, tCar_spec *, br_vector3 *, br_vector3 *, br_scalar *) = (tS16(__cdecl*)(tOpponent_spec *, tCar_spec *, br_vector3 *, br_vector3 *, br_scalar *))0x0040769d;
CARM95_HOOK_FUNCTION(original_FindNearestTrailSection, FindNearestTrailSection)
tS16 __cdecl FindNearestTrailSection(tOpponent_spec *pOpponent_spec, tCar_spec *pPursuee, br_vector3 *pSection_v, br_vector3 *pIntersect, br_scalar *pDistance) {
    LOG_TRACE("(%p, %p, %p, %p, %p)", pOpponent_spec, pPursuee, pSection_v, pIntersect, pDistance);

    (void)pOpponent_spec;
    (void)pPursuee;
    (void)pSection_v;
    (void)pIntersect;
    (void)pDistance;

    if (function_hook_state_FindNearestTrailSection == HOOK_ENABLED) {
        assert(0 && "FindNearestTrailSection not implemented.");
        abort();
    } else {
        return original_FindNearestTrailSection(pOpponent_spec, pPursuee, pSection_v, pIntersect, pDistance);
    }
}

function_hook_state_t function_hook_state_CalcNextTrailSection = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_CalcNextTrailSection)
static tS16(__cdecl*original_CalcNextTrailSection)(tOpponent_spec *, int) = (tS16(__cdecl*)(tOpponent_spec *, int))0x00403145;
CARM95_HOOK_FUNCTION(original_CalcNextTrailSection, CalcNextTrailSection)
tS16 __cdecl CalcNextTrailSection(tOpponent_spec *pOpponent_spec, int pSection) {
    int section_no;
    tPursuee_trail *trail;
    LOG_TRACE("(%p, %d)", pOpponent_spec, pSection);

    (void)pOpponent_spec;
    (void)pSection;
    (void)section_no;
    (void)trail;

    if (function_hook_state_CalcNextTrailSection == HOOK_ENABLED) {
        assert(0 && "CalcNextTrailSection not implemented.");
        abort();
    } else {
        return original_CalcNextTrailSection(pOpponent_spec, pSection);
    }
}

function_hook_state_t function_hook_state_ProcessPursueAndTwat = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_ProcessPursueAndTwat)
static void(__cdecl*original_ProcessPursueAndTwat)(tOpponent_spec *, tProcess_objective_command) = (void(__cdecl*)(tOpponent_spec *, tProcess_objective_command))0x00406a69;
CARM95_HOOK_FUNCTION(original_ProcessPursueAndTwat, ProcessPursueAndTwat)
void __cdecl ProcessPursueAndTwat(tOpponent_spec *pOpponent_spec, tProcess_objective_command pCommand) {
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

    if (function_hook_state_ProcessPursueAndTwat == HOOK_ENABLED) {
        assert(0 && "ProcessPursueAndTwat not implemented.");
        abort();
    } else {
        original_ProcessPursueAndTwat(pOpponent_spec, pCommand);
    }
}

function_hook_state_t function_hook_state_ProcessRunAway = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_ProcessRunAway)
static void(__cdecl*original_ProcessRunAway)(tOpponent_spec *, tProcess_objective_command) = (void(__cdecl*)(tOpponent_spec *, tProcess_objective_command))0x004076d2;
CARM95_HOOK_FUNCTION(original_ProcessRunAway, ProcessRunAway)
void __cdecl ProcessRunAway(tOpponent_spec *pOpponent_spec, tProcess_objective_command pCommand) {
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

    if (function_hook_state_ProcessRunAway == HOOK_ENABLED) {
        assert(0 && "ProcessRunAway not implemented.");
        abort();
    } else {
        original_ProcessRunAway(pOpponent_spec, pCommand);
    }
}

function_hook_state_t function_hook_state_ProcessWaitForSomeHaplessSod = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_ProcessWaitForSomeHaplessSod)
static void(__cdecl*original_ProcessWaitForSomeHaplessSod)(tOpponent_spec *, tProcess_objective_command) = (void(__cdecl*)(tOpponent_spec *, tProcess_objective_command))0x004079da;
CARM95_HOOK_FUNCTION(original_ProcessWaitForSomeHaplessSod, ProcessWaitForSomeHaplessSod)
void __cdecl ProcessWaitForSomeHaplessSod(tOpponent_spec *pOpponent_spec, tProcess_objective_command pCommand) {
    LOG_TRACE("(%p, %d)", pOpponent_spec, pCommand);

    (void)pOpponent_spec;
    (void)pCommand;

    if (function_hook_state_ProcessWaitForSomeHaplessSod == HOOK_ENABLED) {
        assert(0 && "ProcessWaitForSomeHaplessSod not implemented.");
        abort();
    } else {
        original_ProcessWaitForSomeHaplessSod(pOpponent_spec, pCommand);
    }
}

function_hook_state_t function_hook_state_ProcessReturnToStart = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_ProcessReturnToStart)
static void(__cdecl*original_ProcessReturnToStart)(tOpponent_spec *, tProcess_objective_command) = (void(__cdecl*)(tOpponent_spec *, tProcess_objective_command))0x00407a66;
CARM95_HOOK_FUNCTION(original_ProcessReturnToStart, ProcessReturnToStart)
void __cdecl ProcessReturnToStart(tOpponent_spec *pOpponent_spec, tProcess_objective_command pCommand) {
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

    if (function_hook_state_ProcessReturnToStart == HOOK_ENABLED) {
        assert(0 && "ProcessReturnToStart not implemented.");
        abort();
    } else {
        original_ProcessReturnToStart(pOpponent_spec, pCommand);
    }
}

function_hook_state_t function_hook_state_ProcessLevitate = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_ProcessLevitate)
static void(__cdecl*original_ProcessLevitate)(tOpponent_spec *, tProcess_objective_command) = (void(__cdecl*)(tOpponent_spec *, tProcess_objective_command))0x00408349;
CARM95_HOOK_FUNCTION(original_ProcessLevitate, ProcessLevitate)
void __cdecl ProcessLevitate(tOpponent_spec *pOpponent_spec, tProcess_objective_command pCommand) {
    float t;
    float terminal_time;
    float y;
    LOG_TRACE("(%p, %d)", pOpponent_spec, pCommand);

    (void)pOpponent_spec;
    (void)pCommand;
    (void)t;
    (void)terminal_time;
    (void)y;

    if (function_hook_state_ProcessLevitate == HOOK_ENABLED) {
        assert(0 && "ProcessLevitate not implemented.");
        abort();
    } else {
        original_ProcessLevitate(pOpponent_spec, pCommand);
    }
}

function_hook_state_t function_hook_state_ProcessGetNearPlayer = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_ProcessGetNearPlayer)
static void(__cdecl*original_ProcessGetNearPlayer)(tOpponent_spec *, tProcess_objective_command) = (void(__cdecl*)(tOpponent_spec *, tProcess_objective_command))0x004086fe;
CARM95_HOOK_FUNCTION(original_ProcessGetNearPlayer, ProcessGetNearPlayer)
void __cdecl ProcessGetNearPlayer(tOpponent_spec *pOpponent_spec, tProcess_objective_command pCommand) {
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

    if (function_hook_state_ProcessGetNearPlayer == HOOK_ENABLED) {
        assert(0 && "ProcessGetNearPlayer not implemented.");
        abort();
    } else {
        original_ProcessGetNearPlayer(pOpponent_spec, pCommand);
    }
}

function_hook_state_t function_hook_state_ProcessFrozen = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_ProcessFrozen)
static void(__cdecl*original_ProcessFrozen)(tOpponent_spec *, tProcess_objective_command) = (void(__cdecl*)(tOpponent_spec *, tProcess_objective_command))0x00408d47;
CARM95_HOOK_FUNCTION(original_ProcessFrozen, ProcessFrozen)
void __cdecl ProcessFrozen(tOpponent_spec *pOpponent_spec, tProcess_objective_command pCommand) {
    LOG_TRACE("(%p, %d)", pOpponent_spec, pCommand);

    (void)pOpponent_spec;
    (void)pCommand;

    if (function_hook_state_ProcessFrozen == HOOK_ENABLED) {
        assert(0 && "ProcessFrozen not implemented.");
        abort();
    } else {
        original_ProcessFrozen(pOpponent_spec, pCommand);
    }
}

function_hook_state_t function_hook_state_HeadOnWithPlayerPossible = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_HeadOnWithPlayerPossible)
static int(__cdecl*original_HeadOnWithPlayerPossible)(tOpponent_spec *) = (int(__cdecl*)(tOpponent_spec *))0x00409cd5;
CARM95_HOOK_FUNCTION(original_HeadOnWithPlayerPossible, HeadOnWithPlayerPossible)
int __cdecl HeadOnWithPlayerPossible(tOpponent_spec *pOpponent_spec) {
    br_vector3 oppo_to_player_norm;
    br_scalar __block0___scale;
    LOG_TRACE("(%p)", pOpponent_spec);

    (void)pOpponent_spec;
    (void)oppo_to_player_norm;
    (void)__block0___scale;

    if (function_hook_state_HeadOnWithPlayerPossible == HOOK_ENABLED) {
        assert(0 && "HeadOnWithPlayerPossible not implemented.");
        abort();
    } else {
        return original_HeadOnWithPlayerPossible(pOpponent_spec);
    }
}

function_hook_state_t function_hook_state_AlreadyPursuingCar = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_AlreadyPursuingCar)
static int(__cdecl*original_AlreadyPursuingCar)(tOpponent_spec *, tCar_spec *) = (int(__cdecl*)(tOpponent_spec *, tCar_spec *))0x00409e29;
CARM95_HOOK_FUNCTION(original_AlreadyPursuingCar, AlreadyPursuingCar)
int __cdecl AlreadyPursuingCar(tOpponent_spec *pOpponent_spec, tCar_spec *pPursuee) {
    LOG_TRACE("(%p, %p)", pOpponent_spec, pPursuee);

    (void)pOpponent_spec;
    (void)pPursuee;

    if (function_hook_state_AlreadyPursuingCar == HOOK_ENABLED) {
        assert(0 && "AlreadyPursuingCar not implemented.");
        abort();
    } else {
        return original_AlreadyPursuingCar(pOpponent_spec, pPursuee);
    }
}

function_hook_state_t function_hook_state_LastTwatteeAPlayer = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_LastTwatteeAPlayer)
static int(__cdecl*original_LastTwatteeAPlayer)(tOpponent_spec *) = (int(__cdecl*)(tOpponent_spec *))0x00409e64;
CARM95_HOOK_FUNCTION(original_LastTwatteeAPlayer, LastTwatteeAPlayer)
int __cdecl LastTwatteeAPlayer(tOpponent_spec *pOpponent_spec) {
    LOG_TRACE("(%p)", pOpponent_spec);

    (void)pOpponent_spec;

    if (function_hook_state_LastTwatteeAPlayer == HOOK_ENABLED) {
        assert(0 && "LastTwatteeAPlayer not implemented.");
        abort();
    } else {
        return original_LastTwatteeAPlayer(pOpponent_spec);
    }
}

function_hook_state_t function_hook_state_LastTwatterAPlayer = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_LastTwatterAPlayer)
static int(__cdecl*original_LastTwatterAPlayer)(tOpponent_spec *) = (int(__cdecl*)(tOpponent_spec *))0x00409ea9;
CARM95_HOOK_FUNCTION(original_LastTwatterAPlayer, LastTwatterAPlayer)
int __cdecl LastTwatterAPlayer(tOpponent_spec *pOpponent_spec) {
    LOG_TRACE("(%p)", pOpponent_spec);

    (void)pOpponent_spec;

    if (function_hook_state_LastTwatterAPlayer == HOOK_ENABLED) {
        assert(0 && "LastTwatterAPlayer not implemented.");
        abort();
    } else {
        return original_LastTwatterAPlayer(pOpponent_spec);
    }
}

function_hook_state_t function_hook_state_ObjectiveComplete = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_ObjectiveComplete)
static void(__cdecl*original_ObjectiveComplete)(tOpponent_spec *) = (void(__cdecl*)(tOpponent_spec *))0x00408e2d;
CARM95_HOOK_FUNCTION(original_ObjectiveComplete, ObjectiveComplete)
void __cdecl ObjectiveComplete(tOpponent_spec *pOpponent_spec) {
    LOG_TRACE("(%p)", pOpponent_spec);

    (void)pOpponent_spec;

    if (function_hook_state_ObjectiveComplete == HOOK_ENABLED) {
        assert(0 && "ObjectiveComplete not implemented.");
        abort();
    } else {
        original_ObjectiveComplete(pOpponent_spec);
    }
}

function_hook_state_t function_hook_state_TeleportOpponentToNearestSafeLocation = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_TeleportOpponentToNearestSafeLocation)
static void(__cdecl*original_TeleportOpponentToNearestSafeLocation)(tOpponent_spec *) = (void(__cdecl*)(tOpponent_spec *))0x00404464;
CARM95_HOOK_FUNCTION(original_TeleportOpponentToNearestSafeLocation, TeleportOpponentToNearestSafeLocation)
void __cdecl TeleportOpponentToNearestSafeLocation(tOpponent_spec *pOpponent_spec) {
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

    if (function_hook_state_TeleportOpponentToNearestSafeLocation == HOOK_ENABLED) {
        assert(0 && "TeleportOpponentToNearestSafeLocation not implemented.");
        abort();
    } else {
        original_TeleportOpponentToNearestSafeLocation(pOpponent_spec);
    }
}

function_hook_state_t function_hook_state_ChooseNewObjective = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_ChooseNewObjective)
static void(__cdecl*original_ChooseNewObjective)(tOpponent_spec *, int) = (void(__cdecl*)(tOpponent_spec *, int))0x00408ec5;
CARM95_HOOK_FUNCTION(original_ChooseNewObjective, ChooseNewObjective)
void __cdecl ChooseNewObjective(tOpponent_spec *pOpponent_spec, int pMust_choose_one) {
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

    if (function_hook_state_ChooseNewObjective == HOOK_ENABLED) {
        assert(0 && "ChooseNewObjective not implemented.");
        abort();
    } else {
        original_ChooseNewObjective(pOpponent_spec, pMust_choose_one);
    }
}

function_hook_state_t function_hook_state_ProcessThisOpponent = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_ProcessThisOpponent)
static void(__cdecl*original_ProcessThisOpponent)(tOpponent_spec *) = (void(__cdecl*)(tOpponent_spec *))0x00406458;
CARM95_HOOK_FUNCTION(original_ProcessThisOpponent, ProcessThisOpponent)
void __cdecl ProcessThisOpponent(tOpponent_spec *pOpponent_spec) {
    int i;
    LOG_TRACE("(%p)", pOpponent_spec);

    (void)pOpponent_spec;
    (void)i;

    if (function_hook_state_ProcessThisOpponent == HOOK_ENABLED) {
        assert(0 && "ProcessThisOpponent not implemented.");
        abort();
    } else {
        original_ProcessThisOpponent(pOpponent_spec);
    }
}

function_hook_state_t function_hook_state_IsNetCarActive = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_IsNetCarActive)
static int(__cdecl*original_IsNetCarActive)(br_vector3 *) = (int(__cdecl*)(br_vector3 *))0x004034b7;
CARM95_HOOK_FUNCTION(original_IsNetCarActive, IsNetCarActive)
int __cdecl IsNetCarActive(br_vector3 *pPoint) {
    br_vector3 tv;
    LOG_TRACE("(%p)", pPoint);

    (void)pPoint;
    (void)tv;

    if (function_hook_state_IsNetCarActive == HOOK_ENABLED) {
        assert(0 && "IsNetCarActive not implemented.");
        abort();
    } else {
        return original_IsNetCarActive(pPoint);
    }
}

function_hook_state_t function_hook_state_RebuildActiveCarList = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_RebuildActiveCarList)
static void(__cdecl*original_RebuildActiveCarList)() = (void(__cdecl*)())0x004031c3;
CARM95_HOOK_FUNCTION(original_RebuildActiveCarList, RebuildActiveCarList)
void __cdecl RebuildActiveCarList() {
    int i;
    tCar_spec *car_spec;
    LOG_TRACE("()");

    (void)i;
    (void)car_spec;

    if (function_hook_state_RebuildActiveCarList == HOOK_ENABLED) {
        assert(0 && "RebuildActiveCarList not implemented.");
        abort();
    } else {
        original_RebuildActiveCarList();
    }
}

function_hook_state_t function_hook_state_ForceRebuildActiveCarList = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_ForceRebuildActiveCarList)
static void(__cdecl*original_ForceRebuildActiveCarList)() = (void(__cdecl*)())0x0040319c;
CARM95_HOOK_FUNCTION(original_ForceRebuildActiveCarList, ForceRebuildActiveCarList)
void __cdecl ForceRebuildActiveCarList() {
    LOG_TRACE("()");


    if (function_hook_state_ForceRebuildActiveCarList == HOOK_ENABLED) {
        assert(0 && "ForceRebuildActiveCarList not implemented.");
        abort();
    } else {
        original_ForceRebuildActiveCarList();
    }
}

function_hook_state_t function_hook_state_StartToCheat = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_StartToCheat)
static void(__cdecl*original_StartToCheat)(tOpponent_spec *) = (void(__cdecl*)(tOpponent_spec *))0x00409eee;
CARM95_HOOK_FUNCTION(original_StartToCheat, StartToCheat)
void __cdecl StartToCheat(tOpponent_spec *pOpponent_spec) {
    LOG_TRACE("(%p)", pOpponent_spec);

    (void)pOpponent_spec;

    if (function_hook_state_StartToCheat == HOOK_ENABLED) {
        assert(0 && "StartToCheat not implemented.");
        abort();
    } else {
        original_StartToCheat(pOpponent_spec);
    }
}

function_hook_state_t function_hook_state_OiStopCheating = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_OiStopCheating)
static void(__cdecl*original_OiStopCheating)(tOpponent_spec *) = (void(__cdecl*)(tOpponent_spec *))0x00409f78;
CARM95_HOOK_FUNCTION(original_OiStopCheating, OiStopCheating)
void __cdecl OiStopCheating(tOpponent_spec *pOpponent_spec) {
    LOG_TRACE("(%p)", pOpponent_spec);

    (void)pOpponent_spec;

    if (function_hook_state_OiStopCheating == HOOK_ENABLED) {
        assert(0 && "OiStopCheating not implemented.");
        abort();
    } else {
        original_OiStopCheating(pOpponent_spec);
    }
}

function_hook_state_t function_hook_state_TeleportCopToStart = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_TeleportCopToStart)
static int(__cdecl*original_TeleportCopToStart)(tOpponent_spec *) = (int(__cdecl*)(tOpponent_spec *))0x00409ff7;
CARM95_HOOK_FUNCTION(original_TeleportCopToStart, TeleportCopToStart)
int __cdecl TeleportCopToStart(tOpponent_spec *pOpponent_spec) {
    br_vector3 wank;
    LOG_TRACE("(%p)", pOpponent_spec);

    (void)pOpponent_spec;
    (void)wank;

    if (function_hook_state_TeleportCopToStart == HOOK_ENABLED) {
        assert(0 && "TeleportCopToStart not implemented.");
        abort();
    } else {
        return original_TeleportCopToStart(pOpponent_spec);
    }
}

function_hook_state_t function_hook_state_CalcDistanceFromHome = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_CalcDistanceFromHome)
static void(__cdecl*original_CalcDistanceFromHome)(tOpponent_spec *) = (void(__cdecl*)(tOpponent_spec *))0x0040a13d;
CARM95_HOOK_FUNCTION(original_CalcDistanceFromHome, CalcDistanceFromHome)
void __cdecl CalcDistanceFromHome(tOpponent_spec *pOpponent_spec) {
    br_vector3 wank;
    LOG_TRACE("(%p)", pOpponent_spec);

    (void)pOpponent_spec;
    (void)wank;

    if (function_hook_state_CalcDistanceFromHome == HOOK_ENABLED) {
        assert(0 && "CalcDistanceFromHome not implemented.");
        abort();
    } else {
        original_CalcDistanceFromHome(pOpponent_spec);
    }
}

function_hook_state_t function_hook_state_MassageOpponentPosition = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_MassageOpponentPosition)
static int(__cdecl*original_MassageOpponentPosition)(tOpponent_spec *, int) = (int(__cdecl*)(tOpponent_spec *, int))0x0040472e;
CARM95_HOOK_FUNCTION(original_MassageOpponentPosition, MassageOpponentPosition)
int __cdecl MassageOpponentPosition(tOpponent_spec *pOpponent_spec, int pMassage_count) {
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
    (void)__block0___scale;
    (void)__block1___scale;

    if (function_hook_state_MassageOpponentPosition == HOOK_ENABLED) {
        assert(0 && "MassageOpponentPosition not implemented.");
        abort();
    } else {
        return original_MassageOpponentPosition(pOpponent_spec, pMassage_count);
    }
}

function_hook_state_t function_hook_state_RematerialiseOpponentOnThisSection = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_RematerialiseOpponentOnThisSection)
static int(__cdecl*original_RematerialiseOpponentOnThisSection)(tOpponent_spec *, br_scalar, tS16) = (int(__cdecl*)(tOpponent_spec *, br_scalar, tS16))0x004035b1;
CARM95_HOOK_FUNCTION(original_RematerialiseOpponentOnThisSection, RematerialiseOpponentOnThisSection)
int __cdecl RematerialiseOpponentOnThisSection(tOpponent_spec *pOpponent_spec, br_scalar pSpeed, tS16 pSection_no) {
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

    if (function_hook_state_RematerialiseOpponentOnThisSection == HOOK_ENABLED) {
        assert(0 && "RematerialiseOpponentOnThisSection not implemented.");
        abort();
    } else {
        return original_RematerialiseOpponentOnThisSection(pOpponent_spec, pSpeed, pSection_no);
    }
}

function_hook_state_t function_hook_state_RematerialiseOpponentOnNearestSection = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_RematerialiseOpponentOnNearestSection)
static int(__cdecl*original_RematerialiseOpponentOnNearestSection)(tOpponent_spec *, br_scalar) = (int(__cdecl*)(tOpponent_spec *, br_scalar))0x004038fe;
CARM95_HOOK_FUNCTION(original_RematerialiseOpponentOnNearestSection, RematerialiseOpponentOnNearestSection)
int __cdecl RematerialiseOpponentOnNearestSection(tOpponent_spec *pOpponent_spec, br_scalar pSpeed) {
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

    if (function_hook_state_RematerialiseOpponentOnNearestSection == HOOK_ENABLED) {
        assert(0 && "RematerialiseOpponentOnNearestSection not implemented.");
        abort();
    } else {
        return original_RematerialiseOpponentOnNearestSection(pOpponent_spec, pSpeed);
    }
}

function_hook_state_t function_hook_state_RematerialiseOpponent = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_RematerialiseOpponent)
static int(__cdecl*original_RematerialiseOpponent)(tOpponent_spec *, br_scalar) = (int(__cdecl*)(tOpponent_spec *, br_scalar))0x00403ad9;
CARM95_HOOK_FUNCTION(original_RematerialiseOpponent, RematerialiseOpponent)
int __cdecl RematerialiseOpponent(tOpponent_spec *pOpponent_spec, br_scalar pSpeed) {
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
    (void)__block0___scale;

    if (function_hook_state_RematerialiseOpponent == HOOK_ENABLED) {
        assert(0 && "RematerialiseOpponent not implemented.");
        abort();
    } else {
        return original_RematerialiseOpponent(pOpponent_spec, pSpeed);
    }
}

function_hook_state_t function_hook_state_CalcPlayerConspicuousness = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_CalcPlayerConspicuousness)
static void(__cdecl*original_CalcPlayerConspicuousness)(tOpponent_spec *) = (void(__cdecl*)(tOpponent_spec *))0x0040a1ab;
CARM95_HOOK_FUNCTION(original_CalcPlayerConspicuousness, CalcPlayerConspicuousness)
void __cdecl CalcPlayerConspicuousness(tOpponent_spec *pOpponent_spec) {
    br_vector3 pos_in_cop_space;
    br_matrix34 inverse_transform;
    LOG_TRACE("(%p)", pOpponent_spec);

    (void)pOpponent_spec;
    (void)pos_in_cop_space;
    (void)inverse_transform;

    if (function_hook_state_CalcPlayerConspicuousness == HOOK_ENABLED) {
        assert(0 && "CalcPlayerConspicuousness not implemented.");
        abort();
    } else {
        original_CalcPlayerConspicuousness(pOpponent_spec);
    }
}

function_hook_state_t function_hook_state_CalcOpponentConspicuousnessWithAViewToCheatingLikeFuck = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_CalcOpponentConspicuousnessWithAViewToCheatingLikeFuck)
static void(__cdecl*original_CalcOpponentConspicuousnessWithAViewToCheatingLikeFuck)(tOpponent_spec *) = (void(__cdecl*)(tOpponent_spec *))0x00404a0e;
CARM95_HOOK_FUNCTION(original_CalcOpponentConspicuousnessWithAViewToCheatingLikeFuck, CalcOpponentConspicuousnessWithAViewToCheatingLikeFuck)
void __cdecl CalcOpponentConspicuousnessWithAViewToCheatingLikeFuck(tOpponent_spec *pOpponent_spec) {
    LOG_TRACE("(%p)", pOpponent_spec);

    (void)pOpponent_spec;

    if (function_hook_state_CalcOpponentConspicuousnessWithAViewToCheatingLikeFuck == HOOK_ENABLED) {
        assert(0 && "CalcOpponentConspicuousnessWithAViewToCheatingLikeFuck not implemented.");
        abort();
    } else {
        original_CalcOpponentConspicuousnessWithAViewToCheatingLikeFuck(pOpponent_spec);
    }
}

function_hook_state_t function_hook_state_ChallengeOccurred = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_ChallengeOccurred)
static void(__cdecl*original_ChallengeOccurred)(int, int) = (void(__cdecl*)(int, int))0x00404abc;
CARM95_HOOK_FUNCTION(original_ChallengeOccurred, ChallengeOccurred)
void __cdecl ChallengeOccurred(int pChallenger_index, int pAccepted) {
    LOG_TRACE("(%d, %d)", pChallenger_index, pAccepted);

    (void)pChallenger_index;
    (void)pAccepted;

    if (function_hook_state_ChallengeOccurred == HOOK_ENABLED) {
        assert(0 && "ChallengeOccurred not implemented.");
        abort();
    } else {
        original_ChallengeOccurred(pChallenger_index, pAccepted);
    }
}

function_hook_state_t function_hook_state_LoadCopCars = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_LoadCopCars)
static void(__cdecl*original_LoadCopCars)() = (void(__cdecl*)())0x00404ad9;
CARM95_HOOK_FUNCTION(original_LoadCopCars, LoadCopCars)
void __cdecl LoadCopCars() {
    int i;
    LOG_TRACE("()");

    (void)i;

    if (function_hook_state_LoadCopCars == HOOK_ENABLED) {
        assert(0 && "LoadCopCars not implemented.");
        abort();
    } else {
        original_LoadCopCars();
    }
}

function_hook_state_t function_hook_state_LoadInOppoPaths = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_LoadInOppoPaths)
static void(__cdecl*original_LoadInOppoPaths)(FILE *) = (void(__cdecl*)(FILE *))0x00404b9b;
CARM95_HOOK_FUNCTION(original_LoadInOppoPaths, LoadInOppoPaths)
void __cdecl LoadInOppoPaths(FILE *pF) {
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
    (void)__block0__x_0;
    (void)__block0__x_1;
    (void)__block0__x_2;

    if (function_hook_state_LoadInOppoPaths == HOOK_ENABLED) {
        assert(0 && "LoadInOppoPaths not implemented.");
        abort();
    } else {
        original_LoadInOppoPaths(pF);
    }
}

function_hook_state_t function_hook_state_DisposeOpponentPaths = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_DisposeOpponentPaths)
static void(__cdecl*original_DisposeOpponentPaths)() = (void(__cdecl*)())0x00405912;
CARM95_HOOK_FUNCTION(original_DisposeOpponentPaths, DisposeOpponentPaths)
void __cdecl DisposeOpponentPaths() {
    LOG_TRACE("()");


    if (function_hook_state_DisposeOpponentPaths == HOOK_ENABLED) {
        assert(0 && "DisposeOpponentPaths not implemented.");
        abort();
    } else {
        original_DisposeOpponentPaths();
    }
}

function_hook_state_t function_hook_state_MungeOpponents = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_MungeOpponents)
static void(__cdecl*original_MungeOpponents)(tU32) = (void(__cdecl*)(tU32))0x004059a0;
CARM95_HOOK_FUNCTION(original_MungeOpponents, MungeOpponents)
void __cdecl MungeOpponents(tU32 pFrame_period) {
    int i;
    int un_stun_flag;
    LOG_TRACE("(%u)", pFrame_period);

    (void)pFrame_period;
    (void)i;
    (void)un_stun_flag;

    if (function_hook_state_MungeOpponents == HOOK_ENABLED) {
        assert(0 && "MungeOpponents not implemented.");
        abort();
    } else {
        original_MungeOpponents(pFrame_period);
    }
}

function_hook_state_t function_hook_state_SetInitialCopPositions = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_SetInitialCopPositions)
static void(__cdecl*original_SetInitialCopPositions)() = (void(__cdecl*)())0x0040a3a5;
CARM95_HOOK_FUNCTION(original_SetInitialCopPositions, SetInitialCopPositions)
void __cdecl SetInitialCopPositions() {
    int i;
    LOG_TRACE("()");

    (void)i;

    if (function_hook_state_SetInitialCopPositions == HOOK_ENABLED) {
        assert(0 && "SetInitialCopPositions not implemented.");
        abort();
    } else {
        original_SetInitialCopPositions();
    }
}

function_hook_state_t function_hook_state_InitOpponents = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_InitOpponents)
static void(__cdecl*original_InitOpponents)(tRace_info *) = (void(__cdecl*)(tRace_info *))0x0040a4ce;
CARM95_HOOK_FUNCTION(original_InitOpponents, InitOpponents)
void __cdecl InitOpponents(tRace_info *pRace_info) {
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
    (void)__block0__car_spec;
    (void)__block0__opponent_spec;

    if (function_hook_state_InitOpponents == HOOK_ENABLED) {
        assert(0 && "InitOpponents not implemented.");
        abort();
    } else {
        original_InitOpponents(pRace_info);
    }
}

function_hook_state_t function_hook_state_DisposeOpponents = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_DisposeOpponents)
static void(__cdecl*original_DisposeOpponents)() = (void(__cdecl*)())0x0040b186;
CARM95_HOOK_FUNCTION(original_DisposeOpponents, DisposeOpponents)
void __cdecl DisposeOpponents() {
    int i;
    LOG_TRACE("()");

    (void)i;

    if (function_hook_state_DisposeOpponents == HOOK_ENABLED) {
        assert(0 && "DisposeOpponents not implemented.");
        abort();
    } else {
        original_DisposeOpponents();
    }
}

function_hook_state_t function_hook_state_WakeUpOpponentsToTheFactThatTheStartHasBeenJumped = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_WakeUpOpponentsToTheFactThatTheStartHasBeenJumped)
static void(__cdecl*original_WakeUpOpponentsToTheFactThatTheStartHasBeenJumped)(int) = (void(__cdecl*)(int))0x0040b20f;
CARM95_HOOK_FUNCTION(original_WakeUpOpponentsToTheFactThatTheStartHasBeenJumped, WakeUpOpponentsToTheFactThatTheStartHasBeenJumped)
void __cdecl WakeUpOpponentsToTheFactThatTheStartHasBeenJumped(int pWhat_the_countdown_was) {
    int i;
    LOG_TRACE("(%d)", pWhat_the_countdown_was);

    (void)pWhat_the_countdown_was;
    (void)i;

    if (function_hook_state_WakeUpOpponentsToTheFactThatTheStartHasBeenJumped == HOOK_ENABLED) {
        assert(0 && "WakeUpOpponentsToTheFactThatTheStartHasBeenJumped not implemented.");
        abort();
    } else {
        original_WakeUpOpponentsToTheFactThatTheStartHasBeenJumped(pWhat_the_countdown_was);
    }
}

function_hook_state_t function_hook_state_ReportMurderToPoliceDepartment = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_ReportMurderToPoliceDepartment)
static void(__cdecl*original_ReportMurderToPoliceDepartment)(tCar_spec *) = (void(__cdecl*)(tCar_spec *))0x0040b3a5;
CARM95_HOOK_FUNCTION(original_ReportMurderToPoliceDepartment, ReportMurderToPoliceDepartment)
void __cdecl ReportMurderToPoliceDepartment(tCar_spec *pCar_spec) {
    int i;
    LOG_TRACE("(%p)", pCar_spec);

    (void)pCar_spec;
    (void)i;

    if (function_hook_state_ReportMurderToPoliceDepartment == HOOK_ENABLED) {
        assert(0 && "ReportMurderToPoliceDepartment not implemented.");
        abort();
    } else {
        original_ReportMurderToPoliceDepartment(pCar_spec);
    }
}

function_hook_state_t function_hook_state_GetCarCount = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_GetCarCount)
static int(__cdecl*original_GetCarCount)(tVehicle_type) = (int(__cdecl*)(tVehicle_type))0x0040b412;
CARM95_HOOK_FUNCTION(original_GetCarCount, GetCarCount)
int __cdecl GetCarCount(tVehicle_type pCategory) {
    LOG_TRACE("(%d)", pCategory);

    (void)pCategory;

    if (function_hook_state_GetCarCount == HOOK_ENABLED) {
        assert(0 && "GetCarCount not implemented.");
        abort();
    } else {
        return original_GetCarCount(pCategory);
    }
}

function_hook_state_t function_hook_state_GetCarSpec = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_GetCarSpec)
static tCar_spec *(__cdecl*original_GetCarSpec)(tVehicle_type, int) = (tCar_spec *(__cdecl*)(tVehicle_type, int))0x0040b4b1;
CARM95_HOOK_FUNCTION(original_GetCarSpec, GetCarSpec)
tCar_spec* __cdecl GetCarSpec(tVehicle_type pCategory, int pIndex) {
    LOG_TRACE("(%d, %d)", pCategory, pIndex);

    (void)pCategory;
    (void)pIndex;

    if (function_hook_state_GetCarSpec == HOOK_ENABLED) {
        assert(0 && "GetCarSpec not implemented.");
        abort();
    } else {
        return original_GetCarSpec(pCategory, pIndex);
    }
}

function_hook_state_t function_hook_state_GetDriverName = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_GetDriverName)
static char *(__cdecl*original_GetDriverName)(tVehicle_type, int) = (char *(__cdecl*)(tVehicle_type, int))0x0040b592;
CARM95_HOOK_FUNCTION(original_GetDriverName, GetDriverName)
char* __cdecl GetDriverName(tVehicle_type pCategory, int pIndex) {
    LOG_TRACE("(%d, %d)", pCategory, pIndex);

    (void)pCategory;
    (void)pIndex;

    if (function_hook_state_GetDriverName == HOOK_ENABLED) {
        assert(0 && "GetDriverName not implemented.");
        abort();
    } else {
        return original_GetDriverName(pCategory, pIndex);
    }
}

function_hook_state_t function_hook_state_GetOpponentSpecFromCarSpec = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_GetOpponentSpecFromCarSpec)
static tOpponent_spec *(__cdecl*original_GetOpponentSpecFromCarSpec)(tCar_spec *) = (tOpponent_spec *(__cdecl*)(tCar_spec *))0x0040b639;
CARM95_HOOK_FUNCTION(original_GetOpponentSpecFromCarSpec, GetOpponentSpecFromCarSpec)
tOpponent_spec* __cdecl GetOpponentSpecFromCarSpec(tCar_spec *pCar_spec) {
    int i;
    LOG_TRACE("(%p)", pCar_spec);

    (void)pCar_spec;
    (void)i;

    if (function_hook_state_GetOpponentSpecFromCarSpec == HOOK_ENABLED) {
        assert(0 && "GetOpponentSpecFromCarSpec not implemented.");
        abort();
    } else {
        return original_GetOpponentSpecFromCarSpec(pCar_spec);
    }
}

function_hook_state_t function_hook_state_GetCarSpecFromGlobalOppoIndex = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_GetCarSpecFromGlobalOppoIndex)
static tCar_spec *(__cdecl*original_GetCarSpecFromGlobalOppoIndex)(int) = (tCar_spec *(__cdecl*)(int))0x0040b74d;
CARM95_HOOK_FUNCTION(original_GetCarSpecFromGlobalOppoIndex, GetCarSpecFromGlobalOppoIndex)
tCar_spec* __cdecl GetCarSpecFromGlobalOppoIndex(int pIndex) {
    int i;
    LOG_TRACE("(%d)", pIndex);

    (void)pIndex;
    (void)i;

    if (function_hook_state_GetCarSpecFromGlobalOppoIndex == HOOK_ENABLED) {
        assert(0 && "GetCarSpecFromGlobalOppoIndex not implemented.");
        abort();
    } else {
        return original_GetCarSpecFromGlobalOppoIndex(pIndex);
    }
}

function_hook_state_t function_hook_state_GetOpponentsRealSection = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_GetOpponentsRealSection)
static int(__cdecl*original_GetOpponentsRealSection)(tOpponent_spec *, int) = (int(__cdecl*)(tOpponent_spec *, int))0x0040b7b7;
CARM95_HOOK_FUNCTION(original_GetOpponentsRealSection, GetOpponentsRealSection)
int __cdecl GetOpponentsRealSection(tOpponent_spec *pOpponent_spec, int pSection_no) {
    LOG_TRACE("(%p, %d)", pOpponent_spec, pSection_no);

    (void)pOpponent_spec;
    (void)pSection_no;

    if (function_hook_state_GetOpponentsRealSection == HOOK_ENABLED) {
        assert(0 && "GetOpponentsRealSection not implemented.");
        abort();
    } else {
        return original_GetOpponentsRealSection(pOpponent_spec, pSection_no);
    }
}

function_hook_state_t function_hook_state_GetOpponentsFirstSection = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_GetOpponentsFirstSection)
static int(__cdecl*original_GetOpponentsFirstSection)(tOpponent_spec *) = (int(__cdecl*)(tOpponent_spec *))0x0040b806;
CARM95_HOOK_FUNCTION(original_GetOpponentsFirstSection, GetOpponentsFirstSection)
int __cdecl GetOpponentsFirstSection(tOpponent_spec *pOpponent_spec) {
    LOG_TRACE("(%p)", pOpponent_spec);

    (void)pOpponent_spec;

    if (function_hook_state_GetOpponentsFirstSection == HOOK_ENABLED) {
        assert(0 && "GetOpponentsFirstSection not implemented.");
        abort();
    } else {
        return original_GetOpponentsFirstSection(pOpponent_spec);
    }
}

function_hook_state_t function_hook_state_GetOpponentsNextSection = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_GetOpponentsNextSection)
static int(__cdecl*original_GetOpponentsNextSection)(tOpponent_spec *, tS16) = (int(__cdecl*)(tOpponent_spec *, tS16))0x0040b86e;
CARM95_HOOK_FUNCTION(original_GetOpponentsNextSection, GetOpponentsNextSection)
int __cdecl GetOpponentsNextSection(tOpponent_spec *pOpponent_spec, tS16 pCurrent_section) {
    LOG_TRACE("(%p, %d)", pOpponent_spec, pCurrent_section);

    (void)pOpponent_spec;
    (void)pCurrent_section;

    if (function_hook_state_GetOpponentsNextSection == HOOK_ENABLED) {
        assert(0 && "GetOpponentsNextSection not implemented.");
        abort();
    } else {
        return original_GetOpponentsNextSection(pOpponent_spec, pCurrent_section);
    }
}

function_hook_state_t function_hook_state_GetOpponentsSectionStartNode = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_GetOpponentsSectionStartNode)
static tS16(__cdecl*original_GetOpponentsSectionStartNode)(tOpponent_spec *, tS16) = (tS16(__cdecl*)(tOpponent_spec *, tS16))0x0040b91f;
CARM95_HOOK_FUNCTION(original_GetOpponentsSectionStartNode, GetOpponentsSectionStartNode)
tS16 __cdecl GetOpponentsSectionStartNode(tOpponent_spec *pOpponent_spec, tS16 pSection) {
    tS16 section_no;
    int node_index_index;
    LOG_TRACE("(%p, %d)", pOpponent_spec, pSection);

    (void)pOpponent_spec;
    (void)pSection;
    (void)section_no;
    (void)node_index_index;

    if (function_hook_state_GetOpponentsSectionStartNode == HOOK_ENABLED) {
        assert(0 && "GetOpponentsSectionStartNode not implemented.");
        abort();
    } else {
        return original_GetOpponentsSectionStartNode(pOpponent_spec, pSection);
    }
}

function_hook_state_t function_hook_state_GetOpponentsSectionFinishNode = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_GetOpponentsSectionFinishNode)
static tS16(__cdecl*original_GetOpponentsSectionFinishNode)(tOpponent_spec *, tS16) = (tS16(__cdecl*)(tOpponent_spec *, tS16))0x0040b9fb;
CARM95_HOOK_FUNCTION(original_GetOpponentsSectionFinishNode, GetOpponentsSectionFinishNode)
tS16 __cdecl GetOpponentsSectionFinishNode(tOpponent_spec *pOpponent_spec, tS16 pSection) {
    tS16 section_no;
    int node_index_index;
    LOG_TRACE("(%p, %d)", pOpponent_spec, pSection);

    (void)pOpponent_spec;
    (void)pSection;
    (void)section_no;
    (void)node_index_index;

    if (function_hook_state_GetOpponentsSectionFinishNode == HOOK_ENABLED) {
        assert(0 && "GetOpponentsSectionFinishNode not implemented.");
        abort();
    } else {
        return original_GetOpponentsSectionFinishNode(pOpponent_spec, pSection);
    }
}

function_hook_state_t function_hook_state_GetOpponentsSectionStartNodePoint = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_GetOpponentsSectionStartNodePoint)
static br_vector3 *(__cdecl*original_GetOpponentsSectionStartNodePoint)(tOpponent_spec *, tS16) = (br_vector3 *(__cdecl*)(tOpponent_spec *, tS16))0x0040baa1;
CARM95_HOOK_FUNCTION(original_GetOpponentsSectionStartNodePoint, GetOpponentsSectionStartNodePoint)
br_vector3* __cdecl GetOpponentsSectionStartNodePoint(tOpponent_spec *pOpponent_spec, tS16 pSection) {
    tS16 section_no;
    tS16 node_no;
    int node_index_index;
    LOG_TRACE("(%p, %d)", pOpponent_spec, pSection);

    (void)pOpponent_spec;
    (void)pSection;
    (void)section_no;
    (void)node_no;
    (void)node_index_index;

    if (function_hook_state_GetOpponentsSectionStartNodePoint == HOOK_ENABLED) {
        assert(0 && "GetOpponentsSectionStartNodePoint not implemented.");
        abort();
    } else {
        return original_GetOpponentsSectionStartNodePoint(pOpponent_spec, pSection);
    }
}

function_hook_state_t function_hook_state_GetOpponentsSectionFinishNodePoint = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_GetOpponentsSectionFinishNodePoint)
static br_vector3 *(__cdecl*original_GetOpponentsSectionFinishNodePoint)(tOpponent_spec *, tS16) = (br_vector3 *(__cdecl*)(tOpponent_spec *, tS16))0x0040bbc3;
CARM95_HOOK_FUNCTION(original_GetOpponentsSectionFinishNodePoint, GetOpponentsSectionFinishNodePoint)
br_vector3* __cdecl GetOpponentsSectionFinishNodePoint(tOpponent_spec *pOpponent_spec, tS16 pSection) {
    tS16 section_no;
    tS16 node_no;
    int node_index_index;
    LOG_TRACE("(%p, %d)", pOpponent_spec, pSection);

    (void)pOpponent_spec;
    (void)pSection;
    (void)section_no;
    (void)node_no;
    (void)node_index_index;

    if (function_hook_state_GetOpponentsSectionFinishNodePoint == HOOK_ENABLED) {
        assert(0 && "GetOpponentsSectionFinishNodePoint not implemented.");
        abort();
    } else {
        return original_GetOpponentsSectionFinishNodePoint(pOpponent_spec, pSection);
    }
}

function_hook_state_t function_hook_state_GetOpponentsSectionWidth = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_GetOpponentsSectionWidth)
static br_scalar(__cdecl*original_GetOpponentsSectionWidth)(tOpponent_spec *, tS16) = (br_scalar(__cdecl*)(tOpponent_spec *, tS16))0x0040bccd;
CARM95_HOOK_FUNCTION(original_GetOpponentsSectionWidth, GetOpponentsSectionWidth)
br_scalar __cdecl GetOpponentsSectionWidth(tOpponent_spec *pOpponent_spec, tS16 pSection) {
    LOG_TRACE("(%p, %d)", pOpponent_spec, pSection);

    (void)pOpponent_spec;
    (void)pSection;

    if (function_hook_state_GetOpponentsSectionWidth == HOOK_ENABLED) {
        assert(0 && "GetOpponentsSectionWidth not implemented.");
        abort();
    } else {
        return original_GetOpponentsSectionWidth(pOpponent_spec, pSection);
    }
}

function_hook_state_t function_hook_state_GetOpponentsSectionMinSpeed = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_GetOpponentsSectionMinSpeed)
static int(__cdecl*original_GetOpponentsSectionMinSpeed)(tOpponent_spec *, tS16, int) = (int(__cdecl*)(tOpponent_spec *, tS16, int))0x0040bd7a;
CARM95_HOOK_FUNCTION(original_GetOpponentsSectionMinSpeed, GetOpponentsSectionMinSpeed)
int __cdecl GetOpponentsSectionMinSpeed(tOpponent_spec *pOpponent_spec, tS16 pSection, int pTowards_finish) {
    tS16 section_no;
    int direction;
    LOG_TRACE("(%p, %d, %d)", pOpponent_spec, pSection, pTowards_finish);

    (void)pOpponent_spec;
    (void)pSection;
    (void)pTowards_finish;
    (void)section_no;
    (void)direction;

    if (function_hook_state_GetOpponentsSectionMinSpeed == HOOK_ENABLED) {
        assert(0 && "GetOpponentsSectionMinSpeed not implemented.");
        abort();
    } else {
        return original_GetOpponentsSectionMinSpeed(pOpponent_spec, pSection, pTowards_finish);
    }
}

function_hook_state_t function_hook_state_GetOpponentsSectionMaxSpeed = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_GetOpponentsSectionMaxSpeed)
static int(__cdecl*original_GetOpponentsSectionMaxSpeed)(tOpponent_spec *, tS16, int) = (int(__cdecl*)(tOpponent_spec *, tS16, int))0x0040be6e;
CARM95_HOOK_FUNCTION(original_GetOpponentsSectionMaxSpeed, GetOpponentsSectionMaxSpeed)
int __cdecl GetOpponentsSectionMaxSpeed(tOpponent_spec *pOpponent_spec, tS16 pSection, int pTowards_finish) {
    tS16 section_no;
    int direction;
    LOG_TRACE("(%p, %d, %d)", pOpponent_spec, pSection, pTowards_finish);

    (void)pOpponent_spec;
    (void)pSection;
    (void)pTowards_finish;
    (void)section_no;
    (void)direction;

    if (function_hook_state_GetOpponentsSectionMaxSpeed == HOOK_ENABLED) {
        assert(0 && "GetOpponentsSectionMaxSpeed not implemented.");
        abort();
    } else {
        return original_GetOpponentsSectionMaxSpeed(pOpponent_spec, pSection, pTowards_finish);
    }
}

function_hook_state_t function_hook_state_InitOpponentPsyche = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_InitOpponentPsyche)
static void(__cdecl*original_InitOpponentPsyche)(int) = (void(__cdecl*)(int))0x0040bf68;
CARM95_HOOK_FUNCTION(original_InitOpponentPsyche, InitOpponentPsyche)
void __cdecl InitOpponentPsyche(int pOpponent_index) {
    int i;
    LOG_TRACE("(%d)", pOpponent_index);

    (void)pOpponent_index;
    (void)i;

    if (function_hook_state_InitOpponentPsyche == HOOK_ENABLED) {
        assert(0 && "InitOpponentPsyche not implemented.");
        abort();
    } else {
        original_InitOpponentPsyche(pOpponent_index);
    }
}

function_hook_state_t function_hook_state_ClearTwattageOccurrenceVariables = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_ClearTwattageOccurrenceVariables)
static void(__cdecl*original_ClearTwattageOccurrenceVariables)(tOpponent_spec *) = (void(__cdecl*)(tOpponent_spec *))0x0040bf8d;
CARM95_HOOK_FUNCTION(original_ClearTwattageOccurrenceVariables, ClearTwattageOccurrenceVariables)
void __cdecl ClearTwattageOccurrenceVariables(tOpponent_spec *pOpponent_spec) {
    LOG_TRACE("(%p)", pOpponent_spec);

    (void)pOpponent_spec;

    if (function_hook_state_ClearTwattageOccurrenceVariables == HOOK_ENABLED) {
        assert(0 && "ClearTwattageOccurrenceVariables not implemented.");
        abort();
    } else {
        original_ClearTwattageOccurrenceVariables(pOpponent_spec);
    }
}

function_hook_state_t function_hook_state_TwoCarsHitEachOther = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_TwoCarsHitEachOther)
static void(__cdecl*original_TwoCarsHitEachOther)(tCar_spec *, tCar_spec *) = (void(__cdecl*)(tCar_spec *, tCar_spec *))0x0040bfdf;
CARM95_HOOK_FUNCTION(original_TwoCarsHitEachOther, TwoCarsHitEachOther)
void __cdecl TwoCarsHitEachOther(tCar_spec *pA_car, tCar_spec *pAnother_car) {
    LOG_TRACE("(%p, %p)", pA_car, pAnother_car);

    (void)pA_car;
    (void)pAnother_car;

    if (function_hook_state_TwoCarsHitEachOther == HOOK_ENABLED) {
        assert(0 && "TwoCarsHitEachOther not implemented.");
        abort();
    } else {
        original_TwoCarsHitEachOther(pA_car, pAnother_car);
    }
}

function_hook_state_t function_hook_state_RecordOpponentTwattageOccurrence = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_RecordOpponentTwattageOccurrence)
static void(__cdecl*original_RecordOpponentTwattageOccurrence)(tCar_spec *, tCar_spec *) = (void(__cdecl*)(tCar_spec *, tCar_spec *))0x0040c020;
CARM95_HOOK_FUNCTION(original_RecordOpponentTwattageOccurrence, RecordOpponentTwattageOccurrence)
void __cdecl RecordOpponentTwattageOccurrence(tCar_spec *pTwatter, tCar_spec *pTwattee) {
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

    if (function_hook_state_RecordOpponentTwattageOccurrence == HOOK_ENABLED) {
        assert(0 && "RecordOpponentTwattageOccurrence not implemented.");
        abort();
    } else {
        original_RecordOpponentTwattageOccurrence(pTwatter, pTwattee);
    }
}

function_hook_state_t function_hook_state_ToggleOpponentTest = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_ToggleOpponentTest)
static void(__cdecl*original_ToggleOpponentTest)() = (void(__cdecl*)())0x0040c537;
CARM95_HOOK_FUNCTION(original_ToggleOpponentTest, ToggleOpponentTest)
void __cdecl ToggleOpponentTest() {
    LOG_TRACE("()");


    if (function_hook_state_ToggleOpponentTest == HOOK_ENABLED) {
        assert(0 && "ToggleOpponentTest not implemented.");
        abort();
    } else {
        original_ToggleOpponentTest();
    }
}

function_hook_state_t function_hook_state_ToggleOpponentProcessing = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_ToggleOpponentProcessing)
static void(__cdecl*original_ToggleOpponentProcessing)() = (void(__cdecl*)())0x0040c568;
CARM95_HOOK_FUNCTION(original_ToggleOpponentProcessing, ToggleOpponentProcessing)
void __cdecl ToggleOpponentProcessing() {
    int i;
    LOG_TRACE("()");

    (void)i;

    if (function_hook_state_ToggleOpponentProcessing == HOOK_ENABLED) {
        assert(0 && "ToggleOpponentProcessing not implemented.");
        abort();
    } else {
        original_ToggleOpponentProcessing();
    }
}

function_hook_state_t function_hook_state_ToggleMellowOpponents = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_ToggleMellowOpponents)
static void(__cdecl*original_ToggleMellowOpponents)() = (void(__cdecl*)())0x0040c6dd;
CARM95_HOOK_FUNCTION(original_ToggleMellowOpponents, ToggleMellowOpponents)
void __cdecl ToggleMellowOpponents() {
    int i;
    LOG_TRACE("()");

    (void)i;

    if (function_hook_state_ToggleMellowOpponents == HOOK_ENABLED) {
        assert(0 && "ToggleMellowOpponents not implemented.");
        abort();
    } else {
        original_ToggleMellowOpponents();
    }
}

function_hook_state_t function_hook_state_RepairOpponentsSystems = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_RepairOpponentsSystems)
static void(__cdecl*original_RepairOpponentsSystems)() = (void(__cdecl*)())0x0040c795;
CARM95_HOOK_FUNCTION(original_RepairOpponentsSystems, RepairOpponentsSystems)
void __cdecl RepairOpponentsSystems() {
    int i;
    LOG_TRACE("()");

    (void)i;

    if (function_hook_state_RepairOpponentsSystems == HOOK_ENABLED) {
        assert(0 && "RepairOpponentsSystems not implemented.");
        abort();
    } else {
        original_RepairOpponentsSystems();
    }
}

function_hook_state_t function_hook_state_CopyVertex__opponent = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_CopyVertex__opponent)
static void(__cdecl*original_CopyVertex__opponent)(br_vertex *, br_vertex *) = (void(__cdecl*)(br_vertex *, br_vertex *))0x0040e205;
CARM95_HOOK_FUNCTION(original_CopyVertex__opponent, CopyVertex__opponent)
void __cdecl CopyVertex__opponent(br_vertex *pDest_vertex, br_vertex *pSrc_vertex) {
    LOG_TRACE("(%p, %p)", pDest_vertex, pSrc_vertex);

    (void)pDest_vertex;
    (void)pSrc_vertex;

    if (function_hook_state_CopyVertex__opponent == HOOK_ENABLED) {
        assert(0 && "CopyVertex__opponent not implemented.");
        abort();
    } else {
        original_CopyVertex__opponent(pDest_vertex, pSrc_vertex);
    }
}

function_hook_state_t function_hook_state_CopyFace__opponent = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_CopyFace__opponent)
static void(__cdecl*original_CopyFace__opponent)(br_face *, br_face *) = (void(__cdecl*)(br_face *, br_face *))0x0040e27a;
CARM95_HOOK_FUNCTION(original_CopyFace__opponent, CopyFace__opponent)
void __cdecl CopyFace__opponent(br_face *pDest_face, br_face *pSrc_face) {
    LOG_TRACE("(%p, %p)", pDest_face, pSrc_face);

    (void)pDest_face;
    (void)pSrc_face;

    if (function_hook_state_CopyFace__opponent == HOOK_ENABLED) {
        assert(0 && "CopyFace__opponent not implemented.");
        abort();
    } else {
        original_CopyFace__opponent(pDest_face, pSrc_face);
    }
}

function_hook_state_t function_hook_state_DeleteSection = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_DeleteSection)
static void(__cdecl*original_DeleteSection)(tS16) = (void(__cdecl*)(tS16))0x0040c868;
CARM95_HOOK_FUNCTION(original_DeleteSection, DeleteSection)
void __cdecl DeleteSection(tS16 pSection_to_delete) {
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

    if (function_hook_state_DeleteSection == HOOK_ENABLED) {
        assert(0 && "DeleteSection not implemented.");
        abort();
    } else {
        original_DeleteSection(pSection_to_delete);
    }
}

function_hook_state_t function_hook_state_DeleteNode = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_DeleteNode)
static void(__cdecl*original_DeleteNode)(tS16, int) = (void(__cdecl*)(tS16, int))0x0040caf4;
CARM95_HOOK_FUNCTION(original_DeleteNode, DeleteNode)
void __cdecl DeleteNode(tS16 pNode_to_delete, int pAnd_sections) {
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

    if (function_hook_state_DeleteNode == HOOK_ENABLED) {
        assert(0 && "DeleteNode not implemented.");
        abort();
    } else {
        original_DeleteNode(pNode_to_delete, pAnd_sections);
    }
}

function_hook_state_t function_hook_state_DeleteOrphanNodes = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_DeleteOrphanNodes)
static void(__cdecl*original_DeleteOrphanNodes)() = (void(__cdecl*)())0x0040ca84;
CARM95_HOOK_FUNCTION(original_DeleteOrphanNodes, DeleteOrphanNodes)
void __cdecl DeleteOrphanNodes() {
    tS16 node_no;
    LOG_TRACE("()");

    (void)node_no;

    if (function_hook_state_DeleteOrphanNodes == HOOK_ENABLED) {
        assert(0 && "DeleteOrphanNodes not implemented.");
        abort();
    } else {
        original_DeleteOrphanNodes();
    }
}

function_hook_state_t function_hook_state_InsertThisNodeInThisSectionHere = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_InsertThisNodeInThisSectionHere)
static void(__cdecl*original_InsertThisNodeInThisSectionHere)(tS16, tS16, br_vector3 *) = (void(__cdecl*)(tS16, tS16, br_vector3 *))0x0040fb06;
CARM95_HOOK_FUNCTION(original_InsertThisNodeInThisSectionHere, InsertThisNodeInThisSectionHere)
void __cdecl InsertThisNodeInThisSectionHere(tS16 pInserted_node, tS16 pSection_no, br_vector3 *pWhere) {
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

    if (function_hook_state_InsertThisNodeInThisSectionHere == HOOK_ENABLED) {
        assert(0 && "InsertThisNodeInThisSectionHere not implemented.");
        abort();
    } else {
        original_InsertThisNodeInThisSectionHere(pInserted_node, pSection_no, pWhere);
    }
}

function_hook_state_t function_hook_state_TrackElasticateyPath = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_TrackElasticateyPath)
static void(__cdecl*original_TrackElasticateyPath)() = (void(__cdecl*)())0x0040ce66;
CARM95_HOOK_FUNCTION(original_TrackElasticateyPath, TrackElasticateyPath)
void __cdecl TrackElasticateyPath() {
    LOG_TRACE("()");


    if (function_hook_state_TrackElasticateyPath == HOOK_ENABLED) {
        assert(0 && "TrackElasticateyPath not implemented.");
        abort();
    } else {
        original_TrackElasticateyPath();
    }
}

function_hook_state_t function_hook_state_RecalcNearestPathSectionSpeed = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_RecalcNearestPathSectionSpeed)
static void(__cdecl*original_RecalcNearestPathSectionSpeed)(int, int) = (void(__cdecl*)(int, int))0x004105c6;
CARM95_HOOK_FUNCTION(original_RecalcNearestPathSectionSpeed, RecalcNearestPathSectionSpeed)
void __cdecl RecalcNearestPathSectionSpeed(int pMax_not_min, int pAdjustment) {
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

    if (function_hook_state_RecalcNearestPathSectionSpeed == HOOK_ENABLED) {
        assert(0 && "RecalcNearestPathSectionSpeed not implemented.");
        abort();
    } else {
        original_RecalcNearestPathSectionSpeed(pMax_not_min, pAdjustment);
    }
}

function_hook_state_t function_hook_state_RecalcNearestPathSectionWidth = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_RecalcNearestPathSectionWidth)
static void(__cdecl*original_RecalcNearestPathSectionWidth)(br_scalar) = (void(__cdecl*)(br_scalar))0x004103ef;
CARM95_HOOK_FUNCTION(original_RecalcNearestPathSectionWidth, RecalcNearestPathSectionWidth)
void __cdecl RecalcNearestPathSectionWidth(br_scalar pAdjustment) {
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

    if (function_hook_state_RecalcNearestPathSectionWidth == HOOK_ENABLED) {
        assert(0 && "RecalcNearestPathSectionWidth not implemented.");
        abort();
    } else {
        original_RecalcNearestPathSectionWidth(pAdjustment);
    }
}

function_hook_state_t function_hook_state_CalcNegativeXVector = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_CalcNegativeXVector)
static void(__cdecl*original_CalcNegativeXVector)(br_vector3 *, br_vector3 *, br_vector3 *, br_scalar) = (void(__cdecl*)(br_vector3 *, br_vector3 *, br_vector3 *, br_scalar))0x0040cf4e;
CARM95_HOOK_FUNCTION(original_CalcNegativeXVector, CalcNegativeXVector)
void __cdecl CalcNegativeXVector(br_vector3 *pNegative_x_vector, br_vector3 *pStart, br_vector3 *pFinish, br_scalar pLength) {
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
    (void)__block0___scale;

    if (function_hook_state_CalcNegativeXVector == HOOK_ENABLED) {
        assert(0 && "CalcNegativeXVector not implemented.");
        abort();
    } else {
        original_CalcNegativeXVector(pNegative_x_vector, pStart, pFinish, pLength);
    }
}

function_hook_state_t function_hook_state_MakeVertexAndOffsetIt = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_MakeVertexAndOffsetIt)
static void(__cdecl*original_MakeVertexAndOffsetIt)(br_model *, int, br_scalar, br_scalar, br_scalar, br_vector3 *) = (void(__cdecl*)(br_model *, int, br_scalar, br_scalar, br_scalar, br_vector3 *))0x0040d9d3;
CARM95_HOOK_FUNCTION(original_MakeVertexAndOffsetIt, MakeVertexAndOffsetIt)
void __cdecl MakeVertexAndOffsetIt(br_model *pModel, int pVertex_num, br_scalar pX, br_scalar pY, br_scalar pZ, br_vector3 *pOffset) {
    LOG_TRACE("(%p, %d, %f, %f, %f, %p)", pModel, pVertex_num, pX, pY, pZ, pOffset);

    (void)pModel;
    (void)pVertex_num;
    (void)pX;
    (void)pY;
    (void)pZ;
    (void)pOffset;

    if (function_hook_state_MakeVertexAndOffsetIt == HOOK_ENABLED) {
        assert(0 && "MakeVertexAndOffsetIt not implemented.");
        abort();
    } else {
        original_MakeVertexAndOffsetIt(pModel, pVertex_num, pX, pY, pZ, pOffset);
    }
}

function_hook_state_t function_hook_state_MakeFaceAndTextureIt = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_MakeFaceAndTextureIt)
static void(__cdecl*original_MakeFaceAndTextureIt)(br_model *, int, int, int, int, br_material *) = (void(__cdecl*)(br_model *, int, int, int, int, br_material *))0x0040da85;
CARM95_HOOK_FUNCTION(original_MakeFaceAndTextureIt, MakeFaceAndTextureIt)
void __cdecl MakeFaceAndTextureIt(br_model *pModel, int pFace_num, int pV0, int pV1, int pV2, br_material *pMaterial) {
    LOG_TRACE("(%p, %d, %d, %d, %d, %p)", pModel, pFace_num, pV0, pV1, pV2, pMaterial);

    (void)pModel;
    (void)pFace_num;
    (void)pV0;
    (void)pV1;
    (void)pV2;
    (void)pMaterial;

    if (function_hook_state_MakeFaceAndTextureIt == HOOK_ENABLED) {
        assert(0 && "MakeFaceAndTextureIt not implemented.");
        abort();
    } else {
        original_MakeFaceAndTextureIt(pModel, pFace_num, pV0, pV1, pV2, pMaterial);
    }
}

function_hook_state_t function_hook_state_MakeSection = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_MakeSection)
static void(__cdecl*original_MakeSection)(br_uint_16, br_uint_16, br_vector3 *, br_vector3 *, br_scalar, br_material *, br_material *, br_material *, br_material *, br_material *, br_material *) = (void(__cdecl*)(br_uint_16, br_uint_16, br_vector3 *, br_vector3 *, br_scalar, br_material *, br_material *, br_material *, br_material *, br_material *, br_material *))0x0040d59f;
CARM95_HOOK_FUNCTION(original_MakeSection, MakeSection)
void __cdecl MakeSection(br_uint_16 pFirst_vertex, br_uint_16 pFirst_face, br_vector3 *pStart, br_vector3 *pFinish, br_scalar pWidth, br_material *pMaterial_centre_lt, br_material *pMaterial_centre_dk, br_material *pMaterial_edges_start_lt, br_material *pMaterial_edges_start_dk, br_material *pMaterial_edges_finish_lt, br_material *pMaterial_edges_finish_dk) {
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

    if (function_hook_state_MakeSection == HOOK_ENABLED) {
        assert(0 && "MakeSection not implemented.");
        abort();
    } else {
        original_MakeSection(pFirst_vertex, pFirst_face, pStart, pFinish, pWidth, pMaterial_centre_lt, pMaterial_centre_dk, pMaterial_edges_start_lt, pMaterial_edges_start_dk, pMaterial_edges_finish_lt, pMaterial_edges_finish_dk);
    }
}

function_hook_state_t function_hook_state_MakeCube = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_MakeCube)
static void(__cdecl*original_MakeCube)(br_uint_16, br_uint_16, br_vector3 *, br_material *, br_material *, br_material *) = (void(__cdecl*)(br_uint_16, br_uint_16, br_vector3 *, br_material *, br_material *, br_material *))0x0040daf1;
CARM95_HOOK_FUNCTION(original_MakeCube, MakeCube)
void __cdecl MakeCube(br_uint_16 pFirst_vertex, br_uint_16 pFirst_face, br_vector3 *pPoint, br_material *pMaterial_1, br_material *pMaterial_2, br_material *pMaterial_3) {
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

    if (function_hook_state_MakeCube == HOOK_ENABLED) {
        assert(0 && "MakeCube not implemented.");
        abort();
    } else {
        original_MakeCube(pFirst_vertex, pFirst_face, pPoint, pMaterial_1, pMaterial_2, pMaterial_3);
    }
}

function_hook_state_t function_hook_state_CalcNumberOfFacesAndVerticesForOppoPathModel = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_CalcNumberOfFacesAndVerticesForOppoPathModel)
static void(__cdecl*original_CalcNumberOfFacesAndVerticesForOppoPathModel)(br_uint_16 *, br_uint_16 *) = (void(__cdecl*)(br_uint_16 *, br_uint_16 *))0x0040e016;
CARM95_HOOK_FUNCTION(original_CalcNumberOfFacesAndVerticesForOppoPathModel, CalcNumberOfFacesAndVerticesForOppoPathModel)
void __cdecl CalcNumberOfFacesAndVerticesForOppoPathModel(br_uint_16 *pFace_index_ptr, br_uint_16 *pVertex_index_ptr) {
    LOG_TRACE("(%p, %p)", pFace_index_ptr, pVertex_index_ptr);

    (void)pFace_index_ptr;
    (void)pVertex_index_ptr;

    if (function_hook_state_CalcNumberOfFacesAndVerticesForOppoPathModel == HOOK_ENABLED) {
        assert(0 && "CalcNumberOfFacesAndVerticesForOppoPathModel not implemented.");
        abort();
    } else {
        original_CalcNumberOfFacesAndVerticesForOppoPathModel(pFace_index_ptr, pVertex_index_ptr);
    }
}

function_hook_state_t function_hook_state_ReallocModelFacesAndVertices = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_ReallocModelFacesAndVertices)
static void(__cdecl*original_ReallocModelFacesAndVertices)(br_model *, int, int) = (void(__cdecl*)(br_model *, int, int))0x0040e057;
CARM95_HOOK_FUNCTION(original_ReallocModelFacesAndVertices, ReallocModelFacesAndVertices)
void __cdecl ReallocModelFacesAndVertices(br_model *pModel, int pNum_faces, int pNum_vertices) {
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

    if (function_hook_state_ReallocModelFacesAndVertices == HOOK_ENABLED) {
        assert(0 && "ReallocModelFacesAndVertices not implemented.");
        abort();
    } else {
        original_ReallocModelFacesAndVertices(pModel, pNum_faces, pNum_vertices);
    }
}

function_hook_state_t function_hook_state_CreateSimpleMaterial = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_CreateSimpleMaterial)
static br_material *(__cdecl*original_CreateSimpleMaterial)(int) = (br_material *(__cdecl*)(int))0x0040e3cf;
CARM95_HOOK_FUNCTION(original_CreateSimpleMaterial, CreateSimpleMaterial)
br_material* __cdecl CreateSimpleMaterial(int pColour_index) {
    br_material *return_me;
    LOG_TRACE("(%d)", pColour_index);

    (void)pColour_index;
    (void)return_me;

    if (function_hook_state_CreateSimpleMaterial == HOOK_ENABLED) {
        assert(0 && "CreateSimpleMaterial not implemented.");
        abort();
    } else {
        return original_CreateSimpleMaterial(pColour_index);
    }
}

function_hook_state_t function_hook_state_AllocateMatsForOppoPathModel = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_AllocateMatsForOppoPathModel)
static void(__cdecl*original_AllocateMatsForOppoPathModel)() = (void(__cdecl*)())0x0040e2d3;
CARM95_HOOK_FUNCTION(original_AllocateMatsForOppoPathModel, AllocateMatsForOppoPathModel)
void __cdecl AllocateMatsForOppoPathModel() {
    LOG_TRACE("()");


    if (function_hook_state_AllocateMatsForOppoPathModel == HOOK_ENABLED) {
        assert(0 && "AllocateMatsForOppoPathModel not implemented.");
        abort();
    } else {
        original_AllocateMatsForOppoPathModel();
    }
}

function_hook_state_t function_hook_state_RebuildOppoPathModel = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_RebuildOppoPathModel)
static void(__cdecl*original_RebuildOppoPathModel)() = (void(__cdecl*)())0x0040d097;
CARM95_HOOK_FUNCTION(original_RebuildOppoPathModel, RebuildOppoPathModel)
void __cdecl RebuildOppoPathModel() {
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

    if (function_hook_state_RebuildOppoPathModel == HOOK_ENABLED) {
        assert(0 && "RebuildOppoPathModel not implemented.");
        abort();
    } else {
        original_RebuildOppoPathModel();
    }
}

function_hook_state_t function_hook_state_ConsistencyCheck = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_ConsistencyCheck)
static int(__cdecl*original_ConsistencyCheck)() = (int(__cdecl*)())0x0040e436;
CARM95_HOOK_FUNCTION(original_ConsistencyCheck, ConsistencyCheck)
int __cdecl ConsistencyCheck() {
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

    if (function_hook_state_ConsistencyCheck == HOOK_ENABLED) {
        assert(0 && "ConsistencyCheck not implemented.");
        abort();
    } else {
        return original_ConsistencyCheck();
    }
}

function_hook_state_t function_hook_state_ShowOppoPaths = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_ShowOppoPaths)
static void(__cdecl*original_ShowOppoPaths)() = (void(__cdecl*)())0x0040ed8e;
CARM95_HOOK_FUNCTION(original_ShowOppoPaths, ShowOppoPaths)
void __cdecl ShowOppoPaths() {
    char str[256];
    LOG_TRACE("()");

    (void)str;

    if (function_hook_state_ShowOppoPaths == HOOK_ENABLED) {
        assert(0 && "ShowOppoPaths not implemented.");
        abort();
    } else {
        original_ShowOppoPaths();
    }
}

function_hook_state_t function_hook_state_WriteOutOppoPaths = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_WriteOutOppoPaths)
static void(__cdecl*original_WriteOutOppoPaths)() = (void(__cdecl*)())0x0040e9d4;
CARM95_HOOK_FUNCTION(original_WriteOutOppoPaths, WriteOutOppoPaths)
void __cdecl WriteOutOppoPaths() {
    char the_path[256];
    char str[13];
    FILE *f;
    int i;
    LOG_TRACE("()");

    (void)the_path;
    (void)str;
    (void)f;
    (void)i;

    if (function_hook_state_WriteOutOppoPaths == HOOK_ENABLED) {
        assert(0 && "WriteOutOppoPaths not implemented.");
        abort();
    } else {
        original_WriteOutOppoPaths();
    }
}

function_hook_state_t function_hook_state_NewNodeOKHere = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_NewNodeOKHere)
static int(__cdecl*original_NewNodeOKHere)() = (int(__cdecl*)())0x0040f42b;
CARM95_HOOK_FUNCTION(original_NewNodeOKHere, NewNodeOKHere)
int __cdecl NewNodeOKHere() {
    br_vector3 last_node_to_this;
    LOG_TRACE("()");

    (void)last_node_to_this;

    if (function_hook_state_NewNodeOKHere == HOOK_ENABLED) {
        assert(0 && "NewNodeOKHere not implemented.");
        abort();
    } else {
        return original_NewNodeOKHere();
    }
}

function_hook_state_t function_hook_state_ShowHideOppoPaths = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_ShowHideOppoPaths)
static void(__cdecl*original_ShowHideOppoPaths)() = (void(__cdecl*)())0x0040ed4b;
CARM95_HOOK_FUNCTION(original_ShowHideOppoPaths, ShowHideOppoPaths)
void __cdecl ShowHideOppoPaths() {
    LOG_TRACE("()");


    if (function_hook_state_ShowHideOppoPaths == HOOK_ENABLED) {
        assert(0 && "ShowHideOppoPaths not implemented.");
        abort();
    } else {
        original_ShowHideOppoPaths();
    }
}

function_hook_state_t function_hook_state_DropElasticateyNode = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_DropElasticateyNode)
static void(__cdecl*original_DropElasticateyNode)() = (void(__cdecl*)())0x0040ee30;
CARM95_HOOK_FUNCTION(original_DropElasticateyNode, DropElasticateyNode)
void __cdecl DropElasticateyNode() {
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

    if (function_hook_state_DropElasticateyNode == HOOK_ENABLED) {
        assert(0 && "DropElasticateyNode not implemented.");
        abort();
    } else {
        original_DropElasticateyNode();
    }
}

function_hook_state_t function_hook_state_InsertAndElasticate = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_InsertAndElasticate)
static void(__cdecl*original_InsertAndElasticate)() = (void(__cdecl*)())0x0040f565;
CARM95_HOOK_FUNCTION(original_InsertAndElasticate, InsertAndElasticate)
void __cdecl InsertAndElasticate() {
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

    if (function_hook_state_InsertAndElasticate == HOOK_ENABLED) {
        assert(0 && "InsertAndElasticate not implemented.");
        abort();
    } else {
        original_InsertAndElasticate();
    }
}

function_hook_state_t function_hook_state_InsertAndDontElasticate = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_InsertAndDontElasticate)
static void(__cdecl*original_InsertAndDontElasticate)() = (void(__cdecl*)())0x0040fdf3;
CARM95_HOOK_FUNCTION(original_InsertAndDontElasticate, InsertAndDontElasticate)
void __cdecl InsertAndDontElasticate() {
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

    if (function_hook_state_InsertAndDontElasticate == HOOK_ENABLED) {
        assert(0 && "InsertAndDontElasticate not implemented.");
        abort();
    } else {
        original_InsertAndDontElasticate();
    }
}

function_hook_state_t function_hook_state_DropDeadEndNode = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_DropDeadEndNode)
static void(__cdecl*original_DropDeadEndNode)() = (void(__cdecl*)())0x004100f3;
CARM95_HOOK_FUNCTION(original_DropDeadEndNode, DropDeadEndNode)
void __cdecl DropDeadEndNode() {
    char str[256];
    LOG_TRACE("()");

    (void)str;

    if (function_hook_state_DropDeadEndNode == HOOK_ENABLED) {
        assert(0 && "DropDeadEndNode not implemented.");
        abort();
    } else {
        original_DropDeadEndNode();
    }
}

function_hook_state_t function_hook_state_DropNodeOnNodeAndStopElasticating = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_DropNodeOnNodeAndStopElasticating)
static void(__cdecl*original_DropNodeOnNodeAndStopElasticating)() = (void(__cdecl*)())0x0041020c;
CARM95_HOOK_FUNCTION(original_DropNodeOnNodeAndStopElasticating, DropNodeOnNodeAndStopElasticating)
void __cdecl DropNodeOnNodeAndStopElasticating() {
    int node_no;
    char str[256];
    br_scalar distance;
    LOG_TRACE("()");

    (void)node_no;
    (void)str;
    (void)distance;

    if (function_hook_state_DropNodeOnNodeAndStopElasticating == HOOK_ENABLED) {
        assert(0 && "DropNodeOnNodeAndStopElasticating not implemented.");
        abort();
    } else {
        original_DropNodeOnNodeAndStopElasticating();
    }
}

function_hook_state_t function_hook_state_WidenOppoPathSection = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_WidenOppoPathSection)
static void(__cdecl*original_WidenOppoPathSection)() = (void(__cdecl*)())0x004103c5;
CARM95_HOOK_FUNCTION(original_WidenOppoPathSection, WidenOppoPathSection)
void __cdecl WidenOppoPathSection() {
    LOG_TRACE("()");


    if (function_hook_state_WidenOppoPathSection == HOOK_ENABLED) {
        assert(0 && "WidenOppoPathSection not implemented.");
        abort();
    } else {
        original_WidenOppoPathSection();
    }
}

function_hook_state_t function_hook_state_NarrowOppoPathSection = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_NarrowOppoPathSection)
static void(__cdecl*original_NarrowOppoPathSection)() = (void(__cdecl*)())0x00410573;
CARM95_HOOK_FUNCTION(original_NarrowOppoPathSection, NarrowOppoPathSection)
void __cdecl NarrowOppoPathSection() {
    LOG_TRACE("()");


    if (function_hook_state_NarrowOppoPathSection == HOOK_ENABLED) {
        assert(0 && "NarrowOppoPathSection not implemented.");
        abort();
    } else {
        original_NarrowOppoPathSection();
    }
}

function_hook_state_t function_hook_state_IncreaseSectionMinSpeed = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_IncreaseSectionMinSpeed)
static void(__cdecl*original_IncreaseSectionMinSpeed)() = (void(__cdecl*)())0x0041059d;
CARM95_HOOK_FUNCTION(original_IncreaseSectionMinSpeed, IncreaseSectionMinSpeed)
void __cdecl IncreaseSectionMinSpeed() {
    LOG_TRACE("()");


    if (function_hook_state_IncreaseSectionMinSpeed == HOOK_ENABLED) {
        assert(0 && "IncreaseSectionMinSpeed not implemented.");
        abort();
    } else {
        original_IncreaseSectionMinSpeed();
    }
}

function_hook_state_t function_hook_state_DecreaseSectionMinSpeed = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_DecreaseSectionMinSpeed)
static void(__cdecl*original_DecreaseSectionMinSpeed)() = (void(__cdecl*)())0x00410a7f;
CARM95_HOOK_FUNCTION(original_DecreaseSectionMinSpeed, DecreaseSectionMinSpeed)
void __cdecl DecreaseSectionMinSpeed() {
    LOG_TRACE("()");


    if (function_hook_state_DecreaseSectionMinSpeed == HOOK_ENABLED) {
        assert(0 && "DecreaseSectionMinSpeed not implemented.");
        abort();
    } else {
        original_DecreaseSectionMinSpeed();
    }
}

function_hook_state_t function_hook_state_IncreaseSectionMaxSpeed = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_IncreaseSectionMaxSpeed)
static void(__cdecl*original_IncreaseSectionMaxSpeed)() = (void(__cdecl*)())0x00410aa8;
CARM95_HOOK_FUNCTION(original_IncreaseSectionMaxSpeed, IncreaseSectionMaxSpeed)
void __cdecl IncreaseSectionMaxSpeed() {
    LOG_TRACE("()");


    if (function_hook_state_IncreaseSectionMaxSpeed == HOOK_ENABLED) {
        assert(0 && "IncreaseSectionMaxSpeed not implemented.");
        abort();
    } else {
        original_IncreaseSectionMaxSpeed();
    }
}

function_hook_state_t function_hook_state_DecreaseSectionMaxSpeed = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_DecreaseSectionMaxSpeed)
static void(__cdecl*original_DecreaseSectionMaxSpeed)() = (void(__cdecl*)())0x00410ad1;
CARM95_HOOK_FUNCTION(original_DecreaseSectionMaxSpeed, DecreaseSectionMaxSpeed)
void __cdecl DecreaseSectionMaxSpeed() {
    LOG_TRACE("()");


    if (function_hook_state_DecreaseSectionMaxSpeed == HOOK_ENABLED) {
        assert(0 && "DecreaseSectionMaxSpeed not implemented.");
        abort();
    } else {
        original_DecreaseSectionMaxSpeed();
    }
}

function_hook_state_t function_hook_state_PullOppoPoint = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_PullOppoPoint)
static void(__cdecl*original_PullOppoPoint)() = (void(__cdecl*)())0x00410afa;
CARM95_HOOK_FUNCTION(original_PullOppoPoint, PullOppoPoint)
void __cdecl PullOppoPoint() {
    tS16 node_no;
    br_scalar distance;
    LOG_TRACE("()");

    (void)node_no;
    (void)distance;

    if (function_hook_state_PullOppoPoint == HOOK_ENABLED) {
        assert(0 && "PullOppoPoint not implemented.");
        abort();
    } else {
        original_PullOppoPoint();
    }
}

function_hook_state_t function_hook_state_ShowNodeInfo = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_ShowNodeInfo)
static void(__cdecl*original_ShowNodeInfo)() = (void(__cdecl*)())0x00410bfa;
CARM95_HOOK_FUNCTION(original_ShowNodeInfo, ShowNodeInfo)
void __cdecl ShowNodeInfo() {
    tS16 node_no;
    char str[256];
    br_scalar distance;
    LOG_TRACE("()");

    (void)node_no;
    (void)str;
    (void)distance;

    if (function_hook_state_ShowNodeInfo == HOOK_ENABLED) {
        assert(0 && "ShowNodeInfo not implemented.");
        abort();
    } else {
        original_ShowNodeInfo();
    }
}

function_hook_state_t function_hook_state_ShowSectionInfo1 = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_ShowSectionInfo1)
static void(__cdecl*original_ShowSectionInfo1)() = (void(__cdecl*)())0x00410d28;
CARM95_HOOK_FUNCTION(original_ShowSectionInfo1, ShowSectionInfo1)
void __cdecl ShowSectionInfo1() {
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

    if (function_hook_state_ShowSectionInfo1 == HOOK_ENABLED) {
        assert(0 && "ShowSectionInfo1 not implemented.");
        abort();
    } else {
        original_ShowSectionInfo1();
    }
}

function_hook_state_t function_hook_state_ShowSectionInfo2 = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_ShowSectionInfo2)
static void(__cdecl*original_ShowSectionInfo2)() = (void(__cdecl*)())0x00410e9b;
CARM95_HOOK_FUNCTION(original_ShowSectionInfo2, ShowSectionInfo2)
void __cdecl ShowSectionInfo2() {
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

    if (function_hook_state_ShowSectionInfo2 == HOOK_ENABLED) {
        assert(0 && "ShowSectionInfo2 not implemented.");
        abort();
    } else {
        original_ShowSectionInfo2();
    }
}

function_hook_state_t function_hook_state_DeleteOppoPathSection = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_DeleteOppoPathSection)
static void(__cdecl*original_DeleteOppoPathSection)() = (void(__cdecl*)())0x00411124;
CARM95_HOOK_FUNCTION(original_DeleteOppoPathSection, DeleteOppoPathSection)
void __cdecl DeleteOppoPathSection() {
    br_scalar distance;
    br_vector3 intersect;
    br_vector3 direction_v;
    tS16 section_no;
    LOG_TRACE("()");

    (void)distance;
    (void)intersect;
    (void)direction_v;
    (void)section_no;

    if (function_hook_state_DeleteOppoPathSection == HOOK_ENABLED) {
        assert(0 && "DeleteOppoPathSection not implemented.");
        abort();
    } else {
        original_DeleteOppoPathSection();
    }
}

function_hook_state_t function_hook_state_DeleteOppoPathNodeAndSections = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_DeleteOppoPathNodeAndSections)
static void(__cdecl*original_DeleteOppoPathNodeAndSections)() = (void(__cdecl*)())0x00411206;
CARM95_HOOK_FUNCTION(original_DeleteOppoPathNodeAndSections, DeleteOppoPathNodeAndSections)
void __cdecl DeleteOppoPathNodeAndSections() {
    br_scalar distance;
    tS16 node_no;
    LOG_TRACE("()");

    (void)distance;
    (void)node_no;

    if (function_hook_state_DeleteOppoPathNodeAndSections == HOOK_ENABLED) {
        assert(0 && "DeleteOppoPathNodeAndSections not implemented.");
        abort();
    } else {
        original_DeleteOppoPathNodeAndSections();
    }
}

function_hook_state_t function_hook_state_DeleteOppoPathNodeAndJoin = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_DeleteOppoPathNodeAndJoin)
static void(__cdecl*original_DeleteOppoPathNodeAndJoin)() = (void(__cdecl*)())0x004112e2;
CARM95_HOOK_FUNCTION(original_DeleteOppoPathNodeAndJoin, DeleteOppoPathNodeAndJoin)
void __cdecl DeleteOppoPathNodeAndJoin() {
    br_scalar distance;
    tS16 node_no;
    LOG_TRACE("()");

    (void)distance;
    (void)node_no;

    if (function_hook_state_DeleteOppoPathNodeAndJoin == HOOK_ENABLED) {
        assert(0 && "DeleteOppoPathNodeAndJoin not implemented.");
        abort();
    } else {
        original_DeleteOppoPathNodeAndJoin();
    }
}

function_hook_state_t function_hook_state_ReverseSectionDirection = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_ReverseSectionDirection)
static void(__cdecl*original_ReverseSectionDirection)() = (void(__cdecl*)())0x004114dd;
CARM95_HOOK_FUNCTION(original_ReverseSectionDirection, ReverseSectionDirection)
void __cdecl ReverseSectionDirection() {
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

    if (function_hook_state_ReverseSectionDirection == HOOK_ENABLED) {
        assert(0 && "ReverseSectionDirection not implemented.");
        abort();
    } else {
        original_ReverseSectionDirection();
    }
}

function_hook_state_t function_hook_state_CycleSectionType = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_CycleSectionType)
static void(__cdecl*original_CycleSectionType)() = (void(__cdecl*)())0x0041169c;
CARM95_HOOK_FUNCTION(original_CycleSectionType, CycleSectionType)
void __cdecl CycleSectionType() {
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

    if (function_hook_state_CycleSectionType == HOOK_ENABLED) {
        assert(0 && "CycleSectionType not implemented.");
        abort();
    } else {
        original_CycleSectionType();
    }
}

function_hook_state_t function_hook_state_ToggleOneWayNess = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_ToggleOneWayNess)
static void(__cdecl*original_ToggleOneWayNess)() = (void(__cdecl*)())0x004117ee;
CARM95_HOOK_FUNCTION(original_ToggleOneWayNess, ToggleOneWayNess)
void __cdecl ToggleOneWayNess() {
    br_scalar distance;
    br_vector3 intersect;
    br_vector3 direction_v;
    tS16 section_no;
    LOG_TRACE("()");

    (void)distance;
    (void)intersect;
    (void)direction_v;
    (void)section_no;

    if (function_hook_state_ToggleOneWayNess == HOOK_ENABLED) {
        assert(0 && "ToggleOneWayNess not implemented.");
        abort();
    } else {
        original_ToggleOneWayNess();
    }
}

function_hook_state_t function_hook_state_CopStartPointInfo = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_CopStartPointInfo)
static void(__cdecl*original_CopStartPointInfo)() = (void(__cdecl*)())0x00411947;
CARM95_HOOK_FUNCTION(original_CopStartPointInfo, CopStartPointInfo)
void __cdecl CopStartPointInfo() {
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

    if (function_hook_state_CopStartPointInfo == HOOK_ENABLED) {
        assert(0 && "CopStartPointInfo not implemented.");
        abort();
    } else {
        original_CopStartPointInfo();
    }
}

function_hook_state_t function_hook_state_DropCopStartPoint = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_DropCopStartPoint)
static void(__cdecl*original_DropCopStartPoint)() = (void(__cdecl*)())0x00411ae8;
CARM95_HOOK_FUNCTION(original_DropCopStartPoint, DropCopStartPoint)
void __cdecl DropCopStartPoint() {
    char str[256];
    LOG_TRACE("()");

    (void)str;

    if (function_hook_state_DropCopStartPoint == HOOK_ENABLED) {
        assert(0 && "DropCopStartPoint not implemented.");
        abort();
    } else {
        original_DropCopStartPoint();
    }
}

function_hook_state_t function_hook_state_DeleteCopStartPoint = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_DeleteCopStartPoint)
static void(__cdecl*original_DeleteCopStartPoint)() = (void(__cdecl*)())0x00411c18;
CARM95_HOOK_FUNCTION(original_DeleteCopStartPoint, DeleteCopStartPoint)
void __cdecl DeleteCopStartPoint() {
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

    if (function_hook_state_DeleteCopStartPoint == HOOK_ENABLED) {
        assert(0 && "DeleteCopStartPoint not implemented.");
        abort();
    } else {
        original_DeleteCopStartPoint();
    }
}

function_hook_state_t function_hook_state_CycleCopStartPointType = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_CycleCopStartPointType)
static void(__cdecl*original_CycleCopStartPointType)() = (void(__cdecl*)())0x00411e7f;
CARM95_HOOK_FUNCTION(original_CycleCopStartPointType, CycleCopStartPointType)
void __cdecl CycleCopStartPointType() {
    LOG_TRACE("()");


    if (function_hook_state_CycleCopStartPointType == HOOK_ENABLED) {
        assert(0 && "CycleCopStartPointType not implemented.");
        abort();
    } else {
        original_CycleCopStartPointType();
    }
}

