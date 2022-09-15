#include "modrend.h"

#include "harness/trace.h"

#include "carm95_hooks.h"

#include <stdio.h>
struct fmt_vertex(* hookvar_bounds_vertices )[8] = (void*)0x00525818;
struct v11face(* hookvar_bounds_faces )[12] = (void*)0x00525918;
struct v11group(* hookvar_bounds_face_groups )[1] = (void*)0x00525a68;
struct v11model * hookvar_bounds_prepared  = (void*)0x00525a90;
struct br_model * hookvar_bounds_model  = (void*)0x00525ab0;
void(**(* hookvar_RenderStyleCalls )[8])(br_actor *, br_model *, br_material *, void *, br_uint_8, int, ...) = (void*)0x00525b08;
br_colour(* hookvar_bounds_colours )[12] = (void*)0x00541650;

static void(*original_renderFaces)(br_actor *, br_model *, br_material *, void *, br_uint_8, int, ...) = (void(*)(br_actor *, br_model *, br_material *, void *, br_uint_8, int, ...))0x004dda90;
CARM95_HOOK_FUNCTION(original_renderFaces, renderFaces)
void renderFaces(br_actor *actor, br_model *model, br_material *material, void *render_data, br_uint_8 style, int on_screen) {
    LOG_TRACE("(%p, %p, %p, %p, %u, %d)", actor, model, material, render_data, style, on_screen);

    (void)actor;
    (void)model;
    (void)material;
    (void)render_data;
    (void)style;
    (void)on_screen;

    original_renderFaces(actor, model, material, render_data, style, on_screen);
}

static void(*original_renderEdges)(br_actor *, br_model *, br_material *, void *, br_uint_8, int, ...) = (void(*)(br_actor *, br_model *, br_material *, void *, br_uint_8, int, ...))0x004ddb10;
CARM95_HOOK_FUNCTION(original_renderEdges, renderEdges)
void renderEdges(br_actor *actor, br_model *model, br_material *material, void *render_data, br_uint_8 style, int on_screen) {
    LOG_TRACE("(%p, %p, %p, %p, %u, %d)", actor, model, material, render_data, style, on_screen);

    (void)actor;
    (void)model;
    (void)material;
    (void)render_data;
    (void)style;
    (void)on_screen;

    original_renderEdges(actor, model, material, render_data, style, on_screen);
}

static void(*original_renderPoints)(br_actor *, br_model *, br_material *, void *, br_uint_8, int, ...) = (void(*)(br_actor *, br_model *, br_material *, void *, br_uint_8, int, ...))0x004ddb60;
CARM95_HOOK_FUNCTION(original_renderPoints, renderPoints)
void renderPoints(br_actor *actor, br_model *model, br_material *material, void *render_data, br_uint_8 style, int on_screen) {
    LOG_TRACE("(%p, %p, %p, %p, %u, %d)", actor, model, material, render_data, style, on_screen);

    (void)actor;
    (void)model;
    (void)material;
    (void)render_data;
    (void)style;
    (void)on_screen;

    original_renderPoints(actor, model, material, render_data, style, on_screen);
}

static void(*original_nullRender)(br_actor *, br_model *, br_material *, void *, br_uint_8, int, ...) = (void(*)(br_actor *, br_model *, br_material *, void *, br_uint_8, int, ...))0x004ddbb0;
CARM95_HOOK_FUNCTION(original_nullRender, nullRender)
void nullRender(br_actor *actor, br_model *model, br_material *material, void *render_data, br_uint_8 style, int on_screen) {
    LOG_TRACE("(%p, %p, %p, %p, %u, %d)", actor, model, material, render_data, style, on_screen);

    (void)actor;
    (void)model;
    (void)material;
    (void)render_data;
    (void)style;
    (void)on_screen;

    original_nullRender(actor, model, material, render_data, style, on_screen);
}

static struct br_model *(*original_makeMeshFromBounds)(br_bounds *, ...) = (struct br_model *(*)(br_bounds *, ...))0x004ddc10;
CARM95_HOOK_FUNCTION(original_makeMeshFromBounds, makeMeshFromBounds)
struct br_model* makeMeshFromBounds(br_bounds *b) {
    int i;
    LOG_TRACE("(%p)", b);

    (void)b;
    (void)i;

    return original_makeMeshFromBounds(b);
}

static void(*original_boundingBoxRenderPoints)(br_actor *, br_model *, br_material *, void *, br_uint_8, int, ...) = (void(*)(br_actor *, br_model *, br_material *, void *, br_uint_8, int, ...))0x004ddbc0;
CARM95_HOOK_FUNCTION(original_boundingBoxRenderPoints, boundingBoxRenderPoints)
void boundingBoxRenderPoints(br_actor *actor, br_model *model, br_material *material, void *render_data, br_uint_8 style, int on_screen) {
    LOG_TRACE("(%p, %p, %p, %p, %u, %d)", actor, model, material, render_data, style, on_screen);

    (void)actor;
    (void)model;
    (void)material;
    (void)render_data;
    (void)style;
    (void)on_screen;

    original_boundingBoxRenderPoints(actor, model, material, render_data, style, on_screen);
}

static void(*original_boundingBoxRenderEdges)(br_actor *, br_model *, br_material *, void *, br_uint_8, int, ...) = (void(*)(br_actor *, br_model *, br_material *, void *, br_uint_8, int, ...))0x004ddd20;
CARM95_HOOK_FUNCTION(original_boundingBoxRenderEdges, boundingBoxRenderEdges)
void boundingBoxRenderEdges(br_actor *actor, br_model *model, br_material *material, void *render_data, br_uint_8 style, int on_screen) {
    LOG_TRACE("(%p, %p, %p, %p, %u, %d)", actor, model, material, render_data, style, on_screen);

    (void)actor;
    (void)model;
    (void)material;
    (void)render_data;
    (void)style;
    (void)on_screen;

    original_boundingBoxRenderEdges(actor, model, material, render_data, style, on_screen);
}

static void(*original_boundingBoxRenderFaces)(br_actor *, br_model *, br_material *, void *, br_uint_8, int, ...) = (void(*)(br_actor *, br_model *, br_material *, void *, br_uint_8, int, ...))0x004ddd70;
CARM95_HOOK_FUNCTION(original_boundingBoxRenderFaces, boundingBoxRenderFaces)
void boundingBoxRenderFaces(br_actor *actor, br_model *model, br_material *material, void *render_data, br_uint_8 style, int on_screen) {
    LOG_TRACE("(%p, %p, %p, %p, %u, %d)", actor, model, material, render_data, style, on_screen);

    (void)actor;
    (void)model;
    (void)material;
    (void)render_data;
    (void)style;
    (void)on_screen;

    original_boundingBoxRenderFaces(actor, model, material, render_data, style, on_screen);
}

