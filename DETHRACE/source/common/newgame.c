#include "newgame.h"

#include "harness/trace.h"

#include "carm95_hooks.h"

#include <stdio.h>
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

static void(*original_StartRollingPlayerNamesIn)() = (void(*)())0x004affc4;
CARM95_HOOK_FUNCTION(original_StartRollingPlayerNamesIn, StartRollingPlayerNamesIn)
void StartRollingPlayerNamesIn() {
    int i;
    LOG_TRACE("()");

    (void)i;

    original_StartRollingPlayerNamesIn();
}

static void(*original_FrankAnneStart1)() = (void(*)())0x004afe80;
CARM95_HOOK_FUNCTION(original_FrankAnneStart1, FrankAnneStart1)
void FrankAnneStart1() {
    LOG_TRACE("()");


    original_FrankAnneStart1();
}

static void(*original_FrankAnneStart2)() = (void(*)())0x004b0057;
CARM95_HOOK_FUNCTION(original_FrankAnneStart2, FrankAnneStart2)
void FrankAnneStart2() {
    LOG_TRACE("()");


    original_FrankAnneStart2();
}

static void(*original_GetPlayerName)(int, int, char *, int *, ...) = (void(*)(int, int, char *, int *, ...))0x004b00e4;
CARM95_HOOK_FUNCTION(original_GetPlayerName, GetPlayerName)
void GetPlayerName(int pStarting_to_type, int pCurrent_choice, char *pString, int *pMax_length) {
    LOG_TRACE("(%d, %d, \"%s\", %p)", pStarting_to_type, pCurrent_choice, pString, pMax_length);

    (void)pStarting_to_type;
    (void)pCurrent_choice;
    (void)pString;
    (void)pMax_length;

    original_GetPlayerName(pStarting_to_type, pCurrent_choice, pString, pMax_length);
}

static int(*original_FrankAnneDone)(int, int, int, int, int, ...) = (int(*)(int, int, int, int, int, ...))0x004b012b;
CARM95_HOOK_FUNCTION(original_FrankAnneDone, FrankAnneDone)
int FrankAnneDone(int pCurrent_choice, int pCurrent_mode, int pGo_ahead, int pEscaped, int pTimed_out) {
    LOG_TRACE("(%d, %d, %d, %d, %d)", pCurrent_choice, pCurrent_mode, pGo_ahead, pEscaped, pTimed_out);

    (void)pCurrent_choice;
    (void)pCurrent_mode;
    (void)pGo_ahead;
    (void)pEscaped;
    (void)pTimed_out;

    return original_FrankAnneDone(pCurrent_choice, pCurrent_mode, pGo_ahead, pEscaped, pTimed_out);
}

static void(*original_FrankAnneDraw)(int, int, ...) = (void(*)(int, int, ...))0x004b01fb;
CARM95_HOOK_FUNCTION(original_FrankAnneDraw, FrankAnneDraw)
void FrankAnneDraw(int pCurrent_choice, int pCurrent_mode) {
    LOG_TRACE("(%d, %d)", pCurrent_choice, pCurrent_mode);

    (void)pCurrent_choice;
    (void)pCurrent_mode;

    original_FrankAnneDraw(pCurrent_choice, pCurrent_mode);
}

static int(*original_FrankieOrAnnie)() = (int(*)())0x004b03cd;
CARM95_HOOK_FUNCTION(original_FrankieOrAnnie, FrankieOrAnnie)
int FrankieOrAnnie() {
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

    return original_FrankieOrAnnie();
}

static int(*original_SelectSkillLevel)() = (int(*)())0x004b0436;
CARM95_HOOK_FUNCTION(original_SelectSkillLevel, SelectSkillLevel)
int SelectSkillLevel() {
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

    return original_SelectSkillLevel();
}

static int(*original_DoOnePlayerStart)() = (int(*)())0x004b027b;
CARM95_HOOK_FUNCTION(original_DoOnePlayerStart, DoOnePlayerStart)
int DoOnePlayerStart() {
    int merrily_looping;
    tProgram_state saved_state;
    LOG_TRACE("()");

    (void)merrily_looping;
    (void)saved_state;

    return original_DoOnePlayerStart();
}

