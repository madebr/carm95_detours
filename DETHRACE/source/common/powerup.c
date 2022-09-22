#include "powerup.h"

#include "harness/trace.h"

#include "carm95_hooks.h"

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

    original_LosePowerupX(pThe_powerup, pTell_net_players);
}

static void(__cdecl*original_LosePowerup)(tPowerup *) = (void(__cdecl*)(tPowerup *))0x0042cfdd;
CARM95_HOOK_FUNCTION(original_LosePowerup, LosePowerup)
void __cdecl LosePowerup(tPowerup *pThe_powerup) {
    LOG_TRACE("(%p)", pThe_powerup);

    (void)pThe_powerup;

    original_LosePowerup(pThe_powerup);
}

static void(__cdecl*original_LoseAllSimilarPowerups)(tPowerup *) = (void(__cdecl*)(tPowerup *))0x0042cf5e;
CARM95_HOOK_FUNCTION(original_LoseAllSimilarPowerups, LoseAllSimilarPowerups)
void __cdecl LoseAllSimilarPowerups(tPowerup *pThe_powerup) {
    int i;
    tPowerup *the_powerup;
    LOG_TRACE("(%p)", pThe_powerup);

    (void)pThe_powerup;
    (void)i;
    (void)the_powerup;

    original_LoseAllSimilarPowerups(pThe_powerup);
}

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

    return original_GotPowerupX(pCar, pIndex, pTell_net_players, pDisplay_headup, pTime_left);
}

static int(__cdecl*original_GotPowerup)(tCar_spec *, int) = (int(__cdecl*)(tCar_spec *, int))0x0042d121;
CARM95_HOOK_FUNCTION(original_GotPowerup, GotPowerup)
int __cdecl GotPowerup(tCar_spec *pCar, int pIndex) {
    LOG_TRACE("(%p, %d)", pCar, pIndex);

    (void)pCar;
    (void)pIndex;

    return original_GotPowerup(pCar, pIndex);
}

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

    original_LoadPowerups();
}

static void(__cdecl*original_InitPowerups)() = (void(__cdecl*)())0x0042d536;
CARM95_HOOK_FUNCTION(original_InitPowerups, InitPowerups)
void __cdecl InitPowerups() {
    int i;
    tPowerup *the_powerup;
    LOG_TRACE("()");

    (void)i;
    (void)the_powerup;

    original_InitPowerups();
}

static void(__cdecl*original_CloseDownPowerUps)() = (void(__cdecl*)())0x0042d594;
CARM95_HOOK_FUNCTION(original_CloseDownPowerUps, CloseDownPowerUps)
void __cdecl CloseDownPowerUps() {
    int i;
    tPowerup *the_powerup;
    LOG_TRACE("()");

    (void)i;
    (void)the_powerup;

    original_CloseDownPowerUps();
}

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

    original_DrawPowerups(pTime);
}

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

    original_DoPowerupPeriodics(pFrame_period);
}

static void(__cdecl*original_GotPowerupN)(int) = (void(__cdecl*)(int))0x0042d965;
CARM95_HOOK_FUNCTION(original_GotPowerupN, GotPowerupN)
void __cdecl GotPowerupN(int pN) {
    int modifiers;
    LOG_TRACE("(%d)", pN);

    (void)pN;
    (void)modifiers;

    original_GotPowerupN(pN);
}

static void(__cdecl*original_GotPowerup0)() = (void(__cdecl*)())0x0042d9e8;
CARM95_HOOK_FUNCTION(original_GotPowerup0, GotPowerup0)
void __cdecl GotPowerup0() {
    LOG_TRACE("()");


    original_GotPowerup0();
}

static void(__cdecl*original_GotPowerup1)() = (void(__cdecl*)())0x0042d9fd;
CARM95_HOOK_FUNCTION(original_GotPowerup1, GotPowerup1)
void __cdecl GotPowerup1() {
    LOG_TRACE("()");


    original_GotPowerup1();
}

static void(__cdecl*original_GotPowerup2)() = (void(__cdecl*)())0x0042da12;
CARM95_HOOK_FUNCTION(original_GotPowerup2, GotPowerup2)
void __cdecl GotPowerup2() {
    LOG_TRACE("()");


    original_GotPowerup2();
}

static void(__cdecl*original_GotPowerup3)() = (void(__cdecl*)())0x0042da27;
CARM95_HOOK_FUNCTION(original_GotPowerup3, GotPowerup3)
void __cdecl GotPowerup3() {
    LOG_TRACE("()");


    original_GotPowerup3();
}

static void(__cdecl*original_GotPowerup4)() = (void(__cdecl*)())0x0042da3c;
CARM95_HOOK_FUNCTION(original_GotPowerup4, GotPowerup4)
void __cdecl GotPowerup4() {
    LOG_TRACE("()");


    original_GotPowerup4();
}

static void(__cdecl*original_GotPowerup5)() = (void(__cdecl*)())0x0042da51;
CARM95_HOOK_FUNCTION(original_GotPowerup5, GotPowerup5)
void __cdecl GotPowerup5() {
    LOG_TRACE("()");


    original_GotPowerup5();
}

static void(__cdecl*original_GotPowerup6)() = (void(__cdecl*)())0x0042da66;
CARM95_HOOK_FUNCTION(original_GotPowerup6, GotPowerup6)
void __cdecl GotPowerup6() {
    LOG_TRACE("()");


    original_GotPowerup6();
}

