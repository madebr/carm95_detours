#include "options.h"

#include "harness/trace.h"

#include "carm95_hooks.h"

#include <stdio.h>
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

void DrawDial(int pWhich_one, int pWhich_stage) {
    LOG_TRACE("(%d, %d)", pWhich_one, pWhich_stage);

    (void)pWhich_one;
    (void)pWhich_stage;

    NOT_IMPLEMENTED();
}

void MoveDialFromTo(int pWhich_one, int pOld_stage, int pNew_stage) {
    tS32 time_diff;
    tU32 start_time;
    LOG_TRACE("(%d, %d, %d)", pWhich_one, pOld_stage, pNew_stage);

    (void)pWhich_one;
    (void)pOld_stage;
    (void)pNew_stage;
    (void)time_diff;
    (void)start_time;

    NOT_IMPLEMENTED();
}

void SoundOptionsStart() {
    LOG_TRACE("()");


    NOT_IMPLEMENTED();
}

int SoundOptionsDone(int pCurrent_choice, int pCurrent_mode, int pGo_ahead, int pEscaped, int pTimed_out) {
    LOG_TRACE("(%d, %d, %d, %d, %d)", pCurrent_choice, pCurrent_mode, pGo_ahead, pEscaped, pTimed_out);

    (void)pCurrent_choice;
    (void)pCurrent_mode;
    (void)pGo_ahead;
    (void)pEscaped;
    (void)pTimed_out;

    NOT_IMPLEMENTED();
}

int SoundOptionsLeft(int *pCurrent_choice, int *pCurrent_mode) {
    int old_value;
    int *the_value;
    LOG_TRACE("(%p, %p)", pCurrent_choice, pCurrent_mode);

    (void)pCurrent_choice;
    (void)pCurrent_mode;
    (void)old_value;
    (void)the_value;

    NOT_IMPLEMENTED();
}

int SoundOptionsRight(int *pCurrent_choice, int *pCurrent_mode) {
    int old_value;
    int *the_value;
    LOG_TRACE("(%p, %p)", pCurrent_choice, pCurrent_mode);

    (void)pCurrent_choice;
    (void)pCurrent_mode;
    (void)old_value;
    (void)the_value;

    NOT_IMPLEMENTED();
}

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

    NOT_IMPLEMENTED();
}

static void(*original_DoSoundOptions)() = (void(*)())0x0049b7bf;
CARM95_HOOK_FUNCTION(original_DoSoundOptions, DoSoundOptions)
void DoSoundOptions() {
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

    original_DoSoundOptions();
}

static void(*original_GetGraphicsOptions)() = (void(*)())0x0049b87f;
CARM95_HOOK_FUNCTION(original_GetGraphicsOptions, GetGraphicsOptions)
void GetGraphicsOptions() {
    int value;
    br_scalar br_value;
    LOG_TRACE("()");

    (void)value;
    (void)br_value;

    original_GetGraphicsOptions();
}

static void(*original_SetGraphicsOptions)() = (void(*)())0x0049bb74;
CARM95_HOOK_FUNCTION(original_SetGraphicsOptions, SetGraphicsOptions)
void SetGraphicsOptions() {
    LOG_TRACE("()");


    original_SetGraphicsOptions();
}

static void(*original_PlayRadioOn2)(int, int, ...) = (void(*)(int, int, ...))0x00499efe;
CARM95_HOOK_FUNCTION(original_PlayRadioOn2, PlayRadioOn2)
void PlayRadioOn2(int pIndex, int pValue) {
    LOG_TRACE("(%d, %d)", pIndex, pValue);

    (void)pIndex;
    (void)pValue;

    original_PlayRadioOn2(pIndex, pValue);
}

static void(*original_PlayRadioOff2)(int, int, ...) = (void(*)(int, int, ...))0x0049a05d;
CARM95_HOOK_FUNCTION(original_PlayRadioOff2, PlayRadioOff2)
void PlayRadioOff2(int pIndex, int pValue) {
    LOG_TRACE("(%d, %d)", pIndex, pValue);

    (void)pIndex;
    (void)pValue;

    original_PlayRadioOff2(pIndex, pValue);
}

