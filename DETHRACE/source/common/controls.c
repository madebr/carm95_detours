#include "controls.h"

#include "brender/brender.h"
#include "brucetrk.h"
#include "car.h"
#include "constants.h"
#include "crush.h"
#include "depth.h"
#include "displays.h"
#include "finteray.h"
#include "flicplay.h"
#include "globvars.h"
#include "globvrkm.h"
#include "globvrpb.h"
#include "grafdata.h"
#include "graphics.h"
#include "init.h"
#include "input.h"
#include "loadsave.h"
#include "mainloop.h"
#include "netgame.h"
#include "network.h"
#include "opponent.h"
#include "pc-dos/dossys.h"
#include "pedestrn.h"
#include "piping.h"
#include "powerup.h"
#include "pratcam.h"
#include "raycast.h"
#include "replay.h"
#include "s3/s3.h"
#include "sound.h"
#include "spark.h"
#include "structur.h"
#include "utility.h"
#include "world.h"

#include "harness/trace.h"

#include "carm95_hooks.h"

#include "carm95_webserver.h"

#include <assert.h>
tToggle_element(* hookvar_gToggle_array )[43] = (void*)0x0051b1c0;
int * hookvar_gRepair_last_time  = (void*)0x0051b5c8;
int * hookvar_gHad_auto_recover  = (void*)0x0051b5cc;
tU32 * hookvar_gLast_repair_time  = (void*)0x0051b5d0;
tEdit_mode * hookvar_gWhich_edit_mode  = (void*)0x0051b5d4;
char *(* hookvar_gEdit_mode_names )[10] = (void*)0x0051b5d8;
tEdit_func*(* hookvar_gEdit_funcs )[10][18][8] = (void*)0x0051b600;
tCheat(* hookvar_gKev_keys )[44] = (void*)0x0051cc80;
int * hookvar_gAllow_car_flying  = (void*)0x0051cf30;
int * hookvar_gEntering_message  = (void*)0x0051cf34;
tU32 * hookvar_gPalette_fade_time  = (void*)0x0051cf38;
char *(* hookvar_gAbuse_text )[10] = (void*)0x0053d608;
char(* hookvar_gString )[84] = (void*)0x0053d648;
int * hookvar_gToo_late  = (void*)0x0053d5f8;
int * hookvar_gRecover_timer  = (void*)0x0053d5fc;
int * hookvar_gRecovery_voucher_count  = (void*)0x0053d63c;
int * hookvar_gInstant_handbrake  = (void*)0x00550550;
int * hookvar_gAuto_repair  = (void*)0x00550554;

function_hook_state_t function_hook_state_AbortRace = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(AbortRace, function_hook_state_AbortRace)
static void(__cdecl*original_AbortRace)() = (void(__cdecl*)())0x004a0c70;
CARM95_HOOK_FUNCTION(original_AbortRace, AbortRace)
void __cdecl AbortRace() {
    LOG_TRACE("()");


    if (function_hook_state_AbortRace == HOOK_ENABLED) {
        if (!HV(gRace_finished)) {
            HV(gAbandon_game) = 1;
        }
    } else {
        original_AbortRace();
    }
}

function_hook_state_t function_hook_state_F4Key = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(F4Key, function_hook_state_F4Key)
static void(__cdecl*original_F4Key)() = (void(__cdecl*)())0x004a0c92;
CARM95_HOOK_FUNCTION(original_F4Key, F4Key)
void __cdecl F4Key() {
    char s[256];
    tEdit_mode old_edit_mode;
    LOG_TRACE("()");

    (void)s;
    (void)old_edit_mode;

    if (function_hook_state_F4Key == HOOK_ENABLED) {
        old_edit_mode = HV(gWhich_edit_mode);
        if (HV(gI_am_cheating) == 0xa11ee75d || (HV(gI_am_cheating) == 0x564e78b9 && HV(gNet_mode) == eNet_mode_none)) {
            if (PDKeyDown(KEY_SHIFT_ANY)) {
                HV(gWhich_edit_mode)--;
                if ((int)HV(gWhich_edit_mode) < 0) {
                    HV(gWhich_edit_mode) = COUNT_OF(HV(gEdit_funcs)) - 1;
                }
            } else {
                HV(gWhich_edit_mode)++;
                if (HV(gWhich_edit_mode) >= COUNT_OF(HV(gEdit_funcs))) {
                    HV(gWhich_edit_mode) = 0;
                }
            }
            sprintf(s, "Edit mode: %s", HV(gEdit_mode_names)[HV(gWhich_edit_mode)]);
            NewTextHeadupSlot2(4, 0, 2000, -4, s, 0);
            if (HV(gWhich_edit_mode) == eEdit_mode_spec_vol && old_edit_mode != eEdit_mode_spec_vol) {
                ShowSpecialVolumes();
            } else if (HV(gWhich_edit_mode) != eEdit_mode_spec_vol && old_edit_mode == eEdit_mode_spec_vol) {
                HideSpecialVolumes();
            }
        } else {
            HV(gWhich_edit_mode) = eEdit_mode_options;
        }
    } else {
        original_F4Key();
    }
}

function_hook_state_t function_hook_state_SetFlag = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(SetFlag, function_hook_state_SetFlag)
static void(__cdecl*original_SetFlag)(int) = (void(__cdecl*)(int))0x004a0db7;
CARM95_HOOK_FUNCTION(original_SetFlag, SetFlag)
void __cdecl SetFlag(int i) {
    LOG_TRACE("(%d)", i);

    (void)i;

    if (function_hook_state_SetFlag == HOOK_ENABLED) {
        if (HV(gNet_mode) == eNet_mode_none) {
            NewTextHeadupSlot(4, 0, 3000, -4, "You Cheat!");
        }
        HV(gI_am_cheating) = i;
        F4Key();
    } else {
        original_SetFlag(i);
    }
}

function_hook_state_t function_hook_state_FinishLap = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(FinishLap, function_hook_state_FinishLap)
static void(__cdecl*original_FinishLap)(int) = (void(__cdecl*)(int))0x004a0df4;
CARM95_HOOK_FUNCTION(original_FinishLap, FinishLap)
void __cdecl FinishLap(int i) {
    LOG_TRACE("(%d)", i);

    (void)i;

    if (function_hook_state_FinishLap == HOOK_ENABLED) {
        IncrementLap();
    } else {
        original_FinishLap(i);
    }
}

function_hook_state_t function_hook_state_EnsureSpecialVolumesHidden = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(EnsureSpecialVolumesHidden, function_hook_state_EnsureSpecialVolumesHidden)
static void(__cdecl*original_EnsureSpecialVolumesHidden)() = (void(__cdecl*)())0x004a0e04;
CARM95_HOOK_FUNCTION(original_EnsureSpecialVolumesHidden, EnsureSpecialVolumesHidden)
void __cdecl EnsureSpecialVolumesHidden() {
    LOG_TRACE("()");


    if (function_hook_state_EnsureSpecialVolumesHidden == HOOK_ENABLED) {
        if (HV(gWhich_edit_mode) == eEdit_mode_spec_vol) {
            HideSpecialVolumes();
        }
    } else {
        original_EnsureSpecialVolumesHidden();
    }
}

function_hook_state_t function_hook_state_ShowSpecialVolumesIfRequ = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(ShowSpecialVolumesIfRequ, function_hook_state_ShowSpecialVolumesIfRequ)
static void(__cdecl*original_ShowSpecialVolumesIfRequ)() = (void(__cdecl*)())0x004a0e21;
CARM95_HOOK_FUNCTION(original_ShowSpecialVolumesIfRequ, ShowSpecialVolumesIfRequ)
void __cdecl ShowSpecialVolumesIfRequ() {
    LOG_TRACE("()");


    if (function_hook_state_ShowSpecialVolumesIfRequ == HOOK_ENABLED) {
        if (HV(gWhich_edit_mode) == eEdit_mode_spec_vol) {
            ShowSpecialVolumes();
        }
    } else {
        original_ShowSpecialVolumesIfRequ();
    }
}

function_hook_state_t function_hook_state_DoEditModeKey = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(DoEditModeKey, function_hook_state_DoEditModeKey)
static void(__cdecl*original_DoEditModeKey)(int) = (void(__cdecl*)(int))0x004a0e53;
CARM95_HOOK_FUNCTION(original_DoEditModeKey, DoEditModeKey)
void __cdecl DoEditModeKey(int pIndex) {
    int modifiers;
    LOG_TRACE("(%d)", pIndex);

    (void)pIndex;
    (void)modifiers;

    if (function_hook_state_DoEditModeKey == HOOK_ENABLED) {
        if (HV(gI_am_cheating) == 0xa11ee75d || (HV(gI_am_cheating) == 0x564e78b9 && HV(gNet_mode) == eNet_mode_none)) {
            modifiers = 0;
            if (PDKeyDown(KEY_SHIFT_ANY)) {
                modifiers |= 4;
            }
            if (PDKeyDown(KEY_ALT_ANY)) {
                modifiers |= 2;
            }
            if (PDKeyDown(KEY_CTRL_ANY)) {
                modifiers |= 1;
            }
            if (HV(gEdit_funcs)[HV(gWhich_edit_mode)][pIndex][modifiers] != NULL) {
                HV(gEdit_funcs)[HV(gWhich_edit_mode)][pIndex][modifiers]();
            }
        } else {
            HV(gWhich_edit_mode) = eEdit_mode_options;
        }
    } else {
        original_DoEditModeKey(pIndex);
    }
}

function_hook_state_t function_hook_state_F5Key = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(F5Key, function_hook_state_F5Key)
static void(__cdecl*original_F5Key)() = (void(__cdecl*)())0x004a0e3e;
CARM95_HOOK_FUNCTION(original_F5Key, F5Key)
void __cdecl F5Key() {
    LOG_TRACE("()");


    if (function_hook_state_F5Key == HOOK_ENABLED) {
        DoEditModeKey(0);
    } else {
        original_F5Key();
    }
}

function_hook_state_t function_hook_state_F6Key = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(F6Key, function_hook_state_F6Key)
static void(__cdecl*original_F6Key)() = (void(__cdecl*)())0x004a0f3d;
CARM95_HOOK_FUNCTION(original_F6Key, F6Key)
void __cdecl F6Key() {
    LOG_TRACE("()");


    if (function_hook_state_F6Key == HOOK_ENABLED) {
        DoEditModeKey(1);
    } else {
        original_F6Key();
    }
}

function_hook_state_t function_hook_state_F7Key = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(F7Key, function_hook_state_F7Key)
static void(__cdecl*original_F7Key)() = (void(__cdecl*)())0x004a0f52;
CARM95_HOOK_FUNCTION(original_F7Key, F7Key)
void __cdecl F7Key() {
    LOG_TRACE("()");


    if (function_hook_state_F7Key == HOOK_ENABLED) {
        DoEditModeKey(2);
    } else {
        original_F7Key();
    }
}

function_hook_state_t function_hook_state_F8Key = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(F8Key, function_hook_state_F8Key)
static void(__cdecl*original_F8Key)() = (void(__cdecl*)())0x004a0f67;
CARM95_HOOK_FUNCTION(original_F8Key, F8Key)
void __cdecl F8Key() {
    LOG_TRACE("()");


    if (function_hook_state_F8Key == HOOK_ENABLED) {
        DoEditModeKey(3);
    } else {
        original_F8Key();
    }
}

function_hook_state_t function_hook_state_F10Key = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(F10Key, function_hook_state_F10Key)
static void(__cdecl*original_F10Key)() = (void(__cdecl*)())0x004a0f7c;
CARM95_HOOK_FUNCTION(original_F10Key, F10Key)
void __cdecl F10Key() {
    LOG_TRACE("()");


    if (function_hook_state_F10Key == HOOK_ENABLED) {
        DoEditModeKey(4);
    } else {
        original_F10Key();
    }
}

function_hook_state_t function_hook_state_F11Key = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(F11Key, function_hook_state_F11Key)
static void(__cdecl*original_F11Key)() = (void(__cdecl*)())0x004a0f91;
CARM95_HOOK_FUNCTION(original_F11Key, F11Key)
void __cdecl F11Key() {
    LOG_TRACE("()");


    if (function_hook_state_F11Key == HOOK_ENABLED) {
        DoEditModeKey(5);
    } else {
        original_F11Key();
    }
}

function_hook_state_t function_hook_state_F12Key = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(F12Key, function_hook_state_F12Key)
static void(__cdecl*original_F12Key)() = (void(__cdecl*)())0x004a0fa6;
CARM95_HOOK_FUNCTION(original_F12Key, F12Key)
void __cdecl F12Key() {
    LOG_TRACE("()");


    if (function_hook_state_F12Key == HOOK_ENABLED) {
        DoEditModeKey(6);
    } else {
        original_F12Key();
    }
}

function_hook_state_t function_hook_state_NumberKey0 = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(NumberKey0, function_hook_state_NumberKey0)
static void(__cdecl*original_NumberKey0)() = (void(__cdecl*)())0x004a0fbb;
CARM95_HOOK_FUNCTION(original_NumberKey0, NumberKey0)
void __cdecl NumberKey0() {
    LOG_TRACE("()");


    if (function_hook_state_NumberKey0 == HOOK_ENABLED) {
        DoEditModeKey(7);
    } else {
        original_NumberKey0();
    }
}

function_hook_state_t function_hook_state_NumberKey1 = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(NumberKey1, function_hook_state_NumberKey1)
static void(__cdecl*original_NumberKey1)() = (void(__cdecl*)())0x004a0fd0;
CARM95_HOOK_FUNCTION(original_NumberKey1, NumberKey1)
void __cdecl NumberKey1() {
    LOG_TRACE("()");


    if (function_hook_state_NumberKey1 == HOOK_ENABLED) {
        DoEditModeKey(8);
    } else {
        original_NumberKey1();
    }
}

function_hook_state_t function_hook_state_NumberKey2 = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(NumberKey2, function_hook_state_NumberKey2)
static void(__cdecl*original_NumberKey2)() = (void(__cdecl*)())0x004a0fe5;
CARM95_HOOK_FUNCTION(original_NumberKey2, NumberKey2)
void __cdecl NumberKey2() {
    LOG_TRACE("()");


    if (function_hook_state_NumberKey2 == HOOK_ENABLED) {
        DoEditModeKey(9);
    } else {
        original_NumberKey2();
    }
}

function_hook_state_t function_hook_state_NumberKey3 = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(NumberKey3, function_hook_state_NumberKey3)
static void(__cdecl*original_NumberKey3)() = (void(__cdecl*)())0x004a0ffa;
CARM95_HOOK_FUNCTION(original_NumberKey3, NumberKey3)
void __cdecl NumberKey3() {
    LOG_TRACE("()");


    if (function_hook_state_NumberKey3 == HOOK_ENABLED) {
        DoEditModeKey(10);
    } else {
        original_NumberKey3();
    }
}

function_hook_state_t function_hook_state_NumberKey4 = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(NumberKey4, function_hook_state_NumberKey4)
static void(__cdecl*original_NumberKey4)() = (void(__cdecl*)())0x004a100f;
CARM95_HOOK_FUNCTION(original_NumberKey4, NumberKey4)
void __cdecl NumberKey4() {
    LOG_TRACE("()");


    if (function_hook_state_NumberKey4 == HOOK_ENABLED) {
        DoEditModeKey(11);
    } else {
        original_NumberKey4();
    }
}

function_hook_state_t function_hook_state_NumberKey5 = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(NumberKey5, function_hook_state_NumberKey5)
static void(__cdecl*original_NumberKey5)() = (void(__cdecl*)())0x004a1024;
CARM95_HOOK_FUNCTION(original_NumberKey5, NumberKey5)
void __cdecl NumberKey5() {
    LOG_TRACE("()");


    if (function_hook_state_NumberKey5 == HOOK_ENABLED) {
        DoEditModeKey(12);
    } else {
        original_NumberKey5();
    }
}

function_hook_state_t function_hook_state_NumberKey6 = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(NumberKey6, function_hook_state_NumberKey6)
static void(__cdecl*original_NumberKey6)() = (void(__cdecl*)())0x004a1039;
CARM95_HOOK_FUNCTION(original_NumberKey6, NumberKey6)
void __cdecl NumberKey6() {
    LOG_TRACE("()");


    if (function_hook_state_NumberKey6 == HOOK_ENABLED) {
        DoEditModeKey(13);
    } else {
        original_NumberKey6();
    }
}