static void(__cdecl*original_GotPowerup7)() = (void(__cdecl*)())0x0042da7b;
CARM95_HOOK_FUNCTION(original_GotPowerup7, GotPowerup7)
void __cdecl GotPowerup7() {
    LOG_TRACE("()");


    original_GotPowerup7();
}

static void(__cdecl*original_GotPowerup8)() = (void(__cdecl*)())0x0042da90;
CARM95_HOOK_FUNCTION(original_GotPowerup8, GotPowerup8)
void __cdecl GotPowerup8() {
    LOG_TRACE("()");


    original_GotPowerup8();
}

static void(__cdecl*original_GotPowerup9)() = (void(__cdecl*)())0x0042daa5;
CARM95_HOOK_FUNCTION(original_GotPowerup9, GotPowerup9)
void __cdecl GotPowerup9() {
    LOG_TRACE("()");


    original_GotPowerup9();
}

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

    return original_GotCredits(pPowerup, pCar);
}

static void(__cdecl*original_ImprovePSPowerup)(tCar_spec *, int) = (void(__cdecl*)(tCar_spec *, int))0x0042db7a;
CARM95_HOOK_FUNCTION(original_ImprovePSPowerup, ImprovePSPowerup)
void __cdecl ImprovePSPowerup(tCar_spec *pCar, int pIndex) {
    tNet_message *the_message;
    LOG_TRACE("(%p, %d)", pCar, pIndex);

    (void)pCar;
    (void)pIndex;
    (void)the_message;

    original_ImprovePSPowerup(pCar, pIndex);
}

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

    return original_GotTimeOrPower(pPowerup, pCar);
}

static int(__cdecl*original_SetPedSpeed)(tPowerup *, tCar_spec *) = (int(__cdecl*)(tPowerup *, tCar_spec *))0x0042dd8b;
CARM95_HOOK_FUNCTION(original_SetPedSpeed, SetPedSpeed)
int __cdecl SetPedSpeed(tPowerup *pPowerup, tCar_spec *pCar) {
    LOG_TRACE("(%p, %p)", pPowerup, pCar);

    (void)pPowerup;
    (void)pCar;

    return original_SetPedSpeed(pPowerup, pCar);
}

static int(__cdecl*original_SetHades)(tPowerup *, tCar_spec *) = (int(__cdecl*)(tPowerup *, tCar_spec *))0x0042ddb9;
CARM95_HOOK_FUNCTION(original_SetHades, SetHades)
int __cdecl SetHades(tPowerup *pPowerup, tCar_spec *pCar) {
    LOG_TRACE("(%p, %p)", pPowerup, pCar);

    (void)pPowerup;
    (void)pCar;

    return original_SetHades(pPowerup, pCar);
}

static void(__cdecl*original_ResetHades)(tPowerup *, tCar_spec *) = (void(__cdecl*)(tPowerup *, tCar_spec *))0x0042dddf;
CARM95_HOOK_FUNCTION(original_ResetHades, ResetHades)
void __cdecl ResetHades(tPowerup *pPowerup, tCar_spec *pCar) {
    LOG_TRACE("(%p, %p)", pPowerup, pCar);

    (void)pPowerup;
    (void)pCar;

    original_ResetHades(pPowerup, pCar);
}

static int(__cdecl*original_SetPedSize)(tPowerup *, tCar_spec *) = (int(__cdecl*)(tPowerup *, tCar_spec *))0x0042ddef;
CARM95_HOOK_FUNCTION(original_SetPedSize, SetPedSize)
int __cdecl SetPedSize(tPowerup *pPowerup, tCar_spec *pCar) {
    br_scalar old_scale;
    LOG_TRACE("(%p, %p)", pPowerup, pCar);

    (void)pPowerup;
    (void)pCar;
    (void)old_scale;

    return original_SetPedSize(pPowerup, pCar);
}

static int(__cdecl*original_SetPedExplode)(tPowerup *, tCar_spec *) = (int(__cdecl*)(tPowerup *, tCar_spec *))0x0042dec4;
CARM95_HOOK_FUNCTION(original_SetPedExplode, SetPedExplode)
int __cdecl SetPedExplode(tPowerup *pPowerup, tCar_spec *pCar) {
    LOG_TRACE("(%p, %p)", pPowerup, pCar);

    (void)pPowerup;
    (void)pCar;

    return original_SetPedExplode(pPowerup, pCar);
}

static int(__cdecl*original_SetInvulnerability)(tPowerup *, tCar_spec *) = (int(__cdecl*)(tPowerup *, tCar_spec *))0x0042deef;
CARM95_HOOK_FUNCTION(original_SetInvulnerability, SetInvulnerability)
int __cdecl SetInvulnerability(tPowerup *pPowerup, tCar_spec *pCar) {
    LOG_TRACE("(%p, %p)", pPowerup, pCar);

    (void)pPowerup;
    (void)pCar;

    return original_SetInvulnerability(pPowerup, pCar);
}

