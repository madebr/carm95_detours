#include "displays.h"

#include "harness/trace.h"

#include "carm95_hooks.h"

int * hookvar_gLast_fancy_index  = (void*)0x00521678;
 // Suffix added to avoid duplicate symbol
int * hookvar_gLast_credit_headup__displays  = (void*)0x0052167c;
int * hookvar_gLast_time_credit_headup  = (void*)0x00521680;
tDR_font ** hookvar_gCached_font  = (void*)0x00521684;
br_font *(* hookvar_gBR_fonts )[4] = (void*)0x00541598;
tQueued_headup(* hookvar_gQueued_headups )[4] = (void*)0x00541160;
int(* hookvar_gOld_times )[10] = (void*)0x00544e30;
#if 0
int * hookvar_gLast_fancy_headup ;
#endif
tU32 * hookvar_gLast_time_earn_time  = (void*)0x00541594;
tU32 * hookvar_gLast_centre_headup  = (void*)0x005415a8;
tU32 * hookvar_gLast_fancy_time  = (void*)0x005415ac;
int * hookvar_gQueued_headup_count  = (void*)0x00541158;
tU32 * hookvar_gLast_earn_time  = (void*)0x0054114c;
#if 0
tU32 * hookvar_gLast_time_credit_amount ;
#endif
int * hookvar_gLast_credit_amount  = (void*)0x00541150;
tHeadup(* hookvar_gHeadups )[15] = (void*)0x0053fdd8;
int * hookvar_gLaps_headup  = (void*)0x00544e60;
int * hookvar_gCar_kill_count_headup  = (void*)0x00544e68;
int * hookvar_gTimer_headup  = (void*)0x00544e5c;
int * hookvar_gTime_awarded_headup  = (void*)0x00544e6c;
int * hookvar_gPed_kill_count_headup  = (void*)0x00544e64;
int * hookvar_gDim_amount  = (void*)0x00544eec;
br_pixelmap *(* hookvar_gHeadup_images )[31] = (void*)0x00544e70;
int * hookvar_gNet_cash_headup  = (void*)0x00544e58;
int * hookvar_gNet_ped_headup  = (void*)0x00544e1c;
#if 0
int * hookvar_gCredits_lost_headup ;
#endif
int * hookvar_gCredits_won_headup  = (void*)0x00544e20;

static void(__cdecl*original_GetTimerString)(char *, int) = (void(__cdecl*)(char *, int))0x004c4030;
CARM95_HOOK_FUNCTION(original_GetTimerString, GetTimerString)
void __cdecl GetTimerString(char *pStr, int pFudge_colon) {
    LOG_TRACE("(\"%s\", %d)", pStr, pFudge_colon);

    (void)pStr;
    (void)pFudge_colon;

    original_GetTimerString(pStr, pFudge_colon);
}

static void(__cdecl*original_InitHeadups)() = (void(__cdecl*)())0x004c4053;
CARM95_HOOK_FUNCTION(original_InitHeadups, InitHeadups)
void __cdecl InitHeadups() {
    int i;
    LOG_TRACE("()");

    (void)i;

    original_InitHeadups();
}

static void(__cdecl*original_ClearHeadup)(int) = (void(__cdecl*)(int))0x004c40c1;
CARM95_HOOK_FUNCTION(original_ClearHeadup, ClearHeadup)
void __cdecl ClearHeadup(int pIndex) {
    LOG_TRACE("(%d)", pIndex);

    (void)pIndex;

    original_ClearHeadup(pIndex);
}

static void(__cdecl*original_ClearHeadupSlot)(int) = (void(__cdecl*)(int))0x004c40e6;
CARM95_HOOK_FUNCTION(original_ClearHeadupSlot, ClearHeadupSlot)
void __cdecl ClearHeadupSlot(int pSlot_index) {
    int i;
    tHeadup *the_headup;
    LOG_TRACE("(%d)", pSlot_index);

    (void)pSlot_index;
    (void)i;
    (void)the_headup;

    original_ClearHeadupSlot(pSlot_index);
}

static void(__cdecl*original_ClearHeadups)() = (void(__cdecl*)())0x004c414c;
CARM95_HOOK_FUNCTION(original_ClearHeadups, ClearHeadups)
void __cdecl ClearHeadups() {
    int i;
    LOG_TRACE("()");

    (void)i;

    original_ClearHeadups();
}

