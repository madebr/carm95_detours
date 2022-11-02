#include "loadsave.h"

#include "harness/trace.h"

#include "carm95_hooks.h"

#include "carm95_webserver.h"

#include <assert.h>
tSave_game *(* hookvar_gSaved_games )[8] = (void*)0x00536278;
int * hookvar_gStarted_typing  = (void*)0x00536270;
int * hookvar_gSave_allowed  = (void*)0x00536274;

function_hook_state_t function_hook_state_CorrectLoadByteOrdering = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_CorrectLoadByteOrdering)
static void(__cdecl*original_CorrectLoadByteOrdering)(int) = (void(__cdecl*)(int))0x0044bb57;
CARM95_HOOK_FUNCTION(original_CorrectLoadByteOrdering, CorrectLoadByteOrdering)
void __cdecl CorrectLoadByteOrdering(int pIndex) {
    int i;
    LOG_TRACE("(%d)", pIndex);

    (void)pIndex;
    (void)i;

    if (function_hook_state_CorrectLoadByteOrdering == HOOK_ENABLED) {
        assert(0 && "CorrectLoadByteOrdering not implemented.");
        abort();
    } else {
        original_CorrectLoadByteOrdering(pIndex);
    }
}

function_hook_state_t function_hook_state_CalcLSChecksum = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_CalcLSChecksum)
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

    if (function_hook_state_CalcLSChecksum == HOOK_ENABLED) {
        assert(0 && "CalcLSChecksum not implemented.");
        abort();
    } else {
        return original_CalcLSChecksum(pSaved_game);
    }
}

function_hook_state_t function_hook_state_LoadSavedGames = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_LoadSavedGames)
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

    if (function_hook_state_LoadSavedGames == HOOK_ENABLED) {
        assert(0 && "LoadSavedGames not implemented.");
        abort();
    } else {
        original_LoadSavedGames();
    }
}

function_hook_state_t function_hook_state_DisposeSavedGames = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_DisposeSavedGames)
static void(__cdecl*original_DisposeSavedGames)() = (void(__cdecl*)())0x0044c111;
CARM95_HOOK_FUNCTION(original_DisposeSavedGames, DisposeSavedGames)
void __cdecl DisposeSavedGames() {
    int i;
    LOG_TRACE("()");

    (void)i;

    if (function_hook_state_DisposeSavedGames == HOOK_ENABLED) {
        assert(0 && "DisposeSavedGames not implemented.");
        abort();
    } else {
        original_DisposeSavedGames();
    }
}

function_hook_state_t function_hook_state_LoadTheGame = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_LoadTheGame)
static void(__cdecl*original_LoadTheGame)(int) = (void(__cdecl*)(int))0x0044c161;
CARM95_HOOK_FUNCTION(original_LoadTheGame, LoadTheGame)
void __cdecl LoadTheGame(int pSlot_index) {
    int i;
    char the_car_name[14];
    LOG_TRACE("(%d)", pSlot_index);

    (void)pSlot_index;
    (void)i;
    (void)the_car_name;

    if (function_hook_state_LoadTheGame == HOOK_ENABLED) {
        assert(0 && "LoadTheGame not implemented.");
        abort();
    } else {
        original_LoadTheGame(pSlot_index);
    }
}

function_hook_state_t function_hook_state_StartRollingSaveNamesIn = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_StartRollingSaveNamesIn)
static void(__cdecl*original_StartRollingSaveNamesIn)() = (void(__cdecl*)())0x0044be19;
CARM95_HOOK_FUNCTION(original_StartRollingSaveNamesIn, StartRollingSaveNamesIn)
void __cdecl StartRollingSaveNamesIn() {
    int i;
    int save_slot_height;
    LOG_TRACE("()");

    (void)i;
    (void)save_slot_height;

    if (function_hook_state_StartRollingSaveNamesIn == HOOK_ENABLED) {
        assert(0 && "StartRollingSaveNamesIn not implemented.");
        abort();
    } else {
        original_StartRollingSaveNamesIn();
    }
}

