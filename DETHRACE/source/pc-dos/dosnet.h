#ifndef _DOSNET_H_
#define _DOSNET_H_

#include "br_types.h"
#include "dr_types.h"

// extern tU32 * hookvar_gNetwork_init_flags ;
extern tPD_net_game_info ** hookvar_gJoinable_games ; // addr: 00510E90
extern int * hookvar_gMatts_PC ; // addr: 00510E94
// extern tU16 * hookvar_gSocket_number_pd_format ;
// extern _IPX_ELEMENT(* hookvar_gListen_elements )[16];
// extern char(* hookvar_gLocal_ipx_addr_string )[32];
// extern _IPX_ELEMENT(* hookvar_gSend_elements )[16];
extern _IPX_LOCAL_TARGET * hookvar_gLocal_addr_ipx ; // addr: 00536848
extern char(* hookvar_gReceive_buffer )[512]; // addr: 00536450
// extern tPD_net_player_info * hookvar_gRemote_net_player_info ;
extern _IPX_LOCAL_TARGET * hookvar_gBroadcast_addr_ipx ; // addr: 00536838
// extern tPD_net_player_info * hookvar_gLocal_net_player_info ;
extern char(* hookvar_gSend_buffer )[512]; // addr: 00536898
extern tIPX_netnum(* hookvar_gNetworks )[16]; // addr: 00536668
extern _IPX_LOCAL_TARGET * hookvar_gRemote_addr_ipx ; // addr: 00536650
// extern tU8 ** hookvar_gSend_packet ;
// extern W32 * hookvar_gListen_segment ;
// extern tU8 ** hookvar_gSend_packet_ptr ;
// extern W32 * hookvar_gSend_segment ;
// extern tU8 ** hookvar_gListen_packet ;
// extern tU8 ** hookvar_gListen_packet_ptr ;
extern size_t * hookvar_gMsg_header_strlen ; // addr: 0053643C
extern int * hookvar_gNumber_of_networks ; // addr: 00536660
extern int * hookvar_gNumber_of_hosts ; // addr: 00536894
// extern tRM_info * hookvar_RMI ;
// extern _IPX_HEADER * hookvar_gLast_received_IPX_header ;
// extern tU16 * hookvar_gSocket_number_network_order ;
// extern USHORT * hookvar_gECB_offset ;
// extern tU16 * hookvar_gListen_selector ;
// extern tU16 * hookvar_gSend_selector ;

void ClearupPDNetworkStuff();

void MATTMessageCheck(char *pFunction_name, tNet_message *pMessage, int pAlleged_size);

int GetProfileText(char *pDest, int pDest_len, char *pFname, char *pKeyname);

int GetSocketNumberFromProfileFile();

tU32 EthernetAddressToU32(_IPX_LOCAL_TARGET *pAddr_ipx);

void NetNowIPXLocalTarget2String(char *pString, _IPX_LOCAL_TARGET *pSock_addr_ipx);

int __cdecl GetMessageTypeFromMessage(char *pMessage_str);

int __cdecl SameEthernetAddress(_IPX_LOCAL_TARGET *pAddr_ipx1, _IPX_LOCAL_TARGET *pAddr_ipx2);

_IPX_LOCAL_TARGET* GetIPXAddrFromPlayerID(tPlayer_ID pPlayer_id);

void __cdecl MakeMessageToSend(int pMessage_type);

int __cdecl ReceiveHostResponses();

int __cdecl BroadcastMessage();

BOOL hmiIPXCloseSocket(W32 wSocket);

void hmiIPXListenForPacket(_IPX_ECB *pECB_ptr, tU32 pOffset);

BOOL hmiIPXPostListen(_IPX_ECB *pECB_ptr, tU32 pOffset);

BOOL hmiIPXGetData(PSTR pData, tU32 wDSize);

void hmiIPXSendPacket(_IPX_ECB *sECB, _IPX_ECB **pPacket, PSTR pHeader, W32 wSize);

BOOL hmiIPXSendDataDirect(PSTR pHeader, W32 wHSize, PSTR pData, W32 wDSize, _NETNOW_NODE_ADDR *sNode);

void hmiIPXGetInternetworkAddr(_IPX_INTERNET_ADDR *sInterworkAddr);

void hmiIPXGetLocalTarget(_IPX_LOCAL_TARGET *sNetworkAddr);

BOOL AllocateRealMem(W32 wSize, PSTR *pPtr, W32 *pSegment, tU16 *pSelector);

BOOL FreeRealMem(tU16 pSelector);

BOOL hmiIPXInstalled();

BOOL hmiIPXOpenSocket(W32 wSocket);

void GetLargestPacketSizeOoErBetterInsertLinfordChristieJokeHere();

BOOL hmiIPXInitSystem(W32 wSocket);

void GetIPXToStickItsEarToTheGround();

int __cdecl PDNetInitialise();

int __cdecl PDNetShutdown();

void __cdecl PDNetStartProducingJoinList();

void __cdecl PDNetEndJoinList();

int __cdecl PDNetGetNextJoinGame(tNet_game_details *pGame, int pIndex);

void __cdecl PDNetDisposeGameDetails(tNet_game_details *pDetails);

int __cdecl PDNetHostGame(tNet_game_details *pDetails, char *pHost_name, void **pHost_address);

int __cdecl PDNetJoinGame(tNet_game_details *pDetails, char *pPlayer_name);

void __cdecl PDNetLeaveGame(tNet_game_details *pDetails);

void __cdecl PDNetHostFinishGame(tNet_game_details *pDetails);

tU32 __cdecl PDNetExtractGameID(tNet_game_details *pDetails);

tPlayer_ID __cdecl PDNetExtractPlayerID(tNet_game_details *pDetails);

void __cdecl PDNetObtainSystemUserName(char *pName, int pMax_length);

int __cdecl PDNetSendMessageToPlayer(tNet_game_details *pDetails, tNet_message *pMessage, tPlayer_ID pPlayer);

int __cdecl PDNetSendMessageToAllPlayers(tNet_game_details *pDetails, tNet_message *pMessage);

tNet_message* __cdecl PDNetGetNextMessage(tNet_game_details *pDetails, void **pSender_address);

tNet_message* __cdecl PDNetAllocateMessage(tU32 pSize, tS32 pSize_decider);

void PDNetDisposeMessage(tNet_game_details *pDetails, tNet_message *pMessage);

void __cdecl PDNetSetPlayerSystemInfo(tNet_game_player_info *pPlayer, void *pSender_address);

void __cdecl PDNetDisposePlayer(tNet_game_player_info *pPlayer);

int __cdecl PDNetSendMessageToAddress(tNet_game_details *pDetails, tNet_message *pMessage, void *pAddress);

int __cdecl PDNetInitClient(tNet_game_details *pDetails);

int __cdecl PDNetGetHeaderSize();

#endif
