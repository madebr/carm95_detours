#include "newgame.h"

#include "harness/trace.h"

#include "carm95_hooks.h"

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

static void(__cdecl*original_StartRollingPlayerNamesIn)() = (void(__cdecl*)())0x004affc4;
CARM95_HOOK_FUNCTION(original_StartRollingPlayerNamesIn, StartRollingPlayerNamesIn)
void __cdecl StartRollingPlayerNamesIn() {
    int i;
    LOG_TRACE("()");

    (void)i;

    original_StartRollingPlayerNamesIn();
}

static void(__cdecl*original_FrankAnneStart1)() = (void(__cdecl*)())0x004afe80;
CARM95_HOOK_FUNCTION(original_FrankAnneStart1, FrankAnneStart1)
void __cdecl FrankAnneStart1() {
    LOG_TRACE("()");


    original_FrankAnneStart1();
}

static void(__cdecl*original_FrankAnneStart2)() = (void(__cdecl*)())0x004b0057;
CARM95_HOOK_FUNCTION(original_FrankAnneStart2, FrankAnneStart2)
void __cdecl FrankAnneStart2() {
    LOG_TRACE("()");


    original_FrankAnneStart2();
}

static void(__cdecl*original_GetPlayerName)(int, int, char *, int *) = (void(__cdecl*)(int, int, char *, int *))0x004b00e4;
CARM95_HOOK_FUNCTION(original_GetPlayerName, GetPlayerName)
void __cdecl GetPlayerName(int pStarting_to_type, int pCurrent_choice, char *pString, int *pMax_length) {
    LOG_TRACE("(%d, %d, \"%s\", %p)", pStarting_to_type, pCurrent_choice, pString, pMax_length);

    (void)pStarting_to_type;
    (void)pCurrent_choice;
    (void)pString;
    (void)pMax_length;

    original_GetPlayerName(pStarting_to_type, pCurrent_choice, pString, pMax_length);
}

static int(__cdecl*original_FrankAnneDone)(int, int, int, int, int) = (int(__cdecl*)(int, int, int, int, int))0x004b012b;
CARM95_HOOK_FUNCTION(original_FrankAnneDone, FrankAnneDone)
int __cdecl FrankAnneDone(int pCurrent_choice, int pCurrent_mode, int pGo_ahead, int pEscaped, int pTimed_out) {
    LOG_TRACE("(%d, %d, %d, %d, %d)", pCurrent_choice, pCurrent_mode, pGo_ahead, pEscaped, pTimed_out);

    (void)pCurrent_choice;
    (void)pCurrent_mode;
    (void)pGo_ahead;
    (void)pEscaped;
    (void)pTimed_out;

    return original_FrankAnneDone(pCurrent_choice, pCurrent_mode, pGo_ahead, pEscaped, pTimed_out);
}

static void(__cdecl*original_FrankAnneDraw)(int, int) = (void(__cdecl*)(int, int))0x004b01fb;
CARM95_HOOK_FUNCTION(original_FrankAnneDraw, FrankAnneDraw)
void __cdecl FrankAnneDraw(int pCurrent_choice, int pCurrent_mode) {
    LOG_TRACE("(%d, %d)", pCurrent_choice, pCurrent_mode);

    (void)pCurrent_choice;
    (void)pCurrent_mode;

    original_FrankAnneDraw(pCurrent_choice, pCurrent_mode);
}

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

    return original_FrankieOrAnnie();
}

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

    return original_SelectSkillLevel();
}

static int(__cdecl*original_DoOnePlayerStart)() = (int(__cdecl*)())0x004b027b;
CARM95_HOOK_FUNCTION(original_DoOnePlayerStart, DoOnePlayerStart)
int __cdecl DoOnePlayerStart() {
    int merrily_looping;
    tProgram_state saved_state;
    LOG_TRACE("()");

    (void)merrily_looping;
    (void)saved_state;

    return original_DoOnePlayerStart();
}

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

    return original_NewNetGameUp(pCurrent_choice, pCurrent_mode);
}

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

    return original_NewNetGameDown(pCurrent_choice, pCurrent_mode);
}

