#include "dbsetup.h"

#include "harness/trace.h"

#include "carm95_hooks.h"

 // Suffix added to avoid duplicate symbol
#if 0
br_resource_class(* hookvar_resourceClasses__dbsetup )[14];
#endif
br_v1db_state * hookvar_v1db  = (void*)0x00552100;

static br_error(__cdecl*original_BrV1dbBegin)() = (br_error(__cdecl*)())0x004dc9d0;
CARM95_HOOK_FUNCTION(original_BrV1dbBegin, BrV1dbBegin)
br_error __cdecl BrV1dbBegin() {
    int i;
    char *devstr;
    br_size_t s;
    LOG_TRACE("()");

    (void)i;
    (void)devstr;
    (void)s;

    return original_BrV1dbBegin();
}

static br_error(__cdecl*original_BrV1dbEnd)() = (br_error(__cdecl*)())0x004dcade;
CARM95_HOOK_FUNCTION(original_BrV1dbEnd, BrV1dbEnd)
br_error __cdecl BrV1dbEnd() {
    br_device *dev;
    LOG_TRACE("()");

    (void)dev;

    return original_BrV1dbEnd();
}

static br_uint_32(__cdecl*original_updateTable)(br_pixelmap *, void *) = (br_uint_32(__cdecl*)(br_pixelmap *, void *))0x004dcc90;
CARM95_HOOK_FUNCTION(original_updateTable, updateTable)
br_uint_32 __cdecl updateTable(br_pixelmap *item, void *arg) {
    LOG_TRACE("(%p, %p)", item, arg);

    (void)item;
    (void)arg;

    return original_updateTable(item, arg);
}

static br_uint_32(__cdecl*original_updateMap)(br_pixelmap *, void *) = (br_uint_32(__cdecl*)(br_pixelmap *, void *))0x004dccb0;
CARM95_HOOK_FUNCTION(original_updateMap, updateMap)
br_uint_32 __cdecl updateMap(br_pixelmap *item, void *arg) {
    LOG_TRACE("(%p, %p)", item, arg);

    (void)item;
    (void)arg;

    return original_updateMap(item, arg);
}

static br_uint_32(__cdecl*original_updateMaterial)(br_material *, void *) = (br_uint_32(__cdecl*)(br_material *, void *))0x004dccd0;
CARM95_HOOK_FUNCTION(original_updateMaterial, updateMaterial)
br_uint_32 __cdecl updateMaterial(br_material *item, void *arg) {
    LOG_TRACE("(%p, %p)", item, arg);

    (void)item;
    (void)arg;

    return original_updateMaterial(item, arg);
}

br_uint_32 updateModel(br_model *item, void *arg) {
    LOG_TRACE("(%p, %p)", item, arg);

    (void)item;
    (void)arg;

    NOT_IMPLEMENTED();
}

static br_uint_32(__cdecl*original_clearTable)(br_pixelmap *, void *) = (br_uint_32(__cdecl*)(br_pixelmap *, void *))0x004dcda0;
CARM95_HOOK_FUNCTION(original_clearTable, clearTable)
br_uint_32 __cdecl clearTable(br_pixelmap *item, void *arg) {
    LOG_TRACE("(%p, %p)", item, arg);

    (void)item;
    (void)arg;

    return original_clearTable(item, arg);
}

static br_uint_32(__cdecl*original_clearMap)(br_pixelmap *, void *) = (br_uint_32(__cdecl*)(br_pixelmap *, void *))0x004dcdb0;
CARM95_HOOK_FUNCTION(original_clearMap, clearMap)
br_uint_32 __cdecl clearMap(br_pixelmap *item, void *arg) {
    LOG_TRACE("(%p, %p)", item, arg);

    (void)item;
    (void)arg;

    return original_clearMap(item, arg);
}

static br_uint_32(__cdecl*original_clearMaterial)(br_material *, void *) = (br_uint_32(__cdecl*)(br_material *, void *))0x004dcdc0;
CARM95_HOOK_FUNCTION(original_clearMaterial, clearMaterial)
br_uint_32 __cdecl clearMaterial(br_material *item, void *arg) {
    LOG_TRACE("(%p, %p)", item, arg);

    (void)item;
    (void)arg;

    return original_clearMaterial(item, arg);
}

