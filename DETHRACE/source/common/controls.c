#include "controls.h"

#include "harness/trace.h"

#include "carm95_hooks.h"

#include <stdio.h>
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

static void(*original_AbortRace)() = (void(*)())0x004a0c70;
CARM95_HOOK_FUNCTION(original_AbortRace, AbortRace)
void AbortRace() {
    LOG_TRACE("()");


    original_AbortRace();
}

static void(*original_F4Key)() = (void(*)())0x004a0c92;
CARM95_HOOK_FUNCTION(original_F4Key, F4Key)
void F4Key() {
    char s[256];
    tEdit_mode old_edit_mode;
    LOG_TRACE("()");

    (void)s;
    (void)old_edit_mode;

    original_F4Key();
}

static void(*original_SetFlag)(int, ...) = (void(*)(int, ...))0x004a0db7;
CARM95_HOOK_FUNCTION(original_SetFlag, SetFlag)
void SetFlag(int i) {
    LOG_TRACE("(%d)", i);

    (void)i;

    original_SetFlag(i);
}

static void(*original_FinishLap)(int, ...) = (void(*)(int, ...))0x004a0df4;
CARM95_HOOK_FUNCTION(original_FinishLap, FinishLap)
void FinishLap(int i) {
    LOG_TRACE("(%d)", i);

    (void)i;

    original_FinishLap(i);
}

static void(*original_EnsureSpecialVolumesHidden)() = (void(*)())0x004a0e04;
CARM95_HOOK_FUNCTION(original_EnsureSpecialVolumesHidden, EnsureSpecialVolumesHidden)
void EnsureSpecialVolumesHidden() {
    LOG_TRACE("()");


    original_EnsureSpecialVolumesHidden();
}

static void(*original_ShowSpecialVolumesIfRequ)() = (void(*)())0x004a0e21;
CARM95_HOOK_FUNCTION(original_ShowSpecialVolumesIfRequ, ShowSpecialVolumesIfRequ)
void ShowSpecialVolumesIfRequ() {
    LOG_TRACE("()");


    original_ShowSpecialVolumesIfRequ();
}

static void(*original_DoEditModeKey)(int, ...) = (void(*)(int, ...))0x004a0e53;
CARM95_HOOK_FUNCTION(original_DoEditModeKey, DoEditModeKey)
void DoEditModeKey(int pIndex) {
    int modifiers;
    LOG_TRACE("(%d)", pIndex);

    (void)pIndex;
    (void)modifiers;

    original_DoEditModeKey(pIndex);
}

static void(*original_F5Key)() = (void(*)())0x004a0e3e;
CARM95_HOOK_FUNCTION(original_F5Key, F5Key)
void F5Key() {
    LOG_TRACE("()");


    original_F5Key();
}

static void(*original_F6Key)() = (void(*)())0x004a0f3d;
CARM95_HOOK_FUNCTION(original_F6Key, F6Key)
void F6Key() {
    LOG_TRACE("()");


    original_F6Key();
}

static void(*original_F7Key)() = (void(*)())0x004a0f52;
CARM95_HOOK_FUNCTION(original_F7Key, F7Key)
void F7Key() {
    LOG_TRACE("()");


    original_F7Key();
}

static void(*original_F8Key)() = (void(*)())0x004a0f67;
CARM95_HOOK_FUNCTION(original_F8Key, F8Key)
void F8Key() {
    LOG_TRACE("()");


    original_F8Key();
}

static void(*original_F10Key)() = (void(*)())0x004a0f7c;
CARM95_HOOK_FUNCTION(original_F10Key, F10Key)
void F10Key() {
    LOG_TRACE("()");


    original_F10Key();
}

static void(*original_F11Key)() = (void(*)())0x004a0f91;
CARM95_HOOK_FUNCTION(original_F11Key, F11Key)
void F11Key() {
    LOG_TRACE("()");


    original_F11Key();
}

static void(*original_F12Key)() = (void(*)())0x004a0fa6;
CARM95_HOOK_FUNCTION(original_F12Key, F12Key)
void F12Key() {
    LOG_TRACE("()");


    original_F12Key();
}

static void(*original_NumberKey0)() = (void(*)())0x004a0fbb;
CARM95_HOOK_FUNCTION(original_NumberKey0, NumberKey0)
void NumberKey0() {
    LOG_TRACE("()");


    original_NumberKey0();
}

static void(*original_NumberKey1)() = (void(*)())0x004a0fd0;
CARM95_HOOK_FUNCTION(original_NumberKey1, NumberKey1)
void NumberKey1() {
    LOG_TRACE("()");


    original_NumberKey1();
}

