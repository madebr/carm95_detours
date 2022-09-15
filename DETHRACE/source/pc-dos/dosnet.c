#include "dosnet.h"

#include "harness/trace.h"

#include "carm95_hooks.h"

#include <sys/stat.h>
#if 0
tU32 * hookvar_gNetwork_init_flags ;
#endif
tPD_net_game_info ** hookvar_gJoinable_games  = (void*)0x00510e90;
int * hookvar_gMatts_PC  = (void*)0x00510e94;
#if 0
tU16 * hookvar_gSocket_number_pd_format ;
#endif
#if 0
_IPX_ELEMENT(* hookvar_gListen_elements )[16];
#endif
#if 0
char(* hookvar_gLocal_ipx_addr_string )[32];
#endif
#if 0
_IPX_ELEMENT(* hookvar_gSend_elements )[16];
#endif
_IPX_LOCAL_TARGET * hookvar_gLocal_addr_ipx  = (void*)0x00536848;
char(* hookvar_gReceive_buffer )[512] = (void*)0x00536450;
#if 0
tPD_net_player_info * hookvar_gRemote_net_player_info ;
#endif
_IPX_LOCAL_TARGET * hookvar_gBroadcast_addr_ipx  = (void*)0x00536838;
#if 0
tPD_net_player_info * hookvar_gLocal_net_player_info ;
#endif
char(* hookvar_gSend_buffer )[512] = (void*)0x00536898;
tIPX_netnum(* hookvar_gNetworks )[16] = (void*)0x00536668;
_IPX_LOCAL_TARGET * hookvar_gRemote_addr_ipx  = (void*)0x00536650;
#if 0
tU8 ** hookvar_gSend_packet ;
#endif
#if 0
W32 * hookvar_gListen_segment ;
#endif
#if 0
tU8 ** hookvar_gSend_packet_ptr ;
#endif
#if 0
W32 * hookvar_gSend_segment ;
#endif
#if 0
tU8 ** hookvar_gListen_packet ;
#endif
#if 0
tU8 ** hookvar_gListen_packet_ptr ;
#endif
size_t * hookvar_gMsg_header_strlen  = (void*)0x0053643c;
int * hookvar_gNumber_of_networks  = (void*)0x00536660;
int * hookvar_gNumber_of_hosts  = (void*)0x00536894;
#if 0
tRM_info * hookvar_RMI ;
#endif
#if 0
_IPX_HEADER * hookvar_gLast_received_IPX_header ;
#endif
#if 0
tU16 * hookvar_gSocket_number_network_order ;
#endif
#if 0
USHORT * hookvar_gECB_offset ;
#endif
#if 0
tU16 * hookvar_gListen_selector ;
#endif
#if 0
tU16 * hookvar_gSend_selector ;
#endif

void ClearupPDNetworkStuff() {
    LOG_TRACE("()");


    NOT_IMPLEMENTED();
}

void MATTMessageCheck(char *pFunction_name, tNet_message *pMessage, int pAlleged_size) {
    LOG_TRACE("(\"%s\", %p, %d)", pFunction_name, pMessage, pAlleged_size);

    (void)pFunction_name;
    (void)pMessage;
    (void)pAlleged_size;

    NOT_IMPLEMENTED();
}

int GetProfileText(char *pDest, int pDest_len, char *pFname, char *pKeyname) {
    FILE *fp;
    char in_buf[256];
    int i;
    int j;
    int len;
    LOG_TRACE("(\"%s\", %d, \"%s\", \"%s\")", pDest, pDest_len, pFname, pKeyname);

    (void)pDest;
    (void)pDest_len;
    (void)pFname;
    (void)pKeyname;
    (void)fp;
    (void)in_buf;
    (void)i;
    (void)j;
    (void)len;

    NOT_IMPLEMENTED();
}

int GetSocketNumberFromProfileFile() {
    char str[256];
    int sscanf_res;
    tU32 socknum;
    LOG_TRACE("()");

    (void)str;
    (void)sscanf_res;
    (void)socknum;

    NOT_IMPLEMENTED();
}

tU32 EthernetAddressToU32(_IPX_LOCAL_TARGET *pAddr_ipx) {
    LOG_TRACE("(%p)", pAddr_ipx);

    (void)pAddr_ipx;

    NOT_IMPLEMENTED();
}

