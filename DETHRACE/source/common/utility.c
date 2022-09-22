#include "utility.h"

#include "harness/trace.h"

#include "carm95_hooks.h"

int * hookvar_gIn_check_quit  = (void*)0x00521488;
tU32 * hookvar_gLost_time  = (void*)0x0052148c;
tU32(* hookvar_gLong_key )[4] = (void*)0x00521490;
tU32(* hookvar_gOther_long_key )[4] = (void*)0x005214a0;
#if 0
int * hookvar_gEncryption_method ;
#endif
char *(* hookvar_gMisc_strings )[250] = (void*)0x00544ef0;
#if 0
br_pixelmap ** hookvar_g16bit_palette ;
#endif
#if 0
br_pixelmap ** hookvar_gSource_for_16bit_palette ;
#endif

static int(__cdecl*original_CheckQuit)() = (int(__cdecl*)())0x004c1590;
CARM95_HOOK_FUNCTION(original_CheckQuit, CheckQuit)
int __cdecl CheckQuit() {
    int got_as_far_as_verify;
    LOG_TRACE("()");

    (void)got_as_far_as_verify;

    return original_CheckQuit();
}

static double(__cdecl*original_sqr)(double) = (double(__cdecl*)(double))0x004c161d;
CARM95_HOOK_FUNCTION(original_sqr, sqr)
double __cdecl sqr(double pN) {
    LOG_TRACE("(%f)", pN);

    (void)pN;

    return original_sqr(pN);
}

static void(__cdecl*original_EncodeLine)(char *) = (void(__cdecl*)(char *))0x004c1ab1;
CARM95_HOOK_FUNCTION(original_EncodeLine, EncodeLine)
void __cdecl EncodeLine(char *pS) {
    int len;
    int seed;
    int i;
    char *key;
    unsigned char c;
    FILE *test;
    char __block0__s[256];
    char __block0__the_path[256];
    LOG_TRACE("(\"%s\")", pS);

    (void)pS;
    (void)len;
    (void)seed;
    (void)i;
    (void)key;
    (void)c;
    (void)test;
    (void)__block0__s;
    (void)__block0__the_path;

    original_EncodeLine(pS);
}

static int(__cdecl*original_IRandomBetween)(int, int) = (int(__cdecl*)(int, int))0x004c1633;
CARM95_HOOK_FUNCTION(original_IRandomBetween, IRandomBetween)
int __cdecl IRandomBetween(int pA, int pB) {
    int num;
    char s[32];
    LOG_TRACE("(%d, %d)", pA, pB);

    (void)pA;
    (void)pB;
    (void)num;
    (void)s;

    return original_IRandomBetween(pA, pB);
}

static int(__cdecl*original_PercentageChance)(int) = (int(__cdecl*)(int))0x004c166c;
CARM95_HOOK_FUNCTION(original_PercentageChance, PercentageChance)
int __cdecl PercentageChance(int pC) {
    LOG_TRACE("(%d)", pC);

    (void)pC;

    return original_PercentageChance(pC);
}

static int(__cdecl*original_IRandomPosNeg)(int) = (int(__cdecl*)(int))0x004c169d;
CARM95_HOOK_FUNCTION(original_IRandomPosNeg, IRandomPosNeg)
int __cdecl IRandomPosNeg(int pN) {
    LOG_TRACE("(%d)", pN);

    (void)pN;

    return original_IRandomPosNeg(pN);
}

static float(__cdecl*original_FRandomBetween)(float, float) = (float(__cdecl*)(float, float))0x004c16bf;
CARM95_HOOK_FUNCTION(original_FRandomBetween, FRandomBetween)
float __cdecl FRandomBetween(float pA, float pB) {
    LOG_TRACE("(%f, %f)", pA, pB);

    (void)pA;
    (void)pB;

    return original_FRandomBetween(pA, pB);
}

static float(__cdecl*original_FRandomPosNeg)(float) = (float(__cdecl*)(float))0x004c16ee;
CARM95_HOOK_FUNCTION(original_FRandomPosNeg, FRandomPosNeg)
float __cdecl FRandomPosNeg(float pN) {
    LOG_TRACE("(%f)", pN);

    (void)pN;

    return original_FRandomPosNeg(pN);
}

static br_scalar(__cdecl*original_SRandomBetween)(br_scalar, br_scalar) = (br_scalar(__cdecl*)(br_scalar, br_scalar))0x004c1715;
CARM95_HOOK_FUNCTION(original_SRandomBetween, SRandomBetween)
br_scalar __cdecl SRandomBetween(br_scalar pA, br_scalar pB) {
    LOG_TRACE("(%f, %f)", pA, pB);

    (void)pA;
    (void)pB;

    return original_SRandomBetween(pA, pB);
}

static br_scalar(__cdecl*original_SRandomPosNeg)(br_scalar) = (br_scalar(__cdecl*)(br_scalar))0x004c1735;
CARM95_HOOK_FUNCTION(original_SRandomPosNeg, SRandomPosNeg)
br_scalar __cdecl SRandomPosNeg(br_scalar pN) {
    LOG_TRACE("(%f)", pN);

    (void)pN;

    return original_SRandomPosNeg(pN);
}

static char *(__cdecl*original_GetALineWithNoPossibleService)(FILE *, unsigned char *) = (char *(__cdecl*)(FILE *, unsigned char *))0x004c175c;
CARM95_HOOK_FUNCTION(original_GetALineWithNoPossibleService, GetALineWithNoPossibleService)
char* __cdecl GetALineWithNoPossibleService(FILE *pF, unsigned char *pS) {
    signed char *result;
    signed char s[256];
    int ch;
    int len;
    int i;
    LOG_TRACE("(%p, %p)", pF, pS);

    (void)pF;
    (void)pS;
    (void)result;
    (void)s;
    (void)ch;
    (void)len;
    (void)i;

    return original_GetALineWithNoPossibleService(pF, pS);
}

static char *(__cdecl*original_GetALineAndDontArgue)(FILE *, char *) = (char *(__cdecl*)(FILE *, char *))0x004c1d44;
CARM95_HOOK_FUNCTION(original_GetALineAndDontArgue, GetALineAndDontArgue)
char* __cdecl GetALineAndDontArgue(FILE *pF, char *pS) {
    LOG_TRACE("(%p, \"%s\")", pF, pS);

    (void)pF;
    (void)pS;

    return original_GetALineAndDontArgue(pF, pS);
}

