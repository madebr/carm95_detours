#include "displays.h"

#include "harness/trace.h"

#include "carm95_hooks.h"

#include "carm95_webserver.h"

#include <assert.h>
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

function_hook_state_t function_hook_state_GetTimerString = HOOK_UNAVAILABLE;
static void(__cdecl*original_GetTimerString)(char *, int) = (void(__cdecl*)(char *, int))0x004c4030;
CARM95_HOOK_FUNCTION(original_GetTimerString, GetTimerString)
void __cdecl GetTimerString(char *pStr, int pFudge_colon) {
    LOG_TRACE("(\"%s\", %d)", pStr, pFudge_colon);

    (void)pStr;
    (void)pFudge_colon;

    if (function_hook_state_GetTimerString == HOOK_ENABLED) {
        assert(0 && "GetTimerString not implemented.");
        abort();
    } else {
        original_GetTimerString(pStr, pFudge_colon);
    }
}

function_hook_state_t function_hook_state_InitHeadups = HOOK_UNAVAILABLE;
static void(__cdecl*original_InitHeadups)() = (void(__cdecl*)())0x004c4053;
CARM95_HOOK_FUNCTION(original_InitHeadups, InitHeadups)
void __cdecl InitHeadups() {
    int i;
    LOG_TRACE("()");

    (void)i;

    if (function_hook_state_InitHeadups == HOOK_ENABLED) {
        assert(0 && "InitHeadups not implemented.");
        abort();
    } else {
        original_InitHeadups();
    }
}

function_hook_state_t function_hook_state_ClearHeadup = HOOK_UNAVAILABLE;
static void(__cdecl*original_ClearHeadup)(int) = (void(__cdecl*)(int))0x004c40c1;
CARM95_HOOK_FUNCTION(original_ClearHeadup, ClearHeadup)
void __cdecl ClearHeadup(int pIndex) {
    LOG_TRACE("(%d)", pIndex);

    (void)pIndex;

    if (function_hook_state_ClearHeadup == HOOK_ENABLED) {
        assert(0 && "ClearHeadup not implemented.");
        abort();
    } else {
        original_ClearHeadup(pIndex);
    }
}

function_hook_state_t function_hook_state_ClearHeadupSlot = HOOK_UNAVAILABLE;
static void(__cdecl*original_ClearHeadupSlot)(int) = (void(__cdecl*)(int))0x004c40e6;
CARM95_HOOK_FUNCTION(original_ClearHeadupSlot, ClearHeadupSlot)
void __cdecl ClearHeadupSlot(int pSlot_index) {
    int i;
    tHeadup *the_headup;
    LOG_TRACE("(%d)", pSlot_index);

    (void)pSlot_index;
    (void)i;
    (void)the_headup;

    if (function_hook_state_ClearHeadupSlot == HOOK_ENABLED) {
        assert(0 && "ClearHeadupSlot not implemented.");
        abort();
    } else {
        original_ClearHeadupSlot(pSlot_index);
    }
}

function_hook_state_t function_hook_state_ClearHeadups = HOOK_UNAVAILABLE;
static void(__cdecl*original_ClearHeadups)() = (void(__cdecl*)())0x004c414c;
CARM95_HOOK_FUNCTION(original_ClearHeadups, ClearHeadups)
void __cdecl ClearHeadups() {
    int i;
    LOG_TRACE("()");

    (void)i;

    if (function_hook_state_ClearHeadups == HOOK_ENABLED) {
        assert(0 && "ClearHeadups not implemented.");
        abort();
    } else {
        original_ClearHeadups();
    }
}

function_hook_state_t function_hook_state_HeadupActive = HOOK_UNAVAILABLE;
static int(__cdecl*original_HeadupActive)(int) = (int(__cdecl*)(int))0x004c421d;
CARM95_HOOK_FUNCTION(original_HeadupActive, HeadupActive)
int __cdecl HeadupActive(int pIndex) {
    LOG_TRACE("(%d)", pIndex);

    (void)pIndex;

    if (function_hook_state_HeadupActive == HOOK_ENABLED) {
        assert(0 && "HeadupActive not implemented.");
        abort();
    } else {
        return original_HeadupActive(pIndex);
    }
}

