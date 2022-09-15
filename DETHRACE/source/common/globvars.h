#ifndef _GLOBVARS_H_
#define _GLOBVARS_H_

#include "br_types.h"
#include "dr_types.h"

extern int * hookvar_gTyping ; // addr: 005212F0
extern int * hookvar_gArrow_mode ; // addr: 005212F4
extern int * hookvar_gInfo_on ; // addr: 005212F8
extern int * hookvar_gHost_abandon_game ; // addr: 005212FC
extern int * hookvar_gRecover_car ; // addr: 00521300
extern int * hookvar_gDisallow_abandon_race ; // addr: 00521304
// extern int * hookvar_gPipe_reg_snap_before_new_game ;
// extern int * hookvar_gPipe_reg_snap_before_our_car ;
// extern int * hookvar_gPipe_reg_snap_after_our_car ;
extern int * hookvar_gAction_replay_mode ; // addr: 00521314
extern int * hookvar_gDefault_engine_noise_index ; // addr: 00521318
extern int * hookvar_gAusterity_mode ; // addr: 0052131C
// extern int * hookvar_gSausage_override ;
extern int * hookvar_gAustere_override ; // addr: 00521324
// extern int * hookvar_gSound_override ;
extern int * hookvar_gKey_map_index ; // addr: 0052132C
extern int * hookvar_gInterface_within_race_mode ; // addr: 00521330
// extern int * hookvar_gCut_scene_override ;
extern int * hookvar_gGame_to_load ; // addr: 00521338
extern int * hookvar_gCD_is_in_drive ; // addr: 0052133C
extern br_pixelmap ** hookvar_gRearview_screen ; // addr: 00521340
extern br_scalar * hookvar_gCut_delay_1 ; // addr: 00521344
extern br_scalar * hookvar_gCut_delay_2 ; // addr: 00521348
extern br_scalar * hookvar_gCut_delay_3 ; // addr: 0052134C
extern br_scalar * hookvar_gCut_delay_4 ; // addr: 00521350
extern br_scalar * hookvar_gYon_multiplier ; // addr: 00521354
extern tSave_game ** hookvar_gPre_race_saved_game ; // addr: 00521358
// extern FILE ** hookvar_gDiagnostic_file ;
// extern br_vector3 * hookvar_gDisabled_vector ;
extern tU32 * hookvar_gI_am_cheating ; // addr: 0052136C
extern char(* hookvar_gNet_player_name )[32]; // addr: 0054B220
extern br_matrix34 * hookvar_gRearview_camera_to_world ; // addr: 00545440
extern tSpecial_volume * hookvar_gDefault_default_water_spec_vol ; // addr: 00549EB0
extern br_matrix34 * hookvar_gCamera_to_world ; // addr: 00545400
extern tRace_list_spec(* hookvar_gRace_list )[100]; // addr: 005454D0
extern tPath_name * hookvar_gApplication_path ; // addr: 00546820
extern float * hookvar_gPinball_factor ; // addr: 0054A068
extern float * hookvar_gOpponent_speed_factor ; // addr: 0054A064
extern float * hookvar_gCar_crush_min_fold ; // addr: 0054B250
extern float(* hookvar_gNet_recovery_cost )[7]; // addr: 00549FC0
extern float * hookvar_gCar_crush_softness ; // addr: 00545474
extern br_vector3 ** hookvar_gOur_pos ; // addr: 0054B248
extern float * hookvar_gCar_crush_max_fold ; // addr: 00545368
extern tBrender_storage * hookvar_gNet_cars_storage_space ; // addr: 0054A020
extern float(* hookvar_gNet_softness )[7]; // addr: 00545380
// extern tS32 * hookvar_gJoystick_deadzone ;
extern float * hookvar_gCar_crush_limit_deviant ; // addr: 0054B270
extern float(* hookvar_gNet_offensive )[7]; // addr: 005452E0
extern float * hookvar_gCar_crush_split_chance ; // addr: 00545470
extern float * hookvar_gGravity_multiplier ; // addr: 0054532C
extern float * hookvar_gCar_crush_wibble ; // addr: 00545364
extern float(* hookvar_gRepair_cost )[3]; // addr: 00549FE0
extern float * hookvar_gCop_speed_factor ; // addr: 005454C0
extern float * hookvar_gDefault_gravity ; // addr: 0054535C
extern tU32 * hookvar_gKeys_pressed ; // addr: 00545334
extern tSpecial_volume ** hookvar_gDefault_water_spec_vol ; // addr: 0054A054
extern float(* hookvar_gNet_repair_cost )[7]; // addr: 00549F60
extern br_font ** hookvar_gFont_7 ; // addr: 0054537C
extern tU32 * hookvar_gLast_replay_frame_time ; // addr: 0054A00C
extern tU32 * hookvar_gTag_start_time ; // addr: 005453F8
extern tOpponent ** hookvar_gOpponents ; // addr: 0054B254
// extern tU32 * hookvar_gLast_credit_tick ;
extern tBrender_storage * hookvar_gTheir_cars_storage_space ; // addr: 00549F80
extern br_font ** hookvar_gHeadup_font ; // addr: 005452FC
extern tU32 * hookvar_gRace_finished ; // addr: 005454B8
// extern tU32 * hookvar_gFrame_start_time ;
extern tProgram_state * hookvar_gProgram_state ; // addr: 00546930
extern tU32(* hookvar_gCredit_period_single )[3]; // addr: 00545370
extern tU32 * hookvar_gRace_start ; // addr: 0054B240
extern tBrender_storage * hookvar_gTrack_storage_space ; // addr: 005453C0
extern tU32 * hookvar_gFrame_period ; // addr: 005453B0
extern tU32 * hookvar_gCredit_period ; // addr: 005467AC
extern tU32(* hookvar_gCredit_period_network )[7]; // addr: 00545300
extern tBrender_storage * hookvar_gOur_car_storage_space ; // addr: 005467C0
extern tU32 * hookvar_gFox_start_time ; // addr: 0054531C
extern br_font ** hookvar_gBig_font ; // addr: 00546810
extern tBrender_storage * hookvar_gPedestrians_storage_space ; // addr: 00545480
extern tRace_info * hookvar_gCurrent_race ; // addr: 0054A0A0
extern br_actor ** hookvar_gSelf ; // addr: 0054B26C
extern br_actor ** hookvar_gDont_render_actor ; // addr: 00549FB4
extern br_pixelmap ** hookvar_gScreen ; // addr: 005453AC
extern br_pixelmap ** hookvar_gRender_screen ; // addr: 0054A06C
extern br_actor ** hookvar_gRearview_camera ; // addr: 005467B4
extern br_scalar * hookvar_gCamera_hither ; // addr: 005453B4
extern br_pixelmap ** hookvar_gBack_screen ; // addr: 00545340
extern br_scalar * hookvar_gCamera_angle ; // addr: 00545338
extern br_pixelmap ** hookvar_gDigits_pix ; // addr: 00546798
extern br_pixelmap ** hookvar_gRender_shade_table ; // addr: 005454B4
extern br_pixelmap ** hookvar_gRearview_depth_buffer ; // addr: 005467B0
// extern br_pixelmap ** hookvar_gWhole_screen ;
extern br_pixelmap ** hookvar_gIcons_pix ; // addr: 0054A058
extern br_scalar * hookvar_gCamera_yon ; // addr: 0054A060
extern br_actor ** hookvar_gCamera ; // addr: 0054533C
extern br_actor ** hookvar_gArrow_actor ; // addr: 00545360
// extern br_pixelmap ** hookvar_gIcons_pix_low_res ;
extern br_pixelmap ** hookvar_gDepth_buffer ; // addr: 00545324
extern int(* hookvar_gInitial_net_credits )[5]; // addr: 0054A080
extern float(* hookvar_gCar_cred_value )[3]; // addr: 005467A0
extern int * hookvar_gNo_races_yet ; // addr: 00545430
extern int(* hookvar_gJump_start_fine )[3]; // addr: 005453A0
extern int * hookvar_gReal_graf_data_index ; // addr: 005454BC
extern float(* hookvar_gCar_time_value )[3]; // addr: 00549FF0
extern int * hookvar_gTyping_slot ; // addr: 0054679C
extern int(* hookvar_gCunning_stunt_bonus )[3]; // addr: 0054B260
extern int * hookvar_gKnobbled_frame_period ; // addr: 0054B258
extern br_actor ** hookvar_gNon_track_actor ; // addr: 0054B24C
extern int * hookvar_gWait_for_it ; // addr: 00546790
extern int(* hookvar_gCheck_point_cash )[3]; // addr: 0054A070
extern int(* hookvar_gPoints_per_second )[3]; // addr: 0054A010
extern br_actor ** hookvar_gUniverse_actor ; // addr: 005453FC
extern br_actor ** hookvar_gTrack_actor ; // addr: 00546920
extern int * hookvar_gMap_mode ; // addr: 005467F4
extern int(* hookvar_gPed_time_value )[3]; // addr: 0054B290
extern int * hookvar_gAbandon_game ; // addr: 00545328
extern int * hookvar_gLap ; // addr: 005467B8
extern int * hookvar_gShow_opponents ; // addr: 0054B274
extern int * hookvar_gTotal_laps ; // addr: 0054680C
extern int * hookvar_gFree_repairs ; // addr: 00546794
extern int * hookvar_gFreeze_timer ; // addr: 00546924
extern int(* hookvar_gRoll_over_creds )[3]; // addr: 00549EA0
extern int * hookvar_gShow_peds_on_map ; // addr: 00545320
extern int * hookvar_gOn_drugs ; // addr: 005453F4
extern int(* hookvar_gWasted_time )[3]; // addr: 0054B280
extern int * hookvar_gCheckpoint ; // addr: 0054A008
extern int(* hookvar_gRoll_over_time )[3]; // addr: 00546800
extern int(* hookvar_gWasted_creds )[3]; // addr: 00545350
extern int * hookvar_gTimer ; // addr: 0054A004
extern int * hookvar_gCheckpoint_count ; // addr: 00549FB8
extern int * hookvar_gCountdown ; // addr: 0054A05C
extern int * hookvar_gFrame_rate ; // addr: 00549FFC
extern int * hookvar_gNumber_of_racers ; // addr: 00545330
extern int * hookvar_gSound_enabled ; // addr: 0054A09C
extern int * hookvar_gGraf_spec_index ; // addr: 0054A098
extern int * hookvar_gSound_available ; // addr: 0054A000
extern int * hookvar_gNumber_of_races ; // addr: 00545434
extern char(* hookvar_gDir_separator )[3]; // addr: 00549EAC

#endif
