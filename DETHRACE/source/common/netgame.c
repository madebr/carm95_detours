#include "netgame.h"

#include "harness/trace.h"

#include "carm95_hooks.h"

#include <stdio.h>
int(* hookvar_gPowerup_cost )[4] = (void*)0x0050c5e0;
#if 0
int(* hookvar_gGame_scores )[6];
#endif
int * hookvar_gPed_target  = (void*)0x0053220c;
int * hookvar_gNot_shown_race_type_headup  = (void*)0x00532210;
tU32 * hookvar_gLast_it_change  = (void*)0x00532204;
tU32 * hookvar_gTime_for_punishment  = (void*)0x00532208;
tNet_game_player_info ** hookvar_gLast_lepper  = (void*)0x00532200;
int * hookvar_gInitialised_grid  = (void*)0x00551d7c;
int * hookvar_gIt_or_fox  = (void*)0x00551d80;

static void(*original_SendCarData)(tU32, ...) = (void(*)(tU32, ...))0x0042f2d0;
CARM95_HOOK_FUNCTION(original_SendCarData, SendCarData)
void SendCarData(tU32 pNext_frame_time) {
    tNet_contents *contents;
    tCar_spec *car;
    tCollision_info *ncar;
    int i;
    int j;
    static tU32 last_time;
    tU32 time;
    int damaged_wheels;
    LOG_TRACE("(%u)", pNext_frame_time);

    (void)pNext_frame_time;
    (void)contents;
    (void)car;
    (void)ncar;
    (void)i;
    (void)j;
    (void)last_time;
    (void)time;
    (void)damaged_wheels;

    original_SendCarData(pNext_frame_time);
}

static void(*original_ReceivedRecover)(tNet_contents *, ...) = (void(*)(tNet_contents *, ...))0x0042fc35;
CARM95_HOOK_FUNCTION(original_ReceivedRecover, ReceivedRecover)
void ReceivedRecover(tNet_contents *pContents) {
    int i;
    LOG_TRACE("(%p)", pContents);

    (void)pContents;
    (void)i;

    original_ReceivedRecover(pContents);
}

static void(*original_CopyMechanics)(tCar_spec *, tNet_contents *, ...) = (void(*)(tCar_spec *, tNet_contents *, ...))0x0042fcb8;
CARM95_HOOK_FUNCTION(original_CopyMechanics, CopyMechanics)
void CopyMechanics(tCar_spec *pCar, tNet_contents *pContents) {
    int j;
    LOG_TRACE("(%p, %p)", pCar, pContents);

    (void)pCar;
    (void)pContents;
    (void)j;

    original_CopyMechanics(pCar, pContents);
}

static void(*original_ReceivedMechanics)(tNet_contents *, ...) = (void(*)(tNet_contents *, ...))0x0042fd29;
CARM95_HOOK_FUNCTION(original_ReceivedMechanics, ReceivedMechanics)
void ReceivedMechanics(tNet_contents *pContents) {
    int i;
    tCar_spec *car;
    LOG_TRACE("(%p)", pContents);

    (void)pContents;
    (void)i;
    (void)car;

    original_ReceivedMechanics(pContents);
}

static void(*original_ReceivedCopInfo)(tNet_contents *, ...) = (void(*)(tNet_contents *, ...))0x004302c5;
CARM95_HOOK_FUNCTION(original_ReceivedCopInfo, ReceivedCopInfo)
void ReceivedCopInfo(tNet_contents *pContents) {
    tCar_spec *c;
    int i;
    LOG_TRACE("(%p)", pContents);

    (void)pContents;
    (void)c;
    (void)i;

    original_ReceivedCopInfo(pContents);
}

void SendAllNonCarPositions() {
    int i;
    br_actor **list;
    tNon_car_spec *non_car;
    tNet_contents *contents;
    LOG_TRACE("()");

    (void)i;
    (void)list;
    (void)non_car;
    (void)contents;

    NOT_IMPLEMENTED();
}

