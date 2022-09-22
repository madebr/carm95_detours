#ifndef _CUTSCENE_H_
#define _CUTSCENE_H_

#include "br_types.h"
#include "dr_types.h"

// extern tS32 * hookvar_gLast_demo_end_anim ;

void* radmalloc(unsigned long numbytes);

void radfree(void *ptr);

void __cdecl ShowCutScene(int pIndex, int pWait_end, int pSound_ID, br_scalar pDelay);

void __cdecl DoSCILogo();

void __cdecl DoStainlessLogo();

void __cdecl PlaySmackerFile(char *pSmack_name);

void __cdecl DoOpeningAnimation();

void __cdecl DoNewGameAnimation();

void __cdecl DoGoToRaceAnimation();

void __cdecl DoEndRaceAnimation();

void __cdecl DoGameOverAnimation();

void __cdecl DoGameCompletedAnimation();

void __cdecl StartLoadingScreen();

#endif
