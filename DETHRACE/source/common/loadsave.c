#include "loadsave.h"

#include "harness/trace.h"

#include "carm95_hooks.h"

tSave_game *(* hookvar_gSaved_games )[8] = (void*)0x00536278;
int * hookvar_gStarted_typing  = (void*)0x00536270;
int * hookvar_gSave_allowed  = (void*)0x00536274;

static void(__cdecl*original_CorrectLoadByteOrdering)(int) = (void(__cdecl*)(int))0x0044bb57;
CARM95_HOOK_FUNCTION(original_CorrectLoadByteOrdering, CorrectLoadByteOrdering)
void __cdecl CorrectLoadByteOrdering(int pIndex) {
    int i;
    LOG_TRACE("(%d)", pIndex);

    (void)pIndex;
    (void)i;

    original_CorrectLoadByteOrdering(pIndex);
}

static tU32(__cdecl*original_CalcLSChecksum)(tSave_game *) = (tU32(__cdecl*)(tSave_game *))0x0044bd9d;
CARM95_HOOK_FUNCTION(original_CalcLSChecksum, CalcLSChecksum)
tU32 __cdecl CalcLSChecksum(tSave_game *pSaved_game) {
    tU32 checksum;
    tU32 checksum2;
    int i;
    tU8 *ptr;
    LOG_TRACE("(%p)", pSaved_game);

    (void)pSaved_game;
    (void)checksum;
    (void)checksum2;
    (void)i;
    (void)ptr;

    return original_CalcLSChecksum(pSaved_game);
}

static void(__cdecl*original_LoadSavedGames)() = (void(__cdecl*)())0x0044b9b0;
CARM95_HOOK_FUNCTION(original_LoadSavedGames, LoadSavedGames)
void __cdecl LoadSavedGames() {
    tPath_name the_path;
    int i;
    FILE *f;
    tU32 the_size;
    LOG_TRACE("()");

    (void)the_path;
    (void)i;
    (void)f;
    (void)the_size;

    original_LoadSavedGames();
}

static void(__cdecl*original_DisposeSavedGames)() = (void(__cdecl*)())0x0044c111;
CARM95_HOOK_FUNCTION(original_DisposeSavedGames, DisposeSavedGames)
void __cdecl DisposeSavedGames() {
    int i;
    LOG_TRACE("()");

    (void)i;

    original_DisposeSavedGames();
}

static void(__cdecl*original_LoadTheGame)(int) = (void(__cdecl*)(int))0x0044c161;
CARM95_HOOK_FUNCTION(original_LoadTheGame, LoadTheGame)
void __cdecl LoadTheGame(int pSlot_index) {
    int i;
    char the_car_name[14];
    LOG_TRACE("(%d)", pSlot_index);

    (void)pSlot_index;
    (void)i;
    (void)the_car_name;

    original_LoadTheGame(pSlot_index);
}

static void(__cdecl*original_StartRollingSaveNamesIn)() = (void(__cdecl*)())0x0044be19;
CARM95_HOOK_FUNCTION(original_StartRollingSaveNamesIn, StartRollingSaveNamesIn)
void __cdecl StartRollingSaveNamesIn() {
    int i;
    int save_slot_height;
    LOG_TRACE("()");

    (void)i;
    (void)save_slot_height;

    original_StartRollingSaveNamesIn();
}

static void(__cdecl*original_LoadStart)() = (void(__cdecl*)())0x0044be09;
CARM95_HOOK_FUNCTION(original_LoadStart, LoadStart)
void __cdecl LoadStart() {
    LOG_TRACE("()");


    original_LoadStart();
}

static int(__cdecl*original_DoLoadGame)(int) = (int(__cdecl*)(int))0x0044bf62;
CARM95_HOOK_FUNCTION(original_DoLoadGame, DoLoadGame)
int __cdecl DoLoadGame(int pSave_allowed) {
    static tFlicette flicker_on[9];
    static tFlicette flicker_off[9];
    static tFlicette push[9];
    static tMouse_area mouse_areas[9];
    static tRectile recopy_areas[24];
    static tInterface_spec interface_spec;
    int result;
    LOG_TRACE("(%d)", pSave_allowed);

    (void)pSave_allowed;
    (void)flicker_on;
    (void)flicker_off;
    (void)push;
    (void)mouse_areas;
    (void)recopy_areas;
    (void)interface_spec;
    (void)result;

    return original_DoLoadGame(pSave_allowed);
}

static void(__cdecl*original_CorrectSaveByteOrdering)(int) = (void(__cdecl*)(int))0x0044c8e7;
CARM95_HOOK_FUNCTION(original_CorrectSaveByteOrdering, CorrectSaveByteOrdering)
void __cdecl CorrectSaveByteOrdering(int pIndex) {
    int i;
    LOG_TRACE("(%d)", pIndex);

    (void)pIndex;
    (void)i;

    original_CorrectSaveByteOrdering(pIndex);
}

static void(__cdecl*original_SaveTheGame)(int) = (void(__cdecl*)(int))0x0044c7e0;
CARM95_HOOK_FUNCTION(original_SaveTheGame, SaveTheGame)
void __cdecl SaveTheGame(int pSlot_number) {
    tPath_name the_path;
    FILE *f;
    LOG_TRACE("(%d)", pSlot_number);

    (void)pSlot_number;
    (void)the_path;
    (void)f;

    original_SaveTheGame(pSlot_number);
}

