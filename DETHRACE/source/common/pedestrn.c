#include "pedestrn.h"

#include "harness/trace.h"

#include "carm95_hooks.h"

#include "carm95_webserver.h"

#include <assert.h>
int * hookvar_gDetect_peds  = (void*)0x00511740;
int * hookvar_gReally_stupid_ped_bug_enable  = (void*)0x00511744;
int * hookvar_gPed_sound_disable  = (void*)0x00511748;
int * hookvar_gVesuvians_last_time  = (void*)0x0051174c;
int * hookvar_gSend_peds  = (void*)0x00511750;
tU32 * hookvar_gLast_ped_message_send  = (void*)0x00511754;
tPedestrian_instruction ** hookvar_gInitial_instruction  = (void*)0x00511758;
char *(* hookvar_gRate_commands )[3] = (void*)0x00511760;
char *(* hookvar_gCollide_commands )[1] = (void*)0x0051176c;
char *(* hookvar_gInstruc_commands )[10] = (void*)0x00511770;
float(* hookvar_gMin_ped_gib_speeds )[4] = (void*)0x00511798;
float(* hookvar_gPed_gib_distrib )[4] = (void*)0x005117a8;
float(* hookvar_gPed_gib_speeds )[4] = (void*)0x005117b8;
int(* hookvar_gPed_size_counts )[4] = (void*)0x005117c8;
char *(* hookvar_gPed_gib_names )[4][5] = (void*)0x005117d8;
char *(* hookvar_gPed_geb_names )[4][5] = (void*)0x00511828;
int(* hookvar_gPed_gib_maxes )[4][5] = (void*)0x00511878;
br_scalar(* hookvar_gExploding_ped_scale )[3] = (void*)0x005118c8;
 // Suffix added to avoid duplicate symbol
br_vector3 * hookvar_gZero_v__pedestrn  = (void*)0x005118d8;
int * hookvar_gPed_instruc_count  = (void*)0x005118e8;
int * hookvar_gPed_count  = (void*)0x00536b50;
br_actor ** hookvar_gPath_actor  = (void*)0x005118f0;
br_actor ** hookvar_gCurrent_ped_path_actor  = (void*)0x005118f4;
int * hookvar_gPedestrians_on  = (void*)0x005118f8;
int * hookvar_gVesuvian_corpses  = (void*)0x005118fc;
br_material ** hookvar_gPed_material  = (void*)0x005118e4;
int(* hookvar_gPed_gib_counts )[4][5] = (void*)0x005378c8;
tPedestrian_instruction(* hookvar_gPed_instrucs )[100] = (void*)0x00536c48;
tPed_gib(* hookvar_gPed_gibs )[30] = (void*)0x00537418;
tPed_gib_materials(* hookvar_gPed_gib_materials )[4] = (void*)0x00536ab0;
tProximity_ray(* hookvar_gProximity_rays )[20] = (void*)0x00536b58;
#if 0
int * hookvar_gPed_colliding ;
#endif
float * hookvar_gZombie_factor  = (void*)0x00550a90;
int * hookvar_gRespawn_variance  = (void*)0x00550aac;
br_scalar * hookvar_gPed_scale_factor  = (void*)0x00550a94;
int * hookvar_gTotal_peds  = (void*)0x00550a8c;
int * hookvar_gPedestrian_harvest  = (void*)0x00550aa0;
#if 0
br_vector3 * hookvar_gPed_pos_camera ;
#endif
int * hookvar_gMin_respawn_time  = (void*)0x00550aa4;
br_material ** hookvar_gPath_mat_calc  = (void*)0x00536b38;
float * hookvar_gPedestrian_speed_factor  = (void*)0x00550aa8;
int * hookvar_gExploding_pedestrians  = (void*)0x00550a88;
int * hookvar_gBlind_pedestrians  = (void*)0x00550a84;
br_material ** hookvar_gPath_mat_normal  = (void*)0x00536b18;
br_material ** hookvar_gInit_pos_mat_calc  = (void*)0x00536b1c;
#if 0
int * hookvar_gPed_other ;
#endif
int * hookvar_gAttracted_pedestrians  = (void*)0x00550a98;
int * hookvar_gPed_ref_num  = (void*)0x00536aac;
br_scalar * hookvar_gMax_distance_squared  = (void*)0x00536b24;
br_model ** hookvar_gPed_model  = (void*)0x00536b28;
float * hookvar_gDanger_level  = (void*)0x00536b20;
br_vector3 * hookvar_gDanger_direction  = (void*)0x00536b40;
int * hookvar_gInit_ped_instruc  = (void*)0x00536b4c;
int * hookvar_gCurrent_lollipop_index  = (void*)0x00536b10;
int * hookvar_gVesuvians_this_time  = (void*)0x00536aa8;
#if 0
int * hookvar_gNumber_of_ped_gibs ;
#endif
tPedestrian_data ** hookvar_gFlag_waving_bastard  = (void*)0x00536b14;
int * hookvar_gNumber_of_pedestrians  = (void*)0x005118ec;
br_pixelmap ** hookvar_gProx_ray_shade_table  = (void*)0x00536b30;
tPedestrian_data ** hookvar_gPedestrian_array  = (void*)0x0053791c;
tU32 * hookvar_gLast_ped_splat_time  = (void*)0x00536b34;
int * hookvar_gCurrent_ped_multiplier  = (void*)0x00537918;

function_hook_state_t function_hook_state_PedModelUpdate = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(PedModelUpdate, function_hook_state_PedModelUpdate)
static void(__cdecl*original_PedModelUpdate)(br_model *, br_scalar, br_scalar, br_scalar, br_scalar, br_scalar, br_scalar, br_scalar, br_scalar) = (void(__cdecl*)(br_model *, br_scalar, br_scalar, br_scalar, br_scalar, br_scalar, br_scalar, br_scalar, br_scalar))0x00455fcd;
CARM95_HOOK_FUNCTION(original_PedModelUpdate, PedModelUpdate)
void __cdecl PedModelUpdate(br_model *pModel, br_scalar x0, br_scalar y0, br_scalar x1, br_scalar y1, br_scalar x2, br_scalar y2, br_scalar x3, br_scalar y3) {
    LOG_TRACE("(%p, %f, %f, %f, %f, %f, %f, %f, %f)", pModel, x0, y0, x1, y1, x2, y2, x3, y3);

    (void)pModel;
    (void)x0;
    (void)y0;
    (void)x1;
    (void)y1;
    (void)x2;
    (void)y2;
    (void)x3;
    (void)y3;

    if (function_hook_state_PedModelUpdate == HOOK_ENABLED) {
        assert(0 && "PedModelUpdate not implemented.");
        abort();
    } else {
        original_PedModelUpdate(pModel, x0, y0, x1, y1, x2, y2, x3, y3);
    }
}

function_hook_state_t function_hook_state_ActorIsPedestrian = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(ActorIsPedestrian, function_hook_state_ActorIsPedestrian)
static int(__cdecl*original_ActorIsPedestrian)(br_actor *) = (int(__cdecl*)(br_actor *))0x00455870;
CARM95_HOOK_FUNCTION(original_ActorIsPedestrian, ActorIsPedestrian)
int __cdecl ActorIsPedestrian(br_actor *pActor) {
    LOG_TRACE("(%p)", pActor);

    (void)pActor;

    if (function_hook_state_ActorIsPedestrian == HOOK_ENABLED) {
        assert(0 && "ActorIsPedestrian not implemented.");
        abort();
    } else {
        return original_ActorIsPedestrian(pActor);
    }
}

function_hook_state_t function_hook_state_PedHeightFromActor = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(PedHeightFromActor, function_hook_state_PedHeightFromActor)
static br_scalar(__cdecl*original_PedHeightFromActor)(br_actor *) = (br_scalar(__cdecl*)(br_actor *))0x004558b8;
CARM95_HOOK_FUNCTION(original_PedHeightFromActor, PedHeightFromActor)
br_scalar __cdecl PedHeightFromActor(br_actor *pActor) {
    LOG_TRACE("(%p)", pActor);

    (void)pActor;

    if (function_hook_state_PedHeightFromActor == HOOK_ENABLED) {
        assert(0 && "PedHeightFromActor not implemented.");
        abort();
    } else {
        return original_PedHeightFromActor(pActor);
    }
}

function_hook_state_t function_hook_state_GetPedestrianValue = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(GetPedestrianValue, function_hook_state_GetPedestrianValue)
static int(__cdecl*original_GetPedestrianValue)(br_actor *) = (int(__cdecl*)(br_actor *))0x004558fa;
CARM95_HOOK_FUNCTION(original_GetPedestrianValue, GetPedestrianValue)
int __cdecl GetPedestrianValue(br_actor *pActor) {
    LOG_TRACE("(%p)", pActor);

    (void)pActor;

    if (function_hook_state_GetPedestrianValue == HOOK_ENABLED) {
        assert(0 && "GetPedestrianValue not implemented.");
        abort();
    } else {
        return original_GetPedestrianValue(pActor);
    }
}

function_hook_state_t function_hook_state_PedestrianActorIsPerson = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(PedestrianActorIsPerson, function_hook_state_PedestrianActorIsPerson)
static int(__cdecl*original_PedestrianActorIsPerson)(br_actor *) = (int(__cdecl*)(br_actor *))0x00455913;
CARM95_HOOK_FUNCTION(original_PedestrianActorIsPerson, PedestrianActorIsPerson)
int __cdecl PedestrianActorIsPerson(br_actor *pActor) {
    LOG_TRACE("(%p)", pActor);

    (void)pActor;

    if (function_hook_state_PedestrianActorIsPerson == HOOK_ENABLED) {
        assert(0 && "PedestrianActorIsPerson not implemented.");
        abort();
    } else {
        return original_PedestrianActorIsPerson(pActor);
    }
}

function_hook_state_t function_hook_state_GetPedestrianActor = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(GetPedestrianActor, function_hook_state_GetPedestrianActor)
static br_actor *(__cdecl*original_GetPedestrianActor)(int) = (br_actor *(__cdecl*)(int))0x00455953;
CARM95_HOOK_FUNCTION(original_GetPedestrianActor, GetPedestrianActor)
br_actor* __cdecl GetPedestrianActor(int pIndex) {
    LOG_TRACE("(%d)", pIndex);

    (void)pIndex;

    if (function_hook_state_GetPedestrianActor == HOOK_ENABLED) {
        assert(0 && "GetPedestrianActor not implemented.");
        abort();
    } else {
        return original_GetPedestrianActor(pIndex);
    }
}

function_hook_state_t function_hook_state_GetPedestrianTexture = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(GetPedestrianTexture, function_hook_state_GetPedestrianTexture)
static br_pixelmap *(__cdecl*original_GetPedestrianTexture)(br_actor *, int *) = (br_pixelmap *(__cdecl*)(br_actor *, int *))0x0045599e;
CARM95_HOOK_FUNCTION(original_GetPedestrianTexture, GetPedestrianTexture)
br_pixelmap* __cdecl GetPedestrianTexture(br_actor *pActor, int *pFlipped) {
    LOG_TRACE("(%p, %p)", pActor, pFlipped);

    (void)pActor;
    (void)pFlipped;

    if (function_hook_state_GetPedestrianTexture == HOOK_ENABLED) {
        assert(0 && "GetPedestrianTexture not implemented.");
        abort();
    } else {
        return original_GetPedestrianTexture(pActor, pFlipped);
    }
}

function_hook_state_t function_hook_state_TogglePedestrians = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(TogglePedestrians, function_hook_state_TogglePedestrians)
static void(__cdecl*original_TogglePedestrians)() = (void(__cdecl*)())0x004559ea;
CARM95_HOOK_FUNCTION(original_TogglePedestrians, TogglePedestrians)
void __cdecl TogglePedestrians() {
    LOG_TRACE("()");


    if (function_hook_state_TogglePedestrians == HOOK_ENABLED) {
        assert(0 && "TogglePedestrians not implemented.");
        abort();
    } else {
        original_TogglePedestrians();
    }
}

function_hook_state_t function_hook_state_InitPedGibs = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(InitPedGibs, function_hook_state_InitPedGibs)
static void(__cdecl*original_InitPedGibs)() = (void(__cdecl*)())0x0045e3ad;
CARM95_HOOK_FUNCTION(original_InitPedGibs, InitPedGibs)
void __cdecl InitPedGibs() {
    int i;
    int j;
    br_model *the_model;
    br_pixelmap *the_pix;
    br_material *the_material;
    LOG_TRACE("()");

    (void)i;
    (void)j;
    (void)the_model;
    (void)the_pix;
    (void)the_material;

    if (function_hook_state_InitPedGibs == HOOK_ENABLED) {
        assert(0 && "InitPedGibs not implemented.");
        abort();
    } else {
        original_InitPedGibs();
    }
}

