#ifndef _NETGAME_H_
#define _NETGAME_H_

#include "br_types.h"
#include "dr_types.h"

extern int(* hookvar_gPowerup_cost )[4]; // addr: 0050C5E0
// extern int(* hookvar_gGame_scores )[6];
extern int * hookvar_gPed_target ; // addr: 0053220C
extern int * hookvar_gNot_shown_race_type_headup ; // addr: 00532210
extern tU32 * hookvar_gLast_it_change ; // addr: 00532204
extern tU32 * hookvar_gTime_for_punishment ; // addr: 00532208
extern tNet_game_player_info ** hookvar_gLast_lepper ; // addr: 00532200
extern int * hookvar_gInitialised_grid ; // addr: 00551D7C
extern int * hookvar_gIt_or_fox ; // addr: 00551D80

void __cdecl SendCarData(tU32 pNext_frame_time);

void __cdecl ReceivedRecover(tNet_contents *pContents);

void __cdecl CopyMechanics(tCar_spec *pCar, tNet_contents *pContents);

void __cdecl ReceivedMechanics(tNet_contents *pContents);

void __cdecl ReceivedCopInfo(tNet_contents *pContents);

void SendAllNonCarPositions();

void __cdecl ReceivedNonCarPosition(tNet_contents *pContents);

void __cdecl ReceivedNonCar(tNet_contents *pContents);

void __cdecl SignalToStartRace2(int pIndex);

void __cdecl SignalToStartRace();

void __cdecl SetUpNetCarPositions();

void __cdecl ReinitialiseCar(tCar_spec *pCar);

void __cdecl RepositionPlayer(int pIndex);

void __cdecl DisableCar(tCar_spec *pCar);

void __cdecl EnableCar(tCar_spec *pCar);

void __cdecl DoNetworkHeadups(int pCredits);

int __cdecl SortNetHeadAscending(void *pFirst_one, void *pSecond_one);

int __cdecl SortNetHeadDescending(void *pFirst_one, void *pSecond_one);

void __cdecl ClipName(char *pName, tDR_font *pFont, int pMax_width);

void __cdecl DoNetScores2(int pOnly_sort_scores);

void __cdecl DoNetScores();

void __cdecl InitNetHeadups();

void __cdecl DisposeNetHeadups();

void __cdecl EverybodysLost();

void __cdecl DeclareWinner(int pWinner_index);

void __cdecl PlayerIsIt(tNet_game_player_info *pPlayer);

int __cdecl FarEnoughAway(tNet_game_player_info *pPlayer_1, tNet_game_player_info *pPlayer_2);

void __cdecl CarInContactWithItOrFox(tNet_game_player_info *pPlayer);

void __cdecl SelectRandomItOrFox(int pNot_this_one);

void __cdecl CalcPlayerScores();

void __cdecl SendPlayerScores();

void __cdecl DoNetGameManagement();

void __cdecl InitialisePlayerScore(tNet_game_player_info *pPlayer);

void __cdecl InitPlayers();

void __cdecl BuyPSPowerup(int pIndex);

void __cdecl BuyArmour();

void __cdecl BuyPower();

void __cdecl BuyOffense();

void __cdecl UseGeneralScore(int pScore);

void __cdecl NetSendEnvironmentChanges(tNet_game_player_info *pPlayer);

void __cdecl UpdateEnvironments();

void __cdecl ReceivedGameplay(tNet_contents *pContents, tNet_message *pMessage, tU32 pReceive_time);

void __cdecl SendGameplay(tPlayer_ID pPlayer, tNet_gameplay_mess pMess, int pParam_1, int pParam_2, int pParam_3, int pParam_4);

void __cdecl SendGameplayToAllPlayers(tNet_gameplay_mess pMess, int pParam_1, int pParam_2, int pParam_3, int pParam_4);

void __cdecl SendGameplayToHost(tNet_gameplay_mess pMess, int pParam_1, int pParam_2, int pParam_3, int pParam_4);

void __cdecl InitNetGameplayStuff();

void __cdecl DefaultNetName();

void __cdecl NetSendPointCrush(tCar_spec *pCar, tU16 pCrush_point_index, br_vector3 *pEnergy_vector);

void __cdecl RecievedCrushPoint(tNet_contents *pContents);

void __cdecl GetReducedMatrix(tReduced_matrix *m1, br_matrix34 *m2);

void __cdecl GetExpandedMatrix(br_matrix34 *m1, tReduced_matrix *m2);

void __cdecl NetEarnCredits(tNet_game_player_info *pPlayer, tS32 pCredits);

#endif
