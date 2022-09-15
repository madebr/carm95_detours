#include "crush.h"
#include "displays.h"
#include "globvars.h"
#include "globvrpb.h"
#include "netgame.h"
#include "network.h"
#include "opponent.h"
#include "pratcam.h"
#include "raycast.h"
#include "utility.h"

#include <brender/brender.h>
#include <pc-dos/dossys.h>

#include "harness/trace.h"

#include "carm95_hooks.h"

#include <stdio.h>
float(* hookvar_gWobble_spam_y )[8] = (void*)0x00521370;
float(* hookvar_gWobble_spam_z )[8] = (void*)0x00521390;
br_scalar * hookvar_gWheel_circ_to_width  = (void*)0x005213b0;
tU8(* hookvar_gSmoke_damage_step )[12] = (void*)0x005213b8;
int(* hookvar_gSteal_ranks )[5] = (void*)0x005213c4;

static int(*original_ReadCrushData)(FILE *, tCrush_data *, ...) = (int(*)(FILE *, tCrush_data *, ...))0x004bca50;
CARM95_HOOK_FUNCTION(original_ReadCrushData, ReadCrushData)
int ReadCrushData(FILE *pF, tCrush_data *pCrush_data) {
    char s[256];
    char *str;
    int i;
    int j;
    int k;
    tCrush_point_spec *the_spec;
    tCrush_neighbour *the_neighbour;
    float __block0__x_0;
    float __block0__x_1;
    float __block0__x_2;
    float __block1__x_0;
    float __block1__x_1;
    float __block1__x_2;
    float __block2__x_0;
    float __block2__x_1;
    float __block2__x_2;
    float __block3__x_0;
    float __block3__x_1;
    float __block3__x_2;
    LOG_TRACE("(%p, %p)", pF, pCrush_data);

    (void)pF;
    (void)pCrush_data;
    (void)s;
    (void)str;
    (void)i;
    (void)j;
    (void)k;
    (void)the_spec;
    (void)the_neighbour;

    return original_ReadCrushData(pF, pCrush_data);
}

static float(*original_SkipCrushData)(FILE *, ...) = (float(*)(FILE *, ...))0x004bcd40;
CARM95_HOOK_FUNCTION(original_SkipCrushData, SkipCrushData)
float SkipCrushData(FILE *pF) {
    int i;
    int j;
    int count_1;
    int count_2;
    char s[256];
    float softness;
    LOG_TRACE("(%p)", pF);

    (void)pF;
    (void)i;
    (void)j;
    (void)count_1;
    (void)count_2;
    (void)s;
    (void)softness;

    return original_SkipCrushData(pF);
}

static int(*original_WriteCrushData)(FILE *, tCrush_data *, ...) = (int(*)(FILE *, tCrush_data *, ...))0x004bce73;
CARM95_HOOK_FUNCTION(original_WriteCrushData, WriteCrushData)
int WriteCrushData(FILE *pF, tCrush_data *pCrush_data) {
    int i;
    int j;
    int k;
    tCrush_point_spec *the_spec;
    tCrush_neighbour *the_neighbour;
    LOG_TRACE("(%p, %p)", pF, pCrush_data);

    (void)pF;
    (void)pCrush_data;
    (void)i;
    (void)j;
    (void)k;
    (void)the_spec;
    (void)the_neighbour;

    return original_WriteCrushData(pF, pCrush_data);
}

static void(*original_DisposeCrushData)(tCrush_data *, ...) = (void(*)(tCrush_data *, ...))0x004bd0f7;
CARM95_HOOK_FUNCTION(original_DisposeCrushData, DisposeCrushData)
void DisposeCrushData(tCrush_data *pCrush_data) {
    int i;
    LOG_TRACE("(%p)", pCrush_data);

    (void)pCrush_data;
    (void)i;

    original_DisposeCrushData(pCrush_data);
}

static void(*original_CrushModelPoint)(tCar_spec *, int, br_model *, int, br_vector3 *, br_scalar, tCrush_data *, ...) = (void(*)(tCar_spec *, int, br_model *, int, br_vector3 *, br_scalar, tCrush_data *, ...))0x004bd17b;
CARM95_HOOK_FUNCTION(original_CrushModelPoint, CrushModelPoint)
void CrushModelPoint(tCar_spec *pCar, int pModel_index, br_model *pModel, int pCrush_point_index, br_vector3 *pEnergy_vector, br_scalar total_energy, tCrush_data *pCrush_data) {
    int i;
    int j;
    int k;
    int pipe_vertex_count;
    int neighbour_index;
    int bend_axis;
    int default_bend_axis[3];
    tCrush_point_spec *the_crush_point;
    tCrush_neighbour *the_neighbour;
    br_vector3 *target_point;
    br_vector3 old_vector;
    br_vector3 softnesss;
    br_vector3 movement;
    br_scalar random_range;
    br_scalar bend_amount;
    br_scalar min_y_fold_down;
    float default_bend_factor[3];
    float working_min_fold;
    float working_max_fold;
    float working_wibble;
    float working_limit_deviant;
    float working_split_chance;
    tChanged_vertex pipe_array[600];
    tCar_spec *car;
    LOG_TRACE("(%p, %d, %p, %d, %p, %f, %p)", pCar, pModel_index, pModel, pCrush_point_index, pEnergy_vector, total_energy, pCrush_data);

    (void)pCar;
    (void)pModel_index;
    (void)pModel;
    (void)pCrush_point_index;
    (void)pEnergy_vector;
    (void)total_energy;
    (void)pCrush_data;
    (void)i;
    (void)j;
    (void)k;
    (void)pipe_vertex_count;
    (void)neighbour_index;
    (void)bend_axis;
    (void)default_bend_axis;
    (void)the_crush_point;
    (void)the_neighbour;
    (void)target_point;
    (void)old_vector;
    (void)softnesss;
    (void)movement;
    (void)random_range;
    (void)bend_amount;
    (void)min_y_fold_down;
    (void)default_bend_factor;
    (void)working_min_fold;
    (void)working_max_fold;
    (void)working_wibble;
    (void)working_limit_deviant;
    (void)working_split_chance;
    (void)pipe_array;
    (void)car;

    original_CrushModelPoint(pCar, pModel_index, pModel, pCrush_point_index, pEnergy_vector, total_energy, pCrush_data);
}

