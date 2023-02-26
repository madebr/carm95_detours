#include "powerup.h"

#include "car.h"
#include "controls.h"
#include "crush.h"
#include "displays.h"
#include "errors.h"
#include "globvars.h"
#include "globvrpb.h"
#include "grafdata.h"
#include "graphics.h"
#include "input.h"
#include "loading.h"
#include "netgame.h"
#include "network.h"
#include "opponent.h"
#include "pedestrn.h"
#include "piping.h"
#include "pratcam.h"
#include "sound.h"
#include "utility.h"

#include "harness/trace.h"

#include "carm95_hooks.h"

#include "carm95_webserver.h"

#include <assert.h>

tGot_proc*(* hookvar_gGot_procs )[34] = (void*)0x0050ba98;
tLose_proc*(* hookvar_gLose_procs )[34] = (void*)0x0050bb20;
tPeriodic_proc*(* hookvar_gPeriodic_procs )[34] = (void*)0x0050bba8;
tU32 ** hookvar_gReal_render_palette  = (void*)0x0050bc30;
char *(* hookvar_gFizzle_names )[3] = (void*)0x0050bc38;
 // Suffix added to avoid duplicate symbol
br_vector3 * hookvar_gZero_v__powerup  = (void*)0x0050bc48;
int(* hookvar_gPed_harvest_sounds )[4] = (void*)0x0050bc58;
tHeadup_icon(* hookvar_gIcon_list )[20] = (void*)0x005320a0;
br_pixelmap *(* hookvar_gFizzle_in )[3] = (void*)0x005321f0;
int * hookvar_gNumber_of_powerups  = (void*)0x005321fc;
int * hookvar_gFizzle_height  = (void*)0x005321e4;
int * hookvar_gNumber_of_icons  = (void*)0x005321e0;
tPowerup ** hookvar_gPowerup_array  = (void*)0x005321e8;

#define GET_POWERUP_INDEX(POWERUP) ((POWERUP)-HV(gPowerup_array))

function_hook_state_t function_hook_state_LosePowerupX = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(LosePowerupX, function_hook_state_LosePowerupX)
static void(__cdecl*original_LosePowerupX)(tPowerup *, int) = (void(__cdecl*)(tPowerup *, int))0x0042cff6;
CARM95_HOOK_FUNCTION(original_LosePowerupX, LosePowerupX)
void __cdecl LosePowerupX(tPowerup *pThe_powerup, int pTell_net_players) {
    int i;
    tNet_message *the_message;
    LOG_TRACE("(%p, %d)", pThe_powerup, pTell_net_players);

    (void)pThe_powerup;
    (void)pTell_net_players;
    (void)i;
    (void)the_message;

    if (function_hook_state_LosePowerupX == HOOK_ENABLED) {
        if (pThe_powerup->got_time != 0 && pThe_powerup->lose_proc != NULL) {
            pThe_powerup->lose_proc(pThe_powerup, pThe_powerup->car);
        }
        if (HV(gNet_mode) != eNet_mode_none) {
            the_message = NetBuildMessage(21, 0);
            the_message->contents.data.powerup.event = ePowerup_lost;
            the_message->contents.data.powerup.player = HV(gLocal_net_ID);
            the_message->contents.data.powerup.event = GET_POWERUP_INDEX(pThe_powerup);
            NetGuaranteedSendMessageToAllPlayers(HV(gCurrent_net_game), the_message, NULL);
        }
        for (i = 0; i < HV(gNumber_of_icons); i++) {
            if (HV(gIcon_list)[i].powerup == pThe_powerup) {
                HV(gIcon_list)[i].fizzle_stage = 3;
                HV(gIcon_list)[i].fizzle_direction = -1;
                HV(gIcon_list)[i].fizzle_start = GetTotalTime();
                break;
            }
        }
        pThe_powerup->got_time = 0;
    } else {
        original_LosePowerupX(pThe_powerup, pTell_net_players);
    }
}

function_hook_state_t function_hook_state_LosePowerup = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(LosePowerup, function_hook_state_LosePowerup)
static void(__cdecl*original_LosePowerup)(tPowerup *) = (void(__cdecl*)(tPowerup *))0x0042cfdd;
CARM95_HOOK_FUNCTION(original_LosePowerup, LosePowerup)
void __cdecl LosePowerup(tPowerup *pThe_powerup) {
    LOG_TRACE("(%p)", pThe_powerup);

    (void)pThe_powerup;

    if (function_hook_state_LosePowerup == HOOK_ENABLED) {
        LosePowerupX(pThe_powerup, 1);
    } else {
        original_LosePowerup(pThe_powerup);
    }
}

function_hook_state_t function_hook_state_LoseAllSimilarPowerups = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(LoseAllSimilarPowerups, function_hook_state_LoseAllSimilarPowerups)
static void(__cdecl*original_LoseAllSimilarPowerups)(tPowerup *) = (void(__cdecl*)(tPowerup *))0x0042cf5e;
CARM95_HOOK_FUNCTION(original_LoseAllSimilarPowerups, LoseAllSimilarPowerups)
void __cdecl LoseAllSimilarPowerups(tPowerup *pThe_powerup) {
    int i;
    tPowerup *the_powerup;
    LOG_TRACE("(%p)", pThe_powerup);

    (void)pThe_powerup;
    (void)i;
    (void)the_powerup;

    if (function_hook_state_LoseAllSimilarPowerups == HOOK_ENABLED) {
        for (i = 0, the_powerup = HV(gPowerup_array); i < HV(gNumber_of_powerups); i++, the_powerup++) {
            if (the_powerup != pThe_powerup && the_powerup->got_time != 0) {
                if ((pThe_powerup->group_inclusion & the_powerup->group_inclusion) != 0) {
                    LosePowerup(the_powerup);
                }
            }
        }
    } else {
        original_LoseAllSimilarPowerups(pThe_powerup);
    }
}

function_hook_state_t function_hook_state_GotPowerupX = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(GotPowerupX, function_hook_state_GotPowerupX)
static int(__cdecl*original_GotPowerupX)(tCar_spec *, int, int, int, tU32) = (int(__cdecl*)(tCar_spec *, int, int, int, tU32))0x0042ca60;
CARM95_HOOK_FUNCTION(original_GotPowerupX, GotPowerupX)
int __cdecl GotPowerupX(tCar_spec *pCar, int pIndex, int pTell_net_players, int pDisplay_headup, tU32 pTime_left) {
    tPowerup *the_powerup;
    int i;
    int original_index;
    int icon_index;
    int ps_power;
    char s[256];
    char *s2;
    tNet_message *the_message;
    LOG_TRACE("(%p, %d, %d, %d, %u)", pCar, pIndex, pTell_net_players, pDisplay_headup, pTime_left);

    (void)pCar;
    (void)pIndex;
    (void)pTell_net_players;
    (void)pDisplay_headup;
    (void)pTime_left;
    (void)the_powerup;
    (void)i;
    (void)original_index;
    (void)icon_index;
    (void)ps_power;
    (void)s;
    (void)s2;
    (void)the_message;

    if (function_hook_state_GotPowerupX == HOOK_ENABLED) {
        if (pIndex < 0 || pIndex >= HV(gNumber_of_powerups)) {
            return -1;
        }
        the_powerup = &HV(gPowerup_array)[pIndex];
        if (the_powerup->type == ePowerup_dummy) {
            return -1;
        }
        if (the_powerup->got_proc == NULL) {
            NewTextHeadupSlot(4, 0, 3000, -4, GetMiscString(190));
            return -1;
        }
        original_index = pIndex;
        if (((HV(gProgram_state).sausage_eater_mode || HV(gTotal_peds) < 2)
             && (strstr(the_powerup->message, "Ped") != NULL
                 || strstr(the_powerup->message, "ped") != NULL
                 || strstr(the_powerup->message, "corpses") != NULL))
            || (HV(gNet_mode) != eNet_mode_none && the_powerup->net_type == eNet_powerup_inappropriate)) {
            pIndex = 0;
            the_powerup = &HV(gPowerup_array)[pIndex];
        }
        the_powerup->current_value = -1;
        LoseAllSimilarPowerups(the_powerup);
        ps_power = HV(gNet_mode) != eNet_mode_none && the_powerup->got_proc == GotTimeOrPower;
        if (the_powerup->message[0] != '\0' && pDisplay_headup && !ps_power) {
            strcpy(s, the_powerup->message);
            s2 = s;
            if (the_powerup->got_proc == FreezeTimer) {
                s2 = strtok(s, "/");
                if (HV(gFreeze_timer)) {
                    s2 = strtok(NULL, "/");
                }
            }
            NewTextHeadupSlot(4, 0, 3000, -4, s2);
        }
        the_powerup->car = pCar;
        if (the_powerup->got_proc != NULL) {
            pIndex = the_powerup->got_proc(the_powerup, pCar);
        }
        if (pCar->driver == eDriver_non_car_unused_slot || pCar->driver == eDriver_non_car) {
            return pIndex;
        }
        if (the_powerup->type == ePowerup_timed) {
            the_powerup->got_time = GetTotalTime();
            if (pTell_net_players) {
                the_powerup->lose_time = the_powerup->got_time + the_powerup->duration;
            } else {
                the_powerup->lose_time = the_powerup->got_time + pTime_left;
            }
            HV(gProgram_state).current_car.powerups[pIndex] = the_powerup->lose_time;
        } else if (the_powerup->type == ePowerup_whole_race) {
            the_powerup->got_time = GetTotalTime();
            HV(gProgram_state).current_car.powerups[pIndex] = -1;
        }
        if (the_powerup->prat_cam_event >= 0) {
            PratcamEvent(the_powerup->prat_cam_event);
        }
        if (HV(gNet_mode) != eNet_mode_none && pTell_net_players && pIndex == original_index && !ps_power) {
            the_message = NetBuildMessage(21, 0);
            the_message->contents.data.powerup.event = ePowerup_gained;
            the_message->contents.data.powerup.player = HV(gLocal_net_ID);
            the_message->contents.data.powerup.powerup_index = pIndex;
            if (the_powerup->type == ePowerup_timed) {
                the_message->contents.data.powerup.time_left = the_powerup->duration;
            } else {
                the_message->contents.data.powerup.time_left = 0;
            }
            NetGuaranteedSendMessageToAllPlayers(HV(gCurrent_net_game), the_message, NULL);
        }
        if (the_powerup->type != ePowerup_instantaneous && the_powerup->icon != NULL) {
            for (i = 0; i < HV(gNumber_of_icons); i++) {
                if (HV(gIcon_list)[i].powerup == the_powerup) {
                    HV(gIcon_list)[i].fizzle_stage = 4;
                    return pIndex;
                }
            }
            if (HV(gNumber_of_icons) != COUNT_OF(HV(gIcon_list))) {
                HV(gIcon_list)[HV(gNumber_of_icons)].powerup = the_powerup;
                HV(gIcon_list)[HV(gNumber_of_icons)].fizzle_stage = 0;
                HV(gIcon_list)[HV(gNumber_of_icons)].fizzle_direction = 1;
                HV(gIcon_list)[HV(gNumber_of_icons)].fizzle_start = GetTotalTime();
                HV(gNumber_of_icons)++;
            }
        }
        return pIndex;
    } else {
        return original_GotPowerupX(pCar, pIndex, pTell_net_players, pDisplay_headup, pTime_left);
    }
}

function_hook_state_t function_hook_state_GotPowerup = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(GotPowerup, function_hook_state_GotPowerup)
static int(__cdecl*original_GotPowerup)(tCar_spec *, int) = (int(__cdecl*)(tCar_spec *, int))0x0042d121;
CARM95_HOOK_FUNCTION(original_GotPowerup, GotPowerup)
int __cdecl GotPowerup(tCar_spec *pCar, int pIndex) {
    LOG_TRACE("(%p, %d)", pCar, pIndex);

    (void)pCar;
    (void)pIndex;

    if (function_hook_state_GotPowerup == HOOK_ENABLED) {
        return GotPowerupX(pCar, pIndex, 1, 1, 0);
    } else {
        return original_GotPowerup(pCar, pIndex);
    }
}

