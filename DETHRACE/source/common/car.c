#include "car.h"


#include "car.h"
#include "brender/brender.h"
#include "brucetrk.h"
#include "car.h"
#include "constants.h"
#include "controls.h"
#include "crush.h"
#include "displays.h"
#include "finteray.h"
#include "globvars.h"
#include "globvrkm.h"
#include "globvrme.h"
#include "globvrpb.h"
#include "graphics.h"
//#include "harness/config.h"
//#include "harness/trace.h"
#include "netgame.h"
#include "network.h"
#include "oil.h"
#include "opponent.h"
#include "pc-dos/dossys.h"
#include "piping.h"
#include "pratcam.h"
#include "raycast.h"
#include "replay.h"
#include "skidmark.h"
#include "sound.h"
#include "spark.h"
#include "trig.h"
#include "utility.h"
#include "world.h"

#include "harness/trace.h"

#include "carm95_hooks.h"

#include "carm95_webserver.h"

#include <assert.h>
#include <math.h>
#include <stdlib.h>

int * hookvar_gDoing_physics  = (void*)0x00514cb0;
br_scalar * hookvar_gDt  = (void*)0x00514cb4;
 // Suffix added to avoid duplicate symbol
int * hookvar_gCollision_detection_on__car  = (void*)0x00514cb8;
 // Suffix added to avoid duplicate symbol
br_vector3 * hookvar_gGround_normal__car  = (void*)0x00514cc0;
void(*(* hookvar_ControlCar)[6])(tCar_spec *, br_scalar) = (void*)0x00514cd0;
 // Suffix added to avoid duplicate symbol
int * hookvar_gControl__car  = (void*)0x00514ce8;
 // Suffix added to avoid duplicate symbol
int * hookvar_gFace_num__car  = (void*)0x00514df8;
 // Suffix added to avoid duplicate symbol
br_angle * hookvar_gOld_yaw__car  = (void*)0x00514cf0;
br_angle * hookvar_gOld_zoom  = (void*)0x00514cf4;
br_vector3 * hookvar_gCamera_pos_before_collide  = (void*)0x00514cf8;
 // Suffix added to avoid duplicate symbol
int(* hookvar_gMetal_crunch_sound_id__car )[5] = (void*)0x00514d08;
 // Suffix added to avoid duplicate symbol
int(* hookvar_gMetal_scrape_sound_id__car )[3] = (void*)0x00514d20;
int * hookvar_gCar_car_collisions  = (void*)0x00514d2c;
int * hookvar_gFreeze_mechanics  = (void*)0x00514d30;
tU32 * hookvar_gLast_cunning_stunt  = (void*)0x00514d34;
tU32 * hookvar_gWild_start  = (void*)0x00514d38;
tU32 * hookvar_gQuite_wild_start  = (void*)0x00514d3c;
tU32 * hookvar_gQuite_wild_end  = (void*)0x00514d40;
tU32 * hookvar_gOn_me_wheels_start  = (void*)0x00514d44;
int * hookvar_gWoz_upside_down_at_all  = (void*)0x00514d48;
tS3_sound_tag(* hookvar_gSkid_tag )[2] = (void*)0x00514d50;
tCar_spec *(* hookvar_gLast_car_to_skid )[2] = (void*)0x00514d58;
int * hookvar_gEliminate_faces  = (void*)0x00514d60;
 // Suffix added to avoid duplicate symbol
br_vector3 * hookvar_gZero_v__car  = (void*)0x00514d68;
tU32 * hookvar_gSwitch_time  = (void*)0x00514d74;
tSave_camera(* hookvar_gSave_camera )[2] = (void*)0x00514d78;
tU32 * hookvar_gLast_mechanics_time  = (void*)0x00514d90;
int * hookvar_gOpponent_viewing_mode  = (void*)0x00514d94;
int * hookvar_gNet_player_to_view_index  = (void*)0x00514d98;
int * hookvar_gDouble_pling_water  = (void*)0x00514d9c;
int * hookvar_gStop_opponents_moving  = (void*)0x00514da0;
float(* hookvar_gDefensive_powerup_factor )[6] = (void*)0x00514da8;
float(* hookvar_gOffensive_powerup_factor )[6] = (void*)0x00514dc0;
float(* hookvar_gEngine_powerup_factor )[6] = (void*)0x00514dd8;
#if 0
br_angle * hookvar_gPanning_camera_angle ;
#endif
#if 0
br_scalar * hookvar_gPanning_camera_height ;
#endif
int * hookvar_gFace_count  = (void*)0x00514cec;
float(* hookvar_gCar_simplification_factor )[2][5] = (void*)0x00514e00;
int * hookvar_gCar_simplification_level  = (void*)0x00514e28;
int * hookvar_gNum_active_non_cars  = (void*)0x00514e2c;
int * hookvar_gCamera_has_collided  = (void*)0x00514e30;
 // Suffix added to avoid duplicate symbol
tFace_ref(* hookvar_gFace_list__car )[150] = (void*)0x0053a5b8;
tNon_car_spec *(* hookvar_gActive_non_car_list )[50] = (void*)0x00550680;
int * hookvar_gOver_shoot  = (void*)0x0053a57c;
br_scalar * hookvar_gMin_world_y  = (void*)0x0053a574;
#if 0
br_scalar * hookvar_gAccel ;
#endif
br_vector3 * hookvar_gAverage_grid_position  = (void*)0x0053a518;
br_actor ** hookvar_gPed_actor  = (void*)0x0053cfe8;
#if 0
int * hookvar_gCollision_count ;
#endif
int * hookvar_gCamera_frozen  = (void*)0x0053d000;
int * hookvar_gMaterial_index  = (void*)0x0053a584;
int * hookvar_gInTheSea  = (void*)0x0053a578;
int * hookvar_gCamera_mode  = (void*)0x0053a524;
 // Suffix added to avoid duplicate symbol
#if 0
br_scalar * hookvar_gOur_yaw__car ;
#endif
 // Suffix added to avoid duplicate symbol
#if 0
br_scalar * hookvar_gGravity__car ;
#endif
 // Suffix added to avoid duplicate symbol
#if 0
br_vector3 * hookvar_gNew_ground_normal__car ;
#endif
char(* hookvar_gNon_car_spec_list )[100] = (void*)0x00550750;
tU32 * hookvar_gMechanics_time_sync  = (void*)0x00550670;
int * hookvar_gNum_cars_and_non_cars  = (void*)0x00550748;

#define HARNESS_GAME_CONFIG_PHYSICS_STEP_TIME 40

function_hook_state_t function_hook_state_DamageUnit = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(function_hook_state_DamageUnit)
static void(__cdecl*original_DamageUnit)(tCar_spec *, int, int) = (void(__cdecl*)(tCar_spec *, int, int))0x004751c0;
CARM95_HOOK_FUNCTION(original_DamageUnit, DamageUnit)
void __cdecl DamageUnit(tCar_spec *pCar, int pUnit_type, int pDamage_amount) {
    tDamage_unit *the_damage;
    LOG_TRACE("(%p, %d, %d)", pCar, pUnit_type, pDamage_amount);

    (void)pCar;
    (void)pUnit_type;
    (void)pDamage_amount;
    (void)the_damage;

    if (function_hook_state_DamageUnit == HOOK_ENABLED) {
        if (pDamage_amount > 0) {
            the_damage = &pCar->damage_units[pUnit_type];
            the_damage->damage_level += pDamage_amount;
            if (the_damage->damage_level >= 100) {
                the_damage->damage_level = 99;
            }
        }
    } else {
        original_DamageUnit(pCar, pUnit_type, pDamage_amount);
    }
}

function_hook_state_t function_hook_state_DamageUnitWithSmoke = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(function_hook_state_DamageUnitWithSmoke)
static void(__cdecl*original_DamageUnitWithSmoke)(tCar_spec *, int, int) = (void(__cdecl*)(tCar_spec *, int, int))0x00475239;
CARM95_HOOK_FUNCTION(original_DamageUnitWithSmoke, DamageUnitWithSmoke)
void __cdecl DamageUnitWithSmoke(tCar_spec *pCar, int pUnit_type, int pDamage_amount) {
    LOG_TRACE("(%p, %d, %d)", pCar, pUnit_type, pDamage_amount);

    (void)pCar;
    (void)pUnit_type;
    (void)pDamage_amount;

    if (function_hook_state_DamageUnitWithSmoke == HOOK_ENABLED) {
        DamageUnit(pCar, pUnit_type, pDamage_amount);
        SortOutSmoke(pCar);
    } else {
        original_DamageUnitWithSmoke(pCar, pUnit_type, pDamage_amount);
    }
}

function_hook_state_t function_hook_state_DamageEngine = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(function_hook_state_DamageEngine)
static void(__cdecl*original_DamageEngine)(int) = (void(__cdecl*)(int))0x00475215;
CARM95_HOOK_FUNCTION(original_DamageEngine, DamageEngine)
void __cdecl DamageEngine(int pDamage_amount) {
    LOG_TRACE("(%d)", pDamage_amount);

    (void)pDamage_amount;

    if (function_hook_state_DamageEngine == HOOK_ENABLED) {
        DamageUnitWithSmoke(&HV(gProgram_state).current_car, eDamage_engine, pDamage_amount);
    } else {
        original_DamageEngine(pDamage_amount);
    }
}

function_hook_state_t function_hook_state_DamageTrans = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(function_hook_state_DamageTrans)
static void(__cdecl*original_DamageTrans)(int) = (void(__cdecl*)(int))0x00475264;
CARM95_HOOK_FUNCTION(original_DamageTrans, DamageTrans)
void __cdecl DamageTrans(int pDamage_amount) {
    LOG_TRACE("(%d)", pDamage_amount);

    (void)pDamage_amount;

    if (function_hook_state_DamageTrans == HOOK_ENABLED) {
        DamageUnitWithSmoke(&HV(gProgram_state).current_car, eDamage_transmission, pDamage_amount);
    } else {
        original_DamageTrans(pDamage_amount);
    }
}

function_hook_state_t function_hook_state_DamageSteering = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(function_hook_state_DamageSteering)
static void(__cdecl*original_DamageSteering)(int) = (void(__cdecl*)(int))0x00475288;
CARM95_HOOK_FUNCTION(original_DamageSteering, DamageSteering)
void __cdecl DamageSteering(int pDamage_amount) {
    LOG_TRACE("(%d)", pDamage_amount);

    (void)pDamage_amount;

    if (function_hook_state_DamageSteering == HOOK_ENABLED) {
        DamageUnitWithSmoke(&HV(gProgram_state).current_car, eDamage_steering, pDamage_amount);
    } else {
        original_DamageSteering(pDamage_amount);
    }
}

function_hook_state_t function_hook_state_DamageLFWheel = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(function_hook_state_DamageLFWheel)
static void(__cdecl*original_DamageLFWheel)(int) = (void(__cdecl*)(int))0x004752ac;
CARM95_HOOK_FUNCTION(original_DamageLFWheel, DamageLFWheel)
void __cdecl DamageLFWheel(int pDamage_amount) {
    LOG_TRACE("(%d)", pDamage_amount);

    (void)pDamage_amount;

    if (function_hook_state_DamageLFWheel == HOOK_ENABLED) {
        DamageUnitWithSmoke(&HV(gProgram_state).current_car, eDamage_lf_wheel, pDamage_amount);;
    } else {
        original_DamageLFWheel(pDamage_amount);
    }
}

function_hook_state_t function_hook_state_DamageLFBrake = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(function_hook_state_DamageLFBrake)
static void(__cdecl*original_DamageLFBrake)(int) = (void(__cdecl*)(int))0x004752d0;
CARM95_HOOK_FUNCTION(original_DamageLFBrake, DamageLFBrake)
void __cdecl DamageLFBrake(int pDamage_amount) {
    LOG_TRACE("(%d)", pDamage_amount);

    (void)pDamage_amount;

    if (function_hook_state_DamageLFBrake == HOOK_ENABLED) {
        DamageUnitWithSmoke(&HV(gProgram_state).current_car, eDamage_lf_brake, pDamage_amount);
    } else {
        original_DamageLFBrake(pDamage_amount);
    }
}

function_hook_state_t function_hook_state_DamageLRBrake = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(function_hook_state_DamageLRBrake)
static void(__cdecl*original_DamageLRBrake)(int) = (void(__cdecl*)(int))0x004752f4;
CARM95_HOOK_FUNCTION(original_DamageLRBrake, DamageLRBrake)
void __cdecl DamageLRBrake(int pDamage_amount) {
    LOG_TRACE("(%d)", pDamage_amount);

    (void)pDamage_amount;

    if (function_hook_state_DamageLRBrake == HOOK_ENABLED) {
        DamageUnitWithSmoke(&HV(gProgram_state).current_car, eDamage_lr_brake, pDamage_amount);
    } else {
        original_DamageLRBrake(pDamage_amount);
    }
}

function_hook_state_t function_hook_state_DamageLRWheel = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(function_hook_state_DamageLRWheel)
static void(__cdecl*original_DamageLRWheel)(int) = (void(__cdecl*)(int))0x00475318;
CARM95_HOOK_FUNCTION(original_DamageLRWheel, DamageLRWheel)
void __cdecl DamageLRWheel(int pDamage_amount) {
    LOG_TRACE("(%d)", pDamage_amount);

    (void)pDamage_amount;

    if (function_hook_state_DamageLRWheel == HOOK_ENABLED) {
        DamageUnitWithSmoke(&HV(gProgram_state).current_car, eDamage_lr_wheel, pDamage_amount);
    } else {
        original_DamageLRWheel(pDamage_amount);
    }
}

function_hook_state_t function_hook_state_DamageRFWheel = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(function_hook_state_DamageRFWheel)
static void(__cdecl*original_DamageRFWheel)(int) = (void(__cdecl*)(int))0x0047533c;
CARM95_HOOK_FUNCTION(original_DamageRFWheel, DamageRFWheel)
void __cdecl DamageRFWheel(int pDamage_amount) {
    LOG_TRACE("(%d)", pDamage_amount);

    (void)pDamage_amount;

    if (function_hook_state_DamageRFWheel == HOOK_ENABLED) {
        DamageUnitWithSmoke(&HV(gProgram_state).current_car, eDamage_rf_wheel, pDamage_amount);
    } else {
        original_DamageRFWheel(pDamage_amount);
    }
}

function_hook_state_t function_hook_state_DamageRFBrake = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(function_hook_state_DamageRFBrake)
static void(__cdecl*original_DamageRFBrake)(int) = (void(__cdecl*)(int))0x00475360;
CARM95_HOOK_FUNCTION(original_DamageRFBrake, DamageRFBrake)
void __cdecl DamageRFBrake(int pDamage_amount) {
    LOG_TRACE("(%d)", pDamage_amount);

    (void)pDamage_amount;

    if (function_hook_state_DamageRFBrake == HOOK_ENABLED) {
        DamageUnitWithSmoke(&HV(gProgram_state).current_car, eDamage_rf_brake, pDamage_amount);
    } else {
        original_DamageRFBrake(pDamage_amount);
    }
}

function_hook_state_t function_hook_state_DamageRRBrake = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(function_hook_state_DamageRRBrake)
static void(__cdecl*original_DamageRRBrake)(int) = (void(__cdecl*)(int))0x00475384;
CARM95_HOOK_FUNCTION(original_DamageRRBrake, DamageRRBrake)
void __cdecl DamageRRBrake(int pDamage_amount) {
    LOG_TRACE("(%d)", pDamage_amount);

    (void)pDamage_amount;

    if (function_hook_state_DamageRRBrake == HOOK_ENABLED) {
        DamageUnitWithSmoke(&HV(gProgram_state).current_car, eDamage_rr_brake, pDamage_amount);
    } else {
        original_DamageRRBrake(pDamage_amount);
    }
}

function_hook_state_t function_hook_state_DamageRRWheel = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(function_hook_state_DamageRRWheel)
static void(__cdecl*original_DamageRRWheel)(int) = (void(__cdecl*)(int))0x004753a8;
CARM95_HOOK_FUNCTION(original_DamageRRWheel, DamageRRWheel)
void __cdecl DamageRRWheel(int pDamage_amount) {
    LOG_TRACE("(%d)", pDamage_amount);

    (void)pDamage_amount;

    if (function_hook_state_DamageRRWheel == HOOK_ENABLED) {
        DamageUnitWithSmoke(&HV(gProgram_state).current_car, eDamage_rr_wheel, pDamage_amount);
    } else {
        original_DamageRRWheel(pDamage_amount);
    }
}

function_hook_state_t function_hook_state_CalculatePlaneNormal = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_CalculatePlaneNormal)
void CalculatePlaneNormal(br_vector3 *pP1, br_vector3 *pP2, br_vector3 *pP3, br_vector3 *pNormal) {
    br_vector3 p0;
    br_vector3 p1;
    br_vector3 cross_product;
    br_vector3 temp_vector;
    br_scalar __block0___scale;
    br_scalar __block1___scale;
    br_scalar __block2___scale;
    LOG_TRACE("(%p, %p, %p, %p)", pP1, pP2, pP3, pNormal);

    (void)pP1;
    (void)pP2;
    (void)pP3;
    (void)pNormal;
    (void)p0;
    (void)p1;
    (void)cross_product;
    (void)temp_vector;
    (void)__block0___scale;
    (void)__block1___scale;
    (void)__block2___scale;

    if (function_hook_state_CalculatePlaneNormal == HOOK_ENABLED) {
        assert(0 && "CalculatePlaneNormal not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}

function_hook_state_t function_hook_state_CalculateGroundNormal = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_CalculateGroundNormal)
void CalculateGroundNormal(br_model *pThe_model, int pFace_index) {
    LOG_TRACE("(%p, %d)", pThe_model, pFace_index);

    (void)pThe_model;
    (void)pFace_index;

    if (function_hook_state_CalculateGroundNormal == HOOK_ENABLED) {
        assert(0 && "CalculateGroundNormal not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}

function_hook_state_t function_hook_state_ChangeYCoordinate = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_ChangeYCoordinate)
void ChangeYCoordinate(br_scalar pNew_y, tU32 pTime_taken, br_model *pThe_model, int pFace_index) {
    br_scalar y_change;
    br_transform new_transform;
    br_vector3 side_window;
    LOG_TRACE("(%f, %u, %p, %d)", pNew_y, pTime_taken, pThe_model, pFace_index);

    (void)pNew_y;
    (void)pTime_taken;
    (void)pThe_model;
    (void)pFace_index;
    (void)y_change;
    (void)new_transform;
    (void)side_window;

    if (function_hook_state_ChangeYCoordinate == HOOK_ENABLED) {
        assert(0 && "ChangeYCoordinate not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}

function_hook_state_t function_hook_state_SwitchCarActor = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(function_hook_state_SwitchCarActor)
static void(__cdecl*original_SwitchCarActor)(tCar_spec *, int) = (void(__cdecl*)(tCar_spec *, int))0x004753cc;
CARM95_HOOK_FUNCTION(original_SwitchCarActor, SwitchCarActor)
void __cdecl SwitchCarActor(tCar_spec *pCar_spec, int pModel_index) {
    int i;
    LOG_TRACE("(%p, %d)", pCar_spec, pModel_index);

    (void)pCar_spec;
    (void)pModel_index;
    (void)i;

    if (function_hook_state_SwitchCarActor == HOOK_ENABLED) {
        for (i = 0; i < pCar_spec->car_actor_count; i++) {
            if (i == pModel_index) {
                pCar_spec->car_model_actors[i].actor->render_style = BR_RSTYLE_FACES;
            } else {
                pCar_spec->car_model_actors[i].actor->render_style = BR_RSTYLE_NONE;
            }
        }
        pCar_spec->current_car_actor = pModel_index;
    } else {
        original_SwitchCarActor(pCar_spec, pModel_index);
    }
}

function_hook_state_t function_hook_state_InitialiseCar2 = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(function_hook_state_InitialiseCar2)
static void(__cdecl*original_InitialiseCar2)(tCar_spec *, int) = (void(__cdecl*)(tCar_spec *, int))0x0047544b;
CARM95_HOOK_FUNCTION(original_InitialiseCar2, InitialiseCar2)
void __cdecl InitialiseCar2(tCar_spec *pCar, int pClear_disabled_flag) {
    int index;
    int j;
    int cat;
    int car_count;
    br_actor *car_actor;
    br_angle initial_yaw;
    br_scalar nearest_y_above;
    br_scalar nearest_y_below;
    br_scalar speed;
    int below_face_index;
    int above_face_index;
    br_model *below_model;
    br_model *above_model;
    br_vector3 grid_offset;
    br_matrix34 initial_yaw_matrix;
    br_matrix34 safe_position;
    LOG_TRACE("(%p, %d)", pCar, pClear_disabled_flag);

    (void)pCar;
    (void)pClear_disabled_flag;
    (void)index;
    (void)j;
    (void)cat;
    (void)car_count;
    (void)car_actor;
    (void)initial_yaw;
    (void)nearest_y_above;
    (void)nearest_y_below;
    (void)speed;
    (void)below_face_index;
    (void)above_face_index;
    (void)below_model;
    (void)above_model;
    (void)grid_offset;
    (void)initial_yaw_matrix;
    (void)safe_position;

    if (function_hook_state_InitialiseCar2 == HOOK_ENABLED) {
        PossibleService();
        if (pCar->disabled && pClear_disabled_flag) {
            EnableCar(pCar);
        }
        car_actor = pCar->car_master_actor;
        InitCarSkidStuff(pCar);
        if (pCar->current_car_actor >= 0) {
            pCar->car_model_actors[pCar->current_car_actor].actor->render_style = BR_RSTYLE_NONE;
        }
        SwitchCarActor(pCar, pCar->current_car_actor);
        if (strcmp(pCar->name, "STELLA.TXT") == 0) {
            pCar->proxy_ray_distance = 6.0f;
        } else {
            pCar->proxy_ray_distance = 0.0f;
        }
        pCar->last_special_volume = NULL;
        pCar->auto_special_volume = NULL;
        pCar->num_smoke_columns = 0;
        pCar->who_last_hit_me = NULL;
        pCar->screen_material_source = NULL;
        if (pCar->screen_material) {
            pCar->screen_material->colour_map = NULL;
            pCar->screen_material->index_shade = HV(gRender_shade_table);
            BrMaterialUpdate(pCar->screen_material, BR_MATU_ALL);
        }
        if (pCar->driver == eDriver_local_human) {
            ResetRecoveryVouchers();
        }
        BrVector3SetFloat(&pCar->v, 0.0f, 0.0f, 0.0f);
        BrVector3SetFloat(&pCar->omega, 0.0f, 0.0f, 0.0f);
        pCar->curvature = 0.0f;
        BrMatrix34Copy(&safe_position, &car_actor->t.t.mat);
        if (safe_position.m[3][0] > 500.0f) {
            safe_position.m[3][0] -= 1000.0f;
            safe_position.m[3][1] -= 1000.0f;
            safe_position.m[3][2] -= 1000.0f;
        }
        BrMatrix34Copy(&pCar->old_frame_mat, &safe_position);
        BrMatrix34Copy(&pCar->oldmat, &safe_position);
        pCar->oldmat.m[3][0] *= WORLD_SCALE;
        pCar->oldmat.m[3][1] *= WORLD_SCALE;
        pCar->oldmat.m[3][2] *= WORLD_SCALE;
        BrMatrix34ApplyP(&pCar->pos, &pCar->cmpos, &pCar->oldmat);
        pCar->pos.v[0] /= WORLD_SCALE;
        pCar->pos.v[1] /= WORLD_SCALE;
        pCar->pos.v[2] /= WORLD_SCALE;
        for (j = 0; j < COUNT_OF(pCar->oldd); j++) {
            pCar->oldd[j] = pCar->ride_height;
        }
        pCar->gear = 0;
        pCar->revs = 0.0;
        pCar->traction_control = 1;
        pCar->direction.v[0] = -car_actor->t.t.mat.m[2][0];
        pCar->direction.v[1] = -car_actor->t.t.mat.m[2][1];
        pCar->direction.v[2] = -car_actor->t.t.mat.m[2][2];
        for (j = 0; j < COUNT_OF(pCar->last_safe_positions); j++) {
            BrMatrix34Copy(&pCar->last_safe_positions[j], &safe_position);
        }
        pCar->message.type = 0;
        pCar->message.time = 0;
        pCar->dt = -1.0;
        pCar->last_car_car_collision = 1;
        pCar->time_to_recover = 0;
        pCar->repair_time = 0;

        switch (pCar->driver) {

            case eDriver_oppo:
                index = 0;
                for (j = 0; HV(gCurrent_race).number_of_racers > j; ++j) {
                    if (HV(gCurrent_race).opponent_list[j].car_spec->driver == eDriver_oppo) {
                        if (HV(gCurrent_race).opponent_list[j].car_spec == pCar) {
                            pCar->car_ID = index + 512;
                        }
                        index++;
                    }
                }
                break;

            case eDriver_net_human:
                index = 0;
                for (j = 0; HV(gCurrent_race).number_of_racers > j; ++j) {
                    if (HV(gCurrent_race).opponent_list[j].car_spec
                        && HV(gCurrent_race).opponent_list[j].car_spec->driver == eDriver_net_human) {
                        if (HV(gCurrent_race).opponent_list[j].car_spec == pCar) {
                            pCar->car_ID = index + 256;
                        }
                        index++;
                    }
                }
                break;

            case eDriver_local_human:
                pCar->car_ID = 0;
                break;

            default:
                LOG_WARN("Case %d not handled", pCar->driver);
                break;
        }
        PossibleService();
        pCar->box_face_ref = HV(gFace_num__car) - 2;
        pCar->doing_nothing_flag = 0;
        pCar->end_steering_damage_effect = 0;
        pCar->end_trans_damage_effect = 0;
        pCar->wheel_dam_offset[0] = 0.0;
        pCar->wheel_dam_offset[1] = 0.0;
        pCar->wheel_dam_offset[2] = 0.0;
        pCar->wheel_dam_offset[3] = 0.0;
        pCar->shadow_intersection_flags = 0;
        pCar->underwater_ability = 0;
        pCar->invulnerable = 0;
        pCar->wall_climber_mode = 0;
        pCar->grip_multiplier = 1.0;
        pCar->damage_multiplier = 1.0;
        pCar->collision_mass_multiplier = 1.0;
        pCar->engine_power_multiplier = 1.0;
        pCar->bounce_rate = 0.0;
        pCar->bounce_amount = 0.0;
        pCar->knackered = 0;
        TotallyRepairACar(pCar);
        SetCarSuspGiveAndHeight(pCar, 1.0, 1.0, 1.0, 0.0, 0.0);
        for (j = 0; j < 64; ++j) {
            pCar->powerups[j] = 0;
        }
        if (HV(gNet_mode)) {
            for (j = 0; j < 3; ++j) {
                pCar->power_up_levels[j] = 0;
            }
        }
    } else {
        original_InitialiseCar2(pCar, pClear_disabled_flag);
    }
}

function_hook_state_t function_hook_state_InitialiseCar = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(function_hook_state_InitialiseCar)
static void(__cdecl*original_InitialiseCar)(tCar_spec *) = (void(__cdecl*)(tCar_spec *))0x00475b63;
CARM95_HOOK_FUNCTION(original_InitialiseCar, InitialiseCar)
void __cdecl InitialiseCar(tCar_spec *pCar) {
    LOG_TRACE("(%p)", pCar);

    (void)pCar;

    if (function_hook_state_InitialiseCar == HOOK_ENABLED) {
        InitialiseCar2(pCar, 1);
    } else {
        original_InitialiseCar(pCar);
    }
}

function_hook_state_t function_hook_state_InitialiseCarsEtc = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(function_hook_state_InitialiseCarsEtc)
static void(__cdecl*original_InitialiseCarsEtc)(tRace_info *) = (void(__cdecl*)(tRace_info *))0x00475b7c;
CARM95_HOOK_FUNCTION(original_InitialiseCarsEtc, InitialiseCarsEtc)
void __cdecl InitialiseCarsEtc(tRace_info *pThe_race) {
    int i;
    int cat;
    int car_count;
    tCar_spec *car;
    br_bounds bnds;
    LOG_TRACE("(%p)", pThe_race);

    (void)pThe_race;
    (void)i;
    (void)cat;
    (void)car_count;
    (void)car;
    (void)bnds;

    if (function_hook_state_InitialiseCarsEtc == HOOK_ENABLED) {
        HV(gProgram_state).initial_position = pThe_race->initial_position;
        HV(gProgram_state).initial_yaw = pThe_race->initial_yaw;
        BrActorToBounds(&bnds, HV(gProgram_state).track_spec.the_actor);
        HV(gMin_world_y) = bnds.min.v[1];
        HV(gNum_active_non_cars) = 0;
        for (cat = eVehicle_self; cat <= eVehicle_not_really; ++cat) {
            if (cat) {
                car_count = GetCarCount(cat);
            } else {
                car_count = 1;
            }
            for (i = 0; car_count > i; i++) {
                PossibleService();
                if (cat) {
                    car = GetCarSpec(cat, i);
                } else {
                    car = &HV(gProgram_state).current_car;
                }
                if (cat != eVehicle_not_really) {
                    InitialiseCar(car);
                }
            }
        }
        HV(gCamera_yaw) = 0;
        InitialiseExternalCamera();
        HV(gLast_mechanics_time) = 0;
    } else {
        original_InitialiseCarsEtc(pThe_race);
    }
}

function_hook_state_t function_hook_state_GetAverageGridPosition = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(function_hook_state_GetAverageGridPosition)
static void(__cdecl*original_GetAverageGridPosition)(tRace_info *) = (void(__cdecl*)(tRace_info *))0x00475ca4;
CARM95_HOOK_FUNCTION(original_GetAverageGridPosition, GetAverageGridPosition)
void __cdecl GetAverageGridPosition(tRace_info *pThe_race) {
    int i;
    br_scalar total_cars;
    tCar_spec *car;
    LOG_TRACE("(%p)", pThe_race);

    (void)pThe_race;
    (void)i;
    (void)total_cars;
    (void)car;

    if (function_hook_state_GetAverageGridPosition == HOOK_ENABLED) {
        total_cars = 0.0f;
        BrVector3SetFloat(&HV(gAverage_grid_position), 0.0f, 0.0f, 0.0f);
        for (i = 0; i < pThe_race->number_of_racers; i++) {
            car = pThe_race->opponent_list[i].car_spec;
            BrVector3Accumulate(&HV(gAverage_grid_position), &car->pos);
            total_cars += 1.0f;
        }
        BrVector3InvScale(&HV(gAverage_grid_position), &HV(gAverage_grid_position), total_cars);
    } else {
        original_GetAverageGridPosition(pThe_race);
    }
}

function_hook_state_t function_hook_state_SetInitialPosition = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(function_hook_state_SetInitialPosition)
static void(__cdecl*original_SetInitialPosition)(tRace_info *, int, int) = (void(__cdecl*)(tRace_info *, int, int))0x00475d7d;
CARM95_HOOK_FUNCTION(original_SetInitialPosition, SetInitialPosition)
void __cdecl SetInitialPosition(tRace_info *pThe_race, int pCar_index, int pGrid_index) {
    int place_on_grid;
    int i;
    int start_i;
    int j;
    br_actor *car_actor;
    br_angle initial_yaw;
    br_scalar nearest_y_above;
    br_scalar nearest_y_below;
    br_scalar speed;
    int below_face_index;
    int above_face_index;
    br_model *below_model;
    br_model *above_model;
    tCar_spec *car;
    br_vector3 grid_offset;
    br_vector3 dist;
    br_vector3 real_pos;
    br_matrix34 initial_yaw_matrix;
    br_bounds bnds;
    LOG_TRACE("(%p, %d, %d)", pThe_race, pCar_index, pGrid_index);

    (void)pThe_race;
    (void)pCar_index;
    (void)pGrid_index;
    (void)place_on_grid;
    (void)i;
    (void)start_i;
    (void)j;
    (void)car_actor;
    (void)initial_yaw;
    (void)nearest_y_above;
    (void)nearest_y_below;
    (void)speed;
    (void)below_face_index;
    (void)above_face_index;
    (void)below_model;
    (void)above_model;
    (void)car;
    (void)grid_offset;
    (void)dist;
    (void)real_pos;
    (void)initial_yaw_matrix;
    (void)bnds;

    if (function_hook_state_SetInitialPosition == HOOK_ENABLED) {
        initial_yaw = 0;
        car_actor = pThe_race->opponent_list[pCar_index].car_spec->car_master_actor;
        car = pThe_race->opponent_list[pCar_index].car_spec;
        BrMatrix34Identity(&car_actor->t.t.mat);
        place_on_grid = 1;
        if (HV(gNet_mode) && !HV(gCurrent_net_game)->options.grid_start && pThe_race->number_of_net_start_points) {
            TELL_ME_IF_WE_PASS_THIS_WAY();
        }
        if (place_on_grid) {
            initial_yaw = (pThe_race->initial_yaw * 182.0444444444445);
            BrMatrix34RotateY(&initial_yaw_matrix, initial_yaw);
            grid_offset.v[0] = 0.0 - pGrid_index % 2;
            grid_offset.v[1] = 0.0;
            grid_offset.v[2] = (double)(pGrid_index / 2) * 2.0 + (double)(pGrid_index % 2) * 0.40000001;
            BrMatrix34ApplyV(&car_actor->t.t.translate.t, &grid_offset, &initial_yaw_matrix);
            BrVector3Accumulate(&car_actor->t.t.translate.t, &pThe_race->initial_position);
        }
        FindBestY(
                &car_actor->t.t.translate.t,
                HV(gTrack_actor),
                10.0,
                &nearest_y_above,
                &nearest_y_below,
                &above_model,
                &below_model,
                &above_face_index,
                &below_face_index);
        if (nearest_y_above == 30000.0) {
            if (nearest_y_below == -30000.0) {
                car_actor->t.t.translate.t.v[1] = 0.0;
            } else {
                car_actor->t.t.translate.t.v[1] = nearest_y_below;
            }
        } else {
            car_actor->t.t.translate.t.v[1] = nearest_y_above;
        }
        BrMatrix34PreRotateY(&car_actor->t.t.mat, initial_yaw);
        if (HV(gNet_mode)) {
            BrMatrix34Copy(
                    &HV(gNet_players)[pThe_race->opponent_list[pCar_index].net_player_index].initial_position,
                    &car->car_master_actor->t.t.mat);
        }
        if (HV(gNet_mode) && car->disabled && car_actor->t.t.translate.t.v[0] < 500.0) {
            DisableCar(car);
        }
    } else {
        original_SetInitialPosition(pThe_race, pCar_index, pGrid_index);
    }
}

function_hook_state_t function_hook_state_SetInitialPositions = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(function_hook_state_SetInitialPositions)
static void(__cdecl*original_SetInitialPositions)(tRace_info *) = (void(__cdecl*)(tRace_info *))0x00476279;
CARM95_HOOK_FUNCTION(original_SetInitialPositions, SetInitialPositions)
void __cdecl SetInitialPositions(tRace_info *pThe_race) {
    int i;
    LOG_TRACE("(%p)", pThe_race);

    (void)pThe_race;
    (void)i;

    if (function_hook_state_SetInitialPositions == HOOK_ENABLED) {
        for (i = 0; i < pThe_race->number_of_racers; i++) {
            SetInitialPosition(pThe_race, i, i);
        }
    } else {
        original_SetInitialPositions(pThe_race);
    }
}

function_hook_state_t function_hook_state_InitialiseNonCar = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(function_hook_state_InitialiseNonCar)
static void(__cdecl*original_InitialiseNonCar)(tNon_car_spec *) = (void(__cdecl*)(tNon_car_spec *))0x004762c1;
CARM95_HOOK_FUNCTION(original_InitialiseNonCar, InitialiseNonCar)
void __cdecl InitialiseNonCar(tNon_car_spec *non_car) {
    tCollision_info *c;
    LOG_TRACE("(%p)", non_car);

    (void)non_car;
    (void)c;

    if (function_hook_state_InitialiseNonCar == HOOK_ENABLED) {
        c = &non_car->collision_info;
        BrMatrix34Copy(&c->oldmat, &c->car_master_actor->t.t.mat);
        non_car->collision_info.box_face_ref = HV(gFace_num__car) - 2;
        non_car->collision_info.doing_nothing_flag = 1;
        non_car->collision_info.disabled = 0;
        BrVector3SetFloat(&c->v, 0.0f, 0.0f, 0.0f);
        BrVector3SetFloat(&c->omega, 0.0f, 0.0f, 0.0f);
        BrVector3SetFloat(&c->oldomega, 0.0f, 0.0f, 0.0f);
        non_car->collision_info.box_face_ref = HV(gFace_num__car) - 2;
        c->collision_flag = 0;
        c->who_last_hit_me = NULL;
        if (c->car_master_actor->identifier[3] == '!') {
            c->M = non_car->free_mass;
            c->min_torque_squared = 0.0f;
            c->cmpos = non_car->free_cmpos;
        } else {
            c->M = non_car->attached_mass;
            c->cmpos = non_car->attached_cmpos;
            c->min_torque_squared = non_car->min_torque_squared;
        }
        BrVector3Scale(&c->I, &non_car->I_over_M, c->M);
        c->message.type = 0;
        c->message.time = 0;
        c->dt = -1.0f;
        c->last_car_car_collision = 1;
    } else {
        original_InitialiseNonCar(non_car);
    }
}

function_hook_state_t function_hook_state_GetFacesInBox = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(function_hook_state_GetFacesInBox)
static void(__cdecl*original_GetFacesInBox)(tCollision_info *) = (void(__cdecl*)(tCollision_info *))0x004764ca;
CARM95_HOOK_FUNCTION(original_GetFacesInBox, GetFacesInBox)
void __cdecl GetFacesInBox(tCollision_info *c) {
    tBounds bnds;
    br_bounds new_in_old;
    br_bounds predicted_bounds;
    br_matrix34 mat;
    br_matrix34 mat2;
    br_matrix34 mat3;
    br_matrix34 mat4;
    br_matrix34 mat5;
    br_matrix34 mat6;
    br_scalar old_d;
    int i;
    br_bounds current_bounds;
    LOG_TRACE("(%p)", c);

    (void)c;
    (void)bnds;
    (void)new_in_old;
    (void)predicted_bounds;
    (void)mat;
    (void)mat2;
    (void)mat3;
    (void)mat4;
    (void)mat5;
    (void)mat6;
    (void)old_d;
    (void)i;
    (void)current_bounds;

    if (function_hook_state_GetFacesInBox == HOOK_ENABLED) {
        BrMatrix34Copy(&mat, &c->car_master_actor->t.t.mat);
        BrMatrix34Copy(&mat2, &c->oldmat);
        mat.m[3][0] = mat.m[3][0] / 6.9;
        mat.m[3][1] = mat.m[3][1] / 6.9;
        mat.m[3][2] = mat.m[3][2] / 6.9;
        mat2.m[3][0] = mat2.m[3][0] / 6.9;
        mat2.m[3][1] = mat2.m[3][1] / 6.9;
        mat2.m[3][2] = mat2.m[3][2] / 6.9;
        BrMatrix34LPInverse(&mat3, &mat);
        BrMatrix34Mul(&mat4, &mat2, &mat3);
        GetNewBoundingBox(&bnds.original_bounds, c->bounds, &mat4);
        for (i = 0; i < 3; ++i) {
            if (bnds.original_bounds.min.v[i] > c->bounds[0].min.v[i]) {
                bnds.original_bounds.min.v[i] = c->bounds[0].min.v[i];
            }
            if (bnds.original_bounds.max.v[i] < c->bounds[0].max.v[i]) {
                bnds.original_bounds.max.v[i] = c->bounds[0].max.v[i];
            }
            bnds.original_bounds.min.v[i] = bnds.original_bounds.min.v[i] - 0.0020000001;
            bnds.original_bounds.max.v[i] = bnds.original_bounds.max.v[i] + 0.0020000001;
        }
        GetNewBoundingBox(&c->bounds_world_space, &bnds.original_bounds, &mat);
        c->bounds_ws_type = eBounds_ws;
        if ((c->box_face_ref != HV(gFace_num__car) && (c->box_face_ref != HV(gFace_num__car) - 1 || c->box_face_start <= HV(gFace_count)))
            || (BrMatrix34Mul(&mat5, &mat, &c->last_box_inv_mat),
                GetNewBoundingBox(&new_in_old, &bnds.original_bounds, &mat5),
                c->last_box.max.v[0] <= new_in_old.max.v[0])
            || c->last_box.max.v[1] <= new_in_old.max.v[1]
            || c->last_box.max.v[2] <= new_in_old.max.v[2]
            || c->last_box.min.v[0] >= new_in_old.min.v[0]
            || c->last_box.min.v[1] >= new_in_old.min.v[1]
            || c->last_box.min.v[2] >= new_in_old.min.v[2]) {
            BrMatrix34Mul(&mat5, &mat4, &mat4);
            BrMatrix34Mul(&mat6, &mat5, &mat4);
            BrMatrix34LPInverse(&mat5, &mat6);
            GetNewBoundingBox(&predicted_bounds, c->bounds, &mat5);
            for (i = 0; i < 3; ++i) {
                if (bnds.original_bounds.min.v[i] > predicted_bounds.min.v[i]) {
                    bnds.original_bounds.min.v[i] = predicted_bounds.min.v[i];
                }
                if (bnds.original_bounds.max.v[i] < predicted_bounds.max.v[i]) {
                    bnds.original_bounds.max.v[i] = predicted_bounds.max.v[i];
                }
                bnds.original_bounds.min.v[i] = bnds.original_bounds.min.v[i] - 0.02;
                bnds.original_bounds.max.v[i] = bnds.original_bounds.max.v[i] + 0.02;
            }
            c->last_box = bnds.original_bounds;
            BrMatrix34Copy(&c->last_box_inv_mat, &mat3);
            bnds.mat = &mat;
            c->box_face_start = HV(gFace_count);
            HV(gPling_face) = NULL;
            HV(gFace_count) += FindFacesInBox(&bnds, &HV(gFace_list__car)[HV(gFace_count)], 150 - HV(gFace_count));
            if (HV(gFace_count) >= 150) {
                c->box_face_start = 0;
                HV(gFace_count) = FindFacesInBox(&bnds, HV(gFace_list__car), 150);
                ++HV(gFace_num__car);
            }
            old_d = c->water_d;
            if (c->driver == eDriver_local_human
                && c->water_d != 10000.0
                && HV(gDouble_pling_water)
                && c->bounds_world_space.max.v[2] * c->water_normal.v[2] + c->bounds_world_space.max.v[1] * c->water_normal.v[1] + c->water_normal.v[0] * c->bounds_world_space.max.v[0] - c->water_d <= 0.0) {
                HV(gInTheSea) = 1;
                FreezeCamera();
            }
            if (HV(gPling_face) && fabs(HV(gPling_face)->normal.v[1]) > 0.89999998) {
                c->water_normal = HV(gPling_face)->normal;
                if (c->water_normal.v[1] < 0.0) {
                    BrVector3Negate(&c->water_normal, &c->water_normal);
                }
                c->water_d = HV(gPling_face)->v[0].v[1] * c->water_normal.v[1] + HV(gPling_face)->v[0].v[2] * c->water_normal.v[2] + HV(gPling_face)->v[0].v[0] * c->water_normal.v[0];
                if (c->driver == eDriver_local_human) {
                    if (HV(gPling_face)->material->identifier[1] == '!') {
                        if (BrVector3Dot(&c->bounds_world_space.min, &c->water_normal) - c->water_d < 0.0) {
                            GetNewBoundingBox(&current_bounds, &c->bounds[1], &c->car_master_actor->t.t.mat);
                            if (BrVector3Dot(&current_bounds.min, &c->water_normal) / 6.9 - c->water_d < 0.0) {
                                HV(gInTheSea) = 1;
                                FreezeCamera();
                            }
                        }
                        HV(gDouble_pling_water) = 1;
                    } else {
                        HV(gDouble_pling_water) = 0;
                    }
                }
            } else {
                c->water_d = 10000.0;
                if (c->driver == eDriver_local_human) {
                    if (HV(gInTheSea) == 1) {
                        HV(gInTheSea) = 2;
                    } else {
                        HV(gInTheSea) = 0;
                    }
                }
            }
            if (c->water_d != old_d) {
                StartPipingSession(ePipe_chunk_splash);
                AddSplashToPipingSession(c);
                EndPipingSession();
            }
            c->box_face_end = HV(gFace_count);
            c->box_face_ref = HV(gFace_num__car);
        }
    } else {
        original_GetFacesInBox(c);
    }
}

function_hook_state_t function_hook_state_IsCarInTheSea = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(function_hook_state_IsCarInTheSea)
static int(__cdecl*original_IsCarInTheSea)() = (int(__cdecl*)())0x00476cf4;
CARM95_HOOK_FUNCTION(original_IsCarInTheSea, IsCarInTheSea)
int __cdecl IsCarInTheSea() {
    LOG_TRACE("()");


    if (function_hook_state_IsCarInTheSea == HOOK_ENABLED) {
        return HV(gInTheSea);
    } else {
        return original_IsCarInTheSea();
    }
}

function_hook_state_t function_hook_state_RememberSafePosition = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(function_hook_state_RememberSafePosition)
static void(__cdecl*original_RememberSafePosition)(tCar_spec *, tU32) = (void(__cdecl*)(tCar_spec *, tU32))0x004771a2;
CARM95_HOOK_FUNCTION(original_RememberSafePosition, RememberSafePosition)
void __cdecl RememberSafePosition(tCar_spec *car, tU32 pTime) {
    static tU32 time_count;
    int j;
    br_vector3 r;
    br_scalar ts;
    LOG_TRACE("(%p, %u)", car, pTime);

    (void)car;
    (void)pTime;
    (void)time_count;
    (void)j;
    (void)r;
    (void)ts;

    if (function_hook_state_RememberSafePosition == HOOK_ENABLED) {
        if (car->disabled) {
            return;
        }
        time_count += pTime;
        if (time_count < 5000) {
            return;
        }
        time_count = 4000;
        for (j = 0; j < 4; j++) {
            if (car->susp_height[j >> 1] <= car->oldd[j]) {
                return;
            }
        }
        if ((!car->last_special_volume || car->last_special_volume->gravity_multiplier == 1.0)
            && HV(gCurrent_race).material_modifiers[car->material_index[0]].tyre_road_friction >= 0.1
            && HV(gCurrent_race).material_modifiers[car->material_index[1]].tyre_road_friction >= 0.1
            && HV(gCurrent_race).material_modifiers[car->material_index[2]].tyre_road_friction >= 0.1
            && HV(gCurrent_race).material_modifiers[car->material_index[3]].tyre_road_friction >= 0.1
            && car->car_master_actor->t.t.mat.m[1][1] >= 0.80000001) {

            for (j = 0; j < 5; j++) {
                r.v[0] = car->car_master_actor->t.t.mat.m[3][0] - car->last_safe_positions[j].m[3][0];
                r.v[1] = car->car_master_actor->t.t.mat.m[3][1] - car->last_safe_positions[j].m[3][1];
                r.v[2] = car->car_master_actor->t.t.mat.m[3][2] - car->last_safe_positions[j].m[3][2];

                if (BrVector3LengthSquared(&r) < 8.4015961) {
                    return;
                }
            }
            for (j = 3; j > 0; j--) {
                BrMatrix34Copy(&car->last_safe_positions[j], &car->last_safe_positions[j - 1]);
            }
            BrMatrix34Copy(&car->last_safe_positions[0], &car->car_master_actor->t.t.mat);
            time_count = 0;
        }
    } else {
        original_RememberSafePosition(car, pTime);
    }
}

function_hook_state_t function_hook_state_ControlOurCar = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(function_hook_state_ControlOurCar)
static void(__cdecl*original_ControlOurCar)(tU32) = (void(__cdecl*)(tU32))0x00476d09;
CARM95_HOOK_FUNCTION(original_ControlOurCar, ControlOurCar)
void __cdecl ControlOurCar(tU32 pTime_difference) {
    br_scalar ts;
    br_vector3 minus_k;
    tCar_spec *car;
    static int steering_locked;
    int i;
    tU32 time;
    LOG_TRACE("(%u)", pTime_difference);

    (void)pTime_difference;
    (void)ts;
    (void)minus_k;
    (void)car;
    (void)steering_locked;
    (void)i;
    (void)time;

    if (function_hook_state_ControlOurCar == HOOK_ENABLED) {
        car = &HV(gProgram_state).current_car;
        if (HV(gCar_flying)) {
            if (HV(gNet_mode)) {
                HV(gCar_flying) = 0;
            } else {
                car->car_master_actor->t.t.mat.m[3][0] = car->car_master_actor->t.t.mat.m[3][0] * WORLD_SCALE;
                car->car_master_actor->t.t.mat.m[3][1] = car->car_master_actor->t.t.mat.m[3][1] * WORLD_SCALE;
                car->car_master_actor->t.t.mat.m[3][2] = car->car_master_actor->t.t.mat.m[3][2] * WORLD_SCALE;
                ts = (double)pTime_difference / 1000.0;
                FlyCar(car, ts);
                car->car_master_actor->t.t.mat.m[3][0] = car->car_master_actor->t.t.mat.m[3][0] / WORLD_SCALE;
                car->car_master_actor->t.t.mat.m[3][1] = car->car_master_actor->t.t.mat.m[3][1] / WORLD_SCALE;
                car->car_master_actor->t.t.mat.m[3][2] = car->car_master_actor->t.t.mat.m[3][2] / WORLD_SCALE;
            }
            return;
        }
        time = GetTotalTime();
        if (car->damage_units[eDamage_steering].damage_level > 40) {
            if (car->end_steering_damage_effect) {
                if (car->end_steering_damage_effect > time || car->damage_units[eDamage_steering].damage_level == 99) {
                    car->keys.left = car->false_key_left;
                    car->keys.right = car->false_key_right;
                } else {
                    car->end_steering_damage_effect = 0;
                }
            } else {
                ts = pTime_difference * (car->damage_units[eDamage_steering].damage_level - 40) * 0.0045;
                if (PercentageChance(ts) && fabs(car->velocity_car_space.v[2]) > 0.0001) {
                    if (car->keys.left || car->keys.right) {
                        car->false_key_left = !car->keys.left;
                        car->false_key_right = !car->keys.right;
                    } else if (PercentageChance(50)) {
                        car->false_key_left = 1;
                    } else {
                        car->false_key_right = 1;
                    }
                    ts = 5 * (5 * car->damage_units[eDamage_steering].damage_level - 200);
                    car->end_steering_damage_effect = FRandomBetween(0.0, ts) + time;
                }
            }
        }
        if (car->damage_units[eDamage_transmission].damage_level > 40) {
            if (car->end_trans_damage_effect) {
                if (car->end_trans_damage_effect > time || car->damage_units[eDamage_transmission].damage_level == 99) {
                    car->gear = 0;
                    car->just_changed_gear = 1;
                } else {
                    car->end_trans_damage_effect = 0;
                }
            } else {
                ts = pTime_difference * (car->damage_units[eDamage_transmission].damage_level - 40);
                if (PercentageChance(ts) * 0.006 != 0) {
                    ts = 10 * (5 * car->damage_units[eDamage_transmission].damage_level - 200);
                    car->end_trans_damage_effect = FRandomBetween(0.0, ts) + time;
                }
            }
        }
        ts = (double)pTime_difference / 1000.0;
        HV(ControlCar)[HV(gControl__car)](car, ts);
        RememberSafePosition(car, pTime_difference);
        if (HV(gCamera_reset)) {
            BrVector3SetFloat(&minus_k, 0.0, 0.0, -1.0);
            HV(gCamera_sign) = 0;
            BrMatrix34ApplyV(&car->direction, &minus_k, &car->car_master_actor->t.t.mat);
        }
    } else {
        original_ControlOurCar(pTime_difference);
    }
}

function_hook_state_t function_hook_state_CalcEngineForce = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(function_hook_state_CalcEngineForce)
static void(__cdecl*original_CalcEngineForce)(tCar_spec *, br_scalar) = (void(__cdecl*)(tCar_spec *, br_scalar))0x00477433;
CARM95_HOOK_FUNCTION(original_CalcEngineForce, CalcEngineForce)
void __cdecl CalcEngineForce(tCar_spec *c, br_scalar dt) {
    br_scalar torque;
    br_scalar ts;
    br_scalar ts2;
    br_scalar brake_temp;
    int sign;
    tS32 temp_for_swap;
    LOG_TRACE("(%p, %f)", c, dt);

    (void)c;
    (void)dt;
    (void)torque;
    (void)ts;
    (void)ts2;
    (void)brake_temp;
    (void)sign;
    (void)temp_for_swap;

    if (function_hook_state_CalcEngineForce == HOOK_ENABLED) {
        c->acc_force = 0.0;
        if (c->revs == 0.0) {
            c->gear = 0;
        }
        sign = c->gear < 0 || (!c->gear && c->velocity_car_space.v[2] > 0.5);
        if (c->keys.backwards != sign) {
            c->keys.backwards = !c->keys.backwards;
            temp_for_swap = c->keys.acc;
            c->keys.acc = c->keys.dec;
            c->keys.dec = temp_for_swap;

            temp_for_swap = c->joystick.acc;
            c->joystick.acc = c->joystick.dec;
            c->joystick.dec = temp_for_swap;
        }
        if (!c->gear && !c->keys.acc && c->joystick.acc <= 0 && (c->keys.dec || c->joystick.dec > 0) && !c->keys.backwards && fabs(c->velocity_car_space.v[2]) < 1.0) {
            c->keys.backwards = 1;
            c->keys.acc = c->keys.dec;
            c->keys.dec = 0;
            temp_for_swap = c->joystick.acc;
            c->joystick.acc = c->joystick.dec;
            c->joystick.dec = temp_for_swap;
        }
        c->torque = -(c->revs * c->revs / 100000000.0) - 0.2;
        if (c->keys.acc || c->joystick.acc >= 0) {
            if (fabs(c->curvature) > c->maxcurve / 2.0 && c->gear < 2 && c->gear && c->traction_control) {
                ts = 0.69999999;
            } else if (c->joystick.acc < 0) {
                ts = 1.2;
            } else {
                ts = c->joystick.acc / 54613.0;
                LOG_PANIC("ooo");
            }

            torque = c->engine_power_multiplier * ts * HV(gEngine_powerup_factor)[c->power_up_levels[1]];
            if (c->damage_units[0].damage_level > 10) {
                torque = (1.0 - (double)(c->damage_units[0].damage_level - 10) / 100.0) * torque;
            }
            c->torque = c->torque + torque;
        } else {
            c->traction_control = 1;
        }
        if (!c->keys.dec && (!c->keys.acc || c->gear) && c->joystick.dec <= 0 && (c->joystick.acc <= 0 || c->gear)) {
            c->brake_force = 0.0;
        } else {
            if (c->joystick.dec > 0) {
                c->brake_force = (double)(c->joystick.dec / 0x10000) * c->brake_increase + c->initial_brake;
            }
            if (c->brake_force == 0.0) {
                c->brake_force = c->initial_brake;
            } else {
                c->brake_force = c->brake_increase * dt + c->brake_force;
                if (c->initial_brake + c->brake_increase < c->brake_force) {
                    c->brake_force = c->initial_brake + c->brake_increase;
                }
            }
        }
        if (c->gear) {
            c->acc_force = c->force_torque_ratio * c->torque / (double)c->gear;
            if (c->brake_force == 0.0) {
                if (c->revs - 1.0 > c->target_revs || c->revs + 1.0 < c->target_revs) {
                    ts2 = c->torque * dt / 0.0002 + c->revs - c->target_revs;
                    c->acc_force = ts2 / ((1.0 / (c->speed_revs_ratio * c->M) / (double)c->gear + 1.0 / (c->force_torque_ratio * 0.0002) * (double)c->gear) * dt) + c->acc_force;
                }
            } else {
                c->revs = c->target_revs;
            }
        }
    } else {
        original_CalcEngineForce(c, dt);
    }
}

function_hook_state_t function_hook_state_PrepareCars = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(function_hook_state_PrepareCars)
static void(__cdecl*original_PrepareCars)(tU32) = (void(__cdecl*)(tU32))0x00477b11;
CARM95_HOOK_FUNCTION(original_PrepareCars, PrepareCars)
void __cdecl PrepareCars(tU32 pFrame_start_time) {
    tCar_spec *car;
    int i;
    static tU32 last_frame_start;
    LOG_TRACE("(%u)", pFrame_start_time);

    (void)pFrame_start_time;
    (void)car;
    (void)i;
    (void)last_frame_start;

    if (function_hook_state_PrepareCars == HOOK_ENABLED) {
        last_frame_start = pFrame_start_time;
        for (i = 0; i < HV(gNum_cars_and_non_cars); i++) {
            car = HV(gActive_car_list)[i];
            car->car_master_actor->t.t.mat.m[3][0] = car->car_master_actor->t.t.mat.m[3][0] * WORLD_SCALE;
            car->car_master_actor->t.t.mat.m[3][1] = car->car_master_actor->t.t.mat.m[3][1] * WORLD_SCALE;
            car->car_master_actor->t.t.mat.m[3][2] = car->car_master_actor->t.t.mat.m[3][2] * WORLD_SCALE;
            car->velocity_car_space.v[0] = car->velocity_car_space.v[0] * WORLD_SCALE * 1000.0f;
            car->velocity_car_space.v[1] = car->velocity_car_space.v[1] * WORLD_SCALE * 1000.0f;
            car->velocity_car_space.v[2] = car->velocity_car_space.v[2] * WORLD_SCALE * 1000.0f;
            car->frame_collision_flag = HV(gOver_shoot) && car->collision_flag;
            if (car->driver > eDriver_non_car) {
                RecordLastDamage(car);
                if (car->driver == eDriver_oppo && HV(gStop_opponents_moving)) {
                    car->acc_force = 0.0;
                    car->brake_force = 0.0;
                    car->keys.acc = 0;
                    car->keys.dec = 0;
                    car->joystick.acc = -1;
                    car->joystick.dec = -1;
                }
                if (!car->wheel_slip) {
                    StopSkid(car);
                }
                if (car->driver == eDriver_net_human && car->message.time < pFrame_start_time - 1000) {
                    car->keys.acc = 0;
                    car->keys.dec = 0;
                    car->joystick.acc = -1;
                    car->joystick.dec = -1;
                    car->keys.horn = 0;
                }
                SetSmokeLastDamageLevel(car);
            }
            BrMatrix34Copy(&car->car_master_actor->t.t.mat, &car->oldmat);
        }
    } else {
        original_PrepareCars(pFrame_start_time);
    }
}

function_hook_state_t function_hook_state_FinishCars = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(function_hook_state_FinishCars)
static void(__cdecl*original_FinishCars)(tU32, tU32) = (void(__cdecl*)(tU32, tU32))0x00477d38;
CARM95_HOOK_FUNCTION(original_FinishCars, FinishCars)
void __cdecl FinishCars(tU32 pLast_frame_time, tU32 pTime) {
    tCar_spec *car;
    br_vector3 minus_k;
    int i;
    int wheel;
    br_scalar __block0___scale;
    br_scalar __block1___scale;
    LOG_TRACE("(%u, %u)", pLast_frame_time, pTime);

    (void)pLast_frame_time;
    (void)pTime;
    (void)car;
    (void)minus_k;
    (void)i;
    (void)wheel;
    (void)__block0___scale;
    (void)__block1___scale;

    if (function_hook_state_FinishCars == HOOK_ENABLED) {
        for (i = 0; i < HV(gNum_cars_and_non_cars); i++) {
            car = HV(gActive_car_list)[i];
            if (fabs(car->omega.v[0]) > 10000.0
                || fabs(car->omega.v[1]) > 10000.0
                || fabs(car->omega.v[2]) > 10000.0) {
                BrVector3SetFloat(&car->omega, 0.0, 0.0, 0.0);
                BrVector3SetFloat(&car->v, 0.0, 0.0, 0.0);
            }
            BrVector3InvScale(&car->velocity_car_space, &car->velocity_car_space, WORLD_SCALE * 1000.0f);
            car->car_master_actor->t.t.mat.m[3][0] = car->car_master_actor->t.t.mat.m[3][0] / WORLD_SCALE;
            car->car_master_actor->t.t.mat.m[3][1] = car->car_master_actor->t.t.mat.m[3][1] / WORLD_SCALE;
            car->car_master_actor->t.t.mat.m[3][2] = car->car_master_actor->t.t.mat.m[3][2] / WORLD_SCALE;

            car->speed = BR_LENGTH2(car->v.v[0], car->v.v[2]) / (WORLD_SCALE * 1000.0f);
            minus_k.v[0] = -car->car_master_actor->t.t.mat.m[2][0];
            minus_k.v[1] = -car->car_master_actor->t.t.mat.m[2][1];
            minus_k.v[2] = -car->car_master_actor->t.t.mat.m[2][2];
            if (car->speed <= 0.000099999997) {
                if (car->direction.v[1] * minus_k.v[1] + car->direction.v[2] * minus_k.v[2] + car->direction.v[0] * minus_k.v[0] < 0.0) {
                    BrVector3SetFloat(&minus_k, 0.0, 0.0, 1.0);
                } else {
                    BrVector3SetFloat(&minus_k, 0.0, 0.0, -1.0);
                }
                BrMatrix34ApplyV(&car->direction, &minus_k, &car->car_master_actor->t.t.mat);
            } else if (HV(gLast_mechanics_time) > pLast_frame_time && HV(gCar_to_view) == car) {
                BrVector3Sub(&car->old_v, &car->old_v, &car->v);
                BrVector3Scale(&car->old_v, &car->old_v, (HV(gLast_mechanics_time) - pLast_frame_time) / HARNESS_GAME_CONFIG_PHYSICS_STEP_TIME);
                BrVector3Accumulate(&car->old_v, &car->v);
                BrVector3Normalise(&car->direction, &car->old_v);
            } else {
                BrVector3Normalise(&car->direction, &car->v);
            }
            if (car->driver > eDriver_non_car) {
                car->speedo_speed = BrVector3Dot(&minus_k, &car->v) / (WORLD_SCALE * 1000.0f);

                car->steering_angle = d180_OVER_PI * atan((car->wpos[0].v[2] - car->wpos[2].v[2]) * car->curvature);

                car->lr_sus_position = (car->ride_height - car->oldd[0]) / WORLD_SCALE;
                car->rr_sus_position = (car->ride_height - car->oldd[1]) / WORLD_SCALE;
                car->lf_sus_position = (car->ride_height - car->oldd[2]) / WORLD_SCALE;
                car->rf_sus_position = (car->ride_height - car->oldd[3]) / WORLD_SCALE;
                for (wheel = 0; wheel < 4; wheel++) {
                    if (car->oldd[wheel] < car->susp_height[wheel >> 1] && HV(gCurrent_race).material_modifiers[car->material_index[wheel]].smoke_type >= 2 && !car->doing_nothing_flag) {
                        GenerateContinuousSmoke(car, wheel, pTime);
                    }
                }
            }
        }
    } else {
        original_FinishCars(pLast_frame_time, pTime);
    }
}

function_hook_state_t function_hook_state_InterpolateCars = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(function_hook_state_InterpolateCars)
static void(__cdecl*original_InterpolateCars)(tU32, tU32) = (void(__cdecl*)(tU32, tU32))0x00478928;
CARM95_HOOK_FUNCTION(original_InterpolateCars, InterpolateCars)
void __cdecl InterpolateCars(tU32 pLast_frame_time, tU32 pTime) {
    br_scalar dt;
    tCar_spec *car;
    int i;
    LOG_TRACE("(%u, %u)", pLast_frame_time, pTime);

    (void)pLast_frame_time;
    (void)pTime;
    (void)dt;
    (void)car;
    (void)i;

    if (function_hook_state_InterpolateCars == HOOK_ENABLED) {
        dt = ((int)(HV(gLast_mechanics_time) - pLast_frame_time)) / 1000.0;
        if (dt > 0.04 || dt < 0)
            dt = 0;

        HV(gOver_shoot) = dt > 0.0;

        for (i = 0; i < HV(gNum_cars_and_non_cars); i++) {
            car = HV(gActive_car_list)[i];
            BrMatrix34Copy(&car->oldmat, &car->car_master_actor->t.t.mat);
            SimpleRotate((tCollision_info*)car, -dt);
            TranslateCar((tCollision_info*)car, -dt);
            BrMatrix34ApplyP(&car->pos, &car->cmpos, &car->car_master_actor->t.t.mat);
            BrVector3InvScale(&car->pos, &car->pos, WORLD_SCALE);
        }
    } else {
        original_InterpolateCars(pLast_frame_time, pTime);
    }
}

function_hook_state_t function_hook_state_ResetOldmat = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(function_hook_state_ResetOldmat)
static void(__cdecl*original_ResetOldmat)() = (void(__cdecl*)())0x00478a88;
CARM95_HOOK_FUNCTION(original_ResetOldmat, ResetOldmat)
void __cdecl ResetOldmat() {
    tCar_spec *car;
    int i;
    br_matrix34 mat;
    static int normalise_count;
    LOG_TRACE("()");

    (void)car;
    (void)i;
    (void)mat;
    (void)normalise_count;

    if (function_hook_state_ResetOldmat == HOOK_ENABLED) {
        for (i = 0; i < HV(gNum_cars_and_non_cars); i++) {
            BrMatrix34Copy(&HV(gActive_car_list)[i]->oldmat, &HV(gActive_car_list)[i]->car_master_actor->t.t.mat);
        }
        normalise_count++;
        if (normalise_count > 50) {
            normalise_count = 0;
            for (i = 0; i < HV(gNum_cars_and_non_cars); i++) {
                car = HV(gActive_car_list)[i];
                BrMatrix34LPNormalise(&mat, &car->car_master_actor->t.t.mat);
                BrMatrix34Copy(&car->car_master_actor->t.t.mat, &mat);
            }
        }
    } else {
        original_ResetOldmat();
    }
}

function_hook_state_t function_hook_state_GetNonCars = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_GetNonCars)
static void(__cdecl*original_GetNonCars)() = (void(__cdecl*)())0x00478b58;
CARM95_HOOK_FUNCTION(original_GetNonCars, GetNonCars)
void __cdecl GetNonCars() {
    int i;
    int j;
    LOG_TRACE("()");

    (void)i;
    (void)j;

    if (function_hook_state_GetNonCars == HOOK_ENABLED) {
        assert(0 && "GetNonCars not implemented.");
        abort();
    } else {
        original_GetNonCars();
    }
}

function_hook_state_t function_hook_state_GetNetPos = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_GetNetPos)
static void(__cdecl*original_GetNetPos)(tCar_spec *) = (void(__cdecl*)(tCar_spec *))0x00478bb7;
CARM95_HOOK_FUNCTION(original_GetNetPos, GetNetPos)
void __cdecl GetNetPos(tCar_spec *pCar) {
    int j;
    float amount;
    br_scalar total_deflection;
    LOG_TRACE("(%p)", pCar);

    (void)pCar;
    (void)j;
    (void)amount;
    (void)total_deflection;

    if (function_hook_state_GetNetPos == HOOK_ENABLED) {
        assert(0 && "GetNetPos not implemented.");
        abort();
    } else {
        original_GetNetPos(pCar);
    }
}

function_hook_state_t function_hook_state_ApplyPhysicsToCars = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(function_hook_state_ApplyPhysicsToCars)
static void(__cdecl*original_ApplyPhysicsToCars)(tU32, tU32) = (void(__cdecl*)(tU32, tU32))0x0047839b;
CARM95_HOOK_FUNCTION(original_ApplyPhysicsToCars, ApplyPhysicsToCars)
void __cdecl ApplyPhysicsToCars(tU32 last_frame_time, tU32 pTime_difference) {
    br_vector3 minus_k;
    int i;
    int old_num_cars;
    int step_number;
    int dam_index;
    static int steering_locked;
    tCar_spec *car;
    tCollision_info *car_info;
    tNon_car_spec *non_car;
    tU32 time_step;
    tU32 frame_end_time;
    LOG_TRACE("(%u, %u)", last_frame_time, pTime_difference);

    (void)last_frame_time;
    (void)pTime_difference;
    (void)minus_k;
    (void)i;
    (void)old_num_cars;
    (void)step_number;
    (void)dam_index;
    (void)steering_locked;
    (void)car;
    (void)car_info;
    (void)non_car;
    (void)time_step;
    (void)frame_end_time;

    if (function_hook_state_ApplyPhysicsToCars == HOOK_ENABLED) {
        step_number = 0;
        frame_end_time = last_frame_time + pTime_difference;
        if (HV(gFreeze_mechanics)) {
            return;
        }
        if (HV(gNet_mode) == eNet_mode_client) {
            ForceRebuildActiveCarList();
        }
        if (HV(gLast_mechanics_time) < last_frame_time) {
            HV(gLast_mechanics_time) = HARNESS_GAME_CONFIG_PHYSICS_STEP_TIME * (last_frame_time / HARNESS_GAME_CONFIG_PHYSICS_STEP_TIME);
        }
        GetNonCars();
        if (frame_end_time <= HV(gLast_mechanics_time)) {
            PrepareCars(last_frame_time);
            InterpolateCars(frame_end_time, pTime_difference);
            FinishCars(frame_end_time, pTime_difference);
            return;
        }

        HV(gDoing_physics) = 1;
        PrepareCars(last_frame_time);
        HV(gDt) = HARNESS_GAME_CONFIG_PHYSICS_STEP_TIME / 1000.0; // 0.04;
        HV(gMechanics_time_sync) = pTime_difference - (HV(gLast_mechanics_time) - last_frame_time);
        while (HV(gLast_mechanics_time) < frame_end_time && step_number < 5) {
            step_number++;
            ResetOldmat();
            HV(gProgram_state).current_car.old_v = HV(gProgram_state).current_car.v;
            if (&HV(gProgram_state).current_car != HV(gCar_to_view)) {
                HV(gCar_to_view)->old_v.v[0] = HV(gCar_to_view)->v.v[0];
                HV(gCar_to_view)->old_v.v[1] = HV(gCar_to_view)->v.v[1];
                HV(gCar_to_view)->old_v.v[2] = HV(gCar_to_view)->v.v[2];
            }
            for (i = 0; HV(gNum_active_cars) > i; ++i) {
                car = HV(gActive_car_list)[i];
                car->dt = -1.0;
                if (car->message.type == 15 && car->message.time >= HV(gLast_mechanics_time) && HV(gLast_mechanics_time) + HARNESS_GAME_CONFIG_PHYSICS_STEP_TIME >= car->message.time) {
                    car->dt = (double)(HV(gLast_mechanics_time) + HARNESS_GAME_CONFIG_PHYSICS_STEP_TIME - car->message.time) / 1000.0;
                    if (HV(gDt) - 0.0001 <= car->dt) {
                        GetNetPos(car);
                    } else if (HV(gNet_mode) == eNet_mode_host) {
                        car->dt = -1.0;
                    } else {
                        for (dam_index = 0; dam_index < 12; ++dam_index) {
                            if (car->damage_units[dam_index].damage_level < car->message.damage[dam_index]) {
                                car->dt = -1.0;
                                break;
                            }
                        }
                        if (car->dt >= 0.0) {
                            GetNetPos(car);
                        }
                    }
                }
                if (!car->disabled
                    && (!car->doing_nothing_flag || (car->driver >= eDriver_net_human && (!HV(gPalette_fade_time) || car->driver != eDriver_local_human)))) {
                    if (car->box_face_ref != HV(gFace_num__car)
                        && (car->box_face_ref != HV(gFace_num__car) - 1 || car->box_face_start <= HV(gFace_count))) {
                        car_info = (tCollision_info*)car;
                        GetFacesInBox(car_info);
                    }
                    if (car->dt != 0.0) {
                        MoveAndCollideCar(car, HV(gDt));
                    }
                }
            }
            for (i = 0; i < HV(gNum_active_non_cars); i++) {
                non_car = HV(gActive_non_car_list)[i];
                if (!non_car->collision_info.doing_nothing_flag) {
                    non_car->collision_info.dt = -1.0;
                    if (non_car->collision_info.message.type == 16 && non_car->collision_info.message.time >= HV(gLast_mechanics_time) && HV(gLast_mechanics_time) + HARNESS_GAME_CONFIG_PHYSICS_STEP_TIME >= non_car->collision_info.message.time) {
                        non_car->collision_info.dt = (HV(gLast_mechanics_time) + HARNESS_GAME_CONFIG_PHYSICS_STEP_TIME - non_car->collision_info.message.time) / 1000.0f;
                        GetNetPos((tCar_spec*)non_car);
                    }
                    if (non_car->collision_info.box_face_ref != HV(gFace_num__car)
                        && (non_car->collision_info.box_face_ref != HV(gFace_num__car) - 1
                            || non_car->collision_info.box_face_start <= HV(gFace_count))) {
                        GetFacesInBox(&non_car->collision_info);
                    }
                    if (non_car->collision_info.dt != 0.0f) {
                        MoveAndCollideNonCar(non_car, HV(gDt));
                    }
                }
            }
            do {
                old_num_cars = HV(gNum_cars_and_non_cars);
                CrashCarsTogether(HV(gDt));
            } while (old_num_cars < HV(gNum_cars_and_non_cars));
            HV(gMechanics_time_sync) -= HARNESS_GAME_CONFIG_PHYSICS_STEP_TIME;
            HV(gLast_mechanics_time) += HARNESS_GAME_CONFIG_PHYSICS_STEP_TIME;
        }
        HV(gMechanics_time_sync) = 1;
        SendCarData(HV(gLast_mechanics_time));
        InterpolateCars(frame_end_time, pTime_difference);
        FinishCars(frame_end_time, pTime_difference);
        HV(gDoing_physics) = 0;
        CheckForDeAttachmentOfNonCars(pTime_difference);
    } else {
        original_ApplyPhysicsToCars(last_frame_time, pTime_difference);
    }
}

function_hook_state_t function_hook_state_MungeSpecialVolume = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(function_hook_state_MungeSpecialVolume)
static void(__cdecl*original_MungeSpecialVolume)(tCollision_info *) = (void(__cdecl*)(tCollision_info *))0x004792d0;
CARM95_HOOK_FUNCTION(original_MungeSpecialVolume, MungeSpecialVolume)
void __cdecl MungeSpecialVolume(tCollision_info *pCar) {
    tSpecial_volume *new_special_volume;
    tCar_spec *car;
    LOG_TRACE("(%p)", pCar);

    (void)pCar;
    (void)new_special_volume;
    (void)car;

    if (function_hook_state_MungeSpecialVolume == HOOK_ENABLED) {
        new_special_volume = FindSpecialVolume(&pCar->pos, pCar->last_special_volume);
        if (pCar->auto_special_volume != NULL && (new_special_volume == NULL || new_special_volume->gravity_multiplier == 1.f)) {
            if (pCar->water_d == 10000.f && pCar->water_depth_factor != 1.f) {
                pCar->auto_special_volume = NULL;
            } else {
                new_special_volume = pCar->auto_special_volume;
            }
        }
        if (pCar->last_special_volume != new_special_volume && pCar->driver == eDriver_local_human) {
            if (pCar->last_special_volume != NULL && pCar->last_special_volume->exit_noise >= 0 && (new_special_volume == NULL || pCar->last_special_volume->exit_noise != new_special_volume->exit_noise)) {
                DRS3StartSound(HV(gCar_outlet), pCar->last_special_volume->exit_noise);
            }
            if (new_special_volume != NULL && new_special_volume->entry_noise >= 0 && (pCar->last_special_volume == NULL || pCar->last_special_volume->entry_noise != new_special_volume->entry_noise)) {
                DRS3StartSound(HV(gCar_outlet), new_special_volume->entry_noise);
            }
        }
        pCar->last_special_volume = new_special_volume;
        if (new_special_volume != NULL && pCar->num_smoke_columns != 0 && pCar->last_special_volume != NULL && pCar->last_special_volume->gravity_multiplier < 1.f) {
            StopCarSmoking((tCar_spec*)pCar);
        }
    } else {
        original_MungeSpecialVolume(pCar);
    }
}

function_hook_state_t function_hook_state_ResetCarSpecialVolume = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(function_hook_state_ResetCarSpecialVolume)
static void(__cdecl*original_ResetCarSpecialVolume)(tCollision_info *) = (void(__cdecl*)(tCollision_info *))0x0047901e;
CARM95_HOOK_FUNCTION(original_ResetCarSpecialVolume, ResetCarSpecialVolume)
void __cdecl ResetCarSpecialVolume(tCollision_info *pCar) {
    br_vector3 cast_v;
    br_vector3 norm;
    br_scalar t;
    int id_len;
    char *mat_id;
    tSpecial_volume *new_special_volume;
    br_material *material;
    LOG_TRACE("(%p)", pCar);

    (void)pCar;
    (void)cast_v;
    (void)norm;
    (void)t;
    (void)id_len;
    (void)mat_id;
    (void)new_special_volume;
    (void)material;

    if (function_hook_state_ResetCarSpecialVolume == HOOK_ENABLED) {    new_special_volume = NULL;
        BrVector3Set(&cast_v, 0.f, 200.f, 0.f);
        DisablePlingMaterials();
        FindFace(&pCar->car_master_actor->t.t.translate.t, &cast_v, &norm, &t, &material);
        EnablePlingMaterials();
        if (t < 100.0f && material != NULL) {
            mat_id = material->identifier;
            if (mat_id) {
                id_len = strlen(mat_id);
                if (id_len > 0 && (*mat_id == '!' || *mat_id == '#')) {
                    new_special_volume = GetDefaultSpecialVolumeForWater();
                }
            }
        }
        pCar->auto_special_volume = new_special_volume;
        pCar->water_depth_factor = 1.0f;
    } else {
        original_ResetCarSpecialVolume(pCar);
    }
}

function_hook_state_t function_hook_state_TestAutoSpecialVolume = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_TestAutoSpecialVolume)
static void(__cdecl*original_TestAutoSpecialVolume)(tCollision_info *) = (void(__cdecl*)(tCollision_info *))0x004794d3;
CARM95_HOOK_FUNCTION(original_TestAutoSpecialVolume, TestAutoSpecialVolume)
void __cdecl TestAutoSpecialVolume(tCollision_info *pCar) {
    br_vector3 pos;
    br_scalar car_d;
    br_scalar d;
    br_scalar d2;
    br_vector3 dir;
    br_vector3 tv;
    br_vector3 lp;
    br_vector3 hp;
    tSpecial_volume *vol;
    br_matrix34 *mat;
    br_scalar lowest_p;
    br_scalar highest_p;
    br_scalar val;
    int i;
    LOG_TRACE("(%p)", pCar);

    (void)pCar;
    (void)pos;
    (void)car_d;
    (void)d;
    (void)d2;
    (void)dir;
    (void)tv;
    (void)lp;
    (void)hp;
    (void)vol;
    (void)mat;
    (void)lowest_p;
    (void)highest_p;
    (void)val;
    (void)i;

    if (function_hook_state_TestAutoSpecialVolume == HOOK_ENABLED) {
        assert(0 && "TestAutoSpecialVolume not implemented.");
        abort();
    } else {
        original_TestAutoSpecialVolume(pCar);
    }
}

function_hook_state_t function_hook_state_MoveAndCollideCar = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(function_hook_state_MoveAndCollideCar)
static void(__cdecl*original_MoveAndCollideCar)(tCar_spec *, br_scalar) = (void(__cdecl*)(tCar_spec *, br_scalar))0x004790fd;
CARM95_HOOK_FUNCTION(original_MoveAndCollideCar, MoveAndCollideCar)
void __cdecl MoveAndCollideCar(tCar_spec *car, br_scalar dt) {
    tCollision_info *car_info;
    int wheel;
    LOG_TRACE("(%p, %f)", car, dt);

    (void)car;
    (void)dt;
    (void)car_info;
    (void)wheel;

    if (function_hook_state_MoveAndCollideCar == HOOK_ENABLED) {
        if (car->dt >= 0.0) {
            dt = car->dt;
        }
        if (dt != 0.0 && (!HV(gCar_flying) || &HV(gProgram_state).current_car != car)) {
            car_info = (tCollision_info*)car;
            car->new_skidding = 0;
            if (car->water_d != 10000.0) {
                TestAutoSpecialVolume(car_info);
            }
            MungeSpecialVolume(car_info);
            if (car->driver < eDriver_net_human) {
                CalcForce(car, dt);
            } else {
                CalcEngineForce(car, dt);
                CalcForce(car, dt);
                DoRevs(car, dt);
            }
            RotateCar(car_info, dt);
            TranslateCar(car_info, dt);
            CollideCarWithWall(car_info, dt);
            BrMatrix34ApplyP(&car->pos, &car->cmpos, &car->car_master_actor->t.t.mat);
            car->pos.v[0] = car->pos.v[0] / WORLD_SCALE;
            car->pos.v[1] = car->pos.v[1] / WORLD_SCALE;
            car->pos.v[2] = car->pos.v[2] / WORLD_SCALE;
            for (wheel = 0; wheel < 4; wheel++) {
                SkidMark(car, wheel);
            }
        }
    } else {
        original_MoveAndCollideCar(car, dt);
    }
}

function_hook_state_t function_hook_state_MoveAndCollideNonCar = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(function_hook_state_MoveAndCollideNonCar)
static void(__cdecl*original_MoveAndCollideNonCar)(tNon_car_spec *, br_scalar) = (void(__cdecl*)(tNon_car_spec *, br_scalar))0x00479914;
CARM95_HOOK_FUNCTION(original_MoveAndCollideNonCar, MoveAndCollideNonCar)
void __cdecl MoveAndCollideNonCar(tNon_car_spec *non_car, br_scalar dt) {
    tCollision_info *car_info;
    LOG_TRACE("(%p, %f)", non_car, dt);

    (void)non_car;
    (void)dt;
    (void)car_info;

    if (function_hook_state_MoveAndCollideNonCar == HOOK_ENABLED) {
        car_info = &non_car->collision_info;
        if (car_info->water_d != 10000.0f) {
            TestAutoSpecialVolume(&non_car->collision_info);
        }
        MungeSpecialVolume(&non_car->collision_info);
        if (car_info->dt >= 0.0) {
            dt = car_info->dt;
        }
        NonCarCalcForce(non_car, dt);
        RotateCar(&non_car->collision_info, dt);
        TranslateCar(&non_car->collision_info, dt);
        CollideCarWithWall(&non_car->collision_info, dt);
        BrMatrix34ApplyP(&car_info->pos, &car_info->cmpos, &car_info->car_master_actor->t.t.mat);
        BrVector3InvScale(&car_info->pos, &car_info->pos, WORLD_SCALE);
    } else {
        original_MoveAndCollideNonCar(non_car, dt);
    }
}

function_hook_state_t function_hook_state_CollideCarWithWall = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(function_hook_state_CollideCarWithWall)
static int(__cdecl*original_CollideCarWithWall)(tCollision_info *, br_scalar) = (int(__cdecl*)(tCollision_info *, br_scalar))0x00479a2c;
CARM95_HOOK_FUNCTION(original_CollideCarWithWall, CollideCarWithWall)
int __cdecl CollideCarWithWall(tCollision_info *car, br_scalar dt) {
    LOG_TRACE("(%p, %f)", car, dt);

    (void)car;
    (void)dt;

    if (function_hook_state_CollideCarWithWall == HOOK_ENABLED) {
        GetFacesInBox(car);
        if (HV(gCollision_detection_on__car)) {
            car->collision_flag = 0;
            while (CollCheck(car, dt)) {
                car->collision_flag++;
                if (car->collision_flag - 1 > 20) {
                    car->collision_flag = 1;
                    car->v.v[0] = 0.0;
                    car->v.v[1] = 0.0;
                    car->v.v[2] = 0.0;
                    car->omega.v[0] = 0.0;
                    car->omega.v[1] = 0.0;
                    car->omega.v[2] = 0.0;
                    break;
                }
                RotateCar(car, dt);
                TranslateCar(car, dt);
                GetFacesInBox(car);
            }
            if (car->collision_flag) {
                CrashEarnings((tCar_spec*)car, NULL);
            }
            BrMatrix34TApplyV(&car->velocity_car_space, &car->v, &car->oldmat);
            car->frame_collision_flag += car->collision_flag;
        }
        return car->collision_flag;
    } else {
        return original_CollideCarWithWall(car, dt);
    }
}

function_hook_state_t function_hook_state_ToggleControls = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(function_hook_state_ToggleControls)
void ToggleControls() {
    LOG_TRACE("()");


    if (function_hook_state_ToggleControls == HOOK_ENABLED) {
        if (!HV(ControlCar)[++HV(gControl__car)]) {
            HV(gControl__car) = 0;
        }
        switch (HV(gControl__car)) {
            case 0:
                NewTextHeadupSlot(4, 0, 500, -1, "Original Controls");
                break;
            case 1:
                NewTextHeadupSlot(4, 0, 500, -1, "Accelerated steering");
                break;
            case 2:
                NewTextHeadupSlot(4, 0, 500, -1, "0.75 Accelerated");
                break;
            case 3:
                NewTextHeadupSlot(4, 0, 500, -1, "0.5 Accelerated");
                break;
            default:
                NewTextHeadupSlot(4, 0, 500, -1, "New controls");
                break;
        }
    } else {
        NOT_IMPLEMENTED();
    }
}

function_hook_state_t function_hook_state_ControlCar2 = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_ControlCar2)
static void(__cdecl*original_ControlCar2)(tCar_spec *, br_scalar) = (void(__cdecl*)(tCar_spec *, br_scalar))0x00479c6d;
CARM95_HOOK_FUNCTION(original_ControlCar2, ControlCar2)
void __cdecl ControlCar2(tCar_spec *c, br_scalar dt) {
    LOG_TRACE("(%p, %f)", c, dt);

    (void)c;
    (void)dt;

    if (function_hook_state_ControlCar2 == HOOK_ENABLED) {
        assert(0 && "ControlCar2 not implemented.");
        abort();
    } else {
        original_ControlCar2(c, dt);
    }
}

function_hook_state_t function_hook_state_ControlCar3 = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_ControlCar3)
static void(__cdecl*original_ControlCar3)(tCar_spec *, br_scalar) = (void(__cdecl*)(tCar_spec *, br_scalar))0x00479f4b;
CARM95_HOOK_FUNCTION(original_ControlCar3, ControlCar3)
void __cdecl ControlCar3(tCar_spec *c, br_scalar dt) {
    LOG_TRACE("(%p, %f)", c, dt);

    (void)c;
    (void)dt;

    if (function_hook_state_ControlCar3 == HOOK_ENABLED) {
        assert(0 && "ControlCar3 not implemented.");
        abort();
    } else {
        original_ControlCar3(c, dt);
    }
}

function_hook_state_t function_hook_state_ControlCar4 = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(function_hook_state_ControlCar4)
static void(__cdecl*original_ControlCar4)(tCar_spec *, br_scalar) = (void(__cdecl*)(tCar_spec *, br_scalar))0x0047a20e;
CARM95_HOOK_FUNCTION(original_ControlCar4, ControlCar4)
void __cdecl ControlCar4(tCar_spec *c, br_scalar dt) {
    br_scalar ts;
    LOG_TRACE("(%p, %f)", c, dt);

    (void)c;
    (void)dt;
    (void)ts;

    if (function_hook_state_ControlCar4 == HOOK_ENABLED) {
        if (c->keys.left) {
            if (c->turn_speed < 0.0) {
                c->turn_speed = 0.0;
            }
            if (c->velocity_car_space.v[2] <= 0.0) {
                if ((c->curvature < 0.0 || c->omega.v[1] < -0.001) && c->turn_speed == 0.0) {
                    c->turn_speed = 0.050000001 / (BrVector3Length(&c->v) + 5.0) * (dt * 25.0) * 4.0 / 2.0 * 0.5;
                    if (c->omega.v[1] < -0.01) {
                        c->turn_speed = c->turn_speed - dt * 0.01 / 0.04 / 2.0 * c->omega.v[1] * 2.0;
                    }
                } else {
                    c->turn_speed = 0.050000001 / (BrVector3Length(&c->v) + 5.0) * (dt * 25.0) / 2.0 * 0.5 + c->turn_speed;
                }
            } else {
                c->turn_speed = dt * 0.01 / 0.04 / 2.0 * 2.0 + c->turn_speed;
            }
        }
        if (c->keys.right) {
            if (c->turn_speed > 0.0) {
                c->turn_speed = 0.0;
            }
            if (c->velocity_car_space.v[2] <= 0.0) {
                if ((c->curvature > 0.0 || c->omega.v[1] > 0.001) && c->turn_speed == 0.0) {
                    c->turn_speed = 0.050000001
                                    / (BrVector3Length(&c->v) + 5.0) * (dt * 25.0) * -4.0 / 2.0 * 0.5;
                    if (c->omega.v[1] < -0.01) {
                        c->turn_speed = c->turn_speed - dt * 0.01 / 0.04 / 2.0 * c->omega.v[1] * 2.0;
                    }
                } else {
                    c->turn_speed = c->turn_speed
                                    - 0.050000001
                                      / (BrVector3Length(&c->v) + 5.0) * (dt * 25.0) / 2.0 * 0.5;
                }
            } else {
                c->turn_speed = c->turn_speed - dt * 0.01 / 0.04 / 2.0 * 2.0;
            }
        }
        if (c->keys.left || c->keys.right) {
            if (fabs(c->turn_speed) < fabs(dt * 2.0 * c->curvature) && c->curvature * c->turn_speed < 0.0) {
                c->turn_speed = -(dt * 2.0 * c->curvature);
            }
        } else {
            c->turn_speed = 0.0;
        }
        c->curvature = c->curvature + c->turn_speed;
        if (c->joystick.left <= 0) {
            if (c->joystick.right >= 0) {
                ts = (double)c->joystick.right * (double)c->joystick.right / 4294967300.0;
                c->curvature = c->maxcurve * -ts;
            }
        } else {
            c->curvature = (double)c->joystick.left * (double)c->joystick.left / 4294967300.0 * c->maxcurve;
        }
        if (c->curvature > (double)c->maxcurve) {
            c->curvature = c->maxcurve;
        }
        if (-c->maxcurve > c->curvature) {
            c->curvature = -c->maxcurve;
        }
    } else {
        original_ControlCar4(c, dt);
    }
}

function_hook_state_t function_hook_state_ControlCar5 = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_ControlCar5)
static void(__cdecl*original_ControlCar5)(tCar_spec *, br_scalar) = (void(__cdecl*)(tCar_spec *, br_scalar))0x0047a7b1;
CARM95_HOOK_FUNCTION(original_ControlCar5, ControlCar5)
void __cdecl ControlCar5(tCar_spec *c, br_scalar dt) {
    LOG_TRACE("(%p, %f)", c, dt);

    (void)c;
    (void)dt;

    if (function_hook_state_ControlCar5 == HOOK_ENABLED) {
        assert(0 && "ControlCar5 not implemented.");
        abort();
    } else {
        original_ControlCar5(c, dt);
    }
}

function_hook_state_t function_hook_state_ControlCar1 = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_ControlCar1)
static void(__cdecl*original_ControlCar1)(tCar_spec *, br_scalar) = (void(__cdecl*)(tCar_spec *, br_scalar))0x0047ac31;
CARM95_HOOK_FUNCTION(original_ControlCar1, ControlCar1)
void __cdecl ControlCar1(tCar_spec *c, br_scalar dt) {
    LOG_TRACE("(%p, %f)", c, dt);

    (void)c;
    (void)dt;

    if (function_hook_state_ControlCar1 == HOOK_ENABLED) {
        assert(0 && "ControlCar1 not implemented.");
        abort();
    } else {
        original_ControlCar1(c, dt);
    }
}

function_hook_state_t function_hook_state_setrotate = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_setrotate)
void setrotate(struct br_vector3 *wdt, struct br_matrix34 *m) {
    br_euler e;
    LOG_TRACE("(%p, %p)", wdt, m);

    (void)wdt;
    (void)m;
    (void)e;

    if (function_hook_state_setrotate == HOOK_ENABLED) {
        assert(0 && "setrotate not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}

function_hook_state_t function_hook_state_RotateCar2 = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_RotateCar2)
void RotateCar2(tCollision_info *c, br_scalar dt) {
    br_vector3 wdt;
    br_vector3 wdt2;
    br_vector3 L;
    br_vector3 L2;
    br_matrix34 m;
    LOG_TRACE("(%p, %f)", c, dt);

    (void)c;
    (void)dt;
    (void)wdt;
    (void)wdt2;
    (void)L;
    (void)L2;
    (void)m;

    if (function_hook_state_RotateCar2 == HOOK_ENABLED) {
        assert(0 && "RotateCar2 not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}

function_hook_state_t function_hook_state_RotateCarSecondOrder = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(function_hook_state_RotateCarSecondOrder)
static void(__cdecl*original_RotateCarSecondOrder)(tCollision_info *, br_scalar) = (void(__cdecl*)(tCollision_info *, br_scalar))0x0047b434;
CARM95_HOOK_FUNCTION(original_RotateCarSecondOrder, RotateCarSecondOrder)
void __cdecl RotateCarSecondOrder(tCollision_info *c, br_scalar dt) {
    br_vector3 L;
    br_vector3 L2;
    br_vector3 axis;
    br_vector3 omega;
    br_scalar rad;
    br_scalar rad_rate;
    br_matrix34 m;
    LOG_TRACE("(%p, %f)", c, dt);

    (void)c;
    (void)dt;
    (void)L;
    (void)L2;
    (void)axis;
    (void)omega;
    (void)rad;
    (void)rad_rate;
    (void)m;

    if (function_hook_state_RotateCarSecondOrder == HOOK_ENABLED) {
        rad_rate = BrVector3Length(&c->omega);
        rad = rad_rate * dt;

        BrVector3InvScale(&axis, &c->omega, rad_rate);
        L.v[0] = c->I.v[0] * c->omega.v[0];
        L.v[1] = c->I.v[1] * c->omega.v[1];
        L.v[2] = c->I.v[2] * c->omega.v[2];

        BrMatrix34Rotate(&m, BrRadianToAngle(rad) / 2, &axis);
        BrMatrix34TApplyV(&L2, &L, &m);
        omega.v[0] = L2.v[0] / c->I.v[0];
        omega.v[1] = L2.v[1] / c->I.v[1];
        omega.v[2] = L2.v[2] / c->I.v[2];

        rad_rate = BrVector3Length(&omega);
        rad = rad_rate * dt;

        BrVector3InvScale(&axis, &omega, rad_rate);
        BrMatrix34Rotate(&m, BrRadianToAngle(rad), &axis);
        BrMatrix34PreTranslate(&m, -c->cmpos.v[0], -c->cmpos.v[1], -c->cmpos.v[2]);
        BrMatrix34PostTranslate(&m, c->cmpos.v[0], c->cmpos.v[1], c->cmpos.v[2]);
        BrMatrix34Pre(&c->car_master_actor->t.t.mat, &m);
        BrMatrix34TApplyV(&L2, &L, &m);
        c->omega.v[0] = L2.v[0] / c->I.v[0];
        c->omega.v[1] = L2.v[1] / c->I.v[1];
        c->omega.v[2] = L2.v[2] / c->I.v[2];
    } else {
        original_RotateCarSecondOrder(c, dt);
    }
}

function_hook_state_t function_hook_state_RotateCarFirstOrder = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(function_hook_state_RotateCarFirstOrder)
void RotateCarFirstOrder(tCollision_info *c, br_scalar dt) {
    br_vector3 axis;
    br_vector3 L;
    br_vector3 L2;
    br_matrix34 m;
    br_scalar rad_rate;
    br_scalar rad;
    br_scalar e1;
    br_scalar e2;
    static br_scalar max_rad;
    LOG_TRACE("(%p, %f)", c, dt);

    (void)c;
    (void)dt;
    (void)axis;
    (void)L;
    (void)L2;
    (void)m;
    (void)rad_rate;
    (void)rad;
    (void)e1;
    (void)e2;
    (void)max_rad;

    if (function_hook_state_RotateCarFirstOrder == HOOK_ENABLED) {
        rad_rate = BrVector3Length(&c->omega);
        rad = rad_rate * dt;

        if (rad < 0.0001) {
            return;
        }
        BrVector3InvScale(&axis, &c->omega, rad_rate);
        L.v[0] = c->I.v[0] * c->omega.v[0];
        L.v[1] = c->I.v[1] * c->omega.v[1];
        L.v[2] = c->I.v[2] * c->omega.v[2];
        BrMatrix34Rotate(&m, BrRadianToAngle(rad), &axis);
        BrMatrix34TApplyV(&L2, &L, &m);
        BrMatrix34PreTranslate(&m, -c->cmpos.v[0], -c->cmpos.v[1], -c->cmpos.v[2]);
        BrMatrix34PostTranslate(&m, c->cmpos.v[0], c->cmpos.v[1], c->cmpos.v[2]);
        BrMatrix34Pre(&c->car_master_actor->t.t.mat, &m);
        c->omega.v[0] = L2.v[0] / c->I.v[0];
        c->omega.v[1] = L2.v[1] / c->I.v[1];
        c->omega.v[2] = L2.v[2] / c->I.v[2];
    } else {
        NOT_IMPLEMENTED();
    }
}

function_hook_state_t function_hook_state_SimpleRotate = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(function_hook_state_SimpleRotate)
static void(__cdecl*original_SimpleRotate)(tCollision_info *, br_scalar) = (void(__cdecl*)(tCollision_info *, br_scalar))0x0047b23c;
CARM95_HOOK_FUNCTION(original_SimpleRotate, SimpleRotate)
void __cdecl SimpleRotate(tCollision_info *c, br_scalar dt) {
    br_vector3 axis;
    br_scalar rad_rate;
    br_scalar rad;
    LOG_TRACE("(%p, %f)", c, dt);

    (void)c;
    (void)dt;
    (void)axis;
    (void)rad_rate;
    (void)rad;

    if (function_hook_state_SimpleRotate == HOOK_ENABLED) {
        rad_rate = BrVector3Length(&c->omega);
        BrVector3InvScale(&axis, &c->omega, rad_rate);
        rad = rad_rate * dt;
        if (rad >= 0.0001) {
            BrMatrix34PreRotate(&c->car_master_actor->t.t.mat, BrRadianToAngle(rad), &axis);
        }
    } else {
        original_SimpleRotate(c, dt);
    }
}

function_hook_state_t function_hook_state_RotateCar = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(function_hook_state_RotateCar)
static void(__cdecl*original_RotateCar)(tCollision_info *, br_scalar) = (void(__cdecl*)(tCollision_info *, br_scalar))0x0047b2fd;
CARM95_HOOK_FUNCTION(original_RotateCar, RotateCar)
void __cdecl RotateCar(tCollision_info *c, br_scalar dt) {
    br_scalar rad_squared;
    int steps;
    int i;
    LOG_TRACE("(%p, %f)", c, dt);

    (void)c;
    (void)dt;
    (void)rad_squared;
    (void)steps;
    (void)i;

    if (function_hook_state_RotateCar == HOOK_ENABLED) {
        rad_squared = BrVector3LengthSquared(&c->omega) * dt;
        c->oldomega = c->omega;

        if (rad_squared < 0.0000001) {
            return;
        }

        if (rad_squared > 0.008f) {
            steps = sqrt(rad_squared / 0.032) + 1;
            dt = dt / steps;

            for (i = 0; i < steps && i < 20; i++) {
                RotateCarSecondOrder(c, dt);
            }
        } else {
            RotateCarFirstOrder(c, dt);
        }
    } else {
        original_RotateCar(c, dt);
    }
}

function_hook_state_t function_hook_state_SteeringSelfCentre = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(function_hook_state_SteeringSelfCentre)
static void(__cdecl*original_SteeringSelfCentre)(tCar_spec *, br_scalar, br_vector3 *) = (void(__cdecl*)(tCar_spec *, br_scalar, br_vector3 *))0x0047ea86;
CARM95_HOOK_FUNCTION(original_SteeringSelfCentre, SteeringSelfCentre)
void __cdecl SteeringSelfCentre(tCar_spec *c, br_scalar dt, br_vector3 *n) {
    br_scalar ts;
    br_scalar ts2;
    LOG_TRACE("(%p, %f, %p)", c, dt, n);

    (void)c;
    (void)dt;
    (void)n;
    (void)ts;
    (void)ts2;

    if (function_hook_state_SteeringSelfCentre == HOOK_ENABLED) {
        if (c->curvature > c->maxcurve) {
            c->curvature = c->maxcurve;
        }
        if (-c->maxcurve > c->curvature) {
            c->curvature = -c->maxcurve;
        }
        if (!c->keys.left && c->joystick.left <= 0 && !c->keys.right && c->joystick.right <= 0 && !c->keys.holdw) {
            if (c->susp_height[1] > c->oldd[2] || c->susp_height[1] > c->oldd[3]) {
                ts = -((c->omega.v[2] * n->v[2] + c->omega.v[1] * n->v[1] + c->omega.v[0] * n->v[0]) * (dt / (c->wpos[0].v[2] - c->wpos[2].v[2])));
                ts2 = -(c->curvature * dt);
                if (fabs(ts) < fabs(ts2) || (ts * ts2 < 0.0)) {
                    ts = ts2;
                }
                c->curvature = c->curvature + ts;
                if (c->curvature * ts > 0.0) {
                    c->curvature = 0.0;
                }
            }
        }
    } else {
        original_SteeringSelfCentre(c, dt, n);
    }
}

function_hook_state_t function_hook_state_NonCarCalcForce = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(function_hook_state_NonCarCalcForce)
static void(__cdecl*original_NonCarCalcForce)(tNon_car_spec *, br_scalar) = (void(__cdecl*)(tNon_car_spec *, br_scalar))0x0047b68d;
CARM95_HOOK_FUNCTION(original_NonCarCalcForce, NonCarCalcForce)
void __cdecl NonCarCalcForce(tNon_car_spec *nc, br_scalar dt) {
    tCollision_info *c;
    tSpecial_volume *vol;
    br_scalar ts;
    br_vector3 tv;
    br_vector3 v;
    LOG_TRACE("(%p, %f)", nc, dt);

    (void)nc;
    (void)dt;
    (void)c;
    (void)vol;
    (void)ts;
    (void)tv;
    (void)v;

    if (function_hook_state_NonCarCalcForce == HOOK_ENABLED) {
        c = &nc->collision_info;
        vol = nc->collision_info.last_special_volume;
        if (nc->collision_info.car_master_actor->identifier[3] != '!') {
            if (c->car_master_actor->t.t.mat.m[1][1] < nc->snap_off_cosine || c->min_torque_squared == 0.0f) {
                c->car_master_actor->identifier[3] = '!';
                c->M = nc->free_mass;
                c->min_torque_squared = 0.0f;
                BrVector3Sub(&v, &nc->free_cmpos, &c->cmpos);
                BrVector3Cross(&tv, &c->omega, &v);
                BrMatrix34ApplyV(&v, &tv, &c->car_master_actor->t.t.mat);
                BrVector3Accumulate(&c->v, &v);
                c->cmpos = nc->free_cmpos;
            } else {
                BrVector3SetFloat(&c->v, 0.0f, 0.0f, 0.0f);
                ts = BrVector3LengthSquared(&c->omega);
                BrVector3SetFloat(&c->omega, 0.0f, 0.0f, 0.0f);
                c->doing_nothing_flag = 1;
            }
        }
        if (c->car_master_actor->identifier[3] == '!') {
            if (vol != NULL) {
                c->v.v[1] = c->v.v[1] - dt * 10.0f * vol->gravity_multiplier;
            } else {
                c->v.v[1] = c->v.v[1] - dt * 10.0f;
            }
            ts = BrVector3Length(&c->v);
            if (vol != NULL) {
                ts = vol->viscosity_multiplier * ts;
            }
            ts = -(dt * 0.0005f * ts) / c->M;
            BrVector3Scale(&v, &c->v, ts);
            BrVector3Accumulate(&c->v, &v);
            ts = BrVector3Length(&c->omega);
            if (vol != NULL) {
                ts = vol->viscosity_multiplier * ts;
            }
            ts = -(dt * 0.0005 * ts);
            BrVector3Scale(&v, &c->omega, ts);
            ApplyTorque(CAR(c), &v);
        }
    } else {
        original_NonCarCalcForce(nc, dt);
    }
}

function_hook_state_t function_hook_state_AddDrag = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(function_hook_state_AddDrag)
static void(__cdecl*original_AddDrag)(tCar_spec *, br_scalar) = (void(__cdecl*)(tCar_spec *, br_scalar))0x0047ec63;
CARM95_HOOK_FUNCTION(original_AddDrag, AddDrag)
void __cdecl AddDrag(tCar_spec *c, br_scalar dt) {
    br_scalar drag_multiplier;
    br_scalar ts;
    tSpecial_volume *vol;
    br_vector3 b;
    LOG_TRACE("(%p, %f)", c, dt);

    (void)c;
    (void)dt;
    (void)drag_multiplier;
    (void)ts;
    (void)vol;
    (void)b;

    if (function_hook_state_AddDrag == HOOK_ENABLED) {
        vol = c->last_special_volume;
        drag_multiplier = -(dt * TIME_CONV_THING);
        if (vol) {
            if (c->underwater_ability) {
                drag_multiplier = vol->viscosity_multiplier * drag_multiplier * 0.6;
            } else {
                drag_multiplier = vol->viscosity_multiplier * drag_multiplier;
            }
            drag_multiplier = c->water_depth_factor * drag_multiplier;
        }
        ts = BrVector3Length(&c->v) * drag_multiplier / c->M;
        BrVector3Scale(&b, &c->v, ts);
        BrVector3Accumulate(&c->v, &b);
        ts = BrVector3Length(&c->omega) * drag_multiplier;
        BrVector3Scale(&b, &c->omega, ts);
        ApplyTorque(c, &b);
    } else {
        original_AddDrag(c, dt);
    }
}

function_hook_state_t function_hook_state_DoBumpiness = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(function_hook_state_DoBumpiness)
static void(__cdecl*original_DoBumpiness)(tCar_spec *, br_vector3 *, br_vector3 *, br_scalar *, int) = (void(__cdecl*)(tCar_spec *, br_vector3 *, br_vector3 *, br_scalar *, int))0x0047ede9;
CARM95_HOOK_FUNCTION(original_DoBumpiness, DoBumpiness)
void __cdecl DoBumpiness(tCar_spec *c, br_vector3 *wheel_pos, br_vector3 *norm, br_scalar *d, int n) {
    br_vector3 tv;
    int delta;
    int x;
    int y;
    tMaterial_modifiers *mat_list;
    LOG_TRACE("(%p, %p, %p, %p, %d)", c, wheel_pos, norm, d, n);

    (void)c;
    (void)wheel_pos;
    (void)norm;
    (void)d;
    (void)n;
    (void)tv;
    (void)delta;
    (void)x;
    (void)y;
    (void)mat_list;

    if (function_hook_state_DoBumpiness == HOOK_ENABLED) {
        tv.v[0] = c->nor[n].v[0] * d[n] + wheel_pos[n].v[0];
        tv.v[2] = c->nor[n].v[2] * d[n] + wheel_pos[n].v[2];

        x = abs((int)(512.0f * tv.v[0])) % 2048;
        y = abs((int)(512.0f * tv.v[2])) % 2048;

        if (x > 1024) {
            x = 2048 - x;
        }
        if (y > 1024) {
            y = 2048 - y;
        }
        if (x + y <= 1024) {
            delta = x + y;
        } else {
            delta = 2048 - x - y;
        }
        delta -= 400;
        if (delta < 0) {
            delta = 0;
        }
        mat_list = HV(gCurrent_race).material_modifiers;
        d[n] = delta * mat_list[c->material_index[n]].bumpiness / 42400.0f * norm[n].v[1] + d[n];
    } else {
        original_DoBumpiness(c, wheel_pos, norm, d, n);
    }
}

function_hook_state_t function_hook_state_CalcForce = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(function_hook_state_CalcForce)
static void(__cdecl*original_CalcForce)(tCar_spec *, br_scalar) = (void(__cdecl*)(tCar_spec *, br_scalar))0x0047ba5d;
CARM95_HOOK_FUNCTION(original_CalcForce, CalcForce)
void __cdecl CalcForce(tCar_spec *c, br_scalar dt) {
    int n;
    int normnum;
    int i;
    int x;
    int y;
    br_scalar force[4];
    br_scalar d[4];
    br_scalar ts;
    br_scalar ts2;
    br_scalar ts3;
    br_scalar ts4;
    br_scalar ts5;
    br_scalar ts6;
    br_scalar deltaomega;
    br_scalar wheelratio;
    br_scalar modf;
    br_scalar maxfl;
    br_scalar maxfr;
    br_scalar max_retardation;
    br_scalar front_retardation;
    br_scalar friction_number;
    br_vector3 a;
    br_vector3 b;
    br_vector3 tv;
    br_vector3 tv2;
    br_vector3 norm[4];
    br_vector3 v_batwick;
    br_vector3 vplane;
    br_vector3 rightplane;
    br_vector3 t;
    br_vector3 f;
    br_vector3 ff;
    br_vector3 fb;
    br_scalar ffi;
    br_scalar ffk;
    br_scalar fbi;
    br_scalar fbk;
    br_vector3 wheel_pos[4];
    br_scalar direction;
    br_scalar wheel_spin_force;
    br_scalar d_damage;
    br_scalar fl_oil_factor;
    br_scalar fr_oil_factor;
    br_scalar rl_oil_factor;
    br_scalar rr_oil_factor;
    br_matrix34 *mat;
    tMaterial_modifiers *mat_list;
    static br_scalar stop_timer;
    static br_scalar slide_dist;
    tDamage_type dam;
    br_scalar v;
    tSpecial_volume *vol;
    br_scalar __block0___scale;
    br_scalar __block1___scale;
    br_scalar __block2___scale;
    br_scalar __block3___scale;
    LOG_TRACE("(%p, %f)", c, dt);

    (void)c;
    (void)dt;
    (void)n;
    (void)normnum;
    (void)i;
    (void)x;
    (void)y;
    (void)force;
    (void)d;
    (void)ts;
    (void)ts2;
    (void)ts3;
    (void)ts4;
    (void)ts5;
    (void)ts6;
    (void)deltaomega;
    (void)wheelratio;
    (void)modf;
    (void)maxfl;
    (void)maxfr;
    (void)max_retardation;
    (void)front_retardation;
    (void)friction_number;
    (void)a;
    (void)b;
    (void)tv;
    (void)tv2;
    (void)norm;
    (void)v_batwick;
    (void)vplane;
    (void)rightplane;
    (void)t;
    (void)f;
    (void)ff;
    (void)fb;
    (void)ffi;
    (void)ffk;
    (void)fbi;
    (void)fbk;
    (void)wheel_pos;
    (void)direction;
    (void)wheel_spin_force;
    (void)d_damage;
    (void)fl_oil_factor;
    (void)fr_oil_factor;
    (void)rl_oil_factor;
    (void)rr_oil_factor;
    (void)mat;
    (void)mat_list;
    (void)stop_timer;
    (void)slide_dist;
    (void)dam;
    (void)v;
    (void)vol;
    (void)__block0___scale;
    (void)__block1___scale;
    (void)__block2___scale;
    (void)__block3___scale;

    if (function_hook_state_CalcForce == HOOK_ENABLED) {

        int v72;         // [esp+24h] [ebp-1C8h]
        double v73;      // [esp+2Ch] [ebp-1C0h]
        float v74;       // [esp+34h] [ebp-1B8h]
        float v75;       // [esp+38h] [ebp-1B4h]
        float v76;       // [esp+3Ch] [ebp-1B0h]
        float v77;       // [esp+40h] [ebp-1ACh]
        float v78;       // [esp+44h] [ebp-1A8h]
        float v79;       // [esp+48h] [ebp-1A4h]
        float v80;       // [esp+4Ch] [ebp-1A0h] MAPDST
        float v82;       // [esp+50h] [ebp-19Ch] MAPDST
        float v84;       // [esp+54h] [ebp-198h]
        float v85;       // [esp+58h] [ebp-194h] MAPDST
        float v87;       // [esp+5Ch] [ebp-190h] MAPDST
        float v98;       // [esp+88h] [ebp-164h]
        float v99;       // [esp+8Ch] [ebp-160h]
        br_vector3 v102; // [esp+98h] [ebp-154h]
        br_vector3 v103; // [esp+A4h] [ebp-148h]
        int v105;        // [esp+B8h] [ebp-134h]
        float v106;      // [esp+C0h] [ebp-12Ch]
        br_vector3 v107; // [esp+C4h] [ebp-128h]
        float v108;      // [esp+D0h] [ebp-11Ch]
        float v109;      // [esp+D4h] [ebp-118h]
        float v116;      // [esp+F8h] [ebp-F4h]
        br_vector3 B;    // [esp+FCh] [ebp-F0h] BYREF
        br_scalar pV;    // [esp+10Ch] [ebp-E0h]
        br_vector3 v123; // [esp+130h] [ebp-BCh]
        float v125;      // [esp+16Ch] [ebp-80h]
        float v128;      // [esp+18Ch] [ebp-60h]
        float v129;      // [esp+190h] [ebp-5Ch]
        float v134;      // [esp+1D8h] [ebp-14h]
        float v135;      // [esp+1DCh] [ebp-10h]
        br_vector3 v136; // [esp+1E0h] [ebp-Ch]

        BrVector3Set(&v136, 0, 0, 0);
        normnum = 0;
        BrVector3Set(&f, 0, 0, 0);
        BrVector3Set(&B, 0, 0, 0);
        mat = &c->car_master_actor->t.t.mat;
        mat_list = HV(gCurrent_race).material_modifiers;
        vol = c->last_special_volume;
        b.v[0] = -mat->m[1][0];
        b.v[1] = -mat->m[1][1];
        b.v[2] = -mat->m[1][2];
        c->material_index[0] = 0;
        c->material_index[1] = 0;
        c->material_index[2] = 0;
        c->material_index[3] = 0;
        wheelratio = (c->wpos[2].v[2] - c->cmpos.v[2]) / (c->wpos[0].v[2] - c->cmpos.v[2]);
        BrVector3Set(&c->road_normal, 0, 0, 0);
        for (i = 0; i < 4; ++i) {
            BrMatrix34ApplyP(&wheel_pos[i], &c->wpos[i], mat);
        }
        MultiFindFloorInBoxM(4, wheel_pos, &b, c->nor, d, c, c->material_index);
        if (c->last_special_volume && c->last_special_volume->material_modifier_index) {
            c->material_index[0] = c->last_special_volume->material_modifier_index;
            c->material_index[1] = c->material_index[0];
            c->material_index[2] = c->material_index[1];
            c->material_index[3] = c->material_index[2];
        }
        for (i = 0; i < 4; ++i) {
            BrMatrix34TApplyV(&norm[i], &c->nor[i], mat);
            if (mat_list[c->material_index[i]].bumpiness != 0.0) {
                DoBumpiness(c, wheel_pos, norm, d, i);
            }
            if (d[i] < -0.5 || c->wheel_dam_offset[i ^ 2] * 6.9 + c->susp_height[i / 2] < d[i]) {
                force[i] = 0.0;
                d[i] = c->susp_height[i / 2];
            } else {
                BrVector3Accumulate(&c->road_normal, &norm[i]);
                normnum++;
                d[i] = d[i] - c->wheel_dam_offset[i ^ 2] * 6.9;
                force[i] = (c->susp_height[i / 2] - d[i]) * c->sk[1 / 2];
                force[i] = force[i] - (d[i] - c->oldd[i]) / dt * c->sb[i / 2];
                if (c->susp_height[i / 2] == c->oldd[i]
                    && c->nor[i].v[2] * c->v.v[2] + c->nor[i].v[1] * c->v.v[1] + c->nor[i].v[0] * c->v.v[0] > -0.0099999998
                    && c->M * 20.0 / 4.0 < force[i]) {
                    d[i] = c->susp_height[i / 2];
                    force[i] = c->M * 20.0 / 4.0;
                }
                if (force[i] < 0.0) {
                    force[i] = 0.0;
                }
                B.v[1] = force[i] + B.v[1];
                f.v[0] = f.v[0] - (c->wpos[i].v[2] - c->cmpos.v[2]) * force[i];
                f.v[2] = (c->wpos[i].v[0] - c->cmpos.v[0]) * force[i] + f.v[2];
            }
            c->oldd[i] = d[i];
        }
        if (c->driver <= eDriver_non_car || !c->wall_climber_mode || (c->road_normal.v[0] == 0.0 && c->road_normal.v[1] == 0.0 && c->road_normal.v[2] == 0.0)) {
            if (vol) {
                friction_number = (1.0 - vol->gravity_multiplier) * c->water_depth_factor;
                if (c->underwater_ability) {
                    friction_number = friction_number * 0.6;
                }
                friction_number = (1.0 - friction_number) * c->M;
            } else {
                friction_number = c->M;
            }
            friction_number = friction_number * HV(gGravity_multiplier) * 10.0;
            B.v[0] = B.v[0] - mat->m[0][1] * friction_number;
            B.v[1] = B.v[1] - mat->m[1][1] * friction_number;
            B.v[2] = B.v[2] - mat->m[2][1] * friction_number;
        } else {
            BrVector3Normalise(&v107, &c->road_normal);
            BrVector3Scale(&v107, &v107, -(c->M * 10.0));
            BrVector3Accumulate(&B, &v107);
        }
        if (c->driver >= eDriver_net_human) {
            SteeringSelfCentre(c, dt, &c->road_normal);
        }
        if (normnum) {
            // ts = 1.0 / sqrt(1.0); <- looked like this in the windows build definitely wrong
            // ts = 1.0 / sqrt(c->road_normal.v[0] * c->road_normal.v[0] + c->road_normal.v[1] * c->road_normal.v[1] + c->road_normal.v[2] * c->road_normal.v[2]);
            // c->road_normal.v[0] = c->road_normal.v[0] * ts;
            // c->road_normal.v[1] = c->road_normal.v[1] * ts;
            // c->road_normal.v[2] = c->road_normal.v[2] * ts;
            BrVector3NormaliseQuick(&c->road_normal, &c->road_normal);

            friction_number = c->road_normal.v[1] * mat->m[1][1] + c->road_normal.v[2] * mat->m[2][1] + c->road_normal.v[0] * mat->m[0][1];
            if (c->driver > eDriver_non_car && c->wall_climber_mode) {
                friction_number = 1.0;
            }
            friction_number = HV(gCurrent_race).material_modifiers[c->material_index[0]].down_force * friction_number;
            if (friction_number > 0.0f) {
                friction_number = fabs(c->velocity_car_space.v[2]) * c->M * 10.0 * friction_number / c->down_force_speed;
                if (c->M * 10.0 < friction_number) {
                    friction_number = c->M * 10.0;
                }
                if (c->number_of_wheels_on_ground == 4 && c->oldd[2] == c->susp_height[1] && c->oldd[3] == c->susp_height[1]) {
                    a.v[0] = c->wpos[2].v[2] * mat->m[2][0];
                    a.v[1] = c->wpos[2].v[2] * mat->m[2][1];
                    a.v[2] = c->wpos[2].v[2] * mat->m[2][2];
                    a.v[0] = mat->m[3][0] + a.v[0];
                    a.v[1] = mat->m[3][1] + a.v[1];
                    a.v[2] = mat->m[3][2] + a.v[2];
                    BrVector3Scale(&b, &b, (c->wpos[0].v[2] - c->wpos[2].v[2]));
                    findfloor(&a, &b, norm, &ts2);
                    if (ts2 > 1.0) {
                        c->down_force_flag = 1;
                    }
                } else if (c->down_force_flag && (c->oldd[2] < c->susp_height[1] || c->oldd[3] < c->susp_height[1])) {
                    c->down_force_flag = 0;
                }
                if (c->down_force_flag) {
                    friction_number = (c->wpos[2].v[2] - c->cmpos.v[2]) / (c->wpos[2].v[2] - c->wpos[0].v[2]) * friction_number;
                    f.v[0] = (c->wpos[0].v[2] - c->cmpos.v[2]) * friction_number + f.v[0];
                }
                B.v[1] = B.v[1] - friction_number;
            }
            vplane.v[0] = BrVector3Dot(&c->velocity_car_space, &c->road_normal) * c->road_normal.v[0];
            vplane.v[1] = BrVector3Dot(&c->velocity_car_space, &c->road_normal) * c->road_normal.v[1];
            vplane.v[2] = BrVector3Dot(&c->velocity_car_space, &c->road_normal) * c->road_normal.v[2];
            BrVector3Sub(&vplane, &c->velocity_car_space, &vplane);
            if (vplane.v[2] < 0.0) {
                ts = 1.0;
            } else {
                ts = -1.0;
            }
            ts3 = BrVector3Length(&vplane);
            deltaomega = ts3 * c->curvature * ts;
            deltaomega = deltaomega - BrVector3Dot(&c->omega, &c->road_normal);
            BrVector3Set(&v103, c->road_normal.v[1], -c->road_normal.v[0], 0);
            BrVector3Normalise(&v103, &v103);

            friction_number = c->I.v[1] / dt * deltaomega;
            ts = friction_number / (c->wpos[2].v[2] - c->wpos[0].v[2]);
            v108 = ts;
            v109 = -ts;
            BrVector3Set(&rightplane, 0, c->road_normal.v[2], -c->road_normal.v[1]);
            BrVector3Normalise(&rightplane, &rightplane);
            v99 = c->acc_force;
            friction_number = BrVector3Dot(&rightplane, &vplane);
            v87 = BrVector3Dot(&v103, &vplane);
            ts2 = fabs(v87);
            friction_number = (c->wpos[0].v[2] - c->cmpos.v[2]) * friction_number * fabs(c->curvature);
            if (c->curvature <= 0.0) {
                friction_number = v87 - friction_number;
            } else {
                friction_number = v87 + friction_number;
            }
            friction_number = -(c->M / dt * friction_number);
            friction_number = friction_number - BrVector3Dot(&B, &v103);

            friction_number = friction_number / (1.0 - wheelratio);
            v108 = friction_number + v108;
            v109 = -wheelratio * friction_number + v109;
            friction_number = (c->wpos[0].v[2] - c->wpos[2].v[2]) * v108;
            v98 = friction_number * c->curvature;
            friction_number = BrVector3Dot(&c->velocity_car_space, &rightplane) * c->M / dt;
            v129 = BrVector3Dot(&rightplane, &B) + friction_number;
            v128 = c->mu[0] * c->brake_force / (c->mu[1] / c->friction_elipticity + c->mu[0]);
            v125 = c->brake_force - v128;
            v105 = (c->damage_units[7].damage_level + c->damage_units[6].damage_level) / 2;
            if (v105 > 20) {
                v128 = (1.0 - (double)(v105 - 20) / 80.0) * (1.0 - (double)(v105 - 20) / 80.0) * v128;
            }
            v105 = (c->damage_units[5].damage_level + c->damage_units[4].damage_level) / 2;
            if (v105 > 20) {
                v125 = (1.0 - (double)(v105 - 20) / 80.0) * (1.0 - (double)(v105 - 20) / 80.0) * v125;
            }
            ts2 = (force[1] + force[0]) * c->rolling_r_back + v128;
            v87 = (force[2] + force[3]) * c->rolling_r_front + v125;
            v128 = c->wpos[0].v[2] - c->wpos[2].v[2];
            v128 = sqrt(v128 * v128 * c->curvature * c->curvature + 1.0);
            v106 = v87 / v128;
            v134 = v106 + ts2;
            if (fabs(v129) < fabs(v134)) {
                ts2 = v129 / v134 * ts2;
                v106 = v129 / v134 * v106;
            }
            if ((v87 + ts2) * v129 < 0.0) {
                ts2 = -ts2;
                v106 = -v106;
            }
            v129 = v129 - (ts2 + v106);
            v99 = v99 - ts2;
            if (c->keys.brake && c->damage_units[eDamage_lr_brake].damage_level < 60 && c->damage_units[eDamage_rr_brake].damage_level < 60) {
                v99 = v99 - v129;
                c->gear = 0;
            }
            v99 = v99 / c->friction_elipticity;
            v135 = sqrt(v99 * v99 + v109 * v109) / 2.0;

            GetOilFrictionFactors(c, &fl_oil_factor, &fr_oil_factor, &rl_oil_factor, &rr_oil_factor);
            if (c->driver <= eDriver_non_car) {
                v116 = 1.0;
            } else {
                v116 = c->grip_multiplier;
            }
            BrVector3Sub(&v102, &c->wpos[0], &c->cmpos);
            BrVector3Cross(&a, &c->omega, &v102);
            BrVector3Accumulate(&a, &c->velocity_car_space);
            if (c->driver >= eDriver_net_human
                && (((c->keys.left || c->joystick.left > 0x8000) && c->curvature > 0.0 && deltaomega > 0.1 && a.v[0] > 0.0)
                    || ((c->keys.right || c->joystick.right > 0x8000) && c->curvature < 0.0 && deltaomega < 0.1 && a.v[0] < 0.0))
                && ts > 0.0) {
                friction_number = c->mu[0];
            } else {
                friction_number = c->mu[2];
                ts2 = fabs(a.v[0]) / 10.0;
                if (ts2 > 1) {
                    ts2 = 1.0;
                }
                friction_number = (c->mu[2] - c->mu[0]) * ts2 + friction_number;
            }

            maxfl = sqrt(force[0]) * friction_number * (rl_oil_factor * v116) * mat_list[c->material_index[0]].tyre_road_friction;
            maxfr = sqrt(force[1]) * friction_number * (rr_oil_factor * v116) * mat_list[c->material_index[1]].tyre_road_friction;
            c->max_force_rear = maxfr + maxfl;
            if (rl_oil_factor == 1.0 && rr_oil_factor == 1.0 && c->traction_control && v135 * 2.0 > c->max_force_rear && c->acc_force > 0.0
                && (c->driver < eDriver_net_human || (c->target_revs > 1000.0 && c->gear > 0))) {
                ts2 = v99;
                if (v99 * v99 <= v135 * v135 * 4.0) {
                    v87 = sqrt(v135 * v135 * 4.0 - v99 * v99);
                } else {
                    v87 = 0.0;
                }
                if (c->max_force_rear <= v87) {
                    c->torque = -(c->revs * c->revs / 100000000.0) - 0.1;
                } else {
                    float v177 = sqrt(c->max_force_rear * c->max_force_rear - v87 * v87);
                    ts3 = ts2 < 0.0 ? -1.0 : 1.0;
                    // ts4 = (ts2 - ts3 * sqrt(ts3)) * 1.01;
                    // if (fabs(ts2) > fabs(ts4)) {
                    //     v87 = ts4;
                    //     ts2 = v87;
                    // }

                    ts4 = (ts2 - ts3 * v177) * 1.01;
                    if (fabs(ts2) > fabs(ts4)) {
                        ts2 = ts4;
                    }
                }
                v99 = v99 - ts2;
                v135 = sqrt(v99 * v99 + v109 * v109) / 2.0;

            } else if (c->driver >= eDriver_net_human && c->gear > 0 && c->revs > c->target_revs && !c->traction_control) {
                if (!c->keys.change_down) {
                    c->traction_control = 1;
                }
                friction_number = 1.0 - (c->revs - c->target_revs) / (double)(400 * c->gear);
                if (friction_number < 0.40000001) {
                    friction_number = 0.40000001;
                }
                maxfl = friction_number * maxfl;
                maxfr = friction_number * maxfr;
            }
            if (fabs(v109) > maxfr + maxfl && maxfr + maxfl > 0.1) {
                v87 = (maxfr + maxfl) / fabs(v109) * dt;
                v109 = v87 * v109;
                v99 = c->friction_elipticity * v87 * v99;
                friction_number = -((c->wpos[2].v[2] - c->cmpos.v[2]) * v108 * ((c->wpos[2].v[2] - c->cmpos.v[2]) * v108) / c->I.v[1] + (v98 * v98 + v108 * v108) / c->M);
                ts2 = (BrVector3Dot(&v103, &vplane) + v109 / c->M) * v108;
                ts2 = BrVector3Dot(&rightplane, &vplane) * v98 + ts2;
                ts2 = BrVector3Dot(&c->omega, &c->road_normal) * (c->wpos[2].v[2] - c->cmpos.v[2]) * v108 + ts2;
                ts2 = (c->wpos[0].v[2] - c->cmpos.v[2]) * (c->wpos[2].v[2] - c->cmpos.v[2]) * v109 / c->I.v[1] * v108 + ts2;
                if (fabs(friction_number) > 0.1) {
                    friction_number = ts2 / (friction_number * dt);
                    v108 = friction_number * v108;
                    v98 = friction_number * v98;
                }
                v109 = v109 / v87;
                v99 = v99 / (c->friction_elipticity * v87);
            }
            v98 = v98 - v106;
            v108 = (c->wpos[0].v[2] - c->wpos[2].v[2]) * c->curvature * v106 + v108;
            if (v135 > 0.000099999997) {
                v109 = v109 / (v135 * 2.0);
                v99 = v99 / (v135 * 2.0);
            }
            v99 = c->friction_elipticity * v99;
            force[0] = v135;
            force[1] = v135;
            c->wheel_slip = 0;
            switch ((force[0] > maxfl) + 2 * (force[1] > maxfr)) {
                case 0:
                    slide_dist = 0;
                    break;
                case 1:
                    force[0] = c->freduction * maxfl;
                    force[1] = v135 - force[0] + force[1];
                    if (force[1] <= maxfr) {
                        slide_dist = 0;
                    } else {
                        if (maxfr > 0.1) {
                            pV = (force[1] - maxfr) / maxfr;
                            if (&HV(gProgram_state).current_car == c) {
                                v78 = 20.0;
                            } else {
                                v78 = 60.0;
                            }
                            if (v78 <= pV) {
                                c->new_skidding |= 2u;
                            }
                            SkidNoise(c, 1, pV, c->material_index[1]);
                        }
                        force[1] = c->freduction * maxfr;
                        c->wheel_slip |= 2u;
                    }
                    break;
                case 2:
                    force[1] = c->freduction * maxfr;
                    force[0] = v135 - force[1] + force[0];
                    if (force[0] <= maxfl) {
                        slide_dist = 0;
                    } else {
                        if (maxfl > 0.1) {
                            pV = (force[0] - maxfl) / maxfl;
                            if (&HV(gProgram_state).current_car == c) {
                                v77 = 20.0;
                            } else {
                                v77 = 60.0;
                            }
                            if (v77 <= pV) {
                                c->new_skidding |= 1u;
                            }
                            SkidNoise(c, 0, pV, c->material_index[0]);
                        }
                        force[0] = c->freduction * maxfl;
                        c->wheel_slip |= 2u;
                    }
                    break;
                case 3:
                    force[0] = c->freduction * maxfl;
                    force[1] = c->freduction * maxfr;
                    c->wheel_slip |= 2u;
                    pV = (v135 * 2.0 - maxfl - maxfr) / (maxfr + maxfl);
                    if (&HV(gProgram_state).current_car == c) {
                        v79 = 20.0;
                    } else {
                        v79 = 60.0;
                    }
                    if (v79 <= pV) {
                        if (maxfl > 0.1) {
                            c->new_skidding |= 1u;
                        }
                        if (maxfr > 0.1) {
                            c->new_skidding |= 2u;
                        }
                    }
                    if (IRandomBetween(0, 1)) {
                        if (maxfl > 0.1) {
                            SkidNoise(c, 0, pV, c->material_index[0]);
                        }
                    } else if (maxfr > 0.1) {
                        SkidNoise(c, 1, pV, c->material_index[1]);
                    }
                    break;
                default:
                    break;
            }
            if (c->wheel_slip && c->curvature * c->turn_speed > 0.0 && fabs(v109) > 0.0099999998 && c->curvature * v109 < 0.0 && !c->keys.brake && !c->keys.change_down) {
                c->turn_speed = 0.0;
            }
            v135 = sqrt(v108 * v108 + v98 * v98) / 2.0;
            if (v135 > 0.000099999997) {
                v108 = v108 / (v135 * 2.0);
                v98 = v98 / (v135 * 2.0);
            }
            maxfl = sqrt(force[2]) * c->mu[1] * (fl_oil_factor * v116) * mat_list[c->material_index[2]].tyre_road_friction;
            maxfr = sqrt(force[3]) * c->mu[1] * (fr_oil_factor * v116) * mat_list[c->material_index[3]].tyre_road_friction;
            c->max_force_front = maxfr + maxfl;
            force[2] = v135;
            force[3] = v135;
            v72 = (v135 > maxfl) + 2 * (v135 > maxfr);
            switch (v72) {
                case 1:
                    force[2] = c->freduction * maxfl;
                    force[3] = v135 - force[2] + force[3];
                    if (force[3] > maxfr) {
                        if (maxfr > 0.1) {
                            pV = (force[3] - maxfr) / maxfr;
                            if (&HV(gProgram_state).current_car == c) {
                                v75 = 20.0;
                            } else {
                                v75 = 60.0;
                            }
                            if (v75 <= pV) {
                                c->new_skidding |= 8u;
                            }
                            SkidNoise(c, 3, pV, c->material_index[3]);
                        }
                        force[3] = c->freduction * maxfr;
                        c->wheel_slip |= 1u;
                    }
                    break;
                case 2:
                    force[3] = c->freduction * maxfr;
                    force[2] = v135 - force[3] + force[2];
                    if (force[2] > maxfl) {
                        if (maxfl > 0.1) {
                            pV = (force[2] - maxfl) / maxfl;
                            if (&HV(gProgram_state).current_car == c) {
                                v74 = 20.0;
                            } else {
                                v74 = 60.0;
                            }
                            if (v74 <= pV) {
                                c->new_skidding |= 4u;
                            }
                            SkidNoise(c, 2, pV, c->material_index[2]);
                        }
                        force[2] = c->freduction * maxfl;
                        c->wheel_slip |= 1u;
                    }
                    break;
                case 3:
                    force[2] = c->freduction * maxfl;
                    force[3] = c->freduction * maxfr;
                    c->wheel_slip |= 1u;
                    pV = (v135 * 2.0 - maxfl - maxfr) / (maxfr + maxfl);
                    if (&HV(gProgram_state).current_car == c) {
                        v76 = 20.0;
                    } else {
                        v76 = 60.0;
                    }
                    if (v76 <= pV) {
                        if (maxfl > 0.1) {
                            c->new_skidding |= 4u;
                        }
                        if (maxfr > 0.1) {
                            c->new_skidding |= 8u;
                        }
                    }
                    if (IRandomBetween(0, 1)) {
                        if (maxfl > 0.1) {
                            SkidNoise(c, 2, pV, c->material_index[2]);
                        }
                    } else if (maxfr > 0.1) {
                        SkidNoise(c, 3, pV, c->material_index[3]);
                    }
                    break;
            }
            BrVector3Scale(&v136, &rightplane, v99);
            BrVector3Scale(&a, &v103, v109);
            BrVector3Accumulate(&v136, &a);
            BrVector3Scale(&v123, &rightplane, v98);
            BrVector3Scale(&a, &v103, v108);
            BrVector3Accumulate(&v123, &a);

            rightplane = c->wpos[0];
            rightplane.v[1] = rightplane.v[1] - c->oldd[0];
            BrVector3Sub(&rightplane, &rightplane, &c->cmpos);
            BrVector3Scale(&b, &v136, force[0]);
            BrVector3Accumulate(&B, &b);
            BrVector3Cross(&a, &rightplane, &b);
            BrVector3Accumulate(&f, &a);

            rightplane = c->wpos[1];
            rightplane.v[1] = rightplane.v[1] - c->oldd[1];
            BrVector3Sub(&rightplane, &rightplane, &c->cmpos);
            BrVector3Scale(&b, &v136, force[1]);
            BrVector3Accumulate(&B, &b);
            BrVector3Cross(&a, &rightplane, &b);
            BrVector3Accumulate(&f, &a);

            rightplane = c->wpos[2];
            rightplane.v[1] = rightplane.v[1] - c->oldd[2];
            BrVector3Sub(&rightplane, &rightplane, &c->cmpos);
            BrVector3Scale(&b, &v123, force[2]);
            BrVector3Accumulate(&B, &b);
            BrVector3Cross(&a, &rightplane, &b);
            BrVector3Accumulate(&f, &a);

            rightplane = c->wpos[3];
            rightplane.v[1] = rightplane.v[1] - c->oldd[3];
            BrVector3Sub(&rightplane, &rightplane, &c->cmpos);
            BrVector3Scale(&b, &v123, force[3]);
            BrVector3Accumulate(&B, &b);
            BrVector3Cross(&a, &rightplane, &b);
            BrVector3Accumulate(&f, &a);

        } else {
            c->max_force_front = 0.0;
            c->max_force_rear = 0.0;
            StopSkid(c);
        }
        c->number_of_wheels_on_ground = normnum;
        BrMatrix34ApplyV(&b, &B, mat);
        BrVector3Scale(&rightplane, &f, dt);
        ApplyTorque(c, &rightplane);
        BrVector3Scale(&rightplane, &b, dt / c->M);
        BrVector3Accumulate(&c->v, &rightplane);
        if (c->speed < 0.000099999997
            && ((!c->keys.acc && c->joystick.acc <= 0) || !c->gear)
            && !c->keys.dec
            && c->joystick.dec <= 0
            && c->bounce_rate == 0.0
            && BrVector3Length(&c->omega) < 0.05) {
            if (vol) {
                v73 = c->driver > eDriver_non_car && c->underwater_ability ? 1.0 - (1.0 - vol->gravity_multiplier) * 0.6 : vol->gravity_multiplier;
                friction_number = BrVector3Length(&b) / v73 / HV(gGravity_multiplier);
            } else {
                friction_number = BrVector3Length(&b);
            }
            if (c->M > friction_number || (c->keys.brake && normnum >= 3)) {
                if (stop_timer == 100.0) {
                    stop_timer = 0.0;
                }
                if (stop_timer > 0.5) {
                    BrVector3SetFloat(&c->v, 0.0, 0.0, 0.0);
                    BrVector3SetFloat(&c->omega, 0.0, 0.0, 0.0);
                    stop_timer = 0.5;
                }
            }
        }
        stop_timer = dt + stop_timer;
        if (stop_timer > 1.0) {
            stop_timer = 100.0;
        }
        AddDrag(c, dt);
        if (c->driver >= eDriver_net_human) {
            c->acc_force = -(v136.v[2] * force[0]) - v136.v[2] * force[1];
            // LOG_DEBUG("old %f new %f", old, c->acc_force);
        }
    } else {
        original_CalcForce(c, dt);
    }
}

function_hook_state_t function_hook_state_DoRevs = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(function_hook_state_DoRevs)
static void(__cdecl*original_DoRevs)(tCar_spec *, br_scalar) = (void(__cdecl*)(tCar_spec *, br_scalar))0x0047ef8e;
CARM95_HOOK_FUNCTION(original_DoRevs, DoRevs)
void __cdecl DoRevs(tCar_spec *c, br_scalar dt) {
    br_scalar wheel_spin_force;
    br_scalar ts;
    int revs_increase;
    LOG_TRACE("(%p, %f)", c, dt);

    (void)c;
    (void)dt;
    (void)wheel_spin_force;
    (void)ts;
    (void)revs_increase;

    if (function_hook_state_DoRevs == HOOK_ENABLED) {

        ts = -BrVector3Dot((br_vector3*)c->car_master_actor->t.t.mat.m[2], &c->v);

        if (c->gear) {
            c->target_revs = ts / c->speed_revs_ratio / (double)c->gear;
        } else {
            c->target_revs = 0.0;
        }
        if (c->target_revs < 0.0) {
            c->target_revs = 0.0;
            c->gear = 0;
        }
        if (!c->number_of_wheels_on_ground || ((c->wheel_slip & 2) + 1) != 0 || !c->gear) {
            if (c->number_of_wheels_on_ground) {
                wheel_spin_force = c->force_torque_ratio * c->torque - (double)c->gear * c->acc_force;
            } else {
                wheel_spin_force = c->force_torque_ratio * c->torque;
            }
            if (c->gear) {
                if (c->gear < 2 && (c->keys.dec || c->joystick.dec > 0) && fabs(ts) < 1.0 && c->revs > 1000.0) {
                    c->gear = -c->gear;
                }
            } else {
                if (c->revs > 1000.0 && !c->keys.brake && (c->keys.acc || c->joystick.acc > 0) && !HV(gCountdown)) {
                    if (c->keys.backwards) {
                        c->gear = -1;
                    } else {
                        c->gear = 1;
                    }
                }
                wheel_spin_force = c->force_torque_ratio * c->torque;
            }
            c->revs = wheel_spin_force / c->force_torque_ratio * dt / 0.0002 + c->revs;

            if (c->traction_control && wheel_spin_force > 0.0 && c->revs > c->target_revs && c->gear && c->target_revs > 1000.0) {
                c->revs = c->target_revs;
            }
            if (c->revs <= 0.0) {
                c->revs = 0.0;
            }
        }
        if ((c->wheel_slip & 2) == 0 && c->target_revs > 6000.0 && c->revs > 6000.0 && c->gear < c->max_gear && c->gear > 0 && !c->just_changed_gear) {
            c->gear++;
        }
        if (c->gear > 1 && c->target_revs < 3000.0 && !c->just_changed_gear) {
            c->gear--;
        }
        if (c->revs < 200.0 && c->target_revs < 200.0 && c->gear <= 1 && !c->keys.acc && c->joystick.acc <= 0 && !c->just_changed_gear) {
            c->gear = 0;
        }
        if (c->just_changed_gear && c->revs < 6000.0 && c->revs > 200.0 && (c->gear < 2 || c->revs >= 3000.0)) {
            c->just_changed_gear = 0;
        }
        if (c->revs >= 6000.0 && (c->keys.acc || c->joystick.acc > 0)) {
            c->just_changed_gear = 0;
        }
    } else {
        original_DoRevs(c, dt);
    }
}

function_hook_state_t function_hook_state_ApplyTorque = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(function_hook_state_ApplyTorque)
static void(__cdecl*original_ApplyTorque)(tCar_spec *, br_vector3 *) = (void(__cdecl*)(tCar_spec *, br_vector3 *))0x0047f4f2;
CARM95_HOOK_FUNCTION(original_ApplyTorque, ApplyTorque)
void __cdecl ApplyTorque(tCar_spec *c, br_vector3 *tdt) {
    LOG_TRACE("(%p, %p)", c, tdt);

    (void)c;
    (void)tdt;

    if (function_hook_state_ApplyTorque == HOOK_ENABLED) {
        c->omega.v[0] = tdt->v[0] / c->I.v[0] + c->omega.v[0];
        c->omega.v[1] = tdt->v[1] / c->I.v[1] + c->omega.v[1];
        c->omega.v[2] = tdt->v[2] / c->I.v[2] + c->omega.v[2];
    } else {
        original_ApplyTorque(c, tdt);
    }
}

function_hook_state_t function_hook_state_TranslateCar = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(function_hook_state_TranslateCar)
static void(__cdecl*original_TranslateCar)(tCollision_info *, br_scalar) = (void(__cdecl*)(tCollision_info *, br_scalar))0x0047f55f;
CARM95_HOOK_FUNCTION(original_TranslateCar, TranslateCar)
void __cdecl TranslateCar(tCollision_info *c, br_scalar dt) {
    br_vector3 t;
    LOG_TRACE("(%p, %f)", c, dt);

    (void)c;
    (void)dt;
    (void)t;

    if (function_hook_state_TranslateCar == HOOK_ENABLED) {
        t.v[0] = c->v.v[0] * dt;
        t.v[1] = c->v.v[1] * dt;
        t.v[2] = c->v.v[2] * dt;
        c->car_master_actor->t.t.mat.m[3][0] = c->car_master_actor->t.t.mat.m[3][0] + t.v[0];
        c->car_master_actor->t.t.mat.m[3][1] = c->car_master_actor->t.t.mat.m[3][1] + t.v[1];
        c->car_master_actor->t.t.mat.m[3][2] = c->car_master_actor->t.t.mat.m[3][2] + t.v[2];
    } else {
        original_TranslateCar(c, dt);
    }
}

function_hook_state_t function_hook_state_CollCheck = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(function_hook_state_CollCheck)
static int(__cdecl*original_CollCheck)(tCollision_info *, br_scalar) = (int(__cdecl*)(tCollision_info *, br_scalar))0x0047f5d0;
CARM95_HOOK_FUNCTION(original_CollCheck, CollCheck)
int __cdecl CollCheck(tCollision_info *c, br_scalar dt) {
    br_vector3 a;
    br_vector3 a1;
    br_vector3 aa;
    br_vector3 bb;
    br_vector3 cc;
    br_vector3 pos;
    br_vector3 r[8];
    br_vector3 norm;
    br_vector3 n[8];
    br_vector3 dir;
    br_vector3 tv;
    br_vector3 tv2;
    br_vector3 tau[4];
    br_vector3 old_val;
    br_vector3 ftau;
    br_vector3 max_friction;
    br_vector3 vel;
    br_vector3 p_vel;
    br_vector3 normal_force;
    br_vector3 friction_force;
    br_scalar d[4];
    br_scalar f[4];
    br_scalar total_force;
    br_scalar point_vel;
    br_scalar batwick_length;
    br_matrix4 M;
    br_scalar dist;
    br_scalar min_d;
    br_scalar ts;
    br_scalar ts2;
    br_scalar v_diff;
    br_matrix34 *mat;
    br_matrix34 *oldmat;
    br_matrix34 mat_to_oldmat;
    br_matrix34 oldmat_to_mat;
    br_matrix34 tm;
    int collision;
    br_bounds bnds;
    tFace_ref *f_ref;
    int i;
    int j;
    int l;
    int k;
    int material;
    int noise_defeat;
    static int oldk;
    br_scalar min;
    br_scalar max;
    br_vector3 edges[3];
    br_vector3 corner;
    br_vector3 test_dir;
    br_scalar min_acc;
    br_scalar max_acc;
    br_matrix34 message_mat;
    br_scalar __block0___scale;
    br_scalar __block1___scale;
    LOG_TRACE("(%p, %f)", c, dt);

    (void)c;
    (void)dt;
    (void)a;
    (void)a1;
    (void)aa;
    (void)bb;
    (void)cc;
    (void)pos;
    (void)r;
    (void)norm;
    (void)n;
    (void)dir;
    (void)tv;
    (void)tv2;
    (void)tau;
    (void)old_val;
    (void)ftau;
    (void)max_friction;
    (void)vel;
    (void)p_vel;
    (void)normal_force;
    (void)friction_force;
    (void)d;
    (void)f;
    (void)total_force;
    (void)point_vel;
    (void)batwick_length;
    (void)M;
    (void)dist;
    (void)min_d;
    (void)ts;
    (void)ts2;
    (void)v_diff;
    (void)mat;
    (void)oldmat;
    (void)mat_to_oldmat;
    (void)oldmat_to_mat;
    (void)tm;
    (void)collision;
    (void)bnds;
    (void)f_ref;
    (void)i;
    (void)j;
    (void)l;
    (void)k;
    (void)material;
    (void)noise_defeat;
    (void)oldk;
    (void)min;
    (void)max;
    (void)edges;
    (void)corner;
    (void)test_dir;
    (void)min_acc;
    (void)max_acc;
    (void)message_mat;
    (void)__block0___scale;
    (void)__block1___scale;

    if (function_hook_state_CollCheck == HOOK_ENABLED) {
        tCar_spec* car_spec; // added for readability

        // v34 = 0;
        // v35 = 0;
        // v36 = 0x3F800000;
        // v48 = 0x3F800347;
        car_spec = (tCar_spec*)c;
        mat = &c->car_master_actor->t.t.mat;
        oldmat = &c->oldmat;
        k = 0;
        HV(gMaterial_index) = 0;
        if (c->dt >= 0.0f && HV(gNet_mode) == eNet_mode_host) {
            oldmat = &message_mat;
            GetExpandedMatrix(&message_mat, &c->message.mat);
        }
        if (dt < 0.0f) {
            mat = oldmat;
        }
        BrMatrix34LPInverse(&tm, mat);
        BrMatrix34Mul(&oldmat_to_mat, oldmat, &tm);

        oldmat_to_mat.m[3][0] = oldmat_to_mat.m[3][0] / WORLD_SCALE;
        oldmat_to_mat.m[3][1] = oldmat_to_mat.m[3][1] / WORLD_SCALE;
        oldmat_to_mat.m[3][2] = oldmat_to_mat.m[3][2] / WORLD_SCALE;
        GetNewBoundingBox(&bnds, &c->bounds[2], &oldmat_to_mat);
        for (i = 0; i < 3; ++i) {
            if (c->bounds[2].min.v[i] < bnds.min.v[i]) {
                bnds.min.v[i] = c->bounds[2].min.v[i];
            }
            if (c->bounds[2].max.v[i] > bnds.max.v[i]) {
                bnds.max.v[i] = c->bounds[2].max.v[i];
            }
        }
        a1.v[0] = mat->m[3][0] / WORLD_SCALE;
        a1.v[1] = mat->m[3][1] / WORLD_SCALE;
        a1.v[2] = mat->m[3][2] / WORLD_SCALE;
        BrMatrix34ApplyV(&aa, &bnds.min, mat);
        BrVector3Accumulate(&aa, &a1);
        for (j = 0; j < 3; ++j) {
            edges[j].v[0] = (bnds.max.v[j] - bnds.min.v[j]) * mat->m[j][0];
            edges[j].v[1] = (bnds.max.v[j] - bnds.min.v[j]) * mat->m[j][1];
            edges[j].v[2] = (bnds.max.v[j] - bnds.min.v[j]) * mat->m[j][2];
        }
        for (i = 0; i < 50 && i < c->box_face_end - c->box_face_start; i++) {
            f_ref = &HV(gFace_list__car)[c->box_face_start + i];
            BrVector3Sub(&bb, &aa, &f_ref->v[0]);
            max = BrVector3Dot(&bb, &f_ref->normal);
            min = max;
            for (j = 0; j < 3; ++j) {
                ts = BrVector3Dot(&edges[j], &f_ref->normal);
                if (ts >= 0) {
                    max = max + ts;
                } else {
                    min = min + ts;
                }
            }
            if ((max <= 0.001f || min <= 0.001f) && (max >= -0.001f || min >= -0.001f)) {
                f_ref->flags &= ~0x80u;
                k++;
            } else {
                f_ref->flags |= 0x80u;
            }
        }
        if (k == 0) {
            return 0;
        }
        k = 0;
        BrMatrix34LPInverse(&tm, oldmat);
        BrMatrix34Mul(&mat_to_oldmat, mat, &tm);
        HV(gEliminate_faces) = 1;
        for (i = 0; i < 8 + c->extra_point_num; i++) {
            if (i >= 8) {
                tv = c->extra_points[i - 8];
            } else {
                tv.v[0] = ((i & 2) == 0) * c->bounds[1].min.v[0] + ((i & 2) >> 1) * c->bounds[1].max.v[0];
                tv.v[1] = ((i & 1) == 0) * c->bounds[1].min.v[1] + ((i & 1) >> 0) * c->bounds[1].max.v[1];
                tv.v[2] = ((i & 4) == 0) * c->bounds[1].max.v[2] + ((i & 4) >> 2) * c->bounds[1].min.v[2];
            }
            BrMatrix34ApplyP(&dir, &tv, mat);
            if (dt >= 0.0f) {
                BrMatrix34ApplyP(&a, &tv, oldmat);
            } else {
                BrVector3Scale(&a, &c->pos, WORLD_SCALE);
            }
            BrVector3Sub(&dir, &dir, &a);
            BrVector3Normalise(&normal_force, &dir);
            BrVector3Scale(&normal_force, &normal_force, 0.0072463769f);
            BrVector3Accumulate(&dir, &normal_force);
            material = FindFloorInBoxM2(&a, &dir, &norm, &dist, c);
            if (dist >= 0.0f && dist < 1.0001f) {
                BrVector3Scale(&cc, &c->pos, WORLD_SCALE);
                BrVector3Sub(&cc, &cc, &a);
                FindFloorInBoxM(&a, &cc, &bb, &ts, c);
                if (i < 8 || ts > 1.0f) {
                    BrMatrix34TApplyV(&a, &norm, oldmat);
                    AddCollPoint(dist, &tv, &a, r, n, &dir, k, c);
                    k++;
                    if (HV(gMaterial_index) == 0) {
                        HV(gMaterial_index) = material;
                    }
                }
            }
        }
        HV(gEliminate_faces) = 0;
        if (k < 1) {
            k += BoxFaceIntersect(&c->bounds[1], mat, &mat_to_oldmat, &r[k], &n[k], &d[k], 8 - k, c);
        }
        if (k > 4) {
            k = 4;
        }
        for (i = 0; i < k; i++) {
            if (fabsf(r[i].v[1]) + fabsf(r[i].v[2]) + fabsf(r[i].v[0]) > 500.0f) {
                for (j = i + 1; j < k; j++) {
                    if (fabsf(r[j].v[1]) + fabsf(r[j].v[2]) + fabsf(r[j].v[0]) < 500.0f) {
                        r[i] = r[j];
                        n[i] = n[j];
                        i++;
                    }
                }
                k = i;
                break;
            }
        }
        if (dt >= 0.0f) {
            if (k > 0 && c->collision_flag && k < 4
                && (fabsf(r[0].v[0] - c->old_point.v[0]) > 0.05f
                    || fabsf(r[0].v[1] - c->old_point.v[1]) > 0.05f
                    || fabsf(r[0].v[2] - c->old_point.v[2]) > 0.05f)) {
                r[k] = c->old_point;
                n[k] = c->old_norm;
                k++;
            }
            if (k > 0) {
                c->old_point = r[0];
                c->old_norm = n[0];
                BrMatrix34Copy(mat, oldmat);
                c->omega = c->oldomega;
                BrMatrix34TApplyV(&c->velocity_car_space, &c->v, mat);
                memset(&norm, 0, sizeof(norm));
                collision = 0;
                for (i = 0; i < k; i++) {
                    BrVector3Cross(&tau[i], &r[i], &n[i]);
                    tau[i].v[0] = tau[i].v[0] / c->I.v[0];
                    tau[i].v[1] = tau[i].v[1] / c->I.v[1];
                    tau[i].v[2] = tau[i].v[2] / c->I.v[2];
                    BrVector3Cross(&normal_force, &c->omega, &r[i]);
                    BrVector3Accumulate(&normal_force, &c->velocity_car_space);
                    d[i] = -(BrVector3Dot(&n[i], &normal_force));
                    BrVector3Add(&normal_force, &r[i], &c->cmpos);
                    BrMatrix34ApplyP(&dir, &normal_force, &mat_to_oldmat);
                    BrVector3Sub(&dir, &dir, &normal_force);
                    ts = -(BrVector3Dot(&n[i], &dir) / dt);
                    if (ts > d[i]) {
                        d[i] = ts;
                    }
                    if (d[i] > 0.0f) {
                        collision = 1;
                    }
                }
                if (!collision) {
                    d[0] = 0.5f;
                }
                for (i = 0; i < k; i++) {
                    for (j = 0; j < k; j++) {
                        BrVector3Cross(&normal_force, &tau[j], &r[i]);
                        BrVector3InvScale(&norm, &n[j], c->M);
                        BrVector3Accumulate(&normal_force, &norm);
                        M.m[i][j] = BrVector3Dot(&n[i], &normal_force);
                    }
                }
                switch (k) {
                    case 1:
                        ts = SinglePointColl(f, &M, d);
                        break;
                    case 2:
                        ts = TwoPointColl(f, &M, d, tau, n);
                        break;
                    case 3:
                        d[3] = 0.0f;
                        ts = ThreePointCollRec(f, &M, d, tau, n, c);
                        break;
                    case 4:
                        ts = FourPointColl(f, &M, d, tau, n, c);
                        break;
                    default:
                        break;
                }
                if (k > 3) {
                    k = 3;
                }
                // if (f[0] > 10.0f || f[1] > 10.0f || f[2] > 10.0f) {
                //     v31 = 0;
                // }
                if (fabsf(ts) <= 0.000001f) {
                    BrVector3Set(&c->v, 0.f, 0.f, 0.f);
                    BrVector3Set(&c->omega, 0.f, 0.f, 0.f);
                    BrVector3Set(&c->oldomega, 0.f, 0.f, 0.f);
                    return k;
                }
                BrVector3Set(&p_vel, 0.f, 0.f, 0.f);
                BrVector3Set(&dir, 0.f, 0.f, 0.f);
                BrVector3Set(&friction_force, 0.f, 0.f, 0.f);
                total_force = 0.f;
                for (i = 0; i < k; i++) {
                    if (f[i] < 0.001f) {
                        f[i] = 0.001f;
                    }
                    f[i] = f[i] * 1.001f;
                    BrVector3Scale(&tau[i], &tau[i], f[i]);
                    BrVector3Accumulate(&c->omega, &tau[i]);
                    f[i] = f[i] / c->M;
                    BrVector3Scale(&n[i], &n[i], f[i]);
                    BrVector3Accumulate(&p_vel, &n[i]);
                    BrVector3Add(&bb, &r[i], &c->cmpos);
                    BrVector3Scale(&bb, &bb, f[i]);
                    BrVector3Accumulate(&dir, &bb);
                    total_force = f[i] + total_force;
                }
                if (HV(gPinball_factor) != 0.0f) {
                    BrVector3Scale(&p_vel, &p_vel, HV(gPinball_factor));
                    point_vel = BrVector3LengthSquared(&p_vel);
                    if (point_vel > 10.0f) {
                        noise_defeat = 1;
                        if (c->driver == eDriver_local_human) {
                            DRS3StartSound(HV(gCar_outlet), 9011);
                        } else {
                            DRS3StartSound3D(HV(gCar_outlet), 9011, &c->pos, &HV(gZero_v__car), 1, 255, 0x10000, 0x10000);
                        }
                        if (point_vel > 10000.0f) {
                            BrVector3Normalise(&p_vel, &p_vel);
                            BrVector3Scale(&p_vel, &p_vel, 100);
                        }
                    }
                }
                BrVector3Accumulate(&c->velocity_car_space, &p_vel);
                BrVector3InvScale(&dir, &dir, total_force);
                BrVector3Cross(&tv, &c->omega, &dir);
                BrVector3Accumulate(&tv, &c->velocity_car_space);
                batwick_length = BrVector3Length(&tv);
                if (!c->collision_flag || (c->collision_flag == 1 && oldk < k)) {
                    for (i = 0; i < k; i++) {
                        BrVector3Cross(&vel, &c->omega, &r[i]);
                        BrVector3Accumulate(&vel, &c->velocity_car_space);
                        AddFriction(c, &vel, &n[i], &r[i], f[i], &max_friction);
                        BrVector3Accumulate(&friction_force, &max_friction);
                        BrVector3Accumulate(&c->velocity_car_space, &max_friction);
                    }
                }
                oldk = k;
                BrMatrix34ApplyP(&pos, &dir, &c->car_master_actor->t.t.mat);
                BrVector3InvScale(&pos, &pos, WORLD_SCALE);
                noise_defeat = 0;
                BrVector3Add(&normal_force, &friction_force, &p_vel);
                BrMatrix34ApplyV(&norm, &normal_force, mat);
                min = dt * 90.0f / 10.0f;
                max = dt * 110.0f / 10.0f;
                if (c->last_special_volume != NULL) {
                    min *= c->last_special_volume->gravity_multiplier;
                    max *= c->last_special_volume->gravity_multiplier;
                }
                if (BrVector3LengthSquared(&c->velocity_car_space) < 0.05f
                    && 0.1f * total_force > BrVector3Dot(&c->omega, &tv)
                    && k >= 3
                    && norm.v[1] > min
                    && norm.v[1] < max) {
                    if (c->driver <= eDriver_non_car || fabsf(normal_force.v[2]) <= total_force * 0.9f) {
                        BrVector3Set(&c->v, 0.f, 0.f, 0.f);
                        BrVector3Set(&norm, 0.f, 0.f, 0.f);
                        BrVector3Set(&normal_force, 0.f, 0.f, 0.f);
                        BrVector3Set(&c->omega, 0.f, 0.f, 0.f);
                        BrVector3Set(&c->oldomega, 0.f, 0.f, 0.f);
                        if (c->driver <= eDriver_non_car || car_spec->max_force_rear == 0.0f) {
                            if (c->driver <= eDriver_non_car) {
                                PipeSingleNonCar(c);
                            }
                            c->doing_nothing_flag = 1;
                        }
                    } else {
                        BrVector3SetFloat(&tv2, 0.0f, -1.0f, 0.0f);
                        bb.v[0] = mat->m[1][2] * tv2.v[1] - mat->m[1][1] * tv2.v[2];
                        bb.v[1] = mat->m[1][0] * tv2.v[2] - mat->m[1][2] * tv2.v[0];
                        bb.v[2] = mat->m[1][1] * tv2.v[0] - mat->m[1][0] * tv2.v[1];
                        if (BrVector3Dot(&bb, (br_vector3*)&mat->m[0][1]) <= 0.0f) {
                            c->omega.v[0] = -0.5f;
                        } else {
                            c->omega.v[0] = 0.5f;
                        }
                    }
                }
                BrVector3Accumulate(&c->v, &norm);
                if (c->driver >= eDriver_net_human) {
                    BrVector3Scale(&normal_force, &normal_force, HV(gDefensive_powerup_factor)[car_spec->power_up_levels[0]]);
                }
                if (c->driver < eDriver_net_human) {
                    BrVector3Scale(&normal_force, &normal_force, 0.01f);
                } else {
                    BrVector3Scale(&normal_force, &normal_force, 0.75f);
                }
                if (CAR(c)->invulnerable
                    || (c->driver < eDriver_net_human && (c->driver != eDriver_oppo || PointOutOfSight(&c->pos, 150.0f)))
                    || ((v_diff = (car_spec->pre_car_col_velocity.v[1] - c->v.v[1]) * HV(gDefensive_powerup_factor)[car_spec->power_up_levels[0]]) >= -20.0f)
                    || CAR(c)->number_of_wheels_on_ground >= 3) {
                    CrushAndDamageCar(CAR(c), &dir, &normal_force, NULL);
                } else {
                    // Cops Special Forces is always stolen if destroyed!
                    if (c->driver == eDriver_oppo && c->index == 4 && v_diff < -40.0f) {
                        KnackerThisCar(CAR(c));
                        StealCar(CAR(c));
                        v_diff = v_diff * 5.0f;
                    }
                    for (i = 0; i < CAR(c)->car_actor_count; i++) {
                        ts2 = (v_diff + 20.0f) * -0.01f;
                        TotallySpamTheModel(CAR(c), i, CAR(c)->car_model_actors[i].actor, &CAR(c)->car_model_actors[i].crush_data, ts2);
                    }
                    for (i = 0; i < COUNT_OF(CAR(c)->damage_units); i++) {
                        DamageUnit(CAR(c), i, IRandomPosNeg(5) + (v_diff + 20.0f) * -1.5f);
                    }
                }
                if (!noise_defeat) {
                    CrashNoise(&norm, &pos, HV(gMaterial_index));
                    ScrapeNoise(batwick_length, &pos, HV(gMaterial_index));
                }
                BrVector3InvScale(&tv, &tv, WORLD_SCALE);
                BrMatrix34ApplyV(&bb, &tv, &c->car_master_actor->t.t.mat);
                BrMatrix34ApplyV(&norm, &p_vel, &c->car_master_actor->t.t.mat);
                CreateSparks(&pos, &bb, &norm, HV(gCurrent_race).material_modifiers[HV(gMaterial_index)].sparkiness, car_spec);
            }
            return k;
        } else {
            if (k != 0) {
                c->old_point = r[0];
                c->old_norm = n[0];
            }
            return k;
        }
    } else {
        return original_CollCheck(c, dt);
    }
}

function_hook_state_t function_hook_state_AddFriction = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(function_hook_state_AddFriction)
static br_scalar(__cdecl*original_AddFriction)(tCollision_info *, br_vector3 *, br_vector3 *, br_vector3 *, br_scalar, br_vector3 *) = (br_scalar(__cdecl*)(tCollision_info *, br_vector3 *, br_vector3 *, br_vector3 *, br_scalar, br_vector3 *))0x00481cb9;
CARM95_HOOK_FUNCTION(original_AddFriction, AddFriction)
br_scalar __cdecl AddFriction(tCollision_info *c, br_vector3 *vel, br_vector3 *normal_force, br_vector3 *pos, br_scalar total_force, br_vector3 *max_friction) {
    br_vector3 norm;
    br_vector3 tv;
    br_vector3 ftau;
    br_scalar ts;
    br_scalar point_vel;
    LOG_TRACE("(%p, %p, %p, %p, %f, %p)", c, vel, normal_force, pos, total_force, max_friction);

    (void)c;
    (void)vel;
    (void)normal_force;
    (void)pos;
    (void)total_force;
    (void)max_friction;
    (void)norm;
    (void)tv;
    (void)ftau;
    (void)ts;
    (void)point_vel;

    if (function_hook_state_AddFriction == HOOK_ENABLED) {
        ts = BrVector3Dot(normal_force, vel) / BrVector3Dot(normal_force, normal_force);
        BrVector3Scale(&tv, normal_force, ts);
        BrVector3Sub(vel, vel, &tv);
        point_vel = total_force * 0.35f * HV(gCurrent_race).material_modifiers[HV(gMaterial_index)].car_wall_friction;
        ts = BrVector3Length(vel);
        if (ts < 0.0001f) {
            BrVector3Set(max_friction, 0.f, 0.f, 0.f);
            return 0.0;
        }
        BrVector3InvScale(max_friction, vel, -ts);
        BrVector3Cross(&ftau, pos, max_friction);
        BrVector3Scale(&ftau, &ftau, c->M);
        ftau.v[0] = ftau.v[0] / c->I.v[0];
        ftau.v[1] = ftau.v[1] / c->I.v[1];
        ftau.v[2] = ftau.v[2] / c->I.v[2];
        ts = 1.0 / c->M;
        norm.v[0] = pos->v[2] * ftau.v[1] - pos->v[1] * ftau.v[2];
        norm.v[1] = pos->v[0] * ftau.v[2] - pos->v[2] * ftau.v[0];
        norm.v[2] = pos->v[1] * ftau.v[0] - pos->v[0] * ftau.v[1];
        ts = max_friction->v[0] * norm.v[0] + max_friction->v[1] * norm.v[1] + max_friction->v[2] * norm.v[2] + ts;
        if (fabsf(ts) <= 0.0001f) {
            ts = 0.0f;
        } else {
            ts = -BrVector3Dot(max_friction, vel) / ts;
        }
        if (ts > point_vel) {
            ts = point_vel;
        }
        BrVector3Scale(max_friction, max_friction, ts);
        BrVector3Cross(&tv, pos, max_friction);
        BrVector3Scale(&tv, &tv, c->M);
        ApplyTorque((tCar_spec*)c, &tv);
        return point_vel;
    } else {
        return original_AddFriction(c, vel, normal_force, pos, total_force, max_friction);
    }
}

function_hook_state_t function_hook_state_AddFrictionCarToCar = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(function_hook_state_AddFrictionCarToCar)
static void(__cdecl*original_AddFrictionCarToCar)(tCollision_info *, tCollision_info *, br_vector3 *, br_vector3 *, br_vector3 *, br_vector3 *, br_vector3 *, br_scalar, br_vector3 *) = (void(__cdecl*)(tCollision_info *, tCollision_info *, br_vector3 *, br_vector3 *, br_vector3 *, br_vector3 *, br_vector3 *, br_scalar, br_vector3 *))0x0049231c;
CARM95_HOOK_FUNCTION(original_AddFrictionCarToCar, AddFrictionCarToCar)
void __cdecl AddFrictionCarToCar(tCollision_info *car1, tCollision_info *car2, br_vector3 *vel1, br_vector3 *vel2, br_vector3 *normal_force1, br_vector3 *pos1, br_vector3 *pos2, br_scalar total_force, br_vector3 *max_friction) {
    br_vector3 v_diff1;
    br_vector3 v_diff2;
    br_vector3 tau1;
    br_vector3 tau2;
    br_vector3 tv;
    br_vector3 tv2;
    br_vector3 vel2_in_frame_1;
    br_scalar ts;
    br_scalar ts2;
    br_scalar v_diff;
    br_scalar stopping_impulse;
    br_scalar total_friction;
    int i;
    LOG_TRACE("(%p, %p, %p, %p, %p, %p, %p, %f, %p)", car1, car2, vel1, vel2, normal_force1, pos1, pos2, total_force, max_friction);

    (void)car1;
    (void)car2;
    (void)vel1;
    (void)vel2;
    (void)normal_force1;
    (void)pos1;
    (void)pos2;
    (void)total_force;
    (void)max_friction;
    (void)v_diff1;
    (void)v_diff2;
    (void)tau1;
    (void)tau2;
    (void)tv;
    (void)tv2;
    (void)vel2_in_frame_1;
    (void)ts;
    (void)ts2;
    (void)v_diff;
    (void)stopping_impulse;
    (void)total_friction;
    (void)i;

    if (function_hook_state_AddFrictionCarToCar == HOOK_ENABLED) {
        BrMatrix34TApplyV(&tv, vel2, &car2->oldmat);
        BrMatrix34ApplyV(&vel2_in_frame_1, &tv, &car1->oldmat);
        BrVector3Sub(&v_diff1, &vel2_in_frame_1, vel1);
        ts = BrVector3LengthSquared(normal_force1);
        ts2 = BrVector3Dot(normal_force1, &v_diff1) / ts;
        BrVector3Scale(&tv, normal_force1, ts2);
        BrVector3Sub(&v_diff1, &v_diff1, &tv);
        v_diff = BrVector3Length(&v_diff1);
        if (v_diff < 0.01f) {
            max_friction->v[0] = 0.0f;
            max_friction->v[1] = 0.0f;
            max_friction->v[2] = 0.0f;
        } else {
            BrVector3InvScale(&v_diff1, &v_diff1, v_diff);
            BrMatrix34ApplyV(&tv, &v_diff1, &car1->oldmat);
            BrMatrix34TApplyV(&v_diff2, &tv, &car2->oldmat);
            BrVector3Negate(&v_diff2, &v_diff2);
            BrVector3Cross(&tau1, pos1, &v_diff1);
            BrVector3Cross(&tau2, pos2, &v_diff2);
            for (i = 0; i < 3; ++i) {
                tau1.v[i] /= car1->I.v[i];
                tau2.v[i] /= car2->I.v[i];
            }
            BrVector3Cross(&tv, &tau1, pos1);
            BrVector3Cross(&tv2, &tau2, pos2);
            ts = BrVector3Dot(&tv, &v_diff1) + BrVector3Dot(&tv2, &v_diff2) + 1.0 / car2->M + 1.0 / car1->M;
            if (ts < 0.0001f) {
                max_friction->v[0] = 0.0;
                max_friction->v[1] = 0.0;
                max_friction->v[2] = 0.0;
            } else {
                stopping_impulse = v_diff / ts;
                total_friction = total_force * 0.35f;
                if (stopping_impulse < total_friction) {
                    total_friction = stopping_impulse;
                }
                if (!car1->infinite_mass) {
                    BrVector3Scale(&tau1, &tau1, total_friction);
                    BrVector3Accumulate(&car1->omega, &tau1);
                }
                if (!car2->infinite_mass) {
                    BrVector3Scale(&tau2, &tau2, total_friction);
                    BrVector3Accumulate(&car2->omega, &tau2);
                }
                BrVector3Scale(max_friction, &v_diff1, total_friction);
            }
        }
    } else {
        original_AddFrictionCarToCar(car1, car2, vel1, vel2, normal_force1, pos1, pos2, total_force, max_friction);
    }
}

function_hook_state_t function_hook_state_ScrapeNoise = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(function_hook_state_ScrapeNoise)
static void(__cdecl*original_ScrapeNoise)(br_scalar, br_vector3 *, int) = (void(__cdecl*)(br_scalar, br_vector3 *, int))0x00482070;
CARM95_HOOK_FUNCTION(original_ScrapeNoise, ScrapeNoise)
void __cdecl ScrapeNoise(br_scalar vel, br_vector3 *position, int material) {
    tS3_volume vol;
    static tS3_sound_tag scrape_tag;
    static tS3_volume last_scrape_vol;
    br_vector3 velocity;
    br_vector3 position_in_br;
    LOG_TRACE("(%f, %p, %d)", vel, position, material);

    (void)vel;
    (void)position;
    (void)material;
    (void)vol;
    (void)scrape_tag;
    (void)last_scrape_vol;
    (void)velocity;
    (void)position_in_br;

    if (function_hook_state_ScrapeNoise == HOOK_ENABLED) {
        vol = vel * 7.0;
        if (HV(gCurrent_race).material_modifiers[material].scrape_noise_index == -1) {
            return;
        }
        if ((scrape_tag && DRS3SoundStillPlaying(scrape_tag)) || vol <= 30) {
            if (last_scrape_vol < vol) {
                DRS3ChangeVolume(scrape_tag, vol);
                last_scrape_vol = vol;
            }
        } else {
            BrVector3Set(&velocity, 0.f, 0.f, 0.f);
            scrape_tag = DRS3StartSound3D(
                    HV(gCar_outlet),
                    HV(gMetal_scrape_sound_id__car)[IRandomBetween(0, COUNT_OF(HV(gMetal_scrape_sound_id__car)) - 1)],
                    position,
                    &velocity,
                    1,
                    vol,
                    IRandomBetween(49152, 81920),
                    0x10000);
            last_scrape_vol = vol;
        }
    } else {
        original_ScrapeNoise(vel, position, material);
    }
}

function_hook_state_t function_hook_state_SkidNoise = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(function_hook_state_SkidNoise)
static void(__cdecl*original_SkidNoise)(tCar_spec *, int, br_scalar, int) = (void(__cdecl*)(tCar_spec *, int, br_scalar, int))0x0048216d;
CARM95_HOOK_FUNCTION(original_SkidNoise, SkidNoise)
void __cdecl SkidNoise(tCar_spec *pC, int pWheel_num, br_scalar pV, int material) {
    br_vector3 pos;
    br_vector3 world_pos;
    br_vector3 wv;
    br_vector3 wvw;
    br_scalar ts;
    static tS3_volume last_skid_vol[2];
    int i;
    LOG_TRACE("(%p, %d, %f, %d)", pC, pWheel_num, pV, material);

    (void)pC;
    (void)pWheel_num;
    (void)pV;
    (void)material;
    (void)pos;
    (void)world_pos;
    (void)wv;
    (void)wvw;
    (void)ts;
    (void)last_skid_vol;
    (void)i;

    if (function_hook_state_SkidNoise == HOOK_ENABLED) {
        i = IRandomBetween(0, 1);
        if (HV(gCurrent_race).material_modifiers[material].tyre_noise_index == -1) {
            return;
        }
        if (IRandomBetween(0, 4) != 0) {
            return;
        }

        last_skid_vol[i] = pV * 10.0;
        if ((pWheel_num & 1) != 0) {
            pos.v[0] = pC->bounds[1].max.v[0];
        } else {
            pos.v[0] = pC->bounds[1].min.v[0];
        }
        pos.v[1] = pC->wpos[pWheel_num].v[1] - pC->oldd[pWheel_num];
        pos.v[2] = pC->wpos[pWheel_num].v[2];
        BrMatrix34ApplyP(&world_pos, &pos, &pC->car_master_actor->t.t.mat);
        BrVector3InvScale(&world_pos, &world_pos, WORLD_SCALE);
        if (!DRS3SoundStillPlaying(HV(gSkid_tag)[i]) || (pC->driver == eDriver_local_human && HV(gLast_car_to_skid)[i] != pC)) {
            HV(gSkid_tag)[i] = DRS3StartSound3D(
                    HV(gCar_outlet),
                    IRandomBetween(0, 4) + 9000,
                    &world_pos,
                    &pC->velocity_bu_per_sec,
                    1,
                    last_skid_vol[i],
                    IRandomBetween(49152, 81920),
                    0x10000);
            HV(gLast_car_to_skid)[i] = pC;
        }
        if (HV(gCurrent_race).material_modifiers[material].smoke_type == 1) {
            BrVector3Cross(&wv, &pC->omega, &pos);
            BrVector3Add(&wv, &wv, &pC->velocity_car_space);
            ts = -(BrVector3Dot(&wv, &pC->road_normal));
            BrVector3Scale(&wvw, &pC->road_normal, ts);
            BrVector3Add(&wv, &wv, &wvw);
            BrMatrix34ApplyV(&wvw, &wv, &pC->car_master_actor->t.t.mat);
            CreatePuffOfSmoke(&world_pos, &wvw, pV / 25.0, 1.0, 4, pC);
        }
    } else {
        original_SkidNoise(pC, pWheel_num, pV, material);
    }
}

function_hook_state_t function_hook_state_StopSkid = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(function_hook_state_StopSkid)
static void(__cdecl*original_StopSkid)(tCar_spec *) = (void(__cdecl*)(tCar_spec *))0x00482458;
CARM95_HOOK_FUNCTION(original_StopSkid, StopSkid)
void __cdecl StopSkid(tCar_spec *pC) {
    LOG_TRACE("(%p)", pC);

    (void)pC;

    if (function_hook_state_StopSkid == HOOK_ENABLED) {
        if (HV(gLast_car_to_skid)[0] == pC) {
            DRS3StopSound(HV(gSkid_tag)[0]);
        }
        if (HV(gLast_car_to_skid)[1] == pC) {
            DRS3StopSound(HV(gSkid_tag)[1]);
        }
    } else {
        original_StopSkid(pC);
    }
}

function_hook_state_t function_hook_state_CrashNoise = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(function_hook_state_CrashNoise)
static void(__cdecl*original_CrashNoise)(br_vector3 *, br_vector3 *, int) = (void(__cdecl*)(br_vector3 *, br_vector3 *, int))0x0048249d;
CARM95_HOOK_FUNCTION(original_CrashNoise, CrashNoise)
void __cdecl CrashNoise(br_vector3 *pForce, br_vector3 *position, int material) {
    static tS3_sound_tag crunch_tag;
    static tS3_volume last_crunch_vol;
    tS3_volume vol;
    br_vector3 velocity;
    LOG_TRACE("(%p, %p, %d)", pForce, position, material);

    (void)pForce;
    (void)position;
    (void)material;
    (void)crunch_tag;
    (void)last_crunch_vol;
    (void)vol;
    (void)velocity;

    if (function_hook_state_CrashNoise == HOOK_ENABLED) {
        vol = 60.f * BrVector3Length(pForce);
        if (HV(gCurrent_race).material_modifiers[material].crash_noise_index != -1) {
            if (vol >= 256) {
                vol = 255;
            }
            if (crunch_tag == 0 || (!DRS3SoundStillPlaying(crunch_tag) && vol > 30)) {
                last_crunch_vol = vol;
                (void)last_crunch_vol;
                BrVector3Set(&velocity, 0.f, 0.f, 0.f);
                crunch_tag = DRS3StartSound3D(HV(gCar_outlet),
                                              HV(gMetal_crunch_sound_id__car)[IRandomBetween(0, COUNT_OF(HV(gMetal_crunch_sound_id__car)) - 1)],
                                              position, &velocity, 1, vol, IRandomBetween(49152, 81920), 0x10000);
            }
        }
    } else {
        original_CrashNoise(pForce, position, material);
    }
}

function_hook_state_t function_hook_state_CrushAndDamageCar = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(function_hook_state_CrushAndDamageCar)
static void(__cdecl*original_CrushAndDamageCar)(tCar_spec *, br_vector3 *, br_vector3 *, tCar_spec *) = (void(__cdecl*)(tCar_spec *, br_vector3 *, br_vector3 *, tCar_spec *))0x004825a8;
CARM95_HOOK_FUNCTION(original_CrushAndDamageCar, CrushAndDamageCar)
void __cdecl CrushAndDamageCar(tCar_spec *c, br_vector3 *pPosition, br_vector3 *pForce_car_space, tCar_spec *car2) {
    br_vector3 force;
    br_vector3 force2;
    br_vector3 position;
    br_vector3 pos_w;
    br_vector3 car_to_cam;
    br_vector3 force_for_bodywork;
    br_scalar ts;
    int i;
    br_matrix34 m;
    br_scalar fudge_multiplier;
    LOG_TRACE("(%p, %p, %p, %p)", c, pPosition, pForce_car_space, car2);

    (void)c;
    (void)pPosition;
    (void)pForce_car_space;
    (void)car2;
    (void)force;
    (void)force2;
    (void)position;
    (void)pos_w;
    (void)car_to_cam;
    (void)force_for_bodywork;
    (void)ts;
    (void)i;
    (void)m;
    (void)fudge_multiplier;

    if (function_hook_state_CrushAndDamageCar == HOOK_ENABLED) {
        if (car2 != NULL) {
            car2->who_last_hit_me = c;
            c->who_last_hit_me = car2;
        }

        if (c->driver == eDriver_non_car_unused_slot || c->driver == eDriver_non_car) {
            return;
        }
        fudge_multiplier = HV(gNet_mode) == eNet_mode_none || HV(gNet_softness)[HV(gCurrent_net_game)->type] == 1.0f ? 1.0f : HV(gNet_softness)[HV(gCurrent_net_game)->type];
        BrVector3Sub(&car_to_cam, &c->pos, (br_vector3*)HV(gCamera_to_world).m[3]);
        ts = BrVector3LengthSquared(&car_to_cam);
        if (c->driver == eDriver_oppo && ts > 200.0f) {
            return;
        }
        if (car2 != NULL) {
            if (car2->driver > eDriver_non_car) {
                TwoCarsHitEachOther(c, car2);
            }
            if (c->driver >= eDriver_net_human) {
                fudge_multiplier = HV(gDefensive_powerup_factor)[c->power_up_levels[0]] * 1.2f * fudge_multiplier;
            }
            if (car2->driver >= eDriver_net_human) {
                if (HV(gNet_mode) != eNet_mode_none
                    && (HV(gCurrent_net_game)->type == eNet_game_type_fight_to_death || HV(gCurrent_net_game)->type == eNet_game_type_car_crusher)) {
                    fudge_multiplier = HV(gOffensive_powerup_factor)[car2->power_up_levels[2]] * HV(gNet_offensive)[HV(gCurrent_net_game)->type] * car2->damage_multiplier * fudge_multiplier;
                } else {
                    fudge_multiplier = HV(gOffensive_powerup_factor)[car2->power_up_levels[2]] * car2->damage_multiplier * fudge_multiplier;
                }
            }
            if (c->driver == eDriver_oppo && car2->driver == eDriver_oppo) {
                fudge_multiplier = fudge_multiplier * 0.2f;
            }
            if (car2->driver <= eDriver_non_car) {
                car2 = NULL;
            } else {
                fudge_multiplier /= ((car2->car_model_actors[car2->principal_car_actor].crush_data.softness_factor + 0.7f) / 0.7f);
            }
        }
        BrVector3InvScale(&position, pPosition, WORLD_SCALE);
        BrVector3Scale(&force, pForce_car_space, fudge_multiplier * 0.03f);
        ts = BrVector3LengthSquared(&force);
        if (c->driver <= eDriver_non_car || !c->invulnerable) {
            c->damage_magnitude_accumulator += ts;
        }
        if (c->driver < eDriver_net_human) {
            BrVector3Scale(&force_for_bodywork, &force, 1.5f);
        } else {
            if (c->collision_mass_multiplier != 1.0) {
                BrVector3InvScale(&force, &force, c->collision_mass_multiplier);
            }
            BrVector3Scale(&force_for_bodywork, &force, 0.5f);
            if (c->driver == eDriver_local_human) {
                DoPratcamHit(&force);
            }
        }
        if (HV(gNet_mode) == eNet_mode_host && (HV(gCurrent_net_game)->type == eNet_game_type_tag || HV(gCurrent_net_game)->type == eNet_game_type_foxy) && car2 != NULL
            && c->driver >= eDriver_net_human && car2->driver >= eDriver_net_human) {
            if (HV(gNet_players)[HV(gIt_or_fox)].car == c && car2->knackered) {
                CarInContactWithItOrFox(NetPlayerFromCar(car2));
            } else if (HV(gNet_players)[HV(gIt_or_fox)].car == car2 && !c->knackered) {
                CarInContactWithItOrFox(NetPlayerFromCar(c));
            }
        }
        if (HV(gNet_mode) != eNet_mode_client || car2 == NULL) {
            DamageSystems(c, &position, &force, car2 != NULL);
        }
        if (c->driver <= eDriver_non_car || !c->invulnerable) {
            for (i = 0; i < c->car_actor_count; i++) {
                if (c->car_model_actors[i].min_distance_squared != -1.0f || (pForce_car_space->v[1] >= 0.0f && pForce_car_space->v[2] >= 0.0f)) {
                    CrushModel(c, i, c->car_model_actors[i].actor, &position, &force_for_bodywork, &c->car_model_actors[i].crush_data);
                }
            }
            if (car2 && car2->driver == eDriver_local_human && ts > 0.003f) {
                PipeSingleCarIncident(ts, c, &position);
            }
            if (!car2 && c->driver == eDriver_local_human && ts > 0.003f) {
                BrMatrix34Copy(&m, &c->car_master_actor->t.t.mat);
                m.m[3][0] /= WORLD_SCALE;
                m.m[3][1] /= WORLD_SCALE;
                m.m[3][2] /= WORLD_SCALE;
                BrMatrix34ApplyP(&pos_w, &position, &m);
                PipeSingleWallIncident(ts, &pos_w);
            }
        }
        if (car2 != NULL && car2->driver == eDriver_local_human && ts > 0.003f) {
            PipeSingleCarIncident(ts, c, &position);
        }
        if (car2 == NULL && c->driver == eDriver_local_human && ts > 0.003f) {
            BrMatrix34Copy(&m, &c->car_master_actor->t.t.mat);
            m.m[3][0] /= WORLD_SCALE;
            m.m[3][1] /= WORLD_SCALE;
            m.m[3][2] /= WORLD_SCALE;
            BrMatrix34ApplyP(&pos_w, &position, &m);
            PipeSingleWallIncident(ts, &pos_w);
        }
    } else {
        original_CrushAndDamageCar(c, pPosition, pForce_car_space, car2);
    }
}

function_hook_state_t function_hook_state_ExpandBoundingBox = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(function_hook_state_ExpandBoundingBox)
static int(__cdecl*original_ExpandBoundingBox)(tCar_spec *) = (int(__cdecl*)(tCar_spec *))0x00482c00;
CARM95_HOOK_FUNCTION(original_ExpandBoundingBox, ExpandBoundingBox)
int __cdecl ExpandBoundingBox(tCar_spec *c) {
    br_scalar min_z;
    br_scalar max_z;
    br_scalar dist;
    br_vector3 tv;
    br_vector3 old_pos;
    int l;
    br_matrix34 mat;
    LOG_TRACE("(%p)", c);

    (void)c;
    (void)min_z;
    (void)max_z;
    (void)dist;
    (void)tv;
    (void)old_pos;
    (void)l;
    (void)mat;

    if (function_hook_state_ExpandBoundingBox == HOOK_ENABLED) {
        l = 0;
        min_z = c->bounds[1].min.v[2];
        max_z = c->bounds[1].max.v[2];
        old_pos = *(br_vector3*)&c->oldmat.m[3][0];
        CrushBoundingBox(c, 0);
        for (l = 0; l < 5; l++) {
            if (TestForCarInSensiblePlace(c)) {
                break;
            }
            if (c->old_point.v[2] <= 0.0f) {
                dist = min_z - c->bounds[1].min.v[2];
            } else {
                dist = c->bounds[1].max.v[2] - max_z;
            }
            if (dist >= 0.0f) {
                dist += 0.005f;
                BrVector3Scale(&c->old_norm, &c->old_norm, dist);
                BrMatrix34ApplyV(&tv, &c->old_norm, &c->car_master_actor->t.t.mat);
                c->oldmat.m[3][0] += tv.v[0];
                c->oldmat.m[3][1] += tv.v[1];
                c->oldmat.m[3][2] += tv.v[2];
                l++;
            } else {
                l = 5;
            }
        }
        if (l < 5) {
            return 1;
        }
        *(br_vector3*)&c->oldmat.m[3][0] = old_pos;
        c->bounds[1].min.v[2] = min_z;
        c->bounds[1].max.v[2] = max_z;
        if (c->driver == eDriver_local_human) {
            NewTextHeadupSlot(4, 0, 1000, -4, GetMiscString(6));
        }
        return 0;
    } else {
        return original_ExpandBoundingBox(c);
    }
}

function_hook_state_t function_hook_state_CrushBoundingBox = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(function_hook_state_CrushBoundingBox)
static void(__cdecl*original_CrushBoundingBox)(tCar_spec *, int) = (void(__cdecl*)(tCar_spec *, int))0x00482dee;
CARM95_HOOK_FUNCTION(original_CrushBoundingBox, CrushBoundingBox)
void __cdecl CrushBoundingBox(tCar_spec *c, int crush_only) {
    br_vector3 min;
    br_vector3 max;
    int i;
    br_actor *actor;
    LOG_TRACE("(%p, %d)", c, crush_only);

    (void)c;
    (void)crush_only;
    (void)min;
    (void)max;
    (void)i;
    (void)actor;

    if (function_hook_state_CrushBoundingBox == HOOK_ENABLED) {
        if (c == NULL) {
            return;
        }
        actor = c->car_model_actors[c->principal_car_actor].actor;
        max.v[0] = c->wpos[2].v[2] - c->non_driven_wheels_circum / 6.2f;
        min.v[0] = c->driven_wheels_circum / 6.2f + c->wpos[0].v[2];
        max.v[0] /= WORLD_SCALE;
        min.v[0] /= WORLD_SCALE;
        for (i = 0; i < actor->model->nvertices; i++) {
            if (actor->model->vertices[i].p.v[2] < max.v[0]) {
                max.v[0] = actor->model->vertices[i].p.v[2];
            }
            if (actor->model->vertices[i].p.v[2] > min.v[0]) {
                min.v[0] = actor->model->vertices[i].p.v[2];
            }
        }
        max.v[0] *= WORLD_SCALE;
        min.v[0] *= WORLD_SCALE;
        if (crush_only) {
            if (c->bounds[1].min.v[2] > max.v[0]) {
                max.v[0] = c->bounds[1].min.v[2];
            }
            if (c->bounds[1].max.v[2] < min.v[0]) {
                min.v[0] = c->bounds[1].max.v[2];
            }
        } else {
            if (c->max_bounds[1].min.v[2] > max.v[0]) {
                max.v[0] = c->max_bounds[1].min.v[2];
            }
            if (c->max_bounds[1].max.v[2] < min.v[0]) {
                min.v[0] = c->max_bounds[1].max.v[2];
            }
        }
        c->bounds[1].min.v[2] = max.v[0];
        c->bounds[1].max.v[2] = min.v[0];
        for (i = 0; i < c->extra_point_num; i++) {
            if (c->max_bounds[1].max.v[2] + 0.01f >= c->original_extra_points_z[i] && c->max_bounds[1].min.v[2] - 0.01f <= c->original_extra_points_z[i]) {
                if (c->original_extra_points_z[i] > min.v[0]) {
                    c->extra_points[i].v[2] = min.v[0];
                } else if (c->original_extra_points_z[i] >= max.v[0]) {
                    c->extra_points[i].v[2] = c->original_extra_points_z[i];
                } else {
                    c->extra_points[i].v[2] = max.v[0];
                }
                if (c->extra_points[i].v[2] > min.v[0]) {
                    c->extra_points[i].v[2] = min.v[0];
                }
                if (c->extra_points[i].v[2] < max.v[0]) {
                    c->extra_points[i].v[2] = max.v[0];
                }
            } else {
                c->extra_points[i].v[2] = c->original_extra_points_z[i];
            }
        }
    } else {
        original_CrushBoundingBox(c, crush_only);
    }
}

function_hook_state_t function_hook_state_AddCollPoint = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(function_hook_state_AddCollPoint)
static void(__cdecl*original_AddCollPoint)(br_scalar, br_vector3 *, br_vector3 *, br_vector3 *, br_vector3 *, br_vector3 *, int, tCollision_info *) = (void(__cdecl*)(br_scalar, br_vector3 *, br_vector3 *, br_vector3 *, br_vector3 *, br_vector3 *, int, tCollision_info *))0x00483152;
CARM95_HOOK_FUNCTION(original_AddCollPoint, AddCollPoint)
void __cdecl AddCollPoint(br_scalar dist, br_vector3 *p, br_vector3 *norm, br_vector3 *r, br_vector3 *n, br_vector3 *dir, int num, tCollision_info *c) {
    static br_scalar d[4];
    int i;
    int furthest;
    LOG_TRACE("(%f, %p, %p, %p, %p, %p, %d, %p)", dist, p, norm, r, n, dir, num, c);

    (void)dist;
    (void)p;
    (void)norm;
    (void)r;
    (void)n;
    (void)dir;
    (void)num;
    (void)c;
    (void)d;
    (void)i;
    (void)furthest;

    if (function_hook_state_AddCollPoint == HOOK_ENABLED) {
        if (num < 4) {
            d[num] = dist;
            n[num] = *norm;
            BrVector3Sub(&r[num], p, &c->cmpos);
            return;
        }
        furthest = 0;
        for (i = 1; i < 4; i++) {
            if (d[furthest] < d[i]) {
                furthest = i;
            }
        }
        if (d[furthest] >= dist) {
            num = furthest;
            d[num] = dist;
            n[num] = *norm;
            BrVector3Sub(&r[num], p, &c->cmpos);
        }
    } else {
        original_AddCollPoint(dist, p, norm, r, n, dir, num, c);
    }
}

function_hook_state_t function_hook_state_SinglePointColl = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(function_hook_state_SinglePointColl)
static br_scalar(__cdecl*original_SinglePointColl)(br_scalar *, br_matrix4 *, br_scalar *) = (br_scalar(__cdecl*)(br_scalar *, br_matrix4 *, br_scalar *))0x0048326d;
CARM95_HOOK_FUNCTION(original_SinglePointColl, SinglePointColl)
br_scalar __cdecl SinglePointColl(br_scalar *f, br_matrix4 *m, br_scalar *d) {
    LOG_TRACE("(%p, %p, %p)", f, m, d);

    (void)f;
    (void)m;
    (void)d;

    if (function_hook_state_SinglePointColl == HOOK_ENABLED) {
        f[0] = d[0] / m->m[0][0];
        if (f[0] < 0.0f) {
            f[0] = 0.0;
        }
        return fabsf(m->m[0][0]);
    } else {
        return original_SinglePointColl(f, m, d);
    }
}

function_hook_state_t function_hook_state_TwoPointColl = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(function_hook_state_TwoPointColl)
static br_scalar(__cdecl*original_TwoPointColl)(br_scalar *, br_matrix4 *, br_scalar *, br_vector3 *, br_vector3 *) = (br_scalar(__cdecl*)(br_scalar *, br_matrix4 *, br_scalar *, br_vector3 *, br_vector3 *))0x004832b2;
CARM95_HOOK_FUNCTION(original_TwoPointColl, TwoPointColl)
br_scalar __cdecl TwoPointColl(br_scalar *f, br_matrix4 *m, br_scalar *d, br_vector3 *tau, br_vector3 *n) {
    br_scalar ts;
    LOG_TRACE("(%p, %p, %p, %p, %p)", f, m, d, tau, n);

    (void)f;
    (void)m;
    (void)d;
    (void)tau;
    (void)n;
    (void)ts;

    if (function_hook_state_TwoPointColl == HOOK_ENABLED) {
        ts = m->m[1][1] * m->m[0][0] - m->m[0][1] * m->m[1][0];

        if (fabsf(ts) >= 0.000001f) {
            f[0] = (m->m[1][1] * d[0] - m->m[0][1] * d[1]) / ts;
            f[1] = (m->m[1][0] * d[0] - m->m[0][0] * d[1]) / -ts;
        }
        if (f[1] < 0.0f || fabs(ts) < 0.000001f) {
            ts = SinglePointColl(f, m, d);
            f[1] = 0.0;
        } else if (*f < 0.0) {
            m->m[0][0] = m->m[1][1];
            tau[0] = tau[1];
            n[0] = n[1];
            d[0] = d[1];
            ts = SinglePointColl(f, m, d);
            f[1] = 0.0;
        }
        return fabsf(ts);
    } else {
        return original_TwoPointColl(f, m, d, tau, n);
    }
}

function_hook_state_t function_hook_state_DrMatrix4Inverse = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(function_hook_state_DrMatrix4Inverse)
static br_scalar(__cdecl*original_DrMatrix4Inverse)(br_matrix4 *, br_matrix4 *) = (br_scalar(__cdecl*)(br_matrix4 *, br_matrix4 *))0x0048377f;
CARM95_HOOK_FUNCTION(original_DrMatrix4Inverse, DrMatrix4Inverse)
br_scalar __cdecl DrMatrix4Inverse(br_matrix4 *mi, br_matrix4 *mc) {
    LOG_TRACE("(%p, %p)", mi, mc);

    (void)mi;
    (void)mc;

    if (function_hook_state_DrMatrix4Inverse == HOOK_ENABLED) {
        return BrMatrix4Inverse(mi, mc);
    } else {
        return original_DrMatrix4Inverse(mi, mc);
    }
}

function_hook_state_t function_hook_state_ThreePointColl = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(function_hook_state_ThreePointColl)
static br_scalar(__cdecl*original_ThreePointColl)(br_scalar *, br_matrix4 *, br_scalar *) = (br_scalar(__cdecl*)(br_scalar *, br_matrix4 *, br_scalar *))0x004836f1;
CARM95_HOOK_FUNCTION(original_ThreePointColl, ThreePointColl)
br_scalar __cdecl ThreePointColl(br_scalar *f, br_matrix4 *m, br_scalar *d) {
    br_matrix4 mc;
    br_matrix4 mi;
    br_scalar ts;
    LOG_TRACE("(%p, %p, %p)", f, m, d);

    (void)f;
    (void)m;
    (void)d;
    (void)mc;
    (void)mi;
    (void)ts;

    if (function_hook_state_ThreePointColl == HOOK_ENABLED) {
        BrMatrix4Copy(&mc, m);
        memset(&mc.m[2][3], 0, 16);
        mc.m[1][3] = 0.0f;
        mc.m[0][3] = 0.0f;
        mc.m[3][3] = 1.0f;
        ts = DrMatrix4Inverse(&mi, &mc);
        BrMatrix4TApply((br_vector4*)f, (br_vector4*)d, &mi);
        f[3] = 0.0f;
        return fabs(ts);
    } else {
        return original_ThreePointColl(f, m, d);
    }
}

function_hook_state_t function_hook_state_ThreePointCollRec = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(function_hook_state_ThreePointCollRec)
static br_scalar(__cdecl*original_ThreePointCollRec)(br_scalar *, br_matrix4 *, br_scalar *, br_vector3 *, br_vector3 *, tCollision_info *) = (br_scalar(__cdecl*)(br_scalar *, br_matrix4 *, br_scalar *, br_vector3 *, br_vector3 *, tCollision_info *))0x00483425;
CARM95_HOOK_FUNCTION(original_ThreePointCollRec, ThreePointCollRec)
br_scalar __cdecl ThreePointCollRec(br_scalar *f, br_matrix4 *m, br_scalar *d, br_vector3 *tau, br_vector3 *n, tCollision_info *c) {
    int i;
    int j;
    br_scalar ts;
    LOG_TRACE("(%p, %p, %p, %p, %p, %p)", f, m, d, tau, n, c);

    (void)f;
    (void)m;
    (void)d;
    (void)tau;
    (void)n;
    (void)c;
    (void)i;
    (void)j;
    (void)ts;

    if (function_hook_state_ThreePointCollRec == HOOK_ENABLED) {
        ts = ThreePointColl(f, m, d);
        if (f[0] >= 0.0f && f[1] >= 0.0f && f[2] >= 0.0f && ts >= 0.000001f) {
            c->infinite_mass = 256;
            return ts;
        }
        if (ts < 0.000001f) {
            i = 0;
            j = 1;
        } else if (f[0] < 0.0f) {
            i = 1;
            j = 2;
        } else if (f[1] < 0.0f) {
            i = 0;
            j = 2;
        } else if (f[2] < 0.0f) {
            i = 0;
            j = 1;
        } else {
            return 0.0f;
        }
        m->m[0][0] = ((float*)m->m)[5 * i];
        m->m[1][0] = m->m[j][i];
        m->m[0][1] = m->m[i][j];
        m->m[1][1] = ((float*)m->m)[5 * j];
        tau[0] = tau[i];
        tau[1] = tau[j];
        n[0] = n[i];
        n[1] = n[j];
        d[0] = d[i];
        d[1] = d[j];
        ts = TwoPointColl(f, m, d, tau, n);
        f[2] = 0.0f;
        return ts;
    } else {
        return original_ThreePointCollRec(f, m, d, tau, n, c);
    }
}

function_hook_state_t function_hook_state_FourPointColl = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(function_hook_state_FourPointColl)
static br_scalar(__cdecl*original_FourPointColl)(br_scalar *, br_matrix4 *, br_scalar *, br_vector3 *, br_vector3 *, tCollision_info *) = (br_scalar(__cdecl*)(br_scalar *, br_matrix4 *, br_scalar *, br_vector3 *, br_vector3 *, tCollision_info *))0x0048379f;
CARM95_HOOK_FUNCTION(original_FourPointColl, FourPointColl)
br_scalar __cdecl FourPointColl(br_scalar *f, br_matrix4 *m, br_scalar *d, br_vector3 *tau, br_vector3 *n, tCollision_info *c) {
    int i;
    int j;
    int l;
    br_scalar ts;
    LOG_TRACE("(%p, %p, %p, %p, %p, %p)", f, m, d, tau, n, c);

    (void)f;
    (void)m;
    (void)d;
    (void)tau;
    (void)n;
    (void)c;
    (void)i;
    (void)j;
    (void)l;
    (void)ts;

    if (function_hook_state_FourPointColl == HOOK_ENABLED) {
        ts = ThreePointColl(f, m, d);
        if (f[0] < 0.0 || f[1] < 0.0 || f[2] < 0.0 || ts < 0.000001) {
            if (ts < 0.000001) {
                j = 3;
            } else if (f[0] < 0.0) {
                j = 0;
            } else if (f[1] >= 0.0) {
                j = 2;
            } else {
                j = 1;
            }
            for (i = j; i < 3; ++i) {
                for (l = 0; l < 4; ++l) {
                    m->m[i][l] = m->m[i + 1][l];
                }
                d[i] = d[i + 1];
                tau[i] = tau[i + 1];
                n[i] = n[i + 1];
                d[i] = d[i + 1];
            }
            for (i = j; i < 3; ++i) {
                for (l = 0; l < 3; ++l) {
                    m->m[l][i] = m->m[l][i + 1];
                }
            }
            return ThreePointCollRec(f, m, d, tau, n, c);
        } else {
            c->infinite_mass = 256;
            return ts;
        }
    } else {
        return original_FourPointColl(f, m, d, tau, n, c);
    }
}

function_hook_state_t function_hook_state_MultiFindFloorInBoxM = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(function_hook_state_MultiFindFloorInBoxM)
static void(__cdecl*original_MultiFindFloorInBoxM)(int, br_vector3 *, br_vector3 *, br_vector3 *, br_scalar *, tCar_spec *, int *) = (void(__cdecl*)(int, br_vector3 *, br_vector3 *, br_vector3 *, br_scalar *, tCar_spec *, int *))0x00483a49;
CARM95_HOOK_FUNCTION(original_MultiFindFloorInBoxM, MultiFindFloorInBoxM)
void __cdecl MultiFindFloorInBoxM(int pNum_rays, br_vector3 *a, br_vector3 *b, br_vector3 *nor, br_scalar *d, tCar_spec *c, int *mat_ref) {
    br_vector3 aa[4];
    br_vector3 bb;
    int i;
    LOG_TRACE("(%d, %p, %p, %p, %p, %p, %p)", pNum_rays, a, b, nor, d, c, mat_ref);

    (void)pNum_rays;
    (void)a;
    (void)b;
    (void)nor;
    (void)d;
    (void)c;
    (void)mat_ref;
    (void)aa;
    (void)bb;
    (void)i;

    if (function_hook_state_MultiFindFloorInBoxM == HOOK_ENABLED) {
        for (i = 0; i < pNum_rays; i++) {
            aa[i].v[0] = a[i].v[0] / WORLD_SCALE;
            aa[i].v[1] = a[i].v[1] / WORLD_SCALE;
            aa[i].v[2] = a[i].v[2] / WORLD_SCALE;
            d[i] = 2.0;
        }
        bb.v[0] = b->v[0] / WORLD_SCALE;
        bb.v[1] = b->v[1] / WORLD_SCALE;
        bb.v[2] = b->v[2] / WORLD_SCALE;
        MultiFindFloorInBoxBU(pNum_rays, aa, &bb, nor, d, c, mat_ref);
    } else {
        original_MultiFindFloorInBoxM(pNum_rays, a, b, nor, d, c, mat_ref);
    }
}

function_hook_state_t function_hook_state_MultiFindFloorInBoxBU = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(function_hook_state_MultiFindFloorInBoxBU)
static void(__cdecl*original_MultiFindFloorInBoxBU)(int, br_vector3 *, br_vector3 *, br_vector3 *, br_scalar *, tCar_spec *, int *) = (void(__cdecl*)(int, br_vector3 *, br_vector3 *, br_vector3 *, br_scalar *, tCar_spec *, int *))0x00483b2a;
CARM95_HOOK_FUNCTION(original_MultiFindFloorInBoxBU, MultiFindFloorInBoxBU)
void __cdecl MultiFindFloorInBoxBU(int pNum_rays, br_vector3 *a, br_vector3 *b, br_vector3 *nor, br_scalar *d, tCar_spec *c, int *mat_ref) {
    br_vector3 nor2;
    int i;
    int j;
    int l;
    br_scalar dist[4];
    tFace_ref *face_ref;
    LOG_TRACE("(%d, %p, %p, %p, %p, %p, %p)", pNum_rays, a, b, nor, d, c, mat_ref);

    (void)pNum_rays;
    (void)a;
    (void)b;
    (void)nor;
    (void)d;
    (void)c;
    (void)mat_ref;
    (void)nor2;
    (void)i;
    (void)j;
    (void)l;
    (void)dist;
    (void)face_ref;

    if (function_hook_state_MultiFindFloorInBoxBU == HOOK_ENABLED) {
        for (i = c->box_face_start; i < c->box_face_end; i++) {
            face_ref = &HV(gFace_list__car)[i];
            if (!HV(gEliminate_faces) || (face_ref->flags & 0x80) == 0x0) {
                MultiRayCheckSingleFace(pNum_rays, face_ref, a, b, &nor2, dist);
                for (j = 0; j < pNum_rays; ++j) {
                    if (d[j] > dist[j]) {
                        d[j] = dist[j];
                        nor[j] = nor2;
                        l = *HV(gFace_list__car)[i].material->identifier - 47;
                        if (l >= 0 && l < 11) {
                            mat_ref[j] = l;
                        }
                    }
                }
            }
        }
    } else {
        original_MultiFindFloorInBoxBU(pNum_rays, a, b, nor, d, c, mat_ref);
    }
}

function_hook_state_t function_hook_state_findfloor = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(function_hook_state_findfloor)
static void(__cdecl*original_findfloor)(br_vector3 *, br_vector3 *, br_vector3 *, br_scalar *) = (void(__cdecl*)(br_vector3 *, br_vector3 *, br_vector3 *, br_scalar *))0x00483c6a;
CARM95_HOOK_FUNCTION(original_findfloor, findfloor)
void __cdecl findfloor(br_vector3 *a, br_vector3 *b, br_vector3 *nor, br_scalar *d) {
    br_material *material;
    br_vector3 aa;
    br_vector3 bb;
    LOG_TRACE("(%p, %p, %p, %p)", a, b, nor, d);

    (void)a;
    (void)b;
    (void)nor;
    (void)d;
    (void)material;
    (void)aa;
    (void)bb;

    if (function_hook_state_findfloor == HOOK_ENABLED) {
        BrVector3InvScale(&aa, a, WORLD_SCALE);
        BrVector3InvScale(&bb, b, WORLD_SCALE);
        FindFace(&aa, &bb, nor, d, &material);
    } else {
        original_findfloor(a, b, nor, d);
    }
}

function_hook_state_t function_hook_state_FindFloorInBoxM = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(function_hook_state_FindFloorInBoxM)
static int(__cdecl*original_FindFloorInBoxM)(br_vector3 *, br_vector3 *, br_vector3 *, br_scalar *, tCollision_info *) = (int(__cdecl*)(br_vector3 *, br_vector3 *, br_vector3 *, br_scalar *, tCollision_info *))0x00483cec;
CARM95_HOOK_FUNCTION(original_FindFloorInBoxM, FindFloorInBoxM)
int __cdecl FindFloorInBoxM(br_vector3 *a, br_vector3 *b, br_vector3 *nor, br_scalar *d, tCollision_info *c) {
    br_vector3 aa;
    br_vector3 bb;
    LOG_TRACE("(%p, %p, %p, %p, %p)", a, b, nor, d, c);

    (void)a;
    (void)b;
    (void)nor;
    (void)d;
    (void)c;
    (void)aa;
    (void)bb;

    if (function_hook_state_FindFloorInBoxM == HOOK_ENABLED) {
        aa.v[0] = a->v[0] / WORLD_SCALE;
        aa.v[1] = a->v[1] / WORLD_SCALE;
        aa.v[2] = a->v[2] / WORLD_SCALE;
        bb.v[0] = b->v[0] / WORLD_SCALE;
        bb.v[1] = b->v[1] / WORLD_SCALE;
        bb.v[2] = b->v[2] / WORLD_SCALE;
        return FindFloorInBoxBU(&aa, &bb, nor, d, c);
    } else {
        return original_FindFloorInBoxM(a, b, nor, d, c);
    }
}

function_hook_state_t function_hook_state_FindFloorInBoxBU = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(function_hook_state_FindFloorInBoxBU)
static int(__cdecl*original_FindFloorInBoxBU)(br_vector3 *, br_vector3 *, br_vector3 *, br_scalar *, tCollision_info *) = (int(__cdecl*)(br_vector3 *, br_vector3 *, br_vector3 *, br_scalar *, tCollision_info *))0x00483d73;
CARM95_HOOK_FUNCTION(original_FindFloorInBoxBU, FindFloorInBoxBU)
int __cdecl FindFloorInBoxBU(br_vector3 *a, br_vector3 *b, br_vector3 *nor, br_scalar *d, tCollision_info *c) {
    br_vector3 nor2;
    int i;
    int j;
    br_scalar dist;
    tFace_ref *face_ref;
    LOG_TRACE("(%p, %p, %p, %p, %p)", a, b, nor, d, c);

    (void)a;
    (void)b;
    (void)nor;
    (void)d;
    (void)c;
    (void)nor2;
    (void)i;
    (void)j;
    (void)dist;
    (void)face_ref;

    if (function_hook_state_FindFloorInBoxBU == HOOK_ENABLED) {
//#if defined(DETHRACE_FIX_BUGS)
        j = 0; // added to keep compiler happy
//#endif
        *d = 2.0;
        for (i = c->box_face_start; i < c->box_face_end; i++) {
            face_ref = &HV(gFace_list__car)[i];
            if (!HV(gEliminate_faces) || SLOBYTE(face_ref->flags) >= 0) {
                CheckSingleFace(face_ref, a, b, &nor2, &dist);
                if (*d > dist) {
                    *d = dist;
                    j = i;
                    *nor = nor2;
                }
            }
        }
        if (*d >= 2.0) {
            return 0;
        }
        i = *HV(gFace_list__car)[j].material->identifier - '/';
        if (i < 0 || i >= 11) {
            return 0;
        } else {
            return *HV(gFace_list__car)[j].material->identifier - '/';
        }
    } else {
        return original_FindFloorInBoxBU(a, b, nor, d, c);
    }
}

function_hook_state_t function_hook_state_FindFloorInBoxBU2 = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(function_hook_state_FindFloorInBoxBU2)
static int(__cdecl*original_FindFloorInBoxBU2)(br_vector3 *, br_vector3 *, br_vector3 *, br_scalar *, tCollision_info *) = (int(__cdecl*)(br_vector3 *, br_vector3 *, br_vector3 *, br_scalar *, tCollision_info *))0x00483e92;
CARM95_HOOK_FUNCTION(original_FindFloorInBoxBU2, FindFloorInBoxBU2)
int __cdecl FindFloorInBoxBU2(br_vector3 *a, br_vector3 *b, br_vector3 *nor, br_scalar *d, tCollision_info *c) {
    br_vector3 nor2;
    br_vector3 tv;
    int i;
    int j;
    br_scalar dist;
    tFace_ref *face_ref;
    LOG_TRACE("(%p, %p, %p, %p, %p)", a, b, nor, d, c);

    (void)a;
    (void)b;
    (void)nor;
    (void)d;
    (void)c;
    (void)nor2;
    (void)tv;
    (void)i;
    (void)j;
    (void)dist;
    (void)face_ref;

    if (function_hook_state_FindFloorInBoxBU2 == HOOK_ENABLED) {
//#if defined(DETHRACE_FIX_BUGS)
        j = 0; // added to keep compiler happy
//#endif
        *d = 2.0;
        for (i = c->box_face_start; i < c->box_face_end; i++) {
            face_ref = &HV(gFace_list__car)[i];
            if (!HV(gEliminate_faces) || SLOBYTE(face_ref->flags) >= 0) {
                CheckSingleFace(face_ref, a, b, &nor2, &dist);
                if (*d > dist) {
                    if (face_ref->material->user == DOUBLESIDED_USER_FLAG || (face_ref->material->flags & 0x1800) != 0) {
                        tv.v[0] = c->pos.v[0] - a->v[0];
                        tv.v[1] = c->pos.v[1] - a->v[1];
                        tv.v[2] = c->pos.v[2] - a->v[2];
                        if (tv.v[2] * nor2.v[2] + tv.v[1] * nor2.v[1] + tv.v[0] * nor2.v[0] >= 0.0) {
                            *d = dist;
                            j = i;
                            *nor = nor2;
                        }
                    } else {
                        *d = dist;
                        j = i;
                        *nor = nor2;
                    }
                }
            }
            face_ref++;
        }
        if (*d >= 2.0) {
            return 0;
        }
        i = *HV(gFace_list__car)[j].material->identifier - '/';
        if (i < 0 || i >= 11) {
            return 0;
        } else {
            return *HV(gFace_list__car)[j].material->identifier - '/';
        }
    } else {
        return original_FindFloorInBoxBU2(a, b, nor, d, c);
    }
}

function_hook_state_t function_hook_state_FindFloorInBoxM2 = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(function_hook_state_FindFloorInBoxM2)
static int(__cdecl*original_FindFloorInBoxM2)(br_vector3 *, br_vector3 *, br_vector3 *, br_scalar *, tCollision_info *) = (int(__cdecl*)(br_vector3 *, br_vector3 *, br_vector3 *, br_scalar *, tCollision_info *))0x0048405b;
CARM95_HOOK_FUNCTION(original_FindFloorInBoxM2, FindFloorInBoxM2)
int __cdecl FindFloorInBoxM2(br_vector3 *a, br_vector3 *b, br_vector3 *nor, br_scalar *d, tCollision_info *c) {
    br_vector3 aa;
    br_vector3 bb;
    LOG_TRACE("(%p, %p, %p, %p, %p)", a, b, nor, d, c);

    (void)a;
    (void)b;
    (void)nor;
    (void)d;
    (void)c;
    (void)aa;
    (void)bb;

    if (function_hook_state_FindFloorInBoxM2 == HOOK_ENABLED) {
        aa.v[0] = a->v[0] / WORLD_SCALE;
        aa.v[1] = a->v[1] / WORLD_SCALE;
        aa.v[2] = a->v[2] / WORLD_SCALE;
        bb.v[0] = b->v[0] / WORLD_SCALE;
        bb.v[1] = b->v[1] / WORLD_SCALE;
        bb.v[2] = b->v[2] / WORLD_SCALE;
        return FindFloorInBoxBU2(&aa, &bb, nor, d, c);
    } else {
        return original_FindFloorInBoxM2(a, b, nor, d, c);
    }
}

function_hook_state_t function_hook_state_BoxFaceIntersect = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(function_hook_state_BoxFaceIntersect)
static int(__cdecl*original_BoxFaceIntersect)(br_bounds *, br_matrix34 *, br_matrix34 *, br_vector3 *, br_vector3 *, br_scalar *, int, tCollision_info *) = (int(__cdecl*)(br_bounds *, br_matrix34 *, br_matrix34 *, br_vector3 *, br_vector3 *, br_scalar *, int, tCollision_info *))0x004840e2;
CARM95_HOOK_FUNCTION(original_BoxFaceIntersect, BoxFaceIntersect)
int __cdecl BoxFaceIntersect(br_bounds *pB, br_matrix34 *pM, br_matrix34 *pMold, br_vector3 *pPoint_list, br_vector3 *pNorm_list, br_scalar *pDist_list, int pMax_pnts, tCollision_info *c) {
    br_vector3 p[3];
    br_vector3 tv;
    br_vector3 pos;
    br_bounds bnds;
    int i;
    int j;
    int n;
    int flag;
    int m;
    tFace_ref *f_ref;
    br_face *face;
    LOG_TRACE("(%p, %p, %p, %p, %p, %p, %d, %p)", pB, pM, pMold, pPoint_list, pNorm_list, pDist_list, pMax_pnts, c);

    (void)pB;
    (void)pM;
    (void)pMold;
    (void)pPoint_list;
    (void)pNorm_list;
    (void)pDist_list;
    (void)pMax_pnts;
    (void)c;
    (void)p;
    (void)tv;
    (void)pos;
    (void)bnds;
    (void)i;
    (void)j;
    (void)n;
    (void)flag;
    (void)m;
    (void)f_ref;
    (void)face;

    if (function_hook_state_BoxFaceIntersect == HOOK_ENABLED) {
        n = 0;
        bnds.min.v[0] = pB->min.v[0] * 0.14492753;
        bnds.min.v[1] = pB->min.v[1] * 0.14492753;
        bnds.min.v[2] = pB->min.v[2] * 0.14492753;
        bnds.max.v[0] = pB->max.v[0] * 0.14492753;
        bnds.max.v[1] = pB->max.v[1] * 0.14492753;
        bnds.max.v[2] = pB->max.v[2] * 0.14492753;
        pos.v[0] = pM->m[3][0] * 0.14492753;
        pos.v[1] = pM->m[3][1] * 0.14492753;
        pos.v[2] = pM->m[3][2] * 0.14492753;
        pMold->m[3][0] = pMold->m[3][0] * 0.14492753;
        pMold->m[3][1] = pMold->m[3][1] * 0.14492753;
        pMold->m[3][2] = pMold->m[3][2] * 0.14492753;

        for (i = c->box_face_start; i < c->box_face_end && i < c->box_face_start + 50; i++) {
            f_ref = &HV(gFace_list__car)[i];
            if (SLOBYTE(f_ref->flags) >= 0 && *f_ref->material->identifier != '!') {
                tv.v[0] = f_ref->v[0].v[0] - pos.v[0];
                tv.v[1] = f_ref->v[0].v[1] - pos.v[1];
                tv.v[2] = f_ref->v[0].v[2] - pos.v[2];
                BrMatrix34TApplyV(p, &tv, pM);
                tv.v[0] = f_ref->v[1].v[0] - pos.v[0];
                tv.v[1] = f_ref->v[1].v[1] - pos.v[1];
                tv.v[2] = f_ref->v[1].v[2] - pos.v[2];
                BrMatrix34TApplyV(&p[1], &tv, pM);
                tv.v[0] = f_ref->v[2].v[0] - pos.v[0];
                tv.v[1] = f_ref->v[2].v[1] - pos.v[1];
                tv.v[2] = f_ref->v[2].v[2] - pos.v[2];
                BrMatrix34TApplyV(&p[2], &tv, pM);
                j = n;
                if ((f_ref->flags & 1) == 0) {
                    n += AddEdgeCollPoints(p, &p[1], &bnds, pMold, pPoint_list, pNorm_list, n, pMax_pnts, c);
                }
                if ((f_ref->flags & 2) == 0) {
                    n += AddEdgeCollPoints(&p[1], &p[2], &bnds, pMold, pPoint_list, pNorm_list, n, pMax_pnts, c);
                }
                if ((f_ref->flags & 4) == 0) {
                    n += AddEdgeCollPoints(&p[2], p, &bnds, pMold, pPoint_list, pNorm_list, n, pMax_pnts, c);
                }
                if (n > j) {
                    if (!HV(gMaterial_index)) {
                        m = *f_ref->material->identifier - '/';
                        if (m > 0 && m < 11) {
                            HV(gMaterial_index) = m;
                        }
                    }
                    while (n > j) {
                        pPoint_list[j].v[0] = pPoint_list[j].v[0] * WORLD_SCALE;
                        pPoint_list[j].v[1] = pPoint_list[j].v[1] * WORLD_SCALE;
                        pPoint_list[j].v[2] = pPoint_list[j].v[2] * WORLD_SCALE;
                        pPoint_list[j].v[0] = pPoint_list[j].v[0] - c->cmpos.v[0];
                        pPoint_list[j].v[1] = pPoint_list[j].v[1] - c->cmpos.v[1];
                        pPoint_list[j].v[2] = pPoint_list[j].v[2] - c->cmpos.v[2];
                        ++j;
                    }
                }
            }
        }
        if (n) {
            m = 0;
            for (i = 0; i < n - 1; i++) {
                flag = 1;
                for (j = i + 1; j < n; j++) {
                    if (fabs(pPoint_list[i].v[0] - pPoint_list[j].v[0]) <= 0.001
                        && fabs(pPoint_list[i].v[1] - pPoint_list[j].v[1]) <= 0.001
                        && fabs(pPoint_list[i].v[2] - pPoint_list[j].v[2]) <= 0.001) {
                        flag = 0;
                        break;
                    }
                }
                if (flag) {
                    pPoint_list[m].v[0] = pPoint_list[i].v[0];
                    pPoint_list[m].v[1] = pPoint_list[i].v[1];
                    pPoint_list[m].v[2] = pPoint_list[i].v[2];
                    m++;
                }
            }
            pPoint_list[m].v[0] = pPoint_list[n - 1].v[0];
            pPoint_list[m].v[1] = pPoint_list[n - 1].v[1];
            pPoint_list[m].v[2] = pPoint_list[n - 1].v[2];
            n = m + 1;
        }
        pMold->m[3][0] = pMold->m[3][0] * WORLD_SCALE;
        pMold->m[3][1] = pMold->m[3][1] * WORLD_SCALE;
        pMold->m[3][2] = pMold->m[3][2] * WORLD_SCALE;
        return n;
    } else {
        return original_BoxFaceIntersect(pB, pM, pMold, pPoint_list, pNorm_list, pDist_list, pMax_pnts, c);
    }
}

function_hook_state_t function_hook_state_AddEdgeCollPoints = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(function_hook_state_AddEdgeCollPoints)
static int(__cdecl*original_AddEdgeCollPoints)(br_vector3 *, br_vector3 *, br_bounds *, br_matrix34 *, br_vector3 *, br_vector3 *, int, int, tCollision_info *) = (int(__cdecl*)(br_vector3 *, br_vector3 *, br_bounds *, br_matrix34 *, br_vector3 *, br_vector3 *, int, int, tCollision_info *))0x0048469b;
CARM95_HOOK_FUNCTION(original_AddEdgeCollPoints, AddEdgeCollPoints)
int __cdecl AddEdgeCollPoints(br_vector3 *p1, br_vector3 *p2, br_bounds *pB, br_matrix34 *pMold, br_vector3 *pPoint_list, br_vector3 *pNorm_list, int n, int pMax_pnts, tCollision_info *c) {
    br_vector3 op1;
    br_vector3 op2;
    br_vector3 a;
    br_vector3 b;
    br_vector3 edge;
    br_vector3 hp1;
    br_vector3 hp2;
    br_vector3 hp3;
    int plane1;
    int plane2;
    int plane3;
    int d;
    br_scalar __block0___scale;
    br_scalar __block1___scale;
    br_scalar __block2___scale;
    LOG_TRACE("(%p, %p, %p, %p, %p, %p, %d, %d, %p)", p1, p2, pB, pMold, pPoint_list, pNorm_list, n, pMax_pnts, c);

    (void)p1;
    (void)p2;
    (void)pB;
    (void)pMold;
    (void)pPoint_list;
    (void)pNorm_list;
    (void)n;
    (void)pMax_pnts;
    (void)c;
    (void)op1;
    (void)op2;
    (void)a;
    (void)b;
    (void)edge;
    (void)hp1;
    (void)hp2;
    (void)hp3;
    (void)plane1;
    (void)plane2;
    (void)plane3;
    (void)d;
    (void)__block0___scale;
    (void)__block1___scale;
    (void)__block2___scale;

    if (function_hook_state_AddEdgeCollPoints == HOOK_ENABLED) {
        float scale;

        plane1 = LineBoxColl(p1, p2, pB, &hp1);
        if (!plane1) {
            return 0;
        }
        if (n + 2 > pMax_pnts) {
            return 0;
        }
        plane2 = LineBoxColl(p2, p1, pB, &hp2);
        if (!plane2) {
            return 0;
        }
        if (plane1 == 8 || plane2 == 8 || (plane1 ^ plane2) != 4) {
            if (plane1 != 8 || plane2 == 8) {
                if (plane2 != 8 || plane1 == 8) {
                    if (plane1 == 8 || plane2 == 8) {
                        if (plane1 == 8 && plane2 == 8) {
                            BrMatrix34ApplyP(&op1, p1, pMold);
                            plane3 = LineBoxColl(&op1, p1, pB, &pPoint_list[n]);
                            GetPlaneNormal(&pNorm_list[n], plane3);
                            d = n + (plane3 != 8);
                            BrMatrix34ApplyP(&op1, p2, pMold);
                            plane3 = LineBoxColl(&op1, p2, pB, &pPoint_list[d]);
                            GetPlaneNormal(&pNorm_list[d], plane3);
                            return (n != d) + (plane3 != 8);
                        } else {
                            return 0;
                        }
                    } else {
                        op1.v[0] = hp2.v[0] + hp1.v[0];
                        op1.v[1] = hp2.v[1] + hp1.v[1];
                        op1.v[2] = hp2.v[2] + hp1.v[2];
                        op1.v[0] = op1.v[0] * 0.5;
                        op1.v[1] = op1.v[1] * 0.5;
                        op1.v[2] = op1.v[2] * 0.5;
                        BrMatrix34ApplyP(&op2, &op1, pMold);
                        plane3 = LineBoxColl(&op2, &op1, pB, &hp3);
                        if (plane3 != 8 && plane3) {
                            if (plane1 == plane3 || plane2 == plane3) {
                                GetBoundsEdge(
                                        &pPoint_list[n],
                                        &edge,
                                        pB,
                                        plane1,
                                        plane2,
                                        &op2,
                                        &hp1,
                                        &hp2,
                                        c->collision_flag);
                                op1.v[0] = hp1.v[0] - hp2.v[0];
                                op1.v[1] = hp1.v[1] - hp2.v[1];
                                op1.v[2] = hp1.v[2] - hp2.v[2];
                                op2.v[0] = edge.v[1] * op1.v[2] - op1.v[1] * edge.v[2];
                                op2.v[1] = edge.v[2] * op1.v[0] - op1.v[2] * edge.v[0];
                                op2.v[2] = op1.v[1] * edge.v[0] - edge.v[1] * op1.v[0];
                                scale = sqrt(op2.v[1] * op2.v[1] + op2.v[2] * op2.v[2] + op2.v[0] * op2.v[0]);
                                if (scale <= 2.3841858e-7) {
                                    pNorm_list[n].v[0] = 1.0;
                                    pNorm_list[n].v[1] = 0.0;
                                    pNorm_list[n].v[2] = 0.0;
                                } else {
                                    scale = 1.0 / scale;
                                    pNorm_list[n].v[0] = op2.v[0] * scale;
                                    pNorm_list[n].v[1] = op2.v[1] * scale;
                                    pNorm_list[n].v[2] = op2.v[2] * scale;
                                }
                                op1.v[0] = pB->max.v[0] + pB->min.v[0];
                                op1.v[1] = pB->min.v[1] + pB->max.v[1];
                                op1.v[2] = pB->max.v[2] + pB->min.v[2];
                                op1.v[0] = op1.v[0] * 0.5;
                                op1.v[1] = op1.v[1] * 0.5;
                                op1.v[2] = op1.v[2] * 0.5;
                                op1.v[0] = pPoint_list[n].v[0] - op1.v[0];
                                op1.v[1] = pPoint_list[n].v[1] - op1.v[1];
                                op1.v[2] = pPoint_list[n].v[2] - op1.v[2];
                                if (pNorm_list[n].v[1] * op1.v[1] + pNorm_list[n].v[2] * op1.v[2] + pNorm_list[n].v[0] * op1.v[0] > 0.0) {
                                    pNorm_list[n].v[0] = -pNorm_list[n].v[0];
                                    pNorm_list[n].v[1] = -pNorm_list[n].v[1];
                                    pNorm_list[n].v[2] = -pNorm_list[n].v[2];
                                }
                                op1 = pNorm_list[n];
                                BrMatrix34ApplyV(&pNorm_list[n], &op1, pMold);
                                return 1;
                            } else {
                                GetBoundsEdge(
                                        &pPoint_list[n],
                                        &edge,
                                        pB,
                                        plane1,
                                        plane3,
                                        &hp3,
                                        &hp1,
                                        &hp2,
                                        c->collision_flag);
                                GetBoundsEdge(
                                        &pPoint_list[n + 1],
                                        &edge,
                                        pB,
                                        plane2,
                                        plane3,
                                        &hp3,
                                        &hp1,
                                        &hp2,
                                        c->collision_flag);
                                GetPlaneNormal(&pNorm_list[n], plane3);
                                pNorm_list[n + 1] = pNorm_list[n];
                                return 2;
                            }
                        } else {
                            return 0;
                        }
                    }
                } else {
                    BrMatrix34ApplyP(&b, p2, pMold);
                    plane3 = LineBoxColl(&b, p2, pB, &hp3);
                    if (plane3 == 8) {
                        return 0;
                    } else {
                        pPoint_list[n] = hp3;
                        GetPlaneNormal(&pNorm_list[n], plane1);
                        if (plane1 == plane3 || (plane3 ^ plane1) == 4) {
                            return 1;
                        } else {
                            GetBoundsEdge(&pPoint_list[n + 1], &edge, pB, plane1, plane3, p2, &hp1, &hp3, c->collision_flag);
                            op1.v[0] = p1->v[0] - p2->v[0];
                            op1.v[1] = p1->v[1] - p2->v[1];
                            op1.v[2] = p1->v[2] - p2->v[2];
                            pNorm_list[n + 1].v[0] = edge.v[1] * op1.v[2] - op1.v[1] * edge.v[2];
                            pNorm_list[n + 1].v[1] = edge.v[2] * op1.v[0] - op1.v[2] * edge.v[0];
                            pNorm_list[n + 1].v[2] = op1.v[1] * edge.v[0] - edge.v[1] * op1.v[0];
                            scale = sqrt(
                                    pNorm_list[n + 1].v[0] * pNorm_list[n + 1].v[0]
                                    + pNorm_list[n + 1].v[1] * pNorm_list[n + 1].v[1]
                                    + pNorm_list[n + 1].v[2] * pNorm_list[n + 1].v[2]);
                            if (scale <= 2.3841858e-7) {
                                pNorm_list[n + 1].v[0] = 1.0;
                                pNorm_list[n + 1].v[1] = 0.0;
                                pNorm_list[n + 1].v[2] = 0.0;
                            } else {
                                scale = 1.0 / scale;
                                pNorm_list[n + 1].v[0] = pNorm_list[n + 1].v[0] * scale;
                                pNorm_list[n + 1].v[1] = pNorm_list[n + 1].v[1] * scale;
                                pNorm_list[n + 1].v[2] = pNorm_list[n + 1].v[2] * scale;
                            }
                            d = (plane1 - 1) & 3;
                            if ((pNorm_list[n + 1].v[d] < 0.0) == (plane1 & 4) >> 2) {
                                pNorm_list[n + 1].v[0] = -pNorm_list[n + 1].v[0];
                                pNorm_list[n + 1].v[1] = -pNorm_list[n + 1].v[1];
                                pNorm_list[n + 1].v[2] = -pNorm_list[n + 1].v[2];
                            }
                            op1 = pNorm_list[n + 1];
                            BrMatrix34ApplyV(&pNorm_list[n + 1], &op1, pMold);
                            return 2;
                        }
                    }
                }
            } else {
                BrMatrix34ApplyP(&a, p1, pMold);
                plane3 = LineBoxColl(&a, p1, pB, &hp3);
                if (plane3 == 8) {
                    return 0;
                } else {
                    pPoint_list[n] = hp3;
                    GetPlaneNormal(&pNorm_list[n], plane2);
                    if (plane2 == plane3 || (plane3 ^ plane2) == 4) {
                        return 1;
                    } else {
                        GetBoundsEdge(&pPoint_list[n + 1], &edge, pB, plane2, plane3, p1, &hp2, &hp3, c->collision_flag);
                        op1.v[0] = p1->v[0] - p2->v[0];
                        op1.v[1] = p1->v[1] - p2->v[1];
                        op1.v[2] = p1->v[2] - p2->v[2];
                        pNorm_list[n + 1].v[0] = edge.v[1] * op1.v[2] - op1.v[1] * edge.v[2];
                        pNorm_list[n + 1].v[1] = edge.v[2] * op1.v[0] - op1.v[2] * edge.v[0];
                        pNorm_list[n + 1].v[2] = op1.v[1] * edge.v[0] - edge.v[1] * op1.v[0];
                        scale = sqrt(
                                pNorm_list[n + 1].v[0] * pNorm_list[n + 1].v[0]
                                + pNorm_list[n + 1].v[1] * pNorm_list[n + 1].v[1]
                                + pNorm_list[n + 1].v[2] * pNorm_list[n + 1].v[2]);
                        if (scale <= 2.3841858e-7) {
                            pNorm_list[n + 1].v[0] = 1.0;
                            pNorm_list[n + 1].v[1] = 0.0;
                            pNorm_list[n + 1].v[2] = 0.0;
                        } else {
                            scale = 1.0 / scale;
                            pNorm_list[n + 1].v[0] = pNorm_list[n + 1].v[0] * scale;
                            pNorm_list[n + 1].v[1] = pNorm_list[n + 1].v[1] * scale;
                            pNorm_list[n + 1].v[2] = pNorm_list[n + 1].v[2] * scale;
                        }
                        d = (plane2 - 1) & 3;
                        if ((pNorm_list[n + 1].v[d] < 0.0) == (plane2 & 4) >> 2) {
                            pNorm_list[n + 1].v[0] = -pNorm_list[n + 1].v[0];
                            pNorm_list[n + 1].v[1] = -pNorm_list[n + 1].v[1];
                            pNorm_list[n + 1].v[2] = -pNorm_list[n + 1].v[2];
                        }
                        op1 = pNorm_list[n + 1];
                        BrMatrix34ApplyV(&pNorm_list[n + 1], &op1, pMold);
                        return 2;
                    }
                }
            }
        } else {
            op1.v[0] = hp2.v[0] + hp1.v[0];
            op1.v[1] = hp2.v[1] + hp1.v[1];
            op1.v[2] = hp2.v[2] + hp1.v[2];
            op1.v[0] = op1.v[0] * 0.5;
            op1.v[1] = op1.v[1] * 0.5;
            op1.v[2] = op1.v[2] * 0.5;
            BrMatrix34ApplyP(&op2, &op1, pMold);
            plane3 = LineBoxColl(&op2, &op1, pB, &hp3);
            if (plane3 == 8) {
                return 0;
            } else {
                GetBoundsEdge(&pPoint_list[n], &edge, pB, plane1, plane3, &op2, &hp1, &hp2, c->collision_flag);
                GetBoundsEdge(&pPoint_list[n + 1], &edge, pB, plane2, plane3, &op2, &hp1, &hp2, c->collision_flag);
                GetPlaneNormal(&pNorm_list[n], plane3);
                pNorm_list[n + 1] = pNorm_list[n];
                return 2;
            }
        }
    } else {
        return original_AddEdgeCollPoints(p1, p2, pB, pMold, pPoint_list, pNorm_list, n, pMax_pnts, c);
    }
}

function_hook_state_t function_hook_state_GetPlaneNormal = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(function_hook_state_GetPlaneNormal)
static void(__cdecl*original_GetPlaneNormal)(br_vector3 *, int) = (void(__cdecl*)(br_vector3 *, int))0x004854c1;
CARM95_HOOK_FUNCTION(original_GetPlaneNormal, GetPlaneNormal)
void __cdecl GetPlaneNormal(br_vector3 *n, int p) {
    int d;
    LOG_TRACE("(%p, %d)", n, p);

    (void)n;
    (void)p;
    (void)d;

    if (function_hook_state_GetPlaneNormal == HOOK_ENABLED) {
        d = (p - 1) & 3;
        n->v[0] = 0.0;
        n->v[1] = 0.0;
        n->v[2] = 0.0;
        if ((p & 4) != 0) {
            n->v[d] = 1.0;
        } else {
            n->v[d] = -1.0;
        }
    } else {
        original_GetPlaneNormal(n, p);
    }
}

function_hook_state_t function_hook_state_GetBoundsEdge = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(function_hook_state_GetBoundsEdge)
static int(__cdecl*original_GetBoundsEdge)(br_vector3 *, br_vector3 *, br_bounds *, int, int, br_vector3 *, br_vector3 *, br_vector3 *, int) = (int(__cdecl*)(br_vector3 *, br_vector3 *, br_bounds *, int, int, br_vector3 *, br_vector3 *, br_vector3 *, int))0x0048551f;
CARM95_HOOK_FUNCTION(original_GetBoundsEdge, GetBoundsEdge)
int __cdecl GetBoundsEdge(br_vector3 *pos, br_vector3 *edge, br_bounds *pB, int plane1, int plane2, br_vector3 *a, br_vector3 *b, br_vector3 *c, int flag) {
    int d1;
    int d2;
    int d3;
    br_vector3 n;
    br_vector3 p;
    br_vector3 q;
    LOG_TRACE("(%p, %p, %p, %d, %d, %p, %p, %p, %d)", pos, edge, pB, plane1, plane2, a, b, c, flag);

    (void)pos;
    (void)edge;
    (void)pB;
    (void)plane1;
    (void)plane2;
    (void)a;
    (void)b;
    (void)c;
    (void)flag;
    (void)d1;
    (void)d2;
    (void)d3;
    (void)n;
    (void)p;
    (void)q;

    if (function_hook_state_GetBoundsEdge == HOOK_ENABLED) {
        d1 = (plane1 - 1) & 3;
        d2 = (plane2 - 1) & 3;
        n.v[0] = b->v[0] - a->v[0];
        n.v[1] = b->v[1] - a->v[1];
        n.v[2] = b->v[2] - a->v[2];
        p.v[0] = c->v[0] - a->v[0];
        p.v[1] = c->v[1] - a->v[1];
        p.v[2] = c->v[2] - a->v[2];
        q.v[0] = p.v[2] * n.v[1] - p.v[1] * n.v[2];
        q.v[1] = n.v[2] * p.v[0] - p.v[2] * n.v[0];
        q.v[2] = p.v[1] * n.v[0] - n.v[1] * p.v[0];
        if ((plane1 & 4) != 0) {
            pos->v[d1] = pB->min.v[d1];
        } else {
            pos->v[d1] = pB->max.v[d1];
        }
        if ((plane2 & 4) != 0) {
            pos->v[d2] = pB->min.v[d2];
        } else {
            pos->v[d2] = pB->max.v[d2];
        }
        d3 = 3 - d1 - d2;
        edge->v[d1] = 0.0;
        edge->v[d2] = 0.0;
        edge->v[d3] = 1.0;
        if ((flag & 1) != 0) {
            pos->v[d3] = (c->v[d3] + b->v[d3]) / 2.0;
        } else {
            pos->v[d3] = a->v[d3] - ((pos->v[d2] - a->v[d2]) * q.v[d2] + (pos->v[d1] - a->v[d1]) * q.v[d1]) / q.v[d3];
        }
        return 1;
    } else {
        return original_GetBoundsEdge(pos, edge, pB, plane1, plane2, a, b, c, flag);
    }
}

function_hook_state_t function_hook_state_oldMoveOurCar = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_oldMoveOurCar)
void oldMoveOurCar(tU32 pTime_difference) {
    br_vector3 thrust_vector;
    br_matrix34 direction_matrix;
    br_matrix34 old_mat;
    double rotate_amount;
    br_scalar nearest_y_above;
    br_scalar nearest_y_below;
    br_scalar speed;
    int below_face_index;
    int above_face_index;
    br_model *below_model;
    br_model *above_model;
    LOG_TRACE("(%u)", pTime_difference);

    (void)pTime_difference;
    (void)thrust_vector;
    (void)direction_matrix;
    (void)old_mat;
    (void)rotate_amount;
    (void)nearest_y_above;
    (void)nearest_y_below;
    (void)speed;
    (void)below_face_index;
    (void)above_face_index;
    (void)below_model;
    (void)above_model;

    if (function_hook_state_oldMoveOurCar == HOOK_ENABLED) {
        assert(0 && "oldMoveOurCar not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}

function_hook_state_t function_hook_state_ToggleCollisionDetection = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_ToggleCollisionDetection)
void ToggleCollisionDetection() {
    LOG_TRACE("()");


    if (function_hook_state_ToggleCollisionDetection == HOOK_ENABLED) {
        assert(0 && "ToggleCollisionDetection not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}

function_hook_state_t function_hook_state_CancelPendingCunningStunt = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(function_hook_state_CancelPendingCunningStunt)
static void(__cdecl*original_CancelPendingCunningStunt)() = (void(__cdecl*)())0x00485d8b;
CARM95_HOOK_FUNCTION(original_CancelPendingCunningStunt, CancelPendingCunningStunt)
void __cdecl CancelPendingCunningStunt() {
    LOG_TRACE("()");


    if (function_hook_state_CancelPendingCunningStunt == HOOK_ENABLED) {
        HV(gQuite_wild_end) = 0;
        HV(gQuite_wild_start) = 0;
        HV(gOn_me_wheels_start) = 0;
        HV(gWoz_upside_down_at_all) = 0;
        HV(gWild_start) = 0;
    } else {
        original_CancelPendingCunningStunt();
    }
}

function_hook_state_t function_hook_state_frac = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(function_hook_state_frac)
static float(__cdecl*original_frac)(float) = (float(__cdecl*)(float))0x00485dc8;
CARM95_HOOK_FUNCTION(original_frac, frac)
float __cdecl frac(float pN) {
    LOG_TRACE("(%f)", pN);

    (void)pN;

    if (function_hook_state_frac == HOOK_ENABLED) {
        return pN - (float)(int)pN;
    } else {
        return original_frac(pN);
    }
}

function_hook_state_t function_hook_state_SetAmbientPratCam = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(function_hook_state_SetAmbientPratCam)
static void(__cdecl*original_SetAmbientPratCam)(tCar_spec *) = (void(__cdecl*)(tCar_spec *))0x00486d06;
CARM95_HOOK_FUNCTION(original_SetAmbientPratCam, SetAmbientPratCam)
void __cdecl SetAmbientPratCam(tCar_spec *pCar) {
    br_scalar vcs_x;
    br_scalar vcs_y;
    br_scalar vcs_z;
    br_scalar abs_vcs_x;
    br_scalar abs_vcs_y;
    br_scalar abs_vcs_z;
    br_scalar abs_omega_x;
    br_scalar abs_omega_y;
    br_scalar abs_omega_z;
    tU32 the_time;
    static tU32 last_time_on_ground;
    LOG_TRACE("(%p)", pCar);

    (void)pCar;
    (void)vcs_x;
    (void)vcs_y;
    (void)vcs_z;
    (void)abs_vcs_x;
    (void)abs_vcs_y;
    (void)abs_vcs_z;
    (void)abs_omega_x;
    (void)abs_omega_y;
    (void)abs_omega_z;
    (void)the_time;
    (void)last_time_on_ground;

    if (function_hook_state_SetAmbientPratCam == HOOK_ENABLED) {
        if (HV(gRace_finished)) {
            return;
        }
        the_time = GetTotalTime();
        if (pCar->number_of_wheels_on_ground != 0) {
            last_time_on_ground = the_time;
        }
        vcs_x = pCar->velocity_car_space.v[0];
        vcs_y = pCar->velocity_car_space.v[1];
        vcs_z = pCar->velocity_car_space.v[2];
        abs_vcs_x = fabsf(vcs_x);
        abs_vcs_y = fabsf(vcs_y);
        abs_vcs_z = fabsf(vcs_z);
        abs_omega_x = fabsf(pCar->omega.v[0]);
        abs_omega_y = fabsf(pCar->omega.v[1]);
        abs_omega_z = fabsf(pCar->omega.v[2]);

        if (abs_omega_x > 4.5f || abs_omega_z > 4.5f) {
            ChangeAmbientPratcam(9);
        } else if (abs_omega_y > 4.5f) {
            ChangeAmbientPratcam(12);
        } else if (abs_omega_x > 3.f || abs_omega_z > 3.f) {
            ChangeAmbientPratcam(8);
        } else if (abs_omega_y > 3.f) {
            ChangeAmbientPratcam(11);
        } else if (pCar->car_master_actor->t.t.mat.m[1][1] < 0.1f) {
            ChangeAmbientPratcam(44);
        } else if (abs_vcs_y > abs_vcs_z && abs_vcs_y > abs_vcs_x && vcs_y < -.004f) {
            ChangeAmbientPratcam(6);
        } else if (the_time - last_time_on_ground > 500) {
            ChangeAmbientPratcam(5);
        } else if (abs_vcs_x > abs_vcs_z && vcs_x > .001f) {
            ChangeAmbientPratcam(26);
        } else if (abs_vcs_x > abs_vcs_z && vcs_x < -.001f) {
            ChangeAmbientPratcam(25);
        } else if (abs_omega_x > 1.5f || abs_omega_z > 1.5f) {
            ChangeAmbientPratcam(7);
        } else if (abs_omega_y > 1.5f) {
            ChangeAmbientPratcam(10);
        } else if (abs_vcs_z > .01f) {
            ChangeAmbientPratcam(3);
        } else if (abs_vcs_z > .004f) {
            ChangeAmbientPratcam(2);
        } else if (abs_vcs_z > .0015f) {
            ChangeAmbientPratcam(1);
        } else {
            ChangeAmbientPratcam(0);
        }
    } else {
        original_SetAmbientPratCam(pCar);
    }
}

function_hook_state_t function_hook_state_MungeCarGraphics = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(function_hook_state_MungeCarGraphics)
static void(__cdecl*original_MungeCarGraphics)(tU32) = (void(__cdecl*)(tU32))0x00485dee;
CARM95_HOOK_FUNCTION(original_MungeCarGraphics, MungeCarGraphics)
void __cdecl MungeCarGraphics(tU32 pFrame_period) {
    int i;
    int j;
    int update_mat;
    int spinning_wildly;
    int spinning_mildly;
    int car_count;
    int oily_count;
    int car;
    int cat;
    int new_special_screen;
    tCar_spec *the_car;
    br_scalar distance_from_camera;
    br_scalar car_x;
    br_scalar car_z;
    br_scalar oily_size;
    br_scalar car_radius;
    br_scalar abs_omega_x;
    br_scalar abs_omega_y;
    br_scalar abs_omega_z;
    float wheel_speed;
    float speed_mph;
    float rev_angle;
    float sine_angle;
    float raw_revs;
    float rev_reducer;
    tSpecial_screen *the_special_screen;
    br_material *the_material;
    tU32 the_time;
    br_actor *oily_actor;
    LOG_TRACE("(%u)", pFrame_period);

    (void)pFrame_period;
    (void)i;
    (void)j;
    (void)update_mat;
    (void)spinning_wildly;
    (void)spinning_mildly;
    (void)car_count;
    (void)oily_count;
    (void)car;
    (void)cat;
    (void)new_special_screen;
    (void)the_car;
    (void)distance_from_camera;
    (void)car_x;
    (void)car_z;
    (void)oily_size;
    (void)car_radius;
    (void)abs_omega_x;
    (void)abs_omega_y;
    (void)abs_omega_z;
    (void)wheel_speed;
    (void)speed_mph;
    (void)rev_angle;
    (void)sine_angle;
    (void)raw_revs;
    (void)rev_reducer;
    (void)the_special_screen;
    (void)the_material;
    (void)the_time;
    (void)oily_actor;

    if (function_hook_state_MungeCarGraphics == HOOK_ENABLED) {
        if (HV(gNet_mode)
            && ((HV(gCurrent_net_game)->type == eNet_game_type_foxy && HV(gThis_net_player_index) == HV(gIt_or_fox))
                || (HV(gCurrent_net_game)->type == eNet_game_type_tag && HV(gThis_net_player_index) != HV(gIt_or_fox)))) {
            HV(gProgram_state).current_car.power_up_levels[1] = 0;
        }
        SetAmbientPratCam(&HV(gProgram_state).current_car);
        if (HV(gProgram_state).cockpit_on) {
            SwitchCarActor(&HV(gProgram_state).current_car, HV(gProgram_state).current_car.car_actor_count - 1);
        } else {
            SwitchCarActor(&HV(gProgram_state).current_car, HV(gProgram_state).current_car.car_actor_count - 2);
        }

        the_time = PDGetTotalTime();
        for (cat = eVehicle_self; cat <= eVehicle_rozzer; cat++) {
            if (cat) {
                car_count = GetCarCount(cat);
            } else {
                car_count = 1;
            }
            for (car = 0; car_count > car; car++) {
                if (cat) {
                    the_car = GetCarSpec(cat, car);
                } else {
                    the_car = &HV(gProgram_state).current_car;
                }
                the_car->car_master_actor->render_style = (the_car->driver != eDriver_local_human) && PointOutOfSight(&the_car->pos, HV(gYon_squared));
            }
        }
        for (car = 0; car < HV(gNum_active_cars); car++) {
            the_car = HV(gActive_car_list)[car];
            if (the_car->car_master_actor->render_style != BR_RSTYLE_NONE) {
                car_x = the_car->car_master_actor->t.t.mat.m[3][0];
                car_z = the_car->car_master_actor->t.t.mat.m[3][2];
                the_car->shadow_intersection_flags = 0;
                oily_count = GetOilSpillCount();
                for (i = 0; i < oily_count; i++) {
                    GetOilSpillDetails(i, &oily_actor, &oily_size);
                    if (oily_actor) {
                        car_radius = the_car->bounds[1].max.v[2] / WORLD_SCALE * 1.5;
                        if (oily_actor->t.t.mat.m[3][0] - oily_size < car_x + car_radius
                            && oily_actor->t.t.mat.m[3][0] + oily_size > car_x - car_radius
                            && oily_actor->t.t.mat.m[3][2] - oily_size < car_z + car_radius
                            && oily_actor->t.t.mat.m[3][2] + oily_size > car_z - car_radius) {
                            the_car->shadow_intersection_flags |= 1 << i;
                        }
                    }
                }
                if (the_car->driver < eDriver_net_human && (!HV(gAction_replay_mode) || !ReplayIsPaused())) {
                    if (HV(gCountdown)) {
                        sine_angle = FRandomBetween(0.4f, 1.6f) * ((double)GetTotalTime() / ((double)HV(gCountdown) * 100.0));
                        sine_angle = frac(sine_angle) * 360.0;
                        sine_angle = FastScalarSin(sine_angle);
                        raw_revs = (double)the_car->red_line * fabs(sine_angle);
                        rev_reducer = (11.0 - (double)HV(gCountdown)) / 10.0;
                        the_car->revs = rev_reducer * raw_revs;
                    } else {
                        the_car->revs = (the_car->speedo_speed / 0.003
                                         - (double)(int)(the_car->speedo_speed / 0.003))
                                        * (double)(the_car->red_line - 800)
                                        + 800.0;
                    }
                }
                for (i = 0; i < the_car->number_of_steerable_wheels; i++) {
                    ControlBoundFunkGroove(the_car->steering_ref[i], the_car->steering_angle);
                }
                for (i = 0; i < 4; i++) {
                    ControlBoundFunkGroove(the_car->rf_sus_ref[i], the_car->rf_sus_position);
                    if ((i & 1) != 0) {
                        ControlBoundFunkGroove(the_car->lf_sus_ref[i], -the_car->lf_sus_position);
                    } else {
                        ControlBoundFunkGroove(the_car->lf_sus_ref[i], the_car->lf_sus_position);
                    }
                }
                for (i = 0; i < 2; i++) {
                    ControlBoundFunkGroove(the_car->rr_sus_ref[i], the_car->rr_sus_position);
                    if ((i & 1) != 0) {
                        ControlBoundFunkGroove(the_car->lr_sus_ref[i], -the_car->lr_sus_position);
                    } else {
                        ControlBoundFunkGroove(the_car->lr_sus_ref[i], the_car->lr_sus_position);
                    }
                }
                if (!HV(gAction_replay_mode) || !ReplayIsPaused()) {
                    wheel_speed = -(the_car->speedo_speed / the_car->non_driven_wheels_circum * (double)HV(gFrame_period));
                    ControlBoundFunkGroovePlus(the_car->non_driven_wheels_spin_ref_1, wheel_speed);
                    ControlBoundFunkGroovePlus(the_car->non_driven_wheels_spin_ref_2, wheel_speed);
                    ControlBoundFunkGroovePlus(the_car->non_driven_wheels_spin_ref_3, wheel_speed);
                    ControlBoundFunkGroovePlus(the_car->non_driven_wheels_spin_ref_4, wheel_speed);
                    if (the_car->driver >= eDriver_net_human) {
                        if (the_car->gear) {
                            wheel_speed = -(the_car->revs
                                            * the_car->speed_revs_ratio
                                            / 6900.0
                                            * (double)the_car->gear
                                            / the_car->driven_wheels_circum
                                            * (double)HV(gFrame_period));
                        } else if (the_car->keys.brake) {
                            wheel_speed = 0.0;
                        } else {
                            wheel_speed = -(the_car->speedo_speed / the_car->driven_wheels_circum * (double)HV(gFrame_period));
                        }
                    }
                    ControlBoundFunkGroovePlus(the_car->driven_wheels_spin_ref_1, wheel_speed);
                    ControlBoundFunkGroovePlus(the_car->driven_wheels_spin_ref_2, wheel_speed);
                    ControlBoundFunkGroovePlus(the_car->driven_wheels_spin_ref_3, wheel_speed);
                    ControlBoundFunkGroovePlus(the_car->driven_wheels_spin_ref_4, wheel_speed);
                }
                if (HV(gAction_replay_mode)) {
                    MungeSpecialVolume((tCollision_info*)the_car);
                } else if (the_car->driver == eDriver_local_human) {
                    abs_omega_x = (fabs(the_car->I.v[0]) + 3.3) / 2.0 * fabs(the_car->omega.v[0]);
                    abs_omega_y = (fabs(the_car->I.v[1]) + 3.57) / 2.0 * fabs(the_car->omega.v[1]);
                    abs_omega_z = (fabs(the_car->I.v[2]) + 0.44) / 2.0 * fabs(the_car->omega.v[2]);
                    spinning_wildly = abs_omega_x > 26.4 || abs_omega_y > 49.98 || abs_omega_z > 3.52;
                    if (spinning_wildly && the_time - HV(gLast_cunning_stunt) > 10000) {
                        if (HV(gWild_start)
                            && (!the_car->last_special_volume || the_car->last_special_volume->gravity_multiplier == 1.0)) {
                            if (the_time - HV(gWild_start) >= 500) {
                                DoFancyHeadup(kFancyHeadupCunningStuntBonus);
                                EarnCredits(HV(gCunning_stunt_bonus)[HV(gProgram_state).skill_level]);
                                HV(gLast_cunning_stunt) = the_time;
                                HV(gOn_me_wheels_start) = 0;
                                HV(gQuite_wild_end) = 0;
                                HV(gQuite_wild_start) = 0;
                                HV(gWoz_upside_down_at_all) = 0;
                            }
                        } else {
                            HV(gWild_start) = the_time;
                        }
                    } else {
                        HV(gWild_start) = 0;
                        spinning_mildly = abs_omega_x > 1.65 || abs_omega_z > 0.22;
                        if (the_car->number_of_wheels_on_ground <= 3) {
                            HV(gOn_me_wheels_start) = 0;
                            if (the_car->number_of_wheels_on_ground || !spinning_mildly) {
                                HV(gQuite_wild_end) = the_time;
                            } else {
                                if (!HV(gQuite_wild_start)) {
                                    HV(gQuite_wild_start) = the_time;
                                }
                                if (the_car->car_master_actor->t.t.mat.m[1][1] < -0.80000001) {
                                    HV(gWoz_upside_down_at_all) = the_time;
                                }
                            }
                        } else {
                            if (!HV(gQuite_wild_end)) {
                                HV(gQuite_wild_end) = the_time;
                            }
                            if (HV(gQuite_wild_start)
                                && the_time - HV(gLast_cunning_stunt) > 10000
                                && HV(gQuite_wild_end) - HV(gQuite_wild_start) >= 2000
                                && HV(gWoz_upside_down_at_all) >= HV(gQuite_wild_start)
                                && HV(gWoz_upside_down_at_all) <= HV(gQuite_wild_end)
                                && (HV(gOn_me_wheels_start) || the_time - HV(gQuite_wild_end) < 300)) {
                                if (HV(gOn_me_wheels_start)) {
                                    if (the_time - HV(gOn_me_wheels_start) > 500
                                        && (!the_car->last_special_volume
                                            || the_car->last_special_volume->gravity_multiplier == 1.0)) {
                                        DoFancyHeadup(kFancyHeadupCunningStuntBonus);
                                        EarnCredits(HV(gCunning_stunt_bonus)[HV(gProgram_state).skill_level]);
                                        HV(gLast_cunning_stunt) = PDGetTotalTime();
                                        HV(gQuite_wild_end) = 0;
                                        HV(gQuite_wild_start) = 0;
                                        HV(gOn_me_wheels_start) = 0;
                                        HV(gWoz_upside_down_at_all) = 0;
                                    }
                                } else {
                                    HV(gOn_me_wheels_start) = the_time;
                                }
                            } else {
                                HV(gQuite_wild_end) = 0;
                                HV(gQuite_wild_start) = 0;
                                HV(gOn_me_wheels_start) = 0;
                                HV(gWoz_upside_down_at_all) = 0;
                            }
                        }
                    }
                }
                if (the_car->driver != eDriver_local_human && the_car->car_model_variable) {
                    distance_from_camera = (car_x - HV(gCamera_to_world).m[3][0])
                                           * (car_x - HV(gCamera_to_world).m[3][0])
                                           + (car_z - HV(gCamera_to_world).m[3][2])
                                             * (car_z - HV(gCamera_to_world).m[3][2])
                                           + (the_car->car_master_actor->t.t.mat.m[3][1] - HV(gCamera_to_world).m[3][1])
                                             * (the_car->car_master_actor->t.t.mat.m[3][1] - HV(gCamera_to_world).m[3][1]);

                    distance_from_camera = distance_from_camera / HV(gCar_simplification_factor)[HV(gGraf_spec_index)][HV(gCar_simplification_level)];
                    if (HV(gNet_mode) && HV(gNet_players)[HV(gIt_or_fox)].car == the_car) {
                        distance_from_camera = 0.0;
                    }
                    for (i = 0; the_car->car_actor_count > i; i++) {
                        if (the_car->car_model_actors[i].min_distance_squared <= distance_from_camera) {
                            SwitchCarActor(the_car, i);
                            break;
                        }
                    }
                }
                if (the_car->screen_material) {
                    the_material = NULL;
                    if (the_car->last_special_volume && the_car->last_special_volume->screen_material) {
                        if (HV(gAction_replay_mode) && the_car->last_special_volume == HV(gDefault_water_spec_vol)) {
                            if (HV(gProgram_state).current_depth_effect.type == eDepth_effect_fog) {
                                the_material = HV(gProgram_state).standard_screen_fog;
                            } else if (HV(gProgram_state).current_depth_effect.sky_texture) {
                                the_material = HV(gProgram_state).standard_screen;
                            } else {
                                the_material = HV(gProgram_state).standard_screen_dark;
                            }
                        } else {
                            the_material = the_car->last_special_volume->screen_material;
                        }
                    } else if (HV(gProgram_state).current_depth_effect.type == eDepth_effect_fog) {
                        the_material = HV(gProgram_state).standard_screen_fog;
                    } else if (HV(gProgram_state).current_depth_effect.sky_texture) {
                        the_material = HV(gProgram_state).standard_screen;
                    } else {
                        the_material = HV(gProgram_state).standard_screen_dark;
                    }
                    update_mat = 0;
                    if (the_material && the_car->screen_material_source != the_material) {
                        the_car->screen_material->flags = the_material->flags;
                        the_car->screen_material->ka = the_material->ka;
                        the_car->screen_material->kd = the_material->kd;
                        the_car->screen_material->ks = the_material->ks;
                        the_car->screen_material->power = the_material->power;
                        the_car->screen_material->index_base = the_material->index_base;
                        the_car->screen_material->index_range = the_material->index_range;
                        the_car->screen_material->colour_map = the_material->colour_map;

                        the_car->screen_material->map_transform = the_material->map_transform;
                        the_car->screen_material->index_shade = HV(gRender_shade_table);
                        the_car->screen_material_source = the_material;
                        update_mat = 1;
                    }
                    if (the_car->screen_material->colour_map) {
                        the_car->screen_material->map_transform.m[2][0] = fmod(car_x, 1.0);
                        the_car->screen_material->map_transform.m[2][1] = fmod(car_z, 1.0);
                        if (!update_mat) {
                            BrMaterialUpdate(the_car->screen_material, 1u);
                        }
                    }
                    if (update_mat) {
                        BrMaterialUpdate(the_car->screen_material, 0x7FFFu);
                    }
                }
            }
        }
    } else {
        original_MungeCarGraphics(pFrame_period);
    }
}

function_hook_state_t function_hook_state_ResetCarScreens = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(function_hook_state_ResetCarScreens)
static void(__cdecl*original_ResetCarScreens)() = (void(__cdecl*)())0x0048701d;
CARM95_HOOK_FUNCTION(original_ResetCarScreens, ResetCarScreens)
void __cdecl ResetCarScreens() {
    int cat;
    int car_count;
    int i;
    tCar_spec *the_car;
    LOG_TRACE("()");

    (void)cat;
    (void)car_count;
    (void)i;
    (void)the_car;

    if (function_hook_state_ResetCarScreens == HOOK_ENABLED) {
        for (cat = eVehicle_self; cat < eVehicle_drone; cat++) {
            car_count = (cat == eVehicle_self) ? 1 : GetCarCount(cat);
            for (i = 0; i < car_count; i++) {
                the_car = (cat == eVehicle_self) ? &HV(gProgram_state).current_car : GetCarSpec(cat, i);
                the_car->last_special_volume = NULL;
            }
        }
        MungeCarGraphics(HV(gFrame_period));
    } else {
        original_ResetCarScreens();
    }
}

function_hook_state_t function_hook_state_GetRaceLeader = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_GetRaceLeader)
static tCar_spec *(__cdecl*original_GetRaceLeader)() = (tCar_spec *(__cdecl*)())0x00487179;
CARM95_HOOK_FUNCTION(original_GetRaceLeader, GetRaceLeader)
tCar_spec* __cdecl GetRaceLeader() {
    int i;
    int score;
    tCar_spec *car;
    LOG_TRACE("()");

    (void)i;
    (void)score;
    (void)car;

    if (function_hook_state_GetRaceLeader == HOOK_ENABLED) {
        assert(0 && "GetRaceLeader not implemented.");
        abort();
    } else {
        return original_GetRaceLeader();
    }
}

function_hook_state_t function_hook_state_AmIGettingBoredWatchingCameraSpin = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_AmIGettingBoredWatchingCameraSpin)
static void(__cdecl*original_AmIGettingBoredWatchingCameraSpin)() = (void(__cdecl*)())0x004876f1;
CARM95_HOOK_FUNCTION(original_AmIGettingBoredWatchingCameraSpin, AmIGettingBoredWatchingCameraSpin)
void __cdecl AmIGettingBoredWatchingCameraSpin() {
    static tU32 time_of_death;
    static tU32 headup_timer;
    tCar_spec *car;
    char s[256];
    LOG_TRACE("()");

    (void)time_of_death;
    (void)headup_timer;
    (void)car;
    (void)s;

    if (function_hook_state_AmIGettingBoredWatchingCameraSpin == HOOK_ENABLED) {
        assert(0 && "AmIGettingBoredWatchingCameraSpin not implemented.");
        abort();
    } else {
        original_AmIGettingBoredWatchingCameraSpin();
    }
}

function_hook_state_t function_hook_state_ViewNetPlayer = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(function_hook_state_ViewNetPlayer)
static void(__cdecl*original_ViewNetPlayer)() = (void(__cdecl*)())0x004870d8;
CARM95_HOOK_FUNCTION(original_ViewNetPlayer, ViewNetPlayer)
void __cdecl ViewNetPlayer() {
    LOG_TRACE("()");


    if (function_hook_state_ViewNetPlayer == HOOK_ENABLED) {
        if (HV(gOpponent_viewing_mode)) {
            if (HV(gProgram_state).cockpit_on) {
                ToggleCockpit();
            }
            HV(gNet_player_to_view_index)++;
            if (HV(gNumber_of_net_players) <= HV(gNet_player_to_view_index)) {
                HV(gNet_player_to_view_index) = -1;
            }
            if (HV(gNet_player_to_view_index) < 0) {
                HV(gCar_to_view) = GetRaceLeader();
            } else {
                HV(gCar_to_view) = HV(gNet_players)[HV(gNet_player_to_view_index)].car;
            }
            HV(gCamera_yaw) = 0;
            InitialiseExternalCamera();
            PositionExternalCamera(HV(gCar_to_view), 200u);
        }
    } else {
        original_ViewNetPlayer();
    }
}

function_hook_state_t function_hook_state_ViewOpponent = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(function_hook_state_ViewOpponent)
static void(__cdecl*original_ViewOpponent)() = (void(__cdecl*)())0x00487248;
CARM95_HOOK_FUNCTION(original_ViewOpponent, ViewOpponent)
void __cdecl ViewOpponent() {
    static int n;
    LOG_TRACE("()");

    (void)n;

    n++;
    if (HV(gNet_mode)) {
        if (n >= HV(gNumber_of_net_players)) {
            n = 0;
        }
        HV(gCar_to_view) = HV(gNet_players)[n].car;
        NewTextHeadupSlot(4, 0, 2000, -3, HV(gNet_players)[n].player_name);
    } else {
        if (n >= HV(gNum_viewable_cars)) {
            n = 0;
        }
        HV(gCar_to_view) = HV(gViewable_car_list)[n];
        NewTextHeadupSlot(4, 0, 2000, -3, HV(gViewable_car_list)[n]->driver_name);
    }
    HV(gCamera_yaw) = 0;
    InitialiseExternalCamera();
    PositionExternalCamera(HV(gCar_to_view), 200u);
}

function_hook_state_t function_hook_state_ToggleCarToCarCollisions = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(function_hook_state_ToggleCarToCarCollisions)
static void(__cdecl*original_ToggleCarToCarCollisions)() = (void(__cdecl*)())0x00487333;
CARM95_HOOK_FUNCTION(original_ToggleCarToCarCollisions, ToggleCarToCarCollisions)
void __cdecl ToggleCarToCarCollisions() {
    LOG_TRACE("()");


    if (function_hook_state_ToggleCarToCarCollisions == HOOK_ENABLED) {
        HV(gCar_car_collisions) = !HV(gCar_car_collisions);
        if (HV(gCar_car_collisions)) {
            NewTextHeadupSlot(4, 0, 3000, -4, "Car Car Collisions");
        } else {
            NewTextHeadupSlot(4, 0, 3000, -4, "Ghost Cars");
        }
    } else {
        original_ToggleCarToCarCollisions();
    }
}

function_hook_state_t function_hook_state_SwapCar = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(function_hook_state_SwapCar)
static void(__cdecl*original_SwapCar)() = (void(__cdecl*)())0x004873a6;
CARM95_HOOK_FUNCTION(original_SwapCar, SwapCar)
void __cdecl SwapCar() {
    LOG_TRACE("()");


    if (function_hook_state_SwapCar == HOOK_ENABLED) {
    } else {
        original_SwapCar();
    }
}

function_hook_state_t function_hook_state_AdjustDownForce = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(function_hook_state_AdjustDownForce)
static void(__cdecl*original_AdjustDownForce)() = (void(__cdecl*)())0x004873b1;
CARM95_HOOK_FUNCTION(original_AdjustDownForce, AdjustDownForce)
void __cdecl AdjustDownForce() {
    char s[100];
    tCar_spec *c;
    LOG_TRACE("()");

    (void)s;
    (void)c;

    if (function_hook_state_AdjustDownForce == HOOK_ENABLED) {
        c = HV(gCar_to_view);
        c->down_force_speed += 50.f;
        if (c->down_force_speed > 2000.f) {
            c->down_force_speed = 50.f;
        }
        if (c->down_force_speed > 300.f) {
            c->down_force_speed = 2000.0;
        }
        sprintf(s, "DownForceSpeed %f", c->down_force_speed);
        NewTextHeadupSlot(4, 0, 1500, -4, s);
    } else {
        original_AdjustDownForce();
    }
}

function_hook_state_t function_hook_state_FreezeMechanics = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(function_hook_state_FreezeMechanics)
static void(__cdecl*original_FreezeMechanics)() = (void(__cdecl*)())0x00487464;
CARM95_HOOK_FUNCTION(original_FreezeMechanics, FreezeMechanics)
void __cdecl FreezeMechanics() {
    LOG_TRACE("()");


    if (function_hook_state_FreezeMechanics == HOOK_ENABLED) {
        HV(gFreeze_mechanics) = !HV(gFreeze_mechanics);
        if (HV(gFreeze_mechanics)) {
            NewTextHeadupSlot(4, 0, 3000, -4, "Mechanics Frozen");
        } else {
            NewTextHeadupSlot(4, 0, 3000, -4, "Thawed Mechanics");
        }
    } else {
        original_FreezeMechanics();
    }
}

function_hook_state_t function_hook_state_PutOpponentsInNeutral = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(function_hook_state_PutOpponentsInNeutral)
static void(__cdecl*original_PutOpponentsInNeutral)() = (void(__cdecl*)())0x004874d7;
CARM95_HOOK_FUNCTION(original_PutOpponentsInNeutral, PutOpponentsInNeutral)
void __cdecl PutOpponentsInNeutral() {
    LOG_TRACE("()");


    if (function_hook_state_PutOpponentsInNeutral == HOOK_ENABLED) {
        HV(gStop_opponents_moving) = !HV(gStop_opponents_moving);
        if (HV(gStop_opponents_moving) == 0) {
            NewTextHeadupSlot(4, 0, 3000, -4, "Opponents in neutral");
        } else {
            NewTextHeadupSlot(4, 0, 3000, -4, "Back in gear");
        }
    } else {
        original_PutOpponentsInNeutral();
    }
}

function_hook_state_t function_hook_state_SetPanningFieldOfView = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_SetPanningFieldOfView)
static void(__cdecl*original_SetPanningFieldOfView)() = (void(__cdecl*)())0x004879d8;
CARM95_HOOK_FUNCTION(original_SetPanningFieldOfView, SetPanningFieldOfView)
void __cdecl SetPanningFieldOfView() {
    br_camera *camera_ptr;
    LOG_TRACE("()");

    (void)camera_ptr;

    if (function_hook_state_SetPanningFieldOfView == HOOK_ENABLED) {
        assert(0 && "SetPanningFieldOfView not implemented.");
        abort();
    } else {
        original_SetPanningFieldOfView();
    }
}

function_hook_state_t function_hook_state_CheckDisablePlingMaterials = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_CheckDisablePlingMaterials)
static void(__cdecl*original_CheckDisablePlingMaterials)(tCar_spec *) = (void(__cdecl*)(tCar_spec *))0x00487a3b;
CARM95_HOOK_FUNCTION(original_CheckDisablePlingMaterials, CheckDisablePlingMaterials)
void __cdecl CheckDisablePlingMaterials(tCar_spec *pCar) {
    br_matrix34 *mat;
    br_scalar height;
    int i;
    LOG_TRACE("(%p)", pCar);

    (void)pCar;
    (void)mat;
    (void)height;
    (void)i;

    if (function_hook_state_CheckDisablePlingMaterials == HOOK_ENABLED) {
        assert(0 && "CheckDisablePlingMaterials not implemented.");
        abort();
    } else {
        original_CheckDisablePlingMaterials(pCar);
    }
}

function_hook_state_t function_hook_state_PositionExternalCamera = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(function_hook_state_PositionExternalCamera)
static void(__cdecl*original_PositionExternalCamera)(tCar_spec *, tU32) = (void(__cdecl*)(tCar_spec *, tU32))0x0048754a;
CARM95_HOOK_FUNCTION(original_PositionExternalCamera, PositionExternalCamera)
void __cdecl PositionExternalCamera(tCar_spec *c, tU32 pTime) {
    static int old_camera_mode;
    br_camera *camera_ptr;
    LOG_TRACE("(%p, %u)", c, pTime);

    (void)c;
    (void)pTime;
    (void)old_camera_mode;
    (void)camera_ptr;

    if (function_hook_state_PositionExternalCamera == HOOK_ENABLED) {
        camera_ptr = (br_camera*)HV(gCamera)->type_data;
        CheckCameraHither();
        AmIGettingBoredWatchingCameraSpin();
        if ((!HV(gAction_replay_mode) || HV(gAction_replay_camera_mode) == eAction_replay_standard) && old_camera_mode != -1) {
            camera_ptr->field_of_view = BrDegreeToAngle(HV(gCamera_angle));
            old_camera_mode = -1;
        }
        if (!HV(gProgram_state).cockpit_on) {
            if (HV(gOpponent_viewing_mode) && HV(gAction_replay_mode)) {
                c = &HV(gProgram_state).current_car;
            } else {
                c = HV(gCar_to_view);
            }
            if (c->car_master_actor->t.t.mat.m[3][0] <= 500.0) {
                if (HV(gAction_replay_mode) && HV(gAction_replay_camera_mode)) {
                    // Hit when going into replay mode!!!
                    // LOG_PANIC("%d, %d", HV(gAction_replay_mode), HV(gAction_replay_camera_mode));
                    if (HV(gAction_replay_camera_mode) == eAction_replay_action && (CheckDisablePlingMaterials(c), IncidentCam(c, pTime))) {
                        SetPanningFieldOfView();
                        EnablePlingMaterials();
                        old_camera_mode = HV(gAction_replay_camera_mode);
                    } else {
                        CheckDisablePlingMaterials(c);
                        SetPanningFieldOfView();
                        if (HV(gAction_replay_camera_mode) != old_camera_mode) {
                            SetUpPanningCamera(c);
                            old_camera_mode = HV(gAction_replay_camera_mode);
                        }
                        PanningExternalCamera(c, pTime);
                        EnablePlingMaterials();
                    }
                } else {
                    NormalPositionExternalCamera(c, pTime);
                }
            }
        }
    } else {
        original_PositionExternalCamera(c, pTime);
    }
}

function_hook_state_t function_hook_state_CameraBugFix = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_CameraBugFix)
static void(__cdecl*original_CameraBugFix)(tCar_spec *, tU32) = (void(__cdecl*)(tCar_spec *, tU32))0x00487b2c;
CARM95_HOOK_FUNCTION(original_CameraBugFix, CameraBugFix)
void __cdecl CameraBugFix(tCar_spec *c, tU32 pTime) {
    br_matrix34 mat;
    br_matrix34 *m2;
    br_vector3 tv;
    LOG_TRACE("(%p, %u)", c, pTime);

    (void)c;
    (void)pTime;
    (void)mat;
    (void)m2;
    (void)tv;

    if (function_hook_state_CameraBugFix == HOOK_ENABLED) {
        assert(0 && "CameraBugFix not implemented.");
        abort();
    } else {
        original_CameraBugFix(c, pTime);
    }
}

function_hook_state_t function_hook_state_PossibleRemoveNonCarFromWorld = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_PossibleRemoveNonCarFromWorld)
static int(__cdecl*original_PossibleRemoveNonCarFromWorld)(br_actor *) = (int(__cdecl*)(br_actor *))0x0048876d;
CARM95_HOOK_FUNCTION(original_PossibleRemoveNonCarFromWorld, PossibleRemoveNonCarFromWorld)
int __cdecl PossibleRemoveNonCarFromWorld(br_actor *pActor) {
    tU8 cx;
    tU8 cz;
    tTrack_spec *track_spec;
    LOG_TRACE("(%p)", pActor);

    (void)pActor;
    (void)cx;
    (void)cz;
    (void)track_spec;

    if (function_hook_state_PossibleRemoveNonCarFromWorld == HOOK_ENABLED) {
        assert(0 && "PossibleRemoveNonCarFromWorld not implemented.");
        abort();
    } else {
        return original_PossibleRemoveNonCarFromWorld(pActor);
    }
}

function_hook_state_t function_hook_state_PutNonCarBackInWorld = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_PutNonCarBackInWorld)
static void(__cdecl*original_PutNonCarBackInWorld)(br_actor *) = (void(__cdecl*)(br_actor *))0x004887e9;
CARM95_HOOK_FUNCTION(original_PutNonCarBackInWorld, PutNonCarBackInWorld)
void __cdecl PutNonCarBackInWorld(br_actor *pActor) {
    tU8 cx;
    tU8 cz;
    tTrack_spec *track_spec;
    LOG_TRACE("(%p)", pActor);

    (void)pActor;
    (void)cx;
    (void)cz;
    (void)track_spec;

    if (function_hook_state_PutNonCarBackInWorld == HOOK_ENABLED) {
        assert(0 && "PutNonCarBackInWorld not implemented.");
        abort();
    } else {
        original_PutNonCarBackInWorld(pActor);
    }
}

function_hook_state_t function_hook_state_IncidentCam = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_IncidentCam)
static int(__cdecl*original_IncidentCam)(tCar_spec *, tU32) = (int(__cdecl*)(tCar_spec *, tU32))0x00487b89;
CARM95_HOOK_FUNCTION(original_IncidentCam, IncidentCam)
int __cdecl IncidentCam(tCar_spec *c, tU32 pTime) {
    br_matrix34 *m2;
    br_matrix34 mat;
    br_vector3 tv;
    br_vector3 tv2;
    br_vector3 perp;
    br_vector3 vertical;
    br_vector3 murderer_pos;
    br_scalar ts;
    tCar_spec *car2;
    static tU32 next_incident_time;
    static tIncident_type type;
    static float severity;
    static tIncident_info info;
    static int random;
    static int count;
    br_scalar temp;
    br_vector3 old_cam_pos;
    int removed;
    br_scalar __block0___scale;
    br_scalar __block1___scale;
    br_scalar __block2___scale;
    LOG_TRACE("(%p, %u)", c, pTime);

    (void)c;
    (void)pTime;
    (void)m2;
    (void)mat;
    (void)tv;
    (void)tv2;
    (void)perp;
    (void)vertical;
    (void)murderer_pos;
    (void)ts;
    (void)car2;
    (void)next_incident_time;
    (void)type;
    (void)severity;
    (void)info;
    (void)random;
    (void)count;
    (void)temp;
    (void)old_cam_pos;
    (void)removed;
    (void)__block0___scale;
    (void)__block1___scale;
    (void)__block2___scale;

    if (function_hook_state_IncidentCam == HOOK_ENABLED) {
        assert(0 && "IncidentCam not implemented.");
        abort();
    } else {
        return original_IncidentCam(c, pTime);
    }
}

function_hook_state_t function_hook_state_MoveCamToIncident = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_MoveCamToIncident)
static int(__cdecl*original_MoveCamToIncident)(tCar_spec *, tIncident_type *, float *, tIncident_info *, tU32 *) = (int(__cdecl*)(tCar_spec *, tIncident_type *, float *, tIncident_info *, tU32 *))0x00488849;
CARM95_HOOK_FUNCTION(original_MoveCamToIncident, MoveCamToIncident)
int __cdecl MoveCamToIncident(tCar_spec *c, tIncident_type *type, float *severity, tIncident_info *info, tU32 *next_incident_time) {
    tU32 next_incident_time2;
    tU32 t;
    tIncident_type type2;
    float severity2;
    tIncident_info info2;
    br_vector3 pos;
    br_vector3 left;
    br_vector3 right;
    br_vector3 vertical;
    br_vector3 tv;
    br_vector3 tv2;
    br_vector3 perp;
    int test;
    br_scalar __block0___scale;
    LOG_TRACE("(%p, %p, %p, %p, %p)", c, type, severity, info, next_incident_time);

    (void)c;
    (void)type;
    (void)severity;
    (void)info;
    (void)next_incident_time;
    (void)next_incident_time2;
    (void)t;
    (void)type2;
    (void)severity2;
    (void)info2;
    (void)pos;
    (void)left;
    (void)right;
    (void)vertical;
    (void)tv;
    (void)tv2;
    (void)perp;
    (void)test;
    (void)__block0___scale;

    if (function_hook_state_MoveCamToIncident == HOOK_ENABLED) {
        assert(0 && "MoveCamToIncident not implemented.");
        abort();
    } else {
        return original_MoveCamToIncident(c, type, severity, info, next_incident_time);
    }
}

function_hook_state_t function_hook_state_PanningExternalCamera = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_PanningExternalCamera)
static void(__cdecl*original_PanningExternalCamera)(tCar_spec *, tU32) = (void(__cdecl*)(tCar_spec *, tU32))0x00488d45;
CARM95_HOOK_FUNCTION(original_PanningExternalCamera, PanningExternalCamera)
void __cdecl PanningExternalCamera(tCar_spec *c, tU32 pTime) {
    br_matrix34 *m2;
    br_matrix34 *m1;
    br_vector3 tv;
    br_scalar ts;
    static int inside_camera_zone;
    LOG_TRACE("(%p, %u)", c, pTime);

    (void)c;
    (void)pTime;
    (void)m2;
    (void)m1;
    (void)tv;
    (void)ts;
    (void)inside_camera_zone;

    if (function_hook_state_PanningExternalCamera == HOOK_ENABLED) {
        assert(0 && "PanningExternalCamera not implemented.");
        abort();
    } else {
        original_PanningExternalCamera(c, pTime);
    }
}

function_hook_state_t function_hook_state_CheckForWall = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_CheckForWall)
static int(__cdecl*original_CheckForWall)(br_vector3 *, br_vector3 *) = (int(__cdecl*)(br_vector3 *, br_vector3 *))0x00488ed6;
CARM95_HOOK_FUNCTION(original_CheckForWall, CheckForWall)
int __cdecl CheckForWall(br_vector3 *start, br_vector3 *end) {
    br_vector3 dir;
    br_material *material;
    br_vector3 normal;
    br_scalar d;
    LOG_TRACE("(%p, %p)", start, end);

    (void)start;
    (void)end;
    (void)dir;
    (void)material;
    (void)normal;
    (void)d;

    if (function_hook_state_CheckForWall == HOOK_ENABLED) {
        assert(0 && "CheckForWall not implemented.");
        abort();
    } else {
        return original_CheckForWall(start, end);
    }
}

function_hook_state_t function_hook_state_SetUpPanningCamera = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_SetUpPanningCamera)
static void(__cdecl*original_SetUpPanningCamera)(tCar_spec *) = (void(__cdecl*)(tCar_spec *))0x00488f50;
CARM95_HOOK_FUNCTION(original_SetUpPanningCamera, SetUpPanningCamera)
void __cdecl SetUpPanningCamera(tCar_spec *c) {
    br_vector3 pos;
    br_vector3 perp;
    br_vector3 dir;
    br_vector3 tv;
    br_vector3 tv2;
    br_scalar ts;
    tU32 time;
    tU32 t;
    tU32 t2;
    tU32 time_step;
    br_matrix34 *m2;
    br_matrix34 *m1;
    br_vector3 left;
    br_vector3 right;
    br_vector3 car_centre;
    int left_score;
    int right_score;
    LOG_TRACE("(%p)", c);

    (void)c;
    (void)pos;
    (void)perp;
    (void)dir;
    (void)tv;
    (void)tv2;
    (void)ts;
    (void)time;
    (void)t;
    (void)t2;
    (void)time_step;
    (void)m2;
    (void)m1;
    (void)left;
    (void)right;
    (void)car_centre;
    (void)left_score;
    (void)right_score;

    if (function_hook_state_SetUpPanningCamera == HOOK_ENABLED) {
        assert(0 && "SetUpPanningCamera not implemented.");
        abort();
    } else {
        original_SetUpPanningCamera(c);
    }
}

function_hook_state_t function_hook_state_SaveCameraPosition = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(function_hook_state_SaveCameraPosition)
static void(__cdecl*original_SaveCameraPosition)(int) = (void(__cdecl*)(int))0x0048949c;
CARM95_HOOK_FUNCTION(original_SaveCameraPosition, SaveCameraPosition)
void __cdecl SaveCameraPosition(int i) {
    LOG_TRACE("(%d)", i);

    (void)i;

    if (function_hook_state_SaveCameraPosition == HOOK_ENABLED) {
        if (HV(gSave_camera)[i].saved != 1) {
            HV(gSave_camera)[i].zoom = HV(gCamera_zoom);
            HV(gSave_camera)[i].yaw = HV(gCamera_yaw);
            HV(gSave_camera)[i].saved = 1;
        }
    } else {
        original_SaveCameraPosition(i);
    }
}

function_hook_state_t function_hook_state_RestoreCameraPosition = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(function_hook_state_RestoreCameraPosition)
static void(__cdecl*original_RestoreCameraPosition)(int) = (void(__cdecl*)(int))0x004894f8;
CARM95_HOOK_FUNCTION(original_RestoreCameraPosition, RestoreCameraPosition)
void __cdecl RestoreCameraPosition(int i) {
    LOG_TRACE("(%d)", i);

    (void)i;

    if (function_hook_state_RestoreCameraPosition == HOOK_ENABLED) {
        if (HV(gSave_camera)[i].saved != 0) {
            HV(gCamera_zoom) = HV(gSave_camera)[i].zoom;
            HV(gCamera_yaw) = HV(gSave_camera)[i].yaw;
            HV(gSave_camera)[i].saved = 0;
        }
    } else {
        original_RestoreCameraPosition(i);
    }
}

function_hook_state_t function_hook_state_NormalPositionExternalCamera = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(function_hook_state_NormalPositionExternalCamera)
static void(__cdecl*original_NormalPositionExternalCamera)(tCar_spec *, tU32) = (void(__cdecl*)(tCar_spec *, tU32))0x00489553;
CARM95_HOOK_FUNCTION(original_NormalPositionExternalCamera, NormalPositionExternalCamera)
void __cdecl NormalPositionExternalCamera(tCar_spec *c, tU32 pTime) {
    br_matrix34 *m2;
    br_matrix34 *m1;
    br_scalar time;
    br_scalar ts;
    br_scalar ts2;
    br_scalar dist;
    br_scalar height_inc;
    br_scalar l;
    br_scalar frac;
    br_vector3 vn;
    br_vector3 a;
    br_vector3 b;
    br_vector3 tv;
    br_angle yaw;
    br_angle theta;
    br_scalar d;
    int face;
    int i;
    int swoop;
    int manual_swing;
    int manual_zoom;
    br_vector3 old_camera_pos;
    br_scalar __block0___scale;
    br_scalar __block1___scale;
    LOG_TRACE("(%p, %u)", c, pTime);

    (void)c;
    (void)pTime;
    (void)m2;
    (void)m1;
    (void)time;
    (void)ts;
    (void)ts2;
    (void)dist;
    (void)height_inc;
    (void)l;
    (void)frac;
    (void)vn;
    (void)a;
    (void)b;
    (void)tv;
    (void)yaw;
    (void)theta;
    (void)d;
    (void)face;
    (void)i;
    (void)swoop;
    (void)manual_swing;
    (void)manual_zoom;
    (void)old_camera_pos;
    (void)__block0___scale;
    (void)__block1___scale;

    if (function_hook_state_NormalPositionExternalCamera == HOOK_ENABLED) {
        m1 = &HV(gCamera)->t.t.mat;
        m2 = &c->car_master_actor->t.t.mat;
        swoop = HV(gCountdown) && c->pos.v[1] + 0.001f < HV(gCamera_height);
        manual_swing = HV(gOld_yaw__car) != HV(gCamera_yaw) || swoop;
        manual_zoom = (double)HV(gOld_zoom) != HV(gCamera_zoom);
        old_camera_pos = *(br_vector3*)&m1->m[3][0];
        if (!HV(gProgram_state).cockpit_on) {
            if (swoop) {
                HV(gCamera_yaw) = 0;
                manual_swing = 1;
            }
            if (fabs(c->speedo_speed) > 0.0006f && HV(gCamera_mode) > 0) {
                HV(gCamera_mode) = -1;
                HV(gCamera_sign) = m2->m[2][1] * c->direction.v[1]
                               + m2->m[2][2] * c->direction.v[2]
                               + m2->m[2][0] * c->direction.v[0]
                               > 0.0;
            }
            if (c->frame_collision_flag && HV(gCamera_mode) != -2) {
                HV(gCamera_mode) = 1;
            }
            if (HV(gCar_flying) || HV(gCamera_reset) || HV(gCamera_mode) == -2) {
                HV(gCamera_mode) = 0;
            }
            d = sqrtf((float)HV(gCamera_zoom)) + 0.57971013f;
            if (!HV(gCamera_mode) || HV(gCamera_mode) == -1) {
                vn = c->direction;
                MoveWithWheels(c, &vn, manual_swing);
                vn.v[1] = 0.0;
                BrVector3Normalise(&vn, &vn);
                if (HV(gCar_flying)) {
                    HV(gCamera_sign) = 0;
                }
                SwingCamera(c, m2, m1, &vn, pTime);
                BrVector3Scale(&a, &vn, d);
                m1->m[3][0] = c->pos.v[0] - a.v[0];
                m1->m[3][1] = c->pos.v[1] - a.v[1];
                m1->m[3][2] = c->pos.v[2] - a.v[2];
                HV(gView_direction) = vn;
            }
            if (HV(gCamera_mode) == 1) {
                if (manual_swing || manual_zoom) {
                    old_camera_pos = HV(gCamera_pos_before_collide);
                }
                BrVector3Sub(&a, &c->pos, &old_camera_pos);
                a.v[1] = 0.0;
                if (manual_swing) {
                    DrVector3RotateY(&a, (HV(gCamera_sign) == 0 ? 1 : -1) * (HV(gCamera_yaw) - HV(gOld_yaw__car)));
                    HV(gCamera_yaw) = HV(gOld_yaw__car);
                }
                BrVector3Normalise(&vn, &a);
                HV(gView_direction) = vn;
                BrVector3Scale(&vn, &vn, -d);
                BrVector3Accumulate(&a, &vn);
                dist = BrVector3Length(&a);
                l = (float)pTime / 1000.0f * (dist + 1.0f) / dist;
                if (l < 1.0f && BrVector3Dot(&a, &vn) > 0.0f) {
                    BrVector3Scale(&a, &a, (l - 1.f));
                    BrVector3Accumulate(&vn, &a);
                }
                m1->m[3][0] = c->pos.v[0] + vn.v[0];
                m1->m[3][1] = c->pos.v[1] + vn.v[1];
                m1->m[3][2] = c->pos.v[2] + vn.v[2];
            }
            height_inc = HV(gCamera_zoom) * HV(gCamera_zoom) + 0.3f;
            time = pTime * 0.001f;
            if (!HV(gCamera_frozen) || HV(gAction_replay_mode)) {
                if (pTime < 5000) {
                    if (swoop) {
                        if (time > 0.2) {
                            time = 0.2;
                        }
                        HV(gCamera_height) -= time * 5.0;
                        if (HV(gCamera_height) < c->pos.v[1]) {
                            HV(gCamera_height) = c->pos.v[1];
                        }
                    } else {
                        HV(gCamera_height) = time * 5.0 * c->pos.v[1] + HV(gCamera_height);
                        HV(gCamera_height) = HV(gCamera_height) / (time * 5.0 + 1.0);
                    }
                } else {
                    HV(gCamera_height) = c->pos.v[1];
                }
            }
            l = c->direction.v[1] * d;
            if (l > 0) {
                if (c->pos.v[1] - l - height_inc / 2.0f > HV(gCamera_height)) {
                    HV(gCamera_height) = c->pos.v[1] - l - height_inc / 2.0f;
                }
            }

            m1->m[3][1] = height_inc + HV(gCamera_height);
            HV(gCamera_pos_before_collide) = *(br_vector3*)&m1->m[3][0];
            CollideCameraWithOtherCars(&c->pos, (br_vector3*)m1->m[3]);
            if (manual_swing || manual_zoom) {
                CollideCamera2(&c->pos, (br_vector3*)m1->m[3], &old_camera_pos, 1);
            } else {
                CollideCamera2(&c->pos, (br_vector3*)m1->m[3], &old_camera_pos, 0);
            }
            if (HV(gCamera_has_collided) && swoop) {
                HV(gCamera_height) = c->pos.v[1];
            }
            PointCameraAtCar(c, m2, m1);
        }
        HV(gOld_yaw__car) = HV(gCamera_yaw);
        HV(gOld_zoom) = (br_angle)HV(gCamera_zoom);
    } else {
        original_NormalPositionExternalCamera(c, pTime);
    }
}

function_hook_state_t function_hook_state_MoveWithWheels = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(function_hook_state_MoveWithWheels)
static void(__cdecl*original_MoveWithWheels)(tCar_spec *, br_vector3 *, int) = (void(__cdecl*)(tCar_spec *, br_vector3 *, int))0x00489dc2;
CARM95_HOOK_FUNCTION(original_MoveWithWheels, MoveWithWheels)
void __cdecl MoveWithWheels(tCar_spec *c, br_vector3 *vn, int manual_swing) {
    br_angle yaw;
    br_angle theta;
    static int move_with_wheels;
    LOG_TRACE("(%p, %p, %d)", c, vn, manual_swing);

    (void)c;
    (void)vn;
    (void)manual_swing;
    (void)yaw;
    (void)theta;
    (void)move_with_wheels;

    if (function_hook_state_MoveWithWheels == HOOK_ENABLED) {
        if (c->speed <= 0.000099999997 && !HV(gCamera_mode)) {
            if (manual_swing) {
                if (HV(gCamera_yaw) <= 32760u) {
                    yaw = HV(gCamera_yaw);
                } else {
                    yaw = HV(gCamera_yaw) - 32760;
                }
                if (yaw <= 8190u || yaw >= 24570u) {
                    if (!move_with_wheels) {
                        theta = BrRadianToAngle(atan2(c->wpos[0].v[2] * c->curvature, 1.0));
                        HV(gCamera_yaw) -= (-2 * HV(gCamera_sign) + 1) * theta;
                        move_with_wheels = 1;
                    }
                } else if (move_with_wheels) {
                    theta = BrRadianToAngle(atan2(c->wpos[0].v[2] * c->curvature, 1.0));
                    HV(gCamera_yaw) += (-2 * HV(gCamera_sign) + 1) * theta;
                    move_with_wheels = 0;
                }
            }
            if (move_with_wheels) {
                if (!HV(gCar_flying)) {
                    theta = BrRadianToAngle(atan2(c->wpos[0].v[2] * c->curvature, 1.0));
                    DrVector3RotateY(vn, theta);
                }
            }
        }
    } else {
        original_MoveWithWheels(c, vn, manual_swing);
    }
}

function_hook_state_t function_hook_state_SwingCamera = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(function_hook_state_SwingCamera)
static void(__cdecl*original_SwingCamera)(tCar_spec *, br_matrix34 *, br_matrix34 *, br_vector3 *, tU32) = (void(__cdecl*)(tCar_spec *, br_matrix34 *, br_matrix34 *, br_vector3 *, tU32))0x00489f7c;
CARM95_HOOK_FUNCTION(original_SwingCamera, SwingCamera)
void __cdecl SwingCamera(tCar_spec *c, br_matrix34 *m1, br_matrix34 *m2, br_vector3 *vn, tU32 pTime) {
    int i;
    br_scalar ts;
    br_angle yaw;
    br_angle theta;
    br_angle alpha;
    br_scalar sin_dtheta;
    br_scalar cos_dtheta;
    br_scalar sign;
    int manual_swing;
    static br_angle omega = 0;
    static int elapsed_time = -1;
    static br_vector3 old_vn;
    LOG_TRACE("(%p, %p, %p, %p, %u)", c, m1, m2, vn, pTime);

    (void)c;
    (void)m1;
    (void)m2;
    (void)vn;
    (void)pTime;
    (void)i;
    (void)ts;
    (void)yaw;
    (void)theta;
    (void)alpha;
    (void)sin_dtheta;
    (void)cos_dtheta;
    (void)sign;
    (void)manual_swing;
    (void)omega;
    (void)elapsed_time;
    (void)old_vn;

    if (function_hook_state_SwingCamera == HOOK_ENABLED) {
        manual_swing = HV(gOld_yaw__car) != HV(gCamera_yaw);
        if (elapsed_time > 500) {
            elapsed_time = -1;
        }
        if (elapsed_time >= 0) {
            elapsed_time += pTime;
        }
        sign = -(m1->m[2][0] * vn->v[0] + m1->m[2][1] * vn->v[1] + m1->m[2][2] * vn->v[2]);
        ts = BrVector3Dot(vn, &old_vn);

        old_vn = *vn;
        if ((sign < 0.0) == HV(gCamera_sign)) {
            elapsed_time = -1;
        } else if (ts <= 0.0 || elapsed_time >= 0) {
            if (elapsed_time < 0) {
                elapsed_time = 0;
            }
            if (elapsed_time < 500 && sign <= 0.0) {
                vn->v[0] = -vn->v[0];
                vn->v[1] = -vn->v[1];
                vn->v[2] = -vn->v[2];
            } else {
                elapsed_time = 500;
                if (sign <= 0.0) {
                    ts = 0.0006f;
                } else {
                    ts = 0.0001f;
                }
                if (fabs(c->speedo_speed) <= ts || HV(gCar_flying)) {
                    vn->v[0] = -vn->v[0];
                    vn->v[1] = -vn->v[1];
                    vn->v[2] = -vn->v[2];
                } else {
                    HV(gCamera_sign) = HV(gCamera_sign) == 0;
                    omega = BrDegreeToAngle(pTime * 0.03);
                    if (HV(gCamera_yaw) <= 32760) {
                        yaw = HV(gCamera_yaw);
                    } else {
                        yaw = HV(gCamera_yaw) - 32760;
                    }
                    if ((uint16_t)(HV(gCamera_yaw) + 16380) <= 32760) {
                        if (yaw > 8190 && yaw < 24570) {
                            HV(gCamera_yaw) = 32760 - HV(gCamera_yaw);
                        }
                    } else {
                        HV(gCamera_yaw) = 32760 - HV(gCamera_yaw);
                    }
                }
            }
        } else {
            HV(gCamera_sign) = HV(gCamera_sign) == 0;
            if (HV(gCamera_yaw) <= 32760) {
                yaw = HV(gCamera_yaw);
            } else {
                yaw = HV(gCamera_yaw) - 32760;
            }
            if (yaw > 8190 && yaw < 24570) {
                HV(gCamera_yaw) = -HV(gCamera_yaw);
            }
        }
        if (HV(gCamera_sign)) {
            yaw = -HV(gCamera_yaw);
        } else {
            yaw = HV(gCamera_yaw);
        }
        if (!HV(gCar_flying)) {
            DrVector3RotateY(vn, yaw);
        }
        sin_dtheta = 0.0;
        br_scalar v16 = vn->v[0] * HV(gView_direction).v[2] - vn->v[2] * HV(gView_direction).v[0];
        br_scalar v17 = vn->v[0] * HV(gView_direction).v[0] + vn->v[2] * HV(gView_direction).v[2];

        br_angle v8 = BrRadianToAngle(sqrt(c->omega.v[2] * c->omega.v[2] + c->omega.v[0] * c->omega.v[0] + c->omega.v[1] * c->omega.v[1]) * pTime / 1000.0);
        sin_dtheta = sin(BrAngleToRadian(v8)) + 0.1;

        if (omega || HV(gCamera_reset) || (c->speed < 0.0001f && !manual_swing) || HV(gCamera_mode) == -1 || (v17 > 0.0 && !manual_swing && fabs(v16) > sin_dtheta)) {
            if (!HV(gCar_flying)) {
                theta = BrRadianToAngle(asin(sin_dtheta));
                if (omega < theta) {
                    omega = theta;
                }
                if (!omega) {
                    omega = BrDegreeToAngle(pTime * 0.03); // (__int64)((double)(int)pTime * 0.03 * 182.0444444444445);
                }
                cos_dtheta = cos(BrAngleToRadian(omega));
                if (cos_dtheta <= v17) {
                    omega = 0;
                    HV(gCamera_mode) = 0;
                } else {
                    ts = BrAngleToRadian(omega);
                    if (v16 <= 0.0) {
                        vn->v[0] = cos(ts) * HV(gView_direction).v[0] - sin(ts) * HV(gView_direction).v[2];
                        vn->v[2] = sin(ts) * HV(gView_direction).v[0] + cos(ts) * HV(gView_direction).v[2];
                    } else {
                        vn->v[0] = sin(ts) * HV(gView_direction).v[2] + cos(ts) * HV(gView_direction).v[0];
                        vn->v[2] = cos(ts) * HV(gView_direction).v[2] - sin(ts) * HV(gView_direction).v[0];
                    }
                    omega += BrDegreeToAngle(pTime * 0.03);
                    if (BrDegreeToAngle(pTime * 0.1) < omega) {
                        omega = BrDegreeToAngle(pTime * 0.1);
                    }
                    if (omega < theta) {
                        omega = theta;
                    }
                }
            }
        }
    } else {
        original_SwingCamera(c, m1, m2, vn, pTime);
    }
}

function_hook_state_t function_hook_state_PointCameraAtCar = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(function_hook_state_PointCameraAtCar)
static void(__cdecl*original_PointCameraAtCar)(tCar_spec *, br_matrix34 *, br_matrix34 *) = (void(__cdecl*)(tCar_spec *, br_matrix34 *, br_matrix34 *))0x0048a73b;
CARM95_HOOK_FUNCTION(original_PointCameraAtCar, PointCameraAtCar)
void __cdecl PointCameraAtCar(tCar_spec *c, br_matrix34 *m1, br_matrix34 *m2) {
    br_vector3 vn;
    br_vector3 tv;
    br_vector3 tv2;
    br_scalar dist;
    br_scalar frac;
    br_angle theta;
    br_vector3 *pos;
    br_camera *camera_ptr;
    br_angle off_centre_angle;
    int swoop;
    br_scalar __block0___scale;
    LOG_TRACE("(%p, %p, %p)", c, m1, m2);

    (void)c;
    (void)m1;
    (void)m2;
    (void)vn;
    (void)tv;
    (void)tv2;
    (void)dist;
    (void)frac;
    (void)theta;
    (void)pos;
    (void)camera_ptr;
    (void)off_centre_angle;
    (void)swoop;
    (void)__block0___scale;

    if (function_hook_state_PointCameraAtCar == HOOK_ENABLED) {
        camera_ptr = HV(gCamera)->type_data;
        theta = camera_ptr->field_of_view / 5;
        swoop = HV(gCountdown) && c->pos.v[1] + 0.01f < HV(gCamera_height);
        if (0) {
            BrVector3Sub(&tv, &HV(gAverage_grid_position), &c->pos);
            frac = (HV(gCamera_height) - c->pos.v[1]) / 10.0f;
            BrVector3Scale(&tv, &tv, frac);
            BrVector3Accumulate(&tv, &c->pos);
            pos = &tv;
            theta = (1.0f - frac) * (float)theta;
        } else {
            pos = &c->pos;
        }
        BrVector3Set(&vn, c->pos.v[0] - m2->m[3][0], 0.f, c->pos.v[2] - m2->m[3][2]);
        BrVector3Normalise(&vn, &vn);
        m2->m[0][0] = -vn.v[2];
        m2->m[0][1] = 0.0f;
        m2->m[0][2] = vn.v[0];
        m2->m[1][0] = 0.0f;
        m2->m[1][1] = 1.0f;
        m2->m[1][2] = 0.0f;
        m2->m[2][0] = -vn.v[0];
        m2->m[2][1] = 0.0f;
        m2->m[2][2] = -vn.v[2];
        tv2.v[0] = pos->v[0] - m2->m[3][0];
        tv2.v[1] = pos->v[1] - m2->m[3][1];
        tv2.v[2] = pos->v[2] - m2->m[3][2];
        dist = BrVector3Dot(&tv2, &vn);
        BrMatrix34PreRotateX(m2, theta - BrRadianToAngle(atan2f(m2->m[3][1] - pos->v[1], dist)));
    } else {
        original_PointCameraAtCar(c, m1, m2);
    }
}

function_hook_state_t function_hook_state_PointCamera = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_PointCamera)
static void(__cdecl*original_PointCamera)(br_vector3 *, br_matrix34 *) = (void(__cdecl*)(br_vector3 *, br_matrix34 *))0x0048aa19;
CARM95_HOOK_FUNCTION(original_PointCamera, PointCamera)
void __cdecl PointCamera(br_vector3 *pos, br_matrix34 *m2) {
    br_vector3 vn;
    br_scalar dist;
    br_angle theta;
    br_camera *camera_ptr;
    br_scalar __block0___scale;
    LOG_TRACE("(%p, %p)", pos, m2);

    (void)pos;
    (void)m2;
    (void)vn;
    (void)dist;
    (void)theta;
    (void)camera_ptr;
    (void)__block0___scale;

    if (function_hook_state_PointCamera == HOOK_ENABLED) {
        assert(0 && "PointCamera not implemented.");
        abort();
    } else {
        original_PointCamera(pos, m2);
    }
}

function_hook_state_t function_hook_state_CollideCamera2 = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(function_hook_state_CollideCamera2)
static int(__cdecl*original_CollideCamera2)(br_vector3 *, br_vector3 *, br_vector3 *, int) = (int(__cdecl*)(br_vector3 *, br_vector3 *, br_vector3 *, int))0x0048abbb;
CARM95_HOOK_FUNCTION(original_CollideCamera2, CollideCamera2)
int __cdecl CollideCamera2(br_vector3 *car_pos, br_vector3 *cam_pos, br_vector3 *old_camera_pos, int manual_move) {
    int i;
    int k;
    br_vector3 a;
    br_vector3 b;
    br_vector3 vn;
    br_vector3 tv;
    br_vector3 tv2;
    br_scalar l;
    br_scalar d;
    br_scalar ts;
    br_scalar ts2;
    br_scalar dist;
    br_scalar hither;
    br_angle theta;
    tBounds bnds;
    br_matrix34 mat;
    br_material *material;
    br_scalar alpha;
    br_scalar sa;
    br_scalar sb;
    br_scalar sc;
    tFace_ref face_list[3];
    br_scalar __block0___scale;
    br_scalar __block1___scale;
    LOG_TRACE("(%p, %p, %p, %d)", car_pos, cam_pos, old_camera_pos, manual_move);

    (void)car_pos;
    (void)cam_pos;
    (void)old_camera_pos;
    (void)manual_move;
    (void)i;
    (void)k;
    (void)a;
    (void)b;
    (void)vn;
    (void)tv;
    (void)tv2;
    (void)l;
    (void)d;
    (void)ts;
    (void)ts2;
    (void)dist;
    (void)hither;
    (void)theta;
    (void)bnds;
    (void)mat;
    (void)material;
    (void)alpha;
    (void)sa;
    (void)sb;
    (void)sc;
    (void)face_list;
    (void)__block0___scale;
    (void)__block1___scale;

    if (function_hook_state_CollideCamera2 == HOOK_ENABLED) {
//#ifdef DETHRACE_FIX_BUGS
        ts2 = 0.f;
//#endif
        hither = ((br_camera*)HV(gCamera)->type_data)->hither_z * 3.0;
        HV(gCamera_has_collided) = 0;
        for (i = 0; i < 1; i++) {
            tv.v[0] = cam_pos->v[0] - car_pos->v[0];
            tv.v[1] = cam_pos->v[1] - car_pos->v[1];
            tv.v[2] = cam_pos->v[2] - car_pos->v[2];
            dist = sqrt(tv.v[1] * tv.v[1] + tv.v[2] * tv.v[2] + tv.v[0] * tv.v[0]);
            tv.v[0] = tv.v[0] * 1.2;
            tv.v[1] = tv.v[1] * 1.2;
            tv.v[2] = tv.v[2] * 1.2;
            FindFace(car_pos, &tv, &a, &ts, &material);
            if (ts <= 1.0) {
                HV(gCamera_has_collided) = 1;
                if (a.v[1] * tv.v[1] + a.v[2] * tv.v[2] + a.v[0] * tv.v[0] > 0.0) {
                    a.v[0] = -a.v[0];
                    a.v[1] = -a.v[1];
                    a.v[2] = -a.v[2];
                }
                if (HV(gCamera_mode) == 1 && !manual_move) {
                    tv2.v[0] = car_pos->v[0] - old_camera_pos->v[0];
                    tv2.v[1] = car_pos->v[1] - old_camera_pos->v[1];
                    tv2.v[2] = car_pos->v[2] - old_camera_pos->v[2];
                    FindFace(old_camera_pos, &tv2, &b, &ts2, &material);
                    if (ts2 > 1.0) {
                        *cam_pos = *old_camera_pos;
                        return i;
                    }
                }
                tv.v[0] = tv.v[0] * ts;
                tv.v[1] = tv.v[1] * ts;
                tv.v[2] = tv.v[2] * ts;
                tv2.v[0] = a.v[0] * hither;
                tv2.v[1] = a.v[1] * hither;
                tv2.v[2] = a.v[2] * hither;
                tv.v[0] = tv2.v[0] + tv.v[0];
                tv.v[1] = tv2.v[1] + tv.v[1];
                tv.v[2] = tv2.v[2] + tv.v[2];
                dist = sqrt(tv.v[1] * tv.v[1] + tv.v[2] * tv.v[2] + tv.v[0] * tv.v[0]);
                cam_pos->v[0] = car_pos->v[0] + tv.v[0];
                cam_pos->v[1] = car_pos->v[1] + tv.v[1];
                cam_pos->v[2] = car_pos->v[2] + tv.v[2];
                if (HV(gMin_camera_car_distance) > dist && !i && a.v[1] > -0.7) {
                    tv2.v[0] = -a.v[1] * a.v[0];
                    tv2.v[1] = -a.v[1] * a.v[1];
                    tv2.v[2] = -a.v[1] * a.v[2];
                    tv2.v[1] = tv2.v[1] + 1.0;
                    if (HV(gProgram_state).current_car.car_master_actor->t.t.mat.m[1][1] < 0.0) {
                        tv2.v[0] = -tv2.v[0];
                        tv2.v[1] = -tv2.v[1];
                        tv2.v[2] = -tv2.v[2];
                    }
                    d = tv2.v[1] * tv2.v[1] + tv2.v[2] * tv2.v[2] + tv2.v[0] * tv2.v[0];
                    l = tv2.v[1] * tv.v[1] + tv2.v[2] * tv.v[2] + tv2.v[0] * tv.v[0];
                    alpha = tv.v[1] * tv.v[1]
                            + tv.v[2] * tv.v[2]
                            + tv.v[0] * tv.v[0]
                            - HV(gMin_camera_car_distance) * HV(gMin_camera_car_distance);
                    ts2 = l * l - alpha * d * 4.0;
                    if (alpha >= 0 && d != 0.0) {
                        sa = (sqrt(ts2) - l) / (d * 2.0);
                        tv2.v[0] = tv2.v[0] * sa;
                        tv2.v[1] = tv2.v[1] * sa;
                        tv2.v[2] = tv2.v[2] * sa;
                        FindFace(cam_pos, &tv2, &a, &ts, &material);
                        if (ts < 1.0) {
                            tv2.v[0] = tv2.v[0] * ts;
                            tv2.v[1] = tv2.v[1] * ts;
                            tv2.v[2] = tv2.v[2] * ts;
                        }
                        b.v[0] = tv.v[0];
                        b.v[1] = 0.0;
                        b.v[2] = tv.v[2];
                        dist = sqrt(0.0 * 0.0 + tv.v[2] * tv.v[2] + tv.v[0] * tv.v[0]);
                        if (alpha <= 2.3841858e-7) {
                            b.v[0] = 1.0;
                            b.v[1] = 0.0;
                            b.v[2] = 0.0;
                        } else {
                            alpha = 1.0 / dist;
                            b.v[0] = b.v[0] * alpha;
                            b.v[1] = b.v[1] * alpha;
                            b.v[2] = b.v[2] * alpha;
                        }
                        tv.v[0] = tv2.v[0] + tv.v[0];
                        tv.v[1] = tv2.v[1] + tv.v[1];
                        tv.v[2] = tv2.v[2] + tv.v[2];
                        ts2 = tv.v[1] * b.v[1] + tv.v[2] * b.v[2] + b.v[0] * tv.v[0];
                        if (ts2 < 0.029999999 && !HV(gAction_replay_mode)) {
                            dist = sqrt(tv2.v[1] * tv2.v[1] + tv2.v[2] * tv2.v[2] + tv2.v[0] * tv2.v[0]);
                            if (dist <= 2.3841858e-7) {
                                tv2.v[0] = 1.0;
                                tv2.v[1] = 0.0;
                                tv2.v[2] = 0.0;
                            } else {
                                alpha = 1.0 / dist;
                                tv2.v[0] = tv2.v[0] * alpha;
                                tv2.v[1] = tv2.v[1] * alpha;
                                tv2.v[2] = tv2.v[2] * alpha;
                            }
                            if (tv2.v[2] * b.v[2] + tv2.v[0] * b.v[0] + tv2.v[1] * b.v[1] < -0.029999999) {
                                alpha = tv2.v[1] * b.v[1] + tv2.v[2] * b.v[2] + b.v[0] * tv2.v[0];
                                alpha = (0.029999999 - ts2) / alpha;
                                tv2.v[0] = tv2.v[0] * alpha;
                                tv2.v[1] = tv2.v[1] * alpha;
                                tv2.v[2] = tv2.v[2] * alpha;
                                tv.v[0] = tv2.v[0] + tv.v[0];
                                tv.v[1] = tv2.v[1] + tv.v[1];
                                tv.v[2] = tv2.v[2] + tv.v[2];
                            }
                        }
                    }
                    cam_pos->v[0] = car_pos->v[0] + tv.v[0];
                    cam_pos->v[1] = car_pos->v[1] + tv.v[1];
                    cam_pos->v[2] = car_pos->v[2] + tv.v[2];
                }
            }

            bnds.mat = &mat;
            BrMatrix34Identity(&mat);
            tv2.v[0] = hither;
            tv2.v[1] = hither;
            tv2.v[2] = hither;
            bnds.original_bounds.min.v[0] = cam_pos->v[0] - hither;
            bnds.original_bounds.min.v[1] = cam_pos->v[1] - hither;
            bnds.original_bounds.min.v[2] = cam_pos->v[2] - hither;
            bnds.original_bounds.max.v[0] = cam_pos->v[0] + hither;
            bnds.original_bounds.max.v[1] = cam_pos->v[1] + hither;
            bnds.original_bounds.max.v[2] = cam_pos->v[2] + hither;
            k = FindFacesInBox(&bnds, face_list, 3);
            if (k > 0) {
                tv2.v[0] = cam_pos->v[0] - face_list[0].v[0].v[0];
                tv2.v[1] = cam_pos->v[1] - face_list[0].v[0].v[1];
                tv2.v[2] = cam_pos->v[2] - face_list[0].v[0].v[2];
                sa = face_list[0].normal.v[2] * tv2.v[2]
                     + face_list[0].normal.v[1] * tv2.v[1]
                     + face_list[0].normal.v[0] * tv2.v[0];
                // ts2 = sa;
                if (sa < hither && sa >= 0.0) {
                    tv2.v[0] = (hither - sa) * face_list[0].normal.v[0];
                    tv2.v[1] = (hither - sa) * face_list[0].normal.v[1];
                    tv2.v[2] = (hither - sa) * face_list[0].normal.v[2];
                    cam_pos->v[0] = cam_pos->v[0] + tv2.v[0];
                    cam_pos->v[1] = cam_pos->v[1] + tv2.v[1];
                    cam_pos->v[2] = cam_pos->v[2] + tv2.v[2];
                }
                if (k > 1) {
                    sb = face_list[1].normal.v[2] * face_list[0].normal.v[2]
                         + face_list[1].normal.v[1] * face_list[0].normal.v[1]
                         + face_list[1].normal.v[0] * face_list[0].normal.v[0];
                    if (sb > 0.94999999 && k > 2) {
                        face_list[1].normal.v[0] = face_list[2].normal.v[0];
                        face_list[1].normal.v[1] = face_list[2].normal.v[1];
                        face_list[1].normal.v[2] = face_list[2].normal.v[2];
                        face_list[1].v[0].v[0] = face_list[2].v[0].v[0];
                        face_list[1].v[0].v[1] = face_list[2].v[0].v[1];
                        face_list[1].v[0].v[2] = face_list[2].v[0].v[2];
                        sb = face_list[2].normal.v[2] * face_list[0].normal.v[2]
                             + face_list[2].normal.v[1] * face_list[0].normal.v[1]
                             + face_list[2].normal.v[0] * face_list[0].normal.v[0];
                        k = 2;
                    }
                    if (sb <= 0.94999999) {
                        tv2.v[0] = cam_pos->v[0] - face_list[1].v[0].v[0];
                        tv2.v[1] = cam_pos->v[1] - face_list[1].v[0].v[1];
                        tv2.v[2] = cam_pos->v[2] - face_list[1].v[0].v[2];
                        sc = face_list[1].normal.v[2] * tv2.v[2]
                             + face_list[1].normal.v[1] * tv2.v[1]
                             + face_list[1].normal.v[0] * tv2.v[0];
                        if (sc < hither && sc >= 0.0) {
                            sc = face_list[1].normal.v[2] * face_list[0].normal.v[2]
                                 + face_list[1].normal.v[1] * face_list[0].normal.v[1]
                                 + face_list[1].normal.v[0] * face_list[0].normal.v[0];
                            b.v[0] = face_list[0].normal.v[0] * sc;
                            b.v[1] = face_list[0].normal.v[1] * sc;
                            b.v[2] = face_list[0].normal.v[2] * sc;
                            face_list[1].normal.v[0] = face_list[1].normal.v[0] - b.v[0];
                            face_list[1].normal.v[1] = face_list[1].normal.v[1] - b.v[1];
                            face_list[1].normal.v[2] = face_list[1].normal.v[2] - b.v[2];
                            tv2.v[0] = (hither - ts2) * face_list[1].normal.v[0];
                            tv2.v[1] = (hither - ts2) * face_list[1].normal.v[1];
                            tv2.v[2] = (hither - ts2) * face_list[1].normal.v[2];
                            cam_pos->v[0] = cam_pos->v[0] + tv2.v[0];
                            cam_pos->v[1] = cam_pos->v[1] + tv2.v[1];
                            cam_pos->v[2] = cam_pos->v[2] + tv2.v[2];
                        }
                    }
                }
            }
            i += k;
        }
        return i;
    } else {
        return original_CollideCamera2(car_pos, cam_pos, old_camera_pos, manual_move);
    }
}

function_hook_state_t function_hook_state_BoundsTest = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_BoundsTest)
static int(__cdecl*original_BoundsTest)(br_bounds *, br_vector3 *) = (int(__cdecl*)(br_bounds *, br_vector3 *))0x0048ba12;
CARM95_HOOK_FUNCTION(original_BoundsTest, BoundsTest)
int __cdecl BoundsTest(br_bounds *bnds, br_vector3 *p) {
    int j;
    LOG_TRACE("(%p, %p)", bnds, p);

    (void)bnds;
    (void)p;
    (void)j;

    if (function_hook_state_BoundsTest == HOOK_ENABLED) {
        assert(0 && "BoundsTest not implemented.");
        abort();
    } else {
        return original_BoundsTest(bnds, p);
    }
}

function_hook_state_t function_hook_state_CollideCameraWithOtherCars = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_CollideCameraWithOtherCars)
static int(__cdecl*original_CollideCameraWithOtherCars)(br_vector3 *, br_vector3 *) = (int(__cdecl*)(br_vector3 *, br_vector3 *))0x0048b820;
CARM95_HOOK_FUNCTION(original_CollideCameraWithOtherCars, CollideCameraWithOtherCars)
int __cdecl CollideCameraWithOtherCars(br_vector3 *car_pos, br_vector3 *cam_pos) {
    int i;
    int plane;
    br_scalar ts;
    tCar_spec *c;
    br_vector3 tv;
    br_vector3 pos_car_space;
    br_vector3 dir;
    br_vector3 p;
    br_vector3 n;
    br_bounds bnds;
    LOG_TRACE("(%p, %p)", car_pos, cam_pos);

    (void)car_pos;
    (void)cam_pos;
    (void)i;
    (void)plane;
    (void)ts;
    (void)c;
    (void)tv;
    (void)pos_car_space;
    (void)dir;
    (void)p;
    (void)n;
    (void)bnds;

    if (function_hook_state_CollideCameraWithOtherCars == HOOK_ENABLED) {
        assert(0 && "CollideCameraWithOtherCars not implemented.");
        abort();
    } else {
        return original_CollideCameraWithOtherCars(car_pos, cam_pos);
    }
}

function_hook_state_t function_hook_state_InitialiseExternalCamera = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(function_hook_state_InitialiseExternalCamera)
static void(__cdecl*original_InitialiseExternalCamera)() = (void(__cdecl*)())0x0048ba8a;
CARM95_HOOK_FUNCTION(original_InitialiseExternalCamera, InitialiseExternalCamera)
void __cdecl InitialiseExternalCamera() {
    br_scalar ts;
    tCar_spec *c;
    br_vector3 r;
    br_angle yaw;
    br_scalar __block0___scale;
    LOG_TRACE("()");

    (void)ts;
    (void)c;
    (void)r;
    (void)yaw;
    (void)__block0___scale;

    if (function_hook_state_InitialiseExternalCamera == HOOK_ENABLED) {
        c = HV(gCar_to_view);
        if (!HV(gProgram_state).racing) {
            c = &HV(gProgram_state).current_car;
        }
        HV(gCamera_height) = c->pos.v[1];
        BrVector3Set(&HV(gView_direction), c->direction.v[0], 0.0f, c->direction.v[2]);
        BrVector3Normalise(&HV(gView_direction), &HV(gView_direction));
        ts = -BrVector3Dot(&HV(gView_direction), (br_vector3*)c->car_master_actor->t.t.mat.m[2]);
        HV(gCamera_sign) = ts < 0;
        HV(gCamera_mode) = 0;
        if (HV(gCamera_sign)) {
            yaw = -HV(gCamera_yaw);
        } else {
            yaw = HV(gCamera_yaw);
        }
        DrVector3RotateY(&HV(gView_direction), yaw);
        HV(gMin_camera_car_distance) = 0.6f;
        HV(gCamera_frozen) = 0;
        HV(gCamera_mode) = -2;
        if (HV(gCountdown) && (HV(gNet_mode) == eNet_mode_none || HV(gCurrent_net_game)->options.grid_start) && HV(gCountdown) > 4) {
            HV(gCamera_height) = HV(gCamera_height) + 10.0f;
        }
    } else {
        original_InitialiseExternalCamera();
    }
}

function_hook_state_t function_hook_state_FreezeCamera = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(function_hook_state_FreezeCamera)
static void(__cdecl*original_FreezeCamera)() = (void(__cdecl*)())0x0048bc93;
CARM95_HOOK_FUNCTION(original_FreezeCamera, FreezeCamera)
void __cdecl FreezeCamera() {
    LOG_TRACE("()");


    if (function_hook_state_FreezeCamera == HOOK_ENABLED) {
        HV(gCamera_frozen) = 1;
    } else {
        original_FreezeCamera();
    }
}

function_hook_state_t function_hook_state_FlyCar = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(function_hook_state_FlyCar)
static void(__cdecl*original_FlyCar)(tCar_spec *, br_scalar) = (void(__cdecl*)(tCar_spec *, br_scalar))0x0048bca8;
CARM95_HOOK_FUNCTION(original_FlyCar, FlyCar)
void __cdecl FlyCar(tCar_spec *c, br_scalar dt) {
    int accflag;
    int turnflag;
    br_vector3 step;
    br_matrix34 *mat;
    br_angle theta;
    static br_scalar vel = 0.f;
    tFace_ref faces[20];
    tBounds bnds;
    br_vector3 __block0__a;
    br_vector3 __block0__b;
    br_vector3 __block0__norm;
    br_vector3 __block0__norm2;
    br_scalar __block0__dist;
    br_scalar __block0__dist2;
    br_scalar __block0__ts;
    br_angle __block0__phi;
    int __block0__i;
    br_angle __block0__theta;
    LOG_TRACE("(%p, %f)", c, dt);

    (void)c;
    (void)dt;
    (void)accflag;
    (void)turnflag;
    (void)step;
    (void)mat;
    (void)theta;
    (void)vel;
    (void)faces;
    (void)bnds;
    (void)__block0__a;
    (void)__block0__b;
    (void)__block0__norm;
    (void)__block0__norm2;
    (void)__block0__dist;
    (void)__block0__dist2;
    (void)__block0__ts;
    (void)__block0__phi;
    (void)__block0__i;
    (void)__block0__theta;

    if (function_hook_state_FlyCar == HOOK_ENABLED) {
        int i; // Added by DethRace
        br_scalar tmp_scalar1; // Added by DethRace
        br_scalar tmp_scalar2; // Added by DethRace
        br_vector3 tmp1;       // Added by DethRace
        br_vector3 tmp2;       // Added by DethRace
        br_vector3 tmp3;       // Added by DethRace

        accflag = 0;
        turnflag = 0;
        mat = &c->car_master_actor->t.t.mat;
        bnds.mat = mat;
        BrVector3InvScale(&bnds.original_bounds.min, &c->bounds[1].min, WORLD_SCALE);
        BrVector3InvScale(&bnds.original_bounds.max, &c->bounds[1].max, WORLD_SCALE);
        BrVector3InvScale((br_vector3*)bnds.mat->m[3], (br_vector3*)bnds.mat->m[3], WORLD_SCALE);
        FindFacesInBox(&bnds, faces, COUNT_OF(faces));
        BrVector3Scale((br_vector3*)bnds.mat->m[3], (br_vector3*)bnds.mat->m[3], WORLD_SCALE);
        if (c->keys.acc || c->joystick.acc > 0) {
            vel += 10.f * dt;
            accflag = 1;
        }
        if (c->keys.dec || c->joystick.dec > 0) {
            vel -= 10.f * dt;
            accflag = 1;
        }
        if (!accflag) {
            if (vel >= 20.f * dt || vel <= -20.f * dt) {
                vel -= 20.f * vel / fabsf(vel) * dt;
            } else {
                vel = 0.f;
            }
        }
        BrVector3Scale(&step, &c->v, dt);
        BrVector3Accumulate((br_vector3*)mat->m[3], &step);
        BrVector3Scale(&step, (br_vector3*)mat->m[1], dt);
        if (c->keys.left || c->joystick.left > 0) {
            BrVector3Accumulate(&c->omega, &step);
            turnflag = 1;
        }
        if (c->keys.right || c->joystick.right > 0) {
            BrVector3Sub(&c->omega, &c->omega, &step);
            turnflag = 1;
        }
        if (!turnflag) {
            BrVector3SetFloat(&c->omega, 0.f, 0.f, 0.f);
        }
        theta = BrRadianToAngle(c->omega.v[1] * dt);
        DrVector3RotateY(&c->v, theta);
        BrMatrix34PreRotateY(mat, theta);
        if (c->keys.up) {
            BrMatrix34PreRotateX(mat, BrDegreeToAngle(5));
        }
        if (c->keys.down) {
            BrMatrix34PreRotateX(mat, BrDegreeToAngle(360 - 5));
        }
        BrVector3Scale(&c->v, (br_vector3*)mat->m[2], -vel);
        BrVector3Scale(&step, &c->v, dt);
        BrVector3Accumulate((br_vector3*)&mat->m[3], &step);
        if (c->keys.holdw) {
            BrVector3Copy(&step, (br_vector3*)mat->m[3]);
            BrMatrix34RotateY(mat, BrDegreeToAngle(90) - BrRadianToAngle(atan2f(mat->m[2][2], mat->m[2][0])));
            BrVector3Copy((br_vector3*)mat->m[3], &step);
            BrVector3SetFloat(&step, 0.f, -100.f, 0.f);
            BrVector3Copy(&tmp1, (br_vector3*)&mat->m[3]);
            findfloor(&tmp1, &step, &tmp2, &tmp_scalar1);
            tmp1.v[1] += 100.f;
            findfloor(&tmp1, &step, &tmp3, &tmp_scalar2);
            if (tmp_scalar2 <= 1.f) {
                BrVector3SetFloat(&step, 0.f, -5.01f, 0.f);
                tmp1.v[1] -= 20 * 5.f;
                for (i = 0; i < 20; i++) {
                    tmp1.v[1] += 5.f;
                    findfloor(&tmp1, &step, &tmp3, &tmp_scalar2);
                    if (tmp_scalar2 <= 1.f) {
                        break;
                    }
                }
                tmp_scalar2 = -tmp_scalar2 / 20.f + (i + 1) * 0.05f;
            }
            if (tmp_scalar2 < tmp_scalar1) {
                tmp_scalar1 = -tmp_scalar2;
                BrVector3Copy(&tmp2, &tmp3);
            }
            if (tmp_scalar1 <= 1.f) {
                mat->m[3][1] -= tmp_scalar1 * 100.f;
                BrMatrix34PreRotateX(mat, BrRadianToAngle(asinf(BrVector3Dot((br_vector3*)mat->m[2], &tmp2))));
                BrMatrix34PreRotateZ(mat, -BrRadianToAngle(asinf(BrVector3Dot((br_vector3*)mat->m[0], &tmp2))));
            }
        }
        BrVector3Negate((br_vector3*)&c->direction, (br_vector3*)mat->m[2]);
        BrMatrix34Copy(&c->oldmat, mat);
        BrMatrix34ApplyP(&c->pos, &c->cmpos, mat);
        BrVector3InvScale(&c->pos, &c->pos, WORLD_SCALE);
        BrVector3InvScale((br_vector3*)bnds.mat->m[3], (br_vector3*)bnds.mat->m[3], WORLD_SCALE);
        GetNewBoundingBox(&c->bounds_world_space, c->bounds, bnds.mat);
        BrVector3Scale((br_vector3*)bnds.mat->m[3], (br_vector3*)bnds.mat->m[3], WORLD_SCALE);
    } else {
        original_FlyCar(c, dt);
    }
}

function_hook_state_t function_hook_state_DrVector3RotateY = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(function_hook_state_DrVector3RotateY)
static void(__cdecl*original_DrVector3RotateY)(br_vector3 *, br_angle) = (void(__cdecl*)(br_vector3 *, br_angle))0x0048c718;
CARM95_HOOK_FUNCTION(original_DrVector3RotateY, DrVector3RotateY)
void __cdecl DrVector3RotateY(br_vector3 *v, br_angle t) {
    br_scalar c;
    br_scalar s;
    br_scalar ts;
    LOG_TRACE("(%p, %u)", v, t);

    (void)v;
    (void)t;
    (void)c;
    (void)s;
    (void)ts;

    if (function_hook_state_DrVector3RotateY == HOOK_ENABLED) {
        c = cos(BrAngleToRadian(t));
        s = sin(BrAngleToRadian(t));
        ts = v->v[0] * c + v->v[2] * s;
        v->v[2] = v->v[2] * c - v->v[0] * s;
        v->v[0] = ts;
    } else {
        original_DrVector3RotateY(v, t);
    }
}

function_hook_state_t function_hook_state_CrashCarsTogether = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(function_hook_state_CrashCarsTogether)
static void(__cdecl*original_CrashCarsTogether)(br_scalar) = (void(__cdecl*)(br_scalar))0x0048c795;
CARM95_HOOK_FUNCTION(original_CrashCarsTogether, CrashCarsTogether)
void __cdecl CrashCarsTogether(br_scalar dt) {
    int pass;
    int k;
    int i;
    tCollison_data collide_list[32];
    LOG_TRACE("(%f)", dt);

    (void)dt;
    (void)pass;
    (void)k;
    (void)i;
    (void)collide_list;

    if (function_hook_state_CrashCarsTogether == HOOK_ENABLED) {
        for (i = 0; i < HV(gNum_cars_and_non_cars); i++) {
            collide_list[i].car = NULL;
            collide_list[i].ref = HV(gNum_cars_and_non_cars) - 1;
            HV(gActive_car_list)[i]->infinite_mass = 0;
        }
        for (pass = 0; pass < 5; pass++) {
            k = CrashCarsTogetherSinglePass(dt, pass, collide_list);
            if (k <= 0) {
                break;
            }
        }
        if (k > 0) {
            for (i = 0; i < HV(gNum_cars_and_non_cars); i++) {
                BringCarToAGrindingHalt((tCollision_info*)HV(gActive_car_list)[i]);
            }
        }
    } else {
        original_CrashCarsTogether(dt);
    }
}

function_hook_state_t function_hook_state_CrashCarsTogetherSinglePass = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(function_hook_state_CrashCarsTogetherSinglePass)
static int(__cdecl*original_CrashCarsTogetherSinglePass)(br_scalar, int, tCollison_data *) = (int(__cdecl*)(br_scalar, int, tCollison_data *))0x0048c8af;
CARM95_HOOK_FUNCTION(original_CrashCarsTogetherSinglePass, CrashCarsTogetherSinglePass)
int __cdecl CrashCarsTogetherSinglePass(br_scalar dt, int pPass, tCollison_data *collide_list) {
    int i;
    int j;
    int l;
    int m;
    int n;
    int collided;
    int k;
    int ref1;
    int ref2;
    int c1im;
    int c2im;
    tCollision_info *car_1;
    tCollision_info *car_2;
    tCollision_info *car_3;
    tCollision_info *car_in_middle;
    tCollision_info *car_on_wall;
    LOG_TRACE("(%f, %d, %p)", dt, pPass, collide_list);

    (void)dt;
    (void)pPass;
    (void)collide_list;
    (void)i;
    (void)j;
    (void)l;
    (void)m;
    (void)n;
    (void)collided;
    (void)k;
    (void)ref1;
    (void)ref2;
    (void)c1im;
    (void)c2im;
    (void)car_1;
    (void)car_2;
    (void)car_3;
    (void)car_in_middle;
    (void)car_on_wall;

    if (function_hook_state_CrashCarsTogetherSinglePass == HOOK_ENABLED) {
        collided = 0;
        for (i = 0; i < HV(gNum_cars_and_non_cars) - 1; i++) {
            car_1 = (tCollision_info*)HV(gActive_car_list)[i];
            for (j = i + 1; j < HV(gNum_cars_and_non_cars); j++) {
                car_2 = (tCollision_info*)HV(gActive_car_list)[j];
                if (collide_list[i].ref > 0 || collide_list[j].ref > 0) {
                    collide_list[i].ref--;
                    collide_list[j].ref--;
                    if (SimpleCarCarCollisionTest(car_1, car_2)) {
                        if (car_1->infinite_mass == -1 && car_2->infinite_mass > 0) {
                            if (CollideTwoCars(car_1, car_2, -1)) {
                                if (car_2->infinite_mass >= 256 || pPass >= 4) {
                                    BringCarToAGrindingHalt(car_2);
                                } else {
                                    car_2->infinite_mass = 0;
                                    k = CollideTwoCarsWithWalls(car_1, car_2, dt);
                                    car_2->infinite_mass = 256;
                                    if (k < 0) {
                                        BringCarToAGrindingHalt(car_2);
                                    }
                                }
                                collide_list[j].ref = HV(gNum_cars_and_non_cars) - 2;
                                collide_list[j].car = car_1;
                                collided++;
                            }
                        } else if (car_2->infinite_mass == -1 && car_1->infinite_mass > 0) {
                            if (CollideTwoCars(car_1, car_2, -1)) {
                                if (car_1->infinite_mass >= 256 || pPass >= 4) {
                                    BringCarToAGrindingHalt(car_1);
                                } else {
                                    car_1->infinite_mass = 0;
                                    k = CollideTwoCarsWithWalls(car_1, car_2, dt);
                                    car_1->infinite_mass = 256;
                                    if (k < 0) {
                                        BringCarToAGrindingHalt(car_1);
                                    }
                                }
                                collide_list[i].ref = HV(gNum_cars_and_non_cars) - 2;
                                collide_list[i].car = car_2;
                                collided++;
                            }
                        } else if (collide_list[i].car || collide_list[j].car) {
                            if ((collide_list[j].car == NULL) == (collide_list[i].car == NULL)) {
                                if (collide_list[j].car != collide_list[i].car || (car_1->infinite_mass && car_2->infinite_mass)) {
                                    if (collide_list[i].car && collide_list[j].car) {
                                        if (car_1->infinite_mass && car_2->infinite_mass) {
                                            if ((car_1->infinite_mass != -1 || car_2->infinite_mass != -1) && CollideTwoCars(car_1, car_2, -1)) {
                                                collide_list[i].ref = HV(gNum_cars_and_non_cars) - 2;
                                                collide_list[j].ref = HV(gNum_cars_and_non_cars) - 2;
                                                if (car_1->infinite_mass && car_2->infinite_mass) {
                                                    BringCarToAGrindingHalt(car_1);
                                                    BringCarToAGrindingHalt(car_2);
                                                } else {
                                                    k = CollideTwoCarsWithWalls(car_1, car_2, dt);
                                                    if (k >= 0) {
                                                        if (k) {
                                                            if (car_1->infinite_mass >= 0) {
                                                                car_1->infinite_mass++;
                                                            }
                                                            if (car_2->infinite_mass >= 0) {
                                                                car_2->infinite_mass++;
                                                            }
                                                            collided++;
                                                        }
                                                    } else {
                                                        BringCarToAGrindingHalt(car_1);
                                                        BringCarToAGrindingHalt(car_2);
                                                        collided++;
                                                    }
                                                }
                                                collided++;
                                            }
                                        } else {
                                            c1im = car_1->infinite_mass;
                                            c2im = car_2->infinite_mass;
                                            k = CollideTwoCarsWithWalls(car_1, car_2, dt);
                                            if (k > -1) {
                                                if (k) {
                                                    if (!c2im) {
                                                        collide_list[j].ref = HV(gNum_cars_and_non_cars) - 2;
                                                    }
                                                    if (!c1im) {
                                                        collide_list[i].ref = HV(gNum_cars_and_non_cars) - 2;
                                                    }
                                                    collided++;
                                                    if (car_1->infinite_mass >= 0) {
                                                        car_1->infinite_mass++;
                                                    }
                                                    if (car_2->infinite_mass >= 0) {
                                                        car_2->infinite_mass++;
                                                    }
                                                }
                                            } else {
                                                BringCarToAGrindingHalt(car_1);
                                                BringCarToAGrindingHalt(car_2);
                                                if (c1im >= 0) {
                                                    collide_list[i].ref = HV(gNum_cars_and_non_cars) - 2;
                                                }
                                                if (c2im >= 0) {
                                                    collide_list[j].ref = HV(gNum_cars_and_non_cars) - 2;
                                                }
                                                collided++;
                                            }
                                        }
                                    }
                                } else {
                                    k = CollideTwoCarsWithWalls(car_1, car_2, dt);
                                    if (k) {
                                        collide_list[i].ref = HV(gNum_cars_and_non_cars) - 2;
                                        collide_list[j].ref = HV(gNum_cars_and_non_cars) - 2;
                                        if (k == -1) {
                                            BringCarToAGrindingHalt(car_1);
                                            BringCarToAGrindingHalt(car_2);
                                        }
                                        collided++;
                                        if (car_1->infinite_mass >= 0) {
                                            car_1->infinite_mass++;
                                        }
                                        if (car_2->infinite_mass >= 0) {
                                            car_2->infinite_mass++;
                                        }
                                    }
                                }
                            } else {
                                c1im = car_1->infinite_mass;
                                c2im = car_2->infinite_mass;
                                k = CollideTwoCarsWithWalls(car_1, car_2, dt);
                                if (k == -1) {
                                    if (collide_list[i].car) {
                                        car_3 = collide_list[i].car;
                                    } else {
                                        car_3 = collide_list[j].car;
                                    }
                                    if (collide_list[i].car) {
                                        car_in_middle = car_1;
                                    } else {
                                        car_in_middle = car_2;
                                    }
                                    if (car_3->infinite_mass > 1 || car_3->infinite_mass == -1 || (tU8)(car_in_middle->infinite_mass) > 1 || car_in_middle->infinite_mass == -1) {
                                        BringCarToAGrindingHalt(car_1);
                                        BringCarToAGrindingHalt(car_2);
                                        collide_list[i].ref = HV(gNum_cars_and_non_cars) - 2;
                                        collide_list[j].ref = HV(gNum_cars_and_non_cars) - 2;
                                    } else {
                                        if (collide_list[i].car) {
                                            car_on_wall = car_2;
                                        } else {
                                            car_on_wall = car_1;
                                        }
                                        car_in_middle->infinite_mass = 0;
                                        car_3->infinite_mass = 0;
                                        k = CollideTwoCarsWithWalls(car_on_wall, car_in_middle, dt);
                                        car_in_middle->infinite_mass = 2;
                                        car_on_wall->infinite_mass++;
                                        collide_list[i].ref = HV(gNum_cars_and_non_cars) - 2;
                                        collide_list[j].ref = HV(gNum_cars_and_non_cars) - 2;
                                        if (k < 0) {
                                            BringCarToAGrindingHalt(car_1);
                                            BringCarToAGrindingHalt(car_2);
                                        }
                                    }
                                    collide_list[i].car = car_2;
                                    collide_list[j].car = car_1;
                                    collided++;
                                } else if (k) {
                                    collide_list[i].car = car_2;
                                    collide_list[j].car = car_1;
                                    if (!c2im) {
                                        collide_list[j].ref = HV(gNum_cars_and_non_cars) - 2;
                                    }
                                    if (!c1im) {
                                        collide_list[i].ref = HV(gNum_cars_and_non_cars) - 2;
                                    }
                                    collided++;
                                    if (car_1->infinite_mass >= 0) {
                                        car_1->infinite_mass++;
                                    }
                                    if (car_2->infinite_mass >= 0) {
                                        car_2->infinite_mass++;
                                    }
                                }
                            }
                        } else {
                            k = CollideTwoCarsWithWalls(car_1, car_2, dt);
                            if (k) {
                                collide_list[i].car = car_2;
                                collide_list[j].car = car_1;
                                collide_list[i].ref = HV(gNum_cars_and_non_cars) - 2;
                                collide_list[j].ref = HV(gNum_cars_and_non_cars) - 2;
                                if (k == -1) {
                                    BringCarToAGrindingHalt(car_1);
                                    BringCarToAGrindingHalt(car_2);
                                    collide_list[i].ref = HV(gNum_cars_and_non_cars) - 2;
                                    collide_list[j].ref = HV(gNum_cars_and_non_cars) - 2;
                                }
                                collided++;
                            }
                        }
                        CrashEarnings((tCar_spec*)car_1, (tCar_spec*)car_2);
                    }
                }
            }
        }
        return collided;
    } else {
        return original_CrashCarsTogetherSinglePass(dt, pPass, collide_list);
    }
}

function_hook_state_t function_hook_state_BringCarToAGrindingHalt = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(function_hook_state_BringCarToAGrindingHalt)
static void(__cdecl*original_BringCarToAGrindingHalt)(tCollision_info *) = (void(__cdecl*)(tCollision_info *))0x0048d21b;
CARM95_HOOK_FUNCTION(original_BringCarToAGrindingHalt, BringCarToAGrindingHalt)
void __cdecl BringCarToAGrindingHalt(tCollision_info *car) {
    LOG_TRACE("(%p)", car);

    (void)car;

    if (function_hook_state_BringCarToAGrindingHalt == HOOK_ENABLED) {
        BrVector3SetFloat(&car->v, 0.0f, 0.0f, 0.0f);
        BrVector3SetFloat(&car->omega, 0.0f, 0.0f, 0.0f);
        BrVector3SetFloat(&car->oldomega, 0.0f, 0.0f, 0.0f);
        BrMatrix34Copy(&car->car_master_actor->t.t.mat, &car->oldmat);
        car->infinite_mass = -1;
    } else {
        original_BringCarToAGrindingHalt(car);
    }
}

function_hook_state_t function_hook_state_BoundsOverlapTest__car = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(function_hook_state_BoundsOverlapTest__car)
int BoundsOverlapTest__car(br_bounds *b1, br_bounds *b2) {
    LOG_TRACE("(%p, %p)", b1, b2);

    (void)b1;
    (void)b2;

    if (function_hook_state_BoundsOverlapTest__car == HOOK_ENABLED) {
        return b2->max.v[0] >= b1->min.v[0]
               && b1->max.v[0] >= b2->min.v[0]
               && b2->max.v[1] >= b1->min.v[1]
               && b1->max.v[1] >= b2->min.v[1]
               && b2->max.v[2] >= b1->min.v[2]
               && b1->max.v[2] >= b2->min.v[2];
    } else {
        NOT_IMPLEMENTED();
    }
}

function_hook_state_t function_hook_state_SimpleCarCarCollisionTest = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(function_hook_state_SimpleCarCarCollisionTest)
static int(__cdecl*original_SimpleCarCarCollisionTest)(tCollision_info *, tCollision_info *) = (int(__cdecl*)(tCollision_info *, tCollision_info *))0x0048d28f;
CARM95_HOOK_FUNCTION(original_SimpleCarCarCollisionTest, SimpleCarCarCollisionTest)
int __cdecl SimpleCarCarCollisionTest(tCollision_info *car1, tCollision_info *car2) {
    LOG_TRACE("(%p, %p)", car1, car2);

    (void)car1;
    (void)car2;

    if (function_hook_state_SimpleCarCarCollisionTest == HOOK_ENABLED) {
        if (car1->bounds_ws_type == eBounds_ws && car2->bounds_ws_type == eBounds_ws) {
            return BoundsOverlapTest__car(&car1->bounds_world_space, &car2->bounds_world_space);
        } else {
            return 1;
        }
    } else {
        return original_SimpleCarCarCollisionTest(car1, car2);
    }
}

function_hook_state_t function_hook_state_CollideTwoCarsWithWalls = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(function_hook_state_CollideTwoCarsWithWalls)
static int(__cdecl*original_CollideTwoCarsWithWalls)(tCollision_info *, tCollision_info *, br_scalar) = (int(__cdecl*)(tCollision_info *, tCollision_info *, br_scalar))0x0048d38c;
CARM95_HOOK_FUNCTION(original_CollideTwoCarsWithWalls, CollideTwoCarsWithWalls)
int __cdecl CollideTwoCarsWithWalls(tCollision_info *car1, tCollision_info *car2, br_scalar dt) {
    br_vector3 mom1;
    br_vector3 mom2;
    int l;
    int m;
    int n;
    int p;
    int im1;
    int im2;
    LOG_TRACE("(%p, %p, %f)", car1, car2, dt);

    (void)car1;
    (void)car2;
    (void)dt;
    (void)mom1;
    (void)mom2;
    (void)l;
    (void)m;
    (void)n;
    (void)p;
    (void)im1;
    (void)im2;

    if (function_hook_state_CollideTwoCarsWithWalls == HOOK_ENABLED) {
        l = 0;
        m = 0;
        p = 0;
        im1 = car1->infinite_mass;
        im2 = car2->infinite_mass;
        do {
            n = CollideTwoCarsRepeatedly(car1, car2, dt);
            if (n <= 0) {
                if (n == -1) {
                    return -1;
                }
                l = 0;
                m = 0;
            } else {
                ++p;
                if (n >= 5) {
                    if (p >= 10 || car1->infinite_mass || car2->infinite_mass) {
                        return -1;
                    }
                    BrVector3Set(&car1->omega, 0.0f, 0.0f, 0.0f);
                    BrVector3Set(&car2->omega, 0.0f, 0.0f, 0.0f);
                    BrVector3Scale(&mom1, &car1->v, car1->M);
                    BrVector3Scale(&mom2, &car2->v, car2->M);
                    BrVector3Accumulate(&mom1, &mom2);
                    BrVector3InvScale(&car1->v, &mom1, car2->M + car1->M);
                    car2->v = car1->v;
                    RotateCar(car1, dt);
                    TranslateCar(car1, dt);
                    RotateCar(car2, dt);
                    TranslateCar(car2, dt);
                    if (CollideTwoCars(car1, car2, -1)) {
                        return -1;
                    }
                    if (im1 || im2) {
                        return -1;
                    }
                }
                if (!im1) {
                    l = CollideCarWithWall(car1, dt);
                }
                if (!im2) {
                    m = CollideCarWithWall(car2, dt);
                }
                if (p < 3) {
                    car1->infinite_mass = im1;
                    car2->infinite_mass = im2;
                }
                if (p > 5) {
                    if (l) {
                        car1->infinite_mass |= 0x100u;
                    }
                    if (m) {
                        car2->infinite_mass |= 0x100u;
                    }
                }
                if (car1->infinite_mass && car2->infinite_mass) {
                    return -1;
                }
            }
        } while ((l || m) && p < 10);
        if (p < 10) {
            return p;
        } else {
            return -1;
        }
    } else {
        return original_CollideTwoCarsWithWalls(car1, car2, dt);
    }
}

function_hook_state_t function_hook_state_CollideTwoCarsRepeatedly = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(function_hook_state_CollideTwoCarsRepeatedly)
static int(__cdecl*original_CollideTwoCarsRepeatedly)(tCollision_info *, tCollision_info *, br_scalar) = (int(__cdecl*)(tCollision_info *, tCollision_info *, br_scalar))0x0048d719;
CARM95_HOOK_FUNCTION(original_CollideTwoCarsRepeatedly, CollideTwoCarsRepeatedly)
int __cdecl CollideTwoCarsRepeatedly(tCollision_info *car1, tCollision_info *car2, br_scalar dt) {
    int l;
    int collide;
    br_scalar ts;
    LOG_TRACE("(%p, %p, %f)", car1, car2, dt);

    (void)car1;
    (void)car2;
    (void)dt;
    (void)l;
    (void)collide;
    (void)ts;

    if (function_hook_state_CollideTwoCarsRepeatedly == HOOK_ENABLED) {
        l = 0;
        ModifyCarsMass(car1, car2);
        while (1) {
            collide = CollideTwoCars(car1, car2, l);
            if (!collide) {
                break;
            }
            if (collide == -1) {
                ResetCarsMass(car1, car2);
                return -1;
            }
            if (++l >= 5) {
                break;
            }
            RotateCar(car1, dt);
            TranslateCar(car1, dt);
            RotateCar(car2, dt);
            TranslateCar(car2, dt);
        }
        if (l > 0) {
            car1->frame_collision_flag += 256;
            car2->frame_collision_flag += 256;
            if (HV(gNet_mode) == eNet_mode_host) {
                car1->last_car_car_collision = HV(gLast_mechanics_time) + 40;
                car2->last_car_car_collision = HV(gLast_mechanics_time) + 40;
            }
        }
        ResetCarsMass(car1, car2);
        return l;
    } else {
        return original_CollideTwoCarsRepeatedly(car1, car2, dt);
    }
}

function_hook_state_t function_hook_state_CollideTwoCars = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(function_hook_state_CollideTwoCars)
static int(__cdecl*original_CollideTwoCars)(tCollision_info *, tCollision_info *, int) = (int(__cdecl*)(tCollision_info *, tCollision_info *, int))0x0048d84a;
CARM95_HOOK_FUNCTION(original_CollideTwoCars, CollideTwoCars)
int __cdecl CollideTwoCars(tCollision_info *car1, tCollision_info *car2, int pPass) {
    int k;
    int old_k;
    int i;
    int j;
    br_scalar dist;
    br_scalar ts;
    br_bounds new_car1_bnds;
    br_bounds new_car2_bnds;
    br_bounds bnds;
    br_matrix34 *mat1;
    br_matrix34 *mat2;
    br_matrix34 *oldmat1;
    br_matrix34 *oldmat2;
    br_matrix34 inv_mat1;
    br_matrix34 inv_mat2;
    br_matrix34 inv_oldmat1;
    br_matrix34 inv_oldmat2;
    br_matrix34 car2_to_car1;
    br_matrix34 car1_to_car2;
    br_matrix34 old_car2_to_car1;
    br_matrix34 old_car1_to_car2;
    br_matrix34 car1_to_old_car1;
    br_matrix34 car2_to_old_car2;
    br_vector3 r[16];
    br_vector3 n[16];
    br_vector3 sep;
    br_vector3 tv;
    int add_point;
    static br_vector3 oldr1;
    static br_vector3 oldr2;
    static br_vector3 oldn1;
    static br_vector3 oldn2;
    static int is_old_point_available;
    LOG_TRACE("(%p, %p, %d)", car1, car2, pPass);

    (void)car1;
    (void)car2;
    (void)pPass;
    (void)k;
    (void)old_k;
    (void)i;
    (void)j;
    (void)dist;
    (void)ts;
    (void)new_car1_bnds;
    (void)new_car2_bnds;
    (void)bnds;
    (void)mat1;
    (void)mat2;
    (void)oldmat1;
    (void)oldmat2;
    (void)inv_mat1;
    (void)inv_mat2;
    (void)inv_oldmat1;
    (void)inv_oldmat2;
    (void)car2_to_car1;
    (void)car1_to_car2;
    (void)old_car2_to_car1;
    (void)old_car1_to_car2;
    (void)car1_to_old_car1;
    (void)car2_to_old_car2;
    (void)r;
    (void)n;
    (void)sep;
    (void)tv;
    (void)add_point;
    (void)oldr1;
    (void)oldr2;
    (void)oldn1;
    (void)oldn2;
    (void)is_old_point_available;

    if (function_hook_state_CollideTwoCars == HOOK_ENABLED) {
//#ifdef DETHRACE_FIX_BUGS
        // this variable is used uninitialized
    add_point = 0;
//#endif

        if (!HV(gCar_car_collisions)) {
            return 0;
        }
        if (pPass < 0 && !SimpleCarCarCollisionTest(car1, car2)) {
            return 0;
        }

        mat1 = &car1->car_master_actor->t.t.mat;
        mat2 = &car2->car_master_actor->t.t.mat;
        oldmat1 = &car1->oldmat;
        oldmat2 = &car2->oldmat;
        BrMatrix34LPInverse(&inv_oldmat1, &car1->oldmat);
        BrMatrix34LPInverse(&inv_oldmat2, &car2->oldmat);
        BrMatrix34Mul(&car1_to_old_car1, mat1, &inv_oldmat1);
        BrMatrix34Mul(&car2_to_old_car2, mat2, &inv_oldmat2);
        BrMatrix34Mul(&old_car2_to_car1, oldmat2, &inv_oldmat1);
        GetNewBoundingBox(&new_car1_bnds, &car1->bounds[1], &car1_to_old_car1);
        GetNewBoundingBox(&new_car2_bnds, &car2->bounds[1], &car2_to_old_car2);

        for (i = 0; i < 3; ++i) {
            new_car1_bnds.min.v[i] = MIN(car1->bounds[1].min.v[i], new_car1_bnds.min.v[i]);
            new_car1_bnds.max.v[i] = MAX(car1->bounds[1].max.v[i], new_car1_bnds.max.v[i]);

            new_car2_bnds.min.v[i] = MIN(car2->bounds[1].min.v[i], new_car2_bnds.min.v[i]);
            new_car2_bnds.max.v[i] = MAX(car2->bounds[1].max.v[i], new_car2_bnds.max.v[i]);
        }
        GetNewBoundingBox(&bnds, &new_car2_bnds, &old_car2_to_car1);

        if (new_car1_bnds.max.v[0] < bnds.min.v[0]
            || bnds.max.v[0] < new_car1_bnds.min.v[0]
            || new_car1_bnds.max.v[1] < bnds.min.v[1]
            || bnds.max.v[1] < new_car1_bnds.min.v[1]
            || new_car1_bnds.max.v[2] < bnds.min.v[2]
            || bnds.max.v[2] < new_car1_bnds.min.v[2]) {
            return 0;
        }
        BrMatrix34LPInverse(&inv_mat1, mat1);
        BrMatrix34LPInverse(&inv_mat2, mat2);
        BrMatrix34Mul(&car2_to_car1, mat2, &inv_mat1);
        BrMatrix34Mul(&car1_to_car2, mat1, &inv_mat2);
        BrMatrix34Mul(&old_car2_to_car1, oldmat2, &inv_oldmat1);
        BrMatrix34Mul(&old_car1_to_car2, oldmat1, &inv_oldmat2);
        BrMatrix34Mul(&car1_to_old_car1, mat1, &inv_oldmat1);
        BrMatrix34Mul(&car2_to_old_car2, mat2, &inv_oldmat2);
        do {
            k = 0;
            k += FacePointCarCarCollide(car1, car2, &car2_to_car1, &old_car2_to_car1, &car1_to_old_car1, r, n, 8, 0);
            k += FacePointCarCarCollide(car2, car1, &car1_to_car2, &old_car1_to_car2, &car2_to_old_car2, &r[2 * k], &n[2 * k], 8 - k, 1);
            old_k = k;

            if (k < 3 || add_point) {
                k += GetEdgeEdgeCollisions(&car1->bounds[1], &car2->bounds[1], &car2_to_car1, &car1_to_car2, &old_car2_to_car1, &old_car1_to_car2, &car1_to_old_car1, &r[2 * k], &n[2 * k], 8 - k);
            }
            if (k == -1) {
                TestOldMats(car1, car2, 1);
            }
            if (!k) {
                return 0;
            }
            if (k > 4) {
                i = old_k;
                j = old_k;
                while (i < k) {
                    if (BrVector3Dot(&n[2 * i + 1], &r[2 * i + 1]) <= 0.0f || i - j >= k - 4) {
                        if (j != i) {
                            r[2 * j] = r[2 * i];
                        }
                        n[2 * j] = n[2 * i];
                        r[2 * j + 1] = r[2 * i + 1];
                        n[2 * j + 1] = n[2 * i + 1];
                    } else {
                        j--;
                    }
                    i++;
                    j++;
                }
                k = j;
            }
            for (i = 0; i < k; ++i) {
                BrVector3Sub(&r[2 * i], &r[2 * i], &car1->cmpos);
                BrVector3Sub(&r[2 * i + 1], &r[2 * i + 1], &car2->cmpos);
            }
            if (add_point == -1) {
                return k;
            }
            car1->doing_nothing_flag = 0;
            car2->doing_nothing_flag = 0;
            if (k < 3 && add_point) {
                for (i = 0; i < k; i++) {
                    BrVector3Sub(&tv, &r[2 * i], &oldr1);
                    if (BrVector3LengthSquared(&tv) < 0.01f) {
                        add_point = 0;
                    }
                }
                if (add_point) {
                    r[2 * k] = oldr1;
                    r[2 * k + 1] = oldr2;
                    n[2 * k] = oldn1;
                    n[2 * k + 1] = oldn2;
                    k++;
                }
            }
            oldr1 = r[0];
            oldr2 = r[1];
            oldn1 = n[0];
            oldn2 = n[1];
            if (k < 3) {
                if (car1->collision_flag && !car1->infinite_mass) {

                    for (i = 0; i < k; i++) {
                        if (BrVector3Dot(&n[2 * i], &car1->old_norm) < -0.9f) {
                            car1->infinite_mass |= 0x100u;
                        }
                    }
                    if (!car1->infinite_mass) {
                        r[2 * k] = car1->old_point;
                        n[2 * k] = car1->old_norm;
                        BrVector3SetFloat(&n[2 * k + 1], 0.0f, 0.0f, 0.0f);
                        BrVector3SetFloat(&r[2 * k + 1], 0.0f, 0.0f, 0.0f);
                        k++;
                    }
                }
                if (car2->collision_flag && !car2->infinite_mass) {
                    for (i = 0; i < k; i++) {
                        if (BrVector3Dot(&n[2 * i + 1], &car2->old_norm) < -0.9f) {
                            car2->infinite_mass |= 0x100u;
                        }
                    }
                    if (!car2->infinite_mass) {
                        r[2 * k + 1] = car2->old_point;
                        n[2 * k + 1] = car2->old_norm;
                        BrVector3SetFloat(&n[2 * k], 0.0f, 0.0f, 0.0f);
                        BrVector3SetFloat(&r[2 * k], 0.0f, 0.0f, 0.0f);
                        k++;
                    }
                }
            }
            if (car1->infinite_mass && car2->infinite_mass) {
                return -1;
            }
        } while (DoCollide(car1, car2, r, n, k, pPass, &car1_to_car2));
        return k;
    } else {
        return original_CollideTwoCars(car1, car2, pPass);
    }
}

function_hook_state_t function_hook_state_GetEdgeEdgeCollisions = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(function_hook_state_GetEdgeEdgeCollisions)
static int(__cdecl*original_GetEdgeEdgeCollisions)(br_bounds *, br_bounds *, br_matrix34 *, br_matrix34 *, br_matrix34 *, br_matrix34 *, br_matrix34 *, br_vector3 *, br_vector3 *, int) = (int(__cdecl*)(br_bounds *, br_bounds *, br_matrix34 *, br_matrix34 *, br_matrix34 *, br_matrix34 *, br_matrix34 *, br_vector3 *, br_vector3 *, int))0x0048e82a;
CARM95_HOOK_FUNCTION(original_GetEdgeEdgeCollisions, GetEdgeEdgeCollisions)
int __cdecl GetEdgeEdgeCollisions(br_bounds *pB1, br_bounds *pB2, br_matrix34 *pM21, br_matrix34 *pM12, br_matrix34 *pMo21, br_matrix34 *pMo12, br_matrix34 *pM1o1, br_vector3 *pPoint_list, br_vector3 *pNorm_list, int pMax) {
    br_vector3 p1;
    br_vector3 p2;
    br_vector3 tp1;
    br_vector3 tp2;
    br_vector3 tp3;
    br_vector3 hp1;
    br_vector3 hp2;
    br_vector3 hp3;
    br_vector3 shp1;
    br_vector3 shp2;
    br_vector3 edge;
    int plane1;
    int plane2;
    int plane3;
    br_scalar ts;
    int i;
    int j;
    int n;
    br_scalar __block0___scale;
    br_scalar __block1___scale;
    LOG_TRACE("(%p, %p, %p, %p, %p, %p, %p, %p, %p, %d)", pB1, pB2, pM21, pM12, pMo21, pMo12, pM1o1, pPoint_list, pNorm_list, pMax);

    (void)pB1;
    (void)pB2;
    (void)pM21;
    (void)pM12;
    (void)pMo21;
    (void)pMo12;
    (void)pM1o1;
    (void)pPoint_list;
    (void)pNorm_list;
    (void)pMax;
    (void)p1;
    (void)p2;
    (void)tp1;
    (void)tp2;
    (void)tp3;
    (void)hp1;
    (void)hp2;
    (void)hp3;
    (void)shp1;
    (void)shp2;
    (void)edge;
    (void)plane1;
    (void)plane2;
    (void)plane3;
    (void)ts;
    (void)i;
    (void)j;
    (void)n;
    (void)__block0___scale;
    (void)__block1___scale;

    if (function_hook_state_GetEdgeEdgeCollisions == HOOK_ENABLED) {
        // EdgeEdge final version
        n = 0;
        if (pMax < 1) {
            return 0;
        }
        for (i = 0; i < 4; i++) {
            if (i == 3) {
                tp1 = pB2->min;
            } else {
                tp1 = pB2->max;
                tp1.v[i] = pB2->min.v[i];
            }
            for (j = 0; j < 3; j++) {
                tp2 = tp1;
                if (pB2->max.v[j] == tp2.v[j]) {
                    tp2.v[j] = pB2->min.v[j];
                } else {
                    tp2.v[j] = pB2->max.v[j];
                }

                BrMatrix34ApplyP(&p1, &tp1, pM21);
                BrMatrix34ApplyP(&p2, &tp2, pM21);
                plane1 = LineBoxColl(&p1, &p2, pB1, &hp1);
                if (plane1 == 0) {
                    continue;
                }
                plane2 = LineBoxColl(&p2, &p1, pB1, &hp2);
                if (plane1 == 8 || plane2 == 8 || plane2 == 0) {
                    continue;
                }
                BrVector3Add(&p1, &hp1, &hp2);
                BrVector3Scale(&p1, &p1, 0.5f);
                BrMatrix34ApplyP(&tp3, &p1, pM12);
                BrMatrix34ApplyP(&p2, &tp3, pMo21);
                plane3 = LineBoxColl(&p2, &p1, pB1, &hp3);
                // if (plane3 != 8 && plane3 != 0) {
                //     goto LABEL_25;
                // }
                if (plane3 == 8 || plane3 == 0) {
                    BrVector3Sub(&tp3, &p2, &p1);
                    ts = BrVector3Length(&tp3);
                    ts = ts / 0.01f;
                    if (ts == 0.0f) {
                        continue;
                    }
                    BrVector3InvScale(&tp3, &tp3, ts);
                    BrVector3Accumulate(&p2, &tp3);
                    plane3 = LineBoxColl(&p2, &p1, pB1, &hp3);
                    if (plane3 == 8) {
                        continue;
                    }
                }
                if (plane3 == 0) {
                    continue;
                }

                BrMatrix34ApplyP(&shp1, &hp1, pM12);
                BrMatrix34ApplyP(&shp2, &hp2, pM12);
                if ((plane1 ^ plane2) != 4 && (plane3 == plane1 || plane3 == plane2)) {
                    if (n >= pMax) {
                        return n;
                    }
                    GetBoundsEdge(&pPoint_list[2 * n], &edge, pB1, plane1, plane2, &p2, &hp1, &hp2, 0);
                    BrVector3Accumulate(&shp1, &shp2);
                    BrVector3Scale(&pPoint_list[2 * n + 1], &shp1, 0.5f);
                    BrVector3Sub(&p1, &hp1, &hp2);
                    BrVector3Cross(&p2, &edge, &p1);
                    BrVector3Normalise(&p2, &p2);
                    BrVector3Add(&p1, &pB1->max, &pB1->min);
                    BrVector3Scale(&p1, &p1, 0.5f);
                    BrVector3Sub(&p1, &pPoint_list[2 * n], &p1);
                    if (BrVector3Dot(&p1, &p2) > 0.0) {
                        BrVector3Negate(&p2, &p2);
                    }
                    BrMatrix34ApplyV(&p1, &p2, pM12);
                    BrMatrix34TApplyV(&pNorm_list[2 * n], &p1, pMo12);
                    BrMatrix34TApplyV(&pNorm_list[2 * n + 1], &p2, pMo21);
                    BrVector3Negate(&pNorm_list[2 * n + 1], &pNorm_list[2 * n + 1]);
                    n++;
                } else if ((plane1 ^ plane2) == 4) {
                    if (pMax - 1 <= n) {
                        return n;
                    }
                    GetBoundsEdge(&pPoint_list[2 * n], &edge, pB1, plane1, plane3, &p2, &hp1, &hp2, 0);
                    GetBoundsEdge(&pPoint_list[2 * n + 2], &edge, pB1, plane2, plane3, &p2, &hp1, &hp2, 0);
                    pPoint_list[2 * n + 1] = shp1;
                    pPoint_list[2 * n + 3] = shp2;
                    BrVector3Sub(&p1, &hp1, &hp2);
                    BrMatrix34ApplyV(&p2, &p1, pM12);
                    BrMatrix34ApplyV(&p1, &p2, pMo21);
                    BrVector3Cross(&p2, &edge, &p1);
                    BrVector3Normalise(&pNorm_list[2 * n], &p2);
                    GetPlaneNormal(&edge, plane3);
                    if (BrVector3Dot(&pNorm_list[2 * n], &edge) < 0.0f) {
                        BrVector3Negate(&pNorm_list[2 * n], &pNorm_list[2 * n]);
                    }
                    BrMatrix34ApplyV(&pNorm_list[2 * n + 1], &pNorm_list[2 * n], pMo12);
                    BrVector3Negate(&pNorm_list[2 * n + 1], &pNorm_list[2 * n + 1]);
                    BrMatrix34ApplyV(&tp3, &pNorm_list[2 * n], pM12);
                    BrMatrix34ApplyV(&pNorm_list[2 * n], &tp3, pMo21);
                    pNorm_list[2 * n + 2] = pNorm_list[2 * n];
                    pNorm_list[2 * n + 3] = pNorm_list[2 * n + 1];
                    n += 2;
                } else {
                    if (pMax - 1 <= n) {
                        return n;
                    }
                    GetBoundsEdge(&pPoint_list[2 * n], &edge, pB1, plane1, plane3, &p2, &hp1, &hp2, 0);
                    GetBoundsEdge(&pPoint_list[2 * n + 2], &edge, pB1, plane2, plane3, &p2, &hp1, &hp2, 0);
                    BrMatrix34ApplyP(&pPoint_list[2 * n + 1], &hp1, pM12);
                    BrMatrix34ApplyP(&pPoint_list[2 * n + 3], &hp2, pM12);
                    GetPlaneNormal(&pNorm_list[2 * n], plane3);
                    BrMatrix34ApplyV(&pNorm_list[2 * n + 2], &pNorm_list[2 * n], pM1o1);
                    BrMatrix34ApplyV(&pNorm_list[2 * n + 1], &pNorm_list[2 * n + 2], pMo12);
                    pNorm_list[2 * n] = pNorm_list[2 * n + 2];
                    BrVector3Negate(&pNorm_list[2 * n + 1], &pNorm_list[2 * n + 1]);
                    pNorm_list[2 * n + 3] = pNorm_list[2 * n + 1];
                    n += 2;
                }
            }
        }
        return n;
    } else {
        return original_GetEdgeEdgeCollisions(pB1, pB2, pM21, pM12, pMo21, pMo12, pM1o1, pPoint_list, pNorm_list, pMax);
    }
}

function_hook_state_t function_hook_state_FacePointCarCarCollide = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(function_hook_state_FacePointCarCarCollide)
static int(__cdecl*original_FacePointCarCarCollide)(tCollision_info *, tCollision_info *, br_matrix34 *, br_matrix34 *, br_matrix34 *, br_vector3 *, br_vector3 *, int, int) = (int(__cdecl*)(tCollision_info *, tCollision_info *, br_matrix34 *, br_matrix34 *, br_matrix34 *, br_vector3 *, br_vector3 *, int, int))0x0048f686;
CARM95_HOOK_FUNCTION(original_FacePointCarCarCollide, FacePointCarCarCollide)
int __cdecl FacePointCarCarCollide(tCollision_info *car1, tCollision_info *car2, br_matrix34 *pMms, br_matrix34 *pMoms, br_matrix34 *pMsos, br_vector3 *pPoint_list, br_vector3 *pNorm_list, int pMax, int order) {
    int k;
    int i;
    int j;
    int l;
    int plane;
    br_vector3 a;
    br_vector3 a1;
    br_vector3 aa;
    br_vector3 bb;
    br_vector3 norm;
    br_vector3 hp;
    br_vector3 centre;
    br_scalar dist;
    br_bounds *pStat_box;
    br_bounds *pMove_box;
    LOG_TRACE("(%p, %p, %p, %p, %p, %p, %p, %d, %d)", car1, car2, pMms, pMoms, pMsos, pPoint_list, pNorm_list, pMax, order);

    (void)car1;
    (void)car2;
    (void)pMms;
    (void)pMoms;
    (void)pMsos;
    (void)pPoint_list;
    (void)pNorm_list;
    (void)pMax;
    (void)order;
    (void)k;
    (void)i;
    (void)j;
    (void)l;
    (void)plane;
    (void)a;
    (void)a1;
    (void)aa;
    (void)bb;
    (void)norm;
    (void)hp;
    (void)centre;
    (void)dist;
    (void)pStat_box;
    (void)pMove_box;

    if (function_hook_state_FacePointCarCarCollide == HOOK_ENABLED) {
        k = 0;
        pStat_box = &car2->bounds[1];
        BrVector3Add(&centre, &car2->bounds[1].max, &car2->bounds[1].min);
        BrVector3InvScale(&centre, &centre, 2.0f);
        for (i = 0; i < car2->extra_point_num + 8; i++) {
            if (i >= 8) {
                a = car2->extra_points[i - 8];
            } else {
                a.v[0] = ((i & 2) == 0) * pStat_box->min.v[0] + ((i & 2) >> 1) * pStat_box->max.v[0];
                a.v[1] = ((i & 1) == 0) * pStat_box->min.v[1] + (i & 1) * pStat_box->max.v[1];
                a.v[2] = ((i & 4) == 0) * pStat_box->max.v[2] + ((i & 4) >> 2) * pStat_box->min.v[2];
            }
            BrMatrix34ApplyP(&aa, &a, pMms);
            BrMatrix34ApplyP(&bb, &a, pMoms);
            BrVector3Sub(&aa, &aa, &bb);
            dist = BrVector3Length(&aa);
            if (dist >= 0.00001f) {
                BrVector3Scale(&a1, &aa, (0.05f / WORLD_SCALE) / dist); // 0.0072463769 * 6.9 = 0.05
                BrVector3Accumulate(&aa, &a1);
                BrVector3Accumulate(&aa, &bb);
                plane = LineBoxCollWithSphere(&bb, &aa, &car1->bounds[1], &hp);
                if ((plane & 7) != 0) {
                    GetPlaneNormal(&norm, plane);

                    j = 2 * k + order;
                    l = 2 * k + (order == 0);
                    BrMatrix34ApplyV(&pNorm_list[j], &norm, pMsos);
                    BrMatrix34TApplyV(&pNorm_list[l], &pNorm_list[j], pMoms);
                    BrVector3Negate(&pNorm_list[l], &pNorm_list[l]);
                    if ((pNorm_list[l].v[0] >= 0.0f) != (centre.v[0] <= a.v[0]) || (pNorm_list[l].v[1] >= 0.0f) != (centre.v[1] <= a.v[1]) || (pNorm_list[l].v[2] >= 0.0f) != (a.v[2] >= centre.v[2])
                        || !TestOldMats(car1, car2, 0)) {
                        pPoint_list[l] = a;
                        pPoint_list[j] = hp;
                        k++;
                        if (pMax == k) {
                            return k;
                        }
                    }
                }
            }
        }
        return k;
    } else {
        return original_FacePointCarCarCollide(car1, car2, pMms, pMoms, pMsos, pPoint_list, pNorm_list, pMax, order);
    }
}

function_hook_state_t function_hook_state_MungeCarsMass = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(function_hook_state_MungeCarsMass)
static void(__cdecl*original_MungeCarsMass)(tCollision_info *, br_scalar) = (void(__cdecl*)(tCollision_info *, br_scalar))0x0048fc1c;
CARM95_HOOK_FUNCTION(original_MungeCarsMass, MungeCarsMass)
void __cdecl MungeCarsMass(tCollision_info *pCar, br_scalar pFactor) {
    LOG_TRACE("(%p, %f)", pCar, pFactor);

    (void)pCar;
    (void)pFactor;

    if (function_hook_state_MungeCarsMass == HOOK_ENABLED) {
        pCar->M = pCar->M * pFactor;
        BrVector3Scale(&pCar->I, &pCar->I, pFactor);
    } else {
        original_MungeCarsMass(pCar, pFactor);
    }
}

function_hook_state_t function_hook_state_ModifyCarsMass = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(function_hook_state_ModifyCarsMass)
static void(__cdecl*original_ModifyCarsMass)(tCollision_info *, tCollision_info *) = (void(__cdecl*)(tCollision_info *, tCollision_info *))0x0048fb97;
CARM95_HOOK_FUNCTION(original_ModifyCarsMass, ModifyCarsMass)
void __cdecl ModifyCarsMass(tCollision_info *pCar_1, tCollision_info *pCar_2) {
    LOG_TRACE("(%p, %p)", pCar_1, pCar_2);

    (void)pCar_1;
    (void)pCar_2;

    if (function_hook_state_ModifyCarsMass == HOOK_ENABLED) {
        if (pCar_1->driver > eDriver_non_car && ((tCar_spec*)pCar_1)->collision_mass_multiplier != 1.0f) {
            MungeCarsMass(pCar_1, ((tCar_spec*)pCar_1)->collision_mass_multiplier);
        }
        if (pCar_2->driver > eDriver_non_car && ((tCar_spec*)pCar_2)->collision_mass_multiplier != 1.0f) {
            MungeCarsMass(pCar_2, ((tCar_spec*)pCar_2)->collision_mass_multiplier);
        }
    } else {
        original_ModifyCarsMass(pCar_1, pCar_2);
    }
}

function_hook_state_t function_hook_state_ResetCarsMass = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(function_hook_state_ResetCarsMass)
static void(__cdecl*original_ResetCarsMass)(tCollision_info *, tCollision_info *) = (void(__cdecl*)(tCollision_info *, tCollision_info *))0x0048fc7b;
CARM95_HOOK_FUNCTION(original_ResetCarsMass, ResetCarsMass)
void __cdecl ResetCarsMass(tCollision_info *pCar_1, tCollision_info *pCar_2) {
    LOG_TRACE("(%p, %p)", pCar_1, pCar_2);

    (void)pCar_1;
    (void)pCar_2;

    if (function_hook_state_ResetCarsMass == HOOK_ENABLED) {
        if (pCar_1->driver > eDriver_non_car && ((tCar_spec*)pCar_1)->collision_mass_multiplier != 1.0f) {
            MungeCarsMass(pCar_1, 1.0f / ((tCar_spec*)pCar_1)->collision_mass_multiplier);
        }
        if (pCar_2->driver > eDriver_non_car && ((tCar_spec*)pCar_2)->collision_mass_multiplier != 1.0f) {
            MungeCarsMass(pCar_2, 1.0f / ((tCar_spec*)pCar_2)->collision_mass_multiplier);
        }
    } else {
        original_ResetCarsMass(pCar_1, pCar_2);
    }
}

function_hook_state_t function_hook_state_DoCollide = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(function_hook_state_DoCollide)
static int(__cdecl*original_DoCollide)(tCollision_info *, tCollision_info *, br_vector3 *, br_vector3 *, int, int, br_matrix34 *) = (int(__cdecl*)(tCollision_info *, tCollision_info *, br_vector3 *, br_vector3 *, int, int, br_matrix34 *))0x0048fd16;
CARM95_HOOK_FUNCTION(original_DoCollide, DoCollide)
int __cdecl DoCollide(tCollision_info *car1, tCollision_info *car2, br_vector3 *r, br_vector3 *n, int k, int pPass, br_matrix34 *mat1_to_mat2) {
    br_matrix34 *mat1;
    br_matrix34 *mat2;
    br_matrix34 *oldmat1;
    br_matrix34 *oldmat2;
    br_matrix4 M;
    br_vector3 tau1[8];
    br_vector3 a;
    br_vector3 norm;
    br_vector3 f1;
    br_vector3 f2;
    br_vector3 pos1;
    br_vector3 pos2;
    br_vector3 max_friction;
    br_vector3 tv;
    br_vector3 tv2;
    br_vector3 *tau2;
    br_vector3 torque1;
    br_vector3 torque2;
    br_scalar f[4];
    br_scalar d[4];
    br_scalar ts;
    br_scalar tforce;
    int i;
    int j;
    int car1_point;
    int car2_point;
    int plane;
    int move_car1;
    int move_car2;
    br_vector3 a2;
    br_vector3 f12;
    br_vector3 f22;
    br_vector3 point_vel1;
    br_vector3 point_vel2;
    br_scalar fudge_multiplier;
    br_scalar factor;
    int need_to_fudge;
    LOG_TRACE("(%p, %p, %p, %p, %d, %d, %p)", car1, car2, r, n, k, pPass, mat1_to_mat2);

    (void)car1;
    (void)car2;
    (void)r;
    (void)n;
    (void)k;
    (void)pPass;
    (void)mat1_to_mat2;
    (void)mat1;
    (void)mat2;
    (void)oldmat1;
    (void)oldmat2;
    (void)M;
    (void)tau1;
    (void)a;
    (void)norm;
    (void)f1;
    (void)f2;
    (void)pos1;
    (void)pos2;
    (void)max_friction;
    (void)tv;
    (void)tv2;
    (void)tau2;
    (void)torque1;
    (void)torque2;
    (void)f;
    (void)d;
    (void)ts;
    (void)tforce;
    (void)i;
    (void)j;
    (void)car1_point;
    (void)car2_point;
    (void)plane;
    (void)move_car1;
    (void)move_car2;
    (void)a2;
    (void)f12;
    (void)f22;
    (void)point_vel1;
    (void)point_vel2;
    (void)fudge_multiplier;
    (void)factor;
    (void)need_to_fudge;

    if (function_hook_state_DoCollide == HOOK_ENABLED) {
        mat1 = &car1->car_master_actor->t.t.mat;
        mat2 = &car2->car_master_actor->t.t.mat;
        oldmat1 = &car1->oldmat;
        oldmat2 = &car2->oldmat;
        tau2 = &tau1[4];
        move_car1 = !car1->infinite_mass && car1->min_torque_squared == 0.0f;
        move_car2 = !car2->infinite_mass && car2->min_torque_squared == 0.0f;
        if (k > 4) {
            k = 4;
        }
        BrMatrix34Copy(mat1, oldmat1);
        BrMatrix34Copy(mat2, oldmat2);
        car1->omega = car1->oldomega;
        car2->omega = car2->oldomega;
        BrMatrix34TApplyV(&car1->velocity_car_space, &car1->v, mat1);
        BrMatrix34TApplyV(&car2->velocity_car_space, &car2->v, mat2);
        need_to_fudge = 1;
        for (i = 0; i < k; ++i) {
            BrVector3Cross(&tau1[i], &r[2 * i], &n[2 * i]);
            BrVector3Cross(&tau2[i], &r[2 * i + 1], &n[2 * i + 1]);
            Vector3Div(&tau1[i], &tau1[i], &car1->I);
            Vector3Div(&tau2[i], &tau2[i], &car2->I);
            BrVector3Cross(&tv, &car1->omega, &r[2 * i]);
            BrVector3Accumulate(&tv, &car1->velocity_car_space);
            d[i] = -BrVector3Dot(&n[2 * i], &tv);
            BrVector3Cross(&tv, &car2->omega, &r[2 * i + 1]);
            BrVector3Accumulate(&tv, &car2->velocity_car_space);
            d[i] -= BrVector3Dot(&n[2 * i + 1], &tv);
            if (d[i] > 0.0f) {
                need_to_fudge = 0;
            }
        }
        if (need_to_fudge) {
            d[0] = 0.5f;
        }
        factor = 0.0f;
        if (move_car1) {
            factor = car1->M + factor;
        }
        if (move_car2) {
            factor = car2->M + factor;
        }
        for (i = 0; i < k; i++) {
            for (j = 0; j < k; j++) {
                if (move_car1) {
                    BrVector3Cross(&tv, &tau1[j], &r[2 * i]);
                    BrVector3InvScale(&norm, &n[2 * j], car1->M);
                    BrVector3Accumulate(&tv, &norm);
                    M.m[i][j] = BrVector3Dot(&n[2 * i], &tv);
                } else {
                    M.m[i][j] = 0.0f;
                }
                if (move_car2) {
                    BrVector3Cross(&tv, &tau2[j], &r[2 * i + 1]);
                    BrVector3InvScale(&norm, &n[2 * j + 1], car2->M);
                    BrVector3Accumulate(&tv, &norm);
                    M.m[i][j] += BrVector3Dot(&n[2 * i + 1], &tv);
                }
                M.m[i][j] *= factor;
            }
        }
        switch (k) {
            case 1:
                ts = SinglePointColl(f, &M, d);
                break;
            case 2:
                ts = TwoPointCollB(f, &M, d, tau1, n);
                break;
            case 3:
                d[3] = 0.0;
                ts = ThreePointCollRecB(f, &M, d, tau1, n);
                break;
            case 4:
                ts = FourPointCollB(f, &M, d, tau1, n);
                break;
            default:
                ts = 0;
                break;
        }
        if (k > 3) {
            k = 3;
        }
        if (fabs(ts) <= 0.000001f) {
            return 0;
        }
        BrVector3SetFloat(&f1, 0.0f, 0.0f, 0.0f);
        BrVector3SetFloat(&f2, 0.0f, 0.0f, 0.0f);
        BrVector3SetFloat(&pos1, 0.0f, 0.0f, 0.0f);
        BrVector3SetFloat(&pos2, 0.0f, 0.0f, 0.0f);
        BrVector3SetFloat(&torque1, 0.0f, 0.0f, 0.0f);
        BrVector3SetFloat(&torque2, 0.0f, 0.0f, 0.0f);
        tforce = 0.0f;
        car1_point = -1;
        car2_point = -1;
        for (i = 0; i < k; i++) {
            f[i] = f[i] * factor;
            if (f[i] == 0.0f && k != 0) {
                break;
            }
            if (f[i] < 0.001f) {
                f[i] = 0.001f;
            }
            if (f[i] > 10.0f) {
                ts = 0.0f;
            }
            f[i] = f[i] + 0.1f;
            BrVector3Scale(&tau1[i], &tau1[i], f[i]);
            BrVector3Scale(&tau2[i], &tau2[i], f[i]);
            BrVector3Accumulate(&torque1, &tau1[i]);
            BrVector3Accumulate(&torque2, &tau2[i]);
            if (!pPass && n[2 * i].v[0] == 0.0f && n[2 * i].v[1] == 0.0f && n[2 * i].v[2] == 0.0f) {
                car2_point = i;
            } else if (!pPass && n[2 * i + 1].v[0] == 0.0f && n[2 * i + 1].v[1] == 0.0f && n[2 * i + 1].v[2] == 0.0f) {
                car1_point = i;
            } else {
                ts = f[i] / car1->M;
                BrVector3Scale(&tv2, &n[2 * i], ts);
                BrVector3Accumulate(&f1, &tv2);
                ts = f[i] / car2->M;
                BrVector3Scale(&tv2, &n[2 * i + 1], ts);
                BrVector3Accumulate(&f2, &tv2);
                BrVector3Scale(&tv2, &r[2 * i], f[i]);
                BrVector3Accumulate(&pos1, &tv2);
                BrVector3Scale(&tv2, &r[2 * i + 1], f[i]);
                BrVector3Accumulate(&pos2, &tv2);
                tforce = f[i] + tforce;
            }
        }
        if (car1->min_torque_squared != 0.0f && !car1->infinite_mass && BrVector3LengthSquared(&torque1) > car1->min_torque_squared) {
            BrVector3Scale(&car1->omega, &car1->omega, HV(gDt));
            car1->omega.v[0] += torque1.v[0] * 0.04f;
            car1->omega.v[2] += torque1.v[2] * 0.04f;
            if (BrVector3LengthSquared(&car1->omega) > car1->break_off_radians_squared) {
                car1->min_torque_squared = 0.0f;
                return 1;
            }
            BrVector3InvScale(&car1->omega, &car1->omega, HV(gDt));
        }
        if (car2->min_torque_squared != 0.0f && !car2->infinite_mass && BrVector3LengthSquared(&torque2) > car2->min_torque_squared) {
            BrVector3Scale(&car2->omega, &car2->omega, HV(gDt));
            car2->omega.v[0] += torque2.v[0] * 0.04f;
            car2->omega.v[2] += torque2.v[2] * 0.04f;
            if (BrVector3LengthSquared(&car2->omega) > car2->break_off_radians_squared) {
                car2->min_torque_squared = 0.0f;
                return 1;
            }
            BrVector3InvScale(&car2->omega, &car2->omega, HV(gDt));
        }
        if (move_car1) {
            BrVector3Accumulate(&car1->omega, &torque1);
        }
        if (move_car2) {
            BrVector3Accumulate(&car2->omega, &torque2);
        }
        BrVector3InvScale(&pos1, &pos1, tforce);
        BrVector3InvScale(&pos2, &pos2, tforce);
        if (pPass == 0) {
            if (car1_point > -1 && move_car1) {
                f[car1_point] = f[car1_point] / car1->M;
                BrVector3Scale(&n[2 * car1_point], &n[2 * car1_point], f[car1_point]);
                BrVector3Cross(&tv2, &car1->oldomega, &r[2 * car1_point]);
                BrVector3Accumulate(&tv2, &car1->velocity_car_space);
                ts = BrVector3Length(&tv2);
                if (ts > 0.0001f && (car1->driver <= eDriver_non_car || !CAR(car1)->wall_climber_mode)) {
                    AddFriction(car1, &tv2, &n[2 * car1_point], &r[2 * car1_point], f[car1_point], &max_friction);
                    BrVector3Accumulate(&n[2 * car1_point], &max_friction);
                }
                BrMatrix34ApplyV(&tv, &n[2 * car1_point], mat1);
                BrVector3Accumulate(&car1->v, &tv);
            }
            if (car2_point > -1 && move_car2) {
                f[car2_point] = f[car2_point] / car2->M;
                BrVector3Scale(&n[2 * car2_point + 1], &n[2 * car2_point + 1], f[car2_point]);
                BrVector3Cross(&tv2, &car2->oldomega, &r[2 * car2_point + 1]);
                BrVector3Accumulate(&tv2, &car2->velocity_car_space);
                ts = BrVector3Length(&tv2);

                if (ts > 0.0001f && (car1->driver <= eDriver_non_car || !(CAR(car1)->wall_climber_mode))) {
                    AddFriction(car2, &tv2, &n[2 * car2_point + 1], &r[2 * car2_point + 1], f[car2_point], &max_friction);
                    BrVector3Accumulate(&n[2 * car2_point + 1], &max_friction);
                }
                BrMatrix34ApplyV(&tv, &n[2 * car2_point + 1], mat2);
                BrVector3Accumulate(&car2->v, &tv);
            }
            if (tforce != 0.0f) {
                BrVector3Cross(&point_vel1, &car1->oldomega, &pos1);
                BrVector3Sub(&a, &car1->v, &car2->v);
                BrMatrix34TApplyV(&tv2, &a, mat1);
                BrVector3Accumulate(&point_vel1, &tv2);
                BrVector3Cross(&point_vel2, &car2->oldomega, &pos2);
                AddFrictionCarToCar(car1, car2, &point_vel1, &point_vel2, &f1, &pos1, &pos2, tforce, &max_friction);
                if (TestForNan(max_friction.v) || TestForNan(&max_friction.v[1]) || TestForNan(&max_friction.v[2])) {
                    BrVector3SetFloat(&max_friction, 0.0f, 0.0f, 0.0f);
                }
                BrVector3InvScale(&tv2, &max_friction, car1->M);
                BrVector3Accumulate(&f1, &tv2);
                BrMatrix34ApplyV(&tv2, &max_friction, mat1);
                BrMatrix34TApplyV(&max_friction, &tv2, mat2);
                BrVector3InvScale(&tv2, &max_friction, car2->M);
                BrVector3Accumulate(&f2, &tv2);
            }
        }
        if (tforce == 0.0f) {
            return 0;
        }
        BrMatrix34ApplyV(&tv, &f1, mat1);
        if (move_car1) {
            BrVector3Accumulate(&car1->v, &tv);
        }
        CrushAndDamageCar((tCar_spec*)car1, &pos1, &f1, (tCar_spec*)car2);
        if ((car1->infinite_mass & 0x100) != 0) {
            BrVector3Sub(&tv2, &car1->cmpos, &pos1);
            BrVector3Accumulate(&tv2, &car1->cmpos);
            ts = BrVector3Length(&f1);
            if (ts > 0.0001f) {
                ts = 5.0f / ts;
                BrVector3Scale(&a, &f1, ts);
                BrVector3Accumulate(&tv2, &a);
                plane = LineBoxColl(&tv2, &pos1, &car1->bounds[1], &a);
                if (plane) {
                    BrVector3Negate(&f12, &f1);
                    CrushAndDamageCar(CAR(car1), &a, &f12, CAR(car2));
                }
            }
        }
        BrMatrix34ApplyV(&tv, &f2, mat2);
        if (move_car2) {
            BrVector3Accumulate(&car2->v, &tv);
        }
        CrushAndDamageCar(CAR(car2), &pos2, &f2, CAR(car1));
        if ((car2->infinite_mass & 0x100) != 0) {
            BrVector3Sub(&tv2, &car2->cmpos, &pos2);
            BrVector3Accumulate(&tv2, &car2->cmpos);
            ts = BrVector3Length(&f2);
            if (ts > 0.0001f) {
                ts = 5.0 / ts;
                BrVector3Scale(&a, &f2, ts);
                BrVector3Accumulate(&tv2, &a);
                plane = LineBoxColl(&tv2, &pos2, &car2->bounds[1], &a);
                if (plane) {
                    BrVector3Negate(&f22, &f2);
                    CrushAndDamageCar(CAR(car2), &a, &f22, CAR(car1));
                }
            }
        }
        BrMatrix34ApplyP(&tv2, &pos1, mat1);
        BrVector3InvScale(&tv2, &tv2, WORLD_SCALE);
        BrVector3Scale(&f1, &f1, 5.0f);
        CrashNoise(&f1, &tv2, 0);
        BrVector3Add(&a, &car2->v, &car1->v);
        BrVector3Scale(&a, &a, 0.25f / WORLD_SCALE);
        BrVector3Scale(&tv, &tv, car2->M * 3.0f);
        CreateSparkShower(&tv2, &a, &tv, CAR(car1), CAR(car2));
        return 0;
    } else {
        return original_DoCollide(car1, car2, r, n, k, pPass, mat1_to_mat2);
    }
}

function_hook_state_t function_hook_state_TwoPointCollB = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(function_hook_state_TwoPointCollB)
static br_scalar(__cdecl*original_TwoPointCollB)(br_scalar *, br_matrix4 *, br_scalar *, br_vector3 *, br_vector3 *) = (br_scalar(__cdecl*)(br_scalar *, br_matrix4 *, br_scalar *, br_vector3 *, br_vector3 *))0x004927be;
CARM95_HOOK_FUNCTION(original_TwoPointCollB, TwoPointCollB)
br_scalar __cdecl TwoPointCollB(br_scalar *f, br_matrix4 *m, br_scalar *d, br_vector3 *tau, br_vector3 *n) {
    br_scalar ts;
    LOG_TRACE("(%p, %p, %p, %p, %p)", f, m, d, tau, n);

    (void)f;
    (void)m;
    (void)d;
    (void)tau;
    (void)n;
    (void)ts;

    if (function_hook_state_TwoPointCollB == HOOK_ENABLED) {
        ts = m->m[1][1] * m->m[0][0] - m->m[0][1] * m->m[1][0];
        if (fabsf(ts) > 0.000001f) {
            f[0] = (m->m[1][1] * d[0] - m->m[0][1] * d[1]) / ts;
            f[1] = (m->m[1][0] * d[0] - m->m[0][0] * d[1]) / -ts;
        }
        if (f[1] >= 0.0f) {
            if (f[0] < 0.0f) {
                m->m[0][0] = m->m[1][1];
                tau[0] = tau[1];
                tau[4] = tau[5];
                n[0] = n[2];
                n[1] = n[3];
                d[0] = d[1];
                ts = SinglePointColl(f, m, d);
                f[1] = 0.0f;
            }
        } else {
            ts = SinglePointColl(f, m, d);
            f[1] = 0.0;
        }
        return ts;
    } else {
        return original_TwoPointCollB(f, m, d, tau, n);
    }
}

function_hook_state_t function_hook_state_ThreePointCollRecB = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(function_hook_state_ThreePointCollRecB)
static br_scalar(__cdecl*original_ThreePointCollRecB)(br_scalar *, br_matrix4 *, br_scalar *, br_vector3 *, br_vector3 *) = (br_scalar(__cdecl*)(br_scalar *, br_matrix4 *, br_scalar *, br_vector3 *, br_vector3 *))0x00492961;
CARM95_HOOK_FUNCTION(original_ThreePointCollRecB, ThreePointCollRecB)
br_scalar __cdecl ThreePointCollRecB(br_scalar *f, br_matrix4 *m, br_scalar *d, br_vector3 *tau, br_vector3 *n) {
    int i;
    int j;
    br_scalar ts;
    LOG_TRACE("(%p, %p, %p, %p, %p)", f, m, d, tau, n);

    (void)f;
    (void)m;
    (void)d;
    (void)tau;
    (void)n;
    (void)i;
    (void)j;
    (void)ts;

    if (function_hook_state_ThreePointCollRecB == HOOK_ENABLED) {
        ts = ThreePointColl(f, m, d);
        if (f[0] >= 0.0f && f[1] >= 0.0f && f[2] >= 0.0f) {
            return ts;
        }
        if (f[2] < 0.f) {
            i = 0;
            j = 1;
        } else if (f[1] < 0.f) {
            i = 0;
            j = 2;
        } else if (f[0] < 0.f) {
            i = 1;
            j = 2;
        } else {
            return 0.0f;
        }
        m->m[0][0] = ((br_scalar*)(m->m))[5 * i];
        m->m[1][0] = m->m[j][i];
        m->m[0][1] = m->m[i][j];
        m->m[1][1] = ((br_scalar*)(m->m))[5 * j];
        tau[0] = tau[i];
        tau[1] = tau[j];
        tau[4] = tau[i + 4];
        tau[5] = tau[j + 4];
        n[0] = n[2 * i];
        n[2] = n[2 * j];
        n[1] = n[2 * i + 1];
        n[3] = n[2 * j + 1];
        d[0] = d[i];
        d[1] = d[j];
        ts = TwoPointCollB(f, m, d, tau, n);
        f[2] = 0.0;
        return ts;
    } else {
        return original_ThreePointCollRecB(f, m, d, tau, n);
    }
}

function_hook_state_t function_hook_state_FourPointCollB = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(function_hook_state_FourPointCollB)
static br_scalar(__cdecl*original_FourPointCollB)(br_scalar *, br_matrix4 *, br_scalar *, br_vector3 *, br_vector3 *) = (br_scalar(__cdecl*)(br_scalar *, br_matrix4 *, br_scalar *, br_vector3 *, br_vector3 *))0x00492cdd;
CARM95_HOOK_FUNCTION(original_FourPointCollB, FourPointCollB)
br_scalar __cdecl FourPointCollB(br_scalar *f, br_matrix4 *m, br_scalar *d, br_vector3 *tau, br_vector3 *n) {
    int i;
    int j;
    int l;
    br_scalar ts;
    LOG_TRACE("(%p, %p, %p, %p, %p)", f, m, d, tau, n);

    (void)f;
    (void)m;
    (void)d;
    (void)tau;
    (void)n;
    (void)i;
    (void)j;
    (void)l;
    (void)ts;

    if (function_hook_state_FourPointCollB == HOOK_ENABLED) {
        ts = ThreePointColl(f, m, d);
        if (f[0] >= 0.0f && f[1] >= 0.0f && f[2] >= 0.0f) {
            return ts;
        }
        if (f[0] < 0.0f) {
            l = 0;
        } else if (f[1] < 0.0f) {
            l = 1;
        } else {
            l = 2;
        }
        for (i = l; i < 3; i++) {
            for (j = 0; j < 4; j++) {
                m->m[i][j] = m->m[i + 1][j];
            }
            d[i] = d[i + 1];
            tau[i] = tau[i + 1];
            tau[i + 4] = tau[i + 5];
            n[2 * i] = n[2 * i + 2];
            n[2 * i + 1] = n[2 * i + 3];
            d[i] = d[i + 1];
        }
        for (i = l; i < 3; i++) {
            for (j = 0; j < 3; j++) {
                m->m[j][i] = m->m[j][i + 1];
            }
        }
        return ThreePointCollRecB(f, m, d, tau, n);
    } else {
        return original_FourPointCollB(f, m, d, tau, n);
    }
}

function_hook_state_t function_hook_state_TestForNan = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(function_hook_state_TestForNan)
static int(__cdecl*original_TestForNan)(float *) = (int(__cdecl*)(float *))0x00492ff8;
CARM95_HOOK_FUNCTION(original_TestForNan, TestForNan)
int __cdecl TestForNan(float *f) {
    tU32 i;
    LOG_TRACE("(%p)", f);

    (void)f;
    (void)i;

    if (function_hook_state_TestForNan == HOOK_ENABLED) {
        return isnan(*f);
    } else {
        return original_TestForNan(f);
    }
}

function_hook_state_t function_hook_state_CheckCameraHither = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(function_hook_state_CheckCameraHither)
static void(__cdecl*original_CheckCameraHither)() = (void(__cdecl*)())0x00493036;
CARM95_HOOK_FUNCTION(original_CheckCameraHither, CheckCameraHither)
void __cdecl CheckCameraHither() {
    br_camera *cam;
    static int old_hither;
    LOG_TRACE("()");

    (void)cam;
    (void)old_hither;

    if (function_hook_state_CheckCameraHither == HOOK_ENABLED) {
        cam = (br_camera*)HV(gCamera)->type_data;
        if (TestForNan(&cam->hither_z)) {
            cam->hither_z = (float)old_hither;
        }
        old_hither = (int)cam->hither_z;
    } else {
        original_CheckCameraHither();
    }
}

function_hook_state_t function_hook_state_SetCarSuspGiveAndHeight = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(function_hook_state_SetCarSuspGiveAndHeight)
static void(__cdecl*original_SetCarSuspGiveAndHeight)(tCar_spec *, br_scalar, br_scalar, br_scalar, br_scalar, br_scalar) = (void(__cdecl*)(tCar_spec *, br_scalar, br_scalar, br_scalar, br_scalar, br_scalar))0x00493087;
CARM95_HOOK_FUNCTION(original_SetCarSuspGiveAndHeight, SetCarSuspGiveAndHeight)
void __cdecl SetCarSuspGiveAndHeight(tCar_spec *pCar, br_scalar pFront_give_factor, br_scalar pRear_give_factor, br_scalar pDamping_factor, br_scalar pExtra_front_height, br_scalar pExtra_rear_height) {
    br_scalar front_give;
    br_scalar rear_give;
    br_scalar damping;
    br_scalar ratio;
    int i;
    LOG_TRACE("(%p, %f, %f, %f, %f, %f)", pCar, pFront_give_factor, pRear_give_factor, pDamping_factor, pExtra_front_height, pExtra_rear_height);

    (void)pCar;
    (void)pFront_give_factor;
    (void)pRear_give_factor;
    (void)pDamping_factor;
    (void)pExtra_front_height;
    (void)pExtra_rear_height;
    (void)front_give;
    (void)rear_give;
    (void)damping;
    (void)ratio;
    (void)i;

    if (function_hook_state_SetCarSuspGiveAndHeight == HOOK_ENABLED) {
        front_give = pCar->susp_give[1] * pFront_give_factor * WORLD_SCALE;
        rear_give = pCar->susp_give[0] * pRear_give_factor * WORLD_SCALE;
        damping = pCar->damping * pDamping_factor;
        ratio = fabs((pCar->wpos[0].v[2] - pCar->cmpos.v[2]) / (pCar->wpos[2].v[2] - pCar->cmpos.v[2]));
        pCar->sk[0] = pCar->M / (ratio + 1.0) * 5.0 / rear_give;
        pCar->sb[0] = pCar->M / (ratio + 1.0) * sqrt(5.0) / sqrt(rear_give);
        ratio = 1.0 / ratio;
        pCar->sk[1] = pCar->M / (ratio + 1.0) * 5.0 / front_give;
        pCar->sb[1] = pCar->M / (ratio + 1.0) * sqrt(5.0) / sqrt(front_give);
        pCar->sb[0] = pCar->sb[0] * damping;
        pCar->sb[1] = pCar->sb[1] * damping;
        pCar->susp_height[0] = pCar->ride_height + rear_give + pExtra_rear_height;
        pCar->susp_height[1] = pCar->ride_height + front_give + pExtra_front_height;

        if (rear_give >= front_give) {
            i = -rear_give;
        } else {
            i = -front_give;
        }
        if (pExtra_rear_height >= pExtra_front_height) {
            i -= pExtra_rear_height;
        } else {
            i -= pExtra_front_height;
        }
        pCar->bounds[0].min.v[1] = i;
        pCar->bounds[0].min.v[1] = pCar->bounds[0].min.v[1] / WORLD_SCALE;
    } else {
        original_SetCarSuspGiveAndHeight(pCar, pFront_give_factor, pRear_give_factor, pDamping_factor, pExtra_front_height, pExtra_rear_height);
    }
}

function_hook_state_t function_hook_state_TestForCarInSensiblePlace = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(function_hook_state_TestForCarInSensiblePlace)
static int(__cdecl*original_TestForCarInSensiblePlace)(tCar_spec *) = (int(__cdecl*)(tCar_spec *))0x0049327e;
CARM95_HOOK_FUNCTION(original_TestForCarInSensiblePlace, TestForCarInSensiblePlace)
int __cdecl TestForCarInSensiblePlace(tCar_spec *car) {
    br_bounds bnds;
    br_matrix34 mat;
    br_matrix34 *mat1;
    br_matrix34 *mat2;
    int i;
    int j;
    int k;
    tCollision_info *c2;
    tCollision_info *car_info;
    br_vector3 sep;
    br_vector3 tv;
    br_vector3 tv2;
    br_scalar __block0___scale;
    LOG_TRACE("(%p)", car);

    (void)car;
    (void)bnds;
    (void)mat;
    (void)mat1;
    (void)mat2;
    (void)i;
    (void)j;
    (void)k;
    (void)c2;
    (void)car_info;
    (void)sep;
    (void)tv;
    (void)tv2;
    (void)__block0___scale;

    if (function_hook_state_TestForCarInSensiblePlace == HOOK_ENABLED) {
        car_info = (tCollision_info*)car;
        if (!HV(gProgram_state).racing) {
            return 1;
        }
        mat1 = &car_info->car_master_actor->t.t.mat;
        if (!HV(gDoing_physics)) {
            mat1->m[3][0] = mat1->m[3][0] * WORLD_SCALE;
            mat1->m[3][1] = mat1->m[3][1] * WORLD_SCALE;
            mat1->m[3][2] = mat1->m[3][2] * WORLD_SCALE;
        }
        GetFacesInBox(car_info);
        BrMatrix34ApplyP(&car_info->pos, &car_info->cmpos, &car_info->car_master_actor->t.t.mat);
        car_info->pos.v[0] = car_info->pos.v[0] / WORLD_SCALE;
        car_info->pos.v[1] = car_info->pos.v[1] / WORLD_SCALE;
        car_info->pos.v[2] = car_info->pos.v[2] / WORLD_SCALE;
        k = CollCheck(car_info, -2.0);
        if (!k) {
            if (HV(gNum_active_non_cars) + HV(gNum_active_cars) != HV(gNum_cars_and_non_cars)) {
                GetNonCars();
            }
            for (i = 0; i < HV(gNum_cars_and_non_cars); i++) {
                c2 = (tCollision_info*)HV(gActive_car_list)[i];
                if (car_info != c2) {
                    mat2 = &c2->car_master_actor->t.t.mat;
                    mat2->m[3][0] = mat2->m[3][0] * WORLD_SCALE;
                    mat2->m[3][1] = mat2->m[3][1] * WORLD_SCALE;
                    mat2->m[3][2] = mat2->m[3][2] * WORLD_SCALE;
                    sep.v[0] = mat1->m[3][0] - mat2->m[3][0];
                    sep.v[1] = mat1->m[3][1] - mat2->m[3][1];
                    sep.v[2] = mat1->m[3][2] - mat2->m[3][2];
                    if (BrVector3LengthSquared(&sep) <= 100.0) {
                        k += TestOldMats(car_info, c2, 0);
                        k += TestOldMats(c2, car_info, 0);
                    }
                    if (k != 0) {
                        BrMatrix34ApplyP(&tv, &car_info->cmpos, mat1);
                        BrMatrix34ApplyP(&tv2, &c2->cmpos, mat2);
                        BrVector3Sub(&tv, &tv2, &tv);
                        BrMatrix34TApplyV(&car_info->old_point, &tv, &car_info->car_master_actor->t.t.mat);
                        BrVector3Normalise(&car_info->old_norm, &car_info->old_point);
                        BrVector3Negate(&car_info->old_norm, &car_info->old_norm);
                    }
                    mat2->m[3][0] = mat2->m[3][0] / WORLD_SCALE;
                    mat2->m[3][1] = mat2->m[3][1] / WORLD_SCALE;
                    mat2->m[3][2] = mat2->m[3][2] / WORLD_SCALE;
                    if (k != 0) {
                        break;
                    }
                }
            }
        }
        if (!HV(gDoing_physics)) {
            mat1->m[3][0] = mat1->m[3][0] / WORLD_SCALE;
            mat1->m[3][1] = mat1->m[3][1] / WORLD_SCALE;
            mat1->m[3][2] = mat1->m[3][2] / WORLD_SCALE;
        }
        if (k != 0) {
            return 0;
        } else {
            return -1;
        }
    } else {
        return original_TestForCarInSensiblePlace(car);
    }
}

function_hook_state_t function_hook_state_TestOldMats = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(function_hook_state_TestOldMats)
static int(__cdecl*original_TestOldMats)(tCollision_info *, tCollision_info *, int) = (int(__cdecl*)(tCollision_info *, tCollision_info *, int))0x004936e6;
CARM95_HOOK_FUNCTION(original_TestOldMats, TestOldMats)
int __cdecl TestOldMats(tCollision_info *c1, tCollision_info *c2, int newmats) {
    br_vector3 p1;
    br_vector3 p2;
    br_vector3 tp1;
    br_vector3 tp2;
    br_vector3 tp3;
    br_vector3 hp1;
    br_vector3 hp2;
    br_vector3 hp3;
    br_vector3 shp1;
    br_vector3 shp2;
    br_vector3 edge;
    int plane1;
    int plane2;
    int plane3;
    br_scalar ts;
    int i;
    int j;
    int n;
    br_bounds *b1;
    br_bounds *b2;
    br_matrix34 invmat1;
    br_matrix34 mat21;
    LOG_TRACE("(%p, %p, %d)", c1, c2, newmats);

    (void)c1;
    (void)c2;
    (void)newmats;
    (void)p1;
    (void)p2;
    (void)tp1;
    (void)tp2;
    (void)tp3;
    (void)hp1;
    (void)hp2;
    (void)hp3;
    (void)shp1;
    (void)shp2;
    (void)edge;
    (void)plane1;
    (void)plane2;
    (void)plane3;
    (void)ts;
    (void)i;
    (void)j;
    (void)n;
    (void)b1;
    (void)b2;
    (void)invmat1;
    (void)mat21;

    if (function_hook_state_TestOldMats == HOOK_ENABLED) {
        n = 0;
        b1 = &c1->bounds[1];
        b2 = &c2->bounds[1];
        if (newmats) {
            BrMatrix34LPInverse(&invmat1, &c1->car_master_actor->t.t.mat);
            BrMatrix34Mul(&mat21, &c2->car_master_actor->t.t.mat, &invmat1);
        } else {
            BrMatrix34LPInverse(&invmat1, &c1->oldmat);
            BrMatrix34Mul(&mat21, &c2->oldmat, &invmat1);
        }
        for (i = 0; i < 4; ++i) {
            if (i == 3) {
                edge = b2->min;
            } else {
                edge = b2->max;
                edge.v[i] = b2->min.v[i];
            }
            for (j = 0; j < 3; ++j) {
                tp1 = edge;
                if (b2->max.v[j] == tp1.v[j]) {
                    tp1.v[j] = b2->min.v[j];
                } else {
                    tp1.v[j] = b2->max.v[j];
                }
                BrMatrix34ApplyP(&p1, &edge, &mat21);
                BrMatrix34ApplyP(&p2, &tp1, &mat21);
                if (LineBoxColl(&p1, &p2, &c1->bounds[1], &hp1)) {
                    n++;
                }
            }
        }
        return n;
    } else {
        return original_TestOldMats(c1, c2, newmats);
    }
}

function_hook_state_t function_hook_state_PullActorFromWorld = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(function_hook_state_PullActorFromWorld)
static int(__cdecl*original_PullActorFromWorld)(br_actor *) = (int(__cdecl*)(br_actor *))0x0049393a;
CARM95_HOOK_FUNCTION(original_PullActorFromWorld, PullActorFromWorld)
int __cdecl PullActorFromWorld(br_actor *pActor) {
    LOG_TRACE("(%p)", pActor);

    (void)pActor;

    if (function_hook_state_PullActorFromWorld == HOOK_ENABLED) {
        if (HV(gDoing_physics)) {
            return DoPullActorFromWorld(pActor);
        }
        return 0;
    } else {
        return original_PullActorFromWorld(pActor);
    }
}

function_hook_state_t function_hook_state_DoPullActorFromWorld = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(function_hook_state_DoPullActorFromWorld)
static int(__cdecl*original_DoPullActorFromWorld)(br_actor *) = (int(__cdecl*)(br_actor *))0x0049396a;
CARM95_HOOK_FUNCTION(original_DoPullActorFromWorld, DoPullActorFromWorld)
int __cdecl DoPullActorFromWorld(br_actor *pActor) {
    int num;
    int i;
    tCollision_info *c;
    tNon_car_spec *non_car;
    LOG_TRACE("(%p)", pActor);

    (void)pActor;
    (void)num;
    (void)i;
    (void)c;
    (void)non_car;

    if (function_hook_state_DoPullActorFromWorld == HOOK_ENABLED) {
        non_car = NULL;
        num = 10 * (pActor->identifier[1] - '0') + 1 * (pActor->identifier[2] - '0');
        if (HV(gNon_car_spec_list)[num]) {
            non_car = &HV(gProgram_state).non_cars[HV(gNon_car_spec_list)[num] + 4];
        }
        if (non_car && non_car->collision_info.driver == eDriver_non_car) {
            non_car = HV(gProgram_state).non_cars;
            for (i = 0; i < NONCAR_UNUSED_SLOTS; i++) {
                if (non_car->collision_info.driver == eDriver_non_car_unused_slot) {
                    break;
                }
                non_car++;
            }
            if (i == NONCAR_UNUSED_SLOTS) {
                non_car = NULL;
            } else {
                memcpy(non_car, &HV(gProgram_state).non_cars[HV(gNon_car_spec_list)[num] + 4], sizeof(tNon_car_spec));
            }
        }
        if (non_car != NULL) {
            pActor->type_data = non_car;
            c = &non_car->collision_info;
            c->driver = eDriver_non_car;
            c->doing_nothing_flag = 1;
            BrActorRemove(pActor);
            BrActorAdd(HV(gNon_track_actor), pActor);
            c->car_master_actor = pActor;
            c->car_ID = 100 * (pActor->identifier[5] - '0') + 10 * (pActor->identifier[6] - '0') + 1 * (pActor->identifier[7] - '0');
            HV(gActive_non_car_list)[HV(gNum_active_non_cars)] = non_car;
            HV(gNum_active_non_cars)++;
            HV(gActive_car_list)[HV(gNum_cars_and_non_cars)] = (tCar_spec*)non_car;
            HV(gNum_cars_and_non_cars)++;
            GetNewBoundingBox(&c->bounds_world_space, c->bounds, &pActor->t.t.mat);
            non_car->collision_info.bounds_ws_type = eBounds_ws;
            InitialiseNonCar(non_car);
            ResetCarSpecialVolume((tCollision_info*)non_car);
            if (HV(gDoing_physics)) {
                BrVector3Scale((br_vector3*)&pActor->t.t.mat.m[3][0], (br_vector3*)&pActor->t.t.mat.m[3][0], WORLD_SCALE);
            }
            BrMatrix34Copy(&c->oldmat, &pActor->t.t.mat);
            if (!HV(gDoing_physics)) {
                BrVector3Scale((br_vector3*)&c->oldmat.m[3][0], (br_vector3*)&c->oldmat.m[3][0], WORLD_SCALE);
            }
            PipeSingleNonCar((tCollision_info*)non_car);
            return 1;
        } else {
            pActor->identifier[1] = 'x';
            return 0;
        }
    } else {
        return original_DoPullActorFromWorld(pActor);
    }
}

function_hook_state_t function_hook_state_CheckForDeAttachmentOfNonCars = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(function_hook_state_CheckForDeAttachmentOfNonCars)
static void(__cdecl*original_CheckForDeAttachmentOfNonCars)(tU32) = (void(__cdecl*)(tU32))0x00493c46;
CARM95_HOOK_FUNCTION(original_CheckForDeAttachmentOfNonCars, CheckForDeAttachmentOfNonCars)
void __cdecl CheckForDeAttachmentOfNonCars(tU32 pTime) {
    static tU32 total_time;
    br_bounds bnds;
    int i;
    int j;
    int last_free_slot;
    int drop;
    tCollision_info *c;
    tCollision_info *c2;
    br_actor *actor;
    tU8 cx;
    tU8 cz;
    tTrack_spec *track_spec;
    br_matrix34 mat;
    LOG_TRACE("(%u)", pTime);

    (void)pTime;
    (void)total_time;
    (void)bnds;
    (void)i;
    (void)j;
    (void)last_free_slot;
    (void)drop;
    (void)c;
    (void)c2;
    (void)actor;
    (void)cx;
    (void)cz;
    (void)track_spec;
    (void)mat;

    if (function_hook_state_CheckForDeAttachmentOfNonCars == HOOK_ENABLED) {
        if (HV(gNum_active_non_cars) == 0) {
            return;
        }

        last_free_slot = 0;
        track_spec = &HV(gProgram_state).track_spec;

        StartPipingSession(ePipe_chunk_non_car);
        for (i = 0; i < HV(gNum_active_non_cars); i++) {
            if (!HV(gActive_non_car_list)[i]->collision_info.doing_nothing_flag) {
                AddNonCarToPipingSession(HV(gActive_non_car_list)[i]->collision_info.car_ID, HV(gActive_non_car_list)[i]->collision_info.car_master_actor);
            }
        }
        EndPipingSession();

        total_time += pTime;
        if (total_time < 1000) {
            return;
        }
        total_time = 0;
        for (i = 0; i < HV(gNum_active_non_cars); i++) {
            c = &HV(gActive_non_car_list)[i]->collision_info;
            if (c->car_master_actor->t.t.mat.m[3][1] < (double)HV(gMin_world_y)) {
                c->doing_nothing_flag = 1;
            }
            if (TestForNan(&c->car_master_actor->t.t.mat.m[3][1])) {
                BrVector3Set(&c->omega, 0.0f, 0.0f, 0.0f);
                BrMatrix34Identity(&c->car_master_actor->t.t.mat);
                c->car_master_actor->t.t.mat.m[3][0] = 2000.0f;
                c->car_master_actor->t.t.mat.m[3][1] = 0.0f;
                c->car_master_actor->t.t.mat.m[3][2] = 0.0f;
                c->doing_nothing_flag = 1;
            }
            actor = c->car_master_actor;
            HV(gActive_non_car_list)[last_free_slot] = HV(gActive_non_car_list)[i];
            if (c->doing_nothing_flag) {
                drop = 1;
                for (j = 0; j < HV(gNum_cars_and_non_cars); j++) {
                    c2 = (tCollision_info*)HV(gActive_car_list)[j];
                    if (c2 != c && !c2->doing_nothing_flag) {
                        BrMatrix34Mul(&mat, &actor->t.t.mat, &c2->last_box_inv_mat);
                        GetNewBoundingBox(&bnds, &actor->model->bounds, &mat);
                        if (c2->last_box.max.v[0] >= bnds.min.v[0]
                            && c2->last_box.max.v[1] >= bnds.min.v[1]
                            && c2->last_box.max.v[2] >= bnds.min.v[2]
                            && c2->last_box.min.v[0] <= bnds.max.v[0]
                            && c2->last_box.min.v[1] <= bnds.max.v[1]
                            && c2->last_box.min.v[2] <= bnds.max.v[2]) {
                            drop = 0;
                            break;
                        }
                    }
                }
                if (drop) {
                    BrActorRemove(actor);
                    c->driver = eDriver_non_car_unused_slot;
                    last_free_slot--;
                    XZToColumnXZ(&cx, &cz, actor->t.t.mat.m[3][0], actor->t.t.mat.m[3][2], track_spec);
                    if (track_spec->columns[cz][cx]) {
                        BrActorAdd(track_spec->columns[cz][cx], actor);
                    } else {
                        BrActorAdd(HV(gTrack_actor), actor);
                    }
                }
            }
            last_free_slot++;
        }
        HV(gNum_active_non_cars) = last_free_slot;
    } else {
        original_CheckForDeAttachmentOfNonCars(pTime);
    }
}

function_hook_state_t function_hook_state_AdjustNonCar = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_AdjustNonCar)
static void(__cdecl*original_AdjustNonCar)(br_actor *, br_matrix34 *) = (void(__cdecl*)(br_actor *, br_matrix34 *))0x00493ff2;
CARM95_HOOK_FUNCTION(original_AdjustNonCar, AdjustNonCar)
void __cdecl AdjustNonCar(br_actor *pActor, br_matrix34 *pMat) {
    tU8 cx;
    tU8 cz;
    tTrack_spec *track_spec;
    LOG_TRACE("(%p, %p)", pActor, pMat);

    (void)pActor;
    (void)pMat;
    (void)cx;
    (void)cz;
    (void)track_spec;

    if (function_hook_state_AdjustNonCar == HOOK_ENABLED) {
        assert(0 && "AdjustNonCar not implemented.");
        abort();
    } else {
        original_AdjustNonCar(pActor, pMat);
    }
}

function_hook_state_t function_hook_state_PipeSingleNonCar = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_PipeSingleNonCar)
static void(__cdecl*original_PipeSingleNonCar)(tCollision_info *) = (void(__cdecl*)(tCollision_info *))0x004940c2;
CARM95_HOOK_FUNCTION(original_PipeSingleNonCar, PipeSingleNonCar)
void __cdecl PipeSingleNonCar(tCollision_info *c) {
    LOG_TRACE("(%p)", c);

    (void)c;

    if (function_hook_state_PipeSingleNonCar == HOOK_ENABLED) {
        assert(0 && "PipeSingleNonCar not implemented.");
        abort();
    } else {
        original_PipeSingleNonCar(c);
    }
}

function_hook_state_t function_hook_state_GetPrecalculatedFacesUnderCar = HOOK_ENABLED;
CARM95_WEBSERVER_STATE(function_hook_state_GetPrecalculatedFacesUnderCar)
static int(__cdecl*original_GetPrecalculatedFacesUnderCar)(tCar_spec *, tFace_ref **) = (int(__cdecl*)(tCar_spec *, tFace_ref **))0x004941a2;
CARM95_HOOK_FUNCTION(original_GetPrecalculatedFacesUnderCar, GetPrecalculatedFacesUnderCar)
int __cdecl GetPrecalculatedFacesUnderCar(tCar_spec *pCar, tFace_ref **pFace_refs) {
    LOG_TRACE("(%p, %p)", pCar, pFace_refs);

    (void)pCar;
    (void)pFace_refs;

    if (function_hook_state_GetPrecalculatedFacesUnderCar == HOOK_ENABLED) {
        if (pCar->box_face_ref != HV(gFace_num__car)
            && (pCar->box_face_ref != HV(gFace_num__car) - 1 || pCar->box_face_start <= HV(gFace_count))) {
            return 0;
        }
        *pFace_refs = &HV(gFace_list__car)[pCar->box_face_start];
        return pCar->box_face_end - pCar->box_face_start;
    } else {
        return original_GetPrecalculatedFacesUnderCar(pCar, pFace_refs);
    }
}

function_hook_state_t function_hook_state_SomeNearbyMaterial = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_SomeNearbyMaterial)
br_material* SomeNearbyMaterial() {
    LOG_TRACE("()");


    if (function_hook_state_SomeNearbyMaterial == HOOK_ENABLED) {
        assert(0 && "SomeNearbyMaterial not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}

