#include "globvars.h"

#include "harness/trace.h"

#include "carm95_hooks.h"

int * hookvar_gTyping  = (void*)0x005212f0;
int * hookvar_gArrow_mode  = (void*)0x005212f4;
int * hookvar_gInfo_on  = (void*)0x005212f8;
int * hookvar_gHost_abandon_game  = (void*)0x005212fc;
int * hookvar_gRecover_car  = (void*)0x00521300;
int * hookvar_gDisallow_abandon_race  = (void*)0x00521304;
#if 0
int * hookvar_gPipe_reg_snap_before_new_game ;
#endif
#if 0
int * hookvar_gPipe_reg_snap_before_our_car ;
#endif
#if 0
int * hookvar_gPipe_reg_snap_after_our_car ;
#endif
int * hookvar_gAction_replay_mode  = (void*)0x00521314;
int * hookvar_gDefault_engine_noise_index  = (void*)0x00521318;
int * hookvar_gAusterity_mode  = (void*)0x0052131c;
#if 0
int * hookvar_gSausage_override ;
#endif
int * hookvar_gAustere_override  = (void*)0x00521324;
#if 0
int * hookvar_gSound_override ;
#endif
int * hookvar_gKey_map_index  = (void*)0x0052132c;
int * hookvar_gInterface_within_race_mode  = (void*)0x00521330;
#if 0
int * hookvar_gCut_scene_override ;
#endif
int * hookvar_gGame_to_load  = (void*)0x00521338;
int * hookvar_gCD_is_in_drive  = (void*)0x0052133c;
br_pixelmap ** hookvar_gRearview_screen  = (void*)0x00521340;
br_scalar * hookvar_gCut_delay_1  = (void*)0x00521344;
br_scalar * hookvar_gCut_delay_2  = (void*)0x00521348;
br_scalar * hookvar_gCut_delay_3  = (void*)0x0052134c;
br_scalar * hookvar_gCut_delay_4  = (void*)0x00521350;
br_scalar * hookvar_gYon_multiplier  = (void*)0x00521354;
tSave_game ** hookvar_gPre_race_saved_game  = (void*)0x00521358;
#if 0
FILE ** hookvar_gDiagnostic_file ;
#endif
#if 0
br_vector3 * hookvar_gDisabled_vector ;
#endif
tU32 * hookvar_gI_am_cheating  = (void*)0x0052136c;
char(* hookvar_gNet_player_name )[32] = (void*)0x0054b220;
br_matrix34 * hookvar_gRearview_camera_to_world  = (void*)0x00545440;
tSpecial_volume * hookvar_gDefault_default_water_spec_vol  = (void*)0x00549eb0;
br_matrix34 * hookvar_gCamera_to_world  = (void*)0x00545400;
tRace_list_spec(* hookvar_gRace_list )[100] = (void*)0x005454d0;
tPath_name * hookvar_gApplication_path  = (void*)0x00546820;
float * hookvar_gPinball_factor  = (void*)0x0054a068;
float * hookvar_gOpponent_speed_factor  = (void*)0x0054a064;
float * hookvar_gCar_crush_min_fold  = (void*)0x0054b250;
float(* hookvar_gNet_recovery_cost )[7] = (void*)0x00549fc0;
float * hookvar_gCar_crush_softness  = (void*)0x00545474;
br_vector3 ** hookvar_gOur_pos  = (void*)0x0054b248;
float * hookvar_gCar_crush_max_fold  = (void*)0x00545368;
tBrender_storage * hookvar_gNet_cars_storage_space  = (void*)0x0054a020;
float(* hookvar_gNet_softness )[7] = (void*)0x00545380;
#if 0
tS32 * hookvar_gJoystick_deadzone ;
#endif
float * hookvar_gCar_crush_limit_deviant  = (void*)0x0054b270;
float(* hookvar_gNet_offensive )[7] = (void*)0x005452e0;
float * hookvar_gCar_crush_split_chance  = (void*)0x00545470;
float * hookvar_gGravity_multiplier  = (void*)0x0054532c;
float * hookvar_gCar_crush_wibble  = (void*)0x00545364;
float(* hookvar_gRepair_cost )[3] = (void*)0x00549fe0;
float * hookvar_gCop_speed_factor  = (void*)0x005454c0;
float * hookvar_gDefault_gravity  = (void*)0x0054535c;
tU32 * hookvar_gKeys_pressed  = (void*)0x00545334;
tSpecial_volume ** hookvar_gDefault_water_spec_vol  = (void*)0x0054a054;
float(* hookvar_gNet_repair_cost )[7] = (void*)0x00549f60;
br_font ** hookvar_gFont_7  = (void*)0x0054537c;
tU32 * hookvar_gLast_replay_frame_time  = (void*)0x0054a00c;
tU32 * hookvar_gTag_start_time  = (void*)0x005453f8;
tOpponent ** hookvar_gOpponents  = (void*)0x0054b254;
#if 0
tU32 * hookvar_gLast_credit_tick ;
#endif
tBrender_storage * hookvar_gTheir_cars_storage_space  = (void*)0x00549f80;
br_font ** hookvar_gHeadup_font  = (void*)0x005452fc;
tU32 * hookvar_gRace_finished  = (void*)0x005454b8;
#if 0
tU32 * hookvar_gFrame_start_time ;
#endif
tProgram_state * hookvar_gProgram_state  = (void*)0x00546930;
tU32(* hookvar_gCredit_period_single )[3] = (void*)0x00545370;
tU32 * hookvar_gRace_start  = (void*)0x0054b240;
tBrender_storage * hookvar_gTrack_storage_space  = (void*)0x005453c0;
tU32 * hookvar_gFrame_period  = (void*)0x005453b0;
tU32 * hookvar_gCredit_period  = (void*)0x005467ac;
tU32(* hookvar_gCredit_period_network )[7] = (void*)0x00545300;
tBrender_storage * hookvar_gOur_car_storage_space  = (void*)0x005467c0;
tU32 * hookvar_gFox_start_time  = (void*)0x0054531c;
br_font ** hookvar_gBig_font  = (void*)0x00546810;
tBrender_storage * hookvar_gPedestrians_storage_space  = (void*)0x00545480;
tRace_info * hookvar_gCurrent_race  = (void*)0x0054a0a0;
br_actor ** hookvar_gSelf  = (void*)0x0054b26c;
br_actor ** hookvar_gDont_render_actor  = (void*)0x00549fb4;
br_pixelmap ** hookvar_gScreen  = (void*)0x005453ac;
br_pixelmap ** hookvar_gRender_screen  = (void*)0x0054a06c;
br_actor ** hookvar_gRearview_camera  = (void*)0x005467b4;
br_scalar * hookvar_gCamera_hither  = (void*)0x005453b4;
br_pixelmap ** hookvar_gBack_screen  = (void*)0x00545340;
br_scalar * hookvar_gCamera_angle  = (void*)0x00545338;
br_pixelmap ** hookvar_gDigits_pix  = (void*)0x00546798;
br_pixelmap ** hookvar_gRender_shade_table  = (void*)0x005454b4;
br_pixelmap ** hookvar_gRearview_depth_buffer  = (void*)0x005467b0;
#if 0
br_pixelmap ** hookvar_gWhole_screen ;
#endif
br_pixelmap ** hookvar_gIcons_pix  = (void*)0x0054a058;
br_scalar * hookvar_gCamera_yon  = (void*)0x0054a060;
br_actor ** hookvar_gCamera  = (void*)0x0054533c;
br_actor ** hookvar_gArrow_actor  = (void*)0x00545360;
#if 0
br_pixelmap ** hookvar_gIcons_pix_low_res ;
#endif
br_pixelmap ** hookvar_gDepth_buffer  = (void*)0x00545324;
int(* hookvar_gInitial_net_credits )[5] = (void*)0x0054a080;
float(* hookvar_gCar_cred_value )[3] = (void*)0x005467a0;
int * hookvar_gNo_races_yet  = (void*)0x00545430;
int(* hookvar_gJump_start_fine )[3] = (void*)0x005453a0;
int * hookvar_gReal_graf_data_index  = (void*)0x005454bc;
float(* hookvar_gCar_time_value )[3] = (void*)0x00549ff0;
int * hookvar_gTyping_slot  = (void*)0x0054679c;
int(* hookvar_gCunning_stunt_bonus )[3] = (void*)0x0054b260;
int * hookvar_gKnobbled_frame_period  = (void*)0x0054b258;
br_actor ** hookvar_gNon_track_actor  = (void*)0x0054b24c;
int * hookvar_gWait_for_it  = (void*)0x00546790;
int(* hookvar_gCheck_point_cash )[3] = (void*)0x0054a070;
int(* hookvar_gPoints_per_second )[3] = (void*)0x0054a010;
br_actor ** hookvar_gUniverse_actor  = (void*)0x005453fc;
br_actor ** hookvar_gTrack_actor  = (void*)0x00546920;
int * hookvar_gMap_mode  = (void*)0x005467f4;
int(* hookvar_gPed_time_value )[3] = (void*)0x0054b290;
int * hookvar_gAbandon_game  = (void*)0x00545328;
int * hookvar_gLap  = (void*)0x005467b8;
int * hookvar_gShow_opponents  = (void*)0x0054b274;
int * hookvar_gTotal_laps  = (void*)0x0054680c;
int * hookvar_gFree_repairs  = (void*)0x00546794;
int * hookvar_gFreeze_timer  = (void*)0x00546924;
int(* hookvar_gRoll_over_creds )[3] = (void*)0x00549ea0;
int * hookvar_gShow_peds_on_map  = (void*)0x00545320;
int * hookvar_gOn_drugs  = (void*)0x005453f4;
int(* hookvar_gWasted_time )[3] = (void*)0x0054b280;
int * hookvar_gCheckpoint  = (void*)0x0054a008;
int(* hookvar_gRoll_over_time )[3] = (void*)0x00546800;
int(* hookvar_gWasted_creds )[3] = (void*)0x00545350;
int * hookvar_gTimer  = (void*)0x0054a004;
int * hookvar_gCheckpoint_count  = (void*)0x00549fb8;
int * hookvar_gCountdown  = (void*)0x0054a05c;
int * hookvar_gFrame_rate  = (void*)0x00549ffc;
int * hookvar_gNumber_of_racers  = (void*)0x00545330;
int * hookvar_gSound_enabled  = (void*)0x0054a09c;
int * hookvar_gGraf_spec_index  = (void*)0x0054a098;
int * hookvar_gSound_available  = (void*)0x0054a000;
int * hookvar_gNumber_of_races  = (void*)0x00545434;
char(* hookvar_gDir_separator )[3] = (void*)0x00549eac;

