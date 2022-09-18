#include "world.h"

#include "harness/trace.h"

#include "carm95_hooks.h"

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

static float(__cdecl*original_MapSawToTriangle)(float) = (float(__cdecl*)(float))0x0043f377;
CARM95_HOOK_FUNCTION(original_MapSawToTriangle, MapSawToTriangle)
float __cdecl MapSawToTriangle(float pNumber) {
    LOG_TRACE("(%f)", pNumber);

    (void)pNumber;

    return original_MapSawToTriangle(pNumber);
}

static void(__cdecl*original_SetSightDistance)(br_scalar) = (void(__cdecl*)(br_scalar))0x00434b10;
CARM95_HOOK_FUNCTION(original_SetSightDistance, SetSightDistance)
void __cdecl SetSightDistance(br_scalar pYon) {
    LOG_TRACE("(%f)", pYon);

    (void)pYon;

    original_SetSightDistance(pYon);
}

static br_actor *(__cdecl*original_FindActorInArray)(char *) = (br_actor *(__cdecl*)(char *))0x00434b35;
CARM95_HOOK_FUNCTION(original_FindActorInArray, FindActorInArray)
br_actor* __cdecl FindActorInArray(char *pThe_name) {
    int i;
    LOG_TRACE("(\"%s\")", pThe_name);

    (void)pThe_name;
    (void)i;

    return original_FindActorInArray(pThe_name);
}

static br_actor *(__cdecl*original_FindLightInArray)(char *) = (br_actor *(__cdecl*)(char *))0x00434bcc;
CARM95_HOOK_FUNCTION(original_FindLightInArray, FindLightInArray)
br_actor* __cdecl FindLightInArray(char *pThe_name) {
    int i;
    LOG_TRACE("(\"%s\")", pThe_name);

    (void)pThe_name;
    (void)i;

    return original_FindLightInArray(pThe_name);
}