static void(*original_ReceivedNonCarPosition)(tNet_contents *, ...) = (void(*)(tNet_contents *, ...))0x00430520;
CARM95_HOOK_FUNCTION(original_ReceivedNonCarPosition, ReceivedNonCarPosition)
void ReceivedNonCarPosition(tNet_contents *pContents) {
    br_actor *actor;
    LOG_TRACE("(%p)", pContents);

    (void)pContents;
    (void)actor;

    original_ReceivedNonCarPosition(pContents);
}

static void(*original_ReceivedNonCar)(tNet_contents *, ...) = (void(*)(tNet_contents *, ...))0x0043058d;
CARM95_HOOK_FUNCTION(original_ReceivedNonCar, ReceivedNonCar)
void ReceivedNonCar(tNet_contents *pContents) {
    br_actor *actor;
    br_vector3 tv;
    tU8 cx;
    tU8 cz;
    tTrack_spec *track_spec;
    tNon_car_spec *ncar;
    tCollision_info *c;
    LOG_TRACE("(%p)", pContents);

    (void)pContents;
    (void)actor;
    (void)tv;
    (void)cx;
    (void)cz;
    (void)track_spec;
    (void)ncar;
    (void)c;

    original_ReceivedNonCar(pContents);
}

static void(*original_SignalToStartRace2)(int, ...) = (void(*)(int, ...))0x004308fe;
CARM95_HOOK_FUNCTION(original_SignalToStartRace2, SignalToStartRace2)
void SignalToStartRace2(int pIndex) {
    tNet_message *the_message;
    int i;
    int j;
    LOG_TRACE("(%d)", pIndex);

    (void)pIndex;
    (void)the_message;
    (void)i;
    (void)j;

    original_SignalToStartRace2(pIndex);
}

static void(*original_SignalToStartRace)() = (void(*)())0x00430bac;
CARM95_HOOK_FUNCTION(original_SignalToStartRace, SignalToStartRace)
void SignalToStartRace() {
    LOG_TRACE("()");


    original_SignalToStartRace();
}

static void(*original_SetUpNetCarPositions)() = (void(*)())0x00430bcd;
CARM95_HOOK_FUNCTION(original_SetUpNetCarPositions, SetUpNetCarPositions)
void SetUpNetCarPositions() {
    int i;
    int j;
    int k;
    int grid_index;
    int racer_count;
    LOG_TRACE("()");

    (void)i;
    (void)j;
    (void)k;
    (void)grid_index;
    (void)racer_count;

    original_SetUpNetCarPositions();
}

static void(*original_ReinitialiseCar)(tCar_spec *, ...) = (void(*)(tCar_spec *, ...))0x00430f14;
CARM95_HOOK_FUNCTION(original_ReinitialiseCar, ReinitialiseCar)
void ReinitialiseCar(tCar_spec *pCar) {
    int i;
    LOG_TRACE("(%p)", pCar);

    (void)pCar;
    (void)i;

    original_ReinitialiseCar(pCar);
}

static void(*original_RepositionPlayer)(int, ...) = (void(*)(int, ...))0x00430f6e;
CARM95_HOOK_FUNCTION(original_RepositionPlayer, RepositionPlayer)
void RepositionPlayer(int pIndex) {
    tNet_message *the_message;
    tCar_spec *car;
    LOG_TRACE("(%d)", pIndex);

    (void)pIndex;
    (void)the_message;
    (void)car;

    original_RepositionPlayer(pIndex);
}

static void(*original_DisableCar)(tCar_spec *, ...) = (void(*)(tCar_spec *, ...))0x00431094;
CARM95_HOOK_FUNCTION(original_DisableCar, DisableCar)
void DisableCar(tCar_spec *pCar) {
    LOG_TRACE("(%p)", pCar);

    (void)pCar;

    original_DisableCar(pCar);
}

