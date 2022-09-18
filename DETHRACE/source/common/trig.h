#ifndef _TRIG_H_
#define _TRIG_H_

#include "br_types.h"
#include "dr_types.h"

extern float(* hookvar_gFloat_sine_table )[91]; // addr: 0051E620
extern br_fixed_ls(* hookvar_gFixed_sine_table )[91]; // addr: 0051E790
extern br_matrix23 * hookvar_mat23tmp1 ; // addr: 0053E4B8
extern br_matrix23 * hookvar_mat23tmp2 ; // addr: 0053E4D0
extern br_matrix34 * hookvar_mattmp1__trig ; // addr: 0053E4E8 // suffix added to avoid duplicate symbol
extern br_matrix34 * hookvar_mattmp2__trig ; // addr: 0053E518 // suffix added to avoid duplicate symbol

float __cdecl FastFloatSin(int pAngle_in_degrees);

float __cdecl FastFloatCos(int pAngle_in_degrees);

float __cdecl FastFloatTan(int pAngle_in_degrees);

br_scalar __cdecl FastScalarSin(int pAngle_in_degrees);

br_scalar __cdecl FastScalarCos(int pAngle_in_degrees);

br_scalar __cdecl FastScalarTan(int pAngle_in_degrees);

br_scalar __cdecl FastScalarSinAngle(br_angle pBR_angle);

br_scalar __cdecl FastScalarCosAngle(br_angle pBR_angle);

br_scalar __cdecl FastScalarTanAngle(br_angle pBR_angle);

float __cdecl FastFloatArcSin(float pValue);

float __cdecl FastFloatArcCos(float pValue);

br_scalar __cdecl FastScalarArcSin(br_scalar pValue);

br_scalar __cdecl FastScalarArcCos(br_scalar pValue);

float __cdecl FastFloatArcTan2(float pY, float pX);

br_scalar __cdecl FastScalarArcTan2(br_scalar pY, br_scalar pX);

br_angle __cdecl FastFloatArcTan2Angle(float pY, float pX);

br_angle __cdecl FastScalarArcTan2Angle(br_scalar pY, br_scalar pX);

void __cdecl DRMatrix34RotateX(br_matrix34 *mat, br_angle rx);

void __cdecl DRMatrix34RotateY(br_matrix34 *mat, br_angle ry);

void __cdecl DRMatrix34RotateZ(br_matrix34 *mat, br_angle rz);

void __cdecl DRMatrix34Rotate(br_matrix34 *mat, br_angle r, br_vector3 *a);

void __cdecl DRMatrix34PreRotateX(br_matrix34 *mat, br_angle rx);

void __cdecl DRMatrix34PostRotateX(br_matrix34 *mat, br_angle rx);

void __cdecl DRMatrix34PreRotateY(br_matrix34 *mat, br_angle ry);

void __cdecl DRMatrix34PostRotateY(br_matrix34 *mat, br_angle ry);

void __cdecl DRMatrix34PreRotateZ(br_matrix34 *mat, br_angle rz);

void __cdecl DRMatrix34PostRotateZ(br_matrix34 *mat, br_angle rz);

void __cdecl DRMatrix34PreRotate(br_matrix34 *mat, br_angle r, br_vector3 *axis);

void __cdecl DRMatrix34PostRotate(br_matrix34 *mat, br_angle r, br_vector3 *axis);

void __cdecl DRMatrix23Rotate(br_matrix23 *mat, br_angle rz);

void __cdecl DRMatrix23PreRotate(br_matrix23 *mat, br_angle rz);

void __cdecl DRMatrix23PostRotate(br_matrix23 *mat, br_angle rz);

#endif
