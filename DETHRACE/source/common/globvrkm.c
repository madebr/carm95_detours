#include "globvrkm.h"

#include "harness/trace.h"

#include "carm95_hooks.h"

br_scalar * hookvar_gCamera_zoom  = (void*)0x0050d380;
br_angle * hookvar_gCamera_yaw  = (void*)0x0050d384;
br_vector3 * hookvar_gView_direction  = (void*)0x0050d388;
int * hookvar_gCamera_sign  = (void*)0x0050d394;
int * hookvar_gCar_flying  = (void*)0x0050d398;
int * hookvar_gCamera_reset  = (void*)0x0050d39c;
tCar_spec ** hookvar_gCar_to_view  = (void*)0x0050d3a0;
br_actor *(* hookvar_gCamera_list )[2] = (void*)0x00551438;
tCar_spec *(* hookvar_gActive_car_list )[25] = (void*)0x00551450;
int * hookvar_gNum_active_cars  = (void*)0x005514cc;
float(* hookvar_gRecovery_cost )[3] = (void*)0x005514c0;
br_scalar * hookvar_gCamera_height  = (void*)0x005514d0;
br_scalar * hookvar_gMin_camera_car_distance  = (void*)0x00551440;

