#include "world.h"

#include "harness/trace.h"

#include "carm95_hooks.h"

#include <stdio.h>
int * hookvar_gFunkotronics_array_size  = (void*)0x0050c710;
int * hookvar_gGroovidelics_array_size  = (void*)0x0050c714;
int * hookvar_gSpec_vol_mode  = (void*)0x0050c718;
tFunkotronic_spec ** hookvar_gFunkotronics_array  = (void*)0x0050c71c;
tGroovidelic_spec ** hookvar_gGroovidelics_array  = (void*)0x0050c720;
char *(* hookvar_gFunk_type_names )[5] = (void*)0x0050c728;
char *(* hookvar_gFunk_anim_names )[2] = (void*)0x0050c740;
char *(* hookvar_gTime_mode_names )[2] = (void*)0x0050c748;
char *(* hookvar_gFunk_move_names )[6] = (void*)0x0050c750;
char *(* hookvar_gFunk_nature_names )[4] = (void*)0x0050c768;
char *(* hookvar_gGroove_nature_names )[2] = (void*)0x0050c778;
char *(* hookvar_gAxis_names )[3] = (void*)0x0050c780;
char *(* hookvar_gLollipop_names )[3] = (void*)0x0050c790;
char *(* hookvar_gGroove_path_names )[2] = (void*)0x0050c7a0;
char *(* hookvar_gGroove_object_names )[4] = (void*)0x0050c7a8;
char *(* hookvar_gDepth_effect_names )[2] = (void*)0x0050c7b8;
#if 0
br_actor ** hookvar_gGroove_by_proxy_actor ;
#endif
tRotate_mode * hookvar_gCurrent_rotate_mode  = (void*)0x0050c7c4;
tScale_mode * hookvar_gCurrent_scale_mode  = (void*)0x0050c7c8;
int * hookvar_gNumber_of_additional_models  = (void*)0x0050c7cc;
tRoad_texturing_level * hookvar_gRoad_texturing_level  = (void*)0x0050c7d0;
tWall_texturing_level * hookvar_gWall_texturing_level  = (void*)0x0050c7d4;
tCar_texturing_level * hookvar_gCar_texturing_level  = (void*)0x0050c7d8;
int * hookvar_gRendering_accessories  = (void*)0x0050c7dc;
int * hookvar_gNumber_of_actors  = (void*)0x0050c7e0;
int * hookvar_gNumber_of_lights  = (void*)0x0050c7e4;
br_actor *(* hookvar_gActor_array )[500] = (void*)0x005514e0;
float *(* hookvar_gGroove_funk_bindings )[960] = (void*)0x00532af0;
br_actor *(* hookvar_gDelete_list )[500] = (void*)0x00532220;
br_actor *(* hookvar_gLight_array )[50] = (void*)0x00551cb0;
br_model *(* hookvar_gAdditional_models )[1000] = (void*)0x00533b18;
br_actor *(* hookvar_gSpec_vol_actors )[100] = (void*)0x00534ac0;
tPath_name * hookvar_gAdditional_actor_path  = (void*)0x00533a00;
tPath_name * hookvar_gAdditional_model_path  = (void*)0x005329f0;
tU32(* hookvar_gPrevious_groove_times )[2] = (void*)0x00533b00;
int * hookvar_gRace_file_version  = (void*)0x00551d78;
br_vector3 * hookvar_gActor_centre  = (void*)0x005339f0;
#if 0
float * hookvar_gTemp ;
#endif
br_actor ** hookvar_gLast_actor  = (void*)0x00533b0c;
br_actor ** hookvar_gKnown_actor  = (void*)0x00533b08;
br_actor ** hookvar_gAdditional_actors  = (void*)0x00534ab8;
int * hookvar_gDelete_count  = (void*)0x00533b10;
br_scalar * hookvar_gNearest_distance  = (void*)0x005339fc;
br_actor ** hookvar_gNearest_actor  = (void*)0x00534c50;
#if 0
br_actor ** hookvar_gStandard_lamp ;
#endif
br_scalar * hookvar_gSight_distance_squared  = (void*)0x00534abc;

static float(*original_MapSawToTriangle)(float, ...) = (float(*)(float, ...))0x0043f377;
CARM95_HOOK_FUNCTION(original_MapSawToTriangle, MapSawToTriangle)
float MapSawToTriangle(float pNumber) {
    LOG_TRACE("(%f)", pNumber);

    (void)pNumber;

    return original_MapSawToTriangle(pNumber);
}

static void(*original_SetSightDistance)(br_scalar, ...) = (void(*)(br_scalar, ...))0x00434b10;
CARM95_HOOK_FUNCTION(original_SetSightDistance, SetSightDistance)
void SetSightDistance(br_scalar pYon) {
    LOG_TRACE("(%f)", pYon);

    (void)pYon;

    original_SetSightDistance(pYon);
}

static br_actor *(*original_FindActorInArray)(char *, ...) = (br_actor *(*)(char *, ...))0x00434b35;
CARM95_HOOK_FUNCTION(original_FindActorInArray, FindActorInArray)
br_actor* FindActorInArray(char *pThe_name) {
    int i;
    LOG_TRACE("(\"%s\")", pThe_name);

    (void)pThe_name;
    (void)i;

    return original_FindActorInArray(pThe_name);
}

static br_actor *(*original_FindLightInArray)(char *, ...) = (br_actor *(*)(char *, ...))0x00434bcc;
CARM95_HOOK_FUNCTION(original_FindLightInArray, FindLightInArray)
br_actor* FindLightInArray(char *pThe_name) {
    int i;
    LOG_TRACE("(\"%s\")", pThe_name);

    (void)pThe_name;
    (void)i;

    return original_FindLightInArray(pThe_name);
}

static br_actor *(*original_CloneActor)(br_actor *, ...) = (br_actor *(*)(br_actor *, ...))0x00434c62;
CARM95_HOOK_FUNCTION(original_CloneActor, CloneActor)
br_actor* CloneActor(br_actor *pSource_actor) {
    br_actor *new_actor;
    br_actor *child_actor;
    br_actor *new_child_actor;
    LOG_TRACE("(%p)", pSource_actor);

    (void)pSource_actor;
    (void)new_actor;
    (void)child_actor;
    (void)new_child_actor;

    return original_CloneActor(pSource_actor);
}

static void(*original_InitialiseStorageSpace)(tBrender_storage *, int, int, int, int, ...) = (void(*)(tBrender_storage *, int, int, int, int, ...))0x00434d37;
CARM95_HOOK_FUNCTION(original_InitialiseStorageSpace, InitialiseStorageSpace)
void InitialiseStorageSpace(tBrender_storage *pStorage_space, int pMax_pixelmaps, int pMax_shade_tables, int pMax_materials, int pMax_models) {
    LOG_TRACE("(%p, %d, %d, %d, %d)", pStorage_space, pMax_pixelmaps, pMax_shade_tables, pMax_materials, pMax_models);

    (void)pStorage_space;
    (void)pMax_pixelmaps;
    (void)pMax_shade_tables;
    (void)pMax_materials;
    (void)pMax_models;

    original_InitialiseStorageSpace(pStorage_space, pMax_pixelmaps, pMax_shade_tables, pMax_materials, pMax_models);
}

static void(*original_DisposeStorageSpace)(tBrender_storage *, ...) = (void(*)(tBrender_storage *, ...))0x00434e0a;
CARM95_HOOK_FUNCTION(original_DisposeStorageSpace, DisposeStorageSpace)
void DisposeStorageSpace(tBrender_storage *pStorage_space) {
    LOG_TRACE("(%p)", pStorage_space);

    (void)pStorage_space;

    original_DisposeStorageSpace(pStorage_space);
}

static void(*original_ClearOutStorageSpace)(tBrender_storage *, ...) = (void(*)(tBrender_storage *, ...))0x00434e60;
CARM95_HOOK_FUNCTION(original_ClearOutStorageSpace, ClearOutStorageSpace)
void ClearOutStorageSpace(tBrender_storage *pStorage_space) {
    int i;
    LOG_TRACE("(%p)", pStorage_space);

    (void)pStorage_space;
    (void)i;

    original_ClearOutStorageSpace(pStorage_space);
}

static tAdd_to_storage_result(*original_AddPixelmapToStorage)(tBrender_storage *, br_pixelmap **, ...) = (tAdd_to_storage_result(*)(tBrender_storage *, br_pixelmap **, ...))0x00435014;
CARM95_HOOK_FUNCTION(original_AddPixelmapToStorage, AddPixelmapToStorage)
tAdd_to_storage_result AddPixelmapToStorage(tBrender_storage *pStorage_space, br_pixelmap **pThe_pm) {
    int i;
    LOG_TRACE("(%p, %p)", pStorage_space, pThe_pm);

    (void)pStorage_space;
    (void)pThe_pm;
    (void)i;

    return original_AddPixelmapToStorage(pStorage_space, pThe_pm);
}

static tAdd_to_storage_result(*original_AddShadeTableToStorage)(tBrender_storage *, br_pixelmap *, ...) = (tAdd_to_storage_result(*)(tBrender_storage *, br_pixelmap *, ...))0x00435107;
CARM95_HOOK_FUNCTION(original_AddShadeTableToStorage, AddShadeTableToStorage)
tAdd_to_storage_result AddShadeTableToStorage(tBrender_storage *pStorage_space, br_pixelmap *pThe_st) {
    int i;
    LOG_TRACE("(%p, %p)", pStorage_space, pThe_st);

    (void)pStorage_space;
    (void)pThe_st;
    (void)i;

    return original_AddShadeTableToStorage(pStorage_space, pThe_st);
}

static tAdd_to_storage_result(*original_AddMaterialToStorage)(tBrender_storage *, br_material *, ...) = (tAdd_to_storage_result(*)(tBrender_storage *, br_material *, ...))0x004351fa;
CARM95_HOOK_FUNCTION(original_AddMaterialToStorage, AddMaterialToStorage)
tAdd_to_storage_result AddMaterialToStorage(tBrender_storage *pStorage_space, br_material *pThe_mat) {
    int i;
    LOG_TRACE("(%p, %p)", pStorage_space, pThe_mat);

    (void)pStorage_space;
    (void)pThe_mat;
    (void)i;

    return original_AddMaterialToStorage(pStorage_space, pThe_mat);
}

static tAdd_to_storage_result(*original_AddModelToStorage)(tBrender_storage *, br_model *, ...) = (tAdd_to_storage_result(*)(tBrender_storage *, br_model *, ...))0x00435300;
CARM95_HOOK_FUNCTION(original_AddModelToStorage, AddModelToStorage)
tAdd_to_storage_result AddModelToStorage(tBrender_storage *pStorage_space, br_model *pThe_mod) {
    int i;
    LOG_TRACE("(%p, %p)", pStorage_space, pThe_mod);

    (void)pStorage_space;
    (void)pThe_mod;
    (void)i;

    return original_AddModelToStorage(pStorage_space, pThe_mod);
}

static int(*original_LoadNPixelmaps)(tBrender_storage *, FILE *, int, ...) = (int(*)(tBrender_storage *, FILE *, int, ...))0x00435402;
CARM95_HOOK_FUNCTION(original_LoadNPixelmaps, LoadNPixelmaps)
int LoadNPixelmaps(tBrender_storage *pStorage_space, FILE *pF, int pCount) {
    tPath_name the_path;
    int i;
    int j;
    int new_ones;
    int total;
    char s[256];
    char *str;
    br_pixelmap *temp_array[200];
    LOG_TRACE("(%p, %p, %d)", pStorage_space, pF, pCount);

    (void)pStorage_space;
    (void)pF;
    (void)pCount;
    (void)the_path;
    (void)i;
    (void)j;
    (void)new_ones;
    (void)total;
    (void)s;
    (void)str;
    (void)temp_array;

    return original_LoadNPixelmaps(pStorage_space, pF, pCount);
}

static br_pixelmap *(*original_LoadSinglePixelmap)(tBrender_storage *, char *, ...) = (br_pixelmap *(*)(tBrender_storage *, char *, ...))0x00435666;
CARM95_HOOK_FUNCTION(original_LoadSinglePixelmap, LoadSinglePixelmap)
br_pixelmap* LoadSinglePixelmap(tBrender_storage *pStorage_space, char *pName) {
    br_pixelmap *temp;
    LOG_TRACE("(%p, \"%s\")", pStorage_space, pName);

    (void)pStorage_space;
    (void)pName;
    (void)temp;

    return original_LoadSinglePixelmap(pStorage_space, pName);
}

static br_material *(*original_LoadSingleMaterial)(tBrender_storage *, char *, ...) = (br_material *(*)(tBrender_storage *, char *, ...))0x00435731;
CARM95_HOOK_FUNCTION(original_LoadSingleMaterial, LoadSingleMaterial)
br_material* LoadSingleMaterial(tBrender_storage *pStorage_space, char *pName) {
    br_material *temp;
    LOG_TRACE("(%p, \"%s\")", pStorage_space, pName);

    (void)pStorage_space;
    (void)pName;
    (void)temp;

    return original_LoadSingleMaterial(pStorage_space, pName);
}

static int(*original_LoadNShadeTables)(tBrender_storage *, FILE *, int, ...) = (int(*)(tBrender_storage *, FILE *, int, ...))0x004357fc;
CARM95_HOOK_FUNCTION(original_LoadNShadeTables, LoadNShadeTables)
int LoadNShadeTables(tBrender_storage *pStorage_space, FILE *pF, int pCount) {
    tPath_name the_path;
    int i;
    int j;
    int new_ones;
    int total;
    char s[256];
    char *str;
    br_pixelmap *temp_array[50];
    LOG_TRACE("(%p, %p, %d)", pStorage_space, pF, pCount);

    (void)pStorage_space;
    (void)pF;
    (void)pCount;
    (void)the_path;
    (void)i;
    (void)j;
    (void)new_ones;
    (void)total;
    (void)s;
    (void)str;
    (void)temp_array;

    return original_LoadNShadeTables(pStorage_space, pF, pCount);
}

static br_pixelmap *(*original_LoadSingleShadeTable)(tBrender_storage *, char *, ...) = (br_pixelmap *(*)(tBrender_storage *, char *, ...))0x004359c7;
CARM95_HOOK_FUNCTION(original_LoadSingleShadeTable, LoadSingleShadeTable)
br_pixelmap* LoadSingleShadeTable(tBrender_storage *pStorage_space, char *pName) {
    br_pixelmap *temp;
    LOG_TRACE("(%p, \"%s\")", pStorage_space, pName);

    (void)pStorage_space;
    (void)pName;
    (void)temp;

    return original_LoadSingleShadeTable(pStorage_space, pName);
}