void NetNowIPXLocalTarget2String(char *pString, _IPX_LOCAL_TARGET *pSock_addr_ipx) {
    LOG_TRACE("(\"%s\", %p)", pString, pSock_addr_ipx);

    (void)pString;
    (void)pSock_addr_ipx;

    NOT_IMPLEMENTED();
}

static int(*original_GetMessageTypeFromMessage)(char *, ...) = (int(*)(char *, ...))0x00455050;
CARM95_HOOK_FUNCTION(original_GetMessageTypeFromMessage, GetMessageTypeFromMessage)
int GetMessageTypeFromMessage(char *pMessage_str) {
    char *real_msg;
    int msg_type_int;
    LOG_TRACE("(\"%s\")", pMessage_str);

    (void)pMessage_str;
    (void)real_msg;
    (void)msg_type_int;

    return original_GetMessageTypeFromMessage(pMessage_str);
}

static int(*original_SameEthernetAddress)(_IPX_LOCAL_TARGET *, _IPX_LOCAL_TARGET *, ...) = (int(*)(_IPX_LOCAL_TARGET *, _IPX_LOCAL_TARGET *, ...))0x00455119;
CARM95_HOOK_FUNCTION(original_SameEthernetAddress, SameEthernetAddress)
int SameEthernetAddress(_IPX_LOCAL_TARGET *pAddr_ipx1, _IPX_LOCAL_TARGET *pAddr_ipx2) {
    LOG_TRACE("(%p, %p)", pAddr_ipx1, pAddr_ipx2);

    (void)pAddr_ipx1;
    (void)pAddr_ipx2;

    return original_SameEthernetAddress(pAddr_ipx1, pAddr_ipx2);
}

_IPX_LOCAL_TARGET* GetIPXAddrFromPlayerID(tPlayer_ID pPlayer_id) {
    int i;
    tU8 *nodenum;
    LOG_TRACE("(%u)", pPlayer_id);

    (void)pPlayer_id;
    (void)i;
    (void)nodenum;

    NOT_IMPLEMENTED();
}

static void(*original_MakeMessageToSend)(int, ...) = (void(*)(int, ...))0x00454c4c;
CARM95_HOOK_FUNCTION(original_MakeMessageToSend, MakeMessageToSend)
void MakeMessageToSend(int pMessage_type) {
    LOG_TRACE("(%d)", pMessage_type);

    (void)pMessage_type;

    original_MakeMessageToSend(pMessage_type);
}

static int(*original_ReceiveHostResponses)() = (int(*)())0x00454d4d;
CARM95_HOOK_FUNCTION(original_ReceiveHostResponses, ReceiveHostResponses)
int ReceiveHostResponses() {
    char str[256];
    int i;
    int already_registered;
    LOG_TRACE("()");

    (void)str;
    (void)i;
    (void)already_registered;

    return original_ReceiveHostResponses();
}

static int(*original_BroadcastMessage)() = (int(*)())0x00454c72;
CARM95_HOOK_FUNCTION(original_BroadcastMessage, BroadcastMessage)
int BroadcastMessage() {
    int i;
    int errors;
    char broadcast_addr_string[32];
    char *real_msg;
    LOG_TRACE("()");

    (void)i;
    (void)errors;
    (void)broadcast_addr_string;
    (void)real_msg;

    return original_BroadcastMessage();
}

BOOL hmiIPXCloseSocket(W32 wSocket) {
    union REGS regs;
    struct SREGS sregs;
    LOG_TRACE("(%u)", wSocket);

    (void)wSocket;
    (void)regs;
    (void)sregs;

    NOT_IMPLEMENTED();
}

void hmiIPXListenForPacket(_IPX_ECB *pECB_ptr, tU32 pOffset) {
    struct SREGS sregs;
    union REGS regs;
    _IPX_HEADER *IPX_header_ptr;
    _IPX_ECB *sIPXECB;
    LOG_TRACE("(%p, %u)", pECB_ptr, pOffset);

    (void)pECB_ptr;
    (void)pOffset;
    (void)sregs;
    (void)regs;
    (void)IPX_header_ptr;
    (void)sIPXECB;

    NOT_IMPLEMENTED();
}

BOOL hmiIPXPostListen(_IPX_ECB *pECB_ptr, tU32 pOffset) {
    LOG_TRACE("(%p, %u)", pECB_ptr, pOffset);

    (void)pECB_ptr;
    (void)pOffset;

    NOT_IMPLEMENTED();
}