static void(*original_CrushModel)(tCar_spec *, int, br_actor *, br_vector3 *, br_vector3 *, tCrush_data *, ...) = (void(*)(tCar_spec *, int, br_actor *, br_vector3 *, br_vector3 *, tCrush_data *, ...))0x004bd8da;
CARM95_HOOK_FUNCTION(original_CrushModel, CrushModel)
void CrushModel(tCar_spec *pCar, int pModel_index, br_actor *pActor, br_vector3 *pImpact_point, br_vector3 *pEnergy_vector, tCrush_data *pCrush_data) {
    br_scalar this_distance;
    br_scalar total_energy;
    br_scalar nearest_so_far;
    br_vector3 impact_point_model;
    br_vector3 energy_vector_scaled;
    br_vector3 energy_vector_model;
    int i;
    int nearest_index;
    br_vertex *vertices;
    br_vertex *the_vertex;
    br_matrix34 inverse_transform;
    LOG_TRACE("(%p, %d, %p, %p, %p, %p)", pCar, pModel_index, pActor, pImpact_point, pEnergy_vector, pCrush_data);

    (void)pCar;
    (void)pModel_index;
    (void)pActor;
    (void)pImpact_point;
    (void)pEnergy_vector;
    (void)pCrush_data;
    (void)this_distance;
    (void)total_energy;
    (void)nearest_so_far;
    (void)impact_point_model;
    (void)energy_vector_scaled;
    (void)energy_vector_model;
    (void)i;
    (void)nearest_index;
    (void)vertices;
    (void)the_vertex;
    (void)inverse_transform;

    original_CrushModel(pCar, pModel_index, pActor, pImpact_point, pEnergy_vector, pCrush_data);
}

static void(*original_JitModelUpdate)(br_actor *, br_model *, br_material *, void *, br_uint_8, int, ...) = (void(*)(br_actor *, br_model *, br_material *, void *, br_uint_8, int, ...))0x004bdad9;
CARM95_HOOK_FUNCTION(original_JitModelUpdate, JitModelUpdate)
void JitModelUpdate(br_actor *actor, br_model *model, br_material *material, void *render_data, br_uint_8 style, int on_screen) {
    LOG_TRACE("(%p, %p, %p, %p, %u, %d)", actor, model, material, render_data, style, on_screen);

    (void)actor;
    (void)model;
    (void)material;
    (void)render_data;
    (void)style;
    (void)on_screen;

    original_JitModelUpdate(actor, model, material, render_data, style, on_screen);
}

static void(*original_SetModelForUpdate)(br_model *, tCar_spec *, int, ...) = (void(*)(br_model *, tCar_spec *, int, ...))0x004bdb2f;
CARM95_HOOK_FUNCTION(original_SetModelForUpdate, SetModelForUpdate)
void SetModelForUpdate(br_model *pModel, tCar_spec *pCar, int crush_only) {
    LOG_TRACE("(%p, %p, %d)", pModel, pCar, crush_only);

    (void)pModel;
    (void)pCar;
    (void)crush_only;

    original_SetModelForUpdate(pModel, pCar, crush_only);
}

static void(*original_TotallySpamTheModel)(tCar_spec *, int, br_actor *, tCrush_data *, br_scalar, ...) = (void(*)(tCar_spec *, int, br_actor *, tCrush_data *, br_scalar, ...))0x004bdbc1;
CARM95_HOOK_FUNCTION(original_TotallySpamTheModel, TotallySpamTheModel)
void TotallySpamTheModel(tCar_spec *pCar, int pModel_index, br_actor *pActor, tCrush_data *pCrush_data, br_scalar pMagnitude) {
    br_scalar total_energy;
    br_vector3 energy_vector_model;
    int i;
    int the_index;
    br_vertex *the_vertex;
    br_vertex *vertices;
    br_scalar __block0___scale;
    LOG_TRACE("(%p, %d, %p, %p, %f)", pCar, pModel_index, pActor, pCrush_data, pMagnitude);

    (void)pCar;
    (void)pModel_index;
    (void)pActor;
    (void)pCrush_data;
    (void)pMagnitude;
    (void)total_energy;
    (void)energy_vector_model;
    (void)i;
    (void)the_index;
    (void)the_vertex;
    (void)vertices;

    original_TotallySpamTheModel(pCar, pModel_index, pActor, pCrush_data, pMagnitude);
}

