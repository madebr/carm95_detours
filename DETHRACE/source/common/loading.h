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

tU32 ReadU32(FILE *pF);

tU16 ReadU16(FILE *pF);

tU8 ReadU8(FILE *pF);

tS32 ReadS32(FILE *pF);

tS16 ReadS16(FILE *pF);

tS8 ReadS8(FILE *pF);

void WriteU32L(FILE *pF, tU32 pNumber);

void WriteU16L(FILE *pF, tU16 pNumber);

void WriteU8L(FILE *pF, tU8 pNumber);

void WriteS32L(FILE *pF, tS32 pNumber);

void WriteS16L(FILE *pF, tS16 pNumber);

void WriteS8L(FILE *pF, tS8 pNumber);

void SkipBytes(FILE *pF, int pBytes_to_skip);

tU32 MemReadU32(char **pPtr);

tU16 MemReadU16(char **pPtr);

tU8 MemReadU8(char **pPtr);

tS32 MemReadS32(char **pPtr);

tS16 MemReadS16(char **pPtr);

tS8 MemReadS8(char **pPtr);

void MemSkipBytes(char **pPtr, int pBytes_to_skip);

void LoadGeneralParameters();

void FinishLoadingGeneral();

br_pixelmap* LoadPixelmap(char *pName);

br_uint_32 LoadPixelmaps(char *pFile_name, br_pixelmap **pPixelmaps, br_uint_16 pNum);

br_pixelmap* LoadShadeTable(char *pName);

br_material* LoadMaterial(char *pName);

br_model* LoadModel(char *pName);

br_actor* LoadActor(char *pName);

void DRLoadPalette(char *pPath_name);

void DRLoadShadeTable(char *pPath_name);

void RezeroPixelmaps(br_pixelmap **pPixelmap_array, int pCount);

void DRLoadPixelmaps(char *pPath_name);

void DRLoadMaterials(char *pPath_name);

void DRLoadModels(char *pPath_name);

void DRLoadActors(char *pPath_name);

void DRLoadLights(char *pPath_name);

void LoadInFiles(char *pThe_base_path, char *pThe_dir_name, void(**pLoad_routine)(char *, ...));

void LoadInRegisteeDir(char *pThe_dir_path);

void LoadInRegistees();

void LoadKeyMapping();

void LoadInterfaceStuff(int pWithin_race);

void UnlockInterfaceStuff();

void InitInterfaceLoadState();

tS8* ConvertPixTo16BitStripMap(br_pixelmap *pBr_map);

tS8* ConvertPixToStripMap(br_pixelmap *pThe_br_map);

void KillWindscreen(br_model *pModel, br_material *pMaterial);

void DropOffDyingPeds(tCar_spec *pCar);

void DisposeCar(tCar_spec *pCar_spec, int pOwner);

void AdjustCarCoordinates(tCar_spec *pCar);

void LoadSpeedo(FILE *pF, int pIndex, tCar_spec *pCar_spec);

void LoadTacho(FILE *pF, int pIndex, tCar_spec *pCar_spec);

void LoadHeadups(FILE *pF, int pIndex, tCar_spec *pCar_spec);

void ReadNonCarMechanicsData(FILE *pF, tNon_car_spec *non_car);

void ReadMechanicsData(FILE *pF, tCar_spec *c);

void LoadGear(FILE *pF, int pIndex, tCar_spec *pCar_spec);

void AddRefOffset(int *pRef_holder);

void GetDamageProgram(FILE *pF, tCar_spec *pCar_spec, tImpact_location pImpact_location);

br_uint_32 LinkModel(br_actor *pActor, tModel_pool *pModel_pool);

void FreeUpBonnetModels(br_model **pModel_array, int pModel_count);

void LinkModelsToActor(br_actor *pActor, br_model **pModel_array, int pModel_count);

void ReadShrapnelMaterials(FILE *pF, tCollision_info *pCar_spec);

void CloneCar(tCar_spec **pOutput_car, tCar_spec *pInput_car);