BOOL hmiIPXGetData(PSTR pData, tU32 wDSize) {
    tU32 packets_checked;
    tU32 full_packet_ooer_missus;
    _IPX_ECB *ECB_ptr;
    static tU32 round_robin_jobby;
    LOG_TRACE("(\"%s\", %u)", pData, wDSize);

    (void)pData;
    (void)wDSize;
    (void)packets_checked;
    (void)full_packet_ooer_missus;
    (void)ECB_ptr;
    (void)round_robin_jobby;

    NOT_IMPLEMENTED();
}

void hmiIPXSendPacket(_IPX_ECB *sECB, _IPX_ECB **pPacket, PSTR pHeader, W32 wSize) {
    struct SREGS sregs;
    union REGS regs;
    _IPX_HEADER *sIPXHeader;
    _IPX_ECB *sIPXECB;
    PSTR pIPXData;
    LOG_TRACE("(%p, %p, \"%s\", %u)", sECB, pPacket, pHeader, wSize);

    (void)sECB;
    (void)pPacket;
    (void)pHeader;
    (void)wSize;
    (void)sregs;
    (void)regs;
    (void)sIPXHeader;
    (void)sIPXECB;
    (void)pIPXData;

    NOT_IMPLEMENTED();
}

BOOL hmiIPXSendDataDirect(PSTR pHeader, W32 wHSize, PSTR pData, W32 wDSize, _NETNOW_NODE_ADDR *sNode) {
    W32 wIndex;
    _IPX_ELEMENT *sElement;
    W32 *pSequence;
    LOG_TRACE("(\"%s\", %u, \"%s\", %u, %p)", pHeader, wHSize, pData, wDSize, sNode);

    (void)pHeader;
    (void)wHSize;
    (void)pData;
    (void)wDSize;
    (void)sNode;
    (void)wIndex;
    (void)sElement;
    (void)pSequence;

    NOT_IMPLEMENTED();
}

void hmiIPXGetInternetworkAddr(_IPX_INTERNET_ADDR *sInterworkAddr) {
    struct SREGS sregs;
    union REGS regs;
    LOG_TRACE("(%p)", sInterworkAddr);

    (void)sInterworkAddr;
    (void)sregs;
    (void)regs;

    NOT_IMPLEMENTED();
}

void hmiIPXGetLocalTarget(_IPX_LOCAL_TARGET *sNetworkAddr) {
    struct SREGS sregs;
    union REGS regs;
    LOG_TRACE("(%p)", sNetworkAddr);

    (void)sNetworkAddr;
    (void)sregs;
    (void)regs;

    NOT_IMPLEMENTED();
}

BOOL AllocateRealMem(W32 wSize, PSTR *pPtr, W32 *pSegment, tU16 *pSelector) {
    union REGS regs;
    struct SREGS sregs;
    W32 wAddress;
    W32 wHandle;
    W32 wSegment;
    W32 wLinear;
    LOG_TRACE("(%u, %p, %p, %p)", wSize, pPtr, pSegment, pSelector);

    (void)wSize;
    (void)pPtr;
    (void)pSegment;
    (void)pSelector;
    (void)regs;
    (void)sregs;
    (void)wAddress;
    (void)wHandle;
    (void)wSegment;
    (void)wLinear;

    NOT_IMPLEMENTED();
}

BOOL FreeRealMem(tU16 pSelector) {
    union REGS regs;
    struct SREGS sregs;
    W32 wAddress;
    W32 wHandle;
    W32 wSegment;
    W32 wLinear;
    LOG_TRACE("(%u)", pSelector);

    (void)pSelector;
    (void)regs;
    (void)sregs;
    (void)wAddress;
    (void)wHandle;
    (void)wSegment;
    (void)wLinear;

    NOT_IMPLEMENTED();
}

BOOL hmiIPXInstalled() {
    struct SREGS sregs;
    union REGS regs;
    LOG_TRACE("()");

    (void)sregs;
    (void)regs;

    NOT_IMPLEMENTED();
}

BOOL hmiIPXOpenSocket(W32 wSocket) {
    struct SREGS sregs;
    union REGS regs;
    LOG_TRACE("(%u)", wSocket);

    (void)wSocket;
    (void)sregs;
    (void)regs;

    NOT_IMPLEMENTED();
}

