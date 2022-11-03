#include "newgame.h"

#include "harness/trace.h"

#include "carm95_hooks.h"

#include "carm95_webserver.h"

#include <assert.h>
tU8 ** hookvar_gFrank_flic_data  = (void*)0x0051e910;
tU8 ** hookvar_gAnne_flic_data  = (void*)0x0051e914;
int * hookvar_gNet_storage_allocated  = (void*)0x0051e918;
 // Suffix added to avoid duplicate symbol
tRadio_bastards(* hookvar_gRadio_bastards__newgame )[11] = (void*)0x0051e920;
char *(* hookvar_gBasic_car_names )[2] = (void*)0x0051ea80;
tNet_game_options(* hookvar_gNet_settings )[8] = (void*)0x005500c0;
tJoinable_game(* hookvar_gGames_to_join )[6] = (void*)0x0053e5c0;
tNet_game_options ** hookvar_gOptions  = (void*)0x0053e5b8;
int(* hookvar_gNet_target )[7] = (void*)0x005500a0;
 // Suffix added to avoid duplicate symbol
int * hookvar_gLast_graph_sel__newgame  = (void*)0x0053e5f0;
 // Suffix added to avoid duplicate symbol
tInterface_spec ** hookvar_gThe_interface_spec__newgame  = (void*)0x0053e59c;
 // Suffix added to avoid duplicate symbol
tNet_sequence_type * hookvar_gNet_race_sequence__newgame  = (void*)0x0053e5a8;
tNet_game_type * hookvar_gLast_game_type  = (void*)0x0053e594;
#if 0
int * hookvar_gCurrent_net_game_count ;
#endif
#if 0
tU32 * hookvar_gAnne_flic_data_length ;
#endif
#if 0
int * hookvar_gShifted_default_yet ;
#endif
#if 0
char ** hookvar_gNet_name ;
#endif
#if 0
tU32 * hookvar_gFrank_flic_data_length ;
#endif
int * hookvar_gLast_net_choose_box  = (void*)0x0053e5a4;
int * hookvar_gCurrent_game_selection  = (void*)0x0053e5a0;
int * hookvar_gRace_index  = (void*)0x0053e5b4;
int * hookvar_gRadio_selected  = (void*)0x0053e590;

function_hook_state_t function_hook_state_StartRollingPlayerNamesIn = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(StartRollingPlayerNamesIn, function_hook_state_StartRollingPlayerNamesIn)
static void(__cdecl*original_StartRollingPlayerNamesIn)() = (void(__cdecl*)())0x004affc4;
CARM95_HOOK_FUNCTION(original_StartRollingPlayerNamesIn, StartRollingPlayerNamesIn)
void __cdecl StartRollingPlayerNamesIn() {
    int i;
    LOG_TRACE("()");

    (void)i;

    if (function_hook_state_StartRollingPlayerNamesIn == HOOK_ENABLED) {
        assert(0 && "StartRollingPlayerNamesIn not implemented.");
        abort();
    } else {
        original_StartRollingPlayerNamesIn();
    }
}

function_hook_state_t function_hook_state_FrankAnneStart1 = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(FrankAnneStart1, function_hook_state_FrankAnneStart1)
static void(__cdecl*original_FrankAnneStart1)() = (void(__cdecl*)())0x004afe80;
CARM95_HOOK_FUNCTION(original_FrankAnneStart1, FrankAnneStart1)
void __cdecl FrankAnneStart1() {
    LOG_TRACE("()");


    if (function_hook_state_FrankAnneStart1 == HOOK_ENABLED) {
        assert(0 && "FrankAnneStart1 not implemented.");
        abort();
    } else {
        original_FrankAnneStart1();
    }
}

function_hook_state_t function_hook_state_FrankAnneStart2 = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(FrankAnneStart2, function_hook_state_FrankAnneStart2)
static void(__cdecl*original_FrankAnneStart2)() = (void(__cdecl*)())0x004b0057;
CARM95_HOOK_FUNCTION(original_FrankAnneStart2, FrankAnneStart2)
void __cdecl FrankAnneStart2() {
    LOG_TRACE("()");


    if (function_hook_state_FrankAnneStart2 == HOOK_ENABLED) {
        assert(0 && "FrankAnneStart2 not implemented.");
        abort();
    } else {
        original_FrankAnneStart2();
    }
}

function_hook_state_t function_hook_state_GetPlayerName = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(GetPlayerName, function_hook_state_GetPlayerName)
static void(__cdecl*original_GetPlayerName)(int, int, char *, int *) = (void(__cdecl*)(int, int, char *, int *))0x004b00e4;
CARM95_HOOK_FUNCTION(original_GetPlayerName, GetPlayerName)
void __cdecl GetPlayerName(int pStarting_to_type, int pCurrent_choice, char *pString, int *pMax_length) {
    LOG_TRACE("(%d, %d, \"%s\", %p)", pStarting_to_type, pCurrent_choice, pString, pMax_length);

    (void)pStarting_to_type;
    (void)pCurrent_choice;
    (void)pString;
    (void)pMax_length;

    if (function_hook_state_GetPlayerName == HOOK_ENABLED) {
        assert(0 && "GetPlayerName not implemented.");
        abort();
    } else {
        original_GetPlayerName(pStarting_to_type, pCurrent_choice, pString, pMax_length);
    }
}

function_hook_state_t function_hook_state_FrankAnneDone = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(FrankAnneDone, function_hook_state_FrankAnneDone)
static int(__cdecl*original_FrankAnneDone)(int, int, int, int, int) = (int(__cdecl*)(int, int, int, int, int))0x004b012b;
CARM95_HOOK_FUNCTION(original_FrankAnneDone, FrankAnneDone)
int __cdecl FrankAnneDone(int pCurrent_choice, int pCurrent_mode, int pGo_ahead, int pEscaped, int pTimed_out) {
    LOG_TRACE("(%d, %d, %d, %d, %d)", pCurrent_choice, pCurrent_mode, pGo_ahead, pEscaped, pTimed_out);

    (void)pCurrent_choice;
    (void)pCurrent_mode;
    (void)pGo_ahead;
    (void)pEscaped;
    (void)pTimed_out;

    if (function_hook_state_FrankAnneDone == HOOK_ENABLED) {
        assert(0 && "FrankAnneDone not implemented.");
        abort();
    } else {
        return original_FrankAnneDone(pCurrent_choice, pCurrent_mode, pGo_ahead, pEscaped, pTimed_out);
    }
}

function_hook_state_t function_hook_state_FrankAnneDraw = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(FrankAnneDraw, function_hook_state_FrankAnneDraw)
static void(__cdecl*original_FrankAnneDraw)(int, int) = (void(__cdecl*)(int, int))0x004b01fb;
CARM95_HOOK_FUNCTION(original_FrankAnneDraw, FrankAnneDraw)
void __cdecl FrankAnneDraw(int pCurrent_choice, int pCurrent_mode) {
    LOG_TRACE("(%d, %d)", pCurrent_choice, pCurrent_mode);

    (void)pCurrent_choice;
    (void)pCurrent_mode;

    if (function_hook_state_FrankAnneDraw == HOOK_ENABLED) {
        assert(0 && "FrankAnneDraw not implemented.");
        abort();
    } else {
        original_FrankAnneDraw(pCurrent_choice, pCurrent_mode);
    }
}

function_hook_state_t function_hook_state_FrankieOrAnnie = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(FrankieOrAnnie, function_hook_state_FrankieOrAnnie)
static int(__cdecl*original_FrankieOrAnnie)() = (int(__cdecl*)())0x004b03cd;
CARM95_HOOK_FUNCTION(original_FrankieOrAnnie, FrankieOrAnnie)
int __cdecl FrankieOrAnnie() {
    static tFlicette flicker_on[3];
    static tFlicette flicker_off[3];
    static tFlicette push[3];
    static tMouse_area mouse_areas[3];
    static tRectile recopy_areas[2];
    static tInterface_spec interface_spec;
    int result;
    LOG_TRACE("()");

    (void)flicker_on;
    (void)flicker_off;
    (void)push;
    (void)mouse_areas;
    (void)recopy_areas;
    (void)interface_spec;
    (void)result;

    if (function_hook_state_FrankieOrAnnie == HOOK_ENABLED) {
        assert(0 && "FrankieOrAnnie not implemented.");
        abort();
    } else {
        return original_FrankieOrAnnie();
    }
}

