#include "car.h"

#include "harness/trace.h"

#include "carm95_hooks.h"

#include "carm95_webserver.h"

#include <assert.h>
int * hookvar_gDoing_physics  = (void*)0x00514cb0;
br_scalar * hookvar_gDt  = (void*)0x00514cb4;
 // Suffix added to avoid duplicate symbol
int * hookvar_gCollision_detection_on__car  = (void*)0x00514cb8;
 // Suffix added to avoid duplicate symbol
br_vector3 * hookvar_gGround_normal__car  = (void*)0x00514cc0;
 // Suffix added to avoid duplicate symbol
#if 0
void(**(* hookvar_ControlCar__car )[6])(tCar_spec *, br_scalar);
#endif
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
#if 0
tSave_camera(* hookvar_gSave_camera )[2];
#endif
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

function_hook_state_t function_hook_state_DamageUnit = HOOK_UNAVAILABLE;
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
        assert(0 && "DamageUnit not implemented.");
        abort();
    } else {
        original_DamageUnit(pCar, pUnit_type, pDamage_amount);
    }
}

function_hook_state_t function_hook_state_DamageUnitWithSmoke = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_DamageUnitWithSmoke)
static void(__cdecl*original_DamageUnitWithSmoke)(tCar_spec *, int, int) = (void(__cdecl*)(tCar_spec *, int, int))0x00475239;
CARM95_HOOK_FUNCTION(original_DamageUnitWithSmoke, DamageUnitWithSmoke)
void __cdecl DamageUnitWithSmoke(tCar_spec *pCar, int pUnit_type, int pDamage_amount) {
    LOG_TRACE("(%p, %d, %d)", pCar, pUnit_type, pDamage_amount);

    (void)pCar;
    (void)pUnit_type;
    (void)pDamage_amount;

    if (function_hook_state_DamageUnitWithSmoke == HOOK_ENABLED) {
        assert(0 && "DamageUnitWithSmoke not implemented.");
        abort();
    } else {
        original_DamageUnitWithSmoke(pCar, pUnit_type, pDamage_amount);
    }
}

function_hook_state_t function_hook_state_DamageEngine = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_DamageEngine)
static void(__cdecl*original_DamageEngine)(int) = (void(__cdecl*)(int))0x00475215;
CARM95_HOOK_FUNCTION(original_DamageEngine, DamageEngine)
void __cdecl DamageEngine(int pDamage_amount) {
    LOG_TRACE("(%d)", pDamage_amount);

    (void)pDamage_amount;

    if (function_hook_state_DamageEngine == HOOK_ENABLED) {
        assert(0 && "DamageEngine not implemented.");
        abort();
    } else {
        original_DamageEngine(pDamage_amount);
    }
}

function_hook_state_t function_hook_state_DamageTrans = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_DamageTrans)
static void(__cdecl*original_DamageTrans)(int) = (void(__cdecl*)(int))0x00475264;
CARM95_HOOK_FUNCTION(original_DamageTrans, DamageTrans)
void __cdecl DamageTrans(int pDamage_amount) {
    LOG_TRACE("(%d)", pDamage_amount);

    (void)pDamage_amount;

    if (function_hook_state_DamageTrans == HOOK_ENABLED) {
        assert(0 && "DamageTrans not implemented.");
        abort();
    } else {
        original_DamageTrans(pDamage_amount);
    }
}

function_hook_state_t function_hook_state_DamageSteering = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_DamageSteering)
static void(__cdecl*original_DamageSteering)(int) = (void(__cdecl*)(int))0x00475288;
CARM95_HOOK_FUNCTION(original_DamageSteering, DamageSteering)
void __cdecl DamageSteering(int pDamage_amount) {
    LOG_TRACE("(%d)", pDamage_amount);

    (void)pDamage_amount;

    if (function_hook_state_DamageSteering == HOOK_ENABLED) {
        assert(0 && "DamageSteering not implemented.");
        abort();
    } else {
        original_DamageSteering(pDamage_amount);
    }
}

function_hook_state_t function_hook_state_DamageLFWheel = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_DamageLFWheel)
static void(__cdecl*original_DamageLFWheel)(int) = (void(__cdecl*)(int))0x004752ac;
CARM95_HOOK_FUNCTION(original_DamageLFWheel, DamageLFWheel)
void __cdecl DamageLFWheel(int pDamage_amount) {
    LOG_TRACE("(%d)", pDamage_amount);

    (void)pDamage_amount;

    if (function_hook_state_DamageLFWheel == HOOK_ENABLED) {
        assert(0 && "DamageLFWheel not implemented.");
        abort();
    } else {
        original_DamageLFWheel(pDamage_amount);
    }
}

function_hook_state_t function_hook_state_DamageLFBrake = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_DamageLFBrake)
static void(__cdecl*original_DamageLFBrake)(int) = (void(__cdecl*)(int))0x004752d0;
CARM95_HOOK_FUNCTION(original_DamageLFBrake, DamageLFBrake)
void __cdecl DamageLFBrake(int pDamage_amount) {
    LOG_TRACE("(%d)", pDamage_amount);

    (void)pDamage_amount;

    if (function_hook_state_DamageLFBrake == HOOK_ENABLED) {
        assert(0 && "DamageLFBrake not implemented.");
        abort();
    } else {
        original_DamageLFBrake(pDamage_amount);
    }
}

function_hook_state_t function_hook_state_DamageLRBrake = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_DamageLRBrake)
static void(__cdecl*original_DamageLRBrake)(int) = (void(__cdecl*)(int))0x004752f4;
CARM95_HOOK_FUNCTION(original_DamageLRBrake, DamageLRBrake)
void __cdecl DamageLRBrake(int pDamage_amount) {
    LOG_TRACE("(%d)", pDamage_amount);

    (void)pDamage_amount;

    if (function_hook_state_DamageLRBrake == HOOK_ENABLED) {
        assert(0 && "DamageLRBrake not implemented.");
        abort();
    } else {
        original_DamageLRBrake(pDamage_amount);
    }
}

function_hook_state_t function_hook_state_DamageLRWheel = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_DamageLRWheel)
static void(__cdecl*original_DamageLRWheel)(int) = (void(__cdecl*)(int))0x00475318;
CARM95_HOOK_FUNCTION(original_DamageLRWheel, DamageLRWheel)
void __cdecl DamageLRWheel(int pDamage_amount) {
    LOG_TRACE("(%d)", pDamage_amount);

    (void)pDamage_amount;

    if (function_hook_state_DamageLRWheel == HOOK_ENABLED) {
        assert(0 && "DamageLRWheel not implemented.");
        abort();
    } else {
        original_DamageLRWheel(pDamage_amount);
    }
}