static void(__cdecl*original_DisposeJoinableGame)(int) = (void(__cdecl*)(int))0x004b0def;
CARM95_HOOK_FUNCTION(original_DisposeJoinableGame, DisposeJoinableGame)
void __cdecl DisposeJoinableGame(int pIndex) {
    LOG_TRACE("(%d)", pIndex);

    (void)pIndex;

    original_DisposeJoinableGame(pIndex);
}

static void(__cdecl*original_DrawAnItem__newgame)(int, int, int, char *) = (void(__cdecl*)(int, int, int, char *))0x004b0e1b;
CARM95_HOOK_FUNCTION(original_DrawAnItem__newgame, DrawAnItem__newgame)
void __cdecl DrawAnItem__newgame(int pX, int pY_index, int pFont_index, char *pText) {
    LOG_TRACE("(%d, %d, %d, \"%s\")", pX, pY_index, pFont_index, pText);

    (void)pX;
    (void)pY_index;
    (void)pFont_index;
    (void)pText;

    original_DrawAnItem__newgame(pX, pY_index, pFont_index, pText);
}

static void(__cdecl*original_DrawColumnHeading__newgame)(int, int) = (void(__cdecl*)(int, int))0x004b0e9c;
CARM95_HOOK_FUNCTION(original_DrawColumnHeading__newgame, DrawColumnHeading__newgame)
void __cdecl DrawColumnHeading__newgame(int pStr_index, int pX) {
    LOG_TRACE("(%d, %d)", pStr_index, pX);

    (void)pStr_index;
    (void)pX;

    original_DrawColumnHeading__newgame(pStr_index, pX);
}

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

    original_DrawGames(pCurrent_choice, pCurrent_mode);
}

static void(__cdecl*original_InitGamesToJoin)() = (void(__cdecl*)())0x004b1253;
CARM95_HOOK_FUNCTION(original_InitGamesToJoin, InitGamesToJoin)
void __cdecl InitGamesToJoin() {
    int i;
    LOG_TRACE("()");

    (void)i;

    original_InitGamesToJoin();
}

static void(__cdecl*original_DisposeJoinList)(int) = (void(__cdecl*)(int))0x004b1297;
CARM95_HOOK_FUNCTION(original_DisposeJoinList, DisposeJoinList)
void __cdecl DisposeJoinList(int pExemption) {
    int i;
    LOG_TRACE("(%d)", pExemption);

    (void)pExemption;
    (void)i;

    original_DisposeJoinList(pExemption);
}

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

    original_AddToJoinList(pGame);
}

static void(__cdecl*original_NewNetStart1)() = (void(__cdecl*)())0x004b0fff;
CARM95_HOOK_FUNCTION(original_NewNetStart1, NewNetStart1)
void __cdecl NewNetStart1() {
    LOG_TRACE("()");


    original_NewNetStart1();
}

static void(__cdecl*original_NewNetStart2)() = (void(__cdecl*)())0x004b105d;
CARM95_HOOK_FUNCTION(original_NewNetStart2, NewNetStart2)
void __cdecl NewNetStart2() {
    LOG_TRACE("()");


    original_NewNetStart2();
}

static void(__cdecl*original_NewNetGetName)(int, int, char *, int *) = (void(__cdecl*)(int, int, char *, int *))0x004b1083;
CARM95_HOOK_FUNCTION(original_NewNetGetName, NewNetGetName)
void __cdecl NewNetGetName(int pStarting_to_type, int pCurrent_choice, char *pString, int *pMax_length) {
    LOG_TRACE("(%d, %d, \"%s\", %p)", pStarting_to_type, pCurrent_choice, pString, pMax_length);

    (void)pStarting_to_type;
    (void)pCurrent_choice;
    (void)pString;
    (void)pMax_length;

    original_NewNetGetName(pStarting_to_type, pCurrent_choice, pString, pMax_length);
}

static int(__cdecl*original_NewNetDone)(int, int, int, int, int) = (int(__cdecl*)(int, int, int, int, int))0x004b10be;
CARM95_HOOK_FUNCTION(original_NewNetDone, NewNetDone)
int __cdecl NewNetDone(int pCurrent_choice, int pCurrent_mode, int pGo_ahead, int pEscaped, int pTimed_out) {
    LOG_TRACE("(%d, %d, %d, %d, %d)", pCurrent_choice, pCurrent_mode, pGo_ahead, pEscaped, pTimed_out);

    (void)pCurrent_choice;
    (void)pCurrent_mode;
    (void)pGo_ahead;
    (void)pEscaped;
    (void)pTimed_out;

    return original_NewNetDone(pCurrent_choice, pCurrent_mode, pGo_ahead, pEscaped, pTimed_out);
}