static br_uint_32(__cdecl*original_clearModel)(br_model *, void *) = (br_uint_32(__cdecl*)(br_model *, void *))0x004dcdd0;
CARM95_HOOK_FUNCTION(original_clearModel, clearModel)
br_uint_32 __cdecl clearModel(br_model *item, void *arg) {
    LOG_TRACE("(%p, %p)", item, arg);

    (void)item;
    (void)arg;

    return original_clearModel(item, arg);
}

static br_error(__cdecl*original_BrV1dbRendererBegin)(br_device_pixelmap *, br_renderer *) = (br_error(__cdecl*)(br_device_pixelmap *, br_renderer *))0x004dcb20;
CARM95_HOOK_FUNCTION(original_BrV1dbRendererBegin, BrV1dbRendererBegin)
br_error __cdecl BrV1dbRendererBegin(br_device_pixelmap *destination, br_renderer *renderer) {
    br_renderer_facility *renderer_facility;
    br_error r;
    br_token_value tv[2];
    LOG_TRACE("(%p, %p)", destination, renderer);

    (void)destination;
    (void)renderer;
    (void)renderer_facility;
    (void)r;
    (void)tv;

    return original_BrV1dbRendererBegin(destination, renderer);
}

static br_renderer *(__cdecl*original_BrV1dbRendererQuery)() = (br_renderer *(__cdecl*)())0x004dccf0;
CARM95_HOOK_FUNCTION(original_BrV1dbRendererQuery, BrV1dbRendererQuery)
br_renderer* __cdecl BrV1dbRendererQuery() {
    LOG_TRACE("()");


    return original_BrV1dbRendererQuery();
}

static br_error(__cdecl*original_BrV1dbRendererEnd)() = (br_error(__cdecl*)())0x004dcd00;
CARM95_HOOK_FUNCTION(original_BrV1dbRendererEnd, BrV1dbRendererEnd)
br_error __cdecl BrV1dbRendererEnd() {
    LOG_TRACE("()");


    return original_BrV1dbRendererEnd();
}

static void(__cdecl*original_BrZbBegin)(br_uint_8, br_uint_8) = (void(__cdecl*)(br_uint_8, br_uint_8))0x004dcde0;
CARM95_HOOK_FUNCTION(original_BrZbBegin, BrZbBegin)
void __cdecl BrZbBegin(br_uint_8 colour_type, br_uint_8 depth_type) {
    LOG_TRACE("(%u, %u)", colour_type, depth_type);

    (void)colour_type;
    (void)depth_type;

    original_BrZbBegin(colour_type, depth_type);
}

static void(__cdecl*original_BrZsBegin)(br_uint_8, void *, br_uint_32) = (void(__cdecl*)(br_uint_8, void *, br_uint_32))0x004dce20;
CARM95_HOOK_FUNCTION(original_BrZsBegin, BrZsBegin)
void __cdecl BrZsBegin(br_uint_8 colour_type, void *primitive, br_uint_32 size) {
    LOG_TRACE("(%u, %p, %u)", colour_type, primitive, size);

    (void)colour_type;
    (void)primitive;
    (void)size;

    original_BrZsBegin(colour_type, primitive, size);
}

static void(__cdecl*original_BrZbEnd)() = (void(__cdecl*)())0x004dce80;
CARM95_HOOK_FUNCTION(original_BrZbEnd, BrZbEnd)
void __cdecl BrZbEnd() {
    LOG_TRACE("()");


    original_BrZbEnd();
}

static void(__cdecl*original_BrZsEnd)() = (void(__cdecl*)())0x004dcf30;
CARM95_HOOK_FUNCTION(original_BrZsEnd, BrZsEnd)
void __cdecl BrZsEnd() {
    LOG_TRACE("()");


    original_BrZsEnd();
}

void BrV1dbBeginWrapper_Float() {
    LOG_TRACE("()");


    NOT_IMPLEMENTED();
}

static void(__cdecl*original_BrV1dbEndWrapper)() = (void(__cdecl*)())0x004dcfea;
CARM95_HOOK_FUNCTION(original_BrV1dbEndWrapper, BrV1dbEndWrapper)
void __cdecl BrV1dbEndWrapper() {
    LOG_TRACE("()");


    original_BrV1dbEndWrapper();
}

