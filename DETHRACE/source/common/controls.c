#include "controls.h"

#include "harness/trace.h"

#include "carm95_hooks.h"

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

static void(__cdecl*original_AbortRace)() = (void(__cdecl*)())0x004a0c70;
CARM95_HOOK_FUNCTION(original_AbortRace, AbortRace)
void __cdecl AbortRace() {
    LOG_TRACE("()");


    original_AbortRace();
}

static void(__cdecl*original_F4Key)() = (void(__cdecl*)())0x004a0c92;
CARM95_HOOK_FUNCTION(original_F4Key, F4Key)
void __cdecl F4Key() {
    char s[256];
    tEdit_mode old_edit_mode;
    LOG_TRACE("()");

    (void)s;
    (void)old_edit_mode;

    original_F4Key();
}

static void(__cdecl*original_SetFlag)(int) = (void(__cdecl*)(int))0x004a0db7;
CARM95_HOOK_FUNCTION(original_SetFlag, SetFlag)
void __cdecl SetFlag(int i) {
    LOG_TRACE("(%d)", i);

    (void)i;

    original_SetFlag(i);
}

static void(__cdecl*original_FinishLap)(int) = (void(__cdecl*)(int))0x004a0df4;
CARM95_HOOK_FUNCTION(original_FinishLap, FinishLap)
void __cdecl FinishLap(int i) {
    LOG_TRACE("(%d)", i);

    (void)i;

    original_FinishLap(i);
}

static void(__cdecl*original_EnsureSpecialVolumesHidden)() = (void(__cdecl*)())0x004a0e04;
CARM95_HOOK_FUNCTION(original_EnsureSpecialVolumesHidden, EnsureSpecialVolumesHidden)
void __cdecl EnsureSpecialVolumesHidden() {
    LOG_TRACE("()");


    original_EnsureSpecialVolumesHidden();
}

static void(__cdecl*original_ShowSpecialVolumesIfRequ)() = (void(__cdecl*)())0x004a0e21;
CARM95_HOOK_FUNCTION(original_ShowSpecialVolumesIfRequ, ShowSpecialVolumesIfRequ)
void __cdecl ShowSpecialVolumesIfRequ() {
    LOG_TRACE("()");


    original_ShowSpecialVolumesIfRequ();
}

static void(__cdecl*original_DoEditModeKey)(int) = (void(__cdecl*)(int))0x004a0e53;
CARM95_HOOK_FUNCTION(original_DoEditModeKey, DoEditModeKey)
void __cdecl DoEditModeKey(int pIndex) {
    int modifiers;
    LOG_TRACE("(%d)", pIndex);

    (void)pIndex;
    (void)modifiers;

    original_DoEditModeKey(pIndex);
}

static void(__cdecl*original_F5Key)() = (void(__cdecl*)())0x004a0e3e;
CARM95_HOOK_FUNCTION(original_F5Key, F5Key)
void __cdecl F5Key() {
    LOG_TRACE("()");


    original_F5Key();
}

static void(__cdecl*original_F6Key)() = (void(__cdecl*)())0x004a0f3d;
CARM95_HOOK_FUNCTION(original_F6Key, F6Key)
void __cdecl F6Key() {
    LOG_TRACE("()");


    original_F6Key();
}

static void(__cdecl*original_F7Key)() = (void(__cdecl*)())0x004a0f52;
CARM95_HOOK_FUNCTION(original_F7Key, F7Key)
void __cdecl F7Key() {
    LOG_TRACE("()");


    original_F7Key();
}

static void(__cdecl*original_F8Key)() = (void(__cdecl*)())0x004a0f67;
CARM95_HOOK_FUNCTION(original_F8Key, F8Key)
void __cdecl F8Key() {
    LOG_TRACE("()");


    original_F8Key();
}

static void(__cdecl*original_F10Key)() = (void(__cdecl*)())0x004a0f7c;
CARM95_HOOK_FUNCTION(original_F10Key, F10Key)
void __cdecl F10Key() {
    LOG_TRACE("()");


    original_F10Key();
}

static void(__cdecl*original_F11Key)() = (void(__cdecl*)())0x004a0f91;
CARM95_HOOK_FUNCTION(original_F11Key, F11Key)
void __cdecl F11Key() {
    LOG_TRACE("()");


    original_F11Key();
}

static void(__cdecl*original_F12Key)() = (void(__cdecl*)())0x004a0fa6;
CARM95_HOOK_FUNCTION(original_F12Key, F12Key)
void __cdecl F12Key() {
    LOG_TRACE("()");


    original_F12Key();
}

static void(__cdecl*original_NumberKey0)() = (void(__cdecl*)())0x004a0fbb;
CARM95_HOOK_FUNCTION(original_NumberKey0, NumberKey0)
void __cdecl NumberKey0() {
    LOG_TRACE("()");


    original_NumberKey0();
}

