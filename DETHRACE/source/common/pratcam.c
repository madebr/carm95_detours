#include "pratcam.h"

#include "harness/trace.h"

#include "carm95_hooks.h"

#include "carm95_webserver.h"

#include <assert.h>
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

function_hook_state_t function_hook_state_PratcamGetCurrent = HOOK_UNAVAILABLE;
static int(__cdecl*original_PratcamGetCurrent)() = (int(__cdecl*)())0x0044d0b0;
CARM95_HOOK_FUNCTION(original_PratcamGetCurrent, PratcamGetCurrent)
int __cdecl PratcamGetCurrent() {
    LOG_TRACE("()");


    if (function_hook_state_PratcamGetCurrent == HOOK_ENABLED) {
        assert(0 && "PratcamGetCurrent not implemented.");
        abort();
    } else {
        return original_PratcamGetCurrent();
    }
}

function_hook_state_t function_hook_state_PratcamGetAmbient = HOOK_UNAVAILABLE;
static int(__cdecl*original_PratcamGetAmbient)() = (int(__cdecl*)())0x0044d0c5;
CARM95_HOOK_FUNCTION(original_PratcamGetAmbient, PratcamGetAmbient)
int __cdecl PratcamGetAmbient() {
    LOG_TRACE("()");


    if (function_hook_state_PratcamGetAmbient == HOOK_ENABLED) {
        assert(0 && "PratcamGetAmbient not implemented.");
        abort();
    } else {
        return original_PratcamGetAmbient();
    }
}

function_hook_state_t function_hook_state_PratcamGetPending = HOOK_UNAVAILABLE;
static int(__cdecl*original_PratcamGetPending)() = (int(__cdecl*)())0x0044d0da;
CARM95_HOOK_FUNCTION(original_PratcamGetPending, PratcamGetPending)
int __cdecl PratcamGetPending() {
    LOG_TRACE("()");


    if (function_hook_state_PratcamGetPending == HOOK_ENABLED) {
        assert(0 && "PratcamGetPending not implemented.");
        abort();
    } else {
        return original_PratcamGetPending();
    }
}

function_hook_state_t function_hook_state_TogglePratcam = HOOK_UNAVAILABLE;
static void(__cdecl*original_TogglePratcam)() = (void(__cdecl*)())0x0044d0ef;
CARM95_HOOK_FUNCTION(original_TogglePratcam, TogglePratcam)
void __cdecl TogglePratcam() {
    tU32 the_time;
    tU32 time_diff;
    LOG_TRACE("()");

    (void)the_time;
    (void)time_diff;

    if (function_hook_state_TogglePratcam == HOOK_ENABLED) {
        assert(0 && "TogglePratcam not implemented.");
        abort();
    } else {
        original_TogglePratcam();
    }
}

function_hook_state_t function_hook_state_LoadPratcam = HOOK_UNAVAILABLE;
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

    if (function_hook_state_LoadPratcam == HOOK_ENABLED) {
        assert(0 && "LoadPratcam not implemented.");
        abort();
    } else {
        original_LoadPratcam(pFolder_name);
    }
}

function_hook_state_t function_hook_state_NextPratcamChunk = HOOK_UNAVAILABLE;
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

    if (function_hook_state_NextPratcamChunk == HOOK_ENABLED) {
        assert(0 && "NextPratcamChunk not implemented.");
        abort();
    } else {
        original_NextPratcamChunk();
    }
}

function_hook_state_t function_hook_state_NewPratcamSequence = HOOK_UNAVAILABLE;
static void(__cdecl*original_NewPratcamSequence)(int, int) = (void(__cdecl*)(int, int))0x0044d297;
CARM95_HOOK_FUNCTION(original_NewPratcamSequence, NewPratcamSequence)
void __cdecl NewPratcamSequence(int pSequence_index, int pStart_chunk) {
    LOG_TRACE("(%d, %d)", pSequence_index, pStart_chunk);

    (void)pSequence_index;
    (void)pStart_chunk;

    if (function_hook_state_NewPratcamSequence == HOOK_ENABLED) {
        assert(0 && "NewPratcamSequence not implemented.");
        abort();
    } else {
        original_NewPratcamSequence(pSequence_index, pStart_chunk);
    }
}

function_hook_state_t function_hook_state_ChangeAmbientPratcamNow = HOOK_UNAVAILABLE;
static void(__cdecl*original_ChangeAmbientPratcamNow)(int, int) = (void(__cdecl*)(int, int))0x0044d26a;
CARM95_HOOK_FUNCTION(original_ChangeAmbientPratcamNow, ChangeAmbientPratcamNow)
void __cdecl ChangeAmbientPratcamNow(int pIndex, int pStart_chunk) {
    LOG_TRACE("(%d, %d)", pIndex, pStart_chunk);

    (void)pIndex;
    (void)pStart_chunk;

    if (function_hook_state_ChangeAmbientPratcamNow == HOOK_ENABLED) {
        assert(0 && "ChangeAmbientPratcamNow not implemented.");
        abort();
    } else {
        original_ChangeAmbientPratcamNow(pIndex, pStart_chunk);
    }
}