static int(*original_LoadNMaterials)(tBrender_storage *, FILE *, int, ...) = (int(*)(tBrender_storage *, FILE *, int, ...))0x00435a92;
CARM95_HOOK_FUNCTION(original_LoadNMaterials, LoadNMaterials)
int LoadNMaterials(tBrender_storage *pStorage_space, FILE *pF, int pCount) {
    tPath_name the_path;
    int i;
    int j;
    int new_ones;
    int total;
    char s[256];
    char *str;
    br_material *temp_array[200];
    LOG_TRACE("(%p, %p, %d)", pStorage_space, pF, pCount);

    (void)pStorage_space;
    (void)pF;
    (void)pCount;
    (void)the_path;
    (void)i;
    (void)j;
    (void)new_ones;
    (void)total;
    (void)s;
    (void)str;
    (void)temp_array;

    return original_LoadNMaterials(pStorage_space, pF, pCount);
}

static int(*original_LoadNModels)(tBrender_storage *, FILE *, int, ...) = (int(*)(tBrender_storage *, FILE *, int, ...))0x00435c60;
CARM95_HOOK_FUNCTION(original_LoadNModels, LoadNModels)
int LoadNModels(tBrender_storage *pStorage_space, FILE *pF, int pCount) {
    tPath_name the_path;
    int i;
    int j;
    int new_ones;
    int total;
    char s[256];
    char *str;
    br_model *temp_array[2000];
    struct v11model *prepared;
    int group;
    LOG_TRACE("(%p, %p, %d)", pStorage_space, pF, pCount);

    (void)pStorage_space;
    (void)pF;
    (void)pCount;
    (void)the_path;
    (void)i;
    (void)j;
    (void)new_ones;
    (void)total;
    (void)s;
    (void)str;
    (void)temp_array;
    (void)prepared;
    (void)group;

    return original_LoadNModels(pStorage_space, pF, pCount);
}

static void(*original_DodgyModelUpdate)(br_model *, ...) = (void(*)(br_model *, ...))0x00435e72;
CARM95_HOOK_FUNCTION(original_DodgyModelUpdate, DodgyModelUpdate)
void DodgyModelUpdate(br_model *pM) {
    LOG_TRACE("(%p)", pM);

    (void)pM;

    original_DodgyModelUpdate(pM);
}

static br_material *(*original_SuffixedMaterial)(br_material *, char *, ...) = (br_material *(*)(br_material *, char *, ...))0x00435f61;
CARM95_HOOK_FUNCTION(original_SuffixedMaterial, SuffixedMaterial)
br_material* SuffixedMaterial(br_material *pOld, char *pSuffix) {
    br_material *new_mat;
    char *new_id;
    LOG_TRACE("(%p, \"%s\")", pOld, pSuffix);

    (void)pOld;
    (void)pSuffix;
    (void)new_mat;
    (void)new_id;

    return original_SuffixedMaterial(pOld, pSuffix);
}

static int(*original_FaceIsRoad)(br_model *, tU16, ...) = (int(*)(br_model *, tU16, ...))0x00436027;
CARM95_HOOK_FUNCTION(original_FaceIsRoad, FaceIsRoad)
int FaceIsRoad(br_model *pModel, tU16 pFace) {
    br_vector3 v0;
    br_vector3 v1;
    br_vector3 cross;
    LOG_TRACE("(%p, %u)", pModel, pFace);

    (void)pModel;
    (void)pFace;
    (void)v0;
    (void)v1;
    (void)cross;

    return original_FaceIsRoad(pModel, pFace);
}

static br_material *(*original_RoadPerspToUntex)(br_model *, tU16, ...) = (br_material *(*)(br_model *, tU16, ...))0x004365aa;
CARM95_HOOK_FUNCTION(original_RoadPerspToUntex, RoadPerspToUntex)
br_material* RoadPerspToUntex(br_model *pModel, tU16 pFace) {
    br_material *old_mat;
    br_material *new_mat;
    LOG_TRACE("(%p, %u)", pModel, pFace);

    (void)pModel;
    (void)pFace;
    (void)old_mat;
    (void)new_mat;

    return original_RoadPerspToUntex(pModel, pFace);
}

static br_material *(*original_WallPerspToLinear)(br_model *, tU16, ...) = (br_material *(*)(br_model *, tU16, ...))0x00435ec1;
CARM95_HOOK_FUNCTION(original_WallPerspToLinear, WallPerspToLinear)
br_material* WallPerspToLinear(br_model *pModel, tU16 pFace) {
    br_material *old_mat;
    br_material *new_mat;
    LOG_TRACE("(%p, %u)", pModel, pFace);

    (void)pModel;
    (void)pFace;
    (void)old_mat;
    (void)new_mat;

    return original_WallPerspToLinear(pModel, pFace);
}

static br_material *(*original_WallPerspToUntex)(br_model *, tU16, ...) = (br_material *(*)(br_model *, tU16, ...))0x00436269;
CARM95_HOOK_FUNCTION(original_WallPerspToUntex, WallPerspToUntex)
br_material* WallPerspToUntex(br_model *pModel, tU16 pFace) {
    br_material *old_mat;
    br_material *new_mat;
    LOG_TRACE("(%p, %u)", pModel, pFace);

    (void)pModel;
    (void)pFace;
    (void)old_mat;
    (void)new_mat;

    return original_WallPerspToUntex(pModel, pFace);
}

void ProcessModelFaceMaterials2(br_model *pModel, tPMFM2CB pCallback) {
    tU16 f;
    tU16 group;
    br_material *old_mat;
    LOG_TRACE("(%p, %p)", pModel, pCallback);

    (void)pModel;
    (void)pCallback;
    (void)f;
    (void)group;
    (void)old_mat;

    NOT_IMPLEMENTED();
}

static void(*original_ProcessModelFaceMaterials)(br_model *, tPMFMCB*, ...) = (void(*)(br_model *, tPMFMCB*, ...))0x00436640;
CARM95_HOOK_FUNCTION(original_ProcessModelFaceMaterials, ProcessModelFaceMaterials)
void ProcessModelFaceMaterials(br_model *pModel, tPMFMCB pCallback) {
    tU16 f;
    br_material *possible_mat;
    br_material *new_mat;
    LOG_TRACE("(%p, %p)", pModel, pCallback);

    (void)pModel;
    (void)pCallback;
    (void)f;
    (void)possible_mat;
    (void)new_mat;

    original_ProcessModelFaceMaterials(pModel, pCallback);
}

static int(*original_LoadNTrackModels)(tBrender_storage *, FILE *, int, ...) = (int(*)(tBrender_storage *, FILE *, int, ...))0x00436325;
CARM95_HOOK_FUNCTION(original_LoadNTrackModels, LoadNTrackModels)
int LoadNTrackModels(tBrender_storage *pStorage_space, FILE *pF, int pCount) {
    tPath_name the_path;
    int i;
    int j;
    int new_ones;
    int total;
    int group;
    char s[256];
    char *str;
    br_model *temp_array[2000];
    struct v11model *prepared;
    LOG_TRACE("(%p, %p, %d)", pStorage_space, pF, pCount);

    (void)pStorage_space;
    (void)pF;
    (void)pCount;
    (void)the_path;
    (void)i;
    (void)j;
    (void)new_ones;
    (void)total;
    (void)group;
    (void)s;
    (void)str;
    (void)temp_array;
    (void)prepared;

    return original_LoadNTrackModels(pStorage_space, pF, pCount);
}

static void(*original_LoadSomePixelmaps)(tBrender_storage *, FILE *, ...) = (void(*)(tBrender_storage *, FILE *, ...))0x004366f3;
CARM95_HOOK_FUNCTION(original_LoadSomePixelmaps, LoadSomePixelmaps)
void LoadSomePixelmaps(tBrender_storage *pStorage_space, FILE *pF) {
    tPath_name the_path;
    int i;
    int j;
    int count;
    int new_ones;
    char s[256];
    char *str;
    br_pixelmap *temp_array[200];
    LOG_TRACE("(%p, %p)", pStorage_space, pF);

    (void)pStorage_space;
    (void)pF;
    (void)the_path;
    (void)i;
    (void)j;
    (void)count;
    (void)new_ones;
    (void)s;
    (void)str;
    (void)temp_array;

    original_LoadSomePixelmaps(pStorage_space, pF);
}

static void(*original_LoadSomeShadeTables)(tBrender_storage *, FILE *, ...) = (void(*)(tBrender_storage *, FILE *, ...))0x0043675d;
CARM95_HOOK_FUNCTION(original_LoadSomeShadeTables, LoadSomeShadeTables)
void LoadSomeShadeTables(tBrender_storage *pStorage_space, FILE *pF) {
    tPath_name the_path;
    int i;
    int j;
    int count;
    int new_ones;
    char s[256];
    char *str;
    br_pixelmap *temp_array[50];
    LOG_TRACE("(%p, %p)", pStorage_space, pF);

    (void)pStorage_space;
    (void)pF;
    (void)the_path;
    (void)i;
    (void)j;
    (void)count;
    (void)new_ones;
    (void)s;
    (void)str;
    (void)temp_array;

    original_LoadSomeShadeTables(pStorage_space, pF);
}

static void(*original_LoadSomeMaterials)(tBrender_storage *, FILE *, ...) = (void(*)(tBrender_storage *, FILE *, ...))0x004367c7;
CARM95_HOOK_FUNCTION(original_LoadSomeMaterials, LoadSomeMaterials)
void LoadSomeMaterials(tBrender_storage *pStorage_space, FILE *pF) {
    tPath_name the_path;
    int i;
    int j;
    int count;
    int new_ones;
    char s[256];
    char *str;
    br_material *temp_array[200];
    LOG_TRACE("(%p, %p)", pStorage_space, pF);

    (void)pStorage_space;
    (void)pF;
    (void)the_path;
    (void)i;
    (void)j;
    (void)count;
    (void)new_ones;
    (void)s;
    (void)str;
    (void)temp_array;

    original_LoadSomeMaterials(pStorage_space, pF);
}

static void(*original_LoadSomeModels)(tBrender_storage *, FILE *, ...) = (void(*)(tBrender_storage *, FILE *, ...))0x00436831;
CARM95_HOOK_FUNCTION(original_LoadSomeModels, LoadSomeModels)
void LoadSomeModels(tBrender_storage *pStorage_space, FILE *pF) {
    tPath_name the_path;
    int i;
    int j;
    int count;
    int new_ones;
    char s[256];
    char *str;
    br_model *temp_array[2000];
    LOG_TRACE("(%p, %p)", pStorage_space, pF);

    (void)pStorage_space;
    (void)pF;
    (void)the_path;
    (void)i;
    (void)j;
    (void)count;
    (void)new_ones;
    (void)s;
    (void)str;
    (void)temp_array;

    original_LoadSomeModels(pStorage_space, pF);
}

static void(*original_LoadSomeTrackModels)(tBrender_storage *, FILE *, ...) = (void(*)(tBrender_storage *, FILE *, ...))0x0043689f;
CARM95_HOOK_FUNCTION(original_LoadSomeTrackModels, LoadSomeTrackModels)
void LoadSomeTrackModels(tBrender_storage *pStorage_space, FILE *pF) {
    tPath_name the_path;
    int i;
    int j;
    int count;
    int new_ones;
    char s[256];
    char *str;
    br_model *temp_array[2000];
    LOG_TRACE("(%p, %p)", pStorage_space, pF);

    (void)pStorage_space;
    (void)pF;
    (void)the_path;
    (void)i;
    (void)j;
    (void)count;
    (void)new_ones;
    (void)s;
    (void)str;
    (void)temp_array;

    original_LoadSomeTrackModels(pStorage_space, pF);
}

static void(*original_AddFunkGrooveBinding)(int, float *, ...) = (void(*)(int, float *, ...))0x0043690d;
CARM95_HOOK_FUNCTION(original_AddFunkGrooveBinding, AddFunkGrooveBinding)
void AddFunkGrooveBinding(int pSlot_number, float *pPeriod_address) {
    LOG_TRACE("(%d, %p)", pSlot_number, pPeriod_address);

    (void)pSlot_number;
    (void)pPeriod_address;

    original_AddFunkGrooveBinding(pSlot_number, pPeriod_address);
}

static void(*original_ControlBoundFunkGroove)(int, float, ...) = (void(*)(int, float, ...))0x0043694f;
CARM95_HOOK_FUNCTION(original_ControlBoundFunkGroove, ControlBoundFunkGroove)
void ControlBoundFunkGroove(int pSlot_number, float pValue) {
    LOG_TRACE("(%d, %f)", pSlot_number, pValue);

    (void)pSlot_number;
    (void)pValue;

    original_ControlBoundFunkGroove(pSlot_number, pValue);
}

static float(*original_ControlBoundFunkGroovePlus)(int, float, ...) = (float(*)(int, float, ...))0x0043698f;
CARM95_HOOK_FUNCTION(original_ControlBoundFunkGroovePlus, ControlBoundFunkGroovePlus)
float ControlBoundFunkGroovePlus(int pSlot_number, float pValue) {
    LOG_TRACE("(%d, %f)", pSlot_number, pValue);

    (void)pSlot_number;
    (void)pValue;

    return original_ControlBoundFunkGroovePlus(pSlot_number, pValue);
}

static void(*original_ShiftBoundGrooveFunks)(char *, char *, int, ...) = (void(*)(char *, char *, int, ...))0x00437dca;
CARM95_HOOK_FUNCTION(original_ShiftBoundGrooveFunks, ShiftBoundGrooveFunks)
void ShiftBoundGrooveFunks(char *pStart, char *pEnd, int pDelta) {
    int i;
    LOG_TRACE("(\"%s\", \"%s\", %d)", pStart, pEnd, pDelta);

    (void)pStart;
    (void)pEnd;
    (void)pDelta;
    (void)i;

    original_ShiftBoundGrooveFunks(pStart, pEnd, pDelta);
}

static tFunkotronic_spec *(*original_AddNewFunkotronic)() = (tFunkotronic_spec *(*)())0x00437c4c;
CARM95_HOOK_FUNCTION(original_AddNewFunkotronic, AddNewFunkotronic)
tFunkotronic_spec* AddNewFunkotronic() {
    void *new_array;
    int i;
    LOG_TRACE("()");

    (void)new_array;
    (void)i;

    return original_AddNewFunkotronic();
}

static void(*original_DisposeFunkotronics)(int, ...) = (void(*)(int, ...))0x004369fd;
CARM95_HOOK_FUNCTION(original_DisposeFunkotronics, DisposeFunkotronics)
void DisposeFunkotronics(int pOwner) {
    int i;
    tFunkotronic_spec *the_funk;
    LOG_TRACE("(%d)", pOwner);

    (void)pOwner;
    (void)i;
    (void)the_funk;

    original_DisposeFunkotronics(pOwner);
}

static void(*original_AddProximityVertex)(br_vector3 *, tFunkotronic_spec *, ...) = (void(*)(br_vector3 *, tFunkotronic_spec *, ...))0x0043806e;
CARM95_HOOK_FUNCTION(original_AddProximityVertex, AddProximityVertex)
void AddProximityVertex(br_vector3 *pV, tFunkotronic_spec *pThe_funk) {
    LOG_TRACE("(%p, %p)", pV, pThe_funk);

    (void)pV;
    (void)pThe_funk;

    original_AddProximityVertex(pV, pThe_funk);
}

