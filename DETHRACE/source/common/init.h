#ifndef _INIT_H_
#define _INIT_H_

#include "br_types.h"
#include "dr_types.h"

extern int * hookvar_gGame_initialized ; // addr: 0052115C
extern int * hookvar_gBr_initialized ; // addr: 00521160
extern int * hookvar_gBrZb_initialized ; // addr: 00521164
// extern int * hookvar_gInitialisation_finished ;
extern int * hookvar_gRender_indent ; // addr: 0052116C
extern tU32 * hookvar_gAustere_time ; // addr: 0053FDD0
extern int * hookvar_gInitial_rank ; // addr: 0054B2BC
extern int(* hookvar_gCredits_per_rank )[3]; // addr: 0054B2B0
// extern int(* hookvar_gInitial_credits )[3];
extern int * hookvar_gNet_mode_of_last_game ; // addr: 0054B2A0
extern br_material ** hookvar_gDefault_track_material ; // addr: 0054B29C

void __cdecl AllocateSelf();

void __cdecl AllocateCamera();

void __cdecl ReinitialiseForwardCamera();

void __cdecl AllocateRearviewPixelmap();

void __cdecl ReinitialiseRearviewCamera();

void __cdecl ReinitialiseRenderStuff();

void InstallFindFailedHooks();

void __cdecl AllocateStandardLamp();

void __cdecl InitializeBRenderEnvironment();

void __cdecl InitBRFonts();

void __cdecl AustereWarning();

void InitLineStuff();

void InitSmokeStuff();

void Init2DStuff();

void __cdecl InitialiseApplication(int pArgc, char **pArgv);

void InitialiseDeathRace(int pArgc, char **pArgv);

void __cdecl InitGame(int pStart_race);

void __cdecl DisposeGameIfNecessary();

void __cdecl LoadInTrack();

void __cdecl DisposeTrack();

void CopyMaterialColourFromIndex(br_material *pMaterial);

void __cdecl InitRace();

void __cdecl DisposeRace();

int __cdecl GetScreenSize();

void __cdecl SetScreenSize(int pNew_size);

#endif
