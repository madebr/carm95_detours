#include "graphics.h"

#include "harness/trace.h"

#include "carm95_hooks.h"

#include "carm95_webserver.h"

#include <assert.h>
int * hookvar_gPalette_munged  = (void*)0x00520040;
#if 0
int(* hookvar_gColourValues )[1];
#endif
int * hookvar_gNext_transient  = (void*)0x00520048;
int(* hookvar_gCursor_x_offsets )[8] = (void*)0x00520050;
int(* hookvar_gCursor_y_offsets )[8] = (void*)0x00520070;
int(* hookvar_gCursor_gib_x_offsets )[8] = (void*)0x00520090;
int(* hookvar_gCursor_gib_y_offsets )[8] = (void*)0x005200b0;
int(* hookvar_gCursor_giblet_sequence0 )[7] = (void*)0x005200d0;
int(* hookvar_gCursor_giblet_sequence1 )[5] = (void*)0x005200f0;
int(* hookvar_gCursor_giblet_sequence2 )[5] = (void*)0x00520108;
int(* hookvar_gCursor_giblet_sequence3 )[5] = (void*)0x00520120;
int *(* hookvar_gCursor_giblet_sequences )[4] = (void*)0x00520138;
char *(* hookvar_gFont_names )[21] = (void*)0x00520148;
br_colour(* hookvar_gRGB_colours )[9] = (void*)0x005201a0;
br_matrix34 * hookvar_gSheer_mat  = (void*)0x005201c8;
#if 0
br_matrix34 * hookvar_gIdentity34 ;
#endif
tShadow_level * hookvar_gShadow_level  = (void*)0x00520228;
#if 0
br_scalar * hookvar_gShadow_hither_z_move ;
#endif
#if 0
br_scalar * hookvar_gShadow_hither_min_move ;
#endif
int(* hookvar_gArrows )[2][4][60] = (void*)0x00520238;
float * hookvar_gMap_render_x  = (void*)0x005209b8;
float * hookvar_gMap_render_y  = (void*)0x005209bc;
float * hookvar_gMap_render_width  = (void*)0x005209c0;
float * hookvar_gMap_render_height  = (void*)0x005209c4;
int * hookvar_gMouse_started  = (void*)0x005209c8;
int * hookvar_gFaded_palette  = (void*)0x005209cc;
int * hookvar_gAR_fudge_headups  = (void*)0x005209d0;
br_pixelmap ** hookvar_gCurrent_splash  = (void*)0x005209d4;
br_pixelmap ** hookvar_gCurrent_conversion_table  = (void*)0x005209d8;
int(* hookvar_gMap_colours )[4] = (void*)0x005209e0;
br_vector3(* hookvar_gShadow_points )[8] = (void*)0x0053e798;
tConcussion * hookvar_gConcussion  = (void*)0x0053f940;
tClip_details(* hookvar_gShadow_clip_planes )[8] = (void*)0x0053f080;
br_actor *(* hookvar_gLollipops )[100] = (void*)0x0053e5f8;
tWobble_spec(* hookvar_gWobble_array )[5] = (void*)0x0053f8d8;
tSaved_table(* hookvar_gSaved_shade_tables )[100] = (void*)0x0053f0c0;
tCursor_giblet(* hookvar_gCursor_giblets )[45] = (void*)0x0053e808;
tTransient_bm(* hookvar_gTransient_bitmaps )[50] = (void*)0x0053f3f0;
float(* hookvar_gCosine_array )[64] = (void*)0x0054ff30;
br_pixelmap *(* hookvar_gCursors )[8] = (void*)0x0054b300;
br_pixelmap *(* hookvar_gCursor_giblet_images )[18] = (void*)0x00550040;
br_pixelmap ** hookvar_gEval_1  = (void*)0x0053e790;
#if 0
br_pixelmap ** hookvar_gEval_2 ;
#endif
br_vector3 * hookvar_gShadow_light_z  = (void*)0x0053f8b8;
br_vector3 * hookvar_gShadow_light_x  = (void*)0x0053f8a8;
#if 0
int * hookvar_gShadow_dim_amount ;
#endif
int * hookvar_gNumber_of_lollipops  = (void*)0x0053f8a0;
br_vector3 * hookvar_gShadow_light_ray  = (void*)0x0053f8c8;
int * hookvar_gFancy_shadow  = (void*)0x0053e788;
br_model ** hookvar_gShadow_model  = (void*)0x0053f93c;
br_actor ** hookvar_gShadow_actor  = (void*)0x0053e7fc;
int * hookvar_gShadow_clip_plane_count  = (void*)0x0053f928;
br_pixelmap ** hookvar_gPalette_conversion_table  = (void*)0x0053e800;
br_material ** hookvar_gShadow_material  = (void*)0x0053f92c;
int * hookvar_gSaved_table_count  = (void*)0x0053f3e8;
int * hookvar_gCurrent_cursor_index  = (void*)0x0053f3e0;
#if 0
int * hookvar_gPalette_index ;
#endif
int * hookvar_gCursor_transient_index  = (void*)0x0053f3e4;
char ** hookvar_gScratch_pixels  = (void*)0x0053f934;
br_pixelmap ** hookvar_gScratch_palette  = (void*)0x0053f078;
#if 0
int * hookvar_gLast_palette_change ;
#endif
br_pixelmap ** hookvar_gOrig_render_palette  = (void*)0x0053f8a4;
br_pixelmap ** hookvar_gCurrent_palette  = (void*)0x00550030;
br_pixelmap ** hookvar_gRender_palette  = (void*)0x0054fefc;
float * hookvar_gCamera_to_horiz_angle  = (void*)0x0054ff08;
int(* hookvar_gColours )[9] = (void*)0x0054b2d0;
br_pixelmap ** hookvar_gFlic_palette  = (void*)0x00550088;
tDR_font(* hookvar_gFonts )[21] = (void*)0x0054b330;
char ** hookvar_gCurrent_palette_pixels  = (void*)0x00550094;
int * hookvar_gWidth  = (void*)0x0054b320;
int * hookvar_gMap_render_height_i  = (void*)0x0054ff18;
int * hookvar_gScreen_wobble_x  = (void*)0x00550038;
int * hookvar_gScreen_wobble_y  = (void*)0x00550034;
br_scalar * hookvar_gCurrent_ambience  = (void*)0x0054ff0c;
int * hookvar_gY_offset  = (void*)0x0054b2cc;
int * hookvar_gMap_render_width_i  = (void*)0x0055008c;
int * hookvar_gMouse_in_use  = (void*)0x00550090;
int * hookvar_gHeight  = (void*)0x0054b2f8;
int * hookvar_gMouse_last_y_coord  = (void*)0x0054ff00;
int * hookvar_gMouse_last_x_coord  = (void*)0x0054b2f4;
br_scalar * hookvar_gAmbient_adjustment  = (void*)0x0054ff20;
int * hookvar_gMap_render_x_i  = (void*)0x0054ff14;
int * hookvar_gX_offset  = (void*)0x0054ff24;
int * hookvar_gMap_render_y_i  = (void*)0x0054ff10;
 // Suffix added to avoid duplicate symbol
int * hookvar_gMirror_on__graphics  = (void*)0x0054ff04;
br_scalar * hookvar_gYon_squared  = (void*)0x0054ff1c;

function_hook_state_t function_hook_state_TurnOnPaletteConversion = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_TurnOnPaletteConversion)
static void(__cdecl*original_TurnOnPaletteConversion)() = (void(__cdecl*)())0x004b3020;
CARM95_HOOK_FUNCTION(original_TurnOnPaletteConversion, TurnOnPaletteConversion)
void __cdecl TurnOnPaletteConversion() {
    LOG_TRACE("()");


    if (function_hook_state_TurnOnPaletteConversion == HOOK_ENABLED) {
        assert(0 && "TurnOnPaletteConversion not implemented.");
        abort();
    } else {
        original_TurnOnPaletteConversion();
    }
}

function_hook_state_t function_hook_state_TurnOffPaletteConversion = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_TurnOffPaletteConversion)
static void(__cdecl*original_TurnOffPaletteConversion)() = (void(__cdecl*)())0x004b3035;
CARM95_HOOK_FUNCTION(original_TurnOffPaletteConversion, TurnOffPaletteConversion)
void __cdecl TurnOffPaletteConversion() {
    LOG_TRACE("()");


    if (function_hook_state_TurnOffPaletteConversion == HOOK_ENABLED) {
        assert(0 && "TurnOffPaletteConversion not implemented.");
        abort();
    } else {
        original_TurnOffPaletteConversion();
    }
}

function_hook_state_t function_hook_state_ResetLollipopQueue = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_ResetLollipopQueue)
static void(__cdecl*original_ResetLollipopQueue)() = (void(__cdecl*)())0x004b304a;
CARM95_HOOK_FUNCTION(original_ResetLollipopQueue, ResetLollipopQueue)
void __cdecl ResetLollipopQueue() {
    LOG_TRACE("()");


    if (function_hook_state_ResetLollipopQueue == HOOK_ENABLED) {
        assert(0 && "ResetLollipopQueue not implemented.");
        abort();
    } else {
        original_ResetLollipopQueue();
    }
}

function_hook_state_t function_hook_state_AddToLollipopQueue = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_AddToLollipopQueue)
static int(__cdecl*original_AddToLollipopQueue)(br_actor *, int) = (int(__cdecl*)(br_actor *, int))0x004b305f;
CARM95_HOOK_FUNCTION(original_AddToLollipopQueue, AddToLollipopQueue)
int __cdecl AddToLollipopQueue(br_actor *pActor, int pIndex) {
    LOG_TRACE("(%p, %d)", pActor, pIndex);

    (void)pActor;
    (void)pIndex;

    if (function_hook_state_AddToLollipopQueue == HOOK_ENABLED) {
        assert(0 && "AddToLollipopQueue not implemented.");
        abort();
    } else {
        return original_AddToLollipopQueue(pActor, pIndex);
    }
}

function_hook_state_t function_hook_state_RenderLollipops = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_RenderLollipops)
static void(__cdecl*original_RenderLollipops)() = (void(__cdecl*)())0x004b6ac6;
CARM95_HOOK_FUNCTION(original_RenderLollipops, RenderLollipops)
void __cdecl RenderLollipops() {
    int i;
    int must_relink;
    br_actor **the_actor;
    br_actor *old_parent;
    LOG_TRACE("()");

    (void)i;
    (void)must_relink;
    (void)the_actor;
    (void)old_parent;

    if (function_hook_state_RenderLollipops == HOOK_ENABLED) {
        assert(0 && "RenderLollipops not implemented.");
        abort();
    } else {
        original_RenderLollipops();
    }
}

function_hook_state_t function_hook_state_DRDrawLine = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_DRDrawLine)
static void(__cdecl*original_DRDrawLine)(br_pixelmap *, int, int, int, int, int) = (void(__cdecl*)(br_pixelmap *, int, int, int, int, int))0x004b30c6;
CARM95_HOOK_FUNCTION(original_DRDrawLine, DRDrawLine)
void __cdecl DRDrawLine(br_pixelmap *pDestn, int pX1, int pY1, int pX2, int pY2, int pColour) {
    tU8 *d_ptr;
    tS32 y_delta;
    tS32 x_delta;
    tU32 current_y;
    tU32 current_x;
    int row_bytes;
    int x;
    int y;
    int the_diff;
    LOG_TRACE("(%p, %d, %d, %d, %d, %d)", pDestn, pX1, pY1, pX2, pY2, pColour);

    (void)pDestn;
    (void)pX1;
    (void)pY1;
    (void)pX2;
    (void)pY2;
    (void)pColour;
    (void)d_ptr;
    (void)y_delta;
    (void)x_delta;
    (void)current_y;
    (void)current_x;
    (void)row_bytes;
    (void)x;
    (void)y;
    (void)the_diff;

    if (function_hook_state_DRDrawLine == HOOK_ENABLED) {
        assert(0 && "DRDrawLine not implemented.");
        abort();
    } else {
        original_DRDrawLine(pDestn, pX1, pY1, pX2, pY2, pColour);
    }
}

function_hook_state_t function_hook_state_DrawDigitAt = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_DrawDigitAt)
static void(__cdecl*original_DrawDigitAt)(br_pixelmap *, int, int, int, int) = (void(__cdecl*)(br_pixelmap *, int, int, int, int))0x004b3180;
CARM95_HOOK_FUNCTION(original_DrawDigitAt, DrawDigitAt)
void __cdecl DrawDigitAt(br_pixelmap *gImage, int pX, int pY, int pY_pitch, int pValue) {
    LOG_TRACE("(%p, %d, %d, %d, %d)", gImage, pX, pY, pY_pitch, pValue);

    (void)gImage;
    (void)pX;
    (void)pY;
    (void)pY_pitch;
    (void)pValue;

    if (function_hook_state_DrawDigitAt == HOOK_ENABLED) {
        assert(0 && "DrawDigitAt not implemented.");
        abort();
    } else {
        original_DrawDigitAt(gImage, pX, pY, pY_pitch, pValue);
    }
}