static void(__cdecl*original_PathCat)(char *, char *, char *) = (void(__cdecl*)(char *, char *, char *))0x004c1d69;
CARM95_HOOK_FUNCTION(original_PathCat, PathCat)
void __cdecl PathCat(char *pDestn_str, char *pStr_1, char *pStr_2) {
    LOG_TRACE("(\"%s\", \"%s\", \"%s\")", pDestn_str, pStr_1, pStr_2);

    (void)pDestn_str;
    (void)pStr_1;
    (void)pStr_2;

    original_PathCat(pDestn_str, pStr_1, pStr_2);
}

static int(__cdecl*original_Chance)(float, int) = (int(__cdecl*)(float, int))0x004c1e16;
CARM95_HOOK_FUNCTION(original_Chance, Chance)
int __cdecl Chance(float pChance_per_second, int pPeriod) {
    LOG_TRACE("(%f, %d)", pChance_per_second, pPeriod);

    (void)pChance_per_second;
    (void)pPeriod;

    return original_Chance(pChance_per_second, pPeriod);
}

static float(__cdecl*original_tandeg)(float) = (float(__cdecl*)(float))0x004c1e63;
CARM95_HOOK_FUNCTION(original_tandeg, tandeg)
float __cdecl tandeg(float pAngle) {
    LOG_TRACE("(%f)", pAngle);

    (void)pAngle;

    return original_tandeg(pAngle);
}

static tU32(__cdecl*original_GetFileLength)(FILE *) = (tU32(__cdecl*)(FILE *))0x004c1e94;
CARM95_HOOK_FUNCTION(original_GetFileLength, GetFileLength)
tU32 __cdecl GetFileLength(FILE *pF) {
    tU32 the_size;
    LOG_TRACE("(%p)", pF);

    (void)pF;
    (void)the_size;

    return original_GetFileLength(pF);
}

static int(__cdecl*original_BooleanTo1Or0)(int) = (int(__cdecl*)(int))0x004c1ed5;
CARM95_HOOK_FUNCTION(original_BooleanTo1Or0, BooleanTo1Or0)
int __cdecl BooleanTo1Or0(int pB) {
    LOG_TRACE("(%d)", pB);

    (void)pB;

    return original_BooleanTo1Or0(pB);
}

static br_pixelmap *(__cdecl*original_DRPixelmapAllocate)(br_uint_8, br_uint_16, br_uint_16, void *, int) = (br_pixelmap *(__cdecl*)(br_uint_8, br_uint_16, br_uint_16, void *, int))0x004c1efb;
CARM95_HOOK_FUNCTION(original_DRPixelmapAllocate, DRPixelmapAllocate)
br_pixelmap* __cdecl DRPixelmapAllocate(br_uint_8 pType, br_uint_16 pW, br_uint_16 pH, void *pPixels, int pFlags) {
    br_pixelmap *the_map;
    LOG_TRACE("(%u, %u, %u, %p, %d)", pType, pW, pH, pPixels, pFlags);

    (void)pType;
    (void)pW;
    (void)pH;
    (void)pPixels;
    (void)pFlags;
    (void)the_map;

    return original_DRPixelmapAllocate(pType, pW, pH, pPixels, pFlags);
}

static br_pixelmap *(__cdecl*original_DRPixelmapAllocateSub)(br_pixelmap *, br_uint_16, br_uint_16, br_uint_16, br_uint_16) = (br_pixelmap *(__cdecl*)(br_pixelmap *, br_uint_16, br_uint_16, br_uint_16, br_uint_16))0x004c1f56;
CARM95_HOOK_FUNCTION(original_DRPixelmapAllocateSub, DRPixelmapAllocateSub)
br_pixelmap* __cdecl DRPixelmapAllocateSub(br_pixelmap *pPm, br_uint_16 pX, br_uint_16 pY, br_uint_16 pW, br_uint_16 pH) {
    br_pixelmap *the_map;
    LOG_TRACE("(%p, %u, %u, %u, %u)", pPm, pX, pY, pW, pH);

    (void)pPm;
    (void)pX;
    (void)pY;
    (void)pW;
    (void)pH;
    (void)the_map;

    return original_DRPixelmapAllocateSub(pPm, pX, pY, pW, pH);
}

br_pixelmap* DRPixelmapMatchSized(br_pixelmap *pSrc, tU8 pMatch_type, tS32 pWidth, tS32 pHeight) {
    br_pixelmap *result;
    LOG_TRACE("(%p, %u, %d, %d)", pSrc, pMatch_type, pWidth, pHeight);

    (void)pSrc;
    (void)pMatch_type;
    (void)pWidth;
    (void)pHeight;
    (void)result;

    NOT_IMPLEMENTED();
}

void CopyDoubled8BitTo16BitRectangle(br_pixelmap *pDst, br_pixelmap *pSrc, int pSrc_width, int pSrc_height, int pDst_x, int pDst_y, br_pixelmap *pPalette) {
    int x;
    int y;
    tU8 *src_start;
    tU16 *dst_start0;
    tU16 *dst_start1;
    tU16 *palette_entry;
    LOG_TRACE("(%p, %p, %d, %d, %d, %d, %p)", pDst, pSrc, pSrc_width, pSrc_height, pDst_x, pDst_y, pPalette);

    (void)pDst;
    (void)pSrc;
    (void)pSrc_width;
    (void)pSrc_height;
    (void)pDst_x;
    (void)pDst_y;
    (void)pPalette;
    (void)x;
    (void)y;
    (void)src_start;
    (void)dst_start0;
    (void)dst_start1;
    (void)palette_entry;

    NOT_IMPLEMENTED();
}

br_pixelmap* Scale8BitPixelmap(br_pixelmap *pSrc, int pWidth, int pHeight) {
    br_pixelmap *result;
    int x;
    int y;
    tU8 *src_pixels;
    tU8 *dst_pixels;
    LOG_TRACE("(%p, %d, %d)", pSrc, pWidth, pHeight);

    (void)pSrc;
    (void)pWidth;
    (void)pHeight;
    (void)result;
    (void)x;
    (void)y;
    (void)src_pixels;
    (void)dst_pixels;

    NOT_IMPLEMENTED();
}

br_pixelmap* Tile8BitPixelmap(br_pixelmap *pSrc, int pN) {
    br_pixelmap *result;
    int new_width;
    int new_height;
    int x;
    int y2;
    int y;
    tU8 *src_pixels;
    tU8 *dst_pixels;
    LOG_TRACE("(%p, %d)", pSrc, pN);

    (void)pSrc;
    (void)pN;
    (void)result;
    (void)new_width;
    (void)new_height;
    (void)x;
    (void)y2;
    (void)y;
    (void)src_pixels;
    (void)dst_pixels;

    NOT_IMPLEMENTED();
}

