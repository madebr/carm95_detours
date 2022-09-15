#ifndef _MAINLOOP_H_
#define _MAINLOOP_H_

#include "br_types.h"
#include "dr_types.h"

extern int * hookvar_gNasty_kludgey_cockpit_variable ; // addr: 00514AFC
extern tInfo_mode * hookvar_gInfo_mode ; // addr: 00514B00
extern tU32 * hookvar_gLast_tick_count ; // addr: 00514B04
extern tU32 * hookvar_gActual_last_tick_count ; // addr: 00514B08
// extern tU32 * hookvar_gAverage_frame_period ;
extern tU32 * hookvar_gOld_camera_time ; // addr: 0053A1A8
extern tU32 * hookvar_gLast_wasted_massage_start ; // addr: 0053A118
extern float * hookvar_gMr_odo ; // addr: 0053A114
extern tU32 * hookvar_gWasted_last_flash ; // addr: 0053A0E8
extern tTime_bonus_state * hookvar_gTime_bonus_state ; // addr: 0053A120
extern int * hookvar_gQueued_wasted_massages_count ; // addr: 0053A104
extern int * hookvar_gTime_bonus ; // addr: 0053A11C
extern int * hookvar_gRace_bonus_headup ; // addr: 0053A1A4
extern int * hookvar_gWasted_flash_state ; // addr: 0053A10C
extern int * hookvar_gLast_time_headup ; // addr: 0053A110
extern int * hookvar_gTime_bonus_headup ; // addr: 0053A1A0
extern int(* hookvar_gQueued_wasted_massages )[5]; // addr: 0053A0F0
extern tU32 * hookvar_gTime_bonus_start ; // addr: 0053A124
extern int * hookvar_gLast_credit_headup__mainloop ; // addr: 0053A108 // suffix added to avoid duplicate symbol

void ToggleInfo();

void CalculateFrameRate();

void LoseOldestWastedMassage();

void QueueWastedMassage(int pIndex);

void MungeHeadups();

void UpdateFramePeriod(tU32 *pCamera_period);

tU32 GetLastTickCount();

void CheckTimer();

int MungeRaceFinished();

tRace_result MainGameLoop();

tRace_result DoRace();

#endif