static void(__cdecl*original_NumberKey1)() = (void(__cdecl*)())0x004a0fd0;
CARM95_HOOK_FUNCTION(original_NumberKey1, NumberKey1)
void __cdecl NumberKey1() {
    LOG_TRACE("()");


    original_NumberKey1();
}

static void(__cdecl*original_NumberKey2)() = (void(__cdecl*)())0x004a0fe5;
CARM95_HOOK_FUNCTION(original_NumberKey2, NumberKey2)
void __cdecl NumberKey2() {
    LOG_TRACE("()");


    original_NumberKey2();
}

static void(__cdecl*original_NumberKey3)() = (void(__cdecl*)())0x004a0ffa;
CARM95_HOOK_FUNCTION(original_NumberKey3, NumberKey3)
void __cdecl NumberKey3() {
    LOG_TRACE("()");


    original_NumberKey3();
}

static void(__cdecl*original_NumberKey4)() = (void(__cdecl*)())0x004a100f;
CARM95_HOOK_FUNCTION(original_NumberKey4, NumberKey4)
void __cdecl NumberKey4() {
    LOG_TRACE("()");


    original_NumberKey4();
}

static void(__cdecl*original_NumberKey5)() = (void(__cdecl*)())0x004a1024;
CARM95_HOOK_FUNCTION(original_NumberKey5, NumberKey5)
void __cdecl NumberKey5() {
    LOG_TRACE("()");


    original_NumberKey5();
}

static void(__cdecl*original_NumberKey6)() = (void(__cdecl*)())0x004a1039;
CARM95_HOOK_FUNCTION(original_NumberKey6, NumberKey6)
void __cdecl NumberKey6() {
    LOG_TRACE("()");


    original_NumberKey6();
}

static void(__cdecl*original_NumberKey7)() = (void(__cdecl*)())0x004a104e;
CARM95_HOOK_FUNCTION(original_NumberKey7, NumberKey7)
void __cdecl NumberKey7() {
    LOG_TRACE("()");


    original_NumberKey7();
}

static void(__cdecl*original_NumberKey8)() = (void(__cdecl*)())0x004a1063;
CARM95_HOOK_FUNCTION(original_NumberKey8, NumberKey8)
void __cdecl NumberKey8() {
    LOG_TRACE("()");


    original_NumberKey8();
}

static void(__cdecl*original_NumberKey9)() = (void(__cdecl*)())0x004a1078;
CARM95_HOOK_FUNCTION(original_NumberKey9, NumberKey9)
void __cdecl NumberKey9() {
    LOG_TRACE("()");


    original_NumberKey9();
}

static void(__cdecl*original_LookLeft)() = (void(__cdecl*)())0x004a108d;
CARM95_HOOK_FUNCTION(original_LookLeft, LookLeft)
void __cdecl LookLeft() {
    LOG_TRACE("()");


    original_LookLeft();
}

static void(__cdecl*original_LookForward)() = (void(__cdecl*)())0x004a113a;
CARM95_HOOK_FUNCTION(original_LookForward, LookForward)
void __cdecl LookForward() {
    LOG_TRACE("()");


    original_LookForward();
}

static void(__cdecl*original_LookRight)() = (void(__cdecl*)())0x004a11b2;
CARM95_HOOK_FUNCTION(original_LookRight, LookRight)
void __cdecl LookRight() {
    LOG_TRACE("()");


    original_LookRight();
}

static void(__cdecl*original_DamageTest)() = (void(__cdecl*)())0x004a125f;
CARM95_HOOK_FUNCTION(original_DamageTest, DamageTest)
void __cdecl DamageTest() {
    LOG_TRACE("()");


    original_DamageTest();
}

static void(__cdecl*original_TDamageEngine)() = (void(__cdecl*)())0x004a126a;
CARM95_HOOK_FUNCTION(original_TDamageEngine, TDamageEngine)
void __cdecl TDamageEngine() {
    LOG_TRACE("()");


    original_TDamageEngine();
}

static void(__cdecl*original_TDamageDriver)() = (void(__cdecl*)())0x004a127f;
CARM95_HOOK_FUNCTION(original_TDamageDriver, TDamageDriver)
void __cdecl TDamageDriver() {
    LOG_TRACE("()");


    original_TDamageDriver();
}

static void(__cdecl*original_TDamageTrans)() = (void(__cdecl*)())0x004a12d4;
CARM95_HOOK_FUNCTION(original_TDamageTrans, TDamageTrans)
void __cdecl TDamageTrans() {
    LOG_TRACE("()");


    original_TDamageTrans();
}

