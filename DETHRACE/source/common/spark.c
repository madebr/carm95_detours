#include "spark.h"

#include "harness/trace.h"

#include "carm95_hooks.h"

#include "carm95_webserver.h"

#include <assert.h>
int * hookvar_gNext_spark  = (void*)0x005149e8;
int * hookvar_gSpark_flags  = (void*)0x005149ec;
int * hookvar_gNext_shrapnel  = (void*)0x005149f0;
int * hookvar_gShrapnel_flags  = (void*)0x005149f4;
br_model *(* hookvar_gShrapnel_model )[2] = (void*)0x005149f8;
int * hookvar_gSmoke_flags  = (void*)0x00514a00;
int * hookvar_gSmoke_num  = (void*)0x00514a04;
int * hookvar_gOffset  = (void*)0x00514a08;
int * hookvar_gColumn_flags  = (void*)0x00514a0c;
int * hookvar_gNext_column  = (void*)0x00514a10;
br_pixelmap ** hookvar_gBlack_smoke_shade_table  = (void*)0x00514a14;
br_pixelmap ** hookvar_gDark_smoke_shade_table  = (void*)0x00514a18;
br_pixelmap ** hookvar_gGrey_smoke_shade_table  = (void*)0x00514a1c;
int * hookvar_gSmoke_on  = (void*)0x00514a20;
int * hookvar_gNum_splash_types  = (void*)0x00514a24;
#if 0
int * hookvar_gIt_type ;
#endif
br_pixelmap ** hookvar_gIt_shade_table  = (void*)0x00514a2c;
br_pixelmap *** hookvar_gDust_table  = (void*)0x00514a30;
br_pixelmap *(* hookvar_gFlame_map )[20] = (void*)0x00538618;
#if 0
tBRender_smoke *(* hookvar_gBR_smoke_pointers )[30];
#endif
tSplash(* hookvar_gSplash )[32] = (void*)0x00538298;
br_material *(* hookvar_gSplash_material )[20] = (void*)0x00538b00;
#if 0
tBRender_smoke(* hookvar_gBR_smoke_structs )[30];
#endif
tSmoke_column(* hookvar_gSmoke_column )[25] = (void*)0x00538de8;
br_matrix4 * hookvar_gCameraToScreen  = (void*)0x00538668;
tSpark(* hookvar_gSparks )[32] = (void*)0x005398d8;
br_pixelmap *(* hookvar_gShade_list )[16] = (void*)0x005509c0;
#if 0
int * hookvar_gN_BR_smoke_structs ;
#endif
tSmoke(* hookvar_gSmoke )[25] = (void*)0x005386b0;
tU32 * hookvar_gSplash_flags  = (void*)0x0053a0e0;
tU32 * hookvar_gNext_splash  = (void*)0x0053828c;
br_model ** hookvar_gLollipop_model  = (void*)0x0053a0d8;
int * hookvar_gNum_dust_tables  = (void*)0x00538294;
br_model ** hookvar_gSplash_model  = (void*)0x005386a8;
int * hookvar_gDust_rotate  = (void*)0x0053a0dc;
br_camera ** hookvar_gSpark_cam  = (void*)0x00538290;
br_material ** hookvar_gBlack_material  = (void*)0x00538288;
tShrapnel(* hookvar_gShrapnel )[15] = (void*)0x00538b50;

function_hook_state_t function_hook_state_DrawDot = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_DrawDot)
static void(__cdecl*original_DrawDot)(br_scalar, tU8 *, tU16 *, tU8 *) = (void(__cdecl*)(br_scalar, tU8 *, tU16 *, tU8 *))0x00466310;
CARM95_HOOK_FUNCTION(original_DrawDot, DrawDot)
void __cdecl DrawDot(br_scalar z, tU8 *scr_ptr, tU16 *depth_ptr, tU8 *shade_ptr) {
    LOG_TRACE("(%f, %p, %p, %p)", z, scr_ptr, depth_ptr, shade_ptr);

    (void)z;
    (void)scr_ptr;
    (void)depth_ptr;
    (void)shade_ptr;

    if (function_hook_state_DrawDot == HOOK_ENABLED) {
        assert(0 && "DrawDot not implemented.");
        abort();
    } else {
        original_DrawDot(z, scr_ptr, depth_ptr, shade_ptr);
    }
}

function_hook_state_t function_hook_state_SetWorldToScreen = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_SetWorldToScreen)
static void(__cdecl*original_SetWorldToScreen)(br_pixelmap *) = (void(__cdecl*)(br_pixelmap *))0x00466be2;
CARM95_HOOK_FUNCTION(original_SetWorldToScreen, SetWorldToScreen)
void __cdecl SetWorldToScreen(br_pixelmap *pScreen) {
    br_matrix4 mat;
    br_matrix4 mat2;
    LOG_TRACE("(%p)", pScreen);

    (void)pScreen;
    (void)mat;
    (void)mat2;

    if (function_hook_state_SetWorldToScreen == HOOK_ENABLED) {
        assert(0 && "SetWorldToScreen not implemented.");
        abort();
    } else {
        original_SetWorldToScreen(pScreen);
    }
}

function_hook_state_t function_hook_state_DrawLine3DThroughBRender = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_DrawLine3DThroughBRender)
void DrawLine3DThroughBRender(br_vector3 *pStart, br_vector3 *pEnd) {
    LOG_TRACE("(%p, %p)", pStart, pEnd);

    (void)pStart;
    (void)pEnd;

    if (function_hook_state_DrawLine3DThroughBRender == HOOK_ENABLED) {
        assert(0 && "DrawLine3DThroughBRender not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}

function_hook_state_t function_hook_state_DrawLine3D = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_DrawLine3D)
static int(__cdecl*original_DrawLine3D)(br_vector3 *, br_vector3 *, br_pixelmap *, br_pixelmap *, br_pixelmap *) = (int(__cdecl*)(br_vector3 *, br_vector3 *, br_pixelmap *, br_pixelmap *, br_pixelmap *))0x004658e0;
CARM95_HOOK_FUNCTION(original_DrawLine3D, DrawLine3D)
int __cdecl DrawLine3D(br_vector3 *start, br_vector3 *end, br_pixelmap *pScreen, br_pixelmap *pDepth_buffer, br_pixelmap *shade_table) {
    br_vector3 o;
    br_vector3 p;
    br_vector3 tv;
    br_vector4 o2;
    br_vector4 p2;
    br_scalar ts;
    LOG_TRACE("(%p, %p, %p, %p, %p)", start, end, pScreen, pDepth_buffer, shade_table);

    (void)start;
    (void)end;
    (void)pScreen;
    (void)pDepth_buffer;
    (void)shade_table;
    (void)o;
    (void)p;
    (void)tv;
    (void)o2;
    (void)p2;
    (void)ts;

    if (function_hook_state_DrawLine3D == HOOK_ENABLED) {
        assert(0 && "DrawLine3D not implemented.");
        abort();
    } else {
        return original_DrawLine3D(start, end, pScreen, pDepth_buffer, shade_table);
    }
}

function_hook_state_t function_hook_state_DrawLine2D = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_DrawLine2D)
static int(__cdecl*original_DrawLine2D)(br_vector3 *, br_vector3 *, br_pixelmap *, br_pixelmap *, br_scalar, br_pixelmap *) = (int(__cdecl*)(br_vector3 *, br_vector3 *, br_pixelmap *, br_pixelmap *, br_scalar, br_pixelmap *))0x00465ab7;
CARM95_HOOK_FUNCTION(original_DrawLine2D, DrawLine2D)
int __cdecl DrawLine2D(br_vector3 *o, br_vector3 *p, br_pixelmap *pScreen, br_pixelmap *pDepth_buffer, br_scalar brightness, br_pixelmap *shade_table) {
    tU8 *scr_ptr;
    tU16 *depth_ptr;
    tU8 *shade_ptr;
    int x1;
    int x2;
    int y1;
    int y2;
    int d;
    int dx;
    int dy;
    int ax;
    int sx;
    int ay;
    int sy;
    int x;
    int y;
    br_scalar zbuff;
    br_scalar zbuff_inc;
    int darken_count;
    int darken_init;
    LOG_TRACE("(%p, %p, %p, %p, %f, %p)", o, p, pScreen, pDepth_buffer, brightness, shade_table);

    (void)o;
    (void)p;
    (void)pScreen;
    (void)pDepth_buffer;
    (void)brightness;
    (void)shade_table;
    (void)scr_ptr;
    (void)depth_ptr;
    (void)shade_ptr;
    (void)x1;
    (void)x2;
    (void)y1;
    (void)y2;
    (void)d;
    (void)dx;
    (void)dy;
    (void)ax;
    (void)sx;
    (void)ay;
    (void)sy;
    (void)x;
    (void)y;
    (void)zbuff;
    (void)zbuff_inc;
    (void)darken_count;
    (void)darken_init;

    if (function_hook_state_DrawLine2D == HOOK_ENABLED) {
        assert(0 && "DrawLine2D not implemented.");
        abort();
    } else {
        return original_DrawLine2D(o, p, pScreen, pDepth_buffer, brightness, shade_table);
    }
}

function_hook_state_t function_hook_state_SetLineModelCols = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_SetLineModelCols)
void SetLineModelCols(tU8 pCol) {
    LOG_TRACE("(%u)", pCol);

    (void)pCol;

    if (function_hook_state_SetLineModelCols == HOOK_ENABLED) {
        assert(0 && "SetLineModelCols not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}

function_hook_state_t function_hook_state_ReplaySparks = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_ReplaySparks)
static void(__cdecl*original_ReplaySparks)(br_pixelmap *, br_pixelmap *, br_actor *, tU32) = (void(__cdecl*)(br_pixelmap *, br_pixelmap *, br_actor *, tU32))0x00466c92;
CARM95_HOOK_FUNCTION(original_ReplaySparks, ReplaySparks)
void __cdecl ReplaySparks(br_pixelmap *pRender_screen, br_pixelmap *pDepth_buffer, br_actor *pCamera, tU32 pTime) {
    int i;
    br_vector3 pos;
    br_vector3 o;
    br_vector3 p;
    br_vector3 tv;
    br_vector3 new_pos;
    LOG_TRACE("(%p, %p, %p, %u)", pRender_screen, pDepth_buffer, pCamera, pTime);

    (void)pRender_screen;
    (void)pDepth_buffer;
    (void)pCamera;
    (void)pTime;
    (void)i;
    (void)pos;
    (void)o;
    (void)p;
    (void)tv;
    (void)new_pos;

    if (function_hook_state_ReplaySparks == HOOK_ENABLED) {
        assert(0 && "ReplaySparks not implemented.");
        abort();
    } else {
        original_ReplaySparks(pRender_screen, pDepth_buffer, pCamera, pTime);
    }
}

function_hook_state_t function_hook_state_RenderSparks = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_RenderSparks)
static void(__cdecl*original_RenderSparks)(br_pixelmap *, br_pixelmap *, br_actor *, br_matrix34 *, tU32) = (void(__cdecl*)(br_pixelmap *, br_pixelmap *, br_actor *, br_matrix34 *, tU32))0x0046636c;
CARM95_HOOK_FUNCTION(original_RenderSparks, RenderSparks)
void __cdecl RenderSparks(br_pixelmap *pRender_screen, br_pixelmap *pDepth_buffer, br_actor *pCamera, br_matrix34 *pCamera_to_world, tU32 pTime) {
    int i;
    int time;
    br_vector3 tv;
    br_vector3 o;
    br_vector3 p;
    br_vector3 pos;
    br_vector3 new_pos;
    br_scalar ts;
    LOG_TRACE("(%p, %p, %p, %p, %u)", pRender_screen, pDepth_buffer, pCamera, pCamera_to_world, pTime);

    (void)pRender_screen;
    (void)pDepth_buffer;
    (void)pCamera;
    (void)pCamera_to_world;
    (void)pTime;
    (void)i;
    (void)time;
    (void)tv;
    (void)o;
    (void)p;
    (void)pos;
    (void)new_pos;
    (void)ts;

    if (function_hook_state_RenderSparks == HOOK_ENABLED) {
        assert(0 && "RenderSparks not implemented.");
        abort();
    } else {
        original_RenderSparks(pRender_screen, pDepth_buffer, pCamera, pCamera_to_world, pTime);
    }
}

function_hook_state_t function_hook_state_CreateSingleSpark = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_CreateSingleSpark)
static void(__cdecl*original_CreateSingleSpark)(tCar_spec *, br_vector3 *, br_vector3 *) = (void(__cdecl*)(tCar_spec *, br_vector3 *, br_vector3 *))0x0046e43e;
CARM95_HOOK_FUNCTION(original_CreateSingleSpark, CreateSingleSpark)
void __cdecl CreateSingleSpark(tCar_spec *pCar, br_vector3 *pPos, br_vector3 *pVel) {
    LOG_TRACE("(%p, %p, %p)", pCar, pPos, pVel);

    (void)pCar;
    (void)pPos;
    (void)pVel;

    if (function_hook_state_CreateSingleSpark == HOOK_ENABLED) {
        assert(0 && "CreateSingleSpark not implemented.");
        abort();
    } else {
        original_CreateSingleSpark(pCar, pPos, pVel);
    }
}

