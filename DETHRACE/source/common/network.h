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
extern void(*** hookvar_gAdd_proc )(tNet_game_details *); // addr: 00535DC0
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

int __cdecl NetInitialise();

int __cdecl NetShutdown();

void __cdecl ShutdownNetIfRequired();

void __cdecl DisableNetService();

void __cdecl ReenableNetService();

int __cdecl PermitNetServiceReentrancy();

void __cdecl HaltNetServiceReentrancy();

void __cdecl NetSendHeadupToAllPlayers(char *pMessage);

void __cdecl NetSendHeadupToEverybody(char *pMessage);

void __cdecl NetSendHeadupToPlayer(char *pMessage, tPlayer_ID pPlayer);

void __cdecl InitialisePlayerStati();

void __cdecl LeaveTempGame();

void __cdecl DisposeCurrentJoinPollGame();

void __cdecl DoNextJoinPoll();

void __cdecl NetStartProducingJoinList(void(**pAdd_proc)(tNet_game_details *));

void __cdecl NetEndJoinList();

void __cdecl NetDisposePIDGameInfo(tNet_game_details *pDetails);

void __cdecl NetDisposeGameDetails(tNet_game_details *pDetails);

tNet_game_details* __cdecl NetAllocatePIDGameDetails();

void __cdecl NetLeaveGameLowLevel(tNet_game_details *pDetails);

void __cdecl NetLeaveGame(tNet_game_details *pNet_game);

void __cdecl NetSetPlayerSystemInfo(tNet_game_player_info *pPlayer, void *pSender_address);

void __cdecl NetDisposePlayer(tNet_game_player_info *pPlayer);

void __cdecl FillInThisPlayer(tNet_game_details *pGame, tNet_game_player_info *pPlayer, int pCar_index, int pHost);

void __cdecl LoadCarN(int pIndex, tNet_game_player_info *pPlayer);

void __cdecl DisposeCarN(int pIndex);

void __cdecl PlayerHasLeft(int pIndex);

void __cdecl NetPlayersChanged(int pNew_count, tNet_game_player_info *pNew_players);

tNet_game_details* __cdecl NetHostGame(tNet_game_type pGame_type, tNet_game_options *pOptions, int pStart_rank, char *pHost_name, int pCar_index);

int __cdecl NetInitClient(tNet_game_details *pDetails);

int __cdecl NetJoinGameLowLevel(tNet_game_details *pDetails, char *pPlayer_name);

int __cdecl NetJoinGame(tNet_game_details *pDetails, char *pPlayer_name, int pCar_index);

void __cdecl NetObtainSystemUserName(char *pName, int pMax_length);

tU32 __cdecl NetExtractGameID(tNet_game_details *pDetails);

tPlayer_ID __cdecl NetExtractPlayerID(tNet_game_details *pDetails);

int __cdecl NetSendMessageToAddress(tNet_game_details *pDetails, tNet_message *pMessage, void *pAddress);

int __cdecl NetSendMessageToPlayer(tNet_game_details *pDetails, tNet_message *pMessage, tPlayer_ID pPlayer);

int __cdecl NetSendMessageToHost(tNet_game_details *pDetails, tNet_message *pMessage);

int __cdecl NetReplyToMessage(tNet_game_details *pDetails, tNet_message *pIncoming_message, tNet_message *pReply_message);

int __cdecl NetSendMessageToAllPlayers(tNet_game_details *pDetails, tNet_message *pMessage);

tU32 __cdecl NetGetContentsSize(tNet_message_type pType, tS32 pSize_decider);

tU32 __cdecl NetGetMessageSize(tNet_message_type pType, tS32 pSize_decider);

tS32 __cdecl NetCalcSizeDecider(tNet_contents *pContents);

tNet_message* __cdecl NetBuildMessage(tNet_message_type pType, tS32 pSize_decider);

tNet_contents* __cdecl NetGetToHostContents(tNet_message_type pType, tS32 pSize_decider);

tNet_contents* __cdecl NetGetBroadcastContents(tNet_message_type pType, tS32 pSize_decider);

void __cdecl NetSendMessageStacks();

tNet_message* __cdecl NetAllocateMessage(int pSize);

void __cdecl NetFreeExcessMemory();

int __cdecl NetDisposeMessage(tNet_game_details *pDetails, tNet_message *pMessage);

tNet_message* __cdecl NetGetNextMessage(tNet_game_details *pDetails, void **pSender_address);

void __cdecl ReceivedSendMeDetails(tNet_contents *pContents, void *pSender_address);