static int(*original_NewNetGameUp)(int *, int *, ...) = (int(*)(int *, int *, ...))0x004b0484;
CARM95_HOOK_FUNCTION(original_NewNetGameUp, NewNetGameUp)
int NewNetGameUp(int *pCurrent_choice, int *pCurrent_mode) {
    int new_sel;
    int i;
    LOG_TRACE("(%p, %p)", pCurrent_choice, pCurrent_mode);

    (void)pCurrent_choice;
    (void)pCurrent_mode;
    (void)new_sel;
    (void)i;

    return original_NewNetGameUp(pCurrent_choice, pCurrent_mode);
}

static int(*original_NewNetGameDown)(int *, int *, ...) = (int(*)(int *, int *, ...))0x004b0589;
CARM95_HOOK_FUNCTION(original_NewNetGameDown, NewNetGameDown)
int NewNetGameDown(int *pCurrent_choice, int *pCurrent_mode) {
    int new_sel;
    int i;
    LOG_TRACE("(%p, %p)", pCurrent_choice, pCurrent_mode);

    (void)pCurrent_choice;
    (void)pCurrent_mode;
    (void)new_sel;
    (void)i;

    return original_NewNetGameDown(pCurrent_choice, pCurrent_mode);
}

static void(*original_DisposeJoinableGame)(int, ...) = (void(*)(int, ...))0x004b0def;
CARM95_HOOK_FUNCTION(original_DisposeJoinableGame, DisposeJoinableGame)
void DisposeJoinableGame(int pIndex) {
    LOG_TRACE("(%d)", pIndex);

    (void)pIndex;

    original_DisposeJoinableGame(pIndex);
}

static void(*original_DrawAnItem__newgame)(int, int, int, char *, ...) = (void(*)(int, int, int, char *, ...))0x004b0e1b;
CARM95_HOOK_FUNCTION(original_DrawAnItem__newgame, DrawAnItem__newgame)
void DrawAnItem__newgame(int pX, int pY_index, int pFont_index, char *pText) {
    LOG_TRACE("(%d, %d, %d, \"%s\")", pX, pY_index, pFont_index, pText);

    (void)pX;
    (void)pY_index;
    (void)pFont_index;
    (void)pText;

    original_DrawAnItem__newgame(pX, pY_index, pFont_index, pText);
}

static void(*original_DrawColumnHeading__newgame)(int, int, ...) = (void(*)(int, int, ...))0x004b0e9c;
CARM95_HOOK_FUNCTION(original_DrawColumnHeading__newgame, DrawColumnHeading__newgame)
void DrawColumnHeading__newgame(int pStr_index, int pX) {
    LOG_TRACE("(%d, %d)", pStr_index, pX);

    (void)pStr_index;
    (void)pX;

    original_DrawColumnHeading__newgame(pStr_index, pX);
}

static void(*original_DrawGames)(int, int, ...) = (void(*)(int, int, ...))0x004b068e;
CARM95_HOOK_FUNCTION(original_DrawGames, DrawGames)
void DrawGames(int pCurrent_choice, int pCurrent_mode) {
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

    original_DrawGames(pCurrent_choice, pCurrent_mode);
}

static void(*original_InitGamesToJoin)() = (void(*)())0x004b1253;
CARM95_HOOK_FUNCTION(original_InitGamesToJoin, InitGamesToJoin)
void InitGamesToJoin() {
    int i;
    LOG_TRACE("()");

    (void)i;

    original_InitGamesToJoin();
}

static void(*original_DisposeJoinList)(int, ...) = (void(*)(int, ...))0x004b1297;
CARM95_HOOK_FUNCTION(original_DisposeJoinList, DisposeJoinList)
void DisposeJoinList(int pExemption) {
    int i;
    LOG_TRACE("(%d)", pExemption);

    (void)pExemption;
    (void)i;

    original_DisposeJoinList(pExemption);
}

static void(*original_AddToJoinList)(tNet_game_details *, ...) = (void(*)(tNet_game_details *, ...))0x004b0f0f;
CARM95_HOOK_FUNCTION(original_AddToJoinList, AddToJoinList)
void AddToJoinList(tNet_game_details *pGame) {
    int i;
    int slot_to_use;
    tU32 this_game_ID;
    LOG_TRACE("(%p)", pGame);

    (void)pGame;
    (void)i;
    (void)slot_to_use;
    (void)this_game_ID;

    original_AddToJoinList(pGame);
}

