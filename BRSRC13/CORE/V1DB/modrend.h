#ifndef _MODREND_H_
#define _MODREND_H_

#include "br_types.h"

extern void(**(* hookvar_RenderStyleCalls )[8])(br_actor *, br_model *, br_material *, void *, br_uint_8, int); // addr: 00525B08
extern br_colour(* hookvar_bounds_colours )[12]; // addr: 00541650

void __stdcall renderFaces(br_actor *actor, br_model *model, br_material *material, void *render_data, br_uint_8 style, int on_screen);

void __stdcall renderEdges(br_actor *actor, br_model *model, br_material *material, void *render_data, br_uint_8 style, int on_screen);

void __stdcall renderPoints(br_actor *actor, br_model *model, br_material *material, void *render_data, br_uint_8 style, int on_screen);

#if 0
void nullRender_do_not_use(br_actor *actor, br_model *model, br_material *material, void *render_data, br_uint_8 style, int on_screen);
#endif

struct br_model* __stdcall makeMeshFromBounds(br_bounds *b);

void __stdcall boundingBoxRenderPoints(br_actor *actor, br_model *model, br_material *material, void *render_data, br_uint_8 style, int on_screen);

void __stdcall boundingBoxRenderEdges(br_actor *actor, br_model *model, br_material *material, void *render_data, br_uint_8 style, int on_screen);

void __stdcall boundingBoxRenderFaces(br_actor *actor, br_model *model, br_material *material, void *render_data, br_uint_8 style, int on_screen);

#endif
