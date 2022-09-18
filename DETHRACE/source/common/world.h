#ifndef _WORLD_H_
#define _WORLD_H_

#include "br_types.h"
#include "dr_types.h"

extern int * hookvar_gFunkotronics_array_size ; // addr: 0050C710
extern int * hookvar_gGroovidelics_array_size ; // addr: 0050C714
extern int * hookvar_gSpec_vol_mode ; // addr: 0050C718
extern tFunkotronic_spec ** hookvar_gFunkotronics_array ; // addr: 0050C71C
extern tGroovidelic_spec ** hookvar_gGroovidelics_array ; // addr: 0050C720
extern char *(* hookvar_gFunk_type_names )[5]; // addr: 0050C728
extern char *(* hookvar_gFunk_anim_names )[2]; // addr: 0050C740
extern char *(* hookvar_gTime_mode_names )[2]; // addr: 0050C748
extern char *(* hookvar_gFunk_move_names )[6]; // addr: 0050C750
extern char *(* hookvar_gFunk_nature_names )[4]; // addr: 0050C768
extern char *(* hookvar_gGroove_nature_names )[2]; // addr: 0050C778
extern char *(* hookvar_gAxis_names )[3]; // addr: 0050C780
extern char *(* hookvar_gLollipop_names )[3]; // addr: 0050C790
extern char *(* hookvar_gGroove_path_names )[2]; // addr: 0050C7A0
extern char *(* hookvar_gGroove_object_names )[4]; // addr: 0050C7A8
extern char *(* hookvar_gDepth_effect_names )[2]; // addr: 0050C7B8
// extern br_actor ** hookvar_gGroove_by_proxy_actor ;
extern tRotate_mode * hookvar_gCurrent_rotate_mode ; // addr: 0050C7C4
extern tScale_mode * hookvar_gCurrent_scale_mode ; // addr: 0050C7C8
extern int * hookvar_gNumber_of_additional_models ; // addr: 0050C7CC
extern tRoad_texturing_level * hookvar_gRoad_texturing_level ; // addr: 0050C7D0
extern tWall_texturing_level * hookvar_gWall_texturing_level ; // addr: 0050C7D4
extern tCar_texturing_level * hookvar_gCar_texturing_level ; // addr: 0050C7D8
extern int * hookvar_gRendering_accessories ; // addr: 0050C7DC
extern int * hookvar_gNumber_of_actors ; // addr: 0050C7E0
extern int * hookvar_gNumber_of_lights ; // addr: 0050C7E4
extern br_actor *(* hookvar_gActor_array )[500]; // addr: 005514E0
extern float *(* hookvar_gGroove_funk_bindings )[960]; // addr: 00532AF0
extern br_actor *(* hookvar_gDelete_list )[500]; // addr: 00532220
extern br_actor *(* hookvar_gLight_array )[50]; // addr: 00551CB0
extern br_model *(* hookvar_gAdditional_models )[1000]; // addr: 00533B18
extern br_actor *(* hookvar_gSpec_vol_actors )[100]; // addr: 00534AC0
extern tPath_name * hookvar_gAdditional_actor_path ; // addr: 00533A00
extern tPath_name * hookvar_gAdditional_model_path ; // addr: 005329F0
extern tU32(* hookvar_gPrevious_groove_times )[2]; // addr: 00533B00
extern int * hookvar_gRace_file_version ; // addr: 00551D78
extern br_vector3 * hookvar_gActor_centre ; // addr: 005339F0
// extern float * hookvar_gTemp ;
extern br_actor ** hookvar_gLast_actor ; // addr: 00533B0C
extern br_actor ** hookvar_gKnown_actor ; // addr: 00533B08
extern br_actor ** hookvar_gAdditional_actors ; // addr: 00534AB8
extern int * hookvar_gDelete_count ; // addr: 00533B10
extern br_scalar * hookvar_gNearest_distance ; // addr: 005339FC
extern br_actor ** hookvar_gNearest_actor ; // addr: 00534C50
// extern br_actor ** hookvar_gStandard_lamp ;
extern br_scalar * hookvar_gSight_distance_squared ; // addr: 00534ABC

float __cdecl MapSawToTriangle(float pNumber);

void __cdecl SetSightDistance(br_scalar pYon);

br_actor* __cdecl FindActorInArray(char *pThe_name);

br_actor* __cdecl FindLightInArray(char *pThe_name);