static int(__cdecl*original_ConfirmMidGameSave)() = (int(__cdecl*)())0x0044ceb9;
CARM95_HOOK_FUNCTION(original_ConfirmMidGameSave, ConfirmMidGameSave)
int __cdecl ConfirmMidGameSave() {
    static tFlicette flicker_on[2];
    static tFlicette flicker_off[2];
    static tFlicette push[2];
    static tMouse_area mouse_areas[2];
    static tInterface_spec interface_spec;
    LOG_TRACE("()");

    (void)flicker_on;
    (void)flicker_off;
    (void)push;
    (void)mouse_areas;
    (void)interface_spec;

    return original_ConfirmMidGameSave();
}

static void(__cdecl*original_MakeSavedGame)(tSave_game **) = (void(__cdecl*)(tSave_game **))0x0044c443;
CARM95_HOOK_FUNCTION(original_MakeSavedGame, MakeSavedGame)
void __cdecl MakeSavedGame(tSave_game **pSave_record) {
    int i;
    LOG_TRACE("(%p)", pSave_record);

    (void)pSave_record;
    (void)i;

    original_MakeSavedGame(pSave_record);
}

static void(__cdecl*original_SaveStart)() = (void(__cdecl*)())0x0044c66c;
CARM95_HOOK_FUNCTION(original_SaveStart, SaveStart)
void __cdecl SaveStart() {
    LOG_TRACE("()");


    original_SaveStart();
}

static void(__cdecl*original_GetSaveName)(int, int, char *, int *) = (void(__cdecl*)(int, int, char *, int *))0x0044c67c;
CARM95_HOOK_FUNCTION(original_GetSaveName, GetSaveName)
void __cdecl GetSaveName(int pStarting_to_type, int pCurrent_choice, char *pString, int *pMax_length) {
    LOG_TRACE("(%d, %d, \"%s\", %p)", pStarting_to_type, pCurrent_choice, pString, pMax_length);

    (void)pStarting_to_type;
    (void)pCurrent_choice;
    (void)pString;
    (void)pMax_length;

    original_GetSaveName(pStarting_to_type, pCurrent_choice, pString, pMax_length);
}

static int(__cdecl*original_SaveDone)(int, int, int, int, int) = (int(__cdecl*)(int, int, int, int, int))0x0044c73e;
CARM95_HOOK_FUNCTION(original_SaveDone, SaveDone)
int __cdecl SaveDone(int pCurrent_choice, int pCurrent_mode, int pGo_ahead, int pEscaped, int pTimed_out) {
    LOG_TRACE("(%d, %d, %d, %d, %d)", pCurrent_choice, pCurrent_mode, pGo_ahead, pEscaped, pTimed_out);

    (void)pCurrent_choice;
    (void)pCurrent_mode;
    (void)pGo_ahead;
    (void)pEscaped;
    (void)pTimed_out;

    return original_SaveDone(pCurrent_choice, pCurrent_mode, pGo_ahead, pEscaped, pTimed_out);
}

static int(__cdecl*original_SaveGoAhead)(int *, int *) = (int(__cdecl*)(int *, int *))0x0044cb2d;
CARM95_HOOK_FUNCTION(original_SaveGoAhead, SaveGoAhead)
int __cdecl SaveGoAhead(int *pCurrent_choice, int *pCurrent_mode) {
    char s1[256];
    char s2[256];
    LOG_TRACE("(%p, %p)", pCurrent_choice, pCurrent_mode);

    (void)pCurrent_choice;
    (void)pCurrent_mode;
    (void)s1;
    (void)s2;

    return original_SaveGoAhead(pCurrent_choice, pCurrent_mode);
}

static int(__cdecl*original_SaveEscape)(int *, int *) = (int(__cdecl*)(int *, int *))0x0044cc95;
CARM95_HOOK_FUNCTION(original_SaveEscape, SaveEscape)
int __cdecl SaveEscape(int *pCurrent_choice, int *pCurrent_mode) {
    char s1[256];
    char s2[256];
    LOG_TRACE("(%p, %p)", pCurrent_choice, pCurrent_mode);

    (void)pCurrent_choice;
    (void)pCurrent_mode;
    (void)s1;
    (void)s2;

    return original_SaveEscape(pCurrent_choice, pCurrent_mode);
}

static int(__cdecl*original_SaveGameInterface)(int) = (int(__cdecl*)(int))0x0044ceee;
CARM95_HOOK_FUNCTION(original_SaveGameInterface, SaveGameInterface)
int __cdecl SaveGameInterface(int pDefault_choice) {
    static tFlicette flicker_on[9];
    static tFlicette flicker_off[9];
    static tFlicette push[9];
    static tMouse_area mouse_areas[9];
    static tRectile recopy_areas[24];
    static tInterface_spec interface_spec;
    LOG_TRACE("(%d)", pDefault_choice);

    (void)pDefault_choice;
    (void)flicker_on;
    (void)flicker_off;
    (void)push;
    (void)mouse_areas;
    (void)recopy_areas;
    (void)interface_spec;

    return original_SaveGameInterface(pDefault_choice);
}

static void(__cdecl*original_DoSaveGame)(int) = (void(__cdecl*)(int))0x0044cdfd;
CARM95_HOOK_FUNCTION(original_DoSaveGame, DoSaveGame)
void __cdecl DoSaveGame(int pSave_allowed) {
    LOG_TRACE("(%d)", pSave_allowed);

    (void)pSave_allowed;

    original_DoSaveGame(pSave_allowed);
}
