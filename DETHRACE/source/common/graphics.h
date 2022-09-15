#ifndef _GRAPHICS_H_
#define _GRAPHICS_H_

#include "br_types.h"
#include "dr_types.h"

extern int * hookvar_gPalette_munged ; // addr: 00520040
// extern int(* hookvar_gColourValues )[1];
extern int * hookvar_gNext_transient ; // addr: 00520048
extern int(* hookvar_gCursor_x_offsets )[8]; // addr: 00520050
extern int(* hookvar_gCursor_y_offsets )[8]; // addr: 00520070
extern int(* hookvar_gCursor_gib_x_offsets )[8]; // addr: 00520090
extern int(* hookvar_gCursor_gib_y_offsets )[8]; // addr: 005200B0
extern int(* hookvar_gCursor_giblet_sequence0 )[7]; // addr: 005200D0
extern int(* hookvar_gCursor_giblet_sequence1 )[5]; // addr: 005200F0
extern int(* hookvar_gCursor_giblet_sequence2 )[5]; // addr: 00520108
extern int(* hookvar_gCursor_giblet_sequence3 )[5]; // addr: 00520120
extern int *(* hookvar_gCursor_giblet_sequences )[4]; // addr: 00520138
extern char *(* hookvar_gFont_names )[21]; // addr: 00520148
extern br_colour(* hookvar_gRGB_colours )[9]; // addr: 005201A0
extern br_matrix34 * hookvar_gSheer_mat ; // addr: 005201C8
// extern br_matrix34 * hookvar_gIdentity34 ;
extern tShadow_level * hookvar_gShadow_level ; // addr: 00520228
// extern br_scalar * hookvar_gShadow_hither_z_move ;
// extern br_scalar * hookvar_gShadow_hither_min_move ;
extern int(* hookvar_gArrows )[2][4][60]; // addr: 00520238
extern float * hookvar_gMap_render_x ; // addr: 005209B8
extern float * hookvar_gMap_render_y ; // addr: 005209BC
extern float * hookvar_gMap_render_width ; // addr: 005209C0
extern float * hookvar_gMap_render_height ; // addr: 005209C4
extern int * hookvar_gMouse_started ; // addr: 005209C8
extern int * hookvar_gFaded_palette ; // addr: 005209CC
extern int * hookvar_gAR_fudge_headups ; // addr: 005209D0
extern br_pixelmap ** hookvar_gCurrent_splash ; // addr: 005209D4
extern br_pixelmap ** hookvar_gCurrent_conversion_table ; // addr: 005209D8
extern int(* hookvar_gMap_colours )[4]; // addr: 005209E0
extern br_vector3(* hookvar_gShadow_points )[8]; // addr: 0053E798
extern tConcussion * hookvar_gConcussion ; // addr: 0053F940
extern tClip_details(* hookvar_gShadow_clip_planes )[8]; // addr: 0053F080
extern br_actor *(* hookvar_gLollipops )[100]; // addr: 0053E5F8
extern tWobble_spec(* hookvar_gWobble_array )[5]; // addr: 0053F8D8
extern tSaved_table(* hookvar_gSaved_shade_tables )[100]; // addr: 0053F0C0
extern tCursor_giblet(* hookvar_gCursor_giblets )[45]; // addr: 0053E808
extern tTransient_bm(* hookvar_gTransient_bitmaps )[50]; // addr: 0053F3F0
extern float(* hookvar_gCosine_array )[64]; // addr: 0054FF30
extern br_pixelmap *(* hookvar_gCursors )[8]; // addr: 0054B300
extern br_pixelmap *(* hookvar_gCursor_giblet_images )[18]; // addr: 00550040
extern br_pixelmap ** hookvar_gEval_1 ; // addr: 0053E790
// extern br_pixelmap ** hookvar_gEval_2 ;
extern br_vector3 * hookvar_gShadow_light_z ; // addr: 0053F8B8
extern br_vector3 * hookvar_gShadow_light_x ; // addr: 0053F8A8
// extern int * hookvar_gShadow_dim_amount ;
extern int * hookvar_gNumber_of_lollipops ; // addr: 0053F8A0
extern br_vector3 * hookvar_gShadow_light_ray ; // addr: 0053F8C8
extern int * hookvar_gFancy_shadow ; // addr: 0053E788
extern br_model ** hookvar_gShadow_model ; // addr: 0053F93C
extern br_actor ** hookvar_gShadow_actor ; // addr: 0053E7FC
extern int * hookvar_gShadow_clip_plane_count ; // addr: 0053F928
extern br_pixelmap ** hookvar_gPalette_conversion_table ; // addr: 0053E800
extern br_material ** hookvar_gShadow_material ; // addr: 0053F92C
extern int * hookvar_gSaved_table_count ; // addr: 0053F3E8
extern int * hookvar_gCurrent_cursor_index ; // addr: 0053F3E0
// extern int * hookvar_gPalette_index ;
extern int * hookvar_gCursor_transient_index ; // addr: 0053F3E4
extern char ** hookvar_gScratch_pixels ; // addr: 0053F934
extern br_pixelmap ** hookvar_gScratch_palette ; // addr: 0053F078
// extern int * hookvar_gLast_palette_change ;
extern br_pixelmap ** hookvar_gOrig_render_palette ; // addr: 0053F8A4
extern br_pixelmap ** hookvar_gCurrent_palette ; // addr: 00550030
extern br_pixelmap ** hookvar_gRender_palette ; // addr: 0054FEFC
extern float * hookvar_gCamera_to_horiz_angle ; // addr: 0054FF08
extern int(* hookvar_gColours )[9]; // addr: 0054B2D0
extern br_pixelmap ** hookvar_gFlic_palette ; // addr: 00550088
extern tDR_font(* hookvar_gFonts )[21]; // addr: 0054B330
extern char ** hookvar_gCurrent_palette_pixels ; // addr: 00550094
extern int * hookvar_gWidth ; // addr: 0054B320
extern int * hookvar_gMap_render_height_i ; // addr: 0054FF18
extern int * hookvar_gScreen_wobble_x ; // addr: 00550038
extern int * hookvar_gScreen_wobble_y ; // addr: 00550034
extern br_scalar * hookvar_gCurrent_ambience ; // addr: 0054FF0C
extern int * hookvar_gY_offset ; // addr: 0054B2CC
extern int * hookvar_gMap_render_width_i ; // addr: 0055008C
extern int * hookvar_gMouse_in_use ; // addr: 00550090
extern int * hookvar_gHeight ; // addr: 0054B2F8
extern int * hookvar_gMouse_last_y_coord ; // addr: 0054FF00
extern int * hookvar_gMouse_last_x_coord ; // addr: 0054B2F4
extern br_scalar * hookvar_gAmbient_adjustment ; // addr: 0054FF20
extern int * hookvar_gMap_render_x_i ; // addr: 0054FF14
extern int * hookvar_gX_offset ; // addr: 0054FF24
extern int * hookvar_gMap_render_y_i ; // addr: 0054FF10
extern int * hookvar_gMirror_on__graphics ; // addr: 0054FF04 // suffix added to avoid duplicate symbol
extern br_scalar * hookvar_gYon_squared ; // addr: 0054FF1C

