#include "render.h"

#include "harness/trace.h"

#include "carm95_hooks.h"

#include "carm95_webserver.h"

#include <assert.h>

function_hook_state_t function_hook_state_BrDbModelRender = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(BrDbModelRender, function_hook_state_BrDbModelRender)
static void(__cdecl*original_BrDbModelRender)(br_actor *, br_model *, br_material *, void *, br_uint_8, int, int) = (void(__cdecl*)(br_actor *, br_model *, br_material *, void *, br_uint_8, int, int))0x004d9720;
CARM95_HOOK_FUNCTION(original_BrDbModelRender, BrDbModelRender)
void __cdecl BrDbModelRender(br_actor *actor, br_model *model, br_material *material, void *render_data, br_uint_8 style, int on_screen, int use_custom) {
    br_int_32 count;
    br_token_value tv[5];
    br_order_table *__block0__ot;
    br_int_32 __block1__c;
    char __block1__buffer[16];
    br_token_value __block1__tv[3];
    br_int_32 __block1__int_bounds[4];
    LOG_TRACE("(%p, %p, %p, %p, %u, %d, %d)", actor, model, material, render_data, style, on_screen, use_custom);

    (void)actor;
    (void)model;
    (void)material;
    (void)render_data;
    (void)style;
    (void)on_screen;
    (void)use_custom;
    (void)count;
    (void)tv;
    (void)__block0__ot;
    (void)__block1__c;
    (void)__block1__buffer;
    (void)__block1__tv;
    (void)__block1__int_bounds;

    if (function_hook_state_BrDbModelRender == HOOK_ENABLED) {
        assert(0 && "BrDbModelRender not implemented.");
        abort();
    } else {
        original_BrDbModelRender(actor, model, material, render_data, style, on_screen, use_custom);
    }
}

function_hook_state_t function_hook_state_BrOnScreenCheck = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(BrOnScreenCheck, function_hook_state_BrOnScreenCheck)
static br_uint_32(__cdecl*original_BrOnScreenCheck)(br_bounds3 *) = (br_uint_32(__cdecl*)(br_bounds3 *))0x004d9ab0;
CARM95_HOOK_FUNCTION(original_BrOnScreenCheck, BrOnScreenCheck)
br_uint_32 __cdecl BrOnScreenCheck(br_bounds3 *bounds) {
    br_token r;
    LOG_TRACE("(%p)", bounds);

    (void)bounds;
    (void)r;

    if (function_hook_state_BrOnScreenCheck == HOOK_ENABLED) {
        assert(0 && "BrOnScreenCheck not implemented.");
        abort();
    } else {
        return original_BrOnScreenCheck(bounds);
    }
}

