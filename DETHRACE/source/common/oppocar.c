#include "oppocar.h"

#include "harness/trace.h"

#include "carm95_hooks.h"

#include "carm95_webserver.h"

#include <assert.h>
 // Suffix added to avoid duplicate symbol
#if 0
int * hookvar_gCollision_detection_on__oppocar ;
#endif
 // Suffix added to avoid duplicate symbol
#if 0
br_vector3 * hookvar_gGround_normal__oppocar ;
#endif
 // Suffix added to avoid duplicate symbol
#if 0
void(**(* hookvar_ControlCar__oppocar )[6])(tCar_spec *, br_scalar);
#endif
 // Suffix added to avoid duplicate symbol
#if 0
int * hookvar_gControl__oppocar ;
#endif
 // Suffix added to avoid duplicate symbol
#if 0
int * hookvar_gFace_num__oppocar ;
#endif
 // Suffix added to avoid duplicate symbol
#if 0
br_angle * hookvar_gOld_yaw__oppocar ;
#endif
 // Suffix added to avoid duplicate symbol
#if 0
int(* hookvar_gMetal_crunch_sound_id__oppocar )[5];
#endif
 // Suffix added to avoid duplicate symbol
#if 0
int(* hookvar_gMetal_scrape_sound_id__oppocar )[3];
#endif
 // Suffix added to avoid duplicate symbol
#if 0
tFace_ref(* hookvar_gFace_list__oppocar )[32];
#endif
 // Suffix added to avoid duplicate symbol
#if 0
br_scalar * hookvar_gOur_yaw__oppocar ;
#endif
 // Suffix added to avoid duplicate symbol
#if 0
br_scalar * hookvar_gGravity__oppocar ;
#endif
 // Suffix added to avoid duplicate symbol
#if 0
br_vector3 * hookvar_gNew_ground_normal__oppocar ;
#endif

function_hook_state_t function_hook_state_MakeCarStationary = HOOK_UNAVAILABLE;
void MakeCarStationary(tCar_spec *pCar_spec) {
    LOG_TRACE("(%p)", pCar_spec);

    (void)pCar_spec;

    if (function_hook_state_MakeCarStationary == HOOK_ENABLED) {
        assert(0 && "MakeCarStationary not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}

function_hook_state_t function_hook_state_MoveThisCar = HOOK_UNAVAILABLE;
void MoveThisCar(tU32 pTime_difference, tCar_spec *car) {
    br_scalar dt;
    br_scalar ts;
    br_vector3 r;
    br_vector3 minus_k;
    int i;
    int j;
    br_angle phi;
    br_scalar __block0___scale;
    LOG_TRACE("(%u, %p)", pTime_difference, car);

    (void)pTime_difference;
    (void)car;
    (void)dt;
    (void)ts;
    (void)r;
    (void)minus_k;
    (void)i;
    (void)j;
    (void)phi;
    (void)__block0___scale;

    if (function_hook_state_MoveThisCar == HOOK_ENABLED) {
        assert(0 && "MoveThisCar not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}

