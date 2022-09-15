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

int Log2(int pNumber);

br_scalar CalculateWrappingMultiplier(br_scalar pValue, br_scalar pYon);

br_scalar DepthCueingShiftToDistance(int pShift);

void FogAccordingToGPSCDE(br_material *pMaterial);

void FrobFog();

void InstantDepthChange(tDepth_effect_type pType, br_pixelmap *pSky_texture, int pStart, int pEnd);

br_scalar Tan(br_scalar pAngle);

br_scalar EdgeU(br_angle pSky, br_angle pView, br_angle pPerfect);

void MungeSkyModel(br_actor *pCamera, br_model *pModel);

br_model* CreateHorizonModel(br_actor *pCamera);

void LoadDepthTable(char *pName, br_pixelmap **pTable, int *pPower);

void InitDepthEffects();

void DoDepthByShadeTable(br_pixelmap *pRender_buffer, br_pixelmap *pDepth_buffer, br_pixelmap *pShade_table, int pShade_table_power, int pStart, int pEnd);

void ExternalSky(br_pixelmap *pRender_buffer, br_pixelmap *pDepth_buffer, br_actor *pCamera, br_matrix34 *pCamera_to_world);

void DoHorizon(br_pixelmap *pRender_buffer, br_pixelmap *pDepth_buffer, br_actor *pCamera, br_matrix34 *pCamera_to_world);

void DoDepthCue(br_pixelmap *pRender_buffer, br_pixelmap *pDepth_buffer);

void DoFog(br_pixelmap *pRender_buffer, br_pixelmap *pDepth_buffer);

void DepthEffect(br_pixelmap *pRender_buffer, br_pixelmap *pDepth_buffer, br_actor *pCamera, br_matrix34 *pCamera_to_world);

void DepthEffectSky(br_pixelmap *pRender_buffer, br_pixelmap *pDepth_buffer, br_actor *pCamera, br_matrix34 *pCamera_to_world);

void DoWobbleCamera(br_actor *pCamera);

void DoDrugWobbleCamera(br_actor *pCamera);

void DoSpecialCameraEffect(br_actor *pCamera, br_matrix34 *pCamera_to_world);

void LessDepthFactor();

void MoreDepthFactor();

void LessDepthFactor2();

void MoreDepthFactor2();

void AssertYons();

void IncreaseYon();

void DecreaseYon();

void SetYon(br_scalar pYon);

br_scalar GetYon();

void IncreaseAngle();

void DecreaseAngle();

void ToggleDepthMode();

int GetSkyTextureOn();

void SetSkyTextureOn(int pOn);

void ToggleSkyQuietly();

void ToggleSky();

int GetDepthCueingOn();

void SetDepthCueingOn(int pOn);

void ToggleDepthCueingQuietly();

void ToggleDepthCueing();

void ChangeDepthEffect();

void MungeForwardSky();

void MungeRearviewSky();

#endif