function_hook_state_t function_hook_state_LoadPowerups = HOOK_DISABLED;
CARM95_WEBSERVER_STATE(LoadPowerups, function_hook_state_LoadPowerups)
static void(__cdecl*original_LoadPowerups)() = (void(__cdecl*)())0x0042d147;
CARM95_HOOK_FUNCTION(original_LoadPowerups, LoadPowerups)
void __cdecl LoadPowerups() {
    FILE *f;
    tPath_name the_path;
    char s[256];
    int i;
    int j;
    int time;
    int action_index;
    tPowerup *the_powerup;
    LOG_TRACE("()");

    (void)f;
    (void)the_path;
    (void)s;
    (void)i;
    (void)j;
    (void)time;
    (void)action_index;
    (void)the_powerup;

    if (function_hook_state_LoadPowerups == HOOK_ENABLED) {
        for (i = 0; i < COUNT_OF(HV(gFizzle_in)); i++) {
            HV(gFizzle_in)[i] = LoadPixelmap(HV(gFizzle_names)[i]);
        }

        HV(gFizzle_height) = HV(gFizzle_in)[0]->height / 4;
        PathCat(the_path, HV(gApplication_path), "POWERUP.TXT");
        f = DRfopen(the_path, "rt");
        if (f == NULL) {
            FatalError(kFatalError_LoadResolutionIndependentFile);
        }
        HV(gNumber_of_powerups) = GetAnInt(f);
        HV(gPowerup_array) = BrMemAllocate(sizeof(tPowerup) * HV(gNumber_of_powerups), kMem_powerup_array);
        for (i = 0; i < HV(gNumber_of_powerups); i++) {
            the_powerup = &HV(gPowerup_array)[i];

            GetALineAndDontArgue(f, the_powerup->message);
            if (strcmp(the_powerup->message, "dummy") == 0) {
                the_powerup->type = 0;
            } else {
                if (strcmp(the_powerup->message, "n/a") == 0) {
                    the_powerup->message[0] = 0;
                }
                GetAString(f, s);
                the_powerup->icon = LoadPixelmap(s);
                the_powerup->fizzle_type = GetAnInt(f);
                time = 1000 * GetAnInt(f);
                the_powerup->duration = time;
                if (time > 0) {
                    the_powerup->type = ePowerup_timed;
                } else if (time == 0) {
                    the_powerup->type = ePowerup_whole_race;
                } else {
                    the_powerup->type = ePowerup_instantaneous;
                }
            }
            action_index = GetAnInt(f);
            if (action_index >= 0) {
                the_powerup->got_proc = HV(gGot_procs)[action_index];
                the_powerup->lose_proc = HV(gLose_procs)[action_index];
                the_powerup->periodic_proc = HV(gPeriodic_procs)[action_index];
            } else {
                the_powerup->lose_proc = NULL;
                the_powerup->periodic_proc = NULL;
                the_powerup->got_proc = NULL;
            }
            the_powerup->number_of_float_params = GetAnInt(f);
            the_powerup->float_params = BrMemAllocate(sizeof(float) * the_powerup->number_of_float_params, kMem_powerup_float_parms);
            for (j = 0; j < the_powerup->number_of_float_params; j++) {
                the_powerup->float_params[j] = GetAFloat(f);
            }
            the_powerup->number_of_integer_params = GetAnInt(f);
            the_powerup->integer_params = BrMemAllocate(sizeof(int) * the_powerup->number_of_integer_params, kMem_powerup_int_parms);
            for (j = 0; j < the_powerup->number_of_integer_params; j++) {
                the_powerup->integer_params[j] = GetAnInt(f);
            }
            the_powerup->group_inclusion = GetAnInt(f);
            the_powerup->prat_cam_event = GetAnInt(f);
            the_powerup->net_type = GetAnInt(f);
        }
        fclose(f);
    } else {
        original_LoadPowerups();
    }
}

function_hook_state_t function_hook_state_InitPowerups = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(InitPowerups, function_hook_state_InitPowerups)
static void(__cdecl*original_InitPowerups)() = (void(__cdecl*)())0x0042d536;
CARM95_HOOK_FUNCTION(original_InitPowerups, InitPowerups)
void __cdecl InitPowerups() {
    int i;
    tPowerup *the_powerup;
    LOG_TRACE("()");

    (void)i;
    (void)the_powerup;

    if (function_hook_state_InitPowerups == HOOK_ENABLED) {
        for (i = 0, the_powerup = HV(gPowerup_array); i < HV(gNumber_of_powerups); i++, the_powerup++) {
            the_powerup->got_time = 0;
            the_powerup->current_value = -1;
        }
    } else {
        original_InitPowerups();
    }
}

function_hook_state_t function_hook_state_CloseDownPowerUps = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(CloseDownPowerUps, function_hook_state_CloseDownPowerUps)
static void(__cdecl*original_CloseDownPowerUps)() = (void(__cdecl*)())0x0042d594;
CARM95_HOOK_FUNCTION(original_CloseDownPowerUps, CloseDownPowerUps)
void __cdecl CloseDownPowerUps() {
    int i;
    tPowerup *the_powerup;
    LOG_TRACE("()");

    (void)i;
    (void)the_powerup;

    if (function_hook_state_CloseDownPowerUps == HOOK_ENABLED) {
        for (i = 0, the_powerup = HV(gPowerup_array); i < HV(gNumber_of_powerups); i++, the_powerup++) {
            if (the_powerup->got_time != 0) {
                LosePowerup(the_powerup);
            }
        }
    } else {
        original_CloseDownPowerUps();
    }
}

function_hook_state_t function_hook_state_DrawPowerups = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(DrawPowerups, function_hook_state_DrawPowerups)
static void(__cdecl*original_DrawPowerups)(tU32) = (void(__cdecl*)(tU32))0x0042d5ec;
CARM95_HOOK_FUNCTION(original_DrawPowerups, DrawPowerups)
void __cdecl DrawPowerups(tU32 pTime) {
    int i;
    int y;
    int timer;
    tPowerup *the_powerup;
    char s[8];
    tHeadup_icon *the_icon;
    br_pixelmap *fizzle_pix;
    LOG_TRACE("(%u)", pTime);

    (void)pTime;
    (void)i;
    (void)y;
    (void)timer;
    (void)the_powerup;
    (void)s;
    (void)the_icon;
    (void)fizzle_pix;

    if (function_hook_state_DrawPowerups == HOOK_ENABLED) {
        y = HV(gCurrent_graf_data)->power_up_icon_y;
        for (i = 0; i < HV(gNumber_of_icons) && i < 5; i++) {
            the_icon = &HV(gIcon_list)[i];
            the_powerup = the_icon->powerup;
            if (the_powerup->icon == NULL) {
                continue;
            }
            y += HV(gCurrent_graf_data)->power_up_icon_y_pitch;
            if (the_icon->fizzle_stage < 4) {
                if (the_icon->fizzle_direction >= 0) {
                    the_icon->fizzle_stage = (pTime - the_icon->fizzle_start) / 100;
                } else {
                    the_icon->fizzle_stage = 3 - (pTime - the_icon->fizzle_start) / 100;
                }
                if (the_icon->fizzle_stage >= 5) {
                    the_icon->fizzle_stage = 4;
                } else if (the_icon->fizzle_stage < 0) {
                    memmove(the_icon, the_icon + 1, sizeof(tHeadup_icon) * (HV(gNumber_of_icons) - i - 1));
                    HV(gNumber_of_icons)--;
                    continue;
                }
            }
            if (the_icon->fizzle_stage >= 4) {
                DRPixelmapRectangleMaskedCopy(HV(gBack_screen),
                                              HV(gCurrent_graf_data)->power_up_icon_x, y,
                                              the_powerup->icon, 0, 0, the_powerup->icon->width, the_powerup->icon->height);
                if (the_powerup->type == ePowerup_timed) {
                    timer = the_powerup->lose_time - pTime;
                    if (timer <= 0) {
                        timer = 0;
                    }
                    TimerString(timer, s, 0, 0);
                    TransDRPixelmapText(HV(gBack_screen),
                                        HV(gCurrent_graf_data)->power_up_icon_countdown_x,
                                        y + HV(gCurrent_graf_data)->power_up_icon_countdown_y_offset,
                                        &HV(gFonts)[1], s, HV(gCurrent_graf_data)->power_up_icon_countdown_x + 30);
                } else if (the_powerup->current_value > 0) {
                    sprintf(s, "%d", the_powerup->current_value);
                    TransDRPixelmapText(HV(gBack_screen),
                                        HV(gCurrent_graf_data)->power_up_icon_countdown_x,
                                        y + HV(gCurrent_graf_data)->power_up_icon_countdown_y_offset,
                                        &HV(gFonts)[2], s, HV(gCurrent_graf_data)->power_up_icon_countdown_x + 30);
                }
            } else {
                fizzle_pix = HV(gFizzle_in)[the_powerup->fizzle_type];
                DRPixelmapRectangleMaskedCopy(HV(gBack_screen),
                                              HV(gCurrent_graf_data)->power_up_icon_x, y, fizzle_pix, 0,
                                              the_icon->fizzle_stage * HV(gFizzle_height), fizzle_pix->width, HV(gFizzle_height));
            }
        }
    } else {
        original_DrawPowerups(pTime);
    }
}

function_hook_state_t function_hook_state_DoPowerupPeriodics = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(DoPowerupPeriodics, function_hook_state_DoPowerupPeriodics)
static void(__cdecl*original_DoPowerupPeriodics)(tU32) = (void(__cdecl*)(tU32))0x0042d8a9;
CARM95_HOOK_FUNCTION(original_DoPowerupPeriodics, DoPowerupPeriodics)
void __cdecl DoPowerupPeriodics(tU32 pFrame_period) {
    int i;
    tPowerup *the_powerup;
    tU32 the_time;
    LOG_TRACE("(%u)", pFrame_period);

    (void)pFrame_period;
    (void)i;
    (void)the_powerup;
    (void)the_time;

    if (function_hook_state_DoPowerupPeriodics == HOOK_ENABLED) {
        the_time = GetTotalTime();
        for (i = 0, the_powerup = HV(gPowerup_array); i < HV(gNumber_of_powerups); i++, the_powerup++) {
            if (the_powerup->got_time != 0) {
                if (the_powerup->type == ePowerup_timed && the_powerup->lose_time <= the_time) {
                    LosePowerup(the_powerup);
                } else if (the_powerup->current_value == 0) {
                    LosePowerup(the_powerup);
                } else if (the_powerup->periodic_proc != NULL) {
                    the_powerup->periodic_proc(the_powerup, pFrame_period);
                }
            }
        }
    } else {
        original_DoPowerupPeriodics(pFrame_period);
    }
}

function_hook_state_t function_hook_state_GotPowerupN = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(GotPowerupN, function_hook_state_GotPowerupN)
static void(__cdecl*original_GotPowerupN)(int) = (void(__cdecl*)(int))0x0042d965;
CARM95_HOOK_FUNCTION(original_GotPowerupN, GotPowerupN)
void __cdecl GotPowerupN(int pN) {
    int modifiers;
    LOG_TRACE("(%d)", pN);

    (void)pN;
    (void)modifiers;

    if (function_hook_state_GotPowerupN == HOOK_ENABLED) {
        modifiers = 0;
        if (PDKeyDown(0) != 0) {
            modifiers += 10;
        }
        if (PDKeyDown(1) != 0) {
            modifiers += 20;
        }
        if (PDKeyDown(2) != 0) {
            modifiers += 40;
        }
        GotPowerup(&HV(gProgram_state).current_car, modifiers + pN);
    } else {
        original_GotPowerupN(pN);
    }
}

function_hook_state_t function_hook_state_GotPowerup0 = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(GotPowerup0, function_hook_state_GotPowerup0)
static void(__cdecl*original_GotPowerup0)() = (void(__cdecl*)())0x0042d9e8;
CARM95_HOOK_FUNCTION(original_GotPowerup0, GotPowerup0)
void __cdecl GotPowerup0() {
    LOG_TRACE("()");


    if (function_hook_state_GotPowerup0 == HOOK_ENABLED) {
        GotPowerupN(0);
    } else {
        original_GotPowerup0();
    }
}

function_hook_state_t function_hook_state_GotPowerup1 = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(GotPowerup1, function_hook_state_GotPowerup1)
static void(__cdecl*original_GotPowerup1)() = (void(__cdecl*)())0x0042d9fd;
CARM95_HOOK_FUNCTION(original_GotPowerup1, GotPowerup1)
void __cdecl GotPowerup1() {
    LOG_TRACE("()");


    if (function_hook_state_GotPowerup1 == HOOK_ENABLED) {
        GotPowerupN(1);
    } else {
        original_GotPowerup1();
    }
}

function_hook_state_t function_hook_state_GotPowerup2 = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(GotPowerup2, function_hook_state_GotPowerup2)
static void(__cdecl*original_GotPowerup2)() = (void(__cdecl*)())0x0042da12;
CARM95_HOOK_FUNCTION(original_GotPowerup2, GotPowerup2)
void __cdecl GotPowerup2() {
    LOG_TRACE("()");


    if (function_hook_state_GotPowerup2 == HOOK_ENABLED) {
        GotPowerupN(2);
    } else {
        original_GotPowerup2();
    }
}

