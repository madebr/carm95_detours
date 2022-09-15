#include "network.h"

#include "harness/trace.h"

#include "carm95_hooks.h"

#include <stdio.h>
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
void(*** hookvar_gAdd_proc )(tNet_game_details *, ...) = (void*)0x00535dc0;
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

static int(*original_NetInitialise)() = (int(*)())0x004463c0;
CARM95_HOOK_FUNCTION(original_NetInitialise, NetInitialise)
int NetInitialise() {
    int i;
    LOG_TRACE("()");

    (void)i;

    return original_NetInitialise();
}

static int(*original_NetShutdown)() = (int(*)())0x0044657f;
CARM95_HOOK_FUNCTION(original_NetShutdown, NetShutdown)
int NetShutdown() {
    int err;
    int i;
    LOG_TRACE("()");

    (void)err;
    (void)i;

    return original_NetShutdown();
}

static void(*original_ShutdownNetIfRequired)() = (void(*)())0x004465d1;
CARM95_HOOK_FUNCTION(original_ShutdownNetIfRequired, ShutdownNetIfRequired)
void ShutdownNetIfRequired() {
    LOG_TRACE("()");


    original_ShutdownNetIfRequired();
}

static void(*original_DisableNetService)() = (void(*)())0x004465f8;
CARM95_HOOK_FUNCTION(original_DisableNetService, DisableNetService)
void DisableNetService() {
    LOG_TRACE("()");


    original_DisableNetService();
}

static void(*original_ReenableNetService)() = (void(*)())0x0044660d;
CARM95_HOOK_FUNCTION(original_ReenableNetService, ReenableNetService)
void ReenableNetService() {
    LOG_TRACE("()");


    original_ReenableNetService();
}

static int(*original_PermitNetServiceReentrancy)() = (int(*)())0x00446622;
CARM95_HOOK_FUNCTION(original_PermitNetServiceReentrancy, PermitNetServiceReentrancy)
int PermitNetServiceReentrancy() {
    LOG_TRACE("()");


    return original_PermitNetServiceReentrancy();
}

static void(*original_HaltNetServiceReentrancy)() = (void(*)())0x0044665a;
CARM95_HOOK_FUNCTION(original_HaltNetServiceReentrancy, HaltNetServiceReentrancy)
void HaltNetServiceReentrancy() {
    LOG_TRACE("()");


    original_HaltNetServiceReentrancy();
}

static void(*original_NetSendHeadupToAllPlayers)(char *, ...) = (void(*)(char *, ...))0x0044666f;
CARM95_HOOK_FUNCTION(original_NetSendHeadupToAllPlayers, NetSendHeadupToAllPlayers)
void NetSendHeadupToAllPlayers(char *pMessage) {
    tNet_contents *the_contents;
    LOG_TRACE("(\"%s\")", pMessage);

    (void)pMessage;
    (void)the_contents;

    original_NetSendHeadupToAllPlayers(pMessage);
}

static void(*original_NetSendHeadupToEverybody)(char *, ...) = (void(*)(char *, ...))0x004466c1;
CARM95_HOOK_FUNCTION(original_NetSendHeadupToEverybody, NetSendHeadupToEverybody)
void NetSendHeadupToEverybody(char *pMessage) {
    tNet_contents *the_contents;
    LOG_TRACE("(\"%s\")", pMessage);

    (void)pMessage;
    (void)the_contents;

    original_NetSendHeadupToEverybody(pMessage);
}

static void(*original_NetSendHeadupToPlayer)(char *, tPlayer_ID, ...) = (void(*)(char *, tPlayer_ID, ...))0x00446737;
CARM95_HOOK_FUNCTION(original_NetSendHeadupToPlayer, NetSendHeadupToPlayer)
void NetSendHeadupToPlayer(char *pMessage, tPlayer_ID pPlayer) {
    tNet_message *message;
    LOG_TRACE("(\"%s\", %u)", pMessage, pPlayer);

    (void)pMessage;
    (void)pPlayer;
    (void)message;

    original_NetSendHeadupToPlayer(pMessage, pPlayer);
}

static void(*original_InitialisePlayerStati)() = (void(*)())0x0044754e;
CARM95_HOOK_FUNCTION(original_InitialisePlayerStati, InitialisePlayerStati)
void InitialisePlayerStati() {
    int i;
    LOG_TRACE("()");

    (void)i;

    original_InitialisePlayerStati();
}

static void(*original_LeaveTempGame)() = (void(*)())0x00446847;
CARM95_HOOK_FUNCTION(original_LeaveTempGame, LeaveTempGame)
void LeaveTempGame() {
    LOG_TRACE("()");


    original_LeaveTempGame();
}

static void(*original_DisposeCurrentJoinPollGame)() = (void(*)())0x00446881;
CARM95_HOOK_FUNCTION(original_DisposeCurrentJoinPollGame, DisposeCurrentJoinPollGame)
void DisposeCurrentJoinPollGame() {
    LOG_TRACE("()");


    original_DisposeCurrentJoinPollGame();
}

static void(*original_DoNextJoinPoll)() = (void(*)())0x0044a179;
CARM95_HOOK_FUNCTION(original_DoNextJoinPoll, DoNextJoinPoll)
void DoNextJoinPoll() {
    tNet_message *the_message;
    LOG_TRACE("()");

    (void)the_message;

    original_DoNextJoinPoll();
}

static void(*original_NetStartProducingJoinList)(void(**)(tNet_game_details *, ...), ...) = (void(*)(void(**)(tNet_game_details *, ...), ...))0x004467d9;
CARM95_HOOK_FUNCTION(original_NetStartProducingJoinList, NetStartProducingJoinList)
void NetStartProducingJoinList(void(**pAdd_proc)(tNet_game_details *, ...)) {
    LOG_TRACE("(%p)", pAdd_proc);

    (void)pAdd_proc;

    original_NetStartProducingJoinList(pAdd_proc);
}

static void(*original_NetEndJoinList)() = (void(*)())0x00446823;
CARM95_HOOK_FUNCTION(original_NetEndJoinList, NetEndJoinList)
void NetEndJoinList() {
    LOG_TRACE("()");


    original_NetEndJoinList();
}

