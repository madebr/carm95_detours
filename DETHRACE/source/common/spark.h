#ifndef _SPARK_H_
#define _SPARK_H_

#include "br_types.h"
#include "dr_types.h"

extern int * hookvar_gNext_spark ; // addr: 005149E8
extern int * hookvar_gSpark_flags ; // addr: 005149EC
extern int * hookvar_gNext_shrapnel ; // addr: 005149F0
extern int * hookvar_gShrapnel_flags ; // addr: 005149F4
extern br_model *(* hookvar_gShrapnel_model )[2]; // addr: 005149F8
extern int * hookvar_gSmoke_flags ; // addr: 00514A00
extern int * hookvar_gSmoke_num ; // addr: 00514A04
extern int * hookvar_gOffset ; // addr: 00514A08
extern int * hookvar_gColumn_flags ; // addr: 00514A0C
extern int * hookvar_gNext_column ; // addr: 00514A10
extern br_pixelmap ** hookvar_gBlack_smoke_shade_table ; // addr: 00514A14
extern br_pixelmap ** hookvar_gDark_smoke_shade_table ; // addr: 00514A18
extern br_pixelmap ** hookvar_gGrey_smoke_shade_table ; // addr: 00514A1C
extern int * hookvar_gSmoke_on ; // addr: 00514A20
extern int * hookvar_gNum_splash_types ; // addr: 00514A24
// extern int * hookvar_gIt_type ;
extern br_pixelmap ** hookvar_gIt_shade_table ; // addr: 00514A2C
extern br_pixelmap *** hookvar_gDust_table ; // addr: 00514A30
extern br_pixelmap *(* hookvar_gFlame_map )[20]; // addr: 00538618
// extern tBRender_smoke *(* hookvar_gBR_smoke_pointers )[30];
extern tSplash(* hookvar_gSplash )[32]; // addr: 00538298
extern br_material *(* hookvar_gSplash_material )[20]; // addr: 00538B00
extern tSmoke_column(* hookvar_gSmoke_column )[25]; // addr: 00538DE8
extern br_matrix4 * hookvar_gCameraToScreen ; // addr: 00538668
extern tSpark(* hookvar_gSparks )[32]; // addr: 005398D8
extern br_pixelmap *(* hookvar_gShade_list )[16]; // addr: 005509C0
extern tSmoke(* hookvar_gSmoke )[25]; // addr: 005386B0
extern tU32 * hookvar_gSplash_flags ; // addr: 0053A0E0
extern tU32 * hookvar_gNext_splash ; // addr: 0053828C
extern br_model ** hookvar_gLollipop_model ; // addr: 0053A0D8
extern int * hookvar_gNum_dust_tables ; // addr: 00538294
extern br_model ** hookvar_gSplash_model ; // addr: 005386A8
extern int * hookvar_gDust_rotate ; // addr: 0053A0DC
extern br_camera ** hookvar_gSpark_cam ; // addr: 00538290
extern br_material ** hookvar_gBlack_material ; // addr: 00538288
extern tShrapnel(* hookvar_gShrapnel )[15]; // addr: 00538B50

void DrawDot(br_scalar z, tU8 *scr_ptr, tU16 *depth_ptr, tU8 *shade_ptr);

void SetWorldToScreen(br_pixelmap *pScreen);

void DrawLine3DThroughBRender(br_vector3 *pStart, br_vector3 *pEnd);

int DrawLine3D(br_vector3 *start, br_vector3 *end, br_pixelmap *pScreen, br_pixelmap *pDepth_buffer, br_pixelmap *shade_table);

int DrawLine2D(br_vector3 *o, br_vector3 *p, br_pixelmap *pScreen, br_pixelmap *pDepth_buffer, br_scalar brightness, br_pixelmap *shade_table);

void SetLineModelCols(tU8 pCol);

void ReplaySparks(br_pixelmap *pRender_screen, br_pixelmap *pDepth_buffer, br_actor *pCamera, tU32 pTime);

void RenderSparks(br_pixelmap *pRender_screen, br_pixelmap *pDepth_buffer, br_actor *pCamera, br_matrix34 *pCamera_to_world, tU32 pTime);

void CreateSingleSpark(tCar_spec *pCar, br_vector3 *pPos, br_vector3 *pVel);

void CreateSparks(br_vector3 *pos, br_vector3 *v, br_vector3 *pForce, br_scalar sparkiness, tCar_spec *pCar);

void CreateSparkShower(br_vector3 *pos, br_vector3 *v, br_vector3 *pForce, tCar_spec *pCar1, tCar_spec *pCar2);

void AdjustSpark(int pSpark_num, br_vector3 *pos, br_vector3 *length);

void AdjustShrapnel(int pShrapnel_num, br_vector3 *pos, tU16 pAge, br_material *pMaterial);

void ResetSparks();

void ResetShrapnel();