static int(__cdecl*original_HeadupActive)(int) = (int(__cdecl*)(int))0x004c421d;
CARM95_HOOK_FUNCTION(original_HeadupActive, HeadupActive)
int __cdecl HeadupActive(int pIndex) {
    LOG_TRACE("(%d)", pIndex);

    (void)pIndex;

    return original_HeadupActive(pIndex);
}

static void(__cdecl*original_DRPixelmapText)(br_pixelmap *, int, int, tDR_font *, char *, int) = (void(__cdecl*)(br_pixelmap *, int, int, tDR_font *, char *, int))0x004c4256;
CARM95_HOOK_FUNCTION(original_DRPixelmapText, DRPixelmapText)
void __cdecl DRPixelmapText(br_pixelmap *pPixelmap, int pX, int pY, tDR_font *pFont, char *pText, int pRight_edge) {
    int i;
    int x;
    int len;
    int chr;
    int ch_width;
    unsigned char *ch;
    LOG_TRACE("(%p, %d, %d, %p, \"%s\", %d)", pPixelmap, pX, pY, pFont, pText, pRight_edge);

    (void)pPixelmap;
    (void)pX;
    (void)pY;
    (void)pFont;
    (void)pText;
    (void)pRight_edge;
    (void)i;
    (void)x;
    (void)len;
    (void)chr;
    (void)ch_width;
    (void)ch;

    original_DRPixelmapText(pPixelmap, pX, pY, pFont, pText, pRight_edge);
}

static void(__cdecl*original_DRPixelmapCleverText2)(br_pixelmap *, int, int, tDR_font *, signed char *, int) = (void(__cdecl*)(br_pixelmap *, int, int, tDR_font *, signed char *, int))0x004c43cf;
CARM95_HOOK_FUNCTION(original_DRPixelmapCleverText2, DRPixelmapCleverText2)
void __cdecl DRPixelmapCleverText2(br_pixelmap *pPixelmap, int pX, int pY, tDR_font *pFont, signed char *pText, int pRight_edge) {
    int i;
    int x;
    int len;
    int chr;
    int ch_width;
    unsigned char *ch;
    tDR_font *new_font;
    LOG_TRACE("(%p, %d, %d, %p, %p, %d)", pPixelmap, pX, pY, pFont, pText, pRight_edge);

    (void)pPixelmap;
    (void)pX;
    (void)pY;
    (void)pFont;
    (void)pText;
    (void)pRight_edge;
    (void)i;
    (void)x;
    (void)len;
    (void)chr;
    (void)ch_width;
    (void)ch;
    (void)new_font;

    original_DRPixelmapCleverText2(pPixelmap, pX, pY, pFont, pText, pRight_edge);
}

void DeviouslyDimRectangle(br_pixelmap *pPixelmap, int pLeft, int pTop, int pRight, int pBottom, int pKnock_out_corners) {
    LOG_TRACE("(%p, %d, %d, %d, %d, %d)", pPixelmap, pLeft, pTop, pRight, pBottom, pKnock_out_corners);

    (void)pPixelmap;
    (void)pLeft;
    (void)pTop;
    (void)pRight;
    (void)pBottom;
    (void)pKnock_out_corners;

    NOT_IMPLEMENTED();
}

static void(__cdecl*original_DimRectangle)(br_pixelmap *, int, int, int, int, int) = (void(__cdecl*)(br_pixelmap *, int, int, int, int, int))0x004c4604;
CARM95_HOOK_FUNCTION(original_DimRectangle, DimRectangle)
void __cdecl DimRectangle(br_pixelmap *pPixelmap, int pLeft, int pTop, int pRight, int pBottom, int pKnock_out_corners) {
    tU8 *ptr;
    tU8 *depth_table_ptr;
    tU8 *right_ptr;
    int x;
    int y;
    int line_skip;
    int width;
    LOG_TRACE("(%p, %d, %d, %d, %d, %d)", pPixelmap, pLeft, pTop, pRight, pBottom, pKnock_out_corners);

    (void)pPixelmap;
    (void)pLeft;
    (void)pTop;
    (void)pRight;
    (void)pBottom;
    (void)pKnock_out_corners;
    (void)ptr;
    (void)depth_table_ptr;
    (void)right_ptr;
    (void)x;
    (void)y;
    (void)line_skip;
    (void)width;

    original_DimRectangle(pPixelmap, pLeft, pTop, pRight, pBottom, pKnock_out_corners);
}