function_hook_state_t function_hook_state_DrawNumberAt = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_DrawNumberAt)
static void(__cdecl*original_DrawNumberAt)(br_pixelmap *, int, int, int, int, int, int, int) = (void(__cdecl*)(br_pixelmap *, int, int, int, int, int, int, int))0x004b30f4;
CARM95_HOOK_FUNCTION(original_DrawNumberAt, DrawNumberAt)
void __cdecl DrawNumberAt(br_pixelmap *gImage, int pX, int pY, int pX_pitch, int pY_pitch, int pValue, int pDigit_count, int pLeading_zeroes) {
    int i;
    int the_value;
    LOG_TRACE("(%p, %d, %d, %d, %d, %d, %d, %d)", gImage, pX, pY, pX_pitch, pY_pitch, pValue, pDigit_count, pLeading_zeroes);

    (void)gImage;
    (void)pX;
    (void)pY;
    (void)pX_pitch;
    (void)pY_pitch;
    (void)pValue;
    (void)pDigit_count;
    (void)pLeading_zeroes;
    (void)i;
    (void)the_value;

    if (function_hook_state_DrawNumberAt == HOOK_ENABLED) {
        assert(0 && "DrawNumberAt not implemented.");
        abort();
    } else {
        original_DrawNumberAt(gImage, pX, pY, pX_pitch, pY_pitch, pValue, pDigit_count, pLeading_zeroes);
    }
}

function_hook_state_t function_hook_state_BuildColourTable = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_BuildColourTable)
static void(__cdecl*original_BuildColourTable)(br_pixelmap *) = (void(__cdecl*)(br_pixelmap *))0x004b31bb;
CARM95_HOOK_FUNCTION(original_BuildColourTable, BuildColourTable)
void __cdecl BuildColourTable(br_pixelmap *pPalette) {
    int i;
    int j;
    int nearest_index;
    int red;
    int green;
    int blue;
    float nearest_distance;
    float distance;
    LOG_TRACE("(%p)", pPalette);

    (void)pPalette;
    (void)i;
    (void)j;
    (void)nearest_index;
    (void)red;
    (void)green;
    (void)blue;
    (void)nearest_distance;
    (void)distance;

    if (function_hook_state_BuildColourTable == HOOK_ENABLED) {
        assert(0 && "BuildColourTable not implemented.");
        abort();
    } else {
        original_BuildColourTable(pPalette);
    }
}

function_hook_state_t function_hook_state_ClearConcussion = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_ClearConcussion)
static void(__cdecl*original_ClearConcussion)() = (void(__cdecl*)())0x004b32f2;
CARM95_HOOK_FUNCTION(original_ClearConcussion, ClearConcussion)
void __cdecl ClearConcussion() {
    LOG_TRACE("()");


    if (function_hook_state_ClearConcussion == HOOK_ENABLED) {
        assert(0 && "ClearConcussion not implemented.");
        abort();
    } else {
        original_ClearConcussion();
    }
}

function_hook_state_t function_hook_state_SkipLines = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_SkipLines)
static tS8 *(__cdecl*original_SkipLines)(tS8 *, int) = (tS8 *(__cdecl*)(tS8 *, int))0x004b3579;
CARM95_HOOK_FUNCTION(original_SkipLines, SkipLines)
tS8* __cdecl SkipLines(tS8 *pSource, int pCount) {
    int i;
    int j;
    int number_of_chunks;
    int chunk_length;
    LOG_TRACE("(%p, %d)", pSource, pCount);

    (void)pSource;
    (void)pCount;
    (void)i;
    (void)j;
    (void)number_of_chunks;
    (void)chunk_length;

    if (function_hook_state_SkipLines == HOOK_ENABLED) {
        assert(0 && "SkipLines not implemented.");
        abort();
    } else {
        return original_SkipLines(pSource, pCount);
    }
}

function_hook_state_t function_hook_state_CopyWords = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_CopyWords)
void CopyWords(char *pDst, char *pSrc, int pN) {
    tU16 *dst;
    tU16 *src;
    LOG_TRACE("(\"%s\", \"%s\", %d)", pDst, pSrc, pN);

    (void)pDst;
    (void)pSrc;
    (void)pN;
    (void)dst;
    (void)src;

    if (function_hook_state_CopyWords == HOOK_ENABLED) {
        assert(0 && "CopyWords not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}

function_hook_state_t function_hook_state_Copy8BitStripImageTo16Bit = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_Copy8BitStripImageTo16Bit)
void Copy8BitStripImageTo16Bit(br_pixelmap *pDest, br_int_16 pDest_x, br_int_16 pOffset_x, br_int_16 pDest_y, br_int_16 pOffset_y, tS8 *pSource, br_int_16 pSource_x, br_int_16 pSource_y, br_uint_16 pWidth, br_uint_16 pHeight) {
    int i;
    int j;
    int height;
    int number_of_chunks;
    int old_x_byte;
    int x_byte;
    int off_the_left;
    int destn_width;
    int chunk_length;
    char *destn_ptr;
    char *destn_ptr2;
    LOG_TRACE("(%p, %d, %d, %d, %d, %p, %d, %d, %u, %u)", pDest, pDest_x, pOffset_x, pDest_y, pOffset_y, pSource, pSource_x, pSource_y, pWidth, pHeight);

    (void)pDest;
    (void)pDest_x;
    (void)pOffset_x;
    (void)pDest_y;
    (void)pOffset_y;
    (void)pSource;
    (void)pSource_x;
    (void)pSource_y;
    (void)pWidth;
    (void)pHeight;
    (void)i;
    (void)j;
    (void)height;
    (void)number_of_chunks;
    (void)old_x_byte;
    (void)x_byte;
    (void)off_the_left;
    (void)destn_width;
    (void)chunk_length;
    (void)destn_ptr;
    (void)destn_ptr2;

    if (function_hook_state_Copy8BitStripImageTo16Bit == HOOK_ENABLED) {
        assert(0 && "Copy8BitStripImageTo16Bit not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}

function_hook_state_t function_hook_state_CopyStripImage = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_CopyStripImage)
static void(__cdecl*original_CopyStripImage)(br_pixelmap *, br_int_16, br_int_16, br_int_16, br_int_16, tS8 *, br_int_16, br_int_16, br_uint_16, br_uint_16) = (void(__cdecl*)(br_pixelmap *, br_int_16, br_int_16, br_int_16, br_int_16, tS8 *, br_int_16, br_int_16, br_uint_16, br_uint_16))0x004b3307;
CARM95_HOOK_FUNCTION(original_CopyStripImage, CopyStripImage)
void __cdecl CopyStripImage(br_pixelmap *pDest, br_int_16 pDest_x, br_int_16 pOffset_x, br_int_16 pDest_y, br_int_16 pOffset_y, tS8 *pSource, br_int_16 pSource_x, br_int_16 pSource_y, br_uint_16 pWidth, br_uint_16 pHeight) {
    int i;
    int j;
    int height;
    int number_of_chunks;
    int old_x_byte;
    int x_byte;
    int off_the_left;
    int destn_width;
    int chunk_length;
    char *destn_ptr;
    char *destn_ptr2;
    LOG_TRACE("(%p, %d, %d, %d, %d, %p, %d, %d, %u, %u)", pDest, pDest_x, pOffset_x, pDest_y, pOffset_y, pSource, pSource_x, pSource_y, pWidth, pHeight);

    (void)pDest;
    (void)pDest_x;
    (void)pOffset_x;
    (void)pDest_y;
    (void)pOffset_y;
    (void)pSource;
    (void)pSource_x;
    (void)pSource_y;
    (void)pWidth;
    (void)pHeight;
    (void)i;
    (void)j;
    (void)height;
    (void)number_of_chunks;
    (void)old_x_byte;
    (void)x_byte;
    (void)off_the_left;
    (void)destn_width;
    (void)chunk_length;
    (void)destn_ptr;
    (void)destn_ptr2;

    if (function_hook_state_CopyStripImage == HOOK_ENABLED) {
        assert(0 && "CopyStripImage not implemented.");
        abort();
    } else {
        original_CopyStripImage(pDest, pDest_x, pOffset_x, pDest_y, pOffset_y, pSource, pSource_x, pSource_y, pWidth, pHeight);
    }
}

function_hook_state_t function_hook_state_SetBRenderScreenAndBuffers = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_SetBRenderScreenAndBuffers)
static void(__cdecl*original_SetBRenderScreenAndBuffers)(int, int, int, int) = (void(__cdecl*)(int, int, int, int))0x004b35fb;
CARM95_HOOK_FUNCTION(original_SetBRenderScreenAndBuffers, SetBRenderScreenAndBuffers)
void __cdecl SetBRenderScreenAndBuffers(int pX_offset, int pY_offset, int pWidth, int pHeight) {
    LOG_TRACE("(%d, %d, %d, %d)", pX_offset, pY_offset, pWidth, pHeight);

    (void)pX_offset;
    (void)pY_offset;
    (void)pWidth;
    (void)pHeight;

    if (function_hook_state_SetBRenderScreenAndBuffers == HOOK_ENABLED) {
        assert(0 && "SetBRenderScreenAndBuffers not implemented.");
        abort();
    } else {
        original_SetBRenderScreenAndBuffers(pX_offset, pY_offset, pWidth, pHeight);
    }
}

function_hook_state_t function_hook_state_SetIntegerMapRenders = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_SetIntegerMapRenders)
static void(__cdecl*original_SetIntegerMapRenders)() = (void(__cdecl*)())0x004b3810;
CARM95_HOOK_FUNCTION(original_SetIntegerMapRenders, SetIntegerMapRenders)
void __cdecl SetIntegerMapRenders() {
    LOG_TRACE("()");


    if (function_hook_state_SetIntegerMapRenders == HOOK_ENABLED) {
        assert(0 && "SetIntegerMapRenders not implemented.");
        abort();
    } else {
        original_SetIntegerMapRenders();
    }
}

function_hook_state_t function_hook_state_AdjustRenderScreenSize = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_AdjustRenderScreenSize)
static void(__cdecl*original_AdjustRenderScreenSize)() = (void(__cdecl*)())0x004b3895;
CARM95_HOOK_FUNCTION(original_AdjustRenderScreenSize, AdjustRenderScreenSize)
void __cdecl AdjustRenderScreenSize() {
    int switched_res;
    LOG_TRACE("()");

    (void)switched_res;

    if (function_hook_state_AdjustRenderScreenSize == HOOK_ENABLED) {
        assert(0 && "AdjustRenderScreenSize not implemented.");
        abort();
    } else {
        original_AdjustRenderScreenSize();
    }
}

function_hook_state_t function_hook_state_ScreenSmaller = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_ScreenSmaller)
static void(__cdecl*original_ScreenSmaller)() = (void(__cdecl*)())0x004b39f4;
CARM95_HOOK_FUNCTION(original_ScreenSmaller, ScreenSmaller)
void __cdecl ScreenSmaller() {
    LOG_TRACE("()");


    if (function_hook_state_ScreenSmaller == HOOK_ENABLED) {
        assert(0 && "ScreenSmaller not implemented.");
        abort();
    } else {
        original_ScreenSmaller();
    }
}

function_hook_state_t function_hook_state_ScreenLarger = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_ScreenLarger)
static void(__cdecl*original_ScreenLarger)() = (void(__cdecl*)())0x004b3a40;
CARM95_HOOK_FUNCTION(original_ScreenLarger, ScreenLarger)
void __cdecl ScreenLarger() {
    LOG_TRACE("()");


    if (function_hook_state_ScreenLarger == HOOK_ENABLED) {
        assert(0 && "ScreenLarger not implemented.");
        abort();
    } else {
        original_ScreenLarger();
    }
}

function_hook_state_t function_hook_state_DRSetPaletteEntries = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_DRSetPaletteEntries)
static void(__cdecl*original_DRSetPaletteEntries)(br_pixelmap *, int, int) = (void(__cdecl*)(br_pixelmap *, int, int))0x004b3a85;
CARM95_HOOK_FUNCTION(original_DRSetPaletteEntries, DRSetPaletteEntries)
void __cdecl DRSetPaletteEntries(br_pixelmap *pPalette, int pFirst_colour, int pCount) {
    LOG_TRACE("(%p, %d, %d)", pPalette, pFirst_colour, pCount);

    (void)pPalette;
    (void)pFirst_colour;
    (void)pCount;

    if (function_hook_state_DRSetPaletteEntries == HOOK_ENABLED) {
        assert(0 && "DRSetPaletteEntries not implemented.");
        abort();
    } else {
        original_DRSetPaletteEntries(pPalette, pFirst_colour, pCount);
    }
}

function_hook_state_t function_hook_state_DRSetPalette3 = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_DRSetPalette3)
static void(__cdecl*original_DRSetPalette3)(br_pixelmap *, int) = (void(__cdecl*)(br_pixelmap *, int))0x004b3af8;
CARM95_HOOK_FUNCTION(original_DRSetPalette3, DRSetPalette3)
void __cdecl DRSetPalette3(br_pixelmap *pThe_palette, int pSet_current_palette) {
    LOG_TRACE("(%p, %d)", pThe_palette, pSet_current_palette);

    (void)pThe_palette;
    (void)pSet_current_palette;

    if (function_hook_state_DRSetPalette3 == HOOK_ENABLED) {
        assert(0 && "DRSetPalette3 not implemented.");
        abort();
    } else {
        original_DRSetPalette3(pThe_palette, pSet_current_palette);
    }
}

