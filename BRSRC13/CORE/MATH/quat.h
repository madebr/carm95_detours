#ifndef _QUAT_H_
#define _QUAT_H_

#include "br_types.h"


br_quat* __cdecl BrQuatMul(br_quat *q, br_quat *l, br_quat *r);

br_quat* __cdecl BrQuatNormalise(br_quat *q, br_quat *qq);

br_quat* __cdecl BrQuatInvert(br_quat *q, br_quat *qq);

br_quat* __cdecl BrQuatSlerp(br_quat *q, br_quat *l, br_quat *r, br_scalar a, br_int_16 spins);

br_matrix34* __cdecl BrQuatToMatrix34(br_matrix34 *mat, br_quat *q);

br_quat* __cdecl BrMatrix34ToQuat(br_quat *q, br_matrix34 *mat);

br_matrix4* __cdecl BrQuatToMatrix4(br_matrix4 *mat, br_quat *q);

br_quat* __cdecl BrMatrix4ToQuat(br_quat *q, br_matrix4 *mat);

#endif
