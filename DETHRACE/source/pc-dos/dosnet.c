#include "dosnet.h"

#include "harness/trace.h"

#include "carm95_hooks.h"

#include "carm95_webserver.h"

#include <assert.h>
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

function_hook_state_t function_hook_state_ClearupPDNetworkStuff = HOOK_UNAVAILABLE;
void ClearupPDNetworkStuff() {
    LOG_TRACE("()");


    if (function_hook_state_ClearupPDNetworkStuff == HOOK_ENABLED) {
        assert(0 && "ClearupPDNetworkStuff not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}

function_hook_state_t function_hook_state_MATTMessageCheck = HOOK_UNAVAILABLE;
void MATTMessageCheck(char *pFunction_name, tNet_message *pMessage, int pAlleged_size) {
    LOG_TRACE("(\"%s\", %p, %d)", pFunction_name, pMessage, pAlleged_size);

    (void)pFunction_name;
    (void)pMessage;
    (void)pAlleged_size;

    if (function_hook_state_MATTMessageCheck == HOOK_ENABLED) {
        assert(0 && "MATTMessageCheck not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}

function_hook_state_t function_hook_state_GetProfileText = HOOK_UNAVAILABLE;
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

    if (function_hook_state_GetProfileText == HOOK_ENABLED) {
        assert(0 && "GetProfileText not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}

function_hook_state_t function_hook_state_GetSocketNumberFromProfileFile = HOOK_UNAVAILABLE;
int GetSocketNumberFromProfileFile() {
    char str[256];
    int sscanf_res;
    tU32 socknum;
    LOG_TRACE("()");

    (void)str;
    (void)sscanf_res;
    (void)socknum;

    if (function_hook_state_GetSocketNumberFromProfileFile == HOOK_ENABLED) {
        assert(0 && "GetSocketNumberFromProfileFile not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}

function_hook_state_t function_hook_state_EthernetAddressToU32 = HOOK_UNAVAILABLE;
tU32 EthernetAddressToU32(_IPX_LOCAL_TARGET *pAddr_ipx) {
    LOG_TRACE("(%p)", pAddr_ipx);

    (void)pAddr_ipx;

    if (function_hook_state_EthernetAddressToU32 == HOOK_ENABLED) {
        assert(0 && "EthernetAddressToU32 not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}

function_hook_state_t function_hook_state_NetNowIPXLocalTarget2String = HOOK_UNAVAILABLE;
void NetNowIPXLocalTarget2String(char *pString, _IPX_LOCAL_TARGET *pSock_addr_ipx) {
    LOG_TRACE("(\"%s\", %p)", pString, pSock_addr_ipx);

    (void)pString;
    (void)pSock_addr_ipx;

    if (function_hook_state_NetNowIPXLocalTarget2String == HOOK_ENABLED) {
        assert(0 && "NetNowIPXLocalTarget2String not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}

function_hook_state_t function_hook_state_GetMessageTypeFromMessage = HOOK_UNAVAILABLE;
static int(__cdecl*original_GetMessageTypeFromMessage)(char *) = (int(__cdecl*)(char *))0x00455050;
CARM95_HOOK_FUNCTION(original_GetMessageTypeFromMessage, GetMessageTypeFromMessage)
int __cdecl GetMessageTypeFromMessage(char *pMessage_str) {
    char *real_msg;
    int msg_type_int;
    LOG_TRACE("(\"%s\")", pMessage_str);

    (void)pMessage_str;
    (void)real_msg;
    (void)msg_type_int;

    if (function_hook_state_GetMessageTypeFromMessage == HOOK_ENABLED) {
        assert(0 && "GetMessageTypeFromMessage not implemented.");
        abort();
    } else {
        return original_GetMessageTypeFromMessage(pMessage_str);
    }
}

function_hook_state_t function_hook_state_SameEthernetAddress = HOOK_UNAVAILABLE;
static int(__cdecl*original_SameEthernetAddress)(_IPX_LOCAL_TARGET *, _IPX_LOCAL_TARGET *) = (int(__cdecl*)(_IPX_LOCAL_TARGET *, _IPX_LOCAL_TARGET *))0x00455119;
CARM95_HOOK_FUNCTION(original_SameEthernetAddress, SameEthernetAddress)
int __cdecl SameEthernetAddress(_IPX_LOCAL_TARGET *pAddr_ipx1, _IPX_LOCAL_TARGET *pAddr_ipx2) {
    LOG_TRACE("(%p, %p)", pAddr_ipx1, pAddr_ipx2);

    (void)pAddr_ipx1;
    (void)pAddr_ipx2;

    if (function_hook_state_SameEthernetAddress == HOOK_ENABLED) {
        assert(0 && "SameEthernetAddress not implemented.");
        abort();
    } else {
        return original_SameEthernetAddress(pAddr_ipx1, pAddr_ipx2);
    }
}

function_hook_state_t function_hook_state_GetIPXAddrFromPlayerID = HOOK_UNAVAILABLE;
_IPX_LOCAL_TARGET* GetIPXAddrFromPlayerID(tPlayer_ID pPlayer_id) {
    int i;
    tU8 *nodenum;
    LOG_TRACE("(%u)", pPlayer_id);

    (void)pPlayer_id;
    (void)i;
    (void)nodenum;

    if (function_hook_state_GetIPXAddrFromPlayerID == HOOK_ENABLED) {
        assert(0 && "GetIPXAddrFromPlayerID not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}

function_hook_state_t function_hook_state_MakeMessageToSend = HOOK_UNAVAILABLE;
static void(__cdecl*original_MakeMessageToSend)(int) = (void(__cdecl*)(int))0x00454c4c;
CARM95_HOOK_FUNCTION(original_MakeMessageToSend, MakeMessageToSend)
void __cdecl MakeMessageToSend(int pMessage_type) {
    LOG_TRACE("(%d)", pMessage_type);

    (void)pMessage_type;

    if (function_hook_state_MakeMessageToSend == HOOK_ENABLED) {
        assert(0 && "MakeMessageToSend not implemented.");
        abort();
    } else {
        original_MakeMessageToSend(pMessage_type);
    }
}

function_hook_state_t function_hook_state_ReceiveHostResponses = HOOK_UNAVAILABLE;
static int(__cdecl*original_ReceiveHostResponses)() = (int(__cdecl*)())0x00454d4d;
CARM95_HOOK_FUNCTION(original_ReceiveHostResponses, ReceiveHostResponses)
int __cdecl ReceiveHostResponses() {
    char str[256];
    int i;
    int already_registered;
    LOG_TRACE("()");

    (void)str;
    (void)i;
    (void)already_registered;

    if (function_hook_state_ReceiveHostResponses == HOOK_ENABLED) {
        assert(0 && "ReceiveHostResponses not implemented.");
        abort();
    } else {
        return original_ReceiveHostResponses();
    }
}

function_hook_state_t function_hook_state_BroadcastMessage = HOOK_UNAVAILABLE;
static int(__cdecl*original_BroadcastMessage)() = (int(__cdecl*)())0x00454c72;
CARM95_HOOK_FUNCTION(original_BroadcastMessage, BroadcastMessage)
int __cdecl BroadcastMessage() {
    int i;
    int errors;
    char broadcast_addr_string[32];
    char *real_msg;
    LOG_TRACE("()");

    (void)i;
    (void)errors;
    (void)broadcast_addr_string;
    (void)real_msg;

    if (function_hook_state_BroadcastMessage == HOOK_ENABLED) {
        assert(0 && "BroadcastMessage not implemented.");
        abort();
    } else {
        return original_BroadcastMessage();
    }
}

function_hook_state_t function_hook_state_hmiIPXCloseSocket = HOOK_UNAVAILABLE;
BOOL hmiIPXCloseSocket(W32 wSocket) {
    union REGS regs;
    struct SREGS sregs;
    LOG_TRACE("(%u)", wSocket);

    (void)wSocket;
    (void)regs;
    (void)sregs;

    if (function_hook_state_hmiIPXCloseSocket == HOOK_ENABLED) {
        assert(0 && "hmiIPXCloseSocket not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}

function_hook_state_t function_hook_state_hmiIPXListenForPacket = HOOK_UNAVAILABLE;
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

    if (function_hook_state_hmiIPXListenForPacket == HOOK_ENABLED) {
        assert(0 && "hmiIPXListenForPacket not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}

function_hook_state_t function_hook_state_hmiIPXPostListen = HOOK_UNAVAILABLE;
BOOL hmiIPXPostListen(_IPX_ECB *pECB_ptr, tU32 pOffset) {
    LOG_TRACE("(%p, %u)", pECB_ptr, pOffset);

    (void)pECB_ptr;
    (void)pOffset;

    if (function_hook_state_hmiIPXPostListen == HOOK_ENABLED) {
        assert(0 && "hmiIPXPostListen not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}

function_hook_state_t function_hook_state_hmiIPXGetData = HOOK_UNAVAILABLE;
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

    if (function_hook_state_hmiIPXGetData == HOOK_ENABLED) {
        assert(0 && "hmiIPXGetData not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}

function_hook_state_t function_hook_state_hmiIPXSendPacket = HOOK_UNAVAILABLE;
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

    if (function_hook_state_hmiIPXSendPacket == HOOK_ENABLED) {
        assert(0 && "hmiIPXSendPacket not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}

function_hook_state_t function_hook_state_hmiIPXSendDataDirect = HOOK_UNAVAILABLE;
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

    if (function_hook_state_hmiIPXSendDataDirect == HOOK_ENABLED) {
        assert(0 && "hmiIPXSendDataDirect not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}

function_hook_state_t function_hook_state_hmiIPXGetInternetworkAddr = HOOK_UNAVAILABLE;
void hmiIPXGetInternetworkAddr(_IPX_INTERNET_ADDR *sInterworkAddr) {
    struct SREGS sregs;
    union REGS regs;
    LOG_TRACE("(%p)", sInterworkAddr);

    (void)sInterworkAddr;
    (void)sregs;
    (void)regs;

    if (function_hook_state_hmiIPXGetInternetworkAddr == HOOK_ENABLED) {
        assert(0 && "hmiIPXGetInternetworkAddr not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}

function_hook_state_t function_hook_state_hmiIPXGetLocalTarget = HOOK_UNAVAILABLE;
void hmiIPXGetLocalTarget(_IPX_LOCAL_TARGET *sNetworkAddr) {
    struct SREGS sregs;
    union REGS regs;
    LOG_TRACE("(%p)", sNetworkAddr);

    (void)sNetworkAddr;
    (void)sregs;
    (void)regs;

    if (function_hook_state_hmiIPXGetLocalTarget == HOOK_ENABLED) {
        assert(0 && "hmiIPXGetLocalTarget not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}

function_hook_state_t function_hook_state_AllocateRealMem = HOOK_UNAVAILABLE;
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

    if (function_hook_state_AllocateRealMem == HOOK_ENABLED) {
        assert(0 && "AllocateRealMem not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}

function_hook_state_t function_hook_state_FreeRealMem = HOOK_UNAVAILABLE;
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

    if (function_hook_state_FreeRealMem == HOOK_ENABLED) {
        assert(0 && "FreeRealMem not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}

function_hook_state_t function_hook_state_hmiIPXInstalled = HOOK_UNAVAILABLE;
BOOL hmiIPXInstalled() {
    struct SREGS sregs;
    union REGS regs;
    LOG_TRACE("()");

    (void)sregs;
    (void)regs;

    if (function_hook_state_hmiIPXInstalled == HOOK_ENABLED) {
        assert(0 && "hmiIPXInstalled not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}

function_hook_state_t function_hook_state_hmiIPXOpenSocket = HOOK_UNAVAILABLE;
BOOL hmiIPXOpenSocket(W32 wSocket) {
    struct SREGS sregs;
    union REGS regs;
    LOG_TRACE("(%u)", wSocket);

    (void)wSocket;
    (void)sregs;
    (void)regs;

    if (function_hook_state_hmiIPXOpenSocket == HOOK_ENABLED) {
        assert(0 && "hmiIPXOpenSocket not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}

function_hook_state_t function_hook_state_GetLargestPacketSizeOoErBetterInsertLinfordChristieJokeHere = HOOK_UNAVAILABLE;
void GetLargestPacketSizeOoErBetterInsertLinfordChristieJokeHere() {
    struct SREGS sregs;
    union REGS regs;
    LOG_TRACE("()");

    (void)sregs;
    (void)regs;

    if (function_hook_state_GetLargestPacketSizeOoErBetterInsertLinfordChristieJokeHere == HOOK_ENABLED) {
        assert(0 && "GetLargestPacketSizeOoErBetterInsertLinfordChristieJokeHere not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}

function_hook_state_t function_hook_state_hmiIPXInitSystem = HOOK_UNAVAILABLE;
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

    if (function_hook_state_hmiIPXInitSystem == HOOK_ENABLED) {
        assert(0 && "hmiIPXInitSystem not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}

function_hook_state_t function_hook_state_GetIPXToStickItsEarToTheGround = HOOK_UNAVAILABLE;
void GetIPXToStickItsEarToTheGround() {
    int i;
    LOG_TRACE("()");

    (void)i;

    if (function_hook_state_GetIPXToStickItsEarToTheGround == HOOK_ENABLED) {
        assert(0 && "GetIPXToStickItsEarToTheGround not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}

function_hook_state_t function_hook_state_PDNetInitialise = HOOK_UNAVAILABLE;
static int(__cdecl*original_PDNetInitialise)() = (int(__cdecl*)())0x004543f8;
CARM95_HOOK_FUNCTION(original_PDNetInitialise, PDNetInitialise)
int __cdecl PDNetInitialise() {
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

    if (function_hook_state_PDNetInitialise == HOOK_ENABLED) {
        assert(0 && "PDNetInitialise not implemented.");
        abort();
    } else {
        return original_PDNetInitialise();
    }
}

function_hook_state_t function_hook_state_PDNetShutdown = HOOK_UNAVAILABLE;
static int(__cdecl*original_PDNetShutdown)() = (int(__cdecl*)())0x004549f2;
CARM95_HOOK_FUNCTION(original_PDNetShutdown, PDNetShutdown)
int __cdecl PDNetShutdown() {
    LOG_TRACE("()");


    if (function_hook_state_PDNetShutdown == HOOK_ENABLED) {
        assert(0 && "PDNetShutdown not implemented.");
        abort();
    } else {
        return original_PDNetShutdown();
    }
}

function_hook_state_t function_hook_state_PDNetStartProducingJoinList = HOOK_UNAVAILABLE;
static void(__cdecl*original_PDNetStartProducingJoinList)() = (void(__cdecl*)())0x00454a33;
CARM95_HOOK_FUNCTION(original_PDNetStartProducingJoinList, PDNetStartProducingJoinList)
void __cdecl PDNetStartProducingJoinList() {
    LOG_TRACE("()");


    if (function_hook_state_PDNetStartProducingJoinList == HOOK_ENABLED) {
        assert(0 && "PDNetStartProducingJoinList not implemented.");
        abort();
    } else {
        original_PDNetStartProducingJoinList();
    }
}

function_hook_state_t function_hook_state_PDNetEndJoinList = HOOK_UNAVAILABLE;
static void(__cdecl*original_PDNetEndJoinList)() = (void(__cdecl*)())0x00454a86;
CARM95_HOOK_FUNCTION(original_PDNetEndJoinList, PDNetEndJoinList)
void __cdecl PDNetEndJoinList() {
    LOG_TRACE("()");


    if (function_hook_state_PDNetEndJoinList == HOOK_ENABLED) {
        assert(0 && "PDNetEndJoinList not implemented.");
        abort();
    } else {
        original_PDNetEndJoinList();
    }
}

function_hook_state_t function_hook_state_PDNetGetNextJoinGame = HOOK_UNAVAILABLE;
static int(__cdecl*original_PDNetGetNextJoinGame)(tNet_game_details *, int) = (int(__cdecl*)(tNet_game_details *, int))0x00454ac3;
CARM95_HOOK_FUNCTION(original_PDNetGetNextJoinGame, PDNetGetNextJoinGame)
int __cdecl PDNetGetNextJoinGame(tNet_game_details *pGame, int pIndex) {
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

    if (function_hook_state_PDNetGetNextJoinGame == HOOK_ENABLED) {
        assert(0 && "PDNetGetNextJoinGame not implemented.");
        abort();
    } else {
        return original_PDNetGetNextJoinGame(pGame, pIndex);
    }
}

function_hook_state_t function_hook_state_PDNetDisposeGameDetails = HOOK_UNAVAILABLE;
static void(__cdecl*original_PDNetDisposeGameDetails)(tNet_game_details *) = (void(__cdecl*)(tNet_game_details *))0x00455161;
CARM95_HOOK_FUNCTION(original_PDNetDisposeGameDetails, PDNetDisposeGameDetails)
void __cdecl PDNetDisposeGameDetails(tNet_game_details *pDetails) {
    LOG_TRACE("(%p)", pDetails);

    (void)pDetails;

    if (function_hook_state_PDNetDisposeGameDetails == HOOK_ENABLED) {
        assert(0 && "PDNetDisposeGameDetails not implemented.");
        abort();
    } else {
        original_PDNetDisposeGameDetails(pDetails);
    }
}

function_hook_state_t function_hook_state_PDNetHostGame = HOOK_UNAVAILABLE;
static int(__cdecl*original_PDNetHostGame)(tNet_game_details *, char *, void **) = (int(__cdecl*)(tNet_game_details *, char *, void **))0x00455179;
CARM95_HOOK_FUNCTION(original_PDNetHostGame, PDNetHostGame)
int __cdecl PDNetHostGame(tNet_game_details *pDetails, char *pHost_name, void **pHost_address) {
    LOG_TRACE("(%p, \"%s\", %p)", pDetails, pHost_name, pHost_address);

    (void)pDetails;
    (void)pHost_name;
    (void)pHost_address;

    if (function_hook_state_PDNetHostGame == HOOK_ENABLED) {
        assert(0 && "PDNetHostGame not implemented.");
        abort();
    } else {
        return original_PDNetHostGame(pDetails, pHost_name, pHost_address);
    }
}

function_hook_state_t function_hook_state_PDNetJoinGame = HOOK_UNAVAILABLE;
static int(__cdecl*original_PDNetJoinGame)(tNet_game_details *, char *) = (int(__cdecl*)(tNet_game_details *, char *))0x004551a4;
CARM95_HOOK_FUNCTION(original_PDNetJoinGame, PDNetJoinGame)
int __cdecl PDNetJoinGame(tNet_game_details *pDetails, char *pPlayer_name) {
    LOG_TRACE("(%p, \"%s\")", pDetails, pPlayer_name);

    (void)pDetails;
    (void)pPlayer_name;

    if (function_hook_state_PDNetJoinGame == HOOK_ENABLED) {
        assert(0 && "PDNetJoinGame not implemented.");
        abort();
    } else {
        return original_PDNetJoinGame(pDetails, pPlayer_name);
    }
}

function_hook_state_t function_hook_state_PDNetLeaveGame = HOOK_UNAVAILABLE;
static void(__cdecl*original_PDNetLeaveGame)(tNet_game_details *) = (void(__cdecl*)(tNet_game_details *))0x004551c3;
CARM95_HOOK_FUNCTION(original_PDNetLeaveGame, PDNetLeaveGame)
void __cdecl PDNetLeaveGame(tNet_game_details *pDetails) {
    LOG_TRACE("(%p)", pDetails);

    (void)pDetails;

    if (function_hook_state_PDNetLeaveGame == HOOK_ENABLED) {
        assert(0 && "PDNetLeaveGame not implemented.");
        abort();
    } else {
        original_PDNetLeaveGame(pDetails);
    }
}

function_hook_state_t function_hook_state_PDNetHostFinishGame = HOOK_UNAVAILABLE;
static void(__cdecl*original_PDNetHostFinishGame)(tNet_game_details *) = (void(__cdecl*)(tNet_game_details *))0x004551db;
CARM95_HOOK_FUNCTION(original_PDNetHostFinishGame, PDNetHostFinishGame)
void __cdecl PDNetHostFinishGame(tNet_game_details *pDetails) {
    LOG_TRACE("(%p)", pDetails);

    (void)pDetails;

    if (function_hook_state_PDNetHostFinishGame == HOOK_ENABLED) {
        assert(0 && "PDNetHostFinishGame not implemented.");
        abort();
    } else {
        original_PDNetHostFinishGame(pDetails);
    }
}

function_hook_state_t function_hook_state_PDNetExtractGameID = HOOK_UNAVAILABLE;
static tU32(__cdecl*original_PDNetExtractGameID)(tNet_game_details *) = (tU32(__cdecl*)(tNet_game_details *))0x004551f3;
CARM95_HOOK_FUNCTION(original_PDNetExtractGameID, PDNetExtractGameID)
tU32 __cdecl PDNetExtractGameID(tNet_game_details *pDetails) {
    LOG_TRACE("(%p)", pDetails);

    (void)pDetails;

    if (function_hook_state_PDNetExtractGameID == HOOK_ENABLED) {
        assert(0 && "PDNetExtractGameID not implemented.");
        abort();
    } else {
        return original_PDNetExtractGameID(pDetails);
    }
}

function_hook_state_t function_hook_state_PDNetExtractPlayerID = HOOK_UNAVAILABLE;
static tPlayer_ID(__cdecl*original_PDNetExtractPlayerID)(tNet_game_details *) = (tPlayer_ID(__cdecl*)(tNet_game_details *))0x00455277;
CARM95_HOOK_FUNCTION(original_PDNetExtractPlayerID, PDNetExtractPlayerID)
tPlayer_ID __cdecl PDNetExtractPlayerID(tNet_game_details *pDetails) {
    LOG_TRACE("(%p)", pDetails);

    (void)pDetails;

    if (function_hook_state_PDNetExtractPlayerID == HOOK_ENABLED) {
        assert(0 && "PDNetExtractPlayerID not implemented.");
        abort();
    } else {
        return original_PDNetExtractPlayerID(pDetails);
    }
}

function_hook_state_t function_hook_state_PDNetObtainSystemUserName = HOOK_UNAVAILABLE;
static void(__cdecl*original_PDNetObtainSystemUserName)(char *, int) = (void(__cdecl*)(char *, int))0x004552be;
CARM95_HOOK_FUNCTION(original_PDNetObtainSystemUserName, PDNetObtainSystemUserName)
void __cdecl PDNetObtainSystemUserName(char *pName, int pMax_length) {
    LOG_TRACE("(\"%s\", %d)", pName, pMax_length);

    (void)pName;
    (void)pMax_length;

    if (function_hook_state_PDNetObtainSystemUserName == HOOK_ENABLED) {
        assert(0 && "PDNetObtainSystemUserName not implemented.");
        abort();
    } else {
        original_PDNetObtainSystemUserName(pName, pMax_length);
    }
}

function_hook_state_t function_hook_state_PDNetSendMessageToPlayer = HOOK_UNAVAILABLE;
static int(__cdecl*original_PDNetSendMessageToPlayer)(tNet_game_details *, tNet_message *, tPlayer_ID) = (int(__cdecl*)(tNet_game_details *, tNet_message *, tPlayer_ID))0x00455349;
CARM95_HOOK_FUNCTION(original_PDNetSendMessageToPlayer, PDNetSendMessageToPlayer)
int __cdecl PDNetSendMessageToPlayer(tNet_game_details *pDetails, tNet_message *pMessage, tPlayer_ID pPlayer) {
    char str[256];
    _IPX_LOCAL_TARGET *remote_addr_ipx;
    LOG_TRACE("(%p, %p, %u)", pDetails, pMessage, pPlayer);

    (void)pDetails;
    (void)pMessage;
    (void)pPlayer;
    (void)str;
    (void)remote_addr_ipx;

    if (function_hook_state_PDNetSendMessageToPlayer == HOOK_ENABLED) {
        assert(0 && "PDNetSendMessageToPlayer not implemented.");
        abort();
    } else {
        return original_PDNetSendMessageToPlayer(pDetails, pMessage, pPlayer);
    }
}

function_hook_state_t function_hook_state_PDNetSendMessageToAllPlayers = HOOK_UNAVAILABLE;
static int(__cdecl*original_PDNetSendMessageToAllPlayers)(tNet_game_details *, tNet_message *) = (int(__cdecl*)(tNet_game_details *, tNet_message *))0x004553de;
CARM95_HOOK_FUNCTION(original_PDNetSendMessageToAllPlayers, PDNetSendMessageToAllPlayers)
int __cdecl PDNetSendMessageToAllPlayers(tNet_game_details *pDetails, tNet_message *pMessage) {
    char str[256];
    int i;
    LOG_TRACE("(%p, %p)", pDetails, pMessage);

    (void)pDetails;
    (void)pMessage;
    (void)str;
    (void)i;

    if (function_hook_state_PDNetSendMessageToAllPlayers == HOOK_ENABLED) {
        assert(0 && "PDNetSendMessageToAllPlayers not implemented.");
        abort();
    } else {
        return original_PDNetSendMessageToAllPlayers(pDetails, pMessage);
    }
}

function_hook_state_t function_hook_state_PDNetGetNextMessage = HOOK_UNAVAILABLE;
static tNet_message *(__cdecl*original_PDNetGetNextMessage)(tNet_game_details *, void **) = (tNet_message *(__cdecl*)(tNet_game_details *, void **))0x00455495;
CARM95_HOOK_FUNCTION(original_PDNetGetNextMessage, PDNetGetNextMessage)
tNet_message* __cdecl PDNetGetNextMessage(tNet_game_details *pDetails, void **pSender_address) {
    char *receive_buffer;
    char str[256];
    int msg_type;
    LOG_TRACE("(%p, %p)", pDetails, pSender_address);

    (void)pDetails;
    (void)pSender_address;
    (void)receive_buffer;
    (void)str;
    (void)msg_type;

    if (function_hook_state_PDNetGetNextMessage == HOOK_ENABLED) {
        assert(0 && "PDNetGetNextMessage not implemented.");
        abort();
    } else {
        return original_PDNetGetNextMessage(pDetails, pSender_address);
    }
}

function_hook_state_t function_hook_state_PDNetAllocateMessage = HOOK_UNAVAILABLE;
static tNet_message *(__cdecl*original_PDNetAllocateMessage)(tU32, tS32) = (tNet_message *(__cdecl*)(tU32, tS32))0x00455730;
CARM95_HOOK_FUNCTION(original_PDNetAllocateMessage, PDNetAllocateMessage)
tNet_message* __cdecl PDNetAllocateMessage(tU32 pSize, tS32 pSize_decider) {
    LOG_TRACE("(%u, %d)", pSize, pSize_decider);

    (void)pSize;
    (void)pSize_decider;

    if (function_hook_state_PDNetAllocateMessage == HOOK_ENABLED) {
        assert(0 && "PDNetAllocateMessage not implemented.");
        abort();
    } else {
        return original_PDNetAllocateMessage(pSize, pSize_decider);
    }
}

function_hook_state_t function_hook_state_PDNetDisposeMessage = HOOK_UNAVAILABLE;
void PDNetDisposeMessage(tNet_game_details *pDetails, tNet_message *pMessage) {
    LOG_TRACE("(%p, %p)", pDetails, pMessage);

    (void)pDetails;
    (void)pMessage;

    if (function_hook_state_PDNetDisposeMessage == HOOK_ENABLED) {
        assert(0 && "PDNetDisposeMessage not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}

function_hook_state_t function_hook_state_PDNetSetPlayerSystemInfo = HOOK_UNAVAILABLE;
static void(__cdecl*original_PDNetSetPlayerSystemInfo)(tNet_game_player_info *, void *) = (void(__cdecl*)(tNet_game_player_info *, void *))0x0045576c;
CARM95_HOOK_FUNCTION(original_PDNetSetPlayerSystemInfo, PDNetSetPlayerSystemInfo)
void __cdecl PDNetSetPlayerSystemInfo(tNet_game_player_info *pPlayer, void *pSender_address) {
    LOG_TRACE("(%p, %p)", pPlayer, pSender_address);

    (void)pPlayer;
    (void)pSender_address;

    if (function_hook_state_PDNetSetPlayerSystemInfo == HOOK_ENABLED) {
        assert(0 && "PDNetSetPlayerSystemInfo not implemented.");
        abort();
    } else {
        original_PDNetSetPlayerSystemInfo(pPlayer, pSender_address);
    }
}

function_hook_state_t function_hook_state_PDNetDisposePlayer = HOOK_UNAVAILABLE;
static void(__cdecl*original_PDNetDisposePlayer)(tNet_game_player_info *) = (void(__cdecl*)(tNet_game_player_info *))0x004557a2;
CARM95_HOOK_FUNCTION(original_PDNetDisposePlayer, PDNetDisposePlayer)
void __cdecl PDNetDisposePlayer(tNet_game_player_info *pPlayer) {
    LOG_TRACE("(%p)", pPlayer);

    (void)pPlayer;

    if (function_hook_state_PDNetDisposePlayer == HOOK_ENABLED) {
        assert(0 && "PDNetDisposePlayer not implemented.");
        abort();
    } else {
        original_PDNetDisposePlayer(pPlayer);
    }
}

function_hook_state_t function_hook_state_PDNetSendMessageToAddress = HOOK_UNAVAILABLE;
static int(__cdecl*original_PDNetSendMessageToAddress)(tNet_game_details *, tNet_message *, void *) = (int(__cdecl*)(tNet_game_details *, tNet_message *, void *))0x004557ba;
CARM95_HOOK_FUNCTION(original_PDNetSendMessageToAddress, PDNetSendMessageToAddress)
int __cdecl PDNetSendMessageToAddress(tNet_game_details *pDetails, tNet_message *pMessage, void *pAddress) {
    char str[256];
    LOG_TRACE("(%p, %p, %p)", pDetails, pMessage, pAddress);

    (void)pDetails;
    (void)pMessage;
    (void)pAddress;
    (void)str;

    if (function_hook_state_PDNetSendMessageToAddress == HOOK_ENABLED) {
        assert(0 && "PDNetSendMessageToAddress not implemented.");
        abort();
    } else {
        return original_PDNetSendMessageToAddress(pDetails, pMessage, pAddress);
    }
}

function_hook_state_t function_hook_state_PDNetInitClient = HOOK_UNAVAILABLE;
static int(__cdecl*original_PDNetInitClient)(tNet_game_details *) = (int(__cdecl*)(tNet_game_details *))0x00455838;
CARM95_HOOK_FUNCTION(original_PDNetInitClient, PDNetInitClient)
int __cdecl PDNetInitClient(tNet_game_details *pDetails) {
    LOG_TRACE("(%p)", pDetails);

    (void)pDetails;

    if (function_hook_state_PDNetInitClient == HOOK_ENABLED) {
        assert(0 && "PDNetInitClient not implemented.");
        abort();
    } else {
        return original_PDNetInitClient(pDetails);
    }
}

function_hook_state_t function_hook_state_PDNetGetHeaderSize = HOOK_UNAVAILABLE;
static int(__cdecl*original_PDNetGetHeaderSize)() = (int(__cdecl*)())0x00455857;
CARM95_HOOK_FUNCTION(original_PDNetGetHeaderSize, PDNetGetHeaderSize)
int __cdecl PDNetGetHeaderSize() {
    LOG_TRACE("()");


    if (function_hook_state_PDNetGetHeaderSize == HOOK_ENABLED) {
        assert(0 && "PDNetGetHeaderSize not implemented.");
        abort();
    } else {
        return original_PDNetGetHeaderSize();
    }
}