void GetLargestPacketSizeOoErBetterInsertLinfordChristieJokeHere() {
    struct SREGS sregs;
    union REGS regs;
    LOG_TRACE("()");

    (void)sregs;
    (void)regs;

    NOT_IMPLEMENTED();
}

BOOL hmiIPXInitSystem(W32 wSocket) {
    W32 wNIndex;
    W32 wIndex;
    W32 wMIndex;
    USHORT wSOffset;
    USHORT wLOffset;
    LOG_TRACE("(%u)", wSocket);

    (void)wSocket;
    (void)wNIndex;
    (void)wIndex;
    (void)wMIndex;
    (void)wSOffset;
    (void)wLOffset;

    NOT_IMPLEMENTED();
}

void GetIPXToStickItsEarToTheGround() {
    int i;
    LOG_TRACE("()");

    (void)i;

    NOT_IMPLEMENTED();
}

static int(*original_PDNetInitialise)() = (int(*)())0x004543f8;
CARM95_HOOK_FUNCTION(original_PDNetInitialise, PDNetInitialise)
int PDNetInitialise() {
    tU32 timenow;
    char profile_string[32];
    char key_name[32];
    int sscanf_res;
    int i;
    tU32 netnum;
    char str[256];
    int mess_num;
    LOG_TRACE("()");

    (void)timenow;
    (void)profile_string;
    (void)key_name;
    (void)sscanf_res;
    (void)i;
    (void)netnum;
    (void)str;
    (void)mess_num;

    return original_PDNetInitialise();
}

static int(*original_PDNetShutdown)() = (int(*)())0x004549f2;
CARM95_HOOK_FUNCTION(original_PDNetShutdown, PDNetShutdown)
int PDNetShutdown() {
    LOG_TRACE("()");


    return original_PDNetShutdown();
}

static void(*original_PDNetStartProducingJoinList)() = (void(*)())0x00454a33;
CARM95_HOOK_FUNCTION(original_PDNetStartProducingJoinList, PDNetStartProducingJoinList)
void PDNetStartProducingJoinList() {
    LOG_TRACE("()");


    original_PDNetStartProducingJoinList();
}

static void(*original_PDNetEndJoinList)() = (void(*)())0x00454a86;
CARM95_HOOK_FUNCTION(original_PDNetEndJoinList, PDNetEndJoinList)
void PDNetEndJoinList() {
    LOG_TRACE("()");


    original_PDNetEndJoinList();
}

static int(*original_PDNetGetNextJoinGame)(tNet_game_details *, int, ...) = (int(*)(tNet_game_details *, int, ...))0x00454ac3;
CARM95_HOOK_FUNCTION(original_PDNetGetNextJoinGame, PDNetGetNextJoinGame)
int PDNetGetNextJoinGame(tNet_game_details *pGame, int pIndex) {
    static tU32 next_broadcast_time;
    int i;
    int j;
    int number_of_hosts_has_changed;
    char str[256];
    LOG_TRACE("(%p, %d)", pGame, pIndex);

    (void)pGame;
    (void)pIndex;
    (void)next_broadcast_time;
    (void)i;
    (void)j;
    (void)number_of_hosts_has_changed;
    (void)str;

    return original_PDNetGetNextJoinGame(pGame, pIndex);
}

static void(*original_PDNetDisposeGameDetails)(tNet_game_details *, ...) = (void(*)(tNet_game_details *, ...))0x00455161;
CARM95_HOOK_FUNCTION(original_PDNetDisposeGameDetails, PDNetDisposeGameDetails)
void PDNetDisposeGameDetails(tNet_game_details *pDetails) {
    LOG_TRACE("(%p)", pDetails);

    (void)pDetails;

    original_PDNetDisposeGameDetails(pDetails);
}

static int(*original_PDNetHostGame)(tNet_game_details *, char *, void **, ...) = (int(*)(tNet_game_details *, char *, void **, ...))0x00455179;
CARM95_HOOK_FUNCTION(original_PDNetHostGame, PDNetHostGame)
int PDNetHostGame(tNet_game_details *pDetails, char *pHost_name, void **pHost_address) {
    LOG_TRACE("(%p, \"%s\", %p)", pDetails, pHost_name, pHost_address);

    (void)pDetails;
    (void)pHost_name;
    (void)pHost_address;

    return original_PDNetHostGame(pDetails, pHost_name, pHost_address);
}