static int(__cdecl*original_NewNetGoAhead)(int *, int *) = (int(__cdecl*)(int *, int *))0x004b10ea;
CARM95_HOOK_FUNCTION(original_NewNetGoAhead, NewNetGoAhead)
int __cdecl NewNetGoAhead(int *pCurrent_choice, int *pCurrent_mode) {
    LOG_TRACE("(%p, %p)", pCurrent_choice, pCurrent_mode);

    (void)pCurrent_choice;
    (void)pCurrent_mode;

    return original_NewNetGoAhead(pCurrent_choice, pCurrent_mode);
}

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

    return original_JoinOrHostGame(pGame_to_join);
}

static void(__cdecl*original_GetNetOptions)(tNet_game_options *) = (void(__cdecl*)(tNet_game_options *))0x004b2d9b;
CARM95_HOOK_FUNCTION(original_GetNetOptions, GetNetOptions)
void __cdecl GetNetOptions(tNet_game_options *pGame_options) {
    LOG_TRACE("(%p)", pGame_options);

    (void)pGame_options;

    original_GetNetOptions(pGame_options);
}

static void(__cdecl*original_SetNetOptions)(tNet_game_options *) = (void(__cdecl*)(tNet_game_options *))0x004b1b29;
CARM95_HOOK_FUNCTION(original_SetNetOptions, SetNetOptions)
void __cdecl SetNetOptions(tNet_game_options *pGame_options) {
    LOG_TRACE("(%p)", pGame_options);

    (void)pGame_options;

    original_SetNetOptions(pGame_options);
}

static void(__cdecl*original_NetPlayCheckboxOn2)(int) = (void(__cdecl*)(int))0x004b13e5;
CARM95_HOOK_FUNCTION(original_NetPlayCheckboxOn2, NetPlayCheckboxOn2)
void __cdecl NetPlayCheckboxOn2(int pIndex) {
    LOG_TRACE("(%d)", pIndex);

    (void)pIndex;

    original_NetPlayCheckboxOn2(pIndex);
}

static void(__cdecl*original_NetPlayCheckboxOff2)(int) = (void(__cdecl*)(int))0x004b1415;
CARM95_HOOK_FUNCTION(original_NetPlayCheckboxOff2, NetPlayCheckboxOff2)
void __cdecl NetPlayCheckboxOff2(int pIndex) {
    LOG_TRACE("(%d)", pIndex);

    (void)pIndex;

    original_NetPlayCheckboxOff2(pIndex);
}

static void(__cdecl*original_NetPlayCheckboxOn)(int) = (void(__cdecl*)(int))0x004b167d;
CARM95_HOOK_FUNCTION(original_NetPlayCheckboxOn, NetPlayCheckboxOn)
void __cdecl NetPlayCheckboxOn(int pIndex) {
    LOG_TRACE("(%d)", pIndex);

    (void)pIndex;

    original_NetPlayCheckboxOn(pIndex);
}

static void(__cdecl*original_NetPlayCheckboxOff)(int) = (void(__cdecl*)(int))0x004b16b2;
CARM95_HOOK_FUNCTION(original_NetPlayCheckboxOff, NetPlayCheckboxOff)
void __cdecl NetPlayCheckboxOff(int pIndex) {
    LOG_TRACE("(%d)", pIndex);

    (void)pIndex;

    original_NetPlayCheckboxOff(pIndex);
}

static void(__cdecl*original_NetPlayRadioOn2)(int, int) = (void(__cdecl*)(int, int))0x004b1445;
CARM95_HOOK_FUNCTION(original_NetPlayRadioOn2, NetPlayRadioOn2)
void __cdecl NetPlayRadioOn2(int pIndex, int pValue) {
    LOG_TRACE("(%d, %d)", pIndex, pValue);

    (void)pIndex;
    (void)pValue;

    original_NetPlayRadioOn2(pIndex, pValue);
}