function_hook_state_t function_hook_state_NumberKey7 = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(NumberKey7, function_hook_state_NumberKey7)
static void(__cdecl*original_NumberKey7)() = (void(__cdecl*)())0x004a104e;
CARM95_HOOK_FUNCTION(original_NumberKey7, NumberKey7)
void __cdecl NumberKey7() {
    LOG_TRACE("()");


    if (function_hook_state_NumberKey7 == HOOK_ENABLED) {
        DoEditModeKey(14);
    } else {
        original_NumberKey7();
    }
}

function_hook_state_t function_hook_state_NumberKey8 = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(NumberKey8, function_hook_state_NumberKey8)
static void(__cdecl*original_NumberKey8)() = (void(__cdecl*)())0x004a1063;
CARM95_HOOK_FUNCTION(original_NumberKey8, NumberKey8)
void __cdecl NumberKey8() {
    LOG_TRACE("()");


    if (function_hook_state_NumberKey8 == HOOK_ENABLED) {
        DoEditModeKey(15);
    } else {
        original_NumberKey8();
    }
}

function_hook_state_t function_hook_state_NumberKey9 = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(NumberKey9, function_hook_state_NumberKey9)
static void(__cdecl*original_NumberKey9)() = (void(__cdecl*)())0x004a1078;
CARM95_HOOK_FUNCTION(original_NumberKey9, NumberKey9)
void __cdecl NumberKey9() {
    LOG_TRACE("()");


    if (function_hook_state_NumberKey9 == HOOK_ENABLED) {
        DoEditModeKey(16);
    } else {
        original_NumberKey9();
    }
}

function_hook_state_t function_hook_state_LookLeft = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(LookLeft, function_hook_state_LookLeft)
static void(__cdecl*original_LookLeft)() = (void(__cdecl*)())0x004a108d;
CARM95_HOOK_FUNCTION(original_LookLeft, LookLeft)
void __cdecl LookLeft() {
    LOG_TRACE("()");


    if (function_hook_state_LookLeft == HOOK_ENABLED) {
        if (HV(gAusterity_mode)) {
            NewTextHeadupSlot(4, 0, 1000, -4, GetMiscString(192));
        } else {
            PratcamEvent(27);
            HV(gProgram_state).old_view = HV(gProgram_state).which_view;
            if (HV(gProgram_state).which_view == eView_left) {
                LookForward();
            } else if (HV(gProgram_state).which_view == eView_right) {
                LookForward();
                HV(gProgram_state).pending_view = eView_left;
            } else {
                ClearWobbles();
                HV(gProgram_state).new_view = eView_left;
                HV(gProgram_state).view_change_start = PDGetTotalTime();
                HV(gProgram_state).pending_view = eView_undefined;
            }
        }
    } else {
        original_LookLeft();
    }
}

function_hook_state_t function_hook_state_LookForward = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(LookForward, function_hook_state_LookForward)
static void(__cdecl*original_LookForward)() = (void(__cdecl*)())0x004a113a;
CARM95_HOOK_FUNCTION(original_LookForward, LookForward)
void __cdecl LookForward() {
    LOG_TRACE("()");


    if (function_hook_state_LookForward == HOOK_ENABLED) {
        if (HV(gProgram_state).which_view == eView_right) {
            PratcamEvent(27);
        } else if (HV(gProgram_state).which_view == eView_left) {
            PratcamEvent(28);
        }
        if (HV(gProgram_state).which_view != eView_forward) {
            HV(gProgram_state).old_view = HV(gProgram_state).which_view;
            ClearWobbles();
            HV(gProgram_state).new_view = eView_forward;
            HV(gProgram_state).view_change_start = PDGetTotalTime();
            HV(gProgram_state).pending_view = eView_undefined;
        }
    } else {
        original_LookForward();
    }
}

function_hook_state_t function_hook_state_LookRight = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(LookRight, function_hook_state_LookRight)
static void(__cdecl*original_LookRight)() = (void(__cdecl*)())0x004a11b2;
CARM95_HOOK_FUNCTION(original_LookRight, LookRight)
void __cdecl LookRight() {
    LOG_TRACE("()");


    if (function_hook_state_LookRight == HOOK_ENABLED) {
        if (HV(gAusterity_mode)) {
            NewTextHeadupSlot(4, 0, 1000, -4, GetMiscString(192));
        } else {
            PratcamEvent(28);
            HV(gProgram_state).old_view = HV(gProgram_state).which_view;
            if (HV(gProgram_state).which_view == eView_right) {
                LookForward();
            } else if (HV(gProgram_state).which_view == eView_left) {
                LookForward();
                HV(gProgram_state).pending_view = eView_right;
            } else {
                ClearWobbles();
                HV(gProgram_state).new_view = eView_right;
                HV(gProgram_state).view_change_start = PDGetTotalTime();
                HV(gProgram_state).pending_view = eView_undefined;
            }
        }
    } else {
        original_LookRight();
    }
}

function_hook_state_t function_hook_state_DamageTest = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(DamageTest, function_hook_state_DamageTest)
static void(__cdecl*original_DamageTest)() = (void(__cdecl*)())0x004a125f;
CARM95_HOOK_FUNCTION(original_DamageTest, DamageTest)
void __cdecl DamageTest() {
    LOG_TRACE("()");


    if (function_hook_state_DamageTest == HOOK_ENABLED) {
    } else {
        original_DamageTest();
    }
}

function_hook_state_t function_hook_state_TDamageEngine = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(TDamageEngine, function_hook_state_TDamageEngine)
static void(__cdecl*original_TDamageEngine)() = (void(__cdecl*)())0x004a126a;
CARM95_HOOK_FUNCTION(original_TDamageEngine, TDamageEngine)
void __cdecl TDamageEngine() {
    LOG_TRACE("()");


    if (function_hook_state_TDamageEngine == HOOK_ENABLED) {
        DamageEngine(21);
    } else {
        original_TDamageEngine();
    }
}

function_hook_state_t function_hook_state_TDamageDriver = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(TDamageDriver, function_hook_state_TDamageDriver)
static void(__cdecl*original_TDamageDriver)() = (void(__cdecl*)())0x004a127f;
CARM95_HOOK_FUNCTION(original_TDamageDriver, TDamageDriver)
void __cdecl TDamageDriver() {
    LOG_TRACE("()");


    if (function_hook_state_TDamageDriver == HOOK_ENABLED) {
        if (HV(gProgram_state).current_car.damage_units[eDamage_driver].damage_level >= 80) {
            DamageUnit(&HV(gProgram_state).current_car, eDamage_driver, 2);
        } else {
            DamageUnit(&HV(gProgram_state).current_car, eDamage_driver, 80 - HV(gProgram_state).current_car.damage_units[2].damage_level);
        }
    } else {
        original_TDamageDriver();
    }
}

function_hook_state_t function_hook_state_TDamageTrans = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(TDamageTrans, function_hook_state_TDamageTrans)
static void(__cdecl*original_TDamageTrans)() = (void(__cdecl*)())0x004a12d4;
CARM95_HOOK_FUNCTION(original_TDamageTrans, TDamageTrans)
void __cdecl TDamageTrans() {
    LOG_TRACE("()");


    if (function_hook_state_TDamageTrans == HOOK_ENABLED) {
        DamageTrans(21);
    } else {
        original_TDamageTrans();
    }
}

function_hook_state_t function_hook_state_TDamageSteering = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(TDamageSteering, function_hook_state_TDamageSteering)
static void(__cdecl*original_TDamageSteering)() = (void(__cdecl*)())0x004a12e9;
CARM95_HOOK_FUNCTION(original_TDamageSteering, TDamageSteering)
void __cdecl TDamageSteering() {
    LOG_TRACE("()");


    if (function_hook_state_TDamageSteering == HOOK_ENABLED) {
        DamageSteering(21);
    } else {
        original_TDamageSteering();
    }
}

function_hook_state_t function_hook_state_TDamageLFWheel = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(TDamageLFWheel, function_hook_state_TDamageLFWheel)
static void(__cdecl*original_TDamageLFWheel)() = (void(__cdecl*)())0x004a12fe;
CARM95_HOOK_FUNCTION(original_TDamageLFWheel, TDamageLFWheel)
void __cdecl TDamageLFWheel() {
    LOG_TRACE("()");


    if (function_hook_state_TDamageLFWheel == HOOK_ENABLED) {
        DamageLFWheel(21);
    } else {
        original_TDamageLFWheel();
    }
}

function_hook_state_t function_hook_state_TDamageLFBrake = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(TDamageLFBrake, function_hook_state_TDamageLFBrake)
static void(__cdecl*original_TDamageLFBrake)() = (void(__cdecl*)())0x004a1313;
CARM95_HOOK_FUNCTION(original_TDamageLFBrake, TDamageLFBrake)
void __cdecl TDamageLFBrake() {
    LOG_TRACE("()");


    if (function_hook_state_TDamageLFBrake == HOOK_ENABLED) {
        DamageLFBrake(21);
    } else {
        original_TDamageLFBrake();
    }
}

function_hook_state_t function_hook_state_TDamageLRBrake = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(TDamageLRBrake, function_hook_state_TDamageLRBrake)
static void(__cdecl*original_TDamageLRBrake)() = (void(__cdecl*)())0x004a1328;
CARM95_HOOK_FUNCTION(original_TDamageLRBrake, TDamageLRBrake)
void __cdecl TDamageLRBrake() {
    LOG_TRACE("()");


    if (function_hook_state_TDamageLRBrake == HOOK_ENABLED) {
        DamageLRBrake(21);
    } else {
        original_TDamageLRBrake();
    }
}

function_hook_state_t function_hook_state_TDamageLRWheel = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(TDamageLRWheel, function_hook_state_TDamageLRWheel)
static void(__cdecl*original_TDamageLRWheel)() = (void(__cdecl*)())0x004a133d;
CARM95_HOOK_FUNCTION(original_TDamageLRWheel, TDamageLRWheel)
void __cdecl TDamageLRWheel() {
    LOG_TRACE("()");


    if (function_hook_state_TDamageLRWheel == HOOK_ENABLED) {
        DamageLRWheel(21);
    } else {
        original_TDamageLRWheel();
    }
}

function_hook_state_t function_hook_state_TDamageRFWheel = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(TDamageRFWheel, function_hook_state_TDamageRFWheel)
static void(__cdecl*original_TDamageRFWheel)() = (void(__cdecl*)())0x004a1352;
CARM95_HOOK_FUNCTION(original_TDamageRFWheel, TDamageRFWheel)
void __cdecl TDamageRFWheel() {
    LOG_TRACE("()");


    if (function_hook_state_TDamageRFWheel == HOOK_ENABLED) {
        DamageRFWheel(21);
    } else {
        original_TDamageRFWheel();
    }
}

function_hook_state_t function_hook_state_TDamageRFBrake = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(TDamageRFBrake, function_hook_state_TDamageRFBrake)
static void(__cdecl*original_TDamageRFBrake)() = (void(__cdecl*)())0x004a1367;
CARM95_HOOK_FUNCTION(original_TDamageRFBrake, TDamageRFBrake)
void __cdecl TDamageRFBrake() {
    LOG_TRACE("()");


    if (function_hook_state_TDamageRFBrake == HOOK_ENABLED) {
        DamageRFBrake(21);
    } else {
        original_TDamageRFBrake();
    }
}

function_hook_state_t function_hook_state_TDamageRRBrake = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(TDamageRRBrake, function_hook_state_TDamageRRBrake)
static void(__cdecl*original_TDamageRRBrake)() = (void(__cdecl*)())0x004a137c;
CARM95_HOOK_FUNCTION(original_TDamageRRBrake, TDamageRRBrake)
void __cdecl TDamageRRBrake() {
    LOG_TRACE("()");


    if (function_hook_state_TDamageRRBrake == HOOK_ENABLED) {
        DamageRRBrake(21);
    } else {
        original_TDamageRRBrake();
    }
}

function_hook_state_t function_hook_state_TDamageRRWheel = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(TDamageRRWheel, function_hook_state_TDamageRRWheel)
static void(__cdecl*original_TDamageRRWheel)() = (void(__cdecl*)())0x004a1391;
CARM95_HOOK_FUNCTION(original_TDamageRRWheel, TDamageRRWheel)
void __cdecl TDamageRRWheel() {
    LOG_TRACE("()");


    if (function_hook_state_TDamageRRWheel == HOOK_ENABLED) {
        DamageRRWheel(21);
    } else {
        original_TDamageRRWheel();
    }
}

function_hook_state_t function_hook_state_MoveBonnetForward = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(MoveBonnetForward, function_hook_state_MoveBonnetForward)
static void(__cdecl*original_MoveBonnetForward)() = (void(__cdecl*)())0x004a13a6;
CARM95_HOOK_FUNCTION(original_MoveBonnetForward, MoveBonnetForward)
void __cdecl MoveBonnetForward() {
    LOG_TRACE("()");


    if (function_hook_state_MoveBonnetForward == HOOK_ENABLED) {
        HV(gProgram_state).current_car.car_model_actors[HV(gProgram_state).current_car.car_actor_count - 1].actor->t.t.translate.t.v[2] -= .005f;
    } else {
        original_MoveBonnetForward();
    }
}

function_hook_state_t function_hook_state_SaveBonnet = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(SaveBonnet, function_hook_state_SaveBonnet)
static void(__cdecl*original_SaveBonnet)() = (void(__cdecl*)())0x004a13dd;
CARM95_HOOK_FUNCTION(original_SaveBonnet, SaveBonnet)
void __cdecl SaveBonnet() {
    br_actor *bonny;
    tPath_name the_path;
    LOG_TRACE("()");

    (void)bonny;
    (void)the_path;

    if (function_hook_state_SaveBonnet == HOOK_ENABLED) {
        bonny = HV(gProgram_state).current_car.car_model_actors[HV(gProgram_state).current_car.car_actor_count - 1].actor;
        PathCat(the_path, HV(gApplication_path), bonny->identifier);
        BrActorSave(the_path, bonny);
    } else {
        original_SaveBonnet();
    }
}

function_hook_state_t function_hook_state_MoveBonnetBackward = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(MoveBonnetBackward, function_hook_state_MoveBonnetBackward)
static void(__cdecl*original_MoveBonnetBackward)() = (void(__cdecl*)())0x004a142f;
CARM95_HOOK_FUNCTION(original_MoveBonnetBackward, MoveBonnetBackward)
void __cdecl MoveBonnetBackward() {
    LOG_TRACE("()");


    if (function_hook_state_MoveBonnetBackward == HOOK_ENABLED) {
        HV(gProgram_state).current_car.car_model_actors[HV(gProgram_state).current_car.car_actor_count - 1].actor->t.t.translate.t.v[2] += .005f;
    } else {
        original_MoveBonnetBackward();
    }
}

function_hook_state_t function_hook_state_MoveBonnetLeft = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(MoveBonnetLeft, function_hook_state_MoveBonnetLeft)
static void(__cdecl*original_MoveBonnetLeft)() = (void(__cdecl*)())0x004a1466;
CARM95_HOOK_FUNCTION(original_MoveBonnetLeft, MoveBonnetLeft)
void __cdecl MoveBonnetLeft() {
    LOG_TRACE("()");


    if (function_hook_state_MoveBonnetLeft == HOOK_ENABLED) {
        HV(gProgram_state).current_car.car_model_actors[HV(gProgram_state).current_car.car_actor_count - 1].actor->t.t.translate.t.v[0] -= .005f;
    } else {
        original_MoveBonnetLeft();
    }
}

function_hook_state_t function_hook_state_ShrinkBonnetX = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(ShrinkBonnetX, function_hook_state_ShrinkBonnetX)
static void(__cdecl*original_ShrinkBonnetX)() = (void(__cdecl*)())0x004a149d;
CARM95_HOOK_FUNCTION(original_ShrinkBonnetX, ShrinkBonnetX)
void __cdecl ShrinkBonnetX() {
    LOG_TRACE("()");


    if (function_hook_state_ShrinkBonnetX == HOOK_ENABLED) {
        HV(gProgram_state).current_car.car_model_actors[HV(gProgram_state).current_car.car_actor_count - 1].actor->t.t.mat.m[0][0] *= .98f;
    } else {
        original_ShrinkBonnetX();
    }
}

