#include "replay.h"

#include "car.h"
#include "controls.h"
#include "displays.h"
#include "globvars.h"
#include "globvrpb.h"
#include "grafdata.h"
#include "graphics.h"
#include "input.h"
#include "loading.h"
#include "netgame.h"
#include "oil.h"
#include "opponent.h"
#include "main.h"
#include "piping.h"
#include "pc-dos/dossys.h"
#include "utility.h"
#include "world.h"

#include "harness/trace.h"

#include "carm95_hooks.h"

#include "carm95_webserver.h"

#include <assert.h>
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

function_hook_state_t function_hook_state_ReplayIsPaused = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(function_hook_state_ReplayIsPaused)
static int(__cdecl*original_ReplayIsPaused)() = (int(__cdecl*)())0x0041adc0;
CARM95_HOOK_FUNCTION(original_ReplayIsPaused, ReplayIsPaused)
int __cdecl ReplayIsPaused() {
    LOG_TRACE("()");


    if (function_hook_state_ReplayIsPaused == HOOK_ENABLED) {
        return HV(gReplay_rate) == 0.f;
    } else {
        return original_ReplayIsPaused();
    }
}

function_hook_state_t function_hook_state_GetReplayRate = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(function_hook_state_GetReplayRate)
static float(__cdecl*original_GetReplayRate)() = (float(__cdecl*)())0x0041adf3;
CARM95_HOOK_FUNCTION(original_GetReplayRate, GetReplayRate)
float __cdecl GetReplayRate() {
    LOG_TRACE("()");


    if (function_hook_state_GetReplayRate == HOOK_ENABLED) {
        return HV(gReplay_rate);
    } else {
        return original_GetReplayRate();
    }
}

function_hook_state_t function_hook_state_GetReplayDirection = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(function_hook_state_GetReplayDirection)
static int(__stdcall*original_GetReplayDirection)() = (int(__stdcall*)())0x0041ae09;
CARM95_HOOK_FUNCTION(original_GetReplayDirection, GetReplayDirection)
int __stdcall GetReplayDirection() {
    LOG_TRACE("()");


    if (function_hook_state_GetReplayDirection == HOOK_ENABLED) {
        return HV(gPlay_direction);
    } else {
        return original_GetReplayDirection();
    }
}

function_hook_state_t function_hook_state_StopSaving = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(function_hook_state_StopSaving)
static void(__cdecl*original_StopSaving)() = (void(__cdecl*)())0x0041b5a0;
CARM95_HOOK_FUNCTION(original_StopSaving, StopSaving)
void __cdecl StopSaving() {
    LOG_TRACE("()");


    if (function_hook_state_StopSaving == HOOK_ENABLED) {
        HV(gSave_file) = 0;
        HV(gPaused) = 0;
    } else {
        original_StopSaving();
    }
}

