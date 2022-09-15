#ifndef _RACESUMM_H_
#define _RACESUMM_H_

#include "br_types.h"
#include "dr_types.h"

extern int(* hookvar_gPlayer_lookup )[6]; // addr: 00530E38
extern tMouse_area * hookvar_gOld_back_button ; // addr: 00530E58
extern tWreck_info(* hookvar_gWreck_array )[30]; // addr: 00530EC0
extern br_actor ** hookvar_gWreck_root ; // addr: 00530E94
extern br_actor ** hookvar_gWreck_camera ; // addr: 00530E2C
extern tU32 * hookvar_gWreck_start_zoom ; // addr: 00530EAC
extern tU32 * hookvar_gWreck_gallery_start ; // addr: 00530EA4
extern float * hookvar_gTemp_rank_increase ; // addr: 00530E28
extern float * hookvar_gRank_per_ms ; // addr: 00530EB8
extern tU32 * hookvar_gLast_wreck_draw ; // addr: 00530EB0
extern tS3_sound_tag * hookvar_gSumm_sound ; // addr: 00530EA0
extern float * hookvar_gCredits_per_ms ; // addr: 00530E8C
extern tMouse_area ** hookvar_gBack_button_ptr ; // addr: 00530E10
extern tU32 * hookvar_gSummary_start ; // addr: 00530E18
extern br_pixelmap ** hookvar_gWreck_z_buffer ; // addr: 00530E98
extern br_pixelmap ** hookvar_gWreck_render_area ; // addr: 00530E08
extern int * hookvar_gWreck_selected ; // addr: 00531D48
extern int * hookvar_gWreck_zoom_out ; // addr: 00531D4C
extern br_pixelmap ** hookvar_gChrome_font ; // addr: 00530E90
extern int * hookvar_gWreck_zoom_in ; // addr: 00530EB4
extern int * hookvar_gTemp_credits ; // addr: 00530EA8
extern int * hookvar_gUser_interacted ; // addr: 00530E50
extern int * hookvar_gWreck_count ; // addr: 00530E00
extern int * hookvar_gRank_etc_munged ; // addr: 00530E88
extern int * hookvar_gRank_increase ; // addr: 00530E0C
extern int * hookvar_gTemp_earned ; // addr: 00530E14
extern int * hookvar_gTemp_rank ; // addr: 00530E30
extern int * hookvar_gWreck_zoomed_in ; // addr: 00530E24
extern int * hookvar_gDone_initial ; // addr: 00530E04
extern int * hookvar_gTemp_lost ; // addr: 00530E20

void MungeRankEtc(tProgram_state *pThe_state);

void CalcRankIncrease();

int RaceSummaryDone(int pCurrent_choice, int pCurrent_mode, int pGo_ahead, int pEscaped, int pTimed_out);

void DrawInBox(int pBox_left, int pText_left, int pTop, int pRight, int pBottom, int pColour, int pAmount);

void DrawChromeNumber(int pLeft_1, int pLeft_2, int pPitch, int pTop, int pAmount);

void DrawSummaryItems();

void RampUpRate(float *pRate, tU32 pTime);

void DrawSummary(int pCurrent_choice, int pCurrent_mode);

void StartSummary();

void SetUpTemps();

int Summ1GoAhead(int *pCurrent_choice, int *pCurrent_mode);

int SummCheckGameOver(int *pCurrent_choice, int *pCurrent_mode);

tSO_result DoEndRaceSummary1();

void PrepareBoundingRadius__racesumm(br_model *model);

void BuildWrecks();

void DisposeWrecks();

int MatrixIsIdentity(br_matrix34 *pMat);

void SpinWrecks(tU32 pFrame_period);

void ZoomInTo(int pIndex, int *pCurrent_choice, int *pCurrent_mode);

void ZoomOutTo(int pIndex, int *pCurrent_choice, int *pCurrent_mode);

int WreckPick(br_actor *pActor, br_model *pModel, br_material *pMaterial, br_vector3 *pRay_pos, br_vector3 *pRay_dir, br_scalar pNear, br_scalar pFar, void *pArg);

int CastSelectionRay(int *pCurrent_choice, int *pCurrent_mode);

int DamageScrnExit(int *pCurrent_choice, int *pCurrent_mode);

void DamageScrnDraw(int pCurrent_choice, int pCurrent_mode);

int DamageScrnLeft(int *pCurrent_choice, int *pCurrent_mode);

int DamageScrnRight(int *pCurrent_choice, int *pCurrent_mode);

int DamageScrnUp(int *pCurrent_choice, int *pCurrent_mode);

int DamageScrnDown(int *pCurrent_choice, int *pCurrent_mode);

int DamageScrnGoHead(int *pCurrent_choice, int *pCurrent_mode);

int ClickDamage(int *pCurrent_choice, int *pCurrent_mode, int pX_offset, int pY_offset);

int DamageScrnDone(int pCurrent_choice, int pCurrent_mode, int pGo_ahead, int pEscaped, int pTimed_out);

tSO_result DoEndRaceSummary2();

void DrawAnItem__racesumm(int pX, int pY_index, int pFont_index, char *pText);

void DrawColumnHeading__racesumm(int pStr_index, int pX);

int SortScores(void *pFirst_one, void *pSecond_one);

void SortGameScores();

void NetSumDraw(int pCurrent_choice, int pCurrent_mode);

void DoNetRaceSummary();

tSO_result DoEndRaceSummary(int *pFirst_summary_done, tRace_result pRace_result);

#endif
