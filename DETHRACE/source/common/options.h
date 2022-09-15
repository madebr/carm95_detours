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

void DoSoundOptions();

void GetGraphicsOptions();

void SetGraphicsOptions();

void PlayRadioOn2(int pIndex, int pValue);

void PlayRadioOff2(int pIndex, int pValue);

void PlayRadioOn__options(int pIndex, int pValue);

void PlayRadioOff__options(int pIndex, int pValue);

void DrawInitialRadios();

void RadioChanged(int pIndex, int pNew_value);

int GraphOptLeft(int *pCurrent_choice, int *pCurrent_mode);

int GraphOptRight(int *pCurrent_choice, int *pCurrent_mode);

int GraphOptUp(int *pCurrent_choice, int *pCurrent_mode);

int GraphOptDown(int *pCurrent_choice, int *pCurrent_mode);

int RadioClick(int *pCurrent_choice, int *pCurrent_mode, int pX_offset, int pY_offset);

int GraphOptGoAhead(int *pCurrent_choice, int *pCurrent_mode);

void PlotAGraphBox__options(int pIndex, int pColour_value);

void DrawAGraphBox__options(int pIndex);

void EraseAGraphBox__options(int pIndex);

void DrawGraphBox(int pCurrent_choice, int pCurrent_mode);

void DoGraphicsOptions();

void CalibrateJoysticks();

void StripControls(unsigned char *pStr);

void LoadKeyNames();

void DisposeKeyNames();

void SaveOrigKeyMapping();

void GetKeyCoords(int pIndex, int *pY, int *pName_x, int *pKey_x, int *pEnd_box);

void SetKeysToDefault();

void SaveKeyMapping();

void ChangeKeyMapIndex(int pNew_one);

void DrawKeyAssignments(int pCurrent_choice, int pCurrent_mode);

int KeyAssignLeft(int *pCurrent_choice, int *pCurrent_mode);

int KeyAssignRight(int *pCurrent_choice, int *pCurrent_mode);

int KeyAssignUp(int *pCurrent_choice, int *pCurrent_mode);

int KeyAssignDown(int *pCurrent_choice, int *pCurrent_mode);

int KeyAssignGoAhead(int *pCurrent_choice, int *pCurrent_mode);

int MouseyClickBastard(int *pCurrent_choice, int *pCurrent_mode, int pX_offset, int pY_offset);

void DrawInitialKMRadios();

void DoControlOptions();

void LoadSoundOptionsData();

void FreeSoundOptionsData();

void DrawDisabledOptions();

void DoOptions();

#endif
