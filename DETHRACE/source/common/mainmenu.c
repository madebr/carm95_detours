#include "mainmenu.h"

#include "harness/trace.h"

#include "carm95_hooks.h"

#include <stdio.h>
 // Suffix added to avoid duplicate symbol
#if 0
char ** hookvar_gPalette_copy__mainmenu ;
#endif
 // Suffix added to avoid duplicate symbol
#if 0
int * hookvar_gPixel_buffer_size__mainmenu ;
#endif
tInterface_spec ** hookvar_gMain_menu_spec  = (void*)0x00536260;
 // Suffix added to avoid duplicate symbol
int * hookvar_gMouse_was_started__mainmenu  = (void*)0x00536268;
int * hookvar_gReplace_background  = (void*)0x0053626c;
 // Suffix added to avoid duplicate symbol
#if 0
char ** hookvar_gPixels_copy__mainmenu ;
#endif

static int(*original_MainMenuDone1)(int, int, int, int, int, ...) = (int(*)(int, int, int, int, int, ...))0x0044ae90;
CARM95_HOOK_FUNCTION(original_MainMenuDone1, MainMenuDone1)
int MainMenuDone1(int pCurrent_choice, int pCurrent_mode, int pGo_ahead, int pEscaped, int pTimed_out) {
    LOG_TRACE("(%d, %d, %d, %d, %d)", pCurrent_choice, pCurrent_mode, pGo_ahead, pEscaped, pTimed_out);

    (void)pCurrent_choice;
    (void)pCurrent_mode;
    (void)pGo_ahead;
    (void)pEscaped;
    (void)pTimed_out;

    return original_MainMenuDone1(pCurrent_choice, pCurrent_mode, pGo_ahead, pEscaped, pTimed_out);
}

static int(*original_MainMenuDone2)(int, int, int, int, int, ...) = (int(*)(int, int, int, int, int, ...))0x0044af61;
CARM95_HOOK_FUNCTION(original_MainMenuDone2, MainMenuDone2)
int MainMenuDone2(int pCurrent_choice, int pCurrent_mode, int pGo_ahead, int pEscaped, int pTimed_out) {
    LOG_TRACE("(%d, %d, %d, %d, %d)", pCurrent_choice, pCurrent_mode, pGo_ahead, pEscaped, pTimed_out);

    (void)pCurrent_choice;
    (void)pCurrent_mode;
    (void)pGo_ahead;
    (void)pEscaped;
    (void)pTimed_out;

    return original_MainMenuDone2(pCurrent_choice, pCurrent_mode, pGo_ahead, pEscaped, pTimed_out);
}

void StartMainMenu() {
    LOG_TRACE("()");


    NOT_IMPLEMENTED();
}

static int(*original_DoMainMenuInterface)(tU32, int, ...) = (int(*)(tU32, int, ...))0x0044b7cc;
CARM95_HOOK_FUNCTION(original_DoMainMenuInterface, DoMainMenuInterface)
int DoMainMenuInterface(tU32 pTime_out, int pContinue_allowed) {
    static tFlicette flicker_on1[8];
    static tFlicette flicker_off1[8];
    static tFlicette push1[8];
    static tMouse_area mouse_areas1[8];
    static tInterface_spec interface_spec1;
    static tFlicette flicker_on2[5];
    static tFlicette flicker_off2[5];
    static tFlicette push2[5];
    static tMouse_area mouse_areas2[5];
    static tInterface_spec interface_spec2;
    int result;
    LOG_TRACE("(%u, %d)", pTime_out, pContinue_allowed);

    (void)pTime_out;
    (void)pContinue_allowed;
    (void)flicker_on1;
    (void)flicker_off1;
    (void)push1;
    (void)mouse_areas1;
    (void)interface_spec1;
    (void)flicker_on2;
    (void)flicker_off2;
    (void)push2;
    (void)mouse_areas2;
    (void)interface_spec2;
    (void)result;

    return original_DoMainMenuInterface(pTime_out, pContinue_allowed);
}

static tMM_result(*original_GetMainMenuOption)(tU32, int, ...) = (tMM_result(*)(tU32, int, ...))0x0044b6bc;
CARM95_HOOK_FUNCTION(original_GetMainMenuOption, GetMainMenuOption)
tMM_result GetMainMenuOption(tU32 pTime_out, int pContinue_allowed) {
    int result;
    LOG_TRACE("(%u, %d)", pTime_out, pContinue_allowed);

    (void)pTime_out;
    (void)pContinue_allowed;
    (void)result;

    return original_GetMainMenuOption(pTime_out, pContinue_allowed);
}

void QuitVerifyStart() {
    LOG_TRACE("()");


    NOT_IMPLEMENTED();
}

int QuitVerifyDone(int pCurrent_choice, int pCurrent_mode, int pGo_ahead, int pEscaped, int pTimed_out) {
    LOG_TRACE("(%d, %d, %d, %d, %d)", pCurrent_choice, pCurrent_mode, pGo_ahead, pEscaped, pTimed_out);

    (void)pCurrent_choice;
    (void)pCurrent_mode;
    (void)pGo_ahead;
    (void)pEscaped;
    (void)pTimed_out;

    NOT_IMPLEMENTED();
}

static int(*original_DoVerifyQuit)(int, ...) = (int(*)(int, ...))0x0044b25a;
CARM95_HOOK_FUNCTION(original_DoVerifyQuit, DoVerifyQuit)
int DoVerifyQuit(int pReplace_background) {
    static tFlicette flicker_on[2];
    static tFlicette flicker_off[2];
    static tFlicette push[2];
    static tMouse_area mouse_areas[2];
    static tInterface_spec interface_spec;
    int result;
    int switched_res;
    int woz_in_race;
    LOG_TRACE("(%d)", pReplace_background);

    (void)pReplace_background;
    (void)flicker_on;
    (void)flicker_off;
    (void)push;
    (void)mouse_areas;
    (void)interface_spec;
    (void)result;
    (void)switched_res;
    (void)woz_in_race;

    return original_DoVerifyQuit(pReplace_background);
}

static tMM_result(*original_DoMainMenu)(tU32, int, int, ...) = (tMM_result(*)(tU32, int, int, ...))0x0044b51b;
CARM95_HOOK_FUNCTION(original_DoMainMenu, DoMainMenu)
tMM_result DoMainMenu(tU32 pTime_out, int pSave_allowed, int pContinue_allowed) {
    tMM_result the_result;
    LOG_TRACE("(%u, %d, %d)", pTime_out, pSave_allowed, pContinue_allowed);

    (void)pTime_out;
    (void)pSave_allowed;
    (void)pContinue_allowed;
    (void)the_result;

    return original_DoMainMenu(pTime_out, pSave_allowed, pContinue_allowed);
}

static void(*original_DoMainMenuScreen)(tU32, int, int, ...) = (void(*)(tU32, int, int, ...))0x0044b3c3;
CARM95_HOOK_FUNCTION(original_DoMainMenuScreen, DoMainMenuScreen)
void DoMainMenuScreen(tU32 pTime_out, int pSave_allowed, int pContinue_allowed) {
    tPlayer_status old_status;
    LOG_TRACE("(%u, %d, %d)", pTime_out, pSave_allowed, pContinue_allowed);

    (void)pTime_out;
    (void)pSave_allowed;
    (void)pContinue_allowed;
    (void)old_status;

    original_DoMainMenuScreen(pTime_out, pSave_allowed, pContinue_allowed);
}

