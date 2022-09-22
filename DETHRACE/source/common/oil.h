#ifndef _OIL_H_
#define _OIL_H_

#include "br_types.h"
#include "dr_types.h"

extern char *(* hookvar_gOil_pixie_names )[1]; // addr: 00509A38
extern int * hookvar_gNext_oil_pixie ; // addr: 00509A3C
// extern br_scalar * hookvar_gZ_buffer_diff ;
// extern br_scalar * hookvar_gMin_z_diff ;
extern br_pixelmap *(* hookvar_gOil_pixies )[1]; // addr: 00551DC0
extern tOil_spill_info(* hookvar_gOily_spills )[15]; // addr: 00551DD0

void __cdecl InitOilSpills();

void __cdecl ResetOilSpills();

void __cdecl QueueOilSpill(tCar_spec *pCar);

int __cdecl OKToSpillOil(tOil_spill_info *pOil);

void __cdecl Vector3Interpolate(br_vector3 *pDst, br_vector3 *pFrom, br_vector3 *pTo, br_scalar pP);

void __cdecl EnsureGroundDetailVisible(br_vector3 *pNew_pos, br_vector3 *pGround_normal, br_vector3 *pOld_pos);

void __cdecl MungeOilsHeightAboveGround(tOil_spill_info *pOil);

void __cdecl MungeIndexedOilsHeightAboveGround(int pIndex);

void __cdecl SetInitialOilStuff(tOil_spill_info *pOil, br_model *pModel);

void __cdecl ProcessOilSpills(tU32 pFrame_period);

int __cdecl GetOilSpillCount();

void __cdecl GetOilSpillDetails(int pIndex, br_actor **pActor, br_scalar *pSize);

int __cdecl PointInSpill(br_vector3 *pV, int pSpill);

void __cdecl GetOilFrictionFactors(tCar_spec *pCar, br_scalar *pFl_factor, br_scalar *pFr_factor, br_scalar *pRl_factor, br_scalar *pRr_factor);

void __cdecl AdjustOilSpill(int pIndex, br_matrix34 *pMat, br_scalar pFull_size, br_scalar pGrow_rate, tU32 pSpill_time, tU32 pStop_time, tCar_spec *pCar, br_vector3 *pOriginal_pos, br_pixelmap *pPixelmap);

void __cdecl ReceivedOilSpill(tNet_contents *pContents);

#endif