static void(*original_NumberKey2)() = (void(*)())0x004a0fe5;
CARM95_HOOK_FUNCTION(original_NumberKey2, NumberKey2)
void NumberKey2() {
    LOG_TRACE("()");


    original_NumberKey2();
}

static void(*original_NumberKey3)() = (void(*)())0x004a0ffa;
CARM95_HOOK_FUNCTION(original_NumberKey3, NumberKey3)
void NumberKey3() {
    LOG_TRACE("()");


    original_NumberKey3();
}

static void(*original_NumberKey4)() = (void(*)())0x004a100f;
CARM95_HOOK_FUNCTION(original_NumberKey4, NumberKey4)
void NumberKey4() {
    LOG_TRACE("()");


    original_NumberKey4();
}

static void(*original_NumberKey5)() = (void(*)())0x004a1024;
CARM95_HOOK_FUNCTION(original_NumberKey5, NumberKey5)
void NumberKey5() {
    LOG_TRACE("()");


    original_NumberKey5();
}

static void(*original_NumberKey6)() = (void(*)())0x004a1039;
CARM95_HOOK_FUNCTION(original_NumberKey6, NumberKey6)
void NumberKey6() {
    LOG_TRACE("()");


    original_NumberKey6();
}

static void(*original_NumberKey7)() = (void(*)())0x004a104e;
CARM95_HOOK_FUNCTION(original_NumberKey7, NumberKey7)
void NumberKey7() {
    LOG_TRACE("()");


    original_NumberKey7();
}

static void(*original_NumberKey8)() = (void(*)())0x004a1063;
CARM95_HOOK_FUNCTION(original_NumberKey8, NumberKey8)
void NumberKey8() {
    LOG_TRACE("()");


    original_NumberKey8();
}

static void(*original_NumberKey9)() = (void(*)())0x004a1078;
CARM95_HOOK_FUNCTION(original_NumberKey9, NumberKey9)
void NumberKey9() {
    LOG_TRACE("()");


    original_NumberKey9();
}

static void(*original_LookLeft)() = (void(*)())0x004a108d;
CARM95_HOOK_FUNCTION(original_LookLeft, LookLeft)
void LookLeft() {
    LOG_TRACE("()");


    original_LookLeft();
}

static void(*original_LookForward)() = (void(*)())0x004a113a;
CARM95_HOOK_FUNCTION(original_LookForward, LookForward)
void LookForward() {
    LOG_TRACE("()");


    original_LookForward();
}

static void(*original_LookRight)() = (void(*)())0x004a11b2;
CARM95_HOOK_FUNCTION(original_LookRight, LookRight)
void LookRight() {
    LOG_TRACE("()");


    original_LookRight();
}

static void(*original_DamageTest)() = (void(*)())0x004a125f;
CARM95_HOOK_FUNCTION(original_DamageTest, DamageTest)
void DamageTest() {
    LOG_TRACE("()");


    original_DamageTest();
}

static void(*original_TDamageEngine)() = (void(*)())0x004a126a;
CARM95_HOOK_FUNCTION(original_TDamageEngine, TDamageEngine)
void TDamageEngine() {
    LOG_TRACE("()");


    original_TDamageEngine();
}

static void(*original_TDamageDriver)() = (void(*)())0x004a127f;
CARM95_HOOK_FUNCTION(original_TDamageDriver, TDamageDriver)
void TDamageDriver() {
    LOG_TRACE("()");


    original_TDamageDriver();
}

static void(*original_TDamageTrans)() = (void(*)())0x004a12d4;
CARM95_HOOK_FUNCTION(original_TDamageTrans, TDamageTrans)
void TDamageTrans() {
    LOG_TRACE("()");


    original_TDamageTrans();
}

static void(*original_TDamageSteering)() = (void(*)())0x004a12e9;
CARM95_HOOK_FUNCTION(original_TDamageSteering, TDamageSteering)
void TDamageSteering() {
    LOG_TRACE("()");


    original_TDamageSteering();
}

static void(*original_TDamageLFWheel)() = (void(*)())0x004a12fe;
CARM95_HOOK_FUNCTION(original_TDamageLFWheel, TDamageLFWheel)
void TDamageLFWheel() {
    LOG_TRACE("()");


    original_TDamageLFWheel();
}

static void(*original_TDamageLFBrake)() = (void(*)())0x004a1313;
CARM95_HOOK_FUNCTION(original_TDamageLFBrake, TDamageLFBrake)
void TDamageLFBrake() {
    LOG_TRACE("()");


    original_TDamageLFBrake();
}