function_hook_state_t function_hook_state_GotPowerup3 = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(GotPowerup3, function_hook_state_GotPowerup3)
static void(__cdecl*original_GotPowerup3)() = (void(__cdecl*)())0x0042da27;
CARM95_HOOK_FUNCTION(original_GotPowerup3, GotPowerup3)
void __cdecl GotPowerup3() {
    LOG_TRACE("()");


    if (function_hook_state_GotPowerup3 == HOOK_ENABLED) {
        GotPowerupN(3);
    } else {
        original_GotPowerup3();
    }
}

function_hook_state_t function_hook_state_GotPowerup4 = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(GotPowerup4, function_hook_state_GotPowerup4)
static void(__cdecl*original_GotPowerup4)() = (void(__cdecl*)())0x0042da3c;
CARM95_HOOK_FUNCTION(original_GotPowerup4, GotPowerup4)
void __cdecl GotPowerup4() {
    LOG_TRACE("()");


    if (function_hook_state_GotPowerup4 == HOOK_ENABLED) {
        GotPowerupN(4);
    } else {
        original_GotPowerup4();
    }
}

function_hook_state_t function_hook_state_GotPowerup5 = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(GotPowerup5, function_hook_state_GotPowerup5)
static void(__cdecl*original_GotPowerup5)() = (void(__cdecl*)())0x0042da51;
CARM95_HOOK_FUNCTION(original_GotPowerup5, GotPowerup5)
void __cdecl GotPowerup5() {
    LOG_TRACE("()");


    if (function_hook_state_GotPowerup5 == HOOK_ENABLED) {
        GotPowerupN(5);
    } else {
        original_GotPowerup5();
    }
}

function_hook_state_t function_hook_state_GotPowerup6 = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(GotPowerup6, function_hook_state_GotPowerup6)
static void(__cdecl*original_GotPowerup6)() = (void(__cdecl*)())0x0042da66;
CARM95_HOOK_FUNCTION(original_GotPowerup6, GotPowerup6)
void __cdecl GotPowerup6() {
    LOG_TRACE("()");


    if (function_hook_state_GotPowerup6 == HOOK_ENABLED) {
        GotPowerupN(6);
    } else {
        original_GotPowerup6();
    }
}

function_hook_state_t function_hook_state_GotPowerup7 = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(GotPowerup7, function_hook_state_GotPowerup7)
static void(__cdecl*original_GotPowerup7)() = (void(__cdecl*)())0x0042da7b;
CARM95_HOOK_FUNCTION(original_GotPowerup7, GotPowerup7)
void __cdecl GotPowerup7() {
    LOG_TRACE("()");


    if (function_hook_state_GotPowerup7 == HOOK_ENABLED) {
        GotPowerupN(7);
    } else {
        original_GotPowerup7();
    }
}

function_hook_state_t function_hook_state_GotPowerup8 = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(GotPowerup8, function_hook_state_GotPowerup8)
static void(__cdecl*original_GotPowerup8)() = (void(__cdecl*)())0x0042da90;
CARM95_HOOK_FUNCTION(original_GotPowerup8, GotPowerup8)
void __cdecl GotPowerup8() {
    LOG_TRACE("()");


    if (function_hook_state_GotPowerup8 == HOOK_ENABLED) {
        GotPowerupN(8);
    } else {
        original_GotPowerup8();
    }
}

function_hook_state_t function_hook_state_GotPowerup9 = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(GotPowerup9, function_hook_state_GotPowerup9)
static void(__cdecl*original_GotPowerup9)() = (void(__cdecl*)())0x0042daa5;
CARM95_HOOK_FUNCTION(original_GotPowerup9, GotPowerup9)
void __cdecl GotPowerup9() {
    LOG_TRACE("()");


    if (function_hook_state_GotPowerup9 == HOOK_ENABLED) {
        GotPowerupN(9);
    } else {
        original_GotPowerup9();
    }
}

function_hook_state_t function_hook_state_GotCredits = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(GotCredits, function_hook_state_GotCredits)
static int(__cdecl*original_GotCredits)(tPowerup *, tCar_spec *) = (int(__cdecl*)(tPowerup *, tCar_spec *))0x0042daba;
CARM95_HOOK_FUNCTION(original_GotCredits, GotCredits)
int __cdecl GotCredits(tPowerup *pPowerup, tCar_spec *pCar) {
    int credits;
    char s[256];
    LOG_TRACE("(%p, %p)", pPowerup, pCar);

    (void)pPowerup;
    (void)pCar;
    (void)credits;
    (void)s;

    if (function_hook_state_GotCredits == HOOK_ENABLED) {
        if (pCar->driver == eDriver_local_human) {
            strcpy(s, pPowerup->message);
            strcat(s, " ");
            EarnCredits2((IRandomBetween(pPowerup->integer_params[0], pPowerup->integer_params[1]) / 100) * 100, s);
        }
        return GET_POWERUP_INDEX(pPowerup);
    } else {
        return original_GotCredits(pPowerup, pCar);
    }
}

function_hook_state_t function_hook_state_ImprovePSPowerup = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(ImprovePSPowerup, function_hook_state_ImprovePSPowerup)
static void(__cdecl*original_ImprovePSPowerup)(tCar_spec *, int) = (void(__cdecl*)(tCar_spec *, int))0x0042db7a;
CARM95_HOOK_FUNCTION(original_ImprovePSPowerup, ImprovePSPowerup)
void __cdecl ImprovePSPowerup(tCar_spec *pCar, int pIndex) {
    tNet_message *the_message;
    LOG_TRACE("(%p, %d)", pCar, pIndex);

    (void)pCar;
    (void)pIndex;
    (void)the_message;

    if (function_hook_state_ImprovePSPowerup == HOOK_ENABLED) {
        pCar->power_up_levels[pIndex]++;
        NewTextHeadupSlot(4, 0, 3000, -4, GetMiscString(175 + pIndex));
    } else {
        original_ImprovePSPowerup(pCar, pIndex);
    }
}

function_hook_state_t function_hook_state_GotTimeOrPower = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(GotTimeOrPower, function_hook_state_GotTimeOrPower)
static int(__cdecl*original_GotTimeOrPower)(tPowerup *, tCar_spec *) = (int(__cdecl*)(tPowerup *, tCar_spec *))0x0042dbba;
CARM95_HOOK_FUNCTION(original_GotTimeOrPower, GotTimeOrPower)
int __cdecl GotTimeOrPower(tPowerup *pPowerup, tCar_spec *pCar) {
    int time;
    int index;
    int i;
    int not_allowed_power;
    char s[256];
    LOG_TRACE("(%p, %p)", pPowerup, pCar);

    (void)pPowerup;
    (void)pCar;
    (void)time;
    (void)index;
    (void)i;
    (void)not_allowed_power;
    (void)s;

    if (function_hook_state_GotTimeOrPower == HOOK_ENABLED) {
        if (HV(gNet_mode) == eNet_mode_none) {
            if (pCar->driver == eDriver_local_human) {
                time = IRandomBetween(pPowerup->integer_params[0], pPowerup->integer_params[1]);
                AwardTime(time);
            }
        } else {
            not_allowed_power = (HV(gCurrent_net_game)->type == eNet_game_type_foxy && HV(gThis_net_player_index) == HV(gIt_or_fox))
                                || (HV(gCurrent_net_game)->type == eNet_game_type_tag && HV(gThis_net_player_index) != HV(gIt_or_fox));
            if (pCar->power_up_levels[0] < 4 || (pCar->power_up_levels[1] < 4 && !not_allowed_power) || pCar->power_up_levels[2] < 4) {
                for (i = 0; i < 50; i++) {
                    if (not_allowed_power) {
                        index = PercentageChance(50) ? 0 : 2;
                    } else {
                        index = IRandomBetween(0, 2);
                    }
                    if (pCar->power_up_levels[index] < 4) {
                        ImprovePSPowerup(pCar, index);
                        break;
                    }
                }
            } else {
                NewTextHeadupSlot(4, 0, 3000, -4, GetMiscString(174));
            }
        }
        return GET_POWERUP_INDEX(pPowerup);
    } else {
        return original_GotTimeOrPower(pPowerup, pCar);
    }
}

function_hook_state_t function_hook_state_SetPedSpeed = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(SetPedSpeed, function_hook_state_SetPedSpeed)
static int(__cdecl*original_SetPedSpeed)(tPowerup *, tCar_spec *) = (int(__cdecl*)(tPowerup *, tCar_spec *))0x0042dd8b;
CARM95_HOOK_FUNCTION(original_SetPedSpeed, SetPedSpeed)
int __cdecl SetPedSpeed(tPowerup *pPowerup, tCar_spec *pCar) {
    LOG_TRACE("(%p, %p)", pPowerup, pCar);

    (void)pPowerup;
    (void)pCar;

    if (function_hook_state_SetPedSpeed == HOOK_ENABLED) {
        HV(gPedestrian_speed_factor) = pPowerup->float_params[0];
        return GET_POWERUP_INDEX(pPowerup);
    } else {
        return original_SetPedSpeed(pPowerup, pCar);
    }
}

function_hook_state_t function_hook_state_SetHades = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(SetHades, function_hook_state_SetHades)
static int(__cdecl*original_SetHades)(tPowerup *, tCar_spec *) = (int(__cdecl*)(tPowerup *, tCar_spec *))0x0042ddb9;
CARM95_HOOK_FUNCTION(original_SetHades, SetHades)
int __cdecl SetHades(tPowerup *pPowerup, tCar_spec *pCar) {
    LOG_TRACE("(%p, %p)", pPowerup, pCar);

    (void)pPowerup;
    (void)pCar;

    if (function_hook_state_SetHades == HOOK_ENABLED) {
        PedMaterialFromHell();
        return GET_POWERUP_INDEX(pPowerup);
    } else {
        return original_SetHades(pPowerup, pCar);
    }
}

function_hook_state_t function_hook_state_ResetHades = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(ResetHades, function_hook_state_ResetHades)
static void(__cdecl*original_ResetHades)(tPowerup *, tCar_spec *) = (void(__cdecl*)(tPowerup *, tCar_spec *))0x0042dddf;
CARM95_HOOK_FUNCTION(original_ResetHades, ResetHades)
void __cdecl ResetHades(tPowerup *pPowerup, tCar_spec *pCar) {
    LOG_TRACE("(%p, %p)", pPowerup, pCar);

    (void)pPowerup;
    (void)pCar;

    if (function_hook_state_ResetHades == HOOK_ENABLED) {
        ResetPedMaterial();
    } else {
        original_ResetHades(pPowerup, pCar);
    }
}

function_hook_state_t function_hook_state_SetPedSize = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(SetPedSize, function_hook_state_SetPedSize)
static int(__cdecl*original_SetPedSize)(tPowerup *, tCar_spec *) = (int(__cdecl*)(tPowerup *, tCar_spec *))0x0042ddef;
CARM95_HOOK_FUNCTION(original_SetPedSize, SetPedSize)
int __cdecl SetPedSize(tPowerup *pPowerup, tCar_spec *pCar) {
    br_scalar old_scale;
    LOG_TRACE("(%p, %p)", pPowerup, pCar);

    (void)pPowerup;
    (void)pCar;
    (void)old_scale;

    if (function_hook_state_SetPedSize == HOOK_ENABLED) {
        old_scale = HV(gPed_scale_factor);
        if (old_scale != pPowerup->float_params[0]) {
            if (HV(gPed_scale_factor) > 1.f) {
                HV(gPed_scale_factor) = pPowerup->float_params[0];
                PipeSingleSpecial(ePipe_special_giant_ped_off);
            } else {
                HV(gPed_scale_factor) = pPowerup->float_params[0];
                if (old_scale < 1.f) {
                    PipeSingleSpecial(ePipe_special_min_ped_off);
                }
            }
            if (HV(gPed_scale_factor) > 1.f) {
                PipeSingleSpecial(ePipe_special_giant_ped_on);
                old_scale = HV(gPed_scale_factor);
            } else {
                old_scale = HV(gPed_scale_factor);
                if (HV(gPed_scale_factor) < 1.f) {
                    PipeSingleSpecial(ePipe_special_min_ped_on);
                    old_scale = HV(gPed_scale_factor);
                }
            }
        }
        HV(gPed_scale_factor) = old_scale;
        return GET_POWERUP_INDEX(pPowerup);
    } else {
        return original_SetPedSize(pPowerup, pCar);
    }
}

