#ifndef _STRUCTUR_H_
#define _STRUCTUR_H_

#include "br_types.h"
#include "dr_types.h"

extern int * hookvar_gLast_wrong_checkpoint ; // addr: 00509A60
extern int * hookvar_gPratcam_on ; // addr: 00509A68
extern int * hookvar_gCockpit_on ; // addr: 00509A6C
extern int(* hookvar_gOpponent_mix )[10][5]; // addr: 00509A70
extern tU32 * hookvar_gLast_checkpoint_time ; // addr: 00509B38
extern tRace_over_reason * hookvar_gRace_over_reason ; // addr: 00551DBC

int __cdecl NumberOfOpponentsLeft();

void __cdecl RaceCompleted(tRace_over_reason pReason);

void __cdecl Checkpoint(int pCheckpoint_index, int pDo_sound);

void __cdecl IncrementCheckpoint();

void __cdecl IncrementLap();

int __cdecl RayHitFace(br_vector3 *pV0, br_vector3 *pV1, br_vector3 *pV2, br_vector3 *pNormal, br_vector3 *pStart, br_vector3 *pDir);

void __cdecl WrongCheckpoint(int pCheckpoint_index);

void __cdecl CheckCheckpoints();

void __cdecl TotalRepair();

void __cdecl DoLogos();

void __cdecl DoProgOpeningAnimation();

void __cdecl DoProgramDemo();

int __cdecl ChooseOpponent(int pNastiness, int *pHad_scum);

void __cdecl SelectOpponents(tRace_info *pRace_info);

int __cdecl PickNetRace(int pCurrent_race, tNet_sequence_type pNet_race_sequence);

void __cdecl SwapNetCarsLoad();

void __cdecl SwapNetCarsDispose();

void __cdecl DoGame();

void __cdecl InitialiseProgramState();

void __cdecl DoProgram();

void __cdecl JumpTheStart();

void __cdecl GoingToInterfaceFromRace();

void __cdecl GoingBackToRaceFromInterface();

#endif
