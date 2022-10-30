#include "powerup.h"

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

function_hook_state_t function_hook_state_LosePowerupX = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_LosePowerupX)
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
        assert(0 && "LosePowerupX not implemented.");
        abort();
    } else {
        original_LosePowerupX(pThe_powerup, pTell_net_players);
    }
}

function_hook_state_t function_hook_state_LosePowerup = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_LosePowerup)
static void(__cdecl*original_LosePowerup)(tPowerup *) = (void(__cdecl*)(tPowerup *))0x0042cfdd;
CARM95_HOOK_FUNCTION(original_LosePowerup, LosePowerup)
void __cdecl LosePowerup(tPowerup *pThe_powerup) {
    LOG_TRACE("(%p)", pThe_powerup);

    (void)pThe_powerup;

    if (function_hook_state_LosePowerup == HOOK_ENABLED) {
        assert(0 && "LosePowerup not implemented.");
        abort();
    } else {
        original_LosePowerup(pThe_powerup);
    }
}

function_hook_state_t function_hook_state_LoseAllSimilarPowerups = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_LoseAllSimilarPowerups)
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
        assert(0 && "LoseAllSimilarPowerups not implemented.");
        abort();
    } else {
        original_LoseAllSimilarPowerups(pThe_powerup);
    }
}

function_hook_state_t function_hook_state_GotPowerupX = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_GotPowerupX)
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
        assert(0 && "GotPowerupX not implemented.");
        abort();
    } else {
        return original_GotPowerupX(pCar, pIndex, pTell_net_players, pDisplay_headup, pTime_left);
    }
}

function_hook_state_t function_hook_state_GotPowerup = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_GotPowerup)
static int(__cdecl*original_GotPowerup)(tCar_spec *, int) = (int(__cdecl*)(tCar_spec *, int))0x0042d121;
CARM95_HOOK_FUNCTION(original_GotPowerup, GotPowerup)
int __cdecl GotPowerup(tCar_spec *pCar, int pIndex) {
    LOG_TRACE("(%p, %d)", pCar, pIndex);

    (void)pCar;
    (void)pIndex;

    if (function_hook_state_GotPowerup == HOOK_ENABLED) {
        assert(0 && "GotPowerup not implemented.");
        abort();
    } else {
        return original_GotPowerup(pCar, pIndex);
    }
}

function_hook_state_t function_hook_state_LoadPowerups = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_LoadPowerups)
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
        assert(0 && "LoadPowerups not implemented.");
        abort();
    } else {
        original_LoadPowerups();
    }
}

function_hook_state_t function_hook_state_InitPowerups = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_InitPowerups)
static void(__cdecl*original_InitPowerups)() = (void(__cdecl*)())0x0042d536;
CARM95_HOOK_FUNCTION(original_InitPowerups, InitPowerups)
void __cdecl InitPowerups() {
    int i;
    tPowerup *the_powerup;
    LOG_TRACE("()");

    (void)i;
    (void)the_powerup;

    if (function_hook_state_InitPowerups == HOOK_ENABLED) {
        assert(0 && "InitPowerups not implemented.");
        abort();
    } else {
        original_InitPowerups();
    }
}

function_hook_state_t function_hook_state_CloseDownPowerUps = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_CloseDownPowerUps)
static void(__cdecl*original_CloseDownPowerUps)() = (void(__cdecl*)())0x0042d594;
CARM95_HOOK_FUNCTION(original_CloseDownPowerUps, CloseDownPowerUps)
void __cdecl CloseDownPowerUps() {
    int i;
    tPowerup *the_powerup;
    LOG_TRACE("()");

    (void)i;
    (void)the_powerup;

    if (function_hook_state_CloseDownPowerUps == HOOK_ENABLED) {
        assert(0 && "CloseDownPowerUps not implemented.");
        abort();
    } else {
        original_CloseDownPowerUps();
    }
}

function_hook_state_t function_hook_state_DrawPowerups = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_DrawPowerups)
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
        assert(0 && "DrawPowerups not implemented.");
        abort();
    } else {
        original_DrawPowerups(pTime);
    }
}

function_hook_state_t function_hook_state_DoPowerupPeriodics = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_DoPowerupPeriodics)
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
        assert(0 && "DoPowerupPeriodics not implemented.");
        abort();
    } else {
        original_DoPowerupPeriodics(pFrame_period);
    }
}

function_hook_state_t function_hook_state_GotPowerupN = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_GotPowerupN)
static void(__cdecl*original_GotPowerupN)(int) = (void(__cdecl*)(int))0x0042d965;
CARM95_HOOK_FUNCTION(original_GotPowerupN, GotPowerupN)
void __cdecl GotPowerupN(int pN) {
    int modifiers;
    LOG_TRACE("(%d)", pN);

    (void)pN;
    (void)modifiers;

    if (function_hook_state_GotPowerupN == HOOK_ENABLED) {
        assert(0 && "GotPowerupN not implemented.");
        abort();
    } else {
        original_GotPowerupN(pN);
    }
}

function_hook_state_t function_hook_state_GotPowerup0 = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_GotPowerup0)
static void(__cdecl*original_GotPowerup0)() = (void(__cdecl*)())0x0042d9e8;
CARM95_HOOK_FUNCTION(original_GotPowerup0, GotPowerup0)
void __cdecl GotPowerup0() {
    LOG_TRACE("()");


    if (function_hook_state_GotPowerup0 == HOOK_ENABLED) {
        assert(0 && "GotPowerup0 not implemented.");
        abort();
    } else {
        original_GotPowerup0();
    }
}

function_hook_state_t function_hook_state_GotPowerup1 = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_GotPowerup1)
static void(__cdecl*original_GotPowerup1)() = (void(__cdecl*)())0x0042d9fd;
CARM95_HOOK_FUNCTION(original_GotPowerup1, GotPowerup1)
void __cdecl GotPowerup1() {
    LOG_TRACE("()");


    if (function_hook_state_GotPowerup1 == HOOK_ENABLED) {
        assert(0 && "GotPowerup1 not implemented.");
        abort();
    } else {
        original_GotPowerup1();
    }
}

function_hook_state_t function_hook_state_GotPowerup2 = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_GotPowerup2)
static void(__cdecl*original_GotPowerup2)() = (void(__cdecl*)())0x0042da12;
CARM95_HOOK_FUNCTION(original_GotPowerup2, GotPowerup2)
void __cdecl GotPowerup2() {
    LOG_TRACE("()");


    if (function_hook_state_GotPowerup2 == HOOK_ENABLED) {
        assert(0 && "GotPowerup2 not implemented.");
        abort();
    } else {
        original_GotPowerup2();
    }
}

function_hook_state_t function_hook_state_GotPowerup3 = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_GotPowerup3)
static void(__cdecl*original_GotPowerup3)() = (void(__cdecl*)())0x0042da27;
CARM95_HOOK_FUNCTION(original_GotPowerup3, GotPowerup3)
void __cdecl GotPowerup3() {
    LOG_TRACE("()");


    if (function_hook_state_GotPowerup3 == HOOK_ENABLED) {
        assert(0 && "GotPowerup3 not implemented.");
        abort();
    } else {
        original_GotPowerup3();
    }
}

function_hook_state_t function_hook_state_GotPowerup4 = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_GotPowerup4)
static void(__cdecl*original_GotPowerup4)() = (void(__cdecl*)())0x0042da3c;
CARM95_HOOK_FUNCTION(original_GotPowerup4, GotPowerup4)
void __cdecl GotPowerup4() {
    LOG_TRACE("()");


    if (function_hook_state_GotPowerup4 == HOOK_ENABLED) {
        assert(0 && "GotPowerup4 not implemented.");
        abort();
    } else {
        original_GotPowerup4();
    }
}

