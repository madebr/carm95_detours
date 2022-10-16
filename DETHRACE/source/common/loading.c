#include "loading.h"

#include "harness/trace.h"

#include "carm95_hooks.h"

#include "carm95_webserver.h"

#include <assert.h>
tHeadup_info(* hookvar_gHeadup_image_info )[31] = (void*)0x0050a3f0;
#if 0
char *(* hookvar_gYour_car_names )[2][6];
#endif
#if 0
char *(* hookvar_gDrivable_car_names )[6];
#endif
char *(* hookvar_gDamage_names )[12] = (void*)0x0050a530;
char *(* hookvar_gWheel_actor_names )[6] = (void*)0x0050a560;
#if 0
char *(* hookvar_gRaces_file_names )[9];
#endif
char *(* hookvar_gNet_avail_names )[4] = (void*)0x0050a5a0;
char *(* hookvar_gFloorpan_names )[5] = (void*)0x0050a5b0;
int * hookvar_gAllow_open_to_fail  = (void*)0x0050a5c4;
int * hookvar_gDecode_thing  = (void*)0x0050a5c8;
char(* hookvar_gDecode_string )[14] = (void*)0x0050a5d0;
int(* hookvar_gFunk_groove_flags )[30] = (void*)0x00531f00;
char(* hookvar_gDef_def_water_screen_name )[32] = (void*)0x00531f80;
br_material ** hookvar_gDestn_screen_mat  = (void*)0x00531dfc;
br_material ** hookvar_gSource_screen_mat  = (void*)0x00531f78;
int * hookvar_gCurrent_race_file_index  = (void*)0x00531f7c;
int * hookvar_gGroove_funk_offset  = (void*)0x00531df8;
int * hookvar_gDemo_armour  = (void*)0x00551da8;
int * hookvar_gDemo_rank  = (void*)0x00551db0;
#if 0
int(* hookvar_gDemo_opponents )[5];
#endif
int * hookvar_gDemo_power  = (void*)0x00551da4;
int * hookvar_gDemo_offensive  = (void*)0x00551dac;

function_hook_state_t function_hook_state_ReadU32 = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(ReadU32, function_hook_state_ReadU32)
static tU32(__cdecl*original_ReadU32)(FILE *) = (tU32(__cdecl*)(FILE *))0x0041c2b0;
CARM95_HOOK_FUNCTION(original_ReadU32, ReadU32)
tU32 __cdecl ReadU32(FILE *pF) {
    tU32 raw_long;
    LOG_TRACE("(%p)", pF);

    (void)pF;
    (void)raw_long;

    if (function_hook_state_ReadU32 == HOOK_ENABLED) {
        assert(0 && "ReadU32 not implemented.");
        abort();
    } else {
        return original_ReadU32(pF);
    }
}

function_hook_state_t function_hook_state_ReadU16 = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(ReadU16, function_hook_state_ReadU16)
static tU16(__cdecl*original_ReadU16)(FILE *) = (tU16(__cdecl*)(FILE *))0x0041c2da;
CARM95_HOOK_FUNCTION(original_ReadU16, ReadU16)
tU16 __cdecl ReadU16(FILE *pF) {
    tU16 raw_short;
    LOG_TRACE("(%p)", pF);

    (void)pF;
    (void)raw_short;

    if (function_hook_state_ReadU16 == HOOK_ENABLED) {
        assert(0 && "ReadU16 not implemented.");
        abort();
    } else {
        return original_ReadU16(pF);
    }
}

function_hook_state_t function_hook_state_ReadU8 = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(ReadU8, function_hook_state_ReadU8)
static tU8(__cdecl*original_ReadU8)(FILE *) = (tU8(__cdecl*)(FILE *))0x0041c305;
CARM95_HOOK_FUNCTION(original_ReadU8, ReadU8)
tU8 __cdecl ReadU8(FILE *pF) {
    tU8 raw_byte;
    LOG_TRACE("(%p)", pF);

    (void)pF;
    (void)raw_byte;

    if (function_hook_state_ReadU8 == HOOK_ENABLED) {
        assert(0 && "ReadU8 not implemented.");
        abort();
    } else {
        return original_ReadU8(pF);
    }
}

function_hook_state_t function_hook_state_ReadS32 = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(ReadS32, function_hook_state_ReadS32)
static tS32(__cdecl*original_ReadS32)(FILE *) = (tS32(__cdecl*)(FILE *))0x0041c32f;
CARM95_HOOK_FUNCTION(original_ReadS32, ReadS32)
tS32 __cdecl ReadS32(FILE *pF) {
    tS32 raw_long;
    LOG_TRACE("(%p)", pF);

    (void)pF;
    (void)raw_long;

    if (function_hook_state_ReadS32 == HOOK_ENABLED) {
        assert(0 && "ReadS32 not implemented.");
        abort();
    } else {
        return original_ReadS32(pF);
    }
}

function_hook_state_t function_hook_state_ReadS16 = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(ReadS16, function_hook_state_ReadS16)
static tS16(__cdecl*original_ReadS16)(FILE *) = (tS16(__cdecl*)(FILE *))0x0041c359;
CARM95_HOOK_FUNCTION(original_ReadS16, ReadS16)
tS16 __cdecl ReadS16(FILE *pF) {
    tS16 raw_short;
    LOG_TRACE("(%p)", pF);

    (void)pF;
    (void)raw_short;

    if (function_hook_state_ReadS16 == HOOK_ENABLED) {
        assert(0 && "ReadS16 not implemented.");
        abort();
    } else {
        return original_ReadS16(pF);
    }
}

function_hook_state_t function_hook_state_ReadS8 = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(ReadS8, function_hook_state_ReadS8)
static tS8(__cdecl*original_ReadS8)(FILE *) = (tS8(__cdecl*)(FILE *))0x0041c384;
CARM95_HOOK_FUNCTION(original_ReadS8, ReadS8)
tS8 __cdecl ReadS8(FILE *pF) {
    tS8 raw_byte;
    LOG_TRACE("(%p)", pF);

    (void)pF;
    (void)raw_byte;

    if (function_hook_state_ReadS8 == HOOK_ENABLED) {
        assert(0 && "ReadS8 not implemented.");
        abort();
    } else {
        return original_ReadS8(pF);
    }
}

function_hook_state_t function_hook_state_WriteU32L = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(WriteU32L, function_hook_state_WriteU32L)
static void(__cdecl*original_WriteU32L)(FILE *, tU32) = (void(__cdecl*)(FILE *, tU32))0x0041c3ae;
CARM95_HOOK_FUNCTION(original_WriteU32L, WriteU32L)
void __cdecl WriteU32L(FILE *pF, tU32 pNumber) {
    tU32 raw_long;
    LOG_TRACE("(%p, %u)", pF, pNumber);

    (void)pF;
    (void)pNumber;
    (void)raw_long;

    if (function_hook_state_WriteU32L == HOOK_ENABLED) {
        assert(0 && "WriteU32L not implemented.");
        abort();
    } else {
        original_WriteU32L(pF, pNumber);
    }
}

function_hook_state_t function_hook_state_WriteU16L = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(WriteU16L, function_hook_state_WriteU16L)
static void(__cdecl*original_WriteU16L)(FILE *, tU16) = (void(__cdecl*)(FILE *, tU16))0x0041c3d6;
CARM95_HOOK_FUNCTION(original_WriteU16L, WriteU16L)
void __cdecl WriteU16L(FILE *pF, tU16 pNumber) {
    tU16 raw_short;
    LOG_TRACE("(%p, %u)", pF, pNumber);

    (void)pF;
    (void)pNumber;
    (void)raw_short;

    if (function_hook_state_WriteU16L == HOOK_ENABLED) {
        assert(0 && "WriteU16L not implemented.");
        abort();
    } else {
        original_WriteU16L(pF, pNumber);
    }
}

function_hook_state_t function_hook_state_WriteU8L = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(WriteU8L, function_hook_state_WriteU8L)
static void(__cdecl*original_WriteU8L)(FILE *, tU8) = (void(__cdecl*)(FILE *, tU8))0x0041c400;
CARM95_HOOK_FUNCTION(original_WriteU8L, WriteU8L)
void __cdecl WriteU8L(FILE *pF, tU8 pNumber) {
    tU8 raw_byte;
    LOG_TRACE("(%p, %u)", pF, pNumber);

    (void)pF;
    (void)pNumber;
    (void)raw_byte;

    if (function_hook_state_WriteU8L == HOOK_ENABLED) {
        assert(0 && "WriteU8L not implemented.");
        abort();
    } else {
        original_WriteU8L(pF, pNumber);
    }
}

function_hook_state_t function_hook_state_WriteS32L = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(WriteS32L, function_hook_state_WriteS32L)
static void(__cdecl*original_WriteS32L)(FILE *, tS32) = (void(__cdecl*)(FILE *, tS32))0x0041c428;
CARM95_HOOK_FUNCTION(original_WriteS32L, WriteS32L)
void __cdecl WriteS32L(FILE *pF, tS32 pNumber) {
    tS32 raw_long;
    LOG_TRACE("(%p, %d)", pF, pNumber);

    (void)pF;
    (void)pNumber;
    (void)raw_long;

    if (function_hook_state_WriteS32L == HOOK_ENABLED) {
        assert(0 && "WriteS32L not implemented.");
        abort();
    } else {
        original_WriteS32L(pF, pNumber);
    }
}

function_hook_state_t function_hook_state_WriteS16L = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(WriteS16L, function_hook_state_WriteS16L)
static void(__cdecl*original_WriteS16L)(FILE *, tS16) = (void(__cdecl*)(FILE *, tS16))0x0041c450;
CARM95_HOOK_FUNCTION(original_WriteS16L, WriteS16L)
void __cdecl WriteS16L(FILE *pF, tS16 pNumber) {
    tS16 raw_short;
    LOG_TRACE("(%p, %d)", pF, pNumber);

    (void)pF;
    (void)pNumber;
    (void)raw_short;

    if (function_hook_state_WriteS16L == HOOK_ENABLED) {
        assert(0 && "WriteS16L not implemented.");
        abort();
    } else {
        original_WriteS16L(pF, pNumber);
    }
}

function_hook_state_t function_hook_state_WriteS8L = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(WriteS8L, function_hook_state_WriteS8L)
static void(__cdecl*original_WriteS8L)(FILE *, tS8) = (void(__cdecl*)(FILE *, tS8))0x0041c47a;
CARM95_HOOK_FUNCTION(original_WriteS8L, WriteS8L)
void __cdecl WriteS8L(FILE *pF, tS8 pNumber) {
    tS8 raw_byte;
    LOG_TRACE("(%p, %d)", pF, pNumber);

    (void)pF;
    (void)pNumber;
    (void)raw_byte;

    if (function_hook_state_WriteS8L == HOOK_ENABLED) {
        assert(0 && "WriteS8L not implemented.");
        abort();
    } else {
        original_WriteS8L(pF, pNumber);
    }
}

function_hook_state_t function_hook_state_SkipBytes = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(SkipBytes, function_hook_state_SkipBytes)
static void(__cdecl*original_SkipBytes)(FILE *, int) = (void(__cdecl*)(FILE *, int))0x0041c4a2;
CARM95_HOOK_FUNCTION(original_SkipBytes, SkipBytes)
void __cdecl SkipBytes(FILE *pF, int pBytes_to_skip) {
    LOG_TRACE("(%p, %d)", pF, pBytes_to_skip);

    (void)pF;
    (void)pBytes_to_skip;

    if (function_hook_state_SkipBytes == HOOK_ENABLED) {
        assert(0 && "SkipBytes not implemented.");
        abort();
    } else {
        original_SkipBytes(pF, pBytes_to_skip);
    }
}

function_hook_state_t function_hook_state_MemReadU32 = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(MemReadU32, function_hook_state_MemReadU32)
static tU32(__cdecl*original_MemReadU32)(char **) = (tU32(__cdecl*)(char **))0x0041c4bf;
CARM95_HOOK_FUNCTION(original_MemReadU32, MemReadU32)
tU32 __cdecl MemReadU32(char **pPtr) {
    tU32 raw_long;
    LOG_TRACE("(%p)", pPtr);

    (void)pPtr;
    (void)raw_long;

    if (function_hook_state_MemReadU32 == HOOK_ENABLED) {
        assert(0 && "MemReadU32 not implemented.");
        abort();
    } else {
        return original_MemReadU32(pPtr);
    }
}

function_hook_state_t function_hook_state_MemReadU16 = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(MemReadU16, function_hook_state_MemReadU16)
static tU16(__cdecl*original_MemReadU16)(char **) = (tU16(__cdecl*)(char **))0x0041c4e5;
CARM95_HOOK_FUNCTION(original_MemReadU16, MemReadU16)
tU16 __cdecl MemReadU16(char **pPtr) {
    tU16 raw_short;
    LOG_TRACE("(%p)", pPtr);

    (void)pPtr;
    (void)raw_short;

    if (function_hook_state_MemReadU16 == HOOK_ENABLED) {
        assert(0 && "MemReadU16 not implemented.");
        abort();
    } else {
        return original_MemReadU16(pPtr);
    }
}

function_hook_state_t function_hook_state_MemReadU8 = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(MemReadU8, function_hook_state_MemReadU8)
static tU8(__cdecl*original_MemReadU8)(char **) = (tU8(__cdecl*)(char **))0x0041c50e;
CARM95_HOOK_FUNCTION(original_MemReadU8, MemReadU8)
tU8 __cdecl MemReadU8(char **pPtr) {
    LOG_TRACE("(%p)", pPtr);

    (void)pPtr;

    if (function_hook_state_MemReadU8 == HOOK_ENABLED) {
        assert(0 && "MemReadU8 not implemented.");
        abort();
    } else {
        return original_MemReadU8(pPtr);
    }
}

