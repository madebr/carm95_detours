#include "regsupt.h"

#include "harness/trace.h"

#include "carm95_hooks.h"

#include <stdio.h>

static br_model *(*original_BrModelAdd)(br_model *, ...) = (br_model *(*)(br_model *, ...))0x004d5de0;
CARM95_HOOK_FUNCTION(original_BrModelAdd, BrModelAdd)
br_model* BrModelAdd(br_model *model) {
    LOG_TRACE("(%p)", model);

    (void)model;

    return original_BrModelAdd(model);
}

static br_model *(*original_BrModelRemove)(br_model *, ...) = (br_model *(*)(br_model *, ...))0x004d5e10;
CARM95_HOOK_FUNCTION(original_BrModelRemove, BrModelRemove)
br_model* BrModelRemove(br_model *model) {
    LOG_TRACE("(%p)", model);

    (void)model;

    return original_BrModelRemove(model);
}

static br_model *(*original_BrModelFind)(char *, ...) = (br_model *(*)(char *, ...))0x004d5e28;
CARM95_HOOK_FUNCTION(original_BrModelFind, BrModelFind)
br_model* BrModelFind(char *pattern) {
    LOG_TRACE("(\"%s\")", pattern);

    (void)pattern;

    return original_BrModelFind(pattern);
}

static br_model_find_cbfn *(*original_BrModelFindHook)(br_model_find_cbfn *, ...) = (br_model_find_cbfn *(*)(br_model_find_cbfn *, ...))0x004d5e40;
CARM95_HOOK_FUNCTION(original_BrModelFindHook, BrModelFindHook)
br_model_find_cbfn* BrModelFindHook(br_model_find_cbfn *hook) {
    br_model_find_cbfn *old;
    LOG_TRACE("(%p)", hook);

    (void)hook;
    (void)old;

    return original_BrModelFindHook(hook);
}

static br_uint_32(*original_BrModelAddMany)(br_model **, int, ...) = (br_uint_32(*)(br_model **, int, ...))0x004d5e50;
CARM95_HOOK_FUNCTION(original_BrModelAddMany, BrModelAddMany)
br_uint_32 BrModelAddMany(br_model **items, int n) {
    int i;
    int r;
    LOG_TRACE("(%p, %d)", items, n);

    (void)items;
    (void)n;
    (void)i;
    (void)r;

    return original_BrModelAddMany(items, n);
}

static br_uint_32(*original_BrModelRemoveMany)(br_model **, int, ...) = (br_uint_32(*)(br_model **, int, ...))0x004d5ea0;
CARM95_HOOK_FUNCTION(original_BrModelRemoveMany, BrModelRemoveMany)
br_uint_32 BrModelRemoveMany(br_model **items, int n) {
    int i;
    int r;
    LOG_TRACE("(%p, %d)", items, n);

    (void)items;
    (void)n;
    (void)i;
    (void)r;

    return original_BrModelRemoveMany(items, n);
}

static br_uint_32(*original_BrModelFindMany)(char *, br_model **, int, ...) = (br_uint_32(*)(char *, br_model **, int, ...))0x004d5ee0;
CARM95_HOOK_FUNCTION(original_BrModelFindMany, BrModelFindMany)
br_uint_32 BrModelFindMany(char *pattern, br_model **items, int max) {
    LOG_TRACE("(\"%s\", %p, %d)", pattern, items, max);

    (void)pattern;
    (void)items;
    (void)max;

    return original_BrModelFindMany(pattern, items, max);
}

static br_uint_32(*original_BrModelCount)(char *, ...) = (br_uint_32(*)(char *, ...))0x004d5f00;
CARM95_HOOK_FUNCTION(original_BrModelCount, BrModelCount)
br_uint_32 BrModelCount(char *pattern) {
    LOG_TRACE("(\"%s\")", pattern);

    (void)pattern;

    return original_BrModelCount(pattern);
}

static br_uint_32(*original_BrModelEnum)(char *, br_model_enum_cbfn *, void *, ...) = (br_uint_32(*)(char *, br_model_enum_cbfn *, void *, ...))0x004d5f10;
CARM95_HOOK_FUNCTION(original_BrModelEnum, BrModelEnum)
br_uint_32 BrModelEnum(char *pattern, br_model_enum_cbfn *callback, void *arg) {
    LOG_TRACE("(\"%s\", %p, %p)", pattern, callback, arg);

    (void)pattern;
    (void)callback;
    (void)arg;

    return original_BrModelEnum(pattern, callback, arg);
}