br_actor* __cdecl CloneActor(br_actor *pSource_actor);

void __cdecl InitialiseStorageSpace(tBrender_storage *pStorage_space, int pMax_pixelmaps, int pMax_shade_tables, int pMax_materials, int pMax_models);

void __cdecl DisposeStorageSpace(tBrender_storage *pStorage_space);

void __cdecl ClearOutStorageSpace(tBrender_storage *pStorage_space);

tAdd_to_storage_result __cdecl AddPixelmapToStorage(tBrender_storage *pStorage_space, br_pixelmap **pThe_pm);

tAdd_to_storage_result __cdecl AddShadeTableToStorage(tBrender_storage *pStorage_space, br_pixelmap *pThe_st);

tAdd_to_storage_result __cdecl AddMaterialToStorage(tBrender_storage *pStorage_space, br_material *pThe_mat);

tAdd_to_storage_result __cdecl AddModelToStorage(tBrender_storage *pStorage_space, br_model *pThe_mod);

int __cdecl LoadNPixelmaps(tBrender_storage *pStorage_space, FILE *pF, int pCount);

br_pixelmap* __cdecl LoadSinglePixelmap(tBrender_storage *pStorage_space, char *pName);

br_material* __cdecl LoadSingleMaterial(tBrender_storage *pStorage_space, char *pName);

int __cdecl LoadNShadeTables(tBrender_storage *pStorage_space, FILE *pF, int pCount);

br_pixelmap* __cdecl LoadSingleShadeTable(tBrender_storage *pStorage_space, char *pName);

int __cdecl LoadNMaterials(tBrender_storage *pStorage_space, FILE *pF, int pCount);

int __cdecl LoadNModels(tBrender_storage *pStorage_space, FILE *pF, int pCount);

void __cdecl DodgyModelUpdate(br_model *pM);

br_material* __cdecl SuffixedMaterial(br_material *pOld, char *pSuffix);

int __cdecl FaceIsRoad(br_model *pModel, tU16 pFace);

br_material* __cdecl RoadPerspToUntex(br_model *pModel, tU16 pFace);

br_material* __cdecl WallPerspToLinear(br_model *pModel, tU16 pFace);

br_material* __cdecl WallPerspToUntex(br_model *pModel, tU16 pFace);

void ProcessModelFaceMaterials2(br_model *pModel, tPMFM2CB pCallback);

void __cdecl ProcessModelFaceMaterials(br_model *pModel, tPMFMCB pCallback);

int __cdecl LoadNTrackModels(tBrender_storage *pStorage_space, FILE *pF, int pCount);

void __cdecl LoadSomePixelmaps(tBrender_storage *pStorage_space, FILE *pF);

void __cdecl LoadSomeShadeTables(tBrender_storage *pStorage_space, FILE *pF);

void __cdecl LoadSomeMaterials(tBrender_storage *pStorage_space, FILE *pF);

void __cdecl LoadSomeModels(tBrender_storage *pStorage_space, FILE *pF);

void __cdecl LoadSomeTrackModels(tBrender_storage *pStorage_space, FILE *pF);

void __cdecl AddFunkGrooveBinding(int pSlot_number, float *pPeriod_address);

void __cdecl ControlBoundFunkGroove(int pSlot_number, float pValue);

float __cdecl ControlBoundFunkGroovePlus(int pSlot_number, float pValue);

void __cdecl ShiftBoundGrooveFunks(char *pStart, char *pEnd, int pDelta);

tFunkotronic_spec* __cdecl AddNewFunkotronic();

void __cdecl DisposeFunkotronics(int pOwner);

void __cdecl AddProximityVertex(br_vector3 *pV, tFunkotronic_spec *pThe_funk);

void __cdecl AddProximityVertexXYZ(br_scalar pX, br_scalar pY, br_scalar pZ, tFunkotronic_spec *pThe_funk);

br_uint_32 __cdecl CalcProximities(br_actor *pActor, br_material *pMat, tFunkotronic_spec *pThe_funk);

br_uint_32 __cdecl AddProximities(br_actor *pActor, br_material *pMat, tFunkotronic_spec *pThe_funk);

void Adjust2FloatsForExceptions(float *pVictim1, float *pVictim2, br_pixelmap *pCulprit);

void __cdecl AddFunkotronics(FILE *pF, int pOwner, int pRef_offset);