function_hook_state_t function_hook_state_CreateSparks = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_CreateSparks)
static void(__cdecl*original_CreateSparks)(br_vector3 *, br_vector3 *, br_vector3 *, br_scalar, tCar_spec *) = (void(__cdecl*)(br_vector3 *, br_vector3 *, br_vector3 *, br_scalar, tCar_spec *))0x00466e70;
CARM95_HOOK_FUNCTION(original_CreateSparks, CreateSparks)
void __cdecl CreateSparks(br_vector3 *pos, br_vector3 *v, br_vector3 *pForce, br_scalar sparkiness, tCar_spec *pCar) {
    br_vector3 norm;
    br_vector3 normal;
    br_vector3 tv;
    br_vector3 tv2;
    br_vector3 pos2;
    br_scalar ts;
    br_scalar ts2;
    int num;
    int i;
    LOG_TRACE("(%p, %p, %p, %f, %p)", pos, v, pForce, sparkiness, pCar);

    (void)pos;
    (void)v;
    (void)pForce;
    (void)sparkiness;
    (void)pCar;
    (void)norm;
    (void)normal;
    (void)tv;
    (void)tv2;
    (void)pos2;
    (void)ts;
    (void)ts2;
    (void)num;
    (void)i;

    if (function_hook_state_CreateSparks == HOOK_ENABLED) {
        assert(0 && "CreateSparks not implemented.");
        abort();
    } else {
        original_CreateSparks(pos, v, pForce, sparkiness, pCar);
    }
}

function_hook_state_t function_hook_state_CreateSparkShower = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_CreateSparkShower)
static void(__cdecl*original_CreateSparkShower)(br_vector3 *, br_vector3 *, br_vector3 *, tCar_spec *, tCar_spec *) = (void(__cdecl*)(br_vector3 *, br_vector3 *, br_vector3 *, tCar_spec *, tCar_spec *))0x004674b1;
CARM95_HOOK_FUNCTION(original_CreateSparkShower, CreateSparkShower)
void __cdecl CreateSparkShower(br_vector3 *pos, br_vector3 *v, br_vector3 *pForce, tCar_spec *pCar1, tCar_spec *pCar2) {
    br_scalar ts;
    br_scalar ts2;
    int num;
    int i;
    tCar_spec *c;
    br_vector3 tv;
    br_vector3 tv2;
    br_vector3 normal;
    LOG_TRACE("(%p, %p, %p, %p, %p)", pos, v, pForce, pCar1, pCar2);

    (void)pos;
    (void)v;
    (void)pForce;
    (void)pCar1;
    (void)pCar2;
    (void)ts;
    (void)ts2;
    (void)num;
    (void)i;
    (void)c;
    (void)tv;
    (void)tv2;
    (void)normal;

    if (function_hook_state_CreateSparkShower == HOOK_ENABLED) {
        assert(0 && "CreateSparkShower not implemented.");
        abort();
    } else {
        original_CreateSparkShower(pos, v, pForce, pCar1, pCar2);
    }
}

function_hook_state_t function_hook_state_AdjustSpark = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_AdjustSpark)
static void(__cdecl*original_AdjustSpark)(int, br_vector3 *, br_vector3 *) = (void(__cdecl*)(int, br_vector3 *, br_vector3 *))0x004678b3;
CARM95_HOOK_FUNCTION(original_AdjustSpark, AdjustSpark)
void __cdecl AdjustSpark(int pSpark_num, br_vector3 *pos, br_vector3 *length) {
    br_vector3 tv;
    br_matrix34 *mat;
    int i;
    LOG_TRACE("(%d, %p, %p)", pSpark_num, pos, length);

    (void)pSpark_num;
    (void)pos;
    (void)length;
    (void)tv;
    (void)mat;
    (void)i;

    if (function_hook_state_AdjustSpark == HOOK_ENABLED) {
        assert(0 && "AdjustSpark not implemented.");
        abort();
    } else {
        original_AdjustSpark(pSpark_num, pos, length);
    }
}

function_hook_state_t function_hook_state_AdjustShrapnel = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_AdjustShrapnel)
static void(__cdecl*original_AdjustShrapnel)(int, br_vector3 *, tU16, br_material *) = (void(__cdecl*)(int, br_vector3 *, tU16, br_material *))0x004679cd;
CARM95_HOOK_FUNCTION(original_AdjustShrapnel, AdjustShrapnel)
void __cdecl AdjustShrapnel(int pShrapnel_num, br_vector3 *pos, tU16 pAge, br_material *pMaterial) {
    int i;
    LOG_TRACE("(%d, %p, %u, %p)", pShrapnel_num, pos, pAge, pMaterial);

    (void)pShrapnel_num;
    (void)pos;
    (void)pAge;
    (void)pMaterial;
    (void)i;

    if (function_hook_state_AdjustShrapnel == HOOK_ENABLED) {
        assert(0 && "AdjustShrapnel not implemented.");
        abort();
    } else {
        original_AdjustShrapnel(pShrapnel_num, pos, pAge, pMaterial);
    }
}

function_hook_state_t function_hook_state_ResetSparks = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_ResetSparks)
static void(__cdecl*original_ResetSparks)() = (void(__cdecl*)())0x00467abf;
CARM95_HOOK_FUNCTION(original_ResetSparks, ResetSparks)
void __cdecl ResetSparks() {
    LOG_TRACE("()");


    if (function_hook_state_ResetSparks == HOOK_ENABLED) {
        assert(0 && "ResetSparks not implemented.");
        abort();
    } else {
        original_ResetSparks();
    }
}

function_hook_state_t function_hook_state_ResetShrapnel = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_ResetShrapnel)
static void(__cdecl*original_ResetShrapnel)() = (void(__cdecl*)())0x00467ad4;
CARM95_HOOK_FUNCTION(original_ResetShrapnel, ResetShrapnel)
void __cdecl ResetShrapnel() {
    int i;
    LOG_TRACE("()");

    (void)i;

    if (function_hook_state_ResetShrapnel == HOOK_ENABLED) {
        assert(0 && "ResetShrapnel not implemented.");
        abort();
    } else {
        original_ResetShrapnel();
    }
}

