#ifndef _VECTOR_H_
#define _VECTOR_H_

#include "br_types.h"


void __cdecl BrVector2Copy(br_vector2 *v1, br_vector2 *v2);

void __cdecl BrVector2Set(br_vector2 *v1, br_scalar s1, br_scalar s2);

void __cdecl BrVector2SetInt(br_vector2 *v1, int i1, int i2);

void __cdecl BrVector2SetFloat(br_vector2 *v1, float f1, float f2);

void __cdecl BrVector2Negate(br_vector2 *v1, br_vector2 *v2);

void __cdecl BrVector2Add(br_vector2 *v1, br_vector2 *v2, br_vector2 *v3);

void __cdecl BrVector2Accumulate(br_vector2 *v1, br_vector2 *v2);

void __cdecl BrVector2Sub(br_vector2 *v1, br_vector2 *v2, br_vector2 *v3);

void __cdecl BrVector2Scale(br_vector2 *v1, br_vector2 *v2, br_scalar s);

void __cdecl BrVector2InvScale(br_vector2 *v1, br_vector2 *v2, br_scalar s);

br_scalar __cdecl BrVector2Dot(br_vector2 *v1, br_vector2 *v2);

br_scalar __cdecl BrVector2Length(br_vector2 *v1);

br_scalar __cdecl BrVector2LengthSquared(br_vector2 *v1);

void __cdecl BrVector3Copy(br_vector3 *v1, br_vector3 *v2);

void __cdecl BrVector3Set(br_vector3 *v1, br_scalar s1, br_scalar s2, br_scalar s3);

void __cdecl BrVector3SetInt(br_vector3 *v1, int i1, int i2, int i3);

void __cdecl BrVector3SetFloat(br_vector3 *v1, float f1, float f2, float f3);

void __cdecl BrVector3Negate(br_vector3 *v1, br_vector3 *v2);

void __cdecl BrVector3Add(br_vector3 *v1, br_vector3 *v2, br_vector3 *v3);

void __cdecl BrVector3Accumulate(br_vector3 *v1, br_vector3 *v2);

void __cdecl BrVector3Sub(br_vector3 *v1, br_vector3 *v2, br_vector3 *v3);

void __cdecl BrVector3Scale(br_vector3 *v1, br_vector3 *v2, br_scalar s);

void __cdecl BrVector3InvScale(br_vector3 *v1, br_vector3 *v2, br_scalar s);

br_scalar __cdecl BrVector3Dot(br_vector3 *v1, br_vector3 *v2);

void __cdecl BrVector3Cross(br_vector3 *v1, br_vector3 *v2, br_vector3 *v3);

br_scalar __cdecl BrVector3Length(br_vector3 *v1);

br_scalar __cdecl BrVector3LengthSquared(br_vector3 *v1);

void __cdecl BrVector3Normalise(br_vector3 *v1, br_vector3 *v2);

void __cdecl BrVector3NormaliseLP(br_vector3 *v1, br_vector3 *v2);

br_scalar __cdecl BrVector4Dot(br_vector4 *v1, br_vector4 *v2);

void __cdecl BrVector4Copy(br_vector4 *v1, br_vector4 *v2);

br_scalar __stdcall BrFVector2Dot(br_fvector2 *v1, br_vector2 *v2);

void __stdcall BrFVector3Copy(br_fvector3 *v1, br_vector3 *v2);

void __stdcall BrVector3ScaleF(br_vector3 *v1, br_fvector3 *v2, br_scalar s);

br_scalar __stdcall BrFVector3Dot(br_fvector3 *v1, br_vector3 *v2);

void __stdcall BrFVector3Normalise(br_fvector3 *v1, br_vector3 *v2);

void __stdcall BrFVector3NormaliseLP(br_fvector3 *v1, br_vector3 *v2);

void __cdecl BrVector2Normalise(br_vector2 *v1, br_vector2 *v2);

#endif