static void(*original_NewNetStart1)() = (void(*)())0x004b0fff;
CARM95_HOOK_FUNCTION(original_NewNetStart1, NewNetStart1)
void NewNetStart1() {
    LOG_TRACE("()");


    original_NewNetStart1();
}

static void(*original_NewNetStart2)() = (void(*)())0x004b105d;
CARM95_HOOK_FUNCTION(original_NewNetStart2, NewNetStart2)
void NewNetStart2() {
    LOG_TRACE("()");


    original_NewNetStart2();
}

static void(*original_NewNetGetName)(int, int, char *, int *, ...) = (void(*)(int, int, char *, int *, ...))0x004b1083;
CARM95_HOOK_FUNCTION(original_NewNetGetName, NewNetGetName)
void NewNetGetName(int pStarting_to_type, int pCurrent_choice, char *pString, int *pMax_length) {
    LOG_TRACE("(%d, %d, \"%s\", %p)", pStarting_to_type, pCurrent_choice, pString, pMax_length);

    (void)pStarting_to_type;
    (void)pCurrent_choice;
    (void)pString;
    (void)pMax_length;

    original_NewNetGetName(pStarting_to_type, pCurrent_choice, pString, pMax_length);
}

static int(*original_NewNetDone)(int, int, int, int, int, ...) = (int(*)(int, int, int, int, int, ...))0x004b10be;
CARM95_HOOK_FUNCTION(original_NewNetDone, NewNetDone)
int NewNetDone(int pCurrent_choice, int pCurrent_mode, int pGo_ahead, int pEscaped, int pTimed_out) {
    LOG_TRACE("(%d, %d, %d, %d, %d)", pCurrent_choice, pCurrent_mode, pGo_ahead, pEscaped, pTimed_out);

    (void)pCurrent_choice;
    (void)pCurrent_mode;
    (void)pGo_ahead;
    (void)pEscaped;
    (void)pTimed_out;

    return original_NewNetDone(pCurrent_choice, pCurrent_mode, pGo_ahead, pEscaped, pTimed_out);
}

static int(*original_NewNetGoAhead)(int *, int *, ...) = (int(*)(int *, int *, ...))0x004b10ea;
CARM95_HOOK_FUNCTION(original_NewNetGoAhead, NewNetGoAhead)
int NewNetGoAhead(int *pCurrent_choice, int *pCurrent_mode) {
    LOG_TRACE("(%p, %p)", pCurrent_choice, pCurrent_mode);

    (void)pCurrent_choice;
    (void)pCurrent_mode;

    return original_NewNetGoAhead(pCurrent_choice, pCurrent_mode);
}

static tJoin_or_host_result(*original_JoinOrHostGame)(tNet_game_details **, ...) = (tJoin_or_host_result(*)(tNet_game_details **, ...))0x004b1113;
CARM95_HOOK_FUNCTION(original_JoinOrHostGame, JoinOrHostGame)
tJoin_or_host_result JoinOrHostGame(tNet_game_details **pGame_to_join) {
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

    return original_JoinOrHostGame(pGame_to_join);
}

static void(*original_GetNetOptions)(tNet_game_options *, ...) = (void(*)(tNet_game_options *, ...))0x004b2d9b;
CARM95_HOOK_FUNCTION(original_GetNetOptions, GetNetOptions)
void GetNetOptions(tNet_game_options *pGame_options) {
    LOG_TRACE("(%p)", pGame_options);

    (void)pGame_options;

    original_GetNetOptions(pGame_options);
}

static void(*original_SetNetOptions)(tNet_game_options *, ...) = (void(*)(tNet_game_options *, ...))0x004b1b29;
CARM95_HOOK_FUNCTION(original_SetNetOptions, SetNetOptions)
void SetNetOptions(tNet_game_options *pGame_options) {
    LOG_TRACE("(%p)", pGame_options);

    (void)pGame_options;

    original_SetNetOptions(pGame_options);
}

static void(*original_NetPlayCheckboxOn2)(int, ...) = (void(*)(int, ...))0x004b13e5;
CARM95_HOOK_FUNCTION(original_NetPlayCheckboxOn2, NetPlayCheckboxOn2)
void NetPlayCheckboxOn2(int pIndex) {
    LOG_TRACE("(%d)", pIndex);

    (void)pIndex;

    original_NetPlayCheckboxOn2(pIndex);
}