void __cdecl DisposeGroovidelics(int pOwner);

tGroovidelic_spec* __cdecl AddNewGroovidelic();

void __cdecl AddGroovidelics(FILE *pF, int pOwner, br_actor *pParent_actor, int pRef_offset, int pAllowed_to_be_absent);

void __cdecl KillGroovadelic(int pOwner);

void __cdecl KillFunkotronic(int pOwner);

br_uint_32 __cdecl DeleteBastards(br_actor *pActor, br_matrix34 *pMatrix, void *pArg);

void __cdecl DeleteAnyZeroBastards();

br_uint_32 __cdecl ApplyTransToModels(br_actor *pActor, br_matrix34 *pMatrix, void *pArg);

int __cdecl FindSpecVolIndex(br_actor *pActor);

void __cdecl MungeMaterial(br_matrix34 *pMat, br_material *pMat_1, br_material *pMat_2, int pAxis_0, int pAxis_1);

void __cdecl SetSpecVolMatSize(br_actor *pActor);

void __cdecl FindInverseAndWorldBox(tSpecial_volume *pSpec);

void __cdecl UpdateSpecVol();

void __cdecl SaveSpecialVolumes();

void __cdecl SaveAdditionalStuff();

br_uint_32 ProcessMaterials(br_actor *pActor, tPMFM2CB pCallback);

br_uint_32 ProcessFaceMaterials2(br_actor *pActor, tPMFM2CB pCallback);

void ChangePerspToSubdivCB(br_material *pMaterial);

void ChangePerspToSubdiv();

void ChangeSubdivToPerspCB(br_material *pMaterial);

void ChangeSubdivToPersp();

br_uint_32 __cdecl ProcessFaceMaterials(br_actor *pActor, tPMFMCB pCallback);

int __cdecl DRPixelmapHasZeros(br_pixelmap *pm);

int __cdecl StorageContainsPixelmap(tBrender_storage *pStorage, br_pixelmap *pMap);

void __cdecl HideStoredOpaqueTextures(tBrender_storage *pStorage);

void __cdecl RevealStoredTransparentTextures(tBrender_storage *pStorage);

void __cdecl HideStoredTextures(tBrender_storage *pStorage);

void __cdecl RevealStoredTextures(tBrender_storage *pStorage);

void __cdecl SetCarStorageTexturingLevel(tBrender_storage *pStorage, tCar_texturing_level pNew, tCar_texturing_level pOld);

tCar_texturing_level __cdecl GetCarTexturingLevel();

void __cdecl SetCarTexturingLevel(tCar_texturing_level pLevel);

int __cdecl HasThisSuffix(char *pIdent, char *pSuffix);

br_material* __cdecl UnsuffixedMaterial(char *pOld_ident, char *pSuffix);

br_material* __cdecl RoadUntexToPersp(br_model *pModel, tU16 pFace);

br_material* __cdecl WallLinearToUntex(br_model *pModel, tU16 pFace);

br_material* __cdecl WallUntexToLinear(br_model *pModel, tU16 pFace);

br_material* __cdecl WallUntexToPersp(br_model *pModel, tU16 pFace);

br_material* __cdecl WallLinearToPersp(br_model *pModel, tU16 pFace);

tRoad_texturing_level __cdecl GetRoadTexturingLevel();

void __cdecl SetRoadTexturingLevel(tRoad_texturing_level pLevel);

void __cdecl ReallySetRoadTexturingLevel(tRoad_texturing_level pLevel);

tWall_texturing_level __cdecl GetWallTexturingLevel();

void __cdecl SetWallTexturingLevel(tWall_texturing_level pLevel);

void __cdecl ReallySetWallTexturingLevel(tWall_texturing_level pLevel);

br_material* __cdecl DisposeSuffixedMaterials(br_model *pModel, tU16 pFace);

void __cdecl DisposeTexturingMaterials();

br_uint_32 __cdecl SetAccessoryRenderingCB(br_actor *pActor, void *pFlag);

void __cdecl SetAccessoryRendering(int pOn);

int __cdecl GetAccessoryRendering();

void __cdecl SetCarSimplificationLevel(int pLevel);

int __cdecl GetCarSimplificationLevel();

void __cdecl ParseSpecialVolume(FILE *pF, tSpecial_volume *pSpec, char *pScreen_name_str);

void AddExceptionToList(tException_list *pDst, tException_list pNew);