static void(*original_TDamageLRBrake)() = (void(*)())0x004a1328;
CARM95_HOOK_FUNCTION(original_TDamageLRBrake, TDamageLRBrake)
void TDamageLRBrake() {
    LOG_TRACE("()");


    original_TDamageLRBrake();
}

static void(*original_TDamageLRWheel)() = (void(*)())0x004a133d;
CARM95_HOOK_FUNCTION(original_TDamageLRWheel, TDamageLRWheel)
void TDamageLRWheel() {
    LOG_TRACE("()");


    original_TDamageLRWheel();
}

static void(*original_TDamageRFWheel)() = (void(*)())0x004a1352;
CARM95_HOOK_FUNCTION(original_TDamageRFWheel, TDamageRFWheel)
void TDamageRFWheel() {
    LOG_TRACE("()");


    original_TDamageRFWheel();
}

static void(*original_TDamageRFBrake)() = (void(*)())0x004a1367;
CARM95_HOOK_FUNCTION(original_TDamageRFBrake, TDamageRFBrake)
void TDamageRFBrake() {
    LOG_TRACE("()");


    original_TDamageRFBrake();
}

static void(*original_TDamageRRBrake)() = (void(*)())0x004a137c;
CARM95_HOOK_FUNCTION(original_TDamageRRBrake, TDamageRRBrake)
void TDamageRRBrake() {
    LOG_TRACE("()");


    original_TDamageRRBrake();
}

static void(*original_TDamageRRWheel)() = (void(*)())0x004a1391;
CARM95_HOOK_FUNCTION(original_TDamageRRWheel, TDamageRRWheel)
void TDamageRRWheel() {
    LOG_TRACE("()");


    original_TDamageRRWheel();
}

static void(*original_MoveBonnetForward)() = (void(*)())0x004a13a6;
CARM95_HOOK_FUNCTION(original_MoveBonnetForward, MoveBonnetForward)
void MoveBonnetForward() {
    LOG_TRACE("()");


    original_MoveBonnetForward();
}

static void(*original_SaveBonnet)() = (void(*)())0x004a13dd;
CARM95_HOOK_FUNCTION(original_SaveBonnet, SaveBonnet)
void SaveBonnet() {
    br_actor *bonny;
    tPath_name the_path;
    LOG_TRACE("()");

    (void)bonny;
    (void)the_path;

    original_SaveBonnet();
}

static void(*original_MoveBonnetBackward)() = (void(*)())0x004a142f;
CARM95_HOOK_FUNCTION(original_MoveBonnetBackward, MoveBonnetBackward)
void MoveBonnetBackward() {
    LOG_TRACE("()");


    original_MoveBonnetBackward();
}

static void(*original_MoveBonnetLeft)() = (void(*)())0x004a1466;
CARM95_HOOK_FUNCTION(original_MoveBonnetLeft, MoveBonnetLeft)
void MoveBonnetLeft() {
    LOG_TRACE("()");


    original_MoveBonnetLeft();
}

static void(*original_ShrinkBonnetX)() = (void(*)())0x004a149d;
CARM95_HOOK_FUNCTION(original_ShrinkBonnetX, ShrinkBonnetX)
void ShrinkBonnetX() {
    LOG_TRACE("()");


    original_ShrinkBonnetX();
}

static void(*original_SwellBonnetX)() = (void(*)())0x004a14d4;
CARM95_HOOK_FUNCTION(original_SwellBonnetX, SwellBonnetX)
void SwellBonnetX() {
    LOG_TRACE("()");


    original_SwellBonnetX();
}

static void(*original_ShrinkBonnetY)() = (void(*)())0x004a150b;
CARM95_HOOK_FUNCTION(original_ShrinkBonnetY, ShrinkBonnetY)
void ShrinkBonnetY() {
    LOG_TRACE("()");


    original_ShrinkBonnetY();
}

static void(*original_SwellBonnetY)() = (void(*)())0x004a1542;
CARM95_HOOK_FUNCTION(original_SwellBonnetY, SwellBonnetY)
void SwellBonnetY() {
    LOG_TRACE("()");


    original_SwellBonnetY();
}

static void(*original_ShrinkBonnetZ)() = (void(*)())0x004a1579;
CARM95_HOOK_FUNCTION(original_ShrinkBonnetZ, ShrinkBonnetZ)
void ShrinkBonnetZ() {
    LOG_TRACE("()");


    original_ShrinkBonnetZ();
}

