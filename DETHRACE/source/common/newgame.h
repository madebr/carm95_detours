#ifndef _NEWGAME_H_
#define _NEWGAME_H_

#include "br_types.h"
#include "dr_types.h"

extern tU8 ** hookvar_gFrank_flic_data ; // addr: 0051E910
extern tU8 ** hookvar_gAnne_flic_data ; // addr: 0051E914
extern int * hookvar_gNet_storage_allocated ; // addr: 0051E918
extern tRadio_bastards(* hookvar_gRadio_bastards__newgame )[11]; // addr: 0051E920 // suffix added to avoid duplicate symbol
extern char *(* hookvar_gBasic_car_names )[2]; // addr: 0051EA80
extern tNet_game_options(* hookvar_gNet_settings )[8]; // addr: 005500C0
extern tJoinable_game(* hookvar_gGames_to_join )[6]; // addr: 0053E5C0
extern tNet_game_options ** hookvar_gOptions ; // addr: 0053E5B8
extern int(* hookvar_gNet_target )[7]; // addr: 005500A0
extern int * hookvar_gLast_graph_sel__newgame ; // addr: 0053E5F0 // suffix added to avoid duplicate symbol
extern tInterface_spec ** hookvar_gThe_interface_spec__newgame ; // addr: 0053E59C // suffix added to avoid duplicate symbol
extern tNet_sequence_type * hookvar_gNet_race_sequence__newgame ; // addr: 0053E5A8 // suffix added to avoid duplicate symbol
extern tNet_game_type * hookvar_gLast_game_type ; // addr: 0053E594
// extern int * hookvar_gCurrent_net_game_count ;
// extern tU32 * hookvar_gAnne_flic_data_length ;
// extern int * hookvar_gShifted_default_yet ;
// extern char ** hookvar_gNet_name ;
// extern tU32 * hookvar_gFrank_flic_data_length ;
extern int * hookvar_gLast_net_choose_box ; // addr: 0053E5A4
extern int * hookvar_gCurrent_game_selection ; // addr: 0053E5A0
extern int * hookvar_gRace_index ; // addr: 0053E5B4
extern int * hookvar_gRadio_selected ; // addr: 0053E590

void StartRollingPlayerNamesIn();

void FrankAnneStart1();

void FrankAnneStart2();

void GetPlayerName(int pStarting_to_type, int pCurrent_choice, char *pString, int *pMax_length);

int FrankAnneDone(int pCurrent_choice, int pCurrent_mode, int pGo_ahead, int pEscaped, int pTimed_out);

void FrankAnneDraw(int pCurrent_choice, int pCurrent_mode);

int FrankieOrAnnie();

int SelectSkillLevel();

int DoOnePlayerStart();

int NewNetGameUp(int *pCurrent_choice, int *pCurrent_mode);

int NewNetGameDown(int *pCurrent_choice, int *pCurrent_mode);

void DisposeJoinableGame(int pIndex);

void DrawAnItem__newgame(int pX, int pY_index, int pFont_index, char *pText);

void DrawColumnHeading__newgame(int pStr_index, int pX);

void DrawGames(int pCurrent_choice, int pCurrent_mode);

void InitGamesToJoin();

void DisposeJoinList(int pExemption);

void AddToJoinList(tNet_game_details *pGame);

void NewNetStart1();

void NewNetStart2();

void NewNetGetName(int pStarting_to_type, int pCurrent_choice, char *pString, int *pMax_length);

int NewNetDone(int pCurrent_choice, int pCurrent_mode, int pGo_ahead, int pEscaped, int pTimed_out);

int NewNetGoAhead(int *pCurrent_choice, int *pCurrent_mode);

tJoin_or_host_result JoinOrHostGame(tNet_game_details **pGame_to_join);

void GetNetOptions(tNet_game_options *pGame_options);

void SetNetOptions(tNet_game_options *pGame_options);

void NetPlayCheckboxOn2(int pIndex);

void NetPlayCheckboxOff2(int pIndex);

void NetPlayCheckboxOn(int pIndex);

void NetPlayCheckboxOff(int pIndex);

void NetPlayRadioOn2(int pIndex, int pValue);

void NetPlayRadioOff2(int pIndex, int pValue);

void NetPlayRadioOn(int pIndex, int pValue);

void NetPlayRadioOff(int pIndex, int pValue);

void DrawNOptInitialRadios();

void NetRadioChanged(int pIndex, int pNew_value);

void NetCheckboxChanged(int pIndex);

int NetOptLeft(int *pCurrent_choice, int *pCurrent_mode);

int NetOptRight(int *pCurrent_choice, int *pCurrent_mode);

int NetOptUp(int *pCurrent_choice, int *pCurrent_mode);

int NetOptDown(int *pCurrent_choice, int *pCurrent_mode);

int NetRadioClick(int *pCurrent_choice, int *pCurrent_mode, int pX_offset, int pY_offset);

void RevertToDefaults();

void DefaultNetSettings();

int NetOptGoAhead(int *pCurrent_choice, int *pCurrent_mode);

void NetPlotAGraphBox(int pIndex, int pColour_value);

void NetDrawAGraphBox(int pIndex);

void NetEraseAGraphBox(int pIndex);

void DrawNetOptBox(int pCurrent_choice, int pCurrent_mode);

void DoNetOptions(tNet_game_options *pGame_options);

void SetOptions(tNet_game_type pGame_type, tNet_game_options *pGame_options);

void PlayRadioOn__newgame(int pIndex);

void PlayRadioOff__newgame(int pIndex);

void DrawNetChooseInitial();

int NetChooseGoAhead(int *pCurrent_choice, int *pCurrent_mode);

void PlotAGraphBox__newgame(int pIndex, int pColour_value);

void DrawAGraphBox__newgame(int pIndex);

void EraseAGraphBox__newgame(int pIndex);

void DrawNetChoose(int pCurrent_choice, int pCurrent_mode);

int NetChooseLR(int *pCurrent_choice, int *pCurrent_mode);

void SetGameTarget(tNet_game_type *pGame_type, tNet_game_options *pGame_options);

int NetGameChoices(tNet_game_type *pGame_type, tNet_game_options *pGame_options, int *pRace_index);

void ReadNetGameChoices(tNet_game_type *pGame_type, tNet_game_options *pGame_options, int *pRace_index);

int ChooseStartRace(int *pRank);

void SetUpOtherNetThings(tNet_game_details *pNet_game);

void RequestCarDetails(tNet_game_details *pNet_game);

int PickARandomCar();

void PollCarDetails(tNet_game_details *pNet_game);

void SetNetAvailability(tNet_game_options *pOptions);

int ChooseNetCar(tNet_game_details *pNet_game, tNet_game_options *pOptions, int *pCar_index, int pIm_the_host_so_fuck_off);

void InitNetStorageSpace();

void DisposeNetStorageSpace();

int DoMultiPlayerStart();

#endif