function_hook_state_t function_hook_state_LoadStart = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_LoadStart)
static void(__cdecl*original_LoadStart)() = (void(__cdecl*)())0x0044be09;
CARM95_HOOK_FUNCTION(original_LoadStart, LoadStart)
void __cdecl LoadStart() {
    LOG_TRACE("()");


    if (function_hook_state_LoadStart == HOOK_ENABLED) {
        assert(0 && "LoadStart not implemented.");
        abort();
    } else {
        original_LoadStart();
    }
}

function_hook_state_t function_hook_state_DoLoadGame = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_DoLoadGame)
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

    if (function_hook_state_DoLoadGame == HOOK_ENABLED) {
        assert(0 && "DoLoadGame not implemented.");
        abort();
    } else {
        return original_DoLoadGame(pSave_allowed);
    }
}

function_hook_state_t function_hook_state_CorrectSaveByteOrdering = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_CorrectSaveByteOrdering)
static void(__cdecl*original_CorrectSaveByteOrdering)(int) = (void(__cdecl*)(int))0x0044c8e7;
CARM95_HOOK_FUNCTION(original_CorrectSaveByteOrdering, CorrectSaveByteOrdering)
void __cdecl CorrectSaveByteOrdering(int pIndex) {
    int i;
    LOG_TRACE("(%d)", pIndex);

    (void)pIndex;
    (void)i;

    if (function_hook_state_CorrectSaveByteOrdering == HOOK_ENABLED) {
        assert(0 && "CorrectSaveByteOrdering not implemented.");
        abort();
    } else {
        original_CorrectSaveByteOrdering(pIndex);
    }
}

function_hook_state_t function_hook_state_SaveTheGame = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_SaveTheGame)
static void(__cdecl*original_SaveTheGame)(int) = (void(__cdecl*)(int))0x0044c7e0;
CARM95_HOOK_FUNCTION(original_SaveTheGame, SaveTheGame)
void __cdecl SaveTheGame(int pSlot_number) {
    tPath_name the_path;
    FILE *f;
    LOG_TRACE("(%d)", pSlot_number);

    (void)pSlot_number;
    (void)the_path;
    (void)f;

    if (function_hook_state_SaveTheGame == HOOK_ENABLED) {
        assert(0 && "SaveTheGame not implemented.");
        abort();
    } else {
        original_SaveTheGame(pSlot_number);
    }
}

function_hook_state_t function_hook_state_ConfirmMidGameSave = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_ConfirmMidGameSave)
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

    if (function_hook_state_ConfirmMidGameSave == HOOK_ENABLED) {
        assert(0 && "ConfirmMidGameSave not implemented.");
        abort();
    } else {
        return original_ConfirmMidGameSave();
    }
}

function_hook_state_t function_hook_state_MakeSavedGame = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_MakeSavedGame)
static void(__cdecl*original_MakeSavedGame)(tSave_game **) = (void(__cdecl*)(tSave_game **))0x0044c443;
CARM95_HOOK_FUNCTION(original_MakeSavedGame, MakeSavedGame)
void __cdecl MakeSavedGame(tSave_game **pSave_record) {
    int i;
    LOG_TRACE("(%p)", pSave_record);

    (void)pSave_record;
    (void)i;

    if (function_hook_state_MakeSavedGame == HOOK_ENABLED) {
        assert(0 && "MakeSavedGame not implemented.");
        abort();
    } else {
        original_MakeSavedGame(pSave_record);
    }
}

function_hook_state_t function_hook_state_SaveStart = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_SaveStart)
static void(__cdecl*original_SaveStart)() = (void(__cdecl*)())0x0044c66c;
CARM95_HOOK_FUNCTION(original_SaveStart, SaveStart)
void __cdecl SaveStart() {
    LOG_TRACE("()");


    if (function_hook_state_SaveStart == HOOK_ENABLED) {
        assert(0 && "SaveStart not implemented.");
        abort();
    } else {
        original_SaveStart();
    }
}

