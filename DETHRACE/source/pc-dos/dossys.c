#include "dossys.h"

#include "harness/trace.h"

#include "carm95_hooks.h"

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

void KeyboardHandler() {
    tU8 scan_code;
    tU8 up;
    static tU8 extended;
    LOG_TRACE("()");

    (void)scan_code;
    (void)up;
    (void)extended;

    NOT_IMPLEMENTED();
}

int KeyDown(tU8 pScan_code) {
    LOG_TRACE("(%u)", pScan_code);

    (void)pScan_code;

    NOT_IMPLEMENTED();
}

void KeyTranslation(tU8 pKey_index, tU8 pScan_code_1, tU8 pScan_code_2) {
    LOG_TRACE("(%u, %u, %u)", pKey_index, pScan_code_1, pScan_code_2);

    (void)pKey_index;
    (void)pScan_code_1;
    (void)pScan_code_2;

    NOT_IMPLEMENTED();
}

static void(*original_KeyBegin)() = (void(*)())0x004a6b34;
CARM95_HOOK_FUNCTION(original_KeyBegin, KeyBegin)
void KeyBegin() {
    LOG_TRACE("()");


    original_KeyBegin();
}

void KeyEnd() {
    LOG_TRACE("()");


    NOT_IMPLEMENTED();
}

int KeyDown22(int pKey_index) {
    LOG_TRACE("(%d)", pKey_index);

    (void)pKey_index;

    NOT_IMPLEMENTED();
}

static void(*original_PDSetKeyArray)(int *, int, ...) = (void(*)(int *, int, ...))0x004a7d4c;
CARM95_HOOK_FUNCTION(original_PDSetKeyArray, PDSetKeyArray)
void PDSetKeyArray(int *pKeys, int pMark) {
    int i;
    tS32 joyX;
    tS32 joyY;
    LOG_TRACE("(%p, %d)", pKeys, pMark);

    (void)pKeys;
    (void)pMark;
    (void)i;
    (void)joyX;
    (void)joyY;

    original_PDSetKeyArray(pKeys, pMark);
}

static int(*original_PDGetASCIIFromKey)(int, ...) = (int(*)(int, ...))0x004a7a49;
CARM95_HOOK_FUNCTION(original_PDGetASCIIFromKey, PDGetASCIIFromKey)
int PDGetASCIIFromKey(int pKey) {
    LOG_TRACE("(%d)", pKey);

    (void)pKey;

    return original_PDGetASCIIFromKey(pKey);
}

static void(*original_PDFatalError)(char *, ...) = (void(*)(char *, ...))0x004a633f;
CARM95_HOOK_FUNCTION(original_PDFatalError, PDFatalError)
void PDFatalError(char *pThe_str) {
    static int been_here;
    LOG_TRACE("(\"%s\")", pThe_str);

    (void)pThe_str;
    (void)been_here;

    original_PDFatalError(pThe_str);
}

static void(*original_PDNonFatalError)(char *, ...) = (void(*)(char *, ...))0x004a63aa;
CARM95_HOOK_FUNCTION(original_PDNonFatalError, PDNonFatalError)
void PDNonFatalError(char *pThe_str) {
    LOG_TRACE("(\"%s\")", pThe_str);

    (void)pThe_str;

    original_PDNonFatalError(pThe_str);
}

static void(*original_PDInitialiseSystem)() = (void(*)())0x004a692c;
CARM95_HOOK_FUNCTION(original_PDInitialiseSystem, PDInitialiseSystem)
void PDInitialiseSystem() {
    tPath_name the_path;
    FILE *f;
    int len;
    LOG_TRACE("()");

    (void)the_path;
    (void)f;
    (void)len;

    original_PDInitialiseSystem();
}

static void(*original_PDShutdownSystem)() = (void(*)())0x004a6f6d;
CARM95_HOOK_FUNCTION(original_PDShutdownSystem, PDShutdownSystem)
void PDShutdownSystem() {
    LOG_TRACE("()");


    original_PDShutdownSystem();
}