function_hook_state_t function_hook_state_SelectSkillLevel = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(SelectSkillLevel, function_hook_state_SelectSkillLevel)
static int(__cdecl*original_SelectSkillLevel)() = (int(__cdecl*)())0x004b0436;
CARM95_HOOK_FUNCTION(original_SelectSkillLevel, SelectSkillLevel)
int __cdecl SelectSkillLevel() {
    static tFlicette flicker_on[4];
    static tFlicette flicker_off[4];
    static tFlicette push[4];
    static tMouse_area mouse_areas[4];
    static tInterface_spec interface_spec;
    int result;
    LOG_TRACE("()");

    (void)flicker_on;
    (void)flicker_off;
    (void)push;
    (void)mouse_areas;
    (void)interface_spec;
    (void)result;

    if (function_hook_state_SelectSkillLevel == HOOK_ENABLED) {
        assert(0 && "SelectSkillLevel not implemented.");
        abort();
    } else {
        return original_SelectSkillLevel();
    }
}

function_hook_state_t function_hook_state_DoOnePlayerStart = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(DoOnePlayerStart, function_hook_state_DoOnePlayerStart)
static int(__cdecl*original_DoOnePlayerStart)() = (int(__cdecl*)())0x004b027b;
CARM95_HOOK_FUNCTION(original_DoOnePlayerStart, DoOnePlayerStart)
int __cdecl DoOnePlayerStart() {
    int merrily_looping;
    tProgram_state saved_state;
    LOG_TRACE("()");

    (void)merrily_looping;
    (void)saved_state;

    if (function_hook_state_DoOnePlayerStart == HOOK_ENABLED) {
        assert(0 && "DoOnePlayerStart not implemented.");
        abort();
    } else {
        return original_DoOnePlayerStart();
    }
}

function_hook_state_t function_hook_state_NewNetGameUp = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(NewNetGameUp, function_hook_state_NewNetGameUp)
static int(__cdecl*original_NewNetGameUp)(int *, int *) = (int(__cdecl*)(int *, int *))0x004b0484;
CARM95_HOOK_FUNCTION(original_NewNetGameUp, NewNetGameUp)
int __cdecl NewNetGameUp(int *pCurrent_choice, int *pCurrent_mode) {
    int new_sel;
    int i;
    LOG_TRACE("(%p, %p)", pCurrent_choice, pCurrent_mode);

    (void)pCurrent_choice;
    (void)pCurrent_mode;
    (void)new_sel;
    (void)i;

    if (function_hook_state_NewNetGameUp == HOOK_ENABLED) {
        assert(0 && "NewNetGameUp not implemented.");
        abort();
    } else {
        return original_NewNetGameUp(pCurrent_choice, pCurrent_mode);
    }
}

function_hook_state_t function_hook_state_NewNetGameDown = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(NewNetGameDown, function_hook_state_NewNetGameDown)
static int(__cdecl*original_NewNetGameDown)(int *, int *) = (int(__cdecl*)(int *, int *))0x004b0589;
CARM95_HOOK_FUNCTION(original_NewNetGameDown, NewNetGameDown)
int __cdecl NewNetGameDown(int *pCurrent_choice, int *pCurrent_mode) {
    int new_sel;
    int i;
    LOG_TRACE("(%p, %p)", pCurrent_choice, pCurrent_mode);

    (void)pCurrent_choice;
    (void)pCurrent_mode;
    (void)new_sel;
    (void)i;

    if (function_hook_state_NewNetGameDown == HOOK_ENABLED) {
        assert(0 && "NewNetGameDown not implemented.");
        abort();
    } else {
        return original_NewNetGameDown(pCurrent_choice, pCurrent_mode);
    }
}

function_hook_state_t function_hook_state_DisposeJoinableGame = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(DisposeJoinableGame, function_hook_state_DisposeJoinableGame)
static void(__cdecl*original_DisposeJoinableGame)(int) = (void(__cdecl*)(int))0x004b0def;
CARM95_HOOK_FUNCTION(original_DisposeJoinableGame, DisposeJoinableGame)
void __cdecl DisposeJoinableGame(int pIndex) {
    LOG_TRACE("(%d)", pIndex);

    (void)pIndex;

    if (function_hook_state_DisposeJoinableGame == HOOK_ENABLED) {
        assert(0 && "DisposeJoinableGame not implemented.");
        abort();
    } else {
        original_DisposeJoinableGame(pIndex);
    }
}

function_hook_state_t function_hook_state_DrawAnItem__newgame = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(DrawAnItem__newgame, function_hook_state_DrawAnItem__newgame)
static void(__cdecl*original_DrawAnItem__newgame)(int, int, int, char *) = (void(__cdecl*)(int, int, int, char *))0x004b0e1b;
CARM95_HOOK_FUNCTION(original_DrawAnItem__newgame, DrawAnItem__newgame)
void __cdecl DrawAnItem__newgame(int pX, int pY_index, int pFont_index, char *pText) {
    LOG_TRACE("(%d, %d, %d, \"%s\")", pX, pY_index, pFont_index, pText);

    (void)pX;
    (void)pY_index;
    (void)pFont_index;
    (void)pText;

    if (function_hook_state_DrawAnItem__newgame == HOOK_ENABLED) {
        assert(0 && "DrawAnItem__newgame not implemented.");
        abort();
    } else {
        original_DrawAnItem__newgame(pX, pY_index, pFont_index, pText);
    }
}

function_hook_state_t function_hook_state_DrawColumnHeading__newgame = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(DrawColumnHeading__newgame, function_hook_state_DrawColumnHeading__newgame)
static void(__cdecl*original_DrawColumnHeading__newgame)(int, int) = (void(__cdecl*)(int, int))0x004b0e9c;
CARM95_HOOK_FUNCTION(original_DrawColumnHeading__newgame, DrawColumnHeading__newgame)
void __cdecl DrawColumnHeading__newgame(int pStr_index, int pX) {
    LOG_TRACE("(%d, %d)", pStr_index, pX);

    (void)pStr_index;
    (void)pX;

    if (function_hook_state_DrawColumnHeading__newgame == HOOK_ENABLED) {
        assert(0 && "DrawColumnHeading__newgame not implemented.");
        abort();
    } else {
        original_DrawColumnHeading__newgame(pStr_index, pX);
    }
}

function_hook_state_t function_hook_state_DrawGames = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(DrawGames, function_hook_state_DrawGames)
static void(__cdecl*original_DrawGames)(int, int) = (void(__cdecl*)(int, int))0x004b068e;
CARM95_HOOK_FUNCTION(original_DrawGames, DrawGames)
void __cdecl DrawGames(int pCurrent_choice, int pCurrent_mode) {
    int i;
    int font_index;
    int current_index;
    int x_coord;
    int y_coord;
    char s[256];
    char *s2;
    char *s3;
    LOG_TRACE("(%d, %d)", pCurrent_choice, pCurrent_mode);

    (void)pCurrent_choice;
    (void)pCurrent_mode;
    (void)i;
    (void)font_index;
    (void)current_index;
    (void)x_coord;
    (void)y_coord;
    (void)s;
    (void)s2;
    (void)s3;

    if (function_hook_state_DrawGames == HOOK_ENABLED) {
        assert(0 && "DrawGames not implemented.");
        abort();
    } else {
        original_DrawGames(pCurrent_choice, pCurrent_mode);
    }
}

function_hook_state_t function_hook_state_InitGamesToJoin = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(InitGamesToJoin, function_hook_state_InitGamesToJoin)
static void(__cdecl*original_InitGamesToJoin)() = (void(__cdecl*)())0x004b1253;
CARM95_HOOK_FUNCTION(original_InitGamesToJoin, InitGamesToJoin)
void __cdecl InitGamesToJoin() {
    int i;
    LOG_TRACE("()");

    (void)i;

    if (function_hook_state_InitGamesToJoin == HOOK_ENABLED) {
        assert(0 && "InitGamesToJoin not implemented.");
        abort();
    } else {
        original_InitGamesToJoin();
    }
}