static br_material *(*original_BrMaterialAdd)(br_material *, ...) = (br_material *(*)(br_material *, ...))0x004d5f30;
CARM95_HOOK_FUNCTION(original_BrMaterialAdd, BrMaterialAdd)
br_material* BrMaterialAdd(br_material *material) {
    LOG_TRACE("(%p)", material);

    (void)material;

    return original_BrMaterialAdd(material);
}

static br_material *(*original_BrMaterialRemove)(br_material *, ...) = (br_material *(*)(br_material *, ...))0x004d5f60;
CARM95_HOOK_FUNCTION(original_BrMaterialRemove, BrMaterialRemove)
br_material* BrMaterialRemove(br_material *material) {
    LOG_TRACE("(%p)", material);

    (void)material;

    return original_BrMaterialRemove(material);
}

static br_material *(*original_BrMaterialFind)(char *, ...) = (br_material *(*)(char *, ...))0x004d5f80;
CARM95_HOOK_FUNCTION(original_BrMaterialFind, BrMaterialFind)
br_material* BrMaterialFind(char *pattern) {
    LOG_TRACE("(\"%s\")", pattern);

    (void)pattern;

    return original_BrMaterialFind(pattern);
}

static br_material_find_cbfn *(*original_BrMaterialFindHook)(br_material_find_cbfn *, ...) = (br_material_find_cbfn *(*)(br_material_find_cbfn *, ...))0x004d5f90;
CARM95_HOOK_FUNCTION(original_BrMaterialFindHook, BrMaterialFindHook)
br_material_find_cbfn* BrMaterialFindHook(br_material_find_cbfn *hook) {
    br_material_find_cbfn *old;
    LOG_TRACE("(%p)", hook);

    (void)hook;
    (void)old;

    return original_BrMaterialFindHook(hook);
}

static br_uint_32(*original_BrMaterialAddMany)(br_material **, int, ...) = (br_uint_32(*)(br_material **, int, ...))0x004d5fa0;
CARM95_HOOK_FUNCTION(original_BrMaterialAddMany, BrMaterialAddMany)
br_uint_32 BrMaterialAddMany(br_material **items, int n) {
    int i;
    int r;
    LOG_TRACE("(%p, %d)", items, n);

    (void)items;
    (void)n;
    (void)i;
    (void)r;

    return original_BrMaterialAddMany(items, n);
}

static br_uint_32(*original_BrMaterialRemoveMany)(br_material **, int, ...) = (br_uint_32(*)(br_material **, int, ...))0x004d5ff0;
CARM95_HOOK_FUNCTION(original_BrMaterialRemoveMany, BrMaterialRemoveMany)
br_uint_32 BrMaterialRemoveMany(br_material **items, int n) {
    int i;
    int r;
    LOG_TRACE("(%p, %d)", items, n);

    (void)items;
    (void)n;
    (void)i;
    (void)r;

    return original_BrMaterialRemoveMany(items, n);
}

static br_uint_32(*original_BrMaterialFindMany)(char *, br_material **, int, ...) = (br_uint_32(*)(char *, br_material **, int, ...))0x004d603c;
CARM95_HOOK_FUNCTION(original_BrMaterialFindMany, BrMaterialFindMany)
br_uint_32 BrMaterialFindMany(char *pattern, br_material **items, int max) {
    LOG_TRACE("(\"%s\", %p, %d)", pattern, items, max);

    (void)pattern;
    (void)items;
    (void)max;

    return original_BrMaterialFindMany(pattern, items, max);
}

static br_uint_32(*original_BrMaterialCount)(char *, ...) = (br_uint_32(*)(char *, ...))0x004d6050;
CARM95_HOOK_FUNCTION(original_BrMaterialCount, BrMaterialCount)
br_uint_32 BrMaterialCount(char *pattern) {
    LOG_TRACE("(\"%s\")", pattern);

    (void)pattern;

    return original_BrMaterialCount(pattern);
}

static br_uint_32(*original_BrMaterialEnum)(char *, br_material_enum_cbfn *, void *, ...) = (br_uint_32(*)(char *, br_material_enum_cbfn *, void *, ...))0x004d6060;
CARM95_HOOK_FUNCTION(original_BrMaterialEnum, BrMaterialEnum)
br_uint_32 BrMaterialEnum(char *pattern, br_material_enum_cbfn *callback, void *arg) {
    LOG_TRACE("(\"%s\", %p, %p)", pattern, callback, arg);

    (void)pattern;
    (void)callback;
    (void)arg;

    return original_BrMaterialEnum(pattern, callback, arg);
}

