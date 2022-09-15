#include "structur.h"

#include "harness/trace.h"

#include "carm95_hooks.h"

#include <stdio.h>
int * hookvar_gLast_wrong_checkpoint  = (void*)0x00509a60;
 // Suffix added to avoid duplicate symbol
int * hookvar_gMirror_on__structur  = (void*)0x00509a64;
int * hookvar_gPratcam_on  = (void*)0x00509a68;
int * hookvar_gCockpit_on  = (void*)0x00509a6c;
int(* hookvar_gOpponent_mix )[10][5] = (void*)0x00509a70;
tU32 * hookvar_gLast_checkpoint_time  = (void*)0x00509b38;
tRace_over_reason * hookvar_gRace_over_reason  = (void*)0x00551dbc;

static int(*original_NumberOfOpponentsLeft)() = (int(*)())0x00413f90;
CARM95_HOOK_FUNCTION(original_NumberOfOpponentsLeft, NumberOfOpponentsLeft)
int NumberOfOpponentsLeft() {
    int i;
    int car_count;
    int result;
    tCar_spec *the_car;
    LOG_TRACE("()");

    (void)i;
    (void)car_count;
    (void)result;
    (void)the_car;

    return original_NumberOfOpponentsLeft();
}

static void(*original_RaceCompleted)(tRace_over_reason, ...) = (void(*)(tRace_over_reason, ...))0x00413ffe;
CARM95_HOOK_FUNCTION(original_RaceCompleted, RaceCompleted)
void RaceCompleted(tRace_over_reason pReason) {
    LOG_TRACE("(%d)", pReason);

    (void)pReason;

    original_RaceCompleted(pReason);
}

static void(*original_Checkpoint)(int, int, ...) = (void(*)(int, int, ...))0x004141ca;
CARM95_HOOK_FUNCTION(original_Checkpoint, Checkpoint)
void Checkpoint(int pCheckpoint_index, int pDo_sound) {
    LOG_TRACE("(%d, %d)", pCheckpoint_index, pDo_sound);

    (void)pCheckpoint_index;
    (void)pDo_sound;

    original_Checkpoint(pCheckpoint_index, pDo_sound);
}

static void(*original_IncrementCheckpoint)() = (void(*)())0x00414206;
CARM95_HOOK_FUNCTION(original_IncrementCheckpoint, IncrementCheckpoint)
void IncrementCheckpoint() {
    int done_voice;
    LOG_TRACE("()");

    (void)done_voice;

    original_IncrementCheckpoint();
}

static void(*original_IncrementLap)() = (void(*)())0x0041433c;
CARM95_HOOK_FUNCTION(original_IncrementLap, IncrementLap)
void IncrementLap() {
    int i;
    LOG_TRACE("()");

    (void)i;

    original_IncrementLap();
}

static int(*original_RayHitFace)(br_vector3 *, br_vector3 *, br_vector3 *, br_vector3 *, br_vector3 *, br_vector3 *, ...) = (int(*)(br_vector3 *, br_vector3 *, br_vector3 *, br_vector3 *, br_vector3 *, br_vector3 *, ...))0x00414835;
CARM95_HOOK_FUNCTION(original_RayHitFace, RayHitFace)
int RayHitFace(br_vector3 *pV0, br_vector3 *pV1, br_vector3 *pV2, br_vector3 *pNormal, br_vector3 *pStart, br_vector3 *pDir) {
    tFace_ref the_face;
    br_scalar rt;
    LOG_TRACE("(%p, %p, %p, %p, %p, %p)", pV0, pV1, pV2, pNormal, pStart, pDir);

    (void)pV0;
    (void)pV1;
    (void)pV2;
    (void)pNormal;
    (void)pStart;
    (void)pDir;
    (void)the_face;
    (void)rt;

    return original_RayHitFace(pV0, pV1, pV2, pNormal, pStart, pDir);
}

static void(*original_WrongCheckpoint)(int, ...) = (void(*)(int, ...))0x00414373;
CARM95_HOOK_FUNCTION(original_WrongCheckpoint, WrongCheckpoint)
void WrongCheckpoint(int pCheckpoint_index) {
    LOG_TRACE("(%d)", pCheckpoint_index);

    (void)pCheckpoint_index;

    original_WrongCheckpoint(pCheckpoint_index);
}

static void(*original_CheckCheckpoints)() = (void(*)())0x00414468;
CARM95_HOOK_FUNCTION(original_CheckCheckpoints, CheckCheckpoints)
void CheckCheckpoints() {
    tCar_spec *car;
    br_vector3 orig;
    br_vector3 dir;
    int i;
    int j;
    int cat;
    int car_count;
    int car_index;
    tNet_game_player_info *net_player;
    LOG_TRACE("()");

    (void)car;
    (void)orig;
    (void)dir;
    (void)i;
    (void)j;
    (void)cat;
    (void)car_count;
    (void)car_index;
    (void)net_player;

    original_CheckCheckpoints();
}

static void(*original_TotalRepair)() = (void(*)())0x004148f7;
CARM95_HOOK_FUNCTION(original_TotalRepair, TotalRepair)
void TotalRepair() {
    LOG_TRACE("()");


    original_TotalRepair();
}

static void(*original_DoLogos)() = (void(*)())0x00414e48;
CARM95_HOOK_FUNCTION(original_DoLogos, DoLogos)
void DoLogos() {
    LOG_TRACE("()");


    original_DoLogos();
}

