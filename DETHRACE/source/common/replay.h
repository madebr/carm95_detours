#ifndef _REPLAY_H_
#define _REPLAY_H_

#include "br_types.h"
#include "dr_types.h"

extern char *(* hookvar_gReplay_pixie_names )[10]; // addr: 0050A1B0
extern int * hookvar_gSingle_frame_mode ; // addr: 0050A1D8
extern tU32 * hookvar_gCam_change_time ; // addr: 0050A1DC
extern int * hookvar_gSave_file ; // addr: 0050A1E0
extern int(* hookvar_gProgress_line_left )[2]; // addr: 0050A1E8
extern int(* hookvar_gProgress_line_right )[2]; // addr: 0050A1F0
extern int(* hookvar_gProgress_line_top )[2]; // addr: 0050A1F8
extern br_pixelmap *(* hookvar_gReplay_pixies )[10]; // addr: 00531DD0
extern int * hookvar_gKey_down ; // addr: 00531DB8
// extern int * hookvar_gNo_cursor ;
extern int * hookvar_gSave_frame_number ; // addr: 00531DB4
extern int * hookvar_gCam_change_button_down ; // addr: 00531DA8
extern tU32 * hookvar_gAction_replay_start_time ; // addr: 00531DA0
extern tU32 * hookvar_gLast_replay_zappy_screen ; // addr: 00531DC4
extern tS32 * hookvar_gStopped_time ; // addr: 00531DC0
extern float * hookvar_gPending_replay_rate ; // addr: 00531DBC
extern tU32 * hookvar_gAction_replay_end_time ; // addr: 00531DA4
extern float * hookvar_gReplay_rate ; // addr: 00531DCC
extern int * hookvar_gSave_bunch_ID ; // addr: 00531DB0
extern int * hookvar_gPlay_direction ; // addr: 00531DAC
extern int * hookvar_gPaused ; // addr: 00531DC8
extern tAction_replay_camera_type * hookvar_gAction_replay_camera_mode ; // addr: 00551DB4

int __cdecl ReplayIsPaused();

float __cdecl GetReplayRate();

int __stdcall GetReplayDirection();

void __cdecl StopSaving();

void __cdecl ActualActionReplayHeadups(int pSpecial_zappy_bastard);

void __cdecl DoActionReplayPostSwap();

void __cdecl DoZappyActionReplayHeadups(int pSpecial_zappy_bastard);

void __cdecl DoActionReplayHeadups();

void __cdecl MoveReplayBuffer(tS32 pMove_amount);

void __cdecl MoveToEndOfReplay();

void __cdecl MoveToStartOfReplay();

void __cdecl ToggleReplay();

void __cdecl ReverseSound(tS3_effect_tag pEffect_index, tS3_sound_tag pSound_tag);

int __cdecl FindUniqueFile();

void __cdecl PollActionReplayControls(tU32 pFrame_period);

void __cdecl CheckReplayTurnOn();

void __cdecl InitializeActionReplay();

void __cdecl DoActionReplay(tU32 pFrame_period);

void __cdecl SynchronizeActionReplay();

#endif