function_hook_state_t function_hook_state_MemReadS32 = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(MemReadS32, function_hook_state_MemReadS32)
static tS32(__cdecl*original_MemReadS32)(char **) = (tS32(__cdecl*)(char **))0x0041c533;
CARM95_HOOK_FUNCTION(original_MemReadS32, MemReadS32)
tS32 __cdecl MemReadS32(char **pPtr) {
    tS32 raw_long;
    LOG_TRACE("(%p)", pPtr);

    (void)pPtr;
    (void)raw_long;

    if (function_hook_state_MemReadS32 == HOOK_ENABLED) {
        assert(0 && "MemReadS32 not implemented.");
        abort();
    } else {
        return original_MemReadS32(pPtr);
    }
}

function_hook_state_t function_hook_state_MemReadS16 = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(MemReadS16, function_hook_state_MemReadS16)
static tS16(__cdecl*original_MemReadS16)(char **) = (tS16(__cdecl*)(char **))0x0041c559;
CARM95_HOOK_FUNCTION(original_MemReadS16, MemReadS16)
tS16 __cdecl MemReadS16(char **pPtr) {
    tS16 raw_short;
    LOG_TRACE("(%p)", pPtr);

    (void)pPtr;
    (void)raw_short;

    if (function_hook_state_MemReadS16 == HOOK_ENABLED) {
        assert(0 && "MemReadS16 not implemented.");
        abort();
    } else {
        return original_MemReadS16(pPtr);
    }
}

function_hook_state_t function_hook_state_MemReadS8 = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(MemReadS8, function_hook_state_MemReadS8)
static tS8(__cdecl*original_MemReadS8)(char **) = (tS8(__cdecl*)(char **))0x0041c582;
CARM95_HOOK_FUNCTION(original_MemReadS8, MemReadS8)
tS8 __cdecl MemReadS8(char **pPtr) {
    tS8 raw_byte;
    LOG_TRACE("(%p)", pPtr);

    (void)pPtr;
    (void)raw_byte;

    if (function_hook_state_MemReadS8 == HOOK_ENABLED) {
        assert(0 && "MemReadS8 not implemented.");
        abort();
    } else {
        return original_MemReadS8(pPtr);
    }
}

function_hook_state_t function_hook_state_MemSkipBytes = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(MemSkipBytes, function_hook_state_MemSkipBytes)
static void(__cdecl*original_MemSkipBytes)(char **, int) = (void(__cdecl*)(char **, int))0x0041c5a7;
CARM95_HOOK_FUNCTION(original_MemSkipBytes, MemSkipBytes)
void __cdecl MemSkipBytes(char **pPtr, int pBytes_to_skip) {
    LOG_TRACE("(%p, %d)", pPtr, pBytes_to_skip);

    (void)pPtr;
    (void)pBytes_to_skip;

    if (function_hook_state_MemSkipBytes == HOOK_ENABLED) {
        assert(0 && "MemSkipBytes not implemented.");
        abort();
    } else {
        original_MemSkipBytes(pPtr, pBytes_to_skip);
    }
}

function_hook_state_t function_hook_state_LoadGeneralParameters = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(LoadGeneralParameters, function_hook_state_LoadGeneralParameters)
static void(__cdecl*original_LoadGeneralParameters)() = (void(__cdecl*)())0x0041c5ba;
CARM95_HOOK_FUNCTION(original_LoadGeneralParameters, LoadGeneralParameters)
void __cdecl LoadGeneralParameters() {
    FILE *f;
    tPath_name the_path;
    int i;
    int temp;
    char s[256];
    char *str;
    LOG_TRACE("()");

    (void)f;
    (void)the_path;
    (void)i;
    (void)temp;
    (void)s;
    (void)str;

    if (function_hook_state_LoadGeneralParameters == HOOK_ENABLED) {
        assert(0 && "LoadGeneralParameters not implemented.");
        abort();
    } else {
        original_LoadGeneralParameters();
    }
}

function_hook_state_t function_hook_state_FinishLoadingGeneral = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(FinishLoadingGeneral, function_hook_state_FinishLoadingGeneral)
static void(__cdecl*original_FinishLoadingGeneral)() = (void(__cdecl*)())0x0041d210;
CARM95_HOOK_FUNCTION(original_FinishLoadingGeneral, FinishLoadingGeneral)
void __cdecl FinishLoadingGeneral() {
    LOG_TRACE("()");


    if (function_hook_state_FinishLoadingGeneral == HOOK_ENABLED) {
        assert(0 && "FinishLoadingGeneral not implemented.");
        abort();
    } else {
        original_FinishLoadingGeneral();
    }
}

function_hook_state_t function_hook_state_LoadPixelmap = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(LoadPixelmap, function_hook_state_LoadPixelmap)
static br_pixelmap *(__cdecl*original_LoadPixelmap)(char *) = (br_pixelmap *(__cdecl*)(char *))0x0041d22d;
CARM95_HOOK_FUNCTION(original_LoadPixelmap, LoadPixelmap)
br_pixelmap* __cdecl LoadPixelmap(char *pName) {
    tPath_name the_path;
    br_pixelmap *pm;
    char *end;
    LOG_TRACE("(\"%s\")", pName);

    (void)pName;
    (void)the_path;
    (void)pm;
    (void)end;

    if (function_hook_state_LoadPixelmap == HOOK_ENABLED) {
        assert(0 && "LoadPixelmap not implemented.");
        abort();
    } else {
        return original_LoadPixelmap(pName);
    }
}

function_hook_state_t function_hook_state_LoadPixelmaps = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(LoadPixelmaps, function_hook_state_LoadPixelmaps)
static br_uint_32(__cdecl*original_LoadPixelmaps)(char *, br_pixelmap **, br_uint_16) = (br_uint_32(__cdecl*)(char *, br_pixelmap **, br_uint_16))0x0041d372;
CARM95_HOOK_FUNCTION(original_LoadPixelmaps, LoadPixelmaps)
br_uint_32 __cdecl LoadPixelmaps(char *pFile_name, br_pixelmap **pPixelmaps, br_uint_16 pNum) {
    tPath_name path;
    int count;
    LOG_TRACE("(\"%s\", %p, %u)", pFile_name, pPixelmaps, pNum);

    (void)pFile_name;
    (void)pPixelmaps;
    (void)pNum;
    (void)path;
    (void)count;

    if (function_hook_state_LoadPixelmaps == HOOK_ENABLED) {
        assert(0 && "LoadPixelmaps not implemented.");
        abort();
    } else {
        return original_LoadPixelmaps(pFile_name, pPixelmaps, pNum);
    }
}

function_hook_state_t function_hook_state_LoadShadeTable = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(LoadShadeTable, function_hook_state_LoadShadeTable)
static br_pixelmap *(__cdecl*original_LoadShadeTable)(char *) = (br_pixelmap *(__cdecl*)(char *))0x0041d470;
CARM95_HOOK_FUNCTION(original_LoadShadeTable, LoadShadeTable)
br_pixelmap* __cdecl LoadShadeTable(char *pName) {
    tPath_name the_path;
    LOG_TRACE("(\"%s\")", pName);

    (void)pName;
    (void)the_path;

    if (function_hook_state_LoadShadeTable == HOOK_ENABLED) {
        assert(0 && "LoadShadeTable not implemented.");
        abort();
    } else {
        return original_LoadShadeTable(pName);
    }
}

function_hook_state_t function_hook_state_LoadMaterial = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(LoadMaterial, function_hook_state_LoadMaterial)
static br_material *(__cdecl*original_LoadMaterial)(char *) = (br_material *(__cdecl*)(char *))0x0041d4c8;
CARM95_HOOK_FUNCTION(original_LoadMaterial, LoadMaterial)
br_material* __cdecl LoadMaterial(char *pName) {
    tPath_name the_path;
    br_material *result;
    LOG_TRACE("(\"%s\")", pName);

    (void)pName;
    (void)the_path;
    (void)result;

    if (function_hook_state_LoadMaterial == HOOK_ENABLED) {
        assert(0 && "LoadMaterial not implemented.");
        abort();
    } else {
        return original_LoadMaterial(pName);
    }
}

function_hook_state_t function_hook_state_LoadModel = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(LoadModel, function_hook_state_LoadModel)
static br_model *(__cdecl*original_LoadModel)(char *) = (br_model *(__cdecl*)(char *))0x0041d525;
CARM95_HOOK_FUNCTION(original_LoadModel, LoadModel)
br_model* __cdecl LoadModel(char *pName) {
    tPath_name the_path;
    br_model *model;
    LOG_TRACE("(\"%s\")", pName);

    (void)pName;
    (void)the_path;
    (void)model;

    if (function_hook_state_LoadModel == HOOK_ENABLED) {
        assert(0 && "LoadModel not implemented.");
        abort();
    } else {
        return original_LoadModel(pName);
    }
}

function_hook_state_t function_hook_state_LoadActor = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(LoadActor, function_hook_state_LoadActor)
static br_actor *(__cdecl*original_LoadActor)(char *) = (br_actor *(__cdecl*)(char *))0x0041d582;
CARM95_HOOK_FUNCTION(original_LoadActor, LoadActor)
br_actor* __cdecl LoadActor(char *pName) {
    tPath_name the_path;
    LOG_TRACE("(\"%s\")", pName);

    (void)pName;
    (void)the_path;

    if (function_hook_state_LoadActor == HOOK_ENABLED) {
        assert(0 && "LoadActor not implemented.");
        abort();
    } else {
        return original_LoadActor(pName);
    }
}

function_hook_state_t function_hook_state_DRLoadPalette = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(DRLoadPalette, function_hook_state_DRLoadPalette)
static void(__cdecl*original_DRLoadPalette)(char *) = (void(__cdecl*)(char *))0x0041d6d5;
CARM95_HOOK_FUNCTION(original_DRLoadPalette, DRLoadPalette)
void __cdecl DRLoadPalette(char *pPath_name) {
    br_pixelmap *palette_array[100];
    int number_of_palettes;
    LOG_TRACE("(\"%s\")", pPath_name);

    (void)pPath_name;
    (void)palette_array;
    (void)number_of_palettes;

    if (function_hook_state_DRLoadPalette == HOOK_ENABLED) {
        assert(0 && "DRLoadPalette not implemented.");
        abort();
    } else {
        original_DRLoadPalette(pPath_name);
    }
}

function_hook_state_t function_hook_state_DRLoadShadeTable = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(DRLoadShadeTable, function_hook_state_DRLoadShadeTable)
static void(__cdecl*original_DRLoadShadeTable)(char *) = (void(__cdecl*)(char *))0x0041d717;
CARM95_HOOK_FUNCTION(original_DRLoadShadeTable, DRLoadShadeTable)
void __cdecl DRLoadShadeTable(char *pPath_name) {
    br_pixelmap *table_array[100];
    int number_of_tables;
    LOG_TRACE("(\"%s\")", pPath_name);

    (void)pPath_name;
    (void)table_array;
    (void)number_of_tables;

    if (function_hook_state_DRLoadShadeTable == HOOK_ENABLED) {
        assert(0 && "DRLoadShadeTable not implemented.");
        abort();
    } else {
        original_DRLoadShadeTable(pPath_name);
    }
}

function_hook_state_t function_hook_state_RezeroPixelmaps = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(RezeroPixelmaps, function_hook_state_RezeroPixelmaps)
static void(__cdecl*original_RezeroPixelmaps)(br_pixelmap **, int) = (void(__cdecl*)(br_pixelmap **, int))0x0041d7b6;
CARM95_HOOK_FUNCTION(original_RezeroPixelmaps, RezeroPixelmaps)
void __cdecl RezeroPixelmaps(br_pixelmap **pPixelmap_array, int pCount) {
    LOG_TRACE("(%p, %d)", pPixelmap_array, pCount);

    (void)pPixelmap_array;
    (void)pCount;

    if (function_hook_state_RezeroPixelmaps == HOOK_ENABLED) {
        assert(0 && "RezeroPixelmaps not implemented.");
        abort();
    } else {
        original_RezeroPixelmaps(pPixelmap_array, pCount);
    }
}

function_hook_state_t function_hook_state_DRLoadPixelmaps = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(DRLoadPixelmaps, function_hook_state_DRLoadPixelmaps)
static void(__cdecl*original_DRLoadPixelmaps)(char *) = (void(__cdecl*)(char *))0x0041d759;
CARM95_HOOK_FUNCTION(original_DRLoadPixelmaps, DRLoadPixelmaps)
void __cdecl DRLoadPixelmaps(char *pPath_name) {
    br_pixelmap *pixelmap_array[100];
    int number_of_pixelmaps;
    LOG_TRACE("(\"%s\")", pPath_name);

    (void)pPath_name;
    (void)pixelmap_array;
    (void)number_of_pixelmaps;

    if (function_hook_state_DRLoadPixelmaps == HOOK_ENABLED) {
        assert(0 && "DRLoadPixelmaps not implemented.");
        abort();
    } else {
        original_DRLoadPixelmaps(pPath_name);
    }
}

function_hook_state_t function_hook_state_DRLoadMaterials = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(DRLoadMaterials, function_hook_state_DRLoadMaterials)
static void(__cdecl*original_DRLoadMaterials)(char *) = (void(__cdecl*)(char *))0x0041d7ed;
CARM95_HOOK_FUNCTION(original_DRLoadMaterials, DRLoadMaterials)
void __cdecl DRLoadMaterials(char *pPath_name) {
    br_material *material_array[100];
    int number_of_materials;
    LOG_TRACE("(\"%s\")", pPath_name);

    (void)pPath_name;
    (void)material_array;
    (void)number_of_materials;

    if (function_hook_state_DRLoadMaterials == HOOK_ENABLED) {
        assert(0 && "DRLoadMaterials not implemented.");
        abort();
    } else {
        original_DRLoadMaterials(pPath_name);
    }
}