function_hook_state_t function_hook_state_prependActorTransform = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(prependActorTransform, function_hook_state_prependActorTransform)
br_uint_16 prependActorTransform(br_actor *ap, br_uint_16 t) {
    br_matrix34 mt;
    LOG_TRACE("(%p, %u)", ap, t);

    (void)ap;
    (void)t;
    (void)mt;

    if (function_hook_state_prependActorTransform == HOOK_ENABLED) {
        assert(0 && "prependActorTransform not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}

function_hook_state_t function_hook_state_prependMatrix = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(prependMatrix, function_hook_state_prependMatrix)
br_uint_16 prependMatrix(br_matrix34 *mat, br_uint_16 mat_t, br_uint_16 t) {
    br_matrix34 mt;
    LOG_TRACE("(%p, %u, %u)", mat, mat_t, t);

    (void)mat;
    (void)mat_t;
    (void)t;
    (void)mt;

    if (function_hook_state_prependMatrix == HOOK_ENABLED) {
        assert(0 && "prependMatrix not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}

function_hook_state_t function_hook_state_actorRender = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(actorRender, function_hook_state_actorRender)
static void(__stdcall*original_actorRender)(br_actor *, br_model *, br_material *, void *, br_uint_8, br_uint_16) = (void(__stdcall*)(br_actor *, br_model *, br_material *, void *, br_uint_8, br_uint_16))0x004da0d0;
CARM95_HOOK_FUNCTION(original_actorRender, actorRender)
void __stdcall actorRender(br_actor *ap, br_model *model, br_material *material, void *render_data, br_uint_8 style, br_uint_16 t) {
    br_material *this_material;
    br_model *this_model;
    void *this_render_data;
    br_actor *a;
    br_token s;
    LOG_TRACE("(%p, %p, %p, %p, %u, %u)", ap, model, material, render_data, style, t);

    (void)ap;
    (void)model;
    (void)material;
    (void)render_data;
    (void)style;
    (void)t;
    (void)this_material;
    (void)this_model;
    (void)this_render_data;
    (void)a;
    (void)s;

    if (function_hook_state_actorRender == HOOK_ENABLED) {
        assert(0 && "actorRender not implemented.");
        abort();
    } else {
        original_actorRender(ap, model, material, render_data, style, t);
    }
}

function_hook_state_t function_hook_state_actorRenderOnScreen = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(actorRenderOnScreen, function_hook_state_actorRenderOnScreen)
void actorRenderOnScreen(br_actor *ap, br_model *model, br_material *material, void *render_data, br_uint_8 style, br_uint_16 t) {
    br_material *this_material;
    br_model *this_model;
    void *this_render_data;
    br_actor *a;
    LOG_TRACE("(%p, %p, %p, %p, %u, %u)", ap, model, material, render_data, style, t);

    (void)ap;
    (void)model;
    (void)material;
    (void)render_data;
    (void)style;
    (void)t;
    (void)this_material;
    (void)this_model;
    (void)this_render_data;
    (void)a;

    if (function_hook_state_actorRenderOnScreen == HOOK_ENABLED) {
        assert(0 && "actorRenderOnScreen not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}

function_hook_state_t function_hook_state_sceneRenderWorld = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(sceneRenderWorld, function_hook_state_sceneRenderWorld)
void sceneRenderWorld(br_actor *world) {
    br_model *model;
    br_material *material;
    void *render_data;
    br_uint_8 style;
    br_actor *a;
    LOG_TRACE("(%p)", world);

    (void)world;
    (void)model;
    (void)material;
    (void)render_data;
    (void)style;
    (void)a;

    if (function_hook_state_sceneRenderWorld == HOOK_ENABLED) {
        assert(0 && "sceneRenderWorld not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}

function_hook_state_t function_hook_state_sceneRenderAdd = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(sceneRenderAdd, function_hook_state_sceneRenderAdd)
static void(__stdcall*original_sceneRenderAdd)(br_actor *) = (void(__stdcall*)(br_actor *))0x004d9eb0;
CARM95_HOOK_FUNCTION(original_sceneRenderAdd, sceneRenderAdd)
void __stdcall sceneRenderAdd(br_actor *tree) {
    br_material *material;
    br_model *model;
    void *render_data;
    br_uint_8 style;
    br_actor *a;
    br_int_32 t;
    br_matrix34 m;
    LOG_TRACE("(%p)", tree);

    (void)tree;
    (void)material;
    (void)model;
    (void)render_data;
    (void)style;
    (void)a;
    (void)t;
    (void)m;

    if (function_hook_state_sceneRenderAdd == HOOK_ENABLED) {
        assert(0 && "sceneRenderAdd not implemented.");
        abort();
    } else {
        original_sceneRenderAdd(tree);
    }
}

function_hook_state_t function_hook_state_BrDbSceneRenderBegin = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(BrDbSceneRenderBegin, function_hook_state_BrDbSceneRenderBegin)
static void(__cdecl*original_BrDbSceneRenderBegin)(br_actor *, br_actor *) = (void(__cdecl*)(br_actor *, br_actor *))0x004d9ae0;
CARM95_HOOK_FUNCTION(original_BrDbSceneRenderBegin, BrDbSceneRenderBegin)
void __cdecl BrDbSceneRenderBegin(br_actor *world, br_actor *camera) {
    br_matrix34 tfm;
    br_matrix4 vtos;
    br_actor *a;
    int i;
    br_token vtos_type;
    br_uint_32 dummy;
    LOG_TRACE("(%p, %p)", world, camera);

    (void)world;
    (void)camera;
    (void)tfm;
    (void)vtos;
    (void)a;
    (void)i;
    (void)vtos_type;
    (void)dummy;

    if (function_hook_state_BrDbSceneRenderBegin == HOOK_ENABLED) {
        assert(0 && "BrDbSceneRenderBegin not implemented.");
        abort();
    } else {
        original_BrDbSceneRenderBegin(world, camera);
    }
}

function_hook_state_t function_hook_state_BrDbSetRenderBoundsCallback = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(BrDbSetRenderBoundsCallback, function_hook_state_BrDbSetRenderBoundsCallback)
static br_renderbounds_cbfn *(__cdecl*original_BrDbSetRenderBoundsCallback)(br_renderbounds_cbfn *) = (br_renderbounds_cbfn *(__cdecl*)(br_renderbounds_cbfn *))0x004d9cf0;
CARM95_HOOK_FUNCTION(original_BrDbSetRenderBoundsCallback, BrDbSetRenderBoundsCallback)
br_renderbounds_cbfn* __cdecl BrDbSetRenderBoundsCallback(br_renderbounds_cbfn *new_cbfn) {
    br_renderbounds_cbfn *old_cbfn;
    LOG_TRACE("(%p)", new_cbfn);

    (void)new_cbfn;
    (void)old_cbfn;

    if (function_hook_state_BrDbSetRenderBoundsCallback == HOOK_ENABLED) {
        assert(0 && "BrDbSetRenderBoundsCallback not implemented.");
        abort();
    } else {
        return original_BrDbSetRenderBoundsCallback(new_cbfn);
    }
}

function_hook_state_t function_hook_state_SetOrigin = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(SetOrigin, function_hook_state_SetOrigin)
void SetOrigin(br_pixelmap *buffer) {
    LOG_TRACE("(%p)", buffer);

    (void)buffer;

    if (function_hook_state_SetOrigin == HOOK_ENABLED) {
        assert(0 && "SetOrigin not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}

function_hook_state_t function_hook_state_SetViewport = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(SetViewport, function_hook_state_SetViewport)
void SetViewport(br_pixelmap *buffer) {
    LOG_TRACE("(%p)", buffer);

    (void)buffer;

    if (function_hook_state_SetViewport == HOOK_ENABLED) {
        assert(0 && "SetViewport not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}

function_hook_state_t function_hook_state_BrZbSceneRenderBegin = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(BrZbSceneRenderBegin, function_hook_state_BrZbSceneRenderBegin)
static void(__cdecl*original_BrZbSceneRenderBegin)(br_actor *, br_actor *, br_pixelmap *, br_pixelmap *) = (void(__cdecl*)(br_actor *, br_actor *, br_pixelmap *, br_pixelmap *))0x004d9d30;
CARM95_HOOK_FUNCTION(original_BrZbSceneRenderBegin, BrZbSceneRenderBegin)
void __cdecl BrZbSceneRenderBegin(br_actor *world, br_actor *camera, br_pixelmap *colour_buffer, br_pixelmap *depth_buffer) {
    LOG_TRACE("(%p, %p, %p, %p)", world, camera, colour_buffer, depth_buffer);

    (void)world;
    (void)camera;
    (void)colour_buffer;
    (void)depth_buffer;

    if (function_hook_state_BrZbSceneRenderBegin == HOOK_ENABLED) {
        assert(0 && "BrZbSceneRenderBegin not implemented.");
        abort();
    } else {
        original_BrZbSceneRenderBegin(world, camera, colour_buffer, depth_buffer);
    }
}

function_hook_state_t function_hook_state_BrZbSceneRenderAdd = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(BrZbSceneRenderAdd, function_hook_state_BrZbSceneRenderAdd)
static void(__cdecl*original_BrZbSceneRenderAdd)(br_actor *) = (void(__cdecl*)(br_actor *))0x004d9ea0;
CARM95_HOOK_FUNCTION(original_BrZbSceneRenderAdd, BrZbSceneRenderAdd)
void __cdecl BrZbSceneRenderAdd(br_actor *tree) {
    LOG_TRACE("(%p)", tree);

    (void)tree;

    if (function_hook_state_BrZbSceneRenderAdd == HOOK_ENABLED) {
        assert(0 && "BrZbSceneRenderAdd not implemented.");
        abort();
    } else {
        original_BrZbSceneRenderAdd(tree);
    }
}

function_hook_state_t function_hook_state_BrZbSceneRenderEnd = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(BrZbSceneRenderEnd, function_hook_state_BrZbSceneRenderEnd)
static void(__cdecl*original_BrZbSceneRenderEnd)() = (void(__cdecl*)())0x004da630;
CARM95_HOOK_FUNCTION(original_BrZbSceneRenderEnd, BrZbSceneRenderEnd)
void __cdecl BrZbSceneRenderEnd() {
    LOG_TRACE("()");


    if (function_hook_state_BrZbSceneRenderEnd == HOOK_ENABLED) {
        assert(0 && "BrZbSceneRenderEnd not implemented.");
        abort();
    } else {
        original_BrZbSceneRenderEnd();
    }
}

function_hook_state_t function_hook_state_BrZbSceneRender = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(BrZbSceneRender, function_hook_state_BrZbSceneRender)
static void(__cdecl*original_BrZbSceneRender)(br_actor *, br_actor *, br_pixelmap *, br_pixelmap *) = (void(__cdecl*)(br_actor *, br_actor *, br_pixelmap *, br_pixelmap *))0x004da660;
CARM95_HOOK_FUNCTION(original_BrZbSceneRender, BrZbSceneRender)
void __cdecl BrZbSceneRender(br_actor *world, br_actor *camera, br_pixelmap *colour_buffer, br_pixelmap *depth_buffer) {
    br_actor *a;
    LOG_TRACE("(%p, %p, %p, %p)", world, camera, colour_buffer, depth_buffer);

    (void)world;
    (void)camera;
    (void)colour_buffer;
    (void)depth_buffer;
    (void)a;

    if (function_hook_state_BrZbSceneRender == HOOK_ENABLED) {
        assert(0 && "BrZbSceneRender not implemented.");
        abort();
    } else {
        original_BrZbSceneRender(world, camera, colour_buffer, depth_buffer);
    }
}

function_hook_state_t function_hook_state_BrZsSceneRenderBegin = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(BrZsSceneRenderBegin, function_hook_state_BrZsSceneRenderBegin)
static void(__cdecl*original_BrZsSceneRenderBegin)(br_actor *, br_actor *, br_pixelmap *) = (void(__cdecl*)(br_actor *, br_actor *, br_pixelmap *))0x004da860;
CARM95_HOOK_FUNCTION(original_BrZsSceneRenderBegin, BrZsSceneRenderBegin)
void __cdecl BrZsSceneRenderBegin(br_actor *world, br_actor *camera, br_pixelmap *colour_buffer) {
    br_camera *camera_data;
    LOG_TRACE("(%p, %p, %p)", world, camera, colour_buffer);

    (void)world;
    (void)camera;
    (void)colour_buffer;
    (void)camera_data;

    if (function_hook_state_BrZsSceneRenderBegin == HOOK_ENABLED) {
        assert(0 && "BrZsSceneRenderBegin not implemented.");
        abort();
    } else {
        original_BrZsSceneRenderBegin(world, camera, colour_buffer);
    }
}

function_hook_state_t function_hook_state_BrZsSceneRenderAdd = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(BrZsSceneRenderAdd, function_hook_state_BrZsSceneRenderAdd)
static void(__cdecl*original_BrZsSceneRenderAdd)(br_actor *) = (void(__cdecl*)(br_actor *))0x004daa4c;
CARM95_HOOK_FUNCTION(original_BrZsSceneRenderAdd, BrZsSceneRenderAdd)
void __cdecl BrZsSceneRenderAdd(br_actor *tree) {
    LOG_TRACE("(%p)", tree);

    (void)tree;

    if (function_hook_state_BrZsSceneRenderAdd == HOOK_ENABLED) {
        assert(0 && "BrZsSceneRenderAdd not implemented.");
        abort();
    } else {
        original_BrZsSceneRenderAdd(tree);
    }
}

function_hook_state_t function_hook_state_BrZsSceneRenderEnd = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(BrZsSceneRenderEnd, function_hook_state_BrZsSceneRenderEnd)
static void(__cdecl*original_BrZsSceneRenderEnd)() = (void(__cdecl*)())0x004daa5b;
CARM95_HOOK_FUNCTION(original_BrZsSceneRenderEnd, BrZsSceneRenderEnd)
void __cdecl BrZsSceneRenderEnd() {
    LOG_TRACE("()");


    if (function_hook_state_BrZsSceneRenderEnd == HOOK_ENABLED) {
        assert(0 && "BrZsSceneRenderEnd not implemented.");
        abort();
    } else {
        original_BrZsSceneRenderEnd();
    }
}

function_hook_state_t function_hook_state_BrZsSceneRender = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(BrZsSceneRender, function_hook_state_BrZsSceneRender)
static void(__stdcall*original_BrZsSceneRender)(br_actor *, br_actor *, br_pixelmap *) = (void(__stdcall*)(br_actor *, br_actor *, br_pixelmap *))0x004daae0;
CARM95_HOOK_FUNCTION(original_BrZsSceneRender, BrZsSceneRender)
void __stdcall BrZsSceneRender(br_actor *world, br_actor *camera, br_pixelmap *colour_buffer) {
    br_actor *a;
    LOG_TRACE("(%p, %p, %p)", world, camera, colour_buffer);

    (void)world;
    (void)camera;
    (void)colour_buffer;
    (void)a;

    if (function_hook_state_BrZsSceneRender == HOOK_ENABLED) {
        assert(0 && "BrZsSceneRender not implemented.");
        abort();
    } else {
        original_BrZsSceneRender(world, camera, colour_buffer);
    }
}

function_hook_state_t function_hook_state_BrZsPrimitiveCallbackSet = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(BrZsPrimitiveCallbackSet, function_hook_state_BrZsPrimitiveCallbackSet)
static br_primitive_cbfn *(__cdecl*original_BrZsPrimitiveCallbackSet)(br_primitive_cbfn *) = (br_primitive_cbfn *(__cdecl*)(br_primitive_cbfn *))0x004dabe0;
CARM95_HOOK_FUNCTION(original_BrZsPrimitiveCallbackSet, BrZsPrimitiveCallbackSet)
br_primitive_cbfn* __cdecl BrZsPrimitiveCallbackSet(br_primitive_cbfn *new_cbfn) {
    br_primitive_cbfn *old_cbfn;
    LOG_TRACE("(%p)", new_cbfn);

    (void)new_cbfn;
    (void)old_cbfn;

    if (function_hook_state_BrZsPrimitiveCallbackSet == HOOK_ENABLED) {
        assert(0 && "BrZsPrimitiveCallbackSet not implemented.");
        abort();
    } else {
        return original_BrZsPrimitiveCallbackSet(new_cbfn);
    }
}

function_hook_state_t function_hook_state_BrZbModelRender = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(BrZbModelRender, function_hook_state_BrZbModelRender)
static void(__cdecl*original_BrZbModelRender)(br_actor *, br_model *, br_material *, br_uint_8, int, int) = (void(__cdecl*)(br_actor *, br_model *, br_material *, br_uint_8, int, int))0x004dabf0;
CARM95_HOOK_FUNCTION(original_BrZbModelRender, BrZbModelRender)
void __cdecl BrZbModelRender(br_actor *actor, br_model *model, br_material *material, br_uint_8 style, int on_screen, int use_custom) {
    LOG_TRACE("(%p, %p, %p, %u, %d, %d)", actor, model, material, style, on_screen, use_custom);

    (void)actor;
    (void)model;
    (void)material;
    (void)style;
    (void)on_screen;
    (void)use_custom;

    if (function_hook_state_BrZbModelRender == HOOK_ENABLED) {
        assert(0 && "BrZbModelRender not implemented.");
        abort();
    } else {
        original_BrZbModelRender(actor, model, material, style, on_screen, use_custom);
    }
}

function_hook_state_t function_hook_state_BrZsModelRender = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(BrZsModelRender, function_hook_state_BrZsModelRender)
static void(__cdecl*original_BrZsModelRender)(br_actor *, br_model *, br_material *, br_order_table *, br_uint_8, int, int) = (void(__cdecl*)(br_actor *, br_model *, br_material *, br_order_table *, br_uint_8, int, int))0x004dac19;
CARM95_HOOK_FUNCTION(original_BrZsModelRender, BrZsModelRender)
void __cdecl BrZsModelRender(br_actor *actor, br_model *model, br_material *material, br_order_table *order_table, br_uint_8 style, int on_screen, int use_custom) {
    LOG_TRACE("(%p, %p, %p, %p, %u, %d, %d)", actor, model, material, order_table, style, on_screen, use_custom);

    (void)actor;
    (void)model;
    (void)material;
    (void)order_table;
    (void)style;
    (void)on_screen;
    (void)use_custom;

    if (function_hook_state_BrZsModelRender == HOOK_ENABLED) {
        assert(0 && "BrZsModelRender not implemented.");
        abort();
    } else {
        original_BrZsModelRender(actor, model, material, order_table, style, on_screen, use_custom);
    }
}

function_hook_state_t function_hook_state_BrZbRenderBoundsCallbackSet = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(BrZbRenderBoundsCallbackSet, function_hook_state_BrZbRenderBoundsCallbackSet)
static br_renderbounds_cbfn *(__cdecl*original_BrZbRenderBoundsCallbackSet)(br_renderbounds_cbfn *) = (br_renderbounds_cbfn *(__cdecl*)(br_renderbounds_cbfn *))0x004dac4c;
CARM95_HOOK_FUNCTION(original_BrZbRenderBoundsCallbackSet, BrZbRenderBoundsCallbackSet)
br_renderbounds_cbfn* __cdecl BrZbRenderBoundsCallbackSet(br_renderbounds_cbfn *new_cbfn) {
    LOG_TRACE("(%p)", new_cbfn);

    (void)new_cbfn;

    if (function_hook_state_BrZbRenderBoundsCallbackSet == HOOK_ENABLED) {
        assert(0 && "BrZbRenderBoundsCallbackSet not implemented.");
        abort();
    } else {
        return original_BrZbRenderBoundsCallbackSet(new_cbfn);
    }
}

function_hook_state_t function_hook_state_BrZsRenderBoundsCallbackSet = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(BrZsRenderBoundsCallbackSet, function_hook_state_BrZsRenderBoundsCallbackSet)
static br_renderbounds_cbfn *(__cdecl*original_BrZsRenderBoundsCallbackSet)(br_renderbounds_cbfn *) = (br_renderbounds_cbfn *(__cdecl*)(br_renderbounds_cbfn *))0x004dacb0;
CARM95_HOOK_FUNCTION(original_BrZsRenderBoundsCallbackSet, BrZsRenderBoundsCallbackSet)
br_renderbounds_cbfn* __cdecl BrZsRenderBoundsCallbackSet(br_renderbounds_cbfn *new_cbfn) {
    LOG_TRACE("(%p)", new_cbfn);

    (void)new_cbfn;

    if (function_hook_state_BrZsRenderBoundsCallbackSet == HOOK_ENABLED) {
        assert(0 && "BrZsRenderBoundsCallbackSet not implemented.");
        abort();
    } else {
        return original_BrZsRenderBoundsCallbackSet(new_cbfn);
    }
}

