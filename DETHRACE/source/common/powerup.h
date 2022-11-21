#ifndef _POWERUP_H_
#define _POWERUP_H_

#include "br_types.h"
#include "dr_types.h"

extern tGot_proc*(* hookvar_gGot_procs )[34]; // addr: 0050BA98
extern tLose_proc*(* hookvar_gLose_procs )[34]; // addr: 0050BB20
extern tPeriodic_proc*(* hookvar_gPeriodic_procs )[34]; // addr: 0050BBA8
extern tU32 ** hookvar_gReal_render_palette ; // addr: 0050BC30
extern char *(* hookvar_gFizzle_names )[3]; // addr: 0050BC38
extern br_vector3 * hookvar_gZero_v__powerup ; // addr: 0050BC48 // suffix added to avoid duplicate symbol
extern int(* hookvar_gPed_harvest_sounds )[4]; // addr: 0050BC58
extern tHeadup_icon(* hookvar_gIcon_list )[20]; // addr: 005320A0
extern br_pixelmap *(* hookvar_gFizzle_in )[3]; // addr: 005321F0
extern int * hookvar_gNumber_of_powerups ; // addr: 005321FC
extern int * hookvar_gFizzle_height ; // addr: 005321E4
extern int * hookvar_gNumber_of_icons ; // addr: 005321E0
extern tPowerup ** hookvar_gPowerup_array ; // addr: 005321E8

void __cdecl LosePowerupX(tPowerup *pThe_powerup, int pTell_net_players);

void __cdecl LosePowerup(tPowerup *pThe_powerup);

void __cdecl LoseAllSimilarPowerups(tPowerup *pThe_powerup);

int __cdecl GotPowerupX(tCar_spec *pCar, int pIndex, int pTell_net_players, int pDisplay_headup, tU32 pTime_left);

int __cdecl GotPowerup(tCar_spec *pCar, int pIndex);

void __cdecl LoadPowerups();

void __cdecl InitPowerups();

void __cdecl CloseDownPowerUps();

void __cdecl DrawPowerups(tU32 pTime);

void __cdecl DoPowerupPeriodics(tU32 pFrame_period);

void __cdecl GotPowerupN(int pN);

void __cdecl GotPowerup0();

void __cdecl GotPowerup1();

void __cdecl GotPowerup2();

void __cdecl GotPowerup3();

void __cdecl GotPowerup4();

void __cdecl GotPowerup5();

void __cdecl GotPowerup6();

void __cdecl GotPowerup7();

void __cdecl GotPowerup8();

void __cdecl GotPowerup9();

int __cdecl GotCredits(tPowerup *pPowerup, tCar_spec *pCar);

void __cdecl ImprovePSPowerup(tCar_spec *pCar, int pIndex);

int __cdecl GotTimeOrPower(tPowerup *pPowerup, tCar_spec *pCar);

int __cdecl SetPedSpeed(tPowerup *pPowerup, tCar_spec *pCar);

int __cdecl SetHades(tPowerup *pPowerup, tCar_spec *pCar);

void __cdecl ResetHades(tPowerup *pPowerup, tCar_spec *pCar);

int __cdecl SetPedSize(tPowerup *pPowerup, tCar_spec *pCar);

int __cdecl SetPedExplode(tPowerup *pPowerup, tCar_spec *pCar);

int __cdecl SetInvulnerability(tPowerup *pPowerup, tCar_spec *pCar);

void __cdecl ResetInvulnerability(tPowerup *pPowerup, tCar_spec *pCar);

int __cdecl SetFreeRepairs(tPowerup *pPowerup, tCar_spec *pCar);

void __cdecl ResetFreeRepairs(tPowerup *pPowerup, tCar_spec *pCar);

int __cdecl SetBlindPedestrians(tPowerup *pPowerup, tCar_spec *pCar);

void __cdecl ResetBlindPedestrians(tPowerup *pPowerup, tCar_spec *pCar);

int __cdecl FreezeTimer(tPowerup *pPowerup, tCar_spec *pCar);

void __cdecl UnfreezeTimer(tPowerup *pPowerup, tCar_spec *pCar);

int __cdecl DoInstantRepair(tPowerup *pPowerup, tCar_spec *pCar);

void __cdecl ResetPedSpeed(tPowerup *pPowerup, tCar_spec *pCar);

void __cdecl ResetPedSize(tPowerup *pPowerup, tCar_spec *pCar);

void __cdecl ResetPedExplode(tPowerup *pPowerup, tCar_spec *pCar);

int __cdecl SetEngineFactor(tPowerup *pPowerup, tCar_spec *pCar);

