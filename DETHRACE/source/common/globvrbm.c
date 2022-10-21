#include "globvrbm.h"

#include "harness/trace.h"

#include "carm95_hooks.h"

#include "carm95_webserver.h"

#include <assert.h>
br_scalar * hookvar_gYon_factor  = (void*)0x00520038;
br_material *(* hookvar_gMaterial )[2] = (void*)0x00530c80;
#if 0
int * hookvar_g16bit_palette_valid ;
#endif
#if 0
tException_list * hookvar_gExceptions ;
#endif
#if 0
br_actor ** hookvar_g2d_camera ;
#endif
#if 0
int * hookvar_gAlready_copied ;
#endif
#if 0
br_actor ** hookvar_gBlend_actor ;
#endif
#if 0
br_actor ** hookvar_gLine_actor ;
#endif
#if 0
br_model ** hookvar_gBlend_model ;
#endif
#if 0
br_model ** hookvar_gPrat_model ;
#endif
#if 0
char ** hookvar_gExceptions_general_file ;
#endif
#if 0
br_model ** hookvar_gDim_model ;
#endif
#if 0
br_material ** hookvar_gPrat_material ;
#endif
#if 0
br_material ** hookvar_gBlend_material ;
#endif
#if 0
char ** hookvar_gExceptions_file_suffix ;
#endif
#if 0
br_material ** hookvar_gDim_material ;
#endif
#if 0
br_actor ** hookvar_gPrat_actor ;
#endif
#if 0
br_material ** hookvar_gLine_material ;
#endif
#if 0
br_model ** hookvar_gLine_model ;
#endif
#if 0
br_actor ** hookvar_gDim_actor ;
#endif
#if 0
int * hookvar_gNo_transients ;
#endif
#if 0
int * hookvar_gSmall_frames_are_slow ;
#endif
#if 0
int * hookvar_gShade_tables_do_not_work ;
#endif
#if 0
int * hookvar_gInterpolate_textures ;
#endif
#if 0
int * hookvar_gNo_2d_effects ;
#endif
#if 0
int * hookvar_gPerspective_is_fast ;
#endif
#if 0
int * hookvar_gUse_mip_maps ;
#endif
#if 0
int * hookvar_gBlitting_is_slow ;
#endif
#if 0
int * hookvar_gTextures_need_powers_of_2 ;
#endif
#if 0
int * hookvar_gMax_texture_side ;
#endif
#if 0
int * hookvar_gDevious_2d ;
#endif
#if 0
int * hookvar_gMax_texture_aspect_ratio ;
#endif
#if 0
int * hookvar_gMaterial_fogging ;
#endif