static void(*original_EnableCar)(tCar_spec *, ...) = (void(*)(tCar_spec *, ...))0x00431165;
CARM95_HOOK_FUNCTION(original_EnableCar, EnableCar)
void EnableCar(tCar_spec *pCar) {
    LOG_TRACE("(%p)", pCar);

    (void)pCar;

    original_EnableCar(pCar);
}

static void(*original_DoNetworkHeadups)(int, ...) = (void(*)(int, ...))0x00431236;
CARM95_HOOK_FUNCTION(original_DoNetworkHeadups, DoNetworkHeadups)
void DoNetworkHeadups(int pCredits) {
    char s[256];
    char s2[256];
    static tU32 last_flash;
    static int flash_state;
    LOG_TRACE("(%d)", pCredits);

    (void)pCredits;
    (void)s;
    (void)s2;
    (void)last_flash;
    (void)flash_state;

    original_DoNetworkHeadups(pCredits);
}

static int(*original_SortNetHeadAscending)(void *, void *, ...) = (int(*)(void *, void *, ...))0x00431ff8;
CARM95_HOOK_FUNCTION(original_SortNetHeadAscending, SortNetHeadAscending)
int SortNetHeadAscending(void *pFirst_one, void *pSecond_one) {
    LOG_TRACE("(%p, %p)", pFirst_one, pSecond_one);

    (void)pFirst_one;
    (void)pSecond_one;

    return original_SortNetHeadAscending(pFirst_one, pSecond_one);
}

static int(*original_SortNetHeadDescending)(void *, void *, ...) = (int(*)(void *, void *, ...))0x004320a9;
CARM95_HOOK_FUNCTION(original_SortNetHeadDescending, SortNetHeadDescending)
int SortNetHeadDescending(void *pFirst_one, void *pSecond_one) {
    LOG_TRACE("(%p, %p)", pFirst_one, pSecond_one);

    (void)pFirst_one;
    (void)pSecond_one;

    return original_SortNetHeadDescending(pFirst_one, pSecond_one);
}

static void(*original_ClipName)(char *, tDR_font *, int, ...) = (void(*)(char *, tDR_font *, int, ...))0x0043215a;
CARM95_HOOK_FUNCTION(original_ClipName, ClipName)
void ClipName(char *pName, tDR_font *pFont, int pMax_width) {
    LOG_TRACE("(\"%s\", %p, %d)", pName, pFont, pMax_width);

    (void)pName;
    (void)pFont;
    (void)pMax_width;

    original_ClipName(pName, pFont, pMax_width);
}

static void(*original_DoNetScores2)(int, ...) = (void(*)(int, ...))0x004315c0;
CARM95_HOOK_FUNCTION(original_DoNetScores2, DoNetScores2)
void DoNetScores2(int pOnly_sort_scores) {
    int i;
    int j;
    int score;
    int flags;
    int index;
    int right_edge;
    int x;
    int len;
    int ascending_order;
    char s[256];
    static tU32 last_flash;
    static int flash_state;
    tHeadup_pair headup_pairs[6];
    LOG_TRACE("(%d)", pOnly_sort_scores);

    (void)pOnly_sort_scores;
    (void)i;
    (void)j;
    (void)score;
    (void)flags;
    (void)index;
    (void)right_edge;
    (void)x;
    (void)len;
    (void)ascending_order;
    (void)s;
    (void)last_flash;
    (void)flash_state;
    (void)headup_pairs;

    original_DoNetScores2(pOnly_sort_scores);
}

static void(*original_DoNetScores)() = (void(*)())0x004321a5;
CARM95_HOOK_FUNCTION(original_DoNetScores, DoNetScores)
void DoNetScores() {
    LOG_TRACE("()");


    original_DoNetScores();
}

static void(*original_InitNetHeadups)() = (void(*)())0x004321ba;
CARM95_HOOK_FUNCTION(original_InitNetHeadups, InitNetHeadups)
void InitNetHeadups() {
    LOG_TRACE("()");


    original_InitNetHeadups();
}

