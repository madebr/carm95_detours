#ifndef _ACTSUPT_H_
#define _ACTSUPT_H_

#include "br_types.h"


br_uint_32 __cdecl BrActorEnum(br_actor *parent, br_actor_enum_cbfn *callback, void *arg);

br_uint_32 __cdecl BrActorSearchMany(br_actor *root, char *pattern, br_actor **actors, int max);

br_actor* __cdecl BrActorSearch(br_actor *root, char *pattern);

void __stdcall RenumberActor(br_actor *a, int d);

br_actor* __cdecl BrActorAdd(br_actor *parent, br_actor *a);

br_actor* __cdecl BrActorRemove(br_actor *a);

void __cdecl BrActorRelink(br_actor *parent, br_actor *a);

br_actor* __cdecl BrActorAllocate(br_uint_8 type, void *type_data);

void __stdcall InternalActorFree(br_actor *a);

void __cdecl BrActorFree(br_actor *a);

br_boolean __stdcall ActorToRoot(br_actor *a, br_actor *world, br_matrix34 *m);

br_boolean __stdcall ActorToRootTyped(br_actor *a, br_actor *world, br_matrix34 *m, br_int_32 *type);

void __stdcall Matrix4PerspectiveNew(br_matrix4 *mat, br_angle field_of_view, br_scalar aspect, br_scalar hither, br_scalar yon, br_scalar origin_x, br_scalar origin_y);

br_token __stdcall CameraToScreenMatrix4(br_matrix4 *mat, br_actor *camera);

br_uint_16 __cdecl BrActorToActorMatrix34(br_matrix34 *m, br_actor *a, br_actor *b);

void __cdecl BrActorToScreenMatrix4(br_matrix4 *m, br_actor *a, br_actor *camera);

void BrMatrix34ApplyBounds(br_bounds *d, br_bounds *s, br_matrix34 *m);

void __stdcall ActorToBounds(br_bounds *dest, br_actor *ap, br_model *model);

br_bounds* __cdecl BrActorToBounds(br_bounds *b, br_actor *ap);

#endif