function_hook_state_t function_hook_state_ActualActionReplayHeadups = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(function_hook_state_ActualActionReplayHeadups)
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

    if (function_hook_state_ActualActionReplayHeadups == HOOK_ENABLED) {
        the_time     = PDGetTotalTime();
        if (HV(gSave_file) || PDKeyDown(KEY_SHIFT_ANY)) {
            return;
        }
        if ((the_time / 400) % 2) {
            DRMaskedStamp(HV(gCurrent_graf_data)->action_replay_R_x,
                          HV(gCurrent_graf_data)->action_replay_R_y,
                          HV(gReplay_pixies)[0]);
        }
        DRMaskedStamp(HV(gCurrent_graf_data)->action_replay_controls_x,
                      HV(gCurrent_graf_data)->action_replay_controls_y,
                      HV(gReplay_pixies)[1]);
        if (pSpecial_zappy_bastard < 0) {
            DRMaskedStamp(HV(gCurrent_graf_data)->action_replay_rew_start_x,
                          HV(gCurrent_graf_data)->action_replay_hilite_y,
                          HV(gReplay_pixies)[2]);
        } else if (pSpecial_zappy_bastard == 0) {
            if (HV(gReplay_rate) < -1.f) {
                DRMaskedStamp(HV(gCurrent_graf_data)->action_replay_rew_x,
                              HV(gCurrent_graf_data)->action_replay_hilite_y,
                              HV(gReplay_pixies)[3]);
            } else if (HV(gReplay_rate) > 1.f) {
                DRMaskedStamp(HV(gCurrent_graf_data)->action_replay_ffwd_x,
                              HV(gCurrent_graf_data)->action_replay_hilite_y,
                              HV(gReplay_pixies)[7]);
            } else if (HV(gReplay_rate) == 1.f) {
                DRMaskedStamp(HV(gCurrent_graf_data)->action_replay_play_x,
                              HV(gCurrent_graf_data)->action_replay_hilite_y,
                              HV(gReplay_pixies)[6]);
            } else if (HV(gReplay_rate) == -1.f) {
                DRMaskedStamp(HV(gCurrent_graf_data)->action_replay_rev_play_x,
                              HV(gCurrent_graf_data)->action_replay_hilite_y,
                              HV(gReplay_pixies)[4]);
            } else {
                DRMaskedStamp(HV(gCurrent_graf_data)->action_replay_pause_x,
                              HV(gCurrent_graf_data)->action_replay_hilite_y,
                              HV(gReplay_pixies)[5]);
            }
        } else {
            DRMaskedStamp(HV(gCurrent_graf_data)->action_replay_fwd_end_x,
                          HV(gCurrent_graf_data)->action_replay_hilite_y,
                          HV(gReplay_pixies)[8]);
        }

        x = HV(gProgress_line_left)[HV(gGraf_data_index)] + (float)(HV(gProgress_line_right)[HV(gGraf_data_index)] - HV(gProgress_line_left)[HV(gGraf_data_index)]) * (HV(gLast_replay_frame_time) - HV(gAction_replay_start_time)) / (HV(gAction_replay_end_time) - HV(gAction_replay_start_time));
        if (x > HV(gProgress_line_left)[HV(gGraf_data_index)]) {
            BrPixelmapLine(HV(gBack_screen),
                           HV(gProgress_line_left)[HV(gGraf_data_index)], HV(gProgress_line_top)[HV(gGraf_data_index)],
                           x - 1, HV(gProgress_line_top)[HV(gGraf_data_index)],
                           2);
            BrPixelmapLine(HV(gBack_screen),
                           HV(gProgress_line_left)[HV(gGraf_data_index)], HV(gProgress_line_top)[HV(gGraf_data_index)] + 1,
                           x - 1, HV(gProgress_line_top)[HV(gGraf_data_index)] + 1,
                           4);
            BrPixelmapLine(HV(gBack_screen),
                           HV(gProgress_line_left)[HV(gGraf_data_index)], HV(gProgress_line_top)[HV(gGraf_data_index)] + 2,
                           x - 1, HV(gProgress_line_top)[HV(gGraf_data_index)] + 2,
                           2);
        }
        if (x < HV(gProgress_line_right)[HV(gGraf_data_index)]) {
            BrPixelmapLine(HV(gBack_screen),
                           x, HV(gProgress_line_top)[HV(gGraf_data_index)],
                           HV(gProgress_line_right)[HV(gGraf_data_index)] - 1, HV(gProgress_line_top)[HV(gGraf_data_index)],
                           81);
            BrPixelmapLine(HV(gBack_screen),
                           x, HV(gProgress_line_top)[HV(gGraf_data_index)] + 1,
                           HV(gProgress_line_right)[HV(gGraf_data_index)] - 1, HV(gProgress_line_top)[HV(gGraf_data_index)] + 1,
                           82);
            BrPixelmapLine(HV(gBack_screen),
                           x, HV(gProgress_line_top)[HV(gGraf_data_index)] + 2,
                           HV(gProgress_line_right)[HV(gGraf_data_index)] - 1, HV(gProgress_line_top)[HV(gGraf_data_index)] + 2,
                           81);
        }
        BrPixelmapLine(HV(gBack_screen),
                       HV(gProgress_line_left)[HV(gGraf_data_index)] - 1, HV(gProgress_line_top)[HV(gGraf_data_index)],
                       HV(gProgress_line_left)[HV(gGraf_data_index)] - 1, HV(gProgress_line_top)[HV(gGraf_data_index)] + 2,
                       2);
        BrPixelmapLine(HV(gBack_screen),
                       HV(gProgress_line_right)[HV(gGraf_data_index)], HV(gProgress_line_top)[HV(gGraf_data_index)],
                       HV(gProgress_line_right)[HV(gGraf_data_index)], HV(gProgress_line_top)[HV(gGraf_data_index)] + 2,
                       81);
        if (HV(gCam_change_button_down)) {
            DRMaskedStamp(HV(gCurrent_graf_data)->action_replay_camera_x,
                          HV(gCurrent_graf_data)->action_replay_hilite_y,
                          HV(gReplay_pixies)[9]);
        }
        if (the_time - HV(gCam_change_time) < 2000) {
            TransDRPixelmapText(HV(gBack_screen),
                                HV(gCurrent_graf_data)->action_replay_cam_text_x - DRTextWidth(&HV(gFonts)[1], GetMiscString(HV(gAction_replay_camera_mode) ? 39 : 38)),
                                HV(gCurrent_graf_data)->action_replay_cam_text_y,
                                &HV(gFonts)[1],
                                GetMiscString(HV(gAction_replay_camera_mode) ? 39 : 38),
                                2 * HV(gCurrent_graf_data)->action_replay_cam_text_x);
        }
        TurnOnPaletteConversion();
        DoMouseCursor();
        TurnOffPaletteConversion();
    } else {
        original_ActualActionReplayHeadups(pSpecial_zappy_bastard);
    }
}