static br_pixelmap *(*original_BrMapAdd)(br_pixelmap *, ...) = (br_pixelmap *(*)(br_pixelmap *, ...))0x004d6080;
CARM95_HOOK_FUNCTION(original_BrMapAdd, BrMapAdd)
br_pixelmap* BrMapAdd(br_pixelmap *pixelmap) {
    LOG_TRACE("(%p)", pixelmap);

    (void)pixelmap;

    return original_BrMapAdd(pixelmap);
}

static br_pixelmap *(*original_BrMapRemove)(br_pixelmap *, ...) = (br_pixelmap *(*)(br_pixelmap *, ...))0x004d60b0;
CARM95_HOOK_FUNCTION(original_BrMapRemove, BrMapRemove)
br_pixelmap* BrMapRemove(br_pixelmap *pixelmap) {
    LOG_TRACE("(%p)", pixelmap);

    (void)pixelmap;

    return original_BrMapRemove(pixelmap);
}

static br_pixelmap *(*original_BrMapFind)(char *, ...) = (br_pixelmap *(*)(char *, ...))0x004d60d0;
CARM95_HOOK_FUNCTION(original_BrMapFind, BrMapFind)
br_pixelmap* BrMapFind(char *pattern) {
    LOG_TRACE("(\"%s\")", pattern);

    (void)pattern;

    return original_BrMapFind(pattern);
}

static br_map_find_cbfn *(*original_BrMapFindHook)(br_map_find_cbfn *, ...) = (br_map_find_cbfn *(*)(br_map_find_cbfn *, ...))0x004d60e0;
CARM95_HOOK_FUNCTION(original_BrMapFindHook, BrMapFindHook)
br_map_find_cbfn* BrMapFindHook(br_map_find_cbfn *hook) {
    br_map_find_cbfn *old;
    LOG_TRACE("(%p)", hook);

    (void)hook;
    (void)old;

    return original_BrMapFindHook(hook);
}

static br_uint_32(*original_BrMapAddMany)(br_pixelmap **, int, ...) = (br_uint_32(*)(br_pixelmap **, int, ...))0x004d60f0;
CARM95_HOOK_FUNCTION(original_BrMapAddMany, BrMapAddMany)
br_uint_32 BrMapAddMany(br_pixelmap **items, int n) {
    int i;
    int r;
    LOG_TRACE("(%p, %d)", items, n);

    (void)items;
    (void)n;
    (void)i;
    (void)r;

    return original_BrMapAddMany(items, n);
}

static br_uint_32(*original_BrMapRemoveMany)(br_pixelmap **, int, ...) = (br_uint_32(*)(br_pixelmap **, int, ...))0x004d6140;
CARM95_HOOK_FUNCTION(original_BrMapRemoveMany, BrMapRemoveMany)
br_uint_32 BrMapRemoveMany(br_pixelmap **items, int n) {
    int i;
    int r;
    LOG_TRACE("(%p, %d)", items, n);

    (void)items;
    (void)n;
    (void)i;
    (void)r;

    return original_BrMapRemoveMany(items, n);
}

static br_uint_32(*original_BrMapFindMany)(char *, br_pixelmap **, int, ...) = (br_uint_32(*)(char *, br_pixelmap **, int, ...))0x004d618c;
CARM95_HOOK_FUNCTION(original_BrMapFindMany, BrMapFindMany)
br_uint_32 BrMapFindMany(char *pattern, br_pixelmap **items, int max) {
    LOG_TRACE("(\"%s\", %p, %d)", pattern, items, max);

    (void)pattern;
    (void)items;
    (void)max;

    return original_BrMapFindMany(pattern, items, max);
}

static br_uint_32(*original_BrMapCount)(char *, ...) = (br_uint_32(*)(char *, ...))0x004d61a4;
CARM95_HOOK_FUNCTION(original_BrMapCount, BrMapCount)
br_uint_32 BrMapCount(char *pattern) {
    LOG_TRACE("(\"%s\")", pattern);

    (void)pattern;

    return original_BrMapCount(pattern);
}

static br_uint_32(*original_BrMapEnum)(char *, br_map_enum_cbfn *, void *, ...) = (br_uint_32(*)(char *, br_map_enum_cbfn *, void *, ...))0x004d61b0;
CARM95_HOOK_FUNCTION(original_BrMapEnum, BrMapEnum)
br_uint_32 BrMapEnum(char *pattern, br_map_enum_cbfn *callback, void *arg) {
    LOG_TRACE("(\"%s\", %p, %p)", pattern, callback, arg);

    (void)pattern;
    (void)callback;
    (void)arg;

    return original_BrMapEnum(pattern, callback, arg);
}

