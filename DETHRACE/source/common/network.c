#include "network.h"

#include "harness/trace.h"

#include "carm95_hooks.h"

#include "carm95_webserver.h"

#include <assert.h>
#if 0
tU32 * hookvar_gMess_max_flags ;
#endif
#if 0
tU32 * hookvar_gMess_mid_flags ;
#endif
#if 0
tU32 * hookvar_gMess_min_flags ;
#endif
tU32 * hookvar_gGuarantee_number  = (void*)0x0050d224;
int * hookvar_gNet_service_disable  = (void*)0x0050d228;
int * hookvar_gIn_net_service  = (void*)0x0050d22c;
int * hookvar_gPlayer_list_batch_number  = (void*)0x0050d230;
int * hookvar_gOnly_receive_guarantee_replies  = (void*)0x0050d234;
void ** hookvar_gMessage_to_free  = (void*)0x0050d238;
tNet_message ** hookvar_gBroadcast_stack  = (void*)0x0050d23c;
tNet_message ** hookvar_gTo_host_stack  = (void*)0x0050d240;
tU32 * hookvar_gLast_flush_message  = (void*)0x0050d244;
int(* hookvar_gRace_only_flags )[33] = (void*)0x0050d248;
int * hookvar_gJoin_list_mode  = (void*)0x0050d2cc;
tNet_game_player_info(* hookvar_gNew_net_players )[6] = (void*)0x00535dd0;
tGuaranteed_message(* hookvar_gGuarantee_list )[150] = (void*)0x00534c90;
tMid_message ** hookvar_gMid_messages  = (void*)0x00534c70;
tU32 * hookvar_gLast_player_list_received  = (void*)0x00534c84;
tMin_message ** hookvar_gMin_messages  = (void*)0x00534c7c;
void(*** hookvar_gAdd_proc )(tNet_game_details *) = (void*)0x00535dc0;
int * hookvar_gReceiving_batch_number  = (void*)0x00534c64;
int * hookvar_gReceiving_new_players  = (void*)0x00536250;
tMax_message ** hookvar_gMax_messages  = (void*)0x00534c80;
int * hookvar_gNext_guarantee  = (void*)0x00534c58;
tU32 * hookvar_gAsk_time  = (void*)0x0050f1ac;
int * hookvar_gNet_initialised  = (void*)0x00534c6c;
int * hookvar_gDont_allow_joiners  = (void*)0x00534c60;
tNet_game_details ** hookvar_gCurrent_join_poll_game  = (void*)0x00536254;
int * hookvar_gMessage_header_size  = (void*)0x00534c8c;
int * hookvar_gJoin_poll_index  = (void*)0x00534c5c;
int * hookvar_gJoin_request_denied  = (void*)0x00535dc8;
int * hookvar_gHost_died  = (void*)0x00534c68;
#if 0
int * hookvar_gCar_was_taken ;
#endif
int * hookvar_gBastard_has_answered  = (void*)0x00534c78;
#if 0
int * hookvar_gTime_for_next_one ;
#endif
int * hookvar_gReceived_game_scores  = (void*)0x005514d4;

function_hook_state_t function_hook_state_NetInitialise = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(NetInitialise, function_hook_state_NetInitialise)
static int(__cdecl*original_NetInitialise)() = (int(__cdecl*)())0x004463c0;
CARM95_HOOK_FUNCTION(original_NetInitialise, NetInitialise)
int __cdecl NetInitialise() {
    int i;
    LOG_TRACE("()");

    (void)i;

    if (function_hook_state_NetInitialise == HOOK_ENABLED) {
        assert(0 && "NetInitialise not implemented.");
        abort();
    } else {
        return original_NetInitialise();
    }
}

function_hook_state_t function_hook_state_NetShutdown = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(NetShutdown, function_hook_state_NetShutdown)
static int(__cdecl*original_NetShutdown)() = (int(__cdecl*)())0x0044657f;
CARM95_HOOK_FUNCTION(original_NetShutdown, NetShutdown)
int __cdecl NetShutdown() {
    int err;
    int i;
    LOG_TRACE("()");

    (void)err;
    (void)i;

    if (function_hook_state_NetShutdown == HOOK_ENABLED) {
        assert(0 && "NetShutdown not implemented.");
        abort();
    } else {
        return original_NetShutdown();
    }
}

function_hook_state_t function_hook_state_ShutdownNetIfRequired = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(ShutdownNetIfRequired, function_hook_state_ShutdownNetIfRequired)
static void(__cdecl*original_ShutdownNetIfRequired)() = (void(__cdecl*)())0x004465d1;
CARM95_HOOK_FUNCTION(original_ShutdownNetIfRequired, ShutdownNetIfRequired)
void __cdecl ShutdownNetIfRequired() {
    LOG_TRACE("()");


    if (function_hook_state_ShutdownNetIfRequired == HOOK_ENABLED) {
        assert(0 && "ShutdownNetIfRequired not implemented.");
        abort();
    } else {
        original_ShutdownNetIfRequired();
    }
}

function_hook_state_t function_hook_state_DisableNetService = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(DisableNetService, function_hook_state_DisableNetService)
static void(__cdecl*original_DisableNetService)() = (void(__cdecl*)())0x004465f8;
CARM95_HOOK_FUNCTION(original_DisableNetService, DisableNetService)
void __cdecl DisableNetService() {
    LOG_TRACE("()");


    if (function_hook_state_DisableNetService == HOOK_ENABLED) {
        assert(0 && "DisableNetService not implemented.");
        abort();
    } else {
        original_DisableNetService();
    }
}

function_hook_state_t function_hook_state_ReenableNetService = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(ReenableNetService, function_hook_state_ReenableNetService)
static void(__cdecl*original_ReenableNetService)() = (void(__cdecl*)())0x0044660d;
CARM95_HOOK_FUNCTION(original_ReenableNetService, ReenableNetService)
void __cdecl ReenableNetService() {
    LOG_TRACE("()");


    if (function_hook_state_ReenableNetService == HOOK_ENABLED) {
        assert(0 && "ReenableNetService not implemented.");
        abort();
    } else {
        original_ReenableNetService();
    }
}

function_hook_state_t function_hook_state_PermitNetServiceReentrancy = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(PermitNetServiceReentrancy, function_hook_state_PermitNetServiceReentrancy)
static int(__cdecl*original_PermitNetServiceReentrancy)() = (int(__cdecl*)())0x00446622;
CARM95_HOOK_FUNCTION(original_PermitNetServiceReentrancy, PermitNetServiceReentrancy)
int __cdecl PermitNetServiceReentrancy() {
    LOG_TRACE("()");


    if (function_hook_state_PermitNetServiceReentrancy == HOOK_ENABLED) {
        assert(0 && "PermitNetServiceReentrancy not implemented.");
        abort();
    } else {
        return original_PermitNetServiceReentrancy();
    }
}

function_hook_state_t function_hook_state_HaltNetServiceReentrancy = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(HaltNetServiceReentrancy, function_hook_state_HaltNetServiceReentrancy)
static void(__cdecl*original_HaltNetServiceReentrancy)() = (void(__cdecl*)())0x0044665a;
CARM95_HOOK_FUNCTION(original_HaltNetServiceReentrancy, HaltNetServiceReentrancy)
void __cdecl HaltNetServiceReentrancy() {
    LOG_TRACE("()");


    if (function_hook_state_HaltNetServiceReentrancy == HOOK_ENABLED) {
        assert(0 && "HaltNetServiceReentrancy not implemented.");
        abort();
    } else {
        original_HaltNetServiceReentrancy();
    }
}

function_hook_state_t function_hook_state_NetSendHeadupToAllPlayers = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(NetSendHeadupToAllPlayers, function_hook_state_NetSendHeadupToAllPlayers)
static void(__cdecl*original_NetSendHeadupToAllPlayers)(char *) = (void(__cdecl*)(char *))0x0044666f;
CARM95_HOOK_FUNCTION(original_NetSendHeadupToAllPlayers, NetSendHeadupToAllPlayers)
void __cdecl NetSendHeadupToAllPlayers(char *pMessage) {
    tNet_contents *the_contents;
    LOG_TRACE("(\"%s\")", pMessage);

    (void)pMessage;
    (void)the_contents;

    if (function_hook_state_NetSendHeadupToAllPlayers == HOOK_ENABLED) {
        assert(0 && "NetSendHeadupToAllPlayers not implemented.");
        abort();
    } else {
        original_NetSendHeadupToAllPlayers(pMessage);
    }
}

function_hook_state_t function_hook_state_NetSendHeadupToEverybody = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(NetSendHeadupToEverybody, function_hook_state_NetSendHeadupToEverybody)
static void(__cdecl*original_NetSendHeadupToEverybody)(char *) = (void(__cdecl*)(char *))0x004466c1;
CARM95_HOOK_FUNCTION(original_NetSendHeadupToEverybody, NetSendHeadupToEverybody)
void __cdecl NetSendHeadupToEverybody(char *pMessage) {
    tNet_contents *the_contents;
    LOG_TRACE("(\"%s\")", pMessage);

    (void)pMessage;
    (void)the_contents;

    if (function_hook_state_NetSendHeadupToEverybody == HOOK_ENABLED) {
        assert(0 && "NetSendHeadupToEverybody not implemented.");
        abort();
    } else {
        original_NetSendHeadupToEverybody(pMessage);
    }
}

function_hook_state_t function_hook_state_NetSendHeadupToPlayer = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(NetSendHeadupToPlayer, function_hook_state_NetSendHeadupToPlayer)
static void(__cdecl*original_NetSendHeadupToPlayer)(char *, tPlayer_ID) = (void(__cdecl*)(char *, tPlayer_ID))0x00446737;
CARM95_HOOK_FUNCTION(original_NetSendHeadupToPlayer, NetSendHeadupToPlayer)
void __cdecl NetSendHeadupToPlayer(char *pMessage, tPlayer_ID pPlayer) {
    tNet_message *message;
    LOG_TRACE("(\"%s\", %u)", pMessage, pPlayer);

    (void)pMessage;
    (void)pPlayer;
    (void)message;

    if (function_hook_state_NetSendHeadupToPlayer == HOOK_ENABLED) {
        assert(0 && "NetSendHeadupToPlayer not implemented.");
        abort();
    } else {
        original_NetSendHeadupToPlayer(pMessage, pPlayer);
    }
}

function_hook_state_t function_hook_state_InitialisePlayerStati = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(InitialisePlayerStati, function_hook_state_InitialisePlayerStati)
static void(__cdecl*original_InitialisePlayerStati)() = (void(__cdecl*)())0x0044754e;
CARM95_HOOK_FUNCTION(original_InitialisePlayerStati, InitialisePlayerStati)
void __cdecl InitialisePlayerStati() {
    int i;
    LOG_TRACE("()");

    (void)i;

    if (function_hook_state_InitialisePlayerStati == HOOK_ENABLED) {
        assert(0 && "InitialisePlayerStati not implemented.");
        abort();
    } else {
        original_InitialisePlayerStati();
    }
}

function_hook_state_t function_hook_state_LeaveTempGame = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(LeaveTempGame, function_hook_state_LeaveTempGame)
static void(__cdecl*original_LeaveTempGame)() = (void(__cdecl*)())0x00446847;
CARM95_HOOK_FUNCTION(original_LeaveTempGame, LeaveTempGame)
void __cdecl LeaveTempGame() {
    LOG_TRACE("()");


    if (function_hook_state_LeaveTempGame == HOOK_ENABLED) {
        assert(0 && "LeaveTempGame not implemented.");
        abort();
    } else {
        original_LeaveTempGame();
    }
}