static int(*original_PDNetJoinGame)(tNet_game_details *, char *, ...) = (int(*)(tNet_game_details *, char *, ...))0x004551a4;
CARM95_HOOK_FUNCTION(original_PDNetJoinGame, PDNetJoinGame)
int PDNetJoinGame(tNet_game_details *pDetails, char *pPlayer_name) {
    LOG_TRACE("(%p, \"%s\")", pDetails, pPlayer_name);

    (void)pDetails;
    (void)pPlayer_name;

    return original_PDNetJoinGame(pDetails, pPlayer_name);
}

static void(*original_PDNetLeaveGame)(tNet_game_details *, ...) = (void(*)(tNet_game_details *, ...))0x004551c3;
CARM95_HOOK_FUNCTION(original_PDNetLeaveGame, PDNetLeaveGame)
void PDNetLeaveGame(tNet_game_details *pDetails) {
    LOG_TRACE("(%p)", pDetails);

    (void)pDetails;

    original_PDNetLeaveGame(pDetails);
}

static void(*original_PDNetHostFinishGame)(tNet_game_details *, ...) = (void(*)(tNet_game_details *, ...))0x004551db;
CARM95_HOOK_FUNCTION(original_PDNetHostFinishGame, PDNetHostFinishGame)
void PDNetHostFinishGame(tNet_game_details *pDetails) {
    LOG_TRACE("(%p)", pDetails);

    (void)pDetails;

    original_PDNetHostFinishGame(pDetails);
}

static tU32(*original_PDNetExtractGameID)(tNet_game_details *, ...) = (tU32(*)(tNet_game_details *, ...))0x004551f3;
CARM95_HOOK_FUNCTION(original_PDNetExtractGameID, PDNetExtractGameID)
tU32 PDNetExtractGameID(tNet_game_details *pDetails) {
    LOG_TRACE("(%p)", pDetails);

    (void)pDetails;

    return original_PDNetExtractGameID(pDetails);
}

static tPlayer_ID(*original_PDNetExtractPlayerID)(tNet_game_details *, ...) = (tPlayer_ID(*)(tNet_game_details *, ...))0x00455277;
CARM95_HOOK_FUNCTION(original_PDNetExtractPlayerID, PDNetExtractPlayerID)
tPlayer_ID PDNetExtractPlayerID(tNet_game_details *pDetails) {
    LOG_TRACE("(%p)", pDetails);

    (void)pDetails;

    return original_PDNetExtractPlayerID(pDetails);
}

static void(*original_PDNetObtainSystemUserName)(char *, int, ...) = (void(*)(char *, int, ...))0x004552be;
CARM95_HOOK_FUNCTION(original_PDNetObtainSystemUserName, PDNetObtainSystemUserName)
void PDNetObtainSystemUserName(char *pName, int pMax_length) {
    LOG_TRACE("(\"%s\", %d)", pName, pMax_length);

    (void)pName;
    (void)pMax_length;

    original_PDNetObtainSystemUserName(pName, pMax_length);
}

static int(*original_PDNetSendMessageToPlayer)(tNet_game_details *, tNet_message *, tPlayer_ID, ...) = (int(*)(tNet_game_details *, tNet_message *, tPlayer_ID, ...))0x00455349;
CARM95_HOOK_FUNCTION(original_PDNetSendMessageToPlayer, PDNetSendMessageToPlayer)
int PDNetSendMessageToPlayer(tNet_game_details *pDetails, tNet_message *pMessage, tPlayer_ID pPlayer) {
    char str[256];
    _IPX_LOCAL_TARGET *remote_addr_ipx;
    LOG_TRACE("(%p, %p, %u)", pDetails, pMessage, pPlayer);

    (void)pDetails;
    (void)pMessage;
    (void)pPlayer;
    (void)str;
    (void)remote_addr_ipx;

    return original_PDNetSendMessageToPlayer(pDetails, pMessage, pPlayer);
}

static int(*original_PDNetSendMessageToAllPlayers)(tNet_game_details *, tNet_message *, ...) = (int(*)(tNet_game_details *, tNet_message *, ...))0x004553de;
CARM95_HOOK_FUNCTION(original_PDNetSendMessageToAllPlayers, PDNetSendMessageToAllPlayers)
int PDNetSendMessageToAllPlayers(tNet_game_details *pDetails, tNet_message *pMessage) {
    char str[256];
    int i;
    LOG_TRACE("(%p, %p)", pDetails, pMessage);

    (void)pDetails;
    (void)pMessage;
    (void)str;
    (void)i;

    return original_PDNetSendMessageToAllPlayers(pDetails, pMessage);
}