static void(*original_PlayRadioOn__options)(int, int, ...) = (void(*)(int, int, ...))0x00499feb;
CARM95_HOOK_FUNCTION(original_PlayRadioOn__options, PlayRadioOn__options)
void PlayRadioOn__options(int pIndex, int pValue) {
    LOG_TRACE("(%d, %d)", pIndex, pValue);

    (void)pIndex;
    (void)pValue;

    original_PlayRadioOn__options(pIndex, pValue);
}

static void(*original_PlayRadioOff__options)(int, int, ...) = (void(*)(int, int, ...))0x0049a024;
CARM95_HOOK_FUNCTION(original_PlayRadioOff__options, PlayRadioOff__options)
void PlayRadioOff__options(int pIndex, int pValue) {
    LOG_TRACE("(%d, %d)", pIndex, pValue);

    (void)pIndex;
    (void)pValue;

    original_PlayRadioOff__options(pIndex, pValue);
}

static void(*original_DrawInitialRadios)() = (void(*)())0x00499e9b;
CARM95_HOOK_FUNCTION(original_DrawInitialRadios, DrawInitialRadios)
void DrawInitialRadios() {
    int i;
    LOG_TRACE("()");

    (void)i;

    original_DrawInitialRadios();
}

static void(*original_RadioChanged)(int, int, ...) = (void(*)(int, int, ...))0x00499fa8;
CARM95_HOOK_FUNCTION(original_RadioChanged, RadioChanged)
void RadioChanged(int pIndex, int pNew_value) {
    LOG_TRACE("(%d, %d)", pIndex, pNew_value);

    (void)pIndex;
    (void)pNew_value;

    original_RadioChanged(pIndex, pNew_value);
}

static int(*original_GraphOptLeft)(int *, int *, ...) = (int(*)(int *, int *, ...))0x00499f34;
CARM95_HOOK_FUNCTION(original_GraphOptLeft, GraphOptLeft)
int GraphOptLeft(int *pCurrent_choice, int *pCurrent_mode) {
    int new_value;
    LOG_TRACE("(%p, %p)", pCurrent_choice, pCurrent_mode);

    (void)pCurrent_choice;
    (void)pCurrent_mode;
    (void)new_value;

    return original_GraphOptLeft(pCurrent_choice, pCurrent_mode);
}

static int(*original_GraphOptRight)(int *, int *, ...) = (int(*)(int *, int *, ...))0x0049a093;
CARM95_HOOK_FUNCTION(original_GraphOptRight, GraphOptRight)
int GraphOptRight(int *pCurrent_choice, int *pCurrent_mode) {
    int new_value;
    LOG_TRACE("(%p, %p)", pCurrent_choice, pCurrent_mode);

    (void)pCurrent_choice;
    (void)pCurrent_mode;
    (void)new_value;

    return original_GraphOptRight(pCurrent_choice, pCurrent_mode);
}

static int(*original_GraphOptUp)(int *, int *, ...) = (int(*)(int *, int *, ...))0x0049a109;
CARM95_HOOK_FUNCTION(original_GraphOptUp, GraphOptUp)
int GraphOptUp(int *pCurrent_choice, int *pCurrent_mode) {
    LOG_TRACE("(%p, %p)", pCurrent_choice, pCurrent_mode);

    (void)pCurrent_choice;
    (void)pCurrent_mode;

    return original_GraphOptUp(pCurrent_choice, pCurrent_mode);
}

static int(*original_GraphOptDown)(int *, int *, ...) = (int(*)(int *, int *, ...))0x0049a19b;
CARM95_HOOK_FUNCTION(original_GraphOptDown, GraphOptDown)
int GraphOptDown(int *pCurrent_choice, int *pCurrent_mode) {
    LOG_TRACE("(%p, %p)", pCurrent_choice, pCurrent_mode);

    (void)pCurrent_choice;
    (void)pCurrent_mode;

    return original_GraphOptDown(pCurrent_choice, pCurrent_mode);
}