function_hook_state_t function_hook_state_GotPowerup5 = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_GotPowerup5)
static void(__cdecl*original_GotPowerup5)() = (void(__cdecl*)())0x0042da51;
CARM95_HOOK_FUNCTION(original_GotPowerup5, GotPowerup5)
void __cdecl GotPowerup5() {
    LOG_TRACE("()");


    if (function_hook_state_GotPowerup5 == HOOK_ENABLED) {
        assert(0 && "GotPowerup5 not implemented.");
        abort();
    } else {
        original_GotPowerup5();
    }
}

function_hook_state_t function_hook_state_GotPowerup6 = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_GotPowerup6)
static void(__cdecl*original_GotPowerup6)() = (void(__cdecl*)())0x0042da66;
CARM95_HOOK_FUNCTION(original_GotPowerup6, GotPowerup6)
void __cdecl GotPowerup6() {
    LOG_TRACE("()");


    if (function_hook_state_GotPowerup6 == HOOK_ENABLED) {
        assert(0 && "GotPowerup6 not implemented.");
        abort();
    } else {
        original_GotPowerup6();
    }
}

function_hook_state_t function_hook_state_GotPowerup7 = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_GotPowerup7)
static void(__cdecl*original_GotPowerup7)() = (void(__cdecl*)())0x0042da7b;
CARM95_HOOK_FUNCTION(original_GotPowerup7, GotPowerup7)
void __cdecl GotPowerup7() {
    LOG_TRACE("()");


    if (function_hook_state_GotPowerup7 == HOOK_ENABLED) {
        assert(0 && "GotPowerup7 not implemented.");
        abort();
    } else {
        original_GotPowerup7();
    }
}

function_hook_state_t function_hook_state_GotPowerup8 = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_GotPowerup8)
static void(__cdecl*original_GotPowerup8)() = (void(__cdecl*)())0x0042da90;
CARM95_HOOK_FUNCTION(original_GotPowerup8, GotPowerup8)
void __cdecl GotPowerup8() {
    LOG_TRACE("()");


    if (function_hook_state_GotPowerup8 == HOOK_ENABLED) {
        assert(0 && "GotPowerup8 not implemented.");
        abort();
    } else {
        original_GotPowerup8();
    }
}

function_hook_state_t function_hook_state_GotPowerup9 = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_GotPowerup9)
static void(__cdecl*original_GotPowerup9)() = (void(__cdecl*)())0x0042daa5;
CARM95_HOOK_FUNCTION(original_GotPowerup9, GotPowerup9)
void __cdecl GotPowerup9() {
    LOG_TRACE("()");


    if (function_hook_state_GotPowerup9 == HOOK_ENABLED) {
        assert(0 && "GotPowerup9 not implemented.");
        abort();
    } else {
        original_GotPowerup9();
    }
}

function_hook_state_t function_hook_state_GotCredits = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_GotCredits)
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
        assert(0 && "GotCredits not implemented.");
        abort();
    } else {
        return original_GotCredits(pPowerup, pCar);
    }
}

function_hook_state_t function_hook_state_ImprovePSPowerup = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_ImprovePSPowerup)
static void(__cdecl*original_ImprovePSPowerup)(tCar_spec *, int) = (void(__cdecl*)(tCar_spec *, int))0x0042db7a;
CARM95_HOOK_FUNCTION(original_ImprovePSPowerup, ImprovePSPowerup)
void __cdecl ImprovePSPowerup(tCar_spec *pCar, int pIndex) {
    tNet_message *the_message;
    LOG_TRACE("(%p, %d)", pCar, pIndex);

    (void)pCar;
    (void)pIndex;
    (void)the_message;

    if (function_hook_state_ImprovePSPowerup == HOOK_ENABLED) {
        assert(0 && "ImprovePSPowerup not implemented.");
        abort();
    } else {
        original_ImprovePSPowerup(pCar, pIndex);
    }
}

function_hook_state_t function_hook_state_GotTimeOrPower = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_GotTimeOrPower)
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
        assert(0 && "GotTimeOrPower not implemented.");
        abort();
    } else {
        return original_GotTimeOrPower(pPowerup, pCar);
    }
}

function_hook_state_t function_hook_state_SetPedSpeed = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_SetPedSpeed)
static int(__cdecl*original_SetPedSpeed)(tPowerup *, tCar_spec *) = (int(__cdecl*)(tPowerup *, tCar_spec *))0x0042dd8b;
CARM95_HOOK_FUNCTION(original_SetPedSpeed, SetPedSpeed)
int __cdecl SetPedSpeed(tPowerup *pPowerup, tCar_spec *pCar) {
    LOG_TRACE("(%p, %p)", pPowerup, pCar);

    (void)pPowerup;
    (void)pCar;

    if (function_hook_state_SetPedSpeed == HOOK_ENABLED) {
        assert(0 && "SetPedSpeed not implemented.");
        abort();
    } else {
        return original_SetPedSpeed(pPowerup, pCar);
    }
}

function_hook_state_t function_hook_state_SetHades = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_SetHades)
static int(__cdecl*original_SetHades)(tPowerup *, tCar_spec *) = (int(__cdecl*)(tPowerup *, tCar_spec *))0x0042ddb9;
CARM95_HOOK_FUNCTION(original_SetHades, SetHades)
int __cdecl SetHades(tPowerup *pPowerup, tCar_spec *pCar) {
    LOG_TRACE("(%p, %p)", pPowerup, pCar);

    (void)pPowerup;
    (void)pCar;

    if (function_hook_state_SetHades == HOOK_ENABLED) {
        assert(0 && "SetHades not implemented.");
        abort();
    } else {
        return original_SetHades(pPowerup, pCar);
    }
}

function_hook_state_t function_hook_state_ResetHades = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_ResetHades)
static void(__cdecl*original_ResetHades)(tPowerup *, tCar_spec *) = (void(__cdecl*)(tPowerup *, tCar_spec *))0x0042dddf;
CARM95_HOOK_FUNCTION(original_ResetHades, ResetHades)
void __cdecl ResetHades(tPowerup *pPowerup, tCar_spec *pCar) {
    LOG_TRACE("(%p, %p)", pPowerup, pCar);

    (void)pPowerup;
    (void)pCar;

    if (function_hook_state_ResetHades == HOOK_ENABLED) {
        assert(0 && "ResetHades not implemented.");
        abort();
    } else {
        original_ResetHades(pPowerup, pCar);
    }
}

function_hook_state_t function_hook_state_SetPedSize = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_SetPedSize)
static int(__cdecl*original_SetPedSize)(tPowerup *, tCar_spec *) = (int(__cdecl*)(tPowerup *, tCar_spec *))0x0042ddef;
CARM95_HOOK_FUNCTION(original_SetPedSize, SetPedSize)
int __cdecl SetPedSize(tPowerup *pPowerup, tCar_spec *pCar) {
    br_scalar old_scale;
    LOG_TRACE("(%p, %p)", pPowerup, pCar);

    (void)pPowerup;
    (void)pCar;
    (void)old_scale;

    if (function_hook_state_SetPedSize == HOOK_ENABLED) {
        assert(0 && "SetPedSize not implemented.");
        abort();
    } else {
        return original_SetPedSize(pPowerup, pCar);
    }
}

function_hook_state_t function_hook_state_SetPedExplode = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_SetPedExplode)
static int(__cdecl*original_SetPedExplode)(tPowerup *, tCar_spec *) = (int(__cdecl*)(tPowerup *, tCar_spec *))0x0042dec4;
CARM95_HOOK_FUNCTION(original_SetPedExplode, SetPedExplode)
int __cdecl SetPedExplode(tPowerup *pPowerup, tCar_spec *pCar) {
    LOG_TRACE("(%p, %p)", pPowerup, pCar);

    (void)pPowerup;
    (void)pCar;

    if (function_hook_state_SetPedExplode == HOOK_ENABLED) {
        assert(0 && "SetPedExplode not implemented.");
        abort();
    } else {
        return original_SetPedExplode(pPowerup, pCar);
    }
}

