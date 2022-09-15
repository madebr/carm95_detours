#ifndef _CONTROLS_H_
#define _CONTROLS_H_

#include "br_types.h"
#include "dr_types.h"

extern tToggle_element(* hookvar_gToggle_array )[43]; // addr: 0051B1C0
extern int * hookvar_gRepair_last_time ; // addr: 0051B5C8
extern int * hookvar_gHad_auto_recover ; // addr: 0051B5CC
extern tU32 * hookvar_gLast_repair_time ; // addr: 0051B5D0
extern tEdit_mode * hookvar_gWhich_edit_mode ; // addr: 0051B5D4
extern char *(* hookvar_gEdit_mode_names )[10]; // addr: 0051B5D8
extern tEdit_func*(* hookvar_gEdit_funcs )[10][18][8]; // addr: 0051B600
extern tCheat(* hookvar_gKev_keys )[44]; // addr: 0051CC80
extern int * hookvar_gAllow_car_flying ; // addr: 0051CF30
extern int * hookvar_gEntering_message ; // addr: 0051CF34
extern tU32 * hookvar_gPalette_fade_time ; // addr: 0051CF38
extern char *(* hookvar_gAbuse_text )[10]; // addr: 0053D608
extern char(* hookvar_gString )[84]; // addr: 0053D648
extern int * hookvar_gToo_late ; // addr: 0053D5F8
extern int * hookvar_gRecover_timer ; // addr: 0053D5FC
extern int * hookvar_gRecovery_voucher_count ; // addr: 0053D63C
extern int * hookvar_gInstant_handbrake ; // addr: 00550550
extern int * hookvar_gAuto_repair ; // addr: 00550554

void AbortRace();

void F4Key();

void SetFlag(int i);

void FinishLap(int i);

void EnsureSpecialVolumesHidden();

void ShowSpecialVolumesIfRequ();

void DoEditModeKey(int pIndex);

void F5Key();

void F6Key();

void F7Key();

void F8Key();

void F10Key();

void F11Key();

void F12Key();

void NumberKey0();

void NumberKey1();

void NumberKey2();

void NumberKey3();

void NumberKey4();

void NumberKey5();

void NumberKey6();

void NumberKey7();

void NumberKey8();

void NumberKey9();

void LookLeft();

void LookForward();

void LookRight();

void DamageTest();

void TDamageEngine();

void TDamageDriver();

void TDamageTrans();

void TDamageSteering();

void TDamageLFWheel();

void TDamageLFBrake();

void TDamageLRBrake();

void TDamageLRWheel();

void TDamageRFWheel();

void TDamageRFBrake();

void TDamageRRBrake();

void TDamageRRWheel();

void MoveBonnetForward();

void SaveBonnet();

void MoveBonnetBackward();

void MoveBonnetLeft();

void ShrinkBonnetX();

void SwellBonnetX();

void ShrinkBonnetY();

void SwellBonnetY();

void ShrinkBonnetZ();

void SwellBonnetZ();

void MoveBonnetDown();

void MoveBonnetRight();

void MoveBonnetUp();

void TiltBonnetDownX();

void TiltBonnetUpX();

void TiltBonnetDownY();

void TiltBonnetUpY();

void TiltBonnetDownZ();

void TiltBonnetUpZ();

void ToggleCockpit();

void ToggleMirror();

void ConcussMe();

void CheckHelp();

void CheckLoadSave();

void CheckToggles(int pRacing);

int CarWorldOffFallenCheckThingy(tCar_spec *pCar, int pCheck_around);

int HasCarFallenOffWorld(tCar_spec *pCar);

void CheckForBeingOutOfThisWorld();

void CheckHornLocal(tCar_spec *pCar);

void CheckHorn3D(tCar_spec *pCar);

void CheckHorns();

void SetRecovery();

void RecoverCar();

void CheckMapRenderMove();

void ExplodeCar(tCar_spec *pCar);

void CheckRecoveryOfCars(tU32 pEndFrameTime);

void LoseSomePSPowerups(int pNumber);

void CheckOtherRacingKeys();

int CheckRecoverCost();

void SortOutRecover(tCar_spec *pCar);

void SetFlipUpCar(tCar_spec *pCar);

void FlipUpCar(tCar_spec *car);

void GetPowerup(int pNum);

void CheckSystemKeys(int pRacing);

void CheckKevKeys();

void BrakeInstantly();

void PollCarControls(tU32 pTime_difference);

void PollCameraControls(tU32 pTime_difference);

void SetFlag2(int i);

void ToggleFlying();

void ToggleInvulnerability();

void MoreTime();

void MuchMoreTime();

void ToggleTimerFreeze();

void EarnDosh();

void LoseDosh();

void ToggleMap();

int HornBlowing();

void ToggleArrow();

int GetRecoverVoucherCount();

void AddVouchers(int pCount);

void ResetRecoveryVouchers();

void CycleCarTexturingLevel();

void CycleWallTexturingLevel();

void CycleRoadTexturingLevel();

void CycleYonFactor();

void SetSoundDetailLevel(int pLevel);

void ReallySetSoundDetailLevel(int pLevel);

int GetSoundDetailLevel();

void CycleSoundDetailLevel();

void CycleCarSimplificationLevel();

void ToggleAccessoryRendering();

void ToggleSmoke();

void DrawSomeText2(tDR_font *pFont);

void DrawSomeText();

void SaySorryYouLittleBastard();

void UserSendMessage();

void EnterUserMessage();

void DisplayUserMessage();

void InitAbuseomatic();

void DisposeAbuseomatic();

#endif