function_hook_state_t function_hook_state_CreateShrapnelShower = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_CreateShrapnelShower)
static void(__cdecl*original_CreateShrapnelShower)(br_vector3 *, br_vector3 *, br_vector3 *, br_scalar, tCar_spec *, tCar_spec *) = (void(__cdecl*)(br_vector3 *, br_vector3 *, br_vector3 *, br_scalar, tCar_spec *, tCar_spec *))0x00467b4e;
CARM95_HOOK_FUNCTION(original_CreateShrapnelShower, CreateShrapnelShower)
void __cdecl CreateShrapnelShower(br_vector3 *pos, br_vector3 *v, br_vector3 *pNormal, br_scalar pForce, tCar_spec *c1, tCar_spec *c2) {
    br_scalar ts;
    br_scalar ts2;
    br_scalar rnd;
    int num;
    int i;
    tCar_spec *c;
    br_vector3 tv;
    br_vector3 tv2;
    br_vector3 vel;
    LOG_TRACE("(%p, %p, %p, %f, %p, %p)", pos, v, pNormal, pForce, c1, c2);

    (void)pos;
    (void)v;
    (void)pNormal;
    (void)pForce;
    (void)c1;
    (void)c2;
    (void)ts;
    (void)ts2;
    (void)rnd;
    (void)num;
    (void)i;
    (void)c;
    (void)tv;
    (void)tv2;
    (void)vel;

    if (function_hook_state_CreateShrapnelShower == HOOK_ENABLED) {
        assert(0 && "CreateShrapnelShower not implemented.");
        abort();
    } else {
        original_CreateShrapnelShower(pos, v, pNormal, pForce, c1, c2);
    }
}

function_hook_state_t function_hook_state_random = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_random)
br_scalar random() {
    LOG_TRACE("()");


    if (function_hook_state_random == HOOK_ENABLED) {
        assert(0 && "random not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}

function_hook_state_t function_hook_state_InitShrapnel = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_InitShrapnel)
static void(__cdecl*original_InitShrapnel)() = (void(__cdecl*)())0x0046ec02;
CARM95_HOOK_FUNCTION(original_InitShrapnel, InitShrapnel)
void __cdecl InitShrapnel() {
    int i;
    int j;
    br_scalar __block0___scale;
    LOG_TRACE("()");

    (void)i;
    (void)j;
    (void)__block0___scale;

    if (function_hook_state_InitShrapnel == HOOK_ENABLED) {
        assert(0 && "InitShrapnel not implemented.");
        abort();
    } else {
        original_InitShrapnel();
    }
}

function_hook_state_t function_hook_state_LoadInShrapnel = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_LoadInShrapnel)
static void(__cdecl*original_LoadInShrapnel)() = (void(__cdecl*)())0x00467f43;
CARM95_HOOK_FUNCTION(original_LoadInShrapnel, LoadInShrapnel)
void __cdecl LoadInShrapnel() {
    LOG_TRACE("()");


    if (function_hook_state_LoadInShrapnel == HOOK_ENABLED) {
        assert(0 && "LoadInShrapnel not implemented.");
        abort();
    } else {
        original_LoadInShrapnel();
    }
}

function_hook_state_t function_hook_state_KillShrapnel = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_KillShrapnel)
static void(__cdecl*original_KillShrapnel)(int) = (void(__cdecl*)(int))0x00468567;
CARM95_HOOK_FUNCTION(original_KillShrapnel, KillShrapnel)
void __cdecl KillShrapnel(int i) {
    LOG_TRACE("(%d)", i);

    (void)i;

    if (function_hook_state_KillShrapnel == HOOK_ENABLED) {
        assert(0 && "KillShrapnel not implemented.");
        abort();
    } else {
        original_KillShrapnel(i);
    }
}

function_hook_state_t function_hook_state_DisposeShrapnel = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_DisposeShrapnel)
static void(__cdecl*original_DisposeShrapnel)() = (void(__cdecl*)())0x00467fa0;
CARM95_HOOK_FUNCTION(original_DisposeShrapnel, DisposeShrapnel)
void __cdecl DisposeShrapnel() {
    int i;
    LOG_TRACE("()");

    (void)i;

    if (function_hook_state_DisposeShrapnel == HOOK_ENABLED) {
        assert(0 && "DisposeShrapnel not implemented.");
        abort();
    } else {
        original_DisposeShrapnel();
    }
}

function_hook_state_t function_hook_state_ReplayShrapnel = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_ReplayShrapnel)
static void(__cdecl*original_ReplayShrapnel)(tU32) = (void(__cdecl*)(tU32))0x004685a0;
CARM95_HOOK_FUNCTION(original_ReplayShrapnel, ReplayShrapnel)
void __cdecl ReplayShrapnel(tU32 pTime) {
    int i;
    br_matrix34 *mat;
    LOG_TRACE("(%u)", pTime);

    (void)pTime;
    (void)i;
    (void)mat;

    if (function_hook_state_ReplayShrapnel == HOOK_ENABLED) {
        assert(0 && "ReplayShrapnel not implemented.");
        abort();
    } else {
        original_ReplayShrapnel(pTime);
    }
}

function_hook_state_t function_hook_state_MungeShrapnel = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_MungeShrapnel)
static void(__cdecl*original_MungeShrapnel)(tU32) = (void(__cdecl*)(tU32))0x0046805c;
CARM95_HOOK_FUNCTION(original_MungeShrapnel, MungeShrapnel)
void __cdecl MungeShrapnel(tU32 pTime) {
    br_vector3 disp;
    int i;
    br_matrix34 *mat;
    br_scalar ts;
    LOG_TRACE("(%u)", pTime);

    (void)pTime;
    (void)disp;
    (void)i;
    (void)mat;
    (void)ts;

    if (function_hook_state_MungeShrapnel == HOOK_ENABLED) {
        assert(0 && "MungeShrapnel not implemented.");
        abort();
    } else {
        original_MungeShrapnel(pTime);
    }
}

function_hook_state_t function_hook_state_DrMatrix34Rotate = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_DrMatrix34Rotate)
static void(__cdecl*original_DrMatrix34Rotate)(br_matrix34 *, br_angle, br_vector3 *) = (void(__cdecl*)(br_matrix34 *, br_angle, br_vector3 *))0x004686c8;
CARM95_HOOK_FUNCTION(original_DrMatrix34Rotate, DrMatrix34Rotate)
void __cdecl DrMatrix34Rotate(br_matrix34 *mat, br_angle r, br_vector3 *a) {
    br_scalar t;
    br_scalar s;
    br_scalar c;
    br_scalar txy;
    br_scalar txz;
    br_scalar tyz;
    br_scalar sx;
    br_scalar sy;
    br_scalar sz;
    LOG_TRACE("(%p, %u, %p)", mat, r, a);

    (void)mat;
    (void)r;
    (void)a;
    (void)t;
    (void)s;
    (void)c;
    (void)txy;
    (void)txz;
    (void)tyz;
    (void)sx;
    (void)sy;
    (void)sz;

    if (function_hook_state_DrMatrix34Rotate == HOOK_ENABLED) {
        assert(0 && "DrMatrix34Rotate not implemented.");
        abort();
    } else {
        original_DrMatrix34Rotate(mat, r, a);
    }
}

function_hook_state_t function_hook_state_SmokeLine = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_SmokeLine)
static void(__cdecl*original_SmokeLine)(int, int, br_scalar, int, tU8 *, tU16 *, tU8 *, br_scalar, br_scalar, br_scalar) = (void(__cdecl*)(int, int, br_scalar, int, tU8 *, tU16 *, tU8 *, br_scalar, br_scalar, br_scalar))0x00469fc0;
CARM95_HOOK_FUNCTION(original_SmokeLine, SmokeLine)
void __cdecl SmokeLine(int l, int x, br_scalar zbuff, int r_squared, tU8 *scr_ptr, tU16 *depth_ptr, tU8 *shade_ptr, br_scalar r_multiplier, br_scalar z_multiplier, br_scalar shade_offset) {
    int i;
    int r_multiplier_int;
    int shade_offset_int;
    tU16 z;
    LOG_TRACE("(%d, %d, %f, %d, %p, %p, %p, %f, %f, %f)", l, x, zbuff, r_squared, scr_ptr, depth_ptr, shade_ptr, r_multiplier, z_multiplier, shade_offset);

    (void)l;
    (void)x;
    (void)zbuff;
    (void)r_squared;
    (void)scr_ptr;
    (void)depth_ptr;
    (void)shade_ptr;
    (void)r_multiplier;
    (void)z_multiplier;
    (void)shade_offset;
    (void)i;
    (void)r_multiplier_int;
    (void)shade_offset_int;
    (void)z;

    if (function_hook_state_SmokeLine == HOOK_ENABLED) {
        assert(0 && "SmokeLine not implemented.");
        abort();
    } else {
        original_SmokeLine(l, x, zbuff, r_squared, scr_ptr, depth_ptr, shade_ptr, r_multiplier, z_multiplier, shade_offset);
    }
}