function_hook_state_t function_hook_state_SetInvulnerability = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_SetInvulnerability)
static int(__cdecl*original_SetInvulnerability)(tPowerup *, tCar_spec *) = (int(__cdecl*)(tPowerup *, tCar_spec *))0x0042deef;
CARM95_HOOK_FUNCTION(original_SetInvulnerability, SetInvulnerability)
int __cdecl SetInvulnerability(tPowerup *pPowerup, tCar_spec *pCar) {
    LOG_TRACE("(%p, %p)", pPowerup, pCar);

    (void)pPowerup;
    (void)pCar;

    if (function_hook_state_SetInvulnerability == HOOK_ENABLED) {
        assert(0 && "SetInvulnerability not implemented.");
        abort();
    } else {
        return original_SetInvulnerability(pPowerup, pCar);
    }
}

function_hook_state_t function_hook_state_ResetInvulnerability = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_ResetInvulnerability)
static void(__cdecl*original_ResetInvulnerability)(tPowerup *, tCar_spec *) = (void(__cdecl*)(tPowerup *, tCar_spec *))0x0042df1d;
CARM95_HOOK_FUNCTION(original_ResetInvulnerability, ResetInvulnerability)
void __cdecl ResetInvulnerability(tPowerup *pPowerup, tCar_spec *pCar) {
    LOG_TRACE("(%p, %p)", pPowerup, pCar);

    (void)pPowerup;
    (void)pCar;

    if (function_hook_state_ResetInvulnerability == HOOK_ENABLED) {
        assert(0 && "ResetInvulnerability not implemented.");
        abort();
    } else {
        original_ResetInvulnerability(pPowerup, pCar);
    }
}

function_hook_state_t function_hook_state_SetFreeRepairs = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_SetFreeRepairs)
static int(__cdecl*original_SetFreeRepairs)(tPowerup *, tCar_spec *) = (int(__cdecl*)(tPowerup *, tCar_spec *))0x0042df35;
CARM95_HOOK_FUNCTION(original_SetFreeRepairs, SetFreeRepairs)
int __cdecl SetFreeRepairs(tPowerup *pPowerup, tCar_spec *pCar) {
    LOG_TRACE("(%p, %p)", pPowerup, pCar);

    (void)pPowerup;
    (void)pCar;

    if (function_hook_state_SetFreeRepairs == HOOK_ENABLED) {
        assert(0 && "SetFreeRepairs not implemented.");
        abort();
    } else {
        return original_SetFreeRepairs(pPowerup, pCar);
    }
}

function_hook_state_t function_hook_state_ResetFreeRepairs = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_ResetFreeRepairs)
static void(__cdecl*original_ResetFreeRepairs)(tPowerup *, tCar_spec *) = (void(__cdecl*)(tPowerup *, tCar_spec *))0x0042df6d;
CARM95_HOOK_FUNCTION(original_ResetFreeRepairs, ResetFreeRepairs)
void __cdecl ResetFreeRepairs(tPowerup *pPowerup, tCar_spec *pCar) {
    LOG_TRACE("(%p, %p)", pPowerup, pCar);

    (void)pPowerup;
    (void)pCar;

    if (function_hook_state_ResetFreeRepairs == HOOK_ENABLED) {
        assert(0 && "ResetFreeRepairs not implemented.");
        abort();
    } else {
        original_ResetFreeRepairs(pPowerup, pCar);
    }
}

function_hook_state_t function_hook_state_SetBlindPedestrians = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_SetBlindPedestrians)
static int(__cdecl*original_SetBlindPedestrians)(tPowerup *, tCar_spec *) = (int(__cdecl*)(tPowerup *, tCar_spec *))0x0042df8f;
CARM95_HOOK_FUNCTION(original_SetBlindPedestrians, SetBlindPedestrians)
int __cdecl SetBlindPedestrians(tPowerup *pPowerup, tCar_spec *pCar) {
    LOG_TRACE("(%p, %p)", pPowerup, pCar);

    (void)pPowerup;
    (void)pCar;

    if (function_hook_state_SetBlindPedestrians == HOOK_ENABLED) {
        assert(0 && "SetBlindPedestrians not implemented.");
        abort();
    } else {
        return original_SetBlindPedestrians(pPowerup, pCar);
    }
}

function_hook_state_t function_hook_state_ResetBlindPedestrians = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_ResetBlindPedestrians)
static void(__cdecl*original_ResetBlindPedestrians)(tPowerup *, tCar_spec *) = (void(__cdecl*)(tPowerup *, tCar_spec *))0x0042dfba;
CARM95_HOOK_FUNCTION(original_ResetBlindPedestrians, ResetBlindPedestrians)
void __cdecl ResetBlindPedestrians(tPowerup *pPowerup, tCar_spec *pCar) {
    LOG_TRACE("(%p, %p)", pPowerup, pCar);

    (void)pPowerup;
    (void)pCar;

    if (function_hook_state_ResetBlindPedestrians == HOOK_ENABLED) {
        assert(0 && "ResetBlindPedestrians not implemented.");
        abort();
    } else {
        original_ResetBlindPedestrians(pPowerup, pCar);
    }
}

function_hook_state_t function_hook_state_FreezeTimer = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_FreezeTimer)
static int(__cdecl*original_FreezeTimer)(tPowerup *, tCar_spec *) = (int(__cdecl*)(tPowerup *, tCar_spec *))0x0042dfcf;
CARM95_HOOK_FUNCTION(original_FreezeTimer, FreezeTimer)
int __cdecl FreezeTimer(tPowerup *pPowerup, tCar_spec *pCar) {
    LOG_TRACE("(%p, %p)", pPowerup, pCar);

    (void)pPowerup;
    (void)pCar;

    if (function_hook_state_FreezeTimer == HOOK_ENABLED) {
        assert(0 && "FreezeTimer not implemented.");
        abort();
    } else {
        return original_FreezeTimer(pPowerup, pCar);
    }
}

function_hook_state_t function_hook_state_UnfreezeTimer = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_UnfreezeTimer)
static void(__cdecl*original_UnfreezeTimer)(tPowerup *, tCar_spec *) = (void(__cdecl*)(tPowerup *, tCar_spec *))0x0042e023;
CARM95_HOOK_FUNCTION(original_UnfreezeTimer, UnfreezeTimer)
void __cdecl UnfreezeTimer(tPowerup *pPowerup, tCar_spec *pCar) {
    LOG_TRACE("(%p, %p)", pPowerup, pCar);

    (void)pPowerup;
    (void)pCar;

    if (function_hook_state_UnfreezeTimer == HOOK_ENABLED) {
        assert(0 && "UnfreezeTimer not implemented.");
        abort();
    } else {
        original_UnfreezeTimer(pPowerup, pCar);
    }
}

function_hook_state_t function_hook_state_DoInstantRepair = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_DoInstantRepair)
static int(__cdecl*original_DoInstantRepair)(tPowerup *, tCar_spec *) = (int(__cdecl*)(tPowerup *, tCar_spec *))0x0042e045;
CARM95_HOOK_FUNCTION(original_DoInstantRepair, DoInstantRepair)
int __cdecl DoInstantRepair(tPowerup *pPowerup, tCar_spec *pCar) {
    LOG_TRACE("(%p, %p)", pPowerup, pCar);

    (void)pPowerup;
    (void)pCar;

    if (function_hook_state_DoInstantRepair == HOOK_ENABLED) {
        assert(0 && "DoInstantRepair not implemented.");
        abort();
    } else {
        return original_DoInstantRepair(pPowerup, pCar);
    }
}

function_hook_state_t function_hook_state_ResetPedSpeed = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_ResetPedSpeed)
static void(__cdecl*original_ResetPedSpeed)(tPowerup *, tCar_spec *) = (void(__cdecl*)(tPowerup *, tCar_spec *))0x0042e078;
CARM95_HOOK_FUNCTION(original_ResetPedSpeed, ResetPedSpeed)
void __cdecl ResetPedSpeed(tPowerup *pPowerup, tCar_spec *pCar) {
    LOG_TRACE("(%p, %p)", pPowerup, pCar);

    (void)pPowerup;
    (void)pCar;

    if (function_hook_state_ResetPedSpeed == HOOK_ENABLED) {
        assert(0 && "ResetPedSpeed not implemented.");
        abort();
    } else {
        original_ResetPedSpeed(pPowerup, pCar);
    }
}