function_hook_state_t function_hook_state_DisposeCurrentJoinPollGame = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(DisposeCurrentJoinPollGame, function_hook_state_DisposeCurrentJoinPollGame)
static void(__cdecl*original_DisposeCurrentJoinPollGame)() = (void(__cdecl*)())0x00446881;
CARM95_HOOK_FUNCTION(original_DisposeCurrentJoinPollGame, DisposeCurrentJoinPollGame)
void __cdecl DisposeCurrentJoinPollGame() {
    LOG_TRACE("()");


    if (function_hook_state_DisposeCurrentJoinPollGame == HOOK_ENABLED) {
        assert(0 && "DisposeCurrentJoinPollGame not implemented.");
        abort();
    } else {
        original_DisposeCurrentJoinPollGame();
    }
}

function_hook_state_t function_hook_state_DoNextJoinPoll = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(DoNextJoinPoll, function_hook_state_DoNextJoinPoll)
static void(__cdecl*original_DoNextJoinPoll)() = (void(__cdecl*)())0x0044a179;
CARM95_HOOK_FUNCTION(original_DoNextJoinPoll, DoNextJoinPoll)
void __cdecl DoNextJoinPoll() {
    tNet_message *the_message;
    LOG_TRACE("()");

    (void)the_message;

    if (function_hook_state_DoNextJoinPoll == HOOK_ENABLED) {
        assert(0 && "DoNextJoinPoll not implemented.");
        abort();
    } else {
        original_DoNextJoinPoll();
    }
}

function_hook_state_t function_hook_state_NetStartProducingJoinList = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(NetStartProducingJoinList, function_hook_state_NetStartProducingJoinList)
static void(__cdecl*original_NetStartProducingJoinList)(void(**)(tNet_game_details *)) = (void(__cdecl*)(void(**)(tNet_game_details *)))0x004467d9;
CARM95_HOOK_FUNCTION(original_NetStartProducingJoinList, NetStartProducingJoinList)
void __cdecl NetStartProducingJoinList(void(**pAdd_proc)(tNet_game_details *)) {
    LOG_TRACE("(%p)", pAdd_proc);

    (void)pAdd_proc;

    if (function_hook_state_NetStartProducingJoinList == HOOK_ENABLED) {
        assert(0 && "NetStartProducingJoinList not implemented.");
        abort();
    } else {
        original_NetStartProducingJoinList(pAdd_proc);
    }
}

function_hook_state_t function_hook_state_NetEndJoinList = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(NetEndJoinList, function_hook_state_NetEndJoinList)
static void(__cdecl*original_NetEndJoinList)() = (void(__cdecl*)())0x00446823;
CARM95_HOOK_FUNCTION(original_NetEndJoinList, NetEndJoinList)
void __cdecl NetEndJoinList() {
    LOG_TRACE("()");


    if (function_hook_state_NetEndJoinList == HOOK_ENABLED) {
        assert(0 && "NetEndJoinList not implemented.");
        abort();
    } else {
        original_NetEndJoinList();
    }
}

function_hook_state_t function_hook_state_NetDisposePIDGameInfo = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(NetDisposePIDGameInfo, function_hook_state_NetDisposePIDGameInfo)
static void(__cdecl*original_NetDisposePIDGameInfo)(tNet_game_details *) = (void(__cdecl*)(tNet_game_details *))0x004468b1;
CARM95_HOOK_FUNCTION(original_NetDisposePIDGameInfo, NetDisposePIDGameInfo)
void __cdecl NetDisposePIDGameInfo(tNet_game_details *pDetails) {
    LOG_TRACE("(%p)", pDetails);

    (void)pDetails;

    if (function_hook_state_NetDisposePIDGameInfo == HOOK_ENABLED) {
        assert(0 && "NetDisposePIDGameInfo not implemented.");
        abort();
    } else {
        original_NetDisposePIDGameInfo(pDetails);
    }
}

function_hook_state_t function_hook_state_NetDisposeGameDetails = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(NetDisposeGameDetails, function_hook_state_NetDisposeGameDetails)
static void(__cdecl*original_NetDisposeGameDetails)(tNet_game_details *) = (void(__cdecl*)(tNet_game_details *))0x004468d2;
CARM95_HOOK_FUNCTION(original_NetDisposeGameDetails, NetDisposeGameDetails)
void __cdecl NetDisposeGameDetails(tNet_game_details *pDetails) {
    LOG_TRACE("(%p)", pDetails);

    (void)pDetails;

    if (function_hook_state_NetDisposeGameDetails == HOOK_ENABLED) {
        assert(0 && "NetDisposeGameDetails not implemented.");
        abort();
    } else {
        original_NetDisposeGameDetails(pDetails);
    }
}

function_hook_state_t function_hook_state_NetAllocatePIDGameDetails = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(NetAllocatePIDGameDetails, function_hook_state_NetAllocatePIDGameDetails)
static tNet_game_details *(__cdecl*original_NetAllocatePIDGameDetails)() = (tNet_game_details *(__cdecl*)())0x0044759d;
CARM95_HOOK_FUNCTION(original_NetAllocatePIDGameDetails, NetAllocatePIDGameDetails)
tNet_game_details* __cdecl NetAllocatePIDGameDetails() {
    tNet_game_details *game;
    LOG_TRACE("()");

    (void)game;

    if (function_hook_state_NetAllocatePIDGameDetails == HOOK_ENABLED) {
        assert(0 && "NetAllocatePIDGameDetails not implemented.");
        abort();
    } else {
        return original_NetAllocatePIDGameDetails();
    }
}

function_hook_state_t function_hook_state_NetLeaveGameLowLevel = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(NetLeaveGameLowLevel, function_hook_state_NetLeaveGameLowLevel)
static void(__cdecl*original_NetLeaveGameLowLevel)(tNet_game_details *) = (void(__cdecl*)(tNet_game_details *))0x004468f3;
CARM95_HOOK_FUNCTION(original_NetLeaveGameLowLevel, NetLeaveGameLowLevel)
void __cdecl NetLeaveGameLowLevel(tNet_game_details *pDetails) {
    LOG_TRACE("(%p)", pDetails);

    (void)pDetails;

    if (function_hook_state_NetLeaveGameLowLevel == HOOK_ENABLED) {
        assert(0 && "NetLeaveGameLowLevel not implemented.");
        abort();
    } else {
        original_NetLeaveGameLowLevel(pDetails);
    }
}

function_hook_state_t function_hook_state_NetLeaveGame = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(NetLeaveGame, function_hook_state_NetLeaveGame)
static void(__cdecl*original_NetLeaveGame)(tNet_game_details *) = (void(__cdecl*)(tNet_game_details *))0x0044692a;
CARM95_HOOK_FUNCTION(original_NetLeaveGame, NetLeaveGame)
void __cdecl NetLeaveGame(tNet_game_details *pNet_game) {
    tNet_message *the_message;
    char s[256];
    char *s2;
    int i;
    int must_revert_reentrancy;
    LOG_TRACE("(%p)", pNet_game);

    (void)pNet_game;
    (void)the_message;
    (void)s;
    (void)s2;
    (void)i;
    (void)must_revert_reentrancy;

    if (function_hook_state_NetLeaveGame == HOOK_ENABLED) {
        assert(0 && "NetLeaveGame not implemented.");
        abort();
    } else {
        original_NetLeaveGame(pNet_game);
    }
}

function_hook_state_t function_hook_state_NetSetPlayerSystemInfo = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(NetSetPlayerSystemInfo, function_hook_state_NetSetPlayerSystemInfo)
static void(__cdecl*original_NetSetPlayerSystemInfo)(tNet_game_player_info *, void *) = (void(__cdecl*)(tNet_game_player_info *, void *))0x00446b3b;
CARM95_HOOK_FUNCTION(original_NetSetPlayerSystemInfo, NetSetPlayerSystemInfo)
void __cdecl NetSetPlayerSystemInfo(tNet_game_player_info *pPlayer, void *pSender_address) {
    LOG_TRACE("(%p, %p)", pPlayer, pSender_address);

    (void)pPlayer;
    (void)pSender_address;

    if (function_hook_state_NetSetPlayerSystemInfo == HOOK_ENABLED) {
        assert(0 && "NetSetPlayerSystemInfo not implemented.");
        abort();
    } else {
        original_NetSetPlayerSystemInfo(pPlayer, pSender_address);
    }
}

function_hook_state_t function_hook_state_NetDisposePlayer = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(NetDisposePlayer, function_hook_state_NetDisposePlayer)
static void(__cdecl*original_NetDisposePlayer)(tNet_game_player_info *) = (void(__cdecl*)(tNet_game_player_info *))0x00446b56;
CARM95_HOOK_FUNCTION(original_NetDisposePlayer, NetDisposePlayer)
void __cdecl NetDisposePlayer(tNet_game_player_info *pPlayer) {
    LOG_TRACE("(%p)", pPlayer);

    (void)pPlayer;

    if (function_hook_state_NetDisposePlayer == HOOK_ENABLED) {
        assert(0 && "NetDisposePlayer not implemented.");
        abort();
    } else {
        original_NetDisposePlayer(pPlayer);
    }
}

function_hook_state_t function_hook_state_FillInThisPlayer = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(FillInThisPlayer, function_hook_state_FillInThisPlayer)
static void(__cdecl*original_FillInThisPlayer)(tNet_game_details *, tNet_game_player_info *, int, int) = (void(__cdecl*)(tNet_game_details *, tNet_game_player_info *, int, int))0x004475c5;
CARM95_HOOK_FUNCTION(original_FillInThisPlayer, FillInThisPlayer)
void __cdecl FillInThisPlayer(tNet_game_details *pGame, tNet_game_player_info *pPlayer, int pCar_index, int pHost) {
    LOG_TRACE("(%p, %p, %d, %d)", pGame, pPlayer, pCar_index, pHost);

    (void)pGame;
    (void)pPlayer;
    (void)pCar_index;
    (void)pHost;

    if (function_hook_state_FillInThisPlayer == HOOK_ENABLED) {
        assert(0 && "FillInThisPlayer not implemented.");
        abort();
    } else {
        original_FillInThisPlayer(pGame, pPlayer, pCar_index, pHost);
    }
}

function_hook_state_t function_hook_state_LoadCarN = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(LoadCarN, function_hook_state_LoadCarN)
static void(__cdecl*original_LoadCarN)(int, tNet_game_player_info *) = (void(__cdecl*)(int, tNet_game_player_info *))0x0044725a;
CARM95_HOOK_FUNCTION(original_LoadCarN, LoadCarN)
void __cdecl LoadCarN(int pIndex, tNet_game_player_info *pPlayer) {
    int switched_res;
    LOG_TRACE("(%d, %p)", pIndex, pPlayer);

    (void)pIndex;
    (void)pPlayer;
    (void)switched_res;

    if (function_hook_state_LoadCarN == HOOK_ENABLED) {
        assert(0 && "LoadCarN not implemented.");
        abort();
    } else {
        original_LoadCarN(pIndex, pPlayer);
    }
}

function_hook_state_t function_hook_state_DisposeCarN = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(DisposeCarN, function_hook_state_DisposeCarN)
static void(__cdecl*original_DisposeCarN)(int) = (void(__cdecl*)(int))0x00446b6d;
CARM95_HOOK_FUNCTION(original_DisposeCarN, DisposeCarN)
void __cdecl DisposeCarN(int pIndex) {
    int i;
    int j;
    LOG_TRACE("(%d)", pIndex);

    (void)pIndex;
    (void)i;
    (void)j;

    if (function_hook_state_DisposeCarN == HOOK_ENABLED) {
        assert(0 && "DisposeCarN not implemented.");
        abort();
    } else {
        original_DisposeCarN(pIndex);
    }
}