static void(__cdecl*original_DimAFewBits)() = (void(__cdecl*)())0x004c479c;
CARM95_HOOK_FUNCTION(original_DimAFewBits, DimAFewBits)
void __cdecl DimAFewBits() {
    int i;
    LOG_TRACE("()");

    (void)i;

    original_DimAFewBits();
}

static void(__cdecl*original_KillOldestQueuedHeadup)() = (void(__cdecl*)())0x004c524c;
CARM95_HOOK_FUNCTION(original_KillOldestQueuedHeadup, KillOldestQueuedHeadup)
void __cdecl KillOldestQueuedHeadup() {
    LOG_TRACE("()");


    original_KillOldestQueuedHeadup();
}

static void(__cdecl*original_DubreyBar)(int, int, int) = (void(__cdecl*)(int, int, int))0x004c5438;
CARM95_HOOK_FUNCTION(original_DubreyBar, DubreyBar)
void __cdecl DubreyBar(int pX_index, int pY, int pColour) {
    int x;
    LOG_TRACE("(%d, %d, %d)", pX_index, pY, pColour);

    (void)pX_index;
    (void)pY;
    (void)pColour;
    (void)x;

    original_DubreyBar(pX_index, pY, pColour);
}

static void(__cdecl*original_DoPSPowerHeadup)(int, int, char *, int) = (void(__cdecl*)(int, int, char *, int))0x004c530b;
CARM95_HOOK_FUNCTION(original_DoPSPowerHeadup, DoPSPowerHeadup)
void __cdecl DoPSPowerHeadup(int pY, int pLevel, char *pName, int pBar_colour) {
    char s[16];
    int i;
    LOG_TRACE("(%d, %d, \"%s\", %d)", pY, pLevel, pName, pBar_colour);

    (void)pY;
    (void)pLevel;
    (void)pName;
    (void)pBar_colour;
    (void)s;
    (void)i;

    original_DoPSPowerHeadup(pY, pLevel, pName, pBar_colour);
}

static void(__cdecl*original_DoPSPowerupHeadups)() = (void(__cdecl*)())0x004c5288;
CARM95_HOOK_FUNCTION(original_DoPSPowerupHeadups, DoPSPowerupHeadups)
void __cdecl DoPSPowerupHeadups() {
    LOG_TRACE("()");


    original_DoPSPowerupHeadups();
}

static void(__cdecl*original_DoHeadups)(tU32) = (void(__cdecl*)(tU32))0x004c4906;
CARM95_HOOK_FUNCTION(original_DoHeadups, DoHeadups)
void __cdecl DoHeadups(tU32 pThe_time) {
    int i;
    int x_offset;
    int y_offset;
    tHeadup *the_headup;
    int time_factor;
    LOG_TRACE("(%u)", pThe_time);

    (void)pThe_time;
    (void)i;
    (void)x_offset;
    (void)y_offset;
    (void)the_headup;
    (void)time_factor;

    original_DoHeadups(pThe_time);
}

static int(__cdecl*original_FindAHeadupHoleWoofBarkSoundsABitRude)(int) = (int(__cdecl*)(int))0x004c5493;
CARM95_HOOK_FUNCTION(original_FindAHeadupHoleWoofBarkSoundsABitRude, FindAHeadupHoleWoofBarkSoundsABitRude)
int __cdecl FindAHeadupHoleWoofBarkSoundsABitRude(int pSlot_index) {
    int i;
    int empty_one;
    tHeadup *the_headup;
    LOG_TRACE("(%d)", pSlot_index);

    (void)pSlot_index;
    (void)i;
    (void)empty_one;
    (void)the_headup;

    return original_FindAHeadupHoleWoofBarkSoundsABitRude(pSlot_index);
}