function_hook_state_t function_hook_state_ResetPedSize = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_ResetPedSize)
static void(__cdecl*original_ResetPedSize)(tPowerup *, tCar_spec *) = (void(__cdecl*)(tPowerup *, tCar_spec *))0x0042e08d;
CARM95_HOOK_FUNCTION(original_ResetPedSize, ResetPedSize)
void __cdecl ResetPedSize(tPowerup *pPowerup, tCar_spec *pCar) {
    LOG_TRACE("(%p, %p)", pPowerup, pCar);

    (void)pPowerup;
    (void)pCar;

    if (function_hook_state_ResetPedSize == HOOK_ENABLED) {
        assert(0 && "ResetPedSize not implemented.");
        abort();
    } else {
        original_ResetPedSize(pPowerup, pCar);
    }
}

function_hook_state_t function_hook_state_ResetPedExplode = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_ResetPedExplode)
static void(__cdecl*original_ResetPedExplode)(tPowerup *, tCar_spec *) = (void(__cdecl*)(tPowerup *, tCar_spec *))0x0042e0ac;
CARM95_HOOK_FUNCTION(original_ResetPedExplode, ResetPedExplode)
void __cdecl ResetPedExplode(tPowerup *pPowerup, tCar_spec *pCar) {
    LOG_TRACE("(%p, %p)", pPowerup, pCar);

    (void)pPowerup;
    (void)pCar;

    if (function_hook_state_ResetPedExplode == HOOK_ENABLED) {
        assert(0 && "ResetPedExplode not implemented.");
        abort();
    } else {
        original_ResetPedExplode(pPowerup, pCar);
    }
}

function_hook_state_t function_hook_state_SetEngineFactor = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_SetEngineFactor)
static int(__cdecl*original_SetEngineFactor)(tPowerup *, tCar_spec *) = (int(__cdecl*)(tPowerup *, tCar_spec *))0x0042e0c1;
CARM95_HOOK_FUNCTION(original_SetEngineFactor, SetEngineFactor)
int __cdecl SetEngineFactor(tPowerup *pPowerup, tCar_spec *pCar) {
    LOG_TRACE("(%p, %p)", pPowerup, pCar);

    (void)pPowerup;
    (void)pCar;

    if (function_hook_state_SetEngineFactor == HOOK_ENABLED) {
        assert(0 && "SetEngineFactor not implemented.");
        abort();
    } else {
        return original_SetEngineFactor(pPowerup, pCar);
    }
}

function_hook_state_t function_hook_state_SetUnderwater = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_SetUnderwater)
static int(__cdecl*original_SetUnderwater)(tPowerup *, tCar_spec *) = (int(__cdecl*)(tPowerup *, tCar_spec *))0x0042e143;
CARM95_HOOK_FUNCTION(original_SetUnderwater, SetUnderwater)
int __cdecl SetUnderwater(tPowerup *pPowerup, tCar_spec *pCar) {
    LOG_TRACE("(%p, %p)", pPowerup, pCar);

    (void)pPowerup;
    (void)pCar;

    if (function_hook_state_SetUnderwater == HOOK_ENABLED) {
        assert(0 && "SetUnderwater not implemented.");
        abort();
    } else {
        return original_SetUnderwater(pPowerup, pCar);
    }
}

function_hook_state_t function_hook_state_TrashBodywork = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_TrashBodywork)
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
        assert(0 && "TrashBodywork not implemented.");
        abort();
    } else {
        return original_TrashBodywork(pPowerup, pCar);
    }
}

function_hook_state_t function_hook_state_TakeDrugs = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_TakeDrugs)
static int(__cdecl*original_TakeDrugs)(tPowerup *, tCar_spec *) = (int(__cdecl*)(tPowerup *, tCar_spec *))0x0042e26c;
CARM95_HOOK_FUNCTION(original_TakeDrugs, TakeDrugs)
int __cdecl TakeDrugs(tPowerup *pPowerup, tCar_spec *pCar) {
    LOG_TRACE("(%p, %p)", pPowerup, pCar);

    (void)pPowerup;
    (void)pCar;

    if (function_hook_state_TakeDrugs == HOOK_ENABLED) {
        assert(0 && "TakeDrugs not implemented.");
        abort();
    } else {
        return original_TakeDrugs(pPowerup, pCar);
    }
}

function_hook_state_t function_hook_state_PaletteFuckedUpByDrugs = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_PaletteFuckedUpByDrugs)
static void(__cdecl*original_PaletteFuckedUpByDrugs)(br_pixelmap *, int) = (void(__cdecl*)(br_pixelmap *, int))0x0042e30a;
CARM95_HOOK_FUNCTION(original_PaletteFuckedUpByDrugs, PaletteFuckedUpByDrugs)
void __cdecl PaletteFuckedUpByDrugs(br_pixelmap *pPixelmap, int pOffset) {
    int i;
    LOG_TRACE("(%p, %d)", pPixelmap, pOffset);

    (void)pPixelmap;
    (void)pOffset;
    (void)i;

    if (function_hook_state_PaletteFuckedUpByDrugs == HOOK_ENABLED) {
        assert(0 && "PaletteFuckedUpByDrugs not implemented.");
        abort();
    } else {
        original_PaletteFuckedUpByDrugs(pPixelmap, pOffset);
    }
}

function_hook_state_t function_hook_state_TheEffectsOfDrugs = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_TheEffectsOfDrugs)
static void(__cdecl*original_TheEffectsOfDrugs)(tPowerup *, tU32) = (void(__cdecl*)(tPowerup *, tU32))0x0042e2dd;
CARM95_HOOK_FUNCTION(original_TheEffectsOfDrugs, TheEffectsOfDrugs)
void __cdecl TheEffectsOfDrugs(tPowerup *pPowerup, tU32 pPeriod) {
    LOG_TRACE("(%p, %u)", pPowerup, pPeriod);

    (void)pPowerup;
    (void)pPeriod;

    if (function_hook_state_TheEffectsOfDrugs == HOOK_ENABLED) {
        assert(0 && "TheEffectsOfDrugs not implemented.");
        abort();
    } else {
        original_TheEffectsOfDrugs(pPowerup, pPeriod);
    }
}

function_hook_state_t function_hook_state_SetOpponentsSpeed = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_SetOpponentsSpeed)
static int(__cdecl*original_SetOpponentsSpeed)(tPowerup *, tCar_spec *) = (int(__cdecl*)(tPowerup *, tCar_spec *))0x0042e3af;
CARM95_HOOK_FUNCTION(original_SetOpponentsSpeed, SetOpponentsSpeed)
int __cdecl SetOpponentsSpeed(tPowerup *pPowerup, tCar_spec *pCar) {
    int i;
    LOG_TRACE("(%p, %p)", pPowerup, pCar);

    (void)pPowerup;
    (void)pCar;
    (void)i;

    if (function_hook_state_SetOpponentsSpeed == HOOK_ENABLED) {
        assert(0 && "SetOpponentsSpeed not implemented.");
        abort();
    } else {
        return original_SetOpponentsSpeed(pPowerup, pCar);
    }
}

function_hook_state_t function_hook_state_SetCopsSpeed = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_SetCopsSpeed)
static int(__cdecl*original_SetCopsSpeed)(tPowerup *, tCar_spec *) = (int(__cdecl*)(tPowerup *, tCar_spec *))0x0042e445;
CARM95_HOOK_FUNCTION(original_SetCopsSpeed, SetCopsSpeed)
int __cdecl SetCopsSpeed(tPowerup *pPowerup, tCar_spec *pCar) {
    LOG_TRACE("(%p, %p)", pPowerup, pCar);

    (void)pPowerup;
    (void)pCar;

    if (function_hook_state_SetCopsSpeed == HOOK_ENABLED) {
        assert(0 && "SetCopsSpeed not implemented.");
        abort();
    } else {
        return original_SetCopsSpeed(pPowerup, pCar);
    }
}