function_hook_state_t function_hook_state_DoActionReplayPostSwap = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(function_hook_state_DoActionReplayPostSwap)
static void(__cdecl*original_DoActionReplayPostSwap)() = (void(__cdecl*)())0x0041ae1e;
CARM95_HOOK_FUNCTION(original_DoActionReplayPostSwap, DoActionReplayPostSwap)
void __cdecl DoActionReplayPostSwap() {
    LOG_TRACE("()");


    if (function_hook_state_DoActionReplayPostSwap == HOOK_ENABLED) {
        RemoveTransientBitmaps(1);
    } else {
        original_DoActionReplayPostSwap();
    }
}

function_hook_state_t function_hook_state_DoZappyActionReplayHeadups = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(function_hook_state_DoZappyActionReplayHeadups)
static void(__cdecl*original_DoZappyActionReplayHeadups)(int) = (void(__cdecl*)(int))0x0041b5bf;
CARM95_HOOK_FUNCTION(original_DoZappyActionReplayHeadups, DoZappyActionReplayHeadups)
void __cdecl DoZappyActionReplayHeadups(int pSpecial_zappy_bastard) {
    tU32 the_time;
    LOG_TRACE("(%d)", pSpecial_zappy_bastard);

    (void)pSpecial_zappy_bastard;
    (void)the_time;

    if (function_hook_state_DoZappyActionReplayHeadups == HOOK_ENABLED) {
        the_time = PDGetTotalTime();
        // Draw screen every 50ms (when we are going fast)
        if (abs(pSpecial_zappy_bastard) > 10000 && the_time - HV(gLast_replay_zappy_screen) > 50) {
            ActualActionReplayHeadups(pSpecial_zappy_bastard);
            HV(gLast_replay_zappy_screen) = the_time;
            PDScreenBufferSwap(0);
            RemoveTransientBitmaps(1);
        }
    } else {
        original_DoZappyActionReplayHeadups(pSpecial_zappy_bastard);
    }
}

