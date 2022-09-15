#ifndef _MAINMENU_H_
#define _MAINMENU_H_

#include "br_types.h"
#include "dr_types.h"

// extern char ** hookvar_gPalette_copy__mainmenu ; // suffix added to avoid duplicate symbol
// extern int * hookvar_gPixel_buffer_size__mainmenu ; // suffix added to avoid duplicate symbol
extern tInterface_spec ** hookvar_gMain_menu_spec ; // addr: 00536260
extern int * hookvar_gMouse_was_started__mainmenu ; // addr: 00536268 // suffix added to avoid duplicate symbol
extern int * hookvar_gReplace_background ; // addr: 0053626C
// extern char ** hookvar_gPixels_copy__mainmenu ; // suffix added to avoid duplicate symbol

int MainMenuDone1(int pCurrent_choice, int pCurrent_mode, int pGo_ahead, int pEscaped, int pTimed_out);

int MainMenuDone2(int pCurrent_choice, int pCurrent_mode, int pGo_ahead, int pEscaped, int pTimed_out);

void StartMainMenu();

int DoMainMenuInterface(tU32 pTime_out, int pContinue_allowed);

tMM_result GetMainMenuOption(tU32 pTime_out, int pContinue_allowed);

void QuitVerifyStart();

int QuitVerifyDone(int pCurrent_choice, int pCurrent_mode, int pGo_ahead, int pEscaped, int pTimed_out);

int DoVerifyQuit(int pReplace_background);

tMM_result DoMainMenu(tU32 pTime_out, int pSave_allowed, int pContinue_allowed);

void DoMainMenuScreen(tU32 pTime_out, int pSave_allowed, int pContinue_allowed);

#endif