static void(*original_NetPlayCheckboxOff2)(int, ...) = (void(*)(int, ...))0x004b1415;
CARM95_HOOK_FUNCTION(original_NetPlayCheckboxOff2, NetPlayCheckboxOff2)
void NetPlayCheckboxOff2(int pIndex) {
    LOG_TRACE("(%d)", pIndex);

    (void)pIndex;

    original_NetPlayCheckboxOff2(pIndex);
}

static void(*original_NetPlayCheckboxOn)(int, ...) = (void(*)(int, ...))0x004b167d;
CARM95_HOOK_FUNCTION(original_NetPlayCheckboxOn, NetPlayCheckboxOn)
void NetPlayCheckboxOn(int pIndex) {
    LOG_TRACE("(%d)", pIndex);

    (void)pIndex;

    original_NetPlayCheckboxOn(pIndex);
}

static void(*original_NetPlayCheckboxOff)(int, ...) = (void(*)(int, ...))0x004b16b2;
CARM95_HOOK_FUNCTION(original_NetPlayCheckboxOff, NetPlayCheckboxOff)
void NetPlayCheckboxOff(int pIndex) {
    LOG_TRACE("(%d)", pIndex);

    (void)pIndex;

    original_NetPlayCheckboxOff(pIndex);
}

static void(*original_NetPlayRadioOn2)(int, int, ...) = (void(*)(int, int, ...))0x004b1445;
CARM95_HOOK_FUNCTION(original_NetPlayRadioOn2, NetPlayRadioOn2)
void NetPlayRadioOn2(int pIndex, int pValue) {
    LOG_TRACE("(%d, %d)", pIndex, pValue);

    (void)pIndex;
    (void)pValue;

    original_NetPlayRadioOn2(pIndex, pValue);
}

static void(*original_NetPlayRadioOff2)(int, int, ...) = (void(*)(int, int, ...))0x004b147c;
CARM95_HOOK_FUNCTION(original_NetPlayRadioOff2, NetPlayRadioOff2)
void NetPlayRadioOff2(int pIndex, int pValue) {
    LOG_TRACE("(%d, %d)", pIndex, pValue);

    (void)pIndex;
    (void)pValue;

    original_NetPlayRadioOff2(pIndex, pValue);
}

static void(*original_NetPlayRadioOn)(int, int, ...) = (void(*)(int, int, ...))0x004b1598;
CARM95_HOOK_FUNCTION(original_NetPlayRadioOn, NetPlayRadioOn)
void NetPlayRadioOn(int pIndex, int pValue) {
    LOG_TRACE("(%d, %d)", pIndex, pValue);

    (void)pIndex;
    (void)pValue;

    original_NetPlayRadioOn(pIndex, pValue);
}

static void(*original_NetPlayRadioOff)(int, int, ...) = (void(*)(int, int, ...))0x004b15d1;
CARM95_HOOK_FUNCTION(original_NetPlayRadioOff, NetPlayRadioOff)
void NetPlayRadioOff(int pIndex, int pValue) {
    LOG_TRACE("(%d, %d)", pIndex, pValue);

    (void)pIndex;
    (void)pValue;

    original_NetPlayRadioOff(pIndex, pValue);
}

static void(*original_DrawNOptInitialRadios)() = (void(*)())0x004b12ec;
CARM95_HOOK_FUNCTION(original_DrawNOptInitialRadios, DrawNOptInitialRadios)
void DrawNOptInitialRadios() {
    int i;
    int j;
    LOG_TRACE("()");

    (void)i;
    (void)j;

    original_DrawNOptInitialRadios();
}

static void(*original_NetRadioChanged)(int, int, ...) = (void(*)(int, int, ...))0x004b1555;
CARM95_HOOK_FUNCTION(original_NetRadioChanged, NetRadioChanged)
void NetRadioChanged(int pIndex, int pNew_value) {
    LOG_TRACE("(%d, %d)", pIndex, pNew_value);

    (void)pIndex;
    (void)pNew_value;

    original_NetRadioChanged(pIndex, pNew_value);
}

static void(*original_NetCheckboxChanged)(int, ...) = (void(*)(int, ...))0x004b160a;
CARM95_HOOK_FUNCTION(original_NetCheckboxChanged, NetCheckboxChanged)
void NetCheckboxChanged(int pIndex) {
    LOG_TRACE("(%d)", pIndex);

    (void)pIndex;

    original_NetCheckboxChanged(pIndex);
}