function_hook_state_t function_hook_state_SwellBonnetX = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(SwellBonnetX, function_hook_state_SwellBonnetX)
static void(__cdecl*original_SwellBonnetX)() = (void(__cdecl*)())0x004a14d4;
CARM95_HOOK_FUNCTION(original_SwellBonnetX, SwellBonnetX)
void __cdecl SwellBonnetX() {
    LOG_TRACE("()");


    if (function_hook_state_SwellBonnetX == HOOK_ENABLED) {
        HV(gProgram_state).current_car.car_model_actors[HV(gProgram_state).current_car.car_actor_count - 1].actor->t.t.mat.m[0][0] *= 1.02f;
    } else {
        original_SwellBonnetX();
    }
}

function_hook_state_t function_hook_state_ShrinkBonnetY = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(ShrinkBonnetY, function_hook_state_ShrinkBonnetY)
static void(__cdecl*original_ShrinkBonnetY)() = (void(__cdecl*)())0x004a150b;
CARM95_HOOK_FUNCTION(original_ShrinkBonnetY, ShrinkBonnetY)
void __cdecl ShrinkBonnetY() {
    LOG_TRACE("()");


    if (function_hook_state_ShrinkBonnetY == HOOK_ENABLED) {
        HV(gProgram_state).current_car.car_model_actors[HV(gProgram_state).current_car.car_actor_count - 1].actor->t.t.mat.m[1][1] *= .98f;
    } else {
        original_ShrinkBonnetY();
    }
}

function_hook_state_t function_hook_state_SwellBonnetY = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(SwellBonnetY, function_hook_state_SwellBonnetY)
static void(__cdecl*original_SwellBonnetY)() = (void(__cdecl*)())0x004a1542;
CARM95_HOOK_FUNCTION(original_SwellBonnetY, SwellBonnetY)
void __cdecl SwellBonnetY() {
    LOG_TRACE("()");


    if (function_hook_state_SwellBonnetY == HOOK_ENABLED) {
        HV(gProgram_state).current_car.car_model_actors[HV(gProgram_state).current_car.car_actor_count - 1].actor->t.t.mat.m[1][1] *= 1.02f;
    } else {
        original_SwellBonnetY();
    }
}

function_hook_state_t function_hook_state_ShrinkBonnetZ = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(ShrinkBonnetZ, function_hook_state_ShrinkBonnetZ)
static void(__cdecl*original_ShrinkBonnetZ)() = (void(__cdecl*)())0x004a1579;
CARM95_HOOK_FUNCTION(original_ShrinkBonnetZ, ShrinkBonnetZ)
void __cdecl ShrinkBonnetZ() {
    LOG_TRACE("()");


    if (function_hook_state_ShrinkBonnetZ == HOOK_ENABLED) {
        HV(gProgram_state).current_car.car_model_actors[HV(gProgram_state).current_car.car_actor_count - 1].actor->t.t.mat.m[2][2] *= .98f;
    } else {
        original_ShrinkBonnetZ();
    }
}

function_hook_state_t function_hook_state_SwellBonnetZ = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(SwellBonnetZ, function_hook_state_SwellBonnetZ)
static void(__cdecl*original_SwellBonnetZ)() = (void(__cdecl*)())0x004a15b0;
CARM95_HOOK_FUNCTION(original_SwellBonnetZ, SwellBonnetZ)
void __cdecl SwellBonnetZ() {
    LOG_TRACE("()");


    if (function_hook_state_SwellBonnetZ == HOOK_ENABLED) {
        HV(gProgram_state).current_car.car_model_actors[HV(gProgram_state).current_car.car_actor_count - 1].actor->t.t.mat.m[2][2] *= 1.02f;
    } else {
        original_SwellBonnetZ();
    }
}

function_hook_state_t function_hook_state_MoveBonnetDown = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(MoveBonnetDown, function_hook_state_MoveBonnetDown)
static void(__cdecl*original_MoveBonnetDown)() = (void(__cdecl*)())0x004a15e7;
CARM95_HOOK_FUNCTION(original_MoveBonnetDown, MoveBonnetDown)
void __cdecl MoveBonnetDown() {
    LOG_TRACE("()");


    if (function_hook_state_MoveBonnetDown == HOOK_ENABLED) {
        HV(gProgram_state).current_car.car_model_actors[HV(gProgram_state).current_car.car_actor_count - 1].actor->t.t.translate.t.v[1] += .005f;
    } else {
        original_MoveBonnetDown();
    }
}

function_hook_state_t function_hook_state_MoveBonnetRight = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(MoveBonnetRight, function_hook_state_MoveBonnetRight)
static void(__cdecl*original_MoveBonnetRight)() = (void(__cdecl*)())0x004a161e;
CARM95_HOOK_FUNCTION(original_MoveBonnetRight, MoveBonnetRight)
void __cdecl MoveBonnetRight() {
    LOG_TRACE("()");


    if (function_hook_state_MoveBonnetRight == HOOK_ENABLED) {
        HV(gProgram_state).current_car.car_model_actors[HV(gProgram_state).current_car.car_actor_count - 1].actor->t.t.translate.t.v[0] += .005f;
    } else {
        original_MoveBonnetRight();
    }
}

function_hook_state_t function_hook_state_MoveBonnetUp = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(MoveBonnetUp, function_hook_state_MoveBonnetUp)
static void(__cdecl*original_MoveBonnetUp)() = (void(__cdecl*)())0x004a1655;
CARM95_HOOK_FUNCTION(original_MoveBonnetUp, MoveBonnetUp)
void __cdecl MoveBonnetUp() {
    LOG_TRACE("()");


    if (function_hook_state_MoveBonnetUp == HOOK_ENABLED) {
        HV(gProgram_state).current_car.car_model_actors[HV(gProgram_state).current_car.car_actor_count - 1].actor->t.t.translate.t.v[1] -= .005f;
    } else {
        original_MoveBonnetUp();
    }
}

function_hook_state_t function_hook_state_TiltBonnetDownX = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(TiltBonnetDownX, function_hook_state_TiltBonnetDownX)
static void(__cdecl*original_TiltBonnetDownX)() = (void(__cdecl*)())0x004a168c;
CARM95_HOOK_FUNCTION(original_TiltBonnetDownX, TiltBonnetDownX)
void __cdecl TiltBonnetDownX() {
    LOG_TRACE("()");


    if (function_hook_state_TiltBonnetDownX == HOOK_ENABLED) {
        BrMatrix34PreRotateX(&HV(gProgram_state).current_car.car_model_actors[HV(gProgram_state).current_car.car_actor_count - 1].actor->t.t.mat, BR_ANGLE_DEG(.5f));
    } else {
        original_TiltBonnetDownX();
    }
}

function_hook_state_t function_hook_state_TiltBonnetUpX = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(TiltBonnetUpX, function_hook_state_TiltBonnetUpX)
static void(__cdecl*original_TiltBonnetUpX)() = (void(__cdecl*)())0x004a16b5;
CARM95_HOOK_FUNCTION(original_TiltBonnetUpX, TiltBonnetUpX)
void __cdecl TiltBonnetUpX() {
    LOG_TRACE("()");


    if (function_hook_state_TiltBonnetUpX == HOOK_ENABLED) {
        BrMatrix34PreRotateX(&HV(gProgram_state).current_car.car_model_actors[HV(gProgram_state).current_car.car_actor_count - 1].actor->t.t.mat, -BR_ANGLE_DEG(.5f));
    } else {
        original_TiltBonnetUpX();
    }
}

function_hook_state_t function_hook_state_TiltBonnetDownY = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(TiltBonnetDownY, function_hook_state_TiltBonnetDownY)
static void(__cdecl*original_TiltBonnetDownY)() = (void(__cdecl*)())0x004a16e1;
CARM95_HOOK_FUNCTION(original_TiltBonnetDownY, TiltBonnetDownY)
void __cdecl TiltBonnetDownY() {
    LOG_TRACE("()");


    if (function_hook_state_TiltBonnetDownY == HOOK_ENABLED) {
        BrMatrix34PreRotateY(&HV(gProgram_state).current_car.car_model_actors[HV(gProgram_state).current_car.car_actor_count - 1].actor->t.t.mat, BR_ANGLE_DEG(.5f));
    } else {
        original_TiltBonnetDownY();
    }
}

function_hook_state_t function_hook_state_TiltBonnetUpY = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(TiltBonnetUpY, function_hook_state_TiltBonnetUpY)
static void(__cdecl*original_TiltBonnetUpY)() = (void(__cdecl*)())0x004a170a;
CARM95_HOOK_FUNCTION(original_TiltBonnetUpY, TiltBonnetUpY)
void __cdecl TiltBonnetUpY() {
    LOG_TRACE("()");


    if (function_hook_state_TiltBonnetUpY == HOOK_ENABLED) {
        BrMatrix34PreRotateY(&HV(gProgram_state).current_car.car_model_actors[HV(gProgram_state).current_car.car_actor_count - 1].actor->t.t.mat, -BR_ANGLE_DEG(.5f));
    } else {
        original_TiltBonnetUpY();
    }
}

function_hook_state_t function_hook_state_TiltBonnetDownZ = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(TiltBonnetDownZ, function_hook_state_TiltBonnetDownZ)
static void(__cdecl*original_TiltBonnetDownZ)() = (void(__cdecl*)())0x004a1736;
CARM95_HOOK_FUNCTION(original_TiltBonnetDownZ, TiltBonnetDownZ)
void __cdecl TiltBonnetDownZ() {
    LOG_TRACE("()");


    if (function_hook_state_TiltBonnetDownZ == HOOK_ENABLED) {
        BrMatrix34PreRotateZ(&HV(gProgram_state).current_car.car_model_actors[HV(gProgram_state).current_car.car_actor_count - 1].actor->t.t.mat, BR_ANGLE_DEG(.5f));
    } else {
        original_TiltBonnetDownZ();
    }
}

function_hook_state_t function_hook_state_TiltBonnetUpZ = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(TiltBonnetUpZ, function_hook_state_TiltBonnetUpZ)
static void(__cdecl*original_TiltBonnetUpZ)() = (void(__cdecl*)())0x004a175f;
CARM95_HOOK_FUNCTION(original_TiltBonnetUpZ, TiltBonnetUpZ)
void __cdecl TiltBonnetUpZ() {
    LOG_TRACE("()");


    if (function_hook_state_TiltBonnetUpZ == HOOK_ENABLED) {
        BrMatrix34PreRotateZ(&HV(gProgram_state).current_car.car_model_actors[HV(gProgram_state).current_car.car_actor_count - 1].actor->t.t.mat, -BR_ANGLE_DEG(.5f));
    } else {
        original_TiltBonnetUpZ();
    }
}

function_hook_state_t function_hook_state_ToggleCockpit = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(ToggleCockpit, function_hook_state_ToggleCockpit)
static void(__cdecl*original_ToggleCockpit)() = (void(__cdecl*)())0x004a178b;
CARM95_HOOK_FUNCTION(original_ToggleCockpit, ToggleCockpit)
void __cdecl ToggleCockpit() {
    br_scalar ts;
    LOG_TRACE("()");

    (void)ts;

    if (function_hook_state_ToggleCockpit == HOOK_ENABLED) {
        if ((&HV(gProgram_state).current_car == HV(gCar_to_view) || HV(gProgram_state).cockpit_on) && !HV(gMap_mode)) {
            if (!HV(gAusterity_mode) || HV(gProgram_state).cockpit_on) {
                HV(gProgram_state).cockpit_on = !HV(gProgram_state).cockpit_on;
                if (HV(gProgram_state).cockpit_on) {
                    HV(gCamera) = HV(gCamera_list)[0];
                } else {
                    HV(gCamera) = HV(gCamera_list)[1];
                    InitialiseExternalCamera();
                    PositionExternalCamera(&HV(gProgram_state).current_car, 1);
                }
                AdjustRenderScreenSize();
                AdjustHeadups();
                MungeForwardSky();
            } else {
                NewTextHeadupSlot(4, 0, 1000, -4, GetMiscString(192));
            }
        }
    } else {
        original_ToggleCockpit();
    }
}

function_hook_state_t function_hook_state_ToggleMirror = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(ToggleMirror, function_hook_state_ToggleMirror)
static void(__cdecl*original_ToggleMirror)() = (void(__cdecl*)())0x004a1895;
CARM95_HOOK_FUNCTION(original_ToggleMirror, ToggleMirror)
void __cdecl ToggleMirror() {
    LOG_TRACE("()");


    if (function_hook_state_ToggleMirror == HOOK_ENABLED) {
        HV(gProgram_state).mirror_on = !HV(gProgram_state).mirror_on;
        ReinitialiseRearviewCamera();
        if (HV(gProgram_state).mirror_on) {
            NewTextHeadupSlot(4, 0, 500, -4, GetMiscString(2));
        } else {
            NewTextHeadupSlot(4, 0, 500, -4, GetMiscString(3));
        }
    } else {
        original_ToggleMirror();
    }
}

function_hook_state_t function_hook_state_ConcussMe = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(ConcussMe, function_hook_state_ConcussMe)
static void(__cdecl*original_ConcussMe)() = (void(__cdecl*)())0x004a1919;
CARM95_HOOK_FUNCTION(original_ConcussMe, ConcussMe)
void __cdecl ConcussMe() {
    LOG_TRACE("()");


    if (function_hook_state_ConcussMe == HOOK_ENABLED) {
        SufferFromConcussion(1.f);
        NewScreenWobble(IRandomPosNeg(15), IRandomPosNeg(10), IRandomBetween(10, 60));
        PratcamEvent(3);
    } else {
        original_ConcussMe();
    }
}

function_hook_state_t function_hook_state_CheckHelp = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(CheckHelp, function_hook_state_CheckHelp)
static void(__cdecl*original_CheckHelp)() = (void(__cdecl*)())0x004a29aa;
CARM95_HOOK_FUNCTION(original_CheckHelp, CheckHelp)
void __cdecl CheckHelp() {
    LOG_TRACE("()");


    if (function_hook_state_CheckHelp == HOOK_ENABLED) {
        assert(0 && "CheckHelp not implemented.");
        abort();
    } else {
        original_CheckHelp();
    }
}

function_hook_state_t function_hook_state_CheckLoadSave = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(CheckLoadSave, function_hook_state_CheckLoadSave)
static void(__cdecl*original_CheckLoadSave)() = (void(__cdecl*)())0x004a29b5;
CARM95_HOOK_FUNCTION(original_CheckLoadSave, CheckLoadSave)
void __cdecl CheckLoadSave() {
    int save_load_allowed;
    int switched_res;
    LOG_TRACE("()");

    (void)save_load_allowed;
    (void)switched_res;

    if (function_hook_state_CheckLoadSave == HOOK_ENABLED) {
        save_load_allowed = !HV(gProgram_state).saving && !HV(gProgram_state).loading && HV(gProgram_state).prog_status == eProg_game_ongoing && !HV(gProgram_state).dont_save_or_load;

        if (CmdKeyDown(KEYMAP_SAVE, KEYMAP_CTRL_SAVE)) {
            if (save_load_allowed) {
                FadePaletteDown();
                ClearEntireScreen();
                if (HV(gProgram_state).racing) {
                    GoingToInterfaceFromRace();
                }
                DoSaveGame(HV(gProgram_state).racing == 0);
                if (HV(gProgram_state).racing) {
                    GoingBackToRaceFromInterface();
                }
            }
            WaitForNoKeys();
        }
        if (CmdKeyDown(KEYMAP_LOAD, KEYMAP_CTRL_LOAD)) {
            if (save_load_allowed && !HV(gProgram_state).dont_load) {
                FadePaletteDown();
                ClearEntireScreen();
                if (HV(gProgram_state).racing) {
                    GoingToInterfaceFromRace();
                }
                if (DoLoadGame() && !HV(gProgram_state).racing) {
                    HV(gProgram_state).prog_status = eProg_game_starting;
                }
                if (HV(gProgram_state).racing) {
                    GoingBackToRaceFromInterface();
                }
                PlayFlicsFromMemory();
            }
            WaitForNoKeys();
        }
    } else {
        original_CheckLoadSave();
    }
}