function_hook_state_t function_hook_state_SetPedMaterialForRender = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(SetPedMaterialForRender, function_hook_state_SetPedMaterialForRender)
static void(__cdecl*original_SetPedMaterialForRender)(br_actor *) = (void(__cdecl*)(br_actor *))0x00455a76;
CARM95_HOOK_FUNCTION(original_SetPedMaterialForRender, SetPedMaterialForRender)
void __cdecl SetPedMaterialForRender(br_actor *pActor) {
    tPedestrian_data *ped;
    int changed;
    LOG_TRACE("(%p)", pActor);

    (void)pActor;
    (void)ped;
    (void)changed;

    if (function_hook_state_SetPedMaterialForRender == HOOK_ENABLED) {
        assert(0 && "SetPedMaterialForRender not implemented.");
        abort();
    } else {
        original_SetPedMaterialForRender(pActor);
    }
}

function_hook_state_t function_hook_state_PedCallBack = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(PedCallBack, function_hook_state_PedCallBack)
static void(__cdecl*original_PedCallBack)(br_actor *, struct br_model *, struct br_material *, void *, br_uint_8, int) = (void(__cdecl*)(br_actor *, struct br_model *, struct br_material *, void *, br_uint_8, int))0x00455b6f;
CARM95_HOOK_FUNCTION(original_PedCallBack, PedCallBack)
void __cdecl PedCallBack(br_actor *pActor, struct br_model *pModel, struct br_material *pMaterial, void *pRender_data, br_uint_8 pStyle, int pOn_screen) {
    tPedestrian_data *ped;
    LOG_TRACE("(%p, %p, %p, %p, %u, %d)", pActor, pModel, pMaterial, pRender_data, pStyle, pOn_screen);

    (void)pActor;
    (void)pModel;
    (void)pMaterial;
    (void)pRender_data;
    (void)pStyle;
    (void)pOn_screen;
    (void)ped;

    if (function_hook_state_PedCallBack == HOOK_ENABLED) {
        assert(0 && "PedCallBack not implemented.");
        abort();
    } else {
        original_PedCallBack(pActor, pModel, pMaterial, pRender_data, pStyle, pOn_screen);
    }
}

function_hook_state_t function_hook_state_InitPeds = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(InitPeds, function_hook_state_InitPeds)
static void(__cdecl*original_InitPeds)() = (void(__cdecl*)())0x00455c05;
CARM95_HOOK_FUNCTION(original_InitPeds, InitPeds)
void __cdecl InitPeds() {
    LOG_TRACE("()");


    if (function_hook_state_InitPeds == HOOK_ENABLED) {
        assert(0 && "InitPeds not implemented.");
        abort();
    } else {
        original_InitPeds();
    }
}

function_hook_state_t function_hook_state_MungeModelSize = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(MungeModelSize, function_hook_state_MungeModelSize)
static void(__cdecl*original_MungeModelSize)(br_actor *, br_scalar) = (void(__cdecl*)(br_actor *, br_scalar))0x00455f31;
CARM95_HOOK_FUNCTION(original_MungeModelSize, MungeModelSize)
void __cdecl MungeModelSize(br_actor *pActor, br_scalar pScaling_factor) {
    br_pixelmap *the_pix;
    br_scalar half_width;
    br_scalar half_height;
    LOG_TRACE("(%p, %f)", pActor, pScaling_factor);

    (void)pActor;
    (void)pScaling_factor;
    (void)the_pix;
    (void)half_width;
    (void)half_height;

    if (function_hook_state_MungeModelSize == HOOK_ENABLED) {
        assert(0 && "MungeModelSize not implemented.");
        abort();
    } else {
        original_MungeModelSize(pActor, pScaling_factor);
    }
}

function_hook_state_t function_hook_state_BurstPedestrian = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(BurstPedestrian, function_hook_state_BurstPedestrian)
static int(__cdecl*original_BurstPedestrian)(tPedestrian_data *, float, int) = (int(__cdecl*)(tPedestrian_data *, float, int))0x00457ff5;
CARM95_HOOK_FUNCTION(original_BurstPedestrian, BurstPedestrian)
int __cdecl BurstPedestrian(tPedestrian_data *pPedestrian, float pSplattitudinalitude, int pAllow_explosion) {
    int i;
    int j;
    int gib_index;
    int next_gib_index;
    int size_threshold;
    int current_size;
    int max_size;
    int gib_count;
    int exploded;
    tPed_gib *the_ped_gib;
    br_scalar min_speed;
    br_scalar max_speed;
    tU32 the_time;
    LOG_TRACE("(%p, %f, %d)", pPedestrian, pSplattitudinalitude, pAllow_explosion);

    (void)pPedestrian;
    (void)pSplattitudinalitude;
    (void)pAllow_explosion;
    (void)i;
    (void)j;
    (void)gib_index;
    (void)next_gib_index;
    (void)size_threshold;
    (void)current_size;
    (void)max_size;
    (void)gib_count;
    (void)exploded;
    (void)the_ped_gib;
    (void)min_speed;
    (void)max_speed;
    (void)the_time;

    if (function_hook_state_BurstPedestrian == HOOK_ENABLED) {
        assert(0 && "BurstPedestrian not implemented.");
        abort();
    } else {
        return original_BurstPedestrian(pPedestrian, pSplattitudinalitude, pAllow_explosion);
    }
}

function_hook_state_t function_hook_state_ResetAllPedGibs = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(ResetAllPedGibs, function_hook_state_ResetAllPedGibs)
static void(__cdecl*original_ResetAllPedGibs)() = (void(__cdecl*)())0x00455df2;
CARM95_HOOK_FUNCTION(original_ResetAllPedGibs, ResetAllPedGibs)
void __cdecl ResetAllPedGibs() {
    int i;
    tPed_gib *the_ped_gib;
    LOG_TRACE("()");

    (void)i;
    (void)the_ped_gib;

    if (function_hook_state_ResetAllPedGibs == HOOK_ENABLED) {
        assert(0 && "ResetAllPedGibs not implemented.");
        abort();
    } else {
        original_ResetAllPedGibs();
    }
}

function_hook_state_t function_hook_state_AdjustPedGib = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(AdjustPedGib, function_hook_state_AdjustPedGib)
static void(__cdecl*original_AdjustPedGib)(int, int, int, int, br_matrix34 *) = (void(__cdecl*)(int, int, int, int, br_matrix34 *))0x00455e72;
CARM95_HOOK_FUNCTION(original_AdjustPedGib, AdjustPedGib)
void __cdecl AdjustPedGib(int pIndex, int pSize, int pGib_index, int pPed_index, br_matrix34 *pTrans) {
    tPed_gib *the_ped_gib;
    LOG_TRACE("(%d, %d, %d, %d, %p)", pIndex, pSize, pGib_index, pPed_index, pTrans);

    (void)pIndex;
    (void)pSize;
    (void)pGib_index;
    (void)pPed_index;
    (void)pTrans;
    (void)the_ped_gib;

    if (function_hook_state_AdjustPedGib == HOOK_ENABLED) {
        assert(0 && "AdjustPedGib not implemented.");
        abort();
    } else {
        original_AdjustPedGib(pIndex, pSize, pGib_index, pPed_index, pTrans);
    }
}

function_hook_state_t function_hook_state_MungePedGibs = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(MungePedGibs, function_hook_state_MungePedGibs)
static void(__cdecl*original_MungePedGibs)(tU32) = (void(__cdecl*)(tU32))0x00456048;
CARM95_HOOK_FUNCTION(original_MungePedGibs, MungePedGibs)
void __cdecl MungePedGibs(tU32 pFrame_period) {
    int i;
    int frame;
    tPed_gib *the_ped_gib;
    br_scalar s_frame_period;
    tU32 the_time;
    tPedestrian_data *pedestrian;
    LOG_TRACE("(%u)", pFrame_period);

    (void)pFrame_period;
    (void)i;
    (void)frame;
    (void)the_ped_gib;
    (void)s_frame_period;
    (void)the_time;
    (void)pedestrian;

    if (function_hook_state_MungePedGibs == HOOK_ENABLED) {
        assert(0 && "MungePedGibs not implemented.");
        abort();
    } else {
        original_MungePedGibs(pFrame_period);
    }
}

function_hook_state_t function_hook_state_KillPedestrian = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(KillPedestrian, function_hook_state_KillPedestrian)
static void(__cdecl*original_KillPedestrian)(tPedestrian_data *) = (void(__cdecl*)(tPedestrian_data *))0x00456e92;
CARM95_HOOK_FUNCTION(original_KillPedestrian, KillPedestrian)
void __cdecl KillPedestrian(tPedestrian_data *pPedestrian) {
    LOG_TRACE("(%p)", pPedestrian);

    (void)pPedestrian;

    if (function_hook_state_KillPedestrian == HOOK_ENABLED) {
        assert(0 && "KillPedestrian not implemented.");
        abort();
    } else {
        original_KillPedestrian(pPedestrian);
    }
}

function_hook_state_t function_hook_state_CalcPedWidthNHeight = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(CalcPedWidthNHeight, function_hook_state_CalcPedWidthNHeight)
static void(__cdecl*original_CalcPedWidthNHeight)(tPedestrian_data *, br_pixelmap *, br_scalar *, br_scalar *) = (void(__cdecl*)(tPedestrian_data *, br_pixelmap *, br_scalar *, br_scalar *))0x00457492;
CARM95_HOOK_FUNCTION(original_CalcPedWidthNHeight, CalcPedWidthNHeight)
void __cdecl CalcPedWidthNHeight(tPedestrian_data *pPedestrian, br_pixelmap *pPixelmap, br_scalar *pHeight, br_scalar *pWidth) {
    br_pixelmap *reference_pixel_bastard;
    br_scalar scale_to_use;
    LOG_TRACE("(%p, %p, %p, %p)", pPedestrian, pPixelmap, pHeight, pWidth);

    (void)pPedestrian;
    (void)pPixelmap;
    (void)pHeight;
    (void)pWidth;
    (void)reference_pixel_bastard;
    (void)scale_to_use;

    if (function_hook_state_CalcPedWidthNHeight == HOOK_ENABLED) {
        assert(0 && "CalcPedWidthNHeight not implemented.");
        abort();
    } else {
        original_CalcPedWidthNHeight(pPedestrian, pPixelmap, pHeight, pWidth);
    }
}

function_hook_state_t function_hook_state_PedestrianNextInstruction = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(PedestrianNextInstruction, function_hook_state_PedestrianNextInstruction)
static int(__cdecl*original_PedestrianNextInstruction)(tPedestrian_data *, float, int, int) = (int(__cdecl*)(tPedestrian_data *, float, int, int))0x004585f1;
CARM95_HOOK_FUNCTION(original_PedestrianNextInstruction, PedestrianNextInstruction)
int __cdecl PedestrianNextInstruction(tPedestrian_data *pPedestrian, float pDanger_level, int pPosition_explicitly, int pMove_pc) {
    tPedestrian_instruction *instruction;
    float most_dangerous;
    float chance_value;
    int result;
    int start_index;
    int end_index;
    int i;
    int j;
    int choice;
    int the_marker_ref;
    br_scalar __block0___scale;
    LOG_TRACE("(%p, %f, %d, %d)", pPedestrian, pDanger_level, pPosition_explicitly, pMove_pc);

    (void)pPedestrian;
    (void)pDanger_level;
    (void)pPosition_explicitly;
    (void)pMove_pc;
    (void)instruction;
    (void)most_dangerous;
    (void)chance_value;
    (void)result;
    (void)start_index;
    (void)end_index;
    (void)i;
    (void)j;
    (void)choice;
    (void)the_marker_ref;
    (void)__block0___scale;

    if (function_hook_state_PedestrianNextInstruction == HOOK_ENABLED) {
        assert(0 && "PedestrianNextInstruction not implemented.");
        abort();
    } else {
        return original_PedestrianNextInstruction(pPedestrian, pDanger_level, pPosition_explicitly, pMove_pc);
    }
}

function_hook_state_t function_hook_state_MungePedestrianSequence = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(MungePedestrianSequence, function_hook_state_MungePedestrianSequence)
static void(__cdecl*original_MungePedestrianSequence)(tPedestrian_data *, int) = (void(__cdecl*)(tPedestrian_data *, int))0x004566ee;
CARM95_HOOK_FUNCTION(original_MungePedestrianSequence, MungePedestrianSequence)
void __cdecl MungePedestrianSequence(tPedestrian_data *pPedestrian, int pAction_changed) {
    tPedestrian_action *the_action;
    int i;
    int the_sequence;
    int current_looping;
    br_scalar ped_movement_angle;
    float heading_difference;
    tPedestrian_sequence *sequence_ptr;
    LOG_TRACE("(%p, %d)", pPedestrian, pAction_changed);

    (void)pPedestrian;
    (void)pAction_changed;
    (void)the_action;
    (void)i;
    (void)the_sequence;
    (void)current_looping;
    (void)ped_movement_angle;
    (void)heading_difference;
    (void)sequence_ptr;

    if (function_hook_state_MungePedestrianSequence == HOOK_ENABLED) {
        assert(0 && "MungePedestrianSequence not implemented.");
        abort();
    } else {
        original_MungePedestrianSequence(pPedestrian, pAction_changed);
    }
}