static void(__cdecl*original_NetPlayRadioOff2)(int, int) = (void(__cdecl*)(int, int))0x004b147c;
CARM95_HOOK_FUNCTION(original_NetPlayRadioOff2, NetPlayRadioOff2)
void __cdecl NetPlayRadioOff2(int pIndex, int pValue) {
    LOG_TRACE("(%d, %d)", pIndex, pValue);

    (void)pIndex;
    (void)pValue;

    original_NetPlayRadioOff2(pIndex, pValue);
}

static void(__cdecl*original_NetPlayRadioOn)(int, int) = (void(__cdecl*)(int, int))0x004b1598;
CARM95_HOOK_FUNCTION(original_NetPlayRadioOn, NetPlayRadioOn)
void __cdecl NetPlayRadioOn(int pIndex, int pValue) {
    LOG_TRACE("(%d, %d)", pIndex, pValue);

    (void)pIndex;
    (void)pValue;

    original_NetPlayRadioOn(pIndex, pValue);
}

static void(__cdecl*original_NetPlayRadioOff)(int, int) = (void(__cdecl*)(int, int))0x004b15d1;
CARM95_HOOK_FUNCTION(original_NetPlayRadioOff, NetPlayRadioOff)
void __cdecl NetPlayRadioOff(int pIndex, int pValue) {
    LOG_TRACE("(%d, %d)", pIndex, pValue);

    (void)pIndex;
    (void)pValue;

    original_NetPlayRadioOff(pIndex, pValue);
}

static void(__cdecl*original_DrawNOptInitialRadios)() = (void(__cdecl*)())0x004b12ec;
CARM95_HOOK_FUNCTION(original_DrawNOptInitialRadios, DrawNOptInitialRadios)
void __cdecl DrawNOptInitialRadios() {
    int i;
    int j;
    LOG_TRACE("()");

    (void)i;
    (void)j;

    original_DrawNOptInitialRadios();
}

static void(__cdecl*original_NetRadioChanged)(int, int) = (void(__cdecl*)(int, int))0x004b1555;
CARM95_HOOK_FUNCTION(original_NetRadioChanged, NetRadioChanged)
void __cdecl NetRadioChanged(int pIndex, int pNew_value) {
    LOG_TRACE("(%d, %d)", pIndex, pNew_value);

    (void)pIndex;
    (void)pNew_value;

    original_NetRadioChanged(pIndex, pNew_value);
}

static void(__cdecl*original_NetCheckboxChanged)(int) = (void(__cdecl*)(int))0x004b160a;
CARM95_HOOK_FUNCTION(original_NetCheckboxChanged, NetCheckboxChanged)
void __cdecl NetCheckboxChanged(int pIndex) {
    LOG_TRACE("(%d)", pIndex);

    (void)pIndex;

    original_NetCheckboxChanged(pIndex);
}

static int(__cdecl*original_NetOptLeft)(int *, int *) = (int(__cdecl*)(int *, int *))0x004b14b3;
CARM95_HOOK_FUNCTION(original_NetOptLeft, NetOptLeft)
int __cdecl NetOptLeft(int *pCurrent_choice, int *pCurrent_mode) {
    int new_value;
    LOG_TRACE("(%p, %p)", pCurrent_choice, pCurrent_mode);

    (void)pCurrent_choice;
    (void)pCurrent_mode;
    (void)new_value;

    return original_NetOptLeft(pCurrent_choice, pCurrent_mode);
}

static int(__cdecl*original_NetOptRight)(int *, int *) = (int(__cdecl*)(int *, int *))0x004b16e7;
CARM95_HOOK_FUNCTION(original_NetOptRight, NetOptRight)
int __cdecl NetOptRight(int *pCurrent_choice, int *pCurrent_mode) {
    int new_value;
    LOG_TRACE("(%p, %p)", pCurrent_choice, pCurrent_mode);

    (void)pCurrent_choice;
    (void)pCurrent_mode;
    (void)new_value;

    return original_NetOptRight(pCurrent_choice, pCurrent_mode);
}

static int(__cdecl*original_NetOptUp)(int *, int *) = (int(__cdecl*)(int *, int *))0x004b178b;
CARM95_HOOK_FUNCTION(original_NetOptUp, NetOptUp)
int __cdecl NetOptUp(int *pCurrent_choice, int *pCurrent_mode) {
    LOG_TRACE("(%p, %p)", pCurrent_choice, pCurrent_mode);

    (void)pCurrent_choice;
    (void)pCurrent_mode;

    return original_NetOptUp(pCurrent_choice, pCurrent_mode);
}

