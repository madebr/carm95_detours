#include "netgame.h"

#include "harness/trace.h"

#include "carm95_hooks.h"

#include "carm95_webserver.h"

#include <assert.h>
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

function_hook_state_t function_hook_state_SendCarData = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(SendCarData, function_hook_state_SendCarData)
static void(__cdecl*original_SendCarData)(tU32) = (void(__cdecl*)(tU32))0x0042f2d0;
CARM95_HOOK_FUNCTION(original_SendCarData, SendCarData)
void __cdecl SendCarData(tU32 pNext_frame_time) {
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

    if (function_hook_state_SendCarData == HOOK_ENABLED) {
        assert(0 && "SendCarData not implemented.");
        abort();
    } else {
        original_SendCarData(pNext_frame_time);
    }
}

function_hook_state_t function_hook_state_ReceivedRecover = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(ReceivedRecover, function_hook_state_ReceivedRecover)
static void(__cdecl*original_ReceivedRecover)(tNet_contents *) = (void(__cdecl*)(tNet_contents *))0x0042fc35;
CARM95_HOOK_FUNCTION(original_ReceivedRecover, ReceivedRecover)
void __cdecl ReceivedRecover(tNet_contents *pContents) {
    int i;
    LOG_TRACE("(%p)", pContents);

    (void)pContents;
    (void)i;

    if (function_hook_state_ReceivedRecover == HOOK_ENABLED) {
        assert(0 && "ReceivedRecover not implemented.");
        abort();
    } else {
        original_ReceivedRecover(pContents);
    }
}

function_hook_state_t function_hook_state_CopyMechanics = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(CopyMechanics, function_hook_state_CopyMechanics)
static void(__cdecl*original_CopyMechanics)(tCar_spec *, tNet_contents *) = (void(__cdecl*)(tCar_spec *, tNet_contents *))0x0042fcb8;
CARM95_HOOK_FUNCTION(original_CopyMechanics, CopyMechanics)
void __cdecl CopyMechanics(tCar_spec *pCar, tNet_contents *pContents) {
    int j;
    LOG_TRACE("(%p, %p)", pCar, pContents);

    (void)pCar;
    (void)pContents;
    (void)j;

    if (function_hook_state_CopyMechanics == HOOK_ENABLED) {
        assert(0 && "CopyMechanics not implemented.");
        abort();
    } else {
        original_CopyMechanics(pCar, pContents);
    }
}

function_hook_state_t function_hook_state_ReceivedMechanics = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(ReceivedMechanics, function_hook_state_ReceivedMechanics)
static void(__cdecl*original_ReceivedMechanics)(tNet_contents *) = (void(__cdecl*)(tNet_contents *))0x0042fd29;
CARM95_HOOK_FUNCTION(original_ReceivedMechanics, ReceivedMechanics)
void __cdecl ReceivedMechanics(tNet_contents *pContents) {
    int i;
    tCar_spec *car;
    LOG_TRACE("(%p)", pContents);

    (void)pContents;
    (void)i;
    (void)car;

    if (function_hook_state_ReceivedMechanics == HOOK_ENABLED) {
        assert(0 && "ReceivedMechanics not implemented.");
        abort();
    } else {
        original_ReceivedMechanics(pContents);
    }
}

function_hook_state_t function_hook_state_ReceivedCopInfo = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(ReceivedCopInfo, function_hook_state_ReceivedCopInfo)
static void(__cdecl*original_ReceivedCopInfo)(tNet_contents *) = (void(__cdecl*)(tNet_contents *))0x004302c5;
CARM95_HOOK_FUNCTION(original_ReceivedCopInfo, ReceivedCopInfo)
void __cdecl ReceivedCopInfo(tNet_contents *pContents) {
    tCar_spec *c;
    int i;
    LOG_TRACE("(%p)", pContents);

    (void)pContents;
    (void)c;
    (void)i;

    if (function_hook_state_ReceivedCopInfo == HOOK_ENABLED) {
        assert(0 && "ReceivedCopInfo not implemented.");
        abort();
    } else {
        original_ReceivedCopInfo(pContents);
    }
}

