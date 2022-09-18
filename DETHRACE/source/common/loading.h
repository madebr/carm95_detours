#ifndef _LOADING_H_
#define _LOADING_H_

#include "br_types.h"
#include "dr_types.h"

extern tHeadup_info(* hookvar_gHeadup_image_info )[31]; // addr: 0050A3F0
// extern char *(* hookvar_gYour_car_names )[2][6];
// extern char *(* hookvar_gDrivable_car_names )[6];
extern char *(* hookvar_gDamage_names )[12]; // addr: 0050A530
extern char *(* hookvar_gWheel_actor_names )[6]; // addr: 0050A560
// extern char *(* hookvar_gRaces_file_names )[9];
extern char *(* hookvar_gNet_avail_names )[4]; // addr: 0050A5A0
extern char *(* hookvar_gFloorpan_names )[5]; // addr: 0050A5B0
extern int * hookvar_gAllow_open_to_fail ; // addr: 0050A5C4
extern int * hookvar_gDecode_thing ; // addr: 0050A5C8
extern char(* hookvar_gDecode_string )[14]; // addr: 0050A5D0
extern int(* hookvar_gFunk_groove_flags )[30]; // addr: 00531F00
extern char(* hookvar_gDef_def_water_screen_name )[32]; // addr: 00531F80
extern br_material ** hookvar_gDestn_screen_mat ; // addr: 00531DFC
extern br_material ** hookvar_gSource_screen_mat ; // addr: 00531F78
extern int * hookvar_gCurrent_race_file_index ; // addr: 00531F7C
extern int * hookvar_gGroove_funk_offset ; // addr: 00531DF8
extern int * hookvar_gDemo_armour ; // addr: 00551DA8
extern int * hookvar_gDemo_rank ; // addr: 00551DB0
// extern int(* hookvar_gDemo_opponents )[5];
extern int * hookvar_gDemo_power ; // addr: 00551DA4
extern int * hookvar_gDemo_offensive ; // addr: 00551DAC

tU32 __cdecl ReadU32(FILE *pF);

tU16 __cdecl ReadU16(FILE *pF);

tU8 __cdecl ReadU8(FILE *pF);

tS32 __cdecl ReadS32(FILE *pF);

tS16 __cdecl ReadS16(FILE *pF);

tS8 __cdecl ReadS8(FILE *pF);

void __cdecl WriteU32L(FILE *pF, tU32 pNumber);

void __cdecl WriteU16L(FILE *pF, tU16 pNumber);

void __cdecl WriteU8L(FILE *pF, tU8 pNumber);

void __cdecl WriteS32L(FILE *pF, tS32 pNumber);

void __cdecl WriteS16L(FILE *pF, tS16 pNumber);

void __cdecl WriteS8L(FILE *pF, tS8 pNumber);

void __cdecl SkipBytes(FILE *pF, int pBytes_to_skip);

tU32 __cdecl MemReadU32(char **pPtr);

tU16 __cdecl MemReadU16(char **pPtr);

tU8 __cdecl MemReadU8(char **pPtr);

tS32 __cdecl MemReadS32(char **pPtr);

tS16 __cdecl MemReadS16(char **pPtr);

tS8 __cdecl MemReadS8(char **pPtr);

void __cdecl MemSkipBytes(char **pPtr, int pBytes_to_skip);

void __cdecl LoadGeneralParameters();

void __cdecl FinishLoadingGeneral();

br_pixelmap* __cdecl LoadPixelmap(char *pName);

br_uint_32 __cdecl LoadPixelmaps(char *pFile_name, br_pixelmap **pPixelmaps, br_uint_16 pNum);

br_pixelmap* __cdecl LoadShadeTable(char *pName);

br_material* __cdecl LoadMaterial(char *pName);

br_model* __cdecl LoadModel(char *pName);

br_actor* __cdecl LoadActor(char *pName);

void __cdecl DRLoadPalette(char *pPath_name);

void __cdecl DRLoadShadeTable(char *pPath_name);

void __cdecl RezeroPixelmaps(br_pixelmap **pPixelmap_array, int pCount);

void __cdecl DRLoadPixelmaps(char *pPath_name);

void __cdecl DRLoadMaterials(char *pPath_name);

void __cdecl DRLoadModels(char *pPath_name);

void __cdecl DRLoadActors(char *pPath_name);

void __cdecl DRLoadLights(char *pPath_name);

void __cdecl LoadInFiles(char *pThe_base_path, char *pThe_dir_name, void(**pLoad_routine)(char *));

void __cdecl LoadInRegisteeDir(char *pThe_dir_path);

void __cdecl LoadInRegistees();

void __cdecl LoadKeyMapping();

void __cdecl LoadInterfaceStuff(int pWithin_race);

void __cdecl UnlockInterfaceStuff();

void __cdecl InitInterfaceLoadState();

tS8* ConvertPixTo16BitStripMap(br_pixelmap *pBr_map);

tS8* __cdecl ConvertPixToStripMap(br_pixelmap *pThe_br_map);

void __cdecl KillWindscreen(br_model *pModel, br_material *pMaterial);

void __cdecl DropOffDyingPeds(tCar_spec *pCar);

void __cdecl DisposeCar(tCar_spec *pCar_spec, int pOwner);

void __cdecl AdjustCarCoordinates(tCar_spec *pCar);

void __cdecl LoadSpeedo(FILE *pF, int pIndex, tCar_spec *pCar_spec);

void __cdecl LoadTacho(FILE *pF, int pIndex, tCar_spec *pCar_spec);

void __cdecl LoadHeadups(FILE *pF, int pIndex, tCar_spec *pCar_spec);