function_hook_state_t function_hook_state_DRPixelmapText = HOOK_UNAVAILABLE;
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

    if (function_hook_state_DRPixelmapText == HOOK_ENABLED) {
        assert(0 && "DRPixelmapText not implemented.");
        abort();
    } else {
        original_DRPixelmapText(pPixelmap, pX, pY, pFont, pText, pRight_edge);
    }
}

function_hook_state_t function_hook_state_DRPixelmapCleverText2 = HOOK_UNAVAILABLE;
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

    if (function_hook_state_DRPixelmapCleverText2 == HOOK_ENABLED) {
        assert(0 && "DRPixelmapCleverText2 not implemented.");
        abort();
    } else {
        original_DRPixelmapCleverText2(pPixelmap, pX, pY, pFont, pText, pRight_edge);
    }
}

function_hook_state_t function_hook_state_DeviouslyDimRectangle = HOOK_UNAVAILABLE;
void DeviouslyDimRectangle(br_pixelmap *pPixelmap, int pLeft, int pTop, int pRight, int pBottom, int pKnock_out_corners) {
    LOG_TRACE("(%p, %d, %d, %d, %d, %d)", pPixelmap, pLeft, pTop, pRight, pBottom, pKnock_out_corners);

    (void)pPixelmap;
    (void)pLeft;
    (void)pTop;
    (void)pRight;
    (void)pBottom;
    (void)pKnock_out_corners;

    if (function_hook_state_DeviouslyDimRectangle == HOOK_ENABLED) {
        assert(0 && "DeviouslyDimRectangle not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}

function_hook_state_t function_hook_state_DimRectangle = HOOK_UNAVAILABLE;
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

    if (function_hook_state_DimRectangle == HOOK_ENABLED) {
        assert(0 && "DimRectangle not implemented.");
        abort();
    } else {
        original_DimRectangle(pPixelmap, pLeft, pTop, pRight, pBottom, pKnock_out_corners);
    }
}

function_hook_state_t function_hook_state_DimAFewBits = HOOK_UNAVAILABLE;
static void(__cdecl*original_DimAFewBits)() = (void(__cdecl*)())0x004c479c;
CARM95_HOOK_FUNCTION(original_DimAFewBits, DimAFewBits)
void __cdecl DimAFewBits() {
    int i;
    LOG_TRACE("()");

    (void)i;

    if (function_hook_state_DimAFewBits == HOOK_ENABLED) {
        assert(0 && "DimAFewBits not implemented.");
        abort();
    } else {
        original_DimAFewBits();
    }
}

function_hook_state_t function_hook_state_KillOldestQueuedHeadup = HOOK_UNAVAILABLE;
static void(__cdecl*original_KillOldestQueuedHeadup)() = (void(__cdecl*)())0x004c524c;
CARM95_HOOK_FUNCTION(original_KillOldestQueuedHeadup, KillOldestQueuedHeadup)
void __cdecl KillOldestQueuedHeadup() {
    LOG_TRACE("()");


    if (function_hook_state_KillOldestQueuedHeadup == HOOK_ENABLED) {
        assert(0 && "KillOldestQueuedHeadup not implemented.");
        abort();
    } else {
        original_KillOldestQueuedHeadup();
    }
}

function_hook_state_t function_hook_state_DubreyBar = HOOK_UNAVAILABLE;
static void(__cdecl*original_DubreyBar)(int, int, int) = (void(__cdecl*)(int, int, int))0x004c5438;
CARM95_HOOK_FUNCTION(original_DubreyBar, DubreyBar)
void __cdecl DubreyBar(int pX_index, int pY, int pColour) {
    int x;
    LOG_TRACE("(%d, %d, %d)", pX_index, pY, pColour);

    (void)pX_index;
    (void)pY;
    (void)pColour;
    (void)x;

    if (function_hook_state_DubreyBar == HOOK_ENABLED) {
        assert(0 && "DubreyBar not implemented.");
        abort();
    } else {
        original_DubreyBar(pX_index, pY, pColour);
    }
}

function_hook_state_t function_hook_state_DoPSPowerHeadup = HOOK_UNAVAILABLE;
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

    if (function_hook_state_DoPSPowerHeadup == HOOK_ENABLED) {
        assert(0 && "DoPSPowerHeadup not implemented.");
        abort();
    } else {
        original_DoPSPowerHeadup(pY, pLevel, pName, pBar_colour);
    }
}

function_hook_state_t function_hook_state_DoPSPowerupHeadups = HOOK_UNAVAILABLE;
static void(__cdecl*original_DoPSPowerupHeadups)() = (void(__cdecl*)())0x004c5288;
CARM95_HOOK_FUNCTION(original_DoPSPowerupHeadups, DoPSPowerupHeadups)
void __cdecl DoPSPowerupHeadups() {
    LOG_TRACE("()");


    if (function_hook_state_DoPSPowerupHeadups == HOOK_ENABLED) {
        assert(0 && "DoPSPowerupHeadups not implemented.");
        abort();
    } else {
        original_DoPSPowerupHeadups();
    }
}

function_hook_state_t function_hook_state_DoHeadups = HOOK_UNAVAILABLE;
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

    if (function_hook_state_DoHeadups == HOOK_ENABLED) {
        assert(0 && "DoHeadups not implemented.");
        abort();
    } else {
        original_DoHeadups(pThe_time);
    }
}