static int(__cdecl*original_NetOptDown)(int *, int *) = (int(__cdecl*)(int *, int *))0x004b181d;
CARM95_HOOK_FUNCTION(original_NetOptDown, NetOptDown)
int __cdecl NetOptDown(int *pCurrent_choice, int *pCurrent_mode) {
    LOG_TRACE("(%p, %p)", pCurrent_choice, pCurrent_mode);

    (void)pCurrent_choice;
    (void)pCurrent_mode;

    return original_NetOptDown(pCurrent_choice, pCurrent_mode);
}

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

    return original_NetRadioClick(pCurrent_choice, pCurrent_mode, pX_offset, pY_offset);
}

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

    original_RevertToDefaults();
}

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

    original_DefaultNetSettings();
}

static int(__cdecl*original_NetOptGoAhead)(int *, int *) = (int(__cdecl*)(int *, int *))0x004b1a34;
CARM95_HOOK_FUNCTION(original_NetOptGoAhead, NetOptGoAhead)
int __cdecl NetOptGoAhead(int *pCurrent_choice, int *pCurrent_mode) {
    LOG_TRACE("(%p, %p)", pCurrent_choice, pCurrent_mode);

    (void)pCurrent_choice;
    (void)pCurrent_mode;

    return original_NetOptGoAhead(pCurrent_choice, pCurrent_mode);
}

static void(__cdecl*original_NetPlotAGraphBox)(int, int) = (void(__cdecl*)(int, int))0x004b1c58;
CARM95_HOOK_FUNCTION(original_NetPlotAGraphBox, NetPlotAGraphBox)
void __cdecl NetPlotAGraphBox(int pIndex, int pColour_value) {
    LOG_TRACE("(%d, %d)", pIndex, pColour_value);

    (void)pIndex;
    (void)pColour_value;

    original_NetPlotAGraphBox(pIndex, pColour_value);
}

static void(__cdecl*original_NetDrawAGraphBox)(int) = (void(__cdecl*)(int))0x004b1c3f;
CARM95_HOOK_FUNCTION(original_NetDrawAGraphBox, NetDrawAGraphBox)
void __cdecl NetDrawAGraphBox(int pIndex) {
    LOG_TRACE("(%d)", pIndex);

    (void)pIndex;

    original_NetDrawAGraphBox(pIndex);
}

static void(__cdecl*original_NetEraseAGraphBox)(int) = (void(__cdecl*)(int))0x004b1d0a;
CARM95_HOOK_FUNCTION(original_NetEraseAGraphBox, NetEraseAGraphBox)
void __cdecl NetEraseAGraphBox(int pIndex) {
    LOG_TRACE("(%d)", pIndex);

    (void)pIndex;

    original_NetEraseAGraphBox(pIndex);
}

static void(__cdecl*original_DrawNetOptBox)(int, int) = (void(__cdecl*)(int, int))0x004b1bfd;
CARM95_HOOK_FUNCTION(original_DrawNetOptBox, DrawNetOptBox)
void __cdecl DrawNetOptBox(int pCurrent_choice, int pCurrent_mode) {
    LOG_TRACE("(%d, %d)", pCurrent_choice, pCurrent_mode);

    (void)pCurrent_choice;
    (void)pCurrent_mode;

    original_DrawNetOptBox(pCurrent_choice, pCurrent_mode);
}

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

    original_DoNetOptions(pGame_options);
}

static void(__cdecl*original_SetOptions)(tNet_game_type, tNet_game_options *) = (void(__cdecl*)(tNet_game_type, tNet_game_options *))0x004b1e95;
CARM95_HOOK_FUNCTION(original_SetOptions, SetOptions)
void __cdecl SetOptions(tNet_game_type pGame_type, tNet_game_options *pGame_options) {
    LOG_TRACE("(%d, %p)", pGame_type, pGame_options);

    (void)pGame_type;
    (void)pGame_options;

    original_SetOptions(pGame_type, pGame_options);
}

static void(__cdecl*original_PlayRadioOn__newgame)(int) = (void(__cdecl*)(int))0x004b1d3c;
CARM95_HOOK_FUNCTION(original_PlayRadioOn__newgame, PlayRadioOn__newgame)
void __cdecl PlayRadioOn__newgame(int pIndex) {
    LOG_TRACE("(%d)", pIndex);

    (void)pIndex;

    original_PlayRadioOn__newgame(pIndex);
}