function_hook_state_t function_hook_state_SetPedExplode = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(SetPedExplode, function_hook_state_SetPedExplode)
static int(__cdecl*original_SetPedExplode)(tPowerup *, tCar_spec *) = (int(__cdecl*)(tPowerup *, tCar_spec *))0x0042dec4;
CARM95_HOOK_FUNCTION(original_SetPedExplode, SetPedExplode)
int __cdecl SetPedExplode(tPowerup *pPowerup, tCar_spec *pCar) {
    LOG_TRACE("(%p, %p)", pPowerup, pCar);

    (void)pPowerup;
    (void)pCar;

    if (function_hook_state_SetPedExplode == HOOK_ENABLED) {
        HV(gExploding_pedestrians) = 1;
        return GET_POWERUP_INDEX(pPowerup);
    } else {
        return original_SetPedExplode(pPowerup, pCar);
    }
}

function_hook_state_t function_hook_state_SetInvulnerability = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(SetInvulnerability, function_hook_state_SetInvulnerability)
static int(__cdecl*original_SetInvulnerability)(tPowerup *, tCar_spec *) = (int(__cdecl*)(tPowerup *, tCar_spec *))0x0042deef;
CARM95_HOOK_FUNCTION(original_SetInvulnerability, SetInvulnerability)
int __cdecl SetInvulnerability(tPowerup *pPowerup, tCar_spec *pCar) {
    LOG_TRACE("(%p, %p)", pPowerup, pCar);

    (void)pPowerup;
    (void)pCar;

    if (function_hook_state_SetInvulnerability == HOOK_ENABLED) {
        pCar->invulnerable = 1;
        return GET_POWERUP_INDEX(pPowerup);
    } else {
        return original_SetInvulnerability(pPowerup, pCar);
    }
}

function_hook_state_t function_hook_state_ResetInvulnerability = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(ResetInvulnerability, function_hook_state_ResetInvulnerability)
static void(__cdecl*original_ResetInvulnerability)(tPowerup *, tCar_spec *) = (void(__cdecl*)(tPowerup *, tCar_spec *))0x0042df1d;
CARM95_HOOK_FUNCTION(original_ResetInvulnerability, ResetInvulnerability)
void __cdecl ResetInvulnerability(tPowerup *pPowerup, tCar_spec *pCar) {
    LOG_TRACE("(%p, %p)", pPowerup, pCar);

    (void)pPowerup;
    (void)pCar;

    if (function_hook_state_ResetInvulnerability == HOOK_ENABLED) {
        pCar->invulnerable = 0;
    } else {
        original_ResetInvulnerability(pPowerup, pCar);
    }
}

function_hook_state_t function_hook_state_SetFreeRepairs = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(SetFreeRepairs, function_hook_state_SetFreeRepairs)
static int(__cdecl*original_SetFreeRepairs)(tPowerup *, tCar_spec *) = (int(__cdecl*)(tPowerup *, tCar_spec *))0x0042df35;
CARM95_HOOK_FUNCTION(original_SetFreeRepairs, SetFreeRepairs)
int __cdecl SetFreeRepairs(tPowerup *pPowerup, tCar_spec *pCar) {
    LOG_TRACE("(%p, %p)", pPowerup, pCar);

    (void)pPowerup;
    (void)pCar;

    if (function_hook_state_SetFreeRepairs == HOOK_ENABLED) {
        if (pCar->driver == eDriver_local_human) {
            HV(gFree_repairs) = 1;
        }
        return GET_POWERUP_INDEX(pPowerup);
    } else {
        return original_SetFreeRepairs(pPowerup, pCar);
    }
}

function_hook_state_t function_hook_state_ResetFreeRepairs = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(ResetFreeRepairs, function_hook_state_ResetFreeRepairs)
static void(__cdecl*original_ResetFreeRepairs)(tPowerup *, tCar_spec *) = (void(__cdecl*)(tPowerup *, tCar_spec *))0x0042df6d;
CARM95_HOOK_FUNCTION(original_ResetFreeRepairs, ResetFreeRepairs)
void __cdecl ResetFreeRepairs(tPowerup *pPowerup, tCar_spec *pCar) {
    LOG_TRACE("(%p, %p)", pPowerup, pCar);

    (void)pPowerup;
    (void)pCar;

    if (function_hook_state_ResetFreeRepairs == HOOK_ENABLED) {
        if (pCar->driver == eDriver_local_human) {
            HV(gFree_repairs) = 0;
        }
    } else {
        original_ResetFreeRepairs(pPowerup, pCar);
    }
}

function_hook_state_t function_hook_state_SetBlindPedestrians = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(SetBlindPedestrians, function_hook_state_SetBlindPedestrians)
static int(__cdecl*original_SetBlindPedestrians)(tPowerup *, tCar_spec *) = (int(__cdecl*)(tPowerup *, tCar_spec *))0x0042df8f;
CARM95_HOOK_FUNCTION(original_SetBlindPedestrians, SetBlindPedestrians)
int __cdecl SetBlindPedestrians(tPowerup *pPowerup, tCar_spec *pCar) {
    LOG_TRACE("(%p, %p)", pPowerup, pCar);

    (void)pPowerup;
    (void)pCar;

    if (function_hook_state_SetBlindPedestrians == HOOK_ENABLED) {
        HV(gBlind_pedestrians) = 1;
        return GET_POWERUP_INDEX(pPowerup);
    } else {
        return original_SetBlindPedestrians(pPowerup, pCar);
    }
}

function_hook_state_t function_hook_state_ResetBlindPedestrians = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(ResetBlindPedestrians, function_hook_state_ResetBlindPedestrians)
static void(__cdecl*original_ResetBlindPedestrians)(tPowerup *, tCar_spec *) = (void(__cdecl*)(tPowerup *, tCar_spec *))0x0042dfba;
CARM95_HOOK_FUNCTION(original_ResetBlindPedestrians, ResetBlindPedestrians)
void __cdecl ResetBlindPedestrians(tPowerup *pPowerup, tCar_spec *pCar) {
    LOG_TRACE("(%p, %p)", pPowerup, pCar);

    (void)pPowerup;
    (void)pCar;

    if (function_hook_state_ResetBlindPedestrians == HOOK_ENABLED) {
        HV(gBlind_pedestrians) = 0;
    } else {
        original_ResetBlindPedestrians(pPowerup, pCar);
    }
}

function_hook_state_t function_hook_state_FreezeTimer = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(FreezeTimer, function_hook_state_FreezeTimer)
static int(__cdecl*original_FreezeTimer)(tPowerup *, tCar_spec *) = (int(__cdecl*)(tPowerup *, tCar_spec *))0x0042dfcf;
CARM95_HOOK_FUNCTION(original_FreezeTimer, FreezeTimer)
int __cdecl FreezeTimer(tPowerup *pPowerup, tCar_spec *pCar) {
    LOG_TRACE("(%p, %p)", pPowerup, pCar);

    (void)pPowerup;
    (void)pCar;

    if (function_hook_state_FreezeTimer == HOOK_ENABLED) {
        if (pCar->driver == eDriver_local_human) {
            HV(gFreeze_timer) = !HV(gFreeze_timer);
        }
        return GET_POWERUP_INDEX(pPowerup);
    } else {
        return original_FreezeTimer(pPowerup, pCar);
    }
}

function_hook_state_t function_hook_state_UnfreezeTimer = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(UnfreezeTimer, function_hook_state_UnfreezeTimer)
static void(__cdecl*original_UnfreezeTimer)(tPowerup *, tCar_spec *) = (void(__cdecl*)(tPowerup *, tCar_spec *))0x0042e023;
CARM95_HOOK_FUNCTION(original_UnfreezeTimer, UnfreezeTimer)
void __cdecl UnfreezeTimer(tPowerup *pPowerup, tCar_spec *pCar) {
    LOG_TRACE("(%p, %p)", pPowerup, pCar);

    (void)pPowerup;
    (void)pCar;

    if (function_hook_state_UnfreezeTimer == HOOK_ENABLED) {
        if (pCar->driver == eDriver_local_human) {
            HV(gFreeze_timer) = 0;
        }
    } else {
        original_UnfreezeTimer(pPowerup, pCar);
    }
}

function_hook_state_t function_hook_state_DoInstantRepair = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(DoInstantRepair, function_hook_state_DoInstantRepair)
static int(__cdecl*original_DoInstantRepair)(tPowerup *, tCar_spec *) = (int(__cdecl*)(tPowerup *, tCar_spec *))0x0042e045;
CARM95_HOOK_FUNCTION(original_DoInstantRepair, DoInstantRepair)
int __cdecl DoInstantRepair(tPowerup *pPowerup, tCar_spec *pCar) {
    LOG_TRACE("(%p, %p)", pPowerup, pCar);

    (void)pPowerup;
    (void)pCar;

    if (function_hook_state_DoInstantRepair == HOOK_ENABLED) {
        if (pCar->driver == eDriver_local_human) {
            TotallyRepairCar();
        }
        return GET_POWERUP_INDEX(HV(gPowerup_array));
    } else {
        return original_DoInstantRepair(pPowerup, pCar);
    }
}

function_hook_state_t function_hook_state_ResetPedSpeed = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(ResetPedSpeed, function_hook_state_ResetPedSpeed)
static void(__cdecl*original_ResetPedSpeed)(tPowerup *, tCar_spec *) = (void(__cdecl*)(tPowerup *, tCar_spec *))0x0042e078;
CARM95_HOOK_FUNCTION(original_ResetPedSpeed, ResetPedSpeed)
void __cdecl ResetPedSpeed(tPowerup *pPowerup, tCar_spec *pCar) {
    LOG_TRACE("(%p, %p)", pPowerup, pCar);

    (void)pPowerup;
    (void)pCar;

    if (function_hook_state_ResetPedSpeed == HOOK_ENABLED) {
        HV(gPedestrian_speed_factor) = 1.f;
    } else {
        original_ResetPedSpeed(pPowerup, pCar);
    }
}

function_hook_state_t function_hook_state_ResetPedSize = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(ResetPedSize, function_hook_state_ResetPedSize)
static void(__cdecl*original_ResetPedSize)(tPowerup *, tCar_spec *) = (void(__cdecl*)(tPowerup *, tCar_spec *))0x0042e08d;
CARM95_HOOK_FUNCTION(original_ResetPedSize, ResetPedSize)
void __cdecl ResetPedSize(tPowerup *pPowerup, tCar_spec *pCar) {
    LOG_TRACE("(%p, %p)", pPowerup, pCar);

    (void)pPowerup;
    (void)pCar;

    if (function_hook_state_ResetPedSize == HOOK_ENABLED) {
        HV(gPed_scale_factor) = 1.f;
        PipeSingleSpecial(ePipe_special_giant_ped_off);
    } else {
        original_ResetPedSize(pPowerup, pCar);
    }
}

function_hook_state_t function_hook_state_ResetPedExplode = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(ResetPedExplode, function_hook_state_ResetPedExplode)
static void(__cdecl*original_ResetPedExplode)(tPowerup *, tCar_spec *) = (void(__cdecl*)(tPowerup *, tCar_spec *))0x0042e0ac;
CARM95_HOOK_FUNCTION(original_ResetPedExplode, ResetPedExplode)
void __cdecl ResetPedExplode(tPowerup *pPowerup, tCar_spec *pCar) {
    LOG_TRACE("(%p, %p)", pPowerup, pCar);

    (void)pPowerup;
    (void)pCar;

    if (function_hook_state_ResetPedExplode == HOOK_ENABLED) {
        HV(gExploding_pedestrians) = 0;
    } else {
        original_ResetPedExplode(pPowerup, pCar);
    }
}

function_hook_state_t function_hook_state_SetEngineFactor = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(SetEngineFactor, function_hook_state_SetEngineFactor)
static int(__cdecl*original_SetEngineFactor)(tPowerup *, tCar_spec *) = (int(__cdecl*)(tPowerup *, tCar_spec *))0x0042e0c1;
CARM95_HOOK_FUNCTION(original_SetEngineFactor, SetEngineFactor)
int __cdecl SetEngineFactor(tPowerup *pPowerup, tCar_spec *pCar) {
    LOG_TRACE("(%p, %p)", pPowerup, pCar);

    (void)pPowerup;
    (void)pCar;

    if (function_hook_state_SetEngineFactor == HOOK_ENABLED) {
        pCar->engine_power_multiplier = pPowerup->float_params[0];
        pCar->grip_multiplier = pPowerup->float_params[1];
        SetCarSuspGiveAndHeight(pCar, pPowerup->float_params[2], pPowerup->float_params[3],
                                pPowerup->float_params[6], pPowerup->float_params[4], pPowerup->float_params[5]);
        return GET_POWERUP_INDEX(pPowerup);
    } else {
        return original_SetEngineFactor(pPowerup, pCar);
    }
}

