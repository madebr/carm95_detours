#ifndef _GLOBVRKM_H_
#define _GLOBVRKM_H_

#include "br_types.h"
#include "dr_types.h"

extern br_scalar * hookvar_gCamera_zoom ; // addr: 0050D380
extern br_angle * hookvar_gCamera_yaw ; // addr: 0050D384
extern br_vector3 * hookvar_gView_direction ; // addr: 0050D388
extern int * hookvar_gCamera_sign ; // addr: 0050D394
extern int * hookvar_gCar_flying ; // addr: 0050D398
extern int * hookvar_gCamera_reset ; // addr: 0050D39C
extern tCar_spec ** hookvar_gCar_to_view ; // addr: 0050D3A0
extern br_actor *(* hookvar_gCamera_list )[2]; // addr: 00551438
extern tCar_spec *(* hookvar_gActive_car_list )[25]; // addr: 00551450
extern int * hookvar_gNum_active_cars ; // addr: 005514CC
extern float(* hookvar_gRecovery_cost )[3]; // addr: 005514C0
extern br_scalar * hookvar_gCamera_height ; // addr: 005514D0
extern br_scalar * hookvar_gMin_camera_car_distance ; // addr: 00551440

#endif
