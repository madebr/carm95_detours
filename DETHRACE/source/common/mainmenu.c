#include "mainmenu.h"

#include "harness/trace.h"

#include "carm95_hooks.h"

#include "carm95_webserver.h"

#include <assert.h>
 // Suffix added to avoid duplicate symbol
char ** hookvar_gPalette_copy__mainmenu  = (void*)0x00536264;
 // Suffix added to avoid duplicate symbol
int * hookvar_gPixel_buffer_size__mainmenu  = (void*)0x0053625c;
tInterface_spec ** hookvar_gMain_menu_spec  = (void*)0x00536260;
 // Suffix added to avoid duplicate symbol
int * hookvar_gMouse_was_started__mainmenu  = (void*)0x00536268;
int * hookvar_gReplace_background  = (void*)0x0053626c;
 // Suffix added to avoid duplicate symbol
char ** hookvar_gPixels_copy__mainmenu  = (void*)0x00536258;

function_hook_state_t function_hook_state_MainMenuDone1 = HOOK_UNAVAILABLE;
static int(__cdecl*original_MainMenuDone1)(int, int, int, int, int) = (int(__cdecl*)(int, int, int, int, int))0x0044ae90;
CARM95_HOOK_FUNCTION(original_MainMenuDone1, MainMenuDone1)
int __cdecl MainMenuDone1(int pCurrent_choice, int pCurrent_mode, int pGo_ahead, int pEscaped, int pTimed_out) {
    LOG_TRACE("(%d, %d, %d, %d, %d)", pCurrent_choice, pCurrent_mode, pGo_ahead, pEscaped, pTimed_out);

    (void)pCurrent_choice;
    (void)pCurrent_mode;
    (void)pGo_ahead;
    (void)pEscaped;
    (void)pTimed_out;

    if (function_hook_state_MainMenuDone1 == HOOK_ENABLED) {
        assert(0 && "MainMenuDone1 not implemented.");
        abort();
    } else {
        return original_MainMenuDone1(pCurrent_choice, pCurrent_mode, pGo_ahead, pEscaped, pTimed_out);
    }
}

function_hook_state_t function_hook_state_MainMenuDone2 = HOOK_UNAVAILABLE;
static int(__cdecl*original_MainMenuDone2)(int, int, int, int, int) = (int(__cdecl*)(int, int, int, int, int))0x0044af61;
CARM95_HOOK_FUNCTION(original_MainMenuDone2, MainMenuDone2)
int __cdecl MainMenuDone2(int pCurrent_choice, int pCurrent_mode, int pGo_ahead, int pEscaped, int pTimed_out) {
    LOG_TRACE("(%d, %d, %d, %d, %d)", pCurrent_choice, pCurrent_mode, pGo_ahead, pEscaped, pTimed_out);

    (void)pCurrent_choice;
    (void)pCurrent_mode;
    (void)pGo_ahead;
    (void)pEscaped;
    (void)pTimed_out;

    if (function_hook_state_MainMenuDone2 == HOOK_ENABLED) {
        assert(0 && "MainMenuDone2 not implemented.");
        abort();
    } else {
        return original_MainMenuDone2(pCurrent_choice, pCurrent_mode, pGo_ahead, pEscaped, pTimed_out);
    }
}

function_hook_state_t function_hook_state_StartMainMenu = HOOK_UNAVAILABLE;
static void(__cdecl*original_StartMainMenu)() = (void(__cdecl*)())0x0044b018;
CARM95_HOOK_FUNCTION(original_StartMainMenu, StartMainMenu)
void __cdecl StartMainMenu() {
    LOG_TRACE("()");


    if (function_hook_state_StartMainMenu == HOOK_ENABLED) {
        assert(0 && "StartMainMenu not implemented.");
        abort();
    } else {
        original_StartMainMenu();
    }
}

function_hook_state_t function_hook_state_DoMainMenuInterface = HOOK_UNAVAILABLE;
static int(__cdecl*original_DoMainMenuInterface)(tU32, int) = (int(__cdecl*)(tU32, int))0x0044b7cc;
CARM95_HOOK_FUNCTION(original_DoMainMenuInterface, DoMainMenuInterface)
int __cdecl DoMainMenuInterface(tU32 pTime_out, int pContinue_allowed) {
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

    if (function_hook_state_DoMainMenuInterface == HOOK_ENABLED) {
        assert(0 && "DoMainMenuInterface not implemented.");
        abort();
    } else {
        return original_DoMainMenuInterface(pTime_out, pContinue_allowed);
    }
}