static void(*original_DisposeNetHeadups)() = (void(*)())0x0043221f;
CARM95_HOOK_FUNCTION(original_DisposeNetHeadups, DisposeNetHeadups)
void DisposeNetHeadups() {
    LOG_TRACE("()");


    original_DisposeNetHeadups();
}

static void(*original_EverybodysLost)() = (void(*)())0x00433554;
CARM95_HOOK_FUNCTION(original_EverybodysLost, EverybodysLost)
void EverybodysLost() {
    tNet_message *the_message;
    int i;
    LOG_TRACE("()");

    (void)the_message;
    (void)i;

    original_EverybodysLost();
}

static void(*original_DeclareWinner)(int, ...) = (void(*)(int, ...))0x0043227c;
CARM95_HOOK_FUNCTION(original_DeclareWinner, DeclareWinner)
void DeclareWinner(int pWinner_index) {
    tNet_message *the_message;
    int i;
    int j;
    int best_score_index;
    char s[256];
    LOG_TRACE("(%d)", pWinner_index);

    (void)pWinner_index;
    (void)the_message;
    (void)i;
    (void)j;
    (void)best_score_index;
    (void)s;

    original_DeclareWinner(pWinner_index);
}

static void(*original_PlayerIsIt)(tNet_game_player_info *, ...) = (void(*)(tNet_game_player_info *, ...))0x004325be;
CARM95_HOOK_FUNCTION(original_PlayerIsIt, PlayerIsIt)
void PlayerIsIt(tNet_game_player_info *pPlayer) {
    int i;
    char s[256];
    LOG_TRACE("(%p)", pPlayer);

    (void)pPlayer;
    (void)i;
    (void)s;

    original_PlayerIsIt(pPlayer);
}

static int(*original_FarEnoughAway)(tNet_game_player_info *, tNet_game_player_info *, ...) = (int(*)(tNet_game_player_info *, tNet_game_player_info *, ...))0x004335cd;
CARM95_HOOK_FUNCTION(original_FarEnoughAway, FarEnoughAway)
int FarEnoughAway(tNet_game_player_info *pPlayer_1, tNet_game_player_info *pPlayer_2) {
    br_vector3 difference;
    LOG_TRACE("(%p, %p)", pPlayer_1, pPlayer_2);

    (void)pPlayer_1;
    (void)pPlayer_2;
    (void)difference;

    return original_FarEnoughAway(pPlayer_1, pPlayer_2);
}

static void(*original_CarInContactWithItOrFox)(tNet_game_player_info *, ...) = (void(*)(tNet_game_player_info *, ...))0x004327a5;
CARM95_HOOK_FUNCTION(original_CarInContactWithItOrFox, CarInContactWithItOrFox)
void CarInContactWithItOrFox(tNet_game_player_info *pPlayer) {
    LOG_TRACE("(%p)", pPlayer);

    (void)pPlayer;

    original_CarInContactWithItOrFox(pPlayer);
}

static void(*original_SelectRandomItOrFox)(int, ...) = (void(*)(int, ...))0x00433676;
CARM95_HOOK_FUNCTION(original_SelectRandomItOrFox, SelectRandomItOrFox)
void SelectRandomItOrFox(int pNot_this_one) {
    int i;
    int new_choice;
    LOG_TRACE("(%d)", pNot_this_one);

    (void)pNot_this_one;
    (void)i;
    (void)new_choice;

    original_SelectRandomItOrFox(pNot_this_one);
}