static int(*original_RadioClick)(int *, int *, int, int, ...) = (int(*)(int *, int *, int, int, ...))0x0049a22d;
CARM95_HOOK_FUNCTION(original_RadioClick, RadioClick)
int RadioClick(int *pCurrent_choice, int *pCurrent_mode, int pX_offset, int pY_offset) {
    int i;
    LOG_TRACE("(%p, %p, %d, %d)", pCurrent_choice, pCurrent_mode, pX_offset, pY_offset);

    (void)pCurrent_choice;
    (void)pCurrent_mode;
    (void)pX_offset;
    (void)pY_offset;
    (void)i;

    return original_RadioClick(pCurrent_choice, pCurrent_mode, pX_offset, pY_offset);
}

static int(*original_GraphOptGoAhead)(int *, int *, ...) = (int(*)(int *, int *, ...))0x0049a2d1;
CARM95_HOOK_FUNCTION(original_GraphOptGoAhead, GraphOptGoAhead)
int GraphOptGoAhead(int *pCurrent_choice, int *pCurrent_mode) {
    LOG_TRACE("(%p, %p)", pCurrent_choice, pCurrent_mode);

    (void)pCurrent_choice;
    (void)pCurrent_mode;

    return original_GraphOptGoAhead(pCurrent_choice, pCurrent_mode);
}

static void(*original_PlotAGraphBox__options)(int, int, ...) = (void(*)(int, int, ...))0x0049a34d;
CARM95_HOOK_FUNCTION(original_PlotAGraphBox__options, PlotAGraphBox__options)
void PlotAGraphBox__options(int pIndex, int pColour_value) {
    LOG_TRACE("(%d, %d)", pIndex, pColour_value);

    (void)pIndex;
    (void)pColour_value;

    original_PlotAGraphBox__options(pIndex, pColour_value);
}

static void(*original_DrawAGraphBox__options)(int, ...) = (void(*)(int, ...))0x0049a334;
CARM95_HOOK_FUNCTION(original_DrawAGraphBox__options, DrawAGraphBox__options)
void DrawAGraphBox__options(int pIndex) {
    LOG_TRACE("(%d)", pIndex);

    (void)pIndex;

    original_DrawAGraphBox__options(pIndex);
}

static void(*original_EraseAGraphBox__options)(int, ...) = (void(*)(int, ...))0x0049a3e1;
CARM95_HOOK_FUNCTION(original_EraseAGraphBox__options, EraseAGraphBox__options)
void EraseAGraphBox__options(int pIndex) {
    LOG_TRACE("(%d)", pIndex);

    (void)pIndex;

    original_EraseAGraphBox__options(pIndex);
}

static void(*original_DrawGraphBox)(int, int, ...) = (void(*)(int, int, ...))0x0049a2f3;
CARM95_HOOK_FUNCTION(original_DrawGraphBox, DrawGraphBox)
void DrawGraphBox(int pCurrent_choice, int pCurrent_mode) {
    LOG_TRACE("(%d, %d)", pCurrent_choice, pCurrent_mode);

    (void)pCurrent_choice;
    (void)pCurrent_mode;

    original_DrawGraphBox(pCurrent_choice, pCurrent_mode);
}

static void(*original_DoGraphicsOptions)() = (void(*)())0x0049b805;
CARM95_HOOK_FUNCTION(original_DoGraphicsOptions, DoGraphicsOptions)
void DoGraphicsOptions() {
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

    original_DoGraphicsOptions();
}

static void(*original_CalibrateJoysticks)() = (void(*)())0x0049bf81;
CARM95_HOOK_FUNCTION(original_CalibrateJoysticks, CalibrateJoysticks)
void CalibrateJoysticks() {
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

    original_CalibrateJoysticks();
}

static void(*original_StripControls)(unsigned char *, ...) = (void(*)(unsigned char *, ...))0x0049c0b4;
CARM95_HOOK_FUNCTION(original_StripControls, StripControls)
void StripControls(unsigned char *pStr) {
    int i;
    int len;
    LOG_TRACE("(%p)", pStr);

    (void)pStr;
    (void)i;
    (void)len;

    original_StripControls(pStr);
}

static void(*original_LoadKeyNames)() = (void(*)())0x0049bf9b;
CARM95_HOOK_FUNCTION(original_LoadKeyNames, LoadKeyNames)
void LoadKeyNames() {
    int i;
    FILE *f;
    tPath_name the_path;
    unsigned char s[256];
    LOG_TRACE("()");

    (void)i;
    (void)f;
    (void)the_path;
    (void)s;

    original_LoadKeyNames();
}