function_hook_state_t function_hook_state_DoActionReplayHeadups = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(function_hook_state_DoActionReplayHeadups)
static void(__cdecl*original_DoActionReplayHeadups)() = (void(__cdecl*)())0x0041ae33;
CARM95_HOOK_FUNCTION(original_DoActionReplayHeadups, DoActionReplayHeadups)
void __cdecl DoActionReplayHeadups() {
    LOG_TRACE("()");


    if (function_hook_state_DoActionReplayHeadups == HOOK_ENABLED) {
        ActualActionReplayHeadups(0);
    } else {
        original_DoActionReplayHeadups();
    }
}

function_hook_state_t function_hook_state_MoveReplayBuffer = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(function_hook_state_MoveReplayBuffer)
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

    if (function_hook_state_MoveReplayBuffer == HOOK_ENABLED) {
        old_play_ptr = NULL;
        HV(gLast_replay_zappy_screen) = 0;
        old_play_ptr2 = GetPipePlayPtr();
        play_ptr = old_play_ptr2;
        old_time = GetTotalTime();
        for (i = 0; i < abs(pMove_amount) && play_ptr != old_play_ptr; i++) {
            if (KeyIsDown(KEYMAP_ESCAPE)) {
                break;
            }
            if (SomeReplayLeft()) {
                PipingFrameReset();
            }
            old_play_ptr = play_ptr;
            if (pMove_amount >= 1) {
                while (!ApplyPipedSession(&play_ptr)) {
                    DoZappyActionReplayHeadups(pMove_amount);
                }
                SetPipePlayPtr(play_ptr);
            } else if (pMove_amount <= -1) {
                while (!UndoPipedSession(&play_ptr)) {
                    DoZappyActionReplayHeadups(pMove_amount);
                }
                SetPipePlayPtr(play_ptr);
            }
            ProcessOilSpills(HV(gFrame_period));
        }
        if (HV(gReplay_rate) < 0.f) {
            CheckSound((tPipe_chunk*)old_play_ptr2, old_time, GetTotalTime());
        }
        if (old_play_ptr == play_ptr) {
            HV(gReplay_rate) = 0.f;
            HV(gPaused) = 1;
            StopSaving();
        }
        if (KeyIsDown(KEYMAP_ESCAPE)) {
            WaitForNoKeys();
        }
    } else {
        original_MoveReplayBuffer(pMove_amount);
    }
}

function_hook_state_t function_hook_state_MoveToEndOfReplay = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(function_hook_state_MoveToEndOfReplay)
static void(__cdecl*original_MoveToEndOfReplay)() = (void(__cdecl*)())0x0041b3df;
CARM95_HOOK_FUNCTION(original_MoveToEndOfReplay, MoveToEndOfReplay)
void __cdecl MoveToEndOfReplay() {
    float old_replay_rate;
    LOG_TRACE("()");

    (void)old_replay_rate;

    if (function_hook_state_MoveToEndOfReplay == HOOK_ENABLED) {
        DisablePipedSounds();
        old_replay_rate = HV(gReplay_rate);
        HV(gReplay_rate) = 100.f;
        MoveReplayBuffer(INT32_MAX);
        HV(gReplay_rate) = old_replay_rate;
        EnablePipedSounds();
    } else {
        original_MoveToEndOfReplay();
    }
}

function_hook_state_t function_hook_state_MoveToStartOfReplay = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(function_hook_state_MoveToStartOfReplay)
static void(__cdecl*original_MoveToStartOfReplay)() = (void(__cdecl*)())0x0041b622;
CARM95_HOOK_FUNCTION(original_MoveToStartOfReplay, MoveToStartOfReplay)
void __cdecl MoveToStartOfReplay() {
    float old_replay_rate;
    LOG_TRACE("()");

    (void)old_replay_rate;

    if (function_hook_state_MoveToStartOfReplay == HOOK_ENABLED) {
        DisablePipedSounds();
        old_replay_rate = HV(gReplay_rate);
        HV(gReplay_rate) = -100.f;
        MoveReplayBuffer(-INT32_MAX);
        HV(gReplay_rate) = old_replay_rate;
        EnablePipedSounds();
    } else {
        original_MoveToStartOfReplay();
    }
}