function_hook_state_t function_hook_state_SetUnderwater = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(SetUnderwater, function_hook_state_SetUnderwater)
static int(__cdecl*original_SetUnderwater)(tPowerup *, tCar_spec *) = (int(__cdecl*)(tPowerup *, tCar_spec *))0x0042e143;
CARM95_HOOK_FUNCTION(original_SetUnderwater, SetUnderwater)
int __cdecl SetUnderwater(tPowerup *pPowerup, tCar_spec *pCar) {
    LOG_TRACE("(%p, %p)", pPowerup, pCar);

    (void)pPowerup;
    (void)pCar;

    if (function_hook_state_SetUnderwater == HOOK_ENABLED) {
        pCar->underwater_ability = 1;
        return GET_POWERUP_INDEX(pPowerup);
    } else {
        return original_SetUnderwater(pPowerup, pCar);
    }
}

function_hook_state_t function_hook_state_TrashBodywork = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(TrashBodywork, function_hook_state_TrashBodywork)
static int(__cdecl*original_TrashBodywork)(tPowerup *, tCar_spec *) = (int(__cdecl*)(tPowerup *, tCar_spec *))0x0042e171;
CARM95_HOOK_FUNCTION(original_TrashBodywork, TrashBodywork)
int __cdecl TrashBodywork(tPowerup *pPowerup, tCar_spec *pCar) {
    int i;
    tCar_spec *c;
    LOG_TRACE("(%p, %p)", pPowerup, pCar);

    (void)pPowerup;
    (void)pCar;
    (void)i;
    (void)c;

    if (function_hook_state_TrashBodywork == HOOK_ENABLED) {
        for (i = 0; i < pCar->car_actor_count; i++) {
            TotallySpamTheModel(pCar, i, pCar->car_model_actors[i].actor, &pCar->car_model_actors[i].crush_data, 0.5f);
        }
        if (pCar->driver == eDriver_local_human) {
            DRS3StartSound2(HV(gCar_outlet), 5000, 1, 255, 255, -1, -1);
            DRS3StartSound2(HV(gCar_outlet), 5001, 1, 255, 255, -1, -1);
            DRS3StartSound2(HV(gCar_outlet), 5002, 1, 255, 255, -1, -1);
        }
        return GET_POWERUP_INDEX(pPowerup);
    } else {
        return original_TrashBodywork(pPowerup, pCar);
    }
}

function_hook_state_t function_hook_state_TakeDrugs = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(TakeDrugs, function_hook_state_TakeDrugs)
static int(__cdecl*original_TakeDrugs)(tPowerup *, tCar_spec *) = (int(__cdecl*)(tPowerup *, tCar_spec *))0x0042e26c;
CARM95_HOOK_FUNCTION(original_TakeDrugs, TakeDrugs)
int __cdecl TakeDrugs(tPowerup *pPowerup, tCar_spec *pCar) {
    LOG_TRACE("(%p, %p)", pPowerup, pCar);

    (void)pPowerup;
    (void)pCar;

    if (function_hook_state_TakeDrugs == HOOK_ENABLED) {
        if (pCar->driver == eDriver_local_human) {
            if (HV(gReal_render_palette) == NULL) {
                HV(gReal_render_palette) = BrMemAllocate(sizeof(tU32) * 256, kMem_drugs_palette);
                memcpy(HV(gReal_render_palette), HV(gRender_palette)->pixels, sizeof(tU32) * 256);
            }
            HV(gOn_drugs) = 1;
        }
        return GET_POWERUP_INDEX(pPowerup);
    } else {
        return original_TakeDrugs(pPowerup, pCar);
    }
}

function_hook_state_t function_hook_state_PaletteFuckedUpByDrugs = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(PaletteFuckedUpByDrugs, function_hook_state_PaletteFuckedUpByDrugs)
static void(__cdecl*original_PaletteFuckedUpByDrugs)(br_pixelmap *, int) = (void(__cdecl*)(br_pixelmap *, int))0x0042e30a;
CARM95_HOOK_FUNCTION(original_PaletteFuckedUpByDrugs, PaletteFuckedUpByDrugs)
void __cdecl PaletteFuckedUpByDrugs(br_pixelmap *pPixelmap, int pOffset) {
    int i;
    LOG_TRACE("(%p, %d)", pPixelmap, pOffset);

    (void)pPixelmap;
    (void)pOffset;
    (void)i;

    if (function_hook_state_PaletteFuckedUpByDrugs == HOOK_ENABLED) {
        *(tU32*)HV(gRender_palette)->pixels = *HV(gReal_render_palette);
        for (i = 1; i < 224; i++) {
            ((tU32*)HV(gRender_palette)->pixels)[i] = HV(gReal_render_palette)[(i + pOffset) & 0xff];
        }
        for (i = 224; i < 256; i++) {
            ((tU32*)HV(gRender_palette)->pixels)[i] = HV(gReal_render_palette)[i];
        }
    } else {
        original_PaletteFuckedUpByDrugs(pPixelmap, pOffset);
    }
}

function_hook_state_t function_hook_state_TheEffectsOfDrugs = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(TheEffectsOfDrugs, function_hook_state_TheEffectsOfDrugs)
static void(__cdecl*original_TheEffectsOfDrugs)(tPowerup *, tU32) = (void(__cdecl*)(tPowerup *, tU32))0x0042e2dd;
CARM95_HOOK_FUNCTION(original_TheEffectsOfDrugs, TheEffectsOfDrugs)
void __cdecl TheEffectsOfDrugs(tPowerup *pPowerup, tU32 pPeriod) {
    LOG_TRACE("(%p, %u)", pPowerup, pPeriod);

    (void)pPowerup;
    (void)pPeriod;

    if (function_hook_state_TheEffectsOfDrugs == HOOK_ENABLED) {
        PaletteFuckedUpByDrugs(HV(gRender_palette), GetTotalTime() / 100);
        ResetPalette();
    } else {
        original_TheEffectsOfDrugs(pPowerup, pPeriod);
    }
}

function_hook_state_t function_hook_state_SetOpponentsSpeed = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(SetOpponentsSpeed, function_hook_state_SetOpponentsSpeed)
static int(__cdecl*original_SetOpponentsSpeed)(tPowerup *, tCar_spec *) = (int(__cdecl*)(tPowerup *, tCar_spec *))0x0042e3af;
CARM95_HOOK_FUNCTION(original_SetOpponentsSpeed, SetOpponentsSpeed)
int __cdecl SetOpponentsSpeed(tPowerup *pPowerup, tCar_spec *pCar) {
    int i;
    LOG_TRACE("(%p, %p)", pPowerup, pCar);

    (void)pPowerup;
    (void)pCar;
    (void)i;

    if (function_hook_state_SetOpponentsSpeed == HOOK_ENABLED) {
        for (i = 0; i < HV(gCurrent_race).number_of_racers && HV(gCurrent_race).opponent_list[i].index != 29; i++) {
        }
        if (i < HV(gCurrent_race).number_of_racers) {
            SetEngineFactor(HV(gPowerup_array) + 5, HV(gCurrent_race).opponent_list[i].car_spec);
        }
        HV(gOpponent_speed_factor) = pPowerup->float_params[0];
        return GET_POWERUP_INDEX(pPowerup);
    } else {
        return original_SetOpponentsSpeed(pPowerup, pCar);
    }
}

function_hook_state_t function_hook_state_SetCopsSpeed = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(SetCopsSpeed, function_hook_state_SetCopsSpeed)
static int(__cdecl*original_SetCopsSpeed)(tPowerup *, tCar_spec *) = (int(__cdecl*)(tPowerup *, tCar_spec *))0x0042e445;
CARM95_HOOK_FUNCTION(original_SetCopsSpeed, SetCopsSpeed)
int __cdecl SetCopsSpeed(tPowerup *pPowerup, tCar_spec *pCar) {
    LOG_TRACE("(%p, %p)", pPowerup, pCar);

    (void)pPowerup;
    (void)pCar;

    if (function_hook_state_SetCopsSpeed == HOOK_ENABLED) {
        HV(gCop_speed_factor) = pPowerup->float_params[0];
        return GET_POWERUP_INDEX(pPowerup);
    } else {
        return original_SetCopsSpeed(pPowerup, pCar);
    }
}

function_hook_state_t function_hook_state_SetGravity = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(SetGravity, function_hook_state_SetGravity)
static int(__cdecl*original_SetGravity)(tPowerup *, tCar_spec *) = (int(__cdecl*)(tPowerup *, tCar_spec *))0x0042e473;
CARM95_HOOK_FUNCTION(original_SetGravity, SetGravity)
int __cdecl SetGravity(tPowerup *pPowerup, tCar_spec *pCar) {
    LOG_TRACE("(%p, %p)", pPowerup, pCar);

    (void)pPowerup;
    (void)pCar;

    if (function_hook_state_SetGravity == HOOK_ENABLED) {
        HV(gGravity_multiplier) = pPowerup->float_params[0];
        return GET_POWERUP_INDEX(pPowerup);
    } else {
        return original_SetGravity(pPowerup, pCar);
    }
}

function_hook_state_t function_hook_state_SetPinball = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(SetPinball, function_hook_state_SetPinball)
static int(__cdecl*original_SetPinball)(tPowerup *, tCar_spec *) = (int(__cdecl*)(tPowerup *, tCar_spec *))0x0042e4a1;
CARM95_HOOK_FUNCTION(original_SetPinball, SetPinball)
int __cdecl SetPinball(tPowerup *pPowerup, tCar_spec *pCar) {
    LOG_TRACE("(%p, %p)", pPowerup, pCar);

    (void)pPowerup;
    (void)pCar;

    if (function_hook_state_SetPinball == HOOK_ENABLED) {
        HV(gPinball_factor) = pPowerup->float_params[0];
        return GET_POWERUP_INDEX(pPowerup);
    } else {
        return original_SetPinball(pPowerup, pCar);
    }
}

function_hook_state_t function_hook_state_SetWallclimb = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(SetWallclimb, function_hook_state_SetWallclimb)
static int(__cdecl*original_SetWallclimb)(tPowerup *, tCar_spec *) = (int(__cdecl*)(tPowerup *, tCar_spec *))0x0042e4cf;
CARM95_HOOK_FUNCTION(original_SetWallclimb, SetWallclimb)
int __cdecl SetWallclimb(tPowerup *pPowerup, tCar_spec *pCar) {
    LOG_TRACE("(%p, %p)", pPowerup, pCar);

    (void)pPowerup;
    (void)pCar;

    if (function_hook_state_SetWallclimb == HOOK_ENABLED) {
        pCar->wall_climber_mode = 1;
        return GET_POWERUP_INDEX(pPowerup);
    } else {
        return original_SetWallclimb(pPowerup, pCar);
    }
}

function_hook_state_t function_hook_state_SetBouncey = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(SetBouncey, function_hook_state_SetBouncey)
static int(__cdecl*original_SetBouncey)(tPowerup *, tCar_spec *) = (int(__cdecl*)(tPowerup *, tCar_spec *))0x0042e4fd;
CARM95_HOOK_FUNCTION(original_SetBouncey, SetBouncey)
int __cdecl SetBouncey(tPowerup *pPowerup, tCar_spec *pCar) {
    LOG_TRACE("(%p, %p)", pPowerup, pCar);

    (void)pPowerup;
    (void)pCar;

    if (function_hook_state_SetBouncey == HOOK_ENABLED) {
        pCar->bounce_rate = 1000.f / pPowerup->float_params[0];
        pCar->bounce_amount = pPowerup->float_params[1];
        pCar->last_bounce = 0;
        return GET_POWERUP_INDEX(pPowerup);
    } else {
        return original_SetBouncey(pPowerup, pCar);
    }
}