static br_pixelmap *(*original_BrTableAdd)(br_pixelmap *, ...) = (br_pixelmap *(*)(br_pixelmap *, ...))0x004d61d0;
CARM95_HOOK_FUNCTION(original_BrTableAdd, BrTableAdd)
br_pixelmap* BrTableAdd(br_pixelmap *pixelmap) {
    LOG_TRACE("(%p)", pixelmap);

    (void)pixelmap;

    return original_BrTableAdd(pixelmap);
}

static br_pixelmap *(*original_BrTableRemove)(br_pixelmap *, ...) = (br_pixelmap *(*)(br_pixelmap *, ...))0x004d6200;
CARM95_HOOK_FUNCTION(original_BrTableRemove, BrTableRemove)
br_pixelmap* BrTableRemove(br_pixelmap *pixelmap) {
    LOG_TRACE("(%p)", pixelmap);

    (void)pixelmap;

    return original_BrTableRemove(pixelmap);
}

static br_pixelmap *(*original_BrTableFind)(char *, ...) = (br_pixelmap *(*)(char *, ...))0x004d6220;
CARM95_HOOK_FUNCTION(original_BrTableFind, BrTableFind)
br_pixelmap* BrTableFind(char *pattern) {
    LOG_TRACE("(\"%s\")", pattern);

    (void)pattern;

    return original_BrTableFind(pattern);
}

static br_table_find_cbfn *(*original_BrTableFindHook)(br_table_find_cbfn *, ...) = (br_table_find_cbfn *(*)(br_table_find_cbfn *, ...))0x004d6230;
CARM95_HOOK_FUNCTION(original_BrTableFindHook, BrTableFindHook)
br_table_find_cbfn* BrTableFindHook(br_table_find_cbfn *hook) {
    br_table_find_cbfn *old;
    LOG_TRACE("(%p)", hook);

    (void)hook;
    (void)old;

    return original_BrTableFindHook(hook);
}

static br_uint_32(*original_BrTableAddMany)(br_pixelmap **, int, ...) = (br_uint_32(*)(br_pixelmap **, int, ...))0x004d6240;
CARM95_HOOK_FUNCTION(original_BrTableAddMany, BrTableAddMany)
br_uint_32 BrTableAddMany(br_pixelmap **items, int n) {
    int i;
    int r;
    LOG_TRACE("(%p, %d)", items, n);

    (void)items;
    (void)n;
    (void)i;
    (void)r;

    return original_BrTableAddMany(items, n);
}

static br_uint_32(*original_BrTableRemoveMany)(br_pixelmap **, int, ...) = (br_uint_32(*)(br_pixelmap **, int, ...))0x004d6281;
CARM95_HOOK_FUNCTION(original_BrTableRemoveMany, BrTableRemoveMany)
br_uint_32 BrTableRemoveMany(br_pixelmap **items, int n) {
    int i;
    int r;
    LOG_TRACE("(%p, %d)", items, n);

    (void)items;
    (void)n;
    (void)i;
    (void)r;

    return original_BrTableRemoveMany(items, n);
}

static br_uint_32(*original_BrTableFindMany)(char *, br_pixelmap **, int, ...) = (br_uint_32(*)(char *, br_pixelmap **, int, ...))0x004d62c9;
CARM95_HOOK_FUNCTION(original_BrTableFindMany, BrTableFindMany)
br_uint_32 BrTableFindMany(char *pattern, br_pixelmap **items, int max) {
    LOG_TRACE("(\"%s\", %p, %d)", pattern, items, max);

    (void)pattern;
    (void)items;
    (void)max;

    return original_BrTableFindMany(pattern, items, max);
}

static br_uint_32(*original_BrTableCount)(char *, ...) = (br_uint_32(*)(char *, ...))0x004d62ea;
CARM95_HOOK_FUNCTION(original_BrTableCount, BrTableCount)
br_uint_32 BrTableCount(char *pattern) {
    LOG_TRACE("(\"%s\")", pattern);

    (void)pattern;

    return original_BrTableCount(pattern);
}

static br_uint_32(*original_BrTableEnum)(char *, br_table_enum_cbfn *, void *, ...) = (br_uint_32(*)(char *, br_table_enum_cbfn *, void *, ...))0x004d6300;
CARM95_HOOK_FUNCTION(original_BrTableEnum, BrTableEnum)
br_uint_32 BrTableEnum(char *pattern, br_table_enum_cbfn *callback, void *arg) {
    LOG_TRACE("(\"%s\", %p, %p)", pattern, callback, arg);

    (void)pattern;
    (void)callback;
    (void)arg;

    return original_BrTableEnum(pattern, callback, arg);
}