function_hook_state_t function_hook_state_ToggleReplay = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(function_hook_state_ToggleReplay)
static void(__cdecl*original_ToggleReplay)() = (void(__cdecl*)())0x0041b661;
CARM95_HOOK_FUNCTION(original_ToggleReplay, ToggleReplay)
void __cdecl ToggleReplay() {
    LOG_TRACE("()");


    if (function_hook_state_ToggleReplay == HOOK_ENABLED) {
        if (!IsActionReplayAvailable()) {
            NewTextHeadupSlot(4, 0, 1000, -4, GetMiscString(37));
            return;
        }
        if (!HV(gAction_replay_mode)) {
            if (HV(gMap_mode)) {
                ToggleMap();
            }
            if (HV(gNet_mode) == eNet_mode_host) {
                SendGameplayToAllPlayers(eNet_gameplay_host_paused, 0, 0, 0, 0);
            }
            HV(gReplay_rate) = 1.f;
            HV(gPaused) = 1;
            HV(gStopped_time) = PDGetTotalTime();
            HV(gPlay_direction) = 1;
            HV(gAction_replay_end_time) = GetTotalTime();
            HV(gLast_replay_frame_time) = HV(gAction_replay_end_time);
            HV(gAction_replay_start_time) = GetARStartTime();
            ResetPipePlayToEnd();
            LoadInterfaceStuff(1);
            StartMouseCursor();
            HV(gKey_down) = KEY_KP_ENTER;
            HV(gPending_replay_rate) = 0;
            HV(gCam_change_time) = PDGetTotalTime();
            if (!HV(gRace_finished)) {
                SaveCameraPosition(0);
            }
        } else {
            MoveToEndOfReplay();
            EndMouseCursor();
            S3SetEffects(NULL, NULL);
            UnlockInterfaceStuff();
            AddLostTime(PDGetTotalTime() - HV(gStopped_time));
            if (!HV(gRace_finished)) {
                RestoreCameraPosition(0);
            }
            if (HV(gNet_mode) == eNet_mode_host) {
                SendGameplayToAllPlayers(eNet_gameplay_host_unpaused, 0, 0, 0, 0);
            }
        }
        HV(gAction_replay_mode) = !HV(gAction_replay_mode);
        ForceRebuildActiveCarList();
    } else {
        original_ToggleReplay();
    }
}

function_hook_state_t function_hook_state_ReverseSound = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_ReverseSound)
static void(__cdecl*original_ReverseSound)(tS3_effect_tag, tS3_sound_tag) = (void(__cdecl*)(tS3_effect_tag, tS3_sound_tag))0x0041b7fe;
CARM95_HOOK_FUNCTION(original_ReverseSound, ReverseSound)
void __cdecl ReverseSound(tS3_effect_tag pEffect_index, tS3_sound_tag pSound_tag) {
    LOG_TRACE("(%d, %d)", pEffect_index, pSound_tag);

    (void)pEffect_index;
    (void)pSound_tag;

    if (function_hook_state_ReverseSound == HOOK_ENABLED) {
        assert(0 && "ReverseSound not implemented.");
        abort();
    } else {
        original_ReverseSound(pEffect_index, pSound_tag);
    }
}

function_hook_state_t function_hook_state_FindUniqueFile = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(function_hook_state_FindUniqueFile)
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

    if (function_hook_state_FindUniqueFile == HOOK_ENABLED) {
        for (index = 0; index < 1000; index++) {
            PathCat(the_path, HV(gApplication_path), "BMPFILES");
            PathCat(the_path, the_path, "");
            sprintf(&the_path[strlen(the_path)], "%03d", index);
            strcat(the_path, "_0000.BMP");
            f = DRfopen(the_path, "rt");
            if (f == NULL) {
                return index;
            }
            fclose(f);
        }
        return 0;
    } else {
        return original_FindUniqueFile();
    }
}

