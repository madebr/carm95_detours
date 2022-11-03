#include "input.h"

#include "harness/trace.h"

#include "carm95_hooks.h"

#include "carm95_webserver.h"

#include <assert.h>
int * hookvar_gEdge_trigger_mode  = (void*)0x00514c70;
tU32 * hookvar_gLast_poll_keys  = (void*)0x00514c74;
int * hookvar_gInsert_mode  = (void*)0x00514c78;
int(* hookvar_gGo_ahead_keys )[3] = (void*)0x00514c80;
tJoy_array * hookvar_gJoy_array  = (void*)0x005505f4;
tKey_array * hookvar_gKey_array  = (void*)0x0053a250;
int * hookvar_gKey_poll_counter  = (void*)0x0053a248;
tRolling_letter ** hookvar_gRolling_letters  = (void*)0x0053a1f8;
int * hookvar_gCurrent_cursor  = (void*)0x0053a440;
int * hookvar_gCurrent_position  = (void*)0x0053a4c0;
int(* hookvar_gLetter_x_coords )[15] = (void*)0x0053a200;
int * hookvar_gVisible_length  = (void*)0x0053a240;
int(* hookvar_gLetter_y_coords )[15] = (void*)0x0053a1b8;
#if 0
int * hookvar_gThe_key ;
#endif
tU32 * hookvar_gLast_key_down_time  = (void*)0x0053a444;
int * hookvar_gThe_length  = (void*)0x0053a1f4;
tU32 * hookvar_gLast_roll  = (void*)0x0053a448;
int * hookvar_gLast_key_down  = (void*)0x0053a244;
int(* hookvar_gKey_mapping )[67] = (void*)0x005507e0;
char(* hookvar_gCurrent_typing )[110] = (void*)0x0053a450;

function_hook_state_t function_hook_state_SetJoystickArrays = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(SetJoystickArrays, function_hook_state_SetJoystickArrays)
static void(__cdecl*original_SetJoystickArrays)(int *, int) = (void(__cdecl*)(int *, int))0x00471750;
CARM95_HOOK_FUNCTION(original_SetJoystickArrays, SetJoystickArrays)
void __cdecl SetJoystickArrays(int *pKeys, int pMark) {
    int i;
    tS32 joyX;
    tS32 joyY;
    static tS32 old_joy1X;
    static tS32 old_joy1Y;
    static tS32 old_joy2X;
    static tS32 old_joy2Y;
    LOG_TRACE("(%p, %d)", pKeys, pMark);

    (void)pKeys;
    (void)pMark;
    (void)i;
    (void)joyX;
    (void)joyY;
    (void)old_joy1X;
    (void)old_joy1Y;
    (void)old_joy2X;
    (void)old_joy2Y;

    if (function_hook_state_SetJoystickArrays == HOOK_ENABLED) {
        assert(0 && "SetJoystickArrays not implemented.");
        abort();
    } else {
        original_SetJoystickArrays(pKeys, pMark);
    }
}

function_hook_state_t function_hook_state_PollKeys = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(PollKeys, function_hook_state_PollKeys)
static void(__cdecl*original_PollKeys)() = (void(__cdecl*)())0x00471bbf;
CARM95_HOOK_FUNCTION(original_PollKeys, PollKeys)
void __cdecl PollKeys() {
    int i;
    LOG_TRACE("()");

    (void)i;

    if (function_hook_state_PollKeys == HOOK_ENABLED) {
        assert(0 && "PollKeys not implemented.");
        abort();
    } else {
        original_PollKeys();
    }
}

function_hook_state_t function_hook_state_CyclePollKeys = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(CyclePollKeys, function_hook_state_CyclePollKeys)
static void(__cdecl*original_CyclePollKeys)() = (void(__cdecl*)())0x00471c03;
CARM95_HOOK_FUNCTION(original_CyclePollKeys, CyclePollKeys)
void __cdecl CyclePollKeys() {
    int i;
    LOG_TRACE("()");

    (void)i;

    if (function_hook_state_CyclePollKeys == HOOK_ENABLED) {
        assert(0 && "CyclePollKeys not implemented.");
        abort();
    } else {
        original_CyclePollKeys();
    }
}

function_hook_state_t function_hook_state_ResetPollKeys = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(ResetPollKeys, function_hook_state_ResetPollKeys)
static void(__cdecl*original_ResetPollKeys)() = (void(__cdecl*)())0x00471c75;
CARM95_HOOK_FUNCTION(original_ResetPollKeys, ResetPollKeys)
void __cdecl ResetPollKeys() {
    int i;
    LOG_TRACE("()");

    (void)i;

    if (function_hook_state_ResetPollKeys == HOOK_ENABLED) {
        assert(0 && "ResetPollKeys not implemented.");
        abort();
    } else {
        original_ResetPollKeys();
    }
}