static int(__cdecl*original_DRTextWidth)(tDR_font *, char *) = (int(__cdecl*)(tDR_font *, char *))0x004c5514;
CARM95_HOOK_FUNCTION(original_DRTextWidth, DRTextWidth)
int __cdecl DRTextWidth(tDR_font *pFont, char *pText) {
    int i;
    int len;
    int result;
    char *c;
    LOG_TRACE("(%p, \"%s\")", pFont, pText);

    (void)pFont;
    (void)pText;
    (void)i;
    (void)len;
    (void)result;
    (void)c;

    return original_DRTextWidth(pFont, pText);
}

static int(__cdecl*original_DRTextCleverWidth)(tDR_font *, signed char *) = (int(__cdecl*)(tDR_font *, signed char *))0x004c5591;
CARM95_HOOK_FUNCTION(original_DRTextCleverWidth, DRTextCleverWidth)
int __cdecl DRTextCleverWidth(tDR_font *pFont, signed char *pText) {
    int i;
    int len;
    int result;
    unsigned char *c;
    LOG_TRACE("(%p, %p)", pFont, pText);

    (void)pFont;
    (void)pText;
    (void)i;
    (void)len;
    (void)result;
    (void)c;

    return original_DRTextCleverWidth(pFont, pText);
}

static void(__cdecl*original_DRPixelmapCentredText)(br_pixelmap *, int, int, tDR_font *, char *) = (void(__cdecl*)(br_pixelmap *, int, int, tDR_font *, char *))0x004c5665;
CARM95_HOOK_FUNCTION(original_DRPixelmapCentredText, DRPixelmapCentredText)
void __cdecl DRPixelmapCentredText(br_pixelmap *pPixelmap, int pX, int pY, tDR_font *pFont, char *pText) {
    int width_over_2;
    LOG_TRACE("(%p, %d, %d, %p, \"%s\")", pPixelmap, pX, pY, pFont, pText);

    (void)pPixelmap;
    (void)pX;
    (void)pY;
    (void)pFont;
    (void)pText;
    (void)width_over_2;

    original_DRPixelmapCentredText(pPixelmap, pX, pY, pFont, pText);
}

static int(__cdecl*original_IsHeadupTextClever)(signed char *) = (int(__cdecl*)(signed char *))0x004c5bd4;
CARM95_HOOK_FUNCTION(original_IsHeadupTextClever, IsHeadupTextClever)
int __cdecl IsHeadupTextClever(signed char *pText) {
    LOG_TRACE("(%p)", pText);

    (void)pText;

    return original_IsHeadupTextClever(pText);
}

static int(__cdecl*original_MungeHeadupWidth)(tHeadup *) = (int(__cdecl*)(tHeadup *))0x004c5981;
CARM95_HOOK_FUNCTION(original_MungeHeadupWidth, MungeHeadupWidth)
int __cdecl MungeHeadupWidth(tHeadup *pHeadup) {
    int width;
    LOG_TRACE("(%p)", pHeadup);

    (void)pHeadup;
    (void)width;

    return original_MungeHeadupWidth(pHeadup);
}

static int(__cdecl*original_NewTextHeadupSlot2)(int, int, int, int, char *, int) = (int(__cdecl*)(int, int, int, int, char *, int))0x004c56b1;
CARM95_HOOK_FUNCTION(original_NewTextHeadupSlot2, NewTextHeadupSlot2)
int __cdecl NewTextHeadupSlot2(int pSlot_index, int pFlash_rate, int pLifetime, int pFont_index, char *pText, int pQueue_it) {
    int index;
    tHeadup *the_headup;
    tHeadup_slot *headup_slot;
    tU32 time;
    LOG_TRACE("(%d, %d, %d, %d, \"%s\", %d)", pSlot_index, pFlash_rate, pLifetime, pFont_index, pText, pQueue_it);

    (void)pSlot_index;
    (void)pFlash_rate;
    (void)pLifetime;
    (void)pFont_index;
    (void)pText;
    (void)pQueue_it;
    (void)index;
    (void)the_headup;
    (void)headup_slot;
    (void)time;

    return original_NewTextHeadupSlot2(pSlot_index, pFlash_rate, pLifetime, pFont_index, pText, pQueue_it);
}