int __cdecl SetUnderwater(tPowerup *pPowerup, tCar_spec *pCar);

int __cdecl TrashBodywork(tPowerup *pPowerup, tCar_spec *pCar);

int __cdecl TakeDrugs(tPowerup *pPowerup, tCar_spec *pCar);

void __cdecl PaletteFuckedUpByDrugs(br_pixelmap *pPixelmap, int pOffset);

void __cdecl TheEffectsOfDrugs(tPowerup *pPowerup, tU32 pPeriod);

int __cdecl SetOpponentsSpeed(tPowerup *pPowerup, tCar_spec *pCar);

int __cdecl SetCopsSpeed(tPowerup *pPowerup, tCar_spec *pCar);

int __cdecl SetGravity(tPowerup *pPowerup, tCar_spec *pCar);

int __cdecl SetPinball(tPowerup *pPowerup, tCar_spec *pCar);

int __cdecl SetWallclimb(tPowerup *pPowerup, tCar_spec *pCar);

int __cdecl SetBouncey(tPowerup *pPowerup, tCar_spec *pCar);

int __cdecl SetSuspension(tPowerup *pPowerup, tCar_spec *pCar);

int __cdecl SetTyreGrip(tPowerup *pPowerup, tCar_spec *pCar);

int __cdecl SetDamageMultiplier(tPowerup *pPowerup, tCar_spec *pCar);

void __cdecl ResetEngineFactor(tPowerup *pPowerup, tCar_spec *pCar);

void __cdecl ResetUnderwater(tPowerup *pPowerup, tCar_spec *pCar);

void __cdecl PukeDrugsBackUp(tPowerup *pPowerup, tCar_spec *pCar);

void __cdecl ResetOpponentsSpeed(tPowerup *pPowerup, tCar_spec *pCar);

void __cdecl ResetCopsSpeed(tPowerup *pPowerup, tCar_spec *pCar);

void __cdecl ResetGravity(tPowerup *pPowerup, tCar_spec *pCar);

void __cdecl ResetPinball(tPowerup *pPowerup, tCar_spec *pCar);

void __cdecl ResetWallclimb(tPowerup *pPowerup, tCar_spec *pCar);

void __cdecl ResetBouncey(tPowerup *pPowerup, tCar_spec *pCar);

void __cdecl ResetSuspension(tPowerup *pPowerup, tCar_spec *pCar);

void __cdecl ResetDamageMultiplier(tPowerup *pPowerup, tCar_spec *pCar);

void __cdecl ResetTyreGrip(tPowerup *pPowerup, tCar_spec *pCar);

int __cdecl PickAtRandom(tPowerup *pPowerup, tCar_spec *pCar);

int __cdecl PedestrianRespawn(tPowerup *pPowerup, tCar_spec *pCar);

int __cdecl GotVouchers(tPowerup *pPowerup, tCar_spec *pCar);

void __cdecl MungeVouchers(tPowerup *pPowerup, tU32 pPeriod);

int __cdecl SetInstantHandbrake(tPowerup *pPowerup, tCar_spec *pCar);

void __cdecl ResetInstantHandbrake(tPowerup *pPowerup, tCar_spec *pCar);

void __cdecl DoBouncey(tPowerup *pPowerup, tU32 pPeriod);

int __cdecl HitMine(tPowerup *pPowerup, tCar_spec *pCar);

int __cdecl SetMassMultiplier(tPowerup *pPowerup, tCar_spec *pCar);

void __cdecl ResetMassMultiplier(tPowerup *pPowerup, tCar_spec *pCar);

int __cdecl ShowPedestrians(tPowerup *pPowerup, tCar_spec *pCar);

void __cdecl HidePedestrians(tPowerup *pPowerup, tCar_spec *pCar);

int __cdecl SetProximity(tPowerup *pPowerup, tCar_spec *pCar);

void __cdecl ResetProximity(tPowerup *pPowerup, tCar_spec *pCar);

int __cdecl SetPedHarvest(tPowerup *pPowerup, tCar_spec *pCar);

void __cdecl ResetPedHarvest(tPowerup *pPowerup, tCar_spec *pCar);

int __cdecl SetVesuvianCorpses(tPowerup *pPowerup, tCar_spec *pCar);

void __cdecl ResetVesuvianCorpses(tPowerup *pPowerup, tCar_spec *pCar);

void __cdecl ReceivedPowerup(tNet_contents *pContents);

void __cdecl SendCurrentPowerups();

void __cdecl LoseAllLocalPowerups(tCar_spec *pCar);

#endif
