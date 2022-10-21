#include "depth.h"

#include "harness/trace.h"

#include "carm95_hooks.h"

#include "carm95_webserver.h"

#include <assert.h>
#if 0
tDepth_effect(* hookvar_gDistance_depth_effects )[4];
#endif
int * hookvar_gSky_on  = (void*)0x00513430;
int * hookvar_gDepth_cueing_on  = (void*)0x00513434;
tDepth_effect_type * hookvar_gSwap_depth_effect_type  = (void*)0x00513438;
br_scalar * hookvar_gSky_height  = (void*)0x00537930;
br_scalar * hookvar_gSky_x_multiplier  = (void*)0x0053794c;
br_scalar * hookvar_gSky_width  = (void*)0x00537944;
br_scalar * hookvar_gSky_y_multiplier  = (void*)0x00537950;
#if 0
tU32 * hookvar_gLast_depth_change ;
#endif
br_scalar * hookvar_gOld_yon  = (void*)0x00537934;
br_pixelmap ** hookvar_gWater_shade_table  = (void*)0x00550a68;
br_material ** hookvar_gHorizon_material  = (void*)0x0053795c;
br_model ** hookvar_gRearview_sky_model  = (void*)0x0053792c;
int * hookvar_gFog_shade_table_power  = (void*)0x00537924;
br_actor ** hookvar_gRearview_sky_actor  = (void*)0x0053793c;
int * hookvar_gAcid_shade_table_power  = (void*)0x00537958;
int * hookvar_gWater_shade_table_power  = (void*)0x00537948;
br_model ** hookvar_gForward_sky_model  = (void*)0x00537920;
br_actor ** hookvar_gForward_sky_actor  = (void*)0x00537954;
int * hookvar_gDepth_shade_table_power  = (void*)0x00537938;
br_pixelmap ** hookvar_gFog_shade_table  = (void*)0x00550a74;
int * hookvar_gSwap_depth_effect_start  = (void*)0x00550a80;
br_pixelmap ** hookvar_gDepth_shade_table  = (void*)0x00550a60;
tSpecial_volume ** hookvar_gLast_camera_special_volume  = (void*)0x00550a78;
br_pixelmap ** hookvar_gAcid_shade_table  = (void*)0x00550a64;
int * hookvar_gSwap_depth_effect_end  = (void*)0x00550a7c;
br_pixelmap ** hookvar_gSwap_sky_texture  = (void*)0x00550a5c;
br_angle * hookvar_gOld_fov  = (void*)0x00537928;
br_angle * hookvar_gSky_image_width  = (void*)0x00550a6e;
br_angle * hookvar_gSky_image_height  = (void*)0x00550a6c;
br_angle * hookvar_gSky_image_underground  = (void*)0x00550a70;

function_hook_state_t function_hook_state_Log2 = HOOK_UNAVAILABLE;
static int(__cdecl*original_Log2)(int) = (int(__cdecl*)(int))0x00461e02;
CARM95_HOOK_FUNCTION(original_Log2, Log2)
int __cdecl Log2(int pNumber) {
    int i;
    int bits[16];
    LOG_TRACE("(%d)", pNumber);

    (void)pNumber;
    (void)i;
    (void)bits;

    if (function_hook_state_Log2 == HOOK_ENABLED) {
        assert(0 && "Log2 not implemented.");
        abort();
    } else {
        return original_Log2(pNumber);
    }
}

function_hook_state_t function_hook_state_CalculateWrappingMultiplier = HOOK_UNAVAILABLE;
static br_scalar(__cdecl*original_CalculateWrappingMultiplier)(br_scalar, br_scalar) = (br_scalar(__cdecl*)(br_scalar, br_scalar))0x00462ebc;
CARM95_HOOK_FUNCTION(original_CalculateWrappingMultiplier, CalculateWrappingMultiplier)
br_scalar __cdecl CalculateWrappingMultiplier(br_scalar pValue, br_scalar pYon) {
    br_scalar k;
    br_scalar trunc_k;
    int int_k;
    LOG_TRACE("(%f, %f)", pValue, pYon);

    (void)pValue;
    (void)pYon;
    (void)k;
    (void)trunc_k;
    (void)int_k;

    if (function_hook_state_CalculateWrappingMultiplier == HOOK_ENABLED) {
        assert(0 && "CalculateWrappingMultiplier not implemented.");
        abort();
    } else {
        return original_CalculateWrappingMultiplier(pValue, pYon);
    }
}