function_hook_state_t function_hook_state_SetSuspension = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(SetSuspension, function_hook_state_SetSuspension)
static int(__cdecl*original_SetSuspension)(tPowerup *, tCar_spec *) = (int(__cdecl*)(tPowerup *, tCar_spec *))0x0042e554;
CARM95_HOOK_FUNCTION(original_SetSuspension, SetSuspension)
int __cdecl SetSuspension(tPowerup *pPowerup, tCar_spec *pCar) {
    LOG_TRACE("(%p, %p)", pPowerup, pCar);

    (void)pPowerup;
    (void)pCar;

    if (function_hook_state_SetSuspension == HOOK_ENABLED) {
        SetCarSuspGiveAndHeight(pCar,
                                pPowerup->float_params[0], pPowerup->float_params[1], pPowerup->float_params[4],
                                pPowerup->float_params[2], pPowerup->float_params[3]);
        return GET_POWERUP_INDEX(pPowerup);
    } else {
        return original_SetSuspension(pPowerup, pCar);
    }
}

function_hook_state_t function_hook_state_SetTyreGrip = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(SetTyreGrip, function_hook_state_SetTyreGrip)
static int(__cdecl*original_SetTyreGrip)(tPowerup *, tCar_spec *) = (int(__cdecl*)(tPowerup *, tCar_spec *))0x0042e5b2;
CARM95_HOOK_FUNCTION(original_SetTyreGrip, SetTyreGrip)
int __cdecl SetTyreGrip(tPowerup *pPowerup, tCar_spec *pCar) {
    LOG_TRACE("(%p, %p)", pPowerup, pCar);

    (void)pPowerup;
    (void)pCar;

    if (function_hook_state_SetTyreGrip == HOOK_ENABLED) {
        pCar->grip_multiplier = pPowerup->float_params[0];
        return GET_POWERUP_INDEX(pPowerup);
    } else {
        return original_SetTyreGrip(pPowerup, pCar);
    }
}

function_hook_state_t function_hook_state_SetDamageMultiplier = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(SetDamageMultiplier, function_hook_state_SetDamageMultiplier)
static int(__cdecl*original_SetDamageMultiplier)(tPowerup *, tCar_spec *) = (int(__cdecl*)(tPowerup *, tCar_spec *))0x0042e5e4;
CARM95_HOOK_FUNCTION(original_SetDamageMultiplier, SetDamageMultiplier)
int __cdecl SetDamageMultiplier(tPowerup *pPowerup, tCar_spec *pCar) {
    LOG_TRACE("(%p, %p)", pPowerup, pCar);

    (void)pPowerup;
    (void)pCar;

    if (function_hook_state_SetDamageMultiplier == HOOK_ENABLED) {
        pCar->damage_multiplier = pPowerup->float_params[0];
        return GET_POWERUP_INDEX(pPowerup);
    } else {
        return original_SetDamageMultiplier(pPowerup, pCar);
    }
}

function_hook_state_t function_hook_state_ResetEngineFactor = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(ResetEngineFactor, function_hook_state_ResetEngineFactor)
static void(__cdecl*original_ResetEngineFactor)(tPowerup *, tCar_spec *) = (void(__cdecl*)(tPowerup *, tCar_spec *))0x0042e616;
CARM95_HOOK_FUNCTION(original_ResetEngineFactor, ResetEngineFactor)
void __cdecl ResetEngineFactor(tPowerup *pPowerup, tCar_spec *pCar) {
    LOG_TRACE("(%p, %p)", pPowerup, pCar);

    (void)pPowerup;
    (void)pCar;

    if (function_hook_state_ResetEngineFactor == HOOK_ENABLED) {
        pCar->engine_power_multiplier = 1.f;
        pCar->grip_multiplier = 1.f;
        SetCarSuspGiveAndHeight(pCar, 1.f, 1.f, 1.f, 0.f, 0.f);
    } else {
        original_ResetEngineFactor(pPowerup, pCar);
    }
}

function_hook_state_t function_hook_state_ResetUnderwater = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(ResetUnderwater, function_hook_state_ResetUnderwater)
static void(__cdecl*original_ResetUnderwater)(tPowerup *, tCar_spec *) = (void(__cdecl*)(tPowerup *, tCar_spec *))0x0042e65a;
CARM95_HOOK_FUNCTION(original_ResetUnderwater, ResetUnderwater)
void __cdecl ResetUnderwater(tPowerup *pPowerup, tCar_spec *pCar) {
    LOG_TRACE("(%p, %p)", pPowerup, pCar);

    (void)pPowerup;
    (void)pCar;

    if (function_hook_state_ResetUnderwater == HOOK_ENABLED) {
        pCar->underwater_ability = 0;
    } else {
        original_ResetUnderwater(pPowerup, pCar);
    }
}

function_hook_state_t function_hook_state_PukeDrugsBackUp = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(PukeDrugsBackUp, function_hook_state_PukeDrugsBackUp)
static void(__cdecl*original_PukeDrugsBackUp)(tPowerup *, tCar_spec *) = (void(__cdecl*)(tPowerup *, tCar_spec *))0x0042e672;
CARM95_HOOK_FUNCTION(original_PukeDrugsBackUp, PukeDrugsBackUp)
void __cdecl PukeDrugsBackUp(tPowerup *pPowerup, tCar_spec *pCar) {
    LOG_TRACE("(%p, %p)", pPowerup, pCar);

    (void)pPowerup;
    (void)pCar;

    if (function_hook_state_PukeDrugsBackUp == HOOK_ENABLED) {
        if (pCar->driver == eDriver_local_human) {
            HV(gOn_drugs) = 0;
            PaletteFuckedUpByDrugs(HV(gRender_palette), 0);
            ResetPalette();
        }
    } else {
        original_PukeDrugsBackUp(pPowerup, pCar);
    }
}

function_hook_state_t function_hook_state_ResetOpponentsSpeed = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(ResetOpponentsSpeed, function_hook_state_ResetOpponentsSpeed)
static void(__cdecl*original_ResetOpponentsSpeed)(tPowerup *, tCar_spec *) = (void(__cdecl*)(tPowerup *, tCar_spec *))0x0042e6a9;
CARM95_HOOK_FUNCTION(original_ResetOpponentsSpeed, ResetOpponentsSpeed)
void __cdecl ResetOpponentsSpeed(tPowerup *pPowerup, tCar_spec *pCar) {
    int i;
    LOG_TRACE("(%p, %p)", pPowerup, pCar);

    (void)pPowerup;
    (void)pCar;
    (void)i;

    if (function_hook_state_ResetOpponentsSpeed == HOOK_ENABLED) {
        for (i = 0; i < HV(gCurrent_race).number_of_racers && HV(gCurrent_race).opponent_list[i].index != 29; i++) {
        }
        if (i < HV(gCurrent_race).number_of_racers) {
            ResetEngineFactor(&HV(gPowerup_array)[5], HV(gCurrent_race).opponent_list[i].car_spec);
        }
        HV(gOpponent_speed_factor) = 1.f;
    } else {
        original_ResetOpponentsSpeed(pPowerup, pCar);
    }
}

function_hook_state_t function_hook_state_ResetCopsSpeed = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(ResetCopsSpeed, function_hook_state_ResetCopsSpeed)
static void(__cdecl*original_ResetCopsSpeed)(tPowerup *, tCar_spec *) = (void(__cdecl*)(tPowerup *, tCar_spec *))0x0042e726;
CARM95_HOOK_FUNCTION(original_ResetCopsSpeed, ResetCopsSpeed)
void __cdecl ResetCopsSpeed(tPowerup *pPowerup, tCar_spec *pCar) {
    LOG_TRACE("(%p, %p)", pPowerup, pCar);

    (void)pPowerup;
    (void)pCar;

    if (function_hook_state_ResetCopsSpeed == HOOK_ENABLED) {
        HV(gCop_speed_factor) = 1.f;
    } else {
        original_ResetCopsSpeed(pPowerup, pCar);
    }
}

function_hook_state_t function_hook_state_ResetGravity = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(ResetGravity, function_hook_state_ResetGravity)
static void(__cdecl*original_ResetGravity)(tPowerup *, tCar_spec *) = (void(__cdecl*)(tPowerup *, tCar_spec *))0x0042e73b;
CARM95_HOOK_FUNCTION(original_ResetGravity, ResetGravity)
void __cdecl ResetGravity(tPowerup *pPowerup, tCar_spec *pCar) {
    LOG_TRACE("(%p, %p)", pPowerup, pCar);

    (void)pPowerup;
    (void)pCar;

    if (function_hook_state_ResetGravity == HOOK_ENABLED) {
        HV(gGravity_multiplier) = HV(gDefault_gravity);
    } else {
        original_ResetGravity(pPowerup, pCar);
    }
}

function_hook_state_t function_hook_state_ResetPinball = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(ResetPinball, function_hook_state_ResetPinball)
static void(__cdecl*original_ResetPinball)(tPowerup *, tCar_spec *) = (void(__cdecl*)(tPowerup *, tCar_spec *))0x0042e750;
CARM95_HOOK_FUNCTION(original_ResetPinball, ResetPinball)
void __cdecl ResetPinball(tPowerup *pPowerup, tCar_spec *pCar) {
    LOG_TRACE("(%p, %p)", pPowerup, pCar);

    (void)pPowerup;
    (void)pCar;

    if (function_hook_state_ResetPinball == HOOK_ENABLED) {
        HV(gPinball_factor) = 0.f;
    } else {
        original_ResetPinball(pPowerup, pCar);
    }
}

function_hook_state_t function_hook_state_ResetWallclimb = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(ResetWallclimb, function_hook_state_ResetWallclimb)
static void(__cdecl*original_ResetWallclimb)(tPowerup *, tCar_spec *) = (void(__cdecl*)(tPowerup *, tCar_spec *))0x0042e765;
CARM95_HOOK_FUNCTION(original_ResetWallclimb, ResetWallclimb)
void __cdecl ResetWallclimb(tPowerup *pPowerup, tCar_spec *pCar) {
    LOG_TRACE("(%p, %p)", pPowerup, pCar);

    (void)pPowerup;
    (void)pCar;

    if (function_hook_state_ResetWallclimb == HOOK_ENABLED) {
        pCar->wall_climber_mode = 0;
    } else {
        original_ResetWallclimb(pPowerup, pCar);
    }
}

function_hook_state_t function_hook_state_ResetBouncey = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(ResetBouncey, function_hook_state_ResetBouncey)
static void(__cdecl*original_ResetBouncey)(tPowerup *, tCar_spec *) = (void(__cdecl*)(tPowerup *, tCar_spec *))0x0042e77d;
CARM95_HOOK_FUNCTION(original_ResetBouncey, ResetBouncey)
void __cdecl ResetBouncey(tPowerup *pPowerup, tCar_spec *pCar) {
    LOG_TRACE("(%p, %p)", pPowerup, pCar);

    (void)pPowerup;
    (void)pCar;

    if (function_hook_state_ResetBouncey == HOOK_ENABLED) {
        pCar->bounce_rate = 0.f;
        pCar->bounce_amount = 0.f;
    } else {
        original_ResetBouncey(pPowerup, pCar);
    }
}

function_hook_state_t function_hook_state_ResetSuspension = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(ResetSuspension, function_hook_state_ResetSuspension)
static void(__cdecl*original_ResetSuspension)(tPowerup *, tCar_spec *) = (void(__cdecl*)(tPowerup *, tCar_spec *))0x0042e7a2;
CARM95_HOOK_FUNCTION(original_ResetSuspension, ResetSuspension)
void __cdecl ResetSuspension(tPowerup *pPowerup, tCar_spec *pCar) {
    LOG_TRACE("(%p, %p)", pPowerup, pCar);

    (void)pPowerup;
    (void)pCar;

    if (function_hook_state_ResetSuspension == HOOK_ENABLED) {
        SetCarSuspGiveAndHeight(pCar, 1.f, 1.f, 1.f, 0.f, 0.f);
    } else {
        original_ResetSuspension(pPowerup, pCar);
    }
}

function_hook_state_t function_hook_state_ResetDamageMultiplier = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(ResetDamageMultiplier, function_hook_state_ResetDamageMultiplier)
static void(__cdecl*original_ResetDamageMultiplier)(tPowerup *, tCar_spec *) = (void(__cdecl*)(tPowerup *, tCar_spec *))0x0042e7cc;
CARM95_HOOK_FUNCTION(original_ResetDamageMultiplier, ResetDamageMultiplier)
void __cdecl ResetDamageMultiplier(tPowerup *pPowerup, tCar_spec *pCar) {
    LOG_TRACE("(%p, %p)", pPowerup, pCar);

    (void)pPowerup;
    (void)pCar;

    if (function_hook_state_ResetDamageMultiplier == HOOK_ENABLED) {
        pCar->damage_multiplier = 1.f;
    } else {
        original_ResetDamageMultiplier(pPowerup, pCar);
    }
}