function_hook_state_t function_hook_state_DamageRFWheel = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_DamageRFWheel)
static void(__cdecl*original_DamageRFWheel)(int) = (void(__cdecl*)(int))0x0047533c;
CARM95_HOOK_FUNCTION(original_DamageRFWheel, DamageRFWheel)
void __cdecl DamageRFWheel(int pDamage_amount) {
    LOG_TRACE("(%d)", pDamage_amount);

    (void)pDamage_amount;

    if (function_hook_state_DamageRFWheel == HOOK_ENABLED) {
        assert(0 && "DamageRFWheel not implemented.");
        abort();
    } else {
        original_DamageRFWheel(pDamage_amount);
    }
}

function_hook_state_t function_hook_state_DamageRFBrake = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_DamageRFBrake)
static void(__cdecl*original_DamageRFBrake)(int) = (void(__cdecl*)(int))0x00475360;
CARM95_HOOK_FUNCTION(original_DamageRFBrake, DamageRFBrake)
void __cdecl DamageRFBrake(int pDamage_amount) {
    LOG_TRACE("(%d)", pDamage_amount);

    (void)pDamage_amount;

    if (function_hook_state_DamageRFBrake == HOOK_ENABLED) {
        assert(0 && "DamageRFBrake not implemented.");
        abort();
    } else {
        original_DamageRFBrake(pDamage_amount);
    }
}

function_hook_state_t function_hook_state_DamageRRBrake = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_DamageRRBrake)
static void(__cdecl*original_DamageRRBrake)(int) = (void(__cdecl*)(int))0x00475384;
CARM95_HOOK_FUNCTION(original_DamageRRBrake, DamageRRBrake)
void __cdecl DamageRRBrake(int pDamage_amount) {
    LOG_TRACE("(%d)", pDamage_amount);

    (void)pDamage_amount;

    if (function_hook_state_DamageRRBrake == HOOK_ENABLED) {
        assert(0 && "DamageRRBrake not implemented.");
        abort();
    } else {
        original_DamageRRBrake(pDamage_amount);
    }
}

function_hook_state_t function_hook_state_DamageRRWheel = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_DamageRRWheel)
static void(__cdecl*original_DamageRRWheel)(int) = (void(__cdecl*)(int))0x004753a8;
CARM95_HOOK_FUNCTION(original_DamageRRWheel, DamageRRWheel)
void __cdecl DamageRRWheel(int pDamage_amount) {
    LOG_TRACE("(%d)", pDamage_amount);

    (void)pDamage_amount;

    if (function_hook_state_DamageRRWheel == HOOK_ENABLED) {
        assert(0 && "DamageRRWheel not implemented.");
        abort();
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

function_hook_state_t function_hook_state_SwitchCarActor = HOOK_UNAVAILABLE;
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
        assert(0 && "SwitchCarActor not implemented.");
        abort();
    } else {
        original_SwitchCarActor(pCar_spec, pModel_index);
    }
}

function_hook_state_t function_hook_state_InitialiseCar2 = HOOK_UNAVAILABLE;
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
        assert(0 && "InitialiseCar2 not implemented.");
        abort();
    } else {
        original_InitialiseCar2(pCar, pClear_disabled_flag);
    }
}

function_hook_state_t function_hook_state_InitialiseCar = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_InitialiseCar)
static void(__cdecl*original_InitialiseCar)(tCar_spec *) = (void(__cdecl*)(tCar_spec *))0x00475b63;
CARM95_HOOK_FUNCTION(original_InitialiseCar, InitialiseCar)
void __cdecl InitialiseCar(tCar_spec *pCar) {
    LOG_TRACE("(%p)", pCar);

    (void)pCar;

    if (function_hook_state_InitialiseCar == HOOK_ENABLED) {
        assert(0 && "InitialiseCar not implemented.");
        abort();
    } else {
        original_InitialiseCar(pCar);
    }
}

function_hook_state_t function_hook_state_InitialiseCarsEtc = HOOK_UNAVAILABLE;
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
        assert(0 && "InitialiseCarsEtc not implemented.");
        abort();
    } else {
        original_InitialiseCarsEtc(pThe_race);
    }
}

function_hook_state_t function_hook_state_GetAverageGridPosition = HOOK_UNAVAILABLE;
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
        assert(0 && "GetAverageGridPosition not implemented.");
        abort();
    } else {
        original_GetAverageGridPosition(pThe_race);
    }
}

function_hook_state_t function_hook_state_SetInitialPosition = HOOK_UNAVAILABLE;
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
        assert(0 && "SetInitialPosition not implemented.");
        abort();
    } else {
        original_SetInitialPosition(pThe_race, pCar_index, pGrid_index);
    }
}

function_hook_state_t function_hook_state_SetInitialPositions = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_SetInitialPositions)
static void(__cdecl*original_SetInitialPositions)(tRace_info *) = (void(__cdecl*)(tRace_info *))0x00476279;
CARM95_HOOK_FUNCTION(original_SetInitialPositions, SetInitialPositions)
void __cdecl SetInitialPositions(tRace_info *pThe_race) {
    int i;
    LOG_TRACE("(%p)", pThe_race);

    (void)pThe_race;
    (void)i;

    if (function_hook_state_SetInitialPositions == HOOK_ENABLED) {
        assert(0 && "SetInitialPositions not implemented.");
        abort();
    } else {
        original_SetInitialPositions(pThe_race);
    }
}

function_hook_state_t function_hook_state_InitialiseNonCar = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_InitialiseNonCar)
static void(__cdecl*original_InitialiseNonCar)(tNon_car_spec *) = (void(__cdecl*)(tNon_car_spec *))0x004762c1;
CARM95_HOOK_FUNCTION(original_InitialiseNonCar, InitialiseNonCar)
void __cdecl InitialiseNonCar(tNon_car_spec *non_car) {
    tCollision_info *c;
    LOG_TRACE("(%p)", non_car);

    (void)non_car;
    (void)c;

    if (function_hook_state_InitialiseNonCar == HOOK_ENABLED) {
        assert(0 && "InitialiseNonCar not implemented.");
        abort();
    } else {
        original_InitialiseNonCar(non_car);
    }
}

function_hook_state_t function_hook_state_GetFacesInBox = HOOK_UNAVAILABLE;
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
        assert(0 && "GetFacesInBox not implemented.");
        abort();
    } else {
        original_GetFacesInBox(c);
    }
}

