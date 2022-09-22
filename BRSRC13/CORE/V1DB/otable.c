#include "otable.h"

#include "harness/trace.h"

#include "carm95_hooks.h"


static br_order_table *(__cdecl*original_BrZsOrderTableAllocate)(br_uint_16, br_uint_32, br_uint_16) = (br_order_table *(__cdecl*)(br_uint_16, br_uint_32, br_uint_16))0x004ddda0;
CARM95_HOOK_FUNCTION(original_BrZsOrderTableAllocate, BrZsOrderTableAllocate)
br_order_table* __cdecl BrZsOrderTableAllocate(br_uint_16 size, br_uint_32 flags, br_uint_16 type) {
    br_order_table *order_table;
    LOG_TRACE("(%u, %u, %u)", size, flags, type);

    (void)size;
    (void)flags;
    (void)type;
    (void)order_table;

    return original_BrZsOrderTableAllocate(size, flags, type);
}

static void(__cdecl*original_BrZsOrderTableFree)(br_order_table *) = (void(__cdecl*)(br_order_table *))0x004dde10;
CARM95_HOOK_FUNCTION(original_BrZsOrderTableFree, BrZsOrderTableFree)
void __cdecl BrZsOrderTableFree(br_order_table *order_table) {
    LOG_TRACE("(%p)", order_table);

    (void)order_table;

    original_BrZsOrderTableFree(order_table);
}

static br_order_table *(__cdecl*original_BrZsActorOrderTableSet)(br_actor *, br_order_table *) = (br_order_table *(__cdecl*)(br_actor *, br_order_table *))0x004dde20;
CARM95_HOOK_FUNCTION(original_BrZsActorOrderTableSet, BrZsActorOrderTableSet)
br_order_table* __cdecl BrZsActorOrderTableSet(br_actor *actor, br_order_table *order_table) {
    LOG_TRACE("(%p, %p)", actor, order_table);

    (void)actor;
    (void)order_table;

    return original_BrZsActorOrderTableSet(actor, order_table);
}

static br_order_table *(__cdecl*original_BrZsActorOrderTableGet)(br_actor *) = (br_order_table *(__cdecl*)(br_actor *))0x004dde30;
CARM95_HOOK_FUNCTION(original_BrZsActorOrderTableGet, BrZsActorOrderTableGet)
br_order_table* __cdecl BrZsActorOrderTableGet(br_actor *actor) {
    LOG_TRACE("(%p)", actor);

    (void)actor;

    return original_BrZsActorOrderTableGet(actor);
}

static br_order_table *(__cdecl*original_BrZsOrderTableClear)(br_order_table *) = (br_order_table *(__cdecl*)(br_order_table *))0x004dde40;
CARM95_HOOK_FUNCTION(original_BrZsOrderTableClear, BrZsOrderTableClear)
br_order_table* __cdecl BrZsOrderTableClear(br_order_table *order_table) {
    LOG_TRACE("(%p)", order_table);

    (void)order_table;

    return original_BrZsOrderTableClear(order_table);
}

static void(__cdecl*original_BrZsOrderTablePrimitiveInsert)(br_order_table *, br_primitive *, br_uint_16) = (void(__cdecl*)(br_order_table *, br_primitive *, br_uint_16))0x004dde60;
CARM95_HOOK_FUNCTION(original_BrZsOrderTablePrimitiveInsert, BrZsOrderTablePrimitiveInsert)
void __cdecl BrZsOrderTablePrimitiveInsert(br_order_table *order_table, br_primitive *primitive, br_uint_16 bucket) {
    LOG_TRACE("(%p, %p, %u)", order_table, primitive, bucket);

    (void)order_table;
    (void)primitive;
    (void)bucket;

    original_BrZsOrderTablePrimitiveInsert(order_table, primitive, bucket);
}

static br_uint_16(__cdecl*original_BrZsPrimitiveBucketSelect)(br_scalar *, br_uint_16, br_scalar, br_scalar, br_uint_16, br_uint_16) = (br_uint_16(__cdecl*)(br_scalar *, br_uint_16, br_scalar, br_scalar, br_uint_16, br_uint_16))0x004dde90;
CARM95_HOOK_FUNCTION(original_BrZsPrimitiveBucketSelect, BrZsPrimitiveBucketSelect)
br_uint_16 __cdecl BrZsPrimitiveBucketSelect(br_scalar *z, br_uint_16 type, br_scalar min_z, br_scalar max_z, br_uint_16 size, br_uint_16 sort_type) {
    br_uint_16 bucket;
    br_scalar zprim;
    br_scalar range;
    br_scalar scale;
    LOG_TRACE("(%p, %u, %f, %f, %u, %u)", z, type, min_z, max_z, size, sort_type);

    (void)z;
    (void)type;
    (void)min_z;
    (void)max_z;
    (void)size;
    (void)sort_type;
    (void)bucket;
    (void)zprim;
    (void)range;
    (void)scale;

    return original_BrZsPrimitiveBucketSelect(z, type, min_z, max_z, size, sort_type);
}