static void(*original_PDSaveOriginalPalette)() = (void(*)())0x004a7097;
CARM95_HOOK_FUNCTION(original_PDSaveOriginalPalette, PDSaveOriginalPalette)
void PDSaveOriginalPalette() {
    LOG_TRACE("()");


    original_PDSaveOriginalPalette();
}

static void(*original_PDRevertPalette)() = (void(*)())0x004a70a2;
CARM95_HOOK_FUNCTION(original_PDRevertPalette, PDRevertPalette)
void PDRevertPalette() {
    LOG_TRACE("()");


    original_PDRevertPalette();
}

static int(*original_PDInitScreenVars)(int, char **, ...) = (int(*)(int, char **, ...))0x004a70ad;
CARM95_HOOK_FUNCTION(original_PDInitScreenVars, PDInitScreenVars)
int PDInitScreenVars(int pArgc, char **pArgv) {
    LOG_TRACE("(%d, %p)", pArgc, pArgv);

    (void)pArgc;
    (void)pArgv;

    return original_PDInitScreenVars(pArgc, pArgv);
}

static void(*original_PDInitScreen)() = (void(*)())0x004a70d6;
CARM95_HOOK_FUNCTION(original_PDInitScreen, PDInitScreen)
void PDInitScreen() {
    LOG_TRACE("()");


    original_PDInitScreen();
}

static void(*original_PDLockRealBackScreen)() = (void(*)())0x004a7217;
CARM95_HOOK_FUNCTION(original_PDLockRealBackScreen, PDLockRealBackScreen)
void PDLockRealBackScreen() {
    LOG_TRACE("()");


    original_PDLockRealBackScreen();
}

static void(*original_PDUnlockRealBackScreen)() = (void(*)())0x004a727d;
CARM95_HOOK_FUNCTION(original_PDUnlockRealBackScreen, PDUnlockRealBackScreen)
void PDUnlockRealBackScreen() {
    LOG_TRACE("()");


    original_PDUnlockRealBackScreen();
}

static void(*original_PDAllocateScreenAndBack)() = (void(*)())0x004a728d;
CARM95_HOOK_FUNCTION(original_PDAllocateScreenAndBack, PDAllocateScreenAndBack)
void PDAllocateScreenAndBack() {
    LOG_TRACE("()");


    original_PDAllocateScreenAndBack();
}

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

    NOT_IMPLEMENTED();
}

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

    NOT_IMPLEMENTED();
}

br_pixelmap* PDInterfacePixelmap() {
    LOG_TRACE("()");


    NOT_IMPLEMENTED();
}

void SwapBackScreen() {
    LOG_TRACE("()");


    NOT_IMPLEMENTED();
}

void ReallyCopyBackScreen(int pRendering_area_only, int pClear_top_and_bottom) {
    LOG_TRACE("(%d, %d)", pRendering_area_only, pClear_top_and_bottom);

    (void)pRendering_area_only;
    (void)pClear_top_and_bottom;

    NOT_IMPLEMENTED();
}

void CopyBackScreen(int pRendering_area_only) {
    LOG_TRACE("(%d)", pRendering_area_only);

    (void)pRendering_area_only;

    NOT_IMPLEMENTED();
}

static void(*original_PDScreenBufferSwap)(int, ...) = (void(*)(int, ...))0x004a758e;
CARM95_HOOK_FUNCTION(original_PDScreenBufferSwap, PDScreenBufferSwap)
void PDScreenBufferSwap(int pRendering_area_only) {
    LOG_TRACE("(%d)", pRendering_area_only);

    (void)pRendering_area_only;

    original_PDScreenBufferSwap(pRendering_area_only);
}