static void(*original_NetDisposePIDGameInfo)(tNet_game_details *, ...) = (void(*)(tNet_game_details *, ...))0x004468b1;
CARM95_HOOK_FUNCTION(original_NetDisposePIDGameInfo, NetDisposePIDGameInfo)
void NetDisposePIDGameInfo(tNet_game_details *pDetails) {
    LOG_TRACE("(%p)", pDetails);

    (void)pDetails;

    original_NetDisposePIDGameInfo(pDetails);
}

static void(*original_NetDisposeGameDetails)(tNet_game_details *, ...) = (void(*)(tNet_game_details *, ...))0x004468d2;
CARM95_HOOK_FUNCTION(original_NetDisposeGameDetails, NetDisposeGameDetails)
void NetDisposeGameDetails(tNet_game_details *pDetails) {
    LOG_TRACE("(%p)", pDetails);

    (void)pDetails;

    original_NetDisposeGameDetails(pDetails);
}

static tNet_game_details *(*original_NetAllocatePIDGameDetails)() = (tNet_game_details *(*)())0x0044759d;
CARM95_HOOK_FUNCTION(original_NetAllocatePIDGameDetails, NetAllocatePIDGameDetails)
tNet_game_details* NetAllocatePIDGameDetails() {
    tNet_game_details *game;
    LOG_TRACE("()");

    (void)game;

    return original_NetAllocatePIDGameDetails();
}

static void(*original_NetLeaveGameLowLevel)(tNet_game_details *, ...) = (void(*)(tNet_game_details *, ...))0x004468f3;
CARM95_HOOK_FUNCTION(original_NetLeaveGameLowLevel, NetLeaveGameLowLevel)
void NetLeaveGameLowLevel(tNet_game_details *pDetails) {
    LOG_TRACE("(%p)", pDetails);

    (void)pDetails;

    original_NetLeaveGameLowLevel(pDetails);
}

static void(*original_NetLeaveGame)(tNet_game_details *, ...) = (void(*)(tNet_game_details *, ...))0x0044692a;
CARM95_HOOK_FUNCTION(original_NetLeaveGame, NetLeaveGame)
void NetLeaveGame(tNet_game_details *pNet_game) {
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

    original_NetLeaveGame(pNet_game);
}

static void(*original_NetSetPlayerSystemInfo)(tNet_game_player_info *, void *, ...) = (void(*)(tNet_game_player_info *, void *, ...))0x00446b3b;
CARM95_HOOK_FUNCTION(original_NetSetPlayerSystemInfo, NetSetPlayerSystemInfo)
void NetSetPlayerSystemInfo(tNet_game_player_info *pPlayer, void *pSender_address) {
    LOG_TRACE("(%p, %p)", pPlayer, pSender_address);

    (void)pPlayer;
    (void)pSender_address;

    original_NetSetPlayerSystemInfo(pPlayer, pSender_address);
}

static void(*original_NetDisposePlayer)(tNet_game_player_info *, ...) = (void(*)(tNet_game_player_info *, ...))0x00446b56;
CARM95_HOOK_FUNCTION(original_NetDisposePlayer, NetDisposePlayer)
void NetDisposePlayer(tNet_game_player_info *pPlayer) {
    LOG_TRACE("(%p)", pPlayer);

    (void)pPlayer;

    original_NetDisposePlayer(pPlayer);
}

static void(*original_FillInThisPlayer)(tNet_game_details *, tNet_game_player_info *, int, int, ...) = (void(*)(tNet_game_details *, tNet_game_player_info *, int, int, ...))0x004475c5;
CARM95_HOOK_FUNCTION(original_FillInThisPlayer, FillInThisPlayer)
void FillInThisPlayer(tNet_game_details *pGame, tNet_game_player_info *pPlayer, int pCar_index, int pHost) {
    LOG_TRACE("(%p, %p, %d, %d)", pGame, pPlayer, pCar_index, pHost);

    (void)pGame;
    (void)pPlayer;
    (void)pCar_index;
    (void)pHost;

    original_FillInThisPlayer(pGame, pPlayer, pCar_index, pHost);
}

static void(*original_LoadCarN)(int, tNet_game_player_info *, ...) = (void(*)(int, tNet_game_player_info *, ...))0x0044725a;
CARM95_HOOK_FUNCTION(original_LoadCarN, LoadCarN)
void LoadCarN(int pIndex, tNet_game_player_info *pPlayer) {
    int switched_res;
    LOG_TRACE("(%d, %p)", pIndex, pPlayer);

    (void)pIndex;
    (void)pPlayer;
    (void)switched_res;

    original_LoadCarN(pIndex, pPlayer);
}

static void(*original_DisposeCarN)(int, ...) = (void(*)(int, ...))0x00446b6d;
CARM95_HOOK_FUNCTION(original_DisposeCarN, DisposeCarN)
void DisposeCarN(int pIndex) {
    int i;
    int j;
    LOG_TRACE("(%d)", pIndex);

    (void)pIndex;
    (void)i;
    (void)j;

    original_DisposeCarN(pIndex);
}

static void(*original_PlayerHasLeft)(int, ...) = (void(*)(int, ...))0x0044731b;
CARM95_HOOK_FUNCTION(original_PlayerHasLeft, PlayerHasLeft)
void PlayerHasLeft(int pIndex) {
    LOG_TRACE("(%d)", pIndex);

    (void)pIndex;

    original_PlayerHasLeft(pIndex);
}

static void(*original_NetPlayersChanged)(int, tNet_game_player_info *, ...) = (void(*)(int, tNet_game_player_info *, ...))0x00446ca1;
CARM95_HOOK_FUNCTION(original_NetPlayersChanged, NetPlayersChanged)
void NetPlayersChanged(int pNew_count, tNet_game_player_info *pNew_players) {
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

    original_NetPlayersChanged(pNew_count, pNew_players);
}

static tNet_game_details *(*original_NetHostGame)(tNet_game_type, tNet_game_options *, int, char *, int, ...) = (tNet_game_details *(*)(tNet_game_type, tNet_game_options *, int, char *, int, ...))0x004473b1;
CARM95_HOOK_FUNCTION(original_NetHostGame, NetHostGame)
tNet_game_details* NetHostGame(tNet_game_type pGame_type, tNet_game_options *pOptions, int pStart_rank, char *pHost_name, int pCar_index) {
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

    return original_NetHostGame(pGame_type, pOptions, pStart_rank, pHost_name, pCar_index);
}

