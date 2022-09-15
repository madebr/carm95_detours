#ifndef _NETWORK_H_
#define _NETWORK_H_

#include "br_types.h"
#include "dr_types.h"

// extern tU32 * hookvar_gMess_max_flags ;
// extern tU32 * hookvar_gMess_mid_flags ;
// extern tU32 * hookvar_gMess_min_flags ;
extern tU32 * hookvar_gGuarantee_number ; // addr: 0050D224
extern int * hookvar_gNet_service_disable ; // addr: 0050D228
extern int * hookvar_gIn_net_service ; // addr: 0050D22C
extern int * hookvar_gPlayer_list_batch_number ; // addr: 0050D230
extern int * hookvar_gOnly_receive_guarantee_replies ; // addr: 0050D234
extern void ** hookvar_gMessage_to_free ; // addr: 0050D238
extern tNet_message ** hookvar_gBroadcast_stack ; // addr: 0050D23C
extern tNet_message ** hookvar_gTo_host_stack ; // addr: 0050D240
extern tU32 * hookvar_gLast_flush_message ; // addr: 0050D244
extern int(* hookvar_gRace_only_flags )[33]; // addr: 0050D248
extern int * hookvar_gJoin_list_mode ; // addr: 0050D2CC
extern tNet_game_player_info(* hookvar_gNew_net_players )[6]; // addr: 00535DD0
extern tGuaranteed_message(* hookvar_gGuarantee_list )[150]; // addr: 00534C90
extern tMid_message ** hookvar_gMid_messages ; // addr: 00534C70
extern tU32 * hookvar_gLast_player_list_received ; // addr: 00534C84
extern tMin_message ** hookvar_gMin_messages ; // addr: 00534C7C
extern void(*** hookvar_gAdd_proc )(tNet_game_details *, ...); // addr: 00535DC0
extern int * hookvar_gReceiving_batch_number ; // addr: 00534C64
extern int * hookvar_gReceiving_new_players ; // addr: 00536250
extern tMax_message ** hookvar_gMax_messages ; // addr: 00534C80
extern int * hookvar_gNext_guarantee ; // addr: 00534C58
extern tU32 * hookvar_gAsk_time ; // addr: 0050F1AC
extern int * hookvar_gNet_initialised ; // addr: 00534C6C
extern int * hookvar_gDont_allow_joiners ; // addr: 00534C60
extern tNet_game_details ** hookvar_gCurrent_join_poll_game ; // addr: 00536254
extern int * hookvar_gMessage_header_size ; // addr: 00534C8C
extern int * hookvar_gJoin_poll_index ; // addr: 00534C5C
extern int * hookvar_gJoin_request_denied ; // addr: 00535DC8
extern int * hookvar_gHost_died ; // addr: 00534C68
// extern int * hookvar_gCar_was_taken ;
extern int * hookvar_gBastard_has_answered ; // addr: 00534C78
// extern int * hookvar_gTime_for_next_one ;
extern int * hookvar_gReceived_game_scores ; // addr: 005514D4

int NetInitialise();

int NetShutdown();

void ShutdownNetIfRequired();

void DisableNetService();

void ReenableNetService();

int PermitNetServiceReentrancy();

void HaltNetServiceReentrancy();

void NetSendHeadupToAllPlayers(char *pMessage);

void NetSendHeadupToEverybody(char *pMessage);

void NetSendHeadupToPlayer(char *pMessage, tPlayer_ID pPlayer);

void InitialisePlayerStati();

void LeaveTempGame();

void DisposeCurrentJoinPollGame();

void DoNextJoinPoll();

void NetStartProducingJoinList(void(**pAdd_proc)(tNet_game_details *, ...));

void NetEndJoinList();

void NetDisposePIDGameInfo(tNet_game_details *pDetails);

void NetDisposeGameDetails(tNet_game_details *pDetails);

tNet_game_details* NetAllocatePIDGameDetails();

void NetLeaveGameLowLevel(tNet_game_details *pDetails);

void NetLeaveGame(tNet_game_details *pNet_game);

void NetSetPlayerSystemInfo(tNet_game_player_info *pPlayer, void *pSender_address);

void NetDisposePlayer(tNet_game_player_info *pPlayer);

void FillInThisPlayer(tNet_game_details *pGame, tNet_game_player_info *pPlayer, int pCar_index, int pHost);

void LoadCarN(int pIndex, tNet_game_player_info *pPlayer);

void DisposeCarN(int pIndex);

void PlayerHasLeft(int pIndex);

void NetPlayersChanged(int pNew_count, tNet_game_player_info *pNew_players);

tNet_game_details* NetHostGame(tNet_game_type pGame_type, tNet_game_options *pOptions, int pStart_rank, char *pHost_name, int pCar_index);

int NetInitClient(tNet_game_details *pDetails);

int NetJoinGameLowLevel(tNet_game_details *pDetails, char *pPlayer_name);

int NetJoinGame(tNet_game_details *pDetails, char *pPlayer_name, int pCar_index);

void NetObtainSystemUserName(char *pName, int pMax_length);

tU32 NetExtractGameID(tNet_game_details *pDetails);

tPlayer_ID NetExtractPlayerID(tNet_game_details *pDetails);

int NetSendMessageToAddress(tNet_game_details *pDetails, tNet_message *pMessage, void *pAddress);