static void(*original_CalcPlayerScores)() = (void(*)())0x00432865;
CARM95_HOOK_FUNCTION(original_CalcPlayerScores, CalcPlayerScores)
void CalcPlayerScores() {
    int i;
    int j;
    int knock_out_bit;
    int e_dam;
    int t_dam;
    int d_dam;
    int w_dam;
    int cars_left;
    int car_left;
    int flags;
    int score;
    int highest;
    int next_highest;
    int lowest_score;
    int player_left;
    int new_choice;
    tCar_spec *car;
    tNet_message *message;
    tS32 time;
    char s[256];
    tNet_game_player_info *lowest_score_player;
    LOG_TRACE("()");

    (void)i;
    (void)j;
    (void)knock_out_bit;
    (void)e_dam;
    (void)t_dam;
    (void)d_dam;
    (void)w_dam;
    (void)cars_left;
    (void)car_left;
    (void)flags;
    (void)score;
    (void)highest;
    (void)next_highest;
    (void)lowest_score;
    (void)player_left;
    (void)new_choice;
    (void)car;
    (void)message;
    (void)time;
    (void)s;
    (void)lowest_score_player;

    original_CalcPlayerScores();
}

static void(*original_SendPlayerScores)() = (void(*)())0x004337a4;
CARM95_HOOK_FUNCTION(original_SendPlayerScores, SendPlayerScores)
void SendPlayerScores() {
    tNet_contents *the_contents;
    int i;
    LOG_TRACE("()");

    (void)the_contents;
    (void)i;

    original_SendPlayerScores();
}

static void(*original_DoNetGameManagement)() = (void(*)())0x00432843;
CARM95_HOOK_FUNCTION(original_DoNetGameManagement, DoNetGameManagement)
void DoNetGameManagement() {
    LOG_TRACE("()");


    original_DoNetGameManagement();
}

static void(*original_InitialisePlayerScore)(tNet_game_player_info *, ...) = (void(*)(tNet_game_player_info *, ...))0x0043385c;
CARM95_HOOK_FUNCTION(original_InitialisePlayerScore, InitialisePlayerScore)
void InitialisePlayerScore(tNet_game_player_info *pPlayer) {
    LOG_TRACE("(%p)", pPlayer);

    (void)pPlayer;

    original_InitialisePlayerScore(pPlayer);
}

static void(*original_InitPlayers)() = (void(*)())0x00433937;
CARM95_HOOK_FUNCTION(original_InitPlayers, InitPlayers)
void InitPlayers() {
    int i;
    LOG_TRACE("()");

    (void)i;

    original_InitPlayers();
}

static void(*original_BuyPSPowerup)(int, ...) = (void(*)(int, ...))0x004339be;
CARM95_HOOK_FUNCTION(original_BuyPSPowerup, BuyPSPowerup)
void BuyPSPowerup(int pIndex) {
    char s[256];
    char s2[256];
    LOG_TRACE("(%d)", pIndex);

    (void)pIndex;
    (void)s;
    (void)s2;

    original_BuyPSPowerup(pIndex);
}

static void(*original_BuyArmour)() = (void(*)())0x00433b29;
CARM95_HOOK_FUNCTION(original_BuyArmour, BuyArmour)
void BuyArmour() {
    LOG_TRACE("()");


    original_BuyArmour();
}

static void(*original_BuyPower)() = (void(*)())0x00433b3e;
CARM95_HOOK_FUNCTION(original_BuyPower, BuyPower)
void BuyPower() {
    LOG_TRACE("()");


    original_BuyPower();
}

static void(*original_BuyOffense)() = (void(*)())0x00433bf9;
CARM95_HOOK_FUNCTION(original_BuyOffense, BuyOffense)
void BuyOffense() {
    LOG_TRACE("()");


    original_BuyOffense();
}

static void(*original_UseGeneralScore)(int, ...) = (void(*)(int, ...))0x00433c0e;
CARM95_HOOK_FUNCTION(original_UseGeneralScore, UseGeneralScore)
void UseGeneralScore(int pScore) {
    int i;
    LOG_TRACE("(%d)", pScore);

    (void)pScore;
    (void)i;

    original_UseGeneralScore(pScore);
}