static void(*original_DisposeKeyNames)() = (void(*)())0x0049c133;
CARM95_HOOK_FUNCTION(original_DisposeKeyNames, DisposeKeyNames)
void DisposeKeyNames() {
    int i;
    LOG_TRACE("()");

    (void)i;

    original_DisposeKeyNames();
}

static void(*original_SaveOrigKeyMapping)() = (void(*)())0x0049ab5e;
CARM95_HOOK_FUNCTION(original_SaveOrigKeyMapping, SaveOrigKeyMapping)
void SaveOrigKeyMapping() {
    LOG_TRACE("()");


    original_SaveOrigKeyMapping();
}

static void(*original_GetKeyCoords)(int, int *, int *, int *, int *, ...) = (void(*)(int, int *, int *, int *, int *, ...))0x0049a8e2;
CARM95_HOOK_FUNCTION(original_GetKeyCoords, GetKeyCoords)
void GetKeyCoords(int pIndex, int *pY, int *pName_x, int *pKey_x, int *pEnd_box) {
    int col;
    LOG_TRACE("(%d, %p, %p, %p, %p)", pIndex, pY, pName_x, pKey_x, pEnd_box);

    (void)pIndex;
    (void)pY;
    (void)pName_x;
    (void)pKey_x;
    (void)pEnd_box;
    (void)col;

    original_GetKeyCoords(pIndex, pY, pName_x, pKey_x, pEnd_box);
}

static void(*original_SetKeysToDefault)() = (void(*)())0x0049b3f3;
CARM95_HOOK_FUNCTION(original_SetKeysToDefault, SetKeysToDefault)
void SetKeysToDefault() {
    FILE *f;
    tPath_name the_path;
    int i;
    LOG_TRACE("()");

    (void)f;
    (void)the_path;
    (void)i;

    original_SetKeysToDefault();
}

static void(*original_SaveKeyMapping)() = (void(*)())0x0049ab7a;
CARM95_HOOK_FUNCTION(original_SaveKeyMapping, SaveKeyMapping)
void SaveKeyMapping() {
    FILE *f;
    tPath_name the_path;
    int i;
    LOG_TRACE("()");

    (void)f;
    (void)the_path;
    (void)i;

    original_SaveKeyMapping();
}

static void(*original_ChangeKeyMapIndex)(int, ...) = (void(*)(int, ...))0x0049ab3c;
CARM95_HOOK_FUNCTION(original_ChangeKeyMapIndex, ChangeKeyMapIndex)
void ChangeKeyMapIndex(int pNew_one) {
    LOG_TRACE("(%d)", pNew_one);

    (void)pNew_one;

    original_ChangeKeyMapIndex(pNew_one);
}

static void(*original_DrawKeyAssignments)(int, int, ...) = (void(*)(int, int, ...))0x0049a3fa;
CARM95_HOOK_FUNCTION(original_DrawKeyAssignments, DrawKeyAssignments)
void DrawKeyAssignments(int pCurrent_choice, int pCurrent_mode) {
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

    original_DrawKeyAssignments(pCurrent_choice, pCurrent_mode);
}

static int(*original_KeyAssignLeft)(int *, int *, ...) = (int(*)(int *, int *, ...))0x0049aa3a;
CARM95_HOOK_FUNCTION(original_KeyAssignLeft, KeyAssignLeft)
int KeyAssignLeft(int *pCurrent_choice, int *pCurrent_mode) {
    int new_index;
    LOG_TRACE("(%p, %p)", pCurrent_choice, pCurrent_mode);

    (void)pCurrent_choice;
    (void)pCurrent_mode;
    (void)new_index;

    return original_KeyAssignLeft(pCurrent_choice, pCurrent_mode);
}