tException_list FindExceptionInList(char *pName, tException_list pList) {
    LOG_TRACE("(\"%s\", %p)", pName, pList);

    (void)pName;
    (void)pList;

    NOT_IMPLEMENTED();
}

br_pixelmap* PurifiedPixelmap(br_pixelmap *pSrc) {
    br_pixelmap *intermediate;
    br_pixelmap *result;
    int new_width;
    int new_height;
    tException_list e;
    LOG_TRACE("(%p)", pSrc);

    (void)pSrc;
    (void)intermediate;
    (void)result;
    (void)new_width;
    (void)new_height;
    (void)e;

    NOT_IMPLEMENTED();
}

static br_pixelmap *(__cdecl*original_DRPixelmapLoad)(char *) = (br_pixelmap *(__cdecl*)(char *))0x004c1fbb;
CARM95_HOOK_FUNCTION(original_DRPixelmapLoad, DRPixelmapLoad)
br_pixelmap* __cdecl DRPixelmapLoad(char *pFile_name) {
    br_pixelmap *the_map;
    LOG_TRACE("(\"%s\")", pFile_name);

    (void)pFile_name;
    (void)the_map;

    return original_DRPixelmapLoad(pFile_name);
}

static br_uint_32(__cdecl*original_DRPixelmapLoadMany)(char *, br_pixelmap **, br_uint_16) = (br_uint_32(__cdecl*)(char *, br_pixelmap **, br_uint_16))0x004c2010;
CARM95_HOOK_FUNCTION(original_DRPixelmapLoadMany, DRPixelmapLoadMany)
br_uint_32 __cdecl DRPixelmapLoadMany(char *pFile_name, br_pixelmap **pPixelmaps, br_uint_16 pNum) {
    br_pixelmap *the_map;
    int number_loaded;
    int i;
    LOG_TRACE("(\"%s\", %p, %u)", pFile_name, pPixelmaps, pNum);

    (void)pFile_name;
    (void)pPixelmaps;
    (void)pNum;
    (void)the_map;
    (void)number_loaded;
    (void)i;

    return original_DRPixelmapLoadMany(pFile_name, pPixelmaps, pNum);
}

static void(__cdecl*original_WaitFor)(tU32) = (void(__cdecl*)(tU32))0x004c209b;
CARM95_HOOK_FUNCTION(original_WaitFor, WaitFor)
void __cdecl WaitFor(tU32 pDelay) {
    tU32 start_time;
    LOG_TRACE("(%u)", pDelay);

    (void)pDelay;
    (void)start_time;

    original_WaitFor(pDelay);
}

static br_uint_32(__cdecl*original_DRActorEnumRecurse)(br_actor *, br_actor_enum_cbfn *, void *) = (br_uint_32(__cdecl*)(br_actor *, br_actor_enum_cbfn *, void *))0x004c20ce;
CARM95_HOOK_FUNCTION(original_DRActorEnumRecurse, DRActorEnumRecurse)
br_uint_32 __cdecl DRActorEnumRecurse(br_actor *pActor, br_actor_enum_cbfn *callback, void *arg) {
    br_uint_32 result;
    LOG_TRACE("(%p, %p, %p)", pActor, callback, arg);

    (void)pActor;
    (void)callback;
    (void)arg;
    (void)result;

    return original_DRActorEnumRecurse(pActor, callback, arg);
}

static br_uint_32(__cdecl*original_CompareActorID)(br_actor *, void *) = (br_uint_32(__cdecl*)(br_actor *, void *))0x004c2174;
CARM95_HOOK_FUNCTION(original_CompareActorID, CompareActorID)
br_uint_32 __cdecl CompareActorID(br_actor *pActor, void *pArg) {
    LOG_TRACE("(%p, %p)", pActor, pArg);

    (void)pActor;
    (void)pArg;

    return original_CompareActorID(pActor, pArg);
}

static br_actor *(__cdecl*original_DRActorFindRecurse)(br_actor *, char *) = (br_actor *(__cdecl*)(br_actor *, char *))0x004c214f;
CARM95_HOOK_FUNCTION(original_DRActorFindRecurse, DRActorFindRecurse)
br_actor* __cdecl DRActorFindRecurse(br_actor *pSearch_root, char *pName) {
    LOG_TRACE("(%p, \"%s\")", pSearch_root, pName);

    (void)pSearch_root;
    (void)pName;

    return original_DRActorFindRecurse(pSearch_root, pName);
}

static br_uint_32(__cdecl*original_DRActorEnumRecurseWithMat)(br_actor *, br_material *, br_uint_32(**)(br_actor *, br_material *, void *), void *) = (br_uint_32(__cdecl*)(br_actor *, br_material *, br_uint_32(**)(br_actor *, br_material *, void *), void *))0x004c21e9;
CARM95_HOOK_FUNCTION(original_DRActorEnumRecurseWithMat, DRActorEnumRecurseWithMat)
br_uint_32 __cdecl DRActorEnumRecurseWithMat(br_actor *pActor, br_material *pMat, br_uint_32(**pCall_back)(br_actor *, br_material *, void *), void *pArg) {
    br_uint_32 result;
    LOG_TRACE("(%p, %p, %p, %p)", pActor, pMat, pCall_back, pArg);

    (void)pActor;
    (void)pMat;
    (void)pCall_back;
    (void)pArg;
    (void)result;

    return original_DRActorEnumRecurseWithMat(pActor, pMat, pCall_back, pArg);
}

static br_uint_32(__cdecl*original_DRActorEnumRecurseWithTrans)(br_actor *, br_matrix34 *, br_uint_32(**)(br_actor *, br_matrix34 *, void *), void *) = (br_uint_32(__cdecl*)(br_actor *, br_matrix34 *, br_uint_32(**)(br_actor *, br_matrix34 *, void *), void *))0x004c2288;
CARM95_HOOK_FUNCTION(original_DRActorEnumRecurseWithTrans, DRActorEnumRecurseWithTrans)
br_uint_32 __cdecl DRActorEnumRecurseWithTrans(br_actor *pActor, br_matrix34 *pMatrix, br_uint_32(**pCall_back)(br_actor *, br_matrix34 *, void *), void *pArg) {
    br_uint_32 result;
    br_matrix34 combined_transform;
    LOG_TRACE("(%p, %p, %p, %p)", pActor, pMatrix, pCall_back, pArg);

    (void)pActor;
    (void)pMatrix;
    (void)pCall_back;
    (void)pArg;
    (void)result;
    (void)combined_transform;

    return original_DRActorEnumRecurseWithTrans(pActor, pMatrix, pCall_back, pArg);
}