function_hook_state_t function_hook_state_CheckKeysForMouldiness = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(CheckKeysForMouldiness, function_hook_state_CheckKeysForMouldiness)
static void(__cdecl*original_CheckKeysForMouldiness)() = (void(__cdecl*)())0x00471cdb;
CARM95_HOOK_FUNCTION(original_CheckKeysForMouldiness, CheckKeysForMouldiness)
void __cdecl CheckKeysForMouldiness() {
    LOG_TRACE("()");


    if (function_hook_state_CheckKeysForMouldiness == HOOK_ENABLED) {
        assert(0 && "CheckKeysForMouldiness not implemented.");
        abort();
    } else {
        original_CheckKeysForMouldiness();
    }
}

function_hook_state_t function_hook_state_EitherMouseButtonDown = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(EitherMouseButtonDown, function_hook_state_EitherMouseButtonDown)
static int(__cdecl*original_EitherMouseButtonDown)() = (int(__cdecl*)())0x00471d0b;
CARM95_HOOK_FUNCTION(original_EitherMouseButtonDown, EitherMouseButtonDown)
int __cdecl EitherMouseButtonDown() {
    int but_1;
    int but_2;
    LOG_TRACE("()");

    (void)but_1;
    (void)but_2;

    if (function_hook_state_EitherMouseButtonDown == HOOK_ENABLED) {
        assert(0 && "EitherMouseButtonDown not implemented.");
        abort();
    } else {
        return original_EitherMouseButtonDown();
    }
}

function_hook_state_t function_hook_state_PDKeyDown2 = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(PDKeyDown2, function_hook_state_PDKeyDown2)
static tKey_down_result(__cdecl*original_PDKeyDown2)(int) = (tKey_down_result(__cdecl*)(int))0x00471d4e;
CARM95_HOOK_FUNCTION(original_PDKeyDown2, PDKeyDown2)
tKey_down_result __cdecl PDKeyDown2(int pKey_index) {
    tU32 the_time;
    LOG_TRACE("(%d)", pKey_index);

    (void)pKey_index;
    (void)the_time;

    if (function_hook_state_PDKeyDown2 == HOOK_ENABLED) {
        assert(0 && "PDKeyDown2 not implemented.");
        abort();
    } else {
        return original_PDKeyDown2(pKey_index);
    }
}

function_hook_state_t function_hook_state_PDKeyDown = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(PDKeyDown, function_hook_state_PDKeyDown)
static int(__cdecl*original_PDKeyDown)(int) = (int(__cdecl*)(int))0x00471e2d;
CARM95_HOOK_FUNCTION(original_PDKeyDown, PDKeyDown)
int __cdecl PDKeyDown(int pKey_index) {
    tKey_down_result result;
    LOG_TRACE("(%d)", pKey_index);

    (void)pKey_index;
    (void)result;

    if (function_hook_state_PDKeyDown == HOOK_ENABLED) {
        assert(0 && "PDKeyDown not implemented.");
        abort();
    } else {
        return original_PDKeyDown(pKey_index);
    }
}

function_hook_state_t function_hook_state_PDKeyDown3 = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(PDKeyDown3, function_hook_state_PDKeyDown3)
static int(__cdecl*original_PDKeyDown3)(int) = (int(__cdecl*)(int))0x00471ea6;
CARM95_HOOK_FUNCTION(original_PDKeyDown3, PDKeyDown3)
int __cdecl PDKeyDown3(int pKey_index) {
    int last_key_down_time;
    int last_key_down;
    tKey_down_result result;
    LOG_TRACE("(%d)", pKey_index);

    (void)pKey_index;
    (void)last_key_down_time;
    (void)last_key_down;
    (void)result;

    if (function_hook_state_PDKeyDown3 == HOOK_ENABLED) {
        assert(0 && "PDKeyDown3 not implemented.");
        abort();
    } else {
        return original_PDKeyDown3(pKey_index);
    }
}

function_hook_state_t function_hook_state_PDAnyKeyDown = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(PDAnyKeyDown, function_hook_state_PDAnyKeyDown)
static int(__cdecl*original_PDAnyKeyDown)() = (int(__cdecl*)())0x00471f08;
CARM95_HOOK_FUNCTION(original_PDAnyKeyDown, PDAnyKeyDown)
int __cdecl PDAnyKeyDown() {
    int i;
    tKey_down_result result;
    LOG_TRACE("()");

    (void)i;
    (void)result;

    if (function_hook_state_PDAnyKeyDown == HOOK_ENABLED) {
        assert(0 && "PDAnyKeyDown not implemented.");
        abort();
    } else {
        return original_PDAnyKeyDown();
    }
}