function_hook_state_t function_hook_state_SmokeCircle = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_SmokeCircle)
static void(__cdecl*original_SmokeCircle)(br_vector3 *, br_scalar, br_scalar, br_scalar, br_scalar, br_pixelmap *, br_pixelmap *, br_pixelmap *) = (void(__cdecl*)(br_vector3 *, br_scalar, br_scalar, br_scalar, br_scalar, br_pixelmap *, br_pixelmap *, br_pixelmap *))0x0046969c;
CARM95_HOOK_FUNCTION(original_SmokeCircle, SmokeCircle)
void __cdecl SmokeCircle(br_vector3 *o, br_scalar r, br_scalar extra_z, br_scalar strength, br_scalar pAspect, br_pixelmap *pRender_screen, br_pixelmap *pDepth_buffer, br_pixelmap *pShade_table) {
    tU8 *scr_ptr;
    tU16 *depth_ptr;
    tU8 *shade_ptr;
    tU8 *osp;
    tU16 *odp;
    int ox;
    int oy;
    int i;
    int r_squared;
    int max_r_squared;
    int l;
    int l2;
    int x;
    int x2;
    int sx;
    int y;
    int inc;
    int y_limit;
    int max_x;
    int min_x;
    br_scalar shade_offset;
    br_scalar r_multiplier;
    br_scalar ry;
    br_scalar z_multiplier;
    br_scalar zbuff;
    br_scalar aspect_squared;
    void(**line)(int, int, br_scalar, int, tU8 *, tU16 *, tU8 *, br_scalar, br_scalar, br_scalar);
    LOG_TRACE("(%p, %f, %f, %f, %f, %p, %p, %p)", o, r, extra_z, strength, pAspect, pRender_screen, pDepth_buffer, pShade_table);

    (void)o;
    (void)r;
    (void)extra_z;
    (void)strength;
    (void)pAspect;
    (void)pRender_screen;
    (void)pDepth_buffer;
    (void)pShade_table;
    (void)scr_ptr;
    (void)depth_ptr;
    (void)shade_ptr;
    (void)osp;
    (void)odp;
    (void)ox;
    (void)oy;
    (void)i;
    (void)r_squared;
    (void)max_r_squared;
    (void)l;
    (void)l2;
    (void)x;
    (void)x2;
    (void)sx;
    (void)y;
    (void)inc;
    (void)y_limit;
    (void)max_x;
    (void)min_x;
    (void)shade_offset;
    (void)r_multiplier;
    (void)ry;
    (void)z_multiplier;
    (void)zbuff;
    (void)aspect_squared;
    (void)line;

    if (function_hook_state_SmokeCircle == HOOK_ENABLED) {
        assert(0 && "SmokeCircle not implemented.");
        abort();
    } else {
        original_SmokeCircle(o, r, extra_z, strength, pAspect, pRender_screen, pDepth_buffer, pShade_table);
    }
}

function_hook_state_t function_hook_state_CmpSmokeZ = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_CmpSmokeZ)
int CmpSmokeZ(void *p1, void *p2) {
    tBRender_smoke **a;
    tBRender_smoke **b;
    LOG_TRACE("(%p, %p)", p1, p2);

    (void)p1;
    (void)p2;
    (void)a;
    (void)b;

    if (function_hook_state_CmpSmokeZ == HOOK_ENABLED) {
        assert(0 && "CmpSmokeZ not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}

function_hook_state_t function_hook_state_RenderRecordedSmokeCircles = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_RenderRecordedSmokeCircles)
void RenderRecordedSmokeCircles() {
    int i;
    tBRender_smoke *smoke;
    tU8 red;
    tU8 grn;
    tU8 blu;
    LOG_TRACE("()");

    (void)i;
    (void)smoke;
    (void)red;
    (void)grn;
    (void)blu;

    if (function_hook_state_RenderRecordedSmokeCircles == HOOK_ENABLED) {
        assert(0 && "RenderRecordedSmokeCircles not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}

function_hook_state_t function_hook_state_RecordSmokeCircle = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_RecordSmokeCircle)
void RecordSmokeCircle(br_vector3 *pCent, br_scalar pR, br_scalar pStrength, br_pixelmap *pShade, br_scalar pAspect) {
    tU8 shade_index;
    br_colour shade_rgb;
    LOG_TRACE("(%p, %f, %f, %p, %f)", pCent, pR, pStrength, pShade, pAspect);

    (void)pCent;
    (void)pR;
    (void)pStrength;
    (void)pShade;
    (void)pAspect;
    (void)shade_index;
    (void)shade_rgb;

    if (function_hook_state_RecordSmokeCircle == HOOK_ENABLED) {
        assert(0 && "RecordSmokeCircle not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}

function_hook_state_t function_hook_state_SmokeCircle3D = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_SmokeCircle3D)
static void(__cdecl*original_SmokeCircle3D)(br_vector3 *, br_scalar, br_scalar, br_scalar, br_pixelmap *, br_pixelmap *, br_pixelmap *, br_actor *) = (void(__cdecl*)(br_vector3 *, br_scalar, br_scalar, br_scalar, br_pixelmap *, br_pixelmap *, br_pixelmap *, br_actor *))0x00469551;
CARM95_HOOK_FUNCTION(original_SmokeCircle3D, SmokeCircle3D)
void __cdecl SmokeCircle3D(br_vector3 *o, br_scalar r, br_scalar strength, br_scalar pAspect, br_pixelmap *pRender_screen, br_pixelmap *pDepth_buffer, br_pixelmap *pShade_table, br_actor *pCam) {
    br_vector3 tv;
    br_vector3 p;
    br_vector4 o2;
    br_camera *cam;
    int scaled_r;
    br_scalar extra_z;
    LOG_TRACE("(%p, %f, %f, %f, %p, %p, %p, %p)", o, r, strength, pAspect, pRender_screen, pDepth_buffer, pShade_table, pCam);

    (void)o;
    (void)r;
    (void)strength;
    (void)pAspect;
    (void)pRender_screen;
    (void)pDepth_buffer;
    (void)pShade_table;
    (void)pCam;
    (void)tv;
    (void)p;
    (void)o2;
    (void)cam;
    (void)scaled_r;
    (void)extra_z;

    if (function_hook_state_SmokeCircle3D == HOOK_ENABLED) {
        assert(0 && "SmokeCircle3D not implemented.");
        abort();
    } else {
        original_SmokeCircle3D(o, r, strength, pAspect, pRender_screen, pDepth_buffer, pShade_table, pCam);
    }
}

function_hook_state_t function_hook_state_ReplaySmoke = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_ReplaySmoke)
static void(__cdecl*original_ReplaySmoke)(br_pixelmap *, br_pixelmap *, br_actor *) = (void(__cdecl*)(br_pixelmap *, br_pixelmap *, br_actor *))0x0046a09d;
CARM95_HOOK_FUNCTION(original_ReplaySmoke, ReplaySmoke)
void __cdecl ReplaySmoke(br_pixelmap *pRender_screen, br_pixelmap *pDepth_buffer, br_actor *pCamera) {
    br_scalar aspect;
    int i;
    LOG_TRACE("(%p, %p, %p)", pRender_screen, pDepth_buffer, pCamera);

    (void)pRender_screen;
    (void)pDepth_buffer;
    (void)pCamera;
    (void)aspect;
    (void)i;

    if (function_hook_state_ReplaySmoke == HOOK_ENABLED) {
        assert(0 && "ReplaySmoke not implemented.");
        abort();
    } else {
        original_ReplaySmoke(pRender_screen, pDepth_buffer, pCamera);
    }
}

function_hook_state_t function_hook_state_GenerateContinuousSmoke = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_GenerateContinuousSmoke)
static void(__cdecl*original_GenerateContinuousSmoke)(tCar_spec *, int, tU32) = (void(__cdecl*)(tCar_spec *, int, tU32))0x004687dc;
CARM95_HOOK_FUNCTION(original_GenerateContinuousSmoke, GenerateContinuousSmoke)
void __cdecl GenerateContinuousSmoke(tCar_spec *pCar, int wheel, tU32 pTime) {
    br_vector3 pos;
    br_vector3 v;
    br_vector3 vcs;
    br_vector3 tv;
    br_scalar decay_factor;
    br_scalar ts;
    br_scalar alpha;
    br_scalar beta;
    int colour;
    LOG_TRACE("(%p, %d, %u)", pCar, wheel, pTime);

    (void)pCar;
    (void)wheel;
    (void)pTime;
    (void)pos;
    (void)v;
    (void)vcs;
    (void)tv;
    (void)decay_factor;
    (void)ts;
    (void)alpha;
    (void)beta;
    (void)colour;

    if (function_hook_state_GenerateContinuousSmoke == HOOK_ENABLED) {
        assert(0 && "GenerateContinuousSmoke not implemented.");
        abort();
    } else {
        original_GenerateContinuousSmoke(pCar, wheel, pTime);
    }
}

function_hook_state_t function_hook_state_DustRotate = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_DustRotate)
void DustRotate() {
    LOG_TRACE("()");


    if (function_hook_state_DustRotate == HOOK_ENABLED) {
        assert(0 && "DustRotate not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}

function_hook_state_t function_hook_state_RenderSmoke = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_RenderSmoke)
static void(__cdecl*original_RenderSmoke)(br_pixelmap *, br_pixelmap *, br_actor *, br_matrix34 *, tU32) = (void(__cdecl*)(br_pixelmap *, br_pixelmap *, br_actor *, br_matrix34 *, tU32))0x00468c09;
CARM95_HOOK_FUNCTION(original_RenderSmoke, RenderSmoke)
void __cdecl RenderSmoke(br_pixelmap *pRender_screen, br_pixelmap *pDepth_buffer, br_actor *pCamera, br_matrix34 *pCamera_to_world, tU32 pTime) {
    int i;
    int j;
    br_vector3 tv;
    br_scalar aspect;
    br_scalar ts;
    tU32 seed;
    tU32 not_lonely;
    LOG_TRACE("(%p, %p, %p, %p, %u)", pRender_screen, pDepth_buffer, pCamera, pCamera_to_world, pTime);

    (void)pRender_screen;
    (void)pDepth_buffer;
    (void)pCamera;
    (void)pCamera_to_world;
    (void)pTime;
    (void)i;
    (void)j;
    (void)tv;
    (void)aspect;
    (void)ts;
    (void)seed;
    (void)not_lonely;

    if (function_hook_state_RenderSmoke == HOOK_ENABLED) {
        assert(0 && "RenderSmoke not implemented.");
        abort();
    } else {
        original_RenderSmoke(pRender_screen, pDepth_buffer, pCamera, pCamera_to_world, pTime);
    }
}

function_hook_state_t function_hook_state_CreatePuffOfSmoke = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_CreatePuffOfSmoke)
static void(__cdecl*original_CreatePuffOfSmoke)(br_vector3 *, br_vector3 *, br_scalar, br_scalar, int, tCar_spec *) = (void(__cdecl*)(br_vector3 *, br_vector3 *, br_scalar, br_scalar, int, tCar_spec *))0x0046a225;
CARM95_HOOK_FUNCTION(original_CreatePuffOfSmoke, CreatePuffOfSmoke)
void __cdecl CreatePuffOfSmoke(br_vector3 *pos, br_vector3 *v, br_scalar strength, br_scalar pDecay_factor, int pType, tCar_spec *pC) {
    br_vector3 tv;
    int pipe_me;
    LOG_TRACE("(%p, %p, %f, %f, %d, %p)", pos, v, strength, pDecay_factor, pType, pC);

    (void)pos;
    (void)v;
    (void)strength;
    (void)pDecay_factor;
    (void)pType;
    (void)pC;
    (void)tv;
    (void)pipe_me;

    if (function_hook_state_CreatePuffOfSmoke == HOOK_ENABLED) {
        assert(0 && "CreatePuffOfSmoke not implemented.");
        abort();
    } else {
        original_CreatePuffOfSmoke(pos, v, strength, pDecay_factor, pType, pC);
    }
}

function_hook_state_t function_hook_state_ResetSmoke = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_ResetSmoke)
static void(__cdecl*original_ResetSmoke)() = (void(__cdecl*)())0x0046a58d;
CARM95_HOOK_FUNCTION(original_ResetSmoke, ResetSmoke)
void __cdecl ResetSmoke() {
    LOG_TRACE("()");


    if (function_hook_state_ResetSmoke == HOOK_ENABLED) {
        assert(0 && "ResetSmoke not implemented.");
        abort();
    } else {
        original_ResetSmoke();
    }
}

function_hook_state_t function_hook_state_AdjustSmoke = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_AdjustSmoke)
static void(__cdecl*original_AdjustSmoke)(int, tU8, br_vector3 *, br_scalar, br_scalar) = (void(__cdecl*)(int, tU8, br_vector3 *, br_scalar, br_scalar))0x0046a5a2;
CARM95_HOOK_FUNCTION(original_AdjustSmoke, AdjustSmoke)
void __cdecl AdjustSmoke(int pIndex, tU8 pType, br_vector3 *pPos, br_scalar pRadius, br_scalar pStrength) {
    LOG_TRACE("(%d, %u, %p, %f, %f)", pIndex, pType, pPos, pRadius, pStrength);

    (void)pIndex;
    (void)pType;
    (void)pPos;
    (void)pRadius;
    (void)pStrength;

    if (function_hook_state_AdjustSmoke == HOOK_ENABLED) {
        assert(0 && "AdjustSmoke not implemented.");
        abort();
    } else {
        original_AdjustSmoke(pIndex, pType, pPos, pRadius, pStrength);
    }
}

function_hook_state_t function_hook_state_ActorError = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_ActorError)
static void(__cdecl*original_ActorError)() = (void(__cdecl*)())0x0046a791;
CARM95_HOOK_FUNCTION(original_ActorError, ActorError)
void __cdecl ActorError() {
    LOG_TRACE("()");


    if (function_hook_state_ActorError == HOOK_ENABLED) {
        assert(0 && "ActorError not implemented.");
        abort();
    } else {
        original_ActorError();
    }
}

function_hook_state_t function_hook_state_AdjustSmokeColumn = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_AdjustSmokeColumn)
static void(__cdecl*original_AdjustSmokeColumn)(int, tCar_spec *, int, int) = (void(__cdecl*)(int, tCar_spec *, int, int))0x0046a649;
CARM95_HOOK_FUNCTION(original_AdjustSmokeColumn, AdjustSmokeColumn)
void __cdecl AdjustSmokeColumn(int pIndex, tCar_spec *pCar, int pVertex, int pColour) {
    int i;
    br_actor *actor;
    LOG_TRACE("(%d, %p, %d, %d)", pIndex, pCar, pVertex, pColour);

    (void)pIndex;
    (void)pCar;
    (void)pVertex;
    (void)pColour;
    (void)i;
    (void)actor;

    if (function_hook_state_AdjustSmokeColumn == HOOK_ENABLED) {
        assert(0 && "AdjustSmokeColumn not implemented.");
        abort();
    } else {
        original_AdjustSmokeColumn(pIndex, pCar, pVertex, pColour);
    }
}

