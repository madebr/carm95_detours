#ifndef _OTABLE_H_
#define _OTABLE_H_

#include "br_types.h"


br_order_table* __cdecl BrZsOrderTableAllocate(br_uint_16 size, br_uint_32 flags, br_uint_16 type);

void __cdecl BrZsOrderTableFree(br_order_table *order_table);

br_order_table* __cdecl BrZsActorOrderTableSet(br_actor *actor, br_order_table *order_table);

br_order_table* __cdecl BrZsActorOrderTableGet(br_actor *actor);

br_order_table* __cdecl BrZsOrderTableClear(br_order_table *order_table);

void __cdecl BrZsOrderTablePrimitiveInsert(br_order_table *order_table, br_primitive *primitive, br_uint_16 bucket);

br_uint_16 __cdecl BrZsPrimitiveBucketSelect(br_scalar *z, br_uint_16 type, br_scalar min_z, br_scalar max_z, br_uint_16 size, br_uint_16 sort_type);

void __cdecl BrZsOrderTablePrimaryEnable(br_order_table *order_table);

void __cdecl BrZsOrderTablePrimaryDisable();

void __stdcall InsertOrderTableList(br_order_table *order_table);

void __stdcall SetOrderTableBounds(br_bounds *bounds, br_order_table *order_table);

void __stdcall SetOrderTableRange(br_order_table *order_table);

void __cdecl RenderOrderTableList();

void __cdecl RenderPrimaryOrderTable();

#endif
