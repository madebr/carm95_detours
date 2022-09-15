#include "pedestrn.h"

#include "harness/trace.h"

#include "carm95_hooks.h"

#include <stdio.h>
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

static void(*original_PedModelUpdate)(br_model *, br_scalar, br_scalar, br_scalar, br_scalar, br_scalar, br_scalar, br_scalar, br_scalar, ...) = (void(*)(br_model *, br_scalar, br_scalar, br_scalar, br_scalar, br_scalar, br_scalar, br_scalar, br_scalar, ...))0x00455fcd;
CARM95_HOOK_FUNCTION(original_PedModelUpdate, PedModelUpdate)
void PedModelUpdate(br_model *pModel, br_scalar x0, br_scalar y0, br_scalar x1, br_scalar y1, br_scalar x2, br_scalar y2, br_scalar x3, br_scalar y3) {
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

    original_PedModelUpdate(pModel, x0, y0, x1, y1, x2, y2, x3, y3);
}

static int(*original_ActorIsPedestrian)(br_actor *, ...) = (int(*)(br_actor *, ...))0x00455870;
CARM95_HOOK_FUNCTION(original_ActorIsPedestrian, ActorIsPedestrian)
int ActorIsPedestrian(br_actor *pActor) {
    LOG_TRACE("(%p)", pActor);

    (void)pActor;

    return original_ActorIsPedestrian(pActor);
}

static br_scalar(*original_PedHeightFromActor)(br_actor *, ...) = (br_scalar(*)(br_actor *, ...))0x004558b8;
CARM95_HOOK_FUNCTION(original_PedHeightFromActor, PedHeightFromActor)
br_scalar PedHeightFromActor(br_actor *pActor) {
    LOG_TRACE("(%p)", pActor);

    (void)pActor;

    return original_PedHeightFromActor(pActor);
}

static int(*original_GetPedestrianValue)(br_actor *, ...) = (int(*)(br_actor *, ...))0x004558fa;
CARM95_HOOK_FUNCTION(original_GetPedestrianValue, GetPedestrianValue)
int GetPedestrianValue(br_actor *pActor) {
    LOG_TRACE("(%p)", pActor);

    (void)pActor;

    return original_GetPedestrianValue(pActor);
}

static int(*original_PedestrianActorIsPerson)(br_actor *, ...) = (int(*)(br_actor *, ...))0x00455913;
CARM95_HOOK_FUNCTION(original_PedestrianActorIsPerson, PedestrianActorIsPerson)
int PedestrianActorIsPerson(br_actor *pActor) {
    LOG_TRACE("(%p)", pActor);

    (void)pActor;

    return original_PedestrianActorIsPerson(pActor);
}

static br_actor *(*original_GetPedestrianActor)(int, ...) = (br_actor *(*)(int, ...))0x00455953;
CARM95_HOOK_FUNCTION(original_GetPedestrianActor, GetPedestrianActor)
br_actor* GetPedestrianActor(int pIndex) {
    LOG_TRACE("(%d)", pIndex);

    (void)pIndex;

    return original_GetPedestrianActor(pIndex);
}

static br_pixelmap *(*original_GetPedestrianTexture)(br_actor *, int *, ...) = (br_pixelmap *(*)(br_actor *, int *, ...))0x0045599e;
CARM95_HOOK_FUNCTION(original_GetPedestrianTexture, GetPedestrianTexture)
br_pixelmap* GetPedestrianTexture(br_actor *pActor, int *pFlipped) {
    LOG_TRACE("(%p, %p)", pActor, pFlipped);

    (void)pActor;
    (void)pFlipped;

    return original_GetPedestrianTexture(pActor, pFlipped);
}

static void(*original_TogglePedestrians)() = (void(*)())0x004559ea;
CARM95_HOOK_FUNCTION(original_TogglePedestrians, TogglePedestrians)
void TogglePedestrians() {
    LOG_TRACE("()");


    original_TogglePedestrians();
}

static void(*original_InitPedGibs)() = (void(*)())0x0045e3ad;
CARM95_HOOK_FUNCTION(original_InitPedGibs, InitPedGibs)
void InitPedGibs() {
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

    original_InitPedGibs();
}

static void(*original_SetPedMaterialForRender)(br_actor *, ...) = (void(*)(br_actor *, ...))0x00455a76;
CARM95_HOOK_FUNCTION(original_SetPedMaterialForRender, SetPedMaterialForRender)
void SetPedMaterialForRender(br_actor *pActor) {
    tPedestrian_data *ped;
    int changed;
    LOG_TRACE("(%p)", pActor);

    (void)pActor;
    (void)ped;
    (void)changed;

    original_SetPedMaterialForRender(pActor);
}

static void(*original_PedCallBack)(br_actor *, struct br_model *, struct br_material *, void *, br_uint_8, int, ...) = (void(*)(br_actor *, struct br_model *, struct br_material *, void *, br_uint_8, int, ...))0x00455b6f;
CARM95_HOOK_FUNCTION(original_PedCallBack, PedCallBack)
void PedCallBack(br_actor *pActor, struct br_model *pModel, struct br_material *pMaterial, void *pRender_data, br_uint_8 pStyle, int pOn_screen) {
    tPedestrian_data *ped;
    LOG_TRACE("(%p, %p, %p, %p, %u, %d)", pActor, pModel, pMaterial, pRender_data, pStyle, pOn_screen);

    (void)pActor;
    (void)pModel;
    (void)pMaterial;
    (void)pRender_data;
    (void)pStyle;
    (void)pOn_screen;
    (void)ped;

    original_PedCallBack(pActor, pModel, pMaterial, pRender_data, pStyle, pOn_screen);
}