static int(__cdecl*original_sign)(int) = (int(__cdecl*)(int))0x004c234a;
CARM95_HOOK_FUNCTION(original_sign, sign)
int __cdecl sign(int pNumber) {
    LOG_TRACE("(%d)", pNumber);

    (void)pNumber;

    return original_sign(pNumber);
}

static float(__cdecl*original_fsign)(float) = (float(__cdecl*)(float))0x004c2384;
CARM95_HOOK_FUNCTION(original_fsign, fsign)
float __cdecl fsign(float pNumber) {
    LOG_TRACE("(%f)", pNumber);

    (void)pNumber;

    return original_fsign(pNumber);
}

static FILE *(__cdecl*original_OpenUniqueFileB)(char *, char *) = (FILE *(__cdecl*)(char *, char *))0x004c23e7;
CARM95_HOOK_FUNCTION(original_OpenUniqueFileB, OpenUniqueFileB)
FILE* __cdecl OpenUniqueFileB(char *pPrefix, char *pExtension) {
    int index;
    FILE *f;
    tPath_name the_path;
    LOG_TRACE("(\"%s\", \"%s\")", pPrefix, pExtension);

    (void)pPrefix;
    (void)pExtension;
    (void)index;
    (void)f;
    (void)the_path;

    return original_OpenUniqueFileB(pPrefix, pExtension);
}

static void(__cdecl*original_PrintScreenFile)(FILE *) = (void(__cdecl*)(FILE *))0x004c24c8;
CARM95_HOOK_FUNCTION(original_PrintScreenFile, PrintScreenFile)
void __cdecl PrintScreenFile(FILE *pF) {
    int i;
    int j;
    int bit_map_size;
    int offset;
    tU8 *pixel_ptr;
    LOG_TRACE("(%p)", pF);

    (void)pF;
    (void)i;
    (void)j;
    (void)bit_map_size;
    (void)offset;
    (void)pixel_ptr;

    original_PrintScreenFile(pF);
}

void PrintScreenFile16(FILE *pF) {
    int i;
    int j;
    int bit_map_size;
    int offset;
    tU8 *pixel_ptr;
    tU16 pixel;
    LOG_TRACE("(%p)", pF);

    (void)pF;
    (void)i;
    (void)j;
    (void)bit_map_size;
    (void)offset;
    (void)pixel_ptr;
    (void)pixel;

    NOT_IMPLEMENTED();
}

static void(__cdecl*original_PrintScreen)() = (void(__cdecl*)())0x004c272c;
CARM95_HOOK_FUNCTION(original_PrintScreen, PrintScreen)
void __cdecl PrintScreen() {
    FILE *f;
    LOG_TRACE("()");

    (void)f;

    original_PrintScreen();
}

static tU32(__cdecl*original_GetTotalTime)() = (tU32(__cdecl*)())0x004c2771;
CARM95_HOOK_FUNCTION(original_GetTotalTime, GetTotalTime)
tU32 __cdecl GetTotalTime() {
    LOG_TRACE("()");


    return original_GetTotalTime();
}

static tU32(__cdecl*original_GetRaceTime)() = (tU32(__cdecl*)())0x004c27bf;
CARM95_HOOK_FUNCTION(original_GetRaceTime, GetRaceTime)
tU32 __cdecl GetRaceTime() {
    LOG_TRACE("()");


    return original_GetRaceTime();
}

static void(__cdecl*original_AddLostTime)(tU32) = (void(__cdecl*)(tU32))0x004c27da;
CARM95_HOOK_FUNCTION(original_AddLostTime, AddLostTime)
void __cdecl AddLostTime(tU32 pLost_time) {
    LOG_TRACE("(%u)", pLost_time);

    (void)pLost_time;

    original_AddLostTime(pLost_time);
}

static void(__cdecl*original_TimerString)(tU32, char *, int, int) = (void(__cdecl*)(tU32, char *, int, int))0x004c27ee;
CARM95_HOOK_FUNCTION(original_TimerString, TimerString)
void __cdecl TimerString(tU32 pTime, char *pStr, int pFudge_colon, int pForce_colon) {
    int seconds;
    LOG_TRACE("(%u, \"%s\", %d, %d)", pTime, pStr, pFudge_colon, pForce_colon);

    (void)pTime;
    (void)pStr;
    (void)pFudge_colon;
    (void)pForce_colon;
    (void)seconds;

    original_TimerString(pTime, pStr, pFudge_colon, pForce_colon);
}

static char *(__cdecl*original_GetMiscString)(int) = (char *(__cdecl*)(int))0x004c289f;
CARM95_HOOK_FUNCTION(original_GetMiscString, GetMiscString)
char* __cdecl GetMiscString(int pIndex) {
    LOG_TRACE("(%d)", pIndex);

    (void)pIndex;

    return original_GetMiscString(pIndex);
}

static void(__cdecl*original_GetCopyOfMiscString)(int, char *) = (void(__cdecl*)(int, char *))0x004c28b9;
CARM95_HOOK_FUNCTION(original_GetCopyOfMiscString, GetCopyOfMiscString)
void __cdecl GetCopyOfMiscString(int pIndex, char *pStr) {
    LOG_TRACE("(%d, \"%s\")", pIndex, pStr);

    (void)pIndex;
    (void)pStr;

    original_GetCopyOfMiscString(pIndex, pStr);
}

static int(__cdecl*original_Flash)(tU32, tU32 *, int *) = (int(__cdecl*)(tU32, tU32 *, int *))0x004c28f0;
CARM95_HOOK_FUNCTION(original_Flash, Flash)
int __cdecl Flash(tU32 pPeriod, tU32 *pLast_change, int *pCurrent_state) {
    tU32 the_time;
    LOG_TRACE("(%u, %p, %p)", pPeriod, pLast_change, pCurrent_state);

    (void)pPeriod;
    (void)pLast_change;
    (void)pCurrent_state;
    (void)the_time;

    return original_Flash(pPeriod, pLast_change, pCurrent_state);
}

static void(__cdecl*original_MaterialCopy)(br_material *, br_material *) = (void(__cdecl*)(br_material *, br_material *))0x004c294c;
CARM95_HOOK_FUNCTION(original_MaterialCopy, MaterialCopy)
void __cdecl MaterialCopy(br_material *pDst, br_material *pSrc) {
    LOG_TRACE("(%p, %p)", pDst, pSrc);

    (void)pDst;
    (void)pSrc;

    original_MaterialCopy(pDst, pSrc);
}