function_hook_state_t function_hook_state_DetachPedFromCar = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(DetachPedFromCar, function_hook_state_DetachPedFromCar)
static void(__cdecl*original_DetachPedFromCar)(tPedestrian_data *) = (void(__cdecl*)(tPedestrian_data *))0x004563dc;
CARM95_HOOK_FUNCTION(original_DetachPedFromCar, DetachPedFromCar)
void __cdecl DetachPedFromCar(tPedestrian_data *pPedestrian) {
    LOG_TRACE("(%p)", pPedestrian);

    (void)pPedestrian;

    if (function_hook_state_DetachPedFromCar == HOOK_ENABLED) {
        assert(0 && "DetachPedFromCar not implemented.");
        abort();
    } else {
        original_DetachPedFromCar(pPedestrian);
    }
}

function_hook_state_t function_hook_state_SetPedPos = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(SetPedPos, function_hook_state_SetPedPos)
static void(__cdecl*original_SetPedPos)(tPedestrian_data *) = (void(__cdecl*)(tPedestrian_data *))0x0045647b;
CARM95_HOOK_FUNCTION(original_SetPedPos, SetPedPos)
void __cdecl SetPedPos(tPedestrian_data *pPedestrian) {
    br_vector3 temp_v;
    LOG_TRACE("(%p)", pPedestrian);

    (void)pPedestrian;
    (void)temp_v;

    if (function_hook_state_SetPedPos == HOOK_ENABLED) {
        assert(0 && "SetPedPos not implemented.");
        abort();
    } else {
        original_SetPedPos(pPedestrian);
    }
}

function_hook_state_t function_hook_state_DetachPedActorFromCar = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(DetachPedActorFromCar, function_hook_state_DetachPedActorFromCar)
static void(__cdecl*original_DetachPedActorFromCar)(br_actor *) = (void(__cdecl*)(br_actor *))0x004563b3;
CARM95_HOOK_FUNCTION(original_DetachPedActorFromCar, DetachPedActorFromCar)
void __cdecl DetachPedActorFromCar(br_actor *pActor) {
    LOG_TRACE("(%p)", pActor);

    (void)pActor;

    if (function_hook_state_DetachPedActorFromCar == HOOK_ENABLED) {
        assert(0 && "DetachPedActorFromCar not implemented.");
        abort();
    } else {
        original_DetachPedActorFromCar(pActor);
    }
}

function_hook_state_t function_hook_state_MungePedestrianFrames = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(MungePedestrianFrames, function_hook_state_MungePedestrianFrames)
static void(__cdecl*original_MungePedestrianFrames)(tPedestrian_data *) = (void(__cdecl*)(tPedestrian_data *))0x004568d7;
CARM95_HOOK_FUNCTION(original_MungePedestrianFrames, MungePedestrianFrames)
void __cdecl MungePedestrianFrames(tPedestrian_data *pPedestrian) {
    tPedestrian_sequence *the_sequence;
    float f_the_time;
    float frame_period;
    int frame_offset;
    int number_of_frames;
    int new_frame;
    tU32 the_time;
    LOG_TRACE("(%p)", pPedestrian);

    (void)pPedestrian;
    (void)the_sequence;
    (void)f_the_time;
    (void)frame_period;
    (void)frame_offset;
    (void)number_of_frames;
    (void)new_frame;
    (void)the_time;

    if (function_hook_state_MungePedestrianFrames == HOOK_ENABLED) {
        assert(0 && "MungePedestrianFrames not implemented.");
        abort();
    } else {
        original_MungePedestrianFrames(pPedestrian);
    }
}

function_hook_state_t function_hook_state_MungePedModel = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(MungePedModel, function_hook_state_MungePedModel)
static void(__cdecl*original_MungePedModel)(tPedestrian_data *) = (void(__cdecl*)(tPedestrian_data *))0x00456f86;
CARM95_HOOK_FUNCTION(original_MungePedModel, MungePedModel)
void __cdecl MungePedModel(tPedestrian_data *pPedestrian) {
    br_vector3 old_pos;
    br_vector3 delta_pos;
    br_scalar height_over2;
    br_matrix34 mat;
    br_scalar x_offset;
    br_scalar y_offset;
    br_scalar temp_scalar;
    br_scalar *component_address;
    br_pixelmap *current_pixel_bastard;
    br_pixelmap *reference_pixel_bastard;
    br_vertex *vertices;
    int model_changed;
    tPed_frame_info *the_frame;
    tCar_spec *murderer;
    br_actor *old_parent;
    LOG_TRACE("(%p)", pPedestrian);

    (void)pPedestrian;
    (void)old_pos;
    (void)delta_pos;
    (void)height_over2;
    (void)mat;
    (void)x_offset;
    (void)y_offset;
    (void)temp_scalar;
    (void)component_address;
    (void)current_pixel_bastard;
    (void)reference_pixel_bastard;
    (void)vertices;
    (void)model_changed;
    (void)the_frame;
    (void)murderer;
    (void)old_parent;

    if (function_hook_state_MungePedModel == HOOK_ENABLED) {
        assert(0 && "MungePedModel not implemented.");
        abort();
    } else {
        original_MungePedModel(pPedestrian);
    }
}

function_hook_state_t function_hook_state_ChangeActionTo = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(ChangeActionTo, function_hook_state_ChangeActionTo)
static void(__cdecl*original_ChangeActionTo)(tPedestrian_data *, int, int) = (void(__cdecl*)(tPedestrian_data *, int, int))0x0045654d;
CARM95_HOOK_FUNCTION(original_ChangeActionTo, ChangeActionTo)
void __cdecl ChangeActionTo(tPedestrian_data *pPedestrian, int pAction_index, int pRedo_frames_etc) {
    tPedestrian_action *the_action;
    int the_sound;
    tU32 the_pitch;
    LOG_TRACE("(%p, %d, %d)", pPedestrian, pAction_index, pRedo_frames_etc);

    (void)pPedestrian;
    (void)pAction_index;
    (void)pRedo_frames_etc;
    (void)the_action;
    (void)the_sound;
    (void)the_pitch;

    if (function_hook_state_ChangeActionTo == HOOK_ENABLED) {
        assert(0 && "ChangeActionTo not implemented.");
        abort();
    } else {
        original_ChangeActionTo(pPedestrian, pAction_index, pRedo_frames_etc);
    }
}

function_hook_state_t function_hook_state_MungePedestrianAction = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(MungePedestrianAction, function_hook_state_MungePedestrianAction)
static int(__cdecl*original_MungePedestrianAction)(tPedestrian_data *, float) = (int(__cdecl*)(tPedestrian_data *, float))0x00459db7;
CARM95_HOOK_FUNCTION(original_MungePedestrianAction, MungePedestrianAction)
int __cdecl MungePedestrianAction(tPedestrian_data *pPedestrian, float pDanger_level) {
    tU32 time_diff;
    int i;
    int choice;
    int start_index;
    int end_index;
    float chance_value;
    float most_dangerous;
    LOG_TRACE("(%p, %f)", pPedestrian, pDanger_level);

    (void)pPedestrian;
    (void)pDanger_level;
    (void)time_diff;
    (void)i;
    (void)choice;
    (void)start_index;
    (void)end_index;
    (void)chance_value;
    (void)most_dangerous;

    if (function_hook_state_MungePedestrianAction == HOOK_ENABLED) {
        assert(0 && "MungePedestrianAction not implemented.");
        abort();
    } else {
        return original_MungePedestrianAction(pPedestrian, pDanger_level);
    }
}

function_hook_state_t function_hook_state_MakeFlagWavingBastardWaveHisFlagWhichIsTheProbablyTheLastThingHeWillEverDo = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(MakeFlagWavingBastardWaveHisFlagWhichIsTheProbablyTheLastThingHeWillEverDo, function_hook_state_MakeFlagWavingBastardWaveHisFlagWhichIsTheProbablyTheLastThingHeWillEverDo)
static void(__cdecl*original_MakeFlagWavingBastardWaveHisFlagWhichIsTheProbablyTheLastThingHeWillEverDo)() = (void(__cdecl*)())0x004564ed;
CARM95_HOOK_FUNCTION(original_MakeFlagWavingBastardWaveHisFlagWhichIsTheProbablyTheLastThingHeWillEverDo, MakeFlagWavingBastardWaveHisFlagWhichIsTheProbablyTheLastThingHeWillEverDo)
void __cdecl MakeFlagWavingBastardWaveHisFlagWhichIsTheProbablyTheLastThingHeWillEverDo() {
    LOG_TRACE("()");


    if (function_hook_state_MakeFlagWavingBastardWaveHisFlagWhichIsTheProbablyTheLastThingHeWillEverDo == HOOK_ENABLED) {
        assert(0 && "MakeFlagWavingBastardWaveHisFlagWhichIsTheProbablyTheLastThingHeWillEverDo not implemented.");
        abort();
    } else {
        original_MakeFlagWavingBastardWaveHisFlagWhichIsTheProbablyTheLastThingHeWillEverDo();
    }
}

function_hook_state_t function_hook_state_MungePedestrianPath = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(MungePedestrianPath, function_hook_state_MungePedestrianPath)
static void(__cdecl*original_MungePedestrianPath)(tPedestrian_data *, float, br_vector3 *) = (void(__cdecl*)(tPedestrian_data *, float, br_vector3 *))0x00457548;
CARM95_HOOK_FUNCTION(original_MungePedestrianPath, MungePedestrianPath)
void __cdecl MungePedestrianPath(tPedestrian_data *pPedestrian, float pDanger_level, br_vector3 *pDanger_direction) {
    tPedestrian_action *the_action;
    float terminal_speed;
    float new_falling_speed;
    float grav_times_period;
    float ped_gravity;
    br_vector3 movement_vector;
    br_vector3 over_shoot;
    br_vector3 cast_point;
    br_scalar old_y;
    br_scalar new_y;
    int damage;
    tU32 the_pitch;
    LOG_TRACE("(%p, %f, %p)", pPedestrian, pDanger_level, pDanger_direction);

    (void)pPedestrian;
    (void)pDanger_level;
    (void)pDanger_direction;
    (void)the_action;
    (void)terminal_speed;
    (void)new_falling_speed;
    (void)grav_times_period;
    (void)ped_gravity;
    (void)movement_vector;
    (void)over_shoot;
    (void)cast_point;
    (void)old_y;
    (void)new_y;
    (void)damage;
    (void)the_pitch;

    if (function_hook_state_MungePedestrianPath == HOOK_ENABLED) {
        assert(0 && "MungePedestrianPath not implemented.");
        abort();
    } else {
        original_MungePedestrianPath(pPedestrian, pDanger_level, pDanger_direction);
    }
}

function_hook_state_t function_hook_state_CalcPedestrianDangerLevel = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(CalcPedestrianDangerLevel, function_hook_state_CalcPedestrianDangerLevel)
static float(__cdecl*original_CalcPedestrianDangerLevel)(tPedestrian_data *, br_vector3 *) = (float(__cdecl*)(tPedestrian_data *, br_vector3 *))0x0045a078;
CARM95_HOOK_FUNCTION(original_CalcPedestrianDangerLevel, CalcPedestrianDangerLevel)
float __cdecl CalcPedestrianDangerLevel(tPedestrian_data *pPedestrian, br_vector3 *pDanger_direction) {
    br_vector3 *ped_pos;
    int i;
    float most_dangerous;
    float this_danger;
    br_scalar distance_squared;
    br_scalar car_movement_angle;
    br_scalar car_to_pedestrian_angle;
    br_scalar heading_difference;
    br_scalar camera_view_angle;
    tCar_spec *car;
    LOG_TRACE("(%p, %p)", pPedestrian, pDanger_direction);

    (void)pPedestrian;
    (void)pDanger_direction;
    (void)ped_pos;
    (void)i;
    (void)most_dangerous;
    (void)this_danger;
    (void)distance_squared;
    (void)car_movement_angle;
    (void)car_to_pedestrian_angle;
    (void)heading_difference;
    (void)camera_view_angle;
    (void)car;

    if (function_hook_state_CalcPedestrianDangerLevel == HOOK_ENABLED) {
        assert(0 && "CalcPedestrianDangerLevel not implemented.");
        abort();
    } else {
        return original_CalcPedestrianDangerLevel(pPedestrian, pDanger_direction);
    }
}