static void(*original_InitPeds)() = (void(*)())0x00455c05;
CARM95_HOOK_FUNCTION(original_InitPeds, InitPeds)
void InitPeds() {
    LOG_TRACE("()");


    original_InitPeds();
}

static void(*original_MungeModelSize)(br_actor *, br_scalar, ...) = (void(*)(br_actor *, br_scalar, ...))0x00455f31;
CARM95_HOOK_FUNCTION(original_MungeModelSize, MungeModelSize)
void MungeModelSize(br_actor *pActor, br_scalar pScaling_factor) {
    br_pixelmap *the_pix;
    br_scalar half_width;
    br_scalar half_height;
    LOG_TRACE("(%p, %f)", pActor, pScaling_factor);

    (void)pActor;
    (void)pScaling_factor;
    (void)the_pix;
    (void)half_width;
    (void)half_height;

    original_MungeModelSize(pActor, pScaling_factor);
}

static int(*original_BurstPedestrian)(tPedestrian_data *, float, int, ...) = (int(*)(tPedestrian_data *, float, int, ...))0x00457ff5;
CARM95_HOOK_FUNCTION(original_BurstPedestrian, BurstPedestrian)
int BurstPedestrian(tPedestrian_data *pPedestrian, float pSplattitudinalitude, int pAllow_explosion) {
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

    return original_BurstPedestrian(pPedestrian, pSplattitudinalitude, pAllow_explosion);
}

static void(*original_ResetAllPedGibs)() = (void(*)())0x00455df2;
CARM95_HOOK_FUNCTION(original_ResetAllPedGibs, ResetAllPedGibs)
void ResetAllPedGibs() {
    int i;
    tPed_gib *the_ped_gib;
    LOG_TRACE("()");

    (void)i;
    (void)the_ped_gib;

    original_ResetAllPedGibs();
}

static void(*original_AdjustPedGib)(int, int, int, int, br_matrix34 *, ...) = (void(*)(int, int, int, int, br_matrix34 *, ...))0x00455e72;
CARM95_HOOK_FUNCTION(original_AdjustPedGib, AdjustPedGib)
void AdjustPedGib(int pIndex, int pSize, int pGib_index, int pPed_index, br_matrix34 *pTrans) {
    tPed_gib *the_ped_gib;
    LOG_TRACE("(%d, %d, %d, %d, %p)", pIndex, pSize, pGib_index, pPed_index, pTrans);

    (void)pIndex;
    (void)pSize;
    (void)pGib_index;
    (void)pPed_index;
    (void)pTrans;
    (void)the_ped_gib;

    original_AdjustPedGib(pIndex, pSize, pGib_index, pPed_index, pTrans);
}

static void(*original_MungePedGibs)(tU32, ...) = (void(*)(tU32, ...))0x00456048;
CARM95_HOOK_FUNCTION(original_MungePedGibs, MungePedGibs)
void MungePedGibs(tU32 pFrame_period) {
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

    original_MungePedGibs(pFrame_period);
}

static void(*original_KillPedestrian)(tPedestrian_data *, ...) = (void(*)(tPedestrian_data *, ...))0x00456e92;
CARM95_HOOK_FUNCTION(original_KillPedestrian, KillPedestrian)
void KillPedestrian(tPedestrian_data *pPedestrian) {
    LOG_TRACE("(%p)", pPedestrian);

    (void)pPedestrian;

    original_KillPedestrian(pPedestrian);
}

static void(*original_CalcPedWidthNHeight)(tPedestrian_data *, br_pixelmap *, br_scalar *, br_scalar *, ...) = (void(*)(tPedestrian_data *, br_pixelmap *, br_scalar *, br_scalar *, ...))0x00457492;
CARM95_HOOK_FUNCTION(original_CalcPedWidthNHeight, CalcPedWidthNHeight)
void CalcPedWidthNHeight(tPedestrian_data *pPedestrian, br_pixelmap *pPixelmap, br_scalar *pHeight, br_scalar *pWidth) {
    br_pixelmap *reference_pixel_bastard;
    br_scalar scale_to_use;
    LOG_TRACE("(%p, %p, %p, %p)", pPedestrian, pPixelmap, pHeight, pWidth);

    (void)pPedestrian;
    (void)pPixelmap;
    (void)pHeight;
    (void)pWidth;
    (void)reference_pixel_bastard;
    (void)scale_to_use;

    original_CalcPedWidthNHeight(pPedestrian, pPixelmap, pHeight, pWidth);
}

static int(*original_PedestrianNextInstruction)(tPedestrian_data *, float, int, int, ...) = (int(*)(tPedestrian_data *, float, int, int, ...))0x004585f1;
CARM95_HOOK_FUNCTION(original_PedestrianNextInstruction, PedestrianNextInstruction)
int PedestrianNextInstruction(tPedestrian_data *pPedestrian, float pDanger_level, int pPosition_explicitly, int pMove_pc) {
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

    return original_PedestrianNextInstruction(pPedestrian, pDanger_level, pPosition_explicitly, pMove_pc);
}