static int(*original_NetOptLeft)(int *, int *, ...) = (int(*)(int *, int *, ...))0x004b14b3;
CARM95_HOOK_FUNCTION(original_NetOptLeft, NetOptLeft)
int NetOptLeft(int *pCurrent_choice, int *pCurrent_mode) {
    int new_value;
    LOG_TRACE("(%p, %p)", pCurrent_choice, pCurrent_mode);

    (void)pCurrent_choice;
    (void)pCurrent_mode;
    (void)new_value;

    return original_NetOptLeft(pCurrent_choice, pCurrent_mode);
}

static int(*original_NetOptRight)(int *, int *, ...) = (int(*)(int *, int *, ...))0x004b16e7;
CARM95_HOOK_FUNCTION(original_NetOptRight, NetOptRight)
int NetOptRight(int *pCurrent_choice, int *pCurrent_mode) {
    int new_value;
    LOG_TRACE("(%p, %p)", pCurrent_choice, pCurrent_mode);

    (void)pCurrent_choice;
    (void)pCurrent_mode;
    (void)new_value;

    return original_NetOptRight(pCurrent_choice, pCurrent_mode);
}

static int(*original_NetOptUp)(int *, int *, ...) = (int(*)(int *, int *, ...))0x004b178b;
CARM95_HOOK_FUNCTION(original_NetOptUp, NetOptUp)
int NetOptUp(int *pCurrent_choice, int *pCurrent_mode) {
    LOG_TRACE("(%p, %p)", pCurrent_choice, pCurrent_mode);

    (void)pCurrent_choice;
    (void)pCurrent_mode;

    return original_NetOptUp(pCurrent_choice, pCurrent_mode);
}

static int(*original_NetOptDown)(int *, int *, ...) = (int(*)(int *, int *, ...))0x004b181d;
CARM95_HOOK_FUNCTION(original_NetOptDown, NetOptDown)
int NetOptDown(int *pCurrent_choice, int *pCurrent_mode) {
    LOG_TRACE("(%p, %p)", pCurrent_choice, pCurrent_mode);

    (void)pCurrent_choice;
    (void)pCurrent_mode;

    return original_NetOptDown(pCurrent_choice, pCurrent_mode);
}

static int(*original_NetRadioClick)(int *, int *, int, int, ...) = (int(*)(int *, int *, int, int, ...))0x004b18af;
CARM95_HOOK_FUNCTION(original_NetRadioClick, NetRadioClick)
int NetRadioClick(int *pCurrent_choice, int *pCurrent_mode, int pX_offset, int pY_offset) {
    int i;
    LOG_TRACE("(%p, %p, %d, %d)", pCurrent_choice, pCurrent_mode, pX_offset, pY_offset);

    (void)pCurrent_choice;
    (void)pCurrent_mode;
    (void)pX_offset;
    (void)pY_offset;
    (void)i;

    return original_NetRadioClick(pCurrent_choice, pCurrent_mode, pX_offset, pY_offset);
}

static void(*original_RevertToDefaults)() = (void(*)())0x004b1a8e;
CARM95_HOOK_FUNCTION(original_RevertToDefaults, RevertToDefaults)
void RevertToDefaults() {
    tPath_name the_path;
    FILE *f;
    tNet_game_options net_options;
    int i;
    LOG_TRACE("()");

    (void)the_path;
    (void)f;
    (void)net_options;
    (void)i;

    original_RevertToDefaults();
}

static void(*original_DefaultNetSettings)() = (void(*)())0x004b1984;
CARM95_HOOK_FUNCTION(original_DefaultNetSettings, DefaultNetSettings)
void DefaultNetSettings() {
    tPath_name the_path;
    FILE *f;
    int i;
    LOG_TRACE("()");

    (void)the_path;
    (void)f;
    (void)i;

    original_DefaultNetSettings();
}

static int(*original_NetOptGoAhead)(int *, int *, ...) = (int(*)(int *, int *, ...))0x004b1a34;
CARM95_HOOK_FUNCTION(original_NetOptGoAhead, NetOptGoAhead)
int NetOptGoAhead(int *pCurrent_choice, int *pCurrent_mode) {
    LOG_TRACE("(%p, %p)", pCurrent_choice, pCurrent_mode);

    (void)pCurrent_choice;
    (void)pCurrent_mode;

    return original_NetOptGoAhead(pCurrent_choice, pCurrent_mode);
}

