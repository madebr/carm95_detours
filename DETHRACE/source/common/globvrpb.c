#include "globvrpb.h"

#include "harness/trace.h"

#include "carm95_hooks.h"

#include "carm95_webserver.h"

#include <assert.h>
tNet_mode * hookvar_gNet_mode  = (void*)0x0050dd94;
tNet_game_player_info(* hookvar_gNet_players )[6] = (void*)0x00550fa0;
#if 0
br_matrix34 * hookvar_gRoot_to_camera ;
#endif
tCar_detail_info(* hookvar_gCar_details )[60] = (void*)0x00550af0;
int * hookvar_gThis_net_player_index  = (void*)0x00550ae0;
#if 0
br_scalar * hookvar_gPedestrian_distance_squared ;
#endif
int * hookvar_gPending_race  = (void*)0x00551434;
tPlayer_ID * hookvar_gLocal_net_ID  = (void*)0x00550aec;
int * hookvar_gNumber_of_net_players  = (void*)0x00550ae4;
int * hookvar_gStart_race_sent  = (void*)0x00550ad8;
int * hookvar_gSynch_race_start  = (void*)0x00551424;
tNet_game_details ** hookvar_gCurrent_net_game  = (void*)0x00550adc;
int * hookvar_gReceived_car_details  = (void*)0x00550ad4;
int * hookvar_gWaiting_for_unpause  = (void*)0x00550ae8;
tNet_game_options ** hookvar_gNet_options  = (void*)0x00551428;
#if 0
br_vector3 * hookvar_gCamera_direction ;
#endif
#if 0
int * hookvar_gNetwork_available ;
#endif
#if 0
int * hookvar_gPedestrian_image ;
#endif
#if 0
int * hookvar_gHighest_pedestrian_value ;
#endif
#if 0
int * hookvar_gNeed_to_send_start_race ;
#endif
int * hookvar_gRendering_mirror  = (void*)0x00550ad0;