static void(*original_MungePedestrianSequence)(tPedestrian_data *, int, ...) = (void(*)(tPedestrian_data *, int, ...))0x004566ee;
CARM95_HOOK_FUNCTION(original_MungePedestrianSequence, MungePedestrianSequence)
void MungePedestrianSequence(tPedestrian_data *pPedestrian, int pAction_changed) {
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

    original_MungePedestrianSequence(pPedestrian, pAction_changed);
}

static void(*original_DetachPedFromCar)(tPedestrian_data *, ...) = (void(*)(tPedestrian_data *, ...))0x004563dc;
CARM95_HOOK_FUNCTION(original_DetachPedFromCar, DetachPedFromCar)
void DetachPedFromCar(tPedestrian_data *pPedestrian) {
    LOG_TRACE("(%p)", pPedestrian);

    (void)pPedestrian;

    original_DetachPedFromCar(pPedestrian);
}

static void(*original_SetPedPos)(tPedestrian_data *, ...) = (void(*)(tPedestrian_data *, ...))0x0045647b;
CARM95_HOOK_FUNCTION(original_SetPedPos, SetPedPos)
void SetPedPos(tPedestrian_data *pPedestrian) {
    br_vector3 temp_v;
    LOG_TRACE("(%p)", pPedestrian);

    (void)pPedestrian;
    (void)temp_v;

    original_SetPedPos(pPedestrian);
}

static void(*original_DetachPedActorFromCar)(br_actor *, ...) = (void(*)(br_actor *, ...))0x004563b3;
CARM95_HOOK_FUNCTION(original_DetachPedActorFromCar, DetachPedActorFromCar)
void DetachPedActorFromCar(br_actor *pActor) {
    LOG_TRACE("(%p)", pActor);

    (void)pActor;

    original_DetachPedActorFromCar(pActor);
}

static void(*original_MungePedestrianFrames)(tPedestrian_data *, ...) = (void(*)(tPedestrian_data *, ...))0x004568d7;
CARM95_HOOK_FUNCTION(original_MungePedestrianFrames, MungePedestrianFrames)
void MungePedestrianFrames(tPedestrian_data *pPedestrian) {
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

    original_MungePedestrianFrames(pPedestrian);
}

static void(*original_MungePedModel)(tPedestrian_data *, ...) = (void(*)(tPedestrian_data *, ...))0x00456f86;
CARM95_HOOK_FUNCTION(original_MungePedModel, MungePedModel)
void MungePedModel(tPedestrian_data *pPedestrian) {
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

    original_MungePedModel(pPedestrian);
}

static void(*original_ChangeActionTo)(tPedestrian_data *, int, int, ...) = (void(*)(tPedestrian_data *, int, int, ...))0x0045654d;
CARM95_HOOK_FUNCTION(original_ChangeActionTo, ChangeActionTo)
void ChangeActionTo(tPedestrian_data *pPedestrian, int pAction_index, int pRedo_frames_etc) {
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

    original_ChangeActionTo(pPedestrian, pAction_index, pRedo_frames_etc);
}

static int(*original_MungePedestrianAction)(tPedestrian_data *, float, ...) = (int(*)(tPedestrian_data *, float, ...))0x00459db7;
CARM95_HOOK_FUNCTION(original_MungePedestrianAction, MungePedestrianAction)
int MungePedestrianAction(tPedestrian_data *pPedestrian, float pDanger_level) {
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

    return original_MungePedestrianAction(pPedestrian, pDanger_level);
}

static void(*original_MakeFlagWavingBastardWaveHisFlagWhichIsTheProbablyTheLastThingHeWillEverDo)() = (void(*)())0x004564ed;
CARM95_HOOK_FUNCTION(original_MakeFlagWavingBastardWaveHisFlagWhichIsTheProbablyTheLastThingHeWillEverDo, MakeFlagWavingBastardWaveHisFlagWhichIsTheProbablyTheLastThingHeWillEverDo)
void MakeFlagWavingBastardWaveHisFlagWhichIsTheProbablyTheLastThingHeWillEverDo() {
    LOG_TRACE("()");


    original_MakeFlagWavingBastardWaveHisFlagWhichIsTheProbablyTheLastThingHeWillEverDo();
}

static void(*original_MungePedestrianPath)(tPedestrian_data *, float, br_vector3 *, ...) = (void(*)(tPedestrian_data *, float, br_vector3 *, ...))0x00457548;
CARM95_HOOK_FUNCTION(original_MungePedestrianPath, MungePedestrianPath)
void MungePedestrianPath(tPedestrian_data *pPedestrian, float pDanger_level, br_vector3 *pDanger_direction) {
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

    original_MungePedestrianPath(pPedestrian, pDanger_level, pDanger_direction);
}

static float(*original_CalcPedestrianDangerLevel)(tPedestrian_data *, br_vector3 *, ...) = (float(*)(tPedestrian_data *, br_vector3 *, ...))0x0045a078;
CARM95_HOOK_FUNCTION(original_CalcPedestrianDangerLevel, CalcPedestrianDangerLevel)
float CalcPedestrianDangerLevel(tPedestrian_data *pPedestrian, br_vector3 *pDanger_direction) {
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

    return original_CalcPedestrianDangerLevel(pPedestrian, pDanger_direction);
}