function_hook_state_t function_hook_state_GetMainMenuOption = HOOK_UNAVAILABLE;
static tMM_result(__cdecl*original_GetMainMenuOption)(tU32, int) = (tMM_result(__cdecl*)(tU32, int))0x0044b6bc;
CARM95_HOOK_FUNCTION(original_GetMainMenuOption, GetMainMenuOption)
tMM_result __cdecl GetMainMenuOption(tU32 pTime_out, int pContinue_allowed) {
    int result;
    LOG_TRACE("(%u, %d)", pTime_out, pContinue_allowed);

    (void)pTime_out;
    (void)pContinue_allowed;
    (void)result;

    if (function_hook_state_GetMainMenuOption == HOOK_ENABLED) {
        assert(0 && "GetMainMenuOption not implemented.");
        abort();
    } else {
        return original_GetMainMenuOption(pTime_out, pContinue_allowed);
    }
}

function_hook_state_t function_hook_state_QuitVerifyStart = HOOK_UNAVAILABLE;
static void(__cdecl*original_QuitVerifyStart)() = (void(__cdecl*)())0x0044b101;
CARM95_HOOK_FUNCTION(original_QuitVerifyStart, QuitVerifyStart)
void __cdecl QuitVerifyStart() {
    LOG_TRACE("()");


    if (function_hook_state_QuitVerifyStart == HOOK_ENABLED) {
        assert(0 && "QuitVerifyStart not implemented.");
        abort();
    } else {
        original_QuitVerifyStart();
    }
}

function_hook_state_t function_hook_state_QuitVerifyDone = HOOK_UNAVAILABLE;
static int(__cdecl*original_QuitVerifyDone)(int, int, int, int, int) = (int(__cdecl*)(int, int, int, int, int))0x0044b192;
CARM95_HOOK_FUNCTION(original_QuitVerifyDone, QuitVerifyDone)
int __cdecl QuitVerifyDone(int pCurrent_choice, int pCurrent_mode, int pGo_ahead, int pEscaped, int pTimed_out) {
    LOG_TRACE("(%d, %d, %d, %d, %d)", pCurrent_choice, pCurrent_mode, pGo_ahead, pEscaped, pTimed_out);

    (void)pCurrent_choice;
    (void)pCurrent_mode;
    (void)pGo_ahead;
    (void)pEscaped;
    (void)pTimed_out;

    if (function_hook_state_QuitVerifyDone == HOOK_ENABLED) {
        assert(0 && "QuitVerifyDone not implemented.");
        abort();
    } else {
        return original_QuitVerifyDone(pCurrent_choice, pCurrent_mode, pGo_ahead, pEscaped, pTimed_out);
    }
}

function_hook_state_t function_hook_state_DoVerifyQuit = HOOK_UNAVAILABLE;
static int(__cdecl*original_DoVerifyQuit)(int) = (int(__cdecl*)(int))0x0044b25a;
CARM95_HOOK_FUNCTION(original_DoVerifyQuit, DoVerifyQuit)
int __cdecl DoVerifyQuit(int pReplace_background) {
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

    if (function_hook_state_DoVerifyQuit == HOOK_ENABLED) {
        assert(0 && "DoVerifyQuit not implemented.");
        abort();
    } else {
        return original_DoVerifyQuit(pReplace_background);
    }
}

function_hook_state_t function_hook_state_DoMainMenu = HOOK_UNAVAILABLE;
static tMM_result(__cdecl*original_DoMainMenu)(tU32, int, int) = (tMM_result(__cdecl*)(tU32, int, int))0x0044b51b;
CARM95_HOOK_FUNCTION(original_DoMainMenu, DoMainMenu)
tMM_result __cdecl DoMainMenu(tU32 pTime_out, int pSave_allowed, int pContinue_allowed) {
    tMM_result the_result;
    LOG_TRACE("(%u, %d, %d)", pTime_out, pSave_allowed, pContinue_allowed);

    (void)pTime_out;
    (void)pSave_allowed;
    (void)pContinue_allowed;
    (void)the_result;

    if (function_hook_state_DoMainMenu == HOOK_ENABLED) {
        assert(0 && "DoMainMenu not implemented.");
        abort();
    } else {
        return original_DoMainMenu(pTime_out, pSave_allowed, pContinue_allowed);
    }
}

function_hook_state_t function_hook_state_DoMainMenuScreen = HOOK_UNAVAILABLE;
static void(__cdecl*original_DoMainMenuScreen)(tU32, int, int) = (void(__cdecl*)(tU32, int, int))0x0044b3c3;
CARM95_HOOK_FUNCTION(original_DoMainMenuScreen, DoMainMenuScreen)
void __cdecl DoMainMenuScreen(tU32 pTime_out, int pSave_allowed, int pContinue_allowed) {
    tPlayer_status old_status;
    LOG_TRACE("(%u, %d, %d)", pTime_out, pSave_allowed, pContinue_allowed);

    (void)pTime_out;
    (void)pSave_allowed;
    (void)pContinue_allowed;
    (void)old_status;

    if (function_hook_state_DoMainMenuScreen == HOOK_ENABLED) {
        assert(0 && "DoMainMenuScreen not implemented.");
        abort();
    } else {
        original_DoMainMenuScreen(pTime_out, pSave_allowed, pContinue_allowed);
    }
}

