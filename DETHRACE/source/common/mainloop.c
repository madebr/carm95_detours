#include "mainloop.h"

#include "harness/trace.h"

#include "carm95_hooks.h"

#include "carm95_webserver.h"

#include <assert.h>
int * hookvar_gNasty_kludgey_cockpit_variable  = (void*)0x00514afc;
tInfo_mode * hookvar_gInfo_mode  = (void*)0x00514b00;
tU32 * hookvar_gLast_tick_count  = (void*)0x00514b04;
tU32 * hookvar_gActual_last_tick_count  = (void*)0x00514b08;
#if 0
tU32 * hookvar_gAverage_frame_period ;
#endif
tU32 * hookvar_gOld_camera_time  = (void*)0x0053a1a8;
tU32 * hookvar_gLast_wasted_massage_start  = (void*)0x0053a118;
float * hookvar_gMr_odo  = (void*)0x0053a114;
tU32 * hookvar_gWasted_last_flash  = (void*)0x0053a0e8;
tTime_bonus_state * hookvar_gTime_bonus_state  = (void*)0x0053a120;
int * hookvar_gQueued_wasted_massages_count  = (void*)0x0053a104;
int * hookvar_gTime_bonus  = (void*)0x0053a11c;
int * hookvar_gRace_bonus_headup  = (void*)0x0053a1a4;
int * hookvar_gWasted_flash_state  = (void*)0x0053a10c;
int * hookvar_gLast_time_headup  = (void*)0x0053a110;
int * hookvar_gTime_bonus_headup  = (void*)0x0053a1a0;
int(* hookvar_gQueued_wasted_massages )[5] = (void*)0x0053a0f0;
tU32 * hookvar_gTime_bonus_start  = (void*)0x0053a124;
 // Suffix added to avoid duplicate symbol
int * hookvar_gLast_credit_headup__mainloop  = (void*)0x0053a108;

function_hook_state_t function_hook_state_ToggleInfo = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_ToggleInfo)
static void(__cdecl*original_ToggleInfo)() = (void(__cdecl*)())0x0046fd00;
CARM95_HOOK_FUNCTION(original_ToggleInfo, ToggleInfo)
void __cdecl ToggleInfo() {
    LOG_TRACE("()");


    if (function_hook_state_ToggleInfo == HOOK_ENABLED) {
        assert(0 && "ToggleInfo not implemented.");
        abort();
    } else {
        original_ToggleInfo();
    }
}

function_hook_state_t function_hook_state_CalculateFrameRate = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_CalculateFrameRate)
static void(__cdecl*original_CalculateFrameRate)() = (void(__cdecl*)())0x004706fa;
CARM95_HOOK_FUNCTION(original_CalculateFrameRate, CalculateFrameRate)
void __cdecl CalculateFrameRate() {
    static tU32 last_time;
    tU32 new_time;
    static int last_rates[30];
    int new_rate;
    int i;
    LOG_TRACE("()");

    (void)last_time;
    (void)new_time;
    (void)last_rates;
    (void)new_rate;
    (void)i;

    if (function_hook_state_CalculateFrameRate == HOOK_ENABLED) {
        assert(0 && "CalculateFrameRate not implemented.");
        abort();
    } else {
        original_CalculateFrameRate();
    }
}

function_hook_state_t function_hook_state_LoseOldestWastedMassage = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_LoseOldestWastedMassage)
static void(__cdecl*original_LoseOldestWastedMassage)() = (void(__cdecl*)())0x0046fde6;
CARM95_HOOK_FUNCTION(original_LoseOldestWastedMassage, LoseOldestWastedMassage)
void __cdecl LoseOldestWastedMassage() {
    int i;
    LOG_TRACE("()");

    (void)i;

    if (function_hook_state_LoseOldestWastedMassage == HOOK_ENABLED) {
        assert(0 && "LoseOldestWastedMassage not implemented.");
        abort();
    } else {
        original_LoseOldestWastedMassage();
    }
}

function_hook_state_t function_hook_state_QueueWastedMassage = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_QueueWastedMassage)
static void(__cdecl*original_QueueWastedMassage)(int) = (void(__cdecl*)(int))0x0046fd9c;
CARM95_HOOK_FUNCTION(original_QueueWastedMassage, QueueWastedMassage)
void __cdecl QueueWastedMassage(int pIndex) {
    LOG_TRACE("(%d)", pIndex);

    (void)pIndex;

    if (function_hook_state_QueueWastedMassage == HOOK_ENABLED) {
        assert(0 && "QueueWastedMassage not implemented.");
        abort();
    } else {
        original_QueueWastedMassage(pIndex);
    }
}