function_hook_state_t function_hook_state_FindAHeadupHoleWoofBarkSoundsABitRude = HOOK_UNAVAILABLE;
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

    if (function_hook_state_FindAHeadupHoleWoofBarkSoundsABitRude == HOOK_ENABLED) {
        assert(0 && "FindAHeadupHoleWoofBarkSoundsABitRude not implemented.");
        abort();
    } else {
        return original_FindAHeadupHoleWoofBarkSoundsABitRude(pSlot_index);
    }
}

function_hook_state_t function_hook_state_DRTextWidth = HOOK_UNAVAILABLE;
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

    if (function_hook_state_DRTextWidth == HOOK_ENABLED) {
        assert(0 && "DRTextWidth not implemented.");
        abort();
    } else {
        return original_DRTextWidth(pFont, pText);
    }
}

function_hook_state_t function_hook_state_DRTextCleverWidth = HOOK_UNAVAILABLE;
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

    if (function_hook_state_DRTextCleverWidth == HOOK_ENABLED) {
        assert(0 && "DRTextCleverWidth not implemented.");
        abort();
    } else {
        return original_DRTextCleverWidth(pFont, pText);
    }
}

function_hook_state_t function_hook_state_DRPixelmapCentredText = HOOK_UNAVAILABLE;
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

    if (function_hook_state_DRPixelmapCentredText == HOOK_ENABLED) {
        assert(0 && "DRPixelmapCentredText not implemented.");
        abort();
    } else {
        original_DRPixelmapCentredText(pPixelmap, pX, pY, pFont, pText);
    }
}

function_hook_state_t function_hook_state_IsHeadupTextClever = HOOK_UNAVAILABLE;
static int(__cdecl*original_IsHeadupTextClever)(signed char *) = (int(__cdecl*)(signed char *))0x004c5bd4;
CARM95_HOOK_FUNCTION(original_IsHeadupTextClever, IsHeadupTextClever)
int __cdecl IsHeadupTextClever(signed char *pText) {
    LOG_TRACE("(%p)", pText);

    (void)pText;

    if (function_hook_state_IsHeadupTextClever == HOOK_ENABLED) {
        assert(0 && "IsHeadupTextClever not implemented.");
        abort();
    } else {
        return original_IsHeadupTextClever(pText);
    }
}

function_hook_state_t function_hook_state_MungeHeadupWidth = HOOK_UNAVAILABLE;
static int(__cdecl*original_MungeHeadupWidth)(tHeadup *) = (int(__cdecl*)(tHeadup *))0x004c5981;
CARM95_HOOK_FUNCTION(original_MungeHeadupWidth, MungeHeadupWidth)
int __cdecl MungeHeadupWidth(tHeadup *pHeadup) {
    int width;
    LOG_TRACE("(%p)", pHeadup);

    (void)pHeadup;
    (void)width;

    if (function_hook_state_MungeHeadupWidth == HOOK_ENABLED) {
        assert(0 && "MungeHeadupWidth not implemented.");
        abort();
    } else {
        return original_MungeHeadupWidth(pHeadup);
    }
}

