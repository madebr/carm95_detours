#ifndef _DISPLAYS_H_
#define _DISPLAYS_H_

#include "br_types.h"
#include "dr_types.h"

extern int * hookvar_gLast_fancy_index ; // addr: 00521678
extern int * hookvar_gLast_credit_headup__displays ; // addr: 0052167C // suffix added to avoid duplicate symbol
extern int * hookvar_gLast_time_credit_headup ; // addr: 00521680
extern tDR_font ** hookvar_gCached_font ; // addr: 00521684
extern br_font *(* hookvar_gBR_fonts )[4]; // addr: 00541598
extern tQueued_headup(* hookvar_gQueued_headups )[4]; // addr: 00541160
extern int(* hookvar_gOld_times )[10]; // addr: 00544E30
// extern int * hookvar_gLast_fancy_headup ;
extern tU32 * hookvar_gLast_time_earn_time ; // addr: 00541594
extern tU32 * hookvar_gLast_centre_headup ; // addr: 005415A8
extern tU32 * hookvar_gLast_fancy_time ; // addr: 005415AC
extern int * hookvar_gQueued_headup_count ; // addr: 00541158
extern tU32 * hookvar_gLast_earn_time ; // addr: 0054114C
// extern tU32 * hookvar_gLast_time_credit_amount ;
extern int * hookvar_gLast_credit_amount ; // addr: 00541150
extern tHeadup(* hookvar_gHeadups )[15]; // addr: 0053FDD8
extern int * hookvar_gLaps_headup ; // addr: 00544E60
extern int * hookvar_gCar_kill_count_headup ; // addr: 00544E68
extern int * hookvar_gTimer_headup ; // addr: 00544E5C
extern int * hookvar_gTime_awarded_headup ; // addr: 00544E6C
extern int * hookvar_gPed_kill_count_headup ; // addr: 00544E64
extern int * hookvar_gDim_amount ; // addr: 00544EEC
extern br_pixelmap *(* hookvar_gHeadup_images )[31]; // addr: 00544E70
extern int * hookvar_gNet_cash_headup ; // addr: 00544E58
extern int * hookvar_gNet_ped_headup ; // addr: 00544E1C
// extern int * hookvar_gCredits_lost_headup ;
extern int * hookvar_gCredits_won_headup ; // addr: 00544E20

void GetTimerString(char *pStr, int pFudge_colon);

void InitHeadups();

void ClearHeadup(int pIndex);

void ClearHeadupSlot(int pSlot_index);

void ClearHeadups();

int HeadupActive(int pIndex);

void DRPixelmapText(br_pixelmap *pPixelmap, int pX, int pY, tDR_font *pFont, char *pText, int pRight_edge);

void DRPixelmapCleverText2(br_pixelmap *pPixelmap, int pX, int pY, tDR_font *pFont, signed char *pText, int pRight_edge);

void DeviouslyDimRectangle(br_pixelmap *pPixelmap, int pLeft, int pTop, int pRight, int pBottom, int pKnock_out_corners);

void DimRectangle(br_pixelmap *pPixelmap, int pLeft, int pTop, int pRight, int pBottom, int pKnock_out_corners);

void DimAFewBits();

void KillOldestQueuedHeadup();

void DubreyBar(int pX_index, int pY, int pColour);

void DoPSPowerHeadup(int pY, int pLevel, char *pName, int pBar_colour);

void DoPSPowerupHeadups();

void DoHeadups(tU32 pThe_time);

int FindAHeadupHoleWoofBarkSoundsABitRude(int pSlot_index);

int DRTextWidth(tDR_font *pFont, char *pText);

int DRTextCleverWidth(tDR_font *pFont, signed char *pText);

void DRPixelmapCentredText(br_pixelmap *pPixelmap, int pX, int pY, tDR_font *pFont, char *pText);

int IsHeadupTextClever(signed char *pText);

int MungeHeadupWidth(tHeadup *pHeadup);

int NewTextHeadupSlot2(int pSlot_index, int pFlash_rate, int pLifetime, int pFont_index, char *pText, int pQueue_it);

int NewTextHeadupSlot(int pSlot_index, int pFlash_rate, int pLifetime, int pFont_index, char *pText);

int NewImageHeadupSlot(int pSlot_index, int pFlash_rate, int pLifetime, int pImage_index);

void DoFancyHeadup(int pIndex);

void AdjustHeadups();

void MoveHeadupTo(int pHeadup_index, int pNew_x, int pNew_y);

void ChangeHeadupText(int pHeadup_index, char *pNew_text);

void ChangeHeadupImage(int pHeadup_index, int pNew_image);

void ChangeHeadupColour(int pHeadup_index, int pNew_colour);

void DoDamageScreen(tU32 pThe_time);

void PoshDrawLine(float pAngle, br_pixelmap *pDestn, int pX1, int pY1, int pX2, int pY2, int pColour);

void DoInstruments(tU32 pThe_time);

void DoSteeringWheel(tU32 pThe_time);

void ChangingView();

void EarnCredits2(int pAmount, char *pPrefix_text);

void EarnCredits(int pAmount);

int SpendCredits(int pAmount);

void AwardTime(tU32 pTime);

void DrawRectangle(br_pixelmap *pPixelmap, int pLeft, int pTop, int pRight, int pBottom, int pColour);

void DrawRRectangle(br_pixelmap *pPixelmap, int pLeft, int pTop, int pRight, int pBottom, int pColour);

void OoerrIveGotTextInMeBoxMissus(int pFont_index, char *pText, br_pixelmap *pPixelmap, int pLeft, int pTop, int pRight, int pBottom, int pCentred);

void TransBrPixelmapText(br_pixelmap *pPixelmap, int pX, int pY, br_uint_32 pColour, br_font *pFont, signed char *pText);

void TransDRPixelmapText(br_pixelmap *pPixelmap, int pX, int pY, tDR_font *pFont, char *pText, int pRight_edge);

void TransDRPixelmapCleverText(br_pixelmap *pPixelmap, int pX, int pY, tDR_font *pFont, char *pText, int pRight_edge);

#endif