static void(__cdecl*original_ResetInvulnerability)(tPowerup *, tCar_spec *) = (void(__cdecl*)(tPowerup *, tCar_spec *))0x0042df1d;
CARM95_HOOK_FUNCTION(original_ResetInvulnerability, ResetInvulnerability)
void __cdecl ResetInvulnerability(tPowerup *pPowerup, tCar_spec *pCar) {
    LOG_TRACE("(%p, %p)", pPowerup, pCar);

    (void)pPowerup;
    (void)pCar;

    original_ResetInvulnerability(pPowerup, pCar);
}

static int(__cdecl*original_SetFreeRepairs)(tPowerup *, tCar_spec *) = (int(__cdecl*)(tPowerup *, tCar_spec *))0x0042df35;
CARM95_HOOK_FUNCTION(original_SetFreeRepairs, SetFreeRepairs)
int __cdecl SetFreeRepairs(tPowerup *pPowerup, tCar_spec *pCar) {
    LOG_TRACE("(%p, %p)", pPowerup, pCar);

    (void)pPowerup;
    (void)pCar;

    return original_SetFreeRepairs(pPowerup, pCar);
}

static void(__cdecl*original_ResetFreeRepairs)(tPowerup *, tCar_spec *) = (void(__cdecl*)(tPowerup *, tCar_spec *))0x0042df6d;
CARM95_HOOK_FUNCTION(original_ResetFreeRepairs, ResetFreeRepairs)
void __cdecl ResetFreeRepairs(tPowerup *pPowerup, tCar_spec *pCar) {
    LOG_TRACE("(%p, %p)", pPowerup, pCar);

    (void)pPowerup;
    (void)pCar;

    original_ResetFreeRepairs(pPowerup, pCar);
}

static int(__cdecl*original_SetBlindPedestrians)(tPowerup *, tCar_spec *) = (int(__cdecl*)(tPowerup *, tCar_spec *))0x0042df8f;
CARM95_HOOK_FUNCTION(original_SetBlindPedestrians, SetBlindPedestrians)
int __cdecl SetBlindPedestrians(tPowerup *pPowerup, tCar_spec *pCar) {
    LOG_TRACE("(%p, %p)", pPowerup, pCar);

    (void)pPowerup;
    (void)pCar;

    return original_SetBlindPedestrians(pPowerup, pCar);
}

static void(__cdecl*original_ResetBlindPedestrians)(tPowerup *, tCar_spec *) = (void(__cdecl*)(tPowerup *, tCar_spec *))0x0042dfba;
CARM95_HOOK_FUNCTION(original_ResetBlindPedestrians, ResetBlindPedestrians)
void __cdecl ResetBlindPedestrians(tPowerup *pPowerup, tCar_spec *pCar) {
    LOG_TRACE("(%p, %p)", pPowerup, pCar);

    (void)pPowerup;
    (void)pCar;

    original_ResetBlindPedestrians(pPowerup, pCar);
}

static int(__cdecl*original_FreezeTimer)(tPowerup *, tCar_spec *) = (int(__cdecl*)(tPowerup *, tCar_spec *))0x0042dfcf;
CARM95_HOOK_FUNCTION(original_FreezeTimer, FreezeTimer)
int __cdecl FreezeTimer(tPowerup *pPowerup, tCar_spec *pCar) {
    LOG_TRACE("(%p, %p)", pPowerup, pCar);

    (void)pPowerup;
    (void)pCar;

    return original_FreezeTimer(pPowerup, pCar);
}

static void(__cdecl*original_UnfreezeTimer)(tPowerup *, tCar_spec *) = (void(__cdecl*)(tPowerup *, tCar_spec *))0x0042e023;
CARM95_HOOK_FUNCTION(original_UnfreezeTimer, UnfreezeTimer)
void __cdecl UnfreezeTimer(tPowerup *pPowerup, tCar_spec *pCar) {
    LOG_TRACE("(%p, %p)", pPowerup, pCar);

    (void)pPowerup;
    (void)pCar;

    original_UnfreezeTimer(pPowerup, pCar);
}

static int(__cdecl*original_DoInstantRepair)(tPowerup *, tCar_spec *) = (int(__cdecl*)(tPowerup *, tCar_spec *))0x0042e045;
CARM95_HOOK_FUNCTION(original_DoInstantRepair, DoInstantRepair)
int __cdecl DoInstantRepair(tPowerup *pPowerup, tCar_spec *pCar) {
    LOG_TRACE("(%p, %p)", pPowerup, pCar);

    (void)pPowerup;
    (void)pCar;

    return original_DoInstantRepair(pPowerup, pCar);
}

static void(__cdecl*original_ResetPedSpeed)(tPowerup *, tCar_spec *) = (void(__cdecl*)(tPowerup *, tCar_spec *))0x0042e078;
CARM95_HOOK_FUNCTION(original_ResetPedSpeed, ResetPedSpeed)
void __cdecl ResetPedSpeed(tPowerup *pPowerup, tCar_spec *pCar) {
    LOG_TRACE("(%p, %p)", pPowerup, pCar);

    (void)pPowerup;
    (void)pCar;

    original_ResetPedSpeed(pPowerup, pCar);
}

static void(__cdecl*original_ResetPedSize)(tPowerup *, tCar_spec *) = (void(__cdecl*)(tPowerup *, tCar_spec *))0x0042e08d;
CARM95_HOOK_FUNCTION(original_ResetPedSize, ResetPedSize)
void __cdecl ResetPedSize(tPowerup *pPowerup, tCar_spec *pCar) {
    LOG_TRACE("(%p, %p)", pPowerup, pCar);

    (void)pPowerup;
    (void)pCar;

    original_ResetPedSize(pPowerup, pCar);
}