function_hook_state_t function_hook_state_MoveToEdgeOfCar = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(MoveToEdgeOfCar, function_hook_state_MoveToEdgeOfCar)
static tPed_hit_position(__cdecl*original_MoveToEdgeOfCar)(tPedestrian_data *, tCollision_info *, br_actor *, br_scalar, br_scalar, br_scalar, br_scalar, br_scalar, br_scalar, br_vector3 *, br_vector3 *) = (tPed_hit_position(__cdecl*)(tPedestrian_data *, tCollision_info *, br_actor *, br_scalar, br_scalar, br_scalar, br_scalar, br_scalar, br_scalar, br_vector3 *, br_vector3 *))0x0045bcc5;
CARM95_HOOK_FUNCTION(original_MoveToEdgeOfCar, MoveToEdgeOfCar)
tPed_hit_position __cdecl MoveToEdgeOfCar(tPedestrian_data *pPedestrian, tCollision_info *pCar, br_actor *pCar_actor, br_scalar pPed_x, br_scalar pPed_z, br_scalar pCar_bounds_min_x, br_scalar pCar_bounds_max_x, br_scalar pCar_bounds_min_z, br_scalar pCar_bounds_max_z, br_vector3 *pMin_ped_bounds_car, br_vector3 *pMax_ped_bounds_car) {
    br_vector3 car_plus_ped;
    br_vector3 delta_vector;
    br_vector3 ped_move_in_car;
    br_vector3 ped_move_in_global;
    br_vector3 scaled_car_direction;
    br_vector3 scaled_ped_direction;
    br_matrix34 global_to_car;
    br_scalar z_to_use;
    br_scalar x_to_use;
    br_scalar t;
    br_scalar x;
    br_scalar z;
    tPed_hit_position result;
    LOG_TRACE("(%p, %p, %p, %f, %f, %f, %f, %f, %f, %p, %p)", pPedestrian, pCar, pCar_actor, pPed_x, pPed_z, pCar_bounds_min_x, pCar_bounds_max_x, pCar_bounds_min_z, pCar_bounds_max_z, pMin_ped_bounds_car, pMax_ped_bounds_car);

    (void)pPedestrian;
    (void)pCar;
    (void)pCar_actor;
    (void)pPed_x;
    (void)pPed_z;
    (void)pCar_bounds_min_x;
    (void)pCar_bounds_max_x;
    (void)pCar_bounds_min_z;
    (void)pCar_bounds_max_z;
    (void)pMin_ped_bounds_car;
    (void)pMax_ped_bounds_car;
    (void)car_plus_ped;
    (void)delta_vector;
    (void)ped_move_in_car;
    (void)ped_move_in_global;
    (void)scaled_car_direction;
    (void)scaled_ped_direction;
    (void)global_to_car;
    (void)z_to_use;
    (void)x_to_use;
    (void)t;
    (void)x;
    (void)z;
    (void)result;

    if (function_hook_state_MoveToEdgeOfCar == HOOK_ENABLED) {
        assert(0 && "MoveToEdgeOfCar not implemented.");
        abort();
    } else {
        return original_MoveToEdgeOfCar(pPedestrian, pCar, pCar_actor, pPed_x, pPed_z, pCar_bounds_min_x, pCar_bounds_max_x, pCar_bounds_min_z, pCar_bounds_max_z, pMin_ped_bounds_car, pMax_ped_bounds_car);
    }
}

function_hook_state_t function_hook_state_CheckLastPed = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(CheckLastPed, function_hook_state_CheckLastPed)
static void(__cdecl*original_CheckLastPed)() = (void(__cdecl*)())0x0045c0db;
CARM95_HOOK_FUNCTION(original_CheckLastPed, CheckLastPed)
void __cdecl CheckLastPed() {
    LOG_TRACE("()");


    if (function_hook_state_CheckLastPed == HOOK_ENABLED) {
        assert(0 && "CheckLastPed not implemented.");
        abort();
    } else {
        original_CheckLastPed();
    }
}

function_hook_state_t function_hook_state_BloodyWheels = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(BloodyWheels, function_hook_state_BloodyWheels)
static int(__cdecl*original_BloodyWheels)(tCar_spec *, br_vector3 *, br_scalar, br_vector3 *) = (int(__cdecl*)(tCar_spec *, br_vector3 *, br_scalar, br_vector3 *))0x0045c12c;
CARM95_HOOK_FUNCTION(original_BloodyWheels, BloodyWheels)
int __cdecl BloodyWheels(tCar_spec *pCar, br_vector3 *pPed_car, br_scalar pSize, br_vector3 *pPed_glob) {
    int wheel;
    int squish;
    br_scalar ped_m_z;
    br_scalar ped_m_x;
    br_scalar dist_sqr;
    br_scalar size_sqr;
    LOG_TRACE("(%p, %p, %f, %p)", pCar, pPed_car, pSize, pPed_glob);

    (void)pCar;
    (void)pPed_car;
    (void)pSize;
    (void)pPed_glob;
    (void)wheel;
    (void)squish;
    (void)ped_m_z;
    (void)ped_m_x;
    (void)dist_sqr;
    (void)size_sqr;

    if (function_hook_state_BloodyWheels == HOOK_ENABLED) {
        assert(0 && "BloodyWheels not implemented.");
        abort();
    } else {
        return original_BloodyWheels(pCar, pPed_car, pSize, pPed_glob);
    }
}

function_hook_state_t function_hook_state_FancyATossOffMate = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(FancyATossOffMate, function_hook_state_FancyATossOffMate)
static int(__cdecl*original_FancyATossOffMate)(tPedestrian_data *, tCollision_info *, float) = (int(__cdecl*)(tPedestrian_data *, tCollision_info *, float))0x0045c273;
CARM95_HOOK_FUNCTION(original_FancyATossOffMate, FancyATossOffMate)
int __cdecl FancyATossOffMate(tPedestrian_data *pPedestrian, tCollision_info *pCar, float pImpact_speed) {
    LOG_TRACE("(%p, %p, %f)", pPedestrian, pCar, pImpact_speed);

    (void)pPedestrian;
    (void)pCar;
    (void)pImpact_speed;

    if (function_hook_state_FancyATossOffMate == HOOK_ENABLED) {
        assert(0 && "FancyATossOffMate not implemented.");
        abort();
    } else {
        return original_FancyATossOffMate(pPedestrian, pCar, pImpact_speed);
    }
}

function_hook_state_t function_hook_state_CheckPedestrianDeathScenario = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(CheckPedestrianDeathScenario, function_hook_state_CheckPedestrianDeathScenario)
static void(__cdecl*original_CheckPedestrianDeathScenario)(tPedestrian_data *) = (void(__cdecl*)(tPedestrian_data *))0x0045a3bd;
CARM95_HOOK_FUNCTION(original_CheckPedestrianDeathScenario, CheckPedestrianDeathScenario)
void __cdecl CheckPedestrianDeathScenario(tPedestrian_data *pPedestrian) {
    int norman;
    int i;
    int tossing;
    int orig_gib_flag;
    int exploded;
    int proximity_rayed;
    int fated;
    int billiards_shot;
    int credits_value;
    br_vector3 *car_pos;
    br_vector3 *ped_pos;
    br_vector3 min_ped_bounds;
    br_vector3 max_ped_bounds;
    br_vector3 min_ped_bounds_car;
    br_vector3 max_ped_bounds_car;
    br_vector3 ped_to_car_vector;
    br_vector3 up;
    br_vector3 zero_v;
    br_scalar attitude;
    br_scalar distance_squared;
    br_scalar ped_centre_x;
    br_scalar ped_centre_y;
    br_scalar car_bounds_min_x;
    br_scalar car_bounds_max_x;
    br_scalar car_bounds_min_z;
    br_scalar car_bounds_max_z;
    br_scalar prev_car_bounds_min_x;
    br_scalar prev_car_bounds_max_x;
    br_scalar prev_car_bounds_min_z;
    br_scalar prev_car_bounds_max_z;
    br_scalar scalar_frame_time;
    br_scalar gross_dismiss;
    br_actor *car_actor;
    br_actor *incident_actor;
    br_matrix34 ped_to_car;
    tCollision_info *the_car;
    float impact_speed;
    float volume_damage;
    tU32 the_time;
    tPed_hit_position hit_pos;
    br_scalar __block0__temp;
    br_scalar __block1__temp;
    br_scalar __block2__temp;
    LOG_TRACE("(%p)", pPedestrian);

    (void)pPedestrian;
    (void)norman;
    (void)i;
    (void)tossing;
    (void)orig_gib_flag;
    (void)exploded;
    (void)proximity_rayed;
    (void)fated;
    (void)billiards_shot;
    (void)credits_value;
    (void)car_pos;
    (void)ped_pos;
    (void)min_ped_bounds;
    (void)max_ped_bounds;
    (void)min_ped_bounds_car;
    (void)max_ped_bounds_car;
    (void)ped_to_car_vector;
    (void)up;
    (void)zero_v;
    (void)attitude;
    (void)distance_squared;
    (void)ped_centre_x;
    (void)ped_centre_y;
    (void)car_bounds_min_x;
    (void)car_bounds_max_x;
    (void)car_bounds_min_z;
    (void)car_bounds_max_z;
    (void)prev_car_bounds_min_x;
    (void)prev_car_bounds_max_x;
    (void)prev_car_bounds_min_z;
    (void)prev_car_bounds_max_z;
    (void)scalar_frame_time;
    (void)gross_dismiss;
    (void)car_actor;
    (void)incident_actor;
    (void)ped_to_car;
    (void)the_car;
    (void)impact_speed;
    (void)volume_damage;
    (void)the_time;
    (void)hit_pos;
    (void)__block0__temp;
    (void)__block1__temp;
    (void)__block2__temp;

    if (function_hook_state_CheckPedestrianDeathScenario == HOOK_ENABLED) {
        assert(0 && "CheckPedestrianDeathScenario not implemented.");
        abort();
    } else {
        original_CheckPedestrianDeathScenario(pPedestrian);
    }
}

function_hook_state_t function_hook_state_SendPedestrian = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(SendPedestrian, function_hook_state_SendPedestrian)
static void(__cdecl*original_SendPedestrian)(tPedestrian_data *, int) = (void(__cdecl*)(tPedestrian_data *, int))0x0045c2f0;
CARM95_HOOK_FUNCTION(original_SendPedestrian, SendPedestrian)
void __cdecl SendPedestrian(tPedestrian_data *pPedestrian, int pIndex) {
    tNet_contents *the_contents;
    tNet_message *the_message;
    int size_decider;
    LOG_TRACE("(%p, %d)", pPedestrian, pIndex);

    (void)pPedestrian;
    (void)pIndex;
    (void)the_contents;
    (void)the_message;
    (void)size_decider;

    if (function_hook_state_SendPedestrian == HOOK_ENABLED) {
        assert(0 && "SendPedestrian not implemented.");
        abort();
    } else {
        original_SendPedestrian(pPedestrian, pIndex);
    }
}

function_hook_state_t function_hook_state_DoPedestrian = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(DoPedestrian, function_hook_state_DoPedestrian)
static void(__cdecl*original_DoPedestrian)(tPedestrian_data *, int) = (void(__cdecl*)(tPedestrian_data *, int))0x004598e2;
CARM95_HOOK_FUNCTION(original_DoPedestrian, DoPedestrian)
void __cdecl DoPedestrian(tPedestrian_data *pPedestrian, int pIndex) {
    float danger_level;
    float start_speed;
    int action_changed;
    int alive;
    int old_frame;
    int start_ins;
    int start_act;
    int start_hp;
    int start_ins_dir;
    br_vector3 danger_direction;
    br_vector3 old_pos;
    LOG_TRACE("(%p, %d)", pPedestrian, pIndex);

    (void)pPedestrian;
    (void)pIndex;
    (void)danger_level;
    (void)start_speed;
    (void)action_changed;
    (void)alive;
    (void)old_frame;
    (void)start_ins;
    (void)start_act;
    (void)start_hp;
    (void)start_ins_dir;
    (void)danger_direction;
    (void)old_pos;

    if (function_hook_state_DoPedestrian == HOOK_ENABLED) {
        assert(0 && "DoPedestrian not implemented.");
        abort();
    } else {
        original_DoPedestrian(pPedestrian, pIndex);
    }
}