static void(*original_AddProximityVertexXYZ)(br_scalar, br_scalar, br_scalar, tFunkotronic_spec *, ...) = (void(*)(br_scalar, br_scalar, br_scalar, tFunkotronic_spec *, ...))0x004380ad;
CARM95_HOOK_FUNCTION(original_AddProximityVertexXYZ, AddProximityVertexXYZ)
void AddProximityVertexXYZ(br_scalar pX, br_scalar pY, br_scalar pZ, tFunkotronic_spec *pThe_funk) {
    br_vector3 v;
    LOG_TRACE("(%f, %f, %f, %p)", pX, pY, pZ, pThe_funk);

    (void)pX;
    (void)pY;
    (void)pZ;
    (void)pThe_funk;
    (void)v;

    original_AddProximityVertexXYZ(pX, pY, pZ, pThe_funk);
}

static br_uint_32(*original_CalcProximities)(br_actor *, br_material *, tFunkotronic_spec *, ...) = (br_uint_32(*)(br_actor *, br_material *, tFunkotronic_spec *, ...))0x00436af6;
CARM95_HOOK_FUNCTION(original_CalcProximities, CalcProximities)
br_uint_32 CalcProximities(br_actor *pActor, br_material *pMat, tFunkotronic_spec *pThe_funk) {
    br_face *the_face;
    int i;
    LOG_TRACE("(%p, %p, %p)", pActor, pMat, pThe_funk);

    (void)pActor;
    (void)pMat;
    (void)pThe_funk;
    (void)the_face;
    (void)i;

    return original_CalcProximities(pActor, pMat, pThe_funk);
}

static br_uint_32(*original_AddProximities)(br_actor *, br_material *, tFunkotronic_spec *, ...) = (br_uint_32(*)(br_actor *, br_material *, tFunkotronic_spec *, ...))0x00437e2f;
CARM95_HOOK_FUNCTION(original_AddProximities, AddProximities)
br_uint_32 AddProximities(br_actor *pActor, br_material *pMat, tFunkotronic_spec *pThe_funk) {
    br_face *the_face;
    int i;
    LOG_TRACE("(%p, %p, %p)", pActor, pMat, pThe_funk);

    (void)pActor;
    (void)pMat;
    (void)pThe_funk;
    (void)the_face;
    (void)i;

    return original_AddProximities(pActor, pMat, pThe_funk);
}

void Adjust2FloatsForExceptions(float *pVictim1, float *pVictim2, br_pixelmap *pCulprit) {
    tException_list e;
    LOG_TRACE("(%p, %p, %p)", pVictim1, pVictim2, pCulprit);

    (void)pVictim1;
    (void)pVictim2;
    (void)pCulprit;
    (void)e;

    NOT_IMPLEMENTED();
}

static void(*original_AddFunkotronics)(FILE *, int, int, ...) = (void(*)(FILE *, int, int, ...))0x00436b8b;
CARM95_HOOK_FUNCTION(original_AddFunkotronics, AddFunkotronics)
void AddFunkotronics(FILE *pF, int pOwner, int pRef_offset) {
    char s[256];
    char *str;
    int first_time;
    int i;
    int j;
    tFunkotronic_spec *the_funk;
    float speed1;
    float speed2;
    float a_min;
    float d_min;
    float s_min;
    float a_max;
    float d_max;
    float s_max;
    void *the_pixels;
    br_pixelmap *the_pixelmap;
    float __block0__x_0;
    float __block0__x_1;
    float __block1__x_0;
    float __block1__x_1;
    int __block1__d_0;
    int __block1__d_1;
    float __block2__x_0;
    float __block2__x_1;
    float __block3__x_0;
    float __block3__x_1;
    int __block3__d_0;
    int __block3__d_1;
    float __block4__x_0;
    float __block4__x_1;
    int __block4__d_0;
    int __block4__d_1;
    LOG_TRACE("(%p, %d, %d)", pF, pOwner, pRef_offset);

    (void)pF;
    (void)pOwner;
    (void)pRef_offset;
    (void)s;
    (void)str;
    (void)first_time;
    (void)i;
    (void)j;
    (void)the_funk;
    (void)speed1;
    (void)speed2;
    (void)a_min;
    (void)d_min;
    (void)s_min;
    (void)a_max;
    (void)d_max;
    (void)s_max;
    (void)the_pixels;
    (void)the_pixelmap;

    original_AddFunkotronics(pF, pOwner, pRef_offset);
}

static void(*original_DisposeGroovidelics)(int, ...) = (void(*)(int, ...))0x004380dd;
CARM95_HOOK_FUNCTION(original_DisposeGroovidelics, DisposeGroovidelics)
void DisposeGroovidelics(int pOwner) {
    int i;
    tGroovidelic_spec *the_groove;
    LOG_TRACE("(%d)", pOwner);

    (void)pOwner;
    (void)i;
    (void)the_groove;

    original_DisposeGroovidelics(pOwner);
}

static tGroovidelic_spec *(*original_AddNewGroovidelic)() = (tGroovidelic_spec *(*)())0x00438eb1;
CARM95_HOOK_FUNCTION(original_AddNewGroovidelic, AddNewGroovidelic)
tGroovidelic_spec* AddNewGroovidelic() {
    void *new_array;
    int i;
    LOG_TRACE("()");

    (void)new_array;
    (void)i;

    return original_AddNewGroovidelic();
}

static void(*original_AddGroovidelics)(FILE *, int, br_actor *, int, int, ...) = (void(*)(FILE *, int, br_actor *, int, int, ...))0x00438146;
CARM95_HOOK_FUNCTION(original_AddGroovidelics, AddGroovidelics)
void AddGroovidelics(FILE *pF, int pOwner, br_actor *pParent_actor, int pRef_offset, int pAllowed_to_be_absent) {
    char s[256];
    char *str;
    int first_time;
    int i;
    int j;
    tGroovidelic_spec *the_groove;
    float __block0__x_0;
    float __block0__x_1;
    float __block0__x_2;
    float __block1__x_0;
    float __block1__x_1;
    float __block1__x_2;
    float __block2__x_0;
    float __block2__x_1;
    float __block2__x_2;
    float __block3__x_0;
    float __block3__x_1;
    float __block3__x_2;
    float __block4__x_0;
    float __block4__x_1;
    float __block4__x_2;
    int __block4__d_0;
    int __block4__d_1;
    int __block4__d_2;
    float __block5__x_0;
    float __block5__x_1;
    float __block5__x_2;
    float __block6__x_0;
    float __block6__x_1;
    float __block6__x_2;
    int __block6__d_0;
    int __block6__d_1;
    int __block6__d_2;
    float __block7__x_0;
    float __block7__x_1;
    float __block7__x_2;
    LOG_TRACE("(%p, %d, %p, %d, %d)", pF, pOwner, pParent_actor, pRef_offset, pAllowed_to_be_absent);

    (void)pF;
    (void)pOwner;
    (void)pParent_actor;
    (void)pRef_offset;
    (void)pAllowed_to_be_absent;
    (void)s;
    (void)str;
    (void)first_time;
    (void)i;
    (void)j;
    (void)the_groove;

    original_AddGroovidelics(pF, pOwner, pParent_actor, pRef_offset, pAllowed_to_be_absent);
}

static void(*original_KillGroovadelic)(int, ...) = (void(*)(int, ...))0x00439009;
CARM95_HOOK_FUNCTION(original_KillGroovadelic, KillGroovadelic)
void KillGroovadelic(int pOwner) {
    int i;
    tGroovidelic_spec *the_groove;
    LOG_TRACE("(%d)", pOwner);

    (void)pOwner;
    (void)i;
    (void)the_groove;

    original_KillGroovadelic(pOwner);
}

static void(*original_KillFunkotronic)(int, ...) = (void(*)(int, ...))0x004390a0;
CARM95_HOOK_FUNCTION(original_KillFunkotronic, KillFunkotronic)
void KillFunkotronic(int pOwner) {
    int i;
    tFunkotronic_spec *the_funk;
    LOG_TRACE("(%d)", pOwner);

    (void)pOwner;
    (void)i;
    (void)the_funk;

    original_KillFunkotronic(pOwner);
}

static br_uint_32(*original_DeleteBastards)(br_actor *, br_matrix34 *, void *, ...) = (br_uint_32(*)(br_actor *, br_matrix34 *, void *, ...))0x0043c666;
CARM95_HOOK_FUNCTION(original_DeleteBastards, DeleteBastards)
br_uint_32 DeleteBastards(br_actor *pActor, br_matrix34 *pMatrix, void *pArg) {
    int i;
    int parent_already_doomed;
    LOG_TRACE("(%p, %p, %p)", pActor, pMatrix, pArg);

    (void)pActor;
    (void)pMatrix;
    (void)pArg;
    (void)i;
    (void)parent_already_doomed;

    return original_DeleteBastards(pActor, pMatrix, pArg);
}

static void(*original_DeleteAnyZeroBastards)() = (void(*)())0x0043c604;
CARM95_HOOK_FUNCTION(original_DeleteAnyZeroBastards, DeleteAnyZeroBastards)
void DeleteAnyZeroBastards() {
    int i;
    LOG_TRACE("()");

    (void)i;

    original_DeleteAnyZeroBastards();
}

static br_uint_32(*original_ApplyTransToModels)(br_actor *, br_matrix34 *, void *, ...) = (br_uint_32(*)(br_actor *, br_matrix34 *, void *, ...))0x0043c775;
CARM95_HOOK_FUNCTION(original_ApplyTransToModels, ApplyTransToModels)
br_uint_32 ApplyTransToModels(br_actor *pActor, br_matrix34 *pMatrix, void *pArg) {
    int i;
    br_vector3 temp_point;
    LOG_TRACE("(%p, %p, %p)", pActor, pMatrix, pArg);

    (void)pActor;
    (void)pMatrix;
    (void)pArg;
    (void)i;
    (void)temp_point;

    return original_ApplyTransToModels(pActor, pMatrix, pArg);
}

static int(*original_FindSpecVolIndex)(br_actor *, ...) = (int(*)(br_actor *, ...))0x00439152;
CARM95_HOOK_FUNCTION(original_FindSpecVolIndex, FindSpecVolIndex)
int FindSpecVolIndex(br_actor *pActor) {
    int i;
    tSpecial_volume *v;
    LOG_TRACE("(%p)", pActor);

    (void)pActor;
    (void)i;
    (void)v;

    return original_FindSpecVolIndex(pActor);
}

static void(*original_MungeMaterial)(br_matrix34 *, br_material *, br_material *, int, int, ...) = (void(*)(br_matrix34 *, br_material *, br_material *, int, int, ...))0x004392c4;
CARM95_HOOK_FUNCTION(original_MungeMaterial, MungeMaterial)
void MungeMaterial(br_matrix34 *pMat, br_material *pMat_1, br_material *pMat_2, int pAxis_0, int pAxis_1) {
    LOG_TRACE("(%p, %p, %p, %d, %d)", pMat, pMat_1, pMat_2, pAxis_0, pAxis_1);

    (void)pMat;
    (void)pMat_1;
    (void)pMat_2;
    (void)pAxis_0;
    (void)pAxis_1;

    original_MungeMaterial(pMat, pMat_1, pMat_2, pAxis_0, pAxis_1);
}

static void(*original_SetSpecVolMatSize)(br_actor *, ...) = (void(*)(br_actor *, ...))0x00439226;
CARM95_HOOK_FUNCTION(original_SetSpecVolMatSize, SetSpecVolMatSize)
void SetSpecVolMatSize(br_actor *pActor) {
    br_model *model;
    LOG_TRACE("(%p)", pActor);

    (void)pActor;
    (void)model;

    original_SetSpecVolMatSize(pActor);
}

static void(*original_FindInverseAndWorldBox)(tSpecial_volume *, ...) = (void(*)(tSpecial_volume *, ...))0x004393a7;
CARM95_HOOK_FUNCTION(original_FindInverseAndWorldBox, FindInverseAndWorldBox)
void FindInverseAndWorldBox(tSpecial_volume *pSpec) {
    br_bounds bnds;
    LOG_TRACE("(%p)", pSpec);

    (void)pSpec;
    (void)bnds;

    original_FindInverseAndWorldBox(pSpec);
}

static void(*original_UpdateSpecVol)() = (void(*)())0x004391b7;
CARM95_HOOK_FUNCTION(original_UpdateSpecVol, UpdateSpecVol)
void UpdateSpecVol() {
    int index;
    tSpecial_volume *v;
    LOG_TRACE("()");

    (void)index;
    (void)v;

    original_UpdateSpecVol();
}

static void(*original_SaveSpecialVolumes)() = (void(*)())0x0043c853;
CARM95_HOOK_FUNCTION(original_SaveSpecialVolumes, SaveSpecialVolumes)
void SaveSpecialVolumes() {
    tPath_name the_path;
    FILE *f;
    int i;
    tSpecial_volume *v;
    LOG_TRACE("()");

    (void)the_path;
    (void)f;
    (void)i;
    (void)v;

    original_SaveSpecialVolumes();
}

static void(*original_SaveAdditionalStuff)() = (void(*)())0x0043c589;
CARM95_HOOK_FUNCTION(original_SaveAdditionalStuff, SaveAdditionalStuff)
void SaveAdditionalStuff() {
    LOG_TRACE("()");


    original_SaveAdditionalStuff();
}

br_uint_32 ProcessMaterials(br_actor *pActor, tPMFM2CB pCallback) {
    LOG_TRACE("(%p, %p)", pActor, pCallback);

    (void)pActor;
    (void)pCallback;

    NOT_IMPLEMENTED();
}

br_uint_32 ProcessFaceMaterials2(br_actor *pActor, tPMFM2CB pCallback) {
    LOG_TRACE("(%p, %p)", pActor, pCallback);

    (void)pActor;
    (void)pCallback;

    NOT_IMPLEMENTED();
}

void ChangePerspToSubdivCB(br_material *pMaterial) {
    LOG_TRACE("(%p)", pMaterial);

    (void)pMaterial;

    NOT_IMPLEMENTED();
}

void ChangePerspToSubdiv() {
    LOG_TRACE("()");


    NOT_IMPLEMENTED();
}

void ChangeSubdivToPerspCB(br_material *pMaterial) {
    LOG_TRACE("(%p)", pMaterial);

    (void)pMaterial;

    NOT_IMPLEMENTED();
}

void ChangeSubdivToPersp() {
    LOG_TRACE("()");


    NOT_IMPLEMENTED();
}

static br_uint_32(*original_ProcessFaceMaterials)(br_actor *, tPMFMCB*, ...) = (br_uint_32(*)(br_actor *, tPMFMCB*, ...))0x00439ddd;
CARM95_HOOK_FUNCTION(original_ProcessFaceMaterials, ProcessFaceMaterials)
br_uint_32 ProcessFaceMaterials(br_actor *pActor, tPMFMCB pCallback) {
    LOG_TRACE("(%p, %p)", pActor, pCallback);

    (void)pActor;
    (void)pCallback;

    return original_ProcessFaceMaterials(pActor, pCallback);
}