function_hook_state_t function_hook_state_DisposeJoinList = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(DisposeJoinList, function_hook_state_DisposeJoinList)
static void(__cdecl*original_DisposeJoinList)(int) = (void(__cdecl*)(int))0x004b1297;
CARM95_HOOK_FUNCTION(original_DisposeJoinList, DisposeJoinList)
void __cdecl DisposeJoinList(int pExemption) {
    int i;
    LOG_TRACE("(%d)", pExemption);

    (void)pExemption;
    (void)i;

    if (function_hook_state_DisposeJoinList == HOOK_ENABLED) {
        assert(0 && "DisposeJoinList not implemented.");
        abort();
    } else {
        original_DisposeJoinList(pExemption);
    }
}

function_hook_state_t function_hook_state_AddToJoinList = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(AddToJoinList, function_hook_state_AddToJoinList)
static void(__cdecl*original_AddToJoinList)(tNet_game_details *) = (void(__cdecl*)(tNet_game_details *))0x004b0f0f;
CARM95_HOOK_FUNCTION(original_AddToJoinList, AddToJoinList)
void __cdecl AddToJoinList(tNet_game_details *pGame) {
    int i;
    int slot_to_use;
    tU32 this_game_ID;
    LOG_TRACE("(%p)", pGame);

    (void)pGame;
    (void)i;
    (void)slot_to_use;
    (void)this_game_ID;

    if (function_hook_state_AddToJoinList == HOOK_ENABLED) {
        assert(0 && "AddToJoinList not implemented.");
        abort();
    } else {
        original_AddToJoinList(pGame);
    }
}

function_hook_state_t function_hook_state_NewNetStart1 = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(NewNetStart1, function_hook_state_NewNetStart1)
static void(__cdecl*original_NewNetStart1)() = (void(__cdecl*)())0x004b0fff;
CARM95_HOOK_FUNCTION(original_NewNetStart1, NewNetStart1)
void __cdecl NewNetStart1() {
    LOG_TRACE("()");


    if (function_hook_state_NewNetStart1 == HOOK_ENABLED) {
        assert(0 && "NewNetStart1 not implemented.");
        abort();
    } else {
        original_NewNetStart1();
    }
}

function_hook_state_t function_hook_state_NewNetStart2 = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(NewNetStart2, function_hook_state_NewNetStart2)
static void(__cdecl*original_NewNetStart2)() = (void(__cdecl*)())0x004b105d;
CARM95_HOOK_FUNCTION(original_NewNetStart2, NewNetStart2)
void __cdecl NewNetStart2() {
    LOG_TRACE("()");


    if (function_hook_state_NewNetStart2 == HOOK_ENABLED) {
        assert(0 && "NewNetStart2 not implemented.");
        abort();
    } else {
        original_NewNetStart2();
    }
}

function_hook_state_t function_hook_state_NewNetGetName = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(NewNetGetName, function_hook_state_NewNetGetName)
static void(__cdecl*original_NewNetGetName)(int, int, char *, int *) = (void(__cdecl*)(int, int, char *, int *))0x004b1083;
CARM95_HOOK_FUNCTION(original_NewNetGetName, NewNetGetName)
void __cdecl NewNetGetName(int pStarting_to_type, int pCurrent_choice, char *pString, int *pMax_length) {
    LOG_TRACE("(%d, %d, \"%s\", %p)", pStarting_to_type, pCurrent_choice, pString, pMax_length);

    (void)pStarting_to_type;
    (void)pCurrent_choice;
    (void)pString;
    (void)pMax_length;

    if (function_hook_state_NewNetGetName == HOOK_ENABLED) {
        assert(0 && "NewNetGetName not implemented.");
        abort();
    } else {
        original_NewNetGetName(pStarting_to_type, pCurrent_choice, pString, pMax_length);
    }
}

function_hook_state_t function_hook_state_NewNetDone = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(NewNetDone, function_hook_state_NewNetDone)
static int(__cdecl*original_NewNetDone)(int, int, int, int, int) = (int(__cdecl*)(int, int, int, int, int))0x004b10be;
CARM95_HOOK_FUNCTION(original_NewNetDone, NewNetDone)
int __cdecl NewNetDone(int pCurrent_choice, int pCurrent_mode, int pGo_ahead, int pEscaped, int pTimed_out) {
    LOG_TRACE("(%d, %d, %d, %d, %d)", pCurrent_choice, pCurrent_mode, pGo_ahead, pEscaped, pTimed_out);

    (void)pCurrent_choice;
    (void)pCurrent_mode;
    (void)pGo_ahead;
    (void)pEscaped;
    (void)pTimed_out;

    if (function_hook_state_NewNetDone == HOOK_ENABLED) {
        assert(0 && "NewNetDone not implemented.");
        abort();
    } else {
        return original_NewNetDone(pCurrent_choice, pCurrent_mode, pGo_ahead, pEscaped, pTimed_out);
    }
}

function_hook_state_t function_hook_state_NewNetGoAhead = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(NewNetGoAhead, function_hook_state_NewNetGoAhead)
static int(__cdecl*original_NewNetGoAhead)(int *, int *) = (int(__cdecl*)(int *, int *))0x004b10ea;
CARM95_HOOK_FUNCTION(original_NewNetGoAhead, NewNetGoAhead)
int __cdecl NewNetGoAhead(int *pCurrent_choice, int *pCurrent_mode) {
    LOG_TRACE("(%p, %p)", pCurrent_choice, pCurrent_mode);

    (void)pCurrent_choice;
    (void)pCurrent_mode;

    if (function_hook_state_NewNetGoAhead == HOOK_ENABLED) {
        assert(0 && "NewNetGoAhead not implemented.");
        abort();
    } else {
        return original_NewNetGoAhead(pCurrent_choice, pCurrent_mode);
    }
}

function_hook_state_t function_hook_state_JoinOrHostGame = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(JoinOrHostGame, function_hook_state_JoinOrHostGame)
static tJoin_or_host_result(__cdecl*original_JoinOrHostGame)(tNet_game_details **) = (tJoin_or_host_result(__cdecl*)(tNet_game_details **))0x004b1113;
CARM95_HOOK_FUNCTION(original_JoinOrHostGame, JoinOrHostGame)
tJoin_or_host_result __cdecl JoinOrHostGame(tNet_game_details **pGame_to_join) {
    static tFlicette flicker_on[2];
    static tFlicette flicker_off[2];
    static tFlicette push[2];
    static tMouse_area mouse_areas[3];
    static tRectile recopy_areas[1];
    static tInterface_spec interface_spec;
    int result;
    LOG_TRACE("(%p)", pGame_to_join);

    (void)pGame_to_join;
    (void)flicker_on;
    (void)flicker_off;
    (void)push;
    (void)mouse_areas;
    (void)recopy_areas;
    (void)interface_spec;
    (void)result;

    if (function_hook_state_JoinOrHostGame == HOOK_ENABLED) {
        assert(0 && "JoinOrHostGame not implemented.");
        abort();
    } else {
        return original_JoinOrHostGame(pGame_to_join);
    }
}

function_hook_state_t function_hook_state_GetNetOptions = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(GetNetOptions, function_hook_state_GetNetOptions)
static void(__cdecl*original_GetNetOptions)(tNet_game_options *) = (void(__cdecl*)(tNet_game_options *))0x004b2d9b;
CARM95_HOOK_FUNCTION(original_GetNetOptions, GetNetOptions)
void __cdecl GetNetOptions(tNet_game_options *pGame_options) {
    LOG_TRACE("(%p)", pGame_options);

    (void)pGame_options;

    if (function_hook_state_GetNetOptions == HOOK_ENABLED) {
        assert(0 && "GetNetOptions not implemented.");
        abort();
    } else {
        original_GetNetOptions(pGame_options);
    }
}