static void(__cdecl*original_ResetPedExplode)(tPowerup *, tCar_spec *) = (void(__cdecl*)(tPowerup *, tCar_spec *))0x0042e0ac;
CARM95_HOOK_FUNCTION(original_ResetPedExplode, ResetPedExplode)
void __cdecl ResetPedExplode(tPowerup *pPowerup, tCar_spec *pCar) {
    LOG_TRACE("(%p, %p)", pPowerup, pCar);

    (void)pPowerup;
    (void)pCar;

    original_ResetPedExplode(pPowerup, pCar);
}

static int(__cdecl*original_SetEngineFactor)(tPowerup *, tCar_spec *) = (int(__cdecl*)(tPowerup *, tCar_spec *))0x0042e0c1;
CARM95_HOOK_FUNCTION(original_SetEngineFactor, SetEngineFactor)
int __cdecl SetEngineFactor(tPowerup *pPowerup, tCar_spec *pCar) {
    LOG_TRACE("(%p, %p)", pPowerup, pCar);

    (void)pPowerup;
    (void)pCar;

    return original_SetEngineFactor(pPowerup, pCar);
}

static int(__cdecl*original_SetUnderwater)(tPowerup *, tCar_spec *) = (int(__cdecl*)(tPowerup *, tCar_spec *))0x0042e143;
CARM95_HOOK_FUNCTION(original_SetUnderwater, SetUnderwater)
int __cdecl SetUnderwater(tPowerup *pPowerup, tCar_spec *pCar) {
    LOG_TRACE("(%p, %p)", pPowerup, pCar);

    (void)pPowerup;
    (void)pCar;

    return original_SetUnderwater(pPowerup, pCar);
}

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

    return original_TrashBodywork(pPowerup, pCar);
}

static int(__cdecl*original_TakeDrugs)(tPowerup *, tCar_spec *) = (int(__cdecl*)(tPowerup *, tCar_spec *))0x0042e26c;
CARM95_HOOK_FUNCTION(original_TakeDrugs, TakeDrugs)
int __cdecl TakeDrugs(tPowerup *pPowerup, tCar_spec *pCar) {
    LOG_TRACE("(%p, %p)", pPowerup, pCar);

    (void)pPowerup;
    (void)pCar;

    return original_TakeDrugs(pPowerup, pCar);
}

static void(__cdecl*original_PaletteFuckedUpByDrugs)(br_pixelmap *, int) = (void(__cdecl*)(br_pixelmap *, int))0x0042e30a;
CARM95_HOOK_FUNCTION(original_PaletteFuckedUpByDrugs, PaletteFuckedUpByDrugs)
void __cdecl PaletteFuckedUpByDrugs(br_pixelmap *pPixelmap, int pOffset) {
    int i;
    LOG_TRACE("(%p, %d)", pPixelmap, pOffset);

    (void)pPixelmap;
    (void)pOffset;
    (void)i;

    original_PaletteFuckedUpByDrugs(pPixelmap, pOffset);
}

static void(__cdecl*original_TheEffectsOfDrugs)(tPowerup *, tU32) = (void(__cdecl*)(tPowerup *, tU32))0x0042e2dd;
CARM95_HOOK_FUNCTION(original_TheEffectsOfDrugs, TheEffectsOfDrugs)
void __cdecl TheEffectsOfDrugs(tPowerup *pPowerup, tU32 pPeriod) {
    LOG_TRACE("(%p, %u)", pPowerup, pPeriod);

    (void)pPowerup;
    (void)pPeriod;

    original_TheEffectsOfDrugs(pPowerup, pPeriod);
}

static int(__cdecl*original_SetOpponentsSpeed)(tPowerup *, tCar_spec *) = (int(__cdecl*)(tPowerup *, tCar_spec *))0x0042e3af;
CARM95_HOOK_FUNCTION(original_SetOpponentsSpeed, SetOpponentsSpeed)
int __cdecl SetOpponentsSpeed(tPowerup *pPowerup, tCar_spec *pCar) {
    int i;
    LOG_TRACE("(%p, %p)", pPowerup, pCar);

    (void)pPowerup;
    (void)pCar;
    (void)i;

    return original_SetOpponentsSpeed(pPowerup, pCar);
}

static int(__cdecl*original_SetCopsSpeed)(tPowerup *, tCar_spec *) = (int(__cdecl*)(tPowerup *, tCar_spec *))0x0042e445;
CARM95_HOOK_FUNCTION(original_SetCopsSpeed, SetCopsSpeed)
int __cdecl SetCopsSpeed(tPowerup *pPowerup, tCar_spec *pCar) {
    LOG_TRACE("(%p, %p)", pPowerup, pCar);

    (void)pPowerup;
    (void)pCar;

    return original_SetCopsSpeed(pPowerup, pCar);
}

static int(__cdecl*original_SetGravity)(tPowerup *, tCar_spec *) = (int(__cdecl*)(tPowerup *, tCar_spec *))0x0042e473;
CARM95_HOOK_FUNCTION(original_SetGravity, SetGravity)
int __cdecl SetGravity(tPowerup *pPowerup, tCar_spec *pCar) {
    LOG_TRACE("(%p, %p)", pPowerup, pCar);

    (void)pPowerup;
    (void)pCar;

    return original_SetGravity(pPowerup, pCar);
}