static tPed_hit_position(*original_MoveToEdgeOfCar)(tPedestrian_data *, tCollision_info *, br_actor *, br_scalar, br_scalar, br_scalar, br_scalar, br_scalar, br_scalar, br_vector3 *, br_vector3 *, ...) = (tPed_hit_position(*)(tPedestrian_data *, tCollision_info *, br_actor *, br_scalar, br_scalar, br_scalar, br_scalar, br_scalar, br_scalar, br_vector3 *, br_vector3 *, ...))0x0045bcc5;
CARM95_HOOK_FUNCTION(original_MoveToEdgeOfCar, MoveToEdgeOfCar)
tPed_hit_position MoveToEdgeOfCar(tPedestrian_data *pPedestrian, tCollision_info *pCar, br_actor *pCar_actor, br_scalar pPed_x, br_scalar pPed_z, br_scalar pCar_bounds_min_x, br_scalar pCar_bounds_max_x, br_scalar pCar_bounds_min_z, br_scalar pCar_bounds_max_z, br_vector3 *pMin_ped_bounds_car, br_vector3 *pMax_ped_bounds_car) {
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

    return original_MoveToEdgeOfCar(pPedestrian, pCar, pCar_actor, pPed_x, pPed_z, pCar_bounds_min_x, pCar_bounds_max_x, pCar_bounds_min_z, pCar_bounds_max_z, pMin_ped_bounds_car, pMax_ped_bounds_car);
}

static void(*original_CheckLastPed)() = (void(*)())0x0045c0db;
CARM95_HOOK_FUNCTION(original_CheckLastPed, CheckLastPed)
void CheckLastPed() {
    LOG_TRACE("()");


    original_CheckLastPed();
}

static int(*original_BloodyWheels)(tCar_spec *, br_vector3 *, br_scalar, br_vector3 *, ...) = (int(*)(tCar_spec *, br_vector3 *, br_scalar, br_vector3 *, ...))0x0045c12c;
CARM95_HOOK_FUNCTION(original_BloodyWheels, BloodyWheels)
int BloodyWheels(tCar_spec *pCar, br_vector3 *pPed_car, br_scalar pSize, br_vector3 *pPed_glob) {
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

    return original_BloodyWheels(pCar, pPed_car, pSize, pPed_glob);
}

static int(*original_FancyATossOffMate)(tPedestrian_data *, tCollision_info *, float, ...) = (int(*)(tPedestrian_data *, tCollision_info *, float, ...))0x0045c273;
CARM95_HOOK_FUNCTION(original_FancyATossOffMate, FancyATossOffMate)
int FancyATossOffMate(tPedestrian_data *pPedestrian, tCollision_info *pCar, float pImpact_speed) {
    LOG_TRACE("(%p, %p, %f)", pPedestrian, pCar, pImpact_speed);

    (void)pPedestrian;
    (void)pCar;
    (void)pImpact_speed;

    return original_FancyATossOffMate(pPedestrian, pCar, pImpact_speed);
}

static void(*original_CheckPedestrianDeathScenario)(tPedestrian_data *, ...) = (void(*)(tPedestrian_data *, ...))0x0045a3bd;
CARM95_HOOK_FUNCTION(original_CheckPedestrianDeathScenario, CheckPedestrianDeathScenario)
void CheckPedestrianDeathScenario(tPedestrian_data *pPedestrian) {
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

    original_CheckPedestrianDeathScenario(pPedestrian);
}

static void(*original_SendPedestrian)(tPedestrian_data *, int, ...) = (void(*)(tPedestrian_data *, int, ...))0x0045c2f0;
CARM95_HOOK_FUNCTION(original_SendPedestrian, SendPedestrian)
void SendPedestrian(tPedestrian_data *pPedestrian, int pIndex) {
    tNet_contents *the_contents;
    tNet_message *the_message;
    int size_decider;
    LOG_TRACE("(%p, %d)", pPedestrian, pIndex);

    (void)pPedestrian;
    (void)pIndex;
    (void)the_contents;
    (void)the_message;
    (void)size_decider;

    original_SendPedestrian(pPedestrian, pIndex);
}

static void(*original_DoPedestrian)(tPedestrian_data *, int, ...) = (void(*)(tPedestrian_data *, int, ...))0x004598e2;
CARM95_HOOK_FUNCTION(original_DoPedestrian, DoPedestrian)
void DoPedestrian(tPedestrian_data *pPedestrian, int pIndex) {
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

    original_DoPedestrian(pPedestrian, pIndex);
}

static void(*original_AdjustPedestrian)(int, int, int, int, int, tU16, br_actor *, float, br_scalar, br_vector3 *, br_vector3 *, ...) = (void(*)(int, int, int, int, int, tU16, br_actor *, float, br_scalar, br_vector3 *, br_vector3 *, ...))0x00458ec7;
CARM95_HOOK_FUNCTION(original_AdjustPedestrian, AdjustPedestrian)
void AdjustPedestrian(int pIndex, int pAction_index, int pFrame_index, int pHit_points, int pDone_initial, tU16 pParent, br_actor *pParent_actor, float pSpin_period, br_scalar pJump_magnitude, br_vector3 *pOffset, br_vector3 *pTrans) {
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

    original_AdjustPedestrian(pIndex, pAction_index, pFrame_index, pHit_points, pDone_initial, pParent, pParent_actor, pSpin_period, pJump_magnitude, pOffset, pTrans);
}

