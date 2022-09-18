#ifndef _MATRIX34_H_
#define _MATRIX34_H_

#include "br_types.h"

// extern br_matrix34 * hookvar_mattmp1__matrix34 ; // suffix added to avoid duplicate symbol
// extern br_matrix34 * hookvar_mattmp2__matrix34 ; // suffix added to avoid duplicate symbol

void __cdecl BrMatrix34Copy(br_matrix34 *A, br_matrix34 *B);

void __cdecl BrMatrix34Mul(br_matrix34 *A, br_matrix34 *B, br_matrix34 *C);

void __cdecl BrMatrix34Identity(br_matrix34 *mat);

void __cdecl BrMatrix34RotateX(br_matrix34 *mat, br_angle rx);

void __cdecl BrMatrix34RotateY(br_matrix34 *mat, br_angle ry);

void __cdecl BrMatrix34RotateZ(br_matrix34 *mat, br_angle rz);

void __cdecl BrMatrix34Rotate(br_matrix34 *mat, br_angle r, br_vector3 *a);

void __cdecl BrMatrix34Translate(br_matrix34 *mat, br_scalar dx, br_scalar dy, br_scalar dz);

void __cdecl BrMatrix34Scale(br_matrix34 *mat, br_scalar sx, br_scalar sy, br_scalar sz);

void __cdecl BrMatrix34ShearX(br_matrix34 *mat, br_scalar sy, br_scalar sz);

void __cdecl BrMatrix34ShearY(br_matrix34 *mat, br_scalar sx, br_scalar sz);

void __cdecl BrMatrix34ShearZ(br_matrix34 *mat, br_scalar sx, br_scalar sy);

br_scalar __cdecl BrMatrix34Inverse(br_matrix34 *B, br_matrix34 *A);

void __cdecl BrMatrix34LPInverse(br_matrix34 *A, br_matrix34 *B);

void __cdecl BrMatrix34LPNormalise(br_matrix34 *A, br_matrix34 *B);

void __cdecl BrMatrix34RollingBall(br_matrix34 *mat, int dx, int dy, int radius);

br_matrix34* BrBoundsToMatrix34(br_matrix34 *mat, br_bounds *bounds);

void __cdecl BrMatrix34Copy4(br_matrix34 *A, br_matrix4 *B);

void __stdcall BrMatrix34TApplyFV(br_vector3 *A, br_fvector3 *B, br_matrix34 *C);

void __cdecl BrMatrix34Apply(br_vector3 *A, br_vector4 *B, br_matrix34 *C);

void __cdecl BrMatrix34ApplyP(br_vector3 *A, br_vector3 *B, br_matrix34 *C);

void __cdecl BrMatrix34ApplyV(br_vector3 *A, br_vector3 *B, br_matrix34 *C);

void __cdecl BrMatrix34TApply(br_vector4 *A, br_vector4 *B, br_matrix34 *C);

void __cdecl BrMatrix34TApplyP(br_vector3 *A, br_vector3 *B, br_matrix34 *C);

void __cdecl BrMatrix34TApplyV(br_vector3 *A, br_vector3 *B, br_matrix34 *C);

void __cdecl BrMatrix34Pre(br_matrix34 *mat, br_matrix34 *A);

void __cdecl BrMatrix34Post(br_matrix34 *mat, br_matrix34 *A);

void __cdecl BrMatrix34PreRotateX(br_matrix34 *mat, br_angle rx);

void __cdecl BrMatrix34PostRotateX(br_matrix34 *mat, br_angle rx);

void __cdecl BrMatrix34PreRotateY(br_matrix34 *mat, br_angle ry);

void __cdecl BrMatrix34PostRotateY(br_matrix34 *mat, br_angle ry);

void __cdecl BrMatrix34PreRotateZ(br_matrix34 *mat, br_angle rz);

void __cdecl BrMatrix34PostRotateZ(br_matrix34 *mat, br_angle rz);

void __cdecl BrMatrix34PreRotate(br_matrix34 *mat, br_angle r, br_vector3 *axis);

void __cdecl BrMatrix34PostRotate(br_matrix34 *mat, br_angle r, br_vector3 *axis);

void __cdecl BrMatrix34PreTranslate(br_matrix34 *mat, br_scalar x, br_scalar y, br_scalar z);

void __cdecl BrMatrix34PostTranslate(br_matrix34 *mat, br_scalar x, br_scalar y, br_scalar z);

void __cdecl BrMatrix34PreScale(br_matrix34 *mat, br_scalar sx, br_scalar sy, br_scalar sz);

void __cdecl BrMatrix34PostScale(br_matrix34 *mat, br_scalar sx, br_scalar sy, br_scalar sz);

void __cdecl BrMatrix34PreShearX(br_matrix34 *mat, br_scalar sy, br_scalar sz);

void __cdecl BrMatrix34PostShearX(br_matrix34 *mat, br_scalar sy, br_scalar sz);

void __cdecl BrMatrix34PreShearY(br_matrix34 *mat, br_scalar sx, br_scalar sz);

void __cdecl BrMatrix34PostShearY(br_matrix34 *mat, br_scalar sx, br_scalar sz);

void __cdecl BrMatrix34PreShearZ(br_matrix34 *mat, br_scalar sx, br_scalar sy);

void __cdecl BrMatrix34PostShearZ(br_matrix34 *mat, br_scalar sx, br_scalar sy);

#endif