function_hook_state_t function_hook_state_DRLoadModels = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(DRLoadModels, function_hook_state_DRLoadModels)
static void(__cdecl*original_DRLoadModels)(char *) = (void(__cdecl*)(char *))0x0041d82e;
CARM95_HOOK_FUNCTION(original_DRLoadModels, DRLoadModels)
void __cdecl DRLoadModels(char *pPath_name) {
    br_model *model_array[100];
    int number_of_models;
    LOG_TRACE("(\"%s\")", pPath_name);

    (void)pPath_name;
    (void)model_array;
    (void)number_of_models;

    if (function_hook_state_DRLoadModels == HOOK_ENABLED) {
        assert(0 && "DRLoadModels not implemented.");
        abort();
    } else {
        original_DRLoadModels(pPath_name);
    }
}

function_hook_state_t function_hook_state_DRLoadActors = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(DRLoadActors, function_hook_state_DRLoadActors)
static void(__cdecl*original_DRLoadActors)(char *) = (void(__cdecl*)(char *))0x0041d86f;
CARM95_HOOK_FUNCTION(original_DRLoadActors, DRLoadActors)
void __cdecl DRLoadActors(char *pPath_name) {
    br_actor *actor_array[100];
    int number_of_actors;
    int i;
    LOG_TRACE("(\"%s\")", pPath_name);

    (void)pPath_name;
    (void)actor_array;
    (void)number_of_actors;
    (void)i;

    if (function_hook_state_DRLoadActors == HOOK_ENABLED) {
        assert(0 && "DRLoadActors not implemented.");
        abort();
    } else {
        original_DRLoadActors(pPath_name);
    }
}

function_hook_state_t function_hook_state_DRLoadLights = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(DRLoadLights, function_hook_state_DRLoadLights)
static void(__cdecl*original_DRLoadLights)(char *) = (void(__cdecl*)(char *))0x0041d8e0;
CARM95_HOOK_FUNCTION(original_DRLoadLights, DRLoadLights)
void __cdecl DRLoadLights(char *pPath_name) {
    br_actor *light_array[100];
    int number_of_lights;
    int i;
    LOG_TRACE("(\"%s\")", pPath_name);

    (void)pPath_name;
    (void)light_array;
    (void)number_of_lights;
    (void)i;

    if (function_hook_state_DRLoadLights == HOOK_ENABLED) {
        assert(0 && "DRLoadLights not implemented.");
        abort();
    } else {
        original_DRLoadLights(pPath_name);
    }
}

function_hook_state_t function_hook_state_LoadInFiles = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(LoadInFiles, function_hook_state_LoadInFiles)
static void(__cdecl*original_LoadInFiles)(char *, char *, void(**)(char *)) = (void(__cdecl*)(char *, char *, void(**)(char *)))0x0041d957;
CARM95_HOOK_FUNCTION(original_LoadInFiles, LoadInFiles)
void __cdecl LoadInFiles(char *pThe_base_path, char *pThe_dir_name, void(**pLoad_routine)(char *)) {
    tPath_name the_path;
    LOG_TRACE("(\"%s\", \"%s\", %p)", pThe_base_path, pThe_dir_name, pLoad_routine);

    (void)pThe_base_path;
    (void)pThe_dir_name;
    (void)pLoad_routine;
    (void)the_path;

    if (function_hook_state_LoadInFiles == HOOK_ENABLED) {
        assert(0 && "LoadInFiles not implemented.");
        abort();
    } else {
        original_LoadInFiles(pThe_base_path, pThe_dir_name, pLoad_routine);
    }
}

function_hook_state_t function_hook_state_LoadInRegisteeDir = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(LoadInRegisteeDir, function_hook_state_LoadInRegisteeDir)
static void(__cdecl*original_LoadInRegisteeDir)(char *) = (void(__cdecl*)(char *))0x0041d5fd;
CARM95_HOOK_FUNCTION(original_LoadInRegisteeDir, LoadInRegisteeDir)
void __cdecl LoadInRegisteeDir(char *pThe_dir_path) {
    tPath_name the_path;
    LOG_TRACE("(\"%s\")", pThe_dir_path);

    (void)pThe_dir_path;
    (void)the_path;

    if (function_hook_state_LoadInRegisteeDir == HOOK_ENABLED) {
        assert(0 && "LoadInRegisteeDir not implemented.");
        abort();
    } else {
        original_LoadInRegisteeDir(pThe_dir_path);
    }
}

function_hook_state_t function_hook_state_LoadInRegistees = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(LoadInRegistees, function_hook_state_LoadInRegistees)
static void(__cdecl*original_LoadInRegistees)() = (void(__cdecl*)())0x0041d5df;
CARM95_HOOK_FUNCTION(original_LoadInRegistees, LoadInRegistees)
void __cdecl LoadInRegistees() {
    tPath_name the_path;
    LOG_TRACE("()");

    (void)the_path;

    if (function_hook_state_LoadInRegistees == HOOK_ENABLED) {
        assert(0 && "LoadInRegistees not implemented.");
        abort();
    } else {
        original_LoadInRegistees();
    }
}

function_hook_state_t function_hook_state_LoadKeyMapping = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(LoadKeyMapping, function_hook_state_LoadKeyMapping)
static void(__cdecl*original_LoadKeyMapping)() = (void(__cdecl*)())0x0041d992;
CARM95_HOOK_FUNCTION(original_LoadKeyMapping, LoadKeyMapping)
void __cdecl LoadKeyMapping() {
    FILE *f;
    tPath_name the_path;
    int i;
    LOG_TRACE("()");

    (void)f;
    (void)the_path;
    (void)i;

    if (function_hook_state_LoadKeyMapping == HOOK_ENABLED) {
        assert(0 && "LoadKeyMapping not implemented.");
        abort();
    } else {
        original_LoadKeyMapping();
    }
}

function_hook_state_t function_hook_state_LoadInterfaceStuff = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(LoadInterfaceStuff, function_hook_state_LoadInterfaceStuff)
static void(__cdecl*original_LoadInterfaceStuff)(int) = (void(__cdecl*)(int))0x0041da5c;
CARM95_HOOK_FUNCTION(original_LoadInterfaceStuff, LoadInterfaceStuff)
void __cdecl LoadInterfaceStuff(int pWithin_race) {
    tPath_name path;
    int i;
    LOG_TRACE("(%d)", pWithin_race);

    (void)pWithin_race;
    (void)path;
    (void)i;

    if (function_hook_state_LoadInterfaceStuff == HOOK_ENABLED) {
        assert(0 && "LoadInterfaceStuff not implemented.");
        abort();
    } else {
        original_LoadInterfaceStuff(pWithin_race);
    }
}

function_hook_state_t function_hook_state_UnlockInterfaceStuff = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(UnlockInterfaceStuff, function_hook_state_UnlockInterfaceStuff)
static void(__cdecl*original_UnlockInterfaceStuff)() = (void(__cdecl*)())0x0041dbbf;
CARM95_HOOK_FUNCTION(original_UnlockInterfaceStuff, UnlockInterfaceStuff)
void __cdecl UnlockInterfaceStuff() {
    int i;
    LOG_TRACE("()");

    (void)i;

    if (function_hook_state_UnlockInterfaceStuff == HOOK_ENABLED) {
        assert(0 && "UnlockInterfaceStuff not implemented.");
        abort();
    } else {
        original_UnlockInterfaceStuff();
    }
}

function_hook_state_t function_hook_state_InitInterfaceLoadState = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(InitInterfaceLoadState, function_hook_state_InitInterfaceLoadState)
static void(__cdecl*original_InitInterfaceLoadState)() = (void(__cdecl*)())0x0041dcc7;
CARM95_HOOK_FUNCTION(original_InitInterfaceLoadState, InitInterfaceLoadState)
void __cdecl InitInterfaceLoadState() {
    int i;
    LOG_TRACE("()");

    (void)i;

    if (function_hook_state_InitInterfaceLoadState == HOOK_ENABLED) {
        assert(0 && "InitInterfaceLoadState not implemented.");
        abort();
    } else {
        original_InitInterfaceLoadState();
    }
}

