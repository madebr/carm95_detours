#ifndef _REGSUPT_H_
#define _REGSUPT_H_

#include "br_types.h"


br_model* __cdecl BrModelAdd(br_model *model);

br_model* __cdecl BrModelRemove(br_model *model);

br_model* __cdecl BrModelFind(char *pattern);

br_model_find_cbfn* __cdecl BrModelFindHook(br_model_find_cbfn *hook);

br_uint_32 __cdecl BrModelAddMany(br_model **items, int n);

br_uint_32 __cdecl BrModelRemoveMany(br_model **items, int n);

br_uint_32 __cdecl BrModelFindMany(char *pattern, br_model **items, int max);

br_uint_32 __cdecl BrModelCount(char *pattern);

br_uint_32 __cdecl BrModelEnum(char *pattern, br_model_enum_cbfn *callback, void *arg);

br_material* __cdecl BrMaterialAdd(br_material *material);

br_material* __cdecl BrMaterialRemove(br_material *material);

br_material* __cdecl BrMaterialFind(char *pattern);

br_material_find_cbfn* __cdecl BrMaterialFindHook(br_material_find_cbfn *hook);

br_uint_32 __cdecl BrMaterialAddMany(br_material **items, int n);

br_uint_32 __cdecl BrMaterialRemoveMany(br_material **items, int n);

br_uint_32 __fastcall BrMaterialFindMany(char *pattern, br_material **items, int max);

br_uint_32 __cdecl BrMaterialCount(char *pattern);

br_uint_32 __cdecl BrMaterialEnum(char *pattern, br_material_enum_cbfn *callback, void *arg);

br_pixelmap* __cdecl BrMapAdd(br_pixelmap *pixelmap);

br_pixelmap* __cdecl BrMapRemove(br_pixelmap *pixelmap);

br_pixelmap* __cdecl BrMapFind(char *pattern);

br_map_find_cbfn* __cdecl BrMapFindHook(br_map_find_cbfn *hook);

br_uint_32 __cdecl BrMapAddMany(br_pixelmap **items, int n);

br_uint_32 __cdecl BrMapRemoveMany(br_pixelmap **items, int n);

br_uint_32 __fastcall BrMapFindMany(char *pattern, br_pixelmap **items, int max);

br_uint_32 __stdcall BrMapCount(char *pattern);

br_uint_32 __cdecl BrMapEnum(char *pattern, br_map_enum_cbfn *callback, void *arg);

br_pixelmap* __cdecl BrTableAdd(br_pixelmap *pixelmap);

br_pixelmap* __cdecl BrTableRemove(br_pixelmap *pixelmap);

br_pixelmap* __cdecl BrTableFind(char *pattern);

br_table_find_cbfn* __cdecl BrTableFindHook(br_table_find_cbfn *hook);

br_uint_32 __cdecl BrTableAddMany(br_pixelmap **items, int n);

br_uint_32 __cdecl BrTableRemoveMany(br_pixelmap **items, int n);

br_uint_32 __cdecl BrTableFindMany(char *pattern, br_pixelmap **items, int max);

br_uint_32 __cdecl BrTableCount(char *pattern);

br_uint_32 __cdecl BrTableEnum(char *pattern, br_table_enum_cbfn *callback, void *arg);

#endif