static void(*original_NetPlotAGraphBox)(int, int, ...) = (void(*)(int, int, ...))0x004b1c58;
CARM95_HOOK_FUNCTION(original_NetPlotAGraphBox, NetPlotAGraphBox)
void NetPlotAGraphBox(int pIndex, int pColour_value) {
    LOG_TRACE("(%d, %d)", pIndex, pColour_value);

    (void)pIndex;
    (void)pColour_value;

    original_NetPlotAGraphBox(pIndex, pColour_value);
}

static void(*original_NetDrawAGraphBox)(int, ...) = (void(*)(int, ...))0x004b1c3f;
CARM95_HOOK_FUNCTION(original_NetDrawAGraphBox, NetDrawAGraphBox)
void NetDrawAGraphBox(int pIndex) {
    LOG_TRACE("(%d)", pIndex);

    (void)pIndex;

    original_NetDrawAGraphBox(pIndex);
}

static void(*original_NetEraseAGraphBox)(int, ...) = (void(*)(int, ...))0x004b1d0a;
CARM95_HOOK_FUNCTION(original_NetEraseAGraphBox, NetEraseAGraphBox)
void NetEraseAGraphBox(int pIndex) {
    LOG_TRACE("(%d)", pIndex);

    (void)pIndex;

    original_NetEraseAGraphBox(pIndex);
}

static void(*original_DrawNetOptBox)(int, int, ...) = (void(*)(int, int, ...))0x004b1bfd;
CARM95_HOOK_FUNCTION(original_DrawNetOptBox, DrawNetOptBox)
void DrawNetOptBox(int pCurrent_choice, int pCurrent_mode) {
    LOG_TRACE("(%d, %d)", pCurrent_choice, pCurrent_mode);

    (void)pCurrent_choice;
    (void)pCurrent_mode;

    original_DrawNetOptBox(pCurrent_choice, pCurrent_mode);
}

static void(*original_DoNetOptions)(tNet_game_options *, ...) = (void(*)(tNet_game_options *, ...))0x004b2d37;
CARM95_HOOK_FUNCTION(original_DoNetOptions, DoNetOptions)
void DoNetOptions(tNet_game_options *pGame_options) {
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

    original_DoNetOptions(pGame_options);
}

static void(*original_SetOptions)(tNet_game_type, tNet_game_options *, ...) = (void(*)(tNet_game_type, tNet_game_options *, ...))0x004b1e95;
CARM95_HOOK_FUNCTION(original_SetOptions, SetOptions)
void SetOptions(tNet_game_type pGame_type, tNet_game_options *pGame_options) {
    LOG_TRACE("(%d, %p)", pGame_type, pGame_options);

    (void)pGame_type;
    (void)pGame_options;

    original_SetOptions(pGame_type, pGame_options);
}

static void(*original_PlayRadioOn__newgame)(int, ...) = (void(*)(int, ...))0x004b1d3c;
CARM95_HOOK_FUNCTION(original_PlayRadioOn__newgame, PlayRadioOn__newgame)
void PlayRadioOn__newgame(int pIndex) {
    LOG_TRACE("(%d)", pIndex);

    (void)pIndex;

    original_PlayRadioOn__newgame(pIndex);
}

static void(*original_PlayRadioOff__newgame)(int, ...) = (void(*)(int, ...))0x004b1f33;
CARM95_HOOK_FUNCTION(original_PlayRadioOff__newgame, PlayRadioOff__newgame)
void PlayRadioOff__newgame(int pIndex) {
    LOG_TRACE("(%d)", pIndex);

    (void)pIndex;

    original_PlayRadioOff__newgame(pIndex);
}

static void(*original_DrawNetChooseInitial)() = (void(*)())0x004b1d23;
CARM95_HOOK_FUNCTION(original_DrawNetChooseInitial, DrawNetChooseInitial)
void DrawNetChooseInitial() {
    LOG_TRACE("()");


    original_DrawNetChooseInitial();
}

static int(*original_NetChooseGoAhead)(int *, int *, ...) = (int(*)(int *, int *, ...))0x004b1d9c;
CARM95_HOOK_FUNCTION(original_NetChooseGoAhead, NetChooseGoAhead)
int NetChooseGoAhead(int *pCurrent_choice, int *pCurrent_mode) {
    LOG_TRACE("(%p, %p)", pCurrent_choice, pCurrent_mode);

    (void)pCurrent_choice;
    (void)pCurrent_mode;

    return original_NetChooseGoAhead(pCurrent_choice, pCurrent_mode);
}