void LoadExceptionsFile(char *pName);

void LoadExceptionsFileForTrack(char *pTrack_file_name);

void FreeExceptions();

void __cdecl LoadTrack(char *pFile_name, tTrack_spec *pTrack_spec, tRace_info *pRace_info);

br_uint_32 __cdecl RemoveBounds(br_actor *pActor, void *pArg);

void __cdecl RemoveBoundsStructures(br_actor *pActor);

void __cdecl FreeTrack(tTrack_spec *pTrack_spec);

void __cdecl ProcessTrack(br_actor *pWorld, tTrack_spec *pTrack_spec, br_actor *pCamera, br_matrix34 *pCamera_to_world_transform, int pRender_blends);

br_scalar __cdecl NormaliseDegreeAngle(br_scalar pAngle);

void __cdecl FunkThoseTronics();

void __cdecl LollipopizeActor(br_actor *pSubject_actor, br_matrix34 *ref_to_world, tLollipop_mode pWhich_axis);

void __cdecl CalcActorGlobalPos(br_vector3 *pResult, br_actor *pActor);

int __cdecl PointOutOfSight(br_vector3 *pPoint, br_scalar pMax_distance);

void __cdecl PathGrooveBastard(tGroovidelic_spec *pGroove, tU32 pTime, br_matrix34 *pMat, int pInterrupt_it);

void ObjectGrooveBastard(tGroovidelic_spec *pGroove, tU32 pTime, br_matrix34 *pMat, int pInterrupt_it);

void __cdecl GrooveThisDelic(tGroovidelic_spec *pGroove, tU32 pTime, int pInterrupt_it);

void __cdecl GrooveThoseDelics();

void __cdecl StopGroovidelic(br_actor *pActor);

void __cdecl SetGrooveInterrupt(int pGroove_index, br_matrix34 *pMatrix, int pPath_interrupt, int pObject_interrupt, float pPath_resumption, float pObject_resumption);

void __cdecl ResetGrooveFlags();

tSpecial_volume* __cdecl GetDefaultSpecialVolumeForWater();

tSpecial_volume* __cdecl FindSpecialVolume(br_vector3 *pP, tSpecial_volume *pLast_vol);

void __cdecl SaveAdditionalActors();

br_scalar __cdecl DistanceFromFace(br_vector3 *pPos, tFace_ref *pFace);

br_uint_32 __cdecl CalcHighestID(br_actor *pActor, int *pHighest);

br_uint_32 __cdecl SetID(br_actor *pActor, void *pArg);

void __cdecl UniquificateActorsName(br_actor *pUniverse_actor, br_actor *pActor);

void __cdecl AccessoryHeadup(br_actor *pActor, char *pPrefix);

br_uint_32 __cdecl CalcHighestNonAmID(br_actor *pActor, int *pHighest);

br_uint_32 __cdecl SetIDAndDupModel(br_actor *pActor, void *pArg);

void __cdecl DuplicateIfNotAmpersand(br_actor *pActor);

void __cdecl DropActor(int pIndex);

void __cdecl DropActor0();

void __cdecl DropActor1();

void __cdecl DropActor2();

void __cdecl DropActor3();

void __cdecl DropActor4();

void __cdecl DropActor5();

void __cdecl DropActor6();

void __cdecl DropActor7();

void __cdecl DropActor8();

void __cdecl DropActor9();

br_uint_32 __cdecl IdentifyAccCB(br_actor *pActor, void *pArg);

void __cdecl IdentifyAcc();

br_uint_32 __cdecl DelGrooveRef(br_actor *pActor, void *pArg);

br_uint_32 __cdecl DelReferencedModels(br_actor *pActor, void *pArg);

void __cdecl DeleteAcc();

br_uint_32 __cdecl OffsetModel(br_actor *pActor, void *pArg);

void __cdecl OffsetActor(br_actor *pActor, br_vector3 *pOffset);

void __cdecl CentreActor(br_actor *pActor, br_vector3 *pOffset);

void __cdecl SnapAccToVertical();

void __cdecl RotateAccessory(br_angle pAngle);

void __cdecl ScaleAccessory(float pScaling_factor);

void __cdecl MoveAccessory(br_scalar pX_shift, br_scalar pY_shift, br_scalar pZ_shift);

void __cdecl RotateAccL();

void __cdecl RotateAccL2();

void __cdecl RotateAccL3();