function_hook_state_t function_hook_state_AnyKeyDown = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(AnyKeyDown, function_hook_state_AnyKeyDown)
static int(__cdecl*original_AnyKeyDown)() = (int(__cdecl*)())0x00471fe4;
CARM95_HOOK_FUNCTION(original_AnyKeyDown, AnyKeyDown)
int __cdecl AnyKeyDown() {
    int the_key;
    LOG_TRACE("()");

    (void)the_key;

    if (function_hook_state_AnyKeyDown == HOOK_ENABLED) {
        assert(0 && "AnyKeyDown not implemented.");
        abort();
    } else {
        return original_AnyKeyDown();
    }
}

function_hook_state_t function_hook_state_KevKeyService = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(KevKeyService, function_hook_state_KevKeyService)
static tU32 *(__cdecl*original_KevKeyService)() = (tU32 *(__cdecl*)())0x0047202c;
CARM95_HOOK_FUNCTION(original_KevKeyService, KevKeyService)
tU32* __cdecl KevKeyService() {
    static tU32 sum;
    static tU32 code;
    static tU32 code2;
    static int last_key;
    static int last_single_key;
    static tU32 last_time;
    static tU32 return_val[2];
    tU32 keys;
    LOG_TRACE("()");

    (void)sum;
    (void)code;
    (void)code2;
    (void)last_key;
    (void)last_single_key;
    (void)last_time;
    (void)return_val;
    (void)keys;

    if (function_hook_state_KevKeyService == HOOK_ENABLED) {
        assert(0 && "KevKeyService not implemented.");
        abort();
    } else {
        return original_KevKeyService();
    }
}

function_hook_state_t function_hook_state_OldKeyIsDown = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(OldKeyIsDown, function_hook_state_OldKeyIsDown)
static int(__cdecl*original_OldKeyIsDown)(int) = (int(__cdecl*)(int))0x004721fb;
CARM95_HOOK_FUNCTION(original_OldKeyIsDown, OldKeyIsDown)
int __cdecl OldKeyIsDown(int pKey_index) {
    int i;
    LOG_TRACE("(%d)", pKey_index);

    (void)pKey_index;
    (void)i;

    if (function_hook_state_OldKeyIsDown == HOOK_ENABLED) {
        assert(0 && "OldKeyIsDown not implemented.");
        abort();
    } else {
        return original_OldKeyIsDown(pKey_index);
    }
}

function_hook_state_t function_hook_state_KeyIsDown = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(KeyIsDown, function_hook_state_KeyIsDown)
static int(__cdecl*original_KeyIsDown)(int) = (int(__cdecl*)(int))0x00472293;
CARM95_HOOK_FUNCTION(original_KeyIsDown, KeyIsDown)
int __cdecl KeyIsDown(int pKey_index) {
    int i;
    LOG_TRACE("(%d)", pKey_index);

    (void)pKey_index;
    (void)i;

    if (function_hook_state_KeyIsDown == HOOK_ENABLED) {
        assert(0 && "KeyIsDown not implemented.");
        abort();
    } else {
        return original_KeyIsDown(pKey_index);
    }
}

function_hook_state_t function_hook_state_WaitForNoKeys = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(WaitForNoKeys, function_hook_state_WaitForNoKeys)
static void(__cdecl*original_WaitForNoKeys)() = (void(__cdecl*)())0x0047232b;
CARM95_HOOK_FUNCTION(original_WaitForNoKeys, WaitForNoKeys)
void __cdecl WaitForNoKeys() {
    LOG_TRACE("()");


    if (function_hook_state_WaitForNoKeys == HOOK_ENABLED) {
        assert(0 && "WaitForNoKeys not implemented.");
        abort();
    } else {
        original_WaitForNoKeys();
    }
}

function_hook_state_t function_hook_state_WaitForAKey = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(WaitForAKey, function_hook_state_WaitForAKey)
static void(__cdecl*original_WaitForAKey)() = (void(__cdecl*)())0x0047235a;
CARM95_HOOK_FUNCTION(original_WaitForAKey, WaitForAKey)
void __cdecl WaitForAKey() {
    LOG_TRACE("()");


    if (function_hook_state_WaitForAKey == HOOK_ENABLED) {
        assert(0 && "WaitForAKey not implemented.");
        abort();
    } else {
        original_WaitForAKey();
    }
}