function_hook_state_t function_hook_state_DepthCueingShiftToDistance = HOOK_UNAVAILABLE;
br_scalar DepthCueingShiftToDistance(int pShift) {
    LOG_TRACE("(%d)", pShift);

    (void)pShift;

    if (function_hook_state_DepthCueingShiftToDistance == HOOK_ENABLED) {
        assert(0 && "DepthCueingShiftToDistance not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}

function_hook_state_t function_hook_state_FogAccordingToGPSCDE = HOOK_UNAVAILABLE;
void FogAccordingToGPSCDE(br_material *pMaterial) {
    int start;
    int end;
    LOG_TRACE("(%p)", pMaterial);

    (void)pMaterial;
    (void)start;
    (void)end;

    if (function_hook_state_FogAccordingToGPSCDE == HOOK_ENABLED) {
        assert(0 && "FogAccordingToGPSCDE not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}

function_hook_state_t function_hook_state_FrobFog = HOOK_UNAVAILABLE;
void FrobFog() {
    int i;
    br_material *mat;
    LOG_TRACE("()");

    (void)i;
    (void)mat;

    if (function_hook_state_FrobFog == HOOK_ENABLED) {
        assert(0 && "FrobFog not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}

function_hook_state_t function_hook_state_InstantDepthChange = HOOK_UNAVAILABLE;
static void(__cdecl*original_InstantDepthChange)(tDepth_effect_type, br_pixelmap *, int, int) = (void(__cdecl*)(tDepth_effect_type, br_pixelmap *, int, int))0x00461670;
CARM95_HOOK_FUNCTION(original_InstantDepthChange, InstantDepthChange)
void __cdecl InstantDepthChange(tDepth_effect_type pType, br_pixelmap *pSky_texture, int pStart, int pEnd) {
    LOG_TRACE("(%d, %p, %d, %d)", pType, pSky_texture, pStart, pEnd);

    (void)pType;
    (void)pSky_texture;
    (void)pStart;
    (void)pEnd;

    if (function_hook_state_InstantDepthChange == HOOK_ENABLED) {
        assert(0 && "InstantDepthChange not implemented.");
        abort();
    } else {
        original_InstantDepthChange(pType, pSky_texture, pStart, pEnd);
    }
}

function_hook_state_t function_hook_state_Tan = HOOK_UNAVAILABLE;
static br_scalar(__cdecl*original_Tan)(br_scalar) = (br_scalar(__cdecl*)(br_scalar))0x00462226;
CARM95_HOOK_FUNCTION(original_Tan, Tan)
br_scalar __cdecl Tan(br_scalar pAngle) {
    LOG_TRACE("(%f)", pAngle);

    (void)pAngle;

    if (function_hook_state_Tan == HOOK_ENABLED) {
        assert(0 && "Tan not implemented.");
        abort();
    } else {
        return original_Tan(pAngle);
    }
}

function_hook_state_t function_hook_state_EdgeU = HOOK_UNAVAILABLE;
static br_scalar(__cdecl*original_EdgeU)(br_angle, br_angle, br_angle) = (br_scalar(__cdecl*)(br_angle, br_angle, br_angle))0x00462f34;
CARM95_HOOK_FUNCTION(original_EdgeU, EdgeU)
br_scalar __cdecl EdgeU(br_angle pSky, br_angle pView, br_angle pPerfect) {
    br_scalar a;
    br_scalar b;
    br_scalar c;
    LOG_TRACE("(%u, %u, %u)", pSky, pView, pPerfect);

    (void)pSky;
    (void)pView;
    (void)pPerfect;
    (void)a;
    (void)b;
    (void)c;

    if (function_hook_state_EdgeU == HOOK_ENABLED) {
        assert(0 && "EdgeU not implemented.");
        abort();
    } else {
        return original_EdgeU(pSky, pView, pPerfect);
    }
}

function_hook_state_t function_hook_state_MungeSkyModel = HOOK_UNAVAILABLE;
static void(__cdecl*original_MungeSkyModel)(br_actor *, br_model *) = (void(__cdecl*)(br_actor *, br_model *))0x0046280d;
CARM95_HOOK_FUNCTION(original_MungeSkyModel, MungeSkyModel)
void __cdecl MungeSkyModel(br_actor *pCamera, br_model *pModel) {
    br_camera *camera_data;
    br_scalar horizon_half_height;
    br_scalar horizon_half_width;
    br_scalar horizon_half_diag;
    br_scalar tan_half_fov;
    br_scalar sky_distance;
    br_angle half_hori_fov;
    br_angle half_diag_fov;
    tU8 nbands;
    tU8 band;
    tU8 vertex;
    tU8 stripe;
    br_scalar edge_u;
    br_scalar narrow_u;
    br_angle min_angle;
    br_angle angle_range;
    br_angle angle;
    LOG_TRACE("(%p, %p)", pCamera, pModel);

    (void)pCamera;
    (void)pModel;
    (void)camera_data;
    (void)horizon_half_height;
    (void)horizon_half_width;
    (void)horizon_half_diag;
    (void)tan_half_fov;
    (void)sky_distance;
    (void)half_hori_fov;
    (void)half_diag_fov;
    (void)nbands;
    (void)band;
    (void)vertex;
    (void)stripe;
    (void)edge_u;
    (void)narrow_u;
    (void)min_angle;
    (void)angle_range;
    (void)angle;

    if (function_hook_state_MungeSkyModel == HOOK_ENABLED) {
        assert(0 && "MungeSkyModel not implemented.");
        abort();
    } else {
        original_MungeSkyModel(pCamera, pModel);
    }
}

function_hook_state_t function_hook_state_CreateHorizonModel = HOOK_UNAVAILABLE;
static br_model *(__cdecl*original_CreateHorizonModel)(br_actor *) = (br_model *(__cdecl*)(br_actor *))0x0046194b;
CARM95_HOOK_FUNCTION(original_CreateHorizonModel, CreateHorizonModel)
br_model* __cdecl CreateHorizonModel(br_actor *pCamera) {
    tU8 nbands;
    tU8 band;
    tU8 vertex;
    tU8 stripe;
    br_model *model;
    LOG_TRACE("(%p)", pCamera);

    (void)pCamera;
    (void)nbands;
    (void)band;
    (void)vertex;
    (void)stripe;
    (void)model;

    if (function_hook_state_CreateHorizonModel == HOOK_ENABLED) {
        assert(0 && "CreateHorizonModel not implemented.");
        abort();
    } else {
        return original_CreateHorizonModel(pCamera);
    }
}

function_hook_state_t function_hook_state_LoadDepthTable = HOOK_UNAVAILABLE;
static void(__cdecl*original_LoadDepthTable)(char *, br_pixelmap **, int *) = (void(__cdecl*)(char *, br_pixelmap **, int *))0x00461c9b;
CARM95_HOOK_FUNCTION(original_LoadDepthTable, LoadDepthTable)
void __cdecl LoadDepthTable(char *pName, br_pixelmap **pTable, int *pPower) {
    tPath_name the_path;
    int i;
    int j;
    tU8 temp;
    LOG_TRACE("(\"%s\", %p, %p)", pName, pTable, pPower);

    (void)pName;
    (void)pTable;
    (void)pPower;
    (void)the_path;
    (void)i;
    (void)j;
    (void)temp;

    if (function_hook_state_LoadDepthTable == HOOK_ENABLED) {
        assert(0 && "LoadDepthTable not implemented.");
        abort();
    } else {
        original_LoadDepthTable(pName, pTable, pPower);
    }
}

function_hook_state_t function_hook_state_InitDepthEffects = HOOK_UNAVAILABLE;
static void(__cdecl*original_InitDepthEffects)() = (void(__cdecl*)())0x004616f2;
CARM95_HOOK_FUNCTION(original_InitDepthEffects, InitDepthEffects)
void __cdecl InitDepthEffects() {
    tPath_name the_path;
    int i;
    int j;
    LOG_TRACE("()");

    (void)the_path;
    (void)i;
    (void)j;

    if (function_hook_state_InitDepthEffects == HOOK_ENABLED) {
        assert(0 && "InitDepthEffects not implemented.");
        abort();
    } else {
        original_InitDepthEffects();
    }
}

function_hook_state_t function_hook_state_DoDepthByShadeTable = HOOK_UNAVAILABLE;
static void(__cdecl*original_DoDepthByShadeTable)(br_pixelmap *, br_pixelmap *, br_pixelmap *, int, int, int) = (void(__cdecl*)(br_pixelmap *, br_pixelmap *, br_pixelmap *, int, int, int))0x004622cc;
CARM95_HOOK_FUNCTION(original_DoDepthByShadeTable, DoDepthByShadeTable)
void __cdecl DoDepthByShadeTable(br_pixelmap *pRender_buffer, br_pixelmap *pDepth_buffer, br_pixelmap *pShade_table, int pShade_table_power, int pStart, int pEnd) {
    tU8 *render_ptr;
    tU8 *shade_table_pixels;
    tU16 *depth_ptr;
    tU16 depth_value;
    tU16 too_near;
    int depth_shift_amount;
    int depth_start;
    int y;
    int x;
    int depth_line_skip;
    int render_line_skip;
    LOG_TRACE("(%p, %p, %p, %d, %d, %d)", pRender_buffer, pDepth_buffer, pShade_table, pShade_table_power, pStart, pEnd);

    (void)pRender_buffer;
    (void)pDepth_buffer;
    (void)pShade_table;
    (void)pShade_table_power;
    (void)pStart;
    (void)pEnd;
    (void)render_ptr;
    (void)shade_table_pixels;
    (void)depth_ptr;
    (void)depth_value;
    (void)too_near;
    (void)depth_shift_amount;
    (void)depth_start;
    (void)y;
    (void)x;
    (void)depth_line_skip;
    (void)render_line_skip;

    if (function_hook_state_DoDepthByShadeTable == HOOK_ENABLED) {
        assert(0 && "DoDepthByShadeTable not implemented.");
        abort();
    } else {
        original_DoDepthByShadeTable(pRender_buffer, pDepth_buffer, pShade_table, pShade_table_power, pStart, pEnd);
    }
}

function_hook_state_t function_hook_state_ExternalSky = HOOK_UNAVAILABLE;
static void(__cdecl*original_ExternalSky)(br_pixelmap *, br_pixelmap *, br_actor *, br_matrix34 *) = (void(__cdecl*)(br_pixelmap *, br_pixelmap *, br_actor *, br_matrix34 *))0x00461ebd;
CARM95_HOOK_FUNCTION(original_ExternalSky, ExternalSky)
void __cdecl ExternalSky(br_pixelmap *pRender_buffer, br_pixelmap *pDepth_buffer, br_actor *pCamera, br_matrix34 *pCamera_to_world) {
    int dst_x;
    int src_x;
    int dx;
    int hori_y;
    int top_y;
    int hori_pixels;
    br_angle yaw;
    br_angle hori_sky;
    br_angle pitch;
    br_angle vert_sky;
    br_camera *camera;
    br_scalar tan_half_fov;
    br_scalar tan_half_hori_fov;
    br_scalar tan_half_hori_sky;
    br_scalar hshift;
    br_scalar tan_pitch;
    tU8 top_col;
    tU8 bot_col;
    int bot_height;
    int repetitions;
    br_pixelmap *col_map;
    LOG_TRACE("(%p, %p, %p, %p)", pRender_buffer, pDepth_buffer, pCamera, pCamera_to_world);

    (void)pRender_buffer;
    (void)pDepth_buffer;
    (void)pCamera;
    (void)pCamera_to_world;
    (void)dst_x;
    (void)src_x;
    (void)dx;
    (void)hori_y;
    (void)top_y;
    (void)hori_pixels;
    (void)yaw;
    (void)hori_sky;
    (void)pitch;
    (void)vert_sky;
    (void)camera;
    (void)tan_half_fov;
    (void)tan_half_hori_fov;
    (void)tan_half_hori_sky;
    (void)hshift;
    (void)tan_pitch;
    (void)top_col;
    (void)bot_col;
    (void)bot_height;
    (void)repetitions;
    (void)col_map;

    if (function_hook_state_ExternalSky == HOOK_ENABLED) {
        assert(0 && "ExternalSky not implemented.");
        abort();
    } else {
        original_ExternalSky(pRender_buffer, pDepth_buffer, pCamera, pCamera_to_world);
    }
}

function_hook_state_t function_hook_state_DoHorizon = HOOK_UNAVAILABLE;
static void(__cdecl*original_DoHorizon)(br_pixelmap *, br_pixelmap *, br_actor *, br_matrix34 *) = (void(__cdecl*)(br_pixelmap *, br_pixelmap *, br_actor *, br_matrix34 *))0x00462658;
CARM95_HOOK_FUNCTION(original_DoHorizon, DoHorizon)
void __cdecl DoHorizon(br_pixelmap *pRender_buffer, br_pixelmap *pDepth_buffer, br_actor *pCamera, br_matrix34 *pCamera_to_world) {
    br_angle yaw;
    br_actor *actor;
    LOG_TRACE("(%p, %p, %p, %p)", pRender_buffer, pDepth_buffer, pCamera, pCamera_to_world);

    (void)pRender_buffer;
    (void)pDepth_buffer;
    (void)pCamera;
    (void)pCamera_to_world;
    (void)yaw;
    (void)actor;

    if (function_hook_state_DoHorizon == HOOK_ENABLED) {
        assert(0 && "DoHorizon not implemented.");
        abort();
    } else {
        original_DoHorizon(pRender_buffer, pDepth_buffer, pCamera, pCamera_to_world);
    }
}

function_hook_state_t function_hook_state_DoDepthCue = HOOK_UNAVAILABLE;
static void(__cdecl*original_DoDepthCue)(br_pixelmap *, br_pixelmap *) = (void(__cdecl*)(br_pixelmap *, br_pixelmap *))0x00462299;
CARM95_HOOK_FUNCTION(original_DoDepthCue, DoDepthCue)
void __cdecl DoDepthCue(br_pixelmap *pRender_buffer, br_pixelmap *pDepth_buffer) {
    LOG_TRACE("(%p, %p)", pRender_buffer, pDepth_buffer);

    (void)pRender_buffer;
    (void)pDepth_buffer;

    if (function_hook_state_DoDepthCue == HOOK_ENABLED) {
        assert(0 && "DoDepthCue not implemented.");
        abort();
    } else {
        original_DoDepthCue(pRender_buffer, pDepth_buffer);
    }
}

function_hook_state_t function_hook_state_DoFog = HOOK_UNAVAILABLE;
static void(__cdecl*original_DoFog)(br_pixelmap *, br_pixelmap *) = (void(__cdecl*)(br_pixelmap *, br_pixelmap *))0x004625d6;
CARM95_HOOK_FUNCTION(original_DoFog, DoFog)
void __cdecl DoFog(br_pixelmap *pRender_buffer, br_pixelmap *pDepth_buffer) {
    LOG_TRACE("(%p, %p)", pRender_buffer, pDepth_buffer);

    (void)pRender_buffer;
    (void)pDepth_buffer;

    if (function_hook_state_DoFog == HOOK_ENABLED) {
        assert(0 && "DoFog not implemented.");
        abort();
    } else {
        original_DoFog(pRender_buffer, pDepth_buffer);
    }
}

function_hook_state_t function_hook_state_DepthEffect = HOOK_UNAVAILABLE;
static void(__cdecl*original_DepthEffect)(br_pixelmap *, br_pixelmap *, br_actor *, br_matrix34 *) = (void(__cdecl*)(br_pixelmap *, br_pixelmap *, br_actor *, br_matrix34 *))0x00462254;
CARM95_HOOK_FUNCTION(original_DepthEffect, DepthEffect)
void __cdecl DepthEffect(br_pixelmap *pRender_buffer, br_pixelmap *pDepth_buffer, br_actor *pCamera, br_matrix34 *pCamera_to_world) {
    LOG_TRACE("(%p, %p, %p, %p)", pRender_buffer, pDepth_buffer, pCamera, pCamera_to_world);

    (void)pRender_buffer;
    (void)pDepth_buffer;
    (void)pCamera;
    (void)pCamera_to_world;

    if (function_hook_state_DepthEffect == HOOK_ENABLED) {
        assert(0 && "DepthEffect not implemented.");
        abort();
    } else {
        original_DepthEffect(pRender_buffer, pDepth_buffer, pCamera, pCamera_to_world);
    }
}

function_hook_state_t function_hook_state_DepthEffectSky = HOOK_UNAVAILABLE;
static void(__cdecl*original_DepthEffectSky)(br_pixelmap *, br_pixelmap *, br_actor *, br_matrix34 *) = (void(__cdecl*)(br_pixelmap *, br_pixelmap *, br_actor *, br_matrix34 *))0x00462609;
CARM95_HOOK_FUNCTION(original_DepthEffectSky, DepthEffectSky)
void __cdecl DepthEffectSky(br_pixelmap *pRender_buffer, br_pixelmap *pDepth_buffer, br_actor *pCamera, br_matrix34 *pCamera_to_world) {
    LOG_TRACE("(%p, %p, %p, %p)", pRender_buffer, pDepth_buffer, pCamera, pCamera_to_world);

    (void)pRender_buffer;
    (void)pDepth_buffer;
    (void)pCamera;
    (void)pCamera_to_world;

    if (function_hook_state_DepthEffectSky == HOOK_ENABLED) {
        assert(0 && "DepthEffectSky not implemented.");
        abort();
    } else {
        original_DepthEffectSky(pRender_buffer, pDepth_buffer, pCamera, pCamera_to_world);
    }
}

function_hook_state_t function_hook_state_DoWobbleCamera = HOOK_UNAVAILABLE;
static void(__cdecl*original_DoWobbleCamera)(br_actor *) = (void(__cdecl*)(br_actor *))0x00463066;
CARM95_HOOK_FUNCTION(original_DoWobbleCamera, DoWobbleCamera)
void __cdecl DoWobbleCamera(br_actor *pCamera) {
    float f_time;
    static br_scalar mag00;
    static br_scalar mag01;
    static br_scalar mag02;
    static br_scalar mag10;
    static br_scalar mag11;
    static br_scalar mag12;
    static br_scalar mag20;
    static br_scalar mag21;
    static br_scalar mag22;
    static float period00;
    static float period01;
    static float period02;
    static float period10;
    static float period11;
    static float period12;
    static float period20;
    static float period21;
    static float period22;
    LOG_TRACE("(%p)", pCamera);

    (void)pCamera;
    (void)f_time;
    (void)mag00;
    (void)mag01;
    (void)mag02;
    (void)mag10;
    (void)mag11;
    (void)mag12;
    (void)mag20;
    (void)mag21;
    (void)mag22;
    (void)period00;
    (void)period01;
    (void)period02;
    (void)period10;
    (void)period11;
    (void)period12;
    (void)period20;
    (void)period21;
    (void)period22;

    if (function_hook_state_DoWobbleCamera == HOOK_ENABLED) {
        assert(0 && "DoWobbleCamera not implemented.");
        abort();
    } else {
        original_DoWobbleCamera(pCamera);
    }
}

function_hook_state_t function_hook_state_DoDrugWobbleCamera = HOOK_UNAVAILABLE;
static void(__cdecl*original_DoDrugWobbleCamera)(br_actor *) = (void(__cdecl*)(br_actor *))0x00463289;
CARM95_HOOK_FUNCTION(original_DoDrugWobbleCamera, DoDrugWobbleCamera)
void __cdecl DoDrugWobbleCamera(br_actor *pCamera) {
    float f_time;
    static br_scalar mag00;
    static br_scalar mag01;
    static br_scalar mag02;
    static br_scalar mag10;
    static br_scalar mag11;
    static br_scalar mag12;
    static br_scalar mag20;
    static br_scalar mag21;
    static br_scalar mag22;
    static float period00;
    static float period01;
    static float period02;
    static float period10;
    static float period11;
    static float period12;
    static float period20;
    static float period21;
    static float period22;
    LOG_TRACE("(%p)", pCamera);

    (void)pCamera;
    (void)f_time;
    (void)mag00;
    (void)mag01;
    (void)mag02;
    (void)mag10;
    (void)mag11;
    (void)mag12;
    (void)mag20;
    (void)mag21;
    (void)mag22;
    (void)period00;
    (void)period01;
    (void)period02;
    (void)period10;
    (void)period11;
    (void)period12;
    (void)period20;
    (void)period21;
    (void)period22;

    if (function_hook_state_DoDrugWobbleCamera == HOOK_ENABLED) {
        assert(0 && "DoDrugWobbleCamera not implemented.");
        abort();
    } else {
        original_DoDrugWobbleCamera(pCamera);
    }
}

function_hook_state_t function_hook_state_DoSpecialCameraEffect = HOOK_UNAVAILABLE;
static void(__cdecl*original_DoSpecialCameraEffect)(br_actor *, br_matrix34 *) = (void(__cdecl*)(br_actor *, br_matrix34 *))0x00462fdb;
CARM95_HOOK_FUNCTION(original_DoSpecialCameraEffect, DoSpecialCameraEffect)
void __cdecl DoSpecialCameraEffect(br_actor *pCamera, br_matrix34 *pCamera_to_world) {
    LOG_TRACE("(%p, %p)", pCamera, pCamera_to_world);

    (void)pCamera;
    (void)pCamera_to_world;

    if (function_hook_state_DoSpecialCameraEffect == HOOK_ENABLED) {
        assert(0 && "DoSpecialCameraEffect not implemented.");
        abort();
    } else {
        original_DoSpecialCameraEffect(pCamera, pCamera_to_world);
    }
}

function_hook_state_t function_hook_state_LessDepthFactor = HOOK_UNAVAILABLE;
static void(__cdecl*original_LessDepthFactor)() = (void(__cdecl*)())0x004634ac;
CARM95_HOOK_FUNCTION(original_LessDepthFactor, LessDepthFactor)
void __cdecl LessDepthFactor() {
    char s[256];
    LOG_TRACE("()");

    (void)s;

    if (function_hook_state_LessDepthFactor == HOOK_ENABLED) {
        assert(0 && "LessDepthFactor not implemented.");
        abort();
    } else {
        original_LessDepthFactor();
    }
}

function_hook_state_t function_hook_state_MoreDepthFactor = HOOK_UNAVAILABLE;
static void(__cdecl*original_MoreDepthFactor)() = (void(__cdecl*)())0x0046350e;
CARM95_HOOK_FUNCTION(original_MoreDepthFactor, MoreDepthFactor)
void __cdecl MoreDepthFactor() {
    char s[256];
    LOG_TRACE("()");

    (void)s;

    if (function_hook_state_MoreDepthFactor == HOOK_ENABLED) {
        assert(0 && "MoreDepthFactor not implemented.");
        abort();
    } else {
        original_MoreDepthFactor();
    }
}

function_hook_state_t function_hook_state_LessDepthFactor2 = HOOK_UNAVAILABLE;
static void(__cdecl*original_LessDepthFactor2)() = (void(__cdecl*)())0x00463570;
CARM95_HOOK_FUNCTION(original_LessDepthFactor2, LessDepthFactor2)
void __cdecl LessDepthFactor2() {
    char s[256];
    LOG_TRACE("()");

    (void)s;

    if (function_hook_state_LessDepthFactor2 == HOOK_ENABLED) {
        assert(0 && "LessDepthFactor2 not implemented.");
        abort();
    } else {
        original_LessDepthFactor2();
    }
}

function_hook_state_t function_hook_state_MoreDepthFactor2 = HOOK_UNAVAILABLE;
static void(__cdecl*original_MoreDepthFactor2)() = (void(__cdecl*)())0x004635d2;
CARM95_HOOK_FUNCTION(original_MoreDepthFactor2, MoreDepthFactor2)
void __cdecl MoreDepthFactor2() {
    char s[256];
    LOG_TRACE("()");

    (void)s;

    if (function_hook_state_MoreDepthFactor2 == HOOK_ENABLED) {
        assert(0 && "MoreDepthFactor2 not implemented.");
        abort();
    } else {
        original_MoreDepthFactor2();
    }
}

function_hook_state_t function_hook_state_AssertYons = HOOK_UNAVAILABLE;
static void(__cdecl*original_AssertYons)() = (void(__cdecl*)())0x00463634;
CARM95_HOOK_FUNCTION(original_AssertYons, AssertYons)
void __cdecl AssertYons() {
    br_camera *camera_ptr;
    int i;
    LOG_TRACE("()");

    (void)camera_ptr;
    (void)i;

    if (function_hook_state_AssertYons == HOOK_ENABLED) {
        assert(0 && "AssertYons not implemented.");
        abort();
    } else {
        original_AssertYons();
    }
}

function_hook_state_t function_hook_state_IncreaseYon = HOOK_UNAVAILABLE;
static void(__cdecl*original_IncreaseYon)() = (void(__cdecl*)())0x00463682;
CARM95_HOOK_FUNCTION(original_IncreaseYon, IncreaseYon)
void __cdecl IncreaseYon() {
    br_camera *camera_ptr;
    int i;
    char s[256];
    LOG_TRACE("()");

    (void)camera_ptr;
    (void)i;
    (void)s;

    if (function_hook_state_IncreaseYon == HOOK_ENABLED) {
        assert(0 && "IncreaseYon not implemented.");
        abort();
    } else {
        original_IncreaseYon();
    }
}

function_hook_state_t function_hook_state_DecreaseYon = HOOK_UNAVAILABLE;
static void(__cdecl*original_DecreaseYon)() = (void(__cdecl*)())0x004636ef;
CARM95_HOOK_FUNCTION(original_DecreaseYon, DecreaseYon)
void __cdecl DecreaseYon() {
    br_camera *camera_ptr;
    int i;
    char s[256];
    LOG_TRACE("()");

    (void)camera_ptr;
    (void)i;
    (void)s;

    if (function_hook_state_DecreaseYon == HOOK_ENABLED) {
        assert(0 && "DecreaseYon not implemented.");
        abort();
    } else {
        original_DecreaseYon();
    }
}

function_hook_state_t function_hook_state_SetYon = HOOK_UNAVAILABLE;
static void(__cdecl*original_SetYon)(br_scalar) = (void(__cdecl*)(br_scalar))0x00463777;
CARM95_HOOK_FUNCTION(original_SetYon, SetYon)
void __cdecl SetYon(br_scalar pYon) {
    int i;
    br_camera *camera_ptr;
    LOG_TRACE("(%f)", pYon);

    (void)pYon;
    (void)i;
    (void)camera_ptr;

    if (function_hook_state_SetYon == HOOK_ENABLED) {
        assert(0 && "SetYon not implemented.");
        abort();
    } else {
        original_SetYon(pYon);
    }
}

function_hook_state_t function_hook_state_GetYon = HOOK_UNAVAILABLE;
static br_scalar(__cdecl*original_GetYon)() = (br_scalar(__cdecl*)())0x004637f0;
CARM95_HOOK_FUNCTION(original_GetYon, GetYon)
br_scalar __cdecl GetYon() {
    LOG_TRACE("()");


    if (function_hook_state_GetYon == HOOK_ENABLED) {
        assert(0 && "GetYon not implemented.");
        abort();
    } else {
        return original_GetYon();
    }
}

function_hook_state_t function_hook_state_IncreaseAngle = HOOK_UNAVAILABLE;
static void(__cdecl*original_IncreaseAngle)() = (void(__cdecl*)())0x00463806;
CARM95_HOOK_FUNCTION(original_IncreaseAngle, IncreaseAngle)
void __cdecl IncreaseAngle() {
    br_camera *camera_ptr;
    int i;
    char s[256];
    LOG_TRACE("()");

    (void)camera_ptr;
    (void)i;
    (void)s;

    if (function_hook_state_IncreaseAngle == HOOK_ENABLED) {
        assert(0 && "IncreaseAngle not implemented.");
        abort();
    } else {
        original_IncreaseAngle();
    }
}

function_hook_state_t function_hook_state_DecreaseAngle = HOOK_UNAVAILABLE;
static void(__cdecl*original_DecreaseAngle)() = (void(__cdecl*)())0x004638c8;
CARM95_HOOK_FUNCTION(original_DecreaseAngle, DecreaseAngle)
void __cdecl DecreaseAngle() {
    br_camera *camera_ptr;
    int i;
    char s[256];
    LOG_TRACE("()");

    (void)camera_ptr;
    (void)i;
    (void)s;

    if (function_hook_state_DecreaseAngle == HOOK_ENABLED) {
        assert(0 && "DecreaseAngle not implemented.");
        abort();
    } else {
        original_DecreaseAngle();
    }
}

function_hook_state_t function_hook_state_ToggleDepthMode = HOOK_UNAVAILABLE;
static void(__cdecl*original_ToggleDepthMode)() = (void(__cdecl*)())0x0046398a;
CARM95_HOOK_FUNCTION(original_ToggleDepthMode, ToggleDepthMode)
void __cdecl ToggleDepthMode() {
    LOG_TRACE("()");


    if (function_hook_state_ToggleDepthMode == HOOK_ENABLED) {
        assert(0 && "ToggleDepthMode not implemented.");
        abort();
    } else {
        original_ToggleDepthMode();
    }
}

function_hook_state_t function_hook_state_GetSkyTextureOn = HOOK_UNAVAILABLE;
static int(__cdecl*original_GetSkyTextureOn)() = (int(__cdecl*)())0x00463a7e;
CARM95_HOOK_FUNCTION(original_GetSkyTextureOn, GetSkyTextureOn)
int __cdecl GetSkyTextureOn() {
    LOG_TRACE("()");


    if (function_hook_state_GetSkyTextureOn == HOOK_ENABLED) {
        assert(0 && "GetSkyTextureOn not implemented.");
        abort();
    } else {
        return original_GetSkyTextureOn();
    }
}

function_hook_state_t function_hook_state_SetSkyTextureOn = HOOK_UNAVAILABLE;
static void(__cdecl*original_SetSkyTextureOn)(int) = (void(__cdecl*)(int))0x00463a93;
CARM95_HOOK_FUNCTION(original_SetSkyTextureOn, SetSkyTextureOn)
void __cdecl SetSkyTextureOn(int pOn) {
    LOG_TRACE("(%d)", pOn);

    (void)pOn;

    if (function_hook_state_SetSkyTextureOn == HOOK_ENABLED) {
        assert(0 && "SetSkyTextureOn not implemented.");
        abort();
    } else {
        original_SetSkyTextureOn(pOn);
    }
}

function_hook_state_t function_hook_state_ToggleSkyQuietly = HOOK_UNAVAILABLE;
static void(__cdecl*original_ToggleSkyQuietly)() = (void(__cdecl*)())0x00463aba;
CARM95_HOOK_FUNCTION(original_ToggleSkyQuietly, ToggleSkyQuietly)
void __cdecl ToggleSkyQuietly() {
    br_pixelmap *temp;
    LOG_TRACE("()");

    (void)temp;

    if (function_hook_state_ToggleSkyQuietly == HOOK_ENABLED) {
        assert(0 && "ToggleSkyQuietly not implemented.");
        abort();
    } else {
        original_ToggleSkyQuietly();
    }
}

function_hook_state_t function_hook_state_ToggleSky = HOOK_UNAVAILABLE;
static void(__cdecl*original_ToggleSky)() = (void(__cdecl*)())0x00463b27;
CARM95_HOOK_FUNCTION(original_ToggleSky, ToggleSky)
void __cdecl ToggleSky() {
    LOG_TRACE("()");


    if (function_hook_state_ToggleSky == HOOK_ENABLED) {
        assert(0 && "ToggleSky not implemented.");
        abort();
    } else {
        original_ToggleSky();
    }
}

function_hook_state_t function_hook_state_GetDepthCueingOn = HOOK_UNAVAILABLE;
static int(__cdecl*original_GetDepthCueingOn)() = (int(__cdecl*)())0x00463bc5;
CARM95_HOOK_FUNCTION(original_GetDepthCueingOn, GetDepthCueingOn)
int __cdecl GetDepthCueingOn() {
    LOG_TRACE("()");


    if (function_hook_state_GetDepthCueingOn == HOOK_ENABLED) {
        assert(0 && "GetDepthCueingOn not implemented.");
        abort();
    } else {
        return original_GetDepthCueingOn();
    }
}

function_hook_state_t function_hook_state_SetDepthCueingOn = HOOK_UNAVAILABLE;
static void(__cdecl*original_SetDepthCueingOn)(int) = (void(__cdecl*)(int))0x00463bda;
CARM95_HOOK_FUNCTION(original_SetDepthCueingOn, SetDepthCueingOn)
void __cdecl SetDepthCueingOn(int pOn) {
    LOG_TRACE("(%d)", pOn);

    (void)pOn;

    if (function_hook_state_SetDepthCueingOn == HOOK_ENABLED) {
        assert(0 && "SetDepthCueingOn not implemented.");
        abort();
    } else {
        original_SetDepthCueingOn(pOn);
    }
}

function_hook_state_t function_hook_state_ToggleDepthCueingQuietly = HOOK_UNAVAILABLE;
static void(__cdecl*original_ToggleDepthCueingQuietly)() = (void(__cdecl*)())0x00463c0d;
CARM95_HOOK_FUNCTION(original_ToggleDepthCueingQuietly, ToggleDepthCueingQuietly)
void __cdecl ToggleDepthCueingQuietly() {
    tDepth_effect_type temp_type;
    int temp_start;
    int temp_end;
    LOG_TRACE("()");

    (void)temp_type;
    (void)temp_start;
    (void)temp_end;

    if (function_hook_state_ToggleDepthCueingQuietly == HOOK_ENABLED) {
        assert(0 && "ToggleDepthCueingQuietly not implemented.");
        abort();
    } else {
        original_ToggleDepthCueingQuietly();
    }
}

function_hook_state_t function_hook_state_ToggleDepthCueing = HOOK_UNAVAILABLE;
static void(__cdecl*original_ToggleDepthCueing)() = (void(__cdecl*)())0x00463c6b;
CARM95_HOOK_FUNCTION(original_ToggleDepthCueing, ToggleDepthCueing)
void __cdecl ToggleDepthCueing() {
    LOG_TRACE("()");


    if (function_hook_state_ToggleDepthCueing == HOOK_ENABLED) {
        assert(0 && "ToggleDepthCueing not implemented.");
        abort();
    } else {
        original_ToggleDepthCueing();
    }
}

function_hook_state_t function_hook_state_ChangeDepthEffect = HOOK_UNAVAILABLE;
static void(__cdecl*original_ChangeDepthEffect)() = (void(__cdecl*)())0x00463d09;
CARM95_HOOK_FUNCTION(original_ChangeDepthEffect, ChangeDepthEffect)
void __cdecl ChangeDepthEffect() {
    br_scalar x1;
    br_scalar x2;
    br_scalar y1;
    br_scalar y2;
    br_scalar z1;
    br_scalar z2;
    br_scalar distance;
    tSpecial_volume *special_volume;
    LOG_TRACE("()");

    (void)x1;
    (void)x2;
    (void)y1;
    (void)y2;
    (void)z1;
    (void)z2;
    (void)distance;
    (void)special_volume;

    if (function_hook_state_ChangeDepthEffect == HOOK_ENABLED) {
        assert(0 && "ChangeDepthEffect not implemented.");
        abort();
    } else {
        original_ChangeDepthEffect();
    }
}

function_hook_state_t function_hook_state_MungeForwardSky = HOOK_UNAVAILABLE;
static void(__cdecl*original_MungeForwardSky)() = (void(__cdecl*)())0x00463d3f;
CARM95_HOOK_FUNCTION(original_MungeForwardSky, MungeForwardSky)
void __cdecl MungeForwardSky() {
    LOG_TRACE("()");


    if (function_hook_state_MungeForwardSky == HOOK_ENABLED) {
        assert(0 && "MungeForwardSky not implemented.");
        abort();
    } else {
        original_MungeForwardSky();
    }
}

function_hook_state_t function_hook_state_MungeRearviewSky = HOOK_UNAVAILABLE;
static void(__cdecl*original_MungeRearviewSky)() = (void(__cdecl*)())0x00463d4a;
CARM95_HOOK_FUNCTION(original_MungeRearviewSky, MungeRearviewSky)
void __cdecl MungeRearviewSky() {
    LOG_TRACE("()");


    if (function_hook_state_MungeRearviewSky == HOOK_ENABLED) {
        assert(0 && "MungeRearviewSky not implemented.");
        abort();
    } else {
        original_MungeRearviewSky();
    }
}

