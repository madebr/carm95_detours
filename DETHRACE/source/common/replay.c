#include "replay.h"

#include "harness/trace.h"

#include "carm95_hooks.h"

char *(* hookvar_gReplay_pixie_names )[10] = (void*)0x0050a1b0;
int * hookvar_gSingle_frame_mode  = (void*)0x0050a1d8;
tU32 * hookvar_gCam_change_time  = (void*)0x0050a1dc;
int * hookvar_gSave_file  = (void*)0x0050a1e0;
int(* hookvar_gProgress_line_left )[2] = (void*)0x0050a1e8;
int(* hookvar_gProgress_line_right )[2] = (void*)0x0050a1f0;
int(* hookvar_gProgress_line_top )[2] = (void*)0x0050a1f8;
br_pixelmap *(* hookvar_gReplay_pixies )[10] = (void*)0x00531dd0;
int * hookvar_gKey_down  = (void*)0x00531db8;
#if 0
int * hookvar_gNo_cursor ;
#endif
int * hookvar_gSave_frame_number  = (void*)0x00531db4;
int * hookvar_gCam_change_button_down  = (void*)0x00531da8;
tU32 * hookvar_gAction_replay_start_time  = (void*)0x00531da0;
tU32 * hookvar_gLast_replay_zappy_screen  = (void*)0x00531dc4;
tS32 * hookvar_gStopped_time  = (void*)0x00531dc0;
float * hookvar_gPending_replay_rate  = (void*)0x00531dbc;
tU32 * hookvar_gAction_replay_end_time  = (void*)0x00531da4;
float * hookvar_gReplay_rate  = (void*)0x00531dcc;
int * hookvar_gSave_bunch_ID  = (void*)0x00531db0;
int * hookvar_gPlay_direction  = (void*)0x00531dac;
int * hookvar_gPaused  = (void*)0x00531dc8;
tAction_replay_camera_type * hookvar_gAction_replay_camera_mode  = (void*)0x00551db4;

static int(__cdecl*original_ReplayIsPaused)() = (int(__cdecl*)())0x0041adc0;
CARM95_HOOK_FUNCTION(original_ReplayIsPaused, ReplayIsPaused)
int __cdecl ReplayIsPaused() {
    LOG_TRACE("()");


    return original_ReplayIsPaused();
}

static float(__cdecl*original_GetReplayRate)() = (float(__cdecl*)())0x0041adf3;
CARM95_HOOK_FUNCTION(original_GetReplayRate, GetReplayRate)
float __cdecl GetReplayRate() {
    LOG_TRACE("()");


    return original_GetReplayRate();
}

static int(__stdcall*original_GetReplayDirection)() = (int(__stdcall*)())0x0041ae09;
CARM95_HOOK_FUNCTION(original_GetReplayDirection, GetReplayDirection)
int __stdcall GetReplayDirection() {
    LOG_TRACE("()");


    return original_GetReplayDirection();
}

static void(__cdecl*original_StopSaving)() = (void(__cdecl*)())0x0041b5a0;
CARM95_HOOK_FUNCTION(original_StopSaving, StopSaving)
void __cdecl StopSaving() {
    LOG_TRACE("()");


    original_StopSaving();
}

static void(__cdecl*original_ActualActionReplayHeadups)(int) = (void(__cdecl*)(int))0x0041ae48;
CARM95_HOOK_FUNCTION(original_ActualActionReplayHeadups, ActualActionReplayHeadups)
void __cdecl ActualActionReplayHeadups(int pSpecial_zappy_bastard) {
    tU32 the_time;
    int x;
    tU16 played_col1;
    tU16 played_col2;
    tU16 to_play_col1;
    tU16 to_play_col2;
    LOG_TRACE("(%d)", pSpecial_zappy_bastard);

    (void)pSpecial_zappy_bastard;
    (void)the_time;
    (void)x;
    (void)played_col1;
    (void)played_col2;
    (void)to_play_col1;
    (void)to_play_col2;

    original_ActualActionReplayHeadups(pSpecial_zappy_bastard);
}

static void(__cdecl*original_DoActionReplayPostSwap)() = (void(__cdecl*)())0x0041ae1e;
CARM95_HOOK_FUNCTION(original_DoActionReplayPostSwap, DoActionReplayPostSwap)
void __cdecl DoActionReplayPostSwap() {
    LOG_TRACE("()");


    original_DoActionReplayPostSwap();
}

static void(__cdecl*original_DoZappyActionReplayHeadups)(int) = (void(__cdecl*)(int))0x0041b5bf;
CARM95_HOOK_FUNCTION(original_DoZappyActionReplayHeadups, DoZappyActionReplayHeadups)
void __cdecl DoZappyActionReplayHeadups(int pSpecial_zappy_bastard) {
    tU32 the_time;
    LOG_TRACE("(%d)", pSpecial_zappy_bastard);

    (void)pSpecial_zappy_bastard;
    (void)the_time;

    original_DoZappyActionReplayHeadups(pSpecial_zappy_bastard);
}

static void(__cdecl*original_DoActionReplayHeadups)() = (void(__cdecl*)())0x0041ae33;
CARM95_HOOK_FUNCTION(original_DoActionReplayHeadups, DoActionReplayHeadups)
void __cdecl DoActionReplayHeadups() {
    LOG_TRACE("()");


    original_DoActionReplayHeadups();
}