static void(*original_SquirtPathVertex)(br_vertex *, br_vector3 *, ...) = (void(*)(br_vertex *, br_vector3 *, ...))0x0045c66a;
CARM95_HOOK_FUNCTION(original_SquirtPathVertex, SquirtPathVertex)
void SquirtPathVertex(br_vertex *pFirst_vertex, br_vector3 *pPoint) {
    LOG_TRACE("(%p, %p)", pFirst_vertex, pPoint);

    (void)pFirst_vertex;
    (void)pPoint;

    original_SquirtPathVertex(pFirst_vertex, pPoint);
}

static void(*original_ResetAllPedestrians)() = (void(*)())0x00459239;
CARM95_HOOK_FUNCTION(original_ResetAllPedestrians, ResetAllPedestrians)
void ResetAllPedestrians() {
    int i;
    tPedestrian_data *the_pedestrian;
    LOG_TRACE("()");

    (void)i;
    (void)the_pedestrian;

    original_ResetAllPedestrians();
}

static void(*original_GroundPedestrian)(tPedestrian_data *, ...) = (void(*)(tPedestrian_data *, ...))0x0045c75a;
CARM95_HOOK_FUNCTION(original_GroundPedestrian, GroundPedestrian)
void GroundPedestrian(tPedestrian_data *pPedestrian) {
    br_scalar new_y;
    br_vector3 cast_point;
    tPedestrian_sequence *sequence;
    LOG_TRACE("(%p)", pPedestrian);

    (void)pPedestrian;
    (void)new_y;
    (void)cast_point;
    (void)sequence;

    original_GroundPedestrian(pPedestrian);
}

static void(*original_RevivePedestrian)(tPedestrian_data *, int, ...) = (void(*)(tPedestrian_data *, int, ...))0x00459282;
CARM95_HOOK_FUNCTION(original_RevivePedestrian, RevivePedestrian)
void RevivePedestrian(tPedestrian_data *pPedestrian, int pAnimate) {
    LOG_TRACE("(%p, %d)", pPedestrian, pAnimate);

    (void)pPedestrian;
    (void)pAnimate;

    original_RevivePedestrian(pPedestrian, pAnimate);
}

static void(*original_MungePedestrians)(tU32, ...) = (void(*)(tU32, ...))0x00459476;
CARM95_HOOK_FUNCTION(original_MungePedestrians, MungePedestrians)
void MungePedestrians(tU32 pFrame_period) {
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

    original_MungePedestrians(pFrame_period);
}

static void(*original_RespawnPedestrians)() = (void(*)())0x0045c921;
CARM95_HOOK_FUNCTION(original_RespawnPedestrians, RespawnPedestrians)
void RespawnPedestrians() {
    int i;
    tPedestrian_data *the_pedestrian;
    LOG_TRACE("()");

    (void)i;
    (void)the_pedestrian;

    original_RespawnPedestrians();
}

static int(*original_GetPedCount)() = (int(*)())0x0045c9f6;
CARM95_HOOK_FUNCTION(original_GetPedCount, GetPedCount)
int GetPedCount() {
    LOG_TRACE("()");


    return original_GetPedCount();
}

static int(*original_GetPedPosition)(int, br_vector3 *, ...) = (int(*)(int, br_vector3 *, ...))0x0045ca0b;
CARM95_HOOK_FUNCTION(original_GetPedPosition, GetPedPosition)
int GetPedPosition(int pIndex, br_vector3 *pPos) {
    tPedestrian_data *pedestrian;
    LOG_TRACE("(%d, %p)", pIndex, pPos);

    (void)pIndex;
    (void)pPos;
    (void)pedestrian;

    return original_GetPedPosition(pIndex, pPos);
}

static void(*original_CreatePedestrian)(FILE *, tPedestrian_instruction *, int, int, int, int, ...) = (void(*)(FILE *, tPedestrian_instruction *, int, int, int, int, ...))0x0045cb28;
CARM95_HOOK_FUNCTION(original_CreatePedestrian, CreatePedestrian)
void CreatePedestrian(FILE *pG, tPedestrian_instruction *pInstructions, int pInstruc_count, int pInit_instruc, int pRef_num, int pForce_read) {
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

    original_CreatePedestrian(pG, pInstructions, pInstruc_count, pInit_instruc, pRef_num, pForce_read);
}

static void(*original_ResetProxRay)() = (void(*)())0x0045da5c;
CARM95_HOOK_FUNCTION(original_ResetProxRay, ResetProxRay)
void ResetProxRay() {
    int i;
    LOG_TRACE("()");

    (void)i;

    original_ResetProxRay();
}

static void(*original_PedMaterialFromHell)() = (void(*)())0x0045da99;
CARM95_HOOK_FUNCTION(original_PedMaterialFromHell, PedMaterialFromHell)
void PedMaterialFromHell() {
    LOG_TRACE("()");


    original_PedMaterialFromHell();
}

static void(*original_ResetPedMaterial)() = (void(*)())0x0045daa4;
CARM95_HOOK_FUNCTION(original_ResetPedMaterial, ResetPedMaterial)
void ResetPedMaterial() {
    int i;
    int j;
    LOG_TRACE("()");

    (void)i;
    (void)j;

    original_ResetPedMaterial();
}

