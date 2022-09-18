#ifndef _LOADSAVE_H_
#define _LOADSAVE_H_

#include "br_types.h"
#include "dr_types.h"

extern tSave_game *(* hookvar_gSaved_games )[8]; // addr: 00536278
extern int * hookvar_gStarted_typing ; // addr: 00536270
extern int * hookvar_gSave_allowed ; // addr: 00536274

void __cdecl CorrectLoadByteOrdering(int pIndex);

tU32 __cdecl CalcLSChecksum(tSave_game *pSaved_game);

void __cdecl LoadSavedGames();

void __cdecl DisposeSavedGames();

void __cdecl LoadTheGame(int pSlot_index);

void __cdecl StartRollingSaveNamesIn();

void __cdecl LoadStart();

int __cdecl DoLoadGame(int pSave_allowed);

void __cdecl CorrectSaveByteOrdering(int pIndex);

void __cdecl SaveTheGame(int pSlot_number);

int __cdecl ConfirmMidGameSave();

void __cdecl MakeSavedGame(tSave_game **pSave_record);

void __cdecl SaveStart();

void __cdecl GetSaveName(int pStarting_to_type, int pCurrent_choice, char *pString, int *pMax_length);

int __cdecl SaveDone(int pCurrent_choice, int pCurrent_mode, int pGo_ahead, int pEscaped, int pTimed_out);

int __cdecl SaveGoAhead(int *pCurrent_choice, int *pCurrent_mode);

int __cdecl SaveEscape(int *pCurrent_choice, int *pCurrent_mode);

int __cdecl SaveGameInterface(int pDefault_choice);

void __cdecl DoSaveGame(int pSave_allowed);

#endif