static void(*original_PlotAGraphBox__newgame)(int, int, ...) = (void(*)(int, int, ...))0x004b2277;
CARM95_HOOK_FUNCTION(original_PlotAGraphBox__newgame, PlotAGraphBox__newgame)
void PlotAGraphBox__newgame(int pIndex, int pColour_value) {
    LOG_TRACE("(%d, %d)", pIndex, pColour_value);

    (void)pIndex;
    (void)pColour_value;

    original_PlotAGraphBox__newgame(pIndex, pColour_value);
}

static void(*original_DrawAGraphBox__newgame)(int, ...) = (void(*)(int, ...))0x004b225e;
CARM95_HOOK_FUNCTION(original_DrawAGraphBox__newgame, DrawAGraphBox__newgame)
void DrawAGraphBox__newgame(int pIndex) {
    LOG_TRACE("(%d)", pIndex);

    (void)pIndex;

    original_DrawAGraphBox__newgame(pIndex);
}

static void(*original_EraseAGraphBox__newgame)(int, ...) = (void(*)(int, ...))0x004b2325;
CARM95_HOOK_FUNCTION(original_EraseAGraphBox__newgame, EraseAGraphBox__newgame)
void EraseAGraphBox__newgame(int pIndex) {
    LOG_TRACE("(%d)", pIndex);

    (void)pIndex;

    original_EraseAGraphBox__newgame(pIndex);
}

static void(*original_DrawNetChoose)(int, int, ...) = (void(*)(int, int, ...))0x004b1f93;
CARM95_HOOK_FUNCTION(original_DrawNetChoose, DrawNetChoose)
void DrawNetChoose(int pCurrent_choice, int pCurrent_mode) {
    char s[256];
    tU32 *k;
    int i;
    LOG_TRACE("(%d, %d)", pCurrent_choice, pCurrent_mode);

    (void)pCurrent_choice;
    (void)pCurrent_mode;
    (void)s;
    (void)k;
    (void)i;

    original_DrawNetChoose(pCurrent_choice, pCurrent_mode);
}

static int(*original_NetChooseLR)(int *, int *, ...) = (int(*)(int *, int *, ...))0x004b233e;
CARM95_HOOK_FUNCTION(original_NetChooseLR, NetChooseLR)
int NetChooseLR(int *pCurrent_choice, int *pCurrent_mode) {
    LOG_TRACE("(%p, %p)", pCurrent_choice, pCurrent_mode);

    (void)pCurrent_choice;
    (void)pCurrent_mode;

    return original_NetChooseLR(pCurrent_choice, pCurrent_mode);
}

static void(*original_SetGameTarget)(tNet_game_type *, tNet_game_options *, ...) = (void(*)(tNet_game_type *, tNet_game_options *, ...))0x004b2e6f;
CARM95_HOOK_FUNCTION(original_SetGameTarget, SetGameTarget)
void SetGameTarget(tNet_game_type *pGame_type, tNet_game_options *pGame_options) {
    LOG_TRACE("(%p, %p)", pGame_type, pGame_options);

    (void)pGame_type;
    (void)pGame_options;

    original_SetGameTarget(pGame_type, pGame_options);
}

static int(*original_NetGameChoices)(tNet_game_type *, tNet_game_options *, int *, ...) = (int(*)(tNet_game_type *, tNet_game_options *, int *, ...))0x004b2ba3;
CARM95_HOOK_FUNCTION(original_NetGameChoices, NetGameChoices)
int NetGameChoices(tNet_game_type *pGame_type, tNet_game_options *pGame_options, int *pRace_index) {
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

    return original_NetGameChoices(pGame_type, pGame_options, pRace_index);
}

static void(*original_ReadNetGameChoices)(tNet_game_type *, tNet_game_options *, int *, ...) = (void(*)(tNet_game_type *, tNet_game_options *, int *, ...))0x004b2f38;
CARM95_HOOK_FUNCTION(original_ReadNetGameChoices, ReadNetGameChoices)
void ReadNetGameChoices(tNet_game_type *pGame_type, tNet_game_options *pGame_options, int *pRace_index) {
    LOG_TRACE("(%p, %p, %p)", pGame_type, pGame_options, pRace_index);

    (void)pGame_type;
    (void)pGame_options;
    (void)pRace_index;

    original_ReadNetGameChoices(pGame_type, pGame_options, pRace_index);
}

