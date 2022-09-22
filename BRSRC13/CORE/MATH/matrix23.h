#ifndef _MATRIX23_H_
#define _MATRIX23_H_

#include "br_types.h"

// extern br_matrix23 * hookvar_mattmp1__matrix23 ; // suffix added to avoid duplicate symbol
// extern br_matrix23 * hookvar_mattmp2__matrix23 ; // suffix added to avoid duplicate symbol

void __cdecl BrMatrix23Copy(br_matrix23 *A, br_matrix23 *B);

void __cdecl BrMatrix23Mul(br_matrix23 *A, br_matrix23 *B, br_matrix23 *C);

void __cdecl BrMatrix23Identity(br_matrix23 *mat);

void __cdecl BrMatrix23Rotate(br_matrix23 *mat, br_angle rz);

void __cdecl BrMatrix23Translate(br_matrix23 *mat, br_scalar dx, br_scalar dy);

void __cdecl BrMatrix23Scale(br_matrix23 *mat, br_scalar sx, br_scalar sy);

void __cdecl BrMatrix23ShearX(br_matrix23 *mat, br_scalar sy);

void __cdecl BrMatrix23ShearY(br_matrix23 *mat, br_scalar sx);

br_scalar __cdecl BrMatrix23Inverse(br_matrix23 *B, br_matrix23 *A);

void __cdecl BrMatrix23LPInverse(br_matrix23 *B, br_matrix23 *A);

void __cdecl BrMatrix23LPNormalise(br_matrix23 *A, br_matrix23 *B);

void __cdecl BrMatrix23ApplyP(br_vector2 *A, br_vector2 *B, br_matrix23 *C);

void __cdecl BrMatrix23ApplyV(br_vector2 *A, br_vector2 *B, br_matrix23 *C);

void __cdecl BrMatrix23TApplyP(br_vector2 *A, br_vector2 *B, br_matrix23 *C);

void __cdecl BrMatrix23TApplyV(br_vector2 *A, br_vector2 *B, br_matrix23 *C);

void __cdecl BrMatrix23Pre(br_matrix23 *mat, br_matrix23 *A);

void __cdecl BrMatrix23Post(br_matrix23 *mat, br_matrix23 *A);

void __cdecl BrMatrix23PreRotate(br_matrix23 *mat, br_angle rz);

void __cdecl BrMatrix23PostRotate(br_matrix23 *mat, br_angle rz);

void __cdecl BrMatrix23PreTranslate(br_matrix23 *mat, br_scalar x, br_scalar y);

void __cdecl BrMatrix23PostTranslate(br_matrix23 *A, br_scalar x, br_scalar y);

void __cdecl BrMatrix23PreScale(br_matrix23 *mat, br_scalar sx, br_scalar sy);

void __cdecl BrMatrix23PostScale(br_matrix23 *mat, br_scalar sx, br_scalar sy);

void __cdecl BrMatrix23PreShearX(br_matrix23 *mat, br_scalar sy);

void __cdecl BrMatrix23PostShearX(br_matrix23 *mat, br_scalar sy);

void __cdecl BrMatrix23PreShearY(br_matrix23 *mat, br_scalar sx);

void __cdecl BrMatrix23PostShearY(br_matrix23 *mat, br_scalar sx);

#endif