static void(*original_PDPixelmapToScreenRectangleCopy)(br_pixelmap *, br_int_16, br_int_16, br_pixelmap *, br_int_16, br_int_16, br_uint_16, br_uint_16, ...) = (void(*)(br_pixelmap *, br_int_16, br_int_16, br_pixelmap *, br_int_16, br_int_16, br_uint_16, br_uint_16, ...))0x004a763e;
CARM95_HOOK_FUNCTION(original_PDPixelmapToScreenRectangleCopy, PDPixelmapToScreenRectangleCopy)
void PDPixelmapToScreenRectangleCopy(br_pixelmap *dst, br_int_16 dx, br_int_16 dy, br_pixelmap *src, br_int_16 sx, br_int_16 sy, br_uint_16 w, br_uint_16 h) {
    LOG_TRACE("(%p, %d, %d, %p, %d, %d, %u, %u)", dst, dx, dy, src, sx, sy, w, h);

    (void)dst;
    (void)dx;
    (void)dy;
    (void)src;
    (void)sx;
    (void)sy;
    (void)w;
    (void)h;

    original_PDPixelmapToScreenRectangleCopy(dst, dx, dy, src, sx, sy, w, h);
}

static void(*original_PDPixelmapHLineOnScreen)(br_pixelmap *, br_int_16, br_int_16, br_int_16, br_int_16, br_uint_32, ...) = (void(*)(br_pixelmap *, br_int_16, br_int_16, br_int_16, br_int_16, br_uint_32, ...))0x004a768b;
CARM95_HOOK_FUNCTION(original_PDPixelmapHLineOnScreen, PDPixelmapHLineOnScreen)
void PDPixelmapHLineOnScreen(br_pixelmap *dst, br_int_16 x1, br_int_16 y1, br_int_16 x2, br_int_16 y2, br_uint_32 colour) {
    LOG_TRACE("(%p, %d, %d, %d, %d, %u)", dst, x1, y1, x2, y2, colour);

    (void)dst;
    (void)x1;
    (void)y1;
    (void)x2;
    (void)y2;
    (void)colour;

    original_PDPixelmapHLineOnScreen(dst, x1, y1, x2, y2, colour);
}

static void(*original_PDPixelmapVLineOnScreen)(br_pixelmap *, br_int_16, br_int_16, br_int_16, br_int_16, br_uint_32, ...) = (void(*)(br_pixelmap *, br_int_16, br_int_16, br_int_16, br_int_16, br_uint_32, ...))0x004a76ba;
CARM95_HOOK_FUNCTION(original_PDPixelmapVLineOnScreen, PDPixelmapVLineOnScreen)
void PDPixelmapVLineOnScreen(br_pixelmap *dst, br_int_16 x1, br_int_16 y1, br_int_16 x2, br_int_16 y2, br_uint_32 colour) {
    LOG_TRACE("(%p, %d, %d, %d, %d, %u)", dst, x1, y1, x2, y2, colour);

    (void)dst;
    (void)x1;
    (void)y1;
    (void)x2;
    (void)y2;
    (void)colour;

    original_PDPixelmapVLineOnScreen(dst, x1, y1, x2, y2, colour);
}

static void(*original_PDInstallErrorHandlers)() = (void(*)())0x004a7766;
CARM95_HOOK_FUNCTION(original_PDInstallErrorHandlers, PDInstallErrorHandlers)
void PDInstallErrorHandlers() {
    LOG_TRACE("()");


    original_PDInstallErrorHandlers();
}

static void(*original_PDSetFileVariables)() = (void(*)())0x004a779c;
CARM95_HOOK_FUNCTION(original_PDSetFileVariables, PDSetFileVariables)
void PDSetFileVariables() {
    LOG_TRACE("()");


    original_PDSetFileVariables();
}

