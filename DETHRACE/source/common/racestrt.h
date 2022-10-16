#ifndef _RACESTRT_H_
#define _RACESTRT_H_

#include "br_types.h"
#include "dr_types.h"

extern int(* hookvar_gGrid_number_colour )[4]; // addr: 0050F198
extern int * hookvar_gJust_bought_part ; // addr: 0050F1A8
// extern tU32 * hookvar_gLast_host_query ;
extern br_pixelmap ** hookvar_gDead_car ; // addr: 00550ACC
extern int * hookvar_gFade_away_parts_shop ; // addr: 00536408
extern tU32 * hookvar_gDare_start_time ; // addr: 0053635C
extern int * hookvar_gRefund_rate ; // addr: 00536418
extern int * hookvar_gSwap_grid_2 ; // addr: 0053640C
extern int * hookvar_gSwap_grid_1 ; // addr: 00536410
extern int * hookvar_gChange_race_net_mode ; // addr: 005363F0
extern tParts_category * hookvar_gPart_category ; // addr: 0053641C
// extern tU32 * hookvar_gNet_synch_start ;
extern tNet_game_details ** hookvar_gChoose_car_net_game ; // addr: 0053634C
extern int * hookvar_gPart_index ; // addr: 00536404
extern int * hookvar_gChallenger_index__racestrt ; // addr: 0053636C // suffix added to avoid duplicate symbol
extern tGrid_draw * hookvar_gDraw_grid_status ; // addr: 00536360
extern tNet_sequence_type * hookvar_gNet_race_sequence__racestrt ; // addr: 005363EC // suffix added to avoid duplicate symbol
extern br_pixelmap ** hookvar_gTaken_image ; // addr: 0053642C
extern int(* hookvar_gGrid_number_x_coords )[31]; // addr: 00536370
extern int * hookvar_gGrid_transition_stage ; // addr: 005363F4
extern int * hookvar_gGrid_y_adjust ; // addr: 00536428
extern br_pixelmap ** hookvar_gBullet_image ; // addr: 00536400
extern br_pixelmap ** hookvar_gDeceased_image ; // addr: 005363F8
extern int * hookvar_gBest_pos_available ; // addr: 00536364
extern int * hookvar_gChallenger_position ; // addr: 00536358
extern int * hookvar_gOpponent_index ; // addr: 00536414
extern int * hookvar_gChallenge_time ; // addr: 005363FC
extern int * hookvar_gOriginal_position ; // addr: 00536354
extern int * hookvar_gCurrent_race_index ; // addr: 00536420
extern tInterface_spec ** hookvar_gStart_interface_spec ; // addr: 00536350
extern int * hookvar_gCurrent_car_index ; // addr: 00536424
extern int * hookvar_gOur_starting_position ; // addr: 00536368

void __cdecl DrawRaceList(int pOffset);

void __cdecl MoveRaceList(int pFrom, int pTo, tS32 pTime_to_move);

int __cdecl UpRace(int *pCurrent_choice, int *pCurrent_mode);

int __cdecl DownRace(int *pCurrent_choice, int *pCurrent_mode);

int __cdecl ClickOnRace(int *pCurrent_choice, int *pCurrent_mode, int pX_offset, int pY_offset);

int __cdecl UpClickRace(int *pCurrent_choice, int *pCurrent_mode, int pX_offset, int pY_offset);

int __cdecl DownClickRace(int *pCurrent_choice, int *pCurrent_mode, int pX_offset, int pY_offset);

void __cdecl StartChangeRace();

int __cdecl ChangeRace(int *pRace_index, int pNet_mode, tNet_sequence_type pNet_race_sequence);

void __cdecl DoChangeRace();

void __cdecl DrawCar(int pCurrent_choice, int pCurrent_mode);

void __cdecl SetCarFlic();

int __cdecl UpCar(int *pCurrent_choice, int *pCurrent_mode);

int __cdecl DownCar(int *pCurrent_choice, int *pCurrent_mode);

int __cdecl UpClickCar(int *pCurrent_choice, int *pCurrent_mode, int pX_offset, int pY_offset);

int __cdecl DownClickCar(int *pCurrent_choice, int *pCurrent_mode, int pX_offset, int pY_offset);

int __cdecl ChangeCarGoAhead(int *pCurrent_choice, int *pCurrent_mode);

int __cdecl ChangeCar(int pNet_mode, int *pCar_index, tNet_game_details *pNet_game);

void __cdecl DoChangeCar();

int __cdecl PartsShopRecommended();

void __cdecl CalcPartPrice(int pCategory, int pIndex, int *pPrice, int *pCost);

int __cdecl BuyPart(int pCategory, int pIndex);

void __cdecl DoAutoParts();

void __cdecl DrawPartsLabel();

void __cdecl ErasePartsText(int pTotal_as_well);

void __cdecl DrawPartsText();

void __cdecl SetPartsImage();

int __cdecl GetPartsMax();

void __cdecl CalcPartsIndex();

void __cdecl DoExchangePart();

int __cdecl PartsShopGoAhead(int *pCurrent_choice, int *pCurrent_mode);

int __cdecl UpPart(int *pCurrent_choice, int *pCurrent_mode);