static double(__cdecl*original_RGBDifferenceSqr)(tRGB_colour *, tRGB_colour *) = (double(__cdecl*)(tRGB_colour *, tRGB_colour *))0x004c2f71;
CARM95_HOOK_FUNCTION(original_RGBDifferenceSqr, RGBDifferenceSqr)
double __cdecl RGBDifferenceSqr(tRGB_colour *pColour_1, tRGB_colour *pColour_2) {
    LOG_TRACE("(%p, %p)", pColour_1, pColour_2);

    (void)pColour_1;
    (void)pColour_2;

    return original_RGBDifferenceSqr(pColour_1, pColour_2);
}

static int(__cdecl*original_FindBestMatch)(tRGB_colour *, br_pixelmap *) = (int(__cdecl*)(tRGB_colour *, br_pixelmap *))0x004c2eb8;
CARM95_HOOK_FUNCTION(original_FindBestMatch, FindBestMatch)
int __cdecl FindBestMatch(tRGB_colour *pRGB_colour, br_pixelmap *pPalette) {
    int n;
    int near_c;
    double min_d;
    double d;
    tRGB_colour trial_RGB;
    br_colour *dp;
    LOG_TRACE("(%p, %p)", pRGB_colour, pPalette);

    (void)pRGB_colour;
    (void)pPalette;
    (void)n;
    (void)near_c;
    (void)min_d;
    (void)d;
    (void)trial_RGB;
    (void)dp;

    return original_FindBestMatch(pRGB_colour, pPalette);
}

static void(__cdecl*original_BuildShadeTablePath)(char *, int, int, int) = (void(__cdecl*)(char *, int, int, int))0x004c2a2e;
CARM95_HOOK_FUNCTION(original_BuildShadeTablePath, BuildShadeTablePath)
void __cdecl BuildShadeTablePath(char *pThe_path, int pR, int pG, int pB) {
    char s[32];
    LOG_TRACE("(\"%s\", %d, %d, %d)", pThe_path, pR, pG, pB);

    (void)pThe_path;
    (void)pR;
    (void)pG;
    (void)pB;
    (void)s;

    original_BuildShadeTablePath(pThe_path, pR, pG, pB);
}

static br_pixelmap *(__cdecl*original_LoadGeneratedShadeTable)(int, int, int) = (br_pixelmap *(__cdecl*)(int, int, int))0x004c29ee;
CARM95_HOOK_FUNCTION(original_LoadGeneratedShadeTable, LoadGeneratedShadeTable)
br_pixelmap* __cdecl LoadGeneratedShadeTable(int pR, int pG, int pB) {
    char the_path[256];
    LOG_TRACE("(%d, %d, %d)", pR, pG, pB);

    (void)pR;
    (void)pG;
    (void)pB;
    (void)the_path;

    return original_LoadGeneratedShadeTable(pR, pG, pB);
}

static void(__cdecl*original_SaveGeneratedShadeTable)(br_pixelmap *, int, int, int) = (void(__cdecl*)(br_pixelmap *, int, int, int))0x004c2b03;
CARM95_HOOK_FUNCTION(original_SaveGeneratedShadeTable, SaveGeneratedShadeTable)
void __cdecl SaveGeneratedShadeTable(br_pixelmap *pThe_table, int pR, int pG, int pB) {
    char the_path[256];
    LOG_TRACE("(%p, %d, %d, %d)", pThe_table, pR, pG, pB);

    (void)pThe_table;
    (void)pR;
    (void)pG;
    (void)pB;
    (void)the_path;

    original_SaveGeneratedShadeTable(pThe_table, pR, pG, pB);
}

static br_pixelmap *(__cdecl*original_GenerateShadeTable)(int, br_pixelmap *, int, int, int, float, float, float) = (br_pixelmap *(__cdecl*)(int, br_pixelmap *, int, int, int, float, float, float))0x004c2b42;
CARM95_HOOK_FUNCTION(original_GenerateShadeTable, GenerateShadeTable)
br_pixelmap* __cdecl GenerateShadeTable(int pHeight, br_pixelmap *pPalette, int pRed_mix, int pGreen_mix, int pBlue_mix, float pQuarter, float pHalf, float pThree_quarter) {
    LOG_TRACE("(%d, %p, %d, %d, %d, %f, %f, %f)", pHeight, pPalette, pRed_mix, pGreen_mix, pBlue_mix, pQuarter, pHalf, pThree_quarter);

    (void)pHeight;
    (void)pPalette;
    (void)pRed_mix;
    (void)pGreen_mix;
    (void)pBlue_mix;
    (void)pQuarter;
    (void)pHalf;
    (void)pThree_quarter;

    return original_GenerateShadeTable(pHeight, pPalette, pRed_mix, pGreen_mix, pBlue_mix, pQuarter, pHalf, pThree_quarter);
}

static br_pixelmap *(__cdecl*original_GenerateDarkenedShadeTable)(int, br_pixelmap *, int, int, int, float, float, float, br_scalar) = (br_pixelmap *(__cdecl*)(int, br_pixelmap *, int, int, int, float, float, float, br_scalar))0x004c2b84;
CARM95_HOOK_FUNCTION(original_GenerateDarkenedShadeTable, GenerateDarkenedShadeTable)
br_pixelmap* __cdecl GenerateDarkenedShadeTable(int pHeight, br_pixelmap *pPalette, int pRed_mix, int pGreen_mix, int pBlue_mix, float pQuarter, float pHalf, float pThree_quarter, br_scalar pDarken) {
    br_pixelmap *the_table;
    tRGB_colour the_RGB;
    tRGB_colour new_RGB;
    tRGB_colour ref_col;
    br_colour *cp;
    char *tab_ptr;
    char *shade_ptr;
    double f_i;
    double f_total_minus_1;
    double ratio1;
    double ratio2;
    int i;
    int c;
    LOG_TRACE("(%d, %p, %d, %d, %d, %f, %f, %f, %f)", pHeight, pPalette, pRed_mix, pGreen_mix, pBlue_mix, pQuarter, pHalf, pThree_quarter, pDarken);

    (void)pHeight;
    (void)pPalette;
    (void)pRed_mix;
    (void)pGreen_mix;
    (void)pBlue_mix;
    (void)pQuarter;
    (void)pHalf;
    (void)pThree_quarter;
    (void)pDarken;
    (void)the_table;
    (void)the_RGB;
    (void)new_RGB;
    (void)ref_col;
    (void)cp;
    (void)tab_ptr;
    (void)shade_ptr;
    (void)f_i;
    (void)f_total_minus_1;
    (void)ratio1;
    (void)ratio2;
    (void)i;
    (void)c;

    return original_GenerateDarkenedShadeTable(pHeight, pPalette, pRed_mix, pGreen_mix, pBlue_mix, pQuarter, pHalf, pThree_quarter, pDarken);
}

