#ifndef _BRUCETRK_H_
#define _BRUCETRK_H_

#include "br_types.h"
#include "dr_types.h"

extern br_actor ** hookvar_gMr_blendy ; // addr: 0053E488
extern int * hookvar_gDefault_blend_pc ; // addr: 00550244

void __cdecl AllocateActorMatrix(tTrack_spec *pTrack_spec, br_actor ****pDst);

void __cdecl DisposeActorMatrix(tTrack_spec *pTrack_spec, br_actor ****pVictim, int pRemove_act_mod);

void __cdecl DisposeColumns(tTrack_spec *pTrack_spec);

void __cdecl XZToColumnXZ(tU8 *pColumn_x, tU8 *pColumn_z, br_scalar pX, br_scalar pZ, tTrack_spec *pTrack_spec);

void __cdecl StripBlendedFaces(br_actor *pActor, br_model *pModel);

br_uint_32 __cdecl FindNonCarsCB(br_actor *pActor, tTrack_spec *pTrack_spec);

br_uint_32 __cdecl ProcessModelsCB(br_actor *pActor, tTrack_spec *pTrack_spec);

void __cdecl ProcessModels(tTrack_spec *pTrack_spec);

void __cdecl ExtractColumns(tTrack_spec *pTrack_spec);

void LollipopizeActor4(br_actor *pActor, br_matrix34 *pRef_to_world, br_actor *pCamera);

br_uint_32 LollipopizeChildren(br_actor *pActor, void *pArg);

void __cdecl DrawColumns(int pDraw_blends, tTrack_spec *pTrack_spec, int pMin_x, int pMax_x, int pMin_z, int pMax_z, br_matrix34 *pCamera_to_world);

void __cdecl RenderTrack(br_actor *pWorld, tTrack_spec *pTrack_spec, br_actor *pCamera, br_matrix34 *pCamera_to_world, int pRender_blends);

br_scalar __cdecl GetYonFactor();

void __cdecl SetYonFactor(br_scalar pNew);

#endif