function_hook_state_t function_hook_state_AdjustPedestrian = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(AdjustPedestrian, function_hook_state_AdjustPedestrian)
static void(__cdecl*original_AdjustPedestrian)(int, int, int, int, int, tU16, br_actor *, float, br_scalar, br_vector3 *, br_vector3 *) = (void(__cdecl*)(int, int, int, int, int, tU16, br_actor *, float, br_scalar, br_vector3 *, br_vector3 *))0x00458ec7;
CARM95_HOOK_FUNCTION(original_AdjustPedestrian, AdjustPedestrian)
void __cdecl AdjustPedestrian(int pIndex, int pAction_index, int pFrame_index, int pHit_points, int pDone_initial, tU16 pParent, br_actor *pParent_actor, float pSpin_period, br_scalar pJump_magnitude, br_vector3 *pOffset, br_vector3 *pTrans) {
    tPedestrian_data *pedestrian;
    br_actor *parent;
    br_vector3 old_pos;
    br_scalar __block0___scale;
    LOG_TRACE("(%d, %d, %d, %d, %d, %u, %p, %f, %f, %p, %p)", pIndex, pAction_index, pFrame_index, pHit_points, pDone_initial, pParent, pParent_actor, pSpin_period, pJump_magnitude, pOffset, pTrans);

    (void)pIndex;
    (void)pAction_index;
    (void)pFrame_index;
    (void)pHit_points;
    (void)pDone_initial;
    (void)pParent;
    (void)pParent_actor;
    (void)pSpin_period;
    (void)pJump_magnitude;
    (void)pOffset;
    (void)pTrans;
    (void)pedestrian;
    (void)parent;
    (void)old_pos;
    (void)__block0___scale;

    if (function_hook_state_AdjustPedestrian == HOOK_ENABLED) {
        assert(0 && "AdjustPedestrian not implemented.");
        abort();
    } else {
        original_AdjustPedestrian(pIndex, pAction_index, pFrame_index, pHit_points, pDone_initial, pParent, pParent_actor, pSpin_period, pJump_magnitude, pOffset, pTrans);
    }
}

function_hook_state_t function_hook_state_SquirtPathVertex = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(SquirtPathVertex, function_hook_state_SquirtPathVertex)
static void(__cdecl*original_SquirtPathVertex)(br_vertex *, br_vector3 *) = (void(__cdecl*)(br_vertex *, br_vector3 *))0x0045c66a;
CARM95_HOOK_FUNCTION(original_SquirtPathVertex, SquirtPathVertex)
void __cdecl SquirtPathVertex(br_vertex *pFirst_vertex, br_vector3 *pPoint) {
    LOG_TRACE("(%p, %p)", pFirst_vertex, pPoint);

    (void)pFirst_vertex;
    (void)pPoint;

    if (function_hook_state_SquirtPathVertex == HOOK_ENABLED) {
        assert(0 && "SquirtPathVertex not implemented.");
        abort();
    } else {
        original_SquirtPathVertex(pFirst_vertex, pPoint);
    }
}

function_hook_state_t function_hook_state_ResetAllPedestrians = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(ResetAllPedestrians, function_hook_state_ResetAllPedestrians)
static void(__cdecl*original_ResetAllPedestrians)() = (void(__cdecl*)())0x00459239;
CARM95_HOOK_FUNCTION(original_ResetAllPedestrians, ResetAllPedestrians)
void __cdecl ResetAllPedestrians() {
    int i;
    tPedestrian_data *the_pedestrian;
    LOG_TRACE("()");

    (void)i;
    (void)the_pedestrian;

    if (function_hook_state_ResetAllPedestrians == HOOK_ENABLED) {
        assert(0 && "ResetAllPedestrians not implemented.");
        abort();
    } else {
        original_ResetAllPedestrians();
    }
}

function_hook_state_t function_hook_state_GroundPedestrian = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(GroundPedestrian, function_hook_state_GroundPedestrian)
static void(__cdecl*original_GroundPedestrian)(tPedestrian_data *) = (void(__cdecl*)(tPedestrian_data *))0x0045c75a;
CARM95_HOOK_FUNCTION(original_GroundPedestrian, GroundPedestrian)
void __cdecl GroundPedestrian(tPedestrian_data *pPedestrian) {
    br_scalar new_y;
    br_vector3 cast_point;
    tPedestrian_sequence *sequence;
    LOG_TRACE("(%p)", pPedestrian);

    (void)pPedestrian;
    (void)new_y;
    (void)cast_point;
    (void)sequence;

    if (function_hook_state_GroundPedestrian == HOOK_ENABLED) {
        assert(0 && "GroundPedestrian not implemented.");
        abort();
    } else {
        original_GroundPedestrian(pPedestrian);
    }
}

function_hook_state_t function_hook_state_RevivePedestrian = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(RevivePedestrian, function_hook_state_RevivePedestrian)
static void(__cdecl*original_RevivePedestrian)(tPedestrian_data *, int) = (void(__cdecl*)(tPedestrian_data *, int))0x00459282;
CARM95_HOOK_FUNCTION(original_RevivePedestrian, RevivePedestrian)
void __cdecl RevivePedestrian(tPedestrian_data *pPedestrian, int pAnimate) {
    LOG_TRACE("(%p, %d)", pPedestrian, pAnimate);

    (void)pPedestrian;
    (void)pAnimate;

    if (function_hook_state_RevivePedestrian == HOOK_ENABLED) {
        assert(0 && "RevivePedestrian not implemented.");
        abort();
    } else {
        original_RevivePedestrian(pPedestrian, pAnimate);
    }
}

function_hook_state_t function_hook_state_MungePedestrians = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(MungePedestrians, function_hook_state_MungePedestrians)
static void(__cdecl*original_MungePedestrians)(tU32) = (void(__cdecl*)(tU32))0x00459476;
CARM95_HOOK_FUNCTION(original_MungePedestrians, MungePedestrians)
void __cdecl MungePedestrians(tU32 pFrame_period) {
    int i;
    int mirror_on;
    tPedestrian_data *the_pedestrian;
    br_vector3 ped_pos;
    br_vector3 ped_pos_car;
    br_vector3 ped_pos_temp;
    br_matrix34 ped_pos_matrix;
    br_camera *camera_ptr;
    br_scalar max_distance;
    br_scalar distance_squared;
    br_scalar x_delta;
    br_scalar y_delta;
    br_scalar z_delta;
    tS32 diff;
    LOG_TRACE("(%u)", pFrame_period);

    (void)pFrame_period;
    (void)i;
    (void)mirror_on;
    (void)the_pedestrian;
    (void)ped_pos;
    (void)ped_pos_car;
    (void)ped_pos_temp;
    (void)ped_pos_matrix;
    (void)camera_ptr;
    (void)max_distance;
    (void)distance_squared;
    (void)x_delta;
    (void)y_delta;
    (void)z_delta;
    (void)diff;

    if (function_hook_state_MungePedestrians == HOOK_ENABLED) {
        assert(0 && "MungePedestrians not implemented.");
        abort();
    } else {
        original_MungePedestrians(pFrame_period);
    }
}

function_hook_state_t function_hook_state_RespawnPedestrians = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(RespawnPedestrians, function_hook_state_RespawnPedestrians)
static void(__cdecl*original_RespawnPedestrians)() = (void(__cdecl*)())0x0045c921;
CARM95_HOOK_FUNCTION(original_RespawnPedestrians, RespawnPedestrians)
void __cdecl RespawnPedestrians() {
    int i;
    tPedestrian_data *the_pedestrian;
    LOG_TRACE("()");

    (void)i;
    (void)the_pedestrian;

    if (function_hook_state_RespawnPedestrians == HOOK_ENABLED) {
        assert(0 && "RespawnPedestrians not implemented.");
        abort();
    } else {
        original_RespawnPedestrians();
    }
}

function_hook_state_t function_hook_state_GetPedCount = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(GetPedCount, function_hook_state_GetPedCount)
static int(__cdecl*original_GetPedCount)() = (int(__cdecl*)())0x0045c9f6;
CARM95_HOOK_FUNCTION(original_GetPedCount, GetPedCount)
int __cdecl GetPedCount() {
    LOG_TRACE("()");


    if (function_hook_state_GetPedCount == HOOK_ENABLED) {
        assert(0 && "GetPedCount not implemented.");
        abort();
    } else {
        return original_GetPedCount();
    }
}

function_hook_state_t function_hook_state_GetPedPosition = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(GetPedPosition, function_hook_state_GetPedPosition)
static int(__cdecl*original_GetPedPosition)(int, br_vector3 *) = (int(__cdecl*)(int, br_vector3 *))0x0045ca0b;
CARM95_HOOK_FUNCTION(original_GetPedPosition, GetPedPosition)
int __cdecl GetPedPosition(int pIndex, br_vector3 *pPos) {
    tPedestrian_data *pedestrian;
    LOG_TRACE("(%d, %p)", pIndex, pPos);

    (void)pIndex;
    (void)pPos;
    (void)pedestrian;

    if (function_hook_state_GetPedPosition == HOOK_ENABLED) {
        assert(0 && "GetPedPosition not implemented.");
        abort();
    } else {
        return original_GetPedPosition(pIndex, pPos);
    }
}

function_hook_state_t function_hook_state_CreatePedestrian = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(CreatePedestrian, function_hook_state_CreatePedestrian)
static void(__cdecl*original_CreatePedestrian)(FILE *, tPedestrian_instruction *, int, int, int, int) = (void(__cdecl*)(FILE *, tPedestrian_instruction *, int, int, int, int))0x0045cb28;
CARM95_HOOK_FUNCTION(original_CreatePedestrian, CreatePedestrian)
void __cdecl CreatePedestrian(FILE *pG, tPedestrian_instruction *pInstructions, int pInstruc_count, int pInit_instruc, int pRef_num, int pForce_read) {
    tPath_name the_path;
    char s[256];
    char s2[256];
    char *str;
    char *str2;
    tPedestrian_data *the_pedestrian;
    tPedestrian_sequence *the_sequence;
    tPedestrian_action *the_action;
    br_model *the_model;
    int the_ref;
    int i;
    int j;
    int k;
    int l;
    int temp_int;
    int new_frames;
    tPed_collide_type collide_frame;
    float temp_float1;
    float temp_float2;
    br_scalar height;
    br_scalar width_over_2;
    br_scalar minnest_min;
    br_scalar maxest_min;
    br_scalar minnest_max;
    br_scalar maxest_max;
    LOG_TRACE("(%p, %p, %d, %d, %d, %d)", pG, pInstructions, pInstruc_count, pInit_instruc, pRef_num, pForce_read);

    (void)pG;
    (void)pInstructions;
    (void)pInstruc_count;
    (void)pInit_instruc;
    (void)pRef_num;
    (void)pForce_read;
    (void)the_path;
    (void)s;
    (void)s2;
    (void)str;
    (void)str2;
    (void)the_pedestrian;
    (void)the_sequence;
    (void)the_action;
    (void)the_model;
    (void)the_ref;
    (void)i;
    (void)j;
    (void)k;
    (void)l;
    (void)temp_int;
    (void)new_frames;
    (void)collide_frame;
    (void)temp_float1;
    (void)temp_float2;
    (void)height;
    (void)width_over_2;
    (void)minnest_min;
    (void)maxest_min;
    (void)minnest_max;
    (void)maxest_max;

    if (function_hook_state_CreatePedestrian == HOOK_ENABLED) {
        assert(0 && "CreatePedestrian not implemented.");
        abort();
    } else {
        original_CreatePedestrian(pG, pInstructions, pInstruc_count, pInit_instruc, pRef_num, pForce_read);
    }
}

function_hook_state_t function_hook_state_ResetProxRay = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(ResetProxRay, function_hook_state_ResetProxRay)
static void(__cdecl*original_ResetProxRay)() = (void(__cdecl*)())0x0045da5c;
CARM95_HOOK_FUNCTION(original_ResetProxRay, ResetProxRay)
void __cdecl ResetProxRay() {
    int i;
    LOG_TRACE("()");

    (void)i;

    if (function_hook_state_ResetProxRay == HOOK_ENABLED) {
        assert(0 && "ResetProxRay not implemented.");
        abort();
    } else {
        original_ResetProxRay();
    }
}

function_hook_state_t function_hook_state_PedMaterialFromHell = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(PedMaterialFromHell, function_hook_state_PedMaterialFromHell)
static void(__cdecl*original_PedMaterialFromHell)() = (void(__cdecl*)())0x0045da99;
CARM95_HOOK_FUNCTION(original_PedMaterialFromHell, PedMaterialFromHell)
void __cdecl PedMaterialFromHell() {
    LOG_TRACE("()");


    if (function_hook_state_PedMaterialFromHell == HOOK_ENABLED) {
        assert(0 && "PedMaterialFromHell not implemented.");
        abort();
    } else {
        original_PedMaterialFromHell();
    }
}