static void(*original_LoadInPedestrians)(FILE *, int, tPed_subs *, ...) = (void(*)(FILE *, int, tPed_subs *, ...))0x0045dab2;
CARM95_HOOK_FUNCTION(original_LoadInPedestrians, LoadInPedestrians)
void LoadInPedestrians(FILE *pF, int pSubs_count, tPed_subs *pSubs_array) {
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

    original_LoadInPedestrians(pF, pSubs_count, pSubs_array);
}

static br_actor *(*original_BuildPedPaths)(tPedestrian_instruction *, int, int, ...) = (br_actor *(*)(tPedestrian_instruction *, int, int, ...))0x0045e839;
CARM95_HOOK_FUNCTION(original_BuildPedPaths, BuildPedPaths)
br_actor* BuildPedPaths(tPedestrian_instruction *pInstructions, int pInstruc_count, int pInit_instruc) {
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

    return original_BuildPedPaths(pInstructions, pInstruc_count, pInit_instruc);
}

static void(*original_WriteOutPeds)() = (void(*)())0x0045ee73;
CARM95_HOOK_FUNCTION(original_WriteOutPeds, WriteOutPeds)
void WriteOutPeds() {
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

    original_WriteOutPeds();
}

static void(*original_AddPed)() = (void(*)())0x0045f644;
CARM95_HOOK_FUNCTION(original_AddPed, AddPed)
void AddPed() {
    tPedestrian_instruction *instructions;
    FILE *g;
    tPath_name the_path;
    LOG_TRACE("()");

    (void)instructions;
    (void)g;
    (void)the_path;

    original_AddPed();
}

static void(*original_NewPed)(int, ...) = (void(*)(int, ...))0x0045f4f1;
CARM95_HOOK_FUNCTION(original_NewPed, NewPed)
void NewPed(int pRef_num) {
    char s[255];
    LOG_TRACE("(%d)", pRef_num);

    (void)pRef_num;
    (void)s;

    original_NewPed(pRef_num);
}

static void(*original_RemoveCurrentPedPath)() = (void(*)())0x0045f409;
CARM95_HOOK_FUNCTION(original_RemoveCurrentPedPath, RemoveCurrentPedPath)
void RemoveCurrentPedPath() {
    LOG_TRACE("()");


    original_RemoveCurrentPedPath();
}

static void(*original_ScrubPedestrian)() = (void(*)())0x0045f3cb;
CARM95_HOOK_FUNCTION(original_ScrubPedestrian, ScrubPedestrian)
void ScrubPedestrian() {
    LOG_TRACE("()");


    original_ScrubPedestrian();
}

static void(*original_TogglePedDetect)() = (void(*)())0x0045f469;
CARM95_HOOK_FUNCTION(original_TogglePedDetect, TogglePedDetect)
void TogglePedDetect() {
    LOG_TRACE("()");


    original_TogglePedDetect();
}

static void(*original_NewPed0)() = (void(*)())0x0045f4dc;
CARM95_HOOK_FUNCTION(original_NewPed0, NewPed0)
void NewPed0() {
    LOG_TRACE("()");


    original_NewPed0();
}

static void(*original_NewPed1)() = (void(*)())0x0045f72e;
CARM95_HOOK_FUNCTION(original_NewPed1, NewPed1)
void NewPed1() {
    LOG_TRACE("()");


    original_NewPed1();
}

static void(*original_NewPed2)() = (void(*)())0x0045f743;
CARM95_HOOK_FUNCTION(original_NewPed2, NewPed2)
void NewPed2() {
    LOG_TRACE("()");


    original_NewPed2();
}

static void(*original_NewPed3)() = (void(*)())0x0045f758;
CARM95_HOOK_FUNCTION(original_NewPed3, NewPed3)
void NewPed3() {
    LOG_TRACE("()");


    original_NewPed3();
}

static void(*original_NewPed4)() = (void(*)())0x0045f76d;
CARM95_HOOK_FUNCTION(original_NewPed4, NewPed4)
void NewPed4() {
    LOG_TRACE("()");


    original_NewPed4();
}

static void(*original_NewPed5)() = (void(*)())0x0045f782;
CARM95_HOOK_FUNCTION(original_NewPed5, NewPed5)
void NewPed5() {
    LOG_TRACE("()");


    original_NewPed5();
}

static void(*original_NewPed6)() = (void(*)())0x0045f797;
CARM95_HOOK_FUNCTION(original_NewPed6, NewPed6)
void NewPed6() {
    LOG_TRACE("()");


    original_NewPed6();
}

static void(*original_NewPed7)() = (void(*)())0x0045f7ac;
CARM95_HOOK_FUNCTION(original_NewPed7, NewPed7)
void NewPed7() {
    LOG_TRACE("()");


    original_NewPed7();
}

static void(*original_NewPed8)() = (void(*)())0x0045f7c1;
CARM95_HOOK_FUNCTION(original_NewPed8, NewPed8)
void NewPed8() {
    LOG_TRACE("()");


    original_NewPed8();
}

static void(*original_NewPed9)() = (void(*)())0x0045f7d6;
CARM95_HOOK_FUNCTION(original_NewPed9, NewPed9)
void NewPed9() {
    LOG_TRACE("()");


    original_NewPed9();
}

static void(*original_NewPed0B)() = (void(*)())0x0045f7eb;
CARM95_HOOK_FUNCTION(original_NewPed0B, NewPed0B)
void NewPed0B() {
    LOG_TRACE("()");


    original_NewPed0B();
}