static void(*original_PDBuildAppPath)(char *, ...) = (void(*)(char *, ...))0x004a77b3;
CARM95_HOOK_FUNCTION(original_PDBuildAppPath, PDBuildAppPath)
void PDBuildAppPath(char *pThe_path) {
    int pos;
    LOG_TRACE("(\"%s\")", pThe_path);

    (void)pThe_path;
    (void)pos;

    original_PDBuildAppPath(pThe_path);
}

static void(*original_PDForEveryFile)(char *, void(**)(char *, ...), ...) = (void(*)(char *, void(**)(char *, ...), ...))0x004a7807;
CARM95_HOOK_FUNCTION(original_PDForEveryFile, PDForEveryFile)
void PDForEveryFile(char *pThe_path, void(**pAction_routine)(char *, ...)) {
    char find_path[256];
    char found_path[256];
    struct find_t the_find_buffer;
    LOG_TRACE("(\"%s\", %p)", pThe_path, pAction_routine);

    (void)pThe_path;
    (void)pAction_routine;
    (void)find_path;
    (void)found_path;
    (void)the_find_buffer;

    original_PDForEveryFile(pThe_path, pAction_routine);
}

static void(*original_PDSetPalette)(br_pixelmap *, ...) = (void(*)(br_pixelmap *, ...))0x004a7903;
CARM95_HOOK_FUNCTION(original_PDSetPalette, PDSetPalette)
void PDSetPalette(br_pixelmap *pThe_palette) {
    LOG_TRACE("(%p)", pThe_palette);

    (void)pThe_palette;

    original_PDSetPalette(pThe_palette);
}

static void(*original_PDSetPaletteEntries)(br_pixelmap *, int, int, ...) = (void(*)(br_pixelmap *, int, int, ...))0x004a79d0;
CARM95_HOOK_FUNCTION(original_PDSetPaletteEntries, PDSetPaletteEntries)
void PDSetPaletteEntries(br_pixelmap *pPalette, int pFirst_colour, int pCount) {
    int i;
    tU8 *p;
    LOG_TRACE("(%p, %d, %d)", pPalette, pFirst_colour, pCount);

    (void)pPalette;
    (void)pFirst_colour;
    (void)pCount;
    (void)i;
    (void)p;

    original_PDSetPaletteEntries(pPalette, pFirst_colour, pCount);
}

static void(*original_PDSwitchToRealResolution)() = (void(*)())0x004a71ce;
CARM95_HOOK_FUNCTION(original_PDSwitchToRealResolution, PDSwitchToRealResolution)
void PDSwitchToRealResolution() {
    LOG_TRACE("()");


    original_PDSwitchToRealResolution();
}

static void(*original_PDSwitchToLoresMode)() = (void(*)())0x004a71f1;
CARM95_HOOK_FUNCTION(original_PDSwitchToLoresMode, PDSwitchToLoresMode)
void PDSwitchToLoresMode() {
    LOG_TRACE("()");


    original_PDSwitchToLoresMode();
}

static void(*original_PDMouseButtons)(int *, int *, ...) = (void(*)(int *, int *, ...))0x004a79f2;
CARM95_HOOK_FUNCTION(original_PDMouseButtons, PDMouseButtons)
void PDMouseButtons(int *pButton_1, int *pButton_2) {
    br_uint_32 mouse_buttons;
    br_int_32 mouse_x;
    br_int_32 mouse_y;
    LOG_TRACE("(%p, %p)", pButton_1, pButton_2);

    (void)pButton_1;
    (void)pButton_2;
    (void)mouse_buttons;
    (void)mouse_x;
    (void)mouse_y;

    original_PDMouseButtons(pButton_1, pButton_2);
}

static void(*original_PDGetMousePosition)(int *, int *, ...) = (void(*)(int *, int *, ...))0x004a7a11;
CARM95_HOOK_FUNCTION(original_PDGetMousePosition, PDGetMousePosition)
void PDGetMousePosition(int *pX_coord, int *pY_coord) {
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

    original_PDGetMousePosition(pX_coord, pY_coord);
}

