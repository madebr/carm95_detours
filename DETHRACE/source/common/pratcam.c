#include "pratcam.h"

#include "harness/trace.h"

#include "carm95_hooks.h"

tS3_sound_tag * hookvar_gWhirr_noise  = (void*)0x0050f064;
tFlic_descriptor * hookvar_gPrat_flic  = (void*)0x005362b0;
tPrat_sequence ** hookvar_gPratcam_sequences  = (void*)0x00536334;
tPrat_flic_spec ** hookvar_gPratcam_flics  = (void*)0x00536324;
int * hookvar_gCurrent_pratcam_chunk  = (void*)0x00536320;
int * hookvar_gPending_ambient_prat  = (void*)0x0053632c;
int * hookvar_gCurrent_pratcam_index  = (void*)0x005362a0;
br_pixelmap ** hookvar_gPrat_buffer  = (void*)0x00536340;
int * hookvar_gNumber_of_prat_sequences  = (void*)0x00536330;
int * hookvar_gNumber_of_prat_flics  = (void*)0x005362a4;
tU32 * hookvar_gLast_pratcam_frame_time  = (void*)0x0053633c;
int * hookvar_gCurrent_pratcam_precedence  = (void*)0x00536328;
int * hookvar_gCurrent_ambient_prat_sequence  = (void*)0x00536338;
int * hookvar_gCurrent_pratcam_alternative  = (void*)0x005362a8;

static int(__cdecl*original_PratcamGetCurrent)() = (int(__cdecl*)())0x0044d0b0;
CARM95_HOOK_FUNCTION(original_PratcamGetCurrent, PratcamGetCurrent)
int __cdecl PratcamGetCurrent() {
    LOG_TRACE("()");


    return original_PratcamGetCurrent();
}

static int(__cdecl*original_PratcamGetAmbient)() = (int(__cdecl*)())0x0044d0c5;
CARM95_HOOK_FUNCTION(original_PratcamGetAmbient, PratcamGetAmbient)
int __cdecl PratcamGetAmbient() {
    LOG_TRACE("()");


    return original_PratcamGetAmbient();
}

static int(__cdecl*original_PratcamGetPending)() = (int(__cdecl*)())0x0044d0da;
CARM95_HOOK_FUNCTION(original_PratcamGetPending, PratcamGetPending)
int __cdecl PratcamGetPending() {
    LOG_TRACE("()");


    return original_PratcamGetPending();
}

static void(__cdecl*original_TogglePratcam)() = (void(__cdecl*)())0x0044d0ef;
CARM95_HOOK_FUNCTION(original_TogglePratcam, TogglePratcam)
void __cdecl TogglePratcam() {
    tU32 the_time;
    tU32 time_diff;
    LOG_TRACE("()");

    (void)the_time;
    (void)time_diff;

    original_TogglePratcam();
}

static void(__cdecl*original_LoadPratcam)(char *) = (void(__cdecl*)(char *))0x0044d745;
CARM95_HOOK_FUNCTION(original_LoadPratcam, LoadPratcam)
void __cdecl LoadPratcam(char *pFolder_name) {
    FILE *f;
    FILE *g;
    tPath_name the_path;
    int i;
    int j;
    int k;
    int l;
    char s[256];
    char folder_path[256];
    char *str;
    char num_str[256];
    LOG_TRACE("(\"%s\")", pFolder_name);

    (void)pFolder_name;
    (void)f;
    (void)g;
    (void)the_path;
    (void)i;
    (void)j;
    (void)k;
    (void)l;
    (void)s;
    (void)folder_path;
    (void)str;
    (void)num_str;

    original_LoadPratcam(pFolder_name);
}

static void(__cdecl*original_NextPratcamChunk)() = (void(__cdecl*)())0x0044d2d8;
CARM95_HOOK_FUNCTION(original_NextPratcamChunk, NextPratcamChunk)
void __cdecl NextPratcamChunk() {
    int i;
    int random_number;
    int count;
    tPrat_alternative *current_alternative;
    LOG_TRACE("()");

    (void)i;
    (void)random_number;
    (void)count;
    (void)current_alternative;

    original_NextPratcamChunk();
}