static int(*original_NetInitClient)(tNet_game_details *, ...) = (int(*)(tNet_game_details *, ...))0x004476bd;
CARM95_HOOK_FUNCTION(original_NetInitClient, NetInitClient)
int NetInitClient(tNet_game_details *pDetails) {
    LOG_TRACE("(%p)", pDetails);

    (void)pDetails;

    return original_NetInitClient(pDetails);
}

static int(*original_NetJoinGameLowLevel)(tNet_game_details *, char *, ...) = (int(*)(tNet_game_details *, char *, ...))0x00447883;
CARM95_HOOK_FUNCTION(original_NetJoinGameLowLevel, NetJoinGameLowLevel)
int NetJoinGameLowLevel(tNet_game_details *pDetails, char *pPlayer_name) {
    LOG_TRACE("(%p, \"%s\")", pDetails, pPlayer_name);

    (void)pDetails;
    (void)pPlayer_name;

    return original_NetJoinGameLowLevel(pDetails, pPlayer_name);
}

static int(*original_NetJoinGame)(tNet_game_details *, char *, int, ...) = (int(*)(tNet_game_details *, char *, int, ...))0x004476d9;
CARM95_HOOK_FUNCTION(original_NetJoinGame, NetJoinGame)
int NetJoinGame(tNet_game_details *pDetails, char *pPlayer_name, int pCar_index) {
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

    return original_NetJoinGame(pDetails, pPlayer_name, pCar_index);
}

static void(*original_NetObtainSystemUserName)(char *, int, ...) = (void(*)(char *, int, ...))0x004478a3;
CARM95_HOOK_FUNCTION(original_NetObtainSystemUserName, NetObtainSystemUserName)
void NetObtainSystemUserName(char *pName, int pMax_length) {
    LOG_TRACE("(\"%s\", %d)", pName, pMax_length);

    (void)pName;
    (void)pMax_length;

    original_NetObtainSystemUserName(pName, pMax_length);
}

static tU32(*original_NetExtractGameID)(tNet_game_details *, ...) = (tU32(*)(tNet_game_details *, ...))0x004478c5;
CARM95_HOOK_FUNCTION(original_NetExtractGameID, NetExtractGameID)
tU32 NetExtractGameID(tNet_game_details *pDetails) {
    LOG_TRACE("(%p)", pDetails);

    (void)pDetails;

    return original_NetExtractGameID(pDetails);
}

static tPlayer_ID(*original_NetExtractPlayerID)(tNet_game_details *, ...) = (tPlayer_ID(*)(tNet_game_details *, ...))0x004478e1;
CARM95_HOOK_FUNCTION(original_NetExtractPlayerID, NetExtractPlayerID)
tPlayer_ID NetExtractPlayerID(tNet_game_details *pDetails) {
    LOG_TRACE("(%p)", pDetails);

    (void)pDetails;

    return original_NetExtractPlayerID(pDetails);
}

static int(*original_NetSendMessageToAddress)(tNet_game_details *, tNet_message *, void *, ...) = (int(*)(tNet_game_details *, tNet_message *, void *, ...))0x004478fd;
CARM95_HOOK_FUNCTION(original_NetSendMessageToAddress, NetSendMessageToAddress)
int NetSendMessageToAddress(tNet_game_details *pDetails, tNet_message *pMessage, void *pAddress) {
    LOG_TRACE("(%p, %p, %p)", pDetails, pMessage, pAddress);

    (void)pDetails;
    (void)pMessage;
    (void)pAddress;

    return original_NetSendMessageToAddress(pDetails, pMessage, pAddress);
}

static int(*original_NetSendMessageToPlayer)(tNet_game_details *, tNet_message *, tPlayer_ID, ...) = (int(*)(tNet_game_details *, tNet_message *, tPlayer_ID, ...))0x0044796c;
CARM95_HOOK_FUNCTION(original_NetSendMessageToPlayer, NetSendMessageToPlayer)
int NetSendMessageToPlayer(tNet_game_details *pDetails, tNet_message *pMessage, tPlayer_ID pPlayer) {
    int i;
    LOG_TRACE("(%p, %p, %u)", pDetails, pMessage, pPlayer);

    (void)pDetails;
    (void)pMessage;
    (void)pPlayer;
    (void)i;

    return original_NetSendMessageToPlayer(pDetails, pMessage, pPlayer);
}

static int(*original_NetSendMessageToHost)(tNet_game_details *, tNet_message *, ...) = (int(*)(tNet_game_details *, tNet_message *, ...))0x00447a10;
CARM95_HOOK_FUNCTION(original_NetSendMessageToHost, NetSendMessageToHost)
int NetSendMessageToHost(tNet_game_details *pDetails, tNet_message *pMessage) {
    LOG_TRACE("(%p, %p)", pDetails, pMessage);

    (void)pDetails;
    (void)pMessage;

    return original_NetSendMessageToHost(pDetails, pMessage);
}

static int(*original_NetReplyToMessage)(tNet_game_details *, tNet_message *, tNet_message *, ...) = (int(*)(tNet_game_details *, tNet_message *, tNet_message *, ...))0x00447a72;
CARM95_HOOK_FUNCTION(original_NetReplyToMessage, NetReplyToMessage)
int NetReplyToMessage(tNet_game_details *pDetails, tNet_message *pIncoming_message, tNet_message *pReply_message) {
    LOG_TRACE("(%p, %p, %p)", pDetails, pIncoming_message, pReply_message);

    (void)pDetails;
    (void)pIncoming_message;
    (void)pReply_message;

    return original_NetReplyToMessage(pDetails, pIncoming_message, pReply_message);
}

static int(*original_NetSendMessageToAllPlayers)(tNet_game_details *, tNet_message *, ...) = (int(*)(tNet_game_details *, tNet_message *, ...))0x00447a99;
CARM95_HOOK_FUNCTION(original_NetSendMessageToAllPlayers, NetSendMessageToAllPlayers)
int NetSendMessageToAllPlayers(tNet_game_details *pDetails, tNet_message *pMessage) {
    LOG_TRACE("(%p, %p)", pDetails, pMessage);

    (void)pDetails;
    (void)pMessage;

    return original_NetSendMessageToAllPlayers(pDetails, pMessage);
}