function_hook_state_t function_hook_state_SetGravity = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_SetGravity)
static int(__cdecl*original_SetGravity)(tPowerup *, tCar_spec *) = (int(__cdecl*)(tPowerup *, tCar_spec *))0x0042e473;
CARM95_HOOK_FUNCTION(original_SetGravity, SetGravity)
int __cdecl SetGravity(tPowerup *pPowerup, tCar_spec *pCar) {
    LOG_TRACE("(%p, %p)", pPowerup, pCar);

    (void)pPowerup;
    (void)pCar;

    if (function_hook_state_SetGravity == HOOK_ENABLED) {
        assert(0 && "SetGravity not implemented.");
        abort();
    } else {
        return original_SetGravity(pPowerup, pCar);
    }
}

function_hook_state_t function_hook_state_SetPinball = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_SetPinball)
static int(__cdecl*original_SetPinball)(tPowerup *, tCar_spec *) = (int(__cdecl*)(tPowerup *, tCar_spec *))0x0042e4a1;
CARM95_HOOK_FUNCTION(original_SetPinball, SetPinball)
int __cdecl SetPinball(tPowerup *pPowerup, tCar_spec *pCar) {
    LOG_TRACE("(%p, %p)", pPowerup, pCar);

    (void)pPowerup;
    (void)pCar;

    if (function_hook_state_SetPinball == HOOK_ENABLED) {
        assert(0 && "SetPinball not implemented.");
        abort();
    } else {
        return original_SetPinball(pPowerup, pCar);
    }
}

function_hook_state_t function_hook_state_SetWallclimb = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_SetWallclimb)
static int(__cdecl*original_SetWallclimb)(tPowerup *, tCar_spec *) = (int(__cdecl*)(tPowerup *, tCar_spec *))0x0042e4cf;
CARM95_HOOK_FUNCTION(original_SetWallclimb, SetWallclimb)
int __cdecl SetWallclimb(tPowerup *pPowerup, tCar_spec *pCar) {
    LOG_TRACE("(%p, %p)", pPowerup, pCar);

    (void)pPowerup;
    (void)pCar;

    if (function_hook_state_SetWallclimb == HOOK_ENABLED) {
        assert(0 && "SetWallclimb not implemented.");
        abort();
    } else {
        return original_SetWallclimb(pPowerup, pCar);
    }
}

function_hook_state_t function_hook_state_SetBouncey = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_SetBouncey)
static int(__cdecl*original_SetBouncey)(tPowerup *, tCar_spec *) = (int(__cdecl*)(tPowerup *, tCar_spec *))0x0042e4fd;
CARM95_HOOK_FUNCTION(original_SetBouncey, SetBouncey)
int __cdecl SetBouncey(tPowerup *pPowerup, tCar_spec *pCar) {
    LOG_TRACE("(%p, %p)", pPowerup, pCar);

    (void)pPowerup;
    (void)pCar;

    if (function_hook_state_SetBouncey == HOOK_ENABLED) {
        assert(0 && "SetBouncey not implemented.");
        abort();
    } else {
        return original_SetBouncey(pPowerup, pCar);
    }
}

function_hook_state_t function_hook_state_SetSuspension = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_SetSuspension)
static int(__cdecl*original_SetSuspension)(tPowerup *, tCar_spec *) = (int(__cdecl*)(tPowerup *, tCar_spec *))0x0042e554;
CARM95_HOOK_FUNCTION(original_SetSuspension, SetSuspension)
int __cdecl SetSuspension(tPowerup *pPowerup, tCar_spec *pCar) {
    LOG_TRACE("(%p, %p)", pPowerup, pCar);

    (void)pPowerup;
    (void)pCar;

    if (function_hook_state_SetSuspension == HOOK_ENABLED) {
        assert(0 && "SetSuspension not implemented.");
        abort();
    } else {
        return original_SetSuspension(pPowerup, pCar);
    }
}

function_hook_state_t function_hook_state_SetTyreGrip = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_SetTyreGrip)
static int(__cdecl*original_SetTyreGrip)(tPowerup *, tCar_spec *) = (int(__cdecl*)(tPowerup *, tCar_spec *))0x0042e5b2;
CARM95_HOOK_FUNCTION(original_SetTyreGrip, SetTyreGrip)
int __cdecl SetTyreGrip(tPowerup *pPowerup, tCar_spec *pCar) {
    LOG_TRACE("(%p, %p)", pPowerup, pCar);

    (void)pPowerup;
    (void)pCar;

    if (function_hook_state_SetTyreGrip == HOOK_ENABLED) {
        assert(0 && "SetTyreGrip not implemented.");
        abort();
    } else {
        return original_SetTyreGrip(pPowerup, pCar);
    }
}

function_hook_state_t function_hook_state_SetDamageMultiplier = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_SetDamageMultiplier)
static int(__cdecl*original_SetDamageMultiplier)(tPowerup *, tCar_spec *) = (int(__cdecl*)(tPowerup *, tCar_spec *))0x0042e5e4;
CARM95_HOOK_FUNCTION(original_SetDamageMultiplier, SetDamageMultiplier)
int __cdecl SetDamageMultiplier(tPowerup *pPowerup, tCar_spec *pCar) {
    LOG_TRACE("(%p, %p)", pPowerup, pCar);

    (void)pPowerup;
    (void)pCar;

    if (function_hook_state_SetDamageMultiplier == HOOK_ENABLED) {
        assert(0 && "SetDamageMultiplier not implemented.");
        abort();
    } else {
        return original_SetDamageMultiplier(pPowerup, pCar);
    }
}

function_hook_state_t function_hook_state_ResetEngineFactor = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_ResetEngineFactor)
static void(__cdecl*original_ResetEngineFactor)(tPowerup *, tCar_spec *) = (void(__cdecl*)(tPowerup *, tCar_spec *))0x0042e616;
CARM95_HOOK_FUNCTION(original_ResetEngineFactor, ResetEngineFactor)
void __cdecl ResetEngineFactor(tPowerup *pPowerup, tCar_spec *pCar) {
    LOG_TRACE("(%p, %p)", pPowerup, pCar);

    (void)pPowerup;
    (void)pCar;

    if (function_hook_state_ResetEngineFactor == HOOK_ENABLED) {
        assert(0 && "ResetEngineFactor not implemented.");
        abort();
    } else {
        original_ResetEngineFactor(pPowerup, pCar);
    }
}

function_hook_state_t function_hook_state_ResetUnderwater = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_ResetUnderwater)
static void(__cdecl*original_ResetUnderwater)(tPowerup *, tCar_spec *) = (void(__cdecl*)(tPowerup *, tCar_spec *))0x0042e65a;
CARM95_HOOK_FUNCTION(original_ResetUnderwater, ResetUnderwater)
void __cdecl ResetUnderwater(tPowerup *pPowerup, tCar_spec *pCar) {
    LOG_TRACE("(%p, %p)", pPowerup, pCar);

    (void)pPowerup;
    (void)pCar;

    if (function_hook_state_ResetUnderwater == HOOK_ENABLED) {
        assert(0 && "ResetUnderwater not implemented.");
        abort();
    } else {
        original_ResetUnderwater(pPowerup, pCar);
    }
}