function_hook_state_t function_hook_state_IsCarInTheSea = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_IsCarInTheSea)
static int(__cdecl*original_IsCarInTheSea)() = (int(__cdecl*)())0x00476cf4;
CARM95_HOOK_FUNCTION(original_IsCarInTheSea, IsCarInTheSea)
int __cdecl IsCarInTheSea() {
    LOG_TRACE("()");


    if (function_hook_state_IsCarInTheSea == HOOK_ENABLED) {
        assert(0 && "IsCarInTheSea not implemented.");
        abort();
    } else {
        return original_IsCarInTheSea();
    }
}

function_hook_state_t function_hook_state_RememberSafePosition = HOOK_UNAVAILABLE;
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
        assert(0 && "RememberSafePosition not implemented.");
        abort();
    } else {
        original_RememberSafePosition(car, pTime);
    }
}

function_hook_state_t function_hook_state_ControlOurCar = HOOK_UNAVAILABLE;
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
        assert(0 && "ControlOurCar not implemented.");
        abort();
    } else {
        original_ControlOurCar(pTime_difference);
    }
}

function_hook_state_t function_hook_state_CalcEngineForce = HOOK_UNAVAILABLE;
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
        assert(0 && "CalcEngineForce not implemented.");
        abort();
    } else {
        original_CalcEngineForce(c, dt);
    }
}

function_hook_state_t function_hook_state_PrepareCars = HOOK_UNAVAILABLE;
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
        assert(0 && "PrepareCars not implemented.");
        abort();
    } else {
        original_PrepareCars(pFrame_start_time);
    }
}

function_hook_state_t function_hook_state_FinishCars = HOOK_UNAVAILABLE;
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
        assert(0 && "FinishCars not implemented.");
        abort();
    } else {
        original_FinishCars(pLast_frame_time, pTime);
    }
}

function_hook_state_t function_hook_state_InterpolateCars = HOOK_UNAVAILABLE;
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
        assert(0 && "InterpolateCars not implemented.");
        abort();
    } else {
        original_InterpolateCars(pLast_frame_time, pTime);
    }
}

function_hook_state_t function_hook_state_ResetOldmat = HOOK_UNAVAILABLE;
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
        assert(0 && "ResetOldmat not implemented.");
        abort();
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

function_hook_state_t function_hook_state_ApplyPhysicsToCars = HOOK_UNAVAILABLE;
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
        assert(0 && "ApplyPhysicsToCars not implemented.");
        abort();
    } else {
        original_ApplyPhysicsToCars(last_frame_time, pTime_difference);
    }
}

function_hook_state_t function_hook_state_MungeSpecialVolume = HOOK_UNAVAILABLE;
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
        assert(0 && "MungeSpecialVolume not implemented.");
        abort();
    } else {
        original_MungeSpecialVolume(pCar);
    }
}

function_hook_state_t function_hook_state_ResetCarSpecialVolume = HOOK_UNAVAILABLE;
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

    if (function_hook_state_ResetCarSpecialVolume == HOOK_ENABLED) {
        assert(0 && "ResetCarSpecialVolume not implemented.");
        abort();
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

function_hook_state_t function_hook_state_MoveAndCollideCar = HOOK_UNAVAILABLE;
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
        assert(0 && "MoveAndCollideCar not implemented.");
        abort();
    } else {
        original_MoveAndCollideCar(car, dt);
    }
}

function_hook_state_t function_hook_state_MoveAndCollideNonCar = HOOK_UNAVAILABLE;
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
        assert(0 && "MoveAndCollideNonCar not implemented.");
        abort();
    } else {
        original_MoveAndCollideNonCar(non_car, dt);
    }
}

function_hook_state_t function_hook_state_CollideCarWithWall = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_CollideCarWithWall)
static int(__cdecl*original_CollideCarWithWall)(tCollision_info *, br_scalar) = (int(__cdecl*)(tCollision_info *, br_scalar))0x00479a2c;
CARM95_HOOK_FUNCTION(original_CollideCarWithWall, CollideCarWithWall)
int __cdecl CollideCarWithWall(tCollision_info *car, br_scalar dt) {
    LOG_TRACE("(%p, %f)", car, dt);

    (void)car;
    (void)dt;

    if (function_hook_state_CollideCarWithWall == HOOK_ENABLED) {
        assert(0 && "CollideCarWithWall not implemented.");
        abort();
    } else {
        return original_CollideCarWithWall(car, dt);
    }
}

function_hook_state_t function_hook_state_ToggleControls = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_ToggleControls)
void ToggleControls() {
    LOG_TRACE("()");


    if (function_hook_state_ToggleControls == HOOK_ENABLED) {
        assert(0 && "ToggleControls not implemented.");
        abort();
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

function_hook_state_t function_hook_state_ControlCar4 = HOOK_UNAVAILABLE;
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
        assert(0 && "ControlCar4 not implemented.");
        abort();
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

function_hook_state_t function_hook_state_RotateCarSecondOrder = HOOK_UNAVAILABLE;
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
        assert(0 && "RotateCarSecondOrder not implemented.");
        abort();
    } else {
        original_RotateCarSecondOrder(c, dt);
    }
}

function_hook_state_t function_hook_state_RotateCarFirstOrder = HOOK_UNAVAILABLE;
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
        assert(0 && "RotateCarFirstOrder not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}

function_hook_state_t function_hook_state_SimpleRotate = HOOK_UNAVAILABLE;
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
        assert(0 && "SimpleRotate not implemented.");
        abort();
    } else {
        original_SimpleRotate(c, dt);
    }
}

function_hook_state_t function_hook_state_RotateCar = HOOK_UNAVAILABLE;
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
        assert(0 && "RotateCar not implemented.");
        abort();
    } else {
        original_RotateCar(c, dt);
    }
}

function_hook_state_t function_hook_state_SteeringSelfCentre = HOOK_UNAVAILABLE;
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
        assert(0 && "SteeringSelfCentre not implemented.");
        abort();
    } else {
        original_SteeringSelfCentre(c, dt, n);
    }
}

function_hook_state_t function_hook_state_NonCarCalcForce = HOOK_UNAVAILABLE;
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
        assert(0 && "NonCarCalcForce not implemented.");
        abort();
    } else {
        original_NonCarCalcForce(nc, dt);
    }
}

function_hook_state_t function_hook_state_AddDrag = HOOK_UNAVAILABLE;
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
        assert(0 && "AddDrag not implemented.");
        abort();
    } else {
        original_AddDrag(c, dt);
    }
}