static br_scalar(*original_RepairModel)(tCar_spec *, int, br_actor *, br_vertex *, br_scalar, br_scalar *, ...) = (br_scalar(*)(tCar_spec *, int, br_actor *, br_vertex *, br_scalar, br_scalar *, ...))0x004bde6c;
CARM95_HOOK_FUNCTION(original_RepairModel, RepairModel)
br_scalar RepairModel(tCar_spec *pCar, int pModel_index, br_actor *pActor, br_vertex *pUndamaged_vertices, br_scalar pAmount, br_scalar *pTotal_deflection) {
    int i;
    int j;
    int pipe_vertex_count;
    br_vector3 old_point;
    br_vertex *model_vertex;
    br_scalar amount;
    br_scalar deviation;
    tChanged_vertex pipe_array[600];
    LOG_TRACE("(%p, %d, %p, %p, %f, %p)", pCar, pModel_index, pActor, pUndamaged_vertices, pAmount, pTotal_deflection);

    (void)pCar;
    (void)pModel_index;
    (void)pActor;
    (void)pUndamaged_vertices;
    (void)pAmount;
    (void)pTotal_deflection;
    (void)i;
    (void)j;
    (void)pipe_vertex_count;
    (void)old_point;
    (void)model_vertex;
    (void)amount;
    (void)deviation;
    (void)pipe_array;

    return original_RepairModel(pCar, pModel_index, pActor, pUndamaged_vertices, pAmount, pTotal_deflection);
}

static float(*original_RepairCar2)(tCar_spec *, tU32, br_scalar *, ...) = (float(*)(tCar_spec *, tU32, br_scalar *, ...))0x004bdd3b;
CARM95_HOOK_FUNCTION(original_RepairCar2, RepairCar2)
float RepairCar2(tCar_spec *pCar, tU32 pFrame_period, br_scalar *pTotal_deflection) {
    int i;
    tCar_actor *the_car_actor;
    br_scalar amount;
    br_scalar dummy;
    LOG_TRACE("(%p, %u, %p)", pCar, pFrame_period, pTotal_deflection);

    (void)pCar;
    (void)pFrame_period;
    (void)pTotal_deflection;
    (void)i;
    (void)the_car_actor;
    (void)amount;
    (void)dummy;

    return original_RepairCar2(pCar, pFrame_period, pTotal_deflection);
}

static float(*original_RepairCar)(tU16, tU32, br_scalar *, ...) = (float(*)(tU16, tU32, br_scalar *, ...))0x004be159;
CARM95_HOOK_FUNCTION(original_RepairCar, RepairCar)
float RepairCar(tU16 pCar_ID, tU32 pFrame_period, br_scalar *pTotal_deflection) {
    LOG_TRACE("(%u, %u, %p)", pCar_ID, pFrame_period, pTotal_deflection);

    (void)pCar_ID;
    (void)pFrame_period;
    (void)pTotal_deflection;

    return original_RepairCar(pCar_ID, pFrame_period, pTotal_deflection);
}

static void(*original_TotallyRepairACar)(tCar_spec *, ...) = (void(*)(tCar_spec *, ...))0x004be1ca;
CARM95_HOOK_FUNCTION(original_TotallyRepairACar, TotallyRepairACar)
void TotallyRepairACar(tCar_spec *pCar) {
    int i;
    int j;
    int k;
    int pipe_vertex_count;
    tCar_actor *the_car_actor;
    tChanged_vertex pipe_array[600];
    br_bounds storage_bounds;
    LOG_TRACE("(%p)", pCar);

    (void)pCar;
    (void)i;
    (void)j;
    (void)k;
    (void)pipe_vertex_count;
    (void)the_car_actor;
    (void)pipe_array;
    (void)storage_bounds;

    original_TotallyRepairACar(pCar);
}

static void(*original_TotallyRepairCar)() = (void(*)())0x004be52a;
CARM95_HOOK_FUNCTION(original_TotallyRepairCar, TotallyRepairCar)
void TotallyRepairCar() {
    LOG_TRACE("()");


    original_TotallyRepairCar();
}

static void(*original_CheckLastCar)() = (void(*)())0x004be5b5;
CARM95_HOOK_FUNCTION(original_CheckLastCar, CheckLastCar)
void CheckLastCar() {
    LOG_TRACE("()");


    original_CheckLastCar();
}

static void(*original_KnackerThisCar)(tCar_spec *, ...) = (void(*)(tCar_spec *, ...))0x004be555;
CARM95_HOOK_FUNCTION(original_KnackerThisCar, KnackerThisCar)
void KnackerThisCar(tCar_spec *pCar) {
    LOG_TRACE("(%p)", pCar);

    (void)pCar;

    original_KnackerThisCar(pCar);
}

void SetKnackeredFlag(tCar_spec *pCar) {
    LOG_TRACE("(%p)", pCar);

    (void)pCar;

    NOT_IMPLEMENTED();
}

static void(*original_DamageUnit2)(tCar_spec *, int, int, ...) = (void(*)(tCar_spec *, int, int, ...))0x004be737;
CARM95_HOOK_FUNCTION(original_DamageUnit2, DamageUnit2)
void DamageUnit2(tCar_spec *pCar, int pUnit_type, int pDamage_amount) {
    tDamage_unit *the_damage;
    int last_level;
    LOG_TRACE("(%p, %d, %d)", pCar, pUnit_type, pDamage_amount);

    (void)pCar;
    (void)pUnit_type;
    (void)pDamage_amount;
    (void)the_damage;
    (void)last_level;

    original_DamageUnit2(pCar, pUnit_type, pDamage_amount);
}