function_hook_state_t function_hook_state_PollActionReplayControls = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(function_hook_state_PollActionReplayControls)
static void(__cdecl*original_PollActionReplayControls)(tU32) = (void(__cdecl*)(tU32))0x0041b925;
CARM95_HOOK_FUNCTION(original_PollActionReplayControls, PollActionReplayControls)
void __cdecl PollActionReplayControls(tU32 pFrame_period) {
    float old_replay_rate;
    int old_key_down;
    int x_coord;
    int y_coord;
    int i;
    tU32 real_time;
    static tU32 last_real_time = 0;
    static int psuedo_mouse_keys[8] = {
            KEY_KP_7,
            KEY_KP_4,
            KEY_COMMA,
            KEY_SPACE,
            KEY_PERIOD,
            KEY_KP_6,
            KEY_KP_9,
            KEY_KP_MULTIPLY,
    };
    static tRectangle mouse_areas[2][8] = {
            {
                    {  63, 182,  92, 198, },
                    {  93, 182, 118, 198, },
                    { 119, 182, 144, 198, },
                    { 145, 182, 166, 198, },
                    { 167, 182, 192, 198, },
                    { 193, 182, 218, 198, },
                    { 219, 182, 244, 198, },
                    { 245, 182, 272, 198, },
            },
            {
                    { 126, 436, 184, 475, },
                    { 186, 436, 236, 475, },
                    { 238, 436, 288, 475, },
                    { 290, 436, 332, 475, },
                    { 334, 436, 384, 475, },
                    { 386, 436, 436, 475, },
                    { 438, 436, 488, 475, },
                    { 490, 436, 544, 475, },
            },
    };
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

    if (function_hook_state_PollActionReplayControls == HOOK_ENABLED) {
        real_time = PDGetTotalTime();
        old_replay_rate = HV(gReplay_rate);
        old_key_down = HV(gKey_down) == KEY_CAPSLOCK ? -1 : HV(gKey_down);
        HV(gKey_down) = PDAnyKeyDown();
        if (KeyIsDown(KEYMAP_REPLAYMODE) && old_key_down == -1) {
            ToggleReplay();
            return;
        }

        if (HV(gKey_down) == -1) {
            if ((old_key_down == -1 || old_key_down == KEY_KP_4 || old_key_down == KEY_KP_6 || old_key_down == KEY_KP_MULTIPLY) && EitherMouseButtonDown()) {
                GetMousePosition(&x_coord, &y_coord);
                for (i = 0; i < COUNT_OF(mouse_areas[0]); i++) {
                    if (mouse_areas[HV(gGraf_data_index)][i].left <= x_coord && mouse_areas[HV(gGraf_data_index)][i].top <= y_coord &&
                        mouse_areas[HV(gGraf_data_index)][i].right >= x_coord && mouse_areas[HV(gGraf_data_index)][i].bottom >= y_coord) {
                        HV(gKey_down) = psuedo_mouse_keys[i];
                        break;
                    }
                }
            }
        } else {
            HV(gMouse_in_use) = 0;
        }

        if (HV(gKey_down) == KEY_KP_DIVIDE && old_key_down != KEY_KP_DIVIDE) {
            if (HV(gSave_file)) {
                StopSaving();
            } else {
                HV(gSave_bunch_ID) = FindUniqueFile();
                HV(gSave_frame_number) = 0;
                HV(gSave_file) = 1;
                HV(gPlay_direction) = 1;
                HV(gPaused) = 0;
            }
        }

        if (HV(gKey_down) == KEY_KP_MULTIPLY) {
            HV(gCam_change_button_down) = 1;
            if (old_key_down != KEY_KP_MULTIPLY) {
                HV(gCam_change_time) = PDGetTotalTime();
                if (HV(gAction_replay_camera_mode) == eAction_replay_action) {
                    HV(gAction_replay_camera_mode) = eAction_replay_standard;
                } else {
                    HV(gAction_replay_camera_mode)++;
                }
            }
        } else {
            HV(gCam_change_button_down) = 0;
        }

        if ((HV(gKey_down) == KEY_KP_5 || HV(gKey_down) == KEY_SPACE) && old_key_down == -1) {
            HV(gPaused) = !HV(gPaused);
        } else if ((HV(gKey_down) == KEY_KP_0 || HV(gKey_down) == KEY_BACKSPACE) && old_key_down == -1) {
            HV(gPlay_direction) = -HV(gPlay_direction);
            if (HV(gPaused)) {
                HV(gPaused) = 0;
            }
        }

        if (HV(gKey_down) == KEY_KP_1 && old_key_down == -1) {
            HV(gReplay_rate) = -1.f;
            HV(gPlay_direction) = -1;
            HV(gSingle_frame_mode) = 1;
        } else if (HV(gKey_down) == KEY_KP_3 && old_key_down == -1) {
            HV(gReplay_rate) = 1.f;
            HV(gPlay_direction) = 1;
            HV(gSingle_frame_mode) = 1;
        } else if (HV(gKey_down) == KEY_KP_4 || HV(gKey_down) == KEY_PAGEUP) {
            if (HV(gReplay_rate) > -1.2f) {
                HV(gReplay_rate) = -1.2f;
            }
            if (last_real_time != 0) {
                HV(gReplay_rate) -= 0.002f * (real_time - last_real_time);
            }
            if (HV(gReplay_rate) < -8.f) {
                HV(gReplay_rate) = -8.f;
            }
        } else if (HV(gKey_down) == KEY_KP_6 || HV(gKey_down) == KEY_PAGEDOWN) {
            if (HV(gReplay_rate) < 1.2f) {
                HV(gReplay_rate) = 1.2f;
            }
            if (last_real_time != 0) {
                HV(gReplay_rate) += 0.002f * (real_time - last_real_time);
            }
            if (HV(gReplay_rate) > 8.f) {
                HV(gReplay_rate) = 8.f;
            }
        } else if (HV(gKey_down) == KEY_COMMA) {
            HV(gReplay_rate) = -1.f;
            HV(gPlay_direction) = -1;
            HV(gPaused) = 0;
        } else if (HV(gKey_down) == KEY_PERIOD) {
            HV(gReplay_rate) = 1.f;
            HV(gPlay_direction) = 1;
            HV(gPaused) = 0;
        } else if (HV(gPaused)) {
            HV(gReplay_rate) = 0.f;
        } else {
            HV(gReplay_rate) = (float)HV(gPlay_direction);
        }

        if ((HV(gKey_down) == KEY_KP_7 || HV(gKey_down) == KEY_HOME) && old_key_down == -1) {
            MoveToStartOfReplay();
            HV(gReplay_rate) = 1.f;
            MungeCarGraphics(HV(gFrame_period));
            GrooveThoseDelics();
            HV(gReplay_rate) = 0.f;
            HV(gPlay_direction) = 1;
            HV(gPaused) = 1;
        } else if ((HV(gKey_down) == KEY_KP_9 || HV(gKey_down) == KEY_END) && old_key_down == -1) {
            MoveToEndOfReplay();
            HV(gReplay_rate) = -1.f;
            MungeCarGraphics(HV(gFrame_period));
            GrooveThoseDelics();
            HV(gReplay_rate) = 0.f;
            HV(gPlay_direction) = -1;
            HV(gPaused) = 1;
        }

        if (HV(gPending_replay_rate) != 0.f) {
            HV(gReplay_rate) = HV(gPending_replay_rate);
        }
        if (old_replay_rate * HV(gReplay_rate) >= 0.f) {
            HV(gPending_replay_rate) = 0.f;
        } else {
            HV(gPending_replay_rate) = HV(gReplay_rate);
            HV(gReplay_rate) = 0.f;
        }

        if (old_replay_rate != 0.f) {
            HV(gFrame_period) = HV(gFrame_period) * HV(gReplay_rate) / old_replay_rate;
        }
        last_real_time = fabsf(HV(gReplay_rate)) >= 1.2f ? real_time : 0;

        if (old_replay_rate <= 0.f && HV(gReplay_rate) > 0.f) {
            S3SetEffects(NULL, NULL);
        } else if (old_replay_rate >= 0.f && HV(gReplay_rate) < 0.f) {
            S3SetEffects(ReverseSound, ReverseSound);
        }
    } else {
        original_PollActionReplayControls(pFrame_period);
    }
}