static int(*original_DRPixelmapHasZeros)(br_pixelmap *, ...) = (int(*)(br_pixelmap *, ...))0x00439597;
CARM95_HOOK_FUNCTION(original_DRPixelmapHasZeros, DRPixelmapHasZeros)
int DRPixelmapHasZeros(br_pixelmap *pm) {
    int x;
    int y;
    char *row_ptr;
    char *pp;
    LOG_TRACE("(%p)", pm);

    (void)pm;
    (void)x;
    (void)y;
    (void)row_ptr;
    (void)pp;

    return original_DRPixelmapHasZeros(pm);
}

static int(*original_StorageContainsPixelmap)(tBrender_storage *, br_pixelmap *, ...) = (int(*)(tBrender_storage *, br_pixelmap *, ...))0x00439668;
CARM95_HOOK_FUNCTION(original_StorageContainsPixelmap, StorageContainsPixelmap)
int StorageContainsPixelmap(tBrender_storage *pStorage, br_pixelmap *pMap) {
    int i;
    LOG_TRACE("(%p, %p)", pStorage, pMap);

    (void)pStorage;
    (void)pMap;
    (void)i;

    return original_StorageContainsPixelmap(pStorage, pMap);
}

static void(*original_HideStoredOpaqueTextures)(tBrender_storage *, ...) = (void(*)(tBrender_storage *, ...))0x004394b4;
CARM95_HOOK_FUNCTION(original_HideStoredOpaqueTextures, HideStoredOpaqueTextures)
void HideStoredOpaqueTextures(tBrender_storage *pStorage) {
    int i;
    LOG_TRACE("(%p)", pStorage);

    (void)pStorage;
    (void)i;

    original_HideStoredOpaqueTextures(pStorage);
}

static void(*original_RevealStoredTransparentTextures)(tBrender_storage *, ...) = (void(*)(tBrender_storage *, ...))0x004396ce;
CARM95_HOOK_FUNCTION(original_RevealStoredTransparentTextures, RevealStoredTransparentTextures)
void RevealStoredTransparentTextures(tBrender_storage *pStorage) {
    int i;
    LOG_TRACE("(%p)", pStorage);

    (void)pStorage;
    (void)i;

    original_RevealStoredTransparentTextures(pStorage);
}

static void(*original_HideStoredTextures)(tBrender_storage *, ...) = (void(*)(tBrender_storage *, ...))0x00439784;
CARM95_HOOK_FUNCTION(original_HideStoredTextures, HideStoredTextures)
void HideStoredTextures(tBrender_storage *pStorage) {
    int i;
    LOG_TRACE("(%p)", pStorage);

    (void)pStorage;
    (void)i;

    original_HideStoredTextures(pStorage);
}

static void(*original_RevealStoredTextures)(tBrender_storage *, ...) = (void(*)(tBrender_storage *, ...))0x00439847;
CARM95_HOOK_FUNCTION(original_RevealStoredTextures, RevealStoredTextures)
void RevealStoredTextures(tBrender_storage *pStorage) {
    int i;
    LOG_TRACE("(%p)", pStorage);

    (void)pStorage;
    (void)i;

    original_RevealStoredTextures(pStorage);
}

static void(*original_SetCarStorageTexturingLevel)(tBrender_storage *, tCar_texturing_level, tCar_texturing_level, ...) = (void(*)(tBrender_storage *, tCar_texturing_level, tCar_texturing_level, ...))0x0043940b;
CARM95_HOOK_FUNCTION(original_SetCarStorageTexturingLevel, SetCarStorageTexturingLevel)
void SetCarStorageTexturingLevel(tBrender_storage *pStorage, tCar_texturing_level pNew, tCar_texturing_level pOld) {
    LOG_TRACE("(%p, %d, %d)", pStorage, pNew, pOld);

    (void)pStorage;
    (void)pNew;
    (void)pOld;

    original_SetCarStorageTexturingLevel(pStorage, pNew, pOld);
}

static tCar_texturing_level(*original_GetCarTexturingLevel)() = (tCar_texturing_level(*)())0x004398e0;
CARM95_HOOK_FUNCTION(original_GetCarTexturingLevel, GetCarTexturingLevel)
tCar_texturing_level GetCarTexturingLevel() {
    LOG_TRACE("()");


    return original_GetCarTexturingLevel();
}

static void(*original_SetCarTexturingLevel)(tCar_texturing_level, ...) = (void(*)(tCar_texturing_level, ...))0x004398f5;
CARM95_HOOK_FUNCTION(original_SetCarTexturingLevel, SetCarTexturingLevel)
void SetCarTexturingLevel(tCar_texturing_level pLevel) {
    LOG_TRACE("(%d)", pLevel);

    (void)pLevel;

    original_SetCarTexturingLevel(pLevel);
}

static int(*original_HasThisSuffix)(char *, char *, ...) = (int(*)(char *, char *, ...))0x00439a77;
CARM95_HOOK_FUNCTION(original_HasThisSuffix, HasThisSuffix)
int HasThisSuffix(char *pIdent, char *pSuffix) {
    size_t len_ident;
    size_t len_suffix;
    LOG_TRACE("(\"%s\", \"%s\")", pIdent, pSuffix);

    (void)pIdent;
    (void)pSuffix;
    (void)len_ident;
    (void)len_suffix;

    return original_HasThisSuffix(pIdent, pSuffix);
}

static br_material *(*original_UnsuffixedMaterial)(char *, char *, ...) = (br_material *(*)(char *, char *, ...))0x00439bf4;
CARM95_HOOK_FUNCTION(original_UnsuffixedMaterial, UnsuffixedMaterial)
br_material* UnsuffixedMaterial(char *pOld_ident, char *pSuffix) {
    br_material *result;
    int unsuffixed_len;
    char *new_id;
    LOG_TRACE("(\"%s\", \"%s\")", pOld_ident, pSuffix);

    (void)pOld_ident;
    (void)pSuffix;
    (void)result;
    (void)unsuffixed_len;
    (void)new_id;

    return original_UnsuffixedMaterial(pOld_ident, pSuffix);
}

static br_material *(*original_RoadUntexToPersp)(br_model *, tU16, ...) = (br_material *(*)(br_model *, tU16, ...))0x00439e59;
CARM95_HOOK_FUNCTION(original_RoadUntexToPersp, RoadUntexToPersp)
br_material* RoadUntexToPersp(br_model *pModel, tU16 pFace) {
    br_material *old_mat;
    br_material *new_mat;
    LOG_TRACE("(%p, %u)", pModel, pFace);

    (void)pModel;
    (void)pFace;
    (void)old_mat;
    (void)new_mat;

    return original_RoadUntexToPersp(pModel, pFace);
}

static br_material *(*original_WallLinearToUntex)(br_model *, tU16, ...) = (br_material *(*)(br_model *, tU16, ...))0x00439983;
CARM95_HOOK_FUNCTION(original_WallLinearToUntex, WallLinearToUntex)
br_material* WallLinearToUntex(br_model *pModel, tU16 pFace) {
    br_material *old_mat;
    br_material *new_mat;
    LOG_TRACE("(%p, %u)", pModel, pFace);

    (void)pModel;
    (void)pFace;
    (void)old_mat;
    (void)new_mat;

    return original_WallLinearToUntex(pModel, pFace);
}

static br_material *(*original_WallUntexToLinear)(br_model *, tU16, ...) = (br_material *(*)(br_model *, tU16, ...))0x00439b2e;
CARM95_HOOK_FUNCTION(original_WallUntexToLinear, WallUntexToLinear)
br_material* WallUntexToLinear(br_model *pModel, tU16 pFace) {
    br_material *old_mat;
    br_material *new_mat;
    LOG_TRACE("(%p, %u)", pModel, pFace);

    (void)pModel;
    (void)pFace;
    (void)old_mat;
    (void)new_mat;

    return original_WallUntexToLinear(pModel, pFace);
}

static br_material *(*original_WallUntexToPersp)(br_model *, tU16, ...) = (br_material *(*)(br_model *, tU16, ...))0x00439c7a;
CARM95_HOOK_FUNCTION(original_WallUntexToPersp, WallUntexToPersp)
br_material* WallUntexToPersp(br_model *pModel, tU16 pFace) {
    br_material *old_mat;
    br_material *new_mat;
    LOG_TRACE("(%p, %u)", pModel, pFace);

    (void)pModel;
    (void)pFace;
    (void)old_mat;
    (void)new_mat;

    return original_WallUntexToPersp(pModel, pFace);
}

static br_material *(*original_WallLinearToPersp)(br_model *, tU16, ...) = (br_material *(*)(br_model *, tU16, ...))0x00439d11;
CARM95_HOOK_FUNCTION(original_WallLinearToPersp, WallLinearToPersp)
br_material* WallLinearToPersp(br_model *pModel, tU16 pFace) {
    br_material *old_mat;
    br_material *new_mat;
    LOG_TRACE("(%p, %u)", pModel, pFace);

    (void)pModel;
    (void)pFace;
    (void)old_mat;
    (void)new_mat;

    return original_WallLinearToPersp(pModel, pFace);
}

static tRoad_texturing_level(*original_GetRoadTexturingLevel)() = (tRoad_texturing_level(*)())0x00439d73;
CARM95_HOOK_FUNCTION(original_GetRoadTexturingLevel, GetRoadTexturingLevel)
tRoad_texturing_level GetRoadTexturingLevel() {
    LOG_TRACE("()");


    return original_GetRoadTexturingLevel();
}

static void(*original_SetRoadTexturingLevel)(tRoad_texturing_level, ...) = (void(*)(tRoad_texturing_level, ...))0x00439d88;
CARM95_HOOK_FUNCTION(original_SetRoadTexturingLevel, SetRoadTexturingLevel)
void SetRoadTexturingLevel(tRoad_texturing_level pLevel) {
    LOG_TRACE("(%d)", pLevel);

    (void)pLevel;

    original_SetRoadTexturingLevel(pLevel);
}

static void(*original_ReallySetRoadTexturingLevel)(tRoad_texturing_level, ...) = (void(*)(tRoad_texturing_level, ...))0x00439d9b;
CARM95_HOOK_FUNCTION(original_ReallySetRoadTexturingLevel, ReallySetRoadTexturingLevel)
void ReallySetRoadTexturingLevel(tRoad_texturing_level pLevel) {
    LOG_TRACE("(%d)", pLevel);

    (void)pLevel;

    original_ReallySetRoadTexturingLevel(pLevel);
}

static tWall_texturing_level(*original_GetWallTexturingLevel)() = (tWall_texturing_level(*)())0x00439ec1;
CARM95_HOOK_FUNCTION(original_GetWallTexturingLevel, GetWallTexturingLevel)
tWall_texturing_level GetWallTexturingLevel() {
    LOG_TRACE("()");


    return original_GetWallTexturingLevel();
}

static void(*original_SetWallTexturingLevel)(tWall_texturing_level, ...) = (void(*)(tWall_texturing_level, ...))0x00439ed6;
CARM95_HOOK_FUNCTION(original_SetWallTexturingLevel, SetWallTexturingLevel)
void SetWallTexturingLevel(tWall_texturing_level pLevel) {
    LOG_TRACE("(%d)", pLevel);

    (void)pLevel;

    original_SetWallTexturingLevel(pLevel);
}

static void(*original_ReallySetWallTexturingLevel)(tWall_texturing_level, ...) = (void(*)(tWall_texturing_level, ...))0x00439ee9;
CARM95_HOOK_FUNCTION(original_ReallySetWallTexturingLevel, ReallySetWallTexturingLevel)
void ReallySetWallTexturingLevel(tWall_texturing_level pLevel) {
    static tPMFMCB*tweaker[3][3];
    LOG_TRACE("(%d)", pLevel);

    (void)pLevel;
    (void)tweaker;

    original_ReallySetWallTexturingLevel(pLevel);
}

static br_material *(*original_DisposeSuffixedMaterials)(br_model *, tU16, ...) = (br_material *(*)(br_model *, tU16, ...))0x0043cdec;
CARM95_HOOK_FUNCTION(original_DisposeSuffixedMaterials, DisposeSuffixedMaterials)
br_material* DisposeSuffixedMaterials(br_model *pModel, tU16 pFace) {
    size_t max_suffix_len;
    br_material *mat;
    br_material *victim;
    static char *suffixes[3];
    int s;
    char *id;
    LOG_TRACE("(%p, %u)", pModel, pFace);

    (void)pModel;
    (void)pFace;
    (void)max_suffix_len;
    (void)mat;
    (void)victim;
    (void)suffixes;
    (void)s;
    (void)id;

    return original_DisposeSuffixedMaterials(pModel, pFace);
}

static void(*original_DisposeTexturingMaterials)() = (void(*)())0x0043cd4f;
CARM95_HOOK_FUNCTION(original_DisposeTexturingMaterials, DisposeTexturingMaterials)
void DisposeTexturingMaterials() {
    LOG_TRACE("()");


    original_DisposeTexturingMaterials();
}

static br_uint_32(*original_SetAccessoryRenderingCB)(br_actor *, void *, ...) = (br_uint_32(*)(br_actor *, void *, ...))0x00439f27;
CARM95_HOOK_FUNCTION(original_SetAccessoryRenderingCB, SetAccessoryRenderingCB)
br_uint_32 SetAccessoryRenderingCB(br_actor *pActor, void *pFlag) {
    LOG_TRACE("(%p, %p)", pActor, pFlag);

    (void)pActor;
    (void)pFlag;

    return original_SetAccessoryRenderingCB(pActor, pFlag);
}

static void(*original_SetAccessoryRendering)(int, ...) = (void(*)(int, ...))0x00439f63;
CARM95_HOOK_FUNCTION(original_SetAccessoryRendering, SetAccessoryRendering)
void SetAccessoryRendering(int pOn) {
    int style;
    LOG_TRACE("(%d)", pOn);

    (void)pOn;
    (void)style;

    original_SetAccessoryRendering(pOn);
}

static int(*original_GetAccessoryRendering)() = (int(*)())0x00439fba;
CARM95_HOOK_FUNCTION(original_GetAccessoryRendering, GetAccessoryRendering)
int GetAccessoryRendering() {
    LOG_TRACE("()");


    return original_GetAccessoryRendering();
}

static void(*original_SetCarSimplificationLevel)(int, ...) = (void(*)(int, ...))0x00439fcf;
CARM95_HOOK_FUNCTION(original_SetCarSimplificationLevel, SetCarSimplificationLevel)
void SetCarSimplificationLevel(int pLevel) {
    LOG_TRACE("(%d)", pLevel);

    (void)pLevel;

    original_SetCarSimplificationLevel(pLevel);
}

static int(*original_GetCarSimplificationLevel)() = (int(*)())0x00439fe2;
CARM95_HOOK_FUNCTION(original_GetCarSimplificationLevel, GetCarSimplificationLevel)
int GetCarSimplificationLevel() {
    LOG_TRACE("()");


    return original_GetCarSimplificationLevel();
}