function_hook_state_t function_hook_state_NewTextHeadupSlot2 = HOOK_UNAVAILABLE;
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

    if (function_hook_state_NewTextHeadupSlot2 == HOOK_ENABLED) {
        assert(0 && "NewTextHeadupSlot2 not implemented.");
        abort();
    } else {
        return original_NewTextHeadupSlot2(pSlot_index, pFlash_rate, pLifetime, pFont_index, pText, pQueue_it);
    }
}

function_hook_state_t function_hook_state_NewTextHeadupSlot = HOOK_UNAVAILABLE;
static int(__cdecl*original_NewTextHeadupSlot)(int, int, int, int, char *) = (int(__cdecl*)(int, int, int, int, char *))0x004c5c1d;
CARM95_HOOK_FUNCTION(original_NewTextHeadupSlot, NewTextHeadupSlot)
int __cdecl NewTextHeadupSlot(int pSlot_index, int pFlash_rate, int pLifetime, int pFont_index, char *pText) {
    LOG_TRACE("(%d, %d, %d, %d, \"%s\")", pSlot_index, pFlash_rate, pLifetime, pFont_index, pText);

    (void)pSlot_index;
    (void)pFlash_rate;
    (void)pLifetime;
    (void)pFont_index;
    (void)pText;

    if (function_hook_state_NewTextHeadupSlot == HOOK_ENABLED) {
        assert(0 && "NewTextHeadupSlot not implemented.");
        abort();
    } else {
        return original_NewTextHeadupSlot(pSlot_index, pFlash_rate, pLifetime, pFont_index, pText);
    }
}

function_hook_state_t function_hook_state_NewImageHeadupSlot = HOOK_UNAVAILABLE;
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

    if (function_hook_state_NewImageHeadupSlot == HOOK_ENABLED) {
        assert(0 && "NewImageHeadupSlot not implemented.");
        abort();
    } else {
        return original_NewImageHeadupSlot(pSlot_index, pFlash_rate, pLifetime, pImage_index);
    }
}

function_hook_state_t function_hook_state_DoFancyHeadup = HOOK_UNAVAILABLE;
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

    if (function_hook_state_DoFancyHeadup == HOOK_ENABLED) {
        assert(0 && "DoFancyHeadup not implemented.");
        abort();
    } else {
        original_DoFancyHeadup(pIndex);
    }
}

function_hook_state_t function_hook_state_AdjustHeadups = HOOK_UNAVAILABLE;
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

    if (function_hook_state_AdjustHeadups == HOOK_ENABLED) {
        assert(0 && "AdjustHeadups not implemented.");
        abort();
    } else {
        original_AdjustHeadups();
    }
}

function_hook_state_t function_hook_state_MoveHeadupTo = HOOK_UNAVAILABLE;
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

    if (function_hook_state_MoveHeadupTo == HOOK_ENABLED) {
        assert(0 && "MoveHeadupTo not implemented.");
        abort();
    } else {
        original_MoveHeadupTo(pHeadup_index, pNew_x, pNew_y);
    }
}

function_hook_state_t function_hook_state_ChangeHeadupText = HOOK_UNAVAILABLE;
static void(__cdecl*original_ChangeHeadupText)(int, char *) = (void(__cdecl*)(int, char *))0x004c6169;
CARM95_HOOK_FUNCTION(original_ChangeHeadupText, ChangeHeadupText)
void __cdecl ChangeHeadupText(int pHeadup_index, char *pNew_text) {
    tHeadup *the_headup;
    LOG_TRACE("(%d, \"%s\")", pHeadup_index, pNew_text);

    (void)pHeadup_index;
    (void)pNew_text;
    (void)the_headup;

    if (function_hook_state_ChangeHeadupText == HOOK_ENABLED) {
        assert(0 && "ChangeHeadupText not implemented.");
        abort();
    } else {
        original_ChangeHeadupText(pHeadup_index, pNew_text);
    }
}