static int(*original_PDGetTotalTime)() = (int(*)())0x004a83c5;
CARM95_HOOK_FUNCTION(original_PDGetTotalTime, PDGetTotalTime)
int PDGetTotalTime() {
    LOG_TRACE("()");


    return original_PDGetTotalTime();
}

static int(*original_PDServiceSystem)(tU32, ...) = (int(*)(tU32, ...))0x004a7b63;
CARM95_HOOK_FUNCTION(original_PDServiceSystem, PDServiceSystem)
int PDServiceSystem(tU32 pTime_since_last_call) {
    LOG_TRACE("(%u)", pTime_since_last_call);

    (void)pTime_since_last_call;

    return original_PDServiceSystem(pTime_since_last_call);
}

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

    NOT_IMPLEMENTED();
}

void* PDGrabLargestMammaryWeCanPlayWith(tU32 pMaximum_required, tU32 *pAmount_allocated) {
    void *result;
    LOG_TRACE("(%u, %p)", pMaximum_required, pAmount_allocated);

    (void)pMaximum_required;
    (void)pAmount_allocated;
    (void)result;

    NOT_IMPLEMENTED();
}

static void(*original_PDAllocateActionReplayBuffer)(char **, tU32 *, ...) = (void(*)(char **, tU32 *, ...))0x004a68e2;
CARM95_HOOK_FUNCTION(original_PDAllocateActionReplayBuffer, PDAllocateActionReplayBuffer)
void PDAllocateActionReplayBuffer(char **pBuffer, tU32 *pBuffer_size) {
    tU32 lba;
    tU32 required;
    LOG_TRACE("(%p, %p)", pBuffer, pBuffer_size);

    (void)pBuffer;
    (void)pBuffer_size;
    (void)lba;
    (void)required;

    original_PDAllocateActionReplayBuffer(pBuffer, pBuffer_size);
}

static void(*original_PDDisposeActionReplayBuffer)(char *, ...) = (void(*)(char *, ...))0x004a6906;
CARM95_HOOK_FUNCTION(original_PDDisposeActionReplayBuffer, PDDisposeActionReplayBuffer)
void PDDisposeActionReplayBuffer(char *pBuffer) {
    LOG_TRACE("(\"%s\")", pBuffer);

    (void)pBuffer;

    original_PDDisposeActionReplayBuffer(pBuffer);
}

void Usage(char *pProgpath) {
    char basename[9];
    LOG_TRACE("(\"%s\")", pProgpath);

    (void)pProgpath;
    (void)basename;

    NOT_IMPLEMENTED();
}

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

    NOT_IMPLEMENTED();
}

int OurGetChar() {
    int key;
    LOG_TRACE("()");

    (void)key;

    NOT_IMPLEMENTED();
}

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

    NOT_IMPLEMENTED();
}

void PDDisplayGoreworthiness(int pGory) {
    tU32 delay_start;
    LOG_TRACE("(%d)", pGory);

    (void)pGory;
    (void)delay_start;

    NOT_IMPLEMENTED();
}

static void(*original_PDEnterDebugger)(char *, ...) = (void(*)(char *, ...))0x004a60e3;
CARM95_HOOK_FUNCTION(original_PDEnterDebugger, PDEnterDebugger)
void PDEnterDebugger(char *pStr) {
    static unsigned char *save_it;
    LOG_TRACE("(\"%s\")", pStr);

    (void)pStr;
    (void)save_it;

    original_PDEnterDebugger(pStr);
}

void PDEndItAllAndReRunTheBastard() {
    LOG_TRACE("()");


    NOT_IMPLEMENTED();
}

#if 0
int matherr(struct exception *err) {
    LOG_TRACE("(%p)", err);

    (void)err;

    NOT_IMPLEMENTED();
}
#endif