static int(__cdecl*original_NewTextHeadupSlot)(int, int, int, int, char *) = (int(__cdecl*)(int, int, int, int, char *))0x004c5c1d;
CARM95_HOOK_FUNCTION(original_NewTextHeadupSlot, NewTextHeadupSlot)
int __cdecl NewTextHeadupSlot(int pSlot_index, int pFlash_rate, int pLifetime, int pFont_index, char *pText) {
    LOG_TRACE("(%d, %d, %d, %d, \"%s\")", pSlot_index, pFlash_rate, pLifetime, pFont_index, pText);

    (void)pSlot_index;
    (void)pFlash_rate;
    (void)pLifetime;
    (void)pFont_index;
    (void)pText;

    return original_NewTextHeadupSlot(pSlot_index, pFlash_rate, pLifetime, pFont_index, pText);
}

static int(__cdecl*original_NewImageHeadupSlot)(int, int, int, int) = (int(__cdecl*)(int, int, int, int))0x004c5c4b;
CARM95_HOOK_FUNCTION(original_NewImageHeadupSlot, NewImageHeadupSlot)
int __cdecl NewImageHeadupSlot(int pSlot_index, int pFlash_rate, int pLifetime, int pImage_index) {
    int index;
    tHeadup *the_headup;
    tHeadup_slot *headup_slot;
    LOG_TRACE("(%d, %d, %d, %d)", pSlot_index, pFlash_rate, pLifetime, pImage_index);

    (void)pSlot_index;
    (void)pFlash_rate;
    (void)pLifetime;
    (void)pImage_index;
    (void)index;
    (void)the_headup;
    (void)headup_slot;

    return original_NewImageHeadupSlot(pSlot_index, pFlash_rate, pLifetime, pImage_index);
}

static void(__cdecl*original_DoFancyHeadup)(int) = (void(__cdecl*)(int))0x004c5e50;
CARM95_HOOK_FUNCTION(original_DoFancyHeadup, DoFancyHeadup)
void __cdecl DoFancyHeadup(int pIndex) {
    tU32 the_time;
    tHeadup *the_headup;
    int temp_ref;
    LOG_TRACE("(%d)", pIndex);

    (void)pIndex;
    (void)the_time;
    (void)the_headup;
    (void)temp_ref;

    original_DoFancyHeadup(pIndex);
}

static void(__cdecl*original_AdjustHeadups)() = (void(__cdecl*)())0x004c5f58;
CARM95_HOOK_FUNCTION(original_AdjustHeadups, AdjustHeadups)
void __cdecl AdjustHeadups() {
    int i;
    int delta_x;
    int delta_y;
    tHeadup *the_headup;
    LOG_TRACE("()");

    (void)i;
    (void)delta_x;
    (void)delta_y;
    (void)the_headup;

    original_AdjustHeadups();
}

static void(__cdecl*original_MoveHeadupTo)(int, int, int) = (void(__cdecl*)(int, int, int))0x004c6107;
CARM95_HOOK_FUNCTION(original_MoveHeadupTo, MoveHeadupTo)
void __cdecl MoveHeadupTo(int pHeadup_index, int pNew_x, int pNew_y) {
    int delta_x;
    tHeadup *the_headup;
    LOG_TRACE("(%d, %d, %d)", pHeadup_index, pNew_x, pNew_y);

    (void)pHeadup_index;
    (void)pNew_x;
    (void)pNew_y;
    (void)delta_x;
    (void)the_headup;

    original_MoveHeadupTo(pHeadup_index, pNew_x, pNew_y);
}

static void(__cdecl*original_ChangeHeadupText)(int, char *) = (void(__cdecl*)(int, char *))0x004c6169;
CARM95_HOOK_FUNCTION(original_ChangeHeadupText, ChangeHeadupText)
void __cdecl ChangeHeadupText(int pHeadup_index, char *pNew_text) {
    tHeadup *the_headup;
    LOG_TRACE("(%d, \"%s\")", pHeadup_index, pNew_text);

    (void)pHeadup_index;
    (void)pNew_text;
    (void)the_headup;

    original_ChangeHeadupText(pHeadup_index, pNew_text);
}

