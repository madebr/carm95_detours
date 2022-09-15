#ifndef _GLOBVRPB_H_
#define _GLOBVRPB_H_

#include "br_types.h"
#include "dr_types.h"

extern tNet_mode * hookvar_gNet_mode ; // addr: 0050DD94
extern tNet_game_player_info(* hookvar_gNet_players )[6]; // addr: 00550FA0
// extern br_matrix34 * hookvar_gRoot_to_camera ;
extern tCar_detail_info(* hookvar_gCar_details )[60]; // addr: 00550AF0
extern int * hookvar_gThis_net_player_index ; // addr: 00550AE0
// extern br_scalar * hookvar_gPedestrian_distance_squared ;
extern int * hookvar_gPending_race ; // addr: 00551434
extern tPlayer_ID * hookvar_gLocal_net_ID ; // addr: 00550AEC
extern int * hookvar_gNumber_of_net_players ; // addr: 00550AE4
extern int * hookvar_gStart_race_sent ; // addr: 00550AD8
extern int * hookvar_gSynch_race_start ; // addr: 00551424
extern tNet_game_details ** hookvar_gCurrent_net_game ; // addr: 00550ADC
extern int * hookvar_gReceived_car_details ; // addr: 00550AD4
extern int * hookvar_gWaiting_for_unpause ; // addr: 00550AE8
extern tNet_game_options ** hookvar_gNet_options ; // addr: 00551428
// extern br_vector3 * hookvar_gCamera_direction ;
// extern int * hookvar_gNetwork_available ;
// extern int * hookvar_gPedestrian_image ;
// extern int * hookvar_gHighest_pedestrian_value ;
// extern int * hookvar_gNeed_to_send_start_race ;
extern int * hookvar_gRendering_mirror ; // addr: 00550AD0

#endif