void TurnOnPaletteConversion();

void TurnOffPaletteConversion();

void ResetLollipopQueue();

int AddToLollipopQueue(br_actor *pActor, int pIndex);

void RenderLollipops();

void DRDrawLine(br_pixelmap *pDestn, int pX1, int pY1, int pX2, int pY2, int pColour);

void DrawDigitAt(br_pixelmap *gImage, int pX, int pY, int pY_pitch, int pValue);

void DrawNumberAt(br_pixelmap *gImage, int pX, int pY, int pX_pitch, int pY_pitch, int pValue, int pDigit_count, int pLeading_zeroes);

void BuildColourTable(br_pixelmap *pPalette);

void ClearConcussion();

tS8* SkipLines(tS8 *pSource, int pCount);

void CopyWords(char *pDst, char *pSrc, int pN);

void Copy8BitStripImageTo16Bit(br_pixelmap *pDest, br_int_16 pDest_x, br_int_16 pOffset_x, br_int_16 pDest_y, br_int_16 pOffset_y, tS8 *pSource, br_int_16 pSource_x, br_int_16 pSource_y, br_uint_16 pWidth, br_uint_16 pHeight);

void CopyStripImage(br_pixelmap *pDest, br_int_16 pDest_x, br_int_16 pOffset_x, br_int_16 pDest_y, br_int_16 pOffset_y, tS8 *pSource, br_int_16 pSource_x, br_int_16 pSource_y, br_uint_16 pWidth, br_uint_16 pHeight);