static tU32(*original_NetGetContentsSize)(tNet_message_type, tS32, ...) = (tU32(*)(tNet_message_type, tS32, ...))0x00447adb;
CARM95_HOOK_FUNCTION(original_NetGetContentsSize, NetGetContentsSize)
tU32 NetGetContentsSize(tNet_message_type pType, tS32 pSize_decider) {
    tU32 the_size;
    char __block0__s[256];
    LOG_TRACE("(%u, %d)", pType, pSize_decider);

    (void)pType;
    (void)pSize_decider;
    (void)the_size;

    return original_NetGetContentsSize(pType, pSize_decider);
}

static tU32(*original_NetGetMessageSize)(tNet_message_type, tS32, ...) = (tU32(*)(tNet_message_type, tS32, ...))0x00447dd9;
CARM95_HOOK_FUNCTION(original_NetGetMessageSize, NetGetMessageSize)
tU32 NetGetMessageSize(tNet_message_type pType, tS32 pSize_decider) {
    LOG_TRACE("(%u, %d)", pType, pSize_decider);

    (void)pType;
    (void)pSize_decider;

    return original_NetGetMessageSize(pType, pSize_decider);
}

static tS32(*original_NetCalcSizeDecider)(tNet_contents *, ...) = (tS32(*)(tNet_contents *, ...))0x00447dfc;
CARM95_HOOK_FUNCTION(original_NetCalcSizeDecider, NetCalcSizeDecider)
tS32 NetCalcSizeDecider(tNet_contents *pContents) {
    tS32 the_decider;
    LOG_TRACE("(%p)", pContents);

    (void)pContents;
    (void)the_decider;

    return original_NetCalcSizeDecider(pContents);
}

static tNet_message *(*original_NetBuildMessage)(tNet_message_type, tS32, ...) = (tNet_message *(*)(tNet_message_type, tS32, ...))0x00447e7f;
CARM95_HOOK_FUNCTION(original_NetBuildMessage, NetBuildMessage)
tNet_message* NetBuildMessage(tNet_message_type pType, tS32 pSize_decider) {
    tNet_message *the_message;
    tU32 the_size;
    LOG_TRACE("(%u, %d)", pType, pSize_decider);

    (void)pType;
    (void)pSize_decider;
    (void)the_message;
    (void)the_size;

    return original_NetBuildMessage(pType, pSize_decider);
}

static tNet_contents *(*original_NetGetToHostContents)(tNet_message_type, tS32, ...) = (tNet_contents *(*)(tNet_message_type, tS32, ...))0x00447ee4;
CARM95_HOOK_FUNCTION(original_NetGetToHostContents, NetGetToHostContents)
tNet_contents* NetGetToHostContents(tNet_message_type pType, tS32 pSize_decider) {
    tU32 the_size;
    tNet_contents *contents;
    LOG_TRACE("(%u, %d)", pType, pSize_decider);

    (void)pType;
    (void)pSize_decider;
    (void)the_size;
    (void)contents;

    return original_NetGetToHostContents(pType, pSize_decider);
}

static tNet_contents *(*original_NetGetBroadcastContents)(tNet_message_type, tS32, ...) = (tNet_contents *(*)(tNet_message_type, tS32, ...))0x00447fcc;
CARM95_HOOK_FUNCTION(original_NetGetBroadcastContents, NetGetBroadcastContents)
tNet_contents* NetGetBroadcastContents(tNet_message_type pType, tS32 pSize_decider) {
    tU32 the_size;
    tNet_contents *contents;
    LOG_TRACE("(%u, %d)", pType, pSize_decider);

    (void)pType;
    (void)pSize_decider;
    (void)the_size;
    (void)contents;

    return original_NetGetBroadcastContents(pType, pSize_decider);
}

static void(*original_NetSendMessageStacks)() = (void(*)())0x004480b4;
CARM95_HOOK_FUNCTION(original_NetSendMessageStacks, NetSendMessageStacks)
void NetSendMessageStacks() {
    LOG_TRACE("()");


    original_NetSendMessageStacks();
}

static tNet_message *(*original_NetAllocateMessage)(int, ...) = (tNet_message *(*)(int, ...))0x0044811f;
CARM95_HOOK_FUNCTION(original_NetAllocateMessage, NetAllocateMessage)
tNet_message* NetAllocateMessage(int pSize) {
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

    return original_NetAllocateMessage(pSize);
}

static void(*original_NetFreeExcessMemory)() = (void(*)())0x004483eb;
CARM95_HOOK_FUNCTION(original_NetFreeExcessMemory, NetFreeExcessMemory)
void NetFreeExcessMemory() {
    void *temp;
    LOG_TRACE("()");

    (void)temp;

    original_NetFreeExcessMemory();
}

static int(*original_NetDisposeMessage)(tNet_game_details *, tNet_message *, ...) = (int(*)(tNet_game_details *, tNet_message *, ...))0x00448445;
CARM95_HOOK_FUNCTION(original_NetDisposeMessage, NetDisposeMessage)
int NetDisposeMessage(tNet_game_details *pDetails, tNet_message *pMessage) {
    LOG_TRACE("(%p, %p)", pDetails, pMessage);

    (void)pDetails;
    (void)pMessage;

    return original_NetDisposeMessage(pDetails, pMessage);
}

static tNet_message *(*original_NetGetNextMessage)(tNet_game_details *, void **, ...) = (tNet_message *(*)(tNet_game_details *, void **, ...))0x00448475;
CARM95_HOOK_FUNCTION(original_NetGetNextMessage, NetGetNextMessage)
tNet_message* NetGetNextMessage(tNet_game_details *pDetails, void **pSender_address) {
    LOG_TRACE("(%p, %p)", pDetails, pSender_address);

    (void)pDetails;
    (void)pSender_address;

    return original_NetGetNextMessage(pDetails, pSender_address);
}

static void(*original_ReceivedSendMeDetails)(tNet_contents *, void *, ...) = (void(*)(tNet_contents *, void *, ...))0x0044929e;
CARM95_HOOK_FUNCTION(original_ReceivedSendMeDetails, ReceivedSendMeDetails)
void ReceivedSendMeDetails(tNet_contents *pContents, void *pSender_address) {
    tNet_message *message;
    LOG_TRACE("(%p, %p)", pContents, pSender_address);

    (void)pContents;
    (void)pSender_address;
    (void)message;

    original_ReceivedSendMeDetails(pContents, pSender_address);
}