void __cdecl RotateAccL4();

void __cdecl RotateAccR();

void __cdecl RotateAccR2();

void __cdecl RotateAccR3();

void __cdecl RotateAccR4();

void __cdecl CycleAccRotate();

void __cdecl CycleAccScale();

void __cdecl ScaleAccUp2();

void __cdecl ScaleAccUp3();

void __cdecl ScaleAccUp4();

void __cdecl ScaleAccDown2();

void __cdecl ScaleAccDown3();

void __cdecl ScaleAccDown4();

void __cdecl MoveXAccL();

void __cdecl MoveXAccL2();

void __cdecl MoveXAccL3();

void __cdecl MoveXAccL4();

void __cdecl MoveXAccR();

void __cdecl MoveXAccR2();

void __cdecl MoveXAccR3();

void __cdecl MoveXAccR4();

void __cdecl MoveYAccL();

void __cdecl MoveYAccL2();

void __cdecl MoveYAccL3();

void __cdecl MoveYAccL4();

void __cdecl MoveYAccR();

void __cdecl MoveYAccR2();

void __cdecl MoveYAccR3();

void __cdecl MoveYAccR4();

void __cdecl MoveZAccL();

void __cdecl MoveZAccL2();

void __cdecl MoveZAccL3();

void __cdecl MoveZAccL4();

void __cdecl MoveZAccR();

void __cdecl MoveZAccR2();

void __cdecl MoveZAccR3();

void __cdecl MoveZAccR4();

br_material* __cdecl GetInternalMat();

br_material* __cdecl GetExternalMat();

void __cdecl BuildSpecVolModel(tSpecial_volume *pSpec, int pIndex, br_material *pInt_mat, br_material *pExt_mat);

void __cdecl DropSpecVol(int pIndex);

void __cdecl DropSpecVol0();

void __cdecl DropSpecVol1();

void __cdecl DropSpecVol2();

void __cdecl DropSpecVol3();

void __cdecl DropSpecVol4();

void __cdecl DropSpecVol5();

void __cdecl DropSpecVol6();

void __cdecl DropSpecVol7();

void __cdecl DropSpecVol8();

void __cdecl DropSpecVol9();

void __cdecl IdentifySpecVol();

void __cdecl DelSpecVolumeGraph(int pIndex);

void __cdecl DeleteSpecVol();

void __cdecl RotateSpecVolL();

void __cdecl RotateSpecVolL2();

void __cdecl RotateSpecVolL3();

void __cdecl RotateSpecVolL4();

void __cdecl RotateSpecVolR();

void __cdecl RotateSpecVolR2();

void __cdecl RotateSpecVolR3();

void __cdecl RotateSpecVolR4();

void __cdecl CycleSpecVolRotate();

void __cdecl CycleSpecVolScale();

void __cdecl ScaleSpecVolUp2();

void __cdecl ScaleSpecVolUp3();

void __cdecl ScaleSpecVolUp4();

void __cdecl ScaleSpecVolDown2();

void __cdecl ScaleSpecVolDown3();

void __cdecl ScaleSpecVolDown4();

void __cdecl MoveXSpecVolL();

void __cdecl MoveXSpecVolL2();

void __cdecl MoveXSpecVolL3();

void __cdecl MoveXSpecVolL4();

void __cdecl MoveXSpecVolR();

void __cdecl MoveXSpecVolR2();

void __cdecl MoveXSpecVolR3();

void __cdecl MoveXSpecVolR4();

void __cdecl MoveYSpecVolL();

void __cdecl MoveYSpecVolL2();

void __cdecl MoveYSpecVolL3();

void __cdecl MoveYSpecVolL4();

void __cdecl MoveYSpecVolR();

void __cdecl MoveYSpecVolR2();

void __cdecl MoveYSpecVolR3();

void __cdecl MoveYSpecVolR4();

void __cdecl MoveZSpecVolL();

void __cdecl MoveZSpecVolL2();

void __cdecl MoveZSpecVolL3();

void __cdecl MoveZSpecVolL4();

void __cdecl MoveZSpecVolR();

void __cdecl MoveZSpecVolR2();

void __cdecl MoveZSpecVolR3();

void __cdecl MoveZSpecVolR4();

void __cdecl SnapSpecVolToVertical();

void __cdecl ShowSpecialVolumes();

void __cdecl HideSpecialVolumes();

#endif
