#ifndef _DEPTH_H_
#define _DEPTH_H_

#include "br_types.h"
#include "dr_types.h"

// extern tDepth_effect(* hookvar_gDistance_depth_effects )[4];
extern int * hookvar_gSky_on ; // addr: 00513430
extern int * hookvar_gDepth_cueing_on ; // addr: 00513434
extern tDepth_effect_type * hookvar_gSwap_depth_effect_type ; // addr: 00513438
extern br_scalar * hookvar_gSky_height ; // addr: 00537930
extern br_scalar * hookvar_gSky_x_multiplier ; // addr: 0053794C
extern br_scalar * hookvar_gSky_width ; // addr: 00537944
extern br_scalar * hookvar_gSky_y_multiplier ; // addr: 00537950
// extern tU32 * hookvar_gLast_depth_change ;
extern br_scalar * hookvar_gOld_yon ; // addr: 00537934
extern br_pixelmap ** hookvar_gWater_shade_table ; // addr: 00550A68
extern br_material ** hookvar_gHorizon_material ; // addr: 0053795C
extern br_model ** hookvar_gRearview_sky_model ; // addr: 0053792C
extern int * hookvar_gFog_shade_table_power ; // addr: 00537924
extern br_actor ** hookvar_gRearview_sky_actor ; // addr: 0053793C
extern int * hookvar_gAcid_shade_table_power ; // addr: 00537958
extern int * hookvar_gWater_shade_table_power ; // addr: 00537948
extern br_model ** hookvar_gForward_sky_model ; // addr: 00537920
extern br_actor ** hookvar_gForward_sky_actor ; // addr: 00537954
extern int * hookvar_gDepth_shade_table_power ; // addr: 00537938
extern br_pixelmap ** hookvar_gFog_shade_table ; // addr: 00550A74
extern int * hookvar_gSwap_depth_effect_start ; // addr: 00550A80
extern br_pixelmap ** hookvar_gDepth_shade_table ; // addr: 00550A60
extern tSpecial_volume ** hookvar_gLast_camera_special_volume ; // addr: 00550A78
extern br_pixelmap ** hookvar_gAcid_shade_table ; // addr: 00550A64
extern int * hookvar_gSwap_depth_effect_end ; // addr: 00550A7C
extern br_pixelmap ** hookvar_gSwap_sky_texture ; // addr: 00550A5C
extern br_angle * hookvar_gOld_fov ; // addr: 00537928
extern br_angle * hookvar_gSky_image_width ; // addr: 00550A6E
extern br_angle * hookvar_gSky_image_height ; // addr: 00550A6C
extern br_angle * hookvar_gSky_image_underground ; // addr: 00550A70

int __cdecl Log2(int pNumber);

br_scalar __cdecl CalculateWrappingMultiplier(br_scalar pValue, br_scalar pYon);

br_scalar DepthCueingShiftToDistance(int pShift);

void FogAccordingToGPSCDE(br_material *pMaterial);

void FrobFog();

void __cdecl InstantDepthChange(tDepth_effect_type pType, br_pixelmap *pSky_texture, int pStart, int pEnd);

br_scalar __cdecl Tan(br_scalar pAngle);

br_scalar __cdecl EdgeU(br_angle pSky, br_angle pView, br_angle pPerfect);

void __cdecl MungeSkyModel(br_actor *pCamera, br_model *pModel);

br_model* __cdecl CreateHorizonModel(br_actor *pCamera);

void __cdecl LoadDepthTable(char *pName, br_pixelmap **pTable, int *pPower);

void __cdecl InitDepthEffects();

void __cdecl DoDepthByShadeTable(br_pixelmap *pRender_buffer, br_pixelmap *pDepth_buffer, br_pixelmap *pShade_table, int pShade_table_power, int pStart, int pEnd);

void __cdecl ExternalSky(br_pixelmap *pRender_buffer, br_pixelmap *pDepth_buffer, br_actor *pCamera, br_matrix34 *pCamera_to_world);

void __cdecl DoHorizon(br_pixelmap *pRender_buffer, br_pixelmap *pDepth_buffer, br_actor *pCamera, br_matrix34 *pCamera_to_world);

void __cdecl DoDepthCue(br_pixelmap *pRender_buffer, br_pixelmap *pDepth_buffer);

void __cdecl DoFog(br_pixelmap *pRender_buffer, br_pixelmap *pDepth_buffer);

void __cdecl DepthEffect(br_pixelmap *pRender_buffer, br_pixelmap *pDepth_buffer, br_actor *pCamera, br_matrix34 *pCamera_to_world);

void __cdecl DepthEffectSky(br_pixelmap *pRender_buffer, br_pixelmap *pDepth_buffer, br_actor *pCamera, br_matrix34 *pCamera_to_world);

void __cdecl DoWobbleCamera(br_actor *pCamera);

void __cdecl DoDrugWobbleCamera(br_actor *pCamera);

void __cdecl DoSpecialCameraEffect(br_actor *pCamera, br_matrix34 *pCamera_to_world);

void __cdecl LessDepthFactor();

void __cdecl MoreDepthFactor();

void __cdecl LessDepthFactor2();

void __cdecl MoreDepthFactor2();

void __cdecl AssertYons();

void __cdecl IncreaseYon();

void __cdecl DecreaseYon();

void __cdecl SetYon(br_scalar pYon);

br_scalar __cdecl GetYon();

void __cdecl IncreaseAngle();

void __cdecl DecreaseAngle();

void __cdecl ToggleDepthMode();

int __cdecl GetSkyTextureOn();

void __cdecl SetSkyTextureOn(int pOn);

void __cdecl ToggleSkyQuietly();

void __cdecl ToggleSky();

int __cdecl GetDepthCueingOn();

void __cdecl SetDepthCueingOn(int pOn);

void __cdecl ToggleDepthCueingQuietly();

void __cdecl ToggleDepthCueing();

void __cdecl ChangeDepthEffect();

void __cdecl MungeForwardSky();

void __cdecl MungeRearviewSky();

#endif