function_hook_state_t function_hook_state_PukeDrugsBackUp = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_PukeDrugsBackUp)
static void(__cdecl*original_PukeDrugsBackUp)(tPowerup *, tCar_spec *) = (void(__cdecl*)(tPowerup *, tCar_spec *))0x0042e672;
CARM95_HOOK_FUNCTION(original_PukeDrugsBackUp, PukeDrugsBackUp)
void __cdecl PukeDrugsBackUp(tPowerup *pPowerup, tCar_spec *pCar) {
    LOG_TRACE("(%p, %p)", pPowerup, pCar);

    (void)pPowerup;
    (void)pCar;

    if (function_hook_state_PukeDrugsBackUp == HOOK_ENABLED) {
        assert(0 && "PukeDrugsBackUp not implemented.");
        abort();
    } else {
        original_PukeDrugsBackUp(pPowerup, pCar);
    }
}

function_hook_state_t function_hook_state_ResetOpponentsSpeed = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_ResetOpponentsSpeed)
static void(__cdecl*original_ResetOpponentsSpeed)(tPowerup *, tCar_spec *) = (void(__cdecl*)(tPowerup *, tCar_spec *))0x0042e6a9;
CARM95_HOOK_FUNCTION(original_ResetOpponentsSpeed, ResetOpponentsSpeed)
void __cdecl ResetOpponentsSpeed(tPowerup *pPowerup, tCar_spec *pCar) {
    int i;
    LOG_TRACE("(%p, %p)", pPowerup, pCar);

    (void)pPowerup;
    (void)pCar;
    (void)i;

    if (function_hook_state_ResetOpponentsSpeed == HOOK_ENABLED) {
        assert(0 && "ResetOpponentsSpeed not implemented.");
        abort();
    } else {
        original_ResetOpponentsSpeed(pPowerup, pCar);
    }
}

function_hook_state_t function_hook_state_ResetCopsSpeed = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_ResetCopsSpeed)
static void(__cdecl*original_ResetCopsSpeed)(tPowerup *, tCar_spec *) = (void(__cdecl*)(tPowerup *, tCar_spec *))0x0042e726;
CARM95_HOOK_FUNCTION(original_ResetCopsSpeed, ResetCopsSpeed)
void __cdecl ResetCopsSpeed(tPowerup *pPowerup, tCar_spec *pCar) {
    LOG_TRACE("(%p, %p)", pPowerup, pCar);

    (void)pPowerup;
    (void)pCar;

    if (function_hook_state_ResetCopsSpeed == HOOK_ENABLED) {
        assert(0 && "ResetCopsSpeed not implemented.");
        abort();
    } else {
        original_ResetCopsSpeed(pPowerup, pCar);
    }
}

function_hook_state_t function_hook_state_ResetGravity = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_ResetGravity)
static void(__cdecl*original_ResetGravity)(tPowerup *, tCar_spec *) = (void(__cdecl*)(tPowerup *, tCar_spec *))0x0042e73b;
CARM95_HOOK_FUNCTION(original_ResetGravity, ResetGravity)
void __cdecl ResetGravity(tPowerup *pPowerup, tCar_spec *pCar) {
    LOG_TRACE("(%p, %p)", pPowerup, pCar);

    (void)pPowerup;
    (void)pCar;

    if (function_hook_state_ResetGravity == HOOK_ENABLED) {
        assert(0 && "ResetGravity not implemented.");
        abort();
    } else {
        original_ResetGravity(pPowerup, pCar);
    }
}

function_hook_state_t function_hook_state_ResetPinball = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_ResetPinball)
static void(__cdecl*original_ResetPinball)(tPowerup *, tCar_spec *) = (void(__cdecl*)(tPowerup *, tCar_spec *))0x0042e750;
CARM95_HOOK_FUNCTION(original_ResetPinball, ResetPinball)
void __cdecl ResetPinball(tPowerup *pPowerup, tCar_spec *pCar) {
    LOG_TRACE("(%p, %p)", pPowerup, pCar);

    (void)pPowerup;
    (void)pCar;

    if (function_hook_state_ResetPinball == HOOK_ENABLED) {
        assert(0 && "ResetPinball not implemented.");
        abort();
    } else {
        original_ResetPinball(pPowerup, pCar);
    }
}

function_hook_state_t function_hook_state_ResetWallclimb = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_ResetWallclimb)
static void(__cdecl*original_ResetWallclimb)(tPowerup *, tCar_spec *) = (void(__cdecl*)(tPowerup *, tCar_spec *))0x0042e765;
CARM95_HOOK_FUNCTION(original_ResetWallclimb, ResetWallclimb)
void __cdecl ResetWallclimb(tPowerup *pPowerup, tCar_spec *pCar) {
    LOG_TRACE("(%p, %p)", pPowerup, pCar);

    (void)pPowerup;
    (void)pCar;

    if (function_hook_state_ResetWallclimb == HOOK_ENABLED) {
        assert(0 && "ResetWallclimb not implemented.");
        abort();
    } else {
        original_ResetWallclimb(pPowerup, pCar);
    }
}

function_hook_state_t function_hook_state_ResetBouncey = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_ResetBouncey)
static void(__cdecl*original_ResetBouncey)(tPowerup *, tCar_spec *) = (void(__cdecl*)(tPowerup *, tCar_spec *))0x0042e77d;
CARM95_HOOK_FUNCTION(original_ResetBouncey, ResetBouncey)
void __cdecl ResetBouncey(tPowerup *pPowerup, tCar_spec *pCar) {
    LOG_TRACE("(%p, %p)", pPowerup, pCar);

    (void)pPowerup;
    (void)pCar;

    if (function_hook_state_ResetBouncey == HOOK_ENABLED) {
        assert(0 && "ResetBouncey not implemented.");
        abort();
    } else {
        original_ResetBouncey(pPowerup, pCar);
    }
}

function_hook_state_t function_hook_state_ResetSuspension = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_ResetSuspension)
static void(__cdecl*original_ResetSuspension)(tPowerup *, tCar_spec *) = (void(__cdecl*)(tPowerup *, tCar_spec *))0x0042e7a2;
CARM95_HOOK_FUNCTION(original_ResetSuspension, ResetSuspension)
void __cdecl ResetSuspension(tPowerup *pPowerup, tCar_spec *pCar) {
    LOG_TRACE("(%p, %p)", pPowerup, pCar);

    (void)pPowerup;
    (void)pCar;

    if (function_hook_state_ResetSuspension == HOOK_ENABLED) {
        assert(0 && "ResetSuspension not implemented.");
        abort();
    } else {
        original_ResetSuspension(pPowerup, pCar);
    }
}

function_hook_state_t function_hook_state_ResetDamageMultiplier = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_ResetDamageMultiplier)
static void(__cdecl*original_ResetDamageMultiplier)(tPowerup *, tCar_spec *) = (void(__cdecl*)(tPowerup *, tCar_spec *))0x0042e7cc;
CARM95_HOOK_FUNCTION(original_ResetDamageMultiplier, ResetDamageMultiplier)
void __cdecl ResetDamageMultiplier(tPowerup *pPowerup, tCar_spec *pCar) {
    LOG_TRACE("(%p, %p)", pPowerup, pCar);

    (void)pPowerup;
    (void)pCar;

    if (function_hook_state_ResetDamageMultiplier == HOOK_ENABLED) {
        assert(0 && "ResetDamageMultiplier not implemented.");
        abort();
    } else {
        original_ResetDamageMultiplier(pPowerup, pCar);
    }
}

function_hook_state_t function_hook_state_ResetTyreGrip = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_ResetTyreGrip)
static void(__cdecl*original_ResetTyreGrip)(tPowerup *, tCar_spec *) = (void(__cdecl*)(tPowerup *, tCar_spec *))0x0042e7e4;
CARM95_HOOK_FUNCTION(original_ResetTyreGrip, ResetTyreGrip)
void __cdecl ResetTyreGrip(tPowerup *pPowerup, tCar_spec *pCar) {
    LOG_TRACE("(%p, %p)", pPowerup, pCar);

    (void)pPowerup;
    (void)pCar;

    if (function_hook_state_ResetTyreGrip == HOOK_ENABLED) {
        assert(0 && "ResetTyreGrip not implemented.");
        abort();
    } else {
        original_ResetTyreGrip(pPowerup, pCar);
    }
}