static void(*original_NewPed1B)() = (void(*)())0x0045f800;
CARM95_HOOK_FUNCTION(original_NewPed1B, NewPed1B)
void NewPed1B() {
    LOG_TRACE("()");


    original_NewPed1B();
}

static void(*original_NewPed2B)() = (void(*)())0x0045f815;
CARM95_HOOK_FUNCTION(original_NewPed2B, NewPed2B)
void NewPed2B() {
    LOG_TRACE("()");


    original_NewPed2B();
}

static void(*original_NewPed3B)() = (void(*)())0x0045f82a;
CARM95_HOOK_FUNCTION(original_NewPed3B, NewPed3B)
void NewPed3B() {
    LOG_TRACE("()");


    original_NewPed3B();
}

static void(*original_NewPed4B)() = (void(*)())0x0045f83f;
CARM95_HOOK_FUNCTION(original_NewPed4B, NewPed4B)
void NewPed4B() {
    LOG_TRACE("()");


    original_NewPed4B();
}

static void(*original_NewPed5B)() = (void(*)())0x0045f854;
CARM95_HOOK_FUNCTION(original_NewPed5B, NewPed5B)
void NewPed5B() {
    LOG_TRACE("()");


    original_NewPed5B();
}

static void(*original_NewPed6B)() = (void(*)())0x0045f869;
CARM95_HOOK_FUNCTION(original_NewPed6B, NewPed6B)
void NewPed6B() {
    LOG_TRACE("()");


    original_NewPed6B();
}

static void(*original_NewPed7B)() = (void(*)())0x0045f87e;
CARM95_HOOK_FUNCTION(original_NewPed7B, NewPed7B)
void NewPed7B() {
    LOG_TRACE("()");


    original_NewPed7B();
}

static void(*original_NewPed8B)() = (void(*)())0x0045f893;
CARM95_HOOK_FUNCTION(original_NewPed8B, NewPed8B)
void NewPed8B() {
    LOG_TRACE("()");


    original_NewPed8B();
}

static void(*original_NewPed9B)() = (void(*)())0x0045f8a8;
CARM95_HOOK_FUNCTION(original_NewPed9B, NewPed9B)
void NewPed9B() {
    LOG_TRACE("()");


    original_NewPed9B();
}

static void(*original_MungeShowPedPath)() = (void(*)())0x0045f94b;
CARM95_HOOK_FUNCTION(original_MungeShowPedPath, MungeShowPedPath)
void MungeShowPedPath() {
    LOG_TRACE("()");


    original_MungeShowPedPath();
}

static void(*original_DropPedPoint2)() = (void(*)())0x0045f8e5;
CARM95_HOOK_FUNCTION(original_DropPedPoint2, DropPedPoint2)
void DropPedPoint2() {
    LOG_TRACE("()");


    original_DropPedPoint2();
}

static void(*original_DropPedPoint)() = (void(*)())0x0045f8bd;
CARM95_HOOK_FUNCTION(original_DropPedPoint, DropPedPoint)
void DropPedPoint() {
    LOG_TRACE("()");


    original_DropPedPoint();
}

static void(*original_DropInitPedPoint)() = (void(*)())0x0045f9a4;
CARM95_HOOK_FUNCTION(original_DropInitPedPoint, DropInitPedPoint)
void DropInitPedPoint() {
    LOG_TRACE("()");


    original_DropInitPedPoint();
}

static void(*original_DropPedPointAir2)() = (void(*)())0x0045f9fe;
CARM95_HOOK_FUNCTION(original_DropPedPointAir2, DropPedPointAir2)
void DropPedPointAir2() {
    LOG_TRACE("()");


    original_DropPedPointAir2();
}

static void(*original_DropPedPointAir)() = (void(*)())0x0045f9d6;
CARM95_HOOK_FUNCTION(original_DropPedPointAir, DropPedPointAir)
void DropPedPointAir() {
    LOG_TRACE("()");


    original_DropPedPointAir();
}

static void(*original_DropInitPedPointAir)() = (void(*)())0x0045fa88;
CARM95_HOOK_FUNCTION(original_DropInitPedPointAir, DropInitPedPointAir)
void DropInitPedPointAir() {
    LOG_TRACE("()");


    original_DropInitPedPointAir();
}

static br_uint_32(*original_KillActorsModel)(br_actor *, void *, ...) = (br_uint_32(*)(br_actor *, void *, ...))0x0045ff83;
CARM95_HOOK_FUNCTION(original_KillActorsModel, KillActorsModel)
br_uint_32 KillActorsModel(br_actor *pActor, void *pArg) {
    LOG_TRACE("(%p, %p)", pActor, pArg);

    (void)pActor;
    (void)pArg;

    return original_KillActorsModel(pActor, pArg);
}

static void(*original_DisposePedPaths)() = (void(*)())0x0045fef8;
CARM95_HOOK_FUNCTION(original_DisposePedPaths, DisposePedPaths)
void DisposePedPaths() {
    LOG_TRACE("()");


    original_DisposePedPaths();
}

static void(*original_GetPedPos)(int *, int *, ...) = (void(*)(int *, int *, ...))0x0045faba;
CARM95_HOOK_FUNCTION(original_GetPedPos, GetPedPos)
void GetPedPos(int *pPed_index, int *pPoint_index) {
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

    original_GetPedPos(pPed_index, pPoint_index);
}