function_hook_state_t function_hook_state_CheckToggles = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(CheckToggles, function_hook_state_CheckToggles)
static void(__cdecl*original_CheckToggles)(int) = (void(__cdecl*)(int))0x004a198a;
CARM95_HOOK_FUNCTION(original_CheckToggles, CheckToggles)
void __cdecl CheckToggles(int pRacing) {
    int i;
    int new_state;
    LOG_TRACE("(%d)", pRacing);

    (void)pRacing;
    (void)i;
    (void)new_state;

    if (function_hook_state_CheckToggles == HOOK_ENABLED) {
        for (i = 0; i < COUNT_OF(HV(gToggle_array)); i++) {
            if ((!HV(gToggle_array)[i].in_game_only || pRacing)
                && ((!HV(gTyping) && !HV(gEntering_message)) || HV(gToggle_array)[i].key2 != -2)) {
                new_state = 0;
                if (HV(gToggle_array)[i].key1 == -2 || KeyIsDown(HV(gToggle_array)[i].key1)) {
                    if (HV(gToggle_array)[i].key2 == -2 && HV(gToggle_array)[i].exact_modifiers) {
                        if (!PDKeyDown(KEY_SHIFT_ANY) && !PDKeyDown(KEY_ALT_ANY) && !PDKeyDown(KEY_CTRL_ANY) && !PDKeyDown(KEY_CTRL_ANY_2)) {
                            new_state = 1;
                        }
                    } else {
                        if (KeyIsDown(HV(gToggle_array)[i].key2)) {
                            new_state = 1;
                        }
                    }
                }
                if (HV(gToggle_array)[i].on_last_time != new_state) {
                    HV(gToggle_array)[i].on_last_time = new_state;
                    if (new_state) {
                        HV(gToggle_array)[i].action_proc();
                    }
                }
            }
        }
    } else {
        original_CheckToggles(pRacing);
    }
}

function_hook_state_t function_hook_state_CarWorldOffFallenCheckThingy = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(CarWorldOffFallenCheckThingy, function_hook_state_CarWorldOffFallenCheckThingy)
static int(__cdecl*original_CarWorldOffFallenCheckThingy)(tCar_spec *, int) = (int(__cdecl*)(tCar_spec *, int))0x004a1b4d;
CARM95_HOOK_FUNCTION(original_CarWorldOffFallenCheckThingy, CarWorldOffFallenCheckThingy)
int __cdecl CarWorldOffFallenCheckThingy(tCar_spec *pCar, int pCheck_around) {
    br_vector3 car_pos;
    br_vector3 offset_c;
    br_vector3 offset_w;
    int result;
    LOG_TRACE("(%p, %d)", pCar, pCheck_around);

    (void)pCar;
    (void)pCheck_around;
    (void)car_pos;
    (void)offset_c;
    (void)offset_w;
    (void)result;

    if (function_hook_state_CarWorldOffFallenCheckThingy == HOOK_ENABLED) {
        if (pCar->number_of_wheels_on_ground != 0) {
            return 0;
        }
        if (pCar->driver == eDriver_local_human && HV(gCar_flying)) {
            return 0;
        }
        if (HV(gAction_replay_mode)) {
            return 0;
        }
        BrVector3Copy(&car_pos, &pCar->car_master_actor->t.t.translate.t);
        if (FindYVerticallyBelow2(&car_pos) >= -100.f) {
            return 0;
        }
        BrVector3Set(&offset_c, 0.f, 1.f, 0.f);
        BrMatrix34ApplyV(&offset_w, &offset_c, &pCar->car_master_actor->t.t.mat);
        if (FindYVerticallyBelow2(&car_pos) >= -100.f) {
            // FIXME: testing twice using `FindYVerticallyBelow2' is meaningless
            return 0;
        }
        if (!pCheck_around) {
            return 1;
        }
        pCar->car_master_actor->t.t.translate.t.v[0] += 0.05f;
        result = CarWorldOffFallenCheckThingy(pCar, 0);
        pCar->car_master_actor->t.t.translate.t.v[0] -= 0.05f;
        if (!result) {
            return 0;
        }
        pCar->car_master_actor->t.t.translate.t.v[2] += 0.05f;
        result = CarWorldOffFallenCheckThingy(pCar, 0);
        pCar->car_master_actor->t.t.translate.t.v[2] -= 0.05f;
        if (!result) {
            return 0;
        }
        return 1;
    } else {
        return original_CarWorldOffFallenCheckThingy(pCar, pCheck_around);
    }
}

function_hook_state_t function_hook_state_HasCarFallenOffWorld = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(HasCarFallenOffWorld, function_hook_state_HasCarFallenOffWorld)
static int(__cdecl*original_HasCarFallenOffWorld)(tCar_spec *) = (int(__cdecl*)(tCar_spec *))0x004a1b2f;
CARM95_HOOK_FUNCTION(original_HasCarFallenOffWorld, HasCarFallenOffWorld)
int __cdecl HasCarFallenOffWorld(tCar_spec *pCar) {
    LOG_TRACE("(%p)", pCar);

    (void)pCar;

    if (function_hook_state_HasCarFallenOffWorld == HOOK_ENABLED) {
        return CarWorldOffFallenCheckThingy(pCar, 1);
    } else {
        return original_HasCarFallenOffWorld(pCar);
    }
}

function_hook_state_t function_hook_state_CheckForBeingOutOfThisWorld = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(CheckForBeingOutOfThisWorld, function_hook_state_CheckForBeingOutOfThisWorld)
static void(__cdecl*original_CheckForBeingOutOfThisWorld)() = (void(__cdecl*)())0x004a3328;
CARM95_HOOK_FUNCTION(original_CheckForBeingOutOfThisWorld, CheckForBeingOutOfThisWorld)
void __cdecl CheckForBeingOutOfThisWorld() {
    static tU32 the_time;
    static tU32 sLast_check;
    int time_step;
    LOG_TRACE("()");

    (void)the_time;
    (void)sLast_check;
    (void)time_step;

    if (function_hook_state_CheckForBeingOutOfThisWorld == HOOK_ENABLED) {
        the_time = PDGetTotalTime();

        if (HV(gRecover_timer) == 0 || ((HV(gProgram_state).current_car.frame_collision_flag || HV(gProgram_state).current_car.number_of_wheels_on_ground) && !IsCarInTheSea())) {
            HV(gRecover_timer) = 0;
            if ((the_time - sLast_check) > 200) {
                sLast_check = the_time;
                if (HasCarFallenOffWorld(&HV(gProgram_state).current_car)) {
                    HV(gRecover_timer) = 3000;
                }
            }
            if (IsCarInTheSea()) {
                if (!HV(gRecover_timer)) {
                    HV(gRecover_timer) = 3000;
                }
            }
            return;
        }
        HV(gRecover_timer) -= HV(gFrame_period);
        if (HV(gRecover_timer) <= 0 || IsCarInTheSea() == 2) {
            HV(gRecover_timer) = 0;
            RecoverCar();
            HV(gHad_auto_recover) = 1;
        }
    } else {
        original_CheckForBeingOutOfThisWorld();
    }
}

function_hook_state_t function_hook_state_CheckHornLocal = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(CheckHornLocal, function_hook_state_CheckHornLocal)
static void(__cdecl*original_CheckHornLocal)(tCar_spec *) = (void(__cdecl*)(tCar_spec *))0x004a34a8;
CARM95_HOOK_FUNCTION(original_CheckHornLocal, CheckHornLocal)
void __cdecl CheckHornLocal(tCar_spec *pCar) {
    LOG_TRACE("(%p)", pCar);

    (void)pCar;

    if (function_hook_state_CheckHornLocal == HOOK_ENABLED) {
        if (pCar->keys.horn == 1 && pCar->horn_sound_tag == 0) {
            pCar->horn_sound_tag = DRS3StartSound(HV(gEffects_outlet), 5209);
        } else if (pCar->keys.horn == 0 && pCar->horn_sound_tag != 0) {
            if (S3SoundStillPlaying(pCar->horn_sound_tag) != 0) {
                DRS3StopSound(pCar->horn_sound_tag);
                DRS3StopOutletSound(HV(gEffects_outlet));
            }
            if (S3SoundStillPlaying(pCar->horn_sound_tag) == 0) {
                pCar->horn_sound_tag = 0;
            }
        }
    } else {
        original_CheckHornLocal(pCar);
    }
}

function_hook_state_t function_hook_state_CheckHorn3D = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(CheckHorn3D, function_hook_state_CheckHorn3D)
static void(__cdecl*original_CheckHorn3D)(tCar_spec *) = (void(__cdecl*)(tCar_spec *))0x004a3582;
CARM95_HOOK_FUNCTION(original_CheckHorn3D, CheckHorn3D)
void __cdecl CheckHorn3D(tCar_spec *pCar) {
    LOG_TRACE("(%p)", pCar);

    (void)pCar;

    if (function_hook_state_CheckHorn3D == HOOK_ENABLED) {
        assert(0 && "CheckHorn3D not implemented.");
        abort();
    } else {
        original_CheckHorn3D(pCar);
    }
}

function_hook_state_t function_hook_state_CheckHorns = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(CheckHorns, function_hook_state_CheckHorns)
static void(__cdecl*original_CheckHorns)() = (void(__cdecl*)())0x004a343d;
CARM95_HOOK_FUNCTION(original_CheckHorns, CheckHorns)
void __cdecl CheckHorns() {
    int i;
    LOG_TRACE("()");

    (void)i;

    if (function_hook_state_CheckHorns == HOOK_ENABLED) {
        if (HV(gNet_mode) != eNet_mode_none) {
            for (i = 0; i < HV(gNumber_of_net_players); i++) {
                CheckHorn3D(HV(gNet_players)[i].car);
            }
        } else {
            CheckHornLocal(&HV(gProgram_state).current_car);
        }
    } else {
        original_CheckHorns();
    }
}

function_hook_state_t function_hook_state_SetRecovery = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(SetRecovery, function_hook_state_SetRecovery)
static void(__cdecl*original_SetRecovery)() = (void(__cdecl*)())0x004a1d13;
CARM95_HOOK_FUNCTION(original_SetRecovery, SetRecovery)
void __cdecl SetRecovery() {
    LOG_TRACE("()");


    if (function_hook_state_SetRecovery == HOOK_ENABLED) {
        if (HV(gRace_finished)
            || HV(gProgram_state).current_car.knackered
            || HV(gWait_for_it)
            || HV(gHad_auto_recover)
            || HV(gPalette_fade_time)) {
            return;
        }

        if (HV(gNet_mode) == eNet_mode_none) {
            HV(gRecover_car) = 1;
            HV(gRecover_timer) = 0;
            return;
        }
        if (HV(gProgram_state).current_car.time_to_recover) {
            if (GetRaceTime() + 600 >= HV(gProgram_state).current_car.time_to_recover) {
                NewTextHeadupSlot2(4, 0, 2000, -4, GetMiscString(242), 1);
                HV(gToo_late) = 1;
            } else {
                HV(gProgram_state).current_car.time_to_recover = 0;
                NewTextHeadupSlot2(4, 0, 2000, -4, GetMiscString(125), 0);
            }
            return;
        }
        if (!CheckRecoverCost()) {
            return;
        }
        if (HV(gCurrent_net_game)->type == eNet_game_type_foxy) {
            if (HV(gThis_net_player_index) == HV(gIt_or_fox)) {
                HV(gProgram_state).current_car.time_to_recover = GetRaceTime() + 5000;
                HV(gRecover_timer) = 0;
                HV(gToo_late) = 0;
                return;
            }
        } else {
            if (HV(gCurrent_net_game)->type != eNet_game_type_tag) {
                HV(gProgram_state).current_car.time_to_recover = GetRaceTime() + 3000;
                HV(gRecover_timer) = 0;
                HV(gToo_late) = 0;
                return;
            }
            if (HV(gThis_net_player_index) != HV(gIt_or_fox)) {
                HV(gProgram_state).current_car.time_to_recover = GetRaceTime() + 5000;
                HV(gRecover_timer) = 0;
                HV(gToo_late) = 0;
                return;
            }
        }
        HV(gProgram_state).current_car.time_to_recover = GetRaceTime() + 1000;
        HV(gRecover_timer) = 0;
        HV(gToo_late) = 0;
    } else {
        original_SetRecovery();
    }
}

function_hook_state_t function_hook_state_RecoverCar = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(RecoverCar, function_hook_state_RecoverCar)
static void(__cdecl*original_RecoverCar)() = (void(__cdecl*)())0x004a20b0;
CARM95_HOOK_FUNCTION(original_RecoverCar, RecoverCar)
void __cdecl RecoverCar() {
    LOG_TRACE("()");


    if (function_hook_state_RecoverCar == HOOK_ENABLED) {
        if (HV(gNet_mode) == eNet_mode_none || !HV(gPalette_fade_time)) {
            HV(gRecover_car) = 1;
        }
        HV(gProgram_state).current_car.time_to_recover = 0;
    } else {
        original_RecoverCar();
    }
}

function_hook_state_t function_hook_state_CheckMapRenderMove = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(CheckMapRenderMove, function_hook_state_CheckMapRenderMove)
static void(__cdecl*original_CheckMapRenderMove)() = (void(__cdecl*)())0x004a3694;
CARM95_HOOK_FUNCTION(original_CheckMapRenderMove, CheckMapRenderMove)
void __cdecl CheckMapRenderMove() {
    int shift_down;
    int amount;
    float old_x;
    float old_y;
    LOG_TRACE("()");

    (void)shift_down;
    (void)amount;
    (void)old_x;
    (void)old_y;

    if (function_hook_state_CheckMapRenderMove == HOOK_ENABLED) {
        old_y = HV(gMap_render_y);
        old_x = HV(gMap_render_x);
        if (HV(gMap_mode)) {
            amount = HV(gFrame_period) * .1f;
            if (KeyIsDown(30)) {
                HV(gMap_render_y) -= amount;
            } else if (KeyIsDown(31)) {
                HV(gMap_render_y) += amount;
            }
            if (KeyIsDown(32)) {
                HV(gMap_render_x) -= amount;
            } else if (KeyIsDown(33)) {
                HV(gMap_render_x) += amount;
            }
            if (HV(gMap_render_x) != old_x || HV(gMap_render_y) != old_y) {
                SetIntegerMapRenders();
                if (HV(gMap_render_x_i) < HV(gCurrent_graf_data)->map_render_x_marg) {
                    if (HV(gReal_graf_data_index) == 0) {
                        HV(gMap_render_x) = (HV(gCurrent_graf_data)->map_render_x_marg + 3) & ~3;
                    } else {
                        HV(gMap_render_x) = ((HV(gCurrent_graf_data)->map_render_x_marg + 3) & ~3) / 2;
                    }
                }
                if (HV(gMap_render_y_i) < HV(gCurrent_graf_data)->map_render_y_marg) {
                    if (HV(gReal_graf_data_index) == 0) {
                        HV(gMap_render_y) = (HV(gCurrent_graf_data)->map_render_y_marg + 1) & ~1;
                    } else {
                        HV(gMap_render_y) = (((HV(gCurrent_graf_data)->map_render_y_marg + 1) & ~1) - 40) / 2;
                    }
                }
                if (HV(gBack_screen)->width - HV(gCurrent_graf_data)->map_render_x_marg - HV(gMap_render_width_i) < HV(gMap_render_x_i)) {
                    if (HV(gReal_graf_data_index) == 0) {
                        HV(gMap_render_x) = (HV(gBack_screen)->width - HV(gCurrent_graf_data)->map_render_x_marg - HV(gMap_render_width_i)) & ~3;
                    } else {
                        HV(gMap_render_x) = ((HV(gBack_screen)->width - HV(gCurrent_graf_data)->map_render_x_marg - HV(gMap_render_width_i)) & ~3) / 2;
                    }
                }
                if (HV(gBack_screen)->height - HV(gCurrent_graf_data)->map_render_y_marg - HV(gMap_render_height_i) < HV(gMap_render_y_i)) {
                    if (HV(gReal_graf_data_index) == 0) {
                        HV(gMap_render_y) = (HV(gBack_screen)->height - HV(gCurrent_graf_data)->map_render_y_marg - HV(gMap_render_height_i)) & ~1;
                    } else {
                        HV(gMap_render_y) = (((HV(gBack_screen)->height - HV(gCurrent_graf_data)->map_render_y_marg - HV(gMap_render_height_i)) & ~3) - 40) / 2;
                    }
                }
                SetIntegerMapRenders();
                AdjustRenderScreenSize();
            }
        }
    } else {
        original_CheckMapRenderMove();
    }
}