function_hook_state_t function_hook_state_GetSaveName = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_GetSaveName)
static void(__cdecl*original_GetSaveName)(int, int, char *, int *) = (void(__cdecl*)(int, int, char *, int *))0x0044c67c;
CARM95_HOOK_FUNCTION(original_GetSaveName, GetSaveName)
void __cdecl GetSaveName(int pStarting_to_type, int pCurrent_choice, char *pString, int *pMax_length) {
    LOG_TRACE("(%d, %d, \"%s\", %p)", pStarting_to_type, pCurrent_choice, pString, pMax_length);

    (void)pStarting_to_type;
    (void)pCurrent_choice;
    (void)pString;
    (void)pMax_length;

    if (function_hook_state_GetSaveName == HOOK_ENABLED) {
        assert(0 && "GetSaveName not implemented.");
        abort();
    } else {
        original_GetSaveName(pStarting_to_type, pCurrent_choice, pString, pMax_length);
    }
}

function_hook_state_t function_hook_state_SaveDone = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_SaveDone)
static int(__cdecl*original_SaveDone)(int, int, int, int, int) = (int(__cdecl*)(int, int, int, int, int))0x0044c73e;
CARM95_HOOK_FUNCTION(original_SaveDone, SaveDone)
int __cdecl SaveDone(int pCurrent_choice, int pCurrent_mode, int pGo_ahead, int pEscaped, int pTimed_out) {
    LOG_TRACE("(%d, %d, %d, %d, %d)", pCurrent_choice, pCurrent_mode, pGo_ahead, pEscaped, pTimed_out);

    (void)pCurrent_choice;
    (void)pCurrent_mode;
    (void)pGo_ahead;
    (void)pEscaped;
    (void)pTimed_out;

    if (function_hook_state_SaveDone == HOOK_ENABLED) {
        assert(0 && "SaveDone not implemented.");
        abort();
    } else {
        return original_SaveDone(pCurrent_choice, pCurrent_mode, pGo_ahead, pEscaped, pTimed_out);
    }
}

function_hook_state_t function_hook_state_SaveGoAhead = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_SaveGoAhead)
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

    if (function_hook_state_SaveGoAhead == HOOK_ENABLED) {
        assert(0 && "SaveGoAhead not implemented.");
        abort();
    } else {
        return original_SaveGoAhead(pCurrent_choice, pCurrent_mode);
    }
}

function_hook_state_t function_hook_state_SaveEscape = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_SaveEscape)
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

    if (function_hook_state_SaveEscape == HOOK_ENABLED) {
        assert(0 && "SaveEscape not implemented.");
        abort();
    } else {
        return original_SaveEscape(pCurrent_choice, pCurrent_mode);
    }
}

function_hook_state_t function_hook_state_SaveGameInterface = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_SaveGameInterface)
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

    if (function_hook_state_SaveGameInterface == HOOK_ENABLED) {
        assert(0 && "SaveGameInterface not implemented.");
        abort();
    } else {
        return original_SaveGameInterface(pDefault_choice);
    }
}

function_hook_state_t function_hook_state_DoSaveGame = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_DoSaveGame)
static void(__cdecl*original_DoSaveGame)(int) = (void(__cdecl*)(int))0x0044cdfd;
CARM95_HOOK_FUNCTION(original_DoSaveGame, DoSaveGame)
void __cdecl DoSaveGame(int pSave_allowed) {
    LOG_TRACE("(%d)", pSave_allowed);

    (void)pSave_allowed;

    if (function_hook_state_DoSaveGame == HOOK_ENABLED) {
        assert(0 && "DoSaveGame not implemented.");
        abort();
    } else {
        original_DoSaveGame(pSave_allowed);
    }
}