static void(*original_ReceivedDetails)(tNet_contents *, ...) = (void(*)(tNet_contents *, ...))0x004492f6;
CARM95_HOOK_FUNCTION(original_ReceivedDetails, ReceivedDetails)
void ReceivedDetails(tNet_contents *pContents) {
    LOG_TRACE("(%p)", pContents);

    (void)pContents;

    original_ReceivedDetails(pContents);
}

static void(*original_SendOutPlayerList)() = (void(*)())0x004495e0;
CARM95_HOOK_FUNCTION(original_SendOutPlayerList, SendOutPlayerList)
void SendOutPlayerList() {
    tNet_message *message;
    int i;
    LOG_TRACE("()");

    (void)message;
    (void)i;

    original_SendOutPlayerList();
}

static void(*original_ReceivedJoin)(tNet_contents *, void *, ...) = (void(*)(tNet_contents *, void *, ...))0x00449330;
CARM95_HOOK_FUNCTION(original_ReceivedJoin, ReceivedJoin)
void ReceivedJoin(tNet_contents *pContents, void *pSender_address) {
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

    original_ReceivedJoin(pContents, pSender_address);
}

static void(*original_KickPlayerOut)(tPlayer_ID, ...) = (void(*)(tPlayer_ID, ...))0x004496f8;
CARM95_HOOK_FUNCTION(original_KickPlayerOut, KickPlayerOut)
void KickPlayerOut(tPlayer_ID pID) {
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

    original_KickPlayerOut(pID);
}

static void(*original_ReceivedLeave)(tNet_contents *, tNet_message *, ...) = (void(*)(tNet_contents *, tNet_message *, ...))0x004496de;
CARM95_HOOK_FUNCTION(original_ReceivedLeave, ReceivedLeave)
void ReceivedLeave(tNet_contents *pContents, tNet_message *pMessage) {
    LOG_TRACE("(%p, %p)", pContents, pMessage);

    (void)pContents;
    (void)pMessage;

    original_ReceivedLeave(pContents, pMessage);
}

static void(*original_NetFullScreenMessage)(int, int, ...) = (void(*)(int, int, ...))0x00448495;
CARM95_HOOK_FUNCTION(original_NetFullScreenMessage, NetFullScreenMessage)
void NetFullScreenMessage(int pStr_index, int pLeave_it_up_there) {
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

    original_NetFullScreenMessage(pStr_index, pLeave_it_up_there);
}

static void(*original_HostHasBittenTheDust)(int, ...) = (void(*)(int, ...))0x0044989e;
CARM95_HOOK_FUNCTION(original_HostHasBittenTheDust, HostHasBittenTheDust)
void HostHasBittenTheDust(int pMessage_index) {
    LOG_TRACE("(%d)", pMessage_index);

    (void)pMessage_index;

    original_HostHasBittenTheDust(pMessage_index);
}

static void(*original_ReceivedHosticide)(tNet_contents *, ...) = (void(*)(tNet_contents *, ...))0x00449889;
CARM95_HOOK_FUNCTION(original_ReceivedHosticide, ReceivedHosticide)
void ReceivedHosticide(tNet_contents *pContents) {
    LOG_TRACE("(%p)", pContents);

    (void)pContents;

    original_ReceivedHosticide(pContents);
}

void ConfirmReceipt() {
    tNet_message *the_message;
    LOG_TRACE("()");

    (void)the_message;

    NOT_IMPLEMENTED();
}

static void(*original_ReceivedNewPlayerList)(tNet_contents *, tNet_message *, ...) = (void(*)(tNet_contents *, tNet_message *, ...))0x004498d8;
CARM95_HOOK_FUNCTION(original_ReceivedNewPlayerList, ReceivedNewPlayerList)
void ReceivedNewPlayerList(tNet_contents *pContents, tNet_message *pM) {
    int i;
    LOG_TRACE("(%p, %p)", pContents, pM);

    (void)pContents;
    (void)pM;
    (void)i;

    original_ReceivedNewPlayerList(pContents, pM);
}

static void(*original_ReceivedRaceOver)(tNet_contents *, ...) = (void(*)(tNet_contents *, ...))0x00449afb;
CARM95_HOOK_FUNCTION(original_ReceivedRaceOver, ReceivedRaceOver)
void ReceivedRaceOver(tNet_contents *pContents) {
    LOG_TRACE("(%p)", pContents);

    (void)pContents;

    original_ReceivedRaceOver(pContents);
}

static void(*original_ReceivedStatusReport)(tNet_contents *, tNet_message *, ...) = (void(*)(tNet_contents *, tNet_message *, ...))0x00449b46;
CARM95_HOOK_FUNCTION(original_ReceivedStatusReport, ReceivedStatusReport)
void ReceivedStatusReport(tNet_contents *pContents, tNet_message *pMessage) {
    int i;
    LOG_TRACE("(%p, %p)", pContents, pMessage);

    (void)pContents;
    (void)pMessage;
    (void)i;

    original_ReceivedStatusReport(pContents, pMessage);
}

static void(*original_ReceivedStartRace)(tNet_contents *, ...) = (void(*)(tNet_contents *, ...))0x00449c42;
CARM95_HOOK_FUNCTION(original_ReceivedStartRace, ReceivedStartRace)
void ReceivedStartRace(tNet_contents *pContents) {
    int i;
    int index;
    LOG_TRACE("(%p)", pContents);

    (void)pContents;
    (void)i;
    (void)index;

    original_ReceivedStartRace(pContents);
}

static void(*original_ReceivedGuaranteeReply)(tNet_contents *, ...) = (void(*)(tNet_contents *, ...))0x00448695;
CARM95_HOOK_FUNCTION(original_ReceivedGuaranteeReply, ReceivedGuaranteeReply)
void ReceivedGuaranteeReply(tNet_contents *pContents) {
    int i;
    LOG_TRACE("(%p)", pContents);

    (void)pContents;
    (void)i;

    original_ReceivedGuaranteeReply(pContents);
}

static void(*original_ReceivedHeadup)(tNet_contents *, ...) = (void(*)(tNet_contents *, ...))0x004486fb;
CARM95_HOOK_FUNCTION(original_ReceivedHeadup, ReceivedHeadup)
void ReceivedHeadup(tNet_contents *pContents) {
    LOG_TRACE("(%p)", pContents);

    (void)pContents;

    original_ReceivedHeadup(pContents);
}