static void(*original_NetSendEnvironmentChanges)(tNet_game_player_info *, ...) = (void(*)(tNet_game_player_info *, ...))0x00433d0c;
CARM95_HOOK_FUNCTION(original_NetSendEnvironmentChanges, NetSendEnvironmentChanges)
void NetSendEnvironmentChanges(tNet_game_player_info *pPlayer) {
    LOG_TRACE("(%p)", pPlayer);

    (void)pPlayer;

    original_NetSendEnvironmentChanges(pPlayer);
}

static void(*original_UpdateEnvironments)() = (void(*)())0x00433e1b;
CARM95_HOOK_FUNCTION(original_UpdateEnvironments, UpdateEnvironments)
void UpdateEnvironments() {
    int i;
    LOG_TRACE("()");

    (void)i;

    original_UpdateEnvironments();
}

static void(*original_ReceivedGameplay)(tNet_contents *, tNet_message *, tU32, ...) = (void(*)(tNet_contents *, tNet_message *, tU32, ...))0x00433eac;
CARM95_HOOK_FUNCTION(original_ReceivedGameplay, ReceivedGameplay)
void ReceivedGameplay(tNet_contents *pContents, tNet_message *pMessage, tU32 pReceive_time) {
    int must_revert_reentrancy;
    int gPixel_buffer_size;
    char *gPixels_copy;
    char *gPalette_copy;
    static int pause_semaphore;
    LOG_TRACE("(%p, %p, %u)", pContents, pMessage, pReceive_time);

    (void)pContents;
    (void)pMessage;
    (void)pReceive_time;
    (void)must_revert_reentrancy;
    (void)gPixel_buffer_size;
    (void)gPixels_copy;
    (void)gPalette_copy;
    (void)pause_semaphore;

    original_ReceivedGameplay(pContents, pMessage, pReceive_time);
}

static void(*original_SendGameplay)(tPlayer_ID, tNet_gameplay_mess, int, int, int, int, ...) = (void(*)(tPlayer_ID, tNet_gameplay_mess, int, int, int, int, ...))0x00434179;
CARM95_HOOK_FUNCTION(original_SendGameplay, SendGameplay)
void SendGameplay(tPlayer_ID pPlayer, tNet_gameplay_mess pMess, int pParam_1, int pParam_2, int pParam_3, int pParam_4) {
    tNet_message *the_message;
    LOG_TRACE("(%u, %d, %d, %d, %d, %d)", pPlayer, pMess, pParam_1, pParam_2, pParam_3, pParam_4);

    (void)pPlayer;
    (void)pMess;
    (void)pParam_1;
    (void)pParam_2;
    (void)pParam_3;
    (void)pParam_4;
    (void)the_message;

    original_SendGameplay(pPlayer, pMess, pParam_1, pParam_2, pParam_3, pParam_4);
}

static void(*original_SendGameplayToAllPlayers)(tNet_gameplay_mess, int, int, int, int, ...) = (void(*)(tNet_gameplay_mess, int, int, int, int, ...))0x004341db;
CARM95_HOOK_FUNCTION(original_SendGameplayToAllPlayers, SendGameplayToAllPlayers)
void SendGameplayToAllPlayers(tNet_gameplay_mess pMess, int pParam_1, int pParam_2, int pParam_3, int pParam_4) {
    tNet_message *the_message;
    LOG_TRACE("(%d, %d, %d, %d, %d)", pMess, pParam_1, pParam_2, pParam_3, pParam_4);

    (void)pMess;
    (void)pParam_1;
    (void)pParam_2;
    (void)pParam_3;
    (void)pParam_4;
    (void)the_message;

    original_SendGameplayToAllPlayers(pMess, pParam_1, pParam_2, pParam_3, pParam_4);
}