function_hook_state_t function_hook_state_CreateSmokeColumn = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_CreateSmokeColumn)
static void(__cdecl*original_CreateSmokeColumn)(tCar_spec *, int, int, tU32) = (void(__cdecl*)(tCar_spec *, int, int, tU32))0x0046a79c;
CARM95_HOOK_FUNCTION(original_CreateSmokeColumn, CreateSmokeColumn)
void __cdecl CreateSmokeColumn(tCar_spec *pCar, int pColour, int pVertex_index, tU32 pLifetime) {
    int i;
    br_actor *actor;
    tSmoke_column *col;
    LOG_TRACE("(%p, %d, %d, %u)", pCar, pColour, pVertex_index, pLifetime);

    (void)pCar;
    (void)pColour;
    (void)pVertex_index;
    (void)pLifetime;
    (void)i;
    (void)actor;
    (void)col;

    if (function_hook_state_CreateSmokeColumn == HOOK_ENABLED) {
        assert(0 && "CreateSmokeColumn not implemented.");
        abort();
    } else {
        original_CreateSmokeColumn(pCar, pColour, pVertex_index, pLifetime);
    }
}

function_hook_state_t function_hook_state_GenerateSmokeShades = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_GenerateSmokeShades)
static void(__cdecl*original_GenerateSmokeShades)() = (void(__cdecl*)())0x0046abc9;
CARM95_HOOK_FUNCTION(original_GenerateSmokeShades, GenerateSmokeShades)
void __cdecl GenerateSmokeShades() {
    static int rb;
    static int gb;
    static int bb;
    static int rd;
    static int gd;
    static int bd;
    static int rg;
    static int gg;
    static int bg;
    LOG_TRACE("()");

    (void)rb;
    (void)gb;
    (void)bb;
    (void)rd;
    (void)gd;
    (void)bd;
    (void)rg;
    (void)gg;
    (void)bg;

    if (function_hook_state_GenerateSmokeShades == HOOK_ENABLED) {
        assert(0 && "GenerateSmokeShades not implemented.");
        abort();
    } else {
        original_GenerateSmokeShades();
    }
}

function_hook_state_t function_hook_state_GenerateItFoxShadeTable = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_GenerateItFoxShadeTable)
static void(__cdecl*original_GenerateItFoxShadeTable)() = (void(__cdecl*)())0x0046ace7;
CARM95_HOOK_FUNCTION(original_GenerateItFoxShadeTable, GenerateItFoxShadeTable)
void __cdecl GenerateItFoxShadeTable() {
    LOG_TRACE("()");


    if (function_hook_state_GenerateItFoxShadeTable == HOOK_ENABLED) {
        assert(0 && "GenerateItFoxShadeTable not implemented.");
        abort();
    } else {
        original_GenerateItFoxShadeTable();
    }
}

function_hook_state_t function_hook_state_AdjustFlame = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_AdjustFlame)
static void(__cdecl*original_AdjustFlame)(int, int, br_scalar, br_scalar, br_scalar, br_scalar) = (void(__cdecl*)(int, int, br_scalar, br_scalar, br_scalar, br_scalar))0x0046ad34;
CARM95_HOOK_FUNCTION(original_AdjustFlame, AdjustFlame)
void __cdecl AdjustFlame(int pIndex, int pFrame_count, br_scalar pScale_x, br_scalar pScale_y, br_scalar pOffset_x, br_scalar pOffset_z) {
    int i;
    int j;
    tSmoke_column *col;
    br_actor *actor;
    LOG_TRACE("(%d, %d, %f, %f, %f, %f)", pIndex, pFrame_count, pScale_x, pScale_y, pOffset_x, pOffset_z);

    (void)pIndex;
    (void)pFrame_count;
    (void)pScale_x;
    (void)pScale_y;
    (void)pOffset_x;
    (void)pOffset_z;
    (void)i;
    (void)j;
    (void)col;
    (void)actor;

    if (function_hook_state_AdjustFlame == HOOK_ENABLED) {
        assert(0 && "AdjustFlame not implemented.");
        abort();
    } else {
        original_AdjustFlame(pIndex, pFrame_count, pScale_x, pScale_y, pOffset_x, pOffset_z);
    }
}

function_hook_state_t function_hook_state_ReplayFlame = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_ReplayFlame)
static void(__cdecl*original_ReplayFlame)(tSmoke_column *, br_actor *) = (void(__cdecl*)(tSmoke_column *, br_actor *))0x0046b722;
CARM95_HOOK_FUNCTION(original_ReplayFlame, ReplayFlame)
void __cdecl ReplayFlame(tSmoke_column *col, br_actor *actor) {
    int i;
    LOG_TRACE("(%p, %p)", col, actor);

    (void)col;
    (void)actor;
    (void)i;

    if (function_hook_state_ReplayFlame == HOOK_ENABLED) {
        assert(0 && "ReplayFlame not implemented.");
        abort();
    } else {
        original_ReplayFlame(col, actor);
    }
}