static void(*original_ShowPedPos)() = (void(*)())0x0045fc96;
CARM95_HOOK_FUNCTION(original_ShowPedPos, ShowPedPos)
void ShowPedPos() {
    int min_ped;
    int min_point;
    char s[255];
    LOG_TRACE("()");

    (void)min_ped;
    (void)min_point;
    (void)s;

    original_ShowPedPos();
}

static void(*original_ShowPedPaths)() = (void(*)())0x0045fcf5;
CARM95_HOOK_FUNCTION(original_ShowPedPaths, ShowPedPaths)
void ShowPedPaths() {
    int i;
    br_model *the_model;
    LOG_TRACE("()");

    (void)i;
    (void)the_model;

    original_ShowPedPaths();
}

static void(*original_PullPedPoint)() = (void(*)())0x0045fe84;
CARM95_HOOK_FUNCTION(original_PullPedPoint, PullPedPoint)
void PullPedPoint() {
    int the_ped;
    int the_point;
    LOG_TRACE("()");

    (void)the_ped;
    (void)the_point;

    original_PullPedPoint();
}

static void(*original_PullPedPointAir)() = (void(*)())0x0045ffc0;
CARM95_HOOK_FUNCTION(original_PullPedPointAir, PullPedPointAir)
void PullPedPointAir() {
    int the_ped;
    int the_point;
    LOG_TRACE("()");

    (void)the_ped;
    (void)the_point;

    original_PullPedPointAir();
}

static void(*original_DeletePedPath)() = (void(*)())0x00460082;
CARM95_HOOK_FUNCTION(original_DeletePedPath, DeletePedPath)
void DeletePedPath() {
    int the_ped;
    int the_point;
    int i;
    LOG_TRACE("()");

    (void)the_ped;
    (void)the_point;
    (void)i;

    original_DeletePedPath();
}

static void(*original_DeletePedPoint)() = (void(*)())0x0046010f;
CARM95_HOOK_FUNCTION(original_DeletePedPoint, DeletePedPoint)
void DeletePedPoint() {
    LOG_TRACE("()");


    original_DeletePedPoint();
}

static void(*original_DisposePedestrians)() = (void(*)())0x00460169;
CARM95_HOOK_FUNCTION(original_DisposePedestrians, DisposePedestrians)
void DisposePedestrians() {
    int i;
    int j;
    tPedestrian_data *the_pedestrian;
    LOG_TRACE("()");

    (void)i;
    (void)j;
    (void)the_pedestrian;

    original_DisposePedestrians();
}

static void(*original_DoPedReport)() = (void(*)())0x004603d6;
CARM95_HOOK_FUNCTION(original_DoPedReport, DoPedReport)
void DoPedReport() {
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

    original_DoPedReport();
}

static void(*original_RenderProximityRays)(br_pixelmap *, br_pixelmap *, br_actor *, br_matrix34 *, tU32, ...) = (void(*)(br_pixelmap *, br_pixelmap *, br_actor *, br_matrix34 *, tU32, ...))0x00460696;
CARM95_HOOK_FUNCTION(original_RenderProximityRays, RenderProximityRays)
void RenderProximityRays(br_pixelmap *pRender_screen, br_pixelmap *pDepth_buffer, br_actor *pCamera, br_matrix34 *pCamera_to_world, tU32 pTime) {
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

    original_RenderProximityRays(pRender_screen, pDepth_buffer, pCamera, pCamera_to_world, pTime);
}

static void(*original_AdjustProxRay)(int, tU16, tU16, tU32, ...) = (void(*)(int, tU16, tU16, tU32, ...))0x00460ac5;
CARM95_HOOK_FUNCTION(original_AdjustProxRay, AdjustProxRay)
void AdjustProxRay(int pRay_index, tU16 pCar_ID, tU16 pPed_index, tU32 pTime) {
    LOG_TRACE("(%d, %u, %u, %u)", pRay_index, pCar_ID, pPed_index, pTime);

    (void)pRay_index;
    (void)pCar_ID;
    (void)pPed_index;
    (void)pTime;

    original_AdjustProxRay(pRay_index, pCar_ID, pPed_index, pTime);
}

static void(*original_ReceivedPedestrian)(tNet_contents *, tNet_message *, tU32, ...) = (void(*)(tNet_contents *, tNet_message *, tU32, ...))0x00460b66;
CARM95_HOOK_FUNCTION(original_ReceivedPedestrian, ReceivedPedestrian)
void ReceivedPedestrian(tNet_contents *pContents, tNet_message *pMessage, tU32 pReceive_time) {
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

    original_ReceivedPedestrian(pContents, pMessage, pReceive_time);
}

static void(*original_SendAllPedestrianPositions)(tPlayer_ID, ...) = (void(*)(tPlayer_ID, ...))0x0046109c;
CARM95_HOOK_FUNCTION(original_SendAllPedestrianPositions, SendAllPedestrianPositions)
void SendAllPedestrianPositions(tPlayer_ID pPlayer) {
    int i;
    tPedestrian_data *the_pedestrian;
    tNet_contents *the_contents;
    LOG_TRACE("(%u)", pPlayer);

    (void)pPlayer;
    (void)i;
    (void)the_pedestrian;
    (void)the_contents;

    original_SendAllPedestrianPositions(pPlayer);
}