function_hook_state_t function_hook_state_ResetTyreGrip = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(ResetTyreGrip, function_hook_state_ResetTyreGrip)
static void(__cdecl*original_ResetTyreGrip)(tPowerup *, tCar_spec *) = (void(__cdecl*)(tPowerup *, tCar_spec *))0x0042e7e4;
CARM95_HOOK_FUNCTION(original_ResetTyreGrip, ResetTyreGrip)
void __cdecl ResetTyreGrip(tPowerup *pPowerup, tCar_spec *pCar) {
    LOG_TRACE("(%p, %p)", pPowerup, pCar);

    (void)pPowerup;
    (void)pCar;

    if (function_hook_state_ResetTyreGrip == HOOK_ENABLED) {
        pCar->grip_multiplier = 1.f;
    } else {
        original_ResetTyreGrip(pPowerup, pCar);
    }
}

function_hook_state_t function_hook_state_PickAtRandom = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(PickAtRandom, function_hook_state_PickAtRandom)
static int(__cdecl*original_PickAtRandom)(tPowerup *, tCar_spec *) = (int(__cdecl*)(tPowerup *, tCar_spec *))0x0042e7fc;
CARM95_HOOK_FUNCTION(original_PickAtRandom, PickAtRandom)
int __cdecl PickAtRandom(tPowerup *pPowerup, tCar_spec *pCar) {
    LOG_TRACE("(%p, %p)", pPowerup, pCar);

    (void)pPowerup;
    (void)pCar;

    if (function_hook_state_PickAtRandom == HOOK_ENABLED) {
        return GotPowerup(pCar, pPowerup->integer_params[IRandomBetween(0, pPowerup->number_of_integer_params - 1)]);
    } else {
        return original_PickAtRandom(pPowerup, pCar);
    }
}

function_hook_state_t function_hook_state_PedestrianRespawn = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(PedestrianRespawn, function_hook_state_PedestrianRespawn)
static int(__cdecl*original_PedestrianRespawn)(tPowerup *, tCar_spec *) = (int(__cdecl*)(tPowerup *, tCar_spec *))0x0042e834;
CARM95_HOOK_FUNCTION(original_PedestrianRespawn, PedestrianRespawn)
int __cdecl PedestrianRespawn(tPowerup *pPowerup, tCar_spec *pCar) {
    LOG_TRACE("(%p, %p)", pPowerup, pCar);

    (void)pPowerup;
    (void)pCar;

    if (function_hook_state_PedestrianRespawn == HOOK_ENABLED) {
        RespawnPedestrians();
        return GET_POWERUP_INDEX(pPowerup);
    } else {
        return original_PedestrianRespawn(pPowerup, pCar);
    }
}

function_hook_state_t function_hook_state_GotVouchers = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(GotVouchers, function_hook_state_GotVouchers)
static int(__cdecl*original_GotVouchers)(tPowerup *, tCar_spec *) = (int(__cdecl*)(tPowerup *, tCar_spec *))0x0042e85a;
CARM95_HOOK_FUNCTION(original_GotVouchers, GotVouchers)
int __cdecl GotVouchers(tPowerup *pPowerup, tCar_spec *pCar) {
    LOG_TRACE("(%p, %p)", pPowerup, pCar);

    (void)pPowerup;
    (void)pCar;

    if (function_hook_state_GotVouchers == HOOK_ENABLED) {
        if (pCar->driver == eDriver_local_human) {
            AddVouchers(pPowerup->integer_params[0]);
        }
        return GET_POWERUP_INDEX(pPowerup);
    } else {
        return original_GotVouchers(pPowerup, pCar);
    }
}

function_hook_state_t function_hook_state_MungeVouchers = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(MungeVouchers, function_hook_state_MungeVouchers)
static void(__cdecl*original_MungeVouchers)(tPowerup *, tU32) = (void(__cdecl*)(tPowerup *, tU32))0x0042e899;
CARM95_HOOK_FUNCTION(original_MungeVouchers, MungeVouchers)
void __cdecl MungeVouchers(tPowerup *pPowerup, tU32 pPeriod) {
    LOG_TRACE("(%p, %u)", pPowerup, pPeriod);

    (void)pPowerup;
    (void)pPeriod;

    if (function_hook_state_MungeVouchers == HOOK_ENABLED) {
        pPowerup->current_value = GetRecoverVoucherCount();
    } else {
        original_MungeVouchers(pPowerup, pPeriod);
    }
}

function_hook_state_t function_hook_state_SetInstantHandbrake = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(SetInstantHandbrake, function_hook_state_SetInstantHandbrake)
static int(__cdecl*original_SetInstantHandbrake)(tPowerup *, tCar_spec *) = (int(__cdecl*)(tPowerup *, tCar_spec *))0x0042e8af;
CARM95_HOOK_FUNCTION(original_SetInstantHandbrake, SetInstantHandbrake)
int __cdecl SetInstantHandbrake(tPowerup *pPowerup, tCar_spec *pCar) {
    LOG_TRACE("(%p, %p)", pPowerup, pCar);

    (void)pPowerup;
    (void)pCar;

    if (function_hook_state_SetInstantHandbrake == HOOK_ENABLED) {
        if (pCar->driver == eDriver_local_human) {
            HV(gInstant_handbrake) = 1;
        }
        return GET_POWERUP_INDEX(pPowerup);
    } else {
        return original_SetInstantHandbrake(pPowerup, pCar);
    }
}

function_hook_state_t function_hook_state_ResetInstantHandbrake = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(ResetInstantHandbrake, function_hook_state_ResetInstantHandbrake)
static void(__cdecl*original_ResetInstantHandbrake)(tPowerup *, tCar_spec *) = (void(__cdecl*)(tPowerup *, tCar_spec *))0x0042e8e7;
CARM95_HOOK_FUNCTION(original_ResetInstantHandbrake, ResetInstantHandbrake)
void __cdecl ResetInstantHandbrake(tPowerup *pPowerup, tCar_spec *pCar) {
    LOG_TRACE("(%p, %p)", pPowerup, pCar);

    (void)pPowerup;
    (void)pCar;

    if (function_hook_state_ResetInstantHandbrake == HOOK_ENABLED) {
        if (pCar->driver == eDriver_local_human) {
            HV(gInstant_handbrake) = 0;
        }
    } else {
        original_ResetInstantHandbrake(pPowerup, pCar);
    }
}

function_hook_state_t function_hook_state_DoBouncey = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(DoBouncey, function_hook_state_DoBouncey)
static void(__cdecl*original_DoBouncey)(tPowerup *, tU32) = (void(__cdecl*)(tPowerup *, tU32))0x0042e909;
CARM95_HOOK_FUNCTION(original_DoBouncey, DoBouncey)
void __cdecl DoBouncey(tPowerup *pPowerup, tU32 pPeriod) {
    LOG_TRACE("(%p, %u)", pPowerup, pPeriod);

    (void)pPowerup;
    (void)pPeriod;

    if (function_hook_state_DoBouncey == HOOK_ENABLED) {
        if (HV(gProgram_state).current_car.bounce_rate <= GetTotalTime() - HV(gProgram_state).current_car.last_bounce && HV(gProgram_state).current_car.number_of_wheels_on_ground > 2) {
            PratcamEvent(42);
            HV(gProgram_state).current_car.last_bounce = GetTotalTime();
            HV(gProgram_state).current_car.v.v[1] += HV(gProgram_state).current_car.bounce_amount;
            DRS3StartSound(HV(gCar_outlet), 9010);
        }
    } else {
        original_DoBouncey(pPowerup, pPeriod);
    }
}

function_hook_state_t function_hook_state_HitMine = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(HitMine, function_hook_state_HitMine)
static int(__cdecl*original_HitMine)(tPowerup *, tCar_spec *) = (int(__cdecl*)(tPowerup *, tCar_spec *))0x0042e986;
CARM95_HOOK_FUNCTION(original_HitMine, HitMine)
int __cdecl HitMine(tPowerup *pPowerup, tCar_spec *pCar) {
    int i;
    float fudge_multiplier;
    LOG_TRACE("(%p, %p)", pPowerup, pCar);

    (void)pPowerup;
    (void)pCar;
    (void)i;
    (void)fudge_multiplier;

    if (function_hook_state_HitMine == HOOK_ENABLED) {
        pCar->v.v[1] = FRandomBetween(pPowerup->float_params[0], pPowerup->float_params[1]) / pCar->M + pCar->v.v[1];
        pCar->omega.v[2] = FRandomPosNeg(pPowerup->float_params[2]) * TAU / pCar->M + pCar->omega.v[2];
        pCar->omega.v[0] = FRandomPosNeg(pPowerup->float_params[3]) * TAU / pCar->M + pCar->omega.v[0];
        if (pCar->driver != eDriver_non_car_unused_slot && !pCar->invulnerable) {
            fudge_multiplier = pCar->car_model_actors[pCar->principal_car_actor].crush_data.softness_factor / .7f;
            for (i = 0; i < pCar->car_actor_count; i++) {
                TotallySpamTheModel(pCar, i, pCar->car_model_actors[i].actor,
                                    &pCar->car_model_actors[i].crush_data, fudge_multiplier * .1f);
            }
            for (i = 0; i < 12; i++) {
                DamageUnit(pCar, i, IRandomBetween(0, fudge_multiplier * 15.f));
            }
        }
        return GET_POWERUP_INDEX(pPowerup);
    } else {
        return original_HitMine(pPowerup, pCar);
    }
}

function_hook_state_t function_hook_state_SetMassMultiplier = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(SetMassMultiplier, function_hook_state_SetMassMultiplier)
static int(__cdecl*original_SetMassMultiplier)(tPowerup *, tCar_spec *) = (int(__cdecl*)(tPowerup *, tCar_spec *))0x0042eb2f;
CARM95_HOOK_FUNCTION(original_SetMassMultiplier, SetMassMultiplier)
int __cdecl SetMassMultiplier(tPowerup *pPowerup, tCar_spec *pCar) {
    LOG_TRACE("(%p, %p)", pPowerup, pCar);

    (void)pPowerup;
    (void)pCar;

    if (function_hook_state_SetMassMultiplier == HOOK_ENABLED) {
        pCar->collision_mass_multiplier = pPowerup->float_params[0];
        return GET_POWERUP_INDEX(pPowerup);
    } else {
        return original_SetMassMultiplier(pPowerup, pCar);
    }
}

function_hook_state_t function_hook_state_ResetMassMultiplier = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(ResetMassMultiplier, function_hook_state_ResetMassMultiplier)
static void(__cdecl*original_ResetMassMultiplier)(tPowerup *, tCar_spec *) = (void(__cdecl*)(tPowerup *, tCar_spec *))0x0042eb61;
CARM95_HOOK_FUNCTION(original_ResetMassMultiplier, ResetMassMultiplier)
void __cdecl ResetMassMultiplier(tPowerup *pPowerup, tCar_spec *pCar) {
    LOG_TRACE("(%p, %p)", pPowerup, pCar);

    (void)pPowerup;
    (void)pCar;

    if (function_hook_state_ResetMassMultiplier == HOOK_ENABLED) {
        pCar->collision_mass_multiplier = 1.f;
    } else {
        original_ResetMassMultiplier(pPowerup, pCar);
    }
}

function_hook_state_t function_hook_state_ShowPedestrians = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(ShowPedestrians, function_hook_state_ShowPedestrians)
static int(__cdecl*original_ShowPedestrians)(tPowerup *, tCar_spec *) = (int(__cdecl*)(tPowerup *, tCar_spec *))0x0042eb79;
CARM95_HOOK_FUNCTION(original_ShowPedestrians, ShowPedestrians)
int __cdecl ShowPedestrians(tPowerup *pPowerup, tCar_spec *pCar) {
    LOG_TRACE("(%p, %p)", pPowerup, pCar);

    (void)pPowerup;
    (void)pCar;

    if (function_hook_state_ShowPedestrians == HOOK_ENABLED) {
        if (pCar->driver == eDriver_local_human) {
            HV(gShow_peds_on_map) = 1;
        }
        return GET_POWERUP_INDEX(pPowerup);
    } else {
        return original_ShowPedestrians(pPowerup, pCar);
    }
}

function_hook_state_t function_hook_state_HidePedestrians = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(HidePedestrians, function_hook_state_HidePedestrians)
static void(__cdecl*original_HidePedestrians)(tPowerup *, tCar_spec *) = (void(__cdecl*)(tPowerup *, tCar_spec *))0x0042ebb1;
CARM95_HOOK_FUNCTION(original_HidePedestrians, HidePedestrians)
void __cdecl HidePedestrians(tPowerup *pPowerup, tCar_spec *pCar) {
    LOG_TRACE("(%p, %p)", pPowerup, pCar);

    (void)pPowerup;
    (void)pCar;

    if (function_hook_state_HidePedestrians == HOOK_ENABLED) {
        if (pCar->driver == eDriver_local_human) {
            HV(gShow_peds_on_map) = 0;
        }
    } else {
        original_HidePedestrians(pPowerup, pCar);
    }
}