function_hook_state_t function_hook_state_DoBumpiness = HOOK_UNAVAILABLE;
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
        assert(0 && "DoBumpiness not implemented.");
        abort();
    } else {
        original_DoBumpiness(c, wheel_pos, norm, d, n);
    }
}

function_hook_state_t function_hook_state_CalcForce = HOOK_UNAVAILABLE;
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
        assert(0 && "CalcForce not implemented.");
        abort();
    } else {
        original_CalcForce(c, dt);
    }
}

function_hook_state_t function_hook_state_DoRevs = HOOK_UNAVAILABLE;
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
        assert(0 && "DoRevs not implemented.");
        abort();
    } else {
        original_DoRevs(c, dt);
    }
}

function_hook_state_t function_hook_state_ApplyTorque = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_ApplyTorque)
static void(__cdecl*original_ApplyTorque)(tCar_spec *, br_vector3 *) = (void(__cdecl*)(tCar_spec *, br_vector3 *))0x0047f4f2;
CARM95_HOOK_FUNCTION(original_ApplyTorque, ApplyTorque)
void __cdecl ApplyTorque(tCar_spec *c, br_vector3 *tdt) {
    LOG_TRACE("(%p, %p)", c, tdt);

    (void)c;
    (void)tdt;

    if (function_hook_state_ApplyTorque == HOOK_ENABLED) {
        assert(0 && "ApplyTorque not implemented.");
        abort();
    } else {
        original_ApplyTorque(c, tdt);
    }
}

function_hook_state_t function_hook_state_TranslateCar = HOOK_UNAVAILABLE;
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
        assert(0 && "TranslateCar not implemented.");
        abort();
    } else {
        original_TranslateCar(c, dt);
    }
}

function_hook_state_t function_hook_state_CollCheck = HOOK_UNAVAILABLE;
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
        assert(0 && "CollCheck not implemented.");
        abort();
    } else {
        return original_CollCheck(c, dt);
    }
}

function_hook_state_t function_hook_state_AddFriction = HOOK_UNAVAILABLE;
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
        assert(0 && "AddFriction not implemented.");
        abort();
    } else {
        return original_AddFriction(c, vel, normal_force, pos, total_force, max_friction);
    }
}

function_hook_state_t function_hook_state_AddFrictionCarToCar = HOOK_UNAVAILABLE;
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
        assert(0 && "AddFrictionCarToCar not implemented.");
        abort();
    } else {
        original_AddFrictionCarToCar(car1, car2, vel1, vel2, normal_force1, pos1, pos2, total_force, max_friction);
    }
}

function_hook_state_t function_hook_state_ScrapeNoise = HOOK_UNAVAILABLE;
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
        assert(0 && "ScrapeNoise not implemented.");
        abort();
    } else {
        original_ScrapeNoise(vel, position, material);
    }
}

function_hook_state_t function_hook_state_SkidNoise = HOOK_UNAVAILABLE;
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
        assert(0 && "SkidNoise not implemented.");
        abort();
    } else {
        original_SkidNoise(pC, pWheel_num, pV, material);
    }
}

function_hook_state_t function_hook_state_StopSkid = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_StopSkid)
static void(__cdecl*original_StopSkid)(tCar_spec *) = (void(__cdecl*)(tCar_spec *))0x00482458;
CARM95_HOOK_FUNCTION(original_StopSkid, StopSkid)
void __cdecl StopSkid(tCar_spec *pC) {
    LOG_TRACE("(%p)", pC);

    (void)pC;

    if (function_hook_state_StopSkid == HOOK_ENABLED) {
        assert(0 && "StopSkid not implemented.");
        abort();
    } else {
        original_StopSkid(pC);
    }
}

function_hook_state_t function_hook_state_CrashNoise = HOOK_UNAVAILABLE;
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
        assert(0 && "CrashNoise not implemented.");
        abort();
    } else {
        original_CrashNoise(pForce, position, material);
    }
}

function_hook_state_t function_hook_state_CrushAndDamageCar = HOOK_UNAVAILABLE;
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
        assert(0 && "CrushAndDamageCar not implemented.");
        abort();
    } else {
        original_CrushAndDamageCar(c, pPosition, pForce_car_space, car2);
    }
}

function_hook_state_t function_hook_state_ExpandBoundingBox = HOOK_UNAVAILABLE;
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
        assert(0 && "ExpandBoundingBox not implemented.");
        abort();
    } else {
        return original_ExpandBoundingBox(c);
    }
}

function_hook_state_t function_hook_state_CrushBoundingBox = HOOK_UNAVAILABLE;
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
        assert(0 && "CrushBoundingBox not implemented.");
        abort();
    } else {
        original_CrushBoundingBox(c, crush_only);
    }
}

function_hook_state_t function_hook_state_AddCollPoint = HOOK_UNAVAILABLE;
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
        assert(0 && "AddCollPoint not implemented.");
        abort();
    } else {
        original_AddCollPoint(dist, p, norm, r, n, dir, num, c);
    }
}

function_hook_state_t function_hook_state_SinglePointColl = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_SinglePointColl)
static br_scalar(__cdecl*original_SinglePointColl)(br_scalar *, br_matrix4 *, br_scalar *) = (br_scalar(__cdecl*)(br_scalar *, br_matrix4 *, br_scalar *))0x0048326d;
CARM95_HOOK_FUNCTION(original_SinglePointColl, SinglePointColl)
br_scalar __cdecl SinglePointColl(br_scalar *f, br_matrix4 *m, br_scalar *d) {
    LOG_TRACE("(%p, %p, %p)", f, m, d);

    (void)f;
    (void)m;
    (void)d;

    if (function_hook_state_SinglePointColl == HOOK_ENABLED) {
        assert(0 && "SinglePointColl not implemented.");
        abort();
    } else {
        return original_SinglePointColl(f, m, d);
    }
}

function_hook_state_t function_hook_state_TwoPointColl = HOOK_UNAVAILABLE;
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
        assert(0 && "TwoPointColl not implemented.");
        abort();
    } else {
        return original_TwoPointColl(f, m, d, tau, n);
    }
}

function_hook_state_t function_hook_state_DrMatrix4Inverse = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_DrMatrix4Inverse)
static br_scalar(__cdecl*original_DrMatrix4Inverse)(br_matrix4 *, br_matrix4 *) = (br_scalar(__cdecl*)(br_matrix4 *, br_matrix4 *))0x0048377f;
CARM95_HOOK_FUNCTION(original_DrMatrix4Inverse, DrMatrix4Inverse)
br_scalar __cdecl DrMatrix4Inverse(br_matrix4 *mi, br_matrix4 *mc) {
    LOG_TRACE("(%p, %p)", mi, mc);

    (void)mi;
    (void)mc;

    if (function_hook_state_DrMatrix4Inverse == HOOK_ENABLED) {
        assert(0 && "DrMatrix4Inverse not implemented.");
        abort();
    } else {
        return original_DrMatrix4Inverse(mi, mc);
    }
}