function_hook_state_t function_hook_state_CheckReplayTurnOn = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(function_hook_state_CheckReplayTurnOn)
static void(__cdecl*original_CheckReplayTurnOn)() = (void(__cdecl*)())0x0041c03b;
CARM95_HOOK_FUNCTION(original_CheckReplayTurnOn, CheckReplayTurnOn)
void __cdecl CheckReplayTurnOn() {
    LOG_TRACE("()");


    if (function_hook_state_CheckReplayTurnOn == HOOK_ENABLED) {
        if (!HV(gAction_replay_mode)) {
            if (!KeyIsDown(KEYMAP_REPLAYMODE) || HV(gEntering_message)) {
                HV(gKey_down) = -1;
            } else if (HV(gKey_down) == -1) {
                ToggleReplay();
            }
        }
    } else {
        original_CheckReplayTurnOn();
    }
}

function_hook_state_t function_hook_state_InitializeActionReplay = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(function_hook_state_InitializeActionReplay)
static void(__cdecl*original_InitializeActionReplay)() = (void(__cdecl*)())0x0041c093;
CARM95_HOOK_FUNCTION(original_InitializeActionReplay, InitializeActionReplay)
void __cdecl InitializeActionReplay() {
    int i;
    LOG_TRACE("()");

    (void)i;

    if (function_hook_state_InitializeActionReplay == HOOK_ENABLED) {
        for (i = 0; i < COUNT_OF(HV(gReplay_pixie_names)); i++) {
            HV(gReplay_pixies)[i] = LoadPixelmap(HV(gReplay_pixie_names)[i]);
        }
        HV(gAction_replay_camera_mode) = eAction_replay_action;
    } else {
        original_InitializeActionReplay();
    }
}