static void(__cdecl*original_PlayRadioOff__newgame)(int) = (void(__cdecl*)(int))0x004b1f33;
CARM95_HOOK_FUNCTION(original_PlayRadioOff__newgame, PlayRadioOff__newgame)
void __cdecl PlayRadioOff__newgame(int pIndex) {
    LOG_TRACE("(%d)", pIndex);

    (void)pIndex;

    original_PlayRadioOff__newgame(pIndex);
}

static void(__cdecl*original_DrawNetChooseInitial)() = (void(__cdecl*)())0x004b1d23;
CARM95_HOOK_FUNCTION(original_DrawNetChooseInitial, DrawNetChooseInitial)
void __cdecl DrawNetChooseInitial() {
    LOG_TRACE("()");


    original_DrawNetChooseInitial();
}

static int(__cdecl*original_NetChooseGoAhead)(int *, int *) = (int(__cdecl*)(int *, int *))0x004b1d9c;
CARM95_HOOK_FUNCTION(original_NetChooseGoAhead, NetChooseGoAhead)
int __cdecl NetChooseGoAhead(int *pCurrent_choice, int *pCurrent_mode) {
    LOG_TRACE("(%p, %p)", pCurrent_choice, pCurrent_mode);

    (void)pCurrent_choice;
    (void)pCurrent_mode;

    return original_NetChooseGoAhead(pCurrent_choice, pCurrent_mode);
}

static void(__cdecl*original_PlotAGraphBox__newgame)(int, int) = (void(__cdecl*)(int, int))0x004b2277;
CARM95_HOOK_FUNCTION(original_PlotAGraphBox__newgame, PlotAGraphBox__newgame)
void __cdecl PlotAGraphBox__newgame(int pIndex, int pColour_value) {
    LOG_TRACE("(%d, %d)", pIndex, pColour_value);

    (void)pIndex;
    (void)pColour_value;

    original_PlotAGraphBox__newgame(pIndex, pColour_value);
}

static void(__cdecl*original_DrawAGraphBox__newgame)(int) = (void(__cdecl*)(int))0x004b225e;
CARM95_HOOK_FUNCTION(original_DrawAGraphBox__newgame, DrawAGraphBox__newgame)
void __cdecl DrawAGraphBox__newgame(int pIndex) {
    LOG_TRACE("(%d)", pIndex);

    (void)pIndex;

    original_DrawAGraphBox__newgame(pIndex);
}

static void(__cdecl*original_EraseAGraphBox__newgame)(int) = (void(__cdecl*)(int))0x004b2325;
CARM95_HOOK_FUNCTION(original_EraseAGraphBox__newgame, EraseAGraphBox__newgame)
void __cdecl EraseAGraphBox__newgame(int pIndex) {
    LOG_TRACE("(%d)", pIndex);

    (void)pIndex;

    original_EraseAGraphBox__newgame(pIndex);
}

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

    original_DrawNetChoose(pCurrent_choice, pCurrent_mode);
}

static int(__cdecl*original_NetChooseLR)(int *, int *) = (int(__cdecl*)(int *, int *))0x004b233e;
CARM95_HOOK_FUNCTION(original_NetChooseLR, NetChooseLR)
int __cdecl NetChooseLR(int *pCurrent_choice, int *pCurrent_mode) {
    LOG_TRACE("(%p, %p)", pCurrent_choice, pCurrent_mode);

    (void)pCurrent_choice;
    (void)pCurrent_mode;

    return original_NetChooseLR(pCurrent_choice, pCurrent_mode);
}

static void(__cdecl*original_SetGameTarget)(tNet_game_type *, tNet_game_options *) = (void(__cdecl*)(tNet_game_type *, tNet_game_options *))0x004b2e6f;
CARM95_HOOK_FUNCTION(original_SetGameTarget, SetGameTarget)
void __cdecl SetGameTarget(tNet_game_type *pGame_type, tNet_game_options *pGame_options) {
    LOG_TRACE("(%p, %p)", pGame_type, pGame_options);

    (void)pGame_type;
    (void)pGame_options;

    original_SetGameTarget(pGame_type, pGame_options);
}

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

    return original_NetGameChoices(pGame_type, pGame_options, pRace_index);
}