static int(__cdecl*original_SetPinball)(tPowerup *, tCar_spec *) = (int(__cdecl*)(tPowerup *, tCar_spec *))0x0042e4a1;
CARM95_HOOK_FUNCTION(original_SetPinball, SetPinball)
int __cdecl SetPinball(tPowerup *pPowerup, tCar_spec *pCar) {
    LOG_TRACE("(%p, %p)", pPowerup, pCar);

    (void)pPowerup;
    (void)pCar;

    return original_SetPinball(pPowerup, pCar);
}

static int(__cdecl*original_SetWallclimb)(tPowerup *, tCar_spec *) = (int(__cdecl*)(tPowerup *, tCar_spec *))0x0042e4cf;
CARM95_HOOK_FUNCTION(original_SetWallclimb, SetWallclimb)
int __cdecl SetWallclimb(tPowerup *pPowerup, tCar_spec *pCar) {
    LOG_TRACE("(%p, %p)", pPowerup, pCar);

    (void)pPowerup;
    (void)pCar;

    return original_SetWallclimb(pPowerup, pCar);
}

static int(__cdecl*original_SetBouncey)(tPowerup *, tCar_spec *) = (int(__cdecl*)(tPowerup *, tCar_spec *))0x0042e4fd;
CARM95_HOOK_FUNCTION(original_SetBouncey, SetBouncey)
int __cdecl SetBouncey(tPowerup *pPowerup, tCar_spec *pCar) {
    LOG_TRACE("(%p, %p)", pPowerup, pCar);

    (void)pPowerup;
    (void)pCar;

    return original_SetBouncey(pPowerup, pCar);
}

static int(__cdecl*original_SetSuspension)(tPowerup *, tCar_spec *) = (int(__cdecl*)(tPowerup *, tCar_spec *))0x0042e554;
CARM95_HOOK_FUNCTION(original_SetSuspension, SetSuspension)
int __cdecl SetSuspension(tPowerup *pPowerup, tCar_spec *pCar) {
    LOG_TRACE("(%p, %p)", pPowerup, pCar);

    (void)pPowerup;
    (void)pCar;

    return original_SetSuspension(pPowerup, pCar);
}

static int(__cdecl*original_SetTyreGrip)(tPowerup *, tCar_spec *) = (int(__cdecl*)(tPowerup *, tCar_spec *))0x0042e5b2;
CARM95_HOOK_FUNCTION(original_SetTyreGrip, SetTyreGrip)
int __cdecl SetTyreGrip(tPowerup *pPowerup, tCar_spec *pCar) {
    LOG_TRACE("(%p, %p)", pPowerup, pCar);

    (void)pPowerup;
    (void)pCar;

    return original_SetTyreGrip(pPowerup, pCar);
}

static int(__cdecl*original_SetDamageMultiplier)(tPowerup *, tCar_spec *) = (int(__cdecl*)(tPowerup *, tCar_spec *))0x0042e5e4;
CARM95_HOOK_FUNCTION(original_SetDamageMultiplier, SetDamageMultiplier)
int __cdecl SetDamageMultiplier(tPowerup *pPowerup, tCar_spec *pCar) {
    LOG_TRACE("(%p, %p)", pPowerup, pCar);

    (void)pPowerup;
    (void)pCar;

    return original_SetDamageMultiplier(pPowerup, pCar);
}

static void(__cdecl*original_ResetEngineFactor)(tPowerup *, tCar_spec *) = (void(__cdecl*)(tPowerup *, tCar_spec *))0x0042e616;
CARM95_HOOK_FUNCTION(original_ResetEngineFactor, ResetEngineFactor)
void __cdecl ResetEngineFactor(tPowerup *pPowerup, tCar_spec *pCar) {
    LOG_TRACE("(%p, %p)", pPowerup, pCar);

    (void)pPowerup;
    (void)pCar;

    original_ResetEngineFactor(pPowerup, pCar);
}

static void(__cdecl*original_ResetUnderwater)(tPowerup *, tCar_spec *) = (void(__cdecl*)(tPowerup *, tCar_spec *))0x0042e65a;
CARM95_HOOK_FUNCTION(original_ResetUnderwater, ResetUnderwater)
void __cdecl ResetUnderwater(tPowerup *pPowerup, tCar_spec *pCar) {
    LOG_TRACE("(%p, %p)", pPowerup, pCar);

    (void)pPowerup;
    (void)pCar;

    original_ResetUnderwater(pPowerup, pCar);
}

static void(__cdecl*original_PukeDrugsBackUp)(tPowerup *, tCar_spec *) = (void(__cdecl*)(tPowerup *, tCar_spec *))0x0042e672;
CARM95_HOOK_FUNCTION(original_PukeDrugsBackUp, PukeDrugsBackUp)
void __cdecl PukeDrugsBackUp(tPowerup *pPowerup, tCar_spec *pCar) {
    LOG_TRACE("(%p, %p)", pPowerup, pCar);

    (void)pPowerup;
    (void)pCar;

    original_PukeDrugsBackUp(pPowerup, pCar);
}