function_hook_state_t function_hook_state_ExplodeCar = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(ExplodeCar, function_hook_state_ExplodeCar)
static void(__cdecl*original_ExplodeCar)(tCar_spec *) = (void(__cdecl*)(tCar_spec *))0x004a20e9;
CARM95_HOOK_FUNCTION(original_ExplodeCar, ExplodeCar)
void __cdecl ExplodeCar(tCar_spec *pCar) {
    br_vector3 tv;
    br_vector3 pos;
    LOG_TRACE("(%p)", pCar);

    (void)pCar;
    (void)tv;
    (void)pos;

    if (function_hook_state_ExplodeCar == HOOK_ENABLED) {
        pCar->last_car_car_collision = 0;
        pos.v[0] = .1449275f * pCar->cmpos.v[0];
        pos.v[1] = .1449275f * pCar->cmpos.v[1];
        pos.v[2] = pCar->bounds[0].min.v[2] + .3f * (pCar->bounds[0].max.v[2] - pCar->bounds[0].min.v[2]);
        BrMatrix34ApplyP(&tv, &pos, &pCar->car_master_actor->t.t.mat);
        CreatePuffOfSmoke(&tv, &pCar->v, 1.f, 1.f, 7, pCar);

        pos.v[2] = pCar->bounds[0].min.v[2] + .7f * (pCar->bounds[0].max.v[2] - pCar->bounds[0].min.v[2]);
        BrMatrix34ApplyP(&tv, &pos, &pCar->car_master_actor->t.t.mat);
        CreatePuffOfSmoke(&tv, &pCar->v, 1.f, 1.f, 7, pCar);

        DisableCar(pCar);
    } else {
        original_ExplodeCar(pCar);
    }
}

function_hook_state_t function_hook_state_CheckRecoveryOfCars = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(CheckRecoveryOfCars, function_hook_state_CheckRecoveryOfCars)
static void(__cdecl*original_CheckRecoveryOfCars)(tU32) = (void(__cdecl*)(tU32))0x004a1ec9;
CARM95_HOOK_FUNCTION(original_CheckRecoveryOfCars, CheckRecoveryOfCars)
void __cdecl CheckRecoveryOfCars(tU32 pEndFrameTime) {
    int i;
    int time;
    char s[256];
    LOG_TRACE("(%u)", pEndFrameTime);

    (void)pEndFrameTime;
    (void)i;
    (void)time;
    (void)s;

    if (function_hook_state_CheckRecoveryOfCars == HOOK_ENABLED) {
        if (HV(gProgram_state).current_car.time_to_recover) {
            if (HV(gProgram_state).current_car.knackered) {
                HV(gProgram_state).current_car.time_to_recover = 0;
            } else {
                time = (HV(gProgram_state).current_car.time_to_recover - pEndFrameTime + 1000) / 1000;
                sprintf(s, "%s %d %s", GetMiscString(97), time, time > 1 ? GetMiscString(99) : GetMiscString(98));
                if (!HV(gToo_late)) {
                    NewTextHeadupSlot2(4, 0, 2000, -4, s, 0);
                }
                if (HV(gProgram_state).current_car.time_to_recover <= pEndFrameTime) {
                    RecoverCar();
                }
            }
        }
        if (HV(gNet_mode)) {
            for (i = 0; i < HV(gNumber_of_net_players); i++) {
                if (HV(gThis_net_player_index) != i && HV(gNet_players)[i].car->time_to_recover && HV(gNet_players)[i].car->time_to_recover <= pEndFrameTime) {
                    HV(gNet_players)[i].player_status = ePlayer_status_recovering;
                    HV(gNet_players)[i].car->message.type = 32;
                    HV(gNet_players)[i].car->message.time = pEndFrameTime;
                    ExplodeCar(HV(gNet_players)[i].car);
                    HV(gNet_players)[i].car->time_to_recover = 0;
                }
            }
        }
    } else {
        original_CheckRecoveryOfCars(pEndFrameTime);
    }
}

function_hook_state_t function_hook_state_LoseSomePSPowerups = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(LoseSomePSPowerups, function_hook_state_LoseSomePSPowerups)
static void(__cdecl*original_LoseSomePSPowerups)(int) = (void(__cdecl*)(int))0x004a39cc;
CARM95_HOOK_FUNCTION(original_LoseSomePSPowerups, LoseSomePSPowerups)
void __cdecl LoseSomePSPowerups(int pNumber) {
    int index;
    LOG_TRACE("(%d)", pNumber);

    (void)pNumber;
    (void)index;

    if (function_hook_state_LoseSomePSPowerups == HOOK_ENABLED) {
        if (HV(gNet_mode) != eNet_mode_none && pNumber > 0) {
            while (pNumber--) {
                index = IRandomBetween(0, 2);
                if (HV(gProgram_state).current_car.power_up_levels[index]) {
                    HV(gProgram_state).current_car.power_up_levels[index]--;
                }
            }
        }
    } else {
        original_LoseSomePSPowerups(pNumber);
    }
}

function_hook_state_t function_hook_state_CheckOtherRacingKeys = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(CheckOtherRacingKeys, function_hook_state_CheckOtherRacingKeys)
static void(__cdecl*original_CheckOtherRacingKeys)() = (void(__cdecl*)())0x004a2af6;
CARM95_HOOK_FUNCTION(original_CheckOtherRacingKeys, CheckOtherRacingKeys)
void __cdecl CheckOtherRacingKeys() {
    int i;
    int j;
    int new_level;
    int old_level;
    char s[256];
    tU32 cost;
    br_scalar ts;
    br_vector3 tv;
    int flip_up_flag;
    tCar_spec *car;
    float bodywork_repair_amount;
    static tU32 total_repair_cost;
    static tS3_sound_tag sound_tag;
    static br_scalar amount;
    static int NeedToExpandBoundingBox;
    static int total_difference;
    static int stopped_repairing;
    int __block0__loop;
    LOG_TRACE("()");

    (void)i;
    (void)j;
    (void)new_level;
    (void)old_level;
    (void)s;
    (void)cost;
    (void)ts;
    (void)tv;
    (void)flip_up_flag;
    (void)car;
    (void)bodywork_repair_amount;
    (void)total_repair_cost;
    (void)sound_tag;
    (void)amount;
    (void)NeedToExpandBoundingBox;
    (void)total_difference;
    (void)stopped_repairing;
    (void)__block0__loop;

    if (function_hook_state_CheckOtherRacingKeys == HOOK_ENABLED) {
        car = GetCarSpec(eVehicle_self, 0);
        CheckMapRenderMove();
        CheckHorns();
        CheckForBeingOutOfThisWorld();
        if (HV(gPalette_fade_time)) {
            SortOutRecover(car);
        } else if (HV(gNet_mode) && NetGetPlayerStatus() == ePlayer_status_recovering) {
            NetPlayerStatusChanged(ePlayer_status_racing);
        }

        if ((HV(gAuto_repair) || KeyIsDown(KEYMAP_REPAIR)) && !HV(gRace_finished) && !HV(gProgram_state).current_car.knackered && !HV(gWait_for_it) && !HV(gEntering_message)) {
            if (!HV(gAuto_repair) && HV(gRepair_last_time) == 0 && GetTotalTime() - HV(gLast_repair_time) < 1200) {
                HV(gAuto_repair) = 1;
            }
            HV(gLast_repair_time) = GetTotalTime();
            HV(gRepair_last_time) = 1;
            if (!NeedToExpandBoundingBox) {
                if (HV(gFree_repairs)
                    || HV(gNet_mode) == eNet_mode_none
                    || HV(gProgram_state).credits_earned - HV(gProgram_state).credits_lost >= 1) {
                    bodywork_repair_amount = RepairCar(HV(gProgram_state).current_car.car_ID, HV(gFrame_period), &amount);
                    NeedToExpandBoundingBox = bodywork_repair_amount > 0;
                    cost = 0;
                    for (j = 0; j < COUNT_OF(HV(gProgram_state).current_car.damage_units); j++) {
                        old_level = HV(gProgram_state).current_car.damage_units[j].damage_level;
                        if (amount == 0.0f) {
                            new_level = 0;
                        } else {
                            new_level = ((double)HV(gProgram_state).current_car.damage_units[j].damage_level
                                         - floor(bodywork_repair_amount / amount * (double)HV(gProgram_state).current_car.damage_units[j].damage_level));
                        }
                        if (new_level >= 0) {
                            if (new_level < 100) {
                                HV(gProgram_state).current_car.damage_units[j].damage_level = new_level;
                            } else {
                                HV(gProgram_state).current_car.damage_units[j].damage_level = 99;
                            }
                        } else {
                            HV(gProgram_state).current_car.damage_units[j].damage_level = 0;
                        }
                        HV(gProgram_state).current_car.damage_units[j].smoke_last_level = HV(gProgram_state).current_car.damage_units[j].damage_level;
                        if (HV(gNet_mode)) {
                            ts = HV(gNet_repair_cost)[HV(gCurrent_net_game)->type];
                        } else {
                            ts = HV(gRepair_cost)[HV(gProgram_state).skill_level];
                        }
                        cost = (old_level - HV(gProgram_state).current_car.damage_units[j].damage_level) * ts + cost;
                        total_difference += old_level - new_level;
                    }
                    if (!HV(gFree_repairs)) {
                        LoseSomePSPowerups(total_difference / 100);
                    }
                    total_difference %= 100;
                    cost = 10 * (cost / 10);
                    if (((!total_repair_cost && cost) || bodywork_repair_amount != 0.0f) && !sound_tag) {
                        sound_tag = DRS3StartSound(HV(gCar_outlet), 5200);
                    }
                    if (HV(gProgram_state).current_car.num_smoke_columns) {
                        StopCarSmoking(&HV(gProgram_state).current_car);
                    }
                    if (!cost && bodywork_repair_amount == 0.0) {
                        HV(gAuto_repair) = 0;
                    }
                    if (!HV(gFree_repairs)) {
                        cost += SpendCredits(cost);
                    }
                    total_repair_cost += cost;
                    if (total_repair_cost) {
                        if (HV(gFree_repairs)) {
                            NewTextHeadupSlot(4, 0, 1000, -4, GetMiscString(4));
                        } else {
                            sprintf(s, "%s %d", GetMiscString(5), total_repair_cost);
                            NewTextHeadupSlot(4, 0, 1000, -4, s);
                        }
                    }
                } else {
                    if (!stopped_repairing) {
                        NewTextHeadupSlot(4, 0, 1000, -4, GetMiscString(95));
                    }
                    HV(gAuto_repair) = 0;
                    stopped_repairing = 1;
                }
            }

        } else {
            HV(gRepair_last_time) = 0;
            stopped_repairing = 0;
            total_repair_cost = 0;
            total_difference = 0;
            if (sound_tag) {
                for (i = 0; i < 10 && S3SoundStillPlaying(sound_tag); ++i) {
                    DRS3StopSound(sound_tag);
                }
                sound_tag = 0;
            }
        }
        if (NeedToExpandBoundingBox) {
            NeedToExpandBoundingBox = ExpandBoundingBox(&HV(gProgram_state).current_car) == 0;
        }
        if (!HV(gRecover_car) || HV(gProgram_state).current_car.knackered) {
            HV(gHad_auto_recover) = 0;
        } else if (CheckRecoverCost()) {
            HV(gRecover_timer) = 0;
            SetFlipUpCar(car);
            if (HV(gNet_mode) != eNet_mode_none) {
                NewTextHeadupSlot(4, 0, 1500, -4, " ");
            }
            if (HV(gRecovery_voucher_count) != 0) {
                HV(gRecovery_voucher_count)--;
                sprintf(s, "%s", GetMiscString(48));
                NewTextHeadupSlot(4, 0, 1500, -4, s);
            } else {
                if (HV(gNet_mode)) {
                    cost = HV(gNet_recovery_cost)[HV(gCurrent_net_game)->type];
                } else {
                    cost = HV(gRecovery_cost)[HV(gProgram_state).skill_level];
                }
                SpendCredits(cost);
                if (HV(gNet_mode)) {
                    cost = HV(gNet_recovery_cost)[HV(gCurrent_net_game)->type];
                } else {
                    cost = HV(gRecovery_cost)[HV(gProgram_state).skill_level];
                }
                sprintf(s, "%s %d", GetMiscString(7), cost);
                NewTextHeadupSlot(4, 0, 1500, -4, s);
                LoseSomePSPowerups(2);
            }
            CancelPendingCunningStunt();
            PipeSingleSpecial(ePipe_special_fade);
        }
        HV(gRecover_car) = 0;
    } else {
        original_CheckOtherRacingKeys();
    }
}

function_hook_state_t function_hook_state_CheckRecoverCost = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(CheckRecoverCost, function_hook_state_CheckRecoverCost)
static int(__cdecl*original_CheckRecoverCost)() = (int(__cdecl*)())0x004a2208;
CARM95_HOOK_FUNCTION(original_CheckRecoverCost, CheckRecoverCost)
int __cdecl CheckRecoverCost() {
    LOG_TRACE("()");


    if (function_hook_state_CheckRecoverCost == HOOK_ENABLED) {
        if (HV(gProgram_state).current_car.knackered
            || HV(gNet_mode) == eNet_mode_none
            || (HV(gProgram_state).credits_earned - HV(gProgram_state).credits_lost) >= HV(gNet_recovery_cost)[HV(gCurrent_net_game)->type]
            || HV(gRecovery_voucher_count)) {
            return 1;
        }
        HV(gProgram_state).credits_earned = 0;
        HV(gProgram_state).credits_lost = 0;
        NewTextHeadupSlot(4, 0, 1000, -4, GetMiscString(96));
        DoFancyHeadup(kFancyHeadupNetworkRaceNoMoreMoney);
        KnackerThisCar(&HV(gProgram_state).current_car);
        SendGameplayToHost(eNet_gameplay_suicide, 0, 0, 0, 0);
        return 0;
    } else {
        return original_CheckRecoverCost();
    }
}

function_hook_state_t function_hook_state_SortOutRecover = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(SortOutRecover, function_hook_state_SortOutRecover)
static void(__cdecl*original_SortOutRecover)(tCar_spec *) = (void(__cdecl*)(tCar_spec *))0x004a3a33;
CARM95_HOOK_FUNCTION(original_SortOutRecover, SortOutRecover)
void __cdecl SortOutRecover(tCar_spec *pCar) {
    int the_time;
    int val;
    static int old_time;
    LOG_TRACE("(%p)", pCar);

    (void)pCar;
    (void)the_time;
    (void)val;
    (void)old_time;

    if (function_hook_state_SortOutRecover == HOOK_ENABLED) {
        the_time = GetRaceTime() - HV(gPalette_fade_time);
        if (the_time < 0) {
            HV(gPalette_fade_time) = 0;
            old_time = 0;
        }
        if (the_time < 500) {
            val = 256 - (the_time * 256) / 500;
        } else {
            if (old_time < 500) {
                FlipUpCar(pCar);
                PipeSingleSpecial(ePipe_special_fade);
            }
            pCar->doing_nothing_flag = 1;
            val = ((the_time - 1000) * 256) / 500;
            if (val >= 256) {
                val = 256;
                HV(gPalette_fade_time) = 0;
                old_time = 0;
                pCar->doing_nothing_flag = 0;
            }
        }
        if (val <= 0) {
            val = 0;
        }
        SetFadedPalette(val);
        old_time = the_time;
    } else {
        original_SortOutRecover(pCar);
    }
}