function_hook_state_t function_hook_state_ResetPedMaterial = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(ResetPedMaterial, function_hook_state_ResetPedMaterial)
static void(__cdecl*original_ResetPedMaterial)() = (void(__cdecl*)())0x0045daa4;
CARM95_HOOK_FUNCTION(original_ResetPedMaterial, ResetPedMaterial)
void __cdecl ResetPedMaterial() {
    int i;
    int j;
    LOG_TRACE("()");

    (void)i;
    (void)j;

    if (function_hook_state_ResetPedMaterial == HOOK_ENABLED) {
        assert(0 && "ResetPedMaterial not implemented.");
        abort();
    } else {
        original_ResetPedMaterial();
    }
}

function_hook_state_t function_hook_state_LoadInPedestrians = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(LoadInPedestrians, function_hook_state_LoadInPedestrians)
static void(__cdecl*original_LoadInPedestrians)(FILE *, int, tPed_subs *) = (void(__cdecl*)(FILE *, int, tPed_subs *))0x0045dab2;
CARM95_HOOK_FUNCTION(original_LoadInPedestrians, LoadInPedestrians)
void __cdecl LoadInPedestrians(FILE *pF, int pSubs_count, tPed_subs *pSubs_array) {
    tPath_name the_path;
    char s[256];
    char s2[256];
    char *str;
    char *str2;
    FILE *g;
    int the_ref;
    int i;
    int j;
    int k;
    int l;
    int knock_out;
    int check_for_duplicates;
    int duplicates_found;
    int temp_int;
    int ref_number;
    int instruc_count;
    int ped_count;
    int init_instruc;
    float temp_float1;
    float temp_float2;
    tPedestrian_instruction *instructions;
    tPedestrian_instruction *the_instruction;
    tPed_choice *the_choice;
    float __block0__x_0;
    float __block0__x_1;
    float __block0__x_2;
    float __block1__x_0;
    float __block1__x_1;
    float __block1__x_2;
    LOG_TRACE("(%p, %d, %p)", pF, pSubs_count, pSubs_array);

    (void)pF;
    (void)pSubs_count;
    (void)pSubs_array;
    (void)the_path;
    (void)s;
    (void)s2;
    (void)str;
    (void)str2;
    (void)g;
    (void)the_ref;
    (void)i;
    (void)j;
    (void)k;
    (void)l;
    (void)knock_out;
    (void)check_for_duplicates;
    (void)duplicates_found;
    (void)temp_int;
    (void)ref_number;
    (void)instruc_count;
    (void)ped_count;
    (void)init_instruc;
    (void)temp_float1;
    (void)temp_float2;
    (void)instructions;
    (void)the_instruction;
    (void)the_choice;
    (void)__block0__x_0;
    (void)__block0__x_1;
    (void)__block0__x_2;
    (void)__block1__x_0;
    (void)__block1__x_1;
    (void)__block1__x_2;

    if (function_hook_state_LoadInPedestrians == HOOK_ENABLED) {
        assert(0 && "LoadInPedestrians not implemented.");
        abort();
    } else {
        original_LoadInPedestrians(pF, pSubs_count, pSubs_array);
    }
}

function_hook_state_t function_hook_state_BuildPedPaths = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(BuildPedPaths, function_hook_state_BuildPedPaths)
static br_actor *(__cdecl*original_BuildPedPaths)(tPedestrian_instruction *, int, int) = (br_actor *(__cdecl*)(tPedestrian_instruction *, int, int))0x0045e839;
CARM95_HOOK_FUNCTION(original_BuildPedPaths, BuildPedPaths)
br_actor* __cdecl BuildPedPaths(tPedestrian_instruction *pInstructions, int pInstruc_count, int pInit_instruc) {
    int vertex_count;
    int last_vertex_count;
    int face_count;
    int j;
    int point_count;
    br_vector3 the_point;
    br_material *the_mat;
    br_model *the_model;
    br_actor *the_actor;
    LOG_TRACE("(%p, %d, %d)", pInstructions, pInstruc_count, pInit_instruc);

    (void)pInstructions;
    (void)pInstruc_count;
    (void)pInit_instruc;
    (void)vertex_count;
    (void)last_vertex_count;
    (void)face_count;
    (void)j;
    (void)point_count;
    (void)the_point;
    (void)the_mat;
    (void)the_model;
    (void)the_actor;

    if (function_hook_state_BuildPedPaths == HOOK_ENABLED) {
        assert(0 && "BuildPedPaths not implemented.");
        abort();
    } else {
        return original_BuildPedPaths(pInstructions, pInstruc_count, pInit_instruc);
    }
}

function_hook_state_t function_hook_state_WriteOutPeds = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(WriteOutPeds, function_hook_state_WriteOutPeds)
static void(__cdecl*original_WriteOutPeds)() = (void(__cdecl*)())0x0045ee73;
CARM95_HOOK_FUNCTION(original_WriteOutPeds, WriteOutPeds)
void __cdecl WriteOutPeds() {
    int i;
    int j;
    int k;
    int point_count;
    int min_ped;
    int min_point;
    br_vector3 the_point;
    br_vector3 last_point;
    br_scalar min_distance;
    br_scalar the_distance;
    char s[255];
    tPedestrian_data *the_pedestrian;
    tPedestrian_instruction *the_instruction;
    tPed_choice *the_choice;
    FILE *f;
    tPath_name the_path;
    LOG_TRACE("()");

    (void)i;
    (void)j;
    (void)k;
    (void)point_count;
    (void)min_ped;
    (void)min_point;
    (void)the_point;
    (void)last_point;
    (void)min_distance;
    (void)the_distance;
    (void)s;
    (void)the_pedestrian;
    (void)the_instruction;
    (void)the_choice;
    (void)f;
    (void)the_path;

    if (function_hook_state_WriteOutPeds == HOOK_ENABLED) {
        assert(0 && "WriteOutPeds not implemented.");
        abort();
    } else {
        original_WriteOutPeds();
    }
}

function_hook_state_t function_hook_state_AddPed = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(AddPed, function_hook_state_AddPed)
static void(__cdecl*original_AddPed)() = (void(__cdecl*)())0x0045f644;
CARM95_HOOK_FUNCTION(original_AddPed, AddPed)
void __cdecl AddPed() {
    tPedestrian_instruction *instructions;
    FILE *g;
    tPath_name the_path;
    LOG_TRACE("()");

    (void)instructions;
    (void)g;
    (void)the_path;

    if (function_hook_state_AddPed == HOOK_ENABLED) {
        assert(0 && "AddPed not implemented.");
        abort();
    } else {
        original_AddPed();
    }
}

function_hook_state_t function_hook_state_NewPed = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(NewPed, function_hook_state_NewPed)
static void(__cdecl*original_NewPed)(int) = (void(__cdecl*)(int))0x0045f4f1;
CARM95_HOOK_FUNCTION(original_NewPed, NewPed)
void __cdecl NewPed(int pRef_num) {
    char s[255];
    LOG_TRACE("(%d)", pRef_num);

    (void)pRef_num;
    (void)s;

    if (function_hook_state_NewPed == HOOK_ENABLED) {
        assert(0 && "NewPed not implemented.");
        abort();
    } else {
        original_NewPed(pRef_num);
    }
}

function_hook_state_t function_hook_state_RemoveCurrentPedPath = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(RemoveCurrentPedPath, function_hook_state_RemoveCurrentPedPath)
static void(__cdecl*original_RemoveCurrentPedPath)() = (void(__cdecl*)())0x0045f409;
CARM95_HOOK_FUNCTION(original_RemoveCurrentPedPath, RemoveCurrentPedPath)
void __cdecl RemoveCurrentPedPath() {
    LOG_TRACE("()");


    if (function_hook_state_RemoveCurrentPedPath == HOOK_ENABLED) {
        assert(0 && "RemoveCurrentPedPath not implemented.");
        abort();
    } else {
        original_RemoveCurrentPedPath();
    }
}

function_hook_state_t function_hook_state_ScrubPedestrian = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(ScrubPedestrian, function_hook_state_ScrubPedestrian)
static void(__cdecl*original_ScrubPedestrian)() = (void(__cdecl*)())0x0045f3cb;
CARM95_HOOK_FUNCTION(original_ScrubPedestrian, ScrubPedestrian)
void __cdecl ScrubPedestrian() {
    LOG_TRACE("()");


    if (function_hook_state_ScrubPedestrian == HOOK_ENABLED) {
        assert(0 && "ScrubPedestrian not implemented.");
        abort();
    } else {
        original_ScrubPedestrian();
    }
}

function_hook_state_t function_hook_state_TogglePedDetect = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(TogglePedDetect, function_hook_state_TogglePedDetect)
static void(__cdecl*original_TogglePedDetect)() = (void(__cdecl*)())0x0045f469;
CARM95_HOOK_FUNCTION(original_TogglePedDetect, TogglePedDetect)
void __cdecl TogglePedDetect() {
    LOG_TRACE("()");


    if (function_hook_state_TogglePedDetect == HOOK_ENABLED) {
        assert(0 && "TogglePedDetect not implemented.");
        abort();
    } else {
        original_TogglePedDetect();
    }
}

function_hook_state_t function_hook_state_NewPed0 = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(NewPed0, function_hook_state_NewPed0)
static void(__cdecl*original_NewPed0)() = (void(__cdecl*)())0x0045f4dc;
CARM95_HOOK_FUNCTION(original_NewPed0, NewPed0)
void __cdecl NewPed0() {
    LOG_TRACE("()");


    if (function_hook_state_NewPed0 == HOOK_ENABLED) {
        assert(0 && "NewPed0 not implemented.");
        abort();
    } else {
        original_NewPed0();
    }
}

function_hook_state_t function_hook_state_NewPed1 = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(NewPed1, function_hook_state_NewPed1)
static void(__cdecl*original_NewPed1)() = (void(__cdecl*)())0x0045f72e;
CARM95_HOOK_FUNCTION(original_NewPed1, NewPed1)
void __cdecl NewPed1() {
    LOG_TRACE("()");


    if (function_hook_state_NewPed1 == HOOK_ENABLED) {
        assert(0 && "NewPed1 not implemented.");
        abort();
    } else {
        original_NewPed1();
    }
}

function_hook_state_t function_hook_state_NewPed2 = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(NewPed2, function_hook_state_NewPed2)
static void(__cdecl*original_NewPed2)() = (void(__cdecl*)())0x0045f743;
CARM95_HOOK_FUNCTION(original_NewPed2, NewPed2)
void __cdecl NewPed2() {
    LOG_TRACE("()");


    if (function_hook_state_NewPed2 == HOOK_ENABLED) {
        assert(0 && "NewPed2 not implemented.");
        abort();
    } else {
        original_NewPed2();
    }
}

function_hook_state_t function_hook_state_NewPed3 = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(NewPed3, function_hook_state_NewPed3)
static void(__cdecl*original_NewPed3)() = (void(__cdecl*)())0x0045f758;
CARM95_HOOK_FUNCTION(original_NewPed3, NewPed3)
void __cdecl NewPed3() {
    LOG_TRACE("()");


    if (function_hook_state_NewPed3 == HOOK_ENABLED) {
        assert(0 && "NewPed3 not implemented.");
        abort();
    } else {
        original_NewPed3();
    }
}

function_hook_state_t function_hook_state_NewPed4 = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(NewPed4, function_hook_state_NewPed4)
static void(__cdecl*original_NewPed4)() = (void(__cdecl*)())0x0045f76d;
CARM95_HOOK_FUNCTION(original_NewPed4, NewPed4)
void __cdecl NewPed4() {
    LOG_TRACE("()");


    if (function_hook_state_NewPed4 == HOOK_ENABLED) {
        assert(0 && "NewPed4 not implemented.");
        abort();
    } else {
        original_NewPed4();
    }
}

function_hook_state_t function_hook_state_NewPed5 = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(NewPed5, function_hook_state_NewPed5)
static void(__cdecl*original_NewPed5)() = (void(__cdecl*)())0x0045f782;
CARM95_HOOK_FUNCTION(original_NewPed5, NewPed5)
void __cdecl NewPed5() {
    LOG_TRACE("()");


    if (function_hook_state_NewPed5 == HOOK_ENABLED) {
        assert(0 && "NewPed5 not implemented.");
        abort();
    } else {
        original_NewPed5();
    }
}

function_hook_state_t function_hook_state_NewPed6 = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(NewPed6, function_hook_state_NewPed6)
static void(__cdecl*original_NewPed6)() = (void(__cdecl*)())0x0045f797;
CARM95_HOOK_FUNCTION(original_NewPed6, NewPed6)
void __cdecl NewPed6() {
    LOG_TRACE("()");


    if (function_hook_state_NewPed6 == HOOK_ENABLED) {
        assert(0 && "NewPed6 not implemented.");
        abort();
    } else {
        original_NewPed6();
    }
}