static int(*original_KeyAssignRight)(int *, int *, ...) = (int(*)(int *, int *, ...))0x0049ac6f;
CARM95_HOOK_FUNCTION(original_KeyAssignRight, KeyAssignRight)
int KeyAssignRight(int *pCurrent_choice, int *pCurrent_mode) {
    int new_index;
    LOG_TRACE("(%p, %p)", pCurrent_choice, pCurrent_mode);

    (void)pCurrent_choice;
    (void)pCurrent_mode;
    (void)new_index;

    return original_KeyAssignRight(pCurrent_choice, pCurrent_mode);
}

static int(*original_KeyAssignUp)(int *, int *, ...) = (int(*)(int *, int *, ...))0x0049ad71;
CARM95_HOOK_FUNCTION(original_KeyAssignUp, KeyAssignUp)
int KeyAssignUp(int *pCurrent_choice, int *pCurrent_mode) {
    LOG_TRACE("(%p, %p)", pCurrent_choice, pCurrent_mode);

    (void)pCurrent_choice;
    (void)pCurrent_mode;

    return original_KeyAssignUp(pCurrent_choice, pCurrent_mode);
}

static int(*original_KeyAssignDown)(int *, int *, ...) = (int(*)(int *, int *, ...))0x0049ae9b;
CARM95_HOOK_FUNCTION(original_KeyAssignDown, KeyAssignDown)
int KeyAssignDown(int *pCurrent_choice, int *pCurrent_mode) {
    LOG_TRACE("(%p, %p)", pCurrent_choice, pCurrent_mode);

    (void)pCurrent_choice;
    (void)pCurrent_mode;

    return original_KeyAssignDown(pCurrent_choice, pCurrent_mode);
}

static int(*original_KeyAssignGoAhead)(int *, int *, ...) = (int(*)(int *, int *, ...))0x0049afa5;
CARM95_HOOK_FUNCTION(original_KeyAssignGoAhead, KeyAssignGoAhead)
int KeyAssignGoAhead(int *pCurrent_choice, int *pCurrent_mode) {
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

    return original_KeyAssignGoAhead(pCurrent_choice, pCurrent_mode);
}

static int(*original_MouseyClickBastard)(int *, int *, int, int, ...) = (int(*)(int *, int *, int, int, ...))0x0049b4bd;
CARM95_HOOK_FUNCTION(original_MouseyClickBastard, MouseyClickBastard)
int MouseyClickBastard(int *pCurrent_choice, int *pCurrent_mode, int pX_offset, int pY_offset) {
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

    return original_MouseyClickBastard(pCurrent_choice, pCurrent_mode, pX_offset, pY_offset);
}

static void(*original_DrawInitialKMRadios)() = (void(*)())0x0049b56c;
CARM95_HOOK_FUNCTION(original_DrawInitialKMRadios, DrawInitialKMRadios)
void DrawInitialKMRadios() {
    int i;
    LOG_TRACE("()");

    (void)i;

    original_DrawInitialKMRadios();
}

static void(*original_DoControlOptions)() = (void(*)())0x0049be2c;
CARM95_HOOK_FUNCTION(original_DoControlOptions, DoControlOptions)
void DoControlOptions() {
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

    original_DoControlOptions();
}

static void(*original_LoadSoundOptionsData)() = (void(*)())0x0049b5b2;
CARM95_HOOK_FUNCTION(original_LoadSoundOptionsData, LoadSoundOptionsData)
void LoadSoundOptionsData() {
    LOG_TRACE("()");


    original_LoadSoundOptionsData();
}

static void(*original_FreeSoundOptionsData)() = (void(*)())0x0049b5e6;
CARM95_HOOK_FUNCTION(original_FreeSoundOptionsData, FreeSoundOptionsData)
void FreeSoundOptionsData() {
    LOG_TRACE("()");


    original_FreeSoundOptionsData();
}

static void(*original_DrawDisabledOptions)() = (void(*)())0x0049b5ff;
CARM95_HOOK_FUNCTION(original_DrawDisabledOptions, DrawDisabledOptions)
void DrawDisabledOptions() {
    br_pixelmap *image;
    LOG_TRACE("()");

    (void)image;

    original_DrawDisabledOptions();
}

static void(*original_DoOptions)() = (void(*)())0x0049b705;
CARM95_HOOK_FUNCTION(original_DoOptions, DoOptions)
void DoOptions() {
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

    original_DoOptions();
}