static void(__cdecl*original_ReadNetGameChoices)(tNet_game_type *, tNet_game_options *, int *) = (void(__cdecl*)(tNet_game_type *, tNet_game_options *, int *))0x004b2f38;
CARM95_HOOK_FUNCTION(original_ReadNetGameChoices, ReadNetGameChoices)
void __cdecl ReadNetGameChoices(tNet_game_type *pGame_type, tNet_game_options *pGame_options, int *pRace_index) {
    LOG_TRACE("(%p, %p, %p)", pGame_type, pGame_options, pRace_index);

    (void)pGame_type;
    (void)pGame_options;
    (void)pRace_index;

    original_ReadNetGameChoices(pGame_type, pGame_options, pRace_index);
}

static int(__cdecl*original_ChooseStartRace)(int *) = (int(__cdecl*)(int *))0x004b235d;
CARM95_HOOK_FUNCTION(original_ChooseStartRace, ChooseStartRace)
int __cdecl ChooseStartRace(int *pRank) {
    LOG_TRACE("(%p)", pRank);

    (void)pRank;

    return original_ChooseStartRace(pRank);
}

static void(__cdecl*original_SetUpOtherNetThings)(tNet_game_details *) = (void(__cdecl*)(tNet_game_details *))0x004b237b;
CARM95_HOOK_FUNCTION(original_SetUpOtherNetThings, SetUpOtherNetThings)
void __cdecl SetUpOtherNetThings(tNet_game_details *pNet_game) {
    LOG_TRACE("(%p)", pNet_game);

    (void)pNet_game;

    original_SetUpOtherNetThings(pNet_game);
}

static void(__cdecl*original_RequestCarDetails)(tNet_game_details *) = (void(__cdecl*)(tNet_game_details *))0x004b246e;
CARM95_HOOK_FUNCTION(original_RequestCarDetails, RequestCarDetails)
void __cdecl RequestCarDetails(tNet_game_details *pNet_game) {
    tNet_message *message;
    LOG_TRACE("(%p)", pNet_game);

    (void)pNet_game;
    (void)message;

    original_RequestCarDetails(pNet_game);
}

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

    return original_PickARandomCar();
}

static void(__cdecl*original_PollCarDetails)(tNet_game_details *) = (void(__cdecl*)(tNet_game_details *))0x004b244a;
CARM95_HOOK_FUNCTION(original_PollCarDetails, PollCarDetails)
void __cdecl PollCarDetails(tNet_game_details *pNet_game) {
    LOG_TRACE("(%p)", pNet_game);

    (void)pNet_game;

    original_PollCarDetails(pNet_game);
}

static void(__cdecl*original_SetNetAvailability)(tNet_game_options *) = (void(__cdecl*)(tNet_game_options *))0x004b24c2;
CARM95_HOOK_FUNCTION(original_SetNetAvailability, SetNetAvailability)
void __cdecl SetNetAvailability(tNet_game_options *pOptions) {
    int i;
    LOG_TRACE("(%p)", pOptions);

    (void)pOptions;
    (void)i;

    original_SetNetAvailability(pOptions);
}

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

    return original_ChooseNetCar(pNet_game, pOptions, pCar_index, pIm_the_host_so_fuck_off);
}

static void(__cdecl*original_InitNetStorageSpace)() = (void(__cdecl*)())0x004b2f85;
CARM95_HOOK_FUNCTION(original_InitNetStorageSpace, InitNetStorageSpace)
void __cdecl InitNetStorageSpace() {
    int i;
    LOG_TRACE("()");

    (void)i;

    original_InitNetStorageSpace();
}

static void(__cdecl*original_DisposeNetStorageSpace)() = (void(__cdecl*)())0x004b2fe9;
CARM95_HOOK_FUNCTION(original_DisposeNetStorageSpace, DisposeNetStorageSpace)
void __cdecl DisposeNetStorageSpace() {
    LOG_TRACE("()");


    original_DisposeNetStorageSpace();
}

static int(__fastcall*original_DoMultiPlayerStart)() = (int(__fastcall*)())0x004b27a7;
CARM95_HOOK_FUNCTION(original_DoMultiPlayerStart, DoMultiPlayerStart)
int __fastcall DoMultiPlayerStart() {
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