static void(*original_SwellBonnetZ)() = (void(*)())0x004a15b0;
CARM95_HOOK_FUNCTION(original_SwellBonnetZ, SwellBonnetZ)
void SwellBonnetZ() {
    LOG_TRACE("()");


    original_SwellBonnetZ();
}

static void(*original_MoveBonnetDown)() = (void(*)())0x004a15e7;
CARM95_HOOK_FUNCTION(original_MoveBonnetDown, MoveBonnetDown)
void MoveBonnetDown() {
    LOG_TRACE("()");


    original_MoveBonnetDown();
}

static void(*original_MoveBonnetRight)() = (void(*)())0x004a161e;
CARM95_HOOK_FUNCTION(original_MoveBonnetRight, MoveBonnetRight)
void MoveBonnetRight() {
    LOG_TRACE("()");


    original_MoveBonnetRight();
}

static void(*original_MoveBonnetUp)() = (void(*)())0x004a1655;
CARM95_HOOK_FUNCTION(original_MoveBonnetUp, MoveBonnetUp)
void MoveBonnetUp() {
    LOG_TRACE("()");


    original_MoveBonnetUp();
}

static void(*original_TiltBonnetDownX)() = (void(*)())0x004a168c;
CARM95_HOOK_FUNCTION(original_TiltBonnetDownX, TiltBonnetDownX)
void TiltBonnetDownX() {
    LOG_TRACE("()");


    original_TiltBonnetDownX();
}

static void(*original_TiltBonnetUpX)() = (void(*)())0x004a16b5;
CARM95_HOOK_FUNCTION(original_TiltBonnetUpX, TiltBonnetUpX)
void TiltBonnetUpX() {
    LOG_TRACE("()");


    original_TiltBonnetUpX();
}

static void(*original_TiltBonnetDownY)() = (void(*)())0x004a16e1;
CARM95_HOOK_FUNCTION(original_TiltBonnetDownY, TiltBonnetDownY)
void TiltBonnetDownY() {
    LOG_TRACE("()");


    original_TiltBonnetDownY();
}

static void(*original_TiltBonnetUpY)() = (void(*)())0x004a170a;
CARM95_HOOK_FUNCTION(original_TiltBonnetUpY, TiltBonnetUpY)
void TiltBonnetUpY() {
    LOG_TRACE("()");


    original_TiltBonnetUpY();
}

static void(*original_TiltBonnetDownZ)() = (void(*)())0x004a1736;
CARM95_HOOK_FUNCTION(original_TiltBonnetDownZ, TiltBonnetDownZ)
void TiltBonnetDownZ() {
    LOG_TRACE("()");


    original_TiltBonnetDownZ();
}

static void(*original_TiltBonnetUpZ)() = (void(*)())0x004a175f;
CARM95_HOOK_FUNCTION(original_TiltBonnetUpZ, TiltBonnetUpZ)
void TiltBonnetUpZ() {
    LOG_TRACE("()");


    original_TiltBonnetUpZ();
}

static void(*original_ToggleCockpit)() = (void(*)())0x004a178b;
CARM95_HOOK_FUNCTION(original_ToggleCockpit, ToggleCockpit)
void ToggleCockpit() {
    br_scalar ts;
    LOG_TRACE("()");

    (void)ts;

    original_ToggleCockpit();
}

static void(*original_ToggleMirror)() = (void(*)())0x004a1895;
CARM95_HOOK_FUNCTION(original_ToggleMirror, ToggleMirror)
void ToggleMirror() {
    LOG_TRACE("()");


    original_ToggleMirror();
}

static void(*original_ConcussMe)() = (void(*)())0x004a1919;
CARM95_HOOK_FUNCTION(original_ConcussMe, ConcussMe)
void ConcussMe() {
    LOG_TRACE("()");


    original_ConcussMe();
}

static void(*original_CheckHelp)() = (void(*)())0x004a29aa;
CARM95_HOOK_FUNCTION(original_CheckHelp, CheckHelp)
void CheckHelp() {
    LOG_TRACE("()");


    original_CheckHelp();
}

static void(*original_CheckLoadSave)() = (void(*)())0x004a29b5;
CARM95_HOOK_FUNCTION(original_CheckLoadSave, CheckLoadSave)
void CheckLoadSave() {
    int save_load_allowed;
    int switched_res;
    LOG_TRACE("()");

    (void)save_load_allowed;
    (void)switched_res;

    original_CheckLoadSave();
}

static void(*original_CheckToggles)(int, ...) = (void(*)(int, ...))0x004a198a;
CARM95_HOOK_FUNCTION(original_CheckToggles, CheckToggles)
void CheckToggles(int pRacing) {
    int i;
    int new_state;
    LOG_TRACE("(%d)", pRacing);

    (void)pRacing;
    (void)i;
    (void)new_state;

    original_CheckToggles(pRacing);
}