function_hook_state_t function_hook_state_SetFlipUpCar = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(SetFlipUpCar, function_hook_state_SetFlipUpCar)
static void(__cdecl*original_SetFlipUpCar)(tCar_spec *) = (void(__cdecl*)(tCar_spec *))0x004a22f4;
CARM95_HOOK_FUNCTION(original_SetFlipUpCar, SetFlipUpCar)
void __cdecl SetFlipUpCar(tCar_spec *pCar) {
    LOG_TRACE("(%p)", pCar);

    (void)pCar;

    if (function_hook_state_SetFlipUpCar == HOOK_ENABLED) {
        if (HV(gNet_mode) != eNet_mode_none && pCar->driver == eDriver_local_human) {
            DisableCar(pCar);
            HV(gPalette_fade_time) = GetRaceTime();
            NetPlayerStatusChanged(ePlayer_status_recovering);
        } else {
            FlipUpCar(pCar);
        }
    } else {
        original_SetFlipUpCar(pCar);
    }
}

function_hook_state_t function_hook_state_FlipUpCar = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(FlipUpCar, function_hook_state_FlipUpCar)
static void(__cdecl*original_FlipUpCar)(tCar_spec *) = (void(__cdecl*)(tCar_spec *))0x004a234a;
CARM95_HOOK_FUNCTION(original_FlipUpCar, FlipUpCar)
void __cdecl FlipUpCar(tCar_spec *car) {
    br_vector3 tv;
    br_vector3 dir;
    int new_pos;
    int i;
    int j;
    int l;
    int count;
    br_scalar dist;
    br_material *material;
    br_scalar t;
    LOG_TRACE("(%p)", car);

    (void)car;
    (void)tv;
    (void)dir;
    (void)new_pos;
    (void)i;
    (void)j;
    (void)l;
    (void)count;
    (void)dist;
    (void)material;
    (void)t;

    if (function_hook_state_FlipUpCar == HOOK_ENABLED) {
        count = 0;
        if (car->driver == eDriver_local_human && HV(gNet_mode) == eNet_mode_none) {
            FadePaletteDown();
            while (KeyIsDown(44)) {
                ;
            }
        }
        car->doing_nothing_flag = 0;
        EnableCar(car);
        new_pos = 1;
        for (i = 0; i < 4; ++i) {
            if (car->susp_height[i >> 1] <= car->oldd[i]) {
                new_pos = 0;
            }
        }
        do {
            tv.v[0] = car->car_master_actor->t.t.mat.m[3][0] - car->last_safe_positions[0].m[3][0];
            tv.v[1] = car->car_master_actor->t.t.mat.m[3][1] - car->last_safe_positions[0].m[3][1];
            tv.v[2] = car->car_master_actor->t.t.mat.m[3][2] - car->last_safe_positions[0].m[3][2];
            if (BrVector3LengthSquared(&tv) > 8.3015966) {
                new_pos = 0;
            }
            BrMatrix34Copy(&car->car_master_actor->t.t.mat, &car->last_safe_positions[new_pos]);
            BrMatrix34Copy(&car->oldmat, &car->last_safe_positions[new_pos]);
            BrMatrix34Copy(&car->old_frame_mat, &car->oldmat);
            car->oldmat.m[3][0] = car->oldmat.m[3][0] * WORLD_SCALE;
            car->oldmat.m[3][1] = car->oldmat.m[3][1] * WORLD_SCALE;
            car->oldmat.m[3][2] = car->oldmat.m[3][2] * WORLD_SCALE;
            dir.v[0] = 0.0;
            dir.v[1] = 0.28985506;
            dir.v[2] = 0.0;
            FindFace(&car->car_master_actor->t.t.euler.t, &dir, &tv, &t, &material);
            if (t > 1.0) {
                car->car_master_actor->t.t.mat.m[3][0] += dir.v[0];
                car->car_master_actor->t.t.mat.m[3][1] += dir.v[1];
                car->car_master_actor->t.t.mat.m[3][2] += dir.v[2];
                car->oldmat.m[3][0] = car->car_master_actor->t.t.mat.m[3][0] * WORLD_SCALE;
                car->oldmat.m[3][1] = car->car_master_actor->t.t.mat.m[3][1] * WORLD_SCALE;
                car->oldmat.m[3][2] = car->car_master_actor->t.t.mat.m[3][2] * WORLD_SCALE;
                car->old_frame_mat.m[3][0] = car->car_master_actor->t.t.mat.m[3][0];
                car->old_frame_mat.m[3][1] = car->car_master_actor->t.t.mat.m[3][1];
                car->old_frame_mat.m[3][2] = car->car_master_actor->t.t.mat.m[3][2];
            }
            tv.v[0] = 0.0;
            tv.v[1] = 0.0;
            tv.v[2] = -0.001;
            BrMatrix34ApplyV(&car->v, &tv, &car->car_master_actor->t.t.mat);
            car->omega.v[0] = 0.0;
            car->omega.v[1] = 0.0;
            car->omega.v[2] = 0.0;
            car->direction.v[0] = -car->oldmat.m[2][0];
            car->direction.v[1] = -car->oldmat.m[2][1];
            car->direction.v[2] = -car->oldmat.m[2][2];
            for (i = 0; i <= new_pos; i++) {
                for (j = 0; j < 4; j++) {
                    BrMatrix34Copy(&car->last_safe_positions[j], &car->last_safe_positions[j + 1]);
                }
            }
            for (l = 0; l < 10; l++) {
                BrVector3Scale(&car->old_norm, &car->old_norm, 0.072463766);
                BrMatrix34ApplyV(&tv, &car->old_norm, &car->car_master_actor->t.t.mat);
                car->car_master_actor->t.t.mat.m[3][0] = car->car_master_actor->t.t.mat.m[3][0] + tv.v[0];
                car->car_master_actor->t.t.mat.m[3][1] = car->car_master_actor->t.t.mat.m[3][1] + tv.v[1];
                car->car_master_actor->t.t.mat.m[3][2] = car->car_master_actor->t.t.mat.m[3][2] + tv.v[2];
                car->oldmat.m[3][0] = car->car_master_actor->t.t.mat.m[3][0] * WORLD_SCALE;
                car->oldmat.m[3][1] = car->car_master_actor->t.t.mat.m[3][1] * WORLD_SCALE;
                car->oldmat.m[3][2] = car->car_master_actor->t.t.mat.m[3][2] * WORLD_SCALE;
                car->old_frame_mat.m[3][0] = car->car_master_actor->t.t.mat.m[3][0];
                car->old_frame_mat.m[3][1] = car->car_master_actor->t.t.mat.m[3][1];
                car->old_frame_mat.m[3][2] = car->car_master_actor->t.t.mat.m[3][2];
                if (TestForCarInSensiblePlace(car)) {
                    break;
                }
            }
            count++;
        } while (l == 10 && count < 3);
        car->oldmat.m[3][0] = car->car_master_actor->t.t.mat.m[3][0] * WORLD_SCALE;
        car->oldmat.m[3][1] = car->car_master_actor->t.t.mat.m[3][1] * WORLD_SCALE;
        car->oldmat.m[3][2] = car->car_master_actor->t.t.mat.m[3][2] * WORLD_SCALE;
        car->curvature = 0.0;
        for (j = 0; j < 4; ++j) {
            car->oldd[j] = car->ride_height;
        }
        car->revs = 0.0;
        car->gear = 0;
        car->auto_special_volume = 0;
        if (car->driver == eDriver_local_human) {
            InitialiseExternalCamera();
            PositionExternalCamera(car, 100u);
        }
    } else {
        original_FlipUpCar(car);
    }
}

function_hook_state_t function_hook_state_GetPowerup = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(GetPowerup, function_hook_state_GetPowerup)
static void(__cdecl*original_GetPowerup)(int) = (void(__cdecl*)(int))0x004a291d;
CARM95_HOOK_FUNCTION(original_GetPowerup, GetPowerup)
void __cdecl GetPowerup(int pNum) {
    LOG_TRACE("(%d)", pNum);

    (void)pNum;

    if (function_hook_state_GetPowerup == HOOK_ENABLED) {
        GotPowerup(&HV(gProgram_state).current_car, pNum);
    } else {
        original_GetPowerup(pNum);
    }
}

function_hook_state_t function_hook_state_CheckSystemKeys = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(CheckSystemKeys, function_hook_state_CheckSystemKeys)
static void(__cdecl*original_CheckSystemKeys)(int) = (void(__cdecl*)(int))0x004a293f;
CARM95_HOOK_FUNCTION(original_CheckSystemKeys, CheckSystemKeys)
void __cdecl CheckSystemKeys(int pRacing) {
    tU32 start_menu_time;
    int i;
    LOG_TRACE("(%d)", pRacing);

    (void)pRacing;
    (void)start_menu_time;
    (void)i;

    if (function_hook_state_CheckSystemKeys == HOOK_ENABLED) {
        start_menu_time = PDGetTotalTime();
        CheckQuit();
        if (!HV(gAction_replay_mode)) {
            CheckLoadSave();
        }
        AddLostTime(PDGetTotalTime() - start_menu_time);
        CheckToggles(pRacing);
        if (pRacing & !HV(gAction_replay_mode)) {
            CheckOtherRacingKeys();
        }
    } else {
        original_CheckSystemKeys(pRacing);
    }
}

function_hook_state_t function_hook_state_CheckKevKeys = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(CheckKevKeys, function_hook_state_CheckKevKeys)
static void(__cdecl*original_CheckKevKeys)() = (void(__cdecl*)())0x004a3b39;
CARM95_HOOK_FUNCTION(original_CheckKevKeys, CheckKevKeys)
void __cdecl CheckKevKeys() {
    int i;
    tU32 *value;
    char s[128];
    LOG_TRACE("()");

    (void)i;
    (void)value;
    (void)s;

    if (function_hook_state_CheckKevKeys == HOOK_ENABLED) {
        value = KevKeyService();
        if (value[0] == 0) {
            return;
        }

        for (i = 0; HV(gKev_keys)[i].action_proc != 0; i++) {
            if (HV(gKev_keys)[i].code == value[0] && HV(gKev_keys)[i].code2 == value[1]) {
                break;
            }
        }

        if (HV(gKev_keys)[i].action_proc) {
            if (HV(gNet_mode)) {
                if (HV(gKev_keys)[i].num == 0xA11EE75D) {
                    strcpy(s, HV(gNet_players)[HV(gThis_net_player_index)].player_name);
                    strcat(s, " ");
                    strcat(s, GetMiscString(225));
                    NetSendHeadupToEverybody(s);
                    HV(gKev_keys)[i].action_proc(HV(gKev_keys)[i].num);
                } else {
                    strcpy(s, HV(gNet_players)[HV(gThis_net_player_index)].player_name);
                    strcat(s, " ");
                    strcat(s, GetMiscString(224));
                    NetSendHeadupToAllPlayers(s);
                }
            } else {
                HV(gKev_keys)[i].action_proc(HV(gKev_keys)[i].num);
            }
        }
    } else {
        original_CheckKevKeys();
    }
}

function_hook_state_t function_hook_state_BrakeInstantly = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(BrakeInstantly, function_hook_state_BrakeInstantly)
static void(__cdecl*original_BrakeInstantly)() = (void(__cdecl*)())0x004a4159;
CARM95_HOOK_FUNCTION(original_BrakeInstantly, BrakeInstantly)
void __cdecl BrakeInstantly() {
    int i;
    LOG_TRACE("()");

    (void)i;

    if (function_hook_state_BrakeInstantly == HOOK_ENABLED) {
        HV(gProgram_state).current_car.revs = 0.f;
        if (HV(gProgram_state).current_car.number_of_wheels_on_ground != 0 && BrVector3LengthSquared(&HV(gProgram_state).current_car.v) > 0.0001f) {
            PratcamEvent(41);
            for (i = 0; i < 5; i++) {
                DRS3StartSound(HV(gCar_outlet), 9000 + i);
            }
        }
        BrVector3Set(&HV(gProgram_state).current_car.v, 0.f, 0.f, 0.f);
    } else {
        original_BrakeInstantly();
    }
}

function_hook_state_t function_hook_state_PollCarControls = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(PollCarControls, function_hook_state_PollCarControls)
static void(__cdecl*original_PollCarControls)(tU32) = (void(__cdecl*)(tU32))0x004a3d80;
CARM95_HOOK_FUNCTION(original_PollCarControls, PollCarControls)
void __cdecl PollCarControls(tU32 pTime_difference) {
    int decay_steering;
    int decay_speed;
    float decay_rate;
    tS32 joyX;
    tS32 joyY;
    tCar_controls keys;
    tJoystick joystick;
    tCar_spec *c;
    LOG_TRACE("(%u)", pTime_difference);

    (void)pTime_difference;
    (void)decay_steering;
    (void)decay_speed;
    (void)decay_rate;
    (void)joyX;
    (void)joyY;
    (void)keys;
    (void)joystick;
    (void)c;

    if (function_hook_state_PollCarControls == HOOK_ENABLED) {
        c = &HV(gProgram_state).current_car;

        memset(&keys, 0, sizeof(tCar_controls));
        joystick.left = -1;
        joystick.right = -1;
        joystick.acc = -1;
        joystick.dec = -1;
        if (HV(gEntering_message)) {
            memset(&c->keys, 0, sizeof(tCar_controls));
            c->joystick.left = -1;
            c->joystick.right = -1;
            c->joystick.acc = -1;
            c->joystick.dec = -1;
        } else {
            if (HV(gKey_mapping)[46] >= 115 || HV(gKey_mapping)[47] >= 115) {
                joystick.left = HV(gJoy_array)[HV(gKey_mapping)[46] - 115];
                joystick.right = HV(gJoy_array)[HV(gKey_mapping)[47] - 115];
                if (joystick.left < 0 && joystick.right < 0) {
                    joystick.left = 0;
                }
            } else {
                if (KeyIsDown(46)) {
                    keys.left = 1;
                }
                if (KeyIsDown(47)) {
                    keys.right = 1;
                }
            }
            if (KeyIsDown(12)) {
                keys.holdw = 1;
            }
            if (KeyIsDown(53) || HV(gRace_finished)) {
                if (!HV(gInstant_handbrake) || HV(gRace_finished)) {
                    keys.brake = 1;
                } else {
                    BrakeInstantly();
                }
            }
            if (HV(gKey_mapping)[48] < 115) {
                if (KeyIsDown(48) && !HV(gRace_finished) && !c->knackered && !HV(gWait_for_it)) {
                    keys.acc = 1;
                }
            } else {
                joystick.acc = HV(gJoy_array)[HV(gKey_mapping)[48] - 115];
                if (joystick.acc > 0xFFFF) {
                    joystick.acc = 0xFFFF;
                }
            }
            if (HV(gKey_mapping)[49] < 115) {
                if (KeyIsDown(49) && !HV(gRace_finished) && !c->knackered && !HV(gWait_for_it)) {
                    keys.dec = 1;
                }
            } else {
                joystick.dec = HV(gJoy_array)[HV(gKey_mapping)[49] - 115];
                if (joystick.dec > 0xFFFF) {
                    joystick.dec = 0xFFFF;
                }
            }
            if (KeyIsDown(55) && c->gear >= 0) {
                keys.change_down = 1;
                c->just_changed_gear = 1;
                if (keys.acc || joystick.acc > 32000) {
                    c->traction_control = 0;
                } else if (c->gear > 1 && !c->keys.change_down) {
                    --c->gear;
                }
                if (HV(gCountdown) && !c->keys.change_down) {
                    JumpTheStart();
                }
            }
            if (HV(gCar_flying)) {
                if (KeyIsDown(13)) {
                    keys.up = 1;
                }
                if (KeyIsDown(11)) {
                    keys.down = 1;
                }
            }
            if (KeyIsDown(58)) {
                if (!HV(gEntering_message)) {
                    keys.horn = 1;
                }
            }
            c->keys = keys;
            c->joystick = joystick;
        }
    } else {
        original_PollCarControls(pTime_difference);
    }
}