static br_actor *(__cdecl*original_CloneActor)(br_actor *) = (br_actor *(__cdecl*)(br_actor *))0x00434c62;
CARM95_HOOK_FUNCTION(original_CloneActor, CloneActor)
br_actor* __cdecl CloneActor(br_actor *pSource_actor) {
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

static void(__cdecl*original_InitialiseStorageSpace)(tBrender_storage *, int, int, int, int) = (void(__cdecl*)(tBrender_storage *, int, int, int, int))0x00434d37;
CARM95_HOOK_FUNCTION(original_InitialiseStorageSpace, InitialiseStorageSpace)
void __cdecl InitialiseStorageSpace(tBrender_storage *pStorage_space, int pMax_pixelmaps, int pMax_shade_tables, int pMax_materials, int pMax_models) {
    LOG_TRACE("(%p, %d, %d, %d, %d)", pStorage_space, pMax_pixelmaps, pMax_shade_tables, pMax_materials, pMax_models);

    (void)pStorage_space;
    (void)pMax_pixelmaps;
    (void)pMax_shade_tables;
    (void)pMax_materials;
    (void)pMax_models;

    original_InitialiseStorageSpace(pStorage_space, pMax_pixelmaps, pMax_shade_tables, pMax_materials, pMax_models);
}

static void(__cdecl*original_DisposeStorageSpace)(tBrender_storage *) = (void(__cdecl*)(tBrender_storage *))0x00434e0a;
CARM95_HOOK_FUNCTION(original_DisposeStorageSpace, DisposeStorageSpace)
void __cdecl DisposeStorageSpace(tBrender_storage *pStorage_space) {
    LOG_TRACE("(%p)", pStorage_space);

    (void)pStorage_space;

    original_DisposeStorageSpace(pStorage_space);
}

static void(__cdecl*original_ClearOutStorageSpace)(tBrender_storage *) = (void(__cdecl*)(tBrender_storage *))0x00434e60;
CARM95_HOOK_FUNCTION(original_ClearOutStorageSpace, ClearOutStorageSpace)
void __cdecl ClearOutStorageSpace(tBrender_storage *pStorage_space) {
    int i;
    LOG_TRACE("(%p)", pStorage_space);

    (void)pStorage_space;
    (void)i;

    original_ClearOutStorageSpace(pStorage_space);
}

static tAdd_to_storage_result(__cdecl*original_AddPixelmapToStorage)(tBrender_storage *, br_pixelmap **) = (tAdd_to_storage_result(__cdecl*)(tBrender_storage *, br_pixelmap **))0x00435014;
CARM95_HOOK_FUNCTION(original_AddPixelmapToStorage, AddPixelmapToStorage)
tAdd_to_storage_result __cdecl AddPixelmapToStorage(tBrender_storage *pStorage_space, br_pixelmap **pThe_pm) {
    int i;
    LOG_TRACE("(%p, %p)", pStorage_space, pThe_pm);

    (void)pStorage_space;
    (void)pThe_pm;
    (void)i;

    return original_AddPixelmapToStorage(pStorage_space, pThe_pm);
}

static tAdd_to_storage_result(__cdecl*original_AddShadeTableToStorage)(tBrender_storage *, br_pixelmap *) = (tAdd_to_storage_result(__cdecl*)(tBrender_storage *, br_pixelmap *))0x00435107;
CARM95_HOOK_FUNCTION(original_AddShadeTableToStorage, AddShadeTableToStorage)
tAdd_to_storage_result __cdecl AddShadeTableToStorage(tBrender_storage *pStorage_space, br_pixelmap *pThe_st) {
    int i;
    LOG_TRACE("(%p, %p)", pStorage_space, pThe_st);

    (void)pStorage_space;
    (void)pThe_st;
    (void)i;

    return original_AddShadeTableToStorage(pStorage_space, pThe_st);
}

static tAdd_to_storage_result(__cdecl*original_AddMaterialToStorage)(tBrender_storage *, br_material *) = (tAdd_to_storage_result(__cdecl*)(tBrender_storage *, br_material *))0x004351fa;
CARM95_HOOK_FUNCTION(original_AddMaterialToStorage, AddMaterialToStorage)
tAdd_to_storage_result __cdecl AddMaterialToStorage(tBrender_storage *pStorage_space, br_material *pThe_mat) {
    int i;
    LOG_TRACE("(%p, %p)", pStorage_space, pThe_mat);

    (void)pStorage_space;
    (void)pThe_mat;
    (void)i;

    return original_AddMaterialToStorage(pStorage_space, pThe_mat);
}

static tAdd_to_storage_result(__cdecl*original_AddModelToStorage)(tBrender_storage *, br_model *) = (tAdd_to_storage_result(__cdecl*)(tBrender_storage *, br_model *))0x00435300;
CARM95_HOOK_FUNCTION(original_AddModelToStorage, AddModelToStorage)
tAdd_to_storage_result __cdecl AddModelToStorage(tBrender_storage *pStorage_space, br_model *pThe_mod) {
    int i;
    LOG_TRACE("(%p, %p)", pStorage_space, pThe_mod);

    (void)pStorage_space;
    (void)pThe_mod;
    (void)i;

    return original_AddModelToStorage(pStorage_space, pThe_mod);
}

static int(__cdecl*original_LoadNPixelmaps)(tBrender_storage *, FILE *, int) = (int(__cdecl*)(tBrender_storage *, FILE *, int))0x00435402;
CARM95_HOOK_FUNCTION(original_LoadNPixelmaps, LoadNPixelmaps)
int __cdecl LoadNPixelmaps(tBrender_storage *pStorage_space, FILE *pF, int pCount) {
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

static br_pixelmap *(__cdecl*original_LoadSinglePixelmap)(tBrender_storage *, char *) = (br_pixelmap *(__cdecl*)(tBrender_storage *, char *))0x00435666;
CARM95_HOOK_FUNCTION(original_LoadSinglePixelmap, LoadSinglePixelmap)
br_pixelmap* __cdecl LoadSinglePixelmap(tBrender_storage *pStorage_space, char *pName) {
    br_pixelmap *temp;
    LOG_TRACE("(%p, \"%s\")", pStorage_space, pName);

    (void)pStorage_space;
    (void)pName;
    (void)temp;

    return original_LoadSinglePixelmap(pStorage_space, pName);
}

static br_material *(__cdecl*original_LoadSingleMaterial)(tBrender_storage *, char *) = (br_material *(__cdecl*)(tBrender_storage *, char *))0x00435731;
CARM95_HOOK_FUNCTION(original_LoadSingleMaterial, LoadSingleMaterial)
br_material* __cdecl LoadSingleMaterial(tBrender_storage *pStorage_space, char *pName) {
    br_material *temp;
    LOG_TRACE("(%p, \"%s\")", pStorage_space, pName);

    (void)pStorage_space;
    (void)pName;
    (void)temp;

    return original_LoadSingleMaterial(pStorage_space, pName);
}

static int(__cdecl*original_LoadNShadeTables)(tBrender_storage *, FILE *, int) = (int(__cdecl*)(tBrender_storage *, FILE *, int))0x004357fc;
CARM95_HOOK_FUNCTION(original_LoadNShadeTables, LoadNShadeTables)
int __cdecl LoadNShadeTables(tBrender_storage *pStorage_space, FILE *pF, int pCount) {
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

static br_pixelmap *(__cdecl*original_LoadSingleShadeTable)(tBrender_storage *, char *) = (br_pixelmap *(__cdecl*)(tBrender_storage *, char *))0x004359c7;
CARM95_HOOK_FUNCTION(original_LoadSingleShadeTable, LoadSingleShadeTable)
br_pixelmap* __cdecl LoadSingleShadeTable(tBrender_storage *pStorage_space, char *pName) {
    br_pixelmap *temp;
    LOG_TRACE("(%p, \"%s\")", pStorage_space, pName);

    (void)pStorage_space;
    (void)pName;
    (void)temp;

    return original_LoadSingleShadeTable(pStorage_space, pName);
}

static int(__cdecl*original_LoadNMaterials)(tBrender_storage *, FILE *, int) = (int(__cdecl*)(tBrender_storage *, FILE *, int))0x00435a92;
CARM95_HOOK_FUNCTION(original_LoadNMaterials, LoadNMaterials)
int __cdecl LoadNMaterials(tBrender_storage *pStorage_space, FILE *pF, int pCount) {
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

static int(__cdecl*original_LoadNModels)(tBrender_storage *, FILE *, int) = (int(__cdecl*)(tBrender_storage *, FILE *, int))0x00435c60;
CARM95_HOOK_FUNCTION(original_LoadNModels, LoadNModels)
int __cdecl LoadNModels(tBrender_storage *pStorage_space, FILE *pF, int pCount) {
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

static void(__cdecl*original_DodgyModelUpdate)(br_model *) = (void(__cdecl*)(br_model *))0x00435e72;
CARM95_HOOK_FUNCTION(original_DodgyModelUpdate, DodgyModelUpdate)
void __cdecl DodgyModelUpdate(br_model *pM) {
    LOG_TRACE("(%p)", pM);

    (void)pM;

    original_DodgyModelUpdate(pM);
}

static br_material *(__cdecl*original_SuffixedMaterial)(br_material *, char *) = (br_material *(__cdecl*)(br_material *, char *))0x00435f61;
CARM95_HOOK_FUNCTION(original_SuffixedMaterial, SuffixedMaterial)
br_material* __cdecl SuffixedMaterial(br_material *pOld, char *pSuffix) {
    br_material *new_mat;
    char *new_id;
    LOG_TRACE("(%p, \"%s\")", pOld, pSuffix);

    (void)pOld;
    (void)pSuffix;
    (void)new_mat;
    (void)new_id;

    return original_SuffixedMaterial(pOld, pSuffix);
}

static int(__cdecl*original_FaceIsRoad)(br_model *, tU16) = (int(__cdecl*)(br_model *, tU16))0x00436027;
CARM95_HOOK_FUNCTION(original_FaceIsRoad, FaceIsRoad)
int __cdecl FaceIsRoad(br_model *pModel, tU16 pFace) {
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

static br_material *(__cdecl*original_RoadPerspToUntex)(br_model *, tU16) = (br_material *(__cdecl*)(br_model *, tU16))0x004365aa;
CARM95_HOOK_FUNCTION(original_RoadPerspToUntex, RoadPerspToUntex)
br_material* __cdecl RoadPerspToUntex(br_model *pModel, tU16 pFace) {
    br_material *old_mat;
    br_material *new_mat;
    LOG_TRACE("(%p, %u)", pModel, pFace);

    (void)pModel;
    (void)pFace;
    (void)old_mat;
    (void)new_mat;

    return original_RoadPerspToUntex(pModel, pFace);
}

static br_material *(__cdecl*original_WallPerspToLinear)(br_model *, tU16) = (br_material *(__cdecl*)(br_model *, tU16))0x00435ec1;
CARM95_HOOK_FUNCTION(original_WallPerspToLinear, WallPerspToLinear)
br_material* __cdecl WallPerspToLinear(br_model *pModel, tU16 pFace) {
    br_material *old_mat;
    br_material *new_mat;
    LOG_TRACE("(%p, %u)", pModel, pFace);

    (void)pModel;
    (void)pFace;
    (void)old_mat;
    (void)new_mat;

    return original_WallPerspToLinear(pModel, pFace);
}

static br_material *(__cdecl*original_WallPerspToUntex)(br_model *, tU16) = (br_material *(__cdecl*)(br_model *, tU16))0x00436269;
CARM95_HOOK_FUNCTION(original_WallPerspToUntex, WallPerspToUntex)
br_material* __cdecl WallPerspToUntex(br_model *pModel, tU16 pFace) {
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

static void(__cdecl*original_ProcessModelFaceMaterials)(br_model *, tPMFMCB*) = (void(__cdecl*)(br_model *, tPMFMCB*))0x00436640;
CARM95_HOOK_FUNCTION(original_ProcessModelFaceMaterials, ProcessModelFaceMaterials)
void __cdecl ProcessModelFaceMaterials(br_model *pModel, tPMFMCB pCallback) {
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

static int(__cdecl*original_LoadNTrackModels)(tBrender_storage *, FILE *, int) = (int(__cdecl*)(tBrender_storage *, FILE *, int))0x00436325;
CARM95_HOOK_FUNCTION(original_LoadNTrackModels, LoadNTrackModels)
int __cdecl LoadNTrackModels(tBrender_storage *pStorage_space, FILE *pF, int pCount) {
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

static void(__cdecl*original_LoadSomePixelmaps)(tBrender_storage *, FILE *) = (void(__cdecl*)(tBrender_storage *, FILE *))0x004366f3;
CARM95_HOOK_FUNCTION(original_LoadSomePixelmaps, LoadSomePixelmaps)
void __cdecl LoadSomePixelmaps(tBrender_storage *pStorage_space, FILE *pF) {
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

static void(__cdecl*original_LoadSomeShadeTables)(tBrender_storage *, FILE *) = (void(__cdecl*)(tBrender_storage *, FILE *))0x0043675d;
CARM95_HOOK_FUNCTION(original_LoadSomeShadeTables, LoadSomeShadeTables)
void __cdecl LoadSomeShadeTables(tBrender_storage *pStorage_space, FILE *pF) {
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

static void(__cdecl*original_LoadSomeMaterials)(tBrender_storage *, FILE *) = (void(__cdecl*)(tBrender_storage *, FILE *))0x004367c7;
CARM95_HOOK_FUNCTION(original_LoadSomeMaterials, LoadSomeMaterials)
void __cdecl LoadSomeMaterials(tBrender_storage *pStorage_space, FILE *pF) {
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

static void(__cdecl*original_LoadSomeModels)(tBrender_storage *, FILE *) = (void(__cdecl*)(tBrender_storage *, FILE *))0x00436831;
CARM95_HOOK_FUNCTION(original_LoadSomeModels, LoadSomeModels)
void __cdecl LoadSomeModels(tBrender_storage *pStorage_space, FILE *pF) {
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

static void(__cdecl*original_LoadSomeTrackModels)(tBrender_storage *, FILE *) = (void(__cdecl*)(tBrender_storage *, FILE *))0x0043689f;
CARM95_HOOK_FUNCTION(original_LoadSomeTrackModels, LoadSomeTrackModels)
void __cdecl LoadSomeTrackModels(tBrender_storage *pStorage_space, FILE *pF) {
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

static void(__cdecl*original_AddFunkGrooveBinding)(int, float *) = (void(__cdecl*)(int, float *))0x0043690d;
CARM95_HOOK_FUNCTION(original_AddFunkGrooveBinding, AddFunkGrooveBinding)
void __cdecl AddFunkGrooveBinding(int pSlot_number, float *pPeriod_address) {
    LOG_TRACE("(%d, %p)", pSlot_number, pPeriod_address);

    (void)pSlot_number;
    (void)pPeriod_address;

    original_AddFunkGrooveBinding(pSlot_number, pPeriod_address);
}

static void(__cdecl*original_ControlBoundFunkGroove)(int, float) = (void(__cdecl*)(int, float))0x0043694f;
CARM95_HOOK_FUNCTION(original_ControlBoundFunkGroove, ControlBoundFunkGroove)
void __cdecl ControlBoundFunkGroove(int pSlot_number, float pValue) {
    LOG_TRACE("(%d, %f)", pSlot_number, pValue);

    (void)pSlot_number;
    (void)pValue;

    original_ControlBoundFunkGroove(pSlot_number, pValue);
}

static float(__cdecl*original_ControlBoundFunkGroovePlus)(int, float) = (float(__cdecl*)(int, float))0x0043698f;
CARM95_HOOK_FUNCTION(original_ControlBoundFunkGroovePlus, ControlBoundFunkGroovePlus)
float __cdecl ControlBoundFunkGroovePlus(int pSlot_number, float pValue) {
    LOG_TRACE("(%d, %f)", pSlot_number, pValue);

    (void)pSlot_number;
    (void)pValue;

    return original_ControlBoundFunkGroovePlus(pSlot_number, pValue);
}

static void(__cdecl*original_ShiftBoundGrooveFunks)(char *, char *, int) = (void(__cdecl*)(char *, char *, int))0x00437dca;
CARM95_HOOK_FUNCTION(original_ShiftBoundGrooveFunks, ShiftBoundGrooveFunks)
void __cdecl ShiftBoundGrooveFunks(char *pStart, char *pEnd, int pDelta) {
    int i;
    LOG_TRACE("(\"%s\", \"%s\", %d)", pStart, pEnd, pDelta);

    (void)pStart;
    (void)pEnd;
    (void)pDelta;
    (void)i;

    original_ShiftBoundGrooveFunks(pStart, pEnd, pDelta);
}

static tFunkotronic_spec *(__cdecl*original_AddNewFunkotronic)() = (tFunkotronic_spec *(__cdecl*)())0x00437c4c;
CARM95_HOOK_FUNCTION(original_AddNewFunkotronic, AddNewFunkotronic)
tFunkotronic_spec* __cdecl AddNewFunkotronic() {
    void *new_array;
    int i;
    LOG_TRACE("()");

    (void)new_array;
    (void)i;

    return original_AddNewFunkotronic();
}

static void(__cdecl*original_DisposeFunkotronics)(int) = (void(__cdecl*)(int))0x004369fd;
CARM95_HOOK_FUNCTION(original_DisposeFunkotronics, DisposeFunkotronics)
void __cdecl DisposeFunkotronics(int pOwner) {
    int i;
    tFunkotronic_spec *the_funk;
    LOG_TRACE("(%d)", pOwner);

    (void)pOwner;
    (void)i;
    (void)the_funk;

    original_DisposeFunkotronics(pOwner);
}

static void(__cdecl*original_AddProximityVertex)(br_vector3 *, tFunkotronic_spec *) = (void(__cdecl*)(br_vector3 *, tFunkotronic_spec *))0x0043806e;
CARM95_HOOK_FUNCTION(original_AddProximityVertex, AddProximityVertex)
void __cdecl AddProximityVertex(br_vector3 *pV, tFunkotronic_spec *pThe_funk) {
    LOG_TRACE("(%p, %p)", pV, pThe_funk);

    (void)pV;
    (void)pThe_funk;

    original_AddProximityVertex(pV, pThe_funk);
}

static void(__cdecl*original_AddProximityVertexXYZ)(br_scalar, br_scalar, br_scalar, tFunkotronic_spec *) = (void(__cdecl*)(br_scalar, br_scalar, br_scalar, tFunkotronic_spec *))0x004380ad;
CARM95_HOOK_FUNCTION(original_AddProximityVertexXYZ, AddProximityVertexXYZ)
void __cdecl AddProximityVertexXYZ(br_scalar pX, br_scalar pY, br_scalar pZ, tFunkotronic_spec *pThe_funk) {
    br_vector3 v;
    LOG_TRACE("(%f, %f, %f, %p)", pX, pY, pZ, pThe_funk);

    (void)pX;
    (void)pY;
    (void)pZ;
    (void)pThe_funk;
    (void)v;

    original_AddProximityVertexXYZ(pX, pY, pZ, pThe_funk);
}

static br_uint_32(__cdecl*original_CalcProximities)(br_actor *, br_material *, tFunkotronic_spec *) = (br_uint_32(__cdecl*)(br_actor *, br_material *, tFunkotronic_spec *))0x00436af6;
CARM95_HOOK_FUNCTION(original_CalcProximities, CalcProximities)
br_uint_32 __cdecl CalcProximities(br_actor *pActor, br_material *pMat, tFunkotronic_spec *pThe_funk) {
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

static br_uint_32(__cdecl*original_AddProximities)(br_actor *, br_material *, tFunkotronic_spec *) = (br_uint_32(__cdecl*)(br_actor *, br_material *, tFunkotronic_spec *))0x00437e2f;
CARM95_HOOK_FUNCTION(original_AddProximities, AddProximities)
br_uint_32 __cdecl AddProximities(br_actor *pActor, br_material *pMat, tFunkotronic_spec *pThe_funk) {
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

static void(__cdecl*original_AddFunkotronics)(FILE *, int, int) = (void(__cdecl*)(FILE *, int, int))0x00436b8b;
CARM95_HOOK_FUNCTION(original_AddFunkotronics, AddFunkotronics)
void __cdecl AddFunkotronics(FILE *pF, int pOwner, int pRef_offset) {
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
    (void)__block0__x_0;
    (void)__block0__x_1;
    (void)__block1__x_0;
    (void)__block1__x_1;
    (void)__block1__d_0;
    (void)__block1__d_1;
    (void)__block2__x_0;
    (void)__block2__x_1;
    (void)__block3__x_0;
    (void)__block3__x_1;
    (void)__block3__d_0;
    (void)__block3__d_1;
    (void)__block4__x_0;
    (void)__block4__x_1;
    (void)__block4__d_0;
    (void)__block4__d_1;

    original_AddFunkotronics(pF, pOwner, pRef_offset);
}

static void(__cdecl*original_DisposeGroovidelics)(int) = (void(__cdecl*)(int))0x004380dd;
CARM95_HOOK_FUNCTION(original_DisposeGroovidelics, DisposeGroovidelics)
void __cdecl DisposeGroovidelics(int pOwner) {
    int i;
    tGroovidelic_spec *the_groove;
    LOG_TRACE("(%d)", pOwner);

    (void)pOwner;
    (void)i;
    (void)the_groove;

    original_DisposeGroovidelics(pOwner);
}

static tGroovidelic_spec *(__cdecl*original_AddNewGroovidelic)() = (tGroovidelic_spec *(__cdecl*)())0x00438eb1;
CARM95_HOOK_FUNCTION(original_AddNewGroovidelic, AddNewGroovidelic)
tGroovidelic_spec* __cdecl AddNewGroovidelic() {
    void *new_array;
    int i;
    LOG_TRACE("()");

    (void)new_array;
    (void)i;

    return original_AddNewGroovidelic();
}

static void(__cdecl*original_AddGroovidelics)(FILE *, int, br_actor *, int, int) = (void(__cdecl*)(FILE *, int, br_actor *, int, int))0x00438146;
CARM95_HOOK_FUNCTION(original_AddGroovidelics, AddGroovidelics)
void __cdecl AddGroovidelics(FILE *pF, int pOwner, br_actor *pParent_actor, int pRef_offset, int pAllowed_to_be_absent) {
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
    (void)__block0__x_0;
    (void)__block0__x_1;
    (void)__block0__x_2;
    (void)__block1__x_0;
    (void)__block1__x_1;
    (void)__block1__x_2;
    (void)__block2__x_0;
    (void)__block2__x_1;
    (void)__block2__x_2;
    (void)__block3__x_0;
    (void)__block3__x_1;
    (void)__block3__x_2;
    (void)__block4__x_0;
    (void)__block4__x_1;
    (void)__block4__x_2;
    (void)__block4__d_0;
    (void)__block4__d_1;
    (void)__block4__d_2;
    (void)__block5__x_0;
    (void)__block5__x_1;
    (void)__block5__x_2;
    (void)__block6__x_0;
    (void)__block6__x_1;
    (void)__block6__x_2;
    (void)__block6__d_0;
    (void)__block6__d_1;
    (void)__block6__d_2;
    (void)__block7__x_0;
    (void)__block7__x_1;
    (void)__block7__x_2;

    original_AddGroovidelics(pF, pOwner, pParent_actor, pRef_offset, pAllowed_to_be_absent);
}

static void(__cdecl*original_KillGroovadelic)(int) = (void(__cdecl*)(int))0x00439009;
CARM95_HOOK_FUNCTION(original_KillGroovadelic, KillGroovadelic)
void __cdecl KillGroovadelic(int pOwner) {
    int i;
    tGroovidelic_spec *the_groove;
    LOG_TRACE("(%d)", pOwner);

    (void)pOwner;
    (void)i;
    (void)the_groove;

    original_KillGroovadelic(pOwner);
}

static void(__cdecl*original_KillFunkotronic)(int) = (void(__cdecl*)(int))0x004390a0;
CARM95_HOOK_FUNCTION(original_KillFunkotronic, KillFunkotronic)
void __cdecl KillFunkotronic(int pOwner) {
    int i;
    tFunkotronic_spec *the_funk;
    LOG_TRACE("(%d)", pOwner);

    (void)pOwner;
    (void)i;
    (void)the_funk;

    original_KillFunkotronic(pOwner);
}

static br_uint_32(__cdecl*original_DeleteBastards)(br_actor *, br_matrix34 *, void *) = (br_uint_32(__cdecl*)(br_actor *, br_matrix34 *, void *))0x0043c666;
CARM95_HOOK_FUNCTION(original_DeleteBastards, DeleteBastards)
br_uint_32 __cdecl DeleteBastards(br_actor *pActor, br_matrix34 *pMatrix, void *pArg) {
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

static void(__cdecl*original_DeleteAnyZeroBastards)() = (void(__cdecl*)())0x0043c604;
CARM95_HOOK_FUNCTION(original_DeleteAnyZeroBastards, DeleteAnyZeroBastards)
void __cdecl DeleteAnyZeroBastards() {
    int i;
    LOG_TRACE("()");

    (void)i;

    original_DeleteAnyZeroBastards();
}

static br_uint_32(__cdecl*original_ApplyTransToModels)(br_actor *, br_matrix34 *, void *) = (br_uint_32(__cdecl*)(br_actor *, br_matrix34 *, void *))0x0043c775;
CARM95_HOOK_FUNCTION(original_ApplyTransToModels, ApplyTransToModels)
br_uint_32 __cdecl ApplyTransToModels(br_actor *pActor, br_matrix34 *pMatrix, void *pArg) {
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

static int(__cdecl*original_FindSpecVolIndex)(br_actor *) = (int(__cdecl*)(br_actor *))0x00439152;
CARM95_HOOK_FUNCTION(original_FindSpecVolIndex, FindSpecVolIndex)
int __cdecl FindSpecVolIndex(br_actor *pActor) {
    int i;
    tSpecial_volume *v;
    LOG_TRACE("(%p)", pActor);

    (void)pActor;
    (void)i;
    (void)v;

    return original_FindSpecVolIndex(pActor);
}

static void(__cdecl*original_MungeMaterial)(br_matrix34 *, br_material *, br_material *, int, int) = (void(__cdecl*)(br_matrix34 *, br_material *, br_material *, int, int))0x004392c4;
CARM95_HOOK_FUNCTION(original_MungeMaterial, MungeMaterial)
void __cdecl MungeMaterial(br_matrix34 *pMat, br_material *pMat_1, br_material *pMat_2, int pAxis_0, int pAxis_1) {
    LOG_TRACE("(%p, %p, %p, %d, %d)", pMat, pMat_1, pMat_2, pAxis_0, pAxis_1);

    (void)pMat;
    (void)pMat_1;
    (void)pMat_2;
    (void)pAxis_0;
    (void)pAxis_1;

    original_MungeMaterial(pMat, pMat_1, pMat_2, pAxis_0, pAxis_1);
}

static void(__cdecl*original_SetSpecVolMatSize)(br_actor *) = (void(__cdecl*)(br_actor *))0x00439226;
CARM95_HOOK_FUNCTION(original_SetSpecVolMatSize, SetSpecVolMatSize)
void __cdecl SetSpecVolMatSize(br_actor *pActor) {
    br_model *model;
    LOG_TRACE("(%p)", pActor);

    (void)pActor;
    (void)model;

    original_SetSpecVolMatSize(pActor);
}

static void(__cdecl*original_FindInverseAndWorldBox)(tSpecial_volume *) = (void(__cdecl*)(tSpecial_volume *))0x004393a7;
CARM95_HOOK_FUNCTION(original_FindInverseAndWorldBox, FindInverseAndWorldBox)
void __cdecl FindInverseAndWorldBox(tSpecial_volume *pSpec) {
    br_bounds bnds;
    LOG_TRACE("(%p)", pSpec);

    (void)pSpec;
    (void)bnds;

    original_FindInverseAndWorldBox(pSpec);
}

static void(__cdecl*original_UpdateSpecVol)() = (void(__cdecl*)())0x004391b7;
CARM95_HOOK_FUNCTION(original_UpdateSpecVol, UpdateSpecVol)
void __cdecl UpdateSpecVol() {
    int index;
    tSpecial_volume *v;
    LOG_TRACE("()");

    (void)index;
    (void)v;

    original_UpdateSpecVol();
}

static void(__cdecl*original_SaveSpecialVolumes)() = (void(__cdecl*)())0x0043c853;
CARM95_HOOK_FUNCTION(original_SaveSpecialVolumes, SaveSpecialVolumes)
void __cdecl SaveSpecialVolumes() {
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

static void(__cdecl*original_SaveAdditionalStuff)() = (void(__cdecl*)())0x0043c589;
CARM95_HOOK_FUNCTION(original_SaveAdditionalStuff, SaveAdditionalStuff)
void __cdecl SaveAdditionalStuff() {
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

static br_uint_32(__cdecl*original_ProcessFaceMaterials)(br_actor *, tPMFMCB*) = (br_uint_32(__cdecl*)(br_actor *, tPMFMCB*))0x00439ddd;
CARM95_HOOK_FUNCTION(original_ProcessFaceMaterials, ProcessFaceMaterials)
br_uint_32 __cdecl ProcessFaceMaterials(br_actor *pActor, tPMFMCB pCallback) {
    LOG_TRACE("(%p, %p)", pActor, pCallback);

    (void)pActor;
    (void)pCallback;

    return original_ProcessFaceMaterials(pActor, pCallback);
}

static int(__cdecl*original_DRPixelmapHasZeros)(br_pixelmap *) = (int(__cdecl*)(br_pixelmap *))0x00439597;
CARM95_HOOK_FUNCTION(original_DRPixelmapHasZeros, DRPixelmapHasZeros)
int __cdecl DRPixelmapHasZeros(br_pixelmap *pm) {
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

static int(__cdecl*original_StorageContainsPixelmap)(tBrender_storage *, br_pixelmap *) = (int(__cdecl*)(tBrender_storage *, br_pixelmap *))0x00439668;
CARM95_HOOK_FUNCTION(original_StorageContainsPixelmap, StorageContainsPixelmap)
int __cdecl StorageContainsPixelmap(tBrender_storage *pStorage, br_pixelmap *pMap) {
    int i;
    LOG_TRACE("(%p, %p)", pStorage, pMap);

    (void)pStorage;
    (void)pMap;
    (void)i;

    return original_StorageContainsPixelmap(pStorage, pMap);
}

static void(__cdecl*original_HideStoredOpaqueTextures)(tBrender_storage *) = (void(__cdecl*)(tBrender_storage *))0x004394b4;
CARM95_HOOK_FUNCTION(original_HideStoredOpaqueTextures, HideStoredOpaqueTextures)
void __cdecl HideStoredOpaqueTextures(tBrender_storage *pStorage) {
    int i;
    LOG_TRACE("(%p)", pStorage);

    (void)pStorage;
    (void)i;

    original_HideStoredOpaqueTextures(pStorage);
}

static void(__cdecl*original_RevealStoredTransparentTextures)(tBrender_storage *) = (void(__cdecl*)(tBrender_storage *))0x004396ce;
CARM95_HOOK_FUNCTION(original_RevealStoredTransparentTextures, RevealStoredTransparentTextures)
void __cdecl RevealStoredTransparentTextures(tBrender_storage *pStorage) {
    int i;
    LOG_TRACE("(%p)", pStorage);

    (void)pStorage;
    (void)i;

    original_RevealStoredTransparentTextures(pStorage);
}

static void(__cdecl*original_HideStoredTextures)(tBrender_storage *) = (void(__cdecl*)(tBrender_storage *))0x00439784;
CARM95_HOOK_FUNCTION(original_HideStoredTextures, HideStoredTextures)
void __cdecl HideStoredTextures(tBrender_storage *pStorage) {
    int i;
    LOG_TRACE("(%p)", pStorage);

    (void)pStorage;
    (void)i;

    original_HideStoredTextures(pStorage);
}

static void(__cdecl*original_RevealStoredTextures)(tBrender_storage *) = (void(__cdecl*)(tBrender_storage *))0x00439847;
CARM95_HOOK_FUNCTION(original_RevealStoredTextures, RevealStoredTextures)
void __cdecl RevealStoredTextures(tBrender_storage *pStorage) {
    int i;
    LOG_TRACE("(%p)", pStorage);

    (void)pStorage;
    (void)i;

    original_RevealStoredTextures(pStorage);
}

static void(__cdecl*original_SetCarStorageTexturingLevel)(tBrender_storage *, tCar_texturing_level, tCar_texturing_level) = (void(__cdecl*)(tBrender_storage *, tCar_texturing_level, tCar_texturing_level))0x0043940b;
CARM95_HOOK_FUNCTION(original_SetCarStorageTexturingLevel, SetCarStorageTexturingLevel)
void __cdecl SetCarStorageTexturingLevel(tBrender_storage *pStorage, tCar_texturing_level pNew, tCar_texturing_level pOld) {
    LOG_TRACE("(%p, %d, %d)", pStorage, pNew, pOld);

    (void)pStorage;
    (void)pNew;
    (void)pOld;

    original_SetCarStorageTexturingLevel(pStorage, pNew, pOld);
}

static tCar_texturing_level(__cdecl*original_GetCarTexturingLevel)() = (tCar_texturing_level(__cdecl*)())0x004398e0;
CARM95_HOOK_FUNCTION(original_GetCarTexturingLevel, GetCarTexturingLevel)
tCar_texturing_level __cdecl GetCarTexturingLevel() {
    LOG_TRACE("()");


    return original_GetCarTexturingLevel();
}

static void(__cdecl*original_SetCarTexturingLevel)(tCar_texturing_level) = (void(__cdecl*)(tCar_texturing_level))0x004398f5;
CARM95_HOOK_FUNCTION(original_SetCarTexturingLevel, SetCarTexturingLevel)
void __cdecl SetCarTexturingLevel(tCar_texturing_level pLevel) {
    LOG_TRACE("(%d)", pLevel);

    (void)pLevel;

    original_SetCarTexturingLevel(pLevel);
}

static int(__cdecl*original_HasThisSuffix)(char *, char *) = (int(__cdecl*)(char *, char *))0x00439a77;
CARM95_HOOK_FUNCTION(original_HasThisSuffix, HasThisSuffix)
int __cdecl HasThisSuffix(char *pIdent, char *pSuffix) {
    size_t len_ident;
    size_t len_suffix;
    LOG_TRACE("(\"%s\", \"%s\")", pIdent, pSuffix);

    (void)pIdent;
    (void)pSuffix;
    (void)len_ident;
    (void)len_suffix;

    return original_HasThisSuffix(pIdent, pSuffix);
}

static br_material *(__cdecl*original_UnsuffixedMaterial)(char *, char *) = (br_material *(__cdecl*)(char *, char *))0x00439bf4;
CARM95_HOOK_FUNCTION(original_UnsuffixedMaterial, UnsuffixedMaterial)
br_material* __cdecl UnsuffixedMaterial(char *pOld_ident, char *pSuffix) {
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

static br_material *(__cdecl*original_RoadUntexToPersp)(br_model *, tU16) = (br_material *(__cdecl*)(br_model *, tU16))0x00439e59;
CARM95_HOOK_FUNCTION(original_RoadUntexToPersp, RoadUntexToPersp)
br_material* __cdecl RoadUntexToPersp(br_model *pModel, tU16 pFace) {
    br_material *old_mat;
    br_material *new_mat;
    LOG_TRACE("(%p, %u)", pModel, pFace);

    (void)pModel;
    (void)pFace;
    (void)old_mat;
    (void)new_mat;

    return original_RoadUntexToPersp(pModel, pFace);
}

static br_material *(__cdecl*original_WallLinearToUntex)(br_model *, tU16) = (br_material *(__cdecl*)(br_model *, tU16))0x00439983;
CARM95_HOOK_FUNCTION(original_WallLinearToUntex, WallLinearToUntex)
br_material* __cdecl WallLinearToUntex(br_model *pModel, tU16 pFace) {
    br_material *old_mat;
    br_material *new_mat;
    LOG_TRACE("(%p, %u)", pModel, pFace);

    (void)pModel;
    (void)pFace;
    (void)old_mat;
    (void)new_mat;

    return original_WallLinearToUntex(pModel, pFace);
}

static br_material *(__cdecl*original_WallUntexToLinear)(br_model *, tU16) = (br_material *(__cdecl*)(br_model *, tU16))0x00439b2e;
CARM95_HOOK_FUNCTION(original_WallUntexToLinear, WallUntexToLinear)
br_material* __cdecl WallUntexToLinear(br_model *pModel, tU16 pFace) {
    br_material *old_mat;
    br_material *new_mat;
    LOG_TRACE("(%p, %u)", pModel, pFace);

    (void)pModel;
    (void)pFace;
    (void)old_mat;
    (void)new_mat;

    return original_WallUntexToLinear(pModel, pFace);
}

static br_material *(__cdecl*original_WallUntexToPersp)(br_model *, tU16) = (br_material *(__cdecl*)(br_model *, tU16))0x00439c7a;
CARM95_HOOK_FUNCTION(original_WallUntexToPersp, WallUntexToPersp)
br_material* __cdecl WallUntexToPersp(br_model *pModel, tU16 pFace) {
    br_material *old_mat;
    br_material *new_mat;
    LOG_TRACE("(%p, %u)", pModel, pFace);

    (void)pModel;
    (void)pFace;
    (void)old_mat;
    (void)new_mat;

    return original_WallUntexToPersp(pModel, pFace);
}

static br_material *(__cdecl*original_WallLinearToPersp)(br_model *, tU16) = (br_material *(__cdecl*)(br_model *, tU16))0x00439d11;
CARM95_HOOK_FUNCTION(original_WallLinearToPersp, WallLinearToPersp)
br_material* __cdecl WallLinearToPersp(br_model *pModel, tU16 pFace) {
    br_material *old_mat;
    br_material *new_mat;
    LOG_TRACE("(%p, %u)", pModel, pFace);

    (void)pModel;
    (void)pFace;
    (void)old_mat;
    (void)new_mat;

    return original_WallLinearToPersp(pModel, pFace);
}

static tRoad_texturing_level(__cdecl*original_GetRoadTexturingLevel)() = (tRoad_texturing_level(__cdecl*)())0x00439d73;
CARM95_HOOK_FUNCTION(original_GetRoadTexturingLevel, GetRoadTexturingLevel)
tRoad_texturing_level __cdecl GetRoadTexturingLevel() {
    LOG_TRACE("()");


    return original_GetRoadTexturingLevel();
}

static void(__cdecl*original_SetRoadTexturingLevel)(tRoad_texturing_level) = (void(__cdecl*)(tRoad_texturing_level))0x00439d88;
CARM95_HOOK_FUNCTION(original_SetRoadTexturingLevel, SetRoadTexturingLevel)
void __cdecl SetRoadTexturingLevel(tRoad_texturing_level pLevel) {
    LOG_TRACE("(%d)", pLevel);

    (void)pLevel;

    original_SetRoadTexturingLevel(pLevel);
}

static void(__cdecl*original_ReallySetRoadTexturingLevel)(tRoad_texturing_level) = (void(__cdecl*)(tRoad_texturing_level))0x00439d9b;
CARM95_HOOK_FUNCTION(original_ReallySetRoadTexturingLevel, ReallySetRoadTexturingLevel)
void __cdecl ReallySetRoadTexturingLevel(tRoad_texturing_level pLevel) {
    LOG_TRACE("(%d)", pLevel);

    (void)pLevel;

    original_ReallySetRoadTexturingLevel(pLevel);
}

static tWall_texturing_level(__cdecl*original_GetWallTexturingLevel)() = (tWall_texturing_level(__cdecl*)())0x00439ec1;
CARM95_HOOK_FUNCTION(original_GetWallTexturingLevel, GetWallTexturingLevel)
tWall_texturing_level __cdecl GetWallTexturingLevel() {
    LOG_TRACE("()");


    return original_GetWallTexturingLevel();
}

static void(__cdecl*original_SetWallTexturingLevel)(tWall_texturing_level) = (void(__cdecl*)(tWall_texturing_level))0x00439ed6;
CARM95_HOOK_FUNCTION(original_SetWallTexturingLevel, SetWallTexturingLevel)
void __cdecl SetWallTexturingLevel(tWall_texturing_level pLevel) {
    LOG_TRACE("(%d)", pLevel);

    (void)pLevel;

    original_SetWallTexturingLevel(pLevel);
}

static void(__cdecl*original_ReallySetWallTexturingLevel)(tWall_texturing_level) = (void(__cdecl*)(tWall_texturing_level))0x00439ee9;
CARM95_HOOK_FUNCTION(original_ReallySetWallTexturingLevel, ReallySetWallTexturingLevel)
void __cdecl ReallySetWallTexturingLevel(tWall_texturing_level pLevel) {
    static tPMFMCB*tweaker[3][3];
    LOG_TRACE("(%d)", pLevel);

    (void)pLevel;
    (void)tweaker;

    original_ReallySetWallTexturingLevel(pLevel);
}

static br_material *(__cdecl*original_DisposeSuffixedMaterials)(br_model *, tU16) = (br_material *(__cdecl*)(br_model *, tU16))0x0043cdec;
CARM95_HOOK_FUNCTION(original_DisposeSuffixedMaterials, DisposeSuffixedMaterials)
br_material* __cdecl DisposeSuffixedMaterials(br_model *pModel, tU16 pFace) {
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

static void(__cdecl*original_DisposeTexturingMaterials)() = (void(__cdecl*)())0x0043cd4f;
CARM95_HOOK_FUNCTION(original_DisposeTexturingMaterials, DisposeTexturingMaterials)
void __cdecl DisposeTexturingMaterials() {
    LOG_TRACE("()");


    original_DisposeTexturingMaterials();
}

static br_uint_32(__cdecl*original_SetAccessoryRenderingCB)(br_actor *, void *) = (br_uint_32(__cdecl*)(br_actor *, void *))0x00439f27;
CARM95_HOOK_FUNCTION(original_SetAccessoryRenderingCB, SetAccessoryRenderingCB)
br_uint_32 __cdecl SetAccessoryRenderingCB(br_actor *pActor, void *pFlag) {
    LOG_TRACE("(%p, %p)", pActor, pFlag);

    (void)pActor;
    (void)pFlag;

    return original_SetAccessoryRenderingCB(pActor, pFlag);
}

static void(__cdecl*original_SetAccessoryRendering)(int) = (void(__cdecl*)(int))0x00439f63;
CARM95_HOOK_FUNCTION(original_SetAccessoryRendering, SetAccessoryRendering)
void __cdecl SetAccessoryRendering(int pOn) {
    int style;
    LOG_TRACE("(%d)", pOn);

    (void)pOn;
    (void)style;

    original_SetAccessoryRendering(pOn);
}

static int(__cdecl*original_GetAccessoryRendering)() = (int(__cdecl*)())0x00439fba;
CARM95_HOOK_FUNCTION(original_GetAccessoryRendering, GetAccessoryRendering)
int __cdecl GetAccessoryRendering() {
    LOG_TRACE("()");


    return original_GetAccessoryRendering();
}

static void(__cdecl*original_SetCarSimplificationLevel)(int) = (void(__cdecl*)(int))0x00439fcf;
CARM95_HOOK_FUNCTION(original_SetCarSimplificationLevel, SetCarSimplificationLevel)
void __cdecl SetCarSimplificationLevel(int pLevel) {
    LOG_TRACE("(%d)", pLevel);

    (void)pLevel;

    original_SetCarSimplificationLevel(pLevel);
}

static int(__cdecl*original_GetCarSimplificationLevel)() = (int(__cdecl*)())0x00439fe2;
CARM95_HOOK_FUNCTION(original_GetCarSimplificationLevel, GetCarSimplificationLevel)
int __cdecl GetCarSimplificationLevel() {
    LOG_TRACE("()");


    return original_GetCarSimplificationLevel();
}

static void(__cdecl*original_ParseSpecialVolume)(FILE *, tSpecial_volume *, char *) = (void(__cdecl*)(FILE *, tSpecial_volume *, char *))0x00439ff7;
CARM95_HOOK_FUNCTION(original_ParseSpecialVolume, ParseSpecialVolume)
void __cdecl ParseSpecialVolume(FILE *pF, tSpecial_volume *pSpec, char *pScreen_name_str) {
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

static void(__cdecl*original_LoadTrack)(char *, tTrack_spec *, tRace_info *) = (void(__cdecl*)(char *, tTrack_spec *, tRace_info *))0x0043a136;
CARM95_HOOK_FUNCTION(original_LoadTrack, LoadTrack)
void __cdecl LoadTrack(char *pFile_name, tTrack_spec *pTrack_spec, tRace_info *pRace_info) {
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

static br_uint_32(__cdecl*original_RemoveBounds)(br_actor *, void *) = (br_uint_32(__cdecl*)(br_actor *, void *))0x0043cf3f;
CARM95_HOOK_FUNCTION(original_RemoveBounds, RemoveBounds)
br_uint_32 __cdecl RemoveBounds(br_actor *pActor, void *pArg) {
    LOG_TRACE("(%p, %p)", pActor, pArg);

    (void)pActor;
    (void)pArg;

    return original_RemoveBounds(pActor, pArg);
}

static void(__cdecl*original_RemoveBoundsStructures)(br_actor *) = (void(__cdecl*)(br_actor *))0x0043cf21;
CARM95_HOOK_FUNCTION(original_RemoveBoundsStructures, RemoveBoundsStructures)
void __cdecl RemoveBoundsStructures(br_actor *pActor) {
    LOG_TRACE("(%p)", pActor);

    (void)pActor;

    original_RemoveBoundsStructures(pActor);
}

static void(__cdecl*original_FreeTrack)(tTrack_spec *) = (void(__cdecl*)(tTrack_spec *))0x0043cb89;
CARM95_HOOK_FUNCTION(original_FreeTrack, FreeTrack)
void __cdecl FreeTrack(tTrack_spec *pTrack_spec) {
    int i;
    tNon_car_spec *non_car;
    LOG_TRACE("(%p)", pTrack_spec);

    (void)pTrack_spec;
    (void)i;
    (void)non_car;

    original_FreeTrack(pTrack_spec);
}

static void(__cdecl*original_ProcessTrack)(br_actor *, tTrack_spec *, br_actor *, br_matrix34 *, int) = (void(__cdecl*)(br_actor *, tTrack_spec *, br_actor *, br_matrix34 *, int))0x0043cf8c;
CARM95_HOOK_FUNCTION(original_ProcessTrack, ProcessTrack)
void __cdecl ProcessTrack(br_actor *pWorld, tTrack_spec *pTrack_spec, br_actor *pCamera, br_matrix34 *pCamera_to_world_transform, int pRender_blends) {
    LOG_TRACE("(%p, %p, %p, %p, %d)", pWorld, pTrack_spec, pCamera, pCamera_to_world_transform, pRender_blends);

    (void)pWorld;
    (void)pTrack_spec;
    (void)pCamera;
    (void)pCamera_to_world_transform;
    (void)pRender_blends;

    original_ProcessTrack(pWorld, pTrack_spec, pCamera, pCamera_to_world_transform, pRender_blends);
}

static br_scalar(__cdecl*original_NormaliseDegreeAngle)(br_scalar) = (br_scalar(__cdecl*)(br_scalar))0x0043cfd8;
CARM95_HOOK_FUNCTION(original_NormaliseDegreeAngle, NormaliseDegreeAngle)
br_scalar __cdecl NormaliseDegreeAngle(br_scalar pAngle) {
    LOG_TRACE("(%f)", pAngle);

    (void)pAngle;

    return original_NormaliseDegreeAngle(pAngle);
}

static void(__cdecl*original_FunkThoseTronics)() = (void(__cdecl*)())0x0043d010;
CARM95_HOOK_FUNCTION(original_FunkThoseTronics, FunkThoseTronics)
void __cdecl FunkThoseTronics() {
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

static void(__cdecl*original_LollipopizeActor)(br_actor *, br_matrix34 *, tLollipop_mode) = (void(__cdecl*)(br_actor *, br_matrix34 *, tLollipop_mode))0x0043f3c3;
CARM95_HOOK_FUNCTION(original_LollipopizeActor, LollipopizeActor)
void __cdecl LollipopizeActor(br_actor *pSubject_actor, br_matrix34 *ref_to_world, tLollipop_mode pWhich_axis) {
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
    (void)__block0___scale;

    original_LollipopizeActor(pSubject_actor, ref_to_world, pWhich_axis);
}

static void(__cdecl*original_CalcActorGlobalPos)(br_vector3 *, br_actor *) = (void(__cdecl*)(br_vector3 *, br_actor *))0x0043f6c2;
CARM95_HOOK_FUNCTION(original_CalcActorGlobalPos, CalcActorGlobalPos)
void __cdecl CalcActorGlobalPos(br_vector3 *pResult, br_actor *pActor) {
    LOG_TRACE("(%p, %p)", pResult, pActor);

    (void)pResult;
    (void)pActor;

    original_CalcActorGlobalPos(pResult, pActor);
}

static int(__cdecl*original_PointOutOfSight)(br_vector3 *, br_scalar) = (int(__cdecl*)(br_vector3 *, br_scalar))0x0043f744;
CARM95_HOOK_FUNCTION(original_PointOutOfSight, PointOutOfSight)
int __cdecl PointOutOfSight(br_vector3 *pPoint, br_scalar pMax_distance) {
    br_vector3 distance_vector;
    LOG_TRACE("(%p, %f)", pPoint, pMax_distance);

    (void)pPoint;
    (void)pMax_distance;
    (void)distance_vector;

    return original_PointOutOfSight(pPoint, pMax_distance);
}

static void(__cdecl*original_PathGrooveBastard)(tGroovidelic_spec *, tU32, br_matrix34 *, int) = (void(__cdecl*)(tGroovidelic_spec *, tU32, br_matrix34 *, int))0x0043fb08;
CARM95_HOOK_FUNCTION(original_PathGrooveBastard, PathGrooveBastard)
void __cdecl PathGrooveBastard(tGroovidelic_spec *pGroove, tU32 pTime, br_matrix34 *pMat, int pInterrupt_it) {
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

static void(__cdecl*original_GrooveThisDelic)(tGroovidelic_spec *, tU32, int) = (void(__cdecl*)(tGroovidelic_spec *, tU32, int))0x0043f886;
CARM95_HOOK_FUNCTION(original_GrooveThisDelic, GrooveThisDelic)
void __cdecl GrooveThisDelic(tGroovidelic_spec *pGroove, tU32 pTime, int pInterrupt_it) {
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

static void(__cdecl*original_GrooveThoseDelics)() = (void(__cdecl*)())0x004430dd;
CARM95_HOOK_FUNCTION(original_GrooveThoseDelics, GrooveThoseDelics)
void __cdecl GrooveThoseDelics() {
    int i;
    tGroovidelic_spec *the_groove;
    float f_the_time;
    LOG_TRACE("()");

    (void)i;
    (void)the_groove;
    (void)f_the_time;

    original_GrooveThoseDelics();
}

static void(__cdecl*original_StopGroovidelic)(br_actor *) = (void(__cdecl*)(br_actor *))0x00443186;
CARM95_HOOK_FUNCTION(original_StopGroovidelic, StopGroovidelic)
void __cdecl StopGroovidelic(br_actor *pActor) {
    int i;
    tGroovidelic_spec *the_groove;
    LOG_TRACE("(%p)", pActor);

    (void)pActor;
    (void)i;
    (void)the_groove;

    original_StopGroovidelic(pActor);
}

static void(__cdecl*original_SetGrooveInterrupt)(int, br_matrix34 *, int, int, float, float) = (void(__cdecl*)(int, br_matrix34 *, int, int, float, float))0x00443208;
CARM95_HOOK_FUNCTION(original_SetGrooveInterrupt, SetGrooveInterrupt)
void __cdecl SetGrooveInterrupt(int pGroove_index, br_matrix34 *pMatrix, int pPath_interrupt, int pObject_interrupt, float pPath_resumption, float pObject_resumption) {
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

static void(__cdecl*original_ResetGrooveFlags)() = (void(__cdecl*)())0x0044325f;
CARM95_HOOK_FUNCTION(original_ResetGrooveFlags, ResetGrooveFlags)
void __cdecl ResetGrooveFlags() {
    int i;
    tGroovidelic_spec *the_groove;
    LOG_TRACE("()");

    (void)i;
    (void)the_groove;

    original_ResetGrooveFlags();
}

static tSpecial_volume *(__cdecl*original_GetDefaultSpecialVolumeForWater)() = (tSpecial_volume *(__cdecl*)())0x004432a9;
CARM95_HOOK_FUNCTION(original_GetDefaultSpecialVolumeForWater, GetDefaultSpecialVolumeForWater)
tSpecial_volume* __cdecl GetDefaultSpecialVolumeForWater() {
    LOG_TRACE("()");


    return original_GetDefaultSpecialVolumeForWater();
}

static tSpecial_volume *(__cdecl*original_FindSpecialVolume)(br_vector3 *, tSpecial_volume *) = (tSpecial_volume *(__cdecl*)(br_vector3 *, tSpecial_volume *))0x004432be;
CARM95_HOOK_FUNCTION(original_FindSpecialVolume, FindSpecialVolume)
tSpecial_volume* __cdecl FindSpecialVolume(br_vector3 *pP, tSpecial_volume *pLast_vol) {
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

static void(__cdecl*original_SaveAdditionalActors)() = (void(__cdecl*)())0x00443448;
CARM95_HOOK_FUNCTION(original_SaveAdditionalActors, SaveAdditionalActors)
void __cdecl SaveAdditionalActors() {
    LOG_TRACE("()");


    original_SaveAdditionalActors();
}

static br_scalar(__cdecl*original_DistanceFromFace)(br_vector3 *, tFace_ref *) = (br_scalar(__cdecl*)(br_vector3 *, tFace_ref *))0x00443465;
CARM95_HOOK_FUNCTION(original_DistanceFromFace, DistanceFromFace)
br_scalar __cdecl DistanceFromFace(br_vector3 *pPos, tFace_ref *pFace) {
    br_vector3 normal;
    LOG_TRACE("(%p, %p)", pPos, pFace);

    (void)pPos;
    (void)pFace;
    (void)normal;

    return original_DistanceFromFace(pPos, pFace);
}

static br_uint_32(__cdecl*original_CalcHighestID)(br_actor *, int *) = (br_uint_32(__cdecl*)(br_actor *, int *))0x00443e52;
CARM95_HOOK_FUNCTION(original_CalcHighestID, CalcHighestID)
br_uint_32 __cdecl CalcHighestID(br_actor *pActor, int *pHighest) {
    char s[256];
    int number;
    LOG_TRACE("(%p, %p)", pActor, pHighest);

    (void)pActor;
    (void)pHighest;
    (void)s;
    (void)number;

    return original_CalcHighestID(pActor, pHighest);
}

static br_uint_32(__cdecl*original_SetID)(br_actor *, void *) = (br_uint_32(__cdecl*)(br_actor *, void *))0x004435e0;
CARM95_HOOK_FUNCTION(original_SetID, SetID)
br_uint_32 __cdecl SetID(br_actor *pActor, void *pArg) {
    char s[256];
    LOG_TRACE("(%p, %p)", pActor, pArg);

    (void)pActor;
    (void)pArg;
    (void)s;

    return original_SetID(pActor, pArg);
}

static void(__cdecl*original_UniquificateActorsName)(br_actor *, br_actor *) = (void(__cdecl*)(br_actor *, br_actor *))0x004434a5;
CARM95_HOOK_FUNCTION(original_UniquificateActorsName, UniquificateActorsName)
void __cdecl UniquificateActorsName(br_actor *pUniverse_actor, br_actor *pActor) {
    int highest;
    LOG_TRACE("(%p, %p)", pUniverse_actor, pActor);

    (void)pUniverse_actor;
    (void)pActor;
    (void)highest;

    original_UniquificateActorsName(pUniverse_actor, pActor);
}

static void(__cdecl*original_AccessoryHeadup)(br_actor *, char *) = (void(__cdecl*)(br_actor *, char *))0x00443d5b;
CARM95_HOOK_FUNCTION(original_AccessoryHeadup, AccessoryHeadup)
void __cdecl AccessoryHeadup(br_actor *pActor, char *pPrefix) {
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

static br_uint_32(__cdecl*original_CalcHighestNonAmID)(br_actor *, int *) = (br_uint_32(__cdecl*)(br_actor *, int *))0x00443504;
CARM95_HOOK_FUNCTION(original_CalcHighestNonAmID, CalcHighestNonAmID)
br_uint_32 __cdecl CalcHighestNonAmID(br_actor *pActor, int *pHighest) {
    char s[256];
    int number;
    LOG_TRACE("(%p, %p)", pActor, pHighest);

    (void)pActor;
    (void)pHighest;
    (void)s;
    (void)number;

    return original_CalcHighestNonAmID(pActor, pHighest);
}

static br_uint_32(__cdecl*original_SetIDAndDupModel)(br_actor *, void *) = (br_uint_32(__cdecl*)(br_actor *, void *))0x00443ef5;
CARM95_HOOK_FUNCTION(original_SetIDAndDupModel, SetIDAndDupModel)
br_uint_32 __cdecl SetIDAndDupModel(br_actor *pActor, void *pArg) {
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

static void(__cdecl*original_DuplicateIfNotAmpersand)(br_actor *) = (void(__cdecl*)(br_actor *))0x00443df2;
CARM95_HOOK_FUNCTION(original_DuplicateIfNotAmpersand, DuplicateIfNotAmpersand)
void __cdecl DuplicateIfNotAmpersand(br_actor *pActor) {
    int highest;
    LOG_TRACE("(%p)", pActor);

    (void)pActor;
    (void)highest;

    original_DuplicateIfNotAmpersand(pActor);
}

static void(__cdecl*original_DropActor)(int) = (void(__cdecl*)(int))0x004436c2;
CARM95_HOOK_FUNCTION(original_DropActor, DropActor)
void __cdecl DropActor(int pIndex) {
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

static void(__cdecl*original_DropActor0)() = (void(__cdecl*)())0x00444145;
CARM95_HOOK_FUNCTION(original_DropActor0, DropActor0)
void __cdecl DropActor0() {
    LOG_TRACE("()");


    original_DropActor0();
}

static void(__cdecl*original_DropActor1)() = (void(__cdecl*)())0x0044415a;
CARM95_HOOK_FUNCTION(original_DropActor1, DropActor1)
void __cdecl DropActor1() {
    LOG_TRACE("()");


    original_DropActor1();
}

static void(__cdecl*original_DropActor2)() = (void(__cdecl*)())0x0044416f;
CARM95_HOOK_FUNCTION(original_DropActor2, DropActor2)
void __cdecl DropActor2() {
    LOG_TRACE("()");


    original_DropActor2();
}

static void(__cdecl*original_DropActor3)() = (void(__cdecl*)())0x00444184;
CARM95_HOOK_FUNCTION(original_DropActor3, DropActor3)
void __cdecl DropActor3() {
    LOG_TRACE("()");


    original_DropActor3();
}

static void(__cdecl*original_DropActor4)() = (void(__cdecl*)())0x00444199;
CARM95_HOOK_FUNCTION(original_DropActor4, DropActor4)
void __cdecl DropActor4() {
    LOG_TRACE("()");


    original_DropActor4();
}

static void(__cdecl*original_DropActor5)() = (void(__cdecl*)())0x004441ae;
CARM95_HOOK_FUNCTION(original_DropActor5, DropActor5)
void __cdecl DropActor5() {
    LOG_TRACE("()");


    original_DropActor5();
}

static void(__cdecl*original_DropActor6)() = (void(__cdecl*)())0x004441c3;
CARM95_HOOK_FUNCTION(original_DropActor6, DropActor6)
void __cdecl DropActor6() {
    LOG_TRACE("()");


    original_DropActor6();
}

static void(__cdecl*original_DropActor7)() = (void(__cdecl*)())0x004441d8;
CARM95_HOOK_FUNCTION(original_DropActor7, DropActor7)
void __cdecl DropActor7() {
    LOG_TRACE("()");


    original_DropActor7();
}

static void(__cdecl*original_DropActor8)() = (void(__cdecl*)())0x004441ed;
CARM95_HOOK_FUNCTION(original_DropActor8, DropActor8)
void __cdecl DropActor8() {
    LOG_TRACE("()");


    original_DropActor8();
}

static void(__cdecl*original_DropActor9)() = (void(__cdecl*)())0x00444202;
CARM95_HOOK_FUNCTION(original_DropActor9, DropActor9)
void __cdecl DropActor9() {
    LOG_TRACE("()");


    original_DropActor9();
}

static br_uint_32(__cdecl*original_IdentifyAccCB)(br_actor *, void *) = (br_uint_32(__cdecl*)(br_actor *, void *))0x00444275;
CARM95_HOOK_FUNCTION(original_IdentifyAccCB, IdentifyAccCB)
br_uint_32 __cdecl IdentifyAccCB(br_actor *pActor, void *pArg) {
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

static void(__cdecl*original_IdentifyAcc)() = (void(__cdecl*)())0x00444217;
CARM95_HOOK_FUNCTION(original_IdentifyAcc, IdentifyAcc)
void __cdecl IdentifyAcc() {
    LOG_TRACE("()");


    original_IdentifyAcc();
}

static br_uint_32(__cdecl*original_DelGrooveRef)(br_actor *, void *) = (br_uint_32(__cdecl*)(br_actor *, void *))0x0044443b;
CARM95_HOOK_FUNCTION(original_DelGrooveRef, DelGrooveRef)
br_uint_32 __cdecl DelGrooveRef(br_actor *pActor, void *pArg) {
    tGroovidelic_spec *the_groove;
    int i;
    LOG_TRACE("(%p, %p)", pActor, pArg);

    (void)pActor;
    (void)pArg;
    (void)the_groove;
    (void)i;

    return original_DelGrooveRef(pActor, pArg);
}

static br_uint_32(__cdecl*original_DelReferencedModels)(br_actor *, void *) = (br_uint_32(__cdecl*)(br_actor *, void *))0x0044449a;
CARM95_HOOK_FUNCTION(original_DelReferencedModels, DelReferencedModels)
br_uint_32 __cdecl DelReferencedModels(br_actor *pActor, void *pArg) {
    tGroovidelic_spec *the_groove;
    int i;
    LOG_TRACE("(%p, %p)", pActor, pArg);

    (void)pActor;
    (void)pArg;
    (void)the_groove;
    (void)i;

    return original_DelReferencedModels(pActor, pArg);
}

static void(__cdecl*original_DeleteAcc)() = (void(__cdecl*)())0x004443bb;
CARM95_HOOK_FUNCTION(original_DeleteAcc, DeleteAcc)
void __cdecl DeleteAcc() {
    LOG_TRACE("()");


    original_DeleteAcc();
}

static br_uint_32(__cdecl*original_OffsetModel)(br_actor *, void *) = (br_uint_32(__cdecl*)(br_actor *, void *))0x00444737;
CARM95_HOOK_FUNCTION(original_OffsetModel, OffsetModel)
br_uint_32 __cdecl OffsetModel(br_actor *pActor, void *pArg) {
    int i;
    LOG_TRACE("(%p, %p)", pActor, pArg);

    (void)pActor;
    (void)pArg;
    (void)i;

    return original_OffsetModel(pActor, pArg);
}

static void(__cdecl*original_OffsetActor)(br_actor *, br_vector3 *) = (void(__cdecl*)(br_actor *, br_vector3 *))0x00444717;
CARM95_HOOK_FUNCTION(original_OffsetActor, OffsetActor)
void __cdecl OffsetActor(br_actor *pActor, br_vector3 *pOffset) {
    LOG_TRACE("(%p, %p)", pActor, pOffset);

    (void)pActor;
    (void)pOffset;

    original_OffsetActor(pActor, pOffset);
}

static void(__cdecl*original_CentreActor)(br_actor *, br_vector3 *) = (void(__cdecl*)(br_actor *, br_vector3 *))0x00444803;
CARM95_HOOK_FUNCTION(original_CentreActor, CentreActor)
void __cdecl CentreActor(br_actor *pActor, br_vector3 *pOffset) {
    LOG_TRACE("(%p, %p)", pActor, pOffset);

    (void)pActor;
    (void)pOffset;

    original_CentreActor(pActor, pOffset);
}

static void(__cdecl*original_SnapAccToVertical)() = (void(__cdecl*)())0x00444538;
CARM95_HOOK_FUNCTION(original_SnapAccToVertical, SnapAccToVertical)
void __cdecl SnapAccToVertical() {
    LOG_TRACE("()");


    original_SnapAccToVertical();
}

static void(__cdecl*original_RotateAccessory)(br_angle) = (void(__cdecl*)(br_angle))0x004445d9;
CARM95_HOOK_FUNCTION(original_RotateAccessory, RotateAccessory)
void __cdecl RotateAccessory(br_angle pAngle) {
    br_vector3 mr_offset;
    LOG_TRACE("(%u)", pAngle);

    (void)pAngle;
    (void)mr_offset;

    original_RotateAccessory(pAngle);
}

static void(__cdecl*original_ScaleAccessory)(float) = (void(__cdecl*)(float))0x00444b74;
CARM95_HOOK_FUNCTION(original_ScaleAccessory, ScaleAccessory)
void __cdecl ScaleAccessory(float pScaling_factor) {
    br_vector3 mr_offset;
    LOG_TRACE("(%f)", pScaling_factor);

    (void)pScaling_factor;
    (void)mr_offset;

    original_ScaleAccessory(pScaling_factor);
}

static void(__cdecl*original_MoveAccessory)(br_scalar, br_scalar, br_scalar) = (void(__cdecl*)(br_scalar, br_scalar, br_scalar))0x00444d87;
CARM95_HOOK_FUNCTION(original_MoveAccessory, MoveAccessory)
void __cdecl MoveAccessory(br_scalar pX_shift, br_scalar pY_shift, br_scalar pZ_shift) {
    br_vector3 v;
    LOG_TRACE("(%f, %f, %f)", pX_shift, pY_shift, pZ_shift);

    (void)pX_shift;
    (void)pY_shift;
    (void)pZ_shift;
    (void)v;

    original_MoveAccessory(pX_shift, pY_shift, pZ_shift);
}

static void(__cdecl*original_RotateAccL)() = (void(__cdecl*)())0x004445c1;
CARM95_HOOK_FUNCTION(original_RotateAccL, RotateAccL)
void __cdecl RotateAccL() {
    LOG_TRACE("()");


    original_RotateAccL();
}

static void(__cdecl*original_RotateAccL2)() = (void(__cdecl*)())0x0044491e;
CARM95_HOOK_FUNCTION(original_RotateAccL2, RotateAccL2)
void __cdecl RotateAccL2() {
    LOG_TRACE("()");


    original_RotateAccL2();
}

static void(__cdecl*original_RotateAccL3)() = (void(__cdecl*)())0x00444936;
CARM95_HOOK_FUNCTION(original_RotateAccL3, RotateAccL3)
void __cdecl RotateAccL3() {
    LOG_TRACE("()");


    original_RotateAccL3();
}

static void(__cdecl*original_RotateAccL4)() = (void(__cdecl*)())0x0044494e;
CARM95_HOOK_FUNCTION(original_RotateAccL4, RotateAccL4)
void __cdecl RotateAccL4() {
    LOG_TRACE("()");


    original_RotateAccL4();
}

static void(__cdecl*original_RotateAccR)() = (void(__cdecl*)())0x00444966;
CARM95_HOOK_FUNCTION(original_RotateAccR, RotateAccR)
void __cdecl RotateAccR() {
    LOG_TRACE("()");


    original_RotateAccR();
}

static void(__cdecl*original_RotateAccR2)() = (void(__cdecl*)())0x0044497e;
CARM95_HOOK_FUNCTION(original_RotateAccR2, RotateAccR2)
void __cdecl RotateAccR2() {
    LOG_TRACE("()");


    original_RotateAccR2();
}

static void(__cdecl*original_RotateAccR3)() = (void(__cdecl*)())0x00444996;
CARM95_HOOK_FUNCTION(original_RotateAccR3, RotateAccR3)
void __cdecl RotateAccR3() {
    LOG_TRACE("()");


    original_RotateAccR3();
}

static void(__cdecl*original_RotateAccR4)() = (void(__cdecl*)())0x004449ae;
CARM95_HOOK_FUNCTION(original_RotateAccR4, RotateAccR4)
void __cdecl RotateAccR4() {
    LOG_TRACE("()");


    original_RotateAccR4();
}

static void(__cdecl*original_CycleAccRotate)() = (void(__cdecl*)())0x004449c6;
CARM95_HOOK_FUNCTION(original_CycleAccRotate, CycleAccRotate)
void __cdecl CycleAccRotate() {
    LOG_TRACE("()");


    original_CycleAccRotate();
}

static void(__cdecl*original_CycleAccScale)() = (void(__cdecl*)())0x00444a82;
CARM95_HOOK_FUNCTION(original_CycleAccScale, CycleAccScale)
void __cdecl CycleAccScale() {
    LOG_TRACE("()");


    original_CycleAccScale();
}

static void(__cdecl*original_ScaleAccUp2)() = (void(__cdecl*)())0x00444b5c;
CARM95_HOOK_FUNCTION(original_ScaleAccUp2, ScaleAccUp2)
void __cdecl ScaleAccUp2() {
    LOG_TRACE("()");


    original_ScaleAccUp2();
}

static void(__cdecl*original_ScaleAccUp3)() = (void(__cdecl*)())0x00444cf3;
CARM95_HOOK_FUNCTION(original_ScaleAccUp3, ScaleAccUp3)
void __cdecl ScaleAccUp3() {
    LOG_TRACE("()");


    original_ScaleAccUp3();
}

static void(__cdecl*original_ScaleAccUp4)() = (void(__cdecl*)())0x00444d0b;
CARM95_HOOK_FUNCTION(original_ScaleAccUp4, ScaleAccUp4)
void __cdecl ScaleAccUp4() {
    LOG_TRACE("()");


    original_ScaleAccUp4();
}

static void(__cdecl*original_ScaleAccDown2)() = (void(__cdecl*)())0x00444d23;
CARM95_HOOK_FUNCTION(original_ScaleAccDown2, ScaleAccDown2)
void __cdecl ScaleAccDown2() {
    LOG_TRACE("()");


    original_ScaleAccDown2();
}

static void(__cdecl*original_ScaleAccDown3)() = (void(__cdecl*)())0x00444d3b;
CARM95_HOOK_FUNCTION(original_ScaleAccDown3, ScaleAccDown3)
void __cdecl ScaleAccDown3() {
    LOG_TRACE("()");


    original_ScaleAccDown3();
}

static void(__cdecl*original_ScaleAccDown4)() = (void(__cdecl*)())0x00444d53;
CARM95_HOOK_FUNCTION(original_ScaleAccDown4, ScaleAccDown4)
void __cdecl ScaleAccDown4() {
    LOG_TRACE("()");


    original_ScaleAccDown4();
}

static void(__cdecl*original_MoveXAccL)() = (void(__cdecl*)())0x00444d6b;
CARM95_HOOK_FUNCTION(original_MoveXAccL, MoveXAccL)
void __cdecl MoveXAccL() {
    LOG_TRACE("()");


    original_MoveXAccL();
}

static void(__cdecl*original_MoveXAccL2)() = (void(__cdecl*)())0x00444df2;
CARM95_HOOK_FUNCTION(original_MoveXAccL2, MoveXAccL2)
void __cdecl MoveXAccL2() {
    LOG_TRACE("()");


    original_MoveXAccL2();
}

static void(__cdecl*original_MoveXAccL3)() = (void(__cdecl*)())0x00444e0e;
CARM95_HOOK_FUNCTION(original_MoveXAccL3, MoveXAccL3)
void __cdecl MoveXAccL3() {
    LOG_TRACE("()");


    original_MoveXAccL3();
}

static void(__cdecl*original_MoveXAccL4)() = (void(__cdecl*)())0x00444e2a;
CARM95_HOOK_FUNCTION(original_MoveXAccL4, MoveXAccL4)
void __cdecl MoveXAccL4() {
    LOG_TRACE("()");


    original_MoveXAccL4();
}

static void(__cdecl*original_MoveXAccR)() = (void(__cdecl*)())0x00444e46;
CARM95_HOOK_FUNCTION(original_MoveXAccR, MoveXAccR)
void __cdecl MoveXAccR() {
    LOG_TRACE("()");


    original_MoveXAccR();
}

static void(__cdecl*original_MoveXAccR2)() = (void(__cdecl*)())0x00444e62;
CARM95_HOOK_FUNCTION(original_MoveXAccR2, MoveXAccR2)
void __cdecl MoveXAccR2() {
    LOG_TRACE("()");


    original_MoveXAccR2();
}

static void(__cdecl*original_MoveXAccR3)() = (void(__cdecl*)())0x00444e7e;
CARM95_HOOK_FUNCTION(original_MoveXAccR3, MoveXAccR3)
void __cdecl MoveXAccR3() {
    LOG_TRACE("()");


    original_MoveXAccR3();
}

static void(__cdecl*original_MoveXAccR4)() = (void(__cdecl*)())0x00444e9a;
CARM95_HOOK_FUNCTION(original_MoveXAccR4, MoveXAccR4)
void __cdecl MoveXAccR4() {
    LOG_TRACE("()");


    original_MoveXAccR4();
}

static void(__cdecl*original_MoveYAccL)() = (void(__cdecl*)())0x00444eb6;
CARM95_HOOK_FUNCTION(original_MoveYAccL, MoveYAccL)
void __cdecl MoveYAccL() {
    LOG_TRACE("()");


    original_MoveYAccL();
}

static void(__cdecl*original_MoveYAccL2)() = (void(__cdecl*)())0x00444ed2;
CARM95_HOOK_FUNCTION(original_MoveYAccL2, MoveYAccL2)
void __cdecl MoveYAccL2() {
    LOG_TRACE("()");


    original_MoveYAccL2();
}

static void(__cdecl*original_MoveYAccL3)() = (void(__cdecl*)())0x00444eee;
CARM95_HOOK_FUNCTION(original_MoveYAccL3, MoveYAccL3)
void __cdecl MoveYAccL3() {
    LOG_TRACE("()");


    original_MoveYAccL3();
}

static void(__cdecl*original_MoveYAccL4)() = (void(__cdecl*)())0x00444f0a;
CARM95_HOOK_FUNCTION(original_MoveYAccL4, MoveYAccL4)
void __cdecl MoveYAccL4() {
    LOG_TRACE("()");


    original_MoveYAccL4();
}

static void(__cdecl*original_MoveYAccR)() = (void(__cdecl*)())0x00444f26;
CARM95_HOOK_FUNCTION(original_MoveYAccR, MoveYAccR)
void __cdecl MoveYAccR() {
    LOG_TRACE("()");


    original_MoveYAccR();
}

static void(__cdecl*original_MoveYAccR2)() = (void(__cdecl*)())0x00444f42;
CARM95_HOOK_FUNCTION(original_MoveYAccR2, MoveYAccR2)
void __cdecl MoveYAccR2() {
    LOG_TRACE("()");


    original_MoveYAccR2();
}

static void(__cdecl*original_MoveYAccR3)() = (void(__cdecl*)())0x00444f5e;
CARM95_HOOK_FUNCTION(original_MoveYAccR3, MoveYAccR3)
void __cdecl MoveYAccR3() {
    LOG_TRACE("()");


    original_MoveYAccR3();
}

static void(__cdecl*original_MoveYAccR4)() = (void(__cdecl*)())0x00444f7a;
CARM95_HOOK_FUNCTION(original_MoveYAccR4, MoveYAccR4)
void __cdecl MoveYAccR4() {
    LOG_TRACE("()");


    original_MoveYAccR4();
}

static void(__cdecl*original_MoveZAccL)() = (void(__cdecl*)())0x00444f96;
CARM95_HOOK_FUNCTION(original_MoveZAccL, MoveZAccL)
void __cdecl MoveZAccL() {
    LOG_TRACE("()");


    original_MoveZAccL();
}

static void(__cdecl*original_MoveZAccL2)() = (void(__cdecl*)())0x00444fb2;
CARM95_HOOK_FUNCTION(original_MoveZAccL2, MoveZAccL2)
void __cdecl MoveZAccL2() {
    LOG_TRACE("()");


    original_MoveZAccL2();
}

static void(__cdecl*original_MoveZAccL3)() = (void(__cdecl*)())0x00444fce;
CARM95_HOOK_FUNCTION(original_MoveZAccL3, MoveZAccL3)
void __cdecl MoveZAccL3() {
    LOG_TRACE("()");


    original_MoveZAccL3();
}

static void(__cdecl*original_MoveZAccL4)() = (void(__cdecl*)())0x00444fea;
CARM95_HOOK_FUNCTION(original_MoveZAccL4, MoveZAccL4)
void __cdecl MoveZAccL4() {
    LOG_TRACE("()");


    original_MoveZAccL4();
}

static void(__cdecl*original_MoveZAccR)() = (void(__cdecl*)())0x00445006;
CARM95_HOOK_FUNCTION(original_MoveZAccR, MoveZAccR)
void __cdecl MoveZAccR() {
    LOG_TRACE("()");


    original_MoveZAccR();
}

static void(__cdecl*original_MoveZAccR2)() = (void(__cdecl*)())0x00445022;
CARM95_HOOK_FUNCTION(original_MoveZAccR2, MoveZAccR2)
void __cdecl MoveZAccR2() {
    LOG_TRACE("()");


    original_MoveZAccR2();
}

static void(__cdecl*original_MoveZAccR3)() = (void(__cdecl*)())0x0044503e;
CARM95_HOOK_FUNCTION(original_MoveZAccR3, MoveZAccR3)
void __cdecl MoveZAccR3() {
    LOG_TRACE("()");


    original_MoveZAccR3();
}

static void(__cdecl*original_MoveZAccR4)() = (void(__cdecl*)())0x0044505a;
CARM95_HOOK_FUNCTION(original_MoveZAccR4, MoveZAccR4)
void __cdecl MoveZAccR4() {
    LOG_TRACE("()");


    original_MoveZAccR4();
}

static br_material *(__cdecl*original_GetInternalMat)() = (br_material *(__cdecl*)())0x00445076;
CARM95_HOOK_FUNCTION(original_GetInternalMat, GetInternalMat)
br_material* __cdecl GetInternalMat() {
    LOG_TRACE("()");


    return original_GetInternalMat();
}

static br_material *(__cdecl*original_GetExternalMat)() = (br_material *(__cdecl*)())0x00445093;
CARM95_HOOK_FUNCTION(original_GetExternalMat, GetExternalMat)
br_material* __cdecl GetExternalMat() {
    LOG_TRACE("()");


    return original_GetExternalMat();
}

static void(__cdecl*original_BuildSpecVolModel)(tSpecial_volume *, int, br_material *, br_material *) = (void(__cdecl*)(tSpecial_volume *, int, br_material *, br_material *))0x004452b1;
CARM95_HOOK_FUNCTION(original_BuildSpecVolModel, BuildSpecVolModel)
void __cdecl BuildSpecVolModel(tSpecial_volume *pSpec, int pIndex, br_material *pInt_mat, br_material *pExt_mat) {
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

static void(__cdecl*original_DropSpecVol)(int) = (void(__cdecl*)(int))0x004450d0;
CARM95_HOOK_FUNCTION(original_DropSpecVol, DropSpecVol)
void __cdecl DropSpecVol(int pIndex) {
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

static void(__cdecl*original_DropSpecVol0)() = (void(__cdecl*)())0x004450b0;
CARM95_HOOK_FUNCTION(original_DropSpecVol0, DropSpecVol0)
void __cdecl DropSpecVol0() {
    LOG_TRACE("()");


    original_DropSpecVol0();
}

static void(__cdecl*original_DropSpecVol1)() = (void(__cdecl*)())0x004450bb;
CARM95_HOOK_FUNCTION(original_DropSpecVol1, DropSpecVol1)
void __cdecl DropSpecVol1() {
    LOG_TRACE("()");


    original_DropSpecVol1();
}

static void(__cdecl*original_DropSpecVol2)() = (void(__cdecl*)())0x00445b86;
CARM95_HOOK_FUNCTION(original_DropSpecVol2, DropSpecVol2)
void __cdecl DropSpecVol2() {
    LOG_TRACE("()");


    original_DropSpecVol2();
}

static void(__cdecl*original_DropSpecVol3)() = (void(__cdecl*)())0x00445b9b;
CARM95_HOOK_FUNCTION(original_DropSpecVol3, DropSpecVol3)
void __cdecl DropSpecVol3() {
    LOG_TRACE("()");


    original_DropSpecVol3();
}

static void(__cdecl*original_DropSpecVol4)() = (void(__cdecl*)())0x00445bb0;
CARM95_HOOK_FUNCTION(original_DropSpecVol4, DropSpecVol4)
void __cdecl DropSpecVol4() {
    LOG_TRACE("()");


    original_DropSpecVol4();
}

static void(__cdecl*original_DropSpecVol5)() = (void(__cdecl*)())0x00445bc5;
CARM95_HOOK_FUNCTION(original_DropSpecVol5, DropSpecVol5)
void __cdecl DropSpecVol5() {
    LOG_TRACE("()");


    original_DropSpecVol5();
}

static void(__cdecl*original_DropSpecVol6)() = (void(__cdecl*)())0x00445bda;
CARM95_HOOK_FUNCTION(original_DropSpecVol6, DropSpecVol6)
void __cdecl DropSpecVol6() {
    LOG_TRACE("()");


    original_DropSpecVol6();
}

static void(__cdecl*original_DropSpecVol7)() = (void(__cdecl*)())0x00445bef;
CARM95_HOOK_FUNCTION(original_DropSpecVol7, DropSpecVol7)
void __cdecl DropSpecVol7() {
    LOG_TRACE("()");


    original_DropSpecVol7();
}

static void(__cdecl*original_DropSpecVol8)() = (void(__cdecl*)())0x00445c04;
CARM95_HOOK_FUNCTION(original_DropSpecVol8, DropSpecVol8)
void __cdecl DropSpecVol8() {
    LOG_TRACE("()");


    original_DropSpecVol8();
}

static void(__cdecl*original_DropSpecVol9)() = (void(__cdecl*)())0x00445c19;
CARM95_HOOK_FUNCTION(original_DropSpecVol9, DropSpecVol9)
void __cdecl DropSpecVol9() {
    LOG_TRACE("()");


    original_DropSpecVol9();
}

static void(__cdecl*original_IdentifySpecVol)() = (void(__cdecl*)())0x00445c2e;
CARM95_HOOK_FUNCTION(original_IdentifySpecVol, IdentifySpecVol)
void __cdecl IdentifySpecVol() {
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

static void(__cdecl*original_DelSpecVolumeGraph)(int) = (void(__cdecl*)(int))0x00445ed2;
CARM95_HOOK_FUNCTION(original_DelSpecVolumeGraph, DelSpecVolumeGraph)
void __cdecl DelSpecVolumeGraph(int pIndex) {
    br_actor *actor;
    br_model *model;
    LOG_TRACE("(%d)", pIndex);

    (void)pIndex;
    (void)actor;
    (void)model;

    original_DelSpecVolumeGraph(pIndex);
}

static void(__cdecl*original_DeleteSpecVol)() = (void(__cdecl*)())0x00445dc5;
CARM95_HOOK_FUNCTION(original_DeleteSpecVol, DeleteSpecVol)
void __cdecl DeleteSpecVol() {
    int index;
    LOG_TRACE("()");

    (void)index;

    original_DeleteSpecVol();
}

static void(__cdecl*original_RotateSpecVolL)() = (void(__cdecl*)())0x00446022;
CARM95_HOOK_FUNCTION(original_RotateSpecVolL, RotateSpecVolL)
void __cdecl RotateSpecVolL() {
    LOG_TRACE("()");


    original_RotateSpecVolL();
}

static void(__cdecl*original_RotateSpecVolL2)() = (void(__cdecl*)())0x00446032;
CARM95_HOOK_FUNCTION(original_RotateSpecVolL2, RotateSpecVolL2)
void __cdecl RotateSpecVolL2() {
    LOG_TRACE("()");


    original_RotateSpecVolL2();
}

static void(__cdecl*original_RotateSpecVolL3)() = (void(__cdecl*)())0x00446042;
CARM95_HOOK_FUNCTION(original_RotateSpecVolL3, RotateSpecVolL3)
void __cdecl RotateSpecVolL3() {
    LOG_TRACE("()");


    original_RotateSpecVolL3();
}

static void(__cdecl*original_RotateSpecVolL4)() = (void(__cdecl*)())0x00446052;
CARM95_HOOK_FUNCTION(original_RotateSpecVolL4, RotateSpecVolL4)
void __cdecl RotateSpecVolL4() {
    LOG_TRACE("()");


    original_RotateSpecVolL4();
}

static void(__cdecl*original_RotateSpecVolR)() = (void(__cdecl*)())0x00446062;
CARM95_HOOK_FUNCTION(original_RotateSpecVolR, RotateSpecVolR)
void __cdecl RotateSpecVolR() {
    LOG_TRACE("()");


    original_RotateSpecVolR();
}

static void(__cdecl*original_RotateSpecVolR2)() = (void(__cdecl*)())0x00446072;
CARM95_HOOK_FUNCTION(original_RotateSpecVolR2, RotateSpecVolR2)
void __cdecl RotateSpecVolR2() {
    LOG_TRACE("()");


    original_RotateSpecVolR2();
}

static void(__cdecl*original_RotateSpecVolR3)() = (void(__cdecl*)())0x00446082;
CARM95_HOOK_FUNCTION(original_RotateSpecVolR3, RotateSpecVolR3)
void __cdecl RotateSpecVolR3() {
    LOG_TRACE("()");


    original_RotateSpecVolR3();
}

static void(__cdecl*original_RotateSpecVolR4)() = (void(__cdecl*)())0x00446092;
CARM95_HOOK_FUNCTION(original_RotateSpecVolR4, RotateSpecVolR4)
void __cdecl RotateSpecVolR4() {
    LOG_TRACE("()");


    original_RotateSpecVolR4();
}

static void(__cdecl*original_CycleSpecVolRotate)() = (void(__cdecl*)())0x004460a2;
CARM95_HOOK_FUNCTION(original_CycleSpecVolRotate, CycleSpecVolRotate)
void __cdecl CycleSpecVolRotate() {
    LOG_TRACE("()");


    original_CycleSpecVolRotate();
}

static void(__cdecl*original_CycleSpecVolScale)() = (void(__cdecl*)())0x004460b2;
CARM95_HOOK_FUNCTION(original_CycleSpecVolScale, CycleSpecVolScale)
void __cdecl CycleSpecVolScale() {
    LOG_TRACE("()");


    original_CycleSpecVolScale();
}

static void(__cdecl*original_ScaleSpecVolUp2)() = (void(__cdecl*)())0x004460c2;
CARM95_HOOK_FUNCTION(original_ScaleSpecVolUp2, ScaleSpecVolUp2)
void __cdecl ScaleSpecVolUp2() {
    LOG_TRACE("()");


    original_ScaleSpecVolUp2();
}

static void(__cdecl*original_ScaleSpecVolUp3)() = (void(__cdecl*)())0x004460d2;
CARM95_HOOK_FUNCTION(original_ScaleSpecVolUp3, ScaleSpecVolUp3)
void __cdecl ScaleSpecVolUp3() {
    LOG_TRACE("()");


    original_ScaleSpecVolUp3();
}

static void(__cdecl*original_ScaleSpecVolUp4)() = (void(__cdecl*)())0x004460e2;
CARM95_HOOK_FUNCTION(original_ScaleSpecVolUp4, ScaleSpecVolUp4)
void __cdecl ScaleSpecVolUp4() {
    LOG_TRACE("()");


    original_ScaleSpecVolUp4();
}

static void(__cdecl*original_ScaleSpecVolDown2)() = (void(__cdecl*)())0x004460f2;
CARM95_HOOK_FUNCTION(original_ScaleSpecVolDown2, ScaleSpecVolDown2)
void __cdecl ScaleSpecVolDown2() {
    LOG_TRACE("()");


    original_ScaleSpecVolDown2();
}

static void(__cdecl*original_ScaleSpecVolDown3)() = (void(__cdecl*)())0x00446102;
CARM95_HOOK_FUNCTION(original_ScaleSpecVolDown3, ScaleSpecVolDown3)
void __cdecl ScaleSpecVolDown3() {
    LOG_TRACE("()");


    original_ScaleSpecVolDown3();
}

static void(__cdecl*original_ScaleSpecVolDown4)() = (void(__cdecl*)())0x00446112;
CARM95_HOOK_FUNCTION(original_ScaleSpecVolDown4, ScaleSpecVolDown4)
void __cdecl ScaleSpecVolDown4() {
    LOG_TRACE("()");


    original_ScaleSpecVolDown4();
}

static void(__cdecl*original_MoveXSpecVolL)() = (void(__cdecl*)())0x00446122;
CARM95_HOOK_FUNCTION(original_MoveXSpecVolL, MoveXSpecVolL)
void __cdecl MoveXSpecVolL() {
    LOG_TRACE("()");


    original_MoveXSpecVolL();
}

static void(__cdecl*original_MoveXSpecVolL2)() = (void(__cdecl*)())0x00446132;
CARM95_HOOK_FUNCTION(original_MoveXSpecVolL2, MoveXSpecVolL2)
void __cdecl MoveXSpecVolL2() {
    LOG_TRACE("()");


    original_MoveXSpecVolL2();
}

static void(__cdecl*original_MoveXSpecVolL3)() = (void(__cdecl*)())0x00446142;
CARM95_HOOK_FUNCTION(original_MoveXSpecVolL3, MoveXSpecVolL3)
void __cdecl MoveXSpecVolL3() {
    LOG_TRACE("()");


    original_MoveXSpecVolL3();
}

static void(__cdecl*original_MoveXSpecVolL4)() = (void(__cdecl*)())0x00446152;
CARM95_HOOK_FUNCTION(original_MoveXSpecVolL4, MoveXSpecVolL4)
void __cdecl MoveXSpecVolL4() {
    LOG_TRACE("()");


    original_MoveXSpecVolL4();
}

static void(__cdecl*original_MoveXSpecVolR)() = (void(__cdecl*)())0x00446162;
CARM95_HOOK_FUNCTION(original_MoveXSpecVolR, MoveXSpecVolR)
void __cdecl MoveXSpecVolR() {
    LOG_TRACE("()");


    original_MoveXSpecVolR();
}

static void(__cdecl*original_MoveXSpecVolR2)() = (void(__cdecl*)())0x00446172;
CARM95_HOOK_FUNCTION(original_MoveXSpecVolR2, MoveXSpecVolR2)
void __cdecl MoveXSpecVolR2() {
    LOG_TRACE("()");


    original_MoveXSpecVolR2();
}

static void(__cdecl*original_MoveXSpecVolR3)() = (void(__cdecl*)())0x00446182;
CARM95_HOOK_FUNCTION(original_MoveXSpecVolR3, MoveXSpecVolR3)
void __cdecl MoveXSpecVolR3() {
    LOG_TRACE("()");


    original_MoveXSpecVolR3();
}

static void(__cdecl*original_MoveXSpecVolR4)() = (void(__cdecl*)())0x00446192;
CARM95_HOOK_FUNCTION(original_MoveXSpecVolR4, MoveXSpecVolR4)
void __cdecl MoveXSpecVolR4() {
    LOG_TRACE("()");


    original_MoveXSpecVolR4();
}

static void(__cdecl*original_MoveYSpecVolL)() = (void(__cdecl*)())0x004461a2;
CARM95_HOOK_FUNCTION(original_MoveYSpecVolL, MoveYSpecVolL)
void __cdecl MoveYSpecVolL() {
    LOG_TRACE("()");


    original_MoveYSpecVolL();
}

static void(__cdecl*original_MoveYSpecVolL2)() = (void(__cdecl*)())0x004461b2;
CARM95_HOOK_FUNCTION(original_MoveYSpecVolL2, MoveYSpecVolL2)
void __cdecl MoveYSpecVolL2() {
    LOG_TRACE("()");


    original_MoveYSpecVolL2();
}

static void(__cdecl*original_MoveYSpecVolL3)() = (void(__cdecl*)())0x004461c2;
CARM95_HOOK_FUNCTION(original_MoveYSpecVolL3, MoveYSpecVolL3)
void __cdecl MoveYSpecVolL3() {
    LOG_TRACE("()");


    original_MoveYSpecVolL3();
}

static void(__cdecl*original_MoveYSpecVolL4)() = (void(__cdecl*)())0x004461d2;
CARM95_HOOK_FUNCTION(original_MoveYSpecVolL4, MoveYSpecVolL4)
void __cdecl MoveYSpecVolL4() {
    LOG_TRACE("()");


    original_MoveYSpecVolL4();
}

static void(__cdecl*original_MoveYSpecVolR)() = (void(__cdecl*)())0x004461e2;
CARM95_HOOK_FUNCTION(original_MoveYSpecVolR, MoveYSpecVolR)
void __cdecl MoveYSpecVolR() {
    LOG_TRACE("()");


    original_MoveYSpecVolR();
}

static void(__cdecl*original_MoveYSpecVolR2)() = (void(__cdecl*)())0x004461f2;
CARM95_HOOK_FUNCTION(original_MoveYSpecVolR2, MoveYSpecVolR2)
void __cdecl MoveYSpecVolR2() {
    LOG_TRACE("()");


    original_MoveYSpecVolR2();
}

static void(__cdecl*original_MoveYSpecVolR3)() = (void(__cdecl*)())0x00446202;
CARM95_HOOK_FUNCTION(original_MoveYSpecVolR3, MoveYSpecVolR3)
void __cdecl MoveYSpecVolR3() {
    LOG_TRACE("()");


    original_MoveYSpecVolR3();
}

static void(__cdecl*original_MoveYSpecVolR4)() = (void(__cdecl*)())0x00446212;
CARM95_HOOK_FUNCTION(original_MoveYSpecVolR4, MoveYSpecVolR4)
void __cdecl MoveYSpecVolR4() {
    LOG_TRACE("()");


    original_MoveYSpecVolR4();
}

static void(__cdecl*original_MoveZSpecVolL)() = (void(__cdecl*)())0x00446222;
CARM95_HOOK_FUNCTION(original_MoveZSpecVolL, MoveZSpecVolL)
void __cdecl MoveZSpecVolL() {
    LOG_TRACE("()");


    original_MoveZSpecVolL();
}

static void(__cdecl*original_MoveZSpecVolL2)() = (void(__cdecl*)())0x00446232;
CARM95_HOOK_FUNCTION(original_MoveZSpecVolL2, MoveZSpecVolL2)
void __cdecl MoveZSpecVolL2() {
    LOG_TRACE("()");


    original_MoveZSpecVolL2();
}

static void(__cdecl*original_MoveZSpecVolL3)() = (void(__cdecl*)())0x00446242;
CARM95_HOOK_FUNCTION(original_MoveZSpecVolL3, MoveZSpecVolL3)
void __cdecl MoveZSpecVolL3() {
    LOG_TRACE("()");


    original_MoveZSpecVolL3();
}

static void(__cdecl*original_MoveZSpecVolL4)() = (void(__cdecl*)())0x00446252;
CARM95_HOOK_FUNCTION(original_MoveZSpecVolL4, MoveZSpecVolL4)
void __cdecl MoveZSpecVolL4() {
    LOG_TRACE("()");


    original_MoveZSpecVolL4();
}

static void(__cdecl*original_MoveZSpecVolR)() = (void(__cdecl*)())0x00446262;
CARM95_HOOK_FUNCTION(original_MoveZSpecVolR, MoveZSpecVolR)
void __cdecl MoveZSpecVolR() {
    LOG_TRACE("()");


    original_MoveZSpecVolR();
}

static void(__cdecl*original_MoveZSpecVolR2)() = (void(__cdecl*)())0x00446272;
CARM95_HOOK_FUNCTION(original_MoveZSpecVolR2, MoveZSpecVolR2)
void __cdecl MoveZSpecVolR2() {
    LOG_TRACE("()");


    original_MoveZSpecVolR2();
}

static void(__cdecl*original_MoveZSpecVolR3)() = (void(__cdecl*)())0x00446282;
CARM95_HOOK_FUNCTION(original_MoveZSpecVolR3, MoveZSpecVolR3)
void __cdecl MoveZSpecVolR3() {
    LOG_TRACE("()");


    original_MoveZSpecVolR3();
}

static void(__cdecl*original_MoveZSpecVolR4)() = (void(__cdecl*)())0x00446292;
CARM95_HOOK_FUNCTION(original_MoveZSpecVolR4, MoveZSpecVolR4)
void __cdecl MoveZSpecVolR4() {
    LOG_TRACE("()");


    original_MoveZSpecVolR4();
}

static void(__cdecl*original_SnapSpecVolToVertical)() = (void(__cdecl*)())0x004462a2;
CARM95_HOOK_FUNCTION(original_SnapSpecVolToVertical, SnapSpecVolToVertical)
void __cdecl SnapSpecVolToVertical() {
    LOG_TRACE("()");


    original_SnapSpecVolToVertical();
}

static void(__cdecl*original_ShowSpecialVolumes)() = (void(__cdecl*)())0x004462b2;
CARM95_HOOK_FUNCTION(original_ShowSpecialVolumes, ShowSpecialVolumes)
void __cdecl ShowSpecialVolumes() {
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

static void(__cdecl*original_HideSpecialVolumes)() = (void(__cdecl*)())0x00446351;
CARM95_HOOK_FUNCTION(original_HideSpecialVolumes, HideSpecialVolumes)
void __cdecl HideSpecialVolumes() {
    int i;
    tSpecial_volume *v;
    LOG_TRACE("()");

    (void)i;
    (void)v;

    original_HideSpecialVolumes();
}