static void(*original_RecordLastDamage)(tCar_spec *, ...) = (void(*)(tCar_spec *, ...))0x004be86b;
CARM95_HOOK_FUNCTION(original_RecordLastDamage, RecordLastDamage)
void RecordLastDamage(tCar_spec *pCar) {
    int i;
    LOG_TRACE("(%p)", pCar);

    (void)pCar;
    (void)i;

    original_RecordLastDamage(pCar);
}

static void(*original_DoDamage)(tCar_spec *, tDamage_type, float, float, ...) = (void(*)(tCar_spec *, tDamage_type, float, float, ...))0x004bf3b9;
CARM95_HOOK_FUNCTION(original_DoDamage, DoDamage)
void DoDamage(tCar_spec *pCar, tDamage_type pDamage_type, float pMagnitude, float pNastiness) {
    LOG_TRACE("(%p, %d, %f, %f)", pCar, pDamage_type, pMagnitude, pNastiness);

    (void)pCar;
    (void)pDamage_type;
    (void)pMagnitude;
    (void)pNastiness;

    original_DoDamage(pCar, pDamage_type, pMagnitude, pNastiness);
}

static void(*original_CheckPiledriverBonus)(tCar_spec *, br_vector3 *, br_vector3 *, ...) = (void(*)(tCar_spec *, br_vector3 *, br_vector3 *, ...))0x004bf4b2;
CARM95_HOOK_FUNCTION(original_CheckPiledriverBonus, CheckPiledriverBonus)
void CheckPiledriverBonus(tCar_spec *pCar, br_vector3 *pImpact_point, br_vector3 *pEnergy) {
    br_actor *child;
    br_vector3 norm_impact;
    br_vector3 norm_child;
    br_vector3 norm_energy;
    br_scalar dp;
    br_scalar __block0___scale;
    br_scalar __block1___scale;
    br_scalar __block2___scale;
    LOG_TRACE("(%p, %p, %p)", pCar, pImpact_point, pEnergy);

    (void)pCar;
    (void)pImpact_point;
    (void)pEnergy;
    (void)child;
    (void)norm_impact;
    (void)norm_child;
    (void)norm_energy;
    (void)dp;

    original_CheckPiledriverBonus(pCar, pImpact_point, pEnergy);
}

static tImpact_location(*original_CalcModifiedLocation)(tCar_spec *, ...) = (tImpact_location(*)(tCar_spec *, ...))0x004c13e0;
CARM95_HOOK_FUNCTION(original_CalcModifiedLocation, CalcModifiedLocation)
tImpact_location CalcModifiedLocation(tCar_spec *pCar) {
    LOG_TRACE("(%p)", pCar);

    (void)pCar;

    return original_CalcModifiedLocation(pCar);
}

static void(*original_DoPratcamHit)(br_vector3 *, ...) = (void(*)(br_vector3 *, ...))0x004be97b;
CARM95_HOOK_FUNCTION(original_DoPratcamHit, DoPratcamHit)
void DoPratcamHit(br_vector3 *pHit_vector) {
    int strength_modifier;
    br_scalar strength;
    LOG_TRACE("(%p)", pHit_vector);

    (void)pHit_vector;
    (void)strength_modifier;
    (void)strength;

    original_DoPratcamHit(pHit_vector);
}

static void(*original_DamageSystems)(tCar_spec *, br_vector3 *, br_vector3 *, int, ...) = (void(*)(tCar_spec *, br_vector3 *, br_vector3 *, int, ...))0x004beaa3;
CARM95_HOOK_FUNCTION(original_DamageSystems, DamageSystems)
void DamageSystems(tCar_spec *pCar, br_vector3 *pImpact_point, br_vector3 *pEnergy_vector, int pWas_hitting_a_car) {
    int i;
    int j;
    int result;
    br_bounds crushed_car_bounds;
    float proportion_x;
    float proportion_y;
    float proportion_z;
    float energy_magnitude;
    float pure_energy_magnitude;
    br_scalar x;
    br_scalar y;
    br_scalar z;
    br_scalar x1;
    br_scalar x2;
    br_scalar y1;
    br_scalar y2;
    br_scalar z1;
    br_scalar z2;
    br_scalar distance;
    tImpact_location impact_location;
    tDamage_program *the_program;
    tDamage_clause *the_clause;
    tDamage_condition *the_condition;
    tDamage_effect *the_effect;
    tImpact_location modified_location;
    LOG_TRACE("(%p, %p, %p, %d)", pCar, pImpact_point, pEnergy_vector, pWas_hitting_a_car);

    (void)pCar;
    (void)pImpact_point;
    (void)pEnergy_vector;
    (void)pWas_hitting_a_car;
    (void)i;
    (void)j;
    (void)result;
    (void)crushed_car_bounds;
    (void)proportion_x;
    (void)proportion_y;
    (void)proportion_z;
    (void)energy_magnitude;
    (void)pure_energy_magnitude;
    (void)x;
    (void)y;
    (void)z;
    (void)x1;
    (void)x2;
    (void)y1;
    (void)y2;
    (void)z1;
    (void)z2;
    (void)distance;
    (void)impact_location;
    (void)the_program;
    (void)the_clause;
    (void)the_condition;
    (void)the_effect;
    (void)modified_location;

    original_DamageSystems(pCar, pImpact_point, pEnergy_vector, pWas_hitting_a_car);
}

