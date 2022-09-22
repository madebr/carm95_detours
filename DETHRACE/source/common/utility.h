#ifndef _UTILITY_H_
#define _UTILITY_H_

#include "br_types.h"
#include "dr_types.h"

extern int * hookvar_gIn_check_quit ; // addr: 00521488
extern tU32 * hookvar_gLost_time ; // addr: 0052148C
extern tU32(* hookvar_gLong_key )[4]; // addr: 00521490
extern tU32(* hookvar_gOther_long_key )[4]; // addr: 005214A0
// extern int * hookvar_gEncryption_method ;
extern char *(* hookvar_gMisc_strings )[250]; // addr: 00544EF0
// extern br_pixelmap ** hookvar_g16bit_palette ;
// extern br_pixelmap ** hookvar_gSource_for_16bit_palette ;

int __cdecl CheckQuit();

double __cdecl sqr(double pN);

void __cdecl EncodeLine(char *pS);

int __cdecl IRandomBetween(int pA, int pB);

int __cdecl PercentageChance(int pC);

int __cdecl IRandomPosNeg(int pN);

float __cdecl FRandomBetween(float pA, float pB);

float __cdecl FRandomPosNeg(float pN);

br_scalar __cdecl SRandomBetween(br_scalar pA, br_scalar pB);

br_scalar __cdecl SRandomPosNeg(br_scalar pN);

char* __cdecl GetALineWithNoPossibleService(FILE *pF, unsigned char *pS);

char* __cdecl GetALineAndDontArgue(FILE *pF, char *pS);

void __cdecl PathCat(char *pDestn_str, char *pStr_1, char *pStr_2);

int __cdecl Chance(float pChance_per_second, int pPeriod);

float __cdecl tandeg(float pAngle);

tU32 __cdecl GetFileLength(FILE *pF);

int __cdecl BooleanTo1Or0(int pB);

br_pixelmap* __cdecl DRPixelmapAllocate(br_uint_8 pType, br_uint_16 pW, br_uint_16 pH, void *pPixels, int pFlags);

br_pixelmap* __cdecl DRPixelmapAllocateSub(br_pixelmap *pPm, br_uint_16 pX, br_uint_16 pY, br_uint_16 pW, br_uint_16 pH);

br_pixelmap* DRPixelmapMatchSized(br_pixelmap *pSrc, tU8 pMatch_type, tS32 pWidth, tS32 pHeight);

void CopyDoubled8BitTo16BitRectangle(br_pixelmap *pDst, br_pixelmap *pSrc, int pSrc_width, int pSrc_height, int pDst_x, int pDst_y, br_pixelmap *pPalette);

br_pixelmap* Scale8BitPixelmap(br_pixelmap *pSrc, int pWidth, int pHeight);

br_pixelmap* Tile8BitPixelmap(br_pixelmap *pSrc, int pN);

tException_list FindExceptionInList(char *pName, tException_list pList);

br_pixelmap* PurifiedPixelmap(br_pixelmap *pSrc);

br_pixelmap* __cdecl DRPixelmapLoad(char *pFile_name);

br_uint_32 __cdecl DRPixelmapLoadMany(char *pFile_name, br_pixelmap **pPixelmaps, br_uint_16 pNum);

void __cdecl WaitFor(tU32 pDelay);

br_uint_32 __cdecl DRActorEnumRecurse(br_actor *pActor, br_actor_enum_cbfn *callback, void *arg);

br_uint_32 __cdecl CompareActorID(br_actor *pActor, void *pArg);

br_actor* __cdecl DRActorFindRecurse(br_actor *pSearch_root, char *pName);

br_uint_32 __cdecl DRActorEnumRecurseWithMat(br_actor *pActor, br_material *pMat, br_uint_32(**pCall_back)(br_actor *, br_material *, void *), void *pArg);

br_uint_32 __cdecl DRActorEnumRecurseWithTrans(br_actor *pActor, br_matrix34 *pMatrix, br_uint_32(**pCall_back)(br_actor *, br_matrix34 *, void *), void *pArg);

int __cdecl sign(int pNumber);

float __cdecl fsign(float pNumber);

FILE* __cdecl OpenUniqueFileB(char *pPrefix, char *pExtension);

void __cdecl PrintScreenFile(FILE *pF);

void PrintScreenFile16(FILE *pF);

void __cdecl PrintScreen();

tU32 __cdecl GetTotalTime();

tU32 __cdecl GetRaceTime();

void __cdecl AddLostTime(tU32 pLost_time);

void __cdecl TimerString(tU32 pTime, char *pStr, int pFudge_colon, int pForce_colon);

char* __cdecl GetMiscString(int pIndex);

void __cdecl GetCopyOfMiscString(int pIndex, char *pStr);

int __cdecl Flash(tU32 pPeriod, tU32 *pLast_change, int *pCurrent_state);