static void(__fastcall*original_ResetOpponentsSpeed)(tPowerup *, tCar_spec *) = (void(__fastcall*)(tPowerup *, tCar_spec *))0x0042e6a9;
CARM95_HOOK_FUNCTION(original_ResetOpponentsSpeed, ResetOpponentsSpeed)
void __fastcall ResetOpponentsSpeed(tPowerup *pPowerup, tCar_spec *pCar) {
    int i;
    LOG_TRACE("(%p, %p)", pPowerup, pCar);

    (void)pPowerup;
    (void)pCar;
    (void)i;

    original_ResetOpponentsSpeed(pPowerup, pCar);
}

static void(__cdecl*original_ResetCopsSpeed)(tPowerup *, tCar_spec *) = (void(__cdecl*)(tPowerup *, tCar_spec *))0x0042e726;
CARM95_HOOK_FUNCTION(original_ResetCopsSpeed, ResetCopsSpeed)
void __cdecl ResetCopsSpeed(tPowerup *pPowerup, tCar_spec *pCar) {
    LOG_TRACE("(%p, %p)", pPowerup, pCar);

    (void)pPowerup;
    (void)pCar;

    original_ResetCopsSpeed(pPowerup, pCar);
}

static void(__cdecl*original_ResetGravity)(tPowerup *, tCar_spec *) = (void(__cdecl*)(tPowerup *, tCar_spec *))0x0042e73b;
CARM95_HOOK_FUNCTION(original_ResetGravity, ResetGravity)
void __cdecl ResetGravity(tPowerup *pPowerup, tCar_spec *pCar) {
    LOG_TRACE("(%p, %p)", pPowerup, pCar);

    (void)pPowerup;
    (void)pCar;

    original_ResetGravity(pPowerup, pCar);
}

static void(__cdecl*original_ResetPinball)(tPowerup *, tCar_spec *) = (void(__cdecl*)(tPowerup *, tCar_spec *))0x0042e750;
CARM95_HOOK_FUNCTION(original_ResetPinball, ResetPinball)
void __cdecl ResetPinball(tPowerup *pPowerup, tCar_spec *pCar) {
    LOG_TRACE("(%p, %p)", pPowerup, pCar);

    (void)pPowerup;
    (void)pCar;

    original_ResetPinball(pPowerup, pCar);
}

static void(__cdecl*original_ResetWallclimb)(tPowerup *, tCar_spec *) = (void(__cdecl*)(tPowerup *, tCar_spec *))0x0042e765;
CARM95_HOOK_FUNCTION(original_ResetWallclimb, ResetWallclimb)
void __cdecl ResetWallclimb(tPowerup *pPowerup, tCar_spec *pCar) {
    LOG_TRACE("(%p, %p)", pPowerup, pCar);

    (void)pPowerup;
    (void)pCar;

    original_ResetWallclimb(pPowerup, pCar);
}

static void(__cdecl*original_ResetBouncey)(tPowerup *, tCar_spec *) = (void(__cdecl*)(tPowerup *, tCar_spec *))0x0042e77d;
CARM95_HOOK_FUNCTION(original_ResetBouncey, ResetBouncey)
void __cdecl ResetBouncey(tPowerup *pPowerup, tCar_spec *pCar) {
    LOG_TRACE("(%p, %p)", pPowerup, pCar);

    (void)pPowerup;
    (void)pCar;

    original_ResetBouncey(pPowerup, pCar);
}

static void(__cdecl*original_ResetSuspension)(tPowerup *, tCar_spec *) = (void(__cdecl*)(tPowerup *, tCar_spec *))0x0042e7a2;
CARM95_HOOK_FUNCTION(original_ResetSuspension, ResetSuspension)
void __cdecl ResetSuspension(tPowerup *pPowerup, tCar_spec *pCar) {
    LOG_TRACE("(%p, %p)", pPowerup, pCar);

    (void)pPowerup;
    (void)pCar;

    original_ResetSuspension(pPowerup, pCar);
}

static void(__cdecl*original_ResetDamageMultiplier)(tPowerup *, tCar_spec *) = (void(__cdecl*)(tPowerup *, tCar_spec *))0x0042e7cc;
CARM95_HOOK_FUNCTION(original_ResetDamageMultiplier, ResetDamageMultiplier)
void __cdecl ResetDamageMultiplier(tPowerup *pPowerup, tCar_spec *pCar) {
    LOG_TRACE("(%p, %p)", pPowerup, pCar);

    (void)pPowerup;
    (void)pCar;

    original_ResetDamageMultiplier(pPowerup, pCar);
}

static void(__cdecl*original_ResetTyreGrip)(tPowerup *, tCar_spec *) = (void(__cdecl*)(tPowerup *, tCar_spec *))0x0042e7e4;
CARM95_HOOK_FUNCTION(original_ResetTyreGrip, ResetTyreGrip)
void __cdecl ResetTyreGrip(tPowerup *pPowerup, tCar_spec *pCar) {
    LOG_TRACE("(%p, %p)", pPowerup, pCar);

    (void)pPowerup;
    (void)pCar;

    original_ResetTyreGrip(pPowerup, pCar);
}