static void(__cdecl*original_ChangeHeadupImage)(int, int) = (void(__cdecl*)(int, int))0x004c61d2;
CARM95_HOOK_FUNCTION(original_ChangeHeadupImage, ChangeHeadupImage)
void __cdecl ChangeHeadupImage(int pHeadup_index, int pNew_image) {
    tHeadup *the_headup;
    LOG_TRACE("(%d, %d)", pHeadup_index, pNew_image);

    (void)pHeadup_index;
    (void)pNew_image;
    (void)the_headup;

    original_ChangeHeadupImage(pHeadup_index, pNew_image);
}

static void(__cdecl*original_ChangeHeadupColour)(int, int) = (void(__cdecl*)(int, int))0x004c629e;
CARM95_HOOK_FUNCTION(original_ChangeHeadupColour, ChangeHeadupColour)
void __cdecl ChangeHeadupColour(int pHeadup_index, int pNew_colour) {
    LOG_TRACE("(%d, %d)", pHeadup_index, pNew_colour);

    (void)pHeadup_index;
    (void)pNew_colour;

    original_ChangeHeadupColour(pHeadup_index, pNew_colour);
}

static void(__cdecl*original_DoDamageScreen)(tU32) = (void(__cdecl*)(tU32))0x004c62d8;
CARM95_HOOK_FUNCTION(original_DoDamageScreen, DoDamageScreen)
void __cdecl DoDamageScreen(tU32 pThe_time) {
    int i;
    int y_pitch;
    int the_step;
    int the_wobble_x;
    int the_wobble_y;
    br_pixelmap *the_image;
    tDamage_unit *the_damage;
    LOG_TRACE("(%u)", pThe_time);

    (void)pThe_time;
    (void)i;
    (void)y_pitch;
    (void)the_step;
    (void)the_wobble_x;
    (void)the_wobble_y;
    (void)the_image;
    (void)the_damage;

    original_DoDamageScreen(pThe_time);
}

static void(__cdecl*original_PoshDrawLine)(float, br_pixelmap *, int, int, int, int, int) = (void(__cdecl*)(float, br_pixelmap *, int, int, int, int, int))0x004c70fd;
CARM95_HOOK_FUNCTION(original_PoshDrawLine, PoshDrawLine)
void __cdecl PoshDrawLine(float pAngle, br_pixelmap *pDestn, int pX1, int pY1, int pX2, int pY2, int pColour) {
    LOG_TRACE("(%f, %p, %d, %d, %d, %d, %d)", pAngle, pDestn, pX1, pY1, pX2, pY2, pColour);

    (void)pAngle;
    (void)pDestn;
    (void)pX1;
    (void)pY1;
    (void)pX2;
    (void)pY2;
    (void)pColour;

    original_PoshDrawLine(pAngle, pDestn, pX1, pY1, pX2, pY2, pColour);
}

static void(__cdecl*original_DoInstruments)(tU32) = (void(__cdecl*)(tU32))0x004c6474;
CARM95_HOOK_FUNCTION(original_DoInstruments, DoInstruments)
void __cdecl DoInstruments(tU32 pThe_time) {
    br_pixelmap *speedo_image;
    br_pixelmap *tacho_image;
    int the_wobble_x;
    int the_wobble_y;
    int gear;
    double the_angle;
    double the_angle2;
    double sin_angle;
    double cos_angle;
    double speed_mph;
    LOG_TRACE("(%u)", pThe_time);

    (void)pThe_time;
    (void)speedo_image;
    (void)tacho_image;
    (void)the_wobble_x;
    (void)the_wobble_y;
    (void)gear;
    (void)the_angle;
    (void)the_angle2;
    (void)sin_angle;
    (void)cos_angle;
    (void)speed_mph;

    original_DoInstruments(pThe_time);
}

static void(__cdecl*original_DoSteeringWheel)(tU32) = (void(__cdecl*)(tU32))0x004c72e1;
CARM95_HOOK_FUNCTION(original_DoSteeringWheel, DoSteeringWheel)
void __cdecl DoSteeringWheel(tU32 pThe_time) {
    br_pixelmap *hands_image;
    int hands_index;
    LOG_TRACE("(%u)", pThe_time);

    (void)pThe_time;
    (void)hands_image;
    (void)hands_index;

    original_DoSteeringWheel(pThe_time);
}