function_hook_state_t function_hook_state_ThreePointColl = HOOK_UNAVAILABLE;
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
        assert(0 && "ThreePointColl not implemented.");
        abort();
    } else {
        return original_ThreePointColl(f, m, d);
    }
}

function_hook_state_t function_hook_state_ThreePointCollRec = HOOK_UNAVAILABLE;
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
        assert(0 && "ThreePointCollRec not implemented.");
        abort();
    } else {
        return original_ThreePointCollRec(f, m, d, tau, n, c);
    }
}

function_hook_state_t function_hook_state_FourPointColl = HOOK_UNAVAILABLE;
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
        assert(0 && "FourPointColl not implemented.");
        abort();
    } else {
        return original_FourPointColl(f, m, d, tau, n, c);
    }
}

function_hook_state_t function_hook_state_MultiFindFloorInBoxM = HOOK_UNAVAILABLE;
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
        assert(0 && "MultiFindFloorInBoxM not implemented.");
        abort();
    } else {
        original_MultiFindFloorInBoxM(pNum_rays, a, b, nor, d, c, mat_ref);
    }
}

function_hook_state_t function_hook_state_MultiFindFloorInBoxBU = HOOK_UNAVAILABLE;
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
        assert(0 && "MultiFindFloorInBoxBU not implemented.");
        abort();
    } else {
        original_MultiFindFloorInBoxBU(pNum_rays, a, b, nor, d, c, mat_ref);
    }
}

function_hook_state_t function_hook_state_findfloor = HOOK_UNAVAILABLE;
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
        assert(0 && "findfloor not implemented.");
        abort();
    } else {
        original_findfloor(a, b, nor, d);
    }
}

function_hook_state_t function_hook_state_FindFloorInBoxM = HOOK_UNAVAILABLE;
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
        assert(0 && "FindFloorInBoxM not implemented.");
        abort();
    } else {
        return original_FindFloorInBoxM(a, b, nor, d, c);
    }
}

function_hook_state_t function_hook_state_FindFloorInBoxBU = HOOK_UNAVAILABLE;
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
        assert(0 && "FindFloorInBoxBU not implemented.");
        abort();
    } else {
        return original_FindFloorInBoxBU(a, b, nor, d, c);
    }
}

function_hook_state_t function_hook_state_FindFloorInBoxBU2 = HOOK_UNAVAILABLE;
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
        assert(0 && "FindFloorInBoxBU2 not implemented.");
        abort();
    } else {
        return original_FindFloorInBoxBU2(a, b, nor, d, c);
    }
}

function_hook_state_t function_hook_state_FindFloorInBoxM2 = HOOK_UNAVAILABLE;
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
        assert(0 && "FindFloorInBoxM2 not implemented.");
        abort();
    } else {
        return original_FindFloorInBoxM2(a, b, nor, d, c);
    }
}

function_hook_state_t function_hook_state_BoxFaceIntersect = HOOK_UNAVAILABLE;
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
        assert(0 && "BoxFaceIntersect not implemented.");
        abort();
    } else {
        return original_BoxFaceIntersect(pB, pM, pMold, pPoint_list, pNorm_list, pDist_list, pMax_pnts, c);
    }
}

function_hook_state_t function_hook_state_AddEdgeCollPoints = HOOK_UNAVAILABLE;
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
        assert(0 && "AddEdgeCollPoints not implemented.");
        abort();
    } else {
        return original_AddEdgeCollPoints(p1, p2, pB, pMold, pPoint_list, pNorm_list, n, pMax_pnts, c);
    }
}

function_hook_state_t function_hook_state_GetPlaneNormal = HOOK_UNAVAILABLE;
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
        assert(0 && "GetPlaneNormal not implemented.");
        abort();
    } else {
        original_GetPlaneNormal(n, p);
    }
}

function_hook_state_t function_hook_state_GetBoundsEdge = HOOK_UNAVAILABLE;
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
        assert(0 && "GetBoundsEdge not implemented.");
        abort();
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

function_hook_state_t function_hook_state_CancelPendingCunningStunt = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_CancelPendingCunningStunt)
static void(__cdecl*original_CancelPendingCunningStunt)() = (void(__cdecl*)())0x00485d8b;
CARM95_HOOK_FUNCTION(original_CancelPendingCunningStunt, CancelPendingCunningStunt)
void __cdecl CancelPendingCunningStunt() {
    LOG_TRACE("()");


    if (function_hook_state_CancelPendingCunningStunt == HOOK_ENABLED) {
        assert(0 && "CancelPendingCunningStunt not implemented.");
        abort();
    } else {
        original_CancelPendingCunningStunt();
    }
}

function_hook_state_t function_hook_state_frac = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_frac)
static float(__cdecl*original_frac)(float) = (float(__cdecl*)(float))0x00485dc8;
CARM95_HOOK_FUNCTION(original_frac, frac)
float __cdecl frac(float pN) {
    LOG_TRACE("(%f)", pN);

    (void)pN;

    if (function_hook_state_frac == HOOK_ENABLED) {
        assert(0 && "frac not implemented.");
        abort();
    } else {
        return original_frac(pN);
    }
}

function_hook_state_t function_hook_state_SetAmbientPratCam = HOOK_UNAVAILABLE;
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
        assert(0 && "SetAmbientPratCam not implemented.");
        abort();
    } else {
        original_SetAmbientPratCam(pCar);
    }
}

function_hook_state_t function_hook_state_MungeCarGraphics = HOOK_UNAVAILABLE;
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
        assert(0 && "MungeCarGraphics not implemented.");
        abort();
    } else {
        original_MungeCarGraphics(pFrame_period);
    }
}

function_hook_state_t function_hook_state_ResetCarScreens = HOOK_UNAVAILABLE;
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
        assert(0 && "ResetCarScreens not implemented.");
        abort();
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

function_hook_state_t function_hook_state_ViewNetPlayer = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_ViewNetPlayer)
static void(__cdecl*original_ViewNetPlayer)() = (void(__cdecl*)())0x004870d8;
CARM95_HOOK_FUNCTION(original_ViewNetPlayer, ViewNetPlayer)
void __cdecl ViewNetPlayer() {
    LOG_TRACE("()");


    if (function_hook_state_ViewNetPlayer == HOOK_ENABLED) {
        assert(0 && "ViewNetPlayer not implemented.");
        abort();
    } else {
        original_ViewNetPlayer();
    }
}