static void(*original_ReceivedHostQuery)(tNet_contents *, tNet_message *, ...) = (void(*)(tNet_contents *, tNet_message *, ...))0x0044872d;
CARM95_HOOK_FUNCTION(original_ReceivedHostQuery, ReceivedHostQuery)
void ReceivedHostQuery(tNet_contents *pContents, tNet_message *pMessage) {
    tNet_message *message;
    LOG_TRACE("(%p, %p)", pContents, pMessage);

    (void)pContents;
    (void)pMessage;
    (void)message;

    original_ReceivedHostQuery(pContents, pMessage);
}

static void(*original_ReceivedHostReply)(tNet_contents *, ...) = (void(*)(tNet_contents *, ...))0x0044879d;
CARM95_HOOK_FUNCTION(original_ReceivedHostReply, ReceivedHostReply)
void ReceivedHostReply(tNet_contents *pContents) {
    tNet_message *message;
    LOG_TRACE("(%p)", pContents);

    (void)pContents;
    (void)message;

    original_ReceivedHostReply(pContents);
}

static void(*original_SendGuaranteeReply)(tNet_message *, void *, ...) = (void(*)(tNet_message *, void *, ...))0x0044882b;
CARM95_HOOK_FUNCTION(original_SendGuaranteeReply, SendGuaranteeReply)
void SendGuaranteeReply(tNet_message *pMessage, void *pSender_address) {
    tNet_message *message;
    LOG_TRACE("(%p, %p)", pMessage, pSender_address);

    (void)pMessage;
    (void)pSender_address;
    (void)message;

    original_SendGuaranteeReply(pMessage, pSender_address);
}

static int(*original_PlayerIsInList)(tPlayer_ID, ...) = (int(*)(tPlayer_ID, ...))0x00449f18;
CARM95_HOOK_FUNCTION(original_PlayerIsInList, PlayerIsInList)
int PlayerIsInList(tPlayer_ID pID) {
    int i;
    LOG_TRACE("(%u)", pID);

    (void)pID;
    (void)i;

    return original_PlayerIsInList(pID);
}

static void(*original_ReceivedTimeSync)(tNet_contents *, tNet_message *, tU32, ...) = (void(*)(tNet_contents *, tNet_message *, tU32, ...))0x00448874;
CARM95_HOOK_FUNCTION(original_ReceivedTimeSync, ReceivedTimeSync)
void ReceivedTimeSync(tNet_contents *pContents, tNet_message *pMessage, tU32 pReceive_time) {
    LOG_TRACE("(%p, %p, %u)", pContents, pMessage, pReceive_time);

    (void)pContents;
    (void)pMessage;
    (void)pReceive_time;

    original_ReceivedTimeSync(pContents, pMessage, pReceive_time);
}

static void(*original_ReceivedConfirm)(tNet_contents *, ...) = (void(*)(tNet_contents *, ...))0x004488b4;
CARM95_HOOK_FUNCTION(original_ReceivedConfirm, ReceivedConfirm)
void ReceivedConfirm(tNet_contents *pContents) {
    int i;
    LOG_TRACE("(%p)", pContents);

    (void)pContents;
    (void)i;

    original_ReceivedConfirm(pContents);
}

static void(*original_ReceivedDisableCar)(tNet_contents *, ...) = (void(*)(tNet_contents *, ...))0x00448914;
CARM95_HOOK_FUNCTION(original_ReceivedDisableCar, ReceivedDisableCar)
void ReceivedDisableCar(tNet_contents *pContents) {
    LOG_TRACE("(%p)", pContents);

    (void)pContents;

    original_ReceivedDisableCar(pContents);
}

static void(*original_ReceivedEnableCar)(tNet_contents *, ...) = (void(*)(tNet_contents *, ...))0x0044891f;
CARM95_HOOK_FUNCTION(original_ReceivedEnableCar, ReceivedEnableCar)
void ReceivedEnableCar(tNet_contents *pContents) {
    LOG_TRACE("(%p)", pContents);

    (void)pContents;

    original_ReceivedEnableCar(pContents);
}

static void(*original_ReceivedScores)(tNet_contents *, ...) = (void(*)(tNet_contents *, ...))0x0044892a;
CARM95_HOOK_FUNCTION(original_ReceivedScores, ReceivedScores)
void ReceivedScores(tNet_contents *pContents) {
    int i;
    LOG_TRACE("(%p)", pContents);

    (void)pContents;
    (void)i;

    original_ReceivedScores(pContents);
}

static void(*original_ReceivedWasted)(tNet_contents *, ...) = (void(*)(tNet_contents *, ...))0x00448981;
CARM95_HOOK_FUNCTION(original_ReceivedWasted, ReceivedWasted)
void ReceivedWasted(tNet_contents *pContents) {
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

    original_ReceivedWasted(pContents);
}

static void(*original_ReceivedCarDetailsReq)(tNet_contents *, void *, ...) = (void(*)(tNet_contents *, void *, ...))0x00448ca9;
CARM95_HOOK_FUNCTION(original_ReceivedCarDetailsReq, ReceivedCarDetailsReq)
void ReceivedCarDetailsReq(tNet_contents *pContents, void *pSender_address) {
    tNet_message *message;
    int i;
    LOG_TRACE("(%p, %p)", pContents, pSender_address);

    (void)pContents;
    (void)pSender_address;
    (void)message;
    (void)i;

    original_ReceivedCarDetailsReq(pContents, pSender_address);
}

static void(*original_ReceivedCarDetails)(tNet_contents *, ...) = (void(*)(tNet_contents *, ...))0x00448d70;
CARM95_HOOK_FUNCTION(original_ReceivedCarDetails, ReceivedCarDetails)
void ReceivedCarDetails(tNet_contents *pContents) {
    int i;
    int j;
    LOG_TRACE("(%p)", pContents);

    (void)pContents;
    (void)i;
    (void)j;

    original_ReceivedCarDetails(pContents);
}

static void(*original_ReceivedGameScores)(tNet_contents *, ...) = (void(*)(tNet_contents *, ...))0x00448e41;
CARM95_HOOK_FUNCTION(original_ReceivedGameScores, ReceivedGameScores)
void ReceivedGameScores(tNet_contents *pContents) {
    int i;
    LOG_TRACE("(%p)", pContents);

    (void)pContents;
    (void)i;

    original_ReceivedGameScores(pContents);
}