function_hook_state_t function_hook_state_DRSetPalette2 = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_DRSetPalette2)
static void(__cdecl*original_DRSetPalette2)(br_pixelmap *, int) = (void(__cdecl*)(br_pixelmap *, int))0x004b3b53;
CARM95_HOOK_FUNCTION(original_DRSetPalette2, DRSetPalette2)
void __cdecl DRSetPalette2(br_pixelmap *pThe_palette, int pSet_current_palette) {
    LOG_TRACE("(%p, %d)", pThe_palette, pSet_current_palette);

    (void)pThe_palette;
    (void)pSet_current_palette;

    if (function_hook_state_DRSetPalette2 == HOOK_ENABLED) {
        assert(0 && "DRSetPalette2 not implemented.");
        abort();
    } else {
        original_DRSetPalette2(pThe_palette, pSet_current_palette);
    }
}

function_hook_state_t function_hook_state_DRSetPalette = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_DRSetPalette)
static void(__cdecl*original_DRSetPalette)(br_pixelmap *) = (void(__cdecl*)(br_pixelmap *))0x004b3bba;
CARM95_HOOK_FUNCTION(original_DRSetPalette, DRSetPalette)
void __cdecl DRSetPalette(br_pixelmap *pThe_palette) {
    LOG_TRACE("(%p)", pThe_palette);

    (void)pThe_palette;

    if (function_hook_state_DRSetPalette == HOOK_ENABLED) {
        assert(0 && "DRSetPalette not implemented.");
        abort();
    } else {
        original_DRSetPalette(pThe_palette);
    }
}

function_hook_state_t function_hook_state_InitializePalettes = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_InitializePalettes)
static void(__cdecl*original_InitializePalettes)() = (void(__cdecl*)())0x004b3bd3;
CARM95_HOOK_FUNCTION(original_InitializePalettes, InitializePalettes)
void __cdecl InitializePalettes() {
    int i;
    int j;
    LOG_TRACE("()");

    (void)i;
    (void)j;

    if (function_hook_state_InitializePalettes == HOOK_ENABLED) {
        assert(0 && "InitializePalettes not implemented.");
        abort();
    } else {
        original_InitializePalettes();
    }
}

function_hook_state_t function_hook_state_SwitchToPalette = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_SwitchToPalette)
static void(__cdecl*original_SwitchToPalette)(char *) = (void(__cdecl*)(char *))0x004b3d43;
CARM95_HOOK_FUNCTION(original_SwitchToPalette, SwitchToPalette)
void __cdecl SwitchToPalette(char *pPal_name) {
    br_pixelmap *the_palette;
    LOG_TRACE("(\"%s\")", pPal_name);

    (void)pPal_name;
    (void)the_palette;

    if (function_hook_state_SwitchToPalette == HOOK_ENABLED) {
        assert(0 && "SwitchToPalette not implemented.");
        abort();
    } else {
        original_SwitchToPalette(pPal_name);
    }
}

function_hook_state_t function_hook_state_ClearEntireScreen = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_ClearEntireScreen)
static void(__cdecl*original_ClearEntireScreen)() = (void(__cdecl*)())0x004b3d76;
CARM95_HOOK_FUNCTION(original_ClearEntireScreen, ClearEntireScreen)
void __cdecl ClearEntireScreen() {
    LOG_TRACE("()");


    if (function_hook_state_ClearEntireScreen == HOOK_ENABLED) {
        assert(0 && "ClearEntireScreen not implemented.");
        abort();
    } else {
        original_ClearEntireScreen();
    }
}

function_hook_state_t function_hook_state_ClearWobbles = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_ClearWobbles)
static void(__cdecl*original_ClearWobbles)() = (void(__cdecl*)())0x004b3dde;
CARM95_HOOK_FUNCTION(original_ClearWobbles, ClearWobbles)
void __cdecl ClearWobbles() {
    int i;
    LOG_TRACE("()");

    (void)i;

    if (function_hook_state_ClearWobbles == HOOK_ENABLED) {
        assert(0 && "ClearWobbles not implemented.");
        abort();
    } else {
        original_ClearWobbles();
    }
}

function_hook_state_t function_hook_state_InitWobbleStuff = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_InitWobbleStuff)
static void(__cdecl*original_InitWobbleStuff)() = (void(__cdecl*)())0x004b3e1a;
CARM95_HOOK_FUNCTION(original_InitWobbleStuff, InitWobbleStuff)
void __cdecl InitWobbleStuff() {
    int i;
    LOG_TRACE("()");

    (void)i;

    if (function_hook_state_InitWobbleStuff == HOOK_ENABLED) {
        assert(0 && "InitWobbleStuff not implemented.");
        abort();
    } else {
        original_InitWobbleStuff();
    }
}

function_hook_state_t function_hook_state_NewScreenWobble = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_NewScreenWobble)
static void(__cdecl*original_NewScreenWobble)(double, double, double) = (void(__cdecl*)(double, double, double))0x004b3e75;
CARM95_HOOK_FUNCTION(original_NewScreenWobble, NewScreenWobble)
void __cdecl NewScreenWobble(double pAmplitude_x, double pAmplitude_y, double pPeriod) {
    int i;
    int oldest_time;
    int oldest_index;
    LOG_TRACE("(%f, %f, %f)", pAmplitude_x, pAmplitude_y, pPeriod);

    (void)pAmplitude_x;
    (void)pAmplitude_y;
    (void)pPeriod;
    (void)i;
    (void)oldest_time;
    (void)oldest_index;

    if (function_hook_state_NewScreenWobble == HOOK_ENABLED) {
        assert(0 && "NewScreenWobble not implemented.");
        abort();
    } else {
        original_NewScreenWobble(pAmplitude_x, pAmplitude_y, pPeriod);
    }
}

function_hook_state_t function_hook_state_SetScreenWobble = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_SetScreenWobble)
static void(__cdecl*original_SetScreenWobble)(int, int) = (void(__cdecl*)(int, int))0x004b3f3a;
CARM95_HOOK_FUNCTION(original_SetScreenWobble, SetScreenWobble)
void __cdecl SetScreenWobble(int pWobble_x, int pWobble_y) {
    LOG_TRACE("(%d, %d)", pWobble_x, pWobble_y);

    (void)pWobble_x;
    (void)pWobble_y;

    if (function_hook_state_SetScreenWobble == HOOK_ENABLED) {
        assert(0 && "SetScreenWobble not implemented.");
        abort();
    } else {
        original_SetScreenWobble(pWobble_x, pWobble_y);
    }
}

function_hook_state_t function_hook_state_ResetScreenWobble = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_ResetScreenWobble)
static void(__cdecl*original_ResetScreenWobble)() = (void(__cdecl*)())0x004b3f55;
CARM95_HOOK_FUNCTION(original_ResetScreenWobble, ResetScreenWobble)
void __cdecl ResetScreenWobble() {
    LOG_TRACE("()");


    if (function_hook_state_ResetScreenWobble == HOOK_ENABLED) {
        assert(0 && "ResetScreenWobble not implemented.");
        abort();
    } else {
        original_ResetScreenWobble();
    }
}

function_hook_state_t function_hook_state_CalculateWobblitude = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_CalculateWobblitude)
static void(__cdecl*original_CalculateWobblitude)(tU32) = (void(__cdecl*)(tU32))0x004b6baf;
CARM95_HOOK_FUNCTION(original_CalculateWobblitude, CalculateWobblitude)
void __cdecl CalculateWobblitude(tU32 pThe_time) {
    int i;
    tU32 time_going;
    double angle;
    double mod_angle;
    double cosine_over_angle;
    LOG_TRACE("(%u)", pThe_time);

    (void)pThe_time;
    (void)i;
    (void)time_going;
    (void)angle;
    (void)mod_angle;
    (void)cosine_over_angle;

    if (function_hook_state_CalculateWobblitude == HOOK_ENABLED) {
        assert(0 && "CalculateWobblitude not implemented.");
        abort();
    } else {
        original_CalculateWobblitude(pThe_time);
    }
}

function_hook_state_t function_hook_state_CalculateConcussion = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_CalculateConcussion)
static void(__cdecl*original_CalculateConcussion)(tU32) = (void(__cdecl*)(tU32))0x004b6e97;
CARM95_HOOK_FUNCTION(original_CalculateConcussion, CalculateConcussion)
void __cdecl CalculateConcussion(tU32 pThe_time) {
    tU32 time_difference;
    int i;
    int j;
    float the_amplitude;
    float angle;
    float mod_angle;
    float cosine_over_angle;
    LOG_TRACE("(%u)", pThe_time);

    (void)pThe_time;
    (void)time_difference;
    (void)i;
    (void)j;
    (void)the_amplitude;
    (void)angle;
    (void)mod_angle;
    (void)cosine_over_angle;

    if (function_hook_state_CalculateConcussion == HOOK_ENABLED) {
        assert(0 && "CalculateConcussion not implemented.");
        abort();
    } else {
        original_CalculateConcussion(pThe_time);
    }
}

function_hook_state_t function_hook_state_SufferFromConcussion = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_SufferFromConcussion)
static void(__cdecl*original_SufferFromConcussion)(float) = (void(__cdecl*)(float))0x004b3f6c;
CARM95_HOOK_FUNCTION(original_SufferFromConcussion, SufferFromConcussion)
void __cdecl SufferFromConcussion(float pSeriousness) {
    int i;
    int j;
    LOG_TRACE("(%f)", pSeriousness);

    (void)pSeriousness;
    (void)i;
    (void)j;

    if (function_hook_state_SufferFromConcussion == HOOK_ENABLED) {
        assert(0 && "SufferFromConcussion not implemented.");
        abort();
    } else {
        original_SufferFromConcussion(pSeriousness);
    }
}

function_hook_state_t function_hook_state_ProcessNonTrackActors = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_ProcessNonTrackActors)
static void(__cdecl*original_ProcessNonTrackActors)(br_pixelmap *, br_pixelmap *, br_actor *, br_matrix34 *, br_matrix34 *) = (void(__cdecl*)(br_pixelmap *, br_pixelmap *, br_actor *, br_matrix34 *, br_matrix34 *))0x004b70e5;
CARM95_HOOK_FUNCTION(original_ProcessNonTrackActors, ProcessNonTrackActors)
void __cdecl ProcessNonTrackActors(br_pixelmap *pRender_buffer, br_pixelmap *pDepth_buffer, br_actor *pCamera, br_matrix34 *pCamera_to_world, br_matrix34 *pOld_camera_matrix) {
    LOG_TRACE("(%p, %p, %p, %p, %p)", pRender_buffer, pDepth_buffer, pCamera, pCamera_to_world, pOld_camera_matrix);

    (void)pRender_buffer;
    (void)pDepth_buffer;
    (void)pCamera;
    (void)pCamera_to_world;
    (void)pOld_camera_matrix;

    if (function_hook_state_ProcessNonTrackActors == HOOK_ENABLED) {
        assert(0 && "ProcessNonTrackActors not implemented.");
        abort();
    } else {
        original_ProcessNonTrackActors(pRender_buffer, pDepth_buffer, pCamera, pCamera_to_world, pOld_camera_matrix);
    }
}

function_hook_state_t function_hook_state_OppositeColour = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_OppositeColour)
static int(__cdecl*original_OppositeColour)(int) = (int(__cdecl*)(int))0x004b764f;
CARM95_HOOK_FUNCTION(original_OppositeColour, OppositeColour)
int __cdecl OppositeColour(int pColour) {
    int brightness;
    LOG_TRACE("(%d)", pColour);

    (void)pColour;
    (void)brightness;

    if (function_hook_state_OppositeColour == HOOK_ENABLED) {
        assert(0 && "OppositeColour not implemented.");
        abort();
    } else {
        return original_OppositeColour(pColour);
    }
}

function_hook_state_t function_hook_state_DrawMapBlip = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_DrawMapBlip)
static void(__cdecl*original_DrawMapBlip)(tCar_spec *, tU32, br_matrix34 *, br_vector3 *, int) = (void(__cdecl*)(tCar_spec *, tU32, br_matrix34 *, br_vector3 *, int))0x004b70fe;
CARM95_HOOK_FUNCTION(original_DrawMapBlip, DrawMapBlip)
void __cdecl DrawMapBlip(tCar_spec *pCar, tU32 pTime, br_matrix34 *pTrans, br_vector3 *pPos, int pColour) {
    br_vector3 map_pos;
    int offset;
    int *arrow_ptr;
    int point_count;
    int colours[2];
    int x;
    int y;
    int colour;
    int i;
    int j;
    int temp;
    int from_x;
    int from_y;
    int to_x;
    int to_y;
    int arrow_index;
    tU32 time_diff;
    tU32 period;
    br_matrix34 car_in_map_space;
    float bearing;
    float cos_factor;
    float sin_factor;
    LOG_TRACE("(%p, %u, %p, %p, %d)", pCar, pTime, pTrans, pPos, pColour);

    (void)pCar;
    (void)pTime;
    (void)pTrans;
    (void)pPos;
    (void)pColour;
    (void)map_pos;
    (void)offset;
    (void)arrow_ptr;
    (void)point_count;
    (void)colours;
    (void)x;
    (void)y;
    (void)colour;
    (void)i;
    (void)j;
    (void)temp;
    (void)from_x;
    (void)from_y;
    (void)to_x;
    (void)to_y;
    (void)arrow_index;
    (void)time_diff;
    (void)period;
    (void)car_in_map_space;
    (void)bearing;
    (void)cos_factor;
    (void)sin_factor;

    if (function_hook_state_DrawMapBlip == HOOK_ENABLED) {
        assert(0 && "DrawMapBlip not implemented.");
        abort();
    } else {
        original_DrawMapBlip(pCar, pTime, pTrans, pPos, pColour);
    }
}