static void(__cdecl*original_TDamageSteering)() = (void(__cdecl*)())0x004a12e9;
CARM95_HOOK_FUNCTION(original_TDamageSteering, TDamageSteering)
void __cdecl TDamageSteering() {
    LOG_TRACE("()");


    original_TDamageSteering();
}

static void(__cdecl*original_TDamageLFWheel)() = (void(__cdecl*)())0x004a12fe;
CARM95_HOOK_FUNCTION(original_TDamageLFWheel, TDamageLFWheel)
void __cdecl TDamageLFWheel() {
    LOG_TRACE("()");


    original_TDamageLFWheel();
}

static void(__cdecl*original_TDamageLFBrake)() = (void(__cdecl*)())0x004a1313;
CARM95_HOOK_FUNCTION(original_TDamageLFBrake, TDamageLFBrake)
void __cdecl TDamageLFBrake() {
    LOG_TRACE("()");


    original_TDamageLFBrake();
}

static void(__cdecl*original_TDamageLRBrake)() = (void(__cdecl*)())0x004a1328;
CARM95_HOOK_FUNCTION(original_TDamageLRBrake, TDamageLRBrake)
void __cdecl TDamageLRBrake() {
    LOG_TRACE("()");


    original_TDamageLRBrake();
}

static void(__cdecl*original_TDamageLRWheel)() = (void(__cdecl*)())0x004a133d;
CARM95_HOOK_FUNCTION(original_TDamageLRWheel, TDamageLRWheel)
void __cdecl TDamageLRWheel() {
    LOG_TRACE("()");


    original_TDamageLRWheel();
}

static void(__cdecl*original_TDamageRFWheel)() = (void(__cdecl*)())0x004a1352;
CARM95_HOOK_FUNCTION(original_TDamageRFWheel, TDamageRFWheel)
void __cdecl TDamageRFWheel() {
    LOG_TRACE("()");


    original_TDamageRFWheel();
}

static void(__cdecl*original_TDamageRFBrake)() = (void(__cdecl*)())0x004a1367;
CARM95_HOOK_FUNCTION(original_TDamageRFBrake, TDamageRFBrake)
void __cdecl TDamageRFBrake() {
    LOG_TRACE("()");


    original_TDamageRFBrake();
}

static void(__cdecl*original_TDamageRRBrake)() = (void(__cdecl*)())0x004a137c;
CARM95_HOOK_FUNCTION(original_TDamageRRBrake, TDamageRRBrake)
void __cdecl TDamageRRBrake() {
    LOG_TRACE("()");


    original_TDamageRRBrake();
}

static void(__cdecl*original_TDamageRRWheel)() = (void(__cdecl*)())0x004a1391;
CARM95_HOOK_FUNCTION(original_TDamageRRWheel, TDamageRRWheel)
void __cdecl TDamageRRWheel() {
    LOG_TRACE("()");


    original_TDamageRRWheel();
}

static void(__cdecl*original_MoveBonnetForward)() = (void(__cdecl*)())0x004a13a6;
CARM95_HOOK_FUNCTION(original_MoveBonnetForward, MoveBonnetForward)
void __cdecl MoveBonnetForward() {
    LOG_TRACE("()");


    original_MoveBonnetForward();
}

static void(__cdecl*original_SaveBonnet)() = (void(__cdecl*)())0x004a13dd;
CARM95_HOOK_FUNCTION(original_SaveBonnet, SaveBonnet)
void __cdecl SaveBonnet() {
    br_actor *bonny;
    tPath_name the_path;
    LOG_TRACE("()");

    (void)bonny;
    (void)the_path;

    original_SaveBonnet();
}

static void(__cdecl*original_MoveBonnetBackward)() = (void(__cdecl*)())0x004a142f;
CARM95_HOOK_FUNCTION(original_MoveBonnetBackward, MoveBonnetBackward)
void __cdecl MoveBonnetBackward() {
    LOG_TRACE("()");


    original_MoveBonnetBackward();
}

static void(__cdecl*original_MoveBonnetLeft)() = (void(__cdecl*)())0x004a1466;
CARM95_HOOK_FUNCTION(original_MoveBonnetLeft, MoveBonnetLeft)
void __cdecl MoveBonnetLeft() {
    LOG_TRACE("()");


    original_MoveBonnetLeft();
}

static void(__cdecl*original_ShrinkBonnetX)() = (void(__cdecl*)())0x004a149d;
CARM95_HOOK_FUNCTION(original_ShrinkBonnetX, ShrinkBonnetX)
void __cdecl ShrinkBonnetX() {
    LOG_TRACE("()");


    original_ShrinkBonnetX();
}

static void(__cdecl*original_SwellBonnetX)() = (void(__cdecl*)())0x004a14d4;
CARM95_HOOK_FUNCTION(original_SwellBonnetX, SwellBonnetX)
void __cdecl SwellBonnetX() {
    LOG_TRACE("()");


    original_SwellBonnetX();
}