static void(*original_ParseSpecialVolume)(FILE *, tSpecial_volume *, char *, ...) = (void(*)(FILE *, tSpecial_volume *, char *, ...))0x00439ff7;
CARM95_HOOK_FUNCTION(original_ParseSpecialVolume, ParseSpecialVolume)
void ParseSpecialVolume(FILE *pF, tSpecial_volume *pSpec, char *pScreen_name_str) {
    char s[256];
    LOG_TRACE("(%p, %p, \"%s\")", pF, pSpec, pScreen_name_str);

    (void)pF;
    (void)pSpec;
    (void)pScreen_name_str;
    (void)s;

    original_ParseSpecialVolume(pF, pSpec, pScreen_name_str);
}

void AddExceptionToList(tException_list *pDst, tException_list pNew) {
    LOG_TRACE("(%p, %p)", pDst, pNew);

    (void)pDst;
    (void)pNew;

    NOT_IMPLEMENTED();
}

void LoadExceptionsFile(char *pName) {
    FILE *f;
    char line[256];
    char *tok;
    int file_version;
    tException_list e;
    char delimiters[4];
    LOG_TRACE("(\"%s\")", pName);

    (void)pName;
    (void)f;
    (void)line;
    (void)tok;
    (void)file_version;
    (void)e;
    (void)delimiters;

    NOT_IMPLEMENTED();
}

void LoadExceptionsFileForTrack(char *pTrack_file_name) {
    tPath_name exceptions_file_name;
    LOG_TRACE("(\"%s\")", pTrack_file_name);

    (void)pTrack_file_name;
    (void)exceptions_file_name;

    NOT_IMPLEMENTED();
}

void FreeExceptions() {
    tException_list list;
    tException_list next;
    LOG_TRACE("()");

    (void)list;
    (void)next;

    NOT_IMPLEMENTED();
}

static void(*original_LoadTrack)(char *, tTrack_spec *, tRace_info *, ...) = (void(*)(char *, tTrack_spec *, tRace_info *, ...))0x0043a136;
CARM95_HOOK_FUNCTION(original_LoadTrack, LoadTrack)
void LoadTrack(char *pFile_name, tTrack_spec *pTrack_spec, tRace_info *pRace_info) {
    char temp_name[14];
    FILE *f;
    FILE *non_car_f;
    FILE *g;
    int i;
    int j;
    int k;
    int group;
    int needs_updating;
    int killed_sky;
    int line_count;
    int ped_subs_index;
    int sl;
    int num_materials;
    int count;
    int num_non_cars;
    int style;
    int cp_rect_w[2];
    int cp_rect_h[2];
    tPath_name the_path;
    tPath_name general_file_path;
    char s[256];
    char *str;
    float temp_float;
    br_actor *new_root;
    br_vector3 a;
    br_vector3 b;
    tU16 sky_pixels_high;
    tNon_car_spec *non_car;
    tSpecial_volume *spec;
    br_vector3 p[3];
    br_vector3 v1;
    br_vector3 v2;
    br_vector3 temp_v;
    br_bounds temp_bounds;
    tPed_subs *ped_subs;
    br_pixelmap *sky;
    br_material *material;
    LOG_TRACE("(\"%s\", %p, %p)", pFile_name, pTrack_spec, pRace_info);

    (void)pFile_name;
    (void)pTrack_spec;
    (void)pRace_info;
    (void)temp_name;
    (void)f;
    (void)non_car_f;
    (void)g;
    (void)i;
    (void)j;
    (void)k;
    (void)group;
    (void)needs_updating;
    (void)killed_sky;
    (void)line_count;
    (void)ped_subs_index;
    (void)sl;
    (void)num_materials;
    (void)count;
    (void)num_non_cars;
    (void)style;
    (void)cp_rect_w;
    (void)cp_rect_h;
    (void)the_path;
    (void)general_file_path;
    (void)s;
    (void)str;
    (void)temp_float;
    (void)new_root;
    (void)a;
    (void)b;
    (void)sky_pixels_high;
    (void)non_car;
    (void)spec;
    (void)p;
    (void)v1;
    (void)v2;
    (void)temp_v;
    (void)temp_bounds;
    (void)ped_subs;
    (void)sky;
    (void)material;

    original_LoadTrack(pFile_name, pTrack_spec, pRace_info);
}

static br_uint_32(*original_RemoveBounds)(br_actor *, void *, ...) = (br_uint_32(*)(br_actor *, void *, ...))0x0043cf3f;
CARM95_HOOK_FUNCTION(original_RemoveBounds, RemoveBounds)
br_uint_32 RemoveBounds(br_actor *pActor, void *pArg) {
    LOG_TRACE("(%p, %p)", pActor, pArg);

    (void)pActor;
    (void)pArg;

    return original_RemoveBounds(pActor, pArg);
}

static void(*original_RemoveBoundsStructures)(br_actor *, ...) = (void(*)(br_actor *, ...))0x0043cf21;
CARM95_HOOK_FUNCTION(original_RemoveBoundsStructures, RemoveBoundsStructures)
void RemoveBoundsStructures(br_actor *pActor) {
    LOG_TRACE("(%p)", pActor);

    (void)pActor;

    original_RemoveBoundsStructures(pActor);
}

static void(*original_FreeTrack)(tTrack_spec *, ...) = (void(*)(tTrack_spec *, ...))0x0043cb89;
CARM95_HOOK_FUNCTION(original_FreeTrack, FreeTrack)
void FreeTrack(tTrack_spec *pTrack_spec) {
    int i;
    tNon_car_spec *non_car;
    LOG_TRACE("(%p)", pTrack_spec);

    (void)pTrack_spec;
    (void)i;
    (void)non_car;

    original_FreeTrack(pTrack_spec);
}

static void(*original_ProcessTrack)(br_actor *, tTrack_spec *, br_actor *, br_matrix34 *, int, ...) = (void(*)(br_actor *, tTrack_spec *, br_actor *, br_matrix34 *, int, ...))0x0043cf8c;
CARM95_HOOK_FUNCTION(original_ProcessTrack, ProcessTrack)
void ProcessTrack(br_actor *pWorld, tTrack_spec *pTrack_spec, br_actor *pCamera, br_matrix34 *pCamera_to_world_transform, int pRender_blends) {
    LOG_TRACE("(%p, %p, %p, %p, %d)", pWorld, pTrack_spec, pCamera, pCamera_to_world_transform, pRender_blends);

    (void)pWorld;
    (void)pTrack_spec;
    (void)pCamera;
    (void)pCamera_to_world_transform;
    (void)pRender_blends;

    original_ProcessTrack(pWorld, pTrack_spec, pCamera, pCamera_to_world_transform, pRender_blends);
}

static br_scalar(*original_NormaliseDegreeAngle)(br_scalar, ...) = (br_scalar(*)(br_scalar, ...))0x0043cfd8;
CARM95_HOOK_FUNCTION(original_NormaliseDegreeAngle, NormaliseDegreeAngle)
br_scalar NormaliseDegreeAngle(br_scalar pAngle) {
    LOG_TRACE("(%f)", pAngle);

    (void)pAngle;

    return original_NormaliseDegreeAngle(pAngle);
}

static void(*original_FunkThoseTronics)() = (void(*)())0x0043d010;
CARM95_HOOK_FUNCTION(original_FunkThoseTronics, FunkThoseTronics)
void FunkThoseTronics() {
    int i;
    int j;
    int iteration_count;
    int finished;
    tFunkotronic_spec *the_funk;
    br_vector3 *the_proximity;
    tS32 the_time;
    tS32 old_last_time;
    tS32 time_diff;
    br_matrix23 *mat_matrix;
    br_material *the_material;
    float f_the_time;
    float rot_amount;
    float f_time_diff;
    br_pixelmap *old_colour_map;
    LOG_TRACE("()");

    (void)i;
    (void)j;
    (void)iteration_count;
    (void)finished;
    (void)the_funk;
    (void)the_proximity;
    (void)the_time;
    (void)old_last_time;
    (void)time_diff;
    (void)mat_matrix;
    (void)the_material;
    (void)f_the_time;
    (void)rot_amount;
    (void)f_time_diff;
    (void)old_colour_map;

    original_FunkThoseTronics();
}

static void(*original_LollipopizeActor)(br_actor *, br_matrix34 *, tLollipop_mode, ...) = (void(*)(br_actor *, br_matrix34 *, tLollipop_mode, ...))0x0043f3c3;
CARM95_HOOK_FUNCTION(original_LollipopizeActor, LollipopizeActor)
void LollipopizeActor(br_actor *pSubject_actor, br_matrix34 *ref_to_world, tLollipop_mode pWhich_axis) {
    br_vector3 ref_to_subject;
    br_vector3 fixed_axis;
    br_vector3 vector_a;
    br_vector3 vector_b;
    br_matrix34 subject_to_world;
    br_matrix34 mat;
    br_scalar __block0___scale;
    LOG_TRACE("(%p, %p, %d)", pSubject_actor, ref_to_world, pWhich_axis);

    (void)pSubject_actor;
    (void)ref_to_world;
    (void)pWhich_axis;
    (void)ref_to_subject;
    (void)fixed_axis;
    (void)vector_a;
    (void)vector_b;
    (void)subject_to_world;
    (void)mat;

    original_LollipopizeActor(pSubject_actor, ref_to_world, pWhich_axis);
}

static void(*original_CalcActorGlobalPos)(br_vector3 *, br_actor *, ...) = (void(*)(br_vector3 *, br_actor *, ...))0x0043f6c2;
CARM95_HOOK_FUNCTION(original_CalcActorGlobalPos, CalcActorGlobalPos)
void CalcActorGlobalPos(br_vector3 *pResult, br_actor *pActor) {
    LOG_TRACE("(%p, %p)", pResult, pActor);

    (void)pResult;
    (void)pActor;

    original_CalcActorGlobalPos(pResult, pActor);
}

static int(*original_PointOutOfSight)(br_vector3 *, br_scalar, ...) = (int(*)(br_vector3 *, br_scalar, ...))0x0043f744;
CARM95_HOOK_FUNCTION(original_PointOutOfSight, PointOutOfSight)
int PointOutOfSight(br_vector3 *pPoint, br_scalar pMax_distance) {
    br_vector3 distance_vector;
    LOG_TRACE("(%p, %f)", pPoint, pMax_distance);

    (void)pPoint;
    (void)pMax_distance;
    (void)distance_vector;

    return original_PointOutOfSight(pPoint, pMax_distance);
}

static void(*original_PathGrooveBastard)(tGroovidelic_spec *, tU32, br_matrix34 *, int, ...) = (void(*)(tGroovidelic_spec *, tU32, br_matrix34 *, int, ...))0x0043fb08;
CARM95_HOOK_FUNCTION(original_PathGrooveBastard, PathGrooveBastard)
void PathGrooveBastard(tGroovidelic_spec *pGroove, tU32 pTime, br_matrix34 *pMat, int pInterrupt_it) {
    br_scalar pos;
    LOG_TRACE("(%p, %u, %p, %d)", pGroove, pTime, pMat, pInterrupt_it);

    (void)pGroove;
    (void)pTime;
    (void)pMat;
    (void)pInterrupt_it;
    (void)pos;

    original_PathGrooveBastard(pGroove, pTime, pMat, pInterrupt_it);
}

void ObjectGrooveBastard(tGroovidelic_spec *pGroove, tU32 pTime, br_matrix34 *pMat, int pInterrupt_it) {
    int rock_it;
    br_scalar x_size;
    br_scalar y_size;
    br_scalar z_size;
    br_scalar pos;
    br_bounds *bounds;
    LOG_TRACE("(%p, %u, %p, %d)", pGroove, pTime, pMat, pInterrupt_it);

    (void)pGroove;
    (void)pTime;
    (void)pMat;
    (void)pInterrupt_it;
    (void)rock_it;
    (void)x_size;
    (void)y_size;
    (void)z_size;
    (void)pos;
    (void)bounds;

    NOT_IMPLEMENTED();
}

static void(*original_GrooveThisDelic)(tGroovidelic_spec *, tU32, int, ...) = (void(*)(tGroovidelic_spec *, tU32, int, ...))0x0043f886;
CARM95_HOOK_FUNCTION(original_GrooveThisDelic, GrooveThisDelic)
void GrooveThisDelic(tGroovidelic_spec *pGroove, tU32 pTime, int pInterrupt_it) {
    br_actor *the_actor;
    br_vector3 actor_pos;
    br_matrix34 *the_mat;
    tInterrupt_status old_path_interrupt;
    tInterrupt_status old_object_interrupt;
    LOG_TRACE("(%p, %u, %d)", pGroove, pTime, pInterrupt_it);

    (void)pGroove;
    (void)pTime;
    (void)pInterrupt_it;
    (void)the_actor;
    (void)actor_pos;
    (void)the_mat;
    (void)old_path_interrupt;
    (void)old_object_interrupt;

    original_GrooveThisDelic(pGroove, pTime, pInterrupt_it);
}

static void(*original_GrooveThoseDelics)() = (void(*)())0x004430dd;
CARM95_HOOK_FUNCTION(original_GrooveThoseDelics, GrooveThoseDelics)
void GrooveThoseDelics() {
    int i;
    tGroovidelic_spec *the_groove;
    float f_the_time;
    LOG_TRACE("()");

    (void)i;
    (void)the_groove;
    (void)f_the_time;

    original_GrooveThoseDelics();
}

static void(*original_StopGroovidelic)(br_actor *, ...) = (void(*)(br_actor *, ...))0x00443186;
CARM95_HOOK_FUNCTION(original_StopGroovidelic, StopGroovidelic)
void StopGroovidelic(br_actor *pActor) {
    int i;
    tGroovidelic_spec *the_groove;
    LOG_TRACE("(%p)", pActor);

    (void)pActor;
    (void)i;
    (void)the_groove;

    original_StopGroovidelic(pActor);
}

static void(*original_SetGrooveInterrupt)(int, br_matrix34 *, int, int, float, float, ...) = (void(*)(int, br_matrix34 *, int, int, float, float, ...))0x00443208;
CARM95_HOOK_FUNCTION(original_SetGrooveInterrupt, SetGrooveInterrupt)
void SetGrooveInterrupt(int pGroove_index, br_matrix34 *pMatrix, int pPath_interrupt, int pObject_interrupt, float pPath_resumption, float pObject_resumption) {
    tGroovidelic_spec *the_groove;
    LOG_TRACE("(%d, %p, %d, %d, %f, %f)", pGroove_index, pMatrix, pPath_interrupt, pObject_interrupt, pPath_resumption, pObject_resumption);

    (void)pGroove_index;
    (void)pMatrix;
    (void)pPath_interrupt;
    (void)pObject_interrupt;
    (void)pPath_resumption;
    (void)pObject_resumption;
    (void)the_groove;

    original_SetGrooveInterrupt(pGroove_index, pMatrix, pPath_interrupt, pObject_interrupt, pPath_resumption, pObject_resumption);
}

static void(*original_ResetGrooveFlags)() = (void(*)())0x0044325f;
CARM95_HOOK_FUNCTION(original_ResetGrooveFlags, ResetGrooveFlags)
void ResetGrooveFlags() {
    int i;
    tGroovidelic_spec *the_groove;
    LOG_TRACE("()");

    (void)i;
    (void)the_groove;

    original_ResetGrooveFlags();
}