function_hook_state_t function_hook_state_DrawMapSmallBlip = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_DrawMapSmallBlip)
static void(__cdecl*original_DrawMapSmallBlip)(tU32, br_vector3 *, int) = (void(__cdecl*)(tU32, br_vector3 *, int))0x004b76c3;
CARM95_HOOK_FUNCTION(original_DrawMapSmallBlip, DrawMapSmallBlip)
void __cdecl DrawMapSmallBlip(tU32 pTime, br_vector3 *pPos, int pColour) {
    br_vector3 map_pos;
    int offset;
    tU32 time_diff;
    LOG_TRACE("(%u, %p, %d)", pTime, pPos, pColour);

    (void)pTime;
    (void)pPos;
    (void)pColour;
    (void)map_pos;
    (void)offset;
    (void)time_diff;

    if (function_hook_state_DrawMapSmallBlip == HOOK_ENABLED) {
        assert(0 && "DrawMapSmallBlip not implemented.");
        abort();
    } else {
        original_DrawMapSmallBlip(pTime, pPos, pColour);
    }
}

function_hook_state_t function_hook_state_MungeClipPlane = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_MungeClipPlane)
static void(__cdecl*original_MungeClipPlane)(br_vector3 *, tCar_spec *, br_vector3 *, br_vector3 *, br_scalar) = (void(__cdecl*)(br_vector3 *, tCar_spec *, br_vector3 *, br_vector3 *, br_scalar))0x004b553b;
CARM95_HOOK_FUNCTION(original_MungeClipPlane, MungeClipPlane)
void __cdecl MungeClipPlane(br_vector3 *pLight, tCar_spec *pCar, br_vector3 *p1, br_vector3 *p2, br_scalar pY_offset) {
    br_vector3 v1;
    br_vector3 v2;
    br_vector3 v3;
    br_vector3 v4;
    br_scalar length;
    br_actor *new_clip;
    br_scalar __block0___scale;
    LOG_TRACE("(%p, %p, %p, %p, %f)", pLight, pCar, p1, p2, pY_offset);

    (void)pLight;
    (void)pCar;
    (void)p1;
    (void)p2;
    (void)pY_offset;
    (void)v1;
    (void)v2;
    (void)v3;
    (void)v4;
    (void)length;
    (void)new_clip;
    (void)__block0___scale;

    if (function_hook_state_MungeClipPlane == HOOK_ENABLED) {
        assert(0 && "MungeClipPlane not implemented.");
        abort();
    } else {
        original_MungeClipPlane(pLight, pCar, p1, p2, pY_offset);
    }
}

function_hook_state_t function_hook_state_TryThisEdge = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_TryThisEdge)
static void(__cdecl*original_TryThisEdge)(tCar_spec *, br_vector3 *, int, br_scalar, int, br_scalar, int, int, br_scalar) = (void(__cdecl*)(tCar_spec *, br_vector3 *, int, br_scalar, int, br_scalar, int, int, br_scalar))0x004b547f;
CARM95_HOOK_FUNCTION(original_TryThisEdge, TryThisEdge)
void __cdecl TryThisEdge(tCar_spec *pCar, br_vector3 *pLight, int pIndex_1, br_scalar pSign_1, int pIndex_2, br_scalar pSign_2, int pPoint_index_1, int pPoint_index_2, br_scalar pY_offset) {
    br_scalar dot_1;
    br_scalar dot_2;
    br_scalar mult;
    LOG_TRACE("(%p, %p, %d, %f, %d, %f, %d, %d, %f)", pCar, pLight, pIndex_1, pSign_1, pIndex_2, pSign_2, pPoint_index_1, pPoint_index_2, pY_offset);

    (void)pCar;
    (void)pLight;
    (void)pIndex_1;
    (void)pSign_1;
    (void)pIndex_2;
    (void)pSign_2;
    (void)pPoint_index_1;
    (void)pPoint_index_2;
    (void)pY_offset;
    (void)dot_1;
    (void)dot_2;
    (void)mult;

    if (function_hook_state_TryThisEdge == HOOK_ENABLED) {
        assert(0 && "TryThisEdge not implemented.");
        abort();
    } else {
        original_TryThisEdge(pCar, pLight, pIndex_1, pSign_1, pIndex_2, pSign_2, pPoint_index_1, pPoint_index_2, pY_offset);
    }
}

function_hook_state_t function_hook_state_DistanceFromPlane = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_DistanceFromPlane)
static br_scalar(__cdecl*original_DistanceFromPlane)(br_vector3 *, br_scalar, br_scalar, br_scalar, br_scalar) = (br_scalar(__cdecl*)(br_vector3 *, br_scalar, br_scalar, br_scalar, br_scalar))0x004b400e;
CARM95_HOOK_FUNCTION(original_DistanceFromPlane, DistanceFromPlane)
br_scalar __cdecl DistanceFromPlane(br_vector3 *pPos, br_scalar pA, br_scalar pB, br_scalar pC, br_scalar pD) {
    br_vector3 normal;
    LOG_TRACE("(%p, %f, %f, %f, %f)", pPos, pA, pB, pC, pD);

    (void)pPos;
    (void)pA;
    (void)pB;
    (void)pC;
    (void)pD;
    (void)normal;

    if (function_hook_state_DistanceFromPlane == HOOK_ENABLED) {
        assert(0 && "DistanceFromPlane not implemented.");
        abort();
    } else {
        return original_DistanceFromPlane(pPos, pA, pB, pC, pD);
    }
}

function_hook_state_t function_hook_state_DisableLights = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_DisableLights)
void DisableLights() {
    int i;
    LOG_TRACE("()");

    (void)i;

    if (function_hook_state_DisableLights == HOOK_ENABLED) {
        assert(0 && "DisableLights not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}

function_hook_state_t function_hook_state_EnableLights = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_EnableLights)
void EnableLights() {
    int i;
    LOG_TRACE("()");

    (void)i;

    if (function_hook_state_EnableLights == HOOK_ENABLED) {
        assert(0 && "EnableLights not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}

function_hook_state_t function_hook_state_ProcessShadow = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_ProcessShadow)
static void(__cdecl*original_ProcessShadow)(tCar_spec *, br_actor *, tTrack_spec *, br_actor *, br_matrix34 *, br_scalar) = (void(__cdecl*)(tCar_spec *, br_actor *, tTrack_spec *, br_actor *, br_matrix34 *, br_scalar))0x004b405c;
CARM95_HOOK_FUNCTION(original_ProcessShadow, ProcessShadow)
void __cdecl ProcessShadow(tCar_spec *pCar, br_actor *pWorld, tTrack_spec *pTrack_spec, br_actor *pCamera, br_matrix34 *pCamera_to_world_transform, br_scalar pDistance_factor) {
    int i;
    int j;
    int face_count;
    int force_shadow;
    int models_used;
    int point_to_use;
    int oily_count;
    int f_num;
    br_vector3 pos;
    br_vector3 light_ray_car;
    br_vector3 temp_v;
    br_vector3 shadow_points_world[8];
    br_vector3 poly_centre;
    br_vector3 car_to_poly;
    br_vector3 ray;
    br_vector3 ray_pos;
    br_vector3 normal;
    br_vector3 the_normal;
    br_vector3 pos_cam_space;
    br_vector3 *v0;
    br_vector3 *v1;
    br_vector3 *v2;
    br_vector4 *clip_normal;
    br_scalar bounds_x_min;
    br_scalar bounds_x_max;
    br_scalar bounds_y_min;
    br_scalar bounds_y_max;
    br_scalar bounds_z_min;
    br_scalar bounds_z_max;
    br_scalar height;
    br_scalar oily_size;
    br_scalar highest_underneath;
    br_scalar shadow_scaling_factor;
    br_scalar y_offset;
    br_scalar most_neg_dotty;
    br_scalar mr_dotty;
    br_scalar first_poly_below;
    br_scalar distance;
    br_scalar camera_hither_fudge;
    br_scalar camera_angle_additional_fudge;
    br_scalar ray_length;
    tBounds kev_bounds;
    tFace_ref the_list[100];
    tFace_ref *face_ref;
    tFace_ref *list_ptr;
    br_renderbounds_cbfn *old_call_back;
    br_camera *camera_ptr;
    br_actor *oily_actor;
    br_model *model;
    br_material *material;
    br_vertex verts[48];
    br_face faces[16];
    LOG_TRACE("(%p, %p, %p, %p, %p, %f)", pCar, pWorld, pTrack_spec, pCamera, pCamera_to_world_transform, pDistance_factor);

    (void)pCar;
    (void)pWorld;
    (void)pTrack_spec;
    (void)pCamera;
    (void)pCamera_to_world_transform;
    (void)pDistance_factor;
    (void)i;
    (void)j;
    (void)face_count;
    (void)force_shadow;
    (void)models_used;
    (void)point_to_use;
    (void)oily_count;
    (void)f_num;
    (void)pos;
    (void)light_ray_car;
    (void)temp_v;
    (void)shadow_points_world;
    (void)poly_centre;
    (void)car_to_poly;
    (void)ray;
    (void)ray_pos;
    (void)normal;
    (void)the_normal;
    (void)pos_cam_space;
    (void)v0;
    (void)v1;
    (void)v2;
    (void)clip_normal;
    (void)bounds_x_min;
    (void)bounds_x_max;
    (void)bounds_y_min;
    (void)bounds_y_max;
    (void)bounds_z_min;
    (void)bounds_z_max;
    (void)height;
    (void)oily_size;
    (void)highest_underneath;
    (void)shadow_scaling_factor;
    (void)y_offset;
    (void)most_neg_dotty;
    (void)mr_dotty;
    (void)first_poly_below;
    (void)distance;
    (void)camera_hither_fudge;
    (void)camera_angle_additional_fudge;
    (void)ray_length;
    (void)kev_bounds;
    (void)the_list;
    (void)face_ref;
    (void)list_ptr;
    (void)old_call_back;
    (void)camera_ptr;
    (void)oily_actor;
    (void)model;
    (void)material;
    (void)verts;
    (void)faces;

    if (function_hook_state_ProcessShadow == HOOK_ENABLED) {
        assert(0 && "ProcessShadow not implemented.");
        abort();
    } else {
        original_ProcessShadow(pCar, pWorld, pTrack_spec, pCamera, pCamera_to_world_transform, pDistance_factor);
    }
}

function_hook_state_t function_hook_state_RenderShadows = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_RenderShadows)
static void(__cdecl*original_RenderShadows)(br_actor *, tTrack_spec *, br_actor *, br_matrix34 *) = (void(__cdecl*)(br_actor *, tTrack_spec *, br_actor *, br_matrix34 *))0x004b57b6;
CARM95_HOOK_FUNCTION(original_RenderShadows, RenderShadows)
void __cdecl RenderShadows(br_actor *pWorld, tTrack_spec *pTrack_spec, br_actor *pCamera, br_matrix34 *pCamera_to_world_transform) {
    int i;
    int cat;
    int car_count;
    tCar_spec *the_car;
    br_vector3 camera_to_car;
    br_scalar distance_factor;
    LOG_TRACE("(%p, %p, %p, %p)", pWorld, pTrack_spec, pCamera, pCamera_to_world_transform);

    (void)pWorld;
    (void)pTrack_spec;
    (void)pCamera;
    (void)pCamera_to_world_transform;
    (void)i;
    (void)cat;
    (void)car_count;
    (void)the_car;
    (void)camera_to_car;
    (void)distance_factor;

    if (function_hook_state_RenderShadows == HOOK_ENABLED) {
        assert(0 && "RenderShadows not implemented.");
        abort();
    } else {
        original_RenderShadows(pWorld, pTrack_spec, pCamera, pCamera_to_world_transform);
    }
}

function_hook_state_t function_hook_state_FlashyMapCheckpoint = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_FlashyMapCheckpoint)
static void(__cdecl*original_FlashyMapCheckpoint)(int, tU32) = (void(__cdecl*)(int, tU32))0x004b7754;
CARM95_HOOK_FUNCTION(original_FlashyMapCheckpoint, FlashyMapCheckpoint)
void __cdecl FlashyMapCheckpoint(int pIndex, tU32 pTime) {
    tCheckpoint *cp;
    static tU32 last_flash;
    static int flash_state;
    LOG_TRACE("(%d, %u)", pIndex, pTime);

    (void)pIndex;
    (void)pTime;
    (void)cp;
    (void)last_flash;
    (void)flash_state;

    if (function_hook_state_FlashyMapCheckpoint == HOOK_ENABLED) {
        assert(0 && "FlashyMapCheckpoint not implemented.");
        abort();
    } else {
        original_FlashyMapCheckpoint(pIndex, pTime);
    }
}

function_hook_state_t function_hook_state_ConditionallyFillWithSky = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_ConditionallyFillWithSky)
static int(__cdecl*original_ConditionallyFillWithSky)(br_pixelmap *) = (int(__cdecl*)(br_pixelmap *))0x004b784d;
CARM95_HOOK_FUNCTION(original_ConditionallyFillWithSky, ConditionallyFillWithSky)
int __cdecl ConditionallyFillWithSky(br_pixelmap *pPixelmap) {
    int bgnd_col;
    LOG_TRACE("(%p)", pPixelmap);

    (void)pPixelmap;
    (void)bgnd_col;

    if (function_hook_state_ConditionallyFillWithSky == HOOK_ENABLED) {
        assert(0 && "ConditionallyFillWithSky not implemented.");
        abort();
    } else {
        return original_ConditionallyFillWithSky(pPixelmap);
    }
}

function_hook_state_t function_hook_state_RenderAFrame = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_RenderAFrame)
static void(__cdecl*original_RenderAFrame)(int) = (void(__cdecl*)(int))0x004b59ce;
CARM95_HOOK_FUNCTION(original_RenderAFrame, RenderAFrame)
void __cdecl RenderAFrame(int pDepth_mask_on) {
    int cat;
    int i;
    int car_count;
    int flags;
    int x_shift;
    int y_shift;
    int cockpit_on;
    int real_origin_x;
    int real_origin_y;
    int real_base_x;
    int real_base_y;
    int map_timer_x;
    int map_timer_width;
    int ped_type;
    char *old_pixels;
    br_matrix34 old_camera_matrix;
    br_matrix34 old_mirror_cam_matrix;
    tU32 the_time;
    br_vector3 *car_pos;
    br_vector3 pos;
    char the_text[256];
    tCar_spec *car;
    LOG_TRACE("(%d)", pDepth_mask_on);

    (void)pDepth_mask_on;
    (void)cat;
    (void)i;
    (void)car_count;
    (void)flags;
    (void)x_shift;
    (void)y_shift;
    (void)cockpit_on;
    (void)real_origin_x;
    (void)real_origin_y;
    (void)real_base_x;
    (void)real_base_y;
    (void)map_timer_x;
    (void)map_timer_width;
    (void)ped_type;
    (void)old_pixels;
    (void)old_camera_matrix;
    (void)old_mirror_cam_matrix;
    (void)the_time;
    (void)car_pos;
    (void)pos;
    (void)the_text;
    (void)car;

    if (function_hook_state_RenderAFrame == HOOK_ENABLED) {
        assert(0 && "RenderAFrame not implemented.");
        abort();
    } else {
        original_RenderAFrame(pDepth_mask_on);
    }
}