function_hook_state_t function_hook_state_SetNetOptions = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(SetNetOptions, function_hook_state_SetNetOptions)
static void(__cdecl*original_SetNetOptions)(tNet_game_options *) = (void(__cdecl*)(tNet_game_options *))0x004b1b29;
CARM95_HOOK_FUNCTION(original_SetNetOptions, SetNetOptions)
void __cdecl SetNetOptions(tNet_game_options *pGame_options) {
    LOG_TRACE("(%p)", pGame_options);

    (void)pGame_options;

    if (function_hook_state_SetNetOptions == HOOK_ENABLED) {
        assert(0 && "SetNetOptions not implemented.");
        abort();
    } else {
        original_SetNetOptions(pGame_options);
    }
}

function_hook_state_t function_hook_state_NetPlayCheckboxOn2 = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(NetPlayCheckboxOn2, function_hook_state_NetPlayCheckboxOn2)
static void(__cdecl*original_NetPlayCheckboxOn2)(int) = (void(__cdecl*)(int))0x004b13e5;
CARM95_HOOK_FUNCTION(original_NetPlayCheckboxOn2, NetPlayCheckboxOn2)
void __cdecl NetPlayCheckboxOn2(int pIndex) {
    LOG_TRACE("(%d)", pIndex);

    (void)pIndex;

    if (function_hook_state_NetPlayCheckboxOn2 == HOOK_ENABLED) {
        assert(0 && "NetPlayCheckboxOn2 not implemented.");
        abort();
    } else {
        original_NetPlayCheckboxOn2(pIndex);
    }
}

function_hook_state_t function_hook_state_NetPlayCheckboxOff2 = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(NetPlayCheckboxOff2, function_hook_state_NetPlayCheckboxOff2)
static void(__cdecl*original_NetPlayCheckboxOff2)(int) = (void(__cdecl*)(int))0x004b1415;
CARM95_HOOK_FUNCTION(original_NetPlayCheckboxOff2, NetPlayCheckboxOff2)
void __cdecl NetPlayCheckboxOff2(int pIndex) {
    LOG_TRACE("(%d)", pIndex);

    (void)pIndex;

    if (function_hook_state_NetPlayCheckboxOff2 == HOOK_ENABLED) {
        assert(0 && "NetPlayCheckboxOff2 not implemented.");
        abort();
    } else {
        original_NetPlayCheckboxOff2(pIndex);
    }
}

function_hook_state_t function_hook_state_NetPlayCheckboxOn = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(NetPlayCheckboxOn, function_hook_state_NetPlayCheckboxOn)
static void(__cdecl*original_NetPlayCheckboxOn)(int) = (void(__cdecl*)(int))0x004b167d;
CARM95_HOOK_FUNCTION(original_NetPlayCheckboxOn, NetPlayCheckboxOn)
void __cdecl NetPlayCheckboxOn(int pIndex) {
    LOG_TRACE("(%d)", pIndex);

    (void)pIndex;

    if (function_hook_state_NetPlayCheckboxOn == HOOK_ENABLED) {
        assert(0 && "NetPlayCheckboxOn not implemented.");
        abort();
    } else {
        original_NetPlayCheckboxOn(pIndex);
    }
}

function_hook_state_t function_hook_state_NetPlayCheckboxOff = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(NetPlayCheckboxOff, function_hook_state_NetPlayCheckboxOff)
static void(__cdecl*original_NetPlayCheckboxOff)(int) = (void(__cdecl*)(int))0x004b16b2;
CARM95_HOOK_FUNCTION(original_NetPlayCheckboxOff, NetPlayCheckboxOff)
void __cdecl NetPlayCheckboxOff(int pIndex) {
    LOG_TRACE("(%d)", pIndex);

    (void)pIndex;

    if (function_hook_state_NetPlayCheckboxOff == HOOK_ENABLED) {
        assert(0 && "NetPlayCheckboxOff not implemented.");
        abort();
    } else {
        original_NetPlayCheckboxOff(pIndex);
    }
}

function_hook_state_t function_hook_state_NetPlayRadioOn2 = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(NetPlayRadioOn2, function_hook_state_NetPlayRadioOn2)
static void(__cdecl*original_NetPlayRadioOn2)(int, int) = (void(__cdecl*)(int, int))0x004b1445;
CARM95_HOOK_FUNCTION(original_NetPlayRadioOn2, NetPlayRadioOn2)
void __cdecl NetPlayRadioOn2(int pIndex, int pValue) {
    LOG_TRACE("(%d, %d)", pIndex, pValue);

    (void)pIndex;
    (void)pValue;

    if (function_hook_state_NetPlayRadioOn2 == HOOK_ENABLED) {
        assert(0 && "NetPlayRadioOn2 not implemented.");
        abort();
    } else {
        original_NetPlayRadioOn2(pIndex, pValue);
    }
}

function_hook_state_t function_hook_state_NetPlayRadioOff2 = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(NetPlayRadioOff2, function_hook_state_NetPlayRadioOff2)
static void(__cdecl*original_NetPlayRadioOff2)(int, int) = (void(__cdecl*)(int, int))0x004b147c;
CARM95_HOOK_FUNCTION(original_NetPlayRadioOff2, NetPlayRadioOff2)
void __cdecl NetPlayRadioOff2(int pIndex, int pValue) {
    LOG_TRACE("(%d, %d)", pIndex, pValue);

    (void)pIndex;
    (void)pValue;

    if (function_hook_state_NetPlayRadioOff2 == HOOK_ENABLED) {
        assert(0 && "NetPlayRadioOff2 not implemented.");
        abort();
    } else {
        original_NetPlayRadioOff2(pIndex, pValue);
    }
}

function_hook_state_t function_hook_state_NetPlayRadioOn = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(NetPlayRadioOn, function_hook_state_NetPlayRadioOn)
static void(__cdecl*original_NetPlayRadioOn)(int, int) = (void(__cdecl*)(int, int))0x004b1598;
CARM95_HOOK_FUNCTION(original_NetPlayRadioOn, NetPlayRadioOn)
void __cdecl NetPlayRadioOn(int pIndex, int pValue) {
    LOG_TRACE("(%d, %d)", pIndex, pValue);

    (void)pIndex;
    (void)pValue;

    if (function_hook_state_NetPlayRadioOn == HOOK_ENABLED) {
        assert(0 && "NetPlayRadioOn not implemented.");
        abort();
    } else {
        original_NetPlayRadioOn(pIndex, pValue);
    }
}

function_hook_state_t function_hook_state_NetPlayRadioOff = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(NetPlayRadioOff, function_hook_state_NetPlayRadioOff)
static void(__cdecl*original_NetPlayRadioOff)(int, int) = (void(__cdecl*)(int, int))0x004b15d1;
CARM95_HOOK_FUNCTION(original_NetPlayRadioOff, NetPlayRadioOff)
void __cdecl NetPlayRadioOff(int pIndex, int pValue) {
    LOG_TRACE("(%d, %d)", pIndex, pValue);

    (void)pIndex;
    (void)pValue;

    if (function_hook_state_NetPlayRadioOff == HOOK_ENABLED) {
        assert(0 && "NetPlayRadioOff not implemented.");
        abort();
    } else {
        original_NetPlayRadioOff(pIndex, pValue);
    }
}

function_hook_state_t function_hook_state_DrawNOptInitialRadios = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(DrawNOptInitialRadios, function_hook_state_DrawNOptInitialRadios)
static void(__cdecl*original_DrawNOptInitialRadios)() = (void(__cdecl*)())0x004b12ec;
CARM95_HOOK_FUNCTION(original_DrawNOptInitialRadios, DrawNOptInitialRadios)
void __cdecl DrawNOptInitialRadios() {
    int i;
    int j;
    LOG_TRACE("()");

    (void)i;
    (void)j;

    if (function_hook_state_DrawNOptInitialRadios == HOOK_ENABLED) {
        assert(0 && "DrawNOptInitialRadios not implemented.");
        abort();
    } else {
        original_DrawNOptInitialRadios();
    }
}