static void(__cdecl*original_ChangingView)() = (void(__cdecl*)())0x004c7455;
CARM95_HOOK_FUNCTION(original_ChangingView, ChangingView)
void __cdecl ChangingView() {
    tU32 the_time;
    LOG_TRACE("()");

    (void)the_time;

    original_ChangingView();
}

static void(__cdecl*original_EarnCredits2)(int, char *) = (void(__cdecl*)(int, char *))0x004c76d8;
CARM95_HOOK_FUNCTION(original_EarnCredits2, EarnCredits2)
void __cdecl EarnCredits2(int pAmount, char *pPrefix_text) {
    char s[256];
    int original_amount;
    tU32 the_time;
    LOG_TRACE("(%d, \"%s\")", pAmount, pPrefix_text);

    (void)pAmount;
    (void)pPrefix_text;
    (void)s;
    (void)original_amount;
    (void)the_time;

    original_EarnCredits2(pAmount, pPrefix_text);
}

static void(__cdecl*original_EarnCredits)(int) = (void(__cdecl*)(int))0x004c78a8;
CARM95_HOOK_FUNCTION(original_EarnCredits, EarnCredits)
void __cdecl EarnCredits(int pAmount) {
    LOG_TRACE("(%d)", pAmount);

    (void)pAmount;

    original_EarnCredits(pAmount);
}

static int(__cdecl*original_SpendCredits)(int) = (int(__cdecl*)(int))0x004c78c4;
CARM95_HOOK_FUNCTION(original_SpendCredits, SpendCredits)
int __cdecl SpendCredits(int pAmount) {
    int amount;
    LOG_TRACE("(%d)", pAmount);

    (void)pAmount;
    (void)amount;

    return original_SpendCredits(pAmount);
}

static void(__cdecl*original_AwardTime)(tU32) = (void(__cdecl*)(tU32))0x004c791e;
CARM95_HOOK_FUNCTION(original_AwardTime, AwardTime)
void __cdecl AwardTime(tU32 pTime) {
    char s[256];
    tU32 original_amount;
    tU32 the_time;
    int i;
    LOG_TRACE("(%u)", pTime);

    (void)pTime;
    (void)s;
    (void)original_amount;
    (void)the_time;
    (void)i;

    original_AwardTime(pTime);
}

static void(__cdecl*original_DrawRectangle)(br_pixelmap *, int, int, int, int, int) = (void(__cdecl*)(br_pixelmap *, int, int, int, int, int))0x004c7a61;
CARM95_HOOK_FUNCTION(original_DrawRectangle, DrawRectangle)
void __cdecl DrawRectangle(br_pixelmap *pPixelmap, int pLeft, int pTop, int pRight, int pBottom, int pColour) {
    LOG_TRACE("(%p, %d, %d, %d, %d, %d)", pPixelmap, pLeft, pTop, pRight, pBottom, pColour);

    (void)pPixelmap;
    (void)pLeft;
    (void)pTop;
    (void)pRight;
    (void)pBottom;
    (void)pColour;

    original_DrawRectangle(pPixelmap, pLeft, pTop, pRight, pBottom, pColour);
}

static void(__cdecl*original_DrawRRectangle)(br_pixelmap *, int, int, int, int, int) = (void(__cdecl*)(br_pixelmap *, int, int, int, int, int))0x004c7aec;
CARM95_HOOK_FUNCTION(original_DrawRRectangle, DrawRRectangle)
void __cdecl DrawRRectangle(br_pixelmap *pPixelmap, int pLeft, int pTop, int pRight, int pBottom, int pColour) {
    LOG_TRACE("(%p, %d, %d, %d, %d, %d)", pPixelmap, pLeft, pTop, pRight, pBottom, pColour);

    (void)pPixelmap;
    (void)pLeft;
    (void)pTop;
    (void)pRight;
    (void)pBottom;
    (void)pColour;

    original_DrawRRectangle(pPixelmap, pLeft, pTop, pRight, pBottom, pColour);
}