function_hook_state_t function_hook_state_SendAllNonCarPositions = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(SendAllNonCarPositions, function_hook_state_SendAllNonCarPositions)
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

    if (function_hook_state_SendAllNonCarPositions == HOOK_ENABLED) {
        assert(0 && "SendAllNonCarPositions not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}

function_hook_state_t function_hook_state_ReceivedNonCarPosition = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(ReceivedNonCarPosition, function_hook_state_ReceivedNonCarPosition)
static void(__cdecl*original_ReceivedNonCarPosition)(tNet_contents *) = (void(__cdecl*)(tNet_contents *))0x00430520;
CARM95_HOOK_FUNCTION(original_ReceivedNonCarPosition, ReceivedNonCarPosition)
void __cdecl ReceivedNonCarPosition(tNet_contents *pContents) {
    br_actor *actor;
    LOG_TRACE("(%p)", pContents);

    (void)pContents;
    (void)actor;

    if (function_hook_state_ReceivedNonCarPosition == HOOK_ENABLED) {
        assert(0 && "ReceivedNonCarPosition not implemented.");
        abort();
    } else {
        original_ReceivedNonCarPosition(pContents);
    }
}

function_hook_state_t function_hook_state_ReceivedNonCar = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(ReceivedNonCar, function_hook_state_ReceivedNonCar)
static void(__cdecl*original_ReceivedNonCar)(tNet_contents *) = (void(__cdecl*)(tNet_contents *))0x0043058d;
CARM95_HOOK_FUNCTION(original_ReceivedNonCar, ReceivedNonCar)
void __cdecl ReceivedNonCar(tNet_contents *pContents) {
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

    if (function_hook_state_ReceivedNonCar == HOOK_ENABLED) {
        assert(0 && "ReceivedNonCar not implemented.");
        abort();
    } else {
        original_ReceivedNonCar(pContents);
    }
}

function_hook_state_t function_hook_state_SignalToStartRace2 = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(SignalToStartRace2, function_hook_state_SignalToStartRace2)
static void(__cdecl*original_SignalToStartRace2)(int) = (void(__cdecl*)(int))0x004308fe;
CARM95_HOOK_FUNCTION(original_SignalToStartRace2, SignalToStartRace2)
void __cdecl SignalToStartRace2(int pIndex) {
    tNet_message *the_message;
    int i;
    int j;
    LOG_TRACE("(%d)", pIndex);

    (void)pIndex;
    (void)the_message;
    (void)i;
    (void)j;

    if (function_hook_state_SignalToStartRace2 == HOOK_ENABLED) {
        assert(0 && "SignalToStartRace2 not implemented.");
        abort();
    } else {
        original_SignalToStartRace2(pIndex);
    }
}

function_hook_state_t function_hook_state_SignalToStartRace = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(SignalToStartRace, function_hook_state_SignalToStartRace)
static void(__cdecl*original_SignalToStartRace)() = (void(__cdecl*)())0x00430bac;
CARM95_HOOK_FUNCTION(original_SignalToStartRace, SignalToStartRace)
void __cdecl SignalToStartRace() {
    LOG_TRACE("()");


    if (function_hook_state_SignalToStartRace == HOOK_ENABLED) {
        assert(0 && "SignalToStartRace not implemented.");
        abort();
    } else {
        original_SignalToStartRace();
    }
}

function_hook_state_t function_hook_state_SetUpNetCarPositions = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(SetUpNetCarPositions, function_hook_state_SetUpNetCarPositions)
static void(__cdecl*original_SetUpNetCarPositions)() = (void(__cdecl*)())0x00430bcd;
CARM95_HOOK_FUNCTION(original_SetUpNetCarPositions, SetUpNetCarPositions)
void __cdecl SetUpNetCarPositions() {
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

    if (function_hook_state_SetUpNetCarPositions == HOOK_ENABLED) {
        assert(0 && "SetUpNetCarPositions not implemented.");
        abort();
    } else {
        original_SetUpNetCarPositions();
    }
}

function_hook_state_t function_hook_state_ReinitialiseCar = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(ReinitialiseCar, function_hook_state_ReinitialiseCar)
static void(__cdecl*original_ReinitialiseCar)(tCar_spec *) = (void(__cdecl*)(tCar_spec *))0x00430f14;
CARM95_HOOK_FUNCTION(original_ReinitialiseCar, ReinitialiseCar)
void __cdecl ReinitialiseCar(tCar_spec *pCar) {
    int i;
    LOG_TRACE("(%p)", pCar);

    (void)pCar;
    (void)i;

    if (function_hook_state_ReinitialiseCar == HOOK_ENABLED) {
        assert(0 && "ReinitialiseCar not implemented.");
        abort();
    } else {
        original_ReinitialiseCar(pCar);
    }
}

function_hook_state_t function_hook_state_RepositionPlayer = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(RepositionPlayer, function_hook_state_RepositionPlayer)
static void(__cdecl*original_RepositionPlayer)(int) = (void(__cdecl*)(int))0x00430f6e;
CARM95_HOOK_FUNCTION(original_RepositionPlayer, RepositionPlayer)
void __cdecl RepositionPlayer(int pIndex) {
    tNet_message *the_message;
    tCar_spec *car;
    LOG_TRACE("(%d)", pIndex);

    (void)pIndex;
    (void)the_message;
    (void)car;

    if (function_hook_state_RepositionPlayer == HOOK_ENABLED) {
        assert(0 && "RepositionPlayer not implemented.");
        abort();
    } else {
        original_RepositionPlayer(pIndex);
    }
}

function_hook_state_t function_hook_state_DisableCar = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(DisableCar, function_hook_state_DisableCar)
static void(__cdecl*original_DisableCar)(tCar_spec *) = (void(__cdecl*)(tCar_spec *))0x00431094;
CARM95_HOOK_FUNCTION(original_DisableCar, DisableCar)
void __cdecl DisableCar(tCar_spec *pCar) {
    LOG_TRACE("(%p)", pCar);

    (void)pCar;

    if (function_hook_state_DisableCar == HOOK_ENABLED) {
        assert(0 && "DisableCar not implemented.");
        abort();
    } else {
        original_DisableCar(pCar);
    }
}

function_hook_state_t function_hook_state_EnableCar = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(EnableCar, function_hook_state_EnableCar)
static void(__cdecl*original_EnableCar)(tCar_spec *) = (void(__cdecl*)(tCar_spec *))0x00431165;
CARM95_HOOK_FUNCTION(original_EnableCar, EnableCar)
void __cdecl EnableCar(tCar_spec *pCar) {
    LOG_TRACE("(%p)", pCar);

    (void)pCar;

    if (function_hook_state_EnableCar == HOOK_ENABLED) {
        assert(0 && "EnableCar not implemented.");
        abort();
    } else {
        original_EnableCar(pCar);
    }
}

function_hook_state_t function_hook_state_DoNetworkHeadups = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(DoNetworkHeadups, function_hook_state_DoNetworkHeadups)
static void(__cdecl*original_DoNetworkHeadups)(int) = (void(__cdecl*)(int))0x00431236;
CARM95_HOOK_FUNCTION(original_DoNetworkHeadups, DoNetworkHeadups)
void __cdecl DoNetworkHeadups(int pCredits) {
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

    if (function_hook_state_DoNetworkHeadups == HOOK_ENABLED) {
        assert(0 && "DoNetworkHeadups not implemented.");
        abort();
    } else {
        original_DoNetworkHeadups(pCredits);
    }
}

function_hook_state_t function_hook_state_SortNetHeadAscending = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(SortNetHeadAscending, function_hook_state_SortNetHeadAscending)
static int(__cdecl*original_SortNetHeadAscending)(void *, void *) = (int(__cdecl*)(void *, void *))0x00431ff8;
CARM95_HOOK_FUNCTION(original_SortNetHeadAscending, SortNetHeadAscending)
int __cdecl SortNetHeadAscending(void *pFirst_one, void *pSecond_one) {
    LOG_TRACE("(%p, %p)", pFirst_one, pSecond_one);

    (void)pFirst_one;
    (void)pSecond_one;

    if (function_hook_state_SortNetHeadAscending == HOOK_ENABLED) {
        assert(0 && "SortNetHeadAscending not implemented.");
        abort();
    } else {
        return original_SortNetHeadAscending(pFirst_one, pSecond_one);
    }
}

function_hook_state_t function_hook_state_SortNetHeadDescending = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(SortNetHeadDescending, function_hook_state_SortNetHeadDescending)
static int(__cdecl*original_SortNetHeadDescending)(void *, void *) = (int(__cdecl*)(void *, void *))0x004320a9;
CARM95_HOOK_FUNCTION(original_SortNetHeadDescending, SortNetHeadDescending)
int __cdecl SortNetHeadDescending(void *pFirst_one, void *pSecond_one) {
    LOG_TRACE("(%p, %p)", pFirst_one, pSecond_one);

    (void)pFirst_one;
    (void)pSecond_one;

    if (function_hook_state_SortNetHeadDescending == HOOK_ENABLED) {
        assert(0 && "SortNetHeadDescending not implemented.");
        abort();
    } else {
        return original_SortNetHeadDescending(pFirst_one, pSecond_one);
    }
}

function_hook_state_t function_hook_state_ClipName = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(ClipName, function_hook_state_ClipName)
static void(__cdecl*original_ClipName)(char *, tDR_font *, int) = (void(__cdecl*)(char *, tDR_font *, int))0x0043215a;
CARM95_HOOK_FUNCTION(original_ClipName, ClipName)
void __cdecl ClipName(char *pName, tDR_font *pFont, int pMax_width) {
    LOG_TRACE("(\"%s\", %p, %d)", pName, pFont, pMax_width);

    (void)pName;
    (void)pFont;
    (void)pMax_width;

    if (function_hook_state_ClipName == HOOK_ENABLED) {
        assert(0 && "ClipName not implemented.");
        abort();
    } else {
        original_ClipName(pName, pFont, pMax_width);
    }
}

function_hook_state_t function_hook_state_DoNetScores2 = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(DoNetScores2, function_hook_state_DoNetScores2)
static void(__cdecl*original_DoNetScores2)(int) = (void(__cdecl*)(int))0x004315c0;
CARM95_HOOK_FUNCTION(original_DoNetScores2, DoNetScores2)
void __cdecl DoNetScores2(int pOnly_sort_scores) {
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

    if (function_hook_state_DoNetScores2 == HOOK_ENABLED) {
        assert(0 && "DoNetScores2 not implemented.");
        abort();
    } else {
        original_DoNetScores2(pOnly_sort_scores);
    }
}

function_hook_state_t function_hook_state_DoNetScores = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(DoNetScores, function_hook_state_DoNetScores)
static void(__cdecl*original_DoNetScores)() = (void(__cdecl*)())0x004321a5;
CARM95_HOOK_FUNCTION(original_DoNetScores, DoNetScores)
void __cdecl DoNetScores() {
    LOG_TRACE("()");


    if (function_hook_state_DoNetScores == HOOK_ENABLED) {
        assert(0 && "DoNetScores not implemented.");
        abort();
    } else {
        original_DoNetScores();
    }
}

function_hook_state_t function_hook_state_InitNetHeadups = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(InitNetHeadups, function_hook_state_InitNetHeadups)
static void(__cdecl*original_InitNetHeadups)() = (void(__cdecl*)())0x004321ba;
CARM95_HOOK_FUNCTION(original_InitNetHeadups, InitNetHeadups)
void __cdecl InitNetHeadups() {
    LOG_TRACE("()");


    if (function_hook_state_InitNetHeadups == HOOK_ENABLED) {
        assert(0 && "InitNetHeadups not implemented.");
        abort();
    } else {
        original_InitNetHeadups();
    }
}

function_hook_state_t function_hook_state_DisposeNetHeadups = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(DisposeNetHeadups, function_hook_state_DisposeNetHeadups)
static void(__cdecl*original_DisposeNetHeadups)() = (void(__cdecl*)())0x0043221f;
CARM95_HOOK_FUNCTION(original_DisposeNetHeadups, DisposeNetHeadups)
void __cdecl DisposeNetHeadups() {
    LOG_TRACE("()");


    if (function_hook_state_DisposeNetHeadups == HOOK_ENABLED) {
        assert(0 && "DisposeNetHeadups not implemented.");
        abort();
    } else {
        original_DisposeNetHeadups();
    }
}

function_hook_state_t function_hook_state_EverybodysLost = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(EverybodysLost, function_hook_state_EverybodysLost)
static void(__cdecl*original_EverybodysLost)() = (void(__cdecl*)())0x00433554;
CARM95_HOOK_FUNCTION(original_EverybodysLost, EverybodysLost)
void __cdecl EverybodysLost() {
    tNet_message *the_message;
    int i;
    LOG_TRACE("()");

    (void)the_message;
    (void)i;

    if (function_hook_state_EverybodysLost == HOOK_ENABLED) {
        assert(0 && "EverybodysLost not implemented.");
        abort();
    } else {
        original_EverybodysLost();
    }
}

function_hook_state_t function_hook_state_DeclareWinner = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(DeclareWinner, function_hook_state_DeclareWinner)
static void(__cdecl*original_DeclareWinner)(int) = (void(__cdecl*)(int))0x0043227c;
CARM95_HOOK_FUNCTION(original_DeclareWinner, DeclareWinner)
void __cdecl DeclareWinner(int pWinner_index) {
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

    if (function_hook_state_DeclareWinner == HOOK_ENABLED) {
        assert(0 && "DeclareWinner not implemented.");
        abort();
    } else {
        original_DeclareWinner(pWinner_index);
    }
}

function_hook_state_t function_hook_state_PlayerIsIt = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(PlayerIsIt, function_hook_state_PlayerIsIt)
static void(__cdecl*original_PlayerIsIt)(tNet_game_player_info *) = (void(__cdecl*)(tNet_game_player_info *))0x004325be;
CARM95_HOOK_FUNCTION(original_PlayerIsIt, PlayerIsIt)
void __cdecl PlayerIsIt(tNet_game_player_info *pPlayer) {
    int i;
    char s[256];
    LOG_TRACE("(%p)", pPlayer);

    (void)pPlayer;
    (void)i;
    (void)s;

    if (function_hook_state_PlayerIsIt == HOOK_ENABLED) {
        assert(0 && "PlayerIsIt not implemented.");
        abort();
    } else {
        original_PlayerIsIt(pPlayer);
    }
}

function_hook_state_t function_hook_state_FarEnoughAway = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(FarEnoughAway, function_hook_state_FarEnoughAway)
static int(__cdecl*original_FarEnoughAway)(tNet_game_player_info *, tNet_game_player_info *) = (int(__cdecl*)(tNet_game_player_info *, tNet_game_player_info *))0x004335cd;
CARM95_HOOK_FUNCTION(original_FarEnoughAway, FarEnoughAway)
int __cdecl FarEnoughAway(tNet_game_player_info *pPlayer_1, tNet_game_player_info *pPlayer_2) {
    br_vector3 difference;
    LOG_TRACE("(%p, %p)", pPlayer_1, pPlayer_2);

    (void)pPlayer_1;
    (void)pPlayer_2;
    (void)difference;

    if (function_hook_state_FarEnoughAway == HOOK_ENABLED) {
        assert(0 && "FarEnoughAway not implemented.");
        abort();
    } else {
        return original_FarEnoughAway(pPlayer_1, pPlayer_2);
    }
}

function_hook_state_t function_hook_state_CarInContactWithItOrFox = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(CarInContactWithItOrFox, function_hook_state_CarInContactWithItOrFox)
static void(__cdecl*original_CarInContactWithItOrFox)(tNet_game_player_info *) = (void(__cdecl*)(tNet_game_player_info *))0x004327a5;
CARM95_HOOK_FUNCTION(original_CarInContactWithItOrFox, CarInContactWithItOrFox)
void __cdecl CarInContactWithItOrFox(tNet_game_player_info *pPlayer) {
    LOG_TRACE("(%p)", pPlayer);

    (void)pPlayer;

    if (function_hook_state_CarInContactWithItOrFox == HOOK_ENABLED) {
        assert(0 && "CarInContactWithItOrFox not implemented.");
        abort();
    } else {
        original_CarInContactWithItOrFox(pPlayer);
    }
}

function_hook_state_t function_hook_state_SelectRandomItOrFox = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(SelectRandomItOrFox, function_hook_state_SelectRandomItOrFox)
static void(__cdecl*original_SelectRandomItOrFox)(int) = (void(__cdecl*)(int))0x00433676;
CARM95_HOOK_FUNCTION(original_SelectRandomItOrFox, SelectRandomItOrFox)
void __cdecl SelectRandomItOrFox(int pNot_this_one) {
    int i;
    int new_choice;
    LOG_TRACE("(%d)", pNot_this_one);

    (void)pNot_this_one;
    (void)i;
    (void)new_choice;

    if (function_hook_state_SelectRandomItOrFox == HOOK_ENABLED) {
        assert(0 && "SelectRandomItOrFox not implemented.");
        abort();
    } else {
        original_SelectRandomItOrFox(pNot_this_one);
    }
}

function_hook_state_t function_hook_state_CalcPlayerScores = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(CalcPlayerScores, function_hook_state_CalcPlayerScores)
static void(__cdecl*original_CalcPlayerScores)() = (void(__cdecl*)())0x00432865;
CARM95_HOOK_FUNCTION(original_CalcPlayerScores, CalcPlayerScores)
void __cdecl CalcPlayerScores() {
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

    if (function_hook_state_CalcPlayerScores == HOOK_ENABLED) {
        assert(0 && "CalcPlayerScores not implemented.");
        abort();
    } else {
        original_CalcPlayerScores();
    }
}

function_hook_state_t function_hook_state_SendPlayerScores = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(SendPlayerScores, function_hook_state_SendPlayerScores)
static void(__cdecl*original_SendPlayerScores)() = (void(__cdecl*)())0x004337a4;
CARM95_HOOK_FUNCTION(original_SendPlayerScores, SendPlayerScores)
void __cdecl SendPlayerScores() {
    tNet_contents *the_contents;
    int i;
    LOG_TRACE("()");

    (void)the_contents;
    (void)i;

    if (function_hook_state_SendPlayerScores == HOOK_ENABLED) {
        assert(0 && "SendPlayerScores not implemented.");
        abort();
    } else {
        original_SendPlayerScores();
    }
}

function_hook_state_t function_hook_state_DoNetGameManagement = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(DoNetGameManagement, function_hook_state_DoNetGameManagement)
static void(__cdecl*original_DoNetGameManagement)() = (void(__cdecl*)())0x00432843;
CARM95_HOOK_FUNCTION(original_DoNetGameManagement, DoNetGameManagement)
void __cdecl DoNetGameManagement() {
    LOG_TRACE("()");


    if (function_hook_state_DoNetGameManagement == HOOK_ENABLED) {
        assert(0 && "DoNetGameManagement not implemented.");
        abort();
    } else {
        original_DoNetGameManagement();
    }
}

function_hook_state_t function_hook_state_InitialisePlayerScore = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(InitialisePlayerScore, function_hook_state_InitialisePlayerScore)
static void(__cdecl*original_InitialisePlayerScore)(tNet_game_player_info *) = (void(__cdecl*)(tNet_game_player_info *))0x0043385c;
CARM95_HOOK_FUNCTION(original_InitialisePlayerScore, InitialisePlayerScore)
void __cdecl InitialisePlayerScore(tNet_game_player_info *pPlayer) {
    LOG_TRACE("(%p)", pPlayer);

    (void)pPlayer;

    if (function_hook_state_InitialisePlayerScore == HOOK_ENABLED) {
        assert(0 && "InitialisePlayerScore not implemented.");
        abort();
    } else {
        original_InitialisePlayerScore(pPlayer);
    }
}

function_hook_state_t function_hook_state_InitPlayers = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(InitPlayers, function_hook_state_InitPlayers)
static void(__cdecl*original_InitPlayers)() = (void(__cdecl*)())0x00433937;
CARM95_HOOK_FUNCTION(original_InitPlayers, InitPlayers)
void __cdecl InitPlayers() {
    int i;
    LOG_TRACE("()");

    (void)i;

    if (function_hook_state_InitPlayers == HOOK_ENABLED) {
        assert(0 && "InitPlayers not implemented.");
        abort();
    } else {
        original_InitPlayers();
    }
}

function_hook_state_t function_hook_state_BuyPSPowerup = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(BuyPSPowerup, function_hook_state_BuyPSPowerup)
static void(__cdecl*original_BuyPSPowerup)(int) = (void(__cdecl*)(int))0x004339be;
CARM95_HOOK_FUNCTION(original_BuyPSPowerup, BuyPSPowerup)
void __cdecl BuyPSPowerup(int pIndex) {
    char s[256];
    char s2[256];
    LOG_TRACE("(%d)", pIndex);

    (void)pIndex;
    (void)s;
    (void)s2;

    if (function_hook_state_BuyPSPowerup == HOOK_ENABLED) {
        assert(0 && "BuyPSPowerup not implemented.");
        abort();
    } else {
        original_BuyPSPowerup(pIndex);
    }
}

function_hook_state_t function_hook_state_BuyArmour = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(BuyArmour, function_hook_state_BuyArmour)
static void(__cdecl*original_BuyArmour)() = (void(__cdecl*)())0x00433b29;
CARM95_HOOK_FUNCTION(original_BuyArmour, BuyArmour)
void __cdecl BuyArmour() {
    LOG_TRACE("()");


    if (function_hook_state_BuyArmour == HOOK_ENABLED) {
        assert(0 && "BuyArmour not implemented.");
        abort();
    } else {
        original_BuyArmour();
    }
}

function_hook_state_t function_hook_state_BuyPower = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(BuyPower, function_hook_state_BuyPower)
static void(__cdecl*original_BuyPower)() = (void(__cdecl*)())0x00433b3e;
CARM95_HOOK_FUNCTION(original_BuyPower, BuyPower)
void __cdecl BuyPower() {
    LOG_TRACE("()");


    if (function_hook_state_BuyPower == HOOK_ENABLED) {
        assert(0 && "BuyPower not implemented.");
        abort();
    } else {
        original_BuyPower();
    }
}

function_hook_state_t function_hook_state_BuyOffense = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(BuyOffense, function_hook_state_BuyOffense)
static void(__cdecl*original_BuyOffense)() = (void(__cdecl*)())0x00433bf9;
CARM95_HOOK_FUNCTION(original_BuyOffense, BuyOffense)
void __cdecl BuyOffense() {
    LOG_TRACE("()");


    if (function_hook_state_BuyOffense == HOOK_ENABLED) {
        assert(0 && "BuyOffense not implemented.");
        abort();
    } else {
        original_BuyOffense();
    }
}

function_hook_state_t function_hook_state_UseGeneralScore = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(UseGeneralScore, function_hook_state_UseGeneralScore)
static void(__cdecl*original_UseGeneralScore)(int) = (void(__cdecl*)(int))0x00433c0e;
CARM95_HOOK_FUNCTION(original_UseGeneralScore, UseGeneralScore)
void __cdecl UseGeneralScore(int pScore) {
    int i;
    LOG_TRACE("(%d)", pScore);

    (void)pScore;
    (void)i;

    if (function_hook_state_UseGeneralScore == HOOK_ENABLED) {
        assert(0 && "UseGeneralScore not implemented.");
        abort();
    } else {
        original_UseGeneralScore(pScore);
    }
}

function_hook_state_t function_hook_state_NetSendEnvironmentChanges = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(NetSendEnvironmentChanges, function_hook_state_NetSendEnvironmentChanges)
static void(__cdecl*original_NetSendEnvironmentChanges)(tNet_game_player_info *) = (void(__cdecl*)(tNet_game_player_info *))0x00433d0c;
CARM95_HOOK_FUNCTION(original_NetSendEnvironmentChanges, NetSendEnvironmentChanges)
void __cdecl NetSendEnvironmentChanges(tNet_game_player_info *pPlayer) {
    LOG_TRACE("(%p)", pPlayer);

    (void)pPlayer;

    if (function_hook_state_NetSendEnvironmentChanges == HOOK_ENABLED) {
        assert(0 && "NetSendEnvironmentChanges not implemented.");
        abort();
    } else {
        original_NetSendEnvironmentChanges(pPlayer);
    }
}

function_hook_state_t function_hook_state_UpdateEnvironments = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(UpdateEnvironments, function_hook_state_UpdateEnvironments)
static void(__cdecl*original_UpdateEnvironments)() = (void(__cdecl*)())0x00433e1b;
CARM95_HOOK_FUNCTION(original_UpdateEnvironments, UpdateEnvironments)
void __cdecl UpdateEnvironments() {
    int i;
    LOG_TRACE("()");

    (void)i;

    if (function_hook_state_UpdateEnvironments == HOOK_ENABLED) {
        assert(0 && "UpdateEnvironments not implemented.");
        abort();
    } else {
        original_UpdateEnvironments();
    }
}

function_hook_state_t function_hook_state_ReceivedGameplay = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(ReceivedGameplay, function_hook_state_ReceivedGameplay)
static void(__cdecl*original_ReceivedGameplay)(tNet_contents *, tNet_message *, tU32) = (void(__cdecl*)(tNet_contents *, tNet_message *, tU32))0x00433eac;
CARM95_HOOK_FUNCTION(original_ReceivedGameplay, ReceivedGameplay)
void __cdecl ReceivedGameplay(tNet_contents *pContents, tNet_message *pMessage, tU32 pReceive_time) {
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

    if (function_hook_state_ReceivedGameplay == HOOK_ENABLED) {
        assert(0 && "ReceivedGameplay not implemented.");
        abort();
    } else {
        original_ReceivedGameplay(pContents, pMessage, pReceive_time);
    }
}

function_hook_state_t function_hook_state_SendGameplay = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(SendGameplay, function_hook_state_SendGameplay)
static void(__cdecl*original_SendGameplay)(tPlayer_ID, tNet_gameplay_mess, int, int, int, int) = (void(__cdecl*)(tPlayer_ID, tNet_gameplay_mess, int, int, int, int))0x00434179;
CARM95_HOOK_FUNCTION(original_SendGameplay, SendGameplay)
void __cdecl SendGameplay(tPlayer_ID pPlayer, tNet_gameplay_mess pMess, int pParam_1, int pParam_2, int pParam_3, int pParam_4) {
    tNet_message *the_message;
    LOG_TRACE("(%u, %d, %d, %d, %d, %d)", pPlayer, pMess, pParam_1, pParam_2, pParam_3, pParam_4);

    (void)pPlayer;
    (void)pMess;
    (void)pParam_1;
    (void)pParam_2;
    (void)pParam_3;
    (void)pParam_4;
    (void)the_message;

    if (function_hook_state_SendGameplay == HOOK_ENABLED) {
        assert(0 && "SendGameplay not implemented.");
        abort();
    } else {
        original_SendGameplay(pPlayer, pMess, pParam_1, pParam_2, pParam_3, pParam_4);
    }
}

function_hook_state_t function_hook_state_SendGameplayToAllPlayers = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(SendGameplayToAllPlayers, function_hook_state_SendGameplayToAllPlayers)
static void(__cdecl*original_SendGameplayToAllPlayers)(tNet_gameplay_mess, int, int, int, int) = (void(__cdecl*)(tNet_gameplay_mess, int, int, int, int))0x004341db;
CARM95_HOOK_FUNCTION(original_SendGameplayToAllPlayers, SendGameplayToAllPlayers)
void __cdecl SendGameplayToAllPlayers(tNet_gameplay_mess pMess, int pParam_1, int pParam_2, int pParam_3, int pParam_4) {
    tNet_message *the_message;
    LOG_TRACE("(%d, %d, %d, %d, %d)", pMess, pParam_1, pParam_2, pParam_3, pParam_4);

    (void)pMess;
    (void)pParam_1;
    (void)pParam_2;
    (void)pParam_3;
    (void)pParam_4;
    (void)the_message;

    if (function_hook_state_SendGameplayToAllPlayers == HOOK_ENABLED) {
        assert(0 && "SendGameplayToAllPlayers not implemented.");
        abort();
    } else {
        original_SendGameplayToAllPlayers(pMess, pParam_1, pParam_2, pParam_3, pParam_4);
    }
}

function_hook_state_t function_hook_state_SendGameplayToHost = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(SendGameplayToHost, function_hook_state_SendGameplayToHost)
static void(__cdecl*original_SendGameplayToHost)(tNet_gameplay_mess, int, int, int, int) = (void(__cdecl*)(tNet_gameplay_mess, int, int, int, int))0x00434239;
CARM95_HOOK_FUNCTION(original_SendGameplayToHost, SendGameplayToHost)
void __cdecl SendGameplayToHost(tNet_gameplay_mess pMess, int pParam_1, int pParam_2, int pParam_3, int pParam_4) {
    tNet_message *the_message;
    LOG_TRACE("(%d, %d, %d, %d, %d)", pMess, pParam_1, pParam_2, pParam_3, pParam_4);

    (void)pMess;
    (void)pParam_1;
    (void)pParam_2;
    (void)pParam_3;
    (void)pParam_4;
    (void)the_message;

    if (function_hook_state_SendGameplayToHost == HOOK_ENABLED) {
        assert(0 && "SendGameplayToHost not implemented.");
        abort();
    } else {
        original_SendGameplayToHost(pMess, pParam_1, pParam_2, pParam_3, pParam_4);
    }
}

function_hook_state_t function_hook_state_InitNetGameplayStuff = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(InitNetGameplayStuff, function_hook_state_InitNetGameplayStuff)
static void(__cdecl*original_InitNetGameplayStuff)() = (void(__cdecl*)())0x004342a4;
CARM95_HOOK_FUNCTION(original_InitNetGameplayStuff, InitNetGameplayStuff)
void __cdecl InitNetGameplayStuff() {
    LOG_TRACE("()");


    if (function_hook_state_InitNetGameplayStuff == HOOK_ENABLED) {
        assert(0 && "InitNetGameplayStuff not implemented.");
        abort();
    } else {
        original_InitNetGameplayStuff();
    }
}

function_hook_state_t function_hook_state_DefaultNetName = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(DefaultNetName, function_hook_state_DefaultNetName)
static void(__cdecl*original_DefaultNetName)() = (void(__cdecl*)())0x004342cc;
CARM95_HOOK_FUNCTION(original_DefaultNetName, DefaultNetName)
void __cdecl DefaultNetName() {
    LOG_TRACE("()");


    if (function_hook_state_DefaultNetName == HOOK_ENABLED) {
        assert(0 && "DefaultNetName not implemented.");
        abort();
    } else {
        original_DefaultNetName();
    }
}

function_hook_state_t function_hook_state_NetSendPointCrush = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(NetSendPointCrush, function_hook_state_NetSendPointCrush)
static void(__cdecl*original_NetSendPointCrush)(tCar_spec *, tU16, br_vector3 *) = (void(__cdecl*)(tCar_spec *, tU16, br_vector3 *))0x004342e6;
CARM95_HOOK_FUNCTION(original_NetSendPointCrush, NetSendPointCrush)
void __cdecl NetSendPointCrush(tCar_spec *pCar, tU16 pCrush_point_index, br_vector3 *pEnergy_vector) {
    tNet_contents *contents;
    LOG_TRACE("(%p, %u, %p)", pCar, pCrush_point_index, pEnergy_vector);

    (void)pCar;
    (void)pCrush_point_index;
    (void)pEnergy_vector;
    (void)contents;

    if (function_hook_state_NetSendPointCrush == HOOK_ENABLED) {
        assert(0 && "NetSendPointCrush not implemented.");
        abort();
    } else {
        original_NetSendPointCrush(pCar, pCrush_point_index, pEnergy_vector);
    }
}

function_hook_state_t function_hook_state_RecievedCrushPoint = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(RecievedCrushPoint, function_hook_state_RecievedCrushPoint)
static void(__cdecl*original_RecievedCrushPoint)(tNet_contents *) = (void(__cdecl*)(tNet_contents *))0x00434346;
CARM95_HOOK_FUNCTION(original_RecievedCrushPoint, RecievedCrushPoint)
void __cdecl RecievedCrushPoint(tNet_contents *pContents) {
    tCar_spec *car;
    LOG_TRACE("(%p)", pContents);

    (void)pContents;
    (void)car;

    if (function_hook_state_RecievedCrushPoint == HOOK_ENABLED) {
        assert(0 && "RecievedCrushPoint not implemented.");
        abort();
    } else {
        original_RecievedCrushPoint(pContents);
    }
}

function_hook_state_t function_hook_state_GetReducedMatrix = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(GetReducedMatrix, function_hook_state_GetReducedMatrix)
static void(__cdecl*original_GetReducedMatrix)(tReduced_matrix *, br_matrix34 *) = (void(__cdecl*)(tReduced_matrix *, br_matrix34 *))0x0043447f;
CARM95_HOOK_FUNCTION(original_GetReducedMatrix, GetReducedMatrix)
void __cdecl GetReducedMatrix(tReduced_matrix *m1, br_matrix34 *m2) {
    LOG_TRACE("(%p, %p)", m1, m2);

    (void)m1;
    (void)m2;

    if (function_hook_state_GetReducedMatrix == HOOK_ENABLED) {
        assert(0 && "GetReducedMatrix not implemented.");
        abort();
    } else {
        original_GetReducedMatrix(m1, m2);
    }
}

function_hook_state_t function_hook_state_GetExpandedMatrix = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(GetExpandedMatrix, function_hook_state_GetExpandedMatrix)
static void(__cdecl*original_GetExpandedMatrix)(br_matrix34 *, tReduced_matrix *) = (void(__cdecl*)(br_matrix34 *, tReduced_matrix *))0x004344f4;
CARM95_HOOK_FUNCTION(original_GetExpandedMatrix, GetExpandedMatrix)
void __cdecl GetExpandedMatrix(br_matrix34 *m1, tReduced_matrix *m2) {
    LOG_TRACE("(%p, %p)", m1, m2);

    (void)m1;
    (void)m2;

    if (function_hook_state_GetExpandedMatrix == HOOK_ENABLED) {
        assert(0 && "GetExpandedMatrix not implemented.");
        abort();
    } else {
        original_GetExpandedMatrix(m1, m2);
    }
}

function_hook_state_t function_hook_state_NetEarnCredits = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(NetEarnCredits, function_hook_state_NetEarnCredits)
static void(__cdecl*original_NetEarnCredits)(tNet_game_player_info *, tS32) = (void(__cdecl*)(tNet_game_player_info *, tS32))0x004345c7;
CARM95_HOOK_FUNCTION(original_NetEarnCredits, NetEarnCredits)
void __cdecl NetEarnCredits(tNet_game_player_info *pPlayer, tS32 pCredits) {
    LOG_TRACE("(%p, %d)", pPlayer, pCredits);

    (void)pPlayer;
    (void)pCredits;

    if (function_hook_state_NetEarnCredits == HOOK_ENABLED) {
        assert(0 && "NetEarnCredits not implemented.");
        abort();
    } else {
        original_NetEarnCredits(pPlayer, pCredits);
    }
}