function_hook_state_t function_hook_state_NetRadioChanged = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(NetRadioChanged, function_hook_state_NetRadioChanged)
static void(__cdecl*original_NetRadioChanged)(int, int) = (void(__cdecl*)(int, int))0x004b1555;
CARM95_HOOK_FUNCTION(original_NetRadioChanged, NetRadioChanged)
void __cdecl NetRadioChanged(int pIndex, int pNew_value) {
    LOG_TRACE("(%d, %d)", pIndex, pNew_value);

    (void)pIndex;
    (void)pNew_value;

    if (function_hook_state_NetRadioChanged == HOOK_ENABLED) {
        assert(0 && "NetRadioChanged not implemented.");
        abort();
    } else {
        original_NetRadioChanged(pIndex, pNew_value);
    }
}

function_hook_state_t function_hook_state_NetCheckboxChanged = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(NetCheckboxChanged, function_hook_state_NetCheckboxChanged)
static void(__cdecl*original_NetCheckboxChanged)(int) = (void(__cdecl*)(int))0x004b160a;
CARM95_HOOK_FUNCTION(original_NetCheckboxChanged, NetCheckboxChanged)
void __cdecl NetCheckboxChanged(int pIndex) {
    LOG_TRACE("(%d)", pIndex);

    (void)pIndex;

    if (function_hook_state_NetCheckboxChanged == HOOK_ENABLED) {
        assert(0 && "NetCheckboxChanged not implemented.");
        abort();
    } else {
        original_NetCheckboxChanged(pIndex);
    }
}

function_hook_state_t function_hook_state_NetOptLeft = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(NetOptLeft, function_hook_state_NetOptLeft)
static int(__cdecl*original_NetOptLeft)(int *, int *) = (int(__cdecl*)(int *, int *))0x004b14b3;
CARM95_HOOK_FUNCTION(original_NetOptLeft, NetOptLeft)
int __cdecl NetOptLeft(int *pCurrent_choice, int *pCurrent_mode) {
    int new_value;
    LOG_TRACE("(%p, %p)", pCurrent_choice, pCurrent_mode);

    (void)pCurrent_choice;
    (void)pCurrent_mode;
    (void)new_value;

    if (function_hook_state_NetOptLeft == HOOK_ENABLED) {
        assert(0 && "NetOptLeft not implemented.");
        abort();
    } else {
        return original_NetOptLeft(pCurrent_choice, pCurrent_mode);
    }
}

function_hook_state_t function_hook_state_NetOptRight = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(NetOptRight, function_hook_state_NetOptRight)
static int(__cdecl*original_NetOptRight)(int *, int *) = (int(__cdecl*)(int *, int *))0x004b16e7;
CARM95_HOOK_FUNCTION(original_NetOptRight, NetOptRight)
int __cdecl NetOptRight(int *pCurrent_choice, int *pCurrent_mode) {
    int new_value;
    LOG_TRACE("(%p, %p)", pCurrent_choice, pCurrent_mode);

    (void)pCurrent_choice;
    (void)pCurrent_mode;
    (void)new_value;

    if (function_hook_state_NetOptRight == HOOK_ENABLED) {
        assert(0 && "NetOptRight not implemented.");
        abort();
    } else {
        return original_NetOptRight(pCurrent_choice, pCurrent_mode);
    }
}

function_hook_state_t function_hook_state_NetOptUp = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(NetOptUp, function_hook_state_NetOptUp)
static int(__cdecl*original_NetOptUp)(int *, int *) = (int(__cdecl*)(int *, int *))0x004b178b;
CARM95_HOOK_FUNCTION(original_NetOptUp, NetOptUp)
int __cdecl NetOptUp(int *pCurrent_choice, int *pCurrent_mode) {
    LOG_TRACE("(%p, %p)", pCurrent_choice, pCurrent_mode);

    (void)pCurrent_choice;
    (void)pCurrent_mode;

    if (function_hook_state_NetOptUp == HOOK_ENABLED) {
        assert(0 && "NetOptUp not implemented.");
        abort();
    } else {
        return original_NetOptUp(pCurrent_choice, pCurrent_mode);
    }
}

function_hook_state_t function_hook_state_NetOptDown = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(NetOptDown, function_hook_state_NetOptDown)
static int(__cdecl*original_NetOptDown)(int *, int *) = (int(__cdecl*)(int *, int *))0x004b181d;
CARM95_HOOK_FUNCTION(original_NetOptDown, NetOptDown)
int __cdecl NetOptDown(int *pCurrent_choice, int *pCurrent_mode) {
    LOG_TRACE("(%p, %p)", pCurrent_choice, pCurrent_mode);

    (void)pCurrent_choice;
    (void)pCurrent_mode;

    if (function_hook_state_NetOptDown == HOOK_ENABLED) {
        assert(0 && "NetOptDown not implemented.");
        abort();
    } else {
        return original_NetOptDown(pCurrent_choice, pCurrent_mode);
    }
}

function_hook_state_t function_hook_state_NetRadioClick = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(NetRadioClick, function_hook_state_NetRadioClick)
static int(__cdecl*original_NetRadioClick)(int *, int *, int, int) = (int(__cdecl*)(int *, int *, int, int))0x004b18af;
CARM95_HOOK_FUNCTION(original_NetRadioClick, NetRadioClick)
int __cdecl NetRadioClick(int *pCurrent_choice, int *pCurrent_mode, int pX_offset, int pY_offset) {
    int i;
    LOG_TRACE("(%p, %p, %d, %d)", pCurrent_choice, pCurrent_mode, pX_offset, pY_offset);

    (void)pCurrent_choice;
    (void)pCurrent_mode;
    (void)pX_offset;
    (void)pY_offset;
    (void)i;

    if (function_hook_state_NetRadioClick == HOOK_ENABLED) {
        assert(0 && "NetRadioClick not implemented.");
        abort();
    } else {
        return original_NetRadioClick(pCurrent_choice, pCurrent_mode, pX_offset, pY_offset);
    }
}

function_hook_state_t function_hook_state_RevertToDefaults = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(RevertToDefaults, function_hook_state_RevertToDefaults)
static void(__cdecl*original_RevertToDefaults)() = (void(__cdecl*)())0x004b1a8e;
CARM95_HOOK_FUNCTION(original_RevertToDefaults, RevertToDefaults)
void __cdecl RevertToDefaults() {
    tPath_name the_path;
    FILE *f;
    tNet_game_options net_options;
    int i;
    LOG_TRACE("()");

    (void)the_path;
    (void)f;
    (void)net_options;
    (void)i;

    if (function_hook_state_RevertToDefaults == HOOK_ENABLED) {
        assert(0 && "RevertToDefaults not implemented.");
        abort();
    } else {
        original_RevertToDefaults();
    }
}

function_hook_state_t function_hook_state_DefaultNetSettings = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(DefaultNetSettings, function_hook_state_DefaultNetSettings)
static void(__cdecl*original_DefaultNetSettings)() = (void(__cdecl*)())0x004b1984;
CARM95_HOOK_FUNCTION(original_DefaultNetSettings, DefaultNetSettings)
void __cdecl DefaultNetSettings() {
    tPath_name the_path;
    FILE *f;
    int i;
    LOG_TRACE("()");

    (void)the_path;
    (void)f;
    (void)i;

    if (function_hook_state_DefaultNetSettings == HOOK_ENABLED) {
        assert(0 && "DefaultNetSettings not implemented.");
        abort();
    } else {
        original_DefaultNetSettings();
    }
}

function_hook_state_t function_hook_state_NetOptGoAhead = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(NetOptGoAhead, function_hook_state_NetOptGoAhead)
static int(__cdecl*original_NetOptGoAhead)(int *, int *) = (int(__cdecl*)(int *, int *))0x004b1a34;
CARM95_HOOK_FUNCTION(original_NetOptGoAhead, NetOptGoAhead)
int __cdecl NetOptGoAhead(int *pCurrent_choice, int *pCurrent_mode) {
    LOG_TRACE("(%p, %p)", pCurrent_choice, pCurrent_mode);

    (void)pCurrent_choice;
    (void)pCurrent_mode;

    if (function_hook_state_NetOptGoAhead == HOOK_ENABLED) {
        assert(0 && "NetOptGoAhead not implemented.");
        abort();
    } else {
        return original_NetOptGoAhead(pCurrent_choice, pCurrent_mode);
    }
}