void __cdecl ReadNonCarMechanicsData(FILE *pF, tNon_car_spec *non_car);

void __cdecl ReadMechanicsData(FILE *pF, tCar_spec *c);

void __cdecl LoadGear(FILE *pF, int pIndex, tCar_spec *pCar_spec);

void __cdecl AddRefOffset(int *pRef_holder);

void __cdecl GetDamageProgram(FILE *pF, tCar_spec *pCar_spec, tImpact_location pImpact_location);

br_uint_32 __cdecl LinkModel(br_actor *pActor, tModel_pool *pModel_pool);

void FreeUpBonnetModels(br_model **pModel_array, int pModel_count);

void __cdecl LinkModelsToActor(br_actor *pActor, br_model **pModel_array, int pModel_count);

void __cdecl ReadShrapnelMaterials(FILE *pF, tCollision_info *pCar_spec);

void __cdecl CloneCar(tCar_spec **pOutput_car, tCar_spec *pInput_car);

void __cdecl DisposeClonedCar(tCar_spec *pCar);

int __cdecl RemoveDoubleSided(br_model *pModel);

void __cdecl MungeWindscreen(br_model *pModel);

void __cdecl SetModelFlags(br_model *pModel, int pOwner);

void __cdecl LoadCar(char *pCar_name, tDriver pDriver, tCar_spec *pCar_spec, int pOwner, char *pDriver_name, tBrender_storage *pStorage_space);

void __cdecl LoadHeadupImages();

void __cdecl DisposeHeadupImages();

FILE* __cdecl OpenRaceFile();

void __cdecl SkipRestOfRace(FILE *pF);

void __cdecl LoadRaces(tRace_list_spec *pRace_list, int *pCount, int pRace_type_index);

void __cdecl UnlockOpponentMugshot(int pIndex);

void __cdecl LoadOpponentMugShot(int pIndex);

void __cdecl DisposeOpponentGridIcon(tRace_info *pRace_info, int pIndex);

void __cdecl LoadOpponentGridIcon(tRace_info *pRace_info, int pIndex);

void __cdecl LoadRaceInfo(int pRace_index, tRace_info *pRace_info);

void __cdecl DisposeRaceInfo(tRace_info *pRace_info);

void __cdecl LoadGridIcons(tRace_info *pRace_info);

void __cdecl DisposeGridIcons(tRace_info *pRace_info);

void __cdecl LoadOpponents();

br_font* __cdecl LoadBRFont(char *pName);

void __cdecl LoadParts();

void __cdecl UnlockParts();

br_pixelmap* __cdecl LoadChromeFont();

void __cdecl DisposeChromeFont(br_pixelmap *pThe_font);

int __cdecl GetALineAndInterpretCommand(FILE *pF, char **pString_list, int pCount);

int __cdecl GetAnInt(FILE *pF);

float __cdecl GetAFloat(FILE *pF);

float __cdecl GetAFloatPercent(FILE *pF);

void __cdecl GetPairOfFloats(FILE *pF, float *pF1, float *pF2);

void __cdecl GetThreeFloats(FILE *pF, float *pF1, float *pF2, float *pF3);

void __cdecl GetPairOfInts(FILE *pF, int *pF1, int *pF2);

void __cdecl GetThreeInts(FILE *pF, int *pF1, int *pF2, int *pF3);

void __cdecl GetThreeIntsAndAString(FILE *pF, int *pF1, int *pF2, int *pF3, char *pS);

void __cdecl GetFourInts(FILE *pF, int *pF1, int *pF2, int *pF3, int *pF4);

br_scalar __cdecl GetAScalar(FILE *pF);

void __cdecl GetPairOfScalars(FILE *pF, br_scalar *pS1, br_scalar *pS2);

void __cdecl GetThreeScalars(FILE *pF, br_scalar *pS1, br_scalar *pS2, br_scalar *pS3);

void __cdecl GetFourScalars(FILE *pF, br_scalar *pF1, br_scalar *pF2, br_scalar *pF3, br_scalar *pF4);

void __cdecl GetFiveScalars(FILE *pF, br_scalar *pF1, br_scalar *pF2, br_scalar *pF3, br_scalar *pF4, br_scalar *pF5);

void __cdecl GetNScalars(FILE *pF, int pNumber, br_scalar *pScalars);

void __cdecl GetPairOfFloatPercents(FILE *pF, float *pF1, float *pF2);

void __cdecl GetThreeFloatPercents(FILE *pF, float *pF1, float *pF2, float *pF3);

void __cdecl GetAString(FILE *pF, char *pString);

void __cdecl AboutToLoadFirstCar();

void __cdecl LoadOpponentsCars(tRace_info *pRace_info);

void __cdecl DisposeOpponentsCars(tRace_info *pRace_info);

void __cdecl LoadMiscStrings();

void __cdecl FillInRaceInfo(tRace_info *pThe_race);

FILE* __cdecl OldDRfopen(char *pFilename, char *pMode);

void __cdecl AllowOpenToFail();

void DoNotAllowOpenToFail();

FILE* __cdecl DRfopen(char *pFilename, char *pMode);

int __cdecl GetCDPathFromPathsTxtFile(char *pPath_name);

int TestForOriginalCarmaCDinDrive();

int __cdecl OriginalCarmaCDinDrive();

int __cdecl CarmaCDinDriveOrFullGameInstalled();

void __cdecl ReadNetworkSettings(FILE *pF, tNet_game_options *pOptions);

int __cdecl PrintNetOptions(FILE *pF, int pIndex);

int __cdecl SaveOptions();

int __cdecl RestoreOptions();

void __cdecl InitFunkGrooveFlags();

#endif