function_hook_state_t function_hook_state_NewPed7 = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(NewPed7, function_hook_state_NewPed7)
static void(__cdecl*original_NewPed7)() = (void(__cdecl*)())0x0045f7ac;
CARM95_HOOK_FUNCTION(original_NewPed7, NewPed7)
void __cdecl NewPed7() {
    LOG_TRACE("()");


    if (function_hook_state_NewPed7 == HOOK_ENABLED) {
        assert(0 && "NewPed7 not implemented.");
        abort();
    } else {
        original_NewPed7();
    }
}

function_hook_state_t function_hook_state_NewPed8 = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(NewPed8, function_hook_state_NewPed8)
static void(__cdecl*original_NewPed8)() = (void(__cdecl*)())0x0045f7c1;
CARM95_HOOK_FUNCTION(original_NewPed8, NewPed8)
void __cdecl NewPed8() {
    LOG_TRACE("()");


    if (function_hook_state_NewPed8 == HOOK_ENABLED) {
        assert(0 && "NewPed8 not implemented.");
        abort();
    } else {
        original_NewPed8();
    }
}

function_hook_state_t function_hook_state_NewPed9 = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(NewPed9, function_hook_state_NewPed9)
static void(__cdecl*original_NewPed9)() = (void(__cdecl*)())0x0045f7d6;
CARM95_HOOK_FUNCTION(original_NewPed9, NewPed9)
void __cdecl NewPed9() {
    LOG_TRACE("()");


    if (function_hook_state_NewPed9 == HOOK_ENABLED) {
        assert(0 && "NewPed9 not implemented.");
        abort();
    } else {
        original_NewPed9();
    }
}

function_hook_state_t function_hook_state_NewPed0B = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(NewPed0B, function_hook_state_NewPed0B)
static void(__cdecl*original_NewPed0B)() = (void(__cdecl*)())0x0045f7eb;
CARM95_HOOK_FUNCTION(original_NewPed0B, NewPed0B)
void __cdecl NewPed0B() {
    LOG_TRACE("()");


    if (function_hook_state_NewPed0B == HOOK_ENABLED) {
        assert(0 && "NewPed0B not implemented.");
        abort();
    } else {
        original_NewPed0B();
    }
}

function_hook_state_t function_hook_state_NewPed1B = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(NewPed1B, function_hook_state_NewPed1B)
static void(__cdecl*original_NewPed1B)() = (void(__cdecl*)())0x0045f800;
CARM95_HOOK_FUNCTION(original_NewPed1B, NewPed1B)
void __cdecl NewPed1B() {
    LOG_TRACE("()");


    if (function_hook_state_NewPed1B == HOOK_ENABLED) {
        assert(0 && "NewPed1B not implemented.");
        abort();
    } else {
        original_NewPed1B();
    }
}

function_hook_state_t function_hook_state_NewPed2B = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(NewPed2B, function_hook_state_NewPed2B)
static void(__cdecl*original_NewPed2B)() = (void(__cdecl*)())0x0045f815;
CARM95_HOOK_FUNCTION(original_NewPed2B, NewPed2B)
void __cdecl NewPed2B() {
    LOG_TRACE("()");


    if (function_hook_state_NewPed2B == HOOK_ENABLED) {
        assert(0 && "NewPed2B not implemented.");
        abort();
    } else {
        original_NewPed2B();
    }
}

function_hook_state_t function_hook_state_NewPed3B = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(NewPed3B, function_hook_state_NewPed3B)
static void(__cdecl*original_NewPed3B)() = (void(__cdecl*)())0x0045f82a;
CARM95_HOOK_FUNCTION(original_NewPed3B, NewPed3B)
void __cdecl NewPed3B() {
    LOG_TRACE("()");


    if (function_hook_state_NewPed3B == HOOK_ENABLED) {
        assert(0 && "NewPed3B not implemented.");
        abort();
    } else {
        original_NewPed3B();
    }
}

function_hook_state_t function_hook_state_NewPed4B = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(NewPed4B, function_hook_state_NewPed4B)
static void(__cdecl*original_NewPed4B)() = (void(__cdecl*)())0x0045f83f;
CARM95_HOOK_FUNCTION(original_NewPed4B, NewPed4B)
void __cdecl NewPed4B() {
    LOG_TRACE("()");


    if (function_hook_state_NewPed4B == HOOK_ENABLED) {
        assert(0 && "NewPed4B not implemented.");
        abort();
    } else {
        original_NewPed4B();
    }
}

function_hook_state_t function_hook_state_NewPed5B = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(NewPed5B, function_hook_state_NewPed5B)
static void(__cdecl*original_NewPed5B)() = (void(__cdecl*)())0x0045f854;
CARM95_HOOK_FUNCTION(original_NewPed5B, NewPed5B)
void __cdecl NewPed5B() {
    LOG_TRACE("()");


    if (function_hook_state_NewPed5B == HOOK_ENABLED) {
        assert(0 && "NewPed5B not implemented.");
        abort();
    } else {
        original_NewPed5B();
    }
}

function_hook_state_t function_hook_state_NewPed6B = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(NewPed6B, function_hook_state_NewPed6B)
static void(__cdecl*original_NewPed6B)() = (void(__cdecl*)())0x0045f869;
CARM95_HOOK_FUNCTION(original_NewPed6B, NewPed6B)
void __cdecl NewPed6B() {
    LOG_TRACE("()");


    if (function_hook_state_NewPed6B == HOOK_ENABLED) {
        assert(0 && "NewPed6B not implemented.");
        abort();
    } else {
        original_NewPed6B();
    }
}

function_hook_state_t function_hook_state_NewPed7B = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(NewPed7B, function_hook_state_NewPed7B)
static void(__cdecl*original_NewPed7B)() = (void(__cdecl*)())0x0045f87e;
CARM95_HOOK_FUNCTION(original_NewPed7B, NewPed7B)
void __cdecl NewPed7B() {
    LOG_TRACE("()");


    if (function_hook_state_NewPed7B == HOOK_ENABLED) {
        assert(0 && "NewPed7B not implemented.");
        abort();
    } else {
        original_NewPed7B();
    }
}

function_hook_state_t function_hook_state_NewPed8B = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(NewPed8B, function_hook_state_NewPed8B)
static void(__cdecl*original_NewPed8B)() = (void(__cdecl*)())0x0045f893;
CARM95_HOOK_FUNCTION(original_NewPed8B, NewPed8B)
void __cdecl NewPed8B() {
    LOG_TRACE("()");


    if (function_hook_state_NewPed8B == HOOK_ENABLED) {
        assert(0 && "NewPed8B not implemented.");
        abort();
    } else {
        original_NewPed8B();
    }
}

function_hook_state_t function_hook_state_NewPed9B = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(NewPed9B, function_hook_state_NewPed9B)
static void(__cdecl*original_NewPed9B)() = (void(__cdecl*)())0x0045f8a8;
CARM95_HOOK_FUNCTION(original_NewPed9B, NewPed9B)
void __cdecl NewPed9B() {
    LOG_TRACE("()");


    if (function_hook_state_NewPed9B == HOOK_ENABLED) {
        assert(0 && "NewPed9B not implemented.");
        abort();
    } else {
        original_NewPed9B();
    }
}

function_hook_state_t function_hook_state_MungeShowPedPath = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(MungeShowPedPath, function_hook_state_MungeShowPedPath)
static void(__cdecl*original_MungeShowPedPath)() = (void(__cdecl*)())0x0045f94b;
CARM95_HOOK_FUNCTION(original_MungeShowPedPath, MungeShowPedPath)
void __cdecl MungeShowPedPath() {
    LOG_TRACE("()");


    if (function_hook_state_MungeShowPedPath == HOOK_ENABLED) {
        assert(0 && "MungeShowPedPath not implemented.");
        abort();
    } else {
        original_MungeShowPedPath();
    }
}

function_hook_state_t function_hook_state_DropPedPoint2 = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(DropPedPoint2, function_hook_state_DropPedPoint2)
static void(__cdecl*original_DropPedPoint2)() = (void(__cdecl*)())0x0045f8e5;
CARM95_HOOK_FUNCTION(original_DropPedPoint2, DropPedPoint2)
void __cdecl DropPedPoint2() {
    LOG_TRACE("()");


    if (function_hook_state_DropPedPoint2 == HOOK_ENABLED) {
        assert(0 && "DropPedPoint2 not implemented.");
        abort();
    } else {
        original_DropPedPoint2();
    }
}

function_hook_state_t function_hook_state_DropPedPoint = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(DropPedPoint, function_hook_state_DropPedPoint)
static void(__cdecl*original_DropPedPoint)() = (void(__cdecl*)())0x0045f8bd;
CARM95_HOOK_FUNCTION(original_DropPedPoint, DropPedPoint)
void __cdecl DropPedPoint() {
    LOG_TRACE("()");


    if (function_hook_state_DropPedPoint == HOOK_ENABLED) {
        assert(0 && "DropPedPoint not implemented.");
        abort();
    } else {
        original_DropPedPoint();
    }
}

function_hook_state_t function_hook_state_DropInitPedPoint = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(DropInitPedPoint, function_hook_state_DropInitPedPoint)
static void(__cdecl*original_DropInitPedPoint)() = (void(__cdecl*)())0x0045f9a4;
CARM95_HOOK_FUNCTION(original_DropInitPedPoint, DropInitPedPoint)
void __cdecl DropInitPedPoint() {
    LOG_TRACE("()");


    if (function_hook_state_DropInitPedPoint == HOOK_ENABLED) {
        assert(0 && "DropInitPedPoint not implemented.");
        abort();
    } else {
        original_DropInitPedPoint();
    }
}

function_hook_state_t function_hook_state_DropPedPointAir2 = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(DropPedPointAir2, function_hook_state_DropPedPointAir2)
static void(__cdecl*original_DropPedPointAir2)() = (void(__cdecl*)())0x0045f9fe;
CARM95_HOOK_FUNCTION(original_DropPedPointAir2, DropPedPointAir2)
void __cdecl DropPedPointAir2() {
    LOG_TRACE("()");


    if (function_hook_state_DropPedPointAir2 == HOOK_ENABLED) {
        assert(0 && "DropPedPointAir2 not implemented.");
        abort();
    } else {
        original_DropPedPointAir2();
    }
}

function_hook_state_t function_hook_state_DropPedPointAir = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(DropPedPointAir, function_hook_state_DropPedPointAir)
static void(__cdecl*original_DropPedPointAir)() = (void(__cdecl*)())0x0045f9d6;
CARM95_HOOK_FUNCTION(original_DropPedPointAir, DropPedPointAir)
void __cdecl DropPedPointAir() {
    LOG_TRACE("()");


    if (function_hook_state_DropPedPointAir == HOOK_ENABLED) {
        assert(0 && "DropPedPointAir not implemented.");
        abort();
    } else {
        original_DropPedPointAir();
    }
}

function_hook_state_t function_hook_state_DropInitPedPointAir = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(DropInitPedPointAir, function_hook_state_DropInitPedPointAir)
static void(__cdecl*original_DropInitPedPointAir)() = (void(__cdecl*)())0x0045fa88;
CARM95_HOOK_FUNCTION(original_DropInitPedPointAir, DropInitPedPointAir)
void __cdecl DropInitPedPointAir() {
    LOG_TRACE("()");


    if (function_hook_state_DropInitPedPointAir == HOOK_ENABLED) {
        assert(0 && "DropInitPedPointAir not implemented.");
        abort();
    } else {
        original_DropInitPedPointAir();
    }
}

function_hook_state_t function_hook_state_KillActorsModel = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(KillActorsModel, function_hook_state_KillActorsModel)
static br_uint_32(__cdecl*original_KillActorsModel)(br_actor *, void *) = (br_uint_32(__cdecl*)(br_actor *, void *))0x0045ff83;
CARM95_HOOK_FUNCTION(original_KillActorsModel, KillActorsModel)
br_uint_32 __cdecl KillActorsModel(br_actor *pActor, void *pArg) {
    LOG_TRACE("(%p, %p)", pActor, pArg);

    (void)pActor;
    (void)pArg;

    if (function_hook_state_KillActorsModel == HOOK_ENABLED) {
        assert(0 && "KillActorsModel not implemented.");
        abort();
    } else {
        return original_KillActorsModel(pActor, pArg);
    }
}