function_hook_state_t function_hook_state_ViewOpponent = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_ViewOpponent)
static void(__cdecl*original_ViewOpponent)() = (void(__cdecl*)())0x00487248;
CARM95_HOOK_FUNCTION(original_ViewOpponent, ViewOpponent)
void __cdecl ViewOpponent() {
    static int n;
    LOG_TRACE("()");

    (void)n;

    if (function_hook_state_ViewOpponent == HOOK_ENABLED) {
        assert(0 && "ViewOpponent not implemented.");
        abort();
    } else {
        original_ViewOpponent();
    }
}

function_hook_state_t function_hook_state_ToggleCarToCarCollisions = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_ToggleCarToCarCollisions)
static void(__cdecl*original_ToggleCarToCarCollisions)() = (void(__cdecl*)())0x00487333;
CARM95_HOOK_FUNCTION(original_ToggleCarToCarCollisions, ToggleCarToCarCollisions)
void __cdecl ToggleCarToCarCollisions() {
    LOG_TRACE("()");


    if (function_hook_state_ToggleCarToCarCollisions == HOOK_ENABLED) {
        assert(0 && "ToggleCarToCarCollisions not implemented.");
        abort();
    } else {
        original_ToggleCarToCarCollisions();
    }
}

function_hook_state_t function_hook_state_SwapCar = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_SwapCar)
static void(__cdecl*original_SwapCar)() = (void(__cdecl*)())0x004873a6;
CARM95_HOOK_FUNCTION(original_SwapCar, SwapCar)
void __cdecl SwapCar() {
    LOG_TRACE("()");


    if (function_hook_state_SwapCar == HOOK_ENABLED) {
        assert(0 && "SwapCar not implemented.");
        abort();
    } else {
        original_SwapCar();
    }
}

function_hook_state_t function_hook_state_AdjustDownForce = HOOK_UNAVAILABLE;
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
        assert(0 && "AdjustDownForce not implemented.");
        abort();
    } else {
        original_AdjustDownForce();
    }
}

function_hook_state_t function_hook_state_FreezeMechanics = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_FreezeMechanics)
static void(__cdecl*original_FreezeMechanics)() = (void(__cdecl*)())0x00487464;
CARM95_HOOK_FUNCTION(original_FreezeMechanics, FreezeMechanics)
void __cdecl FreezeMechanics() {
    LOG_TRACE("()");


    if (function_hook_state_FreezeMechanics == HOOK_ENABLED) {
        assert(0 && "FreezeMechanics not implemented.");
        abort();
    } else {
        original_FreezeMechanics();
    }
}

function_hook_state_t function_hook_state_PutOpponentsInNeutral = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_PutOpponentsInNeutral)
static void(__cdecl*original_PutOpponentsInNeutral)() = (void(__cdecl*)())0x004874d7;
CARM95_HOOK_FUNCTION(original_PutOpponentsInNeutral, PutOpponentsInNeutral)
void __cdecl PutOpponentsInNeutral() {
    LOG_TRACE("()");


    if (function_hook_state_PutOpponentsInNeutral == HOOK_ENABLED) {
        assert(0 && "PutOpponentsInNeutral not implemented.");
        abort();
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

function_hook_state_t function_hook_state_PositionExternalCamera = HOOK_UNAVAILABLE;
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
        assert(0 && "PositionExternalCamera not implemented.");
        abort();
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

function_hook_state_t function_hook_state_SaveCameraPosition = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_SaveCameraPosition)
static void(__cdecl*original_SaveCameraPosition)(int) = (void(__cdecl*)(int))0x0048949c;
CARM95_HOOK_FUNCTION(original_SaveCameraPosition, SaveCameraPosition)
void __cdecl SaveCameraPosition(int i) {
    LOG_TRACE("(%d)", i);

    (void)i;

    if (function_hook_state_SaveCameraPosition == HOOK_ENABLED) {
        assert(0 && "SaveCameraPosition not implemented.");
        abort();
    } else {
        original_SaveCameraPosition(i);
    }
}

function_hook_state_t function_hook_state_RestoreCameraPosition = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_RestoreCameraPosition)
static void(__cdecl*original_RestoreCameraPosition)(int) = (void(__cdecl*)(int))0x004894f8;
CARM95_HOOK_FUNCTION(original_RestoreCameraPosition, RestoreCameraPosition)
void __cdecl RestoreCameraPosition(int i) {
    LOG_TRACE("(%d)", i);

    (void)i;

    if (function_hook_state_RestoreCameraPosition == HOOK_ENABLED) {
        assert(0 && "RestoreCameraPosition not implemented.");
        abort();
    } else {
        original_RestoreCameraPosition(i);
    }
}

function_hook_state_t function_hook_state_NormalPositionExternalCamera = HOOK_UNAVAILABLE;
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
        assert(0 && "NormalPositionExternalCamera not implemented.");
        abort();
    } else {
        original_NormalPositionExternalCamera(c, pTime);
    }
}

function_hook_state_t function_hook_state_MoveWithWheels = HOOK_UNAVAILABLE;
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
        assert(0 && "MoveWithWheels not implemented.");
        abort();
    } else {
        original_MoveWithWheels(c, vn, manual_swing);
    }
}

function_hook_state_t function_hook_state_SwingCamera = HOOK_UNAVAILABLE;
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
    static br_angle omega;
    static int elapsed_time;
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
        assert(0 && "SwingCamera not implemented.");
        abort();
    } else {
        original_SwingCamera(c, m1, m2, vn, pTime);
    }
}

function_hook_state_t function_hook_state_PointCameraAtCar = HOOK_UNAVAILABLE;
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
        assert(0 && "PointCameraAtCar not implemented.");
        abort();
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

function_hook_state_t function_hook_state_CollideCamera2 = HOOK_UNAVAILABLE;
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
        assert(0 && "CollideCamera2 not implemented.");
        abort();
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

function_hook_state_t function_hook_state_InitialiseExternalCamera = HOOK_UNAVAILABLE;
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
        assert(0 && "InitialiseExternalCamera not implemented.");
        abort();
    } else {
        original_InitialiseExternalCamera();
    }
}

