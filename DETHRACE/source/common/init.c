#include "init.h"

#include "harness/trace.h"

#include "carm95_hooks.h"

int * hookvar_gGame_initialized  = (void*)0x0052115c;
int * hookvar_gBr_initialized  = (void*)0x00521160;
int * hookvar_gBrZb_initialized  = (void*)0x00521164;
#if 0
int * hookvar_gInitialisation_finished ;
#endif
int * hookvar_gRender_indent  = (void*)0x0052116c;
tU32 * hookvar_gAustere_time  = (void*)0x0053fdd0;
int * hookvar_gInitial_rank  = (void*)0x0054b2bc;
int(* hookvar_gCredits_per_rank )[3] = (void*)0x0054b2b0;
#if 0
int(* hookvar_gInitial_credits )[3];
#endif
int * hookvar_gNet_mode_of_last_game  = (void*)0x0054b2a0;
br_material ** hookvar_gDefault_track_material  = (void*)0x0054b29c;

static void(__cdecl*original_AllocateSelf)() = (void(__cdecl*)())0x004bbebf;
CARM95_HOOK_FUNCTION(original_AllocateSelf, AllocateSelf)
void __cdecl AllocateSelf() {
    LOG_TRACE("()");


    original_AllocateSelf();
}

static void(__cdecl*original_AllocateCamera)() = (void(__cdecl*)())0x004bbf22;
CARM95_HOOK_FUNCTION(original_AllocateCamera, AllocateCamera)
void __cdecl AllocateCamera() {
    br_camera *camera_ptr;
    int i;
    LOG_TRACE("()");

    (void)camera_ptr;
    (void)i;

    original_AllocateCamera();
}

static void(__cdecl*original_ReinitialiseForwardCamera)() = (void(__cdecl*)())0x004bb510;
CARM95_HOOK_FUNCTION(original_ReinitialiseForwardCamera, ReinitialiseForwardCamera)
void __cdecl ReinitialiseForwardCamera() {
    br_camera *camera_ptr;
    float the_angle;
    float d;
    float w;
    LOG_TRACE("()");

    (void)camera_ptr;
    (void)the_angle;
    (void)d;
    (void)w;

    original_ReinitialiseForwardCamera();
}

static void(__cdecl*original_AllocateRearviewPixelmap)() = (void(__cdecl*)())0x004bb741;
CARM95_HOOK_FUNCTION(original_AllocateRearviewPixelmap, AllocateRearviewPixelmap)
void __cdecl AllocateRearviewPixelmap() {
    char *rear_screen_pixels;
    LOG_TRACE("()");

    (void)rear_screen_pixels;

    original_AllocateRearviewPixelmap();
}

static void(__cdecl*original_ReinitialiseRearviewCamera)() = (void(__cdecl*)())0x004bb887;
CARM95_HOOK_FUNCTION(original_ReinitialiseRearviewCamera, ReinitialiseRearviewCamera)
void __cdecl ReinitialiseRearviewCamera() {
    br_camera *camera_ptr;
    LOG_TRACE("()");

    (void)camera_ptr;

    original_ReinitialiseRearviewCamera();
}

static void(__cdecl*original_ReinitialiseRenderStuff)() = (void(__cdecl*)())0x004bb916;
CARM95_HOOK_FUNCTION(original_ReinitialiseRenderStuff, ReinitialiseRenderStuff)
void __cdecl ReinitialiseRenderStuff() {
    int x_diff;
    int y_diff;
    LOG_TRACE("()");

    (void)x_diff;
    (void)y_diff;

    original_ReinitialiseRenderStuff();
}

void InstallFindFailedHooks() {
    LOG_TRACE("()");


    NOT_IMPLEMENTED();
}

static void(__cdecl*original_AllocateStandardLamp)() = (void(__cdecl*)())0x004bbcdb;
CARM95_HOOK_FUNCTION(original_AllocateStandardLamp, AllocateStandardLamp)
void __cdecl AllocateStandardLamp() {
    br_actor *the_child;
    br_actor *lamp;
    int i;
    LOG_TRACE("()");

    (void)the_child;
    (void)lamp;
    (void)i;

    original_AllocateStandardLamp();
}

static void(__cdecl*original_InitializeBRenderEnvironment)() = (void(__cdecl*)())0x004bbd6c;
CARM95_HOOK_FUNCTION(original_InitializeBRenderEnvironment, InitializeBRenderEnvironment)
void __cdecl InitializeBRenderEnvironment() {
    br_model *arrow_model;
    LOG_TRACE("()");

    (void)arrow_model;

    original_InitializeBRenderEnvironment();
}