function_hook_state_t function_hook_state_NetPlotAGraphBox = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(NetPlotAGraphBox, function_hook_state_NetPlotAGraphBox)
static void(__cdecl*original_NetPlotAGraphBox)(int, int) = (void(__cdecl*)(int, int))0x004b1c58;
CARM95_HOOK_FUNCTION(original_NetPlotAGraphBox, NetPlotAGraphBox)
void __cdecl NetPlotAGraphBox(int pIndex, int pColour_value) {
    LOG_TRACE("(%d, %d)", pIndex, pColour_value);

    (void)pIndex;
    (void)pColour_value;

    if (function_hook_state_NetPlotAGraphBox == HOOK_ENABLED) {
        assert(0 && "NetPlotAGraphBox not implemented.");
        abort();
    } else {
        original_NetPlotAGraphBox(pIndex, pColour_value);
    }
}

function_hook_state_t function_hook_state_NetDrawAGraphBox = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(NetDrawAGraphBox, function_hook_state_NetDrawAGraphBox)
static void(__cdecl*original_NetDrawAGraphBox)(int) = (void(__cdecl*)(int))0x004b1c3f;
CARM95_HOOK_FUNCTION(original_NetDrawAGraphBox, NetDrawAGraphBox)
void __cdecl NetDrawAGraphBox(int pIndex) {
    LOG_TRACE("(%d)", pIndex);

    (void)pIndex;

    if (function_hook_state_NetDrawAGraphBox == HOOK_ENABLED) {
        assert(0 && "NetDrawAGraphBox not implemented.");
        abort();
    } else {
        original_NetDrawAGraphBox(pIndex);
    }
}

function_hook_state_t function_hook_state_NetEraseAGraphBox = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(NetEraseAGraphBox, function_hook_state_NetEraseAGraphBox)
static void(__cdecl*original_NetEraseAGraphBox)(int) = (void(__cdecl*)(int))0x004b1d0a;
CARM95_HOOK_FUNCTION(original_NetEraseAGraphBox, NetEraseAGraphBox)
void __cdecl NetEraseAGraphBox(int pIndex) {
    LOG_TRACE("(%d)", pIndex);

    (void)pIndex;

    if (function_hook_state_NetEraseAGraphBox == HOOK_ENABLED) {
        assert(0 && "NetEraseAGraphBox not implemented.");
        abort();
    } else {
        original_NetEraseAGraphBox(pIndex);
    }
}

function_hook_state_t function_hook_state_DrawNetOptBox = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(DrawNetOptBox, function_hook_state_DrawNetOptBox)
static void(__cdecl*original_DrawNetOptBox)(int, int) = (void(__cdecl*)(int, int))0x004b1bfd;
CARM95_HOOK_FUNCTION(original_DrawNetOptBox, DrawNetOptBox)
void __cdecl DrawNetOptBox(int pCurrent_choice, int pCurrent_mode) {
    LOG_TRACE("(%d, %d)", pCurrent_choice, pCurrent_mode);

    (void)pCurrent_choice;
    (void)pCurrent_mode;

    if (function_hook_state_DrawNetOptBox == HOOK_ENABLED) {
        assert(0 && "DrawNetOptBox not implemented.");
        abort();
    } else {
        original_DrawNetOptBox(pCurrent_choice, pCurrent_mode);
    }
}

function_hook_state_t function_hook_state_DoNetOptions = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(DoNetOptions, function_hook_state_DoNetOptions)
static void(__cdecl*original_DoNetOptions)(tNet_game_options *) = (void(__cdecl*)(tNet_game_options *))0x004b2d37;
CARM95_HOOK_FUNCTION(original_DoNetOptions, DoNetOptions)
void __cdecl DoNetOptions(tNet_game_options *pGame_options) {
    static tFlicette flicker_on[14];
    static tFlicette flicker_off[14];
    static tFlicette push[14];
    static tMouse_area mouse_areas[14];
    static tInterface_spec interface_spec;
    LOG_TRACE("(%p)", pGame_options);

    (void)pGame_options;
    (void)flicker_on;
    (void)flicker_off;
    (void)push;
    (void)mouse_areas;
    (void)interface_spec;

    if (function_hook_state_DoNetOptions == HOOK_ENABLED) {
        assert(0 && "DoNetOptions not implemented.");
        abort();
    } else {
        original_DoNetOptions(pGame_options);
    }
}

function_hook_state_t function_hook_state_SetOptions = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(SetOptions, function_hook_state_SetOptions)
static void(__cdecl*original_SetOptions)(tNet_game_type, tNet_game_options *) = (void(__cdecl*)(tNet_game_type, tNet_game_options *))0x004b1e95;
CARM95_HOOK_FUNCTION(original_SetOptions, SetOptions)
void __cdecl SetOptions(tNet_game_type pGame_type, tNet_game_options *pGame_options) {
    LOG_TRACE("(%d, %p)", pGame_type, pGame_options);

    (void)pGame_type;
    (void)pGame_options;

    if (function_hook_state_SetOptions == HOOK_ENABLED) {
        assert(0 && "SetOptions not implemented.");
        abort();
    } else {
        original_SetOptions(pGame_type, pGame_options);
    }
}

function_hook_state_t function_hook_state_PlayRadioOn__newgame = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(PlayRadioOn__newgame, function_hook_state_PlayRadioOn__newgame)
static void(__cdecl*original_PlayRadioOn__newgame)(int) = (void(__cdecl*)(int))0x004b1d3c;
CARM95_HOOK_FUNCTION(original_PlayRadioOn__newgame, PlayRadioOn__newgame)
void __cdecl PlayRadioOn__newgame(int pIndex) {
    LOG_TRACE("(%d)", pIndex);

    (void)pIndex;

    if (function_hook_state_PlayRadioOn__newgame == HOOK_ENABLED) {
        assert(0 && "PlayRadioOn__newgame not implemented.");
        abort();
    } else {
        original_PlayRadioOn__newgame(pIndex);
    }
}

function_hook_state_t function_hook_state_PlayRadioOff__newgame = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(PlayRadioOff__newgame, function_hook_state_PlayRadioOff__newgame)
static void(__cdecl*original_PlayRadioOff__newgame)(int) = (void(__cdecl*)(int))0x004b1f33;
CARM95_HOOK_FUNCTION(original_PlayRadioOff__newgame, PlayRadioOff__newgame)
void __cdecl PlayRadioOff__newgame(int pIndex) {
    LOG_TRACE("(%d)", pIndex);

    (void)pIndex;

    if (function_hook_state_PlayRadioOff__newgame == HOOK_ENABLED) {
        assert(0 && "PlayRadioOff__newgame not implemented.");
        abort();
    } else {
        original_PlayRadioOff__newgame(pIndex);
    }
}

function_hook_state_t function_hook_state_DrawNetChooseInitial = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(DrawNetChooseInitial, function_hook_state_DrawNetChooseInitial)
static void(__cdecl*original_DrawNetChooseInitial)() = (void(__cdecl*)())0x004b1d23;
CARM95_HOOK_FUNCTION(original_DrawNetChooseInitial, DrawNetChooseInitial)
void __cdecl DrawNetChooseInitial() {
    LOG_TRACE("()");


    if (function_hook_state_DrawNetChooseInitial == HOOK_ENABLED) {
        assert(0 && "DrawNetChooseInitial not implemented.");
        abort();
    } else {
        original_DrawNetChooseInitial();
    }
}

function_hook_state_t function_hook_state_NetChooseGoAhead = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(NetChooseGoAhead, function_hook_state_NetChooseGoAhead)
static int(__cdecl*original_NetChooseGoAhead)(int *, int *) = (int(__cdecl*)(int *, int *))0x004b1d9c;
CARM95_HOOK_FUNCTION(original_NetChooseGoAhead, NetChooseGoAhead)
int __cdecl NetChooseGoAhead(int *pCurrent_choice, int *pCurrent_mode) {
    LOG_TRACE("(%p, %p)", pCurrent_choice, pCurrent_mode);

    (void)pCurrent_choice;
    (void)pCurrent_mode;

    if (function_hook_state_NetChooseGoAhead == HOOK_ENABLED) {
        assert(0 && "NetChooseGoAhead not implemented.");
        abort();
    } else {
        return original_NetChooseGoAhead(pCurrent_choice, pCurrent_mode);
    }
}