function_hook_state_t function_hook_state_CmdKeyDown = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(CmdKeyDown, function_hook_state_CmdKeyDown)
static int(__cdecl*original_CmdKeyDown)(int, int) = (int(__cdecl*)(int, int))0x0047238e;
CARM95_HOOK_FUNCTION(original_CmdKeyDown, CmdKeyDown)
int __cdecl CmdKeyDown(int pFKey_ID, int pCmd_key_ID) {
    LOG_TRACE("(%d, %d)", pFKey_ID, pCmd_key_ID);

    (void)pFKey_ID;
    (void)pCmd_key_ID;

    if (function_hook_state_CmdKeyDown == HOOK_ENABLED) {
        assert(0 && "CmdKeyDown not implemented.");
        abort();
    } else {
        return original_CmdKeyDown(pFKey_ID, pCmd_key_ID);
    }
}

function_hook_state_t function_hook_state_GetMousePosition = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(GetMousePosition, function_hook_state_GetMousePosition)
static void(__cdecl*original_GetMousePosition)(int *, int *) = (void(__cdecl*)(int *, int *))0x004723e4;
CARM95_HOOK_FUNCTION(original_GetMousePosition, GetMousePosition)
void __cdecl GetMousePosition(int *pX_coord, int *pY_coord) {
    int x_left_margin;
    int x_right_margin;
    int y_top_margin;
    int y_bottom_margin;
    LOG_TRACE("(%p, %p)", pX_coord, pY_coord);

    (void)pX_coord;
    (void)pY_coord;
    (void)x_left_margin;
    (void)x_right_margin;
    (void)y_top_margin;
    (void)y_bottom_margin;

    if (function_hook_state_GetMousePosition == HOOK_ENABLED) {
        assert(0 && "GetMousePosition not implemented.");
        abort();
    } else {
        original_GetMousePosition(pX_coord, pY_coord);
    }
}

function_hook_state_t function_hook_state_InitRollingLetters = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(InitRollingLetters, function_hook_state_InitRollingLetters)
static void(__cdecl*original_InitRollingLetters)() = (void(__cdecl*)())0x004724d1;
CARM95_HOOK_FUNCTION(original_InitRollingLetters, InitRollingLetters)
void __cdecl InitRollingLetters() {
    int i;
    LOG_TRACE("()");

    (void)i;

    if (function_hook_state_InitRollingLetters == HOOK_ENABLED) {
        assert(0 && "InitRollingLetters not implemented.");
        abort();
    } else {
        original_InitRollingLetters();
    }
}

function_hook_state_t function_hook_state_EndRollingLetters = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(EndRollingLetters, function_hook_state_EndRollingLetters)
static void(__cdecl*original_EndRollingLetters)() = (void(__cdecl*)())0x00472543;
CARM95_HOOK_FUNCTION(original_EndRollingLetters, EndRollingLetters)
void __cdecl EndRollingLetters() {
    LOG_TRACE("()");


    if (function_hook_state_EndRollingLetters == HOOK_ENABLED) {
        assert(0 && "EndRollingLetters not implemented.");
        abort();
    } else {
        original_EndRollingLetters();
    }
}

function_hook_state_t function_hook_state_AddRollingLetter = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(AddRollingLetter, function_hook_state_AddRollingLetter)
static int(__cdecl*original_AddRollingLetter)(char, int, int, tRolling_type) = (int(__cdecl*)(char, int, int, tRolling_type))0x0047255c;
CARM95_HOOK_FUNCTION(original_AddRollingLetter, AddRollingLetter)
int __cdecl AddRollingLetter(char pChar, int pX, int pY, tRolling_type rolling_type) {
    tRolling_letter *let;
    int i;
    int number_of_letters;
    LOG_TRACE("('%c', %d, %d, %d)", pChar, pX, pY, rolling_type);

    (void)pChar;
    (void)pX;
    (void)pY;
    (void)rolling_type;
    (void)let;
    (void)i;
    (void)number_of_letters;

    if (function_hook_state_AddRollingLetter == HOOK_ENABLED) {
        assert(0 && "AddRollingLetter not implemented.");
        abort();
    } else {
        return original_AddRollingLetter(pChar, pX, pY, rolling_type);
    }
}

