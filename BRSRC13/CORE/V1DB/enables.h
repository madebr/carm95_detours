#ifndef _ENABLES_H_
#define _ENABLES_H_

#include "br_types.h"


void actorEnable(br_v1db_enable *e, br_actor *a);

void actorDisable(br_v1db_enable *e, br_actor *a);

void __cdecl BrLightEnable(br_actor *l);

void __cdecl BrLightDisable(br_actor *l);

void __cdecl BrClipPlaneEnable(br_actor *c);

void __cdecl BrClipPlaneDisable(br_actor *c);

void __cdecl BrHorizonPlaneEnable(br_actor *h);

void __cdecl BrHorizonPlaneDisable(br_actor *h);

br_actor* __cdecl BrEnvironmentSet(br_actor *a);

br_boolean setupView(br_matrix34 *view_to_this, br_matrix34 *this_to_view, br_matrix34 *world_to_view, br_int_32 w2vt, br_actor *world, br_actor *a);

void __stdcall BrSetupLights(br_actor *world, br_matrix34 *world_to_view, br_int_32 w2vt);

void __stdcall BrSetupClipPlanes(br_actor *world, br_matrix34 *world_to_view, br_int_32 w2vt, br_matrix4 *view_to_screen);

void __stdcall BrSetupEnvironment(br_actor *world, br_matrix34 *world_to_view, br_int_32 w2vt);

#if 0
void BrSetupHorizons_do_not_use(br_actor *world, br_matrix34 *world_to_view, br_int_32 w2vt);
#endif

void __stdcall BrActorEnableCheck(br_actor *a);

#endif