function_hook_state_t function_hook_state_PickAtRandom = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_PickAtRandom)
static int(__cdecl*original_PickAtRandom)(tPowerup *, tCar_spec *) = (int(__cdecl*)(tPowerup *, tCar_spec *))0x0042e7fc;
CARM95_HOOK_FUNCTION(original_PickAtRandom, PickAtRandom)
int __cdecl PickAtRandom(tPowerup *pPowerup, tCar_spec *pCar) {
    LOG_TRACE("(%p, %p)", pPowerup, pCar);

    (void)pPowerup;
    (void)pCar;

    if (function_hook_state_PickAtRandom == HOOK_ENABLED) {
        assert(0 && "PickAtRandom not implemented.");
        abort();
    } else {
        return original_PickAtRandom(pPowerup, pCar);
    }
}

function_hook_state_t function_hook_state_PedestrianRespawn = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_PedestrianRespawn)
static int(__cdecl*original_PedestrianRespawn)(tPowerup *, tCar_spec *) = (int(__cdecl*)(tPowerup *, tCar_spec *))0x0042e834;
CARM95_HOOK_FUNCTION(original_PedestrianRespawn, PedestrianRespawn)
int __cdecl PedestrianRespawn(tPowerup *pPowerup, tCar_spec *pCar) {
    LOG_TRACE("(%p, %p)", pPowerup, pCar);

    (void)pPowerup;
    (void)pCar;

    if (function_hook_state_PedestrianRespawn == HOOK_ENABLED) {
        assert(0 && "PedestrianRespawn not implemented.");
        abort();
    } else {
        return original_PedestrianRespawn(pPowerup, pCar);
    }
}

function_hook_state_t function_hook_state_GotVouchers = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_GotVouchers)
static int(__cdecl*original_GotVouchers)(tPowerup *, tCar_spec *) = (int(__cdecl*)(tPowerup *, tCar_spec *))0x0042e85a;
CARM95_HOOK_FUNCTION(original_GotVouchers, GotVouchers)
int __cdecl GotVouchers(tPowerup *pPowerup, tCar_spec *pCar) {
    LOG_TRACE("(%p, %p)", pPowerup, pCar);

    (void)pPowerup;
    (void)pCar;

    if (function_hook_state_GotVouchers == HOOK_ENABLED) {
        assert(0 && "GotVouchers not implemented.");
        abort();
    } else {
        return original_GotVouchers(pPowerup, pCar);
    }
}

function_hook_state_t function_hook_state_MungeVouchers = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_MungeVouchers)
static void(__cdecl*original_MungeVouchers)(tPowerup *, tU32) = (void(__cdecl*)(tPowerup *, tU32))0x0042e899;
CARM95_HOOK_FUNCTION(original_MungeVouchers, MungeVouchers)
void __cdecl MungeVouchers(tPowerup *pPowerup, tU32 pPeriod) {
    LOG_TRACE("(%p, %u)", pPowerup, pPeriod);

    (void)pPowerup;
    (void)pPeriod;

    if (function_hook_state_MungeVouchers == HOOK_ENABLED) {
        assert(0 && "MungeVouchers not implemented.");
        abort();
    } else {
        original_MungeVouchers(pPowerup, pPeriod);
    }
}

function_hook_state_t function_hook_state_SetInstantHandbrake = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_SetInstantHandbrake)
static int(__cdecl*original_SetInstantHandbrake)(tPowerup *, tCar_spec *) = (int(__cdecl*)(tPowerup *, tCar_spec *))0x0042e8af;
CARM95_HOOK_FUNCTION(original_SetInstantHandbrake, SetInstantHandbrake)
int __cdecl SetInstantHandbrake(tPowerup *pPowerup, tCar_spec *pCar) {
    LOG_TRACE("(%p, %p)", pPowerup, pCar);

    (void)pPowerup;
    (void)pCar;

    if (function_hook_state_SetInstantHandbrake == HOOK_ENABLED) {
        assert(0 && "SetInstantHandbrake not implemented.");
        abort();
    } else {
        return original_SetInstantHandbrake(pPowerup, pCar);
    }
}

function_hook_state_t function_hook_state_ResetInstantHandbrake = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_ResetInstantHandbrake)
static void(__cdecl*original_ResetInstantHandbrake)(tPowerup *, tCar_spec *) = (void(__cdecl*)(tPowerup *, tCar_spec *))0x0042e8e7;
CARM95_HOOK_FUNCTION(original_ResetInstantHandbrake, ResetInstantHandbrake)
void __cdecl ResetInstantHandbrake(tPowerup *pPowerup, tCar_spec *pCar) {
    LOG_TRACE("(%p, %p)", pPowerup, pCar);

    (void)pPowerup;
    (void)pCar;

    if (function_hook_state_ResetInstantHandbrake == HOOK_ENABLED) {
        assert(0 && "ResetInstantHandbrake not implemented.");
        abort();
    } else {
        original_ResetInstantHandbrake(pPowerup, pCar);
    }
}

function_hook_state_t function_hook_state_DoBouncey = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_DoBouncey)
static void(__cdecl*original_DoBouncey)(tPowerup *, tU32) = (void(__cdecl*)(tPowerup *, tU32))0x0042e909;
CARM95_HOOK_FUNCTION(original_DoBouncey, DoBouncey)
void __cdecl DoBouncey(tPowerup *pPowerup, tU32 pPeriod) {
    LOG_TRACE("(%p, %u)", pPowerup, pPeriod);

    (void)pPowerup;
    (void)pPeriod;

    if (function_hook_state_DoBouncey == HOOK_ENABLED) {
        assert(0 && "DoBouncey not implemented.");
        abort();
    } else {
        original_DoBouncey(pPowerup, pPeriod);
    }
}

function_hook_state_t function_hook_state_HitMine = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_HitMine)
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
        assert(0 && "HitMine not implemented.");
        abort();
    } else {
        return original_HitMine(pPowerup, pCar);
    }
}

function_hook_state_t function_hook_state_SetMassMultiplier = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_SetMassMultiplier)
static int(__cdecl*original_SetMassMultiplier)(tPowerup *, tCar_spec *) = (int(__cdecl*)(tPowerup *, tCar_spec *))0x0042eb2f;
CARM95_HOOK_FUNCTION(original_SetMassMultiplier, SetMassMultiplier)
int __cdecl SetMassMultiplier(tPowerup *pPowerup, tCar_spec *pCar) {
    LOG_TRACE("(%p, %p)", pPowerup, pCar);

    (void)pPowerup;
    (void)pCar;

    if (function_hook_state_SetMassMultiplier == HOOK_ENABLED) {
        assert(0 && "SetMassMultiplier not implemented.");
        abort();
    } else {
        return original_SetMassMultiplier(pPowerup, pCar);
    }
}

function_hook_state_t function_hook_state_ResetMassMultiplier = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_ResetMassMultiplier)
static void(__cdecl*original_ResetMassMultiplier)(tPowerup *, tCar_spec *) = (void(__cdecl*)(tPowerup *, tCar_spec *))0x0042eb61;
CARM95_HOOK_FUNCTION(original_ResetMassMultiplier, ResetMassMultiplier)
void __cdecl ResetMassMultiplier(tPowerup *pPowerup, tCar_spec *pCar) {
    LOG_TRACE("(%p, %p)", pPowerup, pCar);

    (void)pPowerup;
    (void)pCar;

    if (function_hook_state_ResetMassMultiplier == HOOK_ENABLED) {
        assert(0 && "ResetMassMultiplier not implemented.");
        abort();
    } else {
        original_ResetMassMultiplier(pPowerup, pCar);
    }
}

