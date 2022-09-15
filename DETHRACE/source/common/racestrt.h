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

void DrawRaceList(int pOffset);

void MoveRaceList(int pFrom, int pTo, tS32 pTime_to_move);

int UpRace(int *pCurrent_choice, int *pCurrent_mode);

int DownRace(int *pCurrent_choice, int *pCurrent_mode);

int ClickOnRace(int *pCurrent_choice, int *pCurrent_mode, int pX_offset, int pY_offset);

int UpClickRace(int *pCurrent_choice, int *pCurrent_mode, int pX_offset, int pY_offset);

int DownClickRace(int *pCurrent_choice, int *pCurrent_mode, int pX_offset, int pY_offset);

void StartChangeRace();

int ChangeRace(int *pRace_index, int pNet_mode, tNet_sequence_type pNet_race_sequence);

void DoChangeRace();

void DrawCar(int pCurrent_choice, int pCurrent_mode);

void SetCarFlic();

int UpCar(int *pCurrent_choice, int *pCurrent_mode);

int DownCar(int *pCurrent_choice, int *pCurrent_mode);

int UpClickCar(int *pCurrent_choice, int *pCurrent_mode, int pX_offset, int pY_offset);

int DownClickCar(int *pCurrent_choice, int *pCurrent_mode, int pX_offset, int pY_offset);

int ChangeCarGoAhead(int *pCurrent_choice, int *pCurrent_mode);

int ChangeCar(int pNet_mode, int *pCar_index, tNet_game_details *pNet_game);

void DoChangeCar();

int PartsShopRecommended();

void CalcPartPrice(int pCategory, int pIndex, int *pPrice, int *pCost);

int BuyPart(int pCategory, int pIndex);

void DoAutoParts();

void DrawPartsLabel();

void ErasePartsText(int pTotal_as_well);

void DrawPartsText();

void SetPartsImage();

int GetPartsMax();

void CalcPartsIndex();

void DoExchangePart();

int PartsShopGoAhead(int *pCurrent_choice, int *pCurrent_mode);

int UpPart(int *pCurrent_choice, int *pCurrent_mode);

int DownPart(int *pCurrent_choice, int *pCurrent_mode);

int UpClickPart(int *pCurrent_choice, int *pCurrent_mode, int pX_offset, int pY_offset);

int DownClickPart(int *pCurrent_choice, int *pCurrent_mode, int pX_offset, int pY_offset);

int PartsArrowsOn(int *pCurrent_choice, int *pCurrent_mode);

int PartsArrowsOff(int *pCurrent_choice, int *pCurrent_mode);

void StartPartsShop();

int DonePartsShop(int pCurrent_choice, int pCurrent_mode, int pGo_ahead, int pEscaped, int pTimed_out);

void DrawPartsShop(int pCurrent_choice, int pCurrent_mode);

void DoPartsShop(int pFade_away);

int AutoPartsDone(int pCurrent_choice, int pCurrent_mode, int pGo_ahead, int pEscaped, int pTimed_out);

tSO_result DoAutoPartsShop();

void SetOpponentFlic();

void DrawSceneyMappyInfoVieweyThing();

void DismissSceneyMappyInfoVieweyThing();

int SelectRaceDone(int pCurrent_choice, int pCurrent_mode, int pGo_ahead, int pEscaped, int pTimed_out);

int StartRaceGoAhead(int *pCurrent_choice, int *pCurrent_mode);

int TryToMoveToArrows(int *pCurrent_choice, int *pCurrent_mode);

int UpOpponent(int *pCurrent_choice, int *pCurrent_mode);

int DownOpponent(int *pCurrent_choice, int *pCurrent_mode);

int UpClickOpp(int *pCurrent_choice, int *pCurrent_mode, int pX_offset, int pY_offset);

int DownClickOpp(int *pCurrent_choice, int *pCurrent_mode, int pX_offset, int pY_offset);

void SelectRaceStart();

int SuggestRace();

void SelectRaceDraw(int pCurrent_choice, int pCurrent_mode);

tSO_result DoSelectRace(int *pSecond_time_around);

void DrawGridCar(int pX, int pY, br_pixelmap *pImage);

void DrawGrid(int pOffset, int pDraw_it);

void MoveGrid(int pFrom, int pTo, tS32 pTime_to_move);

int CalcGridOffset(int pPosition);

void GridDraw(int pCurrent_choice, int pCurrent_mode);

void ActuallySwapOrder(int pFirst_index, int pSecond_index);

void DoGridTransition(int pFirst_index, int pSecond_index);

void ChallengeStart();

int CheckNextStage(int *pCurrent_choice, int *pCurrent_mode);

int ChallengeDone(int pCurrent_choice, int pCurrent_mode, int pGo_ahead, int pEscaped, int pTimed_out);

void DoChallengeScreen();

int GridDone(int pCurrent_choice, int pCurrent_mode, int pGo_ahead, int pEscaped, int pTimed_out);

void GridStart();

int GridMoveLeft(int *pCurrent_choice, int *pCurrent_mode);

int GridMoveRight(int *pCurrent_choice, int *pCurrent_mode);

int GridClickCar(int *pCurrent_choice, int *pCurrent_mode, int pX_offset, int pY_offset);

int GridClickNumbers(int *pCurrent_choice, int *pCurrent_mode, int pX_offset, int pY_offset);

int GridClickLeft(int *pCurrent_choice, int *pCurrent_mode, int pX_offset, int pY_offset);

int GridClickRight(int *pCurrent_choice, int *pCurrent_mode, int pX_offset, int pY_offset);

int CheckChallenge(int *pCurrent_choice, int *pCurrent_mode);

int FindBestPos(int pOur_rank);

int SortGridFunction(void *pFirst_one, void *pSecond_one);

void SortOpponents();

tSO_result DoGridPosition();

void CheckPlayersAreResponding();

void NetSynchStartStart();

void DrawAnItem__racestrt(int pX, int pY_index, int pFont_index, char *pText);

void NetSynchStartDraw(int pCurrent_choice, int pCurrent_mode);

int NetSynchStartDone(int pCurrent_choice, int pCurrent_mode, int pGo_ahead, int pEscaped, int pTimed_out);

int NetSynchStartGoAhead(int *pCurrent_choice, int *pCurrent_mode);

int ExitWhenReady(int *pCurrent_choice, int *pCurrent_mode);

tSO_result NetSynchRaceStart2(tNet_synch_mode pMode);

tSO_result NetSynchRaceStart();

#endif