static tImpact_location(*original_GetDirection)(br_vector3 *, ...) = (tImpact_location(*)(br_vector3 *, ...))0x004c1486;
CARM95_HOOK_FUNCTION(original_GetDirection, GetDirection)
tImpact_location GetDirection(br_vector3 *pVelocity) {
    br_scalar mag_x;
    br_scalar mag_y;
    br_scalar mag_z;
    LOG_TRACE("(%p)", pVelocity);

    (void)pVelocity;
    (void)mag_x;
    (void)mag_y;
    (void)mag_z;

    return original_GetDirection(pVelocity);
}

static void(*original_SetSmokeLastDamageLevel)(tCar_spec *, ...) = (void(*)(tCar_spec *, ...))0x004bf768;
CARM95_HOOK_FUNCTION(original_SetSmokeLastDamageLevel, SetSmokeLastDamageLevel)
void SetSmokeLastDamageLevel(tCar_spec *pCar) {
    int i;
    LOG_TRACE("(%p)", pCar);

    (void)pCar;
    (void)i;

    original_SetSmokeLastDamageLevel(pCar);
}

static void(*original_SortOutSmoke)(tCar_spec *, ...) = (void(*)(tCar_spec *, ...))0x004bf7c2;
CARM95_HOOK_FUNCTION(original_SortOutSmoke, SortOutSmoke)
void SortOutSmoke(tCar_spec *pCar) {
    int i;
    int colour;
    int old_colour;
    int step;
    int pass;
    int repeat;
    LOG_TRACE("(%p)", pCar);

    (void)pCar;
    (void)i;
    (void)colour;
    (void)old_colour;
    (void)step;
    (void)pass;
    (void)repeat;

    original_SortOutSmoke(pCar);
}

static void(*original_StealCar)(tCar_spec *, ...) = (void(*)(tCar_spec *, ...))0x004bf923;
CARM95_HOOK_FUNCTION(original_StealCar, StealCar)
void StealCar(tCar_spec *pCar) {
    LOG_TRACE("(%p)", pCar);

    (void)pCar;

    original_StealCar(pCar);
}

