#ifndef _FLICPLAY_H_
#define _FLICPLAY_H_

#include "br_types.h"
#include "dr_types.h"

extern int * hookvar_gPalette_allocate_count ; // addr: 00514FA0
extern int * hookvar_gPalette_fuck_prevention ; // addr: 00514FA4
extern int * hookvar_gDark_mode ; // addr: 00514FA8
extern int * hookvar_gTransparency_on ; // addr: 00514FAC
extern int * hookvar_gPanel_flic_disable ; // addr: 00514FB0
extern int * hookvar_gPending_flic ; // addr: 00514FB4
extern int * hookvar_gPlay_from_disk ; // addr: 00514FB8
extern int * hookvar_gTrans_enabled ; // addr: 00514FBC
extern br_pixelmap *(* hookvar_gPanel_buffer )[2]; // addr: 00514FC0
extern tU32 * hookvar_gSound_time ; // addr: 00514FC8
extern tFlic_spec(* hookvar_gMain_flic_list )[372]; // addr: 00514FD0
extern int(* hookvar_gFlic_bunch0 )[29]; // addr: 00518420
extern int(* hookvar_gFlic_bunch1 )[31]; // addr: 00518498
extern int(* hookvar_gFlic_bunch2 )[8]; // addr: 00518518
extern int(* hookvar_gFlic_bunch3 )[13]; // addr: 00518538
extern int(* hookvar_gFlic_bunch4 )[22]; // addr: 00518570
extern int(* hookvar_gFlic_bunch5 )[5]; // addr: 005185C8
extern int(* hookvar_gFlic_bunch6 )[51]; // addr: 005185E0
extern int(* hookvar_gFlic_bunch7 )[7]; // addr: 005186B0
extern int(* hookvar_gFlic_bunch8 )[16]; // addr: 005186D0
extern tFlic_bunch(* hookvar_gFlic_bunch )[9]; // addr: 00518710
extern char(* hookvar_gLast_flic_name )[14]; // addr: 00518758
extern tU32(* hookvar_gPanel_flic_data_length )[2]; // addr: 0053D0B8
extern tU32(* hookvar_gLast_panel_frame_time )[2]; // addr: 0053D1B8
extern tU8 *(* hookvar_gPanel_flic_data )[2]; // addr: 0053D060
extern int(* hookvar_gPanel_flic_top )[2]; // addr: 0053D0C0
// extern tFlic_descriptor(* hookvar_gPanel_flic )[2];
extern int(* hookvar_gPanel_flic_left )[2]; // addr: 0053D0B0
extern int * hookvar_gPending_pending_flic ; // addr: 0053D0CC
extern int * hookvar_gSound_ID ; // addr: 0053D1C0
extern int * hookvar_gTranslation_count ; // addr: 0053D06C
extern tDR_font *(* hookvar_gTrans_fonts )[15]; // addr: 0053D070
extern tTranslation_record ** hookvar_gTranslations ; // addr: 0053D0D0
extern br_pixelmap ** hookvar_gPalette ; // addr: 0053D0C8
extern void ** hookvar_gPalette_pixels ; // addr: 0053D068
extern tFlic_descriptor ** hookvar_gFirst_flic ; // addr: 0053D0AC

void __cdecl EnableTranslationText();

void __cdecl DisableTranslationText();

void __cdecl SetFlicSound(int pSound_ID, tU32 pSound_time);

int __cdecl TranslationMode();

void __cdecl DontLetFlicFuckWithPalettes();

void __cdecl LetFlicFuckWithPalettes();

void __cdecl PlayFlicsInDarkness();

void __cdecl ReilluminateFlics();

void __cdecl TurnFlicTransparencyOn();

void __cdecl TurnFlicTransparencyOff();

void __cdecl PlayFlicsFromDisk();

void __cdecl PlayFlicsFromMemory();

int __cdecl FlicsPlayedFromDisk();

void __cdecl TurnOffPanelFlics();

void __cdecl TurnOnPanelFlics();

int __cdecl GetPanelFlicFrameIndex(int pIndex);

void __cdecl FlicPaletteAllocate();