function_hook_state_t function_hook_state_ChangeAmbientPratcam = HOOK_UNAVAILABLE;
static void(__cdecl*original_ChangeAmbientPratcam)(int) = (void(__cdecl*)(int))0x0044d1f0;
CARM95_HOOK_FUNCTION(original_ChangeAmbientPratcam, ChangeAmbientPratcam)
void __cdecl ChangeAmbientPratcam(int pIndex) {
    LOG_TRACE("(%d)", pIndex);

    (void)pIndex;

    if (function_hook_state_ChangeAmbientPratcam == HOOK_ENABLED) {
        assert(0 && "ChangeAmbientPratcam not implemented.");
        abort();
    } else {
        original_ChangeAmbientPratcam(pIndex);
    }
}

function_hook_state_t function_hook_state_PratcamEventNow = HOOK_UNAVAILABLE;
static void(__cdecl*original_PratcamEventNow)(int) = (void(__cdecl*)(int))0x0044d58e;
CARM95_HOOK_FUNCTION(original_PratcamEventNow, PratcamEventNow)
void __cdecl PratcamEventNow(int pIndex) {
    LOG_TRACE("(%d)", pIndex);

    (void)pIndex;

    if (function_hook_state_PratcamEventNow == HOOK_ENABLED) {
        assert(0 && "PratcamEventNow not implemented.");
        abort();
    } else {
        original_PratcamEventNow(pIndex);
    }
}

function_hook_state_t function_hook_state_PratcamEvent = HOOK_UNAVAILABLE;
static void(__cdecl*original_PratcamEvent)(int) = (void(__cdecl*)(int))0x0044d517;
CARM95_HOOK_FUNCTION(original_PratcamEvent, PratcamEvent)
void __cdecl PratcamEvent(int pIndex) {
    LOG_TRACE("(%d)", pIndex);

    (void)pIndex;

    if (function_hook_state_PratcamEvent == HOOK_ENABLED) {
        assert(0 && "PratcamEvent not implemented.");
        abort();
    } else {
        original_PratcamEvent(pIndex);
    }
}