function_hook_state_t function_hook_state_InitPaletteAnimate = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_InitPaletteAnimate)
static void(__cdecl*original_InitPaletteAnimate)() = (void(__cdecl*)())0x004b7932;
CARM95_HOOK_FUNCTION(original_InitPaletteAnimate, InitPaletteAnimate)
void __cdecl InitPaletteAnimate() {
    LOG_TRACE("()");


    if (function_hook_state_InitPaletteAnimate == HOOK_ENABLED) {
        assert(0 && "InitPaletteAnimate not implemented.");
        abort();
    } else {
        original_InitPaletteAnimate();
    }
}

function_hook_state_t function_hook_state_RevertPalette = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_RevertPalette)
static void(__cdecl*original_RevertPalette)() = (void(__cdecl*)())0x004b7951;
CARM95_HOOK_FUNCTION(original_RevertPalette, RevertPalette)
void __cdecl RevertPalette() {
    LOG_TRACE("()");


    if (function_hook_state_RevertPalette == HOOK_ENABLED) {
        assert(0 && "RevertPalette not implemented.");
        abort();
    } else {
        original_RevertPalette();
    }
}

function_hook_state_t function_hook_state_MungePalette = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_MungePalette)
void MungePalette() {
    tU8 *p;
    tU8 *q;
    int i;
    float damage;
    float throb_start;
    float throb_end;
    float throb_amount;
    float throb_amount_dash;
    float omega;
    tU32 period;
    tU32 the_time;
    static int palette_spammed;
    static float last_omega;
    static tU32 next_repair_time;
    static tU32 last_sound;
    LOG_TRACE("()");

    (void)p;
    (void)q;
    (void)i;
    (void)damage;
    (void)throb_start;
    (void)throb_end;
    (void)throb_amount;
    (void)throb_amount_dash;
    (void)omega;
    (void)period;
    (void)the_time;
    (void)palette_spammed;
    (void)last_omega;
    (void)next_repair_time;
    (void)last_sound;

    if (function_hook_state_MungePalette == HOOK_ENABLED) {
        assert(0 && "MungePalette not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}

function_hook_state_t function_hook_state_ResetPalette = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_ResetPalette)
static void(__cdecl*original_ResetPalette)() = (void(__cdecl*)())0x004b7997;
CARM95_HOOK_FUNCTION(original_ResetPalette, ResetPalette)
void __cdecl ResetPalette() {
    LOG_TRACE("()");


    if (function_hook_state_ResetPalette == HOOK_ENABLED) {
        assert(0 && "ResetPalette not implemented.");
        abort();
    } else {
        original_ResetPalette();
    }
}

function_hook_state_t function_hook_state_Darken = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_Darken)
static void(__cdecl*original_Darken)(tU8 *, unsigned int) = (void(__cdecl*)(tU8 *, unsigned int))0x004b7a74;
CARM95_HOOK_FUNCTION(original_Darken, Darken)
void __cdecl Darken(tU8 *pPtr, unsigned int pDarken_amount) {
    unsigned int value;
    LOG_TRACE("(%p, %u)", pPtr, pDarken_amount);

    (void)pPtr;
    (void)pDarken_amount;
    (void)value;

    if (function_hook_state_Darken == HOOK_ENABLED) {
        assert(0 && "Darken not implemented.");
        abort();
    } else {
        original_Darken(pPtr, pDarken_amount);
    }
}

function_hook_state_t function_hook_state_SetFadedPalette = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_SetFadedPalette)
static void(__cdecl*original_SetFadedPalette)(int) = (void(__cdecl*)(int))0x004b79b5;
CARM95_HOOK_FUNCTION(original_SetFadedPalette, SetFadedPalette)
void __cdecl SetFadedPalette(int pDegree) {
    int j;
    br_pixelmap *the_palette;
    char *the_pixels;
    LOG_TRACE("(%d)", pDegree);

    (void)pDegree;
    (void)j;
    (void)the_palette;
    (void)the_pixels;

    if (function_hook_state_SetFadedPalette == HOOK_ENABLED) {
        assert(0 && "SetFadedPalette not implemented.");
        abort();
    } else {
        original_SetFadedPalette(pDegree);
    }
}

function_hook_state_t function_hook_state_FadePaletteDown = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_FadePaletteDown)
static void(__cdecl*original_FadePaletteDown)() = (void(__cdecl*)())0x004b7a98;
CARM95_HOOK_FUNCTION(original_FadePaletteDown, FadePaletteDown)
void __cdecl FadePaletteDown() {
    int i;
    int start_time;
    int the_time;
    LOG_TRACE("()");

    (void)i;
    (void)start_time;
    (void)the_time;

    if (function_hook_state_FadePaletteDown == HOOK_ENABLED) {
        assert(0 && "FadePaletteDown not implemented.");
        abort();
    } else {
        original_FadePaletteDown();
    }
}

function_hook_state_t function_hook_state_FadePaletteUp = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_FadePaletteUp)
static void(__cdecl*original_FadePaletteUp)() = (void(__cdecl*)())0x004b7b28;
CARM95_HOOK_FUNCTION(original_FadePaletteUp, FadePaletteUp)
void __cdecl FadePaletteUp() {
    int i;
    int start_time;
    int the_time;
    LOG_TRACE("()");

    (void)i;
    (void)start_time;
    (void)the_time;

    if (function_hook_state_FadePaletteUp == HOOK_ENABLED) {
        assert(0 && "FadePaletteUp not implemented.");
        abort();
    } else {
        original_FadePaletteUp();
    }
}

function_hook_state_t function_hook_state_KillSplashScreen = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_KillSplashScreen)
static void(__cdecl*original_KillSplashScreen)() = (void(__cdecl*)())0x004b7b9c;
CARM95_HOOK_FUNCTION(original_KillSplashScreen, KillSplashScreen)
void __cdecl KillSplashScreen() {
    LOG_TRACE("()");


    if (function_hook_state_KillSplashScreen == HOOK_ENABLED) {
        assert(0 && "KillSplashScreen not implemented.");
        abort();
    } else {
        original_KillSplashScreen();
    }
}

function_hook_state_t function_hook_state_EnsureRenderPalette = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_EnsureRenderPalette)
static void(__cdecl*original_EnsureRenderPalette)() = (void(__cdecl*)())0x004b7be4;
CARM95_HOOK_FUNCTION(original_EnsureRenderPalette, EnsureRenderPalette)
void __cdecl EnsureRenderPalette() {
    LOG_TRACE("()");


    if (function_hook_state_EnsureRenderPalette == HOOK_ENABLED) {
        assert(0 && "EnsureRenderPalette not implemented.");
        abort();
    } else {
        original_EnsureRenderPalette();
    }
}

function_hook_state_t function_hook_state_SplashScreenWith = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_SplashScreenWith)
static void(__cdecl*original_SplashScreenWith)(char *) = (void(__cdecl*)(char *))0x004b7c0b;
CARM95_HOOK_FUNCTION(original_SplashScreenWith, SplashScreenWith)
void __cdecl SplashScreenWith(char *pPixmap_name) {
    br_pixelmap *the_map;
    LOG_TRACE("(\"%s\")", pPixmap_name);

    (void)pPixmap_name;
    (void)the_map;

    if (function_hook_state_SplashScreenWith == HOOK_ENABLED) {
        assert(0 && "SplashScreenWith not implemented.");
        abort();
    } else {
        original_SplashScreenWith(pPixmap_name);
    }
}

function_hook_state_t function_hook_state_EnsurePaletteUp = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_EnsurePaletteUp)
static void(__cdecl*original_EnsurePaletteUp)() = (void(__cdecl*)())0x004b7d0c;
CARM95_HOOK_FUNCTION(original_EnsurePaletteUp, EnsurePaletteUp)
void __cdecl EnsurePaletteUp() {
    LOG_TRACE("()");


    if (function_hook_state_EnsurePaletteUp == HOOK_ENABLED) {
        assert(0 && "EnsurePaletteUp not implemented.");
        abort();
    } else {
        original_EnsurePaletteUp();
    }
}

function_hook_state_t function_hook_state_AmbientificateMaterial = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_AmbientificateMaterial)
static br_uint_32(__cdecl*original_AmbientificateMaterial)(br_material *, void *) = (br_uint_32(__cdecl*)(br_material *, void *))0x004b7d4a;
CARM95_HOOK_FUNCTION(original_AmbientificateMaterial, AmbientificateMaterial)
br_uint_32 __cdecl AmbientificateMaterial(br_material *pMat, void *pArg) {
    float a;
    LOG_TRACE("(%p, %p)", pMat, pArg);

    (void)pMat;
    (void)pArg;
    (void)a;

    if (function_hook_state_AmbientificateMaterial == HOOK_ENABLED) {
        assert(0 && "AmbientificateMaterial not implemented.");
        abort();
    } else {
        return original_AmbientificateMaterial(pMat, pArg);
    }
}

function_hook_state_t function_hook_state_ChangeAmbience = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_ChangeAmbience)
static void(__cdecl*original_ChangeAmbience)(br_scalar) = (void(__cdecl*)(br_scalar))0x004b7d29;
CARM95_HOOK_FUNCTION(original_ChangeAmbience, ChangeAmbience)
void __cdecl ChangeAmbience(br_scalar pDelta) {
    LOG_TRACE("(%f)", pDelta);

    (void)pDelta;

    if (function_hook_state_ChangeAmbience == HOOK_ENABLED) {
        assert(0 && "ChangeAmbience not implemented.");
        abort();
    } else {
        original_ChangeAmbience(pDelta);
    }
}

function_hook_state_t function_hook_state_InitAmbience = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_InitAmbience)
static void(__cdecl*original_InitAmbience)() = (void(__cdecl*)())0x004b7dae;
CARM95_HOOK_FUNCTION(original_InitAmbience, InitAmbience)
void __cdecl InitAmbience() {
    LOG_TRACE("()");


    if (function_hook_state_InitAmbience == HOOK_ENABLED) {
        assert(0 && "InitAmbience not implemented.");
        abort();
    } else {
        original_InitAmbience();
    }
}

function_hook_state_t function_hook_state_DRPixelmapRectangleMaskedCopy = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_DRPixelmapRectangleMaskedCopy)
static void(__cdecl*original_DRPixelmapRectangleMaskedCopy)(br_pixelmap *, br_int_16, br_int_16, br_pixelmap *, br_int_16, br_int_16, br_int_16, br_int_16) = (void(__cdecl*)(br_pixelmap *, br_int_16, br_int_16, br_pixelmap *, br_int_16, br_int_16, br_int_16, br_int_16))0x004b7dd1;
CARM95_HOOK_FUNCTION(original_DRPixelmapRectangleMaskedCopy, DRPixelmapRectangleMaskedCopy)
void __cdecl DRPixelmapRectangleMaskedCopy(br_pixelmap *pDest, br_int_16 pDest_x, br_int_16 pDest_y, br_pixelmap *pSource, br_int_16 pSource_x, br_int_16 pSource_y, br_int_16 pWidth, br_int_16 pHeight) {
    int y_count;
    int x_count;
    int dest_row_wrap;
    int source_row_wrap;
    int x_delta;
    tU8 the_byte;
    tU8 *source_ptr;
    tU8 *dest_ptr;
    tU8 *conv_table;
    LOG_TRACE("(%p, %d, %d, %p, %d, %d, %d, %d)", pDest, pDest_x, pDest_y, pSource, pSource_x, pSource_y, pWidth, pHeight);

    (void)pDest;
    (void)pDest_x;
    (void)pDest_y;
    (void)pSource;
    (void)pSource_x;
    (void)pSource_y;
    (void)pWidth;
    (void)pHeight;
    (void)y_count;
    (void)x_count;
    (void)dest_row_wrap;
    (void)source_row_wrap;
    (void)x_delta;
    (void)the_byte;
    (void)source_ptr;
    (void)dest_ptr;
    (void)conv_table;

    if (function_hook_state_DRPixelmapRectangleMaskedCopy == HOOK_ENABLED) {
        assert(0 && "DRPixelmapRectangleMaskedCopy not implemented.");
        abort();
    } else {
        original_DRPixelmapRectangleMaskedCopy(pDest, pDest_x, pDest_y, pSource, pSource_x, pSource_y, pWidth, pHeight);
    }
}