function_hook_state_t function_hook_state_FlameAnimate = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_FlameAnimate)
static void(__cdecl*original_FlameAnimate)(int, br_vector3 *, tU32) = (void(__cdecl*)(int, br_vector3 *, tU32))0x0046b391;
CARM95_HOOK_FUNCTION(original_FlameAnimate, FlameAnimate)
void __cdecl FlameAnimate(int c, br_vector3 *pPos, tU32 pTime) {
    tSmoke_column *col;
    br_actor *actor;
    int i;
    LOG_TRACE("(%d, %p, %u)", c, pPos, pTime);

    (void)c;
    (void)pPos;
    (void)pTime;
    (void)col;
    (void)actor;
    (void)i;

    if (function_hook_state_FlameAnimate == HOOK_ENABLED) {
        assert(0 && "FlameAnimate not implemented.");
        abort();
    } else {
        original_FlameAnimate(c, pPos, pTime);
    }
}

function_hook_state_t function_hook_state_DoSmokeColumn = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_DoSmokeColumn)
static void(__cdecl*original_DoSmokeColumn)(int, tU32, br_vector3 *) = (void(__cdecl*)(int, tU32, br_vector3 *))0x0046b86d;
CARM95_HOOK_FUNCTION(original_DoSmokeColumn, DoSmokeColumn)
void __cdecl DoSmokeColumn(int i, tU32 pTime, br_vector3 *pRet_car_pos) {
    tCar_spec *c;
    br_actor *actor;
    br_actor *bonny;
    int group;
    LOG_TRACE("(%d, %u, %p)", i, pTime, pRet_car_pos);

    (void)i;
    (void)pTime;
    (void)pRet_car_pos;
    (void)c;
    (void)actor;
    (void)bonny;
    (void)group;

    if (function_hook_state_DoSmokeColumn == HOOK_ENABLED) {
        assert(0 && "DoSmokeColumn not implemented.");
        abort();
    } else {
        original_DoSmokeColumn(i, pTime, pRet_car_pos);
    }
}

function_hook_state_t function_hook_state_ReplaySmokeColumn = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_ReplaySmokeColumn)
static void(__cdecl*original_ReplaySmokeColumn)(tU32) = (void(__cdecl*)(tU32))0x0046bb0b;
CARM95_HOOK_FUNCTION(original_ReplaySmokeColumn, ReplaySmokeColumn)
void __cdecl ReplaySmokeColumn(tU32 pTime) {
    int i;
    br_vector3 dummy;
    LOG_TRACE("(%u)", pTime);

    (void)pTime;
    (void)i;
    (void)dummy;

    if (function_hook_state_ReplaySmokeColumn == HOOK_ENABLED) {
        assert(0 && "ReplaySmokeColumn not implemented.");
        abort();
    } else {
        original_ReplaySmokeColumn(pTime);
    }
}

function_hook_state_t function_hook_state_MungeSmokeColumn = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_MungeSmokeColumn)
static void(__cdecl*original_MungeSmokeColumn)(tU32) = (void(__cdecl*)(tU32))0x0046ada4;
CARM95_HOOK_FUNCTION(original_MungeSmokeColumn, MungeSmokeColumn)
void __cdecl MungeSmokeColumn(tU32 pTime) {
    int i;
    int plane;
    br_actor *actor;
    br_actor *bonny;
    br_vector3 car_pos;
    br_vector3 pos;
    br_vector3 v;
    br_vector3 up;
    br_vector3 start;
    br_vector3 end;
    br_scalar ts;
    br_scalar decay_factor;
    tCar_spec *c;
    LOG_TRACE("(%u)", pTime);

    (void)pTime;
    (void)i;
    (void)plane;
    (void)actor;
    (void)bonny;
    (void)car_pos;
    (void)pos;
    (void)v;
    (void)up;
    (void)start;
    (void)end;
    (void)ts;
    (void)decay_factor;
    (void)c;

    if (function_hook_state_MungeSmokeColumn == HOOK_ENABLED) {
        assert(0 && "MungeSmokeColumn not implemented.");
        abort();
    } else {
        original_MungeSmokeColumn(pTime);
    }
}

function_hook_state_t function_hook_state_DisposeFlame = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_DisposeFlame)
static void(__cdecl*original_DisposeFlame)() = (void(__cdecl*)())0x0046bba6;
CARM95_HOOK_FUNCTION(original_DisposeFlame, DisposeFlame)
void __cdecl DisposeFlame() {
    int i;
    int j;
    br_actor *actor;
    br_material *material;
    LOG_TRACE("()");

    (void)i;
    (void)j;
    (void)actor;
    (void)material;

    if (function_hook_state_DisposeFlame == HOOK_ENABLED) {
        assert(0 && "DisposeFlame not implemented.");
        abort();
    } else {
        original_DisposeFlame();
    }
}

function_hook_state_t function_hook_state_InitFlame = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_InitFlame)
static void(__cdecl*original_InitFlame)() = (void(__cdecl*)())0x0046bcf7;
CARM95_HOOK_FUNCTION(original_InitFlame, InitFlame)
void __cdecl InitFlame() {
    int i;
    int j;
    int num;
    char the_path[256];
    br_actor *actor;
    br_material *material;
    LOG_TRACE("()");

    (void)i;
    (void)j;
    (void)num;
    (void)the_path;
    (void)actor;
    (void)material;

    if (function_hook_state_InitFlame == HOOK_ENABLED) {
        assert(0 && "InitFlame not implemented.");
        abort();
    } else {
        original_InitFlame();
    }
}

function_hook_state_t function_hook_state_InitSplash = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_InitSplash)
static void(__cdecl*original_InitSplash)(FILE *) = (void(__cdecl*)(FILE *))0x0046ef01;
CARM95_HOOK_FUNCTION(original_InitSplash, InitSplash)
void __cdecl InitSplash(FILE *pF) {
    int i;
    int num_files;
    int num;
    br_actor *actor;
    char the_path[256];
    char s[256];
    br_pixelmap *splash_maps[20];
    LOG_TRACE("(%p)", pF);

    (void)pF;
    (void)i;
    (void)num_files;
    (void)num;
    (void)actor;
    (void)the_path;
    (void)s;
    (void)splash_maps;

    if (function_hook_state_InitSplash == HOOK_ENABLED) {
        assert(0 && "InitSplash not implemented.");
        abort();
    } else {
        original_InitSplash(pF);
    }
}

function_hook_state_t function_hook_state_DisposeSplash = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_DisposeSplash)
static void(__cdecl*original_DisposeSplash)() = (void(__cdecl*)())0x0046c02c;
CARM95_HOOK_FUNCTION(original_DisposeSplash, DisposeSplash)
void __cdecl DisposeSplash() {
    int i;
    LOG_TRACE("()");

    (void)i;

    if (function_hook_state_DisposeSplash == HOOK_ENABLED) {
        assert(0 && "DisposeSplash not implemented.");
        abort();
    } else {
        original_DisposeSplash();
    }
}

function_hook_state_t function_hook_state_DrawTheGlow = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_DrawTheGlow)
static void(__cdecl*original_DrawTheGlow)(br_pixelmap *, br_pixelmap *, br_actor *) = (void(__cdecl*)(br_pixelmap *, br_pixelmap *, br_actor *))0x0046c133;
CARM95_HOOK_FUNCTION(original_DrawTheGlow, DrawTheGlow)
void __cdecl DrawTheGlow(br_pixelmap *pRender_screen, br_pixelmap *pDepth_buffer, br_actor *pCamera) {
    int i;
    br_scalar strength;
    br_vector3 tv;
    tU32 seed;
    LOG_TRACE("(%p, %p, %p)", pRender_screen, pDepth_buffer, pCamera);

    (void)pRender_screen;
    (void)pDepth_buffer;
    (void)pCamera;
    (void)i;
    (void)strength;
    (void)tv;
    (void)seed;

    if (function_hook_state_DrawTheGlow == HOOK_ENABLED) {
        assert(0 && "DrawTheGlow not implemented.");
        abort();
    } else {
        original_DrawTheGlow(pRender_screen, pDepth_buffer, pCamera);
    }
}

function_hook_state_t function_hook_state_PipeInstantUnSmudge = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_PipeInstantUnSmudge)
static void(__cdecl*original_PipeInstantUnSmudge)(tCar_spec *) = (void(__cdecl*)(tCar_spec *))0x0046c29f;
CARM95_HOOK_FUNCTION(original_PipeInstantUnSmudge, PipeInstantUnSmudge)
void __cdecl PipeInstantUnSmudge(tCar_spec *pCar) {
    br_model *model;
    br_model *b_model;
    br_actor *actor;
    br_actor *bonny;
    int j;
    int n;
    int v;
    int group;
    tSmudged_vertex data[1000];
    LOG_TRACE("(%p)", pCar);

    (void)pCar;
    (void)model;
    (void)b_model;
    (void)actor;
    (void)bonny;
    (void)j;
    (void)n;
    (void)v;
    (void)group;
    (void)data;

    if (function_hook_state_PipeInstantUnSmudge == HOOK_ENABLED) {
        assert(0 && "PipeInstantUnSmudge not implemented.");
        abort();
    } else {
        original_PipeInstantUnSmudge(pCar);
    }
}

