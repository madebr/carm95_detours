#include "enables.h"

#include "harness/trace.h"

#include "carm95_hooks.h"

#include <stdio.h>

void actorEnable(br_v1db_enable *e, br_actor *a) {
    int i;
    LOG_TRACE("(%p, %p)", e, a);

    (void)e;
    (void)a;
    (void)i;

    NOT_IMPLEMENTED();
}

void actorDisable(br_v1db_enable *e, br_actor *a) {
    int i;
    LOG_TRACE("(%p, %p)", e, a);

    (void)e;
    (void)a;
    (void)i;

    NOT_IMPLEMENTED();
}

static void(*original_BrLightEnable)(br_actor *, ...) = (void(*)(br_actor *, ...))0x004dd030;
CARM95_HOOK_FUNCTION(original_BrLightEnable, BrLightEnable)
void BrLightEnable(br_actor *l) {
    LOG_TRACE("(%p)", l);

    (void)l;

    original_BrLightEnable(l);
}

static void(*original_BrLightDisable)(br_actor *, ...) = (void(*)(br_actor *, ...))0x004dd0e0;
CARM95_HOOK_FUNCTION(original_BrLightDisable, BrLightDisable)
void BrLightDisable(br_actor *l) {
    LOG_TRACE("(%p)", l);

    (void)l;

    original_BrLightDisable(l);
}

static void(*original_BrClipPlaneEnable)(br_actor *, ...) = (void(*)(br_actor *, ...))0x004dd130;
CARM95_HOOK_FUNCTION(original_BrClipPlaneEnable, BrClipPlaneEnable)
void BrClipPlaneEnable(br_actor *c) {
    LOG_TRACE("(%p)", c);

    (void)c;

    original_BrClipPlaneEnable(c);
}

static void(*original_BrClipPlaneDisable)(br_actor *, ...) = (void(*)(br_actor *, ...))0x004dd1e0;
CARM95_HOOK_FUNCTION(original_BrClipPlaneDisable, BrClipPlaneDisable)
void BrClipPlaneDisable(br_actor *c) {
    LOG_TRACE("(%p)", c);

    (void)c;

    original_BrClipPlaneDisable(c);
}

static void(*original_BrHorizonPlaneEnable)(br_actor *, ...) = (void(*)(br_actor *, ...))0x004dd230;
CARM95_HOOK_FUNCTION(original_BrHorizonPlaneEnable, BrHorizonPlaneEnable)
void BrHorizonPlaneEnable(br_actor *h) {
    LOG_TRACE("(%p)", h);

    (void)h;

    original_BrHorizonPlaneEnable(h);
}

static void(*original_BrHorizonPlaneDisable)(br_actor *, ...) = (void(*)(br_actor *, ...))0x004dd2e0;
CARM95_HOOK_FUNCTION(original_BrHorizonPlaneDisable, BrHorizonPlaneDisable)
void BrHorizonPlaneDisable(br_actor *h) {
    LOG_TRACE("(%p)", h);

    (void)h;

    original_BrHorizonPlaneDisable(h);
}

static br_actor *(*original_BrEnvironmentSet)(br_actor *, ...) = (br_actor *(*)(br_actor *, ...))0x004dd330;
CARM95_HOOK_FUNCTION(original_BrEnvironmentSet, BrEnvironmentSet)
br_actor* BrEnvironmentSet(br_actor *a) {
    br_actor *old_a;
    LOG_TRACE("(%p)", a);

    (void)a;
    (void)old_a;

    return original_BrEnvironmentSet(a);
}

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

    NOT_IMPLEMENTED();
}

static void(*original_BrSetupLights)(br_actor *, br_matrix34 *, br_int_32, ...) = (void(*)(br_actor *, br_matrix34 *, br_int_32, ...))0x004dd340;
CARM95_HOOK_FUNCTION(original_BrSetupLights, BrSetupLights)
void BrSetupLights(br_actor *world, br_matrix34 *world_to_view, br_int_32 w2vt) {
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

    original_BrSetupLights(world, world_to_view, w2vt);
}

static void(*original_BrSetupClipPlanes)(br_actor *, br_matrix34 *, br_int_32, br_matrix4 *, ...) = (void(*)(br_actor *, br_matrix34 *, br_int_32, br_matrix4 *, ...))0x004dd640;
CARM95_HOOK_FUNCTION(original_BrSetupClipPlanes, BrSetupClipPlanes)
void BrSetupClipPlanes(br_actor *world, br_matrix34 *world_to_view, br_int_32 w2vt, br_matrix4 *view_to_screen) {
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

    original_BrSetupClipPlanes(world, world_to_view, w2vt, view_to_screen);
}

static void(*original_BrSetupEnvironment)(br_actor *, br_matrix34 *, br_int_32, ...) = (void(*)(br_actor *, br_matrix34 *, br_int_32, ...))0x004dd820;
CARM95_HOOK_FUNCTION(original_BrSetupEnvironment, BrSetupEnvironment)
void BrSetupEnvironment(br_actor *world, br_matrix34 *world_to_view, br_int_32 w2vt) {
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

    original_BrSetupEnvironment(world, world_to_view, w2vt);
}

static void(*original_BrSetupHorizons)(br_actor *, br_matrix34 *, br_int_32, ...) = (void(*)(br_actor *, br_matrix34 *, br_int_32, ...))0x004dd930;
CARM95_HOOK_FUNCTION(original_BrSetupHorizons, BrSetupHorizons)
void BrSetupHorizons(br_actor *world, br_matrix34 *world_to_view, br_int_32 w2vt) {
    LOG_TRACE("(%p, %p, %d)", world, world_to_view, w2vt);

    (void)world;
    (void)world_to_view;
    (void)w2vt;

    original_BrSetupHorizons(world, world_to_view, w2vt);
}

static void(*original_BrActorEnableCheck)(br_actor *, ...) = (void(*)(br_actor *, ...))0x004dd940;
CARM95_HOOK_FUNCTION(original_BrActorEnableCheck, BrActorEnableCheck)
void BrActorEnableCheck(br_actor *a) {
    LOG_TRACE("(%p)", a);

    (void)a;

    original_BrActorEnableCheck(a);
}