function_hook_state_t function_hook_state_AddRollingString = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(AddRollingString, function_hook_state_AddRollingString)
static void(__cdecl*original_AddRollingString)(char *, int, int, tRolling_type) = (void(__cdecl*)(char *, int, int, tRolling_type))0x004726c3;
CARM95_HOOK_FUNCTION(original_AddRollingString, AddRollingString)
void __cdecl AddRollingString(char *pStr, int pX, int pY, tRolling_type rolling_type) {
    int i;
    LOG_TRACE("(\"%s\", %d, %d, %d)", pStr, pX, pY, rolling_type);

    (void)pStr;
    (void)pX;
    (void)pY;
    (void)rolling_type;
    (void)i;

    if (function_hook_state_AddRollingString == HOOK_ENABLED) {
        assert(0 && "AddRollingString not implemented.");
        abort();
    } else {
        original_AddRollingString(pStr, pX, pY, rolling_type);
    }
}

function_hook_state_t function_hook_state_AddRollingNumber = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(AddRollingNumber, function_hook_state_AddRollingNumber)
static void(__cdecl*original_AddRollingNumber)(tU32, int, int, int) = (void(__cdecl*)(tU32, int, int, int))0x00472729;
CARM95_HOOK_FUNCTION(original_AddRollingNumber, AddRollingNumber)
void __cdecl AddRollingNumber(tU32 pNumber, int pWidth, int pX, int pY) {
    char the_string[32];
    LOG_TRACE("(%u, %d, %d, %d)", pNumber, pWidth, pX, pY);

    (void)pNumber;
    (void)pWidth;
    (void)pX;
    (void)pY;
    (void)the_string;

    if (function_hook_state_AddRollingNumber == HOOK_ENABLED) {
        assert(0 && "AddRollingNumber not implemented.");
        abort();
    } else {
        original_AddRollingNumber(pNumber, pWidth, pX, pY);
    }
}

function_hook_state_t function_hook_state_RollLettersIn = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(RollLettersIn, function_hook_state_RollLettersIn)
static void(__cdecl*original_RollLettersIn)() = (void(__cdecl*)())0x00472766;
CARM95_HOOK_FUNCTION(original_RollLettersIn, RollLettersIn)
void __cdecl RollLettersIn() {
    tU32 new_time;
    tU32 period;
    tRolling_letter *let;
    int i;
    int j;
    int k;
    int offset;
    int which_letter;
    int font_width;
    int letter_offset;
    int font_height;
    int the_row_bytes;
    tU8 *char_ptr;
    tU8 *saved_char_ptr;
    tU8 *source_ptr;
    tU8 the_byte;
    LOG_TRACE("()");

    (void)new_time;
    (void)period;
    (void)let;
    (void)i;
    (void)j;
    (void)k;
    (void)offset;
    (void)which_letter;
    (void)font_width;
    (void)letter_offset;
    (void)font_height;
    (void)the_row_bytes;
    (void)char_ptr;
    (void)saved_char_ptr;
    (void)source_ptr;
    (void)the_byte;

    if (function_hook_state_RollLettersIn == HOOK_ENABLED) {
        assert(0 && "RollLettersIn not implemented.");
        abort();
    } else {
        original_RollLettersIn();
    }
}

function_hook_state_t function_hook_state_ChangeCharTo = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(ChangeCharTo, function_hook_state_ChangeCharTo)
static int(__cdecl*original_ChangeCharTo)(int, int, char) = (int(__cdecl*)(int, int, char))0x00472be8;
CARM95_HOOK_FUNCTION(original_ChangeCharTo, ChangeCharTo)
int __cdecl ChangeCharTo(int pSlot_index, int pChar_index, char pNew_char) {
    int x_coord;
    int y_coord;
    int i;
    int j;
    tRolling_letter *let;
    tRolling_type new_type;
    LOG_TRACE("(%d, %d, '%c')", pSlot_index, pChar_index, pNew_char);

    (void)pSlot_index;
    (void)pChar_index;
    (void)pNew_char;
    (void)x_coord;
    (void)y_coord;
    (void)i;
    (void)j;
    (void)let;
    (void)new_type;

    if (function_hook_state_ChangeCharTo == HOOK_ENABLED) {
        assert(0 && "ChangeCharTo not implemented.");
        abort();
    } else {
        return original_ChangeCharTo(pSlot_index, pChar_index, pNew_char);
    }
}

function_hook_state_t function_hook_state_ChangeTextTo = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(ChangeTextTo, function_hook_state_ChangeTextTo)
static void(__cdecl*original_ChangeTextTo)(int, int, char *, char *) = (void(__cdecl*)(int, int, char *, char *))0x004729df;
CARM95_HOOK_FUNCTION(original_ChangeTextTo, ChangeTextTo)
void __cdecl ChangeTextTo(int pXcoord, int pYcoord, char *pNew_str, char *pOld_str) {
    int x_coord;
    int i;
    int len;
    int len2;
    int j;
    tRolling_letter *let;
    tRolling_type new_type;
    char new_char;
    LOG_TRACE("(%d, %d, \"%s\", \"%s\")", pXcoord, pYcoord, pNew_str, pOld_str);

    (void)pXcoord;
    (void)pYcoord;
    (void)pNew_str;
    (void)pOld_str;
    (void)x_coord;
    (void)i;
    (void)len;
    (void)len2;
    (void)j;
    (void)let;
    (void)new_type;
    (void)new_char;

    if (function_hook_state_ChangeTextTo == HOOK_ENABLED) {
        assert(0 && "ChangeTextTo not implemented.");
        abort();
    } else {
        original_ChangeTextTo(pXcoord, pYcoord, pNew_str, pOld_str);
    }
}