function_hook_state_t function_hook_state_DisposePedPaths = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(DisposePedPaths, function_hook_state_DisposePedPaths)
static void(__cdecl*original_DisposePedPaths)() = (void(__cdecl*)())0x0045fef8;
CARM95_HOOK_FUNCTION(original_DisposePedPaths, DisposePedPaths)
void __cdecl DisposePedPaths() {
    LOG_TRACE("()");


    if (function_hook_state_DisposePedPaths == HOOK_ENABLED) {
        assert(0 && "DisposePedPaths not implemented.");
        abort();
    } else {
        original_DisposePedPaths();
    }
}

function_hook_state_t function_hook_state_GetPedPos = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(GetPedPos, function_hook_state_GetPedPos)
static void(__cdecl*original_GetPedPos)(int *, int *) = (void(__cdecl*)(int *, int *))0x0045faba;
CARM95_HOOK_FUNCTION(original_GetPedPos, GetPedPos)
void __cdecl GetPedPos(int *pPed_index, int *pPoint_index) {
    int i;
    int j;
    int point_count;
    br_vector3 the_point;
    br_vector3 last_point;
    br_scalar min_distance;
    br_scalar the_distance;
    LOG_TRACE("(%p, %p)", pPed_index, pPoint_index);

    (void)pPed_index;
    (void)pPoint_index;
    (void)i;
    (void)j;
    (void)point_count;
    (void)the_point;
    (void)last_point;
    (void)min_distance;
    (void)the_distance;

    if (function_hook_state_GetPedPos == HOOK_ENABLED) {
        assert(0 && "GetPedPos not implemented.");
        abort();
    } else {
        original_GetPedPos(pPed_index, pPoint_index);
    }
}

function_hook_state_t function_hook_state_ShowPedPos = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(ShowPedPos, function_hook_state_ShowPedPos)
static void(__cdecl*original_ShowPedPos)() = (void(__cdecl*)())0x0045fc96;
CARM95_HOOK_FUNCTION(original_ShowPedPos, ShowPedPos)
void __cdecl ShowPedPos() {
    int min_ped;
    int min_point;
    char s[255];
    LOG_TRACE("()");

    (void)min_ped;
    (void)min_point;
    (void)s;

    if (function_hook_state_ShowPedPos == HOOK_ENABLED) {
        assert(0 && "ShowPedPos not implemented.");
        abort();
    } else {
        original_ShowPedPos();
    }
}

function_hook_state_t function_hook_state_ShowPedPaths = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(ShowPedPaths, function_hook_state_ShowPedPaths)
static void(__cdecl*original_ShowPedPaths)() = (void(__cdecl*)())0x0045fcf5;
CARM95_HOOK_FUNCTION(original_ShowPedPaths, ShowPedPaths)
void __cdecl ShowPedPaths() {
    int i;
    br_model *the_model;
    LOG_TRACE("()");

    (void)i;
    (void)the_model;

    if (function_hook_state_ShowPedPaths == HOOK_ENABLED) {
        assert(0 && "ShowPedPaths not implemented.");
        abort();
    } else {
        original_ShowPedPaths();
    }
}

function_hook_state_t function_hook_state_PullPedPoint = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(PullPedPoint, function_hook_state_PullPedPoint)
static void(__cdecl*original_PullPedPoint)() = (void(__cdecl*)())0x0045fe84;
CARM95_HOOK_FUNCTION(original_PullPedPoint, PullPedPoint)
void __cdecl PullPedPoint() {
    int the_ped;
    int the_point;
    LOG_TRACE("()");

    (void)the_ped;
    (void)the_point;

    if (function_hook_state_PullPedPoint == HOOK_ENABLED) {
        assert(0 && "PullPedPoint not implemented.");
        abort();
    } else {
        original_PullPedPoint();
    }
}

function_hook_state_t function_hook_state_PullPedPointAir = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(PullPedPointAir, function_hook_state_PullPedPointAir)
static void(__cdecl*original_PullPedPointAir)() = (void(__cdecl*)())0x0045ffc0;
CARM95_HOOK_FUNCTION(original_PullPedPointAir, PullPedPointAir)
void __cdecl PullPedPointAir() {
    int the_ped;
    int the_point;
    LOG_TRACE("()");

    (void)the_ped;
    (void)the_point;

    if (function_hook_state_PullPedPointAir == HOOK_ENABLED) {
        assert(0 && "PullPedPointAir not implemented.");
        abort();
    } else {
        original_PullPedPointAir();
    }
}

function_hook_state_t function_hook_state_DeletePedPath = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(DeletePedPath, function_hook_state_DeletePedPath)
static void(__cdecl*original_DeletePedPath)() = (void(__cdecl*)())0x00460082;
CARM95_HOOK_FUNCTION(original_DeletePedPath, DeletePedPath)
void __cdecl DeletePedPath() {
    int the_ped;
    int the_point;
    int i;
    LOG_TRACE("()");

    (void)the_ped;
    (void)the_point;
    (void)i;

    if (function_hook_state_DeletePedPath == HOOK_ENABLED) {
        assert(0 && "DeletePedPath not implemented.");
        abort();
    } else {
        original_DeletePedPath();
    }
}

function_hook_state_t function_hook_state_DeletePedPoint = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(DeletePedPoint, function_hook_state_DeletePedPoint)
static void(__cdecl*original_DeletePedPoint)() = (void(__cdecl*)())0x0046010f;
CARM95_HOOK_FUNCTION(original_DeletePedPoint, DeletePedPoint)
void __cdecl DeletePedPoint() {
    LOG_TRACE("()");


    if (function_hook_state_DeletePedPoint == HOOK_ENABLED) {
        assert(0 && "DeletePedPoint not implemented.");
        abort();
    } else {
        original_DeletePedPoint();
    }
}

function_hook_state_t function_hook_state_DisposePedestrians = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(DisposePedestrians, function_hook_state_DisposePedestrians)
static void(__cdecl*original_DisposePedestrians)() = (void(__cdecl*)())0x00460169;
CARM95_HOOK_FUNCTION(original_DisposePedestrians, DisposePedestrians)
void __cdecl DisposePedestrians() {
    int i;
    int j;
    tPedestrian_data *the_pedestrian;
    LOG_TRACE("()");

    (void)i;
    (void)j;
    (void)the_pedestrian;

    if (function_hook_state_DisposePedestrians == HOOK_ENABLED) {
        assert(0 && "DisposePedestrians not implemented.");
        abort();
    } else {
        original_DisposePedestrians();
    }
}

function_hook_state_t function_hook_state_DoPedReport = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(DoPedReport, function_hook_state_DoPedReport)
static void(__cdecl*original_DoPedReport)() = (void(__cdecl*)())0x004603d6;
CARM95_HOOK_FUNCTION(original_DoPedReport, DoPedReport)
void __cdecl DoPedReport() {
    FILE *f;
    tPath_name the_path;
    time_t the_bloody_time;
    int i;
    int j;
    int count;
    int last_ref_num;
    LOG_TRACE("()");

    (void)f;
    (void)the_path;
    (void)the_bloody_time;
    (void)i;
    (void)j;
    (void)count;
    (void)last_ref_num;

    if (function_hook_state_DoPedReport == HOOK_ENABLED) {
        assert(0 && "DoPedReport not implemented.");
        abort();
    } else {
        original_DoPedReport();
    }
}

function_hook_state_t function_hook_state_RenderProximityRays = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(RenderProximityRays, function_hook_state_RenderProximityRays)
static void(__cdecl*original_RenderProximityRays)(br_pixelmap *, br_pixelmap *, br_actor *, br_matrix34 *, tU32) = (void(__cdecl*)(br_pixelmap *, br_pixelmap *, br_actor *, br_matrix34 *, tU32))0x00460696;
CARM95_HOOK_FUNCTION(original_RenderProximityRays, RenderProximityRays)
void __cdecl RenderProximityRays(br_pixelmap *pRender_screen, br_pixelmap *pDepth_buffer, br_actor *pCamera, br_matrix34 *pCamera_to_world, tU32 pTime) {
    int i;
    float seed;
    tU32 the_time;
    br_vector3 car_pos;
    br_vector3 ped_pos;
    br_vector3 car_pos_cam;
    br_vector3 ped_pos_cam;
    br_vector3 car_add;
    br_vector3 car_add_c;
    br_vector3 ped_add;
    br_vector3 ray;
    br_vector3 r1;
    br_vector3 from_pos;
    br_vector3 to_pos;
    br_model *car_model;
    br_scalar distance;
    br_scalar t;
    br_scalar __block0___scale;
    LOG_TRACE("(%p, %p, %p, %p, %u)", pRender_screen, pDepth_buffer, pCamera, pCamera_to_world, pTime);

    (void)pRender_screen;
    (void)pDepth_buffer;
    (void)pCamera;
    (void)pCamera_to_world;
    (void)pTime;
    (void)i;
    (void)seed;
    (void)the_time;
    (void)car_pos;
    (void)ped_pos;
    (void)car_pos_cam;
    (void)ped_pos_cam;
    (void)car_add;
    (void)car_add_c;
    (void)ped_add;
    (void)ray;
    (void)r1;
    (void)from_pos;
    (void)to_pos;
    (void)car_model;
    (void)distance;
    (void)t;
    (void)__block0___scale;

    if (function_hook_state_RenderProximityRays == HOOK_ENABLED) {
        assert(0 && "RenderProximityRays not implemented.");
        abort();
    } else {
        original_RenderProximityRays(pRender_screen, pDepth_buffer, pCamera, pCamera_to_world, pTime);
    }
}

function_hook_state_t function_hook_state_AdjustProxRay = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(AdjustProxRay, function_hook_state_AdjustProxRay)
static void(__cdecl*original_AdjustProxRay)(int, tU16, tU16, tU32) = (void(__cdecl*)(int, tU16, tU16, tU32))0x00460ac5;
CARM95_HOOK_FUNCTION(original_AdjustProxRay, AdjustProxRay)
void __cdecl AdjustProxRay(int pRay_index, tU16 pCar_ID, tU16 pPed_index, tU32 pTime) {
    LOG_TRACE("(%d, %u, %u, %u)", pRay_index, pCar_ID, pPed_index, pTime);

    (void)pRay_index;
    (void)pCar_ID;
    (void)pPed_index;
    (void)pTime;

    if (function_hook_state_AdjustProxRay == HOOK_ENABLED) {
        assert(0 && "AdjustProxRay not implemented.");
        abort();
    } else {
        original_AdjustProxRay(pRay_index, pCar_ID, pPed_index, pTime);
    }
}

function_hook_state_t function_hook_state_ReceivedPedestrian = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(ReceivedPedestrian, function_hook_state_ReceivedPedestrian)
static void(__cdecl*original_ReceivedPedestrian)(tNet_contents *, tNet_message *, tU32) = (void(__cdecl*)(tNet_contents *, tNet_message *, tU32))0x00460b66;
CARM95_HOOK_FUNCTION(original_ReceivedPedestrian, ReceivedPedestrian)
void __cdecl ReceivedPedestrian(tNet_contents *pContents, tNet_message *pMessage, tU32 pReceive_time) {
    tPedestrian_data *the_pedestrian;
    tNet_game_player_info *sender;
    tNet_game_player_info *murderer;
    int modified_action;
    int modified_action_2;
    int action;
    int instruction;
    int dead;
    tPedestrian_sequence *the_sequence;
    LOG_TRACE("(%p, %p, %u)", pContents, pMessage, pReceive_time);

    (void)pContents;
    (void)pMessage;
    (void)pReceive_time;
    (void)the_pedestrian;
    (void)sender;
    (void)murderer;
    (void)modified_action;
    (void)modified_action_2;
    (void)action;
    (void)instruction;
    (void)dead;
    (void)the_sequence;

    if (function_hook_state_ReceivedPedestrian == HOOK_ENABLED) {
        assert(0 && "ReceivedPedestrian not implemented.");
        abort();
    } else {
        original_ReceivedPedestrian(pContents, pMessage, pReceive_time);
    }
}

function_hook_state_t function_hook_state_SendAllPedestrianPositions = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(SendAllPedestrianPositions, function_hook_state_SendAllPedestrianPositions)
static void(__cdecl*original_SendAllPedestrianPositions)(tPlayer_ID) = (void(__cdecl*)(tPlayer_ID))0x0046109c;
CARM95_HOOK_FUNCTION(original_SendAllPedestrianPositions, SendAllPedestrianPositions)
void __cdecl SendAllPedestrianPositions(tPlayer_ID pPlayer) {
    int i;
    tPedestrian_data *the_pedestrian;
    tNet_contents *the_contents;
    LOG_TRACE("(%u)", pPlayer);

    (void)pPlayer;
    (void)i;
    (void)the_pedestrian;
    (void)the_contents;

    if (function_hook_state_SendAllPedestrianPositions == HOOK_ENABLED) {
        assert(0 && "SendAllPedestrianPositions not implemented.");
        abort();
    } else {
        original_SendAllPedestrianPositions(pPlayer);
    }
}

