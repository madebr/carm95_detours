#ifndef _OPPOCAR_H_
#define _OPPOCAR_H_

#include "br_types.h"
#include "dr_types.h"

// extern int * hookvar_gCollision_detection_on__oppocar ; // suffix added to avoid duplicate symbol
// extern br_vector3 * hookvar_gGround_normal__oppocar ; // suffix added to avoid duplicate symbol
// extern void(**(* hookvar_ControlCar__oppocar )[6])(tCar_spec *, br_scalar, ...); // suffix added to avoid duplicate symbol
// extern int * hookvar_gControl__oppocar ; // suffix added to avoid duplicate symbol
// extern int * hookvar_gFace_num__oppocar ; // suffix added to avoid duplicate symbol
// extern br_angle * hookvar_gOld_yaw__oppocar ; // suffix added to avoid duplicate symbol
// extern int(* hookvar_gMetal_crunch_sound_id__oppocar )[5]; // suffix added to avoid duplicate symbol
// extern int(* hookvar_gMetal_scrape_sound_id__oppocar )[3]; // suffix added to avoid duplicate symbol
// extern tFace_ref(* hookvar_gFace_list__oppocar )[32]; // suffix added to avoid duplicate symbol
// extern br_scalar * hookvar_gOur_yaw__oppocar ; // suffix added to avoid duplicate symbol
// extern br_scalar * hookvar_gGravity__oppocar ; // suffix added to avoid duplicate symbol
// extern br_vector3 * hookvar_gNew_ground_normal__oppocar ; // suffix added to avoid duplicate symbol

void MakeCarStationary(tCar_spec *pCar_spec);

void MoveThisCar(tU32 pTime_difference, tCar_spec *car);

#endif