function_hook_state_t function_hook_state_SetProximity = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(SetProximity, function_hook_state_SetProximity)
static int(__cdecl*original_SetProximity)(tPowerup *, tCar_spec *) = (int(__cdecl*)(tPowerup *, tCar_spec *))0x0042ebd3;
CARM95_HOOK_FUNCTION(original_SetProximity, SetProximity)
int __cdecl SetProximity(tPowerup *pPowerup, tCar_spec *pCar) {
    LOG_TRACE("(%p, %p)", pPowerup, pCar);

    (void)pPowerup;
    (void)pCar;

    if (function_hook_state_SetProximity == HOOK_ENABLED) {
        pCar->proxy_ray_distance = pPowerup->float_params[0] * pPowerup->float_params[0];
        return GET_POWERUP_INDEX(pPowerup);
    } else {
        return original_SetProximity(pPowerup, pCar);
    }
}

function_hook_state_t function_hook_state_ResetProximity = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(ResetProximity, function_hook_state_ResetProximity)
static void(__cdecl*original_ResetProximity)(tPowerup *, tCar_spec *) = (void(__cdecl*)(tPowerup *, tCar_spec *))0x0042ec0d;
CARM95_HOOK_FUNCTION(original_ResetProximity, ResetProximity)
void __cdecl ResetProximity(tPowerup *pPowerup, tCar_spec *pCar) {
    LOG_TRACE("(%p, %p)", pPowerup, pCar);

    (void)pPowerup;
    (void)pCar;

    if (function_hook_state_ResetProximity == HOOK_ENABLED) {
        pCar->proxy_ray_distance = 0.f;
    } else {
        original_ResetProximity(pPowerup, pCar);
    }
}

function_hook_state_t function_hook_state_SetPedHarvest = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(SetPedHarvest, function_hook_state_SetPedHarvest)
static int(__cdecl*original_SetPedHarvest)(tPowerup *, tCar_spec *) = (int(__cdecl*)(tPowerup *, tCar_spec *))0x0042ec25;
CARM95_HOOK_FUNCTION(original_SetPedHarvest, SetPedHarvest)
int __cdecl SetPedHarvest(tPowerup *pPowerup, tCar_spec *pCar) {
    LOG_TRACE("(%p, %p)", pPowerup, pCar);

    (void)pPowerup;
    (void)pCar;

    if (function_hook_state_SetPedHarvest == HOOK_ENABLED) {
        HV(gPedestrian_harvest) = 1;
        return GET_POWERUP_INDEX(pPowerup);
    } else {
        return original_SetPedHarvest(pPowerup, pCar);
    }
}

function_hook_state_t function_hook_state_ResetPedHarvest = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(ResetPedHarvest, function_hook_state_ResetPedHarvest)
static void(__cdecl*original_ResetPedHarvest)(tPowerup *, tCar_spec *) = (void(__cdecl*)(tPowerup *, tCar_spec *))0x0042ec50;
CARM95_HOOK_FUNCTION(original_ResetPedHarvest, ResetPedHarvest)
void __cdecl ResetPedHarvest(tPowerup *pPowerup, tCar_spec *pCar) {
    int i;
    LOG_TRACE("(%p, %p)", pPowerup, pCar);

    (void)pPowerup;
    (void)pCar;
    (void)i;

    if (function_hook_state_ResetPedHarvest == HOOK_ENABLED) {
        HV(gPedestrian_harvest) = 0;
        for (i = 0; i < COUNT_OF(HV(gPed_harvest_sounds)); i++) {
            DRS3StartSound3D(HV(gPedestrians_outlet), HV(gPed_harvest_sounds)[i], &pCar->pos,
                             &HV(gZero_v__powerup), 1, 255, -1, -1);
        }
    } else {
        original_ResetPedHarvest(pPowerup, pCar);
    }
}

function_hook_state_t function_hook_state_SetVesuvianCorpses = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(SetVesuvianCorpses, function_hook_state_SetVesuvianCorpses)
static int(__cdecl*original_SetVesuvianCorpses)(tPowerup *, tCar_spec *) = (int(__cdecl*)(tPowerup *, tCar_spec *))0x0042ecb8;
CARM95_HOOK_FUNCTION(original_SetVesuvianCorpses, SetVesuvianCorpses)
int __cdecl SetVesuvianCorpses(tPowerup *pPowerup, tCar_spec *pCar) {
    LOG_TRACE("(%p, %p)", pPowerup, pCar);

    (void)pPowerup;
    (void)pCar;

    if (function_hook_state_SetVesuvianCorpses == HOOK_ENABLED) {
        HV(gVesuvian_corpses) = 1;
        return GET_POWERUP_INDEX(pPowerup);
    } else {
        return original_SetVesuvianCorpses(pPowerup, pCar);
    }
}

function_hook_state_t function_hook_state_ResetVesuvianCorpses = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(ResetVesuvianCorpses, function_hook_state_ResetVesuvianCorpses)
static void(__cdecl*original_ResetVesuvianCorpses)(tPowerup *, tCar_spec *) = (void(__cdecl*)(tPowerup *, tCar_spec *))0x0042ece3;
CARM95_HOOK_FUNCTION(original_ResetVesuvianCorpses, ResetVesuvianCorpses)
void __cdecl ResetVesuvianCorpses(tPowerup *pPowerup, tCar_spec *pCar) {
    LOG_TRACE("(%p, %p)", pPowerup, pCar);

    (void)pPowerup;
    (void)pCar;

    if (function_hook_state_ResetVesuvianCorpses == HOOK_ENABLED) {
        HV(gVesuvian_corpses) = 0;
    } else {
        original_ResetVesuvianCorpses(pPowerup, pCar);
    }
}

function_hook_state_t function_hook_state_ReceivedPowerup = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(ReceivedPowerup, function_hook_state_ReceivedPowerup)
static void(__cdecl*original_ReceivedPowerup)(tNet_contents *) = (void(__cdecl*)(tNet_contents *))0x0042ecf8;
CARM95_HOOK_FUNCTION(original_ReceivedPowerup, ReceivedPowerup)
void __cdecl ReceivedPowerup(tNet_contents *pContents) {
    tPowerup *powerup;
    tCar_spec *car;
    LOG_TRACE("(%p)", pContents);

    (void)pContents;
    (void)powerup;
    (void)car;

    if (function_hook_state_ReceivedPowerup == HOOK_ENABLED) {
        if (HV(gProgram_state).racing && pContents->data.powerup.powerup_index >= 0 && pContents->data.powerup.powerup_index < HV(gNumber_of_powerups)) {
            powerup = &HV(gPowerup_array)[pContents->data.powerup.powerup_index];
            if (pContents->data.powerup.event == ePowerup_gained || pContents->data.powerup.event == ePowerup_ongoing) {
                if (powerup->net_type == eNet_powerup_global) {
                    GotPowerupX(&HV(gProgram_state).current_car, pContents->data.powerup.powerup_index, 0,
                                pContents->data.powerup.event == ePowerup_gained, pContents->data.powerup.time_left);
                } else if (powerup->net_type == eNet_powerup_local && pContents->data.powerup.player != HV(gLocal_net_ID) && powerup->got_proc != NULL) {
                    car = NetCarFromPlayerID(pContents->data.powerup.player);
                    if (car != NULL) {
                        powerup->got_proc(powerup, car);
                        switch (powerup->type) {
                            case ePowerup_timed:
                                car->powerups[pContents->data.powerup.powerup_index] = GetTotalTime() + pContents->data.powerup.time_left;
                                break;
                            case ePowerup_whole_race:
                                car->powerups[pContents->data.powerup.powerup_index] = -1;
                                break;
                            default:
                                break;
                        }
                    }
                }
            } else if (powerup->net_type == eNet_powerup_local && powerup->lose_proc != NULL) {
                car = NetCarFromPlayerID(pContents->data.powerup.player);
                if (car != NULL) {
                    powerup->lose_proc(powerup, car);
                    car->powerups[pContents->data.powerup.powerup_index] = 0;
                }
            }
        }
    } else {
        original_ReceivedPowerup(pContents);
    }
}

function_hook_state_t function_hook_state_SendCurrentPowerups = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(SendCurrentPowerups, function_hook_state_SendCurrentPowerups)
static void(__cdecl*original_SendCurrentPowerups)() = (void(__cdecl*)())0x0042eed9;
CARM95_HOOK_FUNCTION(original_SendCurrentPowerups, SendCurrentPowerups)
void __cdecl SendCurrentPowerups() {
    int i;
    int cat;
    int j;
    int car_count;
    tCar_spec *car;
    tNet_contents *the_contents;
    tPlayer_ID ID;
    LOG_TRACE("()");

    (void)i;
    (void)cat;
    (void)j;
    (void)car_count;
    (void)car;
    (void)the_contents;
    (void)ID;

    if (function_hook_state_SendCurrentPowerups == HOOK_ENABLED) {
        for (cat = eVehicle_self; cat < eVehicle_net_player; cat++) {
            if (cat == eVehicle_self) {
                car_count = 1;
            } else {
                car_count = GetCarCount(cat);
            }
            for (i = 0; i < car_count; i++) {
                if (cat == eVehicle_self) {
                    car = &HV(gProgram_state).current_car;
                } else {
                    car = GetCarSpec(cat, i);
                }
#if defined(DETHRACE_FIX_BUGS)
                ID = HV(gNet_players)[0].ID;
#endif
                for (j = 0; j < HV(gNumber_of_net_players); j++) {
                    if (HV(gNet_players)[j].car == car) {
                        ID = HV(gNet_players)[j].ID;
                        break;
                    }
                }
                for (j = 0; j < HV(gNumber_of_powerups); j++) {
                    if (car->powerups[j] != 0) {
                        the_contents = NetGetBroadcastContents(21, 0);
                        the_contents->data.powerup.event = ePowerup_ongoing;
                        the_contents->data.powerup.player = ID;
                        the_contents->data.powerup.powerup_index = j;
                        the_contents->data.powerup.time_left = car->powerups[i] - GetTotalTime();
                    }
                }
            }
        }
    } else {
        original_SendCurrentPowerups();
    }
}

function_hook_state_t function_hook_state_LoseAllLocalPowerups = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(LoseAllLocalPowerups, function_hook_state_LoseAllLocalPowerups)
static void(__cdecl*original_LoseAllLocalPowerups)(tCar_spec *) = (void(__cdecl*)(tCar_spec *))0x0042f043;
CARM95_HOOK_FUNCTION(original_LoseAllLocalPowerups, LoseAllLocalPowerups)
void __cdecl LoseAllLocalPowerups(tCar_spec *pCar) {
    int i;
    LOG_TRACE("(%p)", pCar);

    (void)pCar;
    (void)i;

    if (function_hook_state_LoseAllLocalPowerups == HOOK_ENABLED) {
        if (pCar->driver == eDriver_local_human) {
            for (i = 0; i < HV(gNumber_of_powerups); i++) {
                if (pCar->powerups[i] != 0 && HV(gPowerup_array)[i].net_type == eNet_powerup_local) {
                    LosePowerup(&HV(gPowerup_array)[i]);
                }
            }
        }
    } else {
        original_LoseAllLocalPowerups(pCar);
    }
}

// Added by dethrace
function_hook_state_t function_hook_state_GetPowerupMessage = HOOK_ENABLED;
static void(__cdecl*original_GetPowerupMessage)(int , char*) = (void(__cdecl*)(int, char *))0x0042f0cc;
CARM95_HOOK_FUNCTION(original_GetPowerupMessage, GetPowerupMessage)
void GetPowerupMessage(int pN, char* pMessage) {


    if (function_hook_state_GetPowerupMessage == HOOK_ENABLED) {
        switch (pN) {
            case 0:
                strcpy(pMessage, "Bonus");
                break;
            case 1:
                strcpy(pMessage, "Mega Bonus");
                break;
            case 14:
            case 46:
                strcpy(pMessage, "Mine");
                break;
            case 28:
            case 29:
            case 30:
            case 31:
                strcpy(pMessage, "Random");
                break;
            default:
                strcpy(pMessage, HV(gPowerup_array)[pN].message);
                break;
        }
    } else {
        original_GetPowerupMessage(pN, pMessage);
    }
}