static int(*original_ChooseStartRace)(int *, ...) = (int(*)(int *, ...))0x004b235d;
CARM95_HOOK_FUNCTION(original_ChooseStartRace, ChooseStartRace)
int ChooseStartRace(int *pRank) {
    LOG_TRACE("(%p)", pRank);

    (void)pRank;

    return original_ChooseStartRace(pRank);
}

static void(*original_SetUpOtherNetThings)(tNet_game_details *, ...) = (void(*)(tNet_game_details *, ...))0x004b237b;
CARM95_HOOK_FUNCTION(original_SetUpOtherNetThings, SetUpOtherNetThings)
void SetUpOtherNetThings(tNet_game_details *pNet_game) {
    LOG_TRACE("(%p)", pNet_game);

    (void)pNet_game;

    original_SetUpOtherNetThings(pNet_game);
}

static void(*original_RequestCarDetails)(tNet_game_details *, ...) = (void(*)(tNet_game_details *, ...))0x004b246e;
CARM95_HOOK_FUNCTION(original_RequestCarDetails, RequestCarDetails)
void RequestCarDetails(tNet_game_details *pNet_game) {
    tNet_message *message;
    LOG_TRACE("(%p)", pNet_game);

    (void)pNet_game;
    (void)message;

    original_RequestCarDetails(pNet_game);
}

static int(*original_PickARandomCar)() = (int(*)())0x004b23a4;
CARM95_HOOK_FUNCTION(original_PickARandomCar, PickARandomCar)
int PickARandomCar() {
    int i;
    int cars[120];
    int array_size;
    LOG_TRACE("()");

    (void)i;
    (void)cars;
    (void)array_size;

    return original_PickARandomCar();
}

static void(*original_PollCarDetails)(tNet_game_details *, ...) = (void(*)(tNet_game_details *, ...))0x004b244a;
CARM95_HOOK_FUNCTION(original_PollCarDetails, PollCarDetails)
void PollCarDetails(tNet_game_details *pNet_game) {
    LOG_TRACE("(%p)", pNet_game);

    (void)pNet_game;

    original_PollCarDetails(pNet_game);
}

static void(*original_SetNetAvailability)(tNet_game_options *, ...) = (void(*)(tNet_game_options *, ...))0x004b24c2;
CARM95_HOOK_FUNCTION(original_SetNetAvailability, SetNetAvailability)
void SetNetAvailability(tNet_game_options *pOptions) {
    int i;
    LOG_TRACE("(%p)", pOptions);

    (void)pOptions;
    (void)i;

    original_SetNetAvailability(pOptions);
}

static int(*original_ChooseNetCar)(tNet_game_details *, tNet_game_options *, int *, int, ...) = (int(*)(tNet_game_details *, tNet_game_options *, int *, int, ...))0x004b25fa;
CARM95_HOOK_FUNCTION(original_ChooseNetCar, ChooseNetCar)
int ChooseNetCar(tNet_game_details *pNet_game, tNet_game_options *pOptions, int *pCar_index, int pIm_the_host_so_fuck_off) {
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

    return original_ChooseNetCar(pNet_game, pOptions, pCar_index, pIm_the_host_so_fuck_off);
}

static void(*original_InitNetStorageSpace)() = (void(*)())0x004b2f85;
CARM95_HOOK_FUNCTION(original_InitNetStorageSpace, InitNetStorageSpace)
void InitNetStorageSpace() {
    int i;
    LOG_TRACE("()");

    (void)i;

    original_InitNetStorageSpace();
}

static void(*original_DisposeNetStorageSpace)() = (void(*)())0x004b2fe9;
CARM95_HOOK_FUNCTION(original_DisposeNetStorageSpace, DisposeNetStorageSpace)
void DisposeNetStorageSpace() {
    LOG_TRACE("()");


    original_DisposeNetStorageSpace();
}

static int(*original_DoMultiPlayerStart)() = (int(*)())0x004b27a7;
CARM95_HOOK_FUNCTION(original_DoMultiPlayerStart, DoMultiPlayerStart)
int DoMultiPlayerStart() {
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

    return original_DoMultiPlayerStart();
}