static int(__cdecl*original_PickAtRandom)(tPowerup *, tCar_spec *) = (int(__cdecl*)(tPowerup *, tCar_spec *))0x0042e7fc;
CARM95_HOOK_FUNCTION(original_PickAtRandom, PickAtRandom)
int __cdecl PickAtRandom(tPowerup *pPowerup, tCar_spec *pCar) {
    LOG_TRACE("(%p, %p)", pPowerup, pCar);

    (void)pPowerup;
    (void)pCar;

    return original_PickAtRandom(pPowerup, pCar);
}

static int(__cdecl*original_PedestrianRespawn)(tPowerup *, tCar_spec *) = (int(__cdecl*)(tPowerup *, tCar_spec *))0x0042e834;
CARM95_HOOK_FUNCTION(original_PedestrianRespawn, PedestrianRespawn)
int __cdecl PedestrianRespawn(tPowerup *pPowerup, tCar_spec *pCar) {
    LOG_TRACE("(%p, %p)", pPowerup, pCar);

    (void)pPowerup;
    (void)pCar;

    return original_PedestrianRespawn(pPowerup, pCar);
}

static int(__cdecl*original_GotVouchers)(tPowerup *, tCar_spec *) = (int(__cdecl*)(tPowerup *, tCar_spec *))0x0042e85a;
CARM95_HOOK_FUNCTION(original_GotVouchers, GotVouchers)
int __cdecl GotVouchers(tPowerup *pPowerup, tCar_spec *pCar) {
    LOG_TRACE("(%p, %p)", pPowerup, pCar);

    (void)pPowerup;
    (void)pCar;

    return original_GotVouchers(pPowerup, pCar);
}

static void(__cdecl*original_MungeVouchers)(tPowerup *, tU32) = (void(__cdecl*)(tPowerup *, tU32))0x0042e899;
CARM95_HOOK_FUNCTION(original_MungeVouchers, MungeVouchers)
void __cdecl MungeVouchers(tPowerup *pPowerup, tU32 pPeriod) {
    LOG_TRACE("(%p, %u)", pPowerup, pPeriod);

    (void)pPowerup;
    (void)pPeriod;

    original_MungeVouchers(pPowerup, pPeriod);
}

static int(__cdecl*original_SetInstantHandbrake)(tPowerup *, tCar_spec *) = (int(__cdecl*)(tPowerup *, tCar_spec *))0x0042e8af;
CARM95_HOOK_FUNCTION(original_SetInstantHandbrake, SetInstantHandbrake)
int __cdecl SetInstantHandbrake(tPowerup *pPowerup, tCar_spec *pCar) {
    LOG_TRACE("(%p, %p)", pPowerup, pCar);

    (void)pPowerup;
    (void)pCar;

    return original_SetInstantHandbrake(pPowerup, pCar);
}

static void(__cdecl*original_ResetInstantHandbrake)(tPowerup *, tCar_spec *) = (void(__cdecl*)(tPowerup *, tCar_spec *))0x0042e8e7;
CARM95_HOOK_FUNCTION(original_ResetInstantHandbrake, ResetInstantHandbrake)
void __cdecl ResetInstantHandbrake(tPowerup *pPowerup, tCar_spec *pCar) {
    LOG_TRACE("(%p, %p)", pPowerup, pCar);

    (void)pPowerup;
    (void)pCar;

    original_ResetInstantHandbrake(pPowerup, pCar);
}

static void(__cdecl*original_DoBouncey)(tPowerup *, tU32) = (void(__cdecl*)(tPowerup *, tU32))0x0042e909;
CARM95_HOOK_FUNCTION(original_DoBouncey, DoBouncey)
void __cdecl DoBouncey(tPowerup *pPowerup, tU32 pPeriod) {
    LOG_TRACE("(%p, %u)", pPowerup, pPeriod);

    (void)pPowerup;
    (void)pPeriod;

    original_DoBouncey(pPowerup, pPeriod);
}

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

    return original_HitMine(pPowerup, pCar);
}

static int(__cdecl*original_SetMassMultiplier)(tPowerup *, tCar_spec *) = (int(__cdecl*)(tPowerup *, tCar_spec *))0x0042eb2f;
CARM95_HOOK_FUNCTION(original_SetMassMultiplier, SetMassMultiplier)
int __cdecl SetMassMultiplier(tPowerup *pPowerup, tCar_spec *pCar) {
    LOG_TRACE("(%p, %p)", pPowerup, pCar);

    (void)pPowerup;
    (void)pCar;

    return original_SetMassMultiplier(pPowerup, pCar);
}

static void(__cdecl*original_ResetMassMultiplier)(tPowerup *, tCar_spec *) = (void(__cdecl*)(tPowerup *, tCar_spec *))0x0042eb61;
CARM95_HOOK_FUNCTION(original_ResetMassMultiplier, ResetMassMultiplier)
void __cdecl ResetMassMultiplier(tPowerup *pPowerup, tCar_spec *pCar) {
    LOG_TRACE("(%p, %p)", pPowerup, pCar);

    (void)pPowerup;
    (void)pCar;

    original_ResetMassMultiplier(pPowerup, pCar);
}

static int(__cdecl*original_ShowPedestrians)(tPowerup *, tCar_spec *) = (int(__cdecl*)(tPowerup *, tCar_spec *))0x0042eb79;
CARM95_HOOK_FUNCTION(original_ShowPedestrians, ShowPedestrians)
int __cdecl ShowPedestrians(tPowerup *pPowerup, tCar_spec *pCar) {
    LOG_TRACE("(%p, %p)", pPowerup, pCar);

    (void)pPowerup;
    (void)pCar;

    return original_ShowPedestrians(pPowerup, pCar);
}

