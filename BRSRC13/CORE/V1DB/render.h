#ifndef _RENDER_H_
#define _RENDER_H_

#include "br_types.h"


void __cdecl BrDbModelRender(br_actor *actor, br_model *model, br_material *material, void *render_data, br_uint_8 style, int on_screen, int use_custom);

br_uint_32 __cdecl BrOnScreenCheck(br_bounds3 *bounds);

br_uint_16 prependActorTransform(br_actor *ap, br_uint_16 t);

br_uint_16 prependMatrix(br_matrix34 *mat, br_uint_16 mat_t, br_uint_16 t);

void __stdcall actorRender(br_actor *ap, br_model *model, br_material *material, void *render_data, br_uint_8 style, br_uint_16 t);

void actorRenderOnScreen(br_actor *ap, br_model *model, br_material *material, void *render_data, br_uint_8 style, br_uint_16 t);

void sceneRenderWorld(br_actor *world);

void __stdcall sceneRenderAdd(br_actor *tree);

void __cdecl BrDbSceneRenderBegin(br_actor *world, br_actor *camera);

br_renderbounds_cbfn* __cdecl BrDbSetRenderBoundsCallback(br_renderbounds_cbfn *new_cbfn);

void SetOrigin(br_pixelmap *buffer);

void SetViewport(br_pixelmap *buffer);

void __cdecl BrZbSceneRenderBegin(br_actor *world, br_actor *camera, br_pixelmap *colour_buffer, br_pixelmap *depth_buffer);

void __cdecl BrZbSceneRenderAdd(br_actor *tree);

void __cdecl BrZbSceneRenderEnd();

void __cdecl BrZbSceneRender(br_actor *world, br_actor *camera, br_pixelmap *colour_buffer, br_pixelmap *depth_buffer);

void __cdecl BrZsSceneRenderBegin(br_actor *world, br_actor *camera, br_pixelmap *colour_buffer);

void __cdecl BrZsSceneRenderAdd(br_actor *tree);

void __cdecl BrZsSceneRenderEnd();

void __stdcall BrZsSceneRender(br_actor *world, br_actor *camera, br_pixelmap *colour_buffer);

br_primitive_cbfn* __cdecl BrZsPrimitiveCallbackSet(br_primitive_cbfn *new_cbfn);

void __cdecl BrZbModelRender(br_actor *actor, br_model *model, br_material *material, br_uint_8 style, int on_screen, int use_custom);

void __cdecl BrZsModelRender(br_actor *actor, br_model *model, br_material *material, br_order_table *order_table, br_uint_8 style, int on_screen, int use_custom);

br_renderbounds_cbfn* __cdecl BrZbRenderBoundsCallbackSet(br_renderbounds_cbfn *new_cbfn);

br_renderbounds_cbfn* __cdecl BrZsRenderBoundsCallbackSet(br_renderbounds_cbfn *new_cbfn);

#endif