static tSpecial_volume *(*original_GetDefaultSpecialVolumeForWater)() = (tSpecial_volume *(*)())0x004432a9;
CARM95_HOOK_FUNCTION(original_GetDefaultSpecialVolumeForWater, GetDefaultSpecialVolumeForWater)
tSpecial_volume* GetDefaultSpecialVolumeForWater() {
    LOG_TRACE("()");


    return original_GetDefaultSpecialVolumeForWater();
}

static tSpecial_volume *(*original_FindSpecialVolume)(br_vector3 *, tSpecial_volume *, ...) = (tSpecial_volume *(*)(br_vector3 *, tSpecial_volume *, ...))0x004432be;
CARM95_HOOK_FUNCTION(original_FindSpecialVolume, FindSpecialVolume)
tSpecial_volume* FindSpecialVolume(br_vector3 *pP, tSpecial_volume *pLast_vol) {
    int i;
    tSpecial_volume *v;
    br_vector3 p;
    LOG_TRACE("(%p, %p)", pP, pLast_vol);

    (void)pP;
    (void)pLast_vol;
    (void)i;
    (void)v;
    (void)p;

    return original_FindSpecialVolume(pP, pLast_vol);
}

static void(*original_SaveAdditionalActors)() = (void(*)())0x00443448;
CARM95_HOOK_FUNCTION(original_SaveAdditionalActors, SaveAdditionalActors)
void SaveAdditionalActors() {
    LOG_TRACE("()");


    original_SaveAdditionalActors();
}

static br_scalar(*original_DistanceFromFace)(br_vector3 *, tFace_ref *, ...) = (br_scalar(*)(br_vector3 *, tFace_ref *, ...))0x00443465;
CARM95_HOOK_FUNCTION(original_DistanceFromFace, DistanceFromFace)
br_scalar DistanceFromFace(br_vector3 *pPos, tFace_ref *pFace) {
    br_vector3 normal;
    LOG_TRACE("(%p, %p)", pPos, pFace);

    (void)pPos;
    (void)pFace;
    (void)normal;

    return original_DistanceFromFace(pPos, pFace);
}

static br_uint_32(*original_CalcHighestID)(br_actor *, int *, ...) = (br_uint_32(*)(br_actor *, int *, ...))0x00443e52;
CARM95_HOOK_FUNCTION(original_CalcHighestID, CalcHighestID)
br_uint_32 CalcHighestID(br_actor *pActor, int *pHighest) {
    char s[256];
    int number;
    LOG_TRACE("(%p, %p)", pActor, pHighest);

    (void)pActor;
    (void)pHighest;
    (void)s;
    (void)number;

    return original_CalcHighestID(pActor, pHighest);
}

static br_uint_32(*original_SetID)(br_actor *, void *, ...) = (br_uint_32(*)(br_actor *, void *, ...))0x004435e0;
CARM95_HOOK_FUNCTION(original_SetID, SetID)
br_uint_32 SetID(br_actor *pActor, void *pArg) {
    char s[256];
    LOG_TRACE("(%p, %p)", pActor, pArg);

    (void)pActor;
    (void)pArg;
    (void)s;

    return original_SetID(pActor, pArg);
}

static void(*original_UniquificateActorsName)(br_actor *, br_actor *, ...) = (void(*)(br_actor *, br_actor *, ...))0x004434a5;
CARM95_HOOK_FUNCTION(original_UniquificateActorsName, UniquificateActorsName)
void UniquificateActorsName(br_actor *pUniverse_actor, br_actor *pActor) {
    int highest;
    LOG_TRACE("(%p, %p)", pUniverse_actor, pActor);

    (void)pUniverse_actor;
    (void)pActor;
    (void)highest;

    original_UniquificateActorsName(pUniverse_actor, pActor);
}

static void(*original_AccessoryHeadup)(br_actor *, char *, ...) = (void(*)(br_actor *, char *, ...))0x00443d5b;
CARM95_HOOK_FUNCTION(original_AccessoryHeadup, AccessoryHeadup)
void AccessoryHeadup(br_actor *pActor, char *pPrefix) {
    char s[256];
    int i;
    br_actor *original_actor;
    LOG_TRACE("(%p, \"%s\")", pActor, pPrefix);

    (void)pActor;
    (void)pPrefix;
    (void)s;
    (void)i;
    (void)original_actor;

    original_AccessoryHeadup(pActor, pPrefix);
}

static br_uint_32(*original_CalcHighestNonAmID)(br_actor *, int *, ...) = (br_uint_32(*)(br_actor *, int *, ...))0x00443504;
CARM95_HOOK_FUNCTION(original_CalcHighestNonAmID, CalcHighestNonAmID)
br_uint_32 CalcHighestNonAmID(br_actor *pActor, int *pHighest) {
    char s[256];
    int number;
    LOG_TRACE("(%p, %p)", pActor, pHighest);

    (void)pActor;
    (void)pHighest;
    (void)s;
    (void)number;

    return original_CalcHighestNonAmID(pActor, pHighest);
}

static br_uint_32(*original_SetIDAndDupModel)(br_actor *, void *, ...) = (br_uint_32(*)(br_actor *, void *, ...))0x00443ef5;
CARM95_HOOK_FUNCTION(original_SetIDAndDupModel, SetIDAndDupModel)
br_uint_32 SetIDAndDupModel(br_actor *pActor, void *pArg) {
    char s[256];
    char s2[256];
    br_model *new_model;
    LOG_TRACE("(%p, %p)", pActor, pArg);

    (void)pActor;
    (void)pArg;
    (void)s;
    (void)s2;
    (void)new_model;

    return original_SetIDAndDupModel(pActor, pArg);
}

static void(*original_DuplicateIfNotAmpersand)(br_actor *, ...) = (void(*)(br_actor *, ...))0x00443df2;
CARM95_HOOK_FUNCTION(original_DuplicateIfNotAmpersand, DuplicateIfNotAmpersand)
void DuplicateIfNotAmpersand(br_actor *pActor) {
    int highest;
    LOG_TRACE("(%p)", pActor);

    (void)pActor;
    (void)highest;

    original_DuplicateIfNotAmpersand(pActor);
}

static void(*original_DropActor)(int, ...) = (void(*)(int, ...))0x004436c2;
CARM95_HOOK_FUNCTION(original_DropActor, DropActor)
void DropActor(int pIndex) {
    FILE *f;
    tPath_name the_path;
    char s[256];
    int i;
    int face_bastard;
    int face_count;
    tBounds kev_bounds;
    tFace_ref the_list[50];
    br_scalar nearest_bastard;
    br_scalar distance_bastard;
    br_scalar ts;
    br_vector3 side_vector;
    br_angle phi;
    br_matrix34 mat;
    br_transform new_transform;
    br_actor *a;
    br_actor *last_non_ampersand;
    LOG_TRACE("(%d)", pIndex);

    (void)pIndex;
    (void)f;
    (void)the_path;
    (void)s;
    (void)i;
    (void)face_bastard;
    (void)face_count;
    (void)kev_bounds;
    (void)the_list;
    (void)nearest_bastard;
    (void)distance_bastard;
    (void)ts;
    (void)side_vector;
    (void)phi;
    (void)mat;
    (void)new_transform;
    (void)a;
    (void)last_non_ampersand;

    original_DropActor(pIndex);
}

static void(*original_DropActor0)() = (void(*)())0x00444145;
CARM95_HOOK_FUNCTION(original_DropActor0, DropActor0)
void DropActor0() {
    LOG_TRACE("()");


    original_DropActor0();
}

static void(*original_DropActor1)() = (void(*)())0x0044415a;
CARM95_HOOK_FUNCTION(original_DropActor1, DropActor1)
void DropActor1() {
    LOG_TRACE("()");


    original_DropActor1();
}

static void(*original_DropActor2)() = (void(*)())0x0044416f;
CARM95_HOOK_FUNCTION(original_DropActor2, DropActor2)
void DropActor2() {
    LOG_TRACE("()");


    original_DropActor2();
}

static void(*original_DropActor3)() = (void(*)())0x00444184;
CARM95_HOOK_FUNCTION(original_DropActor3, DropActor3)
void DropActor3() {
    LOG_TRACE("()");


    original_DropActor3();
}

static void(*original_DropActor4)() = (void(*)())0x00444199;
CARM95_HOOK_FUNCTION(original_DropActor4, DropActor4)
void DropActor4() {
    LOG_TRACE("()");


    original_DropActor4();
}

static void(*original_DropActor5)() = (void(*)())0x004441ae;
CARM95_HOOK_FUNCTION(original_DropActor5, DropActor5)
void DropActor5() {
    LOG_TRACE("()");


    original_DropActor5();
}

static void(*original_DropActor6)() = (void(*)())0x004441c3;
CARM95_HOOK_FUNCTION(original_DropActor6, DropActor6)
void DropActor6() {
    LOG_TRACE("()");


    original_DropActor6();
}

static void(*original_DropActor7)() = (void(*)())0x004441d8;
CARM95_HOOK_FUNCTION(original_DropActor7, DropActor7)
void DropActor7() {
    LOG_TRACE("()");


    original_DropActor7();
}

static void(*original_DropActor8)() = (void(*)())0x004441ed;
CARM95_HOOK_FUNCTION(original_DropActor8, DropActor8)
void DropActor8() {
    LOG_TRACE("()");


    original_DropActor8();
}

static void(*original_DropActor9)() = (void(*)())0x00444202;
CARM95_HOOK_FUNCTION(original_DropActor9, DropActor9)
void DropActor9() {
    LOG_TRACE("()");


    original_DropActor9();
}

static br_uint_32(*original_IdentifyAccCB)(br_actor *, void *, ...) = (br_uint_32(*)(br_actor *, void *, ...))0x00444275;
CARM95_HOOK_FUNCTION(original_IdentifyAccCB, IdentifyAccCB)
br_uint_32 IdentifyAccCB(br_actor *pActor, void *pArg) {
    br_scalar distance;
    char s[256];
    br_vector3 v;
    LOG_TRACE("(%p, %p)", pActor, pArg);

    (void)pActor;
    (void)pArg;
    (void)distance;
    (void)s;
    (void)v;

    return original_IdentifyAccCB(pActor, pArg);
}

static void(*original_IdentifyAcc)() = (void(*)())0x00444217;
CARM95_HOOK_FUNCTION(original_IdentifyAcc, IdentifyAcc)
void IdentifyAcc() {
    LOG_TRACE("()");


    original_IdentifyAcc();
}

static br_uint_32(*original_DelGrooveRef)(br_actor *, void *, ...) = (br_uint_32(*)(br_actor *, void *, ...))0x0044443b;
CARM95_HOOK_FUNCTION(original_DelGrooveRef, DelGrooveRef)
br_uint_32 DelGrooveRef(br_actor *pActor, void *pArg) {
    tGroovidelic_spec *the_groove;
    int i;
    LOG_TRACE("(%p, %p)", pActor, pArg);

    (void)pActor;
    (void)pArg;
    (void)the_groove;
    (void)i;

    return original_DelGrooveRef(pActor, pArg);
}

static br_uint_32(*original_DelReferencedModels)(br_actor *, void *, ...) = (br_uint_32(*)(br_actor *, void *, ...))0x0044449a;
CARM95_HOOK_FUNCTION(original_DelReferencedModels, DelReferencedModels)
br_uint_32 DelReferencedModels(br_actor *pActor, void *pArg) {
    tGroovidelic_spec *the_groove;
    int i;
    LOG_TRACE("(%p, %p)", pActor, pArg);

    (void)pActor;
    (void)pArg;
    (void)the_groove;
    (void)i;

    return original_DelReferencedModels(pActor, pArg);
}

static void(*original_DeleteAcc)() = (void(*)())0x004443bb;
CARM95_HOOK_FUNCTION(original_DeleteAcc, DeleteAcc)
void DeleteAcc() {
    LOG_TRACE("()");


    original_DeleteAcc();
}

static br_uint_32(*original_OffsetModel)(br_actor *, void *, ...) = (br_uint_32(*)(br_actor *, void *, ...))0x00444737;
CARM95_HOOK_FUNCTION(original_OffsetModel, OffsetModel)
br_uint_32 OffsetModel(br_actor *pActor, void *pArg) {
    int i;
    LOG_TRACE("(%p, %p)", pActor, pArg);

    (void)pActor;
    (void)pArg;
    (void)i;

    return original_OffsetModel(pActor, pArg);
}

static void(*original_OffsetActor)(br_actor *, br_vector3 *, ...) = (void(*)(br_actor *, br_vector3 *, ...))0x00444717;
CARM95_HOOK_FUNCTION(original_OffsetActor, OffsetActor)
void OffsetActor(br_actor *pActor, br_vector3 *pOffset) {
    LOG_TRACE("(%p, %p)", pActor, pOffset);

    (void)pActor;
    (void)pOffset;

    original_OffsetActor(pActor, pOffset);
}

static void(*original_CentreActor)(br_actor *, br_vector3 *, ...) = (void(*)(br_actor *, br_vector3 *, ...))0x00444803;
CARM95_HOOK_FUNCTION(original_CentreActor, CentreActor)
void CentreActor(br_actor *pActor, br_vector3 *pOffset) {
    LOG_TRACE("(%p, %p)", pActor, pOffset);

    (void)pActor;
    (void)pOffset;

    original_CentreActor(pActor, pOffset);
}

static void(*original_SnapAccToVertical)() = (void(*)())0x00444538;
CARM95_HOOK_FUNCTION(original_SnapAccToVertical, SnapAccToVertical)
void SnapAccToVertical() {
    LOG_TRACE("()");


    original_SnapAccToVertical();
}

static void(*original_RotateAccessory)(br_angle, ...) = (void(*)(br_angle, ...))0x004445d9;
CARM95_HOOK_FUNCTION(original_RotateAccessory, RotateAccessory)
void RotateAccessory(br_angle pAngle) {
    br_vector3 mr_offset;
    LOG_TRACE("(%u)", pAngle);

    (void)pAngle;
    (void)mr_offset;

    original_RotateAccessory(pAngle);
}

static void(*original_ScaleAccessory)(float, ...) = (void(*)(float, ...))0x00444b74;
CARM95_HOOK_FUNCTION(original_ScaleAccessory, ScaleAccessory)
void ScaleAccessory(float pScaling_factor) {
    br_vector3 mr_offset;
    LOG_TRACE("(%f)", pScaling_factor);

    (void)pScaling_factor;
    (void)mr_offset;

    original_ScaleAccessory(pScaling_factor);
}

static void(*original_MoveAccessory)(br_scalar, br_scalar, br_scalar, ...) = (void(*)(br_scalar, br_scalar, br_scalar, ...))0x00444d87;
CARM95_HOOK_FUNCTION(original_MoveAccessory, MoveAccessory)
void MoveAccessory(br_scalar pX_shift, br_scalar pY_shift, br_scalar pZ_shift) {
    br_vector3 v;
    LOG_TRACE("(%f, %f, %f)", pX_shift, pY_shift, pZ_shift);

    (void)pX_shift;
    (void)pY_shift;
    (void)pZ_shift;
    (void)v;

    original_MoveAccessory(pX_shift, pY_shift, pZ_shift);
}