static void(__cdecl*original_HidePedestrians)(tPowerup *, tCar_spec *) = (void(__cdecl*)(tPowerup *, tCar_spec *))0x0042ebb1;
CARM95_HOOK_FUNCTION(original_HidePedestrians, HidePedestrians)
void __cdecl HidePedestrians(tPowerup *pPowerup, tCar_spec *pCar) {
    LOG_TRACE("(%p, %p)", pPowerup, pCar);

    (void)pPowerup;
    (void)pCar;

    original_HidePedestrians(pPowerup, pCar);
}

static int(__cdecl*original_SetProximity)(tPowerup *, tCar_spec *) = (int(__cdecl*)(tPowerup *, tCar_spec *))0x0042ebd3;
CARM95_HOOK_FUNCTION(original_SetProximity, SetProximity)
int __cdecl SetProximity(tPowerup *pPowerup, tCar_spec *pCar) {
    LOG_TRACE("(%p, %p)", pPowerup, pCar);

    (void)pPowerup;
    (void)pCar;

    return original_SetProximity(pPowerup, pCar);
}

static void(__cdecl*original_ResetProximity)(tPowerup *, tCar_spec *) = (void(__cdecl*)(tPowerup *, tCar_spec *))0x0042ec0d;
CARM95_HOOK_FUNCTION(original_ResetProximity, ResetProximity)
void __cdecl ResetProximity(tPowerup *pPowerup, tCar_spec *pCar) {
    LOG_TRACE("(%p, %p)", pPowerup, pCar);

    (void)pPowerup;
    (void)pCar;

    original_ResetProximity(pPowerup, pCar);
}

static int(__cdecl*original_SetPedHarvest)(tPowerup *, tCar_spec *) = (int(__cdecl*)(tPowerup *, tCar_spec *))0x0042ec25;
CARM95_HOOK_FUNCTION(original_SetPedHarvest, SetPedHarvest)
int __cdecl SetPedHarvest(tPowerup *pPowerup, tCar_spec *pCar) {
    LOG_TRACE("(%p, %p)", pPowerup, pCar);

    (void)pPowerup;
    (void)pCar;

    return original_SetPedHarvest(pPowerup, pCar);
}

static void(__cdecl*original_ResetPedHarvest)(tPowerup *, tCar_spec *) = (void(__cdecl*)(tPowerup *, tCar_spec *))0x0042ec50;
CARM95_HOOK_FUNCTION(original_ResetPedHarvest, ResetPedHarvest)
void __cdecl ResetPedHarvest(tPowerup *pPowerup, tCar_spec *pCar) {
    int i;
    LOG_TRACE("(%p, %p)", pPowerup, pCar);

    (void)pPowerup;
    (void)pCar;
    (void)i;

    original_ResetPedHarvest(pPowerup, pCar);
}

static int(__cdecl*original_SetVesuvianCorpses)(tPowerup *, tCar_spec *) = (int(__cdecl*)(tPowerup *, tCar_spec *))0x0042ecb8;
CARM95_HOOK_FUNCTION(original_SetVesuvianCorpses, SetVesuvianCorpses)
int __cdecl SetVesuvianCorpses(tPowerup *pPowerup, tCar_spec *pCar) {
    LOG_TRACE("(%p, %p)", pPowerup, pCar);

    (void)pPowerup;
    (void)pCar;

    return original_SetVesuvianCorpses(pPowerup, pCar);
}

static void(__cdecl*original_ResetVesuvianCorpses)(tPowerup *, tCar_spec *) = (void(__cdecl*)(tPowerup *, tCar_spec *))0x0042ece3;
CARM95_HOOK_FUNCTION(original_ResetVesuvianCorpses, ResetVesuvianCorpses)
void __cdecl ResetVesuvianCorpses(tPowerup *pPowerup, tCar_spec *pCar) {
    LOG_TRACE("(%p, %p)", pPowerup, pCar);

    (void)pPowerup;
    (void)pCar;

    original_ResetVesuvianCorpses(pPowerup, pCar);
}

static void(__cdecl*original_ReceivedPowerup)(tNet_contents *) = (void(__cdecl*)(tNet_contents *))0x0042ecf8;
CARM95_HOOK_FUNCTION(original_ReceivedPowerup, ReceivedPowerup)
void __cdecl ReceivedPowerup(tNet_contents *pContents) {
    tPowerup *powerup;
    tCar_spec *car;
    LOG_TRACE("(%p)", pContents);

    (void)pContents;
    (void)powerup;
    (void)car;

    original_ReceivedPowerup(pContents);
}

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

    original_SendCurrentPowerups();
}

static void(__cdecl*original_LoseAllLocalPowerups)(tCar_spec *) = (void(__cdecl*)(tCar_spec *))0x0042f043;
CARM95_HOOK_FUNCTION(original_LoseAllLocalPowerups, LoseAllLocalPowerups)
void __cdecl LoseAllLocalPowerups(tCar_spec *pCar) {
    int i;
    LOG_TRACE("(%p)", pCar);

    (void)pCar;
    (void)i;

    original_LoseAllLocalPowerups(pCar);
}