void __cdecl ReceivedDetails(tNet_contents *pContents);

void __cdecl SendOutPlayerList();

void __cdecl ReceivedJoin(tNet_contents *pContents, void *pSender_address);

void __cdecl KickPlayerOut(tPlayer_ID pID);

void __cdecl ReceivedLeave(tNet_contents *pContents, tNet_message *pMessage);

void __cdecl NetFullScreenMessage(int pStr_index, int pLeave_it_up_there);

void __cdecl HostHasBittenTheDust(int pMessage_index);

void __cdecl ReceivedHosticide(tNet_contents *pContents);

void ConfirmReceipt();

void __cdecl ReceivedNewPlayerList(tNet_contents *pContents, tNet_message *pM);

void __cdecl ReceivedRaceOver(tNet_contents *pContents);

void __cdecl ReceivedStatusReport(tNet_contents *pContents, tNet_message *pMessage);

void __cdecl ReceivedStartRace(tNet_contents *pContents);

void __cdecl ReceivedGuaranteeReply(tNet_contents *pContents);

void __cdecl ReceivedHeadup(tNet_contents *pContents);

void __cdecl ReceivedHostQuery(tNet_contents *pContents, tNet_message *pMessage);

void __cdecl ReceivedHostReply(tNet_contents *pContents);

void __cdecl SendGuaranteeReply(tNet_message *pMessage, void *pSender_address);

int __cdecl PlayerIsInList(tPlayer_ID pID);

void __cdecl ReceivedTimeSync(tNet_contents *pContents, tNet_message *pMessage, tU32 pReceive_time);

void __cdecl ReceivedConfirm(tNet_contents *pContents);

void __cdecl ReceivedDisableCar(tNet_contents *pContents);

void __cdecl ReceivedEnableCar(tNet_contents *pContents);

void __cdecl ReceivedScores(tNet_contents *pContents);

void __cdecl ReceivedWasted(tNet_contents *pContents);

void __cdecl ReceivedCarDetailsReq(tNet_contents *pContents, void *pSender_address);

void __cdecl ReceivedCarDetails(tNet_contents *pContents);

void __cdecl ReceivedGameScores(tNet_contents *pContents);

void __cdecl ReceivedMessage(tNet_message *pMessage, void *pSender_address, tU32 pReceive_time);

void __cdecl NetReceiveAndProcessMessages();

void __cdecl BroadcastStatus();

void __cdecl CheckForDisappearees();

void __cdecl CheckForPendingStartRace();

void __cdecl NetService(int pIn_race);

void __cdecl NetFinishRace(tNet_game_details *pDetails, tRace_over_reason pReason);

void __cdecl NetPlayerStatusChanged(tPlayer_status pNew_status);

tPlayer_status __cdecl NetGetPlayerStatus();

int __cdecl NetGuaranteedSendMessageToAllPlayers(tNet_game_details *pDetails, tNet_message *pMessage, int(**pNotifyFail)(tU32, tNet_message *));

int __cdecl NetGuaranteedSendMessageToEverybody(tNet_game_details *pDetails, tNet_message *pMessage, int(**pNotifyFail)(tU32, tNet_message *));

int __cdecl NetGuaranteedSendMessageToHost(tNet_game_details *pDetails, tNet_message *pMessage, int(**pNotifyFail)(tU32, tNet_message *));

int __cdecl NetGuaranteedSendMessageToPlayer(tNet_game_details *pDetails, tNet_message *pMessage, tPlayer_ID pPlayer, int(**pNotifyFail)(tU32, tNet_message *));

int __cdecl NetGuaranteedSendMessageToAddress(tNet_game_details *pDetails, tNet_message *pMessage, void *pAddress, int(**pNotifyFail)(tU32, tNet_message *));

void __cdecl ResendGuaranteedMessages();

int __cdecl SampleFailNotifier(tU32 pAge, tNet_message *pMessage);

void __cdecl NetWaitForGuaranteeReplies();

tNet_game_player_info* __cdecl NetPlayerFromID(tPlayer_ID pPlayer);

tCar_spec* __cdecl NetCarFromPlayerID(tPlayer_ID pPlayer);

tNet_game_player_info* __cdecl NetPlayerFromCar(tCar_spec *pCar);

tU32 DoCheckSum(tNet_message *pMessage);

void __cdecl GetCheckSum(tNet_message *pMessage);

void __cdecl CheckCheckSum(tNet_message *pMessage);

#endif