function_hook_state_t function_hook_state_SmudgeCar = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_SmudgeCar)
static void(__cdecl*original_SmudgeCar)(tCar_spec *, int) = (void(__cdecl*)(tCar_spec *, int))0x0046c72d;
CARM95_HOOK_FUNCTION(original_SmudgeCar, SmudgeCar)
void __cdecl SmudgeCar(tCar_spec *pCar, int fire_point) {
    int v;
    int j;
    int real_vertex_number;
    br_model *model;
    br_model *b_model;
    br_actor *actor;
    br_actor *bonny;
    br_scalar ts;
    br_vector3 tv;
    br_vector3 bonny_pos;
    int group;
    br_vector3 point;
    tSmudged_vertex data[30];
    int n;
    LOG_TRACE("(%p, %d)", pCar, fire_point);

    (void)pCar;
    (void)fire_point;
    (void)v;
    (void)j;
    (void)real_vertex_number;
    (void)model;
    (void)b_model;
    (void)actor;
    (void)bonny;
    (void)ts;
    (void)tv;
    (void)bonny_pos;
    (void)group;
    (void)point;
    (void)data;
    (void)n;

    if (function_hook_state_SmudgeCar == HOOK_ENABLED) {
        assert(0 && "SmudgeCar not implemented.");
        abort();
    } else {
        original_SmudgeCar(pCar, fire_point);
    }
}

function_hook_state_t function_hook_state_ResetSmokeColumns = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_ResetSmokeColumns)
static void(__cdecl*original_ResetSmokeColumns)() = (void(__cdecl*)())0x0046cff6;
CARM95_HOOK_FUNCTION(original_ResetSmokeColumns, ResetSmokeColumns)
void __cdecl ResetSmokeColumns() {
    int i;
    LOG_TRACE("()");

    (void)i;

    if (function_hook_state_ResetSmokeColumns == HOOK_ENABLED) {
        assert(0 && "ResetSmokeColumns not implemented.");
        abort();
    } else {
        original_ResetSmokeColumns();
    }
}

function_hook_state_t function_hook_state_SetSmokeOn = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_SetSmokeOn)
static void(__cdecl*original_SetSmokeOn)(int) = (void(__cdecl*)(int))0x0046d05e;
CARM95_HOOK_FUNCTION(original_SetSmokeOn, SetSmokeOn)
void __cdecl SetSmokeOn(int pSmoke_on) {
    LOG_TRACE("(%d)", pSmoke_on);

    (void)pSmoke_on;

    if (function_hook_state_SetSmokeOn == HOOK_ENABLED) {
        assert(0 && "SetSmokeOn not implemented.");
        abort();
    } else {
        original_SetSmokeOn(pSmoke_on);
    }
}

function_hook_state_t function_hook_state_ReallySetSmokeOn = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_ReallySetSmokeOn)
static void(__cdecl*original_ReallySetSmokeOn)(int) = (void(__cdecl*)(int))0x0046d071;
CARM95_HOOK_FUNCTION(original_ReallySetSmokeOn, ReallySetSmokeOn)
void __cdecl ReallySetSmokeOn(int pSmoke_on) {
    LOG_TRACE("(%d)", pSmoke_on);

    (void)pSmoke_on;

    if (function_hook_state_ReallySetSmokeOn == HOOK_ENABLED) {
        assert(0 && "ReallySetSmokeOn not implemented.");
        abort();
    } else {
        original_ReallySetSmokeOn(pSmoke_on);
    }
}

function_hook_state_t function_hook_state_SetSmoke = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_SetSmoke)
static void(__cdecl*original_SetSmoke)(int) = (void(__cdecl*)(int))0x0046d086;
CARM95_HOOK_FUNCTION(original_SetSmoke, SetSmoke)
void __cdecl SetSmoke(int pSmoke_on) {
    LOG_TRACE("(%d)", pSmoke_on);

    (void)pSmoke_on;

    if (function_hook_state_SetSmoke == HOOK_ENABLED) {
        assert(0 && "SetSmoke not implemented.");
        abort();
    } else {
        original_SetSmoke(pSmoke_on);
    }
}

function_hook_state_t function_hook_state_GetSmokeOn = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_GetSmokeOn)
static int(__cdecl*original_GetSmokeOn)() = (int(__cdecl*)())0x0046d0a9;
CARM95_HOOK_FUNCTION(original_GetSmokeOn, GetSmokeOn)
int __cdecl GetSmokeOn() {
    LOG_TRACE("()");


    if (function_hook_state_GetSmokeOn == HOOK_ENABLED) {
        assert(0 && "GetSmokeOn not implemented.");
        abort();
    } else {
        return original_GetSmokeOn();
    }
}

function_hook_state_t function_hook_state_StopCarSmoking = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_StopCarSmoking)
static void(__cdecl*original_StopCarSmoking)(tCar_spec *) = (void(__cdecl*)(tCar_spec *))0x0046d0be;
CARM95_HOOK_FUNCTION(original_StopCarSmoking, StopCarSmoking)
void __cdecl StopCarSmoking(tCar_spec *pCar) {
    int i;
    LOG_TRACE("(%p)", pCar);

    (void)pCar;
    (void)i;

    if (function_hook_state_StopCarSmoking == HOOK_ENABLED) {
        assert(0 && "StopCarSmoking not implemented.");
        abort();
    } else {
        original_StopCarSmoking(pCar);
    }
}

function_hook_state_t function_hook_state_StopCarSmokingInstantly = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_StopCarSmokingInstantly)
static void(__cdecl*original_StopCarSmokingInstantly)(tCar_spec *) = (void(__cdecl*)(tCar_spec *))0x0046d13f;
CARM95_HOOK_FUNCTION(original_StopCarSmokingInstantly, StopCarSmokingInstantly)
void __cdecl StopCarSmokingInstantly(tCar_spec *pCar) {
    int i;
    LOG_TRACE("(%p)", pCar);

    (void)pCar;
    (void)i;

    if (function_hook_state_StopCarSmokingInstantly == HOOK_ENABLED) {
        assert(0 && "StopCarSmokingInstantly not implemented.");
        abort();
    } else {
        original_StopCarSmokingInstantly(pCar);
    }
}

function_hook_state_t function_hook_state_ConditionalSmokeColumn = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_ConditionalSmokeColumn)
static void(__cdecl*original_ConditionalSmokeColumn)(tCar_spec *, int, int) = (void(__cdecl*)(tCar_spec *, int, int))0x0046d19e;
CARM95_HOOK_FUNCTION(original_ConditionalSmokeColumn, ConditionalSmokeColumn)
void __cdecl ConditionalSmokeColumn(tCar_spec *pCar, int pDamage_index, int pColour) {
    int i;
    LOG_TRACE("(%p, %d, %d)", pCar, pDamage_index, pColour);

    (void)pCar;
    (void)pDamage_index;
    (void)pColour;
    (void)i;

    if (function_hook_state_ConditionalSmokeColumn == HOOK_ENABLED) {
        assert(0 && "ConditionalSmokeColumn not implemented.");
        abort();
    } else {
        original_ConditionalSmokeColumn(pCar, pDamage_index, pColour);
    }
}

function_hook_state_t function_hook_state_SingleSplash = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_SingleSplash)
static void(__cdecl*original_SingleSplash)(tCar_spec *, br_vector3 *, br_vector3 *, tU32) = (void(__cdecl*)(tCar_spec *, br_vector3 *, br_vector3 *, tU32))0x0046dffa;
CARM95_HOOK_FUNCTION(original_SingleSplash, SingleSplash)
void __cdecl SingleSplash(tCar_spec *pCar, br_vector3 *sp, br_vector3 *normal, tU32 pTime) {
    br_matrix34 *mat;
    br_matrix34 *c_mat;
    br_vector3 tv;
    br_vector3 vel;
    br_scalar size;
    br_scalar speed;
    br_scalar ts;
    LOG_TRACE("(%p, %p, %p, %u)", pCar, sp, normal, pTime);

    (void)pCar;
    (void)sp;
    (void)normal;
    (void)pTime;
    (void)mat;
    (void)c_mat;
    (void)tv;
    (void)vel;
    (void)size;
    (void)speed;
    (void)ts;

    if (function_hook_state_SingleSplash == HOOK_ENABLED) {
        assert(0 && "SingleSplash not implemented.");
        abort();
    } else {
        original_SingleSplash(pCar, sp, normal, pTime);
    }
}

function_hook_state_t function_hook_state_CreateSplash = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_CreateSplash)
static void(__cdecl*original_CreateSplash)(tCar_spec *, tU32) = (void(__cdecl*)(tCar_spec *, tU32))0x0046d2ab;
CARM95_HOOK_FUNCTION(original_CreateSplash, CreateSplash)
void __cdecl CreateSplash(tCar_spec *pCar, tU32 pTime) {
    br_vector3 normal_car_space;
    br_vector3 pos2;
    br_vector3 v_plane;
    br_vector3 p;
    br_vector3 tv;
    br_vector3 tv2;
    br_vector3 cm;
    int i;
    int j;
    int mask;
    int axis1;
    int axis2;
    int axis3;
    br_bounds bnds;
    br_scalar min;
    br_scalar max;
    br_scalar d;
    br_scalar d2;
    br_scalar dist;
    br_scalar dist2;
    br_scalar ts;
    br_vector3 back_point[2];
    br_scalar back_val[2];
    br_scalar __block0___scale;
    LOG_TRACE("(%p, %u)", pCar, pTime);

    (void)pCar;
    (void)pTime;
    (void)normal_car_space;
    (void)pos2;
    (void)v_plane;
    (void)p;
    (void)tv;
    (void)tv2;
    (void)cm;
    (void)i;
    (void)j;
    (void)mask;
    (void)axis1;
    (void)axis2;
    (void)axis3;
    (void)bnds;
    (void)min;
    (void)max;
    (void)d;
    (void)d2;
    (void)dist;
    (void)dist2;
    (void)ts;
    (void)back_point;
    (void)back_val;
    (void)__block0___scale;

    if (function_hook_state_CreateSplash == HOOK_ENABLED) {
        assert(0 && "CreateSplash not implemented.");
        abort();
    } else {
        original_CreateSplash(pCar, pTime);
    }
}