static void(__cdecl*original_ShrinkBonnetY)() = (void(__cdecl*)())0x004a150b;
CARM95_HOOK_FUNCTION(original_ShrinkBonnetY, ShrinkBonnetY)
void __cdecl ShrinkBonnetY() {
    LOG_TRACE("()");


    original_ShrinkBonnetY();
}

static void(__cdecl*original_SwellBonnetY)() = (void(__cdecl*)())0x004a1542;
CARM95_HOOK_FUNCTION(original_SwellBonnetY, SwellBonnetY)
void __cdecl SwellBonnetY() {
    LOG_TRACE("()");


    original_SwellBonnetY();
}

static void(__cdecl*original_ShrinkBonnetZ)() = (void(__cdecl*)())0x004a1579;
CARM95_HOOK_FUNCTION(original_ShrinkBonnetZ, ShrinkBonnetZ)
void __cdecl ShrinkBonnetZ() {
    LOG_TRACE("()");


    original_ShrinkBonnetZ();
}

static void(__cdecl*original_SwellBonnetZ)() = (void(__cdecl*)())0x004a15b0;
CARM95_HOOK_FUNCTION(original_SwellBonnetZ, SwellBonnetZ)
void __cdecl SwellBonnetZ() {
    LOG_TRACE("()");


    original_SwellBonnetZ();
}

static void(__cdecl*original_MoveBonnetDown)() = (void(__cdecl*)())0x004a15e7;
CARM95_HOOK_FUNCTION(original_MoveBonnetDown, MoveBonnetDown)
void __cdecl MoveBonnetDown() {
    LOG_TRACE("()");


    original_MoveBonnetDown();
}

static void(__cdecl*original_MoveBonnetRight)() = (void(__cdecl*)())0x004a161e;
CARM95_HOOK_FUNCTION(original_MoveBonnetRight, MoveBonnetRight)
void __cdecl MoveBonnetRight() {
    LOG_TRACE("()");


    original_MoveBonnetRight();
}

static void(__cdecl*original_MoveBonnetUp)() = (void(__cdecl*)())0x004a1655;
CARM95_HOOK_FUNCTION(original_MoveBonnetUp, MoveBonnetUp)
void __cdecl MoveBonnetUp() {
    LOG_TRACE("()");


    original_MoveBonnetUp();
}

static void(__cdecl*original_TiltBonnetDownX)() = (void(__cdecl*)())0x004a168c;
CARM95_HOOK_FUNCTION(original_TiltBonnetDownX, TiltBonnetDownX)
void __cdecl TiltBonnetDownX() {
    LOG_TRACE("()");


    original_TiltBonnetDownX();
}

static void(__cdecl*original_TiltBonnetUpX)() = (void(__cdecl*)())0x004a16b5;
CARM95_HOOK_FUNCTION(original_TiltBonnetUpX, TiltBonnetUpX)
void __cdecl TiltBonnetUpX() {
    LOG_TRACE("()");


    original_TiltBonnetUpX();
}

static void(__cdecl*original_TiltBonnetDownY)() = (void(__cdecl*)())0x004a16e1;
CARM95_HOOK_FUNCTION(original_TiltBonnetDownY, TiltBonnetDownY)
void __cdecl TiltBonnetDownY() {
    LOG_TRACE("()");


    original_TiltBonnetDownY();
}

static void(__cdecl*original_TiltBonnetUpY)() = (void(__cdecl*)())0x004a170a;
CARM95_HOOK_FUNCTION(original_TiltBonnetUpY, TiltBonnetUpY)
void __cdecl TiltBonnetUpY() {
    LOG_TRACE("()");


    original_TiltBonnetUpY();
}

static void(__cdecl*original_TiltBonnetDownZ)() = (void(__cdecl*)())0x004a1736;
CARM95_HOOK_FUNCTION(original_TiltBonnetDownZ, TiltBonnetDownZ)
void __cdecl TiltBonnetDownZ() {
    LOG_TRACE("()");


    original_TiltBonnetDownZ();
}

static void(__cdecl*original_TiltBonnetUpZ)() = (void(__cdecl*)())0x004a175f;
CARM95_HOOK_FUNCTION(original_TiltBonnetUpZ, TiltBonnetUpZ)
void __cdecl TiltBonnetUpZ() {
    LOG_TRACE("()");


    original_TiltBonnetUpZ();
}

static void(__cdecl*original_ToggleCockpit)() = (void(__cdecl*)())0x004a178b;
CARM95_HOOK_FUNCTION(original_ToggleCockpit, ToggleCockpit)
void __cdecl ToggleCockpit() {
    br_scalar ts;
    LOG_TRACE("()");

    (void)ts;

    original_ToggleCockpit();
}

