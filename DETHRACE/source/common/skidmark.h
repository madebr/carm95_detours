#ifndef _SKIDMARK_H_
#define _SKIDMARK_H_

#include "br_types.h"
#include "dr_types.h"

// extern char *(* hookvar_gBoring_material_names )[2];
// extern char *(* hookvar_gMaterial_names )[2];
extern tSkid(* hookvar_gSkids )[100]; // addr: 00530190

void __cdecl StretchMark(tSkid *pMark, br_vector3 *pFrom, br_vector3 *pTo, br_scalar pTexture_start);

br_material* __cdecl MaterialFromIndex(int pIndex);

void __cdecl AdjustSkid(int pSkid_num, br_matrix34 *pMatrix, int pMaterial_index);

int __cdecl FarFromLine2D(br_vector3 *pPt, br_vector3 *pL1, br_vector3 *pL2);

int __cdecl Reflex2D(br_vector3 *pPt, br_vector3 *pL1, br_vector3 *pL2);

void __cdecl InitSkids();

void __cdecl HideSkid(int pSkid_num);

void __cdecl HideSkids();

br_scalar __cdecl SkidLen(int pSkid);

void SkidSection(tCar_spec *pCar, int pWheel_num, br_vector3 *pPos, int pMaterial_index);

void __cdecl SkidMark(tCar_spec *pCar, int pWheel_num);

void __cdecl InitCarSkidStuff(tCar_spec *pCar);

void __cdecl SkidsPerFrame();

void RemoveMaterialsFromSkidmarks();

#endif