static void(__cdecl*original_PossibleService)() = (void(__cdecl*)())0x004c2fdb;
CARM95_HOOK_FUNCTION(original_PossibleService, PossibleService)
void __cdecl PossibleService() {
    tU32 time;
    static tU32 last_service;
    LOG_TRACE("()");

    (void)time;
    (void)last_service;

    original_PossibleService();
}

static void(__cdecl*original_DRMatrix34TApplyP)(br_vector3 *, br_vector3 *, br_matrix34 *) = (void(__cdecl*)(br_vector3 *, br_vector3 *, br_matrix34 *))0x004c302d;
CARM95_HOOK_FUNCTION(original_DRMatrix34TApplyP, DRMatrix34TApplyP)
void __cdecl DRMatrix34TApplyP(br_vector3 *pA, br_vector3 *pB, br_matrix34 *pC) {
    br_scalar t1;
    br_scalar t2;
    br_scalar t3;
    LOG_TRACE("(%p, %p, %p)", pA, pB, pC);

    (void)pA;
    (void)pB;
    (void)pC;
    (void)t1;
    (void)t2;
    (void)t3;

    original_DRMatrix34TApplyP(pA, pB, pC);
}

tU16 PaletteEntry16Bit(br_pixelmap *pPal, int pEntry) {
    tU32 *src_entry;
    int red;
    int green;
    int blue;
    LOG_TRACE("(%p, %d)", pPal, pEntry);

    (void)pPal;
    (void)pEntry;
    (void)src_entry;
    (void)red;
    (void)green;
    (void)blue;

    NOT_IMPLEMENTED();
}

br_pixelmap* PaletteOf16Bits(br_pixelmap *pSrc) {
    tU16 *dst_entry;
    int value;
    LOG_TRACE("(%p)", pSrc);

    (void)pSrc;
    (void)dst_entry;
    (void)value;

    NOT_IMPLEMENTED();
}

void Copy8BitTo16Bit(br_pixelmap *pDst, br_pixelmap *pSrc, br_pixelmap *pPalette) {
    int x;
    int y;
    tU8 *src_start;
    tU16 *dst_start;
    tU16 *palette_entry;
    LOG_TRACE("(%p, %p, %p)", pDst, pSrc, pPalette);

    (void)pDst;
    (void)pSrc;
    (void)pPalette;
    (void)x;
    (void)y;
    (void)src_start;
    (void)dst_start;
    (void)palette_entry;

    NOT_IMPLEMENTED();
}

void Copy8BitTo16BitRectangle(br_pixelmap *pDst, tS16 pDst_x, tS16 pDst_y, br_pixelmap *pSrc, tS16 pSrc_x, tS16 pSrc_y, tS16 pWidth, tS16 pHeight, br_pixelmap *pPalette) {
    int x;
    int y;
    tU8 *src_start;
    tU16 *dst_start;
    tU16 *palette_entry;
    LOG_TRACE("(%p, %d, %d, %p, %d, %d, %d, %d, %p)", pDst, pDst_x, pDst_y, pSrc, pSrc_x, pSrc_y, pWidth, pHeight, pPalette);

    (void)pDst;
    (void)pDst_x;
    (void)pDst_y;
    (void)pSrc;
    (void)pSrc_x;
    (void)pSrc_y;
    (void)pWidth;
    (void)pHeight;
    (void)pPalette;
    (void)x;
    (void)y;
    (void)src_start;
    (void)dst_start;
    (void)palette_entry;

    NOT_IMPLEMENTED();
}

void Copy8BitTo16BitRectangleWithTransparency(br_pixelmap *pDst, tS16 pDst_x, tS16 pDst_y, br_pixelmap *pSrc, tS16 pSrc_x, tS16 pSrc_y, tS16 pWidth, tS16 pHeight, br_pixelmap *pPalette) {
    int x;
    int y;
    tU8 *src_start;
    tU16 *dst_start;
    tU16 *palette_entry;
    LOG_TRACE("(%p, %d, %d, %p, %d, %d, %d, %d, %p)", pDst, pDst_x, pDst_y, pSrc, pSrc_x, pSrc_y, pWidth, pHeight, pPalette);

    (void)pDst;
    (void)pDst_x;
    (void)pDst_y;
    (void)pSrc;
    (void)pSrc_x;
    (void)pSrc_y;
    (void)pWidth;
    (void)pHeight;
    (void)pPalette;
    (void)x;
    (void)y;
    (void)src_start;
    (void)dst_start;
    (void)palette_entry;

    NOT_IMPLEMENTED();
}

void Copy8BitToOnscreen16BitRectangleWithTransparency(br_pixelmap *pDst, tS16 pDst_x, tS16 pDst_y, br_pixelmap *pSrc, tS16 pSrc_x, tS16 pSrc_y, tS16 pWidth, tS16 pHeight, br_pixelmap *pPalette) {
    int x;
    int y;
    tU8 *src_start;
    tU16 *dst_start;
    tU16 *palette_entry;
    LOG_TRACE("(%p, %d, %d, %p, %d, %d, %d, %d, %p)", pDst, pDst_x, pDst_y, pSrc, pSrc_x, pSrc_y, pWidth, pHeight, pPalette);

    (void)pDst;
    (void)pDst_x;
    (void)pDst_y;
    (void)pSrc;
    (void)pSrc_x;
    (void)pSrc_y;
    (void)pWidth;
    (void)pHeight;
    (void)pPalette;
    (void)x;
    (void)y;
    (void)src_start;
    (void)dst_start;
    (void)palette_entry;

    NOT_IMPLEMENTED();
}

void Copy8BitRectangleTo16BitRhombusWithTransparency(br_pixelmap *pDst, tS16 pDst_x, tS16 pDst_y, br_pixelmap *pSrc, tS16 pSrc_x, tS16 pSrc_y, tS16 pWidth, tS16 pHeight, tX1616 pShear, br_pixelmap *pPalette) {
    int x;
    int y;
    tU8 *src_start;
    tU16 *dst_start;
    tU16 *palette_entry;
    tX1616 total_shear;
    tS16 sheared_x;
    tS16 clipped_src_x;
    tS16 clipped_width;
    LOG_TRACE("(%p, %d, %d, %p, %d, %d, %d, %d, %d, %p)", pDst, pDst_x, pDst_y, pSrc, pSrc_x, pSrc_y, pWidth, pHeight, pShear, pPalette);

    (void)pDst;
    (void)pDst_x;
    (void)pDst_y;
    (void)pSrc;
    (void)pSrc_x;
    (void)pSrc_y;
    (void)pWidth;
    (void)pHeight;
    (void)pShear;
    (void)pPalette;
    (void)x;
    (void)y;
    (void)src_start;
    (void)dst_start;
    (void)palette_entry;
    (void)total_shear;
    (void)sheared_x;
    (void)clipped_src_x;
    (void)clipped_width;

    NOT_IMPLEMENTED();
}