static void(*original_RotateAccL)() = (void(*)())0x004445c1;
CARM95_HOOK_FUNCTION(original_RotateAccL, RotateAccL)
void RotateAccL() {
    LOG_TRACE("()");


    original_RotateAccL();
}

static void(*original_RotateAccL2)() = (void(*)())0x0044491e;
CARM95_HOOK_FUNCTION(original_RotateAccL2, RotateAccL2)
void RotateAccL2() {
    LOG_TRACE("()");


    original_RotateAccL2();
}

static void(*original_RotateAccL3)() = (void(*)())0x00444936;
CARM95_HOOK_FUNCTION(original_RotateAccL3, RotateAccL3)
void RotateAccL3() {
    LOG_TRACE("()");


    original_RotateAccL3();
}

static void(*original_RotateAccL4)() = (void(*)())0x0044494e;
CARM95_HOOK_FUNCTION(original_RotateAccL4, RotateAccL4)
void RotateAccL4() {
    LOG_TRACE("()");


    original_RotateAccL4();
}

static void(*original_RotateAccR)() = (void(*)())0x00444966;
CARM95_HOOK_FUNCTION(original_RotateAccR, RotateAccR)
void RotateAccR() {
    LOG_TRACE("()");


    original_RotateAccR();
}

static void(*original_RotateAccR2)() = (void(*)())0x0044497e;
CARM95_HOOK_FUNCTION(original_RotateAccR2, RotateAccR2)
void RotateAccR2() {
    LOG_TRACE("()");


    original_RotateAccR2();
}

static void(*original_RotateAccR3)() = (void(*)())0x00444996;
CARM95_HOOK_FUNCTION(original_RotateAccR3, RotateAccR3)
void RotateAccR3() {
    LOG_TRACE("()");


    original_RotateAccR3();
}

static void(*original_RotateAccR4)() = (void(*)())0x004449ae;
CARM95_HOOK_FUNCTION(original_RotateAccR4, RotateAccR4)
void RotateAccR4() {
    LOG_TRACE("()");


    original_RotateAccR4();
}

static void(*original_CycleAccRotate)() = (void(*)())0x004449c6;
CARM95_HOOK_FUNCTION(original_CycleAccRotate, CycleAccRotate)
void CycleAccRotate() {
    LOG_TRACE("()");


    original_CycleAccRotate();
}

static void(*original_CycleAccScale)() = (void(*)())0x00444a82;
CARM95_HOOK_FUNCTION(original_CycleAccScale, CycleAccScale)
void CycleAccScale() {
    LOG_TRACE("()");


    original_CycleAccScale();
}

static void(*original_ScaleAccUp2)() = (void(*)())0x00444b5c;
CARM95_HOOK_FUNCTION(original_ScaleAccUp2, ScaleAccUp2)
void ScaleAccUp2() {
    LOG_TRACE("()");


    original_ScaleAccUp2();
}

static void(*original_ScaleAccUp3)() = (void(*)())0x00444cf3;
CARM95_HOOK_FUNCTION(original_ScaleAccUp3, ScaleAccUp3)
void ScaleAccUp3() {
    LOG_TRACE("()");


    original_ScaleAccUp3();
}

static void(*original_ScaleAccUp4)() = (void(*)())0x00444d0b;
CARM95_HOOK_FUNCTION(original_ScaleAccUp4, ScaleAccUp4)
void ScaleAccUp4() {
    LOG_TRACE("()");


    original_ScaleAccUp4();
}

static void(*original_ScaleAccDown2)() = (void(*)())0x00444d23;
CARM95_HOOK_FUNCTION(original_ScaleAccDown2, ScaleAccDown2)
void ScaleAccDown2() {
    LOG_TRACE("()");


    original_ScaleAccDown2();
}

static void(*original_ScaleAccDown3)() = (void(*)())0x00444d3b;
CARM95_HOOK_FUNCTION(original_ScaleAccDown3, ScaleAccDown3)
void ScaleAccDown3() {
    LOG_TRACE("()");


    original_ScaleAccDown3();
}

static void(*original_ScaleAccDown4)() = (void(*)())0x00444d53;
CARM95_HOOK_FUNCTION(original_ScaleAccDown4, ScaleAccDown4)
void ScaleAccDown4() {
    LOG_TRACE("()");


    original_ScaleAccDown4();
}

static void(*original_MoveXAccL)() = (void(*)())0x00444d6b;
CARM95_HOOK_FUNCTION(original_MoveXAccL, MoveXAccL)
void MoveXAccL() {
    LOG_TRACE("()");


    original_MoveXAccL();
}

static void(*original_MoveXAccL2)() = (void(*)())0x00444df2;
CARM95_HOOK_FUNCTION(original_MoveXAccL2, MoveXAccL2)
void MoveXAccL2() {
    LOG_TRACE("()");


    original_MoveXAccL2();
}

static void(*original_MoveXAccL3)() = (void(*)())0x00444e0e;
CARM95_HOOK_FUNCTION(original_MoveXAccL3, MoveXAccL3)
void MoveXAccL3() {
    LOG_TRACE("()");


    original_MoveXAccL3();
}

static void(*original_MoveXAccL4)() = (void(*)())0x00444e2a;
CARM95_HOOK_FUNCTION(original_MoveXAccL4, MoveXAccL4)
void MoveXAccL4() {
    LOG_TRACE("()");


    original_MoveXAccL4();
}

static void(*original_MoveXAccR)() = (void(*)())0x00444e46;
CARM95_HOOK_FUNCTION(original_MoveXAccR, MoveXAccR)
void MoveXAccR() {
    LOG_TRACE("()");


    original_MoveXAccR();
}

static void(*original_MoveXAccR2)() = (void(*)())0x00444e62;
CARM95_HOOK_FUNCTION(original_MoveXAccR2, MoveXAccR2)
void MoveXAccR2() {
    LOG_TRACE("()");


    original_MoveXAccR2();
}

static void(*original_MoveXAccR3)() = (void(*)())0x00444e7e;
CARM95_HOOK_FUNCTION(original_MoveXAccR3, MoveXAccR3)
void MoveXAccR3() {
    LOG_TRACE("()");


    original_MoveXAccR3();
}

static void(*original_MoveXAccR4)() = (void(*)())0x00444e9a;
CARM95_HOOK_FUNCTION(original_MoveXAccR4, MoveXAccR4)
void MoveXAccR4() {
    LOG_TRACE("()");


    original_MoveXAccR4();
}

static void(*original_MoveYAccL)() = (void(*)())0x00444eb6;
CARM95_HOOK_FUNCTION(original_MoveYAccL, MoveYAccL)
void MoveYAccL() {
    LOG_TRACE("()");


    original_MoveYAccL();
}

static void(*original_MoveYAccL2)() = (void(*)())0x00444ed2;
CARM95_HOOK_FUNCTION(original_MoveYAccL2, MoveYAccL2)
void MoveYAccL2() {
    LOG_TRACE("()");


    original_MoveYAccL2();
}

static void(*original_MoveYAccL3)() = (void(*)())0x00444eee;
CARM95_HOOK_FUNCTION(original_MoveYAccL3, MoveYAccL3)
void MoveYAccL3() {
    LOG_TRACE("()");


    original_MoveYAccL3();
}

static void(*original_MoveYAccL4)() = (void(*)())0x00444f0a;
CARM95_HOOK_FUNCTION(original_MoveYAccL4, MoveYAccL4)
void MoveYAccL4() {
    LOG_TRACE("()");


    original_MoveYAccL4();
}

static void(*original_MoveYAccR)() = (void(*)())0x00444f26;
CARM95_HOOK_FUNCTION(original_MoveYAccR, MoveYAccR)
void MoveYAccR() {
    LOG_TRACE("()");


    original_MoveYAccR();
}

static void(*original_MoveYAccR2)() = (void(*)())0x00444f42;
CARM95_HOOK_FUNCTION(original_MoveYAccR2, MoveYAccR2)
void MoveYAccR2() {
    LOG_TRACE("()");


    original_MoveYAccR2();
}

static void(*original_MoveYAccR3)() = (void(*)())0x00444f5e;
CARM95_HOOK_FUNCTION(original_MoveYAccR3, MoveYAccR3)
void MoveYAccR3() {
    LOG_TRACE("()");


    original_MoveYAccR3();
}

static void(*original_MoveYAccR4)() = (void(*)())0x00444f7a;
CARM95_HOOK_FUNCTION(original_MoveYAccR4, MoveYAccR4)
void MoveYAccR4() {
    LOG_TRACE("()");


    original_MoveYAccR4();
}

static void(*original_MoveZAccL)() = (void(*)())0x00444f96;
CARM95_HOOK_FUNCTION(original_MoveZAccL, MoveZAccL)
void MoveZAccL() {
    LOG_TRACE("()");


    original_MoveZAccL();
}

static void(*original_MoveZAccL2)() = (void(*)())0x00444fb2;
CARM95_HOOK_FUNCTION(original_MoveZAccL2, MoveZAccL2)
void MoveZAccL2() {
    LOG_TRACE("()");


    original_MoveZAccL2();
}

static void(*original_MoveZAccL3)() = (void(*)())0x00444fce;
CARM95_HOOK_FUNCTION(original_MoveZAccL3, MoveZAccL3)
void MoveZAccL3() {
    LOG_TRACE("()");


    original_MoveZAccL3();
}

static void(*original_MoveZAccL4)() = (void(*)())0x00444fea;
CARM95_HOOK_FUNCTION(original_MoveZAccL4, MoveZAccL4)
void MoveZAccL4() {
    LOG_TRACE("()");


    original_MoveZAccL4();
}

static void(*original_MoveZAccR)() = (void(*)())0x00445006;
CARM95_HOOK_FUNCTION(original_MoveZAccR, MoveZAccR)
void MoveZAccR() {
    LOG_TRACE("()");


    original_MoveZAccR();
}

static void(*original_MoveZAccR2)() = (void(*)())0x00445022;
CARM95_HOOK_FUNCTION(original_MoveZAccR2, MoveZAccR2)
void MoveZAccR2() {
    LOG_TRACE("()");


    original_MoveZAccR2();
}

static void(*original_MoveZAccR3)() = (void(*)())0x0044503e;
CARM95_HOOK_FUNCTION(original_MoveZAccR3, MoveZAccR3)
void MoveZAccR3() {
    LOG_TRACE("()");


    original_MoveZAccR3();
}

static void(*original_MoveZAccR4)() = (void(*)())0x0044505a;
CARM95_HOOK_FUNCTION(original_MoveZAccR4, MoveZAccR4)
void MoveZAccR4() {
    LOG_TRACE("()");


    original_MoveZAccR4();
}

static br_material *(*original_GetInternalMat)() = (br_material *(*)())0x00445076;
CARM95_HOOK_FUNCTION(original_GetInternalMat, GetInternalMat)
br_material* GetInternalMat() {
    LOG_TRACE("()");


    return original_GetInternalMat();
}

static br_material *(*original_GetExternalMat)() = (br_material *(*)())0x00445093;
CARM95_HOOK_FUNCTION(original_GetExternalMat, GetExternalMat)
br_material* GetExternalMat() {
    LOG_TRACE("()");


    return original_GetExternalMat();
}

static void(*original_BuildSpecVolModel)(tSpecial_volume *, int, br_material *, br_material *, ...) = (void(*)(tSpecial_volume *, int, br_material *, br_material *, ...))0x004452b1;
CARM95_HOOK_FUNCTION(original_BuildSpecVolModel, BuildSpecVolModel)
void BuildSpecVolModel(tSpecial_volume *pSpec, int pIndex, br_material *pInt_mat, br_material *pExt_mat) {
    int i;
    int j;
    int temp;
    tSpecial_volume *v;
    br_actor *actor;
    br_model *model;
    LOG_TRACE("(%p, %d, %p, %p)", pSpec, pIndex, pInt_mat, pExt_mat);

    (void)pSpec;
    (void)pIndex;
    (void)pInt_mat;
    (void)pExt_mat;
    (void)i;
    (void)j;
    (void)temp;
    (void)v;
    (void)actor;
    (void)model;

    original_BuildSpecVolModel(pSpec, pIndex, pInt_mat, pExt_mat);
}

static void(*original_DropSpecVol)(int, ...) = (void(*)(int, ...))0x004450d0;
CARM95_HOOK_FUNCTION(original_DropSpecVol, DropSpecVol)
void DropSpecVol(int pIndex) {
    FILE *f;
    tPath_name the_path;
    int i;
    int spec_count;
    tSpecial_volume spec;
    tSpecial_volume *new_specs;
    char s[256];
    LOG_TRACE("(%d)", pIndex);

    (void)pIndex;
    (void)f;
    (void)the_path;
    (void)i;
    (void)spec_count;
    (void)spec;
    (void)new_specs;
    (void)s;

    original_DropSpecVol(pIndex);
}

static void(*original_DropSpecVol0)() = (void(*)())0x004450b0;
CARM95_HOOK_FUNCTION(original_DropSpecVol0, DropSpecVol0)
void DropSpecVol0() {
    LOG_TRACE("()");


    original_DropSpecVol0();
}

static void(*original_DropSpecVol1)() = (void(*)())0x004450bb;
CARM95_HOOK_FUNCTION(original_DropSpecVol1, DropSpecVol1)
void DropSpecVol1() {
    LOG_TRACE("()");


    original_DropSpecVol1();
}

static void(*original_DropSpecVol2)() = (void(*)())0x00445b86;
CARM95_HOOK_FUNCTION(original_DropSpecVol2, DropSpecVol2)
void DropSpecVol2() {
    LOG_TRACE("()");


    original_DropSpecVol2();
}

static void(*original_DropSpecVol3)() = (void(*)())0x00445b9b;
CARM95_HOOK_FUNCTION(original_DropSpecVol3, DropSpecVol3)
void DropSpecVol3() {
    LOG_TRACE("()");


    original_DropSpecVol3();
}

static void(*original_DropSpecVol4)() = (void(*)())0x00445bb0;
CARM95_HOOK_FUNCTION(original_DropSpecVol4, DropSpecVol4)
void DropSpecVol4() {
    LOG_TRACE("()");


    original_DropSpecVol4();
}

static void(*original_DropSpecVol5)() = (void(*)())0x00445bc5;
CARM95_HOOK_FUNCTION(original_DropSpecVol5, DropSpecVol5)
void DropSpecVol5() {
    LOG_TRACE("()");


    original_DropSpecVol5();
}

static void(*original_DropSpecVol6)() = (void(*)())0x00445bda;
CARM95_HOOK_FUNCTION(original_DropSpecVol6, DropSpecVol6)
void DropSpecVol6() {
    LOG_TRACE("()");


    original_DropSpecVol6();
}

static void(*original_DropSpecVol7)() = (void(*)())0x00445bef;
CARM95_HOOK_FUNCTION(original_DropSpecVol7, DropSpecVol7)
void DropSpecVol7() {
    LOG_TRACE("()");


    original_DropSpecVol7();
}

