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

void __cdecl StartRollingPlayerNamesIn();

void __cdecl FrankAnneStart1();

void __cdecl FrankAnneStart2();

void __cdecl GetPlayerName(int pStarting_to_type, int pCurrent_choice, char *pString, int *pMax_length);

int __cdecl FrankAnneDone(int pCurrent_choice, int pCurrent_mode, int pGo_ahead, int pEscaped, int pTimed_out);

void __cdecl FrankAnneDraw(int pCurrent_choice, int pCurrent_mode);

int __cdecl FrankieOrAnnie();

int __cdecl SelectSkillLevel();

int __cdecl DoOnePlayerStart();

int __cdecl NewNetGameUp(int *pCurrent_choice, int *pCurrent_mode);

int __cdecl NewNetGameDown(int *pCurrent_choice, int *pCurrent_mode);

void __cdecl DisposeJoinableGame(int pIndex);

void __cdecl DrawAnItem__newgame(int pX, int pY_index, int pFont_index, char *pText);

void __cdecl DrawColumnHeading__newgame(int pStr_index, int pX);

void __cdecl DrawGames(int pCurrent_choice, int pCurrent_mode);

void __cdecl InitGamesToJoin();

void __cdecl DisposeJoinList(int pExemption);

void __cdecl AddToJoinList(tNet_game_details *pGame);

void __cdecl NewNetStart1();

void __cdecl NewNetStart2();

void __cdecl NewNetGetName(int pStarting_to_type, int pCurrent_choice, char *pString, int *pMax_length);

int __cdecl NewNetDone(int pCurrent_choice, int pCurrent_mode, int pGo_ahead, int pEscaped, int pTimed_out);

int __cdecl NewNetGoAhead(int *pCurrent_choice, int *pCurrent_mode);

tJoin_or_host_result __cdecl JoinOrHostGame(tNet_game_details **pGame_to_join);

void __cdecl GetNetOptions(tNet_game_options *pGame_options);

void __cdecl SetNetOptions(tNet_game_options *pGame_options);

void __cdecl NetPlayCheckboxOn2(int pIndex);

void __cdecl NetPlayCheckboxOff2(int pIndex);

void __cdecl NetPlayCheckboxOn(int pIndex);

void __cdecl NetPlayCheckboxOff(int pIndex);

void __cdecl NetPlayRadioOn2(int pIndex, int pValue);

void __cdecl NetPlayRadioOff2(int pIndex, int pValue);

void __cdecl NetPlayRadioOn(int pIndex, int pValue);

void __cdecl NetPlayRadioOff(int pIndex, int pValue);

void __cdecl DrawNOptInitialRadios();

void __cdecl NetRadioChanged(int pIndex, int pNew_value);

void __cdecl NetCheckboxChanged(int pIndex);

int __cdecl NetOptLeft(int *pCurrent_choice, int *pCurrent_mode);

int __cdecl NetOptRight(int *pCurrent_choice, int *pCurrent_mode);

int __cdecl NetOptUp(int *pCurrent_choice, int *pCurrent_mode);

int __cdecl NetOptDown(int *pCurrent_choice, int *pCurrent_mode);

int __cdecl NetRadioClick(int *pCurrent_choice, int *pCurrent_mode, int pX_offset, int pY_offset);

void __cdecl RevertToDefaults();

void __cdecl DefaultNetSettings();

int __cdecl NetOptGoAhead(int *pCurrent_choice, int *pCurrent_mode);

void __cdecl NetPlotAGraphBox(int pIndex, int pColour_value);

void __cdecl NetDrawAGraphBox(int pIndex);

void __cdecl NetEraseAGraphBox(int pIndex);

void __cdecl DrawNetOptBox(int pCurrent_choice, int pCurrent_mode);

void __cdecl DoNetOptions(tNet_game_options *pGame_options);

void __cdecl SetOptions(tNet_game_type pGame_type, tNet_game_options *pGame_options);

void __cdecl PlayRadioOn__newgame(int pIndex);

void __cdecl PlayRadioOff__newgame(int pIndex);

void __cdecl DrawNetChooseInitial();

int __cdecl NetChooseGoAhead(int *pCurrent_choice, int *pCurrent_mode);

void __cdecl PlotAGraphBox__newgame(int pIndex, int pColour_value);

void __cdecl DrawAGraphBox__newgame(int pIndex);

void __cdecl EraseAGraphBox__newgame(int pIndex);

void __cdecl DrawNetChoose(int pCurrent_choice, int pCurrent_mode);

int __cdecl NetChooseLR(int *pCurrent_choice, int *pCurrent_mode);

void __cdecl SetGameTarget(tNet_game_type *pGame_type, tNet_game_options *pGame_options);

int __cdecl NetGameChoices(tNet_game_type *pGame_type, tNet_game_options *pGame_options, int *pRace_index);

void __cdecl ReadNetGameChoices(tNet_game_type *pGame_type, tNet_game_options *pGame_options, int *pRace_index);

int __cdecl ChooseStartRace(int *pRank);

void __cdecl SetUpOtherNetThings(tNet_game_details *pNet_game);

void __cdecl RequestCarDetails(tNet_game_details *pNet_game);

int __cdecl PickARandomCar();

void __cdecl PollCarDetails(tNet_game_details *pNet_game);

void __cdecl SetNetAvailability(tNet_game_options *pOptions);

int __cdecl ChooseNetCar(tNet_game_details *pNet_game, tNet_game_options *pOptions, int *pCar_index, int pIm_the_host_so_fuck_off);

void __cdecl InitNetStorageSpace();

void __cdecl DisposeNetStorageSpace();

int __fastcall DoMultiPlayerStart();

#endif