#if 0
int LoopLimitTooLow(tU32 limit) {
    clock_t start;
    tU32 count;
    tU32 val;
    LOG_TRACE("(%u)", limit);

    (void)limit;
    (void)start;
    (void)count;
    (void)val;

    NOT_IMPLEMENTED();
}
#endif

tS32 UpperLoopLimit() {
    tU32 limit;
    LOG_TRACE("()");

    (void)limit;

    NOT_IMPLEMENTED();
}

int InitJoysticks() {
    LOG_TRACE("()");


    NOT_IMPLEMENTED();
}

tU32 ReadJoystickAxis(int pBit) {
    tU32 val;
    tU32 count;
    LOG_TRACE("(%d)", pBit);

    (void)pBit;
    (void)val;
    (void)count;

    NOT_IMPLEMENTED();
}

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

    NOT_IMPLEMENTED();
}

tS32 PDGetJoy1X() {
    tS32 joy;
    LOG_TRACE("()");

    (void)joy;

    NOT_IMPLEMENTED();
}

tS32 PDGetJoy1Y() {
    tS32 joy;
    LOG_TRACE("()");

    (void)joy;

    NOT_IMPLEMENTED();
}

tS32 PDGetJoy2X() {
    tS32 joy;
    LOG_TRACE("()");

    (void)joy;

    NOT_IMPLEMENTED();
}

tS32 PDGetJoy2Y() {
    tS32 joy;
    LOG_TRACE("()");

    (void)joy;

    NOT_IMPLEMENTED();
}

int PDGetJoy1Button1() {
    LOG_TRACE("()");


    NOT_IMPLEMENTED();
}

int PDGetJoy1Button2() {
    LOG_TRACE("()");


    NOT_IMPLEMENTED();
}

int PDGetJoy1Button3() {
    LOG_TRACE("()");


    NOT_IMPLEMENTED();
}

int PDGetJoy1Button4() {
    LOG_TRACE("()");


    NOT_IMPLEMENTED();
}

int PDGetJoy2Button1() {
    LOG_TRACE("()");


    NOT_IMPLEMENTED();
}

int PDGetJoy2Button2() {
    LOG_TRACE("()");


    NOT_IMPLEMENTED();
}

int PDGetJoy2Button3() {
    LOG_TRACE("()");


    NOT_IMPLEMENTED();
}

int PDGetJoy2Button4() {
    LOG_TRACE("()");


    NOT_IMPLEMENTED();
}

static int(*original_PDFileUnlock)(char *, ...) = (int(*)(char *, ...))0x004a83e6;
CARM95_HOOK_FUNCTION(original_PDFileUnlock, PDFileUnlock)
int PDFileUnlock(char *pThe_path) {
    unsigned int attr;
    LOG_TRACE("(\"%s\")", pThe_path);

    (void)pThe_path;
    (void)attr;

    return original_PDFileUnlock(pThe_path);
}

#if 0
void CriticalISR(union INTPACK pRegs) {
    LOG_TRACE("()");

    (void)pRegs;

    NOT_IMPLEMENTED();
}
#endif

static int(*original_PDCheckDriveExists2)(char *, char *, tU32, ...) = (int(*)(char *, char *, tU32, ...))0x004a8429;
CARM95_HOOK_FUNCTION(original_PDCheckDriveExists2, PDCheckDriveExists2)
int PDCheckDriveExists2(char *pThe_path, char *pFile_name, tU32 pMin_size) {
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

    return original_PDCheckDriveExists2(pThe_path, pFile_name, pMin_size);
}

static int(*original_PDDoWeLeadAnAustereExistance)() = (int(*)())0x004a856f;
CARM95_HOOK_FUNCTION(original_PDDoWeLeadAnAustereExistance, PDDoWeLeadAnAustereExistance)
int PDDoWeLeadAnAustereExistance() {
    tU32 lba;
    LOG_TRACE("()");

    (void)lba;

    return original_PDDoWeLeadAnAustereExistance();
}