static void(__cdecl*original_DRPixelmapRectangleCopy)(br_pixelmap *, br_int_16, br_int_16, br_pixelmap *, br_int_16, br_int_16, br_uint_16, br_uint_16) = (void(__cdecl*)(br_pixelmap *, br_int_16, br_int_16, br_pixelmap *, br_int_16, br_int_16, br_uint_16, br_uint_16))0x004c30d1;
CARM95_HOOK_FUNCTION(original_DRPixelmapRectangleCopy, DRPixelmapRectangleCopy)
void __cdecl DRPixelmapRectangleCopy(br_pixelmap *dst, br_int_16 dx, br_int_16 dy, br_pixelmap *src, br_int_16 sx, br_int_16 sy, br_uint_16 w, br_uint_16 h) {
    LOG_TRACE("(%p, %d, %d, %p, %d, %d, %u, %u)", dst, dx, dy, src, sx, sy, w, h);

    (void)dst;
    (void)dx;
    (void)dy;
    (void)src;
    (void)sx;
    (void)sy;
    (void)w;
    (void)h;

    original_DRPixelmapRectangleCopy(dst, dx, dy, src, sx, sy, w, h);
}

void DRPixelmapCopy(br_pixelmap *dst, br_pixelmap *src) {
    LOG_TRACE("(%p, %p)", dst, src);

    (void)dst;
    (void)src;

    NOT_IMPLEMENTED();
}

static void(__cdecl*original_DRPixelmapRectangleFill)(br_pixelmap *, br_int_16, br_int_16, br_uint_16, br_uint_16, br_uint_32) = (void(__cdecl*)(br_pixelmap *, br_int_16, br_int_16, br_uint_16, br_uint_16, br_uint_32))0x004c3112;
CARM95_HOOK_FUNCTION(original_DRPixelmapRectangleFill, DRPixelmapRectangleFill)
void __cdecl DRPixelmapRectangleFill(br_pixelmap *dst, br_int_16 x, br_int_16 y, br_uint_16 w, br_uint_16 h, br_uint_32 colour) {
    LOG_TRACE("(%p, %d, %d, %u, %u, %u)", dst, x, y, w, h, colour);

    (void)dst;
    (void)x;
    (void)y;
    (void)w;
    (void)h;
    (void)colour;

    original_DRPixelmapRectangleFill(dst, x, y, w, h, colour);
}

static int(__cdecl*original_NormalSideOfPlane)(br_vector3 *, br_vector3 *, br_scalar) = (int(__cdecl*)(br_vector3 *, br_vector3 *, br_scalar))0x004c3149;
CARM95_HOOK_FUNCTION(original_NormalSideOfPlane, NormalSideOfPlane)
int __cdecl NormalSideOfPlane(br_vector3 *pPoint, br_vector3 *pNormal, br_scalar pD) {
    br_scalar numer;
    br_scalar denom;
    LOG_TRACE("(%p, %p, %f)", pPoint, pNormal, pD);

    (void)pPoint;
    (void)pNormal;
    (void)pD;
    (void)numer;
    (void)denom;

    return original_NormalSideOfPlane(pPoint, pNormal, pD);
}

static br_material *(__cdecl*original_DRMaterialClone)(br_material *) = (br_material *(__cdecl*)(br_material *))0x004c31d1;
CARM95_HOOK_FUNCTION(original_DRMaterialClone, DRMaterialClone)
br_material* __cdecl DRMaterialClone(br_material *pMaterial) {
    br_material *the_material;
    char s[256];
    static int name_suffix;
    LOG_TRACE("(%p)", pMaterial);

    (void)pMaterial;
    (void)the_material;
    (void)s;
    (void)name_suffix;

    return original_DRMaterialClone(pMaterial);
}

static void(__cdecl*original_StripCR)(char *) = (void(__cdecl*)(char *))0x004c331e;
CARM95_HOOK_FUNCTION(original_StripCR, StripCR)
void __cdecl StripCR(char *s) {
    char *pos;
    LOG_TRACE("(\"%s\")", s);

    (void)s;
    (void)pos;

    original_StripCR(s);
}

void(__cdecl*SubsStringJob)(char *) = (void(__cdecl*)(char *))0x004c336e;
void SubsStringJob_do_not_use(char *pStr) {
    char *sub_str;
    char temp_str[256];
    char *sub_pt;
    va_list ap;
    LOG_TRACE("(\"%s\")", pStr);

    (void)pStr;
    (void)sub_str;
    (void)temp_str;
    (void)sub_pt;
    (void)ap;

    NOT_IMPLEMENTED();
}

static void(__cdecl*original_DecodeLine2)(char *) = (void(__cdecl*)(char *))0x004c3468;
CARM95_HOOK_FUNCTION(original_DecodeLine2, DecodeLine2)
void __cdecl DecodeLine2(char *pS) {
    int len;
    int seed;
    int i;
    unsigned char c;
    char *key;
    LOG_TRACE("(\"%s\")", pS);

    (void)pS;
    (void)len;
    (void)seed;
    (void)i;
    (void)c;
    (void)key;

    original_DecodeLine2(pS);
}

static void(__cdecl*original_EncodeLine2)(char *) = (void(__cdecl*)(char *))0x004c368f;
CARM95_HOOK_FUNCTION(original_EncodeLine2, EncodeLine2)
void __cdecl EncodeLine2(char *pS) {
    int len;
    int seed;
    int i;
    int count;
    unsigned char c;
    char *key;
    LOG_TRACE("(\"%s\")", pS);

    (void)pS;
    (void)len;
    (void)seed;
    (void)i;
    (void)count;
    (void)c;
    (void)key;

    original_EncodeLine2(pS);
}

static void(__cdecl*original_EncodeFile)(char *) = (void(__cdecl*)(char *))0x004c37f5;
CARM95_HOOK_FUNCTION(original_EncodeFile, EncodeFile)
void __cdecl EncodeFile(char *pThe_path) {
    FILE *f;
    FILE *d;
    char line[257];
    char new_file[256];
    char *s;
    char *result;
    int ch;
    int decode;
    int len;
    int count;
    LOG_TRACE("(\"%s\")", pThe_path);

    (void)pThe_path;
    (void)f;
    (void)d;
    (void)line;
    (void)new_file;
    (void)s;
    (void)result;
    (void)ch;
    (void)decode;
    (void)len;
    (void)count;

    original_EncodeFile(pThe_path);
}