function_hook_state_t function_hook_state_MungeSplash = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_MungeSplash)
static void(__cdecl*original_MungeSplash)(tU32) = (void(__cdecl*)(tU32))0x0046e559;
CARM95_HOOK_FUNCTION(original_MungeSplash, MungeSplash)
void __cdecl MungeSplash(tU32 pTime) {
    int i;
    br_vector3 tv;
    br_scalar dt;
    br_scalar ts;
    tCar_spec *car;
    tVehicle_type type;
    LOG_TRACE("(%u)", pTime);

    (void)pTime;
    (void)i;
    (void)tv;
    (void)dt;
    (void)ts;
    (void)car;
    (void)type;

    if (function_hook_state_MungeSplash == HOOK_ENABLED) {
        assert(0 && "MungeSplash not implemented.");
        abort();
    } else {
        original_MungeSplash(pTime);
    }
}

function_hook_state_t function_hook_state_RenderSplashes = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_RenderSplashes)
static void(__cdecl*original_RenderSplashes)() = (void(__cdecl*)())0x0046ea05;
CARM95_HOOK_FUNCTION(original_RenderSplashes, RenderSplashes)
void __cdecl RenderSplashes() {
    int i;
    LOG_TRACE("()");

    (void)i;

    if (function_hook_state_RenderSplashes == HOOK_ENABLED) {
        assert(0 && "RenderSplashes not implemented.");
        abort();
    } else {
        original_RenderSplashes();
    }
}

function_hook_state_t function_hook_state_GetSmokeShadeTables = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_GetSmokeShadeTables)
static void(__cdecl*original_GetSmokeShadeTables)(FILE *) = (void(__cdecl*)(FILE *))0x0046eaa6;
CARM95_HOOK_FUNCTION(original_GetSmokeShadeTables, GetSmokeShadeTables)
void __cdecl GetSmokeShadeTables(FILE *f) {
    int i;
    int red;
    int green;
    int blue;
    br_scalar quarter;
    br_scalar half;
    br_scalar three_quarter;
    LOG_TRACE("(%p)", f);

    (void)f;
    (void)i;
    (void)red;
    (void)green;
    (void)blue;
    (void)quarter;
    (void)half;
    (void)three_quarter;

    if (function_hook_state_GetSmokeShadeTables == HOOK_ENABLED) {
        assert(0 && "GetSmokeShadeTables not implemented.");
        abort();
    } else {
        original_GetSmokeShadeTables(f);
    }
}

function_hook_state_t function_hook_state_FreeSmokeShadeTables = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_FreeSmokeShadeTables)
static void(__cdecl*original_FreeSmokeShadeTables)() = (void(__cdecl*)())0x0046eb68;
CARM95_HOOK_FUNCTION(original_FreeSmokeShadeTables, FreeSmokeShadeTables)
void __cdecl FreeSmokeShadeTables() {
    int i;
    LOG_TRACE("()");

    (void)i;

    if (function_hook_state_FreeSmokeShadeTables == HOOK_ENABLED) {
        assert(0 && "FreeSmokeShadeTables not implemented.");
        abort();
    } else {
        original_FreeSmokeShadeTables();
    }
}

function_hook_state_t function_hook_state_LoadInKevStuff = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_LoadInKevStuff)
static void(__cdecl*original_LoadInKevStuff)(FILE *) = (void(__cdecl*)(FILE *))0x0046ebc8;
CARM95_HOOK_FUNCTION(original_LoadInKevStuff, LoadInKevStuff)
void __cdecl LoadInKevStuff(FILE *pF) {
    LOG_TRACE("(%p)", pF);

    (void)pF;

    if (function_hook_state_LoadInKevStuff == HOOK_ENABLED) {
        assert(0 && "LoadInKevStuff not implemented.");
        abort();
    } else {
        original_LoadInKevStuff(pF);
    }
}

function_hook_state_t function_hook_state_DisposeKevStuff = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_DisposeKevStuff)
static void(__cdecl*original_DisposeKevStuff)() = (void(__cdecl*)())0x0046f3dc;
CARM95_HOOK_FUNCTION(original_DisposeKevStuff, DisposeKevStuff)
void __cdecl DisposeKevStuff() {
    LOG_TRACE("()");


    if (function_hook_state_DisposeKevStuff == HOOK_ENABLED) {
        assert(0 && "DisposeKevStuff not implemented.");
        abort();
    } else {
        original_DisposeKevStuff();
    }
}

function_hook_state_t function_hook_state_DisposeKevStuffCar = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_DisposeKevStuffCar)
static void(__cdecl*original_DisposeKevStuffCar)(tCar_spec *) = (void(__cdecl*)(tCar_spec *))0x0046f3f6;
CARM95_HOOK_FUNCTION(original_DisposeKevStuffCar, DisposeKevStuffCar)
void __cdecl DisposeKevStuffCar(tCar_spec *pCar) {
    int i;
    LOG_TRACE("(%p)", pCar);

    (void)pCar;
    (void)i;

    if (function_hook_state_DisposeKevStuffCar == HOOK_ENABLED) {
        assert(0 && "DisposeKevStuffCar not implemented.");
        abort();
    } else {
        original_DisposeKevStuffCar(pCar);
    }
}

function_hook_state_t function_hook_state_DoTrueColModelThing = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_DoTrueColModelThing)
static void(__cdecl*original_DoTrueColModelThing)(br_actor *, br_model *, br_material *, void *, br_uint_8, int) = (void(__cdecl*)(br_actor *, br_model *, br_material *, void *, br_uint_8, int))0x0046f52a;
CARM95_HOOK_FUNCTION(original_DoTrueColModelThing, DoTrueColModelThing)
void __cdecl DoTrueColModelThing(br_actor *actor, br_model *pModel, br_material *material, void *render_data, br_uint_8 style, int on_screen) {
    int group;
    int j;
    int val;
    LOG_TRACE("(%p, %p, %p, %p, %u, %d)", actor, pModel, material, render_data, style, on_screen);

    (void)actor;
    (void)pModel;
    (void)material;
    (void)render_data;
    (void)style;
    (void)on_screen;
    (void)group;
    (void)j;
    (void)val;

    if (function_hook_state_DoTrueColModelThing == HOOK_ENABLED) {
        assert(0 && "DoTrueColModelThing not implemented.");
        abort();
    } else {
        original_DoTrueColModelThing(actor, pModel, material, render_data, style, on_screen);
    }
}

function_hook_state_t function_hook_state_DoModelThing = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_DoModelThing)
void DoModelThing(br_actor *actor, br_model *pModel, br_material *material, void *render_data, br_uint_8 style, int on_screen) {
    int j;
    int i;
    int group;
    tU32 t;
    int val;
    LOG_TRACE("(%p, %p, %p, %p, %u, %d)", actor, pModel, material, render_data, style, on_screen);

    (void)actor;
    (void)pModel;
    (void)material;
    (void)render_data;
    (void)style;
    (void)on_screen;
    (void)j;
    (void)i;
    (void)group;
    (void)t;
    (void)val;

    if (function_hook_state_DoModelThing == HOOK_ENABLED) {
        assert(0 && "DoModelThing not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}

function_hook_state_t function_hook_state_SetModelShade = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_SetModelShade)
static void(__cdecl*original_SetModelShade)(br_actor *, br_pixelmap *) = (void(__cdecl*)(br_actor *, br_pixelmap *))0x0046f9b3;
CARM95_HOOK_FUNCTION(original_SetModelShade, SetModelShade)
void __cdecl SetModelShade(br_actor *pActor, br_pixelmap *pShade) {
    int i;
    br_material *material;
    br_model *model;
    LOG_TRACE("(%p, %p)", pActor, pShade);

    (void)pActor;
    (void)pShade;
    (void)i;
    (void)material;
    (void)model;

    if (function_hook_state_SetModelShade == HOOK_ENABLED) {
        assert(0 && "SetModelShade not implemented.");
        abort();
    } else {
        original_SetModelShade(pActor, pShade);
    }
}

function_hook_state_t function_hook_state_MakeCarIt = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_MakeCarIt)
static void(__cdecl*original_MakeCarIt)(tCar_spec *) = (void(__cdecl*)(tCar_spec *))0x0046f877;
CARM95_HOOK_FUNCTION(original_MakeCarIt, MakeCarIt)
void __cdecl MakeCarIt(tCar_spec *pCar) {
    br_actor *actor;
    br_actor *bonny;
    br_pixelmap *shade[6];
    static int shade_num;
    int i;
    LOG_TRACE("(%p)", pCar);

    (void)pCar;
    (void)actor;
    (void)bonny;
    (void)shade;
    (void)shade_num;
    (void)i;

    if (function_hook_state_MakeCarIt == HOOK_ENABLED) {
        assert(0 && "MakeCarIt not implemented.");
        abort();
    } else {
        original_MakeCarIt(pCar);
    }
}

function_hook_state_t function_hook_state_StopCarBeingIt = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_StopCarBeingIt)
static void(__cdecl*original_StopCarBeingIt)(tCar_spec *) = (void(__cdecl*)(tCar_spec *))0x0046fa75;
CARM95_HOOK_FUNCTION(original_StopCarBeingIt, StopCarBeingIt)
void __cdecl StopCarBeingIt(tCar_spec *pCar) {
    int i;
    int group;
    br_actor *actor;
    br_actor *bonny;
    LOG_TRACE("(%p)", pCar);

    (void)pCar;
    (void)i;
    (void)group;
    (void)actor;
    (void)bonny;

    if (function_hook_state_StopCarBeingIt == HOOK_ENABLED) {
        assert(0 && "StopCarBeingIt not implemented.");
        abort();
    } else {
        original_StopCarBeingIt(pCar);
    }
}

