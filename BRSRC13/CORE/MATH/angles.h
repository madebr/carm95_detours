#ifndef _ANGLES_H_
#define _ANGLES_H_

#include "br_types.h"


br_matrix34* __cdecl BrEulerToMatrix34(br_matrix34 *mat, br_euler *euler);

br_euler* __cdecl BrMatrix34ToEuler(br_euler *euler, br_matrix34 *mat);

br_matrix4* __cdecl BrEulerToMatrix4(br_matrix4 *mat, br_euler *euler);

br_euler* __cdecl BrMatrix4ToEuler(br_euler *dest, br_matrix4 *mat);

br_quat* __cdecl BrEulerToQuat(br_quat *q, br_euler *euler);

br_euler* __cdecl BrQuatToEuler(br_euler *euler, br_quat *q);

#endif