static int(*original_DoCrashEarnings)(tCar_spec *, tCar_spec *, ...) = (int(*)(tCar_spec *, tCar_spec *, ...))0x004bfdb3;
CARM95_HOOK_FUNCTION(original_DoCrashEarnings, DoCrashEarnings)
int DoCrashEarnings(tCar_spec *pCar1, tCar_spec *pCar2) {
    tCar_spec *culprit;
    tCar_spec *victim;
    int i;
    int net_loop;
    int head_on;
    int bonus_level;
    int credits;
    int impact_in_moving_direction_1;
    int impact_in_moving_direction_2;
    int car_off_ground_1;
    int car_off_ground_2;
    int total_units_of_damage;
    int inherited_damage;
    int dam_acc_1;
    int dam_acc_2;
    int car_1_culpable;
    int car_2_culpable;
    int mutual_culpability;
    tU32 the_time;
    tU32 time;
    float credits_squared;
    static tU32 last_earn_time;
    char s[256];
    tImpact_location modified_location_1;
    tImpact_location modified_location_2;
    tImpact_location car_direction_1;
    tImpact_location car_direction_2;
    br_scalar car_1_height;
    br_scalar car_2_height;
    br_scalar dp;
    br_vector3 car_1_pos;
    br_vector3 car_2_pos;
    br_vector3 car_1_offset;
    br_vector3 car_2_offset;
    tNet_message *message;
    LOG_TRACE("(%p, %p)", pCar1, pCar2);



    culprit = 0;
    victim = 0;
    head_on = 0;
    bonus_level = 1;
    car_1_culpable = 0;
    car_2_culpable = 0;
    mutual_culpability = 0;
    the_time = PDGetTotalTime();
    inherited_damage = 0;
    if (pCar1->driver <= eDriver_non_car) {
        dam_acc_1 = 0;
    }
    else {
        dam_acc_1 = pCar1->damage_magnitude_accumulator;
    }
    // dam_acc_2 = pCar2
    //     && (pCar2->driver <= eDriver_non_car ? (v21 = 0.0) : (v21 = pCar2->damage_magnitude_accumulator), v21 != 0.0);

    dam_acc_2 = 0;
    if (pCar2) {
        if (pCar1->driver <= eDriver_non_car) {
            dam_acc_2 = 0;
        }
        else {
            dam_acc_2 = pCar2->damage_magnitude_accumulator != 0;
        }
    }

    if (pCar1->driver <= eDriver_non_car) {
        if (pCar2 == NULL || pCar2->driver <= eDriver_non_car) {
            return 0;
        }
        pCar1 = pCar2;
        pCar2 = NULL;
    }
    if (pCar2 != NULL && pCar2->driver <= eDriver_non_car) {
        pCar2 = NULL;
    }

    if (pCar1->pre_car_col_knackered || (pCar2 && pCar2->pre_car_col_knackered) || (pCar2 && pCar2->damage_magnitude_accumulator <= 0.00005f && pCar1->damage_magnitude_accumulator <= 0.00005f)) {
        return dam_acc_1 || (pCar2 && dam_acc_2);
    }
    // if (!pCar1->pre_car_col_knackered
    //     && (pCar2 == NULL || !pCar2->pre_car_col_knackered)
    //     && (pCar2 == NULL || pCar2->damage_magnitude_accumulator > 0.00005f || pCar1->damage_magnitude_accumulator > 0.00005f)) {

    modified_location_1 = CalcModifiedLocation(pCar1);
    car_direction_1 = GetDirection(&pCar1->pre_car_col_velocity_car_space);
    impact_in_moving_direction_1 = car_direction_1 == modified_location_1;
    if (pCar2 != NULL) {
        modified_location_2 = CalcModifiedLocation(pCar2);
        car_direction_2 = GetDirection(&pCar2->pre_car_col_velocity_car_space);
        impact_in_moving_direction_2 = car_direction_2 == modified_location_2;
    }
    if (pCar1->driver >= eDriver_net_human && pCar2) {
        if (impact_in_moving_direction_1 && (pCar1->driver < eDriver_net_human || (pCar1->pre_car_col_velocity_car_space.v[2] != 0.0 && pCar1->pre_car_col_velocity_car_space.v[2] > 0.0 != pCar1->gear > 0 && (pCar1->keys.acc != 0 || pCar1->joystick.acc > 0x8000)))) {
            pCar2->time_last_hit = the_time;
            pCar2->last_hit_by = pCar1;
        }
    }
    else if (pCar2 && pCar2->driver >= eDriver_net_human && impact_in_moving_direction_2 && (pCar2->driver < eDriver_net_human || (pCar2->pre_car_col_velocity_car_space.v[2] != 0.0f && pCar2->pre_car_col_velocity_car_space.v[2] > 0.0f != pCar2->gear > 0 && (pCar2->keys.acc != 0 || pCar2->joystick.acc > 0x8000)))) {
        pCar1->time_last_hit = the_time;
        pCar1->last_hit_by = pCar2;
    }
    if (pCar2) {
        if (impact_in_moving_direction_1
            && pCar1->pre_car_col_speed * 5.0f > pCar2->pre_car_col_speed
            && pCar1->pre_car_col_speed > 0.0005f
            && (pCar1->driver < eDriver_net_human
                || (pCar1->pre_car_col_velocity_car_space.v[2] != 0.0f
                    && pCar1->pre_car_col_velocity_car_space.v[2] > 0.0f != pCar1->gear > 0
                    && (pCar1->keys.acc != 0 || pCar1->joystick.acc > 0x8000)))) {
            car_1_culpable = 1;
        }
        if (impact_in_moving_direction_2
            && pCar2->pre_car_col_speed * 5.0f > pCar1->pre_car_col_speed
            && pCar2->pre_car_col_speed > 0.0005f
            && (pCar2->driver < eDriver_net_human
                || (pCar2->pre_car_col_velocity_car_space.v[2] != 0.0f
                    && pCar2->pre_car_col_velocity_car_space.v[2] > 0.0f != pCar2->gear > 0
                    && (pCar2->keys.acc != 0 || pCar2->joystick.acc > 0x8000)))) {
            car_2_culpable = 1;
        }
        if (HV(gNet_mode) && car_1_culpable && car_2_culpable) {
            mutual_culpability = 1;
        }
        else {
            if (car_2_culpable && pCar2->driver == eDriver_local_human) {
                car_1_culpable = 0;
            }
            if (car_1_culpable) {
                culprit = pCar1;
                victim = pCar2;
                dp = BrVector3Dot(&pCar1->pre_car_col_direction, &pCar1->pre_car_col_direction); /* pCar1->pre_car_col_direction.v[2] * pCar2->pre_car_col_direction.v[2]
                     + pCar2->pre_car_col_direction.v[1] * pCar1->pre_car_col_direction.v[1]
                     + pCar2->pre_car_col_direction.v[0] * pCar1->pre_car_col_direction.v[0];*/
                if (modified_location_1 == eImpact_front && modified_location_2 == eImpact_front && pCar1->pre_car_col_speed > 0.001f && pCar2->pre_car_col_speed > 0.001f && dp < -0.7f) {
                    head_on = 1;
                    bonus_level = 2;
                }
                else {
                    bonus_level = 1;
                }
            }
            else if (car_2_culpable) {
                culprit = pCar2;
                victim = pCar1;
                // dp = pCar1->pre_car_col_direction.v[2] * pCar2->pre_car_col_direction.v[2]
                //     + pCar2->pre_car_col_direction.v[1] * pCar1->pre_car_col_direction.v[1]
                //     + pCar2->pre_car_col_direction.v[0] * pCar1->pre_car_col_direction.v[0];
                dp = BrVector3Dot(&pCar1->pre_car_col_direction, &pCar1->pre_car_col_direction);
                if (modified_location_1 == eImpact_front && modified_location_2 == eImpact_front && pCar1->pre_car_col_speed > 0.001f && pCar2->pre_car_col_speed > 0.001f && dp < -0.7f) {
                    head_on = 1;
                    bonus_level = 2;
                }
                else {
                    bonus_level = 1;
                }
            }
        }
    }
    else {
        // LOG_DEBUG("no pCar2, timediff is %d", the_time - pCar1->time_last_hit);
        if (the_time - pCar1->time_last_hit >= 3000) {
            return 1;
        }
        culprit = pCar1->last_hit_by;
        victim = pCar1;
        bonus_level = 1;
        inherited_damage = 1;
    }
    if (!mutual_culpability && (!victim || culprit->driver < eDriver_net_human)) {
        if (pCar2 && pCar2->last_culprit == pCar1 && the_time - pCar2->time_last_victim < 750) {
            inherited_damage = 1;
            culprit = pCar1;
            victim = pCar2;
        }
        else if (pCar2 && pCar1->last_culprit == pCar2 && the_time - pCar1->time_last_victim < 750) {
            inherited_damage = 1;
            culprit = pCar2;
            victim = pCar1;
        }
        else if (!pCar2 && the_time - pCar1->time_last_victim < 750) {
            inherited_damage = 1;
            culprit = pCar1->last_culprit;
            victim = pCar1;
        }
    }
    if (culprit && victim) {
        RecordOpponentTwattageOccurrence(culprit, victim);
        total_units_of_damage = 0;
        for (i = 0; i < COUNT_OF(victim->damage_units); i++) {
            if (victim->damage_units[i].damage_level > victim->damage_units[i].last_level) {
                victim->damage_units[i].damage_level = (victim->damage_units[i].damage_level - victim->damage_units[i].last_level) * 2.0f + victim->damage_units[i].last_level;
                if (victim->damage_units[i].damage_level >= 99) {
                    victim->damage_units[i].damage_level = 99;
                }
                total_units_of_damage += victim->damage_units[i].damage_level - victim->damage_units[i].last_level;
            }
            if (culprit->damage_units[i].damage_level > culprit->damage_units[i].last_level) {
                culprit->damage_units[i].damage_level = (culprit->damage_units[i].damage_level - culprit->damage_units[i].last_level) * 0.1f + (double)culprit->damage_units[i].last_level;
                if (culprit->damage_units[i].damage_level < 0) {
                    culprit->damage_units[i].damage_level = 0;
                }
            }
        }
    }
    // TODO: tidy this up
    for (net_loop = 0; 2 - (mutual_culpability == 0) > net_loop; net_loop++) {
        if (mutual_culpability) {
            if (net_loop) {
                culprit = pCar1;
                victim = pCar2;
            }
            else {
                culprit = pCar2;
                victim = pCar1;
            }
            total_units_of_damage = 0;
            for (i = 0; i < COUNT_OF(victim->damage_units); i++) {
                if (victim->damage_units[i].damage_level > victim->damage_units[i].last_level) {
                    total_units_of_damage += victim->damage_units[i].damage_level - victim->damage_units[i].last_level;
                }
            }
        }
        if (culprit && (culprit->driver == eDriver_local_human || HV(gNet_mode)) && victim) {
            SetKnackeredFlag(victim);
            if (victim->knackered && !victim->pre_car_col_knackered) {
                victim->pre_car_col_knackered = 1;
                credits_squared = sqr(0.7f / victim->car_model_actors[victim->principal_car_actor].crush_data.softness_factor) * HV(gWasted_creds)[HV(gProgram_state).skill_level] + 50.0f;
                credits = 100 * (credits_squared / 100.0f);
                if (HV(gNet_mode)) {
                    message = NetBuildMessage(0x18u, 0);
                    message->contents.data.wasted.victim = NetPlayerFromCar(victim)->ID;
                    if (NetPlayerFromCar(culprit)) {
                        message->contents.data.wasted.culprit = NetPlayerFromCar(culprit)->ID;
                    }
                    else {
                        message->contents.data.wasted.culprit = -2;
                    }
                    //NetGuaranteedSendMessageToEverybody(gCurrent_net_game, message, NULL);
                    NetEarnCredits(NetPlayerFromCar(culprit), credits);
                }
                else {
                    PratcamEvent(32);
                    DoFancyHeadup(11);
                    credits_squared = sqr(0.7f / victim->car_model_actors[victim->principal_car_actor].crush_data.softness_factor) * HV(gWasted_creds)[HV(gProgram_state).skill_level] + 50.0f;
                    credits = 100 * (credits_squared / 100.0);
                    AwardTime(HV(gWasted_time)[HV(gProgram_state).skill_level]);
                    EarnCredits(credits);
                    if (victim->can_be_stolen && !HV(gOpponents)[victim->index].dead && ((PercentageChance(50) && HV(gSteal_ranks)[HV(gOpponents)[victim->index].strength_rating] >= HV(gProgram_state).rank) || victim->index == 4)) {
                        StealCar(victim);
                    }
                }
            }
            victim->time_last_hit = the_time;
            victim->last_hit_by = culprit;
            if (!inherited_damage) {
                victim->time_last_victim = the_time;
                victim->last_culprit = culprit;
            }
            if (victim && (fabs(victim->omega.v[0]) > 4.0f || fabs(victim->omega.v[1]) > 6.0f || fabs(victim->omega.v[2]) > 4.0f)) {
                bonus_level *= 2;
            }
            if (pCar1->number_of_wheels_on_ground) {
                car_off_ground_1 = 0;
            }
            else {
                // car_1_pos.v[0] = pCar1->car_master_actor->t.t.mat.m[3][0] / 6.9000001;
                // car_1_pos.v[1] = pCar1->car_master_actor->t.t.mat.m[3][1] / 6.9000001;
                // car_1_pos.v[2] = pCar1->car_master_actor->t.t.mat.m[3][2] / 6.9000001;
                BrVector3InvScale(&car_1_pos, &pCar1->car_master_actor->t.t.translate.t, WORLD_SCALE);
                BrMatrix34ApplyV(&car_1_offset, &pCar1->car_model_actors[pCar1->principal_car_actor].actor->t.t.translate.t, &pCar1->car_master_actor->t.t.mat);
                // car_1_pos.v[0] = car_1_offset.v[0] + car_1_pos.v[0];
                // car_1_pos.v[1] = car_1_offset.v[1] + car_1_pos.v[1];
                // car_1_pos.v[2] = car_1_offset.v[2] + car_1_pos.v[2];
                BrVector3Accumulate(&car_1_pos, &car_1_offset);
                car_1_pos.v[1] += 0.15f;
                car_1_height = FindYVerticallyBelow2(&car_1_pos);
                car_off_ground_1 = car_1_height > -100.0f
                                   && pCar1->car_model_actors[pCar1->principal_car_actor].actor->t.t.translate.t.v[1] * 4.0f <= car_1_pos.v[1] - car_1_height - 0.15f;
            }
            if (!pCar2 || pCar2->number_of_wheels_on_ground) {
                car_off_ground_2 = 0;
            }
            else {
                // car_2_pos.v[0] = pCar2->car_master_actor->t.t.mat.m[3][0] / 6.9000001;
                // car_2_pos.v[1] = pCar2->car_master_actor->t.t.mat.m[3][1] / 6.9000001;
                // car_2_pos.v[2] = pCar2->car_master_actor->t.t.mat.m[3][2] / 6.9000001;
                BrVector3InvScale(&car_2_pos, &pCar2->car_master_actor->t.t.translate.t, WORLD_SCALE);
                BrMatrix34ApplyV(&car_2_offset, &pCar2->car_model_actors[pCar2->principal_car_actor].actor->t.t.translate.t, &pCar2->car_master_actor->t.t.mat);
                // car_2_pos.v[0] = car_2_offset.v[0] + car_2_pos.v[0];
                // car_2_pos.v[1] = car_2_offset.v[1] + car_2_pos.v[1];
                // car_2_pos.v[2] = car_2_pos.v[2] + car_2_offset.v[2];
                BrVector3Accumulate(&car_2_pos, &car_2_offset);
                car_2_pos.v[1] += 0.15f;
                car_2_height = FindYVerticallyBelow2(&car_2_pos);
                car_off_ground_2 = car_2_height > -100.0f
                                   && pCar2->car_model_actors[pCar2->principal_car_actor].actor->t.t.translate.t.v[1] * 4.0f <= car_2_pos.v[1] - car_2_height - 0.15f;
            }
            if (car_off_ground_1) {
                bonus_level *= 2;
            }
            if (car_off_ground_2) {
                bonus_level *= 2;
            }
            total_units_of_damage = 0.7f / victim->car_model_actors[victim->principal_car_actor].crush_data.softness_factor * total_units_of_damage;
            if (!victim->has_been_stolen) {
                credits = 100 * (HV(gCar_cred_value)[HV(gProgram_state).skill_level] * MIN(bonus_level, 8) * total_units_of_damage + 50.0f) / 100.0f;
                if (credits || victim->knackered) {
                    if (!victim->knackered) {
                        if (HV(gNet_mode)) {
                            NetEarnCredits(NetPlayerFromCar(culprit), MIN(credits, 2000));
                        }
                        else {
                            EarnCredits(MIN(credits, 2000));
                        }
                        last_earn_time = the_time;
                        if (HV(gNet_mode) == eNet_mode_none) {
                            time = 5 * ((total_units_of_damage * HV(gCar_time_value)[HV(gProgram_state).skill_level] + 2.5f) / 5.0f);
                            AwardTime(MIN(time, 90));
                            if (pCar2) {
                                if (head_on) {
                                    DoFancyHeadup(10);
                                }
                                else if (bonus_level <= 2) {
                                    if (bonus_level > 1) {
                                        DoFancyHeadup(2);
                                    }
                                }
                                else {
                                    DoFancyHeadup(3);
                                }
                            }
                        }
                    }
                    for (i = 0; i < COUNT_OF(victim->damage_units); i++) {
                        victim->damage_units[i].last_level = victim->damage_units[i].damage_level;
                    }
                }
            }
        }
        else {
            pCar1->time_last_hit = 0;
            if (pCar2) {
                pCar2->time_last_hit = 0;
            }
        }
    }
    pCar1->damage_magnitude_accumulator = 0.0f;
    if (pCar2) {
        pCar2->damage_magnitude_accumulator = 0.0f;
    }
    return 1;

    // return dam_acc_1 || pCar2 && dam_acc_2;
}