int NetSendMessageToPlayer(tNet_game_details *pDetails, tNet_message *pMessage, tPlayer_ID pPlayer);

int NetSendMessageToHost(tNet_game_details *pDetails, tNet_message *pMessage);

int NetReplyToMessage(tNet_game_details *pDetails, tNet_message *pIncoming_message, tNet_message *pReply_message);

int NetSendMessageToAllPlayers(tNet_game_details *pDetails, tNet_message *pMessage);

tU32 NetGetContentsSize(tNet_message_type pType, tS32 pSize_decider);

tU32 NetGetMessageSize(tNet_message_type pType, tS32 pSize_decider);

tS32 NetCalcSizeDecider(tNet_contents *pContents);

tNet_message* NetBuildMessage(tNet_message_type pType, tS32 pSize_decider);

tNet_contents* NetGetToHostContents(tNet_message_type pType, tS32 pSize_decider);

tNet_contents* NetGetBroadcastContents(tNet_message_type pType, tS32 pSize_decider);

void NetSendMessageStacks();

tNet_message* NetAllocateMessage(int pSize);

void NetFreeExcessMemory();

int NetDisposeMessage(tNet_game_details *pDetails, tNet_message *pMessage);

tNet_message* NetGetNextMessage(tNet_game_details *pDetails, void **pSender_address);

void ReceivedSendMeDetails(tNet_contents *pContents, void *pSender_address);

void ReceivedDetails(tNet_contents *pContents);

void SendOutPlayerList();

void ReceivedJoin(tNet_contents *pContents, void *pSender_address);

void KickPlayerOut(tPlayer_ID pID);

void ReceivedLeave(tNet_contents *pContents, tNet_message *pMessage);

void NetFullScreenMessage(int pStr_index, int pLeave_it_up_there);

void HostHasBittenTheDust(int pMessage_index);

void ReceivedHosticide(tNet_contents *pContents);

void ConfirmReceipt();

void ReceivedNewPlayerList(tNet_contents *pContents, tNet_message *pM);

void ReceivedRaceOver(tNet_contents *pContents);

void ReceivedStatusReport(tNet_contents *pContents, tNet_message *pMessage);

void ReceivedStartRace(tNet_contents *pContents);

void ReceivedGuaranteeReply(tNet_contents *pContents);

void ReceivedHeadup(tNet_contents *pContents);

void ReceivedHostQuery(tNet_contents *pContents, tNet_message *pMessage);

void ReceivedHostReply(tNet_contents *pContents);

void SendGuaranteeReply(tNet_message *pMessage, void *pSender_address);

int PlayerIsInList(tPlayer_ID pID);

void ReceivedTimeSync(tNet_contents *pContents, tNet_message *pMessage, tU32 pReceive_time);

void ReceivedConfirm(tNet_contents *pContents);

void ReceivedDisableCar(tNet_contents *pContents);

void ReceivedEnableCar(tNet_contents *pContents);

void ReceivedScores(tNet_contents *pContents);

void ReceivedWasted(tNet_contents *pContents);

void ReceivedCarDetailsReq(tNet_contents *pContents, void *pSender_address);

void ReceivedCarDetails(tNet_contents *pContents);

void ReceivedGameScores(tNet_contents *pContents);

void ReceivedMessage(tNet_message *pMessage, void *pSender_address, tU32 pReceive_time);

void NetReceiveAndProcessMessages();

void BroadcastStatus();

void CheckForDisappearees();

void CheckForPendingStartRace();

void NetService(int pIn_race);

void NetFinishRace(tNet_game_details *pDetails, tRace_over_reason pReason);

void NetPlayerStatusChanged(tPlayer_status pNew_status);

tPlayer_status NetGetPlayerStatus();

int NetGuaranteedSendMessageToAllPlayers(tNet_game_details *pDetails, tNet_message *pMessage, int(**pNotifyFail)(tU32, tNet_message *, ...));

int NetGuaranteedSendMessageToEverybody(tNet_game_details *pDetails, tNet_message *pMessage, int(**pNotifyFail)(tU32, tNet_message *, ...));

int NetGuaranteedSendMessageToHost(tNet_game_details *pDetails, tNet_message *pMessage, int(**pNotifyFail)(tU32, tNet_message *, ...));

int NetGuaranteedSendMessageToPlayer(tNet_game_details *pDetails, tNet_message *pMessage, tPlayer_ID pPlayer, int(**pNotifyFail)(tU32, tNet_message *, ...));

int NetGuaranteedSendMessageToAddress(tNet_game_details *pDetails, tNet_message *pMessage, void *pAddress, int(**pNotifyFail)(tU32, tNet_message *, ...));

void ResendGuaranteedMessages();

int SampleFailNotifier(tU32 pAge, tNet_message *pMessage);

void NetWaitForGuaranteeReplies();

tNet_game_player_info* NetPlayerFromID(tPlayer_ID pPlayer);

tCar_spec* NetCarFromPlayerID(tPlayer_ID pPlayer);

tNet_game_player_info* NetPlayerFromCar(tCar_spec *pCar);

tU32 DoCheckSum(tNet_message *pMessage);

void GetCheckSum(tNet_message *pMessage);

void CheckCheckSum(tNet_message *pMessage);

#endif
