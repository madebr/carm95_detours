#ifndef _MODREND_H_
#define _MODREND_H_

#include "br_types.h"

extern void(**(* hookvar_RenderStyleCalls )[8])(br_actor *, br_model *, br_material *, void *, br_uint_8, int, ...); // addr: 00525B08
extern br_colour(* hookvar_bounds_colours )[12]; // addr: 00541650

void renderFaces(br_actor *actor, br_model *model, br_material *material, void *render_data, br_uint_8 style, int on_screen);

void renderEdges(br_actor *actor, br_model *model, br_material *material, void *render_data, br_uint_8 style, int on_screen);

void renderPoints(br_actor *actor, br_model *model, br_material *material, void *render_data, br_uint_8 style, int on_screen);

void nullRender(br_actor *actor, br_model *model, br_material *material, void *render_data, br_uint_8 style, int on_screen);

struct br_model* makeMeshFromBounds(br_bounds *b);

void boundingBoxRenderPoints(br_actor *actor, br_model *model, br_material *material, void *render_data, br_uint_8 style, int on_screen);

void boundingBoxRenderEdges(br_actor *actor, br_model *model, br_material *material, void *render_data, br_uint_8 style, int on_screen);

void boundingBoxRenderFaces(br_actor *actor, br_model *model, br_material *material, void *render_data, br_uint_8 style, int on_screen);

#endif