static void(*original_DropSpecVol8)() = (void(*)())0x00445c04;
CARM95_HOOK_FUNCTION(original_DropSpecVol8, DropSpecVol8)
void DropSpecVol8() {
    LOG_TRACE("()");


    original_DropSpecVol8();
}

static void(*original_DropSpecVol9)() = (void(*)())0x00445c19;
CARM95_HOOK_FUNCTION(original_DropSpecVol9, DropSpecVol9)
void DropSpecVol9() {
    LOG_TRACE("()");


    original_DropSpecVol9();
}

static void(*original_IdentifySpecVol)() = (void(*)())0x00445c2e;
CARM95_HOOK_FUNCTION(original_IdentifySpecVol, IdentifySpecVol)
void IdentifySpecVol() {
    int i;
    int min_index;
    tSpecial_volume *v;
    br_scalar min_d;
    br_scalar d;
    br_vector3 *p;
    char s[256];
    LOG_TRACE("()");

    (void)i;
    (void)min_index;
    (void)v;
    (void)min_d;
    (void)d;
    (void)p;
    (void)s;

    original_IdentifySpecVol();
}

static void(*original_DelSpecVolumeGraph)(int, ...) = (void(*)(int, ...))0x00445ed2;
CARM95_HOOK_FUNCTION(original_DelSpecVolumeGraph, DelSpecVolumeGraph)
void DelSpecVolumeGraph(int pIndex) {
    br_actor *actor;
    br_model *model;
    LOG_TRACE("(%d)", pIndex);

    (void)pIndex;
    (void)actor;
    (void)model;

    original_DelSpecVolumeGraph(pIndex);
}

static void(*original_DeleteSpecVol)() = (void(*)())0x00445dc5;
CARM95_HOOK_FUNCTION(original_DeleteSpecVol, DeleteSpecVol)
void DeleteSpecVol() {
    int index;
    LOG_TRACE("()");

    (void)index;

    original_DeleteSpecVol();
}

static void(*original_RotateSpecVolL)() = (void(*)())0x00446022;
CARM95_HOOK_FUNCTION(original_RotateSpecVolL, RotateSpecVolL)
void RotateSpecVolL() {
    LOG_TRACE("()");


    original_RotateSpecVolL();
}

static void(*original_RotateSpecVolL2)() = (void(*)())0x00446032;
CARM95_HOOK_FUNCTION(original_RotateSpecVolL2, RotateSpecVolL2)
void RotateSpecVolL2() {
    LOG_TRACE("()");


    original_RotateSpecVolL2();
}

static void(*original_RotateSpecVolL3)() = (void(*)())0x00446042;
CARM95_HOOK_FUNCTION(original_RotateSpecVolL3, RotateSpecVolL3)
void RotateSpecVolL3() {
    LOG_TRACE("()");


    original_RotateSpecVolL3();
}

static void(*original_RotateSpecVolL4)() = (void(*)())0x00446052;
CARM95_HOOK_FUNCTION(original_RotateSpecVolL4, RotateSpecVolL4)
void RotateSpecVolL4() {
    LOG_TRACE("()");


    original_RotateSpecVolL4();
}

static void(*original_RotateSpecVolR)() = (void(*)())0x00446062;
CARM95_HOOK_FUNCTION(original_RotateSpecVolR, RotateSpecVolR)
void RotateSpecVolR() {
    LOG_TRACE("()");


    original_RotateSpecVolR();
}

static void(*original_RotateSpecVolR2)() = (void(*)())0x00446072;
CARM95_HOOK_FUNCTION(original_RotateSpecVolR2, RotateSpecVolR2)
void RotateSpecVolR2() {
    LOG_TRACE("()");


    original_RotateSpecVolR2();
}

static void(*original_RotateSpecVolR3)() = (void(*)())0x00446082;
CARM95_HOOK_FUNCTION(original_RotateSpecVolR3, RotateSpecVolR3)
void RotateSpecVolR3() {
    LOG_TRACE("()");


    original_RotateSpecVolR3();
}

static void(*original_RotateSpecVolR4)() = (void(*)())0x00446092;
CARM95_HOOK_FUNCTION(original_RotateSpecVolR4, RotateSpecVolR4)
void RotateSpecVolR4() {
    LOG_TRACE("()");


    original_RotateSpecVolR4();
}

static void(*original_CycleSpecVolRotate)() = (void(*)())0x004460a2;
CARM95_HOOK_FUNCTION(original_CycleSpecVolRotate, CycleSpecVolRotate)
void CycleSpecVolRotate() {
    LOG_TRACE("()");


    original_CycleSpecVolRotate();
}

static void(*original_CycleSpecVolScale)() = (void(*)())0x004460b2;
CARM95_HOOK_FUNCTION(original_CycleSpecVolScale, CycleSpecVolScale)
void CycleSpecVolScale() {
    LOG_TRACE("()");


    original_CycleSpecVolScale();
}

static void(*original_ScaleSpecVolUp2)() = (void(*)())0x004460c2;
CARM95_HOOK_FUNCTION(original_ScaleSpecVolUp2, ScaleSpecVolUp2)
void ScaleSpecVolUp2() {
    LOG_TRACE("()");


    original_ScaleSpecVolUp2();
}

static void(*original_ScaleSpecVolUp3)() = (void(*)())0x004460d2;
CARM95_HOOK_FUNCTION(original_ScaleSpecVolUp3, ScaleSpecVolUp3)
void ScaleSpecVolUp3() {
    LOG_TRACE("()");


    original_ScaleSpecVolUp3();
}

static void(*original_ScaleSpecVolUp4)() = (void(*)())0x004460e2;
CARM95_HOOK_FUNCTION(original_ScaleSpecVolUp4, ScaleSpecVolUp4)
void ScaleSpecVolUp4() {
    LOG_TRACE("()");


    original_ScaleSpecVolUp4();
}

static void(*original_ScaleSpecVolDown2)() = (void(*)())0x004460f2;
CARM95_HOOK_FUNCTION(original_ScaleSpecVolDown2, ScaleSpecVolDown2)
void ScaleSpecVolDown2() {
    LOG_TRACE("()");


    original_ScaleSpecVolDown2();
}

static void(*original_ScaleSpecVolDown3)() = (void(*)())0x00446102;
CARM95_HOOK_FUNCTION(original_ScaleSpecVolDown3, ScaleSpecVolDown3)
void ScaleSpecVolDown3() {
    LOG_TRACE("()");


    original_ScaleSpecVolDown3();
}

static void(*original_ScaleSpecVolDown4)() = (void(*)())0x00446112;
CARM95_HOOK_FUNCTION(original_ScaleSpecVolDown4, ScaleSpecVolDown4)
void ScaleSpecVolDown4() {
    LOG_TRACE("()");


    original_ScaleSpecVolDown4();
}

static void(*original_MoveXSpecVolL)() = (void(*)())0x00446122;
CARM95_HOOK_FUNCTION(original_MoveXSpecVolL, MoveXSpecVolL)
void MoveXSpecVolL() {
    LOG_TRACE("()");


    original_MoveXSpecVolL();
}

static void(*original_MoveXSpecVolL2)() = (void(*)())0x00446132;
CARM95_HOOK_FUNCTION(original_MoveXSpecVolL2, MoveXSpecVolL2)
void MoveXSpecVolL2() {
    LOG_TRACE("()");


    original_MoveXSpecVolL2();
}

static void(*original_MoveXSpecVolL3)() = (void(*)())0x00446142;
CARM95_HOOK_FUNCTION(original_MoveXSpecVolL3, MoveXSpecVolL3)
void MoveXSpecVolL3() {
    LOG_TRACE("()");


    original_MoveXSpecVolL3();
}

static void(*original_MoveXSpecVolL4)() = (void(*)())0x00446152;
CARM95_HOOK_FUNCTION(original_MoveXSpecVolL4, MoveXSpecVolL4)
void MoveXSpecVolL4() {
    LOG_TRACE("()");


    original_MoveXSpecVolL4();
}

static void(*original_MoveXSpecVolR)() = (void(*)())0x00446162;
CARM95_HOOK_FUNCTION(original_MoveXSpecVolR, MoveXSpecVolR)
void MoveXSpecVolR() {
    LOG_TRACE("()");


    original_MoveXSpecVolR();
}

static void(*original_MoveXSpecVolR2)() = (void(*)())0x00446172;
CARM95_HOOK_FUNCTION(original_MoveXSpecVolR2, MoveXSpecVolR2)
void MoveXSpecVolR2() {
    LOG_TRACE("()");


    original_MoveXSpecVolR2();
}

static void(*original_MoveXSpecVolR3)() = (void(*)())0x00446182;
CARM95_HOOK_FUNCTION(original_MoveXSpecVolR3, MoveXSpecVolR3)
void MoveXSpecVolR3() {
    LOG_TRACE("()");


    original_MoveXSpecVolR3();
}

static void(*original_MoveXSpecVolR4)() = (void(*)())0x00446192;
CARM95_HOOK_FUNCTION(original_MoveXSpecVolR4, MoveXSpecVolR4)
void MoveXSpecVolR4() {
    LOG_TRACE("()");


    original_MoveXSpecVolR4();
}

static void(*original_MoveYSpecVolL)() = (void(*)())0x004461a2;
CARM95_HOOK_FUNCTION(original_MoveYSpecVolL, MoveYSpecVolL)
void MoveYSpecVolL() {
    LOG_TRACE("()");


    original_MoveYSpecVolL();
}

static void(*original_MoveYSpecVolL2)() = (void(*)())0x004461b2;
CARM95_HOOK_FUNCTION(original_MoveYSpecVolL2, MoveYSpecVolL2)
void MoveYSpecVolL2() {
    LOG_TRACE("()");


    original_MoveYSpecVolL2();
}

static void(*original_MoveYSpecVolL3)() = (void(*)())0x004461c2;
CARM95_HOOK_FUNCTION(original_MoveYSpecVolL3, MoveYSpecVolL3)
void MoveYSpecVolL3() {
    LOG_TRACE("()");


    original_MoveYSpecVolL3();
}

static void(*original_MoveYSpecVolL4)() = (void(*)())0x004461d2;
CARM95_HOOK_FUNCTION(original_MoveYSpecVolL4, MoveYSpecVolL4)
void MoveYSpecVolL4() {
    LOG_TRACE("()");


    original_MoveYSpecVolL4();
}

static void(*original_MoveYSpecVolR)() = (void(*)())0x004461e2;
CARM95_HOOK_FUNCTION(original_MoveYSpecVolR, MoveYSpecVolR)
void MoveYSpecVolR() {
    LOG_TRACE("()");


    original_MoveYSpecVolR();
}

static void(*original_MoveYSpecVolR2)() = (void(*)())0x004461f2;
CARM95_HOOK_FUNCTION(original_MoveYSpecVolR2, MoveYSpecVolR2)
void MoveYSpecVolR2() {
    LOG_TRACE("()");


    original_MoveYSpecVolR2();
}

static void(*original_MoveYSpecVolR3)() = (void(*)())0x00446202;
CARM95_HOOK_FUNCTION(original_MoveYSpecVolR3, MoveYSpecVolR3)
void MoveYSpecVolR3() {
    LOG_TRACE("()");


    original_MoveYSpecVolR3();
}

static void(*original_MoveYSpecVolR4)() = (void(*)())0x00446212;
CARM95_HOOK_FUNCTION(original_MoveYSpecVolR4, MoveYSpecVolR4)
void MoveYSpecVolR4() {
    LOG_TRACE("()");


    original_MoveYSpecVolR4();
}

static void(*original_MoveZSpecVolL)() = (void(*)())0x00446222;
CARM95_HOOK_FUNCTION(original_MoveZSpecVolL, MoveZSpecVolL)
void MoveZSpecVolL() {
    LOG_TRACE("()");


    original_MoveZSpecVolL();
}

static void(*original_MoveZSpecVolL2)() = (void(*)())0x00446232;
CARM95_HOOK_FUNCTION(original_MoveZSpecVolL2, MoveZSpecVolL2)
void MoveZSpecVolL2() {
    LOG_TRACE("()");


    original_MoveZSpecVolL2();
}

static void(*original_MoveZSpecVolL3)() = (void(*)())0x00446242;
CARM95_HOOK_FUNCTION(original_MoveZSpecVolL3, MoveZSpecVolL3)
void MoveZSpecVolL3() {
    LOG_TRACE("()");


    original_MoveZSpecVolL3();
}

static void(*original_MoveZSpecVolL4)() = (void(*)())0x00446252;
CARM95_HOOK_FUNCTION(original_MoveZSpecVolL4, MoveZSpecVolL4)
void MoveZSpecVolL4() {
    LOG_TRACE("()");


    original_MoveZSpecVolL4();
}

static void(*original_MoveZSpecVolR)() = (void(*)())0x00446262;
CARM95_HOOK_FUNCTION(original_MoveZSpecVolR, MoveZSpecVolR)
void MoveZSpecVolR() {
    LOG_TRACE("()");


    original_MoveZSpecVolR();
}

static void(*original_MoveZSpecVolR2)() = (void(*)())0x00446272;
CARM95_HOOK_FUNCTION(original_MoveZSpecVolR2, MoveZSpecVolR2)
void MoveZSpecVolR2() {
    LOG_TRACE("()");


    original_MoveZSpecVolR2();
}

static void(*original_MoveZSpecVolR3)() = (void(*)())0x00446282;
CARM95_HOOK_FUNCTION(original_MoveZSpecVolR3, MoveZSpecVolR3)
void MoveZSpecVolR3() {
    LOG_TRACE("()");


    original_MoveZSpecVolR3();
}

static void(*original_MoveZSpecVolR4)() = (void(*)())0x00446292;
CARM95_HOOK_FUNCTION(original_MoveZSpecVolR4, MoveZSpecVolR4)
void MoveZSpecVolR4() {
    LOG_TRACE("()");


    original_MoveZSpecVolR4();
}

static void(*original_SnapSpecVolToVertical)() = (void(*)())0x004462a2;
CARM95_HOOK_FUNCTION(original_SnapSpecVolToVertical, SnapSpecVolToVertical)
void SnapSpecVolToVertical() {
    LOG_TRACE("()");


    original_SnapSpecVolToVertical();
}

static void(*original_ShowSpecialVolumes)() = (void(*)())0x004462b2;
CARM95_HOOK_FUNCTION(original_ShowSpecialVolumes, ShowSpecialVolumes)
void ShowSpecialVolumes() {
    int i;
    int j;
    int temp;
    tSpecial_volume *v;
    br_actor *actor;
    br_model *model;
    br_material *internal_mat;
    br_material *external_mat;
    LOG_TRACE("()");

    (void)i;
    (void)j;
    (void)temp;
    (void)v;
    (void)actor;
    (void)model;
    (void)internal_mat;
    (void)external_mat;

    original_ShowSpecialVolumes();
}

static void(*original_HideSpecialVolumes)() = (void(*)())0x00446351;
CARM95_HOOK_FUNCTION(original_HideSpecialVolumes, HideSpecialVolumes)
void HideSpecialVolumes() {
    int i;
    tSpecial_volume *v;
    LOG_TRACE("()");

    (void)i;
    (void)v;

    original_HideSpecialVolumes();
}