static void(__cdecl*original_EncodeFileWrapper)(char *) = (void(__cdecl*)(char *))0x004c3b44;
CARM95_HOOK_FUNCTION(original_EncodeFileWrapper, EncodeFileWrapper)
void __cdecl EncodeFileWrapper(char *pThe_path) {
    int len;
    LOG_TRACE("(\"%s\")", pThe_path);

    (void)pThe_path;
    (void)len;

    original_EncodeFileWrapper(pThe_path);
}

static void(__cdecl*original_EncodeAllFilesInDirectory)(char *) = (void(__cdecl*)(char *))0x004c3cf5;
CARM95_HOOK_FUNCTION(original_EncodeAllFilesInDirectory, EncodeAllFilesInDirectory)
void __cdecl EncodeAllFilesInDirectory(char *pThe_path) {
    char s[256];
    LOG_TRACE("(\"%s\")", pThe_path);

    (void)pThe_path;
    (void)s;

    original_EncodeAllFilesInDirectory(pThe_path);
}

static void(__cdecl*original_SkipNLines)(FILE *) = (void(__cdecl*)(FILE *))0x004c3d32;
CARM95_HOOK_FUNCTION(original_SkipNLines, SkipNLines)
void __cdecl SkipNLines(FILE *pF) {
    int i;
    int count;
    char s[256];
    LOG_TRACE("(%p)", pF);

    (void)pF;
    (void)i;
    (void)count;
    (void)s;

    original_SkipNLines(pF);
}

static int(__cdecl*original_DRStricmp)(char *, char *) = (int(__cdecl*)(char *, char *))0x004c3d94;
CARM95_HOOK_FUNCTION(original_DRStricmp, DRStricmp)
int __cdecl DRStricmp(char *p1, char *p2) {
    int val;
    LOG_TRACE("(\"%s\", \"%s\")", p1, p2);

    (void)p1;
    (void)p2;
    (void)val;

    return original_DRStricmp(p1, p2);
}

void GlorifyMaterial(br_material **pArray, int pCount) {
    int i;
    int c;
    br_pixelmap *big_tile;
    tException_list e;
    LOG_TRACE("(%p, %d)", pArray, pCount);

    (void)pArray;
    (void)pCount;
    (void)i;
    (void)c;
    (void)big_tile;
    (void)e;

    NOT_IMPLEMENTED();
}

void WhitenVertexRGB(br_model **pArray, int pN) {
    int m;
    int v;
    br_vertex *vertex;
    LOG_TRACE("(%p, %d)", pArray, pN);

    (void)pArray;
    (void)pN;
    (void)m;
    (void)v;
    (void)vertex;

    NOT_IMPLEMENTED();
}

void NobbleNonzeroBlacks(br_pixelmap *pPalette) {
    tU32 red;
    tU32 green;
    tU32 blue;
    tU32 value;
    tU32 *palette_entry;
    tU32 frobbed;
    LOG_TRACE("(%p)", pPalette);

    (void)pPalette;
    (void)red;
    (void)green;
    (void)blue;
    (void)value;
    (void)palette_entry;
    (void)frobbed;

    NOT_IMPLEMENTED();
}

static int(__cdecl*original_PDCheckDriveExists)(char *) = (int(__cdecl*)(char *))0x004c3e0c;
CARM95_HOOK_FUNCTION(original_PDCheckDriveExists, PDCheckDriveExists)
int __cdecl PDCheckDriveExists(char *pThe_path) {
    LOG_TRACE("(\"%s\")", pThe_path);

    (void)pThe_path;

    return original_PDCheckDriveExists(pThe_path);
}

static int(__cdecl*original_OpacityInPrims)(br_token_value *) = (int(__cdecl*)(br_token_value *))0x004c3e79;
CARM95_HOOK_FUNCTION(original_OpacityInPrims, OpacityInPrims)
int __cdecl OpacityInPrims(br_token_value *pPrims) {
    LOG_TRACE("(%p)", pPrims);

    (void)pPrims;

    return original_OpacityInPrims(pPrims);
}

static int(__cdecl*original_AlreadyBlended)(br_material *) = (int(__cdecl*)(br_material *))0x004c3e2c;
CARM95_HOOK_FUNCTION(original_AlreadyBlended, AlreadyBlended)
int __cdecl AlreadyBlended(br_material *pMaterial) {
    LOG_TRACE("(%p)", pMaterial);

    (void)pMaterial;

    return original_AlreadyBlended(pMaterial);
}

static void(__cdecl*original_BlendifyMaterialTablishly)(br_material *, int) = (void(__cdecl*)(br_material *, int))0x004c3f0d;
CARM95_HOOK_FUNCTION(original_BlendifyMaterialTablishly, BlendifyMaterialTablishly)
void __cdecl BlendifyMaterialTablishly(br_material *pMaterial, int pPercent) {
    char *s;
    LOG_TRACE("(%p, %d)", pMaterial, pPercent);

    (void)pMaterial;
    (void)pPercent;
    (void)s;

    original_BlendifyMaterialTablishly(pMaterial, pPercent);
}

static void(__cdecl*original_BlendifyMaterialPrimitively)(br_material *, int) = (void(__cdecl*)(br_material *, int))0x004c3fb5;
CARM95_HOOK_FUNCTION(original_BlendifyMaterialPrimitively, BlendifyMaterialPrimitively)
void __cdecl BlendifyMaterialPrimitively(br_material *pMaterial, int pPercent) {
    static br_token_value alpha25[3];
    static br_token_value alpha50[3];
    static br_token_value alpha75[3];
    LOG_TRACE("(%p, %d)", pMaterial, pPercent);

    (void)pMaterial;
    (void)pPercent;
    (void)alpha25;
    (void)alpha50;
    (void)alpha75;

    original_BlendifyMaterialPrimitively(pMaterial, pPercent);
}

static void(__cdecl*original_BlendifyMaterial)(br_material *, int) = (void(__cdecl*)(br_material *, int))0x004c3eca;
CARM95_HOOK_FUNCTION(original_BlendifyMaterial, BlendifyMaterial)
void __cdecl BlendifyMaterial(br_material *pMaterial, int pPercent) {
    LOG_TRACE("(%p, %d)", pMaterial, pPercent);

    (void)pMaterial;
    (void)pPercent;

    original_BlendifyMaterial(pMaterial, pPercent);
}

