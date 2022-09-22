#ifndef _MAIN_H_
#define _MAIN_H_

#include "br_types.h"
#include "dr_types.h"


void __cdecl QuitGame();

tU32 TrackCount(br_actor *pActor, tU32 *pCount);

void CheckNumberOfTracks();

void __cdecl ServiceTheGame(int pRacing);

void __cdecl ServiceGame();

void __cdecl ServiceGameInRace();

void __cdecl GameMain(int pArgc, char **pArgv);

#endif