function_hook_state_t function_hook_state_FreezeCamera = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_FreezeCamera)
static void(__cdecl*original_FreezeCamera)() = (void(__cdecl*)())0x0048bc93;
CARM95_HOOK_FUNCTION(original_FreezeCamera, FreezeCamera)
void __cdecl FreezeCamera() {
    LOG_TRACE("()");


    if (function_hook_state_FreezeCamera == HOOK_ENABLED) {
        assert(0 && "FreezeCamera not implemented.");
        abort();
    } else {
        original_FreezeCamera();
    }
}

function_hook_state_t function_hook_state_FlyCar = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_FlyCar)
static void(__cdecl*original_FlyCar)(tCar_spec *, br_scalar) = (void(__cdecl*)(tCar_spec *, br_scalar))0x0048bca8;
CARM95_HOOK_FUNCTION(original_FlyCar, FlyCar)
void __cdecl FlyCar(tCar_spec *c, br_scalar dt) {
    int accflag;
    int turnflag;
    br_vector3 step;
    br_matrix34 *mat;
    br_angle theta;
    static br_scalar vel;
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
        assert(0 && "FlyCar not implemented.");
        abort();
    } else {
        original_FlyCar(c, dt);
    }
}

function_hook_state_t function_hook_state_DrVector3RotateY = HOOK_UNAVAILABLE;
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
        assert(0 && "DrVector3RotateY not implemented.");
        abort();
    } else {
        original_DrVector3RotateY(v, t);
    }
}

function_hook_state_t function_hook_state_CrashCarsTogether = HOOK_UNAVAILABLE;
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
        assert(0 && "CrashCarsTogether not implemented.");
        abort();
    } else {
        original_CrashCarsTogether(dt);
    }
}

function_hook_state_t function_hook_state_CrashCarsTogetherSinglePass = HOOK_UNAVAILABLE;
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
        assert(0 && "CrashCarsTogetherSinglePass not implemented.");
        abort();
    } else {
        return original_CrashCarsTogetherSinglePass(dt, pPass, collide_list);
    }
}

function_hook_state_t function_hook_state_BringCarToAGrindingHalt = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_BringCarToAGrindingHalt)
static void(__cdecl*original_BringCarToAGrindingHalt)(tCollision_info *) = (void(__cdecl*)(tCollision_info *))0x0048d21b;
CARM95_HOOK_FUNCTION(original_BringCarToAGrindingHalt, BringCarToAGrindingHalt)
void __cdecl BringCarToAGrindingHalt(tCollision_info *car) {
    LOG_TRACE("(%p)", car);

    (void)car;

    if (function_hook_state_BringCarToAGrindingHalt == HOOK_ENABLED) {
        assert(0 && "BringCarToAGrindingHalt not implemented.");
        abort();
    } else {
        original_BringCarToAGrindingHalt(car);
    }
}

function_hook_state_t function_hook_state_BoundsOverlapTest__car = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_BoundsOverlapTest__car)
int BoundsOverlapTest__car(br_bounds *b1, br_bounds *b2) {
    LOG_TRACE("(%p, %p)", b1, b2);

    (void)b1;
    (void)b2;

    if (function_hook_state_BoundsOverlapTest__car == HOOK_ENABLED) {
        assert(0 && "BoundsOverlapTest__car not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}

function_hook_state_t function_hook_state_SimpleCarCarCollisionTest = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_SimpleCarCarCollisionTest)
static int(__cdecl*original_SimpleCarCarCollisionTest)(tCollision_info *, tCollision_info *) = (int(__cdecl*)(tCollision_info *, tCollision_info *))0x0048d28f;
CARM95_HOOK_FUNCTION(original_SimpleCarCarCollisionTest, SimpleCarCarCollisionTest)
int __cdecl SimpleCarCarCollisionTest(tCollision_info *car1, tCollision_info *car2) {
    LOG_TRACE("(%p, %p)", car1, car2);

    (void)car1;
    (void)car2;

    if (function_hook_state_SimpleCarCarCollisionTest == HOOK_ENABLED) {
        assert(0 && "SimpleCarCarCollisionTest not implemented.");
        abort();
    } else {
        return original_SimpleCarCarCollisionTest(car1, car2);
    }
}

function_hook_state_t function_hook_state_CollideTwoCarsWithWalls = HOOK_UNAVAILABLE;
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
        assert(0 && "CollideTwoCarsWithWalls not implemented.");
        abort();
    } else {
        return original_CollideTwoCarsWithWalls(car1, car2, dt);
    }
}

function_hook_state_t function_hook_state_CollideTwoCarsRepeatedly = HOOK_UNAVAILABLE;
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
        assert(0 && "CollideTwoCarsRepeatedly not implemented.");
        abort();
    } else {
        return original_CollideTwoCarsRepeatedly(car1, car2, dt);
    }
}

function_hook_state_t function_hook_state_CollideTwoCars = HOOK_UNAVAILABLE;
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
        assert(0 && "CollideTwoCars not implemented.");
        abort();
    } else {
        return original_CollideTwoCars(car1, car2, pPass);
    }
}

function_hook_state_t function_hook_state_GetEdgeEdgeCollisions = HOOK_UNAVAILABLE;
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
        assert(0 && "GetEdgeEdgeCollisions not implemented.");
        abort();
    } else {
        return original_GetEdgeEdgeCollisions(pB1, pB2, pM21, pM12, pMo21, pMo12, pM1o1, pPoint_list, pNorm_list, pMax);
    }
}

function_hook_state_t function_hook_state_FacePointCarCarCollide = HOOK_UNAVAILABLE;
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
        assert(0 && "FacePointCarCarCollide not implemented.");
        abort();
    } else {
        return original_FacePointCarCarCollide(car1, car2, pMms, pMoms, pMsos, pPoint_list, pNorm_list, pMax, order);
    }
}

function_hook_state_t function_hook_state_MungeCarsMass = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_MungeCarsMass)
static void(__cdecl*original_MungeCarsMass)(tCollision_info *, br_scalar) = (void(__cdecl*)(tCollision_info *, br_scalar))0x0048fc1c;
CARM95_HOOK_FUNCTION(original_MungeCarsMass, MungeCarsMass)
void __cdecl MungeCarsMass(tCollision_info *pCar, br_scalar pFactor) {
    LOG_TRACE("(%p, %f)", pCar, pFactor);

    (void)pCar;
    (void)pFactor;

    if (function_hook_state_MungeCarsMass == HOOK_ENABLED) {
        assert(0 && "MungeCarsMass not implemented.");
        abort();
    } else {
        original_MungeCarsMass(pCar, pFactor);
    }
}