function_hook_state_t function_hook_state_PollCameraControls = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(PollCameraControls, function_hook_state_PollCameraControls)
static void(__cdecl*original_PollCameraControls)(tU32) = (void(__cdecl*)(tU32))0x004a4214;
CARM95_HOOK_FUNCTION(original_PollCameraControls, PollCameraControls)
void __cdecl PollCameraControls(tU32 pTime_difference) {
    int flag;
    int left;
    int right;
    int swirl_mode;
    int up_and_down_mode;
    int going_up;
    static int last_swirl_mode = 0;
    LOG_TRACE("(%u)", pTime_difference);

    (void)pTime_difference;
    (void)flag;
    (void)left;
    (void)right;
    (void)swirl_mode;
    (void)up_and_down_mode;
    (void)going_up;
    (void)last_swirl_mode;

    if (function_hook_state_PollCameraControls == HOOK_ENABLED) {
        flag = 0;
        swirl_mode = HV(gRace_finished) && !HV(gAction_replay_mode) && (&HV(gProgram_state).current_car == HV(gCar_to_view) || HV(gCar_to_view)->knackered);
        up_and_down_mode = swirl_mode && !HV(gCamera_has_collided);
        going_up = HV(gCamera_zoom) > 1.0;
        if (last_swirl_mode != swirl_mode) {
            if (swirl_mode) {
                SaveCameraPosition(0);
            } else {
                RestoreCameraPosition(0);
            }
            last_swirl_mode = swirl_mode;
        }
        if (!HV(gMap_mode) && !HV(gProgram_state).cockpit_on && (!HV(gAction_replay_mode) || HV(gAction_replay_camera_mode) <= eAction_replay_standard)) {
            if (KeyIsDown(31) || (up_and_down_mode && !going_up)) {
                HV(gCamera_zoom) = (double)pTime_difference * TIME_CONV_THING / (double)(2 * swirl_mode + 1) + HV(gCamera_zoom);
                if (HV(gCamera_zoom) > 2.0f) {
                    HV(gCamera_zoom) = 2.0f;
                }
                if (up_and_down_mode && HV(gCamera_zoom) > 1.0f) {
                    HV(gCamera_zoom) = 1.0f;
                }
            }
            if (KeyIsDown(30) || (up_and_down_mode && going_up)) {
                HV(gCamera_zoom) = HV(gCamera_zoom) - (double)pTime_difference * TIME_CONV_THING / (double)(2 * swirl_mode + 1);
                if (HV(gCamera_zoom) < 0.1) {
                    HV(gCamera_zoom) = 0.1;
                    if (up_and_down_mode) {
                        if (HV(gCamera_zoom) < 1.0f) {
                            HV(gCamera_zoom) = 1.0f;
                        }
                    }
                }
            }
            if (swirl_mode && HV(gProgram_state).current_car.speedo_speed < 0.001449275362318841) {
                left = 1;
                right = 0;
            } else {
                left = KeyIsDown(32);
                right = KeyIsDown(33);
            }

            if ((HV(gCamera_sign) ? left : right)) {
                if (!HV(gCamera_reset)) {
                    HV(gCamera_yaw) += BrDegreeToAngle(pTime_difference * 0.05f);
                }
                flag = 1;
            }
            if ((HV(gCamera_sign) ? right : left)) {
                if (!HV(gCamera_reset)) {
                    HV(gCamera_yaw) -= BrDegreeToAngle(pTime_difference * 0.05f);
                }
                if (flag) {
                    HV(gCamera_yaw) = 0;
                    HV(gCamera_reset) = 1;
                }
            } else if (!flag) {
                HV(gCamera_reset) = 0;
            }
        }
    } else {
        original_PollCameraControls(pTime_difference);
    }
}

function_hook_state_t function_hook_state_SetFlag2 = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(SetFlag2, function_hook_state_SetFlag2)
static void(__cdecl*original_SetFlag2)(int) = (void(__cdecl*)(int))0x004a45e8;
CARM95_HOOK_FUNCTION(original_SetFlag2, SetFlag2)
void __cdecl SetFlag2(int i) {
    LOG_TRACE("(%d)", i);

    (void)i;

    if (function_hook_state_SetFlag2 == HOOK_ENABLED) {
        HV(gAllow_car_flying) = 1;
        ToggleFlying();
        HV(gAllow_car_flying) = HV(gCar_flying);
    } else {
        original_SetFlag2(i);
    }
}

function_hook_state_t function_hook_state_ToggleFlying = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(ToggleFlying, function_hook_state_ToggleFlying)
static void(__cdecl*original_ToggleFlying)() = (void(__cdecl*)())0x004a460c;
CARM95_HOOK_FUNCTION(original_ToggleFlying, ToggleFlying)
void __cdecl ToggleFlying() {
    LOG_TRACE("()");


    if (function_hook_state_ToggleFlying == HOOK_ENABLED) {
        if (HV(gAllow_car_flying) && HV(gNet_mode) == eNet_mode_none) {
            HV(gCar_flying) = !HV(gCar_flying);
            if (HV(gCar_flying)) {
                NewTextHeadupSlot(4, 0, 500, -4, "We have lift off!!");
            } else {
                NewTextHeadupSlot(4, 0, 500, -4, "Back down to Earth");
            }
        } else {
            HV(gCar_flying) = 0;
        }
    } else {
        original_ToggleFlying();
    }
}

function_hook_state_t function_hook_state_ToggleInvulnerability = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(ToggleInvulnerability, function_hook_state_ToggleInvulnerability)
static void(__cdecl*original_ToggleInvulnerability)() = (void(__cdecl*)())0x004a46a8;
CARM95_HOOK_FUNCTION(original_ToggleInvulnerability, ToggleInvulnerability)
void __cdecl ToggleInvulnerability() {
    LOG_TRACE("()");


    if (function_hook_state_ToggleInvulnerability == HOOK_ENABLED) {
        HV(gProgram_state).current_car.invulnerable = !HV(gProgram_state).current_car.invulnerable;
        if (HV(gProgram_state).current_car.invulnerable) {
            NewTextHeadupSlot(4, 0, 1000, -4, GetMiscString(0));
        } else {
            NewTextHeadupSlot(4, 0, 1000, -4, "Vulnerability returns!");
        }
    } else {
        original_ToggleInvulnerability();
    }
}

function_hook_state_t function_hook_state_MoreTime = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(MoreTime, function_hook_state_MoreTime)
static void(__cdecl*original_MoreTime)() = (void(__cdecl*)())0x004a4721;
CARM95_HOOK_FUNCTION(original_MoreTime, MoreTime)
void __cdecl MoreTime() {
    LOG_TRACE("()");


    if (function_hook_state_MoreTime == HOOK_ENABLED) {
        AwardTime(30);
    } else {
        original_MoreTime();
    }
}

function_hook_state_t function_hook_state_MuchMoreTime = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(MuchMoreTime, function_hook_state_MuchMoreTime)
static void(__cdecl*original_MuchMoreTime)() = (void(__cdecl*)())0x004a4736;
CARM95_HOOK_FUNCTION(original_MuchMoreTime, MuchMoreTime)
void __cdecl MuchMoreTime() {
    LOG_TRACE("()");


    if (function_hook_state_MuchMoreTime == HOOK_ENABLED) {
        AwardTime(300);
    } else {
        original_MuchMoreTime();
    }
}

function_hook_state_t function_hook_state_ToggleTimerFreeze = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(ToggleTimerFreeze, function_hook_state_ToggleTimerFreeze)
static void(__cdecl*original_ToggleTimerFreeze)() = (void(__cdecl*)())0x004a474e;
CARM95_HOOK_FUNCTION(original_ToggleTimerFreeze, ToggleTimerFreeze)
void __cdecl ToggleTimerFreeze() {
    LOG_TRACE("()");


    if (function_hook_state_ToggleTimerFreeze == HOOK_ENABLED) {
        HV(gFreeze_timer) = !HV(gFreeze_timer);
        if (HV(gFreeze_timer)) {
            NewTextHeadupSlot(4, 0, 1000, -4, GetMiscString(1));
        } else {
            NewTextHeadupSlot(4, 0, 1000, -4, "Timer thawed out");
        }
    } else {
        original_ToggleTimerFreeze();
    }
}

function_hook_state_t function_hook_state_EarnDosh = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(EarnDosh, function_hook_state_EarnDosh)
static void(__cdecl*original_EarnDosh)() = (void(__cdecl*)())0x004a47c7;
CARM95_HOOK_FUNCTION(original_EarnDosh, EarnDosh)
void __cdecl EarnDosh() {
    LOG_TRACE("()");


    if (function_hook_state_EarnDosh == HOOK_ENABLED) {
        EarnCredits(5000);
    } else {
        original_EarnDosh();
    }
}

function_hook_state_t function_hook_state_LoseDosh = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(LoseDosh, function_hook_state_LoseDosh)
static void(__cdecl*original_LoseDosh)() = (void(__cdecl*)())0x004a47df;
CARM95_HOOK_FUNCTION(original_LoseDosh, LoseDosh)
void __cdecl LoseDosh() {
    LOG_TRACE("()");


    if (function_hook_state_LoseDosh == HOOK_ENABLED) {
        EarnCredits(-5000);
    } else {
        original_LoseDosh();
    }
}

function_hook_state_t function_hook_state_ToggleMap = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(ToggleMap, function_hook_state_ToggleMap)
static void(__cdecl*original_ToggleMap)() = (void(__cdecl*)())0x004a47f7;
CARM95_HOOK_FUNCTION(original_ToggleMap, ToggleMap)
void __cdecl ToggleMap() {
    static int old_indent;
    static int was_in_cockpit;
    LOG_TRACE("()");

    (void)old_indent;
    (void)was_in_cockpit;

    if (function_hook_state_ToggleMap == HOOK_ENABLED) {
        if (HV(gMap_mode) == 0) {
            if (!HV(gAction_replay_mode)) {
                if (HV(gNet_mode) != eNet_mode_none && HV(gCurrent_net_game)->type == eNet_game_type_foxy && HV(gThis_net_player_index) == HV(gIt_or_fox)) {
                    NewTextHeadupSlot(4, 0, 1000, -4, GetMiscString(214));
                } else if (HV(gNet_mode) != eNet_mode_none && HV(gCurrent_net_game)->type == eNet_game_type_tag && HV(gThis_net_player_index) != HV(gIt_or_fox)) {
                    NewTextHeadupSlot(4, 0, 1000, -4, GetMiscString(215));
                } else {
                    old_indent = HV(gRender_indent);
                    HV(gRender_indent) = 0;
                    was_in_cockpit = HV(gProgram_state).cockpit_on;
                    if (HV(gProgram_state).cockpit_on) {
                        ToggleCockpit();
                    }
                    HV(gMap_mode) = PDGetTotalTime();
                }
            }
        } else {
            HV(gMap_mode) = 0;
            HV(gRender_indent) = old_indent;
            if (was_in_cockpit) {
                ToggleCockpit();
            }
        }
        AdjustRenderScreenSize();
    } else {
        original_ToggleMap();
    }
}

function_hook_state_t function_hook_state_HornBlowing = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(HornBlowing, function_hook_state_HornBlowing)
static int(__cdecl*original_HornBlowing)() = (int(__cdecl*)())0x004a492c;
CARM95_HOOK_FUNCTION(original_HornBlowing, HornBlowing)
int __cdecl HornBlowing() {
    LOG_TRACE("()");


    if (function_hook_state_HornBlowing == HOOK_ENABLED) {
        return HV(gProgram_state).current_car.keys.horn;
    } else {
        return original_HornBlowing();
    }
}

function_hook_state_t function_hook_state_ToggleArrow = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(ToggleArrow, function_hook_state_ToggleArrow)
static void(__cdecl*original_ToggleArrow)() = (void(__cdecl*)())0x004a4947;
CARM95_HOOK_FUNCTION(original_ToggleArrow, ToggleArrow)
void __cdecl ToggleArrow() {
    static br_actor *old_actor;
    LOG_TRACE("()");

    (void)old_actor;

    if (function_hook_state_ToggleArrow == HOOK_ENABLED) {
        return;

        if (HV(gArrow_mode)) {
            HV(gProgram_state).current_car.car_model_actors[HV(gProgram_state).current_car.principal_car_actor].actor = old_actor;
            BrActorRemove(HV(gArrow_actor));
            BrActorAdd(HV(gProgram_state).current_car.car_master_actor, old_actor);
            HV(gArrow_mode) = 0;
            if (HV(gInfo_on)) {
                ToggleInfo();
            }
        } else {
            old_actor = HV(gProgram_state).current_car.car_model_actors[HV(gProgram_state).current_car.principal_car_actor].actor;
            BrActorRemove(old_actor);
            BrActorAdd(HV(gProgram_state).current_car.car_master_actor, HV(gArrow_actor));
            HV(gProgram_state).current_car.car_model_actors[HV(gProgram_state).current_car.principal_car_actor].actor = HV(gArrow_actor);
            HV(gArrow_mode) = 1;
            if (!HV(gInfo_on)) {
                ToggleInfo();
            }
        }
    } else {
        original_ToggleArrow();
    }
}

function_hook_state_t function_hook_state_GetRecoverVoucherCount = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(GetRecoverVoucherCount, function_hook_state_GetRecoverVoucherCount)
static int(__cdecl*original_GetRecoverVoucherCount)() = (int(__cdecl*)())0x004a4a23;
CARM95_HOOK_FUNCTION(original_GetRecoverVoucherCount, GetRecoverVoucherCount)
int __cdecl GetRecoverVoucherCount() {
    LOG_TRACE("()");


    if (function_hook_state_GetRecoverVoucherCount == HOOK_ENABLED) {
        return HV(gRecovery_voucher_count);
    } else {
        return original_GetRecoverVoucherCount();
    }
}

function_hook_state_t function_hook_state_AddVouchers = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(AddVouchers, function_hook_state_AddVouchers)
static void(__cdecl*original_AddVouchers)(int) = (void(__cdecl*)(int))0x004a4a38;
CARM95_HOOK_FUNCTION(original_AddVouchers, AddVouchers)
void __cdecl AddVouchers(int pCount) {
    LOG_TRACE("(%d)", pCount);

    (void)pCount;

    if (function_hook_state_AddVouchers == HOOK_ENABLED) {
        HV(gRecovery_voucher_count) += pCount;
    } else {
        original_AddVouchers(pCount);
    }
}

function_hook_state_t function_hook_state_ResetRecoveryVouchers = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(ResetRecoveryVouchers, function_hook_state_ResetRecoveryVouchers)
static void(__cdecl*original_ResetRecoveryVouchers)() = (void(__cdecl*)())0x004a4a4c;
CARM95_HOOK_FUNCTION(original_ResetRecoveryVouchers, ResetRecoveryVouchers)
void __cdecl ResetRecoveryVouchers() {
    LOG_TRACE("()");


    if (function_hook_state_ResetRecoveryVouchers == HOOK_ENABLED) {
        HV(gRecovery_voucher_count) = 0;
    } else {
        original_ResetRecoveryVouchers();
    }
}

function_hook_state_t function_hook_state_CycleCarTexturingLevel = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(CycleCarTexturingLevel, function_hook_state_CycleCarTexturingLevel)
static void(__cdecl*original_CycleCarTexturingLevel)() = (void(__cdecl*)())0x004a4a61;
CARM95_HOOK_FUNCTION(original_CycleCarTexturingLevel, CycleCarTexturingLevel)
void __cdecl CycleCarTexturingLevel() {
    tCar_texturing_level new_level;
    LOG_TRACE("()");

    (void)new_level;

    if (function_hook_state_CycleCarTexturingLevel == HOOK_ENABLED) {
        new_level = (GetCarTexturingLevel() + 1) % eCTL_count;
        SetCarTexturingLevel(new_level);
        switch (new_level) {
            case eCTL_none:
                NewTextHeadupSlot(4, 0, 2000, -4, GetMiscString(50));
                break;
            case eCTL_transparent:
                NewTextHeadupSlot(4, 0, 2000, -4, GetMiscString(51));
                break;
            case eCTL_full:
                NewTextHeadupSlot(4, 0, 2000, -4, GetMiscString(52));
                break;
            case eCTL_count:
                break;
        }
    } else {
        original_CycleCarTexturingLevel();
    }
}

function_hook_state_t function_hook_state_CycleWallTexturingLevel = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(CycleWallTexturingLevel, function_hook_state_CycleWallTexturingLevel)
static void(__cdecl*original_CycleWallTexturingLevel)() = (void(__cdecl*)())0x004a4b28;
CARM95_HOOK_FUNCTION(original_CycleWallTexturingLevel, CycleWallTexturingLevel)
void __cdecl CycleWallTexturingLevel() {
    tWall_texturing_level new_level;
    LOG_TRACE("()");

    (void)new_level;

    if (function_hook_state_CycleWallTexturingLevel == HOOK_ENABLED) {
        new_level = (GetWallTexturingLevel() + 1) % eWTL_count;
        ReallySetWallTexturingLevel(new_level);
        SetWallTexturingLevel(new_level);
        switch (new_level) {
            case eWTL_none:
                NewTextHeadupSlot(4, 0, 2000, -4, GetMiscString(55));
                break;
            case eWTL_linear:
                NewTextHeadupSlot(4, 0, 2000, -4, GetMiscString(56));
                break;
            case eWTL_full:
                NewTextHeadupSlot(4, 0, 2000, -4, GetMiscString(57));
                break;
            case eWTL_count:
                break;
        }
    } else {
        original_CycleWallTexturingLevel();
    }
}