void CreateShrapnelShower(br_vector3 *pos, br_vector3 *v, br_vector3 *pNormal, br_scalar pForce, tCar_spec *c1, tCar_spec *c2);

br_scalar random();

void InitShrapnel();

void LoadInShrapnel();

void KillShrapnel(int i);

void DisposeShrapnel();

void ReplayShrapnel(tU32 pTime);

void MungeShrapnel(tU32 pTime);

void DrMatrix34Rotate(br_matrix34 *mat, br_angle r, br_vector3 *a);

void SmokeLine(int l, int x, br_scalar zbuff, int r_squared, tU8 *scr_ptr, tU16 *depth_ptr, tU8 *shade_ptr, br_scalar r_multiplier, br_scalar z_multiplier, br_scalar shade_offset);

void SmokeCircle(br_vector3 *o, br_scalar r, br_scalar extra_z, br_scalar strength, br_scalar pAspect, br_pixelmap *pRender_screen, br_pixelmap *pDepth_buffer, br_pixelmap *pShade_table);

int CmpSmokeZ(void *p1, void *p2);

void RenderRecordedSmokeCircles();

void RecordSmokeCircle(br_vector3 *pCent, br_scalar pR, br_scalar pStrength, br_pixelmap *pShade, br_scalar pAspect);

void SmokeCircle3D(br_vector3 *o, br_scalar r, br_scalar strength, br_scalar pAspect, br_pixelmap *pRender_screen, br_pixelmap *pDepth_buffer, br_pixelmap *pShade_table, br_actor *pCam);

void ReplaySmoke(br_pixelmap *pRender_screen, br_pixelmap *pDepth_buffer, br_actor *pCamera);

void GenerateContinuousSmoke(tCar_spec *pCar, int wheel, tU32 pTime);

void DustRotate();

void RenderSmoke(br_pixelmap *pRender_screen, br_pixelmap *pDepth_buffer, br_actor *pCamera, br_matrix34 *pCamera_to_world, tU32 pTime);

void CreatePuffOfSmoke(br_vector3 *pos, br_vector3 *v, br_scalar strength, br_scalar pDecay_factor, int pType, tCar_spec *pC);

void ResetSmoke();

void AdjustSmoke(int pIndex, tU8 pType, br_vector3 *pPos, br_scalar pRadius, br_scalar pStrength);

void ActorError();

void AdjustSmokeColumn(int pIndex, tCar_spec *pCar, int pVertex, int pColour);

void CreateSmokeColumn(tCar_spec *pCar, int pColour, int pVertex_index, tU32 pLifetime);

void GenerateSmokeShades();

void GenerateItFoxShadeTable();

void AdjustFlame(int pIndex, int pFrame_count, br_scalar pScale_x, br_scalar pScale_y, br_scalar pOffset_x, br_scalar pOffset_z);

void ReplayFlame(tSmoke_column *col, br_actor *actor);

void FlameAnimate(int c, br_vector3 *pPos, tU32 pTime);

void DoSmokeColumn(int i, tU32 pTime, br_vector3 *pRet_car_pos);

void ReplaySmokeColumn(tU32 pTime);

void MungeSmokeColumn(tU32 pTime);

void DisposeFlame();

void InitFlame();

void InitSplash(FILE *pF);

void DisposeSplash();

void DrawTheGlow(br_pixelmap *pRender_screen, br_pixelmap *pDepth_buffer, br_actor *pCamera);

void PipeInstantUnSmudge(tCar_spec *pCar);

void SmudgeCar(tCar_spec *pCar, int fire_point);

void ResetSmokeColumns();

void SetSmokeOn(int pSmoke_on);

void ReallySetSmokeOn(int pSmoke_on);

void SetSmoke(int pSmoke_on);

int GetSmokeOn();

void StopCarSmoking(tCar_spec *pCar);

void StopCarSmokingInstantly(tCar_spec *pCar);

void ConditionalSmokeColumn(tCar_spec *pCar, int pDamage_index, int pColour);

void SingleSplash(tCar_spec *pCar, br_vector3 *sp, br_vector3 *normal, tU32 pTime);

void CreateSplash(tCar_spec *pCar, tU32 pTime);

void MungeSplash(tU32 pTime);

void RenderSplashes();

void GetSmokeShadeTables(FILE *f);

void FreeSmokeShadeTables();

void LoadInKevStuff(FILE *pF);

void DisposeKevStuff();

void DisposeKevStuffCar(tCar_spec *pCar);

void DoTrueColModelThing(br_actor *actor, br_model *pModel, br_material *material, void *render_data, br_uint_8 style, int on_screen);

void DoModelThing(br_actor *actor, br_model *pModel, br_material *material, void *render_data, br_uint_8 style, int on_screen);

void SetModelShade(br_actor *pActor, br_pixelmap *pShade);

void MakeCarIt(tCar_spec *pCar);

void StopCarBeingIt(tCar_spec *pCar);

#endif