static void(__cdecl*original_ToggleMirror)() = (void(__cdecl*)())0x004a1895;
CARM95_HOOK_FUNCTION(original_ToggleMirror, ToggleMirror)
void __cdecl ToggleMirror() {
    LOG_TRACE("()");


    original_ToggleMirror();
}

static void(__cdecl*original_ConcussMe)() = (void(__cdecl*)())0x004a1919;
CARM95_HOOK_FUNCTION(original_ConcussMe, ConcussMe)
void __cdecl ConcussMe() {
    LOG_TRACE("()");


    original_ConcussMe();
}

static void(__cdecl*original_CheckHelp)() = (void(__cdecl*)())0x004a29aa;
CARM95_HOOK_FUNCTION(original_CheckHelp, CheckHelp)
void __cdecl CheckHelp() {
    LOG_TRACE("()");


    original_CheckHelp();
}

static void(__cdecl*original_CheckLoadSave)() = (void(__cdecl*)())0x004a29b5;
CARM95_HOOK_FUNCTION(original_CheckLoadSave, CheckLoadSave)
void __cdecl CheckLoadSave() {
    int save_load_allowed;
    int switched_res;
    LOG_TRACE("()");

    (void)save_load_allowed;
    (void)switched_res;

    original_CheckLoadSave();
}

static void(__cdecl*original_CheckToggles)(int) = (void(__cdecl*)(int))0x004a198a;
CARM95_HOOK_FUNCTION(original_CheckToggles, CheckToggles)
void __cdecl CheckToggles(int pRacing) {
    int i;
    int new_state;
    LOG_TRACE("(%d)", pRacing);

    (void)pRacing;
    (void)i;
    (void)new_state;

    original_CheckToggles(pRacing);
}

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

    return original_CarWorldOffFallenCheckThingy(pCar, pCheck_around);
}

static int(__cdecl*original_HasCarFallenOffWorld)(tCar_spec *) = (int(__cdecl*)(tCar_spec *))0x004a1b2f;
CARM95_HOOK_FUNCTION(original_HasCarFallenOffWorld, HasCarFallenOffWorld)
int __cdecl HasCarFallenOffWorld(tCar_spec *pCar) {
    LOG_TRACE("(%p)", pCar);

    (void)pCar;

    return original_HasCarFallenOffWorld(pCar);
}

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

    original_CheckForBeingOutOfThisWorld();
}

static void(__cdecl*original_CheckHornLocal)(tCar_spec *) = (void(__cdecl*)(tCar_spec *))0x004a34a8;
CARM95_HOOK_FUNCTION(original_CheckHornLocal, CheckHornLocal)
void __cdecl CheckHornLocal(tCar_spec *pCar) {
    LOG_TRACE("(%p)", pCar);

    (void)pCar;

    original_CheckHornLocal(pCar);
}

static void(__cdecl*original_CheckHorn3D)(tCar_spec *) = (void(__cdecl*)(tCar_spec *))0x004a3582;
CARM95_HOOK_FUNCTION(original_CheckHorn3D, CheckHorn3D)
void __cdecl CheckHorn3D(tCar_spec *pCar) {
    LOG_TRACE("(%p)", pCar);

    (void)pCar;

    original_CheckHorn3D(pCar);
}

static void(__cdecl*original_CheckHorns)() = (void(__cdecl*)())0x004a343d;
CARM95_HOOK_FUNCTION(original_CheckHorns, CheckHorns)
void __cdecl CheckHorns() {
    int i;
    LOG_TRACE("()");

    (void)i;

    original_CheckHorns();
}

static void(__cdecl*original_SetRecovery)() = (void(__cdecl*)())0x004a1d13;
CARM95_HOOK_FUNCTION(original_SetRecovery, SetRecovery)
void __cdecl SetRecovery() {
    LOG_TRACE("()");


    original_SetRecovery();
}

static void(__cdecl*original_RecoverCar)() = (void(__cdecl*)())0x004a20b0;
CARM95_HOOK_FUNCTION(original_RecoverCar, RecoverCar)
void __cdecl RecoverCar() {
    LOG_TRACE("()");


    original_RecoverCar();
}

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

    original_CheckMapRenderMove();
}

static void(__cdecl*original_ExplodeCar)(tCar_spec *) = (void(__cdecl*)(tCar_spec *))0x004a20e9;
CARM95_HOOK_FUNCTION(original_ExplodeCar, ExplodeCar)
void __cdecl ExplodeCar(tCar_spec *pCar) {
    br_vector3 tv;
    br_vector3 pos;
    LOG_TRACE("(%p)", pCar);

    (void)pCar;
    (void)tv;
    (void)pos;

    original_ExplodeCar(pCar);
}

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

    original_CheckRecoveryOfCars(pEndFrameTime);
}