function_hook_state_t function_hook_state_ChangeHeadupImage = HOOK_UNAVAILABLE;
static void(__cdecl*original_ChangeHeadupImage)(int, int) = (void(__cdecl*)(int, int))0x004c61d2;
CARM95_HOOK_FUNCTION(original_ChangeHeadupImage, ChangeHeadupImage)
void __cdecl ChangeHeadupImage(int pHeadup_index, int pNew_image) {
    tHeadup *the_headup;
    LOG_TRACE("(%d, %d)", pHeadup_index, pNew_image);

    (void)pHeadup_index;
    (void)pNew_image;
    (void)the_headup;

    if (function_hook_state_ChangeHeadupImage == HOOK_ENABLED) {
        assert(0 && "ChangeHeadupImage not implemented.");
        abort();
    } else {
        original_ChangeHeadupImage(pHeadup_index, pNew_image);
    }
}

function_hook_state_t function_hook_state_ChangeHeadupColour = HOOK_UNAVAILABLE;
static void(__cdecl*original_ChangeHeadupColour)(int, int) = (void(__cdecl*)(int, int))0x004c629e;
CARM95_HOOK_FUNCTION(original_ChangeHeadupColour, ChangeHeadupColour)
void __cdecl ChangeHeadupColour(int pHeadup_index, int pNew_colour) {
    LOG_TRACE("(%d, %d)", pHeadup_index, pNew_colour);

    (void)pHeadup_index;
    (void)pNew_colour;

    if (function_hook_state_ChangeHeadupColour == HOOK_ENABLED) {
        assert(0 && "ChangeHeadupColour not implemented.");
        abort();
    } else {
        original_ChangeHeadupColour(pHeadup_index, pNew_colour);
    }
}

function_hook_state_t function_hook_state_DoDamageScreen = HOOK_UNAVAILABLE;
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

    if (function_hook_state_DoDamageScreen == HOOK_ENABLED) {
        assert(0 && "DoDamageScreen not implemented.");
        abort();
    } else {
        original_DoDamageScreen(pThe_time);
    }
}

function_hook_state_t function_hook_state_PoshDrawLine = HOOK_UNAVAILABLE;
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

    if (function_hook_state_PoshDrawLine == HOOK_ENABLED) {
        assert(0 && "PoshDrawLine not implemented.");
        abort();
    } else {
        original_PoshDrawLine(pAngle, pDestn, pX1, pY1, pX2, pY2, pColour);
    }
}

function_hook_state_t function_hook_state_DoInstruments = HOOK_UNAVAILABLE;
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

    if (function_hook_state_DoInstruments == HOOK_ENABLED) {
        assert(0 && "DoInstruments not implemented.");
        abort();
    } else {
        original_DoInstruments(pThe_time);
    }
}

function_hook_state_t function_hook_state_DoSteeringWheel = HOOK_UNAVAILABLE;
static void(__cdecl*original_DoSteeringWheel)(tU32) = (void(__cdecl*)(tU32))0x004c72e1;
CARM95_HOOK_FUNCTION(original_DoSteeringWheel, DoSteeringWheel)
void __cdecl DoSteeringWheel(tU32 pThe_time) {
    br_pixelmap *hands_image;
    int hands_index;
    LOG_TRACE("(%u)", pThe_time);

    (void)pThe_time;
    (void)hands_image;
    (void)hands_index;

    if (function_hook_state_DoSteeringWheel == HOOK_ENABLED) {
        assert(0 && "DoSteeringWheel not implemented.");
        abort();
    } else {
        original_DoSteeringWheel(pThe_time);
    }
}

function_hook_state_t function_hook_state_ChangingView = HOOK_UNAVAILABLE;
static void(__cdecl*original_ChangingView)() = (void(__cdecl*)())0x004c7455;
CARM95_HOOK_FUNCTION(original_ChangingView, ChangingView)
void __cdecl ChangingView() {
    tU32 the_time;
    LOG_TRACE("()");

    (void)the_time;

    if (function_hook_state_ChangingView == HOOK_ENABLED) {
        assert(0 && "ChangingView not implemented.");
        abort();
    } else {
        original_ChangingView();
    }
}

function_hook_state_t function_hook_state_EarnCredits2 = HOOK_UNAVAILABLE;
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

    if (function_hook_state_EarnCredits2 == HOOK_ENABLED) {
        assert(0 && "EarnCredits2 not implemented.");
        abort();
    } else {
        original_EarnCredits2(pAmount, pPrefix_text);
    }
}