static void(*original_SendGameplayToHost)(tNet_gameplay_mess, int, int, int, int, ...) = (void(*)(tNet_gameplay_mess, int, int, int, int, ...))0x00434239;
CARM95_HOOK_FUNCTION(original_SendGameplayToHost, SendGameplayToHost)
void SendGameplayToHost(tNet_gameplay_mess pMess, int pParam_1, int pParam_2, int pParam_3, int pParam_4) {
    tNet_message *the_message;
    LOG_TRACE("(%d, %d, %d, %d, %d)", pMess, pParam_1, pParam_2, pParam_3, pParam_4);

    (void)pMess;
    (void)pParam_1;
    (void)pParam_2;
    (void)pParam_3;
    (void)pParam_4;
    (void)the_message;

    original_SendGameplayToHost(pMess, pParam_1, pParam_2, pParam_3, pParam_4);
}

static void(*original_InitNetGameplayStuff)() = (void(*)())0x004342a4;
CARM95_HOOK_FUNCTION(original_InitNetGameplayStuff, InitNetGameplayStuff)
void InitNetGameplayStuff() {
    LOG_TRACE("()");


    original_InitNetGameplayStuff();
}

static void(*original_DefaultNetName)() = (void(*)())0x004342cc;
CARM95_HOOK_FUNCTION(original_DefaultNetName, DefaultNetName)
void DefaultNetName() {
    LOG_TRACE("()");


    original_DefaultNetName();
}

static void(*original_NetSendPointCrush)(tCar_spec *, tU16, br_vector3 *, ...) = (void(*)(tCar_spec *, tU16, br_vector3 *, ...))0x004342e6;
CARM95_HOOK_FUNCTION(original_NetSendPointCrush, NetSendPointCrush)
void NetSendPointCrush(tCar_spec *pCar, tU16 pCrush_point_index, br_vector3 *pEnergy_vector) {
    tNet_contents *contents;
    LOG_TRACE("(%p, %u, %p)", pCar, pCrush_point_index, pEnergy_vector);

    (void)pCar;
    (void)pCrush_point_index;
    (void)pEnergy_vector;
    (void)contents;

    original_NetSendPointCrush(pCar, pCrush_point_index, pEnergy_vector);
}

static void(*original_RecievedCrushPoint)(tNet_contents *, ...) = (void(*)(tNet_contents *, ...))0x00434346;
CARM95_HOOK_FUNCTION(original_RecievedCrushPoint, RecievedCrushPoint)
void RecievedCrushPoint(tNet_contents *pContents) {
    tCar_spec *car;
    LOG_TRACE("(%p)", pContents);

    (void)pContents;
    (void)car;

    original_RecievedCrushPoint(pContents);
}

static void(*original_GetReducedMatrix)(tReduced_matrix *, br_matrix34 *, ...) = (void(*)(tReduced_matrix *, br_matrix34 *, ...))0x0043447f;
CARM95_HOOK_FUNCTION(original_GetReducedMatrix, GetReducedMatrix)
void GetReducedMatrix(tReduced_matrix *m1, br_matrix34 *m2) {
    LOG_TRACE("(%p, %p)", m1, m2);

    (void)m1;
    (void)m2;

    original_GetReducedMatrix(m1, m2);
}

static void(*original_GetExpandedMatrix)(br_matrix34 *, tReduced_matrix *, ...) = (void(*)(br_matrix34 *, tReduced_matrix *, ...))0x004344f4;
CARM95_HOOK_FUNCTION(original_GetExpandedMatrix, GetExpandedMatrix)
void GetExpandedMatrix(br_matrix34 *m1, tReduced_matrix *m2) {
    LOG_TRACE("(%p, %p)", m1, m2);

    (void)m1;
    (void)m2;

    original_GetExpandedMatrix(m1, m2);
}

void NetEarnCredits(tNet_game_player_info *pPlayer, tS32 pCredits) {
    LOG_TRACE("(%p, %d)", pPlayer, pCredits);

    (void)pPlayer;
    (void)pCredits;

    NOT_IMPLEMENTED();
}