void __cdecl AssertFlicPixelmap(tFlic_descriptor_ptr pFlic_info, br_pixelmap *pDest_pixelmap);

int __cdecl StartFlic(char *pFile_name, int pIndex, tFlic_descriptor_ptr pFlic_info, tU32 pSize, tS8 *pData_ptr, br_pixelmap *pDest_pixelmap, int pX_offset, int pY_offset, int pFrame_rate);

void __cdecl FreeFlicPaletteAllocate();

int __cdecl EndFlic(tFlic_descriptor_ptr pFlic_info);

void __cdecl DoColourMap(tFlic_descriptor_ptr pFlic_info, tU32 chunk_length);

void __cdecl DoDifferenceX(tFlic_descriptor *pFlic_info, tU32 chunk_length);

void __cdecl DoDifferenceTrans(tFlic_descriptor *pFlic_info, tU32 chunk_length);

void __cdecl DoColour256(tFlic_descriptor *pFlic_info, tU32 chunk_length);

void __cdecl DoDeltaTrans(tFlic_descriptor *pFlic_info, tU32 chunk_length);

void __cdecl DoDeltaX(tFlic_descriptor *pFlic_info, tU32 chunk_length);

void __cdecl DoBlack(tFlic_descriptor *pFlic_info, tU32 chunk_length);

void __cdecl DoRunLengthX(tFlic_descriptor *pFlic_info, tU32 chunk_length);

void __cdecl DoRunLengthTrans(tFlic_descriptor *pFlic_info, tU32 chunk_length);

void __cdecl DoUncompressed(tFlic_descriptor *pFlic_info, tU32 chunk_length);

void __cdecl DoUncompressedTrans(tFlic_descriptor *pFlic_info, tU32 chunk_length);

void __cdecl DoMini(tFlic_descriptor *pFlic_info, tU32 chunk_length);

void __cdecl DrawTranslations(tFlic_descriptor *pFlic_info, int pLast_frame);

int __cdecl PlayNextFlicFrame2(tFlic_descriptor *pFlic_info, int pPanel_flic);

int __cdecl PlayNextFlicFrame(tFlic_descriptor *pFlic_info);

int __cdecl PlayFlic(int pIndex, tU32 pSize, tS8 *pData_ptr, br_pixelmap *pDest_pixelmap, int pX_offset, int pY_offset, void(**DoPerFrame)(), int pInterruptable, int pFrame_rate);

void __cdecl SwapScreen();

void __cdecl ShowFlic(int pIndex);

void __cdecl InitFlics();

int __cdecl LoadFlic(int pIndex);

void __cdecl UnlockFlic(int pIndex);

int __cdecl LoadFlicData(char *pName, tU8 **pData, tU32 *pData_length);

void __cdecl FreeFlic(int pIndex);

void __cdecl ForceRunFlic(int pIndex);

void __cdecl RunFlicAt(int pIndex, int pX, int pY);

void __cdecl RunFlic(int pIndex);

void __cdecl PreloadBunchOfFlics(int pBunch_index);

void __cdecl UnlockBunchOfFlics(int pBunch_index);

void __cdecl FlushAllFlics(int pBunch_index);

void __cdecl InitFlicQueue();

int __cdecl FlicQueueFinished();

void __cdecl ProcessFlicQueue(tU32 pInterval);

void __cdecl FlushFlicQueue();

void __cdecl AddToFlicQueue(int pIndex, int pX, int pY, int pMust_finish);

void __cdecl InitialiseFlicPanel(int pIndex, int pLeft, int pTop, int pWidth, int pHeight);

void __cdecl DisposeFlicPanel(int pIndex);

void __cdecl ServicePanelFlics(int pCopy_to_buffer);

void __cdecl ChangePanelFlic(int pIndex, tU8 *pData, tU32 pData_length);

br_pixelmap* __cdecl GetPanelPixelmap(int pIndex);

void __cdecl LoadInterfaceStrings();

void __cdecl FlushInterfaceFonts();

void __cdecl SuspendPendingFlic();

void __cdecl ResumePendingFlic();

#endif