function_hook_state_t function_hook_state_DoActionReplay = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(function_hook_state_DoActionReplay)
static void(__cdecl*original_DoActionReplay)(tU32) = (void(__cdecl*)(tU32))0x0041c0e6;
CARM95_HOOK_FUNCTION(original_DoActionReplay, DoActionReplay)
void __cdecl DoActionReplay(tU32 pFrame_period) {
    LOG_TRACE("(%u)", pFrame_period);

    (void)pFrame_period;

    if (function_hook_state_DoActionReplay == HOOK_ENABLED) {
        if (HV(gReplay_rate) != 0.f) {
            MoveReplayBuffer((tS32)HV(gReplay_rate));
        }
    } else {
        original_DoActionReplay(pFrame_period);
    }
}

function_hook_state_t function_hook_state_SynchronizeActionReplay = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(function_hook_state_SynchronizeActionReplay)
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

    if (function_hook_state_SynchronizeActionReplay == HOOK_ENABLED) {
        while (HV(gReplay_rate) != 0.f) {
            if (PDGetTotalTime() - gLast_synch_time >= HV(gFrame_period) / fabsf(HV(gReplay_rate))) {
                break;
            }
            ServiceGameInRace();
        }
        gLast_synch_time = PDGetTotalTime();
        if (HV(gSingle_frame_mode)) {
            HV(gReplay_rate) = 0.f;
            HV(gSingle_frame_mode) = 0;
        }

        if (HV(gSave_file)) {
            PathCat(the_path, HV(gApplication_path), "BMPFILES");
            strcat(the_path, HV(gDir_separator));
            sprintf(&the_path[strlen(the_path)], "%03d_%04d.BMP", HV(gSave_bunch_ID), HV(gSave_frame_number));
            f = DRfopen(the_path, "wb");
            if (f != NULL) {
                PrintScreenFile(f);
                fclose(f);
            }
            HV(gSave_frame_number)++;
        }
    } else {
        original_SynchronizeActionReplay();
    }
}