function_hook_state_t function_hook_state_ConvertPixTo16BitStripMap = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(ConvertPixTo16BitStripMap, function_hook_state_ConvertPixTo16BitStripMap)
tS8* ConvertPixTo16BitStripMap(br_pixelmap *pBr_map) {
    int i;
    int j;
    int new_line_length;
    int current_size;
    int counting_blanks;
    int counter;
    int chunk_counter;
    int max_line_bytes;
    tU8 *next_byte;
    tU8 *strip_image;
    tU8 *current_strip_pointer;
    tU8 *temp_strip_image;
    tU8 *new_line;
    tU8 byte;
    tU16 *palette_entry;
    LOG_TRACE("(%p)", pBr_map);

    (void)pBr_map;
    (void)i;
    (void)j;
    (void)new_line_length;
    (void)current_size;
    (void)counting_blanks;
    (void)counter;
    (void)chunk_counter;
    (void)max_line_bytes;
    (void)next_byte;
    (void)strip_image;
    (void)current_strip_pointer;
    (void)temp_strip_image;
    (void)new_line;
    (void)byte;
    (void)palette_entry;

    if (function_hook_state_ConvertPixTo16BitStripMap == HOOK_ENABLED) {
        assert(0 && "ConvertPixTo16BitStripMap not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}

function_hook_state_t function_hook_state_ConvertPixToStripMap = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(ConvertPixToStripMap, function_hook_state_ConvertPixToStripMap)
static tS8 *(__cdecl*original_ConvertPixToStripMap)(br_pixelmap *) = (tS8 *(__cdecl*)(br_pixelmap *))0x0041dd01;
CARM95_HOOK_FUNCTION(original_ConvertPixToStripMap, ConvertPixToStripMap)
tS8* __cdecl ConvertPixToStripMap(br_pixelmap *pThe_br_map) {
    int i;
    int j;
    int new_line_length;
    int current_size;
    int counting_blanks;
    int counter;
    int chunk_counter;
    tU8 *next_byte;
    tU8 *the_strip_image;
    tU8 *current_strip_pointer;
    tU8 *temp_strip_image;
    tU8 new_line[800];
    tU8 the_byte;
    LOG_TRACE("(%p)", pThe_br_map);

    (void)pThe_br_map;
    (void)i;
    (void)j;
    (void)new_line_length;
    (void)current_size;
    (void)counting_blanks;
    (void)counter;
    (void)chunk_counter;
    (void)next_byte;
    (void)the_strip_image;
    (void)current_strip_pointer;
    (void)temp_strip_image;
    (void)new_line;
    (void)the_byte;

    if (function_hook_state_ConvertPixToStripMap == HOOK_ENABLED) {
        assert(0 && "ConvertPixToStripMap not implemented.");
        abort();
    } else {
        return original_ConvertPixToStripMap(pThe_br_map);
    }
}

function_hook_state_t function_hook_state_KillWindscreen = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(KillWindscreen, function_hook_state_KillWindscreen)
static void(__cdecl*original_KillWindscreen)(br_model *, br_material *) = (void(__cdecl*)(br_model *, br_material *))0x0041e4de;
CARM95_HOOK_FUNCTION(original_KillWindscreen, KillWindscreen)
void __cdecl KillWindscreen(br_model *pModel, br_material *pMaterial) {
    br_face *face;
    int i;
    LOG_TRACE("(%p, %p)", pModel, pMaterial);

    (void)pModel;
    (void)pMaterial;
    (void)face;
    (void)i;

    if (function_hook_state_KillWindscreen == HOOK_ENABLED) {
        assert(0 && "KillWindscreen not implemented.");
        abort();
    } else {
        original_KillWindscreen(pModel, pMaterial);
    }
}

function_hook_state_t function_hook_state_DropOffDyingPeds = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(DropOffDyingPeds, function_hook_state_DropOffDyingPeds)
static void(__cdecl*original_DropOffDyingPeds)(tCar_spec *) = (void(__cdecl*)(tCar_spec *))0x0041e564;
CARM95_HOOK_FUNCTION(original_DropOffDyingPeds, DropOffDyingPeds)
void __cdecl DropOffDyingPeds(tCar_spec *pCar) {
    br_actor *child;
    br_actor *next;
    LOG_TRACE("(%p)", pCar);

    (void)pCar;
    (void)child;
    (void)next;

    if (function_hook_state_DropOffDyingPeds == HOOK_ENABLED) {
        assert(0 && "DropOffDyingPeds not implemented.");
        abort();
    } else {
        original_DropOffDyingPeds(pCar);
    }
}

function_hook_state_t function_hook_state_DisposeCar = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(DisposeCar, function_hook_state_DisposeCar)
static void(__cdecl*original_DisposeCar)(tCar_spec *, int) = (void(__cdecl*)(tCar_spec *, int))0x0041dfbd;
CARM95_HOOK_FUNCTION(original_DisposeCar, DisposeCar)
void __cdecl DisposeCar(tCar_spec *pCar_spec, int pOwner) {
    int i;
    int j;
    LOG_TRACE("(%p, %d)", pCar_spec, pOwner);

    (void)pCar_spec;
    (void)pOwner;
    (void)i;
    (void)j;

    if (function_hook_state_DisposeCar == HOOK_ENABLED) {
        assert(0 && "DisposeCar not implemented.");
        abort();
    } else {
        original_DisposeCar(pCar_spec, pOwner);
    }
}

function_hook_state_t function_hook_state_AdjustCarCoordinates = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(AdjustCarCoordinates, function_hook_state_AdjustCarCoordinates)
static void(__cdecl*original_AdjustCarCoordinates)(tCar_spec *) = (void(__cdecl*)(tCar_spec *))0x00422a79;
CARM95_HOOK_FUNCTION(original_AdjustCarCoordinates, AdjustCarCoordinates)
void __cdecl AdjustCarCoordinates(tCar_spec *pCar) {
    int i;
    LOG_TRACE("(%p)", pCar);

    (void)pCar;
    (void)i;

    if (function_hook_state_AdjustCarCoordinates == HOOK_ENABLED) {
        assert(0 && "AdjustCarCoordinates not implemented.");
        abort();
    } else {
        original_AdjustCarCoordinates(pCar);
    }
}

function_hook_state_t function_hook_state_LoadSpeedo = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(LoadSpeedo, function_hook_state_LoadSpeedo)
static void(__cdecl*original_LoadSpeedo)(FILE *, int, tCar_spec *) = (void(__cdecl*)(FILE *, int, tCar_spec *))0x00422d43;
CARM95_HOOK_FUNCTION(original_LoadSpeedo, LoadSpeedo)
void __cdecl LoadSpeedo(FILE *pF, int pIndex, tCar_spec *pCar_spec) {
    tPath_name the_path;
    char s[256];
    char *str;
    char the_char1;
    char the_char2;
    LOG_TRACE("(%p, %d, %p)", pF, pIndex, pCar_spec);

    (void)pF;
    (void)pIndex;
    (void)pCar_spec;
    (void)the_path;
    (void)s;
    (void)str;
    (void)the_char1;
    (void)the_char2;

    if (function_hook_state_LoadSpeedo == HOOK_ENABLED) {
        assert(0 && "LoadSpeedo not implemented.");
        abort();
    } else {
        original_LoadSpeedo(pF, pIndex, pCar_spec);
    }
}

function_hook_state_t function_hook_state_LoadTacho = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(LoadTacho, function_hook_state_LoadTacho)
static void(__cdecl*original_LoadTacho)(FILE *, int, tCar_spec *) = (void(__cdecl*)(FILE *, int, tCar_spec *))0x004230de;
CARM95_HOOK_FUNCTION(original_LoadTacho, LoadTacho)
void __cdecl LoadTacho(FILE *pF, int pIndex, tCar_spec *pCar_spec) {
    tPath_name the_path;
    char s[256];
    char *str;
    char the_char1;
    char the_char2;
    LOG_TRACE("(%p, %d, %p)", pF, pIndex, pCar_spec);

    (void)pF;
    (void)pIndex;
    (void)pCar_spec;
    (void)the_path;
    (void)s;
    (void)str;
    (void)the_char1;
    (void)the_char2;

    if (function_hook_state_LoadTacho == HOOK_ENABLED) {
        assert(0 && "LoadTacho not implemented.");
        abort();
    } else {
        original_LoadTacho(pF, pIndex, pCar_spec);
    }
}

function_hook_state_t function_hook_state_LoadHeadups = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(LoadHeadups, function_hook_state_LoadHeadups)
static void(__cdecl*original_LoadHeadups)(FILE *, int, tCar_spec *) = (void(__cdecl*)(FILE *, int, tCar_spec *))0x004233d3;
CARM95_HOOK_FUNCTION(original_LoadHeadups, LoadHeadups)
void __cdecl LoadHeadups(FILE *pF, int pIndex, tCar_spec *pCar_spec) {
    char s[256];
    char *str;
    int j;
    int number_of_slots;
    LOG_TRACE("(%p, %d, %p)", pF, pIndex, pCar_spec);

    (void)pF;
    (void)pIndex;
    (void)pCar_spec;
    (void)s;
    (void)str;
    (void)j;
    (void)number_of_slots;

    if (function_hook_state_LoadHeadups == HOOK_ENABLED) {
        assert(0 && "LoadHeadups not implemented.");
        abort();
    } else {
        original_LoadHeadups(pF, pIndex, pCar_spec);
    }
}

function_hook_state_t function_hook_state_ReadNonCarMechanicsData = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(ReadNonCarMechanicsData, function_hook_state_ReadNonCarMechanicsData)
static void(__cdecl*original_ReadNonCarMechanicsData)(FILE *, tNon_car_spec *) = (void(__cdecl*)(FILE *, tNon_car_spec *))0x0041e5d0;
CARM95_HOOK_FUNCTION(original_ReadNonCarMechanicsData, ReadNonCarMechanicsData)
void __cdecl ReadNonCarMechanicsData(FILE *pF, tNon_car_spec *non_car) {
    int number;
    int i;
    int j;
    char s[256];
    tCollision_info *c;
    br_scalar wid;
    br_scalar het;
    br_scalar len;
    br_scalar ts;
    br_scalar ts1;
    br_scalar snap_angle;
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
    float __block5__x_0;
    float __block5__x_1;
    float __block6__x_0;
    float __block6__x_1;
    float __block6__x_2;
    LOG_TRACE("(%p, %p)", pF, non_car);

    (void)pF;
    (void)non_car;
    (void)number;
    (void)i;
    (void)j;
    (void)s;
    (void)c;
    (void)wid;
    (void)het;
    (void)len;
    (void)ts;
    (void)ts1;
    (void)snap_angle;
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
    (void)__block5__x_0;
    (void)__block5__x_1;
    (void)__block6__x_0;
    (void)__block6__x_1;
    (void)__block6__x_2;

    if (function_hook_state_ReadNonCarMechanicsData == HOOK_ENABLED) {
        assert(0 && "ReadNonCarMechanicsData not implemented.");
        abort();
    } else {
        original_ReadNonCarMechanicsData(pF, non_car);
    }
}

function_hook_state_t function_hook_state_ReadMechanicsData = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(ReadMechanicsData, function_hook_state_ReadMechanicsData)
static void(__cdecl*original_ReadMechanicsData)(FILE *, tCar_spec *) = (void(__cdecl*)(FILE *, tCar_spec *))0x0041edfb;
CARM95_HOOK_FUNCTION(original_ReadMechanicsData, ReadMechanicsData)
void __cdecl ReadMechanicsData(FILE *pF, tCar_spec *c) {
    char s[256];
    char version;
    int i;
    int j;
    br_scalar ratio;
    br_scalar ts1;
    br_scalar theta_front;
    br_scalar theta_back;
    br_scalar theta_comp;
    br_scalar wid;
    br_scalar het;
    br_scalar len;
    br_vector3 *actor_offset;
    br_scalar speed;
    br_scalar force;
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
    float __block5__x_0;
    float __block5__x_1;
    float __block6__x_0;
    float __block6__x_1;
    float __block7__x_0;
    float __block7__x_1;
    float __block7__x_2;
    float __block8__x_0;
    float __block8__x_1;
    float __block8__x_2;
    float __block9__x_0;
    float __block9__x_1;
    LOG_TRACE("(%p, %p)", pF, c);

    (void)pF;
    (void)c;
    (void)s;
    (void)version;
    (void)i;
    (void)j;
    (void)ratio;
    (void)ts1;
    (void)theta_front;
    (void)theta_back;
    (void)theta_comp;
    (void)wid;
    (void)het;
    (void)len;
    (void)actor_offset;
    (void)speed;
    (void)force;
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
    (void)__block5__x_0;
    (void)__block5__x_1;
    (void)__block6__x_0;
    (void)__block6__x_1;
    (void)__block7__x_0;
    (void)__block7__x_1;
    (void)__block7__x_2;
    (void)__block8__x_0;
    (void)__block8__x_1;
    (void)__block8__x_2;
    (void)__block9__x_0;
    (void)__block9__x_1;

    if (function_hook_state_ReadMechanicsData == HOOK_ENABLED) {
        assert(0 && "ReadMechanicsData not implemented.");
        abort();
    } else {
        original_ReadMechanicsData(pF, c);
    }
}

function_hook_state_t function_hook_state_LoadGear = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(LoadGear, function_hook_state_LoadGear)
static void(__cdecl*original_LoadGear)(FILE *, int, tCar_spec *) = (void(__cdecl*)(FILE *, int, tCar_spec *))0x004237be;
CARM95_HOOK_FUNCTION(original_LoadGear, LoadGear)
void __cdecl LoadGear(FILE *pF, int pIndex, tCar_spec *pCar_spec) {
    tPath_name the_path;
    char s[256];
    char *str;
    LOG_TRACE("(%p, %d, %p)", pF, pIndex, pCar_spec);

    (void)pF;
    (void)pIndex;
    (void)pCar_spec;
    (void)the_path;
    (void)s;
    (void)str;

    if (function_hook_state_LoadGear == HOOK_ENABLED) {
        assert(0 && "LoadGear not implemented.");
        abort();
    } else {
        original_LoadGear(pF, pIndex, pCar_spec);
    }
}

function_hook_state_t function_hook_state_AddRefOffset = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(AddRefOffset, function_hook_state_AddRefOffset)
static void(__cdecl*original_AddRefOffset)(int *) = (void(__cdecl*)(int *))0x0042387c;
CARM95_HOOK_FUNCTION(original_AddRefOffset, AddRefOffset)
void __cdecl AddRefOffset(int *pRef_holder) {
    LOG_TRACE("(%p)", pRef_holder);

    (void)pRef_holder;

    if (function_hook_state_AddRefOffset == HOOK_ENABLED) {
        assert(0 && "AddRefOffset not implemented.");
        abort();
    } else {
        original_AddRefOffset(pRef_holder);
    }
}

function_hook_state_t function_hook_state_GetDamageProgram = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(GetDamageProgram, function_hook_state_GetDamageProgram)
static void(__cdecl*original_GetDamageProgram)(FILE *, tCar_spec *, tImpact_location) = (void(__cdecl*)(FILE *, tCar_spec *, tImpact_location))0x0042389d;
CARM95_HOOK_FUNCTION(original_GetDamageProgram, GetDamageProgram)
void __cdecl GetDamageProgram(FILE *pF, tCar_spec *pCar_spec, tImpact_location pImpact_location) {
    tDamage_clause *the_clause;
    int i;
    int j;
    int k;
    int count;
    char s[256];
    char delim[64];
    char *str;
    LOG_TRACE("(%p, %p, %d)", pF, pCar_spec, pImpact_location);

    (void)pF;
    (void)pCar_spec;
    (void)pImpact_location;
    (void)the_clause;
    (void)i;
    (void)j;
    (void)k;
    (void)count;
    (void)s;
    (void)delim;
    (void)str;

    if (function_hook_state_GetDamageProgram == HOOK_ENABLED) {
        assert(0 && "GetDamageProgram not implemented.");
        abort();
    } else {
        original_GetDamageProgram(pF, pCar_spec, pImpact_location);
    }
}

function_hook_state_t function_hook_state_LinkModel = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(LinkModel, function_hook_state_LinkModel)
static br_uint_32(__cdecl*original_LinkModel)(br_actor *, tModel_pool *) = (br_uint_32(__cdecl*)(br_actor *, tModel_pool *))0x00423d40;
CARM95_HOOK_FUNCTION(original_LinkModel, LinkModel)
br_uint_32 __cdecl LinkModel(br_actor *pActor, tModel_pool *pModel_pool) {
    int i;
    LOG_TRACE("(%p, %p)", pActor, pModel_pool);

    (void)pActor;
    (void)pModel_pool;
    (void)i;

    if (function_hook_state_LinkModel == HOOK_ENABLED) {
        assert(0 && "LinkModel not implemented.");
        abort();
    } else {
        return original_LinkModel(pActor, pModel_pool);
    }
}

function_hook_state_t function_hook_state_FreeUpBonnetModels = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(FreeUpBonnetModels, function_hook_state_FreeUpBonnetModels)
static void(__cdecl*original_FreeUpBonnetModels)(br_model **, int) = (void(__cdecl*)(br_model **, int))0x00423c66;
CARM95_HOOK_FUNCTION(original_FreeUpBonnetModels, FreeUpBonnetModels)
void __cdecl FreeUpBonnetModels(br_model **pModel_array, int pModel_count) {
    int i;
    LOG_TRACE("(%p, %d)", pModel_array, pModel_count);

    (void)pModel_array;
    (void)pModel_count;
    (void)i;

    if (function_hook_state_FreeUpBonnetModels == HOOK_ENABLED) {
        assert(0 && "FreeUpBonnetModels not implemented.");
        abort();
    } else {
        original_FreeUpBonnetModels(pModel_array, pModel_count);
    }
}

function_hook_state_t function_hook_state_LinkModelsToActor = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(LinkModelsToActor, function_hook_state_LinkModelsToActor)
static void(__cdecl*original_LinkModelsToActor)(br_actor *, br_model **, int) = (void(__cdecl*)(br_actor *, br_model **, int))0x00423d11;
CARM95_HOOK_FUNCTION(original_LinkModelsToActor, LinkModelsToActor)
void __cdecl LinkModelsToActor(br_actor *pActor, br_model **pModel_array, int pModel_count) {
    tModel_pool model_pool;
    LOG_TRACE("(%p, %p, %d)", pActor, pModel_array, pModel_count);

    (void)pActor;
    (void)pModel_array;
    (void)pModel_count;
    (void)model_pool;

    if (function_hook_state_LinkModelsToActor == HOOK_ENABLED) {
        assert(0 && "LinkModelsToActor not implemented.");
        abort();
    } else {
        original_LinkModelsToActor(pActor, pModel_array, pModel_count);
    }
}

function_hook_state_t function_hook_state_ReadShrapnelMaterials = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(ReadShrapnelMaterials, function_hook_state_ReadShrapnelMaterials)
static void(__cdecl*original_ReadShrapnelMaterials)(FILE *, tCollision_info *) = (void(__cdecl*)(FILE *, tCollision_info *))0x0041fde3;
CARM95_HOOK_FUNCTION(original_ReadShrapnelMaterials, ReadShrapnelMaterials)
void __cdecl ReadShrapnelMaterials(FILE *pF, tCollision_info *pCar_spec) {
    char s[256];
    char version;
    int i;
    LOG_TRACE("(%p, %p)", pF, pCar_spec);

    (void)pF;
    (void)pCar_spec;
    (void)s;
    (void)version;
    (void)i;

    if (function_hook_state_ReadShrapnelMaterials == HOOK_ENABLED) {
        assert(0 && "ReadShrapnelMaterials not implemented.");
        abort();
    } else {
        original_ReadShrapnelMaterials(pF, pCar_spec);
    }
}

function_hook_state_t function_hook_state_CloneCar = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(CloneCar, function_hook_state_CloneCar)
static void(__cdecl*original_CloneCar)(tCar_spec **, tCar_spec *) = (void(__cdecl*)(tCar_spec **, tCar_spec *))0x0041fe6a;
CARM95_HOOK_FUNCTION(original_CloneCar, CloneCar)
void __cdecl CloneCar(tCar_spec **pOutput_car, tCar_spec *pInput_car) {
    int i;
    LOG_TRACE("(%p, %p)", pOutput_car, pInput_car);

    (void)pOutput_car;
    (void)pInput_car;
    (void)i;

    if (function_hook_state_CloneCar == HOOK_ENABLED) {
        assert(0 && "CloneCar not implemented.");
        abort();
    } else {
        original_CloneCar(pOutput_car, pInput_car);
    }
}

function_hook_state_t function_hook_state_DisposeClonedCar = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(DisposeClonedCar, function_hook_state_DisposeClonedCar)
static void(__cdecl*original_DisposeClonedCar)(tCar_spec *) = (void(__cdecl*)(tCar_spec *))0x0041ff2f;
CARM95_HOOK_FUNCTION(original_DisposeClonedCar, DisposeClonedCar)
void __cdecl DisposeClonedCar(tCar_spec *pCar) {
    LOG_TRACE("(%p)", pCar);

    (void)pCar;

    if (function_hook_state_DisposeClonedCar == HOOK_ENABLED) {
        assert(0 && "DisposeClonedCar not implemented.");
        abort();
    } else {
        original_DisposeClonedCar(pCar);
    }
}

function_hook_state_t function_hook_state_RemoveDoubleSided = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(RemoveDoubleSided, function_hook_state_RemoveDoubleSided)
static int(__cdecl*original_RemoveDoubleSided)(br_model *) = (int(__cdecl*)(br_model *))0x0041ff58;
CARM95_HOOK_FUNCTION(original_RemoveDoubleSided, RemoveDoubleSided)
int __cdecl RemoveDoubleSided(br_model *pModel) {
    br_face *faces;
    br_face *face;
    int temp;
    int num_double_sided_faces;
    int i;
    int orig_nfaces;
    int result;
    LOG_TRACE("(%p)", pModel);

    (void)pModel;
    (void)faces;
    (void)face;
    (void)temp;
    (void)num_double_sided_faces;
    (void)i;
    (void)orig_nfaces;
    (void)result;

    if (function_hook_state_RemoveDoubleSided == HOOK_ENABLED) {
        assert(0 && "RemoveDoubleSided not implemented.");
        abort();
    } else {
        return original_RemoveDoubleSided(pModel);
    }
}

function_hook_state_t function_hook_state_MungeWindscreen = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(MungeWindscreen, function_hook_state_MungeWindscreen)
static void(__cdecl*original_MungeWindscreen)(br_model *) = (void(__cdecl*)(br_model *))0x00423e17;
CARM95_HOOK_FUNCTION(original_MungeWindscreen, MungeWindscreen)
void __cdecl MungeWindscreen(br_model *pModel) {
    br_face *face;
    int i;
    LOG_TRACE("(%p)", pModel);

    (void)pModel;
    (void)face;
    (void)i;

    if (function_hook_state_MungeWindscreen == HOOK_ENABLED) {
        assert(0 && "MungeWindscreen not implemented.");
        abort();
    } else {
        original_MungeWindscreen(pModel);
    }
}

function_hook_state_t function_hook_state_SetModelFlags = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(SetModelFlags, function_hook_state_SetModelFlags)
static void(__cdecl*original_SetModelFlags)(br_model *, int) = (void(__cdecl*)(br_model *, int))0x00423f0b;
CARM95_HOOK_FUNCTION(original_SetModelFlags, SetModelFlags)
void __cdecl SetModelFlags(br_model *pModel, int pOwner) {
    LOG_TRACE("(%p, %d)", pModel, pOwner);

    (void)pModel;
    (void)pOwner;

    if (function_hook_state_SetModelFlags == HOOK_ENABLED) {
        assert(0 && "SetModelFlags not implemented.");
        abort();
    } else {
        original_SetModelFlags(pModel, pOwner);
    }
}

function_hook_state_t function_hook_state_LoadCar = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(LoadCar, function_hook_state_LoadCar)
static void(__cdecl*original_LoadCar)(char *, tDriver, tCar_spec *, int, char *, tBrender_storage *) = (void(__cdecl*)(char *, tDriver, tCar_spec *, int, char *, tBrender_storage *))0x00420144;
CARM95_HOOK_FUNCTION(original_LoadCar, LoadCar)
void __cdecl LoadCar(char *pCar_name, tDriver pDriver, tCar_spec *pCar_spec, int pOwner, char *pDriver_name, tBrender_storage *pStorage_space) {
    FILE *f;
    FILE *g;
    FILE *h;
    tPath_name the_path;
    int i;
    int j;
    int k;
    int its_a_floorpan;
    int number_of_floorpans;
    int point_num;
    int initial_vertex;
    int old_model_count;
    int old_material_count;
    int temp_index;
    int vertex_array_size;
    char s[256];
    char *str;
    br_pixelmap *the_image;
    float rate;
    float temp_float;
    br_model *model;
    br_vector3 tv;
    int v;
    int v_num;
    int group;
    int vertex_total;
    LOG_TRACE("(\"%s\", %d, %p, %d, \"%s\", %p)", pCar_name, pDriver, pCar_spec, pOwner, pDriver_name, pStorage_space);

    (void)pCar_name;
    (void)pDriver;
    (void)pCar_spec;
    (void)pOwner;
    (void)pDriver_name;
    (void)pStorage_space;
    (void)f;
    (void)g;
    (void)h;
    (void)the_path;
    (void)i;
    (void)j;
    (void)k;
    (void)its_a_floorpan;
    (void)number_of_floorpans;
    (void)point_num;
    (void)initial_vertex;
    (void)old_model_count;
    (void)old_material_count;
    (void)temp_index;
    (void)vertex_array_size;
    (void)s;
    (void)str;
    (void)the_image;
    (void)rate;
    (void)temp_float;
    (void)model;
    (void)tv;
    (void)v;
    (void)v_num;
    (void)group;
    (void)vertex_total;

    if (function_hook_state_LoadCar == HOOK_ENABLED) {
        assert(0 && "LoadCar not implemented.");
        abort();
    } else {
        original_LoadCar(pCar_name, pDriver, pCar_spec, pOwner, pDriver_name, pStorage_space);
    }
}

function_hook_state_t function_hook_state_LoadHeadupImages = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(LoadHeadupImages, function_hook_state_LoadHeadupImages)
static void(__cdecl*original_LoadHeadupImages)() = (void(__cdecl*)())0x00423fad;
CARM95_HOOK_FUNCTION(original_LoadHeadupImages, LoadHeadupImages)
void __cdecl LoadHeadupImages() {
    int i;
    tPath_name the_path;
    LOG_TRACE("()");

    (void)i;
    (void)the_path;

    if (function_hook_state_LoadHeadupImages == HOOK_ENABLED) {
        assert(0 && "LoadHeadupImages not implemented.");
        abort();
    } else {
        original_LoadHeadupImages();
    }
}

function_hook_state_t function_hook_state_DisposeHeadupImages = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(DisposeHeadupImages, function_hook_state_DisposeHeadupImages)
static void(__cdecl*original_DisposeHeadupImages)() = (void(__cdecl*)())0x0042405e;
CARM95_HOOK_FUNCTION(original_DisposeHeadupImages, DisposeHeadupImages)
void __cdecl DisposeHeadupImages() {
    int i;
    tPath_name the_path;
    LOG_TRACE("()");

    (void)i;
    (void)the_path;

    if (function_hook_state_DisposeHeadupImages == HOOK_ENABLED) {
        assert(0 && "DisposeHeadupImages not implemented.");
        abort();
    } else {
        original_DisposeHeadupImages();
    }
}

function_hook_state_t function_hook_state_OpenRaceFile = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(OpenRaceFile, function_hook_state_OpenRaceFile)
static FILE *(__cdecl*original_OpenRaceFile)() = (FILE *(__cdecl*)())0x004240b1;
CARM95_HOOK_FUNCTION(original_OpenRaceFile, OpenRaceFile)
FILE* __cdecl OpenRaceFile() {
    FILE *f;
    tPath_name the_path;
    LOG_TRACE("()");

    (void)f;
    (void)the_path;

    if (function_hook_state_OpenRaceFile == HOOK_ENABLED) {
        assert(0 && "OpenRaceFile not implemented.");
        abort();
    } else {
        return original_OpenRaceFile();
    }
}

function_hook_state_t function_hook_state_SkipRestOfRace = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(SkipRestOfRace, function_hook_state_SkipRestOfRace)
static void(__cdecl*original_SkipRestOfRace)(FILE *) = (void(__cdecl*)(FILE *))0x0042434a;
CARM95_HOOK_FUNCTION(original_SkipRestOfRace, SkipRestOfRace)
void __cdecl SkipRestOfRace(FILE *pF) {
    int j;
    int k;
    int text_chunk_count;
    int line_count;
    char s[256];
    LOG_TRACE("(%p)", pF);

    (void)pF;
    (void)j;
    (void)k;
    (void)text_chunk_count;
    (void)line_count;
    (void)s;

    if (function_hook_state_SkipRestOfRace == HOOK_ENABLED) {
        assert(0 && "SkipRestOfRace not implemented.");
        abort();
    } else {
        original_SkipRestOfRace(pF);
    }
}

function_hook_state_t function_hook_state_LoadRaces = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(LoadRaces, function_hook_state_LoadRaces)
static void(__cdecl*original_LoadRaces)(tRace_list_spec *, int *, int) = (void(__cdecl*)(tRace_list_spec *, int *, int))0x00424116;
CARM95_HOOK_FUNCTION(original_LoadRaces, LoadRaces)
void __cdecl LoadRaces(tRace_list_spec *pRace_list, int *pCount, int pRace_type_index) {
    FILE *f;
    int i;
    int j;
    int k;
    int number_of_racers;
    int last_race;
    char s[256];
    char *str;
    LOG_TRACE("(%p, %p, %d)", pRace_list, pCount, pRace_type_index);

    (void)pRace_list;
    (void)pCount;
    (void)pRace_type_index;
    (void)f;
    (void)i;
    (void)j;
    (void)k;
    (void)number_of_racers;
    (void)last_race;
    (void)s;
    (void)str;

    if (function_hook_state_LoadRaces == HOOK_ENABLED) {
        assert(0 && "LoadRaces not implemented.");
        abort();
    } else {
        original_LoadRaces(pRace_list, pCount, pRace_type_index);
    }
}

function_hook_state_t function_hook_state_UnlockOpponentMugshot = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(UnlockOpponentMugshot, function_hook_state_UnlockOpponentMugshot)
static void(__cdecl*original_UnlockOpponentMugshot)(int) = (void(__cdecl*)(int))0x00424466;
CARM95_HOOK_FUNCTION(original_UnlockOpponentMugshot, UnlockOpponentMugshot)
void __cdecl UnlockOpponentMugshot(int pIndex) {
    LOG_TRACE("(%d)", pIndex);

    (void)pIndex;

    if (function_hook_state_UnlockOpponentMugshot == HOOK_ENABLED) {
        assert(0 && "UnlockOpponentMugshot not implemented.");
        abort();
    } else {
        original_UnlockOpponentMugshot(pIndex);
    }
}

function_hook_state_t function_hook_state_LoadOpponentMugShot = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(LoadOpponentMugShot, function_hook_state_LoadOpponentMugShot)
static void(__cdecl*original_LoadOpponentMugShot)(int) = (void(__cdecl*)(int))0x004244b0;
CARM95_HOOK_FUNCTION(original_LoadOpponentMugShot, LoadOpponentMugShot)
void __cdecl LoadOpponentMugShot(int pIndex) {
    LOG_TRACE("(%d)", pIndex);

    (void)pIndex;

    if (function_hook_state_LoadOpponentMugShot == HOOK_ENABLED) {
        assert(0 && "LoadOpponentMugShot not implemented.");
        abort();
    } else {
        original_LoadOpponentMugShot(pIndex);
    }
}

function_hook_state_t function_hook_state_DisposeOpponentGridIcon = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(DisposeOpponentGridIcon, function_hook_state_DisposeOpponentGridIcon)
static void(__cdecl*original_DisposeOpponentGridIcon)(tRace_info *, int) = (void(__cdecl*)(tRace_info *, int))0x00424557;
CARM95_HOOK_FUNCTION(original_DisposeOpponentGridIcon, DisposeOpponentGridIcon)
void __cdecl DisposeOpponentGridIcon(tRace_info *pRace_info, int pIndex) {
    LOG_TRACE("(%p, %d)", pRace_info, pIndex);

    (void)pRace_info;
    (void)pIndex;

    if (function_hook_state_DisposeOpponentGridIcon == HOOK_ENABLED) {
        assert(0 && "DisposeOpponentGridIcon not implemented.");
        abort();
    } else {
        original_DisposeOpponentGridIcon(pRace_info, pIndex);
    }
}

function_hook_state_t function_hook_state_LoadOpponentGridIcon = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(LoadOpponentGridIcon, function_hook_state_LoadOpponentGridIcon)
static void(__cdecl*original_LoadOpponentGridIcon)(tRace_info *, int) = (void(__cdecl*)(tRace_info *, int))0x004245cf;
CARM95_HOOK_FUNCTION(original_LoadOpponentGridIcon, LoadOpponentGridIcon)
void __cdecl LoadOpponentGridIcon(tRace_info *pRace_info, int pIndex) {
    LOG_TRACE("(%p, %d)", pRace_info, pIndex);

    (void)pRace_info;
    (void)pIndex;

    if (function_hook_state_LoadOpponentGridIcon == HOOK_ENABLED) {
        assert(0 && "LoadOpponentGridIcon not implemented.");
        abort();
    } else {
        original_LoadOpponentGridIcon(pRace_info, pIndex);
    }
}

function_hook_state_t function_hook_state_LoadRaceInfo = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(LoadRaceInfo, function_hook_state_LoadRaceInfo)
static void(__cdecl*original_LoadRaceInfo)(int, tRace_info *) = (void(__cdecl*)(int, tRace_info *))0x0042466e;
CARM95_HOOK_FUNCTION(original_LoadRaceInfo, LoadRaceInfo)
void __cdecl LoadRaceInfo(int pRace_index, tRace_info *pRace_info) {
    FILE *f;
    int i;
    int j;
    int k;
    int duplicate;
    int substitute;
    int auto_scum_count;
    int old_index;
    int temp_index;
    char s[256];
    char *str;
    float temp_float;
    tText_chunk *the_chunk;
    LOG_TRACE("(%d, %p)", pRace_index, pRace_info);

    (void)pRace_index;
    (void)pRace_info;
    (void)f;
    (void)i;
    (void)j;
    (void)k;
    (void)duplicate;
    (void)substitute;
    (void)auto_scum_count;
    (void)old_index;
    (void)temp_index;
    (void)s;
    (void)str;
    (void)temp_float;
    (void)the_chunk;

    if (function_hook_state_LoadRaceInfo == HOOK_ENABLED) {
        assert(0 && "LoadRaceInfo not implemented.");
        abort();
    } else {
        original_LoadRaceInfo(pRace_index, pRace_info);
    }
}

function_hook_state_t function_hook_state_DisposeRaceInfo = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(DisposeRaceInfo, function_hook_state_DisposeRaceInfo)
static void(__cdecl*original_DisposeRaceInfo)(tRace_info *) = (void(__cdecl*)(tRace_info *))0x00424ac0;
CARM95_HOOK_FUNCTION(original_DisposeRaceInfo, DisposeRaceInfo)
void __cdecl DisposeRaceInfo(tRace_info *pRace_info) {
    int i;
    int j;
    int k;
    tText_chunk *the_chunk;
    LOG_TRACE("(%p)", pRace_info);

    (void)pRace_info;
    (void)i;
    (void)j;
    (void)k;
    (void)the_chunk;

    if (function_hook_state_DisposeRaceInfo == HOOK_ENABLED) {
        assert(0 && "DisposeRaceInfo not implemented.");
        abort();
    } else {
        original_DisposeRaceInfo(pRace_info);
    }
}

function_hook_state_t function_hook_state_LoadGridIcons = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(LoadGridIcons, function_hook_state_LoadGridIcons)
static void(__cdecl*original_LoadGridIcons)(tRace_info *) = (void(__cdecl*)(tRace_info *))0x00424c2e;
CARM95_HOOK_FUNCTION(original_LoadGridIcons, LoadGridIcons)
void __cdecl LoadGridIcons(tRace_info *pRace_info) {
    int i;
    LOG_TRACE("(%p)", pRace_info);

    (void)pRace_info;
    (void)i;

    if (function_hook_state_LoadGridIcons == HOOK_ENABLED) {
        assert(0 && "LoadGridIcons not implemented.");
        abort();
    } else {
        original_LoadGridIcons(pRace_info);
    }
}

function_hook_state_t function_hook_state_DisposeGridIcons = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(DisposeGridIcons, function_hook_state_DisposeGridIcons)
static void(__cdecl*original_DisposeGridIcons)(tRace_info *) = (void(__cdecl*)(tRace_info *))0x00424cab;
CARM95_HOOK_FUNCTION(original_DisposeGridIcons, DisposeGridIcons)
void __cdecl DisposeGridIcons(tRace_info *pRace_info) {
    int i;
    LOG_TRACE("(%p)", pRace_info);

    (void)pRace_info;
    (void)i;

    if (function_hook_state_DisposeGridIcons == HOOK_ENABLED) {
        assert(0 && "DisposeGridIcons not implemented.");
        abort();
    } else {
        original_DisposeGridIcons(pRace_info);
    }
}

function_hook_state_t function_hook_state_LoadOpponents = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(LoadOpponents, function_hook_state_LoadOpponents)
static void(__cdecl*original_LoadOpponents)() = (void(__cdecl*)())0x00424d15;
CARM95_HOOK_FUNCTION(original_LoadOpponents, LoadOpponents)
void __cdecl LoadOpponents() {
    FILE *f;
    tPath_name the_path;
    int i;
    int j;
    int k;
    char s[256];
    char *str;
    tText_chunk *the_chunk;
    LOG_TRACE("()");

    (void)f;
    (void)the_path;
    (void)i;
    (void)j;
    (void)k;
    (void)s;
    (void)str;
    (void)the_chunk;

    if (function_hook_state_LoadOpponents == HOOK_ENABLED) {
        assert(0 && "LoadOpponents not implemented.");
        abort();
    } else {
        original_LoadOpponents();
    }
}

function_hook_state_t function_hook_state_LoadBRFont = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(LoadBRFont, function_hook_state_LoadBRFont)
static br_font *(__cdecl*original_LoadBRFont)(char *) = (br_font *(__cdecl*)(char *))0x004252ee;
CARM95_HOOK_FUNCTION(original_LoadBRFont, LoadBRFont)
br_font* __cdecl LoadBRFont(char *pName) {
    FILE *f;
    tPath_name the_path;
    br_font *the_font;
    tU32 data_size;
    int i;
    LOG_TRACE("(\"%s\")", pName);

    (void)pName;
    (void)f;
    (void)the_path;
    (void)the_font;
    (void)data_size;
    (void)i;

    if (function_hook_state_LoadBRFont == HOOK_ENABLED) {
        assert(0 && "LoadBRFont not implemented.");
        abort();
    } else {
        return original_LoadBRFont(pName);
    }
}

function_hook_state_t function_hook_state_LoadParts = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(LoadParts, function_hook_state_LoadParts)
static void(__cdecl*original_LoadParts)() = (void(__cdecl*)())0x00425573;
CARM95_HOOK_FUNCTION(original_LoadParts, LoadParts)
void __cdecl LoadParts() {
    int i;
    int j;
    LOG_TRACE("()");

    (void)i;
    (void)j;

    if (function_hook_state_LoadParts == HOOK_ENABLED) {
        assert(0 && "LoadParts not implemented.");
        abort();
    } else {
        original_LoadParts();
    }
}

function_hook_state_t function_hook_state_UnlockParts = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(UnlockParts, function_hook_state_UnlockParts)
static void(__cdecl*original_UnlockParts)() = (void(__cdecl*)())0x004256b1;
CARM95_HOOK_FUNCTION(original_UnlockParts, UnlockParts)
void __cdecl UnlockParts() {
    int i;
    int j;
    LOG_TRACE("()");

    (void)i;
    (void)j;

    if (function_hook_state_UnlockParts == HOOK_ENABLED) {
        assert(0 && "UnlockParts not implemented.");
        abort();
    } else {
        original_UnlockParts();
    }
}

function_hook_state_t function_hook_state_LoadChromeFont = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(LoadChromeFont, function_hook_state_LoadChromeFont)
static br_pixelmap *(__cdecl*original_LoadChromeFont)() = (br_pixelmap *(__cdecl*)())0x0042575f;
CARM95_HOOK_FUNCTION(original_LoadChromeFont, LoadChromeFont)
br_pixelmap* __cdecl LoadChromeFont() {
    br_pixelmap *result;
    LOG_TRACE("()");

    (void)result;

    if (function_hook_state_LoadChromeFont == HOOK_ENABLED) {
        assert(0 && "LoadChromeFont not implemented.");
        abort();
    } else {
        return original_LoadChromeFont();
    }
}

function_hook_state_t function_hook_state_DisposeChromeFont = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(DisposeChromeFont, function_hook_state_DisposeChromeFont)
static void(__cdecl*original_DisposeChromeFont)(br_pixelmap *) = (void(__cdecl*)(br_pixelmap *))0x00425799;
CARM95_HOOK_FUNCTION(original_DisposeChromeFont, DisposeChromeFont)
void __cdecl DisposeChromeFont(br_pixelmap *pThe_font) {
    LOG_TRACE("(%p)", pThe_font);

    (void)pThe_font;

    if (function_hook_state_DisposeChromeFont == HOOK_ENABLED) {
        assert(0 && "DisposeChromeFont not implemented.");
        abort();
    } else {
        original_DisposeChromeFont(pThe_font);
    }
}

function_hook_state_t function_hook_state_GetALineAndInterpretCommand = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(GetALineAndInterpretCommand, function_hook_state_GetALineAndInterpretCommand)
static int(__cdecl*original_GetALineAndInterpretCommand)(FILE *, char **, int) = (int(__cdecl*)(FILE *, char **, int))0x004257b0;
CARM95_HOOK_FUNCTION(original_GetALineAndInterpretCommand, GetALineAndInterpretCommand)
int __cdecl GetALineAndInterpretCommand(FILE *pF, char **pString_list, int pCount) {
    int i;
    char s[256];
    char *str;
    LOG_TRACE("(%p, %p, %d)", pF, pString_list, pCount);

    (void)pF;
    (void)pString_list;
    (void)pCount;
    (void)i;
    (void)s;
    (void)str;

    if (function_hook_state_GetALineAndInterpretCommand == HOOK_ENABLED) {
        assert(0 && "GetALineAndInterpretCommand not implemented.");
        abort();
    } else {
        return original_GetALineAndInterpretCommand(pF, pString_list, pCount);
    }
}

function_hook_state_t function_hook_state_GetAnInt = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(GetAnInt, function_hook_state_GetAnInt)
static int(__cdecl*original_GetAnInt)(FILE *) = (int(__cdecl*)(FILE *))0x00425878;
CARM95_HOOK_FUNCTION(original_GetAnInt, GetAnInt)
int __cdecl GetAnInt(FILE *pF) {
    char s[256];
    char *str;
    int result;
    LOG_TRACE("(%p)", pF);

    (void)pF;
    (void)s;
    (void)str;
    (void)result;

    if (function_hook_state_GetAnInt == HOOK_ENABLED) {
        assert(0 && "GetAnInt not implemented.");
        abort();
    } else {
        return original_GetAnInt(pF);
    }
}

function_hook_state_t function_hook_state_GetAFloat = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(GetAFloat, function_hook_state_GetAFloat)
static float(__cdecl*original_GetAFloat)(FILE *) = (float(__cdecl*)(FILE *))0x004258d0;
CARM95_HOOK_FUNCTION(original_GetAFloat, GetAFloat)
float __cdecl GetAFloat(FILE *pF) {
    char s[256];
    char *str;
    float result;
    LOG_TRACE("(%p)", pF);

    (void)pF;
    (void)s;
    (void)str;
    (void)result;

    if (function_hook_state_GetAFloat == HOOK_ENABLED) {
        assert(0 && "GetAFloat not implemented.");
        abort();
    } else {
        return original_GetAFloat(pF);
    }
}

function_hook_state_t function_hook_state_GetAFloatPercent = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(GetAFloatPercent, function_hook_state_GetAFloatPercent)
static float(__cdecl*original_GetAFloatPercent)(FILE *) = (float(__cdecl*)(FILE *))0x00425928;
CARM95_HOOK_FUNCTION(original_GetAFloatPercent, GetAFloatPercent)
float __cdecl GetAFloatPercent(FILE *pF) {
    char s[256];
    char *str;
    float result;
    LOG_TRACE("(%p)", pF);

    (void)pF;
    (void)s;
    (void)str;
    (void)result;

    if (function_hook_state_GetAFloatPercent == HOOK_ENABLED) {
        assert(0 && "GetAFloatPercent not implemented.");
        abort();
    } else {
        return original_GetAFloatPercent(pF);
    }
}

function_hook_state_t function_hook_state_GetPairOfFloats = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(GetPairOfFloats, function_hook_state_GetPairOfFloats)
static void(__cdecl*original_GetPairOfFloats)(FILE *, float *, float *) = (void(__cdecl*)(FILE *, float *, float *))0x00425986;
CARM95_HOOK_FUNCTION(original_GetPairOfFloats, GetPairOfFloats)
void __cdecl GetPairOfFloats(FILE *pF, float *pF1, float *pF2) {
    char s[256];
    char *str;
    LOG_TRACE("(%p, %p, %p)", pF, pF1, pF2);

    (void)pF;
    (void)pF1;
    (void)pF2;
    (void)s;
    (void)str;

    if (function_hook_state_GetPairOfFloats == HOOK_ENABLED) {
        assert(0 && "GetPairOfFloats not implemented.");
        abort();
    } else {
        original_GetPairOfFloats(pF, pF1, pF2);
    }
}

function_hook_state_t function_hook_state_GetThreeFloats = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(GetThreeFloats, function_hook_state_GetThreeFloats)
static void(__cdecl*original_GetThreeFloats)(FILE *, float *, float *, float *) = (void(__cdecl*)(FILE *, float *, float *, float *))0x004259fd;
CARM95_HOOK_FUNCTION(original_GetThreeFloats, GetThreeFloats)
void __cdecl GetThreeFloats(FILE *pF, float *pF1, float *pF2, float *pF3) {
    char s[256];
    char *str;
    LOG_TRACE("(%p, %p, %p, %p)", pF, pF1, pF2, pF3);

    (void)pF;
    (void)pF1;
    (void)pF2;
    (void)pF3;
    (void)s;
    (void)str;

    if (function_hook_state_GetThreeFloats == HOOK_ENABLED) {
        assert(0 && "GetThreeFloats not implemented.");
        abort();
    } else {
        original_GetThreeFloats(pF, pF1, pF2, pF3);
    }
}

function_hook_state_t function_hook_state_GetPairOfInts = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(GetPairOfInts, function_hook_state_GetPairOfInts)
static void(__cdecl*original_GetPairOfInts)(FILE *, int *, int *) = (void(__cdecl*)(FILE *, int *, int *))0x00425a9b;
CARM95_HOOK_FUNCTION(original_GetPairOfInts, GetPairOfInts)
void __cdecl GetPairOfInts(FILE *pF, int *pF1, int *pF2) {
    char s[256];
    char *str;
    LOG_TRACE("(%p, %p, %p)", pF, pF1, pF2);

    (void)pF;
    (void)pF1;
    (void)pF2;
    (void)s;
    (void)str;

    if (function_hook_state_GetPairOfInts == HOOK_ENABLED) {
        assert(0 && "GetPairOfInts not implemented.");
        abort();
    } else {
        original_GetPairOfInts(pF, pF1, pF2);
    }
}

function_hook_state_t function_hook_state_GetThreeInts = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(GetThreeInts, function_hook_state_GetThreeInts)
static void(__cdecl*original_GetThreeInts)(FILE *, int *, int *, int *) = (void(__cdecl*)(FILE *, int *, int *, int *))0x00425b12;
CARM95_HOOK_FUNCTION(original_GetThreeInts, GetThreeInts)
void __cdecl GetThreeInts(FILE *pF, int *pF1, int *pF2, int *pF3) {
    char s[256];
    char *str;
    LOG_TRACE("(%p, %p, %p, %p)", pF, pF1, pF2, pF3);

    (void)pF;
    (void)pF1;
    (void)pF2;
    (void)pF3;
    (void)s;
    (void)str;

    if (function_hook_state_GetThreeInts == HOOK_ENABLED) {
        assert(0 && "GetThreeInts not implemented.");
        abort();
    } else {
        original_GetThreeInts(pF, pF1, pF2, pF3);
    }
}

function_hook_state_t function_hook_state_GetThreeIntsAndAString = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(GetThreeIntsAndAString, function_hook_state_GetThreeIntsAndAString)
static void(__cdecl*original_GetThreeIntsAndAString)(FILE *, int *, int *, int *, char *) = (void(__cdecl*)(FILE *, int *, int *, int *, char *))0x00425bb0;
CARM95_HOOK_FUNCTION(original_GetThreeIntsAndAString, GetThreeIntsAndAString)
void __cdecl GetThreeIntsAndAString(FILE *pF, int *pF1, int *pF2, int *pF3, char *pS) {
    char s[256];
    char *str;
    LOG_TRACE("(%p, %p, %p, %p, \"%s\")", pF, pF1, pF2, pF3, pS);

    (void)pF;
    (void)pF1;
    (void)pF2;
    (void)pF3;
    (void)pS;
    (void)s;
    (void)str;

    if (function_hook_state_GetThreeIntsAndAString == HOOK_ENABLED) {
        assert(0 && "GetThreeIntsAndAString not implemented.");
        abort();
    } else {
        original_GetThreeIntsAndAString(pF, pF1, pF2, pF3, pS);
    }
}

function_hook_state_t function_hook_state_GetFourInts = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(GetFourInts, function_hook_state_GetFourInts)
static void(__cdecl*original_GetFourInts)(FILE *, int *, int *, int *, int *) = (void(__cdecl*)(FILE *, int *, int *, int *, int *))0x00425c85;
CARM95_HOOK_FUNCTION(original_GetFourInts, GetFourInts)
void __cdecl GetFourInts(FILE *pF, int *pF1, int *pF2, int *pF3, int *pF4) {
    char s[256];
    char *str;
    LOG_TRACE("(%p, %p, %p, %p, %p)", pF, pF1, pF2, pF3, pF4);

    (void)pF;
    (void)pF1;
    (void)pF2;
    (void)pF3;
    (void)pF4;
    (void)s;
    (void)str;

    if (function_hook_state_GetFourInts == HOOK_ENABLED) {
        assert(0 && "GetFourInts not implemented.");
        abort();
    } else {
        original_GetFourInts(pF, pF1, pF2, pF3, pF4);
    }
}

function_hook_state_t function_hook_state_GetAScalar = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(GetAScalar, function_hook_state_GetAScalar)
static br_scalar(__cdecl*original_GetAScalar)(FILE *) = (br_scalar(__cdecl*)(FILE *))0x00425d4a;
CARM95_HOOK_FUNCTION(original_GetAScalar, GetAScalar)
br_scalar __cdecl GetAScalar(FILE *pF) {
    LOG_TRACE("(%p)", pF);

    (void)pF;

    if (function_hook_state_GetAScalar == HOOK_ENABLED) {
        assert(0 && "GetAScalar not implemented.");
        abort();
    } else {
        return original_GetAScalar(pF);
    }
}

function_hook_state_t function_hook_state_GetPairOfScalars = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(GetPairOfScalars, function_hook_state_GetPairOfScalars)
static void(__cdecl*original_GetPairOfScalars)(FILE *, br_scalar *, br_scalar *) = (void(__cdecl*)(FILE *, br_scalar *, br_scalar *))0x00425d66;
CARM95_HOOK_FUNCTION(original_GetPairOfScalars, GetPairOfScalars)
void __cdecl GetPairOfScalars(FILE *pF, br_scalar *pS1, br_scalar *pS2) {
    float __block0__x_0;
    float __block0__x_1;
    LOG_TRACE("(%p, %p, %p)", pF, pS1, pS2);

    (void)pF;
    (void)pS1;
    (void)pS2;
    (void)__block0__x_0;
    (void)__block0__x_1;

    if (function_hook_state_GetPairOfScalars == HOOK_ENABLED) {
        assert(0 && "GetPairOfScalars not implemented.");
        abort();
    } else {
        original_GetPairOfScalars(pF, pS1, pS2);
    }
}

function_hook_state_t function_hook_state_GetThreeScalars = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(GetThreeScalars, function_hook_state_GetThreeScalars)
static void(__cdecl*original_GetThreeScalars)(FILE *, br_scalar *, br_scalar *, br_scalar *) = (void(__cdecl*)(FILE *, br_scalar *, br_scalar *, br_scalar *))0x00425d98;
CARM95_HOOK_FUNCTION(original_GetThreeScalars, GetThreeScalars)
void __cdecl GetThreeScalars(FILE *pF, br_scalar *pS1, br_scalar *pS2, br_scalar *pS3) {
    float __block0__x_0;
    float __block0__x_1;
    float __block0__x_2;
    LOG_TRACE("(%p, %p, %p, %p)", pF, pS1, pS2, pS3);

    (void)pF;
    (void)pS1;
    (void)pS2;
    (void)pS3;
    (void)__block0__x_0;
    (void)__block0__x_1;
    (void)__block0__x_2;

    if (function_hook_state_GetThreeScalars == HOOK_ENABLED) {
        assert(0 && "GetThreeScalars not implemented.");
        abort();
    } else {
        original_GetThreeScalars(pF, pS1, pS2, pS3);
    }
}

function_hook_state_t function_hook_state_GetFourScalars = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(GetFourScalars, function_hook_state_GetFourScalars)
static void(__cdecl*original_GetFourScalars)(FILE *, br_scalar *, br_scalar *, br_scalar *, br_scalar *) = (void(__cdecl*)(FILE *, br_scalar *, br_scalar *, br_scalar *, br_scalar *))0x00425dd6;
CARM95_HOOK_FUNCTION(original_GetFourScalars, GetFourScalars)
void __cdecl GetFourScalars(FILE *pF, br_scalar *pF1, br_scalar *pF2, br_scalar *pF3, br_scalar *pF4) {
    char s[256];
    char *str;
    float f1;
    float f2;
    float f3;
    float f4;
    LOG_TRACE("(%p, %p, %p, %p, %p)", pF, pF1, pF2, pF3, pF4);

    (void)pF;
    (void)pF1;
    (void)pF2;
    (void)pF3;
    (void)pF4;
    (void)s;
    (void)str;
    (void)f1;
    (void)f2;
    (void)f3;
    (void)f4;

    if (function_hook_state_GetFourScalars == HOOK_ENABLED) {
        assert(0 && "GetFourScalars not implemented.");
        abort();
    } else {
        original_GetFourScalars(pF, pF1, pF2, pF3, pF4);
    }
}

function_hook_state_t function_hook_state_GetFiveScalars = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(GetFiveScalars, function_hook_state_GetFiveScalars)
static void(__cdecl*original_GetFiveScalars)(FILE *, br_scalar *, br_scalar *, br_scalar *, br_scalar *, br_scalar *) = (void(__cdecl*)(FILE *, br_scalar *, br_scalar *, br_scalar *, br_scalar *, br_scalar *))0x00425ec1;
CARM95_HOOK_FUNCTION(original_GetFiveScalars, GetFiveScalars)
void __cdecl GetFiveScalars(FILE *pF, br_scalar *pF1, br_scalar *pF2, br_scalar *pF3, br_scalar *pF4, br_scalar *pF5) {
    char s[256];
    char *str;
    float f1;
    float f2;
    float f3;
    float f4;
    float f5;
    LOG_TRACE("(%p, %p, %p, %p, %p, %p)", pF, pF1, pF2, pF3, pF4, pF5);

    (void)pF;
    (void)pF1;
    (void)pF2;
    (void)pF3;
    (void)pF4;
    (void)pF5;
    (void)s;
    (void)str;
    (void)f1;
    (void)f2;
    (void)f3;
    (void)f4;
    (void)f5;

    if (function_hook_state_GetFiveScalars == HOOK_ENABLED) {
        assert(0 && "GetFiveScalars not implemented.");
        abort();
    } else {
        original_GetFiveScalars(pF, pF1, pF2, pF3, pF4, pF5);
    }
}

function_hook_state_t function_hook_state_GetNScalars = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(GetNScalars, function_hook_state_GetNScalars)
static void(__cdecl*original_GetNScalars)(FILE *, int, br_scalar *) = (void(__cdecl*)(FILE *, int, br_scalar *))0x00425fdb;
CARM95_HOOK_FUNCTION(original_GetNScalars, GetNScalars)
void __cdecl GetNScalars(FILE *pF, int pNumber, br_scalar *pScalars) {
    char s[256];
    char *str;
    float fleurting_point_numero;
    int i;
    LOG_TRACE("(%p, %d, %p)", pF, pNumber, pScalars);

    (void)pF;
    (void)pNumber;
    (void)pScalars;
    (void)s;
    (void)str;
    (void)fleurting_point_numero;
    (void)i;

    if (function_hook_state_GetNScalars == HOOK_ENABLED) {
        assert(0 && "GetNScalars not implemented.");
        abort();
    } else {
        original_GetNScalars(pF, pNumber, pScalars);
    }
}

function_hook_state_t function_hook_state_GetPairOfFloatPercents = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(GetPairOfFloatPercents, function_hook_state_GetPairOfFloatPercents)
static void(__cdecl*original_GetPairOfFloatPercents)(FILE *, float *, float *) = (void(__cdecl*)(FILE *, float *, float *))0x0042607b;
CARM95_HOOK_FUNCTION(original_GetPairOfFloatPercents, GetPairOfFloatPercents)
void __cdecl GetPairOfFloatPercents(FILE *pF, float *pF1, float *pF2) {
    char s[256];
    char *str;
    LOG_TRACE("(%p, %p, %p)", pF, pF1, pF2);

    (void)pF;
    (void)pF1;
    (void)pF2;
    (void)s;
    (void)str;

    if (function_hook_state_GetPairOfFloatPercents == HOOK_ENABLED) {
        assert(0 && "GetPairOfFloatPercents not implemented.");
        abort();
    } else {
        original_GetPairOfFloatPercents(pF, pF1, pF2);
    }
}

function_hook_state_t function_hook_state_GetThreeFloatPercents = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(GetThreeFloatPercents, function_hook_state_GetThreeFloatPercents)
static void(__cdecl*original_GetThreeFloatPercents)(FILE *, float *, float *, float *) = (void(__cdecl*)(FILE *, float *, float *, float *))0x00426112;
CARM95_HOOK_FUNCTION(original_GetThreeFloatPercents, GetThreeFloatPercents)
void __cdecl GetThreeFloatPercents(FILE *pF, float *pF1, float *pF2, float *pF3) {
    char s[256];
    char *str;
    LOG_TRACE("(%p, %p, %p, %p)", pF, pF1, pF2, pF3);

    (void)pF;
    (void)pF1;
    (void)pF2;
    (void)pF3;
    (void)s;
    (void)str;

    if (function_hook_state_GetThreeFloatPercents == HOOK_ENABLED) {
        assert(0 && "GetThreeFloatPercents not implemented.");
        abort();
    } else {
        original_GetThreeFloatPercents(pF, pF1, pF2, pF3);
    }
}

function_hook_state_t function_hook_state_GetAString = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(GetAString, function_hook_state_GetAString)
static void(__cdecl*original_GetAString)(FILE *, char *) = (void(__cdecl*)(FILE *, char *))0x004261e0;
CARM95_HOOK_FUNCTION(original_GetAString, GetAString)
void __cdecl GetAString(FILE *pF, char *pString) {
    char s[256];
    char *str;
    LOG_TRACE("(%p, \"%s\")", pF, pString);

    (void)pF;
    (void)pString;
    (void)s;
    (void)str;

    if (function_hook_state_GetAString == HOOK_ENABLED) {
        assert(0 && "GetAString not implemented.");
        abort();
    } else {
        original_GetAString(pF, pString);
    }
}

function_hook_state_t function_hook_state_AboutToLoadFirstCar = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(AboutToLoadFirstCar, function_hook_state_AboutToLoadFirstCar)
static void(__cdecl*original_AboutToLoadFirstCar)() = (void(__cdecl*)())0x00426240;
CARM95_HOOK_FUNCTION(original_AboutToLoadFirstCar, AboutToLoadFirstCar)
void __cdecl AboutToLoadFirstCar() {
    LOG_TRACE("()");


    if (function_hook_state_AboutToLoadFirstCar == HOOK_ENABLED) {
        assert(0 && "AboutToLoadFirstCar not implemented.");
        abort();
    } else {
        original_AboutToLoadFirstCar();
    }
}

function_hook_state_t function_hook_state_LoadOpponentsCars = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(LoadOpponentsCars, function_hook_state_LoadOpponentsCars)
static void(__cdecl*original_LoadOpponentsCars)(tRace_info *) = (void(__cdecl*)(tRace_info *))0x0042625a;
CARM95_HOOK_FUNCTION(original_LoadOpponentsCars, LoadOpponentsCars)
void __cdecl LoadOpponentsCars(tRace_info *pRace_info) {
    int i;
    LOG_TRACE("(%p)", pRace_info);

    (void)pRace_info;
    (void)i;

    if (function_hook_state_LoadOpponentsCars == HOOK_ENABLED) {
        assert(0 && "LoadOpponentsCars not implemented.");
        abort();
    } else {
        original_LoadOpponentsCars(pRace_info);
    }
}

function_hook_state_t function_hook_state_DisposeOpponentsCars = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(DisposeOpponentsCars, function_hook_state_DisposeOpponentsCars)
static void(__cdecl*original_DisposeOpponentsCars)(tRace_info *) = (void(__cdecl*)(tRace_info *))0x00426359;
CARM95_HOOK_FUNCTION(original_DisposeOpponentsCars, DisposeOpponentsCars)
void __cdecl DisposeOpponentsCars(tRace_info *pRace_info) {
    int i;
    LOG_TRACE("(%p)", pRace_info);

    (void)pRace_info;
    (void)i;

    if (function_hook_state_DisposeOpponentsCars == HOOK_ENABLED) {
        assert(0 && "DisposeOpponentsCars not implemented.");
        abort();
    } else {
        original_DisposeOpponentsCars(pRace_info);
    }
}

function_hook_state_t function_hook_state_LoadMiscStrings = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(LoadMiscStrings, function_hook_state_LoadMiscStrings)
static void(__cdecl*original_LoadMiscStrings)() = (void(__cdecl*)())0x00426410;
CARM95_HOOK_FUNCTION(original_LoadMiscStrings, LoadMiscStrings)
void __cdecl LoadMiscStrings() {
    int i;
    FILE *f;
    char s[256];
    tPath_name the_path;
    LOG_TRACE("()");

    (void)i;
    (void)f;
    (void)s;
    (void)the_path;

    if (function_hook_state_LoadMiscStrings == HOOK_ENABLED) {
        assert(0 && "LoadMiscStrings not implemented.");
        abort();
    } else {
        original_LoadMiscStrings();
    }
}

function_hook_state_t function_hook_state_FillInRaceInfo = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(FillInRaceInfo, function_hook_state_FillInRaceInfo)
static void(__cdecl*original_FillInRaceInfo)(tRace_info *) = (void(__cdecl*)(tRace_info *))0x0042652d;
CARM95_HOOK_FUNCTION(original_FillInRaceInfo, FillInRaceInfo)
void __cdecl FillInRaceInfo(tRace_info *pThe_race) {
    LOG_TRACE("(%p)", pThe_race);

    (void)pThe_race;

    if (function_hook_state_FillInRaceInfo == HOOK_ENABLED) {
        assert(0 && "FillInRaceInfo not implemented.");
        abort();
    } else {
        original_FillInRaceInfo(pThe_race);
    }
}

function_hook_state_t function_hook_state_OldDRfopen = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(OldDRfopen, function_hook_state_OldDRfopen)
static FILE *(__cdecl*original_OldDRfopen)(char *, char *) = (FILE *(__cdecl*)(char *, char *))0x00426654;
CARM95_HOOK_FUNCTION(original_OldDRfopen, OldDRfopen)
FILE* __cdecl OldDRfopen(char *pFilename, char *pMode) {
    FILE *fp;
    FILE *file_ptr;
    FILE *test1;
    FILE *test2;
    char *data_dir;
    tPath_name CD_dir;
    tPath_name path_file;
    tPath_name source_check;
    static int source_exists;
    int len;
    char __block0__ch;
    LOG_TRACE("(\"%s\", \"%s\")", pFilename, pMode);

    (void)pFilename;
    (void)pMode;
    (void)fp;
    (void)file_ptr;
    (void)test1;
    (void)test2;
    (void)data_dir;
    (void)CD_dir;
    (void)path_file;
    (void)source_check;
    (void)source_exists;
    (void)len;
    (void)__block0__ch;

    if (function_hook_state_OldDRfopen == HOOK_ENABLED) {
        assert(0 && "OldDRfopen not implemented.");
        abort();
    } else {
        return original_OldDRfopen(pFilename, pMode);
    }
}

function_hook_state_t function_hook_state_AllowOpenToFail = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(AllowOpenToFail, function_hook_state_AllowOpenToFail)
static void(__cdecl*original_AllowOpenToFail)() = (void(__cdecl*)())0x00426563;
CARM95_HOOK_FUNCTION(original_AllowOpenToFail, AllowOpenToFail)
void __cdecl AllowOpenToFail() {
    LOG_TRACE("()");


    if (function_hook_state_AllowOpenToFail == HOOK_ENABLED) {
        assert(0 && "AllowOpenToFail not implemented.");
        abort();
    } else {
        original_AllowOpenToFail();
    }
}

function_hook_state_t function_hook_state_DoNotAllowOpenToFail = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(DoNotAllowOpenToFail, function_hook_state_DoNotAllowOpenToFail)
void DoNotAllowOpenToFail() {
    LOG_TRACE("()");


    if (function_hook_state_DoNotAllowOpenToFail == HOOK_ENABLED) {
        assert(0 && "DoNotAllowOpenToFail not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}

function_hook_state_t function_hook_state_DRfopen = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(DRfopen, function_hook_state_DRfopen)
static FILE *(__cdecl*original_DRfopen)(char *, char *) = (FILE *(__cdecl*)(char *, char *))0x00426583;
CARM95_HOOK_FUNCTION(original_DRfopen, DRfopen)
FILE* __cdecl DRfopen(char *pFilename, char *pMode) {
    FILE *result;
    tPath_name CD_dir;
    char msg[336];
    LOG_TRACE("(\"%s\", \"%s\")", pFilename, pMode);

    (void)pFilename;
    (void)pMode;
    (void)result;
    (void)CD_dir;
    (void)msg;

    if (function_hook_state_DRfopen == HOOK_ENABLED) {
        assert(0 && "DRfopen not implemented.");
        abort();
    } else {
        return original_DRfopen(pFilename, pMode);
    }
}

function_hook_state_t function_hook_state_GetCDPathFromPathsTxtFile = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(GetCDPathFromPathsTxtFile, function_hook_state_GetCDPathFromPathsTxtFile)
static int(__cdecl*original_GetCDPathFromPathsTxtFile)(char *) = (int(__cdecl*)(char *))0x00426cc5;
CARM95_HOOK_FUNCTION(original_GetCDPathFromPathsTxtFile, GetCDPathFromPathsTxtFile)
int __cdecl GetCDPathFromPathsTxtFile(char *pPath_name) {
    static int got_it_already;
    static tPath_name cd_pathname;
    FILE *paths_txt_fp;
    tPath_name paths_txt;
    LOG_TRACE("(\"%s\")", pPath_name);

    (void)pPath_name;
    (void)got_it_already;
    (void)cd_pathname;
    (void)paths_txt_fp;
    (void)paths_txt;

    if (function_hook_state_GetCDPathFromPathsTxtFile == HOOK_ENABLED) {
        assert(0 && "GetCDPathFromPathsTxtFile not implemented.");
        abort();
    } else {
        return original_GetCDPathFromPathsTxtFile(pPath_name);
    }
}

function_hook_state_t function_hook_state_TestForOriginalCarmaCDinDrive = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(TestForOriginalCarmaCDinDrive, function_hook_state_TestForOriginalCarmaCDinDrive)
int TestForOriginalCarmaCDinDrive() {
    LOG_TRACE("()");


    if (function_hook_state_TestForOriginalCarmaCDinDrive == HOOK_ENABLED) {
        assert(0 && "TestForOriginalCarmaCDinDrive not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}

function_hook_state_t function_hook_state_OriginalCarmaCDinDrive = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(OriginalCarmaCDinDrive, function_hook_state_OriginalCarmaCDinDrive)
static int(__cdecl*original_OriginalCarmaCDinDrive)() = (int(__cdecl*)())0x00427158;
CARM95_HOOK_FUNCTION(original_OriginalCarmaCDinDrive, OriginalCarmaCDinDrive)
int __cdecl OriginalCarmaCDinDrive() {
    LOG_TRACE("()");


    if (function_hook_state_OriginalCarmaCDinDrive == HOOK_ENABLED) {
        return 1;
    } else {
        return original_OriginalCarmaCDinDrive();
    }
}

function_hook_state_t function_hook_state_CarmaCDinDriveOrFullGameInstalled = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(CarmaCDinDriveOrFullGameInstalled, function_hook_state_CarmaCDinDriveOrFullGameInstalled)
static int(__cdecl*original_CarmaCDinDriveOrFullGameInstalled)() = (int(__cdecl*)())0x0042716d;
CARM95_HOOK_FUNCTION(original_CarmaCDinDriveOrFullGameInstalled, CarmaCDinDriveOrFullGameInstalled)
int __cdecl CarmaCDinDriveOrFullGameInstalled() {
    LOG_TRACE("()");


    if (function_hook_state_CarmaCDinDriveOrFullGameInstalled == HOOK_ENABLED) {
        assert(0 && "CarmaCDinDriveOrFullGameInstalled not implemented.");
        abort();
    } else {
        return original_CarmaCDinDriveOrFullGameInstalled();
    }
}

function_hook_state_t function_hook_state_ReadNetworkSettings = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(ReadNetworkSettings, function_hook_state_ReadNetworkSettings)
static void(__cdecl*original_ReadNetworkSettings)(FILE *, tNet_game_options *) = (void(__cdecl*)(FILE *, tNet_game_options *))0x00427199;
CARM95_HOOK_FUNCTION(original_ReadNetworkSettings, ReadNetworkSettings)
void __cdecl ReadNetworkSettings(FILE *pF, tNet_game_options *pOptions) {
    LOG_TRACE("(%p, %p)", pF, pOptions);

    (void)pF;
    (void)pOptions;

    if (function_hook_state_ReadNetworkSettings == HOOK_ENABLED) {
        assert(0 && "ReadNetworkSettings not implemented.");
        abort();
    } else {
        original_ReadNetworkSettings(pF, pOptions);
    }
}

function_hook_state_t function_hook_state_PrintNetOptions = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(PrintNetOptions, function_hook_state_PrintNetOptions)
static int(__cdecl*original_PrintNetOptions)(FILE *, int) = (int(__cdecl*)(FILE *, int))0x00427269;
CARM95_HOOK_FUNCTION(original_PrintNetOptions, PrintNetOptions)
int __cdecl PrintNetOptions(FILE *pF, int pIndex) {
    LOG_TRACE("(%p, %d)", pF, pIndex);

    (void)pF;
    (void)pIndex;

    if (function_hook_state_PrintNetOptions == HOOK_ENABLED) {
        assert(0 && "PrintNetOptions not implemented.");
        abort();
    } else {
        return original_PrintNetOptions(pF, pIndex);
    }
}

function_hook_state_t function_hook_state_SaveOptions = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(SaveOptions, function_hook_state_SaveOptions)
static int(__cdecl*original_SaveOptions)() = (int(__cdecl*)())0x004273e5;
CARM95_HOOK_FUNCTION(original_SaveOptions, SaveOptions)
int __cdecl SaveOptions() {
    tPath_name the_path;
    FILE *f;
    LOG_TRACE("()");

    (void)the_path;
    (void)f;

    if (function_hook_state_SaveOptions == HOOK_ENABLED) {
        assert(0 && "SaveOptions not implemented.");
        abort();
    } else {
        return original_SaveOptions();
    }
}

function_hook_state_t function_hook_state_RestoreOptions = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(RestoreOptions, function_hook_state_RestoreOptions)
static int(__cdecl*original_RestoreOptions)() = (int(__cdecl*)())0x004278be;
CARM95_HOOK_FUNCTION(original_RestoreOptions, RestoreOptions)
int __cdecl RestoreOptions() {
    tPath_name the_path;
    FILE *f;
    char line[80];
    char token[80];
    char *s;
    float arg;
    LOG_TRACE("()");

    (void)the_path;
    (void)f;
    (void)line;
    (void)token;
    (void)s;
    (void)arg;

    if (function_hook_state_RestoreOptions == HOOK_ENABLED) {
        assert(0 && "RestoreOptions not implemented.");
        abort();
    } else {
        return original_RestoreOptions();
    }
}

function_hook_state_t function_hook_state_InitFunkGrooveFlags = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(InitFunkGrooveFlags, function_hook_state_InitFunkGrooveFlags)
static void(__cdecl*original_InitFunkGrooveFlags)() = (void(__cdecl*)())0x00427e87;
CARM95_HOOK_FUNCTION(original_InitFunkGrooveFlags, InitFunkGrooveFlags)
void __cdecl InitFunkGrooveFlags() {
    int i;
    LOG_TRACE("()");

    (void)i;

    if (function_hook_state_InitFunkGrooveFlags == HOOK_ENABLED) {
        assert(0 && "InitFunkGrooveFlags not implemented.");
        abort();
    } else {
        original_InitFunkGrooveFlags();
    }
}