function_hook_state_t function_hook_state_PlayerHasLeft = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(PlayerHasLeft, function_hook_state_PlayerHasLeft)
static void(__cdecl*original_PlayerHasLeft)(int) = (void(__cdecl*)(int))0x0044731b;
CARM95_HOOK_FUNCTION(original_PlayerHasLeft, PlayerHasLeft)
void __cdecl PlayerHasLeft(int pIndex) {
    LOG_TRACE("(%d)", pIndex);

    (void)pIndex;

    if (function_hook_state_PlayerHasLeft == HOOK_ENABLED) {
        assert(0 && "PlayerHasLeft not implemented.");
        abort();
    } else {
        original_PlayerHasLeft(pIndex);
    }
}

function_hook_state_t function_hook_state_NetPlayersChanged = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(NetPlayersChanged, function_hook_state_NetPlayersChanged)
static void(__cdecl*original_NetPlayersChanged)(int, tNet_game_player_info *) = (void(__cdecl*)(int, tNet_game_player_info *))0x00446ca1;
CARM95_HOOK_FUNCTION(original_NetPlayersChanged, NetPlayersChanged)
void __cdecl NetPlayersChanged(int pNew_count, tNet_game_player_info *pNew_players) {
    int i;
    int j;
    int k;
    int switched_res;
    int new_player;
    int player_still_there;
    tPlayer_ID old_fox_it;
    LOG_TRACE("(%d, %p)", pNew_count, pNew_players);

    (void)pNew_count;
    (void)pNew_players;
    (void)i;
    (void)j;
    (void)k;
    (void)switched_res;
    (void)new_player;
    (void)player_still_there;
    (void)old_fox_it;

    if (function_hook_state_NetPlayersChanged == HOOK_ENABLED) {
        assert(0 && "NetPlayersChanged not implemented.");
        abort();
    } else {
        original_NetPlayersChanged(pNew_count, pNew_players);
    }
}

function_hook_state_t function_hook_state_NetHostGame = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(NetHostGame, function_hook_state_NetHostGame)
static tNet_game_details *(__cdecl*original_NetHostGame)(tNet_game_type, tNet_game_options *, int, char *, int) = (tNet_game_details *(__cdecl*)(tNet_game_type, tNet_game_options *, int, char *, int))0x004473b1;
CARM95_HOOK_FUNCTION(original_NetHostGame, NetHostGame)
tNet_game_details* __cdecl NetHostGame(tNet_game_type pGame_type, tNet_game_options *pOptions, int pStart_rank, char *pHost_name, int pCar_index) {
    tNet_game_details *game;
    void *host_address;
    tNet_game_player_info me;
    LOG_TRACE("(%d, %p, %d, \"%s\", %d)", pGame_type, pOptions, pStart_rank, pHost_name, pCar_index);

    (void)pGame_type;
    (void)pOptions;
    (void)pStart_rank;
    (void)pHost_name;
    (void)pCar_index;
    (void)game;
    (void)host_address;
    (void)me;

    if (function_hook_state_NetHostGame == HOOK_ENABLED) {
        assert(0 && "NetHostGame not implemented.");
        abort();
    } else {
        return original_NetHostGame(pGame_type, pOptions, pStart_rank, pHost_name, pCar_index);
    }
}

function_hook_state_t function_hook_state_NetInitClient = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(NetInitClient, function_hook_state_NetInitClient)
static int(__cdecl*original_NetInitClient)(tNet_game_details *) = (int(__cdecl*)(tNet_game_details *))0x004476bd;
CARM95_HOOK_FUNCTION(original_NetInitClient, NetInitClient)
int __cdecl NetInitClient(tNet_game_details *pDetails) {
    LOG_TRACE("(%p)", pDetails);

    (void)pDetails;

    if (function_hook_state_NetInitClient == HOOK_ENABLED) {
        assert(0 && "NetInitClient not implemented.");
        abort();
    } else {
        return original_NetInitClient(pDetails);
    }
}

function_hook_state_t function_hook_state_NetJoinGameLowLevel = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(NetJoinGameLowLevel, function_hook_state_NetJoinGameLowLevel)
static int(__cdecl*original_NetJoinGameLowLevel)(tNet_game_details *, char *) = (int(__cdecl*)(tNet_game_details *, char *))0x00447883;
CARM95_HOOK_FUNCTION(original_NetJoinGameLowLevel, NetJoinGameLowLevel)
int __cdecl NetJoinGameLowLevel(tNet_game_details *pDetails, char *pPlayer_name) {
    LOG_TRACE("(%p, \"%s\")", pDetails, pPlayer_name);

    (void)pDetails;
    (void)pPlayer_name;

    if (function_hook_state_NetJoinGameLowLevel == HOOK_ENABLED) {
        assert(0 && "NetJoinGameLowLevel not implemented.");
        abort();
    } else {
        return original_NetJoinGameLowLevel(pDetails, pPlayer_name);
    }
}

function_hook_state_t function_hook_state_NetJoinGame = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(NetJoinGame, function_hook_state_NetJoinGame)
static int(__cdecl*original_NetJoinGame)(tNet_game_details *, char *, int) = (int(__cdecl*)(tNet_game_details *, char *, int))0x004476d9;
CARM95_HOOK_FUNCTION(original_NetJoinGame, NetJoinGame)
int __cdecl NetJoinGame(tNet_game_details *pDetails, char *pPlayer_name, int pCar_index) {
    int result;
    tNet_message *the_message;
    tU32 start_time;
    LOG_TRACE("(%p, \"%s\", %d)", pDetails, pPlayer_name, pCar_index);

    (void)pDetails;
    (void)pPlayer_name;
    (void)pCar_index;
    (void)result;
    (void)the_message;
    (void)start_time;

    if (function_hook_state_NetJoinGame == HOOK_ENABLED) {
        assert(0 && "NetJoinGame not implemented.");
        abort();
    } else {
        return original_NetJoinGame(pDetails, pPlayer_name, pCar_index);
    }
}

function_hook_state_t function_hook_state_NetObtainSystemUserName = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(NetObtainSystemUserName, function_hook_state_NetObtainSystemUserName)
static void(__cdecl*original_NetObtainSystemUserName)(char *, int) = (void(__cdecl*)(char *, int))0x004478a3;
CARM95_HOOK_FUNCTION(original_NetObtainSystemUserName, NetObtainSystemUserName)
void __cdecl NetObtainSystemUserName(char *pName, int pMax_length) {
    LOG_TRACE("(\"%s\", %d)", pName, pMax_length);

    (void)pName;
    (void)pMax_length;

    if (function_hook_state_NetObtainSystemUserName == HOOK_ENABLED) {
        assert(0 && "NetObtainSystemUserName not implemented.");
        abort();
    } else {
        original_NetObtainSystemUserName(pName, pMax_length);
    }
}

function_hook_state_t function_hook_state_NetExtractGameID = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(NetExtractGameID, function_hook_state_NetExtractGameID)
static tU32(__cdecl*original_NetExtractGameID)(tNet_game_details *) = (tU32(__cdecl*)(tNet_game_details *))0x004478c5;
CARM95_HOOK_FUNCTION(original_NetExtractGameID, NetExtractGameID)
tU32 __cdecl NetExtractGameID(tNet_game_details *pDetails) {
    LOG_TRACE("(%p)", pDetails);

    (void)pDetails;

    if (function_hook_state_NetExtractGameID == HOOK_ENABLED) {
        assert(0 && "NetExtractGameID not implemented.");
        abort();
    } else {
        return original_NetExtractGameID(pDetails);
    }
}

function_hook_state_t function_hook_state_NetExtractPlayerID = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(NetExtractPlayerID, function_hook_state_NetExtractPlayerID)
static tPlayer_ID(__cdecl*original_NetExtractPlayerID)(tNet_game_details *) = (tPlayer_ID(__cdecl*)(tNet_game_details *))0x004478e1;
CARM95_HOOK_FUNCTION(original_NetExtractPlayerID, NetExtractPlayerID)
tPlayer_ID __cdecl NetExtractPlayerID(tNet_game_details *pDetails) {
    LOG_TRACE("(%p)", pDetails);

    (void)pDetails;

    if (function_hook_state_NetExtractPlayerID == HOOK_ENABLED) {
        assert(0 && "NetExtractPlayerID not implemented.");
        abort();
    } else {
        return original_NetExtractPlayerID(pDetails);
    }
}

function_hook_state_t function_hook_state_NetSendMessageToAddress = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(NetSendMessageToAddress, function_hook_state_NetSendMessageToAddress)
static int(__cdecl*original_NetSendMessageToAddress)(tNet_game_details *, tNet_message *, void *) = (int(__cdecl*)(tNet_game_details *, tNet_message *, void *))0x004478fd;
CARM95_HOOK_FUNCTION(original_NetSendMessageToAddress, NetSendMessageToAddress)
int __cdecl NetSendMessageToAddress(tNet_game_details *pDetails, tNet_message *pMessage, void *pAddress) {
    LOG_TRACE("(%p, %p, %p)", pDetails, pMessage, pAddress);

    (void)pDetails;
    (void)pMessage;
    (void)pAddress;

    if (function_hook_state_NetSendMessageToAddress == HOOK_ENABLED) {
        assert(0 && "NetSendMessageToAddress not implemented.");
        abort();
    } else {
        return original_NetSendMessageToAddress(pDetails, pMessage, pAddress);
    }
}

function_hook_state_t function_hook_state_NetSendMessageToPlayer = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(NetSendMessageToPlayer, function_hook_state_NetSendMessageToPlayer)
static int(__cdecl*original_NetSendMessageToPlayer)(tNet_game_details *, tNet_message *, tPlayer_ID) = (int(__cdecl*)(tNet_game_details *, tNet_message *, tPlayer_ID))0x0044796c;
CARM95_HOOK_FUNCTION(original_NetSendMessageToPlayer, NetSendMessageToPlayer)
int __cdecl NetSendMessageToPlayer(tNet_game_details *pDetails, tNet_message *pMessage, tPlayer_ID pPlayer) {
    int i;
    LOG_TRACE("(%p, %p, %u)", pDetails, pMessage, pPlayer);

    (void)pDetails;
    (void)pMessage;
    (void)pPlayer;
    (void)i;

    if (function_hook_state_NetSendMessageToPlayer == HOOK_ENABLED) {
        assert(0 && "NetSendMessageToPlayer not implemented.");
        abort();
    } else {
        return original_NetSendMessageToPlayer(pDetails, pMessage, pPlayer);
    }
}

function_hook_state_t function_hook_state_NetSendMessageToHost = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(NetSendMessageToHost, function_hook_state_NetSendMessageToHost)
static int(__cdecl*original_NetSendMessageToHost)(tNet_game_details *, tNet_message *) = (int(__cdecl*)(tNet_game_details *, tNet_message *))0x00447a10;
CARM95_HOOK_FUNCTION(original_NetSendMessageToHost, NetSendMessageToHost)
int __cdecl NetSendMessageToHost(tNet_game_details *pDetails, tNet_message *pMessage) {
    LOG_TRACE("(%p, %p)", pDetails, pMessage);

    (void)pDetails;
    (void)pMessage;

    if (function_hook_state_NetSendMessageToHost == HOOK_ENABLED) {
        assert(0 && "NetSendMessageToHost not implemented.");
        abort();
    } else {
        return original_NetSendMessageToHost(pDetails, pMessage);
    }
}