function_hook_state_t function_hook_state_CycleRoadTexturingLevel = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(CycleRoadTexturingLevel, function_hook_state_CycleRoadTexturingLevel)
static void(__cdecl*original_CycleRoadTexturingLevel)() = (void(__cdecl*)())0x004a4bfb;
CARM95_HOOK_FUNCTION(original_CycleRoadTexturingLevel, CycleRoadTexturingLevel)
void __cdecl CycleRoadTexturingLevel() {
    tRoad_texturing_level new_level;
    LOG_TRACE("()");

    (void)new_level;

    if (function_hook_state_CycleRoadTexturingLevel == HOOK_ENABLED) {
        new_level = (GetRoadTexturingLevel() + 1) % 3;
        ReallySetRoadTexturingLevel(new_level);
        SetRoadTexturingLevel(new_level);
        if (new_level == eRTL_none) {
            NewTextHeadupSlot(4, 0, 2000, -4, GetMiscString(53));
        } else if (new_level == eRTL_full) {
            NewTextHeadupSlot(4, 0, 2000, -4, GetMiscString(54));
        }
    } else {
        original_CycleRoadTexturingLevel();
    }
}

function_hook_state_t function_hook_state_CycleYonFactor = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(CycleYonFactor, function_hook_state_CycleYonFactor)
static void(__cdecl*original_CycleYonFactor)() = (void(__cdecl*)())0x004a4ca1;
CARM95_HOOK_FUNCTION(original_CycleYonFactor, CycleYonFactor)
void __cdecl CycleYonFactor() {
    br_scalar new_factor;
    char factor_str[5];
    LOG_TRACE("()");

    (void)new_factor;
    (void)factor_str;

    if (function_hook_state_CycleYonFactor == HOOK_ENABLED) {
        new_factor = GetYonFactor() / 2.f;
        if (new_factor < .1f) {
            new_factor = 1.f;
        }
        SetYonFactor(new_factor);
        if (new_factor > .75f) {
            NewTextHeadupSlot(4, 0, 2000, -4, GetMiscString(100));
        } else if (new_factor > .375f) {
            NewTextHeadupSlot(4, 0, 2000, -4, GetMiscString(101));
        } else if (new_factor > .187f) {
            NewTextHeadupSlot(4, 0, 2000, -4, GetMiscString(102));
        } else {
            NewTextHeadupSlot(4, 0, 2000, -4, GetMiscString(103));
        }
    } else {
        original_CycleYonFactor();
    }
}

function_hook_state_t function_hook_state_SetSoundDetailLevel = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(SetSoundDetailLevel, function_hook_state_SetSoundDetailLevel)
static void(__cdecl*original_SetSoundDetailLevel)(int) = (void(__cdecl*)(int))0x004a4da4;
CARM95_HOOK_FUNCTION(original_SetSoundDetailLevel, SetSoundDetailLevel)
void __cdecl SetSoundDetailLevel(int pLevel) {
    LOG_TRACE("(%d)", pLevel);

    (void)pLevel;

    if (function_hook_state_SetSoundDetailLevel == HOOK_ENABLED) {
        HV(gSound_detail_level) = pLevel;
    } else {
        original_SetSoundDetailLevel(pLevel);
    }
}

function_hook_state_t function_hook_state_ReallySetSoundDetailLevel = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(ReallySetSoundDetailLevel, function_hook_state_ReallySetSoundDetailLevel)
static void(__cdecl*original_ReallySetSoundDetailLevel)(int) = (void(__cdecl*)(int))0x004a4db7;
CARM95_HOOK_FUNCTION(original_ReallySetSoundDetailLevel, ReallySetSoundDetailLevel)
void __cdecl ReallySetSoundDetailLevel(int pLevel) {
    LOG_TRACE("(%d)", pLevel);

    (void)pLevel;

    if (function_hook_state_ReallySetSoundDetailLevel == HOOK_ENABLED) {
        DRS3StopAllOutletSounds();
        DisposeSoundSources();
        HV(gSound_detail_level) = pLevel;
        InitSound();
        InitSoundSources();
    } else {
        original_ReallySetSoundDetailLevel(pLevel);
    }
}

function_hook_state_t function_hook_state_GetSoundDetailLevel = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(GetSoundDetailLevel, function_hook_state_GetSoundDetailLevel)
static int(__cdecl*original_GetSoundDetailLevel)() = (int(__cdecl*)())0x004a4dde;
CARM95_HOOK_FUNCTION(original_GetSoundDetailLevel, GetSoundDetailLevel)
int __cdecl GetSoundDetailLevel() {
    LOG_TRACE("()");


    if (function_hook_state_GetSoundDetailLevel == HOOK_ENABLED) {
        return HV(gSound_detail_level);
    } else {
        return original_GetSoundDetailLevel();
    }
}

function_hook_state_t function_hook_state_CycleSoundDetailLevel = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(CycleSoundDetailLevel, function_hook_state_CycleSoundDetailLevel)
static void(__cdecl*original_CycleSoundDetailLevel)() = (void(__cdecl*)())0x004a4df3;
CARM95_HOOK_FUNCTION(original_CycleSoundDetailLevel, CycleSoundDetailLevel)
void __cdecl CycleSoundDetailLevel() {
    int new_level;
    LOG_TRACE("()");

    (void)new_level;

    if (function_hook_state_CycleSoundDetailLevel == HOOK_ENABLED) {
        new_level = (HV(gSound_detail_level) + 1) % 3;
        ReallySetSoundDetailLevel(new_level);
        SetSoundDetailLevel(new_level);
        switch(new_level) {
            case 0:
                NewTextHeadupSlot(4, 0, 2000, -4, GetMiscString(116));
                break;
            case 1:
                NewTextHeadupSlot(4, 0, 2000, -4, GetMiscString(117));
                break;
            case 2:
                NewTextHeadupSlot(4, 0, 2000, -4, GetMiscString(118));
                break;
        }
    } else {
        original_CycleSoundDetailLevel();
    }
}

function_hook_state_t function_hook_state_CycleCarSimplificationLevel = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(CycleCarSimplificationLevel, function_hook_state_CycleCarSimplificationLevel)
static void(__cdecl*original_CycleCarSimplificationLevel)() = (void(__cdecl*)())0x004a4ec8;
CARM95_HOOK_FUNCTION(original_CycleCarSimplificationLevel, CycleCarSimplificationLevel)
void __cdecl CycleCarSimplificationLevel() {
    char *src;
    char *dst;
    LOG_TRACE("()");

    (void)src;
    (void)dst;

    if (function_hook_state_CycleCarSimplificationLevel == HOOK_ENABLED) {
        HV(gCar_simplification_level) = (HV(gCar_simplification_level) + 1) % 5;
        src = GetMiscString(119);
        dst = BrMemAllocate(strlen(src), kMem_simp_level);
        sprintf(dst, src, HV(gCar_simplification_level));
        NewTextHeadupSlot(4, 0, 2000, -4, dst);
        BrMemFree(dst);
    } else {
        original_CycleCarSimplificationLevel();
    }
}

function_hook_state_t function_hook_state_ToggleAccessoryRendering = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(ToggleAccessoryRendering, function_hook_state_ToggleAccessoryRendering)
static void(__cdecl*original_ToggleAccessoryRendering)() = (void(__cdecl*)())0x004a4f58;
CARM95_HOOK_FUNCTION(original_ToggleAccessoryRendering, ToggleAccessoryRendering)
void __cdecl ToggleAccessoryRendering() {
    int on;
    LOG_TRACE("()");

    (void)on;

    if (function_hook_state_ToggleAccessoryRendering == HOOK_ENABLED) {
        if (HV(gNet_mode) == eNet_mode_none) {
            on = !GetAccessoryRendering();
            SetAccessoryRendering(on);
            if (on) {
                NewTextHeadupSlot(4, 0, 2000, -4, GetMiscString(120));
            } else {
                NewTextHeadupSlot(4, 0, 2000, -4, GetMiscString(121));
            }
        } else {
            NewTextHeadupSlot(4, 0, 2000, -4, GetMiscString(124));
        }
    } else {
        original_ToggleAccessoryRendering();
    }
}

function_hook_state_t function_hook_state_ToggleSmoke = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(ToggleSmoke, function_hook_state_ToggleSmoke)
static void(__cdecl*original_ToggleSmoke)() = (void(__cdecl*)())0x004a500d;
CARM95_HOOK_FUNCTION(original_ToggleSmoke, ToggleSmoke)
void __cdecl ToggleSmoke() {
    int on;
    LOG_TRACE("()");

    (void)on;

    if (function_hook_state_ToggleSmoke == HOOK_ENABLED) {
        on = !GetSmokeOn();
        ReallySetSmokeOn(on);
        SetSmokeOn(on);
        if (on) {
            NewTextHeadupSlot(4, 0, 2000, -4, GetMiscString(122));
        } else {
            NewTextHeadupSlot(4, 0, 2000, -4, GetMiscString(123));
        }
    } else {
        original_ToggleSmoke();
    }
}

function_hook_state_t function_hook_state_DrawSomeText2 = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(DrawSomeText2, function_hook_state_DrawSomeText2)
void DrawSomeText2(tDR_font *pFont) {
    int y;
    int i;
    char *txt[15] = {
            "Cops    Show all racers on map    Show peds on map",
            "Random pick-up generation    Pick-up respawn",
            "Open game    Closed game",
            "Grid start    Random start",
            "Random races    Sequential races",
            "Include opponents' cars in car choices",
            "Choose cars    manually    randomly    include Big APC",
            "Starting credits    0    2000    5000    10000    20000",
            "Driven to Destruction",
            "Car Crusher",
            "Carnage Accumulator",
            "Checkpoint Stampede",
            "Sudden Death",
            "Terminal Tag",
            "Fox 'n' Hounds"
    };
    LOG_TRACE("(%p)", pFont);

    (void)pFont;
    (void)y;
    (void)i;
    (void)txt;

    if (function_hook_state_DrawSomeText2 == HOOK_ENABLED) {
        ClearEntireScreen();
        y = 0;
        for (i = 0; i < 15; i++) {
            TransDRPixelmapText(HV(gBack_screen), 0, y, pFont, txt[i], 320);
            y += pFont->height + 1;
        }

        PDScreenBufferSwap(0);
        PrintScreen();
    } else {
        NOT_IMPLEMENTED();
    }
}

function_hook_state_t function_hook_state_DrawSomeText = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(DrawSomeText, function_hook_state_DrawSomeText)
static void(__cdecl*original_DrawSomeText)() = (void(__cdecl*)())0x00485d80;
CARM95_HOOK_FUNCTION(original_DrawSomeText, DrawSomeText)
void __cdecl DrawSomeText() {
    LOG_TRACE("()");


    if (function_hook_state_DrawSomeText == HOOK_ENABLED) {
        DrawSomeText2(&HV(gFonts)[1]);
        DrawSomeText2(&HV(gFonts)[2]);
        DrawSomeText2(&HV(gFonts)[3]);
        DrawSomeText2(&HV(gFonts)[4]);
        DrawSomeText2(&HV(gFonts)[6]);
        DrawSomeText2(&HV(gFonts)[7]);
        DrawSomeText2(&HV(gFonts)[8]);
    } else {
        original_DrawSomeText();
    }
}

function_hook_state_t function_hook_state_SaySorryYouLittleBastard = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(SaySorryYouLittleBastard, function_hook_state_SaySorryYouLittleBastard)
void SaySorryYouLittleBastard() {
    LOG_TRACE("()");


    if (function_hook_state_SaySorryYouLittleBastard == HOOK_ENABLED) {
        if (HV(gNet_mode) != eNet_mode_none && HV(gCurrent_net_game)->options.enable_text_messages) {
            HV(gEntering_message) = 1;
        }
    } else {
        NOT_IMPLEMENTED();
    }
}

function_hook_state_t function_hook_state_UserSendMessage = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(UserSendMessage, function_hook_state_UserSendMessage)
static void(__cdecl*original_UserSendMessage)() = (void(__cdecl*)())0x004a509e;
CARM95_HOOK_FUNCTION(original_UserSendMessage, UserSendMessage)
void __cdecl UserSendMessage() {
    LOG_TRACE("()");


    if (function_hook_state_UserSendMessage == HOOK_ENABLED) {
        assert(0 && "UserSendMessage not implemented.");
        abort();
    } else {
        original_UserSendMessage();
    }
}

function_hook_state_t function_hook_state_EnterUserMessage = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(EnterUserMessage, function_hook_state_EnterUserMessage)
static void(__cdecl*original_EnterUserMessage)() = (void(__cdecl*)())0x004a50cf;
CARM95_HOOK_FUNCTION(original_EnterUserMessage, EnterUserMessage)
void __cdecl EnterUserMessage() {
    static int last_key;
    static int about_to_die;
    static tU32 next_time;
    char *the_message;
    char *p;
    int len;
    int the_key;
    int abuse_num;
    LOG_TRACE("()");

    (void)last_key;
    (void)about_to_die;
    (void)next_time;
    (void)the_message;
    (void)p;
    (void)len;
    (void)the_key;
    (void)abuse_num;

    if (function_hook_state_EnterUserMessage == HOOK_ENABLED) {
        assert(0 && "EnterUserMessage not implemented.");
        abort();
    } else {
        original_EnterUserMessage();
    }
}

function_hook_state_t function_hook_state_DisplayUserMessage = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(DisplayUserMessage, function_hook_state_DisplayUserMessage)
static void(__cdecl*original_DisplayUserMessage)() = (void(__cdecl*)())0x004a54a9;
CARM95_HOOK_FUNCTION(original_DisplayUserMessage, DisplayUserMessage)
void __cdecl DisplayUserMessage() {
    char *the_message;
    int len;
    tDR_font *font;
    LOG_TRACE("()");

    (void)the_message;
    (void)len;
    (void)font;

    if (function_hook_state_DisplayUserMessage == HOOK_ENABLED) {
        assert(0 && "DisplayUserMessage not implemented.");
        abort();
    } else {
        original_DisplayUserMessage();
    }
}

function_hook_state_t function_hook_state_InitAbuseomatic = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(InitAbuseomatic, function_hook_state_InitAbuseomatic)
static void(__cdecl*original_InitAbuseomatic)() = (void(__cdecl*)())0x004a567a;
CARM95_HOOK_FUNCTION(original_InitAbuseomatic, InitAbuseomatic)
void __cdecl InitAbuseomatic() {
    char path[256];
    char s[256];
    FILE *f;
    int i;
    int len;
    LOG_TRACE("()");

    (void)path;
    (void)s;
    (void)f;
    (void)i;
    (void)len;

    if (function_hook_state_InitAbuseomatic == HOOK_ENABLED) {
        assert(0 && "InitAbuseomatic not implemented.");
        abort();
    } else {
        original_InitAbuseomatic();
    }
}

function_hook_state_t function_hook_state_DisposeAbuseomatic = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(DisposeAbuseomatic, function_hook_state_DisposeAbuseomatic)
static void(__cdecl*original_DisposeAbuseomatic)() = (void(__cdecl*)())0x004a5868;
CARM95_HOOK_FUNCTION(original_DisposeAbuseomatic, DisposeAbuseomatic)
void __cdecl DisposeAbuseomatic() {
    int i;
    LOG_TRACE("()");

    (void)i;

    if (function_hook_state_DisposeAbuseomatic == HOOK_ENABLED) {
        for (i = 0; i < COUNT_OF(HV(gAbuse_text)); i++) {
            if (HV(gAbuse_text)[i] != NULL) {
                BrMemFree(HV(gAbuse_text)[i]);
            }
        }
    } else {
        original_DisposeAbuseomatic();
    }
}