static void(__cdecl*original_InitBRFonts)() = (void(__cdecl*)())0x004bc12c;
CARM95_HOOK_FUNCTION(original_InitBRFonts, InitBRFonts)
void __cdecl InitBRFonts() {
    LOG_TRACE("()");


    original_InitBRFonts();
}

static void(__cdecl*original_AustereWarning)() = (void(__cdecl*)())0x004bc16d;
CARM95_HOOK_FUNCTION(original_AustereWarning, AustereWarning)
void __cdecl AustereWarning() {
    LOG_TRACE("()");


    original_AustereWarning();
}

void InitLineStuff() {
    LOG_TRACE("()");


    NOT_IMPLEMENTED();
}

void InitSmokeStuff() {
    static br_token_value fadealpha[3];
    tPath_name path;
    LOG_TRACE("()");

    (void)fadealpha;
    (void)path;

    NOT_IMPLEMENTED();
}

void Init2DStuff() {
    br_camera *camera;
    static br_token_value fadealpha[3];
    tPath_name path;
    br_scalar prat_u;
    br_scalar prat_v;
    LOG_TRACE("()");

    (void)camera;
    (void)fadealpha;
    (void)path;
    (void)prat_u;
    (void)prat_v;

    NOT_IMPLEMENTED();
}

static void(__cdecl*original_InitialiseApplication)(int, char **) = (void(__cdecl*)(int, char **))0x004bba54;
CARM95_HOOK_FUNCTION(original_InitialiseApplication, InitialiseApplication)
void __cdecl InitialiseApplication(int pArgc, char **pArgv) {
    LOG_TRACE("(%d, %p)", pArgc, pArgv);

    (void)pArgc;
    (void)pArgv;

    original_InitialiseApplication(pArgc, pArgv);
}

void InitialiseDeathRace(int pArgc, char **pArgv) {
    tPath_name the_path;
    LOG_TRACE("(%d, %p)", pArgc, pArgv);

    (void)pArgc;
    (void)pArgv;
    (void)the_path;

    NOT_IMPLEMENTED();
}

static void(__cdecl*original_InitGame)(int) = (void(__cdecl*)(int))0x004bc22c;
CARM95_HOOK_FUNCTION(original_InitGame, InitGame)
void __cdecl InitGame(int pStart_race) {
    int i;
    LOG_TRACE("(%d)", pStart_race);

    (void)pStart_race;
    (void)i;

    original_InitGame(pStart_race);
}

static void(__cdecl*original_DisposeGameIfNecessary)() = (void(__cdecl*)())0x004bc3d0;
CARM95_HOOK_FUNCTION(original_DisposeGameIfNecessary, DisposeGameIfNecessary)
void __cdecl DisposeGameIfNecessary() {
    int i;
    LOG_TRACE("()");

    (void)i;

    original_DisposeGameIfNecessary();
}

static void(__cdecl*original_LoadInTrack)() = (void(__cdecl*)())0x004bc93a;
CARM95_HOOK_FUNCTION(original_LoadInTrack, LoadInTrack)
void __cdecl LoadInTrack() {
    LOG_TRACE("()");


    original_LoadInTrack();
}

static void(__cdecl*original_DisposeTrack)() = (void(__cdecl*)())0x004bc493;
CARM95_HOOK_FUNCTION(original_DisposeTrack, DisposeTrack)
void __cdecl DisposeTrack() {
    LOG_TRACE("()");


    original_DisposeTrack();
}

void CopyMaterialColourFromIndex(br_material *pMaterial) {
    LOG_TRACE("(%p)", pMaterial);

    (void)pMaterial;

    NOT_IMPLEMENTED();
}

static void(__cdecl*original_InitRace)() = (void(__cdecl*)())0x004bc4b1;
CARM95_HOOK_FUNCTION(original_InitRace, InitRace)
void __cdecl InitRace() {
    LOG_TRACE("()");


    original_InitRace();
}

static void(__cdecl*original_DisposeRace)() = (void(__cdecl*)())0x004bc968;
CARM95_HOOK_FUNCTION(original_DisposeRace, DisposeRace)
void __cdecl DisposeRace() {
    LOG_TRACE("()");


    original_DisposeRace();
}

static int(__cdecl*original_GetScreenSize)() = (int(__cdecl*)())0x004bca25;
CARM95_HOOK_FUNCTION(original_GetScreenSize, GetScreenSize)
int __cdecl GetScreenSize() {
    LOG_TRACE("()");


    return original_GetScreenSize();
}

static void(__cdecl*original_SetScreenSize)(int) = (void(__cdecl*)(int))0x004bca3a;
CARM95_HOOK_FUNCTION(original_SetScreenSize, SetScreenSize)
void __cdecl SetScreenSize(int pNew_size) {
    LOG_TRACE("(%d)", pNew_size);

    (void)pNew_size;

    original_SetScreenSize(pNew_size);
}