function_hook_state_t function_hook_state_ShowPedestrians = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_ShowPedestrians)
static int(__cdecl*original_ShowPedestrians)(tPowerup *, tCar_spec *) = (int(__cdecl*)(tPowerup *, tCar_spec *))0x0042eb79;
CARM95_HOOK_FUNCTION(original_ShowPedestrians, ShowPedestrians)
int __cdecl ShowPedestrians(tPowerup *pPowerup, tCar_spec *pCar) {
    LOG_TRACE("(%p, %p)", pPowerup, pCar);

    (void)pPowerup;
    (void)pCar;

    if (function_hook_state_ShowPedestrians == HOOK_ENABLED) {
        assert(0 && "ShowPedestrians not implemented.");
        abort();
    } else {
        return original_ShowPedestrians(pPowerup, pCar);
    }
}

function_hook_state_t function_hook_state_HidePedestrians = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_HidePedestrians)
static void(__cdecl*original_HidePedestrians)(tPowerup *, tCar_spec *) = (void(__cdecl*)(tPowerup *, tCar_spec *))0x0042ebb1;
CARM95_HOOK_FUNCTION(original_HidePedestrians, HidePedestrians)
void __cdecl HidePedestrians(tPowerup *pPowerup, tCar_spec *pCar) {
    LOG_TRACE("(%p, %p)", pPowerup, pCar);

    (void)pPowerup;
    (void)pCar;

    if (function_hook_state_HidePedestrians == HOOK_ENABLED) {
        assert(0 && "HidePedestrians not implemented.");
        abort();
    } else {
        original_HidePedestrians(pPowerup, pCar);
    }
}

function_hook_state_t function_hook_state_SetProximity = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_SetProximity)
static int(__cdecl*original_SetProximity)(tPowerup *, tCar_spec *) = (int(__cdecl*)(tPowerup *, tCar_spec *))0x0042ebd3;
CARM95_HOOK_FUNCTION(original_SetProximity, SetProximity)
int __cdecl SetProximity(tPowerup *pPowerup, tCar_spec *pCar) {
    LOG_TRACE("(%p, %p)", pPowerup, pCar);

    (void)pPowerup;
    (void)pCar;

    if (function_hook_state_SetProximity == HOOK_ENABLED) {
        assert(0 && "SetProximity not implemented.");
        abort();
    } else {
        return original_SetProximity(pPowerup, pCar);
    }
}

function_hook_state_t function_hook_state_ResetProximity = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_ResetProximity)
static void(__cdecl*original_ResetProximity)(tPowerup *, tCar_spec *) = (void(__cdecl*)(tPowerup *, tCar_spec *))0x0042ec0d;
CARM95_HOOK_FUNCTION(original_ResetProximity, ResetProximity)
void __cdecl ResetProximity(tPowerup *pPowerup, tCar_spec *pCar) {
    LOG_TRACE("(%p, %p)", pPowerup, pCar);

    (void)pPowerup;
    (void)pCar;

    if (function_hook_state_ResetProximity == HOOK_ENABLED) {
        assert(0 && "ResetProximity not implemented.");
        abort();
    } else {
        original_ResetProximity(pPowerup, pCar);
    }
}

function_hook_state_t function_hook_state_SetPedHarvest = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_SetPedHarvest)
static int(__cdecl*original_SetPedHarvest)(tPowerup *, tCar_spec *) = (int(__cdecl*)(tPowerup *, tCar_spec *))0x0042ec25;
CARM95_HOOK_FUNCTION(original_SetPedHarvest, SetPedHarvest)
int __cdecl SetPedHarvest(tPowerup *pPowerup, tCar_spec *pCar) {
    LOG_TRACE("(%p, %p)", pPowerup, pCar);

    (void)pPowerup;
    (void)pCar;

    if (function_hook_state_SetPedHarvest == HOOK_ENABLED) {
        assert(0 && "SetPedHarvest not implemented.");
        abort();
    } else {
        return original_SetPedHarvest(pPowerup, pCar);
    }
}

function_hook_state_t function_hook_state_ResetPedHarvest = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_ResetPedHarvest)
static void(__cdecl*original_ResetPedHarvest)(tPowerup *, tCar_spec *) = (void(__cdecl*)(tPowerup *, tCar_spec *))0x0042ec50;
CARM95_HOOK_FUNCTION(original_ResetPedHarvest, ResetPedHarvest)
void __cdecl ResetPedHarvest(tPowerup *pPowerup, tCar_spec *pCar) {
    int i;
    LOG_TRACE("(%p, %p)", pPowerup, pCar);

    (void)pPowerup;
    (void)pCar;
    (void)i;

    if (function_hook_state_ResetPedHarvest == HOOK_ENABLED) {
        assert(0 && "ResetPedHarvest not implemented.");
        abort();
    } else {
        original_ResetPedHarvest(pPowerup, pCar);
    }
}

function_hook_state_t function_hook_state_SetVesuvianCorpses = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_SetVesuvianCorpses)
static int(__cdecl*original_SetVesuvianCorpses)(tPowerup *, tCar_spec *) = (int(__cdecl*)(tPowerup *, tCar_spec *))0x0042ecb8;
CARM95_HOOK_FUNCTION(original_SetVesuvianCorpses, SetVesuvianCorpses)
int __cdecl SetVesuvianCorpses(tPowerup *pPowerup, tCar_spec *pCar) {
    LOG_TRACE("(%p, %p)", pPowerup, pCar);

    (void)pPowerup;
    (void)pCar;

    if (function_hook_state_SetVesuvianCorpses == HOOK_ENABLED) {
        assert(0 && "SetVesuvianCorpses not implemented.");
        abort();
    } else {
        return original_SetVesuvianCorpses(pPowerup, pCar);
    }
}

function_hook_state_t function_hook_state_ResetVesuvianCorpses = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_ResetVesuvianCorpses)
static void(__cdecl*original_ResetVesuvianCorpses)(tPowerup *, tCar_spec *) = (void(__cdecl*)(tPowerup *, tCar_spec *))0x0042ece3;
CARM95_HOOK_FUNCTION(original_ResetVesuvianCorpses, ResetVesuvianCorpses)
void __cdecl ResetVesuvianCorpses(tPowerup *pPowerup, tCar_spec *pCar) {
    LOG_TRACE("(%p, %p)", pPowerup, pCar);

    (void)pPowerup;
    (void)pCar;

    if (function_hook_state_ResetVesuvianCorpses == HOOK_ENABLED) {
        assert(0 && "ResetVesuvianCorpses not implemented.");
        abort();
    } else {
        original_ResetVesuvianCorpses(pPowerup, pCar);
    }
}

function_hook_state_t function_hook_state_ReceivedPowerup = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_ReceivedPowerup)
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
        assert(0 && "ReceivedPowerup not implemented.");
        abort();
    } else {
        original_ReceivedPowerup(pContents);
    }
}

function_hook_state_t function_hook_state_SendCurrentPowerups = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_SendCurrentPowerups)
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
        assert(0 && "SendCurrentPowerups not implemented.");
        abort();
    } else {
        original_SendCurrentPowerups();
    }
}

function_hook_state_t function_hook_state_LoseAllLocalPowerups = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_LoseAllLocalPowerups)
static void(__cdecl*original_LoseAllLocalPowerups)(tCar_spec *) = (void(__cdecl*)(tCar_spec *))0x0042f043;
CARM95_HOOK_FUNCTION(original_LoseAllLocalPowerups, LoseAllLocalPowerups)
void __cdecl LoseAllLocalPowerups(tCar_spec *pCar) {
    int i;
    LOG_TRACE("(%p)", pCar);

    (void)pCar;
    (void)i;

    if (function_hook_state_LoseAllLocalPowerups == HOOK_ENABLED) {
        assert(0 && "LoseAllLocalPowerups not implemented.");
        abort();
    } else {
        original_LoseAllLocalPowerups(pCar);
    }
}

// Added by dethrace
function_hook_state_t function_hook_state_GetPowerupMessage = HOOK_UNAVAILABLE;
static void(__cdecl*original_GetPowerupMessage)(int *, char*) = (void(__cdecl*)(int, char *))0x0042f0cc;
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