static void(__cdecl*original_OoerrIveGotTextInMeBoxMissus)(int, char *, br_pixelmap *, int, int, int, int, int) = (void(__cdecl*)(int, char *, br_pixelmap *, int, int, int, int, int))0x004c7b7f;
CARM95_HOOK_FUNCTION(original_OoerrIveGotTextInMeBoxMissus, OoerrIveGotTextInMeBoxMissus)
void __cdecl OoerrIveGotTextInMeBoxMissus(int pFont_index, char *pText, br_pixelmap *pPixelmap, int pLeft, int pTop, int pRight, int pBottom, int pCentred) {
    tDR_font *font;
    int width;
    int current_width;
    int i;
    int centre;
    int line_char_index;
    int input_str_index;
    int start_line;
    int current_y;
    int font_needed_loading;
    char line[256];
    LOG_TRACE("(%d, \"%s\", %p, %d, %d, %d, %d, %d)", pFont_index, pText, pPixelmap, pLeft, pTop, pRight, pBottom, pCentred);

    (void)pFont_index;
    (void)pText;
    (void)pPixelmap;
    (void)pLeft;
    (void)pTop;
    (void)pRight;
    (void)pBottom;
    (void)pCentred;
    (void)font;
    (void)width;
    (void)current_width;
    (void)i;
    (void)centre;
    (void)line_char_index;
    (void)input_str_index;
    (void)start_line;
    (void)current_y;
    (void)font_needed_loading;
    (void)line;

    original_OoerrIveGotTextInMeBoxMissus(pFont_index, pText, pPixelmap, pLeft, pTop, pRight, pBottom, pCentred);
}

static void(__cdecl*original_TransBrPixelmapText)(br_pixelmap *, int, int, br_uint_32, br_font *, signed char *) = (void(__cdecl*)(br_pixelmap *, int, int, br_uint_32, br_font *, signed char *))0x004c7ec5;
CARM95_HOOK_FUNCTION(original_TransBrPixelmapText, TransBrPixelmapText)
void __cdecl TransBrPixelmapText(br_pixelmap *pPixelmap, int pX, int pY, br_uint_32 pColour, br_font *pFont, signed char *pText) {
    int i;
    int len;
    LOG_TRACE("(%p, %d, %d, %u, %p, %p)", pPixelmap, pX, pY, pColour, pFont, pText);

    (void)pPixelmap;
    (void)pX;
    (void)pY;
    (void)pColour;
    (void)pFont;
    (void)pText;
    (void)i;
    (void)len;

    original_TransBrPixelmapText(pPixelmap, pX, pY, pColour, pFont, pText);
}

static void(__cdecl*original_TransDRPixelmapText)(br_pixelmap *, int, int, tDR_font *, char *, int) = (void(__cdecl*)(br_pixelmap *, int, int, tDR_font *, char *, int))0x004c7f08;
CARM95_HOOK_FUNCTION(original_TransDRPixelmapText, TransDRPixelmapText)
void __cdecl TransDRPixelmapText(br_pixelmap *pPixelmap, int pX, int pY, tDR_font *pFont, char *pText, int pRight_edge) {
    LOG_TRACE("(%p, %d, %d, %p, \"%s\", %d)", pPixelmap, pX, pY, pFont, pText, pRight_edge);

    (void)pPixelmap;
    (void)pX;
    (void)pY;
    (void)pFont;
    (void)pText;
    (void)pRight_edge;

    original_TransDRPixelmapText(pPixelmap, pX, pY, pFont, pText, pRight_edge);
}

static void(__cdecl*original_TransDRPixelmapCleverText)(br_pixelmap *, int, int, tDR_font *, char *, int) = (void(__cdecl*)(br_pixelmap *, int, int, tDR_font *, char *, int))0x004c7fd5;
CARM95_HOOK_FUNCTION(original_TransDRPixelmapCleverText, TransDRPixelmapCleverText)
void __cdecl TransDRPixelmapCleverText(br_pixelmap *pPixelmap, int pX, int pY, tDR_font *pFont, char *pText, int pRight_edge) {
    LOG_TRACE("(%p, %d, %d, %p, \"%s\", %d)", pPixelmap, pX, pY, pFont, pText, pRight_edge);

    (void)pPixelmap;
    (void)pX;
    (void)pY;
    (void)pFont;
    (void)pText;
    (void)pRight_edge;

    original_TransDRPixelmapCleverText(pPixelmap, pX, pY, pFont, pText, pRight_edge);
}