static void(__cdecl*original_MoveReplayBuffer)(tS32) = (void(__cdecl*)(tS32))0x0041b41e;
CARM95_HOOK_FUNCTION(original_MoveReplayBuffer, MoveReplayBuffer)
void __cdecl MoveReplayBuffer(tS32 pMove_amount) {
    tU8 *play_ptr;
    tU8 *old_play_ptr;
    tU8 *old_play_ptr2;
    int i;
    int a;
    tU32 old_time;
    LOG_TRACE("(%d)", pMove_amount);

    (void)pMove_amount;
    (void)play_ptr;
    (void)old_play_ptr;
    (void)old_play_ptr2;
    (void)i;
    (void)a;
    (void)old_time;

    original_MoveReplayBuffer(pMove_amount);
}

static void(__cdecl*original_MoveToEndOfReplay)() = (void(__cdecl*)())0x0041b3df;
CARM95_HOOK_FUNCTION(original_MoveToEndOfReplay, MoveToEndOfReplay)
void __cdecl MoveToEndOfReplay() {
    float old_replay_rate;
    LOG_TRACE("()");

    (void)old_replay_rate;

    original_MoveToEndOfReplay();
}

static void(__cdecl*original_MoveToStartOfReplay)() = (void(__cdecl*)())0x0041b622;
CARM95_HOOK_FUNCTION(original_MoveToStartOfReplay, MoveToStartOfReplay)
void __cdecl MoveToStartOfReplay() {
    float old_replay_rate;
    LOG_TRACE("()");

    (void)old_replay_rate;

    original_MoveToStartOfReplay();
}

static void(__cdecl*original_ToggleReplay)() = (void(__cdecl*)())0x0041b661;
CARM95_HOOK_FUNCTION(original_ToggleReplay, ToggleReplay)
void __cdecl ToggleReplay() {
    LOG_TRACE("()");


    original_ToggleReplay();
}

static void(__cdecl*original_ReverseSound)(tS3_effect_tag, tS3_sound_tag) = (void(__cdecl*)(tS3_effect_tag, tS3_sound_tag))0x0041b7fe;
CARM95_HOOK_FUNCTION(original_ReverseSound, ReverseSound)
void __cdecl ReverseSound(tS3_effect_tag pEffect_index, tS3_sound_tag pSound_tag) {
    LOG_TRACE("(%d, %d)", pEffect_index, pSound_tag);

    (void)pEffect_index;
    (void)pSound_tag;

    original_ReverseSound(pEffect_index, pSound_tag);
}

static int(__cdecl*original_FindUniqueFile)() = (int(__cdecl*)())0x0041b819;
CARM95_HOOK_FUNCTION(original_FindUniqueFile, FindUniqueFile)
int __cdecl FindUniqueFile() {
    int index;
    FILE *f;
    tPath_name the_path;
    LOG_TRACE("()");

    (void)index;
    (void)f;
    (void)the_path;

    return original_FindUniqueFile();
}

static void(__cdecl*original_PollActionReplayControls)(tU32) = (void(__cdecl*)(tU32))0x0041b925;
CARM95_HOOK_FUNCTION(original_PollActionReplayControls, PollActionReplayControls)
void __cdecl PollActionReplayControls(tU32 pFrame_period) {
    float old_replay_rate;
    int old_key_down;
    int x_coord;
    int y_coord;
    int i;
    tU32 real_time;
    static tU32 last_real_time;
    static int psuedo_mouse_keys[8];
    static tRectangle mouse_areas[2][8];
    LOG_TRACE("(%u)", pFrame_period);

    (void)pFrame_period;
    (void)old_replay_rate;
    (void)old_key_down;
    (void)x_coord;
    (void)y_coord;
    (void)i;
    (void)real_time;
    (void)last_real_time;
    (void)psuedo_mouse_keys;
    (void)mouse_areas;

    original_PollActionReplayControls(pFrame_period);
}

static void(__cdecl*original_CheckReplayTurnOn)() = (void(__cdecl*)())0x0041c03b;
CARM95_HOOK_FUNCTION(original_CheckReplayTurnOn, CheckReplayTurnOn)
void __cdecl CheckReplayTurnOn() {
    LOG_TRACE("()");


    original_CheckReplayTurnOn();
}

static void(__cdecl*original_InitializeActionReplay)() = (void(__cdecl*)())0x0041c093;
CARM95_HOOK_FUNCTION(original_InitializeActionReplay, InitializeActionReplay)
void __cdecl InitializeActionReplay() {
    int i;
    LOG_TRACE("()");

    (void)i;

    original_InitializeActionReplay();
}

static void(__cdecl*original_DoActionReplay)(tU32) = (void(__cdecl*)(tU32))0x0041c0e6;
CARM95_HOOK_FUNCTION(original_DoActionReplay, DoActionReplay)
void __cdecl DoActionReplay(tU32 pFrame_period) {
    LOG_TRACE("(%u)", pFrame_period);

    (void)pFrame_period;

    original_DoActionReplay(pFrame_period);
}

static void(__cdecl*original_SynchronizeActionReplay)() = (void(__cdecl*)())0x0041c11c;
CARM95_HOOK_FUNCTION(original_SynchronizeActionReplay, SynchronizeActionReplay)
void __cdecl SynchronizeActionReplay() {
    FILE *f;
    tPath_name the_path;
    static tU32 gLast_synch_time;
    LOG_TRACE("()");

    (void)f;
    (void)the_path;
    (void)gLast_synch_time;

    original_SynchronizeActionReplay();
}