static void(__cdecl*original_BrZsOrderTablePrimaryEnable)(br_order_table *) = (void(__cdecl*)(br_order_table *))0x004de050;
CARM95_HOOK_FUNCTION(original_BrZsOrderTablePrimaryEnable, BrZsOrderTablePrimaryEnable)
void __cdecl BrZsOrderTablePrimaryEnable(br_order_table *order_table) {
    LOG_TRACE("(%p)", order_table);

    (void)order_table;

    original_BrZsOrderTablePrimaryEnable(order_table);
}

static void(__stdcall*original_BrZsOrderTablePrimaryDisable)() = (void(__stdcall*)())0x004de070;
CARM95_HOOK_FUNCTION(original_BrZsOrderTablePrimaryDisable, BrZsOrderTablePrimaryDisable)
void __stdcall BrZsOrderTablePrimaryDisable() {
    LOG_TRACE("()");


    original_BrZsOrderTablePrimaryDisable();
}

static void(__stdcall*original_InsertOrderTableList)(br_order_table *) = (void(__stdcall*)(br_order_table *))0x004de080;
CARM95_HOOK_FUNCTION(original_InsertOrderTableList, InsertOrderTableList)
void __stdcall InsertOrderTableList(br_order_table *order_table) {
    br_order_table *previous_table;
    br_order_table *current_table;
    LOG_TRACE("(%p)", order_table);

    (void)order_table;
    (void)previous_table;
    (void)current_table;

    original_InsertOrderTableList(order_table);
}

static void(__stdcall*original_SetOrderTableBounds)(br_bounds *, br_order_table *) = (void(__stdcall*)(br_bounds *, br_order_table *))0x004de0f0;
CARM95_HOOK_FUNCTION(original_SetOrderTableBounds, SetOrderTableBounds)
void __stdcall SetOrderTableBounds(br_bounds *bounds, br_order_table *order_table) {
    br_uint_32 i;
    br_scalar range;
    br_scalar element;
    br_scalar min_z;
    br_scalar max_z;
    br_vector3 *min;
    br_vector3 *max;
    LOG_TRACE("(%p, %p)", bounds, order_table);

    (void)bounds;
    (void)order_table;
    (void)i;
    (void)range;
    (void)element;
    (void)min_z;
    (void)max_z;
    (void)min;
    (void)max;

    original_SetOrderTableBounds(bounds, order_table);
}

static void(__stdcall*original_SetOrderTableRange)(br_order_table *) = (void(__stdcall*)(br_order_table *))0x004de200;
CARM95_HOOK_FUNCTION(original_SetOrderTableRange, SetOrderTableRange)
void __stdcall SetOrderTableRange(br_order_table *order_table) {
    br_scalar range;
    LOG_TRACE("(%p)", order_table);

    (void)order_table;
    (void)range;

    original_SetOrderTableRange(order_table);
}

static void(__stdcall*original_RenderOrderTableList)() = (void(__stdcall*)())0x004de270;
CARM95_HOOK_FUNCTION(original_RenderOrderTableList, RenderOrderTableList)
void __stdcall RenderOrderTableList() {
    br_order_table *order_table;
    LOG_TRACE("()");

    (void)order_table;

    original_RenderOrderTableList();
}

static void(__stdcall*original_RenderPrimaryOrderTable)() = (void(__stdcall*)())0x004de2b0;
CARM95_HOOK_FUNCTION(original_RenderPrimaryOrderTable, RenderPrimaryOrderTable)
void __stdcall RenderPrimaryOrderTable() {
    br_uint_16 m;
    br_uint_16 size;
    br_scalar bucket_size;
    br_scalar min_z;
    br_scalar max_z;
    br_primitive *prim;
    br_primitive **bucket;
    br_order_table *order_table;
    LOG_TRACE("()");

    (void)m;
    (void)size;
    (void)bucket_size;
    (void)min_z;
    (void)max_z;
    (void)prim;
    (void)bucket;
    (void)order_table;

    original_RenderPrimaryOrderTable();
}