static void(__cdecl*original_NewPratcamSequence)(int, int) = (void(__cdecl*)(int, int))0x0044d297;
CARM95_HOOK_FUNCTION(original_NewPratcamSequence, NewPratcamSequence)
void __cdecl NewPratcamSequence(int pSequence_index, int pStart_chunk) {
    LOG_TRACE("(%d, %d)", pSequence_index, pStart_chunk);

    (void)pSequence_index;
    (void)pStart_chunk;

    original_NewPratcamSequence(pSequence_index, pStart_chunk);
}

static void(__cdecl*original_ChangeAmbientPratcamNow)(int, int) = (void(__cdecl*)(int, int))0x0044d26a;
CARM95_HOOK_FUNCTION(original_ChangeAmbientPratcamNow, ChangeAmbientPratcamNow)
void __cdecl ChangeAmbientPratcamNow(int pIndex, int pStart_chunk) {
    LOG_TRACE("(%d, %d)", pIndex, pStart_chunk);

    (void)pIndex;
    (void)pStart_chunk;

    original_ChangeAmbientPratcamNow(pIndex, pStart_chunk);
}

static void(__cdecl*original_ChangeAmbientPratcam)(int) = (void(__cdecl*)(int))0x0044d1f0;
CARM95_HOOK_FUNCTION(original_ChangeAmbientPratcam, ChangeAmbientPratcam)
void __cdecl ChangeAmbientPratcam(int pIndex) {
    LOG_TRACE("(%d)", pIndex);

    (void)pIndex;

    original_ChangeAmbientPratcam(pIndex);
}

static void(__cdecl*original_PratcamEventNow)(int) = (void(__cdecl*)(int))0x0044d58e;
CARM95_HOOK_FUNCTION(original_PratcamEventNow, PratcamEventNow)
void __cdecl PratcamEventNow(int pIndex) {
    LOG_TRACE("(%d)", pIndex);

    (void)pIndex;

    original_PratcamEventNow(pIndex);
}

static void(__cdecl*original_PratcamEvent)(int) = (void(__cdecl*)(int))0x0044d517;
CARM95_HOOK_FUNCTION(original_PratcamEvent, PratcamEvent)
void __cdecl PratcamEvent(int pIndex) {
    LOG_TRACE("(%d)", pIndex);

    (void)pIndex;

    original_PratcamEvent(pIndex);
}

int HighResPratBufferWidth() {
    int prat_width;
    LOG_TRACE("()");

    (void)prat_width;

    NOT_IMPLEMENTED();
}

int HighResPratBufferHeight() {
    int prat_height;
    LOG_TRACE("()");

    (void)prat_height;

    NOT_IMPLEMENTED();
}

static void(__cdecl*original_InitPratcam)() = (void(__cdecl*)())0x0044d5b1;
CARM95_HOOK_FUNCTION(original_InitPratcam, InitPratcam)
void __cdecl InitPratcam() {
    void *the_pixels;
    LOG_TRACE("()");

    (void)the_pixels;

    original_InitPratcam();
}

static void(__cdecl*original_DisposePratcam)() = (void(__cdecl*)())0x0044e0dd;
CARM95_HOOK_FUNCTION(original_DisposePratcam, DisposePratcam)
void __cdecl DisposePratcam() {
    int i;
    int j;
    int k;
    int l;
    LOG_TRACE("()");

    (void)i;
    (void)j;
    (void)k;
    (void)l;

    original_DisposePratcam();
}

