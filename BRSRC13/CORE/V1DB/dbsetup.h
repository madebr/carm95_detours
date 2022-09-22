#ifndef _DBSETUP_H_
#define _DBSETUP_H_

#include "br_types.h"

// extern br_resource_class(* hookvar_resourceClasses__dbsetup )[14]; // suffix added to avoid duplicate symbol
extern br_v1db_state * hookvar_v1db ; // addr: 00552100

br_error __cdecl BrV1dbBegin();

br_error __cdecl BrV1dbEnd();

br_uint_32 __cdecl updateTable(br_pixelmap *item, void *arg);

br_uint_32 __cdecl updateMap(br_pixelmap *item, void *arg);

br_uint_32 __cdecl updateMaterial(br_material *item, void *arg);

br_uint_32 updateModel(br_model *item, void *arg);

br_uint_32 __cdecl clearTable(br_pixelmap *item, void *arg);

br_uint_32 __cdecl clearMap(br_pixelmap *item, void *arg);

br_uint_32 __cdecl clearMaterial(br_material *item, void *arg);

br_uint_32 __cdecl clearModel(br_model *item, void *arg);

br_error __cdecl BrV1dbRendererBegin(br_device_pixelmap *destination, br_renderer *renderer);

br_renderer* __cdecl BrV1dbRendererQuery();

br_error __cdecl BrV1dbRendererEnd();

void __cdecl BrZbBegin(br_uint_8 colour_type, br_uint_8 depth_type);

void __cdecl BrZsBegin(br_uint_8 colour_type, void *primitive, br_uint_32 size);

void __cdecl BrZbEnd();

void __cdecl BrZsEnd();

void BrV1dbBeginWrapper_Float();

void __cdecl BrV1dbEndWrapper();

#endif