function_hook_state_t function_hook_state_SetRollingCursor = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(SetRollingCursor, function_hook_state_SetRollingCursor)
static void(__cdecl*original_SetRollingCursor)(int) = (void(__cdecl*)(int))0x00472ea8;
CARM95_HOOK_FUNCTION(original_SetRollingCursor, SetRollingCursor)
void __cdecl SetRollingCursor(int pSlot_index) {
    LOG_TRACE("(%d)", pSlot_index);

    (void)pSlot_index;

    if (function_hook_state_SetRollingCursor == HOOK_ENABLED) {
        assert(0 && "SetRollingCursor not implemented.");
        abort();
    } else {
        original_SetRollingCursor(pSlot_index);
    }
}

function_hook_state_t function_hook_state_BlankSlot = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(BlankSlot, function_hook_state_BlankSlot)
static void(__cdecl*original_BlankSlot)(int, int, int) = (void(__cdecl*)(int, int, int))0x00472ba0;
CARM95_HOOK_FUNCTION(original_BlankSlot, BlankSlot)
void __cdecl BlankSlot(int pIndex, int pName_length, int pVisible_length) {
    int i;
    LOG_TRACE("(%d, %d, %d)", pIndex, pName_length, pVisible_length);

    (void)pIndex;
    (void)pName_length;
    (void)pVisible_length;
    (void)i;

    if (function_hook_state_BlankSlot == HOOK_ENABLED) {
        assert(0 && "BlankSlot not implemented.");
        abort();
    } else {
        original_BlankSlot(pIndex, pName_length, pVisible_length);
    }
}

function_hook_state_t function_hook_state_DoRLBackspace = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(DoRLBackspace, function_hook_state_DoRLBackspace)
static void(__cdecl*original_DoRLBackspace)(int) = (void(__cdecl*)(int))0x00472fb9;
CARM95_HOOK_FUNCTION(original_DoRLBackspace, DoRLBackspace)
void __cdecl DoRLBackspace(int pSlot_index) {
    int i;
    int new_len;
    LOG_TRACE("(%d)", pSlot_index);

    (void)pSlot_index;
    (void)i;
    (void)new_len;

    if (function_hook_state_DoRLBackspace == HOOK_ENABLED) {
        assert(0 && "DoRLBackspace not implemented.");
        abort();
    } else {
        original_DoRLBackspace(pSlot_index);
    }
}

function_hook_state_t function_hook_state_DoRLDelete = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(DoRLDelete, function_hook_state_DoRLDelete)
static void(__cdecl*original_DoRLDelete)(int) = (void(__cdecl*)(int))0x004730be;
CARM95_HOOK_FUNCTION(original_DoRLDelete, DoRLDelete)
void __cdecl DoRLDelete(int pSlot_index) {
    int i;
    int new_len;
    LOG_TRACE("(%d)", pSlot_index);

    (void)pSlot_index;
    (void)i;
    (void)new_len;

    if (function_hook_state_DoRLDelete == HOOK_ENABLED) {
        assert(0 && "DoRLDelete not implemented.");
        abort();
    } else {
        original_DoRLDelete(pSlot_index);
    }
}

function_hook_state_t function_hook_state_DoRLInsert = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(DoRLInsert, function_hook_state_DoRLInsert)
static void(__cdecl*original_DoRLInsert)(int) = (void(__cdecl*)(int))0x00473189;
CARM95_HOOK_FUNCTION(original_DoRLInsert, DoRLInsert)
void __cdecl DoRLInsert(int pSlot_index) {
    LOG_TRACE("(%d)", pSlot_index);

    (void)pSlot_index;

    if (function_hook_state_DoRLInsert == HOOK_ENABLED) {
        assert(0 && "DoRLInsert not implemented.");
        abort();
    } else {
        original_DoRLInsert(pSlot_index);
    }
}

