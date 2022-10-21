#include "dossys.h"

#include "harness/trace.h"

#include "carm95_hooks.h"

#include "carm95_webserver.h"

#include <assert.h>
#include <sys/stat.h>
#if 0
int * hookvar_gDOSGfx_initialized ;
#endif
#if 0
int * hookvar_gExtra_mem ;
#endif
#if 0
int * hookvar_gReplay_override ;
#endif
tGraf_spec(* hookvar_gGraf_specs )[2] = (void*)0x0051d608;
int(* hookvar_gASCII_table )[128] = (void*)0x0053e270;
#if 0
tU32(* hookvar_gKeyboard_bits )[8];
#endif
int(* hookvar_gASCII_shift_table )[128] = (void*)0x0053d6a8;
#if 0
char(* hookvar_gNetwork_profile_fname )[256];
#endif
#if 0
tS32 * hookvar_gJoystick_min1y ;
#endif
#if 0
tS32 * hookvar_gJoystick_min2y ;
#endif
#if 0
tS32 * hookvar_gJoystick_min2x ;
#endif
#if 0
tS32 * hookvar_gRaw_joystick2y ;
#endif
#if 0
tS32 * hookvar_gRaw_joystick2x ;
#endif
#if 0
tS32 * hookvar_gRaw_joystick1y ;
#endif
#if 0
tS32 * hookvar_gRaw_joystick1x ;
#endif
#if 0
tS32 * hookvar_gJoystick_range2y ;
#endif
#if 0
tS32 * hookvar_gJoystick_range2x ;
#endif
#if 0
tS32 * hookvar_gJoystick_range1y ;
#endif
#if 0
tS32 * hookvar_gJoystick_range1x ;
#endif
#if 0
int * hookvar_gNo_voodoo ;
#endif
#if 0
int * hookvar_gSwitched_resolution ;
#endif
#if 0
br_pixelmap ** hookvar_gReal_back_screen ;
#endif
#if 0
tS32 * hookvar_gJoystick_min1x ;
#endif
br_pixelmap ** hookvar_gTemp_screen  = (void*)0x0051d59c;
#if 0
tU32 * hookvar_gUpper_loop_limit ;
#endif
#if 0
int * hookvar_gReal_back_screen_locked ;
#endif
#if 0
void(*** hookvar_gPrev_keyboard_handler )();
#endif
tU8(* hookvar_gScan_code )[123][2] = (void*)0x00550360;

