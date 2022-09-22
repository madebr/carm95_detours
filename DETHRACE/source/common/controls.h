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

void __cdecl AbortRace();

void __cdecl F4Key();

void __cdecl SetFlag(int i);

void __cdecl FinishLap(int i);

void __cdecl EnsureSpecialVolumesHidden();

void __cdecl ShowSpecialVolumesIfRequ();

void __cdecl DoEditModeKey(int pIndex);

void __cdecl F5Key();

void __cdecl F6Key();

void __cdecl F7Key();

void __cdecl F8Key();

void __cdecl F10Key();

void __cdecl F11Key();

void __cdecl F12Key();

void __cdecl NumberKey0();

void __cdecl NumberKey1();

void __cdecl NumberKey2();

void __cdecl NumberKey3();

void __cdecl NumberKey4();

void __cdecl NumberKey5();

void __cdecl NumberKey6();

void __cdecl NumberKey7();

void __cdecl NumberKey8();

void __cdecl NumberKey9();

void __cdecl LookLeft();

void __cdecl LookForward();

void __cdecl LookRight();

void __cdecl DamageTest();

void __cdecl TDamageEngine();

void __cdecl TDamageDriver();

void __cdecl TDamageTrans();

void __cdecl TDamageSteering();

void __cdecl TDamageLFWheel();

void __cdecl TDamageLFBrake();

void __cdecl TDamageLRBrake();

void __cdecl TDamageLRWheel();

void __cdecl TDamageRFWheel();

void __cdecl TDamageRFBrake();

void __cdecl TDamageRRBrake();

void __cdecl TDamageRRWheel();

void __cdecl MoveBonnetForward();

void __cdecl SaveBonnet();

void __cdecl MoveBonnetBackward();

void __cdecl MoveBonnetLeft();

void __cdecl ShrinkBonnetX();

void __cdecl SwellBonnetX();

void __cdecl ShrinkBonnetY();

void __cdecl SwellBonnetY();

void __cdecl ShrinkBonnetZ();

void __cdecl SwellBonnetZ();

void __cdecl MoveBonnetDown();

void __cdecl MoveBonnetRight();

void __cdecl MoveBonnetUp();

void __cdecl TiltBonnetDownX();

void __cdecl TiltBonnetUpX();

void __cdecl TiltBonnetDownY();

void __cdecl TiltBonnetUpY();

void __cdecl TiltBonnetDownZ();

void __cdecl TiltBonnetUpZ();

void __cdecl ToggleCockpit();

void __cdecl ToggleMirror();

void __cdecl ConcussMe();

void __cdecl CheckHelp();

void __cdecl CheckLoadSave();

void __cdecl CheckToggles(int pRacing);

int __cdecl CarWorldOffFallenCheckThingy(tCar_spec *pCar, int pCheck_around);

int __cdecl HasCarFallenOffWorld(tCar_spec *pCar);

void __cdecl CheckForBeingOutOfThisWorld();

void __cdecl CheckHornLocal(tCar_spec *pCar);

void __cdecl CheckHorn3D(tCar_spec *pCar);

void __cdecl CheckHorns();

void __cdecl SetRecovery();

void __cdecl RecoverCar();

void __cdecl CheckMapRenderMove();

void __cdecl ExplodeCar(tCar_spec *pCar);

void __cdecl CheckRecoveryOfCars(tU32 pEndFrameTime);

void __cdecl LoseSomePSPowerups(int pNumber);

void __cdecl CheckOtherRacingKeys();

int __cdecl CheckRecoverCost();

void __cdecl SortOutRecover(tCar_spec *pCar);

void __cdecl SetFlipUpCar(tCar_spec *pCar);

void __cdecl FlipUpCar(tCar_spec *car);

void __cdecl GetPowerup(int pNum);

void __cdecl CheckSystemKeys(int pRacing);

void __cdecl CheckKevKeys();

void __cdecl BrakeInstantly();

void __cdecl PollCarControls(tU32 pTime_difference);

void __cdecl PollCameraControls(tU32 pTime_difference);

void __cdecl SetFlag2(int i);

void __cdecl ToggleFlying();

void __cdecl ToggleInvulnerability();

void __cdecl MoreTime();

void __cdecl MuchMoreTime();

void __cdecl ToggleTimerFreeze();

void __cdecl EarnDosh();

void __cdecl LoseDosh();

void __cdecl ToggleMap();

int __cdecl HornBlowing();

void __cdecl ToggleArrow();

int __cdecl GetRecoverVoucherCount();

void __cdecl AddVouchers(int pCount);

void __cdecl ResetRecoveryVouchers();

void __cdecl CycleCarTexturingLevel();

void __cdecl CycleWallTexturingLevel();

void __cdecl CycleRoadTexturingLevel();

void __cdecl CycleYonFactor();

void __cdecl SetSoundDetailLevel(int pLevel);

void __cdecl ReallySetSoundDetailLevel(int pLevel);

int __cdecl GetSoundDetailLevel();

void __cdecl CycleSoundDetailLevel();

void __cdecl CycleCarSimplificationLevel();

void __cdecl ToggleAccessoryRendering();

void __cdecl ToggleSmoke();

void DrawSomeText2(tDR_font *pFont);

void __cdecl DrawSomeText();

void SaySorryYouLittleBastard();

void __cdecl UserSendMessage();

void __cdecl EnterUserMessage();

void __cdecl DisplayUserMessage();

void __cdecl InitAbuseomatic();

void __cdecl DisposeAbuseomatic();

#endif