function_hook_state_t function_hook_state_PlotAGraphBox__newgame = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(PlotAGraphBox__newgame, function_hook_state_PlotAGraphBox__newgame)
static void(__cdecl*original_PlotAGraphBox__newgame)(int, int) = (void(__cdecl*)(int, int))0x004b2277;
CARM95_HOOK_FUNCTION(original_PlotAGraphBox__newgame, PlotAGraphBox__newgame)
void __cdecl PlotAGraphBox__newgame(int pIndex, int pColour_value) {
    LOG_TRACE("(%d, %d)", pIndex, pColour_value);

    (void)pIndex;
    (void)pColour_value;

    if (function_hook_state_PlotAGraphBox__newgame == HOOK_ENABLED) {
        assert(0 && "PlotAGraphBox__newgame not implemented.");
        abort();
    } else {
        original_PlotAGraphBox__newgame(pIndex, pColour_value);
    }
}

function_hook_state_t function_hook_state_DrawAGraphBox__newgame = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(DrawAGraphBox__newgame, function_hook_state_DrawAGraphBox__newgame)
static void(__cdecl*original_DrawAGraphBox__newgame)(int) = (void(__cdecl*)(int))0x004b225e;
CARM95_HOOK_FUNCTION(original_DrawAGraphBox__newgame, DrawAGraphBox__newgame)
void __cdecl DrawAGraphBox__newgame(int pIndex) {
    LOG_TRACE("(%d)", pIndex);

    (void)pIndex;

    if (function_hook_state_DrawAGraphBox__newgame == HOOK_ENABLED) {
        assert(0 && "DrawAGraphBox__newgame not implemented.");
        abort();
    } else {
        original_DrawAGraphBox__newgame(pIndex);
    }
}

function_hook_state_t function_hook_state_EraseAGraphBox__newgame = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(EraseAGraphBox__newgame, function_hook_state_EraseAGraphBox__newgame)
static void(__cdecl*original_EraseAGraphBox__newgame)(int) = (void(__cdecl*)(int))0x004b2325;
CARM95_HOOK_FUNCTION(original_EraseAGraphBox__newgame, EraseAGraphBox__newgame)
void __cdecl EraseAGraphBox__newgame(int pIndex) {
    LOG_TRACE("(%d)", pIndex);

    (void)pIndex;

    if (function_hook_state_EraseAGraphBox__newgame == HOOK_ENABLED) {
        assert(0 && "EraseAGraphBox__newgame not implemented.");
        abort();
    } else {
        original_EraseAGraphBox__newgame(pIndex);
    }
}

function_hook_state_t function_hook_state_DrawNetChoose = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(DrawNetChoose, function_hook_state_DrawNetChoose)
static void(__cdecl*original_DrawNetChoose)(int, int) = (void(__cdecl*)(int, int))0x004b1f93;
CARM95_HOOK_FUNCTION(original_DrawNetChoose, DrawNetChoose)
void __cdecl DrawNetChoose(int pCurrent_choice, int pCurrent_mode) {
    char s[256];
    tU32 *k;
    int i;
    LOG_TRACE("(%d, %d)", pCurrent_choice, pCurrent_mode);

    (void)pCurrent_choice;
    (void)pCurrent_mode;
    (void)s;
    (void)k;
    (void)i;

    if (function_hook_state_DrawNetChoose == HOOK_ENABLED) {
        assert(0 && "DrawNetChoose not implemented.");
        abort();
    } else {
        original_DrawNetChoose(pCurrent_choice, pCurrent_mode);
    }
}

function_hook_state_t function_hook_state_NetChooseLR = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(NetChooseLR, function_hook_state_NetChooseLR)
static int(__cdecl*original_NetChooseLR)(int *, int *) = (int(__cdecl*)(int *, int *))0x004b233e;
CARM95_HOOK_FUNCTION(original_NetChooseLR, NetChooseLR)
int __cdecl NetChooseLR(int *pCurrent_choice, int *pCurrent_mode) {
    LOG_TRACE("(%p, %p)", pCurrent_choice, pCurrent_mode);

    (void)pCurrent_choice;
    (void)pCurrent_mode;

    if (function_hook_state_NetChooseLR == HOOK_ENABLED) {
        assert(0 && "NetChooseLR not implemented.");
        abort();
    } else {
        return original_NetChooseLR(pCurrent_choice, pCurrent_mode);
    }
}

function_hook_state_t function_hook_state_SetGameTarget = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(SetGameTarget, function_hook_state_SetGameTarget)
static void(__cdecl*original_SetGameTarget)(tNet_game_type *, tNet_game_options *) = (void(__cdecl*)(tNet_game_type *, tNet_game_options *))0x004b2e6f;
CARM95_HOOK_FUNCTION(original_SetGameTarget, SetGameTarget)
void __cdecl SetGameTarget(tNet_game_type *pGame_type, tNet_game_options *pGame_options) {
    LOG_TRACE("(%p, %p)", pGame_type, pGame_options);

    (void)pGame_type;
    (void)pGame_options;

    if (function_hook_state_SetGameTarget == HOOK_ENABLED) {
        assert(0 && "SetGameTarget not implemented.");
        abort();
    } else {
        original_SetGameTarget(pGame_type, pGame_options);
    }
}

function_hook_state_t function_hook_state_NetGameChoices = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(NetGameChoices, function_hook_state_NetGameChoices)
static int(__cdecl*original_NetGameChoices)(tNet_game_type *, tNet_game_options *, int *) = (int(__cdecl*)(tNet_game_type *, tNet_game_options *, int *))0x004b2ba3;
CARM95_HOOK_FUNCTION(original_NetGameChoices, NetGameChoices)
int __cdecl NetGameChoices(tNet_game_type *pGame_type, tNet_game_options *pGame_options, int *pRace_index) {
    static tFlicette flicker_on[11];
    static tFlicette flicker_off[11];
    static tFlicette push[11];
    static tMouse_area mouse_areas[11];
    static tInterface_spec interface_spec;
    int result;
    LOG_TRACE("(%p, %p, %p)", pGame_type, pGame_options, pRace_index);

    (void)pGame_type;
    (void)pGame_options;
    (void)pRace_index;
    (void)flicker_on;
    (void)flicker_off;
    (void)push;
    (void)mouse_areas;
    (void)interface_spec;
    (void)result;

    if (function_hook_state_NetGameChoices == HOOK_ENABLED) {
        assert(0 && "NetGameChoices not implemented.");
        abort();
    } else {
        return original_NetGameChoices(pGame_type, pGame_options, pRace_index);
    }
}

function_hook_state_t function_hook_state_ReadNetGameChoices = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(ReadNetGameChoices, function_hook_state_ReadNetGameChoices)
static void(__cdecl*original_ReadNetGameChoices)(tNet_game_type *, tNet_game_options *, int *) = (void(__cdecl*)(tNet_game_type *, tNet_game_options *, int *))0x004b2f38;
CARM95_HOOK_FUNCTION(original_ReadNetGameChoices, ReadNetGameChoices)
void __cdecl ReadNetGameChoices(tNet_game_type *pGame_type, tNet_game_options *pGame_options, int *pRace_index) {
    LOG_TRACE("(%p, %p, %p)", pGame_type, pGame_options, pRace_index);

    (void)pGame_type;
    (void)pGame_options;
    (void)pRace_index;

    if (function_hook_state_ReadNetGameChoices == HOOK_ENABLED) {
        assert(0 && "ReadNetGameChoices not implemented.");
        abort();
    } else {
        original_ReadNetGameChoices(pGame_type, pGame_options, pRace_index);
    }
}