void SetBRenderScreenAndBuffers(int pX_offset, int pY_offset, int pWidth, int pHeight);

void SetIntegerMapRenders();

void AdjustRenderScreenSize();

void ScreenSmaller();

void ScreenLarger();

void DRSetPaletteEntries(br_pixelmap *pPalette, int pFirst_colour, int pCount);

void DRSetPalette3(br_pixelmap *pThe_palette, int pSet_current_palette);

void DRSetPalette2(br_pixelmap *pThe_palette, int pSet_current_palette);

void DRSetPalette(br_pixelmap *pThe_palette);

void InitializePalettes();

void SwitchToPalette(char *pPal_name);

void ClearEntireScreen();

void ClearWobbles();

void InitWobbleStuff();

void NewScreenWobble(double pAmplitude_x, double pAmplitude_y, double pPeriod);

void SetScreenWobble(int pWobble_x, int pWobble_y);

void ResetScreenWobble();

void CalculateWobblitude(tU32 pThe_time);

void CalculateConcussion(tU32 pThe_time);

void SufferFromConcussion(float pSeriousness);

void ProcessNonTrackActors(br_pixelmap *pRender_buffer, br_pixelmap *pDepth_buffer, br_actor *pCamera, br_matrix34 *pCamera_to_world, br_matrix34 *pOld_camera_matrix);

int OppositeColour(int pColour);

void DrawMapBlip(tCar_spec *pCar, tU32 pTime, br_matrix34 *pTrans, br_vector3 *pPos, int pColour);

void DrawMapSmallBlip(tU32 pTime, br_vector3 *pPos, int pColour);

void MungeClipPlane(br_vector3 *pLight, tCar_spec *pCar, br_vector3 *p1, br_vector3 *p2, br_scalar pY_offset);

void TryThisEdge(tCar_spec *pCar, br_vector3 *pLight, int pIndex_1, br_scalar pSign_1, int pIndex_2, br_scalar pSign_2, int pPoint_index_1, int pPoint_index_2, br_scalar pY_offset);

br_scalar DistanceFromPlane(br_vector3 *pPos, br_scalar pA, br_scalar pB, br_scalar pC, br_scalar pD);

void DisableLights();

void EnableLights();

void ProcessShadow(tCar_spec *pCar, br_actor *pWorld, tTrack_spec *pTrack_spec, br_actor *pCamera, br_matrix34 *pCamera_to_world_transform, br_scalar pDistance_factor);

void RenderShadows(br_actor *pWorld, tTrack_spec *pTrack_spec, br_actor *pCamera, br_matrix34 *pCamera_to_world_transform);

void FlashyMapCheckpoint(int pIndex, tU32 pTime);

int ConditionallyFillWithSky(br_pixelmap *pPixelmap);

void RenderAFrame(int pDepth_mask_on);

void InitPaletteAnimate();

void RevertPalette();

void MungePalette();

void ResetPalette();

void Darken(tU8 *pPtr, unsigned int pDarken_amount);

void SetFadedPalette(int pDegree);

void FadePaletteDown();

void FadePaletteUp();

void KillSplashScreen();

void EnsureRenderPalette();