function_hook_state_t function_hook_state_NetReplyToMessage = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(NetReplyToMessage, function_hook_state_NetReplyToMessage)
static int(__cdecl*original_NetReplyToMessage)(tNet_game_details *, tNet_message *, tNet_message *) = (int(__cdecl*)(tNet_game_details *, tNet_message *, tNet_message *))0x00447a72;
CARM95_HOOK_FUNCTION(original_NetReplyToMessage, NetReplyToMessage)
int __cdecl NetReplyToMessage(tNet_game_details *pDetails, tNet_message *pIncoming_message, tNet_message *pReply_message) {
    LOG_TRACE("(%p, %p, %p)", pDetails, pIncoming_message, pReply_message);

    (void)pDetails;
    (void)pIncoming_message;
    (void)pReply_message;

    if (function_hook_state_NetReplyToMessage == HOOK_ENABLED) {
        assert(0 && "NetReplyToMessage not implemented.");
        abort();
    } else {
        return original_NetReplyToMessage(pDetails, pIncoming_message, pReply_message);
    }
}

function_hook_state_t function_hook_state_NetSendMessageToAllPlayers = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(NetSendMessageToAllPlayers, function_hook_state_NetSendMessageToAllPlayers)
static int(__cdecl*original_NetSendMessageToAllPlayers)(tNet_game_details *, tNet_message *) = (int(__cdecl*)(tNet_game_details *, tNet_message *))0x00447a99;
CARM95_HOOK_FUNCTION(original_NetSendMessageToAllPlayers, NetSendMessageToAllPlayers)
int __cdecl NetSendMessageToAllPlayers(tNet_game_details *pDetails, tNet_message *pMessage) {
    LOG_TRACE("(%p, %p)", pDetails, pMessage);

    (void)pDetails;
    (void)pMessage;

    if (function_hook_state_NetSendMessageToAllPlayers == HOOK_ENABLED) {
        assert(0 && "NetSendMessageToAllPlayers not implemented.");
        abort();
    } else {
        return original_NetSendMessageToAllPlayers(pDetails, pMessage);
    }
}

function_hook_state_t function_hook_state_NetGetContentsSize = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(NetGetContentsSize, function_hook_state_NetGetContentsSize)
static tU32(__cdecl*original_NetGetContentsSize)(tNet_message_type, tS32) = (tU32(__cdecl*)(tNet_message_type, tS32))0x00447adb;
CARM95_HOOK_FUNCTION(original_NetGetContentsSize, NetGetContentsSize)
tU32 __cdecl NetGetContentsSize(tNet_message_type pType, tS32 pSize_decider) {
    tU32 the_size;
    char __block0__s[256];
    LOG_TRACE("(%u, %d)", pType, pSize_decider);

    (void)pType;
    (void)pSize_decider;
    (void)the_size;
    (void)__block0__s;

    if (function_hook_state_NetGetContentsSize == HOOK_ENABLED) {
        assert(0 && "NetGetContentsSize not implemented.");
        abort();
    } else {
        return original_NetGetContentsSize(pType, pSize_decider);
    }
}

function_hook_state_t function_hook_state_NetGetMessageSize = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(NetGetMessageSize, function_hook_state_NetGetMessageSize)
static tU32(__cdecl*original_NetGetMessageSize)(tNet_message_type, tS32) = (tU32(__cdecl*)(tNet_message_type, tS32))0x00447dd9;
CARM95_HOOK_FUNCTION(original_NetGetMessageSize, NetGetMessageSize)
tU32 __cdecl NetGetMessageSize(tNet_message_type pType, tS32 pSize_decider) {
    LOG_TRACE("(%u, %d)", pType, pSize_decider);

    (void)pType;
    (void)pSize_decider;

    if (function_hook_state_NetGetMessageSize == HOOK_ENABLED) {
        assert(0 && "NetGetMessageSize not implemented.");
        abort();
    } else {
        return original_NetGetMessageSize(pType, pSize_decider);
    }
}

function_hook_state_t function_hook_state_NetCalcSizeDecider = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(NetCalcSizeDecider, function_hook_state_NetCalcSizeDecider)
static tS32(__cdecl*original_NetCalcSizeDecider)(tNet_contents *) = (tS32(__cdecl*)(tNet_contents *))0x00447dfc;
CARM95_HOOK_FUNCTION(original_NetCalcSizeDecider, NetCalcSizeDecider)
tS32 __cdecl NetCalcSizeDecider(tNet_contents *pContents) {
    tS32 the_decider;
    LOG_TRACE("(%p)", pContents);

    (void)pContents;
    (void)the_decider;

    if (function_hook_state_NetCalcSizeDecider == HOOK_ENABLED) {
        assert(0 && "NetCalcSizeDecider not implemented.");
        abort();
    } else {
        return original_NetCalcSizeDecider(pContents);
    }
}

function_hook_state_t function_hook_state_NetBuildMessage = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(NetBuildMessage, function_hook_state_NetBuildMessage)
static tNet_message *(__cdecl*original_NetBuildMessage)(tNet_message_type, tS32) = (tNet_message *(__cdecl*)(tNet_message_type, tS32))0x00447e7f;
CARM95_HOOK_FUNCTION(original_NetBuildMessage, NetBuildMessage)
tNet_message* __cdecl NetBuildMessage(tNet_message_type pType, tS32 pSize_decider) {
    tNet_message *the_message;
    tU32 the_size;
    LOG_TRACE("(%u, %d)", pType, pSize_decider);

    (void)pType;
    (void)pSize_decider;
    (void)the_message;
    (void)the_size;

    if (function_hook_state_NetBuildMessage == HOOK_ENABLED) {
        assert(0 && "NetBuildMessage not implemented.");
        abort();
    } else {
        return original_NetBuildMessage(pType, pSize_decider);
    }
}

function_hook_state_t function_hook_state_NetGetToHostContents = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(NetGetToHostContents, function_hook_state_NetGetToHostContents)
static tNet_contents *(__cdecl*original_NetGetToHostContents)(tNet_message_type, tS32) = (tNet_contents *(__cdecl*)(tNet_message_type, tS32))0x00447ee4;
CARM95_HOOK_FUNCTION(original_NetGetToHostContents, NetGetToHostContents)
tNet_contents* __cdecl NetGetToHostContents(tNet_message_type pType, tS32 pSize_decider) {
    tU32 the_size;
    tNet_contents *contents;
    LOG_TRACE("(%u, %d)", pType, pSize_decider);

    (void)pType;
    (void)pSize_decider;
    (void)the_size;
    (void)contents;

    if (function_hook_state_NetGetToHostContents == HOOK_ENABLED) {
        assert(0 && "NetGetToHostContents not implemented.");
        abort();
    } else {
        return original_NetGetToHostContents(pType, pSize_decider);
    }
}

function_hook_state_t function_hook_state_NetGetBroadcastContents = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(NetGetBroadcastContents, function_hook_state_NetGetBroadcastContents)
static tNet_contents *(__cdecl*original_NetGetBroadcastContents)(tNet_message_type, tS32) = (tNet_contents *(__cdecl*)(tNet_message_type, tS32))0x00447fcc;
CARM95_HOOK_FUNCTION(original_NetGetBroadcastContents, NetGetBroadcastContents)
tNet_contents* __cdecl NetGetBroadcastContents(tNet_message_type pType, tS32 pSize_decider) {
    tU32 the_size;
    tNet_contents *contents;
    LOG_TRACE("(%u, %d)", pType, pSize_decider);

    (void)pType;
    (void)pSize_decider;
    (void)the_size;
    (void)contents;

    if (function_hook_state_NetGetBroadcastContents == HOOK_ENABLED) {
        assert(0 && "NetGetBroadcastContents not implemented.");
        abort();
    } else {
        return original_NetGetBroadcastContents(pType, pSize_decider);
    }
}

function_hook_state_t function_hook_state_NetSendMessageStacks = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(NetSendMessageStacks, function_hook_state_NetSendMessageStacks)
static void(__cdecl*original_NetSendMessageStacks)() = (void(__cdecl*)())0x004480b4;
CARM95_HOOK_FUNCTION(original_NetSendMessageStacks, NetSendMessageStacks)
void __cdecl NetSendMessageStacks() {
    LOG_TRACE("()");


    if (function_hook_state_NetSendMessageStacks == HOOK_ENABLED) {
        assert(0 && "NetSendMessageStacks not implemented.");
        abort();
    } else {
        original_NetSendMessageStacks();
    }
}

function_hook_state_t function_hook_state_NetAllocateMessage = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(NetAllocateMessage, function_hook_state_NetAllocateMessage)
static tNet_message *(__cdecl*original_NetAllocateMessage)(int) = (tNet_message *(__cdecl*)(int))0x0044811f;
CARM95_HOOK_FUNCTION(original_NetAllocateMessage, NetAllocateMessage)
tNet_message* __cdecl NetAllocateMessage(int pSize) {
    void *pointer;
    void *last_message;
    char *test;
    static int rr_min;
    static int rr_mid;
    static int rr_max;
    tNet_message *message;
    int i;
    tNet_message *__block0__m;
    LOG_TRACE("(%d)", pSize);

    (void)pSize;
    (void)pointer;
    (void)last_message;
    (void)test;
    (void)rr_min;
    (void)rr_mid;
    (void)rr_max;
    (void)message;
    (void)i;
    (void)__block0__m;

    if (function_hook_state_NetAllocateMessage == HOOK_ENABLED) {
        assert(0 && "NetAllocateMessage not implemented.");
        abort();
    } else {
        return original_NetAllocateMessage(pSize);
    }
}

function_hook_state_t function_hook_state_NetFreeExcessMemory = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(NetFreeExcessMemory, function_hook_state_NetFreeExcessMemory)
static void(__cdecl*original_NetFreeExcessMemory)() = (void(__cdecl*)())0x004483eb;
CARM95_HOOK_FUNCTION(original_NetFreeExcessMemory, NetFreeExcessMemory)
void __cdecl NetFreeExcessMemory() {
    void *temp;
    LOG_TRACE("()");

    (void)temp;

    if (function_hook_state_NetFreeExcessMemory == HOOK_ENABLED) {
        assert(0 && "NetFreeExcessMemory not implemented.");
        abort();
    } else {
        original_NetFreeExcessMemory();
    }
}

function_hook_state_t function_hook_state_NetDisposeMessage = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(NetDisposeMessage, function_hook_state_NetDisposeMessage)
static int(__cdecl*original_NetDisposeMessage)(tNet_game_details *, tNet_message *) = (int(__cdecl*)(tNet_game_details *, tNet_message *))0x00448445;
CARM95_HOOK_FUNCTION(original_NetDisposeMessage, NetDisposeMessage)
int __cdecl NetDisposeMessage(tNet_game_details *pDetails, tNet_message *pMessage) {
    LOG_TRACE("(%p, %p)", pDetails, pMessage);

    (void)pDetails;
    (void)pMessage;

    if (function_hook_state_NetDisposeMessage == HOOK_ENABLED) {
        assert(0 && "NetDisposeMessage not implemented.");
        abort();
    } else {
        return original_NetDisposeMessage(pDetails, pMessage);
    }
}

function_hook_state_t function_hook_state_NetGetNextMessage = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(NetGetNextMessage, function_hook_state_NetGetNextMessage)
static tNet_message *(__cdecl*original_NetGetNextMessage)(tNet_game_details *, void **) = (tNet_message *(__cdecl*)(tNet_game_details *, void **))0x00448475;
CARM95_HOOK_FUNCTION(original_NetGetNextMessage, NetGetNextMessage)
tNet_message* __cdecl NetGetNextMessage(tNet_game_details *pDetails, void **pSender_address) {
    LOG_TRACE("(%p, %p)", pDetails, pSender_address);

    (void)pDetails;
    (void)pSender_address;

    if (function_hook_state_NetGetNextMessage == HOOK_ENABLED) {
        assert(0 && "NetGetNextMessage not implemented.");
        abort();
    } else {
        return original_NetGetNextMessage(pDetails, pSender_address);
    }
}