void DisposeClonedCar(tCar_spec *pCar);

int RemoveDoubleSided(br_model *pModel);

void MungeWindscreen(br_model *pModel);

void SetModelFlags(br_model *pModel, int pOwner);

void LoadCar(char *pCar_name, tDriver pDriver, tCar_spec *pCar_spec, int pOwner, char *pDriver_name, tBrender_storage *pStorage_space);

void LoadHeadupImages();

void DisposeHeadupImages();

FILE* OpenRaceFile();

void SkipRestOfRace(FILE *pF);

void LoadRaces(tRace_list_spec *pRace_list, int *pCount, int pRace_type_index);

void UnlockOpponentMugshot(int pIndex);

void LoadOpponentMugShot(int pIndex);

void DisposeOpponentGridIcon(tRace_info *pRace_info, int pIndex);

void LoadOpponentGridIcon(tRace_info *pRace_info, int pIndex);

void LoadRaceInfo(int pRace_index, tRace_info *pRace_info);

void DisposeRaceInfo(tRace_info *pRace_info);

void LoadGridIcons(tRace_info *pRace_info);

void DisposeGridIcons(tRace_info *pRace_info);

void LoadOpponents();

br_font* LoadBRFont(char *pName);

void LoadParts();

void UnlockParts();

br_pixelmap* LoadChromeFont();

void DisposeChromeFont(br_pixelmap *pThe_font);

int GetALineAndInterpretCommand(FILE *pF, char **pString_list, int pCount);

int GetAnInt(FILE *pF);

float GetAFloat(FILE *pF);

float GetAFloatPercent(FILE *pF);

void GetPairOfFloats(FILE *pF, float *pF1, float *pF2);

void GetThreeFloats(FILE *pF, float *pF1, float *pF2, float *pF3);

void GetPairOfInts(FILE *pF, int *pF1, int *pF2);

void GetThreeInts(FILE *pF, int *pF1, int *pF2, int *pF3);

void GetThreeIntsAndAString(FILE *pF, int *pF1, int *pF2, int *pF3, char *pS);

void GetFourInts(FILE *pF, int *pF1, int *pF2, int *pF3, int *pF4);

br_scalar GetAScalar(FILE *pF);

void GetPairOfScalars(FILE *pF, br_scalar *pS1, br_scalar *pS2);

void GetThreeScalars(FILE *pF, br_scalar *pS1, br_scalar *pS2, br_scalar *pS3);

void GetFourScalars(FILE *pF, br_scalar *pF1, br_scalar *pF2, br_scalar *pF3, br_scalar *pF4);

void GetFiveScalars(FILE *pF, br_scalar *pF1, br_scalar *pF2, br_scalar *pF3, br_scalar *pF4, br_scalar *pF5);

void GetNScalars(FILE *pF, int pNumber, br_scalar *pScalars);

void GetPairOfFloatPercents(FILE *pF, float *pF1, float *pF2);

void GetThreeFloatPercents(FILE *pF, float *pF1, float *pF2, float *pF3);

void GetAString(FILE *pF, char *pString);

void AboutToLoadFirstCar();

void LoadOpponentsCars(tRace_info *pRace_info);

void DisposeOpponentsCars(tRace_info *pRace_info);

void LoadMiscStrings();

void FillInRaceInfo(tRace_info *pThe_race);

FILE* OldDRfopen(char *pFilename, char *pMode);

void AllowOpenToFail();

void DoNotAllowOpenToFail();

FILE* DRfopen(char *pFilename, char *pMode);

int GetCDPathFromPathsTxtFile(char *pPath_name);

int TestForOriginalCarmaCDinDrive();

int OriginalCarmaCDinDrive();

int CarmaCDinDriveOrFullGameInstalled();

void ReadNetworkSettings(FILE *pF, tNet_game_options *pOptions);

int PrintNetOptions(FILE *pF, int pIndex);

int SaveOptions();

int RestoreOptions();

void InitFunkGrooveFlags();

#endif