static void(__cdecl*original_LoseSomePSPowerups)(int) = (void(__cdecl*)(int))0x004a39cc;
CARM95_HOOK_FUNCTION(original_LoseSomePSPowerups, LoseSomePSPowerups)
void __cdecl LoseSomePSPowerups(int pNumber) {
    int index;
    LOG_TRACE("(%d)", pNumber);

    (void)pNumber;
    (void)index;

    original_LoseSomePSPowerups(pNumber);
}

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

    original_CheckOtherRacingKeys();
}

static int(__cdecl*original_CheckRecoverCost)() = (int(__cdecl*)())0x004a2208;
CARM95_HOOK_FUNCTION(original_CheckRecoverCost, CheckRecoverCost)
int __cdecl CheckRecoverCost() {
    LOG_TRACE("()");


    return original_CheckRecoverCost();
}

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

    original_SortOutRecover(pCar);
}

static void(__cdecl*original_SetFlipUpCar)(tCar_spec *) = (void(__cdecl*)(tCar_spec *))0x004a22f4;
CARM95_HOOK_FUNCTION(original_SetFlipUpCar, SetFlipUpCar)
void __cdecl SetFlipUpCar(tCar_spec *pCar) {
    LOG_TRACE("(%p)", pCar);

    (void)pCar;

    original_SetFlipUpCar(pCar);
}

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

    original_FlipUpCar(car);
}

static void(__cdecl*original_GetPowerup)(int) = (void(__cdecl*)(int))0x004a291d;
CARM95_HOOK_FUNCTION(original_GetPowerup, GetPowerup)
void __cdecl GetPowerup(int pNum) {
    LOG_TRACE("(%d)", pNum);

    (void)pNum;

    original_GetPowerup(pNum);
}

static void(__cdecl*original_CheckSystemKeys)(int) = (void(__cdecl*)(int))0x004a293f;
CARM95_HOOK_FUNCTION(original_CheckSystemKeys, CheckSystemKeys)
void __cdecl CheckSystemKeys(int pRacing) {
    tU32 start_menu_time;
    int i;
    LOG_TRACE("(%d)", pRacing);

    (void)pRacing;
    (void)start_menu_time;
    (void)i;

    original_CheckSystemKeys(pRacing);
}

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

    original_CheckKevKeys();
}

static void(__cdecl*original_BrakeInstantly)() = (void(__cdecl*)())0x004a4159;
CARM95_HOOK_FUNCTION(original_BrakeInstantly, BrakeInstantly)
void __cdecl BrakeInstantly() {
    int i;
    LOG_TRACE("()");

    (void)i;

    original_BrakeInstantly();
}

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

    original_PollCarControls(pTime_difference);
}

static void(__cdecl*original_PollCameraControls)(tU32) = (void(__cdecl*)(tU32))0x004a4214;
CARM95_HOOK_FUNCTION(original_PollCameraControls, PollCameraControls)
void __cdecl PollCameraControls(tU32 pTime_difference) {
    int flag;
    int left;
    int right;
    int swirl_mode;
    int up_and_down_mode;
    int going_up;
    static int last_swirl_mode;
    LOG_TRACE("(%u)", pTime_difference);

    (void)pTime_difference;
    (void)flag;
    (void)left;
    (void)right;
    (void)swirl_mode;
    (void)up_and_down_mode;
    (void)going_up;
    (void)last_swirl_mode;

    original_PollCameraControls(pTime_difference);
}

static void(__cdecl*original_SetFlag2)(int) = (void(__cdecl*)(int))0x004a45e8;
CARM95_HOOK_FUNCTION(original_SetFlag2, SetFlag2)
void __cdecl SetFlag2(int i) {
    LOG_TRACE("(%d)", i);

    (void)i;

    original_SetFlag2(i);
}

static void(__cdecl*original_ToggleFlying)() = (void(__cdecl*)())0x004a460c;
CARM95_HOOK_FUNCTION(original_ToggleFlying, ToggleFlying)
void __cdecl ToggleFlying() {
    LOG_TRACE("()");


    original_ToggleFlying();
}

static void(__cdecl*original_ToggleInvulnerability)() = (void(__cdecl*)())0x004a46a8;
CARM95_HOOK_FUNCTION(original_ToggleInvulnerability, ToggleInvulnerability)
void __cdecl ToggleInvulnerability() {
    LOG_TRACE("()");


    original_ToggleInvulnerability();
}

static void(__cdecl*original_MoreTime)() = (void(__cdecl*)())0x004a4721;
CARM95_HOOK_FUNCTION(original_MoreTime, MoreTime)
void __cdecl MoreTime() {
    LOG_TRACE("()");


    original_MoreTime();
}