function_hook_state_t function_hook_state_ReceivedSendMeDetails = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(ReceivedSendMeDetails, function_hook_state_ReceivedSendMeDetails)
static void(__cdecl*original_ReceivedSendMeDetails)(tNet_contents *, void *) = (void(__cdecl*)(tNet_contents *, void *))0x0044929e;
CARM95_HOOK_FUNCTION(original_ReceivedSendMeDetails, ReceivedSendMeDetails)
void __cdecl ReceivedSendMeDetails(tNet_contents *pContents, void *pSender_address) {
    tNet_message *message;
    LOG_TRACE("(%p, %p)", pContents, pSender_address);

    (void)pContents;
    (void)pSender_address;
    (void)message;

    if (function_hook_state_ReceivedSendMeDetails == HOOK_ENABLED) {
        assert(0 && "ReceivedSendMeDetails not implemented.");
        abort();
    } else {
        original_ReceivedSendMeDetails(pContents, pSender_address);
    }
}

function_hook_state_t function_hook_state_ReceivedDetails = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(ReceivedDetails, function_hook_state_ReceivedDetails)
static void(__cdecl*original_ReceivedDetails)(tNet_contents *) = (void(__cdecl*)(tNet_contents *))0x004492f6;
CARM95_HOOK_FUNCTION(original_ReceivedDetails, ReceivedDetails)
void __cdecl ReceivedDetails(tNet_contents *pContents) {
    LOG_TRACE("(%p)", pContents);

    (void)pContents;

    if (function_hook_state_ReceivedDetails == HOOK_ENABLED) {
        assert(0 && "ReceivedDetails not implemented.");
        abort();
    } else {
        original_ReceivedDetails(pContents);
    }
}

function_hook_state_t function_hook_state_SendOutPlayerList = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(SendOutPlayerList, function_hook_state_SendOutPlayerList)
static void(__cdecl*original_SendOutPlayerList)() = (void(__cdecl*)())0x004495e0;
CARM95_HOOK_FUNCTION(original_SendOutPlayerList, SendOutPlayerList)
void __cdecl SendOutPlayerList() {
    tNet_message *message;
    int i;
    LOG_TRACE("()");

    (void)message;
    (void)i;

    if (function_hook_state_SendOutPlayerList == HOOK_ENABLED) {
        assert(0 && "SendOutPlayerList not implemented.");
        abort();
    } else {
        original_SendOutPlayerList();
    }
}

function_hook_state_t function_hook_state_ReceivedJoin = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(ReceivedJoin, function_hook_state_ReceivedJoin)
static void(__cdecl*original_ReceivedJoin)(tNet_contents *, void *) = (void(__cdecl*)(tNet_contents *, void *))0x00449330;
CARM95_HOOK_FUNCTION(original_ReceivedJoin, ReceivedJoin)
void __cdecl ReceivedJoin(tNet_contents *pContents, void *pSender_address) {
    int i;
    int new_player_count;
    int slot_index;
    tNet_message *message;
    tNet_game_player_info *new_players;
    LOG_TRACE("(%p, %p)", pContents, pSender_address);

    (void)pContents;
    (void)pSender_address;
    (void)i;
    (void)new_player_count;
    (void)slot_index;
    (void)message;
    (void)new_players;

    if (function_hook_state_ReceivedJoin == HOOK_ENABLED) {
        assert(0 && "ReceivedJoin not implemented.");
        abort();
    } else {
        original_ReceivedJoin(pContents, pSender_address);
    }
}

function_hook_state_t function_hook_state_KickPlayerOut = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(KickPlayerOut, function_hook_state_KickPlayerOut)
static void(__cdecl*original_KickPlayerOut)(tPlayer_ID) = (void(__cdecl*)(tPlayer_ID))0x004496f8;
CARM95_HOOK_FUNCTION(original_KickPlayerOut, KickPlayerOut)
void __cdecl KickPlayerOut(tPlayer_ID pID) {
    int i;
    int j;
    int new_player_count;
    tNet_game_player_info *new_players;
    LOG_TRACE("(%u)", pID);

    (void)pID;
    (void)i;
    (void)j;
    (void)new_player_count;
    (void)new_players;

    if (function_hook_state_KickPlayerOut == HOOK_ENABLED) {
        assert(0 && "KickPlayerOut not implemented.");
        abort();
    } else {
        original_KickPlayerOut(pID);
    }
}

function_hook_state_t function_hook_state_ReceivedLeave = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(ReceivedLeave, function_hook_state_ReceivedLeave)
static void(__cdecl*original_ReceivedLeave)(tNet_contents *, tNet_message *) = (void(__cdecl*)(tNet_contents *, tNet_message *))0x004496de;
CARM95_HOOK_FUNCTION(original_ReceivedLeave, ReceivedLeave)
void __cdecl ReceivedLeave(tNet_contents *pContents, tNet_message *pMessage) {
    LOG_TRACE("(%p, %p)", pContents, pMessage);

    (void)pContents;
    (void)pMessage;

    if (function_hook_state_ReceivedLeave == HOOK_ENABLED) {
        assert(0 && "ReceivedLeave not implemented.");
        abort();
    } else {
        original_ReceivedLeave(pContents, pMessage);
    }
}

function_hook_state_t function_hook_state_NetFullScreenMessage = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(NetFullScreenMessage, function_hook_state_NetFullScreenMessage)
static void(__cdecl*original_NetFullScreenMessage)(int, int) = (void(__cdecl*)(int, int))0x00448495;
CARM95_HOOK_FUNCTION(original_NetFullScreenMessage, NetFullScreenMessage)
void __cdecl NetFullScreenMessage(int pStr_index, int pLeave_it_up_there) {
    tU32 start_time;
    char *s;
    int gPixel_buffer_size;
    int restore_screen;
    char *gPixels_copy;
    char *gPalette_copy;
    LOG_TRACE("(%d, %d)", pStr_index, pLeave_it_up_there);

    (void)pStr_index;
    (void)pLeave_it_up_there;
    (void)start_time;
    (void)s;
    (void)gPixel_buffer_size;
    (void)restore_screen;
    (void)gPixels_copy;
    (void)gPalette_copy;

    if (function_hook_state_NetFullScreenMessage == HOOK_ENABLED) {
        assert(0 && "NetFullScreenMessage not implemented.");
        abort();
    } else {
        original_NetFullScreenMessage(pStr_index, pLeave_it_up_there);
    }
}

function_hook_state_t function_hook_state_HostHasBittenTheDust = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(HostHasBittenTheDust, function_hook_state_HostHasBittenTheDust)
static void(__cdecl*original_HostHasBittenTheDust)(int) = (void(__cdecl*)(int))0x0044989e;
CARM95_HOOK_FUNCTION(original_HostHasBittenTheDust, HostHasBittenTheDust)
void __cdecl HostHasBittenTheDust(int pMessage_index) {
    LOG_TRACE("(%d)", pMessage_index);

    (void)pMessage_index;

    if (function_hook_state_HostHasBittenTheDust == HOOK_ENABLED) {
        assert(0 && "HostHasBittenTheDust not implemented.");
        abort();
    } else {
        original_HostHasBittenTheDust(pMessage_index);
    }
}

function_hook_state_t function_hook_state_ReceivedHosticide = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(ReceivedHosticide, function_hook_state_ReceivedHosticide)
static void(__cdecl*original_ReceivedHosticide)(tNet_contents *) = (void(__cdecl*)(tNet_contents *))0x00449889;
CARM95_HOOK_FUNCTION(original_ReceivedHosticide, ReceivedHosticide)
void __cdecl ReceivedHosticide(tNet_contents *pContents) {
    LOG_TRACE("(%p)", pContents);

    (void)pContents;

    if (function_hook_state_ReceivedHosticide == HOOK_ENABLED) {
        assert(0 && "ReceivedHosticide not implemented.");
        abort();
    } else {
        original_ReceivedHosticide(pContents);
    }
}