static void(*original_DoWheelDamage)(tU32, ...) = (void(*)(tU32, ...))0x004bf96c;
CARM95_HOOK_FUNCTION(original_DoWheelDamage, DoWheelDamage)
void DoWheelDamage(tU32 pFrame_period) {
    int i;
    int j;
    int damage;
    tCar_spec *car;
    br_scalar y_amount;
    br_scalar z_amount;
    br_scalar wheel_circum;
    br_scalar old_offset;
    br_vector3 temp_vector;
    br_vector3 wonky_vector;
    static int kev_index[4];
    LOG_TRACE("(%u)", pFrame_period);

    (void)pFrame_period;
    (void)i;
    (void)j;
    (void)damage;
    (void)car;
    (void)y_amount;
    (void)z_amount;
    (void)wheel_circum;
    (void)old_offset;
    (void)temp_vector;
    (void)wonky_vector;
    (void)kev_index;

    original_DoWheelDamage(pFrame_period);
}

static void(*original_CrashEarnings)(tCar_spec *, tCar_spec *, ...) = (void(*)(tCar_spec *, tCar_spec *, ...))0x004bfd78;
CARM95_HOOK_FUNCTION(original_CrashEarnings, CrashEarnings)
void CrashEarnings(tCar_spec *pCar1, tCar_spec *pCar2) {
    LOG_TRACE("(%p, %p)", pCar1, pCar2);

    (void)pCar1;
    (void)pCar2;

    original_CrashEarnings(pCar1, pCar2);
}