static void(*original_ReceivedMessage)(tNet_message *, void *, tU32, ...) = (void(*)(tNet_message *, void *, tU32, ...))0x00448eca;
CARM95_HOOK_FUNCTION(original_ReceivedMessage, ReceivedMessage)
void ReceivedMessage(tNet_message *pMessage, void *pSender_address, tU32 pReceive_time) {
    tNet_contents *contents;
    int i;
    LOG_TRACE("(%p, %p, %u)", pMessage, pSender_address, pReceive_time);

    (void)pMessage;
    (void)pSender_address;
    (void)pReceive_time;
    (void)contents;
    (void)i;

    original_ReceivedMessage(pMessage, pSender_address, pReceive_time);
}

static void(*original_NetReceiveAndProcessMessages)() = (void(*)())0x00449f82;
CARM95_HOOK_FUNCTION(original_NetReceiveAndProcessMessages, NetReceiveAndProcessMessages)
void NetReceiveAndProcessMessages() {
    tNet_message *message;
    void *sender_address;
    tU32 receive_time;
    int old_net_service;
    LOG_TRACE("()");

    (void)message;
    (void)sender_address;
    (void)receive_time;
    (void)old_net_service;

    original_NetReceiveAndProcessMessages();
}

static void(*original_BroadcastStatus)() = (void(*)())0x0044a046;
CARM95_HOOK_FUNCTION(original_BroadcastStatus, BroadcastStatus)
void BroadcastStatus() {
    tNet_message *message;
    LOG_TRACE("()");

    (void)message;

    original_BroadcastStatus();
}

static void(*original_CheckForDisappearees)() = (void(*)())0x0044a2a3;
CARM95_HOOK_FUNCTION(original_CheckForDisappearees, CheckForDisappearees)
void CheckForDisappearees() {
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

    original_CheckForDisappearees();
}

static void(*original_CheckForPendingStartRace)() = (void(*)())0x0044a478;
CARM95_HOOK_FUNCTION(original_CheckForPendingStartRace, CheckForPendingStartRace)
void CheckForPendingStartRace() {
    int i;
    LOG_TRACE("()");

    (void)i;

    original_CheckForPendingStartRace();
}

static void(*original_NetService)(int, ...) = (void(*)(int, ...))0x0044a08a;
CARM95_HOOK_FUNCTION(original_NetService, NetService)
void NetService(int pIn_race) {
    tU32 time;
    static tU32 last_status_broadcast;
    LOG_TRACE("(%d)", pIn_race);

    (void)pIn_race;
    (void)time;
    (void)last_status_broadcast;

    original_NetService(pIn_race);
}

static void(*original_NetFinishRace)(tNet_game_details *, tRace_over_reason, ...) = (void(*)(tNet_game_details *, tRace_over_reason, ...))0x0044a4e1;
CARM95_HOOK_FUNCTION(original_NetFinishRace, NetFinishRace)
void NetFinishRace(tNet_game_details *pDetails, tRace_over_reason pReason) {
    tNet_message *the_message;
    LOG_TRACE("(%p, %d)", pDetails, pReason);

    (void)pDetails;
    (void)pReason;
    (void)the_message;

    original_NetFinishRace(pDetails, pReason);
}

static void(*original_NetPlayerStatusChanged)(tPlayer_status, ...) = (void(*)(tPlayer_status, ...))0x0044a525;
CARM95_HOOK_FUNCTION(original_NetPlayerStatusChanged, NetPlayerStatusChanged)
void NetPlayerStatusChanged(tPlayer_status pNew_status) {
    LOG_TRACE("(%d)", pNew_status);

    (void)pNew_status;

    original_NetPlayerStatusChanged(pNew_status);
}

static tPlayer_status(*original_NetGetPlayerStatus)() = (tPlayer_status(*)())0x0044a5d0;
CARM95_HOOK_FUNCTION(original_NetGetPlayerStatus, NetGetPlayerStatus)
tPlayer_status NetGetPlayerStatus() {
    LOG_TRACE("()");


    return original_NetGetPlayerStatus();
}

static int(*original_NetGuaranteedSendMessageToAllPlayers)(tNet_game_details *, tNet_message *, int(**)(tU32, tNet_message *, ...), ...) = (int(*)(tNet_game_details *, tNet_message *, int(**)(tU32, tNet_message *, ...), ...))0x0044a5ef;
CARM95_HOOK_FUNCTION(original_NetGuaranteedSendMessageToAllPlayers, NetGuaranteedSendMessageToAllPlayers)
int NetGuaranteedSendMessageToAllPlayers(tNet_game_details *pDetails, tNet_message *pMessage, int(**pNotifyFail)(tU32, tNet_message *, ...)) {
    int i;
    int err;
    LOG_TRACE("(%p, %p, %p)", pDetails, pMessage, pNotifyFail);

    (void)pDetails;
    (void)pMessage;
    (void)pNotifyFail;
    (void)i;
    (void)err;

    return original_NetGuaranteedSendMessageToAllPlayers(pDetails, pMessage, pNotifyFail);
}

static int(*original_NetGuaranteedSendMessageToEverybody)(tNet_game_details *, tNet_message *, int(**)(tU32, tNet_message *, ...), ...) = (int(*)(tNet_game_details *, tNet_message *, int(**)(tU32, tNet_message *, ...), ...))0x0044a689;
CARM95_HOOK_FUNCTION(original_NetGuaranteedSendMessageToEverybody, NetGuaranteedSendMessageToEverybody)
int NetGuaranteedSendMessageToEverybody(tNet_game_details *pDetails, tNet_message *pMessage, int(**pNotifyFail)(tU32, tNet_message *, ...)) {
    LOG_TRACE("(%p, %p, %p)", pDetails, pMessage, pNotifyFail);

    (void)pDetails;
    (void)pMessage;
    (void)pNotifyFail;

    return original_NetGuaranteedSendMessageToEverybody(pDetails, pMessage, pNotifyFail);
}

static int(*original_NetGuaranteedSendMessageToHost)(tNet_game_details *, tNet_message *, int(**)(tU32, tNet_message *, ...), ...) = (int(*)(tNet_game_details *, tNet_message *, int(**)(tU32, tNet_message *, ...), ...))0x0044a6f9;
CARM95_HOOK_FUNCTION(original_NetGuaranteedSendMessageToHost, NetGuaranteedSendMessageToHost)
int NetGuaranteedSendMessageToHost(tNet_game_details *pDetails, tNet_message *pMessage, int(**pNotifyFail)(tU32, tNet_message *, ...)) {
    LOG_TRACE("(%p, %p, %p)", pDetails, pMessage, pNotifyFail);

    (void)pDetails;
    (void)pMessage;
    (void)pNotifyFail;

    return original_NetGuaranteedSendMessageToHost(pDetails, pMessage, pNotifyFail);
}