function_hook_state_t function_hook_state_ConfirmReceipt = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(ConfirmReceipt, function_hook_state_ConfirmReceipt)
void ConfirmReceipt() {
    tNet_message *the_message;
    LOG_TRACE("()");

    (void)the_message;

    if (function_hook_state_ConfirmReceipt == HOOK_ENABLED) {
        assert(0 && "ConfirmReceipt not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}

function_hook_state_t function_hook_state_ReceivedNewPlayerList = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(ReceivedNewPlayerList, function_hook_state_ReceivedNewPlayerList)
static void(__cdecl*original_ReceivedNewPlayerList)(tNet_contents *, tNet_message *) = (void(__cdecl*)(tNet_contents *, tNet_message *))0x004498d8;
CARM95_HOOK_FUNCTION(original_ReceivedNewPlayerList, ReceivedNewPlayerList)
void __cdecl ReceivedNewPlayerList(tNet_contents *pContents, tNet_message *pM) {
    int i;
    LOG_TRACE("(%p, %p)", pContents, pM);

    (void)pContents;
    (void)pM;
    (void)i;

    if (function_hook_state_ReceivedNewPlayerList == HOOK_ENABLED) {
        assert(0 && "ReceivedNewPlayerList not implemented.");
        abort();
    } else {
        original_ReceivedNewPlayerList(pContents, pM);
    }
}

function_hook_state_t function_hook_state_ReceivedRaceOver = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(ReceivedRaceOver, function_hook_state_ReceivedRaceOver)
static void(__cdecl*original_ReceivedRaceOver)(tNet_contents *) = (void(__cdecl*)(tNet_contents *))0x00449afb;
CARM95_HOOK_FUNCTION(original_ReceivedRaceOver, ReceivedRaceOver)
void __cdecl ReceivedRaceOver(tNet_contents *pContents) {
    LOG_TRACE("(%p)", pContents);

    (void)pContents;

    if (function_hook_state_ReceivedRaceOver == HOOK_ENABLED) {
        assert(0 && "ReceivedRaceOver not implemented.");
        abort();
    } else {
        original_ReceivedRaceOver(pContents);
    }
}

function_hook_state_t function_hook_state_ReceivedStatusReport = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(ReceivedStatusReport, function_hook_state_ReceivedStatusReport)
static void(__cdecl*original_ReceivedStatusReport)(tNet_contents *, tNet_message *) = (void(__cdecl*)(tNet_contents *, tNet_message *))0x00449b46;
CARM95_HOOK_FUNCTION(original_ReceivedStatusReport, ReceivedStatusReport)
void __cdecl ReceivedStatusReport(tNet_contents *pContents, tNet_message *pMessage) {
    int i;
    LOG_TRACE("(%p, %p)", pContents, pMessage);

    (void)pContents;
    (void)pMessage;
    (void)i;

    if (function_hook_state_ReceivedStatusReport == HOOK_ENABLED) {
        assert(0 && "ReceivedStatusReport not implemented.");
        abort();
    } else {
        original_ReceivedStatusReport(pContents, pMessage);
    }
}

function_hook_state_t function_hook_state_ReceivedStartRace = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(ReceivedStartRace, function_hook_state_ReceivedStartRace)
static void(__cdecl*original_ReceivedStartRace)(tNet_contents *) = (void(__cdecl*)(tNet_contents *))0x00449c42;
CARM95_HOOK_FUNCTION(original_ReceivedStartRace, ReceivedStartRace)
void __cdecl ReceivedStartRace(tNet_contents *pContents) {
    int i;
    int index;
    LOG_TRACE("(%p)", pContents);

    (void)pContents;
    (void)i;
    (void)index;

    if (function_hook_state_ReceivedStartRace == HOOK_ENABLED) {
        assert(0 && "ReceivedStartRace not implemented.");
        abort();
    } else {
        original_ReceivedStartRace(pContents);
    }
}

function_hook_state_t function_hook_state_ReceivedGuaranteeReply = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(ReceivedGuaranteeReply, function_hook_state_ReceivedGuaranteeReply)
static void(__cdecl*original_ReceivedGuaranteeReply)(tNet_contents *) = (void(__cdecl*)(tNet_contents *))0x00448695;
CARM95_HOOK_FUNCTION(original_ReceivedGuaranteeReply, ReceivedGuaranteeReply)
void __cdecl ReceivedGuaranteeReply(tNet_contents *pContents) {
    int i;
    LOG_TRACE("(%p)", pContents);

    (void)pContents;
    (void)i;

    if (function_hook_state_ReceivedGuaranteeReply == HOOK_ENABLED) {
        assert(0 && "ReceivedGuaranteeReply not implemented.");
        abort();
    } else {
        original_ReceivedGuaranteeReply(pContents);
    }
}

function_hook_state_t function_hook_state_ReceivedHeadup = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(ReceivedHeadup, function_hook_state_ReceivedHeadup)
static void(__cdecl*original_ReceivedHeadup)(tNet_contents *) = (void(__cdecl*)(tNet_contents *))0x004486fb;
CARM95_HOOK_FUNCTION(original_ReceivedHeadup, ReceivedHeadup)
void __cdecl ReceivedHeadup(tNet_contents *pContents) {
    LOG_TRACE("(%p)", pContents);

    (void)pContents;

    if (function_hook_state_ReceivedHeadup == HOOK_ENABLED) {
        assert(0 && "ReceivedHeadup not implemented.");
        abort();
    } else {
        original_ReceivedHeadup(pContents);
    }
}

function_hook_state_t function_hook_state_ReceivedHostQuery = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(ReceivedHostQuery, function_hook_state_ReceivedHostQuery)
static void(__cdecl*original_ReceivedHostQuery)(tNet_contents *, tNet_message *) = (void(__cdecl*)(tNet_contents *, tNet_message *))0x0044872d;
CARM95_HOOK_FUNCTION(original_ReceivedHostQuery, ReceivedHostQuery)
void __cdecl ReceivedHostQuery(tNet_contents *pContents, tNet_message *pMessage) {
    tNet_message *message;
    LOG_TRACE("(%p, %p)", pContents, pMessage);

    (void)pContents;
    (void)pMessage;
    (void)message;

    if (function_hook_state_ReceivedHostQuery == HOOK_ENABLED) {
        assert(0 && "ReceivedHostQuery not implemented.");
        abort();
    } else {
        original_ReceivedHostQuery(pContents, pMessage);
    }
}

function_hook_state_t function_hook_state_ReceivedHostReply = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(ReceivedHostReply, function_hook_state_ReceivedHostReply)
static void(__cdecl*original_ReceivedHostReply)(tNet_contents *) = (void(__cdecl*)(tNet_contents *))0x0044879d;
CARM95_HOOK_FUNCTION(original_ReceivedHostReply, ReceivedHostReply)
void __cdecl ReceivedHostReply(tNet_contents *pContents) {
    tNet_message *message;
    LOG_TRACE("(%p)", pContents);

    (void)pContents;
    (void)message;

    if (function_hook_state_ReceivedHostReply == HOOK_ENABLED) {
        assert(0 && "ReceivedHostReply not implemented.");
        abort();
    } else {
        original_ReceivedHostReply(pContents);
    }
}

function_hook_state_t function_hook_state_SendGuaranteeReply = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(SendGuaranteeReply, function_hook_state_SendGuaranteeReply)
static void(__cdecl*original_SendGuaranteeReply)(tNet_message *, void *) = (void(__cdecl*)(tNet_message *, void *))0x0044882b;
CARM95_HOOK_FUNCTION(original_SendGuaranteeReply, SendGuaranteeReply)
void __cdecl SendGuaranteeReply(tNet_message *pMessage, void *pSender_address) {
    tNet_message *message;
    LOG_TRACE("(%p, %p)", pMessage, pSender_address);

    (void)pMessage;
    (void)pSender_address;
    (void)message;

    if (function_hook_state_SendGuaranteeReply == HOOK_ENABLED) {
        assert(0 && "SendGuaranteeReply not implemented.");
        abort();
    } else {
        original_SendGuaranteeReply(pMessage, pSender_address);
    }
}

function_hook_state_t function_hook_state_PlayerIsInList = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(PlayerIsInList, function_hook_state_PlayerIsInList)
static int(__cdecl*original_PlayerIsInList)(tPlayer_ID) = (int(__cdecl*)(tPlayer_ID))0x00449f18;
CARM95_HOOK_FUNCTION(original_PlayerIsInList, PlayerIsInList)
int __cdecl PlayerIsInList(tPlayer_ID pID) {
    int i;
    LOG_TRACE("(%u)", pID);

    (void)pID;
    (void)i;

    if (function_hook_state_PlayerIsInList == HOOK_ENABLED) {
        assert(0 && "PlayerIsInList not implemented.");
        abort();
    } else {
        return original_PlayerIsInList(pID);
    }
}

function_hook_state_t function_hook_state_ReceivedTimeSync = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(ReceivedTimeSync, function_hook_state_ReceivedTimeSync)
static void(__cdecl*original_ReceivedTimeSync)(tNet_contents *, tNet_message *, tU32) = (void(__cdecl*)(tNet_contents *, tNet_message *, tU32))0x00448874;
CARM95_HOOK_FUNCTION(original_ReceivedTimeSync, ReceivedTimeSync)
void __cdecl ReceivedTimeSync(tNet_contents *pContents, tNet_message *pMessage, tU32 pReceive_time) {
    LOG_TRACE("(%p, %p, %u)", pContents, pMessage, pReceive_time);

    (void)pContents;
    (void)pMessage;
    (void)pReceive_time;

    if (function_hook_state_ReceivedTimeSync == HOOK_ENABLED) {
        assert(0 && "ReceivedTimeSync not implemented.");
        abort();
    } else {
        original_ReceivedTimeSync(pContents, pMessage, pReceive_time);
    }
}

function_hook_state_t function_hook_state_ReceivedConfirm = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(ReceivedConfirm, function_hook_state_ReceivedConfirm)
static void(__cdecl*original_ReceivedConfirm)(tNet_contents *) = (void(__cdecl*)(tNet_contents *))0x004488b4;
CARM95_HOOK_FUNCTION(original_ReceivedConfirm, ReceivedConfirm)
void __cdecl ReceivedConfirm(tNet_contents *pContents) {
    int i;
    LOG_TRACE("(%p)", pContents);

    (void)pContents;
    (void)i;

    if (function_hook_state_ReceivedConfirm == HOOK_ENABLED) {
        assert(0 && "ReceivedConfirm not implemented.");
        abort();
    } else {
        original_ReceivedConfirm(pContents);
    }
}

function_hook_state_t function_hook_state_ReceivedDisableCar = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(ReceivedDisableCar, function_hook_state_ReceivedDisableCar)
static void(__cdecl*original_ReceivedDisableCar)(tNet_contents *) = (void(__cdecl*)(tNet_contents *))0x00448914;
CARM95_HOOK_FUNCTION(original_ReceivedDisableCar, ReceivedDisableCar)
void __cdecl ReceivedDisableCar(tNet_contents *pContents) {
    LOG_TRACE("(%p)", pContents);

    (void)pContents;

    if (function_hook_state_ReceivedDisableCar == HOOK_ENABLED) {
        assert(0 && "ReceivedDisableCar not implemented.");
        abort();
    } else {
        original_ReceivedDisableCar(pContents);
    }
}

function_hook_state_t function_hook_state_ReceivedEnableCar = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(ReceivedEnableCar, function_hook_state_ReceivedEnableCar)
static void(__cdecl*original_ReceivedEnableCar)(tNet_contents *) = (void(__cdecl*)(tNet_contents *))0x0044891f;
CARM95_HOOK_FUNCTION(original_ReceivedEnableCar, ReceivedEnableCar)
void __cdecl ReceivedEnableCar(tNet_contents *pContents) {
    LOG_TRACE("(%p)", pContents);

    (void)pContents;

    if (function_hook_state_ReceivedEnableCar == HOOK_ENABLED) {
        assert(0 && "ReceivedEnableCar not implemented.");
        abort();
    } else {
        original_ReceivedEnableCar(pContents);
    }
}

function_hook_state_t function_hook_state_ReceivedScores = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(ReceivedScores, function_hook_state_ReceivedScores)
static void(__cdecl*original_ReceivedScores)(tNet_contents *) = (void(__cdecl*)(tNet_contents *))0x0044892a;
CARM95_HOOK_FUNCTION(original_ReceivedScores, ReceivedScores)
void __cdecl ReceivedScores(tNet_contents *pContents) {
    int i;
    LOG_TRACE("(%p)", pContents);

    (void)pContents;
    (void)i;

    if (function_hook_state_ReceivedScores == HOOK_ENABLED) {
        assert(0 && "ReceivedScores not implemented.");
        abort();
    } else {
        original_ReceivedScores(pContents);
    }
}

function_hook_state_t function_hook_state_ReceivedWasted = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(ReceivedWasted, function_hook_state_ReceivedWasted)
static void(__cdecl*original_ReceivedWasted)(tNet_contents *) = (void(__cdecl*)(tNet_contents *))0x00448981;
CARM95_HOOK_FUNCTION(original_ReceivedWasted, ReceivedWasted)
void __cdecl ReceivedWasted(tNet_contents *pContents) {
    tNet_game_player_info *victim;
    tNet_game_player_info *culprit;
    char s[256];
    tCar_spec *car;
    static tS32 last_got_wasted_time;
    static tS32 last_wasted_em_time;
    static tS32 last_wasty_message_time;
    static tNet_game_player_info *last_culprit;
    static tNet_game_player_info *last_victim;
    LOG_TRACE("(%p)", pContents);

    (void)pContents;
    (void)victim;
    (void)culprit;
    (void)s;
    (void)car;
    (void)last_got_wasted_time;
    (void)last_wasted_em_time;
    (void)last_wasty_message_time;
    (void)last_culprit;
    (void)last_victim;

    if (function_hook_state_ReceivedWasted == HOOK_ENABLED) {
        assert(0 && "ReceivedWasted not implemented.");
        abort();
    } else {
        original_ReceivedWasted(pContents);
    }
}

function_hook_state_t function_hook_state_ReceivedCarDetailsReq = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(ReceivedCarDetailsReq, function_hook_state_ReceivedCarDetailsReq)
static void(__cdecl*original_ReceivedCarDetailsReq)(tNet_contents *, void *) = (void(__cdecl*)(tNet_contents *, void *))0x00448ca9;
CARM95_HOOK_FUNCTION(original_ReceivedCarDetailsReq, ReceivedCarDetailsReq)
void __cdecl ReceivedCarDetailsReq(tNet_contents *pContents, void *pSender_address) {
    tNet_message *message;
    int i;
    LOG_TRACE("(%p, %p)", pContents, pSender_address);

    (void)pContents;
    (void)pSender_address;
    (void)message;
    (void)i;

    if (function_hook_state_ReceivedCarDetailsReq == HOOK_ENABLED) {
        assert(0 && "ReceivedCarDetailsReq not implemented.");
        abort();
    } else {
        original_ReceivedCarDetailsReq(pContents, pSender_address);
    }
}

function_hook_state_t function_hook_state_ReceivedCarDetails = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(ReceivedCarDetails, function_hook_state_ReceivedCarDetails)
static void(__cdecl*original_ReceivedCarDetails)(tNet_contents *) = (void(__cdecl*)(tNet_contents *))0x00448d70;
CARM95_HOOK_FUNCTION(original_ReceivedCarDetails, ReceivedCarDetails)
void __cdecl ReceivedCarDetails(tNet_contents *pContents) {
    int i;
    int j;
    LOG_TRACE("(%p)", pContents);

    (void)pContents;
    (void)i;
    (void)j;

    if (function_hook_state_ReceivedCarDetails == HOOK_ENABLED) {
        assert(0 && "ReceivedCarDetails not implemented.");
        abort();
    } else {
        original_ReceivedCarDetails(pContents);
    }
}

function_hook_state_t function_hook_state_ReceivedGameScores = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(ReceivedGameScores, function_hook_state_ReceivedGameScores)
static void(__cdecl*original_ReceivedGameScores)(tNet_contents *) = (void(__cdecl*)(tNet_contents *))0x00448e41;
CARM95_HOOK_FUNCTION(original_ReceivedGameScores, ReceivedGameScores)
void __cdecl ReceivedGameScores(tNet_contents *pContents) {
    int i;
    LOG_TRACE("(%p)", pContents);

    (void)pContents;
    (void)i;

    if (function_hook_state_ReceivedGameScores == HOOK_ENABLED) {
        assert(0 && "ReceivedGameScores not implemented.");
        abort();
    } else {
        original_ReceivedGameScores(pContents);
    }
}

function_hook_state_t function_hook_state_ReceivedMessage = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(ReceivedMessage, function_hook_state_ReceivedMessage)
static void(__cdecl*original_ReceivedMessage)(tNet_message *, void *, tU32) = (void(__cdecl*)(tNet_message *, void *, tU32))0x00448eca;
CARM95_HOOK_FUNCTION(original_ReceivedMessage, ReceivedMessage)
void __cdecl ReceivedMessage(tNet_message *pMessage, void *pSender_address, tU32 pReceive_time) {
    tNet_contents *contents;
    int i;
    LOG_TRACE("(%p, %p, %u)", pMessage, pSender_address, pReceive_time);

    (void)pMessage;
    (void)pSender_address;
    (void)pReceive_time;
    (void)contents;
    (void)i;

    if (function_hook_state_ReceivedMessage == HOOK_ENABLED) {
        assert(0 && "ReceivedMessage not implemented.");
        abort();
    } else {
        original_ReceivedMessage(pMessage, pSender_address, pReceive_time);
    }
}

function_hook_state_t function_hook_state_NetReceiveAndProcessMessages = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(NetReceiveAndProcessMessages, function_hook_state_NetReceiveAndProcessMessages)
static void(__cdecl*original_NetReceiveAndProcessMessages)() = (void(__cdecl*)())0x00449f82;
CARM95_HOOK_FUNCTION(original_NetReceiveAndProcessMessages, NetReceiveAndProcessMessages)
void __cdecl NetReceiveAndProcessMessages() {
    tNet_message *message;
    void *sender_address;
    tU32 receive_time;
    int old_net_service;
    LOG_TRACE("()");

    (void)message;
    (void)sender_address;
    (void)receive_time;
    (void)old_net_service;

    if (function_hook_state_NetReceiveAndProcessMessages == HOOK_ENABLED) {
        assert(0 && "NetReceiveAndProcessMessages not implemented.");
        abort();
    } else {
        original_NetReceiveAndProcessMessages();
    }
}

function_hook_state_t function_hook_state_BroadcastStatus = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(BroadcastStatus, function_hook_state_BroadcastStatus)
static void(__cdecl*original_BroadcastStatus)() = (void(__cdecl*)())0x0044a046;
CARM95_HOOK_FUNCTION(original_BroadcastStatus, BroadcastStatus)
void __cdecl BroadcastStatus() {
    tNet_message *message;
    LOG_TRACE("()");

    (void)message;

    if (function_hook_state_BroadcastStatus == HOOK_ENABLED) {
        assert(0 && "BroadcastStatus not implemented.");
        abort();
    } else {
        original_BroadcastStatus();
    }
}

function_hook_state_t function_hook_state_CheckForDisappearees = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(CheckForDisappearees, function_hook_state_CheckForDisappearees)
static void(__cdecl*original_CheckForDisappearees)() = (void(__cdecl*)())0x0044a2a3;
CARM95_HOOK_FUNCTION(original_CheckForDisappearees, CheckForDisappearees)
void __cdecl CheckForDisappearees() {
    int i;
    int j;
    tU32 the_time;
    char s[256];
    char *s2;
    LOG_TRACE("()");

    (void)i;
    (void)j;
    (void)the_time;
    (void)s;
    (void)s2;

    if (function_hook_state_CheckForDisappearees == HOOK_ENABLED) {
        assert(0 && "CheckForDisappearees not implemented.");
        abort();
    } else {
        original_CheckForDisappearees();
    }
}

function_hook_state_t function_hook_state_CheckForPendingStartRace = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(CheckForPendingStartRace, function_hook_state_CheckForPendingStartRace)
static void(__cdecl*original_CheckForPendingStartRace)() = (void(__cdecl*)())0x0044a478;
CARM95_HOOK_FUNCTION(original_CheckForPendingStartRace, CheckForPendingStartRace)
void __cdecl CheckForPendingStartRace() {
    int i;
    LOG_TRACE("()");

    (void)i;

    if (function_hook_state_CheckForPendingStartRace == HOOK_ENABLED) {
        assert(0 && "CheckForPendingStartRace not implemented.");
        abort();
    } else {
        original_CheckForPendingStartRace();
    }
}

function_hook_state_t function_hook_state_NetService = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(NetService, function_hook_state_NetService)
static void(__cdecl*original_NetService)(int) = (void(__cdecl*)(int))0x0044a08a;
CARM95_HOOK_FUNCTION(original_NetService, NetService)
void __cdecl NetService(int pIn_race) {
    tU32 time;
    static tU32 last_status_broadcast;
    LOG_TRACE("(%d)", pIn_race);

    (void)pIn_race;
    (void)time;
    (void)last_status_broadcast;

    if (function_hook_state_NetService == HOOK_ENABLED) {
        assert(0 && "NetService not implemented.");
        abort();
    } else {
        original_NetService(pIn_race);
    }
}

function_hook_state_t function_hook_state_NetFinishRace = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(NetFinishRace, function_hook_state_NetFinishRace)
static void(__cdecl*original_NetFinishRace)(tNet_game_details *, tRace_over_reason) = (void(__cdecl*)(tNet_game_details *, tRace_over_reason))0x0044a4e1;
CARM95_HOOK_FUNCTION(original_NetFinishRace, NetFinishRace)
void __cdecl NetFinishRace(tNet_game_details *pDetails, tRace_over_reason pReason) {
    tNet_message *the_message;
    LOG_TRACE("(%p, %d)", pDetails, pReason);

    (void)pDetails;
    (void)pReason;
    (void)the_message;

    if (function_hook_state_NetFinishRace == HOOK_ENABLED) {
        assert(0 && "NetFinishRace not implemented.");
        abort();
    } else {
        original_NetFinishRace(pDetails, pReason);
    }
}

function_hook_state_t function_hook_state_NetPlayerStatusChanged = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(NetPlayerStatusChanged, function_hook_state_NetPlayerStatusChanged)
static void(__cdecl*original_NetPlayerStatusChanged)(tPlayer_status) = (void(__cdecl*)(tPlayer_status))0x0044a525;
CARM95_HOOK_FUNCTION(original_NetPlayerStatusChanged, NetPlayerStatusChanged)
void __cdecl NetPlayerStatusChanged(tPlayer_status pNew_status) {
    LOG_TRACE("(%d)", pNew_status);

    (void)pNew_status;

    if (function_hook_state_NetPlayerStatusChanged == HOOK_ENABLED) {
        assert(0 && "NetPlayerStatusChanged not implemented.");
        abort();
    } else {
        original_NetPlayerStatusChanged(pNew_status);
    }
}

function_hook_state_t function_hook_state_NetGetPlayerStatus = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(NetGetPlayerStatus, function_hook_state_NetGetPlayerStatus)
static tPlayer_status(__cdecl*original_NetGetPlayerStatus)() = (tPlayer_status(__cdecl*)())0x0044a5d0;
CARM95_HOOK_FUNCTION(original_NetGetPlayerStatus, NetGetPlayerStatus)
tPlayer_status __cdecl NetGetPlayerStatus() {
    LOG_TRACE("()");


    if (function_hook_state_NetGetPlayerStatus == HOOK_ENABLED) {
        assert(0 && "NetGetPlayerStatus not implemented.");
        abort();
    } else {
        return original_NetGetPlayerStatus();
    }
}

function_hook_state_t function_hook_state_NetGuaranteedSendMessageToAllPlayers = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(NetGuaranteedSendMessageToAllPlayers, function_hook_state_NetGuaranteedSendMessageToAllPlayers)
static int(__cdecl*original_NetGuaranteedSendMessageToAllPlayers)(tNet_game_details *, tNet_message *, int(**)(tU32, tNet_message *)) = (int(__cdecl*)(tNet_game_details *, tNet_message *, int(**)(tU32, tNet_message *)))0x0044a5ef;
CARM95_HOOK_FUNCTION(original_NetGuaranteedSendMessageToAllPlayers, NetGuaranteedSendMessageToAllPlayers)
int __cdecl NetGuaranteedSendMessageToAllPlayers(tNet_game_details *pDetails, tNet_message *pMessage, int(**pNotifyFail)(tU32, tNet_message *)) {
    int i;
    int err;
    LOG_TRACE("(%p, %p, %p)", pDetails, pMessage, pNotifyFail);

    (void)pDetails;
    (void)pMessage;
    (void)pNotifyFail;
    (void)i;
    (void)err;

    if (function_hook_state_NetGuaranteedSendMessageToAllPlayers == HOOK_ENABLED) {
        assert(0 && "NetGuaranteedSendMessageToAllPlayers not implemented.");
        abort();
    } else {
        return original_NetGuaranteedSendMessageToAllPlayers(pDetails, pMessage, pNotifyFail);
    }
}

function_hook_state_t function_hook_state_NetGuaranteedSendMessageToEverybody = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(NetGuaranteedSendMessageToEverybody, function_hook_state_NetGuaranteedSendMessageToEverybody)
static int(__cdecl*original_NetGuaranteedSendMessageToEverybody)(tNet_game_details *, tNet_message *, int(**)(tU32, tNet_message *)) = (int(__cdecl*)(tNet_game_details *, tNet_message *, int(**)(tU32, tNet_message *)))0x0044a689;
CARM95_HOOK_FUNCTION(original_NetGuaranteedSendMessageToEverybody, NetGuaranteedSendMessageToEverybody)
int __cdecl NetGuaranteedSendMessageToEverybody(tNet_game_details *pDetails, tNet_message *pMessage, int(**pNotifyFail)(tU32, tNet_message *)) {
    LOG_TRACE("(%p, %p, %p)", pDetails, pMessage, pNotifyFail);

    (void)pDetails;
    (void)pMessage;
    (void)pNotifyFail;

    if (function_hook_state_NetGuaranteedSendMessageToEverybody == HOOK_ENABLED) {
        assert(0 && "NetGuaranteedSendMessageToEverybody not implemented.");
        abort();
    } else {
        return original_NetGuaranteedSendMessageToEverybody(pDetails, pMessage, pNotifyFail);
    }
}

function_hook_state_t function_hook_state_NetGuaranteedSendMessageToHost = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(NetGuaranteedSendMessageToHost, function_hook_state_NetGuaranteedSendMessageToHost)
static int(__cdecl*original_NetGuaranteedSendMessageToHost)(tNet_game_details *, tNet_message *, int(**)(tU32, tNet_message *)) = (int(__cdecl*)(tNet_game_details *, tNet_message *, int(**)(tU32, tNet_message *)))0x0044a6f9;
CARM95_HOOK_FUNCTION(original_NetGuaranteedSendMessageToHost, NetGuaranteedSendMessageToHost)
int __cdecl NetGuaranteedSendMessageToHost(tNet_game_details *pDetails, tNet_message *pMessage, int(**pNotifyFail)(tU32, tNet_message *)) {
    LOG_TRACE("(%p, %p, %p)", pDetails, pMessage, pNotifyFail);

    (void)pDetails;
    (void)pMessage;
    (void)pNotifyFail;

    if (function_hook_state_NetGuaranteedSendMessageToHost == HOOK_ENABLED) {
        assert(0 && "NetGuaranteedSendMessageToHost not implemented.");
        abort();
    } else {
        return original_NetGuaranteedSendMessageToHost(pDetails, pMessage, pNotifyFail);
    }
}

function_hook_state_t function_hook_state_NetGuaranteedSendMessageToPlayer = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(NetGuaranteedSendMessageToPlayer, function_hook_state_NetGuaranteedSendMessageToPlayer)
static int(__cdecl*original_NetGuaranteedSendMessageToPlayer)(tNet_game_details *, tNet_message *, tPlayer_ID, int(**)(tU32, tNet_message *)) = (int(__cdecl*)(tNet_game_details *, tNet_message *, tPlayer_ID, int(**)(tU32, tNet_message *)))0x0044a721;
CARM95_HOOK_FUNCTION(original_NetGuaranteedSendMessageToPlayer, NetGuaranteedSendMessageToPlayer)
int __cdecl NetGuaranteedSendMessageToPlayer(tNet_game_details *pDetails, tNet_message *pMessage, tPlayer_ID pPlayer, int(**pNotifyFail)(tU32, tNet_message *)) {
    int i;
    LOG_TRACE("(%p, %p, %u, %p)", pDetails, pMessage, pPlayer, pNotifyFail);

    (void)pDetails;
    (void)pMessage;
    (void)pPlayer;
    (void)pNotifyFail;
    (void)i;

    if (function_hook_state_NetGuaranteedSendMessageToPlayer == HOOK_ENABLED) {
        assert(0 && "NetGuaranteedSendMessageToPlayer not implemented.");
        abort();
    } else {
        return original_NetGuaranteedSendMessageToPlayer(pDetails, pMessage, pPlayer, pNotifyFail);
    }
}

function_hook_state_t function_hook_state_NetGuaranteedSendMessageToAddress = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(NetGuaranteedSendMessageToAddress, function_hook_state_NetGuaranteedSendMessageToAddress)
static int(__cdecl*original_NetGuaranteedSendMessageToAddress)(tNet_game_details *, tNet_message *, void *, int(**)(tU32, tNet_message *)) = (int(__cdecl*)(tNet_game_details *, tNet_message *, void *, int(**)(tU32, tNet_message *)))0x0044a80f;
CARM95_HOOK_FUNCTION(original_NetGuaranteedSendMessageToAddress, NetGuaranteedSendMessageToAddress)
int __cdecl NetGuaranteedSendMessageToAddress(tNet_game_details *pDetails, tNet_message *pMessage, void *pAddress, int(**pNotifyFail)(tU32, tNet_message *)) {
    char __block0__s[256];
    LOG_TRACE("(%p, %p, %p, %p)", pDetails, pMessage, pAddress, pNotifyFail);

    (void)pDetails;
    (void)pMessage;
    (void)pAddress;
    (void)pNotifyFail;
    (void)__block0__s;

    if (function_hook_state_NetGuaranteedSendMessageToAddress == HOOK_ENABLED) {
        assert(0 && "NetGuaranteedSendMessageToAddress not implemented.");
        abort();
    } else {
        return original_NetGuaranteedSendMessageToAddress(pDetails, pMessage, pAddress, pNotifyFail);
    }
}

function_hook_state_t function_hook_state_ResendGuaranteedMessages = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(ResendGuaranteedMessages, function_hook_state_ResendGuaranteedMessages)
static void(__cdecl*original_ResendGuaranteedMessages)() = (void(__cdecl*)())0x0044a9f1;
CARM95_HOOK_FUNCTION(original_ResendGuaranteedMessages, ResendGuaranteedMessages)
void __cdecl ResendGuaranteedMessages() {
    int i;
    int j;
    tU32 time;
    LOG_TRACE("()");

    (void)i;
    (void)j;
    (void)time;

    if (function_hook_state_ResendGuaranteedMessages == HOOK_ENABLED) {
        assert(0 && "ResendGuaranteedMessages not implemented.");
        abort();
    } else {
        original_ResendGuaranteedMessages();
    }
}

function_hook_state_t function_hook_state_SampleFailNotifier = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(SampleFailNotifier, function_hook_state_SampleFailNotifier)
static int(__cdecl*original_SampleFailNotifier)(tU32, tNet_message *) = (int(__cdecl*)(tU32, tNet_message *))0x0044ad06;
CARM95_HOOK_FUNCTION(original_SampleFailNotifier, SampleFailNotifier)
int __cdecl SampleFailNotifier(tU32 pAge, tNet_message *pMessage) {
    LOG_TRACE("(%u, %p)", pAge, pMessage);

    (void)pAge;
    (void)pMessage;

    if (function_hook_state_SampleFailNotifier == HOOK_ENABLED) {
        assert(0 && "SampleFailNotifier not implemented.");
        abort();
    } else {
        return original_SampleFailNotifier(pAge, pMessage);
    }
}

function_hook_state_t function_hook_state_NetWaitForGuaranteeReplies = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(NetWaitForGuaranteeReplies, function_hook_state_NetWaitForGuaranteeReplies)
static void(__cdecl*original_NetWaitForGuaranteeReplies)() = (void(__cdecl*)())0x0044ad2f;
CARM95_HOOK_FUNCTION(original_NetWaitForGuaranteeReplies, NetWaitForGuaranteeReplies)
void __cdecl NetWaitForGuaranteeReplies() {
    tU32 start_time;
    LOG_TRACE("()");

    (void)start_time;

    if (function_hook_state_NetWaitForGuaranteeReplies == HOOK_ENABLED) {
        assert(0 && "NetWaitForGuaranteeReplies not implemented.");
        abort();
    } else {
        original_NetWaitForGuaranteeReplies();
    }
}

function_hook_state_t function_hook_state_NetPlayerFromID = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(NetPlayerFromID, function_hook_state_NetPlayerFromID)
static tNet_game_player_info *(__cdecl*original_NetPlayerFromID)(tPlayer_ID) = (tNet_game_player_info *(__cdecl*)(tPlayer_ID))0x0044ad74;
CARM95_HOOK_FUNCTION(original_NetPlayerFromID, NetPlayerFromID)
tNet_game_player_info* __cdecl NetPlayerFromID(tPlayer_ID pPlayer) {
    int i;
    LOG_TRACE("(%u)", pPlayer);

    (void)pPlayer;
    (void)i;

    if (function_hook_state_NetPlayerFromID == HOOK_ENABLED) {
        assert(0 && "NetPlayerFromID not implemented.");
        abort();
    } else {
        return original_NetPlayerFromID(pPlayer);
    }
}

function_hook_state_t function_hook_state_NetCarFromPlayerID = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(NetCarFromPlayerID, function_hook_state_NetCarFromPlayerID)
static tCar_spec *(__cdecl*original_NetCarFromPlayerID)(tPlayer_ID) = (tCar_spec *(__cdecl*)(tPlayer_ID))0x0044add4;
CARM95_HOOK_FUNCTION(original_NetCarFromPlayerID, NetCarFromPlayerID)
tCar_spec* __cdecl NetCarFromPlayerID(tPlayer_ID pPlayer) {
    int i;
    tNet_game_player_info *player;
    LOG_TRACE("(%u)", pPlayer);

    (void)pPlayer;
    (void)i;
    (void)player;

    if (function_hook_state_NetCarFromPlayerID == HOOK_ENABLED) {
        assert(0 && "NetCarFromPlayerID not implemented.");
        abort();
    } else {
        return original_NetCarFromPlayerID(pPlayer);
    }
}

function_hook_state_t function_hook_state_NetPlayerFromCar = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(NetPlayerFromCar, function_hook_state_NetPlayerFromCar)
static tNet_game_player_info *(__cdecl*original_NetPlayerFromCar)(tCar_spec *) = (tNet_game_player_info *(__cdecl*)(tCar_spec *))0x0044ae15;
CARM95_HOOK_FUNCTION(original_NetPlayerFromCar, NetPlayerFromCar)
tNet_game_player_info* __cdecl NetPlayerFromCar(tCar_spec *pCar) {
    int i;
    LOG_TRACE("(%p)", pCar);

    (void)pCar;
    (void)i;

    if (function_hook_state_NetPlayerFromCar == HOOK_ENABLED) {
        assert(0 && "NetPlayerFromCar not implemented.");
        abort();
    } else {
        return original_NetPlayerFromCar(pCar);
    }
}

function_hook_state_t function_hook_state_DoCheckSum = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(DoCheckSum, function_hook_state_DoCheckSum)
tU32 DoCheckSum(tNet_message *pMessage) {
    int i;
    int j;
    tU32 the_sum;
    tU32 *p;
    tU8 *q;
    LOG_TRACE("(%p)", pMessage);

    (void)pMessage;
    (void)i;
    (void)j;
    (void)the_sum;
    (void)p;
    (void)q;

    if (function_hook_state_DoCheckSum == HOOK_ENABLED) {
        assert(0 && "DoCheckSum not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}

function_hook_state_t function_hook_state_GetCheckSum = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(GetCheckSum, function_hook_state_GetCheckSum)
static void(__cdecl*original_GetCheckSum)(tNet_message *) = (void(__cdecl*)(tNet_message *))0x0044ae74;
CARM95_HOOK_FUNCTION(original_GetCheckSum, GetCheckSum)
void __cdecl GetCheckSum(tNet_message *pMessage) {
    LOG_TRACE("(%p)", pMessage);

    (void)pMessage;

    if (function_hook_state_GetCheckSum == HOOK_ENABLED) {
        assert(0 && "GetCheckSum not implemented.");
        abort();
    } else {
        original_GetCheckSum(pMessage);
    }
}

function_hook_state_t function_hook_state_CheckCheckSum = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(CheckCheckSum, function_hook_state_CheckCheckSum)
static void(__cdecl*original_CheckCheckSum)(tNet_message *) = (void(__cdecl*)(tNet_message *))0x0044ae7f;
CARM95_HOOK_FUNCTION(original_CheckCheckSum, CheckCheckSum)
void __cdecl CheckCheckSum(tNet_message *pMessage) {
    LOG_TRACE("(%p)", pMessage);

    (void)pMessage;

    if (function_hook_state_CheckCheckSum == HOOK_ENABLED) {
        assert(0 && "CheckCheckSum not implemented.");
        abort();
    } else {
        original_CheckCheckSum(pMessage);
    }
}