function_hook_state_t function_hook_state_DoRLCursorLeft = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(DoRLCursorLeft, function_hook_state_DoRLCursorLeft)
static void(__cdecl*original_DoRLCursorLeft)(int) = (void(__cdecl*)(int))0x004731ba;
CARM95_HOOK_FUNCTION(original_DoRLCursorLeft, DoRLCursorLeft)
void __cdecl DoRLCursorLeft(int pSlot_index) {
    LOG_TRACE("(%d)", pSlot_index);

    (void)pSlot_index;

    if (function_hook_state_DoRLCursorLeft == HOOK_ENABLED) {
        assert(0 && "DoRLCursorLeft not implemented.");
        abort();
    } else {
        original_DoRLCursorLeft(pSlot_index);
    }
}

function_hook_state_t function_hook_state_DoRLCursorRight = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(DoRLCursorRight, function_hook_state_DoRLCursorRight)
static void(__cdecl*original_DoRLCursorRight)(int) = (void(__cdecl*)(int))0x00473248;
CARM95_HOOK_FUNCTION(original_DoRLCursorRight, DoRLCursorRight)
void __cdecl DoRLCursorRight(int pSlot_index) {
    LOG_TRACE("(%d)", pSlot_index);

    (void)pSlot_index;

    if (function_hook_state_DoRLCursorRight == HOOK_ENABLED) {
        assert(0 && "DoRLCursorRight not implemented.");
        abort();
    } else {
        original_DoRLCursorRight(pSlot_index);
    }
}

function_hook_state_t function_hook_state_DoRLTypeLetter = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(DoRLTypeLetter, function_hook_state_DoRLTypeLetter)
static void(__cdecl*original_DoRLTypeLetter)(int, int) = (void(__cdecl*)(int, int))0x004732a2;
CARM95_HOOK_FUNCTION(original_DoRLTypeLetter, DoRLTypeLetter)
void __cdecl DoRLTypeLetter(int pChar, int pSlot_index) {
    int i;
    int new_len;
    LOG_TRACE("(%d, %d)", pChar, pSlot_index);

    (void)pChar;
    (void)pSlot_index;
    (void)i;
    (void)new_len;

    if (function_hook_state_DoRLTypeLetter == HOOK_ENABLED) {
        assert(0 && "DoRLTypeLetter not implemented.");
        abort();
    } else {
        original_DoRLTypeLetter(pChar, pSlot_index);
    }
}

function_hook_state_t function_hook_state_StopTyping = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(StopTyping, function_hook_state_StopTyping)
static void(__cdecl*original_StopTyping)(int) = (void(__cdecl*)(int))0x00472d51;
CARM95_HOOK_FUNCTION(original_StopTyping, StopTyping)
void __cdecl StopTyping(int pSlot_index) {
    int i;
    LOG_TRACE("(%d)", pSlot_index);

    (void)pSlot_index;
    (void)i;

    if (function_hook_state_StopTyping == HOOK_ENABLED) {
        assert(0 && "StopTyping not implemented.");
        abort();
    } else {
        original_StopTyping(pSlot_index);
    }
}

function_hook_state_t function_hook_state_RevertTyping = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(RevertTyping, function_hook_state_RevertTyping)
static void(__cdecl*original_RevertTyping)(int, char *) = (void(__cdecl*)(int, char *))0x00472dca;
CARM95_HOOK_FUNCTION(original_RevertTyping, RevertTyping)
void __cdecl RevertTyping(int pSlot_index, char *pRevert_str) {
    int i;
    LOG_TRACE("(%d, \"%s\")", pSlot_index, pRevert_str);

    (void)pSlot_index;
    (void)pRevert_str;
    (void)i;

    if (function_hook_state_RevertTyping == HOOK_ENABLED) {
        assert(0 && "RevertTyping not implemented.");
        abort();
    } else {
        original_RevertTyping(pSlot_index, pRevert_str);
    }
}

function_hook_state_t function_hook_state_StartTyping = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(StartTyping, function_hook_state_StartTyping)
static void(__cdecl*original_StartTyping)(int, char *, int) = (void(__cdecl*)(int, char *, int))0x00472e42;
CARM95_HOOK_FUNCTION(original_StartTyping, StartTyping)
void __cdecl StartTyping(int pSlot_index, char *pText, int pVisible_length) {
    LOG_TRACE("(%d, \"%s\", %d)", pSlot_index, pText, pVisible_length);

    (void)pSlot_index;
    (void)pText;
    (void)pVisible_length;

    if (function_hook_state_StartTyping == HOOK_ENABLED) {
        assert(0 && "StartTyping not implemented.");
        abort();
    } else {
        original_StartTyping(pSlot_index, pText, pVisible_length);
    }
}