function_hook_state_t function_hook_state_EarnCredits = HOOK_UNAVAILABLE;
static void(__cdecl*original_EarnCredits)(int) = (void(__cdecl*)(int))0x004c78a8;
CARM95_HOOK_FUNCTION(original_EarnCredits, EarnCredits)
void __cdecl EarnCredits(int pAmount) {
    LOG_TRACE("(%d)", pAmount);

    (void)pAmount;

    if (function_hook_state_EarnCredits == HOOK_ENABLED) {
        assert(0 && "EarnCredits not implemented.");
        abort();
    } else {
        original_EarnCredits(pAmount);
    }
}

function_hook_state_t function_hook_state_SpendCredits = HOOK_UNAVAILABLE;
static int(__cdecl*original_SpendCredits)(int) = (int(__cdecl*)(int))0x004c78c4;
CARM95_HOOK_FUNCTION(original_SpendCredits, SpendCredits)
int __cdecl SpendCredits(int pAmount) {
    int amount;
    LOG_TRACE("(%d)", pAmount);

    (void)pAmount;
    (void)amount;

    if (function_hook_state_SpendCredits == HOOK_ENABLED) {
        assert(0 && "SpendCredits not implemented.");
        abort();
    } else {
        return original_SpendCredits(pAmount);
    }
}

function_hook_state_t function_hook_state_AwardTime = HOOK_UNAVAILABLE;
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

    if (function_hook_state_AwardTime == HOOK_ENABLED) {
        assert(0 && "AwardTime not implemented.");
        abort();
    } else {
        original_AwardTime(pTime);
    }
}

function_hook_state_t function_hook_state_DrawRectangle = HOOK_UNAVAILABLE;
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

    if (function_hook_state_DrawRectangle == HOOK_ENABLED) {
        assert(0 && "DrawRectangle not implemented.");
        abort();
    } else {
        original_DrawRectangle(pPixelmap, pLeft, pTop, pRight, pBottom, pColour);
    }
}

function_hook_state_t function_hook_state_DrawRRectangle = HOOK_UNAVAILABLE;
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

    if (function_hook_state_DrawRRectangle == HOOK_ENABLED) {
        assert(0 && "DrawRRectangle not implemented.");
        abort();
    } else {
        original_DrawRRectangle(pPixelmap, pLeft, pTop, pRight, pBottom, pColour);
    }
}

function_hook_state_t function_hook_state_OoerrIveGotTextInMeBoxMissus = HOOK_UNAVAILABLE;
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

    if (function_hook_state_OoerrIveGotTextInMeBoxMissus == HOOK_ENABLED) {
        assert(0 && "OoerrIveGotTextInMeBoxMissus not implemented.");
        abort();
    } else {
        original_OoerrIveGotTextInMeBoxMissus(pFont_index, pText, pPixelmap, pLeft, pTop, pRight, pBottom, pCentred);
    }
}

function_hook_state_t function_hook_state_TransBrPixelmapText = HOOK_UNAVAILABLE;
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

    if (function_hook_state_TransBrPixelmapText == HOOK_ENABLED) {
        assert(0 && "TransBrPixelmapText not implemented.");
        abort();
    } else {
        original_TransBrPixelmapText(pPixelmap, pX, pY, pColour, pFont, pText);
    }
}

function_hook_state_t function_hook_state_TransDRPixelmapText = HOOK_UNAVAILABLE;
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

    if (function_hook_state_TransDRPixelmapText == HOOK_ENABLED) {
        assert(0 && "TransDRPixelmapText not implemented.");
        abort();
    } else {
        original_TransDRPixelmapText(pPixelmap, pX, pY, pFont, pText, pRight_edge);
    }
}

function_hook_state_t function_hook_state_TransDRPixelmapCleverText = HOOK_UNAVAILABLE;
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

    if (function_hook_state_TransDRPixelmapCleverText == HOOK_ENABLED) {
        assert(0 && "TransDRPixelmapCleverText not implemented.");
        abort();
    } else {
        original_TransDRPixelmapCleverText(pPixelmap, pX, pY, pFont, pText, pRight_edge);
    }
}

