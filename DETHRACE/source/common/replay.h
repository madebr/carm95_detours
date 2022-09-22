#ifndef _REPLAY_H_
#define _REPLAY_H_

#include "br_types.h"
#include "dr_types.h"

extern char *(* hookvar_gReplay_pixie_names )[10]; // addr: 0050A1B0
// extern int * hookvar_gSingle_frame_mode ;
// extern tU32 * hookvar_gCam_change_time ;
// extern int * hookvar_gSave_file ;
// extern int(* hookvar_gProgress_line_left )[2];
// extern int(* hookvar_gProgress_line_right )[2];
// extern int(* hookvar_gProgress_line_top )[2];
extern br_pixelmap *(* hookvar_gReplay_pixies )[10]; // addr: 00531DD0
extern int * hookvar_gKey_down ; // addr: 00531DB8
// extern int * hookvar_gNo_cursor ;
// extern int * hookvar_gSave_frame_number ;
// extern int * hookvar_gCam_change_button_down ;
// extern tU32 * hookvar_gAction_replay_start_time ;
// extern tU32 * hookvar_gLast_replay_zappy_screen ;
// extern tS32 * hookvar_gStopped_time ;
extern float * hookvar_gPending_replay_rate ; // addr: 00531DBC
// extern tU32 * hookvar_gAction_replay_end_time ;
extern float * hookvar_gReplay_rate ; // addr: 00531DCC
// extern int * hookvar_gSave_bunch_ID ;
// extern int * hookvar_gPlay_direction ;
// extern int * hookvar_gPaused ;
extern tAction_replay_camera_type * hookvar_gAction_replay_camera_mode ; // addr: 00551DB4

int __cdecl ReplayIsPaused();

float __cdecl GetReplayRate();

int GetReplayDirection();

void StopSaving();

void ActualActionReplayHeadups(int pSpecial_zappy_bastard);

void __cdecl DoActionReplayPostSwap();

void __cdecl DoZappyActionReplayHeadups(int pSpecial_zappy_bastard);

void __cdecl DoActionReplayHeadups();

void MoveReplayBuffer(tS32 pMove_amount);

void MoveToEndOfReplay();

void MoveToStartOfReplay();

void __cdecl ToggleReplay();

void __cdecl ReverseSound(tS3_effect_tag pEffect_index, tS3_sound_tag pSound_tag);

int __cdecl FindUniqueFile();

void __cdecl PollActionReplayControls(tU32 pFrame_period);

void __cdecl CheckReplayTurnOn();

void __cdecl InitializeActionReplay();

void __cdecl DoActionReplay(tU32 pFrame_period);

void __cdecl SynchronizeActionReplay();

#endif