int __cdecl DownPart(int *pCurrent_choice, int *pCurrent_mode);

int __cdecl UpClickPart(int *pCurrent_choice, int *pCurrent_mode, int pX_offset, int pY_offset);

int __cdecl DownClickPart(int *pCurrent_choice, int *pCurrent_mode, int pX_offset, int pY_offset);

int __cdecl PartsArrowsOn(int *pCurrent_choice, int *pCurrent_mode);

int __cdecl PartsArrowsOff(int *pCurrent_choice, int *pCurrent_mode);

void __cdecl StartPartsShop();

int __cdecl DonePartsShop(int pCurrent_choice, int pCurrent_mode, int pGo_ahead, int pEscaped, int pTimed_out);

void __cdecl DrawPartsShop(int pCurrent_choice, int pCurrent_mode);

void __cdecl DoPartsShop(int pFade_away);

int __cdecl AutoPartsDone(int pCurrent_choice, int pCurrent_mode, int pGo_ahead, int pEscaped, int pTimed_out);

tSO_result __cdecl DoAutoPartsShop();

void __cdecl SetOpponentFlic();

void __cdecl DrawSceneyMappyInfoVieweyThing();

void __cdecl DismissSceneyMappyInfoVieweyThing();

int __cdecl SelectRaceDone(int pCurrent_choice, int pCurrent_mode, int pGo_ahead, int pEscaped, int pTimed_out);

int __cdecl StartRaceGoAhead(int *pCurrent_choice, int *pCurrent_mode);

int TryToMoveToArrows(int *pCurrent_choice, int *pCurrent_mode);

int __cdecl UpOpponent(int *pCurrent_choice, int *pCurrent_mode);

int __cdecl DownOpponent(int *pCurrent_choice, int *pCurrent_mode);

int __cdecl UpClickOpp(int *pCurrent_choice, int *pCurrent_mode, int pX_offset, int pY_offset);

int __cdecl DownClickOpp(int *pCurrent_choice, int *pCurrent_mode, int pX_offset, int pY_offset);

void __cdecl SelectRaceStart();

int __cdecl SuggestRace();

void __cdecl SelectRaceDraw(int pCurrent_choice, int pCurrent_mode);

tSO_result __cdecl DoSelectRace(int *pSecond_time_around);

void __cdecl DrawGridCar(int pX, int pY, br_pixelmap *pImage);

void __cdecl DrawGrid(int pOffset, int pDraw_it);

void __cdecl MoveGrid(int pFrom, int pTo, tS32 pTime_to_move);

int __cdecl CalcGridOffset(int pPosition);

void __cdecl GridDraw(int pCurrent_choice, int pCurrent_mode);

void __cdecl ActuallySwapOrder(int pFirst_index, int pSecond_index);

void __cdecl DoGridTransition(int pFirst_index, int pSecond_index);

void __cdecl ChallengeStart();

int __cdecl CheckNextStage(int *pCurrent_choice, int *pCurrent_mode);

int __cdecl ChallengeDone(int pCurrent_choice, int pCurrent_mode, int pGo_ahead, int pEscaped, int pTimed_out);

void __cdecl DoChallengeScreen();

int __cdecl GridDone(int pCurrent_choice, int pCurrent_mode, int pGo_ahead, int pEscaped, int pTimed_out);

void __cdecl GridStart();

int __cdecl GridMoveLeft(int *pCurrent_choice, int *pCurrent_mode);

int __cdecl GridMoveRight(int *pCurrent_choice, int *pCurrent_mode);

int __cdecl GridClickCar(int *pCurrent_choice, int *pCurrent_mode, int pX_offset, int pY_offset);

int __cdecl GridClickNumbers(int *pCurrent_choice, int *pCurrent_mode, int pX_offset, int pY_offset);

int __cdecl GridClickLeft(int *pCurrent_choice, int *pCurrent_mode, int pX_offset, int pY_offset);

int __cdecl GridClickRight(int *pCurrent_choice, int *pCurrent_mode, int pX_offset, int pY_offset);

int __cdecl CheckChallenge(int *pCurrent_choice, int *pCurrent_mode);

int __cdecl FindBestPos(int pOur_rank);

int __cdecl SortGridFunction(void *pFirst_one, void *pSecond_one);

void __cdecl SortOpponents();

tSO_result __cdecl DoGridPosition();

void __cdecl CheckPlayersAreResponding();

void __cdecl NetSynchStartStart();

void __cdecl DrawAnItem__racestrt(int pX, int pY_index, int pFont_index, char *pText);

void __cdecl NetSynchStartDraw(int pCurrent_choice, int pCurrent_mode);

int __cdecl NetSynchStartDone(int pCurrent_choice, int pCurrent_mode, int pGo_ahead, int pEscaped, int pTimed_out);

int __cdecl NetSynchStartGoAhead(int *pCurrent_choice, int *pCurrent_mode);

int __cdecl ExitWhenReady(int *pCurrent_choice, int *pCurrent_mode);

tSO_result __cdecl NetSynchRaceStart2(tNet_synch_mode pMode);

tSO_result __cdecl NetSynchRaceStart();

#endif