function_hook_state_t function_hook_state_KeyboardHandler = HOOK_UNAVAILABLE;
void KeyboardHandler() {
    tU8 scan_code;
    tU8 up;
    static tU8 extended;
    LOG_TRACE("()");

    (void)scan_code;
    (void)up;
    (void)extended;

    if (function_hook_state_KeyboardHandler == HOOK_ENABLED) {
        assert(0 && "KeyboardHandler not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}

function_hook_state_t function_hook_state_KeyDown = HOOK_UNAVAILABLE;
int KeyDown(tU8 pScan_code) {
    LOG_TRACE("(%u)", pScan_code);

    (void)pScan_code;

    if (function_hook_state_KeyDown == HOOK_ENABLED) {
        assert(0 && "KeyDown not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}

function_hook_state_t function_hook_state_KeyTranslation = HOOK_UNAVAILABLE;
void KeyTranslation(tU8 pKey_index, tU8 pScan_code_1, tU8 pScan_code_2) {
    LOG_TRACE("(%u, %u, %u)", pKey_index, pScan_code_1, pScan_code_2);

    (void)pKey_index;
    (void)pScan_code_1;
    (void)pScan_code_2;

    if (function_hook_state_KeyTranslation == HOOK_ENABLED) {
        assert(0 && "KeyTranslation not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}

function_hook_state_t function_hook_state_KeyBegin = HOOK_UNAVAILABLE;
static void(__cdecl*original_KeyBegin)() = (void(__cdecl*)())0x004a6b34;
CARM95_HOOK_FUNCTION(original_KeyBegin, KeyBegin)
void __cdecl KeyBegin() {
    LOG_TRACE("()");


    if (function_hook_state_KeyBegin == HOOK_ENABLED) {
        assert(0 && "KeyBegin not implemented.");
        abort();
    } else {
        original_KeyBegin();
    }
}

function_hook_state_t function_hook_state_KeyEnd = HOOK_UNAVAILABLE;
void KeyEnd() {
    LOG_TRACE("()");


    if (function_hook_state_KeyEnd == HOOK_ENABLED) {
        assert(0 && "KeyEnd not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}

function_hook_state_t function_hook_state_KeyDown22 = HOOK_UNAVAILABLE;
int KeyDown22(int pKey_index) {
    LOG_TRACE("(%d)", pKey_index);

    (void)pKey_index;

    if (function_hook_state_KeyDown22 == HOOK_ENABLED) {
        assert(0 && "KeyDown22 not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}

function_hook_state_t function_hook_state_PDSetKeyArray = HOOK_UNAVAILABLE;
static void(__cdecl*original_PDSetKeyArray)(int *, int) = (void(__cdecl*)(int *, int))0x004a7d4c;
CARM95_HOOK_FUNCTION(original_PDSetKeyArray, PDSetKeyArray)
void __cdecl PDSetKeyArray(int *pKeys, int pMark) {
    int i;
    tS32 joyX;
    tS32 joyY;
    LOG_TRACE("(%p, %d)", pKeys, pMark);

    (void)pKeys;
    (void)pMark;
    (void)i;
    (void)joyX;
    (void)joyY;

    if (function_hook_state_PDSetKeyArray == HOOK_ENABLED) {
        assert(0 && "PDSetKeyArray not implemented.");
        abort();
    } else {
        original_PDSetKeyArray(pKeys, pMark);
    }
}

function_hook_state_t function_hook_state_PDGetASCIIFromKey = HOOK_UNAVAILABLE;
static int(__cdecl*original_PDGetASCIIFromKey)(int) = (int(__cdecl*)(int))0x004a7a49;
CARM95_HOOK_FUNCTION(original_PDGetASCIIFromKey, PDGetASCIIFromKey)
int __cdecl PDGetASCIIFromKey(int pKey) {
    LOG_TRACE("(%d)", pKey);

    (void)pKey;

    if (function_hook_state_PDGetASCIIFromKey == HOOK_ENABLED) {
        assert(0 && "PDGetASCIIFromKey not implemented.");
        abort();
    } else {
        return original_PDGetASCIIFromKey(pKey);
    }
}

function_hook_state_t function_hook_state_PDFatalError = HOOK_UNAVAILABLE;
static void(__cdecl*original_PDFatalError)(char *) = (void(__cdecl*)(char *))0x004a633f;
CARM95_HOOK_FUNCTION(original_PDFatalError, PDFatalError)
void __cdecl PDFatalError(char *pThe_str) {
    static int been_here;
    LOG_TRACE("(\"%s\")", pThe_str);

    (void)pThe_str;
    (void)been_here;

    if (function_hook_state_PDFatalError == HOOK_ENABLED) {
        assert(0 && "PDFatalError not implemented.");
        abort();
    } else {
        original_PDFatalError(pThe_str);
    }
}

function_hook_state_t function_hook_state_PDNonFatalError = HOOK_UNAVAILABLE;
static void(__cdecl*original_PDNonFatalError)(char *) = (void(__cdecl*)(char *))0x004a63aa;
CARM95_HOOK_FUNCTION(original_PDNonFatalError, PDNonFatalError)
void __cdecl PDNonFatalError(char *pThe_str) {
    LOG_TRACE("(\"%s\")", pThe_str);

    (void)pThe_str;

    if (function_hook_state_PDNonFatalError == HOOK_ENABLED) {
        assert(0 && "PDNonFatalError not implemented.");
        abort();
    } else {
        original_PDNonFatalError(pThe_str);
    }
}

function_hook_state_t function_hook_state_PDInitialiseSystem = HOOK_UNAVAILABLE;
static void(__cdecl*original_PDInitialiseSystem)() = (void(__cdecl*)())0x004a692c;
CARM95_HOOK_FUNCTION(original_PDInitialiseSystem, PDInitialiseSystem)
void __cdecl PDInitialiseSystem() {
    tPath_name the_path;
    FILE *f;
    int len;
    LOG_TRACE("()");

    (void)the_path;
    (void)f;
    (void)len;

    if (function_hook_state_PDInitialiseSystem == HOOK_ENABLED) {
        assert(0 && "PDInitialiseSystem not implemented.");
        abort();
    } else {
        original_PDInitialiseSystem();
    }
}

function_hook_state_t function_hook_state_PDShutdownSystem = HOOK_UNAVAILABLE;
static void(__stdcall*original_PDShutdownSystem)() = (void(__stdcall*)())0x004a6f6d;
CARM95_HOOK_FUNCTION(original_PDShutdownSystem, PDShutdownSystem)
void __stdcall PDShutdownSystem() {
    LOG_TRACE("()");


    if (function_hook_state_PDShutdownSystem == HOOK_ENABLED) {
        assert(0 && "PDShutdownSystem not implemented.");
        abort();
    } else {
        original_PDShutdownSystem();
    }
}

function_hook_state_t function_hook_state_PDSaveOriginalPalette = HOOK_UNAVAILABLE;
static void(__cdecl*original_PDSaveOriginalPalette)() = (void(__cdecl*)())0x004a7097;
CARM95_HOOK_FUNCTION(original_PDSaveOriginalPalette, PDSaveOriginalPalette)
void __cdecl PDSaveOriginalPalette() {
    LOG_TRACE("()");


    if (function_hook_state_PDSaveOriginalPalette == HOOK_ENABLED) {
        assert(0 && "PDSaveOriginalPalette not implemented.");
        abort();
    } else {
        original_PDSaveOriginalPalette();
    }
}

function_hook_state_t function_hook_state_PDRevertPalette = HOOK_UNAVAILABLE;
static void(__cdecl*original_PDRevertPalette)() = (void(__cdecl*)())0x004a70a2;
CARM95_HOOK_FUNCTION(original_PDRevertPalette, PDRevertPalette)
void __cdecl PDRevertPalette() {
    LOG_TRACE("()");


    if (function_hook_state_PDRevertPalette == HOOK_ENABLED) {
        assert(0 && "PDRevertPalette not implemented.");
        abort();
    } else {
        original_PDRevertPalette();
    }
}

function_hook_state_t function_hook_state_PDInitScreenVars = HOOK_UNAVAILABLE;
static int(__cdecl*original_PDInitScreenVars)(int, char **) = (int(__cdecl*)(int, char **))0x004a70ad;
CARM95_HOOK_FUNCTION(original_PDInitScreenVars, PDInitScreenVars)
int __cdecl PDInitScreenVars(int pArgc, char **pArgv) {
    LOG_TRACE("(%d, %p)", pArgc, pArgv);

    (void)pArgc;
    (void)pArgv;

    if (function_hook_state_PDInitScreenVars == HOOK_ENABLED) {
        assert(0 && "PDInitScreenVars not implemented.");
        abort();
    } else {
        return original_PDInitScreenVars(pArgc, pArgv);
    }
}

function_hook_state_t function_hook_state_PDInitScreen = HOOK_UNAVAILABLE;
static void(__cdecl*original_PDInitScreen)() = (void(__cdecl*)())0x004a70d6;
CARM95_HOOK_FUNCTION(original_PDInitScreen, PDInitScreen)
void __cdecl PDInitScreen() {
    LOG_TRACE("()");


    if (function_hook_state_PDInitScreen == HOOK_ENABLED) {
        assert(0 && "PDInitScreen not implemented.");
        abort();
    } else {
        original_PDInitScreen();
    }
}

function_hook_state_t function_hook_state_PDLockRealBackScreen = HOOK_UNAVAILABLE;
static void(__cdecl*original_PDLockRealBackScreen)() = (void(__cdecl*)())0x004a7217;
CARM95_HOOK_FUNCTION(original_PDLockRealBackScreen, PDLockRealBackScreen)
void __cdecl PDLockRealBackScreen() {
    LOG_TRACE("()");


    if (function_hook_state_PDLockRealBackScreen == HOOK_ENABLED) {
        assert(0 && "PDLockRealBackScreen not implemented.");
        abort();
    } else {
        original_PDLockRealBackScreen();
    }
}

function_hook_state_t function_hook_state_PDUnlockRealBackScreen = HOOK_UNAVAILABLE;
static void(__cdecl*original_PDUnlockRealBackScreen)() = (void(__cdecl*)())0x004a727d;
CARM95_HOOK_FUNCTION(original_PDUnlockRealBackScreen, PDUnlockRealBackScreen)
void __cdecl PDUnlockRealBackScreen() {
    LOG_TRACE("()");


    if (function_hook_state_PDUnlockRealBackScreen == HOOK_ENABLED) {
        assert(0 && "PDUnlockRealBackScreen not implemented.");
        abort();
    } else {
        original_PDUnlockRealBackScreen();
    }
}

function_hook_state_t function_hook_state_PDAllocateScreenAndBack = HOOK_UNAVAILABLE;
static void(__cdecl*original_PDAllocateScreenAndBack)() = (void(__cdecl*)())0x004a728d;
CARM95_HOOK_FUNCTION(original_PDAllocateScreenAndBack, PDAllocateScreenAndBack)
void __cdecl PDAllocateScreenAndBack() {
    LOG_TRACE("()");


    if (function_hook_state_PDAllocateScreenAndBack == HOOK_ENABLED) {
        assert(0 && "PDAllocateScreenAndBack not implemented.");
        abort();
    } else {
        original_PDAllocateScreenAndBack();
    }
}

function_hook_state_t function_hook_state_Copy8BitTo16BitPixelmap = HOOK_UNAVAILABLE;
void Copy8BitTo16BitPixelmap(br_pixelmap *pDst, br_pixelmap *pSrc, br_pixelmap *pPalette) {
    int x;
    int y;
    tU8 *src;
    tU8 value;
    tU8 red;
    tU8 green;
    tU8 blue;
    tU16 *dst;
    tU16 *palette_entry;
    LOG_TRACE("(%p, %p, %p)", pDst, pSrc, pPalette);

    (void)pDst;
    (void)pSrc;
    (void)pPalette;
    (void)x;
    (void)y;
    (void)src;
    (void)value;
    (void)red;
    (void)green;
    (void)blue;
    (void)dst;
    (void)palette_entry;

    if (function_hook_state_Copy8BitTo16BitPixelmap == HOOK_ENABLED) {
        assert(0 && "Copy8BitTo16BitPixelmap not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}

function_hook_state_t function_hook_state_Double8BitTo16BitPixelmap = HOOK_UNAVAILABLE;
void Double8BitTo16BitPixelmap(br_pixelmap *pDst, br_pixelmap *pSrc, br_pixelmap *pPalette, tU16 pOff, tU16 pSrc_width, tU16 pSrc_height) {
    int x;
    int y;
    tU8 *src;
    tU8 value;
    tU8 red;
    tU8 green;
    tU8 blue;
    tU16 *dst0;
    tU16 *dst1;
    tU16 sixteen;
    tU16 *palette_entry;
    LOG_TRACE("(%p, %p, %p, %u, %u, %u)", pDst, pSrc, pPalette, pOff, pSrc_width, pSrc_height);

    (void)pDst;
    (void)pSrc;
    (void)pPalette;
    (void)pOff;
    (void)pSrc_width;
    (void)pSrc_height;
    (void)x;
    (void)y;
    (void)src;
    (void)value;
    (void)red;
    (void)green;
    (void)blue;
    (void)dst0;
    (void)dst1;
    (void)sixteen;
    (void)palette_entry;

    if (function_hook_state_Double8BitTo16BitPixelmap == HOOK_ENABLED) {
        assert(0 && "Double8BitTo16BitPixelmap not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}

function_hook_state_t function_hook_state_PDInterfacePixelmap = HOOK_UNAVAILABLE;
br_pixelmap* PDInterfacePixelmap() {
    LOG_TRACE("()");


    if (function_hook_state_PDInterfacePixelmap == HOOK_ENABLED) {
        assert(0 && "PDInterfacePixelmap not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}

function_hook_state_t function_hook_state_SwapBackScreen = HOOK_UNAVAILABLE;
void SwapBackScreen() {
    LOG_TRACE("()");


    if (function_hook_state_SwapBackScreen == HOOK_ENABLED) {
        assert(0 && "SwapBackScreen not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}

function_hook_state_t function_hook_state_ReallyCopyBackScreen = HOOK_UNAVAILABLE;
void ReallyCopyBackScreen(int pRendering_area_only, int pClear_top_and_bottom) {
    LOG_TRACE("(%d, %d)", pRendering_area_only, pClear_top_and_bottom);

    (void)pRendering_area_only;
    (void)pClear_top_and_bottom;

    if (function_hook_state_ReallyCopyBackScreen == HOOK_ENABLED) {
        assert(0 && "ReallyCopyBackScreen not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}

function_hook_state_t function_hook_state_CopyBackScreen = HOOK_UNAVAILABLE;
void CopyBackScreen(int pRendering_area_only) {
    LOG_TRACE("(%d)", pRendering_area_only);

    (void)pRendering_area_only;

    if (function_hook_state_CopyBackScreen == HOOK_ENABLED) {
        assert(0 && "CopyBackScreen not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}

function_hook_state_t function_hook_state_PDScreenBufferSwap = HOOK_UNAVAILABLE;
static void(__cdecl*original_PDScreenBufferSwap)(int) = (void(__cdecl*)(int))0x004a758e;
CARM95_HOOK_FUNCTION(original_PDScreenBufferSwap, PDScreenBufferSwap)
void __cdecl PDScreenBufferSwap(int pRendering_area_only) {
    LOG_TRACE("(%d)", pRendering_area_only);

    (void)pRendering_area_only;

    if (function_hook_state_PDScreenBufferSwap == HOOK_ENABLED) {
        assert(0 && "PDScreenBufferSwap not implemented.");
        abort();
    } else {
        original_PDScreenBufferSwap(pRendering_area_only);
    }
}

function_hook_state_t function_hook_state_PDPixelmapToScreenRectangleCopy = HOOK_UNAVAILABLE;
static void(__cdecl*original_PDPixelmapToScreenRectangleCopy)(br_pixelmap *, br_int_16, br_int_16, br_pixelmap *, br_int_16, br_int_16, br_uint_16, br_uint_16) = (void(__cdecl*)(br_pixelmap *, br_int_16, br_int_16, br_pixelmap *, br_int_16, br_int_16, br_uint_16, br_uint_16))0x004a763e;
CARM95_HOOK_FUNCTION(original_PDPixelmapToScreenRectangleCopy, PDPixelmapToScreenRectangleCopy)
void __cdecl PDPixelmapToScreenRectangleCopy(br_pixelmap *dst, br_int_16 dx, br_int_16 dy, br_pixelmap *src, br_int_16 sx, br_int_16 sy, br_uint_16 w, br_uint_16 h) {
    LOG_TRACE("(%p, %d, %d, %p, %d, %d, %u, %u)", dst, dx, dy, src, sx, sy, w, h);

    (void)dst;
    (void)dx;
    (void)dy;
    (void)src;
    (void)sx;
    (void)sy;
    (void)w;
    (void)h;

    if (function_hook_state_PDPixelmapToScreenRectangleCopy == HOOK_ENABLED) {
        assert(0 && "PDPixelmapToScreenRectangleCopy not implemented.");
        abort();
    } else {
        original_PDPixelmapToScreenRectangleCopy(dst, dx, dy, src, sx, sy, w, h);
    }
}

function_hook_state_t function_hook_state_PDPixelmapHLineOnScreen = HOOK_UNAVAILABLE;
static void(__cdecl*original_PDPixelmapHLineOnScreen)(br_pixelmap *, br_int_16, br_int_16, br_int_16, br_int_16, br_uint_32) = (void(__cdecl*)(br_pixelmap *, br_int_16, br_int_16, br_int_16, br_int_16, br_uint_32))0x004a768b;
CARM95_HOOK_FUNCTION(original_PDPixelmapHLineOnScreen, PDPixelmapHLineOnScreen)
void __cdecl PDPixelmapHLineOnScreen(br_pixelmap *dst, br_int_16 x1, br_int_16 y1, br_int_16 x2, br_int_16 y2, br_uint_32 colour) {
    LOG_TRACE("(%p, %d, %d, %d, %d, %u)", dst, x1, y1, x2, y2, colour);

    (void)dst;
    (void)x1;
    (void)y1;
    (void)x2;
    (void)y2;
    (void)colour;

    if (function_hook_state_PDPixelmapHLineOnScreen == HOOK_ENABLED) {
        assert(0 && "PDPixelmapHLineOnScreen not implemented.");
        abort();
    } else {
        original_PDPixelmapHLineOnScreen(dst, x1, y1, x2, y2, colour);
    }
}

function_hook_state_t function_hook_state_PDPixelmapVLineOnScreen = HOOK_UNAVAILABLE;
static void(__cdecl*original_PDPixelmapVLineOnScreen)(br_pixelmap *, br_int_16, br_int_16, br_int_16, br_int_16, br_uint_32) = (void(__cdecl*)(br_pixelmap *, br_int_16, br_int_16, br_int_16, br_int_16, br_uint_32))0x004a76ba;
CARM95_HOOK_FUNCTION(original_PDPixelmapVLineOnScreen, PDPixelmapVLineOnScreen)
void __cdecl PDPixelmapVLineOnScreen(br_pixelmap *dst, br_int_16 x1, br_int_16 y1, br_int_16 x2, br_int_16 y2, br_uint_32 colour) {
    LOG_TRACE("(%p, %d, %d, %d, %d, %u)", dst, x1, y1, x2, y2, colour);

    (void)dst;
    (void)x1;
    (void)y1;
    (void)x2;
    (void)y2;
    (void)colour;

    if (function_hook_state_PDPixelmapVLineOnScreen == HOOK_ENABLED) {
        assert(0 && "PDPixelmapVLineOnScreen not implemented.");
        abort();
    } else {
        original_PDPixelmapVLineOnScreen(dst, x1, y1, x2, y2, colour);
    }
}

function_hook_state_t function_hook_state_PDInstallErrorHandlers = HOOK_UNAVAILABLE;
static void(__cdecl*original_PDInstallErrorHandlers)() = (void(__cdecl*)())0x004a7766;
CARM95_HOOK_FUNCTION(original_PDInstallErrorHandlers, PDInstallErrorHandlers)
void __cdecl PDInstallErrorHandlers() {
    LOG_TRACE("()");


    if (function_hook_state_PDInstallErrorHandlers == HOOK_ENABLED) {
        assert(0 && "PDInstallErrorHandlers not implemented.");
        abort();
    } else {
        original_PDInstallErrorHandlers();
    }
}

function_hook_state_t function_hook_state_PDSetFileVariables = HOOK_UNAVAILABLE;
static void(__cdecl*original_PDSetFileVariables)() = (void(__cdecl*)())0x004a779c;
CARM95_HOOK_FUNCTION(original_PDSetFileVariables, PDSetFileVariables)
void __cdecl PDSetFileVariables() {
    LOG_TRACE("()");


    if (function_hook_state_PDSetFileVariables == HOOK_ENABLED) {
        assert(0 && "PDSetFileVariables not implemented.");
        abort();
    } else {
        original_PDSetFileVariables();
    }
}

function_hook_state_t function_hook_state_PDBuildAppPath = HOOK_UNAVAILABLE;
static void(__cdecl*original_PDBuildAppPath)(char *) = (void(__cdecl*)(char *))0x004a77b3;
CARM95_HOOK_FUNCTION(original_PDBuildAppPath, PDBuildAppPath)
void __cdecl PDBuildAppPath(char *pThe_path) {
    int pos;
    LOG_TRACE("(\"%s\")", pThe_path);

    (void)pThe_path;
    (void)pos;

    if (function_hook_state_PDBuildAppPath == HOOK_ENABLED) {
        assert(0 && "PDBuildAppPath not implemented.");
        abort();
    } else {
        original_PDBuildAppPath(pThe_path);
    }
}

function_hook_state_t function_hook_state_PDForEveryFile = HOOK_UNAVAILABLE;
static void(__cdecl*original_PDForEveryFile)(char *, void(**)(char *)) = (void(__cdecl*)(char *, void(**)(char *)))0x004a7807;
CARM95_HOOK_FUNCTION(original_PDForEveryFile, PDForEveryFile)
void __cdecl PDForEveryFile(char *pThe_path, void(**pAction_routine)(char *)) {
    char find_path[256];
    char found_path[256];
    struct find_t the_find_buffer;
    LOG_TRACE("(\"%s\", %p)", pThe_path, pAction_routine);

    (void)pThe_path;
    (void)pAction_routine;
    (void)find_path;
    (void)found_path;
    (void)the_find_buffer;

    if (function_hook_state_PDForEveryFile == HOOK_ENABLED) {
        assert(0 && "PDForEveryFile not implemented.");
        abort();
    } else {
        original_PDForEveryFile(pThe_path, pAction_routine);
    }
}

function_hook_state_t function_hook_state_PDSetPalette = HOOK_UNAVAILABLE;
static void(__cdecl*original_PDSetPalette)(br_pixelmap *) = (void(__cdecl*)(br_pixelmap *))0x004a7903;
CARM95_HOOK_FUNCTION(original_PDSetPalette, PDSetPalette)
void __cdecl PDSetPalette(br_pixelmap *pThe_palette) {
    LOG_TRACE("(%p)", pThe_palette);

    (void)pThe_palette;

    if (function_hook_state_PDSetPalette == HOOK_ENABLED) {
        assert(0 && "PDSetPalette not implemented.");
        abort();
    } else {
        original_PDSetPalette(pThe_palette);
    }
}

function_hook_state_t function_hook_state_PDSetPaletteEntries = HOOK_UNAVAILABLE;
static void(__cdecl*original_PDSetPaletteEntries)(br_pixelmap *, int, int) = (void(__cdecl*)(br_pixelmap *, int, int))0x004a79d0;
CARM95_HOOK_FUNCTION(original_PDSetPaletteEntries, PDSetPaletteEntries)
void __cdecl PDSetPaletteEntries(br_pixelmap *pPalette, int pFirst_colour, int pCount) {
    int i;
    tU8 *p;
    LOG_TRACE("(%p, %d, %d)", pPalette, pFirst_colour, pCount);

    (void)pPalette;
    (void)pFirst_colour;
    (void)pCount;
    (void)i;
    (void)p;

    if (function_hook_state_PDSetPaletteEntries == HOOK_ENABLED) {
        assert(0 && "PDSetPaletteEntries not implemented.");
        abort();
    } else {
        original_PDSetPaletteEntries(pPalette, pFirst_colour, pCount);
    }
}

function_hook_state_t function_hook_state_PDSwitchToRealResolution = HOOK_UNAVAILABLE;
static void(__cdecl*original_PDSwitchToRealResolution)() = (void(__cdecl*)())0x004a71ce;
CARM95_HOOK_FUNCTION(original_PDSwitchToRealResolution, PDSwitchToRealResolution)
void __cdecl PDSwitchToRealResolution() {
    LOG_TRACE("()");


    if (function_hook_state_PDSwitchToRealResolution == HOOK_ENABLED) {
        assert(0 && "PDSwitchToRealResolution not implemented.");
        abort();
    } else {
        original_PDSwitchToRealResolution();
    }
}

function_hook_state_t function_hook_state_PDSwitchToLoresMode = HOOK_UNAVAILABLE;
static void(__cdecl*original_PDSwitchToLoresMode)() = (void(__cdecl*)())0x004a71f1;
CARM95_HOOK_FUNCTION(original_PDSwitchToLoresMode, PDSwitchToLoresMode)
void __cdecl PDSwitchToLoresMode() {
    LOG_TRACE("()");


    if (function_hook_state_PDSwitchToLoresMode == HOOK_ENABLED) {
        assert(0 && "PDSwitchToLoresMode not implemented.");
        abort();
    } else {
        original_PDSwitchToLoresMode();
    }
}

function_hook_state_t function_hook_state_PDMouseButtons = HOOK_UNAVAILABLE;
static void(__cdecl*original_PDMouseButtons)(int *, int *) = (void(__cdecl*)(int *, int *))0x004a79f2;
CARM95_HOOK_FUNCTION(original_PDMouseButtons, PDMouseButtons)
void __cdecl PDMouseButtons(int *pButton_1, int *pButton_2) {
    br_uint_32 mouse_buttons;
    br_int_32 mouse_x;
    br_int_32 mouse_y;
    LOG_TRACE("(%p, %p)", pButton_1, pButton_2);

    (void)pButton_1;
    (void)pButton_2;
    (void)mouse_buttons;
    (void)mouse_x;
    (void)mouse_y;

    if (function_hook_state_PDMouseButtons == HOOK_ENABLED) {
        assert(0 && "PDMouseButtons not implemented.");
        abort();
    } else {
        original_PDMouseButtons(pButton_1, pButton_2);
    }
}

function_hook_state_t function_hook_state_PDGetMousePosition = HOOK_UNAVAILABLE;
static void(__cdecl*original_PDGetMousePosition)(int *, int *) = (void(__cdecl*)(int *, int *))0x004a7a11;
CARM95_HOOK_FUNCTION(original_PDGetMousePosition, PDGetMousePosition)
void __cdecl PDGetMousePosition(int *pX_coord, int *pY_coord) {
    br_uint_32 mouse_buttons;
    br_int_32 mouse_x2;
    br_int_32 mouse_y2;
    int delta_x;
    int delta_y;
    static br_int_32 mouse_x;
    static br_int_32 mouse_y;
    LOG_TRACE("(%p, %p)", pX_coord, pY_coord);

    (void)pX_coord;
    (void)pY_coord;
    (void)mouse_buttons;
    (void)mouse_x2;
    (void)mouse_y2;
    (void)delta_x;
    (void)delta_y;
    (void)mouse_x;
    (void)mouse_y;

    if (function_hook_state_PDGetMousePosition == HOOK_ENABLED) {
        assert(0 && "PDGetMousePosition not implemented.");
        abort();
    } else {
        original_PDGetMousePosition(pX_coord, pY_coord);
    }
}

function_hook_state_t function_hook_state_PDGetTotalTime = HOOK_UNAVAILABLE;
static int(__cdecl*original_PDGetTotalTime)() = (int(__cdecl*)())0x004a83c5;
CARM95_HOOK_FUNCTION(original_PDGetTotalTime, PDGetTotalTime)
int __cdecl PDGetTotalTime() {
    LOG_TRACE("()");


    if (function_hook_state_PDGetTotalTime == HOOK_ENABLED) {
        assert(0 && "PDGetTotalTime not implemented.");
        abort();
    } else {
        return original_PDGetTotalTime();
    }
}

function_hook_state_t function_hook_state_PDServiceSystem = HOOK_UNAVAILABLE;
static int(__cdecl*original_PDServiceSystem)(tU32) = (int(__cdecl*)(tU32))0x004a7b63;
CARM95_HOOK_FUNCTION(original_PDServiceSystem, PDServiceSystem)
int __cdecl PDServiceSystem(tU32 pTime_since_last_call) {
    LOG_TRACE("(%u)", pTime_since_last_call);

    (void)pTime_since_last_call;

    if (function_hook_state_PDServiceSystem == HOOK_ENABLED) {
        assert(0 && "PDServiceSystem not implemented.");
        abort();
    } else {
        return original_PDServiceSystem(pTime_since_last_call);
    }
}

function_hook_state_t function_hook_state_LargestBlockAvail = HOOK_UNAVAILABLE;
tU32 LargestBlockAvail() {
    union REGS regs;
    struct SREGS sregs;
    tMem_info mem_info;
    size_t memmax;
    LOG_TRACE("()");

    (void)regs;
    (void)sregs;
    (void)mem_info;
    (void)memmax;

    if (function_hook_state_LargestBlockAvail == HOOK_ENABLED) {
        assert(0 && "LargestBlockAvail not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}

function_hook_state_t function_hook_state_PDGrabLargestMammaryWeCanPlayWith = HOOK_UNAVAILABLE;
void* PDGrabLargestMammaryWeCanPlayWith(tU32 pMaximum_required, tU32 *pAmount_allocated) {
    void *result;
    LOG_TRACE("(%u, %p)", pMaximum_required, pAmount_allocated);

    (void)pMaximum_required;
    (void)pAmount_allocated;
    (void)result;

    if (function_hook_state_PDGrabLargestMammaryWeCanPlayWith == HOOK_ENABLED) {
        assert(0 && "PDGrabLargestMammaryWeCanPlayWith not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}

function_hook_state_t function_hook_state_PDAllocateActionReplayBuffer = HOOK_UNAVAILABLE;
static void(__cdecl*original_PDAllocateActionReplayBuffer)(char **, tU32 *) = (void(__cdecl*)(char **, tU32 *))0x004a68e2;
CARM95_HOOK_FUNCTION(original_PDAllocateActionReplayBuffer, PDAllocateActionReplayBuffer)
void __cdecl PDAllocateActionReplayBuffer(char **pBuffer, tU32 *pBuffer_size) {
    tU32 lba;
    tU32 required;
    LOG_TRACE("(%p, %p)", pBuffer, pBuffer_size);

    (void)pBuffer;
    (void)pBuffer_size;
    (void)lba;
    (void)required;

    if (function_hook_state_PDAllocateActionReplayBuffer == HOOK_ENABLED) {
        assert(0 && "PDAllocateActionReplayBuffer not implemented.");
        abort();
    } else {
        original_PDAllocateActionReplayBuffer(pBuffer, pBuffer_size);
    }
}

function_hook_state_t function_hook_state_PDDisposeActionReplayBuffer = HOOK_UNAVAILABLE;
static void(__cdecl*original_PDDisposeActionReplayBuffer)(char *) = (void(__cdecl*)(char *))0x004a6906;
CARM95_HOOK_FUNCTION(original_PDDisposeActionReplayBuffer, PDDisposeActionReplayBuffer)
void __cdecl PDDisposeActionReplayBuffer(char *pBuffer) {
    LOG_TRACE("(\"%s\")", pBuffer);

    (void)pBuffer;

    if (function_hook_state_PDDisposeActionReplayBuffer == HOOK_ENABLED) {
        assert(0 && "PDDisposeActionReplayBuffer not implemented.");
        abort();
    } else {
        original_PDDisposeActionReplayBuffer(pBuffer);
    }
}

function_hook_state_t function_hook_state_Usage = HOOK_UNAVAILABLE;
void Usage(char *pProgpath) {
    char basename[9];
    LOG_TRACE("(\"%s\")", pProgpath);

    (void)pProgpath;
    (void)basename;

    if (function_hook_state_Usage == HOOK_ENABLED) {
        assert(0 && "Usage not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}

function_hook_state_t function_hook_state_main = HOOK_UNAVAILABLE;
int main(int pArgc, char **pArgv) {
    int arg;
    int i;
    float f;
    LOG_TRACE("(%d, %p)", pArgc, pArgv);

    (void)pArgc;
    (void)pArgv;
    (void)arg;
    (void)i;
    (void)f;

    if (function_hook_state_main == HOOK_ENABLED) {
        assert(0 && "main not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}

function_hook_state_t function_hook_state_OurGetChar = HOOK_UNAVAILABLE;
int OurGetChar() {
    int key;
    LOG_TRACE("()");

    (void)key;

    if (function_hook_state_OurGetChar == HOOK_ENABLED) {
        assert(0 && "OurGetChar not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}

function_hook_state_t function_hook_state_PDGetGorePassword = HOOK_UNAVAILABLE;
int PDGetGorePassword() {
    int ch;
    int len;
    int chances;
    char password[17];
    LOG_TRACE("()");

    (void)ch;
    (void)len;
    (void)chances;
    (void)password;

    if (function_hook_state_PDGetGorePassword == HOOK_ENABLED) {
        assert(0 && "PDGetGorePassword not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}

function_hook_state_t function_hook_state_PDDisplayGoreworthiness = HOOK_UNAVAILABLE;
void PDDisplayGoreworthiness(int pGory) {
    tU32 delay_start;
    LOG_TRACE("(%d)", pGory);

    (void)pGory;
    (void)delay_start;

    if (function_hook_state_PDDisplayGoreworthiness == HOOK_ENABLED) {
        assert(0 && "PDDisplayGoreworthiness not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}

function_hook_state_t function_hook_state_PDEnterDebugger = HOOK_UNAVAILABLE;
static void(__cdecl*original_PDEnterDebugger)(char *) = (void(__cdecl*)(char *))0x004a60e3;
CARM95_HOOK_FUNCTION(original_PDEnterDebugger, PDEnterDebugger)
void __cdecl PDEnterDebugger(char *pStr) {
    static unsigned char *save_it;
    LOG_TRACE("(\"%s\")", pStr);

    (void)pStr;
    (void)save_it;

    if (function_hook_state_PDEnterDebugger == HOOK_ENABLED) {
        assert(0 && "PDEnterDebugger not implemented.");
        abort();
    } else {
        original_PDEnterDebugger(pStr);
    }
}

function_hook_state_t function_hook_state_PDEndItAllAndReRunTheBastard = HOOK_UNAVAILABLE;
void PDEndItAllAndReRunTheBastard() {
    LOG_TRACE("()");


    if (function_hook_state_PDEndItAllAndReRunTheBastard == HOOK_ENABLED) {
        assert(0 && "PDEndItAllAndReRunTheBastard not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}

#if 0
function_hook_state_t function_hook_state_matherr = HOOK_UNAVAILABLE;
int matherr(struct exception *err) {
    LOG_TRACE("(%p)", err);

    (void)err;

    if (function_hook_state_matherr == HOOK_ENABLED) {
        assert(0 && "matherr not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}
#endif

#if 0
function_hook_state_t function_hook_state_LoopLimitTooLow = HOOK_UNAVAILABLE;
int LoopLimitTooLow(tU32 limit) {
    clock_t start;
    tU32 count;
    tU32 val;
    LOG_TRACE("(%u)", limit);

    (void)limit;
    (void)start;
    (void)count;
    (void)val;

    if (function_hook_state_LoopLimitTooLow == HOOK_ENABLED) {
        assert(0 && "LoopLimitTooLow not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}
#endif

function_hook_state_t function_hook_state_UpperLoopLimit = HOOK_UNAVAILABLE;
tS32 UpperLoopLimit() {
    tU32 limit;
    LOG_TRACE("()");

    (void)limit;

    if (function_hook_state_UpperLoopLimit == HOOK_ENABLED) {
        assert(0 && "UpperLoopLimit not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}

function_hook_state_t function_hook_state_InitJoysticks = HOOK_UNAVAILABLE;
int InitJoysticks() {
    LOG_TRACE("()");


    if (function_hook_state_InitJoysticks == HOOK_ENABLED) {
        assert(0 && "InitJoysticks not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}

function_hook_state_t function_hook_state_ReadJoystickAxis = HOOK_UNAVAILABLE;
tU32 ReadJoystickAxis(int pBit) {
    tU32 val;
    tU32 count;
    LOG_TRACE("(%d)", pBit);

    (void)pBit;
    (void)val;
    (void)count;

    if (function_hook_state_ReadJoystickAxis == HOOK_ENABLED) {
        assert(0 && "ReadJoystickAxis not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}

function_hook_state_t function_hook_state_PDReadJoySticks = HOOK_UNAVAILABLE;
void PDReadJoySticks() {
    tU32 temp1x;
    tU32 temp1y;
    tU32 temp2x;
    tU32 temp2y;
    LOG_TRACE("()");

    (void)temp1x;
    (void)temp1y;
    (void)temp2x;
    (void)temp2y;

    if (function_hook_state_PDReadJoySticks == HOOK_ENABLED) {
        assert(0 && "PDReadJoySticks not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}

function_hook_state_t function_hook_state_PDGetJoy1X = HOOK_UNAVAILABLE;
tS32 PDGetJoy1X() {
    tS32 joy;
    LOG_TRACE("()");

    (void)joy;

    if (function_hook_state_PDGetJoy1X == HOOK_ENABLED) {
        assert(0 && "PDGetJoy1X not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}

function_hook_state_t function_hook_state_PDGetJoy1Y = HOOK_UNAVAILABLE;
tS32 PDGetJoy1Y() {
    tS32 joy;
    LOG_TRACE("()");

    (void)joy;

    if (function_hook_state_PDGetJoy1Y == HOOK_ENABLED) {
        assert(0 && "PDGetJoy1Y not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}

function_hook_state_t function_hook_state_PDGetJoy2X = HOOK_UNAVAILABLE;
tS32 PDGetJoy2X() {
    tS32 joy;
    LOG_TRACE("()");

    (void)joy;

    if (function_hook_state_PDGetJoy2X == HOOK_ENABLED) {
        assert(0 && "PDGetJoy2X not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}

function_hook_state_t function_hook_state_PDGetJoy2Y = HOOK_UNAVAILABLE;
tS32 PDGetJoy2Y() {
    tS32 joy;
    LOG_TRACE("()");

    (void)joy;

    if (function_hook_state_PDGetJoy2Y == HOOK_ENABLED) {
        assert(0 && "PDGetJoy2Y not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}

function_hook_state_t function_hook_state_PDGetJoy1Button1 = HOOK_UNAVAILABLE;
int PDGetJoy1Button1() {
    LOG_TRACE("()");


    if (function_hook_state_PDGetJoy1Button1 == HOOK_ENABLED) {
        assert(0 && "PDGetJoy1Button1 not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}

function_hook_state_t function_hook_state_PDGetJoy1Button2 = HOOK_UNAVAILABLE;
int PDGetJoy1Button2() {
    LOG_TRACE("()");


    if (function_hook_state_PDGetJoy1Button2 == HOOK_ENABLED) {
        assert(0 && "PDGetJoy1Button2 not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}

function_hook_state_t function_hook_state_PDGetJoy1Button3 = HOOK_UNAVAILABLE;
int PDGetJoy1Button3() {
    LOG_TRACE("()");


    if (function_hook_state_PDGetJoy1Button3 == HOOK_ENABLED) {
        assert(0 && "PDGetJoy1Button3 not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}

function_hook_state_t function_hook_state_PDGetJoy1Button4 = HOOK_UNAVAILABLE;
int PDGetJoy1Button4() {
    LOG_TRACE("()");


    if (function_hook_state_PDGetJoy1Button4 == HOOK_ENABLED) {
        assert(0 && "PDGetJoy1Button4 not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}

function_hook_state_t function_hook_state_PDGetJoy2Button1 = HOOK_UNAVAILABLE;
int PDGetJoy2Button1() {
    LOG_TRACE("()");


    if (function_hook_state_PDGetJoy2Button1 == HOOK_ENABLED) {
        assert(0 && "PDGetJoy2Button1 not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}

function_hook_state_t function_hook_state_PDGetJoy2Button2 = HOOK_UNAVAILABLE;
int PDGetJoy2Button2() {
    LOG_TRACE("()");


    if (function_hook_state_PDGetJoy2Button2 == HOOK_ENABLED) {
        assert(0 && "PDGetJoy2Button2 not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}

function_hook_state_t function_hook_state_PDGetJoy2Button3 = HOOK_UNAVAILABLE;
int PDGetJoy2Button3() {
    LOG_TRACE("()");


    if (function_hook_state_PDGetJoy2Button3 == HOOK_ENABLED) {
        assert(0 && "PDGetJoy2Button3 not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}

function_hook_state_t function_hook_state_PDGetJoy2Button4 = HOOK_UNAVAILABLE;
int PDGetJoy2Button4() {
    LOG_TRACE("()");


    if (function_hook_state_PDGetJoy2Button4 == HOOK_ENABLED) {
        assert(0 && "PDGetJoy2Button4 not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}

function_hook_state_t function_hook_state_PDFileUnlock = HOOK_UNAVAILABLE;
static int(__cdecl*original_PDFileUnlock)(char *) = (int(__cdecl*)(char *))0x004a83e6;
CARM95_HOOK_FUNCTION(original_PDFileUnlock, PDFileUnlock)
int __cdecl PDFileUnlock(char *pThe_path) {
    unsigned int attr;
    LOG_TRACE("(\"%s\")", pThe_path);

    (void)pThe_path;
    (void)attr;

    if (function_hook_state_PDFileUnlock == HOOK_ENABLED) {
        assert(0 && "PDFileUnlock not implemented.");
        abort();
    } else {
        return original_PDFileUnlock(pThe_path);
    }
}

function_hook_state_t function_hook_state_CriticalISR = HOOK_UNAVAILABLE;
void CriticalISR(union INTPACK pRegs) {
    LOG_TRACE("()");

    (void)pRegs;

    if (function_hook_state_CriticalISR == HOOK_ENABLED) {
        assert(0 && "CriticalISR not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}

function_hook_state_t function_hook_state_PDCheckDriveExists2 = HOOK_UNAVAILABLE;
static int(__cdecl*original_PDCheckDriveExists2)(char *, char *, tU32) = (int(__cdecl*)(char *, char *, tU32))0x004a8429;
CARM95_HOOK_FUNCTION(original_PDCheckDriveExists2, PDCheckDriveExists2)
int __cdecl PDCheckDriveExists2(char *pThe_path, char *pFile_name, tU32 pMin_size) {
    struct stat buf;
    void(**old_critical_isr)();
    int stat_failed;
    char slasher[4];
    char the_path[256];
    LOG_TRACE("(\"%s\", \"%s\", %u)", pThe_path, pFile_name, pMin_size);

    (void)pThe_path;
    (void)pFile_name;
    (void)pMin_size;
    (void)buf;
    (void)old_critical_isr;
    (void)stat_failed;
    (void)slasher;
    (void)the_path;

    if (function_hook_state_PDCheckDriveExists2 == HOOK_ENABLED) {
        assert(0 && "PDCheckDriveExists2 not implemented.");
        abort();
    } else {
        return original_PDCheckDriveExists2(pThe_path, pFile_name, pMin_size);
    }
}

function_hook_state_t function_hook_state_PDDoWeLeadAnAustereExistance = HOOK_UNAVAILABLE;
static int(__cdecl*original_PDDoWeLeadAnAustereExistance)() = (int(__cdecl*)())0x004a856f;
CARM95_HOOK_FUNCTION(original_PDDoWeLeadAnAustereExistance, PDDoWeLeadAnAustereExistance)
int __cdecl PDDoWeLeadAnAustereExistance() {
    tU32 lba;
    LOG_TRACE("()");

    (void)lba;

    if (function_hook_state_PDDoWeLeadAnAustereExistance == HOOK_ENABLED) {
        assert(0 && "PDDoWeLeadAnAustereExistance not implemented.");
        abort();
    } else {
        return original_PDDoWeLeadAnAustereExistance();
    }
}

