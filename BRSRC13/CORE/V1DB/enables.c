#include "enables.h"

#include "harness/trace.h"

#include "carm95_hooks.h"

#include "carm95_webserver.h"

#include <assert.h>

function_hook_state_t function_hook_state_actorEnable = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(actorEnable, function_hook_state_actorEnable)
void actorEnable(br_v1db_enable *e, br_actor *a) {
    int i;
    LOG_TRACE("(%p, %p)", e, a);

    (void)e;
    (void)a;
    (void)i;

    if (function_hook_state_actorEnable == HOOK_ENABLED) {
        assert(0 && "actorEnable not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}

function_hook_state_t function_hook_state_actorDisable = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(actorDisable, function_hook_state_actorDisable)
void actorDisable(br_v1db_enable *e, br_actor *a) {
    int i;
    LOG_TRACE("(%p, %p)", e, a);

    (void)e;
    (void)a;
    (void)i;

    if (function_hook_state_actorDisable == HOOK_ENABLED) {
        assert(0 && "actorDisable not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}

function_hook_state_t function_hook_state_BrLightEnable = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(BrLightEnable, function_hook_state_BrLightEnable)
static void(__cdecl*original_BrLightEnable)(br_actor *) = (void(__cdecl*)(br_actor *))0x004dd030;
CARM95_HOOK_FUNCTION(original_BrLightEnable, BrLightEnable)
void __cdecl BrLightEnable(br_actor *l) {
    LOG_TRACE("(%p)", l);

    (void)l;

    if (function_hook_state_BrLightEnable == HOOK_ENABLED) {
        assert(0 && "BrLightEnable not implemented.");
        abort();
    } else {
        original_BrLightEnable(l);
    }
}

function_hook_state_t function_hook_state_BrLightDisable = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(BrLightDisable, function_hook_state_BrLightDisable)
static void(__cdecl*original_BrLightDisable)(br_actor *) = (void(__cdecl*)(br_actor *))0x004dd0e0;
CARM95_HOOK_FUNCTION(original_BrLightDisable, BrLightDisable)
void __cdecl BrLightDisable(br_actor *l) {
    LOG_TRACE("(%p)", l);

    (void)l;

    if (function_hook_state_BrLightDisable == HOOK_ENABLED) {
        assert(0 && "BrLightDisable not implemented.");
        abort();
    } else {
        original_BrLightDisable(l);
    }
}

function_hook_state_t function_hook_state_BrClipPlaneEnable = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(BrClipPlaneEnable, function_hook_state_BrClipPlaneEnable)
static void(__cdecl*original_BrClipPlaneEnable)(br_actor *) = (void(__cdecl*)(br_actor *))0x004dd130;
CARM95_HOOK_FUNCTION(original_BrClipPlaneEnable, BrClipPlaneEnable)
void __cdecl BrClipPlaneEnable(br_actor *c) {
    LOG_TRACE("(%p)", c);

    (void)c;

    if (function_hook_state_BrClipPlaneEnable == HOOK_ENABLED) {
        assert(0 && "BrClipPlaneEnable not implemented.");
        abort();
    } else {
        original_BrClipPlaneEnable(c);
    }
}

function_hook_state_t function_hook_state_BrClipPlaneDisable = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(BrClipPlaneDisable, function_hook_state_BrClipPlaneDisable)
static void(__cdecl*original_BrClipPlaneDisable)(br_actor *) = (void(__cdecl*)(br_actor *))0x004dd1e0;
CARM95_HOOK_FUNCTION(original_BrClipPlaneDisable, BrClipPlaneDisable)
void __cdecl BrClipPlaneDisable(br_actor *c) {
    LOG_TRACE("(%p)", c);

    (void)c;

    if (function_hook_state_BrClipPlaneDisable == HOOK_ENABLED) {
        assert(0 && "BrClipPlaneDisable not implemented.");
        abort();
    } else {
        original_BrClipPlaneDisable(c);
    }
}

function_hook_state_t function_hook_state_BrHorizonPlaneEnable = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(BrHorizonPlaneEnable, function_hook_state_BrHorizonPlaneEnable)
static void(__cdecl*original_BrHorizonPlaneEnable)(br_actor *) = (void(__cdecl*)(br_actor *))0x004dd230;
CARM95_HOOK_FUNCTION(original_BrHorizonPlaneEnable, BrHorizonPlaneEnable)
void __cdecl BrHorizonPlaneEnable(br_actor *h) {
    LOG_TRACE("(%p)", h);

    (void)h;

    if (function_hook_state_BrHorizonPlaneEnable == HOOK_ENABLED) {
        assert(0 && "BrHorizonPlaneEnable not implemented.");
        abort();
    } else {
        original_BrHorizonPlaneEnable(h);
    }
}

function_hook_state_t function_hook_state_BrHorizonPlaneDisable = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(BrHorizonPlaneDisable, function_hook_state_BrHorizonPlaneDisable)
static void(__cdecl*original_BrHorizonPlaneDisable)(br_actor *) = (void(__cdecl*)(br_actor *))0x004dd2e0;
CARM95_HOOK_FUNCTION(original_BrHorizonPlaneDisable, BrHorizonPlaneDisable)
void __cdecl BrHorizonPlaneDisable(br_actor *h) {
    LOG_TRACE("(%p)", h);

    (void)h;

    if (function_hook_state_BrHorizonPlaneDisable == HOOK_ENABLED) {
        assert(0 && "BrHorizonPlaneDisable not implemented.");
        abort();
    } else {
        original_BrHorizonPlaneDisable(h);
    }
}

function_hook_state_t function_hook_state_BrEnvironmentSet = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(BrEnvironmentSet, function_hook_state_BrEnvironmentSet)
static br_actor *(__cdecl*original_BrEnvironmentSet)(br_actor *) = (br_actor *(__cdecl*)(br_actor *))0x004dd330;
CARM95_HOOK_FUNCTION(original_BrEnvironmentSet, BrEnvironmentSet)
br_actor* __cdecl BrEnvironmentSet(br_actor *a) {
    br_actor *old_a;
    LOG_TRACE("(%p)", a);

    (void)a;
    (void)old_a;

    if (function_hook_state_BrEnvironmentSet == HOOK_ENABLED) {
        assert(0 && "BrEnvironmentSet not implemented.");
        abort();
    } else {
        return original_BrEnvironmentSet(a);
    }
}

function_hook_state_t function_hook_state_setupView = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(setupView, function_hook_state_setupView)
br_boolean setupView(br_matrix34 *view_to_this, br_matrix34 *this_to_view, br_matrix34 *world_to_view, br_int_32 w2vt, br_actor *world, br_actor *a) {
    br_matrix34 this_to_world;
    br_int_32 root_t;
    br_int_32 t;
    LOG_TRACE("(%p, %p, %p, %d, %p, %p)", view_to_this, this_to_view, world_to_view, w2vt, world, a);

    (void)view_to_this;
    (void)this_to_view;
    (void)world_to_view;
    (void)w2vt;
    (void)world;
    (void)a;
    (void)this_to_world;
    (void)root_t;
    (void)t;

    if (function_hook_state_setupView == HOOK_ENABLED) {
        assert(0 && "setupView not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}

function_hook_state_t function_hook_state_BrSetupLights = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(BrSetupLights, function_hook_state_BrSetupLights)
static void(__stdcall*original_BrSetupLights)(br_actor *, br_matrix34 *, br_int_32) = (void(__stdcall*)(br_actor *, br_matrix34 *, br_int_32))0x004dd340;
CARM95_HOOK_FUNCTION(original_BrSetupLights, BrSetupLights)
void __stdcall BrSetupLights(br_actor *world, br_matrix34 *world_to_view, br_int_32 w2vt) {
    br_matrix34 this_to_view;
    br_matrix34 view_to_this;
    int light_part;
    int i;
    br_token_value tv[16];
    br_token_value *tvp;
    br_vector3 view_position;
    br_vector3 view_direction;
    br_light *light;
    LOG_TRACE("(%p, %p, %d)", world, world_to_view, w2vt);

    (void)world;
    (void)world_to_view;
    (void)w2vt;
    (void)this_to_view;
    (void)view_to_this;
    (void)light_part;
    (void)i;
    (void)tv;
    (void)tvp;
    (void)view_position;
    (void)view_direction;
    (void)light;

    if (function_hook_state_BrSetupLights == HOOK_ENABLED) {
        assert(0 && "BrSetupLights not implemented.");
        abort();
    } else {
        original_BrSetupLights(world, world_to_view, w2vt);
    }
}

function_hook_state_t function_hook_state_BrSetupClipPlanes = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(BrSetupClipPlanes, function_hook_state_BrSetupClipPlanes)
static void(__stdcall*original_BrSetupClipPlanes)(br_actor *, br_matrix34 *, br_int_32, br_matrix4 *) = (void(__stdcall*)(br_actor *, br_matrix34 *, br_int_32, br_matrix4 *))0x004dd640;
CARM95_HOOK_FUNCTION(original_BrSetupClipPlanes, BrSetupClipPlanes)
void __stdcall BrSetupClipPlanes(br_actor *world, br_matrix34 *world_to_view, br_int_32 w2vt, br_matrix4 *view_to_screen) {
    br_matrix34 this_to_view;
    br_matrix34 view_to_this;
    br_matrix4 screen_to_view;
    br_matrix4 tmp4;
    br_matrix4 screen_to_this;
    int light_part;
    int i;
    br_int_32 clip_part;
    br_token_value tv[3];
    br_vector4 sp;
    LOG_TRACE("(%p, %p, %d, %p)", world, world_to_view, w2vt, view_to_screen);

    (void)world;
    (void)world_to_view;
    (void)w2vt;
    (void)view_to_screen;
    (void)this_to_view;
    (void)view_to_this;
    (void)screen_to_view;
    (void)tmp4;
    (void)screen_to_this;
    (void)light_part;
    (void)i;
    (void)clip_part;
    (void)tv;
    (void)sp;

    if (function_hook_state_BrSetupClipPlanes == HOOK_ENABLED) {
        assert(0 && "BrSetupClipPlanes not implemented.");
        abort();
    } else {
        original_BrSetupClipPlanes(world, world_to_view, w2vt, view_to_screen);
    }
}

function_hook_state_t function_hook_state_BrSetupEnvironment = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(BrSetupEnvironment, function_hook_state_BrSetupEnvironment)
static void(__stdcall*original_BrSetupEnvironment)(br_actor *, br_matrix34 *, br_int_32) = (void(__stdcall*)(br_actor *, br_matrix34 *, br_int_32))0x004dd820;
CARM95_HOOK_FUNCTION(original_BrSetupEnvironment, BrSetupEnvironment)
void __stdcall BrSetupEnvironment(br_actor *world, br_matrix34 *world_to_view, br_int_32 w2vt) {
    br_matrix34 view_to_this;
    br_matrix34 this_to_view;
    br_token h;
    LOG_TRACE("(%p, %p, %d)", world, world_to_view, w2vt);

    (void)world;
    (void)world_to_view;
    (void)w2vt;
    (void)view_to_this;
    (void)this_to_view;
    (void)h;

    if (function_hook_state_BrSetupEnvironment == HOOK_ENABLED) {
        assert(0 && "BrSetupEnvironment not implemented.");
        abort();
    } else {
        original_BrSetupEnvironment(world, world_to_view, w2vt);
    }
}

function_hook_state_t function_hook_state_BrSetupHorizons = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(BrSetupHorizons, function_hook_state_BrSetupHorizons)
void(__stdcall*BrSetupHorizons)(br_actor *, br_matrix34 *, br_int_32) = (void(__stdcall*)(br_actor *, br_matrix34 *, br_int_32))0x004dd930;
void BrSetupHorizons_do_not_use(br_actor *world, br_matrix34 *world_to_view, br_int_32 w2vt) {
    LOG_TRACE("(%p, %p, %d)", world, world_to_view, w2vt);

    (void)world;
    (void)world_to_view;
    (void)w2vt;

    if (function_hook_state_BrSetupHorizons == HOOK_ENABLED) {
        assert(0 && "BrSetupHorizons_do_not_use not implemented.");
        abort();
    } else {
        NOT_IMPLEMENTED();
    }
}

function_hook_state_t function_hook_state_BrActorEnableCheck = HOOK_UNAVAILABLE;
CARM95_WEBSERVER_STATE(BrActorEnableCheck, function_hook_state_BrActorEnableCheck)
static void(__stdcall*original_BrActorEnableCheck)(br_actor *) = (void(__stdcall*)(br_actor *))0x004dd940;
CARM95_HOOK_FUNCTION(original_BrActorEnableCheck, BrActorEnableCheck)
void __stdcall BrActorEnableCheck(br_actor *a) {
    LOG_TRACE("(%p)", a);

    (void)a;

    if (function_hook_state_BrActorEnableCheck == HOOK_ENABLED) {
        assert(0 && "BrActorEnableCheck not implemented.");
        abort();
    } else {
        original_BrActorEnableCheck(a);
    }
}