function_hook_state_t function_hook_state_DRMaskedStamp = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_DRMaskedStamp)
static void(__cdecl*original_DRMaskedStamp)(br_int_16, br_int_16, br_pixelmap *) = (void(__cdecl*)(br_int_16, br_int_16, br_pixelmap *))0x004b80cc;
CARM95_HOOK_FUNCTION(original_DRMaskedStamp, DRMaskedStamp)
void __cdecl DRMaskedStamp(br_int_16 pDest_x, br_int_16 pDest_y, br_pixelmap *pSource) {
    LOG_TRACE("(%d, %d, %p)", pDest_x, pDest_y, pSource);

    (void)pDest_x;
    (void)pDest_y;
    (void)pSource;

    if (function_hook_state_DRMaskedStamp == HOOK_ENABLED) {
        assert(0 && "DRMaskedStamp not implemented.");
        abort();
    } else {
        original_DRMaskedStamp(pDest_x, pDest_y, pSource);
    }
}

function_hook_state_t function_hook_state_DRPixelmapRectangleOnscreenCopy = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_DRPixelmapRectangleOnscreenCopy)
static void(__cdecl*original_DRPixelmapRectangleOnscreenCopy)(br_pixelmap *, br_int_16, br_int_16, br_pixelmap *, br_int_16, br_int_16, br_int_16, br_int_16) = (void(__cdecl*)(br_pixelmap *, br_int_16, br_int_16, br_pixelmap *, br_int_16, br_int_16, br_int_16, br_int_16))0x004b8105;
CARM95_HOOK_FUNCTION(original_DRPixelmapRectangleOnscreenCopy, DRPixelmapRectangleOnscreenCopy)
void __cdecl DRPixelmapRectangleOnscreenCopy(br_pixelmap *pDest, br_int_16 pDest_x, br_int_16 pDest_y, br_pixelmap *pSource, br_int_16 pSource_x, br_int_16 pSource_y, br_int_16 pWidth, br_int_16 pHeight) {
    int y_count;
    int x_count;
    int dest_row_wrap;
    int source_row_wrap;
    int x_delta;
    tU8 the_byte;
    tU8 *source_ptr;
    tU8 *dest_ptr;
    tU8 *conv_table;
    LOG_TRACE("(%p, %d, %d, %p, %d, %d, %d, %d)", pDest, pDest_x, pDest_y, pSource, pSource_x, pSource_y, pWidth, pHeight);

    (void)pDest;
    (void)pDest_x;
    (void)pDest_y;
    (void)pSource;
    (void)pSource_x;
    (void)pSource_y;
    (void)pWidth;
    (void)pHeight;
    (void)y_count;
    (void)x_count;
    (void)dest_row_wrap;
    (void)source_row_wrap;
    (void)x_delta;
    (void)the_byte;
    (void)source_ptr;
    (void)dest_ptr;
    (void)conv_table;

    if (function_hook_state_DRPixelmapRectangleOnscreenCopy == HOOK_ENABLED) {
        assert(0 && "DRPixelmapRectangleOnscreenCopy not implemented.");
        abort();
    } else {
        original_DRPixelmapRectangleOnscreenCopy(pDest, pDest_x, pDest_y, pSource, pSource_x, pSource_y, pWidth, pHeight);
    }
}

function_hook_state_t function_hook_state_DRPixelmapRectangleShearedCopy = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_DRPixelmapRectangleShearedCopy)
static void(__cdecl*original_DRPixelmapRectangleShearedCopy)(br_pixelmap *, br_int_16, br_int_16, br_pixelmap *, br_int_16, br_int_16, br_int_16, br_int_16, tX1616) = (void(__cdecl*)(br_pixelmap *, br_int_16, br_int_16, br_pixelmap *, br_int_16, br_int_16, br_int_16, br_int_16, tX1616))0x004b81e6;
CARM95_HOOK_FUNCTION(original_DRPixelmapRectangleShearedCopy, DRPixelmapRectangleShearedCopy)
void __cdecl DRPixelmapRectangleShearedCopy(br_pixelmap *pDest, br_int_16 pDest_x, br_int_16 pDest_y, br_pixelmap *pSource, br_int_16 pSource_x, br_int_16 pSource_y, br_int_16 pWidth, br_int_16 pHeight, tX1616 pShear) {
    int y_count;
    int x_count;
    int dest_row_wrap;
    int source_row_wrap;
    int x_delta;
    int last_shear_x;
    int current_shear_x;
    int shear_x_difference;
    tU8 the_byte;
    tU8 *source_ptr;
    tU8 *dest_ptr;
    tU8 *conv_table;
    tX1616 current_shear;
    LOG_TRACE("(%p, %d, %d, %p, %d, %d, %d, %d, %d)", pDest, pDest_x, pDest_y, pSource, pSource_x, pSource_y, pWidth, pHeight, pShear);

    (void)pDest;
    (void)pDest_x;
    (void)pDest_y;
    (void)pSource;
    (void)pSource_x;
    (void)pSource_y;
    (void)pWidth;
    (void)pHeight;
    (void)pShear;
    (void)y_count;
    (void)x_count;
    (void)dest_row_wrap;
    (void)source_row_wrap;
    (void)x_delta;
    (void)last_shear_x;
    (void)current_shear_x;
    (void)shear_x_difference;
    (void)the_byte;
    (void)source_ptr;
    (void)dest_ptr;
    (void)conv_table;
    (void)current_shear;

    if (function_hook_state_DRPixelmapRectangleShearedCopy == HOOK_ENABLED) {
        assert(0 && "DRPixelmapRectangleShearedCopy not implemented.");
        abort();
    } else {
        original_DRPixelmapRectangleShearedCopy(pDest, pDest_x, pDest_y, pSource, pSource_x, pSource_y, pWidth, pHeight, pShear);
    }
}

function_hook_state_t function_hook_state_DRPixelmapRectangleVScaledCopy = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_DRPixelmapRectangleVScaledCopy)
static void(__cdecl*original_DRPixelmapRectangleVScaledCopy)(br_pixelmap *, br_int_16, br_int_16, br_pixelmap *, br_int_16, br_int_16, br_int_16, br_int_16) = (void(__cdecl*)(br_pixelmap *, br_int_16, br_int_16, br_pixelmap *, br_int_16, br_int_16, br_int_16, br_int_16))0x004b8535;
CARM95_HOOK_FUNCTION(original_DRPixelmapRectangleVScaledCopy, DRPixelmapRectangleVScaledCopy)
void __cdecl DRPixelmapRectangleVScaledCopy(br_pixelmap *pDest, br_int_16 pDest_x, br_int_16 pDest_y, br_pixelmap *pSource, br_int_16 pSource_x, br_int_16 pSource_y, br_int_16 pWidth, br_int_16 pHeight) {
    int y_count;
    int x_count;
    int dest_row_wrap;
    int source_row_wrap;
    int x_delta;
    tU8 the_byte;
    tU8 *source_ptr;
    tU8 *dest_ptr;
    tU32 source_y;
    tU32 source_y_delta;
    tU32 old_source_y;
    LOG_TRACE("(%p, %d, %d, %p, %d, %d, %d, %d)", pDest, pDest_x, pDest_y, pSource, pSource_x, pSource_y, pWidth, pHeight);

    (void)pDest;
    (void)pDest_x;
    (void)pDest_y;
    (void)pSource;
    (void)pSource_x;
    (void)pSource_y;
    (void)pWidth;
    (void)pHeight;
    (void)y_count;
    (void)x_count;
    (void)dest_row_wrap;
    (void)source_row_wrap;
    (void)x_delta;
    (void)the_byte;
    (void)source_ptr;
    (void)dest_ptr;
    (void)source_y;
    (void)source_y_delta;
    (void)old_source_y;

    if (function_hook_state_DRPixelmapRectangleVScaledCopy == HOOK_ENABLED) {
        assert(0 && "DRPixelmapRectangleVScaledCopy not implemented.");
        abort();
    } else {
        original_DRPixelmapRectangleVScaledCopy(pDest, pDest_x, pDest_y, pSource, pSource_x, pSource_y, pWidth, pHeight);
    }
}

function_hook_state_t function_hook_state_InitTransientBitmaps = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_InitTransientBitmaps)
static void(__cdecl*original_InitTransientBitmaps)() = (void(__cdecl*)())0x004b8672;
CARM95_HOOK_FUNCTION(original_InitTransientBitmaps, InitTransientBitmaps)
void __cdecl InitTransientBitmaps() {
    int i;
    LOG_TRACE("()");

    (void)i;

    if (function_hook_state_InitTransientBitmaps == HOOK_ENABLED) {
        assert(0 && "InitTransientBitmaps not implemented.");
        abort();
    } else {
        original_InitTransientBitmaps();
    }
}

function_hook_state_t function_hook_state_AllocateTransientBitmap = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_AllocateTransientBitmap)
static int(__cdecl*original_AllocateTransientBitmap)(int, int, int) = (int(__cdecl*)(int, int, int))0x004b86c0;
CARM95_HOOK_FUNCTION(original_AllocateTransientBitmap, AllocateTransientBitmap)
int __cdecl AllocateTransientBitmap(int pWidth, int pHeight, int pUser_data) {
    int bm_index;
    LOG_TRACE("(%d, %d, %d)", pWidth, pHeight, pUser_data);

    (void)pWidth;
    (void)pHeight;
    (void)pUser_data;
    (void)bm_index;

    if (function_hook_state_AllocateTransientBitmap == HOOK_ENABLED) {
        assert(0 && "AllocateTransientBitmap not implemented.");
        abort();
    } else {
        return original_AllocateTransientBitmap(pWidth, pHeight, pUser_data);
    }
}

function_hook_state_t function_hook_state_DeallocateTransientBitmap = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_DeallocateTransientBitmap)
static void(__cdecl*original_DeallocateTransientBitmap)(int) = (void(__cdecl*)(int))0x004b8763;
CARM95_HOOK_FUNCTION(original_DeallocateTransientBitmap, DeallocateTransientBitmap)
void __cdecl DeallocateTransientBitmap(int pIndex) {
    LOG_TRACE("(%d)", pIndex);

    (void)pIndex;

    if (function_hook_state_DeallocateTransientBitmap == HOOK_ENABLED) {
        assert(0 && "DeallocateTransientBitmap not implemented.");
        abort();
    } else {
        original_DeallocateTransientBitmap(pIndex);
    }
}

function_hook_state_t function_hook_state_DeallocateAllTransientBitmaps = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_DeallocateAllTransientBitmaps)
static void(__cdecl*original_DeallocateAllTransientBitmaps)() = (void(__cdecl*)())0x004b87ba;
CARM95_HOOK_FUNCTION(original_DeallocateAllTransientBitmaps, DeallocateAllTransientBitmaps)
void __cdecl DeallocateAllTransientBitmaps() {
    int i;
    LOG_TRACE("()");

    (void)i;

    if (function_hook_state_DeallocateAllTransientBitmaps == HOOK_ENABLED) {
        assert(0 && "DeallocateAllTransientBitmaps not implemented.");
        abort();
    } else {
        original_DeallocateAllTransientBitmaps();
    }
}

function_hook_state_t function_hook_state_RemoveTransientBitmaps = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_RemoveTransientBitmaps)
static void(__cdecl*original_RemoveTransientBitmaps)(int) = (void(__cdecl*)(int))0x004b87f2;
CARM95_HOOK_FUNCTION(original_RemoveTransientBitmaps, RemoveTransientBitmaps)
void __cdecl RemoveTransientBitmaps(int pGraphically_remove_them) {
    int i;
    int order_number;
    LOG_TRACE("(%d)", pGraphically_remove_them);

    (void)pGraphically_remove_them;
    (void)i;
    (void)order_number;

    if (function_hook_state_RemoveTransientBitmaps == HOOK_ENABLED) {
        assert(0 && "RemoveTransientBitmaps not implemented.");
        abort();
    } else {
        original_RemoveTransientBitmaps(pGraphically_remove_them);
    }
}

function_hook_state_t function_hook_state_SaveTransient = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_SaveTransient)
static void(__cdecl*original_SaveTransient)(int, int, int) = (void(__cdecl*)(int, int, int))0x004b88f9;
CARM95_HOOK_FUNCTION(original_SaveTransient, SaveTransient)
void __cdecl SaveTransient(int pIndex, int pX_coord, int pY_coord) {
    LOG_TRACE("(%d, %d, %d)", pIndex, pX_coord, pY_coord);

    (void)pIndex;
    (void)pX_coord;
    (void)pY_coord;

    if (function_hook_state_SaveTransient == HOOK_ENABLED) {
        assert(0 && "SaveTransient not implemented.");
        abort();
    } else {
        original_SaveTransient(pIndex, pX_coord, pY_coord);
    }
}