function_hook_state_t function_hook_state_HighResPratBufferWidth = HOOK_UNAVAILABLE;
int HighResPratBufferWidth() {
    int prat_width;
    LOG_TRACE("()");

    (void)prat_width;

    if (function_hook_state_HighResPratBufferWidth == HOOK_ENABLED) {
        assert(0 && "HighResPratBufferWidth not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}

function_hook_state_t function_hook_state_HighResPratBufferHeight = HOOK_UNAVAILABLE;
int HighResPratBufferHeight() {
    int prat_height;
    LOG_TRACE("()");

    (void)prat_height;

    if (function_hook_state_HighResPratBufferHeight == HOOK_ENABLED) {
        assert(0 && "HighResPratBufferHeight not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}

function_hook_state_t function_hook_state_InitPratcam = HOOK_UNAVAILABLE;
static void(__cdecl*original_InitPratcam)() = (void(__cdecl*)())0x0044d5b1;
CARM95_HOOK_FUNCTION(original_InitPratcam, InitPratcam)
void __cdecl InitPratcam() {
    void *the_pixels;
    LOG_TRACE("()");

    (void)the_pixels;

    if (function_hook_state_InitPratcam == HOOK_ENABLED) {
        assert(0 && "InitPratcam not implemented.");
        abort();
    } else {
        original_InitPratcam();
    }
}

function_hook_state_t function_hook_state_DisposePratcam = HOOK_UNAVAILABLE;
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

    if (function_hook_state_DisposePratcam == HOOK_ENABLED) {
        assert(0 && "DisposePratcam not implemented.");
        abort();
    } else {
        original_DisposePratcam();
    }
}

function_hook_state_t function_hook_state_DoPratcam = HOOK_UNAVAILABLE;
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

    if (function_hook_state_DoPratcam == HOOK_ENABLED) {
        assert(0 && "DoPratcam not implemented.");
        abort();
    } else {
        original_DoPratcam(pThe_time);
    }
}

function_hook_state_t function_hook_state_TestPratCam = HOOK_UNAVAILABLE;
static void(__cdecl*original_TestPratCam)(int) = (void(__cdecl*)(int))0x0044e6d5;
CARM95_HOOK_FUNCTION(original_TestPratCam, TestPratCam)
void __cdecl TestPratCam(int pIndex) {
    LOG_TRACE("(%d)", pIndex);

    (void)pIndex;

    if (function_hook_state_TestPratCam == HOOK_ENABLED) {
        assert(0 && "TestPratCam not implemented.");
        abort();
    } else {
        original_TestPratCam(pIndex);
    }
}

function_hook_state_t function_hook_state_PratCam0 = HOOK_UNAVAILABLE;
static void(__cdecl*original_PratCam0)() = (void(__cdecl*)())0x0044e6c0;
CARM95_HOOK_FUNCTION(original_PratCam0, PratCam0)
void __cdecl PratCam0() {
    LOG_TRACE("()");


    if (function_hook_state_PratCam0 == HOOK_ENABLED) {
        assert(0 && "PratCam0 not implemented.");
        abort();
    } else {
        original_PratCam0();
    }
}

function_hook_state_t function_hook_state_PratCam1 = HOOK_UNAVAILABLE;
static void(__cdecl*original_PratCam1)() = (void(__cdecl*)())0x0044e72e;
CARM95_HOOK_FUNCTION(original_PratCam1, PratCam1)
void __cdecl PratCam1() {
    LOG_TRACE("()");


    if (function_hook_state_PratCam1 == HOOK_ENABLED) {
        assert(0 && "PratCam1 not implemented.");
        abort();
    } else {
        original_PratCam1();
    }
}

function_hook_state_t function_hook_state_PratCam2 = HOOK_UNAVAILABLE;
static void(__cdecl*original_PratCam2)() = (void(__cdecl*)())0x0044e743;
CARM95_HOOK_FUNCTION(original_PratCam2, PratCam2)
void __cdecl PratCam2() {
    LOG_TRACE("()");


    if (function_hook_state_PratCam2 == HOOK_ENABLED) {
        assert(0 && "PratCam2 not implemented.");
        abort();
    } else {
        original_PratCam2();
    }
}

function_hook_state_t function_hook_state_PratCam3 = HOOK_UNAVAILABLE;
static void(__cdecl*original_PratCam3)() = (void(__cdecl*)())0x0044e758;
CARM95_HOOK_FUNCTION(original_PratCam3, PratCam3)
void __cdecl PratCam3() {
    LOG_TRACE("()");


    if (function_hook_state_PratCam3 == HOOK_ENABLED) {
        assert(0 && "PratCam3 not implemented.");
        abort();
    } else {
        original_PratCam3();
    }
}

function_hook_state_t function_hook_state_PratCam4 = HOOK_UNAVAILABLE;
static void(__cdecl*original_PratCam4)() = (void(__cdecl*)())0x0044e76d;
CARM95_HOOK_FUNCTION(original_PratCam4, PratCam4)
void __cdecl PratCam4() {
    LOG_TRACE("()");


    if (function_hook_state_PratCam4 == HOOK_ENABLED) {
        assert(0 && "PratCam4 not implemented.");
        abort();
    } else {
        original_PratCam4();
    }
}

function_hook_state_t function_hook_state_PratCam5 = HOOK_UNAVAILABLE;
static void(__cdecl*original_PratCam5)() = (void(__cdecl*)())0x0044e782;
CARM95_HOOK_FUNCTION(original_PratCam5, PratCam5)
void __cdecl PratCam5() {
    LOG_TRACE("()");


    if (function_hook_state_PratCam5 == HOOK_ENABLED) {
        assert(0 && "PratCam5 not implemented.");
        abort();
    } else {
        original_PratCam5();
    }
}

function_hook_state_t function_hook_state_PratCam6 = HOOK_UNAVAILABLE;
static void(__cdecl*original_PratCam6)() = (void(__cdecl*)())0x0044e797;
CARM95_HOOK_FUNCTION(original_PratCam6, PratCam6)
void __cdecl PratCam6() {
    LOG_TRACE("()");


    if (function_hook_state_PratCam6 == HOOK_ENABLED) {
        assert(0 && "PratCam6 not implemented.");
        abort();
    } else {
        original_PratCam6();
    }
}

function_hook_state_t function_hook_state_PratCam7 = HOOK_UNAVAILABLE;
static void(__cdecl*original_PratCam7)() = (void(__cdecl*)())0x0044e7ac;
CARM95_HOOK_FUNCTION(original_PratCam7, PratCam7)
void __cdecl PratCam7() {
    LOG_TRACE("()");


    if (function_hook_state_PratCam7 == HOOK_ENABLED) {
        assert(0 && "PratCam7 not implemented.");
        abort();
    } else {
        original_PratCam7();
    }
}

function_hook_state_t function_hook_state_PratCam8 = HOOK_UNAVAILABLE;
static void(__cdecl*original_PratCam8)() = (void(__cdecl*)())0x0044e7c1;
CARM95_HOOK_FUNCTION(original_PratCam8, PratCam8)
void __cdecl PratCam8() {
    LOG_TRACE("()");


    if (function_hook_state_PratCam8 == HOOK_ENABLED) {
        assert(0 && "PratCam8 not implemented.");
        abort();
    } else {
        original_PratCam8();
    }
}

function_hook_state_t function_hook_state_PratCam9 = HOOK_UNAVAILABLE;
static void(__cdecl*original_PratCam9)() = (void(__cdecl*)())0x0044e7d6;
CARM95_HOOK_FUNCTION(original_PratCam9, PratCam9)
void __cdecl PratCam9() {
    LOG_TRACE("()");


    if (function_hook_state_PratCam9 == HOOK_ENABLED) {
        assert(0 && "PratCam9 not implemented.");
        abort();
    } else {
        original_PratCam9();
    }
}

