#ifndef _PRATCAM_H_
#define _PRATCAM_H_

#include "br_types.h"
#include "dr_types.h"

extern tS3_sound_tag * hookvar_gWhirr_noise ; // addr: 0050F064
extern tFlic_descriptor * hookvar_gPrat_flic ; // addr: 005362B0
extern tPrat_sequence ** hookvar_gPratcam_sequences ; // addr: 00536334
extern tPrat_flic_spec ** hookvar_gPratcam_flics ; // addr: 00536324
extern int * hookvar_gCurrent_pratcam_chunk ; // addr: 00536320
extern int * hookvar_gPending_ambient_prat ; // addr: 0053632C
extern int * hookvar_gCurrent_pratcam_index ; // addr: 005362A0
extern br_pixelmap ** hookvar_gPrat_buffer ; // addr: 00536340
extern int * hookvar_gNumber_of_prat_sequences ; // addr: 00536330
extern int * hookvar_gNumber_of_prat_flics ; // addr: 005362A4
extern tU32 * hookvar_gLast_pratcam_frame_time ; // addr: 0053633C
extern int * hookvar_gCurrent_pratcam_precedence ; // addr: 00536328
extern int * hookvar_gCurrent_ambient_prat_sequence ; // addr: 00536338
extern int * hookvar_gCurrent_pratcam_alternative ; // addr: 005362A8

int PratcamGetCurrent();

int PratcamGetAmbient();

int PratcamGetPending();

void TogglePratcam();

void LoadPratcam(char *pFolder_name);

void NextPratcamChunk();

void NewPratcamSequence(int pSequence_index, int pStart_chunk);

void ChangeAmbientPratcamNow(int pIndex, int pStart_chunk);

void ChangeAmbientPratcam(int pIndex);

void PratcamEventNow(int pIndex);

void PratcamEvent(int pIndex);

int HighResPratBufferWidth();

int HighResPratBufferHeight();

void InitPratcam();

void DisposePratcam();

void DoPratcam(tU32 pThe_time);

void TestPratCam(int pIndex);

void PratCam0();

void PratCam1();

void PratCam2();

void PratCam3();

void PratCam4();

void PratCam5();

void PratCam6();

void PratCam7();

void PratCam8();

void PratCam9();

#endif