static void(*original_DoProgOpeningAnimation)() = (void(*)())0x00414e71;
CARM95_HOOK_FUNCTION(original_DoProgOpeningAnimation, DoProgOpeningAnimation)
void DoProgOpeningAnimation() {
    LOG_TRACE("()");


    original_DoProgOpeningAnimation();
}

static void(*original_DoProgramDemo)() = (void(*)())0x00414e94;
CARM95_HOOK_FUNCTION(original_DoProgramDemo, DoProgramDemo)
void DoProgramDemo() {
    LOG_TRACE("()");


    original_DoProgramDemo();
}

static int(*original_ChooseOpponent)(int, int *, ...) = (int(*)(int, int *, ...))0x00414a47;
CARM95_HOOK_FUNCTION(original_ChooseOpponent, ChooseOpponent)
int ChooseOpponent(int pNastiness, int *pHad_scum) {
    int i;
    int count;
    int temp_array[40];
    LOG_TRACE("(%d, %p)", pNastiness, pHad_scum);

    (void)pNastiness;
    (void)pHad_scum;
    (void)i;
    (void)count;
    (void)temp_array;

    return original_ChooseOpponent(pNastiness, pHad_scum);
}

static void(*original_SelectOpponents)(tRace_info *, ...) = (void(*)(tRace_info *, ...))0x00414925;
CARM95_HOOK_FUNCTION(original_SelectOpponents, SelectOpponents)
void SelectOpponents(tRace_info *pRace_info) {
    int i;
    int rank_band;
    int nastiness;
    int had_scum;
    LOG_TRACE("(%p)", pRace_info);

    (void)pRace_info;
    (void)i;
    (void)rank_band;
    (void)nastiness;
    (void)had_scum;

    original_SelectOpponents(pRace_info);
}

static int(*original_PickNetRace)(int, tNet_sequence_type, ...) = (int(*)(int, tNet_sequence_type, ...))0x00414b57;
CARM95_HOOK_FUNCTION(original_PickNetRace, PickNetRace)
int PickNetRace(int pCurrent_race, tNet_sequence_type pNet_race_sequence) {
    int i;
    int new_index;
    int races_count;
    int most_seldom_seen;
    int races_to_pick_from[50];
    LOG_TRACE("(%d, %d)", pCurrent_race, pNet_race_sequence);

    (void)pCurrent_race;
    (void)pNet_race_sequence;
    (void)i;
    (void)new_index;
    (void)races_count;
    (void)most_seldom_seen;
    (void)races_to_pick_from;

    return original_PickNetRace(pCurrent_race, pNet_race_sequence);
}

static void(*original_SwapNetCarsLoad)() = (void(*)())0x0041542b;
CARM95_HOOK_FUNCTION(original_SwapNetCarsLoad, SwapNetCarsLoad)
void SwapNetCarsLoad() {
    int i;
    int switched_res;
    LOG_TRACE("()");

    (void)i;
    (void)switched_res;

    original_SwapNetCarsLoad();
}

static void(*original_SwapNetCarsDispose)() = (void(*)())0x0041552d;
CARM95_HOOK_FUNCTION(original_SwapNetCarsDispose, SwapNetCarsDispose)
void SwapNetCarsDispose() {
    int i;
    LOG_TRACE("()");

    (void)i;

    original_SwapNetCarsDispose();
}

static void(*original_DoGame)() = (void(*)())0x00414ebc;
CARM95_HOOK_FUNCTION(original_DoGame, DoGame)
void DoGame() {
    tSO_result options_result;
    tRace_result race_result;
    int second_select_race;
    int first_summary_done;
    int i;
    LOG_TRACE("()");

    (void)options_result;
    (void)race_result;
    (void)second_select_race;
    (void)first_summary_done;
    (void)i;

    original_DoGame();
}

static void(*original_InitialiseProgramState)() = (void(*)())0x00414ca8;
CARM95_HOOK_FUNCTION(original_InitialiseProgramState, InitialiseProgramState)
void InitialiseProgramState() {
    LOG_TRACE("()");


    original_InitialiseProgramState();
}

static void(*original_DoProgram)() = (void(*)())0x00414d8a;
CARM95_HOOK_FUNCTION(original_DoProgram, DoProgram)
void DoProgram() {
    LOG_TRACE("()");


    original_DoProgram();
}

static void(*original_JumpTheStart)() = (void(*)())0x004155d4;
CARM95_HOOK_FUNCTION(original_JumpTheStart, JumpTheStart)
void JumpTheStart() {
    char s[256];
    LOG_TRACE("()");

    (void)s;

    original_JumpTheStart();
}

static void(*original_GoingToInterfaceFromRace)() = (void(*)())0x004156c2;
CARM95_HOOK_FUNCTION(original_GoingToInterfaceFromRace, GoingToInterfaceFromRace)
void GoingToInterfaceFromRace() {
    LOG_TRACE("()");


    original_GoingToInterfaceFromRace();
}

static void(*original_GoingBackToRaceFromInterface)() = (void(*)())0x00415700;
CARM95_HOOK_FUNCTION(original_GoingBackToRaceFromInterface, GoingBackToRaceFromInterface)
void GoingBackToRaceFromInterface() {
    LOG_TRACE("()");


    original_GoingBackToRaceFromInterface();
}