static void(__cdecl*original_MuchMoreTime)() = (void(__cdecl*)())0x004a4736;
CARM95_HOOK_FUNCTION(original_MuchMoreTime, MuchMoreTime)
void __cdecl MuchMoreTime() {
    LOG_TRACE("()");


    original_MuchMoreTime();
}

static void(__cdecl*original_ToggleTimerFreeze)() = (void(__cdecl*)())0x004a474e;
CARM95_HOOK_FUNCTION(original_ToggleTimerFreeze, ToggleTimerFreeze)
void __cdecl ToggleTimerFreeze() {
    LOG_TRACE("()");


    original_ToggleTimerFreeze();
}

static void(__cdecl*original_EarnDosh)() = (void(__cdecl*)())0x004a47c7;
CARM95_HOOK_FUNCTION(original_EarnDosh, EarnDosh)
void __cdecl EarnDosh() {
    LOG_TRACE("()");


    original_EarnDosh();
}

static void(__cdecl*original_LoseDosh)() = (void(__cdecl*)())0x004a47df;
CARM95_HOOK_FUNCTION(original_LoseDosh, LoseDosh)
void __cdecl LoseDosh() {
    LOG_TRACE("()");


    original_LoseDosh();
}

static void(__cdecl*original_ToggleMap)() = (void(__cdecl*)())0x004a47f7;
CARM95_HOOK_FUNCTION(original_ToggleMap, ToggleMap)
void __cdecl ToggleMap() {
    static int old_indent;
    static int was_in_cockpit;
    LOG_TRACE("()");

    (void)old_indent;
    (void)was_in_cockpit;

    original_ToggleMap();
}

static int(__cdecl*original_HornBlowing)() = (int(__cdecl*)())0x004a492c;
CARM95_HOOK_FUNCTION(original_HornBlowing, HornBlowing)
int __cdecl HornBlowing() {
    LOG_TRACE("()");


    return original_HornBlowing();
}

static void(__cdecl*original_ToggleArrow)() = (void(__cdecl*)())0x004a4947;
CARM95_HOOK_FUNCTION(original_ToggleArrow, ToggleArrow)
void __cdecl ToggleArrow() {
    static br_actor *old_actor;
    LOG_TRACE("()");

    (void)old_actor;

    original_ToggleArrow();
}

static int(__cdecl*original_GetRecoverVoucherCount)() = (int(__cdecl*)())0x004a4a23;
CARM95_HOOK_FUNCTION(original_GetRecoverVoucherCount, GetRecoverVoucherCount)
int __cdecl GetRecoverVoucherCount() {
    LOG_TRACE("()");


    return original_GetRecoverVoucherCount();
}

static void(__cdecl*original_AddVouchers)(int) = (void(__cdecl*)(int))0x004a4a38;
CARM95_HOOK_FUNCTION(original_AddVouchers, AddVouchers)
void __cdecl AddVouchers(int pCount) {
    LOG_TRACE("(%d)", pCount);

    (void)pCount;

    original_AddVouchers(pCount);
}

static void(__cdecl*original_ResetRecoveryVouchers)() = (void(__cdecl*)())0x004a4a4c;
CARM95_HOOK_FUNCTION(original_ResetRecoveryVouchers, ResetRecoveryVouchers)
void __cdecl ResetRecoveryVouchers() {
    LOG_TRACE("()");


    original_ResetRecoveryVouchers();
}

static void(__cdecl*original_CycleCarTexturingLevel)() = (void(__cdecl*)())0x004a4a61;
CARM95_HOOK_FUNCTION(original_CycleCarTexturingLevel, CycleCarTexturingLevel)
void __cdecl CycleCarTexturingLevel() {
    tCar_texturing_level new_level;
    LOG_TRACE("()");

    (void)new_level;

    original_CycleCarTexturingLevel();
}

static void(__cdecl*original_CycleWallTexturingLevel)() = (void(__cdecl*)())0x004a4b28;
CARM95_HOOK_FUNCTION(original_CycleWallTexturingLevel, CycleWallTexturingLevel)
void __cdecl CycleWallTexturingLevel() {
    tWall_texturing_level new_level;
    LOG_TRACE("()");

    (void)new_level;

    original_CycleWallTexturingLevel();
}

static void(__cdecl*original_CycleRoadTexturingLevel)() = (void(__cdecl*)())0x004a4bfb;
CARM95_HOOK_FUNCTION(original_CycleRoadTexturingLevel, CycleRoadTexturingLevel)
void __cdecl CycleRoadTexturingLevel() {
    tRoad_texturing_level new_level;
    LOG_TRACE("()");

    (void)new_level;

    original_CycleRoadTexturingLevel();
}