function_hook_state_t function_hook_state_TypeKey = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(TypeKey, function_hook_state_TypeKey)
static void(__cdecl*original_TypeKey)(int, char) = (void(__cdecl*)(int, char))0x00472ecc;
CARM95_HOOK_FUNCTION(original_TypeKey, TypeKey)
void __cdecl TypeKey(int pSlot_index, char pKey) {
    LOG_TRACE("(%d, '%c')", pSlot_index, pKey);

    (void)pSlot_index;
    (void)pKey;

    if (function_hook_state_TypeKey == HOOK_ENABLED) {
        assert(0 && "TypeKey not implemented.");
        abort();
    } else {
        original_TypeKey(pSlot_index, pKey);
    }
}

function_hook_state_t function_hook_state_SetSlotXY = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(SetSlotXY, function_hook_state_SetSlotXY)
static void(__cdecl*original_SetSlotXY)(int, int, int) = (void(__cdecl*)(int, int, int))0x0047340f;
CARM95_HOOK_FUNCTION(original_SetSlotXY, SetSlotXY)
void __cdecl SetSlotXY(int pSlot_index, int pX_coord, int pY_coord) {
    LOG_TRACE("(%d, %d, %d)", pSlot_index, pX_coord, pY_coord);

    (void)pSlot_index;
    (void)pX_coord;
    (void)pY_coord;

    if (function_hook_state_SetSlotXY == HOOK_ENABLED) {
        assert(0 && "SetSlotXY not implemented.");
        abort();
    } else {
        original_SetSlotXY(pSlot_index, pX_coord, pY_coord);
    }
}

function_hook_state_t function_hook_state_GetTypedName = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(GetTypedName, function_hook_state_GetTypedName)
static void(__cdecl*original_GetTypedName)(char *, int) = (void(__cdecl*)(char *, int))0x00473434;
CARM95_HOOK_FUNCTION(original_GetTypedName, GetTypedName)
void __cdecl GetTypedName(char *pDestn, int pMax_length) {
    LOG_TRACE("(\"%s\", %d)", pDestn, pMax_length);

    (void)pDestn;
    (void)pMax_length;

    if (function_hook_state_GetTypedName == HOOK_ENABLED) {
        assert(0 && "GetTypedName not implemented.");
        abort();
    } else {
        original_GetTypedName(pDestn, pMax_length);
    }
}

function_hook_state_t function_hook_state_KillCursor = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(KillCursor, function_hook_state_KillCursor)
static void(__cdecl*original_KillCursor)(int) = (void(__cdecl*)(int))0x004734aa;
CARM95_HOOK_FUNCTION(original_KillCursor, KillCursor)
void __cdecl KillCursor(int pSlot_index) {
    int x_coord;
    int y_coord;
    int i;
    int j;
    tRolling_letter *let;
    tRolling_type new_type;
    LOG_TRACE("(%d)", pSlot_index);

    (void)pSlot_index;
    (void)x_coord;
    (void)y_coord;
    (void)i;
    (void)j;
    (void)let;
    (void)new_type;

    if (function_hook_state_KillCursor == HOOK_ENABLED) {
        assert(0 && "KillCursor not implemented.");
        abort();
    } else {
        original_KillCursor(pSlot_index);
    }
}

function_hook_state_t function_hook_state_EdgeTriggerModeOn = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(EdgeTriggerModeOn, function_hook_state_EdgeTriggerModeOn)
static void(__cdecl*original_EdgeTriggerModeOn)() = (void(__cdecl*)())0x00473577;
CARM95_HOOK_FUNCTION(original_EdgeTriggerModeOn, EdgeTriggerModeOn)
void __cdecl EdgeTriggerModeOn() {
    LOG_TRACE("()");


    if (function_hook_state_EdgeTriggerModeOn == HOOK_ENABLED) {
        assert(0 && "EdgeTriggerModeOn not implemented.");
        abort();
    } else {
        original_EdgeTriggerModeOn();
    }
}

function_hook_state_t function_hook_state_EdgeTriggerModeOff = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(EdgeTriggerModeOff, function_hook_state_EdgeTriggerModeOff)
static void(__cdecl*original_EdgeTriggerModeOff)() = (void(__cdecl*)())0x0047358c;
CARM95_HOOK_FUNCTION(original_EdgeTriggerModeOff, EdgeTriggerModeOff)
void __cdecl EdgeTriggerModeOff() {
    LOG_TRACE("()");


    if (function_hook_state_EdgeTriggerModeOff == HOOK_ENABLED) {
        assert(0 && "EdgeTriggerModeOff not implemented.");
        abort();
    } else {
        original_EdgeTriggerModeOff();
    }
}

