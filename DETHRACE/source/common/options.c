#include "options.h"

#include "harness/trace.h"

#include "carm95_hooks.h"

#include "carm95_webserver.h"

#include <assert.h>
int(* hookvar_gKey_defns )[18] = (void*)0x00519ad8;
 // Suffix added to avoid duplicate symbol
tRadio_bastards(* hookvar_gRadio_bastards__options )[13] = (void*)0x00519b20;
int * hookvar_gKey_count  = (void*)0x0053d1d4;
 // Suffix added to avoid duplicate symbol
#if 0
int * hookvar_gLast_graph_sel__options ;
#endif
char *(* hookvar_gKey_names )[125] = (void*)0x0053d2f0;
int * hookvar_gPending_entry  = (void*)0x0053d1d0;
 // Suffix added to avoid duplicate symbol
tInterface_spec ** hookvar_gThe_interface_spec__options  = (void*)0x0053d2ec;
int(* hookvar_gOrig_key_mapping )[67] = (void*)0x0053d1e0;
br_pixelmap ** hookvar_gDials_pix  = (void*)0x0053d1d8;
int * hookvar_gCurrent_key  = (void*)0x0053d4e8;

function_hook_state_t function_hook_state_DrawDial = HOOK_UNAVAILABLE;
void DrawDial(int pWhich_one, int pWhich_stage) {
    LOG_TRACE("(%d, %d)", pWhich_one, pWhich_stage);

    (void)pWhich_one;
    (void)pWhich_stage;

    if (function_hook_state_DrawDial == HOOK_ENABLED) {
        assert(0 && "DrawDial not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}

function_hook_state_t function_hook_state_MoveDialFromTo = HOOK_UNAVAILABLE;
void MoveDialFromTo(int pWhich_one, int pOld_stage, int pNew_stage) {
    tS32 time_diff;
    tU32 start_time;
    LOG_TRACE("(%d, %d, %d)", pWhich_one, pOld_stage, pNew_stage);

    (void)pWhich_one;
    (void)pOld_stage;
    (void)pNew_stage;
    (void)time_diff;
    (void)start_time;

    if (function_hook_state_MoveDialFromTo == HOOK_ENABLED) {
        assert(0 && "MoveDialFromTo not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}

function_hook_state_t function_hook_state_SoundOptionsStart = HOOK_UNAVAILABLE;
void SoundOptionsStart() {
    LOG_TRACE("()");


    if (function_hook_state_SoundOptionsStart == HOOK_ENABLED) {
        assert(0 && "SoundOptionsStart not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}

function_hook_state_t function_hook_state_SoundOptionsDone = HOOK_UNAVAILABLE;
int SoundOptionsDone(int pCurrent_choice, int pCurrent_mode, int pGo_ahead, int pEscaped, int pTimed_out) {
    LOG_TRACE("(%d, %d, %d, %d, %d)", pCurrent_choice, pCurrent_mode, pGo_ahead, pEscaped, pTimed_out);

    (void)pCurrent_choice;
    (void)pCurrent_mode;
    (void)pGo_ahead;
    (void)pEscaped;
    (void)pTimed_out;

    if (function_hook_state_SoundOptionsDone == HOOK_ENABLED) {
        assert(0 && "SoundOptionsDone not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}

function_hook_state_t function_hook_state_SoundOptionsLeft = HOOK_UNAVAILABLE;
int SoundOptionsLeft(int *pCurrent_choice, int *pCurrent_mode) {
    int old_value;
    int *the_value;
    LOG_TRACE("(%p, %p)", pCurrent_choice, pCurrent_mode);

    (void)pCurrent_choice;
    (void)pCurrent_mode;
    (void)old_value;
    (void)the_value;

    if (function_hook_state_SoundOptionsLeft == HOOK_ENABLED) {
        assert(0 && "SoundOptionsLeft not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}

function_hook_state_t function_hook_state_SoundOptionsRight = HOOK_UNAVAILABLE;
int SoundOptionsRight(int *pCurrent_choice, int *pCurrent_mode) {
    int old_value;
    int *the_value;
    LOG_TRACE("(%p, %p)", pCurrent_choice, pCurrent_mode);

    (void)pCurrent_choice;
    (void)pCurrent_mode;
    (void)old_value;
    (void)the_value;

    if (function_hook_state_SoundOptionsRight == HOOK_ENABLED) {
        assert(0 && "SoundOptionsRight not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}

function_hook_state_t function_hook_state_SoundClick = HOOK_UNAVAILABLE;
int SoundClick(int *pCurrent_choice, int *pCurrent_mode, int pX_offset, int pY_offset) {
    float x_delta;
    float y_delta;
    float angle;
    int old_value;
    int *the_value;
    LOG_TRACE("(%p, %p, %d, %d)", pCurrent_choice, pCurrent_mode, pX_offset, pY_offset);

    (void)pCurrent_choice;
    (void)pCurrent_mode;
    (void)pX_offset;
    (void)pY_offset;
    (void)x_delta;
    (void)y_delta;
    (void)angle;
    (void)old_value;
    (void)the_value;

    if (function_hook_state_SoundClick == HOOK_ENABLED) {
        assert(0 && "SoundClick not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}

function_hook_state_t function_hook_state_DoSoundOptions = HOOK_UNAVAILABLE;
static void(__cdecl*original_DoSoundOptions)() = (void(__cdecl*)())0x0049b7bf;
CARM95_HOOK_FUNCTION(original_DoSoundOptions, DoSoundOptions)
void __cdecl DoSoundOptions() {
    static tFlicette flicker_on[3];
    static tFlicette flicker_off[3];
    static tFlicette push[3];
    static tMouse_area mouse_areas[3];
    static tInterface_spec interface_spec;
    int result;
    LOG_TRACE("()");

    (void)flicker_on;
    (void)flicker_off;
    (void)push;
    (void)mouse_areas;
    (void)interface_spec;
    (void)result;

    if (function_hook_state_DoSoundOptions == HOOK_ENABLED) {
        assert(0 && "DoSoundOptions not implemented.");
        abort();
    } else {
        original_DoSoundOptions();
    }
}

function_hook_state_t function_hook_state_GetGraphicsOptions = HOOK_UNAVAILABLE;
static void(__cdecl*original_GetGraphicsOptions)() = (void(__cdecl*)())0x0049b87f;
CARM95_HOOK_FUNCTION(original_GetGraphicsOptions, GetGraphicsOptions)
void __cdecl GetGraphicsOptions() {
    int value;
    br_scalar br_value;
    LOG_TRACE("()");

    (void)value;
    (void)br_value;

    if (function_hook_state_GetGraphicsOptions == HOOK_ENABLED) {
        assert(0 && "GetGraphicsOptions not implemented.");
        abort();
    } else {
        original_GetGraphicsOptions();
    }
}

function_hook_state_t function_hook_state_SetGraphicsOptions = HOOK_UNAVAILABLE;
static void(__cdecl*original_SetGraphicsOptions)() = (void(__cdecl*)())0x0049bb74;
CARM95_HOOK_FUNCTION(original_SetGraphicsOptions, SetGraphicsOptions)
void __cdecl SetGraphicsOptions() {
    LOG_TRACE("()");


    if (function_hook_state_SetGraphicsOptions == HOOK_ENABLED) {
        assert(0 && "SetGraphicsOptions not implemented.");
        abort();
    } else {
        original_SetGraphicsOptions();
    }
}

function_hook_state_t function_hook_state_PlayRadioOn2 = HOOK_UNAVAILABLE;
static void(__cdecl*original_PlayRadioOn2)(int, int) = (void(__cdecl*)(int, int))0x00499efe;
CARM95_HOOK_FUNCTION(original_PlayRadioOn2, PlayRadioOn2)
void __cdecl PlayRadioOn2(int pIndex, int pValue) {
    LOG_TRACE("(%d, %d)", pIndex, pValue);

    (void)pIndex;
    (void)pValue;

    if (function_hook_state_PlayRadioOn2 == HOOK_ENABLED) {
        assert(0 && "PlayRadioOn2 not implemented.");
        abort();
    } else {
        original_PlayRadioOn2(pIndex, pValue);
    }
}

function_hook_state_t function_hook_state_PlayRadioOff2 = HOOK_UNAVAILABLE;
static void(__cdecl*original_PlayRadioOff2)(int, int) = (void(__cdecl*)(int, int))0x0049a05d;
CARM95_HOOK_FUNCTION(original_PlayRadioOff2, PlayRadioOff2)
void __cdecl PlayRadioOff2(int pIndex, int pValue) {
    LOG_TRACE("(%d, %d)", pIndex, pValue);

    (void)pIndex;
    (void)pValue;

    if (function_hook_state_PlayRadioOff2 == HOOK_ENABLED) {
        assert(0 && "PlayRadioOff2 not implemented.");
        abort();
    } else {
        original_PlayRadioOff2(pIndex, pValue);
    }
}

function_hook_state_t function_hook_state_PlayRadioOn__options = HOOK_UNAVAILABLE;
static void(__cdecl*original_PlayRadioOn__options)(int, int) = (void(__cdecl*)(int, int))0x00499feb;
CARM95_HOOK_FUNCTION(original_PlayRadioOn__options, PlayRadioOn__options)
void __cdecl PlayRadioOn__options(int pIndex, int pValue) {
    LOG_TRACE("(%d, %d)", pIndex, pValue);

    (void)pIndex;
    (void)pValue;

    if (function_hook_state_PlayRadioOn__options == HOOK_ENABLED) {
        assert(0 && "PlayRadioOn__options not implemented.");
        abort();
    } else {
        original_PlayRadioOn__options(pIndex, pValue);
    }
}

function_hook_state_t function_hook_state_PlayRadioOff__options = HOOK_UNAVAILABLE;
static void(__cdecl*original_PlayRadioOff__options)(int, int) = (void(__cdecl*)(int, int))0x0049a024;
CARM95_HOOK_FUNCTION(original_PlayRadioOff__options, PlayRadioOff__options)
void __cdecl PlayRadioOff__options(int pIndex, int pValue) {
    LOG_TRACE("(%d, %d)", pIndex, pValue);

    (void)pIndex;
    (void)pValue;

    if (function_hook_state_PlayRadioOff__options == HOOK_ENABLED) {
        assert(0 && "PlayRadioOff__options not implemented.");
        abort();
    } else {
        original_PlayRadioOff__options(pIndex, pValue);
    }
}

function_hook_state_t function_hook_state_DrawInitialRadios = HOOK_UNAVAILABLE;
static void(__cdecl*original_DrawInitialRadios)() = (void(__cdecl*)())0x00499e9b;
CARM95_HOOK_FUNCTION(original_DrawInitialRadios, DrawInitialRadios)
void __cdecl DrawInitialRadios() {
    int i;
    LOG_TRACE("()");

    (void)i;

    if (function_hook_state_DrawInitialRadios == HOOK_ENABLED) {
        assert(0 && "DrawInitialRadios not implemented.");
        abort();
    } else {
        original_DrawInitialRadios();
    }
}

function_hook_state_t function_hook_state_RadioChanged = HOOK_UNAVAILABLE;
static void(__cdecl*original_RadioChanged)(int, int) = (void(__cdecl*)(int, int))0x00499fa8;
CARM95_HOOK_FUNCTION(original_RadioChanged, RadioChanged)
void __cdecl RadioChanged(int pIndex, int pNew_value) {
    LOG_TRACE("(%d, %d)", pIndex, pNew_value);

    (void)pIndex;
    (void)pNew_value;

    if (function_hook_state_RadioChanged == HOOK_ENABLED) {
        assert(0 && "RadioChanged not implemented.");
        abort();
    } else {
        original_RadioChanged(pIndex, pNew_value);
    }
}

function_hook_state_t function_hook_state_GraphOptLeft = HOOK_UNAVAILABLE;
static int(__cdecl*original_GraphOptLeft)(int *, int *) = (int(__cdecl*)(int *, int *))0x00499f34;
CARM95_HOOK_FUNCTION(original_GraphOptLeft, GraphOptLeft)
int __cdecl GraphOptLeft(int *pCurrent_choice, int *pCurrent_mode) {
    int new_value;
    LOG_TRACE("(%p, %p)", pCurrent_choice, pCurrent_mode);

    (void)pCurrent_choice;
    (void)pCurrent_mode;
    (void)new_value;

    if (function_hook_state_GraphOptLeft == HOOK_ENABLED) {
        assert(0 && "GraphOptLeft not implemented.");
        abort();
    } else {
        return original_GraphOptLeft(pCurrent_choice, pCurrent_mode);
    }
}

function_hook_state_t function_hook_state_GraphOptRight = HOOK_UNAVAILABLE;
static int(__cdecl*original_GraphOptRight)(int *, int *) = (int(__cdecl*)(int *, int *))0x0049a093;
CARM95_HOOK_FUNCTION(original_GraphOptRight, GraphOptRight)
int __cdecl GraphOptRight(int *pCurrent_choice, int *pCurrent_mode) {
    int new_value;
    LOG_TRACE("(%p, %p)", pCurrent_choice, pCurrent_mode);

    (void)pCurrent_choice;
    (void)pCurrent_mode;
    (void)new_value;

    if (function_hook_state_GraphOptRight == HOOK_ENABLED) {
        assert(0 && "GraphOptRight not implemented.");
        abort();
    } else {
        return original_GraphOptRight(pCurrent_choice, pCurrent_mode);
    }
}

function_hook_state_t function_hook_state_GraphOptUp = HOOK_UNAVAILABLE;
static int(__cdecl*original_GraphOptUp)(int *, int *) = (int(__cdecl*)(int *, int *))0x0049a109;
CARM95_HOOK_FUNCTION(original_GraphOptUp, GraphOptUp)
int __cdecl GraphOptUp(int *pCurrent_choice, int *pCurrent_mode) {
    LOG_TRACE("(%p, %p)", pCurrent_choice, pCurrent_mode);

    (void)pCurrent_choice;
    (void)pCurrent_mode;

    if (function_hook_state_GraphOptUp == HOOK_ENABLED) {
        assert(0 && "GraphOptUp not implemented.");
        abort();
    } else {
        return original_GraphOptUp(pCurrent_choice, pCurrent_mode);
    }
}

function_hook_state_t function_hook_state_GraphOptDown = HOOK_UNAVAILABLE;
static int(__cdecl*original_GraphOptDown)(int *, int *) = (int(__cdecl*)(int *, int *))0x0049a19b;
CARM95_HOOK_FUNCTION(original_GraphOptDown, GraphOptDown)
int __cdecl GraphOptDown(int *pCurrent_choice, int *pCurrent_mode) {
    LOG_TRACE("(%p, %p)", pCurrent_choice, pCurrent_mode);

    (void)pCurrent_choice;
    (void)pCurrent_mode;

    if (function_hook_state_GraphOptDown == HOOK_ENABLED) {
        assert(0 && "GraphOptDown not implemented.");
        abort();
    } else {
        return original_GraphOptDown(pCurrent_choice, pCurrent_mode);
    }
}

function_hook_state_t function_hook_state_RadioClick = HOOK_UNAVAILABLE;
static int(__cdecl*original_RadioClick)(int *, int *, int, int) = (int(__cdecl*)(int *, int *, int, int))0x0049a22d;
CARM95_HOOK_FUNCTION(original_RadioClick, RadioClick)
int __cdecl RadioClick(int *pCurrent_choice, int *pCurrent_mode, int pX_offset, int pY_offset) {
    int i;
    LOG_TRACE("(%p, %p, %d, %d)", pCurrent_choice, pCurrent_mode, pX_offset, pY_offset);

    (void)pCurrent_choice;
    (void)pCurrent_mode;
    (void)pX_offset;
    (void)pY_offset;
    (void)i;

    if (function_hook_state_RadioClick == HOOK_ENABLED) {
        assert(0 && "RadioClick not implemented.");
        abort();
    } else {
        return original_RadioClick(pCurrent_choice, pCurrent_mode, pX_offset, pY_offset);
    }
}

function_hook_state_t function_hook_state_GraphOptGoAhead = HOOK_UNAVAILABLE;
static int(__cdecl*original_GraphOptGoAhead)(int *, int *) = (int(__cdecl*)(int *, int *))0x0049a2d1;
CARM95_HOOK_FUNCTION(original_GraphOptGoAhead, GraphOptGoAhead)
int __cdecl GraphOptGoAhead(int *pCurrent_choice, int *pCurrent_mode) {
    LOG_TRACE("(%p, %p)", pCurrent_choice, pCurrent_mode);

    (void)pCurrent_choice;
    (void)pCurrent_mode;

    if (function_hook_state_GraphOptGoAhead == HOOK_ENABLED) {
        assert(0 && "GraphOptGoAhead not implemented.");
        abort();
    } else {
        return original_GraphOptGoAhead(pCurrent_choice, pCurrent_mode);
    }
}

function_hook_state_t function_hook_state_PlotAGraphBox__options = HOOK_UNAVAILABLE;
static void(__cdecl*original_PlotAGraphBox__options)(int, int) = (void(__cdecl*)(int, int))0x0049a34d;
CARM95_HOOK_FUNCTION(original_PlotAGraphBox__options, PlotAGraphBox__options)
void __cdecl PlotAGraphBox__options(int pIndex, int pColour_value) {
    LOG_TRACE("(%d, %d)", pIndex, pColour_value);

    (void)pIndex;
    (void)pColour_value;

    if (function_hook_state_PlotAGraphBox__options == HOOK_ENABLED) {
        assert(0 && "PlotAGraphBox__options not implemented.");
        abort();
    } else {
        original_PlotAGraphBox__options(pIndex, pColour_value);
    }
}

function_hook_state_t function_hook_state_DrawAGraphBox__options = HOOK_UNAVAILABLE;
static void(__cdecl*original_DrawAGraphBox__options)(int) = (void(__cdecl*)(int))0x0049a334;
CARM95_HOOK_FUNCTION(original_DrawAGraphBox__options, DrawAGraphBox__options)
void __cdecl DrawAGraphBox__options(int pIndex) {
    LOG_TRACE("(%d)", pIndex);

    (void)pIndex;

    if (function_hook_state_DrawAGraphBox__options == HOOK_ENABLED) {
        assert(0 && "DrawAGraphBox__options not implemented.");
        abort();
    } else {
        original_DrawAGraphBox__options(pIndex);
    }
}

function_hook_state_t function_hook_state_EraseAGraphBox__options = HOOK_UNAVAILABLE;
static void(__cdecl*original_EraseAGraphBox__options)(int) = (void(__cdecl*)(int))0x0049a3e1;
CARM95_HOOK_FUNCTION(original_EraseAGraphBox__options, EraseAGraphBox__options)
void __cdecl EraseAGraphBox__options(int pIndex) {
    LOG_TRACE("(%d)", pIndex);

    (void)pIndex;

    if (function_hook_state_EraseAGraphBox__options == HOOK_ENABLED) {
        assert(0 && "EraseAGraphBox__options not implemented.");
        abort();
    } else {
        original_EraseAGraphBox__options(pIndex);
    }
}

function_hook_state_t function_hook_state_DrawGraphBox = HOOK_UNAVAILABLE;
static void(__cdecl*original_DrawGraphBox)(int, int) = (void(__cdecl*)(int, int))0x0049a2f3;
CARM95_HOOK_FUNCTION(original_DrawGraphBox, DrawGraphBox)
void __cdecl DrawGraphBox(int pCurrent_choice, int pCurrent_mode) {
    LOG_TRACE("(%d, %d)", pCurrent_choice, pCurrent_mode);

    (void)pCurrent_choice;
    (void)pCurrent_mode;

    if (function_hook_state_DrawGraphBox == HOOK_ENABLED) {
        assert(0 && "DrawGraphBox not implemented.");
        abort();
    } else {
        original_DrawGraphBox(pCurrent_choice, pCurrent_mode);
    }
}

function_hook_state_t function_hook_state_DoGraphicsOptions = HOOK_UNAVAILABLE;
static void(__cdecl*original_DoGraphicsOptions)() = (void(__cdecl*)())0x0049b805;
CARM95_HOOK_FUNCTION(original_DoGraphicsOptions, DoGraphicsOptions)
void __cdecl DoGraphicsOptions() {
    static tFlicette flicker_on[14];
    static tFlicette flicker_off[14];
    static tFlicette push[14];
    static tMouse_area mouse_areas[14];
    static tInterface_spec interface_spec;
    LOG_TRACE("()");

    (void)flicker_on;
    (void)flicker_off;
    (void)push;
    (void)mouse_areas;
    (void)interface_spec;

    if (function_hook_state_DoGraphicsOptions == HOOK_ENABLED) {
        assert(0 && "DoGraphicsOptions not implemented.");
        abort();
    } else {
        original_DoGraphicsOptions();
    }
}

function_hook_state_t function_hook_state_CalibrateJoysticks = HOOK_UNAVAILABLE;
static void(__cdecl*original_CalibrateJoysticks)() = (void(__cdecl*)())0x0049bf81;
CARM95_HOOK_FUNCTION(original_CalibrateJoysticks, CalibrateJoysticks)
void __cdecl CalibrateJoysticks() {
    tJoy_calib_stage stage;
    int escaped;
    int joy_value_x;
    int joy_value_y;
    int key;
    int top_left[2];
    int bot_right[2];
    int centre[2];
    int range[2];
    int min[2];
    int i;
    int saved_1x;
    int saved_1y;
    int saved_2x;
    int saved_2y;
    int max;
    char s[256];
    LOG_TRACE("()");

    (void)stage;
    (void)escaped;
    (void)joy_value_x;
    (void)joy_value_y;
    (void)key;
    (void)top_left;
    (void)bot_right;
    (void)centre;
    (void)range;
    (void)min;
    (void)i;
    (void)saved_1x;
    (void)saved_1y;
    (void)saved_2x;
    (void)saved_2y;
    (void)max;
    (void)s;

    if (function_hook_state_CalibrateJoysticks == HOOK_ENABLED) {
        assert(0 && "CalibrateJoysticks not implemented.");
        abort();
    } else {
        original_CalibrateJoysticks();
    }
}

function_hook_state_t function_hook_state_StripControls = HOOK_UNAVAILABLE;
static void(__cdecl*original_StripControls)(unsigned char *) = (void(__cdecl*)(unsigned char *))0x0049c0b4;
CARM95_HOOK_FUNCTION(original_StripControls, StripControls)
void __cdecl StripControls(unsigned char *pStr) {
    int i;
    int len;
    LOG_TRACE("(%p)", pStr);

    (void)pStr;
    (void)i;
    (void)len;

    if (function_hook_state_StripControls == HOOK_ENABLED) {
        assert(0 && "StripControls not implemented.");
        abort();
    } else {
        original_StripControls(pStr);
    }
}

function_hook_state_t function_hook_state_LoadKeyNames = HOOK_UNAVAILABLE;
static void(__cdecl*original_LoadKeyNames)() = (void(__cdecl*)())0x0049bf9b;
CARM95_HOOK_FUNCTION(original_LoadKeyNames, LoadKeyNames)
void __cdecl LoadKeyNames() {
    int i;
    FILE *f;
    tPath_name the_path;
    unsigned char s[256];
    LOG_TRACE("()");

    (void)i;
    (void)f;
    (void)the_path;
    (void)s;

    if (function_hook_state_LoadKeyNames == HOOK_ENABLED) {
        assert(0 && "LoadKeyNames not implemented.");
        abort();
    } else {
        original_LoadKeyNames();
    }
}

function_hook_state_t function_hook_state_DisposeKeyNames = HOOK_UNAVAILABLE;
static void(__cdecl*original_DisposeKeyNames)() = (void(__cdecl*)())0x0049c133;
CARM95_HOOK_FUNCTION(original_DisposeKeyNames, DisposeKeyNames)
void __cdecl DisposeKeyNames() {
    int i;
    LOG_TRACE("()");

    (void)i;

    if (function_hook_state_DisposeKeyNames == HOOK_ENABLED) {
        assert(0 && "DisposeKeyNames not implemented.");
        abort();
    } else {
        original_DisposeKeyNames();
    }
}

function_hook_state_t function_hook_state_SaveOrigKeyMapping = HOOK_UNAVAILABLE;
static void(__cdecl*original_SaveOrigKeyMapping)() = (void(__cdecl*)())0x0049ab5e;
CARM95_HOOK_FUNCTION(original_SaveOrigKeyMapping, SaveOrigKeyMapping)
void __cdecl SaveOrigKeyMapping() {
    LOG_TRACE("()");


    if (function_hook_state_SaveOrigKeyMapping == HOOK_ENABLED) {
        assert(0 && "SaveOrigKeyMapping not implemented.");
        abort();
    } else {
        original_SaveOrigKeyMapping();
    }
}

function_hook_state_t function_hook_state_GetKeyCoords = HOOK_UNAVAILABLE;
static void(__cdecl*original_GetKeyCoords)(int, int *, int *, int *, int *) = (void(__cdecl*)(int, int *, int *, int *, int *))0x0049a8e2;
CARM95_HOOK_FUNCTION(original_GetKeyCoords, GetKeyCoords)
void __cdecl GetKeyCoords(int pIndex, int *pY, int *pName_x, int *pKey_x, int *pEnd_box) {
    int col;
    LOG_TRACE("(%d, %p, %p, %p, %p)", pIndex, pY, pName_x, pKey_x, pEnd_box);

    (void)pIndex;
    (void)pY;
    (void)pName_x;
    (void)pKey_x;
    (void)pEnd_box;
    (void)col;

    if (function_hook_state_GetKeyCoords == HOOK_ENABLED) {
        assert(0 && "GetKeyCoords not implemented.");
        abort();
    } else {
        original_GetKeyCoords(pIndex, pY, pName_x, pKey_x, pEnd_box);
    }
}

function_hook_state_t function_hook_state_SetKeysToDefault = HOOK_UNAVAILABLE;
static void(__cdecl*original_SetKeysToDefault)() = (void(__cdecl*)())0x0049b3f3;
CARM95_HOOK_FUNCTION(original_SetKeysToDefault, SetKeysToDefault)
void __cdecl SetKeysToDefault() {
    FILE *f;
    tPath_name the_path;
    int i;
    LOG_TRACE("()");

    (void)f;
    (void)the_path;
    (void)i;

    if (function_hook_state_SetKeysToDefault == HOOK_ENABLED) {
        assert(0 && "SetKeysToDefault not implemented.");
        abort();
    } else {
        original_SetKeysToDefault();
    }
}

function_hook_state_t function_hook_state_SaveKeyMapping = HOOK_UNAVAILABLE;
static void(__cdecl*original_SaveKeyMapping)() = (void(__cdecl*)())0x0049ab7a;
CARM95_HOOK_FUNCTION(original_SaveKeyMapping, SaveKeyMapping)
void __cdecl SaveKeyMapping() {
    FILE *f;
    tPath_name the_path;
    int i;
    LOG_TRACE("()");

    (void)f;
    (void)the_path;
    (void)i;

    if (function_hook_state_SaveKeyMapping == HOOK_ENABLED) {
        assert(0 && "SaveKeyMapping not implemented.");
        abort();
    } else {
        original_SaveKeyMapping();
    }
}

function_hook_state_t function_hook_state_ChangeKeyMapIndex = HOOK_UNAVAILABLE;
static void(__cdecl*original_ChangeKeyMapIndex)(int) = (void(__cdecl*)(int))0x0049ab3c;
CARM95_HOOK_FUNCTION(original_ChangeKeyMapIndex, ChangeKeyMapIndex)
void __cdecl ChangeKeyMapIndex(int pNew_one) {
    LOG_TRACE("(%d)", pNew_one);

    (void)pNew_one;

    if (function_hook_state_ChangeKeyMapIndex == HOOK_ENABLED) {
        assert(0 && "ChangeKeyMapIndex not implemented.");
        abort();
    } else {
        original_ChangeKeyMapIndex(pNew_one);
    }
}

function_hook_state_t function_hook_state_DrawKeyAssignments = HOOK_UNAVAILABLE;
static void(__cdecl*original_DrawKeyAssignments)(int, int) = (void(__cdecl*)(int, int))0x0049a3fa;
CARM95_HOOK_FUNCTION(original_DrawKeyAssignments, DrawKeyAssignments)
void __cdecl DrawKeyAssignments(int pCurrent_choice, int pCurrent_mode) {
    int i;
    int y;
    int x_coord;
    int y_coord;
    int name_x;
    int key_x;
    int new_key;
    int end_box;
    tDR_font *font_n;
    tDR_font *font_k;
    static int on_radios_last_time;
    LOG_TRACE("(%d, %d)", pCurrent_choice, pCurrent_mode);

    (void)pCurrent_choice;
    (void)pCurrent_mode;
    (void)i;
    (void)y;
    (void)x_coord;
    (void)y_coord;
    (void)name_x;
    (void)key_x;
    (void)new_key;
    (void)end_box;
    (void)font_n;
    (void)font_k;
    (void)on_radios_last_time;

    if (function_hook_state_DrawKeyAssignments == HOOK_ENABLED) {
        assert(0 && "DrawKeyAssignments not implemented.");
        abort();
    } else {
        original_DrawKeyAssignments(pCurrent_choice, pCurrent_mode);
    }
}

function_hook_state_t function_hook_state_KeyAssignLeft = HOOK_UNAVAILABLE;
static int(__cdecl*original_KeyAssignLeft)(int *, int *) = (int(__cdecl*)(int *, int *))0x0049aa3a;
CARM95_HOOK_FUNCTION(original_KeyAssignLeft, KeyAssignLeft)
int __cdecl KeyAssignLeft(int *pCurrent_choice, int *pCurrent_mode) {
    int new_index;
    LOG_TRACE("(%p, %p)", pCurrent_choice, pCurrent_mode);

    (void)pCurrent_choice;
    (void)pCurrent_mode;
    (void)new_index;

    if (function_hook_state_KeyAssignLeft == HOOK_ENABLED) {
        assert(0 && "KeyAssignLeft not implemented.");
        abort();
    } else {
        return original_KeyAssignLeft(pCurrent_choice, pCurrent_mode);
    }
}

function_hook_state_t function_hook_state_KeyAssignRight = HOOK_UNAVAILABLE;
static int(__cdecl*original_KeyAssignRight)(int *, int *) = (int(__cdecl*)(int *, int *))0x0049ac6f;
CARM95_HOOK_FUNCTION(original_KeyAssignRight, KeyAssignRight)
int __cdecl KeyAssignRight(int *pCurrent_choice, int *pCurrent_mode) {
    int new_index;
    LOG_TRACE("(%p, %p)", pCurrent_choice, pCurrent_mode);

    (void)pCurrent_choice;
    (void)pCurrent_mode;
    (void)new_index;

    if (function_hook_state_KeyAssignRight == HOOK_ENABLED) {
        assert(0 && "KeyAssignRight not implemented.");
        abort();
    } else {
        return original_KeyAssignRight(pCurrent_choice, pCurrent_mode);
    }
}

function_hook_state_t function_hook_state_KeyAssignUp = HOOK_UNAVAILABLE;
static int(__cdecl*original_KeyAssignUp)(int *, int *) = (int(__cdecl*)(int *, int *))0x0049ad71;
CARM95_HOOK_FUNCTION(original_KeyAssignUp, KeyAssignUp)
int __cdecl KeyAssignUp(int *pCurrent_choice, int *pCurrent_mode) {
    LOG_TRACE("(%p, %p)", pCurrent_choice, pCurrent_mode);

    (void)pCurrent_choice;
    (void)pCurrent_mode;

    if (function_hook_state_KeyAssignUp == HOOK_ENABLED) {
        assert(0 && "KeyAssignUp not implemented.");
        abort();
    } else {
        return original_KeyAssignUp(pCurrent_choice, pCurrent_mode);
    }
}

function_hook_state_t function_hook_state_KeyAssignDown = HOOK_UNAVAILABLE;
static int(__cdecl*original_KeyAssignDown)(int *, int *) = (int(__cdecl*)(int *, int *))0x0049ae9b;
CARM95_HOOK_FUNCTION(original_KeyAssignDown, KeyAssignDown)
int __cdecl KeyAssignDown(int *pCurrent_choice, int *pCurrent_mode) {
    LOG_TRACE("(%p, %p)", pCurrent_choice, pCurrent_mode);

    (void)pCurrent_choice;
    (void)pCurrent_mode;

    if (function_hook_state_KeyAssignDown == HOOK_ENABLED) {
        assert(0 && "KeyAssignDown not implemented.");
        abort();
    } else {
        return original_KeyAssignDown(pCurrent_choice, pCurrent_mode);
    }
}

function_hook_state_t function_hook_state_KeyAssignGoAhead = HOOK_UNAVAILABLE;
static int(__cdecl*original_KeyAssignGoAhead)(int *, int *) = (int(__cdecl*)(int *, int *))0x0049afa5;
CARM95_HOOK_FUNCTION(original_KeyAssignGoAhead, KeyAssignGoAhead)
int __cdecl KeyAssignGoAhead(int *pCurrent_choice, int *pCurrent_mode) {
    int key;
    int i;
    int j;
    int y;
    int new_index;
    int disallowed;
    int name_x;
    int key_x;
    int end_box;
    tDR_font *font;
    LOG_TRACE("(%p, %p)", pCurrent_choice, pCurrent_mode);

    (void)pCurrent_choice;
    (void)pCurrent_mode;
    (void)key;
    (void)i;
    (void)j;
    (void)y;
    (void)new_index;
    (void)disallowed;
    (void)name_x;
    (void)key_x;
    (void)end_box;
    (void)font;

    if (function_hook_state_KeyAssignGoAhead == HOOK_ENABLED) {
        assert(0 && "KeyAssignGoAhead not implemented.");
        abort();
    } else {
        return original_KeyAssignGoAhead(pCurrent_choice, pCurrent_mode);
    }
}

function_hook_state_t function_hook_state_MouseyClickBastard = HOOK_UNAVAILABLE;
static int(__cdecl*original_MouseyClickBastard)(int *, int *, int, int) = (int(__cdecl*)(int *, int *, int, int))0x0049b4bd;
CARM95_HOOK_FUNCTION(original_MouseyClickBastard, MouseyClickBastard)
int __cdecl MouseyClickBastard(int *pCurrent_choice, int *pCurrent_mode, int pX_offset, int pY_offset) {
    int i;
    int x_coord;
    int y_coord;
    LOG_TRACE("(%p, %p, %d, %d)", pCurrent_choice, pCurrent_mode, pX_offset, pY_offset);

    (void)pCurrent_choice;
    (void)pCurrent_mode;
    (void)pX_offset;
    (void)pY_offset;
    (void)i;
    (void)x_coord;
    (void)y_coord;

    if (function_hook_state_MouseyClickBastard == HOOK_ENABLED) {
        assert(0 && "MouseyClickBastard not implemented.");
        abort();
    } else {
        return original_MouseyClickBastard(pCurrent_choice, pCurrent_mode, pX_offset, pY_offset);
    }
}

function_hook_state_t function_hook_state_DrawInitialKMRadios = HOOK_UNAVAILABLE;
static void(__cdecl*original_DrawInitialKMRadios)() = (void(__cdecl*)())0x0049b56c;
CARM95_HOOK_FUNCTION(original_DrawInitialKMRadios, DrawInitialKMRadios)
void __cdecl DrawInitialKMRadios() {
    int i;
    LOG_TRACE("()");

    (void)i;

    if (function_hook_state_DrawInitialKMRadios == HOOK_ENABLED) {
        assert(0 && "DrawInitialKMRadios not implemented.");
        abort();
    } else {
        original_DrawInitialKMRadios();
    }
}

function_hook_state_t function_hook_state_DoControlOptions = HOOK_UNAVAILABLE;
static void(__cdecl*original_DoControlOptions)() = (void(__cdecl*)())0x0049be2c;
CARM95_HOOK_FUNCTION(original_DoControlOptions, DoControlOptions)
void __cdecl DoControlOptions() {
    static tFlicette flicker_on[4];
    static tFlicette flicker_off[4];
    static tFlicette push[4];
    static tMouse_area mouse_areas[5];
    static tInterface_spec interface_spec;
    int result;
    int swap_font_1;
    int swap_font_2;
    int swap_font_3;
    int second_time_around;
    int orig_key_map_index;
    LOG_TRACE("()");

    (void)flicker_on;
    (void)flicker_off;
    (void)push;
    (void)mouse_areas;
    (void)interface_spec;
    (void)result;
    (void)swap_font_1;
    (void)swap_font_2;
    (void)swap_font_3;
    (void)second_time_around;
    (void)orig_key_map_index;

    if (function_hook_state_DoControlOptions == HOOK_ENABLED) {
        assert(0 && "DoControlOptions not implemented.");
        abort();
    } else {
        original_DoControlOptions();
    }
}

function_hook_state_t function_hook_state_LoadSoundOptionsData = HOOK_UNAVAILABLE;
static void(__cdecl*original_LoadSoundOptionsData)() = (void(__cdecl*)())0x0049b5b2;
CARM95_HOOK_FUNCTION(original_LoadSoundOptionsData, LoadSoundOptionsData)
void __cdecl LoadSoundOptionsData() {
    LOG_TRACE("()");


    if (function_hook_state_LoadSoundOptionsData == HOOK_ENABLED) {
        assert(0 && "LoadSoundOptionsData not implemented.");
        abort();
    } else {
        original_LoadSoundOptionsData();
    }
}

function_hook_state_t function_hook_state_FreeSoundOptionsData = HOOK_UNAVAILABLE;
static void(__cdecl*original_FreeSoundOptionsData)() = (void(__cdecl*)())0x0049b5e6;
CARM95_HOOK_FUNCTION(original_FreeSoundOptionsData, FreeSoundOptionsData)
void __cdecl FreeSoundOptionsData() {
    LOG_TRACE("()");


    if (function_hook_state_FreeSoundOptionsData == HOOK_ENABLED) {
        assert(0 && "FreeSoundOptionsData not implemented.");
        abort();
    } else {
        original_FreeSoundOptionsData();
    }
}

function_hook_state_t function_hook_state_DrawDisabledOptions = HOOK_UNAVAILABLE;
static void(__cdecl*original_DrawDisabledOptions)() = (void(__cdecl*)())0x0049b5ff;
CARM95_HOOK_FUNCTION(original_DrawDisabledOptions, DrawDisabledOptions)
void __cdecl DrawDisabledOptions() {
    br_pixelmap *image;
    LOG_TRACE("()");

    (void)image;

    if (function_hook_state_DrawDisabledOptions == HOOK_ENABLED) {
        assert(0 && "DrawDisabledOptions not implemented.");
        abort();
    } else {
        original_DrawDisabledOptions();
    }
}

function_hook_state_t function_hook_state_DoOptions = HOOK_UNAVAILABLE;
static void(__cdecl*original_DoOptions)() = (void(__cdecl*)())0x0049b705;
CARM95_HOOK_FUNCTION(original_DoOptions, DoOptions)
void __cdecl DoOptions() {
    static tFlicette flicker_on[4];
    static tFlicette flicker_off[4];
    static tFlicette push[4];
    static tMouse_area mouse_areas[4];
    static tInterface_spec interface_spec;
    int result;
    LOG_TRACE("()");

    (void)flicker_on;
    (void)flicker_off;
    (void)push;
    (void)mouse_areas;
    (void)interface_spec;
    (void)result;

    if (function_hook_state_DoOptions == HOOK_ENABLED) {
        assert(0 && "DoOptions not implemented.");
        abort();
    } else {
        original_DoOptions();
    }
}