static void(__cdecl*original_CycleYonFactor)() = (void(__cdecl*)())0x004a4ca1;
CARM95_HOOK_FUNCTION(original_CycleYonFactor, CycleYonFactor)
void __cdecl CycleYonFactor() {
    br_scalar new_factor;
    char factor_str[5];
    LOG_TRACE("()");

    (void)new_factor;
    (void)factor_str;

    original_CycleYonFactor();
}

static void(__cdecl*original_SetSoundDetailLevel)(int) = (void(__cdecl*)(int))0x004a4da4;
CARM95_HOOK_FUNCTION(original_SetSoundDetailLevel, SetSoundDetailLevel)
void __cdecl SetSoundDetailLevel(int pLevel) {
    LOG_TRACE("(%d)", pLevel);

    (void)pLevel;

    original_SetSoundDetailLevel(pLevel);
}

static void(__cdecl*original_ReallySetSoundDetailLevel)(int) = (void(__cdecl*)(int))0x004a4db7;
CARM95_HOOK_FUNCTION(original_ReallySetSoundDetailLevel, ReallySetSoundDetailLevel)
void __cdecl ReallySetSoundDetailLevel(int pLevel) {
    LOG_TRACE("(%d)", pLevel);

    (void)pLevel;

    original_ReallySetSoundDetailLevel(pLevel);
}

static int(__cdecl*original_GetSoundDetailLevel)() = (int(__cdecl*)())0x004a4dde;
CARM95_HOOK_FUNCTION(original_GetSoundDetailLevel, GetSoundDetailLevel)
int __cdecl GetSoundDetailLevel() {
    LOG_TRACE("()");


    return original_GetSoundDetailLevel();
}

static void(__cdecl*original_CycleSoundDetailLevel)() = (void(__cdecl*)())0x004a4df3;
CARM95_HOOK_FUNCTION(original_CycleSoundDetailLevel, CycleSoundDetailLevel)
void __cdecl CycleSoundDetailLevel() {
    int new_level;
    LOG_TRACE("()");

    (void)new_level;

    original_CycleSoundDetailLevel();
}

static void(__cdecl*original_CycleCarSimplificationLevel)() = (void(__cdecl*)())0x004a4ec8;
CARM95_HOOK_FUNCTION(original_CycleCarSimplificationLevel, CycleCarSimplificationLevel)
void __cdecl CycleCarSimplificationLevel() {
    char *src;
    char *dst;
    LOG_TRACE("()");

    (void)src;
    (void)dst;

    original_CycleCarSimplificationLevel();
}

static void(__cdecl*original_ToggleAccessoryRendering)() = (void(__cdecl*)())0x004a4f58;
CARM95_HOOK_FUNCTION(original_ToggleAccessoryRendering, ToggleAccessoryRendering)
void __cdecl ToggleAccessoryRendering() {
    int on;
    LOG_TRACE("()");

    (void)on;

    original_ToggleAccessoryRendering();
}

static void(__cdecl*original_ToggleSmoke)() = (void(__cdecl*)())0x004a500d;
CARM95_HOOK_FUNCTION(original_ToggleSmoke, ToggleSmoke)
void __cdecl ToggleSmoke() {
    int on;
    LOG_TRACE("()");

    (void)on;

    original_ToggleSmoke();
}

void DrawSomeText2(tDR_font *pFont) {
    int y;
    int i;
    char *txt[15];
    LOG_TRACE("(%p)", pFont);

    (void)pFont;
    (void)y;
    (void)i;
    (void)txt;

    NOT_IMPLEMENTED();
}

static void(__cdecl*original_DrawSomeText)() = (void(__cdecl*)())0x00485d80;
CARM95_HOOK_FUNCTION(original_DrawSomeText, DrawSomeText)
void __cdecl DrawSomeText() {
    LOG_TRACE("()");


    original_DrawSomeText();
}

void SaySorryYouLittleBastard() {
    LOG_TRACE("()");


    NOT_IMPLEMENTED();
}

static void(__cdecl*original_UserSendMessage)() = (void(__cdecl*)())0x004a509e;
CARM95_HOOK_FUNCTION(original_UserSendMessage, UserSendMessage)
void __cdecl UserSendMessage() {
    LOG_TRACE("()");


    original_UserSendMessage();
}

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

    original_EnterUserMessage();
}

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

    original_DisplayUserMessage();
}

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

    original_InitAbuseomatic();
}

static void(__cdecl*original_DisposeAbuseomatic)() = (void(__cdecl*)())0x004a5868;
CARM95_HOOK_FUNCTION(original_DisposeAbuseomatic, DisposeAbuseomatic)
void __cdecl DisposeAbuseomatic() {
    int i;
    LOG_TRACE("()");

    (void)i;

    original_DisposeAbuseomatic();
}