static int(*original_NetGuaranteedSendMessageToPlayer)(tNet_game_details *, tNet_message *, tPlayer_ID, int(**)(tU32, tNet_message *, ...), ...) = (int(*)(tNet_game_details *, tNet_message *, tPlayer_ID, int(**)(tU32, tNet_message *, ...), ...))0x0044a721;
CARM95_HOOK_FUNCTION(original_NetGuaranteedSendMessageToPlayer, NetGuaranteedSendMessageToPlayer)
int NetGuaranteedSendMessageToPlayer(tNet_game_details *pDetails, tNet_message *pMessage, tPlayer_ID pPlayer, int(**pNotifyFail)(tU32, tNet_message *, ...)) {
    int i;
    LOG_TRACE("(%p, %p, %u, %p)", pDetails, pMessage, pPlayer, pNotifyFail);

    (void)pDetails;
    (void)pMessage;
    (void)pPlayer;
    (void)pNotifyFail;
    (void)i;

    return original_NetGuaranteedSendMessageToPlayer(pDetails, pMessage, pPlayer, pNotifyFail);
}

static int(*original_NetGuaranteedSendMessageToAddress)(tNet_game_details *, tNet_message *, void *, int(**)(tU32, tNet_message *, ...), ...) = (int(*)(tNet_game_details *, tNet_message *, void *, int(**)(tU32, tNet_message *, ...), ...))0x0044a80f;
CARM95_HOOK_FUNCTION(original_NetGuaranteedSendMessageToAddress, NetGuaranteedSendMessageToAddress)
int NetGuaranteedSendMessageToAddress(tNet_game_details *pDetails, tNet_message *pMessage, void *pAddress, int(**pNotifyFail)(tU32, tNet_message *, ...)) {
    char __block0__s[256];
    LOG_TRACE("(%p, %p, %p, %p)", pDetails, pMessage, pAddress, pNotifyFail);

    (void)pDetails;
    (void)pMessage;
    (void)pAddress;
    (void)pNotifyFail;

    return original_NetGuaranteedSendMessageToAddress(pDetails, pMessage, pAddress, pNotifyFail);
}

static void(*original_ResendGuaranteedMessages)() = (void(*)())0x0044a9f1;
CARM95_HOOK_FUNCTION(original_ResendGuaranteedMessages, ResendGuaranteedMessages)
void ResendGuaranteedMessages() {
    int i;
    int j;
    tU32 time;
    LOG_TRACE("()");

    (void)i;
    (void)j;
    (void)time;

    original_ResendGuaranteedMessages();
}

static int(*original_SampleFailNotifier)(tU32, tNet_message *, ...) = (int(*)(tU32, tNet_message *, ...))0x0044ad06;
CARM95_HOOK_FUNCTION(original_SampleFailNotifier, SampleFailNotifier)
int SampleFailNotifier(tU32 pAge, tNet_message *pMessage) {
    LOG_TRACE("(%u, %p)", pAge, pMessage);

    (void)pAge;
    (void)pMessage;

    return original_SampleFailNotifier(pAge, pMessage);
}

static void(*original_NetWaitForGuaranteeReplies)() = (void(*)())0x0044ad2f;
CARM95_HOOK_FUNCTION(original_NetWaitForGuaranteeReplies, NetWaitForGuaranteeReplies)
void NetWaitForGuaranteeReplies() {
    tU32 start_time;
    LOG_TRACE("()");

    (void)start_time;

    original_NetWaitForGuaranteeReplies();
}

static tNet_game_player_info *(*original_NetPlayerFromID)(tPlayer_ID, ...) = (tNet_game_player_info *(*)(tPlayer_ID, ...))0x0044ad74;
CARM95_HOOK_FUNCTION(original_NetPlayerFromID, NetPlayerFromID)
tNet_game_player_info* NetPlayerFromID(tPlayer_ID pPlayer) {
    int i;
    LOG_TRACE("(%u)", pPlayer);

    (void)pPlayer;
    (void)i;

    return original_NetPlayerFromID(pPlayer);
}

static tCar_spec *(*original_NetCarFromPlayerID)(tPlayer_ID, ...) = (tCar_spec *(*)(tPlayer_ID, ...))0x0044add4;
CARM95_HOOK_FUNCTION(original_NetCarFromPlayerID, NetCarFromPlayerID)
tCar_spec* NetCarFromPlayerID(tPlayer_ID pPlayer) {
    int i;
    tNet_game_player_info *player;
    LOG_TRACE("(%u)", pPlayer);

    (void)pPlayer;
    (void)i;
    (void)player;

    return original_NetCarFromPlayerID(pPlayer);
}

static tNet_game_player_info *(*original_NetPlayerFromCar)(tCar_spec *, ...) = (tNet_game_player_info *(*)(tCar_spec *, ...))0x0044ae15;
CARM95_HOOK_FUNCTION(original_NetPlayerFromCar, NetPlayerFromCar)
tNet_game_player_info* NetPlayerFromCar(tCar_spec *pCar) {
    int i;
    LOG_TRACE("(%p)", pCar);

    (void)pCar;
    (void)i;

    return original_NetPlayerFromCar(pCar);
}

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

    NOT_IMPLEMENTED();
}

static void(*original_GetCheckSum)(tNet_message *, ...) = (void(*)(tNet_message *, ...))0x0044ae74;
CARM95_HOOK_FUNCTION(original_GetCheckSum, GetCheckSum)
void GetCheckSum(tNet_message *pMessage) {
    LOG_TRACE("(%p)", pMessage);

    (void)pMessage;

    original_GetCheckSum(pMessage);
}

static void(*original_CheckCheckSum)(tNet_message *, ...) = (void(*)(tNet_message *, ...))0x0044ae7f;
CARM95_HOOK_FUNCTION(original_CheckCheckSum, CheckCheckSum)
void CheckCheckSum(tNet_message *pMessage) {
    LOG_TRACE("(%p)", pMessage);

    (void)pMessage;

    original_CheckCheckSum(pMessage);
}