function_hook_state_t function_hook_state_MungeHeadups = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_MungeHeadups)
static void(__cdecl*original_MungeHeadups)() = (void(__cdecl*)())0x004707bd;
CARM95_HOOK_FUNCTION(original_MungeHeadups, MungeHeadups)
void __cdecl MungeHeadups() {
    char the_text[256];
    int flash_rate;
    int new_countdown;
    int net_credits;
    int previous_gtimer;
    int previous_time_bonus;
    int effective_timer;
    int bonus;
    int oppo_count;
    tU32 the_time;
    float bearing;
    br_material *nearby;
    tPixelmap_user_data *user;
    static tU32 last_rattle_time;
    LOG_TRACE("()");

    (void)the_text;
    (void)flash_rate;
    (void)new_countdown;
    (void)net_credits;
    (void)previous_gtimer;
    (void)previous_time_bonus;
    (void)effective_timer;
    (void)bonus;
    (void)oppo_count;
    (void)the_time;
    (void)bearing;
    (void)nearby;
    (void)user;
    (void)last_rattle_time;

    if (function_hook_state_MungeHeadups == HOOK_ENABLED) {
        assert(0 && "MungeHeadups not implemented.");
        abort();
    } else {
        original_MungeHeadups();
    }
}

function_hook_state_t function_hook_state_UpdateFramePeriod = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_UpdateFramePeriod)
static void(__cdecl*original_UpdateFramePeriod)(tU32 *) = (void(__cdecl*)(tU32 *))0x004712bd;
CARM95_HOOK_FUNCTION(original_UpdateFramePeriod, UpdateFramePeriod)
void __cdecl UpdateFramePeriod(tU32 *pCamera_period) {
    tU32 new_tick_count;
    tU32 new_camera_tick_count;
    int error;
    static int last_AR_mode;
    LOG_TRACE("(%p)", pCamera_period);

    (void)pCamera_period;
    (void)new_tick_count;
    (void)new_camera_tick_count;
    (void)error;
    (void)last_AR_mode;

    if (function_hook_state_UpdateFramePeriod == HOOK_ENABLED) {
        assert(0 && "UpdateFramePeriod not implemented.");
        abort();
    } else {
        original_UpdateFramePeriod(pCamera_period);
    }
}

function_hook_state_t function_hook_state_GetLastTickCount = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_GetLastTickCount)
static tU32(__cdecl*original_GetLastTickCount)() = (tU32(__cdecl*)())0x0046fe3a;
CARM95_HOOK_FUNCTION(original_GetLastTickCount, GetLastTickCount)
tU32 __cdecl GetLastTickCount() {
    LOG_TRACE("()");


    if (function_hook_state_GetLastTickCount == HOOK_ENABLED) {
        assert(0 && "GetLastTickCount not implemented.");
        abort();
    } else {
        return original_GetLastTickCount();
    }
}

function_hook_state_t function_hook_state_CheckTimer = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_CheckTimer)
static void(__cdecl*original_CheckTimer)() = (void(__cdecl*)())0x00471543;
CARM95_HOOK_FUNCTION(original_CheckTimer, CheckTimer)
void __cdecl CheckTimer() {
    tS32 time_in_seconds;
    tS32 time_left;
    static tU32 last_time_in_seconds;
    static tU32 last_demo_time_in_seconds;
    LOG_TRACE("()");

    (void)time_in_seconds;
    (void)time_left;
    (void)last_time_in_seconds;
    (void)last_demo_time_in_seconds;

    if (function_hook_state_CheckTimer == HOOK_ENABLED) {
        assert(0 && "CheckTimer not implemented.");
        abort();
    } else {
        original_CheckTimer();
    }
}

function_hook_state_t function_hook_state_MungeRaceFinished = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_MungeRaceFinished)
static int(__cdecl*original_MungeRaceFinished)() = (int(__cdecl*)())0x00471607;
CARM95_HOOK_FUNCTION(original_MungeRaceFinished, MungeRaceFinished)
int __cdecl MungeRaceFinished() {
    LOG_TRACE("()");


    if (function_hook_state_MungeRaceFinished == HOOK_ENABLED) {
        assert(0 && "MungeRaceFinished not implemented.");
        abort();
    } else {
        return original_MungeRaceFinished();
    }
}

function_hook_state_t function_hook_state_MainGameLoop = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_MainGameLoop)
static tRace_result(__cdecl*original_MainGameLoop)() = (tRace_result(__cdecl*)())0x0046fe77;
CARM95_HOOK_FUNCTION(original_MainGameLoop, MainGameLoop)
tRace_result __cdecl MainGameLoop() {
    tU32 camera_period;
    tU32 start_menu_time;
    tU32 frame_start_time;
    tRace_result result;
    int tried_to_allocate_AR;
    int i;
    int bonus;
    LOG_TRACE("()");

    (void)camera_period;
    (void)start_menu_time;
    (void)frame_start_time;
    (void)result;
    (void)tried_to_allocate_AR;
    (void)i;
    (void)bonus;

    if (function_hook_state_MainGameLoop == HOOK_ENABLED) {
        assert(0 && "MainGameLoop not implemented.");
        abort();
    } else {
        return original_MainGameLoop();
    }
}

function_hook_state_t function_hook_state_DoRace = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_DoRace)
static tRace_result(__cdecl*original_DoRace)() = (tRace_result(__cdecl*)())0x0046fe4f;
CARM95_HOOK_FUNCTION(original_DoRace, DoRace)
tRace_result __cdecl DoRace() {
    tRace_result result;
    LOG_TRACE("()");

    (void)result;

    if (function_hook_state_DoRace == HOOK_ENABLED) {
        assert(0 && "DoRace not implemented.");
        abort();
    } else {
        return original_DoRace();
    }
}