void SplashScreenWith(char *pPixmap_name);

void EnsurePaletteUp();

br_uint_32 AmbientificateMaterial(br_material *pMat, void *pArg);

void ChangeAmbience(br_scalar pDelta);

void InitAmbience();

void DRPixelmapRectangleMaskedCopy(br_pixelmap *pDest, br_int_16 pDest_x, br_int_16 pDest_y, br_pixelmap *pSource, br_int_16 pSource_x, br_int_16 pSource_y, br_int_16 pWidth, br_int_16 pHeight);

void DRMaskedStamp(br_int_16 pDest_x, br_int_16 pDest_y, br_pixelmap *pSource);

void DRPixelmapRectangleOnscreenCopy(br_pixelmap *pDest, br_int_16 pDest_x, br_int_16 pDest_y, br_pixelmap *pSource, br_int_16 pSource_x, br_int_16 pSource_y, br_int_16 pWidth, br_int_16 pHeight);

void DRPixelmapRectangleShearedCopy(br_pixelmap *pDest, br_int_16 pDest_x, br_int_16 pDest_y, br_pixelmap *pSource, br_int_16 pSource_x, br_int_16 pSource_y, br_int_16 pWidth, br_int_16 pHeight, tX1616 pShear);

void DRPixelmapRectangleVScaledCopy(br_pixelmap *pDest, br_int_16 pDest_x, br_int_16 pDest_y, br_pixelmap *pSource, br_int_16 pSource_x, br_int_16 pSource_y, br_int_16 pWidth, br_int_16 pHeight);

void InitTransientBitmaps();

int AllocateTransientBitmap(int pWidth, int pHeight, int pUser_data);

void DeallocateTransientBitmap(int pIndex);

void DeallocateAllTransientBitmaps();

void RemoveTransientBitmaps(int pGraphically_remove_them);

void SaveTransient(int pIndex, int pX_coord, int pY_coord);

void DrawCursorGiblet(tCursor_giblet *pGib);

void ProcessCursorGiblets(int pPeriod);

int NewCursorGiblet(int pX_coord, int pY_coord, float pX_speed, float pY_speed, tU32 pDrop_time);

int DoMouseCursor();

int AllocateCursorTransient();

void StartMouseCursor();

void EndMouseCursor();

void LoadFont(int pFont_ID);

void DisposeFont(int pFont_ID);

void InitDRFonts();

void DrawDropImage(br_pixelmap *pImage, int pLeft, int pTop, int pTop_clip, int pBottom_clip, int pOffset);

void DropInImageFromTop(br_pixelmap *pImage, int pLeft, int pTop, int pTop_clip, int pBottom_clip);

void DropOutImageThruBottom(br_pixelmap *pImage, int pLeft, int pTop, int pTop_clip, int pBottom_clip);

void DropInImageFromBottom(br_pixelmap *pImage, int pLeft, int pTop, int pTop_clip, int pBottom_clip);

void DropOutImageThruTop(br_pixelmap *pImage, int pLeft, int pTop, int pTop_clip, int pBottom_clip);

void DrawTellyLine(br_pixelmap *pImage, int pLeft, int pTop, int pPercentage);

void DrawTellyImage(br_pixelmap *pImage, int pLeft, int pTop, int pPercentage);

void TellyInImage(br_pixelmap *pImage, int pLeft, int pTop);

void TellyOutImage(br_pixelmap *pImage, int pLeft, int pTop);

void SetShadowLevel(tShadow_level pLevel);

tShadow_level GetShadowLevel();

void ToggleShadow();

void InitShadow();

br_uint_32 SaveShadeTable(br_pixelmap *pTable, void *pArg);

void SaveShadeTables();

void DisposeSavedShadeTables();

void ShadowMode();

int SwitchToRealResolution();

int SwitchToLoresMode();

void DRPixelmapDoubledCopy(br_pixelmap *pDestn, br_pixelmap *pSource, int pSource_width, int pSource_height, int pX_offset, int pY_offset);

#endif