static void(__cdecl*original_DoPratcam)(tU32) = (void(__cdecl*)(tU32))0x0044e2e6;
CARM95_HOOK_FUNCTION(original_DoPratcam, DoPratcam)
void __cdecl DoPratcam(tU32 pThe_time) {
    int i;
    int offset;
    int y_offset;
    int top_border_height;
    int prat_cam_move_width;
    int right_hand;
    tU32 time_diff;
    tU32 old_last_time;
    br_pixelmap *the_image;
    br_pixelmap *left_image;
    br_pixelmap *right_image;
    LOG_TRACE("(%u)", pThe_time);

    (void)pThe_time;
    (void)i;
    (void)offset;
    (void)y_offset;
    (void)top_border_height;
    (void)prat_cam_move_width;
    (void)right_hand;
    (void)time_diff;
    (void)old_last_time;
    (void)the_image;
    (void)left_image;
    (void)right_image;

    original_DoPratcam(pThe_time);
}

static void(__cdecl*original_TestPratCam)(int) = (void(__cdecl*)(int))0x0044e6d5;
CARM95_HOOK_FUNCTION(original_TestPratCam, TestPratCam)
void __cdecl TestPratCam(int pIndex) {
    LOG_TRACE("(%d)", pIndex);

    (void)pIndex;

    original_TestPratCam(pIndex);
}

static void(__cdecl*original_PratCam0)() = (void(__cdecl*)())0x0044e6c0;
CARM95_HOOK_FUNCTION(original_PratCam0, PratCam0)
void __cdecl PratCam0() {
    LOG_TRACE("()");


    original_PratCam0();
}

static void(__cdecl*original_PratCam1)() = (void(__cdecl*)())0x0044e72e;
CARM95_HOOK_FUNCTION(original_PratCam1, PratCam1)
void __cdecl PratCam1() {
    LOG_TRACE("()");


    original_PratCam1();
}

static void(__cdecl*original_PratCam2)() = (void(__cdecl*)())0x0044e743;
CARM95_HOOK_FUNCTION(original_PratCam2, PratCam2)
void __cdecl PratCam2() {
    LOG_TRACE("()");


    original_PratCam2();
}

static void(__cdecl*original_PratCam3)() = (void(__cdecl*)())0x0044e758;
CARM95_HOOK_FUNCTION(original_PratCam3, PratCam3)
void __cdecl PratCam3() {
    LOG_TRACE("()");


    original_PratCam3();
}

static void(__cdecl*original_PratCam4)() = (void(__cdecl*)())0x0044e76d;
CARM95_HOOK_FUNCTION(original_PratCam4, PratCam4)
void __cdecl PratCam4() {
    LOG_TRACE("()");


    original_PratCam4();
}

static void(__cdecl*original_PratCam5)() = (void(__cdecl*)())0x0044e782;
CARM95_HOOK_FUNCTION(original_PratCam5, PratCam5)
void __cdecl PratCam5() {
    LOG_TRACE("()");


    original_PratCam5();
}

static void(__cdecl*original_PratCam6)() = (void(__cdecl*)())0x0044e797;
CARM95_HOOK_FUNCTION(original_PratCam6, PratCam6)
void __cdecl PratCam6() {
    LOG_TRACE("()");


    original_PratCam6();
}

static void(__cdecl*original_PratCam7)() = (void(__cdecl*)())0x0044e7ac;
CARM95_HOOK_FUNCTION(original_PratCam7, PratCam7)
void __cdecl PratCam7() {
    LOG_TRACE("()");


    original_PratCam7();
}

static void(__cdecl*original_PratCam8)() = (void(__cdecl*)())0x0044e7c1;
CARM95_HOOK_FUNCTION(original_PratCam8, PratCam8)
void __cdecl PratCam8() {
    LOG_TRACE("()");


    original_PratCam8();
}

static void(__cdecl*original_PratCam9)() = (void(__cdecl*)())0x0044e7d6;
CARM95_HOOK_FUNCTION(original_PratCam9, PratCam9)
void __cdecl PratCam9() {
    LOG_TRACE("()");


    original_PratCam9();
}