static tNet_message *(*original_PDNetGetNextMessage)(tNet_game_details *, void **, ...) = (tNet_message *(*)(tNet_game_details *, void **, ...))0x00455495;
CARM95_HOOK_FUNCTION(original_PDNetGetNextMessage, PDNetGetNextMessage)
tNet_message* PDNetGetNextMessage(tNet_game_details *pDetails, void **pSender_address) {
    char *receive_buffer;
    char str[256];
    int msg_type;
    LOG_TRACE("(%p, %p)", pDetails, pSender_address);

    (void)pDetails;
    (void)pSender_address;
    (void)receive_buffer;
    (void)str;
    (void)msg_type;

    return original_PDNetGetNextMessage(pDetails, pSender_address);
}

static tNet_message *(*original_PDNetAllocateMessage)(tU32, tS32, ...) = (tNet_message *(*)(tU32, tS32, ...))0x00455730;
CARM95_HOOK_FUNCTION(original_PDNetAllocateMessage, PDNetAllocateMessage)
tNet_message* PDNetAllocateMessage(tU32 pSize, tS32 pSize_decider) {
    LOG_TRACE("(%u, %d)", pSize, pSize_decider);

    (void)pSize;
    (void)pSize_decider;

    return original_PDNetAllocateMessage(pSize, pSize_decider);
}

void PDNetDisposeMessage(tNet_game_details *pDetails, tNet_message *pMessage) {
    LOG_TRACE("(%p, %p)", pDetails, pMessage);

    (void)pDetails;
    (void)pMessage;

    NOT_IMPLEMENTED();
}

static void(*original_PDNetSetPlayerSystemInfo)(tNet_game_player_info *, void *, ...) = (void(*)(tNet_game_player_info *, void *, ...))0x0045576c;
CARM95_HOOK_FUNCTION(original_PDNetSetPlayerSystemInfo, PDNetSetPlayerSystemInfo)
void PDNetSetPlayerSystemInfo(tNet_game_player_info *pPlayer, void *pSender_address) {
    LOG_TRACE("(%p, %p)", pPlayer, pSender_address);

    (void)pPlayer;
    (void)pSender_address;

    original_PDNetSetPlayerSystemInfo(pPlayer, pSender_address);
}

static void(*original_PDNetDisposePlayer)(tNet_game_player_info *, ...) = (void(*)(tNet_game_player_info *, ...))0x004557a2;
CARM95_HOOK_FUNCTION(original_PDNetDisposePlayer, PDNetDisposePlayer)
void PDNetDisposePlayer(tNet_game_player_info *pPlayer) {
    LOG_TRACE("(%p)", pPlayer);

    (void)pPlayer;

    original_PDNetDisposePlayer(pPlayer);
}

static int(*original_PDNetSendMessageToAddress)(tNet_game_details *, tNet_message *, void *, ...) = (int(*)(tNet_game_details *, tNet_message *, void *, ...))0x004557ba;
CARM95_HOOK_FUNCTION(original_PDNetSendMessageToAddress, PDNetSendMessageToAddress)
int PDNetSendMessageToAddress(tNet_game_details *pDetails, tNet_message *pMessage, void *pAddress) {
    char str[256];
    LOG_TRACE("(%p, %p, %p)", pDetails, pMessage, pAddress);

    (void)pDetails;
    (void)pMessage;
    (void)pAddress;
    (void)str;

    return original_PDNetSendMessageToAddress(pDetails, pMessage, pAddress);
}

static int(*original_PDNetInitClient)(tNet_game_details *, ...) = (int(*)(tNet_game_details *, ...))0x00455838;
CARM95_HOOK_FUNCTION(original_PDNetInitClient, PDNetInitClient)
int PDNetInitClient(tNet_game_details *pDetails) {
    LOG_TRACE("(%p)", pDetails);

    (void)pDetails;

    return original_PDNetInitClient(pDetails);
}

static int(*original_PDNetGetHeaderSize)() = (int(*)())0x00455857;
CARM95_HOOK_FUNCTION(original_PDNetGetHeaderSize, PDNetGetHeaderSize)
int PDNetGetHeaderSize() {
    LOG_TRACE("()");


    return original_PDNetGetHeaderSize();
}