function_hook_state_t function_hook_state_ModifyCarsMass = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_ModifyCarsMass)
static void(__cdecl*original_ModifyCarsMass)(tCollision_info *, tCollision_info *) = (void(__cdecl*)(tCollision_info *, tCollision_info *))0x0048fb97;
CARM95_HOOK_FUNCTION(original_ModifyCarsMass, ModifyCarsMass)
void __cdecl ModifyCarsMass(tCollision_info *pCar_1, tCollision_info *pCar_2) {
    LOG_TRACE("(%p, %p)", pCar_1, pCar_2);

    (void)pCar_1;
    (void)pCar_2;

    if (function_hook_state_ModifyCarsMass == HOOK_ENABLED) {
        assert(0 && "ModifyCarsMass not implemented.");
        abort();
    } else {
        original_ModifyCarsMass(pCar_1, pCar_2);
    }
}

function_hook_state_t function_hook_state_ResetCarsMass = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_ResetCarsMass)
static void(__cdecl*original_ResetCarsMass)(tCollision_info *, tCollision_info *) = (void(__cdecl*)(tCollision_info *, tCollision_info *))0x0048fc7b;
CARM95_HOOK_FUNCTION(original_ResetCarsMass, ResetCarsMass)
void __cdecl ResetCarsMass(tCollision_info *pCar_1, tCollision_info *pCar_2) {
    LOG_TRACE("(%p, %p)", pCar_1, pCar_2);

    (void)pCar_1;
    (void)pCar_2;

    if (function_hook_state_ResetCarsMass == HOOK_ENABLED) {
        assert(0 && "ResetCarsMass not implemented.");
        abort();
    } else {
        original_ResetCarsMass(pCar_1, pCar_2);
    }
}

function_hook_state_t function_hook_state_DoCollide = HOOK_UNAVAILABLE;
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
        assert(0 && "DoCollide not implemented.");
        abort();
    } else {
        return original_DoCollide(car1, car2, r, n, k, pPass, mat1_to_mat2);
    }
}

function_hook_state_t function_hook_state_TwoPointCollB = HOOK_UNAVAILABLE;
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
        assert(0 && "TwoPointCollB not implemented.");
        abort();
    } else {
        return original_TwoPointCollB(f, m, d, tau, n);
    }
}

function_hook_state_t function_hook_state_ThreePointCollRecB = HOOK_UNAVAILABLE;
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
        assert(0 && "ThreePointCollRecB not implemented.");
        abort();
    } else {
        return original_ThreePointCollRecB(f, m, d, tau, n);
    }
}

function_hook_state_t function_hook_state_FourPointCollB = HOOK_UNAVAILABLE;
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
        assert(0 && "FourPointCollB not implemented.");
        abort();
    } else {
        return original_FourPointCollB(f, m, d, tau, n);
    }
}

function_hook_state_t function_hook_state_TestForNan = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_TestForNan)
static int(__cdecl*original_TestForNan)(float *) = (int(__cdecl*)(float *))0x00492ff8;
CARM95_HOOK_FUNCTION(original_TestForNan, TestForNan)
int __cdecl TestForNan(float *f) {
    tU32 i;
    LOG_TRACE("(%p)", f);

    (void)f;
    (void)i;

    if (function_hook_state_TestForNan == HOOK_ENABLED) {
        assert(0 && "TestForNan not implemented.");
        abort();
    } else {
        return original_TestForNan(f);
    }
}

function_hook_state_t function_hook_state_CheckCameraHither = HOOK_UNAVAILABLE;
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
        assert(0 && "CheckCameraHither not implemented.");
        abort();
    } else {
        original_CheckCameraHither();
    }
}

function_hook_state_t function_hook_state_SetCarSuspGiveAndHeight = HOOK_UNAVAILABLE;
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
        assert(0 && "SetCarSuspGiveAndHeight not implemented.");
        abort();
    } else {
        original_SetCarSuspGiveAndHeight(pCar, pFront_give_factor, pRear_give_factor, pDamping_factor, pExtra_front_height, pExtra_rear_height);
    }
}

function_hook_state_t function_hook_state_TestForCarInSensiblePlace = HOOK_UNAVAILABLE;
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
        assert(0 && "TestForCarInSensiblePlace not implemented.");
        abort();
    } else {
        return original_TestForCarInSensiblePlace(car);
    }
}

function_hook_state_t function_hook_state_TestOldMats = HOOK_UNAVAILABLE;
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
        assert(0 && "TestOldMats not implemented.");
        abort();
    } else {
        return original_TestOldMats(c1, c2, newmats);
    }
}

function_hook_state_t function_hook_state_PullActorFromWorld = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_PullActorFromWorld)
static int(__cdecl*original_PullActorFromWorld)(br_actor *) = (int(__cdecl*)(br_actor *))0x0049393a;
CARM95_HOOK_FUNCTION(original_PullActorFromWorld, PullActorFromWorld)
int __cdecl PullActorFromWorld(br_actor *pActor) {
    LOG_TRACE("(%p)", pActor);

    (void)pActor;

    if (function_hook_state_PullActorFromWorld == HOOK_ENABLED) {
        assert(0 && "PullActorFromWorld not implemented.");
        abort();
    } else {
        return original_PullActorFromWorld(pActor);
    }
}

function_hook_state_t function_hook_state_DoPullActorFromWorld = HOOK_UNAVAILABLE;
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
        assert(0 && "DoPullActorFromWorld not implemented.");
        abort();
    } else {
        return original_DoPullActorFromWorld(pActor);
    }
}

function_hook_state_t function_hook_state_CheckForDeAttachmentOfNonCars = HOOK_UNAVAILABLE;
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
        assert(0 && "CheckForDeAttachmentOfNonCars not implemented.");
        abort();
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

function_hook_state_t function_hook_state_GetPrecalculatedFacesUnderCar = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_GetPrecalculatedFacesUnderCar)
static int(__cdecl*original_GetPrecalculatedFacesUnderCar)(tCar_spec *, tFace_ref **) = (int(__cdecl*)(tCar_spec *, tFace_ref **))0x004941a2;
CARM95_HOOK_FUNCTION(original_GetPrecalculatedFacesUnderCar, GetPrecalculatedFacesUnderCar)
int __cdecl GetPrecalculatedFacesUnderCar(tCar_spec *pCar, tFace_ref **pFace_refs) {
    LOG_TRACE("(%p, %p)", pCar, pFace_refs);

    (void)pCar;
    (void)pFace_refs;

    if (function_hook_state_GetPrecalculatedFacesUnderCar == HOOK_ENABLED) {
        assert(0 && "GetPrecalculatedFacesUnderCar not implemented.");
        abort();
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

