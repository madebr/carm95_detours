#ifndef _OPTIONS_H_
#define _OPTIONS_H_

#include "br_types.h"
#include "dr_types.h"

extern int(* hookvar_gKey_defns )[18]; // addr: 00519AD8
extern tRadio_bastards(* hookvar_gRadio_bastards__options )[13]; // addr: 00519B20 // suffix added to avoid duplicate symbol
extern int * hookvar_gKey_count ; // addr: 0053D1D4
// extern int * hookvar_gLast_graph_sel__options ; // suffix added to avoid duplicate symbol
extern char *(* hookvar_gKey_names )[125]; // addr: 0053D2F0
extern int * hookvar_gPending_entry ; // addr: 0053D1D0
extern tInterface_spec ** hookvar_gThe_interface_spec__options ; // addr: 0053D2EC // suffix added to avoid duplicate symbol
extern int(* hookvar_gOrig_key_mapping )[67]; // addr: 0053D1E0
extern br_pixelmap ** hookvar_gDials_pix ; // addr: 0053D1D8
extern int * hookvar_gCurrent_key ; // addr: 0053D4E8

void DrawDial(int pWhich_one, int pWhich_stage);

void MoveDialFromTo(int pWhich_one, int pOld_stage, int pNew_stage);

void SoundOptionsStart();

int SoundOptionsDone(int pCurrent_choice, int pCurrent_mode, int pGo_ahead, int pEscaped, int pTimed_out);

int SoundOptionsLeft(int *pCurrent_choice, int *pCurrent_mode);

int SoundOptionsRight(int *pCurrent_choice, int *pCurrent_mode);

int SoundClick(int *pCurrent_choice, int *pCurrent_mode, int pX_offset, int pY_offset);

void __cdecl DoSoundOptions();

void __cdecl GetGraphicsOptions();

void __cdecl SetGraphicsOptions();

void __cdecl PlayRadioOn2(int pIndex, int pValue);

void __cdecl PlayRadioOff2(int pIndex, int pValue);

void __cdecl PlayRadioOn__options(int pIndex, int pValue);

void __cdecl PlayRadioOff__options(int pIndex, int pValue);

void __cdecl DrawInitialRadios();

void __cdecl RadioChanged(int pIndex, int pNew_value);

int __cdecl GraphOptLeft(int *pCurrent_choice, int *pCurrent_mode);

int __cdecl GraphOptRight(int *pCurrent_choice, int *pCurrent_mode);

int __cdecl GraphOptUp(int *pCurrent_choice, int *pCurrent_mode);

int __cdecl GraphOptDown(int *pCurrent_choice, int *pCurrent_mode);

int __cdecl RadioClick(int *pCurrent_choice, int *pCurrent_mode, int pX_offset, int pY_offset);

int __cdecl GraphOptGoAhead(int *pCurrent_choice, int *pCurrent_mode);

void __cdecl PlotAGraphBox__options(int pIndex, int pColour_value);

void __cdecl DrawAGraphBox__options(int pIndex);

void __cdecl EraseAGraphBox__options(int pIndex);

void __cdecl DrawGraphBox(int pCurrent_choice, int pCurrent_mode);

void __cdecl DoGraphicsOptions();

void __fastcall CalibrateJoysticks();

void __cdecl StripControls(unsigned char *pStr);

void __cdecl LoadKeyNames();

void __cdecl DisposeKeyNames();

void __cdecl SaveOrigKeyMapping();

void __cdecl GetKeyCoords(int pIndex, int *pY, int *pName_x, int *pKey_x, int *pEnd_box);

void __cdecl SetKeysToDefault();

void __cdecl SaveKeyMapping();

void __cdecl ChangeKeyMapIndex(int pNew_one);

void __cdecl DrawKeyAssignments(int pCurrent_choice, int pCurrent_mode);

int __cdecl KeyAssignLeft(int *pCurrent_choice, int *pCurrent_mode);

int __cdecl KeyAssignRight(int *pCurrent_choice, int *pCurrent_mode);

int __cdecl KeyAssignUp(int *pCurrent_choice, int *pCurrent_mode);

int __cdecl KeyAssignDown(int *pCurrent_choice, int *pCurrent_mode);

int __cdecl KeyAssignGoAhead(int *pCurrent_choice, int *pCurrent_mode);

int __cdecl MouseyClickBastard(int *pCurrent_choice, int *pCurrent_mode, int pX_offset, int pY_offset);

void __cdecl DrawInitialKMRadios();

void __cdecl DoControlOptions();

void __cdecl LoadSoundOptionsData();

void __cdecl FreeSoundOptionsData();

void __cdecl DrawDisabledOptions();

void __cdecl DoOptions();

#endif