function_hook_state_t function_hook_state_DrawCursorGiblet = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_DrawCursorGiblet)
static void(__cdecl*original_DrawCursorGiblet)(tCursor_giblet *) = (void(__cdecl*)(tCursor_giblet *))0x004b924e;
CARM95_HOOK_FUNCTION(original_DrawCursorGiblet, DrawCursorGiblet)
void __cdecl DrawCursorGiblet(tCursor_giblet *pGib) {
    br_pixelmap *the_image;
    LOG_TRACE("(%p)", pGib);

    (void)pGib;
    (void)the_image;

    if (function_hook_state_DrawCursorGiblet == HOOK_ENABLED) {
        assert(0 && "DrawCursorGiblet not implemented.");
        abort();
    } else {
        original_DrawCursorGiblet(pGib);
    }
}

function_hook_state_t function_hook_state_ProcessCursorGiblets = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_ProcessCursorGiblets)
static void(__cdecl*original_ProcessCursorGiblets)(int) = (void(__cdecl*)(int))0x004b8ebe;
CARM95_HOOK_FUNCTION(original_ProcessCursorGiblets, ProcessCursorGiblets)
void __cdecl ProcessCursorGiblets(int pPeriod) {
    int i;
    int kill_the_giblet;
    tU32 time_now;
    tCursor_giblet *gib;
    LOG_TRACE("(%d)", pPeriod);

    (void)pPeriod;
    (void)i;
    (void)kill_the_giblet;
    (void)time_now;
    (void)gib;

    if (function_hook_state_ProcessCursorGiblets == HOOK_ENABLED) {
        assert(0 && "ProcessCursorGiblets not implemented.");
        abort();
    } else {
        original_ProcessCursorGiblets(pPeriod);
    }
}

function_hook_state_t function_hook_state_NewCursorGiblet = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_NewCursorGiblet)
static int(__cdecl*original_NewCursorGiblet)(int, int, float, float, tU32) = (int(__cdecl*)(int, int, float, float, tU32))0x004b92e0;
CARM95_HOOK_FUNCTION(original_NewCursorGiblet, NewCursorGiblet)
int __cdecl NewCursorGiblet(int pX_coord, int pY_coord, float pX_speed, float pY_speed, tU32 pDrop_time) {
    int i;
    int the_width;
    int the_height;
    int sequence_number;
    LOG_TRACE("(%d, %d, %f, %f, %u)", pX_coord, pY_coord, pX_speed, pY_speed, pDrop_time);

    (void)pX_coord;
    (void)pY_coord;
    (void)pX_speed;
    (void)pY_speed;
    (void)pDrop_time;
    (void)i;
    (void)the_width;
    (void)the_height;
    (void)sequence_number;

    if (function_hook_state_NewCursorGiblet == HOOK_ENABLED) {
        assert(0 && "NewCursorGiblet not implemented.");
        abort();
    } else {
        return original_NewCursorGiblet(pX_coord, pY_coord, pX_speed, pY_speed, pDrop_time);
    }
}

function_hook_state_t function_hook_state_DoMouseCursor = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_DoMouseCursor)
static int(__cdecl*original_DoMouseCursor)() = (int(__cdecl*)())0x004b89b4;
CARM95_HOOK_FUNCTION(original_DoMouseCursor, DoMouseCursor)
int __cdecl DoMouseCursor() {
    int x_coord;
    int y_coord;
    int mouse_moved;
    int new_required;
    int giblet_index;
    int cursor_offset;
    int button_is_down;
    int giblet_chance;
    int giblet_count;
    tU32 this_call_time;
    static tU32 last_cursor_change;
    static tU32 last_call_time;
    static tU32 last_required_change;
    tS32 period;
    static int delta_x;
    static int required_cursor;
    static int zero_count;
    static int button_was_down;
    LOG_TRACE("()");

    (void)x_coord;
    (void)y_coord;
    (void)mouse_moved;
    (void)new_required;
    (void)giblet_index;
    (void)cursor_offset;
    (void)button_is_down;
    (void)giblet_chance;
    (void)giblet_count;
    (void)this_call_time;
    (void)last_cursor_change;
    (void)last_call_time;
    (void)last_required_change;
    (void)period;
    (void)delta_x;
    (void)required_cursor;
    (void)zero_count;
    (void)button_was_down;

    if (function_hook_state_DoMouseCursor == HOOK_ENABLED) {
        assert(0 && "DoMouseCursor not implemented.");
        abort();
    } else {
        return original_DoMouseCursor();
    }
}

function_hook_state_t function_hook_state_AllocateCursorTransient = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_AllocateCursorTransient)
static int(__cdecl*original_AllocateCursorTransient)() = (int(__cdecl*)())0x004b95b6;
CARM95_HOOK_FUNCTION(original_AllocateCursorTransient, AllocateCursorTransient)
int __cdecl AllocateCursorTransient() {
    int i;
    int largest_width;
    int largest_height;
    LOG_TRACE("()");

    (void)i;
    (void)largest_width;
    (void)largest_height;

    if (function_hook_state_AllocateCursorTransient == HOOK_ENABLED) {
        assert(0 && "AllocateCursorTransient not implemented.");
        abort();
    } else {
        return original_AllocateCursorTransient();
    }
}

function_hook_state_t function_hook_state_StartMouseCursor = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_StartMouseCursor)
static void(__cdecl*original_StartMouseCursor)() = (void(__cdecl*)())0x004b9535;
CARM95_HOOK_FUNCTION(original_StartMouseCursor, StartMouseCursor)
void __cdecl StartMouseCursor() {
    int i;
    LOG_TRACE("()");

    (void)i;

    if (function_hook_state_StartMouseCursor == HOOK_ENABLED) {
        assert(0 && "StartMouseCursor not implemented.");
        abort();
    } else {
        original_StartMouseCursor();
    }
}

function_hook_state_t function_hook_state_EndMouseCursor = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_EndMouseCursor)
static void(__cdecl*original_EndMouseCursor)() = (void(__cdecl*)())0x004b965f;
CARM95_HOOK_FUNCTION(original_EndMouseCursor, EndMouseCursor)
void __cdecl EndMouseCursor() {
    LOG_TRACE("()");


    if (function_hook_state_EndMouseCursor == HOOK_ENABLED) {
        assert(0 && "EndMouseCursor not implemented.");
        abort();
    } else {
        original_EndMouseCursor();
    }
}

function_hook_state_t function_hook_state_LoadFont = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_LoadFont)
static void(__cdecl*original_LoadFont)(int) = (void(__cdecl*)(int))0x004b9683;
CARM95_HOOK_FUNCTION(original_LoadFont, LoadFont)
void __cdecl LoadFont(int pFont_ID) {
    tPath_name the_path;
    int i;
    int number_of_chars;
    FILE *f;
    tU32 the_size;
    LOG_TRACE("(%d)", pFont_ID);

    (void)pFont_ID;
    (void)the_path;
    (void)i;
    (void)number_of_chars;
    (void)f;
    (void)the_size;

    if (function_hook_state_LoadFont == HOOK_ENABLED) {
        assert(0 && "LoadFont not implemented.");
        abort();
    } else {
        original_LoadFont(pFont_ID);
    }
}

function_hook_state_t function_hook_state_DisposeFont = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_DisposeFont)
static void(__cdecl*original_DisposeFont)(int) = (void(__cdecl*)(int))0x004b99cb;
CARM95_HOOK_FUNCTION(original_DisposeFont, DisposeFont)
void __cdecl DisposeFont(int pFont_ID) {
    LOG_TRACE("(%d)", pFont_ID);

    (void)pFont_ID;

    if (function_hook_state_DisposeFont == HOOK_ENABLED) {
        assert(0 && "DisposeFont not implemented.");
        abort();
    } else {
        original_DisposeFont(pFont_ID);
    }
}

function_hook_state_t function_hook_state_InitDRFonts = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_InitDRFonts)
static void(__cdecl*original_InitDRFonts)() = (void(__cdecl*)())0x004b9a79;
CARM95_HOOK_FUNCTION(original_InitDRFonts, InitDRFonts)
void __cdecl InitDRFonts() {
    int i;
    LOG_TRACE("()");

    (void)i;

    if (function_hook_state_InitDRFonts == HOOK_ENABLED) {
        assert(0 && "InitDRFonts not implemented.");
        abort();
    } else {
        original_InitDRFonts();
    }
}

function_hook_state_t function_hook_state_DrawDropImage = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_DrawDropImage)
static void(__cdecl*original_DrawDropImage)(br_pixelmap *, int, int, int, int, int) = (void(__cdecl*)(br_pixelmap *, int, int, int, int, int))0x004b9b73;
CARM95_HOOK_FUNCTION(original_DrawDropImage, DrawDropImage)
void __cdecl DrawDropImage(br_pixelmap *pImage, int pLeft, int pTop, int pTop_clip, int pBottom_clip, int pOffset) {
    int y;
    int src_y;
    int src_height;
    int y_diff;
    LOG_TRACE("(%p, %d, %d, %d, %d, %d)", pImage, pLeft, pTop, pTop_clip, pBottom_clip, pOffset);

    (void)pImage;
    (void)pLeft;
    (void)pTop;
    (void)pTop_clip;
    (void)pBottom_clip;
    (void)pOffset;
    (void)y;
    (void)src_y;
    (void)src_height;
    (void)y_diff;

    if (function_hook_state_DrawDropImage == HOOK_ENABLED) {
        assert(0 && "DrawDropImage not implemented.");
        abort();
    } else {
        original_DrawDropImage(pImage, pLeft, pTop, pTop_clip, pBottom_clip, pOffset);
    }
}

function_hook_state_t function_hook_state_DropInImageFromTop = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_DropInImageFromTop)
static void(__cdecl*original_DropInImageFromTop)(br_pixelmap *, int, int, int, int) = (void(__cdecl*)(br_pixelmap *, int, int, int, int))0x004b9adf;
CARM95_HOOK_FUNCTION(original_DropInImageFromTop, DropInImageFromTop)
void __cdecl DropInImageFromTop(br_pixelmap *pImage, int pLeft, int pTop, int pTop_clip, int pBottom_clip) {
    tS32 start_time;
    tS32 the_time;
    int drop_distance;
    LOG_TRACE("(%p, %d, %d, %d, %d)", pImage, pLeft, pTop, pTop_clip, pBottom_clip);

    (void)pImage;
    (void)pLeft;
    (void)pTop;
    (void)pTop_clip;
    (void)pBottom_clip;
    (void)start_time;
    (void)the_time;
    (void)drop_distance;

    if (function_hook_state_DropInImageFromTop == HOOK_ENABLED) {
        assert(0 && "DropInImageFromTop not implemented.");
        abort();
    } else {
        original_DropInImageFromTop(pImage, pLeft, pTop, pTop_clip, pBottom_clip);
    }
}

function_hook_state_t function_hook_state_DropOutImageThruBottom = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_DropOutImageThruBottom)
static void(__cdecl*original_DropOutImageThruBottom)(br_pixelmap *, int, int, int, int) = (void(__cdecl*)(br_pixelmap *, int, int, int, int))0x004b9c5d;
CARM95_HOOK_FUNCTION(original_DropOutImageThruBottom, DropOutImageThruBottom)
void __cdecl DropOutImageThruBottom(br_pixelmap *pImage, int pLeft, int pTop, int pTop_clip, int pBottom_clip) {
    tS32 start_time;
    tS32 the_time;
    int drop_distance;
    LOG_TRACE("(%p, %d, %d, %d, %d)", pImage, pLeft, pTop, pTop_clip, pBottom_clip);

    (void)pImage;
    (void)pLeft;
    (void)pTop;
    (void)pTop_clip;
    (void)pBottom_clip;
    (void)start_time;
    (void)the_time;
    (void)drop_distance;

    if (function_hook_state_DropOutImageThruBottom == HOOK_ENABLED) {
        assert(0 && "DropOutImageThruBottom not implemented.");
        abort();
    } else {
        original_DropOutImageThruBottom(pImage, pLeft, pTop, pTop_clip, pBottom_clip);
    }
}

function_hook_state_t function_hook_state_DropInImageFromBottom = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_DropInImageFromBottom)
static void(__cdecl*original_DropInImageFromBottom)(br_pixelmap *, int, int, int, int) = (void(__cdecl*)(br_pixelmap *, int, int, int, int))0x004b9ce8;
CARM95_HOOK_FUNCTION(original_DropInImageFromBottom, DropInImageFromBottom)
void __cdecl DropInImageFromBottom(br_pixelmap *pImage, int pLeft, int pTop, int pTop_clip, int pBottom_clip) {
    tS32 start_time;
    tS32 the_time;
    int drop_distance;
    LOG_TRACE("(%p, %d, %d, %d, %d)", pImage, pLeft, pTop, pTop_clip, pBottom_clip);

    (void)pImage;
    (void)pLeft;
    (void)pTop;
    (void)pTop_clip;
    (void)pBottom_clip;
    (void)start_time;
    (void)the_time;
    (void)drop_distance;

    if (function_hook_state_DropInImageFromBottom == HOOK_ENABLED) {
        assert(0 && "DropInImageFromBottom not implemented.");
        abort();
    } else {
        original_DropInImageFromBottom(pImage, pLeft, pTop, pTop_clip, pBottom_clip);
    }
}

