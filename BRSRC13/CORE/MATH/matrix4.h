#ifndef _MATRIX4_H_
#define _MATRIX4_H_

#include "br_types.h"


void __cdecl BrMatrix4Copy(br_matrix4 *A, br_matrix4 *B);

void __cdecl BrMatrix4Mul(br_matrix4 *A, br_matrix4 *B, br_matrix4 *C);

void __cdecl BrMatrix4Identity(br_matrix4 *mat);

void __cdecl BrMatrix4Scale(br_matrix4 *mat, br_scalar sx, br_scalar sy, br_scalar sz);

br_scalar __cdecl BrMatrix4Inverse(br_matrix4 *A, br_matrix4 *B);

br_scalar __stdcall Determinant3(br_scalar a1, br_scalar a2, br_scalar a3, br_scalar b1, br_scalar b2, br_scalar b3, br_scalar c1, br_scalar c2, br_scalar c3);

br_scalar __cdecl BrMatrix4Determinant(br_matrix4 *mat);

void __cdecl BrMatrix4Adjoint(br_matrix4 *A, br_matrix4 *B);

void __cdecl BrMatrix4Perspective(br_matrix4 *mat, br_angle field_of_view, br_scalar aspect, br_scalar hither, br_scalar yon);

void __cdecl BrMatrix4Apply(br_vector4 *A, br_vector4 *B, br_matrix4 *C);

void __cdecl BrMatrix4ApplyP(br_vector4 *A, br_vector3 *B, br_matrix4 *C);

void __cdecl BrMatrix4ApplyV(br_vector4 *A, br_vector3 *B, br_matrix4 *C);

void __cdecl BrMatrix4TApply(br_vector4 *A, br_vector4 *B, br_matrix4 *C);

void __cdecl BrMatrix4TApplyP(br_vector4 *A, br_vector3 *B, br_matrix4 *C);

void __cdecl BrMatrix4TApplyV(br_vector4 *A, br_vector3 *B, br_matrix4 *C);

void __cdecl BrMatrix4Copy34(br_matrix4 *A, br_matrix34 *B);

void __cdecl BrMatrix4Mul34(br_matrix4 *A, br_matrix34 *B, br_matrix4 *C);

void __cdecl BrMatrix4Pre34(br_matrix4 *A, br_matrix34 *B);

void __cdecl BrMatrix4ShearZ(br_matrix4 *mat, br_scalar sx, br_scalar sy);

#endif