static int(*original_CarWorldOffFallenCheckThingy)(tCar_spec *, int, ...) = (int(*)(tCar_spec *, int, ...))0x004a1b4d;
CARM95_HOOK_FUNCTION(original_CarWorldOffFallenCheckThingy, CarWorldOffFallenCheckThingy)
int CarWorldOffFallenCheckThingy(tCar_spec *pCar, int pCheck_around) {
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

static int(*original_HasCarFallenOffWorld)(tCar_spec *, ...) = (int(*)(tCar_spec *, ...))0x004a1b2f;
CARM95_HOOK_FUNCTION(original_HasCarFallenOffWorld, HasCarFallenOffWorld)
int HasCarFallenOffWorld(tCar_spec *pCar) {
    LOG_TRACE("(%p)", pCar);

    (void)pCar;

    return original_HasCarFallenOffWorld(pCar);
}

static void(*original_CheckForBeingOutOfThisWorld)() = (void(*)())0x004a3328;
CARM95_HOOK_FUNCTION(original_CheckForBeingOutOfThisWorld, CheckForBeingOutOfThisWorld)
void CheckForBeingOutOfThisWorld() {
    static tU32 the_time;
    static tU32 sLast_check;
    int time_step;
    LOG_TRACE("()");

    (void)the_time;
    (void)sLast_check;
    (void)time_step;

    original_CheckForBeingOutOfThisWorld();
}

static void(*original_CheckHornLocal)(tCar_spec *, ...) = (void(*)(tCar_spec *, ...))0x004a34a8;
CARM95_HOOK_FUNCTION(original_CheckHornLocal, CheckHornLocal)
void CheckHornLocal(tCar_spec *pCar) {
    LOG_TRACE("(%p)", pCar);

    (void)pCar;

    original_CheckHornLocal(pCar);
}

static void(*original_CheckHorn3D)(tCar_spec *, ...) = (void(*)(tCar_spec *, ...))0x004a3582;
CARM95_HOOK_FUNCTION(original_CheckHorn3D, CheckHorn3D)
void CheckHorn3D(tCar_spec *pCar) {
    LOG_TRACE("(%p)", pCar);

    (void)pCar;

    original_CheckHorn3D(pCar);
}

static void(*original_CheckHorns)() = (void(*)())0x004a343d;
CARM95_HOOK_FUNCTION(original_CheckHorns, CheckHorns)
void CheckHorns() {
    int i;
    LOG_TRACE("()");

    (void)i;

    original_CheckHorns();
}

static void(*original_SetRecovery)() = (void(*)())0x004a1d13;
CARM95_HOOK_FUNCTION(original_SetRecovery, SetRecovery)
void SetRecovery() {
    LOG_TRACE("()");


    original_SetRecovery();
}

static void(*original_RecoverCar)() = (void(*)())0x004a20b0;
CARM95_HOOK_FUNCTION(original_RecoverCar, RecoverCar)
void RecoverCar() {
    LOG_TRACE("()");


    original_RecoverCar();
}

static void(*original_CheckMapRenderMove)() = (void(*)())0x004a3694;
CARM95_HOOK_FUNCTION(original_CheckMapRenderMove, CheckMapRenderMove)
void CheckMapRenderMove() {
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

static void(*original_ExplodeCar)(tCar_spec *, ...) = (void(*)(tCar_spec *, ...))0x004a20e9;
CARM95_HOOK_FUNCTION(original_ExplodeCar, ExplodeCar)
void ExplodeCar(tCar_spec *pCar) {
    br_vector3 tv;
    br_vector3 pos;
    LOG_TRACE("(%p)", pCar);

    (void)pCar;
    (void)tv;
    (void)pos;

    original_ExplodeCar(pCar);
}

static void(*original_CheckRecoveryOfCars)(tU32, ...) = (void(*)(tU32, ...))0x004a1ec9;
CARM95_HOOK_FUNCTION(original_CheckRecoveryOfCars, CheckRecoveryOfCars)
void CheckRecoveryOfCars(tU32 pEndFrameTime) {
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

static void(*original_LoseSomePSPowerups)(int, ...) = (void(*)(int, ...))0x004a39cc;
CARM95_HOOK_FUNCTION(original_LoseSomePSPowerups, LoseSomePSPowerups)
void LoseSomePSPowerups(int pNumber) {
    int index;
    LOG_TRACE("(%d)", pNumber);

    (void)pNumber;
    (void)index;

    original_LoseSomePSPowerups(pNumber);
}

static void(*original_CheckOtherRacingKeys)() = (void(*)())0x004a2af6;
CARM95_HOOK_FUNCTION(original_CheckOtherRacingKeys, CheckOtherRacingKeys)
void CheckOtherRacingKeys() {
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

    original_CheckOtherRacingKeys();
}

static int(*original_CheckRecoverCost)() = (int(*)())0x004a2208;
CARM95_HOOK_FUNCTION(original_CheckRecoverCost, CheckRecoverCost)
int CheckRecoverCost() {
    LOG_TRACE("()");


    return original_CheckRecoverCost();
}

static void(*original_SortOutRecover)(tCar_spec *, ...) = (void(*)(tCar_spec *, ...))0x004a3a33;
CARM95_HOOK_FUNCTION(original_SortOutRecover, SortOutRecover)
void SortOutRecover(tCar_spec *pCar) {
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

static void(*original_SetFlipUpCar)(tCar_spec *, ...) = (void(*)(tCar_spec *, ...))0x004a22f4;
CARM95_HOOK_FUNCTION(original_SetFlipUpCar, SetFlipUpCar)
void SetFlipUpCar(tCar_spec *pCar) {
    LOG_TRACE("(%p)", pCar);

    (void)pCar;

    original_SetFlipUpCar(pCar);
}

static void(*original_FlipUpCar)(tCar_spec *, ...) = (void(*)(tCar_spec *, ...))0x004a234a;
CARM95_HOOK_FUNCTION(original_FlipUpCar, FlipUpCar)
void FlipUpCar(tCar_spec *car) {
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

static void(*original_GetPowerup)(int, ...) = (void(*)(int, ...))0x004a291d;
CARM95_HOOK_FUNCTION(original_GetPowerup, GetPowerup)
void GetPowerup(int pNum) {
    LOG_TRACE("(%d)", pNum);

    (void)pNum;

    original_GetPowerup(pNum);
}

static void(*original_CheckSystemKeys)(int, ...) = (void(*)(int, ...))0x004a293f;
CARM95_HOOK_FUNCTION(original_CheckSystemKeys, CheckSystemKeys)
void CheckSystemKeys(int pRacing) {
    tU32 start_menu_time;
    int i;
    LOG_TRACE("(%d)", pRacing);

    (void)pRacing;
    (void)start_menu_time;
    (void)i;

    original_CheckSystemKeys(pRacing);
}

static void(*original_CheckKevKeys)() = (void(*)())0x004a3b39;
CARM95_HOOK_FUNCTION(original_CheckKevKeys, CheckKevKeys)
void CheckKevKeys() {
    int i;
    tU32 *value;
    char s[128];
    LOG_TRACE("()");

    (void)i;
    (void)value;
    (void)s;

    original_CheckKevKeys();
}

static void(*original_BrakeInstantly)() = (void(*)())0x004a4159;
CARM95_HOOK_FUNCTION(original_BrakeInstantly, BrakeInstantly)
void BrakeInstantly() {
    int i;
    LOG_TRACE("()");

    (void)i;

    original_BrakeInstantly();
}

static void(*original_PollCarControls)(tU32, ...) = (void(*)(tU32, ...))0x004a3d80;
CARM95_HOOK_FUNCTION(original_PollCarControls, PollCarControls)
void PollCarControls(tU32 pTime_difference) {
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

static void(*original_PollCameraControls)(tU32, ...) = (void(*)(tU32, ...))0x004a4214;
CARM95_HOOK_FUNCTION(original_PollCameraControls, PollCameraControls)
void PollCameraControls(tU32 pTime_difference) {
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

static void(*original_SetFlag2)(int, ...) = (void(*)(int, ...))0x004a45e8;
CARM95_HOOK_FUNCTION(original_SetFlag2, SetFlag2)
void SetFlag2(int i) {
    LOG_TRACE("(%d)", i);

    (void)i;

    original_SetFlag2(i);
}

static void(*original_ToggleFlying)() = (void(*)())0x004a460c;
CARM95_HOOK_FUNCTION(original_ToggleFlying, ToggleFlying)
void ToggleFlying() {
    LOG_TRACE("()");


    original_ToggleFlying();
}

static void(*original_ToggleInvulnerability)() = (void(*)())0x004a46a8;
CARM95_HOOK_FUNCTION(original_ToggleInvulnerability, ToggleInvulnerability)
void ToggleInvulnerability() {
    LOG_TRACE("()");


    original_ToggleInvulnerability();
}

static void(*original_MoreTime)() = (void(*)())0x004a4721;
CARM95_HOOK_FUNCTION(original_MoreTime, MoreTime)
void MoreTime() {
    LOG_TRACE("()");


    original_MoreTime();
}

static void(*original_MuchMoreTime)() = (void(*)())0x004a4736;
CARM95_HOOK_FUNCTION(original_MuchMoreTime, MuchMoreTime)
void MuchMoreTime() {
    LOG_TRACE("()");


    original_MuchMoreTime();
}

static void(*original_ToggleTimerFreeze)() = (void(*)())0x004a474e;
CARM95_HOOK_FUNCTION(original_ToggleTimerFreeze, ToggleTimerFreeze)
void ToggleTimerFreeze() {
    LOG_TRACE("()");


    original_ToggleTimerFreeze();
}

static void(*original_EarnDosh)() = (void(*)())0x004a47c7;
CARM95_HOOK_FUNCTION(original_EarnDosh, EarnDosh)
void EarnDosh() {
    LOG_TRACE("()");


    original_EarnDosh();
}

static void(*original_LoseDosh)() = (void(*)())0x004a47df;
CARM95_HOOK_FUNCTION(original_LoseDosh, LoseDosh)
void LoseDosh() {
    LOG_TRACE("()");


    original_LoseDosh();
}

static void(*original_ToggleMap)() = (void(*)())0x004a47f7;
CARM95_HOOK_FUNCTION(original_ToggleMap, ToggleMap)
void ToggleMap() {
    static int old_indent;
    static int was_in_cockpit;
    LOG_TRACE("()");

    (void)old_indent;
    (void)was_in_cockpit;

    original_ToggleMap();
}

static int(*original_HornBlowing)() = (int(*)())0x004a492c;
CARM95_HOOK_FUNCTION(original_HornBlowing, HornBlowing)
int HornBlowing() {
    LOG_TRACE("()");


    return original_HornBlowing();
}

static void(*original_ToggleArrow)() = (void(*)())0x004a4947;
CARM95_HOOK_FUNCTION(original_ToggleArrow, ToggleArrow)
void ToggleArrow() {
    static br_actor *old_actor;
    LOG_TRACE("()");

    (void)old_actor;

    original_ToggleArrow();
}

static int(*original_GetRecoverVoucherCount)() = (int(*)())0x004a4a23;
CARM95_HOOK_FUNCTION(original_GetRecoverVoucherCount, GetRecoverVoucherCount)
int GetRecoverVoucherCount() {
    LOG_TRACE("()");


    return original_GetRecoverVoucherCount();
}

static void(*original_AddVouchers)(int, ...) = (void(*)(int, ...))0x004a4a38;
CARM95_HOOK_FUNCTION(original_AddVouchers, AddVouchers)
void AddVouchers(int pCount) {
    LOG_TRACE("(%d)", pCount);

    (void)pCount;

    original_AddVouchers(pCount);
}

static void(*original_ResetRecoveryVouchers)() = (void(*)())0x004a4a4c;
CARM95_HOOK_FUNCTION(original_ResetRecoveryVouchers, ResetRecoveryVouchers)
void ResetRecoveryVouchers() {
    LOG_TRACE("()");


    original_ResetRecoveryVouchers();
}

static void(*original_CycleCarTexturingLevel)() = (void(*)())0x004a4a61;
CARM95_HOOK_FUNCTION(original_CycleCarTexturingLevel, CycleCarTexturingLevel)
void CycleCarTexturingLevel() {
    tCar_texturing_level new_level;
    LOG_TRACE("()");

    (void)new_level;

    original_CycleCarTexturingLevel();
}

static void(*original_CycleWallTexturingLevel)() = (void(*)())0x004a4b28;
CARM95_HOOK_FUNCTION(original_CycleWallTexturingLevel, CycleWallTexturingLevel)
void CycleWallTexturingLevel() {
    tWall_texturing_level new_level;
    LOG_TRACE("()");

    (void)new_level;

    original_CycleWallTexturingLevel();
}

static void(*original_CycleRoadTexturingLevel)() = (void(*)())0x004a4bfb;
CARM95_HOOK_FUNCTION(original_CycleRoadTexturingLevel, CycleRoadTexturingLevel)
void CycleRoadTexturingLevel() {
    tRoad_texturing_level new_level;
    LOG_TRACE("()");

    (void)new_level;

    original_CycleRoadTexturingLevel();
}

static void(*original_CycleYonFactor)() = (void(*)())0x004a4ca1;
CARM95_HOOK_FUNCTION(original_CycleYonFactor, CycleYonFactor)
void CycleYonFactor() {
    br_scalar new_factor;
    char factor_str[5];
    LOG_TRACE("()");

    (void)new_factor;
    (void)factor_str;

    original_CycleYonFactor();
}

static void(*original_SetSoundDetailLevel)(int, ...) = (void(*)(int, ...))0x004a4da4;
CARM95_HOOK_FUNCTION(original_SetSoundDetailLevel, SetSoundDetailLevel)
void SetSoundDetailLevel(int pLevel) {
    LOG_TRACE("(%d)", pLevel);

    (void)pLevel;

    original_SetSoundDetailLevel(pLevel);
}

static void(*original_ReallySetSoundDetailLevel)(int, ...) = (void(*)(int, ...))0x004a4db7;
CARM95_HOOK_FUNCTION(original_ReallySetSoundDetailLevel, ReallySetSoundDetailLevel)
void ReallySetSoundDetailLevel(int pLevel) {
    LOG_TRACE("(%d)", pLevel);

    (void)pLevel;

    original_ReallySetSoundDetailLevel(pLevel);
}

static int(*original_GetSoundDetailLevel)() = (int(*)())0x004a4dde;
CARM95_HOOK_FUNCTION(original_GetSoundDetailLevel, GetSoundDetailLevel)
int GetSoundDetailLevel() {
    LOG_TRACE("()");


    return original_GetSoundDetailLevel();
}

static void(*original_CycleSoundDetailLevel)() = (void(*)())0x004a4df3;
CARM95_HOOK_FUNCTION(original_CycleSoundDetailLevel, CycleSoundDetailLevel)
void CycleSoundDetailLevel() {
    int new_level;
    LOG_TRACE("()");

    (void)new_level;

    original_CycleSoundDetailLevel();
}

static void(*original_CycleCarSimplificationLevel)() = (void(*)())0x004a4ec8;
CARM95_HOOK_FUNCTION(original_CycleCarSimplificationLevel, CycleCarSimplificationLevel)
void CycleCarSimplificationLevel() {
    char *src;
    char *dst;
    LOG_TRACE("()");

    (void)src;
    (void)dst;

    original_CycleCarSimplificationLevel();
}

static void(*original_ToggleAccessoryRendering)() = (void(*)())0x004a4f58;
CARM95_HOOK_FUNCTION(original_ToggleAccessoryRendering, ToggleAccessoryRendering)
void ToggleAccessoryRendering() {
    int on;
    LOG_TRACE("()");

    (void)on;

    original_ToggleAccessoryRendering();
}

static void(*original_ToggleSmoke)() = (void(*)())0x004a500d;
CARM95_HOOK_FUNCTION(original_ToggleSmoke, ToggleSmoke)
void ToggleSmoke() {
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

static void(*original_DrawSomeText)() = (void(*)())0x00485d80;
CARM95_HOOK_FUNCTION(original_DrawSomeText, DrawSomeText)
void DrawSomeText() {
    LOG_TRACE("()");


    original_DrawSomeText();
}

void SaySorryYouLittleBastard() {
    LOG_TRACE("()");


    NOT_IMPLEMENTED();
}

static void(*original_UserSendMessage)() = (void(*)())0x004a509e;
CARM95_HOOK_FUNCTION(original_UserSendMessage, UserSendMessage)
void UserSendMessage() {
    LOG_TRACE("()");


    original_UserSendMessage();
}

static void(*original_EnterUserMessage)() = (void(*)())0x004a50cf;
CARM95_HOOK_FUNCTION(original_EnterUserMessage, EnterUserMessage)
void EnterUserMessage() {
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

static void(*original_DisplayUserMessage)() = (void(*)())0x004a54a9;
CARM95_HOOK_FUNCTION(original_DisplayUserMessage, DisplayUserMessage)
void DisplayUserMessage() {
    char *the_message;
    int len;
    tDR_font *font;
    LOG_TRACE("()");

    (void)the_message;
    (void)len;
    (void)font;

    original_DisplayUserMessage();
}

static void(*original_InitAbuseomatic)() = (void(*)())0x004a567a;
CARM95_HOOK_FUNCTION(original_InitAbuseomatic, InitAbuseomatic)
void InitAbuseomatic() {
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

static void(*original_DisposeAbuseomatic)() = (void(*)())0x004a5868;
CARM95_HOOK_FUNCTION(original_DisposeAbuseomatic, DisposeAbuseomatic)
void DisposeAbuseomatic() {
    int i;
    LOG_TRACE("()");

    (void)i;

    original_DisposeAbuseomatic();
}