function_hook_state_t function_hook_state_DropOutImageThruTop = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_DropOutImageThruTop)
static void(__cdecl*original_DropOutImageThruTop)(br_pixelmap *, int, int, int, int) = (void(__cdecl*)(br_pixelmap *, int, int, int, int))0x004b9d75;
CARM95_HOOK_FUNCTION(original_DropOutImageThruTop, DropOutImageThruTop)
void __cdecl DropOutImageThruTop(br_pixelmap *pImage, int pLeft, int pTop, int pTop_clip, int pBottom_clip) {
    tS32 start_time;
    tS32 the_time;
    int drop_distance;
    LOG_TRACE("(%p, %d, %d, %d, %d)", pImage, pLeft, pTop, pTop_clip, pBottom_clip);

    (void)pImage;
    (void)pLeft;
    (void)pTop;
    (void)pTop_clip;
    (void)pBottom_clip;
    (void)start_time;
    (void)the_time;
    (void)drop_distance;

    if (function_hook_state_DropOutImageThruTop == HOOK_ENABLED) {
        assert(0 && "DropOutImageThruTop not implemented.");
        abort();
    } else {
        original_DropOutImageThruTop(pImage, pLeft, pTop, pTop_clip, pBottom_clip);
    }
}

function_hook_state_t function_hook_state_DrawTellyLine = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_DrawTellyLine)
static void(__cdecl*original_DrawTellyLine)(br_pixelmap *, int, int, int) = (void(__cdecl*)(br_pixelmap *, int, int, int))0x004b9ecd;
CARM95_HOOK_FUNCTION(original_DrawTellyLine, DrawTellyLine)
void __cdecl DrawTellyLine(br_pixelmap *pImage, int pLeft, int pTop, int pPercentage) {
    int the_width;
    int the_height;
    LOG_TRACE("(%p, %d, %d, %d)", pImage, pLeft, pTop, pPercentage);

    (void)pImage;
    (void)pLeft;
    (void)pTop;
    (void)pPercentage;
    (void)the_width;
    (void)the_height;

    if (function_hook_state_DrawTellyLine == HOOK_ENABLED) {
        assert(0 && "DrawTellyLine not implemented.");
        abort();
    } else {
        original_DrawTellyLine(pImage, pLeft, pTop, pPercentage);
    }
}

function_hook_state_t function_hook_state_DrawTellyImage = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_DrawTellyImage)
static void(__cdecl*original_DrawTellyImage)(br_pixelmap *, int, int, int) = (void(__cdecl*)(br_pixelmap *, int, int, int))0x004b9f9e;
CARM95_HOOK_FUNCTION(original_DrawTellyImage, DrawTellyImage)
void __cdecl DrawTellyImage(br_pixelmap *pImage, int pLeft, int pTop, int pPercentage) {
    int the_height;
    LOG_TRACE("(%p, %d, %d, %d)", pImage, pLeft, pTop, pPercentage);

    (void)pImage;
    (void)pLeft;
    (void)pTop;
    (void)pPercentage;
    (void)the_height;

    if (function_hook_state_DrawTellyImage == HOOK_ENABLED) {
        assert(0 && "DrawTellyImage not implemented.");
        abort();
    } else {
        original_DrawTellyImage(pImage, pLeft, pTop, pPercentage);
    }
}

function_hook_state_t function_hook_state_TellyInImage = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_TellyInImage)
static void(__cdecl*original_TellyInImage)(br_pixelmap *, int, int) = (void(__cdecl*)(br_pixelmap *, int, int))0x004b9e09;
CARM95_HOOK_FUNCTION(original_TellyInImage, TellyInImage)
void __cdecl TellyInImage(br_pixelmap *pImage, int pLeft, int pTop) {
    tS32 start_time;
    tS32 the_time;
    LOG_TRACE("(%p, %d, %d)", pImage, pLeft, pTop);

    (void)pImage;
    (void)pLeft;
    (void)pTop;
    (void)start_time;
    (void)the_time;

    if (function_hook_state_TellyInImage == HOOK_ENABLED) {
        assert(0 && "TellyInImage not implemented.");
        abort();
    } else {
        original_TellyInImage(pImage, pLeft, pTop);
    }
}

function_hook_state_t function_hook_state_TellyOutImage = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_TellyOutImage)
static void(__cdecl*original_TellyOutImage)(br_pixelmap *, int, int) = (void(__cdecl*)(br_pixelmap *, int, int))0x004ba04e;
CARM95_HOOK_FUNCTION(original_TellyOutImage, TellyOutImage)
void __cdecl TellyOutImage(br_pixelmap *pImage, int pLeft, int pTop) {
    tS32 start_time;
    tS32 the_time;
    int drop_distance;
    LOG_TRACE("(%p, %d, %d)", pImage, pLeft, pTop);

    (void)pImage;
    (void)pLeft;
    (void)pTop;
    (void)start_time;
    (void)the_time;
    (void)drop_distance;

    if (function_hook_state_TellyOutImage == HOOK_ENABLED) {
        assert(0 && "TellyOutImage not implemented.");
        abort();
    } else {
        original_TellyOutImage(pImage, pLeft, pTop);
    }
}

function_hook_state_t function_hook_state_SetShadowLevel = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_SetShadowLevel)
static void(__cdecl*original_SetShadowLevel)(tShadow_level) = (void(__cdecl*)(tShadow_level))0x004ba135;
CARM95_HOOK_FUNCTION(original_SetShadowLevel, SetShadowLevel)
void __cdecl SetShadowLevel(tShadow_level pLevel) {
    LOG_TRACE("(%d)", pLevel);

    (void)pLevel;

    if (function_hook_state_SetShadowLevel == HOOK_ENABLED) {
        assert(0 && "SetShadowLevel not implemented.");
        abort();
    } else {
        original_SetShadowLevel(pLevel);
    }
}

function_hook_state_t function_hook_state_GetShadowLevel = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_GetShadowLevel)
static tShadow_level(__cdecl*original_GetShadowLevel)() = (tShadow_level(__cdecl*)())0x004ba148;
CARM95_HOOK_FUNCTION(original_GetShadowLevel, GetShadowLevel)
tShadow_level __cdecl GetShadowLevel() {
    LOG_TRACE("()");


    if (function_hook_state_GetShadowLevel == HOOK_ENABLED) {
        assert(0 && "GetShadowLevel not implemented.");
        abort();
    } else {
        return original_GetShadowLevel();
    }
}

function_hook_state_t function_hook_state_ToggleShadow = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_ToggleShadow)
static void(__cdecl*original_ToggleShadow)() = (void(__cdecl*)())0x004ba15d;
CARM95_HOOK_FUNCTION(original_ToggleShadow, ToggleShadow)
void __cdecl ToggleShadow() {
    LOG_TRACE("()");


    if (function_hook_state_ToggleShadow == HOOK_ENABLED) {
        assert(0 && "ToggleShadow not implemented.");
        abort();
    } else {
        original_ToggleShadow();
    }
}

function_hook_state_t function_hook_state_InitShadow = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_InitShadow)
static void(__cdecl*original_InitShadow)() = (void(__cdecl*)())0x004ba24f;
CARM95_HOOK_FUNCTION(original_InitShadow, InitShadow)
void __cdecl InitShadow() {
    int i;
    br_vector3 temp_v;
    LOG_TRACE("()");

    (void)i;
    (void)temp_v;

    if (function_hook_state_InitShadow == HOOK_ENABLED) {
        assert(0 && "InitShadow not implemented.");
        abort();
    } else {
        original_InitShadow();
    }
}

function_hook_state_t function_hook_state_SaveShadeTable = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_SaveShadeTable)
static br_uint_32(__cdecl*original_SaveShadeTable)(br_pixelmap *, void *) = (br_uint_32(__cdecl*)(br_pixelmap *, void *))0x004ba427;
CARM95_HOOK_FUNCTION(original_SaveShadeTable, SaveShadeTable)
br_uint_32 __cdecl SaveShadeTable(br_pixelmap *pTable, void *pArg) {
    LOG_TRACE("(%p, %p)", pTable, pArg);

    (void)pTable;
    (void)pArg;

    if (function_hook_state_SaveShadeTable == HOOK_ENABLED) {
        assert(0 && "SaveShadeTable not implemented.");
        abort();
    } else {
        return original_SaveShadeTable(pTable, pArg);
    }
}

function_hook_state_t function_hook_state_SaveShadeTables = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_SaveShadeTables)
static void(__cdecl*original_SaveShadeTables)() = (void(__cdecl*)())0x004ba49d;
CARM95_HOOK_FUNCTION(original_SaveShadeTables, SaveShadeTables)
void __cdecl SaveShadeTables() {
    LOG_TRACE("()");


    if (function_hook_state_SaveShadeTables == HOOK_ENABLED) {
        assert(0 && "SaveShadeTables not implemented.");
        abort();
    } else {
        original_SaveShadeTables();
    }
}

function_hook_state_t function_hook_state_DisposeSavedShadeTables = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_DisposeSavedShadeTables)
static void(__cdecl*original_DisposeSavedShadeTables)() = (void(__cdecl*)())0x004ba4cb;
CARM95_HOOK_FUNCTION(original_DisposeSavedShadeTables, DisposeSavedShadeTables)
void __cdecl DisposeSavedShadeTables() {
    int i;
    LOG_TRACE("()");

    (void)i;

    if (function_hook_state_DisposeSavedShadeTables == HOOK_ENABLED) {
        assert(0 && "DisposeSavedShadeTables not implemented.");
        abort();
    } else {
        original_DisposeSavedShadeTables();
    }
}

function_hook_state_t function_hook_state_ShadowMode = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_ShadowMode)
static void(__cdecl*original_ShadowMode)() = (void(__cdecl*)())0x004ba50e;
CARM95_HOOK_FUNCTION(original_ShadowMode, ShadowMode)
void __cdecl ShadowMode() {
    LOG_TRACE("()");


    if (function_hook_state_ShadowMode == HOOK_ENABLED) {
        assert(0 && "ShadowMode not implemented.");
        abort();
    } else {
        original_ShadowMode();
    }
}

function_hook_state_t function_hook_state_SwitchToRealResolution = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_SwitchToRealResolution)
static int(__cdecl*original_SwitchToRealResolution)() = (int(__cdecl*)())0x004ba581;
CARM95_HOOK_FUNCTION(original_SwitchToRealResolution, SwitchToRealResolution)
int __cdecl SwitchToRealResolution() {
    LOG_TRACE("()");


    if (function_hook_state_SwitchToRealResolution == HOOK_ENABLED) {
        assert(0 && "SwitchToRealResolution not implemented.");
        abort();
    } else {
        return original_SwitchToRealResolution();
    }
}

function_hook_state_t function_hook_state_SwitchToLoresMode = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_SwitchToLoresMode)
static int(__cdecl*original_SwitchToLoresMode)() = (int(__cdecl*)())0x004ba5e7;
CARM95_HOOK_FUNCTION(original_SwitchToLoresMode, SwitchToLoresMode)
int __cdecl SwitchToLoresMode() {
    LOG_TRACE("()");


    if (function_hook_state_SwitchToLoresMode == HOOK_ENABLED) {
        assert(0 && "SwitchToLoresMode not implemented.");
        abort();
    } else {
        return original_SwitchToLoresMode();
    }
}

function_hook_state_t function_hook_state_DRPixelmapDoubledCopy = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(function_hook_state_DRPixelmapDoubledCopy)
static void(__cdecl*original_DRPixelmapDoubledCopy)(br_pixelmap *, br_pixelmap *, int, int, int, int) = (void(__cdecl*)(br_pixelmap *, br_pixelmap *, int, int, int, int))0x004ba65a;
CARM95_HOOK_FUNCTION(original_DRPixelmapDoubledCopy, DRPixelmapDoubledCopy)
void __cdecl DRPixelmapDoubledCopy(br_pixelmap *pDestn, br_pixelmap *pSource, int pSource_width, int pSource_height, int pX_offset, int pY_offset) {
    tU16 *sptr;
    tU16 pixels;
    tU8 *dptr;
    tU8 *dptr2;
    tU8 pixel_1;
    tU8 pixel_2;
    int i;
    int j;
    int dst_row_skip;
    int src_row_skip;
    int width_over_2;
    LOG_TRACE("(%p, %p, %d, %d, %d, %d)", pDestn, pSource, pSource_width, pSource_height, pX_offset, pY_offset);

    (void)pDestn;
    (void)pSource;
    (void)pSource_width;
    (void)pSource_height;
    (void)pX_offset;
    (void)pY_offset;
    (void)sptr;
    (void)pixels;
    (void)dptr;
    (void)dptr2;
    (void)pixel_1;
    (void)pixel_2;
    (void)i;
    (void)j;
    (void)dst_row_skip;
    (void)src_row_skip;
    (void)width_over_2;

    if (function_hook_state_DRPixelmapDoubledCopy == HOOK_ENABLED) {
        assert(0 && "DRPixelmapDoubledCopy not implemented.");
        abort();
    } else {
        original_DRPixelmapDoubledCopy(pDestn, pSource, pSource_width, pSource_height, pX_offset, pY_offset);
    }
}