function_hook_state_t function_hook_state_ChooseStartRace = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(ChooseStartRace, function_hook_state_ChooseStartRace)
static int(__cdecl*original_ChooseStartRace)(int *) = (int(__cdecl*)(int *))0x004b235d;
CARM95_HOOK_FUNCTION(original_ChooseStartRace, ChooseStartRace)
int __cdecl ChooseStartRace(int *pRank) {
    LOG_TRACE("(%p)", pRank);

    (void)pRank;

    if (function_hook_state_ChooseStartRace == HOOK_ENABLED) {
        assert(0 && "ChooseStartRace not implemented.");
        abort();
    } else {
        return original_ChooseStartRace(pRank);
    }
}

function_hook_state_t function_hook_state_SetUpOtherNetThings = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(SetUpOtherNetThings, function_hook_state_SetUpOtherNetThings)
static void(__cdecl*original_SetUpOtherNetThings)(tNet_game_details *) = (void(__cdecl*)(tNet_game_details *))0x004b237b;
CARM95_HOOK_FUNCTION(original_SetUpOtherNetThings, SetUpOtherNetThings)
void __cdecl SetUpOtherNetThings(tNet_game_details *pNet_game) {
    LOG_TRACE("(%p)", pNet_game);

    (void)pNet_game;

    if (function_hook_state_SetUpOtherNetThings == HOOK_ENABLED) {
        assert(0 && "SetUpOtherNetThings not implemented.");
        abort();
    } else {
        original_SetUpOtherNetThings(pNet_game);
    }
}

function_hook_state_t function_hook_state_RequestCarDetails = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(RequestCarDetails, function_hook_state_RequestCarDetails)
static void(__cdecl*original_RequestCarDetails)(tNet_game_details *) = (void(__cdecl*)(tNet_game_details *))0x004b246e;
CARM95_HOOK_FUNCTION(original_RequestCarDetails, RequestCarDetails)
void __cdecl RequestCarDetails(tNet_game_details *pNet_game) {
    tNet_message *message;
    LOG_TRACE("(%p)", pNet_game);

    (void)pNet_game;
    (void)message;

    if (function_hook_state_RequestCarDetails == HOOK_ENABLED) {
        assert(0 && "RequestCarDetails not implemented.");
        abort();
    } else {
        original_RequestCarDetails(pNet_game);
    }
}

function_hook_state_t function_hook_state_PickARandomCar = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(PickARandomCar, function_hook_state_PickARandomCar)
static int(__cdecl*original_PickARandomCar)() = (int(__cdecl*)())0x004b23a4;
CARM95_HOOK_FUNCTION(original_PickARandomCar, PickARandomCar)
int __cdecl PickARandomCar() {
    int i;
    int cars[120];
    int array_size;
    LOG_TRACE("()");

    (void)i;
    (void)cars;
    (void)array_size;

    if (function_hook_state_PickARandomCar == HOOK_ENABLED) {
        assert(0 && "PickARandomCar not implemented.");
        abort();
    } else {
        return original_PickARandomCar();
    }
}

function_hook_state_t function_hook_state_PollCarDetails = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(PollCarDetails, function_hook_state_PollCarDetails)
static void(__cdecl*original_PollCarDetails)(tNet_game_details *) = (void(__cdecl*)(tNet_game_details *))0x004b244a;
CARM95_HOOK_FUNCTION(original_PollCarDetails, PollCarDetails)
void __cdecl PollCarDetails(tNet_game_details *pNet_game) {
    LOG_TRACE("(%p)", pNet_game);

    (void)pNet_game;

    if (function_hook_state_PollCarDetails == HOOK_ENABLED) {
        assert(0 && "PollCarDetails not implemented.");
        abort();
    } else {
        original_PollCarDetails(pNet_game);
    }
}

function_hook_state_t function_hook_state_SetNetAvailability = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(SetNetAvailability, function_hook_state_SetNetAvailability)
static void(__cdecl*original_SetNetAvailability)(tNet_game_options *) = (void(__cdecl*)(tNet_game_options *))0x004b24c2;
CARM95_HOOK_FUNCTION(original_SetNetAvailability, SetNetAvailability)
void __cdecl SetNetAvailability(tNet_game_options *pOptions) {
    int i;
    LOG_TRACE("(%p)", pOptions);

    (void)pOptions;
    (void)i;

    if (function_hook_state_SetNetAvailability == HOOK_ENABLED) {
        assert(0 && "SetNetAvailability not implemented.");
        abort();
    } else {
        original_SetNetAvailability(pOptions);
    }
}

function_hook_state_t function_hook_state_ChooseNetCar = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(ChooseNetCar, function_hook_state_ChooseNetCar)
static int(__cdecl*original_ChooseNetCar)(tNet_game_details *, tNet_game_options *, int *, int) = (int(__cdecl*)(tNet_game_details *, tNet_game_options *, int *, int))0x004b25fa;
CARM95_HOOK_FUNCTION(original_ChooseNetCar, ChooseNetCar)
int __cdecl ChooseNetCar(tNet_game_details *pNet_game, tNet_game_options *pOptions, int *pCar_index, int pIm_the_host_so_fuck_off) {
    tS32 start_time;
    int i;
    int result;
    int car_index;
    int the_car_index;
    LOG_TRACE("(%p, %p, %p, %d)", pNet_game, pOptions, pCar_index, pIm_the_host_so_fuck_off);

    (void)pNet_game;
    (void)pOptions;
    (void)pCar_index;
    (void)pIm_the_host_so_fuck_off;
    (void)start_time;
    (void)i;
    (void)result;
    (void)car_index;
    (void)the_car_index;

    if (function_hook_state_ChooseNetCar == HOOK_ENABLED) {
        assert(0 && "ChooseNetCar not implemented.");
        abort();
    } else {
        return original_ChooseNetCar(pNet_game, pOptions, pCar_index, pIm_the_host_so_fuck_off);
    }
}

function_hook_state_t function_hook_state_InitNetStorageSpace = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(InitNetStorageSpace, function_hook_state_InitNetStorageSpace)
static void(__cdecl*original_InitNetStorageSpace)() = (void(__cdecl*)())0x004b2f85;
CARM95_HOOK_FUNCTION(original_InitNetStorageSpace, InitNetStorageSpace)
void __cdecl InitNetStorageSpace() {
    int i;
    LOG_TRACE("()");

    (void)i;

    if (function_hook_state_InitNetStorageSpace == HOOK_ENABLED) {
        assert(0 && "InitNetStorageSpace not implemented.");
        abort();
    } else {
        original_InitNetStorageSpace();
    }
}

function_hook_state_t function_hook_state_DisposeNetStorageSpace = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(DisposeNetStorageSpace, function_hook_state_DisposeNetStorageSpace)
static void(__cdecl*original_DisposeNetStorageSpace)() = (void(__cdecl*)())0x004b2fe9;
CARM95_HOOK_FUNCTION(original_DisposeNetStorageSpace, DisposeNetStorageSpace)
void __cdecl DisposeNetStorageSpace() {
    LOG_TRACE("()");


    if (function_hook_state_DisposeNetStorageSpace == HOOK_ENABLED) {
        assert(0 && "DisposeNetStorageSpace not implemented.");
        abort();
    } else {
        original_DisposeNetStorageSpace();
    }
}

function_hook_state_t function_hook_state_DoMultiPlayerStart = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(DoMultiPlayerStart, function_hook_state_DoMultiPlayerStart)
static int(__cdecl*original_DoMultiPlayerStart)() = (int(__cdecl*)())0x004b27a7;
CARM95_HOOK_FUNCTION(original_DoMultiPlayerStart, DoMultiPlayerStart)
int __cdecl DoMultiPlayerStart() {
    tJoin_or_host_result result;
    tNet_game_details *game_to_join;
    char s[256];
    char *s2;
    tNet_game_type new_game_type;
    tNet_game_options new_game_options;
    int start_rank;
    int car_index;
    LOG_TRACE("()");

    (void)result;
    (void)game_to_join;
    (void)s;
    (void)s2;
    (void)new_game_type;
    (void)new_game_options;
    (void)start_rank;
    (void)car_index;

    if (function_hook_state_DoMultiPlayerStart == HOOK_ENABLED) {
        assert(0 && "DoMultiPlayerStart not implemented.");
        abort();
    } else {
        return original_DoMultiPlayerStart();
    }
}

