#ifndef _INTRFACE_H_
#define _INTRFACE_H_

#include "br_types.h"
#include "dr_types.h"

extern int(* hookvar_gDisabled_choices )[10]; // addr: 0053A4D8
extern int * hookvar_gCurrent_mode ; // addr: 0053A500
extern tU32 * hookvar_gStart_time ; // addr: 0053A508
extern int * hookvar_gCurrent_choice ; // addr: 0053A504
extern tInterface_spec ** hookvar_gSpec ; // addr: 0053A4C8
extern int * hookvar_gAlways_typing ; // addr: 0053A4D0
extern int * hookvar_gDisabled_count ; // addr: 0053A4CC

void SetAlwaysTyping();

void ClearAlwaysTyping();

int ChoiceDisabled(int pChoice);

void ResetInterfaceTimeout();

void ChangeSelection(tInterface_spec *pSpec, int *pOld_selection, int *pNew_selection, int pMode, int pSkip_disabled);

void RecopyAreas(tInterface_spec *pSpec, br_pixelmap **pCopy_areas);

void DisableChoice(int pChoice);

void EnableChoice(int pChoice);

int DoInterfaceScreen(tInterface_spec *pSpec, int pOptions, int pCurrent_choice);

void ChangeSelectionTo(int pNew_choice, int pNew_mode);

#endif