void __cdecl MaterialCopy(br_material *pDst, br_material *pSrc);

double __cdecl RGBDifferenceSqr(tRGB_colour *pColour_1, tRGB_colour *pColour_2);

int __cdecl FindBestMatch(tRGB_colour *pRGB_colour, br_pixelmap *pPalette);

void __cdecl BuildShadeTablePath(char *pThe_path, int pR, int pG, int pB);

br_pixelmap* __cdecl LoadGeneratedShadeTable(int pR, int pG, int pB);

void __cdecl SaveGeneratedShadeTable(br_pixelmap *pThe_table, int pR, int pG, int pB);

br_pixelmap* __cdecl GenerateShadeTable(int pHeight, br_pixelmap *pPalette, int pRed_mix, int pGreen_mix, int pBlue_mix, float pQuarter, float pHalf, float pThree_quarter);

br_pixelmap* __cdecl GenerateDarkenedShadeTable(int pHeight, br_pixelmap *pPalette, int pRed_mix, int pGreen_mix, int pBlue_mix, float pQuarter, float pHalf, float pThree_quarter, br_scalar pDarken);

void __cdecl PossibleService();

void __cdecl DRMatrix34TApplyP(br_vector3 *pA, br_vector3 *pB, br_matrix34 *pC);

tU16 PaletteEntry16Bit(br_pixelmap *pPal, int pEntry);

br_pixelmap* PaletteOf16Bits(br_pixelmap *pSrc);

void Copy8BitTo16Bit(br_pixelmap *pDst, br_pixelmap *pSrc, br_pixelmap *pPalette);

void Copy8BitTo16BitRectangle(br_pixelmap *pDst, tS16 pDst_x, tS16 pDst_y, br_pixelmap *pSrc, tS16 pSrc_x, tS16 pSrc_y, tS16 pWidth, tS16 pHeight, br_pixelmap *pPalette);

void Copy8BitTo16BitRectangleWithTransparency(br_pixelmap *pDst, tS16 pDst_x, tS16 pDst_y, br_pixelmap *pSrc, tS16 pSrc_x, tS16 pSrc_y, tS16 pWidth, tS16 pHeight, br_pixelmap *pPalette);

void Copy8BitToOnscreen16BitRectangleWithTransparency(br_pixelmap *pDst, tS16 pDst_x, tS16 pDst_y, br_pixelmap *pSrc, tS16 pSrc_x, tS16 pSrc_y, tS16 pWidth, tS16 pHeight, br_pixelmap *pPalette);

void Copy8BitRectangleTo16BitRhombusWithTransparency(br_pixelmap *pDst, tS16 pDst_x, tS16 pDst_y, br_pixelmap *pSrc, tS16 pSrc_x, tS16 pSrc_y, tS16 pWidth, tS16 pHeight, tX1616 pShear, br_pixelmap *pPalette);

void __cdecl DRPixelmapRectangleCopy(br_pixelmap *dst, br_int_16 dx, br_int_16 dy, br_pixelmap *src, br_int_16 sx, br_int_16 sy, br_uint_16 w, br_uint_16 h);

void DRPixelmapCopy(br_pixelmap *dst, br_pixelmap *src);

void __cdecl DRPixelmapRectangleFill(br_pixelmap *dst, br_int_16 x, br_int_16 y, br_uint_16 w, br_uint_16 h, br_uint_32 colour);

int __cdecl NormalSideOfPlane(br_vector3 *pPoint, br_vector3 *pNormal, br_scalar pD);

br_material* __cdecl DRMaterialClone(br_material *pMaterial);

void __cdecl StripCR(char *s);

extern void(__cdecl*SubsStringJob)(char *);
#if 0
void SubsStringJob_do_not_use(char *pStr);
#endif

void __cdecl DecodeLine2(char *pS);

void __cdecl EncodeLine2(char *pS);

void __cdecl EncodeFile(char *pThe_path);

void __cdecl EncodeFileWrapper(char *pThe_path);

void __cdecl EncodeAllFilesInDirectory(char *pThe_path);

void __cdecl SkipNLines(FILE *pF);

int __cdecl DRStricmp(char *p1, char *p2);

void GlorifyMaterial(br_material **pArray, int pCount);

void WhitenVertexRGB(br_model **pArray, int pN);

void NobbleNonzeroBlacks(br_pixelmap *pPalette);

int __cdecl PDCheckDriveExists(char *pThe_path);

int __cdecl OpacityInPrims(br_token_value *pPrims);

int __cdecl AlreadyBlended(br_material *pMaterial);

void __cdecl BlendifyMaterialTablishly(br_material *pMaterial, int pPercent);

void __cdecl BlendifyMaterialPrimitively(br_material *pMaterial, int pPercent);

void __cdecl BlendifyMaterial(br_material *pMaterial, int pPercent);

#endif
